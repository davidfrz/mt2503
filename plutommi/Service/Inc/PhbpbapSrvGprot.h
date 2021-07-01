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
 *  PhbpbapSrvGprot.h
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __PHB_PBAP_SRV_GPROT_H__
#define __PHB_PBAP_SRV_GPROT_H__

#include "MMI_features.h"

#if defined(__BT_PBAP_CLIENT__)

#include "PbapSrvGprot.h"
#include "PhbSrvGprot.h"
#include "BtcmSrvGprot.h"
#include "app_datetime.h"

#ifdef __MMI_PHB_PBAPC_SYNC_CONTACT__
#define __MMI_PHB_PBAPC_NO_CLEAR__
#endif

#ifdef __MMI_PHB_LAST_NAME_FIELD__
#define __SRV_PHB_PBAPC_NAME_ORDER__
#endif

#define SRV_PHB_PBAPC_FAMILY_NAME_LENGTH        (30)
#define SRV_PHB_PBAPC_GIVEN_NAME_LENGTH         (30)
#define SRV_PHB_PBAPC_MID_NAME_LENGTH           (30)

typedef void* SRV_PHB_PBAPC_HANDLE;

/* pbap storage path enum */
typedef enum
{
    SRV_PHB_PBAP_STORAGE_NULL = 0,
    /* phone */
    SRV_PHB_PBAP_STORAGE_PHONE_PB,
    SRV_PHB_PBAP_STORAGE_PHONE_ICH,
    SRV_PHB_PBAP_STORAGE_PHONE_OCH,
    SRV_PHB_PBAP_STORAGE_PHONE_MCH,
    SRV_PHB_PBAP_STORAGE_PHONE_CCH,
    /* sim */
    SRV_PHB_PBAP_STORAGE_SIM1_PB,
    SRV_PHB_PBAP_STORAGE_SIM1_ICH,
    SRV_PHB_PBAP_STORAGE_SIM1_OCH,
    SRV_PHB_PBAP_STORAGE_SIM1_MCH,
    SRV_PHB_PBAP_STORAGE_SIM1_CCH,

    SRV_PHB_PBAP_STORAGE_TOTAL
} srv_phb_pbap_storage_enum;

/* pbap folder type enum */
typedef enum
{
    SRV_PHB_PBAP_FORWARD_FOLDER = PBAP_FORWARD_FOLDER,
    SRV_PHB_PBAP_BACK_FOLDER    = PBAP_BACK_FOLDER,
    SRV_PHB_PBAP_ROOT_FOLDER    = PBAP_ROOT_FOLDER,

    SRV_PHB_PBAP_TOTAL
} srv_phb_pbap_set_folder_type_enum;

/* pbap query attr */
typedef enum
{
    SRV_PHB_PBAP_ATTR_NAME     = PBAP_SEARCH_ATTRIB_NAME,
    SRV_PHB_PBAP_ATTR_NUMBER   = PBAP_SEARCH_ATTRIB_NUMBER,
    SRV_PHB_PBAP_ATTR_SOUND    = PBAP_SEARCH_ATTRIB_SOUND,

    SRV_PHB_PBAP_ATTR_TOTAL
} srv_phb_pbap_query_attr_enum;

/* vcard sort order in listing */
typedef enum
{
    SRV_PHB_PBAP_SORT_ORDER_INDEXED     = PBAP_SORT_ORDER_INDEXED,     /* Indexed sorting  PBAP_SORT_ORDER_INDEXED */
    SRV_PHB_PBAP_SORT_ORDER_ALPHA       = PBAP_SORT_ORDER_ALPHA,       /* Alphabetical sorting */
    SRV_PHB_PBAP_SORT_ORDER_PHONETICAL  = PBAP_SORT_ORDER_PHONETICAL,  /* Phonetical sorting */

    SRV_PHB_PBAP_SORT_ORDER_TOTAL
} srv_phb_pbap_sort_order_enum;

/* vcard format  */
typedef enum
{
    SRV_PHB_PBAP_VCARD_FORMAT_21 = VCARD_FORMAT_21,
    SRV_PHB_PBAP_VCARD_FORMAT_30 = VCARD_FORMAT_30,    
} srv_phb_pbap_vcard_format_enum;

/* phb pbapc job type enum */
typedef enum
{
    SRV_PHB_PBAPC_JOB_NULL = 0,

    SRV_PHB_PBAPC_JOB_SET_PATH,
    SRV_PHB_PBAPC_JOB_READ_LIST,
    SRV_PHB_PBAPC_JOB_READ_FOLDER,
    SRV_PHB_PBAPC_JOB_READ_ENTRY,
    SRV_PHB_PBAPC_JOB_GET_LIST_DATA,

    SRV_PHB_PBAPC_JOB_CREATE_HANDLE,
    SRV_PHB_PBAPC_JOB_DESTORY_HANDLE,

    SRV_PHB_PBAPC_JOB_TOTAL
} srv_phb_pbapc_job_enum;

/* phb pbapc btd enum */
typedef enum
{
    SRV_PHB_PBAPC_BTD_1ST = 0,

    SRV_PHB_PBAPC_BTD_2ND,
    SRV_PHB_PBAPC_BTD_3RD,

    SRV_PHB_PBAPC_BTD_TOTAL
} srv_phb_pbapc_btd_enum;


#define SRV_PHB_PBAP_VCARD_FILTER_VER       (1 << (PBAP_VCARD_FILTER_VER + 1))      /* Version (Bit 0) */
#define SRV_PHB_PBAP_VCARD_FILTER_FN        (1 << (PBAP_VCARD_FILTER_FN + 1))       /* Formatted Name (Bit 1) */
#define SRV_PHB_PBAP_VCARD_FILTER_N         (1 << (PBAP_VCARD_FILTER_N + 1))        /* Structured Presentation of Name (Bit 2) */
#define SRV_PHB_PBAP_VCARD_FILTER_PHOTO     (1 << (PBAP_VCARD_FILTER_PHOTO + 1))    /* Associated Image or Photo (Bit 3) */
#define SRV_PHB_PBAP_VCARD_FILTER_BDAY      (1 << (PBAP_VCARD_FILTER_BDAY + 1))     /* Birthday (Bit 4) */
#define SRV_PHB_PBAP_VCARD_FILTER_ADR       (1 << (PBAP_VCARD_FILTER_ADR + 1))      /* Delivery Address (Bit 5) */
#define SRV_PHB_PBAP_VCARD_FILTER_LABEL     (1 << (PBAP_VCARD_FILTER_LABEL + 1))    /* Delivery (Bit 6) */
#define SRV_PHB_PBAP_VCARD_FILTER_TEL       (1 << (PBAP_VCARD_FILTER_TEL + 1))      /* Telephone (Bit 7) */
#define SRV_PHB_PBAP_VCARD_FILTER_EMAIL     (1 << (PBAP_VCARD_FILTER_EMAIL + 1))    /* Electronic Mail Address (Bit 8) */
#define SRV_PHB_PBAP_VCARD_FILTER_MAILER    (1 << (PBAP_VCARD_FILTER_MAILER + 1))   /* Electronic Mail (Bit 9) */
#define SRV_PHB_PBAP_VCARD_FILTER_TZ        (1 << (PBAP_VCARD_FILTER_TZ + 1))       /* Time Zone (Bit 10) */
#define SRV_PHB_PBAP_VCARD_FILTER_GEO       (1 << (PBAP_VCARD_FILTER_GEO + 1))      /* Geographic Position (Bit 11) */
#define SRV_PHB_PBAP_VCARD_FILTER_TITLE     (1 << (PBAP_VCARD_FILTER_TITLE + 1))    /* Job (Bit 12) */
#define SRV_PHB_PBAP_VCARD_FILTER_ROLE      (1 << (PBAP_VCARD_FILTER_ROLE + 1))     /* Role within the Organization (Bit 13) */
#define SRV_PHB_PBAP_VCARD_FILTER_LOGO      (1 << (PBAP_VCARD_FILTER_LOGO + 1))     /* Organization Logo (Bit 14) */
#define SRV_PHB_PBAP_VCARD_FILTER_AGENT     (1 << (PBAP_VCARD_FILTER_AGENT + 1))    /* vCard of Person Representing (Bit 15) */
#define SRV_PHB_PBAP_VCARD_FILTER_ORG       (1 << (PBAP_VCARD_FILTER_ORG + 1))      /* Name of Organization (Bit 16) */
#define SRV_PHB_PBAP_VCARD_FILTER_NOTE      (1 << (PBAP_VCARD_FILTER_NOTE + 1))     /* Comments (Bit 17) */
#define SRV_PHB_PBAP_VCARD_FILTER_REV       (1 << (PBAP_VCARD_FILTER_REV + 1))      /* Revision (Bit 18) */
#define SRV_PHB_PBAP_VCARD_FILTER_SOUND     (1 << (PBAP_VCARD_FILTER_SOUND + 1))    /* Pronunciation of Name (Bit 19) */
#define SRV_PHB_PBAP_VCARD_FILTER_URL       (1 << (PBAP_VCARD_FILTER_URL + 1))      /* Uniform Resource Locator (Bit 20) */
#define SRV_PHB_PBAP_VCARD_FILTER_UID       (1 << (PBAP_VCARD_FILTER_UID + 1))      /* Unique ID (Bit 21) */
#define SRV_PHB_PBAP_VCARD_FILTER_KEY       (1 << (PBAP_VCARD_FILTER_KEY + 1))      /* Public Encryption Key (Bit 22) */
#define SRV_PHB_PBAP_VCARD_FILTER_NICK      (1 << (PBAP_VCARD_FILTER_NICK + 1))     /* Nickname (Bit 23) */
#define SRV_PHB_PBAP_VCARD_FILTER_CAT       (1 << (PBAP_VCARD_FILTER_CAT + 1))      /* Categories (Bit 24) */
#define SRV_PHB_PBAP_VCARD_FILTER_PRODID    (1 << (PBAP_VCARD_FILTER_PRODID + 1))   /* Product Id (Bit 25) */
#define SRV_PHB_PBAP_VCARD_FILTER_CLASS     (1 << (PBAP_VCARD_FILTER_CLASS + 1))    /* Class Information (Bit 26) */
#define SRV_PHB_PBAP_VCARD_FILTER_SORT_STR  (1 << (PBAP_VCARD_FILTER_SORT_STR + 1)) /* Sort string (Bit 27) */
#define SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP (1 << (PBAP_VCARD_FILTER_TIMESTAMP + 1))/* Time stamp (Bit 28) */

#define SRV_PHB_PBAP_VCARD_FILTER_TOTAL     (PBAP_VCARD_FILTER_TIMESTAMP + 1)

#define SRV_PHB_PBAP_VCARD_FILTER_ALL       (0xffffffff)


#define SRV_PHB_PBAPC_REQ_HEAD              \
    SRV_PHB_PBAPC_HANDLE handle;            \
    U8 bt_index;                            \
    U8 storage;                             \
    void *user_data

#define SRV_PHB_PBAPC_MAX_READ_LIST_COUNT   (0xffff)

#define SRV_PHB_PBAPC_MAX_READ_LIST_NUM     (SRV_PBAPC_XML_PARSE_NUM)

#define SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN    (21) // PBAP_MAX_NAME_LEN/2 128/2

#define SRV_PHB_PBAPC_FOLDER_PATH           (PBAPC_ADP_FOLDER_FILE)

#define SRV_PHB_PBAPC_ENTRY_PATH            (PBAPC_ADP_ENTRY_FILE)

#define SRV_PHB_PBAPC_MAX_PATH_LEN          (127)

#define SRV_PHB_PBAPC_MAX_QUERY_LEN         (32)

/* max support link */
#if (BT_MAX_LINK_NUM) > 1
#define SRV_PHB_PBAPC_LINK_NUM               (BT_MAX_LINK_NUM)
#else
#define SRV_PHB_PBAPC_LINK_NUM               (1)
#endif

/* Structure for the ex-request of reading list */
typedef struct
{
    S32 entry_index;
    U8 entry_name[SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN + 1];
} srv_phb_pbapc_list_entry_struct;

typedef struct
{
    S32 entry_count;
    srv_phb_pbapc_list_entry_struct *list_entry;
} srv_phb_pbapc_read_list_req_ex_struct;

typedef srv_phb_pbapc_read_list_req_ex_struct srv_phb_pbapc_read_list_entry;

/* Structure for the request of reading list */
typedef struct
{
    SRV_PHB_PBAPC_REQ_HEAD;
    U16 *folder_name;
    U8 query_attr;
    U8 order;
    U8 *query_pattern;
    U8 query_length;           /* < SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN */
    U16 query_count;
    U16 query_offset;
    /* ex-req, provide buf to save index & name. list_entry buf size: SRV_PHB_PBAPC_MAX_READ_LIST_NUM * sizeof(srv_phb_pbapc_list_entry_struct) */
    srv_phb_pbapc_read_list_req_ex_struct *list_req_ex;
} srv_phb_pbapc_read_list_req_struct;

/* Structure for the confirmation of reading list   */
typedef struct
{
    U16 phb_size;               // phoneBookSize: 0xffff indicates have only data
    U16 mc;                     //newMissedCalls: 0xffff means type is not MCH
    S32 ret;
    /* when list_valid is TRUE, following data is valid */
    MMI_BOOL is_list_valid;
    U16 more_data;
    S32 entry_count;
    srv_phb_pbapc_read_list_entry *list;
} srv_phb_pbapc_read_list_rsp_struct;


/* Structure for the request of reading entry */
typedef struct
{
    SRV_PHB_PBAPC_REQ_HEAD;
    U16 entry_index;          /* index in pse index.vcf */
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
} srv_phb_pbapc_read_entry_req_struct;

/* Structure for the confirmation of reading entry */
typedef struct
{
    U16 *entry_path;
    S32 ret;
} srv_phb_pbapc_read_entry_rsp_struct;


/* Structure for the request of reading folder */
typedef struct
{
    SRV_PHB_PBAPC_REQ_HEAD;
    U16 *folder_name;
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
    U16 list_count;
    U16 list_offset;
} srv_phb_pbapc_read_folder_req_struct;

/* Structure for the confirmation of reading entry */
typedef struct
{
    U16 phb_size;               // phoneBookSize: 0xffff indicates have only data
    U16 mc;                     //newMissedCalls: 0xffff means type is not MCH
    U16 *folder_path;
    S32 ret;
} srv_phb_pbapc_read_folder_rsp_struct;


/* Structure for the request of reading folder */
typedef struct
{
    SRV_PHB_PBAPC_REQ_HEAD;
    srv_phb_pbap_set_folder_type_enum folder_type;
} srv_phb_pbapc_set_path_req_struct;

/* Structure for the confirmation of reading entry */
typedef struct
{
    S32 ret;
} srv_phb_pbapc_set_path_rsp_struct;


/* phb pbapc notify event struct */
typedef struct
{
    MMI_EVT_PARAM_HEADER
    U8 evt_type;
} srv_phb_pbapc_notify_evt_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_phb_pbapc_btd_enum bt_index;
    U16 sync_count;                             /* sync count */
    U16 total_count;                            /* total count */
} srv_phb_pbapc_sync_status_evt_struct;


typedef struct
{
    MMI_EVT_PARAM_HEADER
    srv_phb_pbapc_btd_enum bt_index;
} srv_phb_pbapc_sync_clear_evt_struct;


/* Result code used in most APIs, should be zero or negative number */
typedef enum
{
    SRV_PHB_PBAPC_RET_OK                    = 0,                     /* Success */
    SRV_PHB_PBAPC_RET_FAIL                  = -1,                    /* Fail */
    SRV_PHB_PBAPC_RET_UNREADY               = -2,                    /* Srv unready */
    SRV_PHB_PBAPC_RET_HD_FULL               = -3,                    /* Handle full */
    SRV_PHB_PBAPC_RET_INVALID               = -4,                    /* Parameter invalid */
    SRV_PHB_PBAPC_RET_JOB_FULL              = -5,                    /* Job full */
    SRV_PHB_PBAPC_RET_BUSY                  = -6,                    /* Srv busy */
    SRV_PHB_PBAPC_RET_DISCONNECTED          = -7,                    /* pbapc don't connect */

    SRV_PHB_PBAPC_RET_UNKNOWN               = -100,                  /* Unknown error */
    SRV_PHB_PBAPC_RET_MAX_ITEM                                       /* Max item */
} srv_phb_pbapc_ret_enum;


#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
typedef struct
{
    U16 family[SRV_PHB_PBAPC_FAMILY_NAME_LENGTH +1];              /* Family Name */
    U16 given[SRV_PHB_PBAPC_GIVEN_NAME_LENGTH +1];                /* Given Name */
    U16 mid[SRV_PHB_PBAPC_MID_NAME_LENGTH +1];                    /* Mid Name */
} srv_phb_pbapc_name_struct;
#endif

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)

typedef struct
{
    U8 type;
    U8 number[SRV_PHB_PBAPC_NUMBER_LENGTH + 1];
} srv_phb_pbapc_number_struct;

typedef struct
{
    U8 storage;
    U8 num_count;
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    srv_phb_pbapc_name_struct name;
#else
    U16 name[SRV_PHB_PBAPC_NAME_LENGTH + 1];
#endif
    srv_phb_pbapc_number_struct number[SRV_PHB_PBAPC_NUMBER_COUNT];
} srv_phb_pbapc_contact_struct;

typedef struct
{
    void *user_data;
} srv_phb_pbapc_load_contact_req;

typedef struct
{
    S32 ret;
    srv_phb_pbapc_btd_enum bt_index;
} srv_phb_pbapc_load_contact_rsp;

#define SRV_PHB_PBAPC_ALPHA_LIST_COUNT                        (26 + 1)

typedef struct
{
    U8 alpha_count;
    U16 jump_pos[SRV_PHB_PBAPC_ALPHA_LIST_COUNT];
    U16 alpha[SRV_PHB_PBAPC_ALPHA_LIST_COUNT];
} srv_phb_pbapc_jump_info_struct;

typedef enum
{
    SRV_PHB_PBAPC_CLT_DEFAULT = 0x00,                 /* Default value, just discard it if act as a filter */
    SRV_PHB_PBAPC_CLT_DIALED = 0x01,                  /* Dialed call log type */
    SRV_PHB_PBAPC_CLT_MISSED = 0x02,                  /* Missed call log type */
    SRV_PHB_PBAPC_CLT_RECVED = 0x04,                  /* Received call log type */
    SRV_PHB_PBAPC_CLT_ALL = 0x0F,                     /* All call log type */
    SRV_PHB_PBAPC_CLT_MAX_ITEM                        /* Max item */
} srv_phb_pbapc_clt_enum;

typedef struct
{
    srv_phb_pbapc_clt_enum call_type;
    WCHAR name[MMI_CLOG_PBAPC_NAME_MAX_LEN + 1];      /* Name */
    U8 cid[MMI_CLOG_PBAPC_CID_MAX_LEN + 1];           /* Caller id (CID), phone number or voip address, in ASCII encode  */
    applib_time_struct timestamp[MMI_CLOG_PBAPC_TIME_DETAIL_MAX_NUM]; /* Timestamp, it is order sequence, and timestamp[0] is the lastest */
} srv_phb_pbapc_clog_struct;

typedef struct
{
    void *user_data;
} srv_phb_pbapc_load_clog_req;

typedef struct
{
    S32 ret;
    srv_phb_pbapc_btd_enum bt_index;
} srv_phb_pbapc_load_clog_rsp;

#endif /* __MMI_PHB_PBAPC_SYNC_CONTACT__ */

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
/* phb name display */
typedef enum
{
    SRV_PHB_PBAPC_NAME_ORDER_1 = 0,                /* last name first name */
    SRV_PHB_PBAPC_NAME_ORDER_2,                    /* first name last name */

    SRV_PHB_PBAPC_NAME_ORDER_TOTAL
} srv_phb_pbapc_name_order_enum;
#endif

/* callback function type */
typedef S32(*srv_phb_pbapc_read_pse_list_cb) (srv_phb_pbapc_read_list_rsp_struct *list_rsp, void *user_data);

typedef S32(*srv_phb_pbapc_read_pse_entry_cb) (srv_phb_pbapc_read_entry_rsp_struct *entry_rsp, void *user_data);

typedef S32(*srv_phb_pbapc_read_pse_folder_cb) (srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

typedef S32(*srv_phb_pbapc_set_pse_path_cb) (srv_phb_pbapc_set_path_rsp_struct *path_rsp, void *user_data);

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)
typedef S32(*srv_phb_pbapc_load_contact_cb) (srv_phb_pbapc_load_contact_rsp *load_rsp, void *user_data);
typedef S32(*srv_phb_pbapc_load_clog_cb) (srv_phb_pbapc_load_clog_rsp *load_rsp, void *user_data);
#endif

/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
#ifdef __cplusplus
extern "C"
{
#endif

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_create_handle
 * DESCRIPTION
 *  this api is employed to create pbapc handle
 * PARAMETERS
 * result       [OUT]  return ret
 * RETURNS
 * if ok, return handle or  NULL
 *****************************************************************************/
extern SRV_PHB_PBAPC_HANDLE srv_phb_pbapc_create_handle_int(S32 *result, const char* file, int line);

#define srv_phb_pbapc_create_handle(result)    srv_phb_pbapc_create_handle_int(result, __FILE__, __LINE__)


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_destory_handle
 * DESCRIPTION
 * this api is employed to destory pbapc handle
 * PARAMETERS
 * hanlde       [IN]    pbapc hanlde created by srv_phb_pbapc_create_handle
 * RETURNS
 * if ok, return success or fail error enum
 *****************************************************************************/
extern S32 srv_phb_pbapc_destory_handle(SRV_PHB_PBAPC_HANDLE handle);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_init_para
 * DESCRIPTION
 * this api is employed to init job req struct
 * PARAMETERS
 * job_type         [IN]        job type enum
 * para               [IN]         req para
 * RETURNS
 * return init ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_init_para(srv_phb_pbapc_job_enum job_type, void *para);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list
 * DESCRIPTION
 * this api is employed to send read pse list req
 * PARAMETERS
 * list_req              [IN]    list req struct
 * cb_func             [IN]     call back function
 * RETURNS
 * return request ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_read_pse_list(srv_phb_pbapc_read_list_req_struct *list_req, srv_phb_pbapc_read_pse_list_cb cb_func);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_entry
 * DESCRIPTION
 * this api is employed to send read pse entry req
 * PARAMETERS
 * entry_req             [IN]    entry req struct
 * cb_func                [IN]     call back function
 * RETURNS
 * return request ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_read_pse_entry(srv_phb_pbapc_read_entry_req_struct *entry_req, srv_phb_pbapc_read_pse_entry_cb cb_func);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_folder
 * DESCRIPTION
 * this api is employed to send read pse folder req
 * PARAMETERS
 * folder_req             [IN]    folder req struct
 * cb_func                 [IN]     call back function
 * RETURNS
 * return request ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_read_pse_folder(srv_phb_pbapc_read_folder_req_struct *folder_req, srv_phb_pbapc_read_pse_folder_cb cb_func);


/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_get_btd_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_phb_pbapc_get_btd_addr(srv_bt_cm_bt_addr *bt_addr, U8 bt_index);


/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_get_btd_index
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_phb_pbapc_get_btd_index(srv_bt_cm_bt_addr *bt_addr, U8 flag);


#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_load_contact
 * DESCRIPTION
 * this api is employed to send load contact req
 * PARAMETERS
 * folder_req             [IN]    load req struct
 * cb_func                 [IN]     call back function
 * RETURNS
 * return request ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_load_contact(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_load_contact_cb cb_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_load_contact_cancel
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
extern void srv_phb_pbapc_load_contact_cancel(srv_phb_pbapc_btd_enum bt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_build_contact_list
 * DESCRIPTION
 *  build contact store_index array by filter
 * PARAMETERS
 *  filter              :   [IN]    build list filter
 *  entry_array         :   [OUT]   output store_index array
 *  max_count           :   [IN]    max count of store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           matched contact's count
 *  <0                  :           refer phb error result
 *****************************************************************************/
extern S32 srv_phb_pbapc_build_contact_list(srv_phb_pbapc_btd_enum bt_index, srv_phb_qsearch_filter_struct* qsearch_filter, U16* entry_array, U32 max_count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_build_alpha_jump_table
 * DESCRIPTION
 *  build alpha jump table
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
extern S32 srv_phb_pbapc_build_alpha_jump_table(U16* entry_array, U16 entry_count, U8 bt_index, srv_phb_pbapc_jump_info_struct *jump_info);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_name
 * DESCRIPTION
 *  This function is used to get PHB name by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  name:               [OUT]       PHB name
 *  len:                [IN]        Name length
 * RETURN VALUES
 *  MMI_TRUE:           Got name
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
extern MMI_BOOL srv_phb_pbapc_get_name(srv_phb_pbapc_btd_enum bt_index, U16 store_index, U16 *name, U16 len);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_number
 * DESCRIPTION
 *  This function is used to get PHB mobile number by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  number:             [OUT]       PHB mobile number
 *  len:                [IN]        Mobile number length
 * RETURN VALUES
 *  MMI_TRUE:           Got number
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
extern MMI_BOOL srv_phb_pbapc_get_number(srv_phb_pbapc_btd_enum bt_index, U16 store_index, U8 num_index, U16 *number, U8 *type, U16 len);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_number_count
 * DESCRIPTION
 *  This function is used to get PHB total records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB total No.
 *****************************************************************************/
extern U16 srv_phb_pbapc_get_number_count(srv_phb_pbapc_btd_enum bt_index, U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_phone_count
 * DESCRIPTION
 *  This function is used to get PHB total records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB total No.
 *****************************************************************************/
extern U16 srv_phb_pbapc_get_phone_count(srv_phb_pbapc_btd_enum bt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_sim_count
 * DESCRIPTION
 *  This function is used to get PHB total records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB total No.
 *****************************************************************************/
extern U16 srv_phb_pbapc_get_sim_count(srv_phb_pbapc_btd_enum bt_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_sync_info
 * DESCRIPTION
 *  This function is used to get PHB total records by PHB storage.
 * PARAMETERS
 *  storage:            [IN]        PHB storage
 * RETURNS
 *  PHB total No.
 *****************************************************************************/
extern void srv_phb_pbapc_get_sync_info(srv_phb_pbapc_btd_enum bt_index, U16 *sync_count, U16 *total_count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_storage
 * DESCRIPTION
 *  This function is used to get PHB storage by store index. If store index is not in a valid range,
 *  it will return 0xFF.
 * PARAMETERS
 *  id:             [IN]        Store index
 * RETURN VALUES
 *  PHB_STORAGE_NVRAM:      Phone storage
 *  PHB_STORAGE_SIM:        SIM storage
 *  PHB_STORAGE_SIM2:       SIM2 storage
 *****************************************************************************/
extern U8 srv_phb_pbapc_get_storage(srv_phb_pbapc_btd_enum bt_index, U16 store_index);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_name_by_number
 * DESCRIPTION
 *  This function is used to get PHB name by the given number. It will call SSE API to search
 *  the number.
 *  If the search ok, but name is empty, or if the search fails, we will fill in name[out] with '\0'.
 * PARAMETERS
 *  number:             [IN]        Number to search
 *  name:               [OUT]       Name to store the search result
 *  len:                [IN]        Name length
 * RETURN VALUES
 *  MMI_TRUE:           Number found
 *  MMI_FALSE:          Number not found
 *****************************************************************************/
extern MMI_BOOL srv_phb_pbapc_get_name_by_number(srv_phb_pbapc_btd_enum bt_index, U16 *number, U16 *name, U16 len);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_load_clog
 * DESCRIPTION
 * this api is employed to send load clog req
 * PARAMETERS
 * folder_req             [IN]    load req struct
 * cb_func                 [IN]     call back function
 * RETURNS
 * return request ret
 *****************************************************************************/
extern S32 srv_phb_pbapc_load_clog(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_load_clog_cb cb_func, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_build_clog_list
 * DESCRIPTION
 *  build clog store_index array by call type
 * PARAMETERS
 *  filter              :   [IN]    build list filter
 *  entry_array         :   [OUT]   output store_index array
 *  max_count           :   [IN]    max count of store_index array
 * RETURNS
 *  S32
 * RETURN VALUES
 *  >=0                 :           matched contact's count
 *  <0                  :           refer phb error result
 *****************************************************************************/
extern S32 srv_phb_pbapc_build_clog_list(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_clt_enum call_type, U16* entry_array, U32 max_count);


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_clog_entry
 * DESCRIPTION
 *  This function is used to get CLOG entry by store index.
 * PARAMETERS
 *  store_index:        [IN]        Store index
 *  name:               [OUT]       PHB name
 *  len:                [IN]        Name length
 * RETURN VALUES
 *  MMI_TRUE:           Got name
 *  MMI_FALSE:          Didn't get it
 *****************************************************************************/
extern MMI_BOOL srv_phb_pbapc_get_clog_entry(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_clt_enum call_type, U16 store_index, srv_phb_pbapc_clog_struct *pse_clog);

#endif /* __MMI_PHB_PBAPC_SYNC_CONTACT__ */

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_get_name_order
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_phb_pbapc_get_name_order(U8 bt_index);


/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_set_name_order
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
extern S32 srv_phb_pbapc_set_name_order(U8 bt_index, U8 name_order);
#endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */

#ifdef __cplusplus
}
#endif

#endif /* defined(__BT_PBAP_CLIENT__) */

#endif /* __PHB_PBAP_SRV_GPROT_H__ */

