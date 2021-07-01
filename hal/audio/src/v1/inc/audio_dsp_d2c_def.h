/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * audio_dsp_d2c_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file defines all the D2M used in audio module.
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __AUD_DSP_D2C_DEF__
#define __AUD_DSP_D2C_DEF__


// common define for AUDIO SPEECH and AFE
#if defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define DPRAM_base(a)                        ((volatile uint16*)DPRAM_CPU_base+(a))
#define DPRAM2_base(a)                       ((volatile uint16*)DPRAM_CPU_base+(a))    
#define DPRAM2_CPU_base                      DPRAM_CPU_base
#else
#define DPRAM_base(a)                        ((volatile uint16*)DPRAM_CPU_base+(a))
#define DPRAM2_base(a)                       ((volatile uint16*)DPRAM2_CPU_base+(a))
#endif

#if defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    #define IO4567_D2C_ID_SPEECH_BASE        1          //1~30
    #define IO4567_D2C_ID_AUDIO_BASE        31          //31~60
    #define IO4567_D2C_ID_OTHER_BASE        61          //61~63
    
    //Speech
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#include "common_def.h"
#include "sal_def.h"

    #define DP_D2C_SPEECH_UL_ID         (IO4567_D2C_ID_SPEECH_BASE+0)   //  1 // mapping to SpeechDSP DP_D2C_SPEECH_UL_ID interrupt which must be consistent with SpeechDSP's setting(D2C_Status_80.h)
    #define DP_D2C_SPEECH_DL_ID         (IO4567_D2C_ID_SPEECH_BASE+1)   //  2 // mapping to SpeechDSP DP_D2C_SPEECH_DL_ID interrupt which must be consistent with SpeechDSP's setting(D2C_Status_80.h)
    #define DP_D2C_SE_SD_DONE           (IO4567_D2C_ID_SPEECH_BASE+1 )  //  2 // TCH mode recording , SE+SD is done, MCU can COPY data FROM SHERIF
    #define DP_D2C_SE_DONE              (IO4567_D2C_ID_SPEECH_BASE+2 )  //  3 // IDLE mode recording, SE is done, MCU can COPY data FROM SHERIF
    #define DP_D2C_SD_DONE              (IO4567_D2C_ID_SPEECH_BASE+3 )  //  4 // IDLE mode playback , SD1+SD2 is done, MCU can WRITE data TO SHERIF
    #define DP_D2C_WAV_REQ              (IO4567_D2C_ID_SPEECH_BASE+4 )  //  5 // ASP WAV Request
    #define DP_D2C_INT_MAPPING_BASIC    (IO4567_D2C_ID_SPEECH_BASE+5)   //  6 // Speech Driver Mapping which can be changed. It is independent of SpeechDSP's setting(D2C_Status_80.h)
    #define DP_D2C_VMEPL_REC_INT        (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_REC_EPL)  //  7 // idle or TCH VM EPL record
    #define DP_D2C_PCM_REC_INT          (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_REC_PCM)  //  8 // idle or TCH pcm record	 
    #define DP_D2C_VM_REC_INT           (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_REC_VM)   //  9 // idle or TCH vm record
    #define DP_D2C_3G_DONE_DL           (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_3G_DL)    // 10 // 3G Call DL
    #define DP_D2C_3G_DONE_UL           (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_3G_UL)    // 11 // 3G Call UL
    #define DP_D2C_PCM_EX_DL            (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_PNW_DL)   // 12 // PCMNWAY for DL
    #define DP_D2C_PCM_EX_UL            (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_PNW_UL)   // 13 // PCMNWAY for UL
    #define DP_D2C_DACA_REQ_DL          (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_DACA_DL)  // 14 // DATACARD for DL
    #define DP_D2C_DACA_REQ_UL          (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_DACA_UL)  // 15 // DATACARD for UL 
    #define DP_D2C_BGS_DL               (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_BGS_DL)   // 16 // Background Sound UL
    #define DP_D2C_BGS_UL               (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_BGS_UL)   // 17 // Background Sound UL
    #define D2C_AUDIO_VIA_BT_ID         (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_AVBT)     // 18 // Audio via BT
    #define DP_D2C_PCM2WAY_ENH_DL            (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_P2W_ENH_DL)   // 19 // PCM2WAY for DL
    #define DP_D2C_PCM2WAY_ENH_UL            (DP_D2C_INT_MAPPING_BASIC+SAL_DSPINT_PRIO_P2W_ENH_UL)   // 20 // PCM2WAY for UL
#else   // chip compile option
    #define DP_D2C_3G_DONE              (IO4567_D2C_ID_SPEECH_BASE+0 ) //0x3333  // Mosi add for 3G INT
    #define DP_D2C_SE_SD_DONE           (IO4567_D2C_ID_SPEECH_BASE+1 ) //0xDDEE  // TCH mode recording , SE+SD is done, MCU can COPY data FROM SHERIF
    #define DP_D2C_SE_DONE              (IO4567_D2C_ID_SPEECH_BASE+2 ) //0xEE01  // IDLE mode recording, SE is done, MCU can COPY data FROM SHERIF
    #define DP_D2C_SD_DONE              (IO4567_D2C_ID_SPEECH_BASE+3 ) //0xDD01  // IDLE mode playback , SD1+SD2 is done, MCU can WRITE data TO SHERIF
    #define DP_D2C_WAV_REQ              (IO4567_D2C_ID_SPEECH_BASE+4 ) //0x0010  // ASP WAV Request
    #define DP_D2C_WAV_REC_REQ          (IO4567_D2C_ID_SPEECH_BASE+5 ) //0x0011  // ASP WAV Record Request
    #define DP_D2C_VR_REQ               (IO4567_D2C_ID_SPEECH_BASE+6 ) //0x0012  // VR Request
    #define DP_D2C_CTM_VOIP_REQ         (IO4567_D2C_ID_SPEECH_BASE+7 ) //0x0014  //------ dsp 2 mcu interrupt ------
    #define D2C_UL_DL_PCM_REC_INT_ID    (IO4567_D2C_ID_SPEECH_BASE+8 ) //0xAA55  // UL+DL PCM record to MCU interrupt
    #define D2C_WAV_REC_REQ_ID          (IO4567_D2C_ID_SPEECH_BASE+9 ) //0xAA56  // ASP WAV Record Request
    #define D2C_SOUND_EFFECT_INT_ID     (IO4567_D2C_ID_SPEECH_BASE+10) //0xAA57
    #define D2C_AUDIO_VIA_BT_ID         (IO4567_D2C_ID_SPEECH_BASE+11) //0xCC66  // Audio via BT
    #define D2C_RINI_ID                 (IO4567_D2C_ID_SPEECH_BASE+12) //0x6688

#if defined(MT6250)
    #define DP_D2C_DACA_REQ_UL          (IO4567_D2C_ID_SPEECH_BASE+13 )
    #define DP_D2C_DACA_REQ_DL          (IO4567_D2C_ID_SPEECH_BASE+14 ) 
#endif

#endif  // chip compile option
    
    //Audio
    #define DP_D2C_WT_INT               (IO4567_D2C_ID_AUDIO_BASE+0)  //0x0013  // WT to MCU interrupt
    #define DP_D2C_PCMROUNT_INT         (IO4567_D2C_ID_AUDIO_BASE+1)  //0xABCD  // PCMRount to MCU interrupt
    #define DP_D2C_MP3_INT              (IO4567_D2C_ID_AUDIO_BASE+2)  //0x1111  // MP3 to MCU interrupt
    #define DP_D2C_AAC_CT_INT           (IO4567_D2C_ID_AUDIO_BASE+3)  //0x2222  // AAC, AACPLUS, AACPS, BSAC to MCU interrupt
    #define DP_D2C_WMA_INT              (IO4567_D2C_ID_AUDIO_BASE+4)  //0x3333  // WMA  to MCU interrupt
    #define DP_D2C_AWB_PLUS_INT         (IO4567_D2C_ID_AUDIO_BASE+5)  //0xBBBB  // AWB PLUS to MCU interrupt
    #define DP_D2C_AUDLP_ERR_INT        (IO4567_D2C_ID_AUDIO_BASE+6)  //0xEECC
    #define DP_D2C_AVSYNC_A2V_INT       (IO4567_D2C_ID_AUDIO_BASE+7)  //0x1234  // AVSync to MCU interrupt
    #define DP_D2C_SBC_INT              (IO4567_D2C_ID_AUDIO_BASE+8)  //0xA4BC
    #define DP_D2C_I2S_REC_INT          (IO4567_D2C_ID_AUDIO_BASE+9)	//0x1414
    #define DP_D2C_COOK_INT             (IO4567_D2C_ID_AUDIO_BASE+10) //0x1313  // COOK, D2C interrupt
    //Other
    #define D2C_INT6_MAGIC              (IO4567_D2C_ID_OTHER_BASE+0)  //0xDD66
    #define D2C_DSP_DEAD_INT_ID         (IO4567_D2C_ID_OTHER_BASE+1)  //0xDD44
    #define D2C_MPU_ERROR               (IO4567_D2C_ID_OTHER_BASE+2)  //0x002A

#else

/* -------------------------------------------------------------------------- */
/* DSP to MCU interrupt magic number definition                               */
/* -------------------------------------------------------------------------- */
    //Speech
    #define DP_D2C_3G_DONE              0x3333
    #define DP_D2C_SE_SD_DONE           0xDDEE
    #define DP_D2C_SE_DONE              0xEE01
    #define DP_D2C_SD_DONE              0xDD01
    #define DP_D2C_WAV_REQ              0x0010
    #define DP_D2C_WAV_REC_REQ          0x0011
    #define DP_D2C_VR_REQ               0x0012
    #define DP_D2C_CTM_VOIP_REQ         0x0014
    #define D2C_UL_DL_PCM_REC_INT_ID    0xAA55
    #define D2C_WAV_REC_REQ_ID          0xAA56
    #define D2C_SOUND_EFFECT_INT_ID     0xAA57 
    #define D2C_AUDIO_VIA_BT_ID         0xCC66
    #define D2C_RINI_ID                 0x6688

    //Audio
    #define DP_D2C_WT_INT               0x0013
    #define DP_D2C_PCMROUNT_INT         0xABCD
    #define DP_D2C_MP3_INT              0x1111
    #define DP_D2C_AAC_CT_INT           0x2222
    #define DP_D2C_WMA_INT              0x3333
    #define DP_D2C_AWB_PLUS_INT         0xBBBB
    #define DP_D2C_AUDLP_ERR            0xEECC
    #define DP_D2C_AVSYNC_A2V_INT       0x1234
    #define DP_D2C_SBC_INT              0xA4BC
    #define DP_D2C_I2S_REC_INT          0x1414
    #define DP_D2C_COOK_INT             0x1313
    
    //Other
    #define D2C_INT6_MAGIC              0xDD66
    #define D2C_DSP_DEAD_INT_ID         0xDD44
    #define D2C_MPU_ERROR               0x002A
#endif

/* -------------------------------------------------------------------------- */ 
/* Old DSP to MCU interrupt magic number definition rename                    */
/* -------------------------------------------------------------------------- */   
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
    #define DP_D2C_PCM_P                DP_D2C_WAV_REQ          
#else   // chip compile option
    #define DP_D2C_3G                   DP_D2C_3G_DONE          
    #define DP_D2C_PCM_P                DP_D2C_WAV_REQ          
    #define DP_D2C_PCM_R                DP_D2C_WAV_REC_REQ      
    #define DP_D2C_PCM_EX               DP_D2C_CTM_VOIP_REQ     
    #define DP_D2C_PCM_TCH_R            D2C_UL_DL_PCM_REC_INT_ID
    #define DP_D2C_WAV_REC              D2C_WAV_REC_REQ_ID      
    #define DP_D2C_ADAPT_VOL            D2C_RINI_ID             
    #define SND_EFFECT_MAGIC_NO         D2C_SOUND_EFFECT_INT_ID
#endif  // chip compile option
                                        
    #define DP_D2C_WT                   DP_D2C_WT_INT           
    #define DP_D2C_PCM_RUT              DP_D2C_PCMROUNT_INT     
    #define DP_D2C_DAF                  DP_D2C_MP3_INT          
    #define DP_D2C_AAC                  DP_D2C_AAC_CT_INT       
    #define DP_D2C_WMA                  DP_D2C_WMA_INT          
    #define DP_D2C_AWBPLUS              DP_D2C_AWB_PLUS_INT     
    #define DP_D2C_AVSYNC               DP_D2C_AVSYNC_A2V_INT   
    #define DP_D2C_I2S_REC              DP_D2C_I2S_REC_INT      
    #define DP_D2C_COOK                 DP_D2C_COOK_INT
    #define D2C_MAGIC_NO_SBC            DP_D2C_SBC_INT
    #define D2C_AUDIO_VIA_8KBT_ID       D2C_AUDIO_VIA_BT_ID

#endif //__AUD_DSP_D2C_DEF__


