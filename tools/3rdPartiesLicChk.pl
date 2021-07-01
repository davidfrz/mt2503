#!/usr/bin/perl -w

&Usage() if ($#ARGV < 1); # be compatible with executing in standalone mode without feature's source level license check
&Usage() if ($#ARGV > 1 && $#ARGV < 5);

use Win32::OLE qw(in with);
use Win32::OLE::Const 'Microsoft Excel';
use File::Basename;
use Win32::Internet;
use Net::SMTP;
use Time::HiRes qw(gettimeofday tv_interval);
use File::Copy;

my $CWD = `cd`;
chomp $CWD;
$CWD =~ s/\\$// if ($CWD =~ /\\$/);

my $DefaultThrdPtyLicFile = '\\\\glbfs14\wcp\sw_releases\@Portal_Material\Custom_Release_Info\customer_3rdparty_info\WCP-SA-Customer_Management.xls';
my $AplixFeatSettingChgLogPth = '\\\\glbfs14\wcp\sw_releases\@Portal_Material\Custom_Release_Info\customer_3rdparty_info\Aplix_Feature_Setting_Changes';
my $AACPlusFeatSettingChgLogPth = '\\\\glbfs14\wcp\sw_releases\@Portal_Material\Custom_Release_Info\customer_3rdparty_info\AACPlus_Feature_Setting_Changes';

#parse command line arguments
my $InputPrjFile = $ARGV[0];
my $InputLicFile = ($ARGV[1] eq "")? $DefaultThrdPtyLicFile : $ARGV[1];
my $Feat2ModTbl = (defined $ARGV[2])? $ARGV[2] : '';
my @SRCModList = (defined $ARGV[3])? split(' ',$ARGV[3]) : ();
my @PSRCModList = (defined $ARGV[4])? split(' ',$ARGV[4]) : ();
my @OBJModList = (defined $ARGV[5])? split(' ',$ARGV[5]) : ();

if (!-e $InputPrjFile)
{
	print "$InputPrjFile does NOT exist!!!\n";
	&Usage();
}

if (!-e $InputLicFile)
{
	print "$InputLicFile does NOT exist!!!\n";
	&Usage();
}

if ($Feat2ModTbl eq '')
{
	warn "Skip 3rd party feature's source level license check due to NOT specify \"Feat2ModTbl\" argument on command line!!!\n";
}
else
{
	warn "$Feat2ModTbl does NOT exist, skip 3rd party feature's source level license check!!!" if (!-e $Feat2ModTbl);
	warn "skip 3rd party feature's source level license check due to NOT specify \"CUS_REL_SRC_COMP\" argument on command line!!!" if (!@SRCModList);
	warn "skip 3rd party feature's source level license check due to NOT specify \"CUS_REL_PAR_SRC_COMP\" argument on command line!!!" if (!@PSRCModList);
	warn "skip 3rd party feature's source level license check due to NOT specify \"CUS_REL_MTK_COMP\" argument on command line!!!" if (!@OBJModList);
}

my $ProjectMF = basename($InputPrjFile);
my $ProjectNm = basename($ProjectMF, ".mak");
my $MFPath = dirname($InputPrjFile);
$MFPath =~ s/\\$//;
open(MF, "<$MFPath\\$ProjectMF") or die "cannot open $MFPath\\$ProjectMF!!!\n";
while (<MF>)
{
	next if (/^\s*#/);
	if (/^\s*(\w+)\s*=\s*(\w+)/)
	{
		my $keyname = uc($1);
		$$keyname = uc($2);
	}
}
close(MF);


#*****************************************************************************
# feature related modules setting for source level license check
# such as @WAP_SUPPORT_OBIGO_Q03C = qw(obigo03cadp obigo03capp obigo03clib)
#*****************************************************************************
if (($Feat2ModTbl ne '') && (-e $Feat2ModTbl))
{
	$Feat2ModTbl = (dirname($Feat2ModTbl) =~ /:|^\\\\\w/)? $Feat2ModTbl : "$CWD\\$Feat2ModTbl";
	open(FH, "<$Feat2ModTbl") or die "cannot open $Feat2ModTbl!!!\n";
	while (<FH>)
	{
		next if (/^\s*#/);
		if (/^\s*(\w+)\s*=\s*(\w+(\s+\w+)*)\s*/)
		{
			my $keyname = uc($1);
			@$keyname = split(' ',$2);
		}
	}
	close(FH);
}


# Data Structure
#my $ThirdPartiesLicInfo = 
#{
# CustID => string,
# ActFlg => boolean,
# CustNm => string,
# ShrtNm => string,
# LicToken => { Opt1 => boolean,
#               Opt2 => boolean,
#               Opt3 => boolean,
#               ......,
#               Optn => boolean},
# # if customer have Aplix or RollTech license,
# # the following two elements will be available
# AplixLicToken => { Opt1 => boolean,
#                    Opt2 => boolean,
#                    ......,
#                    Optn => boolean},
# RollTechLicToken => { Opt1 => boolean,
#                       Opt2 => boolean,
#                       ......,
#                       Optn => boolean}
#};
#*****************************************************************************
# Read all customers' 3rd party feature license info. from license table
#*****************************************************************************
my $PrintLicInfoonScrn = 0; #dump license info. or NOT
my $ErrMsg = '';
my $ErrCnt = 0; # Err. counter

# global varialbes setting for Main table 'Customer_3rdParties'
my $CustID_col = 1;
my $IsCustActive_col = 3;
my $MainShtCustNm_col = 5;
my $MainShtShrtNm_col = 6;
my $MainShtFirstOpt_col = 8;
my $MainShtFeatSeting_row = 2;
my $MainShtFirstCust_row = 5;

# global varialbes setting for Aplix table 'Aplix'
my $AplixShtCustNm_col = 2;
my $AplixShtShrtNm_col = 3;
my $AplixShtFirstOpt_col = 6;
my $AplixShtFeatSeting_row = 4;
my $AplixShtFirstCust_row = 5;
my $AplixFeature = '';
my $AplixIgrptrn = '^\s*SW release request date\s*$|^\s*Expiration date\s*$|^\s*Contract type\s*$|^\s*Note\s*$';

# global varialbes setting for RollTech table 'RollTech'
my $RollTechShtCustNm_col = 3;
my $RollTechShtShrtNm_col = 4;
my $RollTechShtFirstOpt_col = 5;
my $RollTechShtFeatSeting_row = 2;
my $RollTechShtFirstCust_row = 3;
my $RollTechFeature = '';
my $RollTechIgrptrn = '^\s*Scope\s*$|^\s*Platform or Project\s*$|^\s*Note\s*$';


my @ActCustLicInfo = ();
my ($seconds, $microseconds) = gettimeofday;
my $ThirdPartyLicFile = (dirname($InputLicFile) =~ /:|^\\\\\w/)? $InputLicFile : "$CWD\\$InputLicFile";
my $ThirdPartyLicFileCpy = "$CWD\\".basename($ThirdPartyLicFile,'.xls')."_" .$microseconds.'.xls';

my $Excel = Win32::OLE->new('Excel.Application', 'Quit');
`copy /y $ThirdPartyLicFile $ThirdPartyLicFileCpy`;
#copy($ThirdPartyLicFile,$ThirdPartyLicFileCpy) or die "Copy failed: $!";
my $Book = $Excel->Workbooks->Open($ThirdPartyLicFileCpy);

# get the last row and column
my $MainSheet = $Book->Worksheets('Customer_3rdParties'); # most 3rd parties license table

# For finding the correct last row, turn off filter.
$MainSheet->Columns()->AutoFilter();
my $MainShtLastOpt_col  = $MainSheet->Rows("1")->Find({What=>"*", 
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByColumns})->{Column};
												

my $MainShtLastCust_row = $MainSheet->UsedRange->Find({What=>"*",
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByRows})->{Row};

my $AplixSheet = $Book->Worksheets('Aplix');
my $AplixShtLastOpt_col  = $AplixSheet->UsedRange->Find({What=>"*", 
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByColumns})->{Column};
my $AplixShtLastCust_row = $AplixSheet->UsedRange->Find({What=>"*",
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByRows})->{Row};

my $RollTechSheet = $Book->Worksheets('RollTech');
my $RollTechShtLastOpt_col  = $RollTechSheet->UsedRange->Find({What=>"*", 
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByColumns})->{Column};
my $RollTechShtLastCust_row = $RollTechSheet->UsedRange->Find({What=>"*",
												SearchDirection=>xlPrevious,
												SearchOrder=>xlByRows})->{Row};

print "Last (row, column): ($MainShtLastCust_row, $MainShtLastOpt_col)\n";
#*****************************************************************************
# Main Table(Customer_3rdParties), Most 3rd party feature license info. for all customers
#*****************************************************************************

foreach my $row ($MainShtFirstCust_row..$MainShtLastCust_row)
{
	my $ThirdPartiesLicInfo = {};
	next unless defined $MainSheet->Cells($row,$IsCustActive_col)->{'Value'};
	next unless $MainSheet->Cells($row,$IsCustActive_col)->{'Value'} =~ /^\s*Y\s*$/i;
	next unless defined $MainSheet->Cells($row,$MainShtShrtNm_col)->{'Value'};
	$ThirdPartiesLicInfo->{CustID} = $MainSheet->Cells($row,$CustID_col)->{'Value'};
	push (@ActCustLicInfo, $ThirdPartiesLicInfo);
	$ThirdPartiesLicInfo->{ActFlg} = $MainSheet->Cells($row,$IsCustActive_col)->{'Value'};
	$ThirdPartiesLicInfo->{CustNm} = $MainSheet->Cells($row,$MainShtCustNm_col)->{'Value'};
	$ThirdPartiesLicInfo->{ShrtNm} = $MainSheet->Cells($row,$MainShtShrtNm_col)->{'Value'};
	$ThirdPartiesLicInfo->{LicToken} = {};
	foreach my $col ($MainShtFirstOpt_col..$MainShtLastOpt_col)
	{
		next unless defined $MainSheet->Cells($MainShtFeatSeting_row,$col)->{'Value'};
		my $OptSetting = uc($MainSheet->Cells($MainShtFeatSeting_row,$col)->{'Value'});
		$OptSetting =~ s/\s//g;
		$AplixFeature = "$OptSetting" if (($AplixFeature eq '') && ($OptSetting =~ /^J2ME_SUPPORT=JBLENDIA$/i));
		$RollTechFeature = "$OptSetting" if (($RollTechFeature eq '') && ($OptSetting =~ /^J2ME_SUPPORT=IJET$/i));
		if (!defined $MainSheet->Cells($row,$col)->{'Value'})
		{
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 0 if (!defined $ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"});
			next;
		}

		if ($MainSheet->Cells($row,$col)->{'Value'} =~ /^\s*V.*(Partial Source|PSRC)/i)
		{# feature with partial source
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 3;
		}
		elsif ($MainSheet->Cells($row,$col)->{'Value'} =~ /^\s*V.*(Source|SRC)/i)
		{# feature with full source
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 4;
		}
		elsif ($MainSheet->Cells($row,$col)->{'Value'} =~ /^\s*V.*(Object|OBJ)/i)
		{# feature ONLY with library
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 2;
		}
		elsif ($MainSheet->Cells($row,$col)->{'Value'} =~ /^\s*V/i)
		{
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 1;
		}
		elsif (!defined $ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"})
		{
			$ThirdPartiesLicInfo->{LicToken}->{"$OptSetting"} = 0;
		}
	}# foreach my $col ($MainShtFirstOpt_col..$MainShtLastOpt_col)

	$ThirdPartiesLicInfo->{LicToken}->{"AAC_PLUS_DECODE=TRUE"} = 1; # for recording AAC Plus rel. info.
}


#*****************************************************************************
# Read Aplix JAVA feature license info. of customers
#*****************************************************************************
@ActCustLicInfo = &ReadJavaLicInfo(\@ActCustLicInfo, 
																		'Aplix', 
																		$AplixFeature, 
																		$AplixShtFirstCust_row, 
																		$AplixShtLastCust_row, 
																		$AplixShtShrtNm_col, 
																		$AplixShtFirstOpt_col, 
																		$AplixShtLastOpt_col, 
																		$AplixShtFeatSeting_row, 
																		'AplixLicToken',
																		$AplixIgrptrn);

#*****************************************************************************
# Read RollTech JAVA feature license info. of customers
#*****************************************************************************
@ActCustLicInfo = &ReadJavaLicInfo(\@ActCustLicInfo, 
																		'RollTech', 
																		$RollTechFeature, 
																		$RollTechShtFirstCust_row, 
																		$RollTechShtLastCust_row, 
																		$RollTechShtShrtNm_col, 
																		$RollTechShtFirstOpt_col, 
																		$RollTechShtLastOpt_col, 
																		$RollTechShtFeatSeting_row, 
																		'RollTechLicToken',
																		$RollTechIgrptrn);

$Book->Save;
$Book->Close;
`del /q $ThirdPartyLicFileCpy`;
#*****************************************************************************
# Checking license for 3rd party features
#*****************************************************************************
@ActCustLicInfo = sort {$a->{ShrtNm} cmp $b->{ShrtNm}} @ActCustLicInfo;
@ActCustLicInfo = reverse @ActCustLicInfo;

my $find_shortname = 0;
foreach my $cust (@ActCustLicInfo)
{
	if ($ProjectMF =~ /^$cust->{ShrtNm}/i)
	{
		($ErrMsg, $ErrCnt) = &ChkLicense($cust->{CustNm}, $cust->{LicToken}, $ErrMsg, $ErrCnt);
		($ErrMsg, $ErrCnt) = &ChkJavaLicense($J2ME_SUPPORT, $cust, $ErrMsg, $ErrCnt) if (defined $J2ME_SUPPORT);
		($ErrMsg, $ErrCnt) = &ChkSrcLvlLic($cust->{CustNm}, $cust->{LicToken}, $ErrMsg, $ErrCnt);
		$find_shortname = 1;
		last;
	}
}
if (!$find_shortname)
{
	warn "[Warning]: Can Not find any shortname matching the $ProjectMF in 3rd party license table!\n";
	warn "[Warning]: Please check the project makefile and license table!\n";	
}
#*****************************************************************************
# Dump 3rd party features license info. to temp. file if necessary
# Print the checking result on screen
#*****************************************************************************
&PrintLicInfoonScrn(\@ActCustLicInfo) if ($PrintLicInfoonScrn);
&PrintChkRst($ErrMsg, $ErrCnt, $ThirdPartyLicFile);


sub ReadJavaLicInfo
{
	my ($arr_ref,
			$JavaVendor,
			$JavaFeature,
			$JavaShtFirstCust_row, 
			$JavaShtLastCust_row, 
			$JavaShtShrtNm_col, 
			$JavaShtFirstOpt_col, 
			$JavaShtLastOpt_col, 
			$JavaShtFeatSeting_row,
			$JavaLicToken,
			$JavaTblIgrPtrn) = @_;
	my $JavaSheet = $Book->Worksheets($JavaVendor);
	foreach my $customer (@$arr_ref)
	{
		next if (!$customer->{LicToken}->{$JavaFeature});
		foreach my $row ($JavaShtFirstCust_row..$JavaShtLastCust_row)
		{
			next unless defined $JavaSheet->Cells($row,$JavaShtShrtNm_col)->{'Value'};
			if ($customer->{ShrtNm} eq $JavaSheet->Cells($row,$JavaShtShrtNm_col)->{'Value'})
			{
				$customer->{$JavaLicToken} = {};
				foreach my $col ($JavaShtFirstOpt_col..$JavaShtLastOpt_col)
				{
					next unless defined $JavaSheet->Cells($JavaShtFeatSeting_row,$col)->{'Value'};
					next if ($JavaSheet->Cells($JavaShtFeatSeting_row,$col)->{'Value'} =~ 
					         /$JavaTblIgrPtrn/i);
	
					my $OptSetting = uc($JavaSheet->Cells($JavaShtFeatSeting_row,$col)->{'Value'});
					$OptSetting =~ s/\s//g;
	
					if (!defined $JavaSheet->Cells($row,$col)->{'Value'})
					{
						$customer->{$JavaLicToken}->{"$OptSetting"} = 0;
						next;
					}
					if ($JavaSheet->Cells($row,$col)->{'Value'} =~ /^\s*V/i)
					{
						$customer->{$JavaLicToken}->{"$OptSetting"} = 1;
					}
					else
					{
						$customer->{$JavaLicToken}->{"$OptSetting"} = 0;
					}
				}# foreach my $col ($JavaShtFirstOpt_col..$JavaShtLastOpt_col)
				last;
			}# if ($customer->{ShrtNm} eq $JavaSheet->Cells($row,$JavaShtShrtNm_col)->{'Value'})
		}# foreach my $row ($JavaShtFirstCust_row..$JavaShtLastCust_row)
	}# foreach my $customer (@$arr_ref)
	return @$arr_ref;
}

sub ChkJavaLicense
{
	my ($javasln, $hash_ref, $str, $i) = @_;
	my $tmpcnt = $i;

	if ($javasln eq 'JBLENDIA')
	{
		($str, $i) = &ChkLicense($hash_ref->{CustNm}, $hash_ref->{AplixLicToken}, $str, $i);

		if ($i != $tmpcnt)
		{ # the customer has no JBLENDIA license, need notify Aplix
			my ($OrgJavaFeatSet, $RelJavaFeatSet) = &GetJBLDFeatChgs($AplixFeatSettingChgLogPth);
			if (($OrgJavaFeatSet ne "") && ($RelJavaFeatSet ne ""))
			{
				my ($CustStr, $modem) = &GetCustStrAndMODEM($ProjectMF);
				my (undef, $week, $branch) = &GetVernoInfo("$MFPath\\Verno_$CustStr\.bld");
				# CPMQuery need to be rewrited to CQ_Query but is pending now
				#my $CustNameStr = &CPMQuery($CustStr, "Customer"); 
				my $CustNameStr = $hash_ref->{CustNm};
				my $sender = 'justin.chu@mediatek.com';
				my $toAplix = 'mtk-biz@aplix.co.jp';
				my $toSWPM = 'wcp_mt_cpm2@mediatek.com';
				my $cc = 'justin.chu@mediatek.com';
				my $subject = "Change project feature set notification from MTK";
				my $body = "Dear Aplix partners,\n\n"
				         . "    Please be informed that MediaTek will change the feature set of $CustStr($week) project with $PLATFORM chipset on $branch branch "
				         . "for $CustNameStr customer. Since the feature set is different with the last released, "
				         . "please help confirm whether the feature set is acceptable for release to the "
				         . "above-mentioned customer by providing a return e-mail to MediaTek within two (2) "
				         . "business days of this e-mail. This release request shall be deemed automatically "
				         . "accepted by Aplix if MediaTek receives no response from Aplix within two (2) business days of this e-mail.\n\n";
				$body .= "The two feature sets are as follows,\n"
				       . "Original Feature Set:\n"
				       . "$OrgJavaFeatSet\n"
				       . "Released Feature Set:\n"
				       . "$RelJavaFeatSet";
				
				&SendEmailNotify($sender, $toAplix, $cc, $subject, $body);
				&SendEmailNotify($sender, $toSWPM, $cc, $subject, $body);
			}
		}
	}
	elsif ($javasln eq 'IJET')
	{
		($str, $i) = &ChkLicense($hash_ref->{CustNm}, $hash_ref->{RollTechLicToken}, $str, $i);
	}
	return ($str, $i);
}

sub ChkLicense
{
	my ($customer, $hash_ref, $str, $i) = @_;
	foreach my $opt (keys %{$hash_ref})
	{
		if ($opt =~ /^(AAC_PLUS_DECODE)=TRUE$/)
		{# AAC_PLUS_DECODE
			if (defined $AAC_PLUS_DECODE && $AAC_PLUS_DECODE =~ /^TRUE$/)
			{
				my ($CustStr, $modem) = &GetCustStrAndMODEM($ProjectMF);
				my ($VernoStr,undef,undef) = &GetVernoInfo("$MFPath\\Verno_$CustStr\.bld");
				&RecAACPlusRelInfo("$AACPlusFeatSettingChgLogPth\\AACPlusRelInfo.log",
													 &GetCurTime(),
													 $customer,
													 $VernoStr,
													 $ProjectNm,
													 "AAC Plus");
			}
		}# if ($opt =~ /^(AAC_PLUS_DECODE)=TRUE$/)
		elsif ($opt =~ /^(AAC_PLUS_PS_DECODE)=TRUE$/)
		{# AAC_PLUS_PS_DECODE
			if (defined $AAC_PLUS_PS_DECODE && $AAC_PLUS_PS_DECODE =~ /^TRUE$/)
			{
				my ($CustStr, $modem) = &GetCustStrAndMODEM($ProjectMF);
				my ($VernoStr,undef,undef) = &GetVernoInfo("$MFPath\\Verno_$CustStr\.bld");
				&RecAACPlusRelInfo("$AACPlusFeatSettingChgLogPth\\AACPlusV2RelInfo.log",
													 &GetCurTime(),
													 $customer,
													 $VernoStr,
													 $ProjectNm,
													 "AAC Plus V2");
			}
		}# if ($opt =~ /^(AAC_PLUS_PS_DECODE)=TRUE$/)
		elsif ($opt =~ /^(SYNCML_DM_SUPPORT)=TRUE$/)
		{# SYNCML_DM_SUPPORT
			my $OptNm = $1;
			if ((defined $OPTR_SPEC && $OPTR_SPEC =~ /^CMCC/ && $OPTR_SPEC !~ /SEGA/) && defined $$OptNm && !$hash_ref->{$opt})
			{
				$i += 1;
				$str .= "$i: $customer has no license for feature \"$opt\"!!!\n";
			}
		}# if ($opt =~ /^(SYNCML_DM_SUPPORT)=TRUE$/)
		elsif ($opt =~ /^(SINGLE_SIM_MMI_ONLY)=FALSE$/)
		{# SINGLE_SIM_MMI_ONLY (dual sim)
			my $OptNm = $1;
			if ((defined $GEMINI && $GEMINI =~ /^TRUE$/) && (defined $SINGLE_SIM_MMI_ONLY && $SINGLE_SIM_MMI_ONLY =~ /^FALSE$/) && !$hash_ref->{$opt})
			{
				$i += 1;
				$str .= "$i: $customer has no license for feature \"$opt\"!!!\n";
			}
		}# elsif ($opt =~ /^(SINGLE_SIM_MMI_ONLY)=FALSE$/)
		elsif ($opt =~ /^(\w+)=(\w+)$/)
		{
			my $OptNm = $1;
			my $OptVal = $2;
			if (defined $$OptNm && ($$OptNm eq $OptVal) && !$hash_ref->{$opt})
			{
				$i += 1;
				$str .= "$i: $customer has no license for feature \"$opt\"!!!\n";
			}
		}# elsif ($opt =~ /^(\w+)=(\w+)$/)
		elsif ($opt =~ /^(\w+)=((\w+)\.+)$/)
		{# CMCC_......
			my $OptNm = $1;
			my $OptValPfx = $3;
			if (defined $$OptNm && ($$OptNm =~ /^$OptValPfx/) && !$hash_ref->{$opt})
			{
				$i += 1;
				$str .= "$i: $customer has no license for feature \"$OptNm=$$OptNm\"!!!\n";
			}
		}# elsif ($opt =~ /^(\w+)=((\w+)\.+)$/)
	}
	return ($str, $i);
}

sub ChkSrcLvlLic
{
	my ($customer, $hash_ref, $str, $i) = @_;
	foreach my $opt (keys %{$hash_ref})
	{
		if ($opt =~ /^(\w+)=(\w+)$/)
		{
			my $ArrNm = $1.'_'.$2;
			if (@$ArrNm)
			{
				if (($hash_ref->{$opt} == 4) && !&IsSubArr(\@$ArrNm, \@SRCModList))
				{
					$i += 1;
					$str .= "$i: $customer should have source release for feature \"$opt\"!!!\n";
				}
				if (($hash_ref->{$opt} == 3) && !&IsSubArr(\@$ArrNm, \@PSRCModList))
				{
					$i += 1;
					$str .= "$i: $customer should have partial source release for feature \"$opt\"!!!\n";
				}
				if (($hash_ref->{$opt} == 2) && !&IsSubArr(\@$ArrNm, \@OBJModList))
				{
					$i += 1;
					$str .= "$i: $customer should have library release for feature \"$opt\"!!!\n";
				}
			}
		}
	}
	return ($str, $i);
}

sub IsSubArr
{
	my ($arr_ref1, $arr_ref2) = @_;
	my $cnt = 0;
	foreach my $i (@$arr_ref1)
	{
		$cnt++ if (grep(/^$i$/, @$arr_ref2));
	}
	return 1 if ($cnt == @$arr_ref1);
	return 0;
}

sub PrintChkRst
{
	my ($str, $i, $licfile) = @_;
	if ($i)
	{
		print $i == 1? 
		      "There is license problem in the following $i feature setting.\n":
		      "There are license problems in the following $i features setting.\n";
		print $str;
		print "PLEASE check details from 3rd party feature license table \"$licfile\" !!!\n";
		exit 1;
	}
	else
	{
		print "Checking 3rd party features license DONE!!!\n";
		exit 0;
	}
}

#*****************************************************************************
# Print the the cusotmer's 3rd party feature License info.
#*****************************************************************************
sub PrintLicInfoonScrn
{

	open(FH,">~3rdPtyLicInfo.tmp") or die "Cannot open ~3rdPtyLicInfo.tmp!!!\n";
	my $arr_ref = shift;
	foreach my $i (@$arr_ref)
	{
		print FH "#****************************************************\n";
		print FH "# $i->{CustNm}\n";
		print FH "#****************************************************\n";
	# $i ===> $ThirdPartyLicFile	
		foreach my $k (keys %{$i})
		{#$k ===> CustID, ActFlg, CustNm, ShrtNm, LicToken
			if ($k =~ /^LicToken$/i)
			{
				print FH "[License Token]\n";
				foreach my $t (keys %{$i->{$k}})
				{ # $i->{$k} ===> $ThirdPartyLicFile->{LicToken}
					# $t ===> Opt1,Opt2,...,Optn
					printf FH "%-70s%5d\n",$t,$i->{$k}->{$t};
				}
			}# if ($k =~ /^LicToken$/i)
			elsif ($k =~ /^AplixLicToken$/i)
			{
				print FH "[Aplix License Token]\n";
				foreach my $t (keys %{$i->{$k}})
				{ # $i->{$k} ===> $ThirdPartyLicFile->{LicToken}
					# $t ===> Opt1,Opt2,...,Optn
					printf FH "%-70s%5d\n",$t,$i->{$k}->{$t};
				}
			}# elsif ($k =~ /^AplixLicToken$/i)
			elsif ($k =~ /^RollTechLicToken$/i)
			{
				print FH "[Rolltech License Token]\n";
				foreach my $t (keys %{$i->{$k}})
				{ # $i->{$k} ===> $ThirdPartyLicFile->{LicToken}
					# $t ===> Opt1,Opt2,...,Optn
					printf FH "%-70s%5d\n",$t,$i->{$k}->{$t};
				}
			}# elsif ($k =~ /^RollTechLicToken$/i)
			else
			{
				printf FH "%-70s%5s\n",$k,$i->{$k};
				# CustID: string
				# ActFlg: boolean
				# CustNm: string
				# ShrtNm: string
			}
		}
	}
	close(FH);
}

sub CPMQuery
{
    my ($string1, $string2) = @_;
    my ($statuscode, $headers, $file) = ();
    my $my_result   = ();
    my $CPM_address = "/CPM/httpService/CPMService.cfm";

		my ($Srv, $UsrNm, $Pwd);
		my $CPMAuthInfo = dirname($DefaultThrdPtyLicFile)."\\CPMAuthInfo.ini";
		open(AUTHFILE) or die "can NOT open $CPMAuthInfo!\n";
		while(<AUTHFILE>)
		{
			chomp;
			$Srv = $1 if (/^\s*CPM_SERVER\s*=\s*(.*)/);
			$UsrNm = $1 if (/^\s*CPM_ACCOUNT\s*=\s*(.*)/);
			$Pwd = $1 if (/^\s*CPM_PWD\s*=\s*(.*)/);
		}
		close(AUTHFILE);
		my $Session;
		my $Connection = new Win32::Internet();
		$Connection->HTTP($Session, $Srv, $UsrNm, $Pwd);

    if ($string2 ne "Customer")
    {
        ($statuscode, $headers, $file) = $HTTP->Request("$CPM_address?func=getFeatureValuOfProject\&project=$string1\&feature=$string2");
    }
    else
    {
        ($statuscode, $headers, $file) = $HTTP->Request("$CPM_address?func=getCustomerNameOfProject\&project=$string1");
    }
		$Connection->Close();
    $my_result = $file;

    $my_result =~ s/<[^\<\>]*>//g;
    return $my_result;
}

sub GetJBLDFeatChgs
{
	my $logpath = shift;
	my $ChgCnt = 0;
	my @OrgSet = ();
	my @CurSet = ();
	my ($CustStr, $modem) = &GetCustStrAndMODEM($ProjectMF);
	my ($VernoStr,undef,undef) = &GetVernoInfo("$MFPath\\Verno_$CustStr\.bld");
	my $logfile = $VernoStr."_".$CustStr."_".$modem."\.log"; # the log is generated by project creation process

	if (-e "$logpath\\$logfile")
	{
		open(LOGFILE,"<$logpath\\$logfile") or die "can NOT open $logpath\\$logfile!\n";
		while(<LOGFILE>)
		{
			next if (/^\s*#/);
			if (/^\s*(\w+)\s*=\s*(\w+)/)
			{
				my $opt = $1;
				my $orgval = $2;
				next if ($opt =~ /^CHIP_VER$/);
				push(@OrgSet, "$opt = $orgval");
				push(@CurSet, "$opt = $$opt");
				$ChgCnt++ if ($$opt ne $orgval);
			}
		}
		close(LOGFILE);
	}
	if (!$ChgCnt)
	{
		@OrgSet = ();
		@CurSet = ();
	}
	return (join("\n",@OrgSet), join("\n",@CurSet));
}

sub GetCustStrAndMODEM
{
	my $pMF = shift;
	my $modem = '';
	my $CustStr = '';
	my @modem_type = qw (LIS BASIC GSM GPRS UMTS UDVT HSPA TDD128 TDD128DPA TDD128HSPA);
	foreach my $p (@modem_type)
	{
		if ($pMF =~ /(.*)_$p\.mak$/i)
		{
			$CustStr = $1;
			$modem = $p;
			last;
		}
	}
	return ($CustStr, $modem);
}

sub GetVernoInfo
{
	my $vernofile = shift;
	my $verno = '';
	my $weekStr = '';
	my $branchStr = '';
	open(VERNOFILE, "<$vernofile") or die "can NOT open $vernofile!\n";
	while(<VERNOFILE>)
	{
		if (/^\s*VERNO\s*=\s*(MAUI\.((\w+)\.)?(W\d\d\.\d\d)\.?(((OF|MP|SP)\w*)\.?)?.*)/i)
		{
			$verno = $1;
			$weekStr = $4;
			my ($elem3, $elem5, $elem6) = ($3, $5, $6);
			my $tmp = $weekStr;
			$tmp =~ s/\.//;
			$branchStr = ((defined($elem3) && ($elem3 ne ""))? $elem3 : "MAUI")
								 . ((defined($elem5) && ($elem5 ne ""))? $tmp.$elem6 : "");
		}
	}
	close(VERNOFILE);
	return ($verno, $weekStr, $branchStr);
}

sub RecAACPlusRelInfo
{
	my $writed = 0;
	my ($logfile, $timestr, $customer, $verno, $projectname, $featurename) = @_;
	for (1..20)
	{
		if(open(LOGFILE, ">>$logfile"))
		{
	    print LOGFILE "$timestr\t$customer\t$verno\t$projectname\t$featurename\n";
	    close(LOGFILE);
	    $writed = 1;
	    last;
	  } 
	  else
	  {
	  	system("echo cannot open $logfile  Wait 3 sec to open again");
	    sleep(3);
	  }
  }
  if(!$writed)
  {
  	die "cannot open $timestr\t$customer\t$verno\t$projectname\t$featurename";
  }
}

sub GetCurTime
{
	my ($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
	my $timeStr = sprintf("%4.4d-%2.2d-%2.2d %2.2d:%2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
	return $timeStr;
}

sub SendEmailNotify
{
	my ($sender, $to_list, $cc_list, $mail_subject, $mail_content) = @_;
	my $smtp_server = 'mtksmtp2.mtk.com.tw'; #"172.21.100.20"
	my $msg = <<__EOFNOTIFY
To: $to_list
Cc: $cc_list
Subject: $mail_subject
From: $sender

$mail_content

__EOFNOTIFY
;
	my $smtp = Net::SMTP->new($smtp_server);
	$smtp->mail($sender);
	map { $smtp->to($_); } split(/,/, $to_list);
	map { $smtp->cc($_); } split(/,/, $cc_list);
	$smtp->data($msg);
	$smtp->quit;
}

sub Usage
{
  print <<"__EOFUSAGE";

usage: $0 PrjMF 3rdPtyLicFile [<Feat2ModTbl> <CUS_REL_SRC_COMP> <CUS_REL_PAR_SRC_COMP> <CUS_REL_MTK_COMP>]

PrjMF                  project makefile

3rdPtyLicFile          3rd parties license table, if specified as "", 
                       the default licese table will be used

Feat2ModTbl            Mapping file for feature and its module(s)
                       should be specified together with CUS_REL_SRC_COMP, 
                       CUS_REL_PAR_SRC_COMP & CUS_REL_MTK_COMP

CUS_REL_SRC_COMP       SRC module list
                       should be specified together with Feat2ModTbl, 
                       CUS_REL_PAR_SRC_COMP & CUS_REL_MTK_COMP

CUS_REL_PAR_SRC_COMP   PSRC module list
                       should be specified together with Feat2ModTbl, 
                       CUS_REL_SRC_COMP & CUS_REL_MTK_COMP

CUS_REL_MTK_COMP       OBJ module list
                       should be specified together with Feat2ModTbl, 
                       CUS_REL_SRC_COMP & CUS_REL_PAR_SRC_COMP
__EOFUSAGE
  exit 1;
}
