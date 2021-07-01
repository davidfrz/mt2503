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
#*   cfgGen_EMI.pl
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script generates EMI part in the CFG file for flash tool for SV5
#*
#* Author:
#* -------
#*   Marvin Lin  (mtk03483)
#*
#*============================================================================
#*             HISTORY
#* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*------------------------------------------------------------------------------
#* $Revision$
#* $Modtime$
#* $Log$
#*
#* 02 14 2014 peter.wang
#* [MAUI_03480399] [MT6261] emigen check in
#* .
#*
#* 01 13 2014 peter.wang
#* [MAUI_03480399] [MT6261] emigen check in
#* .
#*
#* 01 06 2014 peter.wang
#* [MAUI_03480399] [MT6261] emigen check in
#* .
#*
#* 12 05 2013 peter.wang
#* [MAUI_03478836] [Serial Flash] [Change Feature] Support GigaDevice 3.0V 8Mbits flash (MD25D80)
#* .
#*
#* 08 27 2013 peter.wang
#* [MAUI_03456976] EMIGen and cfgGen fine tune
#* .
#*
#* 12 31 2012 marvin.lin
#* [MAUI_03302250] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] EMIGEN support MT6260 SPI_NAND
#* change for MT6260C SPI NAND design
#*
#* 11 26 2012 marvin.lin
#* [MAUI_03253498] [MemoryStorage][Auto-Gen][EMI Gen/CFG Gen][Request For Design Change] EMIGEN support MT6260 on 11B and 11BW1132SP2
#* .
#*
#*
#*------------------------------------------------------------------------------
#* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
#*============================================================================
#****************************************************************************/

#****************************************************************************
# Included Modules
#****************************************************************************
use strict;

1;

#****************************************************************************
# Constants
#****************************************************************************
my $CFGGEN_EMI_VERNO = " V0.03";
                      #  v0.03 , Fix compile error when $PLATFORM is not found
                      #  v0.02 , Support MT6255 SF+DDR or DISCRETE_NAND case
                      #  v0.01 , Fix unable to pre-compie custom_EMI_MT6256.c when make new issue
                      #  v0.00 , initial version

#****************************************************************************
# Input Parameters and Global Variables
#****************************************************************************

#****************************************************************************
# subroutine:  get_mem_dev_h_value
# input:       $str_BB_path:  BB folder path
# input:       $href_mem_dev: reference of hash of custom_MemoryDevice.h configurations
#****************************************************************************
sub get_mem_dev_h_value
{
    my ($str_BB_path, $href_mem_dev) = @_;

    my $CUSTOM_MEM_DEV_H = $str_BB_path . "\\custom_MemoryDevice.h";

    open (MEMDEVH_HANDLE, "<$CUSTOM_MEM_DEV_H") or &error_handler("$CUSTOM_MEM_DEV_H: file error!", __FILE__, __LINE__);
    while (<MEMDEVH_HANDLE>)
    {
        if (/^#define\s+(\w+)\s+\((\w*)\)/ || /^#define\s+(\w+)\s+(\w*)/)
        {
            my $option = $1;
            my $value  = $2;

            &error_handler("$CUSTOM_MEM_DEV_H: $option redefined in custom_MemoryDevice.h!", __FILE__, __LINE__) if defined($href_mem_dev->{$option});
            if ((!defined $value) or ($value eq ''))
            {
                $href_mem_dev->{$option} = 'TRUE';
            }
            else
            {
                if ($option =~ /CS(\d+)_PART_NUMBER/)
                {
                    if (($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPSDRAM') or ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPDDR') or ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'LPDDR2'))
                    {
                        if ($value =~ /(\w+)_([A-Za-z0-9]+EVB)/ or $value =~ /(\w+)_(Sapphire28)/i)
                        {
                            $href_mem_dev->{$option} = $1;
                        }
                        else
                        {
                            $href_mem_dev->{$option} = $value;
                        }
                    }
                    elsif ($href_mem_dev->{MEMORY_DEVICE_TYPE} eq 'NOR_LPSDRAM_MCP')
                    {
                        if ($value =~ /(\w+)_([A-Za-z0-9]+EVB)/ or $value =~ /(\w+)_(Sapphire28)/i)
                        {
                            $href_mem_dev->{$option} = $1;
                        }
                        else
                        {
                            $href_mem_dev->{$option} = $value;
                        }
                    }
                    else
                    {
                        $href_mem_dev->{$option} = $value;
                    }
                }
                else
                {
                    $href_mem_dev->{$option} = $value;
                }
            }
        }
    }
    close (MEMDEVH_HANDLE);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no) = @_;

    my $final_error_msg = "CFGGEN ERROR: $error_msg at $file line $line_no\n";
    print $final_error_msg;
    die $final_error_msg;
}

#****************************************************************************
# subroutine:  gen_external_memory_setting
# input:       $str_BB_path:  BB folder path
# return:      External Memory Setting
#****************************************************************************
sub gen_external_memory_setting
{
    my ($str_BB_path, $str_board_ver, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $href_MAKEFILE_OPTIONS) = @_;
    #print "$str_BB_path, $str_board_ver, $bb, $cc_cmd, $via_cmd, $option_tmp_file, $href_MAKEFILE_OPTIONS \n";

    my %MEM_DEV_H_Value;
    &get_mem_dev_h_value($str_BB_path, \%MEM_DEV_H_Value);

    ### EMI setting only needs to exist for DDR
    #if (($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} ne 'LPSDRAM') and ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} ne 'LPDDR') and ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} ne 'LPDDR2'))
    #{
         ### MT6255+SERIAL_FLASH or MT6255+DISCRETE_NAND will use DRAM
    #    if (($bb eq 'MT6255') and ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH' or $MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND'))
    #    {
    #    }
    #    else
    #    {
    #        return;
    #    }
    #}

    ### Generate EMI settings from CFG file for chips which do not support Auto-Gen
    if (($bb ne 'MT6276') and ($bb ne 'MT6256') and ($bb ne 'MT6255') and ($bb ne 'MT6922') and ($bb ne 'MT6250') and ($bb ne 'MT6260') and ($bb ne 'MT6261') and ($bb ne 'MT2501') and ($bb ne 'MT2502'))
    {
        my $EMI_CFG_FILE = $str_BB_path . "\\" . $str_board_ver . "\.cfg";
        open (EMI_CFG_FILE, "<$EMI_CFG_FILE") or &error_handler("$EMI_CFG_FILE: file error!", __FILE__, __LINE__);
        my $saved_sep = $/;
        undef $/;
        my $emi_cfg_file_content = <EMI_CFG_FILE>;
        close EMI_CFG_FILE;
        $/ = $saved_sep;
        my $template = <<"__TEMPLATE";
############################################################################################################
#
#  External Memory Setting
#
############################################################################################################

$emi_cfg_file_content

__TEMPLATE

        return $template;
    }

    ### Pre-compile custom_EMI.c
    my ($custom_EMI_c_file);
    if ($bb eq 'MT6276')
    {
        $custom_EMI_c_file = $str_BB_path . "\\custom_EMI.c";
    }
    else
    {
        if ($bb eq 'MT6922')
        {
            $custom_EMI_c_file = ".\\custom\\common\\hal\\custom_EMI_MT6255.c";
        }
        elsif (($bb eq 'MT2501') or ($bb eq 'MT2502'))
        {
            $custom_EMI_c_file = ".\\custom\\common\\hal\\custom_EMI_MT6261.c";
        }
        else
        {
            $custom_EMI_c_file = ".\\custom\\common\\hal\\custom_EMI_" . $bb . ".c";
        }
    }

    print "custom_EMI.c = $custom_EMI_c_file\n";
    my $status = system("$cc_cmd $via_cmd $option_tmp_file -E $custom_EMI_c_file > ~custom_EMI_c.tmp");
    &error_handler("\\tools\\cfgGen_EMI.pl: pre-compile $custom_EMI_c_file error!", __FILE__, __LINE__) if ($status != 0);

    ### Read flash ID from combo_flash_id.h
    my (@flash_id_str_list, @valid_id_length_list);
    my $mcp_count = 0;
    my $COMBO_FLASH_ID_H = $str_BB_path . "\\combo_flash_id.h";
    open (COMBO_FLASH_ID_H, "<$COMBO_FLASH_ID_H") or &error_handler("$COMBO_FLASH_ID_H: file error!", __FILE__, __LINE__);
    while (<COMBO_FLASH_ID_H>)
    {
        if (/\s+(\d+),\s*\/\/\s*Valid\s+ID\s+length/)
        {
            $valid_id_length_list[$mcp_count] = $1;
        }
        elsif (/\s+\{(.+)\}\s*\/\/\s*Flash\s+ID/)
        {
            $flash_id_str_list[$mcp_count] = $1;
            $mcp_count++;
        }
    }
    close COMBO_FLASH_ID_H;

    #print "MCP count: $mcp_count\n";
    for (0..($mcp_count-1))
    {
        #print "flash_id $_(valid: $valid_id_length_list[$_]): $flash_id_str_list[$_]\n";
    }

    ### Read SPI_NAND clock from custom_sfi_clock.h
    my ($flash_clk, $flash_frequency);
    my $CUSTOM_SFI_CLK_H;
    if ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SPI_NAND')
    {
        $CUSTOM_SFI_CLK_H = $str_BB_path . "\\custom_sfi_clock.h";
        open (CUSTOM_SFI_CLK_H, "<$CUSTOM_SFI_CLK_H") or &error_handler("$CUSTOM_SFI_CLK_H: file error!", __FILE__, __LINE__);
        while (<CUSTOM_SFI_CLK_H>)
        {
            if (/#define __SFI_CLK_(\d+)MHZ__/)
            {
                $flash_clk = $1;
            }
        }

        $flash_frequency .= "SPI_NAND" . "_" . $flash_clk . "MHz";

        close CUSTOM_SFI_CLK_H;
    }
    ### Read SPI_NAND setting from combo_snand_config.h
    my $FLASH_INFO_decl_str;
    my @FLASH_INFO_decl_hash;
    my %flash_settings;
    my $COMBO_SNAND_CONFIG_H;
    my $file_content;
    my $FLASH_INFO_value_str;
    if ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SPI_NAND')
    {
        $COMBO_SNAND_CONFIG_H = $str_BB_path . "\\combo_snand_config.h";
        open (COMBO_SNAND_CONFIG_H, "<$COMBO_SNAND_CONFIG_H") or &error_handler("$COMBO_SNAND_CONFIG_H: file error!", __FILE__, __LINE__);
        {
            local $/;
            $file_content = <COMBO_SNAND_CONFIG_H>;
        }
        close COMBO_SNAND_CONFIG_H;

        ### Trim FLASH Info contents string

        if ($file_content =~ /\"COMBO_MEM_SNAND\"([\s|\S]+?)\}/)
        {
            $FLASH_INFO_value_str = $1;
        }

        print "SPI Nand $FLASH_INFO_value_str\n";

        while ($FLASH_INFO_value_str =~ /0x[\w]{1,8}/)
        {
            push(@FLASH_INFO_decl_hash, $&);
            $FLASH_INFO_value_str = $';  #'
        }

        foreach my $item (@FLASH_INFO_decl_hash)
        {
            print "item : $item, $FLASH_INFO_decl_hash[0], $FLASH_INFO_decl_hash[1], $FLASH_INFO_decl_hash[2], $FLASH_INFO_decl_hash[3], $FLASH_INFO_decl_hash[4], $FLASH_INFO_decl_hash[5]\n";
        }


        $flash_settings{'SNF_DLY_CTL1'} = $FLASH_INFO_decl_hash[0];
        $flash_settings{'SNF_DLY_CTL2'} = $FLASH_INFO_decl_hash[1];
        $flash_settings{'SNF_DLY_CTL3'} = $FLASH_INFO_decl_hash[2];
        $flash_settings{'SNF_DLY_CTL4'} = $FLASH_INFO_decl_hash[3];
        $flash_settings{'SNF_MISC_CTL'} = $FLASH_INFO_decl_hash[4];
        $flash_settings{'DRIVING'}      = $FLASH_INFO_decl_hash[5];
    }

    ### Get Memory Type
    my ($emi_clk, $emi_dev_type, $memory_type);
    my $CUSTOM_EMI_RELEASE_H = $str_BB_path . "\\custom_EMI_release.h";
    open (CUSTOM_EMI_RELEASE_H, "<$CUSTOM_EMI_RELEASE_H") or &error_handler("$CUSTOM_EMI_RELEASE_H: file error!", __FILE__, __LINE__);
    while (<CUSTOM_EMI_RELEASE_H>)
    {
        if (/#define __EMI_CLK_(\d+)MHZ__/)
        {
            $emi_clk = $1;
        }
        elsif (/#define __EMI_DEVICE_(\w+)/)
        {
            $emi_dev_type = $1;
        }
    }
    close CUSTOM_EMI_RELEASE_H;
    if ($emi_dev_type =~ /DDR2/)
    {
        $memory_type = "DDR2";
    }
    elsif ($emi_dev_type =~ /DDR/)
    {
        if ($href_MAKEFILE_OPTIONS->{'sip_ram_size'} eq '256M_BITS' && $bb eq 'MT6255')
        {
            $memory_type = "SIP_DDR";
        }
        else
        {
            $memory_type = "DDR";
        }
    }
    else
    {
        $memory_type = "PSRAM";
    }
    $memory_type .= "_" . $emi_clk . "MHz";
    #print "memory_type=$memory_type\n";

    ### Read EMI settings from ~custom_EMI_c.tmp
    my $file_content;
    open (CUSTOM_EMI_C_TMP, "<~custom_EMI_c.tmp") or &error_handler("~custom_EMI_c.tmp: file error!", __FILE__, __LINE__);
    {
        local $/;
        $file_content = <CUSTOM_EMI_C_TMP>;
    }
    close CUSTOM_EMI_C_TMP;

    ### Get EMI_INFO type declaration
    my $EMI_INFO_decl_str;
    my %EMI_INFO_decl_hash;  # key: EMI register; value: index
    my $EMI_INFO_decl_count = 0;
    if ($file_content =~ /typedef\s*struct\s*\{([\S|\s]+?)\}\s*MTK_EMI_Info/)
    {
        $EMI_INFO_decl_str = $1;
    }
    while ($EMI_INFO_decl_str =~ /\{/)  # Skip all other contents between the beginning { and the real EMI info
    {
        $EMI_INFO_decl_str = $';
    }
    while ($EMI_INFO_decl_str =~ /(EMI_\w+)_value\;/)
    {
        $EMI_INFO_decl_hash{$1} = $EMI_INFO_decl_count;
        $EMI_INFO_decl_count++;
        $EMI_INFO_decl_str = $';
    }

    ### Trim EMI Info contents string
    my $EMI_INFO_value_str;
    if ($file_content =~ /\"EMI_INF\"([\s|\S]+?)\}/)
    {
        $EMI_INFO_value_str = $1;
    }
    $EMI_INFO_value_str =~ s/\s//g;  # EMI_INFO_value_str becomes <EMI_INFO set 1>, "EMI_INF", <EMI_INFO set 2>, ......, "EMI_INF"
    $EMI_INFO_value_str =~ s/^,//;  # Remove the beginning ,
    $EMI_INFO_value_str =~ s/,$//;  # Remove the last ,

    ###
    my $combo_mem_param;
    for (0..($mcp_count-1))
    {
        my $combo_idx = $_ + 1;

        ### Get EMI Info contents
        my @cur_emi_info_value_list;
        if ($EMI_INFO_value_str =~ /\"EMI_INF\"/)
        {
            my $cur_emi_info_value_str = $`;
            print "cur_emi_info_value_str=$cur_emi_info_value_str\n";
            foreach (split(/,/, $cur_emi_info_value_str))
            {
                if (/0x[\w]{1,8}/)
                {
                    push @cur_emi_info_value_list, $_;
                }
            }
            foreach (@cur_emi_info_value_list)
            {
                print "$combo_idx cur_emi_info_value_list: $_\n";
            }
            $EMI_INFO_value_str = $';
        }
        else
        {
            foreach (split(/,/, $EMI_INFO_value_str))
            {
                if (/0x[\w]{1,8}/)
                {
                    push @cur_emi_info_value_list, $_;
                }
            }
            foreach (@cur_emi_info_value_list)
            {
                print "$combo_idx cur_emi_info_value_list: $_\n";
            }
        }

        my %emi_settings;
        if (($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR2') || ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND') || ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH'))
        {
            if (($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6250') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6260') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6261') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT2501') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT2502'))
            {

            }
            else
            {
                $emi_settings{'EMI_CONI'} = &get_emi_setting_from_reg('EMI_CONI', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_CONJ'} = &get_emi_setting_from_reg('EMI_CONJ', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_CONK'} = &get_emi_setting_from_reg('EMI_CONK', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_CONL'} = &get_emi_setting_from_reg('EMI_CONL', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_CONN'} = &get_emi_setting_from_reg('EMI_CONN', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DRVA'} = &get_emi_setting_from_reg('EMI_DRVA', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DRVB'} = &get_emi_setting_from_reg('EMI_DRVB', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLA'} = &get_emi_setting_from_reg('EMI_ODLA', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLB'} = &get_emi_setting_from_reg('EMI_ODLB', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLC'} = &get_emi_setting_from_reg('EMI_ODLC', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLD'} = &get_emi_setting_from_reg('EMI_ODLD', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLE'} = &get_emi_setting_from_reg('EMI_ODLE', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLF'} = &get_emi_setting_from_reg('EMI_ODLF', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_ODLG'} = &get_emi_setting_from_reg('EMI_ODLG', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUTA'} = &get_emi_setting_from_reg('EMI_DUTA', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUTB'} = &get_emi_setting_from_reg('EMI_DUTB', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUTC'} = &get_emi_setting_from_reg('EMI_DUTC', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUCA'} = &get_emi_setting_from_reg('EMI_DUCA', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUCB'} = &get_emi_setting_from_reg('EMI_DUCB', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_DUCE'} = &get_emi_setting_from_reg('EMI_DUCE', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
                $emi_settings{'EMI_IOCL'} = &get_emi_setting_from_reg('EMI_IOCL', \%EMI_INFO_decl_hash, \@cur_emi_info_value_list);
            }
        }
        if (($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR') || ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'LPDDR2') || ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'DISCRETE_NAND'))
        {
            $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
      - flash_info:
            flash_type: NAND
            id_length: $valid_id_length_list[$_]
            flash_id:  [$flash_id_str_list[$_]]
        memory_type: $memory_type
        EMI_Setting:
            EMI_CONI: $emi_settings{'EMI_CONI'}
            EMI_CONJ: $emi_settings{'EMI_CONJ'}
            EMI_CONK: $emi_settings{'EMI_CONK'}
            EMI_CONL: $emi_settings{'EMI_CONL'}
            EMI_CONN: $emi_settings{'EMI_CONN'}
            EMI_DRVA: $emi_settings{'EMI_DRVA'}
            EMI_DRVB: $emi_settings{'EMI_DRVB'}
            EMI_ODLA: $emi_settings{'EMI_ODLA'}
            EMI_ODLB: $emi_settings{'EMI_ODLB'}
            EMI_ODLC: $emi_settings{'EMI_ODLC'}
            EMI_ODLD: $emi_settings{'EMI_ODLD'}
            EMI_ODLE: $emi_settings{'EMI_ODLE'}
            EMI_ODLF: $emi_settings{'EMI_ODLF'}
            EMI_ODLG: $emi_settings{'EMI_ODLG'}
            EMI_DUTA: $emi_settings{'EMI_DUTA'}
            EMI_DUTB: $emi_settings{'EMI_DUTB'}
            EMI_DUTC: $emi_settings{'EMI_DUTC'}
            EMI_DUCA: $emi_settings{'EMI_DUCA'}
            EMI_DUCB: $emi_settings{'EMI_DUCB'}
            EMI_DUCE: $emi_settings{'EMI_DUCE'}
            EMI_IOCL: $emi_settings{'EMI_IOCL'}

__TEMPLATE
        }
        elsif (($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH') and ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6255'))
        {
            $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
      - flash_info:
            flash_type: SF
            id_length: $valid_id_length_list[$_]
            flash_id:  [$flash_id_str_list[$_]]
        memory_type: $memory_type
        EMI_Setting:
            EMI_CONI: $emi_settings{'EMI_CONI'}
            EMI_CONJ: $emi_settings{'EMI_CONJ'}
            EMI_CONK: $emi_settings{'EMI_CONK'}
            EMI_CONL: $emi_settings{'EMI_CONL'}
            EMI_CONN: $emi_settings{'EMI_CONN'}
            EMI_DRVA: $emi_settings{'EMI_DRVA'}
            EMI_DRVB: $emi_settings{'EMI_DRVB'}
            EMI_ODLA: $emi_settings{'EMI_ODLA'}
            EMI_ODLB: $emi_settings{'EMI_ODLB'}
            EMI_ODLC: $emi_settings{'EMI_ODLC'}
            EMI_ODLD: $emi_settings{'EMI_ODLD'}
            EMI_ODLE: $emi_settings{'EMI_ODLE'}
            EMI_ODLF: $emi_settings{'EMI_ODLF'}
            EMI_ODLG: $emi_settings{'EMI_ODLG'}
            EMI_DUTA: $emi_settings{'EMI_DUTA'}
            EMI_DUTB: $emi_settings{'EMI_DUTB'}
            EMI_DUTC: $emi_settings{'EMI_DUTC'}
            EMI_DUCA: $emi_settings{'EMI_DUCA'}
            EMI_DUCB: $emi_settings{'EMI_DUCB'}
            EMI_DUCE: $emi_settings{'EMI_DUCE'}
            EMI_IOCL: $emi_settings{'EMI_IOCL'}

__TEMPLATE
        }
        elsif (($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6250') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6260') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT6261') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT2501') || ($href_MAKEFILE_OPTIONS->{'platform'} eq 'MT2502'))
        {
            if ($MEM_DEV_H_Value{MEMORY_DEVICE_TYPE} eq 'SERIAL_FLASH')
            {
                $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
      - flash_info:
            flash_type: SF
            id_length: $valid_id_length_list[$_]
            flash_id:  [$flash_id_str_list[$_]]
        memory_type: $memory_type
        EMI_Setting:

__TEMPLATE
            }
            else
            {
         $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
      - flash_info:
            flash_type: SPI_NAND
            id_length: $valid_id_length_list[$_]
            flash_id:  [$flash_id_str_list[$_]]
        flash_frequency: $flash_frequency
        SPI_NAND_FLASH_Setting:
            DRIVING: $flash_settings{'DRIVING'}
            SNF_DLY_CTL1: $flash_settings{'SNF_DLY_CTL1'}
            SNF_DLY_CTL2: $flash_settings{'SNF_DLY_CTL2'}
            SNF_DLY_CTL3: $flash_settings{'SNF_DLY_CTL3'}
            SNF_DLY_CTL4: $flash_settings{'SNF_DLY_CTL4'}
            SNF_MISC_CTL: $flash_settings{'SNF_MISC_CTL'}
        memory_type: $memory_type
        EMI_Setting:

__TEMPLATE
            }

        }
        else
        {
            $combo_mem_param .= <<"__TEMPLATE";
       # EMI $combo_idx
      - flash_info:
            flash_type: NOR
            id_length: $valid_id_length_list[$_]
            flash_id:  [$flash_id_str_list[$_]]
        memory_type: $memory_type
        EMI_Setting:

__TEMPLATE
        }
    }

    my $template = <<"__TEMPLATE";
############################################################################################################
#
#  External Memory Setting
#
############################################################################################################

external_memory:
    parameters_version: v1
    parameters:
$combo_mem_param
__TEMPLATE

}

#****************************************************************************
# subroutine:  get_emi_setting_from_reg
# input:       $str_reg:           EMI register string
# input:       $emi_reg_hash_href: reference of EMI register hash
# input:       $emi_set_list_href: reference of EMI settings list
# return:      EMI setting of the input register
#****************************************************************************
sub get_emi_setting_from_reg
{
    my ($str_reg, $emi_reg_hash_href, $emi_set_list_href) = @_;

    if (defined $emi_reg_hash_href->{$str_reg})
    {
        return $emi_set_list_href->[$emi_reg_hash_href->{$str_reg}];
    }
    &error_handler("tools\\cfgGen_EMI.pl: Unable to find EMI settings for EMI register $str_reg!", __FILE__, __LINE__);
}



