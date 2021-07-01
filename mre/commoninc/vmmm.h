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
 *  vmmm.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  multimedia
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef VMMM_H_
#define VMMM_H_

#include "vmswitch.h"


#ifdef __MRE_SAL_VIBR__

#include "vmvibr_sdk.h"

#else
#define vm_vibrator_off (void*)NULL
#define vm_vibrator_on (void*)NULL
#define vm_vibrator_once (void*)NULL
#endif


#ifdef __MRE_SAL_AUDIO__

#include "vmmm_sdk.h"

#else

#define vm_audio_resume_bg_play (void*)NULL
#define vm_audio_suspend_bg_play (void*)NULL
#define vm_midi_resume (void*)NULL
#define vm_midi_play_by_bytes_ex (void*)NULL
#define vm_midi_pause (void*)NULL
#define vm_midi_stop (void*)NULL
#define vm_midi_play (void*)NULL
#define vm_audio_mixed_stop (void*)NULL
#define vm_audio_resume (void*)NULL
#define vm_midi_play_by_bytes (void*)NULL
#define vm_midi_get_time (void*)NULL
#define vm_audio_terminate_background_play (void*)NULL
#define vm_set_volume (void*)NULL
#define vm_audio_mixed_pause (void*)NULL
#define vm_audio_mixed_close_all (void*)NULL
#define vm_audio_play_beep (void*)NULL
#define vm_audio_set_volume_type (void*)NULL
#define vm_audio_pause (void*)NULL
#define vm_audio_stop_all (void*)NULL
#define vm_audio_mixed_get_time (void*)NULL
#define vm_audio_mixed_resume (void*)NULL
#define vm_audio_stop (void*)NULL
#define vm_midi_set_type (void*)NULL
#define vm_audio_mixed_set_start_time (void*)NULL
#define vm_midi_stop_all (void*)NULL
#define vm_audio_register_interrupt_callback (void*)NULL
#define vm_audio_play_file (void*)NULL
#define vm_audio_bytes_duration (void*)NULL
#define vm_audio_duration (void*)NULL
#define vm_audio_mixed_open (void*)NULL
#define vm_midi_play_ex (void*)NULL
#define vm_audio_clear_interrupt_callback (void*)NULL
#define vm_audio_mixed_close (void*)NULL
#define vm_audio_mixed_play (void*)NULL
#define vm_get_volume (void*)NULL
#define vm_audio_mixed_set_speedup_mode (void*)NULL
#define vm_audio_get_time (void*)NULL
#define vm_audio_is_calling (void*)NULL
#define vm_audio_play_file_ex (void*)NULL
#define vm_audio_is_app_playing (void*)NULL
#define vm_audio_play_bytes (void*)NULL
#define vm_audio_play_bytes_no_block (void*)NULL
#define vm_record_resume (void*)NULL
#define vm_record_stop (void*)NULL
#define vm_record_start (void*)NULL
#define vm_record_pause (void*)NULL
#define vm_set_key_tone_on (void*)NULL
#define vm_set_key_tone_off (void*)NULL
#define vm_get_key_tone_state (void*)NULL
#define vm_set_key_tone_state (void*)NULL
#define vm_audio_set_sph_volume (void*)NULL
#define vm_audio_get_sph_mode_volume (void*)NULL

#endif

#endif /* VMMM_H_ */
