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
*  TimeSrv.h
*
* Project:
* -------- 
*  MAUI
*
* Description:
* ------------
*  Time sync extension
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
****************************************************************************/

#ifndef __SRV_TIME_H__
#define __SRV_TIME_H__

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "TimeSrvGprot.h"
#include "btostypes.h"
#include "bt_types.h"
#include "GattcSrv.h"
#include "kal_trace.h"
#include "MMI_conn_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_frm_events_gprot.h"


#define SRV_TIME_MAX_LINK_NUM                   (1)
#define SRV_TIME_MAX_SERVICE                    (1)
#define SRV_TIME_MAX_CHAR                       (1)
#define SRV_TIME_MAX_HD_NUM                     (1)


#define SRV_TIME_FLAG_USED                      (0x01)
#define SRV_TIME_FLAG_TF                        (0x02)

#define TIME_SRV_TF_UUID                        (0x1902)
#define TIME_TF_CHAR_UUID                       (0x2B01)

//#define SRV_TIME_UT

typedef enum
{
    SRV_TIME_STATE_IDLE                 = 0,
    SRV_TIME_STATE_REGISTERING,
    SRV_TIME_STATE_LISTENING,
    SRV_TIME_STATE_READY,
    SRV_TIME_STATE_CONNECTING,
    SRV_TIME_STATE_CONNECTED,
    SRV_TIME_STATE_SEARCHING,
    SRV_TIME_STATE_GETTING_CHAR,
    SRV_TIME_STATE_REG_NOTIFY,
    SRV_TIME_STATE_READ_CHAR,
    SRV_TIME_STATE_WRITE_CHAR,
    SRV_TIME_STATE_GET_DESCR,
    SRV_TIME_STATE_READ_DESCR,
    SRV_TIME_STATE_WRITE_DESCR,

    SRV_TIME_STATE_DONE = 100,
    SRV_TIME_STATE_TOTAL = 500,
} srv_time_state_enum;

typedef enum
{
    SRV_TIME_QUERY_BY_NULL          = 0,
    SRV_TIME_QUERY_BY_CONN,
    SRV_TIME_QUERY_BY_ADDR,
    SRV_TIME_QUERY_BY_CHAR_UUID,
    SRV_TIME_QUERY_BY_INDEX,

    SRV_TIME_QUERY_TYPE_TOTAL
} srv_time_query_type_enum;

typedef enum
{
    /* DON'T ALLOW TO MODIFY ENUM VALUE */
    SRV_TIME_SRV_TF = 0,

    SRV_TIME_SRV_TOTAL
} srv_time_srv_enum;


/* char info struct */
typedef struct
{
    MMI_BOOL valid;
    MMI_BOOL need_reg;
    MMI_BOOL registered;
    MMI_BOOL descriptor;
    MMI_BOOL des_writed;
    U8 des_len;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
} srv_time_char_info_struct;

typedef struct
{
    MMI_BOOL valid;
    GATT_SVC_UUID srv_uuid;
} srv_time_srv_info_struct;

/* time handle struct */
typedef struct
{
    void *ud;
} srv_time_handle_struct;

typedef struct
{
    U8 flag;                  /*0x01: used*/
    U8 state;
    BD_ADDR bd_addr;
    void *conn_ctx;
    srv_time_srv_info_struct srv_info[SRV_TIME_MAX_SERVICE];
    srv_time_char_info_struct char_info[SRV_TIME_MAX_CHAR];
    U8 index;

    ATT_UUID *start_char;
} srv_time_dev_info_struct;

typedef struct
{
    U8 state;
    MMI_BOOL init;
    void *reg_ctx;
    srv_time_dev_info_struct *dev_info;
    gattc_callback_struct gattc_cb;
    bt_uuid_struct uuid;

    /* time format */
    BD_ADDR bd_addr;
    U32 flag;
    srv_time_evt_cb cb;
} srv_time_cntx_struct;


/* Static Function */

static srv_time_cntx_struct *srv_time_get_cntx();

static void srv_time_cntx_init();

static void srv_time_register_cb(void *reg_ctx, OS_STATUS status,
    bt_uuid_struct *app_uuid);

static void srv_time_scan_result_cb(void *reg_ctx, BD_ADDR *bd_addr,
    S32 rssi, U8 eir_len, U8 *eir);

static void srv_time_connect_cb(gatt_conn_struct *conn,
    BOOL connected, BD_ADDR *bd_addr);

static void srv_time_connect_ext_cb(gattsrv_conn_struct *conn_ext);

static void srv_time_listen_cb(void *reg_ctx, OS_STATUS status);

static void srv_time_search_service_result_cb(gatt_conn_struct *conn,
    GATT_SVC_UUID *uuid);

static void srv_time_search_service_complete_cb(
    gatt_conn_struct *conn, OS_STATUS status);

static void srv_time_get_char_cb(gatt_conn_struct *conn, OS_STATUS status,
    gattc_char_struct *chr, GATT_CHAR_PROPERTIES properties);

static void srv_time_read_char_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_char_struct *chr, ATT_VALUE *value);

static void srv_time_write_char_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_char_struct *ch);

static void srv_time_register_for_notification_cb(void *reg_ctx,
    OS_STATUS status, BD_ADDR *bd_addr, gattc_char_struct *char_info);

static void srv_time_get_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info);

static void srv_time_read_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info, ATT_VALUE *value);

static void srv_time_write_descriptor_cb(gatt_conn_struct *conn,
    OS_STATUS status, gattc_descr_struct *descr_info);

static void srv_time_notify_cb(gatt_conn_struct *conn,
    BD_ADDR *bd_addr, gattc_char_struct *char_info, ATT_VALUE *value,
    BOOL is_notify);

static srv_time_dev_info_struct *srv_time_alloc_dev();

static void srv_time_free_dev(srv_time_dev_info_struct *dev);

static srv_time_dev_info_struct *srv_time_get_dev(U8 type, void *para);

static void srv_time_fsm(srv_time_dev_info_struct *dev);

static srv_time_char_info_struct *srv_time_get_free_char(U8 type,
    srv_time_dev_info_struct *dev);

static S32 srv_time_check_para(U8 type, void *para);

static void srv_time_research_service_cb(gatt_conn_struct *conn,
    OS_STATUS status, BD_ADDR *bd_addr);


/* */
void srv_time_init();

void srv_time_deinit();

void srv_time_connect(BD_ADDR *bd_addr);

void srv_time_disconnect(BD_ADDR *bd_addr);

S32 srv_time_get_addr(U8 index, BD_ADDR *bd_addr);

#endif /* __SRV_TIME_H__ */

