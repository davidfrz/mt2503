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
 * AvrcpSrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for Bluetooth AVRCP MMI application
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"
#if (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__))
/***************************************************************************** 
* Included files
*****************************************************************************/

/* avrcp header files */
#include "bluetooth_avrcp_struct.h"
#include "AvrcpSrvUtil.h"
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#include "mmi_rp_srv_avrcp_def.h"
#include "AvrcpSrvGprot.h"
#include "AvrcpSrv.h"
#include "A2dpSrv.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "mmi_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "kal_public_api.h"

#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "stack_config.h"
#include "TimerEvents.h"
#include "wgui_categories_list.h"
#include "mmi_frm_timer_gprot.h"
#include "BTMMIScrGprots.h"

/***************************************************************************** 
* Function declare
*****************************************************************************/
static void srv_avrcp_init_event_handler(void);
static void srv_avrcp_activate_cnf_hdlr(void *msg);
static void srv_avrcp_deactivate_cnf_hdlr(void *msg);

static void srv_avrcp_connect_cnf_hdlr(void *msg);
static void srv_avrcp_connect_ind_hdlr(void *msg);
static void srv_avrcp_connect_ind_req_hdlr(void *msg);
static void srv_avrcp_disconnect_cnf_hdlr(void *msg);
static void srv_avrcp_disconnect_ind_hdlr(void *msg);
static void srv_avrcp_cmd_frame_req(U8 avrcp_chnl, U8 op_code, U8 op_id, U8 key_down);
static void srv_avrcp_cmd_frame_cnf_hdlr(void *msg);
static void srv_avrcp_cmd_frame_ind_hdlr(void *msg);
static U8 srv_avrcp_bt_dialer_tg_cmd_callback_int(U8 avrcp_chnl, U8 command, srv_avrcp_key_events key_events);
static void srv_avrcp_auto_release_cmd(void *arg);

static void srv_avrcp_activate_req(void);
static void srv_avrcp_deactivate_req(void);
static void srv_avrcp_notify_connectivity_result(U8 avrcp_chnl,
                                                 MMI_BOOL is_connect,
                                                 MMI_BOOL is_indicate);

#ifdef __MMI_BT_AVRCP_V13__

static U8 srv_avrcp_open_dev(U8 avrcp_chnl);
static U8 srv_avrcp_close_dev(U8 avrcp_chnl);
static void srv_avrcpv13_init_event_handler();
static void srv_avrcp_register_events_notification_req(U8 avrcp_chnl, srv_avrcp_result_union reg_notity_result);
static S32 calculate_pow(int base, int index);
static U8 srv_avrcp_get_supported_attr_val_req(U8 avrcp_chnl);

/*****************************************************************************
* FUNCTION
* srv_avrcp_list_player_app_attr_req
* DESCRIPTION: To get player app supported settings
* PARAMETERS
* RETURNS
* enum : Immediate result : SUCCESS/FAILURE
* Actual Result : It will be notified in app_notify_callback.
* Event ID:    SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_EVENT
* Resut structure : result_union.supported_attr_list_result
* *****************************************************************************/
static U8 srv_avrcp_list_player_app_attr_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_list_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:    SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_VALUE_EVENT
 * Resut structure : result_union.supp_attr_val_list
 *****************************************************************************/
static U8 srv_avrcp_list_player_app_value_req(U8 avrcp_chnl, srv_avrcp_player_app_settings_attr_enum attr_id);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_curr_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:    SRV_AVRCP_EVT_ID_CURR_ATTR_VAL_EVENT
 * Resut structure : result_union.curr_attr_list_result
 *****************************************************************************/
static U8 srv_avrcp_get_curr_player_app_value_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_SET_PLAYERAPP_VAL_EVENT
 * Resut structure : result_union.result_cnf
 *****************************************************************************/
static U8 srv_avrcp_set_player_app_value_req(U8 avrcp_chnl, U8 attr_values[]);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_attr_txt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_ATTR_TXT_EVENT
 * Resut structure : result_union.attr_txt_result
 *****************************************************************************/
static U8 srv_avrcp_get_player_app_attr_txt_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_value_txt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_ATTR_TXT_VAL_EVENT
 * Resut structure : result_union.val_txt_result
 *****************************************************************************/
static U8 srv_avrcp_get_player_app_value_txt_req(U8 avrcp_chnl, srv_avrcp_player_app_settings_attr_enum attr_id);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_equalizer_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_equalizer_setting_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_repeat_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_repeat_setting_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_shuffle_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_shuffle_setting_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_scan_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_scan_setting_req(U8 avrcp_chnl);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_displayable_charset_req
 * DESCRIPTION
 *  Set  Character set at TG to notify result to CT.
 *  UTF-8 is default charset format.
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_INFORM_DISPLAYABLE_CHARSET_EVENT
 * Resut structure : result_union.result_cnf
 *****************************************************************************/
static U8 srv_avrcp_inform_displayable_charset_req(U8 avrcp_chnl, U16 charset[]);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_battery_status_of_ct_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_INFORM_BATT_STATUS_CT_EVENT
 * Resut structure : result_union.result_cnf
 *****************************************************************************/
static U8 srv_avrcp_inform_battery_status_of_ct_req(U8 avrcp_chnl, srv_avrcp_battery_status_enum battery_status);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_element_attr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_ELEM_ATTR_EVENT
 * Resut structure : result_union.attr_txt_result
 *****************************************************************************/
static U8 srv_avrcp_get_element_attr_req(U8 avrcp_chnl, srv_avrcp_media_attr_enum attr_ids[]);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_register_notification_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_REG_NOTIFICATION_EVENT
 * Resut structure : result_union.play_status
 *****************************************************************************/
static U8 srv_avrcp_register_notification_req(U8 avrcp_chnl, 
    srv_avrcp_metadata_trasnfer_events event_id, U32 playback_interval);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_abort_continueing_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 * enum - intermediate_result
 * Actual Result : It will be notified in app_notify_callback.
 * Event ID:     SRV_AVRCP_EVT_ID_ABORT_REQ_EVENT
 * Resut structure : result_union.result_cnf
 *****************************************************************************/
static U8 srv_avrcp_abort_continueing_req(U8 avrcp_chnl);


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_attribute_support_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  TRUE/FALSE
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_attribute_support_status_req(U8 avrcp_chnl, 
    srv_avrcp_player_app_settings_attr_enum attribute_id);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_supported_attr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  enum - intermediate_result
 *****************************************************************************/
static U8 srv_avrcp_get_supported_attr_req(U8 avrcp_chnl, 
    srv_avrcp_player_app_settings_attr_enum supported_attr[]);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_attribute_supported_values_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 *    attr_value[] -is corressponding enum to attribute value.
 *    SRV_AVRCP_PLAYER_APP_SETTING_EQUALIZER   -srv_avrcp_equalizer_state_enum
 *    SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE -srv_avrcp_repeat_mode_enum
 *    SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE -srv_avrcp_shuffle_mode_enum
 *    SRV_AVRCP_PLAYER_APP_SETTING_SCAN_MODE  -srv_avrcp_scan_mode_enum
 * RETURNS
 *  enum - intermediate_result
 *****************************************************************************/
static U8 srv_avrcp_get_attribute_supported_values_req(U8 avrcp_chnl, 
    srv_avrcp_player_app_settings_attr_enum attr_id, U8 attr_val[], U8 *count);

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_unmask_reg_notification_event_id
 * DESCRIPTION
 *  Below are current registered notification for events:
 *     SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED
 *    SRV_AVRCP_EVENT_TRACK_CHANGED
 *    SRV_AVRCP_EVENT_TRACK_REACHED_END
 *    SRV_AVRCP_EVENT_TRACK_REACHED_START
 *    SRV_AVRCP_EVENT_BATT_STATUS_CHANGED
 *    SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED
 *If user want to notify other events of  this enum, user should pass event id.
 *playback_interval for event -  SRV_AVRCP_EVENT_PLAYBACK_POS_CHNAGED otherwise -1
 * PARAMETERS
 *  
 * RETURNS
 *  enum - intermediate_result
 *****************************************************************************/
static U8 srv_avrcp_unmask_reg_notification_event_id(U8 avrcp_chnl, 
    srv_avrcp_metadata_trasnfer_events event_id, S16 playback_interval);

static void srv_avrcp_sdp_query_req(U8 avrcp_chnl);
#endif
/***************************************************************************** 
* External Variable
*****************************************************************************/

/***************************************************************************** 
* Globol Variable
*****************************************************************************/
static const srv_bt_cm_profile_struct g_avrcp_ct_tg_prof = 
{
    SRV_BT_CM_AV_REMOTE_CONTROL_UUID,
    srv_avrcp_activate_req,
    srv_avrcp_deactivate_req,
    srv_avrcp_disconnect_ct_tg_req
};

// TODO: BT_AVRCP_MAX_CHANNEL 2
static srv_avrcp_cntx_struct g_srv_avrcp_cntx[BT_AVRCP_MAX_CHANNEL];

#define BT_AVRCP_MAX_CALLBACK_NUM 2
static SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK g_srv_avrcp_bt_dialer_tg_cmd_fun_ptr = NULL;
static AVRCP_SRV_CMD_CALLBACK g_srv_avrcp_cmd_func_ptr_list[BT_AVRCP_MAX_CALLBACK_NUM]; /* at most 2 func ptr */
static S32 g_srv_avrcp_cmd_func_ptr_count = 0 ; /* at most 2 func ptr */
static U8 g_srv_avrcp_last_pressed_cmd = 0xff; /* last pressed command, 0xff is a non spec command value to identify there is no command */
static U8 g_srv_avrcp_pressed_cmd_count = 0 ;  /* to accumulate total pressed cmd numer with the same av/c command */
static MMI_BOOL g_srv_avrcp_frm_blocked = MMI_FALSE ;  /* framework keypad / touch blocked */

static U8 g_srv_avrcp_cmd_frame_count = 0;  /* accumalute total cmd frame in avrcp srv */
const U8 SRV_AVRCP_CMD_FRAME_COUNT_MAX = 4;

#if defined(__BT_SPEAKER_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)
static void srv_avrcp_sink_timer_callback(srv_bt_cm_bt_addr *dev_addr, U16 op_code, U8 command_type, BOOL key_press);
static void srv_avrcp_ct_set_cmd_frame_cnf_hdlr(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_cmd_cnf_callback callback_func);
#endif /*__BT_SPEAKER_SUPPORT__,__MMI_AVRCP_CT_SUPPORT__*/

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
static MMI_BOOL g_srv_avrcp_actively_connect_tg = MMI_FALSE;
#endif
#ifdef  SRV_A2DP_SINK_BT_AVRCP_CONNECT_CT_ACTIVELY__
static MMI_BOOL g_srv_avrcp_actively_connect_ct = MMI_FALSE;
#endif

#ifdef __MMI_BT_AVRCP_V13__
void mmi_dummy_srv_avrcp_register_event(srv_avrcp_event_enum event_id, srv_avrcp_result_union result);
#endif

/***************************************************************************** 
* External Functions
*****************************************************************************/

/***************************************************************************** 
* Functions
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_channel_valid
 * DESCRIPTION
 *  This function is to check channel index
 * PARAMETERS
 *  avrcp_chnl      :       [IN] avrcp channel
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_channel_valid(S32 avrcp_chnl)
{
    if (avrcp_chnl < 0 || avrcp_chnl >= BT_AVRCP_MAX_CHANNEL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CHANNEL_INDEX_ERROR, avrcp_chnl);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_devices_identical
 * DESCRIPTION
 *  This function is to check two device address identical
 * PARAMETERS
 *  avrcp_chnl      :       [IN] avrcp channel
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_devices_identical(srv_bt_cm_bt_addr *dev_addr1, 
                                                  srv_bt_cm_bt_addr *dev_addr2)
{
    if (dev_addr1 == NULL || dev_addr2 == NULL)
    {
        return MMI_FALSE;
    }

    return ((dev_addr1->lap & 0x00FFFFFF) == (dev_addr2->lap & 0x00FFFFFF)) &&
            (dev_addr1->nap == dev_addr2->nap) &&
            (dev_addr1->uap == dev_addr2->uap) ? MMI_TRUE : MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_cmd_hdlr
 * DESCRIPTION
 *  This function is to get the latest register cmd hdlr ptr
 * PARAMETERS
 *  void
 * RETURNS
 *  AVRCP_SRV_CMD_CALLBACK
 *****************************************************************************/
static AVRCP_SRV_CMD_CALLBACK srv_avrcp_get_cmd_hdlr_func_ptr(void)
{
    S32 i = g_srv_avrcp_cmd_func_ptr_count;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_GET_CMD_HDLR_FUNC_HDLR, i);

    if (i == 0)
    {
        return NULL;
    }

    ASSERT(i <= BT_AVRCP_MAX_CALLBACK_NUM);

    return g_srv_avrcp_cmd_func_ptr_list[i - 1];
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr
 * DESCRIPTION
 *  This function is to get the tg register cmd hdlr ptr
 * PARAMETERS
 *  void
 * RETURNS
 *  AVRCP_SRV_CMD_CALLBACK
 *****************************************************************************/
static SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr(void)
{
    return g_srv_avrcp_bt_dialer_tg_cmd_fun_ptr;
}



/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_reset_context
 * DESCRIPTION
 *  This function is to reset context
 * PARAMETERS
 *  is_init             :       [IN] init flag
 *  avrcp_chnl          :       [IN] channel num
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_reset_context(MMI_BOOL is_init, U8 avrcp_chnl)
{
    if (g_srv_avrcp_cntx[avrcp_chnl].cmgr_id > 0)
    {
        srv_bt_cm_stop_conn(g_srv_avrcp_cntx[avrcp_chnl].cmgr_id);
        g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = 0;
    }

    if (is_init == MMI_TRUE)
    {
        memset(&g_srv_avrcp_cntx[avrcp_chnl], 0, sizeof(srv_avrcp_cntx_struct));
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_IDLE);
        g_srv_avrcp_cntx[avrcp_chnl].is_timer_on = 0;
        g_srv_avrcp_cntx[avrcp_chnl].cmd_frame = 0;
    }
    else
    {
        MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_ACTIVATED);
        /* [MAUI_03486977] should not clear bt address, or notify cm and other app will fail with zero address */
        //memset(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, 0, sizeof(srv_bt_cm_bt_addr));
    }
    
    g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = BT_AVRCP_ROLE_UNDEF;
    g_srv_avrcp_cntx[avrcp_chnl].chnl_num = 0xFF;
   // g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = mmi_bt_dialor_callback;
	g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = NULL;
    g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm = MMI_FALSE;
    
#ifdef __MMI_BT_AVRCP_V13__
    g_srv_avrcp_cntx[avrcp_chnl].intermediate_attr_state = SRV_AVRCP_LIST_PLAYER_INITIAL;
    g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state = SRV_AVRCP_SDP_QUERY_NOT_START;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_init
 * DESCRIPTION
 *  This function is to init avrcp service, called when system boot up or bt reset
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_INIT);
    srv_avrcp_init_event_handler();
    
#ifdef __MMI_BT_AVRCP_V13__
    srv_avrcpv13_init_event_handler();
#endif

    srv_bt_cm_profile_register(&g_avrcp_ct_tg_prof);

    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        srv_avrcp_reset_context(MMI_TRUE, i);
    }
    
//#ifdef __BT_SPEAKER_SUPPORT__
    //srv_a2dp_sink_reg_cb_err_evts(srv_avrcp_sink_send_cmd_frame);
//#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_init_event_handler
 * DESCRIPTION
 *  This function is to init event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_INIT_EVENT_HDLR);

    SetProtocolEventHandler(srv_avrcp_activate_cnf_hdlr, MSG_ID_BT_AVRCP_ACTIVATE_CNF);
    SetProtocolEventHandler(srv_avrcp_deactivate_cnf_hdlr, MSG_ID_BT_AVRCP_DEACTIVATE_CNF);
    SetProtocolEventHandler(srv_avrcp_connect_cnf_hdlr, MSG_ID_BT_AVRCP_CONNECT_CNF);
    SetProtocolEventHandler(srv_avrcp_connect_ind_hdlr, MSG_ID_BT_AVRCP_CONNECT_IND);
    SetProtocolEventHandler(srv_avrcp_connect_ind_req_hdlr, MSG_ID_BT_AVRCP_CONNECT_IND_REQ);
    SetProtocolEventHandler(srv_avrcp_disconnect_cnf_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_CNF);
    SetProtocolEventHandler(srv_avrcp_disconnect_ind_hdlr, MSG_ID_BT_AVRCP_DISCONNECT_IND);

    SetProtocolEventHandler(srv_avrcp_cmd_frame_cnf_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_CNF);
    SetProtocolEventHandler(srv_avrcp_cmd_frame_ind_hdlr, MSG_ID_BT_AVRCP_CMD_FRAME_IND);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_profile_id
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U32 srv_avrcp_get_profile_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 profile_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_id = SRV_BT_CM_AV_REMOTE_CONTROL_UUID;
    return profile_id;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_find_channel_by_channel_num
 * DESCRIPTION
 *  This function is to find channel by channel num
 * PARAMETERS
 *  chnl_num     :   [IN]      channel num
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_avrcp_find_channel_by_channel_num(U8 chnl_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_cntx_struct *cntx_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        cntx_ptr = &g_srv_avrcp_cntx[i]; 
        
        if (cntx_ptr->chnl_num == chnl_num)
        {
            return i;
        }
    }    

    return -1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_find_channel_by_device_addr
 * DESCRIPTION
 *  This function is to find channel by device addr
 * PARAMETERS
 *  bt_addr     :   [IN]      device addr
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_avrcp_find_channel_by_device_addr(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_cntx_struct *cntx_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        cntx_ptr = &g_srv_avrcp_cntx[i]; 
        
        if (cntx_ptr->device_addr.lap == dev_addr->lap &&
            cntx_ptr->device_addr.nap == dev_addr->nap &&
            cntx_ptr->device_addr.uap == dev_addr->uap)
        {
            return i;
        }
    }    

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_find_channel_by_role
 * DESCRIPTION
 *  This function is to find channel by role
 * PARAMETERS
 *  bt_addr     :   [IN]      device addr
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_avrcp_find_channel_by_role(U8 role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_cntx_struct *cntx_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        cntx_ptr = &g_srv_avrcp_cntx[i]; 
        
        if (cntx_ptr->avrcp_role == role)
        {
            return i;
        }
    }    

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_find_channel_by_cmgr_id
 * DESCRIPTION
 *  This function is to find channel by cmgr id
 * PARAMETERS
 *  cmgr_id        :       [IN] cmgr id
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_avrcp_find_channel_by_cmgr_id(U32 cmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_cntx_struct *cntx_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        cntx_ptr = &g_srv_avrcp_cntx[i]; 
        
        if (cntx_ptr->cmgr_id == cmgr_id)
        {
            return i;
        }
    }    

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_free_channel
 * DESCRIPTION
 *  This function is to find free channel
 * PARAMETERS
 *  void
 * RETURNS
 *  S32
 *****************************************************************************/
static S32 srv_avrcp_get_free_channel(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_cntx_struct *cntx_ptr = NULL;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        cntx_ptr = &g_srv_avrcp_cntx[i]; 
        
        if (cntx_ptr->avrcp_state == SRV_AVRCP_ACTIVATED)
        {
            return i;
        }
    }    

    return -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_req
 * DESCRIPTION
 *  This function is to send avrcp all channel request
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_ACTIVATE_REQ);
    
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        MMI_AVRCP_LOG_STATE(i);

        if (MMI_AVRCP_CTX(i, avrcp_state) != SRV_AVRCP_IDLE)
        {
            return;
        }

        MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_ACTIVATING);
    }

    
#if (defined(__MMI_WEARABLE_DEVICE__) && !defined(__MMI_A2DP_SUPPORT__))
    srv_avrcp_send_activate_req(MOD_MMI, BT_AVRCP_CT);/* ON ASTER Project, avrcp only as a CT role */
#else
	/* Currently two channels, use role value as channel number */
	srv_avrcp_send_activate_req(MOD_MMI, BT_AVRCP_CT_TG);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is to response activate confirm msg
 * PARAMETERS
 *  msg         :       [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_activate_cnf_struct *msg_p = (bt_avrcp_activate_cnf_struct*) msg;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_ACTIVATE_CNF_HDLR, msg_p->result);

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
        {
            if (MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_ACTIVATING)
            {
                MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_ACTIVATED);
                srv_bt_cm_activate_cnf_hdler(srv_avrcp_get_profile_id());
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_req
 * DESCRIPTION
 *  This function is to send deactivate request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEACTIVATE_REQ);

    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    {
        MMI_AVRCP_LOG_STATE(i);

        if (MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_ACTIVATED ||
            MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_CONNECTING)
        {
            srv_avrcp_send_deactivate_req(MOD_MMI);
            MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_DEACTIVATING);
        }
        /* If in connected state, need to disconnect in advance */
        else if (MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_CONNECTED)
        {
            srv_avrcp_send_disconnect_req(MOD_MMI, g_srv_avrcp_cntx[i].chnl_num);
            MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_DEACTIVATING);
        }
        /* Wait connect / disconnect response to deactivate AVRCP */
        else if (MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_DISCONNECTING ||
                 MMI_AVRCP_CTX(i, avrcp_state) == SRV_AVRCP_CONNECTING)
        {
            MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_DEACTIVATING);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_deactivate_cnf_hdlr
 * DESCRIPTION
 *  This function is to response deativate confirm msg
 * PARAMETERS
 *  msg         :       [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_deactivate_cnf_struct *msg_p = (bt_avrcp_deactivate_cnf_struct*)msg;
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEACTIVATE_CNF_HDLR, msg_p->result);

    if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
    {
        for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
        {
            MMI_AVRCP_STATE_TRANS(i, SRV_AVRCP_IDLE);
        }

        srv_bt_cm_deactivate_cnf_hdler(srv_avrcp_get_profile_id());
    }
    /* MAUI_03477996 */
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_tg_req
 * DESCRIPTION
 *  This function is to send tg connect request
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_tg_req(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req(BT_AVRCP_TG, dev_addr, cb_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ct_req
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_ct_req(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req(BT_AVRCP_CT, dev_addr, cb_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_req_from_a2dp
 * DESCRIPTION
 *  This function is to ask connect request from a2dp
 * PARAMETERS
 *  role            :       [IN] avrcp role
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_connect_req_from_a2dp(U8 role, srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_addr == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEVICE_ADDR_NULL_EXCEPTION);
        return;
    }
    
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        avrcp_chnl = srv_avrcp_get_free_channel();
    }

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_FROM_A2DP, role, avrcp_chnl);

    if (MMI_FALSE == srv_bt_cm_is_bt_dialer(dev_addr) || 
        BT_AVRCP_TG != role)
    {
        srv_avrcp_connect_req(role, dev_addr, cb_ptr);
    }
    else
    {
        /* set callback */
        if (cb_ptr != NULL)
        {
            g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback = cb_ptr;
            g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = role;
        }

        memcpy(&g_srv_avrcp_cntx[avrcp_chnl].device_addr,
               dev_addr,
               sizeof(srv_bt_cm_bt_addr));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_tg_req_from_a2dp
 * DESCRIPTION
 *  This function is to ask tg connect request from a2dp
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_tg_req_from_a2dp(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req_from_a2dp(BT_AVRCP_TG, dev_addr, cb_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ct_req_from_a2dp
 * DESCRIPTION
 *  This function is to ask ct connect request from a2dp
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_ct_req_from_a2dp(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_avrcp_connect_req_from_a2dp(BT_AVRCP_CT, dev_addr, cb_ptr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_req
 * DESCRIPTION
 *  This function is to send avrcp connect request
 * PARAMETERS
 *  role            :       [IN] avrcp role
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] connectivity callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_connect_req(U8 role, srv_bt_cm_bt_addr *dev_addr, srv_avrcp_connectivity_notify_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 profile_id = 0;
    S32 avrcp_chnl;
	MMI_BOOL is_indicate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dev_addr == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DEVICE_ADDR_NULL_EXCEPTION);
        return;
    }
    
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);   

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        avrcp_chnl = srv_avrcp_get_free_channel();
    }

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_REQ, role, avrcp_chnl);
    }
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    /* set callback */
    if (cb_ptr != NULL)
    {
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback = cb_ptr;
    }

	/* if con from cm */
    if(g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm)
    {
		is_indicate = MMI_FALSE;
	}
	else
	{
		is_indicate = MMI_TRUE;
	}

    /* callback directly if connected */
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state == SRV_AVRCP_CONNECTED)
    {
        srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, is_indicate);
        return;
    }
    
    /* MAUI_03458213 [BT Dialer v2.2][1] Assert fail: Caller Address: 0xf0592c4a Line: 2620 - MMI File: plutommi\Service\AvrcpSrv\AvrcpSrv.c
       if connected, reconnect request will lead cnf hdlr again and clear connect_id to 0 */
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state != SRV_AVRCP_ACTIVATED)
    {
    	srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, is_indicate);
        return;
    }
    
    g_srv_avrcp_cmd_frame_count = 0;
    profile_id = srv_avrcp_get_profile_id();
    g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = srv_bt_cm_start_conn(MMI_FALSE, profile_id, dev_addr, NULL);
    memcpy(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
    g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = role;
    srv_avrcp_send_connect_req(MOD_MMI, (bt_avrcp_dev_addr_struct*)dev_addr, role);

    MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_CONNECTING);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_notify_connectivity_result
 * DESCRIPTION
 *  This function is to notify connectivity result to caller
 * PARAMETERS
 *  avrcp_chnl      :       [IN] avrcp channel index
 *  is_connect      :       [IN] connect or disconnect
 *  is_indicate     :       [IN] indicate flag
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_notify_connectivity_result(U8 avrcp_chnl,
                                                 MMI_BOOL is_connect,
                                                 MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_avrcp_connectivity_notify_result notify_result;
    MMI_BOOL cm_result;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_TRUE == is_connect)
    {
        if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state == SRV_AVRCP_CONNECTED)
        {
            cm_result = MMI_TRUE;
            notify_result = SRV_AVRCP_CONNECTIVITY_CONNECTED;
        }
        else
        {
            cm_result = MMI_FALSE;
            notify_result = SRV_AVRCP_CONNECTIVITY_CONNECT_FAIL;
        }
    }
    else
    {
        if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state == SRV_AVRCP_ACTIVATED)
        {
            cm_result = MMI_TRUE;
            notify_result = SRV_AVRCP_CONNECTIVITY_DISCONNECTED;
        }
        else
        {
            cm_result = MMI_FALSE;
            notify_result = SRV_AVRCP_CONNECTIVITY_DISCONNECT_FAIL;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_NOTIFY_CONNECTIVITY_RESULT, 
              avrcp_chnl,
              g_srv_avrcp_cntx[avrcp_chnl].avrcp_state,
              is_connect,
              g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback,
              notify_result,
              g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback,
              cm_result);
              
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback)
    {
        (*g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback)(
            &g_srv_avrcp_cntx[avrcp_chnl].device_addr, notify_result);
    }    
    
    /* no need to callback cm if tg role */
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback && 
        srv_avrcp_get_role(&g_srv_avrcp_cntx[avrcp_chnl].device_addr) != BT_AVRCP_TG)
    {
        (*g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback)(
            &g_srv_avrcp_cntx[avrcp_chnl].device_addr,
            SRV_BT_CM_AVRCP_CT_CONNECTION, 
            cm_result,
            is_connect,
            is_indicate);

		g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm = MMI_FALSE;
    }

    if (MMI_FALSE == is_connect)
    {
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_conn_notify_callback = NULL;
        /* no need to clear cm callback */
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_hdlr_int
 * DESCRIPTION
 *  This function is to for both connect cnf and indication handle
 * PARAMETERS
 *  avrcp_chnl          :       [IN] avrcp num
 *  chnl_num            :       [IN] channel num
 *  is_indication       :       [IN] specific ind or cnf msg
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_connect_hdlr_int(U8 avrcp_chnl, U8 chnl_num, MMI_BOOL is_indication)
{
    g_srv_avrcp_cntx[avrcp_chnl].chnl_num = chnl_num;
    g_srv_avrcp_last_pressed_cmd = 0xff;
    g_srv_avrcp_pressed_cmd_count = 0;
    
    MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_CONNECTED);

    /* stop conn to reset cm state to idle */
    if (MMI_TRUE == is_indication)
    {
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = 
            srv_avrcp_get_role(&(g_srv_avrcp_cntx[avrcp_chnl].device_addr));
        
        if (g_srv_avrcp_cntx[avrcp_chnl].cmgr_id > 0)
        {
            srv_bt_cm_stop_conn(g_srv_avrcp_cntx[avrcp_chnl].cmgr_id);
            g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = 0;
        }

        g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = 
            srv_bt_cm_start_conn(MMI_TRUE, 
                                 srv_avrcp_get_profile_id(), 
                                 &g_srv_avrcp_cntx[avrcp_chnl].device_addr, 
                                 NULL);
    }

    srv_bt_cm_connect_ind(g_srv_avrcp_cntx[avrcp_chnl].cmgr_id);
    
#ifdef __BT_SPEAKER_SUPPORT__
    srv_avrcp_ct_set_cmd_frame_cnf_hdlr(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, (srv_avrcp_cmd_cnf_callback)srv_avrcp_sink_timer_callback);
#endif //__BT_SPEAKER_SUPPORT__
    
#ifdef __MMI_BT_AVRCP_V13__
    g_srv_avrcp_cntx[avrcp_chnl].event = 0;

    if (is_indication == MMI_TRUE)
    {
        srv_avrcp_sdp_query_req(avrcp_chnl);
    }
    else
    {
        srv_avrcp_open_dev(avrcp_chnl);
    }
#endif //__MMI_BT_AVRCP_V13__
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is to response connect confirm msg
 * PARAMETERS
 *  msg         :       [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_cnf_struct *msg_p = (bt_avrcp_connect_cnf_struct*)msg;
    S32 avrcp_chnl;
    MMI_BOOL is_indicate;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* can only get channel num by device addr */
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr((srv_bt_cm_bt_addr*)(&(msg_p->device_addr)));

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_CONNECT_CNF_HDLR, 
              msg_p->result, 
              avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_CONNECTING:
        {

			if (g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm)
			{
			  is_indicate = MMI_FALSE;
			}
			else
			{
			  is_indicate = MMI_TRUE;
			}
            /* Change state when connect success */
            if (msg_p->result == BT_AVRCP_RESULT_SUCCESS)
            {
				srv_avrcp_connect_hdlr_int(avrcp_chnl, msg_p->chnl_num, MMI_FALSE);
				/* notify caller avrcp connect has finished */
				srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, is_indicate);
            #if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)/*no need to callback cm app if bt dialer  was closed*/
				BT_Music_app_emit_event(EVT_ID_BT_MUSIC_AVRCP_CONNECTED_EVENT_ID, (void*) &g_srv_avrcp_cntx[avrcp_chnl].device_addr);
            #endif
            }
            /* Connect fail */
            else
            {
            	/* notify caller avrcp connect has finished */
            	/* stop connection @ cm firstly, and then callback cm app*/
            	if (g_srv_avrcp_cntx[avrcp_chnl].cmgr_id > 0)
            	{
            	    srv_bt_cm_stop_conn(g_srv_avrcp_cntx[avrcp_chnl].cmgr_id);
            	    g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = 0;
            	}
            	srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, MMI_FALSE);
				srv_avrcp_reset_context(MMI_FALSE, avrcp_chnl);
            }

            break;
        }
        
        case SRV_AVRCP_DISCONNECTING:
        {
            break;
        }

        case SRV_AVRCP_DEACTIVATING:
        {
            srv_avrcp_send_deactivate_req(MOD_MMI);
            break;
        }

        default:
        {
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_only_single_headset_connected
 * DESCRIPTION
 *  This function is to check only single headset device connected
 * PARAMETERS
 *  dev_addr         :       [IN] device address     
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_only_single_headset_connected(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* only one handset for dialer */
    for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
    { 
        if (MMI_AVRCP_CTX(i, avrcp_state) != SRV_AVRCP_CONNECTED)
        {
            continue;
        }

        if (srv_avrcp_get_role(&g_srv_avrcp_cntx[i].device_addr) == BT_AVRCP_TG && 
            srv_avrcp_get_role(dev_addr) == BT_AVRCP_TG && 
            MMI_FALSE == srv_avrcp_check_devices_identical(&g_srv_avrcp_cntx[i].device_addr, dev_addr))
        {
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to response connect indication req msg
 * PARAMETERS
 *  msg         :       [IN] indication msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_connect_ind_req_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_ind_req_struct *msg_p = (bt_avrcp_connect_ind_req_struct*)msg;
    bt_avrcp_connect_ind_rsp_struct *send_msg;
    srv_bt_cm_bt_addr *exist_addr;
    //U32 dev_count;
    S32 avrcp_chnl;
    MMI_BOOL is_bt_dialer;
    kal_bool accept_conn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr((srv_bt_cm_bt_addr*)(&(msg_p->device_addr)));
    is_bt_dialer = srv_bt_cm_is_bt_dialer((srv_bt_cm_bt_addr*)(&msg_p->device_addr));
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        avrcp_chnl = srv_avrcp_get_free_channel();
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_IND_REQ_HDLR, is_bt_dialer, avrcp_chnl);

    // TODO: reject in some case
    do
    {
        /* not valid channel for connect indication request */
        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            accept_conn = KAL_FALSE;
            break;
        }
        
        /* only one handset for dialer */
        if (MMI_FALSE == srv_avrcp_check_only_single_headset_connected((srv_bt_cm_bt_addr*)(&msg_p->device_addr)))
        {
            accept_conn = KAL_FALSE;
            break;
        }
        
        /* reject if previous device is busy connecting and now new device coming to connect */
        exist_addr = (srv_bt_cm_bt_addr*)srv_bt_cm_get_busy_dev();
        if (exist_addr != NULL && srv_avrcp_check_devices_identical(
            exist_addr,
            (srv_bt_cm_bt_addr*)(&(msg_p->device_addr))) == MMI_FALSE)
        {
            accept_conn = KAL_FALSE;
            break;
        }

        g_srv_avrcp_cntx[avrcp_chnl].avrcp_state = SRV_AVRCP_CONNECTING;
        memcpy(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, 
               (srv_bt_cm_bt_addr*)(&msg_p->device_addr),
               sizeof(srv_bt_cm_bt_addr));
        accept_conn = KAL_TRUE;
    } while(0);
    
    send_msg = (bt_avrcp_connect_ind_rsp_struct*)
            construct_local_para(sizeof(bt_avrcp_connect_ind_rsp_struct), TD_CTRL);
    send_msg->accept_conn = accept_conn;
    send_msg->chnl_num = msg_p->chnl_num;
    srv_avrcp_send_msg_to_bt(MOD_MMI, (kal_uint16)MSG_ID_BT_AVRCP_CONNECT_IND_RSP, send_msg, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_connect_ind_hdlr
 * DESCRIPTION
 *  This function is to response connect indication msg
 * PARAMETERS
 *  msg         :       [IN] indication msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_connect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_connect_ind_struct *msg_p = (bt_avrcp_connect_ind_struct*)msg;
    S32 avrcp_chnl;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr((srv_bt_cm_bt_addr*)(&(msg_p->device_addr)));
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CONNECT_IND_HDLR, msg_p->chnl_num, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_ACTIVATED:
        case SRV_AVRCP_CONNECTING:
        {
            memcpy(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, 
                   (srv_bt_cm_bt_addr*)(&(msg_p->device_addr)),
                   sizeof(srv_bt_cm_bt_addr));
            
            srv_avrcp_connect_hdlr_int(avrcp_chnl, msg_p->chnl_num, MMI_TRUE);
        #if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)/*no need to callback cm app if bt dialer  was closed*/
            /* need notify cm indicate connect has finished */
			if(!g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback)
				g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = mmi_bt_dialor_callback;
        #endif /*defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)*/
			
			/* notify caller avrcp indicate connect has finished */
            srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, MMI_TRUE);
		#if	 defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__) /*no need to callback bt music app if bt dialer  was closed */	
			BT_Music_app_emit_event(EVT_ID_BT_MUSIC_AVRCP_CONNECTED_EVENT_ID, (void*) &g_srv_avrcp_cntx[avrcp_chnl].device_addr);
		#endif /*defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)*/
            break;
        }
        
        default:
        {
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_role_from_a2dp
 * DESCRIPTION
 *  This function is to get a2dp role
 * PARAMETERS
 *  a2dp_role        :       [IN] a2dp_role     
 * RETURNS
 *  S32
 *****************************************************************************/
static U8 srv_avrcp_get_role_from_a2dp(U8 a2dp_role)
{
    switch (a2dp_role)
    {
        case BT_A2DP_SINK:
        {
            return BT_AVRCP_CT;
        }

        case BT_A2DP_SOURCE:
        {
            return BT_AVRCP_TG;
        }

        default:
        {
            return BT_AVRCP_ROLE_UNDEF;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_role
 * DESCRIPTION
 *  get avrcp role
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_avrcp_get_role(srv_bt_cm_bt_addr *dev_addr)
{
    U8 role = BT_AVRCP_ROLE_UNDEF;

    do
    {
        S32 avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            break;
        }

        role = g_srv_avrcp_cntx[avrcp_chnl].avrcp_role;

    #ifdef __MMI_A2DP_SUPPORT__
        if (role == BT_AVRCP_ROLE_UNDEF)
        {
            role = srv_avrcp_get_role_from_a2dp(srv_a2dp_get_role(dev_addr));
        }
    #endif
    } while(0);

	MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_GET_ROLE, role);
    return role;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_role
 * DESCRIPTION
 *  set role callback
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  a2dp_role       :       [IN] a2dp_role
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_role(srv_bt_cm_bt_addr *dev_addr, U8 a2dp_role)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = srv_avrcp_get_role_from_a2dp(a2dp_role);
    
    /* need to sdp query again if sdp has fail for undef role */
#ifdef __MMI_BT_AVRCP_V13__
    if (g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state == SRV_AVRCP_SDP_QUERY_UNDEF_ROLE_ERR)
    {
        srv_avrcp_sdp_query_req(avrcp_chnl);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_from_a2dp
 * DESCRIPTION
 *  to set the flag of disconnect avrcp from av_bt, 
 *  so that we can judge if we shall inform cm for disconnect ind or cnf
 * PARAMETERS
 *  dev_addr    :       [IN] device address
 *  set         :       [IN] flag
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_from_a2dp(srv_bt_cm_bt_addr *dev_addr, MMI_BOOL set)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;   
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_DISCONNECT_FROM_AVBT,
              g_srv_avrcp_cntx[avrcp_chnl].disconnect_from_a2dp,
              set);

    g_srv_avrcp_cntx[avrcp_chnl].disconnect_from_a2dp = set;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_tg_req
 * DESCRIPTION
 *  This function is to send disconnect tg request
 * PARAMETERS
 *  dev_addr            :           [IN] device address
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_tg_req(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_TG_REQ);
    srv_avrcp_disconnect_req(dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_ct_req
 * DESCRIPTION
 *  This function is to send disconnect ct request
 * PARAMETERS
 *  dev_addr            :           [IN] device address
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_ct_req(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_CT_REQ);
    srv_avrcp_disconnect_req(dev_addr);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_ct_tg_req
 * DESCRIPTION
 *  This function is to disconnect tg and ct by cmgr id
 * PARAMETERS
 *  cmgr_id         :       [IN] cmgr id
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_ct_tg_req(U32 cmgr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl = srv_avrcp_find_channel_by_cmgr_id(cmgr_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_CT_TG_REQ, -1, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_CT_TG_REQ, g_srv_avrcp_cntx[avrcp_chnl].avrcp_role, avrcp_chnl);
    srv_avrcp_disconnect_req(&(g_srv_avrcp_cntx[avrcp_chnl].device_addr));
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_req
 * DESCRIPTION
 *  This function is to send disconnect request
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_req(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;
    MMI_BOOL is_indicate;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_REQ, avrcp_chnl);

    if(g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm)
    {
		is_indicate = MMI_FALSE;
	}
	else
	{
		is_indicate = MMI_TRUE;
	}

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        /* notify caller avrcp disconnect has finished */
        srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_FALSE, is_indicate);
        return;
    }
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);
    
    /* callback directly if disconnected */
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state == SRV_AVRCP_ACTIVATED)
    {
        srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_FALSE, is_indicate);
        return;
    }

    if (MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == SRV_AVRCP_CONNECTED ||
        MMI_AVRCP_CTX(avrcp_chnl,avrcp_state) == SRV_AVRCP_CONNECTING)
    {
        /* MAUI_03477996 */
        if (g_srv_avrcp_cntx[avrcp_chnl].chnl_num != 0xFF)
        {
            srv_avrcp_send_disconnect_req(MOD_MMI, g_srv_avrcp_cntx[avrcp_chnl].chnl_num);
            MMI_AVRCP_STATE_TRANS(avrcp_chnl, SRV_AVRCP_DISCONNECTING);
        }
    }
    else
    {
        srv_avrcp_disconnect_from_a2dp(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, MMI_FALSE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_cnf_hdlr
 * DESCRIPTION
 *  This function is to
 * PARAMETERS
 *  msg         :       [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_cnf_struct *msg_p = (bt_avrcp_disconnect_cnf_struct*) msg;
    S32 avrcp_chnl;
	MMI_BOOL is_indicate;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_CNF_HDLR, msg_p->chnl_num, avrcp_chnl);

    if (msg_p->result != BT_AVRCP_RESULT_SUCCESS)
    {
        return;
    }
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }

    g_srv_avrcp_cmd_frame_count = 0;
    
    srv_avrcp_disconnect_from_a2dp(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, MMI_FALSE);

    switch (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state))
    {
        case SRV_AVRCP_DISCONNECTING:
        {
			//MAUI_03512531
			if (g_srv_avrcp_cntx[avrcp_chnl].cmgr_id > 0)
			{
				srv_bt_cm_stop_conn(g_srv_avrcp_cntx[avrcp_chnl].cmgr_id);
				g_srv_avrcp_cntx[avrcp_chnl].cmgr_id = 0;
			}
            /* notify caller avrcp disconnect has finished */
			if (g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm)
			{
			  is_indicate = MMI_FALSE;
			}
			else
			{
			  is_indicate = MMI_TRUE;
			}
		
            srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_FALSE, is_indicate);
			srv_avrcp_reset_context(MMI_FALSE, avrcp_chnl);

        #ifdef __MMI_BT_AVRCP_V13__
            srv_avrcp_close_dev(avrcp_chnl);
        #endif
            break;
        }

        case SRV_AVRCP_DEACTIVATING:
        {
            srv_avrcp_send_deactivate_req(MOD_MMI);
            break;
        }

        default:
        {
            MMI_AVRCP_LOG_STATE_ERR(avrcp_chnl);
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_disconnect_ind_hdlr
 * DESCRIPTION
 *  This function is to response disconnect indication msg
 * PARAMETERS
 *  msg         :           [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_disconnect_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_disconnect_ind_struct *msg_p = (bt_avrcp_disconnect_ind_struct*)msg;
    S32 avrcp_chnl;
    AVRCP_SRV_CMD_CALLBACK func_ptr;
    SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK tg_cmd_func_ptr;
    srv_avrcp_key_events key_events;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_DISCONNECT_IND_HDLR, msg_p->chnl_num, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    g_srv_avrcp_cmd_frame_count = 0;
    
    srv_avrcp_disconnect_from_a2dp(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, MMI_FALSE);

    /* Change to activated state if not in idle state */
    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) > SRV_AVRCP_IDLE)
    {
        srv_avrcp_reset_context(MMI_FALSE, avrcp_chnl);
		
	#if	defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)/*no need to callback cm app if bt dialer  was closed*/
		/* need notify cm indicate disconnect has finished */
		if(!g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback)
			g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = mmi_bt_dialor_callback;
	#endif

        /* notify caller avrcp indicate disconnect has finished */
        srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_FALSE, MMI_TRUE);

	#if	defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)/*no need to callback bt music app if bt dialer  was closed*/
		/* notify bt music app avrcp indicate disconnect has finished */
		BT_Music_app_emit_event(EVT_ID_BT_MUSIC_AVRCP_DISCONNECTED_EVENT_ID, (void*) &g_srv_avrcp_cntx[avrcp_chnl].device_addr);
	#endif/*defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)*/

        /*to handle the button down cancel action*/
        func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr();
        tg_cmd_func_ptr = srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr();
           
        if ((func_ptr != NULL || tg_cmd_func_ptr != NULL) && g_srv_avrcp_last_pressed_cmd != 0xff)
        {
            key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_CANCELED;

            if (srv_avrcp_bt_dialer_tg_cmd_callback_int(
                avrcp_chnl, g_srv_avrcp_last_pressed_cmd, key_events) != BT_AVRCP_CR_ACCEPT)
            {
                func_ptr(g_srv_avrcp_last_pressed_cmd, key_events);
            }

            g_srv_avrcp_last_pressed_cmd = 0xff;
            g_srv_avrcp_pressed_cmd_count = 0;
        }       
    }
    
#ifdef __MMI_BT_AVRCP_V13__
    srv_avrcp_close_dev(avrcp_chnl);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_req
 * DESCRIPTION
 *  This function is to send cmd frame request
 * PARAMETERS
 *  avrcp_chnl          :           [IN] avrcp channel
 *  op_code             :           [IN] op code
 *  op_id               :           [IN] op id
 *  key_down            :           [IN] key down flag
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_cmd_frame_req(U8 avrcp_chnl, U8 op_code, U8 op_id, U8 key_down)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 ctype = 0;
    U8 subunit_type = 0;
    U8 subunit_id = 0;
    U8 send_data[BT_AVRCP_MAX_CMD_FRAME_SIZE];
    U16 length = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CMD_FRAME_REQ);
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) != SRV_AVRCP_CONNECTED)
    {
        return;
    }
    
    if (g_srv_avrcp_cmd_frame_count ==  SRV_AVRCP_CMD_FRAME_COUNT_MAX)
    {
        kal_print_string_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "srv_avrcp_cmd_frame_req: g_srv_avrcp_cmd_frame_count reach max");   
        return;
    }

    switch (op_code)
    {
        case BT_AVRCP_OP_UNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO;
            subunit_id = BT_AVRCP_SUBUNIT_ID_UNIT_INFO;
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0xFF;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6;
            
        break;

        case BT_AVRCP_OP_SUBUNIT_INFO:
            ctype = BT_AVRCP_CR_STATUS;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO; 
            subunit_id = BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO;
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0xFF;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF; 
            length = 6; 
            
        break;

        case BT_AVRCP_OP_PASS_THROUGH:
            ctype = BT_AVRCP_CR_CONTROL;
            subunit_type = BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH;            
            subunit_id = BT_AVRCP_SUBUNIT_ID_PASS_THROUGH;
            send_data[0] = BT_AVRCP_OP_PASS_THROUGH;

            if (key_down) /* down */
            {
                send_data[1] = op_id;
            }
            else /* up */
            {
                send_data[1] = op_id | 0x80;          
            }

            send_data[2] = 0;
            length = 3 ;
        break;

        case BT_AVRCP_OP_VENDOR:
        default:
            /*not support now*/
        return;
    }
        
    g_srv_avrcp_cmd_frame_count++;
    
    srv_avrcp_send_cmd_frame_req(MOD_MMI,
                                 g_srv_avrcp_cntx[avrcp_chnl].chnl_num,
                                 0, /* Not used */
                                 ctype,
                                 subunit_type,
                                 subunit_id,
                                 length,
                                 &send_data[0]);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  This function is to set cmd frame confirm handler
 * PARAMETERS
 *  dev_addr            :           [IN] device address
 *  callback_func       :           [IN] call back
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_cmd_frame_cnf_hdlr(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_cmd_cnf_callback callback_func)
{
#ifdef __MMI_AVRCP_CT_SUPPORT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr = callback_func;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_cnf_hdlr
 * DESCRIPTION
 *  This function is to response cmd frame confirm msg
 * PARAMETERS
 *  msg             :           [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_cmd_frame_cnf_hdlr(void *msg)
{
#if defined(__BT_SPEAKER_SUPPORT__) || defined (__MMI_AVRCP_CT_SUPPORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_cnf_struct *msg_p = (bt_avrcp_cmd_frame_cnf_struct*) msg;
    U16 cmd_type = 0;
    S32 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CMD_FRAME_CNF_HDLR, msg_p->chnl_num, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);
    
    g_srv_avrcp_cmd_frame_count--;

    cmd_type = srv_avrcp_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
                
    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
        {
            if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr != NULL)
            {
                g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr(
                    &g_srv_avrcp_cntx[avrcp_chnl].device_addr,
                    BT_AVRCP_OP_UNIT_INFO, 
                    0, 
                    (MMI_BOOL)0);
            }
            
            break;
        }

        case BT_AVRCP_OP_SUBUNIT_INFO:
        {
            if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr != NULL)
            {
                g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr(
                    &g_srv_avrcp_cntx[avrcp_chnl].device_addr,
                    BT_AVRCP_OP_SUBUNIT_INFO, 
                    0, 
                    (MMI_BOOL)0);
            }
            
            break;
        }

        case BT_AVRCP_OP_PASS_THROUGH:
        {
            if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr != NULL)
            {
                if (g_srv_avrcp_cntx[avrcp_chnl].is_timer_on)
                {
                    g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr(
                        &g_srv_avrcp_cntx[avrcp_chnl].device_addr,
                        BT_AVRCP_OP_PASS_THROUGH, 
                        (U16)(msg_p->frame_data[1] & 0x7f), 
                        (MMI_BOOL)(msg_p->frame_data[1] & 0x80));
                }
            }
            
            break;
        }

        default:
        {
            break;
        }
    }
#endif /* __MMI_AVRCP_CT_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_bt_dialer_tg_cmd_callback_int
 * DESCRIPTION
 *  This function is to response bt dialer cmd frame
 * PARAMETERS
 *  avrcp_chnl          :           [IN] avrcp channel
 *  command             :           [IN] command
 *  key_events          :           [IN] key events
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static U8 srv_avrcp_bt_dialer_tg_cmd_callback_int(U8 avrcp_chnl, U8 command, srv_avrcp_key_events key_events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK tg_cmd_func_ptr = srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr();
    srv_avrcp_state_enum state = MMI_AVRCP_CTX(avrcp_chnl, avrcp_state);
    MMI_BOOL is_dialer = srv_bt_cm_is_bt_dialer(&g_srv_avrcp_cntx[avrcp_chnl].device_addr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,
              MMI_AVRCP_CT_TRC_TG_CMD_CALLBACK,
              is_dialer,
              tg_cmd_func_ptr,
              state,
              command,
              key_events);
              
    if (!tg_cmd_func_ptr || state != SRV_AVRCP_CONNECTED)
    {
        return BT_AVRCP_CR_NOT_IMPLEMENT;
    }

    /* not our dialer, return directly */
    if (MMI_FALSE == srv_bt_cm_is_bt_dialer(&g_srv_avrcp_cntx[avrcp_chnl].device_addr))
    {
        return BT_AVRCP_CR_REJECT;
    }
    
    return tg_cmd_func_ptr(&g_srv_avrcp_cntx[avrcp_chnl].device_addr, command, key_events) == 
        MMI_TRUE ? BT_AVRCP_CR_ACCEPT : BT_AVRCP_CR_REJECT;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_cmd_frame_ind_hdlr
 * DESCRIPTION
 *  This function is to response cmd frame indication msg
 * PARAMETERS
 *  msg             :           [IN] received msg     
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_cmd_frame_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_cmd_frame_ind_struct *msg_p = (bt_avrcp_cmd_frame_ind_struct*)msg;
    AVRCP_SRV_CMD_CALLBACK func_ptr;
    SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK tg_cmd_func_ptr;
    srv_avrcp_key_events key_events;
    U16 cmd_type = 0;
    U8 send_len;
    U8 send_data[6];
    U8 type_result = BT_AVRCP_CR_NOT_IMPLEMENT;
    S32 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_CMD_FRAME_IND_HDLR, 
              g_srv_avrcp_frm_blocked,
              msg_p->chnl_num,
              avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    MMI_AVRCP_LOG_STATE(avrcp_chnl);

    cmd_type = srv_avrcp_check_cmd_type(
                msg_p->c_type,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);

#ifdef __MMI_A2DP_SUPPORT__
    //srv_a2dp_check_and_restart_disc_timer();
#endif

    switch (cmd_type)
    {
        case BT_AVRCP_OP_UNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_UNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            srv_avrcp_send_cmd_frame_ind_rsp(
                MOD_MMI,
                g_srv_avrcp_cntx[avrcp_chnl].chnl_num,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_UNIT_INFO,
                send_len,
                send_data);
            break;
        }

        case BT_AVRCP_OP_SUBUNIT_INFO:
        {
            send_data[0] = BT_AVRCP_OP_SUBUNIT_INFO;
            send_data[1] = 0x07;
            send_data[2] = 0x48;
            send_data[3] = 0xFF;
            send_data[4] = 0xFF;
            send_data[5] = 0xFF;
            send_len = 6;

            srv_avrcp_send_cmd_frame_ind_rsp(
                MOD_MMI,
                g_srv_avrcp_cntx[avrcp_chnl].chnl_num,                
                msg_p->seq_id,
                msg_p->profile_id,
                BT_AVRCP_CR_STABLE,
                BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO,
                BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO,
                send_len,
                send_data);
            break;
        }

        case BT_AVRCP_OP_PASS_THROUGH:
        {
            type_result = MMI_AVRCP_CR_REJECT;
            func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr();
            tg_cmd_func_ptr = srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr();
            
            if ((func_ptr != NULL || tg_cmd_func_ptr != NULL) && !g_srv_avrcp_frm_blocked)
            {
                U8 command = msg_p->frame_data[1] & 0x7f ;
                if ((msg_p->frame_data[1] & 0x80) == 0)
                {
                    /*key pressed*/

                    /* receive another pressed cmd while previous */
                    /* pressed command has not released yet,      */
                    /* 1. auto relase previous command first      */
                    /* 2. pass current pressed cmd                */
                    if ((g_srv_avrcp_last_pressed_cmd != 0xff) && (g_srv_avrcp_last_pressed_cmd != command))
                    {
                        srv_avrcp_auto_release_cmd((void*)avrcp_chnl);
                        g_srv_avrcp_last_pressed_cmd = command ;
                        g_srv_avrcp_pressed_cmd_count = 1 ;
                        key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_DOWN;
                        
                        if ((type_result = srv_avrcp_bt_dialer_tg_cmd_callback_int(
                            avrcp_chnl, command, key_events)) != BT_AVRCP_CR_ACCEPT)
                        {
                            if (func_ptr)
                            {
                                type_result = func_ptr(command, key_events);
                            }
                        }

                        StartTimerEx(BT_AVRCP_AUTO_RELEASE_TIMER, 
                                     2000, 
                                     (oslTimerFuncPtr)srv_avrcp_auto_release_cmd,
                                     (void*)avrcp_chnl);
                    }
                    /* receive the same pressed cmd, */
                    /* 1. restart timer              */
                    /* 2. pass longpress or repeat   */
                    else if (g_srv_avrcp_last_pressed_cmd == command)
                    {
                        StartTimerEx(BT_AVRCP_AUTO_RELEASE_TIMER, 
                                     2000, 
                                     (oslTimerFuncPtr)srv_avrcp_auto_release_cmd,
                                     (void*)avrcp_chnl);
                        g_srv_avrcp_pressed_cmd_count ++;
                        
                        if (g_srv_avrcp_pressed_cmd_count > 2)
                        {
                            key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_REPEAT;
                        }
                        else
                        {
                            key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_LONGPRESS;
                        }

                        if ((type_result = srv_avrcp_bt_dialer_tg_cmd_callback_int(
                            avrcp_chnl, command, key_events)) != BT_AVRCP_CR_ACCEPT)
                        {
                            if (func_ptr)
                            {
                                type_result = func_ptr(command, key_events);
                            }
                        }

                        if (type_result == MMI_AVRCP_CR_REJECT)
                        {
                            --g_srv_avrcp_pressed_cmd_count;
                        }
                    }
                    /* first time receive pressed cmd */
                    else
                    {
                        g_srv_avrcp_last_pressed_cmd = command ;
                        g_srv_avrcp_pressed_cmd_count = 1 ;
                        key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_DOWN;
                        
                        if ((type_result = srv_avrcp_bt_dialer_tg_cmd_callback_int(
                            avrcp_chnl, command, key_events)) != BT_AVRCP_CR_ACCEPT)
                        {
                            if (func_ptr)
                            {
                                type_result = func_ptr(command, key_events);
                            }
                        }
                        
                        StartTimerEx(BT_AVRCP_AUTO_RELEASE_TIMER, 
                                     2000, 
                                     (oslTimerFuncPtr)srv_avrcp_auto_release_cmd,
                                     (void*)avrcp_chnl);
                    }
                }
                else if (g_srv_avrcp_last_pressed_cmd == command)
                {
                    /*key released and matched key pressed command*/
                    /*reset previous pressed command to oxff*/
                    StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
                    g_srv_avrcp_last_pressed_cmd = 0xff ;
                    g_srv_avrcp_pressed_cmd_count = 0 ;
                    key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_UP;
                    
                    if ((type_result = srv_avrcp_bt_dialer_tg_cmd_callback_int(
                        avrcp_chnl, command, key_events)) != BT_AVRCP_CR_ACCEPT)
                    {
                        if (func_ptr)
                        {
                            type_result = func_ptr(command, key_events);
                        }
                    }
                }
                else
                {
                    /*key released but key pressed command not matched*/
                    type_result = MMI_AVRCP_CR_REJECT ;
                }
            }

        #ifndef __MMI_AVRCP_TEST__
            srv_avrcp_send_cmd_frame_ind_rsp(
                MOD_MMI,
                g_srv_avrcp_cntx[avrcp_chnl].chnl_num,                
                msg_p->seq_id,
                msg_p->profile_id,
                type_result,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
        #endif
            break;
        }

        case BT_AVRCP_OP_VENDOR:
        {
            type_result = MMI_AVRCP_CR_REJECT;

            msg_p->frame_data[1] = 0x00;
            msg_p->frame_data[2] = 0x19;
            msg_p->frame_data[3] = 0x58;

            msg_p->frame_data[5] = 0x00;    // packet type
            msg_p->frame_data[6] = 0x00;    // parameter length
            msg_p->frame_data[7] = 0x01;    // parameter length
            msg_p->frame_data[8] = 0x00;    // error code: invalid cmd
            msg_p->data_len = 9;            // opcode: 1 + company id: 3 + pdu id: 1 + packet type: 1 + len: 2 + error code: 1

            srv_avrcp_send_cmd_frame_ind_rsp(
                MOD_MMI,
                g_srv_avrcp_cntx[avrcp_chnl].chnl_num,
                msg_p->seq_id,
                msg_p->profile_id,
                type_result,
                msg_p->subunit_type,
                msg_p->subunit_id,
                msg_p->data_len,
                msg_p->frame_data);
            break;
        }

        default:
        {
            // TODO: Error Trace Here.
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_cmd_hdlr
 * DESCRIPTION
 *  This function is to set command response handler
 * PARAMETERS
 *  callback_func       :       [IN] callback function       
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Already registered */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_CMD_HDLR);
    
    for (i = 0; i < BT_AVRCP_MAX_CALLBACK_NUM; ++i)
    {
        if (g_srv_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            return;
        }
    }
    
    ASSERT(g_srv_avrcp_cmd_func_ptr_count < BT_AVRCP_MAX_CALLBACK_NUM);

    g_srv_avrcp_cmd_func_ptr_list[g_srv_avrcp_cmd_func_ptr_count++] = callback_func;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_CMD_HDLR1, g_srv_avrcp_cmd_func_ptr_count);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_clear_cmd_hdlr
 * DESCRIPTION
 *  This function is to clear command handler
 * PARAMETERS
 *  callback_func           :       [IN] callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_clear_cmd_hdlr(AVRCP_SRV_CMD_CALLBACK callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CLEAR_CMD_HDLR,g_srv_avrcp_cmd_func_ptr_count);
    
    for (i = 0; i < BT_AVRCP_MAX_CALLBACK_NUM; ++i)
    {
        if (g_srv_avrcp_cmd_func_ptr_list[i] == callback_func)
        {
            g_srv_avrcp_cmd_func_ptr_list[i] = NULL;
            --g_srv_avrcp_cmd_func_ptr_count;
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CLEAR_CMD_HDLR1, g_srv_avrcp_cmd_func_ptr_count);            
        }
    }

    if (g_srv_avrcp_cmd_func_ptr_list[0] == NULL && g_srv_avrcp_cmd_func_ptr_list[1] != NULL)
    {
       g_srv_avrcp_cmd_func_ptr_list[0] = g_srv_avrcp_cmd_func_ptr_list[1];
       g_srv_avrcp_cmd_func_ptr_list[1] = NULL;
    }

	/*MAUI_03507244*/
	if(srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr() == NULL && g_srv_avrcp_cmd_func_ptr_count == 0)
	{
       g_srv_avrcp_last_pressed_cmd = 0xff;
       g_srv_avrcp_pressed_cmd_count = 0;
	}
	
    ASSERT(g_srv_avrcp_cmd_func_ptr_count >= 0);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_auto_release_cmd
 * DESCRIPTION
 *  automatically pass a released command to application
 * PARAMETERS
 *  arg         :       [IN] channel num
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_auto_release_cmd(void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AVRCP_SRV_CMD_CALLBACK func_ptr;
    SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK tg_cmd_func_ptr;
    U32 avrcp_chnl = (U32)arg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AUTO_RELEASE1);
    func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr();
    tg_cmd_func_ptr = srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr();

    if ((func_ptr != NULL || tg_cmd_func_ptr != NULL) && g_srv_avrcp_last_pressed_cmd != 0xff)
    {
        srv_avrcp_key_events key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_UP;
        
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AUTO_RELEASE2);

        if (srv_avrcp_bt_dialer_tg_cmd_callback_int(
            (U8)avrcp_chnl, g_srv_avrcp_last_pressed_cmd, key_events) != BT_AVRCP_CR_ACCEPT)
        {
            func_ptr(g_srv_avrcp_last_pressed_cmd, key_events);
        }
        
        g_srv_avrcp_last_pressed_cmd = 0xff ;
        g_srv_avrcp_pressed_cmd_count = 0;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_frm_sync_calllback
 * DESCRIPTION
 *  for framework to callback if keypad / touch is triggered.
 * PARAMETERS
 *  BOOL    [IN] is keypad / touch blocked by target
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_frm_sync_calllback(MMI_BOOL is_blocked)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    AVRCP_SRV_CMD_CALLBACK func_ptr;
    SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK tg_cmd_func_ptr;
    srv_avrcp_key_events key_events;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_BLOCK, is_blocked);

    g_srv_avrcp_frm_blocked = is_blocked;
    
    /* if blocked                                            */
    /* 1. cancel previous key down cmd                       */
    /* 2. pass key up cmd for previous longpress, repeat cmd */
    func_ptr = srv_avrcp_get_cmd_hdlr_func_ptr();
    tg_cmd_func_ptr = srv_avrcp_get_bt_didaler_tg_cmd_hdlr_func_ptr();
            
    if ((func_ptr != NULL || tg_cmd_func_ptr != NULL) && g_srv_avrcp_last_pressed_cmd != 0xff)
    {
        U32 i;
        MMI_BOOL ignore_other_app = MMI_FALSE;
        
        if (g_srv_avrcp_pressed_cmd_count == 1)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_SYNC1);
            key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_CANCELED;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_FRAMEWORK_SYNC2);
            key_events = (srv_avrcp_key_events)MMI_AVRCP_KEY_UP;
        }

        for (i = 0; i < BT_AVRCP_MAX_CHANNEL; ++i)
        {
            /* callback bt music key command */
            if (srv_avrcp_bt_dialer_tg_cmd_callback_int(
                i, g_srv_avrcp_last_pressed_cmd, key_events) == BT_AVRCP_CR_ACCEPT)
            {
                ignore_other_app = MMI_TRUE;
                break;
            }
        }

        if (MMI_FALSE == ignore_other_app)
        {
            func_ptr(g_srv_avrcp_last_pressed_cmd, key_events);
        }
        
        StopTimer(BT_AVRCP_AUTO_RELEASE_TIMER);
        g_srv_avrcp_last_pressed_cmd = 0xff;
        g_srv_avrcp_pressed_cmd_count = 0;
    }
}

void srv_avrcp_connect_from_cm(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_cm_callback cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_CONNECT_FROM_CM,
              cb_ptr,
              avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        avrcp_chnl = srv_avrcp_get_free_channel();
    }

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        if (cb_ptr)
        {
            cb_ptr(dev_addr, SRV_BT_CM_AVRCP_CT_CONNECTION, MMI_FALSE, MMI_TRUE, MMI_FALSE);
        }
        
        return;
    }
    
    if (cb_ptr)
    {
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = cb_ptr;
		g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm = MMI_TRUE; 
    }

    // MAUI_03495342
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state == SRV_AVRCP_CONNECTED)
    {
        srv_avrcp_notify_connectivity_result(avrcp_chnl, MMI_TRUE, MMI_FALSE);
    #ifdef __MMI_BT_AVRCP_V13__
        if (g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state == SRV_AVRCP_SDP_QUERY_UNDEF_ROLE_ERR)
        {
            g_srv_avrcp_cntx[avrcp_chnl].avrcp_role = BT_AVRCP_CT;
            srv_avrcp_sdp_query_req(avrcp_chnl);
        }
    #endif
        return;
    }   
    
    /* from cm, it just connect as CT role */
    srv_avrcp_connect_req(BT_AVRCP_CT, dev_addr, NULL);
}

void srv_avrcp_disconnect_from_cm(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_cm_callback cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_DISCONNECT_FROM_CM,
              cb_ptr,
              avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        if (cb_ptr)
        {
            cb_ptr(dev_addr, SRV_BT_CM_AVRCP_CT_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
        }
        
        return;
    }
    
    if (cb_ptr)
    {
        g_srv_avrcp_cntx[avrcp_chnl].avrcp_cm_callback = cb_ptr;
		g_srv_avrcp_cntx[avrcp_chnl].initiate_from_cm = MMI_TRUE; 
    }

    srv_avrcp_disconnect_req(dev_addr);
}


#ifdef __MMI_BT_AVRCP_V13__

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_version_capability
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_avrcp_check_version_capability(U8 avrcp_chnl)
{
    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state != SRV_AVRCP_CONNECTED)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AVRCP_NOT_CONNECTED);
        return SRV_AVRCP_ERROR_NOT_CONNECTED;
    }

    if (g_srv_avrcp_cntx[avrcp_chnl].version < SRV_AVRCP_VERSION_V13)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AVRCP_VERSION_MISMATCH, g_srv_avrcp_cntx[avrcp_chnl].version);
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    return g_srv_avrcp_cntx[avrcp_chnl].version;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_version_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  role
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_version_valid(U8 avrcp_chnl)
{
    U16 check_ret = srv_avrcp_check_version_capability(avrcp_chnl);

    if (SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY == check_ret || 
        SRV_AVRCP_ERROR_NOT_CONNECTED == check_ret)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_sdp_query_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_sdp_query_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 local_role/* = BT_AVRCP_CT*/;
    bt_avrcp_sdp_query_req_struct* msg_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    local_role = g_srv_avrcp_cntx[avrcp_chnl].avrcp_role;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AVRCP_SDP_QUERY_REQ, local_role, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_valid_role(local_role))
    {
        g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state = SRV_AVRCP_SDP_QUERY_UNDEF_ROLE_ERR;
        return;
    }

    if (local_role != BT_AVRCP_CT)
    {
        return;
    }
    
    g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state = SRV_AVRCP_SDP_QUERY_ON_GOING;
    msg_p = (bt_avrcp_sdp_query_req_struct*)OslConstructDataPtr(sizeof(bt_avrcp_sdp_query_req_struct));
    msg_p->chnl_num = avrcp_chnl;
    msg_p->local_role = local_role;
    srv_avrcp_send_msg_to_bt(MOD_MMI, (kal_uint16)MSG_ID_BT_AVRCP_SDP_QUERY_REQ, msg_p, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_sdp_query_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
// MAUI_03495342
static void srv_avrcp_sdp_query_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result; 
    S32 avrcp_chnl = 0;
    bt_avrcp_sdp_query_cnf_struct *msg_p = (bt_avrcp_sdp_query_cnf_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_AVRCP_SDP_QUERY_CNF, 
              msg_p->result, 
              msg_p->chnl_num, 
              msg_p->version,
              avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    
    if (result == (U16)SRV_AVRCP_RESULT_SUCCESS)
    {
        //MAUI_03495342
        g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state = SRV_AVRCP_SDP_QUERY_SUCCESS;
        g_srv_avrcp_cntx[avrcp_chnl].version = msg_p->version;
        g_srv_avrcp_cntx[avrcp_chnl].remote_supported_features = msg_p->remote_support_feature;
    
        if (g_srv_avrcp_cntx[avrcp_chnl].version >= SRV_AVRCP_VERSION_V13)
        {
            srv_avrcp_open_dev(avrcp_chnl);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_sdp_query_ind_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_sdp_query_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 result; 
    S32 avrcp_chnl = 0;
    bt_avrcp_sdp_query_ind_struct *msg_p = (bt_avrcp_sdp_query_ind_struct*)msg;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr((srv_bt_cm_bt_addr*)(&msg_p->device_addr));
    MMI_TRACE(MMI_CONN_TRC_G7_BT,
              MMI_AVRCP_TRC_AVRCP_VERSION_IND_HDLR,
              msg_p->status,
              msg_p->ct_version,
              msg_p->tg_version,
              avrcp_chnl);
    
    result = msg_p->status;
    
    if (result == (U16)SRV_AVRCP_RESULT_SUCCESS)
    {
        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            return;
        }

        g_srv_avrcp_cntx[avrcp_chnl].sdp_query_state = SRV_AVRCP_SDP_QUERY_SUCCESS;
        
        if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_CT)
        {
            g_srv_avrcp_cntx[avrcp_chnl].version = msg_p->tg_version;
            g_srv_avrcp_cntx[avrcp_chnl].remote_supported_features = 
                msg_p->remote_tg_support_feature;
        }
        else if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_role == BT_AVRCP_TG)
        {
            g_srv_avrcp_cntx[avrcp_chnl].version = msg_p->ct_version;
            g_srv_avrcp_cntx[avrcp_chnl].remote_supported_features = 
                msg_p->remote_ct_support_feature;
        }

        /* open device if connected */
        if (MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_CONNECTED)
        {
            srv_avrcp_open_dev(avrcp_chnl);
        }
    }   
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_list_player_app_attr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_list_player_app_attr_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_list_playerapp_attribute_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_ATTR_REQ, avrcp_chnl);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_list_playerapp_attribute_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_list_playerapp_attribute_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 0x01;
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, (kal_uint16)MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_REQ, msg_p, NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_notification_result
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_notification_result(U8 avrcp_chnl, U16 result, 
    U8 error_code, U8 event_id, srv_avrcp_result_union final_result)
{
    if (result != (U16)SRV_AVRCP_RESULT_SUCCESS)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_AVRCP_RESULT, result, error_code);
        MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, final_result);
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_list_player_app_attr_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_list_player_app_attr_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U16 result;
    U8  error_code;
    S32 avrcp_chnl = 0;
    U8  event_id = 0;
    srv_avrcp_result_union attribute_list;
    bt_avrcp_list_playerapp_attribute_cnf_struct* msg_p = 
        (bt_avrcp_list_playerapp_attribute_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_id = SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_EVENT;        
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT,
              MMI_AVRCP_TRC_AVRCP_APP_ATTR_CNF_HDLR,
              msg_p->chnl_num,
              avrcp_chnl);

    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_PLAYER_APP_ATTR_CNF_HDLR, 
              msg_p->result, 
              msg_p->error_code);
    MMI_AVRCPV13_RESULT(attribute_list.supported_attr_list_result, result, error_code);

    do
    {
        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            return;
        }
        
        if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                             result, 
                                                             error_code, 
                                                             event_id, 
                                                             attribute_list))
        {
            break;
        }
        
        g_srv_avrcp_cntx[avrcp_chnl].attr_count = msg_p->count;
        attribute_list.supported_attr_list_result.attr_count = msg_p->count;
        
        while (i < msg_p->count)
        {
            g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i] = msg_p->attribute_ids[i];
            g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[i].attribute_id = msg_p->attribute_ids[i];
            attribute_list.supported_attr_list_result.supported_attr_list[i] = 
                (srv_avrcp_player_app_settings_attr_enum)msg_p->attribute_ids[i];
            ++i;
        }
        
        MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, attribute_list);
    } while(0);
    
    srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_list_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_list_player_app_value_req(U8 avrcp_chnl, srv_avrcp_player_app_settings_attr_enum attr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_list_playerapp_value_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_VAL_REQ, avrcp_chnl, attr_id);
    
    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }
   
    if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, attr_id) == MMI_FALSE)
    {
        return SRV_AVRCP_ATTRIBUTE_NOT_SUPPORTED;
    }

    msg_p = (bt_avrcp_list_playerapp_value_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_list_playerapp_value_req_struct));

    g_srv_avrcp_cntx[avrcp_chnl].attr_id = (U8)attr_id;
        
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->attribute_id= (U8)attr_id;
    msg_p->seq_id = 0x02;
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_list_player_app_value_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_list_player_app_value_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U16 result = 0; 
    U8  error_code = 0;
    U8  pos = 255;
    S32 avrcp_chnl = 0;
    U8  attr_count;
    U8  attr_val_count;
    U8  event_id;
    srv_avrcp_result_union attribute_values;
    bt_avrcp_list_playerapp_value_cnf_struct *msg_p = (bt_avrcp_list_playerapp_value_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_PLAYER_APP_VAL_CNF_HDLR, 
              msg_p->result, 
              msg_p->error_code);
    event_id = SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_VALUE_EVENT;
    result = msg_p->result;
    error_code = msg_p->error_code;
    attr_val_count = msg_p->count;

    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT,
              MMI_AVRCP_TRC_AVRCP_APP_VALUE_CNF_HDLR,
              msg_p->chnl_num,
              avrcp_chnl);
    MMI_AVRCPV13_RESULT(attribute_values.supp_attr_val_list, result, error_code);

    do
    {
        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            return;
        }
        
        if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                             result, 
                                                             error_code, 
                                                             event_id, 
                                                             attribute_values))
        {
            break;
        }
    
        attr_count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
        
        while (i < attr_count)
        {
            if (g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i] == g_srv_avrcp_cntx[avrcp_chnl].attr_id)
            {
                pos = i;
                break;
            }
            
            i++;
        }

        if (pos == 255)
        {
            break;
        }
        
        g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attr_val_count = msg_p->count;
        g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attribute_id = g_srv_avrcp_cntx[avrcp_chnl].attr_id;

        attribute_values.supp_attr_val_list.attr_val_count = attr_val_count;
        attribute_values.supp_attr_val_list.attribute_id = (srv_avrcp_player_app_settings_attr_enum)g_srv_avrcp_cntx[avrcp_chnl].attr_id;

        i = 0;
        
        do
        {
            g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attr_values[i] = msg_p->attribute_values[i];
            attribute_values.supp_attr_val_list.attr_values[i] = msg_p->attribute_values[i];
        } while (i++ < attr_val_count);
    
        MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, attribute_values);
    } while(0);
    
    srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_curr_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_curr_player_app_value_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_get_curplayerapp_value_req_struct* msg_p;   

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_CURR_PLAYER_APP_VAL_REQ, avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_get_curplayerapp_value_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_get_curplayerapp_value_req_struct));
    msg_p->count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 0x03;
    
    while (i < SRV_AVRCP_MAX_ATTR_NUM)
    {
        msg_p->attribute_ids[i] = g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i];
        ++i;
    }

    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_curr_player_app_value_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_curr_player_app_value_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 avrcp_chnl = 0;
    U16 result; 
    U8 error_code;
    srv_avrcp_result_union attribute_values;
    bt_avrcp_get_curplayerapp_value_cnf_struct* msg_p = (bt_avrcp_get_curplayerapp_value_cnf_struct*)msg;
    U8 event_id = SRV_AVRCP_EVT_ID_CURR_ATTR_VAL_EVENT;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_CURR_APP_VAL_CNF_HDLR,
              msg_p->result,
              msg_p->error_code,
              msg_p->chnl_num,
              avrcp_chnl);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;
    g_srv_avrcp_cntx[avrcp_chnl].attr_count = msg_p->count;   
    attribute_values.curr_attr_list_result.count = msg_p->count;
    
    MMI_AVRCPV13_RESULT(attribute_values.curr_attr_list_result, result, error_code);
    
    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         attribute_values))
    {
        return;
    }
    
    while (i < SRV_AVRCP_MAX_ATTR_NUM)
    {
        attribute_values.curr_attr_list_result.curr_attr_list[i].attribute_id = (srv_avrcp_player_app_settings_attr_enum)msg_p->attribute_ids[i];
        attribute_values.curr_attr_list_result.curr_attr_list[i].attr_values= msg_p->attribute_values[i];
        ++i;
    }
    
    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, attribute_values);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_player_app_value_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_set_player_app_value_req(U8 avrcp_chnl, U8 attr_values[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_set_playerapp_value_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_APP_SET_PLAYER_APP_VALUE);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_set_playerapp_value_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_set_playerapp_value_req_struct));
    msg_p->count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 0x04;

    while (i < g_srv_avrcp_cntx[avrcp_chnl].attr_count)
    {
        msg_p->attribute_ids[i] = g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i];
        msg_p->values[i] = attr_values[i];
        ++i;
    }
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, (kal_uint16)MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_REQ, msg_p, NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_player_app_value_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_set_player_app_value_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 event_id = 0;
    U8 error_code;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union set_player_settings_result;
    bt_avrcp_set_playerapp_value_cnf_struct* msg_p = (bt_avrcp_set_playerapp_value_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_APP_SET_PLAYER_APP_RESULT);
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;
    event_id = SRV_AVRCP_EVT_ID_SET_PLAYERAPP_VAL_EVENT;
    
    MMI_AVRCPV13_RESULT(set_player_settings_result.result_cnf, result, error_code);

    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         set_player_settings_result))
    {
        return;
    }

    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, set_player_settings_result);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_attr_txt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_player_app_attr_txt_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_get_playerapp_attributetext_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_APP_GET_PLAYER_APP_ATTR_TXT);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_get_playerapp_attributetext_req_struct*)OslConstructDataPtr(sizeof(bt_avrcp_get_playerapp_attributetext_req_struct));
    msg_p->count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 0x05;
    
    while (i < g_srv_avrcp_cntx[avrcp_chnl].attr_count)
    {
        msg_p->attribute_ids[i] = g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i];
        ++i;
    }
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_REQ, 
                             msg_p, 
                             NULL);    
    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_attr_txt_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_player_app_attr_txt_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                  */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8 error_code;
    U8 event_id = 0;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union result_cnf;
    bt_avrcp_get_playerapp_attributetext_cnf_struct* msg_p = (bt_avrcp_get_playerapp_attributetext_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_APP_GET_PLAYER_APP_ATTR_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    event_id = SRV_AVRCP_EVT_ID_ATTR_TXT_EVENT;
    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_AVRCPV13_RESULT(result_cnf.attr_txt_result, result, error_code);
    
    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         result_cnf))
    {
        return;
    }
    
    result_cnf.attr_txt_result.count = msg_p->count;
    
    while (i < (msg_p->count))
    {
        result_cnf.attr_txt_result.attr_txt[i].attribute_id = (srv_avrcp_player_app_settings_attr_enum)msg_p->attribute_id[i];
        result_cnf.attr_txt_result.charset[i] = msg_p->charset[i];
        result_cnf.attr_txt_result.attr_txt[i].attr_str = (U8 *)OslMalloc(SRV_AVRCP_MAX_ATTRIBUTE_STRING_SIZE);
        memset((void *)result_cnf.attr_txt_result.attr_txt[i].attr_str,
               0,
               SRV_AVRCP_MAX_ATTRIBUTE_STRING_SIZE);
        memcpy((void *)result_cnf.attr_txt_result.attr_txt[i].attr_str,
               (void *)msg_p->attribute_string[i],
               sizeof(msg_p->attribute_string[i]));
        ++i;
    }

    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, result_cnf);

    for (i = 0; i < (msg_p->count); ++i)
    {
        OslMfree(result_cnf.attr_txt_result.attr_txt[i].attr_str);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_value_txt_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_player_app_value_txt_req(U8 avrcp_chnl, 
                                                 srv_avrcp_player_app_settings_attr_enum attr_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_get_playerapp_valuetext_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_VAL_TXT_REQ);    

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }
    
    if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, attr_id) == MMI_FALSE)
    {
        return SRV_AVRCP_ATTRIBUTE_NOT_SUPPORTED;
    }

    msg_p = (bt_avrcp_get_playerapp_valuetext_req_struct*)OslConstructDataPtr(sizeof(bt_avrcp_get_playerapp_valuetext_req_struct));
    msg_p->count = g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[attr_id].attr_val_count;
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->attribute_id= attr_id;
    msg_p->seq_id = 0x06;
    
    while(i < msg_p->count)
    {
        msg_p->value_ids[i] = g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[attr_id].attr_values[i];
        ++i;
    }
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_player_app_value_txt_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_player_app_value_txt_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 avrcp_chnl = 0;
    U8 event_id= 0;
    U8 error_code;
    U16 result;
    srv_avrcp_result_union val_txt_result;
    bt_avrcp_get_playerapp_valuetext_cnf_struct *msg_p = (bt_avrcp_get_playerapp_valuetext_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_AVRCP_TRC_PLAYER_APP_VAL_TXT_CNF_HDLR, 
              msg_p->chnl_num, 
              avrcp_chnl);
    
    event_id = SRV_AVRCP_EVT_ID_ATTR_TXT_VAL_EVENT;

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;
    
    MMI_AVRCPV13_RESULT(val_txt_result.val_txt_result, result, error_code);

    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         val_txt_result))
    {
        return;
    }
    
    val_txt_result.val_txt_result.attr_id = (srv_avrcp_player_app_settings_attr_enum)msg_p->attribute_id;
    val_txt_result.val_txt_result.count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    
    while (i < (msg_p->count))
    {
        val_txt_result.val_txt_result.value_txt[i].value_id = msg_p->value_ids[i];
        val_txt_result.val_txt_result.value_txt[i].charset = msg_p->charset[i];
        memset((void *)val_txt_result.val_txt_result.value_txt[i].value_str,
                0,
                SRV_AVRCP_MAX_ATTRIBUTE_STRING_SIZE);
        memcpy((void *)val_txt_result.val_txt_result.value_txt[i].value_str,
                (void *)msg_p->value_string[i],
                sizeof((void *)msg_p->value_string[i]));
        ++i;
    }
    
    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, val_txt_result);

    for (i = 0; i < msg_p->count; ++i)
    {
        OslMfree(val_txt_result.val_txt_result.value_txt[i].value_str);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_displayable_charset_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_inform_displayable_charset_req(U8 avrcp_chnl, U16 charset[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_inform_display_charset_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_INFORM_CHARSET);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_inform_display_charset_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_inform_display_charset_req_struct));
    msg_p->count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 0x07;
    
    while (i < g_srv_avrcp_cntx[avrcp_chnl].attr_count)
    {
        g_srv_avrcp_cntx[avrcp_chnl].charset[i] = charset[i];
        msg_p->charset_ids[i] = g_srv_avrcp_cntx[avrcp_chnl].charset[i];
        ++i;
    }
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_displayable_charset_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_inform_displayable_charset_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_code;
    U8 event_id = 0;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union cnf_result;
    bt_avrcp_inform_display_charset_cnf_struct *msg_p = (bt_avrcp_inform_display_charset_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_INFORM_CHARSET_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    event_id = SRV_AVRCP_EVT_ID_INFORM_DISPLAYABLE_CHARSET_EVENT;
    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_AVRCPV13_RESULT(cnf_result.result_cnf, result, error_code);
    
    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         cnf_result))
    {
        return;
    }
    
    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, (srv_avrcp_event_enum)event_id, cnf_result);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_battery_status_of_ct_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_inform_battery_status_of_ct_req(U8 avrcp_chnl, srv_avrcp_battery_status_enum battery_status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_inform_battery_statusofct_req_struct* msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_INFORM_BATT_STATUS);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_inform_battery_statusofct_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_inform_battery_statusofct_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->battery_status = battery_status;
    msg_p->seq_id = 0x08;
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_inform_battery_status_of_ct_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_inform_battery_status_of_ct_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_code;
    U8 event_id = SRV_AVRCP_EVT_ID_INFORM_BATT_STATUS_CT_EVENT;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union cnf_result;
    bt_avrcp_inform_battery_statusofct_cnf_struct *msg_p = (bt_avrcp_inform_battery_statusofct_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_INFORM_BATT_STATUS_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_AVRCPV13_RESULT(cnf_result.result_cnf, result, error_code);

    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         cnf_result))
    {
        return;
    }

    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, cnf_result);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_element_attr_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_element_attr_req(U8 avrcp_chnl, srv_avrcp_media_attr_enum attr_ids[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    bt_avrcp_get_element_attributes_req_struct* msg_p;    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_ELEM_ATTR_REQ);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_get_element_attributes_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_get_element_attributes_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    g_srv_avrcp_cntx[avrcp_chnl].elem_count = SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM - 1; /* [MAUI_03462722] spec support max 7 */
    msg_p->count = SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM - 1; /* [MAUI_03462722] spec support max 7 */
    msg_p->seq_id = 0x09;
    
    memset(msg_p->identifier, 0, SRV_AVRCP_MAX_IDENTIFIER_COUNT);
    
    while (i < SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM)
    {
        msg_p->attributes[i] = attr_ids[i];
        ++i;
    }
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_element_attr_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_element_attr_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_code;
    U8 *str_ptr = NULL;
    U8 *tmp_ptr = NULL;
    U8 event_id = SRV_AVRCP_EVT_ID_ELEM_ATTR_EVENT;
    U16 result;
    S32 i = 0;
    S32 avrcp_chnl;
    srv_avrcp_result_union get_elem_result;
    bt_avrcp_get_element_attributes_cnf_struct *msg_p = (bt_avrcp_get_element_attributes_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_ELEM_ATTR_CNF_HDLR);
    
    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;
    
    MMI_AVRCPV13_RESULT(get_elem_result.attr_txt_result, result, error_code);

    do
    {
        if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                             result, 
                                                             error_code, 
                                                             event_id, 
                                                             get_elem_result))
        {
            break;
        }

        get_elem_result.elem_attr.result = (srv_avrcp_result_enum)msg_p->result;
        get_elem_result.elem_attr.error_code = (srv_avrcp_error_code_enum)msg_p->error_code;
        get_elem_result.elem_attr.count = msg_p->count;
        
        str_ptr = msg_p->element_data;
        
        for (i = 0; i < (msg_p->count); ++i)
        {
            get_elem_result.elem_attr.elements[i].elem_id= (srv_avrcp_media_attr_enum)msg_p->elements[i].attribute_id;
            get_elem_result.elem_attr.elements[i].charset = msg_p->elements[i].charset;
            
            get_elem_result.elem_attr.elements[i].element_data = (U8 *)OslMalloc(SRV_AVRCP_ELEM_DATA_SIZE);
            memset(get_elem_result.elem_attr.elements[i].element_data, 0, SRV_AVRCP_ELEM_DATA_SIZE);

            tmp_ptr = str_ptr + msg_p->elements[i].value_text_offset; 
            strcpy((char*)get_elem_result.elem_attr.elements[i].element_data, (char*)tmp_ptr);
        }
        
        MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, (srv_avrcp_event_enum)event_id, get_elem_result);
        
        for (i = 0; i < msg_p->count; ++i)
        {
            OslMfree(get_elem_result.elem_attr.elements[i].element_data);
        }
    } while(0);
    
    srv_avrcp_open_dev(avrcp_chnl);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_play_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_avrcp_get_play_status_req(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_get_playerstatus_req_struct* msg_p;
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_GET_PLAY_STATUS);
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return SRV_AVRCP_INTERNAL_ERROR;
    }

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_get_playerstatus_req_struct*)OslConstructDataPtr(sizeof(bt_avrcp_get_playerstatus_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 10;
    
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_play_status_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_play_status_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_code;
    U8 event_id = SRV_AVRCP_EVT_ID_PLAY_STATUS_EVENT;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union play_status_result;
    bt_avrcp_get_playerstatus_cnf_struct *msg_p = (bt_avrcp_get_playerstatus_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_GET_PLAY_STATUS_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_AVRCPV13_RESULT(play_status_result.play_status, result, error_code);

    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         play_status_result))
    {
        return;
    }
    
    play_status_result.play_status.play_status = (srv_avrcp_play_status_enum)msg_p->play_status;;
    play_status_result.play_status.song_len = msg_p->song_length;
    play_status_result.play_status.song_pos = msg_p->song_position;
    
    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, play_status_result);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_register_notification_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_register_notification_req(U8 avrcp_chnl, U8 event_id, U32 playback_interval)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_register_notification_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_REG_NOTIFY_REQ);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_register_notification_req_struct*)OslConstructDataPtr(sizeof(bt_avrcp_register_notification_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->event_id = event_id;
    
    if (event_id & SRV_AVRCP_EVENT_PLAYBACK_POS_CHNAGED)
    {
        msg_p->playback_interval = playback_interval;
    }
    
    msg_p->seq_id = 11;
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_register_notification_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_register_notification_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U8 error_code;
    U8 event_id = SRV_AVRCP_EVT_ID_REG_NOTIFICATION_EVENT;
    U16 result;
    S32 avrcp_chnl;
    srv_avrcp_result_union reg_notity_result;
    bt_avrcp_register_notification_cnf_struct *msg_p = (bt_avrcp_register_notification_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_REG_NOTIFY_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;
    
    MMI_AVRCPV13_RESULT(reg_notity_result.reg_notification_event, result, error_code);
    
    if (result != (U16)SRV_AVRCP_RESULT_SUCCESS)    
    {                                            
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_RE_REG_NOTIFY_CNF_HDLR);
        MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, reg_notity_result);        
        srv_avrcp_register_events_notification_req(avrcp_chnl, reg_notity_result);
        return;                                                    
    }
    
    reg_notity_result.reg_notification_event.event_id = (srv_avrcp_metadata_trasnfer_events)msg_p->event_id;
    reg_notity_result.reg_notification_event.is_interim = (srv_avrcp_reg_notify_enum)msg_p->is_interim;
    
    switch (msg_p->event_id)
    {
        case SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED:
        {
            reg_notity_result.reg_notification_event.playback_status = (srv_avrcp_play_status_enum)msg_p->status;
            break;
        }
        
        case SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED:
        {
            reg_notity_result.reg_notification_event.system_status = (srv_avrcp_system_status_enum)msg_p->status;
            break;
        }
        
        case SRV_AVRCP_EVENT_BATT_STATUS_CHANGED:
        {
            reg_notity_result.reg_notification_event.batt_status = (srv_avrcp_battery_status_enum)msg_p->status;
            break;
        }
    }
    
    reg_notity_result.reg_notification_event.count= msg_p->count;
    reg_notity_result.reg_notification_event.song_pos = msg_p->pos;
    
    while (i < SRV_AVRCP_MAX_ATTR_NUM)
    {
        reg_notity_result.reg_notification_event.attr_id[i]  = (srv_avrcp_player_app_settings_attr_enum)msg_p->attribute_id[i];
        reg_notity_result.reg_notification_event.attr_val[i] = msg_p->attribute_value[i];
        ++i;
    }

    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, reg_notity_result);
    srv_avrcp_register_events_notification_req(avrcp_chnl, reg_notity_result);
}


/*****************************************************************************
* FUNCTION
* srv_avrcp_register_result_notifier
* DESCRIPTION: 
* Application should register the above callback function using this interface
* The application should register the callback function before using the service of
* BT dialer, otherwise BT dialer won't be able to send back the response to APP.
* PARAMETERS
*  dev_addr        :       [IN] device address
*  cb_ptr          :       [IN] callback
* RETURNS
*  U8
******************************************************************************/
U8 srv_avrcp_register_notification_hdlr(srv_bt_cm_bt_addr *dev_addr, 
                                        srv_avrcp_notification_hdlr cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (cb_ptr)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_NOTIFIER_REGISTERED, avrcp_chnl);

        if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
        {
            return SRV_AVRCP_NOTIFICATION_CALLBACK_PARAMETER_ERR;
        }

        g_srv_avrcp_cntx[avrcp_chnl].app_notify_callback = cb_ptr;
        return SRV_AVRCP_RESULT_CMD_SUCCESS;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_NOTIFIER_REG_FAIL, avrcp_chnl);
    return SRV_AVRCP_NOTIFICATION_CALLBACK_NULL;
}


/*****************************************************************************
 * FUNCTION
 * srv_avrcp_register_tg_cmd_callback
 * DESCRIPTION: 
 * Application should register the above callback function using this interface
 * to handle command sent from tg device
 * PARAMETERS
 *  dev_addr        :       [IN] device address
 *  cb_ptr          :       [IN] callback
 * RETURNS
 *  U8
 *******************************************************************************/
void srv_avrcp_register_bt_dialer_tg_cmd_callback(SRV_AVRCP_BT_DIALER_TG_CMD_CALLBACK cb_ptr)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_REGISTER_TG_CMD_CALLBACK, cb_ptr);
    g_srv_avrcp_bt_dialer_tg_cmd_fun_ptr = cb_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_abort_continueing_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_abort_continueing_req(U8 avrcp_chnl)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_avrcp_abort_continueresponse_req_struct *msg_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_ABORT_REQ);

    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }

    msg_p = (bt_avrcp_abort_continueresponse_req_struct*)
        OslConstructDataPtr(sizeof(bt_avrcp_abort_continueresponse_req_struct));
    msg_p->chnl_num = g_srv_avrcp_cntx[avrcp_chnl].chnl_num;
    msg_p->seq_id = 12;
    srv_avrcp_send_msg_to_bt(MOD_MMI, 
                             (kal_uint16)MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_REQ, 
                             msg_p, 
                             NULL);    

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_abort_continueing_cnf_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_abort_continueing_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 error_code;
    U16 result;
    U8 event_id = SRV_AVRCP_EVT_ID_ABORT_REQ_EVENT;
    S32 avrcp_chnl;
    srv_avrcp_result_union abort_cont_result;
    bt_avrcp_abort_continueresponse_cnf_struct *msg_p = 
        (bt_avrcp_abort_continueresponse_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_channel_num(msg_p->chnl_num);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_ABORT_CNF_HDLR);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    result = msg_p->result;
    error_code = msg_p->error_code;

    MMI_AVRCPV13_RESULT(abort_cont_result.result_cnf, result, error_code);

    if (MMI_FALSE == srv_avrcp_check_notification_result(avrcp_chnl, 
                                                         result, 
                                                         error_code, 
                                                         event_id, 
                                                         abort_cont_result))
    {
        return;
    }

    MMI_AVRCP_APP_NOTIFY_CALLBACK(avrcp_chnl, event_id, abort_cont_result);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_elements_attr_request
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_get_elements_attr_request(srv_bt_cm_bt_addr *dev_addr)
{
    S32 avrcp_chnl;  
    S32 i = 0;
    srv_avrcp_media_attr_enum elem_id = SRV_AVRCP_MEDIA_TITLE;
    srv_avrcp_media_attr_enum attr_id[SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM];
    
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    for (i = 0; i < (SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM - 1); ++i)
    {
        attr_id[i] = elem_id++;
    }
    
    attr_id[SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM - 1] = SRV_AVRCP_MEDIA_ATTR_UNDEFINED;
    srv_avrcp_get_element_attr_req(avrcp_chnl, attr_id);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_attribute_support_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_avrcp_check_attribute_support_status_req(U8 avrcp_chnl, srv_avrcp_player_app_settings_attr_enum attribute_id)
{
    S32 i = 0;
    
    for (i = 0; i < g_srv_avrcp_cntx[avrcp_chnl].attr_count; ++i)
    {
        if (attribute_id == g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i])
        {
            return MMI_TRUE;
        }
    }
    
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_attribute_support_status_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_supported_attr_req(U8 avrcp_chnl, U8 supported_attr[])
{
    U8 attr_count;
    S32 i = 0;;

    attr_count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;
    
    for (i = 0; i < attr_count; ++i)
    {
        supported_attr[i] = g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[i].attribute_id;
    }

    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_attribute_supported_values_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_get_attribute_supported_values_req(U8 avrcp_chnl, srv_avrcp_player_app_settings_attr_enum attr_id ,U8 attr_val[], U8 *count)
{
    U8 attr_count;
    S32 i = 0;
    S32 pos = -1;
    
    attr_count = g_srv_avrcp_cntx[avrcp_chnl].attr_count;

    do
    {
        for (i = 0; i < attr_count; ++i)
        {
            if (g_srv_avrcp_cntx[avrcp_chnl].attribute_id[i] == attr_id)
            {
                pos = i;
                *count = g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attr_val_count;
            }
        }
        
        if (pos == -1)
        {
            break;
        }
        
        memset(attr_val,0,SRV_AVRCP_MAX_ATTR_VAL_NUM);
        
        for (i = 0; i < g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attr_val_count; ++i)
        {
            attr_val[i] = g_srv_avrcp_cntx[avrcp_chnl].supported_attr_val[pos].attr_values[i];
        }
        
        return SRV_AVRCP_RESULT_CMD_SUCCESS;
    } while(0);

    return SRV_AVRCP_ATTRIBUTE_NOT_SUPPORTED;    
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_unmask_reg_notification_event_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_avrcp_unmask_reg_notification_event_id(U8 avrcp_chnl, 
                                                     srv_avrcp_metadata_trasnfer_events event_id, 
                                                     S16 playback_interval)
{
    U16 tmp_val = 0;
    intermediate_result result;
    tmp_val = (S32)calculate_pow(2, event_id);
    
    if (g_srv_avrcp_cntx[avrcp_chnl].event_ids & event_id)
    {
        return SRV_AVRCP_NOTIFICATION_ALREADY_REGISTERED;
    }
    
    if (event_id < 8)
    {
        g_srv_avrcp_cntx[avrcp_chnl].event_ids = 
            g_srv_avrcp_cntx[avrcp_chnl].event_ids | (S32)calculate_pow(2, event_id);
    }
    
    if (playback_interval != -1)
    {
        g_srv_avrcp_cntx[avrcp_chnl].playback_interval = playback_interval;
    }
    
    if (tmp_val & event_id)
    {
        result = (intermediate_result)srv_avrcp_register_notification_req(avrcp_chnl, 
                                                                          event_id, 
                                                                          g_srv_avrcp_cntx[avrcp_chnl].playback_interval);
    }
    else
    {
        return SRV_AVRCP_ATTRIBUTE_NOT_SUPPORTED;
    }

    return (U8)result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_equalizer_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_equalizer_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_EQUALIZER;
    srv_avrcp_get_player_app_value_txt_req(avrcp_chnl, equliazer_settings);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_repeat_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_repeat_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE;
    srv_avrcp_get_player_app_value_txt_req(avrcp_chnl, equliazer_settings);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_shuffle_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_shuffle_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE;
    srv_avrcp_get_player_app_value_txt_req(avrcp_chnl, equliazer_settings);
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_playerapp_value_txt_scan_setting_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_get_playerapp_value_txt_scan_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_SCAN_MODE;
    srv_avrcp_get_player_app_value_txt_req(avrcp_chnl, equliazer_settings);
}


static void srv_avrcpv13_init_event_handler()
{
    // MAUI_03495342
    SetProtocolEventHandler(srv_avrcp_sdp_query_cnf_hdlr, MSG_ID_BT_AVRCP_SDP_QUERY_CNF);
    SetProtocolEventHandler(srv_avrcp_sdp_query_ind_hdlr, MSG_ID_BT_AVRCP_SDP_QUERY_IND);
    SetProtocolEventHandler(srv_avrcp_list_player_app_attr_cnf_hdlr, MSG_ID_BT_AVRCP_LIST_PLAYERAPP_ATTRIBUTE_CNF);
    SetProtocolEventHandler(srv_avrcp_list_player_app_value_cnf_hdlr, MSG_ID_BT_AVRCP_LIST_PLAYERAPP_VALUE_CNF);
    SetProtocolEventHandler(srv_avrcp_curr_player_app_value_cnf_hdlr, MSG_ID_BT_AVRCP_GET_CURPLAYERAPP_VALUE_CNF);
    SetProtocolEventHandler(srv_avrcp_set_player_app_value_cnf_hdlr, MSG_ID_BT_AVRCP_SET_PLAYERAPP_VALUE_CNF);
    SetProtocolEventHandler(srv_avrcp_get_player_app_attr_txt_cnf_hdlr, MSG_ID_BT_AVRCP_GET_PLAYERAPP_ATTRIBUTETEXT_CNF);
    SetProtocolEventHandler(srv_avrcp_get_player_app_value_txt_cnf_hdlr, MSG_ID_BT_AVRCP_GET_PLAYERAPP_VALUETEXT_CNF);
    SetProtocolEventHandler(srv_avrcp_inform_displayable_charset_cnf_hdlr, MSG_ID_BT_AVRCP_INFORM_DISPLAY_CHARSET_CNF);
    SetProtocolEventHandler(srv_avrcp_inform_battery_status_of_ct_cnf_hdlr, MSG_ID_BT_AVRCP_INFORM_BATTERY_STATUSOFCT_CNF);
    SetProtocolEventHandler(srv_avrcp_get_element_attr_cnf_hdlr, MSG_ID_BT_AVRCP_GET_ELEMENT_ATTRIBUTES_CNF);
    SetProtocolEventHandler(srv_avrcp_get_play_status_cnf_hdlr, MSG_ID_BT_AVRCP_GET_PLAYERSTATUS_CNF);
    SetProtocolEventHandler(srv_avrcp_register_notification_cnf_hdlr, MSG_ID_BT_AVRCP_REGISTER_NOTIFICATION_CNF);
    SetProtocolEventHandler(srv_avrcp_abort_continueing_cnf_hdlr, MSG_ID_BT_AVRCP_ABORT_CONTINUERESPONSE_CNF);
}


static U8 srv_avrcp_open_dev(U8 avrcp_chnl)
{
    srv_avrcp_result_union reg_notity_result;
    
    g_srv_avrcp_cntx[avrcp_chnl].playback_interval = -1;
    g_srv_avrcp_cntx[avrcp_chnl].event_ids = (S32)calculate_pow(2,SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED) | 
                                             (S32)calculate_pow(2,SRV_AVRCP_EVENT_TRACK_CHANGED) |
                                             (S32)calculate_pow(2,SRV_AVRCP_EVENT_TRACK_REACHED_END) |
                                             (S32)calculate_pow(2,SRV_AVRCP_EVENT_TRACK_REACHED_START) |
                                             (S32)calculate_pow(2,SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED) |
                                             (S32)calculate_pow(2,SRV_AVRCP_EVENT_PLAYER_APP_SETTING_CHNAGED);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_OPEN_DEV);

    switch (g_srv_avrcp_cntx[avrcp_chnl].intermediate_attr_state)
    {
        case SRV_AVRCP_LIST_PLAYER_INITIAL:
        {
        #if 0
            #ifdef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
            #endif
        #endif
        
            srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_GET_ELEM_ATTR:
        {
            srv_avrcp_get_elements_attr_request(&g_srv_avrcp_cntx[avrcp_chnl].device_addr);
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_REGISTER_NOTIFY);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_REGISTER_NOTIFY:
        {
            srv_avrcp_register_events_notification_req(avrcp_chnl, reg_notity_result);
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_UNDEFINED);
            break;
        }
    }
    
    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


static U8 srv_avrcp_close_dev(U8 avrcp_chnl)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_CLOSE_DEV);
    MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_INITIAL);
    g_srv_avrcp_cntx[avrcp_chnl].event = 1;
    
#if 0
    #ifdef __MMI_BT_DIALER_SUPPORT__
/* under construction !*/
    #endif
#endif
    
    return SRV_AVRCP_RESULT_CMD_SUCCESS;
}


static void srv_avrcp_register_events_notification_req(U8 avrcp_chnl, srv_avrcp_result_union reg_notity_result)
{
    static MMI_BOOL is_play_status_final_result = MMI_FALSE;
    U8 playback_interval;
    U16 tmp_val = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_PLAYER_APP_REG_NOTIFY_ALL);
    avrcp_chnl = srv_avrcp_find_channel_by_role(BT_AVRCP_CT);
    playback_interval = g_srv_avrcp_cntx[avrcp_chnl].playback_interval;
    
    if ((g_srv_avrcp_cntx[avrcp_chnl].event != 1) && 
        (reg_notity_result.reg_notification_event.is_interim == 0x00) &&
        (reg_notity_result.reg_notification_event.result == SRV_AVRCP_RESULT_SUCCESS))
    {
        is_play_status_final_result = MMI_TRUE;
        srv_avrcp_register_notification_req(avrcp_chnl, reg_notity_result.reg_notification_event.event_id, playback_interval);
        return;
    }
    
    ++g_srv_avrcp_cntx[avrcp_chnl].event;
    tmp_val = (S32)calculate_pow(2, g_srv_avrcp_cntx[avrcp_chnl].event);
    
    if ((tmp_val & g_srv_avrcp_cntx[avrcp_chnl].event_ids) &&
        (g_srv_avrcp_cntx[avrcp_chnl].event) < SRV_AVRCP_MAX_GET_ELEMENT_ATTR_NUM)
    {
        srv_avrcp_register_notification_req(avrcp_chnl, g_srv_avrcp_cntx[avrcp_chnl].event, playback_interval);
        return;
    }
    
    if (is_play_status_final_result == MMI_TRUE)
    {
        switch (reg_notity_result.reg_notification_event.event_id)
        {
            case SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED:
            case SRV_AVRCP_EVENT_TRACK_CHANGED:
            case SRV_AVRCP_EVENT_TRACK_REACHED_END:
            case SRV_AVRCP_EVENT_TRACK_REACHED_START:
            {
                is_play_status_final_result = MMI_FALSE;
                srv_avrcp_get_elements_attr_request(&g_srv_avrcp_cntx[avrcp_chnl].device_addr);
                break;
            }
        }
    }  
}


static void srv_avrcp_get_playerapp_equalizer_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_EQUALIZER;
    srv_avrcp_list_player_app_value_req(avrcp_chnl, equliazer_settings);
}


static void srv_avrcp_get_playerapp_repeat_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE;
    srv_avrcp_list_player_app_value_req(avrcp_chnl, equliazer_settings);
}


static void srv_avrcp_get_playerapp_shuffle_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE;
    srv_avrcp_list_player_app_value_req(avrcp_chnl, equliazer_settings);
}


static void srv_avrcp_get_playerapp_scan_setting_req(U8 avrcp_chnl)
{
    srv_avrcp_player_app_settings_attr_enum equliazer_settings;

    equliazer_settings = SRV_AVRCP_PLAYER_APP_SETTING_SCAN_MODE;
    srv_avrcp_list_player_app_value_req(avrcp_chnl, equliazer_settings);
}


static U8 srv_avrcp_get_supported_attr_val_req(U8 avrcp_chnl)
{
    U8 state;
    
    if (MMI_FALSE == srv_avrcp_check_version_valid(avrcp_chnl))
    {
        return SRV_AVRCP_VERSION_SUPPORT_INCOMPATIBILTY;
    }
    
    if (SRV_AVRCP_LIST_PLAYER_INITIAL == g_srv_avrcp_cntx[avrcp_chnl].intermediate_attr_state)
    {
        MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl,SRV_AVRCP_LIST_PLAYER_ATTR);
    }
    
    state = g_srv_avrcp_cntx[avrcp_chnl].intermediate_attr_state;

    switch (state)
    {
        case SRV_AVRCP_LIST_PLAYER_ATTR:
        {
            srv_avrcp_list_player_app_attr_req(avrcp_chnl);
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_ATTR_VAL_EQUALIZER);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_ATTR_VAL_EQUALIZER:
        {
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_ATTR_VAL_REPEAT);
            
            if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, SRV_AVRCP_PLAYER_APP_SETTING_EQUALIZER) != MMI_TRUE)
            {
                srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
                break;
            }
            
            srv_avrcp_get_playerapp_equalizer_setting_req(avrcp_chnl);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_ATTR_VAL_REPEAT:
        {
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_ATTR_VAL_SHUFFLE);

            if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE) != MMI_TRUE)
            {
                srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
                break;
            }
            
            srv_avrcp_get_playerapp_repeat_setting_req(avrcp_chnl);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_ATTR_VAL_SHUFFLE:
        {
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_ATTR_VAL_SCAN);

            if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE) != MMI_TRUE)
            {
                srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
                break;
            }
            
            srv_avrcp_get_playerapp_shuffle_setting_req(avrcp_chnl);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_ATTR_VAL_SCAN:
        {
            MMI_AVRCP_INTER_ATTR_STATE_TRANS(avrcp_chnl, SRV_AVRCP_LIST_PLAYER_REGISTER_NOTIFY);

            if (srv_avrcp_check_attribute_support_status_req(avrcp_chnl, SRV_AVRCP_PLAYER_APP_SETTING_SCAN_MODE) != MMI_TRUE)
            {
                srv_avrcp_get_supported_attr_val_req(avrcp_chnl);
                break;
            }
            
            srv_avrcp_get_playerapp_scan_setting_req(avrcp_chnl);
            break;
        }
        
        case SRV_AVRCP_LIST_PLAYER_REGISTER_NOTIFY:
        {
            g_srv_avrcp_cntx[avrcp_chnl].event = 0;
            srv_avrcp_open_dev(avrcp_chnl);
            break;
        }
    }
    
    return 0;
}


static S32 calculate_pow(S32 base, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, ret = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < index; ++i)
    {
        ret = ret * base;
    }
    
    return ret;
}

//#define TEST_CODE

#ifdef TEST_CODE
U8  mmi_srv_avrcp_proc_inject_string(U8 index, kal_uint8* string)
{
    U8 event_ids;
    S32 pos = 0;
    U16    charset[4];
    U16    attribute_ids[4];
    U8    values[4];
    S32 count= 2;
    U8    attr_id ;
    U8 attr_val[4];
    U8 count1 = 0;
    srv_avrcp_result_union reg_notity_result;
    S32 i = 0;
    srv_avrcp_player_app_settings_attr_enum supported_attr[4];
    MMI_BOOL check_status = MMI_FALSE;
    
    charset[0] = 0x02;
    charset[1] = 0x00;
    charset[2] = 0x00;
    charset[3] = 0x00;
    attribute_ids[0] = 0x02;
    attribute_ids[1] = 0x03;
    values[0] = 0x02;
    values[1] = 0x01;
    values[2] = 0x03;
    values[3] = 0x02;
    event_ids = SRV_AVRCP_EVENT_PLAYBACK_STATUS_CHANGED | 
                SRV_AVRCP_EVENT_TRACK_CHANGED |
                SRV_AVRCP_EVENT_TRACK_REACHED_END |
                SRV_AVRCP_EVENT_TRACK_REACHED_START |
                SRV_AVRCP_EVENT_PLAYBACK_POS_CHNAGED |
                SRV_AVRCP_EVENT_BATT_STATUS_CHANGED |
                SRV_AVRCP_EVENT_SYSTEM_STATUS_CHANGED |
                SRV_AVRCP_EVENT_PLAYER_APP_SETTING_CHNAGED;
    pos = 2;

    switch (index)
    {
        case 26:    
            i = (S32)calculate_pow(2,4) | (S32)calculate_pow(2,3);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"test:%d",i);
        case 25:
            srv_avrcp_register_result_notifier(mmi_dummy_srv_avrcp_register_event);
            break;
        case 0:
            srv_avrcp_list_player_app_attr_req();
            break;
        case 1:
            srv_avrcp_list_player_app_value_req(SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE);
            break;
        case 2:
            srv_avrcp_list_player_app_value_req(SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE);
            break;
        case 3:
            srv_avrcp_get_supported_attr_req(supported_attr);
            for (i=0;i<4;i++)
                kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"attr:%d",supported_attr[i]);
            break;
        case 4:
            check_status = srv_avrcp_check_attribute_support_status_req(SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"check_status:%d",check_status); 
            check_status = srv_avrcp_check_attribute_support_status_req(SRV_AVRCP_PLAYER_APP_SETTING_SHUFFLE_MODE);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"check_status:%d",check_status); 
            check_status = srv_avrcp_check_attribute_support_status_req(SRV_AVRCP_PLAYER_APP_SETTING_SCAN_MODE);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"check_status:%d",check_status); 
            break;
        case 5:
            attr_id = SRV_AVRCP_PLAYER_APP_SETTING_REPEAT_MODE;
            check_status = srv_avrcp_get_attribute_supported_values_req(attr_id ,attr_val,&count1);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"result:%d",check_status);
            if (SRV_AVRCP_RESULT_CMD_SUCCESS != check_status)
                break;
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"count:%d",count1);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"attr_id:%d",attr_id);
            for (i=0;i<(count1);i++)
                kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"attr_value[%d]:%d",i,attr_val[i]);
            break;
        case 6:
            srv_avrcp_get_curr_player_app_value_req();
            break;
        case 7:
            srv_avrcp_set_player_app_value_req(values);
            break;
        case 8:
            srv_avrcp_get_player_app_attr_txt_req();
            break;
        case 9:
            srv_avrcp_get_playerapp_value_txt_equalizer_setting_req();
            break;
        case 10:
            srv_avrcp_get_playerapp_value_txt_repeat_setting_req();
            break;
        case 11:
            srv_avrcp_get_playerapp_value_txt_shuffle_setting_req();
            break;
        case 12:
            srv_avrcp_get_playerapp_value_txt_scan_setting_req();
            break;
        case 13:
            srv_avrcp_inform_displayable_charset_req(charset);
            break;
        case 14:
            srv_avrcp_inform_battery_status_of_ct_req(SRV_AVRCP_BATTERY_STATUS_CRITICAL);
            break;
        case 15:
            srv_avrcp_get_elements_attr_request();
            break;
        case 16:
            srv_avrcp_get_play_status_req();
            break;
        case 17:
            srv_avrcp_abort_continueing_req();
            break;
        case 18:
            srv_avrcp_unmask_reg_notification_event_id(SRV_AVRCP_EVENT_TRACK_REACHED_END,-1);
            break;
        case 19:
            check_status = srv_avrcp_unmask_reg_notification_event_id(SRV_AVRCP_EVENT_PLAYBACK_POS_CHNAGED,-1);
            kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"check_status:%d",check_status);
            break;
        case 20:
            srv_avrcp_open_dev(BT_AVRCP_CT);
            break;
        case 21:
            srv_avrcp_get_supported_attr_val_req();
            break;
        case 22:
            srv_avrcp_register_events_notification_req(reg_notity_result);
            break;
    }
    
    return 0;
}


void mmi_dummy_srv_avrcp_register_event(srv_avrcp_event_enum notify_event_id, srv_avrcp_result_union result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    S32 j = 0;
    S32 pos = 0;
    S32 attr_count;
    S32 attr_val_count;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (notify_event_id)
    {
        case SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_EVENT");
            
            if (result.supported_attr_list_result.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            attr_count = result.supported_attr_list_result.attr_count;
            
            for (j = 0; j < attr_count; ++j)
            {
                TRACE(result.supported_attr_list_result.supported_attr_list[j])
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_VALUE_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_SUPPORTED_ATTR_VALUE_EVENT,id:%d",result.supp_attr_val_list.attribute_id);

            if (result.supp_attr_val_list.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            attr_val_count = result.supp_attr_val_list.attr_val_count;
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "val_count:%d",attr_val_count);
            
            for (j = 0; j < attr_val_count; ++j)
            {
                TRACE(result.supp_attr_val_list.attr_values[j]);
            }
            
            break;
        }
        
        case  SRV_AVRCP_EVT_ID_CURR_ATTR_VAL_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_CURR_ATTR_VAL_EVENT");
            
            if (result.supported_attr_list_result.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.curr_attr_list_result.count);
            TRACE(result.curr_attr_list_result.error_code);
            TRACE(result.curr_attr_list_result.result);
            
            for (i = 0; i < result.curr_attr_list_result.count; ++i)
            {
                TRACE(result.curr_attr_list_result.curr_attr_list[i].attribute_id);
                TRACE(result.curr_attr_list_result.curr_attr_list[i].attr_values);
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_SET_PLAYERAPP_VAL_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_SET_PLAYERAPP_VAL_EVENT");
            
            if (result.result_cnf.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.curr_attr_list_result.error_code);
            TRACE(result.curr_attr_list_result.result);
            break;
        }
        
        case SRV_AVRCP_EVT_ID_ATTR_TXT_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_ATTR_TXT_EVENT");
            
            if (result.attr_txt_result.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.attr_txt_result.count);
            TRACE(result.attr_txt_result.error_code);
            TRACE(result.attr_txt_result.result);
            TRACE(result.attr_txt_result.count);
            
            for (i = 0; i < result.attr_txt_result.count; ++i)
            {
                TRACE(result.attr_txt_result.charset[i]);
                TRACE(result.attr_txt_result.attr_txt[i].attribute_id);
                TRACE_S(result.attr_txt_result.attr_txt[i].attr_str);
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_ATTR_TXT_VAL_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_ATTR_TXT_VAL_EVENT");
            
            if (result.val_txt_result.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.val_txt_result.count);
            TRACE(result.val_txt_result.attr_id);
            TRACE(result.val_txt_result.error_code);
            TRACE(result.val_txt_result.result);
            
            for (i = 0; i < result.val_txt_result.count; ++i)
            {
                TRACE(result.val_txt_result.value_txt[result.val_txt_result.attr_id].charset);
                TRACE(result.val_txt_result.value_txt[result.val_txt_result.attr_id].value_id);
                TRACE_S(result.val_txt_result.value_txt[result.val_txt_result.attr_id].value_str);
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_PLAY_STATUS_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_PLAY_STATUS_EVENT");
            
            if (result.play_status.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.play_status.error_code);
            TRACE(result.play_status.play_status);
            TRACE(result.play_status.result);
            TRACE(result.play_status.song_len);
            TRACE(result.play_status.song_pos);
            break;
        }
        
        case SRV_AVRCP_EVT_ID_ELEM_ATTR_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_ELEM_ATTR_EVENT");
            
            if (result.elem_attr.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.elem_attr.count);
            TRACE(result.elem_attr.error_code);
            TRACE(result.elem_attr.result);
            
            for (i = 0; i < result.elem_attr.count; ++i)
            {
                TRACE(result.elem_attr.elements[i].elem_id);
                TRACE(result.elem_attr.elements[i].charset);
                TRACE_S(result.elem_attr.elements[i].element_data);
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_INFORM_BATT_STATUS_CT_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_INFORM_BATT_STATUS_CT_EVENT");

            if (result.result_cnf.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.curr_attr_list_result.error_code);
            TRACE(result.curr_attr_list_result.result);
            break;
        }
        
        case SRV_AVRCP_EVT_ID_INFORM_DISPLAYABLE_CHARSET_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7,"SRV_AVRCP_EVT_ID_INFORM_DISPLAYABLE_CHARSET_EVENT");

            if (result.result_cnf.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.curr_attr_list_result.error_code);
            TRACE(result.curr_attr_list_result.result);
            break;
        }
        
        case SRV_AVRCP_EVT_ID_REG_NOTIFICATION_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_REG_NOTIFICATION_EVENT");
            
            if (result.reg_notification_event.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.reg_notification_event.is_interim);
            TRACE(result.reg_notification_event.event_id);
            TRACE(result.reg_notification_event.batt_status);
            TRACE(result.reg_notification_event.playback_status);
            TRACE(result.reg_notification_event.song_pos);
            TRACE(result.reg_notification_event.system_status);
            TRACE(result.reg_notification_event.count);
            
            for (i = 0; i < result.reg_notification_event.count; ++i)
            {
                TRACE(result.reg_notification_event.attr_id[i]);
                TRACE(result.reg_notification_event.attr_val[i]);
            }
            
            break;
        }
        
        case SRV_AVRCP_EVT_ID_ABORT_REQ_EVENT:
        {
            kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_7, "SRV_AVRCP_EVT_ID_ABORT_REQ_EVENT");
            
            if (result.result_cnf.result != SRV_AVRCP_RESULT_SUCCESS)
            {
                break;
            }
            
            TRACE(result.curr_attr_list_result.error_code);
            TRACE(result.curr_attr_list_result.result);
            break;
        }
    }
}
#endif //TEST CODE
#endif /*__MMI_BT_AVRCP_V13__*/


#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_actively_connect_tg_flag
 * DESCRIPTION
 *  get flag 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_avrcp_get_actively_connect_tg_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_GET_ACTIVELY_TG, g_srv_avrcp_actively_connect_tg);

    return g_srv_avrcp_actively_connect_tg;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_actively_connect_tg_flag
 * DESCRIPTION
 *  for em to set this flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_actively_connect_tg_flag(MMI_BOOL on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_TRC_SET_ACTIVELY_TG, on_off);

    g_srv_avrcp_actively_connect_tg = on_off;
}

#endif


#ifdef SRV_A2DP_SINK_BT_AVRCP_CONNECT_CT_ACTIVELY__
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_get_actively_connect_tg_flag
 * DESCRIPTION
 *  get flag 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_avrcp_get_actively_connect_ct_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return g_srv_avrcp_actively_connect_ct;
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_set_actively_connect_tg_flag
 * DESCRIPTION
 *  for em to set this flag
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_set_actively_connect_ct_flag(MMI_BOOL on_off)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    g_srv_avrcp_actively_connect_ct = on_off ;
}
#endif //SRV_A2DP_SINK_BT_AVRCP_CONNECT_CT_ACTIVELY__


#ifdef __BT_SPEAKER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_sink_timer_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_avrcp_sink_timer_callback(srv_bt_cm_bt_addr *dev_addr, U16 op_code, U8 command_type, BOOL key_press)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_CLEAR_CMD_FRAME, g_srv_avrcp_cntx[avrcp_chnl].cmd_frame); 

    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state != SRV_AVRCP_CONNECTED)
    {
        return;
    }
    
    srv_avrcp_cmd_frame_req(avrcp_chnl, BT_AVRCP_OP_PASS_THROUGH, g_srv_avrcp_cntx[avrcp_chnl].cmd_frame, 0);
    g_srv_avrcp_cntx[avrcp_chnl].is_timer_on = 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_sink_send_cmd_frame
 * DESCRIPTION
 *  send avrcp command to TG device
 * PARAMETERS
 *  cmd_frame           [IN]    :   cmd frame
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_sink_send_cmd_frame(S32 cmd_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_send_cmd_frame
 * DESCRIPTION
 *  send avrcp command to remote device
 * PARAMETERS
 *  dev_addr            [IN]    :   device address
 *  cmd_frame           [IN]    :   cmd frame
 * RETURNS
 *  void
 *****************************************************************************/
void srv_avrcp_send_cmd_frame(srv_bt_cm_bt_addr *dev_addr, S32 cmd_frame)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_SEND_CMD_FRAME, cmd_frame); 
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }

    if (g_srv_avrcp_cntx[avrcp_chnl].avrcp_state != SRV_AVRCP_CONNECTED)
    {
        return;
    }
    
    if (cmd_frame < 0)
    {
        return;
    }
    
    srv_avrcp_cmd_frame_req(avrcp_chnl, BT_AVRCP_OP_PASS_THROUGH, cmd_frame, 1);
    g_srv_avrcp_cntx[avrcp_chnl].cmd_frame = (U32)cmd_frame;
    g_srv_avrcp_cntx[avrcp_chnl].is_timer_on = 1;
}


static void srv_avrcp_ct_set_cmd_frame_cnf_hdlr(srv_bt_cm_bt_addr *dev_addr, srv_avrcp_cmd_cnf_callback callback_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return;
    }
    
    g_srv_avrcp_cntx[avrcp_chnl].avrcp_cmd_cnf_ptr = callback_func;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_is_avrcp_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_avrcp_is_avrcp_connected(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_IS_CONN, -1);
        return MMI_FALSE;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_IS_CONN, g_srv_avrcp_cntx[avrcp_chnl].avrcp_state);
    return MMI_AVRCP_CTX(avrcp_chnl, avrcp_state) == SRV_AVRCP_CONNECTED ? MMI_TRUE : MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_is_avrcp_ct_ready_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  MMI_BOOL    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_avrcp_is_avrcp_ct_ready_cmd(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 avrcp_chnl;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    avrcp_chnl = srv_avrcp_find_channel_by_device_addr(dev_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_AVRCP_CT_TRC_IS_CT_READY, g_srv_avrcp_cntx[avrcp_chnl].is_timer_on); 

    if (MMI_FALSE == srv_avrcp_check_channel_valid(avrcp_chnl))
    {
        return MMI_FALSE;
    }

    return g_srv_avrcp_cntx[avrcp_chnl].is_timer_on == 0 ? MMI_TRUE : MMI_FALSE;
}
#endif //__BT_SPEAKER_SUPPORT__

#endif /* (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__)) */

