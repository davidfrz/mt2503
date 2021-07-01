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
 *  BtNotiSrvParser.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  SMS Service For BT Parser Xml File
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
#ifdef __MMI_BT_NOTI_SRV__

#include "xml_def.h"
#include "Stdlib.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "MMI_common_app_trc.h"
#include "MMI_trc_Int.h"
#include "BtNotifySrvParser.h"
#include "xmlgen_common.h"
#include "xmlgen.h"
#include "app_base64.h"
#include "mmi_frm_mem_gprot.h"
#include "BTNotiSrvGprot.h"
#include "MMI_conn_app_trc.h"
#include "BtNotiSrvData.h"

/***************************************************************************** 
 * define
 *****************************************************************************/
 
#define BT_NOTIFY_NODE_LEVEL_1              1
#define BT_NOTIFY_NODE_LEVEL_2              2
#define BT_NOTIFY_NODE_LEVEL_3              3
#define BT_NOTIFY_NODE_LEVEL_4              4


#define BT_NOTIFY_TYPE_DATA                 1
#define BT_NOTIFY_TYPE_ATTR                 2
#define NOTIFY_READ_BUFFER_LEN              240
#define MAX_BYTES_EACH_CHARACTER_IN_UTF8    3       /* max 3 bytes for each character when use utf-8 */

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef kal_int32 (*srv_bt_notify_call)(const kal_char *, const kal_char **, const kal_char *, kal_int32);

typedef struct 
{
    kal_char *name;
    kal_uint16 deep;
    kal_uint16 type;
    srv_bt_notify_call call_back;
} bt_notify_node_struct;

typedef struct 
{
    kal_uint8 stack;
    MMI_BOOL is_run;
    srv_bt_notify_parse_para para_flag;
    srv_bt_parse_xml_callback callback;
    void *data;
    void *user_data;
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    U32 curr_action_id_index;
    U32 curr_action_name_index;
    U32 curr_page_indx;
#endif
} bt_notify_parser_struct;

/***************************************************************************** 
 * Static function
 *****************************************************************************/

static kal_int32 srv_bt_notify_node_category(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_subtype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_msgid(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_action(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_page_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_page_indx(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_group_id(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_sender(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_appid(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_title(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_ticker_text(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_content(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_timestamp(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_action_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_action_id(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_action_name(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_icon(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 srv_bt_notify_node_missed_call_count(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static void srv_bt_notify_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error);
static void srv_bt_notify_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error);
static void srv_bt_notify_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error);
static kal_int32 srv_bt_notify_xml_gen_header(XG_HANDLE xml_gen_handle, srv_bt_notify_data_struct *data);
static kal_int32 srv_bt_notify_xml_gen_body(XG_HANDLE xml_gen_handle, srv_bt_notify_data_struct *data);

/***************************************************************************** 
 * Variable
 *****************************************************************************/
 
static bt_notify_parser_struct g_bt_notify_parser = {0};

static const char NOTIFY_REPORT[]               = "event_report";
static const char NOTIFY_HEADER[]               = "header";
static const char NOTIFY_BODY[]                 = "body";

static const char NOTIFY_CATEGORY[]             = "category";
static const char NOTIFY_SUBTYPE[]              = "subType";
static const char NOTIFY_MSGID[]                = "msgId";
static const char NOTIFY_ACTION[]               = "action";
static const char NOTIFY_SENDER[]               = "sender";
static const char NOTIFY_APPID[]                = "appId";
static const char NOTIFY_TITLE[]                = "title";
static const char NOTIFY_TICKER[]               = "ticker_text";
static const char NOTIFY_CONTENT[]              = "content";
static const char NOTIFY_TIMESTAMP[]            = "timestamp";
static const char NOTIFY_NUMBER[]               = "number";
static const char NOTIFY_ICON[]                 = "icon";
static const char NOTIFY_MISSED_CALL_COUNT[]    = "missed_call_count";

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static const char NOTIFY_NOTI_ID[]              = "noti_id";
static const char NOTIFY_NOTI_ACTION[]          = "action_num";
static const char NOTIFY_ACTION_ID[]            = "action_id";
static const char NOTIFY_ACTION_NAME[]          = "action_name";
static const char NOTIFY_ACTION_ICON[]          = "action_icon";
static const char NOTIFY_PAGE_NUM[]             = "page_num";
static const char NOTIFY_PAGE[]                 = "page";
static const char NOTIFY_PAGE_INDX[]            = "index";
static const char NOTIFY_GROUP_ID[]             = "group_id";
#endif


static const char NOTIFY_CATEGORY_NOTI[]        = "notification";
static const char NOTIFY_SUBTYPE_NOTI[]         = "text";
static const char NOTIFY_SUBTYPE_SMS[]          = "sms";
static const char NOTIFY_SUBTYPE_BLOCK_SENDER[] = "block_sender";
static const char NOTIFY_SUBTYPE_ACTION_OPERATE[] = "action_operate";
static const char NOTIFY_SUBTYPE_NOTI_DELETE[]  = "notification_delete";

static const char NOTIFY_CATEGORY_CALL[]        = "call";
static const char NOTIFY_SUBTYPE_MISSED_CALL[]  = "missed_call";

static const char NOTIFY_ACTION_ADD[]           = "add";
static const char NOTIFY_ACTION_DEL[]           = "delete";
static const char NOTIFY_ACTION_Del_ALL[]       = "deleteAll";
static const char NOTIFY_ACTION_UPDATE[]        = "update";

static bt_notify_node_struct bt_notify_node[] = 
{
    {(kal_char*)&NOTIFY_CATEGORY,  BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_category},
    {(kal_char*)&NOTIFY_SUBTYPE,   BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_subtype},
    {(kal_char*)&NOTIFY_MSGID,     BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_msgid},
    {(kal_char*)&NOTIFY_ACTION,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_action},
    {(kal_char*)&NOTIFY_SENDER,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_sender},
    {(kal_char*)&NOTIFY_APPID,     BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_appid},
#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
    {(kal_char*)&NOTIFY_TITLE,     BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_title},
    {(kal_char*)&NOTIFY_TICKER,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_ticker_text},
    {(kal_char*)&NOTIFY_CONTENT,   BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_content},
#else
    {(kal_char*)&NOTIFY_PAGE_NUM,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_page_number},
    {(kal_char*)&NOTIFY_PAGE,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_ATTR,   srv_bt_notify_node_page_indx},
    {(kal_char*)&NOTIFY_GROUP_ID,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_group_id},
    {(kal_char*)&NOTIFY_NOTI_ACTION,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_action_number},
    {(kal_char*)&NOTIFY_ACTION_ID,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_action_id},
    {(kal_char*)&NOTIFY_ACTION_NAME,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_action_name},
    {(kal_char*)&NOTIFY_TITLE,     BT_NOTIFY_NODE_LEVEL_4,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_title},
    {(kal_char*)&NOTIFY_CONTENT,   BT_NOTIFY_NODE_LEVEL_4,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_content},
#endif
    {(kal_char*)&NOTIFY_TIMESTAMP, BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_timestamp},
    {(kal_char*)&NOTIFY_NUMBER,    BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_number},
    {(kal_char*)&NOTIFY_ICON,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_icon},
    {(kal_char*)&NOTIFY_MISSED_CALL_COUNT,      BT_NOTIFY_NODE_LEVEL_3,   BT_NOTIFY_TYPE_DATA,   srv_bt_notify_node_missed_call_count},
};

static const WCHAR ICON_NAME[] = L"receive.bmp";

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_category
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_category(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_header)
    {
        srv_bt_notify_header_struct *header = (srv_bt_notify_header_struct*)g_bt_notify_parser.data;
        
        if (strcmp(data, (CHAR*)&NOTIFY_CATEGORY_NOTI) == 0)
        {
            header->category = srv_bt_notify_category_noti;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_CATEGORY_CALL) == 0)
        {
            header->category = srv_bt_notify_category_call;
        }
        else
        {
            header->category = srv_bt_notify_category_none;
        }
    }    
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_subtype
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_subtype(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_header)
    {
        srv_bt_notify_header_struct *header = (srv_bt_notify_header_struct*)g_bt_notify_parser.data;
        
        if (strcmp(data, (CHAR*)&NOTIFY_SUBTYPE_NOTI) == 0)
        {
            header->subtype = srv_bt_notify_subtype_text;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_SUBTYPE_SMS) == 0)
        {
            header->subtype = srv_bt_notify_subtype_sms;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_SUBTYPE_MISSED_CALL) == 0)
        {
            header->subtype = srv_bt_notify_subtype_missed_call;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_SUBTYPE_NOTI_DELETE) == 0)
        {
            header->subtype = srv_bt_notify_subtype_noti_delete;
        }
    }    
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_msgid
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_msgid(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_header)
    {
        srv_bt_notify_header_struct *header = (srv_bt_notify_header_struct*)g_bt_notify_parser.data;
        header->msg_id = atoi(data);
    }    
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_action
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem [IN]      element.
 *  attr   [IN]      element attribute.
 *  data  [IN]      data.
 *  len    [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_action(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_header)
    {
        srv_bt_notify_header_struct *header = (srv_bt_notify_header_struct*)g_bt_notify_parser.data;
        
        if (strcmp(data, (CHAR*)&NOTIFY_ACTION_ADD) == 0)
        {
            header->action = srv_bt_notify_action_add;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_ACTION_DEL) == 0)
        {
            header->action = srv_bt_notify_action_delete;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_ACTION_Del_ALL) == 0)
        {
            header->action = srv_bt_notify_action_delete_all;
        }
        else if (strcmp(data, (CHAR*)&NOTIFY_ACTION_UPDATE) == 0)
        {
            header->action = srv_bt_notify_action_update;
        }
    }    
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_sender
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_sender(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    U32 sender_len = BT_NOTIFY_SENDER_LENTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        memset(noti_body->sender, 0, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_SENDER_LENTH)
        {
            sender_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)noti_body->sender, sender_len * ENCODING_LENGTH, (U8*)data);
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_sms_body)
    {
        srv_bt_notify_sms_struct *sms_body = (srv_bt_notify_sms_struct*)g_bt_notify_parser.data;
        memset(sms_body->sender, 0, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_SENDER_LENTH)
        {
            sender_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)sms_body->sender, sender_len * ENCODING_LENGTH, (U8*)data);
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_call_body)
    {
        srv_bt_notify_call_struct *call_body = (srv_bt_notify_call_struct*)g_bt_notify_parser.data;
        memset(call_body->sender, 0, BT_NOTIFY_SENDER_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_SENDER_LENTH)
        {
            sender_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)call_body->sender, sender_len * ENCODING_LENGTH, (U8*)data);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_appid
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_appid(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{  
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        noti_body->app_id = (U32)atoi((const char*)data);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_title
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_title(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    U32 title_len = BT_NOTIFY_TITLE_LENTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        U32 i = 0;
        srv_bt_noti_page_content_struct *page_content;
        
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
        memset(noti_body->title, 0, BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
#endif       
        if (len < BT_NOTIFY_TITLE_LENTH)
        {
            title_len = len + 1;
        }
       
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        page_content = noti_body->page_content;
        if (g_bt_notify_parser.curr_page_indx >= BT_NOTIFY_PAGE_MAX_NUM)
        {
            return KAL_TRUE;
        }
        for (i = 0; i < g_bt_notify_parser.curr_page_indx; i++)
        {
            if (i < noti_body->page_num)
            {
                page_content = page_content->next;
            }
            else
            {
                return KAL_TRUE;
            }
        }
        memset(page_content->title, 0, BT_NOTIFY_TITLE_LENTH * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)page_content->title, title_len * ENCODING_LENGTH, (U8*)data);
#else
        mmi_chset_utf8_to_ucs2_string((U8*)noti_body->title, title_len * ENCODING_LENGTH, (U8*)data);
#endif
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_ticker_text
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
static kal_int32 srv_bt_notify_node_ticker_text(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    U32 text_len = BT_NOTIFY_TICKER_TEXT_LENTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        memset(noti_body->ticker_text, 0, BT_NOTIFY_TICKER_TEXT_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_TICKER_TEXT_LENTH)
        {
            text_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)noti_body->ticker_text, text_len * ENCODING_LENGTH, (U8*)data);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_content
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_content(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    U32 content_len = BT_NOTIFY_CONTENT_LENTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_noti_page_content_struct *page_content;
        U32 i;
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;

#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
        if (noti_body->content == NULL)
        {
            return MMI_FALSE;
        }
        
        memset(noti_body->content, 0, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
#endif 
        if (len < BT_NOTIFY_CONTENT_LENTH)
        {
            content_len = len + 1;
        }

#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (g_bt_notify_parser.curr_page_indx >= BT_NOTIFY_PAGE_MAX_NUM)
        {
            return KAL_TRUE;
        }
        page_content = noti_body->page_content;
        for (i = 0; i < g_bt_notify_parser.curr_page_indx; i++)
        {
            if (i < noti_body->page_num)
            {
                page_content = page_content->next;
            }
            else
            {
                return KAL_TRUE;
            }
        }
        memset(page_content->content, 0, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
        mmi_chset_utf8_to_ucs2_string((U8*)page_content->content, content_len * ENCODING_LENGTH, (U8*)data);
#else
        mmi_chset_utf8_to_ucs2_string((U8*)noti_body->content, content_len * ENCODING_LENGTH, (U8*)data);
#endif
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_sms_body)
    {
        srv_bt_notify_sms_struct *sms_body = (srv_bt_notify_sms_struct*)g_bt_notify_parser.data;
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        sms_body->page_content= (srv_bt_noti_page_content_struct *)srv_bt_noti_data_mem_alloc(sizeof(srv_bt_noti_page_content_struct));
        memset(sms_body->page_content->content, 0, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
        sms_body->page_content->next = NULL;
        if (len < BT_NOTIFY_CONTENT_LENTH)
        {
            content_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)sms_body->page_content->content, content_len * ENCODING_LENGTH, (U8*)data);
    #else      
        if (sms_body->content == NULL)
        {
            return MMI_FALSE;
        }
        
        memset(sms_body->content, 0, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_CONTENT_LENTH)
        {
            content_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)sms_body->content, content_len * ENCODING_LENGTH, (U8*)data);
    #endif
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_call_body)
    {
        srv_bt_notify_call_struct *call_body = (srv_bt_notify_call_struct*)g_bt_notify_parser.data;

        if (call_body->content == NULL)
        {
            return MMI_FALSE;
        }
        
        /*memset(call_body->content, 0, BT_NOTIFY_CONTENT_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_CONTENT_LENTH)
        {
            content_len = len + 1;
        }
        
        mmi_chset_utf8_to_ucs2_string((U8*)call_body->content, content_len * ENCODING_LENGTH, (U8*)data);*/
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_timestamp
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_timestamp(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        noti_body->timestamp = atoi(data);
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_sms_body)
    {
        srv_bt_notify_sms_struct *sms_body = (srv_bt_notify_sms_struct*)g_bt_notify_parser.data;
        sms_body->timestamp = atoi(data);
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_call_body)
    {
        srv_bt_notify_call_struct *call_body = (srv_bt_notify_call_struct*)g_bt_notify_parser.data;
        call_body->timestamp = atoi(data);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_number
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_sms_body)
    {
        srv_bt_notify_sms_struct *sms_body = (srv_bt_notify_sms_struct*)g_bt_notify_parser.data;
        memset(sms_body->send_number, 0, BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_NUMBER_LENTH)
        {
            mmi_asc_to_ucs2((CHAR*)sms_body->send_number, (CHAR*)data);
        }
        else
        {
            mmi_asc_n_to_ucs2((CHAR*)sms_body->send_number, (CHAR*)data, BT_NOTIFY_NUMBER_LENTH - 1);
        }  
    }
    else if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_call_body)
    {
        srv_bt_notify_call_struct *call_body = (srv_bt_notify_call_struct*)g_bt_notify_parser.data;
        memset(call_body->send_number, 0, BT_NOTIFY_NUMBER_LENTH * ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_NUMBER_LENTH)
        {
            mmi_asc_to_ucs2((CHAR*)call_body->send_number, (CHAR*)data);
        }
        else
        {
            mmi_asc_n_to_ucs2((CHAR*)call_body->send_number, (CHAR*)data, BT_NOTIFY_NUMBER_LENTH - 1);
        }  
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_icon
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_icon(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        WCHAR file_name[40] = {0};
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        FS_HANDLE fwrite = -1, fread = -1;
        applib_base64_part_context cntx = {0};
        S32 fs_error = FS_NO_ERROR;
        
        mmi_wcscpy(file_name, BT_NOTIFY_ROOT_FOLDER);
        mmi_wcscat(file_name, ICON_NAME);
        fwrite = FS_CheckFile(file_name);
        
        if (fwrite >= FS_NO_ERROR)
        {
            FS_Delete(file_name);
        } 
        
        FS_Close(fwrite);
        fwrite = FS_Open(file_name, FS_CREATE | FS_READ_WRITE);
        
        if (len == 0)
        {
            FS_HANDLE fread = -1;
            kal_uint32 read;
            kal_int32 out_size, lenth;
            kal_char *in_buff, *out_buff;
            out_size = applib_base64_part_decode_init(&cntx, NOTIFY_READ_BUFFER_LEN);
            in_buff = (kal_char*)OslMalloc(NOTIFY_READ_BUFFER_LEN);
            out_buff = (kal_char*)OslMalloc(NOTIFY_READ_BUFFER_LEN);
            fread = FS_Open((WCHAR*)data, FS_READ_ONLY);
            
            while (FS_Read(fread, in_buff, NOTIFY_READ_BUFFER_LEN, &read) == FS_NO_ERROR)
            {
                lenth = applib_base64_part_decode_append(&cntx, in_buff, (kal_int32*)&read, out_buff, out_size);
                if (lenth > 0)
                {
                    fs_error = FS_Write(fwrite, out_buff, (kal_uint32)lenth, NULL);
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_PARSE_ICON, fs_error);
                }
                if (read < NOTIFY_READ_BUFFER_LEN)
                {
                    break;
                }
            }
            
            OslMfree(in_buff);
            OslMfree(out_buff);
            applib_base64_part_decode_finish(&cntx, NULL);
            FS_Close(fread);
        }
        else
        {
            kal_uint32 read = 0;
            kal_uint32 offset = 0;
            kal_uint32 remain_len = len;
            kal_int32 out_size, lenth;
            kal_char *in_buff, *out_buff;
            in_buff = (kal_char*)OslMalloc(NOTIFY_READ_BUFFER_LEN);
            out_buff = (kal_char*)OslMalloc(NOTIFY_READ_BUFFER_LEN);
            out_size = applib_base64_part_decode_init(&cntx, NOTIFY_READ_BUFFER_LEN);
            
            while (remain_len > 0)
            {
                memset(in_buff, 0, NOTIFY_READ_BUFFER_LEN);
                memset(out_buff, 0, NOTIFY_READ_BUFFER_LEN);
                read = remain_len > NOTIFY_READ_BUFFER_LEN ? NOTIFY_READ_BUFFER_LEN : remain_len;
                memcpy(in_buff, data+offset, read);
                offset += read;
                remain_len -= read;
                lenth = applib_base64_part_decode_append(&cntx, in_buff, (kal_int32*)&read, out_buff, out_size);
                if (lenth > 0)
                {
                    fs_error = FS_Write(fwrite, out_buff, (kal_uint32)lenth, NULL);
                    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_PARSE_ICON, fs_error);
                }
            }
            
            OslMfree(in_buff);
            OslMfree(out_buff);
            applib_base64_part_decode_finish(&cntx, NULL);
        }
        
        FS_Close(fwrite);
    #ifdef __BT_NOTI_SRV_ICON_WITH_BUFFER__
        fread = FS_Open(file_name, FS_CREATE | FS_READ_WRITE);
        if (fread > 0)
        {
            U32 read_length = 0;
            FS_Read(fread, (noti_body->icon)->icon_buffer, BT_NOTIFY_MAX_ICON_LENGTH, &((noti_body->icon)->icon_size));
            FS_Close(fread);
        }
    #else
        mmi_wcscpy((noti_body->icon)->icon_path, (WCHAR*)&file_name);
    #endif
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_node_missed_call_count
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  elem    [IN]      element.
 *  attr    [IN]      element attribute.
 *  data    [IN]      data.
 *  len     [IN]      data len.
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_node_missed_call_count(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_call_body)
    {
        srv_bt_notify_call_struct *call_body = (srv_bt_notify_call_struct*)g_bt_notify_parser.data;
        call_body->missed_call_count = atoi(data);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}


#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
static kal_int32 srv_bt_notify_node_page_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        U32 i;
        srv_bt_noti_page_content_struct *page_content;
        srv_bt_noti_page_content_struct *p_page_content;
        
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        noti_body->page_num = atoi(data);
        if(noti_body->page_num > BT_NOTIFY_PAGE_MAX_NUM)
        {
            noti_body->page_num = BT_NOTIFY_PAGE_MAX_NUM;
        }
        
        if (noti_body->page_num == 0)
        {   
            return KAL_TRUE;
        }
        
        for(i = 0; i < noti_body->page_num; i++)
        {
            if (i == 0)
            {
                p_page_content = (srv_bt_noti_page_content_struct *)srv_bt_noti_data_mem_alloc(sizeof(srv_bt_noti_page_content_struct));
                ASSERT(p_page_content);
                p_page_content->next = NULL;
                noti_body->page_content = p_page_content;
            }
            else
            {
                page_content = (srv_bt_noti_page_content_struct *)srv_bt_noti_data_mem_alloc(sizeof(srv_bt_noti_page_content_struct));
                ASSERT(p_page_content);
                page_content->next = NULL;
                for(;p_page_content->next != NULL;)
                {
                    p_page_content = p_page_content->next;
                }

                p_page_content->next = page_content;
            }
        }

        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7,  "[BTNOTIFYSRVParser] parse page num: %d", noti_body->page_num); 
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}


static kal_int32 srv_bt_notify_node_page_indx(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        if (strcmp(attr[0],NOTIFY_PAGE_INDX) == 0)
        {
            if(attr[1] != NULL)
            {
                g_bt_notify_parser.curr_page_indx = atoi(attr[1]);
            }
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    return KAL_TRUE;
}


static kal_int32 srv_bt_notify_node_group_id(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        U32 group_len = BT_NOTIFY_GROUP_MAX_LENGTH;
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        
        memset(noti_body->group_id, 0, BT_NOTIFY_GROUP_MAX_LENGTH);
        
        if (data == NULL)
        {
            return KAL_TRUE;
        }
        
        if (len < BT_NOTIFY_GROUP_MAX_LENGTH)
        {
            group_len = len + 1;
        }
        
        strncpy((U8*)noti_body->group_id, (U8*)data, group_len);

        MMI_PRINT(MOD_MMI_CONN_APP, 
                    TRACE_GROUP_7,  
                    "[BTNOTIFYSRV]parse group id: %s", 
                    noti_body->group_id); 
        
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    return KAL_TRUE;
}




static kal_int32 srv_bt_notify_node_action_number(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        noti_body->action_number = atoi(data);

        if (noti_body->action_number > BT_NOTIFY_ACTION_MAX_NUM)
        {
            noti_body->action_number = BT_NOTIFY_ACTION_MAX_NUM;
        }
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}


static kal_int32 srv_bt_notify_node_action_id(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{   

    U32 id_len = BT_NOTIFY_ACTION_ID_LENTH;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;
        
        if (g_bt_notify_parser.curr_action_id_index >= BT_NOTIFY_ACTION_MAX_NUM)
        {
            return KAL_TRUE;
        }
        memset(noti_body->noti_action[g_bt_notify_parser.curr_action_id_index].action_id, 0, BT_NOTIFY_ACTION_ID_LENTH* ENCODING_LENGTH);
        
        if (len < BT_NOTIFY_ACTION_ID_LENTH)
        {
            id_len = len + 1;
        }
        else
        {
            return KAL_TRUE;
        }       
        mmi_chset_utf8_to_ucs2_string((U8*)noti_body->noti_action[g_bt_notify_parser.curr_action_id_index].action_id, id_len * ENCODING_LENGTH, (U8*)data);
         g_bt_notify_parser.curr_action_id_index++;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }
    
    return KAL_TRUE;
}


static kal_int32 srv_bt_notify_node_action_name(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{   

    U32 name_len = BT_NOTIFY_ACTION_NAME_LENTH;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    if (g_bt_notify_parser.para_flag == srv_bt_notify_parse_noti_body)
    {
        srv_bt_notify_noti_struct *noti_body = (srv_bt_notify_noti_struct*)g_bt_notify_parser.data;

        if (g_bt_notify_parser.curr_action_name_index >= BT_NOTIFY_ACTION_MAX_NUM)
        {
            return KAL_TRUE;
        }
        
        memset(noti_body->noti_action[g_bt_notify_parser.curr_action_name_index].action_name, 0, BT_NOTIFY_ACTION_NAME_LENTH* ENCODING_LENGTH);

        if (len < BT_NOTIFY_ACTION_NAME_LENTH)
        {
            name_len = len + 1;
            mmi_chset_utf8_to_ucs2_string(
                (U8*)noti_body->noti_action[g_bt_notify_parser.curr_action_name_index].action_name, 
                name_len * ENCODING_LENGTH, 
                (U8*)data);
        }
        else
        {
            name_len = BT_NOTIFY_ACTION_NAME_LENTH;
            mmi_chset_utf8_to_ucs2_string(
                (U8*)noti_body->noti_action[g_bt_notify_parser.curr_action_name_index].action_name, 
                name_len * ENCODING_LENGTH, 
                (U8*)data);
            mmi_wcscat(noti_body->noti_action[g_bt_notify_parser.curr_action_name_index].action_name,
                L"...");
        }
        
        
        g_bt_notify_parser.curr_action_name_index++;
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_NOT_PARSER);
    }

    
    
    return KAL_TRUE;
}

#endif /*__MMI_BT_NOTIFICATION_ENHANCE__*/
/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_elem_start_hdlr
 * DESCRIPTION
 *  Process element start.
 * PARAMETERS
 *  data  [IN]      data.
 *  el    [IN]      element.
 *  attr  [IN]      element attribute.
 *  error [IN]      error code.
 * RETURNS
 *  void.
 *****************************************************************************/
static void srv_bt_notify_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i=0, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_num = sizeof(bt_notify_node) / sizeof(bt_notify_node[0]);

    g_bt_notify_parser.stack++;

    for (i = 0; i < tab_num; i++)
    {
        if (bt_notify_node[i].type != BT_NOTIFY_TYPE_ATTR ||
            strcmp(el, bt_notify_node[i].name) != 0 ||
            bt_notify_node[i].deep != g_bt_notify_parser.stack)
        {
            continue;
        }

        bt_notify_node[i].call_back(el, attr, NULL, 0);
        break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_elem_end_hdlr
 * DESCRIPTION
 *  Process element end.
 * PARAMETERS
 *  data  [IN]      data.
 *  el    [IN]      element. 
 *  error [IN]      error code.
 * RETURNS
 *  void.
 *****************************************************************************/
static void srv_bt_notify_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret_val = error == XML_NO_ERROR ? MMI_TRUE : MMI_FALSE;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_ELEM_END, error);
    
    if (g_bt_notify_parser.stack > 0)
    {
        g_bt_notify_parser.stack--;
    }
    
    if (MMI_FALSE == ret_val || strcmp(el, (CHAR*)&NOTIFY_REPORT) == 0)
    {    
        g_bt_notify_parser.is_run = MMI_FALSE;
        
        if (g_bt_notify_parser.callback != NULL)
        {
            g_bt_notify_parser.callback(g_bt_notify_parser.para_flag, g_bt_notify_parser.data, g_bt_notify_parser.user_data, ret_val);
        }
        
        g_bt_notify_parser.callback = NULL;
        g_bt_notify_parser.para_flag = srv_bt_notify_parse_none;
        g_bt_notify_parser.data = NULL;
        g_bt_notify_parser.user_data = NULL;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_data_hdlr
 * DESCRIPTION
 *  Process element data.
 * PARAMETERS
 *  resv  [IN]      xml data.
 *  el    [IN]      element name. 
 *  data  [IN]      element data.
 *  len   [IN]      length of data.
 *  error [IN]      error code.    
 * RETURNS
 *  void.
 *****************************************************************************/
static void srv_bt_notify_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 i, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_DATA_END, error);  
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7,  "[BTNOTIFYSRV] %s %s %d", el, data, g_bt_notify_parser.stack); 
    
    tab_num = sizeof(bt_notify_node) / sizeof(bt_notify_node[0]);

    if (error)
    {
        xml_stop_parse((XML_PARSER_STRUCT*)resv);
        return;
    }

    for (i = 0; i < tab_num; i++)
    {
        if (strcmp(el, bt_notify_node[i].name) != 0 ||
            bt_notify_node[i].deep != g_bt_notify_parser.stack)
        {
            continue;
        }        
        bt_notify_node[i].call_back(el, NULL, data, len);
        break;
    } 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_xml_parse
 * DESCRIPTION
 *  parser configuration file to pre-install account.
 * PARAMETERS
 *  void *  [IN]    msg.
 * RETURNS
 *  void
 *****************************************************************************/
kal_int32 srv_bt_notify_xml_parse(WCHAR *file_name, srv_bt_notify_parse_para para_flag, srv_bt_parse_xml_callback callback, void *data, void *user_data)
{
    kal_int32 ret = XML_NO_ERROR;
    XML_PARSER_STRUCT * xml_parser = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/  
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_PARSE_BEFORE_START, g_bt_notify_parser.is_run, para_flag, callback, data);

    if (g_bt_notify_parser.is_run == MMI_TRUE)
    {
        return -1;
    }

    do
    {
        g_bt_notify_parser.is_run = MMI_TRUE;
        g_bt_notify_parser.para_flag = para_flag;
        g_bt_notify_parser.callback = callback;
        g_bt_notify_parser.data = data;
        g_bt_notify_parser.user_data = user_data;
        g_bt_notify_parser.stack= 0;
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        g_bt_notify_parser.curr_action_id_index = 0;
        g_bt_notify_parser.curr_action_name_index = 0;
#endif
        xml_parser = (XML_PARSER_STRUCT*)OslMalloc(sizeof(XML_PARSER_STRUCT));
        ret = xml_new_parser(xml_parser);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_PARSE_START, ret);

        if (ret != XML_NO_ERROR)
        {
            break;
        }
    
        xml_register_element_handler(xml_parser, srv_bt_notify_elem_start_hdlr, srv_bt_notify_elem_end_hdlr);
        xml_register_data_handler(xml_parser, srv_bt_notify_data_hdlr); 
        ret = xml_parse(xml_parser, file_name);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_PARSE_DONE, ret);
    } while(0);

    xml_close_parser(xml_parser);
    OslMfree(xml_parser);

    /* error happened, clear state */
    if (ret != XML_NO_ERROR)
    {
        g_bt_notify_parser.is_run = MMI_FALSE;
        g_bt_notify_parser.para_flag = srv_bt_notify_parse_none;
        g_bt_notify_parser.callback = NULL;
        g_bt_notify_parser.data = NULL;
        g_bt_notify_parser.user_data = NULL;
        return -1;
    }
    
    return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_xml_gen_header
 * DESCRIPTION
 *  gen xml header.
 * PARAMETERS
 *  xml_gen_handle      [IN].
 *  data                [IN]   .
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_xml_gen_header(XG_HANDLE xml_gen_handle, srv_bt_notify_data_struct *data)
{
    kal_int32 ret = -1;
    srv_bt_notify_header_struct *header = &(data->header);
    kal_char *xml_data = NULL;
    
    ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_HEADER, NULL, 0);
    
    /* check data */
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_GEN_HEADER, header->category, header->subtype, header->msg_id, header->action);

    if (header->category == srv_bt_notify_category_noti)
    {
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_CATEGORY, (kal_char*)&NOTIFY_CATEGORY_NOTI, strlen((kal_char*)&NOTIFY_CATEGORY_NOTI));
    }
    else if (header->category == srv_bt_notify_category_call)
    {
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_CATEGORY, (kal_char*)&NOTIFY_CATEGORY_CALL, strlen((kal_char*)&NOTIFY_CATEGORY_CALL));
    }
  
    switch(header->subtype)
    {
        case srv_bt_notify_subtype_text:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_NOTI;
            break;
        }
        case srv_bt_notify_subtype_sms:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_SMS;
            break;
        }
        case srv_bt_notify_subtype_missed_call:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_MISSED_CALL;
            break;
        }
        case srv_bt_notify_subtype_block_sender:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_BLOCK_SENDER;
            break;
        }
        case srv_bt_notify_subtype_action_operate:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_ACTION_OPERATE;
            break;
        }
        case srv_bt_notify_subtype_noti_delete:
        {
            xml_data = (kal_char*)&NOTIFY_SUBTYPE_NOTI_DELETE;
            break;
        }
    }
    
    if (header->subtype == srv_bt_notify_subtype_text ||
        header->subtype == srv_bt_notify_subtype_sms ||
        header->subtype == srv_bt_notify_subtype_missed_call ||
        header->subtype == srv_bt_notify_subtype_block_sender ||
        header->subtype == srv_bt_notify_subtype_action_operate ||
        header->subtype == srv_bt_notify_subtype_noti_delete)
    {
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_SUBTYPE, xml_data, strlen(xml_data));
    }
    
    if (header->msg_id != 0)
    {
        CHAR str_msg_id[20] = {0};
        kal_sprintf(str_msg_id, "%d", header->msg_id);
        //srv_bt_notify_itoa((CHAR*)&str_msg_id, header->msg_id, 10);
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_MSGID, (CHAR*)&str_msg_id, strlen((CHAR*)&str_msg_id));
    }
    
    switch(header->action)
    {
        case srv_bt_notify_action_add:
        {
            xml_data = (kal_char*)&NOTIFY_ACTION_ADD;
            break;
        }
        case srv_bt_notify_action_delete:
        {
            xml_data = (kal_char*)&NOTIFY_ACTION_DEL;
            break;
        }
        case srv_bt_notify_action_delete_all:
        {
            xml_data = (kal_char*)&NOTIFY_ACTION_Del_ALL;
            break;
        }
        case srv_bt_notify_action_update:
        {
            xml_data = (kal_char*)&NOTIFY_ACTION_UPDATE;
            break;
        }
        default:
        {
            xml_data = NULL;
            break;
        }
    }
    
    if (xml_data != NULL)
    {
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_ACTION, xml_data, strlen(xml_data));
    }
    
    ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_HEADER);   
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_xml_gen_app_id
 * DESCRIPTION
 *  gen xml body.
 * PARAMETERS
 *  xml_gen_handle  [IN].
 *  app_id          [IN]   .
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_xml_gen_app_id(XG_HANDLE xml_gen_handle, U32 app_id)
{
    CHAR app_id_buffer[20] = {0};
    kal_int32 ret;
    
    kal_sprintf(app_id_buffer, "%d", app_id);
    ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_APPID, (kal_char*)app_id_buffer, strlen((kal_char*)app_id_buffer));
    
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_xml_gen_body
 * DESCRIPTION
 *  gen xml body.
 * PARAMETERS
 *  xml_gen_handle  [IN].
 *  data            [IN]   .
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
static kal_int32 srv_bt_notify_xml_gen_body(XG_HANDLE xml_gen_handle, srv_bt_notify_data_struct *data)
{
    kal_int32 ret = -1;
    srv_bt_notify_header_struct *header = &(data->header);

    ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_BODY, NULL, 0);
    
    if (header->subtype == srv_bt_notify_subtype_sms)
    {
        U32 len = 0;
        srv_bt_notify_sms_struct *body = (srv_bt_notify_sms_struct*)&(data->mbody);
        
        /* check data */
        len = mmi_wcslen((WCHAR*)&(body->sender));
        
        if (len != 0)
        {
            U8 *sender = NULL;

            sender = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(sender, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)&(body->sender));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_SENDER, (kal_char*)sender, strlen((kal_char*)sender));
            OslMfree(sender);
        }
            
        if (mmi_wcslen((WCHAR*)&(body->send_number)) != 0)
        {
            CHAR send_numbesr[BT_NOTIFY_NUMBER_LENTH] = {0};

            mmi_wcs_to_asc((CHAR*)&send_numbesr, (WCHAR*)&(body->send_number));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_NUMBER, (CHAR*)&send_numbesr, strlen((CHAR*)&send_numbesr));
        }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (body->page_content != NULL && (len = mmi_wcslen(body->page_content->content)) != 0)
        {
            U8 *content = NULL;

            content = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(content, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)body->page_content->content);
            ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT, NULL, 0);
            ret = xml_generate_cdata(xml_gen_handle, (kal_char*)content, strlen((kal_char*)content));
            ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT);
            OslMfree(content);
        }
#else
        if (body->content != NULL && (len = mmi_wcslen(body->content)) != 0)
        {
            U8 *content = NULL;

            content = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(content, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)body->content);
            ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT, NULL, 0);
            ret = xml_generate_cdata(xml_gen_handle, (kal_char*)content, strlen((kal_char*)content));
            ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT);
            OslMfree(content);
        }
#endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/
        if (body->timestamp != 0)
        {
            CHAR str_timestamp[20] = {0};
            srv_bt_notify_itoa((CHAR*)&str_timestamp, body->timestamp, 10);
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_TIMESTAMP, (kal_char*)&str_timestamp, strlen((CHAR*)&str_timestamp));
        }
    }
#ifndef __MMI_BT_NOTIFICATION_ENHANCE__
    else if (header->subtype == srv_bt_notify_subtype_text)
    {
        U32 len = 0;
        srv_bt_notify_noti_struct *body = (srv_bt_notify_noti_struct*)&(data->mbody);
        
        /* check data */
        len = mmi_wcslen((WCHAR*)&(body->sender));
        
        if (len != 0)
        {
            U8 *sender = NULL;

            sender = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(sender, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)&(body->sender));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_SENDER, (kal_char*)sender, strlen((kal_char*)sender));
            OslMfree(sender);
        }
        
        if (body->content != NULL && (len = mmi_wcslen(body->content)) != 0)
        {
            U8 *content = NULL;
            
            content = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(content, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)body->content);
            ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT, NULL, 0);
            ret = xml_generate_cdata(xml_gen_handle, (kal_char*)content, strlen((kal_char*)content));
            ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT);
            OslMfree(content);
        }
        
        if (body->timestamp != 0)
        {
            CHAR str_timestamp[20] = {0};
            srv_bt_notify_itoa((CHAR*)&str_timestamp, body->timestamp, 10);
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_TIMESTAMP, (kal_char*)&str_timestamp, strlen((CHAR*)&str_timestamp));
        }
    }
#endif
    else if (header->subtype == srv_bt_notify_subtype_missed_call)
    {
        U32 len = 0;
        srv_bt_notify_call_struct *body = (srv_bt_notify_call_struct*)&(data->mbody);
        
        /* check data */
        len = mmi_wcslen((WCHAR*)&(body->sender));
        
        if (len != 0)
        {
            U8 *sender = NULL;

            sender = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(sender, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)&(body->sender));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_SENDER, (kal_char*)sender, strlen((kal_char*)sender));
            OslMfree(sender);
        }
        
        if (mmi_wcslen((WCHAR*)&(body->send_number)) != 0)
        {
            CHAR send_numbesr[BT_NOTIFY_NUMBER_LENTH] = {0};

            mmi_wcs_to_asc((CHAR*)&send_numbesr, (WCHAR*)&(body->send_number));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_NUMBER, (CHAR*)&send_numbesr, strlen((CHAR*)&send_numbesr));
        }
        
        if (body->content != NULL && (len = mmi_wcslen(body->content)) != 0)
        {
            U8 *content = NULL;

            content = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(content, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)body->content);
            ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT, NULL, 0);
            ret = xml_generate_cdata(xml_gen_handle, (kal_char*)content, strlen((kal_char*)content));
            ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_CONTENT);
            OslMfree(content);
        }
        
        //if (body->missed_call_count >= 0)
        {
            CHAR str_missed_call_count[20] = {0};
            srv_bt_notify_itoa((CHAR*)&str_missed_call_count, body->missed_call_count, 10);
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_MISSED_CALL_COUNT, (kal_char*)&str_missed_call_count, strlen((CHAR*)&str_missed_call_count));
        }
        
        if (body->timestamp != 0)
        {
            CHAR str_timestamp[20] = {0};
            srv_bt_notify_itoa((CHAR*)&str_timestamp, body->timestamp, 10);
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_TIMESTAMP, (kal_char*)&str_timestamp, strlen((CHAR*)&str_timestamp));
        }
    }
    else if (header->subtype == srv_bt_notify_subtype_block_sender)
    {
        U32 len = 0;
        srv_bt_notify_block_sender_struct *body = (srv_bt_notify_block_sender_struct*)&(data->mbody);
        
        /* check data */
        len = mmi_wcslen((WCHAR*)&(body->sender));
        
        if (len != 0)
        {
            U8 *sender = NULL;

            sender = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(sender, len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, (kal_uint8*)&(body->sender));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_SENDER, (kal_char*)sender, strlen((kal_char*)sender));
            OslMfree(sender);
        }
        
        ret = srv_bt_notify_xml_gen_app_id(xml_gen_handle, body->app_id);
        
        if (mmi_wcslen((WCHAR*)&(body->send_number)) != 0)
        {
            CHAR send_numbesr[BT_NOTIFY_NUMBER_LENTH] = {0};

            mmi_wcs_to_asc((CHAR*)&send_numbesr, (WCHAR*)&(body->send_number));
            ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_NUMBER, (CHAR*)&send_numbesr, strlen((CHAR*)&send_numbesr));
        }
    }
#ifdef __MMI_BT_NOTIFICATION_ENHANCE__
    else if (header->subtype == srv_bt_notify_subtype_action_operate) 
    {
        U32 len = 0;
        srv_bt_notify_action_operate_struct *body = (srv_bt_notify_action_operate_struct *)&(data->mbody);
        U8 noti_id_buffer[20] = {0};        
        kal_int32 ret;
    
        kal_sprintf(noti_id_buffer, "%d", body->noti_id);
        ret = xml_generate_inline_element(xml_gen_handle, (kal_char*)&NOTIFY_NOTI_ID, (kal_char*)noti_id_buffer, strlen((kal_char*)noti_id_buffer));

        
        len = mmi_wcslen((WCHAR*)&(body->action_id));

        if (len != 0)
        {
            U8 *action_id = NULL;

            action_id  = (U8*)OslMalloc(len * MAX_BYTES_EACH_CHARACTER_IN_UTF8);
            mmi_chset_ucs2_to_utf8_string(action_id, 
                len * MAX_BYTES_EACH_CHARACTER_IN_UTF8, 
                (kal_uint8*)&(body->action_id));
            ret = xml_generate_inline_element(xml_gen_handle, 
                (kal_char*)&NOTIFY_ACTION_ID, 
                (kal_char*)action_id, 
                strlen((kal_char*)action_id));
            OslMfree(action_id);
        } 
    }
#endif/*__MMI_BT_NOTIFICATION_ENHANCE__*/
    
    ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_BODY);
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_itoa
 * DESCRIPTION
 *  itoa function.
 * PARAMETERS
 *  buf         [IN/OUT].
 *  i           [IN]   .
 *  base        [IN]   .
 * RETURNS
 *  void.
 *****************************************************************************/
void srv_bt_notify_itoa(kal_char *buf, U32 i, kal_int32 base)
{
    kal_char *s;
#define LEN   20
    kal_int32 rem;
    kal_char rev[LEN+1] = {0};

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
        {
            *--s = rem + '0';
        }
        i /= base;
    }
    while (*s)
    {
        buf[0] = *s++;
        ++buf;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_notify_xml_generator
 * DESCRIPTION
 *  gen xml.
 * PARAMETERS
 *  filename        [IN].
 *  data            [IN]   .
 * RETURNS
 *  kal_int32.
 *****************************************************************************/
kal_int32 srv_bt_notify_xml_generator(WCHAR *file_name, srv_bt_notify_data_struct *data)
{
    kal_int32 ret = -1;
    FS_HANDLE FSHandle = -1;
    XG_HANDLE xml_gen_handle = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_BEFORE_GEN);
    FSHandle = FS_CheckFile(file_name);
    
    if (FSHandle >= FS_NO_ERROR)
    {
        FS_Delete(file_name);
    } 
    FS_Close(FSHandle);
    
    FSHandle = FS_Open(file_name, FS_CREATE | FS_READ_WRITE);
    
    if (FSHandle < FS_NO_ERROR)
    {
        return -1;//ASSERT(0); //Create File Fail
    }
    
    xml_gen_handle = xml_new_generator_file(FSHandle);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_GEN, xml_gen_handle);
    
    if (xml_gen_handle >= 0)
    {
        ret = xml_generate_xmldecl(xml_gen_handle, "1.0", XML_ENCODING_UTF8);
        ret = xml_generate_stag(xml_gen_handle, (kal_char*)&NOTIFY_REPORT, NULL, 0);
        ret = srv_bt_notify_xml_gen_header(xml_gen_handle, data);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_GEN_RES, ret);
        ret = srv_bt_notify_xml_gen_body(xml_gen_handle, data);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_BT_NOTIFY_XML_GEN_RES, ret);
        ret = xml_generate_etag(xml_gen_handle, (kal_char*)&NOTIFY_REPORT);
        ret = xml_close_generator(xml_gen_handle);
        FS_Close(FSHandle);
    }
    
    return ret;
}

#endif /*__MMI_BT_NOTI_SRV__*/

