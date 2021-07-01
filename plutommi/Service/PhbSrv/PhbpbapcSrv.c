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
 *  PhbpbapcSrv.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__BT_PBAP_CLIENT__)

#include "PbapSrvGprot.h"
#include "PhbpbapcSrv.h"
#include "PhbpbapSrvGprot.h"
#include "PhbSrvIprot.h"
#include "PhbSrv.h"
#include "Unicodexdcl.h"

/* variable */

static const WCHAR *g_srv_phb_pbapc_path[] =
{
    L"",                    /* SRV_PHB_PBAP_STORAGE_NO */

    L"telecom/pb",          /* SRV_PHB_PBAP_STORAGE_PHONE_PB */
    L"telecom/ich",         /* SRV_PHB_PBAP_STORAGE_PHONE_ICH */
    L"telecom/och",         /* SRV_PHB_PBAP_STORAGE_PHONE_OCH */
    L"telecom/mch",         /* SRV_PHB_PBAP_STORAGE_PHONE_MCH */
    L"telecom/cch",         /* SRV_PHB_PBAP_STORAGE_PHONE_CCH */

    L"SIM1/telecom/pb",     /* SRV_PHB_PBAP_STORAGE_SIM1_PB */
    L"SIM1/telecom/ich",    /* SRV_PHB_PBAP_STORAGE_SIM1_ICH */    
    L"SIM1/telecom/och",    /* SRV_PHB_PBAP_STORAGE_SIM1_OCH */
    L"SIM1/telecom/mch",    /* SRV_PHB_PBAP_STORAGE_SIM1_MCH */
    L"SIM1/telecom/cch",    /* SRV_PHB_PBAP_STORAGE_SIM1_CCH */

    L"End"                  /* SRV_PHB_PBAP_STORAGE_TOTAL */
};

static const WCHAR *srv_phb_pbapc_folder_name[] =
{
    L"",            /* SRV_PHB_PBAP_STORAGE_NO */

    L"pb",          /* SRV_PHB_PBAP_STORAGE_PHONE_PB */
    L"ich",         /* SRV_PHB_PBAP_STORAGE_PHONE_ICH */
    L"och",         /* SRV_PHB_PBAP_STORAGE_PHONE_OCH */
    L"mch",         /* SRV_PHB_PBAP_STORAGE_PHONE_MCH */
    L"cch",         /* SRV_PHB_PBAP_STORAGE_PHONE_CCH */

    L"pb",          /* SRV_PHB_PBAP_STORAGE_SIM1_PB */
    L"ich",         /* SRV_PHB_PBAP_STORAGE_SIM1_ICH */    
    L"och",         /* SRV_PHB_PBAP_STORAGE_SIM1_OCH */
    L"mch",         /* SRV_PHB_PBAP_STORAGE_SIM1_MCH */
    L"cch",         /* SRV_PHB_PBAP_STORAGE_SIM1_CCH */

    L"End"          /* SRV_PHB_PBAP_STORAGE_TOTAL */
};


static const WCHAR *srv_phb_pbapc_file_name[] = 
{
    SRV_PHB_PBAPC_FILE_1ST, // PHB TAB1
    SRV_PHB_PBAPC_FILE_2ND, // PHB TAB2
    SRV_PHB_PBAPC_FILE_3RD, // PHB TAB3
    SRV_PHB_PBAPC_FILE_4TH, // CLOG TAB1
    SRV_PHB_PBAPC_FILE_5TH, // CLOG TAB2
    SRV_PHB_PBAPC_FILE_6TH  // CLOG TAB3
};


/* btd mgr */
static srv_phb_pbapc_btd_mgr_struct srv_phb_pbapc_btd_mgr;
/* job mgr */
static srv_phb_pbapc_job_mgr_struct srv_phb_pbapc_job_mgr;
/* handle mgr */
static srv_phb_pbapc_handle_mgr_struct srv_phb_pbapc_handle_mgr;
/* cntx */
static srv_phb_pbapc_cntx_struct srv_phb_pbapc_cntx;

srv_phb_pbapc_read_list_req_ex_struct g_srv_phb_pbapc_list_req;

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
U16 g_srv_phb_pbapc_name_order = 0; /*b0~b3 BTD1; b4~b7 BTD2; b8~b11; BTD3; b12~b15 BTD4*/
#endif
/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_init
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_pbapc_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&srv_phb_pbapc_cntx, 0x00, sizeof(srv_phb_pbapc_cntx_struct));
    memset(&srv_phb_pbapc_job_mgr, 0x00, sizeof(srv_phb_pbapc_job_mgr_struct));
    memset(&srv_phb_pbapc_btd_mgr, 0x00, sizeof(srv_phb_pbapc_btd_mgr_struct));
    memset(&srv_phb_pbapc_handle_mgr, 0x00, sizeof(srv_phb_pbapc_handle_mgr_struct));

    srv_phb_pbapc_cntx.job = NULL;
    srv_phb_pbapc_cntx.job_mgr = &srv_phb_pbapc_job_mgr;
    srv_phb_pbapc_cntx.btd_mgr = &srv_phb_pbapc_btd_mgr;
    srv_phb_pbapc_cntx.hd_mgr = &srv_phb_pbapc_handle_mgr;

    srv_phb_pbapc_cntx.ready = MMI_TRUE;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_INIT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_cntx
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_phb_pbapc_cntx_struct *srv_phb_pbapc_get_cntx()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &srv_phb_pbapc_cntx;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_is_ready
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static MMI_BOOL srv_phb_pbapc_is_ready()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    return srv_cntx_p->ready;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_bt_notify
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
mmi_ret srv_phb_pbapc_bt_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_notify_event_struct *notify_evt = (srv_pbapc_notify_event_struct *)evt;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BT_NOTIFY, notify_evt->type, notify_evt->bt_index, srv_cntx_p->job->job_type);

    switch (notify_evt->type)
    {
        case EVT_ID_PBAPC_READ_FOLDER_RSP:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->job_type == SRV_PHB_PBAPC_JOB_READ_FOLDER)
            {
                srv_phb_pbapc_read_pse_folder_hdlr(notify_evt);
            }

            break;
        }

        case EVT_ID_PBAPC_READ_LIST_RSP:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->job_type == SRV_PHB_PBAPC_JOB_READ_LIST)
            {
                srv_phb_pbapc_read_pse_list_hdlr(notify_evt);
            }

            break;
        }

        case EVT_ID_PBAPC_READ_DATA_RSP:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->job_type == SRV_PHB_PBAPC_JOB_GET_LIST_DATA)
            {
                srv_phb_pbapc_read_list_data_hdlr(notify_evt);
            }

            break;
        }

        case EVT_ID_PBAPC_READ_ENTRY_RSP:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->job_type == SRV_PHB_PBAPC_JOB_READ_ENTRY)
            {
                srv_phb_pbapc_read_pse_entry_hdlr(notify_evt);
            }

            break;
        }

        case EVT_ID_PBAPC_SET_PATH_RSP:
        {
            if (srv_cntx_p->job)
            {
                srv_phb_pbapc_set_pse_path_hdlr(notify_evt);
            }
            break;
        }

        case EVT_ID_PBAPC_CONNECT_RSP:
        {
            break;
        }

        case EVT_ID_PBAPC_DISCONNECT_RSP:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->bt_index == notify_evt->bt_index)
            {
                srv_phb_pbapc_err_handler(srv_cntx_p->job, SRV_PHB_PBAPC_RET_FAIL);
            }

            break;
        }

        case EVT_ID_PBAPC_DISCONNECT_IND:
        {
            if (srv_cntx_p->job &&
                srv_cntx_p->job->bt_index == notify_evt->bt_index)
            {
                srv_phb_pbapc_err_handler(srv_cntx_p->job, SRV_PHB_PBAPC_RET_FAIL);
            }

            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_list_hdlr(srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_read_list_rsp_struct *list_rsp = (srv_pbapc_read_list_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_job_struct *job = NULL;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_read_list_rsp_struct rsp;
    srv_phb_pbapc_read_pse_list_cb func_cb = NULL;
    void *user_data = NULL;
    srv_phb_pbapc_read_list_req_struct *list_req = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    MMI_BOOL need_cb = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;
    list_req = (srv_phb_pbapc_read_list_req_struct *)job->para;
    func_cb = (srv_phb_pbapc_read_pse_list_cb) job->func_cb;
    user_data = job->user_data;

    memset(&rsp, 0x00, sizeof(srv_phb_pbapc_read_list_rsp_struct));

    if (list_rsp->ret == SRV_PBAPC_RET_OK)
    {
        rsp.ret = SRV_PHB_PBAPC_RET_OK;
        rsp.phb_size = list_rsp->phoneBookSize;
        rsp.mc = list_rsp->newMissedCalls;
        rsp.is_list_valid = MMI_FALSE;

        /* change job type */
        job->job_type = SRV_PHB_PBAPC_JOB_GET_LIST_DATA;
        /* async notify pbapc srv parse xml file */
        srv_phb_async_event_interface(srv_phb_pbapc_start_read_data, NULL);
    }
    else
    {
        rsp.ret = SRV_PHB_PBAPC_RET_FAIL;

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

        job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
        srv_phb_pbapc_free_job(job);
        srv_cntx_p->job = NULL;
    }

    /* send msg to drive job flow */
    srv_phb_pbapc_async_process();

    /* callback app */
    func_cb(&rsp, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_list_data_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_list_data_hdlr(srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_list_data_rsp_struct *data_rsp = (srv_pbapc_list_data_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_read_list_rsp_struct list_rsp;
    srv_phb_pbapc_read_list_req_struct *list_req = NULL;
    srv_phb_pbapc_job_struct *job = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    srv_phb_pbapc_read_pse_list_cb func_cb = NULL;
    void *user_data = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;
    list_req = (srv_phb_pbapc_read_list_req_struct *)job->para;
    user_data = job->user_data;
    func_cb = (srv_phb_pbapc_read_pse_list_cb)job->func_cb;

    /* copy list data */
    srv_phb_pbapc_copy_list_entry(srv_cntx_p->job, notify_evt);

    /* fill list rsp */
    memset(&list_rsp, 0x00, sizeof(srv_phb_pbapc_read_list_rsp_struct));
    list_rsp.phb_size = 0xffff;
    list_rsp.mc = 0xffff;
    list_rsp.ret = SRV_PHB_PBAPC_RET_OK;
    list_rsp.is_list_valid = MMI_TRUE;
    list_rsp.more_data = data_rsp->more;
    list_rsp.entry_count = data_rsp->num;
    list_rsp.list = list_req->list_req_ex;

    if (data_rsp->more == 0)
    {
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

        job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
        srv_phb_pbapc_free_job(job);
        srv_cntx_p->job = NULL;

        /* send msg to drive job flow */
        srv_phb_pbapc_async_process();
    }

    /* callback app */
    ret = func_cb(&list_rsp, user_data);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_entry_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_entry_hdlr(srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_read_entry_rsp_struct *entry_rsp = (srv_pbapc_read_entry_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_job_struct *job = NULL;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_read_entry_rsp_struct rsp;
    srv_phb_pbapc_read_pse_entry_cb func_cb = NULL;
    void *user_data = NULL;
    srv_phb_pbapc_read_entry_req_struct *entry_req = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    MMI_BOOL need_cb = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;
    entry_req = (srv_phb_pbapc_read_entry_req_struct *)job->para;
    func_cb = (srv_phb_pbapc_read_pse_entry_cb) job->func_cb;
    user_data = job->user_data;

    memset(&rsp, 0x00, sizeof(srv_phb_pbapc_read_folder_rsp_struct));
    if (entry_rsp->ret == SRV_PBAPC_RET_OK)
    {
        rsp.ret = SRV_PHB_PBAPC_RET_OK;
        rsp.entry_path = SRV_PHB_PBAPC_ENTRY_PATH;
    }
    else
    {
        rsp.ret = SRV_PHB_PBAPC_RET_FAIL;
    }

    #if 0
/* under construction !*/
    #endif

    if (SRV_PHB_PBAPC_STATE_RUNNING == job->job_state)
    {
        need_cb = MMI_TRUE;
    }

    job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
    srv_phb_pbapc_free_job(job);
    srv_cntx_p->job = NULL;

    /* send msg to drive job flow */
    srv_phb_pbapc_async_process();

    /* callback app */
    if (need_cb)
    {
        func_cb(&rsp, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_folder_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_read_pse_folder_hdlr(srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_read_folder_rsp_struct *folder_rsp = (srv_pbapc_read_folder_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_job_struct *job = NULL;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_read_folder_rsp_struct rsp;
    srv_phb_pbapc_read_pse_folder_cb func_cb = NULL;
    void *user_data = NULL;
    srv_phb_pbapc_read_folder_req_struct *folder_req = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    MMI_BOOL need_cb = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;
    folder_req = (srv_phb_pbapc_read_folder_req_struct *)job->para;
    func_cb = (srv_phb_pbapc_read_pse_folder_cb) job->func_cb;
    user_data = job->user_data;

    memset(&rsp, 0x00, sizeof(srv_phb_pbapc_read_folder_rsp_struct));
    if (folder_rsp->ret == SRV_PBAPC_RET_OK)
    {
        rsp.ret = SRV_PHB_PBAPC_RET_OK;
        rsp.folder_path = SRV_PHB_PBAPC_FOLDER_PATH;
        rsp.mc = folder_rsp->newMissedCalls;
        rsp.phb_size = folder_rsp->phoneBookSize;
    }
    else
    {
        rsp.ret = SRV_PHB_PBAPC_RET_FAIL;
    }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    if (SRV_PHB_PBAPC_STATE_RUNNING == job->job_state)
    {
        need_cb = MMI_TRUE;
        job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
    }

    srv_phb_pbapc_free_job(job);
    srv_cntx_p->job = NULL;

    /* send msg to drive job flow */
    srv_phb_pbapc_async_process();

    /* callback app */
    if (need_cb)
    {
        func_cb(&rsp, user_data);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_set_pse_path_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_set_pse_path_hdlr(srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_set_path_rsp_struct *path_rsp = (srv_pbapc_set_path_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_job_struct *job = NULL;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_btd_struct *btd = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    U8 bt_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;
    bt_index = job->bt_index;
    btd = &(srv_cntx_p->btd_mgr->btd[bt_index]);

    /* path success, can proecess next */
    if (path_rsp->ret == SRV_PBAPC_RET_OK)
    {
        btd->cur_path = btd->want_path;
        srv_phb_pbapc_job_process(job);
    }
    else /* fail call back app */
    {
        btd->cur_path = SRV_PHB_PBAP_STORAGE_NULL;

        srv_phb_pbapc_err_handler(job, SRV_PHB_PBAPC_RET_FAIL);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_path_enum
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_pbapc_path_enum srv_phb_pbapc_get_path_enum(srv_phb_pbap_storage_enum storage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_path_enum path = PBAPC_PATH_ROOT;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (storage)
    {
        case SRV_PHB_PBAP_STORAGE_PHONE_PB:
        {
            path = PBAPC_PATH_PHONEBOOK;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_ICH:
        {
            path = PBAPC_PATH_INCOMING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_OCH:
        {
            path = PBAPC_PATH_OUTGOING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_MCH:
        {
            path = PBAPC_PATH_MISSED;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_PHONE_CCH:
        {
            path = PBAPC_PATH_COMBINED;
            break;
        }
        /* sim */
        case SRV_PHB_PBAP_STORAGE_SIM1_PB:
        {
            path = PBAPC_PATH_SIM_PHONEBOOK;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_ICH:
        {
            path = PBAPC_PATH_SIM_INCOMING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_OCH:
        {
            path = PBAPC_PATH_SIM_OUTGOING;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_MCH:
        {
            path = PBAPC_PATH_SIM_MISSED;
            break;
        }
        case SRV_PHB_PBAP_STORAGE_SIM1_CCH:
        {
            path = PBAPC_PATH_SIM_COMBINED;
            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return path;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_copy_list_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_copy_list_entry(srv_phb_pbapc_job_struct *job, srv_pbapc_notify_event_struct *notify_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_list_data_rsp_struct *data_rsp = (srv_pbapc_list_data_rsp_struct *)notify_evt->data;
    srv_phb_pbapc_read_list_req_struct *list_req = (srv_phb_pbapc_read_list_req_struct *)job->para;
    srv_phb_pbapc_read_list_req_ex_struct *list_entry_ex = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    S32 i = 0;
    S32 max_read = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    list_entry_ex = list_req->list_req_ex;
    max_read = (list_entry_ex->entry_count > data_rsp->num ? (data_rsp->num):(list_entry_ex->entry_count));

    for (i = 0; i < max_read; ++i)
    {
        list_entry_ex->list_entry[i].entry_index = data_rsp->handle[i];
        memcpy(list_entry_ex->list_entry[i].entry_name, data_rsp->name[i], SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN);
        list_entry_ex->list_entry[i].entry_name[SRV_PHB_PBAPC_MAX_ENTRY_NAME_LEN] = L'\0';

        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CY_LIST, data_rsp->handle[i], data_rsp->name[i]);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_obj_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_obj_name(U16 entry_index, U16 *obj_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wsprintf_ex((WCHAR *)obj_name, name_len, (WCHAR *)L"%x", entry_index);
    mmi_wcsncat(obj_name, SRV_PHB_PBAPC_OBJ_NAME_SUFFIX, mmi_wcslen(SRV_PHB_PBAPC_OBJ_NAME_SUFFIX));

    return mmi_wcslen(obj_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_folder_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_folder_name(srv_phb_pbap_storage_enum folder, U16 *folder_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR *) folder_name, srv_phb_pbapc_folder_name[folder]);
    mmi_wcs_to_asc(name, (WCHAR *)srv_phb_pbapc_folder_name[folder]);
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_FOLER_NAME, name);
    return mmi_wcslen(folder_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_folder_name
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static S32 srv_phb_pbapc_get_file_name(srv_phb_pbap_storage_enum folder, U16 *file_name, U16 name_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcscpy((WCHAR *)file_name, g_srv_phb_pbapc_path[folder]);
    mmi_wcscat((WCHAR *)file_name, (WCHAR *)L".vcf");
    mmi_wcs_to_asc(name, (WCHAR *)file_name);
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_FILE_NAME, name);

    return mmi_wcslen(file_name);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_vcard_filter
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_get_vcard_filter(PbapVcardFilter *vcard_filter, U32 filter)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(vcard_filter, 0x0, sizeof(PbapVcardFilter));

    filter &= (~SRV_PHB_PBAP_VCARD_FILTER_PHOTO); /* filter remove photo */

    for (i = PBAP_VCARD_FILTER_VER; i < SRV_PHB_PBAP_VCARD_FILTER_TOTAL; ++i)
    {
        if (filter & (1 << (i + 1)))
        {
            vcard_filter->byte[i / 8] |= (1 << (i % 8));
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_start_read_data
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_start_read_data(void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_job_struct *job = NULL;
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_START_READ_DATA);

    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job;

    srv_pbapc_start_read_data(job->bt_index);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_check_para
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_check_para(U8 job_type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (job_type)
    {
        case SRV_PHB_PBAPC_JOB_READ_FOLDER:
        {
            srv_phb_pbapc_read_folder_req_struct *folder_req = (srv_phb_pbapc_read_folder_req_struct *) para;

            if (srv_phb_pbapc_get_job_used() == SRV_PHB_PBAPC_MAX_JOB_NUM)
            {
                ret = SRV_PHB_PBAPC_RET_JOB_FULL;
            }
            else if (!srv_pbapc_is_connect(folder_req->bt_index))
            {
                ret = SRV_PHB_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PHB_PBAPC_JOB_CREATE_HANDLE:
        {
            if (!srv_phb_pbapc_is_ready())
            {
                ret = SRV_PHB_PBAPC_RET_UNREADY;
            }
            else if (srv_phb_pbapc_get_hd_used() == SRV_PHB_PBAPC_MAX_HANDLE_NUM)
            {
                ret = SRV_PHB_PBAPC_RET_HD_FULL;
            }

            break;
        }

        case SRV_PHB_PBAPC_JOB_DESTORY_HANDLE:
        {
            srv_phb_pbapc_handle_struct *hd = (srv_phb_pbapc_handle_struct *) para;

            if (!hd)
            {
                ret = SRV_PHB_PBAPC_RET_INVALID;
            }

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_LIST:
        {
            srv_phb_pbapc_read_list_req_struct *list_req = (srv_phb_pbapc_read_list_req_struct *) para;

            if (srv_phb_pbapc_get_job_used() == SRV_PHB_PBAPC_MAX_JOB_NUM)
            {
                ret = SRV_PHB_PBAPC_RET_JOB_FULL;
            }
            else if (!srv_pbapc_is_connect(list_req->bt_index))
            {
                ret = SRV_PHB_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_ENTRY:
        {
            srv_phb_pbapc_read_entry_req_struct *entry_req = (srv_phb_pbapc_read_entry_req_struct *) para;

            if (srv_phb_pbapc_get_job_used() == SRV_PHB_PBAPC_MAX_JOB_NUM)
            {
                ret = SRV_PHB_PBAPC_RET_JOB_FULL;
            }
            else if (!srv_pbapc_is_connect(entry_req->bt_index))
            {
                ret = SRV_PHB_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        default:
        {
            MMI_ASSERT(0);
            break;
        }
    }

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_hd_used
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_get_hd_used()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    return srv_cntx_p->hd_mgr->used;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_free_hd
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
srv_phb_pbapc_handle_struct *srv_phb_pbapc_get_free_hd()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_handle_struct *hd = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    hd = srv_cntx_p->hd_mgr->handle;

    /* find free hd */
    for (i = 0; i < SRV_PHB_PBAPC_MAX_HANDLE_NUM; ++i)
    {
        if ((hd->flag & 0x01) == 0x00)
        {
            break;
        }

        hd++;
    }

    srv_cntx_p->hd_mgr->used += 1;
    /* init hd */
    hd->flag |= 0x01;
    hd->index = i;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_FREE_HD, hd->index, srv_cntx_p->hd_mgr->used);

    return hd;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_cancel_job
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_cancel_job(srv_phb_pbapc_handle_struct *hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_job_struct *job = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job_mgr->job;

    for (i = 0; i < SRV_PHB_PBAPC_MAX_JOB_NUM; ++i)
    {
        if ((job->flag & 0x01) == 0x01)
        {
            if (job->hd_index == hd->index)
            {
                /* running, wait rsp coming  */
                if (job->job_state == SRV_PHB_PBAPC_STATE_RUNNING)
                {
                    job->job_state = SRV_PHB_PBAPC_STATE_CANCEL;
                }
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
                else if (job->job_state == SRV_PHB_PBAPC_STATE_CANCEL)
                {
                    /* later free job */
                    ;
                }
                else
                {
                    job->job_state = SRV_PHB_PBAPC_STATE_CANCEL;
                    srv_phb_pbapc_free_job(job);
                }
            }
        }

        job++;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_job_used
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_get_job_used()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    return srv_cntx_p->job_mgr->used;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_free_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
void srv_phb_pbapc_free_handle(srv_phb_pbapc_handle_struct *hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    S32 index = hd->index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    memset(hd, 0x00, sizeof(srv_phb_pbapc_handle_struct));
    srv_cntx_p->hd_mgr->used -= 1;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_FREE_HANDLE, index, srv_cntx_p->hd_mgr->used);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_free_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_free_job(srv_phb_pbapc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_FREE_JOB,
                    job->job_type, job->job_state, job->bt_index, job->hd_index, job->func_cb);

    srv_cntx_p = srv_phb_pbapc_get_cntx();

    /* free mem */
    if (job->para)
    {
        switch (job->job_type)
        {
            case SRV_PHB_PBAPC_JOB_READ_LIST:
            {
                srv_phb_pbapc_read_list_req_struct *list_req = (srv_phb_pbapc_read_list_req_struct *) job->para;

                if (list_req->folder_name)
                {
                    srv_phb_mem_free(list_req->folder_name);
                }
                if (list_req->query_pattern)
                {
                    srv_phb_mem_free(list_req->query_pattern);
                }
                srv_phb_mem_free(list_req);

                break;
            }

            case SRV_PHB_PBAPC_JOB_READ_ENTRY:
            {
                srv_phb_pbapc_read_entry_req_struct *entry_req = (srv_phb_pbapc_read_entry_req_struct *) job->para;

                srv_phb_mem_free(entry_req);

                break;
            }

            case SRV_PHB_PBAPC_JOB_READ_FOLDER:
            {
                srv_phb_pbapc_read_folder_req_struct *folder_req = (srv_phb_pbapc_read_folder_req_struct *) job->para;

                if (folder_req->folder_name)
                {
                    srv_phb_mem_free(folder_req->folder_name);
                }
                srv_phb_mem_free(folder_req);

                break;
            }

            default:
            {
                MMI_ASSERT(0);
                break;
            }
        }
    }

    memset(job, 0x00, sizeof(srv_phb_pbapc_job_struct));

    srv_cntx_p->job_mgr->used -= 1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_free_job
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
srv_phb_pbapc_job_struct *srv_phb_pbapc_get_free_job(U8 job_type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_job_struct *job = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job = srv_cntx_p->job_mgr->job;

    /* find free job */
    for (i = 0; i < SRV_PHB_PBAPC_MAX_HANDLE_NUM; ++i)
    {
        if ((job->flag & 0x01) == 0x00)
        {
            break;
        }

        job++;
    }

    srv_cntx_p->job_mgr->used += 1;
    /* fill job info */
    job->flag |= 0x01;
    job->job_state = SRV_PHB_PBAPC_STATE_PENDING;
    job->pid = srv_phb_pbapc_get_pid();

    switch (job_type)
    {
        case SRV_PHB_PBAPC_JOB_READ_FOLDER:
        {
            srv_phb_pbapc_read_folder_req_struct *req = NULL;    
            srv_phb_pbapc_read_folder_req_struct *folder_req = (srv_phb_pbapc_read_folder_req_struct *)para;
            srv_phb_pbapc_handle_struct *hd = (srv_phb_pbapc_handle_struct *)folder_req->handle;
            job->job_type = SRV_PHB_PBAPC_JOB_READ_FOLDER;
            job->hd_index = hd->index;

            /* malloc mem */
            req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_folder_req_struct), SRV_PHB_MEMORY_TYPE_CTR);
            memcpy(req, folder_req, sizeof(srv_phb_pbapc_read_folder_req_struct));
            if (folder_req->folder_name)
            {
                req->folder_name = srv_phb_mem_malloc(sizeof(U16) * (SRV_PHB_PBAPC_MAX_PATH_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
                memcpy(req->folder_name, folder_req->folder_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
                req->folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
            }
            else
            {
                req->folder_name = NULL;
            }

            job->para = (void *)req;
            job->user_data = folder_req->user_data;
            job->bt_index = folder_req->bt_index;

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_LIST:
        {
            srv_phb_pbapc_read_list_req_struct *req = NULL;    
            srv_phb_pbapc_read_list_req_struct *list_req = (srv_phb_pbapc_read_list_req_struct *)para;
            srv_phb_pbapc_handle_struct *hd = (srv_phb_pbapc_handle_struct *)list_req->handle;
            job->job_type = SRV_PHB_PBAPC_JOB_READ_LIST;
            job->hd_index = hd->index;

            /* malloc mem */
            req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_list_req_struct), SRV_PHB_MEMORY_TYPE_CTR);
            memcpy(req, list_req, sizeof(srv_phb_pbapc_read_list_req_struct));
            if (list_req->folder_name)
            {
                req->folder_name = srv_phb_mem_malloc(sizeof(U16) * (SRV_PHB_PBAPC_MAX_PATH_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
                memcpy(req->folder_name, list_req->folder_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
                req->folder_name[SRV_PHB_PBAPC_MAX_PATH_LEN] = L'\0';
            }
            else
            {
                req->folder_name = NULL;
            }

            if (list_req->query_pattern)
            {
                req->query_pattern = srv_phb_mem_malloc(sizeof(U8) * (SRV_PHB_PBAPC_MAX_QUERY_LEN + 1), SRV_PHB_MEMORY_TYPE_CTR);
                memcpy(req->query_pattern, list_req->query_pattern, SRV_PHB_PBAPC_MAX_QUERY_LEN);
                req->query_pattern[SRV_PHB_PBAPC_MAX_QUERY_LEN] = '\0';
            }
            else
            {
                req->query_pattern = NULL;
            }

            job->para = (void *)req;
            job->user_data = list_req->user_data;
            job->bt_index = list_req->bt_index;

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_ENTRY:
        {
            srv_phb_pbapc_read_entry_req_struct *req = NULL;    
            srv_phb_pbapc_read_entry_req_struct *etnry_req = (srv_phb_pbapc_read_entry_req_struct *)para;
            srv_phb_pbapc_handle_struct *hd = (srv_phb_pbapc_handle_struct *)etnry_req->handle;
            job->job_type = SRV_PHB_PBAPC_JOB_READ_ENTRY;
            job->hd_index = hd->index;

            /* malloc mem */
            req = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_read_entry_req_struct), SRV_PHB_MEMORY_TYPE_CTR);
            memcpy(req, etnry_req, sizeof(srv_phb_pbapc_read_entry_req_struct));

            job->para = (void *)req;
            job->user_data = etnry_req->user_data;
            job->bt_index = etnry_req->bt_index;

            break;
        }

        default:
        {
            MMI_ASSERT(0);

            break;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_FREE_JOB,
                    job->job_type, job->bt_index, job->hd_index);

    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_pid
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_get_pid()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();                                      
    if (SRV_PHB_PBAPC_MAX_PID == srv_cntx_p->pid)
    {
        /* reset pid */
        srv_cntx_p->pid = 0;
    }

    srv_cntx_p->pid += 1;

    return srv_cntx_p->pid;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_get_next_job
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static srv_phb_pbapc_job_struct *srv_phb_pbapc_get_next_job()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_job_mgr_struct *job_mgr = NULL;
    srv_phb_pbapc_job_struct *job = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    job_mgr = srv_cntx_p->job_mgr;

    job = &(job_mgr->job[0]);

    /* return next process job */
    for (i = 0; i < SRV_PHB_PBAPC_MAX_JOB_NUM; ++i)
    {
        if (((job_mgr->job[i].flag & 0x01) == 0x01) &&
            (job_mgr->job[i].job_state == SRV_PHB_PBAPC_STATE_PENDING))
        {
            job = &(job_mgr->job[i]);

            break;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_GET_NEXT_JOB,
                    i, job->pid, job->job_type, job->bt_index, job->hd_index);

    return job;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_async_process
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_async_process()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_phb_async_event_interface(srv_phb_pbapc_job_continue_hdlr, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_job_continue_hdlr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_job_continue_hdlr(void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p = srv_phb_pbapc_get_cntx();

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_JOB_CONTINUE_HDLR,
                    srv_cntx_p->job, srv_phb_pbapc_get_job_used());

    /* can process next job */
    if (NULL == srv_cntx_p->job && srv_phb_pbapc_get_job_used() != 0)
    {
        job = srv_phb_pbapc_get_next_job();

        if (job)
        {
            srv_cntx_p->job = job;
            job->job_state = SRV_PHB_PBAPC_STATE_RUNNING;
            srv_phb_pbapc_job_process(job);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_job_process
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_job_process(srv_phb_pbapc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (job->job_type)
    {
        case SRV_PHB_PBAPC_JOB_READ_LIST:
        {
            srv_phb_pbapc_job_list(job);

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_FOLDER:
        {
            srv_phb_pbapc_job_folder(job);

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_ENTRY:
        {
            srv_phb_pbapc_job_entry(job);

            break;
        }

        default:
        {
            break;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_job_folder
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_job_folder(srv_phb_pbapc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_btd_struct *btd = NULL;
    srv_phb_pbapc_read_folder_req_struct *req = (srv_phb_pbapc_read_folder_req_struct *)job->para;
    S32 index;
    S32 ret = SRV_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = req->bt_index;
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    btd = &(srv_cntx_p->btd_mgr->btd[index]);

    /* 1st: don't set path */
    if (MMI_TRUE)
    //if (btd->cur_path == req->storage)
    {
        srv_pbapc_read_folder_req_struct folder_req;
        U16 file_name[SRV_PHB_PBAPC_MAX_PATH_LEN + 1];

        folder_req.format = req->vcard_format;
        /* get vcard filter */
        srv_phb_pbapc_get_vcard_filter(&folder_req.filter, req->vcard_filter);
        folder_req.count = req->list_count;
        folder_req.offset = req->list_offset;
        srv_phb_pbapc_get_file_name(req->storage, file_name, SRV_PHB_PBAPC_MAX_PATH_LEN);

        /* 2nd: pb.vcf */
        //srv_phb_pbapc_get_folder_name(req->storage, file_name, SRV_PHB_PBAPC_MAX_PATH_LEN);
        //mmi_wcscat((WCHAR *)file_name, (WCHAR *)L".vcf");

        /* 3rd: pass NULL */
        //folder_req.name = NULL;

        folder_req.name = file_name;
        /* multi link */
        folder_req.bt_index = index;

        //kal_wap_trace(MOD_MMI_COMMON_APP, SRV_PHB_PBAP_TRACE_GROUP, "[SrvPhb][PBAPC]job_folder--storage: %d, name: %s, count: %d\n",
        //            req->storage, folder_req.name, folder_req.count);

        ret = srv_pbapc_read_folder_req(&folder_req);

        if (SRV_PBAPC_RET_OK != ret)
        {
            srv_phb_pbapc_err_handler(job, SRV_PHB_PBAPC_RET_FAIL);
        }
    }
    else
    {
        srv_pbapc_set_path_req_struct path_req;

        path_req.folder_type = PBAP_FORWARD_FOLDER;
        path_req.path = srv_phb_pbapc_get_path_enum(req->storage);
        btd->want_path = req->storage;
        /* multi link */
        path_req.bt_index = index;

        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_JOB_FOLDER, req->storage, path_req.path);

        ret = srv_pbapc_set_path_req(&path_req);

        /* handing loading stuck case */
        if (SRV_PBAPC_RET_OK != ret)
        {
            srv_phb_pbapc_err_handler(job, SRV_PHB_PBAPC_RET_FAIL);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_job_list
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_job_list(srv_phb_pbapc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_btd_struct *btd = NULL;
    srv_phb_pbapc_read_list_req_struct *req = (srv_phb_pbapc_read_list_req_struct *)job->para;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = req->bt_index;
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    btd = &(srv_cntx_p->btd_mgr->btd[index]);

    if (btd->cur_path == req->storage)
    {
        srv_pbapc_read_list_req_struct list_req;

        list_req.order = req->order;
        list_req.length = req->query_length;
        list_req.attribute = req->query_attr;
        list_req.count = req->query_count;
        list_req.offset = req->query_offset;
        list_req.name = req->folder_name;
        list_req.value = req->query_pattern;

        /* multi link */
        list_req.bt_index = index;

        srv_pbapc_read_list_req(&list_req);
    }
    else
    {
        srv_pbapc_set_path_req_struct path_req;

        path_req.folder_type = PBAP_FORWARD_FOLDER;
        path_req.path = srv_phb_pbapc_get_path_enum(req->storage);
        btd->want_path = req->storage;
        /* multi link */
        path_req.bt_index = index;

        srv_pbapc_set_path_req(&path_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_job_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_job_entry(srv_phb_pbapc_job_struct *job)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;
    srv_phb_pbapc_btd_struct *btd = NULL;
    srv_phb_pbapc_read_entry_req_struct *req = (srv_phb_pbapc_read_entry_req_struct *)job->para;
    S32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    index = req->bt_index;
    srv_cntx_p = srv_phb_pbapc_get_cntx();
    btd = &(srv_cntx_p->btd_mgr->btd[index]);

    if (btd->cur_path == req->storage)
    {
        srv_pbapc_read_entry_req_struct entry_req;
        U16 obj_name[SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN + 1];

        /* get index obj name */
        srv_phb_pbapc_get_obj_name(req->entry_index, obj_name, SRV_PHB_PBAPC_MAX_OBJ_NAME_LEN);
        /* get vcard filter */
        srv_phb_pbapc_get_vcard_filter(&entry_req.filter, req->vcard_filter);

        entry_req.format = req->vcard_format;
        entry_req.name = obj_name;

        /* multi link */
        entry_req.bt_index = index;

        srv_pbapc_read_entry_req(&entry_req);
    }
    else
    {
        srv_pbapc_set_path_req_struct path_req;

        path_req.folder_type = PBAP_FORWARD_FOLDER;
        path_req.path = srv_phb_pbapc_get_path_enum(req->storage);
        btd->want_path = req->storage;
        /* multi link */
        path_req.bt_index = index;

        srv_pbapc_set_path_req(&path_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_err_handler
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_phb_pbapc_err_handler(srv_phb_pbapc_job_struct *job, S32 ret)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_cntx_struct *srv_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_ERR_HANDLER, job->job_type, ret);

    srv_cntx_p = srv_phb_pbapc_get_cntx();

    switch (job->job_type)
    {
        case SRV_PHB_PBAPC_JOB_READ_LIST:
        {
            srv_phb_pbapc_read_list_rsp_struct list_rsp;
            srv_phb_pbapc_read_pse_list_cb func_cb = NULL;
            void *user_data = NULL;
            srv_phb_pbapc_read_list_req_struct *list_req = (srv_phb_pbapc_read_list_req_struct *)job->para;

            func_cb = (srv_phb_pbapc_read_pse_list_cb) job->func_cb;
            user_data = job->user_data;

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

            /* free job */
            job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
            srv_phb_pbapc_free_job(job);
            srv_cntx_p->job = NULL;

            /* send msg to drive job flow */
            srv_phb_pbapc_async_process();

            /* callback app */
            memset(&list_rsp, 0x00, sizeof(srv_phb_pbapc_read_list_rsp_struct));
            list_rsp.ret = ret;
            func_cb(&list_rsp, user_data);

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_FOLDER:
        {
            srv_phb_pbapc_read_folder_rsp_struct folder_rsp;
            srv_phb_pbapc_read_pse_folder_cb func_cb = NULL;
            void *user_data = NULL;
            srv_phb_pbapc_read_folder_req_struct *folder_req = (srv_phb_pbapc_read_folder_req_struct *)job->para;

            /* free job */
            func_cb = (srv_phb_pbapc_read_pse_folder_cb) job->func_cb;
            user_data = job->user_data;
            #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif

            /* free job */
            job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
            srv_phb_pbapc_free_job(job);
            srv_cntx_p->job = NULL;

            /* send msg to drive job flow */
            srv_phb_pbapc_async_process();

            /* callback app */
            memset(&folder_rsp, 0x00, sizeof(srv_phb_pbapc_read_folder_rsp_struct));
            folder_rsp.ret = ret;
            func_cb(&folder_rsp, user_data);

            break;
        }

        case SRV_PHB_PBAPC_JOB_READ_ENTRY:
        {
            srv_phb_pbapc_read_entry_rsp_struct entry_rsp;
            srv_phb_pbapc_read_pse_entry_cb func_cb = NULL;
            void *user_data = NULL;
            srv_phb_pbapc_read_entry_req_struct *entry_req = (srv_phb_pbapc_read_entry_req_struct *)job->para;

            entry_req = (srv_phb_pbapc_read_entry_req_struct *)job->para;
            func_cb = (srv_phb_pbapc_read_pse_entry_cb) job->func_cb;
            user_data = job->user_data;

            #if 0
/* under construction !*/
            #endif

            /* free job */
            job->job_state = SRV_PHB_PBAPC_STATE_FINISH;
            srv_phb_pbapc_free_job(job);
            srv_cntx_p->job = NULL;

            /* send msg to drive job flow */
            srv_phb_pbapc_async_process();

            /* callback app */
            memset(&entry_rsp, 0x00, sizeof(srv_phb_pbapc_read_folder_rsp_struct));
            entry_rsp.ret = ret;
            func_cb(&entry_rsp, user_data);

            break;
        }

        default:
        {
            break;
        }
    }
}


#define SRV_PHB_PBAPC_EXTERN_API

/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_create_handle_int
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
SRV_PHB_PBAPC_HANDLE srv_phb_pbapc_create_handle_int(S32 *result, const char* file, int line)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_handle_struct *hd = NULL;
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_phb_pbapc_check_para(SRV_PHB_PBAPC_JOB_CREATE_HANDLE, NULL);

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        hd = srv_phb_pbapc_get_free_hd();

        /* debug info */
        hd->line = line;
        strncpy(hd->file, file, 63);
        hd->file[63] = '\0';
    }

    *result = ret;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CREATE_HANDLE_INT, ret);

    return hd;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_destory_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_destory_handle(SRV_PHB_PBAPC_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_phb_pbapc_check_para(SRV_PHB_PBAPC_JOB_DESTORY_HANDLE, handle);

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        /* cancel job */
        srv_phb_pbapc_cancel_job(handle);

        /* reset hd */
        srv_phb_pbapc_free_handle(handle);
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_DESTORY_HANDLE, ret);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_list
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_list(srv_phb_pbapc_read_list_req_struct *list_req, srv_phb_pbapc_read_pse_list_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    srv_phb_pbapc_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_phb_pbapc_check_para(SRV_PHB_PBAPC_JOB_READ_LIST, list_req);

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        /* get free job */
        job = srv_phb_pbapc_get_free_job(SRV_PHB_PBAPC_JOB_READ_LIST, list_req);

        job->func_cb = (void *)cb_func;
        /* send msg, process next job */
        srv_phb_pbapc_async_process();
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_PSE_LIST, ret, cb_func);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_entry
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_entry(srv_phb_pbapc_read_entry_req_struct *entry_req, srv_phb_pbapc_read_pse_entry_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    srv_phb_pbapc_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_phb_pbapc_check_para(SRV_PHB_PBAPC_JOB_READ_ENTRY, entry_req);

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        /* get free job */
        job = srv_phb_pbapc_get_free_job(SRV_PHB_PBAPC_JOB_READ_ENTRY, entry_req);

        job->func_cb = (void *)cb_func;
        /* send msg, process next job */
        srv_phb_pbapc_async_process();
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_PSE_ENTRY, ret, cb_func);

    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_read_pse_folder
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_read_pse_folder(srv_phb_pbapc_read_folder_req_struct *folder_req, srv_phb_pbapc_read_pse_folder_cb cb_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    srv_phb_pbapc_job_struct *job = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_phb_pbapc_check_para(SRV_PHB_PBAPC_JOB_READ_FOLDER, folder_req);

    if (SRV_PHB_PBAPC_RET_OK == ret)
    {
        /* get free job */
        job = srv_phb_pbapc_get_free_job(SRV_PHB_PBAPC_JOB_READ_FOLDER, folder_req);

        job->func_cb = (void *)cb_func;
        /* send msg, process next job */
        srv_phb_pbapc_async_process();
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_READ_PSE_FOLDER, ret, cb_func);

    return ret;
}



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
S32 srv_phb_pbapc_get_btd_addr(srv_bt_cm_bt_addr *bt_addr, U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_pbapc_get_btd_addr(bt_addr, bt_index);

    return ret;
}


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
S32 srv_phb_pbapc_get_btd_index(srv_bt_cm_bt_addr *bt_addr, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_pbapc_get_btd_index(bt_addr, flag);

    return ret;
}


/* test through inject string */
U8 srv_phb_pbapc_proc_inject_string(U8 index, kal_uint8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return 0;
}


#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__)

#include "vcard_lib.h"

#define SRV_PHB_SORT_LENGTH                     (10)

typedef struct
{
    U16 word[SRV_PHB_PBAPC_CONTACT_COUNT];           /* first word */
    U16 input_mode;                            /* input mode */
} srv_phb_pbapc_qsearch_cache_struct;

typedef struct
{
    U16 ori_char;                               /* original char */
    U16 convert[MMI_PHB_QSEARCH_LENGTH];        /* converted string */
    U16 len;
} srv_phb_pbapc_qsearch_convert_struct;

typedef struct
{
    U8 job;         /* 0: init; 1: read phone count; 2: read sim count; 3: read phone folder; 4: read sim folder; */
    U8 op_stop;
    U16 pse_count;
    U16 phone_count; /* valid count */
    U16 sim_count;
    U16 phone_total; /* may not the real count */
    U16 sim_total;
    U16 phone_time;
    U16 sim_time;
    SRV_PHB_PBAPC_HANDLE handle;
    VP_HANDLE p_handle;
    srv_phb_pbapc_load_contact_cb cb_func;
    void *user_data;
    U16 entry_count;
    mmi_phb_contact_id name_index[SRV_PHB_PBAPC_CONTACT_COUNT];
#if defined(__MMI_PHB_PINYIN_SORT__)
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    U16 pinyin_cache[SRV_PHB_PBAPC_NAME_ORDER_TOTAL][SRV_PHB_PBAPC_CONTACT_COUNT][(SRV_PHB_SORT_LENGTH + 1)];
#else
    U16 pinyin_cache[SRV_PHB_PBAPC_CONTACT_COUNT][(SRV_PHB_SORT_LENGTH + 1)];
#endif
#endif
#if defined(__MMI_PHB_QUICK_SEARCH__)
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    srv_phb_pbapc_qsearch_cache_struct *q_cache[SRV_PHB_PBAPC_NAME_ORDER_TOTAL];
#else
    srv_phb_pbapc_qsearch_cache_struct *q_cache;
#endif
#endif
    srv_phb_lookup_number_node_struct number_node[SRV_PHB_PBAPC_CONTACT_COUNT * SRV_PHB_PBAPC_NUMBER_COUNT];
    MMI_BOOL number_ready;
    U16 number_count;
} srv_phb_pbapc_load_contact_cntx_struct;

static srv_phb_pbapc_load_contact_cntx_struct g_srv_phb_pbapc_load_contact_cntx[SRV_PBAPC_LINK_NUM];

static srv_phb_pbapc_contact_struct g_srv_phb_pbapc_contact[SRV_PBAPC_LINK_NUM][SRV_PHB_PBAPC_CONTACT_COUNT];

/* function */
static S32 srv_phb_pbapc_check_continue(srv_phb_pbapc_btd_enum bt_index);

static S32 srv_phb_pbapc_remove_sp_char(U16 *number);

static S32 srv_phb_pbapc_push_contact(vcard_object_struct *vcard_object, srv_phb_pbapc_contact_struct *pse_phb);

static void srv_phb_pbapc_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data);

static void srv_phb_pbapc_parse(srv_phb_pbapc_btd_enum bt_index, U16 *path);

static S32 srv_phb_pbapc_read_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

static void srv_phb_pbapc_job_hdlr(srv_phb_pbapc_btd_enum bt_index);

static void srv_phb_pbapc_notify_app(srv_phb_pbapc_btd_enum bt_index, MMI_BOOL disconn);

static void srv_phb_pbapc_populate_name_index(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id);

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
static void srv_phb_pbapc_make_pinyin_cache(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, srv_phb_pbapc_name_struct *name);
#else
static void srv_phb_pbapc_make_pinyin_cache(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, U16 *name);
#endif

static void srv_phb_pbapc_build_name_index(srv_phb_pbapc_btd_enum bt_index);

static void srv_phb_pbapc_populate_number(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, CHAR* number);

static void srv_phb_pbapc_build_lookup_table(srv_phb_pbapc_btd_enum bt_index);

static S32 srv_phb_pbapc_check_continue(srv_phb_pbapc_btd_enum bt_index)
{
    S32 ret = 0;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    if (srv_cntx_p->p_handle != NULL)
    {
        vcard_close_parser(srv_cntx_p->p_handle);
        srv_cntx_p->p_handle = NULL;

        FS_Delete(srv_phb_pbapc_file_name[bt_index]);
    }

    if (srv_cntx_p->job == 3)
    {
        if (srv_cntx_p->phone_time * SRV_PHB_PBAPC_FOLDER_SIZE < srv_cntx_p->phone_total)
        {
            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else
        {
        #ifdef SRV_PHB_PBAPC_READ_PHONE_ONLY
            srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
        #else
            srv_cntx_p->job = 4;
            srv_phb_pbapc_check_continue(bt_index);
        #endif
        }
    }
    else if (srv_cntx_p->job == 4)
    {
        if (srv_cntx_p->sim_time * SRV_PHB_PBAPC_FOLDER_SIZE < srv_cntx_p->sim_total)
        {
            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else
        {
            srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
        }
    }
#if !defined(__MTK_TARGET__)
    else if (srv_cntx_p->job == 0x7f)
    {
        srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
    }
#endif /* !defined(__MTK_TARGET__) */
    else
    {
        MMI_ASSERT(0);
    }

    return ret;
}


static S32 srv_phb_pbapc_remove_sp_char(U16 *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 len = 0, i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < MMI_PHB_NUMBER_LENGTH && number[i] != L'\0'; ++i)
    {
        if (number[i] == L'-') // filter char '-'
        {
            continue;
        }

        if (number[i] == L'(' || number[i] == L')') // filter char '()'
        {
            continue;
        }

        if (number[i] == L' ') // filter space
        {
            continue;
        }
        number[len++] = number[i];
    }
    number[len] = L'\0';

    return len;
}


static S32 srv_phb_pbapc_push_contact(vcard_object_struct *vcard_object, srv_phb_pbapc_contact_struct *pse_phb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, index = 0;
    U32 field_mask = 0;
    U16 temp_name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = { L'\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pse_phb, 0x00, sizeof(srv_phb_pbapc_contact_struct));

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    if (vcard_object->n.family && vcard_object->n.family[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        mmi_wcsncpy(pse_phb->name.family, vcard_object->n.family, SRV_PHB_PBAPC_FAMILY_NAME_LENGTH);
        pse_phb->name.family[SRV_PHB_PBAPC_FAMILY_NAME_LENGTH] = L'\0';
    }
    if (vcard_object->n.given && vcard_object->n.given[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.given);
        mmi_wcsncpy(pse_phb->name.given, vcard_object->n.given, SRV_PHB_PBAPC_GIVEN_NAME_LENGTH);
        pse_phb->name.given[SRV_PHB_PBAPC_GIVEN_NAME_LENGTH] = L'\0';
    }
    if (vcard_object->n.mid && vcard_object->n.mid[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.mid);
        mmi_wcsncpy(pse_phb->name.mid, vcard_object->n.mid, SRV_PHB_PBAPC_MID_NAME_LENGTH);
        pse_phb->name.mid[SRV_PHB_PBAPC_MID_NAME_LENGTH] = L'\0';
    }

    if (pse_phb->name.family[0] || pse_phb->name.given[0] || pse_phb->name.mid[0])
    {
        field_mask |= 0x01;
    }
#else
    if (vcard_object->n.mid && vcard_object->n.mid[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.mid);
        srv_phb_remove_invalid_name(vcard_object->n.given);

        mmi_wcsncpy((WCHAR *)temp_name, vcard_object->n.mid, SRV_PHB_PBAPC_NAME_LENGTH);
        mmi_wcsncat((WCHAR *)(temp_name + mmi_wcslen(temp_name)), vcard_object->n.given, SRV_PHB_PBAPC_NAME_LENGTH - mmi_wcslen(temp_name));

        srv_phb_convert_to_name(
                pse_phb->name,
                temp_name,
                vcard_object->n.family,
                SRV_PHB_PBAPC_NAME_LENGTH);
    }
    else
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.given);
        srv_phb_convert_to_name(
                        pse_phb->name,
                        vcard_object->n.given,
                        vcard_object->n.family,
                        SRV_PHB_PBAPC_NAME_LENGTH);
    }

    if (pse_phb->name[0])
    {
        field_mask |= 0x01;
    }
#endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */

    for (i = 0; i < VCARD_MAX_TEL_COUNT; ++i)
    {
        if (pse_phb->num_count < SRV_PHB_PBAPC_NUMBER_COUNT && vcard_object->tel[i].tel && vcard_object->tel[i].tel[0])
        {
            srv_phb_pbapc_remove_sp_char(vcard_object->tel[i].tel);
            srv_phb_remove_invalid_number(vcard_object->tel[i].tel);

            if (vcard_object->tel[i].tel[0])
            {
                index = pse_phb->num_count;
                mmi_wcs_n_to_asc(pse_phb->number[index].number, vcard_object->tel[i].tel, SRV_PHB_PBAPC_NUMBER_LENGTH * 2);
                pse_phb->number[index].type = vcard_object->tel[i].type;

                ++pse_phb->num_count;
                field_mask |= 0x02;
            }
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PUSH_CONTACT, field_mask, pse_phb->num_count);

    return field_mask;
}


void srv_phb_pbapc_update_sync_status(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_sync_status_evt_struct evt;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_UPDATE_SYNC_STATUS, srv_cntx_p->pse_count, srv_cntx_p->phone_total, srv_cntx_p->sim_total);
    if (srv_cntx_p->op_stop == MMI_FALSE)
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_PBAPC_SYNC_STATUS_UPDATE);
        evt.bt_index = bt_index;
        evt.sync_count = srv_cntx_p->pse_count;
        evt.total_count = srv_cntx_p->phone_total + srv_cntx_p->sim_total;
        MMI_FRM_CB_EMIT_EVENT(&evt);
    }
}


static void srv_phb_pbapc_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) user_data;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    S32 ret = 0;
    U8 num_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
        return;
    }

    if (percentage <= 100 && error_code == VCARD_NO_ERROR)
    {
        if (srv_phb_vcard_is_valid_contact(object) && srv_cntx_p->pse_count < SRV_PHB_PBAPC_CONTACT_COUNT)
        {
            pse_phb = &(g_srv_phb_pbapc_contact[bt_index][srv_cntx_p->pse_count]);
            ret = srv_phb_pbapc_push_contact(object, pse_phb);

            if (ret)
            {
            #if defined(__MMI_PHB_PINYIN_SORT__)
            #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
                srv_phb_pbapc_make_pinyin_cache(bt_index, srv_cntx_p->pse_count, &(pse_phb->name));
            #else
                srv_phb_pbapc_make_pinyin_cache(bt_index, srv_cntx_p->pse_count, pse_phb->name);
            #endif
            #endif
                srv_phb_pbapc_populate_name_index(bt_index, srv_cntx_p->pse_count);
                for (num_index = 0; num_index < pse_phb->num_count; num_index++)
                {
                    srv_phb_pbapc_populate_number(bt_index, srv_cntx_p->pse_count, (CHAR*)pse_phb->number[num_index].number);
                }
                srv_cntx_p->pse_count++;

                if (srv_cntx_p->job == 3)
                {
                    srv_cntx_p->phone_count++;
                    pse_phb->storage = PHB_STORAGE_NVRAM;
                }
                else if (srv_cntx_p->job == 4)
                {
                    srv_cntx_p->sim_count++;
                    pse_phb->storage = PHB_STORAGE_SIM;
                }
            #if !defined(__MTK_TARGET__)
                else if (srv_cntx_p->job == 0x7f)
                {
                    if (srv_cntx_p->pse_count > 1)
                    {
                        srv_cntx_p->phone_count = 1;
                        srv_cntx_p->sim_count = srv_cntx_p->pse_count - 1;
                        pse_phb->storage = PHB_STORAGE_SIM;
                    }
                    else
                    {
                        srv_cntx_p->phone_count = srv_cntx_p->pse_count;
                        srv_cntx_p->sim_count = 0;
                        pse_phb->storage = PHB_STORAGE_NVRAM;
                    }
                }
            #endif /* !defined(__MTK_TARGET__) */
                else
                {
                    MMI_ASSERT(0);
                }
            }

            srv_phb_pbapc_update_sync_status(bt_index);
        }

        if (percentage == 100 || srv_cntx_p->pse_count == SRV_PHB_PBAPC_CONTACT_COUNT)
        {
            srv_phb_pbapc_check_continue(bt_index);
        }
        else
        {
            vcard_multi_parse(srv_cntx_p->p_handle, srv_phb_pbapc_parse_cb, (void*)bt_index);
        }

        return;
    }

    srv_phb_pbapc_check_continue(bt_index);
}


static void srv_phb_pbapc_parse(srv_phb_pbapc_btd_enum bt_index, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    U32 property = VCARD_PROPERTY_N | VCARD_PROPERTY_TEL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p->p_handle = vcard_open_parser(path, property, &ret);

    if (srv_cntx_p->p_handle)
    {
        srv_phb_pbapc_update_sync_status(bt_index);
        vcard_multi_parse(srv_cntx_p->p_handle, srv_phb_pbapc_parse_cb, (void*)bt_index);
    }
    else
    {
        srv_phb_pbapc_check_continue(bt_index);
    }
}


static void srv_phb_pbapc_copy_file(srv_phb_pbapc_btd_enum bt_index, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret1, ret2, ret3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret1 = ret2 = ret3 = -251;

    ret1 = srv_fmgr_fs_path_exist(SRV_PHB_PBAPC_WORK_FOLDER);

    if (ret1 < 0)
    {
       ret2 = srv_fmgr_fs_create_folder(SRV_PHB_PBAPC_WORK_FOLDER);
    }

    ret3 = FS_Move(path, srv_phb_pbapc_file_name[bt_index], FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, NULL);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CP_FILE, ret1, ret2, ret3);
}


static S32 srv_phb_pbapc_read_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) user_data;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_rsp->ret == SRV_PBAPC_RET_OK)
    {
        if (srv_cntx_p->job == 1)
        {
            srv_cntx_p->phone_total = folder_rsp->phb_size;
            if (srv_cntx_p->phone_total > SRV_PHB_PBAPC_CONTACT_COUNT)
            {
                srv_cntx_p->phone_total = SRV_PHB_PBAPC_CONTACT_COUNT + 1;
            }
            srv_cntx_p->job = 2;

            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 2)
        {
            srv_cntx_p->sim_total = folder_rsp->phb_size;
            if (srv_cntx_p->phone_total + srv_cntx_p->sim_total > SRV_PHB_PBAPC_CONTACT_COUNT)
            {
                srv_cntx_p->sim_total = SRV_PHB_PBAPC_CONTACT_COUNT + 2 - srv_cntx_p->phone_total;
            }
            srv_cntx_p->job = 3;

            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 3)
        {
            srv_phb_pbapc_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[bt_index]));
        }
        else if (srv_cntx_p->job == 4)
        {
            srv_phb_pbapc_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[bt_index]));
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        if (srv_cntx_p->job == 1)
        {
            srv_cntx_p->phone_total = 0;
            srv_cntx_p->job = 2;

            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 2)
        {
            srv_cntx_p->sim_total = 0;
            srv_cntx_p->job = 3;

            srv_phb_pbapc_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 3)
        {
            srv_cntx_p->job = 4;
            srv_phb_pbapc_check_continue(bt_index);
        }
        else if (srv_cntx_p->job == 4)
        {
            srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    return 0;
}


static void srv_phb_pbapc_job_hdlr(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cntx_p->job == 1)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL;
        folder_req.list_count = 0;
        folder_req.list_offset = 0;
    }
    else if (srv_cntx_p->job == 2)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_SIM1_PB;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL;
        folder_req.list_count = 0;
        folder_req.list_offset = 0;
    }
    else if (srv_cntx_p->job == 3)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL;
        folder_req.list_count = SRV_PHB_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->phone_time * SRV_PHB_PBAPC_FOLDER_SIZE;

        srv_cntx_p->phone_time += 1;
    }
    else if (srv_cntx_p->job == 4)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_SIM1_PB;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL;
        folder_req.list_count = SRV_PHB_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->sim_time * SRV_PHB_PBAPC_FOLDER_SIZE;

        srv_cntx_p->sim_time += 1;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
    }
    else
    {
        ret = srv_phb_pbapc_read_pse_folder(&folder_req, srv_phb_pbapc_read_cb);

        if (SRV_PHB_PBAPC_RET_DISCONNECTED == ret)
        {
            srv_phb_pbapc_notify_app(bt_index, MMI_TRUE);
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_JOB_HDLR,
                    srv_cntx_p->job, srv_cntx_p->phone_time, srv_cntx_p->sim_time);
}


static void srv_phb_pbapc_notify_app(srv_phb_pbapc_btd_enum bt_index, MMI_BOOL disconn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_rsp load_rsp;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_NOTI_APP, srv_cntx_p->op_stop, srv_cntx_p->phone_count, srv_cntx_p->sim_count);
    if (srv_cntx_p->handle != NULL)
    {
        srv_phb_pbapc_destory_handle(srv_cntx_p->handle);
        srv_cntx_p->handle = NULL;
    }

    if (srv_cntx_p->p_handle != NULL)
    {
        vcard_close_parser(srv_cntx_p->p_handle);
        srv_cntx_p->p_handle = NULL;

        FS_Delete(srv_phb_pbapc_file_name[bt_index]);
    }

    if (disconn == MMI_FALSE)
    {
        srv_phb_pbapc_build_name_index(bt_index);
        srv_phb_pbapc_build_lookup_table(bt_index);

        load_rsp.ret = SRV_PHB_PBAPC_RET_OK;
    }
    else
    {
    #ifdef __MMI_PHB_PBAPC_NO_CLEAR__
        if (srv_cntx_p->op_stop == MMI_FALSE) /* No need to sort again since it has been done when cancel */
        {
            srv_phb_pbapc_build_name_index(bt_index);
            srv_phb_pbapc_build_lookup_table(bt_index);
        }
    #else /* __MMI_PHB_PBAPC_NO_CLEAR__ */
        srv_cntx_p->pse_count = 0;
        srv_cntx_p->phone_count = 0;
        srv_cntx_p->sim_count = 0;
        srv_cntx_p->entry_count = 0;
    #endif /* __MMI_PHB_PBAPC_NO_CLEAR__ */

        load_rsp.ret = SRV_PHB_PBAPC_RET_FAIL;
    }

    load_rsp.bt_index = bt_index;

    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_cntx_p->op_stop = MMI_FALSE;
    }
    else if (srv_cntx_p->cb_func != NULL)
    {
        srv_cntx_p->cb_func(&load_rsp, srv_cntx_p->user_data);
    }
    srv_cntx_p->cb_func = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_load_contact
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_load_contact(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_load_contact_cb cb_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    SRV_PHB_PBAPC_HANDLE handle = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    U8 order = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_PHB_QUICK_SEARCH__)
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    order = SRV_PHB_PBAPC_NAME_ORDER_1;
    if (srv_cntx_p->q_cache[order] != NULL)
    {
        srv_phb_mem_free(srv_cntx_p->q_cache[order]);
        srv_cntx_p->q_cache[order] = NULL;
    }

    order = SRV_PHB_PBAPC_NAME_ORDER_2;
    if (srv_cntx_p->q_cache[order] != NULL)
    {
        srv_phb_mem_free(srv_cntx_p->q_cache[order]);
        srv_cntx_p->q_cache[order] = NULL;
    }
#else
    if (srv_cntx_p->q_cache != NULL)
    {
        srv_phb_mem_free(srv_cntx_p->q_cache);
        srv_cntx_p->q_cache = NULL;
    }
#endif
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */

#if !defined(__MTK_TARGET__)
    /* reset */
    memset(srv_cntx_p, 0x00, sizeof(srv_phb_pbapc_load_contact_cntx_struct));
    srv_cntx_p->handle = handle;
    srv_cntx_p->job = 0x7f;
    srv_cntx_p->cb_func = cb_func;
    srv_cntx_p->user_data = user_data;

    // To simulate IOT issue, we set phone_total != phone_count
    srv_cntx_p->phone_total = 1;
    srv_cntx_p->sim_total = 3;

    srv_phb_pbapc_parse(bt_index, L"E:\\test.vcf");

    return 0;
#endif /* !defined(__MTK_TARGET__) */

    if (srv_cntx_p->op_stop == MMI_TRUE || srv_cntx_p->cb_func != NULL)
    {
        ret = SRV_PHB_PBAPC_RET_BUSY;
    }
    else
    {
        handle = srv_phb_pbapc_create_handle(&ret);

        if (ret == SRV_PHB_PBAPC_RET_OK)
        {
            /* reset */
            memset(srv_cntx_p, 0x00, sizeof(srv_phb_pbapc_load_contact_cntx_struct));
            srv_cntx_p->handle = handle;
            srv_cntx_p->job = 1;
            srv_cntx_p->cb_func = cb_func;
            srv_cntx_p->user_data = user_data;

            srv_phb_pbapc_job_hdlr(bt_index);
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_LOAD_CONTACT, ret);

    return ret;
}


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
void srv_phb_pbapc_load_contact_cancel(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_LD_CANCEL);
    srv_cntx_p->op_stop = MMI_TRUE;
    srv_phb_pbapc_notify_app(bt_index, MMI_FALSE);
#if 0
#ifdef __MMI_PHB_PBAPC_NO_CLEAR__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHB_PBAPC_NO_CLEAR__ */
#endif
}


static void srv_phb_pbapc_populate_name_index(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p->name_index[srv_cntx_p->entry_count++] = id;
}


#if defined(__MMI_PHB_QUICK_SEARCH__)
static MMI_BOOL srv_phb_pbapc_qsearch_filter(srv_phb_pbapc_btd_enum bt_index, U16 store_index, srv_phb_qsearch_filter_struct* qsearch_filter, srv_phb_pbapc_qsearch_convert_struct* convert_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16* string;
    U16 name[SRV_PHB_PBAPC_NAME_LENGTH + 1];
    U16 convert_string[MMI_PHB_QSEARCH_LENGTH  + 1];
    U16 first_char[MMI_PHB_QSEARCH_LENGTH + 1];
    S32 i, j;
    U16 key_length = (qsearch_filter->key_len > MMI_PHB_QSEARCH_LENGTH ? MMI_PHB_QSEARCH_LENGTH : qsearch_filter->key_len);
    U16* keyword = qsearch_filter->key_word;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    U16 cache = 0;
    U16 left_len = key_length;
    U8 order = 0;
    U16 tmp_name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = {L'\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * search length == 1, compare whole list with first character only.
     */
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    order = srv_phb_pbapc_get_name_order(bt_index);
    cache = srv_cntx_p->q_cache[order]->word[store_index];
#else
    cache = srv_cntx_p->q_cache->word[store_index];
#endif

    if (key_length >= 1)
    {
        /* Compare character in cache first. If match, compare the rest part. */
        if (srv_phb_compare_wchar(cache, keyword[0]) == 0)
        {
        #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
            srv_phb_pbapc_convert_name(&(g_srv_phb_pbapc_contact[bt_index][store_index].name), tmp_name, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);
            mmi_wcsncpy(name, tmp_name, SRV_PHB_PBAPC_NAME_LENGTH);
        #else
            mmi_wcsncpy(name, g_srv_phb_pbapc_contact[bt_index][store_index].name, SRV_PHB_PBAPC_NAME_LENGTH);
        #endif
            name[SRV_PHB_PBAPC_NAME_LENGTH] = 0;
            if (srv_phb_check_ucs2_character(name))
            {
                string = convert_string;
                for (i = 0; i < key_length && name[i]; i++)
                {
                    if (name[i] != convert_buffer[i].ori_char)
                    {
                        convert_buffer[i].ori_char = name[i];
                        convert_buffer[i].len = srv_phb_convert_to_spelling(
                                                    qsearch_filter->input_mode,
                                                    name[i],
                                                    convert_buffer[i].convert,
                                                    MMI_PHB_QSEARCH_LENGTH);
                    }
                    for (j = 0; left_len > 0 && j < convert_buffer[i].len;j++)
                    {
                        *string++ = convert_buffer[i].convert[j];
                        left_len--;
                    }
                    first_char[i] = convert_buffer[i].convert[0];
                }
                first_char[i] = 0;
                *string = 0;
                string = convert_string;
            }
            else    /* ASCII */
            {
                string = name;
                srv_phb_convert_to_initial(name, first_char, key_length);
                string[key_length] = 0;
            }

            if (srv_phb_compare_ucs2_string(first_char, keyword) == 0)
            {
                return MMI_TRUE;
            }

            if (srv_phb_compare_ucs2_string(string, keyword) == 0)
            {
                return MMI_TRUE;
            }            
        }
    }
    /*
     *search length == 0, display whole list.
     */
    else
    {
        return MMI_TRUE;
    }        
    return MMI_FALSE;
}


static void srv_phb_pbapc_make_qsearch_cache(srv_phb_pbapc_btd_enum bt_index, U16* cache, U16 input_mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    U16 pre_name = 0;
    U16 pre_index = 0;
    U16 store_index;
    U16 name[2];
    U8 order = 0;
    U16 tmp_name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = {L'\0'};
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Begin to convert first character of name field to associated input method string. */
    for (i = 0; i < srv_cntx_p->entry_count; i++)
    {
        store_index = srv_cntx_p->name_index[i];

    #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
        order = srv_phb_pbapc_get_name_order(bt_index);
        srv_phb_pbapc_convert_name(&(g_srv_phb_pbapc_contact[bt_index][store_index].name), tmp_name, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);
        if (tmp_name[0])
        {
            name[0] = tmp_name[0];
            if (UI_TEST_UCS2_CHARACTER(name[0]))
            {
                if (i != 0)
                {
                    /* If character is the same, do not convert again. */
                    if (name[0] == pre_name)
                    {
                        cache[store_index] = cache[pre_index];
                        continue;
                    }
                }
        
                srv_phb_convert_to_spelling(input_mode, name[0], &cache[store_index], 1);
                pre_index = store_index;
                pre_name = name[0];
            }
            else
                /* This is an ASCII char */
            {
                cache[store_index] = name[0];
            }
        }
        /* The name field is Empty */
        else
        {
            cache[store_index] = 0;
        }
    #else
        if (g_srv_phb_pbapc_contact[bt_index][store_index].name[0])
        {
            name[0] = g_srv_phb_pbapc_contact[bt_index][store_index].name[0];
            if (UI_TEST_UCS2_CHARACTER(name[0]))
            {
                if (i != 0)
                {
                    /* If character is the same, do not convert again. */
                    if (name[0] == pre_name)
                    {
                        cache[store_index] = cache[pre_index];
                        continue;
                    }
                }

                srv_phb_convert_to_spelling(input_mode, name[0], &cache[store_index], 1);
                pre_index = store_index;
                pre_name = name[0];
            }
            else
                /* This is an ASCII char */
            {
                cache[store_index] = name[0];
            }
        }
        /* The name field is Empty */
        else
        {
            cache[store_index] = 0;
        }
    #endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */    
    }
}

#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
static void srv_phb_pbapc_make_pinyin_cache(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, srv_phb_pbapc_name_struct *name)
#else
static void srv_phb_pbapc_make_pinyin_cache(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, U16 *name)
#endif
{
#if defined(__MMI_PHB_PINYIN_SORT__)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 count;
    U16 str[SRV_PHB_PBAPC_NAME_LENGTH + 1] = {L'\0'};
    U8 order = 0;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    order = SRV_PHB_PBAPC_NAME_ORDER_1;
    srv_phb_pbapc_convert_name_ex(name, order, str, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);

    if (str && srv_phb_check_ucs2_character(str))
    {
        count = srv_phb_convert_to_pinyin(
                    str,
                    &srv_cntx_p->pinyin_cache[order][id][0],
                    SRV_PHB_SORT_LENGTH);
        srv_cntx_p->pinyin_cache[order][id][count++] = 0;
    }
    else
    {
        srv_cntx_p->pinyin_cache[order][id][0] = 0;
    }
    order = SRV_PHB_PBAPC_NAME_ORDER_2;
    srv_phb_pbapc_convert_name_ex(name, order, str, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);

    if (str && srv_phb_check_ucs2_character(str))
    {
        count = srv_phb_convert_to_pinyin(
                    str,
                    &srv_cntx_p->pinyin_cache[order][id][0],
                    SRV_PHB_SORT_LENGTH);
        srv_cntx_p->pinyin_cache[order][id][count++] = 0;
    }
    else
    {
        srv_cntx_p->pinyin_cache[order][id][0] = 0;
    }
#else
    if (name && srv_phb_check_ucs2_character(name))
    {
        count = srv_phb_convert_to_pinyin(
                    name,
                    &srv_cntx_p->pinyin_cache[id][0],
                    SRV_PHB_SORT_LENGTH);
        srv_cntx_p->pinyin_cache[id][count++] = 0;
    }
    else
    {
        srv_cntx_p->pinyin_cache[id][0] = 0;
    }
#endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */
#endif
}

#endif /* __MMI_PHB_QUICK_SEARCH__ */


static void srv_phb_pbapc_compare_name_index(srv_phb_pbapc_btd_enum bt_index, U16 first, U16 second, S32 *distance)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 buffer1[SRV_PHB_PBAPC_NAME_LENGTH + 1];
    U16 buffer2[SRV_PHB_PBAPC_NAME_LENGTH + 1];
    U16* string1;
    U16* string2;
    U8 order = 0;
    U16 name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = {L'\0'};
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    order = srv_phb_pbapc_get_name_order(bt_index);
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_cntx_p->pinyin_cache[order][first][0] != 0)
    {
        string1 = srv_cntx_p->pinyin_cache[order][first];
    }
    else
#endif
    {
        srv_phb_pbapc_convert_name(&(g_srv_phb_pbapc_contact[bt_index][first].name), name, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);
        mmi_wcsncpy(buffer1, name, SRV_PHB_PBAPC_NAME_LENGTH);
        buffer1[SRV_PHB_PBAPC_NAME_LENGTH] = 0;
        string1 = buffer1;
    }

#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_cntx_p->pinyin_cache[order][second][0] != 0)
    {
        string2 = srv_cntx_p->pinyin_cache[order][second];
    }
    else
#endif
    {
        srv_phb_pbapc_convert_name(&(g_srv_phb_pbapc_contact[bt_index][second].name), name, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);
        mmi_wcsncpy(buffer2, name, SRV_PHB_PBAPC_NAME_LENGTH);
        buffer2[SRV_PHB_PBAPC_NAME_LENGTH] = 0;
        string2 = buffer2;
    }
#else
#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_cntx_p->pinyin_cache[first][0] != 0)
    {
        string1 = srv_cntx_p->pinyin_cache[first];
    }
    else
#endif
    {
        mmi_wcsncpy(buffer1, g_srv_phb_pbapc_contact[bt_index][first].name, SRV_PHB_PBAPC_NAME_LENGTH);
        buffer1[SRV_PHB_PBAPC_NAME_LENGTH] = 0;
        string1 = buffer1;
    }

#if defined(__MMI_PHB_PINYIN_SORT__)
    if (srv_cntx_p->pinyin_cache[second][0] != 0)
    {
        string2 = srv_cntx_p->pinyin_cache[second];
    }
    else
#endif
    {
        mmi_wcsncpy(buffer2, g_srv_phb_pbapc_contact[bt_index][second].name, SRV_PHB_PBAPC_NAME_LENGTH);
        buffer2[SRV_PHB_PBAPC_NAME_LENGTH] = 0;
        string2 = buffer2;
    }
#endif

#ifndef __MMI_PHB_EMPTY_NAME_TOP__
    /* if name empty */
    if (!string1[0])
    {
        string1[0] = 0x7B;
        string1[1] = 0;
    }

    /* if name empty */
    if (!string2[0])
    {
        string2[0] = 0x7B;
        string2[1] = 0;
    }
#endif

    /* Compare two strings */
#if defined(__MMI_PHB_PINYIN_SORT__)
    //*distance = srv_phb_compare_pinyin_string(string1, string2);
    *distance = srv_phb_compare_ucs2_string(string1, string2);
#else
    *distance = srv_phb_compare_ucs2_string(string1, string2);
#endif
    if (*distance == 0)
    {
        *distance = mmi_wcscmp(string1, string2);
    }

    /* sort according storage location, let entry in NVRAM put before in SIM. (store_index can decide store location) */
    if (*distance == 0)
    {
        if (first < second)
        {
            *distance = -1;
        }
        else if (first > second)
        {
            *distance = 1;
        }
    }
}


static void srv_phb_pbapc_name_swap(srv_phb_pbapc_btd_enum bt_index, U16 a, U16 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = srv_cntx_p->name_index[a];
    srv_cntx_p->name_index[a] = srv_cntx_p->name_index[b];
    srv_cntx_p->name_index[b] = temp;
}


static void srv_phb_pbapc_name_quicksort(srv_phb_pbapc_btd_enum bt_index, U16 left, U16 right)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 const Min = 4;  /* Lower bound to sort */
    U16 i;
    U16 j;
    U16 pivot;
    S32 distance;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((right - left) > Min)
    {
        i = (right + left) / 2;

        /* left > mid */
        srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[left], srv_cntx_p->name_index[i], &distance);
        if (distance > 0)
        {
            srv_phb_pbapc_name_swap(bt_index, left, i);
        }

        /* left > right */
        srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[left], srv_cntx_p->name_index[right], &distance);
        if (distance > 0)
        {
            srv_phb_pbapc_name_swap(bt_index, left, right);
        }

        /* mid > right */
        srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[i], srv_cntx_p->name_index[right], &distance);
        if (distance > 0)
        {
            srv_phb_pbapc_name_swap(bt_index, i, right);
        }

        j = right - 1;
        srv_phb_pbapc_name_swap(bt_index, i, j);

        i = left;

        pivot = srv_cntx_p->name_index[j];    /* kal_mem_cpy(&v, (void const*)&a[j], sizeof(pindex_struct)); */

        for (;;)
        {
            do  /* ++i < pivot */
            {
                srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[++i], pivot, &distance);
            }
            while (distance < 0);

            do  /* --j > pivot */
            {
                srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[--j], pivot, &distance);
            }
            while (distance > 0);

            if (j < i)
            {
                break;
            }

            srv_phb_pbapc_name_swap(bt_index, i, j);
        }

        srv_phb_pbapc_name_swap(bt_index, i, (U16) (right - 1));
        srv_phb_pbapc_name_quicksort(bt_index, left, j);
        srv_phb_pbapc_name_quicksort(bt_index, (U16)(i + 1), right);
    }
}   /* end of phb_quicksort */


static void srv_phb_pbapc_name_insertionsort(srv_phb_pbapc_btd_enum bt_index, U16 low, U16 high)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i;
    U16 j;
    U16 pivot;
    S32 distance;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = low + 1; i <= high; ++i)
    {
        pivot = srv_cntx_p->name_index[i];

        j = i;
        while (j > low)
        {
            srv_phb_pbapc_compare_name_index(bt_index, srv_cntx_p->name_index[j - 1], pivot, &distance);
            if (distance <= 0)
            {
                break;
            }

            srv_cntx_p->name_index[j] = srv_cntx_p->name_index[j - 1];

            j--;
        }

        srv_cntx_p->name_index[j] = pivot;
    }
}   /* end of phb_insertion_sort */


static void srv_phb_pbapc_build_name_index(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cntx_p->entry_count >= 1)
    {
        srv_phb_pbapc_name_quicksort(bt_index, 0, (U16)(srv_cntx_p->entry_count - 1));
        srv_phb_pbapc_name_insertionsort(bt_index, 0, (U16)(srv_cntx_p->entry_count - 1));
    }
}


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
S32 srv_phb_pbapc_build_contact_list(srv_phb_pbapc_btd_enum bt_index, srv_phb_qsearch_filter_struct* qsearch_filter, U16* entry_array, U32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_count = 0;
    S32 i;
    U16 store_index;
    U8 order = 0;
#if defined(__MMI_PHB_QUICK_SEARCH__)
    srv_phb_pbapc_qsearch_convert_struct* convert_buffer = NULL;
#endif
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!qsearch_filter)
    {
        if (max_count > srv_cntx_p->entry_count)
        {
            max_count = srv_cntx_p->entry_count;
        }
        memcpy(entry_array, srv_cntx_p->name_index, max_count * sizeof(U16));
        return max_count;
    }

#if defined(__MMI_PHB_QUICK_SEARCH__)
    if (qsearch_filter && qsearch_filter->key_len)
    {
        convert_buffer = srv_phb_mem_malloc(
                            MMI_PHB_QSEARCH_LENGTH * sizeof(srv_phb_pbapc_qsearch_convert_struct), 
                            SRV_PHB_MEMORY_TYPE_CTR);
        memset(convert_buffer, 0, MMI_PHB_QSEARCH_LENGTH * sizeof(srv_phb_pbapc_qsearch_convert_struct));
     #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
         order = srv_phb_pbapc_get_name_order(bt_index);
         do
         {
             if (!srv_cntx_p->q_cache[order])
             {
                 srv_cntx_p->q_cache[order] = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_qsearch_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
                 memset(srv_cntx_p->q_cache[order]->word, 0, SRV_PHB_PBAPC_CONTACT_COUNT);
             }

             srv_cntx_p->q_cache[order]->input_mode = qsearch_filter->input_mode;
             srv_phb_pbapc_make_qsearch_cache(bt_index, srv_cntx_p->q_cache[order]->word, srv_cntx_p->q_cache[order]->input_mode);
         } while (0);
     #else
        do
        {
            if (!srv_cntx_p->q_cache)
            {
                srv_cntx_p->q_cache = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_qsearch_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
                memset(srv_cntx_p->q_cache->word, 0, SRV_PHB_PBAPC_CONTACT_COUNT);
            }

            srv_cntx_p->q_cache->input_mode = qsearch_filter->input_mode;
            srv_phb_pbapc_make_qsearch_cache(bt_index, srv_cntx_p->q_cache->word, srv_cntx_p->q_cache->input_mode);
        } while (0);
     #endif
    }
#endif /* __MMI_PHB_QUICK_SEARCH__ */

    for (i = 0; i < (srv_cntx_p->entry_count) && (entry_count < (U16)max_count); i++)
    {
        store_index = srv_cntx_p->name_index[i]; 

     #if defined(__MMI_PHB_QUICK_SEARCH__)
        if (qsearch_filter && qsearch_filter->key_len && !srv_phb_pbapc_qsearch_filter(bt_index, store_index, qsearch_filter, convert_buffer))
        {
            continue;
        }
    #endif /* __MMI_PHB_QUICK_SEARCH__ */
 
        entry_array[entry_count++] = store_index;
    }
#ifdef __MMI_PHB_QUICK_SEARCH__
    if (convert_buffer)
    {
        srv_phb_mem_free(convert_buffer);
    }
#endif /* __MMI_PHB_QUICK_SEARCH__ */
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BUILD_CONTACT_LIST, entry_count);

    return entry_count;
}


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
MMI_BOOL srv_phb_pbapc_get_name(srv_phb_pbapc_btd_enum bt_index, U16 store_index, U16 *name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    U8 order = 0;
    U16 tmp_name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = {L'\0'};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index < srv_cntx_p->pse_count)
    {
    #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][store_index]);
        srv_phb_pbapc_convert_name(&(pse_phb->name), tmp_name, SRV_PHB_PBAPC_NAME_LENGTH, bt_index);
        mmi_wcsncpy(name, tmp_name, len);
        return MMI_TRUE;
    #else
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][store_index]);
        mmi_wcsncpy(name, pse_phb->name, len);
        return MMI_TRUE;
    #endif
    }

    *name = 0;
    return MMI_FALSE;
}


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
MMI_BOOL srv_phb_pbapc_get_number(srv_phb_pbapc_btd_enum bt_index, U16 store_index, U8 num_index, U16 *number, U8 *type, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index < srv_cntx_p->pse_count)
    {
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][store_index]);
        if (num_index < pse_phb->num_count)
        {
            mmi_asc_n_to_wcs(number, pse_phb->number[num_index].number, len);
            if (type)
            {
                *type = pse_phb->number[num_index].type;
            }
            return MMI_TRUE;
        }
    }

    *number = 0;
    return MMI_FALSE;
}


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
U16 srv_phb_pbapc_get_number_count(srv_phb_pbapc_btd_enum bt_index, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index < srv_cntx_p->pse_count)
    {
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][store_index]);
        return pse_phb->num_count;
    }

    return 0;
}


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
U16 srv_phb_pbapc_get_phone_count(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cntx_p->phone_count;
}


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
U16 srv_phb_pbapc_get_sim_count(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_cntx_p->sim_count;
}


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
void srv_phb_pbapc_get_sync_info(srv_phb_pbapc_btd_enum bt_index, U16 *sync_count, U16 *total_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (sync_count) *sync_count = srv_cntx_p->pse_count;
    if (total_count) *total_count = srv_cntx_p->phone_total + srv_cntx_p->sim_total;
}


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
U8 srv_phb_pbapc_get_storage(srv_phb_pbapc_btd_enum bt_index, U16 store_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (store_index < srv_cntx_p->pse_count)
    {
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][store_index]);
        return pse_phb->storage;
    }

    return 0xFF;
}


#if defined(__MMI_PHB_QUICK_SEARCH__)
/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_build_alpha_jump_table
 * DESCRIPTION
 *  build alpha jump table
 * PARAMETERS
 * RETURNS
 *****************************************************************************/
S32 srv_phb_pbapc_build_alpha_jump_table(U16* entry_array, U16 entry_count, U8 bt_index, srv_phb_pbapc_jump_info_struct *jump_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    U16 ch = 0;
    U16 latin = 0;
    U16 pre_ch = 0x7fff;
    MMI_BOOL valid_ch = MMI_FALSE;
    U16 contact_id;
    U16 index = 0;
    U16 pos = 0;
    U16 k = 0;
    U8 order = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SRV_PHB_PBAPC_NAME_ORDER__
    order = srv_phb_pbapc_get_name_order(bt_index);
    do
    {
        if (!srv_cntx_p->q_cache[order])
        {
            srv_cntx_p->q_cache[order] = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_qsearch_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
            memset(srv_cntx_p->q_cache[order]->word, 0, SRV_PHB_PBAPC_CONTACT_COUNT);
        }

        srv_cntx_p->q_cache[order]->input_mode = IMM_INPUT_MODE_QUICK_SEARCH_PINYIN;
        srv_phb_pbapc_make_qsearch_cache(bt_index, srv_cntx_p->q_cache[order]->word, srv_cntx_p->q_cache[order]->input_mode);
    } while (0);
#else
    do
    {
        if (!srv_cntx_p->q_cache)
        {
            srv_cntx_p->q_cache = srv_phb_mem_malloc(sizeof(srv_phb_pbapc_qsearch_cache_struct), SRV_PHB_MEMORY_TYPE_ADM);
            memset(srv_cntx_p->q_cache->word, 0, SRV_PHB_PBAPC_CONTACT_COUNT);
        }
    
        srv_cntx_p->q_cache->input_mode = IMM_INPUT_MODE_QUICK_SEARCH_PINYIN;
        srv_phb_pbapc_make_qsearch_cache(bt_index, srv_cntx_p->q_cache->word, srv_cntx_p->q_cache->input_mode);
    } while (0);
#endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */
    memset(jump_info, 0x00, sizeof(srv_phb_pbapc_jump_info_struct));

    for (i = 0; i < entry_count; i++)
    {
        contact_id = entry_array[i];
    #ifdef __SRV_PHB_PBAPC_NAME_ORDER__
        order = srv_phb_pbapc_get_name_order(bt_index);
        ch = srv_cntx_p->q_cache[order]->word[contact_id];
    #else
        ch = srv_cntx_p->q_cache->word[contact_id];
    #endif
        latin = srv_phb_convert_to_latin(ch);
        ch = latin;
        if ((ch >= L'a') && (ch <= L'z'))    /* lower case */
        {
            index = (U8)(ch - L'a');
            ch = index + L'A'; //
            valid_ch = MMI_TRUE;
        }
        else if ((ch >= L'A') && (ch <= L'Z'))       /* upper case */
        {
            index = (U8)(ch - L'A');
            valid_ch = MMI_TRUE;
        }
        else
        {
            valid_ch = MMI_FALSE;
            ch = L'#';
        }

        if (i == 0)
        {
            pre_ch = ch;
            pos = 0;
        }

        if (pre_ch != ch)
        {
            k = jump_info->alpha_count;
            jump_info->alpha[k] = pre_ch;

            jump_info->jump_pos[k] = pos;

            jump_info->alpha_count += 1;

            pre_ch = ch;
            pos = i;
        }

        MMI_ASSERT((jump_info->alpha_count) < (SRV_PHB_PBAPC_ALPHA_LIST_COUNT));
    }

    if (entry_count)
    {
        k = jump_info->alpha_count;
        jump_info->alpha[k] = pre_ch;

        jump_info->jump_pos[k] = pos;

        jump_info->alpha_count += 1;

        pre_ch = ch;
        pos = i;
    }

    for (i = 0; i < jump_info->alpha_count; ++i)
    {
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BD_JP_TAB, jump_info->jump_pos[i], jump_info->alpha[i]);
    }

    return 0;
}
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */


#ifndef __MMI_TELEPHONY_SUPPORT__
U8 number_compare_length;
/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_convert_number_to_int
 * DESCRIPTION
 *  Converts the last n characters of a phone number to digits
 * PARAMETERS
 *  ascii_number       : [IN]        Input ascii number
 * RETURNS
 *  interger of input number
 *****************************************************************************/
U32 srv_phb_pbapc_convert_number_to_int(CHAR *ascii_number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 num_len;
    U16 ext_len;
    U16 buff_len = MMI_PHB_NUMBER_PLUS_LENGTH;
    CHAR *number;
    CHAR temp_number[MMI_PHB_NUMBER_PLUS_LENGTH + 1];
    U8 compare_length = 9;  /* Maximum convert number length is 9 digits. (4 bytes integer) */
    U32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ascii_number != NULL)
    {
        strncpy(temp_number, ascii_number, buff_len);
        temp_number[buff_len] = 0;  /* Makre sure there will be terminator */
    }
    else
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    number = temp_number;

    /* Ignore  *31# and #31# case */
    while (((number[0] == '*') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')) ||
           ((number[0] == '#') && (number[1] == '3') && (number[2] == '1') && (number[3] == '#')))
    {
        number += 4;
    }

    /* Skip the first plus sign */
    if (number[0] == '+')
    {
        number++;
    }

    /* number empty */
    if (number[0] == '\0')
    {
        return SRV_PHB_INVALID_NUMBER;
    }

    /* Find the position of extension number and remove that part */
    ext_len = strcspn(number, "+pPwW*#");
    if (!ext_len)
    {
        return SRV_PHB_EMPTY_NUMBER;
    }
    else
    {
        MMI_ASSERT(ext_len <= buff_len);

        number[ext_len] = '\0';

        /* Read compare length from NVRAM */
        if (!number_compare_length)
        {
            number_compare_length = srv_phb_read_compare_length();
        }

        num_len = strlen(number);

        /* May compare less number than 9 digits */
        if (number_compare_length < 9)
        {
            compare_length = number_compare_length;
        }

        /* Convert at most 9 digits integer */
        if (num_len > compare_length)
        {
            number += num_len - compare_length;
        }

        /* return a 32 bits integer by atol() */
        result = atol(number);

        return result;
    }
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */


static void srv_phb_pbapc_populate_number(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id id, CHAR* number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number != NULL)
    {
    #ifndef __MMI_TELEPHONY_SUPPORT__
        U32 temp = srv_phb_pbapc_convert_number_to_int(number);
    #else
        U32 temp = srv_phb_sse_convert_number_to_int(number);
    #endif
        if (temp < SRV_PHB_INVALID_NUMBER && srv_cntx_p->number_count < SRV_PHB_PBAPC_CONTACT_COUNT * SRV_PHB_PBAPC_NUMBER_COUNT)
        {
            srv_cntx_p->number_node[srv_cntx_p->number_count].id = id;
            srv_cntx_p->number_node[srv_cntx_p->number_count].number = temp;
            srv_cntx_p->number_count++;
        }
    }
}


static void srv_phb_pbapc_lookup_table_swap_node(srv_phb_pbapc_btd_enum bt_index, U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_lookup_number_node_struct temp;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &srv_cntx_p->number_node[i], sizeof(srv_phb_lookup_number_node_struct));
    memcpy(&srv_cntx_p->number_node[i], &srv_cntx_p->number_node[j], sizeof(srv_phb_lookup_number_node_struct));
    memcpy(&srv_cntx_p->number_node[j], &temp, sizeof(srv_phb_lookup_number_node_struct));
}


static void srv_phb_pbapc_lookup_table_quicksort(srv_phb_pbapc_btd_enum bt_index, U16 l, U16 r)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    U32 pivot;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    srv_phb_lookup_number_node_struct* node = srv_cntx_p->number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((r - l) > 4)
    {
        i = (r + l) / 2;
        if (node[l].number > node[i].number)
        {
            srv_phb_pbapc_lookup_table_swap_node(bt_index, l, i);
        }
        if (node[l].number > node[r].number)
        {
            srv_phb_pbapc_lookup_table_swap_node(bt_index, l, r);
        }
        if (node[i].number > node[r].number)
        {
            srv_phb_pbapc_lookup_table_swap_node(bt_index, i, r);
        }

        j = r - 1;
        srv_phb_pbapc_lookup_table_swap_node(bt_index, i, j);
        i = l;
        pivot = node[j].number;

        for (;;)
        {
            do
            {
            } while (node[++i].number < pivot);
            do
            {
            } while (node[--j].number > pivot);

            if (j < i)
            {
                break;
            }

            srv_phb_pbapc_lookup_table_swap_node(bt_index, i, j);
        }

        srv_phb_pbapc_lookup_table_swap_node(bt_index, i, (U16)(r - 1));
        srv_phb_pbapc_lookup_table_quicksort(bt_index, l, j);
        srv_phb_pbapc_lookup_table_quicksort(bt_index, (U16)(i + 1), r);
    }
}


static void srv_phb_pbapc_lookup_table_insertionsort(srv_phb_pbapc_btd_enum bt_index, U16 lo, U16 hi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 i, j;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    srv_phb_lookup_number_node_struct* node = srv_cntx_p->number_node;
    srv_phb_lookup_number_node_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = lo + 1; i <= hi; ++i)
    {
        memcpy(&temp, &node[i], sizeof(srv_phb_lookup_number_node_struct));

        j = i;
        while (j > lo)
        {
            if (node[j - 1].number <= temp.number)
            {
                break;
            }
            memcpy(&node[j], &node[j - 1], sizeof(srv_phb_lookup_number_node_struct));
            j--;
        }
        memcpy(&node[j], &temp, sizeof(srv_phb_lookup_number_node_struct));
    }
}


static void srv_phb_pbapc_build_lookup_table(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cntx_p->number_count)
    {
        /* Begin to sort. */
        srv_phb_pbapc_lookup_table_quicksort(bt_index, 0, (U16)(srv_cntx_p->number_count - 1));
        srv_phb_pbapc_lookup_table_insertionsort(bt_index, 0, (U16)(srv_cntx_p->number_count - 1));
    }
    srv_cntx_p->number_ready = MMI_TRUE;
}


#if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
#ifndef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_remove_number_prefix
 * DESCRIPTION
 *  remove number prefix
 * PARAMETERS
 *  number_in            : [IN] input number               
 * RETURNS
 *  number without prefix
 *****************************************************************************/
CHAR* srv_phb_pbapc_remove_number_prefix(CHAR* number_in)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ext_len;
    CHAR* temp_number;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp_number = number_in;

    /* Ignore  *31# and #31# case */
    while (((temp_number[0] == '*') && (temp_number[1] == '3') && (temp_number[2] == '1') && (temp_number[3] == '#')) ||
           ((temp_number[0] == '#') && (temp_number[1] == '3') && (temp_number[2] == '1') && (temp_number[3] == '#')))
    {
        temp_number += 4;
    }

    /* Skip the first plus sign */
    if (temp_number[0] == '+')
    {
        temp_number++;
    }

    /* number empty */
    if (temp_number[0] == '\0')
    {
        return temp_number;
    }

    /* Find the position of extension number and remove that part */
    ext_len = strcspn(temp_number, "+pPwW*#");
    if (ext_len)
    {
        /* Read compare length from NVRAM */
        if (!number_compare_length)
        {
            number_compare_length = srv_phb_read_compare_length();
        }

        /* Convert at most 9 digits integer */
        if (ext_len > number_compare_length)
        {
            temp_number += ext_len - number_compare_length;
        }
    }
    return temp_number;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_compare_number
 * DESCRIPTION
 *  compare two number
 * PARAMETERS
 *  number1        :   [IN]      number to search
 *  number2        :   [IN]      number from phonebook            
 * RETURNS
 *  S32
 * RETURN VALUES
 *  SRV_PHB_NO_ERROR           :    number is same
 *  SRV_PHB_ERROR              :    number not same
 *  SRV_PHB_HALF_MARTCHED      :    the same mean with SRV_PHB_ERROR for other app, 
                                    mean half martched for lookup number search
 *****************************************************************************/
S32 srv_phb_pbapc_compare_number(CHAR* number1, CHAR* number2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result = SRV_PHB_HALF_MARTCHED;
    CHAR char1, char2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (*number1 && *number2)
    {
        if (*number1 == 'P')
        {
            char1 = 'p';
        }
        else if (*number1 == 'W')
        {
            char1 = 'w';
        }
        else
        {
            char1 = *number1;
        }
        if (*number2 == 'P')
        {
            char2 = 'p';
        }
        else if (*number2 == 'W')
        {
            char2 = 'w';
        }
        else
        {
            char2 = *number2;
        }
        if (char1 != char2)
        {
            return SRV_PHB_ERROR;
        }
        if (char2 == '+' || char2 == 'p' || char2 == 'w' || char2 == '*' || char2 == '#')
        {
            result = SRV_PHB_ERROR;
        }
        number1++;
        number2++;
    }
    if (*number1 == 'P' || *number1 == 'p' || *number1 == 'w' || *number1 == 'W')
    {
        return result;
    }
    if (*number1 || *number2)
    {
        return SRV_PHB_ERROR;
    }
    return SRV_PHB_NO_ERROR;
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */


static MMI_BOOL srv_phb_pbapc_adv_number_compare(srv_phb_pbapc_btd_enum bt_index, mmi_phb_contact_id dest_id, CHAR* src_number, CHAR* dest_number, U32* dest_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CHAR* number1, *number2;
    srv_phb_pbapc_contact_struct *pse_phb = NULL;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    S32 result, count;
    U8 num_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_TELEPHONY_SUPPORT__
    number1 = srv_phb_pbapc_remove_number_prefix(src_number);
#else
    number1 = srv_phb_sse_remove_number_prefix(src_number);
#endif
    count = srv_phb_pbapc_get_number_count(bt_index, dest_id);
    for (num_index = 0; num_index < count; num_index++)
    {
        pse_phb = &(g_srv_phb_pbapc_contact[bt_index][dest_id]);
        if (pse_phb->number[num_index].number[0])
        {
        #ifndef __MMI_TELEPHONY_SUPPORT__
            number2 = srv_phb_pbapc_remove_number_prefix(pse_phb->number[num_index].number);
            result = srv_phb_pbapc_compare_number(number1, number2);
        #else
            number2 = srv_phb_sse_remove_number_prefix(pse_phb->number[num_index].number);
            result = srv_phb_sse_compare_number(number1, number2);
        #endif
            if (result == SRV_PHB_NO_ERROR)
            {
                *dest_index = num_index;
                return MMI_TRUE;
            }
            else if (result == SRV_PHB_HALF_MARTCHED && *dest_number == 0)
            {
                *dest_index = num_index;
                strcpy(dest_number, pse_phb->number[num_index].number);
            }
        }
    }

    return MMI_FALSE;
}


static S32 srv_phb_pbapc_adv_number_search(srv_phb_pbapc_btd_enum bt_index, S32 mid, U32 number, CHAR *number_ascii, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i, new_mid, min_index, counter;
    CHAR dest_number[SRV_PHB_PBAPC_NUMBER_LENGTH + 1] = {0};
    U16 j;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    srv_phb_lookup_number_node_struct* node = srv_cntx_p->number_node;
    U32 dest_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    new_mid = mid;
    min_index = SRV_PHB_PBAPC_CONTACT_COUNT;
    counter = 0;

    /* Compare number before mid */
    i = mid;
    while ((i >= 0) && (node[i].number == number))
    {
        if (srv_phb_pbapc_adv_number_compare(bt_index, node[i].id, number_ascii, dest_number, &dest_index))
        {
            for (j = 0; j < srv_cntx_p->entry_count; j++)
            {
                if (srv_cntx_p->name_index[j] == node[i].id)
                {
                    break;
                }
            }
            if (j < min_index)
            {
                if (number_index)
                {
                     *number_index = dest_index;
                }
                min_index = j;
                new_mid = i;
            }
        }
        i--;
        counter++;
        if (counter >= SRV_PHB_NUM_ADV_COMP_COUNT)
        {
            break;
        }
    }

    /* Compare number after mid */
    i = mid + 1;
    while ((i < srv_cntx_p->number_count) && (srv_cntx_p->number_node[i].number == number))
    {
        if (srv_phb_pbapc_adv_number_compare(bt_index, node[i].id, number_ascii, dest_number, &dest_index))
        {
            for (j = 0; j < srv_cntx_p->entry_count; j++)
            {
                if (srv_cntx_p->name_index[j] == node[i].id)
                {
                    break;
                }
            }
            if (j < min_index)
            {
                if (number_index)
                {
                    *number_index = dest_index;
                }
                min_index = j;
                new_mid = i;
            }
        }
        i++;
        counter++;
        if (counter >= SRV_PHB_NUM_ADV_COMP_COUNT)
        {
            break;
        }
    }

    if (min_index == SRV_PHB_PBAPC_CONTACT_COUNT)
    {
        if ((counter <= 1) && *dest_number)
        {
            return mid;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        return new_mid;
    }
}
#endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 


static S32 srv_phb_pbapc_lookup_table_search(srv_phb_pbapc_btd_enum bt_index, U32 number, S16 low, S16 high, CHAR *number_ascii, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 mid;
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    srv_phb_lookup_number_node_struct* node = srv_cntx_p->number_node;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (number == node[mid].number)
        {
            /*
             * Advanced Compare - Compare number longer than 9 digit,
             * with extension, find out the prior one if numbers are the same, and etc.
             */
        #if defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__)
            mid = srv_phb_pbapc_adv_number_search(bt_index, mid, number, number_ascii, number_index);

            if (mid < 0)
            {
                return SRV_PHB_NOT_FOUND;  /* an invalid number */
            }
            else
        #endif /* defined(__MMI_PHB_ADV_NUM_MATCH_MOBILE__) */ 
            {
                return node[mid].id;
            }
        }
        else if (number < node[mid].number)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return SRV_PHB_NOT_FOUND;
}


static S32 srv_phb_pbapc_search_number(srv_phb_pbapc_btd_enum bt_index, U16* number, U32* number_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
    CHAR number_ascii[SRV_PHB_PBAPC_NUMBER_LENGTH + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (number[0] == 0)
    {
        return SRV_PHB_NOT_FOUND;
    }

    mmi_wcs_n_to_asc(number_ascii, number, SRV_PHB_PBAPC_NUMBER_LENGTH * sizeof(U16));

    /* Lookup into table when (1) lookup table not empty (3)All Entries populated and sorted */
    if (srv_cntx_p->number_ready && srv_cntx_p->number_count)
    {
    #ifndef __MMI_TELEPHONY_SUPPORT__
        U32 temp = srv_phb_pbapc_convert_number_to_int(number_ascii);
    #else
        U32 temp = srv_phb_sse_convert_number_to_int(number_ascii);
    #endif
        if (temp < SRV_PHB_INVALID_NUMBER)
        {
            return srv_phb_pbapc_lookup_table_search(bt_index, temp, (S16)0, (S16)(srv_cntx_p->number_count - 1), (CHAR*)number_ascii, number_index);            
        }
    }
    else
    {
        return SRV_PHB_NUM_NOT_READY;
    }

    return SRV_PHB_NOT_FOUND;
}


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
MMI_BOOL srv_phb_pbapc_get_name_by_number(srv_phb_pbapc_btd_enum bt_index, U16 *number, U16 *name, U16 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = srv_phb_pbapc_search_number(bt_index, number, NULL);
    if (result >= 0)
    {
        srv_phb_pbapc_get_name(bt_index, (U16) result, name, len);
        return MMI_TRUE;
    }

    name[0] = 0;
    return MMI_FALSE;
}


mmi_ret srv_phb_pbapc_disconn_hdlr(mmi_event_struct *evt)
{
    srv_pbapc_notify_event_struct *notify_evt;

    notify_evt = (srv_pbapc_notify_event_struct *)evt;
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_DISCONN_HDLR, notify_evt->type);
    if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && (notify_evt->type == EVT_ID_PBAPC_DISCONNECT_IND || notify_evt->type == EVT_ID_PBAPC_DISCONNECT_RSP))
    {
        srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
        srv_phb_pbapc_notify_app(bt_index, MMI_TRUE);
    }
    else if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && notify_evt->type == EVT_ID_PBAPC_CONNECT_RSP)
    {
        srv_pbapc_connect_rsp_struct *connect_rsp = (srv_pbapc_connect_rsp_struct*) notify_evt->data;
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_DISCONN_HDLR_I, connect_rsp->new_btd, connect_rsp->ret);
        if (connect_rsp->new_btd == MMI_TRUE)
        {
            srv_phb_pbapc_sync_clear_evt_struct evt;
            srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
            srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
            srv_cntx_p->pse_count = 0;
            srv_cntx_p->phone_count = 0;
            srv_cntx_p->sim_count = 0;
            srv_cntx_p->entry_count = 0;
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_PHB_PBAPC_SYNC_DATA_CLEAR);
            evt.bt_index = bt_index;
            MMI_FRM_CB_EMIT_EVENT(&evt);
        }
    }
    else if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && notify_evt->type == EVT_ID_PBAPC_DEL_BTD)
    {
        srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
        srv_phb_pbapc_load_contact_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_contact_cntx[bt_index];
        srv_cntx_p->pse_count = 0;
        srv_cntx_p->phone_count = 0;
        srv_cntx_p->sim_count = 0;
        srv_cntx_p->entry_count = 0;
    }

    return MMI_RET_OK;
}

#include "custom_calllog.h"

typedef struct
{
    U8 job;         /* 0: init; 1: read phone count; 2: read sim count; 3: read phone folder; 4: read sim folder; */
    U8 op_stop;
#ifndef __MMI_WEARABLE_DEVICE__
    U16 dialed_count; /* valid count */
    U16 received_count;
    U16 missed_count;
#endif /* __MMI_WEARABLE_DEVICE__ */
    U16 clog_count;
    U16 read_time;
    SRV_PHB_PBAPC_HANDLE handle;
    VP_HANDLE p_handle;
    srv_phb_pbapc_load_clog_cb cb_func;
    void *user_data;
    U16 entry_count;
#ifndef __MMI_WEARABLE_DEVICE__
    U16 dialed_index[MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES];
    U16 received_index[MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES];
    U16 missed_index[MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES];
#endif /* __MMI_WEARABLE_DEVICE__ */
    U16 clog_index[MMI_CLOG_PBAPC_ALL_CALL_ENTRIES];
} srv_phb_pbapc_load_clog_cntx_struct;

static srv_phb_pbapc_load_clog_cntx_struct g_srv_phb_pbapc_load_clog_cntx[SRV_PBAPC_LINK_NUM];

#ifndef __MMI_WEARABLE_DEVICE__
static srv_phb_pbapc_clog_struct g_srv_phb_pbapc_dialed[SRV_PBAPC_LINK_NUM][MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES];

static srv_phb_pbapc_clog_struct g_srv_phb_pbapc_received[SRV_PBAPC_LINK_NUM][MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES];

static srv_phb_pbapc_clog_struct g_srv_phb_pbapc_missed[SRV_PBAPC_LINK_NUM][MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES];
#endif /* __MMI_WEARABLE_DEVICE__ */

static srv_phb_pbapc_clog_struct g_srv_phb_pbapc_clog[SRV_PBAPC_LINK_NUM][MMI_CLOG_PBAPC_ALL_CALL_ENTRIES];

/* function */
static S32 srv_phb_pbapc_clog_check_continue(srv_phb_pbapc_btd_enum bt_index);

static S32 srv_phb_pbapc_push_clog(vcard_object_struct *vcard_object, srv_phb_pbapc_clog_struct *pse_clog);

static void srv_phb_pbapc_clog_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data);

static void srv_phb_pbapc_clog_parse(srv_phb_pbapc_btd_enum bt_index, U16 *path);

static S32 srv_phb_pbapc_clog_read_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data);

static void srv_phb_pbapc_clog_job_hdlr(srv_phb_pbapc_btd_enum bt_index);

static void srv_phb_pbapc_clog_notify_app(srv_phb_pbapc_btd_enum bt_index, MMI_BOOL disconn);

static void srv_phb_pbapc_populate_clog_index(srv_phb_pbapc_btd_enum bt_index, U16 id);

static void srv_phb_pbapc_build_clog_index(srv_phb_pbapc_btd_enum bt_index);

static S32 srv_phb_pbapc_clog_check_continue(srv_phb_pbapc_btd_enum bt_index)
{
    S32 ret = 0;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    if (srv_cntx_p->p_handle != NULL)
    {
        vcard_close_parser(srv_cntx_p->p_handle);
        srv_cntx_p->p_handle = NULL;

        FS_Delete(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]);
    }

#ifndef __MMI_WEARABLE_DEVICE__
    if (srv_cntx_p->job == 1)
    {
        if (srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE < MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES)
        {
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else
        {
            srv_cntx_p->job = 2;
            srv_cntx_p->read_time = 0;
            srv_cntx_p->entry_count = 0;
            srv_phb_pbapc_clog_check_continue(bt_index);
        }
    }
    else if (srv_cntx_p->job == 2)
    {
        if (srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE < MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES)
        {
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else
        {
            srv_cntx_p->job = 3;
            srv_cntx_p->read_time = 0;
            srv_cntx_p->entry_count = 0;
            srv_phb_pbapc_clog_check_continue(bt_index);
        }
    }
    else if (srv_cntx_p->job == 3)
    {
        if (srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE < MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES)
        {
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else
        {
            srv_cntx_p->job = 4;
            srv_cntx_p->read_time = 0;
            srv_cntx_p->entry_count = 0;
            srv_phb_pbapc_clog_check_continue(bt_index);
        }
    }
    else
#endif /* __MMI_WEARABLE_DEVICE__ */
    if (srv_cntx_p->job == 4)
    {
        if (srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE < MMI_CLOG_PBAPC_ALL_CALL_ENTRIES)
        {
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else
        {
            srv_phb_pbapc_clog_notify_app(bt_index, MMI_FALSE);
        }
    }
#if !defined(__MTK_TARGET__)
    else if (srv_cntx_p->job == 0x7f)
    {
        srv_phb_pbapc_clog_notify_app(bt_index, MMI_FALSE);
    }
#endif /* !defined(__MTK_TARGET__) */
    else
    {
        MMI_ASSERT(0);
    }

    return ret;
}


static S32 srv_phb_pbapc_push_clog(vcard_object_struct *vcard_object, srv_phb_pbapc_clog_struct *pse_clog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U32 field_mask = 0;
    U16 temp_name[MMI_CLOG_PBAPC_NAME_MAX_LEN + 1] = { L'\0' };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pse_clog, 0x00, sizeof(srv_phb_pbapc_clog_struct));

    if (vcard_object->n.mid && vcard_object->n.mid[0])
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.mid);
        srv_phb_remove_invalid_name(vcard_object->n.given);

        mmi_wcsncpy((WCHAR *)temp_name, vcard_object->n.mid, MMI_CLOG_PBAPC_NAME_MAX_LEN);
        mmi_wcsncat((WCHAR *)(temp_name + mmi_wcslen(temp_name)), vcard_object->n.given, MMI_CLOG_PBAPC_NAME_MAX_LEN - mmi_wcslen(temp_name));

        srv_phb_convert_to_name(
                pse_clog->name,
                temp_name,
                vcard_object->n.family,
                MMI_CLOG_PBAPC_NAME_MAX_LEN);
    }
    else
    {
        srv_phb_remove_invalid_name(vcard_object->n.family);
        srv_phb_remove_invalid_name(vcard_object->n.given);
        srv_phb_convert_to_name(
                        pse_clog->name,
                        vcard_object->n.given,
                        vcard_object->n.family,
                        MMI_CLOG_PBAPC_NAME_MAX_LEN);
    }

    if (pse_clog->name[0])
    {
        field_mask |= 0x01;
    }

    for (i = 0; i < VCARD_MAX_TEL_COUNT; ++i)
    {
        if (vcard_object->tel[i].tel && vcard_object->tel[i].tel[0])
        {
            srv_phb_pbapc_remove_sp_char(vcard_object->tel[i].tel);
            srv_phb_remove_invalid_number(vcard_object->tel[i].tel);

            if (vcard_object->tel[i].tel[0])
            {
                mmi_wcs_n_to_asc(pse_clog->cid, vcard_object->tel[i].tel, MMI_CLOG_PBAPC_CID_MAX_LEN * 2);
                field_mask |= 0x02;
                break;
            }
        }
    }

    memcpy(&(pse_clog->timestamp[0]), &(vcard_object->x.call_time), sizeof(applib_time_struct));

    if (applib_dt_is_valid(&(pse_clog->timestamp[0])))
    {
        field_mask |= 0x04;
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_PUSH_CLOG, field_mask);

    return field_mask;
}


static void srv_phb_pbapc_clog_parse_cb(kal_int32 error_code, kal_uint16 percentage, vcard_object_struct *object, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) user_data;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];
    srv_phb_pbapc_clog_struct *pse_clog = NULL;
    S32 ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_phb_pbapc_clog_notify_app(bt_index, MMI_FALSE);
        return;
    }

    if (percentage <= 100 && error_code == VCARD_NO_ERROR)
    {
    #ifndef __MMI_WEARABLE_DEVICE__
        if (srv_cntx_p->job == 1 && srv_cntx_p->dialed_count < MMI_CLOG_PBAPC_DIALED_CALL_ENTRIES)
        {
            pse_clog = &(g_srv_phb_pbapc_dialed[bt_index][srv_cntx_p->dialed_count]);
        }
        else if (srv_cntx_p->job == 2 && srv_cntx_p->received_count < MMI_CLOG_PBAPC_RECVED_CALL_ENTRIES)
        {
            pse_clog = &(g_srv_phb_pbapc_received[bt_index][srv_cntx_p->received_count]);
        }
        else if (srv_cntx_p->job == 3 && srv_cntx_p->missed_count < MMI_CLOG_PBAPC_MISSED_CALL_ENTRIES)
        {
            pse_clog = &(g_srv_phb_pbapc_missed[bt_index][srv_cntx_p->missed_count]);
        }
        else
    #endif /* __MMI_WEARABLE_DEVICE__ */
        if (srv_cntx_p->job == 4 && srv_cntx_p->clog_count < MMI_CLOG_PBAPC_ALL_CALL_ENTRIES)
        {
            pse_clog = &(g_srv_phb_pbapc_clog[bt_index][srv_cntx_p->clog_count]);
        }
    #if !defined(__MTK_TARGET__)
        else if (srv_cntx_p->job == 0x7f)
        {
            pse_clog = &(g_srv_phb_pbapc_clog[bt_index][srv_cntx_p->clog_count]);
        }
    #endif /* !defined(__MTK_TARGET__) */
        else if (srv_cntx_p->clog_count == MMI_CLOG_PBAPC_ALL_CALL_ENTRIES)
        {
            srv_phb_pbapc_clog_check_continue(bt_index);
            return;
        }
        else
        {
            MMI_ASSERT(0);
        }

        ret = srv_phb_pbapc_push_clog(object, pse_clog);

        if (ret)
        {
        #ifndef __MMI_WEARABLE_DEVICE__
            if (srv_cntx_p->job == 1)
            {
                srv_phb_pbapc_populate_clog_index(bt_index, srv_cntx_p->dialed_count);
                srv_cntx_p->dialed_count++;
            }
            else if (srv_cntx_p->job == 2)
            {
                srv_phb_pbapc_populate_clog_index(bt_index, srv_cntx_p->received_count);
                srv_cntx_p->received_count++;
            }
            else if (srv_cntx_p->job == 3)
            {
                srv_phb_pbapc_populate_clog_index(bt_index, srv_cntx_p->missed_count);
                srv_cntx_p->missed_count++;
            }
            else
        #endif /* __MMI_WEARABLE_DEVICE__ */
            {
                srv_phb_pbapc_populate_clog_index(bt_index, srv_cntx_p->clog_count);
                srv_cntx_p->clog_count++;
            }
            pse_clog->call_type = object->x.call_type;
        }

        if (percentage == 100)
        {
            srv_phb_pbapc_clog_check_continue(bt_index);
        }
        else
        {
            vcard_multi_parse(srv_cntx_p->p_handle, srv_phb_pbapc_clog_parse_cb, (void*)bt_index);
        }

        return;
    }

    srv_phb_pbapc_clog_check_continue(bt_index);
}


static void srv_phb_pbapc_clog_parse(srv_phb_pbapc_btd_enum bt_index, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];
    U32 property = VCARD_PROPERTY_N | VCARD_PROPERTY_TEL | VCARD_PROPERTY_X;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_cntx_p->p_handle = vcard_open_parser(path, property, &ret);

    if (srv_cntx_p->p_handle)
    {
        vcard_multi_parse(srv_cntx_p->p_handle, srv_phb_pbapc_clog_parse_cb, (void*)bt_index);
    }
    else
    {
        srv_phb_pbapc_clog_check_continue(bt_index);
    }
}


static void srv_phb_pbapc_clog_copy_file(srv_phb_pbapc_btd_enum bt_index, U16 *path)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret1, ret2, ret3;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret1 = ret2 = ret3 = -251;

    ret1 = srv_fmgr_fs_path_exist(SRV_PHB_PBAPC_WORK_FOLDER);

    if (ret1 < 0)
    {
       ret2 = srv_fmgr_fs_create_folder(SRV_PHB_PBAPC_WORK_FOLDER);
    }

    ret3 = FS_Move(path, srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index], FS_MOVE_COPY | FS_MOVE_OVERWRITE, NULL, NULL, NULL);

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_COPY_FILE, ret1, ret2, ret3);
    
}


static S32 srv_phb_pbapc_clog_read_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) user_data;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (folder_rsp->ret == SRV_PBAPC_RET_OK)
    {
    #ifndef __MMI_WEARABLE_DEVICE__
        if (srv_cntx_p->job == 1)
        {
            srv_phb_pbapc_clog_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_clog_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]));
        }
        else if (srv_cntx_p->job == 2)
        {
            srv_phb_pbapc_clog_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_clog_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]));
        }
        else if (srv_cntx_p->job == 3)
        {
            srv_phb_pbapc_clog_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_clog_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]));
        }
        else
    #endif /* __MMI_WEARABLE_DEVICE__ */
        if (srv_cntx_p->job == 4)
        {
            srv_phb_pbapc_clog_copy_file(bt_index, folder_rsp->folder_path);
            srv_phb_pbapc_clog_parse(bt_index, (U16 *)(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]));
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
    #ifndef __MMI_WEARABLE_DEVICE__
        if (srv_cntx_p->job == 1)
        {
            srv_cntx_p->job = 2;
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 2)
        {
            srv_cntx_p->job = 3;
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else if (srv_cntx_p->job == 3)
        {
            srv_cntx_p->job = 4;
            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
        else
    #endif /* __MMI_WEARABLE_DEVICE__ */
        if (srv_cntx_p->job == 4)
        {
            srv_phb_pbapc_clog_notify_app(bt_index, MMI_FALSE);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }

    return 0;
}


static void srv_phb_pbapc_clog_job_hdlr(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WEARABLE_DEVICE__
    if (srv_cntx_p->job == 1)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_OCH;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL | SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP;
        folder_req.list_count = MMI_CLOG_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE;

        srv_cntx_p->read_time++;
    }
    else if (srv_cntx_p->job == 2)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_ICH;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL | SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP;
        folder_req.list_count = MMI_CLOG_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE;

        srv_cntx_p->read_time++;
    }
    else if (srv_cntx_p->job == 3)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_MCH;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL | SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP;
        folder_req.list_count = MMI_CLOG_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE;

        srv_cntx_p->read_time++;
    }
    else
#endif /* __MMI_WEARABLE_DEVICE__ */
    if (srv_cntx_p->job == 4)
    {
        folder_req.handle = srv_cntx_p->handle;
        folder_req.bt_index = bt_index;
        folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_CCH;
        folder_req.user_data = (void *)bt_index;

        folder_req.folder_name = NULL;
        folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
        folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_N | SRV_PHB_PBAP_VCARD_FILTER_FN | SRV_PHB_PBAP_VCARD_FILTER_TEL | SRV_PHB_PBAP_VCARD_FILTER_TIMESTAMP;
        folder_req.list_count = MMI_CLOG_PBAPC_FOLDER_SIZE;
        folder_req.list_offset = srv_cntx_p->read_time * MMI_CLOG_PBAPC_FOLDER_SIZE;

        srv_cntx_p->read_time++;
    }
    else
    {
        MMI_ASSERT(0);
    }

    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_phb_pbapc_clog_notify_app(bt_index, MMI_FALSE);
    }
    else
    {
        ret = srv_phb_pbapc_read_pse_folder(&folder_req, srv_phb_pbapc_clog_read_cb);

        if (SRV_PHB_PBAPC_RET_DISCONNECTED == ret)
        {
            srv_phb_pbapc_clog_notify_app(bt_index, MMI_TRUE);
        }
    }
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CLG_JOB_HDLR, srv_cntx_p->job, srv_cntx_p->read_time);
}


static void srv_phb_pbapc_clog_notify_app(srv_phb_pbapc_btd_enum bt_index, MMI_BOOL disconn)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_clog_rsp load_rsp;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_CLG_NOTI_APP, srv_cntx_p->op_stop);
    if (srv_cntx_p->handle != NULL)
    {
        srv_phb_pbapc_destory_handle(srv_cntx_p->handle);
        srv_cntx_p->handle = NULL;
    }

    if (srv_cntx_p->p_handle != NULL)
    {
        vcard_close_parser(srv_cntx_p->p_handle);
        srv_cntx_p->p_handle = NULL;

        FS_Delete(srv_phb_pbapc_file_name[SRV_PHB_PBAPC_BTD_TOTAL + bt_index]);
    }

    if (disconn == MMI_FALSE)
    {
        srv_phb_pbapc_build_clog_index(bt_index);

        load_rsp.ret = SRV_PHB_PBAPC_RET_OK;
    }
    else
    {
    #ifdef __MMI_PHB_PBAPC_NO_CLEAR__
        if (srv_cntx_p->op_stop == MMI_FALSE) /* No need to sort again since it has been done when cancel */
        {
            srv_phb_pbapc_build_clog_index(bt_index);
        }
    #else /* __MMI_PHB_PBAPC_NO_CLEAR__ */
        srv_cntx_p->pse_count = 0;
        srv_cntx_p->entry_count = 0;
    #endif /* __MMI_PHB_PBAPC_NO_CLEAR__ */

        load_rsp.ret = SRV_PHB_PBAPC_RET_FAIL;
    }

    load_rsp.bt_index = bt_index;

    if (srv_cntx_p->op_stop == MMI_TRUE)
    {
        srv_cntx_p->op_stop = MMI_FALSE;
    }
    else if (srv_cntx_p->cb_func != NULL)
    {
        srv_cntx_p->cb_func(&load_rsp, srv_cntx_p->user_data);
    }
    srv_cntx_p->cb_func = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_phb_pbapc_load_clog
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 * 
 *****************************************************************************/
S32 srv_phb_pbapc_load_clog(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_load_clog_cb cb_func, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = -1;
    SRV_PHB_PBAPC_HANDLE handle = NULL;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__)
    /* reset */
    memset(srv_cntx_p, 0x00, sizeof(srv_phb_pbapc_load_clog_cntx_struct));
    srv_cntx_p->handle = handle;
    srv_cntx_p->job = 0x7f;
    srv_cntx_p->cb_func = cb_func;
    srv_cntx_p->user_data = user_data;

    srv_phb_pbapc_clog_parse(bt_index, L"E:\\test.vcf");

    return 0;
#endif /* !defined(__MTK_TARGET__) */

    if (srv_cntx_p->op_stop == MMI_TRUE || srv_cntx_p->cb_func != NULL)
    {
        ret = SRV_PHB_PBAPC_RET_BUSY;
    }
    else
    {
        handle = srv_phb_pbapc_create_handle(&ret);

        if (ret == SRV_PHB_PBAPC_RET_OK)
        {
            /* reset */
            memset(srv_cntx_p, 0x00, sizeof(srv_phb_pbapc_load_clog_cntx_struct));
            srv_cntx_p->handle = handle;
        #ifndef __MMI_WEARABLE_DEVICE__
            srv_cntx_p->job = 1;
        #else
            srv_cntx_p->job = 4;
        #endif
            srv_cntx_p->cb_func = cb_func;
            srv_cntx_p->user_data = user_data;

            srv_phb_pbapc_clog_job_hdlr(bt_index);
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_LOAD_CLG, ret);
    return ret;
}


static void srv_phb_pbapc_populate_clog_index(srv_phb_pbapc_btd_enum bt_index, U16 id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WEARABLE_DEVICE__
    if (srv_cntx_p->job == 1)
    {
        srv_cntx_p->dialed_index[srv_cntx_p->entry_count++] = id;
    }
    else if (srv_cntx_p->job == 2)
    {
        srv_cntx_p->received_index[srv_cntx_p->entry_count++] = id;
    }
    else if (srv_cntx_p->job == 3)
    {
        srv_cntx_p->missed_index[srv_cntx_p->entry_count++] = id;
    }
    else
#endif /* __MMI_WEARABLE_DEVICE__ */
    {
        srv_cntx_p->clog_index[srv_cntx_p->entry_count++] = id;
    }
}


static void srv_phb_pbapc_swap_clog_index(srv_phb_pbapc_clog_struct *pse_clog, U16 i, U16 j)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_clog_struct temp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(&temp, &pse_clog[i], sizeof(srv_phb_pbapc_clog_struct));
    memcpy(&pse_clog[i], &pse_clog[j], sizeof(srv_phb_pbapc_clog_struct));
    memcpy(&pse_clog[j], &temp, sizeof(srv_phb_pbapc_clog_struct));
}


static void srv_phb_pbapc_build_clog_index(srv_phb_pbapc_btd_enum bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];
    U16 i = 0, j = 0;
    applib_time_struct curr_time, next_time;
    srv_phb_pbapc_clog_struct *pse_clog;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WEARABLE_DEVICE__
    if (srv_cntx_p->dialed_count >= 2)
    {
        pse_clog = g_srv_phb_pbapc_dialed[bt_index];
        for (i = 0; i <= (srv_cntx_p->dialed_count - 1); i++)
        {
            for (j = 0; j < (srv_cntx_p->dialed_count - 1 - i); j++)
            {
                curr_time = pse_clog[j].timestamp[0];
                next_time = pse_clog[j + 1].timestamp[0];
                if (applib_dt_compare_time(&curr_time, &next_time, NULL) == DT_TIME_LESS)
                {
                    srv_phb_pbapc_swap_clog_index(pse_clog, j, j + 1);
                }
            }
        }
    }

    if (srv_cntx_p->received_count >= 2)
    {
        pse_clog = g_srv_phb_pbapc_received[bt_index];
        for (i = 0; i <= (srv_cntx_p->received_count - 1); i++)
        {
            for (j = 0; j < (srv_cntx_p->received_count - 1 - i); j++)
            {
                curr_time = pse_clog[j].timestamp[0];
                next_time = pse_clog[j + 1].timestamp[0];
                if (applib_dt_compare_time(&curr_time, &next_time, NULL) == DT_TIME_LESS)
                {
                    srv_phb_pbapc_swap_clog_index(pse_clog, j, j + 1);
                }
            }
        }
    }

    if (srv_cntx_p->missed_count >= 2)
    {
        pse_clog = g_srv_phb_pbapc_missed[bt_index];
        for (i = 0; i <= (srv_cntx_p->missed_count - 1); i++)
        {
            for (j = 0; j < (srv_cntx_p->missed_count - 1 - i); j++)
            {
                curr_time = pse_clog[j].timestamp[0];
                next_time = pse_clog[j + 1].timestamp[0];
                if (applib_dt_compare_time(&curr_time, &next_time, NULL) == DT_TIME_LESS)
                {
                    srv_phb_pbapc_swap_clog_index(pse_clog, j, j + 1);
                }
            }
        }
    }
#endif /* __MMI_WEARABLE_DEVICE__ */
    if (srv_cntx_p->clog_count >= 2)
    {
        pse_clog = g_srv_phb_pbapc_clog[bt_index];
        for (i = 0; i <= (srv_cntx_p->clog_count - 1); i++)
        {
            for (j = 0; j < (srv_cntx_p->clog_count - 1 - i); j++)
            {
                curr_time = pse_clog[j].timestamp[0];
                next_time = pse_clog[j + 1].timestamp[0];
                if (applib_dt_compare_time(&curr_time, &next_time, NULL) == DT_TIME_LESS)
                {
                    srv_phb_pbapc_swap_clog_index(pse_clog, j, j + 1);
                }
            }
        }
    }
}


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
S32 srv_phb_pbapc_build_clog_list(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_clt_enum call_type, U16* entry_array, U32 max_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 entry_count = 0;
    S32 i;
    U16 store_index;
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WEARABLE_DEVICE__
    if (call_type == SRV_PHB_PBAPC_CLT_DIALED)
    {
        for (i = 0; i < (srv_cntx_p->dialed_count) && (entry_count < (U16)max_count); i++)
        {
            store_index = srv_cntx_p->dialed_index[i]; 
 
            entry_array[entry_count++] = store_index;
        }
    }
    else if (call_type == SRV_PHB_PBAPC_CLT_RECVED)
    {
        for (i = 0; i < (srv_cntx_p->received_count) && (entry_count < (U16)max_count); i++)
        {
            store_index = srv_cntx_p->received_index[i]; 
 
            entry_array[entry_count++] = store_index;
        }
    }
    else if (call_type == SRV_PHB_PBAPC_CLT_MISSED)
    {
        for (i = 0; i < (srv_cntx_p->missed_count) && (entry_count < (U16)max_count); i++)
        {
            store_index = srv_cntx_p->missed_index[i]; 
 
            entry_array[entry_count++] = store_index;
        }
    }
    else
#endif /* __MMI_WEARABLE_DEVICE__ */
    if (call_type == SRV_PHB_PBAPC_CLT_ALL)
    {
        for (i = 0; i < (srv_cntx_p->clog_count) && (entry_count < (U16)max_count); i++)
        {
            store_index = srv_cntx_p->clog_index[i]; 
 
            entry_array[entry_count++] = store_index;
        }
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_PBAPC_BUILD_CLG_LIST, entry_count);
    return entry_count;
}


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
MMI_BOOL srv_phb_pbapc_get_clog_entry(srv_phb_pbapc_btd_enum bt_index, srv_phb_pbapc_clt_enum call_type, U16 store_index, srv_phb_pbapc_clog_struct *pse_clog)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_WEARABLE_DEVICE__
    if (call_type == SRV_PHB_PBAPC_CLT_DIALED && store_index < srv_cntx_p->dialed_count)
    {
        memcpy(pse_clog, &(g_srv_phb_pbapc_dialed[bt_index][store_index]), sizeof(srv_phb_pbapc_clog_struct));
        return MMI_TRUE;
    }
    else if (call_type == SRV_PHB_PBAPC_CLT_RECVED && store_index < srv_cntx_p->received_count)
    {
        memcpy(pse_clog, &(g_srv_phb_pbapc_received[bt_index][store_index]), sizeof(srv_phb_pbapc_clog_struct));
        return MMI_TRUE;
    }
    else if (call_type == SRV_PHB_PBAPC_CLT_MISSED && store_index < srv_cntx_p->missed_count)
    {
        memcpy(pse_clog, &(g_srv_phb_pbapc_missed[bt_index][store_index]), sizeof(srv_phb_pbapc_clog_struct));
        return MMI_TRUE;
    }
    else
#endif /* __MMI_WEARABLE_DEVICE__ */
    if (call_type == SRV_PHB_PBAPC_CLT_ALL && store_index < srv_cntx_p->clog_count)
    {
        memcpy(pse_clog, &(g_srv_phb_pbapc_clog[bt_index][store_index]), sizeof(srv_phb_pbapc_clog_struct));
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


mmi_ret srv_phb_pbapc_clog_disconn_hdlr(mmi_event_struct *evt)
{
    srv_pbapc_notify_event_struct *notify_evt;

    notify_evt = (srv_pbapc_notify_event_struct *)evt;
    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_CLG_DISCONN_HDLR, notify_evt->type);
    if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && (notify_evt->type == EVT_ID_PBAPC_DISCONNECT_IND || notify_evt->type == EVT_ID_PBAPC_DISCONNECT_RSP))
    {
        srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
        srv_phb_pbapc_clog_notify_app(bt_index, MMI_TRUE);
    }
    else if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && notify_evt->type == EVT_ID_PBAPC_CONNECT_RSP)
    {
        srv_pbapc_connect_rsp_struct *connect_rsp = (srv_pbapc_connect_rsp_struct*) notify_evt->data;
        MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_CLG_DISCONN_HDLR_I, connect_rsp->new_btd, connect_rsp->ret);
        if (connect_rsp->new_btd == MMI_TRUE)
        {
            srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
            srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];
        #ifndef __MMI_WEARABLE_DEVICE__
            srv_cntx_p->dialed_count = 0;
            srv_cntx_p->received_count = 0;
            srv_cntx_p->missed_count = 0;
        #endif /* __MMI_WEARABLE_DEVICE__ */
            srv_cntx_p->clog_count = 0;
        }
    }
    else if (notify_evt->evt_id == EVT_ID_PBAP_NOTIFY && notify_evt->type == EVT_ID_PBAPC_DEL_BTD)
    {
        srv_phb_pbapc_btd_enum bt_index = (srv_phb_pbapc_btd_enum) notify_evt->bt_index;
        srv_phb_pbapc_load_clog_cntx_struct *srv_cntx_p = &g_srv_phb_pbapc_load_clog_cntx[bt_index];
    #ifndef __MMI_WEARABLE_DEVICE__
        srv_cntx_p->dialed_count = 0;
        srv_cntx_p->received_count = 0;
        srv_cntx_p->missed_count = 0;
    #endif /* __MMI_WEARABLE_DEVICE__ */
        srv_cntx_p->clog_count = 0;
    }

    return MMI_RET_OK;
}

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
S32 srv_phb_pbapc_get_name_order(U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_FAIL;
    U16 set = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bt_index)
    {
        case SRV_PHB_PBAPC_BTD_1ST:
        {
            set = g_srv_phb_pbapc_name_order & 0x000f;

            break;
        }

        case SRV_PHB_PBAPC_BTD_2ND:
        {
            set = (g_srv_phb_pbapc_name_order & 0x00f0) >> 4;

            break;
        }

        case SRV_PHB_PBAPC_BTD_3RD:
        {
            set = (g_srv_phb_pbapc_name_order & 0x0f00) >> 8;

            break;
        }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
            MMI_ASSERT(0);
            break;
    }

    if (set & (1 << SRV_PHB_PBAPC_NAME_ORDER_1))
    {
        ret = SRV_PHB_PBAPC_NAME_ORDER_1;
    }
    else if (set & (1 << SRV_PHB_PBAPC_NAME_ORDER_2))
    {
        ret = SRV_PHB_PBAPC_NAME_ORDER_2;
    }
    else
    {
        ;
    }

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_CLG_GET_NAME_ORDER, g_srv_phb_pbapc_name_order, bt_index, ret);

    return ret;
}


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
S32 srv_phb_pbapc_set_name_order(U8 bt_index, U8 name_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PHB_PBAPC_RET_OK;
    U16 clear = 0x00;
    U16 set = 0x00;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (bt_index)
    {
        case SRV_PHB_PBAPC_BTD_1ST:
        {
            clear = 0xfff0;
            set = (0x01 << name_order);

            break;
        }

        case SRV_PHB_PBAPC_BTD_2ND:
        {
            clear = 0xff0f;
            set = (0x01 << name_order) << 4;

            break;
        }
        case SRV_PHB_PBAPC_BTD_3RD:
        {
            clear = 0xf0ff;
            set = (0x01 << name_order) << 8;

            break;
        }

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
            MMI_ASSERT(0);
            break;
    }

    g_srv_phb_pbapc_name_order &= clear;
    g_srv_phb_pbapc_name_order |= set;

    MMI_TRACE(SRV_PHB_PBAP_TRACE_GROUP, TRC_SRV_PHB_CLG_SET_NAME_ORDER, g_srv_phb_pbapc_name_order, bt_index, name_order);

    WriteValueSlim(NVRAM_PHB_PBAPC_NAME_ORDER, &g_srv_phb_pbapc_name_order, DS_SHORT);
    srv_phb_pbapc_build_name_index(bt_index);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_phb_pbapc_convert_name
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_phb_pbapc_convert_name(srv_phb_pbapc_name_struct *name, U16 *cov, U16 len, U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 order = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    order = srv_phb_pbapc_get_name_order(bt_index);

    return srv_phb_pbapc_convert_name_ex(name, order, cov, len, bt_index);
}


S32 srv_phb_pbapc_convert_name_ex(srv_phb_pbapc_name_struct *name, U8 order, U16 *cov, U16 len, U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 temp_name[SRV_PHB_PBAPC_NAME_LENGTH + 1] = { L'\0' };
    U32 old_len = len;
    U16 *name_1;
    U16 *name_2;
    U16 separator;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_wcsncpy((WCHAR *)temp_name, name->mid, SRV_PHB_PBAPC_NAME_LENGTH);
    mmi_wcsncat((WCHAR *)(temp_name + mmi_wcslen(temp_name)), name->given, SRV_PHB_PBAPC_NAME_LENGTH - mmi_wcslen(temp_name));

    switch (order)
    {
        case SRV_PHB_PBAPC_NAME_ORDER_1:
        {
            name_1 = name->family;
            name_2 = temp_name;
            separator = ' ';
            break;
        }

        case SRV_PHB_PBAPC_NAME_ORDER_2:
        {
            name_1 = temp_name;
            name_2 = name->family;
            separator = ' ';
            break;
        }

        default:
        {
            name_1 = name->family;
            name_2 = temp_name;
            separator = ' ';
            break;
        }
    }

    if (name_1 || name_2)
    {
        if (name_1)
        {
            while (len && *name_1)
            {
                *(cov++) = *(name_1++);
                len--;
            }
        }
        if ((len > 1) && (old_len != len) && name_2 && *name_2)
        {
            *(cov++) = separator;
            len--;
        }
        if (name_2)
        {
            while (len && *name_2)
            {
                *(cov++) = *(name_2++);
                len--;
            }
        }
    }
    *cov = L'\0';

    return old_len - len;
}

#endif /* __SRV_PHB_PBAPC_NAME_ORDER__ */

#endif /* defined(__BT_PBAP_CLIENT__) */

