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

/*******************************************************************************
 * Filename:
 * ---------
 * aud_main.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file includes primary global variables of audio manager task.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef MED_NOT_PRESENT

#ifndef _AUD_MAIN_H
#define _AUD_MAIN_H

#include "kal_general_types.h"
#include "stack_config.h"
#include "med_struct.h"
#include "l1audio.h"
#include "kal_public_defs.h"
#include "med_global.h"
#include "fsal.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"

extern void aud_speech_enable_megaphone_req_hdlr(ilm_struct *ilm_ptr);


typedef enum
{
    AUD_EVT_NOWAIT             = 0x00000000,
    AUD_EVT_PLAY               = 0x00000001,
    AUD_EVT_STOP               = 0x00000002,
    AUD_EVT_RECORD             = 0x00000004,
    AUD_EVT_PAUSE              = 0x00000008,
    AUD_EVT_RESUME             = 0x00000010,
    AUD_EVT_BLOCK              = 0x00000020,
    AUD_EVT_FMR_ON             = 0x00000040,
    AUD_EVT_FMR_OFF            = 0x00000080,
    AUD_EVT_FMR_SET            = 0x00000100,
    AUD_EVT_FMR_MUTE           = 0x00000200,
    AUD_EVT_FMR_EVA_THRESHOLD  = 0x00000400,
    AUD_EVT_FMR_SET_CHANNEL    = 0x00000800,
    AUD_EVT_GET_DURATION       = 0x00001000,
    AUD_EVT_GET_VOLUME         = 0x00002000,
    AUD_EVT_SET_VOLUME         = 0x00004000,
    AUD_EVT_GET_PROGRESS_TIME  = 0x00008000,
    AUD_EVT_SET_PROGRESS_TIME  = 0x00010000,
    AUD_EVT_GET_SPECTRUM       = 0x00020000,
    AUD_EVT_BT_CLOSE_AUDIO     = 0x00040000,
    AUD_EVT_BT_TURN_OFF_AUDIO  = 0x00080000,
    AUD_EVT_IS_PURE_AUDIO      = 0x00100000,
    AUD_EVT_START_KT_DETECT    = 0x00200000,
    AUD_EVT_STOP_KT_DETECT     = 0x00400000,
    AUD_EVT_WAIT               = 0x00800000,  /* General wait event */
    #ifdef __VOICE_CHANGER_SUPPORT__
    AUD_VOICE_CHANGER_EVT_SET      = 0x01000000,
    #endif
    #ifdef __KARAOKE_NEED_KEEP_SRC_PATH__
    AUD_KARAOKE_EVT_SET      = 0x01000000
    #endif

	#ifdef __VAD_SUPPORT__
    AUD_VAD_EVT_SET      = 0x02000000
    #endif
}
aud_wait_event_enum;

typedef enum
{
    VRSI_EVT_INIT              = 0x00000001,
    VRSI_EVT_ADD_TAGS          = 0x00000002,
    VRSI_EVT_START_CMD_TRN     = 0x00000004,
    VRSI_EVT_START_CMD_RCG     = 0x00000008,
    VRSI_EVT_START_DIGIT_RCG   = 0x00000010,
    VRSI_EVT_START_DIGIT_ADAPT = 0x00000020,
    VRSI_EVT_PLAY_TAG          = 0x00000040,
    VRSI_EVT_PLAY_TTS          = 0x00000080,
    VRSI_EVT_GET_TAG_NUM       = 0x00000100,
    VRSI_EVT_GET_TAG_INFO      = 0x00000200,
    VRSI_EVT_DEL_TAGS          = 0x00000400,
    VRSI_EVT_RESET_TAGS        = 0x00000800,
    VRSI_EVT_SYNC_DB           = 0x00001000,
    VRSI_EVT_ABORT             = 0x00002000,
    VRSI_EVT_CLOSE             = 0x00004000,
    AUD_EVT_VR_GET_VER         = 0x00008000,
    AUD_EVT_VR_GET_PARAM       = 0x00010000,
    AUD_EVT_VR_SET_PARAM       = 0x00020000,
    AUD_EVT_VR_INIT_RCG        = 0x00040000,
    AUD_EVT_VR_INIT_TRN        = 0x00080000,
    AUD_EVT_VR_VOICE_IN        = 0x00100000,
    AUD_EVT_VR_DEL_TAG         = 0x00200000,
    AUD_EVT_VR_CHECK_TAG       = 0x00400000,
    AUD_EVT_VR_SYNC_DB         = 0x00800000,
    AUD_EVT_VR_PLAY_TAG        = 0x01000000,
    AUD_EVT_VR_GET_DIR         = 0x02000000,
    AUD_EVT_VR_ADD_TAG         = 0x04000000,
    AUD_EVT_VR_ABORT           = 0x08000000
}
vrsi_wait_event_enum;

typedef enum
{
    AUD_VR_STATE_IDLE,
    AUD_VR_STATE_TRN_SESSION,
    AUD_VR_STATE_RCG_SESSION,
    AUD_VR_NO_OF_STATE
} aud_vr_state_enum;

typedef enum
{
    AUD_VR_SD_SESSION_STAGE_NOT_READY,
    AUD_VR_SD_SESSION_STAGE_READY,
    AUD_VR_SD_SESSION_STAGE_PROCESS,
    AUD_VR_SD_SESSION_STAGE_WAIT,
    AUD_VR_SD_SESSION_STAGE_PROCESS_2ND,
    AUD_VR_SD_SESSION_NO_OF_STAGE
} aud_vr_sd_session_stage_enum;

typedef enum
{
    AUD_CTM_STATE_IDLE,
    AUD_CTM_STATE_READY,
    AUD_CTM_STATE_CONNECTING,
    AUD_CTM_STATE_CONNECTED,
    AUD_CTM_STATE_SENDING,
    AUD_CTM_NO_OF_STATE
} aud_ctm_state_enum;

typedef enum
{
    AUD_MMA_CHECK_MODE_ALL,
    AUD_MMA_CHECK_MODE_SINGLE
} aud_mma_check_mode_enum;

typedef struct
{
    kal_uint64 volume;       /* Volume */
    kal_wchar* file_name;    /* File name */
    kal_uint8* data_p;       /* Media data */
    kal_uint32 data_len;     /* The length of media data */
    void*      cache_p;      /* Cache table */
    kal_uint32 start_offset; /* Start time */
    kal_uint32 end_offset;   /* Stop time */
    kal_int16  format;       /* Media format */
    kal_uint16 identifier;   /* Resource ID */
    kal_uint8  source_type;  /* Source type - file, string or id (aud_source_type_enum) */
    kal_uint8  play_mode;    /* aud_media_play_mode_enum */
    kal_uint8  play_style;   /* audio_play_style_enum */
    kal_uint8  output_path;  /* Output path */
    kal_bool   is_restore;   /* Restore */
    
} aud_media_player_play_req_t;

typedef struct
{
    module_type src_mod;
    kal_uint32 session_id;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
    kal_uint16 group_id;
    kal_uint16 word_id;
    kal_int16 db_drive;
    kal_uint8 state;
    kal_uint8 mode;
    kal_uint8 lang;
}
aud_vr_context_struct;

typedef struct
{
    kal_uint16 app_id;
    VRSI_AddTags_Param addtags_param;
    VRSI_Tag_Param tag_param;
    VRSI_Recog_Result *recog_result;
    VRSI_Digit_Recog_Result *dgt_rcg_result;
    kal_uint8 *buffer;
    kal_uint16 *id_list;
    kal_uint8 *grammar;
    kal_uint32 session_id;
    kal_bool session_on;
    kal_uint8 pmp_len;
    kal_uint8 state;
    const kal_uint16 *pmp_text;
    kal_uint16 db_path[VR_MAX_DB_PATH_LEN + 1];
} aud_vrsi_context_struct;

typedef struct
{
    kal_uint16 app_id;
    kal_uint8 stage;
    kal_uint16 id_array[VR_SD_MAX_GROUP_NUM][VR_SD_MAX_GROUP_TAG_NUM];
    kal_uint16 id_length[VR_SD_MAX_GROUP_NUM];
    kal_uint8 *buffer;
}
aud_vr_sd_context_struct;

typedef struct
{
    kal_uint8 head;
    kal_uint8 tail;
    kal_uint16 queue[CTM_MAX_SEND_REQ_NUM + 1];
} aud_ctm_send_text_req_queue_struct;

typedef struct
{
    kal_uint8 state;
    kal_uint8 mode;
    kal_uint8 first_recv_utf8_byte;
    kal_bool more_recv_utf8_byte;
    module_type src_mod_id;
    kal_uint16 unsent_count;    /* count bytes */
    aud_ctm_send_text_req_queue_struct send_req_queue;
    kal_uint8 *buf_p;
    kal_uint8 *ucs2_utf8_buf_p;
    kal_uint8 input_vol, output_vol;
} aud_ctm_context_struct;

#define AUD_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(aud_context_p->aud_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define AUD_SET_EVENT(evt_) do{                                \
   kal_set_eg_events(aud_context_p->aud_event, (evt_),KAL_OR); \
   } while(0)

#define VR_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                              \
         kal_retrieve_eg_events(aud_context_p->vr_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define VR_SET_EVENT(evt_) do{                                \
   kal_set_eg_events(aud_context_p->vr_event, (evt_),KAL_OR); \
   } while(0)

#ifdef __GAIN_TABLE_SUPPORT__
#define SET_CURRENT_VOLUME_LEVEL(_m_,_v_)                                               \
    do{                                                                                 \
        if (aud_context_p->audio_mode<MAX_AUD_MODE_NUM && _m_<AUD_MAX_VOLUME_TYPE)      \
        {                                                                               \
            aud_context_p->volume_tbl[_m_]= (kal_uint64)_v_;                            \
        }                                                                               \
    } while(0)
#else
#define SET_CURRENT_VOLUME_LEVEL(_m_,_v_)                                               \
    do{                                                                                 \
        if (aud_context_p->audio_mode<MAX_AUD_MODE_NUM && _m_<AUD_MAX_VOLUME_TYPE)      \
        {                                                                               \
            aud_context_p->acoustic_data.volume[AUD_MODE_NORMAL][_m_]= (kal_uint8)_v_;  \
            aud_context_p->acoustic_data.volume[AUD_MODE_HEADSET][_m_]= (kal_uint8)_v_; \
            aud_context_p->acoustic_data.volume[AUD_MODE_LOUDSPK][_m_]= (kal_uint8)_v_; \
        }                                                                               \
    } while(0)
#endif /* __GAIN_TABLE_SUPPORT__ */

/* for MMA event group */
typedef enum
{
    MMA_EVT_NOWAIT =                   0,
    MMA_EVT_OPEN =                0x0001,
    MMA_EVT_CLOSE =               0x0002,
    MMA_EVT_PLAY =                0x0004,
    MMA_EVT_STOP =                0x0008,
    MMA_EVT_PAUSE =               0x0010,
    MMA_EVT_RESUME =              0x0020,
    MMA_EVT_SET_START_TIME =      0x0040,
    MMA_EVT_SET_STOP_TIME =       0x0080,
    MMA_EVT_SET_RATE =            0x0100,
    MMA_EVT_SET_TEMPO =           0x0200,
    MMA_EVT_SET_PITCH =           0x0400,
    MMA_EVT_SET_VOLUME =          0x0800,
    MMA_EVT_SEND_LONG_MSG =       0x1000,
    MMA_EVT_SEND_SHORT_MSG =      0x2000,
    MMA_EVT_OPEN_DEVICE =         0x4000,
    MMA_EVT_CLOSE_DEVICE =        0x8000,
    MMA_EVT_SET_CHANNEL_VOLUME = 0x10000,
    MMA_EVT_SET_PROGRAM =        0x20000,
    MMA_EVT_SET_DATA =           0x40000,
    MMA_EVT_GET_DURATION =       0x80000,
    MMA_EVT_GET_CURR_TIME =     0x100000,
    MMA_EVT_GET_VOLUME =        0x200000,
    MMA_EVT_WRITE_DATA_IND =    0x400000,
    MMA_EVT_GET_AUD_INFO =      0x800000,
    MMA_EVT_GET_PDL_PERCENT =  0x1000000,
    MMA_EVT_WAIT =             0x2000000  /* All mma request can share this event, seems no need to define so many different event */
}
mma_wait_event_enum;

#define MMA_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                             \
         kal_retrieve_eg_events(aud_context_p->mma_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define MMA_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->mma_event, (evt_),KAL_OR)

#if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)

typedef enum
{
    SND_EVT_NOWAIT = 0,
    SND_EVT_CHECK = 0x0001,
    SND_EVT_PLAY = 0x0002,
    SND_EVT_STOP = 0x0004,
    SND_EVT_SET = 0x0008,
    TS_EVT_CHECK = 0x0010,
    TS_EVT_SET = 0x0020,
    TS_EVT_CLOSE = 0x0040,
    REVERB_EVT_SET = 0x0080,
    REVERB_EVT_ON = 0x0100,
    REVERB_EVT_OFF = 0x0200,
    SURROUND_EVT_ON = 0x0400,
    SURROUND_EVT_OFF = 0x0800,
    EQ_EVT_SET = 0x1000,
    EQ_EVT_ON = 0x2000,
    EQ_EVT_OFF = 0x4000,
    AUD_PP_EVT_WAIT = 0x8000  /* All audio post process request can share this event, seems no need to define so many different event */
}
aud_effect_wait_event_enum;

#define EFFECT_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                                \
         kal_retrieve_eg_events(aud_context_p->effect_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define EFFECT_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->effect_event, (evt_),KAL_OR)

#endif /* #if defined(__MED_SND_MOD__) || defined(__MED_AUD_AUDIO_EFFECT__)*/ 

#if defined(__MED_GENERAL_TTS__)
typedef enum
{
    TTS_EVT_NO_WAIT = 0,
    TTS_EVT_PLAY = 0x0001,
    TTS_EVT_STOP = 0x0002,
    TTS_EVT_PAUSE = 0x0004,
    TTS_EVT_RESUME = 0x0008,
    TTS_EVT_SET_ATTR = 0x0010
}
aud_tts_wait_event_enum;

#define TTS_WAIT_EVENT(evt_) do{                                  \
         kal_uint32 retrieved_events;                                \
         kal_retrieve_eg_events(aud_context_p->tts_event, (evt_), \
         KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND); }while(0)

#define TTS_SET_EVENT(evt_) kal_set_eg_events(aud_context_p->tts_event, (evt_),KAL_OR)

#endif /* #if defined(__MED_GENERAL_TTS__) */ 

#define aud_send_msg_to_med( src_id, msg_id, local_param_ptr ) aud_send_ilm(MOD_MED, msg_id, local_param_ptr, NULL)
#define aud_send_msg_from_med( dst_id, msg_id, local_param_ptr ) aud_send_ilm(dst_id, msg_id, local_param_ptr, NULL)


#ifdef __MED_BT_A2DP_MOD__
typedef enum
{
    AUD_BT_A2DP_STATE_IDLE,
    AUD_BT_A2DP_STATE_CONFIGURED,
    AUD_BT_A2DP_STATE_OPEN,
    AUD_BT_A2DP_STATE_STREAMING
} aud_bt_a2dp_state_enum;

typedef enum
{
    AUD_BT_A2DP_WAIT_NONE,
    AUD_BT_A2DP_WAIT_ABORT,
    AUD_BT_A2DP_WAIT_DISCOVER,
    AUD_BT_A2DP_WAIT_GET_CAP,
    AUD_BT_A2DP_WAIT_CONFIG_STREAM,
    AUD_BT_A2DP_WAIT_RECONFIG_STREAM,
    AUD_BT_A2DP_WAIT_OPEN_STREAM,
    AUD_BT_A2DP_WAIT_START_STREAM,
    AUD_BT_A2DP_WAIT_PAUSE_STREAM,
    AUD_BT_A2DP_WAIT_CLOSE_STREAM
} aud_bt_a2dp_wait_enum;

typedef enum
{
    AUD_BT_A2DP_CMD_NONE,
    AUD_BT_A2DP_CMD_ABORT,
    AUD_BT_A2DP_CMD_RECONFIG_STREAM,
    AUD_BT_A2DP_CMD_START_STREAM,
    AUD_BT_A2DP_CMD_PAUSE_STREAM,
    AUD_BT_A2DP_CMD_CLOSE_STREAM
} aud_bt_a2dp_cmd_enum;

typedef enum
{
    AUD_BT_A2DP_SERVICE_STATUS_IDLE,
    AUD_BT_A2DP_SERVICE_STATUS_OPENING,
    AUD_BT_A2DP_SERVICE_STATUS_RUNNING,
    AUD_BT_A2DP_SERVICE_STATUS_CLOSING,
    AUD_BT_A2DP_SERVICE_STATUS_OPENING_CLOSING
} aud_bt_a2dp_sevice_status_enum;
#endif /* __MED_BT_A2DP_MOD__ */ 

#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
typedef enum
{
    AUD_BT_HFP_STATE_IDLE,
    AUD_BT_HFP_STATE_OPEN
} aud_bt_hfp_state_enum;

typedef enum
{
    AUD_BT_HFP_CMD_NONE,
    AUD_BT_HFP_CMD_CONNECT_SCO,
    AUD_BT_HFP_CMD_DISCONNECT_SCO
} aud_bt_hfp_cmd_enum;
#endif /* __MED_BT_HFP_MOD__ */ 

typedef enum
{
    AUD_REC_MODE_IDLE,         /* Idle record */
    AUD_REC_MODE_SPEECH,       /* In-call record */
    AUD_REC_MODE_FMR,          /* FMR record */
    AUD_REC_MODE_ATV           /* ATV record */
} aud_rec_mode_enum;

typedef enum
{
    AUD_REC_QUALITY_LOW,
    AUD_REC_QUALITY_MED,
    AUD_REC_QUALITY_HIGH,
    AUD_REC_QUALITY_AUTO,

    AUD_REC_QUALITY_AMR_4_75,  /* AMR 4.75  kbit/s */
    AUD_REC_QUALITY_AMR_5_15,  /* AMR 5.15  kbit/s */
    AUD_REC_QUALITY_AMR_5_9,   /* AMR 5.9   kbit/s */
    AUD_REC_QUALITY_AMR_6_7,   /* AMR 6.7   kbit/s */
    AUD_REC_QUALITY_AMR_7_4,   /* AMR 7.4   kbit/s */
    AUD_REC_QUALITY_AMR_7_95,  /* AMR 7.95  kbit/s */
    AUD_REC_QUALITY_AMR_10_2,  /* AMR 10.2  kbit/s */
    AUD_REC_QUALITY_AMR_12_2,  /* AMR 12.2  kbit/s */

    AUD_REC_QUALITY_AWB_6_6,   /* AWB 6.6   kbit/s */
    AUD_REC_QUALITY_AWB_8_85,  /* AWB 8.85  kbit/s */
    AUD_REC_QUALITY_AWB_12_65, /* AWB 12.65 kbit/s */
    AUD_REC_QUALITY_AWB_14_25, /* AWB 14.25 kbit/s */
    AUD_REC_QUALITY_AWB_15_85, /* AWB 15.85 kbit/s */
    AUD_REC_QUALITY_AWB_18_25, /* AWB 18.25 kbit/s */
    AUD_REC_QUALITY_AWB_19_85, /* AWB 19.85 kbit/s */
    AUD_REC_QUALITY_AWB_23_05, /* AWB 23.05 kbit/s */
    AUD_REC_QUALITY_AWB_23_85  /* AWB 23.85 kbit/s */
} aud_rec_quality_enum;

typedef struct {
   Media_Format format;        /* Media format */
   kal_uint32   byte_rate;     /* Byte per second */
   kal_wchar    file_ext[5];   /* File extension */
} aud_rec_param_struct;

/* for mute digital gain application */
typedef enum
{
    AUD_DIGITAL_GAIN_AUDIO =  0x0001,
    AUD_DIGITAL_GAIN_MTV   =  0x0002,
    AUD_DIGITAL_GAIN_VIDEO =  0x0004
} aud_mute_digital_gain_app_enum;

/* Speech event */
typedef enum
{
    AUD_SPEECH_EVENT_PRE_ON,     /* Before speech is on */
    AUD_SPEECH_EVENT_POST_ON,    /* After speech is on */
    AUD_SPEECH_EVENT_PRE_OFF,    /* Before speech is off */
    AUD_SPEECH_EVENT_POST_OFF    /* After speech is off */
} aud_speech_event_enum;

/*==== Typedefs ===========*/
typedef MHdl *(*media_open_func_ptr) (void (*handler) (MHdl *hdl, Media_Event event), STFSAL *pstFSAL, void *param);
typedef Media_Status(*media_ctrl_func_ptr) (MHdl *hdl);
typedef void (*media_set_buf_func_ptr) (MHdl *hdl, kal_uint8 *buffer, kal_uint32 buf_len);
typedef Media_Status(*media_set_time_func_ptr) (MHdl *hdl, kal_uint32 msStartTime);
typedef Media_Event(*media_proc_func_ptr) (MHdl *hdl, Media_Event event);
typedef Media_Status(*media_get_info_func_ptr) (STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);

/*---- Audio utilities -----*/

/* event */
extern void aud_wait_event(kal_uint32 evt);
extern void aud_set_event(kal_uint32 evt);


/* ring buffer */
extern void aud_util_alloc_ring_buffer_w_log(char* file, long line, kal_int32 size, kal_uint16** pp_mem);
extern void aud_util_free_ring_buffer_w_log(char* file, long line, kal_uint16** pp_mem);

#define aud_util_alloc_ring_buffer(void) \
    aud_util_alloc_ring_buffer_w_log(__FILE__,__LINE__, AUD_RING_BUFFER_SIZE, &aud_context_p->ring_buf)
    
#define aud_util_free_ring_buffer(void) \
    aud_util_free_ring_buffer_w_log(__FILE__,__LINE__, &aud_context_p->ring_buf)
    
#define aud_util_alloc_ring_buffer_ext(size, pp_mem) \
    aud_util_alloc_ring_buffer_w_log(__FILE__,__LINE__, size, pp_mem)
    
#define aud_util_free_ring_buffer_ext(pp_mem) \
    aud_util_free_ring_buffer_w_log(__FILE__,__LINE__, pp_mem)

extern void* aud_util_alloc_aud_mem(kal_uint32 size, char* file_p, long line);
extern void* aud_util_alloc_aud_cacheable_mem(kal_uint32 size, char* file_p, long line);
extern void* aud_util_alloc_aud_toppest_cacheable_mem(kal_uint32 size, char* file_p, long line);     //for driver alloc buffer in toppest mode
extern void aud_util_free_aud_mem(void** mem_p, char* file_p, long line);

#if defined(__RM_DEC_SUPPORT__)
extern Media_Status RM_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param );
#endif /* __RM_DEC_SUPPORT__ */

#ifdef __FLV_FILE_FORMAT_SUPPORT__
extern Media_Status FLV_GetContentDescInfo(STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);
#endif

#if defined(MED_PURE_AUDIO) || defined(M4A_DECODE)
extern Media_Status MP4S_GetContentDescInfo(STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param);
#endif


extern kal_bool aud_util_build_cache_start(kal_wchar *filename, void* cache_p, kal_int32 cache_size, void *file_buf, kal_int32 file_buf_size, void *proc_buf, kal_int32 proc_buf_size);
extern kal_uint32 aud_util_build_cache_get_duration(void);
extern void aud_util_build_cache_stop(void);
extern void aud_util_build_cache_stop(void);
extern kal_bool aud_util_build_cache_process( kal_uint32 *progress_p );

extern void aud_util_proc_in_med(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);
extern void aud_util_proc_in_med_ext(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len);
extern void aud_util_proc_in_med_v(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);
extern void aud_util_proc_in_med_v_ext(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len);
extern void aud_util_in_proc_call_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_util_in_proc_call_ext_req_hdlr(ilm_struct * ilm_ptr);
extern void aud_send_in_proc_call_req(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
extern void aud_send_in_proc_call_ext_req(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len);
extern void aud_send_in_proc_call_req2(module_type src_mod_id, media_in_proc_call_type func, kal_uint32 func_arg1, void *func_arg2);
extern void aud_send_in_proc_call_ext_req2(module_type src_mod_id, media_in_proc_call_ext_type pf_func, void* pv_data, kal_uint16 ui2_data_len);

extern void aud_tst_handler(ilm_struct *ilm_ptr);

/*---- main -----*/
extern kal_bool aud_init(void);
extern void aud_main(ilm_struct *ilm_ptr);
extern void aud_enter_state(kal_uint8 aud_state);
extern void aud_startup_hdlr(ilm_struct *ilm_ptr);
//extern void aud_startup_set_param(void* param);
extern void aud_startup_read_nvram_data(void);
extern void aud_debug_print_aud_drv_return(kal_int32 aud_ret, kal_uint32 line);

/* atv */
extern void aud_atv_open(void);
extern void aud_atv_close(void);
extern kal_bool aud_atv_is_open(void);
extern void aud_atv_mute(kal_bool mute);
extern void aud_atv_set_input_device(void);
extern void aud_atv_set_output_device(kal_uint8 device);
extern void aud_atv_set_volume_by_mode(kal_uint8 mode, kal_uint8 level);
extern void aud_atv_set_output_volume(kal_uint8 volume, kal_int8 digital_gain_index);
extern void aud_set_active_atv_volume(void);
extern kal_bool aud_atv_is_recorder_resource_available(void);
extern kal_bool aud_atv_is_mute(void);

/* volume */
extern void aud_volume_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_volume_update_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_volume_set_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_volume_set_tone_volume(kal_uint64 volume);
extern void aud_volume_set_keytone_volume(kal_uint64 volume);
extern void aud_volume_set_mic_volume(kal_uint64 volume);
extern void aud_volume_set_fmr_volume(kal_uint64 volume);
extern void aud_volume_set_speech_volume(kal_uint64 volume);
extern void aud_volume_set_sidetone_volume(kal_uint64 volume);
extern void aud_volume_set_media_volume(kal_uint64 volume);
extern void aud_volume_set_atv_volume(kal_uint64 volume);

/* audio */
extern void aud_audio_init(void);
extern void aud_set_audio_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_profile_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_audio_param_from_nvram_rsp(void* param);
extern void aud_set_audio_param_to_driver(audio_param_struct *param_p);
extern void aud_set_audio_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_get_dc_calibration_hdlr(ilm_struct *ilm_ptr);

#ifdef __AMRWB_LINK_SUPPORT__
extern void aud_get_audio_wb_input_fir_req_hdlr(ilm_struct * ilm_ptr);
extern void aud_get_audio_wb_output_fir_req_hdlr(ilm_struct * ilm_ptr);
extern void aud_get_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_input_fir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_output_fir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_audio_wb_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_set_audio_wb_input_fir_cnf(kal_uint8 result);
extern void aud_send_set_audio_wb_output_fir_cnf(kal_uint8 result);
extern void aud_send_set_audio_wb_mode_cnf(kal_uint8 result);
#endif

extern void aud_audio_set_melody_path_volume(kal_uint8 audio_mode);
extern void aud_audio_set_fmrdo_path_volume(kal_uint8 audio_mode);
#ifdef __ATV_SUPPORT__
extern void aud_audio_set_atv_path_volume(kal_uint8 audio_mode);
#endif
extern void aud_set_aud_path_volume(kal_uint8 audio_mode);
extern kal_uint8 aud_get_active_audio_mode(void);
extern void aud_set_tv_out_aud_path(kal_uint8 tv_on);
extern void aud_set_tv_out_param(kal_uint8 enable_loud_spk);
extern void aud_audio_get_max_volume_level_in_sync_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_get_max_volume_level_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_get_volume_in_sync_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_get_volume_req_hdlr(ilm_struct *ilm_ptr);
//extern void aud_audio_set_max_volume_level_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_set_volume_req_hdlr(ilm_struct *ilm_ptr);
#ifdef __GAIN_TABLE_SUPPORT__
extern void aud_audio_update_volume_req_hdlr(ilm_struct *ilm_ptr);
#endif /*__GAIN_TABLE_SUPPORT__*/
extern void aud_audio_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_audio_mute_digital_gain(kal_bool set_mute, kal_uint16 mute_app);
extern kal_bool aud_cfg_audio_out_device(kal_uint8 audio_sound_id, kal_uint8 *out_device_path);
extern void aud_media_play_by_id_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_by_id_req_hdlr(ilm_struct *ilm_ptr);
#if defined(__MED_AUD_FS_ACCESS__)
extern void aud_media_play_by_name_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_by_name_req_hdlr(ilm_struct *ilm_ptr);
#endif /*__MED_AUD_FS_ACCESS__*/
extern void aud_media_play_by_string_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_by_string_req_hdlr(ilm_struct *ilm_ptr);
extern kal_uint8 aud_get_volume_gain(kal_uint8 mode, kal_uint8 type, kal_uint8 level);
extern kal_uint8 aud_get_volume_level(kal_uint8 mode, kal_uint8 type);
extern void aud_audio_set_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_headset_mode_output_path_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_set_headset_mode_mic_req_hdlr(ilm_struct *ilm_ptr);

extern void aud_get_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_start_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_calc_spectrum_req_hdlr(ilm_struct *ilm_ptr);
extern void* aud_media_get_desc_func_pointer(kal_int16 format);
extern void aud_media_get_duration_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_get_progress_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_set_progress_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_is_pure_audio_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_query_ability_req_hdlr(aud_media_query_abilty_enum ability_type, ilm_struct *ilm_ptr);
extern void aud_media_is_file_seekable_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_is_file_pausable_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_is_resource_available_req_hdlr(ilm_struct *ilm_ptr);
extern kal_bool aud_media_is_resource_available(kal_uint8 resource);
extern kal_int32 aud_media_player_play_req(aud_media_player_play_req_t* req_p);
extern kal_bool aud_media_is_build_cache_required(kal_wchar* file_name);

/* trim */
#ifdef __AUDIO_TRIM_SUPPORT__
extern void aud_trim_open_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_close_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_start_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_get_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_trim_event_callback_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_trim_result_ind(module_type dst_mod_id, kal_uint32 handle, kal_uint32 result);
extern void aud_send_trim_open_req(kal_wchar* file_name_in, kal_wchar* file_name_out, kal_uint32* handle_p);
extern void aud_send_trim_close_req(kal_uint32 handle);
extern void aud_send_trim_start_req(kal_uint32 handle);
extern void aud_send_trim_stop_req(kal_uint32 handle);
extern void aud_send_trim_set_param_req(kal_int32 handle, kal_uint8 set_type, void* data_p, kal_uint16 data_len);
extern void aud_send_trim_get_param_req(kal_int32 handle, kal_uint8 get_type, void* data_p, kal_uint16* data_len_p);
#endif /* __AUDIO_TRIM_SUPPORT__ */

/* speech */
extern void aud_speech_init(void);
extern void aud_speech_main(ilm_struct *ilm_ptr);
extern void aud_speech_set_output_device(kal_uint8 device);
extern void aud_speech_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_speech_set_volume_level_param(kal_uint8 speech_volume_level, kal_uint8 speech_mode);
extern void aud_speech_set_input_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_speech_on(kal_uint8 rat_mode);
extern void aud_speech_off(void);
extern void aud_speech_set_mode_req_hdlr(ilm_struct *ilm_ptr);
extern kal_uint8 aud_speech_get_param_mode(kal_uint8 audio_mode);
#ifdef __GAIN_TABLE_SUPPORT__
extern void aud_speech_set_fir_coeff_req_hdlr(ilm_struct *ilm_ptr);
#endif
extern void aud_speech_set_enhance_mode_req_hdlr(ilm_struct *ilm_ptr);
//extern void aud_speech_set_fir(kal_bool fir_on);
extern void aud_speech_set_fir_index_by_mode(kal_uint8 audio_mode);
extern SPH_ENH_AND_FIR_SCENE aud_speech_query_speech_scenario_by_mode(kal_uint8 audio_mode);
extern void aud_speech_set_fir_index(void);
extern void aud_send_set_speech_mode_req(kal_bool speech_on, kal_uint8 rat_mode);

extern void aud_send_set_speech_fir_coeff_req(module_type src_mod_id, kal_int16 input_idx, kal_int16 output_idx);
extern void aud_send_set_speech_enhance_mode_req(kal_uint8 mode);

#ifdef __VOICE_CHANGER_SUPPORT__
extern void aud_speech_set_voice_changer_mode_req_hdlr(ilm_struct *ilm_ptr);
#endif

#ifdef __LINE_IN_SUPPORT__
extern void aud_enable_bt_box_linein_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_force_use_linein_mic_req_hdlr(ilm_struct *ilm_ptr);
#endif

#if defined(__KARAOKE_SUPPORT__) && defined(__KARAOKE_NEED_KEEP_SRC_PATH__)
extern void aud_karaoke_remix_turn_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_karaoke_remix_turn_off_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_karaoke_set_remix_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_karaoke_set_remix_audio_gain_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_karaoke_set_remix_voice_gain_req_hdlr(ilm_struct *ilm_ptr);
#endif

#ifdef __VAD_SUPPORT__
extern void aud_set_vad_level_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_switch_vad_on_off_req_hdlr(ilm_struct *ilm_ptr);
#endif

extern void aud_mic_set_device(kal_uint8 device);
extern void aud_mic_set_device_no_apply(kal_uint8 device);
extern void aud_send_update_volume_req(module_type src_mod_id, kal_uint8 vol_type, kal_uint64 volume);
extern void aud_mic_set_volume(kal_uint8 volume1, kal_uint8 volume2);
extern void aud_mic_mute(kal_bool mute);
extern void aud_mic_set_dual_nr_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_set_mic_dual_nr_req(module_type src_mod_id, kal_bool is_enable);

/* Sidetone */
extern void aud_side_tone_set_volume(kal_uint8 volume1, kal_int8 digital_gain_index);

/* keytone */
extern void aud_keytone_main(ilm_struct *ilm_ptr);
extern void aud_keytone_set_output_device(kal_uint8 device);
extern void aud_keytone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_keytone_play(kal_uint8 audio_id, kal_uint8 audio_out_device, kal_uint8 play_style);
extern void aud_keytone_stop(void);
#ifdef __KEY_TONE_DETECTION__
extern void aud_keytone_detect_process_callback_hdlr(ilm_struct *ilm_ptr);
extern void aud_keytone_detect_start_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_keytone_detect_stop_req_hdlr(ilm_struct *ilm_ptr);
#endif /*__KEY_TONE_DETECTION__*/

/* tone */
extern void aud_tone_init(void);
extern void aud_tone_main(ilm_struct *ilm_ptr);
extern void aud_tone_set_output_device(kal_uint8 device);
extern void aud_tone_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_tone_play(kal_uint8 audio_id, kal_uint8 audio_out_device);
extern void aud_tone_stop(void);
extern void aud_set_active_tone_volume(void);

/* melody */
extern void aud_melody_init(void);
extern void aud_melody_main(ilm_struct *ilm_ptr);
extern void aud_melody_set_output_device(kal_uint8 device);
extern void aud_melody_set_output_volume(kal_uint8 volume1, kal_int8 digital_gain_index);
extern void aud_set_active_ring_tone_volume(void);
extern void aud_get_active_device_path_by_mode(kal_uint8 request_path, void (*set_path_func)(kal_uint8));
extern void aud_melody_stop_crescendo(void);
extern void aud_melody_start_crescendo(kal_uint8 play_style);
extern void aud_melody_crescendo_hdlr(void *arg);
extern void aud_melody_set_volume_by_mode(kal_uint8 mode, kal_uint8 level);
extern void aud_melody_set_max_swing(kal_uint16 max_swing);
#ifdef __VIBRATION_SPEAKER_SUPPORT__
extern void aud_send_vib_spk_calibration();
extern void aud_vib_spk_calibration_hdlr();
extern void aud_send_vib_spk_is_calib();
#endif

#ifdef __MED_IMY_EVENT__
extern void aud_set_vibrator_enabled_req_hdlr(ilm_struct *ilm_ptr);
#endif 

extern void aud_melody_imy_close_backlight_ctrl(void);

#ifdef __MED_IMY_EVENT__
extern void aud_melody_stop_driver(void);
extern void aud_melody_imy_vibrator_hdlr(kal_bool on);
extern void aud_melody_imy_led_hdlr(kal_bool on);
extern void aud_melody_imy_backlight_hdlr(kal_bool on);
extern void aud_store_driver_status(void);
extern void aud_restore_driver_status(void);
#endif


#ifdef __MED_MMA_MOD__
/* mma */
extern void mma_set_handle(kal_int32 handle);
extern void mma_set_result(kal_int32 result);
#ifndef __MED_SLIM_MMA__
extern kal_bool aud_mma_startup(void);
extern kal_bool aud_mma_is_playing(aud_mma_check_mode_enum mode);
#endif
extern kal_bool aud_mma_is_async_mode(kal_int32 handle);
extern void aud_mma_close_all(void);
extern void aud_mma_play_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_fsal_process_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_open_req_hdlr(ilm_struct *ilm_ptr, kal_bool async_open);
extern void aud_mma_set_cache_table_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_close_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_build_BLISRC_table_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_audio_info_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_duration_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_current_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_start_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_stop_time_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_volume_req_hdlr(ilm_struct *ilm_ptr);
#ifdef __MED_MMA_EXTRA_CTRL__
extern void aud_mma_set_rate_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_tempo_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_pitch_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_send_long_msg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_send_short_msg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_open_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_close_device_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_channel_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_program_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_set_data_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_channel_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_pitch_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_rate_range_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_rate_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_tempo_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_program_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_bank_list_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_program_list_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_program_name_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_key_name_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_is_bank_support_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_get_is_sp_midi_req_hdlr(ilm_struct *ilm_ptr);
#endif /* __MED_MMA_EXTRA_CTRL__ */
extern void aud_mma_pdl_write_data_ind_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_mma_pdl_get_buf_percent_req_hdlr(ilm_struct *ilm_ptr);
#endif /* __MED_MMA_MOD__ */ 

#ifdef VM_SUPPORT
/* vm */
extern void aud_vm_init(void);
extern void aud_vm_start_logging(void);
extern void aud_vm_stop_logging(void);

#endif /* VM_SUPPORT */ 

/* record */
extern void aud_media_record_req_hdlr(ilm_struct *ilm_ptr);
extern kal_bool aud_rec_init(void);
extern void aud_rec_get_record_param(aud_rec_mode_enum mode, aud_rec_quality_enum quality, aud_rec_param_struct* param_p);
extern kal_uint32 aud_rec_get_record_quality_param(Media_Format format, aud_rec_quality_enum quality);
extern kal_uint32 aud_rec_get_estimated_record_byte_rate(aud_rec_mode_enum mode, Media_Format format, aud_rec_quality_enum quality);

#if defined(__AUD_REC_INTENSITY__)
extern void aud_record_get_intensity_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_record_get_intensity_limit_req_hdlr(ilm_struct *ilm_ptr);
#endif/*__AUD_REC_INTENSITY__*/

extern kal_int32 aud_rec_start_record(ilm_struct *ilm_ptr);
extern kal_int32 aud_rec_stop_record(kal_bool is_stop_unfinished);
extern kal_int32 aud_rec_pause_record(void);
extern kal_int32 aud_rec_resume_record(void);
extern void aud_rec_speech_event_nfy(aud_speech_event_enum event);
#ifdef __HD_RECORD__
extern kal_bool aud_rec_query_record_speech_mode(SPH_ENH_AND_FIR_SCENE * scene);
#endif

/* media */
extern void aud_media_main(ilm_struct *ilm_ptr);

extern void aud_media_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_close_file_handle(void);
extern void aud_media_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_resume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_store_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_media_restore_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stop_unfinished_process(void);
extern void aud_stop_unfinished_audio(void);

/* fmr */
extern void aud_send_fmr_power_on_req(kal_uint8 output_path);
extern void aud_send_fmr_power_off_req(void);
extern void aud_send_fmr_set_output_path_req(kal_uint8 output_path);
extern void aud_send_fmr_set_freq_req(kal_uint16 freq);
extern void aud_send_fmr_mute_req(kal_uint8 mute);
extern void aud_send_fmr_set_channel_req(kal_bool is_mono);

extern void aud_fmr_power_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_power_off_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_set_output_path_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_set_freq_req_hdlr(ilm_struct *ilm_ptr);
#ifdef INTERNAL_ANTENNAL_SUPPORT
extern void aud_fmr_set_antenna_req_hdlr(ilm_struct *ilm_ptr);
#endif
extern void aud_fmr_mute_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_check_is_valid_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_get_signal_level_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_set_output_volume(kal_uint8 volume, kal_int8 digital_gain_index);
extern void aud_fmr_set_volume_by_mode(kal_uint8 mode, kal_uint8 level);
extern void aud_set_active_fmr_volume(void);
extern void aud_fmr_set_output_device(kal_uint8 device);
extern void aud_fmr_set_channel_req_hdlr(ilm_struct *ilm_ptr);
extern kal_bool aud_fmr_is_power_on(void);
extern void aud_fmr_seek_process_callback_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_seek_start_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_seek_abort_req_hdlr(ilm_struct *ilm_ptr);

#ifdef __FM_RADIO_HW_SCAN__
extern void aud_send_fmr_hw_scan_req(kal_uint8 *scan_table);
extern void aud_send_fmr_hw_scan_abort_req(void);
extern void aud_fmr_hw_scan_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_hw_scan_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_hw_scan_callback(kal_int16 freq, kal_uint8 signal_level, kal_bool is_valid);
extern void aud_fmr_hw_scan_callback_ind_hdlr(ilm_struct *ilm_ptr);
#endif /* __FM_RADIO_HW_SCAN__ */ 

#ifdef __FM_RADIO_HW_SEARCH__
extern void aud_send_fmr_seek_start_req(module_type src_mod_id, kal_uint16 start_freq, kal_bool is_step_up, kal_bool is_preset, kal_int16 space_value);
extern void aud_send_fmr_seek_abort_req(module_type src_mod_id);
extern void aud_send_fmr_seek_result_ind(kal_uint16 stop_freq, kal_uint8 signal_level, kal_bool is_valid);
extern void aud_fmr_seek_callback_ind_hdlr(void *ilm_ptr);
extern void aud_fmr_seek_process_callback_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_seek_callback(kal_int16 freq, kal_uint8 signal_level, kal_bool is_valid);
extern void aud_fmr_seek_start_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_seek_abort_req_hdlr(ilm_struct *ilm_ptr);
#else /* __FM_RADIO_HW_SEARCH__ */
extern void aud_send_fmr_check_is_valid_stop_req(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up);
extern void aud_send_fmr_check_is_valid_stop_cnf(kal_uint8 is_valid);
extern void aud_send_fmr_get_signal_level_req(module_type src_mod_id, kal_uint16 freq, kal_uint8 is_step_up);
extern void aud_send_fmr_get_signal_level_cnf(kal_uint8 sig_lvl);
#endif /* __FM_RADIO_HW_SEARCH__ */

#ifdef __FM_RADIO_RDS_SUPPORT__
extern void aud_send_fmr_rds_enable_req(module_type src_mod_id, kal_bool af_enable, kal_bool tp_enable);
extern void aud_send_fmr_rds_disable_req(module_type src_mod_id);
extern void aud_send_fmr_rds_poll_rds_event_rds(module_type src_mod_id);
extern void aud_fmr_rds_callback_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_rds_enable_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_rds_disable_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_rds_init(void);
extern void aud_fmr_rds_send_event_ind(kal_uint16 event, kal_uint16 flag, kal_uint16 *data, kal_uint16 data_len, kal_uint16 freq);
extern void aud_fmr_rds_poll_rds_event_rds_hdlr(ilm_struct *ilm_ptr);
extern void aud_fmr_rds_set_buffer(kal_uint16 *RT_Data, kal_uint16 *PS_Data, kal_uint16 *AF_Data, kal_uint16 *TP_Data);
extern void aud_fmr_rds_reset_buffer(void);
#endif /* __FM_RADIO_RDS_SUPPORT__ */

#ifdef INTERNAL_ANTENNAL_SUPPORT
extern void aud_send_fmr_set_antenna_req(kal_bool is_short_antenna);
#endif

/* melody */
#ifdef __MMI_SUPPORT_VIBRATOR_SYNC__
/* -- added for turn on/off vibrator by MMI task -- */
extern void aud_vibrator_ctrl_rsp_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_vibrator_ctrl_req(module_type dst_mod_id, kal_uint8 on_off);
#endif /*__MMI_SUPPORT_VIBRATOR_SYNC__*/

#ifdef __MMI_SUPPORT_BACKLIGHT_SYNC__
/* -- added for turn on/off backlight by MMI task -- */
#ifdef __MED_IMY_EVENT__
extern void aud_backlight_ctrl_rsp_hdlr(ilm_struct *ilm_ptr);
#endif /*__MED_IMY_EVENT__*/
extern void aud_send_backlight_ctrl_req(module_type dst_mod_id, kal_uint8 on_off, kal_uint8 disable_timer);
#endif /* __MMI_SUPPORT_BACKLIGHT_SYNC__ */ 

#ifdef __MMI_SUPPORT_LED_SYNC__
/* -- added for turn on/off led by MMI task -- */
extern void aud_led_ctrl_rsp_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_led_ctrl_req(module_type dst_mod_id, kal_uint8 on_off);
#endif /* __MMI_SUPPORT_LED_SYNC__ */ 

/* ilm */
extern void aud_send_ilm(module_type dest_id, kal_uint16 msg_id, void *local_param_ptr, void *peer_buf_ptr);

#ifdef __GAIN_TABLE_SUPPORT__
extern void aud_send_state_change_ind(kal_uint8 reason, void* data_p);
#endif
extern void aud_send_audio_play_finish_ind(kal_uint8 result, kal_uint16 id);

extern void aud_send_msg_to_nvram(msg_type msg_name, kal_uint16 ef_id, void *data_ptr, kal_uint16 length);
extern void aud_send_startup_cnf(kal_uint8 result);
extern void aud_send_set_audio_profile_cnf(kal_uint8 result);
extern void aud_send_set_audio_param_cnf(kal_uint8 result);
extern void aud_send_mute_req(kal_uint8 vol_type, kal_bool mute);
extern void aud_send_set_volume_req(kal_uint8 vol_type, kal_uint64 volume, kal_bool apply, kal_bool blocking);
extern void aud_send_set_audio_mode_req(kal_uint8 audio_mode);
extern void aud_send_set_device_req(kal_uint8 audio_type, kal_uint8 device);
//extern void aud_send_set_max_volume_req(module_type src_mod_id, kal_uint8 max_volume);

/* for aud_api.c, to send message to media task */
extern void aud_send_play_id_req(void *id_param);
extern void aud_send_stop_id_req(kal_uint8 audio_id);
extern void aud_send_play_string_req(void *string_param);
extern void aud_send_stop_string_req(kal_uint8 src_id);
#if defined(__MED_AUD_FS_ACCESS__)
extern void aud_send_play_file_req(void *file_param);
extern void aud_send_stop_file_req(kal_uint8 src_id);
#endif /*__MED_AUD_FS_ACCESS__*/
#if defined(__MED_AUD_REC_MOD__)
extern void aud_send_record_req(
                kal_wchar *file_name,
                kal_uint8 format,
                kal_uint8 quality,
                kal_bool default_input,
                kal_uint8 input_source,
                kal_uint32 size_limit,
                kal_uint32 time_limit);
extern void aud_send_stop_record_req(kal_uint8 src_id);
#endif /*__MED_AUD_REC_MOD__*/
extern void aud_send_pause_req(kal_uint8 src_id);
extern void aud_send_resume_req(kal_uint8 src_id);
extern void aud_send_set_vibrator_enabled_req(kal_uint8 enable);
extern void aud_send_set_headset_mode_output_path_req(kal_uint8 device);
#if defined(__MED_AUD_FS_ACCESS__)
extern void aud_send_store_req(kal_uint8 src_id);
extern void aud_send_restore_req(void *file_param);
#endif /*__MED_AUD_FS_ACCESS__*/
extern void aud_send_get_spectrum_req(kal_uint8 *top_p, kal_uint8 *val_p);
extern void aud_send_start_calc_spectrum_req(void);
extern void aud_send_stop_calc_spectrum_req(void);
extern void aud_send_get_duration_req(kal_bool default_handle,
                               void *file_name,
                               kal_uint8 *audio_data,
                               kal_uint32 len,
                               kal_uint8 format,
                               kal_bool full_duration);
extern void aud_send_get_progress_time_req(void);
extern void aud_send_set_progress_time_req(kal_uint32 progress);
extern void aud_send_check_is_pure_audio_req(void *file_name);
extern void aud_send_check_is_file_seekable_req(void *file_name);
extern void aud_send_check_is_file_pausable_req(void *file_name);
extern void aud_send_check_is_resource_available_req(aud_resource_enum resource);


extern void aud_send_fmr_seek_continue(module_type src_id, void *local_param_ptr);
#ifndef MED_V_NOT_PRESENT
extern void aud_send_start_seek_req(void *local_param_ptr);
extern void aud_send_stop_seek_req(void);
extern void aud_send_start_build_cache_async_req(void *local_param_ptr);
extern void aud_send_close_build_cache_async_req(void);
extern void aud_send_start_build_cache_req(void *local_param_ptr);
extern void aud_send_stop_build_cache_req(void);
extern void aud_send_close_build_cache_req(void);
extern void aud_send_reset_build_cache_vars_req(void);
extern void aud_send_build_cache_fail_ind(void);
extern void medv_run_low_priority_api(ilm_struct *ilm_ptr);
extern void aud_send_run_low_priority_in_medv_req(module_type src_id, void (*func_p)(void));
extern void aud_send_run_low_priority_in_medv_cnf(module_type des_id);
/* BGSND */
#ifdef __MED_SND_MOD__
extern void aud_send_med_v_bgsnd_play_req(kal_uint8 result);
extern void aud_send_med_v_bgsnd_stop_req(void);
extern void aud_send_med_v_bgsnd_process_data_ind(kal_uint8 event, kal_uint32 snd_handle);
#endif /*__MED_SND_MOD__*/
#endif /*MED_V_NOT_PRESENT*/
extern void aud_send_update_duration_ind(kal_uint32 duration);

#ifdef __MED_MMA_MOD__
/* mma */
extern void aud_send_mma_open_req(kal_int32 param);
extern void aud_send_mma_open_async_req(kal_int32 param_p);
extern void aud_send_mma_set_cache_table_req(kal_int32 handle, kal_uint8 *cache_tbl);
extern void aud_send_mma_close_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_set_param_req(kal_uint8 param_type, void* param_value, kal_int32 handle);
extern void aud_send_mma_build_BLISRC_table(kal_bool turn_on);
extern void aud_send_mma_play_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_stop_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_pause_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_resume_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_get_audio_info_req(
                                     kal_uint16 app_id,
                                     kal_wchar* file_path,
                                     kal_uint8 media_type,
                                     kal_uint8* data,
                                     kal_uint32 data_len,
                                     void *audio_info);
extern void aud_send_mma_get_duration_req(kal_uint8 media_type, kal_int32 handle, kal_bool use_default_handle);
extern void aud_send_mma_get_current_time_req(kal_uint8 media_type, kal_int32 handle);

extern void aud_send_mma_set_start_time_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_int32 start_time);
extern void aud_send_mma_set_stop_time_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_int32 stop_time);
extern void aud_send_mma_get_volume_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_set_volume_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 volume);
extern void aud_send_mma_pdl_write_data_ind_req(kal_uint8 media_type, kal_int32 handle, kal_bool is_finish);
extern void aud_send_mma_pdl_get_buf_percent_req(kal_int32 handle, kal_uint32 cache_sec, kal_uint32* percent);
#ifdef __MED_MMA_EXTRA_CTRL__
extern void aud_send_mma_set_rate_req(kal_uint8 media_type, kal_int32 handle, kal_int32 rate);
extern void aud_send_mma_set_tempo_req(kal_uint8 media_type, kal_int32 handle, kal_int32 tempo);
extern void aud_send_mma_set_pitch_req(kal_uint8 media_type, kal_int32 handle, kal_int32 pitch);
extern void aud_send_mma_send_long_msg_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 *buf,
                kal_uint16 len);
extern void aud_send_mma_send_short_msg_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 type,
                kal_uint8 data1,
                kal_uint8 data2);
extern void aud_send_mma_open_device_req(kal_uint8 media_type, kal_bool fast_pass);
extern void aud_send_mma_close_device_req(kal_uint8 media_type, kal_int32 handle);
extern void aud_send_mma_set_channel_volume_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 channel,
                kal_uint8 level);
extern void aud_send_mma_set_program_req(
                kal_uint8 media_type,
                kal_int32 handle,
                kal_uint8 channel,
                kal_uint8 bank,
                kal_uint8 program);
extern void aud_send_mma_set_data_req(kal_uint8 media_type, kal_int32 handle, kal_int32 param);
extern void aud_send_mma_get_pitch_req(kal_int32 handle, kal_uint8 media_type, kal_int32* pitch_p);
extern void aud_send_mma_get_rate_range_req(kal_uint8 media_type, kal_int32* max_rate_p, kal_int32* min_rate_p);
extern void aud_send_mma_get_rate_req(kal_int32 handle, kal_uint8 media_type, kal_int32* rate_p);
extern void aud_send_mma_get_tempo_req(kal_int32 handle, kal_uint8 media_type, kal_int32* tempo_p);
extern void aud_send_mma_get_channel_volume_req(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_uint8* volume_p);
extern void aud_send_mma_get_program_req(kal_int32 handle, kal_uint8 media_type, kal_uint8 channel, kal_int16* bank_p, kal_int8* program_p);
extern void aud_send_mma_get_is_bank_support_req(kal_int32 handle, kal_uint8 media_type, kal_bool* is_bank_support_p);
extern void aud_send_mma_get_bank_list_req(kal_int32 handle, kal_uint8 media_type, kal_bool custom, const kal_int16** buf_p, kal_int16* len_p);
extern void aud_send_mma_get_program_list_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, const kal_int8** buf_p, kal_int16* len_p);
extern void aud_send_mma_get_program_name_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 program, const kal_uint8** name_p);
extern void aud_send_mma_get_key_name_req(kal_int32 handle, kal_uint8 media_type, kal_int16 bank, kal_int8 program, kal_int8 key, const kal_uint8** name_p);
extern void aud_send_mma_get_is_sp_midi_req(kal_int32 handle, kal_uint8 media_type, kal_bool* is_sp_midi_p);
#endif /* __MED_MMA_EXTRA_CTRL__ */
#endif /* __MED_MMA_MOD__ */ 

extern void aud_send_media_record_cnf(kal_uint8 result);
extern void aud_send_media_play_cnf(kal_uint8 result);
extern void aud_send_media_stop_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_media_pause_cnf(kal_uint8 result, kal_wchar *file_name);
extern void aud_send_media_resume_cnf(kal_uint8 result);
extern void aud_send_media_record_finish_ind(kal_uint8 result);

/* utility */
extern kal_uint8 aud_audio_out_dev_convert(kal_uint8 speaker_id);
extern kal_uint8 aud_get_res(kal_uint8 result);
extern kal_uint8 aud_check_disc_space(kal_wchar *dir_name, kal_int32 free_byte);
extern int aud_create_full_path_folder(kal_uint16 *filepath);
extern kal_bool aud_is_streaming_type(kal_uint8 format);

/* api */
extern void aud_set_result(kal_int32 result);
extern void aud_set_result_and_event(kal_int32 result, kal_uint32 evt);
extern void aud_set_pair_results(kal_int32 result, kal_uint32 value);

/* VR */
#ifdef __MED_VR_MOD__
/* SD */
extern kal_int32 aud_vr_sd_find_word_id(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_extract_group_id(kal_uint16 *filename);
extern kal_int32 aud_vr_sd_extract_word_id(kal_uint16 *filename, kal_uint16 max_filename_len);
extern void aud_vr_sd_scan_tags_in_group_folder(kal_uint16 group_id, kal_uint16 *path);
extern void aud_vr_sd_filter_out_not_exist_tags(kal_uint16 group_id);
extern kal_bool aud_vr_sd_startup(void);
extern kal_int32 aud_vr_sd_init_rcg(kal_uint16 app_id);
extern kal_int32 aud_vr_sd_init_trn(kal_uint16 app_id);
extern void aud_vr_sd_rcg_process(void);
extern void aud_vr_sd_trn_process(void);
extern kal_int32 aud_vr_sd_rcg_voice_in(void);
extern kal_int32 aud_vr_sd_trn_voice_in(kal_uint8 seq_no);
extern kal_int32 aud_vr_sd_sync_db(kal_uint16 group_id, kal_uint16 *id_length_p, kal_uint16 *id_array);
extern kal_bool aud_vr_sd_delete_one_tag(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_delete_tag(kal_uint16 group_id, kal_uint16 word_id);
extern kal_int32 aud_vr_sd_add_tag(kal_uint16 group_id, kal_uint16 *cid_array, kal_uint16 cid_length);
extern kal_int32 aud_vr_sd_play_tag(void);
extern void aud_vr_sd_abort(void);
extern kal_bool aud_vr_sd_is_active(void);

extern kal_bool aud_vr_check_db_folder(kal_uint16 *folder_name, kal_uint8 mode, kal_uint8 lang, kal_uint8 group_id);
extern kal_bool aud_vr_startup(void);
extern void aud_vr_main(ilm_struct *ilm_ptr);
extern void aud_vr_get_version_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_get_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_set_param_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_init_rcg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_init_trn_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_voice_in_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_del_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_check_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_sync_db_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_play_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_get_dir_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_add_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vr_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_send_vr_get_version_req(module_type src_mod_id, kal_uint8 mode, kal_uint8 lang);
extern void aud_send_vr_get_param_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_int16 *sim,
                kal_int16 *diff,
                kal_int16 *rej);
extern void aud_send_vr_set_param_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_int16 sim,
                kal_int16 diff,
                kal_int16 rej);
extern void aud_send_vr_init_rcg_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 app_id);
extern void aud_send_vr_init_trn_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id,
                kal_uint16 app_id);
extern void aud_send_vr_voice_in_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 seq_no);
extern void aud_send_vr_rcg_result_ind(
                module_type dst_mod_id,
                kal_uint32 session_id,
                kal_int32 result,
                kal_uint16 id_length,
                kal_uint16 *id_array);
extern void aud_send_vr_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_int32 result);
extern void aud_send_vr_del_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id);
extern void aud_send_vr_check_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id);
extern void aud_send_vr_sync_db_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 *id_length_p,
                kal_uint16 *id_array);
extern void aud_send_vr_play_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 word_id,
                kal_uint16 identifier);
extern void aud_send_vr_get_dir_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 *folder_name);
extern void aud_send_vr_add_tag_req(
                module_type src_mod_id,
                kal_uint8 mode,
                kal_uint8 lang,
                kal_uint8 group_id,
                kal_uint16 id_length,
                kal_uint16 *id_array);
extern void aud_send_vr_abort_req(module_type src_mod_id);
extern void aud_send_vr_abort_ind(module_type dst_mod_id, kal_uint32 session_id);
#endif /* __MED_VR_MOD__ */ 

#ifdef __MED_VRSI_MOD__

extern void aud_vrsi_startup(void);
extern void aud_vrsi_main(ilm_struct *ilm_ptr);
extern void aud_vrsi_init_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_add_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_start_trn_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_start_rcg_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_process_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_play_tag_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_play_tts_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_get_tagnum_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_get_taginfo_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_del_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_reset_tags_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_sync_db_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_abort_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_vrsi_close_req_hdlr(ilm_struct *ilm_ptr);

extern void aud_vrsi_callback(VRSI_Event event);
extern void aud_vrsi_prompt_cnf(void);
extern kal_int32 aud_vrsi_error(void);
extern kal_int32 aud_vrsi_init(kal_uint16 app_id);
extern kal_int32 aud_vrsi_add_tags(void);
extern void aud_vrsi_save_addtags_result(void);
extern kal_int32 aud_vrsi_start_cmd_rcg(void);
extern kal_int32 aud_vrsi_start_cmd_trn(void);
extern kal_int32 aud_vrsi_start_digit_rcg(kal_uint8 lang, kal_uint16 limit);
extern kal_int32 aud_vrsi_start_digit_adapt(kal_uint8 lang);
extern kal_int32 aud_vrsi_play_tag(kal_uint16 tag_id);
extern kal_int32 aud_vrsi_play_tts(kal_uint8 lang);
extern kal_int32 aud_vrsi_get_tagnum(kal_int32 *tagNum);
extern kal_int32 aud_vrsi_get_tag_info(
                    kal_int32 tagNum,
                    const kal_uint16 *pTagID,
                    kal_uint16 **ppTagName,
                    kal_int32 *pTagLong);
extern kal_int32 aud_vrsi_del_tags(kal_int32 tagNum, const kal_uint16 *pTagID);
extern kal_int32 aud_vrsi_reset_tags(void);
extern kal_int32 aud_vrsi_sync_db(
                    kal_uint32 tag_num,
                    kal_uint16 *id_list,
                    kal_uint16 **name_list,
                    kal_uint8 *sync_flag);
extern kal_int32 aud_vrsi_sync_db_by_id(kal_uint32 tag_num, kal_uint16 *id_list, kal_uint8 *sync_flag);
extern void aud_vrsi_abort(void);
extern void aud_vrsi_close(void);
extern kal_bool aud_vrsi_is_active(void);

extern void aud_send_vrsi_init_req(module_type src_mod_id, kal_uint16 app_id);
extern void aud_send_vrsi_add_tags_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 tag_num,
                kal_uint16 **name_list,
                kal_int32 *long_list,
                kal_uint8 *is_name_list,
                kal_uint16 *id_list);
extern void aud_send_vrsi_start_cmd_trn_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 *tag_name,
                kal_int32 tag_long);
extern void aud_send_vrsi_start_cmd_rcg_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 *grammar);
extern void aud_send_vrsi_start_digit_rcg_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 lang,
                kal_uint16 limit);
extern void aud_send_vrsi_start_digit_adapt_req(module_type src_mod_id, kal_uint32 session_id, kal_uint8 lang);
extern void aud_send_vrsi_play_tag_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint8 *grammar,
                kal_uint16 tag_id,
                kal_uint8 volume,
                kal_uint8 output_path);
extern void aud_send_vrsi_play_TTS_req(
                module_type src_mod_id,
                kal_uint32 session_id,
                kal_uint16 *text,
                kal_uint8 volume,
                kal_uint8 output_path,
                kal_uint8 lang);
extern void aud_send_vrsi_get_tag_num_req(module_type src_mod_id, kal_uint8 *grammar, kal_int32 *tag_num);
extern void aud_send_vrsi_get_tag_info_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list,
                kal_uint16 **name_list,
                kal_int32 *long_list);
extern void aud_send_vrsi_del_tags_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list);
extern void aud_send_vrsi_reset_tags_req(module_type src_mod_id, kal_uint8 *grammar);
extern void aud_send_vrsi_sync_db_req(
                module_type src_mod_id,
                kal_uint8 *grammar,
                kal_int32 tag_num,
                kal_uint16 *id_list,
                kal_uint16 **name_list,
                kal_uint8 *sync_flag);
extern void aud_send_vrsi_abort_req(module_type src_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_close_req(module_type src_mod_id);
extern void aud_send_vrsi_process_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 proc_type);
extern void aud_send_vrsi_trn_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode);
extern void aud_send_vrsi_trn_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 tag_id);
extern void aud_send_vrsi_rcg_prompt_req(module_type dst_mod_id, kal_uint32 session_id, kal_uint8 pmp_mode);
extern void aud_send_vrsi_rcg_result_ind(module_type dst_mod_id, kal_uint32 session_id, kal_uint16 res_type);
extern void aud_send_vrsi_err_ind(module_type dst_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_play_tag_finish_ind(module_type dst_mod_id, kal_uint32 session_id);
extern void aud_send_vrsi_play_tts_finish_ind(module_type dst_mod_id, kal_uint32 session_id);

#endif /* __MED_VRSI_MOD__ */ 

#ifdef __MED_CTM_MOD__
extern void aud_ctm_init(void);
extern kal_bool aud_ctm_is_tty_on(void);
extern void aud_ctm_headset_mode_update_mic(kal_bool with_mic);
extern void aud_ctm_set_speech_vol_and_path(kal_uint8 audio_mode);
extern void aud_ctm_resume(void);
extern void aud_ctm_main(ilm_struct *ilm_ptr);
extern void aud_send_ctm_open_req(module_type src_mod_id, kal_uint8 ctm_interface, ctm_param_struct *ctm_param);
extern void aud_send_ctm_open_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_close_req(module_type src_mod_id);
extern void aud_send_ctm_close_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_connect_req(module_type src_mod_id);
extern void aud_send_ctm_connect_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_connected_ind(module_type dst_mod_id);
extern void aud_send_ctm_send_text_req(module_type src_mod_id, kal_uint16 num_of_char, void *text);
extern void aud_send_ctm_send_text_cnf(module_type dst_mod_id, kal_uint8 result);
extern void aud_send_ctm_recv_text_ind(module_type dst_mod_id, kal_uint16 num_of_char, void *text);
#endif /* __MED_CTM_MOD__ */ 

#ifdef __MED_ECALL_MOD__
extern void aud_ecall_main(ilm_struct *ilm_ptr);
#endif /* __MED_ECALL_MOD__ */ 

#ifdef __MED_SND_MOD__
extern kal_bool aud_snd_startup(void);
extern void aud_snd_check_byte_stream_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_check_file_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_play_byte_stream_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_play_file_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_process_event(ilm_struct *ilm_ptr);
extern void aud_snd_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_set_volume_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_set_output_device(kal_uint8 device);

extern void aud_send_snd_check_byte_stream_format_req(module_type src_mod_id, kal_uint8 *data, kal_uint32 size);
extern void aud_send_snd_check_file_format_req(module_type src_mod_id, kal_wchar *file_name);
extern void aud_send_snd_play_byte_stream_req(
                module_type src_mod_id,
                kal_uint8 *data,
                kal_int32 size,
                kal_int16 repeats,
                kal_uint8 format, 
                kal_uint8 volume,
                kal_uint8 output_path,
                kal_uint16 identifier);
extern void aud_send_snd_play_file_req(
                module_type src_mod_id,
                kal_wchar *file_name,
                kal_int16 repeats,
                kal_uint8 volume,
                kal_uint8 output_path,
                kal_uint16 identifier);
extern void aud_send_snd_play_finish_ind(module_type dst_mod_id, kal_uint16 identifier, kal_int32 result);
extern void aud_send_snd_stop_play_req(module_type src_mod_id);
extern void aud_send_snd_set_volume_req(module_type src_mod_id, kal_uint8 volume);

extern void aud_snd_med_v_stop_cnf_hdlr(ilm_struct *ilm_ptr);
extern void aud_snd_med_v_finish_ind_hdlr(ilm_struct *ilm_ptr);
#endif /* __MED_SND_MOD__ */ 

#ifdef __MED_GENERAL_TTS__
extern void aud_send_tts_set_attr_req(module_type src_mod_id, kal_uint32 attr_id, kal_uint32 attr_value);
extern void aud_send_tts_play_req(module_type src_mod_id, void *tts_param);
extern void aud_send_tts_update_info_ind(kal_uint8 *data);
#endif

#if defined(__MED_AUD_AUDIO_EFFECT__)
extern kal_bool aud_post_process_startup(void);
#endif
#if defined(__MED___BES_TS_SUPPORT____)
extern void aud_stretch_check_stream_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stretch_check_file_format_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_stretch_set_speed_req_hdlr(ilm_struct *ilm_ptr);
extern kal_int32 aud_stretch_set_speed(kal_uint16 speed);
extern void aud_stretch_close_req_hdlr(void);
extern void aud_stretch_close(void);
#endif /* #if defined(__MED___BES_TS_SUPPORT____) */ 
#if defined(__MED___BES_LIVE_SUPPORT____)
extern void aud_reverb_set_mode_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_reverb_turn_on_req_hdlr(void);
extern void aud_reverb_turn_off_req_hdlr(void);
#endif /* #if defined(__MED___BES_LIVE_SUPPORT____) */ 
#if defined(__MED_AUD_SURROUND__)
extern void aud_surround_turn_on_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_surround_turn_off_req_hdlr(void);
#endif /*#if defined(__MED___BES_LIVE_SUPPORT____)*/
#if defined(__MED_AUD_EQUALIZER__)
extern void aud_eq_set_magnitude_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_eq_turn_on_req_hdlr(void);
extern void aud_eq_turn_off_req_hdlr(void);
#endif /* #if defined(__MED_AUD_EQUALIZER__) */ 
#if defined(__MED_AUD_BASS_ENHANCE__)
extern void aud_bass_enhance_turn_on_req_hdlr(void);
extern void aud_bass_enhance_turn_off_req_hdlr(void);
#endif /*#if defined(__MED_AUD_BASS_ENHANCE__)*/
#if defined(__MED_AUD_LOUDNESS__)
extern void aud_loudness_turn_on_req_hdlr(void);
extern void aud_loudness_turn_off_req_hdlr(void);
#endif /*#if defined(__MED_AUD_LOUDNESS__)*/

#ifdef __MED_GENERAL_TTS__
extern void aud_tts_startup(void);
extern void aud_tts_set_attr_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_process_event_ind_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_play_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_stop(void);
extern void aud_tts_stop_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_pause_req_hdlr(ilm_struct *ilm_ptr);
extern void aud_tts_resume_req_hdlr(ilm_struct *ilm_ptr);
#endif /*#ifdef __MED_GENERAL_TTS__*/

extern void aud_send_bt_open_codec_req(module_type src_mod_id, bt_a2dp_audio_cap_struct *cfg, 
    kal_uint8 stream_handle, kal_bool immediate, kal_uint32 seq_no);
extern void aud_send_bt_close_codec_req(module_type src_mod_id);
extern void aud_send_bt_close_codec_ind(module_type src_mod_id,
    kal_uint8 stream_handle, kal_uint32 seq_no);
#ifdef __BT_SPEAKER_SUPPORT__
extern void aud_send_bt_open_sink_codec_req(module_type src_mod_id, bt_a2dp_audio_cap_struct *cfg, 
    kal_uint8 stream_handle, kal_bool immediate, kal_uint32 seq_no);
extern void aud_send_bt_close_sink_codec_req(module_type src_mod_id);
extern void aud_send_bt_open_sink_codec_cnf(module_type src_mod_id,  kal_uint8 stream_handle, kal_uint8 result);
extern void aud_send_bt_close_sink_codec_cnf(module_type src_mod_id,  kal_uint8 stream_handle, kal_uint8 result);
extern void aud_send_bt_sink_codec_ind(module_type dst_mod_id, kal_uint8 stream_handle, kal_uint8 events);
extern void aud_send_bt_start_sink_codec_cnf(module_type src_mod_id, kal_uint8 result);
extern void aud_send_bt_stop_sink_codec_cnf(module_type src_mod_id, kal_uint8 result);
#endif

#ifdef __BT_HF_PROFILE__
extern void aud_send_bt_hf_sco_connect_req(module_type dst_mod_id, kal_uint8 connection_id);
extern void aud_send_bt_hf_sco_disconnect_req(module_type dst_mod_id, kal_uint8 connection_id);
#endif
#ifdef __MED_BT_MOD__
extern void aud_send_bt_audio_open_req(
                module_type src_mod_id,
                kal_uint8 profile,
                kal_uint8 mode,
                kal_uint16 connect_id,
                void* pContext,
				void* req_context);
extern void aud_send_bt_audio_open_cnf(module_type dst_mod_id, kal_uint16 result, kal_uint16 error_cause);//kal_uint8 profile, kal_uint16 result, kal_uint16 error_cause);
extern void aud_send_bt_audio_open_ind(module_type dst_mod_id,kal_uint8 profile , kal_uint8 connect_id); //, kal_uint8 profile);
extern void aud_send_bt_audio_close_req(kal_uint8 profile);
extern void aud_send_bt_audio_close_cnf(module_type dst_mod_id, kal_uint16 result); //kal_uint8 profile, kal_uint16 result);
extern void aud_send_bt_audio_close_ind(module_type dst_mod_id, kal_uint16 cause,kal_uint8 profile ,kal_uint8 connect_id );//kal_uint8 profile, kal_uint16 cause);
extern void aud_send_bt_audio_turn_on_req(module_type src_mod_id, kal_uint8 profile);
extern void aud_send_bt_audio_turn_off_req(kal_uint8 profile);

extern void aud_send_bt_audio_set_sco_mode_req(module_type src_mod_id, kal_uint8 mode);
#if defined( __MED_BT_HFP_MOD__) || defined(__MED_BT_HF_MOD__)
extern kal_bool aud_bt_hfp_is_audio_path_on(void);
extern kal_bool aud_bt_hfp_is_speech_path_on(void);
extern SPH_ENH_AND_FIR_SCENE aud_bt_hfp_query_bt_speech_scenario(void);
extern void aud_bt_hfp_set_speech_path_on(void);
extern void aud_bt_hfp_set_speech_path_off(void);
extern void aud_bt_hfp_set_audio_path_on(void);
extern void aud_bt_hfp_set_audio_path_off(void);
extern void aud_bt_hfp_set_audio_path(kal_bool on);
#endif /* __MED_BT_HFP_MOD__ */ 

/*move out for dummy function*/
extern void aud_bt_a2dp_open_codec(kal_int32 audio_format);

#ifdef __MED_BT_A2DP_MOD__
#if defined(__BTMTK__)
extern void aud_bt_a2dp_close_codec_ind(void);
extern void aud_bt_a2dp_close_codec_for_open(void);
extern kal_bool aud_bt_a2dp_is_mute_phone(void);
extern kal_bool aud_bt_a2dp_is_codec_opened(void);
#endif
#endif /* __MED_BT_A2DP_MOD__ */

#endif /* __MED_BT_MOD__ */ 

/* For MoDIS Simulation audio in Windows */
#ifndef __MTK_TARGET__

typedef struct
{
    kal_uint8 *data;
    kal_uint32 size;
} Modis_Aud_Param;

extern MHdl *Aud_Modis_Open_File(void(*handler)(MHdl *handle, Media_Event event), STFSAL *pstFSAL, void *param);
extern MHdl *Aud_Modis_Open_String(void(*handler)(MHdl *handle, Media_Event event), STFSAL *pstFSAL, void *param);

extern kal_uint8 aud_modis_get_duration(kal_wchar *file_name, kal_uint8 *aud_data, kal_uint32 aud_len, kal_uint32 *duration);
#endif /* #ifndef __MTK_TARGET__ */

#ifdef __CLASSK_CP_SUPPORT__
extern kal_uint32 aud_get_vbat_value(void);
extern void aud_send_classk_state(kal_bool classk_state);
#endif/*__CLASSK_CP_SUPPORT__*/

#endif /* _AUD_MAIN_H */ /* _AUD_H */

#endif /* MED_NOT_PRESENT */ 

