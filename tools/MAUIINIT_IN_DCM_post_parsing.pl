# this perl should be called at post build stage.
# first it parse .lis file to get all symbol(function) in DYNAMIC_COMP_MAUIINIT_SECTION
# then analysis from callgraph.txt to check whether these symbol should be put in MAUIINIT_COMP_SECTION or not

use strict;
use warnings;

use constant TOOL_SCRIPT_DEBUG => 0;

my $DEBUG_INFO_ENABLE = 1;
my $PROMPT_INFO_ENABLE = 0;
my $TRACE_INFO_ENABLE = 0;

# global config variables

my $LISFilePath = undef;
my $callgraphFilePath = undef;

my $totalWarningCnt = 0;

my %exceptionList;
my %region_info_hash;
my @symbol_table;
my %symbolInfo;
my $pSymbolInfo = \%symbolInfo;

my %BlackEndList = (
"fatal_error_handler" => 1,
"assert_common" => 1,
"kal_mem_cpy" => 1,
"kal_trace" => 1,
"DclRTC_Open" => 1
);

my %InitEntryPointsList = (
"nvram_init" => 1, 
"tst_task_init" => 1, 
"tst_reader_init" => 1, 
"dt_init" => 1, 
"ratcm_init" => 1, 
"ratdm_init" => 1, 
"rsva_init" => 1, 
"mm_init" => 1, 
"cc_init" => 1, 
"ciss_init" => 1, 
"sms_init" => 1, 
"sim_process_init" => 1, 
"sim_process_init" => 1, 
"layer4_init" => 1, 
"rr_init" => 1, 
"rlc_reasm_init" => 1, 
"snd_init" => 1, 
"sm_init" => 1, 
"llc_init" => 1, 
"CalTaskInit" => 1, 
"CalLowTaskInit" => 1, 
"l1_init" => 1, 
"l1_init_2" => 1, 
"fm_task_init" => 1, 
"bmt_task_init" => 1, 
"usb_task_init" => 1, 
"brt_task_init" => 1, 
"l1audio_init" => 1, 
"vfile_task_init" => 1, 
"vcodec_v2_task_init" => 1, 
"vsrc_task_init" => 1, 
"fs_task_init" => 1, 
"mATV_task_init" => 1, 
"fmt_init" => 1, 
"vrt_task_init" => 1, 
"gdi_task_init" => 1, 
"MMI_Init" => 1, 
"abm_init" => 1, 
"tcpip_init" => 1, 
"soc_init" => 1, 
"wap_init" => 1, 
"wps_init" => 1, 
"mms_init" => 1, 
"gdc_init" => 1, 
"gdd_init" => 1, 
"pls_init" => 1, 
"NMS_init" => 1, 
"med_init" => 1, 
"med_v_init" => 1, 
"bt_init" => 1, 
"INC_Initialize" => 1,
"INT_Initialize" => 1,
);

# global config variables initialization

if(TOOL_SCRIPT_DEBUG)
{
	$LISFilePath = ".\\THOR61D_DEMO_PCB01_none_MT6261_S00.lis";
	$callgraphFilePath = ".\\THOR61D_DEMO_PCB01_none_MT6261_S00.txt";
}
else
{
	$LISFilePath = shift;
	$callgraphFilePath = shift;
}

#open DCM_FH,">dcm_post_parsing.log" or output_error_info("can not open file: $!");

# sub functions

sub output_trace_info
{
	my $msg = shift;
	if($TRACE_INFO_ENABLE)
	{
		printf STDOUT "$msg\n";
	}
}

sub output_debug_info
{
	my $msg = shift;
	if($DEBUG_INFO_ENABLE)
	{
		printf STDOUT "[DCM post parsing][info]: $msg\n";
	}
}

sub output_prompt_info
{
	my $msg = shift;
	if($PROMPT_INFO_ENABLE)
	{
		printf STDOUT "$msg";
	}
}

sub output_warning_info
{
	my $msg = shift;
	printf STDOUT "[DCM post parsing]][Error]: $msg\n";
	$totalWarningCnt++;
}

sub output_error_info
{
	my $msg = shift;
	printf STDERR "[[DCM post parsing]][error]: $msg\n";
	exit 1;
}

#***********************************************************
#			step1 parse lis file
#			get all functions in DCM region
#***********************************************************

sub parse_lis
{
	my ($file,$g_symbol_table) = @_;
	open my $info, $file or output_error_info("Could not open $file: $!");
	
	my $line_count = 0;
	my $dynamic_code_region_count = 0;
	while( my $line = <$info>)
	{
		if( $line =~ /Thumb Code.*DYNAMIC_COMP_MAUIINIT_SECTION/ )
		{
			$line =~ /^\s+(\w+)\s+(0x\w{8}).*/;
			push @$g_symbol_table,$1;
		}
	}
	close $info;

	if(0)
	{	
		foreach my $symbol (@$g_symbol_table)
		{
			output_trace_info($symbol);
		}
	}
}


sub parse_CGF
{
	my ($file,$infoDB) = @_;
	open my $CGF, $file or die "Could not open $file: $!";

	while( my $line = <$CGF>){
		if($line =~ /^Global Symbols/){ # starging of global symbol info.
			my $symbolName = undef;
			my $level1Key = undef;
			my $value = undef;
	
			while($line = <$CGF>)
			{
				if($line =~ /\t(.*)\s+\((ARM|Thumb), \d+ bytes,.*\)/)
				{
					$symbolName = $1;
				}
				
				if($line =~ /\t{2}\[(.*)\]/)
				{
					$level1Key = $1;
				}
				
				if($line =~ /\t{3}(.*)/)
				{
					$value = $1;
					if($level1Key eq "Called By" || $level1Key eq "Calls")
					{
						if($value =~ /\(via .*\)/)
						{
							$value =~ / \* (.*)\s+\(via .*\)/;
							$value = $1;
						}
						elsif($value =~ /\(Weak Reference\)/)
						{
							next;
						}
						else
						{
							$value =~ / \* (.*)/;
							$value = $1;
						}
						
						push @{$infoDB->{$symbolName}{$level1Key}},$value;
					}
					elsif($level1Key =~ /Address Reference Count/)
					{
						push @{$infoDB->{$symbolName}{"Reference"}},$value;
					}
					elsif($level1Key ne "Stack")
					{
						output_error_info($level1Key);
					}
				}
				
				if($line =~ /^\n\r/){
					next;
				}
			}
		}
	}
	
	if(0){
		foreach my $symbolName (keys %$infoDB){
			output_trace_info("\t$symbolName");
			my $hash = $infoDB->{$symbolName};
			
			if(!defined $infoDB->{$symbolName}{"Called By"} && !defined $infoDB->{$symbolName}{"Reference"})
			{
				foreach my $l1Key (keys %$hash)
				{
					output_trace_info("\t\t$l1Key");
					my $array = $infoDB->{$symbolName}{$l1Key};
					foreach my $value (@$array)
					{
						output_trace_info("\t\t\t$value");
					}
				}
				die;
			}
			
			foreach my $l1Key (keys %$hash){
				output_trace_info("\t\t$l1Key");
				my $array = $infoDB->{$symbolName}{$l1Key};
				foreach my $value (@$array){
					output_trace_info("\t\t\t$value");
				}
			}
		}
	}
	close $CGF;
}

sub check_symbol
{
	my ($symbol,$infoDB) = @_; 
	
	output_trace_info("check_symbol : $symbol");
	if(defined $InitEntryPointsList{$symbol})
	{
		return 1;
	}
	else
	{
		if(!defined $infoDB->{$symbol}{"Called By"})  # no father
		{
			return 0;
		}
		else
		{
			my $array_father = $infoDB->{$symbol}{"Called By"};
			my $array_father_cnt = @$array_father;
			
			if($array_father_cnt == 1)
			{
				output_trace_info("has one father");
				return check_symbol($array_father->[0],$infoDB);
			}
			else
			{
				output_trace_info("has two or more father");
				foreach my $father (@$array_father)
				{
					if(check_symbol($father,$infoDB) == 1)
					{
						next;
					}
					else
					{
						output_trace_info("more father fail: $father");
						return 0;
					}
				}
				return 1;
			}
		}
	}
}

sub print_callPath
{
	my ($symbol,$infoDB,$callflowInfo) = @_;
	
	$callflowInfo = $callflowInfo." <- $symbol";
	
	if(defined $BlackEndList{$symbol})
	{
		$callflowInfo = $callflowInfo." <- ...\n";
		output_prompt_info($callflowInfo);
		return;
	}
	
	if(defined $InitEntryPointsList{$symbol})
	{
		$callflowInfo = $callflowInfo." <- END\n";
		output_prompt_info($callflowInfo);
		return;
	}
	
	if(!defined $infoDB->{$symbol}{"Called By"})  # no father
	{
		$callflowInfo = $callflowInfo."<-END\n";
		output_prompt_info($callflowInfo);
		return;
	}
	else
	{
		my $array_father = $infoDB->{$symbol}{"Called By"};
		my $array_father_cnt = @$array_father;

		my $i = 0;
		
		foreach my $father (@$array_father)
		{
			print_callPath($array_father->[$i],$infoDB,$callflowInfo);
			$i = $i+1;
		}
	}
}

sub parse_exception_list
{
	my $exceptionFile = ".\\tools\\ddt\\MAUIINIT_in_DCM_exception_list.csv";
	open my $EXF, $exceptionFile or die "Could not open $exceptionFile: $!";

	while( my $line = <$EXF>)
	{
		chomp($line);
		$exceptionList{$line} = 1;
	}
	close $EXF;
}

# main function

my $ErrorFixPrompt = "Please remove the above functions from \'DYNAMIC_COMP_MAUIINIT_SECTION\', or contact \nDCM owner for help.\n";

output_debug_info("MAUIINIT in DCM post parsing start...");
my $start_time = time;

parse_exception_list();
parse_lis($LISFilePath,\@symbol_table);
parse_CGF($callgraphFilePath, $pSymbolInfo);

foreach my $symbolName (@symbol_table)
{
	
	if(check_symbol($symbolName,$pSymbolInfo) == 1)
	{
		output_prompt_info("$symbolName: -> TRUE \n");
	}
	else
	{
		if(not defined $exceptionList{$symbolName})
		{
			output_warning_info("$symbolName: should not be put in DYNAMIC_COMP_MAUIINIT_SECTION");
			output_prompt_info("[CALL FLOW]-$symbolName: \n");
			print_callPath($symbolName,$pSymbolInfo,"\t\t");
		}
	}
}

output_debug_info(sprintf("total takes %ds.",time - $start_time));
output_debug_info("total errors: $totalWarningCnt");

if($totalWarningCnt != 0)
{
	printf STDOUT "$ErrorFixPrompt";
	exit 1;
}

#close DCM_FH;