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
 * BTNotiSrvRecv.h
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
#ifndef __BT_NOTIFICATION_SRV_H__
#define __BT_NOTIFICATION_SRV_H__

#include "MMI_features.h"
#ifdef __MMI_BT_NOTI_SRV__

#include "MMIDataType.h"
#include "SppSrvGprot.h"
#include "fs_gprot.h"  
#include "BTNotiSrvGprot.h"
#include "app_datetime.h"

/* delete all vxp begain */
#include "MREAppMgrSrvGprot.h"
/* delete all vxp end */

/* change device name begain */
#include "BtcmSrvGprot.h"
/* change device name end */

#if defined(__MMI_BT_NOTI_SRV_ENHANCE_BUFFER__)
#define BT_NOTIFY_RECEIVE_BUF_SIZE ((SRV_SPP_MIN_BUFF_SIZE / 2048 + 1) * 1024)
#else
#define BT_NOTIFY_RECEIVE_BUF_SIZE (2048)
#endif

/*a random number to avoid repeate*/
#define BT_NOTIFY_DELETE_ALL_MSG_ID  (-3523442)

typedef enum 
{
    SRV_BT_EXT_EVENT_SPPC_CONNECT_CNF,
    SRV_BT_EXT_EVENT_SPPC_DISCONNECT_CNF,
    SRV_BT_EXT_EVENT_SPPC_READY_TO_READ,
    SRV_BT_EXT_EVENT_SPPC_READY_TO_WRITE, 
    SRV_BT_EXT_EVENT_POST_FSM,
    SRV_BT_EXT_EVENT_NEW_MSG,
    SRV_BT_EXT_EVENT_DEL_MSG,
    SRV_BT_EXT_EVENT_SYNC_DEV,
    SRV_BT_EXT_EVENT_MAP_CONNECT_CNF,
    SRV_BT_EXT_EVENT_MAP_DISCONNECT_CNF,
    SRV_BT_EXT_EVENT_MAP_CMD_NOTIFY,
    SRV_BT_EXT_EVENT_CAP_CMD_NOTIFY,
    SRV_BT_EXT_EVENT_MRE_INSTALL_NOTIFY,
    SRV_BT_EXT_EVENT_SPP_CONNECT_CNF,
    SRV_BT_EXT_EVENT_SPP_DISCONNECT_CNF,
    SRV_BT_EXT_EVENT_SPP_READY_TO_READ,
    SRV_BT_EXT_EVENT_SPP_READY_TO_WRITE,

    SRV_BT_EXT_EVENT_SOGPS_CONNECT_IND,
    SRV_BT_EXT_EVENT_SOGPS_DISCONNECT_IND,
    SRV_BT_EXT_EVENT_SOGPS_READY_TO_READ,
    SRV_BT_EXT_EVENT_SOGPS_READY_TO_WRITE,

    SRV_BT_EXT_EVENT_CONNECTION_STATUS_CHANGE,
    SRV_BT_EXT_EVENT_END
} srv_bt_notify_extrtnal_event_enum;

typedef enum
{
    SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER1,
    SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER2,
    SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER3,
    SRV_BT_NOTI_WAIT_SYNC_CMD_TIMER4,
    SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP1,
    SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP2,
    SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP3,
    SRV_BT_NOTI_RECEIVE_DATA_TIME_GAP4
} srv_bt_notify_external_timer_enum;

U16 srv_bt_noti_get_external_event_id(srv_bt_notify_extrtnal_event_enum type);
U16 srv_bt_noti_get_external_timer_id(srv_bt_notify_external_timer_enum type);

#define BT_NOTIFY_EVT(_type)  srv_bt_noti_get_external_event_id((srv_bt_notify_extrtnal_event_enum)(_type))
#define BT_NOTIFY_TIMER(_type) srv_bt_noti_get_external_timer_id((srv_bt_notify_external_timer_enum)(_type))

/* for BTD v3.0 */
U16 srv_bt_noti_get_wait_sync_cmd_timer_id(U8 cntx_chnl);
U16 srv_bt_noti_get_recv_data_gap_timer_id(U8 cntx_chnl);

#define BT_NOTIFY_WAIT_SYNC_CMD_TIMER(cntx_chnl) srv_bt_noti_get_wait_sync_cmd_timer_id(cntx_chnl)
#define BT_NOTIFY_RECV_DATA_GAP_CMD_TIMER(cntx_chnl) srv_bt_noti_get_recv_data_gap_timer_id(cntx_chnl)

#define BT_NOTIFY_MAX_HEADER_LEN 60
#define BT_NOTIFY_MIN_HEADER_LEN 7     
#define BT_NOTIFY_SYNC_LEN 4                 
#define BT_NOTIFY_ENC_HEADER_LEN 4

#define BT_NOTIFY_MAX_SUPPORTED_REGISTER_COUNT 32

typedef enum
{    
    BT_NOTIFY_STATUS_ENUM_IDLE = 0,         // no available data in recv_buf
    BT_NOTIFY_STATUS_ENUM_READING_CMD,      // reading command 
    BT_NOTIFY_STATUS_ENUM_READING_DATA,     // reading data
    BT_NOTIFY_STATUS_ENUM_PARSING,          // parsing data
    BT_NOTIFY_STATUS_ENUM_READING_EXT_DATA,   // reading data
}bt_notify_status_enum;

typedef enum{    
    BT_NOTIFY_CMD_TYPE_ENUM_INVALID = -1,
    BT_NOTIFY_CMD_TYPE_ENUM_DATA,  // only support this CMD TYPE currently 
    BT_NOTIFY_CMD_TYPE_ENUM_SYNC,
    BT_NOTIFY_CMD_TYPE_ENUM_ACKY,
    BT_NOTIFY_CMD_TYPE_ENUM_ACKN,
    BT_NOTIFY_CMD_TYPE_ENUM_VERN,
    BT_NOTIFY_CMD_TYPE_ENUM_MAPD,
    BT_NOTIFY_CMD_TYPE_ENUM_MAPX,
    BT_NOTIFY_CMD_TYPE_ENUM_CAPC,
    BT_NOTIFY_CMD_TYPE_ENUM_MREE,
    BT_NOTIFY_CMD_TYPE_ENUM_CMD1,  // just reserved 
} bt_notify_cmd_type_enum; // only meaningful when not in IDLE status 

typedef struct
{
    CHAR cmd[5];
    CHAR sender_id[16];
    srv_bt_noti_callback callback;
    MMI_BOOL exist;
} bt_notify_register_callback_struct;

typedef struct
{
    MMI_BOOL is_connect;
    MMI_BOOL is_sync;
    MMI_BOOL is_vern_matched;
    MMI_BOOL connect_fail; 
    MMI_BOOL is_ver_send;
    MMI_BOOL is_wait_timer_started;
    MMI_BOOL is_receiving_timer_started;
    MMI_BOOL is_send_connect_cnf;
    
    bt_notify_status_enum status;
    bt_notify_cmd_type_enum cmd_type;
    MMI_BOOL buffer_to_read;

    S32 conn_id;
    srv_bt_cm_bt_addr bt_addr;
    //srv_bt_notify_data_source_enum source;
    U32 source;
        
#ifdef SRV_BT_NOTIFY_TEST_CLIENT
    SppHandle server_handle;
    SppHandle client_handle;
    S32 client_conn_id;
    U8 client_buf[SRV_SPP_MIN_BUFF_SIZE];
#endif
    
    FS_HANDLE fs_handle;
    WCHAR xml_file_path[BT_NOTIFY_XML_FILE_NAME_LENTH];
    CHAR mre_file_ext[BT_NOTIFY_XML_FILE_NAME_LENTH];
    S32 map_ret_code;
    S32 cap_ret_code;
    U32 xml_file_size;
    U32 xml_file_wrritten_size;
    U32 ext_recv_buf_size;
    U32 total_ext_file_size;
    U32 total_ext_file_recv_size;

    U8 recv_buf[BT_NOTIFY_RECEIVE_BUF_SIZE];    
    S32 recv_buf_len;
    S32 recv_counter;

    S32 cmd_buf_len;
    U8 cmd_buf_plain[BT_NOTIFY_MAX_HEADER_LEN];     
    U8 cmd_buf_encrypt[BT_NOTIFY_MAX_HEADER_LEN];

    U8 send_buf[BT_NOTIFY_RECEIVE_BUF_SIZE]; 

    CHAR cmd[5];
    srv_bt_noti_callback_struct callback_struct;
    bt_notify_register_callback_struct register_callback[BT_NOTIFY_MAX_SUPPORTED_REGISTER_COUNT];

    bt_notify_remote_system_enum remote_system;
} bt_notify_context;

/*for app info*/
typedef struct
{
    char provider[49 + 1];                                        // provider id
    //U32 version;                                         // version   
    CHAR version[16];
    S32 app_id;                                        // app_id
    CHAR app_name[SRV_FMGR_PATH_MAX_LEN + 1];
    //CHAR *app_name;
    U32 app_name_len;
	U32 preinstall;  // 1 instead of can not uninstall
} bt_notify_app_info_struct;
/* for app info*/

void srv_bt_noti_recv_init(void);
void srv_bt_noti_recv_server_init(void);
void srv_bt_noti_recv_client_init(void);

S32 srv_bt_noti_client_hdlr(U32 evt, void* para);

mmi_ret srv_bt_noti_recv_event_handler(mmi_event_struct *param);
void srv_bt_noti_recv_receive_data_fsm(mmi_event_struct *evt);
static void srv_bt_noti_recv_receive_data_fsm_int(U8 cntx_chnl);

MMI_BOOL srv_bt_noti_file_exist(const WCHAR *filename);
MMI_BOOL srv_bt_noti_check_wearable_device_option_enable(void);
MMI_BOOL srv_bt_noti_recv_check_enable_alarm_setting_sync(void);

U16 srv_bt_noti_get_external_event_id(srv_bt_notify_extrtnal_event_enum type);
U16 srv_bt_noti_get_external_timer_id(srv_bt_notify_external_timer_enum type);
U32 srv_bt_noti_get_receiving_data_time_gap(void);
U32 srv_bt_noti_get_sync_time_gap(void);

S16 srv_bt_noti_recv_get_curr_time_zone(void);
MMI_BOOL srv_bt_noti_recv_sync_check_time_zone(S32 time_zone);
U32 srv_bt_noti_recv_get_curr_time(void);
MMI_BOOL srv_bt_noti_recv_check_valid_date(S32 time, applib_time_struct *local_time_out);

void srv_bt_noti_recv_update_time(S32 time, S32 time_zone);
void srv_bt_noti_recv_update_alarm_time(U32 index, U8 weekday, U8 hour, U8 minute);
const char* srv_bt_noti_recv_get_device_infor();
const char* srv_bt_noti_recv_get_version_number();


/* for customer to set the key begain*/
CHAR *srv_bt_get_custom_key(void);
/* for customer to set the key end*/

/* change device name begain*/
s32 srv_bt_noti_recv_set_dev_name(U8 *name);
s32 srv_bt_noti_recv_set_notify(void * callback,void* user_data);
S32 srv_bt_noti_recv_reset_notify(S32 srv_hd);
S32 srv_bt_noti_recv_change_device_name_btcm_callback(U32 event, void* para);
void srv_bt_noti_recv_change_device_name_callback(U32 event, void* para);
/* change device name end*/
void srv_bt_noti_recv_send_device_name(U8 cntx_chnl, const char* device_infor);

MMI_BOOL srv_bt_noti_file_exist(const WCHAR *filename);
MMI_BOOL srv_bt_noti_file_check_integrity(const WCHAR *filename,
                                          U32 *file_size,
                                          U32 expected_file_size);

U64 srv_bt_noti_recv_check_free_space(U8 drv_letter, S32 *ret);
MMI_BOOL srv_bt_noti_send_cmd_ext_by_chnl_num(S32 cntx_chnl, 
                                  const char *cmd, 
                                  const char *data, 
                                  U16 data_len);

S32 srv_bt_noti_find_cntx_channel_by_device_addr_and_source(srv_bt_cm_bt_addr *bt_addr,
                                                                                                                           srv_bt_notify_data_source_enum source);

S32 srv_bt_noti_find_connected_cntx_channel_by_device_addr(srv_bt_cm_bt_addr *bt_addr);

void srv_bt_noti_print_cntx_channel();

S32 srv_bt_noti_get_free_cntx_channel(void);

void srv_bt_noti_recv_release_source(S32 cntx_chnl, srv_bt_notify_data_source_enum source);



/* Uese for receive data gap */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U32 cntx_chnl;                                  /* cntx index */
} srv_bt_noti_recv_data_time_gap_evt_struct;

#endif /*__MMI_BT_NOTI_SRV__*/

#endif/*__BT_NOTIFICATION_SRV_H__*/

