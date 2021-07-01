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
 * BTNotiSrvData.c
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
#include "MMI_features.h"

#ifdef __MMI_BT_NOTI_SRV__
#include "MMIDataType.h"

#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#include "OslMemory.h"
#include "Kal_trace.h"
#include "Unicodexdcl.h"
#include "AlertScreen.h"
#include "fs_gprot.h"

#include "BTNotiSrvData.h"
#include "BTNotiSrvDisp.h"
#include "BTNotiSrvRecv.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "BTNotiSrvGprot.h"
#include "SmsBtMapCSrvGProt.h"

static srv_bt_noti_data_msg_node_struct srv_bt_noti_data_node_list[BT_NOTIFY_MAX_CHANNEL][SRV_BT_NOTI_MSG_LIST_MAX_NUM];
#ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
static srv_bt_noti_data_icon_struct srv_bt_noti_data_icon_list[BT_NOTIFY_MAX_CHANNEL][SRV_BT_NOTI_MSG_LIST_MAX_NUM];
#endif
static srv_bt_noti_data_msg_context_struct srv_bt_noti_data_msg_context[BT_NOTIFY_MAX_CHANNEL];
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
srv_bt_noti_data_group_list_struct srv_bt_noti_data_group_list[BT_NOTIFY_MAX_CHANNEL][BT_NOTIFY_MAX_GROUP_NUM];
srv_bt_noti_data_parser_struct srv_bt_noti_data_flag;

#endif

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
srv_bt_noti_data_listmgr_context_struct srv_bt_noti_data_listmgr_context;
#endif

/*memory pool management*/
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static U8 bt_noti_mem_pool[BT_NOTIFY_MEM_POOL_SIZE];
KAL_ADM_ID bt_noti_pool_id = 0;
#endif


// cm: Common Modules
// SP->FP
static srv_bt_noti_data_msg_node_struct srv_bt_notify_call_data_node[BT_NOTIFY_MAX_CHANNEL];
static U32 srv_bt_notify_call_data_node_index = 1111;

static srv_bt_noti_data_msg_node_struct srv_bt_notify_sms_data_node[BT_NOTIFY_MAX_CHANNEL];
static U32 srv_bt_notify_sms_data_node_index = 1112;

static U32 srv_bt_notify_noti_id_counter = 0;

#ifndef __MTK_TARGET__
#ifndef SRV_BT_NOTIFY_TEST_FSM
#define SRV_BT_NOTIFY_TEST_FSM
#endif
#ifndef SRV_BT_MODIS_TEST
#define SRV_BT_MODIS_TEST
#endif
#endif


#ifndef __MMI_BT_MAPC_NEW_SMS_POPUP__
#define SMS_IN_NOTIFICATION
#endif

static void srv_bt_noti_call_init(void);
static void srv_bt_noti_notify_missed_call(srv_bt_cm_bt_addr *bt_addr, 
                                                                            U32 missed_call_count, 
                                                                            U32 timestamp,
                                                                            WCHAR* send_number,
                                                                            WCHAR* sender);

static void srv_bt_noti_data_listmgr_group_list_sort();


#ifndef SMS_IN_NOTIFICATION                                                                            
static void srv_bt_noti_sms_init(void);
static void srv_bt_noti_notify_new_sms(srv_bt_cm_bt_addr *bt_addr, 
                                                                            WCHAR* content, 
                                                                            U32 timestamp,
                                                                            WCHAR* send_number,
                                                                            WCHAR* sender);
#endif
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static void srv_bt_noti_data_group_handle_delete_msg(S32 cntx_chnl, U32 del_node_index);
#endif

MMI_BOOL srv_bt_noti_data_handle_connected(srv_bt_noti_event_info_connceted*  event_info);


//#define __TEST__
#ifdef __TEST__
kal_int32 srv_bt_notify_xml_parse(
    WCHAR *file_name, 
    srv_bt_notify_parse_para para_flag, 
    srv_bt_parse_xml_callback callback, 
    void *data )
{
    srv_bt_notify_noti_struct *noti;
    srv_bt_notify_sms_struct *sms;
    
    if (para_flag == srv_bt_notify_parse_noti_body)
    {
        noti = (srv_bt_notify_noti_struct*)data;
        strcpy(noti->content, file_name); 
    }
    else
    {
        sms = (srv_bt_notify_sms_struct*)data;
        strcpy(sms->content, file_name);
    }
    
    callback(para_flag, data, 0);
    
    return 0;    
}

void srv_bt_noti_data_print(void)
{
    U32 i, num;
    srv_bt_noti_data_msg_node_struct * node;
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context;

    for (i = 0;i < SRV_BT_NOTI_MSG_LIST_MAX_NUM; ++i)
    {
        printf("%d ", context->srv_bt_noti_data_list_mask[i]);       
    }
    
    num = srv_bt_noti_data_get_msg_num();
    printf("\nmsg_num=%d\n", num);
    
    for (i = 0; i < num; ++i)
    {
        node = srv_bt_noti_data_get_msg_info(i); 
        printf("node_index = %d, content: %s\n", context->node_index[i], node->content); 
    }
    
    printf("\n");    
}

void srv_bt_noti_data_test(void)
{
    srv_bt_noti_event_struct event_data;
    srv_bt_noti_event_info_new event_info;
    srv_bt_notify_header_struct header;

    event_data.evt_id = EVT_ID_SRV_BT_NOTI_NEW_MSG;
    event_data.event_info = &event_info;
    event_info.header = &header;
    
    event_info.xml_file_path = "xml_file_name1";
    header.subtype = srv_bt_notify_subtype_text;
        
    srv_bt_noti_data_event_hdlr(&event_data);
    srv_bt_noti_data_print();

    event_info.xml_file_path = "xml_file_name2";
    srv_bt_noti_data_event_hdlr(&event_data);
    srv_bt_noti_data_print();

    event_info.xml_file_path = "xml_file_name3";
    srv_bt_noti_data_event_hdlr(&event_data);
    srv_bt_noti_data_print();

    srv_bt_noti_data_delete_msg_int(1);
    srv_bt_noti_data_print();
    
    srv_bt_noti_data_delete_all();
    srv_bt_noti_data_print();    
}
#endif

#ifndef __MTK_TARGET__
void srv_bt_noti_send_sms_test()
{
    MMI_BOOL retval = srv_bt_noti_data_reply_remote_sms(NULL, L"15882487297", L"testetstt");
}
#endif

static void srv_bt_noti_data_init_msg(U8 cntx_chnl, srv_bt_noti_data_msg_node_struct *msg_node, U32 msg_node_index)
{
    CHAR bt_format_addr[20];
    srv_bt_cm_bt_addr *bt_addr = srv_bt_noti_get_bt_device_addr(cntx_chnl);

    memset(msg_node, 0, sizeof(srv_bt_noti_data_msg_node_struct));

    srv_bt_notify_noti_id_counter ++;
    msg_node->noti_id = srv_bt_notify_noti_id_counter;
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "init msg, noti_id: %d", 
              msg_node->noti_id);
    
    msg_node->chnnl_num = cntx_chnl;
    
    if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
    {
        return;
    }
    kal_wsprintf(msg_node->xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
    srv_bt_noti_create_folder(msg_node->xml_file_path);
#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__    
    kal_wsprintf(msg_node->icon_file_path, "%w%s\\%d.jpg", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, msg_node_index);
#endif
    kal_wsprintf(msg_node->xml_file_path, "%w%s\\%d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, msg_node_index);
}

#ifdef SRV_BT_MODIS_TEST
void srv_bt_noti_data_new_msg_test(U8  index)
{
    srv_bt_noti_event_struct event_data;
    srv_bt_noti_event_info_new event_info;
    srv_bt_notify_header_struct header;

    event_data.evt_id = EVT_ID_SRV_BT_NOTI_NEW_MSG;
    event_data.event_info = &event_info;
    event_info.header = &header;

    if(index == 0)
    {
        event_info.xml_file_path = L"c:\\@BTNotify\\bt_notify_text.xml";
        header.subtype = srv_bt_notify_subtype_text;
    }
    else
    {
        event_info.xml_file_path = L"c:\\@BTNotify\\bt_notify_sms.xml";
        header.subtype = srv_bt_notify_subtype_sms;
    }

    
    header.category = srv_bt_notify_category_noti;
            
    srv_bt_noti_data_event_hdlr(&event_data);
}


void srv_bt_noti_data_connect_test(int index)
{
    srv_bt_noti_event_info_connceted event_infor;
    event_infor.source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;
       

    event_infor.bt_addr.lap = 0xF2F1F0;
    event_infor.bt_addr.nap = 0xF5F4;
    event_infor.bt_addr.uap = 0xF3;

    srv_bt_noti_data_handle_connected(&event_infor);
}

#ifdef SRV_BT_MODIS_TEST

void srv_bt_noti_data_add_msg_test(int index)
{
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__

    srv_bt_noti_event_info_add event_infor;
    srv_bt_noti_data_msg_node_struct  *node = &(event_infor.msg_info);
        
    //copy data 
    memset( &(node->header),  0, sizeof(srv_bt_noti_data_msg_node_struct));          
    memcpy(node->sender, L"test sender", BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
    memcpy(node->send_number, L"test number", BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH);
    node->page_content = OslMalloc(sizeof(srv_bt_noti_page_content_struct));
    node->page_num = 1;
    memcpy(node->page_content->content, L"test ANCS content", BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
    memcpy(node->page_content->title, L"test title", BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
    //memcpy(node->content, L"test ANCS content", BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
    //memcpy(node->title, L"test title", BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
    //memcpy(node->ticker_text, L"test ticker_text", BT_NOTIFY_TICKER_TEXT_LENTH * ENCODING_LENGTH);
    node->timestamp = 1372300293;
    node->source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;

    node->ANCS_msg_id = index+5;

    event_infor.bt_addr.lap = 0xF2F1F0;
    event_infor.bt_addr.nap = 0xF5F4;
    event_infor.bt_addr.uap = 0xF3;

    srv_bt_noti_data_handle_add_msg(&event_infor);
    OslMfree(node->page_content);
#endif /*__MMI_BT_NOTIFICATION_ENHANCE__*/
}
#endif
static void srv_bt_noti_data_handle_del_msg(srv_bt_noti_event_info_del *event_info);

void srv_bt_noti_data_delete_msg_test(int index)
{
    srv_bt_noti_event_info_del event_infor;

    event_infor.source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;
    event_infor.ANCS_id = 5+index;
    event_infor.bt_addr.lap = 0xF8F7F6;
    event_infor.bt_addr.nap = 0xFBFA;
    event_infor.bt_addr.uap = 0xF9;

    srv_bt_noti_data_handle_del_msg(&event_infor);
}
#endif

void srv_bt_noti_data_ut_handle(U8  index, kal_uint8 *string)
{
#ifdef SRV_BT_MODIS_TEST

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
    static void srv_bt_noti_data_listmgr_ut();
    if (strcmp((const kal_char*)string, "BTNOTIFY_LISTMGR_UT" ) == 0)
    {
        srv_bt_noti_data_listmgr_ut();            
        return ;
    }
#endif

    if (strcmp((const kal_char*)string, "BTNOTIFY_ADD" ) == 0)
    {
        srv_bt_noti_data_add_msg_test(index);            
        return ;
    }
    else if (strcmp((const kal_char*)string, "BTNOTIFY_CONN" ) == 0)
    {
        srv_bt_noti_data_connect_test(index);            
        return ;
    }    
    else if (strcmp((const kal_char*)string, "BTNOTIFY_DEL" ) == 0)
    {
        srv_bt_noti_data_delete_msg_test(index);            
        return ;
    }
    
    srv_bt_noti_data_new_msg_test(index);
#endif
}


#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
MMI_BOOL srv_bt_noti_memory_create()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static U32 subpool_size[] = {1024,0xffffffff,0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (bt_noti_pool_id)
    {
        return MMI_TRUE;
    }

    bt_noti_pool_id = kal_adm_create(bt_noti_mem_pool, BT_NOTIFY_MEM_POOL_SIZE, subpool_size,
#ifdef __BT_NOTI_SRV_MEM_DEBUG__
                                               KAL_TRUE
#else 
                                               KAL_FALSE
#endif 
        );

    if (!bt_noti_pool_id)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


KAL_ADM_ID srv_bt_noti_data_get_mem_pool_id()
{
    return bt_noti_pool_id;
}

void *srv_bt_noti_data_mem_alloc(int size)
{
    return kal_adm_alloc(bt_noti_pool_id,size);
}

void srv_bt_noti_data_mem_free(void *ptr)
{
    kal_adm_free(bt_noti_pool_id, ptr);
    return;
}

void srv_bt_noti_data_node_free(srv_bt_noti_data_msg_node_struct *node)
{
    int i,j;
    srv_bt_noti_page_content_struct *page_content;
    srv_bt_noti_page_content_struct *pre_page_content;  
    
    for(i = node->page_num; i > 0; i--)
    {
        page_content = node->page_content;
        pre_page_content = page_content;
        for(j = 0; j < i - 1; j++)
        {
            pre_page_content = page_content;
            page_content = page_content->next;
        }

        if (page_content)
        {
            srv_bt_noti_data_mem_free(page_content);
            pre_page_content->next = NULL;
            page_content = NULL;
        }
    }
    node->page_content = NULL;
}
#endif

void srv_bt_noti_data_init(void)
{
    memset(&srv_bt_noti_data_msg_context, 0, sizeof(srv_bt_noti_data_msg_context_struct));
#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__    
    memset(&srv_bt_noti_data_listmgr_context, 0, sizeof(srv_bt_noti_data_listmgr_context_struct));
#endif

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    if (!srv_bt_noti_memory_create())
    {
        MMI_ASSERT(0);
    }
#endif

    srv_bt_noti_disp_set_interrupt_event_handler(
        EVT_ID_SRV_BT_NOTI_NEW_MSG,
        srv_bt_notify_category_noti,
        srv_bt_noti_data_event_hdlr,
        NULL);

    srv_bt_noti_disp_set_interrupt_event_handler(
        EVT_ID_SRV_BT_NOTI_DEL_MSG,
        srv_bt_notify_category_noti,
        srv_bt_noti_data_event_hdlr,
        NULL);

    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_ADD_MSG, srv_bt_noti_data_ext_event_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_DEL_MSG, srv_bt_noti_data_ext_event_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_CONNECTED, srv_bt_noti_data_ext_event_handler, NULL);
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_DISCONNECTED, srv_bt_noti_data_ext_event_handler, NULL);
         
#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_LISTMGR_REFRESH, srv_bt_noti_data_ext_event_handler, NULL);
#endif

    srv_bt_noti_call_init();
    #ifndef SMS_IN_NOTIFICATION   
    srv_bt_noti_sms_init();
    #endif
    #ifdef __TEST__
    srv_bt_noti_data_test();
    #endif

    #ifdef SRV_BT_NOTIFY_TEST_FSM
    //srv_bt_noti_data_new_msg_test();
    #endif
}

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
U32 srv_bt_noti_data_get_msg_num(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_noti_data_msg_context_struct *context;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return 0;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_NUM, cntx_chnl, context->node_num);
     
    return context->node_num;
}


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
srv_bt_noti_data_msg_node_struct *srv_bt_noti_data_get_msg_info(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    srv_bt_noti_data_msg_node_struct *node;
    U32 node_index;
    
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return NULL;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_INFO, cntx_chnl, index);
    MMI_ASSERT(index < context->node_num);
    
    node_index = context->node_index[index];
    MMI_ASSERT(node_index < SRV_BT_NOTI_MSG_LIST_MAX_NUM);    
    node = &(node_list[node_index]);
    
    return node;
}


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
S32 srv_bt_noti_data_get_msg_index_by_msg_id(srv_bt_cm_bt_addr *bt_addr, U32 msg_id)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;    
    srv_bt_noti_data_msg_node_struct *node;
    U32 i;
    S32 index = -1;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return -1;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);
    
    for (i = 0; i < context->node_num; ++i)        
    {
        node = &(node_list[i]);
        
        if (node->header.msg_id == msg_id)
        {
            index = i;
            break;
        }
    }
    
    return index;
}


S32 srv_bt_noti_data_get_msg_sort_index_by_msg_id(srv_bt_cm_bt_addr *bt_addr, U32 msg_id)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;    
    srv_bt_noti_data_msg_node_struct *node;
    U32 i;
    S32 index = -1;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return -1;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);
    
    for (i = 0; i < context->node_num; ++i)        
    {
        node = &(node_list[context->node_index[i]]);
        
        if (node->header.msg_id == msg_id)
        {
            index = i;
            break;
        }
    }
    
    return index;
}



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
MMI_BOOL srv_bt_noti_data_get_msg_info_ref(srv_bt_cm_bt_addr *bt_addr, 
                                           U32 index, 
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    srv_bt_noti_data_msg_node_struct *node;
    U32 node_index;
    
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return MMI_FALSE;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_INFO_REF, cntx_chnl, index);
        
    if (index >= context->node_num)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    node_index = index;
#else
    node_index = context->node_index[index];
#endif
    
    if (node_index >= SRV_BT_NOTI_MSG_LIST_MAX_NUM)
    {
        return MMI_FALSE;
    }
    
    node = &(node_list[node_index]);
    *node_ref = *node;
    
    return MMI_TRUE;
}

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
 MMI_BOOL srv_bt_noti_data_set_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index, MMI_BOOL is_read)
{
    srv_bt_noti_data_msg_node_struct *node;


    node =  srv_bt_noti_data_get_msg_info(bt_addr, index);

    if(node == NULL)
    {
        return MMI_FALSE;
    }

    node->is_read = is_read;
        
    return MMI_TRUE;
}

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
 MMI_BOOL srv_bt_noti_data_set_all_as_read(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;    
    srv_bt_noti_data_msg_node_struct *node;
    U32 i;

    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return MMI_FALSE;
    }

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    for (i = 0; i < context->node_num; ++i)        
    {
        node = &(node_list[context->node_index[i]]);
        node->is_read = MMI_TRUE;
    }

    return MMI_TRUE;

}

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
 MMI_BOOL srv_bt_noti_data_get_read_status(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
    srv_bt_noti_data_msg_node_struct *node;


    node =  srv_bt_noti_data_get_msg_info(bt_addr, index);

    if(node == NULL)
    {
        return MMI_TRUE;
    }

    return node->is_read;
}


MMI_BOOL srv_bt_noti_delete_remote(srv_bt_cm_bt_addr *bt_addr, U32 noti_id)
{
    srv_bt_notify_data_struct* node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];

    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTNOTIFYSRV]deleteRemote noti_id:%d.", noti_id);
    do
    {
        node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (node == NULL)
        {
            break;
        }
        
        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }
        
        memset(node, 0, sizeof(srv_bt_notify_data_struct));
        node->header.category= srv_bt_notify_category_noti;
        node->header.subtype= srv_bt_notify_subtype_noti_delete;
        node->header.action = srv_bt_notify_action_delete;        
        node->header.msg_id= noti_id;

        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\update_noti_delete_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);

        parse_ret = srv_bt_notify_xml_generator(xml_file_path, node);
        //trace
        //MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_UPDATE_REMOTE_BLOCK_PARSE_RESULT, parse_ret);
        
        if (parse_ret == -1)
        {
            break;
        }          

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }
    
    if (node != NULL)
    {
        OslMfree(node);
    }
    
    return retval;
}




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
void srv_bt_noti_data_delete_msg_int(srv_bt_cm_bt_addr *bt_addr, U32 index, srv_bt_notify_refresh_reason_enum  delete_reason)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    
    U32 del_node_index;
    srv_bt_noti_data_msg_node_struct *node;

    U32 i;
    U32 noti_id, msg_id;

    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_DELETE_MSG, cntx_chnl, index);   
    MMI_ASSERT(index<context->node_num);

    del_node_index = context->node_index[index];
    MMI_ASSERT(del_node_index < SRV_BT_NOTI_MSG_LIST_MAX_NUM);
    node = &(node_list[del_node_index]);
    msg_id = node->header.msg_id;
    noti_id = node->noti_id;

#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    FS_Delete(node->icon_file_path);
#endif
    FS_Delete(node->xml_file_path);

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    srv_bt_noti_data_group_handle_delete_msg(cntx_chnl,del_node_index);

    srv_bt_noti_data_node_free(node);
#endif
    memset(node, 0, sizeof(srv_bt_noti_data_msg_node_struct));

    // context->srv_bt_noti_data_list_mask[index] = 0;
    // [MAUI_03446114] delete notification show wrong msg, use wrong index
    context->srv_bt_noti_data_list_mask[del_node_index] = 0;

    for (i = index; i < context->node_num - 1; ++i)
    {
        context->node_index[i] = context->node_index[i + 1];
    }
    
    --context->node_num;
    if (delete_reason == srv_bt_notify_refresh_reason_from_app)
    {
        srv_bt_noti_delete_remote(bt_addr, msg_id);
    }
    srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_DEL,delete_reason, 0, noti_id);
}

void srv_bt_noti_data_delete_msg(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
      srv_bt_noti_data_delete_msg_int(bt_addr, index, srv_bt_notify_refresh_reason_from_app);
}

static void srv_bt_noti_data_delete_msg_by_app_id(srv_bt_cm_bt_addr *bt_addr, U32 app_id)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;  
    U32 del_node_index;
    srv_bt_noti_data_msg_node_struct *node;
    U32 i = 0,j = 0;
    
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    while (i < context->node_num)
    {
        del_node_index = context->node_index[i];
        MMI_ASSERT(del_node_index<SRV_BT_NOTI_MSG_LIST_MAX_NUM);
        node = &(node_list[del_node_index]);

        if (node->app_id == app_id)
        {
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            node->is_blocked = MMI_TRUE;
            i++;
        #else
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_DELETE_MSG, cntx_chnl, i);
            #ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
            FS_Delete(node->icon_file_path);
            #endif
            FS_Delete(node->xml_file_path);
            
            memset(node, 0, sizeof(srv_bt_noti_data_msg_node_struct));
            // context->srv_bt_noti_data_list_mask[i] = 0;
            // [MAUI_03446114] delete notification show wrong msg, use wrong index
            context->srv_bt_noti_data_list_mask[del_node_index] = 0;

            --context->node_num;
            
            for (j = i; j < context->node_num; ++j)
            {
                context->node_index[j] = context->node_index[j + 1];
            }
        #endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/
        }
        else
        {
            ++i;
        }
    }

    srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_DEL,srv_bt_notify_refresh_reason_from_app, 0, 0);
}


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
void srv_bt_noti_data_delete_all(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;    
    srv_bt_noti_data_msg_node_struct *node;
    U32 i;

    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_DELETE_ALL, cntx_chnl);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    for (i = 0; i < context->node_num; ++i)        
    {
        node = &(node_list[i]);

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        srv_bt_noti_data_node_free(node);
#endif

#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
        FS_Delete(node->icon_file_path);
#endif
        FS_Delete(node->xml_file_path);
    }

    memset(context, 0, sizeof(srv_bt_noti_data_msg_context_struct));
    srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_DEL,srv_bt_notify_refresh_reason_from_service, 0, 0);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_get_noti_id_by_ancs_id
 * DESCRIPTION
 *  This function is to get msg info through msg index.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 * RETURNS
 *  srv_bt_noti_data_msg_node_struct*
 *****************************************************************************/
U32 srv_bt_noti_data_get_noti_id_by_ancs_id(srv_bt_cm_bt_addr *bt_addr, 
                                                                                        U32 ancs_id)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    srv_bt_noti_data_msg_node_struct *node;
    U32 noti_id=0;
    U32 i=0;
    U32 node_index;

    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_NOTI_ID_BY_ANCS_ID, ancs_id);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return NULL;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    //MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_INFO, cntx_chnl, ancs_id);
    for (i = 0; i < context->node_num; ++i)        
    {
        node_index = context->node_index[i];
        node = &(node_list[node_index]);
        
        if (node->ANCS_msg_id== ancs_id &&
            node->source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
        {
            noti_id = node->noti_id;
            break;
        }
    }

     MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_NOTI_ID_BY_ANCS_ID_RESULT, noti_id);
     
    return noti_id;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_delete_msg_by_noti_id_int
 * DESCRIPTION
 *  This function is to delete specified msg through msg index.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_noti_data_delete_msg_by_noti_id_int(srv_bt_cm_bt_addr *bt_addr,
                                                              U32 noti_id, 
                                                              srv_bt_notify_refresh_reason_enum  delete_reason)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    
    U32 del_node_index;
    U32 index;
    srv_bt_noti_data_msg_node_struct *node;
    U32 i;
    MMI_BOOL is_found = MMI_FALSE;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_DELETE_MSG_BY_NOTI_ID, cntx_chnl, noti_id);   


    for (i = 0; i < context->node_num; ++i)
    {
        del_node_index = context->node_index[i] ;

        node =&(node_list[del_node_index]);

        if ( node->noti_id== noti_id )
        {
            is_found = MMI_TRUE;
            index = i;
            break;
        }
    }

    if(!is_found)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, 
                  TRACE_GROUP_7, 
              "[BTNOTIFYSRV] error: node not found!");
        return;
    }

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    srv_bt_noti_data_group_handle_delete_msg(cntx_chnl, del_node_index);

    srv_bt_noti_data_node_free(&node_list[del_node_index]);
#endif

#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    FS_Delete(node->icon_file_path);
#endif
    FS_Delete(node->xml_file_path);
    memset(node, 0, sizeof(srv_bt_noti_data_msg_node_struct));

    // context->srv_bt_noti_data_list_mask[index] = 0;
    // [MAUI_03446114] delete notification show wrong msg, use wrong index
    context->srv_bt_noti_data_list_mask[del_node_index] = 0;

    for (i = index; i < context->node_num - 1; ++i)
    {
        context->node_index[i] = context->node_index[i + 1];
    }
    
    --context->node_num;
    srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_DEL, delete_reason, 0, noti_id);
}


/************ List Manager *************/
#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_listmgr_get_msg_num
 * DESCRIPTION
 *  This function is to get total msg number.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  S32
 *****************************************************************************/
U32 srv_bt_noti_data_listmgr_get_msg_num()
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_MSG_NUM, context->listmgr_node_num);
    
    return context->listmgr_node_num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_listmgr_get_msg_info_ref
 * DESCRIPTION
 *  This function is to get msg info reference.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :       [IN] msg index
 *  node_ref        :       [OUT] node ref
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_noti_data_listmgr_get_msg_info_ref(U32 index, 
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_msg_node_struct *node = NULL;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_MSG_INFO_REF, index);

    if(index >= context->listmgr_node_num)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_INVALID_INDEX, index);       
        return MMI_FALSE;
    }  
    
    node = srv_bt_noti_data_listmgr_get_msg_info(index);

    if(node != NULL && node_ref != NULL)
    {
        memcpy(node_ref, node, sizeof(srv_bt_noti_data_msg_node_struct));
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}

MMI_BOOL srv_bt_noti_data_listmgr_get_msg_info_ref_by_id(U32 noti_id, 
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    U32 index = 0;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_MSG_INFO_REF_BY_ID, noti_id);

    if(noti_id == 0)
    {      
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_INVALID_NOTI_ID);
        return MMI_FALSE;       
    }

    if(srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &index))
    {
        return srv_bt_noti_data_listmgr_get_msg_info_ref(index, node_ref);
    }
    else
    {
        return MMI_FALSE;
    }
        
    return MMI_TRUE;
}

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
 MMI_BOOL srv_bt_noti_data_listmgr_set_read_status(U32 noti_id, 
                                                                                  MMI_BOOL is_read)
{
    srv_bt_noti_data_msg_node_struct *node = NULL;
    U32 unified_index = 0;
    srv_bt_cm_bt_addr bt_addr;
    U32 solo_index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_SET_READ, noti_id, is_read);  
        
    if( srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &unified_index) )
    {
        node =  srv_bt_noti_data_listmgr_get_msg_info(unified_index);
    }

    if(node != NULL)
    {
        if( !srv_bt_noti_data_listmgr_locate_by_noti_id(noti_id, NULL, &solo_index, &bt_addr, NULL) )
        {
            return MMI_FALSE;
        }
                                                                                                           
        return srv_bt_noti_data_set_read_status(&bt_addr, solo_index, is_read);
    }
    else
    {
        return MMI_FALSE;
    }
}

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
 MMI_BOOL srv_bt_noti_data_listmgr_set_all_as_read()
{ 
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    U32 chnnl_num;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_SET_ALL_READ);  

    for(chnnl_num=0; chnnl_num<BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        context = &srv_bt_noti_data_msg_context[chnnl_num];
        node_list = &(srv_bt_noti_data_node_list[chnnl_num][0]);

        if( context->node_num > 0)
        {
            srv_bt_noti_data_set_all_as_read(&(node_list[context->node_index[0]].bt_addr));    
        }
    }    

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_listmgr_get_unread_num
 * DESCRIPTION
 *  This function is to get the unread msg num.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
U32 srv_bt_noti_data_listmgr_get_unread_num()
{ 
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    U32 chnnl_num;
    U32 unread_num;

    unread_num = 0;
    
    for(chnnl_num = 0; chnnl_num < BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        context = &srv_bt_noti_data_msg_context[chnnl_num];
        node_list = &(srv_bt_noti_data_node_list[chnnl_num][0]);

        if( context->node_num > 0)
        {   
            srv_bt_noti_data_msg_node_struct *node;
            U32 i;
        
            S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(&(node_list[context->node_index[0]].bt_addr));
            
            if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
            {
                continue;
            }
                
            for (i = 0; i < context->node_num; ++i)        
            {
                node = &(node_list[context->node_index[i]]);
                if (node->is_read == MMI_FALSE)
                {
                    unread_num++;
                }
            }        
        }
    }    

    return unread_num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_listmgr_get_read_status
 * DESCRIPTION
 *  This function is to get the read status of one msg.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 *  index           :        [IN] msg index
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
 MMI_BOOL srv_bt_noti_data_listmgr_get_read_status(U32 noti_id)
{
    srv_bt_noti_data_msg_node_struct *node = NULL;
    U32 index = 0;
    MMI_BOOL is_read = MMI_FALSE;
    srv_bt_cm_bt_addr bt_addr;
    U32 solo_index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_READ, noti_id);  
        
    if( srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &index) )
    {
        node =  srv_bt_noti_data_listmgr_get_msg_info(index);
    }

    if(node != NULL)
    {
        if( !srv_bt_noti_data_listmgr_locate_by_noti_id(noti_id, NULL, &solo_index, &bt_addr, NULL) )
        {
            return MMI_FALSE;
        }
        
        is_read =  srv_bt_noti_data_get_read_status(&bt_addr, solo_index);
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_READ_RESULT, is_read);  
    
    return is_read;

}

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
static void srv_bt_noti_data_listmgr_delete_msg_int(U32 noti_id, srv_bt_notify_refresh_reason_enum  delete_reason)
{
    srv_bt_noti_data_msg_node_struct *node = NULL;
    U32 unified_index = 0;
    srv_bt_cm_bt_addr bt_addr;
    U32 solo_index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_DELETE_MSG, noti_id);  
        
    if( srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &unified_index) )
    {
        node =  srv_bt_noti_data_listmgr_get_msg_info(unified_index);
    }

    if(node != NULL)
    {
        if( !srv_bt_noti_data_listmgr_locate_by_noti_id(noti_id, NULL, &solo_index, &bt_addr, NULL) )
        {
            return ; //MMI_FALSE;
        }
                                                                                                           
        srv_bt_noti_data_delete_msg_int(&bt_addr, solo_index, delete_reason);
        return;
    }
    else
    {
        return; // MMI_FALSE;
    }

}

void srv_bt_noti_data_listmgr_delete_msg(U32 noti_id)
{
    srv_bt_noti_data_listmgr_delete_msg_int(noti_id, srv_bt_notify_refresh_reason_from_app);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_noti_data_listmgr_delete_all
 * DESCRIPTION
 *  This function is to delete all msgs.
 * PARAMETERS
 *  bt_addr         :       [IN] bt device address
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_noti_data_listmgr_delete_all()
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    U32 chnnl_num;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_DELETE_ALL);  

    for(chnnl_num=0; chnnl_num<BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        context = &srv_bt_noti_data_msg_context[chnnl_num];
        node_list = &(srv_bt_noti_data_node_list[chnnl_num][0]);

        if( context->node_num > 0)
        {
            srv_bt_noti_data_delete_all(&(node_list[context->node_index[0]].bt_addr));    
        }
    }    

    return;
}

/****** internal functions ******/

static void srv_bt_noti_data_listmgr_send_refresh(srv_bt_cm_bt_addr *bt_addr, 
    srv_bt_notify_refresh_type refresh_type, 
    srv_bt_notify_refresh_reason_enum refresh_reason,
    U32 index,
    U32 noti_id)
{
    srv_bt_noti_refresh_evt_struct event;

    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_REFRESH);
    event.refresh_type = refresh_type;
    event.index = index;
    event.noti_id= noti_id;
    event.refresh_reason = refresh_reason;
    event.is_listmgr = MMI_TRUE;
    if(bt_addr != NULL)
        memcpy(&event.bt_addr, bt_addr, sizeof(srv_bt_cm_bt_addr));
    else
        memset(&event.bt_addr, 0, sizeof(srv_bt_cm_bt_addr));
    MMI_FRM_CB_EMIT_POST_EVENT(&event);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_SEND_REFRESH, refresh_type, noti_id, refresh_reason, MMI_TRUE);
}

static void srv_bt_noti_data_listmgr_refresh_data(srv_bt_notify_refresh_type refresh_type,
        srv_bt_notify_refresh_reason_enum refresh_reason,
        U32 noti_id)
{
    srv_bt_noti_data_msg_context_struct *sContext;
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32 chnnl_num, solo_index, node_index;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_REFRESH_DATA);

    uContext = &srv_bt_noti_data_listmgr_context;
    uContext->listmgr_node_num = 0;
        
    for(chnnl_num=0; chnnl_num<BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        sContext = &srv_bt_noti_data_msg_context[chnnl_num];
        for(solo_index=0; solo_index<sContext->node_num; solo_index++)
        {
            node_index = sContext->node_index[solo_index];
            uContext->listmgr_node[uContext->listmgr_node_num].node_index = node_index;
            uContext->listmgr_node[uContext->listmgr_node_num].chnnl_num = chnnl_num;
            uContext->listmgr_node_num++;               
        }      
    }    

    srv_bt_noti_data_listmgr_list_sort();    
    srv_bt_noti_data_listmgr_list_print();
    
    srv_bt_noti_data_listmgr_send_refresh(NULL,refresh_type,refresh_reason,0,noti_id);
}


S32 srv_bt_noti_data_listmgr_get_latest_unread_noti_id()
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_msg_node_struct *node = NULL;
    srv_bt_noti_data_listmgr_node_struct *listmgr_node = NULL;
    U32 i = 0;
    S32 noti_id = -1;

    for(i = 0; i< (context->listmgr_node_num); i++)
    {
        listmgr_node = &(context->listmgr_node[i]);
        node =  &(srv_bt_noti_data_node_list[listmgr_node->chnnl_num][listmgr_node->node_index]);
        
        if(!node->is_read)
        {
            noti_id = (S32)node->noti_id;
            break;
        }
    }

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] get_latest_unread_noti_id, noti_id:%d!",
              noti_id);
    return noti_id;
}


static srv_bt_noti_data_msg_node_struct * srv_bt_noti_data_listmgr_get_msg_info(U32 index)
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_msg_node_struct *node = NULL;
    srv_bt_noti_data_listmgr_node_struct *listmgr_node = NULL;
   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_MSG_INFO, index, context->listmgr_node_num);

    if(index >= context->listmgr_node_num)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_INVALID_INDEX, index);       
        return NULL;
    }  
    
    listmgr_node = &(context->listmgr_node[index]);
    node =  &(srv_bt_noti_data_node_list[listmgr_node->chnnl_num][listmgr_node->node_index]);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_MSG_INFO_FOUND, listmgr_node->chnnl_num, listmgr_node->node_index);
    
    return node;
}

static MMI_BOOL srv_bt_noti_data_listmgr_get_index_by_noti_id(U32 noti_id, U32 *index)
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_msg_node_struct *node = NULL;
    srv_bt_noti_data_listmgr_node_struct *listmgr_node = NULL;
    U32 i=0;
    MMI_BOOL is_found = MMI_FALSE;    

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_INDEX_BY_NOTI_ID, noti_id);

    *index = (U32)-1;
        
    if(noti_id == 0)
    {      
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_INVALID_NOTI_ID);
        return MMI_FALSE;       
    }
    
    for(i=0; i< (context->listmgr_node_num); i++)
    {
        listmgr_node = &(context->listmgr_node[i]);
        node =  &(srv_bt_noti_data_node_list[listmgr_node->chnnl_num][listmgr_node->node_index]);
        
        if(node->noti_id == noti_id)
        {
            is_found = MMI_TRUE;
            *index = i;
        }           
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_GET_INDEX_BY_NOTI_ID_FOUND, *index);
    
    return is_found;
}

static MMI_BOOL srv_bt_noti_data_listmgr_locate_by_noti_id(U32 noti_id, 
                                                                     U32 *unified_index,
                                                                     U32 *solo_index,
                                                                     srv_bt_cm_bt_addr *bt_addr,
                                                                     U32 *chnnl_num)
{
    srv_bt_noti_data_msg_node_struct * node = NULL;
    U32 uIndex, sIndex;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_LOCATE_NODE, noti_id);  
        
    if( srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &uIndex) )
    {
        node = srv_bt_noti_data_listmgr_get_msg_info(uIndex);
    }

    if(node == NULL)
        return MMI_FALSE;

    if(unified_index)
    {
        *unified_index = uIndex;      
    }


    {      
        srv_bt_noti_data_msg_context_struct *context;
        srv_bt_noti_data_msg_node_struct *node_list;
        U32 index;
        srv_bt_noti_data_msg_node_struct * solo_node = NULL;
        U32 i;
        context = &srv_bt_noti_data_msg_context[node->chnnl_num];
        node_list = &(srv_bt_noti_data_node_list[node->chnnl_num][0]);
        
        for (i = 0; i < context->node_num; ++i)
        {
            index = context->node_index[i] ;
            solo_node =&(node_list[index]);

            if(solo_node == node)
            {
                break;
            }            
        }

        if(i<=context->node_num)
        {
            //found
            if(solo_index)
            {
                *solo_index = i;
            }
            sIndex = i;
        }
        else
        {
            *solo_index = 0;
            sIndex = 0;
            MMI_ASSERT(0);
        }
    }

    if(bt_addr)
    {
        memcpy(bt_addr, &(node->bt_addr), sizeof(srv_bt_cm_bt_addr));
    }

    if(chnnl_num)
    {
        *chnnl_num = node->chnnl_num;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
        TRC_SRV_BT_NOTIFY_DATA_LISTMGR_LOCATE_NODE_RESULT, 
        uIndex ,
        sIndex,
        &(node->bt_addr),
        node->chnnl_num);  

    return MMI_TRUE;
}

#ifdef SRV_BT_MODIS_TEST
static void srv_bt_noti_data_listmgr_ut()
{
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32  unified_index;

    uContext = &srv_bt_noti_data_listmgr_context;
    
    for(unified_index=0; unified_index<uContext->listmgr_node_num; unified_index++)
    {
        srv_bt_noti_data_msg_node_struct node;
        srv_bt_noti_data_listmgr_get_msg_info_ref(unified_index, &node);
        srv_bt_noti_data_listmgr_get_msg_info_ref_by_id(node.noti_id, &node);
        srv_bt_noti_data_listmgr_set_read_status(node.noti_id, MMI_TRUE);
        srv_bt_noti_data_listmgr_get_read_status(node.noti_id);
        if( unified_index % 2 == 1)
            srv_bt_noti_data_listmgr_delete_msg(node.noti_id);
    }

    srv_bt_noti_data_listmgr_set_all_as_read();
    srv_bt_noti_data_listmgr_delete_all();
}
#endif

static void srv_bt_noti_data_listmgr_list_print()
{
    srv_bt_noti_data_msg_context_struct *sContext;
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32 chnnl_num, solo_index,unified_index,node_index;
    U32 index_print[5];
    U32 count = 0;

    uContext = &srv_bt_noti_data_listmgr_context;
            
    for(chnnl_num=0; chnnl_num<BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        sContext = &srv_bt_noti_data_msg_context[chnnl_num];

        for(solo_index=0; solo_index<5; solo_index++)
        {
            index_print[solo_index] = -1;
        }
        
        for(solo_index=0; solo_index<sContext->node_num; solo_index++)
        {
            node_index = sContext->node_index[solo_index];

            if(solo_index < 5)
                index_print[solo_index] =  node_index;
        } 
        
        MMI_TRACE(MMI_CONN_TRC_G7_BT, 
            TRC_SRV_BT_NOTIFY_DATA_LISTMGR_PRINT_CHANNLE_DATA, 
            chnnl_num ,
            sContext->node_num,
            index_print[0],index_print[1],index_print[2],index_print[3],index_print[4]);  

        
    } 

    for(unified_index=0; unified_index<uContext->listmgr_node_num; unified_index++)
    {
        node_index = uContext->listmgr_node[unified_index].node_index;

        if( count < 5)
        {
            index_print[count++] =  node_index;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, 
                TRC_SRV_BT_NOTIFY_DATA_LISTMGR_PRINT_LISTMGR_DATA, 
                uContext->listmgr_node_num,
                unified_index - 5,
                unified_index - 1,
                index_print[0],index_print[1],index_print[2],index_print[3],index_print[4]); 
            count = 0;
            index_print[count++] =  node_index;
        }
    }

    if(count > 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, 
                TRC_SRV_BT_NOTIFY_DATA_LISTMGR_PRINT_LISTMGR_DATA, 
                uContext->listmgr_node_num,
                unified_index - count ,
                unified_index - 1 ,
                index_print[0],index_print[1],index_print[2],index_print[3],index_print[4]); 
    }

}

static void srv_bt_noti_data_listmgr_list_sort()
{
#if 1
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32  chnnl_num,unified_index,unified_index2, node_index;
    srv_bt_noti_data_msg_node_struct *node_list = NULL;
    srv_bt_noti_data_msg_node_struct *node, *node2 = NULL;
    MMI_BOOL flag = MMI_FALSE;

    uContext = &srv_bt_noti_data_listmgr_context;

    if(uContext->listmgr_node_num == 0)
        return;

     for(unified_index=0; unified_index<uContext->listmgr_node_num-1; unified_index++)
    {
        flag = MMI_FALSE;
        
        for(unified_index2=uContext->listmgr_node_num-1; unified_index2>unified_index; unified_index2--)
        {
            node_index = uContext->listmgr_node[unified_index2-1].node_index;
            chnnl_num = uContext->listmgr_node[unified_index2-1].chnnl_num;
            node_list= &(srv_bt_noti_data_node_list[chnnl_num][0]);
            node = &(node_list[node_index]);        
        
            node_index = uContext->listmgr_node[unified_index2].node_index;
            chnnl_num = uContext->listmgr_node[unified_index2].chnnl_num;
            node_list= &(srv_bt_noti_data_node_list[chnnl_num][0]);
            node2 = &(node_list[node_index]);  
        
            if(node2->timestamp > node->timestamp)
            {
                //swap
                node_index = uContext->listmgr_node[unified_index2-1].node_index;
                chnnl_num = uContext->listmgr_node[unified_index2-1].chnnl_num;

                
                uContext->listmgr_node[unified_index2-1].node_index =  uContext->listmgr_node[unified_index2].node_index;
                uContext->listmgr_node[unified_index2-1].chnnl_num = uContext->listmgr_node[unified_index2].chnnl_num;

                uContext->listmgr_node[unified_index2].node_index = node_index;
                uContext->listmgr_node[unified_index2].chnnl_num = chnnl_num;        
                
                flag = MMI_TRUE;
            }
        }

        if(flag == MMI_FALSE)
        {
            break;
        }
    }
     
    for(unified_index=0; unified_index<uContext->listmgr_node_num; unified_index++)
    {
        node_index = uContext->listmgr_node[unified_index].node_index;
        chnnl_num = uContext->listmgr_node[unified_index].chnnl_num;
        node_list= &(srv_bt_noti_data_node_list[chnnl_num][0]);
        node = &(node_list[node_index]);
        
        MMI_PRINT(MOD_MMI_CONN_APP, 
                                  TRACE_GROUP_7, 
                                  "[BTNOTIFYSRV] ud:%d, nd:%d, cn:%d, sr:%d, ni:%d, ai:%d, ts:%d",
                                  unified_index,
                                  node_index,
                                  chnnl_num,
                                  node->source,
                                  node->noti_id,
                                  node->ANCS_msg_id,
                                  node->timestamp);
       
    }
#endif
}

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__

U32 srv_bt_noti_data_listmgr_get_group_num()
{
    return srv_bt_noti_data_listmgr_context.listmgr_group_node_num;
}


void srv_bt_noti_data_listmgr_delete_msg_by_group(U32 index)
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_group_list_struct *node = NULL;
    srv_bt_noti_data_listmgr_node_struct *listmgr_node;
    srv_bt_noti_data_msg_node_struct *msg_list;
    U32 i,noti_num;

    MMI_PRINT(MOD_MMI_CONN_APP,
        TRACE_GROUP_7, 
        "[BTNOTIFYSRV] delete_group, index: %d",
        index);

    if(index >= context->listmgr_node_num)
    {
        MMI_PRINT(MOD_MMI_CONN_APP,
        TRACE_GROUP_7, 
        "[BTNOTIFYSRV] delete_group index_error!, index: %d",
        index);   
        return;
    }  

    listmgr_node = &(context->listmgr_group_node[index]);
    node =  &(srv_bt_noti_data_group_list[listmgr_node->chnnl_num][listmgr_node->node_index]);
    msg_list = &(srv_bt_noti_data_node_list[listmgr_node->chnnl_num][0]);
    noti_num = node->noti_num;
    for (i = 0; i < noti_num; i++)
    {
        U32 noti_id;
        noti_id = msg_list[node->noti_index[0].node_index].noti_id;
        srv_bt_noti_data_listmgr_delete_msg_int(noti_id, srv_bt_notify_refresh_reason_from_app);
    }
}


srv_bt_noti_data_group_list_struct  *srv_bt_noti_data_listmgr_get_group_info_ref(U32 index)
{
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_group_list_struct *node = NULL;
    srv_bt_noti_data_listmgr_node_struct *listmgr_node;
    
    MMI_PRINT(MOD_MMI_CONN_APP,
        TRACE_GROUP_7, 
        "[BTNOTIFYSRV] get_group_info, index: %d",
        index);

    if(index >= context->listmgr_group_node_num)
    {
        MMI_PRINT(MOD_MMI_CONN_APP,
        TRACE_GROUP_7, 
        "[BTNOTIFYSRV] get_group_info index_error!, index: %d",
        index);   
        return NULL;
    }  
    

    listmgr_node = &(context->listmgr_group_node[index]);
    node =  &(srv_bt_noti_data_group_list[listmgr_node->chnnl_num][listmgr_node->node_index]);

    if(node != NULL)
    {
        return node;
    }
    else
    {
        return NULL;
    }
}


static void srv_bt_noti_data_listmgr_refresh_group_data(srv_bt_notify_refresh_type refresh_type,
        srv_bt_notify_refresh_reason_enum refresh_reason)
{
    srv_bt_noti_data_msg_context_struct *sContext;
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32 chnnl_num, solo_index, node_index;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_LISTMGR_REFRESH_DATA);

    uContext = &srv_bt_noti_data_listmgr_context;
    uContext->listmgr_group_node_num = 0;
        
    for(chnnl_num=0; chnnl_num<BT_NOTIFY_MAX_CHANNEL; chnnl_num++)
    {
        sContext = &srv_bt_noti_data_msg_context[chnnl_num];
        for(solo_index=0; solo_index<sContext->group_num; solo_index++)
        {
            node_index = sContext->group_index[solo_index];
            uContext->listmgr_group_node[uContext->listmgr_group_node_num].node_index = node_index;
            uContext->listmgr_group_node[uContext->listmgr_group_node_num].chnnl_num = chnnl_num;
            uContext->listmgr_group_node_num++;               
        }      
    }    

    srv_bt_noti_data_listmgr_group_list_sort();    
    //srv_bt_noti_data_listmgr_list_print();
    
    //srv_bt_noti_data_listmgr_send_refresh(NULL,refresh_type,refresh_reason,0,noti_id);
}


static void srv_bt_noti_data_listmgr_group_list_sort()
{
#if 1
    srv_bt_noti_data_listmgr_context_struct *uContext;
    U32  chnnl_num,unified_index,unified_index2, node_index;
    srv_bt_noti_data_group_list_struct *node_list = NULL;
    srv_bt_noti_data_group_list_struct *node, *node2 = NULL;
    MMI_BOOL flag = MMI_FALSE;

    uContext = &srv_bt_noti_data_listmgr_context;

    if(uContext->listmgr_group_node_num == 0)
        return;

     for(unified_index=0; unified_index<uContext->listmgr_group_node_num-1; unified_index++)
    {
        flag = MMI_FALSE;
        
        for(unified_index2=uContext->listmgr_group_node_num-1; unified_index2>unified_index; unified_index2--)
        {
            node_index = uContext->listmgr_group_node[unified_index2-1].node_index;
            chnnl_num = uContext->listmgr_group_node[unified_index2-1].chnnl_num;
            node_list= &(srv_bt_noti_data_group_list[chnnl_num][0]);
            node = &(node_list[node_index]);        
        
            node_index = uContext->listmgr_group_node[unified_index2].node_index;
            chnnl_num = uContext->listmgr_group_node[unified_index2].chnnl_num;
            node_list= &(srv_bt_noti_data_group_list[chnnl_num][0]);
            node2 = &(node_list[node_index]);  
        
            if(node2->latest_timestamp > node->latest_timestamp)
            {
                //swap
                node_index = uContext->listmgr_group_node[unified_index2-1].node_index;
                chnnl_num = uContext->listmgr_group_node[unified_index2-1].chnnl_num;

                
                uContext->listmgr_group_node[unified_index2-1].node_index =  uContext->listmgr_group_node[unified_index2].node_index;
                uContext->listmgr_group_node[unified_index2-1].chnnl_num = uContext->listmgr_group_node[unified_index2].chnnl_num;

                uContext->listmgr_group_node[unified_index2].node_index = node_index;
                uContext->listmgr_group_node[unified_index2].chnnl_num = chnnl_num;        
                
                flag = MMI_TRUE;
            }
        }

        if(flag == MMI_FALSE)
        {
            break;
        }
    }
     
    for(unified_index=0; unified_index<uContext->listmgr_node_num; unified_index++)
    {
        node_index = uContext->listmgr_group_node[unified_index].node_index;
        chnnl_num = uContext->listmgr_group_node[unified_index].chnnl_num;
        node_list= &(srv_bt_noti_data_group_list[chnnl_num][0]);
        node = &(node_list[node_index]);
        
        MMI_PRINT(MOD_MMI_CONN_APP, 
                                  TRACE_GROUP_7, 
                                  "[BTNOTIFYSRV] GroupSort,ud:%d, nd:%d, cn:%d, ts:%d",
                                  unified_index,
                                  node_index,
                                  chnnl_num,
                                  node->latest_timestamp);
       
    }
#endif
}

S32 srv_bt_noti_data_listmgr_get_group_idx(U32 chnnl_num, U32 node_index)
{
    U32 i = 0;
    srv_bt_noti_data_listmgr_context_struct *listmgr_context = &srv_bt_noti_data_listmgr_context;
    for (i = 0; i < listmgr_context->listmgr_node_num; i++)
    {
        if (listmgr_context->listmgr_group_node[i].chnnl_num == chnnl_num &&
            listmgr_context->listmgr_group_node[i].node_index == node_index)
        {
            return i;
        }
    }

    return -1;
}

srv_bt_noti_data_group_list_struct *srv_bt_noti_data_listmgr_get_group_info_ref_by_id(S32 app_id,U8 *group_id, U32 *index)
{
    U32 i = 0, j = 0;
    srv_bt_noti_data_group_list_struct *list;
    srv_bt_noti_data_msg_context_struct *context;

    for(j = 0; j < BT_NOTIFY_MAX_CHANNEL; j++)
    {
        list = &(srv_bt_noti_data_group_list[j][0]);
        context = &srv_bt_noti_data_msg_context[j];

        for(i = 0; i < context->group_num; i++)
        {
            if (app_id == list[context->group_index[i]].app_id &&
                (strcmp(group_id, list[context->group_index[i]].group_id) == 0))
            {
                *index = srv_bt_noti_data_listmgr_get_group_idx(j, context->group_index[i]);
                //MMI_ASSERT(*index);               
                return &list[context->group_index[i]];
            }
        }
    }
    *index = 0;
    return NULL;
}


MMI_BOOL srv_bt_noti_data_listmgr_action_operate(U32 noti_id, WCHAR *action_id)
{
    srv_bt_notify_data_struct* action_node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];
    srv_bt_cm_bt_addr *bt_addr;
    srv_bt_noti_data_listmgr_context_struct *context = &srv_bt_noti_data_listmgr_context;
    srv_bt_noti_data_msg_node_struct *node = NULL;
    U32 unified_index;

    

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] listmgr_action_operate,noti_id:%d, action_id:%s,",
              noti_id,
              action_id);

    if( srv_bt_noti_data_listmgr_get_index_by_noti_id(noti_id, &unified_index) )
    {
        node =  srv_bt_noti_data_listmgr_get_msg_info(unified_index);
    }

    if (node == NULL)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] listmgr_action_operate error,node = NULL");
        return MMI_FALSE;
    }
    bt_addr =  srv_bt_noti_get_bt_device_addr_by_conn_index(node->chnnl_num);
    
    do
    {
        action_node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (action_node == NULL)
        {
            break;
        }
        
        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }
        
        memset(action_node, 0, sizeof(srv_bt_notify_data_struct));
        action_node->header.category= srv_bt_notify_category_noti;
        action_node->header.subtype= srv_bt_notify_subtype_action_operate;
        action_node->header.action = srv_bt_notify_action_update; 
        action_node->header.msg_id = node->header.msg_id;
        action_node->mbody.action_operate.noti_id = node->header.msg_id;
        mmi_wcscpy(action_node->mbody.action_operate.action_id, action_id);

        MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] listmgr_action_operate,category:%d, subtype:%d, msg_id:%d",
              action_node->header.category,
              action_node->header.subtype,
              action_node->header.msg_id);
        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\update_action_operate_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);

        parse_ret = srv_bt_notify_xml_generator(xml_file_path, action_node);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_UPDATE_REMOTE_BLOCK_PARSE_RESULT, parse_ret);
        
        if (parse_ret == -1)
        {
            break;
        }          

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }
    
    if (action_node != NULL)
    {
        OslMfree(action_node);
    }
    
    return retval;
}

#endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/


#endif /*  __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__ */

static MMI_BOOL srv_bt_noti_data_create_msg(U8 cntx_chnl, 
                                            srv_bt_noti_data_msg_node_struct **node, 
                                            U32 *node_index)
{
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context[cntx_chnl];
    srv_bt_noti_data_msg_node_struct *node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);
#ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    srv_bt_noti_data_icon_struct *icon;
#endif

    U32 i;
    S32 new_node_index = -1;

    for (i = 0; i < SRV_BT_NOTI_MSG_LIST_MAX_NUM; ++i)
    {
        if (context->srv_bt_noti_data_list_mask[i] == 0)
        {
            new_node_index = i;
            context->srv_bt_noti_data_list_mask[i] = 1;
            break;
        }
    }

    if (new_node_index == -1)
    {
        /* replace the last one */
        srv_bt_cm_bt_addr *addr;
        srv_bt_noti_data_msg_node_struct *node_ref;
        
        new_node_index = context->node_index[context->node_num - 1];

        addr = srv_bt_noti_get_bt_device_addr(cntx_chnl);
        node_ref = srv_bt_noti_data_get_msg_info(addr, context->node_num - 1);
        srv_bt_noti_data_delete_msg_by_noti_id_int(addr,
                                                   node_ref->noti_id, 
                                                   srv_bt_notify_refresh_reason_from_service); 
        if (context->srv_bt_noti_data_list_mask[new_node_index] == 0)
        {
            context->srv_bt_noti_data_list_mask[new_node_index] = 1;
        }

    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        srv_bt_noti_data_node_free(&node_list[new_node_index]);
    #endif
    }

    for (i = context->node_num; i > 0; --i)
    {
        context->node_index[i] = context->node_index[i - 1];    
    }
    
    context->node_index[0] = new_node_index;
    ++context->node_num;

    *node = &(node_list[new_node_index]);
    *node_index = (U32)new_node_index;
    srv_bt_noti_data_init_msg(cntx_chnl, *node, *node_index);
#ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    icon = &(srv_bt_noti_data_icon_list[cntx_chnl][new_node_index]);
    memset(icon, 0, sizeof(srv_bt_noti_data_icon_struct));
    icon->icon_size = 0;
    (*node)->icon = icon;
#endif
      
    return MMI_TRUE;    
}


#ifdef __MMI_BT_NOTIFICATION_ENHANCE__

U32 srv_bt_noti_data_get_group_num(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_noti_data_msg_context_struct *context;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    context = &srv_bt_noti_data_msg_context[cntx_chnl];

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] get_group_num,group_num:%d",
              context->group_num);
    return context->group_num;
}

srv_bt_noti_data_group_list_struct* srv_bt_noti_data_get_group_info_ref(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_group_list_struct *group_list;
    srv_bt_noti_data_group_list_struct *node;
    U32 node_index;
    
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);

    if (srv_bt_noti_check_channel_valid(cntx_chnl) == MMI_FALSE)
    {
        return NULL;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    group_list = &(srv_bt_noti_data_group_list[cntx_chnl][0]);

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] get_group_info,chnl: %d, idx: %d",
              cntx_chnl,
              index);
        
    if (index >= context->group_num)
    {
        return NULL;
    }
    
    node_index = context->group_index[index];
    
    if (node_index >= BT_NOTIFY_MAX_GROUP_NUM)
    {
        return NULL;
    }
    
    node = &(group_list[node_index]);
    
    return node;
}


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
                                           srv_bt_noti_data_msg_node_struct *node_ref)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    srv_bt_noti_data_msg_node_struct *node;
    U32 node_index;

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return MMI_FALSE;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_INFO_REF, cntx_chnl, index_in_group);
    
    node_index = index_in_group;
    
    if (node_index >= SRV_BT_NOTI_MSG_LIST_MAX_NUM)
    {
        return MMI_FALSE;
    }
    
    node = &(node_list[node_index]);
    *node_ref = *node;
    
    return MMI_TRUE;
}


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
srv_bt_noti_data_msg_node_struct *srv_bt_noti_data_get_msg_info_in_group(S32 cntx_chnl, U32 index_in_group)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    srv_bt_noti_data_msg_node_struct *node;
    U32 node_index;

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return NULL;
    }
    
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_GET_MSG_INFO_REF, cntx_chnl, index_in_group);
    
    node_index = index_in_group;
    
    if (node_index >= SRV_BT_NOTI_MSG_LIST_MAX_NUM)
    {
        return NULL;
    }

    node = &(node_list[node_index]);
    
    return node;
}


static srv_bt_noti_data_group_list_struct *srv_bt_noti_data_get_group_by_noti_idx(U32 cntx_chnl, 
                                                                                    U32 noti_idx, 
                                                                                    U32 *group_indx, 
                                                                                    U32 *group_list_indx, 
                                                                                    U32 *group_noti_indx)
{
    U32 i,j,curr_group_index;
    srv_bt_noti_data_group_list_struct *list = &(srv_bt_noti_data_group_list[cntx_chnl][0]);
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context[cntx_chnl];
    srv_bt_noti_data_group_list_struct *node;

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] srv_bt_noti_data_get_group_by_noti_idx1,chnl: %d, idx: %d. curr_group_num: %d",
              cntx_chnl,
              noti_idx,
              context->group_num);
    for(i = 0; i < context->group_num; i++) 
    {
        curr_group_index = context->group_index[i];
        node = &(srv_bt_noti_data_group_list[cntx_chnl][curr_group_index]);
        for (j = 0; j < node->noti_num; j++)
        {
            if (noti_idx == node->noti_index[j].node_index)
            {
                if (group_indx != NULL)
                {
                    *group_indx = i;
                }
                if (group_list_indx != NULL)
                {
                    *group_list_indx = curr_group_index;
                }
                if (group_noti_indx != NULL)
                {
                    *group_noti_indx = j;
                }
                return node;
            }
        }
    }
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] srv_bt_noti_data_get_group_by_noti_idx_ERROR,chnl: %d, idx: %d",
              cntx_chnl,
              noti_idx);
    return NULL;
}


static srv_bt_noti_data_group_list_struct *srv_bt_noti_data_get_noti_group(U32 cntx_chnl, srv_bt_notify_noti_struct *noti)
{
    U32 i = 0;
    srv_bt_noti_data_group_list_struct *list = &(srv_bt_noti_data_group_list[cntx_chnl][0]);
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context[cntx_chnl];

    for(i = 0; i < context->group_num; i++)
    {
        if ((strcmp(noti->group_id, list[context->group_index[i]].group_id) == 0) &&
             (mmi_wcscmp(noti->sender, list[context->group_index[i]].sender) == 0))
        {
            return &list[context->group_index[i]];
        }
    }
    return NULL;
}


static srv_bt_noti_data_group_list_struct *srv_bt_noti_data_get_sms_group(U32 cntx_chnl)
{
    U32 i = 0;
    srv_bt_noti_data_group_list_struct *list = &(srv_bt_noti_data_group_list[cntx_chnl][0]);
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context[cntx_chnl];

    for(i = 0; i < context->group_num; i++)
    {
        if (list[context->group_index[i]].app_id == BT_NOTI_SRV_DATA_SMS_APP_ID)
        {
            return &list[context->group_index[i]];
        }
    }
    return NULL;
}


static void srv_bt_noti_data_create_group(U32 cntx_chnl, 
                                                void *data, 
                                                U32 noti_index,
                                                srv_bt_notify_subtype_enum sub_type)
{
    srv_bt_noti_data_group_list_struct *group_node;
    U32 i;
    S32 new_node_index = -1;
    srv_bt_notify_noti_struct *noti = NULL;
    srv_bt_notify_sms_struct *sms = NULL;
    srv_bt_noti_data_msg_context_struct *context = &srv_bt_noti_data_msg_context[cntx_chnl];

    if (sub_type == srv_bt_notify_subtype_sms)
    {
        sms = (srv_bt_notify_sms_struct *)data;
    }
    else 
    {
        noti = (srv_bt_notify_noti_struct *)data;
    }
      
	MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] create_group,subtype: %d",
              sub_type);
    for (i = 0; i < BT_NOTIFY_MAX_GROUP_NUM; ++i)
    {
        if (context->srv_bt_noti_group_list_mask[i] == 0)
        {
            new_node_index = i;
            context->srv_bt_noti_group_list_mask[i] = 1;
            break;
        }
    }

    if (new_node_index == -1)
    {
    	MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] create_group,group_not_enough");
        /* replace the last one */
        new_node_index = context->group_index[context->node_num - 1];
        --context->group_num;        
    }

    for (i = context->group_num; i > 0; --i)
    {
        context->group_index[i] = context->group_index[i - 1];    
    }

    context->group_index[0] = new_node_index;
    ++context->group_num;
    
    group_node = &srv_bt_noti_data_group_list[cntx_chnl][new_node_index];

    memset(group_node->sender, 0, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
    memset(group_node->group_id, 0, BT_NOTIFY_SENDER_LENTH);
    
    if (sub_type == srv_bt_notify_subtype_sms)
    {
        mmi_wcscpy(group_node->sender, sms->sender);
        group_node->app_id = BT_NOTI_SRV_DATA_SMS_APP_ID;
        group_node->latest_timestamp = sms->timestamp; 
    }
    else
    {
        mmi_wcscpy(group_node->sender, noti->sender);
        group_node->app_id = noti->app_id;
        if (strlen(noti->group_id) > 1)
        {
            strcpy(group_node->group_id, noti->group_id);
        }
        else
        {
            srv_bt_notify_itoa(group_node->group_id, context->group_count, 10);
        }
        group_node->latest_timestamp = noti->timestamp;
    }
    
    context->group_count++;
    group_node->noti_index[0].node_index = noti_index;
    group_node->noti_index[0].chnnl_num = cntx_chnl;
    group_node->noti_num = 1;  
          
}



static MMI_BOOL srv_bt_noti_data_handle_group(U32 cntx_chnl, 
                                                    srv_bt_noti_data_msg_node_struct *node, 
                                                    void *data,
                                                    U32 node_index)
{
    srv_bt_noti_data_group_list_struct *group_node = NULL;
    srv_bt_notify_noti_struct *noti = NULL;
    srv_bt_notify_sms_struct *sms = NULL;
    U32 timestamp = 0;

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] handle_group,chnl: %d, idx: %d",
              cntx_chnl,
              node_index);
    /*if (node->header.subtype == srv_bt_notify_subtype_sms)
    {
        sms = (srv_bt_notify_sms_struct *)data;
        group_node = srv_bt_noti_data_get_sms_group(cntx_chnl);
        timestamp = sms->timestamp;
    }
    else */ /*make sms in a group*/
    {
        group_node = srv_bt_noti_data_get_group_by_noti_idx(cntx_chnl, node_index,NULL, NULL, NULL);
        if (group_node != NULL)
        {
            MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] handle_group, exist return.");
            return MMI_FALSE;
        }
        noti = (srv_bt_notify_noti_struct *)data;
        if(strlen(noti->group_id) <= 1)
        {
            srv_bt_noti_data_create_group(cntx_chnl, data, node_index, node->header.subtype);
            return MMI_TRUE;
        }
        group_node = srv_bt_noti_data_get_noti_group(cntx_chnl, noti);
        timestamp = noti->timestamp;
    }
    strcpy(node->group_id, noti->group_id);


    if (group_node != NULL)
    {
        U32 i;
        U32 first_index;
        
        if(group_node->noti_num < SRV_BT_NOTI_MSG_LIST_MAX_NUM)
        {
            first_index = group_node->noti_num;
            group_node->noti_num++;                     
        }
        else/*replace the last one*/
        {
            first_index = (group_node->noti_num - 1);
        }
        for (i = first_index; i > 0; i--)
        {
            group_node->noti_index[i].node_index = group_node->noti_index[i-1].node_index;
            group_node->noti_index[i].chnnl_num = group_node->noti_index[i-1].chnnl_num;
        }
        group_node->noti_index[0].node_index = node_index;
        group_node->noti_index[0].chnnl_num = cntx_chnl;
        group_node->latest_timestamp = timestamp;
    }
    else
    {
        srv_bt_noti_data_create_group(cntx_chnl, data, node_index, node->header.subtype);
    }
    return MMI_TRUE;
}

static void srv_bt_noti_data_group_handle_delete_msg(S32 cntx_chnl, U32 del_node_index)
{
    srv_bt_noti_data_group_list_struct *group_node;
    srv_bt_noti_data_msg_context_struct *context;
    U32 group_idx, group_noti_idx, group_list_idx;
    U32 i,j;

    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] srv_bt_noti_data_group_handle_delete_msg,chnl: %d, idx: %d",
              cntx_chnl,
              del_node_index);
    group_node = srv_bt_noti_data_get_group_by_noti_idx(cntx_chnl, del_node_index, &group_idx, &group_list_idx, &group_noti_idx);
    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    //MMI_ASSERT(group_node);
    if (group_node == NULL)
    {
	MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] err!donnot found group,chnl: %d, idx: %d",
              cntx_chnl,
              del_node_index);
        return;
    }
    if(group_node->noti_num > 1)
    {
        for(j = group_noti_idx; j < group_node->noti_num - 1; j++)
        {
            group_node->noti_index[j] = group_node->noti_index[j+1];
        }
        group_node->noti_num--;
    }
    else
    {
        context->srv_bt_noti_group_list_mask[group_list_idx] = 0;

        for(i = group_idx; i < context->group_num - 1; i++)
        {
            context->group_index[i] = context->group_index[i+1];
        }
        --context->group_num;
    }
}

void srv_bt_noti_data_delete_msg_by_group(srv_bt_cm_bt_addr *bt_addr, U32 index)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_group_list_struct *group_list;
    srv_bt_noti_data_msg_node_struct *msg_list;
    
    srv_bt_noti_data_group_list_struct *group_node;
    U32 group_list_idx;
    U32 i;

    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    group_list = &(srv_bt_noti_data_group_list[cntx_chnl][0]);
    msg_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);

    group_list_idx = context->group_index[index];
    group_node = &group_list[group_list_idx];

    for (i = 0; i < group_node->noti_num; i++)
    {
        U32 noti_id;
        noti_id = msg_list[group_node->noti_index[i].node_index].noti_id;
        srv_bt_noti_data_delete_msg_by_noti_id_int(bt_addr,noti_id,srv_bt_notify_refresh_reason_from_app);
    }
}


#endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/

static void srv_bt_noti_data_parse_xml_callback(srv_bt_notify_parse_para para_flag, void *data, void* user_data, MMI_BOOL ret_val)
{
    srv_bt_notify_noti_struct *noti;
    srv_bt_notify_sms_struct *sms;
    srv_bt_notify_call_struct *call;
    srv_bt_noti_data_msg_node_struct *node;
    U32 user_para = (U32)user_data;
    U32 node_index = user_para >> 16;
    U32 cntx_chnl = (user_para & 0xFFFF);
    srv_bt_cm_bt_addr *bt_addr = srv_bt_noti_get_bt_device_addr(cntx_chnl);
    U32 i = 0;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              TRC_SRV_BT_NOTIFY_DATA_PARSE_XML_CALLBACK, 
              cntx_chnl,
              para_flag, 
              data, 
              user_data, 
              ret_val);

    do
    {    
        if (MMI_FALSE == ret_val)
        {
            srv_bt_noti_data_delete_msg_int(bt_addr, node_index,srv_bt_notify_refresh_reason_from_service);
            break;
        }
        
        if ((para_flag != srv_bt_notify_parse_call_body) &&
        #ifndef SMS_IN_NOTIFICATION    
             (para_flag != srv_bt_notify_parse_sms_body) &&  
        #endif     
            (srv_bt_noti_data_msg_context[cntx_chnl].srv_bt_noti_data_list_mask[node_index] == 0))
        {
            /* invalid node index, maybe the node has been cleared while waiting for parer's call back, 
               such as receiving EVT_ID_SRV_BT_NOTI_DEL_MSG
            */
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_PARSE_XML_CALLBACK_ERR_1, cntx_chnl);
            break;
        }
            
        if (para_flag == srv_bt_notify_parse_noti_body)
        {
            node = &(srv_bt_noti_data_node_list[cntx_chnl][node_index]);
            noti = (srv_bt_notify_noti_struct*)data;
            node->timestamp = noti->timestamp;
            /* app id */
            node->app_id = noti->app_id;            
           
            mmi_wcscpy(node->sender, noti->sender);
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            node->action_num = noti->action_number;
            srv_bt_noti_data_node_free(node);
            node->page_num = noti->page_num;
            node->page_content = noti->page_content;
            for (i = 0; i < node->action_num; i++) 
            {
                mmi_wcscpy(node->noti_action[i].action_id, noti->noti_action[i].action_id);
                mmi_wcscpy(node->noti_action[i].action_name, noti->noti_action[i].action_name);
                MMI_PRINT(MOD_MMI_CONN_APP, 
                              TRACE_GROUP_7, 
                              "[BTNOTIFYSRV] parse callback,action_id: %s, action_name: %s",
                              node->noti_action[i].action_id,
                              node->noti_action[i].action_name);
            }
            srv_bt_noti_data_handle_group(cntx_chnl, node, noti, node_index);
#else
            mmi_wcscpy(node->title, noti->title);
            mmi_wcscpy(node->ticker_text, noti->ticker_text);           
#endif
            
#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
            FS_Delete(node->icon_file_path);
            
            if (FS_Rename(noti->icon_path, node->icon_file_path) != FS_NO_ERROR) 
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_PARSE_XML_CALLBACK_ERR_2, cntx_chnl);
            }
#endif

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            if (srv_bt_noti_data_flag.is_new_msg)
            {
                srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_NEW, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
            }
            else
            {
                srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_UPDATE, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
            }
#else
            srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_NEW, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
#endif                  
        }
        else if (para_flag == srv_bt_notify_parse_sms_body)
        {
            sms = (srv_bt_notify_sms_struct*)data;
    #ifdef SMS_IN_NOTIFICATION
            node = &(srv_bt_noti_data_node_list[cntx_chnl][node_index]);                 
            node->timestamp = sms->timestamp;
            mmi_wcscpy(node->sender, sms->sender);
            mmi_wcscpy(node->send_number, sms->send_number);         
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            node->page_content = sms->page_content;
            srv_bt_noti_data_handle_group(cntx_chnl, node, sms, node_index);
            /*if it's the new msg, send NEW, else send update*/
            if(srv_bt_noti_data_flag.is_new_msg)
            {
                srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_NEW, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
            }
            else
            {
                srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_UPDATE, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
            }
        #else
                srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_NEW, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);
        #endif
    #else
         #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            srv_bt_noti_notify_new_sms(bt_addr, 
                                    sms->page_content->content, 
                                    sms->timestamp, 
                                    sms->send_number,
                                    sms->sender); 
            kal_adm_free(srv_bt_noti_data_get_mem_pool_id(), sms->page_content);
        #else
            srv_bt_noti_notify_new_sms(bt_addr, 
                                    sms->content, 
                                    sms->timestamp, 
                                    sms->send_number,
                                    sms->sender);
        #endif
    #endif
        }
        else if (para_flag == srv_bt_notify_parse_call_body)
        {
            call = (srv_bt_notify_call_struct*)data;
            srv_bt_noti_notify_missed_call( bt_addr, 
                                                            call->missed_call_count, 
                                                            call->timestamp, 
                                                            call->send_number,
                                                            call->sender);       
        }
    } while(0);

    srv_bt_noti_data_msg_context[cntx_chnl].is_waiting_parser_callback = MMI_FALSE;
    //OslMfree(data);
}

static void srv_bt_noti_data_handle_new_msg(srv_bt_noti_event_info_new *event_info)
{
    srv_bt_noti_data_msg_node_struct *node=NULL;
    S32 node_index;
    srv_bt_notify_parse_para para_flag = srv_bt_notify_parse_none;
    srv_bt_notify_body_union *body; 
    S32 parse_ret  = -1;
    U32 user_para;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(&event_info->bt_addr);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_HANDLE_NEW_MSG, cntx_chnl);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    }
    
    if (srv_bt_noti_data_msg_context[cntx_chnl].is_waiting_parser_callback == MMI_TRUE)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_HANDLE_NEW_MSG_ERR_1, cntx_chnl);
        return;
    }
    
    if (event_info->xml_file_path)
    {
        if (event_info->header->category == srv_bt_notify_category_noti) 
        {  

        #ifndef SMS_IN_NOTIFICATION
            if(event_info->header->subtype == srv_bt_notify_subtype_sms)
            {
                node = &srv_bt_notify_sms_data_node[cntx_chnl];
                node_index = srv_bt_notify_sms_data_node_index; 
                srv_bt_noti_data_init_msg(cntx_chnl, node, node_index);
            }
            else
        #endif
            {
                /* creat new msg */
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                node_index = srv_bt_noti_data_get_msg_sort_index_by_msg_id(&event_info->bt_addr, event_info->header->msg_id);
                if (node_index == -1)
                {
                    srv_bt_noti_data_flag.is_new_msg = MMI_TRUE;
                }
                else
                {
                    srv_bt_noti_data_flag.is_new_msg = MMI_FALSE;
                    srv_bt_noti_data_delete_msg_int(&event_info->bt_addr, node_index, srv_bt_notify_refresh_reason_from_service);
                }             
            #endif    
                srv_bt_noti_data_create_msg(cntx_chnl, &node, &node_index);
                if (node == NULL)
                {
                    MMI_PRINT(MOD_MMI_CONN_APP, 
                              TRACE_GROUP_7, 
                              "[BTNOTIFYSRV] new_msg create fail,chnl: %d, idx: %",
                              cntx_chnl);
                    return;
                }
                 MMI_PRINT(MOD_MMI_CONN_APP, 
                              TRACE_GROUP_7, 
                              "[BTNOTIFYSRV] handle_new_msg noti_cate,msg_id:%d, noti_id:%d",
                              event_info->header->msg_id,
                              node->noti_id);
            }
         
        }
        else if (event_info->header->category == srv_bt_notify_category_call)
        {
            node = &srv_bt_notify_call_data_node[cntx_chnl];
            node_index = srv_bt_notify_call_data_node_index;            
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_HANDLE_NEW_MSG_ERR_2, cntx_chnl);
            return;
        }
        
        /* copy header */
        memcpy(&(node->header), event_info->header, sizeof(srv_bt_notify_header_struct));
        memcpy(&(node->bt_addr), &(event_info->bt_addr), sizeof(srv_bt_cm_bt_addr));
        node->ANCS_msg_id = 0;
        node->source = srv_bt_noti_recv_get_source(cntx_chnl);
            
        body = OslMalloc(sizeof(srv_bt_notify_body_union));        
        memset(body, 0, sizeof(srv_bt_notify_body_union));
        
        /* parse the body from xml file */
        if (event_info->header->subtype == srv_bt_notify_subtype_text)
        {
            para_flag = srv_bt_notify_parse_noti_body;
        }
        else if (event_info->header->subtype == srv_bt_notify_subtype_sms)
        {
            para_flag = srv_bt_notify_parse_sms_body;
        }
        else if (event_info->header->subtype == srv_bt_notify_subtype_missed_call)
        {
            para_flag = srv_bt_notify_parse_call_body;
        }

        if (para_flag == srv_bt_notify_parse_noti_body)
        {
        #ifndef __MMI_BT_NOTIFICATION_ENHANCE__
            body->noti.content = (WCHAR*)&(node->content);
        #endif

        #ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
            body->noti.icon = node->icon;
        #endif
        }
        else if (para_flag == srv_bt_notify_parse_sms_body)
        {
        #ifndef __MMI_BT_NOTIFICATION_ENHANCE__
            body->sms.content = (WCHAR*)&(node->content);
        #endif
        }
        else if (para_flag == srv_bt_notify_parse_call_body)
        {
        #ifndef __MMI_BT_NOTIFICATION_ENHANCE__
            body->call.content = (WCHAR*)&(node->content);
        #endif
        }        
     
        FS_Delete(node->xml_file_path);        
        
        if (FS_Move(event_info->xml_file_path, node->xml_file_path, FS_MOVE_OVERWRITE | FS_MOVE_COPY, NULL, NULL, 0) != FS_NO_ERROR)    
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_HANDLE_NEW_MSG_ERR_3, cntx_chnl);
            OslMfree(body);
            return;
        }

        srv_bt_noti_data_msg_context[cntx_chnl].is_waiting_parser_callback = MMI_TRUE;
        user_para = ((U16)node_index) << 16 | (U16)cntx_chnl;
        parse_ret = srv_bt_notify_xml_parse(node->xml_file_path,
                                            para_flag,
                                            srv_bt_noti_data_parse_xml_callback,
                                            (void*)body,
                                            (void*)user_para);

        /* delete xml file to reduce quota size */
    #if !defined(__SRV_BT_NOTI_QUOTA_DEBUG_ENABLE__)
        FS_Delete(node->xml_file_path);
    #endif

        OslMfree(body);
    
        if (parse_ret == -1)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_HANDLE_NEW_MSG_ERR_4, cntx_chnl);
            
            srv_bt_noti_data_msg_context[cntx_chnl].is_waiting_parser_callback = MMI_FALSE;
            return;
        }
    }   
}

static void srv_bt_noti_data_handle_del_msg(srv_bt_noti_event_info_del *event_info)
{
    srv_bt_noti_data_msg_context_struct *context;
    srv_bt_noti_data_msg_node_struct *node_list;
    S32 msg_id;
    U32 ANCS_id;
    U32 i;
    U32 noti_id = 0;
    
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(&event_info->bt_addr);
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
        TRC_SRV_BT_NOTIFY_DATA_HANDLE_DEL_MSG, 
        cntx_chnl, 
        event_info->del_msg_id,
        event_info->source,
        event_info->ANCS_id);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return;
    } 

    context = &srv_bt_noti_data_msg_context[cntx_chnl];
    node_list = &(srv_bt_noti_data_node_list[cntx_chnl][0]);       
    msg_id = event_info->del_msg_id;
    ANCS_id = event_info->ANCS_id;
    
    if( event_info->source != SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        if (msg_id == BT_NOTIFY_DELETE_ALL_MSG_ID)
        {
            srv_bt_noti_data_delete_all(&event_info->bt_addr);
        }
        else
        {
            for (i = 0; i < context->node_num; ++i)
            {
                if ((U32)msg_id == node_list[context->node_index[i]].header.msg_id)
                {
                    srv_bt_noti_data_delete_msg_int(&event_info->bt_addr, i, srv_bt_notify_refresh_reason_from_service);
                }
            }
        }
    }
    else if(event_info->source == SRV_BT_NOTIFY_DATA_SOURCE_ANCS)
    {
        // delete by ANCS_id
        U32 count = 1;
#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
        count = srv_bt_noti_data_listmgr_get_msg_num();
#endif


        while(count>0)
        {
            noti_id = srv_bt_noti_data_get_noti_id_by_ancs_id( &event_info->bt_addr, ANCS_id );
            
            if(noti_id>0)
            {
                srv_bt_noti_data_delete_msg_by_noti_id_int(&event_info->bt_addr, noti_id, srv_bt_notify_refresh_reason_from_service);
            }

            count --;
        }
    }
}

MMI_BOOL srv_bt_noti_data_handle_add_msg(srv_bt_noti_event_info_add*  event_info)
{
    srv_bt_cm_bt_addr *bt_addr = &(event_info->bt_addr);
    srv_bt_noti_data_msg_node_struct *noti = &(event_info->msg_info);
    srv_bt_notify_noti_struct group_noti;
    S32 cntx_chnl = srv_bt_noti_find_synced_cntx_channel_by_device_addr(bt_addr);
    srv_bt_noti_data_msg_node_struct *node=NULL;
    U32 node_index;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
        TRC_SRV_BT_NOTIFY_DATA_HANDLE_ADD_MSG, 
        cntx_chnl, 
        event_info->msg_info.source,
        event_info->msg_info.ANCS_msg_id);

    if(bt_addr)
    {
        srv_bt_noti_recv_print_format_bt_addr(bt_addr);
    }
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return MMI_FALSE;
    }
     
    srv_bt_noti_data_create_msg(cntx_chnl, &node, &node_index);
                
    if (node == NULL)
    {            
        return MMI_FALSE;
    }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    node->page_content = (srv_bt_noti_page_content_struct *)srv_bt_noti_data_mem_alloc(sizeof(srv_bt_noti_page_content_struct));
    MMI_ASSERT(node->page_content);
#endif /*__MMI_BT_NOTIFICATION_ENHANCE__*/

    //copy data 
    memcpy( &(node->header),  &(noti->header), sizeof(srv_bt_notify_header_struct));          
    memcpy(node->sender, noti->sender, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
    memcpy(node->send_number, noti->send_number, BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH);
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    node->page_num = 1;
    memcpy(node->page_content->content, noti->page_content->content, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
    memcpy(node->page_content->title, noti->page_content->title, BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
#else
    memcpy(node->content, noti->content, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
    memcpy(node->title, noti->title, BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
    memcpy(node->ticker_text, noti->ticker_text, BT_NOTIFY_TICKER_TEXT_LENTH * ENCODING_LENGTH);
#endif
    node->timestamp = noti->timestamp;
    
    node->source = noti->source;
    node->ANCS_msg_id = noti->ANCS_msg_id;
    if(bt_addr != NULL)
    {
        memcpy(&(node->bt_addr), bt_addr, sizeof(srv_bt_cm_bt_addr));
    } 

    // print data
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] title = %s", node->page_content->title);
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] content = %s", node->page_content->content);
#else
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] title = %s", node->title);
   
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] content = %s", node->content);
#endif
    MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "[BTNOTIFYSRV] sender = %s", node->sender);
    // clear data 
    node->missed_call_count = 0;
    node->app_id = noti->app_id;
    node->is_read = MMI_FALSE;
    
#ifndef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    memset(node->icon_file_path, 0, BT_NOTIFY_ICON_FILE_NAME_LENTH * ENCODING_LENGTH);
#endif
    memset(node->xml_file_path, 0, BT_NOTIFY_XML_FILE_NAME_LENTH * ENCODING_LENGTH);

    MMI_PRINT(MOD_MMI_CONN_APP, 
                  TRACE_GROUP_7, 
                  "[BTNOTIFYSRV]addmsg app_id = %d", noti->app_id);

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    memset(&group_noti, 0, sizeof(srv_bt_notify_noti_struct));
    memcpy(group_noti.sender, noti->sender, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
    #ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
    group_noti.icon = NULL;
    #else
    memset(group_noti.icon_path, 0, 256 * ENCODING_LENGTH);
    #endif
    group_noti.app_id = noti->app_id;
    group_noti.timestamp = noti->timestamp;
    srv_bt_noti_data_handle_group(cntx_chnl, node, &group_noti,node_index);
#endif
    srv_bt_noti_data_send_refresh(bt_addr, SRV_BT_NOTIFY_REFRESH_NEW, 0, srv_bt_notify_refresh_reason_from_service, node->noti_id);

    return MMI_TRUE;  
}


MMI_BOOL srv_bt_noti_data_handle_disconnected(srv_bt_noti_event_info_disconnceted *event_info)
{
    srv_bt_cm_bt_addr *bt_addr = &(event_info->bt_addr);
    S32 cntx_chnl = srv_bt_noti_find_cntx_channel_by_device_addr(bt_addr);

    MMI_PRINT(MOD_MMI_CONN_APP, 
                  TRACE_GROUP_7, 
                  "[BTNOTIFYSRV]srv_bt_noti_data_handle_disconnected cntx_chnl = %d, source = %d", 
                  cntx_chnl,
                  event_info->source);

    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        return MMI_FALSE;
    }

    srv_bt_noti_recv_release_source(cntx_chnl, event_info->source);
    return MMI_TRUE;
}

MMI_BOOL srv_bt_noti_data_handle_connected(srv_bt_noti_event_info_connceted*  event_info)
{
    srv_bt_cm_bt_addr *bt_addr = &(event_info->bt_addr);
    S32 cntx_chnl = srv_bt_noti_find_cntx_channel_by_device_addr(bt_addr);

   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
        TRC_SRV_BT_NOTIFY_DATA_HANDLE_CONNECTED, 
        cntx_chnl, 
        event_info->source);
    
    if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
    {
        cntx_chnl = srv_bt_noti_get_free_cntx_channel();

        MMI_TRACE(MMI_CONN_TRC_G7_BT, 
            TRC_SRV_BT_NOTIFY_DATA_HANDLE_CONNECTED, 
            cntx_chnl, 
            event_info->source);
        
        if (MMI_FALSE == srv_bt_noti_check_channel_valid(cntx_chnl))
        {
            return MMI_FALSE;
        }       
    }
     
    srv_bt_noti_recv_set_source(cntx_chnl, event_info->source, bt_addr); 

    return MMI_TRUE;  
}

static void srv_bt_noti_data_send_refresh(srv_bt_cm_bt_addr *bt_addr, 
    srv_bt_notify_refresh_type refresh_type, 
    srv_bt_notify_refresh_reason_enum refresh_reason,
    U32 index,
    U32 noti_id)
{
    srv_bt_noti_refresh_evt_struct event;

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__  
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_LISTMGR_REFRESH);
#else
	MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_REFRESH);
#endif
    event.refresh_type = refresh_type;
    event.index = index;
    event.noti_id= noti_id;
    event.refresh_reason = refresh_reason;
    event.is_listmgr = MMI_FALSE;
    memcpy(&event.bt_addr, bt_addr, sizeof(srv_bt_cm_bt_addr));

#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__    
    MMI_FRM_CB_EMIT_EVENT(&event);
#else
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
#endif
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_SEND_REFRESH, refresh_type, noti_id, refresh_reason, MMI_FALSE );
}

static MMI_BOOL srv_bt_noti_data_event_hdlr(srv_bt_noti_event_struct* event_data)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_EVENT_HDLR, event_data->evt_id);
    
    switch (event_data->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_NEW_MSG:
        {
            srv_bt_noti_data_handle_new_msg((srv_bt_noti_event_info_new*)event_data->event_info);          
            break;
        }

        case EVT_ID_SRV_BT_NOTI_DEL_MSG:
        {
            srv_bt_noti_data_handle_del_msg((srv_bt_noti_event_info_del*)event_data->event_info);
            break;
        }


        default:
        {
            break;
        }
    }

    return MMI_FALSE;
}

static mmi_ret srv_bt_noti_data_ext_event_handler(mmi_event_struct *evt)
{
    
    srv_bt_noti_event_struct* event_data = (srv_bt_noti_event_struct*) evt;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_EXT_EVENT_HDLR, event_data->evt_id);
        
    switch(event_data->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_DEL_MSG:
        {
            srv_bt_noti_data_handle_del_msg((srv_bt_noti_event_info_del*)event_data->event_info);
            break;
        }
                
        case EVT_ID_SRV_BT_NOTI_ADD_MSG:
        {
            srv_bt_noti_data_handle_add_msg((srv_bt_noti_event_info_add*)event_data->event_info);
            break;
        }

        case EVT_ID_SRV_BT_NOTI_CONNECTED:
        {
            srv_bt_noti_data_handle_connected((srv_bt_noti_event_info_connceted*)event_data->event_info);
            break;
        }

        case EVT_ID_SRV_BT_NOTI_DISCONNECTED:
        {
            srv_bt_noti_data_handle_disconnected((srv_bt_noti_event_info_disconnceted*)event_data->event_info);
        }
#ifdef __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__
        case EVT_ID_SRV_BT_NOTI_LISTMGR_REFRESH:
        {
            srv_bt_noti_refresh_evt_struct* refresh_event = (srv_bt_noti_refresh_evt_struct*) evt; 

            if(refresh_event->is_listmgr == MMI_TRUE)
            {
                break;
            }
            srv_bt_noti_data_listmgr_refresh_data( refresh_event->refresh_type,
                                                                        refresh_event->refresh_reason,
                                                                        refresh_event->noti_id);
        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
            srv_bt_noti_data_listmgr_refresh_group_data( refresh_event->refresh_type,                                                                    refresh_event->refresh_reason);
        #endif
            break;
        }
#endif /* __MMI_BT_NOTI_SRV_LISTMGR_SUPPORT__ */

        default:
        {
            break;
        }       
    }

    return MMI_RET_OK;
}

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
MMI_BOOL srv_bt_noti_data_reply_remote_sms(srv_bt_cm_bt_addr *bt_addr, WCHAR *send_number, WCHAR *content)
{
    srv_bt_notify_data_struct* node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];
    
    do
    {
        node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (node == NULL)
        {
            break;
        }
    
        memset(node, 0, sizeof(srv_bt_notify_data_struct));
        node->header.category= srv_bt_notify_category_noti;
        node->header.subtype= srv_bt_notify_subtype_sms;
        node->header.action = srv_bt_notify_action_add;
        node->header.msg_id = 0;
        node->mbody.sms.sender[0] = 0;
        node->mbody.sms.timestamp= 0;
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        node->mbody.sms.page_content = NULL;
    #else
        node->mbody.sms.content= NULL;
    #endif
        if (mmi_ucs2strlen((const CHAR*)send_number) > BT_NOTIFY_NUMBER_LENTH)
        {
            break;
        }
        
        mmi_wcscpy(node->mbody.sms.send_number, send_number);

        if (mmi_ucs2strlen((const CHAR*)content) > BT_NOTIFY_SEND_SMS_CONTENT_LENTH)
        {
            break;
        }
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        node->mbody.sms.page_content = OslMalloc(sizeof(srv_bt_noti_page_content_struct));
        if (node->mbody.sms.page_content == NULL)
        {
            break;
        }
        mmi_wcscpy(node->mbody.sms.page_content->content, content);
    #else
        
        node->mbody.sms.content = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_SEND_SMS_CONTENT_LENTH);
        if (node->mbody.sms.content == NULL)
        {
            break;
        }
    
        mmi_wcscpy(node->mbody.sms.content, content);
    #endif
        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }

        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\send_sms_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);

        parse_ret = srv_bt_notify_xml_generator(xml_file_path, node);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_SEND_SMS_PARSE_RESULT, parse_ret); 
        
        if (parse_ret == -1)
        {
            break;
        }          

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    if (node->mbody.sms.page_content != NULL)
    {
        OslMfree(node->mbody.sms.page_content);
    }
#else
    if (node->mbody.sms.content != NULL)
    {
        OslMfree(node->mbody.sms.content);
    }
    #endif
    
    if (node != NULL)
    {
        OslMfree(node);
    }
    
    return retval;
}

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
MMI_BOOL srv_bt_noti_data_block_remote_notification(srv_bt_cm_bt_addr *bt_addr, U32 app_id)
{
    srv_bt_notify_data_struct* node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];
    
    do
    {
        node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (node == NULL)
        {
            break;
        }
        
        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }
        
        memset(node, 0, sizeof(srv_bt_notify_data_struct));
        node->header.category= srv_bt_notify_category_noti;
        node->header.subtype= srv_bt_notify_subtype_block_sender;
        node->header.action = srv_bt_notify_action_update;        
        node->mbody.block_sender.sender[0] = 0;
        node->mbody.block_sender.send_number[0] = 0;
        node->mbody.block_sender.app_id = app_id;

        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\update_block_sender_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);

        parse_ret = srv_bt_notify_xml_generator(xml_file_path, node);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_UPDATE_REMOTE_BLOCK_PARSE_RESULT, parse_ret);
        
        if (parse_ret == -1)
        {
            break;
        }          

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }
    
    if (node != NULL)
    {
        OslMfree(node);
    }

    /* delete corresponding msg */
    if (MMI_TRUE == retval)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_UPDATE_REMOTE_BLOCK_DELETE_MSG, app_id);
        srv_bt_noti_data_delete_msg_by_app_id(bt_addr, app_id);
    }
    
    return retval;
}


MMI_BOOL srv_bt_noti_action_operate(srv_bt_cm_bt_addr *bt_addr, U32 msg_id, WCHAR *action_id)
{
    srv_bt_notify_data_struct* node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];

    kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[btnotify]action_operate noti_id:%d. action_id:%s", msg_id, action_id);
    do
    {
        node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (node == NULL)
        {
            break;
        }
        
        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }
        
        memset(node, 0, sizeof(srv_bt_notify_data_struct));
        node->header.category= srv_bt_notify_category_noti;
        node->header.subtype= srv_bt_notify_subtype_action_operate;
        node->header.action = srv_bt_notify_action_update; 
        node->header.msg_id = msg_id;
        node->mbody.action_operate.noti_id = msg_id;
        mmi_wcscpy(node->mbody.action_operate.action_id, action_id);

        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\update_action_operate_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);

        parse_ret = srv_bt_notify_xml_generator(xml_file_path, node);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_UPDATE_REMOTE_BLOCK_PARSE_RESULT, parse_ret);
        
        if (parse_ret == -1)
        {
            break;
        }          

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }
    
    if (node != NULL)
    {
        OslMfree(node);
    }
    
    return retval;
}



/* call: Call Modules */
static void srv_bt_noti_call_init(void)
{
    U32 i;
    
    srv_bt_noti_disp_set_interrupt_event_handler(
        EVT_ID_SRV_BT_NOTI_NEW_MSG,
        srv_bt_notify_category_call,
        srv_bt_noti_data_event_hdlr,
        NULL);

    for (i = 0; i < BT_NOTIFY_MAX_CHANNEL; ++i)
    {
        srv_bt_noti_data_init_msg(
            i,
            &srv_bt_notify_call_data_node[i], 
            srv_bt_notify_call_data_node_index);
    }
}

static void srv_bt_noti_notify_missed_call(srv_bt_cm_bt_addr *bt_addr, 
                                                                            U32 missed_call_count, 
                                                                            U32 timestamp,
                                                                            WCHAR* send_number,
                                                                            WCHAR* sender)
{
    srv_bt_noti_missed_call_evt_struct event;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_MISSED_CALL_COUNT, missed_call_count);
    MMI_PRINT(MOD_MMI_CONN_APP, 
                  TRACE_GROUP_7, 
                  "bt_addr: %x:%x:%x", 
                  bt_addr->lap,
                  bt_addr->uap, 
                  bt_addr->nap);
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_MISSED_CALL);
    memcpy(&event.bt_addr, bt_addr, sizeof(srv_bt_cm_bt_addr));
    event.missed_call_count = missed_call_count;
    event.timestamp = timestamp;
    mmi_wcscpy(event.send_number, send_number);
    mmi_wcscpy(event.sender, sender);
    MMI_FRM_CB_EMIT_POST_EVENT(&event);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_SEND_REFRESH);
}

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
MMI_BOOL srv_bt_noti_update_remote_missed_call(srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_notify_data_struct* node = NULL;
    WCHAR *xml_file_path = NULL;
    S32 parse_ret;
    MMI_BOOL retval = MMI_FALSE;
    CHAR bt_format_addr[20];
    
    do
    {
        node = OslMalloc(sizeof(srv_bt_notify_data_struct));

        if (node == NULL)
        {
            break;
        }
        
        memset(node, 0, sizeof(srv_bt_notify_data_struct));
        node->header.category= srv_bt_notify_category_call;
        node->header.subtype= srv_bt_notify_subtype_missed_call;
        node->header.action = srv_bt_notify_action_update;
        node->header.msg_id = 0;
        node->mbody.call.sender[0] = 0;
        node->mbody.call.send_number[0] = 0;
        node->mbody.call.missed_call_count = 0;
        node->mbody.call.timestamp = 0;
        node->mbody.call.content = NULL;

        xml_file_path = OslMalloc(sizeof(WCHAR) * BT_NOTIFY_XML_FILE_NAME_LENTH);

        if (xml_file_path == NULL)
        {
            break;
        }

        if (MMI_FALSE == srv_bt_noti_get_format_bt_device_addr(bt_addr, bt_format_addr, 20))
        {
            break;
        }

        kal_wsprintf(xml_file_path, "%w%s", BT_NOTIFY_ROOT_FOLDER, bt_format_addr);
        srv_bt_noti_create_folder(xml_file_path);
        kal_wsprintf(xml_file_path, "%w%s\\update_missed_call_%04d.xml", BT_NOTIFY_ROOT_FOLDER, bt_format_addr, 0);
        parse_ret = srv_bt_notify_xml_generator(xml_file_path, node);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_UPDATE_REMOTE_MISSED_CALL_PARSE_RESULT, parse_ret);
        MMI_PRINT(MOD_MMI_CONN_APP, 
              TRACE_GROUP_7, 
              "bt_addr: %x:%x:%x", 
              bt_addr->lap,
              bt_addr->uap, 
              bt_addr->nap);
            
        if (parse_ret == -1)
        {
            break;
        }

        retval = srv_bt_noti_send_xml(bt_addr, xml_file_path);
    } while(0);

    if (xml_file_path != NULL)
    {
        OslMfree(xml_file_path);
    }

    if (node != NULL)
    {
        OslMfree(node);
    }

    return retval;
}

/* For Message APP */
#ifndef SMS_IN_NOTIFICATION   
static void srv_bt_noti_sms_init(void)
{
    U32 i;
    
    /* srv_bt_noti_disp_set_interrupt_event_handler(
        EVT_ID_SRV_BT_NOTI_NEW_MSG,
        srv_bt_notify_category_call,
        srv_bt_noti_data_event_hdlr,
        NULL); */

    for (i = 0; i < BT_NOTIFY_MAX_CHANNEL; ++i)
    {
        srv_bt_noti_data_init_msg(
            i,
            &srv_bt_notify_sms_data_node[i], 
            srv_bt_notify_sms_data_node_index);
    }
}

static void srv_bt_noti_notify_new_sms(srv_bt_cm_bt_addr *bt_addr, 
                                                                            WCHAR* content, 
                                                                            U32 timestamp,
                                                                            WCHAR* send_number,
                                                                            WCHAR* sender)
{
    srv_bt_noti_new_sms_evt_struct event;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NEW_SMS);
    
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SRV_BT_NOTI_NEW_SMS);
    memcpy(&event.bt_addr, bt_addr, sizeof(srv_bt_cm_bt_addr));
    event.timestamp = timestamp;
    mmi_wcscpy(event.send_number, send_number);
    mmi_wcscpy(event.sender, sender);
    mmi_wcscpy(event.content, content);
    MMI_FRM_CB_EMIT_POST_EVENT(&event);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_SEND_REFRESH);
}
#endif

#endif // __MMI_BT_NOTI_SRV__

