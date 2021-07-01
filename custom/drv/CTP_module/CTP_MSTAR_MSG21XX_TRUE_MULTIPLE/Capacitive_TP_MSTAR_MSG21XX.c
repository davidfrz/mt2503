//add by CKT WangLei 2011-12-26 FixID:3573 TP driver begin
#if defined(__TOUCH_PANEL_CAPACITY__)
/**********************************************************************
*	Head files
**********************************************************************/
#include "kal_release.h"
//#include "pwic.h"
#include "sccb_v2.h"
#include "touch_panel.h"
#include "eint.h"
#include "Capacitive_TP_MSTAR_MSG21XX.h"
#include "drv_comm.h"
#include "Capacitive_TP_I2C.h"
#include "I2c.h"
#include "Dcl.h"
#include "touch_panel_custom.h"
#include "us_timer.h"
#include "kbd_table.h"

/*****************************************************
CTP debug macro define
*****************************************************/
#define DBG_CTP
#ifdef DBG_CTP
#define ctp_dbg_print		kal_prompt_trace
#else
#define ctp_dbg_print(...)
#endif

#ifndef __MTK_TARGET__
void dbg_print(char *fmt,...){}
#endif

#if !defined(IC_MODULE_TEST)
extern kal_uint32 /*lint -e(526)*/L1I_GetTimeStamp(void);
#endif

/*****************************************************
CTP global struct and variable
*****************************************************/
#if defined(__FAR_ANALOG_DISTANCE_SENSOR__)
static kal_uint8 g_far_flag_tp_call =0;
#endif

#define __MTK6260__  
/*
The variable CTP_DELAY_TIME is to indicate the I2C transmission speed.
But the speed will be modified after calling function ctp_i2c_configure()
*/
kal_uint32 CTP_DELAY_TIME	= 300;

CTP_parameters_struct CTP_parameters;

/*
This struct recorded the basic infomation of the CTP vendor and chip id
*/
CTP_custom_information_struct  ctp_custom_information_def = 
{
	"SMC",
		"MSG2033",
		"UNKNOWN ",	
};
void Ctp_MSG2133_Delayus(kal_uint32 delay)
{
	volatile kal_uint32 uscnt2, uscnt1;
	kal_uint32 count = 0;
	kal_uint32 escape = 0;
	
	uscnt1 = ust_get_current_time();
	do{
		uscnt2 = ust_get_current_time();
		if( uscnt2 > uscnt1 )
		{
			count += uscnt2 - uscnt1;
		}
		else if(uscnt2 < uscnt1)
		{
			count += uscnt2+1;
		}
		uscnt1 = uscnt2;
		escape++;
	}while( ( count <= delay ) && (escape < 0xFFFFFF) );
	
	if(escape == 0xFFFFFF)
		ASSERT(0);
}

void Ctp_MSG2133_Delayms(kal_uint32 delay)
{
	kal_uint32 tick, duration;
	
	tick = drv_get_current_time();
	do{
		duration = drv_get_duration_ms(tick);
	}while(duration < delay);
}


/*********************************************************************
*    			I2C and CTP transmission API 
*				Function Implement 
*********************************************************************/
/*
Enable HW I2C power domain.
JUST for HW I2C.

  CTP_I2C_LDO 			==>		HW I2C using LDO 	(see to enum PMU_LDO_BUCK_LIST_ENUM)
  CTP_I2C_LDO_VOLTAGE	==>		The voltage of VIO	(see to enum PMU_VOLTAGE_ENUM)
  CTP_I2C_LDO and CTP_I2C_LDO_VOLTAGE are defined in the file "touch_panel_custom.h".
  The customer can modify them according to the actual hardware design
*/
/*
extern char gpio_ctp_reset_pin;

void CTP_I2C_POWER_ON(void)
{
	DCL_HANDLE rst_handle;
	
	dbg_print("CTP_I2C_POWER_ON \r\n");
	
	rst_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_MODE_0, NULL);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
	
	//ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
}
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_i2c_sda_pin;
void CTP_I2C_POWER_OFF(void)
{
	DCL_HANDLE rst_handle;
	DCL_HANDLE sda_handle;
	DCL_HANDLE scl_handle;  
	dbg_print("CTP_I2C_POWER_ON \r\n");
	
	rst_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_MODE_0, NULL);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	
	DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_LOW, NULL);
	
	if(gpio_ctp_i2c_sda_pin != 0xFF)	
	{
		sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		
		DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);	
		
		scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);
		
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
		
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
	}
	
	//ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
}
*/
extern const char gpio_ctp_i2c_scl_pin;
extern const char gpio_ctp_i2c_sda_pin;
extern const char gpio_ctp_reset_pin;
//power
DCL_HANDLE breath_pmu_handle=DCL_HANDLE_NONE;
void touchpanel_ldo_power_on(kal_bool ON, kal_uint32 ldo, kal_uint32 ldo_volt)
{
	PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN pmu_ldo_voltage_en;
	PMU_CTRL_LDO_BUCK_SET_EN pmu_ldo_en;
	PMU_CTRL_LDO_BUCK_SET_VSIM2_GPLDO_EN pmu_vsim2_ldo_voltage_en;
	PMU_CTRL_LDO_BUCK_SET_SIM2_GPIO_EN pmu_vsim2_gpio_en;
	breath_pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
		
	pmu_ldo_voltage_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
	pmu_ldo_voltage_en.voltage =(PMU_VOLTAGE_ENUM)ldo_volt;
	DclPMU_Control(breath_pmu_handle, LDO_BUCK_SET_VOLTAGE_EN,(DCL_CTRL_DATA_T *)& pmu_ldo_voltage_en);

		//VSIM2
		pmu_vsim2_ldo_voltage_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
		pmu_vsim2_ldo_voltage_en.enable = ON;
		DclPMU_Control(breath_pmu_handle, LDO_BUCK_SET_VSIM2_GPLDO_EN,(DCL_CTRL_DATA_T *)& pmu_vsim2_ldo_voltage_en);

		//vsim2 gpio
		pmu_vsim2_gpio_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
		pmu_vsim2_gpio_en.enable = ON;
              DclPMU_Control(breath_pmu_handle, LDO_BUCK_SET_SIM2_GPIO_EN,(DCL_CTRL_DATA_T *)&pmu_vsim2_gpio_en);
			
		pmu_ldo_en.mod = (PMU_LDO_BUCK_LIST_ENUM)ldo;
		pmu_ldo_en.enable = ON;
		DclPMU_Control(breath_pmu_handle, LDO_BUCK_SET_EN,(DCL_CTRL_DATA_T *)&pmu_ldo_en);


}

/*********************************************************************
 *    			I2C and CTP transmission API 
 *				Function Implement 
 *********************************************************************/
/*
Enable HW I2C power domain.
JUST for HW I2C.

CTP_I2C_LDO 			==>		HW I2C using LDO 	(see to enum PMU_LDO_BUCK_LIST_ENUM)
CTP_I2C_LDO_VOLTAGE	==>		The voltage of VIO	(see to enum PMU_VOLTAGE_ENUM)
CTP_I2C_LDO and CTP_I2C_LDO_VOLTAGE are defined in the file "touch_panel_custom.h".
The customer can modify them according to the actual hardware design
*/
void CTP_I2C_POWER_ON(void)
{

	DCL_HANDLE rst_handle;
	DCL_HANDLE sda_handle;
	DCL_HANDLE scl_handle;	
	dbg_print("CTP_I2C_POWER_ON \r\n");
	
	rst_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_DIR_OUT, NULL);	
	DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_HIGH, NULL);
	DclGPIO_Close(rst_handle);

	//Ctp_MSG2133_Delayms(10);

	if(gpio_ctp_i2c_sda_pin != 0xFF)
	{
		sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_HIGH, NULL);
		DclGPIO_Close(sda_handle);
		
		scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_HIGH, NULL);
		DclGPIO_Close(scl_handle);
	}

	//ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
	//touchpanel_ldo_power_on(KAL_TRUE,VSIM2, PMU_VOLT_03_000000_V);	
}

void CTP_I2C_POWER_OFF(void)
{
	
	//touchpanel_ldo_power_on(KAL_FALSE,VSIM2, PMU_VOLT_03_000000_V);
	DCL_HANDLE rst_handle;
	DCL_HANDLE sda_handle;
	DCL_HANDLE scl_handle;
	
	rst_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_reset_pin);
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(rst_handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(rst_handle, GPIO_CMD_WRITE_LOW, NULL);
	DclGPIO_Close(rst_handle);

	//Ctp_MSG2133_Delayms(10);
	
	/*if(gpio_ctp_i2c_sda_pin != 0xFF)
	{

		sda_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_sda_pin);
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(sda_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(sda_handle, GPIO_CMD_WRITE_LOW, NULL);
		DclGPIO_Close(sda_handle);
		
		scl_handle = DclGPIO_Open(DCL_GPIO, gpio_ctp_i2c_scl_pin);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_MODE_0, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_SET_DIR_OUT, NULL);
		DclGPIO_Control(scl_handle, GPIO_CMD_WRITE_LOW, NULL);
		DclGPIO_Close(scl_handle);
	}*/
	
	

}
/*
Do HW I2C initialization
JUST for HW I2C.

  About "I2C CLOCK EXTENSION",  it is a feature of the Hardware I2C.
  Enable I2C clock extension. It means host will hold the clk pin low until client pull the clk pin high.
  To some CTP chip that need much strict I2C timing, we should enable I2C clock extension feature.
*/
void CTP_I2C_Init(void)
{
	ctp_i2c_configure(CTP_SLAVE_ADDR, CTP_DELAY_TIME);		//set hw i2c speed is 300K (fast mode)
	ENABLE_I2C_CLOCK_EXTENSION;					//<==Must enable i2c_clk_extension for being ensure controller timing matching with HW I2C timing
	#ifdef __MTK6260__
	SET_I2C_SCL_WIRED_AND_MODE;
	SET_I2C_SDA_WIRED_AND_MODE;
	#endif
	
}

kal_bool MSG2033_i2c_send(kal_uint8 ucDeviceAddr, kal_uint8* pucData, kal_uint32 unDataLength)
{
	kal_uint32 i;
	kal_bool bRet = KAL_TRUE;

	if(gpio_ctp_i2c_sda_pin == 0xFF)
	{
		ctp_i2c_send(ucDeviceAddr, pucData[0], pucData + 1, unDataLength - 1);
	}
	else
	{
		ctp_i2c_start();

		if(ctp_i2c_send_byte(ucDeviceAddr & 0xFE) == CTP_I2C_ACK)
		{
			ctp_i2c_udelay(200);
			for(i = 0; i < unDataLength; i++)
			{
				if(ctp_i2c_send_byte(pucData[i]) == CTP_I2C_NAK)
				{
					ctp_dbg_print(MOD_TP_TASK, "MSG2033_i2c_send CTP_I2C_NAK failed!");
					bRet = KAL_FALSE;
					break;
				}
			}
		}
		else
		{
			ctp_dbg_print(MOD_TP_TASK, "MSG2033_i2c_send CTP_I2C_ACK failed!");
			bRet = KAL_FALSE;
		}
		ctp_i2c_stop();
	}

	return bRet;
}


// I2C receive data function
kal_bool MSG2033_i2c_receive(kal_uint8 ucDeviceAddr, kal_uint8* pucData, kal_uint32 unDataLength)
{
	kal_uint32 i;
	kal_bool bRet = KAL_TRUE;

	if(gpio_ctp_i2c_sda_pin == 0xFF)
	{
	#ifdef __MTK6260__
	ctp_i2c_receive_ext(ucDeviceAddr,0, pucData, unDataLength);
	//ctp_i2c_receive(ucDeviceAddr, pucData, unDataLength);
	#else
	ctp_i2c_receive(ucDeviceAddr, 0, pucData, unDataLength);
	#endif
	}
	else
		
	{

		ctp_i2c_start();
		
		if(ctp_i2c_send_byte(ucDeviceAddr | 0x01) == CTP_I2C_ACK)
		{
			ctp_i2c_udelay(100);
			//ctp_i2c_start();
			for(i = 0; i < unDataLength - 1; i++)
			{
				pucData[i] = ctp_i2c_receive_byte((kal_bool)CTP_I2C_ACK);
			}
			pucData[unDataLength - 1] = ctp_i2c_receive_byte((kal_bool)CTP_I2C_NAK);
		}
		else
		{
			ctp_dbg_print(MOD_TP_TASK, "MSG2033_i2c_receive fail!");
			bRet = KAL_FALSE;
		}
		ctp_i2c_stop();
	}

	return bRet;
}


/***************************************************************
*    			     MSG2033 CTP driver API 
*				Function Implement 
***************************************************************/
/*
MSG2033 CTP initialization
*/

extern kal_bool firmware_version_store(void);
extern void firmware_update_store(kal_bool readfile);
extern kal_uint8 update_switch=0 ;

kal_bool ctp_MSG_2033_init(void)
{
	kal_uint8 lvalue;
	kal_uint8 write_data[2];
	kal_bool temp_result = KAL_TRUE;

	if(gpio_ctp_i2c_sda_pin != 0xFF)
	{
		CTP_DELAY_TIME = 10;
	}
	
	//CTP_I2C_POWER_ON();
	//reset
	CTP_SET_RESET_PIN_OUTPUT;	
	CTP_SET_RESET_PIN_HIGH;
	Ctp_MSG2133_Delayms(10);
	//CTP_SET_RESET_PIN_LOW;		
	//Ctp_MSG2133_Delayms(10);
	//CTP_SET_RESET_PIN_HIGH;
	//Ctp_MSG2133_Delayms(200);
	
	CTP_I2C_Init();
	
	//kal_sleep_task(1);
	
	EINT_Set_HW_Debounce(custom_eint_get_channel(touch_panel_eint_chann), 0);
	EINT_SW_Debounce_Modify(custom_eint_get_channel(touch_panel_eint_chann),0);
	EINT_Set_Sensitivity(custom_eint_get_channel(touch_panel_eint_chann), EDGE_SENSITIVE);
	EINT_Set_Polarity(custom_eint_get_channel(touch_panel_eint_chann),LEVEL_LOW); //modify
	Ctp_MSG2133_Delayms(300);
#if defined(TP_FIRMWARE_UPDATE) 
	if(firmware_version_store()==KAL_FALSE)
	{
		firmware_update_store(0);
	}
#endif
    if (KAL_FALSE == temp_result)
    {
		ctp_dbg_print(MOD_TP_TASK, "ctp_cypress_cy8ctma340_init failed!");
		
		return KAL_FALSE;
    }
	else
	{
		ctp_dbg_print(MOD_TP_TASK, "ctp_cypress_cy8ctma340_init succeed! HST_MODE_ADDR=%x", lvalue);
		
		return KAL_TRUE;
	}
}


/*
Upper layer will call this function to enable/disable CTP power.
If FOCUS the POWRE CONSUME, it is suggested to implement it!
*/
kal_bool ctp_MSG_2033_power_on(kal_bool enable)
{
#if defined(__FAR_ANALOG_DISTANCE_SENSOR__)
	if(g_far_flag_tp_call)
	{
		return;
	}
#endif
	
	//_TODO:  Implement this funciton by customer
	if( enable )
	{
		CTP_I2C_POWER_ON();
		//ctp_i2c_power_on(KAL_TRUE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
		ctp_dbg_print(MOD_TP_TASK, "ctp_MSG_2033_power_on !!!!!!!!!");
	}
	else
	{
		CTP_I2C_POWER_OFF();
	}
#if defined(TP_FIRMWARE_UPDATE) //by yxy 20130929
	else if(update_switch==0)
	{
		//   ctp_i2c_power_on(KAL_FALSE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
		CTP_I2C_POWER_OFF();
		ctp_dbg_print(MOD_TP_TASK, "ctp_MSG_2033_power_off !!!!!!!!!");
	}
#endif
	return 1;
}

kal_bool ctp_MSG_2033_power_off(kal_bool enable)
{
	//_TODO:  Implement this funciton by customer
#if defined(TP_FIRMWARE_UPDATE) //by yxy 20130929
	if(update_switch==0)
	{
		//ctp_i2c_power_on(KAL_FALSE, CTP_I2C_LDO, CTP_I2C_LDO_VOLTAGE);
	}
#endif
	return 1;
}

/*
If needed, uppder layer will call this function to swicth CTP mode.

  By now, Maybe this function has not been used by upper layer.
  If you want to implement this function, you can see the sample code in the function body.
*/
kal_bool ctp_MSG_2033_device_mode(ctp_device_mode_enum mode)
{
	
	//_TODO:  if needed, add this function to switch decive work mode
	//_TODO: Implement this function by customer
	
	return KAL_TRUE;
}


/*
The following function is JUST used in timer trigger mode. 
Now we use interrupt mode to get data. So this function is not used.

  ATTENTION: DO NOT delete this function!!
  This function is one member of the CTP function pointer struct.
*/
Touch_Panel_PenState_enum ctp_MSG_2033_hisr(void)
{
	return 0;
}


/*
This function is a INTERNAL FUNCTION in CTP driver.
By now, it has not been used~
If needed, implement it by yourselves.
But NO implement is OK~
*/
kal_bool ctp_MSG_2033_get_version(CTP_custom_information_struct  *version)
{
	return KAL_TRUE;
}

/*
This function is used to get parameter from CTP IC or set parameter to CTP IC.

  By now, Maybe this function has not been used by upper layer.
  ATTENTION: If need to implement it, DO NOT get and set the same parameter in the same time
*/
kal_bool ctp_MSG_2033_parameters(CTP_parameters_struct *para, kal_uint32 get_para, kal_uint32 set_para)
{
	//_TODO: not implement. if needed,  please add them.
	//_TODO: Implement this function by customer
	
	
	return KAL_TRUE;
}

kal_uint8 tp_caculate_checksum(const kal_uint8 *buf, kal_uint32 size)
{
	kal_uint32 i;
	kal_uint8 chksum = 0;
	
	for (i = 0; i < size; i++)
	{
		chksum += *buf++;    
	}
	chksum = (kal_uint8) (256 - chksum) & 0xFF;
	return chksum;
}

kal_uint8 kbd_status = 0;
extern kal_uint32  kbd_set_short_cut_key(kal_uint8);
/*
This fucntion is a INTERNAL FUNCTION in the CTP driver.

  It ONLY can be used to read the coordination values of all points that are pressed now 
  and JUST be called by ctp_MSG_2033_get_data() function.
*/
kal_bool msg2033_read_all_point(TouchPanelMultipleEventStruct *tpes)
{
	kal_bool temp_result;
	kal_uint32 i = 0;
	kal_uint8 values[8] = {0};
	kal_uint16 temp_x=0, temp_y=0;//, diff_x=0, diff_y=0;
	static kal_uint32 virtual_key = DEVICE_KEY_NONE;
	static kal_uint32 virtual_key2 = DEVICE_KEY_NONE;
	
	ASSERT(tpes);
	temp_result = MSG2033_i2c_receive(CTP_SLAVE_ADDR,values, 8);
/*
kal_prompt_trace(MOD_AUX,"(msg2033_read_all_point debug info)values[0]=%x,values[1]=%x,values[2]=%x,values[3]=%x,values[4]=%x,values[5]=%x,values[6]=%x,values[7]=%x\n",
values[0],values[1],values[2],values[3],values[4],values[5],values[6],values[7]
);
*/
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	tpes->model=0;

	if((values[0] == 0x52) && (tp_caculate_checksum(values,7) == values[7]))
	{
		if(values[1]==0xff && values[2]==0xff && values[3]==0xff && values[4]==0xff && values[6]==0xff)
		{				
			if(values[5]==0x01)
			{
				tpes->model=0;
				kbd_status = values[5];
				//kbd_set_short_cut_key(0);
				virtual_key = DEVICE_KEY_BACK;
				//ctp_dbg_print(MOD_TP_TASK, "\r\n Key 1====");
			}
			else if(values[5]==0x02)
			{
				tpes->model=0;
				kbd_status = values[5];
				//kbd_set_short_cut_key(1);
				virtual_key = DEVICE_KEY_HOME;
				//ctp_dbg_print(MOD_TP_TASK, "\r\n Key 2====");
			}
			else if(values[5]==0x04)
			{
				tpes->model=0;
				kbd_status = values[5];
				//kbd_set_short_cut_key(2);
				virtual_key = DEVICE_KEY_SEND;
				//ctp_dbg_print(MOD_TP_TASK, "\r\n Key 3====");
			}
			else if(values[5]==0x08)
			{
				tpes->model=0;
				kbd_status = values[5];
				//kbd_set_short_cut_key(3);
				//ctp_dbg_print(MOD_TP_TASK, "\r\n Key 4====");
			}
			else if(values[5]==0x40)
			{
				//kal_prompt_trace(MOD_TP_TASK,"DEVICE_KEY_F2 %d", values[5]);
				tpes->points[0].x = 0xFFFF;
				tpes->points[0].y = 0xFFFF;
				if(virtual_key2 == DEVICE_KEY_F1)
                {
                    //kbd_Press_one_key(DEVICE_KEY_F2);
			        virtual_key2 = DEVICE_KEY_NONE;
                    kal_prompt_trace(MOD_TP_TASK,"DEVICE_KEY_F2");
                }
				
			}
			else if(values[5]==0x80)
			{
				//kal_prompt_trace(MOD_TP_TASK,"DEVICE_KEY_F1 %d", values[5]);
				tpes->points[0].x = 0xFFFF;
				tpes->points[0].y = 0xFFFF;
				if(virtual_key2 == DEVICE_KEY_NONE)
                {
                	//kbd_Press_one_key(DEVICE_KEY_F1);
			        virtual_key2 = DEVICE_KEY_F1;
                    kal_prompt_trace(MOD_TP_TASK,"DEVICE_KEY_F1");
                }                
			}
			//else if(values[5]==0xFF||values[5]==0x00)
			else if(values[5]==0xFF||values[5]==0x00||((values[5]&0x0F)!=0))
			{
				ctp_dbg_print(MOD_TP_TASK, "\r\n Touch Up====");
				tpes->model=0;
            #if 0 //by yxy 10130929
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
            	if(virtual_key != DEVICE_KEY_NONE)
				{
					//kbd_key_release(virtual_key);
					//kbd_Press_one_key(virtual_key);
					virtual_key = DEVICE_KEY_NONE;
				}
				kbd_status = 0;
                //ctp_dbg_print(MOD_TP_TASK, "msg2033_read_all_point error key");
				return KAL_FALSE;
			}
			else
			{
				ctp_dbg_print(MOD_TP_TASK, "key --> msg2033_read_all_point error check %x  %x  %x  %x  %x  %x", values[0], values[1], values[2], values[3], values[4], values[5]);
				return KAL_FALSE;
			}
		}
		else
		{
			temp_x = (((values[1] & 0xf0) << 4) & 0xff00) |values[2];
			temp_y = (((values[1] & 0x0f) << 8) & 0xff00) |values[3];
			if(temp_x <= 2047 && temp_y <= 2047)
			{
				tpes->model=1;
				//ctp_dbg_print(MOD_TP_TASK, "msg2033_read_all_point 2 x=%x,y=%x \r\n",temp_x,temp_y);

				temp_x=temp_x*15/128;            //5/32;//-20;//15/64
				temp_y=temp_y*15/128;            //15/64;//-75;//5/32
				tpes->points[0].x = 240 - temp_y;     //;
				tpes->points[0].y = temp_x;     //;         	
				
				ctp_dbg_print(MOD_TP_TASK, "msg2033_read_all_point 33333 x=%d,y=%d \r\n",tpes->points[0].x,tpes->points[0].y);
				//dbg_print("x=%d,y=%d \r\n",tpes->points[0].x,tpes->points[0].y);
			}
			else
			{
                ctp_dbg_print(MOD_TP_TASK, "msg2033_read_all_point error data");
				return KAL_FALSE;
			}
		}
	}
	else
	{
		ctp_dbg_print(MOD_TP_TASK, "msg2033_read_all_point error check result %x  %x  %x  %x  %x  %x", values[0], values[1], values[2], values[3], values[4], values[5]);
		return KAL_FALSE;
	}
	
	return KAL_TRUE;
}

/*
This function is used to get the raw data of the fingures that are pressed.
When CTP IC send intterupt signal to BB chip, this function will be called in the interrupt handler function.

  ATTENTION: Becasue this function is called in the interrupt handler function, it MUST NOT run too long.
  That will block the entire system.
  If blocking too long, it generally will cause system crash *....*
  */
 static TouchPanelMultipleEventStruct prevPt={0};
 kal_bool ctp_MSG_2033_get_data(TouchPanelMultipleEventStruct *tpes)
  {
	  kal_bool temp_result;
	  kal_uint8 lvalue;
	  kal_uint32 counter = 0;
	  //kal_uint32 model = 0;
      
	  ASSERT(tpes);
	  
	  tpes->time_stamp = (kal_uint16)L1I_GetTimeStamp();
	  tpes->padding = CTP_PATTERN;
	  
	  /*Using while loop to poll the CTP status.
	  We have to wait for CTP being ready, then get the coordination of the all points.
	  */
	  temp_result = msg2033_read_all_point(tpes);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
	  #endif
	  if(temp_result == KAL_TRUE)
	  {
		memcpy(&prevPt, tpes, sizeof(prevPt));
	  }
	  else
	  {
	  	memcpy(tpes, &prevPt, sizeof(prevPt));
	  }
	  
	  return temp_result;
 }
  
  /*
  JUST return CTP information.
  Not Need to modify it!
  */
 CTP_custom_information_struct *ctp_Get_Data(void) 
 {
	  return (&ctp_custom_information_def);
 }
  

#if defined(__CTP_COMBO_FAR__)	
kal_bool ctp_mstar_msg2133_check_id(void)
{
	return KAL_TRUE;
}
#endif

#if 0//defined(__ATA_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


#if defined(__PHONE_INFO_FAR__) 
kal_bool aatemp_result =0;

void ctp_mstar_msg2133_get_device_info(kal_uint8 *info)
{
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	//strcpy(info, "MSG2133");
	sprintf(info, "MSG2133 v %d", aatemp_result);
}
#endif
  
  /*
  This structure is to initialize function pointer to CTP driver.
  NOT all function MUST BE implemented in this struct, 
  JUST doing function declaration is OK!!
  
	But the following TWO functions MUST BE implemented:
	ctp_MSG_2033_init
	ctp_MSG_2033_get_data
	
  Other functions should be implemented by customer for better performance.
  */
CTP_customize_function_struct ctp_custom_func=
{
	  ctp_MSG_2033_init,
	  ctp_MSG_2033_device_mode,
	  ctp_MSG_2033_hisr,
	  ctp_MSG_2033_get_data,
	  ctp_MSG_2033_parameters,
	  ctp_MSG_2033_power_on,
	  NULL,//command
#if defined(__CTP_COMBO_FAR__)	
	  ctp_mstar_msg2133_check_id,
#endif
#if 0//defined(__ATA_SUPPORT__)
/* under construction !*/
#endif	
#if defined(__PHONE_INFO_FAR__)  
	  ctp_mstar_msg2133_get_device_info,
#endif	   	  
};
  
  /*
  Upper layer use this hook to get CTP driver function
  */
 CTP_customize_function_struct *ctp_GetFunc(void)
 {
  	
  	kal_uint8 values[8] = {0};
  	ctp_MSG_2033_init();
#if defined(__PHONE_INFO_FAR__) 
  	aatemp_result = MSG2033_i2c_receive(CTP_SLAVE_ADDR,values, 8);
#endif
  		
	  return (&ctp_custom_func);  
  }
#endif //#if defined(__TOUCH_PANEL_CAPACITY__)

kal_bool open_analog_distance_sensor(void) 
{

	kal_bool temp_result = 0;  
#ifdef __MTK_TARGET__

	kal_uint8 data1[4]= {0x52,0x00,0x4A,0xA0};//enable

	ctp_dbg_print(MOD_TP_TASK, "open_analog_distance_sensor");
	MSG2033_i2c_send(CTP_SLAVE_ADDR, data1, 4);
#if defined(__FAR_ANALOG_DISTANCE_SENSOR__)
	g_far_flag_tp_call = 1;
#endif
#endif
	return temp_result;
}
  
kal_bool close_analog_distance_sensor(void) 
{
	kal_bool temp_result = 0;  
#ifdef __MTK_TARGET__	
	kal_uint8 data1[4]= {0x52,0x00,0x4A,0xA1};//disable

#if defined(__FAR_ANALOG_DISTANCE_SENSOR__)
	g_far_flag_tp_call = 0;
#endif
 	ctp_dbg_print(MOD_TP_TASK, "close_analog_distance_sensor");
	MSG2033_i2c_send(CTP_SLAVE_ADDR, data1, 4);
#endif
	return temp_result;
}


  //add by CKT WangLei 2011-12-26 FixID:3573 TP driver end
