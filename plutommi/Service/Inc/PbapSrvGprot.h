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
 *  PhoneBookPBAP.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  phonebook access profile
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __SRV_PBAP_GPROT_H__
#define __SRV_PBAP_GPROT_H__

#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__
#if defined(__MMI_PBAP_SUPPORT__) 

#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "bluetooth_pbap_struct.h"

/*max device name, the name is display on when authorize ind received*/
#define MAX_DEV_NAME  80

/*pbap service return result, it indicates the service can use*/
#define SRV_PBAP_RESULT_OK            0

/*pbap service return result, it indicates the service currently can not used*/
#define SRV_PBAP_RESULT_INVALID_HANDLE  -1

/*pbap service return result, it indicates user set the parameter not right*/
#define SRV_PBAP_RESULT_INVALID_PARAMETERS        -2

/*pbap service return result, it indicates service currently is busy*/
#define SRV_PBAP_RESULT_BUSY        -3

/*pbap service event: if want to know pbap register message, it should care this event*/
#define SRV_PBAP_EVENT_START    0x0001

/*pbap service event: if want to know pbap deregister message, it should care this event*/
#define SRV_PBAP_EVENT_STOP    0x0002

/*pbap service event: if want to know pbap authorize message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHORIZE_NOTIFY  0x0004

/*pbap service event: if want to know pbap authentication message, it should care this event*/
#define SRV_PBAP_EVENT_AUTHENTICATION_NOTIFY    0x0008

/*pbap service event: if want to know pbap connect message, it should care this event*/
#define SRV_PBAP_EVENT_CONN_NOTIFY   0x0010

/*pbap service event: if want to know pbap disconnect message, it should care this event*/
#define SRV_PBAP_EVENT_DISCONN_NOTIFY   0x0020

/*****************************************************************************
 *  authorize struct, when service received opposite authorize_ind, will use this struct
 *  to notify mmi
 *    conn_id:  it indicates this authorize process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;                    /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;      /* bt address, it indicate which device want to connect pbap*/
    U8 dev_name[MAX_DEV_NAME];      /* server UI used, if not paired device, ui use the it */
} srv_pbap_auth_notify_struct;

/*****************************************************************************
 *  connect struct, pbap client to connect pbap server, server will received connect_ind
 *    conn_id:  it indicates this process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;                    /* cm conn_id, UI use it to notify cm */
    srv_bt_cm_bt_addr bt_addr;        /*server UI used to notify cm, */
    U8 dev_name[MAX_DEV_NAME]; /* server UI used, if not paired device, ui use the it */
} srv_pbap_conn_notify_struct;

/*****************************************************************************
 *  disconnect struct, pbap client or server want to disconnect the connection, 
 *  after connection disconnected, will received disconnect_ind, and use it to notify mmi
 *    conn_id:  it indicates this authorize process connect id, it is sole
 *    bt_addr:  it indicates the opposite device bt address
 *
*****************************************************************************/
typedef struct
{
    U32 conn_id;        /*cm conn_id, UI use it to notify cm*/
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL disconnect_from_cm;
}srv_pbap_disconn_notify_struct;

/*****************************************************************************
 *  authentication struct, BT stack want to challenge the device, will use this struct
 *  to notify 
 *    dev_name: it indicates the opposite device name, if modified to nickname, will use it
 *
*****************************************************************************/
typedef struct
{
    U8 dev_name[MAX_DEV_NAME]; /* utf8 encoding */ 
} srv_pbap_authentication_notify_struct;

/*****************************************************************************
 *  notify callback, when service happened some event,and will use the callback
 *  to notify the user who care the events
 *    srv_hd:  [in] it indicates who register the callback, it is sole
 *    event: [in] it indicates the app care what event
 *    para: [in] if mmi does not want to record some data, it can send to service,
 *               when service finished one event, will give the data to mmi also.
 *
*****************************************************************************/
typedef S32(*bt_notify) (S32 srv_hd, U32 event, void *para);

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_init
 * DESCRIPTION
 *  init pbap service, it will initialize variable
 * PARAMETERS
 *  vaoid      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_init(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deinit
 * DESCRIPTION
 *  deinit pbap, when bt power off, will deinit it
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_open
 * DESCRIPTION
 *  open a pbap service
 * PARAMETERS
 *  void      : 
 * RETURNS
 *  srv_hd : return a hanlder to record who open the pbap
 *****************************************************************************/
extern S32 srv_pbap_open(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_close
 * DESCRIPTION
 *  close pbap service
 * PARAMETERS
 *  srv_hd      : [IN] which want to close pbap
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_close(S32 srv_hd);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_set_notify
 * DESCRIPTION
 *  mmi set owner callback and event to service
 * PARAMETERS
 *  srv_hd      : [IN]record who use the pbap
 *  event_mask  : [IN] MMI care the event
 *  notifier    : [IN] MMI register callback
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern S32 srv_pbap_set_notify(S32 srv_hd, U32 event_mask, bt_notify notifier);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_activate
 * DESCRIPTION
 *  activate the pbap server
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32         : service current result
 *****************************************************************************/
extern void srv_pbap_activate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_deactivate
 * DESCRIPTION
 *  deactivate the pbap, if deactive, pbab server will not be used
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern void srv_pbap_deactivate(void);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_disconnect_client
 * DESCRIPTION
 *  pbap server disconnect client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 *  conn_id     : [IN] pbap server disconnect client
 * RETURNS
 *  void
 *****************************************************************************/
extern void srv_pbap_disconnect_client(U32 conn_id);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_accept_conn
 * DESCRIPTION
 *  pbap server accept connection from pbap client
 * PARAMETERS
 *  app_id      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_pbap_accept_conn(S32 srv_hd, U8 *password);

/*****************************************************************************
 * FUNCTION
 *  srv_pbap_reject_conn
 * DESCRIPTION
 *  pbap server reject connection from pbap client
 * PARAMETERS
 *  srv_hd      : [IN] record who use the pbap
 * RETURNS
 *  S32        : service current result
 *****************************************************************************/
extern S32 srv_pbap_reject_conn(S32 srv_hd);

#ifdef __cplusplus
}
#endif


#endif /* defined(__MMI_PBAP_SUPPORT__) */

#ifdef __BT_PBAP_CLIENT__

#define PCE_DEFINED

#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "bluetooth_pbapc_struct.h"

/* max support link */
#if (BT_MAX_LINK_NUM) > 1
#define SRV_PBAPC_LINK_NUM                  (BT_MAX_LINK_NUM)
#else
#define SRV_PBAPC_LINK_NUM                  (1)
#endif

/* max parse xml data num */
#define SRV_PBAPC_XML_PARSE_NUM             (20)

/* bt index */
typedef U8 SRV_PBAPC_BT_INDEX;

/* invalid bt index */
#define SRV_PBAPC_INVALID_BT_INDEX          (0xff)

/*****************Response Event Ids***********************/
typedef enum
{
    EVT_ID_PBAPC_CONNECT_RSP = 0,       /* 0 */

    EVT_ID_PBAPC_DISCONNECT_RSP,        /* 1 */
    EVT_ID_PBAPC_READ_FOLDER_RSP,       /* 2 */
    EVT_ID_PBAPC_READ_LIST_RSP,         /* 3 */
    EVT_ID_PBAPC_READ_ENTRY_RSP,        /* 4 */
    EVT_ID_PBAPC_SET_PATH_RSP,          /* 5 */
    EVT_ID_PBAPC_DISCONNECT_IND,        /* 6 */
    EVT_ID_PBAPC_ENABLE_RSP,            /* 7 */
    EVT_ID_PBAPC_DISABLE_RSP,           /* 8 */
    EVT_ID_PBAPC_ABORT_IND,             /* 9 */
    EVT_ID_PBAPC_ABORT_RSP,             /* 10 */
    EVT_ID_PBAPC_AUTH_CHALLENGE_IND,    /* 11 */
    EVT_ID_PBAPC_READ_DATA_RSP,         /* 12 */
    EVT_ID_PBAPC_DEL_BTD,               /* 13 */

    EVT_ID_PBAPC_TOTAL
} srv_pbapc_event_enum;

/* flag */
#define SRV_PBAPC_FLAG_SUPPORT              (0x01)
#define SRV_PBAPC_FLAG_CONNECTED            (0x01)
#define SRV_PBAPC_FLAG_NEW_BTD              (0x04)
/* comm flag */
#define SRV_PBAPC_FLAG_USED                 (0x02)

#define SRV_PBAPC_FLAG_ALL                  (0xff)


/* pbapc btd enum */
typedef enum
{
    SRV_PBAPC_BTD_1ST = 0,

    SRV_PBAPC_BTD_2ND,
    SRV_PBAPC_BTD_3RD,
    SRV_PBAPC_BTD_4TH,
    SRV_PBAPC_BTD_5TH,
    SRV_PBAPC_BTD_6TH,

    SRV_PBAPC_BTD_TOTAL
} srv_pbapc_btd_enum;

/* Response Structures */
typedef struct
{
    MMI_EVT_PARAM_HEADER

    srv_pbapc_event_enum type;
    SRV_PBAPC_BT_INDEX bt_index;
    void *data;
} srv_pbapc_notify_event_struct ;

/* del btd struct */
typedef struct
{
    SRV_PBAPC_BT_INDEX bt_index;
} srv_pbapc_del_btd_struct;

/* connect rsp struct */
typedef struct
{
    S32 ret;
    MMI_BOOL new_btd;
} srv_pbapc_connect_rsp_struct;

/* connect ind struct */
typedef struct
{
    S32 ret;
} srv_pbapc_connect_ind_struct;

/* disconnect rsp struct */
typedef struct 
{
    S32 ret;
} srv_pbapc_disconnect_rsp_struct;

/* disconnect ind struct */
typedef struct
{
    S32 ret;
} srv_pbapc_disconnect_ind_struct;

/* set path req struct */
typedef struct
{
    pbap_set_folder_type_enum folder_type;
    U8 path;                                /* srv_pbapc_path_enum path */
    SRV_PBAPC_BT_INDEX bt_index;
} srv_pbapc_set_path_req_struct ;

/* set path rsp struct */
typedef struct
{
    S32 ret;
} srv_pbapc_set_path_rsp_struct ;

/* read entry req struct */
typedef struct 
{
    PbapVcardFormat format;
    PbapVcardFilter filter;
    U16 *name;               /* object name PBAP_MAX_NAME_LEN / 2 + 1 */
    SRV_PBAPC_BT_INDEX bt_index;
} srv_pbapc_read_entry_req_struct;

/* read entry rsp struct */
typedef struct 
{
    S32 ret;
} srv_pbapc_read_entry_rsp_struct;

/* read folder rsp struct */
typedef struct
{
    PbapVcardFormat format;
    PbapVcardFilter filter;
    U16 count;
    U16 offset;
    U16 *name;              /* folder name PBAP_MAX_NAME_LEN / 2 + 1 */
    SRV_PBAPC_BT_INDEX bt_index;
} srv_pbapc_read_folder_req_struct;

/* read folder rsp struct */
typedef struct
{
    S32  ret;
    U16 phoneBookSize;      //0xffff indicates have only data
    U16 newMissedCalls;     //0xffff means type is not MCH
} srv_pbapc_read_folder_rsp_struct;

/* read list req struct */
typedef struct
{
    U8 order;
    U8 length;
    U8 attribute;
    U16 count;
    U16 offset;
    U16 *name;           /* folder name PBAP_MAX_NAME_LEN / 2 + 1 */
    U8 *value;
    SRV_PBAPC_BT_INDEX bt_index;
} srv_pbapc_read_list_req_struct;

/* read list rsp struct */
typedef struct
{
    S32 ret;
    U16 phoneBookSize;      //0xffff indicates have only data
    U16 newMissedCalls;     //0xffff means type is not MCH
} srv_pbapc_read_list_rsp_struct;

/* parse list data rsp struct */
typedef struct
{
    S32 more;                                               // 1 for moredata from PBAP SRV, 0 for no more data
    S32 num;                                        //No. of useful entries in the handle and name array
    U16 handle[SRV_PBAPC_XML_PARSE_NUM];                        //List of handles on remote device
    U8 name[SRV_PBAPC_XML_PARSE_NUM][PBAP_MAX_NAME_LEN / 2];    //list of names ,name is mapped one to one for handle
} srv_pbapc_list_data_rsp_struct;


/**********  Filters for PCE *****************/

typedef U8 PbapVcardFilterBit;

#define PBAP_VCARD_FILTER_VER       0        /* Version (Bit 0) */
#define PBAP_VCARD_FILTER_FN        1        /* Formatted Name (Bit 1) */
#define PBAP_VCARD_FILTER_N         2        /* Structured Presentation of Name (Bit 2) */
#define PBAP_VCARD_FILTER_PHOTO     3        /* Associated Image or Photo (Bit 3) */
#define PBAP_VCARD_FILTER_BDAY      4        /* Birthday (Bit 4) */
#define PBAP_VCARD_FILTER_ADR       5        /* Delivery Address (Bit 5) */
#define PBAP_VCARD_FILTER_LABEL     6        /* Delivery (Bit 6) */
#define PBAP_VCARD_FILTER_TEL       7        /* Telephone (Bit 7) */
#define PBAP_VCARD_FILTER_EMAIL     8        /* Electronic Mail Address (Bit 8) */
#define PBAP_VCARD_FILTER_MAILER    9        /* Electronic Mail (Bit 9) */
#define PBAP_VCARD_FILTER_TZ        10       /* Time Zone (Bit 10) */
#define PBAP_VCARD_FILTER_GEO       11       /* Geographic Position (Bit 11) */
#define PBAP_VCARD_FILTER_TITLE     12       /* Job (Bit 12) */
#define PBAP_VCARD_FILTER_ROLE      13       /* Role within the Organization (Bit 13) */
#define PBAP_VCARD_FILTER_LOGO      14       /* Organization Logo (Bit 14) */
#define PBAP_VCARD_FILTER_AGENT     15       /* vCard of Person Representing (Bit 15) */
#define PBAP_VCARD_FILTER_ORG       16       /* Name of Organization (Bit 16) */
#define PBAP_VCARD_FILTER_NOTE      17       /* Comments (Bit 17) */
#define PBAP_VCARD_FILTER_REV       18       /* Revision (Bit 18) */
#define PBAP_VCARD_FILTER_SOUND     19       /* Pronunciation of Name (Bit 19) */
#define PBAP_VCARD_FILTER_URL       20       /* Uniform Resource Locator (Bit 20) */
#define PBAP_VCARD_FILTER_UID       21       /* Unique ID (Bit 21) */
#define PBAP_VCARD_FILTER_KEY       22       /* Public Encryption Key (Bit 22) */
#define PBAP_VCARD_FILTER_NICK      23       /* Nickname (Bit 23) */
#define PBAP_VCARD_FILTER_CAT       24       /* Categories (Bit 24) */
#define PBAP_VCARD_FILTER_PRODID    25       /* Product Id (Bit 25) */
#define PBAP_VCARD_FILTER_CLASS     26       /* Class Information (Bit 26) */
#define PBAP_VCARD_FILTER_SORT_STR  27       /* Sort string (Bit 27) */
#define PBAP_VCARD_FILTER_TIMESTAMP 28       /* Time stamp (Bit 28) */
/* Bits 29-38 Reserved for future use */
#define PBAP_VCARD_FILTER_PROP      39       /* Use of a proprietary filter (Bit 39) */
/* Bits 40-63 Reserved for proprietary filter usage */


/************  Path for PSE *********/
typedef enum
{
    PBAPC_PATH_INVALID,
    PBAPC_PATH_ROOT = 1,

    PBAPC_PATH_PHONEBOOK,          /* Phone Phonebook path is used */
    PBAPC_PATH_INCOMING,           /* Phone Incoming call path is used */
    PBAPC_PATH_OUTGOING,           /* Phone  Outgoing call path is used */
    PBAPC_PATH_MISSED,             /* Phone  Missed call path is used */
    PBAPC_PATH_COMBINED,           /* Phone  Combined call path is used */
    PBAPC_PATH_PB_TELECOM ,        /* Phone Telecom  path is used */
    PBAPC_PATH_SIM_PHONEBOOK,      /* SIM  Phonebook path is used */
    PBAPC_PATH_SIM_INCOMING,       /* SIM  Incoming call  path is used */       
    PBAPC_PATH_SIM_OUTGOING,       /* SIM Outgoing call path is used */
    PBAPC_PATH_SIM_MISSED,         /* SIM Missed call path is used */
    PBAPC_PATH_SIM_COMBINED,       /* SIM Combined call path is used */
    PBAPC_PATH_SIM_TELECOM,        /* SIM Telecom call path is used */
    PBAPC_PATH_TELECOM,            /* Should not be used by PHB  SRV */
    PBAPC_PATH_SIM,                /* Should not be used by PHB  SRV */

    PBAPC_PATH_TOTAL               /* Should not be used by PHB  SRV */
} srv_pbapc_path_enum;

/* Result code used in most APIs, should be zero or negative number */
typedef enum
{
    SRV_PBAPC_RET_OK                    = 0,

    SRV_PBAPC_RET_FAIL                  = -1,
    SRV_PBAPC_RET_CONNECTED             = -2,
    SRV_PBAPC_RET_DISCONECTTING         = -3,
    SRV_PBAPC_RET_DISCONNECTED          = -4,
    SRV_PBAPC_RET_FORBID_CONNECT        = -5,

    SRV_PBAPC_RET_TATAL                 = -100
} srv_pbapc_ret_enum;


typedef struct
{
    S32 bt_index; /* configure bt index for bt addr */
} srv_pbapc_query_req_struct;


/* event notify func (now just for phb srv) */
typedef S32 (* srv_pbapc_callback)(srv_pbapc_notify_event_struct *evt);

typedef S32 (* srv_pbapc_query_func)(srv_pbapc_query_req_struct *req);

typedef  void (*srv_pbapc_cm_callback)(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result, MMI_BOOL is_connect, MMI_BOOL is_indicate);

/*srv pbapc init */
extern void srv_pbapc_init();


/* srv pbapc deinit */
extern void srv_pbapc_deinit();

/* connect */
extern S32 srv_pbapc_connect(srv_bt_cm_bt_addr *bt_addr, srv_pbapc_cm_callback cm_cb);

/* disconnect */
extern S32 srv_pbapc_disconnect(srv_bt_cm_bt_addr *bt_addr, srv_pbapc_cm_callback cm_cb);

/* Read a Vcard from remote device ****/
extern S32 srv_pbapc_read_entry_req(srv_pbapc_read_entry_req_struct *entry_req);


/* Sets working path on remote device ***/
extern S32 srv_pbapc_set_path_req(srv_pbapc_set_path_req_struct *path_req);


/* Reads list of vcard entries for a given path from remote device ****/
extern S32 srv_pbapc_read_list_req(srv_pbapc_read_list_req_struct *list_req);


/* Reads complete folder for a given path from remote device ***/
extern S32 srv_pbapc_read_folder_req(srv_pbapc_read_folder_req_struct *folder_req);


/* start parse xml ***/
extern void srv_pbapc_start_read_data(U8 bt_index);


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_btd_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_pbapc_get_btd_addr(srv_bt_cm_bt_addr *bt_addr, U8 bt_index);


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_btd_index
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_pbapc_get_btd_index(srv_bt_cm_bt_addr *bt_addr, U8 flag);


/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_query_func
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_pbapc_set_query_func(srv_pbapc_query_func query_func);


/*****************************************************************************
* FUNCTION
*  srv_pbapc_is_connect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern MMI_BOOL srv_pbapc_is_connect(U8 bt_index);

#endif /*__BT_PBAP_CLIENT__*/

#endif /* __MMI_BT_SUPPORT__ */

#endif 

