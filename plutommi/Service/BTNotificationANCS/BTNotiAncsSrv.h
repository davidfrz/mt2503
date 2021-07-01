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
*  BTNotiAncsSrv.h
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

#ifndef SRV_NOTI_ANCS_PROT_H
#define SRV_NOTI_ANCS_PROT_H

#include "MMI_features.h"
#ifdef __MMI_BLE_ANCS_SUPPORT__
#include "MMIDatatype.h"
#include "GattSrv.h"
#include "Btostypes.h"
#include "BTNotiAncsSrvGprot.h"
#include "GattCSrv.h"
#include "custom_btcm_config.h"


#define SRV_ANCS_CTRL_POINT_MAX_ATTR_ID_COUNT 256
#define SRV_ANCS_CTRL_POINT_MAX_LEN_PARA 6

#define SRV_ANCS_CTRL_POINT_MAX_BUFF_LEN (SRV_ANCS_CTRL_POINT_MAX_ATTR_ID_COUNT+SRV_ANCS_CTRL_POINT_MAX_LEN_PARA) // byte

#define SRV_ANCS_MAX_CHAR 3

#define SRV_ANCS_DES_VALUE_LEN 4

#define SRV_ANCS_DSRC_BUFF_SIZE 15

#define __MMI_ANCS_MAX_QUEUE__

#ifdef __MMI_ANCS_MAX_QUEUE__
#define SRV_ANCS_MAX_QUEUE_COUNT 30
#endif /* __MMI_ANCS_MAX_QUEUE__ */


#ifdef __MMI_BLE_LOW_POWER__
#define SRV_ANCS_RESET_INT_TIME 15000
#endif /* __MMI_BLE_LOW_POWER__ */

typedef enum {
    GET_IDLE,
    GET_SERVICE,
    GET_CHAR,
    REG_NOTI,
    GET_DESCR,
    READ_DESCR,
    WRITE_DESCR,
    WRITE_DONE,
    GET_STATE_NUM
} srv_ancs_get_state_enum;

typedef enum {
    CUT_NONE = 0,
    CUT_CID_END = 1,
    CUT_NID = 2,
    CUT_NID_END = 3,
    CUT_ATT = 4,
    CUT_ATT_LEN = 5,
    CUT_ATT_LEND = 6,
    CUT_ATT_VAL = 7,
    CUT_ATT_VALD = 8, //valid end
    CUT_APP_ID = 9,
    CUT_APP_IDD = 10
} srv_ancs_cut_type_enum;

typedef enum
{
    ANCS_TYPE_UNKNOW = 0,
    ANCS_TYPE_SERVICE,
    ANCS_TYPE_CHARACTERISTIC,
    ANCS_TYPE_DESCRIPTOR,
    ANCS_TYPE_INCLUDE_SRV,
} srv_ancs_delc_type_enum;

typedef enum
{
    ANCS_QUERY_TYPE_CHAR = 0,
    ANCS_QUERY_TYPE_UUID,
    ANCS_QUERY_TYPE_TOTAL
} srv_ancs_char_query_type_enum;

typedef enum
{
    ANCS_UUID_PRI_SRV = 0, // primary service
    ANCS_UUID_NOTI_SRC, // notification source
    ANCS_UUID_CTRL_PTR, // control point
    ANCS_UUID_DATA_SRC, // data source
    ANCS_UUID_TOTAL,
} srv_ancs_uuid_enum;

typedef enum
{
    ANCS_UUID_STR_LEN_128 = 32,
    ANCS_UUID_STR_LEN_16 = 8,
    ANCS_UUID_STR_LEN_2 = 4
} srv_ancs_uuid_len_enum;

typedef struct
{
    srv_ancs_delc_type_enum    type;
    U8*                           uuid;
    BT_UUID                       bt_uuid;
}srv_ancs_decl_struct;

typedef struct
{
    void* reg_ctx;
    bt_uuid_struct app_uuid;
} srv_ancs_reg_struct;


typedef struct
{
    MMI_BOOL      valid;
    GATT_SVC_UUID uuid;
} srv_ancs_service_info_struct;

typedef struct _srv_ancs_nsrc_node_struct
{
    U32 delay_time; // for some notifications, like Email, if get it too quickly, IOS will return "This message has no content"
    srv_ancs_nsrc_struct data;
    struct _srv_ancs_nsrc_node_struct* prev;
    struct _srv_ancs_nsrc_node_struct* next;
} srv_ancs_nsrc_node_struct;

typedef struct
{
    MMI_BOOL               valid;
    MMI_BOOL               registered;
    MMI_BOOL               descriptor;
    MMI_BOOL               des_writed;
    U8                     des_len;
    srv_ancs_uuid_enum  type;
    ATT_UUID               char_uuid;
    ATT_UUID               descr_uuid;
    U8                     des_value[SRV_ANCS_DES_VALUE_LEN];
} srv_ancs_char_info_struct;

typedef struct
{
    U8        ctrl_pt_attr_id;
    U8*       cut_ptr;
    U32       cut_left_len;
    S32       srv_hd;
    BD_ADDR   bd_addr;
    void*     conn_ctx;
    srv_ancs_attr_node_struct*      pending_attr;
    srv_ancs_noti_attr_struct*   pending_noti_info_p;
    srv_ancs_app_attr_struct*    pending_app_info_p;
    srv_ancs_nsrc_node_struct*   pending_noti_node_p;
    srv_ancs_cut_type_enum       cut_type;
    srv_ancs_get_state_enum      get_flow;
    srv_ancs_service_info_struct srv_info;
    srv_ancs_char_info_struct    char_info[SRV_ANCS_MAX_CHAR];
    ATT_VALUE ctrl_pt_buff;
#ifdef __MMI_ANCS_MAX_QUEUE__
    U32 nsrc_count;
#endif /* __MMI_ANCS_MAX_QUEUE__ */
    srv_ancs_nsrc_node_struct nsrc_list;
    srv_ancs_noti_src_info_struct noti_src[SRV_ANCS_MAX_NOTI_SOURCE]; // notification source
    srv_ancs_noti_attr_struct noti_info[SRV_ANCS_MAX_NOTI_NUM]; // notificaion attribute
    srv_ancs_app_attr_struct app_info[SRV_ANCS_MAX_APP_ATTRIBUTE_NUM]; // app attribute
} srv_ancs_dev_info_struct;

typedef struct
{
    srv_ancs_reg_struct ancs_srv;
    srv_ancs_dev_info_struct dev_info[SRV_ANCS_MAX_DEV];
} srv_ancs_context_struct;


void srv_ancs_parse_notification_source(srv_ancs_nsrc_struct* noti_src, ATT_VALUE* ptr);
void srv_ancs_parse_control_point(U8 command_id, void* para, ATT_VALUE* ctrl_buff);
void srv_ancs_parse_data_source(srv_ancs_dev_info_struct* dev_p, ATT_VALUE* input_ptr);
void srv_ancs_cm_notify_hdlr(U32 event, void *args);

void srv_ancs_fsm(srv_ancs_dev_info_struct* dev_p, srv_ancs_get_state_enum step);
void srv_ancs_register_client_cb(void* reg_ctx, OS_STATUS status, bt_uuid_struct* app_uuid);
void srv_ancs_connection_cb(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void srv_ancs_scan_result_cb(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir);
void srv_ancs_search_result_cb(gatt_conn_struct *conn, GATT_SVC_UUID *uuid);
void srv_ancs_search_complete_cb(gatt_conn_struct *conn, OS_STATUS status);
void srv_ancs_get_characteristic_cb(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties);
void srv_ancs_read_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr_info, ATT_VALUE *value);                                
void srv_ancs_write_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr_info);
void srv_ancs_get_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr_info);
void srv_ancs_notify_cb(gatt_conn_struct *conn, BD_ADDR *bd_addr,
                                gattc_char_struct *char_info, ATT_VALUE *value, BOOL is_notify);
void srv_ancs_write_characteristic_cb(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *char_info);
void srv_ancs_service_change_notify_cb(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);
void srv_ancs_register_for_notification_cb(void *reg_ctx, OS_STATUS status, 
                                BD_ADDR *bd_addr, gattc_char_struct *char_info);

void srv_ancs_reg_notification(srv_ancs_dev_info_struct* dev_p, srv_ancs_uuid_enum type);
srv_ancs_char_info_struct* srv_ancs_query_characteristics(srv_ancs_dev_info_struct* dev_p, srv_ancs_char_query_type_enum type, void* value);
U32 srv_ancs_get_delay_time(U8 category_id);
srv_ancs_dev_info_struct* srv_ancs_get_free_dev(void);
srv_ancs_dev_info_struct* srv_ancs_get_dev_info(srv_ancs_query_type_enum op, void* para);
srv_ancs_noti_src_info_struct* srv_ancs_get_noti_src(srv_ancs_dev_info_struct* dev_p, S32 noti_id);
MMI_BOOL srv_ancs_get_uuid_type(gattc_char_struct* char_info, srv_ancs_uuid_enum* uuid);
srv_ancs_noti_attr_struct* srv_ancs_get_attr_info(srv_ancs_dev_info_struct* dev_p, S32 noti_id);
srv_ancs_app_attr_struct* srv_ancs_get_app_info(srv_ancs_dev_info_struct* dev_p, U8* app_id, U32 len);
srv_ancs_attr_node_struct* srv_ancs_get_attr_node(U8 attr_value, srv_ancs_attr_node_struct* attr_list);
srv_ancs_char_info_struct* srv_ancs_get_free_char(srv_ancs_dev_info_struct* dev_p);
MMI_BOOL srv_ancs_is_same_dev(BD_ADDR* dest_addr, BD_ADDR* src_addr);
MMI_BOOL srv_ancs_is_same_uuid(bt_uuid_struct* dest_uu, bt_uuid_struct* src_uu);
MMI_BOOL srv_ancs_is_any_services_exist(void);
void* srv_ancs_mem_alloc(U32 size);
void srv_ancs_mem_free(void* ptr);
srv_ancs_dev_info_struct* srv_ancs_new_dev(void* conn_ctx, BD_ADDR* bd_addr);
void srv_ancs_del_dev(S32 srv_hd);
void srv_ancs_del_noti_info(srv_ancs_noti_attr_struct* noti_info_p);
void srv_ancs_del_noti_node(srv_ancs_dev_info_struct* dev_p, srv_ancs_nsrc_struct* data, MMI_BOOL del_all);
void srv_ancs_del_app_info(srv_ancs_app_attr_struct* app_info_p);
srv_ancs_noti_src_info_struct* srv_ancs_create_noti_src(srv_ancs_dev_info_struct* dev_p, srv_ancs_nsrc_struct* noti_data);
srv_ancs_noti_attr_struct* srv_ancs_create_noti_info(srv_ancs_dev_info_struct* dev_p, S32 noti_id);
srv_ancs_app_attr_struct* srv_ancs_create_app_info(srv_ancs_dev_info_struct* dev_p, U8* app_id, U32 len);
srv_ancs_nsrc_node_struct* srv_ancs_create_noti_node(srv_ancs_dev_info_struct* dev_p, srv_ancs_nsrc_struct* data);
void srv_ancs_send_indication(srv_ancs_noti_type_enum ind_op, S32 noti_id, void *ptr);
mmi_ret srv_ancs_post_event_callback(mmi_post_result_event_struct *result_evt);

void srv_ancs_str_to_uuid(const U8* str, BT_UUID* uuid);
MMI_BOOL srv_ancs_is_correct_uuid(BT_UUID* src, BT_UUID* dest);
void srv_ancs_covert2cm_addr(U8 *src, srv_bt_cm_bt_addr *dst);
U32 srv_ancs_app_id_hash(U8* app_id);
MMI_BOOL srv_ancs_disconnect_req(srv_bt_cm_bt_addr* addr);
#endif /* __MMI_BLE_ANCS_SUPPORT__ */
#endif /* SRV_NOTI_ANCS_PROT_H */
