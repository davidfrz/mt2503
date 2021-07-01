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
 *   a2dpParser.c
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   A2DP parser component
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
#include "l1audio.h"
#include "sbc_codec.h"

#define A2DP_PAR_INTBUF_SIZE 2048

static OMX_U32 A2dpPar_MoveDataFromInputQueue(AudComHdl *hdl){
   OMX_U32 free_space, data_size, total_data; 
   OMX_U8 *pBuf;
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   A2DP_ParData  *pParData = (A2DP_ParData *) ihdl->pPrivateData;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;
   
   while (1) {
      pMedHdl->GetReadBuffer(pMedHdl, &pBuf, &data_size);
      if(0 == data_size){ //no data
         break;
      }

      free_space = pParData->bsBuf_size - pParData->bsBuf_w;
      if(data_size > free_space){
         data_size = free_space;
      }
      free_space -= data_size;
 
      memcpy((OMX_U8*)pParData->tmp_buf+pParData->bsBuf_w, pBuf, data_size *sizeof(OMX_U8));
      pParData->bsBuf_w += data_size;
      pMedHdl->ReadDataDone(pMedHdl, data_size);
      if(0 == free_space){
         break;
      }
   }

   total_data = pParData->bsBuf_w - pParData->bsBuf_r;
   return total_data;
}

static OMX_ERRORTYPE A2dpPar_Start(AudComHdl *hdl){
		 
	 AudComHdlInt *ihdl  = (AudComHdlInt *)hdl;
   A2DP_ParData  *pParData = (A2DP_ParData *) ihdl->pPrivateData;
   OMX_ERRORTYPE result = OMX_ErrorNone;
   kal_uint32 uFileSize = 0;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_START, MTKAUD_PARSER_A2DP, ihdl->mediaStatus,0,0,0,0);
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY); 
   
   ihdl->Decode_EOF        = KAL_FALSE;
   ihdl->isEOF             = KAL_FALSE; 
   ihdl->endStatus         = MEDIA_NONE;
   pParData->bsBuf_r = 0;
   pParData->bsBuf_w = 0;
   
   pParData->parHandle = SbcDecParser_Init(pParData->int_buf,0x3453);
   if(pParData->parHandle==NULL)
   {
      return OMX_ErrorUndefined;
   }
   
   ihdl->mediaStatus = COMPONENT_STATE_PLAY;  
   //To execute process function in advance to avoid buffer underflow in the next stage
  {
     kal_uint32 I;
     for (I=0; I<A2DP_PARSER_BUFNUM; I++) 
     {
        result = A2dpPar_Process_Internal(hdl);
        if (result != OMX_ErrorNone) 
        {
           mhdlException( ihdl->mhdl, MEDIA_ERROR );
           return result;
        }
     }
  }

   return OMX_ErrorNone;   
}


OMX_ERRORTYPE A2dpPar_Process_Internal(AudComHdl *hdl){
	 OMX_U32 outbufSize, inbufSize, datacount;
   OMX_U8 *inBuf, *outBuf;
   kal_int32 parse_result = 0;
	 AudComHdlInt *ihdl  = (AudComHdlInt *)hdl;
	 MHdl *pMedHdl = (MHdl *)ihdl->mhdl;
   A2DP_ParData *pParData = (A2DP_ParData *)ihdl->pPrivateData; 
   OMX_BUFFERHEADERTYPE *pBufHdr;
 
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS_I, MTKAUD_PARSER_A2DP,ihdl->isEOF,ihdl->mediaStatus, ihdl->Decode_EOF,0,0);
   if ( ihdl->Decode_EOF || ihdl->mediaStatus != COMPONENT_STATE_PLAY ){  	  
      return OMX_ErrorNone;
   }
   
   //read data from med ring buffer
   ACU_GetWriteBuffer(hdl, &outBuf, &outbufSize);
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_A2DP,outbufSize,outBuf,1,0,0,0);
   if (outbufSize == 0) 
   {
      return OMX_ErrorNone;
   }
   
   pBufHdr = ihdl->OutputQ.pCurBufHdr;
     
   inbufSize = A2dpPar_MoveDataFromInputQueue(hdl);
   datacount = inbufSize;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_A2DP,inbufSize,0,2,0,0);
   if(pMedHdl->eof||inbufSize)
   {
#if !defined(SBC_UT)      
      
      //put data from med ring buffer and extract SBC frames     
      parse_result = SbcDecParser_Process(pParData->parHandle, (OMX_U8*)pParData->tmp_buf, &inbufSize, (OMX_U8*)outBuf, &outbufSize);                                                                                                                                                                                                                           
      if(parse_result)
      {
      	 kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_ERR, MTKAUD_PARSER_A2DP,parse_result,0,3,0,0,0);
         return OMX_ErrorStreamCorrupt;
      }
      kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PAR_OK, MTKAUD_PARSER_A2DP,inbufSize,outbufSize,4,0,0);
#else
      if(inbufSize > outbufSize)
      {
      	  inbufSize=outbufSize;
      }	
      memcpy(outBuf, inBuf, inbufSize);
      outbufSize = inbufSize;     	
#endif                        
      pParData->bsBuf_r += inbufSize;
      if(pParData->bsBuf_r !=0){
         memcpy((OMX_U8*)pParData->tmp_buf ,(OMX_U8*)pParData->tmp_buf+pParData->bsBuf_r ,(datacount-inbufSize)*sizeof(OMX_U8));
         pParData->bsBuf_r = 0;
         pParData->bsBuf_w = datacount-inbufSize;
      }      
      if(ihdl->isEOF || 512 <= (pBufHdr->nFilledLen + outbufSize))
      {
         ACU_WriteDataDone_ImmediateCallback(hdl, outbufSize);
      }
      else
      {
         ACU_WriteDataDone(hdl, outbufSize);
      }
      if(pMedHdl->eof)
      {
      	 ihdl->isEOF = KAL_TRUE;
         ihdl->Decode_EOF = KAL_TRUE;
         pBufHdr->nFlags |= OMX_BUFFERFLAG_EOS;
         ACU_SendCommand(ihdl, 0, OMX_EventBufferFlag, 1, pBufHdr->nFlags, pBufHdr);
         kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_EOF, MTKAUD_PARSER_A2DP, 0,0,0,0,0);
      }
      else 
      {
         pBufHdr->nFlags &= ~OMX_BUFFERFLAG_EOS;
      }
   }
     
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE A2dpPar_Process(AudComHdl *hdl){
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   MHdl *pMedHdl = (MHdl *)ihdl->mhdl;
   OMX_ERRORTYPE result = OMX_ErrorNone;         
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_PROCESS, MTKAUD_PARSER_A2DP, pMedHdl->waiting, ihdl->Decode_EOF,0,0,0);
   if (ihdl->Decode_EOF)
      return OMX_ErrorNone;
   
   result = A2dpPar_Process_Internal(hdl);
   if (result != OMX_ErrorNone) 
   {
      mhdlException( ihdl->mhdl, MEDIA_ERROR );
      return result;
   }                                  
   return OMX_ErrorNone;
}
  

static OMX_ERRORTYPE A2dpPar_Stop(AudComHdl *hdl){
   AudComHdlInt *ihdl = (AudComHdlInt *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_STOP, MTKAUD_PARSER_A2DP, ihdl->mediaStatus,ihdl->endStatus,0,0,0);
   if (ihdl->mediaStatus == COMPONENT_STATE_PLAY){
      ihdl->mediaStatus = COMPONENT_STATE_IDLE;
      ihdl->endStatus = MEDIA_TERMINATED;
   } 
   else{
      // Avoid re-entrance
      return OMX_ErrorNone;
   }   
   return OMX_ErrorNone;
}


static OMX_ERRORTYPE A2dpPar_Deinit(AudComHdl *hdl){
   AudComHdlInt *ihdl  = (AudComHdlInt *)hdl;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_DEINIT, MTKAUD_PARSER_A2DP, ihdl->mediaStatus,0,0,0,0);   
   ASSERT(ihdl->mediaStatus != COMPONENT_STATE_PLAY);
   ACU_FlushBufferQueue(hdl);   
   return OMX_ErrorNone;
}

static OMX_ERRORTYPE A2dpPar_SetParameter(AudComHdl *hdl, OMX_INDEXTYPE index, OMX_PTR pStruct){

   return OMX_ErrorNone;	
}

/*------------------------------------------------*/
/* The public functions of A2DP parser.            */
/*------------------------------------------------*/
OMX_U32 A2dpPar_GetMemSize( void ){
   OMX_U32 uTempSize, uReqSizeTotal;
   OMX_S32 int_buf_size;
   uReqSizeTotal = 0;
     
   // The memory size for AudComHdlInt
   uTempSize = (sizeof(AudComHdlInt) + 3) & ~0x3;
   uReqSizeTotal += uTempSize;
   
   // The memory for A2DP private data
   uTempSize = (sizeof(A2DP_ParData) + 3) & ~0x3;     
   uReqSizeTotal += uTempSize;
   
   SbcDecParser_GetBufferSize(&int_buf_size);
   int_buf_size =(int_buf_size + 3) & ~0x3;
   uReqSizeTotal += int_buf_size;
   uReqSizeTotal += A2DP_PAR_INTBUF_SIZE;
   return uReqSizeTotal;
}


OMX_ERRORTYPE A2dpPar_Init(
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
   uBufSize = A2dpPar_GetMemSize();
   memset(pBuffer, 0, uBufSize);
   
   // Assign and distribute the memory
   *pHandle = pBuffer;
   pBuffer8 = (kal_uint8 *)pBuffer;
   ihdl = (AudComHdlInt *)pBuffer;
   pBuffer8 += (sizeof(AudComHdlInt) + 3) & ~0x3;
   ihdl->pPrivateData = (void *)pBuffer8;   
   pBuffer8 += (sizeof(A2DP_ParData) + 3) & ~0x3;    
   
   ihdl->mediaType = MEDIA_FORMAT_A2DP;
   
   // Initialize the audio handler as default setting
   ACU_InitHdl(*pHandle, pFWData, pCallback);
   
   //The memory for A2DP parser SWIP
   {
      OMX_S32 int_buf_size;
      A2DP_ParData *pParData = (A2DP_ParData *)ihdl->pPrivateData;
      
      SbcDecParser_GetBufferSize(&int_buf_size);
      int_buf_size =(int_buf_size + 3) & ~0x3;
      
      pParData->int_buf = (void *)pBuffer8;
      pBuffer8 += int_buf_size;  
      pParData->tmp_buf = (void *)pBuffer8;
      pBuffer8 += A2DP_PAR_INTBUF_SIZE; 
      
      pParData->bsBuf_size = A2DP_PAR_INTBUF_SIZE;
   }   
      
   // Overwrite the member functions
   ihdl->basic.Start        = A2dpPar_Start;
   ihdl->basic.Stop         = A2dpPar_Stop;
   ihdl->basic.Deinit       = A2dpPar_Deinit;
   ihdl->basic.Process      = A2dpPar_Process;
   ihdl->basic.SetParameter = A2dpPar_SetParameter;

   ihdl->mediaStatus = COMPONENT_STATE_READY;
   kal_trace( TRACE_GROUP_AUD_PLAYBACK, L1AUDIO_GENERAL_INFO, AUDIO_TRACE_COMP_INIT, MTKAUD_PARSER_A2DP, ihdl->mediaStatus,0,0,0,0);
   return OMX_ErrorNone;
}


#endif // #if defined(__SBC_DECODE__)
