/* drivers/input/touchscreen/gt9xx_update.c
 *
 * 2010 - 2012 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * Version: 2.0   
 * Revision Record: 
 *      V1.0:  first release. by Andrew, 2012/08/27.
 *      V1.2:  modify gt9110p pid map, by Andrew, 2012/10/15
 *      V1.4: 
 *          1. modify gup_enter_update_mode,
 *          2. rewrite i2c read/write func
 *          3. check update file checksum
 *                  by Andrew, 2012/12/12
 *      v1.6:
 *          1. delete GTP_FW_DOWNLOAD related things.
 *          2. add GTP_HEADER_FW_UPDATE switch to update fw by gtp_default_fw in *.h directly
 *                  by Meta, 2013/04/18
 *      V2.0:
 *          1. GT9XXF main clock calibration
 *          2. header fw update no fs related
 *          3. update file searching optimization
 *          4. config update as module, switchable
 *                  by Meta, 2013/08/28
 */
#ifdef __MTK_TARGET__
#include "kal_release.h"
#include "Capacitive_TP_Goodix_GT9xx.h"
#include "Capacitive_TP_I2C.h"
#include "dcl.h"
#include "dcl_gpio.h"
#include "eint.h"
#include "kal_trace.h"
#include "Capacitive_TP_trc.h"
#include "fs_type.h"
#include "fs_func.h"
#include "GT9XX_hotknot.h"

#if ( (GTP_AUTO_UPDATE && GTP_HEADER_FW_UPDATE) || GTP_COMPATIBLE_MODE || GTP_HOTKNOT_MODULE)
    #include "gt9XX_firmware.h"
#endif

#if GTP_HOTKNOT_MODULE
//for hotknot BT MAC
#include "BtcmSrvGprot.h"
//for hotknot BLE MAC
#include "bt_api.h"

#include "phonesetup.h"

#include "custom_scatstruct.h"
#include "custom_ubin_irt.h"
#endif
#include "device.h"



#define GTP_GPIO_OUTPUT(pin,level) ctp_set_gpio(level,pin)
#define GTP_GPIO_AS_INT(pin)       ctp_set_gpio2eint(pin)

extern void delay_ms(kal_uint32 millisecs);
#define msleep(x) delay_ms(x)
extern void EINT_Mask(kal_uint8 eintno);
extern void EINT_UnMask(kal_uint8 eintno);
#define mt_eint_mask(x)   EINT_Mask(x)
#define mt_eint_unmask(x)  EINT_UnMask(x)
extern const char TOUCH_PANEL_EINT_NO;
#define CUST_EINT_TOUCH_PANEL_NUM TOUCH_PANEL_EINT_NO
extern kal_bool ctp_goodix_gt9xx_set_configuration( void );

static kal_uint32 ctp_firmware_mem_pool[(FW_SECTION_LENGTH + 1024) / sizeof(kal_uint32)];
static KAL_ADM_ID ctp_firmware_adm_id = NULL;

#define GFP_KERNEL 0	//for kzalloc use 2nd para

u8 * kzalloc(int len, int flag)
{
	ctp_firmware_adm_id = kal_adm_create(ctp_firmware_mem_pool, (FW_SECTION_LENGTH + 1024), NULL, KAL_FALSE);
	GTP_DEBUG("ctp_firmware_adm_id = %d",ctp_firmware_adm_id);
	return (u8 *) kal_adm_alloc(ctp_firmware_adm_id, len);
}

#define kfree(x)  do{\
				kal_adm_free(ctp_firmware_adm_id, x);\
				kal_adm_delete(ctp_firmware_adm_id);}while(0)


#define IS_ERR(x) (x < 0)


// porting define end

#if 1
#pragma pack(1)
typedef struct
{
    u8  hw_info[4];          //hardware info//
    u8  pid[8];              //product id   //
    u16 vid;                //version id   //
    
} st_fw_head;
#pragma pack()
#endif


typedef struct
{
    u8 force_update;
    u8 fw_flag;
    FS_HANDLE file;
    FS_HANDLE cfg_file;
    st_fw_head  ic_fw_msg;
    u32 fw_total_len;
    u32 fw_burned_len;
} st_update_msg;

st_update_msg update_msg;

struct i2c_client *i2c_client_point = NULL;

u16 show_len;
u16 total_len;
//extern u8 fw_updating;
extern	kal_uint8 gt9xx_config[];
u8 cfg_len = 186;
u8 searching_file = 0;
u8 got_file_flag = 0;
kal_uint8 load_fw_process = 0;

extern const char gpio_ctp_eint_pin;
extern const char gpio_ctp_reset_pin;

#define GTP_INT_PORT gpio_ctp_eint_pin
#define GTP_RST_PORT gpio_ctp_reset_pin


#if GTP_ESD_PROTECT
extern void gtp_esd_switch(struct i2c_client *client, s32 on);
#endif

#if (GTP_ESD_PROTECT || GTP_COMPATIBLE_MODE)
extern u8 is_reseting;
#endif

#if (GTP_COMPATIBLE_MODE ||GTP_HOTKNOT_MODULE)
CHIP_TYPE_T gtp_chip_type = CHIP_TYPE_GT9;
static u8 gup_check_and_repair(struct i2c_client *, s32 , u8 *, u32 );
#endif

#if GTP_COMPATIBLE_MODE
extern u8 rqst_processing;
s32 gup_fw_download_proc(void *dir, u8 dwn_mode);
#endif

#if GTP_HOTKNOT_MODULE
s32 gup_recovery_calibration0(void);
s32 gup_load_calibration0(char *filepath);
u8 * gup_load_calibration_from_file(char *filepath);
s32 gup_load_calibration(u8 *firmware, s32 length, u8 need_check);
#endif

#define _CLOSE_FILE(p_file) if (p_file && !IS_ERR(p_file)) \
                            { \
                                FS_Close(p_file); \
                            }

#if GTP_HOTKNOT_MODULE

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
#endif
#if 1
kal_uint8 mtk_hotknot_apk_data[] = {\

		0x00,//for hotknot header in smart phone
		'H',//hotknot header
		'N',
		0x00,
		0x2e,
		0x11,//TLV: AND
		0x22,
		'a',
		'p',
		'p',
		'l',
		'i',
		'c',
		'a',
		't',
		'i',
		'o',
		'n',
		'/',
		'c',
		'o',
		'm',
		'.',
		'm',
		't',
		'k',
		'.',
		'b',
		't',
		'n',
		'o',
		't',
		'i',
		'f',
		'i',
		'c',
		'a',
		't',
		'i',
		'o',
		'n'
	};
#endif
kal_uint8 hotknot_data[64] = {0};

kal_uint8 test_lenth;

#define HOTKNOT_PERIOD 50
#define HOTKNOT_REENTER_MASTER_TIME 400	//about 2s
#endif

void ctp_set_gpio(char data,char port)
{
    DCL_HANDLE handle;
	handle = DclGPIO_Open(DCL_GPIO,port);
	DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, NULL);
	DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, NULL);
	DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, NULL);
	DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, NULL);
	if(!data)
	{
		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
	}
	else
	{
		DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
	}
	DclGPIO_Close(handle);
}

void ctp_set_gpio2eint(char port)
{
    DCL_HANDLE handle;
	handle = DclGPIO_Open(DCL_GPIO,port);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, NULL);
	DclGPIO_Control(handle, GPIO_CMD_SET_MODE_2, NULL);
	DclGPIO_Close(handle);

}

#if GTP_HOTKNOT_MODULE
kal_timerid hotknot_timerid;
//kal_timerid hotknot_readback_timerid;
#define CALIBRATION_HEADER_LEN 14


void TP_MmiSendilm(module_type dest_id, msg_type msg_id, local_para_struct *data, sap_type sap_id)
{
	ilm_struct *ilm;
	DRV_SendPrimitive(ilm,
					MOD_AUX,
					dest_id,
					msg_id,
					data,
					sap_id);
	msg_send_ext_queue(ilm);
}

//extern kal_uint32 gup_load_calibration1(void);
//extern kal_uint32  gup_recovery_calibration0(void);
//hotknot function
kal_uint8 calculate_check_sum(kal_uint8* data,kal_uint8 len)
{
	kal_uint8 checkesum = 0;
	kal_uint8 i = 0;
	
	for(i = 0; i < len; i++)
	{
		checkesum += data[i];
	}
	//DEBUG("%d calculate the cksum is 0x%x,0-cksum is 0x%x",len,checkesum,0-checkesum);

	return (0 - checkesum);
}

kal_bool gtp_hotknot_send(kal_uint8 *data, kal_uint8 length)
{
	kal_uint8 buffer[256];
	kal_uint8 sendFlag[4];
	kal_uint8 ret = 0;
	kal_uint8 retry = 0;
	kal_uint8 idleTimes = 0;
	
	buffer[0] = length;
    memcpy(&buffer[1], data, length);
	buffer[length + 1] = calculate_check_sum(buffer,length + 1);//checksum
	
	while(retry++ < 5)
	{
        //Writes data to the 0xAC90
        ret = CTP_I2C_send(REG_SNDBUF_START, buffer, length + 2);
        if(ret == 0)
        {
        	kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# IIC write to 0xAC90 error.");
            continue;
        }
        sendFlag[0] = 0xAA;
        ret = CTP_I2C_send(REG_DATA_FRESH, sendFlag, 1);
        if(ret == 0)
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# IIC write to 0xAD91 error.");
            continue;
        }
        break;
    }
    
    if(retry >= 5)
    {
        kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# Time out error");
        return KAL_FALSE;
    }
  
    //polling 0xAB10 send state is 0x03,send success
    while(1)
    {
        if(idleTimes>200)
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# Wait send flag[0xAB10] timeout error.");
            return KAL_FALSE;
        }
        ret = CTP_I2C_read(REG_XFE_STATE, sendFlag, 4);
        if(ret == 0)
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# IIC read from 0xAB10 error.");
            idleTimes ++;
            //delay_ms(40);
            continue;
        }
        if(sendFlag[1] != sendFlag[3] || sendFlag[0] != sendFlag[2])
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# Flag not match[0xAB10~0xAB13]:0x%02x,0x%02x,0x%02x,0x%02x"
                 ,sendFlag[0],sendFlag[1],sendFlag[2],sendFlag[3]);
            CTP_I2C_read(0x81B0, sendFlag, 2);
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# [0x81B0]=0x%02x,[0x81B1]=0x%02x", sendFlag[0], sendFlag[1]);
            idleTimes ++;
            //delay_ms(40);
            continue;
        } 
        kal_prompt_trace(MOD_TP_TASK,"Pending: send_data# Snd state[0xAB10]=0x%02x,Retries=%d", sendFlag[0], idleTimes);
        switch(sendFlag[0])
        { 
        case 0x01:
        case 0x02:
        case 0x05:
            idleTimes++;            
            break;
        case 0x03:
            CTP_I2C_send(REG_NOTIFY_STATE, sendFlag, 1);
            return KAL_TRUE;
        case 0x04:
            kal_prompt_trace(MOD_TP_TASK,"Pending: Chip request re_send_data.");
            ret = CTP_I2C_send(REG_SNDBUF_START, buffer, length + 2);
            if(ret == 0)
            {
                kal_prompt_trace(MOD_TP_TASK,"Fail: re_send_data# IIC write to 0xAC90 error.");
                continue;
            }
            sendFlag[0] = 0xAA;
            ret = CTP_I2C_send(REG_DATA_FRESH, sendFlag, 1);
            if(ret == 0)
            {
                kal_prompt_trace(MOD_TP_TASK,"Fail: re_send_data# IIC write to 0xAC90 error.");
            }
            break;
        case 7:
        	return KAL_FALSE;
        default:
            kal_prompt_trace(MOD_TP_TASK,"Fail: send_data# Unknown state read from 0xAB10");
            idleTimes++;
            break;
        } 
        delay_ms(4);
    }
	return KAL_FALSE;
}


kal_bool gtp_hotknot_enter_master()
{
    kal_uint8 ret = KAL_FALSE;
    kal_uint8  buf[1] = {CMD_ENTER_MASTER};
	kal_uint8 modeBuf[2];
    kal_uint8  retry = 0;
    
    while(retry++ < 10)
    {
        if (!CTP_I2C_send(REG_1ST_CMD, buf, 1))
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: Send 1st cmd error");
            continue;
        }
		if (!CTP_I2C_send(REG_2ND_CMD, buf, 1))
        {
           kal_prompt_trace(MOD_TP_TASK,"Fail: Send 2nd cmd error");
            continue;
        }
        delay_ms(40);
        ret = CTP_I2C_read(REG_LINK_MODE, modeBuf, 2);
        if (ret < 0)
        {
            kal_prompt_trace(MOD_TP_TASK,"Fail: IIC read error.");
            continue;
        }
        if (modeBuf[0] == MODE_MASTER && modeBuf[0]==modeBuf[1])        
        {
            return KAL_TRUE;
        }
        kal_prompt_trace(MOD_TP_TASK,"Fail: exit_master_mode# [0x81B0]=0x%02x,[0x81B1]=0x%02x", modeBuf[0], modeBuf[1]);
    }
    return KAL_FALSE;
}

#if 1
void combination_of_hotknotdata(void)
{
	kal_uint8 temp_data[6]={NULL};
	kal_uint8 temp_lenth;
	kal_uint8 i;
	srv_bt_cm_dev_struct* dev_info;
    srv_bt_cm_bt_addr *bd_addr_p = NULL;
	unsigned int* p_mmi_symblo_addr = NULL;
	//srv_bt_cm_cntx_struct bt_mac_temp;
	//memcpy(hotknot_data,mtk_hotknot_apk_data,sizeof(mtk_hotknot_apk_data));
	for(i = 0; i <= sizeof(mtk_hotknot_apk_data); i++)
	{
		hotknot_data[i] = mtk_hotknot_apk_data[i];
	}
	temp_lenth = sizeof(mtk_hotknot_apk_data);
	kal_prompt_trace(MOD_TP_TASK,"sizeof(mtk_hotknot_apk_data) = %d",temp_lenth);
	//MtkBt_Get_BT_LE_ADDR(temp_data);
	//for(i = temp_lenth; i < (temp_lenth + sizeof(temp_data)); i++ )
	//{
	//	hotknot_data[i] = temp_data[i-temp_lenth];
	//	kal_prompt_trace(MOD_TP_TASK,"BLE MAC byte[i]:0x%x",hotknot_data[i]);
	//}
	//memcpy(hotknot_data[37],temp_data,sizeof(temp_data));
	//memcpy(hotknot_data[43],0x02,1);
	//memcpy(hotknot_data[44],0x20,1);
	//memcpy(hotknot_data[45],0x06,1);
	//hotknot_data[42] = 0x02;
	//hotknot_data[43] = 0x20;
	//hotknot_data[44] = 0x06;
#ifdef __UPDATE_BINARY_FILE__
	p_mmi_symblo_addr = (unsigned int*)(custom_get_UPDATE_ROM_entry()
		+ UBIN_SYMBOL_UBIN_GET_BT_ADDRESS * sizeof(void *));
	dev_info = ((srv_bt_cm_dev_struct* (*)(void))(*p_mmi_symblo_addr))();//srv_bt_cm_get_host_dev_info();
    bd_addr_p = &(dev_info->bd_addr);
#else
	dev_info = srv_bt_cm_get_host_dev_info();
    bd_addr_p = &(dev_info->bd_addr);
#endif	
	hotknot_data[temp_lenth++] = ((bd_addr_p->nap & 0xff00) >> 8);
	kal_prompt_trace(MOD_TP_TASK,"BT_address1 %x",hotknot_data[temp_lenth - 1]);
	hotknot_data[temp_lenth++] = (bd_addr_p->nap & 0x00ff);
	kal_prompt_trace(MOD_TP_TASK,"BT_address2 %x",hotknot_data[temp_lenth - 1]);
	hotknot_data[temp_lenth++] = bd_addr_p->uap;
	kal_prompt_trace(MOD_TP_TASK,"BT_address3 %x",hotknot_data[temp_lenth - 1]);
	hotknot_data[temp_lenth++] = ((bd_addr_p->lap & 0xff0000) >> 16);
	kal_prompt_trace(MOD_TP_TASK,"BT_address4 %x",hotknot_data[temp_lenth - 1]);
	hotknot_data[temp_lenth++] = ((bd_addr_p->lap & 0x00ff00) >> 8);
	kal_prompt_trace(MOD_TP_TASK,"BT_address5 %x",hotknot_data[temp_lenth - 1]);
	hotknot_data[temp_lenth++] = ((bd_addr_p->lap & 0x0000ff));
	kal_prompt_trace(MOD_TP_TASK,"BT_address6 %x",hotknot_data[temp_lenth - 1]);
	//for(i = 45; i < 51; i++ )
	//{
	//	kal_prompt_trace(MOD_TP_TASK,"BT MAC byte[i]:0x%x",hotknot_data[i]);
	//}
	//hotknot_data[46] = g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.nap;
	//hotknot_data[48] = g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.uap;
	//hotknot_data[49] = g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.lap;
	//memcpy(hotknot_data[46],g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.nap,sizeof(g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.nap));
	//temp_lenth += sizeof(g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.lap);
	//memcpy(hotknot_data[48],g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.uap,sizeof(g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.uap));
	//temp_lenth += sizeof(g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.uap);
	//memcpy(hotknot_data[49],g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.lap,sizeof(g_srv_bt_cm_cntx.dev_list.dev_info.bd_addr.nap));
	//memcpy(hotknot_data[0],(0x80 + 50),1);
	hotknot_data[0] = 0x80 + temp_lenth - 1;
	for(i = temp_lenth; i < 64; i++)
	{
		hotknot_data[i] = 0x00;
	}
	
	for(i = 0; i < 64; i++)
	{
		kal_prompt_trace(MOD_TP_TASK,"hotknot data[%d] = 0x%x",i,hotknot_data[i]);
	}
	//memcpy(hotknot_data[55],0x00,13);
}
#endif
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
#endif
extern void ctp_update_firmware_enable_wdt(kal_bool enable);

kal_bool is_hotknot_pair = KAL_FALSE;
kal_timerid hotknot_query_status;
kal_timerid hotknot_recovery_status;

HOTKNOT_STATUS_T hotknot_status = HOTKNOT_STATUS_NORMAL;

void modify_hotknot_status(HOTKNOT_STATUS_T set_status)
{
	kal_prompt_trace(MOD_TP_TASK,"modify_hotknot_status = %d",set_status);
	hotknot_status = set_status;
}

void hotknot_recovery_back_to_master(void)
{
	kal_prompt_trace(MOD_TP_TASK,"hotknot_recovery_back_to_master");
	gtp_hotknot_enter_master();
	kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)Hotknot_polling_cb, NULL, HOTKNOT_PERIOD, 0);
	hotknot_status = HOTKNOT_STATUS_NORMAL;
}

void hotknot_recovery(void)
{
	if(hotknot_status == HOTKNOT_LCD_ON_AGAIN_STATUS)
	{
		kal_prompt_trace(MOD_TP_TASK,"hotknot_recovery = %d",hotknot_status);
		//delay_ms(20);//kal_sleep_task(20);
		//CTP_I2C_read(REG_LINK_MODE,buff_test,2);
		kal_cancel_timer(hotknot_recovery_status);
		gup_recovery_calibration0();
		//delay_ms(20);
		//gtp_hotknot_enter_master();
		//EINT_UnMask(TOUCH_PANEL_EINT_NO);
		//ctp_set_gpio2eint(TOUCH_PANEL_EINT_NO);
		//ctp_update_firmware_enable_wdt(KAL_TRUE);
		kal_prompt_trace(MOD_TP_TASK,"reset timer_in hotknot_recovery!");
		kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)hotknot_recovery_back_to_master, NULL, HOTKNOT_REENTER_MASTER_TIME, 0);
		hotknot_status = HOTKNOT_STATUS_NORMAL;
		is_hotknot_pair = KAL_FALSE;
		
		kal_prompt_trace(MOD_TP_TASK,"is_hotknot_pair reset = %d",is_hotknot_pair);
		//EINT_UnMask(TOUCH_PANEL_EINT_NO);
	}
	else
	{
		kal_prompt_trace(MOD_TP_TASK,"hotknot_recovery else = %d",hotknot_status);
		kal_set_timer(hotknot_recovery_status,(kal_timer_func_ptr)hotknot_recovery, NULL, HOTKNOT_PERIOD, 0);
	}
}

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
#endif

void hotknot_upload_frm_send(void)
{
static kal_uint16 retry_times;
	if(hotknot_status == HOTKNOT_LCD_OFF_STATUS)
	{
		retry_times++;
		//EINT_Mask(TOUCH_PANEL_EINT_NO);
		kal_prompt_trace(MOD_TP_TASK,"upload_frm = %d",hotknot_status);
		kal_cancel_timer(hotknot_timerid);
		kal_cancel_timer(hotknot_query_status);
		/*bellow is for firmware update*/
		//gup_update_proc(NULL);
		/*bellow is for hotknot*/
		gup_load_calibration1();
		//CTP_I2C_read(0x8140,buff_test,10);
		delay_ms(100);//kal_sleep_task(100);
		//CTP_I2C_read(REG_LINK_MODE,buff_test,2);
		//kal_prompt_trace(MOD_TP_TASK,"Hotknot_REG_LINK_MODE = %d,%d!",buf[0],buf[1]);
		//test_lenth = gtp_load_hoknot_data(test_data);
		//kal_prompt_trace(MOD_TP_TASK,"gtp_load_hoknot_data lenth = %d",test_lenth);
		//if(test_lenth > 0)
		gtp_hotknot_send(hotknot_data, sizeof(hotknot_data));
		
		TP_MmiSendilm(MOD_MMI,MSG_ID_TOUCH_HOTKNOT_SEND_DONE,NULL,NULL);
		kal_set_timer(hotknot_recovery_status,(kal_timer_func_ptr)hotknot_recovery, NULL, HOTKNOT_PERIOD, 0);
		//if(retry_times > 5)
		//{
		//	retry_times = 0;
		//	hotknot_status = HOTKNOT_LCD_ON_AGAIN_STATUS;
		//	return;
		//}
	}
	else
	{
		kal_prompt_trace(MOD_TP_TASK,"upload_frm else = %d",hotknot_status);
		kal_set_timer(hotknot_query_status,(kal_timer_func_ptr)hotknot_upload_frm_send, NULL, HOTKNOT_PERIOD, 0);
	}
}
//#define HK_CATCHE_NOISE
#ifdef HK_CATCHE_NOISE
extern kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level );

kal_uint8 hotknot_buffer[300][16] = {0};

void hotknot_print_reg_info(void)
{
	kal_uint16 i,j;
	for(i = 0; i<300; i++)
	{
		for(j = 0; j < 16; j++)
		{
			kal_prompt_trace(MOD_TP_TASK,"HK read back REG[%d][%d]=0x%x",i,j,hotknot_buffer[i][j]);
		}
		kal_prompt_trace(MOD_TP_TASK,"===================================");
	}
}


void hotknot_catch_reg_info(void)
{
	kal_uint16 start_addr = 0xCB3F;
	kal_uint16 end_addr = 0xCB4E;
	kal_uint16 cur_addr;
	kal_uint16 loop = 300;
	kal_uint8 result;
	kal_uint16 i;
	ctp_update_firmware_enable_wdt(KAL_FALSE);
	//force_lcd_sleep_in(1);
	//custom_cfg_gpio_set_level(0,0);
	delay_ms(1000);
	while(loop--)
	{
		i = 0;
		for(cur_addr = start_addr; cur_addr <= end_addr; cur_addr++)
		{
			CTP_I2C_read(cur_addr,&result,1);
			hotknot_buffer[loop][i] = result;
			i++;
		}
	}
	//delay_ms(1000);
	//lcd_sleep_out(1);
	//custom_cfg_gpio_set_level(0,5);
	//delay_ms(10000);
	
	hotknot_print_reg_info();
	ctp_update_firmware_enable_wdt(KAL_TRUE);
}
#endif

extern	kal_bool custom_cfg_gpio_set_level(kal_uint8 gpio_dev_type, kal_uint8 gpio_dev_level );
void Hotknot_polling_cb(void)
{
	kal_uint8 ret;
	kal_uint8 buf[2];
	kal_uint8 bt_nap[2];
	kal_uint8 bt_uap[1];
	kal_uint8 bt_lap[3];

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

#ifdef HK_CATCHE_NOISE
	hotknot_catch_reg_info();
	return;
#endif
	//for debug
    ret = CTP_I2C_read(REG_LINK_MODE, buf, 2);
    kal_prompt_trace(MOD_TP_TASK,"[0x81B0]=0x%02x,[0x81B1]=0x%02x", buf[0], buf[1]);
	
	ret = CTP_I2C_read(REG_PAIR_FLAG, buf, 2);	
	kal_prompt_trace(MOD_TP_TASK,"Hotknot_polling_cb REG_PAIR_FLAG = %d,%d!",buf[0],buf[1]);

		kal_cancel_timer(hotknot_timerid);
		if(buf[0] == buf[1] && buf[0] == MODE_PAIRED)
		{
			//ctp_update_firmware_enable_wdt(KAL_FALSE);
			//ctp_set_gpio(NULL,TOUCH_PANEL_EINT_NO);
			//EINT_Mask(TOUCH_PANEL_EINT_NO);
			is_hotknot_pair = KAL_TRUE;
			kal_prompt_trace(MOD_TP_TASK,"is_hotknot_pair set = %d",is_hotknot_pair);
			TP_MmiSendilm(MOD_MMI,MSG_ID_TOUCH_HOTKNOT_APPROACH,NULL,NULL);
			//custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, 0);
			combination_of_hotknotdata();
			kal_prompt_trace(MOD_TP_TASK,"Pair successfully!");
			kal_set_timer(hotknot_query_status,(kal_timer_func_ptr)hotknot_upload_frm_send, NULL, HOTKNOT_PERIOD, 0);
		}
		else
		{
			kal_prompt_trace(MOD_TP_TASK,"reset timer_in hotknot_CB!");
			kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)Hotknot_polling_cb, NULL, HOTKNOT_PERIOD, 0);
		}
}

void touch_hotknot_init(void)
{
	if(hotknot_timerid == NULL)
	{
		hotknot_timerid = kal_create_timer("hotknot");
	}
	if(hotknot_query_status == NULL)
	{
		hotknot_query_status = kal_create_timer("hotknot_query_status");
	}
	if(hotknot_recovery_status == NULL)
	{
		hotknot_recovery_status = kal_create_timer("hotknot_recovery_status"); 
	}
}

kal_bool tp_hotknot_enable_menu = KAL_FALSE;
static kal_bool tp_hotknot_ready = KAL_FALSE;
kal_bool tp_hotknot_enable(void)
{
	kal_prompt_trace(MOD_TP_TASK,"tp_hotknot_enable tp_hotknot_enable_menu = %d",tp_hotknot_enable_menu);
	kal_prompt_trace(MOD_TP_TASK,"tp_hotknot_enable tp_hotknot_ready = %d",tp_hotknot_ready);
	if(tp_hotknot_enable_menu)
	{
		if(!tp_hotknot_ready)
		{
			tp_hotknot_ready = KAL_TRUE;
			//gtp_hotknot_enter_master();
			
			//hotknot function
			kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)tp_hotknot_start_polling, NULL,  100, 0);
		}
	}
}

void tp_hotknot_start_polling(void)
{
	gtp_hotknot_enter_master();
	kal_set_timer(hotknot_timerid,(kal_timer_func_ptr)Hotknot_polling_cb, NULL,  HOTKNOT_PERIOD, 0);
}


kal_bool tp_hotknot_disable(void)
{
	kal_uint8 reg = HN_COMMAND_EXIT_MASTER;
	kal_prompt_trace(MOD_TP_TASK,"tp_hotknot_disable tp_hotknot_enable_menu = %d",tp_hotknot_enable_menu);
	//if(!tp_hotknot_enable_menu)
	//{
	CTP_I2C_send(HN_REG_COMMAND_CHECK,&reg,1);
	CTP_I2C_send(HN_REG_COMMAND,&reg,1);
		kal_cancel_timer(hotknot_timerid);
		tp_hotknot_ready = KAL_FALSE;
	//}
}

kal_bool touch_panel_hotknot_enable(void)
{
		tp_hotknot_enable_menu = KAL_TRUE;
		tp_hotknot_enable();	
}

kal_bool touch_panel_hotknot_disable(void)
{
		tp_hotknot_enable_menu = KAL_FALSE;
		tp_hotknot_disable();	
}
#endif

static u8 gup_burn_fw_app_section(struct i2c_client *client, u8 *fw_section, u16 start_addr, u32 len, u8 bank_cmd );

static s32 gup_i2c_read(struct i2c_client *client, u8 *buf, s32 len)
{
    s32 ret = -1;
    u16 addr = (buf[0] << 8) + buf[1];

    return CTP_I2C_read(addr, &buf[2], len - 2);
}

static s32 gup_i2c_write(struct i2c_client *client, u8 *buf, s32 len)
{
    s32 ret = 0;
    u16 addr = (buf[0] << 8) + buf[1];

    return CTP_I2C_send(addr, &buf[2], len - 2);
}
static s32 gtp_i2c_read_dbl_check(struct i2c_client *client, u16 addr, u8 *rxbuf, s32 len)
{
    u8 buf[16] = {0};
    u8 confirm_buf[16] = {0};
    u8 retry = 0;
    
    while (retry++ < 3)
    {
        memset(buf, 0xAA, 16);
        buf[0] = (u8)(addr >> 8);
        buf[1] = (u8)(addr & 0xFF);
        gup_i2c_read(client, buf, len + 2);
        
        memset(confirm_buf, 0xAB, 16);
        confirm_buf[0] = (u8)(addr >> 8);
        confirm_buf[1] = (u8)(addr & 0xFF);
        gup_i2c_read(client, confirm_buf, len + 2);
        
        if (!memcmp(buf, confirm_buf, len+2))
        {
            memcpy(rxbuf, confirm_buf+2, len);
            return SUCCESS;
        }
    }    
    GTP_ERROR("i2c read 0x%04X, %d bytes, double check failed!", addr, len);
    return FAIL;
}

static u8 gup_get_ic_msg(struct i2c_client *client, u16 addr, u8 *msg, s32 len)
{
    s32 i = 0;

    msg[0] = (addr >> 8) & 0xff;
    msg[1] = addr & 0xff;

    for (i = 0; i < 5; i++)
    {
        if (gup_i2c_read(client, msg, GTP_ADDR_LENGTH + len) > 0)
        {
            break;
        }
    }

    if (i >= 5)
    {
        GTP_ERROR("Read data from 0x%02x%02x failed!", msg[0], msg[1]);
        return FAIL;
    }

    return SUCCESS;
}

static u8 gup_set_ic_msg(struct i2c_client *client, u16 addr, u8 val)
{
    s32 i = 0;
    u8 msg[3];

    msg[0] = (addr >> 8) & 0xff;
    msg[1] = addr & 0xff;
    msg[2] = val; 
 
    for (i = 0; i < 5; i++)
    {
        if (gup_i2c_write(client, msg, GTP_ADDR_LENGTH + 1) > 0)
        {
            break;
        }
    }

    if (i >= 5)
    {
        GTP_ERROR("Set data to 0x%02x%02x failed!", msg[0], msg[1]);
        return FAIL;
    }

    return SUCCESS;
}

void gtp_int_sync(s32 ms)
{
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
    msleep(ms);
    GTP_GPIO_AS_INT(GTP_INT_PORT);
}

void gtp_reset_guitar(struct i2c_client *client, s32 ms)
{
    GTP_INFO("GTP RESET!\n");
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    msleep(ms);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);//client->addr == 0x14);

    msleep(2);
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 1);

    msleep(6);                      //must >= 6ms

#if GTP_COMPATIBLE_MODE
    if (CHIP_TYPE_GT9F == gtp_chip_type)
    {
        return;
    }
#endif

    gtp_int_sync(50);  // for dbl-system
#if GTP_ESD_PROTECT
    gtp_init_ext_watchdog(i2c_client_point);
#endif
}



#if 1  // GTP_UPDATE
static u8 gup_get_ic_fw_msg(struct i2c_client *client)
{
    s32 ret = -1;
    u8  retry = 0;
    u8  buf[16];
    u8  i;

    //step1:get hardware info
    ret = gtp_i2c_read_dbl_check(client, GUP_REG_HW_INFO, &buf[GTP_ADDR_LENGTH], 4);
    if (FAIL == ret)
    {
        GTP_ERROR("[get_ic_fw_msg]get hw_info failed,exit");
        return FAIL;
    }

    // buf[2~5]: 00 06 90 00
    // hw_info: 00 90 06 00
    for (i = 0; i < 4; i++)
    {
        update_msg.ic_fw_msg.hw_info[i] = buf[GTP_ADDR_LENGTH + 3 - i];
    }

    GTP_INFO("IC Hardware info:%02x%02x%02x%02x", update_msg.ic_fw_msg.hw_info[0], update_msg.ic_fw_msg.hw_info[1],
             update_msg.ic_fw_msg.hw_info[2], update_msg.ic_fw_msg.hw_info[3]);

    //step2:get firmware message
    for (retry = 0; retry < 2; retry++)
    {
        ret = gup_get_ic_msg(client, GUP_REG_FW_MSG, buf, 1);

        if (FAIL == ret)
        {
            GTP_ERROR("Read firmware message fail.");
            return ret;
        }

        update_msg.force_update = buf[GTP_ADDR_LENGTH];

        if ((0xBE != update_msg.force_update) && (!retry))
        {
            GTP_INFO("The check sum in ic is error.");
            GTP_INFO("The IC will be updated by force.");
            continue;
        }
        break;
    }

    GTP_INFO("IC force update flag:0x%x", update_msg.force_update);

    //step3:get pid & vid
    ret = gtp_i2c_read_dbl_check(client, GUP_REG_PID_VID, &buf[GTP_ADDR_LENGTH], 6);
    if (FAIL == ret)
    {
        GTP_ERROR("[get_ic_fw_msg]get pid & vid failed,exit");
        return FAIL;
    }

    memset(update_msg.ic_fw_msg.pid, 0, sizeof(update_msg.ic_fw_msg.pid));
    memcpy(update_msg.ic_fw_msg.pid, &buf[GTP_ADDR_LENGTH], 4);


    //GT9XX PID MAPPING
    /*|-----FLASH-----RAM-----|
      |------918------918-----|
      |------968------968-----|
      |------913------913-----|
      |------913P-----913P----|
      |------927------927-----|
      |------927P-----927P----|
      |------9110-----9110----|
      |------9110P----9111----|*/
    if(update_msg.ic_fw_msg.pid[0] != 0)
    {
        if (!memcmp(update_msg.ic_fw_msg.pid, "9111", 4))
        {
            GTP_INFO("IC Mapping Product id:%s", update_msg.ic_fw_msg.pid);
            memcpy(update_msg.ic_fw_msg.pid, "9110P", 5);
        }
    }

    update_msg.ic_fw_msg.vid = buf[GTP_ADDR_LENGTH + 4] + (buf[GTP_ADDR_LENGTH + 5] << 8);
    return SUCCESS;
}

s32 gup_enter_update_mode(struct i2c_client *client)
{
    s32 ret = -1;
    s32 retry = 0;
    u8 rd_buf[3];
    
    //step1:RST output low last at least 2ms
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    msleep(2);
    
    //step2:select I2C slave addr,INT:0--0xBA;1--0x28.
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);//(client->addr == 0x14));
    msleep(2);
    
    //step3:RST output high reset guitar
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 1);
    
    //20121211 modify start
    msleep(5);
    while(retry++ < 200)
    {
        //step4:Hold ss51 & dsp
        ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);
        if(ret <= 0)
        {
            GTP_DEBUG("Hold ss51 & dsp I2C error,retry:%d", retry);
            continue;
        }
        
        //step5:Confirm hold
        ret = gup_get_ic_msg(client, _rRW_MISCTL__SWRST_B0_, rd_buf, 1);
        if(ret <= 0)
        {
            GTP_DEBUG("Hold ss51 & dsp I2C error,retry:%d", retry);
            continue;
        }
        if(0x0C == rd_buf[GTP_ADDR_LENGTH])
        {
            GTP_DEBUG("Hold ss51 & dsp confirm SUCCESS");
            break;
        }
        GTP_DEBUG("Hold ss51 & dsp confirm 0x4180 failed,value:%d", rd_buf[GTP_ADDR_LENGTH]);
    }
    if(retry >= 200)
    {
        GTP_ERROR("Enter update Hold ss51 failed.");
        return FAIL;
    }
    
    //step6:DSP_CK and DSP_ALU_CK PowerOn
    ret = gup_set_ic_msg(client, 0x4010, 0x00);
    
    //20121211 modify end
    return ret;
}

void gup_leave_update_mode(void)
{
    GTP_GPIO_AS_INT(GTP_INT_PORT);
    
    GTP_DEBUG("[leave_update_mode]reset chip.");
#if GTP_COMPATIBLE_MODE
    if (CHIP_TYPE_GT9F == gtp_chip_type)
    {
        force_reset_guitar();
        GTP_INFO("User layer reset GT9XXF.");
        return;
    }
#endif
    gtp_reset_guitar(i2c_client_point, 5);
}

static u8 gup_enter_update_judge(st_fw_head *fw_head)
{
    u16 u16_tmp;
    s32 i = 0;
    u32 fw_len = 0;
    s32 pid_cmp_len = 0;
    //Get the correct nvram data
    //The correct conditions:
    //1. the hardware info is the same
    //2. the product id is the same
    //3. the firmware version in update file is greater than the firmware version in ic
    //or the check sum in ic is wrong

    u16_tmp = fw_head->vid;
    fw_head->vid = (u16)(u16_tmp >> 8) + (u16)(u16_tmp << 8);

    GTP_INFO("FILE HARDWARE INFO:%02x%02x%02x%02x", fw_head->hw_info[0], fw_head->hw_info[1], fw_head->hw_info[2], fw_head->hw_info[3]);
    GTP_INFO("FILE PID:%s", fw_head->pid);
    GTP_INFO("FILE VID:%04x", fw_head->vid);
    GTP_INFO("IC HARDWARE INFO:%02x%02x%02x%02x", update_msg.ic_fw_msg.hw_info[0], update_msg.ic_fw_msg.hw_info[1],
             update_msg.ic_fw_msg.hw_info[2], update_msg.ic_fw_msg.hw_info[3]);
    GTP_INFO("IC PID:%s", update_msg.ic_fw_msg.pid);
    GTP_INFO("IC VID:%04x", update_msg.ic_fw_msg.vid);
    
    if (!memcmp(fw_head->hw_info, update_msg.ic_fw_msg.hw_info, sizeof(update_msg.ic_fw_msg.hw_info)))
    {
        fw_len = 42 * 1024;
    }
    else
    {
        fw_len = fw_head->hw_info[3];
        fw_len += (((u32)fw_head->hw_info[2]) << 8);
        fw_len += (((u32)fw_head->hw_info[1]) << 16);
        fw_len += (((u32)fw_head->hw_info[0]) << 24);
    }
    if (update_msg.fw_total_len != fw_len)
    {
        GTP_ERROR("Inconsistent firmware size, Update aborted! Default size: %d(%dK), actual size: %d(%dK)", fw_len, fw_len/1024, update_msg.fw_total_len, update_msg.fw_total_len/1024);
        return FAIL;
    }
    if ((update_msg.fw_total_len < 36*1024) || (update_msg.fw_total_len > 128*1024))
    {
        GTP_ERROR("Invalid firmware length(%d), update aborted!", update_msg.fw_total_len);
        return FAIL;
    }
    GTP_INFO("Firmware length:%d(%dK)", update_msg.fw_total_len, update_msg.fw_total_len/1024);
    
    if (update_msg.force_update != 0xBE)
    {
        GTP_INFO("FW chksum error,need enter update.");
        return SUCCESS;
    }

    // 20130523 start
    if (strlen(update_msg.ic_fw_msg.pid) < 3)
    {
        GTP_INFO("Illegal IC pid, need enter update");
        return SUCCESS;
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            if ((update_msg.ic_fw_msg.pid[i] < 0x30) || (update_msg.ic_fw_msg.pid[i] > 0x39))
            {
                GTP_INFO("Illegal IC pid, out of bound, need enter update");
                return SUCCESS;
            }
        }
    }
    // 20130523 end
    
    pid_cmp_len = strlen(fw_head->pid);
    if (pid_cmp_len < strlen(update_msg.ic_fw_msg.pid))
    {
        pid_cmp_len = strlen(update_msg.ic_fw_msg.pid);
    }
    
    if ((!memcmp(fw_head->pid, update_msg.ic_fw_msg.pid, pid_cmp_len)) ||
            (!memcmp(update_msg.ic_fw_msg.pid, "91XX", 4))||
            (!memcmp(fw_head->pid, "91XX", 4)))
    {
        if(!memcmp(fw_head->pid, "91XX", 4))
        {
            GTP_DEBUG("Force none same pid update mode.");
        }
        else
        {
            GTP_DEBUG("Get the same pid.");
        }

        //The third condition
        if (fw_head->vid > update_msg.ic_fw_msg.vid)
        {

            GTP_INFO("Need enter update.");
            return SUCCESS;
        }

        GTP_INFO("Don't meet the third condition.");
        GTP_ERROR("File VID <= IC VID, update aborted!");
    }
    else
    {
        GTP_ERROR("File PID != IC PID, update aborted!");
    }

    return FAIL;
}

#if GTP_AUTO_UPDATE_CFG
static u8 ascii2hex(u8 a)
{
    u8 value = 0;

    if(a >= '0' && a <= '9')
    {
        value = a - '0';
    }
    else if(a >= 'A' && a <= 'F')
    {
        value = a - 'A' + 0x0A;
    }
    else if(a >= 'a' && a <= 'f')
    {
        value = a - 'a' + 0x0A;
    }
    else
    {
        value = 0xff;
    }
    
    return value;
}

static s32 gup_update_config(struct i2c_client *client)
{
    s32 file_len = 0;
    s32 ret = 0;
    s32 i = 0;
    s32 file_cfg_len = 0;
    s32 chip_cfg_len = 0;
    s32 count = 0;
    u8 *buf;
    u8 *pre_buf;
    u8 *file_config;
    //u8 checksum = 0;
    s32 rLen = 0;
    
    if(NULL == update_msg.cfg_file)
    {
        GTP_ERROR("[update_cfg]No need to upgrade config!");
        return FAIL;
    }
    file_len = FS_Seek(update_msg.cfg_file, 0, SEEK_END);
    
    chip_cfg_len = cfg_len;
    
    GTP_DEBUG("[update_cfg]config file len:%d", file_len);
    GTP_DEBUG("[update_cfg]need config len:%d",chip_cfg_len);
    if((file_len+5) < chip_cfg_len*5)
    {
        GTP_ERROR("Config length error");
        return -1;
    }
    
    buf = (u8*)kzalloc(5*1024, GFP_KERNEL);//(u8*)kzalloc(file_len, GFP_KERNEL);
    pre_buf = &buf[2048];//(u8*)kzalloc(file_len, GFP_KERNEL);
    file_config = &buf[4096];//(u8*)kzalloc(chip_cfg_len + GTP_ADDR_LENGTH, GFP_KERNEL);
    FS_Seek(update_msg.cfg_file, 0, SEEK_SET);
    
    GTP_DEBUG("[update_cfg]Read config from file.");
    ret = FS_Read(update_msg.cfg_file, (char*)pre_buf, file_len, &rLen);
    if(ret<0 || rLen != file_len)
    {
        GTP_ERROR("[update_cfg]Read config file failed.");
        goto update_cfg_file_failed;
    }
    
    GTP_DEBUG("[update_cfg]Delete illgal charactor.");
    for(i=0,count=0; i<file_len; i++)
    {
        if (pre_buf[i] == ' ' || pre_buf[i] == '\r' || pre_buf[i] == '\n')
        {
            continue;
        }
        buf[count++] = pre_buf[i];
    }
    
    GTP_DEBUG("[update_cfg]Ascii to hex.");
    file_config[0] = CTP_CONFIG_REG_BASE>> 8;
    file_config[1] = CTP_CONFIG_REG_BASE & 0xff;
    for(i=0,file_cfg_len=GTP_ADDR_LENGTH; i<count; i+=5)
    {
        if((buf[i]=='0') && ((buf[i+1]=='x') || (buf[i+1]=='X')))
        {
            u8 high,low;
            high = ascii2hex(buf[i+2]);
            low = ascii2hex(buf[i+3]);
            
            if((high == 0xFF) || (low == 0xFF))
            {
                ret = 0;
                GTP_ERROR("[update_cfg]Illegal config file.");
                goto update_cfg_file_failed;
            }
            file_config[file_cfg_len++] = (high<<4) + low;
        }
        else
        {
            ret = 0;
            GTP_ERROR("[update_cfg]Illegal config file.");
            goto update_cfg_file_failed;
        }
    }
    
    
    GTP_DEBUG("config:");
    GTP_DEBUG_ARRAY(file_config+2, file_cfg_len);
    
    i = 0;
    while(i++ < 5)
    {
        ret = gup_i2c_write(client, file_config, file_cfg_len);
        if(ret > 0)
        {
            GTP_INFO("[update_cfg]Send config SUCCESS.");
            break;
        }
        GTP_ERROR("[update_cfg]Send config i2c error.");
    }
    
update_cfg_file_failed:
    //kfree(pre_buf);
    kfree(buf);
    //kfree(file_config);
    return ret;
}
#endif

#if (GTP_AUTO_UPDATE && (!GTP_HEADER_FW_UPDATE || GTP_AUTO_UPDATE_CFG))
static void gup_search_file(s32 search_type)
{
    s32 i = 0;
    FS_HANDLE pfile = NULL;

    got_file_flag = 0x00;
    
    searching_file = 1;
    for (i = 0; i < GUP_SEARCH_FILE_TIMES; ++i)
    {            
        if (0 == searching_file)
        {
            GTP_INFO("Force exiting file searching");
            got_file_flag = 0x00;
            return;
        }
        
        if (search_type & AUTO_SEARCH_BIN)
        {
            GTP_DEBUG("Search for %s, %s for fw update.(%d/%d)", UPDATE_FILE_PATH_1, UPDATE_FILE_PATH_2, i+1, GUP_SEARCH_FILE_TIMES);
            pfile = FS_Open(UPDATE_FILE_PATH_1, FS_READ_ONLY);
            if (IS_ERR(pfile))
            {
                pfile = FS_Open(UPDATE_FILE_PATH_2, FS_READ_ONLY);
                if (!IS_ERR(pfile))
                {
                    GTP_INFO("Bin file: %s for fw update.", UPDATE_FILE_PATH_2);
                    got_file_flag |= BIN_FILE_READY;
                    update_msg.file = pfile;
                }
            }
            else
            {
                GTP_INFO("Bin file: %s for fw update.", UPDATE_FILE_PATH_1);
                got_file_flag |= BIN_FILE_READY;
                update_msg.file = pfile;
            }
            if (got_file_flag & BIN_FILE_READY)
            {
            #if GTP_AUTO_UPDATE_CFG
                if (search_type & AUTO_SEARCH_CFG)
                {
                    i = GUP_SEARCH_FILE_TIMES;    // Bin & Cfg File required to be in the same directory
                }
                else
            #endif
                {
                    searching_file = 0;
                    return;
                }
            }
        }
    
    #if GTP_AUTO_UPDATE_CFG
        if ( (search_type & AUTO_SEARCH_CFG) && !(got_file_flag & CFG_FILE_READY) )
        {
            GTP_DEBUG("Search for %s, %s for config update.(%d/%d)", CONFIG_FILE_PATH_1, CONFIG_FILE_PATH_2, i+1, GUP_SEARCH_FILE_TIMES);
            pfile = FS_Open(CONFIG_FILE_PATH_1, FS_READ_ONLY);
            if (IS_ERR(pfile))
            {
                pfile = FS_Open(CONFIG_FILE_PATH_2, FS_READ_ONLY);
                if (!IS_ERR(pfile))
                {
                    GTP_INFO("Cfg file: %s for config update.", CONFIG_FILE_PATH_2);
                    got_file_flag |= CFG_FILE_READY;
                    update_msg.cfg_file = pfile;
                }
            }
            else
            {
                GTP_INFO("Cfg file: %s for config update.", CONFIG_FILE_PATH_1);
                got_file_flag |= CFG_FILE_READY;
                update_msg.cfg_file = pfile;
            }
            if (got_file_flag & CFG_FILE_READY)
            {
                searching_file = 0;
                return;
            }
        }
    #endif
    }
    searching_file = 0;
}

#endif

static u8 gup_check_update_file(struct i2c_client *client, st_fw_head *fw_head, kal_wchar *path)
{
    s32 ret = 0;
    s32 i = 0;
    s32 fw_checksum = 0;
    u8 buf[FW_HEAD_LENGTH];
    s32 rLen = 0;

    got_file_flag = 0x00;
    if (path)
    {
        //GTP_DEBUG("Update File path:%s, %d", path, strlen(path));
        update_msg.file = FS_Open(path, FS_READ_ONLY);

        if (IS_ERR(update_msg.file))
        {
            //GTP_ERROR("Open update file(%s) error!", path);
            GTP_ERROR("Open update file error!");
            return FAIL;
        }
        got_file_flag = BIN_FILE_READY;
    }
    else
    {
#if GTP_AUTO_UPDATE
	#if GTP_HEADER_FW_UPDATE
        GTP_INFO("Update by default firmware array");
        update_msg.fw_total_len = sizeof(gtp_default_FW) - FW_HEAD_LENGTH;
        if (sizeof(gtp_default_FW) < (FW_HEAD_LENGTH + FW_SECTION_LENGTH*4+FW_DSP_ISP_LENGTH+FW_DSP_LENGTH+FW_BOOT_LENGTH))
        {
            GTP_INFO("[check_update_file]default firmware array is INVALID!");
            return FAIL;
        }
        GTP_DEBUG("Firmware actual size: %d(%dK)", update_msg.fw_total_len, update_msg.fw_total_len/1024);
        memcpy(fw_head, &gtp_default_FW[0], FW_HEAD_LENGTH);
        
        //check firmware legality
        fw_checksum = 0;
        for (i = 0; i < update_msg.fw_total_len; i += 2)
        {
            fw_checksum += (gtp_default_FW[FW_HEAD_LENGTH + i] << 8) + gtp_default_FW[FW_HEAD_LENGTH + i + 1];
        }
        if(fw_checksum&0xFFFF)
        {
            GTP_ERROR("Illegal firmware with checksum(0x%04X)", fw_checksum & 0xFFFF);
            return FAIL;
        }
        got_file_flag = HEADER_FW_READY;
        return SUCCESS;       
    #else
        #if GTP_AUTO_UPDATE_CFG
            gup_search_file(AUTO_SEARCH_BIN | AUTO_SEARCH_CFG);
            if (got_file_flag & CFG_FILE_READY)
            {
                ret = gup_update_config(client);
            	if(ret <= 0)
                {
                    GTP_ERROR("Update config failed!");
                }
                _CLOSE_FILE(update_msg.cfg_file);
                msleep(500);                //waiting config to be stored in FLASH.
            }
        #else
            gup_search_file(AUTO_SEARCH_BIN);
        #endif

            if (!(got_file_flag & BIN_FILE_READY))
            {
                GTP_ERROR("No bin file for fw Update");
                return FAIL;
            }
    #endif
#else
        {
            GTP_ERROR("NULL file for fw update!");
            return FAIL;
        }
#endif
    }

    
    FS_Seek(update_msg.file, 0, SEEK_SET);
    update_msg.fw_total_len = FS_Seek(update_msg.file, 0, SEEK_END);
    
    update_msg.fw_total_len -= FW_HEAD_LENGTH;
    
    GTP_DEBUG("Bin firmware actual size: %d(%dK)", update_msg.fw_total_len, update_msg.fw_total_len/1024);
    
    FS_Seek(update_msg.file, 0, SEEK_SET);
    ret = FS_Read(update_msg.file, (char *)buf, FW_HEAD_LENGTH, &rLen);

    if (ret < 0 || rLen != FW_HEAD_LENGTH)
    {
        GTP_ERROR("Read firmware head in update file error.");
        goto load_failed;
    }

    memcpy(fw_head, buf, FW_HEAD_LENGTH);
    
    //check firmware legality
    fw_checksum = 0;
    for(i=0; i < update_msg.fw_total_len; i+=2)
    {
        u16 temp;
        ret = FS_Read(update_msg.file, (char*)buf, 2, &rLen);
        if (ret < 0 || rLen != 2)
        {
            GTP_ERROR("Read firmware file error.");
            goto load_failed;
        }
        //GTP_DEBUG("BUF[0]:%x", buf[0]);
        temp = (buf[0]<<8) + buf[1];
        fw_checksum += temp;
    }
    
    GTP_DEBUG("firmware checksum:%x", fw_checksum&0xFFFF);
    if(fw_checksum&0xFFFF)
    {
        GTP_ERROR("Illegal firmware file.");
        goto load_failed;
    }
    
    return SUCCESS;

load_failed:
    _CLOSE_FILE(update_msg.file);
    return FAIL;
}

static u8 gup_burn_proc(struct i2c_client *client, u8 *burn_buf, u16 start_addr, u16 total_length)
{
    s32 ret = 0;
    u16 burn_addr = start_addr;
    u16 frame_length = 0;
    u16 burn_length = 0;
    u8  wr_buf[PACK_SIZE + GTP_ADDR_LENGTH];
    u8  rd_buf[PACK_SIZE + GTP_ADDR_LENGTH];
    u8  retry = 0;

    GTP_DEBUG("Begin burn %dk data to addr 0x%x", (total_length / 1024), start_addr);

    while (burn_length < total_length)
    {
        GTP_DEBUG("B/T:%04d/%04d", burn_length, total_length);
        frame_length = ((total_length - burn_length) > PACK_SIZE) ? PACK_SIZE : (total_length - burn_length);
        wr_buf[0] = (u8)(burn_addr >> 8);
        rd_buf[0] = wr_buf[0];
        wr_buf[1] = (u8)burn_addr;
        rd_buf[1] = wr_buf[1];
        memcpy(&wr_buf[GTP_ADDR_LENGTH], &burn_buf[burn_length], frame_length);

        for (retry = 0; retry < MAX_FRAME_CHECK_TIME; retry++)
        {
            ret = gup_i2c_write(client, wr_buf, GTP_ADDR_LENGTH + frame_length);

            if (ret <= 0)
            {
                GTP_ERROR("Write frame data i2c error.");
                continue;
            }

            ret = gup_i2c_read(client, rd_buf, GTP_ADDR_LENGTH + frame_length);

            if (ret <= 0)
            {
                GTP_ERROR("Read back frame data i2c error.");
                continue;
            }

            if (memcmp(&wr_buf[GTP_ADDR_LENGTH], &rd_buf[GTP_ADDR_LENGTH], frame_length))
            {
                GTP_ERROR("Check frame data fail,not equal.");
                GTP_DEBUG("write array:");
                GTP_DEBUG_ARRAY(&wr_buf[GTP_ADDR_LENGTH], frame_length);
                GTP_DEBUG("read array:");
                GTP_DEBUG_ARRAY(&rd_buf[GTP_ADDR_LENGTH], frame_length);
                continue;
            }
            else
            {
                //GTP_DEBUG("Check frame data success.");
                break;
            }
        }

        if (retry > MAX_FRAME_CHECK_TIME)
        {
            GTP_ERROR("Burn frame data time out,exit.");
            return FAIL;
        }

        burn_length += frame_length;
        burn_addr += frame_length;
    }

    return SUCCESS;
}

static u8 gup_load_section_file(u8 *buf, u32 offset, u16 length, u8 set_or_end)
{
	s32 rLen = 0;

#if (GTP_AUTO_UPDATE && GTP_HEADER_FW_UPDATE)
    if (HEADER_FW_READY == got_file_flag)
    {
        if(SEEK_SET == set_or_end)
        {
            memcpy(buf, &gtp_default_FW[FW_HEAD_LENGTH + offset], length);
        }
        else    //seek end
        {
            memcpy(buf, &gtp_default_FW[update_msg.fw_total_len + FW_HEAD_LENGTH - offset], length);
        }
        return SUCCESS;
    }
#endif
    {
        s32 ret = 0;
    
        if ( (update_msg.file == NULL) || IS_ERR(update_msg.file))
        {
            GTP_ERROR("cannot find update file,load section file fail.");
            return FAIL;
        }
        
        if(SEEK_SET == set_or_end)
        {
            FS_Seek(update_msg.file, FW_HEAD_LENGTH + offset, SEEK_SET);
        }
        else    //seek end
        {
            FS_Seek(update_msg.file, update_msg.fw_total_len + FW_HEAD_LENGTH - offset, SEEK_SET);
        }
    
        ret = FS_Read(update_msg.file, (char *)buf, length, &rLen);
    
        if (ret < 0 || rLen != length)
        {
            GTP_ERROR("Read update file fail.");
            return FAIL;
        }
    
        return SUCCESS;
    }
}

static u8 gup_recall_check(struct i2c_client *client, u8 *chk_src, u16 start_rd_addr, u16 chk_length)
{
    u8  rd_buf[PACK_SIZE + GTP_ADDR_LENGTH];
    s32 ret = 0;
    u16 recall_addr = start_rd_addr;
    u16 recall_length = 0;
    u16 frame_length = 0;

    while (recall_length < chk_length)
    {
        frame_length = ((chk_length - recall_length) > PACK_SIZE) ? PACK_SIZE : (chk_length - recall_length);
        ret = gup_get_ic_msg(client, recall_addr, rd_buf, frame_length);

        if (ret <= 0)
        {
            GTP_ERROR("recall i2c error,exit");
            return FAIL;
        }

        if (memcmp(&rd_buf[GTP_ADDR_LENGTH], &chk_src[recall_length], frame_length))
        {
            GTP_ERROR("Recall frame data fail,not equal.");
            GTP_DEBUG("chk_src array:");
            GTP_DEBUG_ARRAY(&chk_src[recall_length], frame_length);
            GTP_DEBUG("recall array:");
            GTP_DEBUG_ARRAY(&rd_buf[GTP_ADDR_LENGTH], frame_length);
            return FAIL;
        }

        recall_length += frame_length;
        recall_addr += frame_length;
    }

    GTP_DEBUG("Recall check %dk firmware success.", (chk_length / 1024));

    return SUCCESS;
}

static u8 gup_burn_fw_section(struct i2c_client *client, u8 *fw_section, u16 start_addr, u8 bank_cmd)
{
    s32 ret = 0;
    u8  rd_buf[5];

    //step1:hold ss51 & dsp
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]hold ss51 & dsp fail.");
        return FAIL;
    }

    //step2:set scramble
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]set scramble fail.");
        return FAIL;
    }

    //step3:select bank
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, (bank_cmd >> 4) & 0x0F);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]select bank %d fail.", (bank_cmd >> 4) & 0x0F);
        return FAIL;
    }

    //step4:enable accessing code
    ret = gup_set_ic_msg(client, _bRW_MISCTL__MEM_CD_EN, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]enable accessing code fail.");
        return FAIL;
    }

    //step5:burn 8k fw section
    ret = gup_burn_proc(client, fw_section, start_addr, FW_SECTION_LENGTH);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_section]burn fw_section fail.");
        return FAIL;
    }

    //step6:hold ss51 & release dsp
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x04);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]hold ss51 & release dsp fail.");
        return FAIL;
    }

    //must delay
    msleep(1);

    //step7:send burn cmd to move data to flash from sram
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, bank_cmd & 0x0f);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]send burn cmd fail.");
        return FAIL;
    }

    GTP_DEBUG("[burn_fw_section]Wait for the burn is complete......");

    do
    {
        ret = gup_get_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, rd_buf, 1);

        if (ret <= 0)
        {
            GTP_ERROR("[burn_fw_section]Get burn state fail");
            return FAIL;
        }

        msleep(10);
        //GTP_DEBUG("[burn_fw_section]Get burn state:%d.", rd_buf[GTP_ADDR_LENGTH]);
    }
    while (rd_buf[GTP_ADDR_LENGTH]);

    //step8:select bank
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, (bank_cmd >> 4) & 0x0F);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]select bank %d fail.", (bank_cmd >> 4) & 0x0F);
        return FAIL;
    }

    //step9:enable accessing code
    ret = gup_set_ic_msg(client, _bRW_MISCTL__MEM_CD_EN, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]enable accessing code fail.");
        return FAIL;
    }

    //step10:recall 8k fw section
    ret = gup_recall_check(client, fw_section, start_addr, FW_SECTION_LENGTH);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_section]recall check %dk firmware fail.", FW_SECTION_LENGTH/1024);
        return FAIL;
    }

    //step11:disable accessing code
    ret = gup_set_ic_msg(client, _bRW_MISCTL__MEM_CD_EN, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]disable accessing code fail.");
        return FAIL;
    }

    return SUCCESS;
}

static u8 gup_burn_dsp_isp(struct i2c_client *client)
{
    s32 ret = 0;
    u8 *fw_dsp_isp = NULL;
    u8  retry = 0;
    //u32 offset;

    GTP_INFO("[burn_dsp_isp]Begin burn dsp isp---->>");

    //step1:alloc memory
    GTP_DEBUG("[burn_dsp_isp]step1:alloc memory");

    while (retry++ < 5)
    {
        fw_dsp_isp = (u8 *)kzalloc(FW_DSP_ISP_LENGTH, GFP_KERNEL);

        if (fw_dsp_isp == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_dsp_isp]Alloc %dk byte memory success.", (FW_DSP_ISP_LENGTH / 1024));
            break;
        }
    }

    if (retry >= 5)
    {
        GTP_ERROR("[burn_dsp_isp]Alloc memory fail,exit.");
        return FAIL;
    }

    //step2:load dsp isp file data
    GTP_DEBUG("[burn_dsp_isp]step2:load dsp isp file data");
    ret = gup_load_section_file(fw_dsp_isp, FW_DSP_ISP_LENGTH, FW_DSP_ISP_LENGTH, SEEK_END);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_dsp_isp]load firmware dsp_isp fail.");
        goto exit_burn_dsp_isp;
    }

    //step3:disable wdt,clear cache enable
    GTP_DEBUG("[burn_dsp_isp]step3:disable wdt,clear cache enable");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__TMR0_EN, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]disable wdt fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    ret = gup_set_ic_msg(client, _bRW_MISCTL__CACHE_EN, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]clear cache enable fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step4:hold ss51 & dsp
    GTP_DEBUG("[burn_dsp_isp]step4:hold ss51 & dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]hold ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step5:set boot from sram
    GTP_DEBUG("[burn_dsp_isp]step5:set boot from sram");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOTCTL_B0_, 0x02);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]set boot from sram fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step6:software reboot
    GTP_DEBUG("[burn_dsp_isp]step6:software reboot");
    ret = gup_set_ic_msg(client, _bWO_MISCTL__CPU_SWRST_PULSE, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]software reboot fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step7:select bank2
    GTP_DEBUG("[burn_dsp_isp]step7:select bank2");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, 0x02);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]select bank2 fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step8:enable accessing code
    GTP_DEBUG("[burn_dsp_isp]step8:enable accessing code");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__MEM_CD_EN, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]enable accessing code fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }

    //step9:burn 4k dsp_isp
    GTP_DEBUG("[burn_dsp_isp]step9:burn 4k dsp_isp");
    ret = gup_burn_proc(client, fw_dsp_isp, 0xC000, FW_DSP_ISP_LENGTH);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_dsp_isp]burn dsp_isp fail.");
        goto exit_burn_dsp_isp;
    }

    //step10:set scramble
    GTP_DEBUG("[burn_dsp_isp]step10:set scramble");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_dsp_isp]set scramble fail.");
        ret = FAIL;
        goto exit_burn_dsp_isp;
    }
    
    update_msg.fw_burned_len += FW_DSP_ISP_LENGTH;
    GTP_DEBUG("[burn_dsp_isp]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;

exit_burn_dsp_isp:
    kfree(fw_dsp_isp);
    return ret;
}

static u8 gup_burn_fw_ss51(struct i2c_client *client)
{
    u8 *fw_ss51 = NULL;
    u8  retry = 0;
    s32 ret = 0;

    GTP_INFO("[burn_fw_ss51]Begin burn ss51 firmware---->>");

    //step1:alloc memory
    GTP_DEBUG("[burn_fw_ss51]step1:alloc memory");

    while (retry++ < 5)
    {
        fw_ss51 = (u8 *)kzalloc(FW_SECTION_LENGTH, GFP_KERNEL);

        if (fw_ss51 == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_ss51]Alloc %dk byte memory success.", (FW_SECTION_LENGTH / 1024));
            break;
        }
    }

    if (retry >= 5)
    {
        GTP_ERROR("[burn_fw_ss51]Alloc memory fail,exit.");
        return FAIL;
    }

    //step2:load ss51 firmware section 1 file data
    //GTP_DEBUG("[burn_fw_ss51]step2:load ss51 firmware section 1 file data");
    //ret = gup_load_section_file(fw_ss51, 0, FW_SECTION_LENGTH, SEEK_SET);
//	
//    if (FAIL == ret)
//    {
//        GTP_ERROR("[burn_fw_ss51]load ss51 firmware section 1 fail.");
//        goto exit_burn_fw_ss51;
//    }
    GTP_INFO("[burn_fw_ss51]Reset first 8K of ss51 to 0xFF.");
    GTP_DEBUG("[burn_fw_ss51]step2: reset bank0 0xC000~0xD000");
    memset(fw_ss51, 0xFF, FW_SECTION_LENGTH);

    //step3:clear control flag
    GTP_DEBUG("[burn_fw_ss51]step3:clear control flag");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_ss51]clear control flag fail.");
        ret = FAIL;
        goto exit_burn_fw_ss51;
    }

    //step4:burn ss51 firmware section 1
    GTP_DEBUG("[burn_fw_ss51]step4:burn ss51 firmware section 1");
    ret = gup_burn_fw_section(client, fw_ss51, 0xC000, 0x01);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]burn ss51 firmware section 1 fail.");
        goto exit_burn_fw_ss51;
    }

    //step5:load ss51 firmware section 2 file data
    GTP_DEBUG("[burn_fw_ss51]step5:load ss51 firmware section 2 file data");
    ret = gup_load_section_file(fw_ss51, FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]load ss51 firmware section 2 fail.");
        goto exit_burn_fw_ss51;
    }

    //step6:burn ss51 firmware section 2
    GTP_DEBUG("[burn_fw_ss51]step6:burn ss51 firmware section 2");
    ret = gup_burn_fw_section(client, fw_ss51, 0xE000, 0x02);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]burn ss51 firmware section 2 fail.");
        goto exit_burn_fw_ss51;
    }

    //step7:load ss51 firmware section 3 file data
    GTP_DEBUG("[burn_fw_ss51]step7:load ss51 firmware section 3 file data");
    ret = gup_load_section_file(fw_ss51, 2 * FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]load ss51 firmware section 3 fail.");
        goto exit_burn_fw_ss51;
    }

    //step8:burn ss51 firmware section 3
    GTP_DEBUG("[burn_fw_ss51]step8:burn ss51 firmware section 3");
    ret = gup_burn_fw_section(client, fw_ss51, 0xC000, 0x13);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]burn ss51 firmware section 3 fail.");
        goto exit_burn_fw_ss51;
    }

    //step9:load ss51 firmware section 4 file data
    GTP_DEBUG("[burn_fw_ss51]step9:load ss51 firmware section 4 file data");
    ret = gup_load_section_file(fw_ss51, 3 * FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]load ss51 firmware section 4 fail.");
        goto exit_burn_fw_ss51;
    }

    //step10:burn ss51 firmware section 4
    GTP_DEBUG("[burn_fw_ss51]step10:burn ss51 firmware section 4");
    ret = gup_burn_fw_section(client, fw_ss51, 0xE000, 0x14);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_ss51]burn ss51 firmware section 4 fail.");
        goto exit_burn_fw_ss51;
    }
    
    update_msg.fw_burned_len += (FW_SECTION_LENGTH*4);
    GTP_DEBUG("[burn_fw_ss51]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;

exit_burn_fw_ss51:
    kfree(fw_ss51);
    return ret;
}

static u8 gup_burn_fw_dsp(struct i2c_client *client)
{
    s32 ret = 0;
    u8 *fw_dsp = NULL;
    u8  retry = 0;
    u8  rd_buf[5];

    GTP_INFO("[burn_fw_dsp]Begin burn dsp firmware---->>");
    //step1:alloc memory
    GTP_DEBUG("[burn_fw_dsp]step1:alloc memory");

    while (retry++ < 5)
    {
        fw_dsp = (u8 *)kzalloc(FW_DSP_LENGTH, GFP_KERNEL);

        if (fw_dsp == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_dsp]Alloc %dk byte memory success.", (FW_SECTION_LENGTH / 1024));
            break;
        }
    }

    if (retry >= 5)
    {
        GTP_ERROR("[burn_fw_dsp]Alloc memory fail,exit.");
        return FAIL;
    }

    //step2:load firmware dsp
    GTP_DEBUG("[burn_fw_dsp]step2:load firmware dsp");
    ret = gup_load_section_file(fw_dsp, 4 * FW_SECTION_LENGTH, FW_DSP_LENGTH, SEEK_SET);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_dsp]load firmware dsp fail.");
        goto exit_burn_fw_dsp;
    }

    //step3:select bank3
    GTP_DEBUG("[burn_fw_dsp]step3:select bank3");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, 0x03);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_dsp]select bank3 fail.");
        ret = FAIL;
        goto exit_burn_fw_dsp;
    }

    //step4:hold ss51 & dsp
    GTP_DEBUG("[burn_fw_dsp]step4:hold ss51 & dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_dsp]hold ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_dsp;
    }

    //step5:set scramble
    GTP_DEBUG("[burn_fw_dsp]step5:set scramble");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_dsp]set scramble fail.");
        ret = FAIL;
        goto exit_burn_fw_dsp;
    }

    //step6:release ss51 & dsp
    GTP_DEBUG("[burn_fw_dsp]step6:release ss51 & dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x04);             //20121212

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_dsp]release ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_dsp;
    }

    //must delay
    msleep(1);

    //step7:burn 4k dsp firmware
    GTP_DEBUG("[burn_fw_dsp]step7:burn 4k dsp firmware");
    ret = gup_burn_proc(client, fw_dsp, 0x9000, FW_DSP_LENGTH);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_dsp]burn fw_section fail.");
        goto exit_burn_fw_dsp;
    }

    //step8:send burn cmd to move data to flash from sram
    GTP_DEBUG("[burn_fw_dsp]step8:send burn cmd to move data to flash from sram");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x05);

    if (ret <= 0)
    {
        GTP_ERROR("[burn_fw_dsp]send burn cmd fail.");
        goto exit_burn_fw_dsp;
    }

    GTP_DEBUG("[burn_fw_dsp]Wait for the burn is complete......");

    do
    {
        ret = gup_get_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, rd_buf, 1);

        if (ret <= 0)
        {
            GTP_ERROR("[burn_fw_dsp]Get burn state fail");
            goto exit_burn_fw_dsp;
        }

        msleep(10);
        //GTP_DEBUG("[burn_fw_dsp]Get burn state:%d.", rd_buf[GTP_ADDR_LENGTH]);
    }
    while (rd_buf[GTP_ADDR_LENGTH]);

    //step9:recall check 4k dsp firmware
    GTP_DEBUG("[burn_fw_dsp]step9:recall check 4k dsp firmware");
    ret = gup_recall_check(client, fw_dsp, 0x9000, FW_DSP_LENGTH);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_dsp]recall check 4k dsp firmware fail.");
        goto exit_burn_fw_dsp;
    }
    
    update_msg.fw_burned_len += FW_DSP_LENGTH;
    GTP_DEBUG("[burn_fw_dsp]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;

exit_burn_fw_dsp:
    kfree(fw_dsp);
    return ret;
}

static u8 gup_burn_fw_boot(struct i2c_client *client)
{
    s32 ret = 0;
    u8* fw_boot = NULL;
    u8  retry = 0;
    u8  rd_buf[5];
    
    GTP_DEBUG("[burn_fw_boot]Begin burn bootloader firmware---->>");
    
    //step1:Alloc memory
    GTP_DEBUG("[burn_fw_boot]step1:Alloc memory");

    while(retry++ < 5)
    {
        fw_boot = (u8*)kzalloc(FW_BOOT_LENGTH, GFP_KERNEL);

        if(fw_boot == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_boot]Alloc %dk byte memory success.", (FW_BOOT_LENGTH/1024));
            break;
        }
    }

    if(retry >= 5)
    {
        GTP_ERROR("[burn_fw_boot]Alloc memory fail,exit.");
        return FAIL;
    }
    
    //step2:load firmware bootloader
    GTP_DEBUG("[burn_fw_boot]step2:load firmware bootloader");
    ret = gup_load_section_file(fw_boot, (4 * FW_SECTION_LENGTH + FW_DSP_LENGTH), FW_BOOT_LENGTH, SEEK_SET);

    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot]load firmware bootcode fail.");
        goto exit_burn_fw_boot;
    }
    
    //step3:hold ss51 & dsp
    GTP_DEBUG("[burn_fw_boot]step3:hold ss51 & dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot]hold ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_boot;
    }
    
    //step4:set scramble
    GTP_DEBUG("[burn_fw_boot]step4:set scramble");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot]set scramble fail.");
        ret = FAIL;
        goto exit_burn_fw_boot;
    }
    
    //step5:hold ss51 & release dsp
    GTP_DEBUG("[burn_fw_boot]step5:hold ss51 & release dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x04);                 //20121211
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot]release ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_boot;
    }
    //must delay
    msleep(1);
    
    //step6:select bank3
    GTP_DEBUG("[burn_fw_boot]step6:select bank3");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, 0x03);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot]select bank3 fail.");
        ret = FAIL;
        goto exit_burn_fw_boot;
    }
    
    //step7:burn 2k bootloader firmware
    GTP_DEBUG("[burn_fw_boot]step7:burn 2k bootloader firmware");
    ret = gup_burn_proc(client, fw_boot, 0x9000, FW_BOOT_LENGTH);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot]burn fw_boot fail.");
        goto exit_burn_fw_boot;
    }
    
    //step7:send burn cmd to move data to flash from sram
    GTP_DEBUG("[burn_fw_boot]step7:send burn cmd to move data to flash from sram");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x06);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot]send burn cmd fail.");
        goto exit_burn_fw_boot;
    }
    GTP_DEBUG("[burn_fw_boot]Wait for the burn is complete......");
    do{
        ret = gup_get_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, rd_buf, 1);
        if(ret <= 0)
        {
            GTP_ERROR("[burn_fw_boot]Get burn state fail");
            goto exit_burn_fw_boot;
        }
        msleep(10);
        //GTP_DEBUG("[burn_fw_boot]Get burn state:%d.", rd_buf[GTP_ADDR_LENGTH]);
    }while(rd_buf[GTP_ADDR_LENGTH]);
    
    //step8:recall check 2k bootloader firmware
    GTP_DEBUG("[burn_fw_boot]step8:recall check 2k bootloader firmware");
    ret = gup_recall_check(client, fw_boot, 0x9000, FW_BOOT_LENGTH);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot]recall check 2k bootcode firmware fail.");
        goto exit_burn_fw_boot;
    }
    
    update_msg.fw_burned_len += FW_BOOT_LENGTH;
    GTP_DEBUG("[burn_fw_boot]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;
    
exit_burn_fw_boot:
    kfree(fw_boot);
    return ret;
}

static u8 gup_burn_fw_boot_isp(struct i2c_client *client)
{
    s32 ret = 0;
    u8* fw_boot_isp = NULL;
    u8  retry = 0;
    u8  rd_buf[5];
    
    if(update_msg.fw_burned_len >= update_msg.fw_total_len)
    {
        GTP_INFO("No need to upgrade the boot_isp code!");
        return SUCCESS;
    }
    GTP_DEBUG("[burn_fw_boot_isp]Begin burn bootloader firmware---->>");
    
    //step1:Alloc memory
    GTP_DEBUG("[burn_fw_boot_isp]step1:Alloc memory");
    while(retry++ < 5)
    {
        fw_boot_isp = (u8*)kzalloc(FW_BOOT_ISP_LENGTH, GFP_KERNEL);
        if(fw_boot_isp == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_boot_isp]Alloc %dk byte memory success.", (FW_BOOT_ISP_LENGTH/1024));
            break;
        }
    }
    if(retry >= 5)
    {
        GTP_ERROR("[burn_fw_boot_isp]Alloc memory fail,exit.");
        return FAIL;
    }
    
    //step2:load firmware bootloader
    GTP_DEBUG("[burn_fw_boot_isp]step2:load firmware bootloader isp");
    //ret = gup_load_section_file(fw_boot_isp, (4*FW_SECTION_LENGTH+FW_DSP_LENGTH+FW_BOOT_LENGTH+FW_DSP_ISP_LENGTH), FW_BOOT_ISP_LENGTH, SEEK_SET);
    ret = gup_load_section_file(fw_boot_isp, (update_msg.fw_burned_len - FW_DSP_ISP_LENGTH), FW_BOOT_ISP_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot_isp]load firmware boot_isp fail.");
        goto exit_burn_fw_boot_isp;
    }
    
    //step3:hold ss51 & dsp
    GTP_DEBUG("[burn_fw_boot_isp]step3:hold ss51 & dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot_isp]hold ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_boot_isp;
    }
    
    //step4:set scramble
    GTP_DEBUG("[burn_fw_boot_isp]step4:set scramble");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot_isp]set scramble fail.");
        ret = FAIL;
        goto exit_burn_fw_boot_isp;
    }
    
    
    //step5:hold ss51 & release dsp
    GTP_DEBUG("[burn_fw_boot_isp]step5:hold ss51 & release dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x04);                 //20121211
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot_isp]release ss51 & dsp fail.");
        ret = FAIL;
        goto exit_burn_fw_boot_isp;
    }
    //must delay
    msleep(1);
    
    //step6:select bank3
    GTP_DEBUG("[burn_fw_boot_isp]step6:select bank3");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, 0x03);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot_isp]select bank3 fail.");
        ret = FAIL;
        goto exit_burn_fw_boot_isp;
    }
    
    //step7:burn 2k bootload_isp firmware
    GTP_DEBUG("[burn_fw_boot_isp]step7:burn 2k bootloader firmware");
    ret = gup_burn_proc(client, fw_boot_isp, 0x9000, FW_BOOT_ISP_LENGTH);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot_isp]burn fw_section fail.");
        goto exit_burn_fw_boot_isp;
    }
    
    //step7:send burn cmd to move data to flash from sram
    GTP_DEBUG("[burn_fw_boot_isp]step7:send burn cmd to move data to flash from sram");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x07);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_boot_isp]send burn cmd fail.");
        goto exit_burn_fw_boot_isp;
    }
    GTP_DEBUG("[burn_fw_boot_isp]Wait for the burn is complete......");
    do{
        ret = gup_get_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, rd_buf, 1);
        if(ret <= 0)
        {
            GTP_ERROR("[burn_fw_boot_isp]Get burn state fail");
            goto exit_burn_fw_boot_isp;
        }
        msleep(10);
        //GTP_DEBUG("[burn_fw_boot_isp]Get burn state:%d.", rd_buf[GTP_ADDR_LENGTH]);
    }while(rd_buf[GTP_ADDR_LENGTH]);
    
    //step8:recall check 2k bootload_isp firmware
    GTP_DEBUG("[burn_fw_boot_isp]step8:recall check 2k bootloader firmware");
    ret = gup_recall_check(client, fw_boot_isp, 0x9000, FW_BOOT_ISP_LENGTH);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_boot_isp]recall check 2k bootcode_isp firmware fail.");
        goto exit_burn_fw_boot_isp;
    }
    
    update_msg.fw_burned_len += FW_BOOT_ISP_LENGTH;
    GTP_DEBUG("[burn_fw_boot_isp]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;
    
exit_burn_fw_boot_isp:
    kfree(fw_boot_isp);
    return ret;
}

static u8 gup_burn_fw_link(struct i2c_client *client)
{
    s32 ret = 0;
    u8* fw_link = NULL;
    u8  retry = 0;
    u32 offset;
    
    if(update_msg.fw_burned_len >= update_msg.fw_total_len)
    {
        GTP_INFO("No need to upgrade the link code!");
        return SUCCESS;
    }
    GTP_DEBUG("[burn_fw_link]Begin burn link firmware---->>");
    
    //step1:Alloc memory
    GTP_DEBUG("[burn_fw_link]step1:Alloc memory");
    while(retry++ < 5)
    {
        fw_link = (u8*)kzalloc(FW_SECTION_LENGTH, GFP_KERNEL);
        if(fw_link == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_link]Alloc %dk byte memory success.", (FW_SECTION_LENGTH/1024));
            break;
        }
    }
    if(retry >= 5)
    {
        GTP_ERROR("[burn_fw_link]Alloc memory fail,exit.");
        return FAIL;
    }
    
    //step2:load firmware link section 1
    GTP_DEBUG("[burn_fw_link]step2:load firmware link section 1");
    offset = update_msg.fw_burned_len - FW_DSP_ISP_LENGTH;
    ret = gup_load_section_file(fw_link, offset, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_link]load firmware link section 1 fail.");
        goto exit_burn_fw_link;
    }
    
    
    //step3:burn link firmware section 1
    GTP_DEBUG("[burn_fw_link]step3:burn link firmware section 1");
    ret = gup_burn_fw_app_section(client, fw_link, 0x9000, FW_SECTION_LENGTH, 0x38);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_link]burn link firmware section 1 fail.");
        goto exit_burn_fw_link;
    }
    
    //step4:load link firmware section 2 file data
    GTP_DEBUG("[burn_fw_link]step4:load link firmware section 2 file data");
    offset += FW_SECTION_LENGTH;
    ret = gup_load_section_file(fw_link, offset, FW_LINK_LENGTH - FW_SECTION_LENGTH, SEEK_SET);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_link]load link firmware section 2 fail.");
        goto exit_burn_fw_link;
    }
    
    //step5:burn link firmware section 2
    GTP_DEBUG("[burn_fw_link]step4:burn link firmware section 2");
    ret = gup_burn_fw_app_section(client, fw_link, 0x9000, FW_LINK_LENGTH - FW_SECTION_LENGTH, 0x39);

    if (FAIL == ret)
    {
        GTP_ERROR("[burn_fw_link]burn link firmware section 2 fail.");
        goto exit_burn_fw_link;
    }
    
    update_msg.fw_burned_len += FW_LINK_LENGTH;
    GTP_DEBUG("[burn_fw_link]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;
    
exit_burn_fw_link:
    kfree(fw_link);
    return ret;
}

static u8 gup_burn_fw_app_section(struct i2c_client *client, u8 *fw_section, u16 start_addr, u32 len, u8 bank_cmd )
{
    s32 ret = 0;
    u8  rd_buf[5];
  
    //step1:hold ss51 & dsp
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_app_section]hold ss51 & dsp fail.");
        return FAIL;
    }
    
    //step2:set scramble
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_app_section]set scramble fail.");
        return FAIL;
    }
        
    //step3:hold ss51 & release dsp
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x04);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_app_section]hold ss51 & release dsp fail.");
        return FAIL;
    }
    //must delay
    msleep(1);
    
    //step4:select bank
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, (bank_cmd >> 4)&0x0F);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_section]select bank %d fail.", (bank_cmd >> 4)&0x0F);
        return FAIL;
    }
    
    //step5:burn fw section
    ret = gup_burn_proc(client, fw_section, start_addr, len);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_section]burn fw_section fail.");
        return FAIL;
    }
    
    //step6:send burn cmd to move data to flash from sram
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, bank_cmd&0x0F);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_app_section]send burn cmd fail.");
        return FAIL;
    }
    GTP_DEBUG("[burn_fw_section]Wait for the burn is complete......");
    do{
        ret = gup_get_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, rd_buf, 1);
        if(ret <= 0)
        {
            GTP_ERROR("[burn_fw_app_section]Get burn state fail");
            return FAIL;
        }
        msleep(10);
        //GTP_DEBUG("[burn_fw_app_section]Get burn state:%d.", rd_buf[GTP_ADDR_LENGTH]);
    }while(rd_buf[GTP_ADDR_LENGTH]);
    
    //step7:recall fw section
    ret = gup_recall_check(client, fw_section, start_addr, len);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_section]recall check %dk firmware fail.", len/1024);
        return FAIL;
    }
    
    return SUCCESS;
}

static u8 gup_burn_fw_app_code(struct i2c_client *client)
{
    u8* fw_app_code = NULL;
    u8  retry = 0;
    s32 ret = 0;
    //u16 start_index = 4*FW_SECTION_LENGTH+FW_DSP_LENGTH+FW_BOOT_LENGTH + FW_DSP_ISP_LENGTH + FW_BOOT_ISP_LENGTH; // 32 + 4 + 2 + 4 = 42K
    u16 start_index;
    
    if(update_msg.fw_burned_len >= update_msg.fw_total_len)
    {
        GTP_INFO("No need to upgrade the app code!");
        return SUCCESS;
    }
    start_index = update_msg.fw_burned_len - FW_DSP_ISP_LENGTH;
    GTP_DEBUG("[burn_fw_app_code]Begin burn app_code firmware---->>");
    
    //step1:alloc memory
    GTP_DEBUG("[burn_fw_app_code]step1:alloc memory");
    while(retry++ < 5)
    {
        fw_app_code = (u8*)kzalloc(FW_SECTION_LENGTH, GFP_KERNEL);
        if(fw_app_code == NULL)
        {
            continue;
        }
        else
        {
            GTP_INFO("[burn_fw_app_code]Alloc %dk byte memory success.", (FW_SECTION_LENGTH/1024));
            break;
        }
    }
    if(retry >= 5)
    {
        GTP_ERROR("[burn_fw_app_code]Alloc memory fail,exit.");
        return FAIL;
    }
    
    //step2:load app_code firmware section 1 file data
    GTP_DEBUG("[burn_fw_app_code]step2:load app_code firmware section 1 file data");
    ret = gup_load_section_file(fw_app_code, start_index, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]load app_code firmware section 1 fail.");
        goto exit_burn_fw_app_code;
    }
  
    //step3:burn app_code firmware section 1
    GTP_DEBUG("[burn_fw_app_code]step3:burn app_code firmware section 1");
    ret = gup_burn_fw_app_section(client, fw_app_code, 0x9000, FW_SECTION_LENGTH, 0x3A);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]burn app_code firmware section 1 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step5:load app_code firmware section 2 file data
    GTP_DEBUG("[burn_fw_app_code]step5:load app_code firmware section 2 file data");
    ret = gup_load_section_file(fw_app_code, start_index+FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]load app_code firmware section 2 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step6:burn app_code firmware section 2
    GTP_DEBUG("[burn_fw_app_code]step6:burn app_code firmware section 2");
    ret = gup_burn_fw_app_section(client, fw_app_code, 0x9000, FW_SECTION_LENGTH, 0x3B);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]burn app_code firmware section 2 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step7:load app_code firmware section 3 file data
    GTP_DEBUG("[burn_fw_app_code]step7:load app_code firmware section 3 file data");
    ret = gup_load_section_file(fw_app_code, start_index+2*FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]load app_code firmware section 3 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step8:burn app_code firmware section 3
    GTP_DEBUG("[burn_fw_app_code]step8:burn app_code firmware section 3");
    ret = gup_burn_fw_app_section(client, fw_app_code, 0x9000, FW_SECTION_LENGTH, 0x3C);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]burn app_code firmware section 3 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step9:load app_code firmware section 4 file data
    GTP_DEBUG("[burn_fw_app_code]step9:load app_code firmware section 4 file data");
    ret = gup_load_section_file(fw_app_code, start_index + 3*FW_SECTION_LENGTH, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]load app_code firmware section 4 fail.");
        goto exit_burn_fw_app_code;
    }
    
    //step10:burn app_code firmware section 4
    GTP_DEBUG("[burn_fw_app_code]step10:burn app_code firmware section 4");
    ret = gup_burn_fw_app_section(client, fw_app_code, 0x9000, FW_SECTION_LENGTH, 0x3D);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_app_code]burn app_code firmware section 4 fail.");
        goto exit_burn_fw_app_code;
    }
    
    update_msg.fw_burned_len += FW_APP_CODE_LENGTH;
    GTP_DEBUG("[burn_fw_gwake]Burned length:%d", update_msg.fw_burned_len);
    ret = SUCCESS;
    
exit_burn_fw_app_code:
    kfree(fw_app_code);
    return ret;
}

static u8 gup_burn_fw_finish(struct i2c_client *client)
{
    u8* fw_ss51 = NULL;
    u8  retry = 0;
    s32 ret = 0;
    
    GTP_INFO("[burn_fw_finish]burn first 8K of ss51 and finish update.");
    //step1:alloc memory
    GTP_DEBUG("[burn_fw_finish]step1:alloc memory");
    while(retry++ < 5)
    {
        fw_ss51 = (u8*)kzalloc(FW_SECTION_LENGTH, GFP_KERNEL);
        if(fw_ss51 == NULL)
        {
            continue;
        }
        else
        {
            GTP_DEBUG("[burn_fw_finish]Alloc %dk byte memory success.", (FW_SECTION_LENGTH/1024));
            break;
        }
    }
    if(retry >= 5)
    {
        GTP_ERROR("[burn_fw_finish]Alloc memory fail,exit.");
        return FAIL;
    }
    
    GTP_DEBUG("[burn_fw_finish]step2: burn ss51 first 8K.");
    ret = gup_load_section_file(fw_ss51, 0, FW_SECTION_LENGTH, SEEK_SET);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_finish]load ss51 firmware section 1 fail.");
        goto exit_burn_fw_finish;
    }

    GTP_DEBUG("[burn_fw_finish]step3:clear control flag");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x00);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_finish]clear control flag fail.");
        goto exit_burn_fw_finish;
    }
    
    GTP_DEBUG("[burn_fw_finish]step4:burn ss51 firmware section 1");
    ret = gup_burn_fw_section(client, fw_ss51, 0xC000, 0x01);
    if(FAIL == ret)
    {
        GTP_ERROR("[burn_fw_finish]burn ss51 firmware section 1 fail.");
        goto exit_burn_fw_finish;
    }
    
    //step11:enable download DSP code 
    GTP_DEBUG("[burn_fw_finish]step5:enable download DSP code ");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x99);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_finish]enable download DSP code fail.");
        goto exit_burn_fw_finish;
    }
    
    //step12:release ss51 & hold dsp
    GTP_DEBUG("[burn_fw_finish]step6:release ss51 & hold dsp");
    ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x08);
    if(ret <= 0)
    {
        GTP_ERROR("[burn_fw_finish]release ss51 & hold dsp fail.");
        goto exit_burn_fw_finish;
    }

    if (fw_ss51)
    {
        kfree(fw_ss51);
    }
    return SUCCESS;
    
exit_burn_fw_finish:
    if (fw_ss51)
    {
        kfree(fw_ss51);
    }
    return FAIL;
}

s32 gup_update_proc(void *dir)
{
    s32 ret = 0;
    u8  retry = 0;
    s32 update_ret = FAIL;
    st_fw_head fw_head;

    GTP_INFO("[update_proc]Begin update ......");
    
#if GTP_AUTO_UPDATE
    if (1 == searching_file)
    {
        u8 timeout = 0;
        searching_file = 0;     // exit .bin update file searching 
        GTP_INFO("Exiting searching file for auto update.");
        while ((show_len != 200) && (show_len != 100) && (timeout++ < 150))     // wait for auto update quitted completely
        {
            msleep(100);
        }
    }
#endif
    
    show_len = 1;
    total_len = 100; 
    
#if GTP_COMPATIBLE_MODE
    if (CHIP_TYPE_GT9F == gtp_chip_type)
    {
        return gup_fw_download_proc(dir, GTP_FL_FW_BURN);
    }
#endif
    update_msg.file = NULL;
    ret = gup_check_update_file(i2c_client_point, &fw_head, (kal_wchar *)dir);    //20121212

    if (FAIL == ret)
    {
        GTP_ERROR("[update_proc]check update file fail.");
        goto file_fail;
    }
    
    //gtp_reset_guitar(i2c_client_point, 20);
    ret = gup_get_ic_fw_msg(i2c_client_point);

    if (FAIL == ret)
    {
        GTP_ERROR("[update_proc]get ic message fail.");
        goto file_fail;
    }
    ret = gup_enter_update_judge(&fw_head);                             //20121212

    if (FAIL == ret)
    {
        GTP_ERROR("[update_proc]Check *.bin file fail.");
        goto file_fail;
    }
    mt_eint_mask(CUST_EINT_TOUCH_PANEL_NUM);
#if GTP_ESD_PROTECT
    gtp_esd_switch(i2c_client_point, SWITCH_OFF);
#endif
    ret = gup_enter_update_mode(i2c_client_point);

    if (FAIL == ret)
    {
        GTP_ERROR("[update_proc]enter update mode fail.");
        goto update_fail;
    }

    while (retry++ < 5)
    {
        show_len = 10;
        total_len = 100;
        update_msg.fw_burned_len = 0;
        GTP_DEBUG("[update_proc]Burned length:%d", update_msg.fw_burned_len);
        ret = gup_burn_dsp_isp(i2c_client_point);
        if(FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn dsp isp fail.");
            continue;
        }
        
        show_len = 30;
        ret = gup_burn_fw_ss51(i2c_client_point);
        if(FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn ss51 firmware fail.");
            continue;
        }
        
        show_len = 40;
        ret = gup_burn_fw_dsp(i2c_client_point);
        if(FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn dsp firmware fail.");
            continue;
        }
        
        show_len = 50;
        ret = gup_burn_fw_boot(i2c_client_point);
        if(FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn bootloader firmware fail.");
            continue;
        }
        show_len = 60;
        
        ret = gup_burn_fw_boot_isp(i2c_client_point);
        if (FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn boot_isp firmware fail.");
            continue;
        }
        
        show_len = 70;
        ret = gup_burn_fw_link(i2c_client_point);
        if (FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn link firmware fail.");
            continue;
        }
        
        show_len = 80;
        ret = gup_burn_fw_app_code(i2c_client_point);
        if (FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn app_code firmware fail.");
            continue;
        }       
        show_len = 90;
        ret = gup_burn_fw_finish(i2c_client_point);
        if (FAIL == ret)
        {
            GTP_ERROR("[update_proc]burn finish fail.");
            continue;
        }
        show_len = 95;
        GTP_INFO("[update_proc]UPDATE SUCCESS.");
        break;
    }

    if (retry >= 5)
    {
        GTP_ERROR("[update_proc]retry timeout,UPDATE FAIL.");
        update_ret = FAIL;
    }
    else
    {
        update_ret = SUCCESS;
    }
    
update_fail:
    GTP_DEBUG("[update_proc]leave update mode.");
    gup_leave_update_mode();    
    
    if (SUCCESS == update_ret)
    {
        GTP_DEBUG("[update_proc]send config.");
        ret = ctp_goodix_gt9xx_set_configuration();
        if (ret == KAL_FALSE)
        {
            GTP_ERROR("[update_proc]send config fail.");
        }
    }
    
#if GTP_ESD_PROTECT
    gtp_esd_switch(i2c_client_point, SWITCH_ON);
#endif

file_fail:
    mt_eint_unmask(CUST_EINT_TOUCH_PANEL_NUM);
    
	if (update_msg.file && !IS_ERR(update_msg.file))
	{
		FS_Close(update_msg.file);
	}
#if (GTP_AUTO_UPDATE && GTP_HEADER_FW_UPDATE && GTP_AUTO_UPDATE_CFG)
    if (NULL == dir)
    {
        gup_search_file(AUTO_SEARCH_CFG);
        if (got_file_flag & CFG_FILE_READY)
        {
            ret = gup_update_config(i2c_client_point);
            if (FAIL == ret)
            {
                GTP_ERROR("Update config failed!");
            }
        }
    }    
#endif

    total_len = 100;
    if (SUCCESS == update_ret)
    {
        show_len = 100;
        return SUCCESS;
    }
    else
    {
        show_len = 200;
        return FAIL;
    }
}
#endif

#if (GTP_COMPATIBLE_MODE || GTP_HOTKNOT_MODULE)
//******************* For GT9XXF Start ********************//

#define FL_UPDATE_PATH              "/data/_fl_update_.bin"
#define FL_UPDATE_PATH_SD           "/sdcard/_fl_update_.bin" 

#define GUP_FW_CHK_SIZE              256
#define MAX_CHECK_TIMES              128    // max: 2 * (16 * 1024) / 256 = 128

//for clk cal
#define PULSE_LENGTH      (200)
#define INIT_CLK_DAC      (50)
#define MAX_CLK_DAC       (120)
#define CLK_AVG_TIME      (1)
#define MILLION           1000000

#define _wRW_MISCTL__RG_DMY                       0x4282
#define _bRW_MISCTL__RG_OSC_CALIB                 0x4268
#define _fRW_MISCTL__GIO0                         0x41e9
#define _fRW_MISCTL__GIO1                         0x41ed
#define _fRW_MISCTL__GIO2                         0x41f1
#define _fRW_MISCTL__GIO3                         0x41f5
#define _fRW_MISCTL__GIO4                         0x41f9
#define _fRW_MISCTL__GIO5                         0x41fd
#define _fRW_MISCTL__GIO6                         0x4201
#define _fRW_MISCTL__GIO7                         0x4205
#define _fRW_MISCTL__GIO8                         0x4209
#define _fRW_MISCTL__GIO9                         0x420d
#define _fRW_MISCTL__MEA                          0x41a0
#define _bRW_MISCTL__MEA_MODE                     0x41a1
#define _wRW_MISCTL__MEA_MAX_NUM                  0x41a4
#define _dRO_MISCTL__MEA_VAL                      0x41b0
#define _bRW_MISCTL__MEA_SRCSEL                   0x41a3
#define _bRO_MISCTL__MEA_RDY                      0x41a8
#define _rRW_MISCTL__ANA_RXADC_B0_                0x4250
#define _bRW_MISCTL__RG_LDO_A18_PWD               0x426f
#define _bRW_MISCTL__RG_BG_PWD                    0x426a
#define _bRW_MISCTL__RG_CLKGEN_PWD                0x4269
#define _fRW_MISCTL__RG_RXADC_PWD                 0x426a
#define _bRW_MISCTL__OSC_CK_SEL                   0x4030
#define _rRW_MISCTL_RG_DMY83                      0x4283
#define _rRW_MISCTL__GIO1CTL_B2_                  0x41ee
#define _rRW_MISCTL__GIO1CTL_B1_                  0x41ed


s32 gup_hold_ss51_dsp(struct i2c_client *client)
{
    s32 ret = -1;
    s32 retry = 0;
    u8 rd_buf[3];
    
    while(retry++ < 200)
    {
        // step4:Hold ss51 & dsp
        ret = gup_set_ic_msg(client, _rRW_MISCTL__SWRST_B0_, 0x0C);
        if(ret <= 0)
        {
            GTP_DEBUG("Hold ss51 & dsp I2C error,retry:%d", retry);
            continue;
        }
        
        // step5:Confirm hold
        ret = gup_get_ic_msg(client, _rRW_MISCTL__SWRST_B0_, rd_buf, 1);
        if (ret <= 0)
        {
            GTP_DEBUG("Hold ss51 & dsp I2C error,retry:%d", retry);
            continue;
        }
        if (0x0C == rd_buf[GTP_ADDR_LENGTH])
        {
            GTP_DEBUG("[enter_update_mode]Hold ss51 & dsp confirm SUCCESS");
            break;
        }
        GTP_DEBUG("Hold ss51 & dsp confirm 0x4180 failed,value:%d", rd_buf[GTP_ADDR_LENGTH]);
    }
    if(retry >= 200)
    {
        GTP_ERROR("Enter update Hold ss51 failed.");
        return FAIL;
    }
        //DSP_CK and DSP_ALU_CK PowerOn
    ret = gup_set_ic_msg(client, 0x4010, 0x00);
    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]DSP_CK and DSP_ALU_CK PowerOn fail.");
        return FAIL;
    }
    
    //disable wdt
    ret = gup_set_ic_msg(client, _bRW_MISCTL__TMR0_EN, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]disable wdt fail.");
        return FAIL;
    }
    
    //clear cache enable
    ret = gup_set_ic_msg(client, _bRW_MISCTL__CACHE_EN, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]clear cache enable fail.");
        return FAIL;
    }
    
    //set boot from sram
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOTCTL_B0_, 0x02);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]set boot from sram fail.");
        return FAIL;
    }

	//software reboot    
	ret = gup_set_ic_msg(client, _bWO_MISCTL__CPU_SWRST_PULSE, 0x01);
	if (ret <= 0)
	{    
	    GTP_ERROR("[enter_update_mode]software reboot fail.");
	    return FAIL;
	}
    
    return SUCCESS;
}

static kal_bool i2c_read_bytes(struct i2c_client *client, u16 chk_addr,u8 *chk_buf, u32 rd_size)
{
	CTP_I2C_read(chk_addr,chk_buf,rd_size);
}

static kal_bool i2c_write_bytes(struct i2c_client *client, u16 chk_addr,u8 *chk_buf, u32 rd_size)
{
	CTP_I2C_send(chk_addr,chk_buf,rd_size);
}

static u8 gup_check_and_repair(struct i2c_client *client, s32 chk_start_addr, u8 *target_fw, u32 chk_total_length)
{
    s32 ret = 0;
    u32 chked_len = 0;
    u8  chked_times = 0;
    u32 chk_addr = 0;
    u8  chk_buf[GUP_FW_CHK_SIZE];
    u32 rd_size = 0;
    u8  flag_err = 0;
    s32 i = 0;
    
    chk_addr = chk_start_addr;
    while((chked_times < MAX_CHECK_TIMES) && (chked_len < chk_total_length))
    {
        rd_size = chk_total_length - chked_len;
        if(rd_size >= GUP_FW_CHK_SIZE)
        {
            rd_size = GUP_FW_CHK_SIZE;
        }
    #if GTP_SUPPORT_I2C_DMA
        ret = i2c_read_bytes(client, chk_addr, chk_buf, rd_size);
    #else
        if (!i)
        {
            ret = i2c_read_bytes(client, chk_addr, chk_buf, rd_size);
        }
        else
        {
            ret = i2c_auto_read(client, chk_buf, rd_size);
        }
    #endif
    
        if(-1 == ret)
        {
            GTP_ERROR("Read chk ram fw i2c error");
            chked_times++;
            continue;
        }
        
        for(i=0; i<rd_size; i++)
        {
            if(chk_buf[i] != target_fw[i])
            {
                GTP_ERROR("Ram pos[0x%04x] checked failed,rewrite.", chk_addr + i);
                i2c_write_bytes(client, chk_addr+i, &target_fw[i], rd_size-i);
                flag_err = 1;
                i = 0;
                break;
            }
        }
        
        if(!flag_err)
        {
            chked_len += rd_size;
            target_fw += rd_size;
            chk_addr += rd_size;
        }
        else
        {
            flag_err = 0;
            chked_times++;
        }      
    }
    
    if(chked_times >= MAX_CHECK_TIMES)
    {
        GTP_ERROR("Ram data check failed.");
        return FAIL;
    }
    return SUCCESS;
}

u8 gtp_fw_startup(struct i2c_client *client)
{
    u8 wr_buf[4];
    s32 ret = 0;
    
    //init sw WDT
    wr_buf[0] = 0xAA;
    ret = i2c_write_bytes(client, 0x8041, wr_buf, 1);
    if (ret < 0)
    {
        GTP_ERROR("I2C error to firmware startup.");
        return FAIL;
    }
    //release SS51 & DSP
    wr_buf[0] = 0x00;
    i2c_write_bytes(client, 0x4180, wr_buf, 1);
    
    //int sync
    gtp_int_sync(20);
    
    //check fw run status
    i2c_read_bytes(client, 0x8041, wr_buf, 1);
    if(0xAA == wr_buf[0])
    {
        GTP_ERROR("IC works abnormally,startup failed.");
        return FAIL;
    }
    else
    {
        GTP_DEBUG("IC works normally,Startup success.");
        wr_buf[0] = 0xAA;
        i2c_write_bytes(client, 0x8041, wr_buf, 1);
        return SUCCESS;
    }
}

#endif // (GTP_COMPATIBLE_MODE || GTP_HOTKNOT_MODE)


#if GTP_COMPATIBLE_MODE

u8 gup_check_fs_mounted(char *path_name)
{
    struct path root_path;
    struct path path;
    int err;
    err = kern_path("/", LOOKUP_FOLLOW, &root_path);

    if (err)
        return FAIL;

    err = kern_path(path_name, LOOKUP_FOLLOW, &path);

    if (err)
        return FAIL;

    if (path.mnt->mnt_sb == root_path.mnt->mnt_sb)
    {
        //-- not mounted
        return FAIL;
    }
    else
    {
        return SUCCESS;
    }
}


s32 gup_enter_update_mode_fl(struct i2c_client *client)
{
    s32 ret = -1;
    //s32 retry = 0;
    //u8 rd_buf[3];
    
    //step1:RST output low last at least 2ms
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 0);
    msleep(2);
    
    //step2:select I2C slave addr,INT:0--0xBA;1--0x28.
    GTP_GPIO_OUTPUT(GTP_INT_PORT, (client->addr == 0x14));
    msleep(2);
    
    //step3:RST output high reset guitar
    GTP_GPIO_OUTPUT(GTP_RST_PORT, 1);
    
    msleep(5);
    
    //select addr & hold ss51_dsp
    ret = gup_hold_ss51_dsp(client);
    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]hold ss51 & dsp failed.");
        return FAIL;
    }
    
    //clear control flag
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_CTL_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]clear control flag fail.");
        return FAIL;
    }
    
    //set scramble
    ret = gup_set_ic_msg(client, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]set scramble fail.");
        return FAIL;
    }
    
    //enable accessing code
    ret = gup_set_ic_msg(client, _bRW_MISCTL__MEM_CD_EN, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]enable accessing code fail.");
        return FAIL;
    }
    
    return SUCCESS;
}


static s32 gup_prepare_fl_fw(char *path, st_fw_head *fw_head)
{
    s32 i = 0;
    s32 ret = 0;
    s32 timeout = 0;
	s32 rLen = 0;
    
    if (!memcmp(path, "update", 6))
    {
        GTP_INFO("Search for Flashless firmware file to update");
        searching_file = 1;
        for (i = 0; i < GUP_SEARCH_FILE_TIMES; ++i)
        {
            if (0 == searching_file)
            {
                GTP_INFO("Force terminate searching file auto update.");
                return FAIL;
            }
            update_msg.file = FS_Open(FL_UPDATE_PATH, FS_READ_ONLY);
            if (IS_ERR(update_msg.file))
            {
                update_msg.file = FS_Open(FL_UPDATE_PATH_SD, FS_READ_ONLY);
                if (IS_ERR(update_msg.file))
                {
                    msleep(2000);
                    continue;
                }
                else
                {
                    path = FL_UPDATE_PATH_SD;
                    break;
                }
            }
            else
            {
                path = FL_UPDATE_PATH;
                break;
            }
        }
        searching_file = 0;
        if (i >= 50)
        {
            GTP_ERROR("Search timeout, update aborted");
            return FAIL;
        }
        else
        {
            _CLOSE_FILE(update_msg.file);
        }
        while (rqst_processing && (timeout++ < 15))
        {
            GTP_INFO("wait for request process completed!");
            msleep(1000);
        }
    }
    
    GTP_INFO("Firmware update file path: %s", path);
    update_msg.file = FS_Open(path, FS_READ_ONLY);
    
    if (IS_ERR(update_msg.file))
    {
        GTP_ERROR("Open update file(%s) error!", path);
        return FAIL;
    }
    
    FS_Seek(update_msg.file, 0, SEEK_SET);
    update_msg.fw_total_len = FS_Seek(update_msg.file, 0, SEEK_END);
    if (sizeof(gtp_hotknot_calibration_section0) != update_msg.fw_total_len)
    {
        GTP_ERROR("Inconsistent firmware size. File size: %d, default fw size: %d", update_msg.fw_total_len, sizeof(gtp_hotknot_calibration_section0));
        _CLOSE_FILE(update_msg.file);
        return FAIL;
    }
    
    GTP_DEBUG("Firmware size: %d", update_msg.fw_total_len);
    FS_Seek(update_msg.file, 0, SEEK_SET);
    FS_Read(update_msg.file, (char*)fw_head, FW_HEAD_LENGTH, &rLen);
    FS_Seek(update_msg.file, 0, SEEK_SET);
    //copy fw file to gtp_hotknot_calibration_section0 array
    ret =  FS_Read(update_msg.file, 
                                (char*)gtp_hotknot_calibration_section0,
                                update_msg.fw_total_len,
                                &rLen);
    if (ret < 0 || rLen != update_msg.fw_total_len)
    {
        GTP_ERROR("Failed to read firmware data from %s, err-code: %d", path, ret);
        ret = FAIL;
    }
    else
    {
        ret = SUCCESS;
    }
    _CLOSE_FILE(update_msg.file);
    return ret;
}

static u8 gup_check_update_file_fl(struct i2c_client *client, st_fw_head *fw_head, char *path)
{
    s32 i = 0;
    s32 fw_checksum = 0;
    s32 ret = 0;
    
    if (NULL != path)
    {
        ret = gup_prepare_fl_fw(path, fw_head);
        if (ret == FAIL)
        {
            return FAIL;
        }
    }
    else
    {
        memcpy(fw_head, gtp_hotknot_calibration_section0, FW_HEAD_LENGTH);
        GTP_INFO("FILE HARDWARE INFO:%02x%02x%02x%02x", fw_head->hw_info[0], fw_head->hw_info[1], fw_head->hw_info[2], fw_head->hw_info[3]);
        GTP_INFO("FILE PID:%s", fw_head->pid);
        fw_head->vid = ((fw_head->vid & 0xFF00) >> 8) + ((fw_head->vid & 0x00FF) << 8);
        GTP_INFO("FILE VID:%04x", fw_head->vid);
    }

    //check firmware legality
    fw_checksum = 0;
    for (i = FW_HEAD_LENGTH; i < (FW_HEAD_LENGTH + update_msg.fw_total_len); i += 2)
    {
        fw_checksum = (gtp_hotknot_calibration_section0[i]<<8) + gtp_hotknot_calibration_section0[i+1];
    }
    
    GTP_DEBUG("firmware checksum:%x", fw_checksum&0xFFFF);
    if(fw_checksum&0xFFFF)
    {
        GTP_ERROR("Illegal firmware file.");
        return FAIL;
    }
    
    return SUCCESS;
}

static u8 gup_download_fw_ss51(struct i2c_client *client, u8 dwn_mode)
{
    s32 ret = 0;

    if(GTP_FL_FW_BURN == dwn_mode)
    {
        GTP_INFO("[download_fw_ss51]Begin download ss51 firmware---->>");
    }
    else
    {
        GTP_INFO("[download_fw_ss51]Begin check ss51 firmware----->>");
    }
    //step1:download FW section 1
    GTP_DEBUG("[download_fw_ss51]step1:download FW section 1");
    ret = gup_set_ic_msg(i2c_client_point, _bRW_MISCTL__SRAM_BANK, 0x00);
    
    if (ret <= 0)
    {
        GTP_ERROR("[download_fw_ss51]select bank0 fail.");
        ret = FAIL;
        goto exit_download_fw_ss51;
    }
    
    
    ret = i2c_write_bytes(client, 0xC000, 
                &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH], FW_DOWNLOAD_LENGTH);   // write the first bank

    if (ret == -1)
    {
        GTP_ERROR("[download_fw_ss51]download FW section 1 fail.");
        ret = FAIL;
        goto exit_download_fw_ss51;
    }
    
    
    if (GTP_FL_FW_BURN == dwn_mode)
    {
        ret = gup_check_and_repair(i2c_client_point, 
                                   0xC000, 
                                   &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH], 
                                   FW_DOWNLOAD_LENGTH);
        if(FAIL == ret)
        {
            GTP_ERROR("[download_fw_ss51]Checked FW section 1 fail.");
            goto exit_download_fw_ss51;
        }
    }
    
    //step2:download FW section 2
    GTP_DEBUG("[download_fw_ss51]step2:download FW section 1");
    ret = gup_set_ic_msg(i2c_client_point, _bRW_MISCTL__SRAM_BANK, 0x01);
    
    if (ret <= 0)
    {
        GTP_ERROR("[download_fw_ss51]select bank1 fail.");
        ret = FAIL;
        goto exit_download_fw_ss51;
    }

    ret = i2c_write_bytes(client, 0xC000, &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH+FW_DOWNLOAD_LENGTH],FW_DOWNLOAD_LENGTH);  // write the second bank

    if (ret == -1)
    {
        GTP_ERROR("[download_fw_ss51]download FW section 2 fail.");
        ret = FAIL;
        goto exit_download_fw_ss51;
    }
    
    if (GTP_FL_FW_BURN == dwn_mode)
    {
        ret = gup_check_and_repair(i2c_client_point, 
                                   0xC000, 
                                   &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH+FW_DOWNLOAD_LENGTH], 
                                   FW_DOWNLOAD_LENGTH);
        
        if(FAIL == ret)
        {
            GTP_ERROR("[download_fw_ss51]Checked FW section 2 fail.");
            goto exit_download_fw_ss51;
        }
    }
    ret = SUCCESS;

exit_download_fw_ss51:
    
    return ret;
}
#if (!GTP_SUPPORT_I2C_DMA)
static s32 i2c_auto_read(struct i2c_client *client,u8 *rxbuf, int len)
{
    u8 retry;
    u16 left = len;
    u16 offset = 0;
    
    struct i2c_msg msg = 
    {
        //.addr = ((client->addr &I2C_MASK_FLAG) | (I2C_ENEXT_FLAG)),
        .addr = ((client->addr &I2C_MASK_FLAG) | (I2C_PUSHPULL_FLAG)),
        .flags = I2C_M_RD,
        .timing = I2C_MASTER_CLOCK
    };
    
    if(NULL == rxbuf)
    {
        return -1;
    }
    
    while (left > 0)
    {
        msg.buf = &rxbuf[offset];

        if (left > MAX_TRANSACTION_LENGTH)
        {
            msg.len = MAX_TRANSACTION_LENGTH;
            left -= MAX_TRANSACTION_LENGTH;
            offset += MAX_TRANSACTION_LENGTH;
        }
        else
        {
            msg.len = left;
            left = 0;
        }

        retry = 0;

        while (i2c_transfer(client->adapter, &msg, 1) != 1)
        {
            retry++;

            if (retry == 20)
            {
                GTP_ERROR("I2C read 0x%X length=%d failed\n", offset, len);
                return -1;
            }
        }
    }
    
    return 0;
}
#endif

static u8 gup_download_fw_dsp(struct i2c_client *client, u8 dwn_mode)
{
    s32 ret = 0;
    
    if(GTP_FL_FW_BURN == dwn_mode)
    {
        GTP_INFO("[download_fw_dsp]Begin download dsp fw---->>");
    }
    else
    {
        GTP_INFO("[download_fw_dsp]Begin check dsp fw---->>");
    }

    //step1:select bank2
    GTP_DEBUG("[download_fw_dsp]step1:select bank2");
    ret = gup_set_ic_msg(client, _bRW_MISCTL__SRAM_BANK, 0x02);

    if (ret <= 0)
    {
        GTP_ERROR("[download_fw_dsp]select bank2 fail.");
        ret = FAIL;
        goto exit_download_fw_dsp;
    }
    
    ret = i2c_write_bytes(client,
                          0xC000,
                          &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH+2*FW_DOWNLOAD_LENGTH],
                          FW_DSP_LENGTH); // write the second bank    
    if (ret == -1)
    {
        GTP_ERROR("[download_fw_dsp]download FW dsp fail.");
        ret = FAIL;
        goto exit_download_fw_dsp;
    }

    if (GTP_FL_FW_BURN == dwn_mode)
    {
        ret = gup_check_and_repair(client, 
                                   0xC000, 
                                   &gtp_hotknot_calibration_section0[FW_HEAD_LENGTH+2*FW_DOWNLOAD_LENGTH], 
                                   FW_DSP_LENGTH);
        
        if(FAIL == ret)
        {
            GTP_ERROR("[download_fw_dsp]Checked FW dsp fail.");
            goto exit_download_fw_dsp;
        }
    
    }
    ret = SUCCESS;

exit_download_fw_dsp:
    
    return ret;
}

s32 gup_fw_download_proc(void *dir, u8 dwn_mode)
{
    s32 ret = 0;
    u8  retry = 0;
    st_fw_head fw_head;
    
    if(GTP_FL_FW_BURN == dwn_mode)
    {
        GTP_INFO("[fw_download_proc]Begin fw download ......");
    }
    else
    {
        GTP_INFO("[fw_download_proc]Begin fw check ......");
    }
    show_len = 0;
    total_len = 100;
    
    ret = gup_check_update_file_fl(i2c_client_point, &fw_head, (char *)dir);
    
    show_len = 10;
    
    if (FAIL == ret)
    {
        GTP_ERROR("[fw_download_proc]check update file fail.");
        goto file_fail;
    }
    
    mt_eint_mask(CUST_EINT_TOUCH_PANEL_NUM);
    if (NULL != dir)
    {
    #if GTP_ESD_PROTECT
        gtp_esd_switch(i2c_client_point, SWITCH_OFF);
    #endif
    }

    ret = gup_enter_update_mode_fl(i2c_client_point);
    show_len = 20;
    
    if (FAIL == ret)
    {
        GTP_ERROR("[fw_download_proc]enter update mode fail.");
        goto download_fail;
    }

    while (retry++ < 5)
    {
        ret = gup_download_fw_ss51(i2c_client_point, dwn_mode);
        show_len = 60;
        if (FAIL == ret)
        {
            GTP_ERROR("[fw_download_proc]burn ss51 firmware fail.");
            continue;
        }

        ret = gup_download_fw_dsp(i2c_client_point, dwn_mode);
        show_len = 80;
        if (FAIL == ret)
        {
            GTP_ERROR("[fw_download_proc]burn dsp firmware fail.");
            continue;
        }

        GTP_INFO("[fw_download_proc]UPDATE SUCCESS.");
        break;
    }

    if (retry >= 5)
    {
        GTP_ERROR("[fw_download_proc]retry timeout,UPDATE FAIL.");
        goto download_fail;
    }

    if (NULL != dir)
    {
        gtp_fw_startup(i2c_client_point);
    #if GTP_ESD_PROTECT
        gtp_esd_switch(i2c_client_point, SWITCH_ON);
    #endif    
    }
    show_len = 100;
    mt_eint_unmask(CUST_EINT_TOUCH_PANEL_NUM);
    return SUCCESS;
    
download_fail:
    if (NULL != dir)
    {
        gtp_fw_startup(i2c_client_point);
    #if GTP_ESD_PROTECT
        gtp_esd_switch(i2c_client_point, SWITCH_ON);
    #endif    
    }
    
file_fail:
    show_len = 200;
    mt_eint_unmask(CUST_EINT_TOUCH_PANEL_NUM);
    return FAIL;
}


static void gup_bit_write(s32 addr, s32 bit, s32 val)
{
    u8 buf;
    i2c_read_bytes(i2c_client_point, addr, &buf, 1);

    buf = (buf & (~((u8)1 << bit))) | ((u8)val << bit);

    i2c_write_bytes(i2c_client_point, addr, &buf, 1);
}

static void gup_clk_count_init(s32 bCh, s32 bCNT)
{
    u8 buf;
    
    //_fRW_MISCTL__MEA_EN = 0; //Frequency measure enable
    gup_bit_write(_fRW_MISCTL__MEA, 0, 0);
    //_fRW_MISCTL__MEA_CLR = 1; //Frequency measure clear
    gup_bit_write(_fRW_MISCTL__MEA, 1, 1);
    //_bRW_MISCTL__MEA_MODE = 0; //Pulse mode
    buf = 0;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__MEA_MODE, &buf, 1);
    //_bRW_MISCTL__MEA_SRCSEL = 8 + bCh; //From GIO1
    buf = 8 + bCh;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__MEA_SRCSEL, &buf, 1);
    //_wRW_MISCTL__MEA_MAX_NUM = bCNT; //Set the Measure Counts = 1
    buf = bCNT;
    i2c_write_bytes(i2c_client_point, _wRW_MISCTL__MEA_MAX_NUM, &buf, 1);
    //_fRW_MISCTL__MEA_CLR = 0; //Frequency measure not clear
    gup_bit_write(_fRW_MISCTL__MEA, 1, 0);
    //_fRW_MISCTL__MEA_EN = 1;
    gup_bit_write(_fRW_MISCTL__MEA, 0, 1);
}

static u32 gup_clk_count_get(void)
{
    s32 ready = 0;
    s32 temp;
    s8  buf[4];

    while ((ready == 0)) //Wait for measurement complete
    {
        i2c_read_bytes(i2c_client_point, _bRO_MISCTL__MEA_RDY, buf, 1);
        ready = buf[0];
    }

    udelay(50);

    //_fRW_MISCTL__MEA_EN = 0;
    gup_bit_write(_fRW_MISCTL__MEA, 0, 0);
    i2c_read_bytes(i2c_client_point, _dRO_MISCTL__MEA_VAL, buf, 4);
    GTP_INFO("Clk_count 0: %2X", buf[0]);
    GTP_INFO("Clk_count 1: %2X", buf[1]);
    GTP_INFO("Clk_count 2: %2X", buf[2]);
    GTP_INFO("Clk_count 3: %2X", buf[3]);

    temp = (s32)buf[0] + ((s32)buf[1] << 8) + ((s32)buf[2] << 16) + ((s32)buf[3] << 24);
    GTP_INFO("Clk_count : %d", temp);
    return temp;
}
u8 gup_clk_dac_setting(int dac)
{
    s8 buf1, buf2;
    
    i2c_read_bytes(i2c_client_point, _wRW_MISCTL__RG_DMY, &buf1, 1);
    i2c_read_bytes(i2c_client_point, _bRW_MISCTL__RG_OSC_CALIB, &buf2, 1);

    buf1 = (buf1 & 0xFFCF) | ((dac & 0x03) << 4);
    buf2 = (dac >> 2) & 0x3f;

    i2c_write_bytes(i2c_client_point, _wRW_MISCTL__RG_DMY, &buf1, 1);
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__RG_OSC_CALIB, &buf2, 1);
    
    return 0;
}

static u8 gup_clk_calibration_pin_select(s32 bCh)
{
    s32 i2c_addr;

    switch (bCh)
    {
        case 0:
            i2c_addr = _fRW_MISCTL__GIO0;
            break;

        case 1:
            i2c_addr = _fRW_MISCTL__GIO1;
            break;

        case 2:
            i2c_addr = _fRW_MISCTL__GIO2;
            break;

        case 3:
            i2c_addr = _fRW_MISCTL__GIO3;
            break;

        case 4:
            i2c_addr = _fRW_MISCTL__GIO4;
            break;

        case 5:
            i2c_addr = _fRW_MISCTL__GIO5;
            break;

        case 6:
            i2c_addr = _fRW_MISCTL__GIO6;
            break;

        case 7:
            i2c_addr = _fRW_MISCTL__GIO7;
            break;

        case 8:
            i2c_addr = _fRW_MISCTL__GIO8;
            break;

        case 9:
            i2c_addr = _fRW_MISCTL__GIO9;
            break;
    }

    gup_bit_write(i2c_addr, 1, 0);
    
    return 0;
}

void gup_output_pulse(int t)
{
    unsigned long flags;
    //s32 i;
    
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
    udelay(10);
    
    local_irq_save(flags);

    mt_set_gpio_out(GTP_INT_PORT, 1);
    udelay(50);
    mt_set_gpio_out(GTP_INT_PORT, 0);
    udelay(t - 50);
    mt_set_gpio_out(GTP_INT_PORT, 1);

    local_irq_restore(flags);

    udelay(20);
    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
}

static void gup_sys_clk_init(void)
{
    u8 buf;
    
    //_fRW_MISCTL__RG_RXADC_CKMUX = 0;
    gup_bit_write(_rRW_MISCTL__ANA_RXADC_B0_, 5, 0);
    //_bRW_MISCTL__RG_LDO_A18_PWD = 0; //DrvMISCTL_A18_PowerON
    buf = 0;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__RG_LDO_A18_PWD, &buf, 1);
    //_bRW_MISCTL__RG_BG_PWD = 0; //DrvMISCTL_BG_PowerON
    buf = 0;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__RG_BG_PWD, &buf, 1);
    //_bRW_MISCTL__RG_CLKGEN_PWD = 0; //DrvMISCTL_CLKGEN_PowerON
    buf = 0;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__RG_CLKGEN_PWD, &buf, 1);
    //_fRW_MISCTL__RG_RXADC_PWD = 0; //DrvMISCTL_RX_ADC_PowerON
    gup_bit_write(_rRW_MISCTL__ANA_RXADC_B0_, 0, 0);
    //_fRW_MISCTL__RG_RXADC_REF_PWD = 0; //DrvMISCTL_RX_ADCREF_PowerON
    gup_bit_write(_rRW_MISCTL__ANA_RXADC_B0_, 1, 0);
    //gup_clk_dac_setting(60);
    //_bRW_MISCTL__OSC_CK_SEL = 1;;
    buf = 1;
    i2c_write_bytes(i2c_client_point, _bRW_MISCTL__OSC_CK_SEL, &buf, 1);
}

u8 gup_clk_calibration(void)
{
    //u8 buf;
    //u8 trigger;
    s32 i;
    struct timeval start, end;
    s32 count;
    s32 count_ref;
    s32 sec;
    s32 usec;
    s32 ret = 0;
    //unsigned long flags;

    //buf = 0x0C; // hold ss51 and dsp
    //i2c_write_bytes(i2c_client_point, _rRW_MISCTL__SWRST_B0_, &buf, 1);
    ret = gup_hold_ss51_dsp(i2c_client_point);
    if (ret <= 0)
    {
        GTP_ERROR("[gup_clk_calibration]hold ss51 & dsp failed.");
        return FAIL;
    }

    //_fRW_MISCTL__CLK_BIAS = 0; //disable clock bias
    gup_bit_write(_rRW_MISCTL_RG_DMY83, 7, 0);

    //_fRW_MISCTL__GIO1_PU = 0; //set TOUCH INT PIN MODE as input
    gup_bit_write(_rRW_MISCTL__GIO1CTL_B2_, 0, 0);

    //_fRW_MISCTL__GIO1_OE = 0; //set TOUCH INT PIN MODE as input
    gup_bit_write(_rRW_MISCTL__GIO1CTL_B1_, 1, 0);

    //buf = 0x00;
    //i2c_write_bytes(i2c_client_point, _rRW_MISCTL__SWRST_B0_, &buf, 1);
    //msleep(1000);

    GTP_INFO("CLK calibration GO");
    gup_sys_clk_init();
    gup_clk_calibration_pin_select(1);//use GIO1 to do the calibration

    GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
 
    for (i = INIT_CLK_DAC; i < MAX_CLK_DAC; i++)
    {
        if (tpd_halt)
        {
            i = 80;     // if sleeping while calibrating main clock, set it default 80
            break;
        }
        GTP_INFO("CLK calibration DAC %d", i);

        gup_clk_dac_setting(i);
        gup_clk_count_init(1, CLK_AVG_TIME);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #else
        GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
        
        //local_irq_save(flags);
        do_gettimeofday(&start);
        mt_set_gpio_out(GTP_INT_PORT, 1);
        //local_irq_restore(flags);
        
        msleep(1);
        mt_set_gpio_out(GTP_INT_PORT, 0);
        msleep(1);
        
        //local_irq_save(flags);
        do_gettimeofday(&end);
        mt_set_gpio_out(GTP_INT_PORT, 1);
        //local_irq_restore(flags);
        
        count = gup_clk_count_get();
        udelay(20);
        GTP_GPIO_OUTPUT(GTP_INT_PORT, 0);
        
        usec = end.tv_usec - start.tv_usec;
        sec = end.tv_sec - start.tv_sec;
        count_ref = 60 * (usec+ sec * MILLION);//60= 60Mhz * 1us
        
        GTP_DEBUG("== time %d, %d, %d", sec, usec, count_ref);
        
        if (count > count_ref)
        {
            GTP_DEBUG("== count_diff %d", count - count_ref);
            break;
        }

    #endif
    }

    //clk_dac = i;

    //gtp_reset_guitar(i2c_client_point, 20);

#if 0//for debug
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

    GTP_GPIO_AS_INT(GTP_INT_PORT);
    return i;
}

#endif //GTP_COMPATIBLE_MODE


#if GTP_HOTKNOT_MODULE

#define CALIBRATION_HEADER_LEN 14

static u32 current_calibration_length = 0;

#if GTP_AUTO_UPDATE_HOTKNOT 

u8 *gup_load_calibration_from_file(char *filepath)
{
    struct file *calibration_file = NULL;
	mm_segment_t old_fs;
	long len = 0;
    u8 *buffer = NULL;
	s32 rLen = 0;

	if(filepath == NULL)
	{
		GTP_ERROR("[load_calibration_file]filepath: NULL");
		goto load_calibration_file_exit;
	}
    
    calibration_file = FS_Open(filepath, FS_READ_ONLY);
    if (calibration_file == NULL || IS_ERR(calibration_file))
    {
        GTP_ERROR("[load_calibration_file]Failed to open: %s", filepath);
		goto load_calibration_file_exit;
    }
    FS_Seek(calibration_file, 0, SEEK_SET);
    len = FS_Seek(calibration_file, 0, SEEK_END);
    if(len<1024)
    {
        GTP_ERROR("[load_calibration_file]Calibration is too short: %ld", len);
        goto load_calibration_file_failed;
    }
    buffer = (u8 *)kmalloc(sizeof(u8) * len, GFP_KERNEL);
    if(buffer == NULL)
    {
        GTP_ERROR("[load_calibration_file]Failed to allocate buffer: %ld", len);
        goto load_calibration_file_failed;
    }
    
    memset(buffer, 0, sizeof(u8) * len);
    
    FS_Seek(calibration_file, 0, SEEK_SET);
    FS_Read(calibration_file, buffer, len, & rLen);

    GTP_ERROR("[load_calibration_file]Load from file success: %ld %s", len, filepath);


load_calibration_file_failed:
    FS_Close(calibration_file, NULL);

load_calibration_file_exit:
    return buffer;
}
#endif

s32 gup_check_section(u8 *section, u32 length)
{
    u32 i = 0;
    u32 section_checksum = 0;
    u16 temp;
    
    for(i=0; i<length; i+=2)
    {
        temp = (section[i]<<8) + section[i+1];
        section_checksum += temp;
    }
    
    GTP_DEBUG("section checksum: %4X", section_checksum&0xFFFF);
    if(section_checksum&0xFFFF)
    {
        return FAIL;
    }
    return SUCCESS;
}

s32 gup_enter_update_mode_noreset(void)
{
    s32 ret = FAIL;
	
	// disable watchdog
    ret = gup_set_ic_msg(i2c_client_point, _bRW_MISCTL__TMR0_EN, 0x00);
    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]disable wdt fail.");
        return FAIL;
    }	
    //select addr & hold ss51_dsp
    ret = gup_hold_ss51_dsp(i2c_client_point);
    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]hold ss51 & dsp failed.");
        return FAIL;
    }
    
    //clear control flag
    ret = gup_set_ic_msg(i2c_client_point, _rRW_MISCTL__BOOT_CTL_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]clear control flag fail.");
        return FAIL;
    }
    
    //set scramble
    ret = gup_set_ic_msg(i2c_client_point, _rRW_MISCTL__BOOT_OPT_B0_, 0x00);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]set scramble fail.");
        return FAIL;
    }
    
    //enable accessing code
    ret = gup_set_ic_msg(i2c_client_point, _bRW_MISCTL__MEM_CD_EN, 0x01);

    if (ret <= 0)
    {
        GTP_ERROR("[enter_update_mode]enable accessing code fail.");
        return FAIL;
    }
    
    return SUCCESS;
}

s32 gup_load_by_bank(u8 bank, u8 need_check, u8 *fw, u32 length)
{
    s32 ret = FAIL;
    s32 retry = 0;

    GTP_DEBUG("[load_by_bank]begin load [bank:%d,length:%d].",bank,length);    
    while(retry++ < 5)
    {
        ret = gup_set_ic_msg(i2c_client_point, _bRW_MISCTL__SRAM_BANK, bank);    
        if (ret <= 0)
        {
            GTP_ERROR("[load_by_bank]select bank fail.");
            continue;
        }
            
        ret = i2c_write_bytes(i2c_client_point, 0xC000,fw, length);
        if (ret == -1)
        {
            GTP_ERROR("[load_by_bank]load bank fail.");
            continue;
        }    
        
		if(need_check)
		{
			ret = gup_check_and_repair(i2c_client_point, 0xC000, fw, length);
			if(FAIL == ret)
			{
				GTP_ERROR("[load_by_bank]checked bank fail.");
				continue;
			}
		}
        break;
    }
    if(retry<5)
    {
        return SUCCESS;
    }
    else
    {
        return FAIL;
    }
}

s32 gup_load_calibration(u8 *data, s32 length, u8 need_check)
{
    s32 ret = -1;
    u8 bank = 0;

    //disable irq & ESD protect 
    mt_eint_mask(CUST_EINT_TOUCH_PANEL_NUM);
#if GTP_ESD_PROTECT
    gtp_esd_switch(i2c_client_point, SWITCH_OFF);
#endif
    ret = gup_enter_update_mode_noreset();
    if (FAIL == ret)
    {
        goto gup_load_calibration_exit;
    }
	GTP_DEBUG("enter update mode success.");
    while(length > 0)
    {
        u32 len = length >16*1024? 16*1024:length;
        ret = gup_load_by_bank(bank, need_check, &data[bank*16*1024], len);
        if(FAIL == ret)
        {
            goto gup_load_calibration_exit;
        }
		GTP_DEBUG("load bank%d  length:%d  success.", bank, len);
        bank++;
        length -= len;
    }
    
    ret = gtp_fw_startup(i2c_client_point);

gup_load_calibration_exit:
#if GTP_ESD_PROTECT
#if FLASHLESS_FLASH_WORKROUND

#else
    gtp_esd_switch(i2c_client_point, SWITCH_ON);
#endif
#endif
    mt_eint_unmask(CUST_EINT_TOUCH_PANEL_NUM);
    return ret;    
}

s32 gup_load_calibration2(void)
{
    s32 ret = -1;
    u8 *section = NULL;
    u32 is_load_from_file = 0;
    u32 length = 0;

	GTP_INFO("[gup_load_calibration2] Load calibration2.");	

	section = gtp_hotknot_calibration_section2;
	
#if GTP_AUTO_UPDATE_HOTKNOT    
    section = gup_load_calibration_from_file( FX_SYSTEM_PATH );
    if(section == NULL)
    {
        section = gtp_hotknot_calibration_section2;
		GTP_INFO("[gup_load_calibration2] Use default calibration2.");			
    }
	else
	{
	    is_load_from_file = 1;
	}
#endif

    length = section[0]*256*256*256+
             section[1]*256*256+
             section[2]*256+
             section[3];

	if(length > 32*1024 || length < 4*1024 )
	{
		GTP_ERROR("[gup_load_calibration2]calibration2's length is invalid.");
		goto load_calibration2_exit;
	}
			 
    ret = gup_check_section(&section[CALIBRATION_HEADER_LEN],length);
    if(ret == FAIL)
    {
        GTP_ERROR("[gup_load_calibration2]calibration2's checksum is error.");
        goto load_calibration2_exit;
    }

    current_calibration_length = length;
    
    ret = gup_load_calibration(&section[CALIBRATION_HEADER_LEN], length, 1);
    
load_calibration2_exit:

    if(is_load_from_file)
    {
        kfree(section);
    }
    
    return ret;
}


s32 gup_load_calibration1(void)
{
    s32 ret = -1;
    u8 *section = NULL;
    u32 is_load_from_file = 0;
    u32 length = 0;
    
    load_fw_process = 1;

	GTP_INFO("[load_calibration1] Load calibration1.");

    section = gtp_hotknot_calibration_section1;
	
#if GTP_AUTO_UPDATE_HOTKNOT  	
    section = gup_load_calibration_from_file( HOTKNOT_SYSTEM_PATH );
    if(section == NULL)
    {
        section = gtp_hotknot_calibration_section1;
		GTP_INFO("[load_calibration1] Use default calibration1.");
    }
	else
	{
        is_load_from_file = 1;	
	}
#endif

    length = section[0]*256*256*256+
             section[1]*256*256+
             section[2]*256+
             section[3];
	if(length > 32*1024 || length < 4*1024 )
	{
		GTP_ERROR("[load_calibration1]calibration1's length is invalid.");
		goto load_calibration1_exit;
	}

    ret = gup_check_section(&section[CALIBRATION_HEADER_LEN],length);
    if(ret == FAIL)
    {
        GTP_ERROR("[load_calibration1]calibration1's checksum is error.");
        goto load_calibration1_exit;
    }

    current_calibration_length = length;

    ret = gup_load_calibration(&section[CALIBRATION_HEADER_LEN], length, 0);
    
load_calibration1_exit:

    if(is_load_from_file)
    {
        kfree(section);
    }
    
    return ret;

}

s32 gup_recovery_calibration0(void)
{
    s32 ret = -1;
    u8 *section = NULL;
    u32 is_load_from_file = 0;
    u32 length = 0;
    
	GTP_INFO("[recovery_calibration0] Recovery calibration0.");
    
    if(gtp_chip_type == CHIP_TYPE_GT9)
    {
	    load_fw_process = 0;
        gtp_reset_guitar(i2c_client_point,5);
        return SUCCESS;
    }

	
#if GTP_AUTO_UPDATE_HOTKNOT
	section = gtp_hotknot_calibration_section0;
	
    section = gup_load_calibration_from_file(MAIN_SYSTEM_PATH);
    if(section == NULL)
    {
        section = gtp_hotknot_calibration_section0;
		GTP_INFO("[recovery_calibration0]Use default calibration0.");
    }
	else
	{
	    is_load_from_file = 1;
	}
#endif

	if(section[0]==0x00&&section[1]==0x90&&section[2]==0x06&&section[3]==0x00)
	{
		length = 36*1024;
	}
	else
	{
		length = section[0]*256*256*256+
				 section[1]*256*256+
				 section[2]*256+
				 section[3];
	}
	if(length > 36*1024 || length < 16*1024 )
	{
		GTP_ERROR("[recovery_calibration0]calibration0's length is invalid.");
		goto recovery_calibration0_exit;
	}
	
    ret = gup_check_section(&section[CALIBRATION_HEADER_LEN],length);
    if(ret == FAIL)
    {
        GTP_ERROR("[recovery_calibration0]calibration0's checksum is error.");
        goto recovery_calibration0_exit;
    }

    if(current_calibration_length == 0)
    {
        current_calibration_length = length;
    }
	
	GTP_INFO("[recovery_calibration0] Recovery length: %d.", current_calibration_length);
	
    ret = gup_load_calibration(&section[CALIBRATION_HEADER_LEN], current_calibration_length, 0);
	
#if (FLASHLESS_FLASH_WORKROUND && GTP_ESD_PROTECT)
    gtp_esd_switch(i2c_client_point, SWITCH_ON);
#endif 
  
recovery_calibration0_exit:

    if(is_load_from_file)
    {
        kfree(section);
    }
    
	load_fw_process = 0;
    return ret;

}

s32 gup_load_calibration0(char *filepath)
{
    s32 ret = -1;
    u8 *section = NULL;
    u32 is_load_from_file = 0;
    u32 length = 0;
    
	GTP_INFO("[load_calibration0] Load calibration0.");
	
#if GTP_AUTO_UPDATE_HOTKNOT  

	if(filepath != NULL)
	{
		section = gup_load_calibration_from_file(filepath);
		if(section == NULL)
		{
			GTP_INFO("[load_calibration0]can not open file: %s", filepath);
			goto load_calibration0_exit;
		}
		else
		{
			is_load_from_file = 1;
		}
	}
	else
	{
		section = gtp_hotknot_calibration_section0;
	}
    section = gup_load_calibration_from_file(filepath);
    if(section == NULL)
    {
        if(gtp_chip_type == CHIP_TYPE_GT9)
			section = gtp_default_FW;
		else
        	section = gtp_hotknot_calibration_section0;
		GTP_INFO("[load_calibration0]Use default calibration0. type:%d", gtp_chip_type);
    }
	else
	{
	    is_load_from_file = 1;
	}
#endif
	
	if(section[0]==0x00&&section[1]==0x90&&section[2]==0x06&&section[3]==0x00)
	{
		length = 36*1024;
	}
	else
	{
		length = section[0]*256*256*256+
				 section[1]*256*256+
				 section[2]*256+
				 section[3];
		if(length > 36*1024)
		{
			length = 36*1024;
		}
	}
    ret = gup_check_section(&section[CALIBRATION_HEADER_LEN],length);
    if(ret == FAIL)
    {
        GTP_ERROR("[load_calibration0]calibration0's checksum is error.");
        goto load_calibration0_exit;
    }
    GTP_INFO("[load_calibration0]calibration0 length: %d.", length);
    
	//memcpy(gtp_hotknot_calibration_section0, section, length);
	
	ret = gup_load_calibration(&section[CALIBRATION_HEADER_LEN], length, 1);
    show_len = 100;

#if (FLASHLESS_FLASH_WORKROUND && GTP_ESD_PROTECT)
    gtp_esd_switch(i2c_client_point, SWITCH_ON);
#endif 

load_calibration0_exit:

    if(is_load_from_file)
    {
        kfree(section);
    }

    return ret;
}

#endif //GTP_HOTKNOT_MODULE

#endif
//*************** For GT9XXF End ***********************//
