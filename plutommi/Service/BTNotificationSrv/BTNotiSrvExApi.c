/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * BTNotiSrvExApi.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT Notification srv.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_BT_NOTI_SRV__
#include "Stdlib.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h" 

#include "SppSrvGprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#if !defined(__IOT__)

#include "mmi_rp_app_bluetooth_def.h"
#endif
#include "mmi_frm_scenario_gprot.h"
#include "mmi_cb_mgr_gprot.h"

#include "BtNotiSrvGprot.h"
#include "BTNotiSrvRecv.h"
#include "BTNotiSrvData.h"
#include "BtNotifySrvParser.h"
#include "BTNotiSrvDisp.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "..\\..\\mtkapp\\connectivity\\connectivityinc\\btmtk\\BTMMISppGprots.h"
#include "custom_mmi_default_value.h"

/* for time and time zone */
#include "DateTimeGprot.h"
#include "SettingGprots.h"
#include "worldclock.h"
#include "PhoneSetupGprots.h"
#include "DateTimeSrvGprot.h"

/* for alarm */
#include "AlarmSrvGprot.h"

/* for mre install and uninstall */
#include "MREAppMgrSrvGprot.h"
#include "MRESrvGProt.h"

#include "mmi_rp_srv_bt_noti_def.h"

/*for app infor*/
#include "vmcert.h"
#include "vmgettag_sdk.h"
/* for app infor*/

/* for customer to set the key begain*/
static CHAR g_custom_key_set[10] ={0};

CHAR *srv_bt_get_custom_key(void)
{
	MMI_PRINT(MOD_MMI_CONN_APP, 
		  TRACE_GROUP_7, 
		  "[BTNOTIFYSRV] srv_bt_set_custom_key() g_custom_key_set = %s", 
		  g_custom_key_set);

	return g_custom_key_set;
}
/* for customer to set the key end*/

U16 srv_bt_noti_get_external_event_id(srv_bt_notify_extrtnal_event_enum type)
{
    switch (type)
    {
        case SRV_BT_EXT_EVENT_SPPC_CONNECT_CNF:
        {
            return EVT_ID_SPPC_CONNECT_CNF;
        }

        case SRV_BT_EXT_EVENT_SPP_CONNECT_CNF:
        {
            return EVT_ID_SPPS_CONNECT_IND;
        }
            
        case SRV_BT_EXT_EVENT_SPPC_DISCONNECT_CNF:
        {
            return EVT_ID_SPPC_DISCONNECT_CNF;
        }

        case SRV_BT_EXT_EVENT_SPP_DISCONNECT_CNF:
        {
            return EVT_ID_SPPS_DISCONNECT_CNF;
        }
            
        case SRV_BT_EXT_EVENT_SPPC_READY_TO_READ:
        {
            return EVT_ID_SPPC_READY_TO_READ;
        }

        case SRV_BT_EXT_EVENT_SPP_READY_TO_READ:
        {
            return EVT_ID_SPPS_READY_TO_READ;
        }
            
        case SRV_BT_EXT_EVENT_SPPC_READY_TO_WRITE:
        {
            return EVT_ID_SPPC_READY_TO_WRITE;
        }

        case SRV_BT_EXT_EVENT_SPP_READY_TO_WRITE:
        {
            return EVT_ID_SPPS_READY_TO_WRITE;
        }
            
        case SRV_BT_EXT_EVENT_POST_FSM:
        {
            return EVT_ID_SRV_BT_NOTI_POST_FSM;
        }

        case SRV_BT_EXT_EVENT_NEW_MSG:
        {
            return EVT_ID_SRV_BT_NOTI_NEW_MSG;
        }

        case SRV_BT_EXT_EVENT_DEL_MSG:
        {
            return EVT_ID_SRV_BT_NOTI_DEL_MSG;
        }

        case SRV_BT_EXT_EVENT_SYNC_DEV:
        {
            return EVT_ID_SRV_BT_NOTI_SYNC_DEV;
        }

        case SRV_BT_EXT_EVENT_MAP_CONNECT_CNF:
        {
            return EVT_ID_SRV_BT_NOTI_MAP_CONNECT_CNF;
        }

        case SRV_BT_EXT_EVENT_MAP_DISCONNECT_CNF:
        {
            return EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF;
        }

        case SRV_BT_EXT_EVENT_MAP_CMD_NOTIFY:
        {
            return EVT_ID_SRV_BT_NOTI_MAP_CMD_NOTIFY;
        }
        
        case SRV_BT_EXT_EVENT_CAP_CMD_NOTIFY:
        {
            return EVT_ID_SRV_BT_NOTI_CAP_CMD_NOTIFY;
        }

    #if defined(__MMI_WEARABLE_DEVICE__)
        case SRV_BT_EXT_EVENT_MRE_INSTALL_NOTIFY:
        {
            return EVT_ID_SRV_BT_NOTI_MRE_INSTALL_NOTIFY;
        }
    #endif

        case SRV_BT_EXT_EVENT_SOGPS_CONNECT_IND:
        {
            return EVT_ID_SOGPS_CONNECT_IND;
        }
        
        case SRV_BT_EXT_EVENT_SOGPS_DISCONNECT_IND:
        {
            return EVT_ID_SOGPS_DISCONNECT_IND;
        }

        case SRV_BT_EXT_EVENT_SOGPS_READY_TO_READ:
        {
            return EVT_ID_SOGPS_READY_TO_READ;
        }

        case SRV_BT_EXT_EVENT_SOGPS_READY_TO_WRITE:
        {
            return EVT_ID_SOGPS_READY_TO_WRITE;
        }      

        case SRV_BT_EXT_EVENT_CONNECTION_STATUS_CHANGE:
        {
            return EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE;
        }
        
        default:
        {
            return 0;
        }
    }
}

U16 srv_bt_noti_get_external_timer_id(srv_bt_notify_external_timer_enum type)
{
    switch (type)
    {
        case SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER1:
        case SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER2:
        case SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER3:
        case SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER4:
        {
            return (U16)(TIMER_ID_BT_NOTI_WAIT_SYNC_CMD1 + type);
        }

        case SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP1:
        case SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP2:
        case SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP3:
        case SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP4:
        {
            return (U16)(TIMER_ID_BT_NOTI_RECEIVE_DATA_TIME_GAP1 + type - SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP1);    
        }
        
        default:
        {
            return 0;
        }
    }
}

U16 srv_bt_noti_get_wait_sync_cmd_timer_id(U8 cntx_chnl)
{
    return srv_bt_noti_get_external_timer_id(
        (srv_bt_notify_external_timer_enum)(SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER1 + cntx_chnl));
}

U16 srv_bt_noti_get_recv_data_gap_timer_id(U8 cntx_chnl)
{
    return srv_bt_noti_get_external_timer_id(
        (srv_bt_notify_external_timer_enum)(SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP1 + cntx_chnl));
}


U32 srv_bt_noti_get_receiving_data_time_gap(void)
{
    return BT_NOTIFY_RECEIVING_DATA_TIME_GAP;
}

U32 srv_bt_noti_get_sync_time_gap(void)
{
#if defined(__MMI_WEARABLE_DEVICE__)
    return 0;
#else
    return BT_NOTIFY_SYNC_TIME_GAP;
#endif
}

MMI_BOOL srv_bt_noti_check_wearable_device_option_enable(void)
{
#if defined(__MMI_WEARABLE_DEVICE__)
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}

MMI_BOOL srv_bt_noti_recv_check_valid_date(S32 time, applib_time_struct *local_time_out)
{
    applib_time_struct local_time;
    U32 local_time_sec;
    
    local_time_sec = applib_dt_sec_utc_to_local((kal_uint32)time);
    mmi_dt_utc_sec_2_mytime(local_time_sec, &local_time, MMI_FALSE);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              TRC_SRV_BT_NOTIFY_RECV_SYNC_TIME,
              local_time.nYear,
              local_time.nMonth,
              local_time.nDay,
              local_time.nHour,
              local_time.nMin,
              local_time.nSec);

    if (!applib_dt_check_valid_by_app(DT_UTC_BASE_YEAR,
                                      DT_MAX_YEAR,
                                      &local_time))
    {
        return MMI_FALSE;
    }
    else
    {
        if (local_time_out != NULL)
        {
            memcpy(local_time_out, &local_time, sizeof(applib_time_struct));
        }
        
        return MMI_TRUE;
    }
}

static void srv_bt_noti_recv_update_time_notify()
{
    srv_bt_noti_update_time_notify_struct event;
    
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_UPDATE_TIME_NOTIFY);
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}

void srv_bt_noti_recv_update_time(S32 time, S32 time_zone)
{
    applib_time_struct local_time;
    S16 home_city;
    U8 city_count;
    U8 i;
 
    /* set time zone */
    home_city = (S16)(time_zone * 4 / 3600000);
    city_count = mmi_wc_get_size() - 1;

    /* 0 implements first zone */
    for (i = 0; i < city_count; ++i)
    { 
    #if !defined(__IOT__)
        if ((S16)(GetTimeZone(i) * 4) == home_city)
        {
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        #ifdef __MMI_SETTINGS_SUPPORT__ 
            ATSetHomeCity(i + 1);        
        #endif

            /* just for test home city */
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        
            break;
        }
    #endif
    }

    /* MAUI_03483827 */
    /* MAUI_03485571 should first set home city before check time */
    if (MMI_FALSE == srv_bt_noti_recv_check_valid_date(time, (applib_time_struct*)&local_time))
    {
        return;
    }
#if !defined(__IOT__)
    //mmi_dt_set_rtc_dt((MYTIME*)&local_time);
    srv_dt_set_dt(SRV_UTC_DT_SYNC_LEVEL4,
                &local_time,
                NULL,
                NULL);
    srv_dt_set_time_zone(home_city);
#endif
    srv_bt_noti_recv_update_time_notify();
}

S16 srv_bt_noti_recv_get_curr_time_zone(void)
{
#if !defined(__IOT__)
    return (S16)(GetTimeZone(PhnsetGetHomeCity()) * 4);
#endif
}

MMI_BOOL srv_bt_noti_recv_sync_check_time_zone(S32 time_zone)
{
    return ((S16)(time_zone * 4 / 3600000) == srv_bt_noti_recv_get_curr_time_zone()) ? MMI_TRUE : MMI_FALSE;
}

U32 srv_bt_noti_recv_get_curr_time(void)
{
    applib_time_struct time;

    applib_dt_get_rtc_time(&time);
    return applib_dt_sec_local_to_utc(applib_dt_mytime_2_utc_sec(&time, MMI_FALSE));
}


MMI_BOOL srv_bt_noti_recv_uninstall_mre(WCHAR *mre_file_path)
{
    MMI_BOOL ret = MMI_FALSE;
    U16 app_name_tmp[MMI_APP_NAME_MAX_LEN];
    mmi_app_package_char app_name[MMI_APP_NAME_MAX_LEN];
    srv_mre_check_app_state_result_enum app_state;
    CHAR file_path[40 + 1];

    memset(file_path, 0, 41);
    
    if (mre_file_path == NULL)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, 
            TRACE_GROUP_7, 
            "[BTNOTIFYSRV] uninstall_mre: NULL, ret = %d",
            ret);
        return MMI_FALSE;
    }

    mmi_wcs_n_to_asc(file_path, (WCHAR*) mre_file_path, 40 * ENCODING_LENGTH);
        
    srv_mre_appmgr_generate_identification(mre_file_path, app_name_tmp);
    mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_UTF8, (char*)app_name_tmp, (char*)app_name, MMI_APP_NAME_MAX_LEN);

    /* just exit the mre app before uninstalling when app is running */
    app_state = srv_mre_get_app_state(mre_file_path);
    
    if (SRV_MRE_APP_STATE_FORGROUND == app_state || 
        SRV_MRE_APP_STATE_BACKGROUND == app_state)
    {
        srv_mre_close_app(mre_file_path);
    }
    
    ret = srv_mre_appmgr_app_uninstall(app_name);
    FS_Delete(mre_file_path);

    MMI_PRINT(MOD_MMI_CONN_APP, 
          TRACE_GROUP_7, 
          "[BTNOTIFYSRV] uninstall_mre: %s, ret = %d",
          file_path,
          ret);
        
    return ret;
}


/* change device name begain*/
S32 srv_bt_noti_recv_change_device_name_btcm_callback(U32 event, void* para)
{
	S32 channel;
    srv_bt_cm_set_name_struct *p_event = (srv_bt_cm_set_name_struct *)para;
	kal_uint8 device_name[60];
	MMI_PRINT(MOD_MMI_CONN_APP, 
			  TRACE_GROUP_7, 
			  "[BTNOTIFYSRV] srv_bt_noti_recv_change_device_name_btcm_callback() p_event->result = %d", 
			  p_event->result);

    switch (event)
    {
        case SRV_BT_CM_EVENT_SET_NAME:
		{
			srv_bt_cm_dev_struct *dev_info = NULL;
			
			MMI_PRINT(MOD_MMI_CONN_APP, 
				  TRACE_GROUP_7, 
				  "[BTNOTIFYSRV] srv_bt_noti_recv_change_device_name_btcm_callback() set result = %d", 
				  p_event->result);	

			dev_info = (srv_bt_cm_dev_struct *)srv_bt_cm_get_host_dev_info();
			if (NULL != dev_info)
			{
				memcpy((CHAR *)device_name, (CHAR *)(dev_info->name), strlen(dev_info->name));
				MMI_PRINT(MOD_MMI_CONN_APP, 
						  TRACE_GROUP_7, 
						  "[BTNOTIFYSRV] srv_bt_noti_recv_change_device_name_btcm_callback() dev_info->name = %s, str_len = %d", 
						  dev_info->name,
						  strlen(dev_info->name));
				device_name[strlen(dev_info->name)] = '\0';
				device_name[strlen(dev_info->name) + 1] = '\0';

				channel = (S32)(p_event->user_data);

				MMI_PRINT(MOD_MMI_CONN_APP, 
						  TRACE_GROUP_7, 
						  "[BTNOTIFYSRV] srv_bt_noti_recv_change_device_name_btcm_callback() channel = %d, dev_info->name = %s, Str_len = %d", 
						  channel,
						  device_name,
						  strlen(device_name));
				srv_bt_noti_recv_send_device_name((U8)channel,(const char *)device_name);
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				return channel;
			}
		}
            break;
		default :
		{
			return -1;
		}
			break;
	}
}

s32 srv_bt_noti_recv_set_notify(void* callback,void* user_data)
{
    S32 srv_bt_hd;
	U32 event_mask = SRV_BT_CM_EVENT_SET_NAME;

	srv_bt_hd = srv_bt_cm_set_notify((srv_bt_cm_notifier)callback,event_mask,user_data);
	MMI_PRINT(MOD_MMI_CONN_APP, 
			  TRACE_GROUP_7, 
			  "[BTNOTIFYSRV] srv_bt_noti_recv_set_notify() srv_bt_hd = %d", 
			  srv_bt_hd);

	return srv_bt_hd;

}
S32 srv_bt_noti_recv_reset_notify(S32 srv_hd)
{
    S32 ret;
	if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_reset_notify(srv_hd))
	{
	    ret = 0;
	}
	else
	{
		ret = -2;
	}
	MMI_PRINT(MOD_MMI_CONN_APP, 
			  TRACE_GROUP_7, 
			  "[BTNOTIFYSRV] srv_bt_noti_recv_reset_notify() ret = %d", 
			  ret);

	return ret;
}
s32 srv_bt_noti_recv_set_dev_name(U8 *name)
{
    S32 ret;

	if (SRV_BT_CM_RESULT_SUCCESS == srv_bt_cm_set_host_dev_name(name))
	{
		ret = 0;
	}
	else
	{
		ret = -1;
	}
	MMI_PRINT(MOD_MMI_CONN_APP, 
			  TRACE_GROUP_7, 
			  "[BTNOTIFYSRV] srv_bt_noti_recv_set_dev_name() ret = %d", 
			  ret);

	return ret;

}
/* change device name end*/


MMI_BOOL srv_bt_noti_recv_check_enable_alarm_setting_sync(void)
{
#if defined(__MMI_WEARABLE_DEVICE__)
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}

void srv_bt_noti_recv_update_alarm_time(U32 index, U8 weekday, U8 hour, U8 minute)
{
#ifdef __MMI_ORGANIZER_SUPPORT__
    srv_alm_node_type *node = NULL;

    if (index >= NUM_OF_ALM)
    {
        return;
    }
    
    node = srv_alm_read(index);
    
    if (node != NULL)
    {
        node->State = 1;
        node->Days = weekday;
        node->Hour = hour;
        node->Min = minute;
        srv_alm_write(index, node);
    }
#endif
}

const char* srv_bt_noti_recv_get_device_infor()
{
    static const char device_infor[] =  "<deviceinfo> \
 <lcdsize width = '240' length = '240'/> \
 <g_sensor>BMI055</g_sensor> \
 <magnetic_sensor>YAS530</magnetic_sensor> \
 <gyro_sensor>BMI055</gyro_sensor> \
 <heart_rate_sensor>none</heart_rate_sensor> \
 <temperature_sensor>none</temperature_sensor> \
 <humidity_sensor>none</humidity_sensor> \
 <max_memory>102400</max_memory> \
 <mre_version>4.0</mre_version> \
 <gsm>none</gsm> \
 <gps>none</gps> \
 <brand>MTK</brand> \
 <model>TEST</model> \
 <version>MAUI.WEARv1_DEV.W14.20</version> \
 </deviceinfo>";

    return device_infor;
}

MMI_BOOL srv_bt_noti_file_exist(const WCHAR *filename)
{
    int fp = FS_Open(filename, FS_READ_ONLY);

    if (fp >= FS_NO_ERROR)
    {
        FS_Close(fp);
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
}

MMI_BOOL srv_bt_noti_file_check_integrity(const WCHAR *filename,
                                          U32 *file_size,
                                          U32 expected_file_size)
{
    int fp = -1;
    MMI_BOOL ret = MMI_FALSE;
    *file_size = 0;
    
    do
    {
        if (expected_file_size <= 0)
        {
            MMI_PRINT(MOD_MMI_CONN_APP, 
				          TRACE_GROUP_7, 
				          "[BTNOTIFYSRV] srv_bt_noti_file_check_integrity ERROR. fileSize:%D",
				          expected_file_size);
            break;
        }
        fp = FS_Open(filename, FS_READ_ONLY);

        if (fp < FS_NO_ERROR)
        {         
            break;
        }

        if (FS_GetFileSize(fp, file_size) < FS_NO_ERROR)
        {
            break;
        }

        if (*file_size == expected_file_size)
        {
            ret = MMI_TRUE;
        }
    } while(0);

    if (fp >= 0)
    {
        FS_Close(fp);
        fp = -1;
    }
    
    return ret;
}

U64 srv_bt_noti_recv_check_free_space(U8 drv_letter, S32 *ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FS_DiskInfo disk_info;
    U64 disk_free_space = 0;
    S32 fs_ret = 0;
    U16 path[10] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    kal_wsprintf(path, "%c:\\", drv_letter);    
    fs_ret = FS_GetDiskInfo((kal_uint16*)path, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    *ret = fs_ret;

    if (fs_ret < 0)
    {
        return disk_free_space;
    }
    else
    {        
        disk_free_space = disk_info.FreeClusters * 
                          disk_info.SectorsPerCluster * 
                          disk_info.BytesPerSector;
        return disk_free_space - disk_info.BytesPerSector;
    }
}

/*if customize the version number, the number must bigger than original*/
const char* srv_bt_noti_recv_get_version_number()
{
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    static const char  version_number[] = "340";
#else 
    static const char  version_number[] = "331";
#endif
    return version_number; 
}

#endif // __MMI_BT_NOTI_SRV__

