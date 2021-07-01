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
#*   scatGenTS.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script designed as module to be include by top level perl script
#*
#* Author:
#* -------
#*   Yinli Liang  (mtk54166)
#*
#****************************************************************************/

use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysGenUtility;                 #pm file name without case sensitivity
use CommonUtility;
#global variables
my $FEATURE_QUERY_FUNCTION_PTR;
my $ref_BoardParameters;
my $AP_SCATTERFILE;
my $TS_SCATTERFILE;
my $ref_FEATURE_CONFIG_Value;
my $BB;
my ($strTS_ROM1_base,$strTS_ROM2_base);#LV base equal to EV base
my ($strTS_ROM1_LV_maxsize,$strTS_ROM2_LV_maxsize);#LV max-size
my ($strTS_ROM1_EV_maxsize,$strTS_ROM2_EV_maxsize);#EV max-size
my ($strTS_ROM3_LV_Base, $strTS_ROM3_LV_maxsize);

my $DebugPrint    = 1;             # 1 for debug; 0 for non-debug
#****************************************************************************
# Constants
#****************************************************************************
my $SCATGEN_TS_VERNO = " v0.02 -> p0.03 -> p0.04 -> p0.05 -> p0.06 -> p0.07 -> p0.08";
                     #  p0.08   2015/04/07 by Dongming, mt2502C slim patch back from MT2502C_DEV, tiny system layout reorg.
                     #  p0.07 , 2014/05/30 by Yinli, Adjust TS_ROM1 execution region max-size setting: TS_ROM1_EV 35kB/TS_ROM1_ZI 9kB
                     #  p0.06 , 2014/05/19 by Yinli, Support Tiny System AAPMC
                     #  p0.05 , 2014/05/19 by Yinli, TS layout improvement
                     #  p0.04 , 2014/05/19 by Yinli, set Tiny-mode logging buffer size depend on AP-mode TST_RING_BUFFER_SIZE
                     #  p0.03 , 2014/05/19 by Yinli, remove DSPRAM bakeup on EMI
                     #  v0.02 , 2014/03/25 by Yinli, set a dummy end to restrict the max size of TINYSYS_ROM1 EV
                     #  v0.01 , 2014/02/21 by Yinli, initial draft

#****************************************************************************
# oo >>>  Finished
#****************************************************************************
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenTS_main
{
    ($FEATURE_QUERY_FUNCTION_PTR, $ref_BoardParameters,$AP_SCATTERFILE, $TS_SCATTERFILE,$ref_FEATURE_CONFIG_Value) = @_;
    $BB = $ref_BoardParameters->{'BB'};
    
    #parse AP(MAUI) scatter to get TS_ROM1/TS_ROM2 LV maxsize
    &Parse_AP_ScatterFile($AP_SCATTERFILE);

    #get TS_ROM1/TS_ROM2 base address and EV maxsize
    ($strTS_ROM1_base,$strTS_ROM1_EV_maxsize) = &sysUtil::GetTS_IntsramInfo_under_tiny_mode($BB);

    if($BB eq 'MT6260')
    {#use EMI to simulate DSPRAM for 60 demo
        my ($strTSMMDumpSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($FEATURE_QUERY_FUNCTION_PTR,$BB,$ref_FEATURE_CONFIG_Value);
        $strTSMMDumpSize = (exists $ref_FEATURE_CONFIG_Value->{MAX_TS_MM_DUMP_SIZE})? $ref_FEATURE_CONFIG_Value->{MAX_TS_MM_DUMP_SIZE}
                                                                                    : $strTSMMDumpSize;
        my $total_res_size = hex($strCSCIInfoSize)+hex($strTSMMDumpSize)+hex($strAPIntsramBakSize)+hex($strTSLogSize)+hex($strTSResEmiSize);
        $strTS_ROM2_EV_maxsize = $strTSResEmiSize;
        $strTS_ROM2_base = &CommonUtil::Dec2Hex($ref_BoardParameters->{'EXTSRAM'}-$total_res_size);
    }
    else
    {#on DSPRAM
        ($strTS_ROM2_base,$strTS_ROM2_EV_maxsize) = &sysUtil::GetTS_DspramInfo($BB);
    }

    #generate $TS_SCATTERFILE
    &GenerateFile($TS_SCATTERFILE, undef);
}

#****************************************************************************
# subroutine:  GenerateFile
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
#              $PreprocessFunc_ref = to preprocess if there is any condition 
#                                    which needs to be tested before generating
# Output:      x
#****************************************************************************
sub GenerateFile
{
    my ($strFilePath, $PreprocessFunc_ref) = @_;
    if(&isToGen($strFilePath))
    {
        &$PreprocessFunc_ref() if(defined $PreprocessFunc_ref);
        my $content = &ProcessTemplate($strFilePath);
        &WriteFile($strFilePath, $content);
        print "$TS_SCATTERFILE is generated\n";
    }
}
#****************************************************************************
# subroutine:  isToGen
# Input:       $strFilePath = the file to be generated if it exists without check-in history.
# Output:      $bToGen: undef = not to generate file, 1=need to generate file 
#****************************************************************************
sub isToGen
{
    my ($strFilePath) = @_;
    my $bToGen = undef;
    if(-e $strFilePath)
    {
        $bToGen = 1 if(1 != &sysUtil::HasCheckinHistory($strFilePath));
    }
    else
    {
        &scatgenTS_die("[1.0]$strFilePath: the template must exist!", __FILE__, __LINE__);   
    }
    return $bToGen;
}
#****************************************************************************
# subroutine:  ProcessTemplate
# Input:       $strFilePath: the file to be processed
# Output:      $content: the content after processing
# Description: if there is the pattern as [AUTOGEN_funcname], 
#              the whole pattern will be replaced by calling funcname().
#              if funcname() doesn't exist, it'll fail and report error.
#****************************************************************************
sub ProcessTemplate
{
    my ($strFilePath) = @_;
    my $content;
    open (FILE_HANDLE, $strFilePath) or &scatgenTS_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
    while(<FILE_HANDLE>)
    {
        my $strLine = $_;
        while ($strLine =~ /\[AUTOGEN_(\w+)\]/)
        {
            my $func = $1;
            my $template;
            {
                no strict 'refs';
                $template = &{$func}() if(exists &{$func}) 
                    or &scatgenTS_die("[2.0]$func() doesn't exist!\n", __FILE__, __LINE__);
            }
            $strLine =~ s/\[AUTOGEN_$func\]/$template/g;
        }
        $content .= $strLine;
    }
    $content .= &GenTINYSYS_ROM3_Layout();
    close FILE_HANDLE;
    return $content;
}
#****************************************************************************
# subroutine:  WriteFile
# Input:       $strFilePath: the file to be generated
#              $content: the content to be written into $strFilePath
# Output:      x
#****************************************************************************
sub WriteFile
{
    my ($strFilePath, $content) = @_;
    open (FILE, ">$strFilePath") or &scatgenTS_die("[1.0]Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE $content;
    close FILE;
}

sub Parse_AP_ScatterFile()
{
   my $ap_scatter = shift;
   open (SCATTER_H,"<$ap_scatter") or scatgenTS_die("[1.0]Cannot open $ap_scatter!",__FILE__,__LINE__);
   while(<SCATTER_H>)
   {
        if(/^\s*TS_ROM1\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $strTS_ROM1_LV_maxsize = $2;
        }
        elsif(/^\s*TS_ROM2\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $strTS_ROM2_LV_maxsize = $2;
        }
        elsif(/^\s*TS_EMI_CODE_EV\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $strTS_ROM3_LV_Base = $1;
            $strTS_ROM3_LV_maxsize = $2;
        }
        last if(defined($strTS_ROM1_LV_maxsize) && defined($strTS_ROM2_LV_maxsize) && defined($strTS_ROM3_LV_maxsize));
   }
   close (SCATTER_H) or &scatgenTS_die("[1.0]Cannot close $ap_scatter!", __FILE__, __LINE__);
}
sub QueryFileName_TS
{
    my $filename;
    $filename = $1 if($TS_SCATTERFILE =~ /(\w+\.txt)/);
    return $filename;
}
sub GenVersion
{
    return "system auto generator". $SCATGEN_TS_VERNO;
}

sub GenDate
{
    my ($day, $month, $year) = (localtime)[3,4,5]; $month++; $year+=1900;
    return "$year/$month/$day";
}

#****************************************************************************
# subroutine:  GetTINYSYS_ROM1BaseAndSize
# description: get TINYSYS_ROM1 LV base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTINYSYS_ROM1BaseAndSize()
{
    return $strTS_ROM1_base. ' '. $strTS_ROM1_LV_maxsize;
}
#****************************************************************************
# subroutine:  GetTS_ROM1_EVSize
# description: get TS_ROM1_EV max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTS_ROM1_EVSize
{
    &scatgenTS_die("[2.0]TS_ROM1_EV max-size setting base on TS_ROM1 EV total size is 0xB000, but now is $strTS_ROM1_EV_maxsize\n", __FILE__, __LINE__) if(hex($strTS_ROM1_EV_maxsize) != 0xB000) ;

    #TS_ROM1 use 44kB TCM area as its working space (32k cache + 8k TCM + 4k TCM for ALICE)
    #The front 32k size of TS_ROM1 image can be loaded under 206M clock and the loader code (memcpy) on AP side can be put in 8k TCM,
    #so using RO/RW to fill in TS_ROM1 front 32k area , and the left area (44-32)k is filled in by ZI can reduce TS_ROM1 image loading time
    #but because total ZI is less than 12k, so using RO/RW to fill in front (32+3)k area, and using ZI to fill in left (44-35)k area
    #and reserve 0x80 for GFH/Signature size, to make sure TS_ROM1 image size is less than (32+3)kB
    
    my $max_size = 0x8C00 - 0x80; 
    return &CommonUtil::Dec2Hex($max_size);
}

#****************************************************************************
# subroutine:  GetTS_ROM1_ZISize
# description: get GetTS_ROM1_ZI max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTS_ROM1_ZISize
{
    &scatgenTS_die("[2.0]TS_ROM1_ZI max-size setting base on TS_ROM1 EV total size is 0xB000, but now is $strTS_ROM1_EV_maxsize\n", __FILE__, __LINE__) if(hex($strTS_ROM1_EV_maxsize) != 0xB000) ;
    #the left 9kB area of TS_ROM1 can be filled up by ZI, to make sure TS_ROM1 size is less than 35kB
    my $max_size = 0xB000 - 0x8C00;
    return &CommonUtil::Dec2Hex($max_size);
}

#****************************************************************************
# subroutine:  GetTINYSYS_ROM2BaseAndSize
# description: get TINYSYS_ROM2 LV base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTINYSYS_ROM2BaseAndSize()
{
    return $strTS_ROM2_base.' '.$strTS_ROM2_LV_maxsize;
}
#****************************************************************************
# subroutine:  GetTS_ROM2_EVSize
# description: get GetTS_ROM2_EV max-size
# Input:      
# Output:      
#****************************************************************************
sub GetTS_ROM2_EVSize
{
    my ($strTSMMDumpSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($FEATURE_QUERY_FUNCTION_PTR,$BB,$ref_FEATURE_CONFIG_Value);  
    #TS_ROM2_EV max-size = TS_ROM2 max_size - CSCI_DATA max-size
    #reserve 0x80 for GFH/Signature size
    my $max_size = hex($strTS_ROM2_EV_maxsize) - hex($strCSCIInfoSize) - 0x80;
    return &CommonUtil::Dec2Hex($max_size);
}

#****************************************************************************
# subroutine:  GenTINYSYS_ROM3_Layout
# description: gen TINYSYS_ROM3 Layout
# Input:      
# Output:      
#****************************************************************************
sub GenTINYSYS_ROM3_Layout()
{
    $strTS_ROM3_LV_maxsize = (exists $ref_FEATURE_CONFIG_Value->{MAX_TS_ROM3_SIZE})? $ref_FEATURE_CONFIG_Value->{MAX_TS_ROM3_SIZE}
                                                                                : $strTS_ROM3_LV_maxsize;

    #$ts_rom3_ev_size size and $strTS_ROM3_LV_maxsize are from different place. 
    #$ts_rom3_ev_size size is equal to TS_EMI_CODE_EV ev size.TS_EMI_CODE_EV is located at AP scatfile
    my $ts_rom3_ev_size = &sysUtil::GetTS_ROM3Info($BB);
    if(exists $ref_FEATURE_CONFIG_Value->{MAX_TS_ROM3_EMI_SIZE})
    {
        $ts_rom3_ev_size = $ref_FEATURE_CONFIG_Value->{MAX_TS_ROM3_EMI_SIZE};
    }
    #we should exclude the GFH value.
    $ts_rom3_ev_size = sprintf("0x%08x",hex($ts_rom3_ev_size) - 0x80);
    my $layout_ts_rom3 = <<"__TS_ROM3_LAYOUT";
TINYSYS_ROM3 $strTS_ROM3_LV_Base $strTS_ROM3_LV_maxsize
{
    TS_ROM3_GFH +0x0
    {
        * (TINY_SYS_ROM3_GFH)
    }
;TS_EMI_CODE_REGION max size = MAX_TS_ROM3_EMI_SIZE - GFH_Size(0x80)
;TS_ROM2_GFH_size real size is 0x38, we reserve 0x80 for flexible
    TS_EMI_CODE_REGION +0x0 $ts_rom3_ev_size
    {
				* (TS_EMI_ROCODE)
				* (TS_EMI_RODATA)
				* (TS_EMI_RWDATA)
				* (TS_EMI_ZI)
    }

}
__TS_ROM3_LAYOUT
    return $layout_ts_rom3;
}

#****************************************************************************
# subroutine:  GetCSCI_DATABaseAndSize
# description: get execution region GetCSCI_DATABaseAndSize base and max-size
# Input:      
# Output:      
#****************************************************************************
sub GetCSCI_DATABaseAndSize
{
    my ($strCSCI_DATA_base,$strCSCI_DATA_size);
    my ($strTSMMDumpSize,$strAPIntsramBakSize,$strTSLogSize,$strTSResEmiSize,$strCSCIInfoSize) = &sysUtil::GetTS_ResMemSize($FEATURE_QUERY_FUNCTION_PTR,$BB,$ref_FEATURE_CONFIG_Value);
    $strTSMMDumpSize = (exists $ref_FEATURE_CONFIG_Value->{MAX_TS_MM_DUMP_SIZE})? $ref_FEATURE_CONFIG_Value->{MAX_TS_MM_DUMP_SIZE}
                                                                                : $strTSMMDumpSize;

    if($BB eq 'MT6260')
    {#on EMI
        my $total_res_size = hex($strCSCIInfoSize)+hex($strTSMMDumpSize)+hex($strAPIntsramBakSize)+hex($strTSLogSize)+hex($strTSResEmiSize); 
        $strCSCI_DATA_base = &CommonUtil::Dec2Hex($ref_BoardParameters->{'EXTSRAM'}-$total_res_size+hex($strTSResEmiSize)-hex($strCSCIInfoSize));
        $strCSCI_DATA_size = $strCSCIInfoSize;
    }
    else
    {#on DSPRAM
        my ($strDSPRAM_base,$strDSPRAM_size) = &sysUtil::GetTS_DspramInfo($BB);
        $strCSCI_DATA_base = &CommonUtil::Dec2Hex(hex($strDSPRAM_base)+hex($strDSPRAM_size)-hex($strCSCIInfoSize));
        $strCSCI_DATA_size = $strCSCIInfoSize;
    }    
    return $strCSCI_DATA_base .' '.$strCSCI_DATA_size;
}

#****************************************************************************
# subroutine:  GetTS_ROM1_DUMMY_ENDBase
# description: get TINYSYS_ROM1 EV end address
# Input:      
# Output:      
#****************************************************************************
sub GetTS_ROM1_DUMMY_ENDBase
{
    my $nEnd_addr = hex($strTS_ROM1_base) + hex($strTS_ROM1_EV_maxsize);
    return sprintf("0x%08x",$nEnd_addr);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle ERROR: $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}

sub scatgenTS_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SCATGEN_TS');
}

