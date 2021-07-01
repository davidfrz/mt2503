/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *   bt_serial_sync_drv.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   The BT serial playback audio synchronization driver
 *
 * Author:
 * -------
 * -------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "l1audio.h"

#if defined(__BT_SERIAL_PLAYBACK_AUDIO_SYNC__)
#include "bt_serial_sync.h"
#include "sbc_dec_exp.h"
#include "audio_def.h"
#include "media.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

#ifndef MINIMUM
#define MINIMUM(a,b) ((a) < (b) ? (a) : (b))
#endif

#define BT_CLK_NORM_DIFF(t_targ, t_curr) (t_targ - t_curr)
#define BT_CLK_WRAP_DIFF(t_targ, t_curr) (BT_CLK_UPPER_BOUND + t_targ - t_curr)
#define BT_CLK_MAX_DIFF     0x001D4C00  // 10 minutes

#define BT_CLK_BTD1_DELAY   1280    // 400 ms
#define BT_CLK_BTD2_DELAY   1280    // 400 ms

static struct {
    kal_bool b_apply_delay;
    kal_uint32 channel_type;
    kal_uint32 start_time;
    kal_uint32 offset;
    kal_uint32 silence_cnt;
} BT_SERIAL_SYNC_STATIC;

void BT_Serial_Sync_Init (void)
{
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_INIT);
    BT_SERIAL_SYNC_STATIC.b_apply_delay = KAL_FALSE;
    BT_SERIAL_SYNC_STATIC.channel_type = PLAYBACK_CH_NORMAL;
    BT_SERIAL_SYNC_STATIC.start_time = 0xFFFFFFFF;
    BT_SERIAL_SYNC_STATIC.offset = 0xFFFFFFFF;
    BT_SERIAL_SYNC_STATIC.silence_cnt = 0;
    
    return;
}

kal_bool BT_Serial_Sync_Is_Applied (void)
{
    return BT_SERIAL_SYNC_STATIC.b_apply_delay;
}

kal_uint32 BT_Serial_Sync_Get_Channel_Type (void)
{
    return BT_SERIAL_SYNC_STATIC.channel_type;
}

kal_uint32 BT_Serial_Sync_Get_Start_Time (void)
{
    return BT_SERIAL_SYNC_STATIC.start_time;
}

kal_uint32 BT_Serial_Sync_Get_Offset (void)
{
    return BT_SERIAL_SYNC_STATIC.offset;
}

kal_uint32 BT_Serial_Sync_Get_Silence_Count (void)
{
    return BT_SERIAL_SYNC_STATIC.silence_cnt;
}

void BT_Serial_Sync_Set_Silence_Count (kal_uint32 silence_cnt)
{
    BT_SERIAL_SYNC_STATIC.silence_cnt = silence_cnt;
    
    return;
}

static kal_int32 BT_Serial_Sync_Calculate_BT_Clock_Diff (kal_int32 clk_curr, kal_int32 clk_targ)
{
    kal_int32 norm_diff = BT_CLK_NORM_DIFF(clk_targ, clk_curr);
    kal_int32 wrap_diff = BT_CLK_WRAP_DIFF(clk_targ, clk_curr);
    kal_int32 diff;
    
    if (norm_diff > 0 && norm_diff < BT_CLK_MAX_DIFF)
    {
        diff = norm_diff;
    }
    else if (wrap_diff > 0 && wrap_diff < BT_CLK_MAX_DIFF)
    {
        diff = wrap_diff;
    }
    else
    {
        diff = 0;
    }
    
    return diff;
}

void BT_Serial_Sync_Waiting_Loop(void)
{
    if (BT_Serial_Sync_Is_Applied())
    {
        kal_uint32 start_time = BT_Serial_Sync_Get_Start_Time();
        kal_uint32 offset = BT_Serial_Sync_Get_Offset();
        kal_uint32 bt_clk = BTIF_Get_BT_HW_Native_Clk();
        kal_uint32 master_clk = (bt_clk + offset) & BT_CLK_MASK;
        
        kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 0, BT_CLK_UPPER_BOUND);
        
        if (master_clk < BT_CLK_UPPER_BOUND && start_time < BT_CLK_UPPER_BOUND)
        {
            kal_int32 clk_curr = (kal_int32)master_clk;
            kal_int32 clk_targ = (kal_int32)start_time;
            kal_int32 diff = BT_Serial_Sync_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
            kal_int32 timeout_cnt;
            
            timeout_cnt = 500;  // about 2.3 sec (= 500 x 4.615 ms)
            
            kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 1, timeout_cnt);
            
            while (diff > BT_CLK_SLEEP_TICK)
            {
                kal_sleep_task(1);
                bt_clk = BTIF_Get_BT_HW_Native_Clk();
                master_clk = (bt_clk + offset) & BT_CLK_MASK;
                clk_curr = (kal_int32)master_clk;
                diff = BT_Serial_Sync_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
                if (--timeout_cnt <= 0)
                {
                    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 2, diff);
                    break;
                }
            }
            
            timeout_cnt = 1000; // Experimental value to avoid infinite loop
            
            kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 3, timeout_cnt);
            
            while (diff > 0)
            {
                bt_clk = BTIF_Get_BT_HW_Native_Clk();
                master_clk = (bt_clk + offset) & BT_CLK_MASK;
                clk_curr = (kal_int32)master_clk;
                diff = BT_Serial_Sync_Calculate_BT_Clock_Diff (clk_curr, clk_targ);
                if (--timeout_cnt <= 0)
                {
                    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 4, diff);
                    break;
                }
            }
        }
        
        kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PCMSINK_START, 5, 0);
    }
    
    return;
}

void Media_Set_A2DP_Stream_Start_Time(A2DP_Stream_Start_Param *p_param)
{
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_SET_START_TIME, p_param->channel_type, p_param->start_time, p_param->offset);
    BT_SERIAL_SYNC_STATIC.b_apply_delay = KAL_TRUE;
    BT_SERIAL_SYNC_STATIC.channel_type = p_param->channel_type;
    BT_SERIAL_SYNC_STATIC.start_time = p_param->start_time;
    BT_SERIAL_SYNC_STATIC.offset = p_param->offset;
    BT_SERIAL_SYNC_STATIC.silence_cnt = 0;
    
    return;
}

void Media_Set_Channel_Type(kal_uint32 channel_type)
{
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_SET_CH_TYPE, channel_type);
    BT_SERIAL_SYNC_STATIC.channel_type = channel_type;
    
    return;
}

kal_uint32 Media_Get_A2DP_Reserved_Bytes(void)
{   // 2 + 4 = sync word + start time
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_GET_RESERVED_BYTE, 6);
    return 6;
}

kal_uint32 Media_Get_A2DP_Delay_Timing(A2DP_Stream_Device device)
{
    kal_uint32 delay;
    
    if (device == A2DP_STREAM_DEVICE_BTD1)
    {
        delay = BT_CLK_BTD1_DELAY;
    }
    else // if (device == A2DP_STREAM_DEVICE_BTD2)
    {
        delay = BT_CLK_BTD2_DELAY;
    }
    
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_GET_DELAY_TIMING, device, delay);
    
    return delay;
}

kal_uint32 Media_Add_A2DP_Next_Device_Start_Time(kal_uint8 *p_in, kal_uint8 *p_out, kal_uint32 payload_len, kal_uint32 start_time)
{
    kal_uint32 result = 0;
    
    if (payload_len >= 6)
    {
        *p_out++ = 0x33;
        *p_out++ = 0x77;
        *p_out++ = (kal_uint8)((start_time >> 24) & 0x000000FF);
        *p_out++ = (kal_uint8)((start_time >> 16) & 0x000000FF);
        *p_out++ = (kal_uint8)((start_time >>  8) & 0x000000FF);
        *p_out++ = (kal_uint8)( start_time        & 0x000000FF);
        payload_len -= 6;
        while(payload_len-- > 0)
        {
            *p_out++ = *p_in++;
        }
    }
    else
    {
        result = 1;
    }
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_ADD_START_TIME, start_time, payload_len);
    return result;
}

kal_uint32 Media_Check_A2DP_Stream(kal_uint8 *p_payload, kal_uint32 payload_len)
{
    kal_uint32 start_time = 0xFFFFFFFF;
    
    if (payload_len >= 6)
    {
        kal_uint8 header[6];
        kal_uint32 payload_idx;
        
        for (payload_idx = 0; payload_idx < 6; payload_idx++)
        {
            header[payload_idx] = *p_payload++;
        }
        
        if (header[0] == 0x33 && header[1] == 0x77)
        {
            kal_uint32 byte_0 = ((kal_uint32)header[2] << 24) & 0xFF000000;
            kal_uint32 byte_1 = ((kal_uint32)header[3] << 16) & 0x00FF0000;
            kal_uint32 byte_2 = ((kal_uint32)header[4] <<  8) & 0x0000FF00;
            kal_uint32 byte_3 =  (kal_uint32)header[5]        & 0x000000FF;
            start_time = byte_0 | byte_1 | byte_2 | byte_3;
        }
    }
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_CHECK_STREAM, payload_len);
    return start_time;
}

kal_uint32 Media_A2DP_Get_Payload_Sample_Count(A2DP_Stream_Codec_Type codec_type, kal_uint8 *p_in, kal_uint32 payload_len)
{
    kal_int32 result = 0;
    kal_uint32 consumed = payload_len;
    kal_uint32 smpl_cnt = 0;
    
    if (codec_type == A2DP_STREAM_SBC_DEC)
    {
        result = SbcDec_GetMediaPayloadSampleCount (p_in, &consumed, &smpl_cnt);
    }
    
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_GET_SMPL_CNT, codec_type, result, payload_len, consumed, smpl_cnt);
    
    return smpl_cnt;
}

kal_uint32 Media_A2DP_Get_Silence_Payload_Length(A2DP_Stream_Codec_Type codec_type, kal_uint32 silence_cnt)
{
    kal_uint32 silence_len = 0;
    
    if (codec_type == A2DP_STREAM_SBC_DEC)
    {
        silence_len = SbcEnc_GetSilencePayloadLength (silence_cnt);
    }
    
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_GET_SILENCE_LEN, codec_type, silence_cnt, silence_len);
    
    return silence_len;
}

kal_int32 Media_A2DP_Produce_Silence_Payload(A2DP_Stream_Codec_Type codec_type, kal_uint8 *p_out, kal_uint32 silence_cnt, kal_uint32 silence_len)
{
    kal_int32 result = 0;
    kal_int32 produced = silence_len;
    
    if (codec_type == A2DP_STREAM_SBC_DEC)
    {
        result = SbcEnc_ProduceSilencePayload (silence_cnt, p_out, &produced);
    }
    
    kal_brief_trace(TRACE_GROUP_BT_AUD_SYNC, BT_AUD_SYNC_PRODUCE_SILENCE, codec_type, result, silence_cnt, silence_len, produced);
    
    return result;
}

#else   // defined(__BT_SERIAL_PLAYBACK_AUDIO_SYNC__)
void Media_Set_A2DP_Stream_Start_Time(A2DP_Stream_Start_Param *p_param)
{
    return;
}

void Media_Set_Channel_Type(kal_uint32 channel_type)
{
    return;
}

kal_uint32 Media_Get_A2DP_Reserved_Bytes(void)
{
    return 0;
}

kal_uint32 Media_Get_A2DP_Delay_Timing(A2DP_Stream_Device device)
{
    return 0;
}

kal_uint32 Media_Add_A2DP_Next_Device_Start_Time(kal_uint8 *p_in, kal_uint8 *p_out, kal_uint32 payload_len, kal_uint32 start_time)
{
    return 0;
}

kal_uint32 Media_Check_A2DP_Stream(kal_uint8 *p_payload, kal_uint32 payload_len)
{
    return 0;
}

kal_uint32 Media_A2DP_Get_Payload_Sample_Count(A2DP_Stream_Codec_Type codec_type, kal_uint8 *p_in, kal_uint32 payload_len)
{
    return 0;
}

kal_uint32 Media_A2DP_Get_Silence_Payload_Length(A2DP_Stream_Codec_Type codec_type, kal_uint32 silence_cnt)
{
    return 0;
}

kal_int32 Media_A2DP_Produce_Silence_Payload(A2DP_Stream_Codec_Type codec_type, kal_uint8 *p_out, kal_uint32 silence_cnt, kal_uint32 silence_len)
{
    return 0;
}
#endif  // defined(__BT_SERIAL_PLAYBACK_AUDIO_SYNC__)

