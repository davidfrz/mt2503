#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   TSReservedSize_AutoConfig.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script parses LIS and modifies custom_FeatureConfig.h
#*
#* Author:
#* -------
#*   Yinli Liang  (mtk54166)
#*
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path             
use LISInfo;
use FileInfoParser;
use auto_adjust_mem; #pm file name without case sensitivity
use sysGenUtility;
use CommonUtility;
#****************************************************************************
# AutoCheckin Information
#****************************************************************************
use constant OWNER        => "";
#****************************************************************************
# Constants
#****************************************************************************
my $TSSIZE_CONFIG_VERNO    = " v0.02 -> v0.03";
                            #  p0.03,  by Dongming, 20150407, mt2502C slim patch back from MT2502C_DEV, tiny system layout reorg.
                            #  v0.02 , Support dump vector table under tiny mode
                            #  v0.01 , initial draft

#****************************************************************************
# Inputs
#****************************************************************************
my $TS_LIS_FILE_PTH             = $ARGV[0];
my $CUSTOM_FEATURE_CONFIG_H     = $ARGV[1] . "\\custom_FeatureConfig.h";
my $AP_MAKEFILE                 = $ARGV[2];
my $INTERMEDIATE_FILE           = $ARGV[3]; #make\\~TS_LinkError.tmp
my $PROJECT_NAME                = $ARGV[4];
my $LOG_PATH                    = $ARGV[5];
my $AP_SCATTER_FILE_PATH        = $ARGV[6];
my $TS_SCATTER_FILE_PATH        = $ARGV[7];
print "Input parameters:"
    . "\n $TS_LIS_FILE_PTH"
    . "\n $CUSTOM_FEATURE_CONFIG_H"
    . "\n $AP_MAKEFILE"
    . "\n $INTERMEDIATE_FILE"
    . "\n $PROJECT_NAME"
    . "\n $LOG_PATH"
    . "\n $AP_SCATTER_FILE_PATH"
    . "\n $TS_SCATTER_FILE_PATH \n\n";   
#****************************************************************************
# Global Variables
#****************************************************************************
my $g_bAutoConfig          = 0;
my $g_bMAUIHasHistory      = 0;
my $g_bTSHasHistory        = 0;
my $g_bLinkError           = 0;
my $strLinkErrorContent;
#****************************************************************************
# 0 > Parse Log
#****************************************************************************
&tsconfig_die("$INTERMEDIATE_FILE doesn't exist!", __FILE__, __LINE__) if(!-e $INTERMEDIATE_FILE);
my $nLinkError = 0;

open (FILE_HANDLE, "<$INTERMEDIATE_FILE") or &tsconfig_die("$INTERMEDIATE_FILE: file error!", __FILE__, __LINE__);
while (<FILE_HANDLE>)
{
    $strLinkErrorContent .= $_;
    #e.g. Error: L6220E: Load region DEMAND_PAGING_ROM0 size (54932988 bytes) exceeds limit (1048576 bytes).
    if(/L(\S+)E: Load region/)
    {
        $nLinkError++ if($1 ne "6220");
        $g_bLinkError = 1 if($1 eq "6220");
    }
    elsif(/L(\S+)E: Execution region/)
    {
        $nLinkError++;
    }
}
close FILE_HANDLE;

if($nLinkError > 0)
{
    &WriteLog($INTERMEDIATE_FILE, undef, "[AAPMC]tools\TSReservedSize_AutoConfig.pl can't handle this kind of link errors:\n$strLinkErrorContent\n");
    exit ERR::CANNOT_ADJUST;
}

#****************************************************************************
# 1 > Parse MAKEFILE
#****************************************************************************
my (%AP_MAKEFILE_OPTIONS,$BB);
if(1 != &FileInfo::Parse_MAKEFILE($AP_MAKEFILE, \%AP_MAKEFILE_OPTIONS))
{
    print "MakeFile Parse Error: ERR_UNEXPECTED\n";
    exit ERR::ERR_UNEXPECTED;
}
$g_bAutoConfig =1 if(&FileInfo::is("TSRESERVEDSIZE_AUTOCONFIG", "TRUE"));
$BB = $AP_MAKEFILE_OPTIONS{'platform'};

#****************************************************************************
# 2 > Parse scatter file
#****************************************************************************
if($g_bAutoConfig == 1)
{
    $g_bMAUIHasHistory  = &sysUtil::HasCheckinHistory($AP_SCATTER_FILE_PATH);
    $g_bTSHasHistory    = &sysUtil::HasCheckinHistory($TS_SCATTER_FILE_PATH);
    $g_bAutoConfig =0 if((defined $g_bMAUIHasHistory and $g_bMAUIHasHistory == 1) 
                         or (defined $g_bTSHasHistory and $g_bTSHasHistory == 1)
                         or (!defined $g_bMAUIHasHistory)
                         or (!defined $g_bTSHasHistory));  # if the file doesn't exist
}

#****************************************************************************
# 3 > Parse LIS
#****************************************************************************
&LISInfo::ParseLIS($TS_LIS_FILE_PTH);
my ($nTS_ROM1Base, $nTS_ROM1ActualSize, $nTS_ROM1MaxSize, $strTS_ROM1Attr) = LISInfo::GetLoadRegionInfo("TINYSYS_ROM1", 0);
my ($nTS_ROM2Base, $nTS_ROM2ActualSize, $nTS_ROM2MaxSize, $strTS_ROM2Attr) = LISInfo::GetLoadRegionInfo("TINYSYS_ROM2", 0);
my ($nTS_ROM3Base, $nTS_ROM3ActualSize, $nTS_ROM3MaxSize, $strTS_ROM3Attr) = LISInfo::GetLoadRegionInfo("TINYSYS_ROM3", 0);
my $ERR_CODE =&AutoAdjust($nTS_ROM1ActualSize, $nTS_ROM1MaxSize, $nTS_ROM2ActualSize, $nTS_ROM2MaxSize,$nTS_ROM3ActualSize, $nTS_ROM3MaxSize);

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
exit $ERR_CODE;

#****************************************************************************
# subroutines
#****************************************************************************
sub AutoAdjust
{
    my ($nTS_ROM1ActualSize, $nTS_ROM1MaxSize, $nTS_ROM2ActualSize, $nTS_ROM2MaxSize,$nTS_ROM3ActualSize, $nTS_ROM3MaxSize) = @_;
    my $ERR_CODE = ERR::NO_NEED_TO_UPDATE;
    print "[step_1]adjust MAX_TS_ROM1_SIZE/MAX_TS_ROM2_SIZE/MAX_TS_ROM3_SIZE begin...\n";
    print "[max Size]    TINYSYS_ROM1=".&CommonUtil::Dec2Hex($nTS_ROM1MaxSize).", TINYSYS_ROM2=".&CommonUtil::Dec2Hex($nTS_ROM2MaxSize)."\n";
    print "[Actual Size] TINYSYS_ROM1=".&CommonUtil::Dec2Hex($nTS_ROM1ActualSize).", TINYSYS_ROM2=".&CommonUtil::Dec2Hex($nTS_ROM2ActualSize)."\n";
    print "[max Size]    TINYSYS_ROM3=".&CommonUtil::Dec2Hex($nTS_ROM3MaxSize)."\n";
    print "[Actual Size] TINYSYS_ROM3=".&CommonUtil::Dec2Hex($nTS_ROM3ActualSize)."\n";

    my $nTS_ROM1Size_suggest = $nTS_ROM1ActualSize % (1024) == 0 ? 1024*(int($nTS_ROM1ActualSize / 1024)) : 1024*(int($nTS_ROM1ActualSize / 1024)+1);
    my $nTS_ROM2Size_suggest = $nTS_ROM2ActualSize % (1024) == 0 ? 1024*(int($nTS_ROM2ActualSize / 1024)) : 1024*(int($nTS_ROM2ActualSize / 1024)+1);
    my $nTS_ROM3Size_suggest;
    $nTS_ROM3Size_suggest = $nTS_ROM3ActualSize % (1024) == 0 ? 1024*(int($nTS_ROM3ActualSize / 1024)) : 1024*(int($nTS_ROM3ActualSize / 1024)+1);
    print "[Suggest Size]TINYSYS_ROM1=".&CommonUtil::Dec2Hex($nTS_ROM1Size_suggest).", TINYSYS_ROM2=".&CommonUtil::Dec2Hex($nTS_ROM2Size_suggest)."\n";
    print "[Suggest Size]TINYSYS_ROM3=".&CommonUtil::Dec2Hex($nTS_ROM3Size_suggest)."\n";

    my %RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
    if($nTS_ROM1Size_suggest != $nTS_ROM1MaxSize)
    {
        $RegionInfo{TS_ROM1} = [&CommonUtil::Dec2Hex($nTS_ROM1MaxSize), &CommonUtil::Dec2Hex($nTS_ROM1Size_suggest)];
    }
    if($nTS_ROM2Size_suggest != $nTS_ROM2MaxSize )
    {
        $RegionInfo{TS_ROM2} = [&CommonUtil::Dec2Hex($nTS_ROM2MaxSize), &CommonUtil::Dec2Hex($nTS_ROM2Size_suggest)];
    }
    if($nTS_ROM3Size_suggest != $nTS_ROM3MaxSize )
    {
        $RegionInfo{TS_ROM3} = [&CommonUtil::Dec2Hex($nTS_ROM3MaxSize), &CommonUtil::Dec2Hex($nTS_ROM3Size_suggest)];
    }
    #check MAX_TS_MM_DUMP_SIZE
    my ($needAdjust,$nTSMMDumpMaxSize,$nTSMMDumpSize_suggest) = GetTSMMDumpSize($nTS_ROM1Size_suggest,$nTS_ROM2Size_suggest);
    if($needAdjust)
    {
        $RegionInfo{TS_MM_DUMP} = [&CommonUtil::Dec2Hex($nTSMMDumpMaxSize), &CommonUtil::Dec2Hex($nTSMMDumpSize_suggest)];
    }
    #print "nTSMMDumpMaxSize=". &CommonUtil::Dec2Hex($nTSMMDumpMaxSize).",nTSMMDumpSize_suggest=".&CommonUtil::Dec2Hex($nTSMMDumpSize_suggest) . "\n";
    print "\n[step_3]continue...\n";
    my $RegionInfoSize = keys %RegionInfo;
    my $strErrorMsg = "LinkError: \n$strLinkErrorContent\n" if($strLinkErrorContent ne "");
    if($RegionInfoSize != 0)
    {   
        if(!$g_bAutoConfig)
        {
            print "NO CHANGE\n";
            if(&FileInfo::is("TSRESERVEDSIZE_AUTOCONFIG", "TRUE"))
            {
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, ($g_bMAUIHasHistory==1 or $g_bTSHasHistory==1)?
                        "$strErrorMsg\nManual check-in history exists in scatter file.\nPlease remove your own modifications first, \nrebuild and make sure the load is successfully built, \nthen add your own modifications back.\n" : undef);
            }
            else
            {
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, "$strErrorMsg\TSRESERVEDSIZE_AUTOCONFIG=FALSE or not exist, no update.\n");
            }
            $ERR_CODE = $g_bLinkError ? ERR::NO_MODIFY : ERR::NO_NEED_TO_UPDATE;
        }
        else
        {
            my $strModifiedRegionInfo = &GetModifiedInfo(\%RegionInfo);
            my $P4Info_ref =  &AUTO_ADJUST::CreateP4InfoTemplate(OWNER, $PROJECT_NAME, "\n[AutoCheckin]", $strModifiedRegionInfo);
            my %ChangeList;
            map {$ChangeList{"MAX_$_\_SIZE"} = $RegionInfo{$_}[1] }keys %RegionInfo;
            if( ERR::AAPMCLOG_SUCCESS == &AAPMCLogParser::Open($LOG_PATH))
            {
                $ERR_CODE = &AAPMCLogParser::AddOneChangeRecord($CUSTOM_FEATURE_CONFIG_H, \%ChangeList, $P4Info_ref);
                &AAPMCLogParser::Close($LOG_PATH);
            }
            print "Duplicated modification\n" if($ERR_CODE == ERR::ERR_MODIFYDUPLICATED);
            print "Unexpected Error\n" if($ERR_CODE == ERR::ERR_UNEXPECTED);
            if($ERR_CODE == ERR::AAPMCLOG_SUCCESS)
            {
                print "MODIFY SUCCESS\n";
                &WriteLog($INTERMEDIATE_FILE, \%RegionInfo, undef);
            }
        }
    }
    else
    {
        if($g_bLinkError)
        {
            print "$strErrorMsg\nTS Link Error:L6220E Load Region: shouldn't be no adjustment.\n";
            $ERR_CODE = ERR::ERR_UNEXPECTED;
        }
        else
        {
            print "No need to update.\n";
        }
        print "(nTS_ROM1ActualSize, nTS_ROM1MaxSize, nTS_ROM1Size_suggest) = ($nTS_ROM1ActualSize, $nTS_ROM1MaxSize, $nTS_ROM1Size_suggest)\n";
        print "(nTS_ROM2ActualSize, nTS_ROM2MaxSize, nTS_ROM2Size_suggest) = ($nTS_ROM2ActualSize, $nTS_ROM2MaxSize, $nTS_ROM2Size_suggest)\n";
        print "(nTS_MM_DUMPMaxSize, nTS_MM_DUMPSize_suggest) = ($nTSMMDumpMaxSize, $nTSMMDumpSize_suggest)\n";
        print "(nTS_ROM3ActualSize, nTS_ROM3MaxSize, nTS_ROM3Size_suggest) = ($nTS_ROM3ActualSize, $nTS_ROM3MaxSize, $nTS_ROM3Size_suggest)\n";
    }
    print "Return ERR_CODE: $ERR_CODE\n";
    return $ERR_CODE;
}


sub GetTSMMDumpSize
{
    my ($nTS_ROM1Size_suggest,$nTS_ROM2Size_suggest) = @_;
    print "\n[step_2]adjust MAX_TS_MM_DUMP_SIZE begin...\n";
    # 1 > get current TS_MM_DUMP size
    my (%FEATURE_CONFIG_Value,$nTSMMDumpMaxSize) = (undef,0x0);
    &FileInfo::ParseDefinition($CUSTOM_FEATURE_CONFIG_H,\%FEATURE_CONFIG_Value,0);
    if(defined $FEATURE_CONFIG_Value{MAX_TS_MM_DUMP_SIZE})
    {   #value in custom_feature_config.h has higer priority
        $nTSMMDumpMaxSize = hex($FEATURE_CONFIG_Value{MAX_TS_MM_DUMP_SIZE});
    }
    else
    {   #value in script is the default 
        my ($strTSMMDumpSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize(sub { my ($key) = @_;
                                                                                                                                  if (exists $AP_MAKEFILE_OPTIONS{$key})
                                                                                                                                  {   return $AP_MAKEFILE_OPTIONS{$key};
                                                                                                                                  }
                                                                                                                                  else
                                                                                                                                  {   return undef;
                                                                                                                                  }
                                                                                                                                },
                                                                                                                                $BB,
                                                                                                                                \%FEATURE_CONFIG_Value);
        $nTSMMDumpMaxSize = hex($strTSMMDumpSize);
        print "$BB: nTSMMDumpMaxSize=$nTSMMDumpMaxSize,$strTSMMDumpSize\n";
    }
    # 2 > get memory dump size and image size of Tiny System
    my ($nTSMMDumpSize_suggest,$nTS_ImageSize,$nTSMMDumpActualSize) = (0,0,0);
    {  
        # 2.1 > get all RW/ZI and reserved size for dump register on TS mode (user_1)
        print "get all RW/ZI and reserve size for dump register on TS mode\n";
        &LISInfo::ts_ClassifyRegionType();
        my $DumpRegions_ref = &LISInfo::ts_GetDumpExeRegions();
        foreach my $strGroupName (%$DumpRegions_ref)
        {
            my $array_ref = $DumpRegions_ref->{$strGroupName};
            foreach my $RegionItem (@$array_ref)
            {
                foreach my $RegionName (@$RegionItem)
                {
                    my $nRegionActualSize = 0x0;
                    if($RegionName eq "TS_DUMP_VECTOR_TABLE")
                    {
                        my ($nRegionBase, $nRegionMaxSize, $strRegionAttr);
                        ($nRegionBase,$nRegionActualSize,$nRegionMaxSize, $strRegionAttr)= &LISInfo::GetExeRegionInfo($RegionName, 0);
                        $nRegionActualSize = $nRegionMaxSize; #always dump 64byte vector table under tiny mode
                    }
                    elsif($RegionName =~ /_EV$/)
                    {
                        my($dumpBase,$dumpEnd);
                        #custom_query_ts_dump_region() in custom_tsconfig.c will define linker symbols used in memory dump
                        $dumpBase = &LISInfo::GetLinkerSymbolInfo("Image\$\$$RegionName\$\$RW\$\$Base");
                        $dumpEnd = &LISInfo::GetLinkerSymbolInfo("Image\$\$$RegionName\$\$ZI\$\$Limit");
                        $nRegionActualSize = (defined $dumpBase and defined $dumpEnd)? (hex($dumpEnd)-hex($dumpBase)): 0x0;
                        #print "$RegionName: $dumpBase,$dumpEnd\n";
                    }
                    else
                    {
                        my ($nRegionBase, $nRegionMaxSize, $strRegionAttr);
                        ($nRegionBase,$nRegionActualSize,$nRegionMaxSize, $strRegionAttr)= &LISInfo::GetExeRegionInfo($RegionName, 0);
                    }
                    
                    $nTSMMDumpActualSize += $nRegionActualSize;
                    print "\t$strGroupName -> $RegionName : " . &CommonUtil::Dec2Hex($nRegionActualSize) . "\n";
                } 
            }
        }
        #reserved 1kB for dump register and 256Byte for exception handler store materials
        $nTSMMDumpActualSize += (1024 + 256);
        # 1kB alignment
        $nTSMMDumpActualSize = (($nTSMMDumpActualSize%1024)==0)? 1024*(int($nTSMMDumpActualSize / 1024)) : 1024*(int($nTSMMDumpActualSize / 1024)+1);
        
        # 2.2 > get TS image size (user_2)
        $nTS_ImageSize = $nTS_ROM1Size_suggest + $nTS_ROM2Size_suggest;
    }
    
    # 3 > get suggstion size: $nTSMMDumpSize_suggest should be the bigger one between user_1 and user_2
    print "[Max Size]    nTSMMDumpMaxSize=" . &CommonUtil::Dec2Hex($nTSMMDumpMaxSize). "\n";
    print "[Actual Size] nTSMMDumpActualSize=" . &CommonUtil::Dec2Hex($nTSMMDumpActualSize) . ",nTS_ImageSize=" . &CommonUtil::Dec2Hex($nTS_ImageSize) . "\n";
    $nTSMMDumpSize_suggest = ($nTSMMDumpActualSize > $nTS_ImageSize)? $nTSMMDumpActualSize : $nTS_ImageSize ;
    print "[Suggest Size]nTSMMDumpSize_suggest=" . &CommonUtil::Dec2Hex($nTSMMDumpSize_suggest). "\n";
    return ($nTSMMDumpMaxSize != $nTSMMDumpSize_suggest)? (1,$nTSMMDumpMaxSize,$nTSMMDumpSize_suggest):(0,$nTSMMDumpMaxSize,$nTSMMDumpSize_suggest);
}
#****************************************************************************
# subroutine:  GetModifiedInfo
#              to get Modified Region information
# input:       $RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
#              strRegionName: Load Region Name
#              strOrgMaxSize: Original MaxSize
#              strMaxSize_suggest: Suggested MaxSize
# output:      $strInfo - Modified region information
#****************************************************************************
sub GetModifiedInfo
{
    my ($RegionInfo_ref) = (@_);
    my $strInfo;
    $strInfo =  "[Before auto adjustment]\n";
    map {$strInfo .= $_." MAXSIZE=".$RegionInfo_ref->{$_}[0]."\n" } keys %$RegionInfo_ref;
    $strInfo .= "[After auto adjustment]\n";
    $strInfo .= "In custom\\system\\[BB]\\custom_featureconfig.h:\n";
    map {$strInfo .= "RECOMMAND: Please set MAX_".$_."_SIZE=".$RegionInfo_ref->{$_}[1]."\n" } keys %$RegionInfo_ref;
    return $strInfo;
}

#****************************************************************************
# subroutine:  WriteLog
# input:       $LogPath: Log Path
#              $RegionInfo; # Key: strRegionName, Value=[strOrgMaxSize, strMaxSize_suggest]
#              strRegionName: Load Region Name
#              strOrgMaxSize: Original MaxSize
#              strMaxSize_suggest: Suggested MaxSize
#              $strMsg: comment
#****************************************************************************
sub WriteLog
{
    my ($LogPath, $RegionInfo_ref, $strMsg) = (@_);
    print $strMsg if(defined $strMsg);    
    my $strModifiedInfo;
    if(defined $RegionInfo_ref)
    {
        $strModifiedInfo = &GetModifiedInfo($RegionInfo_ref);
        print $strModifiedInfo;
    }
    open (FILE_HANDLE, ">$LogPath") or &tsconfig_die("Cannot open log: $LogPath\n", __FILE__, __LINE__);
    print FILE_HANDLE $strMsg if(defined $strMsg);
    if(defined $RegionInfo_ref)
    {
        print FILE_HANDLE $strModifiedInfo;
    }   
    close FILE_HANDLE;
}
#****************************************************************************
# subroutine:  tsconfig_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub tsconfig_die
{
    my ($error_msg, $file, $line_no) = @_;
    &AUTO_ADJUST::error_handler($error_msg, $file, $line_no, 'TSReservedSize_Config');
}
