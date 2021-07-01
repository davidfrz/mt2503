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
 * A2dpSrvGprot.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * Global Export Function
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef __A2DP_SRV_GPROT_H__
#define __A2DP_SRV_GPROT_H__

#include "BtcmSrvGprot.h"
#include "kal_general_types.h"
#include "MMIDataType.h"
#include "UcmSrvGprot.h"
#include "bluetooth_a2dp_struct.h"
#include "BTDialerSrvGprot.h"

#ifdef __cplusplus
extern "C"
{
#endif


#define MMI_TRACE_BT_ADDREES(lap,uap,nap) MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_A2DP_SRV_BT_ADDRESS, lap, uap, nap, __LINE__)

typedef void(*A2DP_SRV_CALLBACK)(srv_bt_cm_bt_addr *address, kal_int32 result);
//typedef void(*A2DP_SRV_CALLBACK_EX)(srv_bt_cm_bt_addr *address, kal_int32 result);
typedef MMI_BOOL(*A2DP_SRV_CHECK_OUTPUT_CALLBACK)(void);
typedef MMI_BOOL(*A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK)(void);
typedef srv_bt_cm_bt_addr*(*A2DP_SRV_GET_BT_HEADSET_CALLBACK)(void);
typedef void(*srv_a2dp_sink_app_callback)(S32 avrcp_ind);
typedef void(*srv_bt_a2dp_cm_connect_notify)(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_connection_type conn_type,MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate); 


typedef enum
{
    A2DP_STATE_IDLE,
    A2DP_STATE_ABORTING,
    A2DP_STATE_OPEN,
    A2DP_STATE_STREAMING
} a2dp_state_enum;

typedef enum
{
    A2DP_ROLE_SOURCE = BT_A2DP_SOURCE,
    A2DP_ROLE_SINK   = BT_A2DP_SINK,
    A2DP_ROLE_NONE
} a2dp_role_enum;

typedef enum
{
    A2DP_CODEC_NONE,
    A2DP_CODEC_SRC,
    A2DP_CODEC_SINK
} a2dp_codec_enum;


typedef enum
{
    A2DP_WAIT_NONE,
    A2DP_WAIT_OPEN_CNF,
    A2DP_WAIT_START_CNF,
    A2DP_WAIT_PAUSE_CNF,
    A2DP_WAIT_CLOSE_CNF,
    A2DP_WAIT_ABORT_CNF,
    A2DP_WAIT_RECONFIG_CNF,
    A2DP_WAIT_DISCONNECT_CNF
} a2dp_waitting_cnf_enum;

/* Open result */
typedef enum
{
    SRV_A2DP_OPEN_WAITING,      /* wiat for result. result will be pass to client through callback */
    SRV_A2DP_OPEN_FAILED,       /* open failed */
    SRV_A2DP_OPEN_DONE          /* open done, A2DP streaming started */
} srv_a2dp_open_result_enum;


/* Open result */
typedef enum
{
    SRV_A2DP_CLOSE_WAITING,      /* wiat for result. result will be pass to client through callback */
    SRV_A2DP_CLOSE_FAILED,       /* open failed */
    SRV_A2DP_CLOSE_DONE          /* open done, A2DP streaming started */
} srv_a2dp_close_result_enum;


typedef enum
{
    A2DP_REVERSE_STEP_NONE,
    A2DP_REVERSE_STEP_CLOSE,
    A2DP_REVERSE_STEP_OPEN,
    A2DP_REVERSE_STEP_STREAMING
}a2dp_reverse_state_enum;


/* The result or event of A2DP streaming, which will pass to clinet through registered callback */
typedef enum
{
    SRV_A2DP_CALLBACK_EVENT_OPEN_OK,                    /* open success */
    SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED,                /* open faied */
    SRV_A2DP_CALLBACK_EVENT_OPEN_STOPPED,               /* open stopped by client */
    SRV_A2DP_CALLBACK_EVENT_OPEN_CANCELED,              /* open canceled by another audio playback request */
    SRV_A2DP_CALLBACK_EVENT_STREAM_SUSPEND_IND,         /* streaming suspend indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_START_IND,           /* streaming start indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_PAUSE_IND,           /* streaming pause indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_CLOSE_IND,           /* streaming close indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_STREAM_ABORT_IND,           /* streaming abort indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_UNEXPECTED_DISCONNECT_IND,  /* streaming disconnect indication by lower layer (ex: the other BT device) */
    SRV_A2DP_CALLBACK_EVENT_INQUIRY_START_IND,          /* BT CM starts to inquiry BT devices */
    SRV_A2DP_CALLBACK_EVENT_INQUIRY_STOP_IND,           /* BT CM stops inquirying BT devices */
    SRV_A2DP_CALLBACK_EVENT_OPEN_SCO,                   /* A2DP connect fail but HFP SCO is connected successfully */
/* DOM-NOT_FOR_SDK-BEGIN */
    SRV_A2DP_CALLBACK_EVENT_SECURITY_BLOCK              /* Connect fail due to stack security block, clinet will not get thie result, it will be SRV_A2DP_CALLBACK_EVENT_OPEN_FAILED instead */
/* DOM-NOT_FOR_SDK-END */
} srv_a2dp_callback_event_enum;



typedef enum {
   SRV_A2DP_SINK_NONE,
   SRV_A2DP_SINK_DATA_REQUEST,
   SRV_A2DP_SINK_DATA_NOTIFICATION,
   SRV_A2DP_SINK_END, //3
   SRV_A2DP_SINK_ERROR, //4
   SRV_A2DP_SINK_DECODER_UNSUPPORT,
   SRV_A2DP_SINK_REPEATED,
   SRV_A2DP_SINK_TERMINATED, //7
   SRV_A2DP_SINK_RESUME, //8
   SRV_A2DP_SINK_LED_ON,
   SRV_A2DP_SINK_LED_OFF,
   SRV_A2DP_SINK_VIBRATOR_ON,
   SRV_A2DP_SINK_VIBRATOR_OFF,
   SRV_A2DP_SINK_BACKLIGHT_ON,
   SRV_A2DP_SINK_BACKLIGHT_OFF,
   SRV_A2DP_SINK_EXTENDED_EVENT,
   SRV_A2DP_SINK_READ_ERROR,
   SRV_A2DP_SINK_UPDATE_DUR,
   SRV_A2DP_SINK_STOP_TIME_UP,
   SRV_A2DP_SINK_DEMO_TIME_UP,
   SRV_A2DP_SINK_BUFFER_UNDERFLOW,
   SRV_A2DP_SINK_READY_TO_PLAY,
   SRV_A2DP_SINK_DATA_REFILL
} srv_a2dp_sink_media_err_events;


typedef struct
{
    U8                       stream_hdl;
    S32                      cmgr_id;
    srv_bt_cm_bt_addr        address;
    a2dp_role_enum           role;
    a2dp_state_enum          state;
    a2dp_reverse_state_enum  reverse_state;
    a2dp_waitting_cnf_enum   waitting;
    bt_a2dp_audio_cap_struct audio_cfg;
    kal_bool                 is_connect_avrcp;
    kal_bool                 is_reconfig;
    kal_bool                 is_open_req;
    kal_bool                 close_pending;
    A2DP_SRV_CALLBACK        user_callback;
    srv_bt_a2dp_cm_connect_notify cm_callback;
} a2dp_dev_info_struct;


extern void srv_a2dp_init(void);

extern kal_bool srv_a2dp_quiry_by_role(a2dp_role_enum role, U8 *pIndex);

extern kal_bool srv_a2dp_quiry_by_role_ex(a2dp_role_enum role, srv_bt_cm_bt_addr *address);

extern void srv_a2dp_set_auto_disconnect_dalay(kal_uint16 msec);

extern void srv_bt_a2dp_connect_req(srv_bt_cm_bt_addr dev_addr);

extern a2dp_state_enum srv_bt_a2dp_query_state(void);

extern void srv_a2dp_set_bt_music_callback(srv_bt_cm_bt_addr *bt_dev, A2DP_SRV_CALLBACK callback);

extern void srv_a2dp_set_default_callback(A2DP_SRV_CALLBACK handler);

extern void srv_a2dp_set_app_callback(A2DP_SRV_CALLBACK handler);

extern void srv_a2dp_delete_app_callback(void);

extern void srv_a2dp_set_check_output_callback(A2DP_SRV_CHECK_OUTPUT_CALLBACK handler);

extern void srv_a2dp_get_dev_info_by_index(a2dp_dev_info_struct* info, U8 index);

extern void srv_a2dp_set_is_output_to_bt_callback(A2DP_SRV_IS_OUTPUT_TO_BT_CALLBACK handler);

extern void srv_a2dp_set_get_bt_headset_callback(A2DP_SRV_GET_BT_HEADSET_CALLBACK handler);

extern MMI_BOOL srv_a2dp_is_output_to_bt(void);

srv_bt_cm_bt_addr *srv_a2dp_get_connect_bt_addr(void);

extern MMI_BOOL srv_a2dp_is_bt_inquirying(void);

extern MMI_BOOL srv_a2dp_is_codec_open(void);

extern MMI_BOOL srv_a2dp_is_streaming(void);

extern MMI_BOOL srv_a2dp_is_mp3_configured(void);

mmi_ret srv_a2dp_sco_disconnected_event_hdlr(void *param);

U8 srv_a2dp_get_stream_handle(srv_bt_cm_bt_addr* bt_addr);

U8 srv_a2dp_get_role(srv_bt_cm_bt_addr* bt_addr);

S32 srv_a2dp_open_sink(srv_bt_cm_bt_addr *bt_dev, A2DP_SRV_CALLBACK callback, MMI_BOOL connect_avrcp);

S32 srv_a2dp_open_source(srv_bt_cm_bt_addr *bt_dev, MMI_BOOL connect_avrcp);

void srv_a2dp_sink_start_stream(void);

void srv_a2dp_sink_pause_stream(void);

void srv_a2dp_pause_stream_hdlr();

void srv_a2dp_disable_stream();

void srv_a2dp_enable_stream();

extern S32 srv_a2dp_open(srv_bt_cm_bt_addr *bt_dev, U16 sample_rate, U8 stereo, A2DP_SRV_CALLBACK callback, MMI_BOOL immediate_callback);

extern S32 srv_a2dp_open_ex(srv_bt_cm_bt_addr *bt_dev, WCHAR *filename, A2DP_SRV_CALLBACK callback, MMI_BOOL sbc_only, MMI_BOOL immediate_callback);

extern S32 srv_a2dp_close(MMI_BOOL notify_opener);

extern void srv_a2dp_open_codec(MMI_BOOL immediate);

extern void srv_a2dp_close_codec(void);

extern void srv_a2dp_pause(void);

extern void srv_a2dp_inquiry_start_callback(void);

extern void srv_a2dp_inquiry_stop_callback(void);

extern S32 srv_a2dp_close_ex(srv_bt_cm_bt_addr *address);
MMI_BOOL srv_a2dp_is_connected_by_req(srv_bt_cm_bt_addr *address);
MMI_BOOL srv_a2dp_is_connected(void);
MMI_BOOL srv_a2dp_sink_is_codec_open(void);
MMI_BOOL srv_a2dp_sink_is_streaming(void);

S32 srv_a2dp_reconfig_start_streaming(
            srv_bt_cm_bt_addr *address, 
            WCHAR* filename, 
            U16 sample_rate, 
            U8 stereo, 
            MMI_BOOL sbc_only);

void srv_a2dp_sink_open_codec(MMI_BOOL immediate);
void srv_a2dp_sink_close_codec(MMI_BOOL immediate);
void srv_a2dp_sink_reg_cb_err_evts(srv_a2dp_sink_app_callback cb_ptr);
void srv_a2dp_sink_avrcp_interface(S32 events);
void srv_a2dp_sink_resume_stream(void);
void srv_a2dp_sink_set_callback_notifier(srv_bt_cm_bt_addr *dev_addr, 
                                                 A2DP_SRV_CALLBACK callback);
MMI_RET srv_a2dp_sink_handle_gsm_call_ind(srv_ucm_ind_evt_struct *ind);

void srv_bt_a2dp_src_cm_connect_req(srv_bt_cm_bt_addr *dev_addr, 
                                              srv_bt_a2dp_cm_connect_notify srv_cm_cb);

void srv_bt_a2dp_sink_cm_connect_req(srv_bt_cm_bt_addr *dev_addr, 
                                              srv_bt_a2dp_cm_connect_notify srv_cm_cb);

void srv_bt_a2dp_cm_disconnect_req(srv_bt_cm_bt_addr *dev_addr, 
                                                srv_bt_a2dp_cm_connect_notify srv_cm_cb);


#ifdef __cplusplus
}
#endif

#endif /* __A2DP_SRV_GPROT_H__ */
