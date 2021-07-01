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

/*******************************************************************************
* Filename:
* ---------
*  BloodPressure.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   BloodPressure Source File
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"                   // STR_GLOBAL_ERROR


#ifdef __MMI_BLOOD_PRESSURE_SUPPORT__
#include "btnotisrvgprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "mmi_rp_app_blood_pressure_def.h"

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
#include "mmi_rp_app_scr_locker_def.h" //EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING
#endif
#include "GpioSrvGprot.h"
#include "BloodPressure.h"
#include "common_nvram_editor_data_item.h"
#ifdef __MTK_TARGET__
#include "sensor_manager.h"
#include "sensor_alg_interface.h"
#endif
static mmi_bp_context_t g_bp_context;
static mmi_bp_context_t *g_bp_p = &g_bp_context;


static U32 mmi_blood_pressure_little_endian_to_32(const U8 *ptr) 
{
	return (U32)(((U32)*(ptr + 3) << 24) |
					((U32)*(ptr + 2) <<16) |
					((U32)*(ptr + 1)) << 8 |
					((U32)*ptr));
}


static void mmi_blood_pressure_srcn_close_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (mmi_frm_scrn_is_present(GRP_ID_BP_APP, SCR_ID_BP_MAIN, MMI_FRM_NODE_ALL_FLAG)) {
		mmi_frm_scrn_close(GRP_ID_BP_APP, SCR_ID_BP_MAIN);
	}

	if (mmi_frm_group_is_present (GRP_ID_BP_APP)) {
    	mmi_frm_group_close(GRP_ID_BP_APP);
	}

}


static void mmi_blood_pressure_count_down_timeout(void)
{
	mmi_frm_display_dummy_screen();
	mmi_frm_scrn_close_active_id();
}


static void mmi_blood_pressure_detect_timeout(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_TIMEOUT);
	
	g_bp_p->detect_timeout = MMI_TRUE;

	mmi_frm_display_dummy_screen();
	mmi_frm_scrn_close_active_id();
}


static void mmi_blood_pressure_scrn_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer = NULL;
	U8 message[200] = {0};
	CHAR temp_str[80];
	mmi_rp_app_blood_pressure_str_enum msg_title;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_SCRN_SHOW, g_bp_p->detect_timeout, g_bp_p->bp_sdp, g_bp_p->bp_dbp);
	
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	
	if (g_bp_p->bt_connected) {
		msg_title = STR_ID_BP_BT_CONNECTED;
	}else {
		msg_title = STR_ID_BP_BT_DISCONNECTED;
	}

	mmi_ucs2cpy((CHAR*)message, (CHAR*)GetString(STR_ID_BP_BLOOD_PRESSURE));

	if (g_bp_p->count_down > 0) {
		//show count down
		CHAR str_count[10];
		
		mmi_asc_to_ucs2(temp_str, "\n");
		mmi_ucs2cat(message, temp_str);
		mmi_ucs2cat(message, GetString(STR_ID_BP_PROMPT));
		sprintf(str_count, "%d", g_bp_p->count_down - 1);
		mmi_asc_to_ucs2(temp_str, str_count);
		mmi_ucs2cat(message, temp_str);
		mmi_ucs2cat(message, GetString(STR_ID_BP_COUNT_DOWN));
		
		StartTimer(BP_COUNT_DOWN_TIMER,
                         BP_COUNT_DOWN_TIMEOUT_DURATION,
                         mmi_blood_pressure_count_down_timeout);
		
		g_bp_p->count_down--;
	} else {
	
		mmi_asc_to_ucs2(temp_str, "\n");
		mmi_ucs2cat(message, temp_str);
		
		if (g_bp_p->sensor_started == MMI_FALSE) {
#ifdef __MTK_TARGET__
			sensor_subsys_enable(SENSOR_TYPE_BLOOD_PRESSURE_MONITOR, MMI_TRUE);
#endif
			g_bp_p->sensor_started = MMI_TRUE;

			StartTimer(BP_DETECT_OVER_TIMER,
								 BP_DETECT_OVER_TIMEOUT_DURATION,
								 mmi_blood_pressure_detect_timeout);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_DETECT_TIMER_START);
			g_bp_p->detect_timeout = MMI_FALSE;

			mmi_ucs2cat(message, GetString(STR_ID_BP_DETECT));

		} else {
			if (g_bp_p->detect_timeout == MMI_FALSE) {
				mmi_ucs2cat(message, GetString(STR_ID_BP_DETECT));

			} else {

				if (g_bp_p->bp_sdp == 0 && g_bp_p->bp_dbp == 0) {
					// show detect fail
					mmi_ucs2cat(message, GetString(STR_ID_BP_DETECT_FAIL));
				} else {
					//show blood pressure
					char str_bp[10];
					
					sprintf(str_bp, " %d/%d", g_bp_p->bp_sdp, g_bp_p->bp_dbp);
					mmi_asc_to_ucs2(temp_str, str_bp);
					mmi_ucs2cat(message, temp_str);
				}
			}
		}

		
		/*if (g_bp_p->bp_sdp == 0 && g_bp_p->bp_dbp == 0) {
			mmi_asc_to_ucs2(temp_str, "\n");
			mmi_ucs2cat(message, temp_str);

			if (g_bp_p->detect_timeout == MMI_FALSE && !IsMyTimerExist(BP_DETECT_OVER_TIMER)) {
				//show detecting...

				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_DETECT_TIMER_START);
				mmi_ucs2cat(message, GetString(STR_ID_BP_DETECT));
				StartTimer(BP_DETECT_OVER_TIMER,
                         BP_DETECT_OVER_TIMEOUT_DURATION,
                         mmi_blood_pressure_detect_timeout);
			} else {
				// show detect fail
				mmi_ucs2cat(message, GetString(STR_ID_BP_DETECT_FAIL));
			}
		} else {
			//show blood pressure
			char str_bp[10];
			
			sprintf(str_bp, " %d/%d", g_bp_p->bp_sdp, g_bp_p->bp_dbp);
			mmi_asc_to_ucs2(temp_str, str_bp);
			mmi_ucs2cat(message, temp_str);
		}*/
	}


    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        NULL,    
        NULL,
        NULL,
        NULL,
        STR_GLOBAL_BACK,
        NULL,
        NULL,
        (U8 *)GetString(msg_title), 
        message,
        NULL,
        gui_buffer,
        NULL);

	wgui_BTcat145_footer_area_register_controlled_callback(mmi_blood_pressure_srcn_close_hdlr, 1);
}


static mmi_ret mmi_blood_pressure_launch_proc (mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            mmi_blood_pressure_scrn_show();
            break;

        case EVT_ID_SCRN_DEINIT:
#ifdef __MTK_TARGET__
			sensor_subsys_enable(SENSOR_TYPE_BLOOD_PRESSURE_MONITOR, MMI_FALSE);
#endif
			g_bp_p->sensor_started = MMI_FALSE;
			if (IsMyTimerExist(BP_DETECT_OVER_TIMER)) {
					
				StopTimer(BP_DETECT_OVER_TIMER);
			}
            break;

        case EVT_ID_GROUP_DEINIT:
			
           break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_blood_pressure_update_data(U8 *data, U32 data_len)
{
	MMI_BOOL result;
	
	
	g_bp_p->bp_sdp = mmi_blood_pressure_little_endian_to_32(data + 12);
	g_bp_p->bp_dbp = mmi_blood_pressure_little_endian_to_32(data + 16);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_UPDATE_DATA, g_bp_p->bp_sdp, g_bp_p->bp_dbp);

		
	if (g_bp_p->bt_connected) {
		char buff[120];
		U32 buff_len;
		
		sprintf(buff, "%s %s 0 %d ", SENDER_BLOOD_PRESSURE, RECEIVER_BLOOD_PRESSURE, 64);
		buff_len = strlen(buff);
		memcpy(buff + buff_len, data, data_len);
		buff_len += data_len;
		result = srv_bt_noti_send_cmd_ext(
	        &g_bp_p->bt_addr,
	        BLOOD_PRESSURE_EXTEND_CMD,
	        buff,
	        buff_len);

		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_SEND_DATA_TO_BT, buff_len, result);
	}

	if (g_bp_p->bp_sdp != 0 && g_bp_p->bp_dbp != 0) {
		if (IsMyTimerExist(BP_DETECT_OVER_TIMER)) {
		
			StopTimer(BP_DETECT_OVER_TIMER);
			g_bp_p->detect_timeout = MMI_TRUE;
		}
		
		mmi_frm_display_dummy_screen();
		mmi_frm_scrn_close_active_id();
	}
}


void mmi_blood_pressure_send_data(U8 *data, U32 data_len)
{
	MMI_BOOL result;


	//MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_SEND_DATA, g_bp_p->raw_len);

	//send raw data
	if (g_bp_p->bt_connected) {
		if (g_bp_p->raw_len < 640) {
			memcpy(g_bp_p->raw_data + g_bp_p->raw_len, data, data_len);
			g_bp_p->raw_len += data_len;
		} 

		if (g_bp_p->raw_len == 640) {

			char buff[700];
			MMI_BOOL result;
			U32 buff_len;

			memset(buff, 0, 700);
			sprintf(buff, "%s %s 0 %d ", SENDER_BLOOD_PRESSURE, RECEIVER_BLOOD_PRESSURE, 640);
			buff_len = strlen(buff);
			memcpy(buff + buff_len, g_bp_p->raw_data, 640);
			buff_len += 640;
			result = srv_bt_noti_send_cmd_ext_by_source(
				&g_bp_p->bt_addr,
				SRV_BT_NOTIFY_DATA_SOURCE_SPP,
				BLOOD_PRESSURE_EXTEND_CMD,
				buff,
				buff_len);
		
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_SEND_DATA_TO_BT, buff_len, result);
			
			g_bp_p->raw_len = 0;
			memset(g_bp_p->raw_data, 0, 640);
		}
	}
}


static void mmi_blood_pressure_receive_data_callback(void *param)
{
	srv_bt_noti_callback_struct *rev_data = (srv_bt_noti_callback_struct*)param;
	nvram_ef_bp_info_struct bp_info;
	U8 parsed_len = 0;
	char data[100] = {0};
	MMI_BOOL result;
	U32 data_len;
	U32 rsp[16] = {12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345, 12345};

	if (!strcmp(rev_data->receiver_id, RECEIVER_BLOOD_PRESSURE) && 
		rev_data->data_type == SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER) {

		if (!strcmp(rev_data->data.buffer.data, BP_HANDSHAKE_CMD)) {
			//handshake
			char rsp[100] = {0};

			g_bp_p->bt_connected = MMI_TRUE;
			
			//send RESPONSE
			sprintf(rsp, "%s %s 0 %d ok", SENDER_BLOOD_PRESSURE, RECEIVER_BLOOD_PRESSURE, 2);

			result = srv_bt_noti_send_cmd_ext(
		        &g_bp_p->bt_addr,
		        BLOOD_PRESSURE_EXTEND_CMD,
		        rsp,
		        strlen(rsp));
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_HANDSHAKE, result, strlen(rsp));
		} else {
			mmi_bp_tag_id_t tag_id;
			U8 tag_len;
			

			/*parse the received data*/
			memset(&bp_info, 0, sizeof(nvram_ef_bp_info_struct));

			parsed_len += 5;

			while (parsed_len < rev_data->data.buffer.data[0]) {
				
				tag_id = rev_data->data.buffer.data[parsed_len];
				
				parsed_len++;
				tag_len = rev_data->data.buffer.data[parsed_len];
				parsed_len++;

				switch(tag_id) {
					case MMI_BP_TAG_USER_NAME:
						{
							U8 max_len = tag_len > NVRAM_EF_BP_USERID_LEN ? NVRAM_EF_BP_USERID_LEN : tag_len;
							
							memcpy(bp_info.userid, rev_data->data.buffer.data + parsed_len, max_len);
							parsed_len += tag_len;
						}
						break;
						
					case MMI_BP_TAG_HEIGHT:
						bp_info.height = mmi_blood_pressure_little_endian_to_32(rev_data->data.buffer.data + parsed_len);
						parsed_len += tag_len;
						break;
						
					case MMI_BP_TAG_WEIGHT:
						bp_info.weight = mmi_blood_pressure_little_endian_to_32(rev_data->data.buffer.data + parsed_len);
						parsed_len += tag_len;
						break;
						
					case MMI_BP_TAG_GENDER:
						bp_info.gender = mmi_blood_pressure_little_endian_to_32(rev_data->data.buffer.data + parsed_len);
						parsed_len += tag_len;
						break;
						
					case MMI_BP_TAG_AGE:
						bp_info.age = mmi_blood_pressure_little_endian_to_32(rev_data->data.buffer.data + parsed_len);
						parsed_len += tag_len;
						break;
						
					case MMI_BP_TAG_ARMLEN:
						bp_info.armlen = mmi_blood_pressure_little_endian_to_32(rev_data->data.buffer.data + parsed_len);
						parsed_len += tag_len;
						break;
						
					default:
						break;
				}
				
			}

			if (parsed_len == rev_data->data.buffer.data[0]) {
				S32 write_len;
				
				//parse success
				rsp[3] = 0; //non_zero means fail
				
				//write to NVRAM
				write_len = WriteRecordSlim(NVRAM_EF_BP_INFO_LID, 1, (void*)&bp_info, NVRAM_EF_BP_INFO_SIZE);
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_PARSE_SCCUESS, write_len);

			}

			//send RESPONSE
			rsp[0] = 54321;
			rsp[1] = 3001;
			sprintf(data, "%s %s 0 %d ", SENDER_BLOOD_PRESSURE, RECEIVER_BLOOD_PRESSURE, 64);
			data_len = strlen(data);
			memcpy(data + data_len, rsp, 16 * sizeof(U32));
			data_len += 64;
			result = srv_bt_noti_send_cmd_ext_by_source(
		        &g_bp_p->bt_addr,
		        SRV_BT_NOTIFY_DATA_SOURCE_SPP,
		        BLOOD_PRESSURE_EXTEND_CMD,
		        data,
		        data_len);

			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_SEND_RESPONSE, data_len, result);
		}
	}

	//for test
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
#endif
}


void mmi_blood_pressure_init(void)
{

	return;
}


void mmi_blood_pressure_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	kal_prompt_trace(MOD_MMI, "[BP]mmi_blood_pressure_launch");
	g_bp_p->count_down = 11;
	g_bp_p->bp_dbp = 0;
	g_bp_p->bp_sdp = 0;
	g_bp_p->sensor_started = MMI_FALSE;
	g_bp_p->detect_timeout = MMI_FALSE;
	
	mmi_frm_group_create_ex(GRP_ID_ROOT,
                GRP_ID_BP_APP,
                mmi_blood_pressure_launch_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_scrn_create(GRP_ID_BP_APP, 
	   SCR_ID_BP_MAIN, 
	   mmi_blood_pressure_launch_proc,
	   NULL);

}

mmi_ret mmi_blood_pressure_evt_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE:
		{
			srv_bt_noti_connect_status_change_notify_struct *status_change = (srv_bt_noti_connect_status_change_notify_struct*)evt;

			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BP_CONNECTION_CHANGE, status_change->is_connected);

			if (status_change->is_connected) {
				//g_bp_p->bt_connected = MMI_TRUE;
				memcpy(&(g_bp_p->bt_addr), &(status_change->bt_addr), sizeof(srv_bt_cm_bt_addr));

				srv_bt_noti_register_callback(&(g_bp_p->bt_addr),
											  BLOOD_PRESSURE_EXTEND_CMD, 
											  SENDER_BLOOD_PRESSURE,
											  mmi_blood_pressure_receive_data_callback);

			} else {
				srv_bt_noti_deregister_callback(&(g_bp_p->bt_addr), mmi_blood_pressure_receive_data_callback);
				
				g_bp_p->bt_connected = MMI_FALSE;
				memset(&(g_bp_p->bt_addr), 0, sizeof(srv_bt_cm_bt_addr));
			}

			if (mmi_frm_group_is_present(GRP_ID_BP_APP)) {
				mmi_frm_display_dummy_screen();
				mmi_frm_scrn_close_active_id();
			}
		}
            break;

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
            {
                if (mmi_frm_group_is_present(GRP_ID_BP_APP))
                {
                    result = MMI_RET_ERR; //not allow to lock screen
                }
            }
            break;
#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__ */

        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            {
                if (mmi_frm_group_is_present(GRP_ID_BP_APP))
                {
                    result = MMI_RET_ERR; //not allow to turn off the backlight
                }
            }
            break;

        default:
            break;
    }

    return result;
}

#endif /* __MMI_BLOOD_PRESSURE_SUPPORT__ */
