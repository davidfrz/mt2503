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
 * A2dpAdp.h
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __A2DP_UTIL_H__
#define __A2DP_UTIL_H__

#include "MMIDataType.h"
#include "Conversions.h"
#include "stack_msgs.h"
#include "bluetooth_a2dp_struct.h"
#include "bt_mmi.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"


/****************************************************************************
* data define
****************************************************************************/

/****************************************************************************
* function define
****************************************************************************/

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
                                  U8 sink_sep_num);

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
void btmtk_a2dp_send_deactivate_req();

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
void btmtk_a2dp_send_stream_open_req(bt_addr_struct *device_addr, U8 local_role);

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_start_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_start_req(U8 stream_handle);

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
void btmtk_a2dp_send_stream_pause_req(U8 stream_handle);

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
void btmtk_a2dp_send_stream_abort_req(U8 stream_handle);

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
void btmtk_a2dp_send_stream_reconfig_req(U8 stream_handle, bt_a2dp_audio_cap_struct *audio_cap);

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
void btmtk_a2dp_send_stream_close_req(U8 stream_handle);

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_start_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_start_sink_codec_req(U8 stream_handle);

/*****************************************************************************
 * FUNCTION
 *  btmtk_a2dp_send_stream_stop_sink_codec_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void btmtk_a2dp_send_stream_stop_sink_codec_req(U8 stream_handle);

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
void btmtk_a2dp_send_stream_open_res(U8 stream_handle, U16 accept);

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
void btmtk_a2dp_send_stream_start_res(U8 stream_handle, U16 result);


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
void btmtk_a2dp_send_stream_pause_res(U8 stream_handle, U16 result);

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
void btmtk_a2dp_send_stream_close_res(U8 stream_handle, U16 result);

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
void btmtk_a2dp_send_stream_abort_res(U8 stream_handle);

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
void btmtk_a2dp_send_stream_reconfig_res(U8 stream_handle, U16 result);

// audio-sync add
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
void btmtk_a2dp_send_stream_sync_req(kal_bool sync, U8 state);


#endif //__A2DP_UTIL_H__
