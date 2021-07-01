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
 *  VoIPMsgHdlr.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Coding Template header file
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
#include "MMI_include.h"

#ifdef __MMI_VOIP__

#include "ProtocolEvents.h"
#include "CommonScreens.h"
#include "SettingProfile.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_data_account.h"

#include "Conversions.h"
#include "gpioInc.h"
#include "ServiceDefs.h"
#include "UCMGProt.h"
#include "..\..\..\Service\UcmSrv\UcmSrvIntProt.h"

#include "VoIPResDef.h"
#include "VoIPGProt.h"
#include "VoIPProt.h"

#include "ProfilesSrvGprot.h"
#include "UcmSrvGprot.h"

extern U32 voip_custom_get_local_port(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_send_message
 * DESCRIPTION
 *  General function to send message to other task.
 * PARAMETERS
 *  moduleSrc           [IN]        
 *  moduleDest          [IN]        
 *  msgId               [IN]        Message id
 *  localPara           [IN]        Local parameter
 *  peerBuff            [IN]        Peer buffer
 *  module_type         [IN]        Destination module
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_send_message(module_type moduleSrc, module_type moduleDest, U16 msgId, void *localPara, void *peerBuff)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //Message.oslSrcId = moduleSrc;
    //Message.oslDestId = moduleDest;
    //Message.oslMsgId = msgId;
    //Message.oslDataPtr = localPara;
    //Message.oslPeerBuffPtr = peerBuff;

    //OslMsgSendExtQueue(&Message);
     mmi_frm_send_ilm(moduleDest, (oslMsgType) msgId, 
                        (oslParaType*)localPara, (oslPeerBuffType*) peerBuff);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_register_req
 * DESCRIPTION
 *  Send register request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_register_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 actprofIndex = g_voip_cntx_p->prof_setting_info.actprofIndex;
    S32 refreshTime = 0;
    mmi_voip_register_req_struct *msgReq;
    U32 data_acnt = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq = (mmi_voip_register_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_register_req_struct));
    g_voip_cntx_p->reg_state_info = MMI_VOIP_PROCESS_STATE;

    StopTimer(VOIP_AUTOLOGIN_TIMER);
    
    msgReq->profile.local_port = (U16)voip_custom_get_local_port(); /* for auto provisioning */
    data_acnt = cbm_set_app_id(g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].comm_info.dataAcct, g_voip_cntx_p->app_id);
    msgReq->profile.data_account = data_acnt;
    memcpy(
        msgReq->profile.voice_mail,
        g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].comm_info.vmServer,
        VOIP_URI_LEN);
    memcpy(
        msgReq->profile.sip_server,
        g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.sipServer,
        VOIP_URI_LEN);
    msgReq->profile.sip_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.sipPort;
    mmi_chset_convert(
        MMI_CHSET_UCS2,
        MMI_CHSET_UTF8,
        (char*)g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.dispName,
        (char*)msgReq->profile.disp_name,
        (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
    memcpy(
        msgReq->profile.sip_username,
        g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.username,
        VOIP_USERNAME_LEN);
    memcpy(
        msgReq->profile.sip_password,
        g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.password,
        VOIP_PASSWORD_LEN);
    memcpy(
        msgReq->profile.auth_username,
        g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].acct_info.authName,
        VOIP_USERNAME_LEN);
    msgReq->profile.outbound_type = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].out_server_info.status;
    if ((msgReq->profile.outbound_type == VOIP_OUTBOUND_AUTO) ||
        (msgReq->profile.outbound_type == VOIP_OUTBOUND_ALWAYS))
    {
        memcpy(
            msgReq->profile.outbound_server,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].out_server_info.server,
            VOIP_URI_LEN);
        msgReq->profile.outbound_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].out_server_info.port;
        memcpy(
            msgReq->profile.outbound_username,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].out_server_info.username,
            VOIP_USERNAME_LEN);
        memcpy(
            msgReq->profile.outbound_password,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].out_server_info.password,
            VOIP_PASSWORD_LEN);
    }
    msgReq->profile.enable_registrar =
        (g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].reg_server_info.status == 1) ? (TRUE) : (FALSE);
    if (msgReq->profile.enable_registrar == TRUE)
    {
        memcpy(
            msgReq->profile.registrar_server,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].reg_server_info.server,
            VOIP_URI_LEN);
        msgReq->profile.registrar_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].reg_server_info.port;
        memcpy(
            msgReq->profile.registrar_username,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].reg_server_info.username,
            VOIP_USERNAME_LEN);
        memcpy(
            msgReq->profile.registrar_password,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].reg_server_info.password,
            VOIP_PASSWORD_LEN);
    }
    msgReq->profile.nat_type = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.natStatus;
    if (msgReq->profile.nat_type == VOIP_NAT_TYPE_STATIC_IP)    /* Static NAT */
    {
        msgReq->profile.fire_wall[0] =
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.natFirewall[0];
        msgReq->profile.fire_wall[1] =
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.natFirewall[1];
        msgReq->profile.fire_wall[2] =
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.natFirewall[2];
        msgReq->profile.fire_wall[3] =
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.natFirewall[3];
    }
    else if (msgReq->profile.nat_type == VOIP_NAT_TYPE_STUN)    /* STUN Server */
    {
        memcpy(
            msgReq->profile.stun_server,
            g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.stunServer,
            VOIP_URI_LEN);
        msgReq->profile.stun_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.stunPort;
        msgReq->profile.nat_refresh =
            (g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.refInterval == 0) ? (TRUE) : (FALSE);
        if (msgReq->profile.nat_refresh == FALSE)
        {
            refreshTime = (U8)g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].nat_info.refInterval;
            switch (refreshTime)
            {
                case 1:
                    msgReq->profile.nat_refresh_time = 9;
                    break;
                case 2:
                    msgReq->profile.nat_refresh_time = 15;
                    break;
                case 3:
                    msgReq->profile.nat_refresh_time = 30;
                    break;
                case 4:
                    msgReq->profile.nat_refresh_time = 60;
                    break;
                default:
                    break;
            }
        }
    }
    msgReq->profile.rtp_start_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].rtp_info.start_port;
    msgReq->profile.rtp_end_port = g_voip_cntx_p->prof_setting_info.saved_prof[actprofIndex].rtp_info.end_port;

    msgReq->setting.auto_answer = (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 2) ? (TRUE) : (FALSE);
    msgReq->setting.auto_decline = (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 1) ? (TRUE) : (FALSE);
    msgReq->setting.do_not_disturb =
        (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 2) ? (TRUE) : (FALSE);
    msgReq->setting.hide_user_id =
        (g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId == 1) ? (TRUE) : (FALSE);
    msgReq->setting.dtmf = g_voip_cntx_p->call_setting_info.saved_setting.dtmf;
    msgReq->setting.comfortable_noise =
        (g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise == 0) ? (TRUE) : (FALSE);
    msgReq->setting.srtp = (g_voip_cntx_p->call_setting_info.saved_setting.srtp == 1) ? (TRUE) : (FALSE);
    memcpy(
        msgReq->setting.codec_order,
        g_voip_cntx_p->call_setting_info.codecEnum,
        (VOIP_MAX_NUM_CODEC * sizeof(voip_codec_enum)));

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_REGISTER_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_register_rsp
 * DESCRIPTION
 *  Receive register response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_register_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_register_rsp_struct *msgRsp = (mmi_voip_register_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->proc_scr_info.cause == MMI_VOIP_PROC_CAUSE_ABORT_LOGIN)
    {
        return;
    }
    if (msgRsp->result == VOIP_OK)
    {
        g_voip_cntx_p->reg_state_info = MMI_VOIP_REG_STATE;
        ShowStatusIcon(STATUS_ICON_VOIP);
        UpdateStatusIcons();
        
        StopTimer(VOIP_AUTOLOGIN_TIMER);
        
        if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR))
        {
            mmi_display_popup(
                get_string(STR_ID_VOIP_LOGIN_OK),
                MMI_EVENT_SUCCESS);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
        }
        else if (IsScreenPresent(SCR_ID_VOIP_MAIN))
        {
            mmi_display_popup(
                get_string(STR_ID_VOIP_LOGIN_OK),
                MMI_EVENT_SUCCESS);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else if (IsScreenPresent(SERVICES_MAIN_MENU_SCREEN_ID) && (IsScreenPresent(SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_PROCESSING))) /* intend to go to voip main menu but state is not allowed */
        {
            mmi_voip_entry_main_menu();
            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else if (GetExitScrnID() == SCR_ID_VOIP_PROCESSING) /* dial voip call from other application */
        {
            mmi_display_popup(
                get_string(STR_ID_VOIP_LOGIN_OK),
                MMI_EVENT_SUCCESS);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else /* rsp for auto login */
        {
            /* do nothing */
        }
    }
    else
    {
        g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;
        HideStatusIcon(STATUS_ICON_VOIP);
        UpdateStatusIcons();
        
        if (IsScreenPresent(SCR_ID_VOIP_CALL_EDITOR))
        {
            mmi_display_popup(
                get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
            DeleteScreenIfPresent(SCR_ID_VOIP_CALL_EDITOR_OPTION); /* go back to call editor screen */
        }
        else if (IsScreenPresent(SCR_ID_VOIP_MAIN))
        {
            mmi_display_popup(
                get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else if (IsScreenPresent(SERVICES_MAIN_MENU_SCREEN_ID) && (IsScreenPresent(SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_PROCESSING))) /* intend to go to voip main menu but state is not allowed */
        {
            mmi_voip_entry_main_menu();
            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else if (GetExitScrnID() == SCR_ID_VOIP_PROCESSING) /* dial voip call from other application */
        {
            mmi_display_popup(
                get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else /* rsp for auto login */
        {
            /* do nothing */
        }

        if (msgRsp->cause == VOIP_NETWORK_ERROR)
        {
        #ifdef __MMI_WLAN_FEATURES__
            mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED, mmi_voip_main_evt_hdlr, NULL);
        #endif
        }
        else
        {
            /* always start a 20s timer, but not always apply auto login when timer expiry */
            StartTimer(VOIP_AUTOLOGIN_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 10), mmi_voip_entry_auto_login);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_deregister_req
 * DESCRIPTION
 *  Send de-register request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_deregister_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->reg_state_info = MMI_VOIP_PROCESS_STATE;
    
    StopTimer(VOIP_AUTOLOGIN_TIMER);

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_DEREGISTER_REQ, NULL, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_deregister_rsp
 * DESCRIPTION
 *  Receive de-register response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_deregister_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_deregister_rsp_struct *msgRsp = (mmi_voip_deregister_rsp_struct*)inMsg;
    U16 title_str_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == VOIP_OK)
    {
        if(g_voip_cntx_p->proc_scr_info.cause == MMI_VOIP_PROC_CAUSE_ABORT_LOGIN)
        {
            title_str_id = STR_ID_VOIP_LOGIN_ABORTED;
        }
        else
        {
            title_str_id = STR_ID_VOIP_LOGOUT_OK;
        }
        g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;
        HideStatusIcon(STATUS_ICON_VOIP);
        UpdateStatusIcons();
        mmi_display_popup(
            get_string(title_str_id),
            MMI_EVENT_SUCCESS);

        DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
    }
    else
    {
        g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;
        HideStatusIcon(STATUS_ICON_VOIP);
        UpdateStatusIcons();
        if (IsScreenPresent(SCR_ID_VOIP_MAIN))
        {
            mmi_display_popup(
                get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else if (IsScreenPresent(SERVICES_MAIN_MENU_SCREEN_ID) && (IsScreenPresent(SCR_ID_VOIP_PROCESSING) || (GetExitScrnID() == SCR_ID_VOIP_PROCESSING))) /* intend to go to voip main menu but state is not allowed */
        {
            mmi_voip_entry_main_menu();
            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
        else /* dial voip call from other application */
        {
            mmi_display_popup(
                get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
                MMI_EVENT_FAILURE);

            DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        }
    }
    g_voip_cntx_p->proc_scr_info.cause = MMI_VOIP_PROC_CAUSE_NONE;

#ifdef __MMI_WLAN_FEATURES__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED, mmi_voip_main_evt_hdlr, NULL);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_deregister_ind
 * DESCRIPTION
 *  Receive de-register indication from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_deregister_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_deregister_ind_struct *msgInd = (mmi_voip_deregister_ind_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->result != VOIP_OK)
    {
        g_voip_cntx_p->reg_state_info = MMI_VOIP_DEREG_STATE;
        HideStatusIcon(STATUS_ICON_VOIP);
        UpdateStatusIcons();
        mmi_display_popup(
            get_string(STR_ID_VOIP_LOGOUT_IND),
            MMI_EVENT_SUCCESS);

        DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
        /* in case receiving deregister_ind during redialing process */
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            mmi_voip_entry_abort_redial();
        }
    }
    else
    {
        MMI_ASSERT(msgInd->result != VOIP_OK);
    }

#ifdef __MMI_VOIP_PERIODICALLY_LOGIN__
    if ((msgInd->cause == VOIP_DHCP_ERROR) || (msgInd->cause == VOIP_REREGISTER_FAILED))
#else
    if (msgInd->cause == VOIP_DHCP_ERROR)
#endif
    {
    	/* always start a 20s timer, but not always apply auto login when timer expiry */
        StartTimer(VOIP_AUTOLOGIN_TIMER, (MMI_VOIP_GENERAL_TIMEOUT * 10), mmi_voip_entry_auto_login);
    }
    else
    {
    #ifdef __MMI_WLAN_FEATURES__
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONNECTED, mmi_voip_main_evt_hdlr, NULL);
    #endif
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setting_req
 * DESCRIPTION
 *  Send setting request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_setting_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_setting_req_struct *msgReq;
    msgReq = (mmi_voip_setting_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_setting_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->setting.auto_answer = (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 2) ? (TRUE) : (FALSE);
    msgReq->setting.auto_decline = (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 1) ? (TRUE) : (FALSE);
    msgReq->setting.do_not_disturb =
        (g_voip_cntx_p->call_setting_info.saved_setting.autoReject == 2) ? (TRUE) : (FALSE);
    msgReq->setting.hide_user_id =
        (g_voip_cntx_p->call_setting_info.saved_setting.hidecallerId == 1) ? (TRUE) : (FALSE);
    msgReq->setting.dtmf = g_voip_cntx_p->call_setting_info.saved_setting.dtmf;
    msgReq->setting.srtp = (g_voip_cntx_p->call_setting_info.saved_setting.srtp == 1) ? (TRUE) : (FALSE);
    msgReq->setting.comfortable_noise =
        (g_voip_cntx_p->call_setting_info.saved_setting.comfortNoise == 0) ? (TRUE) : (FALSE);
    memcpy(
        msgReq->setting.codec_order,
        g_voip_cntx_p->call_setting_info.codecEnum,
        (VOIP_MAX_NUM_CODEC * sizeof(voip_codec_enum)));

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_SETTING_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_setting_rsp
 * DESCRIPTION
 *  Receive setting response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_setting_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_setting_rsp_struct *msgRsp = (mmi_voip_setting_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == VOIP_OK)
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_SAVED),
            MMI_EVENT_SUCCESS);
    }
    else
    {
        mmi_display_popup(
            get_string(STR_GLOBAL_UNFINISHED),
            MMI_EVENT_FAILURE);
    }

    DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_SET_CODEC_ORDER_OPTION);  /* for set codec order screen */
    DeleteScreenIfPresent(SCR_ID_VOIP_SETTING_GENERAL); /* for all screens except set codec order screen */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_progressing_ind
 * DESCRIPTION
 *  Receive progressing indication from VoIP CC when
 *  MO call request is sent but not yet received response.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_progressing_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_progressing_ind_struct *msgInd = (mmi_voip_progressing_ind_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgInd->status == VOIP_CALL_PROG_TRYING)
    {
        g_voip_cntx_p->call_list_info.processCId = msgInd->call_id;
        g_voip_cntx_p->call_list_info.processDId = msgInd->dialog_id;
        mmi_voip_add_to_call_list(msgInd->call_list, msgInd->call_id, msgInd->dialog_id, MMI_VOIP_OUTGOING_STATE);
        mmi_voip_switch_session(MMI_VOIP_OUTGOING_STATE);
        mmi_voip_ucm_sync_call_list();

        mmi_voip_ucm_dial_act_rsp(SRV_UCM_INT_DIAL_ACT, msgInd->call_id, msgInd->dialog_id, TRUE, NULL);
    }
    else if (msgInd->status == VOIP_CALL_PROG_FORWARDED)
    {
        mmi_voip_ucm_notify_ind((U8*)GetString(STR_ID_VOIP_CALL_FORWARDED), IMG_GLOBAL_ACTIVATED, SUCCESS_TONE_IN_CALL);
    }
    else /* msgInd->status == VOIP_CALL_PROG_RINGING */
    {
        mmi_voip_ucm_alert_ind(g_voip_cntx_p->call_list_info.processCId, g_voip_cntx_p->call_list_info.processDId, TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_ring_ind
 * DESCRIPTION
 *  Receive ring indication from VoIP CC when MT call is coming.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_ring_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_ring_ind_struct *msgInd = (mmi_voip_call_ring_ind_struct*)inMsg;
    S32 num_of_incoming_call = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_voip_cntx_p->call_list_info.numTotal < MMI_VOIP_MAX_NUM_CALL)
    {
        num_of_incoming_call = srv_ucm_query_call_count(SRV_UCM_INCOMING_STATE, SRV_UCM_CALL_TYPE_ALL, NULL);
        if ((g_voip_cntx_p->call_list_info.processCId == -1) && (num_of_incoming_call <= 0))
        {
            mmi_voip_add_to_call_list(msgInd->call_list, msgInd->call_id, msgInd->dialog_id, MMI_VOIP_INCOMING_STATE);
            mmi_voip_switch_session(MMI_VOIP_INCOMING_STATE);
            mmi_voip_ucm_ring_ind(msgInd->call_id, msgInd->dialog_id);
            /* auto answer is only applicable to the first incoming call, both for voip and gsm */
            /* abort auto redial when there is an incoming call */
            if (mmi_voip_is_auto_redial() == MMI_TRUE)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_ABORT_REDIAL, num_of_incoming_call, g_voip_cntx_p->reg_state_info);
                mmi_voip_entry_abort_redial();
            }
        }
        else /* pending action exists */
        {
            /* background reject without user's awareness */
            mmi_voip_background_reject_req(msgInd->call_id, msgInd->dialog_id);
        }
    }
    else /* call boundry exceeds */
    {
        /* background reject without user's awareness */
        mmi_voip_background_reject_req(msgInd->call_id, msgInd->dialog_id);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_end_ind
 * DESCRIPTION
 *  Receive end indication from VoIP CC when call is disconnected.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_end_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0;
    mmi_voip_call_end_ind_struct *msgInd = (mmi_voip_call_end_ind_struct*)inMsg;
    S16 dialog_idx = mmi_voip_get_dialog_idx(msgInd->call_id, msgInd->dialog_id);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_VOIP_TRC_GRP, TRC_MMI_VOIP_CALL_END_IND, msgInd->call_id, msgInd->dialog_id, dialog_idx);

    if (g_voip_cntx_p->call_setting_info.saved_setting.autoAnswer == 2)
    {
        StopTimer(VOIP_AUTOANSWER_TIMER);
    }
    
    if (msgInd->result == VOIP_OK)
    {
        /* in case remote release call when local is asked to transfer it, 
         * mmi will not handle transfer failed state_ind after end_ind */
        callIndex = mmi_voip_get_call_index(msgInd->call_id);
        if ((callIndex != -1) && 
            (g_voip_cntx_p->call_list_info.call_info[callIndex].currState == MMI_VOIP_TRANSFER_STATE) && 
            (msgInd->call_id == g_voip_cntx_p->call_list_info.processCId) && 
            (msgInd->dialog_id == g_voip_cntx_p->call_list_info.processDId))
        {
            //g_voip_cntx_p->call_list_info.processCId = -1;
            //g_voip_cntx_p->call_list_info.processDId = -1;
            //mmi_voip_ucm_stop_processing_ind((U8*)GetString(STR_ID_VOIP_TRANSFER_FAIL), IMG_GLOBAL_UNFINISHED, ERROR_TONE_IN_CALL);
        }
        mmi_voip_update_call_list(msgInd->call_list, FALSE); /* delete call id from call list */
        mmi_voip_ucm_release_ind(msgInd->call_id, dialog_idx, (U8*)GetString(STR_ID_VOIP_CALL_END), IMG_ID_VOIP_CALL_ENDED, SUCCESS_TONE_IN_CALL);
        mmi_voip_del_call_from_force_rel_list(msgInd->call_id, dialog_idx, MMI_TRUE);
    }
    else
    {
        MMI_ASSERT(msgInd->result == VOIP_OK); /* call end cannot fail */
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_state_ind
 * DESCRIPTION
 *  Receive state indication from VoIP CC when remote state is changed.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_state_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0;
    mmi_voip_call_state_ind_struct *msgInd = (mmi_voip_call_state_ind_struct*)inMsg;
    S32 original_dlg_idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* update call info only for specific call in case call list file open fail 
     * due to remote hold / unhold rapidly */   
    callIndex = mmi_voip_get_call_index(msgInd->call_id);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, msgInd->dialog_id);
        if (dialogIndex != -1)
        {
            original_dlg_idx = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogIdx;
            g_voip_cntx_p->call_list_info.call_info[callIndex].currState = mmi_voip_get_call_state_enum(msgInd->call.dialog[msgInd->dialog_id].dialog_state);
            memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 0, (VOIP_DISP_NAME_LEN * sizeof(U16)));
            mmi_chset_convert(
                MMI_CHSET_UTF8, 
                MMI_CHSET_UCS2, 
                (char*)msgInd->call.dialog[msgInd->dialog_id].user_addr.disp_name, 
                (char*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
                (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
            /* uri changes, need to update appName */
            if (strncmp((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, (S8*)msgInd->call.dialog[msgInd->dialog_id].user_addr.uri, VOIP_URI_LEN))
            {
                memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 0, (VOIP_DISP_NAME_LEN * sizeof(U16)));
            }
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogIdx = msgInd->call.dialog[msgInd->dialog_id].dialog_idx;
            memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, 0, VOIP_URI_LEN);
            memcpy(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, msgInd->call.dialog[msgInd->dialog_id].user_addr.uri, VOIP_URI_LEN);
            mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri);
            if((msgInd->change_cause == VOIP_STATE_IND_TRANSFERED) || ((g_voip_cntx_p->call_list_info.processCId == -1) && (g_voip_cntx_p->call_list_info.processDId == -1)))
            {
                if (mmi_voip_is_addr_change(&g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].sdp_info, &msgInd->call.dialog[msgInd->dialog_id].sdp_info))
                {
                    if(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle != -1)
                    {
                        g_voip_cntx_p->rtp_proc_info.remove_mixer_list[g_voip_cntx_p->rtp_proc_info.remove_mixer_num++] = callIndex;
                        g_voip_cntx_p->rtp_proc_info.close_rtp_list[g_voip_cntx_p->rtp_proc_info.close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                    }
                    g_voip_cntx_p->rtp_proc_info.rtp_process[callIndex][dialogIndex] |= MMI_VOIP_RTP_PROC_CREATE;
                }
                memcpy(&g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].sdp_info, &msgInd->call.dialog[msgInd->dialog_id].sdp_info, sizeof(voip_sdp_struct));
                g_voip_cntx_p->rtp_proc_info.rtp_process[callIndex][dialogIndex] |= MMI_VOIP_RTP_PROC_UPDATE;
	            mmi_voip_update_rtp();
            }
            if (msgInd->change_cause == VOIP_STATE_IND_TRANSFERING)
            {
                if ((g_voip_cntx_p->call_list_info.processCId == -1) && 
                    (g_voip_cntx_p->call_list_info.processDId == -1) && 
                    (srv_ucm_is_busy() == MMI_FALSE))
                {
                    /* in case of release call, release current transfering call */
                    g_voip_cntx_p->call_list_info.processCId = msgInd->call_id;
                    g_voip_cntx_p->call_list_info.processDId = msgInd->dialog_id;
                    /* voip cc dialog state is active for transferring,
                       so mmi needs to set it as TRANSFER_STATE itself */
                    g_voip_cntx_p->call_list_info.call_info[callIndex].currState = MMI_VOIP_TRANSFER_STATE;
                    mmi_voip_ucm_start_processing_ind(msgInd->call_id, msgInd->dialog_id, (U8*)GetString(STR_ID_VOIP_TRANSFER));
                    mmi_voip_transferee_cnf(TRUE);
                }
                else /* pending action exists */
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_TRANSFEREE_NOT_ALLOW, g_voip_cntx_p->call_list_info.processCId, g_voip_cntx_p->call_list_info.processDId);
                    mmi_voip_transferee_cnf(FALSE);
                }
            }
            else if (msgInd->change_cause == VOIP_STATE_IND_TRANSFERED)
            {
                /* ensure not to reset other pending action's call id and dialog id */
                if ((msgInd->call_id == g_voip_cntx_p->call_list_info.processCId) && 
                    (msgInd->dialog_id == g_voip_cntx_p->call_list_info.processDId))
                {
                    g_voip_cntx_p->call_list_info.processCId = -1;
                    g_voip_cntx_p->call_list_info.processDId = -1;
                }
                mmi_voip_ucm_replace_ind(callIndex,
                                            dialogIndex,
                                            g_voip_cntx_p->call_list_info.call_info[callIndex].callId,
                                            g_voip_cntx_p->call_list_info.call_info[callIndex].callId,
                                            original_dlg_idx,
                                            msgInd->call.dialog[msgInd->dialog_id].dialog_idx);
                mmi_voip_ucm_stop_processing_ind((U8*)GetString(STR_ID_VOIP_TRANSFER_OK), IMG_GLOBAL_ACTIVATED, SUCCESS_TONE_IN_CALL);
            }
            else if (msgInd->change_cause == VOIP_STATE_IND_TRANSFER_FAILED)
            {
                /* ensure not to reset other pending action's call id and dialog id */
                if ((msgInd->call_id == g_voip_cntx_p->call_list_info.processCId) && 
                    (msgInd->dialog_id == g_voip_cntx_p->call_list_info.processDId))
                {
                    g_voip_cntx_p->call_list_info.processCId = -1;
                    g_voip_cntx_p->call_list_info.processDId = -1;
                }
                mmi_voip_ucm_stop_processing_ind((U8*)GetString(STR_ID_VOIP_TRANSFER_FAIL), IMG_GLOBAL_UNFINISHED, ERROR_TONE_IN_CALL);
            }
            else    /* msgInd->change_cause == VOIP_STATE_IND_SDP_CHANGE */
            {
                /* do nothing */
            }
        }
        else
        {
            /* do not assert in case answering gsm when transferring,
               state_ind will still be received even all voip calls are released */
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_DIALOG_NOT_EXIST);
        }
    }
    else
    {
        /* do not assert in case answering gsm when transferring,
           state_ind will still be received even all voip calls are released */
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_CALL_NOT_EXIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_replace_ind
 * DESCRIPTION
 *  Receive replace indication from VoIP CC to replace a specific call information.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_replace_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_replace_ind_struct *msgInd = (mmi_voip_call_replace_ind_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((g_voip_cntx_p->call_list_info.processCId == -1) && 
        (g_voip_cntx_p->call_list_info.processDId == -1) &&
        (mmi_voip_get_active_call_id() == msgInd->call_id))
    {    
        /* in case of release call, release current replacing call */
        /* could only replace a call which is in active state */
        g_voip_cntx_p->call_list_info.processCId = msgInd->replace_call_id;
        g_voip_cntx_p->call_list_info.processDId = msgInd->replace_dialog_id;
        mmi_voip_ucm_start_processing_ind(msgInd->replace_call_id, msgInd->replace_dialog_id, (U8*)GetString(STR_ID_VOIP_REPLACE));
        mmi_voip_call_replace_cnf(TRUE, msgInd);
    }
    else /* pending action exists */
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_REPLACE_NOT_ALLOW, g_voip_cntx_p->call_list_info.processCId, g_voip_cntx_p->call_list_info.processDId);
        mmi_voip_call_replace_cnf(FALSE, msgInd);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_replace_cnf
 * DESCRIPTION
 *  Send replace confirm to VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_replace_cnf(U8 result, void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_replace_ind_struct *msgInd = (mmi_voip_call_replace_ind_struct*)inMsg;
    mmi_voip_call_replace_cnf_struct *msgReq;
    msgReq = (mmi_voip_call_replace_cnf_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_replace_cnf_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->result = result;
    msgReq->call_id = msgInd->call_id;
    msgReq->dialog_id = msgInd->dialog_id;
    msgReq->replace_call_id = msgInd->replace_call_id;
    msgReq->replace_dialog_id = msgInd->replace_dialog_id;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_REPLACE_CNF, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_replace_complete_ind
 * DESCRIPTION
 *  Receive replace complete indication from VoIP CC when replace action is done.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_replace_complete_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callIndex = 0, dialogIndex = 0, original_dlg_idx = 0;
    mmi_voip_call_replace_complete_ind_struct *msgInd = (mmi_voip_call_replace_complete_ind_struct*)inMsg;
    //S16 dialog_idx = mmi_voip_get_dialog_idx(msgInd->replace_call_id, msgInd->replace_dialog_id);
    mmi_voip_rtp_proc_struct *rtp_proc = &(g_voip_cntx_p->rtp_proc_info);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callIndex = mmi_voip_get_call_index(msgInd->replace_call_id);
    if (callIndex != -1)
    {
        dialogIndex = mmi_voip_get_dialog_index(callIndex, msgInd->replace_dialog_id);
        if (dialogIndex != -1)
        {
            original_dlg_idx = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogIdx;
            g_voip_cntx_p->call_list_info.call_info[callIndex].currState = mmi_voip_get_call_state_enum(msgInd->call.dialog[0].dialog_state);
            memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 0, (VOIP_DISP_NAME_LEN * sizeof(U16)));
            mmi_chset_convert(
                MMI_CHSET_UTF8, 
                MMI_CHSET_UCS2, 
                (char*)msgInd->call.dialog[0].user_addr.disp_name, 
                (char*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dispName, 
                (S32)(VOIP_DISP_NAME_LEN * sizeof(U16)));
            /* uri changes, need to update appName */
            if (strncmp((S8*)g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, (S8*)msgInd->call.dialog[0].user_addr.uri, VOIP_URI_LEN))
            {
                memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].appName, 0, (VOIP_DISP_NAME_LEN * sizeof(U16)));
            }
            memset(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, 0, VOIP_URI_LEN);
            memcpy(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri, msgInd->call.dialog[0].user_addr.uri, VOIP_URI_LEN);
            mmi_voip_convert_uri_star_n_pound(g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].remoteUri);
            if (mmi_voip_is_addr_change(&g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].sdp_info, &msgInd->call.dialog[0].sdp_info))
            {
                rtp_proc->remove_mixer_list[rtp_proc->remove_mixer_num++] = callIndex;
                rtp_proc->close_rtp_list[rtp_proc->close_rtp_num++] = g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].rtpHandle;
                rtp_proc->rtp_process[callIndex][dialogIndex] |= MMI_VOIP_RTP_PROC_CREATE;
            }
            memcpy(&g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].sdp_info, &msgInd->call.dialog[0].sdp_info, sizeof(voip_sdp_struct));
            rtp_proc->rtp_process[callIndex][dialogIndex] |= MMI_VOIP_RTP_PROC_UPDATE;
            mmi_voip_update_rtp();

            /* arbitrarily change call id and dialog id with the new one */
            g_voip_cntx_p->call_list_info.call_info[callIndex].callId = msgInd->call.call_id;
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogId = msgInd->call.dialog[0].dialog_id;
            g_voip_cntx_p->call_list_info.call_info[callIndex].dialog_info[dialogIndex].dialogIdx = msgInd->call.dialog[0].dialog_idx;
            
            if ((msgInd->call.call_id == g_voip_cntx_p->call_list_info.processCId) && 
                (msgInd->call.dialog[0].dialog_id == g_voip_cntx_p->call_list_info.processDId))
            {
                g_voip_cntx_p->call_list_info.processCId = -1;
                g_voip_cntx_p->call_list_info.processDId = -1;
            }
            mmi_voip_ucm_replace_ind(callIndex,
                                                dialogIndex,
                                                msgInd->replace_call_id,
                                                msgInd->call.call_id,
                                                original_dlg_idx/*original_dlg_idx*/,
                                                msgInd->call.dialog[dialogIndex].dialog_idx);

//            mmi_voip_go_back_screen_check();
            mmi_voip_ucm_stop_processing_ind((U8*)GetString(STR_ID_VOIP_REPLACE_OK), IMG_GLOBAL_ACTIVATED, SUCCESS_TONE_IN_CALL);

        }
        else
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_DIALOG_NOT_EXIST);
        }
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_CALL_NOT_EXIST);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_msg_waiting_ind
 * DESCRIPTION
 *  Receive message waiting indication from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_msg_waiting_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    mmi_voip_waiting_msg_ind_struct *msgInd = (mmi_voip_waiting_msg_ind_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    TurnOnBacklight(1);
    for (i = (VOIP_MWI_TOTAL - 1); i >= 0; i--)
    {
        if (msgInd->mwi_info.msg_present[i] == TRUE)
        {
            g_voip_cntx_p->msg_waiting_info.isDisp = TRUE;
            g_voip_cntx_p->msg_waiting_info.mwiType = mmi_voip_get_mwi_state_enum(i);
            memcpy(&g_voip_cntx_p->msg_waiting_info.mwiMsg, &msgInd->mwi_info.msg[i], sizeof(voip_msg_struct));
            if (msgInd->mwi_info.is_account_present == TRUE)
            {
                memcpy(g_voip_cntx_p->msg_waiting_info.mwiAcct, msgInd->mwi_info.msg_account, VOIP_URI_LEN);
            }
            else
            {
                memset(g_voip_cntx_p->msg_waiting_info.mwiAcct, 0, VOIP_URI_LEN);
            }
            if (mmi_voip_is_idle_state())
            {
                mmi_voip_entry_msg_waiting_ind();
            }
            else
            {
                if (!(srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0))
                {
                    /* ! isInCall */
                    mmi_voip_entry_msg_waiting_popup();
                }
                else    /* do not interrupt GSM call or VoIP call, only play a beep */
                {
                    srv_prof_play_tone(SRV_PROF_TONE_SMS_INCALL, NULL);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_at_call_ctrl_approve_ind
 * DESCRIPTION
 *  Receive AT command call control approve indication from L4C.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from l4c
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_at_call_ctrl_approve_ind(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_at_call_ctrl_approve_ind_struct *msgInd = (mmi_voip_at_call_ctrl_approve_ind_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msgInd->action)
    {
        case RMMI_CM_ATD:
        case RMMI_CM_BLDN:
            if (g_voip_cntx_p->call_list_info.numTotal != 0)
            {
                mmi_voip_at_call_ctrl_approve_res_req(FALSE, msgInd->action);
            }
            else
            {
                mmi_voip_at_call_ctrl_approve_res_req(TRUE, msgInd->action);
            }            
            break;
        case RMMI_CM_ATH:
            /* release gsm call doesn't affect voip, so always return true */
            mmi_voip_at_call_ctrl_approve_res_req(TRUE, msgInd->action);
            break;
        case RMMI_CM_ATA:
            #if (0)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
            {
                mmi_voip_at_call_ctrl_approve_res_req(TRUE, msgInd->action);
            }            
            break;
        case RMMI_CM_CHLD:
            /* for gsm and voip co-existence, retrieve a gsm held call must notify voip first.
               in current design, since gsm and voip cannot co-exist, cannot hold gsm call when voip call exists 
               in case the screen changes and voip incoming screen disappears */
            if (g_voip_cntx_p->call_list_info.numTotal != 0)
            {
                mmi_voip_at_call_ctrl_approve_res_req(FALSE, msgInd->action);
            }
            else
            {
                mmi_voip_at_call_ctrl_approve_res_req(TRUE, msgInd->action);
            }
            break;
        default:
            MMI_ASSERT(0);
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_at_call_ctrl_approve_res_req
 * DESCRIPTION
 *  Send AT command call control approve confirm to L4C.
 * PARAMETERS
 *  result          [IN]        Approve to proceed the at command or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_at_call_ctrl_approve_res_req(U8 result, U8 action)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_at_call_ctrl_approve_res_req_struct *msgReq;
    msgReq = (mmi_voip_at_call_ctrl_approve_res_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_at_call_ctrl_approve_res_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->result = result;
    msgReq->action = action;
    msgReq->string_ptr = NULL;
    msgReq->node_ptr = NULL;
    msgReq->err_id = NULL;

    mmi_voip_send_message(MOD_MMI, MOD_L4C, MSG_ID_MMI_VOIP_AT_CALL_CTRL_APPROVE_RES_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_status_req
 * DESCRIPTION
 *  Send call status request to L4C.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from l4c
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_status_req(U8 status)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_eq_call_status_req_struct *msgReq;
    msgReq = (mmi_eq_call_status_req_struct*)OslConstructDataPtr(sizeof(mmi_eq_call_status_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->call_status = status;

    mmi_voip_send_message(MOD_MMI, MOD_L4C, MSG_ID_MMI_EQ_CALL_STATUS_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_call_status_rsp
 * DESCRIPTION
 *  Receive call status response from L4C.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from l4c
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_call_status_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* no need to handle its response because the action is always success */
}


#ifdef SIP_CONFORMANCE_TEST
/*****************************************************************************
 * FUNCTION
 *  mmi_voip_option_query_req
 * DESCRIPTION
 *  Send option query request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_option_query_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_option_req_struct *msgReq;
    msgReq = (mmi_voip_option_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_option_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy(msgReq->uri, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);

    SetProtocolEventHandler(mmi_voip_option_query_rsp, MSG_ID_MMI_VOIP_OPTION_RSP);
    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_OPTION_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_option_query_rsp
 * DESCRIPTION
 *  Receive option query response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_option_query_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_option_rsp_struct *msgRsp = (mmi_voip_option_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_entry_option_query_result((U8*)msgRsp->data);
    }
    else
    {
        mmi_display_popup(
            get_string(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)),
            MMI_EVENT_FAILURE);
    }
    DeleteScreenIfPresent(SCR_ID_VOIP_PROCESSING);
    DeleteScreenIfPresent(SCR_ID_VOIP_OPTION_QUERY_EDITOR);
}
#endif /* SIP_CONFORMANCE_TEST */


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dispatch_call_act_rsp
 * DESCRIPTION
 *  Receive action response from VoIP CC and
 *  dispatch to corresponding response handler.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dispatch_call_act_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (msgRsp->op_code)
    {
        case VOIP_CALL_ACT_DIAL_CALL:
        case VOIP_CALL_ACT_HOLD_AND_DIAL:
            mmi_voip_dial_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_ACCEPT_CALL:
        case VOIP_CALL_ACT_HOLD_AND_ACCEPT:
            mmi_voip_accept_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_HOLD_CALL:
            mmi_voip_hold_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_RETRIEVE_CALL:
            mmi_voip_retrieve_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_SWAP_CALL:
            mmi_voip_swap_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_MERGE_CALL:
            mmi_voip_merge_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_SPLIT_CALL:
            mmi_voip_split_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_REL_CALL:
        case VOIP_CALL_ACT_REL_ALL_CALLS:
        case VOIP_CALL_ACT_FORCE_REL_CALL:
            mmi_voip_release_rsp(inMsg);
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    #ifdef __MMI_VOIP_UNATTENDED_TRANSFER__
        case VOIP_CALL_ACT_UNATTENDED_TRANSFER:
    #else
        case VOIP_CALL_ACT_BLIND_TRANSFER:
    #endif
            mmi_voip_transfer_rsp(inMsg);
            break;
        case VOIP_CALL_ACT_REL_ALL_AND_DIAL_EMERGENCY:
            mmi_voip_dial_sos_rsp(inMsg);
            break;
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        default:
            MMI_ASSERT(0);  /* unrecognized call action */
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_req
 * DESCRIPTION
 *  Send dial request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dial_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = 0;
    g_voip_cntx_p->call_list_info.processDId = 0;

    msgReq->op_code = VOIP_CALL_ACT_DIAL_CALL;
    memcpy(msgReq->target_call, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_rsp
 * DESCRIPTION
 *  Receive dial response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dial_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0, dialogId = 0, outgoingId = mmi_voip_get_outgoing_call_id();
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = g_voip_cntx_p->call_list_info.processCId;
    dialogId = g_voip_cntx_p->call_list_info.processDId;
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if(callId == -1)
    {
        callId = outgoingId;
        dialogId = 0;
    }
    else if(callId != outgoingId)
    {
        //error!
    }
    if (msgRsp->result == VOIP_OK)
    {
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            mmi_voip_entry_abort_redial();
        }        
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_connect_ind(callId, dialogId);
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        /* send release_ind to ucm only if it does not actually dial to sip, otherwise, 
           it will send two release_ind (one is in call_end_ind, the other is here), which will cause ucm assert */
        if ((msgRsp->cause == VOIP_INVALID_PARAM) || (msgRsp->cause == VOIP_BUSY))
        {
            mmi_voip_ucm_dial_act_rsp(SRV_UCM_INT_DIAL_ACT, SRV_UCM_INVALID_ID, SRV_UCM_INVALID_ID, FALSE, (U8*)GetString(STR_ID_VOIP_INVALID_USERNAME));
        }
        /* call not exist error cause is because of race condition, do not apply auto redial */
        if ((mmi_voip_is_auto_redial() == MMI_TRUE) && 
            (msgRsp->cause != VOIP_CALL_NOT_EXIST) &&
            (msgRsp->cause != VOIP_INVALID_PARAM) &&
            (msgRsp->cause != VOIP_INVALID_URI) &&
            (msgRsp->cause != VOIP_CALL_ABORT_LOCALLY))
        {
            /* in case processing previous dial_rsp after abort_req is sent, 
               redial structure does not exist anymore */
            if ((g_voip_cntx_p->call_redial_info.currAttempt < g_voip_cntx_p->call_redial_info.maxAttempt) &&
                (strlen((S8*)g_voip_cntx_p->call_redial_info.redialUri)))
            {
                //mmi_voip_entry_redial();
                g_voip_cntx_p->call_redial_info.currAttempt++;
                mmi_voip_ucm_auto_redial_ind();
            }
            else
            {
                mmi_voip_entry_abort_redial();
            }
        }
        /* call not exist error cause does not apply auto redial, 
           but redial structure needs to clear to prevent misuse by next call */
        else
        {
            mmi_voip_entry_abort_redial();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_accept_req
 * DESCRIPTION
 *  Send accept request to VoIP CC.
 * PARAMETERS
 *  callId      [IN]        Incoming call id that intends to accept
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_accept_req(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = 0;

    msgReq->op_code = VOIP_CALL_ACT_ACCEPT_CALL;
    msgReq->active_call.call_id = callId;
    msgReq->active_call.dialog_id = 0;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_accept_rsp
 * DESCRIPTION
 *  Receive accept response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_accept_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0, dialogId = 0;
    U8 opCode = 0;
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = g_voip_cntx_p->call_list_info.processCId;
    dialogId = g_voip_cntx_p->call_list_info.processDId;
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;
    opCode = SRV_UCM_INT_ACCEPT_ACT;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(opCode, TRUE, NULL);
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(opCode, FALSE, (U8*)GetString(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_req
 * DESCRIPTION
 *  Send hold request to VoIP CC.
 * PARAMETERS
 *  callId      [IN]        Active call id that intends to hold
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hold_req(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = VOIP_MAX_NUM_DIALOG;

    msgReq->op_code = VOIP_CALL_ACT_HOLD_CALL;
    msgReq->hold_call.call_id = callId;
    msgReq->hold_call.dialog_id = VOIP_MAX_NUM_DIALOG;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_rsp
 * DESCRIPTION
 *  Receive hold response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hold_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_HOLD_ACT, TRUE, (U8*)GetString(STR_ID_VOIP_HOLD_OK));
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_HOLD_ACT, FALSE, (U8*)GetString(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_retrieve_req
 * DESCRIPTION
 *  Send retrieve request to VoIP CC.
 * PARAMETERS
 *  callId      [IN]        Held call id that intends to retrieve
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_retrieve_req(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = VOIP_MAX_NUM_DIALOG;

    msgReq->op_code = VOIP_CALL_ACT_RETRIEVE_CALL;
    msgReq->active_call.call_id = callId;
    msgReq->active_call.dialog_id = VOIP_MAX_NUM_DIALOG;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_retrieve_rsp
 * DESCRIPTION
 *  Receive retrieve response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_retrieve_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_RETRIEVE_ACT, TRUE, (U8*)GetString(STR_ID_VOIP_RETRIEVE_OK));
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_RETRIEVE_ACT, FALSE, (U8*)GetString(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_swap_req
 * DESCRIPTION
 *  Send swap request to VoIP CC.
 * PARAMETERS
 *  activecallId        [IN]        Active call id that intends to hold
 *  heldcallId          [IN]        Held call id that intends to retrieve
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_swap_req(S32 activecallId, S32 heldcallId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 currhiliteTab = 0, callId = 0;
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    currhiliteTab = g_voip_cntx_p->call_misc_info.currhiliteTab;
    callId = g_voip_cntx_p->call_list_info.call_info[currhiliteTab].callId;

    /* in case of release call, release current highlight call */
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = VOIP_MAX_NUM_DIALOG;

    msgReq->op_code = VOIP_CALL_ACT_SWAP_CALL;
    msgReq->active_call.call_id = activecallId;
    msgReq->active_call.dialog_id = VOIP_MAX_NUM_DIALOG;
    msgReq->hold_call.call_id = heldcallId;
    msgReq->hold_call.dialog_id = VOIP_MAX_NUM_DIALOG;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_swap_rsp
 * DESCRIPTION
 *  Receive swap response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_swap_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_SWAP_ACT, TRUE, (U8*)GetString(STR_ID_VOIP_SWAP_OK));
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_SWAP_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_SWAP_FAIL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_merge_req
 * DESCRIPTION
 *  Send merge request to VoIP CC.
 * PARAMETERS
 *  activecallId        [IN]        Active call id that will be the first dialog of conference call
 *  heldcallId          [IN]        Held call id that will be the second dialog of conference call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_merge_req(S32 activecallId, S32 heldcallId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case of release call, release original held call */
    g_voip_cntx_p->call_list_info.processCId = heldcallId;
    g_voip_cntx_p->call_list_info.processDId = VOIP_MAX_NUM_DIALOG;

    msgReq->op_code = VOIP_CALL_ACT_MERGE_CALL;
    msgReq->active_call.call_id = activecallId;
    msgReq->active_call.dialog_id = VOIP_MAX_NUM_DIALOG;
    msgReq->hold_call.call_id = heldcallId;
    msgReq->hold_call.dialog_id = VOIP_MAX_NUM_DIALOG;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_merge_rsp
 * DESCRIPTION
 *  Receive merge response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_merge_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, TRUE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_CONFERENCE_ACT, TRUE, (U8*)GetString(STR_ID_VOIP_CONFERENCE_OK));
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, TRUE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_CONFERENCE_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_CONFERENCE_FAIL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_split_req
 * DESCRIPTION
 *  Send split request to VoIP CC.
 * PARAMETERS
 *  activecallId        [IN]        Active call id that will remain an active call
 *  helddialogId        [IN]        Unhilite dialog id that will be a held call
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_split_req(S32 callId, S32 helddialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = helddialogId;

    msgReq->op_code = VOIP_CALL_ACT_SPLIT_CALL;
    msgReq->hold_call.call_id = callId;
    msgReq->hold_call.dialog_id = helddialogId;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_split_rsp
 * DESCRIPTION
 *  Receive split response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_split_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, TRUE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_SPLIT_ACT, TRUE, (U8*)GetString(STR_ID_VOIP_SPLIT_OK));
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, TRUE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_SPLIT_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_SPLIT_FAIL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_release_req
 * DESCRIPTION
 *  Send release request to VoIP CC.
 * PARAMETERS
 *  callId          [IN]        Call id that intends to release
 *  dialogId        [IN]        Dialog id that intends to release
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_release_req(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = dialogId;

    if ((callId != -1) && (dialogId != -1)) /* end single */
    {
        msgReq->op_code = VOIP_CALL_ACT_REL_CALL;
        /* distinguish abort call so that voip cc can ignore the action 
           if the call is connected by remote first */
        msgReq->abort_call_id = (g_voip_cntx_p->call_misc_info.isAbort == TRUE) ? (callId) : (-1);
        if (callId != g_voip_cntx_p->call_list_info.maxnumCall)
        {
            msgReq->rel_call.call_id = callId;
            msgReq->rel_call.dialog_id = dialogId;
        }
    }
    else if (callId != -1) /* end conference */
    {
        msgReq->op_code = VOIP_CALL_ACT_REL_CALL;
        msgReq->abort_call_id = -1;
        msgReq->rel_call.call_id = callId;
        msgReq->rel_call.dialog_id = VOIP_MAX_NUM_DIALOG;
    }
    else /* end all */
    {
        msgReq->op_code = VOIP_CALL_ACT_REL_ALL_CALLS;
        msgReq->abort_call_id = -1;
    }

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_release_rsp
 * DESCRIPTION
 *  Receive release response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_release_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0, dialogId = 0;
    S16 dialogIdx = 0;
    MMI_BOOL callAbort = FALSE;
    U8 opCode = 0;
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = g_voip_cntx_p->call_list_info.processCId;
    dialogId = g_voip_cntx_p->call_list_info.processDId;
    callAbort = g_voip_cntx_p->call_misc_info.isAbort;

    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;
    g_voip_cntx_p->call_misc_info.isAbort = FALSE;
    dialogIdx = mmi_voip_get_dialog_idx(callId, dialogId);

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        if ((callId != -1) && (dialogId != -1)) /* end single */
        {
            if(mmi_voip_ucm_get_act_opcode() == SRV_UCM_INT_END_ALL_ACT)
            {
                opCode = SRV_UCM_INT_END_ALL_ACT;
            }
            else
            {
                opCode = SRV_UCM_INT_END_SINGLE_ACT;
            }
        }
        else if (callId != -1) /* end conference */
        {
            opCode = SRV_UCM_INT_END_CONFERENCE_ACT;
        }
        else /* end all */
        {
            opCode = SRV_UCM_INT_END_ALL_ACT;
        }

        opCode = mmi_voip_ucm_get_act_opcode();
        
        mmi_voip_ucm_act_rsp(opCode, TRUE, NULL);
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        if ((callId != -1) && (dialogId != -1)) /* end single */
        {
            opCode = SRV_UCM_INT_END_SINGLE_ACT;
        }
        else if (callId != -1) /* end conference */
        {
            opCode = SRV_UCM_INT_END_CONFERENCE_ACT;
        }
        else /* end all */
        {
            opCode = SRV_UCM_INT_END_ALL_ACT;
        }
        
        if (callAbort == TRUE)
        {
            callAbort = FALSE;
            mmi_voip_ucm_release_ind(callId, dialogIdx, (U8*)GetString(STR_ID_VOIP_CALL_ABORT), IMG_ID_VOIP_CALL_ENDED, SUCCESS_TONE_IN_CALL);
        }
        opCode = mmi_voip_ucm_get_act_opcode();
        mmi_voip_ucm_act_rsp(opCode, TRUE, NULL); /* release call cannot fail */
        if (opCode == SRV_UCM_INT_FORCE_RELEASE_ACT)
        {
            mmi_voip_del_call_from_force_rel_list(0xffff, 0xffff, MMI_FALSE);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_force_release_req
 * DESCRIPTION
 *  Send force release request to VoIP CC.
 * PARAMETERS
 *  callId          [IN]        Call id that intends to force release
 *  dialogId        [IN]        Dialog id that intends to force release
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_force_release_req(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, j = 0;
    mmi_voip_call_act_req_struct *msgReq;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ClearInputEventHandler(MMI_DEVICE_ALL);
    ClearKeyHandler(KEY_END, KEY_EVENT_UP);
    ClearKeyHandler(KEY_END, KEY_EVENT_DOWN);
    ClearKeyHandler(KEY_END, KEY_LONG_PRESS);
    ClearKeyHandler(KEY_END, KEY_REPEAT);

    if ((callId != -1) && (dialogId != -1))
    {
        msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));
        msgReq->op_code = VOIP_CALL_ACT_FORCE_REL_CALL;
        /* distinguish abort call so that voip cc can ignore the action 
           if the call is connected by remote first */
        msgReq->abort_call_id = (g_voip_cntx_p->call_misc_info.isAbort == TRUE) ? (callId) : (-1);
        if (callId != g_voip_cntx_p->call_list_info.maxnumCall)
        {
            msgReq->rel_call.call_id = callId;
            msgReq->rel_call.dialog_id = dialogId;
        }
        mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
    }
    else if (callId != -1)
    {
        for (i = 0; i < VOIP_MAX_NUM_DIALOG; i++)
        {
            msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));
            msgReq->op_code = VOIP_CALL_ACT_FORCE_REL_CALL;
            msgReq->abort_call_id = -1;
            msgReq->rel_call.call_id = callId;
            msgReq->rel_call.dialog_id = i;
            mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
        }
    }
    else /* end all */
    {
        for (i = 0; i < g_voip_cntx_p->call_list_info.numTotal; i++)
        {
            for (j = 0; j < g_voip_cntx_p->call_list_info.call_info[i].numDialog; j++)
            {
                msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));
                msgReq->op_code = VOIP_CALL_ACT_FORCE_REL_CALL;
                msgReq->abort_call_id = -1;
                msgReq->rel_call.call_id = g_voip_cntx_p->call_list_info.call_info[i].callId;
                msgReq->rel_call.dialog_id = g_voip_cntx_p->call_list_info.call_info[i].dialog_info[j].dialogId;
                mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_force_release_rsp
 * DESCRIPTION
 *  Receive force release response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_force_release_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* force release will not receive its response, instead, original release response will receive */
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_background_reject_req
 * DESCRIPTION
 *  Send background reject request to VoIP CC.
 * PARAMETERS
 *  callId          [IN]        Call id that intends to background reject
 *  dialogId        [IN]        Dialog id that intends to background reject
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_background_reject_req(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.bkrejCId = callId;
    g_voip_cntx_p->call_list_info.bkrejDId = dialogId;

    if ((callId != -1) && (dialogId != -1))
    {
        msgReq->op_code = VOIP_CALL_ACT_BK_REL_MT_CALL;
        msgReq->abort_call_id = -1;
        msgReq->rel_call.call_id = callId;
        msgReq->rel_call.dialog_id = dialogId;
    }

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_background_reject_rsp
 * DESCRIPTION
 *  Receive background reject response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_background_reject_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_act_bk_rej_rsp_struct *msgRsp = (mmi_voip_act_bk_rej_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((msgRsp->call_id == g_voip_cntx_p->call_list_info.bkrejCId) && 
        (msgRsp->dialog_id == g_voip_cntx_p->call_list_info.bkrejDId))
    {
        g_voip_cntx_p->call_list_info.bkrejCId = -1;
        g_voip_cntx_p->call_list_info.bkrejDId = -1;
    }      

    if (msgRsp->result == VOIP_OK)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_BK_REJECT, g_voip_cntx_p->call_list_info.bkrejCId, g_voip_cntx_p->call_list_info.bkrejDId);
        mmi_voip_del_from_call_list(msgRsp->call_id, msgRsp->dialog_id);
    }
    /* call not exist error cause is because of race condition, 
       need to delete mmi call list to sync with voip cc */
    else if (msgRsp->cause == VOIP_CALL_NOT_EXIST)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_VOIP_BK_REJECT, g_voip_cntx_p->call_list_info.bkrejCId, g_voip_cntx_p->call_list_info.bkrejDId);
        mmi_voip_del_from_call_list(msgRsp->call_id, msgRsp->dialog_id);
    }
}

#if (0)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_voip_transfer_req
 * DESCRIPTION
 *  Send blind transfer request to VoIP CC.
 * PARAMETERS
 *  callId          [IN]        Call id that intends to transfer
 *  dialogId        [IN]        Dialog id that intends to transfer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_transfer_req(S32 callId, S32 dialogId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = dialogId;

#ifdef __MMI_VOIP_UNATTENDED_TRANSFER__
    msgReq->op_code = VOIP_CALL_ACT_UNATTENDED_TRANSFER;
#else
    msgReq->op_code = VOIP_CALL_ACT_BLIND_TRANSFER;
#endif
    msgReq->active_call.call_id = callId;
    msgReq->active_call.dialog_id = dialogId;
    memcpy(msgReq->target_call, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_transfer_rsp
 * DESCRIPTION
 *  Receive blind transfer response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_transfer_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_TRANSFER_ACT, TRUE, NULL);
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_act_rsp(SRV_UCM_INT_TRANSFER_ACT, FALSE, (U8*)GetString(STR_ID_VOIP_TRANSFER_FAIL));
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_transferee_cnf
 * DESCRIPTION
 *  Send transferee confirm to VoIP CC.
 * PARAMETERS
 *  result          [IN]        Approve to proceed to be the transferee or not
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_transferee_cnf(U8 result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_transferee_cnf_struct *msgReq;
    msgReq = (mmi_voip_transferee_cnf_struct*)OslConstructDataPtr(sizeof(mmi_voip_transferee_cnf_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msgReq->result = result;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_TRANSFEREE_CNF, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_sos_req
 * DESCRIPTION
 *  Send dial SOS request to VoIP CC.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dial_sos_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_voip_cntx_p->call_list_info.processCId = 0;
    g_voip_cntx_p->call_list_info.processDId = 0;

    msgReq->op_code = VOIP_CALL_ACT_REL_ALL_AND_DIAL_EMERGENCY;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_dial_sos_rsp
 * DESCRIPTION
 *  Receive dial SOS response from VoIP CC.
 * PARAMETERS
 *  inMsg           [IN]        Message structure from voip cc
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_dial_sos_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 callId = 0, dialogId = 0;
    mmi_voip_call_act_rsp_struct *msgRsp = (mmi_voip_call_act_rsp_struct*)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    callId = g_voip_cntx_p->call_list_info.processCId;
    dialogId = g_voip_cntx_p->call_list_info.processDId;
    g_voip_cntx_p->call_list_info.processCId = -1;
    g_voip_cntx_p->call_list_info.processDId = -1;

    if (msgRsp->result == VOIP_OK)
    {
        /* emergency call does not apply auto redial, but redial structure needs to clear to prevent misuse by next call */
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            mmi_voip_entry_abort_redial();
        }
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        mmi_voip_ucm_connect_ind(callId, dialogId);
    }
    else
    {
        mmi_voip_update_call_list(msgRsp->call_list, FALSE);
        /* send release_ind to ucm only if it does not actually dial to sip, otherwise, 
           it will send two release_ind (one is in call_end_ind, the other is here), which will cause ucm assert */
        if ((msgRsp->cause == VOIP_INVALID_PARAM) || (msgRsp->cause == VOIP_BUSY))
        {
            mmi_voip_ucm_release_ind(callId, dialogId, (U8*)GetString(mmi_voip_get_error_cause(msgRsp->result, msgRsp->cause)), IMG_GLOBAL_UNFINISHED, SUCCESS_TONE_IN_CALL);
        }

        /* emergency call does not apply auto redial, but redial structure needs to clear to prevent misuse by next call */
        if (mmi_voip_is_auto_redial() == MMI_TRUE)
        {
            mmi_voip_entry_abort_redial();
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_and_dial_req
 * DESCRIPTION
 *  Send hold and dial request to VoIP CC.
 * PARAMETERS
 *  callId      [IN]        Active call id that intends to hold
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hold_and_dial_req(S32 callId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* not have dialing call id yet so set intended hold call id to voip cc
       in case of release call, release dialing call still */
    g_voip_cntx_p->call_list_info.processCId = callId;
    g_voip_cntx_p->call_list_info.processDId = VOIP_MAX_NUM_DIALOG;

    msgReq->op_code = VOIP_CALL_ACT_HOLD_AND_DIAL;
    msgReq->hold_call.call_id = callId;
    msgReq->hold_call.dialog_id = VOIP_MAX_NUM_DIALOG;
    memcpy(msgReq->target_call, g_voip_cntx_p->call_misc_info.inputUri, VOIP_URI_LEN);

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_voip_hold_and_accept_req
 * DESCRIPTION
 *  Send hold and accept request to VoIP CC.
 * PARAMETERS
 *  activecallId        [IN]        Active call id that intends to hold
 *  mtcallId            [IN]        Incoming call id that intends to accept
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_voip_hold_and_accept_req(S32 activecallId, S32 mtcallId)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_voip_call_act_req_struct *msgReq;
    msgReq = (mmi_voip_call_act_req_struct*)OslConstructDataPtr(sizeof(mmi_voip_call_act_req_struct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* in case of release call, release accepting call */
    g_voip_cntx_p->call_list_info.processCId = mtcallId;
    g_voip_cntx_p->call_list_info.processDId = 0;

    msgReq->op_code = VOIP_CALL_ACT_HOLD_AND_ACCEPT;
    msgReq->active_call.call_id = mtcallId;
    msgReq->active_call.dialog_id = 0;
    msgReq->hold_call.call_id = activecallId;
    msgReq->hold_call.dialog_id = VOIP_MAX_NUM_DIALOG;

    mmi_voip_send_message(MOD_MMI, MOD_VOIP, MSG_ID_MMI_VOIP_CALL_ACT_REQ, msgReq, NULL);
}


#endif /* __MMI_VOIP__ */

