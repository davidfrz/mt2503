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
#*   scatGenIOTFOTA.pl
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

#use strict;
BEGIN { push @INC, '.\\tools\\' }  # add additional library path
use sysgenUtility;                 #pm file name without case sensitivity
use strict;

#****************************************************************************
# Global variables
#****************************************************************************
my ($strUB_ROM_base,$strUB_ROM_maxsize);
my ($strUB_RAM_base,$strUB_RAM_maxsize);
my $FEATURE_QUERY_FUNCTION_PTR;       
my $DebugPrint    = 1;             # 1 for debug; 0 for non-debug
#****************************************************************************
# Constants
#****************************************************************************
my $SCATGEN_TS_VERNO = "v0.01";
                     #  v0.01 , 2014/07/03 by Yinli, initial draft
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
1;

#****************************************************************************
# MAIN INTERFACE
# input: 
#****************************************************************************
sub scatGenIOTFOTA_main
{
    my ($func,$bb,$mb_scatter) = @_;
    my $ub_layout;
    my $ev_ub_rom;
    
    $FEATURE_QUERY_FUNCTION_PTR = $func;
    
    #parse main-bin scatter file to get update-bin size info
    &Parse_AP_ScatterFile($mb_scatter);

    #gen update-bin EV
    $ev_ub_rom = &layout_ub_rom_ev($bb,$strUB_ROM_base,$strUB_RAM_base,$strUB_RAM_maxsize);

    $ub_layout = <<"__UB_LAYOUT";
UB_ROM $strUB_ROM_base $strUB_ROM_maxsize
{
$ev_ub_rom
}  
__UB_LAYOUT

    return $ub_layout;
}

sub Parse_AP_ScatterFile()
{
    my $mb_scatter = shift;
    open (SCATTER_H,"<$mb_scatter") or scatgenTS_die("[1.0]Cannot open $mb_scatter!",__FILE__,__LINE__);
    while(<SCATTER_H>)
    {
        if(/^\s*UPDATE_ROM\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $strUB_ROM_base = $1;
            $strUB_ROM_maxsize = $2;
        }
        elsif(/^\s*UB_RAM\s*(0x\w+)\s*\w*\s*(0x\w+)/)
        {
            $strUB_RAM_base = $1;
            $strUB_RAM_maxsize = $2;
        }
        last if(defined($strUB_ROM_base) && defined($strUB_ROM_maxsize) && defined($strUB_RAM_base) && defined($strUB_RAM_maxsize));
    }
    close (SCATTER_H) or &scatgenIOTFOTA_die("[1.0]Cannot close $mb_scatter!", __FILE__, __LINE__);
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: 
#****************************************************************************
sub layout_ub_rom_ev
{
    my ($bb,$rom_addr,$ram_addr,$ram_size) = @_;
    my $template;
    $template .= &ub_rom_part_ev($bb,$rom_addr);
    $template .= &ub_ram_part_ev($bb,$ram_addr,$ram_size,'UB_');
    $template .= &ub_signature_section_ev($bb,'+0x0','UB_');
    
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: 
#****************************************************************************
sub ub_rom_part_ev
{
    my($bb,$rom_addr) = @_;
    # --- --- --- 
    my $ev_string;
    ### for SV5
    &scatgenIOTFOTA_die("[1.0]IOTFOTA must be on SV5 platform!", __FILE__, __LINE__) if(&sysUtil::is_sv5($bb) != 1);

    $ev_string  = &format_execution_view(   "UB_ROM_GFH",
                                            $rom_addr,
                                            undef,
                                            ["* (UB_ROM_GFH, +First)",
                                            ]
                                        );

    $ev_string .= &format_execution_view(   "UB_IRT_TABLE_ENTRY",
                                            "+0x0",
                                            undef,
                                            ["ubin_symbol_array.obj (MMISYMBOLARRAY_ROCODE,MMISYMBOLARRAY_RODATA)",
                                            ]
                                        );
    $ev_string .= &format_execution_view(   "UB_ROM_EV",
                                            "+0x0",
                                            undef,
                                            ["* (+RO-CODE,+RO-DATA)",
                                            ]
                                        );   
   return $ev_string;                                     
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: 
# note:  refer to EXTSRAM_type_7() in scatGenLib.pl
#****************************************************************************
sub ub_ram_part_ev
{
    my($bb,$ram_addr,$ram_size,$name_prefix) = @_;
    my $ev_string;
    #--- --- --- --- --- --- --- --- --- --- --- --- ---       
    #UB_EXTSRAM 
    #
    #UB_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL    +0x1000
    #UB_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI                    +0x0
    #UB_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW                  +0x0
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    $ev_string .= &EXTSRAM_EV($name_prefix,$ram_addr);
    $ev_string .= &DYNAMIC_DNC_ZI_MMIPOOL_EV($name_prefix,'+0x1000');
    $ev_string .= &DYNAMIC_DNC_ZI_EV($name_prefix,'+0x0');                                  
    $ev_string .= &DYNAMIC_DNC_RW_EV($name_prefix, '+0x0');

    #--- --- --- --- --- --- --- --- --- --- --- --- ---
    #UB_CACHED_EXTSRAM                                                                                         +0xF0001000
    #--- --- --- --- --- --- --- --- --- --- --- --- ---
    $ev_string .= &CACHED_EXTSRAM_EV($name_prefix,'+0xF0001000');
    $ev_string .= &app_feature_res_prot($name_prefix,$bb,"+0x00");
    $ev_string .= &app_feature_gadget($name_prefix,"+0x00");
    $ev_string .= &DYNAMIC_DC_RW_EV($name_prefix,"+0x1000");
    
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL                  +0x0
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE        +0x0
    #DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI                                  +0x0
    # --- --- --- --- --- --- --- --- --- --- --- --- ---
    $ev_string .= &DYNAMIC_DC_ZI_MMIPOOL($name_prefix,"+0x0");
    if ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
        $ev_string .= &DYNAMIC_DC_ZI_FLMM_PASPACE($name_prefix,'+0x0');
    }
    $ev_string .= &DYNAMIC_DC_ZI($name_prefix,"+0x0");

    $ev_string .= &CACHED_DUMY_END($name_prefix,$ram_addr,$ram_size);

    return $ev_string;
}   

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_EXTSRAM
#****************************************************************************
sub EXTSRAM_EV
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'EXTSRAM';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
        * (NONCACHEDRW, NONCACHEDZI)
        *deniro.lib (+RW, +ZI)
        *fs_fig.lib (+RW, +ZI)
    }
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL
#****************************************************************************
sub DYNAMIC_DNC_ZI_MMIPOOL_EV
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI_MMIPOOL';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
        med_main.obj (LARGEPOOL_ZI)
        * (DYNAMICCACHEABLEZI_NC_MMIPOOL)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI
#****************************************************************************
sub DYNAMIC_DNC_ZI_EV 
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_ZI';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
        * (DYNAMICCACHEABLEZI_NC)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW
#****************************************************************************
sub DYNAMIC_DNC_RW_EV
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_NONCACHEABLE_RW';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
        * (DYNAMICCACHEABLERW_NC)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_CACHED_EXTSRAM
#****************************************************************************
sub CACHED_EXTSRAM_EV
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'CACHED_EXTSRAM';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
; All RW/ZI are put in CACHED region by default
         * (+RW, +ZI)
         * (CACHED_EXTSRAM_RW, CACHED_EXTSRAM_ZI)
    }
__TEMPLATE

    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_EXTSRAM_PROTECTED_RES     
#****************************************************************************
sub app_feature_res_prot
{
	my ($name_prefix,$bb,$base_addr) = @_;
    my $res_prot = &$FEATURE_QUERY_FUNCTION_PTR('res_prot');
    my $nfb_or_emb;
    if (defined &$FEATURE_QUERY_FUNCTION_PTR('nand_flash_booting') and &$FEATURE_QUERY_FUNCTION_PTR('nand_flash_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$FEATURE_QUERY_FUNCTION_PTR('nand_flash_booting');
    }
    elsif (defined &$FEATURE_QUERY_FUNCTION_PTR('emmc_booting') and &$FEATURE_QUERY_FUNCTION_PTR('emmc_booting') ne 'NONE')
    {
    	  $nfb_or_emb = &$FEATURE_QUERY_FUNCTION_PTR('emmc_booting');
    }
    else
    {
    	  $nfb_or_emb = 'NONE';
    }
    my $name_str;
    if ($bb eq 'MT6251')
    {
    	  $name_str = "INTSRAM_PROTECTED_RES";
    }
    elsif ((&sysUtil::is_arm9($bb) == 1) or (&sysUtil::is_arm11($bb) == 1))
    {
        if (defined $nfb_or_emb and $nfb_or_emb ne 'NONE')
        {
            $name_str = "PRIMARY_CACHED_EXTSRAM_PROTECTED_RES";
        }
        else
        {
            $name_str = "CACHED_EXTSRAM_PROTECTED_RES";
        }
    }
    else
    {
    	  $name_str = "EXTSRAM_PROTECTED_RES";
    }
    $name_str = $name_prefix . $name_str;
    if (defined $res_prot and $res_prot eq 'TRUE')
    {
        return &format_execution_view( $name_str,
                                       $base_addr,
                                       undef,
                                       ["* (PROTECTED_RES_HEAD, +First)",
                                        "* (PROTECTED_RES)",
                                        "* (PROTECTED_RES_TAIL, +Last)",
                                       ]
                                     );
    }
    return '';
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_EXTSRAM_GADGET
#****************************************************************************
sub app_feature_gadget
{
    my ($name_prefix,$start_address) = @_;
    my $region_name = $name_prefix . "EXTSRAM_GADGET";
    return &format_execution_view( $region_name,
                                       $start_address,
                                       undef,
                                       ["*gadget_adp.lib (+RW, +ZI)",
                                        "*gadget_lib.lib (+RW, +ZI)",
                                        "* (EXTSRAM_GADGET_RW, EXTSRAM_GADGET_ZI)",
                                       ]
                                     );
}
#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW
#****************************************************************************
sub DYNAMIC_DC_RW_EV
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_RW';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
         * (DYNAMICCACHEABLERW_C)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL
#****************************************************************************
sub DYNAMIC_DC_ZI_MMIPOOL
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_MMIPOOL';
    # we don't support video_standalone in NOR so put VIDEOPOOL_C in asm pool just in case it's be turned on
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
         * (DYNAMICCACHEABLEZI_C_MMIPOOL)
         * (VIDEOPOOL_C)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE
#****************************************************************************
sub DYNAMIC_DC_ZI_FLMM_PASPACE
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI_FLMM_PASPACE';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
         * (FLMM_PASPACE)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI
#****************************************************************************
sub DYNAMIC_DC_ZI
{
    my ($prefix,$base_addr) = @_;
    my $region_name = $prefix . 'DYNAMIC_CACHEABLE_EXTSRAM_DEFAULT_CACHEABLE_ZI';
    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
         * (DYNAMICCACHEABLEZI_C)
    }
__TEMPLATE
    return $template;
}

#****************************************************************************
# subroutine:  Default Layout :: UB_ROM :: Exec View :: EXTSRAM :: XXX_CACHED_DUMMY_END
#****************************************************************************
sub CACHED_DUMY_END
{
    my ($prefix,$base_addr,$max_size) = @_;
    my $end_addr = hex($base_addr) + hex($max_size);
    my $str_end_addr = sprintf("0x%08x",($end_addr|0xF0000000));
    
    my $region_name = $prefix . 'CACHED_DUMMY_END';
    my $template = <<"__TEMPLATE";
    $region_name $str_end_addr
    {
        UBIN_GFH_BODY.obj (UB_DUMMY_SYMBOL)
    }
__TEMPLATE

    return $template;
}
#****************************************************************************
# subroutine:  Default Layout :: ROM :: Exec View :: EXTSRAM :: XXX_ROM_SIGNATURE_SECTION
#****************************************************************************
sub ub_signature_section_ev
{
    my($bb,$base_addr,$prefix) = @_;
    my $region_name = $prefix . 'ROM_SIGNATURE_SECTION';
    my $pragma_name = $prefix . 'SIGNATURE_SECTION';
    ### for SV5
    &scatgenIOTFOTA_die("[1.0]IOTFOTA must be on SV5 platform!", __FILE__, __LINE__) if(&sysUtil::is_sv5($bb) != 1);

    my $template = <<"__TEMPLATE";
    $region_name $base_addr
    {
        * ($pragma_name)
    }
__TEMPLATE
    return $template;
}
#****************************************************************************
# subroutine:  Execution View Generator
# input:       Region name [string], Begin [string], Length [string], Content [Array Reference]
# output:      execution view body string
#****************************************************************************
sub format_execution_view
{
    my ($name, $begin, $length, $ar) = @_;
    my $formated_string = ' ' x 4 . $name . " $begin $length\n";
    $formated_string .= ' ' x 4 . "{\n";
    foreach (@$ar)
    {
    	   $formated_string .= ' ' x 9 . $_ . "\n";
    }
    $formated_string .= ' ' x 4 . "}\n";
    return $formated_string;
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

sub scatgenIOTFOTA_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'SCATGEN_IOTFOTA');
}
