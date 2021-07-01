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
 *
 * Filename:
 * ---------
 * aud_common.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   Common Audio Customization Parameters 
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/

#include "audcoeff_default.h"
#include "Aud_common_config.h"

//#include "kal_release.h"
//#include "nvram_default_audio.h"

/* I2S_INPUT_MODE Sampling rate */
/* Should be 32000, 44100, or 48000 */
const unsigned short Media_I2S_INPUT_MODE_SR = 32000;

/* I2S INPUT/OUTPUT Mode select*/
/* 0: master mode / 1: slave mode*/
/* currently, only master mode is supported*/
const char Media_I2S_SLAVE_MODE = 0;

/* SW_SYN_8K | SW_SYN_16K : Maximum Amplitude of MCU Software Synthesizer  */
const unsigned short Media_Playback_Maximum_Swing = DEFAULT_MEDIA_PLAYBACK_MAXIMUM_SWING;

/* DSP_WT_SYN Melody Compensation Filter  */ 
const signed short Melody_FIR[25] = DEFAULT_MELODY_FIR;
/*
#if defined(WT600K) || defined(WT300K)
const signed short Melody_FIR[25] = 
{ 
   -21,  -269,     7,   141,  -326,  -203,   257,  -396,  -472,  1323, 
   192, -6458, 15256, -6458,   192,  1323,  -472,  -396,   257,  -203, 
  -326,   141,     7,  -269,   -21 
};
#else
// for WT150K WT100K WT70K WT20K
const signed short Melody_FIR[25] = 
{ 
54, -142, -169, 36, 88, -111, -553, -291, 737, -96, -1605, 560, 5836, 560,
-1605, -96, 737, -291, -553, -111, 88, 36, -169, -142, 54,
};
#endif
*/
#if defined(__DUAL_MIC_SUPPORT__)
#ifdef __AMRWB_LINK_SUPPORT__
const signed short WB_DMNR_Para[76] = DEFAULT_WB_DMNR_PARAM;
#endif
const signed short DMNR_Para[44] = DEFAULT_DMNR_PARAM;
#endif

/*
 * Speech Enhancement Parameter
 * Refer to audcoeff_default.h
 */
const unsigned short Speech_Normal_Mode_Para[16] = DEFAULT_SPEECH_NORMAL_MODE_PARA;
const unsigned short Speech_Earphone_Mode_Para[16] = DEFAULT_SPEECH_EARPHONE_MODE_PARA;
const unsigned short Speech_LoudSpk_Mode_Para[16] = DEFAULT_SPEECH_LOUDSPK_MODE_PARA;
const unsigned short Speech_BT_Earphone_Mode_Para[16] = DEFAULT_SPEECH_BT_EARPHONE_MODE_PARA;
const unsigned short Speech_BT_Cordless_Mode_Para[16] = DEFAULT_SPEECH_BT_CORDLESS_MODE_PARA;
const unsigned short Speech_CARKIT_Mode_Para[16] = DEFAULT_SPEECH_CARKIT_MODE_PARA;
const unsigned short Speech_AUX1_Mode_Para[16] = DEFAULT_SPEECH_AUX1_MODE_PARA;
const unsigned short Speech_AUX2_Mode_Para[16] = DEFAULT_SPEECH_AUX2_MODE_PARA;

#ifdef __AMRWB_LINK_SUPPORT__
const unsigned short WB_Speech_Normal_Mode_Para[16] = DEFAULT_WB_SPEECH_NORMAL_MODE_PARA;
const unsigned short WB_Speech_Earphone_Mode_Para[16] = DEFAULT_WB_SPEECH_EARPHONE_MODE_PARA;
const unsigned short WB_Speech_LoudSpk_Mode_Para[16] = DEFAULT_WB_SPEECH_LOUDSPK_MODE_PARA;
const unsigned short WB_Speech_BT_Earphone_Mode_Para[16] = DEFAULT_WB_SPEECH_BT_EARPHONE_MODE_PARA;
const unsigned short WB_Speech_BT_Cordless_Mode_Para[16] = DEFAULT_WB_SPEECH_BT_CORDLESS_MODE_PARA;
const unsigned short WB_Speech_CARKIT_Mode_Para[16] = DEFAULT_WB_SPEECH_CARKIT_MODE_PARA;
const unsigned short WB_Speech_AUX1_Mode_Para[16] = DEFAULT_WB_SPEECH_AUX1_MODE_PARA;
const unsigned short WB_Speech_AUX2_Mode_Para[16] = DEFAULT_WB_SPEECH_AUX2_MODE_PARA;
#endif

const unsigned short Speech_Vol_Para[4] = DEFAULT_SPEECH_VOL_PARA;

#ifdef AUDIO_COMPENSATION_ENABLE
/* Audio Compensation Filter */
const signed short Audio_Compensation_Filter[3][45] = DEFAULT_COMPENSATION_FLT;
/*
{ 
    { / * 0: Compensation Filter for Normal mode *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0 
    },
    { / * 0: Compensation Filter for Headset mode *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0 
    },
    { / * 0: Compensation Filter for loudspeaker ringtone mode *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0 
    }
};
*/
#endif /* AUDIO_COMPENSATION_ENABLE */

#ifdef __AUDIO_COMPENSATION_SW_VERSION__
const signed short Audio_Compensation_Filter_SW[3][3][45] = 
	DEFAULT_AUDIO_COMPENSATION_FILTER_SW;
/*
{ 
  {
    { / * 0: Compensation Filter for Normal mode, Sample rate: 48000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for Normal mode, Sample rate: 24000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for Normal mode, Sample rate: 12000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
  },
  {
    { / * 0: Compensation Filter for Headset mode, Sample rate: 48000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for Headset mode, Sample rate: 24000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for Headset mode, Sample rate: 12000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
  },
  {
    { / * 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 48000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 24000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
    { / * 0: Compensation Filter for loudspeaker ringtone mode, Sample rate: 12000 *
     32767,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0,
         0,     0,     0,     0,     0
    },
  },
};
*/
#endif


#if defined( __BES_BASS_SUPPORT__ )
const unsigned short BBAS_LoudspeakerCutoff = DEFAULT_BASS_LOUDSPEAKER_CUTOFF;
#endif

#if defined(__BT_SUPPORT__) || defined(__DUAL_TALK_MODEM_SUPPORT__)
/* The Bluetooth PCM digital volume */
/* default_bt_pcm_in_vol : uplink, only for enlarge volume, 
                           0x100 : 0dB  gain
                           0x200 : 6dB  gain
                           0x300 : 9dB  gain
                           0x400 : 12dB gain
                           0x800 : 18dB gain
                           0xF00 : 24dB gain             */
const unsigned short default_bt_pcm_in_vol        =   0x100;
/* default_bt_pcm_out_vol : downlink gain, 
                           0x1000 : 0dB; maximum 0x7FFF  */
const unsigned short default_bt_pcm_out_vol       =  0x1000;
#endif

const unsigned short L1Audio_Debug_Info[16]=
{ 
      0,     0,        0,     0,     0,
      0,     0,        0,     0,     0,
      0,     0,        0,     0,     0,
      0
};

#ifdef __BES_LOUDNESS_SUPPORT__

#if defined(__BES_LOUDNESS_V4_SUPPORT__)
/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_spk_hsf_Coeffs[2][9][5] = 
	DEFAULT_AUDIO_COMPENSATION_SPK_HSF_COEFFS;

/* Compensation Filter BPF coeffs       */ 
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_spk_bpf_Coeffs[6][6][3] = 
	DEFAULT_AUDIO_COMPENSATION_SPK_BPF_COEFFS;

/* Compensation Filter LPF coeffs       */
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_spk_lpf_Coeffs[6][3] = 
	DEFAULT_AUDIO_COMPENSATION_SPK_LPF_COEFFS;

/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_hdp_hsf_Coeffs[2][9][5] = 
	DEFAULT_AUDIO_COMPENSATION_HDP_HSF_COEFFS;

/* Compensation Filter BPF coeffs       */ 
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_hdp_bpf_Coeffs[6][6][3] = 
	DEFAULT_AUDIO_COMPENSATION_HDP_BPF_COEFFS;

/* Compensation Filter LPF coeffs       */
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_hdp_lpf_Coeffs[6][3] = 
	DEFAULT_AUDIO_COMPENSATION_HDP_LPF_COEFFS;

const unsigned int BESLOUDNESS_ATT_TIME = DEFAULT_BESLOUDNESS_ATT_TIME;
const unsigned int BESLOUDNESS_REL_TIME = DEFAULT_BESLOUDNESS_REL_TIME;

#else
/* Compensation Filter HSF coeffs       */
/* BesLoudness also uses this coeffs    */ 
const unsigned int Audio_Compensation_hsf_Coeffs[9][4] = 
	DEFAULT_AUDIO_COMPENSATION_HSF_COEFFS;

/* Compensation Filter BPF coeffs       */ 
const unsigned int Audio_Compensation_bpf_Coeffs[4][6][3] = 
	DEFAULT_AUDIO_COMPENSATION_BPF_COEFFS;

const unsigned int BESLOUDNESS_GAIN_PROFILE_FORGET_FACT_TABLE[9][2] = 
	DEFAULT_BESLOUDNESS_GAIN_PROFILE_FORGET_FACT_TABLE;

#endif

const signed char BESLOUDNESS_GAINMAP_IN[5] = DEFAULT_BESLOUDNESS_GAINMAP_IN;
const signed char BESLOUDNESS_GAINMAP_OUT[5] = DEFAULT_BESLOUDNESS_GAINMAP_OUT;
const unsigned int BESLOUDNESS_WS_GAIN_MAX = DEFAULT_BESLOUDNESS_WS_GAIN_MAX;
const unsigned int BESLOUDNESS_WS_GAIN_MIN = DEFAULT_BESLOUDNESS_WS_GAIN_MIN;
const unsigned int BESLOUDNESS_FILTER_FIRST = DEFAULT_BESLOUDNESS_FILTER_FIRST;

#endif

#if defined(__BES_LOUDNESS_ON_I2S__) || defined(APPLY_HPF_ON_FM_I2S)

#if 0
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

//30Hz
const unsigned int Audio_Compensation_hsf_Coeffs_for_I2S[9][4] = {
0x07FA4870, 0xF00CB3C9, 0x07F903E9, 0x7F9AC065, /*    48000 */ 
0x07F9C723, 0xF00DD303, 0x07F86602, 0x7F91C06E, /*    44100 */ 
0x07F76DAC, 0xF0130AFB, 0x07F587A3, 0x7F67C098, /*    32000 */ 
0x07F49397, 0xF019605F, 0x07F20C8D, 0x7F34C0CA, /*    24000 */ 
0x07F3917F, 0xF01B9D7E, 0x07F0D19F, 0x7F22C0DC, /*    22050 */ 
0x07EEE17E, 0xF02605B7, 0x07EB19F2, 0x7ECEC12E, /*    16000 */ 
0x07E9322B, 0xF032A3C4, 0x07E42C1D, 0x7E68C192, /*    12000 */ 
0x07E73006, 0xF037189D, 0x07E1B9C8, 0x7E43C1B5, /*    11025 */ 
0x07DDDBEE, 0xF04BC9CF, 0x07D65ED5, 0x7D9BC257, /*     8000 */ }; 

#endif

#if defined(__HD_RECORD__)
const char HD_RECORD_MODE_NAMES[NUM_RECORD_SPH_MODE][LEN_OF_ENHANCEMENT_MODE_NAME] = {
	HD_RECORD_MODE_NAME_VOICE_HANDSET,
	HD_RECORD_MODE_NAME_VOICE_EARPHONE,
	HD_RECORD_MODE_NAME_VOICE_BT,
	
	HD_RECORD_MODE_NAME_VIDEO_HANDSET,
	HD_RECORD_MODE_NAME_VIDEO_EARPHONE,
	HD_RECORD_MODE_NAME_VIDEO_BT
};

const char HD_RECORD_MODE_CATEGORY_NAME[NUM_RECORD_SPH_MODE_CATEGORY][LEN_OF_ENHANCEMENT_CATEGORY_NAME] = {
	HD_RECORD_CATEGORY_NAME_1,
	HD_RECORD_CATEGORY_NAME_2
};

const short HD_RECORD_MODE_CATEGORY[NUM_RECORD_SPH_MODE] = {
	RECORD_SPH_MODE_CATEGORY_1_INDEX, 
	RECORD_SPH_MODE_CATEGORY_1_INDEX, 
	RECORD_SPH_MODE_CATEGORY_1_INDEX, 

	RECORD_SPH_MODE_CATEGORY_2_INDEX, 
	RECORD_SPH_MODE_CATEGORY_2_INDEX, 
	RECORD_SPH_MODE_CATEGORY_2_INDEX
};

//for HD record speech enhancement mode, original 6 FIRs is also available
//The new added FIR is indexing from NUM_SPH_INPUT_FIR.
//As the result, the max value inside the mapping table is (NUM_SPH_INPUT_FIR+NUM_RECORD_INPUT_FIR-1)
const short HD_RECORD_MODE_FIR_MAPPING_CH1[NUM_RECORD_SPH_MODE] = { 
	SPH_FIR_COEFF_NORMAL,
	SPH_FIR_COEFF_HEADSET,
	SPH_FIR_COEFF_BT,

	SPH_FIR_COEFF_NORMAL,
	SPH_FIR_COEFF_HEADSET,
	SPH_FIR_COEFF_BT
};

#if defined(__STEREO_RECORD__)
const short HD_RECORD_MODE_FIR_MAPPING_CH2[NUM_RECORD_SPH_MODE] = { 
	(NUM_SPH_INPUT_FIR + 0),
	-1,
	-1,
	
	-1,
	-1,
	-1
};

#endif

const char HD_RECORD_MODE_DEVICE_MAPPING[NUM_RECORD_SPH_MODE] = { 
	SPH_MODE_NORMAL,
    SPH_MODE_EARPHONE,
    SPH_MODE_BT_EARPHONE,

	SPH_MODE_NORMAL,
    SPH_MODE_EARPHONE,
    SPH_MODE_BT_EARPHONE

};


#endif //__HD_RECORD__

