#!/usr/bin/env perl
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
use strict;
use File::Basename;
#****************************************************************************
# Input Parameters & Global Variables
#****************************************************************************
my $sym_f = $ARGV[0];
my $out_f = $ARGV[1];
my $infomake_f   = $ARGV[2];
my $comp_lib_dir = $ARGV[3];
my $cus_mtk_lib  = $ARGV[4];
my $custom_release  = $ARGV[5];
my %CUS_REL_SRC_COMP = ();
my %CUS_REL_MTK_COMP = ();
my %COMPOBJS = ();


# read release type of module from infomake.log
open(FILE_INFO, "<$infomake_f") or die "Error: Fail to open $infomake_f $!"; 
while(<FILE_INFO>){
	if ($_ =~ /\bCUS_REL_SRC_COMP\s*=\s*(.+)/i){
		my $cus_rel_src_comp = $1;
		%CUS_REL_SRC_COMP = map {$_ => 1} split(/\s+/,$cus_rel_src_comp);
	}
	if ($_ =~ /\bCUS_REL_MTK_COMP\s*=\s*(.+)/i){
		my $cus_rel_mtk_comp = $1;
		%CUS_REL_MTK_COMP = map {$_ => 1} split(/\s+/,$cus_rel_mtk_comp);
	}
	if ($_ =~ /\bCOMPOBJS\s*=\s*(.+)/i){
		my $compobjs = $1;
		my @compobjs_arr = split(/\s+/,$compobjs);
		foreach my $lib_path (@compobjs_arr) {
			my $libname = basename($lib_path);
			$libname =~ /(.*)\.[a|lib]/;
			$libname = $1;
			$COMPOBJS{$libname} = dirname($lib_path);
		}
	}
}
close FILE_INFO;

open(FILE_HANDLE, "<$sym_f") or die "Error: Fail to open $sym_f $!"; 
open(FILE_OUT, ">$out_f") or die "Error: Fail to open $out_f $!"; 
while (<FILE_HANDLE>)
{
	chomp $_;
	print FILE_OUT "$_\n" if ($_ =~ /--keep/);
	if($_ =~ /(.*)\.lib/ || $_ =~ /(.*)\.a/)
	{
		my $lib = $1;
		if (exists $CUS_REL_SRC_COMP{$lib}) {
			print FILE_OUT "$comp_lib_dir\\$_\n";
		} 
		elsif (exists $CUS_REL_MTK_COMP{$lib}) {
			if ($custom_release eq "TRUE") {
				print FILE_OUT "$cus_mtk_lib\\$_\n";
			}
			else {
				print FILE_OUT "$comp_lib_dir\\$_\n";
			}
		}
		elsif (exists $COMPOBJS{$lib}) {
			print FILE_OUT "$COMPOBJS{$lib}\\$_\n";
			print "$COMPOBJS{$lib}\\$_\n";
		}
		else {
			warn "$lib do NOT in CUS_REL_XXX_COMP!\n";
		}
	}
}
close FILE_HANDLE;
close FILE_OUT;

