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
*  HeartRate.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   HeartRate UI Source File
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
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"

#ifdef __MMI_HEART_RATE_SUPPORT__
#include "btnotisrvgprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "mmi_rp_app_heart_rate_def.h"

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
#include "mmi_rp_app_scr_locker_def.h"
#endif
#include "GpioSrvGprot.h"
#include "HeartRate.h"

#ifdef __MTK_TARGET__
#include "sensor_manager.h"
#include "sensor_alg_interface.h"
#endif

static mmi_hr_context_t g_hr_context;
static mmi_hr_context_t *g_hr_p = &g_hr_context;


static U32 mmi_heart_rate_little_endian_to_32(const U8 *ptr) 
{
	return (U32)(((U32)*(ptr + 3) << 24) |
					((U32)*(ptr + 2) <<16) |
					((U32)*(ptr + 1)) << 8 |
					((U32)*ptr));
}


static void mmi_heart_rate_srcn_close_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (mmi_frm_scrn_is_present(GRP_ID_HR_APP, SCR_ID_HR_MAIN, MMI_FRM_NODE_ALL_FLAG)) {
		mmi_frm_scrn_close(GRP_ID_HR_APP, SCR_ID_HR_MAIN);
	}

	if (mmi_frm_group_is_present (GRP_ID_HR_APP)) {
    	mmi_frm_group_close(GRP_ID_HR_APP);
	}
}


static void mmi_heart_rate_scrn_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* gui_buffer = NULL;
	U8 message[80] = {0};
	CHAR temp_str[80];
	mmi_rp_app_heart_rate_str_enum msg_title;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_SCRN_SHOW, g_hr_p->hr_bpm);
    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

	if (g_hr_p->bt_connected) {
		
		msg_title = STR_ID_HR_BT_CONNECTED; 
		
	} else {
	
		msg_title = STR_ID_HR_BT_DISCONNECTED;
		
	}

	mmi_ucs2cpy((CHAR*)message, (CHAR*)GetString(STR_ID_HR_HEART_RATE));


	if (g_hr_p->hr_bpm == 0) {
#ifdef __MTK_TARGET__
		//enable sensor
		sensor_subsys_enable(SENSOR_TYPE_HEART_RATE_MONITOR, MMI_TRUE);
#endif
		//show string	
		mmi_asc_to_ucs2(temp_str, "\n");
		mmi_ucs2cat(message, temp_str);
		mmi_ucs2cat(message, GetString(STR_ID_HR_DETECT));
	} else {
		CHAR str_bpm[10];
		
		sprintf(str_bpm, " %d %d", g_hr_p->hr_bpm, g_hr_p->hr_status);
		mmi_asc_to_ucs2(temp_str, str_bpm);
		mmi_ucs2cat(message, temp_str);
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

	wgui_BTcat145_footer_area_register_controlled_callback(mmi_heart_rate_srcn_close_hdlr, 1);

}

static mmi_ret mmi_heart_rate_launch_proc (mmi_event_struct *evt)
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
            mmi_heart_rate_scrn_show();
            break;

        case EVT_ID_SCRN_DEINIT:
#ifdef __MTK_TARGET__
			sensor_subsys_enable(SENSOR_TYPE_HEART_RATE_MONITOR, MMI_FALSE);
#endif
			g_hr_p->hr_bpm = 0;
			g_hr_p->hr_status = 0;

            break;

        case EVT_ID_GROUP_DEINIT:
           break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


void mmi_heart_rate_update_data(U8 *data, U32 data_len)
{
	MMI_BOOL result;
	
	
	g_hr_p->hr_bpm = mmi_heart_rate_little_endian_to_32(data + 12);
	g_hr_p->hr_status = mmi_heart_rate_little_endian_to_32(data + 16) & 0x000000FF;
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_UPDATE_DATA, g_hr_p->hr_bpm, g_hr_p->hr_status);

	
	if (g_hr_p->bt_connected) {
		char buff[120];
		U32 buff_len;
		
		sprintf(buff, "%s %s 0 %d ", SENDER_HEART_RATE, RECEIVER_HEART_RATE, 64);
		buff_len = strlen(buff);
		memcpy(buff + buff_len, data, data_len);
		buff_len += data_len;
		result = srv_bt_noti_send_cmd_ext(
	        &g_hr_p->bt_addr,
	        HEART_RATE_EXTEND_CMD,
	        buff,
	        buff_len);

		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_SEND_DATA_TO_BT, buff_len, result);
	}
	

	/*update the screen*/
	mmi_frm_display_dummy_screen();
	mmi_frm_scrn_close_active_id();
}


void mmi_heart_rate_send_data(U8 *data, U32 data_len)
{
	MMI_BOOL result;

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_SEND_DATA, g_hr_p->raw_len);

	if (g_hr_p->bt_connected) {

		if (g_hr_p->raw_len < 640) {
			memcpy(g_hr_p->raw_data + g_hr_p->raw_len, data, data_len);
			g_hr_p->raw_len += data_len;
		} 
		
		if (g_hr_p->raw_len == 640) {

			char buff[700];
			MMI_BOOL result;
			U32 buff_len;

			memset(buff, 0, 700);
			sprintf(buff, "%s %s 0 %d ", SENDER_HEART_RATE, RECEIVER_HEART_RATE, 640);
			buff_len = strlen(buff);
			memcpy(buff + buff_len, g_hr_p->raw_data, 640);
			buff_len += 640;
			result = srv_bt_noti_send_cmd_ext_by_source(
				&g_hr_p->bt_addr,
				SRV_BT_NOTIFY_DATA_SOURCE_SPP,
				HEART_RATE_EXTEND_CMD,
				buff,
				buff_len);
		
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_SEND_DATA_TO_BT, buff_len, result);
			
			g_hr_p->raw_len = 0;
			memset(g_hr_p->raw_data, 0, 640);
		}
	}
}


void mmi_heart_rate_init(void)
{
	return;
}


void mmi_heart_rate_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	mmi_frm_group_create_ex(GRP_ID_ROOT,
                GRP_ID_HR_APP,
                mmi_heart_rate_launch_proc,
                NULL,
                MMI_FRM_NODE_SMART_CLOSE_FLAG);

	mmi_frm_scrn_create(GRP_ID_HR_APP, 
	   SCR_ID_HR_MAIN, 
	   mmi_heart_rate_launch_proc,
	   NULL);

}


static void mmi_heart_rate_receive_data_callback(void *param)
{

	srv_bt_noti_callback_struct *rev_data = (srv_bt_noti_callback_struct*)param;


	if (!strcmp(rev_data->receiver_id, RECEIVER_HEART_RATE) && 
		rev_data->data_type == SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER &&
		!strcmp(rev_data->data.buffer.data, HEART_RATE_HANDSHAKE_CMD)) {
		char rsp[100] = {0};
		MMI_BOOL result;

		g_hr_p->bt_connected = MMI_TRUE;
		//send RESPONSE
		sprintf(rsp, "%s %s 0 %d ok", SENDER_HEART_RATE, RECEIVER_HEART_RATE, 2);

		result = srv_bt_noti_send_cmd_ext(
	        &g_hr_p->bt_addr,
	        HEART_RATE_EXTEND_CMD,
	        rsp,
	        strlen(rsp));
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_HANDSHAKE, result, strlen(rsp));
	}
}


mmi_ret mmi_heart_rate_evt_hdlr(mmi_event_struct* evt)
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

			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_HR_CONNECTION_CHANGE, status_change->is_connected);

			if (status_change->is_connected) {
				
				//g_hr_p->bt_connected = MMI_TRUE;
				memcpy(&(g_hr_p->bt_addr), &(status_change->bt_addr), sizeof(srv_bt_cm_bt_addr));
				g_hr_p->raw_len = 0;
				memset(g_hr_p->raw_data, 0, sizeof(g_hr_p->raw_data));

				memcpy(&(g_hr_p->bt_addr), &(status_change->bt_addr), sizeof(srv_bt_cm_bt_addr));

				srv_bt_noti_register_callback(&(g_hr_p->bt_addr),
											  HEART_RATE_EXTEND_CMD, 
											  SENDER_HEART_RATE,
											  mmi_heart_rate_receive_data_callback);

			} else {
				srv_bt_noti_deregister_callback(&(g_hr_p->bt_addr), mmi_heart_rate_receive_data_callback);
				
				g_hr_p->bt_connected = MMI_FALSE;
				memset(&(g_hr_p->bt_addr), 0, sizeof(srv_bt_cm_bt_addr));
			}
			
			if (mmi_frm_group_is_present(GRP_ID_HR_APP)) {
				mmi_frm_display_dummy_screen();
				mmi_frm_scrn_close_active_id();
			}
		}
            break;

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
            {
                if (mmi_frm_group_is_present(GRP_ID_HR_APP))
                {
                    result = MMI_RET_ERR; //not allow to lock screen
                }
            }
            break;
#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__ */

        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            {
                if (mmi_frm_group_is_present(GRP_ID_HR_APP))
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

#endif /* __MMI_HEART_RATE_SUPPORT__ */

