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
 * BTNotiSrvData.h
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
#ifndef __BT_NOTI_SRV_DATA_H__
#define __BT_NOTI_SRV_DATA_H__

#include "MMI_features.h"
#ifdef __MMI_BT_NOTI_SRV__

#include "MMIDataType.h"
#include "fs_gprot.h"  

#include "BtNotiSrvGprot.h"
#include "BtNotifySrvParser.h"

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
#define BT_NOTIFY_MEM_POOL_SIZE ((SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_PAGE_MAX_NUM + 1) * 700)
#endif


typedef struct 
{
    U32 node_index[SRV_BT_NOTI_MSG_LIST_MAX_NUM];
    U32 srv_bt_noti_data_list_mask[SRV_BT_NOTI_MSG_LIST_MAX_NUM];
    U32 node_num;
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    U32 group_num;
    U32 group_index[BT_NOTIFY_MAX_GROUP_NUM];    
    U32 srv_bt_noti_group_list_mask[SRV_BT_NOTI_MSG_LIST_MAX_NUM];
    U32 group_count;
#endif
    MMI_BOOL is_waiting_parser_callback;
}srv_bt_noti_data_msg_context_struct;


#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
#define SRV_BT_NOTI_LISTMGR_MSG_LIST_MAX_NUM (SRV_BT_NOTI_MSG_LIST_MAX_NUM * BT_NOTIFY_MAX_CHANNEL)
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
#define SRV_BT_NOTI_LISTMGR_GROUP_LIST_MAX_NUM (BT_NOTIFY_MAX_GROUP_NUM * BT_NOTIFY_MAX_CHANNEL)

typedef struct
{
    U32 group_index;
    U32 chnnl_num;
}srv_bt_noti_data_listmgr_group_node_struct;

#endif


typedef struct 
{
    srv_bt_noti_data_listmgr_node_struct  listmgr_node[SRV_BT_NOTI_LISTMGR_MSG_LIST_MAX_NUM];   
    U32 listmgr_node_num;

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    srv_bt_noti_data_listmgr_node_struct listmgr_group_node[SRV_BT_NOTI_LISTMGR_GROUP_LIST_MAX_NUM];
    U32 listmgr_group_node_num;
#endif
}srv_bt_noti_data_listmgr_context_struct;
#endif


#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
typedef struct
{
    MMI_BOOL is_new_msg;
}srv_bt_noti_data_parser_struct;
#endif


static MMI_BOOL srv_bt_noti_data_event_hdlr(srv_bt_noti_event_struct* event_data);

static void srv_bt_noti_data_send_refresh(srv_bt_cm_bt_addr *bt_addr, 
    srv_bt_notify_refresh_type refresh_type, 
    srv_bt_notify_refresh_reason_enum refresh_reason,
    U32 index,
    U32 noti_id);
void srv_bt_noti_data_delete_msg_int(srv_bt_cm_bt_addr *bt_addr, U32 index, srv_bt_notify_refresh_reason_enum  delete_reason);
static MMI_BOOL srv_bt_noti_data_handle_add_msg(srv_bt_noti_event_info_add*  event_info);
static mmi_ret srv_bt_noti_data_ext_event_handler(mmi_event_struct *evt);

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
static void srv_bt_noti_data_listmgr_send_refresh(srv_bt_cm_bt_addr *bt_addr, 
    srv_bt_notify_refresh_type refresh_type, 
    srv_bt_notify_refresh_reason_enum refresh_reason,
    U32 index,
    U32 noti_id);
static void srv_bt_noti_data_listmgr_refresh_data(srv_bt_notify_refresh_type refresh_type,
        srv_bt_notify_refresh_reason_enum refresh_reason,
        U32 noti_id);
static srv_bt_noti_data_msg_node_struct * srv_bt_noti_data_listmgr_get_msg_info(U32 index);
static MMI_BOOL srv_bt_noti_data_listmgr_get_index_by_noti_id(U32 noti_id, U32 *index);
static MMI_BOOL srv_bt_noti_data_listmgr_locate_by_noti_id(U32 noti_id, 
                                                                                                             U32 *unified_index,
                                                                                                             U32 *solo_index,
                                                                                                             srv_bt_cm_bt_addr *bt_addr,
                                                                                                             U32 *chnnl_num);
static void srv_bt_noti_data_listmgr_delete_msg_int(U32 noti_id, srv_bt_notify_refresh_reason_enum  delete_reason);
static void srv_bt_noti_data_listmgr_list_print();
static void srv_bt_noti_data_listmgr_list_sort();
srv_bt_noti_data_group_list_struct *srv_bt_noti_data_get_group_by_noti_idx(U32 cntx_chnl, 
                                                                                        U32 noti_idx, 
                                                                                        U32 *group_indx, 
                                                                                        U32 *group_list_indx, 
                                                                                        U32 *group_noti_indx);


KAL_ADM_ID srv_bt_noti_data_get_mem_pool_id();
void *srv_bt_noti_data_mem_alloc(int size);
void srv_bt_noti_data_mem_free(void *ptr);


#endif


#endif/*__MMI_BT_NOTI_SRV__*/

#endif/*__BT_NOTI_SRV_DATA_H__*/

