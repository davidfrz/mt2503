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
*****************************************************************************
*
* Filename:
* ---------
* ATA_AT_COMMAND_HDLR.C
*
* Project:
* --------
*   MT6250
*
* Description:
* ------------
*   This file is intends for ...
*
* Author:
* -------
* -------
*/
/*
**   Includes
*/
#include "stdio.h"
#include "string.h"
#include "kal_general_types.h"
#include "kal_internal_api.h"
#if (defined(__COMPOSITE_WEBCAM__))
#include "cal_api.h"
#include "cal_comm_def.h"
#endif
#ifdef __TWOMICNR_SUPPORT__
#include "two_mic_NR_custom_if.h" 
#endif
#include "Stack_ltlcom.h"
#include "device.h"
#include "Tst_sap.h"
#include "Stack_ltlcom.h"
#if defined(TOUCH_PANEL_SUPPORT)
#include "touch_panel.h"
#endif
#include "dcl.h"


#include "ata_external.h"


#if defined(__DCM_WITH_COMPRESSION_MMI_POOL_A__)
#include "dcmgr.h"
#elif defined (__DCM_WITH_COMPRESSION_MMI_AP__) && defined(__MTK_TARGET__)
#include "MMI_ap_dcm_config.h"  
#endif /* __DCM_WITH_COMPRESSION_MMI_POOL_A__ */









#if defined(__ATA_SUPPORT__) && defined(__MTK_TARGET__)
	
	void (*ata_tp_ui)(kal_uint8);
	void (*ata_lcm_ui)(kal_uint8);

	#if defined(TOUCH_PANEL_SUPPORT) && defined(TOUCH_PANEL_INTERNAL)
	custom_rsp_type_enum ata_tp_hdlr_v1(custom_cmdLine *commandBuffer_p)
	{
		custom_cmd_mode_enum result;
		custom_rsp_type_enum ret_value	= CUSTOM_RSP_ERROR;
		char buffer[MAX_UART_LEN+1];
		kal_bool tp_status;
		
		result = custom_find_cmd_mode(commandBuffer_p); 	
		switch (result)
		{
			case CUSTOM_ACTIVE_MODE:
			{		
				ts_tcs_off_(KAL_TRUE);
				kal_sleep_task(20);
				tp_status = tp_level();
				ts_tcs_off_(KAL_FALSE);
				if(tp_status)
				{
					sprintf(buffer, "+ETPSTATUS:1");
					rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
				}
				else
				{
					sprintf(buffer, "+ETPSTATUS:0");
					rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
				}

		 
				ret_value = CUSTOM_RSP_OK;

			}
			break;
			default:
			ret_value = CUSTOM_RSP_ERROR;
			break;
		}
		return ret_value;
	}
	#endif/*TOUCH_PANEL_SUPPORT */

	
		custom_rsp_type_enum ata_vibrator_hdlr_v1(custom_cmdLine *commandBuffer_p)
		{
			kal_uint32 vi_state = 0;
			char buffer[MAX_UART_LEN+1]; //MAUI_02377056
			
#if defined(__MMI_AP_DCM_FM__)
		
				if(!DCM_Isloaded(DYNAMIC_CODE_COMPRESS_FM))
				{
				   DCM_Load(DYNAMIC_CODE_COMPRESS_FM, NULL, NULL);
				}
#endif		
			 
			vi_state = ata_get_at_para(commandBuffer_p);
					
			if (vi_state == 0)
			{
							
				//Set Vibrator Off here
			}
			else if(vi_state == 1)
			{
							
				//Set Vibrator On here
			}
			else
			{
				return CUSTOM_RSP_ERROR;
			}
				
			sprintf(buffer, "\r\n+EMVI:OK\r\n");
			rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		
				
#if defined(__MMI_AP_DCM_FM__)
				if(DCM_Isloaded(DYNAMIC_CODE_COMPRESS_FM))
				{
				   DCM_Unload(DYNAMIC_CODE_COMPRESS_FM);
				}
#endif		
				
			return CUSTOM_RSP_OK;
			
				
		}

	void ata_led_on()//example code, customer should add code to control led on
	{
		/*
		DCL_HANDLE handle;
		PMU_CTRL_KPLED_SET_EN val_led;
	
		PWM2_level(LED_LIGHT_LEVEL5);
		val_led.enble = DCL_TRUE;
	
		handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *) &val_led);
		DclPMU_Close(handle);
		*/
	}
	
	void ata_led_off()//example code, customer should add code to control led off
	{
		/*
		DCL_HANDLE handle;
		PMU_CTRL_KPLED_SET_EN val_led;
	
		PWM2_level(LED_LIGHT_LEVEL0);
		val_led.enble = DCL_FALSE;
	
		handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
		DclPMU_Control(handle, KPLED_SET_EN, (DCL_CTRL_DATA_T *) &val_led);
		DclPMU_Close(handle);
		*/
	}


	custom_rsp_type_enum ata_led_hdlr(custom_cmdLine * commandBuffer_p)
	{
		char buffer[MAX_UART_LEN+1];
		kal_int32  led_para;


		//For Internal Test, customer should delete two lines below
		sprintf (buffer, "\r\nLED AT OK\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

 //Customer should open code below and write the ata_led_on and ata_led_off
 /*
		led_para = ata_get_at_para(commandBuffer_p);
		if(led_para)
		{
			ata_led_on();
		}
		else
		{
			ata_led_off();
		}
*/
		return CUSTOM_RSP_OK;


	}


custom_rsp_type_enum ata_led_tsem_hdlr(custom_cmdLine * commandBuffer_p)
{
	//please refer to <ATA Keypad FM and LED Test for 6260.ppt>
	return CUSTOM_RSP_OK;
}

custom_rsp_type_enum ata_led_gsem_hdlr(custom_cmdLine * commandBuffer_p)
{
	//please refer to <ATA Keypad FM and LED Test for 6260.ppt>
	return CUSTOM_RSP_OK;
}


//backlight  but not support currently
	//extern void srv_backlight_close();
	custom_rsp_type_enum ata_bkl_hdlr(custom_cmdLine * commandBuffer_p)
	{
		char buffer[MAX_UART_LEN+1];


		//For Internal Test, customer should delete two lines below
		sprintf (buffer, "\r\nBKL AT OK\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		
	//Customer should open code below and use srv_backlight_close or your own backlight close function
		//srv_backlight_close();

		
		return CUSTOM_RSP_OK;
	}

	custom_rsp_type_enum ata_lcm_hdlr(custom_cmdLine * commandBuffer_p)
	{
		custom_cmd_mode_enum result;
		custom_rsp_type_enum ret_value	= CUSTOM_RSP_ERROR;
		char buffer[MAX_UART_LEN+1];
		kal_bool tp_status;
		kal_uint16 camera_value;
		result = custom_find_cmd_mode(commandBuffer_p); 
		
		//For Internal Test, customer should delete two lines below
		sprintf (buffer, "\r\nLCM AT OK\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

	//Customer should open code below and write the lcm_test by ATA Display Programming Guide
	/*
		switch (result)
		{
			case CUSTOM_READ_MODE:
				{		
					camera_value = lcm_test ();
					if (camera_value == KAL_TRUE)
					{
						sprintf (buffer, "\r\n+ELCM:OK\r\n");
					}
					else
					{
						sprintf (buffer, "\r\n+ELCM:ERROR\r\n");
					}
					rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
					ret_value = CUSTOM_RSP_OK;
				}
				break;
 
			default:
				ret_value = CUSTOM_RSP_ERROR;
				break;
		}

*/
		return ret_value;
	}


#if defined(TOUCH_PANEL_SUPPORT)

 
 extern kal_uint8 ata_tp_test;
 
 custom_rsp_type_enum ata_tp_hdlr_v2(custom_cmdLine *commandBuffer_p)
 {
 	  int i = 0;
	  char buffer[200];
	  STS_CTRL_GET_T touch_data;
	  static DCL_HANDLE pen_drv_handle;
	  
	  
	  kal_int32 tp_test_para;
 	  tp_test_para = ata_get_at_para(commandBuffer_p);

	  if(tp_test_para == 0)
	  {
	    ata_tp_test = 0;
	  
	  	sprintf (buffer, "\r\n+ETPV2:OK\r\n");
	    rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	    return CUSTOM_RSP_OK;
	  }
	  else if(tp_test_para == 1)
	  {
	    ata_tp_test = 1;
	 
	 	sprintf (buffer, "\r\n+ETPV2:OK\r\n");
	    rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	    return CUSTOM_RSP_OK;
	  }
	else if(tp_test_para == 2)
	{
	    pen_drv_handle = DclSTS_Open(DCL_TS,0);
	 	while(DclSTS_Control(pen_drv_handle,STS_CMD_GET_EVENT, (DCL_CTRL_DATA_T*) &touch_data)) 
	 	{

			for(i = 0; i < touch_data.uModel; i++)
			{
				if(touch_data.rPoints[i].u2Event == DCL_PEN_DOWN)
		 		{
		 			sprintf (buffer, "\r\n+ETPV2:%d,%d", touch_data.rPoints[i].u2x,  touch_data.rPoints[i].u2y);
					rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		 		}
			}
	 	}
		sprintf (buffer, "\r\n+ETPV2:LAST\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	 	DclSTS_Close(pen_drv_handle);

 	 return CUSTOM_RSP_OK;
	}
	 
	return CUSTOM_RSP_ERROR;
 }

#endif

#if defined(__LCD_SUPPORT__)
custom_rsp_type_enum ata_tp_ui_hdlr(custom_cmdLine *commandBuffer_p)
{		 
	char buffer[MAX_UART_LEN+1];
	custom_rsp_type_enum ret_value	= CUSTOM_RSP_OK;
	kal_uint32 para = 0;
	kal_uint8 i = 0;

	kal_uint8 point_state = 0;
	

	for(i = 0; i < 4; i++)
	{
		para = ata_get_at_para(commandBuffer_p);
		point_state |= ((para & 1) << i);
	}

	ata_tp_ui(point_state);

	sprintf (buffer, "\r\n+ETPUI:OK\r\n");
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	return ret_value;
}


custom_rsp_type_enum ata_lcm_hdlr_v2(custom_cmdLine * commandBuffer_p)
{	
	kal_uint32 color_state = 0;
	char buffer[MAX_UART_LEN+1];
	custom_rsp_type_enum ret_value	= CUSTOM_RSP_OK;
 
	color_state = ata_get_at_para(commandBuffer_p);
	ata_lcm_ui((kal_uint8)color_state);
	
	sprintf (buffer, "\r\n+ELCMV2:OK\r\n");
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

	return ret_value;
}
#endif


  
#if defined(NORMAL_KEYPAD)|| defined(REDUCED_KEYPAD)|| defined(QWERTY_KEYPAD)
custom_rsp_type_enum ata_kpt_hdlr_v2(custom_cmdLine * commandBuffer_p)
{	

	char buffer[MAX_UART_LEN+1];
	int i = 0;


	kal_uint32 keys[8], rows[8], cols[8], sub_cols[8];

	for(i = 0; i < 8; i++)
	{
		keys[i]=0xff;
		rows[i]=0xff;
		cols[i]=0xff;
		sub_cols[i]=0xff;

	}

	if(kbd_get_key_position(keys, rows, cols, sub_cols))
	{

		for(i = 0; i< 8; i++)
		{
			if(rows[i] == 0xff)
			{
				break;
			}
			sprintf(buffer, "\r\n+EKPTV2:%d,%d,%d\r\n", rows[i], cols[i], sub_cols[i]);
			rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		}
	}
	sprintf(buffer, "\r\n+EKPTV2:LAST\r\n");
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);

	return CUSTOM_RSP_OK;

}
#endif


#if !defined(SIM_NOT_PRESENT)

extern kal_uint8 isSimCardRdy(kal_uint32 SIM_index);

custom_rsp_type_enum ata_sim_hdlr_v2(custom_cmdLine * commandBuffer_p)
{

	char buffer[MAX_UART_LEN+1];


	kal_uint32 sim_index;
	
	sim_index = ata_get_at_para(commandBuffer_p);

	

	if(isSimCardRdy(sim_index))
	{
		sprintf (buffer, "\r\n+ESIMV2:OK\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return CUSTOM_RSP_OK;

	}
	else
	{
		sprintf (buffer, "\r\n+ESIMV2:FAIL\r\n");
		rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
		return CUSTOM_RSP_OK;
	}
	

}
#endif

custom_rsp_type_enum ata_customer_lcd_hdlr(custom_cmdLine * commandBuffer_p)
{

	char buffer[MAX_UART_LEN+1];


	kal_uint32 para;
	
	para = ata_get_at_para(commandBuffer_p);
	

	
	sprintf (buffer, "\r\n+ECUSLCD:OK\r\n");
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	return CUSTOM_RSP_OK;

}

custom_rsp_type_enum ata_led_hdlr_v2(custom_cmdLine * commandBuffer_p)
{

	char buffer[MAX_UART_LEN+1];


	kal_uint32 para;
	
	para = ata_get_at_para(commandBuffer_p);

	
	sprintf (buffer, "\r\n+ELEDV2:OK\r\n");
	rmmi_write_to_uart((kal_uint8*)buffer, strlen(buffer), KAL_TRUE);
	return CUSTOM_RSP_OK;

}




	
#endif


