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
 *  PbapcSrv.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  new pbapc srv, support multi links
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__

#if defined(__BT_PBAP_CLIENT__)

#include "PbapcSrv.h"
#include "wgui_softkeys.h"
#include "DebugInitDef_Int.h"
#include "MMI_conn_app_trc.h"

#include "MMI_trc_Int.h"


/* global cntx */
static srv_pbapc_btd_mgr_struct srv_pbapc_btd_mgr;

static srv_pbapc_context_struct g_srv_pbapc_cntx;

U16 auth_scr_ui_buff[MMI_PBAPC_AUTH_UI_BUFF_SIZE / 2];


/*****************************************************************************
* FUNCTION
*  srv_pbapc_init
* DESCRIPTION
*  Initialize PCE context structures and sets event handlers.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_init() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_cntx_init();
    srv_pbapc_protocol_init();
}


static void srv_pbapc_bt_event_notify_handle(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case SRV_BT_CM_EVENT_MYDEV_DEL:
        {
            srv_bt_cm_mydev_del_struct *mydev_del = (srv_bt_cm_mydev_del_struct *) para;
            srv_pbapc_btd_struct *btd = NULL;

            if (mydev_del->result)
            {
                btd = srv_pbapc_get_btd_from_bt_addr(&(mydev_del->del_dev->bd_addr), SRV_PBAPC_FLAG_USED);

                /* reset btd */
                if (btd)
                {
                    srv_pbapc_notify_event_struct notify_evt;
                    srv_pbapc_del_btd_struct del_btd;

                    /* evt */
                    MMI_FRM_INIT_EVENT(&notify_evt, EVT_ID_PBAP_NOTIFY);

                    del_btd.bt_index = btd->index;
                    notify_evt.data = (void *)&del_btd;
                    notify_evt.type = EVT_ID_PBAPC_DEL_BTD;
                    notify_evt.bt_index = btd->index;

                    memset(btd, 0x00, sizeof(srv_pbapc_btd_struct));

                    MMI_FRM_CB_EMIT_EVENT(&notify_evt);
                }
            }

            break;
        }

        default:
            break;
   }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_cntx_init
* DESCRIPTION
* Initialize PCE context structures.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_cntx_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_profile_struct profile_info;
    S32 fp = -1;
    S32 ret = SRV_PBAPC_RET_OK, i = 0;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    extern void mmi_bt_dialor_callback(srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect);
    extern mmi_ret srv_phb_pbapc_bt_notify(mmi_event_struct *evt);
    U32 event_mask;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    /* work folder init */
    fp = FS_Open(PBAPC_ADP_WORK_FOLDER, FS_OPEN_DIR | FS_READ_ONLY);
    if (fp < 0)
    {
        if (FS_CreateDir(PBAPC_ADP_WORK_FOLDER) < 0)
        {
            ret = SRV_PBAPC_RET_FAIL;
        }
    }
    else
    {
        FS_Close(fp);
    }

    /* reset all */
    memset(srv_pbapc_p, 0x00, sizeof(srv_pbapc_context_struct));
    memset(&srv_pbapc_btd_mgr, 0x00, sizeof(srv_pbapc_btd_mgr_struct));

    /* global init */
    srv_pbapc_p->cur_state = SRV_PBAPC_STATE_IDLE;
    srv_pbapc_p->cm_app_cb = mmi_bt_dialor_callback;
    srv_pbapc_p->pbapc_cb_func = srv_phb_pbapc_bt_notify;
    srv_pbapc_p->btd_mgr = &srv_pbapc_btd_mgr;

    /* pbapc handle init */
    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        srv_pbapc_p->handle[i].path = PBAPC_PATH_INVALID;
        srv_pbapc_p->handle[i].cm_conn_id = SRV_PBAPC_INVALID_CM_ID;
        srv_pbapc_p->handle[i].goep_conn_id = SRV_PBAPC_INVALID_CM_ID;
        srv_pbapc_p->handle[i].state = SRV_PBAPC_STATE_IDLE;
    }

    profile_info.profile_id = SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID;
    profile_info.activater = srv_pbapc_enable_req;
    profile_info.deactivater = srv_pbapc_disable_req;
    profile_info.disconnector = srv_pbapc_disconnect_from_cm_id;

    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&profile_info);

    event_mask = SRV_BT_CM_EVENT_MYDEV_DEL;

    srv_pbapc_p->cm_handle = srv_bt_cm_set_notify(srv_pbapc_bt_event_notify_handle, event_mask, (void *)0xbabe);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_CNTX_INIT, ret);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_protocol_init
* DESCRIPTION
*  Sets event handler for messages from PBAP ADP.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_protocol_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_enable_cnf_hdlr, MSG_ID_BT_PBAPC_ENABLE_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disable_cnf_hdlr, MSG_ID_BT_PBAPC_DISABLE_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_set_path_cnf_hdlr, MSG_ID_BT_PBAPC_SET_PATH_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_read_folder_cnf_hdlr, MSG_ID_BT_PBAPC_READ_FOLDER_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_read_entry_cnf_hdlr, MSG_ID_BT_PBAPC_READ_ENTRY_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_read_list_cnf_hdlr, MSG_ID_BT_PBAPC_READ_LIST_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_connect_cnf_hdlr, MSG_ID_BT_PBAPC_CONNECT_CNF);

    SetProtocolEventHandler((PsFuncPtr)srv_pbapc_auth_ind_hdlr, MSG_ID_BT_PBAPC_AUTH_CHALLENGE_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disconnect_ind_hdlr, MSG_ID_BT_PBAPC_DISCONNECT_IND);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_disconnect_cnf_hdlr, MSG_ID_BT_PBAPC_DISCONNECT_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_abort_cnf_hdlr, MSG_ID_BT_PBAPC_ABORT_CNF);

    SetProtocolEventHandler((PsFuncPtr) srv_pbapc_abort_ind_hdlr, MSG_ID_BT_PBAPC_ABORT_IND);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_deinit
* DESCRIPTION
*  Resets PCE Context structures.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_cntx
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_context_struct *srv_pbapc_get_cntx() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_srv_pbapc_cntx;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_handle_from_cm_id
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_cm_id(U32 cm_id) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        if (srv_pbapc_p->handle[i].cm_conn_id == cm_id)
        {
            pbapc_handle = &(srv_pbapc_p->handle[i]);

            break;
        }
    }

    return pbapc_handle;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_handle_from_goep_id
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_goep_id(U32 goep_id) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        if (srv_pbapc_p->handle[i].goep_conn_id == goep_id)
        {
            pbapc_handle = &(srv_pbapc_p->handle[i]);

            break;
        }
    }

    return pbapc_handle;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_handle_from_bt_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_handle_struct *srv_pbapc_get_handle_from_bt_addr(srv_bt_cm_bt_addr *bt_addr) 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        if (srv_pbapc_p->handle[i].bt_addr.lap == bt_addr->lap &&
            srv_pbapc_p->handle[i].bt_addr.uap == bt_addr->uap &&
            srv_pbapc_p->handle[i].bt_addr.nap == bt_addr->nap)
        {
            pbapc_handle = &(srv_pbapc_p->handle[i]);

            break;
        }
    }

    return pbapc_handle;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_reset_handle
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_pbapc_reset_handle(srv_pbapc_handle_struct *pbapc_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(pbapc_handle, 0x00, sizeof(srv_pbapc_handle_struct));
    pbapc_handle->state = SRV_PBAPC_STATE_IDLE;
    pbapc_handle->path = PBAPC_PATH_INVALID;
    pbapc_handle->goep_conn_id = SRV_PBAPC_INVALID_CM_ID;
    pbapc_handle->cm_conn_id = SRV_PBAPC_INVALID_CM_ID;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_change_state
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_pbapc_change_state(srv_pbapc_handle_struct *hd, U8 state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    hd->state = state;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_free_handle
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_handle_struct *srv_pbapc_get_free_handle() 
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        if(!(srv_pbapc_p->handle[i].flag & SRV_PBAPC_FLAG_USED))
        {
            pbapc_handle = &(srv_pbapc_p->handle[i]);
            pbapc_handle->flag |= SRV_PBAPC_FLAG_USED;

            break;
        }
    }

    MMI_ASSERT(pbapc_handle);

    return pbapc_handle;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_path
* DESCRIPTION
*  Get string path for enum path.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 static void srv_pbapc_get_path(srv_pbapc_path_enum path , kal_int8 *name)
 {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(path)
    {
        case PBAPC_PATH_SIM:
            app_strlcpy((kal_char *)name, (kal_char *)"SIM1", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_TELECOM:
            app_strlcpy((kal_char *)name, (kal_char *)"telecom", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_PHONEBOOK:
            app_strlcpy((kal_char *)name, (kal_char *)"pb", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_INCOMING:
            app_strlcpy((kal_char *)name, (kal_char *)"ich", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_OUTGOING:
            app_strlcpy((kal_char *)name, (kal_char *)"och", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_MISSED:
            app_strlcpy((kal_char *)name, (kal_char *)"mch", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_COMBINED:
            app_strlcpy((kal_char *)name, (kal_char *)"cch", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_SIM_PHONEBOOK:
            app_strlcpy((kal_char *)name, (kal_char *)"pb", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_SIM_INCOMING:
            app_strlcpy((kal_char *)name, (kal_char *)"ich", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_SIM_OUTGOING:
            app_strlcpy((kal_char *)name, (kal_char *)"och", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_SIM_MISSED:
            app_strlcpy((kal_char *)name, (kal_char *)"mch", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_SIM_COMBINED:
            app_strlcpy((kal_char *)name, (kal_char*)"cch", PBAP_MAX_NAME_LEN / 2 + 1);
            break;
        case PBAPC_PATH_PB_TELECOM:
            app_strlcpy((kal_char *)name, (kal_char *)"cch", PBAP_MAX_NAME_LEN / 2 + 1);  
            break;
        case PBAPC_PATH_SIM_TELECOM:
            app_strlcpy((kal_char *)name, (kal_char *)"cch", PBAP_MAX_NAME_LEN / 2 + 1);  
            break;
        default:
            name = NULL;
            break;
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_check_bt_index
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static S32 srv_pbapc_check_para(U8 type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_bt_addr *bt_addr = NULL;
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    switch (type)
    {
        case SRV_PBAPC_JOB_CONNECT:
        {
            bt_addr = (srv_bt_cm_bt_addr *) para;
            pbapc_handle = srv_pbapc_get_handle_from_bt_addr(bt_addr);

            /* connecting state */
            if (pbapc_handle && pbapc_handle->state == SRV_PBAPC_STATE_CONNECTING1)
            {
                ret = SRV_PBAPC_RET_FAIL;
            }
            else if (pbapc_handle && pbapc_handle->state > SRV_PBAPC_STATE_CONNECTING2)
            {
                ret = SRV_PBAPC_RET_CONNECTED;
            }
            else if (!srv_bt_cm_is_dev_in_link_table(bt_addr))
            {
                ret = SRV_PBAPC_RET_FORBID_CONNECT;
            }

            break;
        }

        case SRV_PBAPC_JOB_DISCONNECT:
        {
            bt_addr = (srv_bt_cm_bt_addr *) para;
            pbapc_handle = srv_pbapc_get_handle_from_bt_addr(bt_addr);
            if (!pbapc_handle)
            {
                ret = SRV_PBAPC_RET_FAIL;
            }
            else if (pbapc_handle && pbapc_handle->state == SRV_PBAPC_STATE_DISCONECTTING)
            {
                ret = SRV_PBAPC_RET_DISCONECTTING;
            }
            else if (pbapc_handle && pbapc_handle->goep_conn_id == SRV_PBAPC_INVALID_CM_ID)
            {
                ret = SRV_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PBAPC_JOB_SET_PATH:
        {
            srv_pbapc_set_path_req_struct *path_req = (srv_pbapc_set_path_req_struct *) para;

            if (!srv_pbapc_is_connect(path_req->bt_index))
            {
                ret = SRV_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PBAPC_JOB_READ_LIST:
        {
            srv_pbapc_read_list_req_struct *list_req = (srv_pbapc_read_list_req_struct *) para;

            if (!srv_pbapc_is_connect(list_req->bt_index))
            {
                ret = SRV_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PBAPC_JOB_READ_FOLDER:
        {
            srv_pbapc_read_folder_req_struct *folder_req = (srv_pbapc_read_folder_req_struct *) para;

            if (!srv_pbapc_is_connect(folder_req->bt_index))
            {
                ret = SRV_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        case SRV_PBAPC_JOB_READ_ENTRY:
        {
            srv_pbapc_read_entry_req_struct *entry_req = (srv_pbapc_read_entry_req_struct *) para;

            if (!srv_pbapc_is_connect(entry_req->bt_index))
            {
                ret = SRV_PBAPC_RET_DISCONNECTED;
            }

            break;
        }

        default:
            break;
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_CHECK_PARA, type, ret);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_enable_req
* DESCRIPTION
*  Register the PCE SDP database record 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_enable_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_ENABLE_REQ);

    srv_pbapc_send_msg(MSG_ID_BT_PBAPC_ENABLE_REQ, NULL);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_enable_cnf_hdlr
* DESCRIPTION
*  Handles enable response from Remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_enable_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_enable_cnf_struct *enable_rsp = (bt_pbapc_enable_cnf_struct*)ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_activate_cnf_hdler((U32) SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disable_req
* DESCRIPTION
*  Removes  PCE SDP database record .
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disable_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISABLE_REQ);

    srv_pbapc_send_msg(MSG_ID_BT_PBAPC_DISABLE_REQ, NULL);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disable_cnf_hdlr
* DESCRIPTION
* Handles disable response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disable_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_disable_cnf_struct *deregister_rsp = (bt_pbapc_disable_cnf_struct*)ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_deactivate_cnf_hdler((U32)SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_path_req
* DESCRIPTION
*  Sets path on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
S32 srv_pbapc_set_path_req(srv_pbapc_set_path_req_struct *path_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    bt_pbapc_set_path_req_struct *set_path_req;
    U8 name[PBAP_MAX_NAME_LEN / 2 + 1] = {'\0'};
    U8 path;
    srv_bt_cm_bt_addr bt_addr;
    S32 ret = SRV_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    path = path_req->path;

    /* check para & cur pbapc srv state */
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_SET_PATH, path_req);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_get_btd_addr(&bt_addr, path_req->bt_index);
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

        /* copy path req */
        memcpy(&(pbapc_handle->path_req), path_req, sizeof(srv_pbapc_set_path_req_struct));

        path = path_req->path;

        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_SET_PATH_REQ1, path_req->path);

        if(path >= PBAPC_PATH_PHONEBOOK && path <= PBAPC_PATH_PB_TELECOM && pbapc_handle->path == PBAPC_PATH_INVALID)
        {
            path += PBAPC_PATH_TELECOM;
        }
        else if(path >= PBAPC_PATH_SIM_PHONEBOOK && path <= PBAPC_PATH_SIM_TELECOM && pbapc_handle->path == PBAPC_PATH_INVALID)
        {
            path += PBAPC_PATH_SIM + PBAPC_PATH_TELECOM;
        }
        else if(path > PBAPC_PATH_SIM + PBAPC_PATH_TELECOM + PBAPC_PATH_ROOT)
        {
            path -= PBAPC_PATH_SIM;
            srv_pbapc_get_path(PBAPC_PATH_SIM,name);
        }
        else if(path > PBAPC_PATH_TELECOM + PBAPC_PATH_ROOT)
        {
            path -= PBAPC_PATH_TELECOM;
            srv_pbapc_get_path(PBAPC_PATH_TELECOM,name);
        }
        else 
        {
            srv_pbapc_get_path(path, name);
            path = PBAPC_PATH_INVALID;
        }

        pbapc_handle->path = path;

        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_SET_PATH_REQ2, pbapc_handle->path);
        /* update next path */
        pbapc_handle->path_req.path = path;

        set_path_req = (bt_pbapc_set_path_req_struct*)OslConstructDataPtr(sizeof(bt_pbapc_set_path_req_struct));

        memset(set_path_req->name, 0x00, PBAP_MAX_NAME_LEN / 2 + 1);

        set_path_req->type = path_req->folder_type;
        set_path_req->conn_id = pbapc_handle->goep_conn_id;

        if(name[0] != '\0')
        {
            app_asc_str_n_to_ucs2_str((U8 *)set_path_req->name, (U8 *)name, PBAP_MAX_NAME_LEN / 4);
        }
        else
        {
            /* first */
            set_path_req->type = PBAP_ROOT_FOLDER;
        }

        /* change state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_SETTING_PATH);

        srv_pbapc_send_msg(MSG_ID_BT_PBAPC_SET_PATH_REQ, (void *)set_path_req);
    }
    else
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
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_path_cnf_hdlr
* DESCRIPTION
*  Hnadles set path response from remote device  nad sends set path request if path still left.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_set_path_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    bt_pbapc_set_path_cnf_struct *path_cnf = (bt_pbapc_set_path_cnf_struct*)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_set_path_rsp_struct path_rsp;
    srv_pbapc_set_path_req_struct *path_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(path_cnf->conn_id);
    path_req = &(pbapc_handle->path_req);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_SET_PATH_CNF_HDLR, path_cnf->cnf_code, path_req->path, path_req->bt_index);

    if(path_cnf->cnf_code == GOEP_STATUS_SUCCESS && path_req->path != PBAPC_PATH_INVALID)
    {
        srv_pbapc_set_path_req(path_req);
    }
    else
    {
        if (path_cnf->cnf_code == GOEP_STATUS_SUCCESS)
        {
            path_rsp.ret = SRV_PBAPC_RET_OK;
        }
        else
        {
            path_rsp.ret = SRV_PBAPC_RET_FAIL;
        }


        notify_evt.data = (void *)&path_rsp;
        notify_evt.type = EVT_ID_PBAPC_SET_PATH_RSP;
        notify_evt.bt_index = pbapc_handle->path_req.bt_index;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_SET_PATH);

        pbapc_handle->path = PBAPC_PATH_INVALID;
        path_req->path = PBAPC_PATH_INVALID;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_folder_req
* DESCRIPTION
*  Sends read folder request on remote device.
* PARAMETERS
*  
* RETURNS
*  void
*****************************************************************************/
S32 srv_pbapc_read_folder_req(srv_pbapc_read_folder_req_struct *folder_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    bt_pbapc_read_folder_req_struct *read_folder_req = NULL;
    srv_bt_cm_bt_addr bt_addr;
    S32 ret = SRV_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    /* check para & cur pbapc srv state */
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_READ_FOLDER, folder_req);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_get_btd_addr(&bt_addr, folder_req->bt_index);
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

        read_folder_req = (bt_pbapc_read_folder_req_struct *)OslConstructDataPtr(sizeof(bt_pbapc_read_folder_req_struct));

        memset(read_folder_req->pbap_data_file, 0, BT_PBAP_MAX_FILEPATH_NAME_LEN);

        memset(read_folder_req->folderName, 0, PBAP_MAX_NAME_LEN / 2 + 1);

        mmi_ucs2ncpy((CHAR *)read_folder_req->pbap_data_file, (CHAR *)PBAPC_ADP_FOLDER_FILE, BT_PBAP_MAX_FILEPATH_NAME_LEN);

        if(folder_req->name)
        {
            mmi_ucs2ncpy((CHAR *)read_folder_req->folderName, (CHAR *)(folder_req->name), PBAP_MAX_NAME_LEN / 2 + 1);
        }

        kal_mem_cpy((kal_uint8 *)read_folder_req->filter.byte, (kal_uint8 *)((folder_req->filter).byte), PBAP_FILTER_SIZE);

        read_folder_req->format = folder_req->format;
        read_folder_req->maxListCount = folder_req->count;
        read_folder_req->listStartOffset = folder_req->offset;

        /* goep conn id */
        read_folder_req->conn_id = pbapc_handle->goep_conn_id;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_READ_FOLDER);

        srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_FOLDER_REQ, (void *)read_folder_req);

        {
            extern S32 g_pbap_bqb_flag;

            if (srv_bt_cm_get_bqb_test_flag() && g_pbap_bqb_flag == 1)
            {
                srv_pbapc_bqb_abort_req();
            }
        }
    }
    else
    {
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_folder_cnf_hdlr
* DESCRIPTION
*  Handles read folder response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_read_folder_cnf_hdlr(void * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_read_folder_cnf_struct *read_folder_cnf = (bt_pbapc_read_folder_cnf_struct *)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_read_folder_rsp_struct folder_rsp;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p= srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(read_folder_cnf->conn_id);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_FLD_HDLR, srv_pbapc_p->cur_state, pbapc_handle);

    if (pbapc_handle)
    {
        //kal_wap_trace(MOD_MMI_CONN_APP, SRV_PBAPC_TRACE_GROUP, "[SrvPbapc]read_folder_cnf_hdlr--hd_state: %d\n", pbapc_handle->state);
        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_FLD_HDLR,  pbapc_handle->state);

        /* get index from bt addr */
        bt_index = srv_pbapc_get_btd_index(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        if(read_folder_cnf->cnf_code == GOEP_STATUS_SUCCESS)
        {
            folder_rsp.ret = SRV_PBAPC_RET_OK;
        }
        else
        {
            folder_rsp.ret = SRV_PBAPC_RET_FAIL;
        }

        folder_rsp.newMissedCalls = read_folder_cnf->newMissedCalls;
        folder_rsp.phoneBookSize = read_folder_cnf->phoneBookSize;

        notify_evt.data = (void *)&folder_rsp;
        notify_evt.type = EVT_ID_PBAPC_READ_FOLDER_RSP;
        notify_evt.bt_index = bt_index;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_list_req
* DESCRIPTION
*  Sends read list request on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
S32 srv_pbapc_read_list_req(srv_pbapc_read_list_req_struct *list_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    bt_pbapc_read_list_req_struct *read_list_req = NULL;
    srv_bt_cm_bt_addr bt_addr;
    S32 ret = SRV_PBAPC_RET_OK;
    U8 len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    /* check para & cur pbapc srv state */
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_READ_LIST, list_req);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_get_btd_addr(&bt_addr, list_req->bt_index);
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

        read_list_req = (bt_pbapc_read_list_req_struct *)OslConstructDataPtr(sizeof(bt_pbapc_read_list_req_struct));

        memset(read_list_req->pbap_data_file, 0,BT_PBAP_MAX_FILEPATH_NAME_LEN);
        memset(read_list_req->folderName, 0, PBAP_MAX_NAME_LEN / 2 + 1);
        memset(read_list_req->searchValue, 0, MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH + 1);

        //app_ucs2_wcsncpy((kal_wchar *)read_list_req->pbap_data_file, (kal_wchar *)PBAPC_ADP_LIST_FILE, BT_PBAP_MAX_FILEPATH_NAME_LEN / 2);       
        mmi_ucs2ncpy((CHAR *)read_list_req->pbap_data_file, (CHAR *)PBAPC_ADP_LIST_FILE, BT_PBAP_MAX_FILEPATH_NAME_LEN);

        if(list_req->name)
        {
            app_ucs2_wcsncpy((kal_wchar *)read_list_req->folderName, (kal_wchar *)(list_req->name), PBAP_MAX_NAME_LEN / 4);    
        }

        if(list_req->length < MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH)
        {
            len = list_req->length;
        }
        else
        {
            len = MAX_PBAP_CLIENT_SEARCH_VALUE_LENGTH;
        }
        if(list_req->value)
        {
            kal_mem_cpy((kal_int8 *)read_list_req->searchValue, (kal_int8 *)(list_req->value), len);     
        }

        read_list_req->searchValueLength = len ;
        read_list_req->order = list_req->order;
        read_list_req->maxListCount = list_req->count;
        read_list_req->listStartOffset = list_req->offset;
        read_list_req->searchAttribute = list_req->attribute;

        /* goep conn id */
        read_list_req->conn_id = pbapc_handle->goep_conn_id;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_READ_LIST);

        srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_LIST_REQ, (void *)read_list_req);

    }
    else
    {
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_list_cnf_hdlr
* DESCRIPTION
*  Handles read list response from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_read_list_cnf_hdlr(void * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_read_list_cnf_struct *read_list_cnf = (bt_pbapc_read_list_cnf_struct *)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_read_list_rsp_struct list_rsp;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p= srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(read_list_cnf->conn_id);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_LIST_CNF, srv_pbapc_p->cur_state, pbapc_handle);

    if (pbapc_handle)
    {
        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_LIST_CNF_I, pbapc_handle->state);
        /* get index from bt addr */
        bt_index = srv_pbapc_get_btd_index(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        if(read_list_cnf->cnf_code == GOEP_STATUS_SUCCESS)
        {
            list_rsp.ret = SRV_PBAPC_RET_OK;
        }
        else
        {
            list_rsp.ret = SRV_PBAPC_RET_FAIL;
        }

        list_rsp.newMissedCalls = read_list_cnf->newMissedCalls;
        list_rsp.phoneBookSize = read_list_cnf->phoneBookSize;

        notify_evt.data = (void *)&list_rsp;
        notify_evt.type = EVT_ID_PBAPC_READ_LIST_RSP;
        notify_evt.bt_index = bt_index;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_entry_req
* DESCRIPTION
*  Sends read entry request on remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
S32 srv_pbapc_read_entry_req(srv_pbapc_read_entry_req_struct *entry_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    bt_pbapc_read_entry_req_struct *read_entry_req = NULL;
    srv_bt_cm_bt_addr bt_addr;
    S32 ret = SRV_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    /* check para & cur pbapc srv state */
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_READ_ENTRY, entry_req);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_get_btd_addr(&bt_addr, entry_req->bt_index);
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

        read_entry_req = (bt_pbapc_read_entry_req_struct *)OslConstructDataPtr(sizeof(bt_pbapc_read_entry_req_struct));

        memset(read_entry_req->pbap_data_file, 0, BT_PBAP_MAX_FILEPATH_NAME_LEN);
        memset(read_entry_req->objectName, 0, PBAP_MAX_NAME_LEN / 2 + 1);

        //app_ucs2_wcsncpy((kal_wchar *)read_entry_req->pbap_data_file, (kal_wchar *)PBAPC_ADP_ENTRY_FILE, BT_PBAP_MAX_FILEPATH_NAME_LEN / 2);
        mmi_ucs2ncpy((CHAR *)read_entry_req->pbap_data_file, (CHAR *)PBAPC_ADP_ENTRY_FILE, BT_PBAP_MAX_FILEPATH_NAME_LEN);

        if(entry_req->name)
        {
            app_ucs2_wcsncpy((kal_wchar *)read_entry_req->objectName, (kal_wchar *) (entry_req->name), PBAP_MAX_NAME_LEN / 4);
        }

        kal_mem_cpy((char *)read_entry_req->filter.byte, (char *)(entry_req->filter).byte, PBAP_FILTER_SIZE);
        read_entry_req->format = entry_req->format;

        /* goep conn id */
        read_entry_req->conn_id = pbapc_handle->goep_conn_id;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_READ_ENTRY);

        srv_pbapc_send_msg(MSG_ID_BT_PBAPC_READ_ENTRY_REQ, (void *)read_entry_req);
    }
    else
    {
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_read_entry_cnf_hdlr
* DESCRIPTION
*  Handles read entry response from remote dvice.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_read_entry_cnf_hdlr(void * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_read_entry_cnf_struct *read_entry_cnf = (bt_pbapc_read_entry_cnf_struct*)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_read_entry_rsp_struct entry_rsp;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p= srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(read_entry_cnf->conn_id);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_ENTRY_HD, srv_pbapc_p->cur_state, pbapc_handle);

    if (pbapc_handle)
    {
        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_RD_ENTRY_HD_I);
        /* get index from bt addr */
        bt_index = srv_pbapc_get_btd_index(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        if(read_entry_cnf->cnf_code == GOEP_STATUS_SUCCESS)
        {
            entry_rsp.ret = SRV_PBAPC_RET_OK;
        }
        else
        {
            entry_rsp.ret = SRV_PBAPC_RET_FAIL;
        }

        notify_evt.data = (void *)&entry_rsp;
        notify_evt.type = EVT_ID_PBAPC_READ_ENTRY_RSP;
        notify_evt.bt_index = bt_index;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_req
* DESCRIPTION
*  Sends abort request to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
 static void srv_pbapc_abort_req(U32 goep_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_abort_req_struct *abort_req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    abort_req = (bt_pbapc_abort_req_struct *)OslConstructDataPtr(sizeof(bt_pbapc_abort_req_struct));
    abort_req->conn_id = goep_id;

    srv_pbapc_send_msg(MSG_ID_BT_PBAPC_ABORT_REQ, (void *)abort_req);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_ind_hdlr
* DESCRIPTION
*  Handles abort indication from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_abort_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_abort_cnf_hdlr
* DESCRIPTION
*  Handles abort confirmation from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_abort_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_abort_cnf_struct *abort_cnf = (bt_pbapc_abort_cnf_struct *)ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_connect_req
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_pbapc_connect_req(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_connect_req_struct *connect_req = NULL;
    S32 cm_conn_id = -1;
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    /* add bt addr in btd mgr */
    srv_pbapc_btd_push(bt_addr);

    cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID, bt_addr, NULL);

    if (cm_conn_id < 0)
    {
        /* notify cm app */
        srv_pbapc_p->cm_app_cb(bt_addr, SRV_BT_CM_PBAPC_CONNECTION, MMI_FALSE, MMI_TRUE, MMI_FALSE);

        ret = SRV_PBAPC_RET_FAIL;
    }
    else
    {
        pbapc_handle = srv_pbapc_get_free_handle();

        /* set handle */
        pbapc_handle->bt_addr.lap = bt_addr->lap;
        pbapc_handle->bt_addr.uap = bt_addr->uap;
        pbapc_handle->bt_addr.nap = bt_addr->nap;
        pbapc_handle->cm_conn_id = cm_conn_id;

        connect_req = (bt_pbapc_connect_req_struct*)construct_local_para(sizeof(bt_pbapc_connect_req_struct), TD_CTRL);

        connect_req->bd_addr.lap = bt_addr->lap;
        connect_req->bd_addr.uap = bt_addr->uap;
        connect_req->bd_addr.nap = bt_addr->nap;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_CONNECTING1);

        srv_pbapc_p->cur_state = SRV_PBAPC_STATE_CONNECTING1;

        srv_bt_cm_set_dev_busy_state(bt_addr, SRV_BT_CM_PBAPC_CONNECTION, MMI_TRUE);

        srv_pbapc_send_msg(MSG_ID_BT_PBAPC_CONNECT_REQ, connect_req);
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_CONNECT_REQ, ret);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_connect_cnf_hdlr
* DESCRIPTION
* Handles conncet confirmation from remote device.
* PARAMETERSf
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_connect_cnf_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    bt_pbapc_connect_cnf_struct *connect_cnf = (bt_pbapc_connect_cnf_struct *)ilm_ptr;
    srv_bt_cm_bt_addr bt_addr;
    MMI_BOOL ret = MMI_FALSE;
    srv_pbapc_btd_struct *btd = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_connect_rsp_struct connect_rsp;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    bt_addr.lap = connect_cnf->bd_addr.lap;
    bt_addr.uap = connect_cnf->bd_addr.uap;
    bt_addr.nap = connect_cnf->bd_addr.nap;

    pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_CONN_HD, srv_pbapc_p->cur_state, pbapc_handle);

    srv_bt_cm_set_dev_busy_state(&bt_addr, SRV_BT_CM_PBAPC_CONNECTION, MMI_FALSE);

    /* update state */
    srv_pbapc_p->cur_state = SRV_PBAPC_STATE_IDLE;

    if(connect_cnf->cnf_code == GOEP_STATUS_SUCCESS)
    {
        srv_bt_cm_connect_ind(pbapc_handle->cm_conn_id);

        pbapc_handle->goep_conn_id = connect_cnf->conn_id;

        /* add connected flag */
        //srv_pbapc_p->cur_btd->flag |= SRV_PBAPC_FLAG_CONNECTED;
        btd = srv_pbapc_get_btd_from_bt_addr(&bt_addr, SRV_PBAPC_FLAG_USED);
        btd->flag |= SRV_PBAPC_FLAG_CONNECTED;

        ret = MMI_TRUE;

        /* update state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_CONNECTED);
    }
    else
    {
        srv_bt_cm_stop_conn(pbapc_handle->cm_conn_id);

        srv_pbapc_reset_handle(pbapc_handle);
    }

    if(srv_bt_cm_check_dev_profile_support_status(&bt_addr, SRV_BT_CM_OBEX_PBA_PROFILE_CLIENT_UUID))
    {
        pbapc_handle->flag |= SRV_PBAPC_FLAG_SUPPORT;
    }

    srv_pbapc_p->cm_app_cb(&bt_addr, SRV_BT_CM_PBAPC_CONNECTION, ret, MMI_TRUE, MMI_FALSE);

    /* reset cm app cb */
    srv_pbapc_p->cm_app_cb = mmi_bt_dialor_callback;

    /* evt */
    MMI_FRM_INIT_EVENT(&notify_evt, EVT_ID_PBAP_NOTIFY);

    bt_index = srv_pbapc_get_btd_index(&bt_addr, SRV_PBAPC_FLAG_USED);
    /* set notfiy evt struct */
    connect_rsp.ret = (connect_cnf->cnf_code == PBAP_CNF_SUCCESS) ? (SRV_PBAPC_RET_OK) : (SRV_PBAPC_RET_FAIL);

    btd = srv_pbapc_get_btd_from_bt_addr(&bt_addr, SRV_PBAPC_FLAG_USED);

    if (btd->flag & SRV_PBAPC_FLAG_NEW_BTD)
    {
        connect_rsp.new_btd = MMI_TRUE;
    }
    else
    {
        connect_rsp.new_btd = MMI_FALSE;
    }

    notify_evt.data = (void *)&connect_rsp;
    notify_evt.type = EVT_ID_PBAPC_CONNECT_RSP;
    notify_evt.bt_index = bt_index;

    /* BQB mode, don't notfiy connect evt */
    if (!srv_bt_cm_get_bqb_test_flag())
    {
    /* notify phb srv */
    srv_pbapc_p->pbapc_cb_func(&notify_evt);

    MMI_FRM_CB_EMIT_EVENT(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_from_cm_id
* DESCRIPTION
* 
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_from_cm_id(U32 cm_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_handle_struct *pbapc_handle;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pbapc_handle = srv_pbapc_get_handle_from_cm_id(cm_id);

    srv_pbapc_disconnect_req(pbapc_handle->goep_conn_id);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_req
* DESCRIPTION
*  Sends disconnect request to remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_req(U32 goep_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_disconnect_req_struct *disconnect_req;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    disconnect_req = (bt_pbapc_disconnect_req_struct *)OslConstructDataPtr(sizeof(bt_pbapc_disconnect_req_struct));
    disconnect_req->conn_id = goep_id;

    pbapc_handle = srv_pbapc_get_handle_from_goep_id(goep_id);

    //srv_pbapc_p->cur_btd = srv_pbapc_get_btd_from_bt_addr(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

    /* change state */
    srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_DISCONECTTING);

    srv_pbapc_send_msg(MSG_ID_BT_PBAPC_DISCONNECT_REQ, (void *)disconnect_req);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_cnf_hdlr
* DESCRIPTION
*  Hanldes disconnect confirmation from remote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_cnf_hdlr(void * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_disconnect_cnf_struct *disconnect_cnf = (bt_pbapc_disconnect_cnf_struct*)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    U8 bt_index;
    srv_pbapc_disconnect_rsp_struct disconnect_rsp;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    MMI_BOOL ret = MMI_FALSE;
    srv_bt_cm_bt_addr bt_addr;
    srv_pbapc_btd_struct *btd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(disconnect_cnf->conn_id);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISCONN_HD, srv_pbapc_p->cur_state, pbapc_handle);
    if (pbapc_handle && pbapc_handle->state == SRV_PBAPC_STATE_DISCONECTTING)
    {
        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISCONN_HD_I, pbapc_handle->state);

        /* save bt_addr */
        bt_addr.lap = pbapc_handle->bt_addr.lap;
        bt_addr.uap = pbapc_handle->bt_addr.uap;
        bt_addr.nap = pbapc_handle->bt_addr.nap;

        /* get index from bt addr */
        bt_index = srv_pbapc_get_btd_index(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        /* notfiy cm srv */
        srv_bt_cm_stop_conn(pbapc_handle->cm_conn_id);

        /* remove connected flag */
        //srv_pbapc_p->cur_btd->flag &= ~SRV_PBAPC_FLAG_CONNECTED;
        btd = srv_pbapc_get_btd_from_bt_addr(&bt_addr, SRV_PBAPC_FLAG_CONNECTED);
        btd->flag &= ~SRV_PBAPC_FLAG_CONNECTED;
        /* add reset btd, for can't disconnect pbap */
        //memset(btd, 0x00, sizeof(srv_pbapc_btd_struct));

        /* reset pbapc handle */
        srv_pbapc_reset_handle(pbapc_handle);

        /* evt */
        MMI_FRM_INIT_EVENT(&notify_evt, EVT_ID_PBAP_NOTIFY);

        /* set notfiy evt struct */
        disconnect_rsp.ret = (disconnect_cnf->cnf_code == PBAP_CNF_SUCCESS) ? (SRV_PBAPC_RET_OK) : (SRV_PBAPC_RET_FAIL);
        ret = (disconnect_cnf->cnf_code == PBAP_CNF_SUCCESS) ? (MMI_TRUE) : (MMI_FALSE);

        if (disconnect_cnf->cnf_code == PBAP_CNF_WRONG_CONN_NUM)
        {
            ret = MMI_TRUE;
            disconnect_rsp.ret = SRV_PBAPC_RET_OK;
        }

        notify_evt.data = (void *)&disconnect_rsp;
        notify_evt.type = EVT_ID_PBAPC_DISCONNECT_RSP;
        notify_evt.bt_index = bt_index;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);

        /* notify cm app */
        srv_pbapc_p->cm_app_cb(&bt_addr, SRV_BT_CM_PBAPC_CONNECTION, ret, MMI_FALSE, MMI_FALSE);

        /* reset cm app cb */
        srv_pbapc_p->cm_app_cb = mmi_bt_dialor_callback;

        MMI_FRM_CB_EMIT_EVENT(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect_ind_hdlr
* DESCRIPTION
*  Handles disconnect indication from rote device.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_disconnect_ind_hdlr(void * ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_pbapc_disconnect_ind_struct *disconnect_ind = (bt_pbapc_disconnect_ind_struct*)ilm_ptr;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    U8 bt_index;
    srv_pbapc_disconnect_ind_struct disconnect_rsp;
    srv_pbapc_notify_event_struct notify_evt;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_bt_cm_bt_addr bt_addr;
    srv_pbapc_btd_struct *btd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_get_handle_from_goep_id(disconnect_ind->conn_id);

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISCONN_IND_HD, srv_pbapc_p->cur_state, pbapc_handle);

    if (pbapc_handle && pbapc_handle->state != SRV_PBAPC_STATE_DISCONECTTING)
    {
        MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISCONN_IND_HD_I, pbapc_handle->state);

        /* save bt_addr */
        bt_addr.lap = pbapc_handle->bt_addr.lap;
        bt_addr.uap = pbapc_handle->bt_addr.uap;
        bt_addr.nap = pbapc_handle->bt_addr.nap;

        /* get index from bt addr */
        bt_index = srv_pbapc_get_btd_index(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        /* get btd */
        btd = srv_pbapc_get_btd_from_bt_addr(&(pbapc_handle->bt_addr), SRV_PBAPC_FLAG_CONNECTED);

        /* remove connected flag */
        btd->flag &= ~SRV_PBAPC_FLAG_CONNECTED;
        /* add reset btd, for can't disconnect pbap */
        //memset(btd, 0x00, sizeof(srv_pbapc_btd_struct));

        /* notfiy cm srv */
        srv_bt_cm_stop_conn(pbapc_handle->cm_conn_id);

        /* reset pbapc handle */
        srv_pbapc_reset_handle(pbapc_handle);

        /* evt */
        MMI_FRM_INIT_EVENT(&notify_evt, EVT_ID_PBAP_NOTIFY);

        /* set notfiy evt struct */
        disconnect_rsp.ret = SRV_PBAPC_RET_OK;

        notify_evt.data = (void *)&disconnect_rsp;
        notify_evt.type = EVT_ID_PBAPC_DISCONNECT_IND;
        notify_evt.bt_index = bt_index;

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);

        /* notify cm app */
        srv_pbapc_p->cm_app_cb(&bt_addr, SRV_BT_CM_PBAPC_CONNECTION, MMI_TRUE, MMI_FALSE, MMI_TRUE);

        MMI_FRM_CB_EMIT_EVENT(&notify_evt);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_auth_ind_hdlr
* DESCRIPTION
*  Hanldes authentication indiaction from remote device
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_auth_ind_hdlr(void *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    srv_bt_cm_bt_addr bt_addr;
    bt_pbapc_auth_challenge_ind_struct *auth_ind = (bt_pbapc_auth_challenge_ind_struct *)ilm_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p= srv_pbapc_get_cntx();
    bt_addr.lap = auth_ind->bd_addr.lap;
    bt_addr.uap = auth_ind->bd_addr.uap;
    bt_addr.nap = auth_ind->bd_addr.nap;
    pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&bt_addr);

    srv_pbapc_p->cur_handle = pbapc_handle;

    /* change state */
    srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_AUTHORISE);

    mmi_pbapc_authentication_confirm_hdlr();
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_auth_rsp
* DESCRIPTION
* 
* PARAMETERS
* 
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_auth_rsp(S32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    bt_pbapc_auth_challenge_rsp_struct *auth_rsp = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    pbapc_handle = srv_pbapc_p->cur_handle;

    auth_rsp = (bt_pbapc_auth_challenge_rsp_struct *)OslConstructDataPtr(sizeof(bt_pbapc_auth_challenge_rsp_struct));

    memset(auth_rsp->password, 0, PBAP_MAX_PASSWORD_LEN);
    memset(auth_rsp->userId, 0, PBAP_MAX_USERID_LEN);

    if(1 == flag)
    {
        mmi_chset_ucs2_to_utf8_string((kal_uint8 *)auth_rsp->password, MMI_PBAPC_AUTH_UI_BUFF_SIZE, (kal_uint8 *)(srv_pbapc_p->password));
        auth_rsp->cancel = 0;
    }
    else
    {
        auth_rsp->cancel = 1;
    }

    auth_rsp->bd_addr.lap = pbapc_handle->bt_addr.lap;
    auth_rsp->bd_addr.uap = pbapc_handle->bt_addr.uap;
    auth_rsp->bd_addr.nap = pbapc_handle->bt_addr.nap;

    /* update state */
    srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_AUTHORIZED);

    srv_pbapc_send_msg(MSG_ID_BT_PBAPC_AUTH_CHALLENGE_RSP, (void *)auth_rsp);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_send_msg
* DESCRIPTION
*  Sends message to another module.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_send_msg(U32 msg_id, void *local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_cm_send_msg(MOD_BT, BT_PBAP_SAP, msg_id, (void *)local_para, NULL);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_connect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_connect(srv_bt_cm_bt_addr *bt_addr, srv_pbapc_cm_callback cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_cm_callback ori_cb = NULL;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_CONNECT, bt_addr);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_p = srv_pbapc_get_cntx();

        srv_pbapc_p->cm_app_cb = cm_cb;
        srv_pbapc_connect_req(bt_addr);
    }
    else
    {
        if (SRV_PBAPC_RET_CONNECTED == ret)
        {
            result = MMI_TRUE;
        }
        /* notify cm app */
        cm_cb(bt_addr, SRV_BT_CM_PBAPC_CONNECTION, result, MMI_TRUE, MMI_FALSE);
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_CONNECT, bt_addr->lap, bt_addr->uap, bt_addr->nap, cm_cb);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_disconnect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_disconnect(srv_bt_cm_bt_addr *bt_addr, srv_pbapc_cm_callback cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;
    MMI_BOOL result = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = srv_pbapc_check_para(SRV_PBAPC_JOB_DISCONNECT, bt_addr);

    if (SRV_PBAPC_RET_OK == ret)
    {
        srv_pbapc_p = srv_pbapc_get_cntx();
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(bt_addr);

        srv_pbapc_p->cm_app_cb = cm_cb;

        /* change state */
        srv_pbapc_change_state(pbapc_handle, SRV_PBAPC_STATE_DISCONECTTING);

        srv_pbapc_disconnect_req(pbapc_handle->goep_conn_id);
    }
    else
    {
        if (SRV_PBAPC_RET_DISCONECTTING == ret)
        {
            ;
        }
        else
        {
            result = MMI_TRUE;
        }
        /* cb */
        cm_cb(bt_addr, SRV_BT_CM_PBAPC_CONNECTION, result, MMI_FALSE, MMI_FALSE);
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_DISCONNECT, bt_addr->lap, bt_addr->uap, bt_addr->nap, cm_cb);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_cm_callback
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_set_cm_callback(srv_bt_cm_bt_addr *bt_addr, srv_pbapc_cm_callback cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    srv_pbapc_p->cm_app_cb = cm_cb;

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_query_func
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_set_query_func(srv_pbapc_query_func query_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 ret = SRV_PBAPC_RET_OK;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    srv_pbapc_p->query_func = query_func;

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_is_connect
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
MMI_BOOL srv_pbapc_is_connect(U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_btd_struct *btd = NULL;
    srv_pbapc_handle_struct *pbapc_handle = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    btd = &(srv_pbapc_p->btd_mgr->btd[bt_index]);

    if (btd->flag & SRV_PBAPC_FLAG_CONNECTED)
    {
        pbapc_handle = srv_pbapc_get_handle_from_bt_addr(&(btd->bt_addr));

        if (pbapc_handle &&
            pbapc_handle->state != SRV_PBAPC_STATE_DISCONECTTING)
        {
            ret = MMI_TRUE;
        }
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_IS_DISCONN, btd->flag, bt_index, ret);

    return ret;
}


#define BTD_MGR
/*****************************************************************************
* FUNCTION
*  srv_pbapc_set_cm_callback
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_pbapc_btd_push(srv_bt_cm_bt_addr *bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_btd_mgr_struct *btd_mgr = NULL;
    srv_pbapc_btd_struct *btd = NULL;
    S32 ret = SRV_PBAPC_RET_FAIL;
    S32 query = -1;
    srv_pbapc_query_req_struct *req = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    btd_mgr = srv_pbapc_p->btd_mgr;

    req = &(srv_pbapc_p->query_req);
    if (srv_pbapc_p->query_func)
    {
        query = srv_pbapc_p->query_func(req);
    }

    /* MMI can configure */
    if (query >= 0)
    {
        if (req->bt_index >= 0 && req->bt_index < SRV_PBAPC_LINK_NUM)
        {
            if(btd_mgr->btd[req->bt_index].flag & SRV_PBAPC_FLAG_CONNECTED)
            {
                EXT_ASSERT(0, 0, 0, 0);
            }
            else
            {
                btd = &(btd_mgr->btd[req->bt_index]);
                btd->index = req->bt_index;

                ret = req->bt_index + 10;
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else
    {
        /*1. reuse same bt addr array */
        for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
        {
            if (btd_mgr->btd[i].bt_addr.lap == bt_addr->lap &&
                btd_mgr->btd[i].bt_addr.uap == bt_addr->uap &&
                btd_mgr->btd[i].bt_addr.nap == bt_addr->nap)
            {
                if (btd_mgr->btd[i].flag & SRV_PBAPC_FLAG_CONNECTED)
                {
                    MMI_ASSERT(0);
                }
                else
                {
                    btd = &(btd_mgr->btd[i]);
                    btd->flag |= SRV_PBAPC_FLAG_USED;
                    btd->index = i;

                    ret = i + 30; // reuse

                    break;
                }
             }
        }

        /*2. find free bt addr array */
        if (SRV_PBAPC_RET_FAIL == ret)
        {
            for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
            {
                if (!(btd_mgr->btd[i].flag & SRV_PBAPC_FLAG_USED))
                {
                    btd = &(btd_mgr->btd[i]);
                    btd->flag |= SRV_PBAPC_FLAG_USED;
                    btd->index = i;

                    ret = i; // free
                    break;
                }
            }
        }

        /*3. find used but not connect bt addr array */
        if (SRV_PBAPC_RET_FAIL == ret)
        {
            for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
            {
                if (!(btd_mgr->btd[i].flag & SRV_PBAPC_FLAG_CONNECTED))
                {
                    btd = &(btd_mgr->btd[i]);
                    btd->flag |= SRV_PBAPC_FLAG_USED;
                    btd->index = i;

                    ret = i + 20; // used not connect
                    break;
                }
            }
        }

        MMI_ASSERT(btd);
    }

    /* reset same bt addr */
    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
    
        if (btd->index == btd_mgr->btd[i].index)
        {
            continue;
        }

        if (btd_mgr->btd[i].bt_addr.lap == bt_addr->lap &&
            btd_mgr->btd[i].bt_addr.uap == bt_addr->uap &&
            btd_mgr->btd[i].bt_addr.nap == bt_addr->nap)
        {
            if (btd_mgr->btd[i].flag & SRV_PBAPC_FLAG_CONNECTED)
            {
                MMI_ASSERT(0);
            }
            else
            {
                //MMI_ASSERT(0);
                memset(&(btd_mgr->btd[i]), 0x00, sizeof(srv_pbapc_btd_struct));
            }
        }
    }

    if (btd->bt_addr.lap == bt_addr->lap &&
        btd->bt_addr.uap == bt_addr->uap &&
        btd->bt_addr.nap == bt_addr->nap)
    {
        btd->flag &= ~SRV_PBAPC_FLAG_NEW_BTD;
    }
    else
    {
        btd->flag |= SRV_PBAPC_FLAG_NEW_BTD;
    }

    btd->bt_addr.lap = bt_addr->lap;
    btd->bt_addr.uap = bt_addr->uap;
    btd->bt_addr.nap = bt_addr->nap;
    btd->flag |= SRV_PBAPC_FLAG_USED;

    //srv_pbapc_p->cur_btd = btd;

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_BTD_PUSH, bt_addr->lap, bt_addr->uap, bt_addr->nap, ret);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_btd_from_bt_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_pbapc_btd_struct *srv_pbapc_get_btd_from_bt_addr(srv_bt_cm_bt_addr *bt_addr, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_btd_mgr_struct *btd_mgr = NULL;
    srv_pbapc_btd_struct *btd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(SRV_PBAPC_TRACE_GROUP,TRC_SRV_PBAPC_GET_BTD, bt_addr->lap, bt_addr->uap, bt_addr->nap, flag);
    srv_pbapc_p = srv_pbapc_get_cntx();
    btd_mgr = srv_pbapc_p->btd_mgr;

    for (i = 0; i < SRV_PBAPC_LINK_NUM; ++i)
    {
        if (btd_mgr->btd[i].bt_addr.lap == bt_addr->lap &&
            btd_mgr->btd[i].bt_addr.uap == bt_addr->uap &&
            btd_mgr->btd[i].bt_addr.nap == bt_addr->nap &&
            (btd_mgr->btd[i].flag & flag) == flag)
        {
            btd = &(btd_mgr->btd[i]);

            break;
        }
    }

    return btd;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_btd_addr
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_get_btd_addr(srv_bt_cm_bt_addr *bt_addr, U8 bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_btd_struct *btd = NULL;
    S32 ret = SRV_PBAPC_RET_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    btd = &(srv_pbapc_p->btd_mgr->btd[bt_index]);

    if (btd->flag & 0x03)
    {
        bt_addr->lap = btd->bt_addr.lap;
        bt_addr->uap = btd->bt_addr.uap;
        bt_addr->nap = btd->bt_addr.nap;

        ret = SRV_PBAPC_RET_OK;
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_GET_BTD_ADDR,  bt_addr->lap, bt_addr->uap, bt_addr->nap, bt_index, btd->flag, 
                ret);

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_get_btd_index
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
S32 srv_pbapc_get_btd_index(srv_bt_cm_bt_addr *bt_addr, U8 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_btd_struct *btd = NULL;
    S32 ret = SRV_PBAPC_RET_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd = srv_pbapc_get_btd_from_bt_addr(bt_addr, flag);

    if (btd)
    {
        ret = btd->index;
    }

    MMI_TRACE(SRV_PBAPC_TRACE_GROUP, TRC_SRV_PBAPC_GET_BTD_INDX, bt_addr->lap, bt_addr->uap, bt_addr->nap, flag, ret);

    return ret;
}


#define AUTH_MMI
/*****************************************************************************
 * FUNCTION
 *  mmi_pbapc_authentication_confirm_hdlr
 * DESCRIPTION
 *  display authentication screen
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbapc_authentication_confirm_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_BT_PBAP_CLIENT__) && defined(__MMI_WEARABLE_DEVICE__)
    {
        srv_pbapc_context_struct *srv_pbapc_p = NULL;

        srv_pbapc_p = srv_pbapc_get_cntx();

        if (srv_bt_cm_get_bqb_test_flag())
        {
            mmi_wcscpy((WCHAR *)(srv_pbapc_p->password), L"0000");
            srv_pbapc_auth_rsp(1);
        }
        else
        {
            mmi_frm_nmgr_notify_by_app(
                    MMI_SCENARIO_ID_BT_ACCESS_REQ,
                    MMI_EVENT_INFO,
                    mmi_pbapc_entry_authentication_confirm,
                    NULL);
        }
    }
#else
    mmi_frm_nmgr_notify_by_app(
            MMI_SCENARIO_ID_BT_ACCESS_REQ,
            MMI_EVENT_INFO,
            mmi_pbapc_entry_authentication_confirm,
            NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_interrupt_notify_hdlr
 * DESCRIPTION
 *  display authentication screen
 * PARAMETERS
 *  S8 *path: ASCII encoding
 *  
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_pbapc_entry_authentication_confirm(mmi_scenario_id scen_id, void *arg)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = mmi_frm_group_create(
                        GRP_ID_ROOT,
                        GRP_ID_BT_PBAPC_AUTHENTICATE,
                        mmi_pbapc_entry_authentication_confirm_proc,
                        NULL);

    if (ret == 0)
    {
        srv_pbapc_auth_rsp(0);
        return MMI_FALSE;
    }

    mmi_frm_group_enter(GRP_ID_BT_PBAPC_AUTHENTICATE, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_pbapc_entry_authentication_confirm_scr();
#endif /* __PLUTO_MMI_PACKAGE__ */

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbapc_entry_authentication_confirm_scr
 * DESCRIPTION
 *  This function is used to entry the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbapc_entry_authentication_confirm_scr(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8  *guiBuffer = NULL;  
    U8  *inputBuffer= NULL;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    if (mmi_frm_scrn_enter(
            GRP_ID_BT_PBAPC_AUTHENTICATE, 
            SCR_PBAPC_PASSWORD, 
            NULL, 
            mmi_pbapc_entry_authentication_confirm_scr, 
            MMI_FRM_FULL_SCRN))
    {
        mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);

#ifdef __MMI_FRM_HISTORY_
        guiBuffer = GetCurrGuiBuffer(SCR_PBAPC_PASSWORD);
        inputBuffer = GetCurrInputBuffer(SCR_PBAPC_PASSWORD);
#endif
        if (inputBuffer == NULL)
        {
            memset(srv_pbapc_p->password, 0, MMI_PBAPC_AUTH_UI_BUFF_SIZE);
            memset(auth_scr_ui_buff, 0, MMI_PBAPC_AUTH_UI_BUFF_SIZE);
            mmi_wcscat(auth_scr_ui_buff, (U16 *)L"(");            
            mmi_wcscat(auth_scr_ui_buff, (U16*)L"PBAP Password");
            mmi_wcscat(auth_scr_ui_buff, (U16 *)L")");
            mmi_wcscat(auth_scr_ui_buff, (U16 *)L":");
        }
        /* inputbuffer != NULL */
        else
        {
            kal_mem_cpy(srv_pbapc_p->password, (U8*) inputBuffer, MMI_PBAPC_AUTH_UI_BUFF_SIZE);
            /* donot need to update ui_buffer */
        }

        RegisterInputBoxValidationFunction(mmi_pbapc_auth_input_validation_func);
        ShowCategory111Screen_ext(
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            (U8*)auth_scr_ui_buff,
            IMM_INPUT_TYPE_NUMERIC_PASSWORD,
            srv_pbapc_p->password,
            (GOEP_MAX_PASSWD_SIZE + 1),
            NULL,
            0,
            guiBuffer);

        SetLeftSoftkeyFunction(mmi_pbapc_auth_send, KEY_EVENT_UP);    
        if (mmi_ucs2strlen((CHAR *) (srv_pbapc_p->password)) < 1)
        {
            ChangeLeftSoftkey(0, 0);
        }

        SetCategory111RightSoftkeyFunction(mmi_pbapc_auth_reject, KEY_EVENT_UP);

        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(mmi_pbapc_auth_send,KEY_EVENT_UP);

        mmi_frm_scrn_set_leave_proc(GRP_ID_BT_PBAPC_AUTHENTICATE, SCR_PBAPC_PASSWORD, mmi_pbapc_entry_authentication_confirm_scr_proc);
    }
#endif /* __PLUTO_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_entry_authentication_confirm_proc
 * DESCRIPTION
 *  This function is used to exit the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pbapc_entry_authentication_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_DEINIT:
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_ACCESS_REQ);
            break;

        case EVT_ID_GROUP_INACTIVE:
            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbapc_entry_authentication_confirm_scr_proc
 * DESCRIPTION
 *  This function is used to exit the authenticating screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_pbapc_entry_authentication_confirm_scr_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_DEINIT:
        {
            mmi_pbapc_auth_reject();
            break;
        }
        default:
            break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_send
 * DESCRIPTION
 *  This function is to send a authentication response to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbapc_auth_send(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_auth_rsp(1);
    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_PBAPC_AUTHENTICATE, SCR_PBAPC_PASSWORD, NULL);
    mmi_frm_group_close(GRP_ID_BT_PBAPC_AUTHENTICATE);
#endif /* __PLUTO_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_reject
 * DESCRIPTION
 *  This function is to send a authentication response with cancel flag to BT
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbapc_auth_reject(void)
{
#ifdef __PLUTO_MMI_PACKAGE__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_auth_rsp(0);
    mmi_frm_scrn_set_leave_proc(GRP_ID_BT_PBAPC_AUTHENTICATE, SCR_PBAPC_PASSWORD, NULL);
    mmi_frm_group_close(GRP_ID_BT_PBAPC_AUTHENTICATE);
#endif /* __PLUTO_MMI_PACKAGE__ */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_pbap_auth_input_validation_func
 * DESCRIPTION
 *  This function is to check the input buffer of authenticating screen
 * PARAMETERS
 *  text        [?]             
 *  cursor      [?]             
 *  length      [IN]            
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_pbapc_auth_input_validation_func(U8 *text, U8 *cursor, S32 length)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((length) < 1)
    {
        ChangeLeftSoftkey(0, 0);
    }
    else
    {
        EnableLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    }
}


#define PARSE_XML

/*****************************************************************************
* FUNCTION
*  srv_pbapc_start_read_data
* DESCRIPTION
*
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void srv_pbapc_start_read_data(SRV_PBAPC_BT_INDEX bt_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p->bt_index = bt_index;

    srv_pbapc_parse_xml_file(PBAPC_ADP_LIST_FILE);
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_parse_xml_file
* DESCRIPTION
*  Parses the XML PBAP list file.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static S32 srv_pbapc_parse_xml_file(U16 *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_list_data_rsp_struct list_data_rsp;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    S32 ret = SRV_PBAPC_RET_OK;
    XML_PARSER_STRUCT *xml_parser = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();
    xml_parser = (XML_PARSER_STRUCT*) OslMalloc(sizeof(XML_PARSER_STRUCT));
    ret = xml_new_parser(xml_parser);

    if (ret)
    {
        xml_close_parser(xml_parser);
        OslMfree(xml_parser);
        xml_parser = NULL;
    }
    else
    {
        kal_mem_set(&(srv_pbapc_p->xml_info), 0x00, sizeof(srv_pbapc_parse_xml_struct));

        xml_register_element_handler(xml_parser, srv_pbapc_xml_start_element_hdlr, srv_pbapc_xml_end_element_hdlr);
        xml_register_data_handler(xml_parser, srv_pbapc_xml_data_hdlr);
        ret = xml_parse(xml_parser, filename);
        xml_close_parser(xml_parser);

        kal_mem_set(&list_data_rsp, 0x00, sizeof(srv_pbapc_list_data_rsp_struct));
        kal_mem_cpy((char *)list_data_rsp.handle, (char *)(srv_pbapc_p->xml_info.handle), srv_pbapc_p->xml_info.num * sizeof(U16));
        kal_mem_cpy((char *)list_data_rsp.name, (char *)(srv_pbapc_p->xml_info.name), srv_pbapc_p->xml_info.num * (PBAP_MAX_NAME_LEN / 2));
        list_data_rsp.num = srv_pbapc_p->xml_info.num;
        list_data_rsp.more = 0;

        notify_evt.data = (void *)(&list_data_rsp);
        notify_evt.type = EVT_ID_PBAPC_READ_DATA_RSP;
        notify_evt.bt_index = srv_pbapc_p->bt_index;

        kal_mem_set(&(srv_pbapc_p->xml_info), 0x00, sizeof(srv_pbapc_parse_xml_struct));

        /* notify phb srv */
        srv_pbapc_p->pbapc_cb_func(&notify_evt);
    }

    return ret;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_xml_data_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_xml_data_hdlr(void *data, const char *el, const char *value, int len, int error)
{
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_xml_data_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static U32 srv_pbapc_string_to_hex(char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 result = 0;
    S32 c; 
    S32 len = strlen(s);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *(s + len - 4) = '\0';                    //Remove .vcf from string

    while (*s) 
    {
        result = result << 4;

        if (c = (*s - '0'), (c >= 0 && c <= 9))
        {
            result |= c;
        }
        else if ( c = (*s - 'A'), ( c>= 0 && c <= 5))
        {
            result |= (c + 10);
        }
        else if (c = (*s - 'a'), ( c >= 0 && c <=5 ))
        {
            result |= (c + 10);
        }
        else
        {
            break;
        }

        s++;
    }

    return result;
}


/*****************************************************************************
* FUNCTION
*  srv_pbapc_xml_start_element_hdlr
* DESCRIPTION
*  Stores parsed XML each  list element into a global structure one by one and sends response to PHB srv.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_xml_start_element_hdlr(void *data, const char *el,const char **attr, int error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char *temp_handle = NULL;
    srv_pbapc_list_data_rsp_struct list_data_rsp;
    srv_pbapc_context_struct *srv_pbapc_p = NULL;
    srv_pbapc_notify_event_struct notify_evt;
    S32 ret = SRV_PBAPC_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    if (!error)
    {
        if (srv_pbapc_p->xml_info.num == SRV_PBAPC_XML_PARSE_NUM)
        {
            kal_mem_set(&list_data_rsp, 0x00, sizeof(srv_pbapc_list_data_rsp_struct));
            kal_mem_cpy((char *)list_data_rsp.handle, (char *)(srv_pbapc_p->xml_info.handle), SRV_PBAPC_XML_PARSE_NUM * sizeof(U16));
            kal_mem_cpy((char *)list_data_rsp.name, (char *)(srv_pbapc_p->xml_info.name), SRV_PBAPC_XML_PARSE_NUM * (PBAP_MAX_NAME_LEN / 2));
            list_data_rsp.num = srv_pbapc_p->xml_info.num;
            list_data_rsp.more = 1;

            notify_evt.data = (void *)(&list_data_rsp);
            notify_evt.type = EVT_ID_PBAPC_READ_DATA_RSP;
            notify_evt.bt_index = srv_pbapc_p->bt_index;

            kal_mem_set(&(srv_pbapc_p->xml_info), 0x00, sizeof(srv_pbapc_parse_xml_struct));

            /* notify phb srv */
            srv_pbapc_p->pbapc_cb_func(&notify_evt);
        }

        if (!strcmp(PBAP_XML_ELEMNT_VCARD, el))
        {
            if ((attr[0] && !strcmp(PBAP_XML_ELEMNT_HANDLE, attr[0])) || (attr[2] && !strcmp(PBAP_XML_ELEMNT_NAME, attr[2])))
            {
                if (attr[0] && !strcmp(PBAP_XML_ELEMNT_HANDLE, attr[0]))
                {
                    temp_handle = (char*)OslMalloc(strlen(attr[1]) + 1);

                    if (temp_handle)
                    {
                        kal_mem_set(temp_handle, 0x00, strlen(attr[1]) + 1);
                        kal_mem_cpy((char *)temp_handle, (char *)attr[1], strlen(attr[1]) + 1);
                        srv_pbapc_p->xml_info.handle[srv_pbapc_p->xml_info.num] = srv_pbapc_string_to_hex(temp_handle);
                        OslMfree(temp_handle);
                    }
                }

                if (attr[2] && !strcmp(PBAP_XML_ELEMNT_NAME, attr[2]))
                {           
                    kal_mem_cpy((char *)srv_pbapc_p->xml_info.name[srv_pbapc_p->xml_info.num],attr[3], (PBAP_MAX_NAME_LEN / 2));

                    srv_pbapc_p->xml_info.num += 1;
                }
            }
        }
    }
}


/*****************************************************************************
* FUNCTION
*  srv_pbabc_xml_end_element_hdlr
* DESCRIPTION
*  Displays the details of the selected phonebook entry
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void srv_pbapc_xml_end_element_hdlr(void *data, const char *el, int error)
{
}


#define BQB_TEST

void srv_pbapc_bqb_abort_req()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    srv_pbapc_abort_req(srv_pbapc_p->handle[0].goep_conn_id);
}


static void srv_pbapc_bqb_disconnect_cb(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}


void srv_pbapc_bqb_disconnect()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_pbapc_context_struct *srv_pbapc_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_pbapc_p = srv_pbapc_get_cntx();

    srv_pbapc_disconnect(&(srv_pbapc_p->handle[0].bt_addr), srv_pbapc_bqb_disconnect_cb);
}


#define CATCHER_INJECT
/*****************************************************************************
* FUNCTION
*  mmi_bt_pbap_proc_inject_string
* DESCRIPTION
*  Inject string from catcher.
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
U8 mmi_bt_pbap_proc_inject_string(U8 index, kal_uint8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    return 0;
}

#endif /* __BT_PBAP_CLIENT__ */

#endif /* __MMI_BT_SUPPORT__ */

