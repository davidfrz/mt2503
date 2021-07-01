my $PMU_INITSETTING_VERNO     = " V1.00";
$time =localtime(time);

#time information for ECO Version Check, ex: ECO_Version_Check_2011_12_22
my ($sec, $min, $hour, $day, $mon, $year) = localtime(time);
$now_date=join("_",($year+1900,$mon+1,$day));	#�~ $year �O�q1900 �~�Һ�F�Ӥ�����ܬO�q0�_��
$now_time=join(":",($hour,$min,$sec));
#print "$sec, $min, $hour, $day, $mon, $year, $now_date, $now_time\n"; 

my @desc_list = ("pmu_init.c", 
                       "This file provide for pmu initial setting",
                                 "Oscar Liu", $PMU_INITSETTING_VERNO, $time);
#information by pmu chip                                 
$pmu = 1;   # pmu = 0 if using PMIC                                 
$pmu_name;                                 


print "Input file :";
#my $data_file = <STDIN>;
chomp($data_file=<STDIN>);
#pmu initial parameter
@address;
@mask;
@value;

#pmic initial parameter
@APshift;
@APmask;
@APvalue;
@APbank;

#Flag for using SW version or HW version
@HW_Version_Flag;
$HW_ECO_Gen_Flag = 0;
$pre_majrev = 0;

#SW Version
@MAJREV;
@MINREV;

#ECO Version
@ECO;	#c code string
@ECO_version;
$ECO_number = 0;
$ECO_array_number = 0;

$data_number = 0;	#number of initial data
$latest_ECOversion = 0;
$parsing = 0;
$linenumber = 0;


open(IN_FILE_INDEX,$data_file) || die("Could not open file!");
@raw_data = <IN_FILE_INDEX>;	#put the input data to raw_data(array)

foreach $data_handle (@raw_data)	#parsing PMU/PMIC and total ECO number;
{
	if($data_handle =~/^\/\// )	#check //�}�Y��string	
	{
	}
	else
	{
		$data_handle =~ s/\s+//g;	#remove all white space
	}	
	
	if($data_handle =~/^MT(\d+)/)
	{
		$chip_number = $1;
		#print $pmu_name;
	}
	
	if($data_handle =~/^PMIC/ )	#check �O�_��ECO�}�Y, check ECO version
	{
		$pmu = 0;
		#print $pmu;	
	}	
				
	if($data_handle =~/^ECO_TRUE_E(\d+)/)
	{
		$ECO_version[$1]=1;	#save the ECO_Ex to variable $1
		#print $maxECOnumber;
		$ECO_number ++;
		$ECO_array_number = $1;
		#print $ECO_number;
		
		@HW_Version_Flag[$1]=1;	#if HW_Version_Flag ==1, using hw version
		$HW_ECO_Gen_Flag = 1;
	}	
	
	if($data_handle =~/^ECO_E(\d+)/)
	{
		$ECO_version[$1]=1;	#save the ECO_Ex to variable $1
		#print $maxECOnumber;
		$ECO_number ++;
		$ECO_array_number = $1;
		#print $ECO_number;
	}	
	
	if($data_handle =~/^MAJREV_(\d+)/)
	{
		#print $ECO_number;
		$MAJREV[$ECO_array_number]=$1;	#save the SW_version_Sx to variable $1, sw version start from 0
		if($pre_majrev != $MAJREV[$ECO_array_number])
		{
			$pre_majrev = $MAJREV[$ECO_array_number];
			$majrev_number ++;
		}
	}
	
	if($data_handle =~/^MINREV_(\d+)/)
	{
		#print $ECO_number;
		$MINREV[$ECO_array_number]=$1;	#save the SW_version_Sx to variable $1, sw version start from 0
		$minrev_number ++;
	}

}

if($ECO_number != 1)		#only 1 ECO version, no need ECO version judgement
{
	if($pmu ==1)
	{
		
		if($minrev_number != 1)
		{
			$ECO_String = $ECO_String."\t"."SW_SECVERSION SwVersion = INT_SW_SecVersion();"."\n";
		}	
		if($HW_ECO_Gen_Flag == 1)
		{
			$ECO_String = $ECO_String."\t"."ECO_VERSION ChipVersion = INT_ecoVersion();"."\n";
		}	
	}
	else
	{
		$ECO_String = $ECO_String."\t"."PMU_CTRL_PMIC_ECO_VERSION_ENUM ChipVersion = pmic_get_ECO_version();"."\n";
	}	
}


for($i=20;$i>=0;$i--)
{
		$parsing = 0;
		$linenumber = 0;
		
		#print "$i \n";	
		#print "ECO_Version".$ECO_version[$i]." \n";
		#print "MINREV".$MINREV[$i]." \n";
		#print "HW_Version_Flag".$HW_Version_Flag[$i]." \n";
					
		if($ECO_version[$i] == 1)
		{
					
			if($latest_ECOversion == 0)
			{	
				if($ECO_number != 1)	#only 1 ECO version, no need ECO version judgement
				{
					if($pmu ==1)
					{
						if($HW_Version_Flag[$i] == 1)
						{
							$ECO[$i] = $ECO[$i]."\t"."if(ChipVersion >= ECO_E"."$i".")\n";		
						}
						else
						{	if($minrev_number != 1)
							{
								$ECO[$i] = $ECO[$i]."\t"."if(SwVersion >= SW_SEC_"."$MINREV[$i]".")\n";	
							}	
						}	
					}
					else
					{
						$ECO[$i] = $ECO[$i]."\t"."if(ChipVersion >= PMIC_ECO_E"."$i".")\n";	
					}	
				}	
				$ECO[$i] = $ECO[$i]."\t{\n";
				$latest_ECOversion = 1;		#set latest ECO version on the top of C code
			}
			else
			{
				if($pmu ==1)
				{	
					if($HW_Version_Flag[$i] == 1)
					{
						$ECO[$i] = $ECO[$i]."\t"."else if(ChipVersion >= ECO_E"."$i".")\n";
					}
					else
					{
						if($MINREV[$i] == 0)
						{
							$ECO[$i] = $ECO[$i]."\t"."else"."\n";	
						}
						else
						{
							$ECO[$i] = $ECO[$i]."\t"."else if(SwVersion >= SW_SEC_"."$MINREV[$i]".")\n";	
						}	
					}	
				}
				else
				{
					$ECO[$i] = $ECO[$i]."\t"."else if(ChipVersion >= PMIC_ECO_E"."$i".")\n";	
				}	
				$ECO[$i] = $ECO[$i]."\t{\n";
			}
				
			foreach $data_handle (@raw_data)
			{
				$error = 0;	#check input data error
				chomp($data_handle);	#remove CR/LF(����)
				
								
				#$data_handle =~ s/\s+//g;	#remove all white space
				$linenumber++;
				
				#if($data_handle =~/^PMIC/ )	#check �O�_��ECO�}�Y, check ECO version
				#{
				#	$pmu = 0;
				#	#print $pmu;	
				#}
				
				
				
				if($data_handle =~/^pmu(\d+)/)
				{
					$pmu_name = "pmu"."$1";
					#print $pmu_name;
				}
				elsif($data_handle =~/^pmic(\d+)/ )
				{
					$pmu_name = "pmic"."$1";
					#print $pmu_name;
				}
								
				if($data_handle =~/^ECO_TRUE_E(\d+)/ )	#check �O�_��ECO�}�Y, check ECO version
				{
					if($1 == $i)
					{
						$parsing = 1;	
						#print "$i yes\n"
					}
					else
					{
						$parsing = 0;
						#print "$i no\n"	
					}
				}
				elsif($data_handle =~/^ECO_E(\d+)/ )	#check �O�_��ECO�}�Y, check ECO version
				{
					if($1 == $i)
					{
						$parsing = 1;	
						#print "$i yes\n"
					}
					else
					{
						$parsing = 0;
						#print "$i no\n"	
					}
				}
				else
				{
					#print "$i $parsing\n"	
				}
				if($parsing == 1)
				{
									
					if($data_handle =~s/^$// )	#delete �ťզ�
					{
						
					}
					elsif($data_handle =~/^MAJREV_/)
					{
						
					}
					elsif($data_handle =~/^MINREV_/)
					{
						
					}
					elsif($data_handle =~/^ECO_/ )	#check �O�_��ECO�}�Y, check ECO version	
					{
						$ECO_Version_Check = $ECO_Version_Check.$data_handle."\n";
					}
					elsif($data_handle =~/^\/\// )	#check //�}�Y��string
					{
						$ECO[$i] = $ECO[$i]."\t".$data_handle."\n";	
						#print $data_handle."\n";	
					}
					elsif($data_handle =~/^\// )	#check /�}�Y��string
					{
						print "$data_handle"." is not acceptable, missing / ,line $linenumber \n";	
					}
					elsif($data_handle !~/\,\w+\,/ )	#check �O�_����,[a-zA-Z0-9],
					{
						print "$data_handle"." is not acceptable, line $linenumber  \n";	
					}
					else
					{
							
						($address[$data_number],$mask[$data_number],$value[$data_number], $APshift[$data_number], $APmask[$data_number], $APvalue[$data_number],$APbank[$data_number]) = split(/,/,$data_handle);	
						
						if($address[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$address[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}
						if($mask[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$mask[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($value[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$value[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APshift[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$APshift[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}
						if($APmask[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$APmask[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APvalue[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$APvalue[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						if($APbank[$data_number] =~/[g-wyzG-Z]/)	#check �O�_�����T��16�i��))	
						{
							print "$APbank[$data_number]"." is not acceptable, line $linenumber  \n";
							$error = 1;
						}	
						
						if($address[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$address[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}	
						if($mask[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$mask[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($value[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$value[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						
						if($APshift[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$APshift[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}	
						if($APmask[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$APmask[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($APvalue[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$APvalue[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
						if($APbank[$data_number] !~/^0x/ )	#check �O�_��0x�}�Y))	
						{
							print "$APbank[$data_number]"." is not acceptable, line $linenumber \n";
							$error = 1;
						}
								
						#print "PMU_DRV_SetData16(".$address[$data_number].",".$mask[$data_number].",".$startbit[$data_number].");\n";
						if($error == 0)
						{
							if($pmu ==1)
							{	
								$ECO[$i] = $ECO[$i]."\t"."\t"."PMU_DRV_SetData16(".$address[$data_number].",".$mask[$data_number].",".$value[$data_number].");\n";
							}
							else
							{
								$ECO[$i] = $ECO[$i]."\t"."\t"."PMIC_DRV_SetData(".$address[$data_number].",".$mask[$data_number].",".$value[$data_number].",".$APbank[$data_number].");\n";	
							}	
						}	
					}
					
					
					#print "$address[$data_number] $mask[$data_number] $startbit[$data_number] $value[$data_number] $data_number";
					
					$data_number++;
					
				}
				
			}
			
			$ECO[$i] = $ECO[$i]."\t}\n";
			$ECO_String = $ECO_String.$ECO[$i];
		}
	
}
close(IN_FILE_INDEX);

if($error == 0)
{
	print "code generation OK"; 	
}
# //translate the number to string
#$address_string = join ',' , @address;
#$mask_string = join ',' , @mask;
#$startbit_string = join ',' , @startbit;
#$value_string = join ',' , @value;
#print "$address_string $mask_string $startbit_string $value_string";
	
	
if($pmu ==1)
{
	$file_body_func_name = "config_PMUc_file_body";
}
else
{
	$file_body_func_name = "config_PMICc_file_body";
}	

$output_file = "..\\hal\\peripheral\\src\\dcl_"."$pmu_name"."_init.c";
$pmu_fuunction_name = "dcl_"."$pmu_name"."_internal_init"; 
open(OUT_FILE_INDEX,">$output_file") || die("Cannot Open File"); 
print OUT_FILE_INDEX &copyright_file_header();
print OUT_FILE_INDEX &description_file_header(@desc_list);
print OUT_FILE_INDEX &{$file_body_func_name}($pmu_fuunction_name,$ECO_String);
close(OUT_FILE_INDEX);

#ECO_Version_check.txt record all ECO Version for designer to double confirm the initial setting .txt 	
$output_txt_file = "..\\hal\\peripheral\\src\\ECO_Version_Check_"."$now_date".".txt";
open(OUT_FILE_INDEX,">$output_txt_file") || die("Cannot Open File"); 
print OUT_FILE_INDEX &{"ECO_Version_Check_body"}($ECO_Version_Check);
close(OUT_FILE_INDEX);
#****************************************************************************
# subroutine:  generate pmu_init.c content body
# return:      the body strings
#****************************************************************************
sub config_PMUc_file_body
{
	my($pmu_fuunction_name,$ECO_String) = @_;
	my $template = <<"__TEMPLATE";
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

//$data_file	
void $pmu_fuunction_name(void)
{
$ECO_String}
	
__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  generate pmic_init.c content body
# return:      the body strings
#****************************************************************************
sub config_PMICc_file_body
{
	my($pmu_fuunction_name,$ECO_String) = @_;
	my $template = <<"__TEMPLATE";
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_common_sw.h"

extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic_get_ECO_version(void);

void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}

//$data_file
void $pmu_fuunction_name(void)
{
$ECO_String}
	
__TEMPLATE

   return $template;
}
#****************************************************************************
# subroutine:  copyright_file_header
# return:      file header -- copyright
#****************************************************************************
sub copyright_file_header
{
    my $template = <<"__TEMPLATE";
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  description_file_header
# return:      file header -- description 
# input:       $filename:     filename
# input:       $description:  one line description
# input:       $author:       optional
#****************************************************************************
sub description_file_header
{
    my ($filename, $description, $author, $PMU_INITSETTING_VERNO, $time) = @_;
    my $template = <<"__TEMPLATE";
/*****************************************************************************
 *
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   $description
 *
 * Author:
 * -------
 *   $author
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * \$Revision\$   $PMU_INITSETTING_VERNO
 * \$Modtime\$     $time 
 * \$Log\$
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
__TEMPLATE

   return $template;
}


#****************************************************************************
# subroutine:  generate ECO_Version_check.txt content body
# return:      the body strings
#****************************************************************************
sub ECO_Version_Check_body
{
	my($ECO_Version_Check) = @_;
	my $template = <<"__TEMPLATE";
$time
$ECO_Version_Check
	
__TEMPLATE

   return $template;
}