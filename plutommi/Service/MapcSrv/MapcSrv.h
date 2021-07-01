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
 * Btmapc_srv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for bluetooth map client profile and used by any application
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
 *-------------------------------------------------------------------------------------------*/
#ifndef __MAPC_SRV_H__
#define __MAPC_SRV_H__
 
#include "BtcmSrvGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "MapSrvGprot.h"
#include "App_str.h"

#if defined(__BT_MAPC_PROFILE__)
#define __MMI_BT_MAPC_BY_MAP__
#else /*__BT_MAPC_PROFILE__*/
#undef __MMI_BT_MAPC_BY_MAP__
#endif /*__BT_MAPC_PROFILE__*/

#if defined(__MMI_BLE_DOGP_SUPPORT__) && defined(__MMI_BT_NOTI_SRV__)
#define __MMI_BT_MAPC_BY_DOGP__
#else /*__MMI_BLE_DOGP_SUPPORT__*/
#undef __MMI_BT_MAPC_BY_DOGP__
#endif /*__MMI_BLE_DOGP_SUPPORT__*/

#define MMI_MAPC_TRC_CLASS                MMI_CONN_TRC_G7_BT
//#define SRV_BT_MAPC_MAX_SUBJECT_LENGTH    255 
#define MAPC_BY_SPP_WORK_FOLDER           L"z:\\@map\\"
#define MAPC_ROOT_FOLDER                  (L"\telecom")
#define MAPC_ROOT_FOLDER2                 L"\msg"
#define MAPC_ROOT_FOLDER_DEPTH           2

/* max support link */
#if (BT_MAX_LINK_NUM) > 1
#define MAX_MAPC_LINK_SUPPORT                  (BT_MAX_LINK_NUM)
#else
#define MAX_MAPC_LINK_SUPPORT                  (1)
#endif

typedef enum
{
    SRV_MAPC_STATE_INIT,            /* Initial */
    SRV_MAPC_STATE_ACTIVATING,      /* Activating  */
    SRV_MAPC_STATE_ACTIVATED,       /* Activated */
    SRV_MAPC_STATE_DEACTIVATING,    /* Deactivaing */
    SRV_MAPC_STATE_DISCONNECTING,    /* Disconnecting: send request to disconnect and wait for disconnect result */
    SRV_MAPC_STATE_CONNECTING,      /* Connecting: send request to connect and wait for connect result */
    SRV_MAPC_STATE_CONNECTED,       /* Connected */
    SRV_MAPC_STATE_IDLE,
	SRV_MAPC_MNS_STATE_AUTHORIZING,
	SRV_MAPC_MNS_STATE_ABORTING,
	SRV_MAPC_STATE_GETTING_FOLDER,
	SRV_MAPC_STATE_SET_MSG_LISTING_PROPERTY,
	SRV_MAPC_STATE_GETTING_MESSAGE_LISTING,
	SRV_MAPC_STATE_GETTING_MESSAGE,
	SRV_MAPC_STATE_SET_NOTIFY_REGISTRATION,
	SRV_MAPC_STATE_SET_MESSAGE_STATUS,
	SRV_MAPC_STATE_PUSHING_MESSAGE,
	SRV_MAPC_STATE_UPDATING_INBOX,
	SRV_MAPC_STATE_SEND_EVENT_IND,
	SRV_MAPC_MNS_STATE_DISCONNECTING,
} srv_mapc_state_enum;

typedef enum
{
    SRV_MAPC_MNS_STATE_FALSE,            /* Initial */
	SRV_MAPC_MNS_STATE_TRUE,
	SRV_MAPC_MNS_SETTING_TRUE,
	SRV_MAPC_MNS_SETTING_FALSE,
} srv_mapc_mns_enum;


extern void MMI_MAPC_ADP_dump_dev_addr(srv_bt_cm_bt_addr *dev_addr);
void srv_mapc_set_event_hdlr(void);
extern MMI_BOOL srv_bt_cm_get_bqb_test_flag(void);
extern U8 srv_bt_mapc_get_dev_cntx_index(srv_bt_cm_bt_addr *bt_addr, S32 mas_id);
typedef void (*srv_bt_mapc_notify_cb)(S32 srv_hd, srv_bt_mapc_cbevent_enum event, void* para);
typedef void (*srv_bt_cm_map_callback)(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
typedef struct
{
	srv_mapc_state_enum state;
	srv_bt_cm_bt_addr bd_addr;
	srv_bt_cm_bt_addr prev_bd_addr;
	U8 folder_depth;
	S32 mas_id;// conn id from connection manager 
	S32 srv_hd;
	S32 app_id;
	MMI_BOOL mns_support;
	srv_btmapc_folder_flag_enum folder_flag;
	void *user_data;
	srv_bt_mapc_listing_enum get_msg_lst;
	srv_bt_mapc_set_msg_listing_prop_struct msg_lst_prop;
	U8 child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN + 1];
	U8 prev_child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN + 1];
	srv_bt_mapc_notify_cb srv_map_callback;
	srv_bt_cm_map_callback srv_cm_cb;
	srv_mapc_mns_enum mns_registration;
	srv_bt_mapc_connected_enum conn_type;
} srv_map_client_cntx_struct;

#endif 
#endif /*__MAPC_SRV_H__*/
