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

/*******************************************************************************
 * Filename:
 * ---------
 * CommSettingSpof.c
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 *   Scheduled power on off setting for IOT
 *
 * Author:
 * -------
 * 
 * 
 *==============================================================================*/


/***************************************************************************** 
 * Include
 *****************************************************************************/
#if 1
#include "mmi_features.h"
#include "mmi_include.h"
#include "CommSettings.h"
#include "CommSettingSpof.h"
#include "DateTimeType.h"
#include "ReminderSrvGprot.h"
#include "mmi_rp_srv_general_setting_def.h"
#include "mmi_rp_srv_reminder_def.h"
#include "Nvram_common_defs.h"
#include "ShutdownSrvGprot.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Variables
 *****************************************************************************/
spof_nvram_struct AppSponList[NUM_OF_SPOF];

/***************************************************************************** 
 * Function
 *****************************************************************************/
static void app_spof_init_nvram(void);
static void app_spof_reinit_queue(void);
static void app_spon_expiry_handler(U8 sponIndex, BOOL power_on);
static void app_spoff_expiry_handler(U8 index, BOOL power_on);


int app_set_spof_status(operationTypesSchedulePowerOnOff operation, const spof_nvram_struct* in_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    spof_nvram_struct data = *in_data;
	S16 error;
	U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];
	MYTIME time, newTime;
	U32 index;            //scheduled power on/off list index
	srv_reminder_type type = SRV_REMINDER_TYPE_SPON;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettingSpof.c]app_set_spof_status.");
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_set_spof_status.type:%d, status:%d, Hour:%d, Min:%d.", data.Type, data.Status, data.Hour, data.Min);

	index = data.Type;   // 0: APP_SPOF_POWERON; 1:APP_SPOF_POWEROFF
	
    // Check if it is conflict schedule
    if (data.Status == APP_SPOF_ENABLE)
	{
	    if (data.Type == APP_SPOF_POWERON)
	    {
			if (AppSponList[1].Status == APP_SPOF_ENABLE 
                && AppSponList[1].Hour == data.Hour
                && AppSponList[1].Min == data.Min)
        	{
        	    return SETTING_RESULT_FAIL;
        	}
		}
		else if (data.Type == APP_SPOF_POWEROFF)
		{
			if (AppSponList[0].Status == APP_SPOF_ENABLE 
                && AppSponList[0].Hour == data.Hour
                && AppSponList[0].Min == data.Min)
        	{
        	    return SETTING_RESULT_FAIL;
        	}
		}
	}

    AppSponList[index] = data;
	memcpy(nvram_buf, AppSponList, sizeof(AppSponList));
    WriteRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
	
    // set to reminder service
    switch (AppSponList[index].Type)
	{
	case APP_SPOF_POWERON:
		type = SRV_REMINDER_TYPE_SPON;
		break;
	case APP_SPOF_POWEROFF:
		type = SRV_REMINDER_TYPE_SPOF;
		break;
	default:
		ASSERT(0);
	}
    
    srv_reminder_cancel(type, data.Type);
    if (AppSponList[index].Status != APP_SPOF_ENABLE)
	{
	    return SETTING_RESULT_OK;
	}
    
    DTGetRTCTime(&time);
    time.nMin = AppSponList[index].Min;
    time.nHour = AppSponList[index].Hour;
    time.nSec = 0;
    
    newTime = srv_reminder_calc_time(&time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[IoTSpof.c] setSchedule type %d %d:%d:%d", type, newTime.nHour, newTime.nMin, newTime.nDay);
    srv_reminder_set(type, &newTime, index);
    return SETTING_RESULT_OK;
}



void app_spof_init_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    U8 nvram_buf[NVRAM_ALM_SPOF_DATA_SIZE];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettingSpof.c]app_spon_init_nvram.");
    ReadRecord(NVRAM_EF_ALM_SPOF_DATA_LID, 1, &nvram_buf, NVRAM_ALM_SPOF_DATA_SIZE, &error);
    memcpy(AppSponList, nvram_buf, sizeof(AppSponList));

    /* zero initialized */
    if (AppSponList[0].Hour > NUM_HRS_DAY)
    {
        memset(AppSponList, 0, sizeof(AppSponList));
    }

	AppSponList[0].Type = APP_SPOF_POWERON;
	AppSponList[1].Type = APP_SPOF_POWEROFF;
}


/*****************************************************************************
 * FUNCTION
 *  app_spof_reinit_queue
 * DESCRIPTION
 *  Reinit SPOF to reminder queue
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void app_spof_reinit_queue(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spof_reinit_queue");    
    for (i = 0; i < APP_SPON_NUM; i++)
    {
        if (AppSponList[i].Status == APP_SPOF_ENABLE)
        {
            /* save the alarm in the nvram */
            MYTIME set_time, calc_time; 
            srv_reminder_type type;

            DTGetRTCTime(&set_time);
            set_time.nMin = AppSponList[i].Min;
            set_time.nHour = AppSponList[i].Hour;
            set_time.nSec = 0;
            calc_time = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
        
            if (AppSponList[i].Type == APP_SPOF_POWERON)
            {
                type = SRV_REMINDER_TYPE_SPON;
            }
            else
            {
                type = SRV_REMINDER_TYPE_SPOF;
            }
            srv_reminder_set(type, &calc_time, i);
        }
		
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spof_reinit_queue id: %d, status: %d, type: %d", i, AppSponList[i].Status, AppSponList[i].Type); 
        MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spof_reinit_queue hour: %d, min: %d", AppSponList[i].Hour, AppSponList[i].Min); 
    }

}


/*****************************************************************************
 * FUNCTION
 *  app_spon_expiry_handler
 * DESCRIPTION
 *  CallBack handler to execute SPON expiry.
 * PARAMETERS
 *  sponIndex       [IN]                 
 *  power_on        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void app_spon_expiry_handler(U8 sponIndex, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME set_time, resTime; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spon_expiry_handler %d, %d", sponIndex, power_on);

    DTGetRTCTime(&set_time);
    set_time.nMin = AppSponList[sponIndex].Min;
    set_time.nHour = AppSponList[sponIndex].Hour;
    set_time.nSec = 0;
	
    resTime = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    srv_reminder_set(SRV_REMINDER_TYPE_SPON, &resTime, sponIndex);

	if (power_on)
    {
        srv_reminder_notify_finish(MMI_FALSE);
    }
    else
    {
        srv_reminder_util_send_pwron();
    }
}


/*****************************************************************************
 * FUNCTION
 *  app_spoff_expiry_handler
 * DESCRIPTION
 *  CallBack handler to execute SPOF expiry.
 * PARAMETERS
 *  index           [IN]                
 *  power_on        [IN]     
 *  U8(?)           [IN]        Index of alarm item
 *  BOOL(?)         [IN]        Power status
 * RETURNS
 *  void
 *****************************************************************************/
static void app_spoff_expiry_handler(U8 index, BOOL power_on)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MYTIME set_time, resTime; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spoff_expiry_handler %d, %d", index, power_on);    
 
    DTGetRTCTime(&set_time);
    set_time.nMin = AppSponList[index].Min;
    set_time.nHour = AppSponList[index].Hour;
    set_time.nSec = 0;
	
    resTime = srv_reminder_calc_time(&set_time, SRV_REMINDER_REPEAT_EVERYDAY, 0);
    srv_reminder_set(SRV_REMINDER_TYPE_SPOF, &resTime, index);
	
    if (power_on)
    {
        srv_reminder_notify_finish(MMI_FALSE);
        srv_shutdown_normal_start(0);
    }
    else
    {
        srv_reminder_notify_finish(MMI_FALSE);        
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_spof_reminder_srv_proc
 * DESCRIPTION
 *  Proc function for reminder service 
 * PARAMETERS
 *  
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret app_spof_reminder_srv_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_reminder_evt_struct *reminder_evt = (srv_reminder_evt_struct*)evt;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spof_reminder_srv_proc id (%d)", evt->evt_id);
    MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "app_spof_reminder_srv_proc type (%d)", reminder_evt->reminder_type);
    if ((reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPON 
         && reminder_evt->reminder_type != SRV_REMINDER_TYPE_SPOF
         && reminder_evt->reminder_type != SRV_REMINDER_TYPE_TOTAL) 
        || reminder_evt->evt_id != EVT_ID_SRV_REMINDER_NOTIFY)
	{
	    return MMI_RET_OK;
	}
    switch (reminder_evt->notify)
	{
    case SRV_REMINDER_NOTIFY_INIT:
	{
        app_spof_init_nvram();
        break;
    }  
	
    case SRV_REMINDER_NOTIFY_EXPIRY:
    {
        if (reminder_evt->reminder_type == SRV_REMINDER_TYPE_SPON)
    	{
    	    app_spon_expiry_handler(reminder_evt->usr_data, !reminder_evt->pwr_off);
    	}
        else
        {
    	    app_spoff_expiry_handler(reminder_evt->usr_data, !reminder_evt->pwr_off);            
        }
        break;
    }
        
    case SRV_REMINDER_NOTIFY_REINIT:
	{
        app_spof_reinit_queue();
        break;
    } 
	
	default:
		break;
	}
    return MMI_RET_OK;
}

#endif /*__IOT__*/

