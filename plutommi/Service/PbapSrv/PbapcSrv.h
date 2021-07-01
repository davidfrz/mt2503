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
 *  PbapcSrv.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  new pbapc srv, support multi links
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __SRV_PBAPC_H__
#define __SRV_PBAPC_H__

#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__

#ifdef __BT_PBAP_CLIENT__ 


/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
/* KAL Layer */
#include "kal_general_types.h"

/* MMI Layer */
#include "MMIDataType.h"
#include "BtcmSrvGprot.h"
#include "PbapSrvGprot.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_conn_app_trc.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "ImeGprotEnums.h"
#include "mmi_frm_queue_gprot.h"
#include "wgui_inputs.h"

/* */
#include "Bluetooth_struct.h"
#include "xml_def.h"
#include "fs_type.h"


#define MMI_PBAPC_AUTH_UI_BUFF_SIZE         (102)   /* "Password Exchange("device_name"):" + NULL = 50*2 + 2 */


typedef enum
{
    SRV_PBAPC_STATE_IDLE = 0,               /* 0 */

    SRV_PBAPC_STATE_ENABLE,                 /* 1 */
    SRV_PBAPC_STATE_OPEN,                   /* 2 */
    SRV_PBAPC_STATE_CONNECTING1,            /* 3 */
    SRV_PBAPC_STATE_AUTHORISE,              /* 4 */
    SRV_PBAPC_STATE_AUTHORIZED,             /* 5 */
    SRV_PBAPC_STATE_CONNECTING2,            /* 6 */
    SRV_PBAPC_STATE_CONNECTED,              /* 7 */
    SRV_PBAPC_STATE_SETTING_PATH,           /* 8 */
    SRV_PBAPC_STATE_SET_PATH,               /* 9 */
    SRV_PBAPC_STATE_READ_FOLDER,            /* 10 */
    SRV_PBAPC_STATE_READ_ENTRY,             /* 11 */
    SRV_PBAPC_STATE_READ_LIST,              /* 12 */
    SRV_PBAPC_STATE_DISCONECTTING,          /* 13 */
    SRV_PBAPC_STATE_DISCONECTED,            /* 14 */
    SRV_PBAPC_STATE_CLOSE,                  /* 15 */

    SRV_PBAPC_STATE_TOTAL
} srv_pbapc_state_enum;

/* pbapc job type enum */
typedef enum
{
    SRV_PBAPC_JOB_NULL = 0,                 /* 0 */

    SRV_PBAPC_JOB_CONNECT,                  /* 1 */
    SRV_PBAPC_JOB_DISCONNECT,               /* 2 */
    SRV_PBAPC_JOB_SET_PATH,                 /* 3 */
    SRV_PBAPC_JOB_READ_LIST,                /* 4 */
    SRV_PBAPC_JOB_READ_FOLDER,              /* 5 */
    SRV_PBAPC_JOB_READ_ENTRY,               /* 6 */

    SRV_PBAPC_JOB_TOTAL
} srv_pbapc_job_enum;

/* invalid cm id */
#define SRV_PBAPC_INVALID_CM_ID         (0x7fffff)


#define SRV_PBAPC_TRACE_GROUP           MMI_CONN_TRC_G7_BT


typedef struct
{
    U8 state;                       /* state */
    U8 path;                        /* cur path */
    /* merge set path */
    srv_pbapc_set_path_req_struct path_req;

    /* 0: unknow; 0x01: support; 0x02: handle used; */
    U8 flag;
    /* map following id with addr */
    U32 goep_conn_id;               /* profile conn id */
    U32 cm_conn_id;                 /* cm srv conn id */
    srv_bt_cm_bt_addr bt_addr;      /* Device Address for connect request */
} srv_pbapc_handle_struct;

/* btd struct */
typedef struct
{
    /* 0: unknow; 0x01: connect; 0x02: used; */
    U8 flag;
    U8 index;
    srv_bt_cm_bt_addr bt_addr;
} srv_pbapc_btd_struct;

/* btd mgr struct */
typedef struct
{
    srv_pbapc_btd_struct btd[SRV_PBAPC_LINK_NUM];
} srv_pbapc_btd_mgr_struct;

/*****************************************************************************
* XML Parse Structure
*****************************************************************************/
typedef struct
{
    U8 num;
    U8 name[SRV_PBAPC_XML_PARSE_NUM][PBAP_MAX_NAME_LEN / 2];
    U16 handle[SRV_PBAPC_XML_PARSE_NUM];
} srv_pbapc_parse_xml_struct;

/* pbapc srv context struct */
typedef struct
{
    U8 cur_state;

    /* bt index */
    U8 bt_index;

    /* auth password if need */
    U8 password[MMI_PBAPC_AUTH_UI_BUFF_SIZE];

    /* parse xml info */
    srv_pbapc_parse_xml_struct xml_info;

    /* pbapc event notify cb function */
    srv_pbapc_callback pbapc_cb_func;           /* now, just for phb srv */

    /* cm app call back function */
    srv_pbapc_cm_callback cm_app_cb;            /* notify cm app */

    /* cur handle */
    srv_pbapc_handle_struct *cur_handle;        /* now, auth use */
    /* cur btd */
    srv_pbapc_btd_struct *cur_btd;

    /* single bt handle */
    srv_pbapc_handle_struct handle[SRV_PBAPC_LINK_NUM];

    /* btd mgr */
    srv_pbapc_btd_mgr_struct *btd_mgr;

    /* query info */
    srv_pbapc_query_func query_func;
    srv_pbapc_query_req_struct query_req;

    S32 cm_handle;
} srv_pbapc_context_struct;


/*XML PARSING Contexts*********************************************************/

#define PBAP_XML_ELEMNT_VCARD                   "card"
#define PBAP_XML_ELEMNT_VCARD_VERSION           "vCard-listing"
#define PBAP_XML_ELEMNT_HANDLE                  "handle"
#define PBAP_XML_ELEMNT_NAME                    "name"


/* function declare */
static void srv_pbapc_cntx_init(void);

static void srv_pbapc_bt_event_notify_handle(U32 event, void* para);

static void srv_pbapc_protocol_init(void);

static srv_pbapc_context_struct *srv_pbapc_get_cntx();

static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_cm_id(U32 cm_id);

static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_goep_id(U32 goep_id);

static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_bt_addr(srv_bt_cm_bt_addr *bt_addr);

static void srv_pbapc_reset_handle(srv_pbapc_handle_struct *pbapc_handle);

static void srv_pbapc_change_state(srv_pbapc_handle_struct *hd, U8 state);

static srv_pbapc_handle_struct *srv_pbapc_get_free_handle();

static void srv_pbapc_get_path(srv_pbapc_path_enum path , kal_int8 *name);

static S32 srv_pbapc_check_para(U8 type, void *para);

static void srv_pbapc_enable_req(void);

static void srv_pbapc_enable_cnf_hdlr(void *ilm_ptr);

static void srv_pbapc_disable_req(void);

static void srv_pbapc_disable_cnf_hdlr(void *ilm_ptr);

S32 srv_pbapc_set_path_req(srv_pbapc_set_path_req_struct *path_req);

static void srv_pbapc_set_path_cnf_hdlr(void *ilm_ptr);

S32 srv_pbapc_read_folder_req(srv_pbapc_read_folder_req_struct *folder_req);

static void srv_pbapc_read_folder_cnf_hdlr(void * ilm_ptr);

S32 srv_pbapc_read_list_req(srv_pbapc_read_list_req_struct *list_req);

static void srv_pbapc_read_list_cnf_hdlr(void * ilm_ptr);

S32 srv_pbapc_read_entry_req(srv_pbapc_read_entry_req_struct *entry_req);

static void srv_pbapc_read_entry_cnf_hdlr(void * ilm_ptr);

static void srv_pbapc_abort_req(U32 goep_id);

static void srv_pbapc_abort_ind_hdlr(void *ilm_ptr);

static void srv_pbapc_abort_cnf_hdlr(void *ilm_ptr);

static void srv_pbapc_connect_req(srv_bt_cm_bt_addr *bt_addr);

static void srv_pbapc_connect_cnf_hdlr(void *ilm_ptr);

static void srv_pbapc_disconnect_from_cm_id(U32 cm_id);

static void srv_pbapc_disconnect_req(U32 goep_id);

static void srv_pbapc_disconnect_cnf_hdlr(void * ilm_ptr);

static void srv_pbapc_disconnect_ind_hdlr(void * ilm_ptr);

static void srv_pbapc_auth_ind_hdlr(void *ilm_ptr);

static void srv_pbapc_auth_rsp(S32 flag);

static void srv_pbapc_send_msg(U32 msg_id, void *local_para);

static void mmi_pbapc_authentication_confirm_hdlr(void);

static MMI_BOOL mmi_pbapc_entry_authentication_confirm(mmi_scenario_id scen_id, void *arg);

static void mmi_pbapc_entry_authentication_confirm_scr(void);

static mmi_ret mmi_pbapc_entry_authentication_confirm_proc(mmi_event_struct *evt);

static mmi_ret mmi_pbapc_entry_authentication_confirm_scr_proc(mmi_event_struct *evt);

static void mmi_pbapc_auth_send(void);

static void mmi_pbapc_auth_reject(void);

static void mmi_pbapc_auth_input_validation_func(U8 *text, U8 *cursor, S32 length);

void srv_pbapc_start_read_data(U8 bt_index);

static S32 srv_pbapc_parse_xml_file(U16 *filename);

static void srv_pbapc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error);

static U32 srv_pbapc_string_to_hex(char *s);

static void srv_pbapc_xml_start_element_hdlr(void *data, const char *el,const char **attr, int error);

static void srv_pbapc_xml_end_element_hdlr(void *data, const char *el, int error);

static srv_pbapc_btd_struct *srv_pbapc_get_btd_from_bt_addr(srv_bt_cm_bt_addr *bt_addr, U8 flag);

static void srv_pbapc_btd_push(srv_bt_cm_bt_addr *bt_addr);

void srv_pbapc_bqb_abort_req();

#endif /* __BT_PBAP_CLIENT__ */

#endif /* __MMI_BT_SUPPORT__ */

#endif /* __SRV_PBAPC_H__ */ 

