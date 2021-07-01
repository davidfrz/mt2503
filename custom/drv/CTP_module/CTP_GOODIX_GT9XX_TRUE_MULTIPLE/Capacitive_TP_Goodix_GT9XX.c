/*****************************************************************************
*  Copyright Statement: 
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   Capacitive_TP_Goodix_GT9xx.c
 *
 *
 * Description:
 * ------------
 *   Capacitive Touch Panel I2C read/write Driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "kal_release.h"
#include "touch_panel.h"
#include "Capacitive_TP_Goodix_GT9xx.h"
#include "Capacitive_TP_I2C.h"
#include "touch_panel_custom.h"
#include "us_timer.h"
#include "dcl.h"
#include "eint.h"
#include "kal_trace.h"
#include "Capacitive_TP_trc.h"
#include "fs_type.h"
#include "fs_func.h"
#include "GT9XX_config.h"
#include "GT9XX_hotknot.h"



#ifdef __CTP_GOODIX_GT9XX_TRUE_MULTIPLE__
	

#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

#define TPD_RESET_ISSUE_WORDAROUND
//#define TPD_BYTE_READ_WORKAROUND
#define CTP_MAX_RESET_COUNT 3

#ifdef __MTK_TARGET__
#define CTP_DEBUG_LINE_TRACE() drv_trace1(TRACE_GROUP_7, CTP_GOODIX_DRV_LINE_TRACE, __LINE__)
#else
#define CTP_DEBUG_LINE_TRACE() do {} while (0);
#endif

extern const char gpio_ctp_power_enable_pin;
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;
extern const char gpio_ctp_eint_pin_M_EINT;


void delay_ms(kal_uint32 millisecs);

kal_uint32 CTP_DELAY_TIME = 100;//400;

DCL_HANDLE CTP_dcl_handle = DCL_HANDLE_INVALID;

CTP_custom_information_struct  ctp_custom_information_def = 
{
    "Goodix ",
    "GT9xx",
    "UNKNOWN ",	
};

kal_bool CTP_I2C_write_byte(kal_uint16 ucBufferIndex, kal_uint8 pucData)
{
    return ctp_i2c_send( CTP_SLAVE_ADDR, ucBufferIndex, &pucData, 1);
}



static kal_bool ctp_goodix_gt9xx_set_device_mode(ctp_device_mode_enum mode);

#define GT9xx_MASTER_STRING  "ctp_9xx_master_firmware.bin"
#define GT9xx_DSP_STRING     "ctp_9xx_dsp_firmware.bin"

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//extern srv_bt_cm_cntx_struct g_srv_bt_cm_cntx;
//extern	void MtkBt_Get_BT_LE_ADDR(unsigned char addr[]);

void ctp_pmu_vcamd_enable(kal_bool enable)
{
	PMU_CTRL_LDO_BUCK_SET_EN val;

	
	val.enable=enable;
	val.mod=VCAMD;
	if (CTP_dcl_handle == DCL_HANDLE_INVALID) 
	{
		CTP_dcl_handle=DclPMU_Open(DCL_PMU, FLAGS_NONE);
	}
	
	DclPMU_Control(CTP_dcl_handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
	if(!enable)
	{
		DclPMU_Close(CTP_dcl_handle);
		CTP_dcl_handle = DCL_HANDLE_INVALID;
	}	
}

void ctp_pmu_set_vcamd(PMU_VOLTAGE_ENUM vol)
{
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;

	
	val.voltage=vol;
	val.mod=VCAMD;
	if (CTP_dcl_handle == DCL_HANDLE_INVALID)
	{
		CTP_dcl_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
	}
	DclPMU_Control(CTP_dcl_handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void ctp_goodix_gt9xx_power(kal_bool ON)
{
    static kal_bool power_status = KAL_TRUE;
    DCL_HANDLE enable_handle;

	DCL_HANDLE Handle = DCL_HANDLE_INVALID;
	PMU_CTRL_LDO_BUCK_SET_EN PmuEn;
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE PmuVol;

	
    CTP_DEBUG_LINE_TRACE();

    if(ON == power_status)
    {
        return;
    }

    power_status = ON;

    if ( ON )
    {
        ctp_goodix_gt9xx_set_device_mode( CTP_ACTIVE_MODE );
    }
    else
    {
        ctp_goodix_gt9xx_set_device_mode( CTP_SLEEP_MODE );
    }
}

//If controller has the register store these informations
//Read out the informations from controller through I2C
static kal_bool ctp_goodix_gt9xx_get_information(ctp_info_t *ctp_info)
{
	kal_bool ret;
	kal_uint8 cfg;

	ret = CTP_I2C_read( CTP_VERSION_INFO_REG, (kal_uint8 *)ctp_info, sizeof( ctp_info_t ) );

	drv_trace4( TRACE_GROUP_7, CTP_GOODIX_DRV_VERION_TRACE ,ctp_info->version_1, ctp_info->version_2,ctp_info->vendor_id_1,ctp_info->vendor_id_2);

	ctp_custom_information_def.FirmwareVersion[0] = ctp_info->version_1%100;
	ctp_custom_information_def.FirmwareVersion[1] = ctp_info->version_1/100;


	ret = CTP_I2C_read(CTP_CONFIG_REG_BASE, &cfg, 1);
	kal_prompt_trace(MOD_TP_TASK,"CFG VERSION = %x", cfg);

	return ret;
}

kal_bool ctp_goodix_gt9xx_set_configuration( void )
{
	kal_bool ret;
	kal_int16 cfg_idx = CTP_CONFIG_NORMAL;
	kal_uint8 *cfg_p;
	ctp_info_t ctp_info;
	kal_uint16 temp_len,check_sum = 0;

	if ( ctp_goodix_gt9xx_get_information(&ctp_info) != KAL_TRUE )
	{
		return KAL_FALSE;
	}

	drv_trace1( TRACE_GROUP_7, CTP_GOODIX_DRV_SET_CFG_TRACE, cfg_idx );

#if 1
	// set frame rate as 70Hz        
	//cfg_p = GET_CTP_CONFIG(cfg_idx);
	//cfg_p[ CTP_CONFIG_FPS_REG - CTP_CONFIG_REG_BASE ] = 70;

	//ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, GET_CTP_CONFIG(cfg_idx) , CTP_CONFIG_LENGTH );
#if 1
	gt9xx_config[1] = LCD_WIDTH;
	gt9xx_config[2] = LCD_WIDTH >> 8;
	gt9xx_config[3] = LCD_HEIGHT;
	gt9xx_config[4] = LCD_HEIGHT >> 8;
	for(temp_len = 0; temp_len < (sizeof(gt9xx_config) - 2); temp_len++)
	{
		check_sum += gt9xx_config[temp_len];
	}
	gt9xx_config[sizeof(gt9xx_config) - 2] = (~check_sum) + 1; 
#endif
	ret = CTP_I2C_send( CTP_CONFIG_REG_BASE, gt9xx_config , sizeof(gt9xx_config) );
#endif 

	return ret;
}

static Touch_Panel_PenState_enum ctp_goodix_gt9xx_hisr(void)
{
	kal_uint8 lvalue;

	CTP_I2C_read(CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);

	if(lvalue & CTP_STAT_NUMBER_TOUCH)
	{
		return DOWN;
	}
	else
	{
		return UP;
	}
}

extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);
void delay_ms(kal_uint32 millisecs)
{
	kal_uint32 start;
	volatile kal_uint32 duration, i;
	
	start = drv_get_current_time();  
	
	do
	{
	  for(i=0;i<5000;i++){}// loop 5000 times per 1ms
	  duration = drv_get_duration_ms(start);
	}while(duration < millisecs);

}

void ctp_update_firmware_enable_wdt(kal_bool enable)
{
	
	WDT_CTRL_ENABLE_T wdt_data;
	DCL_HANDLE init_dcl_wdt_handle;
	
	wdt_data.fgEnable=enable;
	init_dcl_wdt_handle=DclWDT_Open(DCL_WDT,0); 
	DclWDT_Control(init_dcl_wdt_handle,WDT_CMD_ENABLE,(DCL_CTRL_DATA_T*)&wdt_data);
	DclWDT_Close(init_dcl_wdt_handle);	
}

extern	void gtp_reset_guitar(struct i2c_client *client, kal_uint32 ms);
static kal_bool ctp_goodix_gt9xx_init(void)
{
    DCL_HANDLE sda_handle, scl_handle;
    DCL_HANDLE eint_handle, reset_handle;
    kal_bool ack;
    ctp_info_t ctp_info;
	kal_uint16 reg_value;

	kal_uint8 i=0;
//	hotknot_timerid = kal_create_timer("hotknot");
//	hotknot_readback_timerid = kal_create_timer("hotknot_readback");
#ifdef __HOTKNOT_SUPPORT__
	touch_hotknot_init();
#endif
    CTP_DEBUG_LINE_TRACE();

	//turn on VMC
	Drv_ReadReg(0xA07001C0,&reg_value);
	reg_value |= 0x03;
	DRV_WriteReg(0xA07001C0,reg_value);

	//turn on VSIM2
	Drv_ReadReg(0xA0700198,&reg_value);
	reg_value |= 0x02;
	DRV_WriteReg(0xA0700198,0x2);

	Drv_ReadReg(0xA0700190,&reg_value);
	reg_value |= 0x01;
	DRV_WriteReg(0xA0700190,reg_value);

    //gpio_ctp_reset_pin
    //ctp_goodix_gt9xx_power(KAL_TRUE);

    // init i2c 
    if(gpio_ctp_i2c_sda_pin != 0xFF)
    {
        sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
        scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);

        DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
        DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
        CTP_DELAY_TIME = 3;
    }

    ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);

    eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
    reset_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	    
	////////////////////////////reset//////////////////////////////////
	DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_LOW, NULL);

	DclGPIO_Control(reset_handle, GPIO_CMD_SET_MODE_0, NULL);	
	DclGPIO_Control(reset_handle, GPIO_CMD_SET_DIR_OUT, NULL);    
	DclGPIO_Control(reset_handle, GPIO_CMD_WRITE_LOW, NULL);
	delay_ms(5);	
	DclGPIO_Control(reset_handle, GPIO_CMD_WRITE_HIGH, NULL);
	delay_ms(50);	
	//////////////////////////////////////////////////////////////////
	DclGPIO_Close(eint_handle);
	DclGPIO_Close(reset_handle);
#ifdef __MTK_TARGET__    
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
		DclGPIO_Control(eint_handle, gpio_ctp_eint_pin_M_EINT, NULL);
		EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
#endif
#if 0
/* under construction !*/
/* under construction !*/
#endif

	//test_lenth = gtp_load_hoknot_data(test_data);
#if 1			
	ack = ctp_goodix_gt9xx_set_configuration();
	if(ack == KAL_FALSE)
	{
		kal_prompt_trace(MOD_TP_TASK, "ctp_goodix_gt9xx_set_configuration fail!!!" );
    	return KAL_FALSE;
	}	
	kal_prompt_trace(MOD_TP_TASK, "ctp_goodix_gt9xx_set_configuration OK!!!" );

	ack = ctp_goodix_gt9xx_get_information( &ctp_info );
    
    if ( ack == KAL_FALSE )
    {
        kal_prompt_trace(MOD_TP_TASK, "read information fail" );
        return KAL_FALSE;
    }
#endif
#ifdef __HOTKNOT_SUPPORT__
	tp_hotknot_enable();
	//gtp_hotknot_enter_master();
	
	//kal_set_timer(hotknot_readback_timerid,(kal_timer_func_ptr)ctp_print_parameter, NULL,  1000, 0);
	//gup_update_proc(NULL);

	//hotknot function
	//kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)Hotknot_polling_cb, NULL,  HOTKNOT_PERIOD, 0);
#endif
	
    return KAL_TRUE;
	
}

static kal_bool ctp_goodix_gt9xx_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
	return KAL_TRUE;
}

static kal_bool ctp_read_one_point(kal_uint32 x_base, TP_SINGLE_EVENT_T *event)
{
	kal_uint8 point_info[CTP_POINT_INFO_LEN];
#ifdef TPD_BYTE_READ_WORKAROUND
	int i;

	for ( i = 1 ; i < CTP_POINT_INFO_LEN ; i++ )
	{
		CTP_I2C_read(x_base+i, &point_info[i], 1);
	}
#else
	CTP_I2C_read(x_base, point_info, CTP_POINT_INFO_LEN);
#endif

	//event->y = CTP_Y_RES - (( point_info[1] + ( point_info[2] << 8 ))*CTP_Y_RES)/800;
	//event->x = CTP_X_RES - (( point_info[3] + ( point_info[4] << 8 ))*CTP_X_RES)/480;
	//event->z = point_info[5] + ( point_info[6] << 8 );

	event->x = point_info[1] + ( point_info[2] << 8);
	event->y = point_info[3] + ( point_info[4] << 8);
	event->z = 32;
	kal_prompt_trace(MOD_TP_TASK, "id:%d", point_info[0]);
	drv_trace2( TRACE_GROUP_7, CTP_COORDINATE1, event->x, event->y);

	return KAL_TRUE;
		
}

static kal_bool ctp_read_all_point(TouchPanelMultipleEventStruct *tpes, kal_uint32 points)
{
    kal_uint32 i=0;
    TP_SINGLE_EVENT_T get_one_point;	
	
    ASSERT(tpes);

    if((points<1) || (points>5))
    {
        return KAL_FALSE;
    }
		
    for(i=0;i<points;i++)
    {
        ctp_read_one_point( CTP_POINT_INFO_REG_BASE + CTP_POINT_INFO_LEN*i , &get_one_point);
        tpes->points[i].x = get_one_point.x;
        tpes->points[i].y = get_one_point.y;
        tpes->points[i].z = get_one_point.z;
    }	

    return KAL_TRUE;
		
}

extern kal_uint8 load_fw_process;

static kal_bool ctp_goodix_gt9xx_get_data(TouchPanelMultipleEventStruct *tpes)
{
	kal_uint8  lvalue = 0;
	kal_uint32 model = 0;
	kal_uint8  buf_status;
	kal_bool   ret = KAL_TRUE;
	kal_uint8  rst_char = 0;
	kal_uint8 config_info[5],i;

	ASSERT(tpes);

	if(load_fw_process)
		return KAL_FALSE;

	tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	tpes->padding = CTP_PATTERN;
	
	CTP_I2C_read(CTP_CONFIG_REG_BASE, &config_info[0],5);
	for(i=0;i<5;i++)
	{
		kal_prompt_trace(MOD_TP_TASK,"config_info[%d] = %d",i,config_info[i]);
	}
	CTP_I2C_read( CTP_TOUCH_INFO_REG_BASE, &lvalue, 1);

	model = (kal_uint32)(lvalue & CTP_STAT_NUMBER_TOUCH);
	buf_status = lvalue&0xF0;

	kal_prompt_trace(MOD_TP_TASK, "model:%d buf_status:%d", model,buf_status);


    if(model > 5) //goodix only support 5 fingers
    {
        ret = KAL_FALSE;
        goto exit_get_data;
    }

	tpes->model = (kal_uint16)model;  //read out all touch points coordinates.

	if (model == 0)
	{
		ret = KAL_FALSE;
		CTP_I2C_read( CTP_POINT_INFO_REG_BASE + 1 , &lvalue, 1);
		goto exit_get_data;
	}
    
	if ( model <= 10 )
	{
		if ( ( buf_status & 0x80 ) != 0 )        
		{
			ctp_read_all_point(tpes, model);
		}
		else
		{
			goto exit_get_data;
		}
	}
	else
	{
		if(model == 0x0d)
		{
			//TODO: check this event
		}
		else if(model == 0x0e)
		{
			//TODO: check this event
		}
		else
		{
			//TODO: check this event
		}

		goto exit_get_data;
	}

exit_get_data:   
 
	CTP_I2C_send( CTP_TOUCH_INFO_REG_BASE , &rst_char, 1);

	return ret;
	
}

#ifdef __HOTKNOT_SUPPORT__
extern kal_bool is_hotknot_pair;
#endif

static kal_bool ctp_goodix_gt9xx_set_device_mode(ctp_device_mode_enum mode)
{
	kal_uint8 suspend_command = 0x05;
	DCL_HANDLE eint_handle;
	ctp_info_t ctp_info;
	kal_uint8 ctp_buffer[2] = {0};

	//kal_prompt_trace(MOD_TP_TASK,"SET MODE CTP_ACTIVE_MODE = %d",CTP_ACTIVE_MODE);
	//kal_prompt_trace(MOD_TP_TASK,"SET MODE CTP_SLEEP_MODE = %d",CTP_SLEEP_MODE);
	//kal_prompt_trace(MOD_TP_TASK,"SET MODE CTP_FIRMWARE_UPDATE = %d",CTP_FIRMWARE_UPDATE);
	//kal_prompt_trace(MOD_TP_TASK,"SET MODE mode = %d",mode);
	//kal_prompt_trace(MOD_TP_TASK,"is_hotknot_pair = %d",is_hotknot_pair);
	if( mode == CTP_ACTIVE_MODE )
	{      
		//gup_update_proc(NULL);
		//gtp_reset_guitar(NULL,20);
		kal_prompt_trace(MOD_TP_TASK,"ctp_sleep_in");
		eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_HIGH, NULL);
		delay_ms(15);
		DclGPIO_Control(eint_handle, gpio_ctp_eint_pin_M_EINT, NULL);
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_IN, NULL);
		CTP_DEBUG_LINE_TRACE();
		//ctp_goodix_gt9xx_init();
#ifdef __HOTKNOT_SUPPORT__
		tp_hotknot_enable();
#endif
		DclGPIO_Close(eint_handle);
	}    
	else if( (mode == CTP_SLEEP_MODE)
#ifdef __HOTKNOT_SUPPORT__
		&& (is_hotknot_pair == KAL_FALSE) 
#endif
		)
	{
#ifdef __HOTKNOT_SUPPORT__
		tp_hotknot_disable();
#endif
		eint_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_eint_pin);
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(eint_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(eint_handle, GPIO_CMD_WRITE_LOW, NULL);
		delay_ms(5);
		CTP_I2C_send( CTP_POWER_MODE_REG, &suspend_command, 1 );
		CTP_I2C_read(CTP_POWER_MODE_REG,ctp_buffer,1);
		kal_prompt_trace(MOD_TP_TASK,"SET MODE mode readback= %d",ctp_buffer[0]);
		CTP_DEBUG_LINE_TRACE();
		DclGPIO_Close(eint_handle);
	}
	else if (mode == CTP_FIRMWARE_UPDATE )
	{
	#ifdef __MTK_TARGET__
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif
	ctp_update_firmware_enable_wdt(KAL_FALSE);
	gup_update_proc(NULL);
	ctp_update_firmware_enable_wdt(KAL_TRUE);
	//gtp_reset_guitar(NULL,5);
	//gtp_reset_guitar(NULL, 5);
		//ctp_goodix_gt9xx_init();
	#endif        
	}
	
	return KAL_FALSE;
	
}

static kal_uint32 ctp_goodix_gt9xx_command(kal_uint32 cmd, void* p1, void* p2) // p1: input p2: output
{
	#define TPD_SYNC_REG                  0x711
	#define TPD_DIFF_DATA_REG             0xD80
	#define TPD_CHANNEL_CONFIG_REG        0x6D5
	#define TPD_RAW_DATA_1_REG            0x880
	#define TPD_RAW_DATA_2_REG            0x9C0

	#define MAX_DRIVING_CHANNEL 16
	#define MAX_SENSING_CHANNLE 10
	#define MAX_DIFF_DATA_SIZE   (MAX_DRIVING_CHANNEL*MAX_SENSING_CHANNLE*2)
	#define MAX_RAW_DATA_SIZE    MAX_DIFF_DATA_SIZE

	char **dst = (char **)p2;
	ctp_info_t ctp_info;
	kal_bool ret = KAL_TRUE;
	kal_uint8 *cfg = (kal_uint8 *)p1;
	kal_uint8 mode;
	kal_uint8 *tpd_raw_data;
	kal_uint8 tmp[MAX_DIFF_DATA_SIZE];
	kal_uint8 *ptr;
	kal_uint8 row;

	*dst = NULL;

	switch ( cmd )
	{
		case DCL_CTP_COMMAND_GET_VERSION: // get firmware version
			if ( ctp_goodix_gt9xx_get_information(&ctp_info) )
			{
				memcpy( tpd_raw_data, (kal_uint8 *)&ctp_info, sizeof( ctp_info_t ) );
				*dst = (char *)tpd_raw_data;
			}
			else
			{
				ret = KAL_FALSE;
			}
			break;
			
		case DCL_CTP_COMMAND_GET_CONFIG:
			if ( 	CTP_I2C_read( CTP_CONFIG_REG_BASE, tpd_raw_data, CTP_CONFIG_LENGTH ) )
			{
				*dst = (char *)tpd_raw_data;
			}
			else
			{
				ret = KAL_FALSE;
			}
			break;
			
		case DCL_CTP_COMMAND_LOAD_INT_CONFIG:
			ctp_goodix_gt9xx_set_configuration();
			break;
			
		case DCL_CTP_COMMAND_LOAD_EXT_CONFIG:
			cfg[105] = 1;
			CTP_I2C_send( CTP_CONFIG_REG_BASE, cfg, CTP_CONFIG_LENGTH );
			break;
			
		case DCL_CTP_COMMAND_GET_DIFF_DATA:
			break;
			
		case DCL_CTP_COMMAND_GET_FW_BUFFER:
			break;
		
		case DCL_CTP_COMMAND_DO_FW_UPDATE:
			break;
			
		default:
			ret = KAL_FALSE;        
	}
    
	return ret;	
	
}

CTP_custom_information_struct *ctp_Get_Data(void) 
{
	return (&ctp_custom_information_def);
}

static CTP_customize_function_struct ctp_custom_func=
{
	ctp_goodix_gt9xx_init,
	ctp_goodix_gt9xx_set_device_mode,
	ctp_goodix_gt9xx_hisr,
	ctp_goodix_gt9xx_get_data,
	ctp_goodix_gt9xx_parameters,
	ctp_goodix_gt9xx_power,
	ctp_goodix_gt9xx_command
};

CTP_customize_function_struct *ctp_GetFunc(void)
{
	return (&ctp_custom_func);  
}

#else

DCL_STATUS DclHPXS_Initialize(void)
{
	return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclHPXS_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclHPXS_Close(DCL_HANDLE handle)
{
	return STATUS_UNSUPPORTED;
}

#endif //#ifdef __CTP_GOODIX_GT9xx_TRUE_MULTIPLE__
