/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    hr_dvt.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the ADC driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#define DRV_HR_DVT
#ifdef DRV_HR_DVT

#include "drv_features.h"
#include "drv_comm.h"
#include "stack_common.h"  
#include "syscomp_config.h"   /*MOD_BMT*/
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */
#include "event_shed.h"       /* Event scheduler */
#include "stack_timer.h"     /*Timer*/
#include "kal_release.h"
#include "dcl.h"
#include "tst_sap.h"
#include "us_timer.h"
#include "eint.h"



//#define A60927_SLAVE_ADDRESS	0xD4
#define GPIO_A60927_ADC_PWD 			5
#define GPIO_A60927_RESET	 			6

#define EINT_A60927_ADC_RDY				3
#define EINT_A60927_IRQ					6	//eint number


#define SRAM_EKG				0
#define SRAM_PPG1  				1
#define SRAM_PPG2				2
#define SRAM_BISI				3


kal_uint32 sram_data[1000];
char buf2[50];
DCL_HANDLE A60927I2CHandle;

kal_uint16 sram_addr[4]={0x33C8,0x33D8,0x33E8,0x33F8};
kal_uint16 sram_read_counter_addr[4]={0x33C0,0x33D0,0x33E0,0x33F0};
kal_uint16 sram_write_counter_addr[4]={0x33CC,0x33DC,0x33EC,0x33FC};
kal_uint32 rg_afe_mem_en[4]={0x10,0x20,0x40,0x80};
kal_uint32 rg_int_en_mem[4]={0x02,0x10,0x80,0x400};
kal_uint32 rg_int_stauts_mask[4]={0x20000,0x100000,0x800000,0x4000000};

kal_uint16  irqth;
kal_uint32  sram_dump_count;
kal_uint32 sram_count=0;
kal_uint8  sram_type;
kal_int32 sram_write_count=0;
kal_int32 sram_read_count=0;






char * strsep(stringp, delim)
    char **stringp;
    const char *delim;
{
    char *s;
    const char *spanp;
    int c, sc;
    char *tok;

    if ((s = *stringp) == NULL)
        return (NULL);
    for (tok = s;;) {
        c = *s++;
        spanp = delim;
        do {
            if ((sc = *spanp++) == c) {
                if (c == 0)
                    s = NULL;
                else
                    s[-1] = 0;
                *stringp = s;
                return (tok);
            }
        } while (sc != 0);
    }
    /* NOTREACHED */
}


unsigned int stringtohex(const char * s)
{
 unsigned int result = 0;
 int c ;
 
 while (*s) {
   result = result << 4;
   if (c=(*s-'0'),(c>=0 && c <=9)) result|=c;
   else if (c=(*s-'A'),(c>=0 && c <=5)) result|=(c+10);
   else if (c=(*s-'a'),(c>=0 && c <=5)) result|=(c+10);
   else break;
   ++s;
  }

 return result;
}



void A60927_HW_I2C_init(kal_uint8 deviceAddress)
{
	I2C_CONFIG_T HWI2CPara;

	if(0 == A60927I2CHandle){

		//DclSI2C_Initialize();
		A60927I2CHandle = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_A60927);
	}	

		HWI2CPara.eOwner = DCL_I2C_OWNER_A60927;
		HWI2CPara.fgGetHandleWait = KAL_TRUE;
		HWI2CPara.u1SlaveAddress = (deviceAddress*2) ;
		HWI2CPara.u1DelayLen = 0;
		HWI2CPara.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		HWI2CPara.u4FastModeSpeed = HWI2CPara.u4HSModeSpeed = 200;
		HWI2CPara.fgEnableDMA = KAL_FALSE;
		DclSI2C_Configure(A60927I2CHandle, (DCL_CONFIGURE_T *)&HWI2CPara);
}



void A60927_HW_I2C_writer(DCL_UINT16 addr, DCL_UINT8 *pu1Data, DCL_UINT32 u4DataLen)
{
	DCL_STATUS status;
	kal_uint32 i;
	kal_uint8 WriteBuff[5];
	I2C_CTRL_SINGLE_WRITE_T WriteData;
	kal_uint8  register_addr, slave_addr;
	I2C_CONFIG_T HWI2CPara;

	register_addr = addr & 0x00FF;
	slave_addr = (addr & 0xFF00) >> 8;

	if(0 == A60927I2CHandle){

		//DclSI2C_Initialize();
		A60927I2CHandle = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_A60927);
	}	

		HWI2CPara.eOwner = DCL_I2C_OWNER_A60927;
		HWI2CPara.fgGetHandleWait = KAL_TRUE;
		HWI2CPara.u1SlaveAddress = (slave_addr*2) ;
		HWI2CPara.u1DelayLen = 0;
		HWI2CPara.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		HWI2CPara.u4FastModeSpeed = HWI2CPara.u4HSModeSpeed = 200;
		HWI2CPara.fgEnableDMA = KAL_FALSE;
		DclSI2C_Configure(A60927I2CHandle, (DCL_CONFIGURE_T *)&HWI2CPara);

	WriteData.u4DataLen = u4DataLen;

	WriteBuff[0] = register_addr;

	for(i=0;i<u4DataLen;i++)
	{
		WriteBuff[i+1] = pu1Data[i];
	}
		
	
	WriteData.u4DataLen = u4DataLen+1;
	WriteData.pu1Data = WriteBuff;

	status = DclSI2C_Control(A60927I2CHandle, I2C_CMD_SINGLE_WRITE, (DCL_CTRL_DATA_T *)&WriteData);
	if(STATUS_OK != status){
		kal_prompt_trace(MOD_BMT,"A60927_HW_I2C_writer Fail");
	}

}


void A60927_HW_I2C_reader(DCL_UINT16 addr, DCL_UINT8 *ReadBuff, DCL_UINT32 len)
{
	DCL_STATUS status;
	kal_uint8 WriteBuff[1];
	I2C_CTRL_WRITE_AND_READE_T I2cData;
	kal_uint8  register_addr, slave_addr;
	I2C_CONFIG_T HWI2CPara;

	register_addr = addr & 0x00FF;
	slave_addr = (addr & 0xFF00) >> 8;

	if(0 == A60927I2CHandle){

		//DclSI2C_Initialize();
		A60927I2CHandle = DclSI2C_Open(DCL_I2C, DCL_I2C_OWNER_A60927);
	}	

		HWI2CPara.eOwner = DCL_I2C_OWNER_A60927;
		HWI2CPara.fgGetHandleWait = KAL_TRUE;
		HWI2CPara.u1SlaveAddress = (slave_addr*2) ;
		HWI2CPara.u1DelayLen = 0;
		HWI2CPara.eTransactionMode = DCL_I2C_TRANSACTION_FAST_MODE;
		HWI2CPara.u4FastModeSpeed = HWI2CPara.u4HSModeSpeed = 200;
		HWI2CPara.fgEnableDMA = KAL_FALSE;
		DclSI2C_Configure(A60927I2CHandle, (DCL_CONFIGURE_T *)&HWI2CPara);
	

	WriteBuff[0] = register_addr;
	I2cData.pu1OutData = WriteBuff;
	I2cData.u4OutDataLen = 1;
	I2cData.pu1InData = ReadBuff;
	I2cData.u4InDataLen = len;

	status = DclSI2C_Control(A60927I2CHandle, I2C_CMD_WRITE_AND_READ, (DCL_CTRL_DATA_T *)&I2cData);
	if(STATUS_OK != status){
		kal_prompt_trace(MOD_BMT,"A60927_HW_I2C_reader Fail");
	}
}


void A60927_i2c_4bytes_read(kal_uint16 addr)
{
	kal_uint8 i2c_multi_data[4];
    kal_uint32 register_val;
		

	A60927_HW_I2C_reader(addr,&i2c_multi_data[0],4);

	register_val = i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);
		
	sprintf(buf2,"I2C Multi read, addr=0x%x ,reg_val=0x%x, data1=0x%x,data2=0x%x,data3=0x%x,data4=0x%x ",
		addr,register_val,i2c_multi_data[0],i2c_multi_data[1],i2c_multi_data[2],i2c_multi_data[3]);
	kal_prompt_trace(MOD_BMT,buf2);

}


void A60927_i2c_4bytes_write(kal_uint16 addr, kal_uint32 register_val)
{
	kal_uint8 i2c_multi_data[4];
	
	i2c_multi_data[0] = register_val & 0x000000FF;
	i2c_multi_data[1] = (register_val & 0x0000FF00) >> 8;
	i2c_multi_data[2] = (register_val & 0x00FF0000) >> 16;
	i2c_multi_data[3] = (register_val & 0xFF000000) >> 24;
				
	A60927_HW_I2C_writer(addr,&i2c_multi_data[0],4);
			
	sprintf(buf2,"I2C Multi write, addr=0x%x , data1=0x%x,data2=0x%x,data3=0x%x,data4=0x%x ",
		addr,i2c_multi_data[0],i2c_multi_data[1],i2c_multi_data[2],i2c_multi_data[3]);
	kal_prompt_trace(MOD_BMT,buf2);

}


void HS_DRV_ClearData(kal_uint16 addr,kal_uint32 value)
{
   kal_uint32 temp;
   kal_uint32 register_val;
   kal_uint8 temp_i2c_multi_data[4];
  
	
   A60927_HW_I2C_reader(addr,&temp_i2c_multi_data[0],4);
   temp = register_val= temp_i2c_multi_data[0] | (temp_i2c_multi_data[1]<<8) | (temp_i2c_multi_data[2]<<16) | (temp_i2c_multi_data[3]<<24);

   temp &=~(value);

   temp_i2c_multi_data[0] = temp & 0x000000FF;
   temp_i2c_multi_data[1] = (temp & 0x0000FF00) >> 8;
   temp_i2c_multi_data[2] = (temp & 0x00FF0000) >> 16;
   temp_i2c_multi_data[3] = (temp & 0xFF000000) >> 24;

  
   A60927_HW_I2C_writer(addr,&temp_i2c_multi_data[0],4);

   sprintf(buf2,"addr=0x%x, reg_val=0x%x, reg_val after clear=0x%x ",addr,register_val,temp);
			kal_prompt_trace(MOD_BMT,buf2);
}




void HS_DRV_SetData(kal_uint16 addr,kal_uint32 bitmask,kal_uint32 value)
{
   kal_uint32 temp;
   kal_uint8 temp_i2c_multi_data[4];
   kal_uint32 register_val;
  	
   A60927_HW_I2C_reader(addr,&temp_i2c_multi_data[0],4);
   register_val = temp_i2c_multi_data[0] | (temp_i2c_multi_data[1]<<8) | (temp_i2c_multi_data[2]<<16) | (temp_i2c_multi_data[3]<<24);
   
   temp = (~(bitmask)) & register_val;
   temp |= ((value) & (bitmask));

   temp_i2c_multi_data[0] = temp & 0x000000FF;
   temp_i2c_multi_data[1] = (temp & 0x0000FF00) >> 8;
   temp_i2c_multi_data[2] = (temp & 0x00FF0000) >> 16;
   temp_i2c_multi_data[3] = (temp & 0xFF000000) >> 24;

   A60927_HW_I2C_writer(addr,&temp_i2c_multi_data[0],4);

   sprintf(buf2,"addr=0x%x, mask=0x%x, reg_val=0x%x, reg_val after set=0x%x ",addr,bitmask,register_val,temp);
			kal_prompt_trace(MOD_BMT,buf2);
   
}



void HeartRate_Sram_Counter_Check(void)	//read, write counter
{
	kal_uint8 i2c_multi_data[4];
	kal_uint32 register_val;
	kal_uint32 data1, data2;
	
	//step0 
	A60927_HW_I2C_reader(sram_write_counter_addr[sram_type],&i2c_multi_data[0],4);
	register_val = i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);
    data1 = register_val & 0x01ff0000;	// bit 25 ~ bit 16
	sram_write_count = data1 >> 16;

	//step1
	A60927_HW_I2C_reader(sram_read_counter_addr[sram_type],&i2c_multi_data[0],4);
	register_val = i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);
	data2 = register_val & 0x01ff0000;	// bit 25 ~ bit 16
	sram_read_count = data2 >> 16;

	sprintf(buf2,"read SRAM, 0x%x=0x%x, 0x%x=0x%x",sram_write_counter_addr[sram_type],data1,sram_read_counter_addr[sram_type], data2);
	kal_prompt_trace(MOD_BMT,buf2);

}


void HeartRate_Digital_Disabled(kal_uint8 sram_type)
{
	if(sram_type == SRAM_EKG)
	{
		HS_DRV_ClearData(0x3360,0x00000218);		
		HS_DRV_ClearData(0x334C,0x00000002);		
		HS_DRV_ClearData(0x3350,0x00000040);		
	}
	else if(sram_type == SRAM_PPG1)
	{
		HS_DRV_ClearData(0x3360,0x00000124);		
		HS_DRV_ClearData(0x334C,0x00000010);		
		HS_DRV_ClearData(0x3350,0x00000080);		
	}
	else if(sram_type == SRAM_PPG2)
	{
		HS_DRV_ClearData(0x3360,0x00000144);		
		HS_DRV_ClearData(0x334C,0x00000080);		
		HS_DRV_ClearData(0x3350,0x00000080);				
	}
	else if(sram_type == SRAM_BISI)
	{
		HS_DRV_ClearData(0x3360,0x000001E7);		
		HS_DRV_ClearData(0x334C,0x00000400);		
		HS_DRV_ClearData(0x3350,0x00000080);				
	}

	kal_prompt_trace(MOD_BMT,"Sram count reach limit, digital module disabled");
}


void HeartRate_Dump_Sram(kal_uint32 len)
{
	kal_uint32 i;
	kal_uint8 i2c_multi_data[4];
	kal_uint32 round, remind; 
	kal_uint32 *ptr;
	char *sram_string[]={"EKG","PPG1","PPG2","BISI"};

	ptr = (kal_uint32 *)&sram_data[0];
	round = irqth / 4;
	remind = irqth % 4;
	
	//step4
	for(i=0;i<len;i++)
	{
		A60927_HW_I2C_reader(sram_addr[sram_type],&i2c_multi_data[0],4);
		sram_data[i]= i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);
	}

	sprintf(buf2,"%s SRAM data start dump, irqth=%d,len=%d,count=%d---------------",sram_string[sram_type],irqth,len,sram_count);
	kal_prompt_trace(MOD_BMT,buf2);
	if(len<4)
	{
		switch (remind)
		{
			case 1:
				sprintf(buf2,"%x, , , ,", *ptr);
				kal_prompt_trace(MOD_BMT,buf2);
			break;
			case 2:
				sprintf(buf2,"%x, %x, , ,", *ptr, *(ptr+1));
				kal_prompt_trace(MOD_BMT,buf2);
			break;
			case 3:
				sprintf(buf2,"%x, %x, %x, ,", *ptr, *(ptr+1), *(ptr+2));
				kal_prompt_trace(MOD_BMT,buf2);	
			break;
			default:
			break;
		}

		#if 0
/* under construction !*/
/* under construction !*/
		#endif
	}
	else
	{
		for (i=0;i<round;i++)
		{
			sprintf(buf2,"%x, %x, %x, %x,", *ptr, *(ptr+1), *(ptr+2), *(ptr+3));
			kal_prompt_trace(MOD_BMT,buf2);
			ptr += 4;
		}
		switch (remind)
		{
			case 1:
				sprintf(buf2,"%x, , , ,", *ptr);
				kal_prompt_trace(MOD_BMT,buf2);
			break;
			case 2:
				sprintf(buf2,"%x, %x, , ,", *ptr, *(ptr+1));
				kal_prompt_trace(MOD_BMT,buf2);
			break;
			case 3:
				sprintf(buf2,"%x, %x, %x, ,", *ptr, *(ptr+1), *(ptr+2));
				kal_prompt_trace(MOD_BMT,buf2);	
			break;
			default:
			break;
		}
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
	}

	sprintf(buf2,"%s SRAM data dump End -------------------",sram_string[sram_type]);
	kal_prompt_trace(MOD_BMT,buf2);
}


static void HeartRate_EINT_HISR(void)
{

	kal_uint8 i2c_multi_data[4];
	kal_uint32 irq_status;
	kal_uint32 irq_status2;
	kal_uint16 i;
	static kal_bool bIrqStatus = LEVEL_HIGH;


	EINT_Mask(EINT_A60927_IRQ);

	if(bIrqStatus == LEVEL_HIGH)
	{
		EINT_Set_Polarity(EINT_A60927_IRQ,LEVEL_LOW);
		bIrqStatus = LEVEL_LOW;
	}
	else
	{
		EINT_Set_Polarity(EINT_A60927_IRQ,LEVEL_HIGH);
		bIrqStatus = LEVEL_HIGH;
		kal_prompt_trace(MOD_BMT,"Clear Interrupt Done");
		EINT_UnMask(EINT_A60927_IRQ);
		return;
	}


	A60927_HW_I2C_reader(0x3354,&i2c_multi_data[0],4);
	irq_status = i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);

	
	A60927_HW_I2C_reader(0x3358,&i2c_multi_data[0],4);
	irq_status2= i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);

	sprintf(buf2,"Receive Interrupt, irq_stats(0x54)=0x%x, (0x58)=0x%x",irq_status,irq_status2);
	kal_prompt_trace(MOD_BMT,buf2);

	
	//HeartRate_Sram_Counter_Check();
	
	if(irq_status & 0x00000002)	//EKG
	{
		sram_type = SRAM_EKG;
		HeartRate_Dump_Sram(irqth);

		HS_DRV_ClearData(0x334C,rg_int_en_mem[sram_type]);

		HS_DRV_SetData(0x3354,rg_int_stauts_mask[sram_type],rg_int_stauts_mask[sram_type]);
		HS_DRV_ClearData(0x3354,rg_int_stauts_mask[sram_type]);
		
		HS_DRV_SetData(0x334C,rg_int_en_mem[sram_type],rg_int_en_mem[sram_type]);
	}
	else if(irq_status & 0x00000010)	//PPG1
	{
		sram_type = SRAM_PPG1;
		HeartRate_Dump_Sram(irqth);

		HS_DRV_ClearData(0x334C,rg_int_en_mem[sram_type]);

		HS_DRV_SetData(0x3354,rg_int_stauts_mask[sram_type],rg_int_stauts_mask[sram_type]);
		HS_DRV_ClearData(0x3354,rg_int_stauts_mask[sram_type]);
		
		HS_DRV_SetData(0x334C,rg_int_en_mem[sram_type],rg_int_en_mem[sram_type]);
	}
	else if(irq_status & 0x00000080)	//PPG2
	{
		sram_type = SRAM_PPG2;
		HeartRate_Dump_Sram(irqth);

		HS_DRV_ClearData(0x334C,rg_int_en_mem[sram_type]);

		HS_DRV_SetData(0x3354,rg_int_stauts_mask[sram_type],rg_int_stauts_mask[sram_type]);
		HS_DRV_ClearData(0x3354,rg_int_stauts_mask[sram_type]);
		
		HS_DRV_SetData(0x334C,rg_int_en_mem[sram_type],rg_int_en_mem[sram_type]);
	}
	else if(irq_status & 0x00000400)	//BISI
	{
		sram_type = SRAM_BISI;
		HeartRate_Dump_Sram(irqth);

		HS_DRV_ClearData(0x334C,rg_int_en_mem[sram_type]);

		HS_DRV_SetData(0x3354,rg_int_stauts_mask[sram_type],rg_int_stauts_mask[sram_type]);
		HS_DRV_ClearData(0x3354,rg_int_stauts_mask[sram_type]);
		
		HS_DRV_SetData(0x334C,rg_int_en_mem[sram_type],rg_int_en_mem[sram_type]);
	}

	
	if(irq_status2 & 0xff)	//AGC
	{
		sram_type = SRAM_BISI;
		
		for(i=0x2388;i<=0x23A4;i+=4)
		{
			A60927_i2c_4bytes_read(i);
		}

		HeartRate_Dump_Sram(irqth);
		
		HS_DRV_SetData(0x3350,0xff,0x0);
		HS_DRV_SetData(0x3358,0x01ff0000,0xff0000);
		HS_DRV_SetData(0x3358,0xff,0xff);
		HS_DRV_SetData(0x3358,0x01ff0000,0x0);
		
		HS_DRV_SetData(0x3358,0xff,0x0);
		//HS_DRV_SetData(0x3350,0x3f,0x0);
		HS_DRV_SetData(0x3350,0xff,0xff);


	}
	
	
	// step 4.	
	HeartRate_Sram_Counter_Check();

	sram_count++;
	
	if(sram_count >= sram_dump_count)
	{
		HS_DRV_ClearData(0x334C,rg_int_en_mem[sram_type]);	
//		HeartRate_Digital_Disabled(sram_type);
	}

	EINT_UnMask(EINT_A60927_IRQ);

}


void bmt_handleTstCommand(ilm_struct * ilm_ptr)
{
	char *pStr;
	char *token,*prefix;
	tst_module_string_inject_struct* tst_inject = NULL;
	kal_uint32 register_val;
	kal_uint32 addr;
	kal_uint32 register_write_val;
	kal_uint8 i2c_data;
	kal_uint8 i2c_multi_data[4];
	kal_uint32 mask;
	kal_uint16 len;
	DCL_HANDLE handle;
	kal_uint32 afe_mem_en_mask;
	
	
	tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;

	pStr=tst_inject->string;

	kal_prompt_trace(MOD_BMT,"BMT get inject cmd");

	kal_prompt_trace(MOD_BMT,pStr);

	do
	{
		token = strsep(&pStr, ","); 
		{

			prefix=strsep(&token,"=");
			
			sprintf(buf2,"prefix=%s, token=%s ",prefix,token);
			kal_prompt_trace(MOD_BMT,buf2);
				
			/*
			if(strcmp(prefix,"ch")==0)
			{
				ch=atoi(token);
			}
			else if(strcmp(prefix,"delay")==0)
			{
				delay=atoi(token);
			}
			else if(strcmp(prefix,"data")==0)
			{
				data=atoi(token);
			}
			*/
			if(strcmp(prefix,"addr")==0)
			{
				addr = stringtohex(token);
				
			}
			else if(strcmp(prefix,"val")==0)
			{
				register_write_val = stringtohex(token);
				i2c_data = i2c_multi_data[0] = register_write_val & 0x000000FF;
				i2c_multi_data[1] = (register_write_val & 0x0000FF00) >> 8;
				i2c_multi_data[2] = (register_write_val & 0x00FF0000) >> 16;
				i2c_multi_data[3] = (register_write_val & 0xFF000000) >> 24;
			}
			else if(strcmp(prefix,"len")==0)
			{
				len = atoi(token);
			}
			else if(strcmp(prefix,"mask")==0)
			{
				mask = stringtohex(token);
			}
			else if(strcmp(prefix,"irqth")==0)
			{
				irqth = atoi(token);
			}
			else if(strcmp(prefix,"count")==0)
			{
				sram_dump_count = atoi(token); 
			}
			else if(strcmp(prefix,"sram")==0)
			{
				if(strcmp(token,"EKG")==0)
				{
					sram_type = SRAM_EKG;
					afe_mem_en_mask = rg_afe_mem_en[0];
				}
				else if(strcmp(token,"PPG1")==0)
				{		
					sram_type = SRAM_PPG1;
					afe_mem_en_mask = rg_afe_mem_en[1];
				}
				else if(strcmp(token,"PPG2")==0)
				{
					sram_type = SRAM_PPG2;
					afe_mem_en_mask = rg_afe_mem_en[2];
				}
				else if(strcmp(token,"BISI")==0)
				{
					sram_type = SRAM_BISI;
					afe_mem_en_mask = rg_afe_mem_en[3];					
				}
				else if(strcmp(token,"ALL")==0)
				{
					afe_mem_en_mask = rg_afe_mem_en[0] | rg_afe_mem_en[1] | rg_afe_mem_en[2] | rg_afe_mem_en[3];
				}
			}
		}
	}while(pStr);


	//A60927_HW_I2C_init(slave_addr);
		
	switch (tst_inject->index)
	{
		case 0:
		{	
			//provide 32KHz
			DRV_WriteReg(0xA0020E20,0x0004);

			//System reset
			handle = DclGPIO_Open(DCL_GPIO,GPIO_A60927_RESET);

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
			ust_busy_wait(10000);	// wait for 10ms
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
			ust_busy_wait(10000);	// wait for 10ms
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
			
			DclGPIO_Close(handle);
			

			//Enable BioAFE
			handle = DclGPIO_Open(DCL_GPIO,GPIO_A60927_ADC_PWD);

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
			ust_busy_wait(10000);	// wait for 10ms
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
			
			DclGPIO_Close(handle);
			
			kal_prompt_trace(MOD_BMT,"Power on Sequence");
		}	
		break;
		
		case 1:		//single write, addr=1234,val=E5
		{
			A60927_HW_I2C_writer(addr,&i2c_data,1);

			sprintf(buf2,"I2C Single write, addr=0x%x , val=0x%x ",addr,i2c_data);
			kal_prompt_trace(MOD_BMT,buf2);
		
		}	
		break;

		
		case 2:  //multi write, addr=1234,val=12345678
		{
			A60927_HW_I2C_writer(addr,&i2c_multi_data[0],4);
			
			sprintf(buf2,"I2C Multi write, addr=0x%x , data1=0x%x,data2=0x%x,data3=0x%x,data4=0x%x ",
				addr,i2c_multi_data[0],i2c_multi_data[1],i2c_multi_data[2],i2c_multi_data[3]);
			kal_prompt_trace(MOD_BMT,buf2);
		}	
		break;

		case 3:	//single read, addr=1234
		{
			A60927_HW_I2C_reader(addr,&i2c_data,1);
				
			sprintf(buf2,"I2C Single read, addr=0x%x , val=0x%x ",addr,i2c_data);
			kal_prompt_trace(MOD_BMT,buf2);
		}
		break;

		case 4:	//multi read, addr=1234
		{
			A60927_HW_I2C_reader(addr,&i2c_multi_data[0],4);

			register_val = i2c_multi_data[0] | (i2c_multi_data[1]<<8) | (i2c_multi_data[2]<<16) | (i2c_multi_data[3]<<24);
				
			sprintf(buf2,"I2C Multi read, addr=0x%x ,reg_val=0x%x, data1=0x%x,data2=0x%x,data3=0x%x,data4=0x%x ",
				addr,register_val,i2c_multi_data[0],i2c_multi_data[1],i2c_multi_data[2],i2c_multi_data[3]);
			kal_prompt_trace(MOD_BMT,buf2);
		}
		break;

		case 5:	//addr=1234,mask=ff00,val=3300
		{
			HS_DRV_SetData(addr,mask,register_write_val);
		}
		break;

		case 6:	//sram=EKG,irqth=200,val=60000022,len=100   //for EKG,PPG1,PPG2,BISI
		{
						
			HeartRate_Sram_Counter_Check();
			
			//step2
			HS_DRV_SetData(sram_write_counter_addr[sram_type],0x1ff,irqth);

			//step3
			HS_DRV_SetData(sram_read_counter_addr[sram_type],0x600001ff,register_write_val);

			//step4
			HeartRate_Dump_Sram(len);
		}			
		break;	

		case 7:	//ISR, sram=EKG,irqth=200,val=60000022,count=3   //for EKG,PPG1,PPG2,BISI
		{
			sram_count = 0;	

			EINT_Set_HW_Debounce(EINT_A60927_IRQ,5);
			EINT_SW_Debounce_Modify(EINT_A60927_IRQ, 0); // Set de-bounce time 100ms
			EINT_Registration(EINT_A60927_IRQ, KAL_TRUE, LEVEL_HIGH, HeartRate_EINT_HISR, KAL_FALSE);
			


			//HeartRate_Sram_Counter_Check();
			
			//step2
			//HS_DRV_SetData(sram_write_counter_addr[sram_type],0x1ff,irqth);

			//step3
			//HS_DRV_SetData(sram_read_counter_addr[sram_type],0x600001ff,register_write_val);

			//enable interrupt			
			//HS_DRV_SetData(0x3360,rg_afe_mem_en[sram_type],rg_afe_mem_en[sram_type]);
			//HS_DRV_SetData(0x3360,afe_mem_en_mask,afe_mem_en_mask);
			
		}
		break;

		case 8:	
		{
			HeartRate_Sram_Counter_Check();
			
			//step2
			//HS_DRV_SetData(sram_write_counter_addr[sram_type],0x1ff,irqth);

			//step3
			//HS_DRV_SetData(sram_read_counter_addr[sram_type],0x600001ff,register_write_val);

			sprintf(buf2,"sram_write_count=%d, sram_read_count=%d",sram_write_count,sram_read_count);
			kal_prompt_trace(MOD_BMT,buf2);

			if(sram_write_count - sram_read_count < 0)
			{
				if(((sram_write_count + 384) - sram_read_count) >= irqth)
						HeartRate_Dump_Sram(len);
			}
			else
			{
				if((sram_write_count - sram_read_count) >= irqth )
					HeartRate_Dump_Sram(len);
			}
		}
		break;

		
		case 9:	
		{
			
			//System reset
			handle = DclGPIO_Open(DCL_GPIO,GPIO_A60927_RESET);

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
			DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
			
			DclGPIO_Close(handle);
			

			//Disable BioAFE
			handle = DclGPIO_Open(DCL_GPIO,GPIO_A60927_ADC_PWD);

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
			DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);

			
			DclGPIO_Close(handle);
			
			kal_prompt_trace(MOD_BMT,"Power off Sequence");
			
			
		}
		break;

		case 10:	// CS
		{
			static kal_uint32 pinstatus = 0;
				
			handle = DclGPIO_Open(DCL_GPIO,26);	

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);

			if(pinstatus == 0)
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
				pinstatus = 1;
			}	
			else
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
				pinstatus = 0;
			}

			DclGPIO_Close(handle);
		}
		break;
		
		case 11:	// CLK
		{
			
			static kal_uint32 pinstatus = 0;
				
			handle = DclGPIO_Open(DCL_GPIO,27);	

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);

			if(pinstatus == 0)
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
				pinstatus = 1;
			}	
			else
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
				pinstatus = 0;
			}

			DclGPIO_Close(handle);
		}
		break;

		case 12:	// MOSI
		{
			
			static kal_uint32 pinstatus = 0;
				
			handle = DclGPIO_Open(DCL_GPIO,28);	

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);

			if(pinstatus == 0)
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
				pinstatus = 1;
			}	
			else
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
				pinstatus = 0;
			}

			DclGPIO_Close(handle);
		}
		break;

		case 13:	// MISO
		{
			
			static kal_uint32 pinstatus = 0;
				
			handle = DclGPIO_Open(DCL_GPIO,29);	

			DclGPIO_Control(handle,GPIO_CMD_SET_MODE_0,0);
			DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);

			if(pinstatus == 0)
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
				pinstatus = 1;
			}	
			else
			{
				DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
				pinstatus = 0;
			}

			DclGPIO_Close(handle);
		}
		break;
	
		default:
		break;
	}

}

#endif
