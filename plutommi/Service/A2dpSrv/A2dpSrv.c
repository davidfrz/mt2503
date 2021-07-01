/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * A2dpSrv.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * A2dp connection service
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#ifdef __MMI_A2DP_SUPPORT__

/****************************************************************************
* header files
****************************************************************************/
#ifdef __MMI_AVRCP_SUPPORT__
#include "BTMMIAVRCPGProt.h"
#include "AvrcpSrvGprot.h"
#endif
#ifdef __MMI_BT_AUDIO_VIA_SCO__                  
#include "mmi_rp_srv_btsco_def.h"
#include "BthScoPathSrvGProt.h"
#endif
#include "MMI_conn_app_trc.h"
#include "BTAudioSrvGprot.h"
#include "BTMMIScrGprots.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_rp_srv_a2dp_def.h"
#include "MMIDataType.h"
#include "Conversions.h"
#include "mdi_audio.h"
#include "aud_main.h"

#include "A2dpSrvGprot.h"
#include "A2dpSrv.h"
#include "A2dpSrvUtil.h"

/****************************************************************************
* data define
****************************************************************************/
static a2dp_ctx_struct g_srv_a2dp_cntx;
srv_bt_a2dp_cm_connect_notify cm_notify_callback = NULL;
srv_a2dp_sink_app_callback g_avrcp_cm_callback;
static srv_bt_cm_bt_addr g_a2dp_open_addr;
static bt_a2dp_audio_cap_struct g_a2dp_reconfig_cfg;
static MMI_BOOL g_a2dp_streaming_suspended = MMI_FALSE; //local call
static MMI_BOOL g_a2dp_suspended_by_call = MMI_FALSE; //dialer call
//static MMI_BOOL g_a2dp_cm_notify = MMI_FALSE;
static MMI_BOOL g_a2dp_streaming_interrupt = MMI_FALSE; //for SP2 interrupt SP1
static MMI_BOOL g_a2dp_need_reopen = MMI_FALSE; //for reopen, must false for the first time
static MMI_BOOL g_a2dp_delay_start = MMI_FALSE; //for MAUI_03494324
static MMI_BOOL g_a2dp_stream_stop = MMI_FALSE; //for MAUI_03494324
static MMI_BOOL g_a2dp_stream_disable = MMI_FALSE; // for MAUI_03507248

static U16 g_gsm_call_active = 0;
static U16 g_call_suspend_index;
static U16 g_sp_interrupt_index;
static U16 g_local_interrupt_index;
static U16 g_delay_callback_index;

#if !defined(__IOT__)
extern void mmi_bt_dialor_connect_a2dp_src_cb(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
#endif
/****************************************************************************
* function define
****************************************************************************/
static void mmi_a2dp_send_avrcp_cmd(S32 cmd_frame);

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_cmp_aud_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  aud_cfg1    [IN]
 *  aud_cfg2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool mmi_a2dp_cmp_aud_cfg(bt_a2dp_audio_cap_struct *aud_cfg1, bt_a2dp_audio_cap_struct *aud_cfg2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_bool result = KAL_FALSE;
    bt_a2dp_sbc_codec_cap_struct *sbc_cfg1, *sbc_cfg2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (aud_cfg1->codec_type == aud_cfg2->codec_type)
    {
        switch (aud_cfg1->codec_type)
        {
            case BT_A2DP_SBC:
                sbc_cfg1 = &aud_cfg1->codec_cap.sbc;
                sbc_cfg2 = &aud_cfg2->codec_cap.sbc;
                result = (kal_bool)(sbc_cfg1->block_len == sbc_cfg2->block_len &&
                    sbc_cfg1->subband_num == sbc_cfg2->subband_num &&
                    sbc_cfg1->alloc_method == sbc_cfg2->alloc_method &&
                    sbc_cfg1->sample_rate == sbc_cfg2->sample_rate &&
                    sbc_cfg1->channel_mode == sbc_cfg2->channel_mode);
                break;
        #ifndef __LOW_COST_SUPPORT_COMMON__
            case BT_A2DP_MP3:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.mp3,
                            (const void*)&aud_cfg2->codec_cap.mp3,
                            sizeof(bt_a2dp_mp3_codec_cap_struct)) == 0);
                break;
            case BT_A2DP_AAC:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.aac,
                            (const void*)&aud_cfg2->codec_cap.aac,
                            sizeof(bt_a2dp_aac_codec_cap_struct)) == 0);
                break;
            case BT_A2DP_ATRAC:
                result = (kal_bool)(memcmp(
                            (const void*)&aud_cfg1->codec_cap.atrac,
                            (const void*)&aud_cfg2->codec_cap.atrac,
                            sizeof(bt_a2dp_atrac_codec_cap_struct)) == 0);
                break;
        #endif /*__LOW_COST_SUPPORT_COMMON__*/

            default:
                ASSERT(0);
        }
    }

    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_COMPARE_AUDIO_CFG, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_active_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_active_req(void)
{ 
    bt_a2dp_audio_cap_struct src_aud_cap[MAX_A2DP_SRC_SEP_NUM];
#ifdef __MMI_BT_SPEAKER_SUPPORT__
    bt_a2dp_audio_cap_struct sink_aud_cap[MAX_A2DP_SNK_SEP_NUM];
#endif
    U8 i = 0;
    U8 j = 0;


    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_ACTIVE_REQ);

#ifdef __MMI_BT_SPEAKER_SUPPORT__
    for (i=0; i<MAX_A2DP_SRC_LINK_NUM; i++)
    {
        src_aud_cap[i*A2DP_SRC_CODEC_NUM].codec_type = BT_A2DP_SBC;
        memcpy(&(src_aud_cap[i*A2DP_SRC_CODEC_NUM].codec_cap.sbc),
               &(sbc_cap[0]),
               sizeof(bt_a2dp_sbc_codec_cap_struct));
        /*
        src_aud_cap[i*A2DP_SRC_CODEC_NUM + 1].codec_type = BT_A2DP_MP3;
        memcpy(&(src_aud_cap[i*A2DP_SRC_CODEC_NUM + 1].codec_cap.mp3),
               &(mp3_cap[0]),
               sizeof(bt_a2dp_mp3_codec_cap_struct));

        src_aud_cap[i*A2DP_SRC_CODEC_NUM + 2].codec_type = BT_A2DP_AAC;
        memcpy(&(src_aud_cap[i*A2DP_SRC_CODEC_NUM + 2].codec_cap.aac),
               &(aac_cap[0]),
               sizeof(bt_a2dp_aac_codec_cap_struct));*/
    }

    for (i=0; i<MAX_A2DP_SNK_LINK_NUM; i++)
    {
        j = i*A2DP_SNK_CODEC_NUM - 1;
        #if defined(SBC_DECODE)
        j++;
        sink_aud_cap[j].codec_type = BT_A2DP_SBC;
        memcpy(&(sink_aud_cap[j].codec_cap.sbc),
               &(sbc_cap_snk[0]),
               sizeof(bt_a2dp_sbc_codec_cap_struct));
        #endif
        #if  !defined (__MMI_WEARABLE_DEVICE__)
        #if defined(DAF_DECODE)
        j++;
        sink_aud_cap[j].codec_type = BT_A2DP_MP3;
        memcpy(&(sink_aud_cap[j].codec_cap.mp3),
               &(mp3_cap_snk[0]),
               sizeof(bt_a2dp_mp3_codec_cap_struct));
        #endif

        #if defined(AAC_DECODE)
        j++;
        sink_aud_cap[j].codec_type = BT_A2DP_AAC;
        memcpy(&(sink_aud_cap[j].codec_cap.aac),
               &(aac_cap_snk[0]),
               sizeof(bt_a2dp_aac_codec_cap_struct));
        #endif
        #endif
    }

    btmtk_a2dp_send_activate_req(src_aud_cap,
                                 sink_aud_cap,
                                 MAX_A2DP_SRC_SEP_NUM,
                                 MAX_A2DP_SNK_SEP_NUM);
#else
    for (i=0; i<MAX_A2DP_SRC_LINK_NUM; i++)
    {
        src_aud_cap[i*A2DP_SRC_CODEC_NUM].codec_type = BT_A2DP_SBC;
        memcpy(&(src_aud_cap[i*A2DP_SRC_CODEC_NUM].codec_cap.sbc),
               &(sbc_cap[0]),
               sizeof(bt_a2dp_sbc_codec_cap_struct));
    }

    btmtk_a2dp_send_activate_req(src_aud_cap,
                                 NULL,
                                 MAX_A2DP_SRC_SEP_NUM,
                                 MAX_A2DP_SNK_SEP_NUM);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_active_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_active_cnf(void *message)
{
    bt_a2dp_activate_cnf_struct *pMsg = NULL;

    pMsg = (bt_a2dp_activate_cnf_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_ACTIVE_CNF, pMsg->result);
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {
        g_srv_a2dp_cntx.ctx_actived = KAL_TRUE;
        
        srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_deactive_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_deactive_req()
{
    U8 index = 0;
    U8 count = 0;

    if (!g_srv_a2dp_cntx.ctx_actived)
    {
        return;
    }

    for (index=0; index<MAX_A2DP_LINK_NUM; index++)
    {
        if (A2DP_STATE_IDLE < g_srv_a2dp_cntx.dev_info[index].state)
        {
            count++;
            g_srv_a2dp_cntx.deactive_pending = KAL_TRUE;
            mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[index]));
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEACTIVE_REQ, count);
    if (0 == count)
    {
        btmtk_a2dp_send_deactivate_req();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_deactive_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_deactive_cnf(void *message)
{
    bt_a2dp_deactivate_cnf_struct *pMsg = NULL;

    pMsg = (bt_a2dp_deactivate_cnf_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEACTIVE_CNF, pMsg->result);
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {
       mmi_a2dp_reset_ctx();
       srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_disconnect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_disconnect_req(U32 connect_id)
{
    U8 index = 0;
    S32 result;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DISCONNECT, connect_id); 
    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        if(connect_id == g_srv_a2dp_cntx.dev_info[index].cmgr_id)
        {
            cm_notify_callback = g_srv_a2dp_cntx.dev_info[index].cm_callback;
            result = srv_a2dp_close_ex(&(g_srv_a2dp_cntx.dev_info[index].address));
            break;
        }
    }

    if(result == SRV_A2DP_CLOSE_DONE)
    {
        mmi_a2dp_notify_cm(&(g_srv_a2dp_cntx.dev_info[index].address), MMI_TRUE, MMI_FALSE, MMI_FALSE, MMI_TRUE);
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_open_cnf(void *message)
{
    bt_a2dp_stream_open_cnf_struct *pMsg = NULL;
    A2DP_SRV_CALLBACK user_callback;
    mmi_event_struct evt;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_open_cnf_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPENE_CNF, pMsg->result);
    bFound = mmi_a2dp_quiry_by_address((srv_bt_cm_bt_addr*)(&pMsg->device_addr), &index);
    if (!bFound)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_TRC_A2DP_SRV_OPENE_CNF_INFO,
              g_srv_a2dp_cntx.dev_info[index].role,
              g_srv_a2dp_cntx.dev_info[index].state,
              g_srv_a2dp_cntx.dev_info[index].waitting,
              g_srv_a2dp_cntx.dev_info[index].reverse_state);
    
    if (A2DP_WAIT_OPEN_CNF != g_srv_a2dp_cntx.dev_info[index].waitting)
    {
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
    }
    
    user_callback = g_srv_a2dp_cntx.dev_info[index].user_callback;
    cm_notify_callback = g_srv_a2dp_cntx.dev_info[index].cm_callback;
    if (BT_A2DP_RESULT_OK == pMsg->result ||
        g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_OPEN)
    {
        MMI_BOOL conn_conflict = MMI_FALSE;
        if (g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_OPEN)
        {
            conn_conflict = MMI_TRUE;
        }
        if (!conn_conflict)
        {
            g_srv_a2dp_cntx.dev_info[index].stream_hdl = pMsg->stream_handle;
            g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_OPEN;
            memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
               &(pMsg->current_config),
               sizeof(bt_a2dp_audio_cap_struct));
        }

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CONFIG_AUDIO_CAP, g_srv_a2dp_cntx.dev_info[index].audio_cfg.codec_type);
        g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
        g_srv_a2dp_cntx.dev_info[index].is_open_req = KAL_TRUE;

        srv_bt_cm_connect_ind(g_srv_a2dp_cntx.dev_info[index].cmgr_id);
        mmi_a2dp_notify_cm(&(g_srv_a2dp_cntx.dev_info[index].address),MMI_TRUE,MMI_TRUE,MMI_FALSE, g_srv_a2dp_cntx.init_from_cm);
        
        if (g_srv_a2dp_cntx.dev_info[index].is_connect_avrcp)
        {
            g_srv_a2dp_cntx.dev_info[index].is_connect_avrcp = KAL_FALSE;
        #ifdef __MMI_AVRCP_SUPPORT__
            mmi_a2dp_connect_avrcp(g_srv_a2dp_cntx.dev_info[index].address,
                                   g_srv_a2dp_cntx.dev_info[index].role);
        #endif
        }
        else
        {
            mmi_a2dp_notify((srv_bt_cm_bt_addr*)(&pMsg->device_addr),
                            user_callback,
                            SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
        }

        //if play local APP need start_stream
        if((g_srv_a2dp_cntx.dev_info[index].reverse_state == A2DP_REVERSE_STEP_OPEN)
            && (g_srv_a2dp_cntx.dev_info[index].waitting == A2DP_WAIT_NONE))
        {
            mmi_a2dp_start_req(&(g_srv_a2dp_cntx.dev_info[index]));
            g_srv_a2dp_cntx.dev_info[index].reverse_state = A2DP_REVERSE_STEP_STREAMING;
        }

        
    #if defined(__BT_SPEAKER_SUPPORT__)
        //notify app a2dp will play, local app should close to idle
        if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
        {
            MMI_BOOL in_bt_call = MMI_FALSE;
            MMI_BOOL is_streaming = MMI_FALSE;
        #ifdef __MMI_HF_SUPPORT__
            in_bt_call = srv_bt_dialer_is_any_call();
        #endif
            is_streaming = srv_a2dp_sink_is_streaming();
            if((g_gsm_call_active <= 0) && (!in_bt_call) && (!is_streaming))
            {
                mdi_audio_terminate_background_play();
            }
            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_A2DP_CONNECT);
            evt.user_data = (void*)(&g_srv_a2dp_cntx.dev_info[index].address);
            mmi_frm_cb_emit_post_event(&evt);
        }
    #endif
    }
    else
    {
        srv_bt_cm_stop_conn(g_srv_a2dp_cntx.dev_info[index].cmgr_id);
        mmi_a2dp_notify((srv_bt_cm_bt_addr*)(&pMsg->device_addr), 
                        user_callback, 
                        SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
        mmi_a2dp_notify_cm((srv_bt_cm_bt_addr*)(&pMsg->device_addr),
                            MMI_FALSE, MMI_TRUE, MMI_FALSE, g_srv_a2dp_cntx.init_from_cm);

        mmi_a2dp_enable_sco();
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        srv_a2dp_open_audio_via_sco();
    #endif
        mmi_a2dp_reset_dev_info(index);
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_open_ind(void *message)
{
    bt_a2dp_stream_open_ind_struct *pMsg = NULL;
    kal_bool bFound = KAL_FALSE;
    MMI_BOOL is_dialer;
    MMI_BOOL dev_existed = MMI_FALSE;
    MMI_BOOL conn_conflict = MMI_FALSE;
    mmi_event_struct evt;
    U8 index = 0;
    S32 cmgr_id;
    g_a2dp_need_reopen = MMI_FALSE;

    pMsg = (bt_a2dp_stream_open_ind_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPEN_IND, pMsg->local_role);

    dev_existed = mmi_a2dp_quiry_by_address((srv_bt_cm_bt_addr*)(&pMsg->device_addr), &index);
    conn_conflict = dev_existed && g_srv_a2dp_cntx.dev_info[index].waitting == A2DP_WAIT_OPEN_CNF;
    if (!conn_conflict)
    {
        cmgr_id = srv_bt_cm_start_conn(MMI_TRUE, 
                                   SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID, 
                                   (srv_bt_cm_bt_addr*)(&pMsg->device_addr),
                                   NULL);
    
        bFound = mmi_a2dp_alloc_resource((srv_bt_cm_bt_addr *)&(pMsg->device_addr), (a2dp_role_enum)pMsg->local_role, &index);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_ALLOC_INDEX, index);
        //g_a2dp_cm_notify = MMI_TRUE;
    }

    if ((bFound && cmgr_id > 0) || conn_conflict)
    {
        if (!conn_conflict)
        {
            mmi_a2dp_reset_dev_info(index);
            memcpy(&(g_srv_a2dp_cntx.dev_info[index].address), 
                (srv_bt_cm_bt_addr *)&(pMsg->device_addr), 
                sizeof(srv_bt_cm_bt_addr));
            g_srv_a2dp_cntx.dev_info[index].cmgr_id = cmgr_id;
        }
        memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
                &(pMsg->current_config),
                sizeof(bt_a2dp_audio_cap_struct));
        
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CONFIG_AUDIO_CAP, g_srv_a2dp_cntx.dev_info[index].audio_cfg.codec_type);
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_OPEN;
        g_srv_a2dp_cntx.dev_info[index].stream_hdl = pMsg->stream_handle;
        g_srv_a2dp_cntx.dev_info[index].role = pMsg->local_role;
        g_srv_a2dp_cntx.dev_info[index].is_open_req = KAL_FALSE;
    #if !defined(__IOT__)

        if (!conn_conflict)
        {
            if(pMsg->local_role == A2DP_ROLE_SINK)
            {
                cm_notify_callback = mmi_bt_dialor_callback;
            }
            else
            {
                cm_notify_callback = mmi_bt_dialor_connect_a2dp_src_cb;
            }
        }
    #endif
        if (!conn_conflict)
        {
            g_srv_a2dp_cntx.dev_info[index].cm_callback = cm_notify_callback;

            srv_bt_cm_connect_ind(g_srv_a2dp_cntx.dev_info[index].cmgr_id);
            mmi_a2dp_notify_cm(&(g_srv_a2dp_cntx.dev_info[index].address),MMI_TRUE,MMI_TRUE,MMI_TRUE, MMI_FALSE);
            g_srv_a2dp_cntx.need_reconfig = KAL_TRUE;
            //mmi_a2dp_transfer_data();
        }
        btmtk_a2dp_send_stream_open_res(pMsg->stream_handle, BT_A2DP_RESULT_OK);
    }
    else
    {
        if(cmgr_id > 0)
        {
            srv_bt_cm_stop_conn(cmgr_id);
        }
        btmtk_a2dp_send_stream_open_res(pMsg->stream_handle, BT_A2DP_RESULT_BAD_STATE);
        btmtk_a2dp_send_stream_close_req(pMsg->stream_handle);

        is_dialer = srv_bt_cm_is_bt_dialer((srv_bt_cm_bt_addr*)&pMsg->device_addr);
        //dialer, need reopen
        if((pMsg->local_role == A2DP_ROLE_SOURCE) && is_dialer)
        {
            memcpy(&g_a2dp_open_addr,
                   (srv_bt_cm_bt_addr*)&pMsg->device_addr,
                    sizeof(srv_bt_cm_bt_addr));
            g_a2dp_need_reopen = MMI_TRUE;
        }
        return;
    }


    if(g_srv_a2dp_cntx.check_output_callback && !g_srv_a2dp_cntx.check_output_callback())
    {
        srv_a2dp_close_ex((srv_bt_cm_bt_addr *)&(pMsg->device_addr));
    }

#if defined(__BT_SPEAKER_SUPPORT__)
    //notify app a2dp will play, app should close to idle
    if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
    {
        MMI_BOOL in_bt_call = MMI_FALSE;
        MMI_BOOL is_streaming = MMI_FALSE;
    #ifdef __MMI_HF_SUPPORT__
        in_bt_call = srv_bt_dialer_is_any_call();
    #endif
        is_streaming = srv_a2dp_sink_is_streaming();
        if((g_gsm_call_active <= 0) && (!in_bt_call) && (!is_streaming))
        {
            mdi_audio_terminate_background_play();
        }
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_A2DP_CONNECT);
        evt.user_data = (void*)(&g_srv_a2dp_cntx.dev_info[index].address);
        mmi_frm_cb_emit_post_event(&evt);
    }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_open_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_open_done(void *message)
{
    bt_a2dp_stream_open_cnf_struct *pMsg = NULL;
    A2DP_SRV_CALLBACK user_callback;
    mmi_event_struct evt;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_open_cnf_struct *)message;
    bFound = mmi_a2dp_quiry_by_address((srv_bt_cm_bt_addr*)(&pMsg->device_addr), &index);
    if (!bFound)
    {
        return;
    }

    if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SOURCE)
    {
        g_delay_callback_index = index;
        StartTimer(AV_BT_START_TIMER, A2DP_SRV_PLAY_DUR_TIME, (FuncPtr)mmi_a2dp_delay_open_callback_hdlr);
    }
    else
    {
        mmi_a2dp_notify((srv_bt_cm_bt_addr*)(&pMsg->device_addr),
                        g_srv_a2dp_cntx.dev_info[index].user_callback,
                        SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
    }

    if ((BT_A2DP_RESULT_OK == pMsg->result) && (g_srv_a2dp_cntx.need_reconfig == KAL_TRUE))
    {
        MMI_A2DP_MESSAGE_TRANS(pMsg->result);
        mmi_a2dp_transfer_data();
    }

    g_srv_a2dp_cntx.need_reconfig = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_start_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_start_cnf(void *message)
{
    bt_a2dp_stream_start_cnf_struct *pMsg = NULL;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_start_cnf_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_START_CNF, pMsg->result); 
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (!bFound)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_TRC_A2DP_SRV_START_CNF_INFO,
              g_srv_a2dp_cntx.dev_info[index].role,
              g_srv_a2dp_cntx.dev_info[index].state,
              g_srv_a2dp_cntx.dev_info[index].waitting,
              g_srv_a2dp_cntx.dev_info[index].reverse_state);

    if (A2DP_WAIT_START_CNF != g_srv_a2dp_cntx.dev_info[index].waitting)
    {
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
    }
    
    g_srv_a2dp_cntx.dev_info[index].is_reconfig = KAL_FALSE;
    g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_STREAMING;
        memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
               &(pMsg->current_config),
               sizeof(bt_a2dp_audio_cap_struct));
        
        mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
                            g_srv_a2dp_cntx.dev_info[index].stream_hdl,
                            g_srv_a2dp_cntx.dev_info[index].role,
                            MMI_TRUE);
        
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                        g_srv_a2dp_cntx.dev_info[index].user_callback,
                        SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);

        if(g_srv_a2dp_cntx.dev_info[index].reverse_state == A2DP_REVERSE_STEP_STREAMING)
        {
            g_srv_a2dp_cntx.dev_info[index].reverse_state = A2DP_REVERSE_STEP_NONE;
        }
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_start_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_start_ind(void *message)
{
    bt_a2dp_stream_start_ind_struct *pMsg = NULL;
    S32 result = BT_A2DP_RESULT_BAD_STATE;
    kal_bool bFound = KAL_FALSE;
    kal_bool bSame = KAL_FALSE;
    kal_bool bStream = KAL_FALSE;
    MMI_BOOL is_dialer;
    U8 index = 0;
    U8 i = 0;
    a2dp_dev_info_struct info;

    pMsg = (bt_a2dp_stream_start_ind_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_START_IND);
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    
    if(bFound)
    {
        btmtk_a2dp_send_stream_start_res(pMsg->stream_handle, BT_A2DP_RESULT_OK);
    }
    else
    {
        btmtk_a2dp_send_stream_start_res(pMsg->stream_handle, BT_A2DP_RESULT_BAD_STATE);
        return;
    }

    if(g_gsm_call_active > 0)
    {
        if(g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_OPEN)
        {
            g_a2dp_streaming_suspended = MMI_TRUE;
            //pause the streaming req
            #ifdef __MMI_AVRCP_SUPPORT__
                srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[index].address), SRV_AVRCP_POP_PAUSE);
            #endif
        }
    }
#ifdef __MMI_HF_SUPPORT__
    else if(srv_bt_dialer_is_any_call())
    {
        g_a2dp_suspended_by_call = MMI_TRUE;

        if (g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_OPEN 
            && g_srv_a2dp_cntx.check_output_callback())
        {
            g_call_suspend_index = index;
            result = BT_A2DP_RESULT_OK;

            //the role is the local role
            if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
            {
                memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg), 
                       &(pMsg->current_config), 
                       sizeof(bt_a2dp_audio_cap_struct));
            }
        }
    }
#endif
    else
    {
        //for the parallel interrupt
        if(srv_a2dp_is_streaming())
        {
            U8 stream_index = 0;
            bStream = mmi_a2dp_quiry_streaming_dev(&stream_index);
            if(bStream && (g_srv_a2dp_cntx.dev_info[stream_index].role == A2DP_ROLE_SINK))
            {
                //close codec after pause req
            #ifdef __MMI_AVRCP_SUPPORT__
                srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[stream_index].address), SRV_AVRCP_POP_PAUSE);
            #endif
                mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[stream_index].role);
                g_a2dp_streaming_interrupt = MMI_TRUE;
            }
        }
        
        if (A2DP_STATE_OPEN == g_srv_a2dp_cntx.dev_info[index].state)
        {
            g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_STREAMING;

            //the role is the local role
            if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
            {
                memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg), 
                       &(pMsg->current_config), 
                       sizeof(bt_a2dp_audio_cap_struct));
            }

            if((!g_a2dp_streaming_interrupt) && (!g_a2dp_stream_disable))
            {
                mmi_a2dp_open_codec(&(pMsg->current_config),
                                    g_srv_a2dp_cntx.dev_info[index].stream_hdl,
                                    g_srv_a2dp_cntx.dev_info[index].role,
                                    MMI_TRUE);
            }
            else
            {
                g_sp_interrupt_index = index;
            }

            mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                            g_srv_a2dp_cntx.dev_info[index].user_callback,
                            SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
            
            // audio-sync mod
            if (g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
            {
                mmi_a2dp_check_audio_sync();
            }
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
          MMI_TRC_A2DP_SRV_START_IND_INFO,
          g_srv_a2dp_cntx.dev_info[index].role,
          g_srv_a2dp_cntx.dev_info[index].state,
          g_srv_a2dp_cntx.dev_info[index].waitting,
          g_srv_a2dp_cntx.dev_info[index].reverse_state);

    if(g_srv_a2dp_cntx.check_output_callback && !g_srv_a2dp_cntx.check_output_callback())
    {
        srv_a2dp_close_ex(&(g_srv_a2dp_cntx.dev_info[index].address));
        return;
    }

    if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SOURCE)
    {
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
        mmi_a2dp_pause_req(&(g_srv_a2dp_cntx.dev_info[index]));
        return;
    }

    //notify the next to start
    mmi_a2dp_transfer_data();

    //if this is sink streaming, next is sink & dialer, need reverse
    for(i = 0; i < MAX_A2DP_LINK_NUM; i++)
    {
        srv_a2dp_get_dev_info_by_index(&info, i);

        bSame = mmi_a2dp_cmp_address(&(info.address), &(g_srv_a2dp_cntx.dev_info[index].address));
        if(bSame)
        {
            continue;
        }

        if(info.role == A2DP_ROLE_SINK)
        {
            //dialer, need reverse
            is_dialer = srv_bt_cm_is_bt_dialer(&(info.address));
            if(is_dialer)
            {
                g_srv_a2dp_cntx.dev_info[i].reverse_state = A2DP_REVERSE_STEP_CLOSE;
                mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[i]));
                
            }
        }
        else
        {
            continue;
        }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_pause_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_pause_cnf(void *message)
{
    bt_a2dp_stream_pause_cnf_struct *pMsg = NULL;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_pause_cnf_struct *)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_PAUSE_CNF, pMsg->result);
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (!bFound)
    {
        return;
    }

    if (A2DP_WAIT_PAUSE_CNF != g_srv_a2dp_cntx.dev_info[index].waitting)
    {
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
    }
    
    g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_OPEN;
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
        
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address), 
                        g_srv_a2dp_cntx.dev_info[index].user_callback, 
                        SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND);


        if(g_srv_a2dp_cntx.dev_info[index].is_reconfig == KAL_TRUE)
        {
            //reconfig
            mmi_a2dp_reconfig_req(&(g_srv_a2dp_cntx.dev_info[index]), &g_a2dp_reconfig_cfg);
        }
        else if(g_a2dp_delay_start == MMI_TRUE)
        {
            g_a2dp_delay_start = MMI_FALSE;
            mmi_a2dp_start_req(&(g_srv_a2dp_cntx.dev_info[index]));
        }
    }
    else
    {
        g_srv_a2dp_cntx.dev_info[index].is_reconfig = KAL_FALSE;
        g_a2dp_delay_start = MMI_FALSE;
    }

    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_pause_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_pause_ind(void *message)
{
    bt_a2dp_stream_pause_ind_struct *pMsg = NULL;
    S32 result = BT_A2DP_RESULT_BAD_STATE;
    kal_bool bFound = KAL_FALSE;
    kal_bool bSame = KAL_FALSE;
    MMI_BOOL is_dialer;
    U8 index = 0;
    U8 i = 0;
    a2dp_dev_info_struct info;

    pMsg = (bt_a2dp_stream_pause_ind_struct *)message;    
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (bFound)
    {
        result = BT_A2DP_RESULT_OK;
        btmtk_a2dp_send_stream_pause_res(pMsg->stream_handle, result);
        if (A2DP_STATE_STREAMING == g_srv_a2dp_cntx.dev_info[index].state)
        {
            g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_OPEN;
            if(!g_a2dp_streaming_interrupt)
            {
                mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
            }
            else
            {
                //open codec after SP1 pause, otherwise the sound will be mixed
                mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].audio_cfg),
                                    g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].stream_hdl,
                                    g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].role,
                                    MMI_TRUE);
            }
            mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address), 
                            g_srv_a2dp_cntx.dev_info[index].user_callback, 
                            SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND);
        }
    }
    else
    {
        btmtk_a2dp_send_stream_pause_res(pMsg->stream_handle, result);
    }
    
    g_a2dp_streaming_interrupt = MMI_FALSE;

    if(result == BT_A2DP_RESULT_BAD_STATE)
    {
        return;
    }

    //notify next sink to pause
    for(i = 0; i < MAX_A2DP_LINK_NUM; i++)
    {
        srv_a2dp_get_dev_info_by_index(&info, i);

        bSame = mmi_a2dp_cmp_address(&(info.address), &(g_srv_a2dp_cntx.dev_info[index].address));
        if(bSame)
        {
            continue;
        }

        if(info.role == A2DP_ROLE_SOURCE)
        {
            //next is dialer, need pause
            is_dialer = srv_bt_cm_is_bt_dialer(&(g_srv_a2dp_cntx.dev_info[i].address));
            if(is_dialer)
            {
                mmi_a2dp_pause_req(&(g_srv_a2dp_cntx.dev_info[i]));
            }
        }
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_close_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_close_cnf(void *message)
{
    bt_a2dp_stream_close_cnf_struct *pMsg = NULL;
    mmi_event_struct evt;
    A2DP_SRV_CALLBACK user_callback;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_close_cnf_struct*)message;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CLOSE_CNF, pMsg->result);

    if(g_a2dp_need_reopen)
    {
        #if !defined(__IOT__)
        cm_notify_callback = mmi_bt_dialor_callback;
        #endif
        mmi_a2dp_open_by_role(&g_a2dp_open_addr,
                                A2DP_ROLE_SINK, 
                                NULL,
                                MMI_FALSE);
        g_a2dp_need_reopen = MMI_FALSE;
        return;
    }

    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (!bFound)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, 
              MMI_TRC_A2DP_SRV_CLOSE_CNF_INFO,
              g_srv_a2dp_cntx.dev_info[index].state,
              g_srv_a2dp_cntx.dev_info[index].waitting,
              g_srv_a2dp_cntx.dev_info[index].reverse_state);

    if (A2DP_WAIT_CLOSE_CNF != g_srv_a2dp_cntx.dev_info[index].waitting)
    {
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
    }

    g_a2dp_streaming_interrupt = MMI_FALSE;
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {
        a2dp_state_enum global_state;
        srv_bt_cm_stop_conn(g_srv_a2dp_cntx.dev_info[index].cmgr_id);

        if(g_srv_a2dp_cntx.dev_info[index].reverse_state == A2DP_REVERSE_STEP_CLOSE)
        {
            S32 ret;
            memset(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg), 0x00, sizeof(bt_a2dp_audio_cap_struct));
            g_srv_a2dp_cntx.dev_info[index].role = A2DP_ROLE_NONE;
            g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_IDLE;
            g_srv_a2dp_cntx.dev_info[index].stream_hdl = UNKNOWN_STREAM_HANDLE;
            g_srv_a2dp_cntx.dev_info[index].cmgr_id = 0;
            g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
            g_srv_a2dp_cntx.dev_info[index].close_pending = KAL_FALSE;
    #if !defined(__IOT__)
            cm_notify_callback = mmi_bt_dialor_connect_a2dp_src_cb;
    #endif
            ret = mmi_a2dp_open_by_role(&(g_srv_a2dp_cntx.dev_info[index].address), 
                                        A2DP_ROLE_SOURCE, 
                                        g_srv_a2dp_cntx.dev_info[index].user_callback,
                                        MMI_FALSE);

            if(ret != SRV_A2DP_OPEN_FAILED)
            {
                g_srv_a2dp_cntx.dev_info[index].reverse_state = A2DP_REVERSE_STEP_OPEN;
                return;
            }
        }

        cm_notify_callback = g_srv_a2dp_cntx.dev_info[index].cm_callback;
        mmi_a2dp_notify_cm(&(g_srv_a2dp_cntx.dev_info[index].address),
                           MMI_TRUE, MMI_FALSE, MMI_FALSE, g_srv_a2dp_cntx.init_from_cm);
        
        user_callback = g_srv_a2dp_cntx.dev_info[index].user_callback;
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                        user_callback,
                        SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND);

        global_state = mmi_a2dp_global_state();
        if ((A2DP_STATE_IDLE == global_state) && (g_srv_a2dp_cntx.deactive_pending))
        {
            btmtk_a2dp_send_deactivate_req();
            g_srv_a2dp_cntx.deactive_pending = KAL_FALSE;
        }
        
        mmi_a2dp_enable_sco();
    #ifdef __MMI_BT_AUDIO_VIA_SCO__
        srv_a2dp_open_audio_via_sco();
    #endif
        mmi_a2dp_reset_dev_info(index);
    }
    else
    {
        g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
    }

    cm_notify_callback = NULL;

#if defined(__BT_SPEAKER_SUPPORT__)
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_A2DP_DISCONNECT);
    mmi_frm_cb_emit_post_event(&evt);
#endif

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_close_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_close_ind(void *message)
{
    bt_a2dp_stream_close_ind_struct *pMsg = NULL;
    A2DP_SRV_CALLBACK user_callback;
    mmi_event_struct evt;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CLOSE_IND);
    pMsg = (bt_a2dp_stream_close_ind_struct *)message;
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);

    //g_a2dp_cm_notify = MMI_TRUE;
    btmtk_a2dp_send_stream_close_res(pMsg->stream_handle, BT_A2DP_RESULT_OK);

    if (bFound)
    {
        a2dp_state_enum global_state;
        //set the state first
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_IDLE;
        srv_bt_cm_stop_conn(g_srv_a2dp_cntx.dev_info[index].cmgr_id);
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
        g_a2dp_streaming_interrupt = MMI_FALSE;

        user_callback = g_srv_a2dp_cntx.dev_info[index].user_callback;
        cm_notify_callback = g_srv_a2dp_cntx.dev_info[index].cm_callback;
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                        user_callback,
                        SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND);
        mmi_a2dp_notify_cm(&(g_srv_a2dp_cntx.dev_info[index].address),
                        MMI_TRUE, MMI_FALSE, MMI_TRUE, MMI_FALSE);

        global_state = mmi_a2dp_global_state();
        if ((A2DP_STATE_IDLE == global_state) && (g_srv_a2dp_cntx.deactive_pending))
        {
            btmtk_a2dp_send_deactivate_req();
            g_srv_a2dp_cntx.deactive_pending = KAL_FALSE;
        }
    }

    mmi_a2dp_enable_sco();
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_a2dp_open_audio_via_sco();
#endif
    mmi_a2dp_reset_dev_info(index);
    
    cm_notify_callback = NULL;
    
#if defined(__BT_SPEAKER_SUPPORT__)
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_A2DP_DISCONNECT);
    mmi_frm_cb_emit_post_event(&evt);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_abort_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_abort_cnf(void *message)
{
    bt_a2dp_stream_abort_cnf_struct *pMsg = NULL;
    A2DP_SRV_CALLBACK user_callback;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_abort_cnf_struct *)message;  
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (bFound)
    {
        //set the state first
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_ABORTING;
        user_callback = g_srv_a2dp_cntx.dev_info[index].user_callback;
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                        user_callback,
                        SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND);

        mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[index]));
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_abort_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_abort_ind(void *message)
{
    bt_a2dp_stream_abort_ind_struct *pMsg = NULL;
    A2DP_SRV_CALLBACK user_callback;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_abort_ind_struct *)message;
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);

    btmtk_a2dp_send_stream_abort_res(pMsg->stream_handle);
    if (bFound)
    {
        //set the state first
        g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_ABORTING;
        user_callback = g_srv_a2dp_cntx.dev_info[index].user_callback;

        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
        mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                        user_callback,
                        SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND);
    }
    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_reconfig_cnf
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_reconfig_cnf(void *message)
{
    bt_a2dp_stream_reconfig_cnf_struct *pMsg = NULL;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_reconfig_cnf_struct *)message;
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (!bFound)
    {
        return;
    }

    if (A2DP_WAIT_RECONFIG_CNF != g_srv_a2dp_cntx.dev_info[index].waitting)
    {
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
    }
    
    g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
    if (BT_A2DP_RESULT_OK == pMsg->result)
    {

        if(g_srv_a2dp_cntx.dev_info[index].is_reconfig == KAL_TRUE)
        {
            memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
                   &g_a2dp_reconfig_cfg,
                   sizeof(bt_a2dp_audio_cap_struct)); 
        }
        
        // temp test
        mmi_a2dp_start_req(&(g_srv_a2dp_cntx.dev_info[index]));
                
        if ((g_srv_a2dp_cntx.dev_info[index].reverse_state == A2DP_REVERSE_STEP_OPEN) &&
            g_srv_a2dp_cntx.dev_info[index].waitting == A2DP_WAIT_NONE)
        {
            g_srv_a2dp_cntx.dev_info[index].reverse_state = A2DP_REVERSE_STEP_STREAMING;
        }
    }
    else
    {
        mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[index]));
    }
    
    return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_reconfig_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_stream_reconfig_ind(void *message)
{
    bt_a2dp_stream_reconfig_ind_struct *pMsg = NULL;
    S32 result = BT_A2DP_RESULT_BAD_STATE;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    pMsg = (bt_a2dp_stream_reconfig_ind_struct *)message;
    bFound = mmi_a2dp_quiry_by_handle(pMsg->stream_handle, &index);
    if (bFound)
    { 
        if (A2DP_STATE_OPEN == g_srv_a2dp_cntx.dev_info[index].state)
        {
            result = BT_A2DP_RESULT_OK;
        }

        memcpy(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
               &(pMsg->audio_cap),
               sizeof(bt_a2dp_audio_cap_struct));

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CONFIG_AUDIO_CAP, g_srv_a2dp_cntx.dev_info[index].audio_cfg.codec_type);
    }
    
    btmtk_a2dp_send_stream_reconfig_res(pMsg->stream_handle, result);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_start_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void mmi_a2dp_stream_start_sink_codec_req(U8 stream_handle)
{
    btmtk_a2dp_send_stream_start_sink_codec_req(stream_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_stream_stop_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void mmi_a2dp_stream_stop_sink_codec_req(U8 stream_handle)
{
    btmtk_a2dp_send_stream_stop_sink_codec_req(stream_handle);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_aud_sink_codec_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_aud_sink_codec_ind(void *msg)
{
    U8 i = 0;
    U8 index = 0;
    kal_bool bStream = KAL_FALSE;
    media_bt_sink_codec_ind_struct *pMsg = NULL;
    pMsg = (media_bt_sink_codec_ind_struct*)msg;

    
    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {
        if ((g_srv_a2dp_cntx.dev_info[i].role == BT_A2DP_SINK) &&
            (g_srv_a2dp_cntx.dev_info[i].state == A2DP_STATE_STREAMING))
        {
            index = i;
            bStream = KAL_TRUE;
        }
    }

    if(!bStream)
    {
        return;
    }

    if((pMsg->events == MEDIA_ERROR) && (pMsg->stream_handle == g_srv_a2dp_cntx.dev_info[index].stream_hdl))
    {
        mmi_a2dp_stream_stop_sink_codec_req(g_srv_a2dp_cntx.dev_info[index].stream_hdl);
        mmi_a2dp_stream_start_sink_codec_req(g_srv_a2dp_cntx.dev_info[index].stream_hdl);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_aud_close_codec_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_aud_close_codec_ind(void *msg)
{
    media_bt_close_codec_ind_struct *pMsg = NULL;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CODEC_CLOSE_IND, g_srv_a2dp_cntx.codec_opened);
    pMsg = (media_bt_close_codec_ind_struct*)msg;
    if ((g_srv_a2dp_cntx.codec_opened != A2DP_CODEC_NONE)
        && (pMsg->seq_no == g_srv_a2dp_cntx.codec_seq_no))
    {
        g_srv_a2dp_cntx.codec_opened = A2DP_CODEC_NONE;
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_start_req(a2dp_dev_info_struct *dev_info)
{
    if (!dev_info)
    {
        return;
    }
    
    StopTimer(AV_BT_DELAY_PAUSE_TIMER);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_START_REQ, dev_info->state);

    if(dev_info->waitting != A2DP_WAIT_NONE)
    {
        if(dev_info->waitting == A2DP_WAIT_PAUSE_CNF)
        {
            g_a2dp_delay_start = MMI_TRUE;
        }
        return;
    }
    else if (dev_info->state != A2DP_STATE_OPEN)
    {
        if(dev_info->state == A2DP_STATE_STREAMING)
        {
            //MAUI_03500521
            mmi_a2dp_close_codec(dev_info->role);
            //MAUI_03499656
            mmi_a2dp_open_codec(&(dev_info->audio_cfg),
                                dev_info->stream_hdl,
                                dev_info->role,
                                MMI_TRUE);
            mmi_a2dp_notify(&(dev_info->address),
                            dev_info->user_callback,
                            SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
        }
        return;
    }

    mmi_a2dp_open_codec(&(dev_info->audio_cfg),
                        dev_info->stream_hdl,
                        dev_info->role,
                        MMI_TRUE);

    dev_info->waitting = A2DP_WAIT_START_CNF;
    btmtk_a2dp_send_stream_start_req(dev_info->stream_hdl);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_pause_req(a2dp_dev_info_struct *dev_info)
{
    if (!dev_info)
    {
        return;
    }
    
    if (dev_info->state != A2DP_STATE_STREAMING)
    {
        return;
    }
    else if(dev_info->waitting != A2DP_WAIT_NONE)
    {
        return;
    }

    dev_info->waitting = A2DP_WAIT_PAUSE_CNF;
    btmtk_a2dp_send_stream_pause_req(dev_info->stream_hdl);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_abort_req(a2dp_dev_info_struct *dev_info)
{
    if (!dev_info)
    {
        return;
    }
    
    if (dev_info->state == A2DP_STATE_IDLE)
    {
        return;
    }
    else if (dev_info->waitting != A2DP_WAIT_NONE)
    {
        return;
    }

    dev_info->waitting = A2DP_WAIT_ABORT_CNF;
    btmtk_a2dp_send_stream_abort_req(dev_info->stream_hdl);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_reconfig_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_reconfig_req(a2dp_dev_info_struct *dev_info, bt_a2dp_audio_cap_struct *audio_cap)
{
    if (!dev_info || !audio_cap)
    {
        return;
    }

    if(dev_info->waitting != A2DP_WAIT_NONE)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_RECONFIG_REQ, dev_info->state);
    if (A2DP_STATE_OPEN == dev_info->state)
    {
        dev_info->waitting = A2DP_WAIT_RECONFIG_CNF;
        btmtk_a2dp_send_stream_reconfig_req(dev_info->stream_hdl, audio_cap);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_close_req(a2dp_dev_info_struct *dev_info)
{
    kal_bool close_codec = KAL_TRUE;

    if (!dev_info)
    {
        return;
    }

    if(dev_info->reverse_state == A2DP_REVERSE_STEP_CLOSE)
    {
        close_codec = KAL_FALSE;
    }
    
    if (A2DP_STATE_IDLE == dev_info->state)
    {
    #if defined(__BT_SPEAKER_SUPPORT__)
        mmi_event_struct evt;
        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_A2DP_DISCONNECT);
        mmi_frm_cb_emit_post_event(&evt);
    #endif
        return;
    }

    if (A2DP_WAIT_NONE != dev_info->waitting)
    {
        if (A2DP_WAIT_DISCONNECT_CNF != dev_info->waitting)
        {
            dev_info->close_pending = KAL_TRUE;
        }
        return;
    }

    mdi_audio_set_pseudo_play_file_callback(NULL, NULL);

    if(close_codec)
    {
        mmi_a2dp_close_codec(dev_info->role);
    }

    dev_info->close_pending = KAL_FALSE;
    dev_info->waitting = A2DP_WAIT_CLOSE_CNF;
    btmtk_a2dp_send_stream_close_req(dev_info->stream_hdl);
}




/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_app_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static mmi_ret mmi_a2dp_app_callback(mmi_event_struct *param)
{
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;
    a2dp_app_notify_struct *dev = param->user_data;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_APP, dev->evt);
    //if(dev->func != NULL)
    //{
        //dev->func(dev->address, dev->evt);
    //}

    if(g_a2dp_stream_stop == MMI_TRUE)
    {
        g_a2dp_stream_stop = MMI_FALSE;
        return;
    }

    bFound = mmi_a2dp_quiry_by_address(&(dev->address), &index);

    if(bFound && (g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SOURCE))
    {
        if(g_srv_a2dp_cntx.media_callback != NULL)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_APP, -1);
            g_srv_a2dp_cntx.media_callback(&(dev->address), dev->evt);
        }
        else if(g_srv_a2dp_cntx.default_callback != NULL)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_APP, -2);
            g_srv_a2dp_cntx.default_callback(&(dev->address), dev->evt);
        }
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_delay_open_callback_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void mmi_a2dp_delay_open_callback_hdlr()
{
    U16 index = g_delay_callback_index;
    
    mmi_a2dp_notify((srv_bt_cm_bt_addr*)(&g_srv_a2dp_cntx.dev_info[index].address),
                    g_srv_a2dp_cntx.dev_info[index].user_callback,
                    SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_notify
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static a2dp_app_notify_struct ctx;

static void mmi_a2dp_notify(srv_bt_cm_bt_addr *address,
                            A2DP_SRV_CALLBACK notify_func, 
                            srv_a2dp_callback_event_enum event)
{
    mmi_event_struct evt;

    if (!address)
    {
        return;
    }

    //notify_func may be a temp param
    if(notify_func != NULL)
    {
        notify_func(address, event);
    }
    
    memcpy(&ctx.address, address, sizeof(srv_bt_cm_bt_addr));
    ctx.func = NULL;
    ctx.evt = event;

    //use post event
    evt.evt_id = 0;
    evt.user_data = (void*)&ctx;
    evt.size = sizeof(mmi_event_struct);

    mmi_frm_post_event(&evt, mmi_a2dp_app_callback, (void*)&ctx);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_notify_cm
 * DESCRIPTION
 *  notify CM app a2dp connected or disconnected
 * PARAMETERS
 *  address       [IN]   device address
 *  result        [IN]   result: success or failed
 *  is_connect    [IN]   connected or disconnected
 *  is_indicate   [IN]   
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_a2dp_notify_cm(srv_bt_cm_bt_addr *address,
                                MMI_BOOL result,
                                MMI_BOOL is_connect,
                                MMI_BOOL is_indicate,
                                MMI_BOOL match_cm_req)
{
    //a2dp_role_enum role;
    MMI_BOOL ind_back_to_cm = is_indicate;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_CM_BEGIN, address->lap, address->nap, address->uap);

    if ((!address) || (!cm_notify_callback))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_CM_END, -1, 0, 0);
        return;
    }

    // music app connection: ind 0, cm_req 0 ==> ind 1 for cm cb
    // cm app connection: ind 0, cm_req 1 ==> ind 0 for cm cb, and then clear init_from_cm
    // passive connection: ind 1, cm_req 0 ==> ind 1 for cm cb
    // invalid case: ind 1, cm_req 1 ==> 
    if (is_indicate == MMI_FALSE && match_cm_req == MMI_FALSE)
    {
        ind_back_to_cm = MMI_TRUE;
    }
    if (match_cm_req)
    {
        g_srv_a2dp_cntx.init_from_cm = MMI_FALSE;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_NOTIFY_CM_END, result, is_connect, is_indicate);
    cm_notify_callback(address, SRV_BT_CM_A2DP_CONNECTION, result, is_connect, ind_back_to_cm);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_send_avrcp_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_send_avrcp_cmd(S32 cmd_frame)
{
    U8 index;
    kal_bool ret;

    ret = srv_a2dp_quiry_by_role(A2DP_ROLE_SINK, &index);
    if(ret == KAL_TRUE)
    {
    #ifdef __MMI_AVRCP_SUPPORT__
        srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[index].address), cmd_frame);
    #endif
    }
}


// audio-sync begin
/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_check_audio_sync
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_check_audio_sync(void)
{
    kal_bool found_src = KAL_FALSE;
    kal_bool found_sink = KAL_FALSE;
    kal_bool dialer_src = KAL_FALSE;
    kal_bool dialer_sink = KAL_FALSE;
    kal_bool sync = KAL_FALSE;
    U8 index_src = 0;
    U8 index_sink = 0;
    U8 dialer_index = BT_A2DP_DIALER_MAX;

    found_sink = srv_a2dp_quiry_by_role(A2DP_ROLE_SINK, &index_sink);
    found_src = srv_a2dp_quiry_by_role(A2DP_ROLE_SOURCE, &index_src);
    if (found_sink && found_src)
    {
        dialer_sink = srv_bt_cm_is_bt_dialer(&(g_srv_a2dp_cntx.dev_info[index_sink].address));
        dialer_src = srv_bt_cm_is_bt_dialer(&(g_srv_a2dp_cntx.dev_info[index_src].address));
        if ((!dialer_sink) && dialer_src)
        {
            sync = KAL_TRUE;
            dialer_index = BT_A2DP_DIALER_1;
        }
    }
    else if (found_sink && (!found_src))
    {
        dialer_sink = srv_bt_cm_is_bt_dialer(&(g_srv_a2dp_cntx.dev_info[index_sink].address));
        if (dialer_sink)
        {
            sync = KAL_TRUE;
            dialer_index = BT_A2DP_DIALER_2;
        }
    }
    
    btmtk_a2dp_send_stream_sync_req(sync, dialer_index);
}
// audio-sync end

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_transfer_data
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_transfer_data(void)
{
    kal_bool bSame = KAL_FALSE;
    kal_bool found_src = KAL_FALSE;
    kal_bool found_sink = KAL_FALSE;
    MMI_BOOL is_dialer;
    U8 src_index = 0;
    U8 sink_index = 0;

    found_src = srv_a2dp_quiry_by_role(A2DP_ROLE_SOURCE, &src_index);
    found_sink = srv_a2dp_quiry_by_role(A2DP_ROLE_SINK, &sink_index);
    if (!found_sink || !found_src)
    {
        return;
    }

    is_dialer = srv_bt_cm_is_bt_dialer(&(g_srv_a2dp_cntx.dev_info[src_index].address));
    if (!is_dialer) // check if source SEP is Dialer
    {
        return;
    }

    if (!(A2DP_STATE_OPEN == g_srv_a2dp_cntx.dev_info[src_index].state)
        || !(A2DP_STATE_STREAMING == g_srv_a2dp_cntx.dev_info[sink_index].state))
    {
        return;
    }

    bSame = mmi_a2dp_cmp_aud_cfg(&(g_srv_a2dp_cntx.dev_info[src_index].audio_cfg),
                                 &(g_srv_a2dp_cntx.dev_info[sink_index].audio_cfg));
    if (bSame && (g_srv_a2dp_cntx.dev_info[src_index].state == A2DP_STATE_OPEN))
    {
        mmi_a2dp_start_req(&(g_srv_a2dp_cntx.dev_info[src_index]));
    }
    else
    {
        mmi_a2dp_reconfig_req(&(g_srv_a2dp_cntx.dev_info[src_index]), 
                              &(g_srv_a2dp_cntx.dev_info[sink_index].audio_cfg));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_connect_avrcp_cb
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  A2DP_SRV_CALLBACK
 *****************************************************************************/ 

#ifdef __MMI_AVRCP_SUPPORT__
static void mmi_a2dp_connect_avrcp_cb(srv_bt_cm_bt_addr *address, 
                                      srv_avrcp_connectivity_notify_result evt)
{
#ifdef __MMI_AVRCP_SUPPORT__
    srv_a2dp_callback_event_enum result;
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_AVRCP_CB, evt);
    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        return;
    }

    if ((SRV_AVRCP_CONNECTIVITY_CONNECTED == evt)
        && (g_srv_a2dp_cntx.dev_info[index].state > A2DP_STATE_IDLE))
    {
        result = SRV_A2DP_CALLBACK_EVENT_OPEN_OK;
    }
    else
    {
        result = SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED;
    }

    mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[index].address),
                    g_srv_a2dp_cntx.dev_info[index].user_callback,
                    result);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_connect_avrcp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_connect_avrcp(srv_bt_cm_bt_addr address, a2dp_role_enum role)
{
#ifndef __MMI_AVRCP_SUPPORT__
    return;
#endif

#ifdef __MMI_EM_BT_AVRCP_CONNECT_TG_ACTIVELY__
#ifndef __BT_SPEAKER_SUPPORT__
    if(srv_avrcp_get_actively_connect_tg_flag())
    {
        srv_avrcp_connect_tg_req(&address);
    }
#endif
#else
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CONNECT_AVRCP, role);
    if(A2DP_ROLE_SINK == role)
    {
        srv_avrcp_connect_ct_req_from_a2dp((srv_bt_cm_bt_addr*)&address, mmi_a2dp_connect_avrcp_cb);
    }
    else if(A2DP_ROLE_SOURCE == role)
    {
        srv_avrcp_connect_tg_req_from_a2dp((srv_bt_cm_bt_addr*)&address, mmi_a2dp_connect_avrcp_cb);
    }
    
    srv_avrcp_set_role((srv_bt_cm_bt_addr*)&address, role);
#endif
}

#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_open_codec
 * DESCRIPTION
 *  role, it is the connect addr role
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void mmi_a2dp_open_codec(bt_a2dp_audio_cap_struct *cfg,
                                kal_uint8 stream_handle,
                                a2dp_role_enum role,
                                kal_bool immediate)
{

    kal_uint32 seq_no = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPEN_CODEC, role, g_srv_a2dp_cntx.codec_opened);
    if (g_srv_a2dp_cntx.codec_opened != A2DP_CODEC_NONE || role == A2DP_ROLE_NONE)
    {
        return;
    }

    seq_no = g_srv_a2dp_cntx.codec_seq_no;
    if (A2DP_ROLE_SOURCE == role)
    {
        aud_send_bt_open_codec_req(MOD_MMI,cfg,stream_handle,immediate,seq_no);
        g_srv_a2dp_cntx.codec_opened = A2DP_CODEC_SRC;
    }
    else
    {
        
        #if defined(__MMI_BT_MUSIC_NOLCD__)
		{
    #ifdef __KARAOKE_SUPPORT__
			extern MMI_BOOL mmi_bt_music_nolcd_is_karaoke_enable(void);
    #endif
			extern void mmi_bt_music_nolcd_interrupt_callback(S32 result, void *user_data);
			void mmi_bt_music_nolcd_send_avrcp_cmd(S32 cmd);
			extern kal_bool g_pause_btmusic_for_notify;
			extern MMI_BOOL g_is_wait_for_notify;
			if(g_is_wait_for_notify)
			{
				mmi_bt_music_nolcd_send_avrcp_cmd(SRV_AVRCP_POP_PAUSE);
				g_pause_btmusic_for_notify=MMI_TRUE;
				return;
			}
			#ifdef __KARAOKE_SUPPORT__
			if(mmi_bt_music_nolcd_is_karaoke_enable())
			{
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_PLAY_MIX_ONLY,NULL);
			}
			#endif
		}
        #endif
        srv_bt_cm_set_btdialor_mode(MMI_TRUE);
        mdi_audio_terminate_background_play();
        mdi_bt_speaker_power_on();
        aud_send_bt_open_sink_codec_req(MOD_MMI,cfg,stream_handle,immediate,seq_no);
        g_srv_a2dp_cntx.codec_opened = A2DP_CODEC_SINK;
    #if (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__))
        mdi_audio_register_interrupt_callback(mmi_bt_sepaker_power_off, NULL);
        mmi_btspeaker_set_volume_handler();
    #endif
	    
        #if defined(__MMI_BT_MUSIC_NOLCD__)
		mdi_audio_register_interrupt_callback(mmi_bt_music_nolcd_interrupt_callback,NULL);
        #endif
    }
    
    g_srv_a2dp_cntx.codec_seq_no ++;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_close_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void mmi_a2dp_close_codec(a2dp_role_enum role)
{
    MMI_BOOL in_call = MMI_FALSE;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CLOSE_CODEC, role, g_srv_a2dp_cntx.codec_opened);
    if (g_srv_a2dp_cntx.codec_opened == A2DP_CODEC_NONE)
    {
        return;
    }

    if (A2DP_ROLE_SOURCE == role)
    {
        aud_send_bt_close_codec_req(MOD_MMI);
    }
    else 
    {
        aud_send_bt_close_sink_codec_req(MOD_MMI);

        mdi_bt_speaker_power_off();
        mdi_audio_clear_interrupt_callback();
		
        #if defined(__MMI_BT_MUSIC_NOLCD__)
		{
			#ifdef __KARAOKE_SUPPORT__
			extern MMI_BOOL mmi_bt_music_nolcd_is_karaoke_enable(void);
			if(mmi_bt_music_nolcd_is_karaoke_enable())
			{
				mdi_audio_set_karaoke_mode(MEDIA_KARAPLAY_MIX_NONE,NULL);
			}
			#endif
		}
        #endif
    }
    
    g_srv_a2dp_cntx.codec_opened = A2DP_CODEC_NONE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_global_state
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static a2dp_state_enum mmi_a2dp_global_state(void)
{
    a2dp_state_enum global_state = A2DP_STATE_IDLE;
    U8 index = 0;
    
    for (index=0; index<MAX_A2DP_LINK_NUM; index++)
    {
        if (g_srv_a2dp_cntx.dev_info[index].state > global_state)
        {
            global_state = g_srv_a2dp_cntx.dev_info[index].state;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GLOBAL_STATE, global_state);
    return global_state;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_reset_dev_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void mmi_a2dp_reset_dev_info(U8 index)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_RESET_DEV, index);

    memset(&(g_srv_a2dp_cntx.dev_info[index].address), 0x00, sizeof(srv_bt_cm_bt_addr));
    memset(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg), 0x00, sizeof(bt_a2dp_audio_cap_struct));
    g_srv_a2dp_cntx.dev_info[index].role = A2DP_ROLE_NONE;
    g_srv_a2dp_cntx.dev_info[index].state = A2DP_STATE_IDLE;
    g_srv_a2dp_cntx.dev_info[index].stream_hdl = UNKNOWN_STREAM_HANDLE;
    g_srv_a2dp_cntx.dev_info[index].cmgr_id = 0;
    g_srv_a2dp_cntx.dev_info[index].user_callback = NULL;
    //g_srv_a2dp_cntx.dev_info[index].cm_callback = NULL;
    g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_NONE;
    g_srv_a2dp_cntx.dev_info[index].close_pending = KAL_FALSE;
    g_srv_a2dp_cntx.dev_info[index].reverse_state = A2DP_REVERSE_STEP_NONE;
    g_srv_a2dp_cntx.dev_info[index].is_connect_avrcp = KAL_FALSE;
    g_srv_a2dp_cntx.dev_info[index].is_reconfig = KAL_FALSE;
    g_srv_a2dp_cntx.dev_info[index].is_open_req = KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_reset_ctx
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static void mmi_a2dp_reset_ctx(void)
{
    U8 i = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_RESET_CTX);
    for (i=0; i<MAX_A2DP_LINK_NUM; i++)
    {
        mmi_a2dp_reset_dev_info(i);
    }

    g_srv_a2dp_cntx.ctx_actived = KAL_FALSE;
    g_srv_a2dp_cntx.deactive_pending = KAL_FALSE;
    g_srv_a2dp_cntx.codec_opened = A2DP_CODEC_NONE;
    g_srv_a2dp_cntx.codec_seq_no = 0;
    g_srv_a2dp_cntx.need_reconfig = KAL_FALSE;
    g_srv_a2dp_cntx.default_callback = NULL;
    g_srv_a2dp_cntx.media_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_cmp_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_addr1    [IN]
 *  bt_addr2    [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool mmi_a2dp_cmp_address(srv_bt_cm_bt_addr *bt_addr1, srv_bt_cm_bt_addr *bt_addr2)
{
    if (!bt_addr1 || !bt_addr2)
    {
        return KAL_FALSE;
    }

    if (((bt_addr1->lap & 0x00FFFFFF) == (bt_addr2->lap & 0x00FFFFFF))
        && (bt_addr1->uap == bt_addr2->uap)
        && (bt_addr1->nap == bt_addr2->nap))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CMP_ADDRESS, KAL_TRUE);
        return KAL_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CMP_ADDRESS, KAL_FALSE);
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_quiry_streaming_dev
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_a2dp_quiry_streaming_dev(U8 *pIndex)
{
    U8 i = 0;

    for (i=0; i<MAX_A2DP_LINK_NUM; i++)
    {
        if (A2DP_STATE_STREAMING == g_srv_a2dp_cntx.dev_info[i].state)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_STREAMING, i);
            *pIndex = i;
            return KAL_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_STREAMING, -1);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_quiry_by_handle
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_a2dp_quiry_by_handle(U8 stream_hdl, U8 *pIndex)
{
    U8 i = 0;

    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {
        if (stream_hdl == g_srv_a2dp_cntx.dev_info[i].stream_hdl)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_HANDLE, i);
            *pIndex = i;
            return KAL_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_HANDLE, -1);
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_quiry_by_address
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_a2dp_quiry_by_address(srv_bt_cm_bt_addr *address, U8 *pIndex)
{
    kal_bool bFound = KAL_FALSE;
    U8 i = 0;

    if (!address)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ADDRESS, -1);
        return KAL_FALSE;
    }

    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {

        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_ADDRESS, g_srv_a2dp_cntx.dev_info[i].address.lap, g_srv_a2dp_cntx.dev_info[i].address.nap, g_srv_a2dp_cntx.dev_info[i].address.uap, __LINE__);
    
        bFound = mmi_a2dp_cmp_address(address, &(g_srv_a2dp_cntx.dev_info[i].address));
        if (bFound)
        {
            if (pIndex)
            {
                *pIndex = i;
            }

            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ADDRESS, i);
            return KAL_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ADDRESS, -2);
    return KAL_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_alloc_resource
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static kal_bool mmi_a2dp_alloc_resource(srv_bt_cm_bt_addr *address, a2dp_role_enum local_role, U8 *pIndex)
{
    U8 i = 0;
    U8 j = 0;
    U8 sep_num = MAX_A2DP_LINK_NUM;
    U8 src_num = MAX_A2DP_SRC_LINK_NUM;
    U8 sink_num = MAX_A2DP_SNK_LINK_NUM;
    kal_bool bSame = KAL_FALSE;
    a2dp_dev_info_struct info;

    //check whether there is dummy resource
    for(i=0; i<sep_num; i++)
    {
        if((g_srv_a2dp_cntx.dev_info[i].state == A2DP_STATE_IDLE) &&
            (g_srv_a2dp_cntx.dev_info[i].waitting == A2DP_WAIT_NONE))
        {
            mmi_a2dp_reset_dev_info(i);
        }
    }

    for (i=0; i<sep_num; i++)
    {
        srv_a2dp_get_dev_info_by_index(&info, i);

        //if be the same addr, need reverse the role
        bSame = mmi_a2dp_cmp_address(&(info.address), address);
        if(bSame)
        {
            g_srv_a2dp_cntx.dev_info[i].role = local_role;
            j = i;
            *pIndex = i;
            break;
        }
    }
    
    for (i=0; i<sep_num; i++)
    {
        srv_a2dp_get_dev_info_by_index(&info, i);
        
        if(info.role == A2DP_ROLE_SOURCE)
        {
            src_num--;
        }
        else if(info.role == A2DP_ROLE_SINK)
        {
            sink_num--;
        }
        else if((j == 0) && (!bSame))
        {
            if((local_role == A2DP_ROLE_SOURCE) && (src_num <= 0))
            {
                return KAL_FALSE;
            }
            if((local_role == A2DP_ROLE_SINK) && (sink_num <= 0))
            {
                return KAL_FALSE;
            }
            
            *pIndex = i;
            return KAL_TRUE;
        }

        if((src_num >= 0) || (sink_num >= 0))
        {
            continue;
        }

        if((local_role == A2DP_ROLE_SOURCE) && (src_num < 0))
        {
            return KAL_FALSE;
        }
        if((local_role == A2DP_ROLE_SINK) && (sink_num < 0))
        {
            return KAL_FALSE;
        }
        
    }

    if(bSame)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }

}

static kal_bool mmi_a2dp_connect_sco_check(void)
{
    a2dp_state_enum state;
    kal_bool is_connected = KAL_FALSE;
    U8 index = 0;

    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        state = g_srv_a2dp_cntx.dev_info[index].state;
        is_connected = ((state >= A2DP_STATE_OPEN) ? KAL_TRUE : KAL_FALSE );
        if((is_connected) && (g_srv_a2dp_cntx.dev_info[index].role == BT_A2DP_SINK))
        {
            return KAL_FALSE;
        }
    }

    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_enable_sco
 * DESCRIPTION
 *  
 * PARAMETERS
 *  immediate      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_a2dp_enable_sco(void)
{
    if(srv_a2dp_is_streaming())
    {
        return;
    }

#ifdef __MMI_BT_AUDIO_VIA_SCO__
    srv_btsco_enable_sco_connection(SRV_BT_SCO_INT_A2DP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_disable_sco
 * DESCRIPTION
 *  
 * PARAMETERS
 *  immediate      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_a2dp_disable_sco(void)
{
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    /* Disconnect SCO if connect to A2DP */
    srv_btsco_disable_sco_connection(SRV_BT_SCO_INT_A2DP);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_a2dp_open_by_role
 * DESCRIPTION
 *  open A2DP connection by address, the role be defined by user
 * PARAMETERS
 *  address            [IN]
 *  cb_func            [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
static S32 mmi_a2dp_open_by_role(srv_bt_cm_bt_addr *address, 
                                 a2dp_role_enum local_role, 
                                 A2DP_SRV_CALLBACK cb_func,
                                 MMI_BOOL connect_avrcp)
{
    kal_bool bFound;
    U8 index = 0;
    S32 cmgr_id;
    srv_bt_cm_bt_addr open_address;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPEN_BY_ROLE, local_role);


    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_ADDRESS, address->lap, address->nap, address->uap, __LINE__);
    //the address maybe a insex can be reset, so copy to open_adress
    memcpy(&open_address, address, sizeof(srv_bt_cm_bt_addr));

    bFound = mmi_a2dp_quiry_by_address(&open_address, &index);
    if (bFound)
    {
        if(cb_func)
        {
            g_srv_a2dp_cntx.dev_info[index].user_callback = cb_func;
        }
        
        MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].state);
        if (g_srv_a2dp_cntx.dev_info[index].state >= A2DP_STATE_OPEN)
        {
            if (local_role == A2DP_ROLE_SINK && connect_avrcp)
            {
                g_srv_a2dp_cntx.dev_info[index].is_connect_avrcp = KAL_FALSE;
            #ifdef __MMI_AVRCP_SUPPORT__
                mmi_a2dp_connect_avrcp(g_srv_a2dp_cntx.dev_info[index].address,
                                           g_srv_a2dp_cntx.dev_info[index].role);
            #endif
            }
            else
            {
                mmi_a2dp_notify((srv_bt_cm_bt_addr*)&open_address,
                            g_srv_a2dp_cntx.dev_info[index].user_callback,
                            SRV_A2DP_CALLBACK_EVENT_OPEN_OK);
            }
            return SRV_A2DP_OPEN_DONE;
        }
        if(g_srv_a2dp_cntx.dev_info[index].waitting != A2DP_WAIT_NONE)
        {
            MMI_A2DP_MESSAGE_TRANS(g_srv_a2dp_cntx.dev_info[index].waitting);
            mmi_a2dp_notify((srv_bt_cm_bt_addr*)&open_address,
                            g_srv_a2dp_cntx.dev_info[index].user_callback,
                            SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);

            return SRV_A2DP_OPEN_FAILED;
        }
    }

    bFound = mmi_a2dp_alloc_resource(&open_address, local_role, &index);
    if (!bFound)
    {
        mmi_a2dp_notify((srv_bt_cm_bt_addr*)&open_address,
                        g_srv_a2dp_cntx.dev_info[index].user_callback,
                        SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);

        return SRV_A2DP_OPEN_FAILED;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_ALLOC_INDEX, index);

    cmgr_id = srv_bt_cm_start_conn(MMI_FALSE, SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID, (srv_bt_cm_bt_addr *)&open_address, NULL);
    mmi_a2dp_reset_dev_info(index);
    if(cmgr_id < 0)
    {
        mmi_a2dp_notify((srv_bt_cm_bt_addr*)&open_address,
                        g_srv_a2dp_cntx.dev_info[index].user_callback,
                        SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);

        return SRV_A2DP_OPEN_FAILED;
    }
    
    memcpy(&(g_srv_a2dp_cntx.dev_info[index].address), &open_address, sizeof(srv_bt_cm_bt_addr));
    g_srv_a2dp_cntx.dev_info[index].role = local_role;
    g_srv_a2dp_cntx.dev_info[index].cmgr_id = cmgr_id;
    g_srv_a2dp_cntx.dev_info[index].user_callback = cb_func;
    g_srv_a2dp_cntx.dev_info[index].waitting = A2DP_WAIT_OPEN_CNF;
    g_srv_a2dp_cntx.dev_info[index].is_connect_avrcp = connect_avrcp;
    g_srv_a2dp_cntx.dev_info[index].cm_callback = cm_notify_callback;
    btmtk_a2dp_send_stream_open_req((bt_addr_struct*)&open_address, local_role);
    return SRV_A2DP_OPEN_WAITING;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_quiry_by_role
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool srv_a2dp_quiry_by_role(a2dp_role_enum role, U8 *pIndex)
{
    U8 i = 0;

    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {
        if (role == g_srv_a2dp_cntx.dev_info[i].role)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ROLE, i);
            *pIndex = i;
            return KAL_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ROLE, -1);
    return KAL_FALSE;
}


kal_bool srv_a2dp_quiry_by_role_ex(a2dp_role_enum role, srv_bt_cm_bt_addr *address)
{
    U8 i = 0;

    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {
        if (role == g_srv_a2dp_cntx.dev_info[i].role)
        {
            address = &(g_srv_a2dp_cntx.dev_info[i].address);
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_ADDRESS, g_srv_a2dp_cntx.dev_info[i].address.lap, g_srv_a2dp_cntx.dev_info[i].address.nap, g_srv_a2dp_cntx.dev_info[i].address.uap, __LINE__);
            return KAL_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_QUIRY_BY_ROLE, -2);
    return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  immediate      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_open_codec(MMI_BOOL immediate)
{
    MMI_BOOL bFound = MMI_FALSE;
    U8 index = 0;

    bFound = mmi_a2dp_quiry_streaming_dev(&index);
    if (bFound)
    {
        mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg),
                            g_srv_a2dp_cntx.dev_info[index].stream_hdl,
                            g_srv_a2dp_cntx.dev_info[index].role,
                            immediate);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_codec
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_close_codec(void)
{
    MMI_BOOL bFound = MMI_FALSE;
    U8 index = 0;

    bFound = mmi_a2dp_quiry_streaming_dev(&index);
    if (bFound)
    {
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_src_cm_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_src_cm_connect_req(srv_bt_cm_bt_addr *dev_addr, 
                                    srv_bt_a2dp_cm_connect_notify srv_cm_cb)
{
    S32 ret;

    //if (srv_cm_cb != NULL)
    {
        cm_notify_callback = srv_cm_cb;
        //g_a2dp_cm_notify = MMI_TRUE;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CM_CONNECT_SRC);
    //cm not use app callback, so set NULL
    g_srv_a2dp_cntx.init_from_cm = MMI_TRUE;
    ret = mmi_a2dp_open_by_role(dev_addr, A2DP_ROLE_SOURCE, NULL, MMI_FALSE);
    if(ret != SRV_A2DP_OPEN_WAITING)
    {
        MMI_BOOL result = (ret == SRV_A2DP_OPEN_DONE);
        mmi_a2dp_notify_cm(dev_addr, result, MMI_TRUE, MMI_FALSE, MMI_TRUE);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_sink_cm_connect_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_sink_cm_connect_req(srv_bt_cm_bt_addr *dev_addr, 
                                     srv_bt_a2dp_cm_connect_notify srv_cm_cb)
{
    S32 ret;

    //if (srv_cm_cb != NULL)
    {
        cm_notify_callback = srv_cm_cb;
        //g_a2dp_cm_notify = MMI_TRUE;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CM_CONNECT_SINK);
    //cm not use app callback, so set NULL
    g_srv_a2dp_cntx.init_from_cm = MMI_TRUE;
    ret = mmi_a2dp_open_by_role(dev_addr, A2DP_ROLE_SINK, NULL, MMI_FALSE);

    if(ret != SRV_A2DP_OPEN_WAITING)
    {
        MMI_BOOL result = (ret == SRV_A2DP_OPEN_DONE);
        mmi_a2dp_notify_cm(dev_addr, result, MMI_TRUE, MMI_FALSE, MMI_TRUE);
    }
}


void srv_bt_a2dp_cm_disconnect_req(srv_bt_cm_bt_addr *dev_addr, 
                                   srv_bt_a2dp_cm_connect_notify srv_cm_cb)
{
    S32 result;

    //if (srv_cm_cb != NULL)
    {
        cm_notify_callback = srv_cm_cb;
        //g_a2dp_cm_notify = MMI_TRUE;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_CM_DISCONNECT);
    g_srv_a2dp_cntx.init_from_cm = MMI_TRUE;
    result = srv_a2dp_close_ex(dev_addr);

    if(result != SRV_A2DP_CLOSE_WAITING)
    {
        MMI_BOOL status = (result == SRV_A2DP_CLOSE_DONE);
        mmi_a2dp_notify_cm(dev_addr, status, MMI_FALSE, MMI_FALSE, MMI_TRUE);
    }
}

#ifdef __MMI_BT_AUDIO_VIA_SCO__

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sco_disconnected_event_hdlr
 * DESCRIPTION
 *  sco disconnected callback event hdlr
 * PARAMETERS
 *  param
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
mmi_ret srv_a2dp_sco_disconnected_event_hdlr(void *param)
{
    /* there is case that BT headset start stream ind when we are waiting for SCO disconnection, 
       for this case, the state will enter streaming thus don't need to connect again */
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    mmi_frm_cb_dereg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_a2dp_sco_disconnected_event_hdlr, NULL);
#endif
    return MMI_RET_OK; 
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_sco_callback_hdlr
 * DESCRIPTION
 *  sco connection callback hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_sco_callback_hdlr(void)
{
    U8 index = 0;

    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
        {
            g_srv_a2dp_cntx.dev_info[index].user_callback(&(g_srv_a2dp_cntx.dev_info[index].address), SRV_A2DP_CALLBACK_EVENT_OPEN_SCO);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_connect_hfp_callback_hdlr
 * DESCRIPTION
 *  connect HFP callback hdlr
 * PARAMETERS
 *  MMI_BOOL    [IN] indicate if connect success
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_connect_hfp_callback_hdlr(MMI_BOOL success)
{
    U8 index = 0;

    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        if((g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK) && (!success))
        {
            g_srv_a2dp_cntx.dev_info[index].user_callback(&(g_srv_a2dp_cntx.dev_info[index].address), SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_audio_via_sco
 * DESCRIPTION
 *  check if need to connect HFP / SCO
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_a2dp_open_result_enum    SRV_A2DP_OPEN_WAITING: need to wait HFP / SCO connect; 
 *                               SRV_A2DP_OPEN_FAILED: do not need to wait HFP / SCO connect
 *                               SRV_A2DP_OPEN_DONE: sco already connectd
 *****************************************************************************/
srv_a2dp_open_result_enum srv_a2dp_open_audio_via_sco(void)
{
    kal_bool connect_sco;

    connect_sco = mmi_a2dp_connect_sco_check();

    if(!connect_sco)
    {
        return SRV_A2DP_OPEN_FAILED;
    }

#ifdef __MMI_A2DP_HIDE_BT_SETTINGS__
    {
        BtAudStatus status = srv_btaud_get_status(BTAUD_CHNL_ANY);

        if (status == BTAUD_ACTIVE)
        {
            if(!srv_bt_cm_is_audio_path_to_headset())
            {
               return SRV_A2DP_OPEN_FAILED;
            }

            /* not allow sco connection and return fail*/
            if(!srv_btsco_is_profile_connect_allowed())
            {
                return SRV_A2DP_OPEN_FAILED;
            }

            if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
            {
                /*start connecting*/
                return SRV_A2DP_OPEN_WAITING;
            }
            else
            {
                /*not connect sco for some reason*/
                return SRV_A2DP_OPEN_FAILED;
            }
        }
        
        if (status == BTAUD_SWITCH_ON)
        {
            /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
            if(!srv_btsco_is_profile_connect_allowed())
            {
                srv_btsco_disconnect_sco_req();
                return SRV_A2DP_OPEN_FAILED;
            }
            else
            {
                return SRV_A2DP_OPEN_DONE;
            }
        }

        return SRV_A2DP_OPEN_FAILED;
    }

#else
    if(!srv_bt_cm_get_default_dev_addr(SRV_BT_CM_DEFAULT_DEV_TYPE_HS))
    {
        /*default earphone not existed*/

        if(!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
        {
            /*no existed hs connection*/
            return SRV_A2DP_OPEN_FAILED;
        }

    #ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
        if(!srv_bt_cm_is_audio_path_to_headset())
        {
           return SRV_A2DP_OPEN_FAILED;
        }
    #endif

        /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
        if(!srv_btsco_is_profile_connect_allowed())
        {
            srv_btsco_disconnect_sco_req();
            return SRV_A2DP_OPEN_FAILED;
        }

        if(srv_bt_cm_is_audio_link_on())
        {
            /* SCO already connected*/
            return SRV_A2DP_OPEN_DONE;
        }

        /*connect SCO with current hs conection*/
        if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
        {
            /*start connecting*/
            return SRV_A2DP_OPEN_WAITING;
        }
        else
        {
            /*not connect sco for some reason*/
            return SRV_A2DP_OPEN_FAILED;
        }
    }
    else
    {
        /*default earphone existed*/

        if(!(srv_bt_cm_is_profile_connected(SRV_BT_CM_HFP_CONNECTION) || srv_bt_cm_is_profile_connected(SRV_BT_CM_HSP_CONNECTION)))
        {
            /*no existed hs connection*/
            if(!srv_bt_cm_connect_default_headset(srv_a2dp_connect_hfp_callback_hdlr))
            {
                return SRV_A2DP_OPEN_FAILED;  
            }
            return SRV_A2DP_OPEN_WAITING;
        }

    #ifndef __MMI_A2DP_HIDE_BT_SETTINGS__
        if(!srv_bt_cm_is_audio_path_to_headset())
        {
           return SRV_A2DP_OPEN_FAILED;
        }
    #endif

        /* not allow sco connection, so disconnect sco (casue sco might be connected by other module like FM) and return fail*/
        if(!srv_btsco_is_profile_connect_allowed())
        {
            srv_btsco_disconnect_sco_req();
            return SRV_A2DP_OPEN_FAILED;
        }

        if(srv_bt_cm_is_audio_link_on())
        {
            /* SCO already connected*/
            return SRV_A2DP_OPEN_DONE;
        }

        /*connect SCO with current hs conection*/
        if (srv_btsco_connect_sco_req(srv_a2dp_connect_sco_callback_hdlr))
        {
            /*start connecting*/
            return SRV_A2DP_OPEN_WAITING;
        }
        else
        {
            /*not connect sco for some reason*/
            return SRV_A2DP_OPEN_FAILED;
        }

    }

#endif
}

#endif
/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sink_reg_cb_err_evts
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void srv_a2dp_sink_reg_cb_err_evts(srv_a2dp_sink_app_callback cb_ptr)
{
	if(cb_ptr!=NULL)
		g_avrcp_cm_callback = cb_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sink_avrcp_interface
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void srv_a2dp_sink_avrcp_interface(S32 events)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_a2dp_sink_media_err_events evt = (srv_a2dp_sink_media_err_events)events;
    U8 index = 0;
    kal_bool bStream;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SINK_INTERRUPT, evt);

    switch(evt)
    {
        case SRV_A2DP_SINK_END:
        case SRV_A2DP_SINK_ERROR:
        case SRV_A2DP_SINK_TERMINATED:
        {
            bStream = mmi_a2dp_quiry_streaming_dev(&index);
            if(bStream && (g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK))
            {
                g_local_interrupt_index = index;
            #ifdef __MMI_AVRCP_SUPPORT__
                srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[index].address), SRV_AVRCP_POP_PAUSE);
            #endif
                mmi_a2dp_close_codec(A2DP_ROLE_SINK);
            }
            break;
        }

        case SRV_A2DP_SINK_RESUME:
        {
            if (g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].state == A2DP_STATE_STREAMING)
            {
                mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].audio_cfg),
                                    g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].stream_hdl,
                                    g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].role,
                                    MMI_TRUE);
                mmi_a2dp_stream_start_sink_codec_req(g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].stream_hdl);
            }
            else
            {
            #ifdef __MMI_AVRCP_SUPPORT__
                srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[g_local_interrupt_index].address), SRV_AVRCP_POP_PLAY);
            #endif
            }
            break;
        }
        
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_dev_info_by_index
 * DESCRIPTION
 * To get the a2dp role
 * PARAMETERS
 *  void
 * RETURNS
 *  BT_A2DP_SRC_SINK  : invalid
 *  BT_A2DP_SINK : CT
 *  BT_A2DP_SOURCE: TG
 *****************************************************************************/
void srv_a2dp_get_dev_info_by_index(a2dp_dev_info_struct* info, U8 index)
{
    if(info != NULL)
    {
        memcpy(info, &(g_srv_a2dp_cntx.dev_info[index]), sizeof(a2dp_dev_info_struct));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_role
 * DESCRIPTION
 * To get the a2dp role
 * PARAMETERS
 *  void
 * RETURNS
 *  BT_A2DP_SRC_SINK  : invalid
 *  BT_A2DP_SINK : CT
 *  BT_A2DP_SOURCE: TG
 *****************************************************************************/
U8 srv_a2dp_get_role(srv_bt_cm_bt_addr* bt_addr)
{
    MMI_BOOL bFound = MMI_FALSE;
    U8 index = 0;
    U8 role = A2DP_ROLE_NONE;

    if (!bt_addr)
    {
        return A2DP_ROLE_NONE;
    }

    bFound = mmi_a2dp_quiry_by_address(bt_addr, &index);
    if (!bFound)
    {
        return A2DP_ROLE_NONE;
    }

    role = g_srv_a2dp_cntx.dev_info[index].role;
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GET_ROLE, role);
    return role;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_stream_handle
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  BT_A2DP_SRC_SINK  : invalid
 *  BT_A2DP_SINK : CT
 *  BT_A2DP_SOURCE: TG
 *****************************************************************************/
U8 srv_a2dp_get_stream_handle(srv_bt_cm_bt_addr* bt_addr)
{
    MMI_BOOL bFound = MMI_FALSE;
    U8 handle = -1;
    U8 index;

    if (!bt_addr)
    {
        return -1;
    }

    bFound = mmi_a2dp_quiry_by_address(bt_addr, &index);
    if (!bFound)
    {
        return -1;
    }
    else if(g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_IDLE)
    {
        return -1;
    }

    handle = g_srv_a2dp_cntx.dev_info[index].stream_hdl;
    return handle;
}



/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_connected
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_connected(void)
{
    a2dp_state_enum state;
    MMI_BOOL is_connected = MMI_FALSE;
    U8 index = 0;

    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        state = g_srv_a2dp_cntx.dev_info[index].state;
        is_connected = ((state >= A2DP_STATE_OPEN) ? KAL_TRUE : KAL_FALSE );
        if(is_connected)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_CONNECTED, MMI_TRUE);
            return MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_CONNECTED, MMI_FALSE);
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_connected_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_connected_ex(srv_bt_cm_bt_addr *address)
{
    a2dp_state_enum state;
    MMI_BOOL is_connected = MMI_FALSE;
    MMI_BOOL bFound = MMI_FALSE;
    U8 index = 0;

    if (!address)
    {
        return MMI_FALSE;
    }

    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_CONNECTED, MMI_FALSE);
        return MMI_FALSE;
    }

    state = g_srv_a2dp_cntx.dev_info[index].state;
    is_connected = ((state >= A2DP_STATE_OPEN) ? KAL_TRUE : KAL_FALSE );
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_CONNECTED, is_connected);
    return is_connected;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_streaming
 * DESCRIPTION
 *  check device streaming state, the device role is "SRC"
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_streaming(void)
{
    a2dp_state_enum state;
    MMI_BOOL is_streaming = MMI_FALSE;
    U8 index = 0;

    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        state = g_srv_a2dp_cntx.dev_info[index].state;
        is_streaming = ((state == A2DP_STATE_STREAMING) ? KAL_TRUE : KAL_FALSE);
        if(is_streaming)
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_STREAMING, MMI_TRUE);
            return MMI_TRUE;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_STREAMING, MMI_FALSE);
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_streaming
 * DESCRIPTION
 *  check device streaming state by address
 * PARAMETERS
 *  address       [IN]   device bt address
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_streaming_ex(srv_bt_cm_bt_addr *address)
{
    a2dp_state_enum state;
    MMI_BOOL is_streaming = MMI_FALSE;
    MMI_BOOL bFound = MMI_FALSE;
    U8 index = 0;

    if (!address)
    {
        return MMI_FALSE;
    }

    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_STREAMING, MMI_FALSE);
        return MMI_FALSE;
    }

    state = g_srv_a2dp_cntx.dev_info[index].state;
    is_streaming = (A2DP_STATE_STREAMING == state)?(MMI_TRUE):(MMI_FALSE);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_STREAMING, is_streaming);
    return is_streaming;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause
 * DESCRIPTION
 *  pause A2DP stream, will pause the "SRC" device after 300ms
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause_stream()
{
    U8 index;
    kal_bool is_streaming;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_PAUSE_STREAM);
    StopTimer(AV_BT_DELAY_PAUSE_TIMER);
    StartTimer(AV_BT_DELAY_PAUSE_TIMER, A2DP_SRV_PLAY_DUR_TIME, (FuncPtr)srv_a2dp_pause_stream_hdlr);

    is_streaming = mmi_a2dp_quiry_streaming_dev(&index);
    if(is_streaming)
    {
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_pause_stream_hdlr
 * DESCRIPTION
 *  pause A2DP stream, will pause the "SRC" device
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_pause_stream_hdlr()
{
    U8 index;
    kal_bool is_streaming;

    is_streaming = mmi_a2dp_quiry_streaming_dev(&index);
    if(is_streaming)
    {
        if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SOURCE)
        {
            mmi_a2dp_pause_req(&(g_srv_a2dp_cntx.dev_info[index]));
        }
        else if(g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SINK)
        {
        #ifdef __MMI_AVRCP_SUPPORT__
            srv_avrcp_send_cmd_frame(&(g_srv_a2dp_cntx.dev_info[index].address), SRV_AVRCP_POP_PAUSE);
        #endif
        }
        
        mmi_a2dp_close_codec(g_srv_a2dp_cntx.dev_info[index].role);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_start_stream
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void srv_a2dp_start_stream(srv_bt_cm_bt_addr *address)
{
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    if (!address)
    {
        return;
    }

    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_STRAT_STREAM);
    /* disable to make sure sco will not be activated*/
    mmi_a2dp_disable_sco();
    /* need to wait until sco disconnected ind*/
    
#ifdef __MMI_BT_AUDIO_VIA_SCO__
    if(srv_btsco_is_sco_open())
    {
        mmi_frm_cb_reg_event(EVT_ID_SRV_BTSCO_CLOSE_IND, (mmi_proc_func) srv_a2dp_sco_disconnected_event_hdlr, NULL);
    }
    else
#endif
    {
        mmi_a2dp_start_req(&(g_srv_a2dp_cntx.dev_info[index]));
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_disable_stream
 * DESCRIPTION
 *  disable stream, so that BTD will not sound when SP send audio data to it
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void srv_a2dp_disable_stream()
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DISABLE_STREAM);
    g_a2dp_stream_disable = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_enable_stream
 * DESCRIPTION
 * 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void srv_a2dp_enable_stream()
{

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_ENABLE_STREAM, g_a2dp_stream_disable, g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].state);

    if((g_a2dp_stream_disable == MMI_TRUE) &&
        (g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].state == A2DP_STATE_STREAMING))
    {
        mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].audio_cfg),
                            g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].stream_hdl,
                            g_srv_a2dp_cntx.dev_info[g_sp_interrupt_index].role,
                            MMI_TRUE);
    }

    g_a2dp_stream_disable = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close
 * DESCRIPTION
 *  close A2DP connection, will close the "SRC" device
 * PARAMETERS
 *  notify_opener            [IN]
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_a2dp_close(MMI_BOOL notify_opener)
{
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_CLOSE);
    bFound = srv_a2dp_quiry_by_role(A2DP_ROLE_SOURCE, &index);
    if (!bFound)
    {
        return;
    }
    mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[index])); 
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_close_ex
 * DESCRIPTION
 *  close A2DP connection by address
 * PARAMETERS
 *  address            [IN]
 *  cb_func            [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_close_ex(srv_bt_cm_bt_addr *address)
{
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_CLOSE);
    if (!address)
    {
        return SRV_A2DP_CLOSE_DONE;
    }

    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        return SRV_A2DP_CLOSE_DONE;
    }
    else if(g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_IDLE)
    {
        return SRV_A2DP_CLOSE_DONE;
    }
    else if(g_srv_a2dp_cntx.dev_info[index].waitting != A2DP_WAIT_NONE)
    {
        return SRV_A2DP_CLOSE_FAILED;
    }

    g_srv_a2dp_cntx.dev_info[index].cm_callback = cm_notify_callback;
    mmi_a2dp_close_req(&(g_srv_a2dp_cntx.dev_info[index]));
    return SRV_A2DP_CLOSE_WAITING;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open
 * DESCRIPTION
 *  open A2DP connection by address, the role is "SRC"
 * PARAMETERS
 *  bt_dev              [IN]
 *  sample_rate         [IN]
 *  stereo              [IN]
 *  callback            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_open(srv_bt_cm_bt_addr *bt_dev,
                  U16 sample_rate,
                  U8 stereo,
                  A2DP_SRV_CALLBACK callback,
                  MMI_BOOL immediate_callback)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SRC_OPEN);
    // no need callback cm when app connect a2dp, by the cm app design
    //g_a2dp_cm_notify = MMI_FALSE;
    cm_notify_callback = NULL;
    return mmi_a2dp_open_by_role(bt_dev, A2DP_ROLE_SOURCE, callback, MMI_TRUE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_ex
 * DESCRIPTION
 *   Request A2DP service to establish a connection configured to start streaming 
 *   audio with the requested audio file (Audio Only).
 *   This function could only supported in PlutoMMI for memory configuration sake.
 *   For non-PlutoMMI project, it returns failed directly.
 * PARAMETERS
 *  bt_dev              : [IN] bt address to connect
 *  filename            : [IN] audio file full path.
 *  callback            : [IN] callback function
 *  sbc_only            : [IN] do not goes with mp3 streaming
 *  immediate_callback  : [IN] if need to callback when the result can be return immediately
 * RETURNS
 *  S32
 *****************************************************************************/
S32 srv_a2dp_open_ex(srv_bt_cm_bt_addr *bt_dev, 
                     WCHAR *filename, 
                     A2DP_SRV_CALLBACK callback, 
                     MMI_BOOL sbc_only, 
                     MMI_BOOL immediate_callback)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DEV_OPEN);
    // no need callback cm when app connect a2dp, by the cm app design
    //g_a2dp_cm_notify = MMI_FALSE;
    cm_notify_callback = NULL;
    return mmi_a2dp_open_by_role(bt_dev, A2DP_ROLE_SOURCE, callback, MMI_TRUE);
}


/////////////////////////////////////////////////////

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_init(void)
{
    srv_bt_cm_profile_struct prof_info;
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_INIT);
    mmi_a2dp_reset_ctx();
    prof_info.profile_id = SRV_BT_CM_ADVANCED_AUDIO_PROFILE_UUID;
    prof_info.activater = mmi_a2dp_active_req;
    prof_info.deactivater = mmi_a2dp_deactive_req;
    prof_info.disconnector = mmi_a2dp_disconnect_req;
    srv_bt_cm_profile_register(&prof_info);

#ifdef __MMI_BT_DIALER_SUPPORT__
#if defined(__IOT__)
    cm_notify_callback = NULL;
#else
    cm_notify_callback = mmi_bt_dialor_callback;
#endif
#endif

    /* set msg hdlrs */ 
    SetProtocolEventHandler(mmi_a2dp_active_cnf, MSG_ID_BT_A2DP_ACTIVATE_CNF);
    SetProtocolEventHandler(mmi_a2dp_deactive_cnf, MSG_ID_BT_A2DP_DEACTIVATE_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_open_cnf, MSG_ID_BT_A2DP_STREAM_OPEN_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_open_ind, MSG_ID_BT_A2DP_STREAM_OPEN_IND);
    SetProtocolEventHandler(mmi_a2dp_stream_open_done, MSG_ID_BT_A2DP_STREAM_OPEN_DONE);
    SetProtocolEventHandler(mmi_a2dp_stream_start_cnf, MSG_ID_BT_A2DP_STREAM_START_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_start_ind, MSG_ID_BT_A2DP_STREAM_START_IND);
    SetProtocolEventHandler(mmi_a2dp_stream_pause_cnf, MSG_ID_BT_A2DP_STREAM_PAUSE_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_pause_ind, MSG_ID_BT_A2DP_STREAM_PAUSE_IND);
    SetProtocolEventHandler(mmi_a2dp_stream_close_cnf, MSG_ID_BT_A2DP_STREAM_CLOSE_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_close_ind, MSG_ID_BT_A2DP_STREAM_CLOSE_IND);
    SetProtocolEventHandler(mmi_a2dp_stream_abort_cnf, MSG_ID_BT_A2DP_STREAM_ABORT_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_abort_ind, MSG_ID_BT_A2DP_STREAM_ABORT_IND);
    SetProtocolEventHandler(mmi_a2dp_stream_reconfig_cnf, MSG_ID_BT_A2DP_STREAM_RECONFIG_CNF);
    SetProtocolEventHandler(mmi_a2dp_stream_reconfig_ind, MSG_ID_BT_A2DP_STREAM_RECONFIG_IND);
    SetProtocolEventHandler(mmi_a2dp_aud_close_codec_ind, MSG_ID_MEDIA_BT_CLOSE_CODEC_IND);
    SetProtocolEventHandler(mmi_a2dp_aud_sink_codec_ind, MSG_ID_MEDIA_BT_SINK_CODEC_IND);

}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_auto_disconnect_dalay
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msec  [IN] delay time in milli second
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_auto_disconnect_dalay(kal_uint16 msec)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_default_callback
 * DESCRIPTION
 *  This function is to set default callback handler.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_default_callback(A2DP_SRV_CALLBACK handler)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DELETE_APP_CALLBACK, handler);
    //un-unsed
    g_srv_a2dp_cntx.default_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_bt_music_callback
 * DESCRIPTION
 *  This function is to set default callback handler.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_bt_music_callback(srv_bt_cm_bt_addr *bt_dev, A2DP_SRV_CALLBACK callback)
{
    kal_bool bFound;
    U8 index;
    
    bFound = mmi_a2dp_quiry_by_address(bt_dev, &index);
    if (bFound && (callback != NULL))
    {
        g_srv_a2dp_cntx.dev_info[index].user_callback = callback;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_app_callback
 * DESCRIPTION
 *  This function is to set default callback handler.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_app_callback(A2DP_SRV_CALLBACK handler)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SET_APP_CALLBACK, handler);
    g_srv_a2dp_cntx.media_callback = handler;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_delete_app_callback
 * DESCRIPTION
 *  This function is to set default callback handler.
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_delete_app_callback(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_DELETE_APP_CALLBACK, g_srv_a2dp_cntx.media_callback);
    g_srv_a2dp_cntx.media_callback = NULL;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_check_output_callback
 * DESCRIPTION
 *  This function is to set check output path hdlr
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_check_output_callback(A2DP_SRV_CHECK_OUTPUT_CALLBACK handler)
{
    g_srv_a2dp_cntx.check_output_callback = handler;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_is_output_to_bt_callback
 * DESCRIPTION
 *  This function is to set is output to be callback
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_is_output_to_bt_callback(A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK handler)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_set_get_bt_headset_callback
 * DESCRIPTION
 *  This function is to set get bt headset address callbackk
 * PARAMETERS
 *  handler     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_set_get_bt_headset_callback(A2DP_SRV_GET_BT_HEADSET_CALLBACK handler)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_output_to_bt
 * DESCRIPTION
 *  to check if currently application could go through a2dp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_output_to_bt(void)
{
    a2dp_role_enum role = BT_A2DP_SINK;
    U8 Index;
    kal_bool bFound;

    bFound = srv_a2dp_quiry_by_role(BT_A2DP_SOURCE, &Index);
    if(bFound)
    {
        return MMI_TRUE;
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_connect_bt_addr
 * DESCRIPTION
 *  to query current a2dp headset setting to pass to a2dp service for signal connection
 * PARAMETERS
 *  void
 * RETURNS
 *  bt_addr_struct *
 *****************************************************************************/
srv_bt_cm_bt_addr *srv_a2dp_get_connect_bt_addr(void)
{
    //CM call it
    return NULL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_bt_inquirying
 * DESCRIPTION
 *  This function is for background play application to check if BT CM is now
 *  performing inquirying action
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : inquirying
 *  MMI_FALSE : not inquiring
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_bt_inquirying(void)
{
    return (MMI_BOOL)g_srv_a2dp_cntx.is_inquiry;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_codec_open
 * DESCRIPTION
 *  To check if audio driver open codec to send A2DP streaming data to BT stack
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : codec open
 *  MMI_FALSE : codec not open
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_codec_open(void)
{
    if(g_srv_a2dp_cntx.codec_opened != A2DP_CODEC_NONE)
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
 *  srv_a2dp_is_mp3_configured
 * DESCRIPTION
 *  To check if A2DP coedc is configured as mp3 streaming.
 *  After 11A, mp3 streaming is disabled for some performance reason.
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_TRUE  : streaming
 *  MMI_FALSE : not streaming
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_mp3_configured(void)
{
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_start_callback
 * DESCRIPTION
 *  for BT CM to infrom A2DP service about inquiry action starts
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_inquiry_start_callback(void)
{
    U8 index = 0;
    a2dp_dev_info_struct info;
    
    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        srv_a2dp_get_dev_info_by_index(&info, index);
        if(info.user_callback && (!g_srv_a2dp_cntx.is_inquiry))
        {
            g_srv_a2dp_cntx.is_inquiry = KAL_TRUE;
            info.user_callback(&(info.address), SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_inquiry_stop_callback
 * DESCRIPTION
 *  for BT CM to infrom A2DP service about inquiry action stops
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_a2dp_inquiry_stop_callback(void)
{
    U8 index = 0;
    a2dp_dev_info_struct info;
    
    for(index = 0; index < MAX_A2DP_LINK_NUM; index++)
    {
        srv_a2dp_get_dev_info_by_index(&info, index);
        if(info.user_callback && g_srv_a2dp_cntx.is_inquiry)
        {
            g_srv_a2dp_cntx.is_inquiry = KAL_FALSE;
            info.user_callback(&(info.address), SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_calc_audio_config
 * DESCRIPTION
 *  
 * PARAMETERS
 *  aud_info    [IN]
 *  aud_cfg     [IN]
 *  aud_fmt     [IN]
 *  codec_type  [IN]
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool srv_a2dp_aud_info_to_cfg(
            audInfoStruct *aud_info,
            bt_a2dp_audio_cap_struct *aud_cfg,
            kal_int16 aud_fmt,
            kal_uint8 codec_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*kal_bool stereo = aud_info->stereo;*/
    kal_uint32 samplerate = aud_info->sampleRate;
    kal_bool result = KAL_TRUE; 

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (codec_type == BT_A2DP_SBC)
    {   /* SBC transcoding is necessary */
        bt_a2dp_sbc_codec_cap_struct *sbc = &aud_cfg->codec_cap.sbc;

        samplerate /= 1000;
        switch (samplerate)
        {
            case 7:
            case 8:
            case 15:
            case 16:
            #if 0
/* under construction !*/
/* under construction !*/
            #endif
            case 31:
            case 32:
                sbc->sample_rate = 0x4; /* convert to 32000 sps */
                break;
            case 10:
            case 11:
            case 21:
            case 22:
            case 43:
            case 44:
                sbc->sample_rate = 0x2; /* convert to 44100 sps */
                break;
            case 12:
            case 23:
            case 24:
            case 47:
            case 48:
                sbc->sample_rate = 0x1; /* convert to 48000 sps */
                break;
            default:
                return KAL_FALSE;
        }

        #if 0   /* defined(L1SBC_SUPPORT_MONO) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* 1 */ 
        sbc->channel_mode = 0x1;    /* default: joint-stereo */

        sbc->block_len = 0x1;       /* 16: fixed */
        sbc->subband_num = 0x1;     /* 8: fixed */
        sbc->alloc_method = 0x1;    /* loudness: fixed */
        SBC_InitiateBitPool(sbc->channel_mode, sbc->sample_rate, &sbc->min_bit_pool, &sbc->max_bit_pool);
    }
    else
    {
    #ifndef __LOW_COST_SUPPORT_COMMON__
        /* not support transcoding here, media format shall be the same with codec type */
        if (codec_type == BT_A2DP_MP3 && (aud_fmt == MDI_FORMAT_DAF || aud_fmt == MDI_FORMAT_MUSICAM))
        {                       /* MP3 streaming */
            bt_a2dp_mp3_codec_cap_struct *mp3 = &aud_cfg->codec_cap.mp3;

            mp3->layer = 0x1;
            mp3->CRC = (kal_bool)aud_info->details.DAF.CRC;
            if (aud_info->details.DAF.channel_mode == 0x00)
               mp3->channel_mode = 0x2;
            else if (aud_info->details.DAF.channel_mode == 0x01)
               mp3->channel_mode = 0x1;
            else if (aud_info->details.DAF.channel_mode == 0x02)
               mp3->channel_mode = 0x4;
            else if (aud_info->details.DAF.channel_mode == 0x03)
               mp3->channel_mode = 0x8;
            else
               return KAL_FALSE;

            mp3->MPF = KAL_FALSE;
            if (samplerate == 48000)
               mp3->sample_rate = 0x1;
            else if (samplerate == 44100)
               mp3->sample_rate = 0x2;
            else if (samplerate == 32000)
               mp3->sample_rate = 0x4;
            else if (samplerate == 24000)
               mp3->sample_rate = 0x8;
            else if (samplerate == 22050)
               mp3->sample_rate = 0x10;
            else if (samplerate == 16000)
               mp3->sample_rate = 0x20;
            else
               return KAL_FALSE;
            mp3->VBR = KAL_TRUE;
            mp3->bit_rate = 0x4000;

            result = srv_a2dp_check_handset_mp3_config(mp3);

        }
        else if (codec_type == BT_A2DP_AAC && aud_fmt == MDI_FORMAT_AAC)
        {                       /* AAC streaming */
            /* bt_a2dp_aac_codec_cap_struct *aac = &aud_cfg->codec_cap.aac; */
            return KAL_FALSE;   /* not support now */
        }
        else
        {   /* not supported streaming codec */
            return KAL_FALSE;
        }

    #else
        return KAL_FALSE;
    #endif /*__LOW_COST_SUPPORT_COMMON__*/

    }

    if(result)
    {
        aud_cfg->codec_type = codec_type;
    }

    return result;

}



/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_aud_cfg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  filename    [IN]
 *  aud_cfg     [IN]
 *  sbc_only    [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 srv_a2dp_get_aud_cfg(kal_wchar* filename, bt_a2dp_audio_cap_struct *aud_cfg,
    kal_bool sbc_only)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int16 format, i, count;
    kal_uint8 codec_type[2] = {BT_A2DP_SBC, 0};
    kal_uint8* pFSALBuf;
    STFSAL file;
    audInfoStruct *aud_info;
#ifdef KUR_DECODE
    Media_KURO_Param extFormat;
    KURO_HEAD_INFO *kur_header_info;
    KURO_FUN_CODE kur_result;
#endif /*KUR_DECODE*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    //now local only support SBC
    aud_cfg[0].codec_type = 0;
    aud_cfg[1].codec_type = 0;
    //aud_info.bitRate = 0;

    format = med_get_media_type(filename);

    // open file
    if (FSAL_Open(&file, filename, FSAL_READ_SHARED) != FSAL_OK)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GET_AUDIO_CFG, -1);
        return -1;
    }

    // set FSAL buffer
    pFSALBuf = (kal_uint8*) get_ctrl_buffer(1024);
    FSAL_SetBuffer(&file, 1024, pFSALBuf);

    aud_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));
    aud_info->bitRate = 0;

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GET_AUDIO_CFG_FORMAT, format);

    switch (format)
    {
        #ifdef AMR_DECODE
        case MDI_FORMAT_AMR:
        #ifdef AMRWB_DECODE
        case MDI_FORMAT_AMR_WB:
        #endif 
            AMR_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* AMR_DECODE */ 
        #ifdef __VM_CODEC_SUPPORT__
        case MDI_FORMAT_GSM_FR:
        case MDI_FORMAT_GSM_HR:
        case MDI_FORMAT_GSM_EFR:
        #ifdef __MED_VR_MOD__
        case MDI_FORMAT_VR:
        #endif 
            VM_GetContentDescInfo(&file, aud_info, &format);
            break;
        #endif /*__VM_CODEC_SUPPORT__*/
        #ifdef WAV_CODEC
        case MDI_FORMAT_PCM_16K:
        case MDI_FORMAT_PCM_8K:
        case MDI_FORMAT_DVI_ADPCM:
            PCM_GetContentDescInfo(&file, aud_info, (void*)format);
            break;
        #endif /*WAV_CODEC*/
        #ifdef DAF_DECODE
        case MDI_FORMAT_DAF:
        #ifdef MUSICAM_DECODE        
        case MDI_FORMAT_MUSICAM:
        #endif
            DAF_GetContentDescInfo(&file, aud_info, NULL);

        /* to prevent from performance issue, we do not support MP3 streaming now, 
           it is reference only now.*/
        #if defined(__MMI_A2DP_SUPPORT_DAF_STREAMING__) && !defined(__LOW_COST_SUPPORT_COMMON__)
            if (!sbc_only && aud_info->details.DAF.mediaFormat == MEDIA_FORMAT_DAF)
            {
                codec_type[0] = BT_A2DP_MP3;
                codec_type[1] = BT_A2DP_SBC;
            }
        #endif
            break;
        #endif /* DAF_DECODE */ 
        #ifdef WAV_CODEC
        case MDI_FORMAT_WAV:
        case MDI_FORMAT_WAV_ALAW:
        case MDI_FORMAT_WAV_ULAW:
        case MDI_FORMAT_WAV_DVI_ADPCM:
            WAV_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /*WAV_CODEC*/
        #ifdef AU_DECODE
        case MDI_FORMAT_AU:
            AU_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* AU_DECODE */
        #ifdef AIFF_DECODE
        case MDI_FORMAT_AIFF:
            AIFF_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* AIFF_DECODE */
        #ifdef WMA_DECODE
        case MDI_FORMAT_WMA:
            WMA_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* WMA_DECODE */ 
        #ifdef AAC_DECODE
        case MDI_FORMAT_AAC:
        #ifdef BSAC_DECODE
/* under construction !*/
        #endif /* BSAC_DECODE */
            AAC_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* AAC_DECODE */ 
        #ifdef M4A_DECODE
        case MDI_FORMAT_M4A:
            MP4S_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* M4A_DECODE */

        #if defined(PURE_AUDIO_SUPPORT) //|| defined(MP4_DECODE)
        case MDI_FORMAT_3GP:
        case MDI_FORMAT_MP4:
            MP4S_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /* defined(__MMI_PURE_AUDIO__) */ 

        #ifdef __FLV_FILE_FORMAT_SUPPORT__
        case MDI_FORMAT_F4A:
        case MDI_FORMAT_F4V:
        case MDI_FORMAT_FLV:
            FLV_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /*__FLV_FILE_FORMAT_SUPPORT__*/

        #ifdef KUR_DECODE
        case MDI_FORMAT_KURO:
            /* Get kuro header info for decrypt */
            kur_header_info = (void*)get_ctrl_buffer(sizeof(KURO_HEAD_INFO));
            kur_result = KURO_GetKuroHeadInfo(file.hFile, kur_header_info);

            if(kur_result != KURO_OK)
            {
                free_ctrl_buffer(kur_header_info);
                break;
            }

            extFormat.paramType.type = MEDIA_EXT_PARAM_KURO_CONTENT;
            extFormat.pInfo = (void*)kur_header_info;

            if(KURO_adp_get_media_type(kur_header_info) == MED_TYPE_KURO_AAC)
            {
                AAC_GetContentDescInfo(&file, aud_info, &extFormat);
            }
            else
            {
                DAF_GetContentDescInfo(&file, aud_info, &extFormat);
            }

            free_ctrl_buffer(kur_header_info);
            break;
        #endif /* KUR_DECODE */
        #ifdef __RM_DEC_SUPPORT__
        case MDI_FORMAT_RMVB:
        case MDI_FORMAT_RM:
        case MDI_FORMAT_RA:
        case MDI_FORMAT_RV:
            RM_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif /*__RM_DEC_SUPPORT__*/
        #ifdef __APE_DECODE__
        case MDI_FORMAT_APE:
        	  APE_GetContentDescInfo(&file, aud_info, NULL);
        	break;
        #endif
        #ifdef __VORBIS_DECODE__
        case MDI_FORMAT_VORBIS:
            VORBIS_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif

        #ifdef __FLAC_DECODE__
        case MDI_FORMAT_FLAC:
            FLAC_GetContentDescInfo(&file, aud_info, NULL);
            break;
        #endif
        default:
            aud_info->sampleRate = 32000;
            aud_info->stereo = KAL_TRUE;
            break;
    }

    FSAL_Close(&file);
    free_ctrl_buffer(pFSALBuf);

    for( count = i = 0; i < 2 && codec_type[i]; i++ )
    {
        if (srv_a2dp_aud_info_to_cfg(aud_info, &aud_cfg[count], format, codec_type[i]))
        {
            if( aud_cfg[count].codec_type == BT_A2DP_SBC )
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GET_AUDIO_CFG_SBC,
                                                aud_cfg[count].codec_cap.sbc.min_bit_pool,
                                                aud_cfg[count].codec_cap.sbc.max_bit_pool,
                                                aud_cfg[count].codec_cap.sbc.sample_rate,
                                                aud_cfg[count].codec_cap.sbc.channel_mode);
            }
        #ifndef __LOW_COST_SUPPORT_COMMON__
            else if (aud_cfg[count].codec_type == BT_A2DP_MP3)
            {

                MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_A2DP_SRV_GET_AUDIO_CFG_MP3,\
                    aud_cfg[count].codec_cap.mp3.bit_rate, \
                    aud_cfg[count].codec_cap.mp3.layer, \
                    aud_cfg[count].codec_cap.mp3.sample_rate, \
                    aud_cfg[count].codec_cap.mp3.channel_mode, \
                    aud_cfg[count].codec_cap.mp3.VBR, \
                    aud_cfg[count].codec_cap.mp3.MPF);
            }
            /* enforce a bitrate limit to 320K, otherwise, use SBC encode */
            if (codec_type[i] == BT_A2DP_MP3 && aud_info->bitRate >= 320000)
            {
                continue;
            }
        #endif
            count++;
        }
        else
        {
            continue;
        }
    }

    free_ctrl_buffer(aud_info);

    return (count > 0) ? 0: -1;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_get_aud_cfg_ex
 * DESCRIPTION
 *  
 * PARAMETERS
 *  sample_rate [IN]
 *  stereo      [IN]
 *  aud_cfg     [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
kal_int32 srv_a2dp_get_aud_cfg_ex(kal_uint16 sample_rate, kal_bool stereo, bt_a2dp_audio_cap_struct *aud_cfg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    audInfoStruct *aud_info;
    aud_info = (audInfoStruct*) get_ctrl_buffer(sizeof(audInfoStruct));

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    

    aud_cfg[0].codec_type = 0;
    aud_cfg[1].codec_type = 0;

    aud_info->sampleRate = (kal_uint32)sample_rate;
    aud_info->stereo = stereo;

    if (!srv_a2dp_aud_info_to_cfg(aud_info, &aud_cfg[0], 0, BT_A2DP_SBC))
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GET_AUDIO_CFG, -1);
        free_ctrl_buffer(aud_info);
        return -1;
    }

    MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_TRC_A2DP_SRV_GET_AUD_CFG_EX, \
        aud_cfg[0].codec_cap.sbc.min_bit_pool, \
        aud_cfg[0].codec_cap.sbc.max_bit_pool, \
        aud_cfg[0].codec_cap.sbc.sample_rate, \
        aud_cfg[0].codec_cap.sbc.channel_mode);

    free_ctrl_buffer(aud_info);
    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_reconfig_start_streaming
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  callback            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_reconfig_start_streaming(
            srv_bt_cm_bt_addr *address, 
            WCHAR* filename, 
            U16 sample_rate, 
            U8 stereo, 
            MMI_BOOL sbc_only)
{
    kal_bool bFound;
    kal_bool bSame;
    U8 index = 0;
    srv_bt_cm_bt_addr open_address;
    
    if (!address)
    {
        return SRV_A2DP_OPEN_FAILED;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_STREAM_RECONFI_START, address->nap, address->uap, address->lap, filename);
    memcpy(&open_address, address, sizeof(srv_bt_cm_bt_addr));

    bFound = mmi_a2dp_quiry_by_address(&open_address, &index);
    if(bFound && (g_srv_a2dp_cntx.dev_info[index].role == A2DP_ROLE_SOURCE))
    {
        //g_a2dp_reconfig_cfg, bit pool should use open cap, can not be reconfig
        bt_a2dp_audio_cap_struct audio_cap[2];

        //for the fast switch song
        g_a2dp_stream_stop = MMI_FALSE;

        //match audio cap
        if(filename != NULL)
        {
            if(srv_a2dp_get_aud_cfg(filename, &audio_cap[0], sbc_only) < 0)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_STREAM_RECONFI_START_CODEC, -1);
                return SRV_A2DP_OPEN_FAILED;
            }
            else
            {
                bSame = mmi_a2dp_cmp_aud_cfg(&audio_cap[0], &g_a2dp_reconfig_cfg);
                if((!bSame) && (g_srv_a2dp_cntx.dev_info[index].is_reconfig == KAL_TRUE))
                {
                    g_a2dp_stream_stop = MMI_TRUE;
                    return SRV_A2DP_OPEN_FAILED;
                }
            
                //only support SBC
                memcpy(&g_a2dp_reconfig_cfg, &audio_cap[0], sizeof(bt_a2dp_audio_cap_struct));
            }

        }
        else
        {
            if(srv_a2dp_get_aud_cfg_ex(sample_rate, (kal_bool)stereo, &audio_cap[0]) < 0)
            {
                MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_STREAM_RECONFI_START_CODEC, -2);
                return SRV_A2DP_OPEN_FAILED;
            }
            else
            {
                //only support SBC
                memcpy(&g_a2dp_reconfig_cfg, &audio_cap[0], sizeof(bt_a2dp_audio_cap_struct));
            }
        }

        //g_a2dp_reconfig_cfg, bit pool should use open cap, can not be reconfig
        if(g_a2dp_reconfig_cfg.codec_type == BT_A2DP_SBC)
        {
            memcpy(&(g_a2dp_reconfig_cfg.codec_cap.sbc.max_bit_pool), 
                &(g_srv_a2dp_cntx.dev_info[index].audio_cfg.codec_cap.sbc.max_bit_pool), 
                sizeof(U8));
            
            memcpy(&(g_a2dp_reconfig_cfg.codec_cap.sbc.min_bit_pool), 
                &(g_srv_a2dp_cntx.dev_info[index].audio_cfg.codec_cap.sbc.min_bit_pool), 
                sizeof(U8));
        }
        MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_STREAM_RECONFI_START_CODEC, g_a2dp_reconfig_cfg.codec_type);
        
        bSame = mmi_a2dp_cmp_aud_cfg(&(g_srv_a2dp_cntx.dev_info[index].audio_cfg), &g_a2dp_reconfig_cfg);
        if(bSame)
        {
            srv_a2dp_start_stream(&(g_srv_a2dp_cntx.dev_info[index].address));
            return SRV_A2DP_OPEN_DONE;
        }

        //state
        if(g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_STREAMING)
        {
            mmi_a2dp_pause_req(&(g_srv_a2dp_cntx.dev_info[index]));
            g_srv_a2dp_cntx.dev_info[index].is_reconfig = KAL_TRUE;
        }
        else if(g_srv_a2dp_cntx.dev_info[index].state == A2DP_STATE_OPEN)
        {
            mmi_a2dp_reconfig_req(&(g_srv_a2dp_cntx.dev_info[index]), &g_a2dp_reconfig_cfg);
            g_srv_a2dp_cntx.dev_info[index].is_reconfig = KAL_TRUE;
        }
        else
        {
            return SRV_A2DP_OPEN_FAILED;
        }
        
        return SRV_A2DP_OPEN_WAITING;
    }

    return SRV_A2DP_OPEN_FAILED;
    
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_source
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  callback            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_open_source(srv_bt_cm_bt_addr *bt_dev, MMI_BOOL connect_avrcp)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPEN_SOURCE);
    // no need callback cm when app connect a2dp, by the cm app design
    //g_a2dp_cm_notify = MMI_FALSE;
    cm_notify_callback = NULL;
    return mmi_a2dp_open_by_role(bt_dev, A2DP_ROLE_SOURCE, NULL, connect_avrcp);
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_open_sink
 * DESCRIPTION
 *  
 * PARAMETERS
 *  bt_dev              [IN]
 *  callback            [IN]
 *  immediate_callback  [IN]
 * RETURNS
 *  kal_int32
 *****************************************************************************/
S32 srv_a2dp_open_sink(srv_bt_cm_bt_addr *bt_dev, A2DP_SRV_CALLBACK callback, MMI_BOOL connect_avrcp)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_OPEN_SINK);
    cm_notify_callback = NULL;
    return mmi_a2dp_open_by_role(bt_dev, A2DP_ROLE_SINK, callback, connect_avrcp);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_connect_req
 * DESCRIPTION
 *  send a connect req to bluetooth task
 * PARAMETERS
 *  dev_addr        [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_a2dp_connect_req(srv_bt_cm_bt_addr dev_addr)
{
    #if !defined(__IOT__)
    cm_notify_callback = mmi_bt_dialor_connect_a2dp_src_cb;
    #endif
    mmi_a2dp_open_by_role(&dev_addr, A2DP_ROLE_SOURCE, NULL, MMI_FALSE);
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_a2dp_query_state
 * DESCRIPTION
 *  query a2dp state
 * PARAMETERS
 *  voide    
 * RETURNS
 *  void
 *****************************************************************************/
a2dp_state_enum srv_bt_a2dp_query_state(void)
{
    if(srv_a2dp_is_connected())
    {
        return A2DP_STATE_OPEN;
    }
    else if(srv_a2dp_is_streaming())
    {
        return A2DP_STATE_STREAMING;
    }
    else
    {
        return A2DP_STATE_IDLE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_is_connected_by_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_a2dp_is_connected_by_req(srv_bt_cm_bt_addr *address)
{
    kal_bool bFound = KAL_FALSE;
    U8 index = 0;

    if (!address)
    {
        return;
    }

    bFound = mmi_a2dp_quiry_by_address(address, &index);
    if (!bFound)
    {
        return;
    }

    return (MMI_BOOL)(g_srv_a2dp_cntx.dev_info[index].is_open_req);
}


#ifdef __BT_SPEAKER_SUPPORT__

MMI_BOOL srv_a2dp_sink_is_codec_open(void)
{
    return MMI_TRUE;
}

MMI_BOOL srv_a2dp_sink_is_streaming(void)
{
    U8 i = 0;
    
    for (i=0; i< MAX_A2DP_LINK_NUM; i++)
    {
        if ((g_srv_a2dp_cntx.dev_info[i].role == BT_A2DP_SINK) &&
            (g_srv_a2dp_cntx.dev_info[i].state == A2DP_STATE_STREAMING))
        {
            return KAL_TRUE;
        }
    }

    return MMI_FALSE;
}

void srv_a2dp_sink_open_codec(MMI_BOOL immediate)
{
    return;
}

void srv_a2dp_sink_close_codec(MMI_BOOL immediate)
{
    return;
}


void srv_a2dp_sink_resume_stream(void)
{
    return;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sink_set_callback_notifier
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
void srv_a2dp_sink_set_callback_notifier(srv_bt_cm_bt_addr *dev_addr, 
                                         A2DP_SRV_CALLBACK callback)
{
    kal_bool found;
    U8 index = 0;

    found = mmi_a2dp_quiry_by_address(dev_addr, &index);
    if (found)
    {
        g_srv_a2dp_cntx.dev_info[index].user_callback = callback;
    }
}

MMI_RET srv_a2dp_sink_handle_gsm_call_ind(srv_ucm_ind_evt_struct *ind)
{

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_GSM_CALL_IND, ind->ind_type);

    switch (ind->ind_type)
	{
		case SRV_UCM_INCOMING_CALL_IND:
		case SRV_UCM_OUTGOING_CALL_IND:
			g_gsm_call_active++;
			break;
		case SRV_UCM_RELEASE_IND:
			if(g_gsm_call_active > 0)
			{
				g_gsm_call_active--;
			}
			if(g_gsm_call_active == 0)
			{
			
                #if defined(__MMI_HF_SUPPORT__) && defined(__MMI_BT_AUDIO_SUPPORT__)
				if( (mdi_audio_is_background_play_suspended() == MMI_TRUE) &&
					(srv_bt_dialer_is_any_call() == MMI_FALSE) )
				{
				    if(g_a2dp_streaming_suspended == MMI_TRUE)
					{
                    #ifdef __MMI_AVRCP_SUPPORT__
						mmi_a2dp_send_avrcp_cmd(SRV_AVRCP_POP_PLAY);
                    #endif
                        g_a2dp_streaming_suspended = MMI_FALSE;

                    }
				}
                #endif
			}
			break;
		default:
			break;
	}

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  srv_a2dp_sink_dialer_call_interrupt_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  kal_bool
 *****************************************************************************/
MMI_RET srv_a2dp_sink_dialer_call_interrupt_hdlr(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_BT_CALL_INTERRUPT_HDLR, g_a2dp_suspended_by_call);

    if(g_a2dp_suspended_by_call)
    {
        if (A2DP_STATE_OPEN == g_srv_a2dp_cntx.dev_info[g_call_suspend_index].state)
        {
            g_srv_a2dp_cntx.dev_info[g_call_suspend_index].state = A2DP_STATE_STREAMING;

            
            mmi_a2dp_open_codec(&(g_srv_a2dp_cntx.dev_info[g_call_suspend_index].audio_cfg),
                                g_srv_a2dp_cntx.dev_info[g_call_suspend_index].stream_hdl,
                                g_srv_a2dp_cntx.dev_info[g_call_suspend_index].role,
                                MMI_TRUE);

            mmi_a2dp_notify(&(g_srv_a2dp_cntx.dev_info[g_call_suspend_index].address),
                            g_srv_a2dp_cntx.dev_info[g_call_suspend_index].user_callback,
                            SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND);
        }

        g_a2dp_suspended_by_call = MMI_FALSE;
    }
    return MMI_RET_OK;
}

#endif  // __BT_SPEAKER_SUPPORT__

#endif //__MMI_A2DP_SUPPORT__
