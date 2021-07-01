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
 *  SmsBtMapCParserSrv.c
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
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *****************************************************************************/
#include "MMI_features.h"

#ifdef __XML_SUPPORT__
#include "SmsBtMapCSrvParser.h"
#include "xml_def.h"
#include "Stdlib.h"
#include "SmsBtMapCSrvProt.h"
#include "app_datetime.h"
#include "SmsBtmapcSrvStorage.h"
#include "SmsBtMapCSrvConverter.h"
#include "SmsBtMapCSrvGProt.h"
#include "Unicodexdcl.h"
#include "Conversions.h"
#include "MMI_common_app_trc.h"
#include "MMI_trc_Int.h"
#include "SmsSrvGprot.h"
#include "mmi_rp_srv_sms_btmapc_def.h"

#ifdef __SRV_SMS_BTMAPC__

#define SMS_BTMAPC_MAX_PARSE_ITEM    SRV_SMS_BTMAPC_MAX_SMS_ENTRY

#define NODE_LEVEL_1    1
#define NODE_LEVEL_2    2

#define SMS_BTMAPC_TYPE_DATA 1
#define SMS_BTMAPC_TYPE_ATTR 2

#define SMS_BTMAPC_MSG_LIST_NAME      "MAP-msg-listing"
#define SMS_BTMAPC_NODE_MSG           "msg"
#define SMS_BTMAPC_ATTR_VERNO         "version"
#define SMS_BTMAPC_ATTR_HD            "handle"
#define SMS_BTMAPC_ATTR_SUBJ          "subject"
#define SMS_BTMAPC_ATTR_DATETIME      "datetime"
#define SMS_BTMAPC_ATTR_SENDER_NAME   "sender_name"
#define SMS_BTMAPC_ATTR_SENDER_ADDR   "sender_addressing"
#define SMS_BTMAPC_ATTR_RCPT_ADDR     "recipient_addressing"
#define SMS_BTMAPC_ATTR_RCPT_NAME     "recipient_name"
#define SMS_BTMAPC_ATTR_TYPE          "type"
#define SMS_BTMAPC_ATTR_SIZE          "size"
#define SMS_BTMAPC_ATTR_ATTACH_SIZE   "attachment_size"
#define SMS_BTMAPC_ATTR_PRIORITY      "Priotity"
#define SMS_BTMAPC_ATTR_READ          "read"
#define SMS_BTMAPC_ATTR_SENT          "sent"
#define SMS_BTMAPC_ATTR_PROTECTED     "protected"
#define SMS_BTMAPC_ATTR_MSG_TYPE      "msg_type"
#define SMS_BTMAPC_ATTR_FLDR          "folder"
#define SMS_BTMAPC_ATTR_FLDR_INBOX_C    "TELECOM/MSG/INBOX"
#define SMS_BTMAPC_ATTR_FLDR_INBOX_L    "telecom/msg/inbox"
#define SMS_BTMAPC_ATTR_FLDR_OUTBOX_C   "TELECOM/MSG/OUTBOX"
#define SMS_BTMAPC_ATTR_FLDR_OUTBOX_L   "telecom/msg/outbox"
#define SMS_BTMAPC_ATTR_FLDR_SENT_C     "TELECOM/MSG/SENT"
#define SMS_BTMAPC_ATTR_FLDR_SENT_L     "telecom/msg/sent"
#define SMS_BTMAPC_ATTR_FLDR_DELETED_C  "TELECOM/MSG/DELETED"
#define SMS_BTMAPC_ATTR_FLDR_DELETED_L  "telecom/msg/deleted"
#define SMS_BTMAPC_ATTR_FLDR_DRAFT_C    "TELECOM/MSG/DRAFT"
#define SMS_BTMAPC_ATTR_FLDR_DRAFT_L    "telecom/msg/draft"


#define SMS_BTMAPC_VERS_VALUE         "1.0"
#define SMS_BTMAPC_ATTR_VAL_YES       "yes"
#define SMS_BTMAPC_ATTR_VAL_NO        "no"
#define SMS_BTMAPC_ATTR_SMS_TYPE      "SMS_GSM"


#define SMS_BTMAPC_ATTR_NEW_MSG     "NewMessage"
#define SMS_BTMAPC_ATTR_DELI_SUCC   "DeliverySuccess"
#define SMS_BTMAPC_ATTR_SEND_SUCC   "SendingSuccess"
#define SMS_BTMAPC_ATTR_DELI_FAIL   "DeliveryFailure"
#define SMS_BTMAPC_ATTR_SEND_FAIL   "SendingFailure"
#define SMS_BTMAPC_ATTR_MEM_FULL    "MemoryFull"
#define SMS_BTMAPC_ATTR_MEM_AVAIL   "MemoryAvailable"
#define SMS_BTMAPC_ATTR_MSG_DELE    "MessageDeleted"
#define SMS_BTMAPC_ATTR_MSG_SHIFT   "MessageShift"

extern srv_sms_btmapc_node_event_struct sms_btmapc_evt_report;



/***************************************************************************** 
 * Typedef
 *****************************************************************************/

typedef kal_int32 (*sms_btmapc_call)(const kal_char *, const kal_char **, const kal_char *, kal_int32);

typedef struct 
{
    kal_char *name;
    kal_uint16 deep;
    kal_uint16 type;
    sms_btmapc_call call_back;
} sms_btmapc_node_struct;


typedef struct 
{
    XML_PARSER_STRUCT xml_parser;
    kal_uint8 save;
    kal_uint8 bearer;
    kal_uint8 stack;
    kal_uint8 count;
    void* dtcnt_data;
    void* common_data;
} sms_btmapc_parser_struct;


/***************************************************************************** 
 * Variable
 *****************************************************************************/

static sms_btmapc_parser_struct g_sms_btmapc_parser;
static XML_PARSER_STRUCT *g_sms_btmapc_xml_parser = &g_sms_btmapc_parser.xml_parser;


/***************************************************************************** 
 * Static function
 *****************************************************************************/
static kal_int32 sms_btmapc_node_msg_verno(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 sms_btmapc_node_msg(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static kal_int32 sms_btmapc_node_event(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len);
static void sms_btmapc_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error);
static void sms_btmapc_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error);
static void sms_btmapc_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error);
static void sms_btmapc_resume_parse_hdlr(void *msg);
extern void srv_sms_btmapc_send_evt_rsp(srv_bt_mapc_bt_enum bt_index, srv_sms_btmapc_ind_enum type);


static sms_btmapc_node_struct sms_btmapc_node[] = 
{
    {"MAP-msg-listing", NODE_LEVEL_1,   SMS_BTMAPC_TYPE_ATTR,   sms_btmapc_node_msg_verno},
    {"msg",             NODE_LEVEL_2,   SMS_BTMAPC_TYPE_ATTR,   sms_btmapc_node_msg},
    {"MAP-event-report",NODE_LEVEL_1,   SMS_BTMAPC_TYPE_ATTR,   sms_btmapc_node_msg_verno},
    {"event",           NODE_LEVEL_2,   SMS_BTMAPC_TYPE_ATTR,   sms_btmapc_node_event}
};

static kal_int32 sms_btmapc_node_msg_verno(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;
    const kal_char *verno = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], SMS_BTMAPC_ATTR_VERNO) == 0)
        {
            verno = attr[i+1];
            if (strncmp(verno, SMS_BTMAPC_VERS_VALUE, len) == 0)
            {
                return KAL_TRUE;
            }
        }
    }

    return KAL_FALSE;
}


static kal_int32 sms_btmapc_node_event(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&sms_btmapc_evt_report, 0x00, sizeof(srv_sms_btmapc_node_event_struct));

    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_EVT_PARSE0);
    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], SMS_BTMAPC_ATTR_TYPE) == 0)
        {
            if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_NEW_MSG) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_NEW_MSG;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_DELI_SUCC) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_DELI_SUCC;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_SEND_SUCC) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_SEND_SUCC;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_DELI_FAIL) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_DELI_FAIL;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_SEND_FAIL) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_SEND_FAIL;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_MEM_FULL) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_MEM_FULL;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_MEM_AVAIL) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_MEM_AVAILABLE;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_MSG_DELE) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_MSG_DELETED;
            }
            else if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_MSG_SHIFT) == 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_MSG_SHIFT;
            }
            g_sms_btmapc_parser.count++;
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_HD) == 0)
        {
            if(strlen(attr[i+1]) < SRV_BT_MAP_MAX_HANDLE_STR_LEN)
            {
                memcpy(sms_btmapc_evt_report.msg_handle, attr[i+1], strlen(attr[i+1]));
            }
            else
            {       
                memcpy(sms_btmapc_evt_report.msg_handle, attr[i+1], SRV_BT_MAP_MAX_HANDLE_STR_LEN);
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_FLDR) == 0)
        {
            if ((strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_INBOX_C) == 0) || 
                (strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_INBOX_L) == 0))
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_INBOX;
            }
            else if ((strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_OUTBOX_C) == 0) || 
                     (strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_OUTBOX_L) == 0))
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_UNSENT;
            }
            else if ((strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_SENT_C) == 0) || 
                     (strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_SENT_L) == 0))
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_OUTBOX;
            }
            else if ((strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_DELETED_C) == 0) || 
                     (strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_DELETED_L) == 0))
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_DELETED;
            }
            else if ((strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_DRAFT_C) == 0) || 
                     (strcmp(attr[i+1], SMS_BTMAPC_ATTR_FLDR_DRAFT_L) == 0))
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_DRAFTS;
            }
            else
            {
                sms_btmapc_evt_report.box_type = SRV_SMS_BTMAPC_BOX_INBOX;
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_MSG_TYPE) == 0)
        {
            if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_SMS_TYPE) != 0)
            {
                sms_btmapc_evt_report.evt_report_type = SRV_SMS_BTMAPC_NOT_SUPPORTED;
                return KAL_FALSE;
            }
        }
        i+=2;
    }
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_EVT_PARSE1, sms_btmapc_evt_report.evt_report_type);
    return KAL_TRUE;
}


static kal_int32 sms_btmapc_node_msg(const kal_char *elem, const kal_char **attr, const kal_char *data, kal_int32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    const kal_char *hd = NULL;
    const kal_char *dt = NULL;
    kal_int32 i = 0;
    srv_sms_btmapc_msg_node_struct msg_node = {0};
    CHAR msg_handle_temp[(SRV_BT_MAP_MAX_HANDLE_STR_LEN + 1) * 2] = {0};
    U16 msg_id = SRV_SMS_INVALID_MSG_ID;
    srv_sms_event_add_struct *event_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_sms_btmapc_box_enum boxType = srv_sms_btmapc_get_curr_box();
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_MSG_NODE_PARSE, boxType);
    
    while ((attr[i] != NULL) && (attr[i+1] != NULL))
    {
        if (strcmp(attr[i], SMS_BTMAPC_ATTR_HD) == 0)
        {
            hd = attr[i+1];
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_SUBJ) == 0)
        {
            S32 dest_size =  strlen(attr[i+1]);
            if(dest_size > SRV_SMS_MSG_INFO_CONTENT_LEN)
            {
                dest_size = SRV_SMS_MSG_INFO_CONTENT_LEN;
            }
            mmi_chset_utf8_to_ucs2_string((U8 *)msg_node.content, dest_size * ENCODING_LENGTH + 2, (U8 *)attr[i+1]);
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_DATETIME) == 0)
        {
            applib_time_struct utc_time;   
            
            dt = attr[i+1];
            srv_sms_btmapc_str_to_utctime(&utc_time, dt);
            msg_node.timestamp = applib_dt_mytime_2_utc_sec(&utc_time, KAL_FALSE);
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_SIZE) == 0)
        {
            U16 size;
            
            size = (U16)atoi(attr[i+1]);
            msg_node.size = size;
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_RCPT_ADDR) == 0)
        {
            if (boxType == SRV_SMS_BTMAPC_BOX_OUTBOX || 
                boxType == SRV_SMS_BTMAPC_BOX_UNSENT ||
                boxType == SRV_SMS_BTMAPC_BOX_DRAFTS)
            {
                if (strlen(attr[i+1]) < SRV_SMS_MAX_ADDR_LEN)
                {
                    memcpy(msg_node.number, attr[i+1], strlen(attr[i+1]));
                }
                else
                {
                    memcpy(msg_node.number, attr[i+1], SRV_SMS_MAX_ADDR_LEN);
                }
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_SENDER_ADDR) == 0)
        {
            if (boxType == SRV_SMS_BTMAPC_BOX_INBOX)
            {
                if (strlen(attr[i+1]) < SRV_SMS_MAX_ADDR_LEN)
                {
                    memcpy(msg_node.number, attr[i+1], strlen(attr[i+1]));
                }
                else
                {
                    memcpy(msg_node.number, attr[i+1], SRV_SMS_MAX_ADDR_LEN);
                }
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_RCPT_NAME) == 0)
        {
           if (boxType == SRV_SMS_BTMAPC_BOX_OUTBOX || 
               boxType == SRV_SMS_BTMAPC_BOX_UNSENT ||
               boxType == SRV_SMS_BTMAPC_BOX_DRAFTS)
            {
                S32 dest_size =  strlen(attr[i+1]);
                if(dest_size > SRV_BT_MAP_MAX_SENDER_NAME_LEN)
                {
                    dest_size = SRV_BT_MAP_MAX_SENDER_NAME_LEN;
                }
                mmi_chset_utf8_to_ucs2_string((U8 *)msg_node.sender_name, dest_size * ENCODING_LENGTH + 2, (U8 *)attr[i+1]);
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_SENDER_NAME) == 0)
        {
            if (boxType == SRV_SMS_BTMAPC_BOX_INBOX)
            {
                S32 dest_size =  strlen(attr[i+1]);
                if(dest_size > SRV_BT_MAP_MAX_SENDER_NAME_LEN)
                {
                    dest_size = SRV_BT_MAP_MAX_SENDER_NAME_LEN;
                }
                mmi_chset_utf8_to_ucs2_string((U8 *)msg_node.sender_name, dest_size * ENCODING_LENGTH + 2, (U8 *)attr[i+1]);
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_TYPE) == 0)
        {
            if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_SMS_TYPE) != 0)
            {
                return KAL_FALSE;
            }
        }
        else if (strcmp(attr[i], SMS_BTMAPC_ATTR_READ) == 0)
        {
            if (boxType != SRV_SMS_BTMAPC_BOX_INBOX)
            {
                i += 2;
                continue;
            }
            if (strcmp(attr[i+1], SMS_BTMAPC_ATTR_VAL_YES) == 0)
            {
                msg_node.status |= SRV_SMS_STATUS_READ;
            }
            else
            {
                msg_node.status |= SRV_SMS_STATUS_UNREAD;
            }
        }
        i+=2;
    }
            
    switch (boxType)
    {
        case SRV_SMS_BTMAPC_BOX_DRAFTS :
        {
            msg_node.status = SRV_SMS_STATUS_DRAFT;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_OUTBOX :
        {
            msg_node.status = SRV_SMS_STATUS_SENT;
            break;
        }
        case SRV_SMS_BTMAPC_BOX_UNSENT :
        {
            msg_node.status = SRV_SMS_STATUS_UNSENT;
            break;
        }
		case SRV_SMS_BTMAPC_BOX_INBOX :
		{
			if(msg_node.status == SRV_SMS_STATUS_NONE)
			{
				msg_node.status = SRV_SMS_STATUS_READ;
			}
			break;

		}
    }
    
    if (srv_sms_btmapc_get_msg_id_by_handle((U8 *)hd) != SRV_SMS_INVALID_MSG_ID)
    {
       return KAL_TRUE;
    }
    else
    {
        msg_node.is_download = MMI_FALSE;
        mmi_asc_to_ucs2(msg_handle_temp, (CHAR *)hd);
        if(strlen(hd) < SRV_BT_MAP_MAX_HANDLE_STR_LEN + 1)
        {
            memcpy(msg_node.msg_handle, msg_handle_temp, strlen(hd) * 2);
        }
        else
        {
            memcpy(msg_node.msg_handle, msg_handle_temp, SRV_BT_MAP_MAX_HANDLE_STR_LEN * 2);
        }
    }
    msg_id = srv_sms_btmapc_add_msg_node(&msg_node);
    /* Set Event data For Add Event */
    if (msg_id != SRV_SMS_INVALID_MSG_ID)
    {
        event_data = (srv_sms_event_add_struct *)OslMalloc(sizeof(srv_sms_event_add_struct));
    
        event_data->msg_id = msg_id;
        srv_sms_btmapc_msg_node_to_msg_info(&event_data->msg_info, &msg_node);
        srv_sms_btmapc_exec_interrupt_event(EVT_ID_SRV_SMS_BTMAPC_ADD_MSG, event_data);
    
        OslMfree(event_data);
    }
    g_sms_btmapc_parser.count++;
    return KAL_TRUE;
}



/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_elem_start_hdlr
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
static void sms_btmapc_elem_start_hdlr(void *data, const kal_char *el, const kal_char **attr, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i=0, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tab_num = sizeof(sms_btmapc_node) / sizeof(sms_btmapc_node[0]);

    g_sms_btmapc_parser.stack++;

    for (i = 0; i < tab_num; i++)
    {
        if (sms_btmapc_node[i].type != SMS_BTMAPC_TYPE_ATTR ||
        strcmp(el, sms_btmapc_node[i].name) != 0   ||
        sms_btmapc_node[i].deep != g_sms_btmapc_parser.stack)
        {
            continue;
        }

        sms_btmapc_node[i].call_back(el, attr, NULL, 0);

        break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_elem_end_hdlr
 * DESCRIPTION
 *  Process element end.
 * PARAMETERS
 *  data  [IN]      data.
 *  el    [IN]      element. 
 *  error [IN]      error code.
 * RETURNS
 *  void.
 *****************************************************************************/
static void sms_btmapc_elem_end_hdlr(void *data, const kal_char *el, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
        
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_XML_ELEM_END_HDLR, error);
    if (g_sms_btmapc_parser.stack > 0)
    {
        g_sms_btmapc_parser.stack--;
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    if (strcmp(el, SMS_BTMAPC_MSG_LIST_NAME) == 0)
    {
        srv_sms_btmapc_storage_save_data();
        if (g_sms_btmapc_parser.count == SMS_BTMAPC_MAX_PARSE_ITEM)
        {
            xml_pause_parse(g_sms_btmapc_xml_parser);
            // TODO: performance failed, can decrease the count
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_data_hdlr
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
static void sms_btmapc_data_hdlr(void *resv, const kal_char *el, const kal_char *data, kal_int32 len, kal_int32 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int32 i, tab_num;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G6_DTCNT, TRC_VAPP_XML_DATA_HDLR, error);
    tab_num = sizeof(sms_btmapc_node) / sizeof(sms_btmapc_node[0]);

    if (error)
    {
        xml_stop_parse((XML_PARSER_STRUCT*)resv);
        return;
    }
    
    if (!g_sms_btmapc_parser.save)
    {
        return;
    }

    for (i = 0; i < tab_num; i++)
    {
        if (strcmp(el, sms_btmapc_node[i].name) != 0 ||
                sms_btmapc_node[i].deep != g_sms_btmapc_parser.stack)
        {
            continue;
        }        
        sms_btmapc_node[i].call_back(el, NULL, data, len);
        break;
    } 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dtcnt_resume_parse_hdlr
 * DESCRIPTION
 *  Resume to parser data account configuration file to pre-install account.
 * PARAMETERS
 *  void *  [IN]        msg.
 * RETURNS
 *  void
 *****************************************************************************/
static void sms_btmapc_resume_parse_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_sms_btmapc_parser.count = 0;
    xml_resume_parse(g_sms_btmapc_xml_parser);
    if (g_sms_btmapc_parser.count < SMS_BTMAPC_MAX_PARSE_ITEM)
    {
        xml_close_parser(g_sms_btmapc_xml_parser);
        memset(&g_sms_btmapc_parser, 0, sizeof(g_sms_btmapc_parser));
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_sms_btmapc_xml_parse
 * DESCRIPTION
 *  parser configuration file to pre-install account.
 * PARAMETERS
 *  void *  [IN]        msg.
 * RETURNS
 *  void
 *****************************************************************************/

kal_int32 srv_sms_btmapc_xml_parse(WCHAR *file_name)
{
     kal_int32 ret;
    

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = xml_new_parser(g_sms_btmapc_xml_parser);
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_XML_PARSE0);
    if (ret < 0)
    {   
        return ret;
    }
    SetProtocolEventHandler(sms_btmapc_resume_parse_hdlr, MSG_ID_MMI_DTCNT_RESUME_PARSE_IND);
    xml_register_element_handler(g_sms_btmapc_xml_parser, sms_btmapc_elem_start_hdlr, sms_btmapc_elem_end_hdlr);
    xml_register_data_handler(g_sms_btmapc_xml_parser, sms_btmapc_data_hdlr);
        
    xml_parse(g_sms_btmapc_xml_parser, file_name);

    ret = g_sms_btmapc_parser.count;
    xml_close_parser(g_sms_btmapc_xml_parser);
    memset(&g_sms_btmapc_parser, 0, sizeof(g_sms_btmapc_parser));
    MMI_TRACE(MMI_COMMON_TRC_G6_MSG, TRC_SRV_SMS_BTMAPC_XML_PARSE1, ret);
    return ret;
}

#endif /*__XML_SUPPORT__*/
#endif /*__SRV_SMS_BTMAPC__*/

