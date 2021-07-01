#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#

use strict;
my $logPath = ".\\build\\$ARGV[0]\\log";
my $logPath_modis = ".\\MoDIS_VC9\\_BUILD_LOG";
my $modisConfig = "false";
my $debugPrint = 0;
if (defined $ARGV[1])
{
  $modisConfig = lc($ARGV[1]);
}
else
{
  $debugPrint = 1;
}
my $filename;

open (Fout, ">comp_err.txt") || die "I can't open $! ";

if ($modisConfig eq "true")
{
  $filename = "${logPath_modis}\\codegen.log";
}
else
{
  $filename = "${logPath}\\codegen.log";
}
if ((-e $filename) && (!-z $filename)) {
  print "Codegen might be failed ==> $filename\n";
  print Fout "Codegen might be failed ==> $filename\n";
  open(F, $filename) || die "I can't open $filename";
  while(<F>) {
    next if (/^\s*$/);
    if ($debugPrint) {
      print "   $_";
    }
    print Fout "   $_";
  }
  close (F);
}

$filename = "${logPath}\\nvram_gen.log";
if ((-e $filename) && (!-z $filename)) {
  print "nvram_auto_gen might be failed ==> $filename\n";
  print Fout "nvram_auto_gen might be failed ==> $filename\n";
  open(F, $filename) || die "I can't open $filename";
  while(<F>) {
    next if (/^\s*$/);
    if ($debugPrint){
      print "   $_";
    }
    print Fout "   $_";
  }
  close (F);
}

if ($modisConfig eq "true")
{
  $filename = "${logPath_modis}\\mcddll_update.log";
}
else
{
  $filename = "${logPath}\\mcddll_update.log";
}
if ((-e $filename) && (!-z $filename)) {
  open(F, $filename) || die "I can't open $filename";
  my $errFlag = 0;
  while(<F>) {
    next if (/^\s*$/);
    next if (/^\[Dependency\]/i);
    next if (/^\[Info\]/i);
    if ($errFlag == 0) {
      $errFlag = 1;
      print "mcddll_update might be failed ==> $filename\n";
      print Fout "mcddll_update might be failed ==> $filename\n";
    }
    if ($debugPrint) {
      print "   $_";
    }
    print Fout "   $_";
  }
  close (F);
}

$filename = "${logPath}\\res_gen.log";
if ((-e $filename) && (!-z $filename)) {
  open(F, $filename ) || die "I can't open $filename";
  my $errFlag = 0;
  while(<F>) {
    if ((/Serious error:/)||(/Error:/i)||(/Fatal error:/)||(/No rule/)||(/dependency errors/)) {
      if ($errFlag == 0) {
        $errFlag = 1;
        if ($debugPrint) {
          print "$filename\n";
        }
        print Fout "$filename\n";
      }
      if ($debugPrint) {
        print "   $_";
      }
      print Fout "   $_";
    }
  } ## while
  close(F);
  if ($errFlag == 1) {
    close (Fout);
    exit 0;
  }
}

if ($modisConfig eq "true")
{
  close (Fout);
  exit 0;
}

my $errModule = 0;
while(defined($filename= <./build/$ARGV[0]/log/*.log>)) {
  next if ($filename =~ /info/);
  next if ($filename =~ /codegen/);
  next if ($filename =~ /res_gen/);
  next if ($filename =~ /objcheck.compile/);
  open(F, $filename ) || die "I can't open $filename";
  my $errFlag = 0;
  my $showthefile = 1;
  my $thefile;
  while(<F>) {
    if (/\/\*.*error\s*:.*\*\//i) {
      next;
    }
    if (/Compiling (\S+)/) {
      $thefile = $1;
      $showthefile = 0;
    } elsif ((/Serious error:/)||(/Error:/i)||(/Fatal error:/)||(/No rule/)||(/dependency errors/) || ((/\bError(s?)\b/)&&($_ !~ /\b0 Errors\b/)&&($filename =~ "bootloader"))) {
      $errModule++;
      if ($errFlag == 0) {
        $errFlag = 1;
        if ($debugPrint) {
          print "$filename\n";
        }
        print Fout "$filename\n";
      }
      if ($debugPrint) {
        ($showthefile == 0) && print "   $thefile:\n";
        print "      $_";
      }
      ($showthefile == 0) && print Fout "   $thefile:\n";
      $showthefile = 1;
      print Fout "      $_";
      last if ($errModule > 300);
    }
  } ## while
  close(F);
  last if ($errModule > 300);
} ## while

if ($errModule == 0) {
  while(defined($filename= <./build/$ARGV[0]/*.log>)) {
    if($filename =~ /_error.log/){
      next;
    }
    open(F, $filename ) || die "I can't open $filename";
    my $errFlag = 0;
    while(<F>) {
      if ((/Serious error:/) || (/Error:/) || (/No rule/) || (/Fatal error:/)) {
        if ($errFlag == 0) {
          $errFlag = 1;
          if ($debugPrint) {
            print "$filename\n";
          }
          print Fout "$filename\n";
        }
        if ($debugPrint) {
          print "   $_";
        }
        print Fout "   $_";
      }
    } ## while
    close(F);
  } ## while
} elsif ($errModule > 300) {
  print "\n   Too many errors. Stop parsing.";
  print Fout "\n   Too many errors. Stop parsing.";
}

close (Fout);
exit 0;
