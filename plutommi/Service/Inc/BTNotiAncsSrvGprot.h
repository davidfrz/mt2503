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
*  BTNotiAncsGprot.h
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   ANCS service header File
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#ifndef SRV_NOTI_ANCS_GPROT_H
#define SRV_NOTI_ANCS_GPROT_H

#include "MMI_features.h"
#ifdef __MMI_BLE_ANCS_SUPPORT__
#include "MMIDataType.h"
#include "custom_mmi_default_value.h" // MYTIME

// for device
#define SRV_ANCS_MAX_DEV         __BT_MAX_LE_LINK_NUM__
#define SRV_ANCS_MAX_MEMOEY (3*1024)

// for notification source
#define SRV_ANCS_MAX_NOTI_SOURCE (SRV_ANCS_MAX_NOTI_NUM + 1)     //the first item is head
#define SRV_ANCS_MAX_NOTI_VALUE (8)

// for control point

// for data source
#define SRV_ANCS_MAX_NOTI_NUM (1)  //  the number of notifications, same as the number of notification attribute
#define SRV_ANCS_MAX_APP_ATTRIBUTE_NUM (6)  //the number of app attribute
// attr:
#define SRV_ANCS_ATTR_LIST_COUNT (6)
#define SRV_ANCS_APP_ID_MAX_LEN (50)
#define SRV_ANCS_TITILE_MAX_LEN (40)
#define SRV_ANCS_SUB_TITILE_MAX_LEN (30)
#define SRV_ANCS_MSG_MAX_LEN (300)
#define SRV_ANCS_MSG_SIZE_LEN (4)
#define SRV_ANCS_DATA_MAX_LEN (30)
// app:
#define SRV_ANCS_APP_LIST_COUNT (2)
#define SRV_ANCS_APP_DISPLAY_NAME (30)

/* Indication opcode enum */
typedef enum
{
    SRV_ANCS_TYPE_ADDED = 0, /*  srv_ancs_noti_ind_struct */
    SRV_ANCS_TYPE_MODIFIED = 1, /*  */
    SRV_ANCS_TYPE_REMOVED = 2,
    SRV_ANCS_TYPE_CONNECTED = 3,
    SRV_ANCS_TYPE_DISCONNECTED = 4,
    SRV_ANCS_TYPE_TOTAL /* Total enum number */
}srv_ancs_noti_type_enum;

/* Category ID value enum */
typedef enum
{
    SRV_ANCS_CAT_OTHER = 0, /*  categoryIDother = 0 */
    SRV_ANCS_CAT_INCOMING_CALL = 1, /*  categoryIDIncomingCall = 1*/
    SRV_ANCS_CAT_MISSED_CALL = 2, /* categoryIDMissedCall = 2*/
    SRV_ANCS_CAT_VOICE_MAIL = 3, /* categoryIDVoicemail = 3 */
    SRV_ANCS_CAT_SOCIAL = 4, /* categoryIDsocial = 4 */
    SRV_ANCS_CAT_SCHEDULE = 5, /* categoryIDSchedule = 5 */
    SRV_ANCS_CAT_EMAIL = 6, /* categoryIDEmail = 6*/
    SRV_ANCS_CAT_NEWS = 7, /* categoryIDNews = 7*/
    SRV_ANCS_CAT_HEALTH_FITNESS = 8, /* categoryIDHeathAndFitness = 8 */
    SRV_ANCS_CAT_BUSINESS_FINANCE = 9, /* categoryIDBusinessAndFinance = 9 */
    SRV_ANCS_CAT_LOCATION = 10,/* categoryIDLocation = 10 */
    SRV_ANCS_CAT_ENTERTAINMENT = 11, /* categoryIDEntertainment = 11 */
    SRV_ANCS_CAT_UNDEFINE = 12, /* Reserved Category ID value = 12 - 255*/
    SRV_ANCS_CAT_TOTAL /* Total enum number */
} srv_ancs_category_enum;

/* Event Flag value enum */
typedef enum
{
    SRV_ANCS_EVTFG_NONE = 0x00,
    SRV_ANCS_EVTFG_SILENT = 0x01, /* 1 << 0*/
    SRV_ANCS_EVTFG_IMPORTANT = 0x02, /* 1 << 1*/
    SRV_ANCS_EVTFG_UNDEFINE, /* Reserved EventFlags (1 << 2) - (1 << 7) */
    SRV_ANCS_EVTFG_TOTAL
} srv_ancs_evt_flags_enum;

typedef enum
{
    SRV_ANCS_ATTR_NONE = 0x00,
    SRV_ANCS_ATTR_BASE = 0x01,
    SRV_ANCS_ATTR_APP_ID = 0x02,
    SRV_ANCS_ATTR_TITLE = 0x04,
    SRV_ANCS_ATTR_SUB_TITLE = 0x08,
    SRV_ANCS_ATTR_MSG = 0x10,
    SRV_ANCS_ATTR_MSG_SIZE = 0x20,
    SRV_ANCS_ATTR_DATE = 0x40,
    SRV_ANCS_ATTR_APP_NAME = 0x200,
    SRV_ANCS_ATTR_TOTAL
    // TODO: ATTR_MSG_SIZE ?
} srv_ancs_attr_flags_enum;

/* query type */
typedef enum
{
    SRV_ANCS_GET_BY_NONE = 0,
    SRV_ANCS_GET_BY_HD = 1, /*  srv_ancs_noti_ind_struct */
    SRV_ANCS_GET_BY_ADDR = 2, /*  */
    SRV_ANCS_GET_BY_CONN_ID = 3,
    SRV_ANCS_GET_TYPE_TOTAL /* Total enum number */
}srv_ancs_query_type_enum;

typedef struct
{
    U8  event_id;
    U8  event_flags;
    U8  category_id;
    U8  category_count;
    S32 noti_uid;
}srv_ancs_nsrc_struct;

typedef struct
{
    MMI_BOOL alloc;
	U8 next;
    srv_ancs_nsrc_struct data;
}srv_ancs_noti_src_info_struct;

typedef struct
{
    U8    attr_id;
    U16   attr_len;
    U8*   attr_ptr;
} srv_ancs_attr_node_struct;

typedef struct
{
    U8 alloc;   //the number of app who use this app id
    U32 app_id_len;
    U8  app_id[SRV_ANCS_APP_ID_MAX_LEN + 1];
    srv_ancs_attr_node_struct attr_list[SRV_ANCS_APP_LIST_COUNT];
}srv_ancs_app_attr_struct;

typedef struct
{
    MMI_BOOL alloc;
    U32 noti_uid;
    srv_ancs_attr_node_struct attr_list[SRV_ANCS_ATTR_LIST_COUNT];
}srv_ancs_noti_attr_struct;

typedef struct
{
    U8   cmd_id;
    S32  noti_id;
    U8   attr_id;
    U16  max_attr_title;
    U16  max_attr_subtitle;
    U16  max_attr_msg;
}srv_ancs_src_get_attr_cmd_req;

typedef struct
{
    U8* app_id;
    U8 app_attr_id;
    U32 id_len;
}srv_ancs_src_get_app_attr_req;

/* new notification indication struct */
typedef srv_ancs_nsrc_struct srv_ancs_noti_ind_struct;

/* event structure for EVT_ID_SRV_ANCS_NOTI */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ancs_noti_type_enum ind_type; /* Indication type */
    void *ptr; /* Data pointer */
} srv_ancs_ind_evt_struct;

typedef struct
{
    S32 noti_id;
    srv_ancs_noti_type_enum noti_type;
    srv_ancs_category_enum cat_id;
    srv_ancs_evt_flags_enum evt_flag;
    U8 cat_count;
    BD_ADDR bd_addr;
    U32 attr_flags;
    U8 app_id[SRV_ANCS_APP_ID_MAX_LEN+1];
    U16 title[SRV_ANCS_TITILE_MAX_LEN+1];
    U16 sub_title[SRV_ANCS_SUB_TITILE_MAX_LEN+1];
    U16 msg[SRV_ANCS_MSG_MAX_LEN+1];
    MYTIME date;
    U16 app_name[SRV_ANCS_APP_DISPLAY_NAME+1];
} srv_ancs_noti_info_struct;

extern void srv_ancs_init(void);
extern U8 srv_ancs_ut_handle(U8 index, kal_uint8* string);
extern MMI_BOOL srv_ancs_query_notification_info(srv_ancs_noti_info_struct* noti_info, S32 noti_id, srv_ancs_query_type_enum type, S32* para);
extern U32 srv_ancs_query_notification_count(S32 nid_list[], srv_ancs_query_type_enum type, S32* para);
extern MMI_BOOL srv_ancs_is_connected(srv_ancs_query_type_enum type, S32* para);
extern MMI_BOOL srv_ancs_delete_notification(S32 nid, srv_ancs_query_type_enum type, S32* para);
#endif /* __MMI_BLE_ANCS_SUPPORT__ */
#endif /* SRV_NOTI_ANCS_GPROT_H */

