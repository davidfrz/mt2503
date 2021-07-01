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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
#include "MMI_features.h"
#ifdef __MMI_A2DP_SUPPORT__

#include "MMI_conn_app_trc.h"
#include "A2dpSrvUtil.h"

/****************************************************************************
* function define
****************************************************************************/
#define a2dp_send_msg_to_bt(msg_id, local_param_ptr) a2dp_send_msg(MOD_MMI, MOD_BT, BT_A2DP_SAP, (msg_id), (local_param_ptr))

/*****************************************************************************
 * FUNCTION
 *  a2dp_send_msg
 * DESCRIPTION
 *  
 * PARAMETERS
 *  src_id              [IN]        
 *  dst_id              [IN]        
 *  sap_id              [IN]        
 *  msg_id              [IN]        
 *  local_param_ptr     [IN]         
 * RETURNS
 *  void
 *****************************************************************************/
static void a2dp_send_msg(module_type src_id,
                          module_type dst_id,
                          U16 sap_id,
                          U16 msg_id,
                          void *local_param_ptr)
{
    ilm_struct *ilm_ptr = allocate_ilm(src_id);

    ilm_ptr->src_mod_id = src_id;
    ilm_ptr->dest_mod_id = dst_id;
    ilm_ptr->sap_id = (sap_type)sap_id;
    ilm_ptr->msg_id = (msg_type) msg_id;
    ilm_ptr->local_para_ptr = (local_para_struct*) local_param_ptr;
    ilm_ptr->peer_buff_ptr = (peer_buff_struct*) NULL;

    msg_send_ext_queue(ilm_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_activate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_activate_req(bt_a2dp_audio_cap_struct src_aud_cap[],
                                  bt_a2dp_audio_cap_struct sink_aud_cap[],
                                  U8 src_sep_num,
                                  U8 sink_sep_num)
{
    bt_a2dp_activate_req_struct *pMsg = NULL;
    U8 i = 0;

    pMsg = (bt_a2dp_activate_req_struct*)
            construct_local_para(sizeof(bt_a2dp_activate_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }
    
    pMsg->src_sep_num = src_sep_num;
    pMsg->sink_sep_num = sink_sep_num;

    for (i=0; i<src_sep_num; i++)
    {
        memcpy(&(pMsg->local_src_sep[i]),
               &(src_aud_cap[i]),
               sizeof(bt_a2dp_audio_cap_struct));
    }

    for (i=0; i<sink_sep_num; i++)
    {
        memcpy(&(pMsg->local_sink_sep[i]),
               &(sink_aud_cap[i]),
               sizeof(bt_a2dp_audio_cap_struct));
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_ACTIVATE_REQ);
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_ACTIVATE_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_deactivate_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_deactivate_req()
{
    bt_a2dp_deactivate_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_deactivate_req_struct*)
            construct_local_para(sizeof(bt_a2dp_deactivate_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_DEACTIVATE_REQ);
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_DEACTIVATE_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_open_req(bt_addr_struct *device_addr, U8 local_role)
{
    bt_a2dp_stream_open_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_open_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_open_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_OPEN_REQ, local_role);
    memcpy(&(pMsg->device_addr), device_addr, sizeof(bt_addr_struct));
    pMsg->local_role = local_role;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_OPEN_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_open_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_start_req(U8 stream_handle)
{
    bt_a2dp_stream_start_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_start_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_start_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_START_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_START_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_pause_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_pause_req(U8 stream_handle)
{
    bt_a2dp_stream_pause_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_pause_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_pause_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_PAUSE_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_PAUSE_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_abort_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_abort_req(U8 stream_handle)
{
    bt_a2dp_stream_abort_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_abort_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_abort_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_ABORT_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_ABORT_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_reconfig_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_reconfig_req(U8 stream_handle, bt_a2dp_audio_cap_struct *audio_cap)
{
    bt_a2dp_stream_reconfig_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_reconfig_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_reconfig_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_RECONFIG_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    memcpy(&(pMsg->audio_cap), audio_cap, sizeof(bt_a2dp_audio_cap_struct));
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_RECONFIG_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_close_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_close_req(U8 stream_handle)
{
    bt_a2dp_stream_close_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_close_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_close_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_CLOSE_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_CLOSE_REQ, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 btmtk_a2dp_send_stream_start_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_start_sink_codec_req(U8 stream_handle)
{
    bt_a2dp_stream_codec_start_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_codec_start_req_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_codec_start_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_START_SINK_CODEC_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_SINK_CODEC_START_REQ, (void*)pMsg);
}


/*****************************************************************************
 * FUNCTION
 btmtk_a2dp_send_stream_stop_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_stop_sink_codec_req(U8 stream_handle)
{
    bt_a2dp_sink_codec_stop_req_struct *pMsg = NULL;

    pMsg = (bt_a2dp_sink_codec_stop_req_struct*)
            construct_local_para(sizeof(bt_a2dp_sink_codec_stop_req_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_STOP_SINK_CODEC_REQ, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_SINK_CODEC_STOP_REQ, (void*)pMsg);
}



/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_open_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_open_res(U8 stream_handle, U16 accept)
{
    bt_a2dp_stream_open_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_open_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_open_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_OPEN_RES, stream_handle, accept);
    pMsg->stream_handle = stream_handle;
    pMsg->accept = accept;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_OPEN_RES, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_start_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_start_res(U8 stream_handle, U16 result)
{
    bt_a2dp_stream_start_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_start_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_start_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_START_RES, stream_handle, result);
    pMsg->stream_handle = stream_handle;
    pMsg->result = result;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_START_RES, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_pause_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_pause_res(U8 stream_handle, U16 result)
{
    bt_a2dp_stream_pause_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_pause_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_pause_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_PAUSE_RES, stream_handle, result);
    pMsg->stream_handle = stream_handle;
    pMsg->result = result;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_PAUSE_RES, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_close_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_close_res(U8 stream_handle, U16 result)
{
    bt_a2dp_stream_close_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_close_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_close_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_CLOSE_RES, stream_handle, result);
    pMsg->stream_handle = stream_handle;
    pMsg->result = result;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_CLOSE_RES, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_abort_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_abort_res(U8 stream_handle)
{
    bt_a2dp_stream_abort_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_abort_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_abort_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_ABORT_RES, stream_handle);
    pMsg->stream_handle = stream_handle;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_ABORT_RES, (void*)pMsg);
}

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_reconfig_res
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_reconfig_res(U8 stream_handle, U16 result)
{
    bt_a2dp_stream_reconfig_res_struct *pMsg = NULL;

    pMsg = (bt_a2dp_stream_reconfig_res_struct*)
            construct_local_para(sizeof(bt_a2dp_stream_reconfig_res_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_RECONFIG_RES, stream_handle, result);
    pMsg->stream_handle = stream_handle;
    pMsg->result = result;
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_STREAM_RECONFIG_RES, (void*)pMsg);
}

// audio-sync begin
/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_sync_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_sync_req(kal_bool sync, U8 state)
{
    bt_a2dp_audio_sync_set_struct *pMsg = NULL;

    pMsg = (bt_a2dp_audio_sync_set_struct*)
            construct_local_para(sizeof(bt_a2dp_audio_sync_set_struct), TD_CTRL);
    if (!pMsg)
    {
        return;
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, MMI_TRC_A2DP_SRV_SEND_AUDIO_SYNC_REQ, sync, state);
    pMsg->audio_sync_flag = (U8)sync;
    pMsg->dialer_index = state;
    
    a2dp_send_msg_to_bt((U16)MSG_ID_BT_A2DP_AUDIO_SYNC_SET, (void*)pMsg);
}
// audio-sync end

#endif //__MMI_A2DP_SUPPORT__
