/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * a2dp_comp_drv.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SBC playback driver
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(SBC_DECODE)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "fsal.h"
#include "string.h"
#include "kal_trace.h"
#include "fs_errcode.h"
#include "l1audio.h"
#include "audio_enum.h"
#include "media.h"
#include "l1sp_trc.h"
#include "am.h"
#include "MedAdapt.h"
#include "common_def.h"
#include "PostProcess.h"
#include "sbc_codec.h"


const bt_a2dp_sbc_codec_cap_struct sbc_cap_snk[1] = {
   { 
      25,  // min_bit_pool
      75,  // max_bit_pool
      0xf, // block_len: all
      0xf, // subband_num: all
      0x3, // both snr/loudness
      0xf, // sample_rate: all
      0xf  // channel_mode: all
   }
};

const bt_a2dp_mp3_codec_cap_struct mp3_cap_snk[1] = {
   {
      0x01,      //Layer, b0: layerIII, b1: layerII, b0: layerI
      KAL_TRUE,  //CRC, Mandatory for sink
      0x0F,      //channel_mode, b0: joint stereo, b1: stereo, b2: dual channel, b3: mono
      KAL_FALSE, //MPF(Media Payload Format)
      0x3F,      //Sample_rate, b0: 48000, b1: 44100, b2: 32000, b3: 24000, b4: 22050, b5: 16000
      KAL_TRUE,  //VBR
      0x7FFE     //Bit-rate index
   }
};

const bt_a2dp_aac_codec_cap_struct aac_cap_snk[1] = {
   {
      0xC0,      //Object type, b4: M4-scalable, b5: M4-LTP, b6: M4-LC, b7: M2-LC
      0x0FF8,    //Sample_rate, b0~b11: 96000,88200,64000,48000,44100,32000,24000,22050,16000,12000,11025,8000
      0x03,      //Channels
      KAL_TRUE,  //VBR
      0x60000    //bit_rate, 384 Kbps
   }
};


// For component
// need to know how large the buffer size needed
static MHPB_CompList sbcDecFuncArray[4] = {
   {A2dpPar_GetMemSize, A2dpPar_Init, 4096 , A2DP_PARSER_BUFNUM},
   {SbcStrmDec_GetMemSize, SbcStrmDec_Init,  4096 , SBCDEC_DECODER_BUFNUM},
   {APMCom_GetMemSize,  APMCom_Init,  APM_OUT_BUFSIZE, APM_OUT_BUFNUM},
   {PcmSink_GetMemSize, PcmSinkGen_Init, 0, 0}
};

Media_Status A2DP_GetContentDescInfo( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *ext_param  ){
   
   return MEDIA_UNSUPPORTED_OPERATION;
}

static Media_Status a2dpMedPlay( MHdl *hdl ){
   
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   SinkParam Sink_param;
   OMX_ERRORTYPE uStatus = OMX_ErrorNone;
#if defined(__AUDIO_NOT_SUPPORTED__)
   return MEDIA_FAIL;
#endif
   PcmSink_TerminateSound();

   hdl->waiting = KAL_FALSE;
   hdl->eof = KAL_FALSE;
   ihdl->endflag = KAL_FALSE; 

   // Change status
   hdl->state = COMPONENT_STATE_PLAY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY, hdl->mediaType, hdl->state, hdl->current_time,0,0,0);

   
   if(OMX_ErrorNone != ihdl->NodeArray[0].curHdl->Start(ihdl->NodeArray[0].curHdl))
   {
      if(ihdl->mh.eof)
      {
         hdl->Stop(hdl);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 0,MEDIA_SEEK_EOF,0,0,0,0);
         return MEDIA_SEEK_EOF;
      }
      else
      {
         hdl->Stop(hdl);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 1,MEDIA_FAIL,0,0,0,0);
         return MEDIA_FAIL;
      }
   }    
     
   ihdl->NodeArray[1].curHdl->Start(ihdl->NodeArray[1].curHdl);
   
   //get ch and SR 
   if(OMX_ErrorNone != ihdl->NodeArray[1].curHdl->SetParameter(ihdl->NodeArray[1].curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param))
   {
       hdl->Stop(hdl);
       kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 2,MEDIA_FAIL,0,0,0,0);
       return MEDIA_FAIL;
   }
   
      
   if(OMX_ErrorNone != AudioDrain_Check_SR_CH(Sink_param.uSamplingFreq, Sink_param.uChannelNum)){
   	  hdl->Stop(hdl);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 3, MEDIA_FAIL,0,0,0,0);
      return MEDIA_FAIL;
      
   } 
 
   if(OMX_ErrorNone != ihdl->NodeArray[2].curHdl->SetParameter(ihdl->NodeArray[2].curHdl, OMX_IndexParamMediaTekAPMParam, &Sink_param))
   {
      hdl->Stop(hdl);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 4,MEDIA_FAIL,1,0,0,0);
      return MEDIA_FAIL;
   }
   if(OMX_ErrorNone != ihdl->NodeArray[3].curHdl->SetParameter(ihdl->NodeArray[3].curHdl, OMX_IndexParamMediaTekPcmSink, &Sink_param))
   {
      hdl->Stop(hdl);
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PLAY_ERROR, hdl->mediaType, 5,MEDIA_FAIL,1,0,0,0);
      return MEDIA_FAIL;
   }
   ihdl->NodeArray[2].curHdl->Start(ihdl->NodeArray[2].curHdl);
   ihdl->NodeArray[3].curHdl->Start(ihdl->NodeArray[3].curHdl);         

   return MEDIA_SUCCESS;		
}


static Media_Event a2dpMedProcess( MHdl *hdl, Media_Event event ){
   MHPB_Internal *ihdl = (MHPB_Internal *)hdl;
   AudComHdl *pParHdl = ihdl->NodeArray[0].curHdl;
     
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_PROCESS, hdl->mediaType, hdl, event, hdl->state, hdl->eof,0); 
   switch(event) {
      case MEDIA_END:
      case MEDIA_STOP_TIME_UP:
      case MEDIA_ERROR:
         hdl->Stop(hdl);
         break;
      case MEDIA_DATA_REQUEST:
      case MEDIA_BUFFER_UNDERFLOW:
      {
         ACU_SendProcessCommandl((AudComHdlInt *)pParHdl);     
         break;
      }      	
      default: // should never reach here
         ASSERT(0);
   }   
   return event;
}


MHdl *A2DPDec_Strm_Open(void(*handler)( MHdl *handle, Media_Event event ), STFSAL *pstFSAL, void *param){
		
	 MHdl *hdl;
	 MHPB_Internal *ihdl;

   MHPB_CompList *pArray[6] = {
      &sbcDecFuncArray[0],
      &sbcDecFuncArray[1],
      &sbcDecFuncArray[2],
      &sbcDecFuncArray[3],
      NULL,
      NULL}; 

   if (handler == NULL) 
   {
      pArray[1] = NULL;
   }
   
   hdl = MH_Component_List_Open(handler, pstFSAL, pArray);
   hdl->mediaType = MEDIA_FORMAT_A2DP;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_OPEN, hdl->mediaType, hdl, handler,0,0,0,0);  
   
   ihdl = (MHPB_Internal *)hdl;   
      
   // set SR/CH
   if(OMX_ErrorNone != ihdl->NodeArray[1].curHdl->SetParameter(ihdl->NodeArray[1].curHdl, OMX_IndexParamMediaTekSetPCMInfo, (void*)param))
   {
   	  return 0;
   }
   hdl->Play    = a2dpMedPlay;
   hdl->Resume  = a2dpMedPlay;
   hdl->Process = a2dpMedProcess;

   hdl->state = COMPONENT_STATE_IDLE;
   return hdl;
}


#endif   // #if defined(SBC_DECODE)
