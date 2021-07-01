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
 * btnotisrvgprot.h
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
#ifndef __BT_NOTI_SRV_DATA_GPROT_H__
#define __BT_NOTI_SRV_DATA_GPROT_H__

#include "MMI_features.h"
#ifdef __MMI_BT_NOTI_SRV__

#include "MMIDataType.h"
#include "fs_gprot.h"
#include "custom_btnotification_config.h"
#include "custom_btcm_config.h"
#include "bluetooth_struct.h"

#define __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
#define __BT_NOTI_SRV_MEM_DEBUG__

#define BT_NOTI_SRV_DATA_SMS_APP_ID  (-2)
#define BT_NOTI_SRV_DATA_MISSCALL_APP_ID  (-3)

#define BT_NOTIFY_SENDER_LENTH              50
#define BT_NOTIFY_NUMBER_LENTH              20
#define BT_NOTIFY_CONTENT_LENTH             300         /* remote device limitation is 256 */
#define BT_NOTIFY_SEND_SMS_CONTENT_LENTH    512
#define BT_NOTIFY_ICON_FILE_NAME_LENTH      80
#define BT_NOTIFY_MAX_ICON_LENGTH           2560
#define BT_NOTIFY_XML_FILE_NAME_LENTH       80
#define BT_NOTIFY_TITLE_LENTH               30
#define BT_NOTIFY_TICKER_TEXT_LENTH         150

/*actions related*/
#define BT_NOTIFY_ACTION_MAX_NUM            5
#define BT_NOTIFY_ACTION_NAME_LENTH         20
#define BT_NOTIFY_ACTION_ICON_MAX_LEN       2048
#define BT_NOTIFY_ACTION_ID_LENTH           20
#define BT_NOTIFY_ACTION_ICON_PATH_LEN      200

/*page releated*/
#define BT_NOTIFY_PAGE_MAX_NUM              3

/*group releated*/
#define BT_NOTIFY_GROUP_MAX_LENGTH         30
#define BT_NOTIFY_MAX_GROUP_NUM            SRV_BT_NOTI_MSG_LIST_MAX_NUM

#define BT_NOTIFY_RECEIVING_DATA_TIME_GAP   (100)       /* receiving data time gap ms, 
                                                           for receive near two notification,
                                                           millisecond, must be positive number */

#define BT_NOTIFY_SYNC_TIME_GAP             (5)         /* sync device allowed to do when time gap big than 5 seconds. */


#define BT_NOTIFY_MRE_FILE_NAME_LENTH BT_NOTIFY_XML_FILE_NAME_LENTH

#ifdef __MMI_SPP_SUPPORT__
    #define __MMI_BT_NOTI_SRV_ENHANCE_BUFFER__
#endif

#if defined(__MMI_BT_NOTI_SRV_ENHANCE_BUFFER__)
#define BT_NOTIFY_MRE_MAX_DATA_LENTH (8 * 1024 - 50)
#else
#define BT_NOTIFY_MRE_MAX_DATA_LENTH (2047 - 50)
#endif

//#define BT_NOTIFY_MAX_CHANNEL                  (BT_PROFILES_LINK_NUM) /* One Target and one Controller */
#define BT_NOTIFY_MAX_CHANNEL                  (2) /* One Target and one Controller */
#define BT_NOTIFY_MAX_SYNCED_CHANNEL    (2)

#define __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__

#ifdef __MTK_TARGET__
#define BT_NOTIFY_ROOT_FOLDER               L"z:\\@BTNotify\\"
#define BT_NOTIFY_MAP_ROOT_FOLDER           L"z:\\@map\\"
#define BT_NOTIFY_CAP_ROOT_FOLDER           L"z:\\@cap\\"
#define BT_NOTIFY_MRE_ROOT_FOLDER           L"z:\\@BTMre\\"
#define BT_NOTIFY_MRE_INSTALLED_FOLDER      L"installed\\"
//temp for fimware
#define BT_NOTIFY_FIRMWARE_FILE             L"mt6261_patch_e1_hdr.bin"
#else
#define BT_NOTIFY_ROOT_FOLDER               L"C:\\@BTNotify\\"
#define BT_NOTIFY_MAP_ROOT_FOLDER           L"C:\\@map\\"
#define BT_NOTIFY_CAP_ROOT_FOLDER           L"C:\\@cap\\"
#define BT_NOTIFY_MRE_ROOT_FOLDER           L"C:\\@BTMre\\"
#define BT_NOTIFY_MRE_INSTALLED_FOLDER      L"installed\\"
//temp for fimware
#define BT_NOTIFY_FIRMWARE_FILE             L"mt6261_patch_e1_hdr.bin"

#endif

/* mre callback data type */
typedef enum
{
    SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER = 0,
    SRV_BT_NOTI_MRE_DATA_TYPE_FILE
} srv_bt_noti_mre_data_type_enum;

/* for mre installer */
typedef enum
{
    SRV_BT_NOTI_MRE_INSTALL_START,
    SRV_BT_NOTI_MRE_INSTALL_FAIL,
    SRV_BT_NOTI_MRE_INSTALL_SUCCESS,
    SRV_BT_NOTI_MRE_UNINSTALL_FAIL,
    SRV_BT_NOTI_MRE_UNINSTALL_SUCCESS
} srv_bt_noti_mre_install_uninstall_result_enum;

/* notification category enum */
typedef enum {
    srv_bt_notify_category_none,                /* none category */
    srv_bt_notify_category_noti,                /* notification category */
    srv_bt_notify_category_call,                /* call category */
    srv_bt_notify_category_map                  /* map category */
} srv_bt_notify_category_enum;

/* notification subtype enum */
typedef enum {
    srv_bt_notify_subtype_text,                 /* for category noti text subtype */
    srv_bt_notify_subtype_sms,                  /* for category noti sms subtype */
    srv_bt_notify_subtype_block_sender,         /* for category noti block sender subtype */
    srv_bt_notify_subtype_missed_call,           /* for category call */
    srv_bt_notify_subtype_action_operate,        /*for action operate*/
    srv_bt_notify_subtype_noti_delete                /*for delete the remote notification*/
} srv_bt_notify_subtype_enum;

/* notification action enum */
typedef enum {
    srv_bt_notify_action_add,                   /* add action */
    srv_bt_notify_action_delete,                /* delete action */
    srv_bt_notify_action_delete_all,            /* delete all action */
    srv_bt_notify_action_update                 /* update action */
} srv_bt_notify_opeate_enum;

/* refresh reason enum */
typedef enum {
    srv_bt_notify_refresh_reason_from_app,                   /* add action */
    srv_bt_notify_refresh_reason_from_service,                /* delete action */
} srv_bt_notify_refresh_reason_enum;


/* refresh type enum */
typedef enum 
{
    SRV_BT_NOTIFY_REFRESH_NEW,                  /* refresh new */
    SRV_BT_NOTIFY_REFRESH_DEL,                   /* refresh del */
    SRV_BT_NOTIFY_REFRESH_UPDATE
} srv_bt_notify_refresh_type;

/* ret code */
typedef enum
{
    SRV_BT_NOTIFY_RET_NO_ERROR = 0,
    SRV_BT_NOTIFY_RET_UNKNOWN_ERROR = -1000,    /* unknown error */
    SRV_BT_NOTIFY_RET_FILE_NOT_EXIST,           /* file not exist */
    SRV_BT_NOTIFY_RET_FILE_INTEGRITY_ERROR,     /* file length error */
    SRV_BT_NOTIFY_RET_LINK_DISCONNECTED,
    SRV_BT_NOTIFY_RET_MRE_PARSE_PARA_ERROR,
    SRV_BT_NOTIFY_RET_PARSE_PARA_ERROR,
    SRV_BT_NOTIFY_RET_MAP_FILE_PARSE_PARA_ERROR,
} srv_bt_notify_ret_code;

/* map file ext type */
typedef enum
{
    SRV_BT_NOTIFY_MAP_INVALID_FILE_TYPE = -1,
    SRV_BT_NOTIFY_MAP_XML_FILE_TYPE,
    SRV_BT_NOTIFY_MAP_VCF_FILE_TYPE
} srv_bt_map_file_ext_type;

/* register callback return code enum */
typedef enum
{  
    SRV_BT_NOTIFY_DATA_SOURCE_UNKNOWN = 0x00,
    SRV_BT_NOTIFY_DATA_SOURCE_SPP = 0x01,
    SRV_BT_NOTIFY_DATA_SOURCE_DOGP = 0x02,    
    SRV_BT_NOTIFY_DATA_SOURCE_ANCS = 0x04,
} srv_bt_notify_data_source_enum;

/* register callback return code enum */
typedef enum
{  
    SRV_BT_NOTIFY_REGISTER_RET_INVALID_PARAMETER = -4,
    SRV_BT_NOTIFY_REGISTER_RET_SYSTEM_REGISTERED,
    SRV_BT_NOTIFY_REGISTER_RET_REPEAT_REGISTER,
    SRV_BT_NOTIFY_REGISTER_RET_NOT_IMPLEMENT,
    SRV_BT_NOTIFY_REGISTER_RET_OK,
} srv_bt_notify_register_result_enum;

/* mre callback struct */
typedef struct
{
    CHAR sender_id[16];                         /* sender id for FP */
    CHAR receiver_id[16];                       /* receiver id for SP */
    S32 err_code;                               /* error code */
    srv_bt_noti_mre_data_type_enum  data_type;  /* data type, 0 for buffer, 1 for file */
    
    union
    {
        WCHAR file_path[BT_NOTIFY_MRE_FILE_NAME_LENTH];
        struct
        {
            U8  data[BT_NOTIFY_MRE_MAX_DATA_LENTH];
            U16 len;
        } buffer;
    } data;

    srv_bt_cm_bt_addr bt_addr;
} srv_bt_noti_mre_callback_struct;

typedef srv_bt_noti_mre_callback_struct srv_bt_noti_callback_struct;

/* notification header struct */
typedef struct 
{
    srv_bt_notify_category_enum category;       /* notification category */
    srv_bt_notify_subtype_enum subtype;         /* notification subtype */
    srv_bt_notify_opeate_enum action;           /* notification action */
    U32 msg_id;                                 /* notification msg id */  
} srv_bt_notify_header_struct;


typedef enum
{
    BT_NOTIFY_REMOTE_SYSTEM_NONE,
    BT_NOTIFY_REMOTE_SYSTEM_ANDROID,
    BT_NOTIFY_REMOTE_SYSTEM_IOS
}bt_notify_remote_system_enum;



/* Uese for notifying missed call count to calllog */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    U32 missed_call_count;                  /* missed call count */
    U32 timestamp;                             /* timestamp  */
    WCHAR send_number[BT_NOTIFY_NUMBER_LENTH];            /* send_number */
    WCHAR sender[BT_NOTIFY_SENDER_LENTH];                       /* sender */
} srv_bt_noti_missed_call_evt_struct;

/* Uese for notifying new sms to message */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    WCHAR sender[BT_NOTIFY_SENDER_LENTH];
    WCHAR send_number[BT_NOTIFY_NUMBER_LENTH];
    WCHAR content[BT_NOTIFY_CONTENT_LENTH]; 
    U32 timestamp;
} srv_bt_noti_new_sms_evt_struct;


/* Event information data. For each event's event infomation structure, 
  *refer the discription of each event in enum srv_sms_event_enum. */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    void *event_info;
} srv_bt_noti_event_struct;

/* The bt notification sync with remote device operation complete callback */
typedef void (*srv_bt_noti_sync_device_callback)(srv_bt_cm_bt_addr *bt_addr, S32 time, S32 time_zone, MMI_BOOL need_sync);

/* The bt notification callback mre engine */
typedef void (*srv_bt_noti_mre_callback)(void *data);
typedef srv_bt_noti_mre_callback srv_bt_noti_callback;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    S32 time;                                               /* time in second */
    S32 time_zone;                                          /* time zone in millisecond */
    srv_bt_noti_sync_device_callback call_back;             /* Sync callback */
} srv_bt_noti_sync_event_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    U32 len;
    S32 ret_code;
    S32 cmd_type;
    MMI_BOOL ret_is_num;  
} srv_bt_noti_map_event_notify_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    U32 len;
    S32 ret_code;
    S32 cmd_type;
    MMI_BOOL ret_is_num;  
} srv_bt_noti_cap_event_notify_struct;

/* for mre installer */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    srv_bt_noti_mre_install_uninstall_result_enum ret_code;
    srv_bt_notify_ret_code err_code;
} srv_bt_noti_mre_install_event_notify_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL is_connected;
    bt_notify_remote_system_enum remote_system;
} srv_bt_noti_map_connectivity_notify_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER

} srv_bt_noti_update_time_notify_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL is_connected;
    bt_notify_remote_system_enum remote_system;
} srv_bt_noti_connect_status_change_notify_struct;

/*notification action info*/
typedef struct
{
    WCHAR action_id[BT_NOTIFY_ACTION_ID_LENTH];
    WCHAR action_name[BT_NOTIFY_ACTION_NAME_LENTH + 3];
#ifdef __MMI_BT_NOTI_ACTION_ICON__
    WCHAR action_icon_path[BT_NOTIFY_ACTION_ICON_PATH_LEN];
#endif
}srv_bt_noti_action_struct;

typedef struct page_struct
{
    WCHAR content[BT_NOTIFY_CONTENT_LENTH];//modify
    WCHAR title[BT_NOTIFY_TITLE_LENTH];//modify
    struct page_struct *next;
}srv_bt_noti_page_content_struct;


typedef struct 
{
    U32 node_index;   
    U32 chnnl_num;
}srv_bt_noti_data_listmgr_node_struct;



typedef struct 
{
    U8 group_id[BT_NOTIFY_GROUP_MAX_LENGTH];
    U32 app_id;
    WCHAR sender[BT_NOTIFY_SENDER_LENTH];
    U32 noti_num;
    srv_bt_noti_data_listmgr_node_struct noti_index[SRV_BT_NOTI_MSG_LIST_MAX_NUM];
    U32 latest_timestamp;
}srv_bt_noti_data_group_list_struct;



typedef struct
{
    U8 icon_buffer[BT_NOTIFY_MAX_ICON_LENGTH];
    U32 icon_size;
}srv_bt_noti_data_icon_struct;


/* The data msg node struct */
typedef struct 
{
    srv_bt_notify_header_struct header;                     /* notification header */    
    WCHAR sender[BT_NOTIFY_SENDER_LENTH];                   /* for notification: app name, for sms: contact name or number */
    WCHAR send_number[BT_NOTIFY_NUMBER_LENTH];              /* for sms only, contact number */
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    S32 page_num;
    srv_bt_noti_page_content_struct *page_content;
    U8 group_id[BT_NOTIFY_GROUP_MAX_LENGTH];
    U32 action_num;
    srv_bt_noti_action_struct noti_action[BT_NOTIFY_ACTION_MAX_NUM];   /*notification action*/
    MMI_BOOL is_blocked;
#else
    WCHAR content[BT_NOTIFY_CONTENT_LENTH];                 /* notification content */
    WCHAR title[BT_NOTIFY_TITLE_LENTH];                     /* notification title */
    WCHAR ticker_text[BT_NOTIFY_TICKER_TEXT_LENTH];         /* notification ticker text */ 
#endif
    U32 missed_call_count;                                  /* only for missed call subtype */
    U32 timestamp;                                          /* notification timestamp */
    U32 app_id;                                             /* app id */   
#ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    srv_bt_noti_data_icon_struct *icon;
#else
    WCHAR icon_file_path[BT_NOTIFY_ICON_FILE_NAME_LENTH];   /* icon file path */
#endif
    WCHAR xml_file_path[BT_NOTIFY_XML_FILE_NAME_LENTH];     /* xml file path */
    
    
    MMI_BOOL is_read;

    U32 noti_id;
    srv_bt_notify_data_source_enum source;
    U32 ANCS_msg_id;
    srv_bt_cm_bt_addr bt_addr;
    U32 chnnl_num;
} srv_bt_noti_data_msg_node_struct;

/* new notification event info */
typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    WCHAR *xml_file_path;                       /* xml file path */
    srv_bt_notify_header_struct *header;        /* notification header struct */
} srv_bt_noti_event_info_new;


/* delete notification event info */
typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    S32 del_msg_id;                             /* delete msg id, valid for source != SRV_BT_NOTIFY_DATA_SOURCE_DEFAULT cases */

    srv_bt_notify_data_source_enum source;
    U32 ANCS_id;                                 /* ANCS msg id, valid for source == SRV_BT_NOTIFY_DATA_SOURCE_DEFAULT cases */
} srv_bt_noti_event_info_del;

/* add notification event info, for source != SRV_BT_NOTIFY_DATA_SOURCE_DEFAULT cases */
typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    srv_bt_noti_data_msg_node_struct msg_info;
} srv_bt_noti_event_info_add;

/* connected event info, for source != SRV_BT_NOTIFY_DATA_SOURCE_DEFAULT cases */
typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    srv_bt_notify_data_source_enum source;
} srv_bt_noti_event_info_connceted;


typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    srv_bt_notify_data_source_enum source;
} srv_bt_noti_event_info_disconnceted;



/* Uese for notifying missed call count to calllog */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_bt_cm_bt_addr bt_addr;
    srv_bt_notify_refresh_type refresh_type;    /* refresh type */
    U32 index;                                  /* refresh notification index */
    U32 noti_id;
    srv_bt_notify_refresh_reason_enum refresh_reason;
    MMI_BOOL is_listmgr;
} srv_bt_noti_refresh_evt_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_num
 * DESCRIPTION
 *  This function is to get total msg number.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  S32
 *****************************************************************************/
extern U32 srv_bt_noti_data_get_msg_num(srv_bt_cm_bt_addr *bt_addr);



#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_group_num
 * DESCRIPTION
 *  This function is to get total group number.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  S32
 *****************************************************************************/
extern U32 srv_bt_noti_data_get_group_num(srv_bt_cm_bt_addr *bt_addr);


extern U32 srv_bt_noti_data_listmgr_get_msg_num();



/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_group_list
 * DESCRIPTION
 *  This function is to get  group list.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  S32
 *****************************************************************************/
extern srv_bt_noti_data_group_list_struct* srv_bt_noti_data_get_group_info_ref(srv_bt_cm_bt_addr *bt_addr, U32 index);

srv_bt_noti_data_group_list_struct  *srv_bt_noti_data_listmgr_get_group_info_ref(U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_info_ref_in_group
 * DESCRIPTION
 *  This function is to get msg info reference.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 *  node_ref        :       [OUT] node ref
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

MMI_BOOL srv_bt_noti_data_get_msg_info_ref_in_group(S32 cntx_chnl, 
                                           U32 index_in_group, 
                                           srv_bt_noti_data_msg_node_struct *node_ref);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_info_ref_in_group
 * DESCRIPTION
 *  This function is to get msg info reference.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 * RETURNS
 *  srv_bt_noti_data_msg_node_struct *
 *****************************************************************************/
srv_bt_noti_data_msg_node_struct *srv_bt_noti_data_get_msg_info_in_group(S32 cntx_chnl, U32 index_in_group);



/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_idx_by_group
 * DESCRIPTION
 *  This function is to get msg index by group id.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  group_id        :       [IN] group id
 *  index             :       [OUT] the message index
 * RETURNS
 *  S32              :        index num
 *****************************************************************************/

extern void srv_bt_noti_data_delete_msg_by_group(srv_bt_cm_bt_addr *bt_addr, U32 index);

extern void srv_bt_noti_data_listmgr_delete_msg_by_group(U32 index);



/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_action_operate
 * DESCRIPTION
 *  This function is to send action operation to remote device
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  noti_id     :       [IN] the notification id
 *  action_id         :       [IN] the action id
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

extern MMI_BOOL srv_bt_noti_action_operate(srv_bt_cm_bt_addr *bt_addr, U32 msg_id, WCHAR *action_id);

extern MMI_BOOL srv_bt_noti_data_listmgr_action_operate(U32 index, WCHAR *action_id);



/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_action_operate
 * DESCRIPTION
 *  This function is to send action operation to remote device
 * PARAMETERS
 *  app_id         :       [IN] bt device address
 *  group_id     :       [IN] the group id
 *  index         :       [out] the group index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

extern srv_bt_noti_data_group_list_struct *srv_bt_noti_data_listmgr_get_group_info_ref_by_id(S32 app_id, U8 *group_id, U32 *index);


#endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_get_format_bt_device_addr
 * DESCRIPTION
 *  This function is to get bt device format address from context channel
 * PARAMETERS
 *  bt_addr             :           [IN] bt address
 *  out_bt_addr         :           [OUT] output bt address
 *  buf_len             :           [IN] output buffer size
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_get_format_bt_device_addr(srv_bt_cm_bt_addr *bt_addr, CHAR* out_bt_addr, U32 buf_len);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_create_folder
 * DESCRIPTION
 *  This function is to create dest folder
 * PARAMETERS
 *  folder_path             :           [IN] to create folder path
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_noti_create_folder(WCHAR *folder_path);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_info
 * DESCRIPTION
 *  This function is to get msg info through msg index.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 * RETURNS
 *  srv_bt_noti_data_msg_node_struct*
 *****************************************************************************/
extern srv_bt_noti_data_msg_node_struct *srv_bt_noti_data_get_msg_info(srv_bt_cm_bt_addr *bt_addr, U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_set_read_status
 * DESCRIPTION
 *  This function is to set the read status of one msg.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :        [IN] msg index
 *  is_read        :        [IN] read status to be set
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 MMI_BOOL srv_bt_noti_data_set_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index, MMI_BOOL is_read);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_read_status
 * DESCRIPTION
 *  This function is to get the read status of one msg.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :        [IN] msg index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 MMI_BOOL srv_bt_noti_data_get_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_set_all_as_read
 * DESCRIPTION
 *  This function is to set the read status of one msg.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 MMI_BOOL srv_bt_noti_data_set_all_as_read(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_info_ref
 * DESCRIPTION
 *  This function is to get msg info reference.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 *  node_ref        :       [OUT] node ref
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_data_get_msg_info_ref(srv_bt_cm_bt_addr *bt_addr, 
                                                  U32 index, 
                                                  srv_bt_noti_data_msg_node_struct *node_ref);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_delete_msg
 * DESCRIPTION
 *  This function is to delete specified msg through msg index.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_noti_data_delete_msg(srv_bt_cm_bt_addr *bt_addr, U32 index);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_delete_all
 * DESCRIPTION
 *  This function is to delete all msgs.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_noti_data_delete_all(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_msg_index_by_msg_id
 * DESCRIPTION
 *  This function is to get msg index through msg id
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  msg_id          :       [IN] msg id
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_bt_noti_data_get_msg_index_by_msg_id(srv_bt_cm_bt_addr *bt_addr, U32 msg_id);

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
U32 srv_bt_noti_data_listmgr_get_msg_num();
MMI_BOOL srv_bt_noti_data_listmgr_get_msg_info_ref(U32 index, 
                                           srv_bt_noti_data_msg_node_struct *node_ref);
MMI_BOOL srv_bt_noti_data_listmgr_get_msg_info_ref_by_id(U32 noti_id, 
                                           srv_bt_noti_data_msg_node_struct *node_ref);
S32 srv_bt_noti_data_listmgr_get_latest_unread_noti_id();

MMI_BOOL srv_bt_noti_data_listmgr_set_read_status(U32 noti_id, MMI_BOOL is_read);
MMI_BOOL srv_bt_noti_data_listmgr_set_all_as_read();
U32 srv_bt_noti_data_listmgr_get_unread_num();
MMI_BOOL srv_bt_noti_data_listmgr_get_read_status(U32 noti_id);
void srv_bt_noti_data_listmgr_delete_msg(U32 noti_id);
void srv_bt_noti_data_listmgr_delete_all();
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_reply_remote_sms
 * DESCRIPTION
 *  This function is to reply sms to remote device through spp, it will return result when send operation done.
 *  it does not care remote device when to send the reply sms or the sent status.
 *  NOTE: content must be ended with '\0' and the strlen must be smaller than BT_NOTIFY_SEND_SMS_CONTENT_LENTH
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  send_number     :       [IN] send number
 *  content         :       [IN] sms content, must be ended with '\0' and the strlen must be 
 *                               smaller than BT_NOTIFY_SEND_SMS_CONTENT_LENTH
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_data_reply_remote_sms(srv_bt_cm_bt_addr *bt_addr, WCHAR *send_number, WCHAR *content);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_block_remote_notification
 * DESCRIPTION
 *  This function is to send data to remote device through spp to notify it block the specified
 *  notification by app id, it will return result when send operation done.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  app_id          :       [IN] app id of notification
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_data_block_remote_notification(srv_bt_cm_bt_addr *bt_addr, U32 app_id);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_update_remote_missed_call
 * DESCRIPTION
 *  This function is to send data to remote device though spp to notify remote device 
 *  to clear the missed call count, it will return result when send operation done.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  void
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_update_remote_missed_call(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_send_xml
 * DESCRIPTION
 *  This function is to send xml file to remote device though spp, and return result when
 *  send operation done.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  xml_file        :       [IN] xml file path
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_send_xml(srv_bt_cm_bt_addr *bt_addr, const WCHAR *xml_file);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_send_file_with_prefix_command
 * DESCRIPTION
 *  This function is to send file to remote device though spp, and return result when
 *  send operation done.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device add  
 *  file_path       :       [IN] file path
 *  prefix_command  :       [IN] prefix command sync with remote device, ended with '\0'
 *  data            :       [IN] user data
 *  data_len        :       [IN] user data len
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_send_file_with_prefix_command(srv_bt_cm_bt_addr *bt_addr,
                                                          const WCHAR *file_path,
                                                          const char *prefix_command,
                                                          const char *data,
                                                          U16   data_len);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_send_cmd
 * DESCRIPTION
 *  This function is to send cmd to remote device though spp, and return result when
 *  send operation done.
 * PARAMETERS
 *  bt_addr     :       [IN] bt device address
 *  cmd         :       [IN] command string, ended with '\0'
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_send_cmd(srv_bt_cm_bt_addr *bt_addr, const char *cmd);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_send_cmd_ext
 * DESCRIPTION
 *  This function is to send cmd to remote device though spp, and return result when
 *  send operation done.
 * PARAMETERS
 *  bt_addr     :       [IN] bt device address
 *  cmd         :       [IN] command string, ended with '\0'
 *  data        :       [IN] user data string
 *  data_len    :       [IN] user data string length
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_send_cmd_ext(srv_bt_cm_bt_addr *bt_addr, 
                                         const char *cmd, 
                                         const char *data, 
                                         U16 data_len);

extern MMI_BOOL srv_bt_noti_send_cmd_ext_by_source(srv_bt_cm_bt_addr *bt_addr, 
                                  srv_bt_notify_data_source_enum source,
                                  const char *cmd, 
                                  const char *data, 
                                  U16 data_len);

extern U8 srv_bt_noti_get_connection_number(void);
extern U8 srv_bt_noti_get_sync_connection_number(void);

extern srv_bt_cm_bt_addr* srv_bt_noti_get_bt_device_addr_by_conn_index(U8 conn_index);

extern srv_bt_notify_data_source_enum srv_bt_noti_recv_get_source(S32 cntx_chnl );
void srv_bt_noti_recv_set_source(S32 cntx_chnl, srv_bt_notify_data_source_enum source, srv_bt_cm_bt_addr *bt_addr);
void srv_bt_noti_recv_print_format_bt_addr(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_connection
 * DESCRIPTION
 *  This function is to check connect status with remote device, if connected, will return 
 *  MMI_TRUE, then local device can receive data from remote device
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_check_connection(void);

extern MMI_BOOL srv_bt_noti_check_sync_connection(void);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_vern
 * DESCRIPTION
 *  This function is to check connected remote device APK version, if matched, will return 
 *  MMI_TRUE, then local device can receive data from remote device
 * PARAMETERS
 *  srv_bt_cm_bt_addr *
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/

extern MMI_BOOL srv_bt_noti_check_vern(srv_bt_cm_bt_addr *bt_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_connection_ext
 * DESCRIPTION
 *  This function is to check connect status with remote device, if connected, will return 
 *  MMI_TRUE, then local device can receive data from remote device
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_check_connection_ext(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_get_remote_system
 * DESCRIPTION
 *  This function is to get remote device system
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 * RETURNS
 *  bt_notify_remote_system_enum
 *  BT_NOTIFY_REMOTE_SYSTEM_NONE: connect fail or cannot get remote system
 *  BT_NOTIFY_REMOTE_SYSTEM_ANDROID
 *  BT_NOTIFY_REMOTE_SYSTEM_IOS
 *****************************************************************************/

bt_notify_remote_system_enum srv_bt_noti_get_remote_system(srv_bt_cm_bt_addr *bt_addr);


MMI_BOOL srv_bt_noti_check_sync_connection_ext_by_source(srv_bt_cm_bt_addr *bt_addr,
                                                                                                    srv_bt_notify_data_source_enum source);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_connect_fail
 * DESCRIPTION
 *  This function is to check connect status with remote device, if failed, will return 
 *  MMI_TRUE, then local device can not send and receive data with remote device
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_check_connect_fail(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_sync
 * DESCRIPTION
 *  This function is check sync state, if has sync with remote device, then it will return 
 *  MMI_TRUE, and local device can send data to remote device
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_check_sync(srv_bt_cm_bt_addr *bt_addr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_find_cntx_channel_by_device_addr
 * DESCRIPTION
 *  This function is to find context channel from device address
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 * RETURNS
 *  S32
 *****************************************************************************/
extern S32 srv_bt_noti_find_cntx_channel_by_device_addr(srv_bt_cm_bt_addr *bt_addr);

extern S32 srv_bt_noti_find_synced_cntx_channel_by_device_addr(srv_bt_cm_bt_addr *bt_addr);

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_check_channel_valid
 * DESCRIPTION
 *  This function is to check validation context channel
 * PARAMETERS
 *  cntx_chnl         :           [IN] channel index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_check_channel_valid(S32 cntx_chnl);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_get_bt_device_addr
 * DESCRIPTION
 *  This function is to get bt device address from context channel
 * PARAMETERS
 *  cntx_chnl         :           [IN] channel index
 * RETURNS
 *  srv_bt_cm_bt_addr*
 *****************************************************************************/
extern srv_bt_cm_bt_addr* srv_bt_noti_get_bt_device_addr(U8 cntx_chnl);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_register_mre_callback
 * DESCRIPTION
 *  This function is to register mre callback,
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 *  cb_ptr          :           [IN] mre callback
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_bt_noti_register_mre_callback(srv_bt_cm_bt_addr *bt_addr, srv_bt_noti_mre_callback cb_ptr);


/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_register_callback
 * DESCRIPTION
 *  This function is to register callback,
 * PARAMETERS
 *  bt_addr      :     [IN] bt device address
 *  cmd          :     [IN] command, must be 4 bytes length string, ex: "EXCD"
 *  sender       :     [IN] sender, app identifier, maximized 16 bytes length string, ex: "remotecapture"
 *  cb_ptr       :     [IN] mre callback
 * RETURNS
 *  srv_bt_notify_register_result_enum
 *
 * Usage:
 *
 * 1.receive data:
 * (1) define callback function to process command data:
 *     void xxx_callback_hdlr(void *data);
 *
 * (2) call register function:
 *     srv_bt_notify_register_result_enum ret = srv_bt_noti_register_callback("EXCD", "remotecapture", xxx_callback_hdlr);
 *     if (SRV_BT_NOTIFY_REGISTER_RET_OK != ret)
 *     {
 *         error process;
 *     }
 * 
 * (3) when new data arrived, notification srv will call app, app can handle as follow:
 *     SP sending data format:
 *        "cmd sender receiver err_code data_type data_len data"
 *     Just received some data from SP as below:
 *        "EXCD remotecapture xxx_apk 0 0 8 launch 1"
 *
 *     App can process data in callback function:
 *     void xxx_callback_hdlr(void *data)
 *     {
 *         srv_bt_noti_callback_struct *p_data = (srv_bt_noti_callback_struct*)data;
 *
 *         //p_data->sender_id:        remotecapture
 *         //p_data->receiver_id:      xxx_apk
 *         //p_data->err_code:         0
 *         //p_data->data_type:        0, means buffer
 *         //p_data->data.buffer.data: "launch 1"
 *         //p_data->data.buffer.len:  8
 *
 *         if (NULL == p_data)
 *         {
 *             return;
 *         }
 *
 *         // data format is buffer
 *         if (SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER == p_data->data_type)
 *         {
 *             U8 *buf = p_data->data.buffer.data;
 *             U16 len = p_data->data.buffer.len;
 *             process code;
 *         }
 *         // data format is file
 *         else if (SRV_BT_NOTI_MRE_DATA_TYPE_FILE == p_data->data_type)
 *         {
 *             WCHAR *path = p_data->data.buffer.file_path;
 *             process code;
 *         }
 *     }
 *
 * 2.send data:
 *      send data format: "cmd sender receiver data_type data_len data"
 *   ex: 
 *      "EXCD remotecapture xxx_apk 0 6 launch"
 *   send data ex:
 *      MMI_BOOL ret;
 *      ret = srv_bt_noti_send_cmd_ext("EXCD", "remotecapture xxx_apk 0 6 launch", strlen("remotecapture xxx_apk 0 6 launch"));
 *      if (MMI_FALSE == ret)
 *      {
 *          error process;
 *          reason:
 *            (1) SPP connect fail
 *            (2) sync fail with SP
 *      }
 *****************************************************************************/
extern srv_bt_notify_register_result_enum srv_bt_noti_register_callback(srv_bt_cm_bt_addr *bt_addr, CHAR *cmd, CHAR *sender, srv_bt_noti_callback cb_ptr);

extern srv_bt_notify_register_result_enum srv_bt_noti_register_callback_ext( 
                                                                 CHAR *cmd, 
                                                                 CHAR *sender, 
                                                                 srv_bt_noti_callback cb_ptr);



/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_deregister_callback
 * DESCRIPTION
 *  This function is to deregister callback,
 * PARAMETERS
 *  bt_addr         :           [IN] bt device address
 *  cb_ptr          :           [IN] srv_bt_noti_callback cb_ptr
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
extern MMI_BOOL srv_bt_noti_deregister_callback(srv_bt_cm_bt_addr *bt_addr, srv_bt_noti_callback cb_ptr);

extern void srv_bt_notify_itoa(kal_char *buf, U32 i, kal_int32 base);



#endif/*__MMI_BT_NOTI_SRV__*/

#endif/*__BT_NOTI_SRV_DATA_GPROT_H__*/

