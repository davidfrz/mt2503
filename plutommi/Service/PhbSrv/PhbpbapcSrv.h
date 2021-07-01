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
 *  PhbpbapcSrv.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PHB_PBAPC_SRV_H__
#define __PHB_PBAPC_SRV_H__

#include "MMI_features.h"

#if defined(__BT_PBAP_CLIENT__)

/*----------------------------------------------------------------------------*/
/* Include                                                                    */
/*----------------------------------------------------------------------------*/
/* KAL Layer */
#include "kal_general_types.h"

/* MMI Layer */
#include "MMIDataType.h"
#include "PhbpbapSrvGprot.h"
#include "MMI_common_app_trc.h"

#include "MMI_trc_Int.h"
#include "string.h"
#include "kal_trace.h"
#include "MMI_include.h"
#include "Nvram_common_defs.h"
#include "mmi_rp_srv_phb_def.h"

#define SRV_PHB_PBAP_TRACE_GROUP     TRACE_GROUP_9


#define SRV_PHB_PBAPC_MAX_HANDLE_NUM            (5)
#define SRV_PHB_PBAPC_MAX_JOB_NUM               (5)
#define SRV_PHB_PBAPC_MAX_PID                   (0x6fffffff)
#define SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN          (32)

#define SRV_PHB_PBAPC_OBJ_NAME_SUFFIX           (L".vcf")

#define SRV_PHB_PBAPC_WORK_FOLDER     (L"Z:\\@pbapc\\")
#define SRV_PHB_PBAPC_FILE_1ST        (L"Z:\\@pbapc\\1st.tmp")
#define SRV_PHB_PBAPC_FILE_2ND        (L"Z:\\@pbapc\\2nd.tmp")
#define SRV_PHB_PBAPC_FILE_3RD        (L"Z:\\@pbapc\\3rd.tmp")
#define SRV_PHB_PBAPC_FILE_4TH        (L"Z:\\@pbapc\\4th.tmp")
#define SRV_PHB_PBAPC_FILE_5TH        (L"Z:\\@pbapc\\5th.tmp")
#define SRV_PHB_PBAPC_FILE_6TH        (L"Z:\\@pbapc\\6th.tmp")


/* phb pbapc job state enum */
typedef enum
{
    SRV_PHB_PBAPC_STATE_NULL = 0,

    SRV_PHB_PBAPC_STATE_IDLE,
    SRV_PHB_PBAPC_STATE_PENDING,
    SRV_PHB_PBAPC_STATE_RUNNING,
    SRV_PHB_PBAPC_STATE_CANCEL,
    SRV_PHB_PBAPC_STATE_FINISH,

    SRV_PHB_PBAPC_STATE_TOTAL
} srv_phb_pbapc_state_enum;

typedef struct
{
    void *para;
    S32 list_count;
} srv_phb_pbapc_handle_ex_strcut;

/* phb pbapc handle struct */
typedef struct
{
    U8 flag; /* b0-- 0x00:  un-used, 0x01: used */
    U8 index;
    S32 pid;

    /* debug info */
    CHAR file[64];
    S32 line;
} srv_phb_pbapc_handle_struct;

/* phb pbapc job struct */
typedef struct
{
    U8 flag;        /*b0--0x00: unused, 0x01: used */
    U8 job_type;
    U8 job_state;
    U8 hd_index;
    U8 bt_index;
    S32 pid;

    /* info */
    void *user_data;
    void *func_cb;
    void *para;
} srv_phb_pbapc_job_struct;

/* phb pbapc btd struct */
typedef struct
{
    U8 cur_path;
    U8 want_path;
} srv_phb_pbapc_btd_struct;

/* phb pbapc job mgr struct */
typedef struct
{
    U8 used;
    srv_phb_pbapc_job_struct job[SRV_PHB_PBAPC_MAX_JOB_NUM];
} srv_phb_pbapc_job_mgr_struct;

/* phb pbapc handle mgr struct */
typedef struct
{
    U8 used;
    srv_phb_pbapc_handle_struct handle[SRV_PHB_PBAPC_MAX_HANDLE_NUM];
} srv_phb_pbapc_handle_mgr_struct;

/* phb pbapc btd mgr struct */
typedef struct
{
    srv_phb_pbapc_btd_struct btd[SRV_PHB_PBAPC_LINK_NUM];
} srv_phb_pbapc_btd_mgr_struct;

/* phb pbapc cntx struct */
typedef struct
{
    /* */
    MMI_BOOL ready;
    U32 pid;

    /* mgr struct */
    srv_phb_pbapc_job_struct *job;                  /* running job */
    srv_phb_pbapc_job_mgr_struct *job_mgr;          /* job mgr */
    srv_phb_pbapc_handle_mgr_struct *hd_mgr;    /* handle mgr */
    srv_phb_pbapc_btd_mgr_struct *btd_mgr;          /* btd mgr */
} srv_phb_pbapc_cntx_struct;

typedef struct
{
    S32 srv_handle;
    void *para;
    void *user_data;
} srv_phb_pbapc_async_hdlr_struct;


/* Structure for the request of prepare reading list */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_list_cb cb_func;
    S32 srv_hd;

    U16 *folder_name;
    U8 query_attr;
    U8 order;
    U8 *query_pattern;
    U8 query_length;           /* < SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN */
    U16 query_count;
    U16 query_offset;
    /* ex-req, provide buf to save index & name. list_entry buf size: SRV_PHB_PBAPC_MAX_READ_LIST_NUM * sizeof(srv_phb_pbapc_list_entry_struct) */
    srv_phb_pbapc_read_list_req_ex_struct list_req_ex;
} srv_phb_pbapc_prepare_read_list_req_struct;


/* Structure for the request of prepare reading folder */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_folder_cb cb_func;
    S32 srv_hd;

    U16 *folder_name;
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
    U16 list_count;
    U16 list_offset;
} srv_phb_pbapc_prepare_read_folder_req_struct;


/* Structure for the request of prepare reading entry */
typedef struct
{
    srv_phb_pbap_storage_enum storage;
    void *user_data;
    srv_phb_pbapc_read_pse_entry_cb cb_func;
    S32 srv_hd;

    U16 entry_index;          /* index in pse index.vcf */
    srv_phb_pbap_vcard_format_enum vcard_format;
    U32 vcard_filter;
} srv_phb_pbapc_prepare_read_entry_req_struct;


/* function declare */

static srv_phb_pbapc_handle_struct *srv_phb_pbapc_get_handle_from_srv_hd(S32 srv_hd, S32 *result);

static void srv_phb_pbapc_read_pse_list_hdlr(srv_pbapc_notify_event_struct *notify_evt);

static void srv_phb_pbapc_read_pse_entry_hdlr(srv_pbapc_notify_event_struct *notify_evt);

static void srv_phb_pbapc_read_pse_folder_hdlr(srv_pbapc_notify_event_struct *notify_evt);

static void srv_phb_pbapc_read_list_data_hdlr(srv_pbapc_notify_event_struct *notify_evt);

static void srv_phb_pbapc_disconnect_pse_hdlr(void *user_data);

static void srv_phb_pbapc_set_pse_path_hdlr(srv_pbapc_notify_event_struct *notify_evt);

static srv_phb_pbapc_cntx_struct *srv_phb_pbapc_get_cntx(void);

static srv_pbapc_path_enum srv_phb_pbapc_get_path_enum(srv_phb_pbap_storage_enum storage);

static void srv_phb_pbapc_copy_list_entry(srv_phb_pbapc_job_struct *job, srv_pbapc_notify_event_struct *notify_evt);

static srv_phb_pbapc_job_enum srv_phb_pbapc_get_job_type(S32 srv_hd);

static S32 srv_phb_pbapc_set_pse_path(srv_phb_pbapc_set_path_req_struct *path_req, srv_phb_pbapc_set_pse_path_cb cb_func);

static S32 srv_phb_pbapc_get_folder_name(srv_phb_pbap_storage_enum folder, U16 *folder_name, U16 name_len);

static S32 srv_phb_pbapc_get_obj_name(U16 entry_index, U16 *obj_name, U16 name_len);

static void srv_phb_pbapc_start_read_data(void *user_data);

static void srv_phb_pbapc_free_job(srv_phb_pbapc_job_struct *job);

static void srv_phb_pbapc_async_process();

static void srv_phb_pbapc_job_process(srv_phb_pbapc_job_struct *job);

static void srv_phb_pbapc_job_folder(srv_phb_pbapc_job_struct *job);

static void srv_phb_pbapc_job_list(srv_phb_pbapc_job_struct *job);

static void srv_phb_pbapc_job_entry(srv_phb_pbapc_job_struct *job);

static void srv_phb_pbapc_err_handler(srv_phb_pbapc_job_struct *job, S32 ret);

static void srv_phb_pbapc_job_continue_hdlr(void *para);

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
S32 srv_phb_pbapc_convert_name(srv_phb_pbapc_name_struct *name, U16 *cov, U16 len, U8 bt_index);
S32 srv_phb_pbapc_convert_name_ex(srv_phb_pbapc_name_struct *name, U8 order, U16 *cov, U16 len, U8 bt_index);
#endif
#define __SRV_PHB_PBAPC_TEST_TST__

#endif /* defined(__BT_PBAP_CLIENT__) */

#endif /* __PHB_PBAPC_SRV_H__ */

