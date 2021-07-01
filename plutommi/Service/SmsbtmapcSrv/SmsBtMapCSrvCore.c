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
 *  SmsBtMapCCoreSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT File
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/

#include "MMI_features.h"


// TODO:ADD Compile Option
#include "MapSrvGprot.h"
#include "SmsBtMapCSrvParser.h"
#include "SmsBtMapCSrvStorage.h"
#include "SmsBtMapCSrvGProt.h"
#include "SmsSrvGProt.h"
#include "SmsBtMapCSrvUtil.h"
#include "SmsBtMapCSrvConverter.h"
#include "MapObjSrv.h"
#include "FileMgrSrvGProt.h"
#include "SmsBtMapCSrvCore.h"
#include "Unicodexdcl.h"
#include "mmi_rp_srv_sms_btmapc_def.h"
#include "MMI_trc_Int.h"
#include "MMI_common_app_trc.h"
#include "App_str.h"
#include "tst_sap.h"
#include "tst_def.h"
#include "Conversions.h"
#include "nvram_common_defs.h"
#include "Conversions.h"
#include "vmstdlib_sdk.h"

#ifndef __MTK_TARGET__
#define __MMI_BT_MAP_CLIENT_TEST__
#endif 

#ifdef __SRV_SMS_BTMAPC__

const CHAR MSG_ROOT_PATH[] = "telecom/msg/";
const CHAR INBOX_PATH[] = "inbox";
const CHAR OUTBOX_PATH[] = "outbox";
const CHAR SENT_PATH[] = "sent";
const CHAR DRAFT_PATH[] = "draft";
const CHAR OPER_VERSION[] = "VERSION:2.1";
const CHAR OPER_NAME[] = "N:";
const CHAR OPER_TEL[] = "TEL:";
const CHAR OPER_BVCARD[] = "BEGIN:VCARD";
const CHAR OPER_EVCARD[] = "END:VCARD";
const CHAR OPER_END[] = "\r\n";
extern srv_sms_btmapc_node_event_struct sms_btmapc_evt_report;
extern SMS_HANDLE g_srv_sms_bt_send_handle;
extern U8 g_sms_bt_opt_cancel_flag;
extern U8 g_sms_bt_send_cancel_flag;
extern srv_sms_btmapc_bt_enum g_sms_active_dev_index;


#ifdef __MMI_BT_MAP_CLIENT_TEST__
static U16 g_sms_offset;
static void* g_user_data;
static SrvSmsCallbackFunc g_callback_func;
#endif

static void srv_sms_btmapc_connect_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_disconnect_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_disconnect_ind(S32 srv_hd, void* para);
static void srv_sms_btmapc_set_folder_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_get_msg_list_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_get_msg_req(srv_bt_mapc_bt_enum bt_index, U16 msg_id, void *userData);
static void srv_sms_btmapc_get_msg_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_set_msg_status_req(srv_bt_mapc_bt_enum bt_index, U16 msg_id, srv_bt_mapc_msg_status_enum status, void *userData);
static void srv_sms_btmapc_set_msg_status_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_send_msg_req(srv_bt_mapc_push_message_req_struct *req, void *userData);
static void srv_sms_btmapc_send_msg_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_abort_rsp(S32 srv_hd, void* para);
static void srv_sms_btmapc_handle_evt_report(S32 srv_hd, void* para);
static MMI_BOOL srv_sms_btmapc_build_bmessage(srv_sms_btmapc_send_handle_struct *hd_data, srv_bt_mapc_push_message_req_struct *req);
static void srv_sms_btmapc_set_list_property(srv_bt_mapc_set_msg_listing_prop_struct *msg);
static void srv_sms_btmapc_save_sms_callback(srv_sms_callback_struct* data);
static SMS_HANDLE srv_sms_btmapc_change_folder(srv_sms_btmapc_bt_enum bt_index, srv_sms_btmapc_box_enum box_type, srv_btmapc_folder_flag_enum folder_flag, SrvSmsCallbackFunc callback_func, void *user_data);
#ifdef __SRV_SMS_BTMAPC_TEST__
U8 srv_sms_btmapc_ut_handle(U8 index, kal_uint8* string);
#endif

MBT_MAP_MSG_OBJECT g_msg; 

MBT_MAP_MSG_OBJECT *msg = &g_msg;


#ifdef __SRV_SMS_BTMAPC_TEST__
void get_content_callback(srv_sms_callback_struct* callback_data)
{
    srv_sms_msg_data_struct *msg_data = NULL;
    srv_sms_read_msg_cb_struct *cb = (srv_sms_read_msg_cb_struct *)callback_data->action_data;

    msg_data = cb->msg_data;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_CONTENT, 11 ,callback_data->result, callback_data->cause);
    if(callback_data->result)
    {
        srv_sms_btmapc_write_file(OUTPUT_MSG_DETAIL, (void *)msg_data);
    }
    OslMfree(msg_data->content_buff);
    OslMfree(msg_data);
}

U16 srv_sms_get_msg_id_by_index(U8 index)
{
    U32 i;
    U16 msg_id = 0;

    for(i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
    {
        if(srv_sms_btmapc_is_msg_exist(msg_id) == MMI_TRUE)
        {
            if(index > 0)
            {
                msg_id++;
            }
            
            if(index == 0)
            {
                break;
            }
            else
            {
                index--;
            }
        }
        else
        {
            msg_id++;
        }
    }
    return msg_id;
}


U8 srv_sms_btmapc_ut_handle(U8 index, kal_uint8 *string)
{
    CHAR number[12] = {'1','3','4','0','2','8','0','6','5','7','1'};
    CHAR ucs2_addr[20*2] = {0};
    
    mmi_asc_n_to_ucs2((S8*)ucs2_addr, number, strlen(number));
    
    if (strcmp((char*)string, "smsconn") == 0)
    {
        srv_sms_btmapc_connect(SRV_SMS_BTMAPC, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdisconn") == 0)
    {
        srv_sms_btmapc_disconnect(sms_btmapc_storage_cntx.hd, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsroot") == 0)
    {
        srv_sms_btmapc_change_folder(SRV_SMS_BTMAPC_BOX_ROOT, SRV_BT_MAPC_FORWARD, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsin") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_INBOX, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsout") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_UNSENT, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smssent") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_OUTBOX, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdraft") == 0)
    {
        srv_sms_btmapc_get_msg_list(MMI_TRUE, SRV_SMS_BTMAPC_BOX_DRAFTS, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsget") == 0)
    {
        U16 msg_id = 0;
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_get_msg(msg_id, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsread") == 0)
    {
        S8 *msg_content = (S8 *)OslMalloc(1024);
        srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
        
        msg_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
        msg_data->content_buff_size = 1024;
        msg_data->content_buff = msg_content;
        srv_sms_btmapc_read_msg((U16)index, MMI_TRUE, msg_data, get_content_callback, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsforward") == 0)
    {
        U16 msg_id = 0;
        SMS_HANDLE smsHdlr;
        WCHAR path_msg[200] = {0};
        WCHAR path_address[100] = {0};
        CHAR address[20];
        CHAR sms_content[500];
        S32 address_fhandle = -1;        
        S32 msg_fhandle = -1;
        U32 read_lenth = 0;

        kal_wsprintf(path_address, "%c:\\@SmsBtMapC\\phonenumber.txt", (CHAR)SRV_FMGR_CARD_DRV);
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_get_msg_name(msg_id, MMI_FALSE, path_msg);
        smsHdlr = srv_sms_btmapc_get_send_handle();
        if((msg_fhandle = FS_Open(path_msg, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        if ((address_fhandle = FS_Open(path_address, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        FS_Read(msg_fhandle, sms_content, 500, &read_lenth);
        sms_content[read_lenth] = 0;
        FS_Read(address_fhandle, address, 20, &read_lenth);
        address[read_lenth] = 0;
        
        srv_sms_btmapc_set_content(smsHdlr, sms_content, (U16)(strlen(sms_content)));
        mmi_asc_n_to_ucs2((S8*)ucs2_addr, address, strlen(address));
        srv_sms_btmapc_set_address(smsHdlr, (CHAR *)ucs2_addr);
        srv_sms_btmapc_set_send_type(smsHdlr, SRV_SMS_FG_SEND);
        srv_sms_btmapc_send_msg(smsHdlr, NULL, NULL);
        
        FS_Close(msg_fhandle);
        FS_Close(address_fhandle);
        return MMI_TRUE;
    }

    else if (strcmp((char*)string, "smssend") == 0)
    {
        SMS_HANDLE smsHdlr;
        S32 content_fhandle = -1;
        S32 address_fhandle = -1;
        CHAR sms_content[500];
        CHAR address[20];
        WCHAR path_content[100] = {0};
        WCHAR path_address[100] = {0};
        U32 read_lenth = 0;
        kal_wsprintf(path_content, "%c:\\@SmsBtMapC\\smssend.txt", (CHAR)SRV_FMGR_CARD_DRV);
        kal_wsprintf(path_address, "%c:\\@SmsBtMapC\\phonenumber.txt", (CHAR)SRV_FMGR_CARD_DRV);
        smsHdlr = srv_sms_btmapc_get_send_handle();
        
        if ((content_fhandle = FS_Open(path_content, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        if ((address_fhandle = FS_Open(path_address, FS_READ_ONLY)) < 0)
        {
            return MMI_TRUE;
        }
        FS_Read(content_fhandle, sms_content, 500, &read_lenth);
        sms_content[read_lenth] = 0;
        FS_Read(address_fhandle, address, 20, &read_lenth);
        address[read_lenth] = 0;

        
        srv_sms_btmapc_set_content(smsHdlr, sms_content, (U16)(strlen(sms_content)));
        mmi_asc_n_to_ucs2((S8*)ucs2_addr, address, strlen(address));
        srv_sms_btmapc_set_address(smsHdlr, (CHAR *)ucs2_addr);
        srv_sms_btmapc_set_send_type(smsHdlr, SRV_SMS_FG_SEND);
        srv_sms_btmapc_send_msg(smsHdlr, NULL, NULL);

        FS_Close(content_fhandle);
        FS_Close(address_fhandle);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsdelete") == 0)
    {
        U16 msg_id = 0;
        
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_delete_msg(msg_id, NULL, NULL);
        return MMI_TRUE;
    }

    else if (strcmp((char*)string, "smsfetchmessage") == 0)
    {
        srv_sms_btmapc_read_cntx_struct *read_cntx;
        srv_bt_mapc_message_cnf_struct res;
        S8 *msg_content = (S8 *)OslMalloc(1024);
        srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct*)OslMalloc(sizeof(srv_sms_msg_data_struct));
        char filename[] = "z:\\aa\\a.vcf";
        
        msg_data->para_flag = (srv_sms_para_enum)(SRV_SMS_PARA_CONTENT_BUFF | SRV_SMS_PARA_ORI_8BIT_DATA);
        msg_data->content_buff_size = 1024;
        msg_data->content_buff = msg_content;

        read_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_read_cntx_struct),
                        SRV_SMS_BTMAPC_OP_GET_MSG,
                        NULL,
                        NULL);
        srv_sms_btmapc_read_msg_init(
                    read_cntx,
                    0,
                    MMI_FALSE,
                    msg_data);
        res.Error = SRV_BT_MAPC_SUCCESS;
        memcpy(res.file, filename, strlen(filename));
        res.file[strlen(filename)] = 0;
        res.user_data = (void *)read_cntx;
        srv_sms_btmapc_get_msg_rsp(0, &res);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsparsemsglist") == 0)
    {
        WCHAR file_name[] = L"z:\\aa\\maps_message_list.xml";
        srv_sms_btmapc_xml_parse(file_name);
        srv_sms_btmapc_write_file(OUTPUT_MSG_LIST, (void *)srv_sms_btmapc_msg_list);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smsparseevent") == 0)
    {
        WCHAR file_name[] = L"z:\\aa\\maps_event_report.xml";
        srv_sms_btmapc_xml_parse(file_name);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smscsread") == 0)
    {
        U16 msg_id = 0;
        
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_change_msg_status(msg_id, SRV_SMS_STATUS_READ, NULL, NULL);
        return MMI_TRUE;
    }
    else if (strcmp((char*)string, "smscsunread") == 0)
    {
        U16 msg_id = 0;
        
        msg_id = srv_sms_get_msg_id_by_index(index);
        srv_sms_btmapc_change_msg_status(msg_id, SRV_SMS_STATUS_UNREAD, NULL, NULL);
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif

#ifdef __SRV_SMS_BTMAPC_TEST__
static void srv_sms_btmapc_itoa(kal_char *buf, kal_int32 i, kal_int32 base)
{
   kal_char *s;
#define LEN   20
   kal_int32 rem;
   static kal_char rev[LEN+1];

   rev[LEN] = 0;
   if (i == 0)
   {
      buf[0] = '0';
      ++buf;
      return;
   }
   s = &rev[LEN];
   while (i)
   {
      rem = i % base;
      if (rem < 10)
         *--s = rem + '0';
      else if (base == 16)
         *--s = "abcdef"[rem - 10];
      i /= base;
   }
   while (*s)
   {
      buf[0] = *s++;
      ++buf;
   }
}

void srv_sms_btmapc_write_file(srv_sms_btmapc_output_type output_type, void *data)
{
    switch (output_type)
    {
        case OUTPUT_MSG_LIST:
        {
            srv_sms_btmapc_msg_node_struct *msg_node = (srv_sms_btmapc_msg_node_struct *)data;
            WCHAR path[100] = {0};
            WCHAR root_path[100] = {0};
            S32 fhandle = 0;
            int i = 0;
            kal_char *index = OslMalloc(4);

            memset(index, 0, 4);
            kal_wsprintf(path, "%c:\\@SmsBtMapC\\output_msglist.txt", (CHAR)SRV_FMGR_CARD_DRV);
            kal_wsprintf(root_path, "%c:\\@SmsBtMapC", (CHAR)SRV_FMGR_CARD_DRV);
            FS_CreateDir(root_path);
            FS_Delete(path);
            if ((fhandle = FS_Open(path, FS_READ_WRITE|FS_CREATE)) < 0)
            {
                return;
            }
            for (i = 0; i < SRV_SMS_BTMAPC_MAX_SMS_ENTRY; i++)
            {
                FS_Write(fhandle, "msg_index :", 12, NULL);
                srv_sms_btmapc_itoa(index, i, 10);
                FS_Write(fhandle, index, 3, NULL);
                FS_Write(fhandle, "  number :", 11, NULL);;
                FS_Write(fhandle, msg_node[i].number, strlen(msg_node[i].number), NULL);
                FS_Write(fhandle, "\r\n", 2, NULL);
            }
            OslMfree(index);
            FS_Close(fhandle);
            break;
        }
        case OUTPUT_MSG_DETAIL:
        {
            srv_sms_msg_data_struct *msg_data = (srv_sms_msg_data_struct *)data;
            WCHAR path[200] = {0};
            WCHAR root_path[50] = {0};
            char msg_number[20] = {0};
            char msg_content[1024] = {0};
            S32 fhandle = 0;

            kal_wsprintf(path, "%c:\\@SmsBtMapC\\%d_output_smsrecv.txt", (CHAR)SRV_FMGR_CARD_DRV, msg_data->tp_st);
            kal_wsprintf(root_path, "%c:\\@SmsBtMapC", (CHAR)SRV_FMGR_CARD_DRV);
            FS_CreateDir(root_path);
            if ((fhandle = FS_Open(path, FS_READ_WRITE|FS_CREATE)) < 0)
            {
                return;
            }
            FS_Write(fhandle, "Number: ", 9, NULL);
            mmi_ucs2_to_asc(msg_number, msg_data->number);
            FS_Write(fhandle, msg_number, strlen(msg_number), NULL);
            FS_Write(fhandle, "\r\n", 2, NULL);
            FS_Write(fhandle, "Content: \r\n", 11, NULL);

            //mmi_chset_convert(MMI_CHSET_UCS2, MMI_CHSET_GB2312, msg_data->content_buff, msg_content, 1024);
            mmi_ucs2_to_asc(msg_content, msg_data->content_buff);
            FS_Write(fhandle, msg_content, strlen(msg_content), NULL);
            FS_Close(fhandle);
        }

        default:
            break;
    }
}
#endif

#ifdef __MMI_BT_MAP_CLIENT_TEST__
void srv_sms_test_send_new_event()
{
    srv_sms_event_new_sms_struct *event_data = NULL;
    event_data = (srv_sms_event_new_sms_struct *)OslMalloc(sizeof(srv_sms_event_new_sms_struct));
    srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_NEW_MSG, event_data);
    OslMfree(event_data);
}
#endif

#ifdef __MMI_BT_MAPC_NEW_SMS_POPUP__
U16 g_sms_btmapc_noti_count = 0;
U16 srv_sms_btmapc_get_notify_count(void)
{
    return g_sms_btmapc_noti_count;
}

U16 srv_sms_btmapc_update_notify_count(void)
{
    return g_sms_btmapc_noti_count++;
}

U16 srv_sms_btmapc_reset_notify_count(void)
{
    return g_sms_btmapc_noti_count = 0;
}
#endif

void srv_sms_btmapc_init()
{
    S32 hd = 0;
    WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];
    
#ifdef __SRV_SMS_BTMAPC_TEST__
    //mmi_frm_set_protocol_event_handler(MSG_ID_TST_INJECT_STRING, (PsIntFuncPtr)srv_sms_btmapc_ut_handle, MMI_TRUE);
#endif

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_INIT);
    if(!srv_sms_btmapc_file_exist(SMS_BT_BMESSAGE_ROOT_FOLDER))
    {
        FS_CreateDir(SMS_BT_BMESSAGE_ROOT_FOLDER);
    }
    if(!srv_sms_btmapc_file_exist(MAP_ADP_WORK_FOLDER))
    {
        FS_CreateDir(MAP_ADP_WORK_FOLDER);
    }
    
    srv_sms_btmapc_get_root_name(file_name);
    if(!srv_sms_btmapc_file_exist(file_name))
    {
        FS_CreateDir(file_name);
    }
    srv_sms_btmapc_storage_init_data();
    srv_sms_btmapc_list_init();
    #ifndef __MMI_TELEPHONY_SUPPORT__
        #ifdef __MMI_WEARABLE_DEVICE__
        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #else
        srv_sms_btmapc_delete_all();
        #endif
    #else
        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
    #endif
#ifdef __MMI_BT_MAPC_NEW_SMS_POPUP__
    srv_sms_btmapc_reset_notify_count();  
#endif
    
    hd = srv_mapc_open(SRV_SMS_BTMAPC);
    
    sms_btmapc_storage_cntx.hd = hd;
    srv_bt_mapc_register_callback(hd, srv_sms_btmapc_handle_evt);
}


MMI_BOOL srv_sms_btmapc_get_folder_path(srv_sms_btmapc_box_enum box_type, CHAR *path)
{
    MMI_BOOL result = MMI_TRUE;
    if(path == NULL)
    {
        return MMI_FALSE;
    }
    switch(box_type)
    {
        case SRV_SMS_BTMAPC_BOX_INBOX:
        {
            mmi_asc_to_ucs2(path, (char *)INBOX_PATH);
            break;
        }
        case SRV_SMS_BTMAPC_BOX_OUTBOX:
        {
            mmi_asc_to_ucs2(path, (char *)SENT_PATH);
            break;
        }
        case SRV_SMS_BTMAPC_BOX_DRAFTS:
        {
            mmi_asc_to_ucs2(path, (char *)DRAFT_PATH);
            break;
        }
        case SRV_SMS_BTMAPC_BOX_UNSENT:
        {
            mmi_asc_to_ucs2(path, (char *)OUTBOX_PATH);
            break;
        }
        default:
        {
            result = MMI_FALSE;
            break;
        }
    }
    return result;
}

S32 srv_sms_btmapc_connect(
          int app_id,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_action_struct *conn_cntx = NULL;

    S32 hd = srv_mapc_open(app_id);
    sms_btmapc_storage_cntx.hd = hd;
    srv_bt_mapc_register_callback(hd, srv_sms_btmapc_handle_evt);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_connect srv_sms_btmapc_alloc_cntx");
    conn_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_action_struct),
                            SRV_SMS_BTMAPC_OP_CONN,
                            callback_func,
                            user_data);
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_REQ, conn_cntx);
    if(conn_cntx != NULL)
    {
        //srv_bt_mapc_connect((void *)conn_cntx);
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CONN, error_cause, user_data, callback_func);
    }
    return hd;
}


void srv_sms_btmapc_disconnect(
          srv_bt_mapc_bt_enum bt_index,    
          S32 hd,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_action_struct *disconn_cntx = NULL;
    
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_disconnect srv_sms_btmapc_alloc_cntx");
    disconn_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_action_struct),
                            SRV_SMS_BTMAPC_OP_DISCONN,
                            callback_func,
                            user_data);    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DISCONNECT_REQ, disconn_cntx);
    if(disconn_cntx != NULL)
    {
        srv_mapc_disconnect(bt_index, (void *)disconn_cntx);
        srv_mapc_close(hd);
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_DISCONN, error_cause, user_data, callback_func);
    }
}

#ifdef __MMI_BT_MAP_CLIENT_TEST__
int test_aa = 0;
void srv_sms_btmapc_timeout(void)
{
    WCHAR file_name[] = L"z:\\aa\\maps_message_list.xml";
    WCHAR file_name2[] = L"z:\\aa\\maps_message_list2.xml";
    WCHAR file_name3[] = L"z:\\aa\\maps_message_list3.xml";
    srv_sms_btmapc_change_folder_struct *change_folder_cntx;

    
    StopTimer(SMS_BTMACSRV_TIMER_ID);
    change_folder_cntx = g_user_data;
    //if (!test_aa)
    if(1)
    {
        //test_aa++;
        srv_sms_btmapc_box_enum curr_box = srv_sms_btmapc_get_curr_box();
        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        srv_sms_btmapc_set_curr_box(curr_box);
        srv_sms_btmapc_xml_parse(file_name);
        //srv_sms_btmapc_xml_parse(file_name3);
    }
    else
    {
        test_aa = 0;
        srv_sms_btmapc_xml_parse(file_name2);
    }
    srv_sms_btmapc_cntx_callback(
        g_user_data,
        MMI_TRUE,
        0,
        NULL);
    //srv_sms_btmapc_succ_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, NULL, g_user_data, g_callback_func);
}

extern srv_sms_btmapc_bt_enum	g_sms_timeout_dev_index;	   /* Bt index ID */
void srv_sms_btmapc_delete_timeout(void)
{
    srv_sms_btmapc_delete_cntx_struct *delete_cntx = NULL;
    srv_sms_btmapc_bt_enum bt_index = g_sms_timeout_dev_index;
    
    StopTimer(SMS_BTMACSRV_TIMER_ID);
    delete_cntx = g_user_data;
    srv_sms_btmapc_delete_msg_detail(
                    bt_index,
                    delete_cntx->msg_id, 
                    MMI_FALSE,
                    delete_cntx);
}
#endif

MMI_BOOL srv_sms_btmapc_cancel_op(SMS_HANDLE srv_hd)
{
    srv_sms_btmapc_handle_struct *sms_cntx = (srv_sms_btmapc_handle_struct*)srv_hd;
    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    srv_sms_btmapc_set_curr_box(SRV_SMS_BTMAPC_BOX_NONE);
    if (sms_cntx != NULL)
    {
        srv_sms_btmapc_free_cntx(sms_cntx);
    }
    return MMI_TRUE;
}

extern MMI_BOOL g_sms_bt_disable_del_event;
SMS_HANDLE srv_sms_btmapc_get_msg_list_by_tab(
                srv_sms_btmapc_bt_enum bt_index,
                MMI_BOOL is_refresh,
                srv_sms_btmapc_box_enum box_type,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
#ifndef __MMI_BT_MAP_CLIENT_TEST__  
    SMS_HANDLE handle = NULL;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST, is_refresh, box_type, 0);
    kal_prompt_trace(MOD_MMI, "[SMS],srv_sms_btmapc_get_msg_list_by_tab bt_index = %d", bt_index);
	g_sms_bt_disable_del_event = MMI_TRUE;
    if(srv_sms_btmapc_get_curr_box() == SRV_SMS_BTMAPC_BOX_NONE || bt_index != g_sms_active_dev_index) 
    {
        handle = srv_sms_btmapc_change_folder(bt_index, box_type, SRV_BT_MAPC_ROOT, callback_func, user_data);
    }
    else
    {
        if(is_refresh == MMI_TRUE)
        {
            handle = srv_sms_btmapc_change_folder(bt_index, box_type, SRV_BT_MAPC_NEXT, callback_func, user_data);
        }
        else
        {
            srv_sms_btmapc_succ_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, NULL, user_data, callback_func);
        }
    }
    return handle;
#else
    SMS_HANDLE handle = NULL;
	g_sms_bt_disable_del_event = MMI_TRUE;
    if (is_refresh)
    {
        srv_sms_btmapc_change_folder_struct *change_folder_cntx = NULL;
        change_folder_cntx = srv_sms_btmapc_alloc_cntx(
                               sizeof(srv_sms_btmapc_change_folder_struct),
                               SRV_SMS_BTMAPC_OP_CHANGE_FOLDER,
                               callback_func,
                               user_data);
        change_folder_cntx->bt_index = bt_index;
        handle = (SMS_HANDLE)change_folder_cntx;
        g_user_data = change_folder_cntx;
        g_callback_func = callback_func;
        srv_sms_btmapc_set_curr_box(box_type);
        StartTimer(SMS_BTMACSRV_TIMER_ID,500,srv_sms_btmapc_timeout);
    }
    else
    {
        srv_sms_btmapc_set_curr_box(box_type);
        srv_sms_btmapc_succ_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, NULL, user_data, callback_func);
    }
    return handle;	
#endif
}


SMS_HANDLE srv_sms_btmapc_change_msg_status(
          srv_bt_mapc_bt_enum bt_index,
          U16 msg_id,
          srv_sms_status_enum status,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_change_status_cntx_struct *change_cntx = NULL;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CHANGE_MSG_STATUS, msg_id, status);
	
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_change_msg_status srv_sms_btmapc_alloc_cntx");
    change_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_status_cntx_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_STATUS,
                            callback_func,
                            user_data);
    if (change_cntx != NULL)
    {
        srv_sms_btmapc_change_msg_status_init(
                    change_cntx,
                    msg_id,
                    status);
        
        error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_CHANGE_STATUS);
        if(error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            srv_sms_status_enum msg_status;
            srv_sms_mti_enum mti;
            srv_sms_mti_enum msg_mti;

            msg_status = srv_sms_btmapc_get_msg_status(msg_id);
            if (status == msg_status)
            {
                srv_sms_btmapc_cntx_callback(
                        change_cntx,
                        MMI_TRUE,
                        SRV_SMS_CAUSE_NO_ERROR,
                        NULL);
                return NULL;
            }
            
            mti = srv_sms_btmapc_status_to_mti(status);
            msg_mti = srv_sms_btmapc_status_to_mti(msg_status);
            if (mti != msg_mti)
            {
                srv_sms_btmapc_cntx_callback(
                        change_cntx,
                        MMI_FALSE,
                        SRV_SMS_CAUSE_OP_NOT_ALLOWED,
                        NULL);
                return NULL;
            }
            if(msg_mti == SRV_SMS_MTI_DELIVER)
            {
                if(status == SRV_SMS_STATUS_READ)
                {
                    srv_sms_btmapc_set_msg_status_req(bt_index, msg_id, SRV_BT_MAP_MSG_STATUS_READ, (void *)change_cntx);
                }
                else if(status == SRV_SMS_STATUS_UNREAD)
                {
                    srv_sms_btmapc_set_msg_status_req(bt_index, msg_id, SRV_BT_MAP_MSG_STATUS_UNREAD, (void *)change_cntx);
                }
                else
                {
                    srv_sms_btmapc_cntx_callback(
                            change_cntx,
                            MMI_FALSE,
                            error_cause,
                            NULL);
                 }
            }  
        }
        else
        {    
            srv_sms_btmapc_cntx_callback(
                    change_cntx,
                    MMI_FALSE,
                    SRV_SMS_CAUSE_OP_NOT_ALLOWED,
                    NULL);
        }
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_STATUS, error_cause, user_data, callback_func);
    }
    return change_cntx;
}

#ifdef __MMI_BT_MAP_CLIENT_TEST__ 
srv_sms_btmapc_bt_enum	g_sms_timeout_dev_index;	   /* Bt index ID */
#endif

SMS_HANDLE srv_sms_btmapc_delete_msg(
		  srv_bt_mapc_bt_enum bt_index,
          U16 msg_id, 
          SrvSmsCallbackFunc callback_func, 
          void *user_data)
{
    srv_sms_cause_enum error_cause = SRV_SMS_CAUSE_NO_ERROR;
    srv_sms_btmapc_delete_cntx_struct *delete_cntx = NULL;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DELETE_MSG, msg_id);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_delete_msg srv_sms_btmapc_alloc_cntx");
    delete_cntx = srv_sms_btmapc_alloc_cntx(
                    sizeof(srv_sms_btmapc_delete_cntx_struct),
                    SRV_SMS_BTMAPC_OP_DELETE_MSG,
                    callback_func,
                    user_data);
    if(delete_cntx != NULL)
    {
        srv_sms_btmapc_delete_msg_init(
                delete_cntx,
                msg_id,
                MMI_FALSE);
        
        error_cause = srv_sms_btmapc_check_common_msg_error(msg_id, SRV_SMS_ACTION_DELETE);
        if(error_cause == SRV_SMS_CAUSE_NO_ERROR)
        {
            #ifdef __MMI_BT_MAP_CLIENT_TEST__ 
            g_user_data = delete_cntx;
            g_sms_timeout_dev_index = bt_index;
            StartTimer(SMS_BTMACSRV_TIMER_ID,100,srv_sms_btmapc_delete_timeout);
            /*srv_sms_btmapc_delete_msg_detail(
                    delete_cntx->msg_id, 
                    MMI_FALSE,
                    delete_cntx);*/
            #else
            if (srv_sms_btmapc_get_msg_status(msg_id) == SRV_SMS_STATUS_DRAFT &&
                srv_sms_btmapc_is_msg_local(msg_id) == MMI_TRUE)
            {
                srv_sms_btmapc_delete_msg_detail(
                    bt_index,
                    delete_cntx->msg_id, 
                    MMI_FALSE,
                    delete_cntx);
            }
            else
            {
                srv_sms_btmapc_set_msg_status_req(bt_index, msg_id, SRV_BT_MAP_MSG_STATUS_DELETE, (void *)delete_cntx);
            }
            #endif
        }
		else
			srv_sms_btmapc_cntx_callback(
	            (void *)delete_cntx,
	            MMI_FALSE,
	            SRV_SMS_BTMAPC_OP_FAIL,
	            NULL);
    }
    else
    {    
        error_cause = SRV_SMS_CAUSE_MEM_INSUFFICIENT;
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_DELETE_MSG, error_cause, user_data, callback_func);
    }
    return delete_cntx;
}


void srv_sms_btmapc_send_msg(
          SMS_HANDLE sms_handle, 
          SrvSmsCallbackFunc callback_func, 
          void *user_data)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_cause_enum cause = SRV_SMS_CAUSE_NO_ERROR;
    MMI_BOOL result = MMI_FALSE;
    S8* number = NULL;
    srv_sms_btmapc_handle_struct *sms_hd = (srv_sms_btmapc_handle_struct*) sms_handle;
    srv_sms_btmapc_send_handle_struct *hd_data = (srv_sms_btmapc_send_handle_struct*) sms_hd->hd_data;
    hd_data->callback_func = callback_func;
    hd_data->user_data = user_data;
    number = hd_data->msg_data.number;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SEND_MSG, sms_handle);
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_send_msg");
    if ((number[0] == '\0') && (number[1] == '\0'))
    {
        cause = SRV_SMS_CAUSE_NUMBER_EMPTY;
    }
    else if (srv_sms_btmapc_check_ucs2_number(number) == MMI_FALSE)
    {
        cause = SRV_SMS_CAUSE_NUMBER_INVALID;
    }
    if (cause == SRV_SMS_CAUSE_NO_ERROR)
    {
        srv_bt_mapc_push_message_req_struct req;
        result = srv_sms_btmapc_build_bmessage(hd_data, &req);
        if (result)
        {
            kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_send_msg  srv_sms_btmapc_send_msg_req ");
            srv_sms_btmapc_send_msg_req(&req, sms_handle);
        }
        else
        {	
            cause = SRV_SMS_CAUSE_FS_ERROR;
            srv_sms_btmapc_send_msg_callback(sms_handle, MMI_FALSE, cause);
        }
    }
    else
    {
        kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_send_msg  srv_sms_btmapc_send_msg_callback ");
        srv_sms_btmapc_send_msg_callback(sms_handle, MMI_FALSE, cause);
    }
}


SMS_HANDLE srv_sms_btmapc_read_msg(
                srv_sms_btmapc_bt_enum bt_index,	
                U16 msg_id,
                MMI_BOOL change_status,
                srv_sms_msg_data_struct* msg_data,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
    srv_sms_btmapc_read_cntx_struct *read_cntx = NULL;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_READ_MSG0, msg_id);
#ifndef __MMI_BT_MAP_CLIENT_TEST__ 
    if(srv_sms_btmapc_is_msg_download(bt_index, msg_id) == MMI_TRUE)
    {
#endif
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_READ_MSG1, msg_id);
        kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_read_msg srv_sms_btmapc_alloc_cntx");
        read_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_read_cntx_struct),
                        SRV_SMS_BTMAPC_OP_READ_MSG,
                        callback_func,
                        user_data);
        if(read_cntx != NULL)
        {
            srv_sms_btmapc_read_msg_init(
                    read_cntx,
                    msg_id,
                    change_status,
                    msg_data);
            read_cntx = srv_sms_btmapc_read_msg_detail(
                              bt_index,
                              msg_id, 
                              change_status, 
                              msg_data, 
                              (void *)read_cntx);
        }
#ifndef __MMI_BT_MAP_CLIENT_TEST__ 
    }
#endif
    return read_cntx;
}


SMS_HANDLE srv_sms_btmapc_get_msg(
                srv_bt_mapc_bt_enum bt_index,
                U16 msg_id,
                SrvSmsCallbackFunc callback_func,
                void *user_data)
{
#ifdef __MMI_BT_MAP_CLIENT_TEST__ 
    srv_sms_btmapc_get_msg_cntx_struct *get_msg_cntx = NULL;
    srv_bt_mapc_message_cnf_struct msg_cnf;
    WCHAR filename[] = L"z:\\aa\\bt_notify_map.vcf";
    get_msg_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_get_msg_cntx_struct),
                        SRV_SMS_BTMAPC_OP_GET_MSG,
                        callback_func,
                        user_data);
    get_msg_cntx->msg_id = msg_id;
	get_msg_cntx->bt_index = bt_index;
    memset(msg_cnf.file, 0, SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
    memcpy(msg_cnf.file, filename, mmi_wcslen(filename) * 2 + 2);
    msg_cnf.user_data = get_msg_cntx;
    msg_cnf.Error = 0;
    /*if (callback_func != NULL)
    {
        srv_sms_callback_struct callback_data;
        callback_data.result = MMI_TRUE;
        callback_data.cause = 0;
        callback_data.action = 0;
        callback_data.action_data = NULL;
        callback_data.user_data = user_data;
        callback_func(&callback_data);
    }
    return NULL;*/
   srv_sms_btmapc_get_msg_rsp(bt_index,&msg_cnf);
#else
    srv_sms_btmapc_get_msg_cntx_struct *get_msg_cntx = NULL;
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_get_msg srv_sms_btmapc_alloc_cntx");

    get_msg_cntx = srv_sms_btmapc_alloc_cntx(
                        sizeof(srv_sms_btmapc_get_msg_cntx_struct),
                        SRV_SMS_BTMAPC_OP_GET_MSG,
                        callback_func,
                        user_data);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG, msg_id, get_msg_cntx);
    if(get_msg_cntx != NULL)
    {
        get_msg_cntx->msg_id = msg_id;
        get_msg_cntx->bt_index = bt_index;		
        srv_sms_btmapc_get_msg_req(bt_index, msg_id, (void *)get_msg_cntx);
    }
    return get_msg_cntx;
#endif
}

void srv_sms_btmapc_abort(srv_sms_btmapc_bt_enum bt_index, SMS_HANDLE handle, SrvSmsCallbackFunc callback_func, void* user_data)
{
    srv_sms_btmapc_handle_struct *sms_cntx = (srv_sms_btmapc_handle_struct *)handle;
    sms_cntx->abort_func = callback_func;
    sms_cntx->abort_user_data = user_data;
    srv_bt_mapc_abort_req(bt_index, sms_cntx);
}

void srv_sms_btmapc_handle_evt(S32 srv_hd, srv_bt_mapc_cbevent_enum evt, void* para)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_HANDLE_EVT, evt);
    switch(evt)
    {
        case SRV_BT_MAPC_EVT_ID_CONNECT_RSP:
            srv_sms_btmapc_connect_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_DISCONNECT_RSP:
            srv_sms_btmapc_disconnect_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_DISCONNECT_IND:
            srv_sms_btmapc_disconnect_ind(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP:
			if(!g_sms_bt_opt_cancel_flag && !g_sms_bt_send_cancel_flag)
	            srv_sms_btmapc_set_folder_rsp(srv_hd, para);
            break;
        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
        case SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP:
            //parse msg list, emit evt can refresh folder
			if(!g_sms_bt_opt_cancel_flag && !g_sms_bt_send_cancel_flag)
            	srv_sms_btmapc_get_msg_list_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP:
            //emit evt
            srv_sms_btmapc_set_msg_status_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_GET_MSG_RSP:
            //Parse folder list
            srv_sms_btmapc_get_msg_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP:
            //emit evt
            if(!g_sms_bt_send_cancel_flag)
                srv_sms_btmapc_send_msg_rsp(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_MNS_IND:
            //emit evt, new msg incoming
            srv_sms_btmapc_handle_evt_report(srv_hd, para);
            break;
        case SRV_BT_MAPC_EVT_ID_ABORT_RSP:
        {
            srv_sms_btmapc_abort_rsp(srv_hd, para);
            break;
        }
        default:
            break;
    }
}


static void srv_sms_btmapc_connect_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_connect_rsp *res = (srv_bt_mapc_connect_rsp *)para;
    srv_sms_btmapc_conn_struct *event_data = OslMalloc(sizeof(srv_sms_btmapc_conn_struct));
    event_data->error = res->Error;
    event_data->bt_index = srv_hd;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_RSP, res->Error, res->user_data);
	if(srv_hd != g_sms_active_dev_index)
	{
		OslMfree(event_data);
		return;
	}
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_NEW_CONN);
        #ifndef __MMI_TELEPHONY_SUPPORT__
            srv_sms_btmapc_delete_all();
        #else /* __MMI_TELEPHONY_SUPPORT__ */
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif /* __MMI_TELEPHONY_SUPPORT__ */
    }
    srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_CONNECTED, event_data);
    OslMfree(event_data);
}


static void srv_sms_btmapc_disconnect_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_disconnect_rsp *res = (srv_bt_mapc_disconnect_rsp *)para;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    srv_sms_btmapc_conn_struct *event_data = OslMalloc(sizeof(srv_sms_btmapc_conn_struct));
    event_data->error = res->Error;
    event_data->bt_index = srv_hd;
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DISCONNECT_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
    	if(srv_hd == g_sms_active_dev_index)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            #ifdef __MMI_WEARABLE_DEVICE__
	        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
            #else
	        srv_sms_btmapc_delete_all();
            #endif
        #else /* __MMI_TELEPHONY_SUPPORT__ */
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        	#endif /* __MMI_TELEPHONY_SUPPORT__ */
        	srv_sms_btmapc_storage_save_data();
    	}
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_DISCONNECTED, event_data);
    }

    OslMfree(event_data);//emit evt
    srv_sms_btmapc_cntx_callback(
        res->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_disconnect_ind(S32 srv_hd, void* para)
{
    srv_sms_btmapc_conn_struct *event_data = OslMalloc(sizeof(srv_sms_btmapc_conn_struct));
	
	if(srv_hd == g_sms_active_dev_index)
    {
	    #ifndef __MMI_TELEPHONY_SUPPORT__
            #ifdef __MMI_WEARABLE_DEVICE__
	        srv_sms_btmapc_storage_reset_data(MMI_TRUE);
            #else
	        srv_sms_btmapc_delete_all();
            #endif
	    #else /* __MMI_TELEPHONY_SUPPORT__ */
	    srv_sms_btmapc_storage_reset_data(MMI_TRUE);
	    #endif /* __MMI_TELEPHONY_SUPPORT__ */
	    srv_sms_btmapc_storage_save_data();
	}
    event_data->error = SRV_BT_MAPC_SUCCESS;
    event_data->bt_index = srv_hd;
    srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_DISCONNECTED, event_data);
    OslMfree(event_data);//emit evt
}


SMS_HANDLE srv_sms_btmapc_change_folder(
          srv_sms_btmapc_bt_enum bt_index,
          srv_sms_btmapc_box_enum box_type,
          srv_btmapc_folder_flag_enum folder_flag,
          SrvSmsCallbackFunc callback_func,
          void *user_data)
{
    CHAR path[32] = {0};
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = NULL;
    srv_bt_mapc_set_msg_listing_prop_struct msg_property = {0};
    MMI_BOOL change_folder_result = MMI_TRUE;
    
    kal_prompt_trace(MOD_MMI, "[SMS], Entry srv_sms_btmapc_change_folder srv_sms_btmapc_alloc_cntx");
    change_folder_cntx = srv_sms_btmapc_alloc_cntx(
                            sizeof(srv_sms_btmapc_change_folder_struct),
                            SRV_SMS_BTMAPC_OP_CHANGE_FOLDER,
                            callback_func,
                            user_data);
	g_sms_bt_opt_cancel_flag = 0;
	g_sms_bt_send_cancel_flag = 0;

    if(change_folder_cntx != NULL)
    {
        srv_sms_btmapc_box_enum curr_box;
        srv_sms_action_enum curr_op;
        MMI_BOOL result;
        
        change_folder_cntx->curr_box_type = box_type;
        change_folder_cntx->bt_index = bt_index;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST, MMI_TRUE, box_type, change_folder_cntx);
		
        curr_box = srv_sms_btmapc_get_curr_box();
        curr_op = srv_sms_btmapc_get_curr_op();
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST_STATUS, folder_flag, curr_box, curr_op);
        if(curr_box == SRV_SMS_BTMAPC_BOX_NONE)
        {
            if(folder_flag == SRV_BT_MAPC_ROOT)
            {
                if(curr_op != SRV_SMS_BTMAPC_OP_NONE)
                {
					srv_sms_btmapc_free_cntx(change_folder_cntx); 
					change_folder_cntx = NULL;
                    srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_CAUSE_NOT_READY, user_data, callback_func);
                    return NULL;
                }
                srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER);
                change_folder_result = srv_mapc_change_folder(bt_index, NULL, folder_flag, SRV_BT_MAPC_NONE, (void *)change_folder_cntx);
            }
        }
        else
        {
            result = srv_sms_btmapc_get_folder_path(box_type, path);
            if(!result)
            {
            	srv_sms_btmapc_free_cntx(change_folder_cntx);
            	change_folder_cntx = NULL;
                srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_BTMAPC_OP_FAIL, user_data, callback_func);
                return NULL;
            }
            srv_sms_btmapc_set_list_property(&msg_property);
            srv_bt_mapc_set_msg_listing_prop(bt_index, &msg_property);
           
            if((curr_box == SRV_SMS_BTMAPC_BOX_ROOT && folder_flag == SRV_BT_MAPC_FORWARD) ||
                (curr_box > SRV_SMS_BTMAPC_BOX_NONE && curr_box < SRV_SMS_BTMAPC_BOX_ROOT && folder_flag == SRV_BT_MAPC_NEXT))
            {
                if(curr_op != SRV_SMS_BTMAPC_OP_NONE)
                {
                	srv_sms_btmapc_free_cntx(change_folder_cntx);
                	change_folder_cntx = NULL;
                    //srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_BTMAPC_OP_FAIL, user_data, callback_func);
                    return NULL;
                }
                srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER);
                change_folder_result = srv_mapc_change_folder(bt_index, (U8 *)path, folder_flag, SRV_BT_MAPC_MESSAGE_LIST_ONLY, (void *)change_folder_cntx);
            }
        }
    }
    else
    {    
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_CAUSE_MEM_INSUFFICIENT, user_data, callback_func);
    }
    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6," chagefolder result: %d", change_folder_result);
    if (!change_folder_result)
    {
    	srv_sms_btmapc_free_cntx(change_folder_cntx);
    	change_folder_cntx = NULL;
        srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
        srv_sms_btmapc_error_callback(SRV_SMS_BTMAPC_OP_CHANGE_FOLDER, SRV_SMS_BTMAPC_OP_FAIL, user_data, callback_func);
    }
    return (SMS_HANDLE)change_folder_cntx;
}


static void srv_sms_btmapc_set_folder_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_set_folder_res *res = (srv_bt_mapc_set_folder_res *)para;
    srv_sms_btmapc_change_folder_struct *change_folder_cntx = (srv_sms_btmapc_change_folder_struct *)res->user_data;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;

    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_CONNECT_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {        
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        if(srv_sms_btmapc_get_curr_box() == SRV_SMS_BTMAPC_BOX_NONE)
        {
            srv_sms_btmapc_handle_struct *sms_cntx;
            
            srv_sms_btmapc_set_curr_box(SRV_SMS_BTMAPC_BOX_ROOT);
            sms_cntx = (srv_sms_btmapc_handle_struct*)res->user_data;
            srv_sms_btmapc_change_folder(change_folder_cntx->bt_index, change_folder_cntx->curr_box_type, SRV_BT_MAPC_FORWARD, sms_cntx->callback_func, sms_cntx->user_data);
            srv_sms_btmapc_free_cntx(sms_cntx);
            return;
        }
        else
        {
            srv_sms_btmapc_set_curr_box(change_folder_cntx->curr_box_type);
        }
    }
    else if (res->Error != SRV_BT_MAPC_SUCCESS)
    {
    	if(res->Error == SRV_BT_MAPC_FAIL_BAD_STATE)
		{
			error_cause = SRV_SMS_CAUSE_NOT_READY;
		}
        srv_sms_btmapc_cntx_callback(
            res->user_data,
            result,
            error_cause,
            NULL);
    }
}


static void srv_sms_btmapc_get_msg_list_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_get_msg_listing_rsp *rsp = (srv_bt_mapc_get_msg_listing_rsp *)para;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_LIST_RSP, rsp->Error, rsp->user_data);
    if(rsp->Error == SRV_BT_MAPC_SUCCESS && rsp->file != NULL)
    {
        srv_sms_btmapc_box_enum curr_box = srv_sms_btmapc_get_curr_box();
        kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_6,"get msg list rsp, curr_box: %d", curr_box);
        result = MMI_TRUE;
        error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        if(curr_box == SRV_SMS_BTMAPC_BOX_NONE)
        {
            srv_sms_btmapc_cntx_callback(
                rsp->user_data,
                MMI_FALSE,
                SRV_SMS_BTMAPC_OP_FAIL,
                NULL);
            return;	
        }
		
        if (curr_box != SRV_SMS_BTMAPC_BOX_UNSENT)
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            #ifdef __MMI_WEARABLE_DEVICE__
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
            #else
            srv_sms_btmapc_delete_all();
            #endif
        #else /* __MMI_TELEPHONY_SUPPORT__ */
            srv_sms_btmapc_storage_reset_data(MMI_TRUE);
        #endif /* __MMI_TELEPHONY_SUPPORT__ */
        }
        srv_sms_btmapc_set_curr_box(curr_box);
        srv_sms_btmapc_xml_parse((WCHAR *)rsp->file); 
        //FS_Delete((WCHAR *)rsp->file);
    }
	else if(rsp->Error == SRV_BT_MAPC_FAIL_BAD_STATE)
	{
		error_cause = SRV_SMS_CAUSE_NOT_READY;
	}
#ifdef __SRV_SMS_BTMAPC_TEST__
    srv_sms_btmapc_write_file(OUTPUT_MSG_LIST, (void *)srv_sms_btmapc_msg_list);
#endif
    srv_sms_btmapc_cntx_callback(
        rsp->user_data,
        result,
        error_cause,
        NULL);
}


static void srv_sms_btmapc_get_msg_req(srv_bt_mapc_bt_enum bt_index, U16 msg_id, void *userData)
{
    U8 *msg_handle = NULL;
#ifndef __MMI_BT_MAP_CLIENT_TEST__  
    if(srv_sms_btmapc_is_msg_download(bt_index, msg_id) == MMI_TRUE)
    {
        srv_sms_btmapc_cntx_callback(
                    userData,
                    MMI_TRUE,
                    SRV_SMS_BTMAPC_OP_SUCC,
                    NULL);
        return;
    }
#endif   
    msg_handle = srv_sms_btmapc_get_msg_handle(msg_id);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG, msg_id, userData);
    
    if(msg_handle != NULL)
    {
        if(srv_sms_btmapc_get_curr_op() != SRV_SMS_BTMAPC_OP_NONE)
        {
            srv_sms_btmapc_cntx_callback(
                userData,
                MMI_FALSE,
                SRV_SMS_CAUSE_NOT_READY,
                NULL);
            return;
        }
        srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_GET_MSG);
        srv_bt_mapc_get_msg_req(bt_index, msg_handle, MMI_FALSE, SRV_BT_CHARSET_UTF8, userData);
    }
    else
    {
        srv_sms_btmapc_cntx_callback(
            userData,
            MMI_FALSE,
            SRV_SMS_BTMAPC_OP_FAIL,
            NULL);
    }
}


static void srv_sms_btmapc_get_msg_rsp(S32 srv_hd, void* para)
{
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    srv_bt_mapc_message_cnf_struct *res = (srv_bt_mapc_message_cnf_struct *)para;
    srv_sms_btmapc_get_msg_cntx_struct *get_msg_cntx = (srv_sms_btmapc_get_msg_cntx_struct *)res->user_data;
    U16 msg_id = get_msg_cntx->msg_id;

    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        S32 fs_res = 0;
        U8 index = 0;
        //MBT_MAP_MSG_OBJECT *msg = (MBT_MAP_MSG_OBJECT *)OslMalloc(sizeof(MBT_MAP_MSG_OBJECT));
        WCHAR orig_filename[SRV_FMGR_PATH_MAX_LEN];
        WCHAR file_name[SRV_SMS_BTMAPC_MAX_PATH_LEN];

        memset(msg,0, sizeof(MBT_MAP_MSG_OBJECT));
        memset(orig_filename, 0, SRV_FMGR_PATH_MAX_LEN + 1);
        memset(file_name, 0, SRV_SMS_BTMAPC_MAX_PATH_LEN);
        srv_sms_btmapc_get_msg_name(srv_hd, msg_id, MMI_FALSE, file_name);
        if(srv_sms_btmapc_file_exist(file_name))
        {
            FS_Delete(file_name);
        }
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_GET_MSG_ID, msg_id);
        kal_wsprintf(orig_filename, BT_MAP_RCV_MESSAGE_PUSH_FILE, 0);
        fs_res = FS_Move((WCHAR *)res->file, orig_filename, FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, 0);
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_MOVE_FILE, fs_res);
        if(fs_res < 0)
        {
            result = MMI_FALSE;
            error_cause = SRV_SMS_CAUSE_FS_ERROR;
        }
        else
        {
            result = btmtk_map_vcard_parse_message_by_file(0, msg, NULL, file_name);
            MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_WRITE_CONTENT, 1, result, 0);
        }
        if (result)
        {
            S32 file_handle = 0;
            U32 real_size = 0;
            U32 read_size;
            U8 sms_content[SRV_SMS_BTMAPC_MAX_DISPLAY_BUFF_SIZE];
            
            if((file_handle = FS_Open(file_name, FS_READ_ONLY)) >= 0)
            {
                FS_GetFileSize(file_handle, &real_size);
                read_size = real_size;
                
                if(read_size > SRV_SMS_BTMAPC_MAX_DISPLAY_BUFF_SIZE)
                {
                    read_size = SRV_SMS_BTMAPC_DISPLAY_CHAR_SIZE;
                    //sms_content = (U8 *)OslMalloc(read_size);
                    memset(sms_content, 0, SRV_SMS_BTMAPC_MAX_DISPLAY_BUFF_SIZE);
                    
                    FS_Read(file_handle, sms_content, SRV_SMS_BTMAPC_MAX_DISPLAY_BUFF_SIZE, &read_size);
                    FS_Close(file_handle);
                    FS_Delete(file_name);
                    if((file_handle = FS_Open(file_name, FS_READ_WRITE | FS_CREATE)) >= 0)
                    {
                        FS_Write(file_handle, sms_content, read_size, &read_size);
                        //FS_Close(file_handle);
                    }
                   // OslMfree(sms_content);
                }
                FS_Close(file_handle);
                srv_sms_btmapc_set_msg_size(msg_id, read_size, real_size);
            }
            else
            {
                //create a file with no content
                if(srv_sms_btmapc_file_exist(file_name) == MMI_FALSE)
                {
                    if((file_handle = FS_Open(file_name, FS_READ_WRITE | FS_CREATE)) >= 0)
                    {
                        FS_Close(file_handle);
                    }
                }
            }
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            result = MMI_TRUE;
            error_cause = SRV_SMS_BTMAPC_OP_SUCC;
        }
        if (msg->Originator)
    	{
    		OslMfree(msg->Originator);
    		msg->Originator = NULL;
    	}
    	for( ;index < MBT_MAP_MAX_MSG_ENVELOPE_NUM; index++)
    	{
    		if (msg->Envelope[index].Recipient) 
    		{
    			OslMfree(msg->Envelope[index].Recipient);
    			msg->Envelope[index].Recipient = NULL;
    		}
    	}
        //OslMfree(msg);
        //OslMfree(orig_filename);
    }
	else if(res->Error == SRV_BT_MAPC_FAIL_BAD_STATE)
	{
		error_cause = SRV_SMS_CAUSE_NOT_READY;
	}
    srv_sms_btmapc_callback(
        SRV_SMS_BTMAPC_OP_GET_MSG,
        result,
        error_cause,
        NULL,
        res->user_data,
        srv_sms_btmapc_save_sms_callback);
}


static void srv_sms_btmapc_set_msg_status_req(srv_bt_mapc_bt_enum bt_index, U16 msg_id, srv_bt_mapc_msg_status_enum status, void *userData)
{
    U8 *msg_handle = NULL;
    
    if(srv_sms_btmapc_is_msg_exist(msg_id))
    {
        msg_handle = srv_sms_btmapc_get_msg_handle(msg_id);
    }
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SET_MSG_STATUS_REQ, status, userData);
    if(msg_handle != NULL)
    {
        if(srv_sms_btmapc_get_curr_op() != SRV_SMS_BTMAPC_OP_NONE)
        {
            srv_sms_btmapc_cntx_callback(
                userData,
                MMI_FALSE,
                SRV_SMS_CAUSE_NOT_READY,
                NULL);
            return;
        }
        srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_CHANGE_STATUS);
        srv_bt_mapc_set_message_status_req(bt_index, msg_handle, status, userData);
    }
    else
    {
        srv_sms_btmapc_cntx_callback(
            userData,
            MMI_FALSE,
            SRV_SMS_BTMAPC_OP_FAIL,
            NULL);
    }
}


static void srv_sms_btmapc_set_msg_status_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_set_message_status_rsp *res = (srv_bt_mapc_set_message_status_rsp *)para;
    srv_sms_btmapc_handle_struct *sms_btmapc_cntx = (srv_sms_btmapc_handle_struct*)res->user_data;
    MMI_BOOL result = MMI_FALSE;
    srv_sms_cause_enum error_cause = SRV_SMS_BTMAPC_OP_FAIL;
    
    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SET_MSG_STATUS_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        if(sms_btmapc_cntx->action == SRV_SMS_BTMAPC_OP_DELETE_MSG)
        {
            srv_sms_btmapc_delete_cntx_struct *delete_cntx = (srv_sms_btmapc_delete_cntx_struct *)res->user_data;
            srv_sms_btmapc_delete_msg_detail(
                srv_hd,
                delete_cntx->msg_id, 
                MMI_FALSE,
                delete_cntx);
        }
        else if(sms_btmapc_cntx->action == SRV_SMS_BTMAPC_OP_CHANGE_STATUS)
        {
            srv_sms_btmapc_change_status_cntx_struct *change_cntx = (srv_sms_btmapc_change_status_cntx_struct *)res->user_data;
            srv_sms_btmapc_change_msg_status_detail(
                change_cntx->msg_id,
                change_cntx->status,
                change_cntx);
        }      
    }
    else
    {
    	if(res->Error == SRV_BT_MAPC_FAIL_BAD_STATE)
		{
			error_cause = SRV_SMS_CAUSE_NOT_READY;
		}
        srv_sms_btmapc_cntx_callback(
            res->user_data,
            result,
            error_cause,
            NULL);
    }
}


static void srv_sms_btmapc_send_msg_req(srv_bt_mapc_push_message_req_struct *req, void *userData)
{
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SEND_MSG_REQ, userData);
    if(srv_sms_btmapc_get_curr_op() != SRV_SMS_BTMAPC_OP_NONE)
    {
        if(userData != NULL)
        {
            srv_sms_btmapc_send_msg_callback(userData, MMI_FALSE, SRV_SMS_CAUSE_NOT_READY);
        }
        return;
    }
    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_SEND_MSG);
    srv_bt_mapc_push_message_req(req->bt_index, req, userData);
}


static void srv_sms_btmapc_send_msg_rsp(S32 srv_hd, void* para)
{
    srv_bt_mapc_push_message_status_res *res = (srv_bt_mapc_push_message_status_res *)para;
    srv_sms_cause_enum cause = SRV_SMS_BTMAPC_OP_FAIL;
    MMI_BOOL result = MMI_FALSE;
    
    srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_SEND_MSG_RSP, res->Error, res->user_data);
    if(res->Error == SRV_BT_MAPC_SUCCESS)
    {
        cause = SRV_SMS_BTMAPC_OP_SUCC;
        result = MMI_TRUE;
    }
	else if(res->Error == SRV_BT_MAPC_FAIL_BAD_STATE)
	{
		cause = SRV_SMS_CAUSE_NOT_READY;
	}
    if(res->user_data != NULL && g_srv_sms_bt_send_handle != NULL)
    {
        srv_sms_btmapc_send_msg_callback(res->user_data, result, cause);
    }
}

static void srv_sms_btmapc_handle_evt_report(S32 srv_hd, void* para)
{
    //may be can notify number, and
    srv_bt_mapc_mns_send_event_ind_struct* newMsgInd = (srv_bt_mapc_mns_send_event_ind_struct *)para;
    
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_HANDLE_EVT_REPORT, newMsgInd->data_size);
    if(newMsgInd->data_size > 0 && newMsgInd->file != NULL)
    {
        kal_int32 count = 0;
        count = srv_sms_btmapc_xml_parse((WCHAR *)newMsgInd->file);
        if (count == 0)
        {
            srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, SRV_SMS_BTMAPC_FILE_ERROR);
        }
        else
        {
            if (sms_btmapc_evt_report.evt_report_type == SRV_SMS_BTMAPC_NEW_MSG)
            {
                srv_sms_btmapc_event_new_sms_struct *event_data = NULL;
                event_data = (srv_sms_btmapc_event_new_sms_struct *)OslMalloc(sizeof(srv_sms_btmapc_event_new_sms_struct));

                event_data->box_type = sms_btmapc_evt_report.box_type;
                event_data->bt_index = newMsgInd->bt_index;
                srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index,SRV_SMS_BTMAPC_NEW_MSG);
                srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_NEW_MSG, event_data);

                if (event_data != NULL)
                {
                    OslMfree(event_data);
                }
            }
            else if (sms_btmapc_evt_report.evt_report_type == SRV_SMS_BTMAPC_MSG_DELETED)
            {
                srv_sms_btmapc_event_new_sms_struct *event_data = NULL;
                U16 msg_id = srv_sms_btmapc_get_msg_id_by_handle((U8 *)sms_btmapc_evt_report.msg_handle);
                MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_HANDLE_EVT_REPORT_DEL, msg_id);

                event_data = (srv_sms_btmapc_event_new_sms_struct *)OslMalloc(sizeof(srv_sms_btmapc_event_new_sms_struct));
                event_data->bt_index = newMsgInd->bt_index;
                srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_DEL_MSG, event_data);
                    
                if (event_data != NULL)
                {
                    OslMfree(event_data);
                }
                srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, SRV_SMS_BTMAPC_MSG_DELETED);
            }
            else if (sms_btmapc_evt_report.evt_report_type == SRV_SMS_BTMAPC_MSG_SHIFT)
            {
                srv_sms_btmapc_box_enum curr_box = srv_sms_btmapc_get_curr_box();
                srv_sms_event_update_struct *event_data = NULL;
                event_data = (srv_sms_event_update_struct *)OslMalloc(sizeof(srv_sms_event_update_struct));
                event_data->bt_index = newMsgInd->bt_index;
                srv_sms_btmapc_set_curr_box(curr_box);
                srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, SRV_SMS_BTMAPC_MSG_SHIFT);
				
                #ifndef __MMI_WEARABLE_DEVICE__
                srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_RESET_LIST, event_data);                
                #endif
				
                if (event_data != NULL)
                {
                    OslMfree(event_data);
                }
            }
            else if (sms_btmapc_evt_report.evt_report_type == SRV_SMS_BTMAPC_NOT_SUPPORTED)			
            {
                srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, SRV_SMS_BTMAPC_NOT_SUPPORTED);
            }
            else
            {
                srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, sms_btmapc_evt_report.evt_report_type);
            }
        }
    }
    else
    {
        srv_sms_btmapc_send_evt_rsp(newMsgInd->bt_index, SRV_SMS_BTMAPC_FILE_ERROR);
    }
}

void srv_sms_btmapc_send_evt_rsp(srv_bt_mapc_bt_enum bt_index, srv_sms_btmapc_ind_enum type)
{
    srv_bt_mapc_mns_send_event_rsp_struct rsp;
    srv_bt_mapc_result_enum result = SRV_BT_MAPC_SUCCESS;
    
    switch(type)
    {
        case SRV_SMS_BTMAPC_NEW_MSG:
        case SRV_SMS_BTMAPC_DELI_SUCC:
        case SRV_SMS_BTMAPC_SEND_SUCC:
        case SRV_SMS_BTMAPC_MSG_DELETED:
        case SRV_SMS_BTMAPC_MSG_SHIFT:    
        case SRV_SMS_BTMAPC_NOT_SUPPORTED:  
            result = SRV_BT_MAPC_SUCCESS;
            break;
        case SRV_SMS_BTMAPC_MEM_FULL:
            result = SRV_BT_MAPC_FAIL_STORAGE_FULL;
            break;
        case SRV_SMS_BTMAPC_FILE_ERROR:
            result = SRV_BT_MAPC_FAIL_NO_RESOURCE;
            break;
        default:
            break;
    }
    rsp.result = result;
    rsp.index_order = bt_index;
    srv_bt_mapc_mns_send_event_rsp(bt_index, rsp);
}

void srv_sms_btmapc_abort_rsp(S32 srv_hd, void* para)
{
    srv_mapc_abort_cnf *abort_cnf = (srv_mapc_abort_cnf *)para;
    srv_sms_btmapc_handle_struct *sms_cntx = (srv_sms_btmapc_handle_struct*)abort_cnf->user_data;
    
    srv_sms_action_enum curr_op = srv_sms_btmapc_get_curr_op();
    if(curr_op != SRV_SMS_BTMAPC_OP_NONE)
    {
        if(abort_cnf->Error == SRV_BT_MAPC_SUCCESS)
        {
            srv_sms_btmapc_set_curr_op(SRV_SMS_BTMAPC_OP_NONE);
            srv_sms_btmapc_abort_ex(sms_cntx, sms_cntx->callback_func, sms_cntx->user_data);
        }
    }
    else
    {
        srv_sms_btmapc_abort_ex(sms_cntx, sms_cntx->callback_func, sms_cntx->user_data);
    }
}


static MMI_BOOL srv_sms_btmapc_build_bmessage(srv_sms_btmapc_send_handle_struct *hd_data, srv_bt_mapc_push_message_req_struct *req)
{
    MBT_MAP_MSG_OBJECT *msg = (MBT_MAP_MSG_OBJECT *)OslMalloc(sizeof(MBT_MAP_MSG_OBJECT));
    MMI_BOOL result;
    WCHAR *cont_filename;
    U8 *sms_content;
    U32 sms_content_size = 0;
    U32 content_size;
    S32 fhandle;
    U32 bytes_written =0;
	int ret = 0;
    char number[SRV_SMS_MAX_ADDR_LEN +1];
    srv_sms_btmapc_int_msg_data_struct *msg_data;

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_BUILD_BMSG0);
    cont_filename = (WCHAR *)OslMalloc(SRV_FMGR_PATH_MAX_LEN + 1);
    kal_wsprintf(cont_filename, SMS_BT_BMESSAGE_CONTENT_SEND, 0);
    if ((fhandle = FS_Open(cont_filename, FS_READ_WRITE | FS_CREATE)) < 0)
    {
     	kal_prompt_trace(MOD_MMI, "[SMS]srv_sms_btmapc_build_bmessage FS_Open:ret = %d", fhandle);
        OslMfree(msg);
        OslMfree(cont_filename);
        return MMI_FALSE;
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_BUILD_BMSG1);
    msg_data = &(hd_data->msg_data);
    content_size = mmi_wcslen((WCHAR *)msg_data->content_buff);
    if(content_size > SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE / 3)
    {
        content_size = SRV_SMS_BTMAPC_DISPLAY_BUFFER_SIZE / 3;
    }
    sms_content_size = content_size * 3 + 1;
    sms_content = (U8 *)OslMalloc(sms_content_size);
    memset(sms_content, 0, sms_content_size);
    mmi_chset_ucs2_to_utf8_string(sms_content, sms_content_size, (U8 *)msg_data->content_buff);
    sms_content_size = strlen(sms_content);
    //memset(msg_data->content_buff, 0, msg_data->content_buff_size);
    //memcpy(msg_data->content_buff, sms_content, sms_content_size);
    
    ret = FS_Write(fhandle, sms_content, sms_content_size, &bytes_written);
    //FS_Write(fhandle, msg_data->content_buff, msg_data->content_buff_size, &bytes_written);  
    kal_prompt_trace(MOD_MMI, "[SMS]build_bmessage FS_Write:ret=%d,len=%d,written_len=%d", ret,sms_content_size,bytes_written);
    OslMfree(sms_content);
    FS_Close(fhandle);
        
    memset(msg, 0x00, sizeof(MBT_MAP_MSG_OBJECT));
    msg->MsgVer = MBT_MAP_MSG_VER_10;
    msg->ReadStatus = MBT_MAP_MSG_STATUS_UNREAD;
    msg->MsgType = MBT_MAP_MSG_TYPE_SMS_GSM;
    
    memcpy(msg->FolderPath, MSG_ROOT_PATH, strlen(MSG_ROOT_PATH));
    strcat(msg->FolderPath, OUTBOX_PATH);

    msg->Originator = (char *)OslMalloc(SMS_BT_MAX_FOLDER_LENGTH);
    sprintf(msg->Originator, "%s%s", OPER_BVCARD, OPER_END);
    strcat(msg->Originator, OPER_VERSION);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_NAME);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_TEL);
    strcat(msg->Originator, OPER_END);
    strcat(msg->Originator, OPER_EVCARD);
    msg->OriginatorSize = strlen(msg->Originator);

    msg->Envelope[0].Recipient = (char *)OslMalloc(SMS_BT_MAX_FOLDER_LENGTH);
    sprintf(msg->Envelope[0].Recipient, "%s%s", OPER_BVCARD, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_VERSION);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_NAME);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_TEL);
    mmi_ucs2_to_asc(number, (hd_data->msg_data).number);
    strcat(msg->Envelope[0].Recipient, number);
    strcat(msg->Envelope[0].Recipient, OPER_END);
    strcat(msg->Envelope[0].Recipient, OPER_EVCARD);
    msg->Envelope[0].RecipientSize = strlen(msg->Envelope[0].Recipient);   
    
    msg->Charset = MBT_MAP_MSG_CHARSET_UTF8;

    msg->FragmentNum = 1;
    msg->FragmentSize[0] = bytes_written;

    msg->ContentSize = bytes_written;
    result = btmtk_map_vcard_create_message_by_file(0,
                                                    MBT_MAP_FRAC_REQ_NO,
                                                    MBT_MAP_FRAC_DELIVER_NO,
                                                    msg,
                                                    0,
                                                    cont_filename);
    if (result)
    {
        S32 fileHandle;
        U32 size = 0;
        req->charset = MBT_MAP_MSG_CHARSET_UTF8;
        req->bt_index = hd_data->send_bt_index;

        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_BUILD_BMSG2);
        mmi_asc_to_ucs2((CHAR *)req->child_folder, (CHAR *)OUTBOX_PATH);
        kal_wsprintf((WCHAR *)req->file, BT_MAP_MESSAGE_GET_FILE, 0);
        if ((fileHandle = FS_Open((WCHAR *)req->file, FS_READ_ONLY)) < 0)
        {
            req->data_size = 0;
        }
        else
        {
            FS_GetFileSize(fileHandle, &size);
            req->data_size = (U16)size;
            FS_Close(fileHandle);
        }        
    }
    
    FS_Delete(cont_filename);
    OslMfree(msg->Originator);
    OslMfree(msg->Envelope[0].Recipient);
    OslMfree(msg);
    OslMfree(cont_filename);
    return result;
}



static void srv_sms_btmapc_set_list_property(srv_bt_mapc_set_msg_listing_prop_struct *msg)
{
    msg->FilterMessageType = SRV_BT_MAPC_FILTER_MSG_TYPE_SMS_CDMA | SRV_BT_MAPC_FILTER_MSG_TYPE_EMAIL | SRV_BT_MAPC_FILTER_MSG_TYPE_MMS;
    msg->FilterPriority = SRV_BT_MAPC_NO_PRIORITY;
    msg->Maxlistcount = SRV_SMS_BTMAPC_MAX_SMS_ENTRY;
    msg->ListStartOffset = 0;
    msg->SubjectLength = SRV_SMS_MSG_INFO_CONTENT_LEN;
    msg->ParameterMask = SRV_BT_MAPC_PARAMETER_MSGLISTING_ALL & (~SRV_BT_MAPC_PARAMETER_MSGLISTING_REPLY_TOADDRESSING);
    msg->FilterReadStatus = SRV_BT_MAPC_NO_READ_FILTER;
}

static void srv_sms_btmapc_save_sms_callback(srv_sms_callback_struct* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_get_msg_cntx_struct* get_msg_cntx = (srv_sms_btmapc_get_msg_cntx_struct*)user_data->user_data;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (user_data->result == MMI_FALSE)
    {
        if (user_data->cause == SRV_SMS_CAUSE_MEM_FULL)    
        {
            srv_sms_event_mem_exceed_struct *event_data;

            event_data = (srv_sms_event_mem_exceed_struct *)OslMalloc(sizeof(srv_sms_event_mem_exceed_struct));
            //error_cause = SRV_SMS_FCS_MEM_EXCEED;                
            event_data->mem_type = SRV_SMS_MEM_ME_ONLY;            
            srv_sms_btmapc_emit_event(EVT_ID_SRV_SMS_BTMAPC_MEM_EXCEED, event_data);
            OslMfree(event_data);
        }
    }
    else
    {    
        U16 msg_id = get_msg_cntx->msg_id;
        MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_DOWNLOAD_DONE);
        srv_sms_btmapc_set_msg_download(msg_id, MMI_TRUE);
    }

    srv_sms_btmapc_cntx_callback(
        get_msg_cntx,
        user_data->result,
        user_data->cause,
        NULL);
}

MMI_BOOL srv_sms_btmapc_check_mapc_status(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(srv_bt_mapc_is_available(g_sms_active_dev_index) == MMI_TRUE)
        return MMI_TRUE;
    else
        return MMI_FALSE;
}

#endif /* __SRV_SMS_BTMAPC__ */


