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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   SbcDecoder.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   SBC stream decoder component
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
 
#if defined(SBC_DECODE)

#include "audio_enum.h"
#include "kal_trace.h"
#include "common_def.h"
#include "l1sp_trc.h"
#include "AudComUtil.h"
#include "media.h"
#include "sbc_codec.h"

/*------------------------------------------------*/
/* The private member functions of SBC decoder.   */
/*------------------------------------------------*/
static OMX_U32 sbcDec_MoveDataFromInputQueue(AudComHdl *hdl){
   OMX_U32 free_space, data_size, total_data; 
   OMX_U8 *pBufQueue;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   SBC_DecData *pDecData = (SBC_DecData *)ihdl->pPrivateData;
   
   while (1) {
      ACU_GetReadBuffer(hdl, &pBufQueue, &data_size);
      if(0 == data_size){ //no data
         if(pBufQueue){
            ACU_ReadDataDone(hdl, data_size);
         }
         break;
      }

      free_space = pDecData->bsBuf_size - pDecData->bsBuf_w;
      if(data_size > free_space){
         data_size = free_space;
      }
      free_space -= data_size;
 
      memcpy((OMX_U8*)pDecData->bs_buf+pDecData->bsBuf_w, pBufQueue, data_size *sizeof(OMX_U8));
      pDecData->bsBuf_w += data_size;

      ACU_ReadDataDone(hdl ,data_size);
      if(0 == free_space){
         break;
      }
   }

   total_data = pDecData->bsBuf_w - pDecData->bsBuf_r;
   return total_data;
}


static OMX_ERRORTYPE SbcStrmDec_Start(AudComHdl *hdl){
	 
   AudComHdlInt *ihdl  = (AudComHdlInt *)hdl;
   SBC_DecData *pDecData = (SBC_DecData *) ihdl->pPrivateData;
     
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_DECODER_SBC, ihdl->mediaStatus,0,0,0,0);

   {
      //reset data
      ihdl->isTimeUP = KAL_FALSE;
      ihdl->isEOF = KAL_FALSE;
      ihdl->Decode_EOF = KAL_FALSE;
      ihdl->endStatus = MEDIA_NONE;
      pDecData->bError = KAL_FALSE;
      pDecData->bsBuf_r = 0;
      pDecData->bsBuf_w = 0;
   } 

   pDecData->decHandle = SbcDec_Init(pDecData->int_buf);   
   if(pDecData->decHandle==NULL)
   {
      return OMX_ErrorUndefined;
   }
   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;
   
   ACU_SendProcessCommandl( ihdl );
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE SbcStrmDec_Stop(AudComHdl *hdl){
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   SBC_DecData *pDecData = (SBC_DecData *)   ihdl->pPrivateData;
   
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_STOP, MTKAUD_DECODER_SBC, ihdl->mediaStatus,ihdl->endStatus,0,0,0);
   ihdl->mediaStatus = COMPONENT_STATE_IDLE;
   ihdl->endStatus = MEDIA_TERMINATED;
   pDecData->decHandle =NULL;    
   
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE SbcStrmDec_Deinit(AudComHdl *hdl){
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEINIT, MTKAUD_DECODER_SBC, ihdl->mediaStatus,0,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);
   ACU_FlushBufferQueue(hdl);
   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE SbcStrmDec_Process(AudComHdl *hdl){
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   SBC_DecData *pDecData = (SBC_DecData *)ihdl->pPrivateData;
   OMX_U32 pcm_buf_size;
   OMX_S32 sBsLen;
   OMX_U8 *pcm_buf;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_DECODER_SBC, ihdl->mediaStatus, pDecData->bError, ihdl->Decode_EOF,0,0);
   if(ihdl->mediaStatus != COMPONENT_STATE_PLAY || pDecData->bError){
      return OMX_ErrorNone;
   }

   {
      kal_uint32 uCurrentTime = ihdl->mhdl->GetCurrentTime(ihdl->mhdl);
      if( uCurrentTime >= ihdl->mhdl->stop_time )   
      {
         if(!ihdl->isTimeUP)
         {
            ihdl->isTimeUP = KAL_TRUE;
            mhdlException( ihdl->mhdl, MEDIA_STOP_TIME_UP );
         }
         return OMX_ErrorNone;
      }
   }
    
   while(1)
   {
      OMX_U32 uOutputByte = 0;
      OMX_S32 consumBsLen = 0;
      OMX_S32 decoder_status =0 ;
      
      sBsLen = sbcDec_MoveDataFromInputQueue(hdl);
      ACU_GetWriteBuffer(hdl, &pcm_buf, &pcm_buf_size);
      
      consumBsLen = sBsLen;       //[I:input BS size; O:consume BS length ]
      uOutputByte = pcm_buf_size; //[I:valid o/p buf size; O:produced PCM length ]
      
      if(pcm_buf_size==0 || sBsLen==0 || ihdl->Decode_EOF )
         break;

      decoder_status = SbcDec_Process(pDecData->decHandle, 
                                     (OMX_U8*)pDecData->bs_buf,
                                     &consumBsLen,
                                     pcm_buf,
                                     &uOutputByte);      
                                          
      if(ihdl->isEOF){ 
      	 OMX_S32 sBsLen_temp;     	
         sBsLen_temp = sBsLen - consumBsLen;
         if(sBsLen_temp<=0){
            kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_DECODER_SBC, sBsLen_temp,decoder_status,consumBsLen,uOutputByte,0);
            ihdl->Decode_EOF = KAL_TRUE;
            ACU_SetEOS(hdl);
            ACU_WriteDataDone_ImmediateCallback(hdl, uOutputByte);
            break;
         }
      }     
      
      if(decoder_status)
      {
          pDecData->bError = KAL_TRUE;  
          kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_ERR, MTKAUD_DECODER_SBC, 1,decoder_status, 0, 0, 0, 0);
          mhdlException( ihdl->mhdl, MEDIA_ERROR );
          break;
      }
      else if (consumBsLen == 0 && uOutputByte == 0)
      {
          kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_SBC, 3, sBsLen, pcm_buf_size, 0, 0, 0);
          break;
      }
      else
      { 
     	    kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEC_OK, MTKAUD_DECODER_SBC, 2,decoder_status, consumBsLen, uOutputByte,ihdl->isEOF,0);
      	  pDecData->bsBuf_r += consumBsLen;
      	  if(pDecData->bsBuf_r !=0){
       	     memcpy((OMX_U8*)pDecData->bs_buf ,(OMX_U8*)pDecData->bs_buf+pDecData->bsBuf_r ,(sBsLen-consumBsLen)*sizeof(OMX_U8));
       	     pDecData->bsBuf_r = 0;
       	     pDecData->bsBuf_w = sBsLen-consumBsLen;
          }
          ACU_WriteDataDone_ImmediateCallback(hdl, uOutputByte);
      }                                          
   }          
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE SbcStrmDec_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct){
	 AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   SBC_DecData *pDecData = (SBC_DecData *)ihdl->pPrivateData;
   switch (index) {
   	   case OMX_IndexParamMediaTekSetPCMInfo:
       {
           kal_uint8 channel_mode, sample_rate;
           bt_a2dp_audio_cap_struct *pParam = (bt_a2dp_audio_cap_struct *)pStruct;
           if(pParam->codec_type !=1)
           {
           	   return OMX_ErrorUndefined;
           }
           channel_mode     = pParam->codec_cap.sbc.channel_mode;
           sample_rate      = pParam->codec_cap.sbc.sample_rate ;            
           
           switch (channel_mode) 
           {
              case 8:
                 pDecData->param.nChannels = 1;
                 break;
              case 4:
              case 2:
              case 1:
                 pDecData->param.nChannels = 2;
                 break;
              default:
              	 ASSERT(0);
              	 break;
           }
           
           switch (sample_rate) 
           {
              case 8:
                 pDecData->param.sampRate = 16000;
                 break;
              case 4:
              	 pDecData->param.sampRate = 32000;
                 break;
              case 2:
              	 pDecData->param.sampRate = 44100;
                 break;
              case 1:
                 pDecData->param.sampRate = 48000;
                 break;
              default:
              	 ASSERT(0);
              	 break;
           }
      }
      case OMX_IndexParamMediaTekPcmSink:
      {
         SinkParam *pParam = (SinkParam *)pStruct;
         pParam ->uSamplingFreq = pDecData->param.sampRate;
         pParam ->uChannelNum   = pDecData->param.nChannels;
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_SETPARAM, MTKAUD_DECODER_SBC, 2, pParam ->uSamplingFreq ,pParam ->uChannelNum,0,0,0);
         break;
      }  
      default:
         return OMX_ErrorNotImplemented;
   }
   return OMX_ErrorNone;
   
}

/*------------------------------------------------*/
/* The private functions of SBC decoder.          */
/*------------------------------------------------*/
OMX_U32 SbcStrmDec_GetMemSize( void ){
   OMX_U32 uTempSize, uReqSizeTotal;
   OMX_S32 int_buf_size, bs_buf_size, pcm_buf_size;
   uReqSizeTotal = 0;
   
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for SBC private data
   uTempSize = (sizeof(SBC_DecData) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   SbcDec_GetBufferSize(&bs_buf_size, &pcm_buf_size, &int_buf_size);
   int_buf_size =(int_buf_size + 3) & ~0x3;
   uReqSizeTotal += int_buf_size;
   bs_buf_size  =(bs_buf_size  + 3) & ~0x3;  
   uReqSizeTotal += bs_buf_size;
   
   return uReqSizeTotal;
}


OMX_ERRORTYPE SbcStrmDec_Init(
   AudComHdl      **pHandle,
   void           *pBuffer,
   void           *pFWData,
   AudComCallback *pCallback
){
   OMX_U32 uBufSize;
   AudComHdlInt *ihdl;
   kal_uint8 *pBuffer8;
   
   *pHandle = NULL;
   // The buffer address should be 4 bytes aligned
   ASSERT( (((kal_uint32)pBuffer) & 0x3) == 0);
   
   // Empty the memory
   uBufSize = SbcStrmDec_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;
   pBuffer8 += (sizeof(SBC_DecData) + 3) & ~0x3;   
   ihdl->mediaType = MEDIA_FORMAT_A2DP;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   //The memory for SBC decoder SWIP
   {
      OMX_S32 int_buf_size, bs_buf_size, pcm_buf_size;
      SBC_DecData *pDecData = (SBC_DecData *)ihdl->pPrivateData;
      
      SbcDec_GetBufferSize(&bs_buf_size, &pcm_buf_size, &int_buf_size);
      int_buf_size =(int_buf_size + 3) & ~0x3;
      bs_buf_size  =(bs_buf_size  + 3) & ~0x3;  
            
      pDecData->bs_buf = (void *)pBuffer8;
      pBuffer8 += bs_buf_size;
      pDecData->int_buf = (void *)pBuffer8;
      pBuffer8 += int_buf_size;   
      
      pDecData->bsBuf_size = bs_buf_size;
   }            
   
   // Overwrite the member functions
   ihdl->basic.Start        = SbcStrmDec_Start;
   ihdl->basic.Stop         = SbcStrmDec_Stop;
   ihdl->basic.Deinit       = SbcStrmDec_Deinit;
   ihdl->basic.Process      = SbcStrmDec_Process;
   ihdl->basic.SetParameter = SbcStrmDec_SetParameter;

   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_DECODER_SBC, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
} 

#endif // #if defined(__SBC_DECODE__)
