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
 * BLEcmSrvInterface.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM external API and internal API declaration
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/

#include "bluetooth_bm_struct.h"

#include "MMIDataType.h"

#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "MMI_conn_app_trc.h"   

#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "app_ltlcom.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"

#include "kal_public_api.h"
#include "bluetooth_struct.h"
#include "BLEcmSrvProt.h"
#include "BLESrvGprot.h"
#include "BtcmSrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"

static void srv_ble_event_notify_handler(U32 event, void* para);
static void srv_ble_cm_set_notify_event(void);
srv_le_cm_auto_conn_dev_struct g_srv_ble_cm_auto_conn_dev[SRV_BLE_CM_MAX_CONNECTED_LIST];

#ifdef __MMI_BLE_LOW_POWER__
#include "GattcSrv.h"
#endif

#ifdef __MMI_BLE_LOW_POWER__
#define SRV_BLE_SET_ADV_INTERVAL_TIME        (1000 * 30)
#define SRV_BLE_UPDATE_CONN_INTERVAL_TIME        (1000 * 30)
#define SRV_BLE_MAX_TIMER_NUM  8
#define SRV_BLE_PROFILE_ID (100)
typedef struct
{
    srv_bt_cm_bt_addr dev_addr;
	U16 timer_id; 
} srv_ble_conn_update_struct;

srv_ble_conn_update_struct conn_update_info;

U16 g_srv_ble_timer_id[SRV_BLE_MAX_TIMER_NUM] = {
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID0, 
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID1,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID2,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID3,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID4,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID5,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID6,
	SRV_BLE_UPDATE_CONN_INTERVAL_TIMER_ID7};

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_get_bd_addr
 * DESCRIPTION
 *  convert srv bt cm addr to bd addr
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ble_cm_get_bd_addr(BD_ADDR *dst, const srv_bt_cm_bt_addr *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((U8 *)&dst->addr[0], (U8 *)&src->lap, 3);
    dst->addr[3] = src->uap;
    memcpy((U8 *)&dst->addr[4], (U8 *)&src->nap, 2);
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
			SRV_BLE_CM_GATT_CNF, 
			dst->addr[0],
	        dst->addr[1],
	        dst->addr[2],
	        dst->addr[3],
	        dst->addr[4],
	        dst->addr[5],
	        1,
	        0,
	        0,
	        2);

}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_set_adv_param_end
 * DESCRIPTION
 *  send request for adv interval setting
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ble_set_adv_param_end(void)
{
	srv_gattc_set_adv_interval((U32)SRV_BLE_PROFILE_ID, GATTC_ADV_INTERVAL_REDUCE_POWER);
	StopTimer(SRV_BLE_SET_ADV_INTERVAL_TIMER_ID);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_set_adv_param_pattern
 * DESCRIPTION
 *  send request for adv interval setting
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ble_set_adv_param_pattern(void)
{
	srv_gattc_set_adv_interval((U32)SRV_BLE_PROFILE_ID, GATTC_ADV_INTERVAL_FAST_CONN);
	
	StopTimer(SRV_BLE_SET_ADV_INTERVAL_TIMER_ID);
	StartTimer(SRV_BLE_SET_ADV_INTERVAL_TIMER_ID, SRV_BLE_SET_ADV_INTERVAL_TIME, srv_ble_set_adv_param_end);
}



/*****************************************************************************
 * FUNCTION
 *  srv_ble_update_conn_interval_req
 * DESCRIPTION
 *  send request for adv interval setting
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ble_update_conn_interval_req(void* arg)
{
	BD_ADDR bdaddr;
	U16 timer_id = 0;
	srv_ble_conn_update_struct *conn_info = (srv_ble_conn_update_struct *)arg;

	timer_id = conn_info->timer_id;
	memset(&bdaddr, 0, sizeof(BD_ADDR));
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
			SRV_BLE_CM_GATT_CNF, 
			((conn_info->dev_addr.nap & 0xff00) >> 8),
			(conn_info->dev_addr.nap & 0x00ff),
			(conn_info->dev_addr.uap),
			((conn_info->dev_addr.lap & 0xff0000) >> 16),
			((conn_info->dev_addr.lap & 0x00ff00) >> 8),
			(conn_info->dev_addr.lap & 0x0000ff),
	        1,
	        0,
	        0,
	        1);
	srv_ble_cm_get_bd_addr(&bdaddr, &conn_info->dev_addr);

	srv_gattc_conn_param_update((U32)SRV_BLE_PROFILE_ID, (char *)bdaddr.addr, CONNECTION_PRIORITY_LOW_POWER);
	StopTimer(timer_id);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_get_unused_timer_id
 * DESCRIPTION
 *  get one unusing timer id
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_ble_get_unused_timer_id(void)
{
	int i;
	
	for (i = 0; i < SRV_BLE_MAX_TIMER_NUM; i++)
	{
		if (!IsMyTimerExist(g_srv_ble_timer_id[i]))
		{
			return g_srv_ble_timer_id[i];
		}
	}
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_update_conn_interval_start
 * DESCRIPTION
 *  send request for connection interval setting
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ble_update_conn_interval_start(srv_bt_cm_bt_addr* dev_addr)
{	
	U16 timer_id = 0;

	timer_id = srv_ble_get_unused_timer_id();
	if (0 != timer_id)
	{
		//conn_info.dev_addr = dev_addr;
		memset(&conn_update_info, 0x00, sizeof(srv_ble_conn_update_struct));
		memcpy(&conn_update_info.dev_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
		MMI_TRACE(MMI_CONN_TRC_G7_BT,
			SRV_BLE_CM_GATT_CNF, 
			((conn_update_info.dev_addr.nap & 0xff00) >> 8),
	        (conn_update_info.dev_addr.nap & 0x00ff),
	        (conn_update_info.dev_addr.uap),
	        ((conn_update_info.dev_addr.lap & 0xff0000) >> 16),
	        ((conn_update_info.dev_addr.lap & 0x00ff00) >> 8),
	        (conn_update_info.dev_addr.lap & 0x0000ff),
	        1,
	        0,
	        0,
	        0);
		conn_update_info.timer_id = timer_id;
		StartTimerEx(timer_id, 
			SRV_BLE_UPDATE_CONN_INTERVAL_TIME, 
			srv_ble_update_conn_interval_req, 
			(void *)&conn_update_info);
	}

}

#endif /*__MMI_BLE_LOW_POWER__*/

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_init
 * DESCRIPTION
 *  This function is to init CM
 *        1. set flag
 *        2. init context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ble_cm_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_INIT_FUNC);
    memset(&g_srv_ble_cm_cntx, 0, sizeof(srv_ble_cm_cntx_struct));

	g_srv_ble_cm_cntx.connected_dev_num = 0;
	srv_ble_init_event_handler();
	
	srv_ble_cm_set_notify_event();
}
/*****************************************************************************
 * FUNCTION
 *  srv_ble_event_notify_handler
 * DESCRIPTION
 *  This function is to received bt notify event
 * PARAMETERS
 *  event: bt notify event id
 *  para : bt notify event para
 *
 * RETURNS
 *  voids
 *****************************************************************************/
static void srv_ble_event_notify_handler(U32 event, void* para)
{
    switch (event)
    {
        case SRV_BT_CM_EVENT_PANIC_IND:
			#ifdef __MMI_BLE_LOW_POWER__
			StopTimer(SRV_BLE_SET_ADV_INTERVAL_TIMER_ID);
			#endif
			srv_ble_cm_init();
	        break;
			
		case SRV_BT_CM_EVENT_ACTIVATE:
			#ifdef __MMI_BLE_LOW_POWER__
			srv_ble_set_adv_param_pattern();
			#endif
			
			break;
			
		default :
			break;
	}

}


/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_set_notify_event
 * DESCRIPTION
 *  This function is set bt event
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ble_cm_set_notify_event(void)
{
	U32 event_mask;

    event_mask = SRV_BT_CM_EVENT_PANIC_IND |
                 SRV_BT_CM_EVENT_ACTIVATE;
	
	srv_bt_cm_set_notify((srv_bt_cm_notifier)srv_ble_event_notify_handler, event_mask, NULL);
	return;


}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_get_state
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_ble_cm_state_enum          current bluetooth state
 *****************************************************************************/
srv_ble_cm_state_enum srv_ble_cm_get_state(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_GET_STATE,
        g_srv_ble_cm_cntx.dev_state.state);
	
    return g_srv_ble_cm_cntx.dev_state.state;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_get_state
 * DESCRIPTION
 *  This function is to get current bluetooth state
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_ble_cm_state_enum          current bluetooth state
 *****************************************************************************/
srv_bt_cm_bt_addr* srv_ble_cm_get_current_dev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_GET_CURRENT_DEV,
		((g_srv_ble_cm_cntx.dev_state.dev_addr.nap & 0xff00) >> 8),
        (g_srv_ble_cm_cntx.dev_state.dev_addr.nap & 0x00ff),
        (g_srv_ble_cm_cntx.dev_state.dev_addr.uap),
        ((g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0xff0000) >> 16),
        ((g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0x00ff00) >> 8),
        (g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0x0000ff));
    return &g_srv_ble_cm_cntx.dev_state.dev_addr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_set_state
 * DESCRIPTION
 *  This function is to set current bluetooth state
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_ble_cm_state_enum          current bluetooth state
 *****************************************************************************/
void srv_ble_cm_set_state(srv_bt_cm_bt_addr* addr, srv_ble_cm_state_enum state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	g_srv_ble_cm_cntx.dev_state.state = state;

	if(addr)
	{
	    memcpy(&g_srv_ble_cm_cntx.dev_state.dev_addr, addr, sizeof(srv_bt_cm_bt_addr));
		MMI_TRACE(
			MMI_CONN_TRC_G7_BT,
			SRV_BLE_CM_SET_STATE_2,
			((g_srv_ble_cm_cntx.dev_state.dev_addr.nap & 0xff00) >> 8),
	        (g_srv_ble_cm_cntx.dev_state.dev_addr.nap & 0x00ff),
	        (g_srv_ble_cm_cntx.dev_state.dev_addr.uap),
	        ((g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0xff0000) >> 16),
	        ((g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0x00ff00) >> 8),
	        (g_srv_ble_cm_cntx.dev_state.dev_addr.lap & 0x0000ff));
	}
	else
	{
        memset(&g_srv_ble_cm_cntx.dev_state.dev_addr, 0, sizeof(srv_bt_cm_bt_addr));
	}
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_SET_STATE,
		g_srv_ble_cm_cntx.dev_state.state);
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_search
 * DESCRIPTION 
 *  This function is to process inquiry request and invoke srv_bt_cm_discovery_req_hdler
 * PARAMETERS
 *  max_response        [IN]            max repsone number of device
 *  timeout             [IN]                inquiry timeout timer
 *  cod                 [IN]                  class of device
 *  name_discovery      [IN]            name discovery 
 *  user_data   [IN]            user data 
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_ble_cm_search(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_bm_discovery_req_struct* msg_p;
    U32 i=0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	U32 bt_state = srv_bt_cm_get_state();
    MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_SEARCH_FUNC ,max_response, timeout, cod, name_discovery,g_srv_ble_cm_cntx.dev_state.state);
    if ((bt_state >= SRV_BT_CM_STATE_IDLE) &&
		(bt_state != SRV_BT_CM_STATE_INQUIRING) &&
        (bt_state != SRV_BT_CM_STATE_INQUIR_RES_IND) &&
        (bt_state != SRV_BT_CM_STATE_INQUIR_CANCELLING) &&
        (bt_state != SRV_BT_CM_STATE_BONDING) &&
        (bt_state != SRV_BT_CM_STATE_PASSKEY_IND) &&
        (bt_state != SRV_BT_CM_STATE_PASSKEY_RES) &&
        (bt_state != SRV_BT_CM_STATE_NUMERIC_CONFIRM) &&
        (bt_state != SRV_BT_CM_STATE_NUMERIC_CONFIRM_RSP) &&
        (bt_state != SRV_BT_CM_STATE_PASSKEY_NOTIFY) &&
        (bt_state != SRV_BT_CM_STATE_KEYPRESS_NOTIFY_CANCEL) &&
        (bt_state != SRV_BT_CM_STATE_SDC_SEARCHING) &&
        (bt_state != SRV_BT_CM_STATE_CONNECTING) &&
        (g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIRING) &&
        (g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIR_RES_IND) &&
        (g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIR_CANCELLING) &&
        (g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_DISCONNECTING) &&
        (g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_CONNECTING))
    {

		  srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_INQUIRING);
	
	    msg_p = (bt_bm_discovery_req_struct*)construct_local_para(
	        sizeof(bt_bm_discovery_req_struct),
	        TD_CTRL);
	    msg_p->cod = cod;
	    msg_p->inquiry_length = ((timeout * 1000) / 1280);
	    msg_p->inquiry_number = max_response;
	    msg_p->access_mode = BTBM_GENERAL_INQUIRY;
	    if (name_discovery)
	    {
	        msg_p->discovery_mode = BTBM_DISCOVERY_WITH_NAME;// if no get name, will go name discovery
	    }
	    else
	    {
	        msg_p->discovery_mode = BTBM_DISCOVERY_WITHOUT_NAME;
	    }

		msg_p->discovery_type = BTBM_DISCOVERY_LE_ONLY;
		memset(g_srv_ble_cm_cntx.scan_list, 0, sizeof(srv_bt_cm_dev_struct)*SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST);
		g_srv_ble_cm_cntx.discovered_dev_num = 0;
	    for (i = 0; i < SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST; i++)
	    {
			MMI_TRACE(MMI_CONN_TRC_G7_BT, 
				   SRV_BLE_CM_SEARCHED_LIST,
				   i,
				   ((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0xff00) >> 8),
				   (g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0x00ff),
				   (g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.uap),
				   ((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0xff0000) >> 16),
				   ((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x00ff00) >> 8),
				   (g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x0000ff),
				   g_srv_ble_cm_cntx.discovered_dev_num);
		}

		srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_REQ, (void*)msg_p, NULL);

		return SRV_BT_CM_RESULT_SUCCESS;
	}

    return SRV_BT_CM_RESULT_FAILED;
}
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_search_abort
 * DESCRIPTION
 *  This function is to process inquiry cancel request and invoke srv_bt_cm_cancel_discovery_req_hdler
 * PARAMETERS
 *  user_data        [IN]            user data
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_ble_cm_search_abort(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_SEARCH_ABORT,
        g_srv_ble_cm_cntx.dev_state.state);

    switch (g_srv_ble_cm_cntx.dev_state.state)
    {
        case SRV_BLE_CM_STATE_INQUIRING:
        case SRV_BLE_CM_STATE_INQUIR_RES_IND:		
			srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_INQUIR_CANCELLING);
			srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_DISCOVERY_CANCEL_REQ, (void*)NULL, NULL);
            return SRV_BT_CM_RESULT_SUCCESS;
    }
    
    return SRV_BT_CM_RESULT_FAILED;
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_dev_index
 * DESCRIPTION
 *  this function is to get device index in corresponding device list
 *  according to device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return index in corresponding device list
 *  if failed to find the device, return 0xFFFFFFFF
 ******************************************************************************/
U32 srv_ble_cm_get_dev_index(const srv_bt_cm_bt_addr* dev_addr, srv_ble_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, idx, total_num = 0;
    U8* idx_list = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_GET_DEV_INDEX,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_type);

    if (dev_addr)
    {
        switch (dev_type)
        {
            case SRV_BLE_CM_DISCOVERED_DEV:
                for (i = 0; i < g_srv_ble_cm_cntx.discovered_dev_num; ++i)
                {
                    if (srv_bt_cm_is_dev_addr_equal(&g_srv_ble_cm_cntx.scan_list[i].le_bd_addr, dev_addr))
                    {
                        MMI_TRACE(
                            MMI_CONN_TRC_G7_BT,
                            SRV_BLE_CM_GET_DEV_INDEX_2,
                            i);

                        return i;
                    }
                }
                return 0xFFFFFFFF;

            case SRV_BLE_CM_CONNECTED_DEV:
             
				for (i = 0; i < g_srv_ble_cm_cntx.connected_dev_num; ++i)
				{
					if (srv_bt_cm_is_dev_addr_equal(&g_srv_ble_cm_cntx.connected_list[i].le_bd_addr, dev_addr))
					{
						 MMI_TRACE(
							 MMI_CONN_TRC_G7_BT,
							 SRV_BLE_CM_GET_DEV_INDEX_2,
							 i);

						 return i;
					}
				}
				return 0xFFFFFFFF;
             
                break;

        }

    }
   
    return 0xFFFFFFFF;
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_dev_info_by_addr
 * DESCRIPTION
 *  this function is to get the device infomation througth device address
 *  according to the device type
 * PARAMETERS
 *  dev_addr:    [IN]    device address
 *  dev_type:    [IN]    device type
 *  
 * RETURNS
 *  if succeed to find the device, return its infomation
 *  if failed to find the device, return NULL
 ******************************************************************************/
const srv_bt_cm_dev_struct* srv_ble_cm_get_dev_info_by_addr(
    const srv_bt_cm_bt_addr* dev_addr,
    srv_ble_cm_dev_type_enum dev_type)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i=0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_GET_DEV_INFO_BY_ADDR,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_type);


	i= srv_ble_cm_get_dev_index(dev_addr,dev_type);
	if (dev_type==SRV_BLE_CM_DISCOVERED_DEV && i!=0xFFFFFFFF)
    {
	    return &g_srv_ble_cm_cntx.scan_list[i];
	}

    else if (dev_type==SRV_BLE_CM_CONNECTED_DEV && i!=0xFFFFFFFF)
    {
		return &g_srv_ble_cm_cntx.connected_list[i];
    }
    return NULL;


}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_copy_addr
 * DESCRIPTION
 *  this function is to copy address.
 * PARAMETERS
 *  dest
 *  src
 *  
 * RETURNS
 * void
 ******************************************************************************/

void srv_ble_cm_copy_addr(void *dest,void *src)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/
	srv_bt_cm_bt_addr *addr_src= (srv_bt_cm_bt_addr *) src;
	srv_bt_cm_bt_addr *addr_dest= (srv_bt_cm_bt_addr *) dest;

	/*----------------------------------------------------------------*/
	/* Code Body 											       */
	/*----------------------------------------------------------------*/

	addr_dest->lap = addr_src->lap;
	addr_dest->nap = addr_src->nap;
	addr_dest->uap = addr_src->uap;

}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_connect_req
 * DESCRIPTION
 *  this function is send event to app ,connect gatt.
 * PARAMETERS
 *  dev_addr:  [IN] address
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_connect_req(srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

   	srv_le_cm_evt_connect_req_struct evt_info;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_CONNECT_REQ, 
		((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));
	memset(&evt_info,0,sizeof(evt_info));
	srv_ble_cm_set_state(dev_addr,SRV_BLE_CM_STATE_CONNECTING);
    MMI_FRM_INIT_EVENT(&evt_info, SRV_LE_CM_EVENT_CONNECT_REQ);	
    evt_info.dev_addr=dev_addr;
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_CONNECT_REQ, 
		((evt_info.dev_addr->nap & 0xff00) >> 8),
        (evt_info.dev_addr->nap & 0x00ff),
        (evt_info.dev_addr->uap),
        ((evt_info.dev_addr->lap & 0xff0000) >> 16),
        ((evt_info.dev_addr->lap & 0x00ff00) >> 8),
        (evt_info.dev_addr->lap & 0x0000ff));
    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info);

}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_disconnect_req
 * DESCRIPTION
 *  this function is send event to app ,disconnect gatt.
 * PARAMETERS
 *  dev_addr:  [IN] address
 *  
 * RETURNS
 * void
 ******************************************************************************/

void srv_ble_cm_disconnect_req(srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	srv_le_cm_evt_disconnect_struct evt_info;
	srv_le_cm_evt_gatt_cnf_struct evt_info1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_DISCONNECT_REQ, 
		((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));
	
	if (MMI_TRUE == srv_ble_cm_is_auto_conn_dev(dev_addr))
	{
	
        memset(&evt_info1,0,sizeof(srv_le_cm_evt_gatt_cnf_struct));
	    MMI_FRM_INIT_EVENT(&evt_info1, SRV_LE_CM_EVENT_DISCONNECT_CNF); 
		memcpy(&evt_info1.dev_addr,dev_addr,sizeof(srv_bt_cm_bt_addr));
		evt_info1.is_conn = MMI_FALSE;
		evt_info1.is_ind= MMI_FALSE;
		evt_info1.result= MMI_FALSE;
		mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info1);
	}
	else
	{
	    memset(&evt_info,0,sizeof(evt_info));
		srv_ble_cm_set_state(dev_addr, SRV_BLE_CM_STATE_DISCONNECTING);
	    MMI_FRM_INIT_EVENT(&evt_info, SRV_LE_CM_EVENT_DISCONNECT_REQ);	
	    evt_info.dev_addr=dev_addr;
		MMI_TRACE(MMI_CONN_TRC_G7_BT,
			SRV_BLE_CM_DISCONNECT_REQ, 
			((evt_info.dev_addr->nap & 0xff00) >> 8),
	        (evt_info.dev_addr->nap & 0x00ff),
	        (evt_info.dev_addr->uap),
	        ((evt_info.dev_addr->lap & 0xff0000) >> 16),
	        ((evt_info.dev_addr->lap & 0x00ff00) >> 8),
	        (evt_info.dev_addr->lap & 0x0000ff));
	    mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info);
	}

}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_gatt_cnf
 * DESCRIPTION
 *  this function is send gatt connect/disconnect cnf.
 * PARAMETERS
 *  dev_info:  [IN] the device info.
 *  
 * RETURNS
 * void
 ******************************************************************************/

void srv_ble_cm_gatt_cnf(srv_le_cm_gatt_dev_info_struct* dev_info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/

	//WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
  //  WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};

	srv_le_cm_evt_gatt_cnf_struct evt_info;
    memset(&evt_info,0,sizeof(srv_le_cm_evt_gatt_cnf_struct));
//	mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)dev_info->name);
		
//	mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
//	kal_prompt_trace(MOD_MMI, "[BLECM]gatt_cnf NAME = %s", string1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_GATT_CNF, 
		((dev_info->dev_addr->nap & 0xff00) >> 8),
        (dev_info->dev_addr->nap & 0x00ff),
        (dev_info->dev_addr->uap),
        ((dev_info->dev_addr->lap & 0xff0000) >> 16),
        ((dev_info->dev_addr->lap & 0x00ff00) >> 8),
        (dev_info->dev_addr->lap & 0x0000ff),
        dev_info->is_conn,
        dev_info->is_ind,
        dev_info->result,
        dev_info->reason);
    
	if (dev_info->is_conn)
	{   
	  	//if it is auto-connect device , need  delete auto-connect device
        if (srv_ble_cm_is_auto_conn_dev(dev_info->dev_addr))
        {
			srv_ble_cm_reset_auto_conn_dev(dev_info->dev_addr);
			if (!dev_info->result)
			{
			
			    srv_ble_cm_del_connected_list(dev_info);
				MMI_FRM_INIT_EVENT(&evt_info, SRV_LE_CM_EVENT_DISCONNECT_CNF); 
				memcpy(&evt_info.dev_addr,dev_info->dev_addr,sizeof(srv_bt_cm_bt_addr));
				evt_info.is_conn = MMI_FALSE;
				evt_info.is_ind= MMI_TRUE;
				evt_info.result= MMI_FALSE;	
				mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info);

			}

		}
		else
		{
		MMI_FRM_INIT_EVENT(&evt_info, SRV_LE_CM_EVENT_CONNECT_CNF); 
		memcpy(&evt_info.dev_addr,dev_info->dev_addr,sizeof(srv_bt_cm_bt_addr));
        evt_info.is_conn = dev_info->is_conn;
        evt_info.is_ind= dev_info->is_ind;
        evt_info.result= dev_info->result;
        
		if(dev_info->result)
	    {
			srv_ble_cm_add_connected_list(dev_info);
		#ifdef __MMI_BLE_LOW_POWER__
			//StopTimer(SRV_BLE_SET_ADV_INTERVAL_TIMER_ID);
			srv_ble_update_conn_interval_start(dev_info->dev_addr);
		#endif

		}
		mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info);

	}
	}
	else
	{
	    if((dev_info->reason == 0x3e) && (dev_info->is_ind))
	    {
			if(!srv_ble_cm_is_auto_conn_dev(dev_info->dev_addr))	    //set auto-connect device falg, info.
			{
			    if(srv_ble_cm_set_auto_conn_dev(dev_info->dev_addr))
			    {
				    srv_ble_cm_connect_req(dev_info->dev_addr);
			    }
			}
			else
			{
				srv_ble_cm_connect_req(dev_info->dev_addr);

			}
	    }
		else
		{
	
			MMI_FRM_INIT_EVENT(&evt_info, SRV_LE_CM_EVENT_DISCONNECT_CNF); 
			memcpy(&evt_info.dev_addr,dev_info->dev_addr,sizeof(srv_bt_cm_bt_addr));
	        evt_info.is_conn = dev_info->is_conn;
	        evt_info.is_ind= dev_info->is_ind;
	        evt_info.result= dev_info->result;
			if(dev_info->result)
		    {
				srv_ble_cm_del_connected_list(dev_info);
		    #ifdef __MMI_BLE_LOW_POWER__
			    srv_ble_set_adv_param_pattern();
		    #endif

			}
			mmi_frm_cb_emit_event((mmi_event_struct*)&evt_info);

		}
	}
	/*if (!dev_info->is_ind)
	{
		srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
	}
	else if((dev_info->is_ind))*/
	{
	    if(((SRV_BLE_CM_STATE_DISCONNECTING == srv_ble_cm_get_state())||
			(SRV_BLE_CM_STATE_CONNECTING == srv_ble_cm_get_state())) && 
			//(srv_ble_cm_get_current_dev()== dev_info->dev_addr)
			(srv_bt_cm_is_dev_addr_equal( dev_info->dev_addr, srv_ble_cm_get_current_dev())))
	    {
		    srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
	    }

	}

}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_maxed_linked_num
 * DESCRIPTION
 *  this function is to get maxed linked num,BLE_LINK_NUM is defined in le cm service.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32: the maxed num.
 ******************************************************************************/

U32 srv_ble_cm_get_maxed_linked_num(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												 */
	/*----------------------------------------------------------------*/	
    /*----------------------------------------------------------------*/
    /* Code Body                                                                               */
    /*----------------------------------------------------------------*/

	return BLE_LINK_NUM;
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_connected_list_inx
 * DESCRIPTION
 *  this function is to get index about connected list.
 * PARAMETERS
 *  dev_addr:  [IN] address
 *  
 * RETURNS
 * U32: index
 ******************************************************************************/

U32 srv_ble_cm_get_connected_list_inx(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < BLE_LINK_NUM; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_srv_ble_cm_cntx.connected_list[i].le_bd_addr, dev_addr))
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_GET_CONNED_LIST_INX,i);
            return i;
        }
    }
    
    return -1;    
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_searched_dev_num
 * DESCRIPTION
 *  this function is to get total number about scan_list.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32: number
 ******************************************************************************/   
U32 srv_ble_cm_get_searched_dev_num(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/

   return srv_ble_cm_get_dev_num(SRV_BT_CM_DISCOVERED_DEV);
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_searched_dev_info
 * DESCRIPTION
 *  this function is to get device info in scan list by index.
 * PARAMETERS
 *  U16: [IN] index
 *  
 * RETURNS
 * srv_bt_cm_dev_struct* : the device info
 ******************************************************************************/  

srv_bt_cm_dev_struct* srv_ble_cm_get_searched_dev_info(U16 index)
{
   /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/
   U32 i=0;

   MMI_TRACE(
	   MMI_CONN_TRC_G7_BT,
	   SRV_BLE_CM_GET_SEARCHED_DEV_INFO,
	   index);

   MMI_BT_ASSERT(index < g_srv_ble_cm_cntx.discovered_dev_num);
   for (i = 0; i < SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST; i++)
   {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_SEARCHED_LIST,
			i,
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.uap),
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_cntx.discovered_dev_num);
	}
   
   return &(g_srv_ble_cm_cntx.scan_list[index]);
}

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_connected_dev_num
 * DESCRIPTION
 *  this function is to get the number about connected device.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32 : number
 ******************************************************************************/  
U32 srv_ble_cm_get_connected_dev_num(void)
{
   /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/

   return srv_ble_cm_get_dev_num(SRV_BLE_CM_CONNECTED_DEV);
}
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_connected_dev_info
 * DESCRIPTION
 *  this function is to get the device infor in connected device by index
 * PARAMETERS
 *  U16: [IN] index
 *  
 * RETURNS
 * srv_bt_cm_dev_struct* : the device info
 ******************************************************************************/  
srv_bt_cm_dev_struct* srv_ble_cm_get_connected_dev_info(U16 index)
{
   /*----------------------------------------------------------------*/
   /* Local Variables												 */
   /*----------------------------------------------------------------*/

   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/
	//WCHAR string[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};
	//WCHAR string1[NVRAM_BYTE_BT_DIALER_CONNSTR_SIZE] = {0};


	//mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (SRV_BT_CM_BD_UCS2_NAME_LEN * 2), (kal_uint8*)g_srv_ble_cm_cntx.connected_list[index].name);

	//mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
	//kal_prompt_trace(MOD_MMI, "[BLECM]get_connected_dev NAME = %s", string1);
	MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_GET_CONNECTED_DEV_INFO,index);

    MMI_BT_ASSERT(index < g_srv_ble_cm_cntx.connected_dev_num);

    return &(g_srv_ble_cm_cntx.connected_list[index]);
}


/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_set_visibility
 * DESCRIPTION
 *  This function is to handle write scanenable mode request and send MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ
 * PARAMETERS
 *  type       [IN]            visiblity type
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_ble_cm_set_visibility(srv_ble_cm_visibility_type type)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U8 page_inquiry_mode = 0;
	
    bt_bm_write_scanenable_mode_req_struct* msg_p;
	static S32 vis = SRV_BLE_CM_VISIBILITY_P_ON_I_ON;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_SET_VISIBILITY,
		vis, 
		type,
		g_srv_ble_cm_cntx.dev_state.state);
	if (vis != type)
	{
		srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_VISIBILITY_SETTING);
	
		switch (type)
		{
			case SRV_BLE_CM_VISIBILITY_P_ON_I_ON:
				page_inquiry_mode = BTBM_ADP_P_ON_I_ON_L_OFF;
				break;

			case SRV_BLE_CM_VISIBILITY_P_OFF_I_OFF:
				page_inquiry_mode = BTBM_ADP_P_OFF_I_OFF_L_OFF;
				break;
				
			case SRV_BLE_CM_VISIBILITY_P_OFF_I_ON:
				page_inquiry_mode = BTBM_ADP_P_OFF_I_ON_L_OFF;
				break;
				
			case SRV_BLE_CM_VISIBILITY_P_ON_I_OFF:
				page_inquiry_mode = BTBM_ADP_P_ON_I_OFF_L_OFF;
				break;
		}

	    MMI_TRACE(
	        MMI_CONN_TRC_G7_BT,
	        SRV_BLE_CM_WRITE_SCANENABLE_MODE_REQ,
	        page_inquiry_mode);

	    msg_p = (bt_bm_write_scanenable_mode_req_struct*)construct_local_para(
	        sizeof(bt_bm_write_scanenable_mode_req_struct),
	        TD_CTRL);
	    msg_p->mode = (btbm_scan_enable_type)page_inquiry_mode;
	    srv_bt_cm_send_msg(MOD_BT, BT_APP_SAP, MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ, (void*)msg_p, NULL);

		return SRV_BT_CM_RESULT_SUCCESS;
	}

	return SRV_BT_CM_RESULT_FAILED;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_update_conn_dev_name
 * DESCRIPTION
 *  This function is to handle update connected device name,send event to ap.
 * PARAMETERS
 *  dev_name       [IN]          
 *  dev_addr       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/

void srv_ble_cm_update_conn_dev_name(kal_uint8 * dev_name, srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dev_idx = -1;
	mmi_event_struct evt;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(dev_name && dev_addr)
    {
       if( srv_ble_cm_get_dev_info_by_addr(dev_addr,SRV_BLE_CM_CONNECTED_DEV))
       {
			dev_idx = srv_ble_cm_get_connected_list_inx(dev_addr);
			memcpy(g_srv_ble_cm_cntx.connected_list[dev_idx].name,dev_name,sizeof(kal_uint8)*SRV_BT_CM_BD_FNAME_LEN-1);
			g_srv_ble_cm_cntx.connected_list[dev_idx].name[SRV_BT_CM_BD_FNAME_LEN-1] = '\0';
		  
			MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_UPDATE_CONN_DEV_NAME);
			// send  update name           
			MMI_FRM_INIT_EVENT(&evt, SRV_LE_CM_EVENT_UPDATE_NAME); 
			mmi_frm_cb_emit_event(&evt);
	   }
	}
	 {// test
			   WCHAR string[100] = {0};
			   WCHAR string1[100] = {0};
			   mmi_chset_utf8_to_ucs2_string((kal_uint8*)string, (100 * 2), (kal_uint8*)g_srv_ble_cm_cntx.connected_list[dev_idx].name);
			   mmi_wcs_to_asc((CHAR *)string1, (WCHAR *)string);
			   kal_prompt_trace(MOD_MMI, "[BLECM]update NAME = %s, dev_idx = %d", g_srv_ble_cm_cntx.connected_list[dev_idx].name, dev_idx); 
	}
}
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_set_auto_conn_dev
 * DESCRIPTION
 *  This function is to set auto reconnect device when 0x3e error happen from BT task to mmi.
 * PARAMETERS       
 *  dev_addr       [IN]            
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

MMI_BOOL srv_ble_cm_set_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U32 i;
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_SET_AUTO_CONN_DEV,
        ((dev_addr->nap & 0xff00) >> 8),
		(dev_addr->nap & 0x00ff),
		(dev_addr->uap),
		((dev_addr->lap & 0xff0000) >> 16),
		((dev_addr->lap & 0x00ff00) >> 8),
		(dev_addr->lap & 0x0000ff));
	
	for (i = 0; i < BLE_LINK_NUM; i++)
    {
        if (srv_ble_cm_addr_is_null(&g_srv_ble_cm_auto_conn_dev[i].bd_addr))
        {
            memcpy(&g_srv_ble_cm_auto_conn_dev[i].bd_addr,dev_addr, sizeof(srv_bt_cm_bt_addr));
			g_srv_ble_cm_auto_conn_dev[i].conn_flag = MMI_TRUE;
			result = MMI_TRUE;
		}
        break;
    }
    for (i = 0; i < BLE_LINK_NUM; i++)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_AUTO_CONN_DEV_LIST,
			i,
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.uap),
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_auto_conn_dev[i].conn_flag);
    }
    return result;
     
}
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_is_auto_conn_dev
 * DESCRIPTION
 *  This function is to judge whether the device is auto connect dev.
 * PARAMETERS
 *  dev_name       [IN]          
 *  dev_addr       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/

MMI_BOOL srv_ble_cm_is_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U32 i;
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
	        SRV_BLE_CM_IS_AUTO_CONN_DEV,
	        ((dev_addr->nap & 0xff00) >> 8),
			(dev_addr->nap & 0x00ff),
			(dev_addr->uap),
			((dev_addr->lap & 0xff0000) >> 16),
			((dev_addr->lap & 0x00ff00) >> 8),
			(dev_addr->lap & 0x0000ff));

	
	for (i = 0; i < BLE_LINK_NUM; ++i)
    {
        if (srv_bt_cm_is_dev_addr_equal(&g_srv_ble_cm_auto_conn_dev[i].bd_addr, dev_addr))
        {
            MMI_TRACE(
                MMI_CONN_TRC_G7_BT,
                SRV_BLE_CM_IS_AUTO_CONN_DEV_2,
                i);

            result = MMI_TRUE;
        }
    }
    return result;
     
}
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_reset_auto_conn_dev
 * DESCRIPTION
 *  This function is to clean the auto connect device in cm.
 * PARAMETERS
 *  dev_name       [IN]          
 *  dev_addr       [IN]            
 * RETURNS
 *  void
 *****************************************************************************/

void srv_ble_cm_reset_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr)
{
    
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 i, j;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
	        SRV_BLE_CM_RESET_AUTO_CONN_DEV,
	        ((dev_addr->nap & 0xff00) >> 8),
			(dev_addr->nap & 0x00ff),
			(dev_addr->uap),
			((dev_addr->lap & 0xff0000) >> 16),
			((dev_addr->lap & 0x00ff00) >> 8),
			(dev_addr->lap & 0x0000ff));

	for (i=0; i<BLE_LINK_NUM; i++)
	{
		if (srv_bt_cm_is_dev_addr_equal(dev_addr, &g_srv_ble_cm_auto_conn_dev[i].bd_addr))
		{
		    g_srv_ble_cm_auto_conn_dev[i].conn_flag = MMI_FALSE;
			for (j = i; j < BLE_LINK_NUM - 1; j++)
			{
				//shift array
				memcpy(&g_srv_ble_cm_auto_conn_dev[j],&g_srv_ble_cm_auto_conn_dev[j+1], sizeof(srv_bt_cm_bt_addr));
			}
			memset(&g_srv_ble_cm_auto_conn_dev[SRV_BLE_CM_MAX_CONNECTED_LIST-1],0,sizeof(srv_bt_cm_bt_addr));
		
			break;
		}
	}
	for (i = 0; i < BLE_LINK_NUM; i++)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_AUTO_CONN_DEV_LIST,
			i,
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.uap),
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_auto_conn_dev[i].bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_auto_conn_dev[i].conn_flag);
    }
     
}

#endif  /* __MMI_BT_SUPPORT__ */
