/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  TipAppMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the tip application.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

				  
#ifdef __MMI_BLE_TIP_SUPPORT__

#include "TipAppGprot.h"
#include "TipAppProt.h"
#include "TipAppMain.h"
#include "mmi_rp_app_tipapp_def.h"
#include "TipcSrv.h"
#include "DateTimeGprot.h"
#include "BtcmSrvGprot.h"


#include "GpioSrvGprot.h"
#include "wgui_softkeys.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "CommonScreens.h"
#include "MMI_conn_app_trc.h"
#include "TouchScreenGprot_Int.h"
#include "MMI_common_app_trc.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "BootupSrvGprot.h"
#include "IdleGprot.h"
#include "gui_effect_oem.h"
#include "GeneralSettingSrvGprot.h"
#include "TimeSrvGprot.h"
#include "PhbSrvGprot.h"


/****************************************************************************
 * Global and define
 ****************************************************************************/
typedef struct
{
	// Exact Time 256
	U16 year;
	U8 month;
	U8 day;
	U8 hours;
	U8 minutes;
	U8 seconds;
	U8 day_of_week;
	U8 frac_256;

	/*Adjust Reason*/
	U8 adj_reason;
	/* Reserved bytes*/
	U8 rsv01;
	U8 rsv02;
}tipc_time_struct;
static void *s_tipc_cntx = NULL;
static tipc_time_struct s_tipc_data = {0};
static mmi_tipc_cntx_struct g_mmi_tipc_cntx;


#ifdef __MMI_WEARABLE_DEVICE_SETTING__
extern MMI_BOOL mmi_get_time_autosync_status(void);
#endif  //__MMI_WEARABLE_DEVICE_SETTING__

/*****************************************************************************
* FUNCTION
*  mmi_tipc_cm_notify_hdlr
* DESCRIPTION
* 
* PARAMETERS
*  void
*
* RETURNS
*  void
*****************************************************************************/
void mmi_tipc_cm_notify_hdlr(U32 event, void *args)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // BT power on
    if (SRV_BT_CM_EVENT_BLE_ACTIVATE == event)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_REGISTER);
        srv_tipc_register(mmi_bt_tip_register_cb);
    }
    // BT power off
    else if (SRV_BT_CM_EVENT_BEGIN_DEACTIVATE == event)
    {
        if(s_tipc_cntx)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_DEREGISTER);
            srv_tipc_deregister(s_tipc_cntx);
        }
    }
}


/*****************************************************************************
* FUNCTION
*  mmi_tipc_init
* DESCRIPTION
*  This function is to enable tip client
* PARAMETERS
*  void
*
* RETURNS
*  void
*****************************************************************************/
void mmi_tipc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&g_mmi_tipc_cntx, 0x00, sizeof(mmi_tipc_cntx_struct));

#ifdef __MMI_WEARABLE_DEVICE_SETTING__
    g_mmi_tipc_cntx.sync_enable = mmi_get_time_autosync_status();
#else
    g_mmi_tipc_cntx.sync_enable = MMI_FALSE;
#endif
    srv_bt_cm_set_notify(mmi_tipc_cm_notify_hdlr, (SRV_BT_CM_EVENT_BLE_ACTIVATE | SRV_BT_CM_EVENT_BEGIN_DEACTIVATE), NULL);
}


/*****************************************************************************
* FUNCTION
*  mmi_bt_enable_tip_to_sync_time
* DESCRIPTION
*  This function is to enable tip client
* PARAMETERS
*  void
*
*
* RETURNS
*  void
*****************************************************************************/
void mmi_bt_enable_tip_to_sync_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_tipc_cntx.sync_enable = MMI_TRUE;
    srv_tipc_get_time(s_tipc_cntx);
}
void mmi_bt_tip_register_cb(void *app_cntx, tipc_event_type event, OS_STATUS status, void *data)
{
	tipc_date_time_struct *tipc_data = (tipc_date_time_struct *)data;
    srv_setting_time_format_enum cur, sp_cur;
    U32 tmp = 0;
    srv_time_update_tf_struct evt;

	switch (event)
	{
		case TIPC_EVENT_REGISTER_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_REGISTER_CB,status);
			if ((OS_STATUS_SUCCESS == status) && (NULL != app_cntx) )
			{
				s_tipc_cntx = app_cntx;	
			}
			else
			{
				/*error popup*/ 	  	
			}  
		}
        break;
		case TIPC_EVENT_TIME_INFO_RESULT:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_TIME_INFO,status);
			if ((OS_STATUS_SUCCESS == status) && (s_tipc_cntx == app_cntx) && (NULL != app_cntx) )
			{
			    memset(&s_tipc_data,0,sizeof(tipc_time_struct));
				
				s_tipc_data.year = tipc_data->year;
				s_tipc_data.month = tipc_data->month;
				s_tipc_data.day = tipc_data->day;
				s_tipc_data.hours = tipc_data->hours;
				s_tipc_data.minutes = tipc_data->minutes;
				s_tipc_data.seconds = tipc_data->seconds;
				s_tipc_data.day_of_week = tipc_data->day_of_week;/* 0=Sunday */
				s_tipc_data.frac_256 = tipc_data->frac_256;
				s_tipc_data.adj_reason = tipc_data->adj_reason;
				mmi_bt_tip_noti_recv_update_time(&s_tipc_data);
				
			}
			else
			{
				/*error popup*/ 	  	
			}  
		}
        break;
		case TIPC_EVENT_DEREGISTER_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_DEREGISTER_CB,status);
			if (OS_STATUS_SUCCESS == status)
			{
                /*release buffer*/
				if (s_tipc_cntx)
				{
					s_tipc_cntx = NULL;
				}
			    memset(&s_tipc_data,0,sizeof(tipc_time_struct));

                g_mmi_tipc_cntx.tipc_connect = MMI_FALSE;
			}
			else
			{
				/*error popup*/ 	  	
			}  
		}
        break;
        case TIPC_EVENT_CONNECT_RESULT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G7_BT, "[BLE_TIPAPP]TIPC_EVENT_CONNECT_RESULT--status: %d\n", status);

            if (OS_STATUS_SUCCESS == status)
            {
                g_mmi_tipc_cntx.tipc_connect = MMI_TRUE;
            }
            else
            {
                g_mmi_tipc_cntx.tipc_connect = MMI_FALSE;
            }

            break;
        }
        case TIPC_EVENT_TIME_TF:
        {
            if (g_mmi_tipc_cntx.sync_enable)
            {
                tmp = (U32) data;
                if (tmp == 0)
                {
                    sp_cur = SETTING_TIME_FORMAT_12_HOURS;
                }
                else if (tmp == 1)
                {
                    sp_cur = SETTING_TIME_FORMAT_24_HOURS;
                }
                else
                {
                    sp_cur = SETTING_TIME_FORMAT_12_HOURS;
                }

                cur = srv_setting_get_time_format();

                kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G7_BT, "[BLE_TIPAPP]TIME_TF--tmp: %d, cur: %d\n", tmp, cur);

                if (cur != sp_cur)
                {
                    srv_setting_set_time_format(sp_cur);
                    MMI_FRM_INIT_EVENT(&evt, EVT_ID_GATT_UPDATE_TF);
                    MMI_FRM_CB_EMIT_EVENT(&evt);
                }
            }
            break;
        }
		default :
			break;
	}     
}
void mmi_bt_tip_noti_recv_update_time(void* tipc_data)
{
    tipc_time_struct* time_data = (tipc_time_struct*)tipc_data;
    srv_tip_update_time_struct evt;
    applib_time_struct local_time;
    S32 ret = 0;

    memset(&local_time,0,sizeof(applib_time_struct));

    local_time.nYear = time_data->year;
    local_time.nMonth = time_data->month;
    local_time.nDay = time_data->day;
    local_time.nHour = time_data->hours;
    local_time.nMin = time_data->minutes;
    local_time.nSec = time_data->seconds;
    local_time.DayIndex = time_data->day_of_week;/* 0=Sunday */

    if (g_mmi_tipc_cntx.sync_enable)
    {
        if (local_time.nYear >= 2030 || local_time.nYear < 2000)
        {
            ret = -2;
        }
        else
        {
            mmi_dt_set_rtc_dt((MYTIME*)&local_time);

            MMI_FRM_INIT_EVENT(&evt, EVT_ID_TIP_UPDATE_TIME);
            MMI_FRM_CB_EMIT_EVENT(&evt);
            ret = 1;
        }
    }
    else
    {
        ret = -1;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_TIP_UPDATE_TIME);
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[SrvTime] APP_update_time--%d\n", ret);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_disable_tip_to_sync_time
 * DESCRIPTION
 *  This function is to unregister service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_disable_tip_to_sync_time(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_tipc_cntx.sync_enable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tipc_is_connected
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 *
 * RETURNS
 *
 *****************************************************************************/
MMI_BOOL mmi_tipc_is_connected(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_tipc_cntx.tipc_connect;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_tipc_allow_sync_time
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL mmi_tipc_allow_sync_time()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    MMI_BOOL r1 = MMI_FALSE, r2 = MMI_FALSE, r3 = MMI_FALSE;
    S32 ts = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    r1 = g_mmi_tipc_cntx.sync_enable;
    r2 = g_mmi_tipc_cntx.tipc_connect;

#ifdef __MMI_WEARABLE_DEVICE_SETTING__
    ts = 1;
    r3 = mmi_get_time_autosync_status();
#else
    ts = -1;
#endif
    if (r1 == MMI_TRUE && r2 == MMI_TRUE)
    {
        ret = MMI_FALSE;
    }
    else
    {
        ret = MMI_TRUE;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, MMI_CONN_TRC_G7_BT, "[TipApp]mmi_tipc_allow_sync_time--ret: %d, ts: %d, r1: %d, r2: %d, r3: %d\n", 
        ret, ts, r1, r2, r3);
    return ret;
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

#endif /* __MMI_BLE_TIP_SUPPORT__*/

