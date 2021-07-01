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
 * BtDialersrv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/

#include "MMI_features.h"

#ifdef __MMI_HF_SUPPORT__

#include "MMIDataType.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
//#include "bluetooth_bm_struct.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_queue_gprot.h"
#include "Mmi_frm_mem_gprot.h"
#include "BTDialerSrvGprot.h"
#include "BTDialerSrv.h"
#include "Mdi_audio.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "BthScoPathSrvGProt.h"
#include "mmi_res_range_def.h"
#include "GpioSrvGprot.h"
#include "VolumeHandler.h"
#include "mmi_rp_app_bt_dialer_def.h"
#include "Bt_message.h"
#include "BtcmSrvGprot.h"
#include "bt_hfadp_struct.h"
#include "UcmBTSrvGprot.h"
#include "UcmSrvGprot.h"
#include "mdi_datatype.h" // MDI_AUDIO_SUCCESS
#include "mmi_rp_srv_btsco_def.h" // EVT_ID_SRV_BTSCO_CLOSE_IND
#ifdef __MMI_WEARABLE_DEVICE__
#include "vmsettings.h"
#endif

#define IsValidDevice(addr) \
            ((addr != NULL) && \
            ((addr)->lap != 0 || (addr)->nap != 0 || (addr)->uap != 0))


#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__)
extern void mmi_bt_dialor_callback(srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect);
#endif
static srv_bt_dialer_context_struct g_srv_bt_dialer_cntx;
static srv_bt_dialer_context_struct* g_srv_bt_dialer_p = &g_srv_bt_dialer_cntx;

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_connection_notify
 * DESCRIPTION
 * 
 * CALLS
 * 
 * RETURNS
 * 
 *****************************************************************************/
static void srv_bt_dialer_connection_notify(srv_bt_dialer_notify_event_struct* notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(notify);

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_HF_CONN_NOTIFY, g_srv_bt_dialer_p->connection_cb, notify->event_id);

    if (g_srv_bt_dialer_p->connection_cb)
    {
        g_srv_bt_dialer_p->connection_cb(notify);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_new_device
 * DESCRIPTION
 *  This function is to create a new device.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
static srv_bt_dialer_dev_info_struct* srv_bt_dialer_new_device(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL indication)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_addr);

    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_HF_NEW_DEV,
                    g_srv_bt_dialer_p->conn_dev_count,
                    ((dev_addr->nap & 0xff00) >> 8),
                    (dev_addr->nap & 0x00ff),
                    (dev_addr->uap),
                    ((dev_addr->lap & 0xff0000) >> 16),
                    ((dev_addr->lap & 0x00ff00) >> 8),
                    (dev_addr->lap & 0x0000ff));

    if (!IsValidDevice(dev_addr))
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_INVALID_ADDR);
        return NULL;
    }

    for (idx = 0, dev_info = g_srv_bt_dialer_p->dev_info; idx < BT_MAX_HF_DEV; idx++)
    {
        if (dev_info->alloc
        && dev_info->bd_addr.lap == dev_addr->lap
        && dev_info->bd_addr.nap == dev_addr->nap
        && dev_info->bd_addr.uap== dev_addr->uap)
        {
            // already exist.
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_DEV_EXIST, dev_info);
            dev_info->dev_ref++;
            return dev_info;
        }
        dev_info++;
    }

    for (idx = 0, dev_info = g_srv_bt_dialer_p->dev_info; idx < BT_MAX_HF_DEV; idx++)
    {
        if (!dev_info->alloc)
        {
            dev_info->alloc = MMI_TRUE;
            memcpy(&dev_info->bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
            memcpy(&g_srv_bt_dialer_p->last_dev_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
            dev_info->indication = indication;
            g_srv_bt_dialer_p->conn_dev_count++;
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NEW_DEV_SUC, dev_info);
            return dev_info;
        }
        dev_info++;
    }

    // for the case MAUI_03503124.
    // BT receive connection indication first and MMI send connect request at same time.
    // connection indication's priorty is higher than connection request(because the request will fail)
    // if no device can be alloced, remove the connceting request.
    for (idx = 0, dev_info = g_srv_bt_dialer_p->dev_info; idx < BT_MAX_HF_DEV; idx++)
    {
        SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_NEW_DEV_SPEC, dev_info, dev_info->indication, dev_info->cm_conn_id);

        if (dev_info->alloc && dev_info->indication == MMI_FALSE)
        {
            srv_bt_dialer_notify_event_struct notify;

            if (dev_info->cm_conn_id > 0 && dev_info->cm_conn_id <= SRV_BT_CM_MAX_CONNECTION)
            {
                srv_bt_cm_stop_conn(dev_info->cm_conn_id);
            }

            notify.event_id = SRV_BT_DIALER_EVT_ID_DISCONNECT_IND;
            memcpy(&notify.result.conn_info.dev_addr, &dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));
            srv_bt_dialer_connection_notify(&notify);

            memcpy(&dev_info->bd_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
            memcpy(&g_srv_bt_dialer_p->last_dev_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));
            dev_info->indication = indication;
            return dev_info;
        }
        dev_info++;
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_del_device
 * DESCRIPTION
 *  This function is to create a new device.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
static void srv_bt_dialer_del_device(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // connection fail.
    if (IsValidDevice(dev_addr))
    {
        dev_info = srv_bt_dialer_get_dev_info_by_addr(dev_addr);
    }

    MMI_ASSERT(dev_info);

    SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_DEL_DEV, dev_info->srv_hd, dev_info->alloc, dev_info);

    if (dev_info->alloc)
    {
        if (dev_info->dev_ref == 0)
        {

            if (g_srv_bt_dialer_p->sco_allow == dev_info->conn_id)
            {
                g_srv_bt_dialer_p->sco_allow = MMI_HF_INVALID_CONN_ID;
            }

            srv_bt_dialer_free_atcmd_queue(dev_info->conn_id);
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_DEL_CM_ID, dev_info->cm_conn_id);
            memset(dev_info, 0, sizeof(srv_bt_dialer_dev_info_struct));
            dev_info->cm_conn_id = MMI_HF_INVALID_CM_CONN_ID;
            dev_info->conn_id = MMI_HF_INVALID_CONN_ID;
            dev_info->cm_cb = mmi_bt_dialor_callback;
            g_srv_bt_dialer_p->conn_dev_count--;
        }
        else
        {
            dev_info->dev_ref--;
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_DEL_REF_CNT, dev_info->dev_ref);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_init
 * DESCRIPTION
 *  this function is to initialize the BT Dialer global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_cm_profile_struct profile_info_p;
    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    profile_info_p.profile_id     = SRV_BT_CM_HF_PROFILE_UUID;
    profile_info_p.activater      = srv_bt_dialer_send_activate_req;
    profile_info_p.deactivater    = srv_bt_dialer_send_deactivate_req;
    profile_info_p.disconnector   = srv_bt_dialer_send_disconnect_req;
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct *)&profile_info_p);

    for (idx = 0; idx < BT_MAX_HF_DEV; idx++)
    {
        g_srv_bt_dialer_p->dev_info[idx].srv_hd = -1;
        g_srv_bt_dialer_p->dev_info[idx].cm_cb = mmi_bt_dialor_callback;
        g_srv_bt_dialer_p->dev_info[idx].cm_conn_id = MMI_HF_INVALID_CM_CONN_ID;
        g_srv_bt_dialer_p->dev_info[idx].conn_id = MMI_HF_INVALID_CONN_ID;
        g_srv_bt_dialer_p->dev_info[idx].state = SRV_BTD_DEV_STATE_IDLE;
    }
    g_srv_bt_dialer_p->sco_allow = MMI_HF_INVALID_CONN_ID;

    SRV_BT_DIALER_LOG(SRV_BT_DIALER_INIT_OPERATION);

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CONNECT_IND_REQ, (PsIntFuncPtr)srv_bt_dialer_connect_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DISCONNECT_IND, (PsIntFuncPtr)srv_bt_dialer_disconnect_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_RING_IND, (PsIntFuncPtr)srv_bt_dialer_ring_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALL_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_call_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALLSETUP_IND, (PsIntFuncPtr)srv_bt_dialer_callsetup_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_CALLHELD_IND, (PsIntFuncPtr)srv_bt_dialer_callheld_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLIP_IND, (PsIntFuncPtr)srv_bt_dialer_clip_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CCWA_IND, (PsIntFuncPtr)srv_bt_dialer_ccwa_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CONNECT_CNF, (PsIntFuncPtr)srv_bt_dialer_connect_cnf_hdlr, MMI_TRUE);
#ifndef __MMI_BTBOX_NOLCD__
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BSIR_IND, (PsIntFuncPtr)srv_bt_dialer_bsir_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGS_IND, (PsIntFuncPtr)srv_bt_dialer_vgs_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGM_IND, (PsIntFuncPtr)srv_bt_dialer_vgm_ind_hdlr, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_SERVICE_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_service_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_SIGNAL_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_signal_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_ROAM_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_roam_ind, MMI_TRUE);
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CIEV_BATTCHG_IND, (PsIntFuncPtr)srv_bt_dialer_ciev_battchg_ind, MMI_TRUE);
#ifdef __BT_HF_BVRA_SUPPORT__
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BVRA_IND, (PsIntFuncPtr)srv_bt_dialer_bvra_ind, MMI_TRUE);
#endif /* __BT_HF_BVRA_SUPPORT__ */
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_IND, (PsIntFuncPtr)srv_bt_dialer_btrh_ind, MMI_TRUE);
#endif /* __MMI_BTBOX_NOLCD__ */
#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_ACL_DISCONN_SUPER_TO,(PsIntFuncPtr)srv_bt_dialer_timeout_disconnect_ind, MMI_TRUE);
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/

    mmi_frm_cb_reg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_bt_dialer_sco_connection_event_hdlr, NULL);

    srv_ucm_bt_init();
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_deinit
 * DESCRIPTION
 * this function is to deinit the BT Dialer global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 speech_vol_level;
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dev_info = &g_srv_bt_dialer_p->dev_info[0]; dev_info < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info++)
    {
        if (dev_info->alloc && IsValidDevice(&dev_info->bd_addr))
        {
            srv_bt_dialer_del_device(&dev_info->bd_addr);
        }
    }
    memset(g_srv_bt_dialer_p, 0, sizeof(srv_bt_dialer_context_struct));
    g_srv_bt_dialer_p->sco_allow = MMI_HF_INVALID_CONN_ID;
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEINIT_OPERATION);
    speech_vol_level = MDI_AUD_VOL_GET_EX_LEVEL(srv_speech_get_mode_volume()); //get speech volume
    srv_speech_save_mode_volume(MDI_AUD_VOL_MUTE(speech_vol_level));  //restore speech volume
    mdi_audio_set_mic_volume(); //restore MIC volume

    mmi_frm_cb_dereg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_bt_dialer_sco_connection_event_hdlr, NULL);

    srv_ucm_bt_deinit();

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_open
 * DESCRIPTION
 *  This function is to open BT Dialer context and return service handler to APP.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
S32 srv_bt_dialer_open(srv_bt_cm_bt_addr *dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_addr(dev_addr);

    MMI_ASSERT(dev_info);

    dev_info->srv_hd = (((U32)(dev_info)) & 0xFFFF);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_OPEN, dev_info->srv_hd);
    return dev_info->srv_hd;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_close
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_close(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_hd(srv_hd);

    if (dev_info != NULL)
    {
        dev_info->srv_hd = 0;
    }
    else
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_CLOSE_FAIL);
    }

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_CLOSE, srv_hd);
}

static void srv_bt_dialer_reset_call_state(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_RESET, conn_id);
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_info_p)
    {
        dev_info_p->callsetup = 0;
        dev_info_p->ciev_call = 0;
        dev_info_p->callheld = 0;
    }
    else
    {
        // MMI_ASSERT(0);
        // Remove assert, because of MAUI_03502090.
        // The issue could happen in special case:go to call logs>tap on a no. to call >at the same time turn off bt of SP
    }
}

static void srv_bt_dialer_dump_cur_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dev_info_p = &g_srv_bt_dialer_p->dev_info[0]; dev_info_p < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info_p++)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_DUMP_CUR_DEV,
                dev_info_p->bd_addr.lap,
                dev_info_p->bd_addr.uap,
                dev_info_p->bd_addr.nap,
                dev_info_p->cm_conn_id,
                dev_info_p->conn_id,
                dev_info_p->srv_hd,
                dev_info_p->state);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_register_hf_connection_notifier
 * DESCRIPTION
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_register_hf_connection_notifier(srv_bt_dialer_notify_hf_connection_event cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_srv_bt_dialer_p->connection_cb = cb_ptr;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_register_hf_notifier
 * DESCRIPTION
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_dialer_register_hf_notifier(S32 srv_hd, srv_bt_dialer_notify_hf_event cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
//    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_hd(srv_hd);

    if (dev_info)
    {
        dev_info->cb_ptr = cb_ptr;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        return SRV_BT_DIALER_SUCCESS;
    }
    else
    {
        return SRV_BT_DIALER_FAILURE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_register_indicators
 * DESCRIPTION
 * API for UCM to register specific events to recieve notifications for selected events.
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_dialer_register_indicators(S32 srv_hd, U16 ind_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_hd(srv_hd);
    dev_info->ind_mask = ind_event;
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_INDICATORS, ind_event);
    return SRV_BT_DIALER_SUCCESS;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_free_atcmd_queue
 * DESCRIPTION
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_free_atcmd_queue(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_send_at_cmd_struct *temp = NULL;
    srv_bt_dialer_send_at_cmd_struct *temp2 = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = g_srv_bt_dialer_p->hf_cmd;

    while((temp != NULL))
    {
        if (conn_id == temp->conn_id)
        {
            if (temp->btd_hf_cmd != NULL)
            {
                OslMfree(temp->btd_hf_cmd);
            }
            if (temp2 != NULL)
            {
                temp2->Flink = temp->Flink;
                OslMfree(temp);
                temp = temp2;
            }
        }
        else
        {
            temp2 = temp;
        }
        temp = temp->Flink;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_activate_req
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_REQ);
    g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_ACTIVATING;
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ACTIVATE_CNF, (PsIntFuncPtr)srv_bt_dialer_activate_cnf_hdlr, MMI_TRUE); 
    srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_ACTIVATE_REQ, MOD_BT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_activate_cnf_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_activate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_activate_cnf_struct *activate_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    activate_rsp = (bt_hf_activate_cnf_struct*) msg;
    ASSERT(activate_rsp);

    if(activate_rsp->result != 0)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_CNF_FAIL);
        g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_IDLE;
        return MMI_FALSE;
    }
    if (g_srv_bt_dialer_p->serv_state == SRV_BTD_STATE_ACTIVATING)
    {
        g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_ACTIVATED;
    }
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_ACTIVATE_CNF_SUCCESS);
    srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_HF_PROFILE_UUID);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_deactivate_req
 * DESCRIPTION
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATE);
    g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_DEACTIVATING;
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DEACTIVATE_CNF, (PsIntFuncPtr)srv_bt_dialer_deactivate_cnf_hdlr, MMI_TRUE); 
    srv_bt_dialer_send_ilm((void*)NULL, MSG_ID_BT_HF_DEACTIVATE_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_deactivate_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_deactivate_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_deactivate_cnf_struct *deactivate_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    deactivate_rsp = (bt_hf_deactivate_cnf_struct*) msg;
    ASSERT(deactivate_rsp);

    if(deactivate_rsp->result != 0)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATE_FAIL);        
        g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_IDLE;
        return MMI_FALSE;
    }
    if (g_srv_bt_dialer_p->serv_state == SRV_BTD_STATE_DEACTIVATING)
    { 
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_DEACTIVATED);
        g_srv_bt_dialer_p->serv_state = SRV_BTD_STATE_IDLE;
        srv_bt_cm_deactivate_cnf_hdler((U32) SRV_BT_CM_HF_PROFILE_UUID);
    }
    return MMI_TRUE;
}

srv_bt_cm_bt_addr* srv_bt_get_dialor_addr(void)
{
    return &g_srv_bt_dialer_p->last_dev_addr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_reset_enable_feature
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static srv_bt_dialer_reset_enable_feature(srv_bt_dialer_dev_info_struct* dev_p, srv_bt_dialer_enable_features_enum feature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_p);

    if (feature > 0)
    {
        dev_p->enable_mask &= (~feature);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_enable_feature
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static srv_bt_dialer_set_enable_feature(srv_bt_dialer_dev_info_struct* dev_p, srv_bt_dialer_enable_features_enum feature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_p);

    if (feature > 0)
    {
        dev_p->enable_mask |= feature;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_enable_feature
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dialer_enable_feature(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_p;
    srv_bt_dialer_enable_features_enum feature;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_p == NULL)
    {
        return;
    }

    if (dev_p->enable_mask & SRV_BT_DIALER_ENABLE_CLIP)
    {
        srv_bt_dialer_send_set_clip_req(dev_p->srv_hd, MMI_TRUE);
        feature = SRV_BT_DIALER_ENABLE_CLIP;
    }
    else if (dev_p->enable_mask & SRV_BT_DIALER_ENABLE_CCWA)
    {
        srv_bt_dialer_send_call_wait_notify_req(dev_p->srv_hd,MMI_TRUE);
        feature = SRV_BT_DIALER_ENABLE_CCWA;
    }
    else if (dev_p->enable_mask & SRV_BT_DIALER_ENABLE_XAPL)
    {
        U8 features = SRV_BT_DIALER_XAPL_NONE;
    #ifdef __MMI_HF_BAT_SUPPORT__
        features |= SRV_BT_DIALER_XAPL_BAT;
    #endif /* __MMI_HF_BAT_SUPPORT__ */
        srv_bt_dialer_enable_custom_at_cmd_req(dev_p->srv_hd, features);
        feature = SRV_BT_DIALER_ENABLE_XAPL;
    }
    else
    {
        feature = SRV_BT_DIALER_ENABLE_NONE;
    }
    srv_bt_dialer_reset_enable_feature(dev_p, feature);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_connect_req
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_connect_req(srv_bt_cm_bt_addr* bd_addr, srv_bt_dialer_cm_connect_notify srv_cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/
    bt_hf_connect_req_struct *req;
    S32 cm_conn_id;
    srv_bt_dialer_dev_info_struct* dev_info;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bd_addr);

    SRV_BT_DIALER_LOG3(SRV_BT_DIALER_CONNECT_REQ, bd_addr->lap, bd_addr->uap, bd_addr->nap);

    dev_info = srv_bt_dialer_get_dev_info_by_addr(bd_addr);

    if(dev_info != NULL && (dev_info->state == SRV_BTD_DEV_STATE_CONNECTED 
       || dev_info->state == SRV_BTD_DEV_STATE_CONNECTING || dev_info->state == SRV_BTD_DEV_STATE_DISCONNECTING))
    {
        if (srv_cm_cb)
        {
            srv_cm_cb(bd_addr, SRV_BT_CM_HF_CONNECTION, MMI_FALSE, MMI_TRUE, MMI_FALSE);
        }
        return;
    }

    dev_info = srv_bt_dialer_new_device(bd_addr, MMI_FALSE);

    if (!dev_info)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_NEW_DEV_FAIL);
        if (srv_cm_cb)
        {
            srv_cm_cb(bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_FALSE,MMI_TRUE,MMI_FALSE);
        }
        return;
    }

    dev_info->cm_cb = srv_cm_cb;

    cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_HF_PROFILE_UUID, bd_addr, NULL);

    if(cm_conn_id < 0 || !srv_bt_dialer_is_serv_ready())
    {
        if (cm_conn_id > 0 && cm_conn_id <= SRV_BT_CM_MAX_CONNECTION)
        {
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID , cm_conn_id);
            srv_bt_cm_stop_conn(cm_conn_id);
        }

        if(dev_info->cm_cb)
        {
            dev_info->cm_cb(bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_FALSE,MMI_TRUE,MMI_FALSE);
        }

        srv_bt_dialer_del_device(bd_addr);

        return;
    }

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_ALLOC_CM_ID, cm_conn_id);
    dev_info->cm_conn_id = cm_conn_id;
    dev_info->conn_id = MMI_HF_TEMP_CONN_ID;
    dev_info->state = SRV_BTD_DEV_STATE_CONNECTING;

    req = (bt_hf_connect_req_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_req_struct));

    srv_bt_dialer_addr_transfer(&req->bt_addr, bd_addr, MMI_FALSE);
    
    req->hs_conn = MMI_FALSE;

    notify.event_id = SRV_BT_DIALER_EVT_ID_CONNECT_REQ;
    memcpy(&notify.result.conn_info.dev_addr, bd_addr, sizeof(srv_bt_cm_bt_addr));

    srv_bt_dialer_connection_notify(&notify);

    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CONNECT_REQ, MOD_BT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_connect_cnf_hdlr
 * DESCRIPTION
 *  This function is used to
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_connect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_connect_cnf_struct *rsp= NULL;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info = NULL;
    srv_bt_cm_bt_addr dev_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_connect_cnf_struct*) msg;

    ASSERT(rsp);

    srv_bt_dialer_addr_transfer(&dev_addr, &rsp->bt_addr, MMI_TRUE);

    if (IsValidDevice(&dev_addr))
    {
        dev_info = srv_bt_dialer_get_dev_info_by_addr(&dev_addr);
    }

    if (dev_info == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_FATAL_ERR, 101,
            rsp->connection_id, dev_addr.lap, dev_addr.uap, dev_addr.nap);
        srv_bt_dialer_dump_cur_device();
        return MMI_FALSE;
    }

    notify.event_id = SRV_BT_DIALER_EVT_ID_CONNECT_CNF;
    notify.result.conn_cnf.result = rsp->result;
    memcpy(&notify.result.conn_cnf.dev_addr, &dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));
    srv_bt_dialer_connection_notify(&notify);
 
    if(rsp->result != 0)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_CONNECT_CNF_FAIL);

        if (MMI_HF_INVALID_CM_CONN_ID != dev_info->cm_conn_id && dev_info->dev_ref == 0)
        {
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID, dev_info->cm_conn_id);
            srv_bt_cm_stop_conn(dev_info->cm_conn_id);
        }

    #ifdef __MMI_WEARABLE_DEVICE__
        if (dev_info->sg_conn_cb)
        {
            dev_info->sg_conn_cb(&dev_info->bd_addr, (MMI_BOOL)!rsp->result);
            dev_info->sg_conn_cb = NULL; // use once
        }
        else if (dev_info->cm_cb)
    #else
        if(dev_info->cm_cb)
    #endif
        {      
            dev_info->cm_cb(&dev_info->bd_addr, SRV_BT_CM_HF_CONNECTION,(MMI_BOOL)!rsp->result,MMI_TRUE,dev_info->indication);
        }

        srv_bt_dialer_del_device(&dev_info->bd_addr);

        return MMI_FALSE;
    }

    if (SRV_BTD_DEV_STATE_CONNECTING == dev_info->state)
    {
        srv_bt_cm_connect_ind(dev_info->cm_conn_id);
    }

    dev_info->conn_id = rsp->connection_id;
    dev_info->state = SRV_BTD_DEV_STATE_CONNECTED;

    if (dev_info->callsetup != 0 || dev_info->ciev_call != 0 || dev_info->callheld != 0)
    {
        if (dev_info->callsetup != 0)
        {
            notify.event_id = SRV_BT_DIALER_CIEV_CALL_SETUP_INDICATION;
            notify.result.call_setup_ind.setup = (srv_bt_dialer_call_setup_ind_enum)dev_info->callsetup;
        }
        if (dev_info->ciev_call != 0)
        {
            notify.event_id = SRV_BT_DIALER_CIEV_CALL_INDICATION;
            notify.result.call_ind.call = (srv_bt_dialer_call_ind_enum)dev_info->ciev_call;
        }
        if (dev_info->callheld != 0)
        {
            notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD;
            notify.result.held_ind.held = (srv_bt_dialer_AtHeldInd_enum)dev_info->callheld;
        }

        if(dev_info->cb_ptr)
        {
            dev_info->cb_ptr(dev_info->srv_hd, &notify); 
        }
        else
        {
            SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
        }

    }

#ifdef __MMI_WEARABLE_DEVICE__
    if (dev_info->sg_conn_cb)
    {
        dev_info->sg_conn_cb(&dev_info->bd_addr, (MMI_BOOL)!rsp->result);
        dev_info->sg_conn_cb = NULL; // use once
    }
    else if (dev_info->cm_cb)
#else
    if(dev_info->cm_cb)
#endif
    {
        dev_info->cm_cb(&dev_info->bd_addr, SRV_BT_CM_HF_CONNECTION,(MMI_BOOL)!rsp->result,MMI_TRUE,dev_info->indication);
    }

    SRV_BT_DIALER_LOG(SRV_BT_DIALER_CONNECT_CNF_PASSED);


    srv_bt_dialer_set_enable_feature(dev_info,(srv_bt_dialer_enable_features_enum)
                                     (SRV_BT_DIALER_ENABLE_CLIP| SRV_BT_DIALER_ENABLE_CCWA
                                     |SRV_BT_DIALER_ENABLE_XAPL));

    srv_bt_dialer_enable_feature(rsp->connection_id);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_connect_ind
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_connect_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_connect_ind_req_struct *req;
    srv_bt_cm_bt_addr bd_addr;
    S32 cm_conn_id;
    srv_bt_dialer_dev_info_struct* dev_info;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
     
    req = (bt_hf_connect_ind_req_struct*) msg;
    ASSERT(req);
     
    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_CONNECT_IND,
                     req->connection_id,
                    ((req->bt_addr.nap & 0xff00) >> 8),
                    (req->bt_addr.nap & 0x00ff),
                    (req->bt_addr.uap),
                    ((req->bt_addr.lap & 0xff0000) >> 16),
                    ((req->bt_addr.lap & 0x00ff00) >> 8),
                    (req->bt_addr.lap & 0x0000ff));

    srv_bt_dialer_addr_transfer(&bd_addr, &req->bt_addr, MMI_TRUE);

    dev_info = srv_bt_dialer_new_device(&bd_addr, MMI_TRUE);

    if (!dev_info)
    {
        bt_hf_connect_ind_res_struct *rsp;
     
        rsp = (bt_hf_connect_ind_res_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_ind_res_struct));
        rsp->connection_id = req->connection_id;
        rsp->accept = MMI_FALSE;
        memcpy(&rsp->bt_addr, &req->bt_addr, sizeof(bt_dm_addr_struct));
        srv_bt_dialer_send_ilm((void*)rsp, MSG_ID_BT_HF_CONNECT_IND_RES, MOD_BT);
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_NEW_DEV_FAIL);
        return;
    }

    if (dev_info->cm_conn_id > 0 && dev_info->cm_conn_id <= SRV_BT_CM_MAX_CONNECTION)
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID, dev_info->cm_conn_id);
        srv_bt_cm_stop_conn(dev_info->cm_conn_id);
    }

    dev_info->conn_id = req->connection_id;
    dev_info->hs_conn = req->hs_conn;

    cm_conn_id = srv_bt_cm_start_conn(MMI_TRUE, SRV_BT_CM_HF_PROFILE_UUID, &bd_addr, NULL);

    notify.event_id = SRV_BT_DIALER_EVT_ID_CONNECT_IND;
    memcpy(&notify.result.conn_info.dev_addr, &dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));
    srv_bt_dialer_connection_notify(&notify);

    if (cm_conn_id < 0 || cm_conn_id > SRV_BT_CM_MAX_CONNECTION)
    {
        srv_bt_dialer_send_connect_ind_rsp(dev_info->conn_id, MMI_HF_CONN_CNF_REJECT);
        return;
    }

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_ALLOC_CM_ID, cm_conn_id);
    dev_info->cm_conn_id = cm_conn_id;

    srv_bt_dialer_send_connect_ind_rsp(dev_info->conn_id, MMI_HF_CONN_CNF_ACCEPT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_connect_ind_rsp
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_connect_ind_rsp(U8 conn_id, S32 accept)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_connect_ind_res_struct *rsp;
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
     
    rsp = (bt_hf_connect_ind_res_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_ind_res_struct));

    dev_info = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    MMI_ASSERT(dev_info);

    rsp->connection_id = conn_id;

    srv_bt_dialer_addr_transfer(&rsp->bt_addr, &dev_info->bd_addr, MMI_FALSE);

    rsp->accept = (MMI_BOOL)accept;

    if (rsp->accept)
    {
        // for IPhone6 IOT issue
        srv_bt_cm_connect_ind(dev_info->cm_conn_id);
        dev_info->state = SRV_BTD_DEV_STATE_CONNECTED;
    }
    else
    {
        dev_info->state = SRV_BTD_DEV_STATE_CONNECTING;
    }

    srv_bt_dialer_send_ilm((void*)rsp, MSG_ID_BT_HF_CONNECT_IND_RES, MOD_BT);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CONNECT_IND_RSP, accept);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_deconnect_req
 * DESCRIPTION
 * PARAMETERS
 *  bd_addr     [IN]        
 *  conn_id     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_send_disconnect_req(U32 cm_conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_disconnect_req_struct *req;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_REQ);

    for (dev_info = &g_srv_bt_dialer_p->dev_info[0]; dev_info < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info++)
    {
        if (dev_info->cm_conn_id == cm_conn_id)
        {
            if (dev_info->state == SRV_BTD_DEV_STATE_DISCONNECTING)
            {
                //dev_info->cm_cb(&dev_info->bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_FALSE,MMI_FALSE,MMI_FALSE);
                return;
            }
            else if (dev_info->state == SRV_BTD_DEV_STATE_CONNECTING)
            {
                dev_info->cm_cb(&dev_info->bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_FALSE,MMI_FALSE,MMI_FALSE);
                return;
            }

            req = (bt_hf_disconnect_req_struct*)OslConstructDataPtr(sizeof(bt_hf_disconnect_req_struct));

            srv_bt_dialer_addr_transfer(&req->bt_addr, &dev_info->bd_addr, MMI_FALSE);
            req->connection_id = dev_info->conn_id;
            dev_info->state = SRV_BTD_DEV_STATE_DISCONNECTING;
            mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_DISCONNECT_CNF, (PsIntFuncPtr)srv_bt_dialer_disconnect_cnf_hdlr, MMI_TRUE); 
            srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_DISCONNECT_REQ, MOD_BT);

            notify.event_id = SRV_BT_DIALER_EVT_ID_DISCONNECT_REQ;
            memcpy(&notify.result.conn_info.dev_addr, &dev_info->bd_addr, sizeof(srv_bt_cm_bt_addr));

            srv_bt_dialer_connection_notify(&notify);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_disconnect_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_disconnect_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_disconnect_cnf_struct *disconnect_rsp;
    srv_bt_dialer_dev_info_struct* dev_info_p = NULL;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_cm_bt_addr dev_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disconnect_rsp = (bt_hf_disconnect_cnf_struct*) msg;
    ASSERT(disconnect_rsp);

    srv_bt_dialer_addr_transfer(&dev_addr, &disconnect_rsp->bt_addr, MMI_TRUE);

    if (IsValidDevice(&dev_addr))
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_addr(&dev_addr);
    }

    if (dev_info_p == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_FATAL_ERR, 102, disconnect_rsp->connection_id,
            dev_addr.lap, dev_addr.uap, dev_addr.nap);
        srv_bt_dialer_dump_cur_device();
        return MMI_FALSE;
    }

    notify.event_id = SRV_BT_DIALER_EVT_ID_DISCONNECT_CNF;
    notify.result.conn_cnf.result = disconnect_rsp->result;
    memcpy(&notify.result.conn_cnf.dev_addr, &dev_info_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
    srv_bt_dialer_connection_notify(&notify);

    if(disconnect_rsp->result != 0)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_FAIL);

        if (dev_info_p->cm_conn_id != MMI_HF_INVALID_CM_CONN_ID)
        {
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID, dev_info_p->cm_conn_id);
            srv_bt_cm_stop_conn(dev_info_p->cm_conn_id);
        }

        if(dev_info_p->cm_cb)
        {
            dev_info_p->cm_cb(&dev_info_p->bd_addr, SRV_BT_CM_HF_CONNECTION,(MMI_BOOL)!disconnect_rsp->result,MMI_FALSE,MMI_FALSE);
        }

        srv_bt_dialer_del_device(&dev_info_p->bd_addr);

        return MMI_FALSE;
    }

    if (dev_info_p->state == SRV_BTD_DEV_STATE_DISCONNECTING)
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID, dev_info_p->cm_conn_id);
        srv_bt_cm_stop_conn(dev_info_p->cm_conn_id);
    }

    if(dev_info_p->cm_cb)
    {
        dev_info_p->cm_cb(&dev_info_p->bd_addr,SRV_BT_CM_HF_CONNECTION,(MMI_BOOL)!disconnect_rsp->result,MMI_FALSE,MMI_FALSE);
    }

    srv_bt_dialer_del_device(&dev_info_p->bd_addr);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_disconnect_ind
 * DESCRIPTION
 * CALLS
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_disconnect_ind(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_disconnect_ind_struct *disc_ind;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    disc_ind = (bt_hf_disconnect_ind_struct*) msg;
    ASSERT(disc_ind);
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_DISCONNECT_IND);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(disc_ind->connection_id);

    if (dev_info_p == NULL)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_FATAL_ERR, 103, disc_ind->connection_id,
            disc_ind->bt_addr.lap, disc_ind->bt_addr.uap, disc_ind->bt_addr.nap);
        srv_bt_dialer_dump_cur_device();
        return MMI_FALSE;
    }

    if (MMI_HF_INVALID_CM_CONN_ID != dev_info_p->cm_conn_id)
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID, dev_info_p->cm_conn_id);
        srv_bt_cm_stop_conn(dev_info_p->cm_conn_id);
    }

    notify.event_id = SRV_BT_DIALER_EVT_ID_DISCONNECT_IND;
    memcpy(&notify.result.conn_info.dev_addr, &dev_info_p->bd_addr, sizeof(srv_bt_cm_bt_addr));
    srv_bt_dialer_connection_notify(&notify);

    if(dev_info_p->cm_cb)
    {
        dev_info_p->cm_cb(&dev_info_p->bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_TRUE,MMI_FALSE,MMI_TRUE);
    }

    srv_bt_dialer_del_device(&dev_info_p->bd_addr);

    return MMI_TRUE;
}

#ifdef __MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_timeout_disconnect_ind
 * DESCRIPTION
 * 
  * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_timeout_disconnect_ind()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    mmi_btdialer_app_emit_timeout_event();
}
#endif /*__MMI_BT_ACL_TIMEOUT_DISCONNECT_NOTIFY__*/

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_hf_proc_func
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void

 *****************************************************************************/
mmi_ret srv_bt_dialer_hf_proc_func(mmi_event_struct *evt)
{
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_PROC_FUNC);

    if(g_srv_bt_dialer_p->hf_cmd != NULL)
    {
        srv_bt_dialer_HfExecuteNextCommand();
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_at_command
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_at_command(S32 srv_hd,
                                    srv_bt_dialer_at_cmd_type_enum type,
                                    srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evnt;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = srv_bt_dialer_get_dev_info_by_hd(srv_hd);

    if(dev_info_p == NULL)
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NOT_FIND_DEV , srv_hd);
        return SRV_BT_DIALER_FAILURE;
    }

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_PENDING_ACTION, dev_info_p->pending_action);

    if (type == SRV_BT_DIALER_AT_LIST_CURRENT_CALLS)
    {
        if (dev_info_p->querying)
        {
            return SRV_BT_DIALER_FAILURE;
        }
        else
        {
            dev_info_p->querying = MMI_TRUE;
        }
    }
    else if (dev_info_p->pending_action > SRV_BT_DIALER_AT_NONE
     && dev_info_p->pending_action < SRV_BT_DIALER_AT_LIST_CURRENT_CALLS)
    {
        return SRV_BT_DIALER_FAILURE;
    }
    else
    {
        dev_info_p->pending_action = type;
    }

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_SEND_AT_CMD, dev_info_p->srv_hd, dev_info_p->conn_id);
    srv_bt_dialer_add_node_to_list(dev_info_p->conn_id, btd_hf_cmd, type);
    MMI_FRM_INIT_EVENT((mmi_event_struct *)&evnt, SRV_BT_DIALER_AT_CMD_EVENT);
    mmi_frm_post_event((mmi_event_struct *)&evnt, (mmi_proc_func)srv_bt_dialer_hf_proc_func,NULL);
    return SRV_BT_DIALER_SUCCESS;
}

 /*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_ilm
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dialer_send_ilm(void *local_para, msg_type msg_id, module_type dst_mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(stack_get_active_module_id(),
                dst_mod,
                BT_APP_SAP,
                msg_id,
                (local_para_struct *)local_para);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_add_node_to_list
 * DESCRIPTION
 *  this function is to initialize the MMI WPS agent global context
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_add_node_to_list(U8 conn_id,
                                             srv_bt_dialer_AtHfCmd_struct *cmd,
                                             srv_bt_dialer_at_cmd_type_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_send_at_cmd_struct *temp = NULL;
    int len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    temp = (srv_bt_dialer_send_at_cmd_struct*)OslMalloc(sizeof(srv_bt_dialer_send_at_cmd_struct));

    memset((void *)temp,0,sizeof(srv_bt_dialer_send_at_cmd_struct));

    if(cmd != NULL)
    {
        temp->btd_hf_cmd = (srv_bt_dialer_AtHfCmd_struct*)OslMalloc(sizeof(srv_bt_dialer_AtHfCmd_struct));
        memset((void *)(temp->btd_hf_cmd),0,sizeof(srv_bt_dialer_AtHfCmd_struct));
        memcpy(temp->btd_hf_cmd, cmd,sizeof(srv_bt_dialer_AtHfCmd_struct));

        switch(type)
        {
            case SRV_BT_DIALER_AT_DIAL_NUMBER:
            {
                len = strlen(cmd->dial.number);
                temp->btd_hf_cmd->dial.number= (const char*)OslMalloc(len+1);
                memset((void *)(temp->btd_hf_cmd->dial.number),0,len+1);
                memcpy((char*)temp->btd_hf_cmd->dial.number, (char*)cmd->dial.number, len);
            }
            break;
            default:
            break;
        }
    }

    temp->conn_id = conn_id;
    temp->type = type;

    srv_bt_dialer_InsertTailList(temp);
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_HfGetCurrentCommand
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
srv_bt_dialer_send_at_cmd_struct * srv_bt_dialer_HfGetCurrentCommand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_send_at_cmd_struct *temp = g_srv_bt_dialer_p->hf_cmd;
    if(temp!=NULL)
    {
        if(temp->Flink!=NULL)
        {
            g_srv_bt_dialer_p->hf_cmd = temp->Flink;
        }
        else
        {
            g_srv_bt_dialer_p->hf_cmd = NULL;
        }
        return temp;
    }
    return NULL;
}
 /*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_HfExecuteNextCommand
 * DESCRIPTION
 *  This function is used to send ILM to WPS task
 * PARAMETERS
  * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_HfExecuteNextCommand(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     srv_bt_dialer_send_at_cmd_struct *command;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    command = srv_bt_dialer_HfGetCurrentCommand();

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_EXEC_AT_CMD, command->type, command->conn_id);

    if(command == NULL)
    {
        return;
    }

    switch (command->type)
    {
        case SRV_BT_DIALER_AT_DIAL_NUMBER:
        {
            srv_bt_dialer_atd_req(command);    
            if(command->btd_hf_cmd->dial.number)
            {
                OslMfree((void *)command->btd_hf_cmd->dial.number);
            }
            break;
        }
        case SRV_BT_DIALER_AT_ANSWER:
        {
            srv_bt_dialer_ata_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_HANG_UP:
        {
            srv_bt_dialer_atchup_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_CALL_HOLD:
        {
            srv_bt_dialer_atchld_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_CALL_ID:
        {
            srv_bt_dialer_atclip_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY:
        {
            srv_bt_dialer_atccwa_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_LIST_CURRENT_CALLS:
        {
            srv_bt_dialer_atclcc_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_REDIAL:
        {
            srv_bt_dialer_atbldn_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_XAPL:
        {
            srv_bt_dialer_atxapl_req(command);
            break;
        }
    #ifdef __MMI_HF_BAT_SUPPORT__
        case SRV_BT_DIALER_AT_IPHONEACCEV:
        {
            srv_bt_dialer_iphone_accev_req(command);
            break;
        }
    #endif /* __MMI_HF_BAT_SUPPORT__ */
    #ifndef __MMI_BTBOX_NOLCD__
        case SRV_BT_DIALER_AT_GENERATE_DTMF_TONE:
        {
            srv_bt_dialer_atvts_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_DIAL_MEMORY:
        {
            srv_bt_dialer_atmem_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_SPEAKER_GAIN:
        {
            srv_bt_dialer_vgs_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_MICROPHONE_GAIN:
        {
            srv_bt_dialer_vgm_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_EVENT_REPORTING:
        {
            srv_bt_dialer_atcmee_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_VOICE_TAG:
        {
            srv_bt_dialer_atbinp_req(command);
            break;
        }
    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_BT_DIALER_AT_VOICE_RECOGNITION:
        {
            srv_bt_dialer_atbvra_req(command);
            break;
        }
    #endif /* __BT_HF_BVRA_SUPPORT__ */
        case SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R:
        {
            srv_bt_dialer_atnrec_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_RESPONSE_AND_HOLD:
        {
            if(command->btd_hf_cmd->btrh.at_type == SRV_BT_DIALER_ATRESHOLD_READ)
            {
                srv_bt_dialer_atbtrh_read_req(command);
            }
            else if (command->btd_hf_cmd->btrh.at_type == SRV_BT_DIALER_ATRESHOLD_SET)
            {
                srv_bt_dialer_atbtrh_set_req(command);
            }
            break;
        }
        case SRV_BT_DIALER_AT_SUBSCRIBER_NUM:
        {
            srv_bt_dialer_atcnum_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_NETWORK_OPERATOR:
        {
            srv_bt_dialer_atcops_req(command);
            break;
        }
        case SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT:
        {
            srv_bt_dialer_set_atcops_req(command);
            break;
        }
    #endif /* __MMI_BTBOX_NOLCD__ */
    }
    if(command !=NULL && command->btd_hf_cmd)
        OslMfree(command->btd_hf_cmd);
    if(command !=NULL)
        OslMfree(command);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ind_notify_cb
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dialer_ind_notify_cb(U8 conn_id, srv_bt_dialer_notify_event_struct* notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (!dev_info_p)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_DEV_NOT_READY);
        return;
    }

    MMI_ASSERT(dev_info_p);

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_HF_IND_NOTIFY, conn_id, notify->event_id);

    if(dev_info_p && dev_info_p->cb_ptr && notify)
    {
        dev_info_p->cb_ptr(dev_info_p->srv_hd, notify); 
    }
    else
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_cmd_cnf_cb
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_bt_dialer_cmd_cnf_cb(U8 conn_id, srv_bt_dialer_notify_event_struct* notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if(!dev_info_p)
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NOT_FIND_DEV, conn_id);
        return;
    }

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_HF_CNF_NOTIFY, dev_info_p->pending_action, notify->event_id);

    if (dev_info_p->pending_action != SRV_BT_DIALER_AT_NONE)
    {
        dev_info_p->pending_action = SRV_BT_DIALER_AT_NONE;
    }

    if(dev_info_p && dev_info_p->cb_ptr && notify)
    {
        dev_info_p->cb_ptr(dev_info_p->srv_hd, notify); 
    }
    else
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_CB_PTR_ERR);
    }

}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ata_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_ata_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ata_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cmd_req);
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_ATA_CMD);
    req = (bt_hf_ata_req_struct*)OslConstructDataPtr(sizeof(bt_hf_ata_req_struct));
    req->connection_id = cmd_req->conn_id;
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATA_CNF, (PsIntFuncPtr)srv_bt_dialer_ata_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ATA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ata_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ata_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ata_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ata_cnf_struct*)msg;
    ASSERT(rsp);
    
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATA_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_ATA_CMD_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        srv_bt_dialer_reset_call_state(rsp->connection_id);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atd_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atd_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_atd_num_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cmd_req);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATD_CMD, cmd_req->btd_hf_cmd->dial.number);

    req = (bt_hf_atd_num_req_struct*)OslConstructDataPtr(sizeof(bt_hf_atd_num_req_struct));
    req->connection_id = cmd_req->conn_id;
    req->size = strlen((const char*)cmd_req->btd_hf_cmd->dial.number);
    strcpy((char*)req->number,(const char*)cmd_req->btd_hf_cmd->dial.number);
    req->number[req->size] = '\0';
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATD_NUM_CNF, (PsIntFuncPtr)srv_bt_dialer_atd_cnf_hdlr, MMI_TRUE);
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ATD_NUM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atd_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atd_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_atd_num_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_atd_num_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATD_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_DIAL_CMD_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        srv_bt_dialer_reset_call_state(rsp->connection_id);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atmem_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_atd_mem_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_MEM, cmd_req->btd_hf_cmd->mem_dial.index);

    req = (bt_hf_atd_mem_req_struct*)OslConstructDataPtr(sizeof(bt_hf_atd_mem_req_struct));
    req->index = cmd_req->btd_hf_cmd->mem_dial.index;
    req->connection_id = cmd_req->conn_id;
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ATD_MEM_CNF, (PsIntFuncPtr)srv_bt_dialer_atmem_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ATD_MEM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atmem_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_atd_mem_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_atd_mem_cnf_struct*) msg;
    ASSERT(rsp);

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ATMEM_CMD_CNF_HDLR,rsp->result);
    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_MEM_DIAL_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbldn_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbldn_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bldn_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BLDN);

    req = (bt_hf_bldn_req_struct*)OslConstructDataPtr(sizeof(bt_hf_bldn_req_struct));

    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BLDN_CNF, (PsIntFuncPtr)srv_bt_dialer_atbldn_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BLDN_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atmem_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbldn_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bldn_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_bldn_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BLDN_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_BLDN_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchup_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atchup_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_chup_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_CHUP_CMD);
    req = (bt_hf_chup_req_struct*)OslConstructDataPtr(sizeof(bt_hf_chup_req_struct));
    req->connection_id = cmd_req->conn_id;
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CHUP_CNF, (PsIntFuncPtr)srv_bt_dialer_atchup_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CHUP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchup_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atchup_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_chup_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_chup_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHUP_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_HANGUP_ACTIVE_CALLS_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        srv_bt_dialer_reset_call_state(rsp->connection_id);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcmee_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcmee_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     bt_hf_cmee_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CMEE, cmd_req->btd_hf_cmd->report.ind);

    req = (bt_hf_cmee_req_struct*)OslConstructDataPtr(sizeof(bt_hf_cmee_req_struct));
    req->enable = (MMI_BOOL)cmd_req->btd_hf_cmd->report.ind;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CMEE_CNF, (PsIntFuncPtr)srv_bt_dialer_atcmee_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CMEE_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcmee_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcmee_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     bt_hf_cmee_cnf_struct *rsp;
     srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_cmee_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CMEE_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CMEE_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atnrec_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_nrec_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_NREC);

    req = (bt_hf_nrec_req_struct*)OslConstructDataPtr(sizeof(bt_hf_nrec_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_NREC_CNF, (PsIntFuncPtr)srv_bt_dialer_atnrec_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_NREC_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atnrec_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_nrec_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_nrec_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_NREC_RSP,rsp->result);

    /*notify error to application*/
    /*rsp->cme_errcode*/
    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_NREC_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atvts_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
     bt_hf_vts_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VTS, cmd_req->btd_hf_cmd->dtmf.tone);

    req = (bt_hf_vts_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vts_req_struct));
    req->dtmf = cmd_req->btd_hf_cmd->dtmf.tone;
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VTS_CNF, (PsIntFuncPtr)srv_bt_dialer_atvts_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VTS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atnrec_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atvts_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vts_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_vts_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VTS_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_DTMF_CMD_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ring_ind_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ring_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_notify_event_struct notify;
    bt_hf_ring_ind_struct* rsp = (bt_hf_ring_ind_struct*)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_RING_ALERT);
    ASSERT(rsp);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE;

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_vgs_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgs_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGS, cmd_req->btd_hf_cmd->vgs.gain);

    req = (bt_hf_vgs_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vgs_req_struct));
    req->gain = cmd_req->btd_hf_cmd->vgs.gain;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGS_CNF, (PsIntFuncPtr)srv_bt_dialer_vgs_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VGS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgs_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgs_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_vgs_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGS_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VGS_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_vgm_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgm_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGM, cmd_req->btd_hf_cmd->vgm.gain);

    req = (bt_hf_vgm_req_struct*)OslConstructDataPtr(sizeof(bt_hf_vgm_req_struct));
    req->gain = cmd_req->btd_hf_cmd->vgm.gain;
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_VGM_CNF, (PsIntFuncPtr)srv_bt_dialer_vgm_cnf_hdlr, MMI_TRUE);
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VGM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgm_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgm_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_vgm_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_VGM_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VGM_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atchld_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atchld_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_chld_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHLD, cmd_req->btd_hf_cmd->hold.call);
    req = (bt_hf_chld_req_struct*)OslConstructDataPtr(sizeof(bt_hf_chld_req_struct));
    req->n = cmd_req->btd_hf_cmd->hold.call;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CHLD_CNF, (PsIntFuncPtr)srv_bt_dialer_atchld_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CHLD_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atchld_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atchld_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_chld_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_chld_cnf_struct*)msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CHLD_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_HOLD_ACTION_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        srv_bt_dialer_reset_call_state(rsp->connection_id);
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclip_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atclip_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_clip_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CLIP, cmd_req->btd_hf_cmd->callId.enabled);

    req = (bt_hf_clip_req_struct*)OslConstructDataPtr(sizeof(bt_hf_clip_req_struct));
    req->enable = (MMI_BOOL)cmd_req->btd_hf_cmd->callId.enabled;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLIP_CNF, (PsIntFuncPtr)srv_bt_dialer_atclip_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CLIP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atclip_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atclip_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_clip_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_clip_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CLIP_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_ID;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    srv_bt_dialer_enable_feature(rsp->connection_id);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atccwa_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atccwa_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ccwa_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CCWA, cmd_req->btd_hf_cmd->wait.notify);

    req = (bt_hf_ccwa_req_struct*)OslConstructDataPtr(sizeof(bt_hf_ccwa_req_struct));
    req->enable = (MMI_BOOL)cmd_req->btd_hf_cmd->wait.notify;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CCWA_CNF, (PsIntFuncPtr)srv_bt_dialer_atccwa_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CCWA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  MMI_BOOLsrv_bt_dialer_atccwa_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atccwa_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ccwa_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ccwa_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CCWA_CMD_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_WAIT_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    srv_bt_dialer_enable_feature(rsp->connection_id);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_atcops_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_set_atcops_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cops_set_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_SET_AT_COPS);

    req = (bt_hf_cops_set_req_struct*)OslConstructDataPtr(sizeof(bt_hf_cops_set_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_COPS_SET_CNF, (PsIntFuncPtr)srv_bt_dialer_set_atcops_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_COPS_SET_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_atcops_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_set_atcops_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cops_set_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_cops_set_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_SET_AT_COPS_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcops_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcops_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cops_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_COPS);

    req = (bt_hf_cops_req_struct*)OslConstructDataPtr(sizeof(bt_hf_cops_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_COPS_CNF, (PsIntFuncPtr)srv_bt_dialer_atcops_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_COPS_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcops_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcops_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cops_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_cops_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SSRV_BT_DIALER_AT_COPS_CNF_HDLR,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_NETWORK_OPERATOR;
    notify.result.networkOper_read.mode = 0;
    notify.result.networkOper_read.format = SRV_BT_DIALER_ATOF_LONG_ALPHANUM;
    notify.result.networkOper_read.final = rsp->final;
    notify.result.networkOper_read.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode, rsp->result);
    notify.result.networkOper_read.oper = (const char*)OslMalloc(rsp->size+1);    
    memset((void*)notify.result.networkOper_read.oper,0, rsp->size +1);        
    strncpy((char *)notify.result.networkOper_read.oper,(char *)rsp->operator_string, rsp->size);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    OslMfree((void*)notify.result.networkOper_read.oper);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcnum_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atcnum_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cnum_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_CNUM);

    req = (bt_hf_cops_req_struct*)OslConstructDataPtr(sizeof(bt_hf_cops_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CNUM_CNF, (PsIntFuncPtr)srv_bt_dialer_atcnum_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CNUM_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atcnum_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atcnum_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_cnum_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_cnum_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_CNUM_CNF,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_SUBSCRIBER_NUM;
    notify.result.subscribeNum.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
    notify.result.subscribeNum.service = rsp->service;
    notify.result.subscribeNum.final = rsp->final;
    notify.result.subscribeNum.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode, rsp->result);
    notify.result.subscribeNum.number = (char *)OslMalloc(rsp->size+1);
    memset((void *)notify.result.subscribeNum.number,0,rsp->size+1);
    strncpy((char *)notify.result.subscribeNum.number,(char *)rsp->number,rsp->size);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    OslMfree((void*)notify.result.subscribeNum.number);

    return MMI_TRUE;
}


#ifdef __BT_HF_BVRA_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbvra_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbvra_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bvra_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BVRA, cmd_req->btd_hf_cmd->vrec.enabled);

    req = (bt_hf_bvra_req_struct*)OslConstructDataPtr(sizeof(bt_hf_bvra_req_struct));
    req->enable = cmd_req->btd_hf_cmd->vrec.enabled;
    req->connection_id = cmd_req->conn_id;
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BVRA_CNF, (PsIntFuncPtr)srv_bt_dialer_atbvra_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BVRA_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbvra_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbvra_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bvra_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_bvra_cnf_struct*) msg;
    ASSERT(rsp);

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BVRA_CNF,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_BVRA_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(rsp->result != HF_FINAL_RESULT_CODE_OK)
    {   
        return MMI_FALSE;
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_bvra_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_bvra_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bvra_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_bvra_ind_struct*) msg;
    ASSERT(rsp);

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_BVRA_IND,rsp->enable);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->bvra_enable  = rsp->enable;
    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VOICE_RECOGNITION;
    notify.result.vrec.enabled = rsp->enable;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_voice_recognition_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_voice_recognition_req(S32 srv_hd, MMI_BOOL enabled_vr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.vrec.enabled = enabled_vr;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_VOICE_RECOGNITION, &btd_hf_cmd); 
}
#endif /* __BT_HF_BVRA_SUPPORT__ */


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbinp_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbinp_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_binp_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BNIP);

    req = (bt_hf_binp_req_struct*)OslConstructDataPtr(sizeof(bt_hf_binp_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BINP_CNF, (PsIntFuncPtr)srv_bt_dialer_atbinp_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BINP_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbinp_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbinp_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_binp_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_binp_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BNIP_CNF,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VOICE_TAG;
    notify.result.voiceTag.final = rsp->final;
    notify.result.voiceTag.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode, rsp->result);
    notify.result.voiceTag.number =(char *)OslMalloc(rsp->size+1);
    memset((void *)notify.result.voiceTag.number,0,rsp->size+1);
    strncpy( (char *)notify.result.voiceTag.number , (char *)rsp->number,rsp->size);

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    OslMfree((void *)notify.result.voiceTag.number);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_read_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbtrh_read_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_btrh_req_struct* req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_AT_BTRH);

    req = (bt_hf_btrh_req_struct*)OslConstructDataPtr(sizeof(bt_hf_btrh_req_struct));
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_READ_CNF, (PsIntFuncPtr)srv_bt_dialer_atbtrh_read_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BTRH_READ_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_read_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbtrh_read_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_btrh_read_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_btrh_read_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_BTRH_CNF,rsp->result,rsp->n);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
    notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;
    notify.result.btrh.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode, rsp->result);
    notify.result.btrh.final = rsp->final;

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_set_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atbtrh_set_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_btrh_set_req_struct *req;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_BTRH_SET,cmd_req->btd_hf_cmd->btrh.setting);
    req = (bt_hf_btrh_set_req_struct*)OslConstructDataPtr(sizeof(bt_hf_btrh_set_req_struct));
    req->n = (U8)cmd_req->btd_hf_cmd->btrh.setting;
    req->connection_id = cmd_req->conn_id;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_BTRH_SET_CNF, (PsIntFuncPtr)srv_bt_dialer_atbtrh_set_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_BTRH_SET_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atbtrh_set_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atbtrh_set_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_btrh_set_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_btrh_set_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_BTRH_SET_CNF,rsp->result,rsp->n);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
    notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;
    notify.result.btrh.final = rsp->final;
    notify.result.btrh.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);
    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclcc_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atclcc_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_clcc_req_struct* req;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_CLCC_REQ);
    req = (bt_hf_clcc_req_struct*)OslConstructDataPtr(sizeof(bt_hf_clcc_req_struct));
    req->connection_id = cmd_req->conn_id;

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(cmd_req->conn_id);
    dev_info_p->call_count = 0;

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_CLCC_CNF, (PsIntFuncPtr)srv_bt_dialer_atclcc_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CLCC_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atclcc_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atclcc_cnf_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_clcc_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_clcc_cnf_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CLCC_CNF,rsp->result);


    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_LIST_CURRENT_CALLS;

    notify.result.currentCalls.final = rsp->final;
    notify.result.currentCalls.index = rsp->index;
    notify.result.currentCalls.dir = rsp->dir;
    notify.result.currentCalls.mode = rsp->mode;
    notify.result.currentCalls.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
    notify.result.currentCalls.state = (srv_bt_dialer_AtCallState_enum)rsp->status;
    notify.result.currentCalls.multiParty = rsp->multiparty;
    notify.result.currentCalls.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    if(!rsp->final)
    {
        MMI_ASSERT(dev_info_p);
        notify.result.currentCalls.number = (char *)OslMalloc(rsp->size+1);
        memset((void *)notify.result.currentCalls.number,0,rsp->size+1);
        strncpy((char *)notify.result.currentCalls.number,(char *)rsp->number,rsp->size);
        dev_info_p->call_count++;
    }

    if (dev_info_p && rsp->final && dev_info_p->querying)
    {
        dev_info_p->querying = MMI_FALSE;
    }

    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    if(!rsp->final)
    {
        OslMfree((void*)notify.result.currentCalls.number);
    }

    return MMI_TRUE;
}


#ifdef __MMI_HF_BAT_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_iphone_accev_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_iphone_accev_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_accev_req_struct* req;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cmd_req && cmd_req->btd_hf_cmd);

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_ACCEV_REQ, cmd_req->btd_hf_cmd->accev.key, cmd_req->btd_hf_cmd->accev.bat);

    req = (bt_hf_accev_req_struct*)OslConstructDataPtr(sizeof(bt_hf_accev_req_struct));
    req->connection_id = cmd_req->conn_id;
    req->num = 0;

    // Number of key/value pairs: The number of parameers coming next.
    if (cmd_req->btd_hf_cmd->accev.key & SRV_BT_DIALER_ACCEV_BAT)
    {
        req->key[req->num] = SRV_BT_DIALER_ACCEV_BAT;
        req->value[req->num] = cmd_req->btd_hf_cmd->accev.bat;
        req->num++;
    }
    if (cmd_req->btd_hf_cmd->accev.key & SRV_BT_DIALER_ACCEV_POW)
    {
        req->key[req->num] = SRV_BT_DIALER_ACCEV_POW;
        req->value[req->num] = cmd_req->btd_hf_cmd->accev.pow;
        req->num++;
    }

    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_ACCEV_CNF, (PsIntFuncPtr)srv_bt_dialer_iphone_accev_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_ACCEV_REQ, MOD_BT);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_iphone_accev_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_iphone_accev_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_accev_cnf_struct* rsp;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_accev_cnf_struct*)msg;

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_ACCEV_CNF,rsp->result);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_ACCEV_RSP;
    notify.result.error_code.error = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);
    srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);

    srv_bt_dialer_enable_feature(rsp->connection_id);

    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_battery_report_req
 * DESCRIPTION: reports a battery change to Iphone
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_battery_report_req(S32 srv_hd, U32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.accev.key = SRV_BT_DIALER_ACCEV_BAT;
    btd_hf_cmd.accev.bat = value;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_IPHONEACCEV, &btd_hf_cmd); 

}
#endif /* __MMI_HF_BAT_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atxapl_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_atxapl_req(srv_bt_dialer_send_at_cmd_struct* cmd_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_xapl_req_struct *req;
    CHAR* id_ver_p = "MTK-BTD-v3.0";

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cmd_req && cmd_req->btd_hf_cmd);

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_AT_XAPL_REQ, cmd_req->btd_hf_cmd->xapl.features);

    req = (bt_hf_xapl_req_struct*)OslConstructDataPtr(sizeof(bt_hf_xapl_req_struct));
    req->connection_id = cmd_req->conn_id;
    req->features = cmd_req->btd_hf_cmd->xapl.features;

    strncpy((CHAR*)req->id_version, id_ver_p, MAX_HF_XAPL_NUMBER_LENGTH);
    req->size = strlen(id_ver_p) + 1; // 1 for '\0'
    MMI_ASSERT(req->size < MAX_HF_XAPL_NUMBER_LENGTH);
    
    mmi_frm_set_protocol_event_handler(MSG_ID_BT_HF_XAPL_CNF, (PsIntFuncPtr)srv_bt_dialer_atxapl_cnf_hdlr, MMI_TRUE);    
    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_XAPL_REQ, MOD_BT);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_atxapl_cnf_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_atxapl_cnf_hdlr(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_xapl_cnf_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_xapl_cnf_struct*)msg;

    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_AT_XAPL_CNF, rsp->result, rsp->features);

    if (rsp->final)
    {
        srv_bt_dialer_enable_feature(rsp->connection_id);
    }
    else
    {
        notify.event_id = SRV_BT_DIALER_EVT_ID_AT_XAPL_RSP;
        notify.result.xapl.features = rsp->features;
        result = srv_bt_dialer_convert_error_code(rsp->cme_errcode,rsp->result);
    
        if (result == SRV_BT_DIALER_ATCME_SUCCESS)
        {
            notify.result.xapl.valid = MMI_TRUE;
        }
        else
        {
            notify.result.xapl.valid = MMI_FALSE;
        }

        srv_bt_dialer_cmd_cnf_cb(rsp->connection_id, &notify);
    }

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_bsir_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_bsir_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_bsir_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_bsir_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_IN_BAND_RING_IND,rsp->enable);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    dev_info_p->bsir_enable  = rsp->enable;

    // just for BQB TP/ICA/BV-05-I
    dev_info_p->bsir_bqb_state = rsp->enable + 1;

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_BSIR_IND;
    notify.result.inBandRing.enabled = rsp->enable;
           
    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);
    return MMI_TRUE;
}


#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_is_bt_call_allowed
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_bt_dialer_is_bt_call_allowed(U8 setup, U8 call, U8 held)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_TRUE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_DIALER_HF_BT_CALL_ALLOWED, g_srv_bt_dialer_p->bt_call_unallowed, setup, call, held);
    if (g_srv_bt_dialer_p->bt_call_unallowed && setup != 1 && setup != 2)
    {
        return MMI_FALSE;
    }

    if (srv_ucm_is_incoming_call())
    {
        if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
        {
            if (1 == setup || 2 == setup)
            {
                g_srv_bt_dialer_p->bt_call_unallowed = MMI_TRUE;
                result = MMI_FALSE;
            }
        }
        else
        {
            if (setup != 0 || call != 0 || held != 0)
            {
                g_srv_bt_dialer_p->bt_call_unallowed = MMI_TRUE;
                result = MMI_FALSE;
            }
        }
    }
    else
    {
        g_srv_bt_dialer_p->bt_call_unallowed = MMI_FALSE;
        result = MMI_TRUE;
    }
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_BT_CALL_ALLOWED_RESULT, result);
    return result;
}
#endif /* __MMI_TELEPHONY_SUPPORT__ */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_service_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_service_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_service_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_service_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_CIEV_SERVICE_IND,rsp->service);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->ciev_service  = (MMI_BOOL)rsp->service;

    if(dev_info_p->ind_mask & SRV_BT_DIALER_UNMASK_CIEV_SERVICE_INDICATION)
    {
        notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
        notify.result.event.indicator = SRV_BT_DIALER_UNMASK_CIEV_SERVICE_INDICATION;
        notify.result.event.value = rsp->service;
        srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_call_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_call_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_call_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_call_ind_struct*) msg;
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_CIEV_CALL_IND,rsp->call);
    ASSERT(rsp);
#ifdef __MMI_WEARABLE_DEVICE__
    if (!vm_is_bt_call_allowed())
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WEARABLE_DEVICE__ */

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    if (dev_info_p->pending_action == SRV_BT_DIALER_AT_DIAL_NUMBER)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_bt_dialer_is_bt_call_allowed(0 , rsp->call, 0))
    {
        return MMI_FALSE;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */

    // must before dev_info_p->ciev_call  = rsp->call;
    srv_bt_dialer_set_hilite_dev(rsp->connection_id, dev_info_p->callsetup, rsp->call, dev_info_p->callheld);

    dev_info_p->ciev_call  = rsp->call;

    notify.event_id = SRV_BT_DIALER_CIEV_CALL_INDICATION;
    notify.result.call_ind.call = (srv_bt_dialer_call_ind_enum)rsp->call;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

#ifndef __BT_DIALER_HF_SCO_ALWAYS__
    if((dev_info_p->ciev_call == 1) && (!dev_info_p->sco_auto))
    {
        if(srv_btsco_is_sco_open() == MMI_TRUE)
        {
            srv_btsco_dialer_close_stream_req();
            // dev_info_p->sco_auto = MMI_TRUE;
        }
    }
#endif /* __BT_DIALER_HF_SCO_ALWAYS__ */
#ifdef __BT_DIALER_HF_NO_IN_BAND_TONE__
    if ((dev_info_p->ciev_call == 1) && srv_bt_dialer_get_mute_inband_flag(rsp->connection_id))
    {
        srv_bt_dialer_set_mute_inband_flag(rsp->connection_id, MMI_FALSE);
        mdi_audio_stop_all();
        if (srv_btsco_is_sco_open())
        {
            mdi_audio_set_sco_mode(MDI_AUD_BT_SCO_MODE_BT_DIALER);
        }
    }
#endif /* __BT_DIALER_HF_NO_IN_BAND_TONE__ */
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_callsetup_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_callsetup_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_callsetup_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_callsetup_ind_struct*) msg;
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CIEV_CALLSETUP_IND,rsp->callsetup);
    ASSERT(rsp);
#ifdef __MMI_WEARABLE_DEVICE__
    if (!vm_is_bt_call_allowed())
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WEARABLE_DEVICE__ */
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    if (dev_info_p->pending_action == SRV_BT_DIALER_AT_DIAL_NUMBER)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_bt_dialer_is_bt_call_allowed(rsp->callsetup, 0, 0))
    {
        return MMI_FALSE;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */

    // must before dev_info_p->callsetup  = rsp->callsetup;
    srv_bt_dialer_set_hilite_dev(rsp->connection_id, rsp->callsetup, dev_info_p->ciev_call, dev_info_p->callheld);

    dev_info_p->callsetup  = rsp->callsetup;

    notify.event_id = SRV_BT_DIALER_CIEV_CALL_SETUP_INDICATION;
    notify.result.call_setup_ind.setup = (srv_bt_dialer_call_setup_ind_enum)rsp->callsetup;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

#ifndef __BT_DIALER_HF_SCO_ALWAYS__
    if( (dev_info_p->callsetup == 3) && (!dev_info_p->sco_auto))
    {
        if(srv_btsco_is_sco_open() == MMI_TRUE)
        {
            srv_btsco_dialer_close_stream_req();
        }
    }
#endif /* __BT_DIALER_HF_SCO_ALWAYS__ */
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_callheld_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_callheld_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_callheld_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_callheld_ind_struct*) msg;
    ASSERT(rsp);
#ifdef __MMI_WEARABLE_DEVICE__
    if (!vm_is_bt_call_allowed())
    {
        return MMI_FALSE;
    }
#endif /* __MMI_WEARABLE_DEVICE__ */

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    if (dev_info_p->pending_action == SRV_BT_DIALER_AT_DIAL_NUMBER)
    {
        return MMI_FALSE;
    }
#ifdef __MMI_TELEPHONY_SUPPORT__
    if (!srv_bt_dialer_is_bt_call_allowed(0, 0, rsp->callheld))
    {
        return MMI_FALSE;
    }
#endif /* __MMI_TELEPHONY_SUPPORT__ */
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_CALL_HELD_IND,rsp->callheld);

    // must before     dev_info_p->callheld  = rsp->callheld;
    srv_bt_dialer_set_hilite_dev(rsp->connection_id, dev_info_p->callsetup, dev_info_p->ciev_call, rsp->callheld);

    dev_info_p->callheld  = rsp->callheld;

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD;
    notify.result.held_ind.held = (srv_bt_dialer_AtHeldInd_enum)rsp->callheld;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_signal_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_signal_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_signal_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_signal_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_SIGNAL_IND,rsp->signal);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->ciev_signal  = rsp->signal;

    if(dev_info_p->ind_mask & SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION)
    {
        notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
        notify.result.event.indicator = SRV_BT_DIALER_UNMASK_CIEV_SIGNAL_INDICATION;
        notify.result.event.value = rsp->signal;                
        srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);
    }        
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_roam_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_roam_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_roam_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_roam_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_ROAMING_IND,rsp->roam);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->ciev_roam  = rsp->roam;

    if(dev_info_p->ind_mask & SRV_BT_DIALER_UNMASK_ROAM_INDICATION)
    {
        notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
        notify.result.event.indicator = SRV_BT_DIALER_UNMASK_ROAM_INDICATION;
        notify.result.event.value = dev_info_p->ciev_roam;
        srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ciev_battchg_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ciev_battchg_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ciev_battchg_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ciev_battchg_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_BATTCH_IND,rsp->battchg);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);
    if (dev_info_p == NULL)
    {
        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(MMI_HF_TEMP_CONN_ID);
    }

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->ciev_battchg  = rsp->battchg;

    if(dev_info_p->ind_mask & SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION)
    {
        notify.event_id = SRV_BT_DIALER_EVT_ID_AT_INDICATOR_EVENT;
        notify.result.event.indicator = SRV_BT_DIALER_UNMASK_BATTCHG_INDICATION;
        notify.result.event.value = dev_info_p->ciev_battchg;        
        srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);
    }    
    return MMI_TRUE;
}


/*************************************************************
 [HF RING]
**************************************************************/
/* MSG_ID_BT_HF_RING_IND */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_clip_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_clip_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_clip_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_clip_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_CLIP_IND);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    notify.event_id = SRV_BT_DIALER_EVT_ID_CLIP_IND;
    notify.result.callId.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;
    notify.result.callId.number = (char *)OslMalloc(rsp->size+1);
    memset((void *)notify.result.callId.number,0,rsp->size+1);
    strncpy((char *)notify.result.callId.number,(char*)rsp->number,rsp->size);

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    OslMfree((void*)notify.result.callId.number);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_ccwa_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_ccwa_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_ccwa_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_ccwa_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG(SRV_BT_DIALER_LOG_CCWA_IND);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_CALL_WAIT_NOTIFY;
    notify.result.wait.number = (const char*)OslMalloc(rsp->size+1);
    memset((void*)notify.result.wait.number,0, rsp->size +1);
    strncpy((char *)notify.result.wait.number, (char *)rsp->number, rsp->size);
    notify.result.wait.type = (srv_bt_dialer_AtNumberFormat_enum)rsp->type;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    OslMfree((void*)notify.result.wait.number);
    
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_btrh_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_btrh_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_btrh_ind_struct *rsp;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_btrh_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_LOG_BTRH_IND,rsp->n);

    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(rsp->connection_id);

    if (dev_info_p == NULL)
    {
        return MMI_FALSE;
    }

    dev_info_p->btrh_n  = rsp->n;
    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_RESPONSE_AND_HOLD;
    notify.result.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)rsp->n;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgs_ind
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgs_ind(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgs_ind_struct *rsp;
    bt_hf_vgs_ind_res_struct* req;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_vgs_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_VGS_IND,rsp->gain);

    notify.event_id = SRV_BT_DIALER_EVT_ID_AT_VGS_IND;
    notify.result.vgs.gain = rsp->gain;

    srv_bt_dialer_ind_notify_cb(rsp->connection_id, &notify);

    req = (bt_hf_vgs_ind_res_struct*)OslConstructDataPtr(sizeof(bt_hf_vgs_ind_res_struct));

    req->connection_id = rsp->connection_id;
    req->gain          = rsp->gain;

    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_VGS_IND_RES, MOD_BT);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_vgm_ind_hdlr
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_vgm_ind_hdlr(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_hf_vgm_ind_struct *rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    rsp = (bt_hf_vgm_ind_struct*) msg;
    ASSERT(rsp);
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_VGM_IND,rsp->gain);
    /*call MDI API to notify volume gain*/
    //mdi_audio_sync_volume_from_bt(rsp->gain);
    return MMI_TRUE;
}


/*---------------------------------------------------------------------------
 *            _srv_bt_dialer_InsertTailList()
 *---------------------------------------------------------------------------
 *
 * Synopsis:  Insert an entry at the tail of the list specified by head.
 *
 * Return:    void
 */
void srv_bt_dialer_InsertTailList(srv_bt_dialer_send_at_cmd_struct* entry)
{
    srv_bt_dialer_send_at_cmd_struct *temp = g_srv_bt_dialer_p->hf_cmd;
    if(temp == NULL)
    {
        g_srv_bt_dialer_p->hf_cmd = entry;
        g_srv_bt_dialer_p->hf_cmd->Flink = NULL;
    }
    else
    {
        while(temp->Flink != NULL)
        {
            temp = temp->Flink;
        }
        temp->Flink = entry;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_handle_pending_at_cmd
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_handle_pending_at_cmd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evnt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT((mmi_event_struct *)&evnt, SRV_BT_DIALER_AT_CMD_EVENT);
    if(g_srv_bt_dialer_p->hf_cmd != NULL)
    {
        mmi_frm_post_event((mmi_event_struct *)&evnt, (mmi_proc_func)srv_bt_dialer_hf_proc_func,NULL);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_convert_error_code
 * DESCRIPTION: 
 *  Convert result and CME error codes and send result to APP
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_bt_dialer_convert_error_code(S32 error,S32 result_code)
{
    S32 err_code;
    switch(result_code)
    {
        case HF_FINAL_RESULT_CODE_OK:
        {
            err_code = SRV_BT_DIALER_ATCME_SUCCESS;
        }
        break;

        case HF_FINAL_RESULT_CODE_CME_ERROR:
        {
            err_code = error;
        }
        break;

        case HF_FINAL_RESULT_CODE_TIMEOUT:
        {
            err_code = SRV_BT_DIALER_CMD_TIME_OUT;
        }
        break;

        default:
        {
            err_code = SRV_BT_DIALER_INTERNAL_ERROR;
        }
        break;
    }
    return err_code;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_ata_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_ata_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_at_cmd_type_enum type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    type = SRV_BT_DIALER_AT_ANSWER;
    return srv_bt_dialer_send_at_command(srv_hd, type, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_dial_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_dial_req(S32 srv_hd, const char *number)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    MMI_BOOL result;
    U32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if((number != NULL))
    {
        len = strlen(number);
        btd_hf_cmd.dial.number = (const char*)OslMalloc(len+1);
        memset((void *)btd_hf_cmd.dial.number,0, len+1);
        memcpy((char *)btd_hf_cmd.dial.number,number, len+1);
        result = srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_DIAL_NUMBER, &btd_hf_cmd);         
        OslMfree((void*)btd_hf_cmd.dial.number);
        return result;
    }
    return SRV_BT_DIALER_FAILURE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_hangup_current_call
 * DESCRIPTION:
 *Hangup all currently active calls. It will also end any incoming call.
 * So when there is any call waiting, and give this command, it will
 * release the waiting call. Also it will release the outgoing call which is
 * not still active.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_hangup_current_call(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_HANG_UP,NULL); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_set_clip_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_set_clip_req(S32 srv_hd, MMI_BOOL enable_callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.callId.enabled = enable_callId;       
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_ID, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_speaker_vol_gain_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_speaker_vol_gain_req(S32 srv_hd,U8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.vgs.gain = gain;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_SPEAKER_GAIN,&btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_mic_vol_gain_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_mic_vol_gain_req(S32 srv_hd, U8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.vgm.gain = gain;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_MICROPHONE_GAIN, &btd_hf_cmd); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_generate_dtmf_tone_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_generate_dtmf_tone_req(S32 srv_hd, U8 tone)
{
#ifndef __MMI_BTBOX_NOLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.dtmf.tone = tone;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_GENERATE_DTMF_TONE,  &btd_hf_cmd);
#else
    return MMI_FALSE;
#endif /* __MMI_BTBOX_NOLCD__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_enable_custom_at_cmd_req
 * DESCRIPTION: enable custom AT commands from an accessory
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_enable_custom_at_cmd_req(S32 srv_hd, U8 feature)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_BT_DIALER_XAPL_NONE != feature)
    {
        btd_hf_cmd.xapl.features = feature;
        result = srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_XAPL, &btd_hf_cmd);
    }
    else
    {
        result = MMI_FALSE;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_voice_tag_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_voice_tag_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_VOICE_TAG, NULL); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_noise_red_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_noise_red_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R, NULL); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_redial_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_redial_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_REDIAL, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_network_operator_format
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_set_network_operator_format(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT, NULL); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_network_operator_info_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_get_network_operator_info_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_NETWORK_OPERATOR, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_list_current_calls
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_list_current_calls(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_LIST_CURRENT_CALLS, NULL); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_subscriber_num_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_subscriber_num_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_SUBSCRIBER_NUM, NULL); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_call_wait_notify_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_call_wait_notify_req(S32 srv_hd, MMI_BOOL wait)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.wait.notify = wait;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_event_reporting
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_event_reporting(S32 srv_hd, U8 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.report.ind = event;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_EVENT_REPORTING, &btd_hf_cmd); 
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_call_retrieve_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_call_retrieve_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_HOLD_ACTIVE_CALLS;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_HOLD, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_release_all_held_calls
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_release_all_held_calls(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_RELEASE_HELD_CALLS;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_HOLD, &btd_hf_cmd);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_release_all_active_calls
 * Releases all active calls (if any exist) and accepts the other
 *  (held or waiting) call. If "call" is specified, will release the
 *  specific call.
  *  Note - In case of no index ,specify  'Call' as  '-1'
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_release_all_active_calls(S32 srv_hd,S8 Call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(Call != (S8)-1)
    {
        btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_RELEASE_ACTIVE_CALLS*10 + Call;
    }
    else
    {
        btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_RELEASE_ACTIVE_CALLS;
    }
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_HOLD, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_release_all_active_calls
 * Releases all active calls (if any exist) and accepts the other
 *  (held or waiting) call. If "call" is specified, will release the
 *  specific call.
 *  Note - In case of no index ,specify  'Call' as  '-1'
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_hold_all_active_calls(S32 srv_hd,S8 Call)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(Call != (S8)-1)
    {
        btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_HOLD_ACTIVE_CALLS*10 + Call;
    }
    else
    {
        btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_HOLD_ACTIVE_CALLS;
    }
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_HOLD, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_add_held_call_to_conversation
 * Releases all active calls (if any exist) and accepts the other
     *  (held or waiting) call. If "call" is specified, will release the
     *  specific call.
     *
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_add_held_call_to_conversation(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.hold.call = SRV_BT_DIALER_AT_HOLD_ADD_HELD_CALL;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_CALL_HOLD, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_hold_response_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_hold_response_set_req(S32 srv_hd,srv_bt_dialer_AtResponseHold_enum index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.btrh.setting = (srv_bt_dialer_AtResponseHold_enum)index;
    btd_hf_cmd.btrh.at_type = SRV_BT_DIALER_ATRESHOLD_SET;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_RESPONSE_AND_HOLD, &btd_hf_cmd); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_send_read_hold_req
 * DESCRIPTION: This function is used to receive notification event
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_send_response_hold_read_req(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_AtHfCmd_struct btd_hf_cmd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    btd_hf_cmd.btrh.at_type = SRV_BT_DIALER_ATRESHOLD_READ;
    return srv_bt_dialer_send_at_command(srv_hd, SRV_BT_DIALER_AT_RESPONSE_AND_HOLD, &btd_hf_cmd); 
}


#ifdef __MMI_WEARABLE_DEVICE__
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_cm_connect_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_single_connect_req(srv_bt_cm_bt_addr *bd_addr,srv_bt_dialer_single_connect_notify srv_sg_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/
    bt_hf_connect_req_struct *req;
    S32 cm_conn_id;
    srv_bt_dialer_dev_info_struct* dev_info;
    srv_bt_dialer_notify_event_struct notify;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bd_addr);

    SRV_BT_DIALER_LOG3(SRV_BT_DIALER_CONNECT_REQ, bd_addr->lap, bd_addr->uap, bd_addr->nap);

    dev_info = srv_bt_dialer_get_dev_info_by_addr(bd_addr);

    if(dev_info != NULL && (dev_info->state == SRV_BTD_DEV_STATE_CONNECTED || dev_info->state == SRV_BTD_DEV_STATE_CONNECTING))
    {
        if (srv_sg_cb)
        {
            srv_sg_cb(bd_addr, MMI_FALSE);
        }
        return;
    }

    dev_info = srv_bt_dialer_new_device(bd_addr, MMI_FALSE);

    if (!dev_info)
    {
        SRV_BT_DIALER_LOG(SRV_BT_DIALER_HF_NEW_DEV_FAIL);
        if (srv_sg_cb)
        {
            srv_sg_cb(bd_addr, MMI_FALSE);
        }
        return;
    }

    dev_info->sg_conn_cb = srv_sg_cb;

    cm_conn_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_HF_PROFILE_UUID, bd_addr, NULL);

    if(cm_conn_id < 0 || !srv_bt_dialer_is_serv_ready())
    {
        if (cm_conn_id > 0 && cm_conn_id <= SRV_BT_CM_MAX_CONNECTION)
        {
            SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_FREE_CM_ID , cm_conn_id);
            srv_bt_cm_stop_conn(cm_conn_id);
        }

        if(dev_info->cm_cb)
        {
            dev_info->cm_cb(bd_addr, SRV_BT_CM_HF_CONNECTION,MMI_FALSE,MMI_TRUE,MMI_FALSE);
        }

        srv_bt_dialer_del_device(bd_addr);

        return;
    }

    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_ALLOC_CM_ID, cm_conn_id);
    dev_info->cm_conn_id = cm_conn_id;
    dev_info->conn_id = MMI_HF_TEMP_CONN_ID;
    dev_info->state = SRV_BTD_DEV_STATE_CONNECTING;

    req = (bt_hf_connect_req_struct*)OslConstructDataPtr(sizeof(bt_hf_connect_req_struct));

    srv_bt_dialer_addr_transfer(&req->bt_addr, bd_addr, MMI_FALSE);
    
    req->hs_conn = MMI_FALSE;

    notify.event_id = SRV_BT_DIALER_EVT_ID_CONNECT_REQ;
    memcpy(&notify.result.conn_info.dev_addr, bd_addr, sizeof(srv_bt_cm_bt_addr));

    srv_bt_dialer_connection_notify(&notify);

    srv_bt_dialer_send_ilm((void*)req, MSG_ID_BT_HF_CONNECT_REQ, MOD_BT);
}
#endif /* __MMI_WEARABLE_DEVICE__ */

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_cm_connect_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_cm_connect_req(srv_bt_cm_bt_addr *dev_addr,srv_bt_dialer_cm_connect_notify srv_cm_cb)
{
    srv_bt_dialer_send_connect_req(dev_addr, srv_cm_cb);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_cm_disconnect_req
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_cm_disconnect_req(srv_bt_cm_bt_addr *bt_addr, srv_bt_dialer_cm_connect_notify srv_cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_addr(bt_addr);

    if (dev_info)
    {
        if(srv_cm_cb != NULL)
        {
            dev_info->cm_cb = srv_cm_cb;
        }
        srv_bt_dialer_send_disconnect_req(dev_info->cm_conn_id);
    }
    else if (srv_cm_cb != NULL)
    {
        srv_cm_cb(bt_addr, SRV_BT_CM_HF_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
    }
    else
    {
        SRV_BT_DIALER_LOG2(SRV_BT_DIALER_DISCONNECT_ERR, dev_info, srv_cm_cb);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_post_evt_to_a2dp
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_post_evt_to_a2dp(void)
{
#ifdef __MMI_BT_DIALER_SUPPORT__
    mmi_event_struct evt;

    if (!srv_bt_dialer_is_any_call())
    {
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_DIALER_EVENT_ALL_CALL_END_ID);
        mmi_frm_cb_emit_post_event(&evt);
    }
#endif /* __MMI_BT_DIALER_SUPPORT__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_hilite_dev
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_is_sco_allow(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG2(SRV_BT_DIALER_IS_SCO_ALLOW, g_srv_bt_dialer_p->sco_allow, conn_id);
    if (g_srv_bt_dialer_p->sco_allow == conn_id || g_srv_bt_dialer_p->sco_allow == MMI_HF_INVALID_CONN_ID)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_hilite_dev
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_set_hilite_dev(U8 conn_id, U8 setup, U8 call, U8 held)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_NOTIFY, setup, call, held);

    if (!srv_bt_dialer_is_any_call() && (setup != 0 || call != 0 || held != 0))
    {
        g_srv_bt_dialer_p->sco_allow = conn_id;
    }
    else if (setup == 0 && call == 0 && held == 0 && g_srv_bt_dialer_p->sco_allow == conn_id)
    {
        g_srv_bt_dialer_p->sco_allow = MMI_HF_INVALID_CONN_ID;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_incoming_call_ans_status
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_get_incoming_call_ans_status(U8 conn_id)
{
#ifndef __BT_DIALER_HF_SCO_ALWAYS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_p;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_p)
    {
        ret = dev_p->sco_auto;
    }
    else
    {
        ret = MMI_FALSE;
    }
    return ret;
#else
    return MMI_TRUE;
#endif /* __BT_DIALER_HF_SCO_ALWAYS__ */
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_set_incoming_call_ans_status
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_dialer_set_incoming_call_ans_status(U8 conn_id, MMI_BOOL flag)
{
#ifndef __BT_DIALER_HF_SCO_ALWAYS__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_p)
    {
        dev_p->sco_auto = flag;
    }
#endif /* __BT_DIALER_HF_SCO_ALWAYS__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_ciev_call
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_dialer_get_ciev_call(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_p;
    U8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_p)
    {
        ret = dev_p->ciev_call;
    }
    else
    {
        ret = 0xFF;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_ciev_setup
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_bt_dialer_get_ciev_setup(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_p;
    U8 ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_p)
    {
        ret = dev_p->callsetup;
    }
    else
    {
        ret = 0xFF;
    }
    return ret;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_is_any_call
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_is_any_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dev_info_p = &g_srv_bt_dialer_p->dev_info[0]; dev_info_p < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info_p++)
    {
        SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_IS_ANY_CALL, dev_info_p->callsetup, dev_info_p->ciev_call, dev_info_p->callheld);
        if (dev_info_p->callsetup != 0 || dev_info_p->ciev_call != 0 || dev_info_p->callheld != 0)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_is_any_call_ex
 * DESCRIPTION
 * PARAMETERS
 *
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_dialer_is_any_call_ex(srv_bt_cm_bt_addr* bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bt_addr);
    for (dev_info_p = &g_srv_bt_dialer_p->dev_info[0]; dev_info_p < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info_p++)
    {
        if (dev_info_p->alloc && memcmp(&dev_info_p->bd_addr, bt_addr, sizeof(srv_bt_cm_bt_addr)) == 0)
        {
            SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_IS_ANY_CALL, dev_info_p->callsetup, dev_info_p->ciev_call, dev_info_p->callheld);
            if (dev_info_p->callsetup != 0 || dev_info_p->ciev_call != 0 || dev_info_p->callheld != 0)
            {
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


MMI_BOOL srv_bt_dialer_is_in_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = g_srv_bt_dialer_p->dev_info;
    for (i = 0; i < BT_MAX_HF_DEV; i++)
    {
        SRV_BT_DIALER_LOG2(SRV_BT_DIALER_HF_IS_IN_CALL, dev_info_p->ciev_call, dev_info_p->callheld);
        if (dev_info_p->ciev_call != 0 || dev_info_p->callheld != 0)
        {
            return MMI_TRUE;
        }
        dev_info_p++;
    }
    return MMI_FALSE;

}

MMI_BOOL srv_bt_dialer_is_atd_pending(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_bt_dialer_get_dev_info_by_hd(srv_hd);

    if (dev_info && dev_info->pending_action == SRV_BT_DIALER_AT_DIAL_NUMBER)
    {
        return MMI_TRUE;
    }

    return MMI_FALSE;
}


void srv_bt_dialer_switch_audio_path_bt(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_btsco_is_sco_open())
    {
        srv_btsco_dialer_close_stream_req();
    }
    else
    {
        srv_btsco_dialer_open_stream_req(srv_hd);
    }
}


U8 srv_bt_dialer_get_connection_id(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_bt_cm_is_profile_connected(SRV_BT_CM_HF_CONNECTION))
    {
        for (i = 0; i < BT_MAX_HF_DEV; i++)
        {
            if (srv_hd == g_srv_bt_dialer_p->dev_info[i].srv_hd)
            {
                return g_srv_bt_dialer_p->dev_info[i].conn_id;
            }
        }
    }
    return 0xFF;
}

// just for BQB TP/ICA/BV-05-I
U8 srv_bt_dialer_get_bqb_bsir_enable(void)
{
    srv_bt_dialer_dev_info_struct* dev_info;

    for (dev_info = &g_srv_bt_dialer_p->dev_info[0]; dev_info < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info++)
    {
        if (dev_info->alloc)
        {
            return dev_info->bsir_bqb_state;
        }
    }
    return 0;
}

// just for BQB TP/ICA/BV-05-I
void srv_bt_dialer_reset_bqb_bsir_enable(void)
{
    srv_bt_dialer_dev_info_struct* dev_info;

    for (dev_info = &g_srv_bt_dialer_p->dev_info[0]; dev_info < &g_srv_bt_dialer_p->dev_info[BT_MAX_HF_DEV]; dev_info++)
    {
        if (dev_info->alloc && dev_info->bsir_bqb_state != 0)
        {
            dev_info->bsir_bqb_state = 0;
        }
    }
}


MMI_BOOL srv_bt_dialer_is_serv_ready(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_srv_bt_dialer_p->serv_state == SRV_BTD_STATE_ACTIVATED)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_dev_info_by_conn_id
 * DESCRIPTION
 * 
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_conn_id(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (idx = 0; idx < BT_MAX_HF_DEV; idx++)
    {
        if (g_srv_bt_dialer_p->dev_info[idx].conn_id == conn_id)
        {
            return &g_srv_bt_dialer_p->dev_info[idx];
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_dev_info_by_hd
 * DESCRIPTION
 *  
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_hd(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_GET_DEV_BY_HD, srv_hd);
    for (idx = 0; idx < BT_MAX_HF_DEV; idx++)
    {
        SRV_BT_DIALER_LOG2(SRV_BT_DIALER_HF_GET_DEV_INFO, g_srv_bt_dialer_p->dev_info[idx].srv_hd,g_srv_bt_dialer_p->dev_info[idx].conn_id);
        if (g_srv_bt_dialer_p->dev_info[idx].srv_hd == srv_hd)
        {
            return &g_srv_bt_dialer_p->dev_info[idx];
        }
    }
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_dialer_get_dev_info_by_addr
 * DESCRIPTION
 *  This function is to get free device index.
 * CALLS
 * PARAMETERS
 * RETURNS
 *  int
 *****************************************************************************/
srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_addr(srv_bt_cm_bt_addr* bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bd_addr);
    for (idx = 0; idx < BT_MAX_HF_DEV; idx++)
    {
        if (g_srv_bt_dialer_p->dev_info[idx].bd_addr.lap == bd_addr->lap
         && g_srv_bt_dialer_p->dev_info[idx].bd_addr.uap == bd_addr->uap
         && g_srv_bt_dialer_p->dev_info[idx].bd_addr.nap == bd_addr->nap)
        {
            return &g_srv_bt_dialer_p->dev_info[idx];
        }
    }
    return NULL;
}

void srv_bt_dialer_reset_protocol_event_handler(U16 event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearProtocolEventHandler(event);
}

void srv_bt_dialer_addr_transfer(void* out_addr, void* in_addr, MMI_BOOL bt_2_mmi)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_dm_addr_struct* bt_addr;
    srv_bt_cm_bt_addr* mmi_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(out_addr && in_addr);

    if (bt_2_mmi)
    {
        bt_addr = (bt_dm_addr_struct*)in_addr;
        mmi_addr = (srv_bt_cm_bt_addr*)out_addr;
        mmi_addr->lap = bt_addr->lap;
        mmi_addr->nap = bt_addr->nap;
        mmi_addr->uap = bt_addr->uap;
    }
    else
    {
        mmi_addr = (srv_bt_cm_bt_addr*)in_addr;
        bt_addr = (bt_dm_addr_struct*)out_addr;
        bt_addr->lap = mmi_addr->lap;
        bt_addr->nap = mmi_addr->nap;
        bt_addr->uap = mmi_addr->uap;
    }
}

mmi_ret srv_bt_dialer_sco_connection_event_hdlr(void *param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_evt_srv_btsco_close_ind_struct* sco_evt;
    srv_bt_dialer_notify_event_struct notify;
    srv_bt_dialer_dev_info_struct* dev_info_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(param);

    sco_evt = (mmi_evt_srv_btsco_close_ind_struct*)param;

    SRV_BT_DIALER_LOG3(SRV_BT_DIALER_HF_SCO_CONN , sco_evt->conn_id, sco_evt->error_cause, sco_evt->is_open);

    if (sco_evt->error_cause == MDI_AUDIO_SUCCESS)
    {
        notify.event_id = SRV_BT_DILAER_EVT_ID_SCO_CONN_IND;
        notify.result.sco_conn_ind.is_open = sco_evt->is_open;
        if (sco_evt->is_open && g_srv_bt_dialer_p->sco_allow == MMI_HF_INVALID_CONN_ID)
        {
            g_srv_bt_dialer_p->sco_allow = sco_evt->conn_id;
        }

        dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(sco_evt->conn_id);

        if (!sco_evt->is_open && dev_info_p && dev_info_p->callheld == 0
          && dev_info_p->callsetup == 0 && dev_info_p->ciev_call == 0)
        {
            g_srv_bt_dialer_p->sco_allow = MMI_HF_INVALID_CONN_ID;
        }
        srv_bt_dialer_ind_notify_cb(sco_evt->conn_id, &notify);
    }
    return MMI_RET_OK;
}


#ifdef __BT_DIALER_HF_NO_IN_BAND_TONE__
MMI_BOOL srv_bt_dialer_is_inband_ringtone(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_info_p)
    {
        if (dev_info_p->alloc && dev_info_p->callsetup == SRV_BT_DIALER_CALL_INCOMING_CALL
        && dev_info_p->ciev_call == SRV_BT_DIALER_CALL_NOT_ACTIVE && dev_info_p->callheld == SRV_BT_DIALER_NO_CALL_HELD)
        {
           ret = MMI_TRUE;
        }
        else
        {
           ret = MMI_FALSE;
        }
    }
    else
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NOT_FIND_DEV, conn_id);
        ret = MMI_FALSE;
    }
    return ret;
}

void srv_bt_dialer_set_mute_inband_flag(U8 conn_id, MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_info_p && dev_info_p->alloc)
    {
        dev_info_p->inband_muted = flag;
    }
    else
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NOT_FIND_DEV, conn_id);
    }
}

MMI_BOOL srv_bt_dialer_get_mute_inband_flag(U8 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_dev_info_struct* dev_info_p;
    MMI_BOOL ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info_p = srv_bt_dialer_get_dev_info_by_conn_id(conn_id);

    if (dev_info_p)
    {
        if (dev_info_p->alloc && dev_info_p->inband_muted)
        {
           ret = MMI_TRUE;
        }
        else
        {
           ret = MMI_FALSE;
        }
    }
    else
    {
        SRV_BT_DIALER_LOG1(SRV_BT_DIALER_HF_NOT_FIND_DEV, conn_id);
        ret = MMI_FALSE;
    }
    return ret;
}
#endif /* __BT_DIALER_HF_NO_IN_BAND_TONE__ */
#endif /*__MMI_HF_SUPPORT__*/


