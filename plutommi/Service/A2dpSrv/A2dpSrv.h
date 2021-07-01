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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#ifndef __A2DP_SRV_H__
#define __A2DP_SRV_H__
#include "stack_msgs.h"
#include "bluetooth_a2dp_struct.h"
#include "A2dpSrvGProt.h"
#include "BtcmSrvGprot.h"
#include "BtDialerSrvGprot.h"
#include "MMI_media_app_trc.h"
#include "DebugInitDef_Int.h"
#include "AvrcpSrvGprot.h"

/****************************************************************************
* data define
****************************************************************************/
//#define MAX_A2DP_SRC_NUM      (MAX_A2DP_SRC_SEP_NUM)
//#define MAX_A2DP_SINK_NUM     (MAX_A2DP_SINK_SEP_NUM)
//#define MAX_A2DP_LINK_NUM     (MAX_A2DP_DEV_NUM)

#if defined(SBC_DECODE)
    #define SBC_SINK_CODEC (1)
#else
    #define SBC_SINK_CODEC (0)
#endif

#if defined(AAC_DECODE) && !defined (__MMI_WEARABLE_DEVICE__)
    #define AAC_SINK_CODEC (1)
#else
    #define AAC_SINK_CODEC (0)
#endif

#if defined(DAF_DECODE) && !defined (__MMI_WEARABLE_DEVICE__)
    #define MP3_SINK_CODEC (1)
#else
    #define MP3_SINK_CODEC (0)
#endif


#ifdef __MMI_BT_SPEAKER_SUPPORT__
#define MAX_A2DP_SRC_LINK_NUM   (1)
#define MAX_A2DP_SNK_LINK_NUM   (1)
#define MAX_A2DP_LINK_NUM       (__BT_MAX_LINK_NUM__)
#else
#define MAX_A2DP_SRC_LINK_NUM   (1)
#define MAX_A2DP_SNK_LINK_NUM   (0)
#define MAX_A2DP_LINK_NUM       (1)
#endif

#ifdef __MMI_BT_SPEAKER_SUPPORT__
#define A2DP_SRC_CODEC_NUM   (1)
#define A2DP_SNK_CODEC_NUM   (SBC_SINK_CODEC + AAC_SINK_CODEC + MP3_SINK_CODEC)
#else
#define A2DP_SRC_CODEC_NUM   (1)
#define A2DP_SNK_CODEC_NUM   (0)
#endif

#define MAX_A2DP_SRC_SEP_NUM    (A2DP_SRC_CODEC_NUM * MAX_A2DP_SRC_LINK_NUM)
#define MAX_A2DP_SNK_SEP_NUM    (A2DP_SNK_CODEC_NUM * MAX_A2DP_SNK_LINK_NUM)

#define A2DP_SRV_PLAY_DUR_TIME (300)


#define MMI_A2DP_MESSAGE_TRANS(x) \
{                                 \
    MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_A2DP_SRV_MSG_REPORT, __LINE__, x); \
}


typedef struct
{
    a2dp_dev_info_struct     dev_info[MAX_A2DP_LINK_NUM];
    kal_bool                 ctx_actived;
    kal_bool                 deactive_pending;
    kal_bool                 is_inquiry;
    kal_bool                 need_reconfig;
    kal_bool                 init_from_cm;
    a2dp_codec_enum          codec_opened;
    kal_uint32               codec_seq_no;
    A2DP_SRV_CALLBACK        default_callback;
    A2DP_SRV_CALLBACK        media_callback;
    A2DP_SRV_CHECK_OUTPUT_CALLBACK    check_output_callback;
}a2dp_ctx_struct;


typedef struct
{
    srv_bt_cm_bt_addr address;
    A2DP_SRV_CALLBACK func;
    srv_a2dp_callback_event_enum evt;
}a2dp_app_notify_struct;


/****************************************************************************
* extern data define
****************************************************************************/
extern const bt_a2dp_sbc_codec_cap_struct sbc_cap[1];
#if defined(__MMI_BT_SPEAKER_SUPPORT__)
extern const bt_a2dp_mp3_codec_cap_struct mp3_cap[1];
extern const bt_a2dp_aac_codec_cap_struct aac_cap[1];
#endif

#if defined(__MMI_BT_SPEAKER_SUPPORT__)
extern const bt_a2dp_sbc_codec_cap_struct sbc_cap_snk[1];
extern const bt_a2dp_mp3_codec_cap_struct mp3_cap_snk[1];
extern const bt_a2dp_aac_codec_cap_struct aac_cap_snk[1];
#endif

/****************************************************************************
* function define
****************************************************************************/
static void mmi_a2dp_start_req(a2dp_dev_info_struct *dev_info);
static void mmi_a2dp_close_req(a2dp_dev_info_struct *dev_info);
static void mmi_a2dp_pause_req(a2dp_dev_info_struct *dev_info);
static void mmi_a2dp_abort_req(a2dp_dev_info_struct *dev_info);
static void mmi_a2dp_close_codec(a2dp_role_enum role);
static a2dp_state_enum mmi_a2dp_global_state(void);
static void mmi_a2dp_reset_dev_info(U8 index);
static void srv_a2dp_get_connect_dev_info_by_index(a2dp_dev_info_struct* info, U8 index);
static void mmi_a2dp_reset_ctx(void);
static kal_bool mmi_a2dp_cmp_address(srv_bt_cm_bt_addr *bt_addr1, srv_bt_cm_bt_addr *bt_addr2);
static kal_bool mmi_a2dp_quiry_streaming_dev(U8 *pIndex);
static kal_bool mmi_a2dp_quiry_by_handle(U8 stream_hdl, U8 *pIndex);
static kal_bool mmi_a2dp_quiry_by_address(srv_bt_cm_bt_addr *address, U8 *pIndex);
static kal_bool mmi_a2dp_alloc_resource(srv_bt_cm_bt_addr *address, a2dp_role_enum local_role, U8 *pIndex);
#ifdef __MMI_AVRCP_SUPPORT__
static void mmi_a2dp_connect_avrcp(srv_bt_cm_bt_addr address, a2dp_role_enum role);
static void mmi_a2dp_connect_avrcp_cb(srv_bt_cm_bt_addr *address, srv_avrcp_connectivity_notify_result evt);
#endif
static void mmi_a2dp_delay_open_callback_hdlr();
static void mmi_a2dp_notify(srv_bt_cm_bt_addr *address, A2DP_SRV_CALLBACK notify_func, srv_a2dp_callback_event_enum event);
static void mmi_a2dp_notify_cm(srv_bt_cm_bt_addr *address, MMI_BOOL result,MMI_BOOL is_connect,MMI_BOOL is_indicate, MMI_BOOL match_cm_req);
static void mmi_a2dp_open_codec(bt_a2dp_audio_cap_struct *cfg,kal_uint8 stream_handle,a2dp_role_enum role,kal_bool immediate);
static void mmi_a2dp_get_dev_info_by_index(a2dp_dev_info_struct* info, U8 index);
static void mmi_a2dp_reconfig_req(a2dp_dev_info_struct *dev_info, bt_a2dp_audio_cap_struct *audio_cap);
static S32 mmi_a2dp_open_by_role(srv_bt_cm_bt_addr *address, a2dp_role_enum local_role, A2DP_SRV_CALLBACK cb_func,MMI_BOOL connect_avrcp);
static void mmi_a2dp_enable_sco(void);
static void mmi_a2dp_transfer_data(void);
static void mmi_a2dp_check_audio_sync(void); // audio-sync add

extern void mmi_a2dp_stream_start_sink_codec_req(U8 stream_handle);
extern void mmi_a2dp_stream_stop_sink_codec_req(U8 stream_handle);


#ifdef __MMI_BT_AUDIO_VIA_SCO__
srv_a2dp_open_result_enum srv_a2dp_open_audio_via_sco(void);
#endif

/****************************************************************************
* extern function define
****************************************************************************/
extern void aud_send_bt_close_codec_req(module_type src_mod_id);
extern void aud_send_bt_open_codec_req(module_type src_mod_id,
                                       bt_a2dp_audio_cap_struct *cfg,
                                       kal_uint8 stream_handle,
                                       kal_bool immediate,
                                       kal_uint32 seq_no);

#if defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
extern void mmi_btspeaker_set_volume_handler();
extern void mmi_bt_sepaker_power_off(S32 result, void *user_data);
#endif
extern void mdi_bt_speaker_power_on(void);
extern void mdi_bt_speaker_power_off(void);

#endif //__A2DP_SRV_H__
