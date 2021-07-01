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
 * wav.c
 *
 * Project:
 * --------
 *   MTK6208
 *
 * Description:
 * ------------
 *   WAV/MP3 driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_general_types.h"
#include "string.h"
#include "kal_trace.h"
#include "reg_base.h"
#include "l1d_reg.h"

#include "l1sp_trc.h"
#include "l1audio.h"
#include "common_def.h"
#include "audio_def.h"
#include "media.h"
#include "wav.h"
#include "DraExport.h"

#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
struct wav_Struct wav;
#pragma arm section rwdata, rodata , zidata
struct wavHeader_Struct wavHeader;

#if !defined(__WAV_DECODE_SWIP__)

#if defined(MT6235) || defined(MT6235B) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6256_S00)
#define PAGE_NUM 2
#elif defined(MT6253) || defined(MT6251) || defined(MT6253E) || defined(MT6253L)|| defined(MT6252) || defined(MT6252H)
#define PAGE_NUM 1
#elif defined(MT6256_S01) || defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502) 
#define PAGE_NUM 5
#else
#error The new chip should define DM page number
#endif


//----------- Functions for DRA -----------
#if defined(__DRA_DECODE_SUPPORT__)

static kal_int32 draGetDataCount(wavMediaHdl *ihdl)
{
   int32 dataLen;
   
   dataLen = ihdl->wav.bsWrite - ihdl->wav.bsRead;
   if (dataLen < 0) {
      dataLen += ihdl->wav.bsSize;
   }
   return dataLen;
}

static kal_int32 draGetBytesFromBitstream(MHdl *hdl, kal_uint32 num_bytes, kal_uint8 *ptr)
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;
   int32 dataLen, segment;

   dataLen = draGetDataCount(ihdl);
   if (dataLen >= num_bytes) {
      dataLen = num_bytes;
   }

   // Firsr segment
   segment = ihdl->wav.bsSize - ihdl->wav.bsRead;
   if (segment >= dataLen) {
      segment = dataLen;
   }
   memcpy(ptr, ihdl->wav.bsBase+ihdl->wav.bsRead, segment*sizeof(kal_uint8));
   ihdl->wav.bsRead += segment;
   ptr += segment;
   if (ihdl->wav.bsRead >= ihdl->wav.bsSize) {
      ihdl->wav.bsRead = 0;
   }

   // Second segment
   segment = dataLen - segment;
   if (segment) {
      memcpy(ptr, ihdl->wav.bsBase, segment*sizeof(kal_uint8));
      ihdl->wav.bsRead = segment;
   }

   return dataLen;
}

static kal_int32 draGetBytes(MHdl *hdl, kal_uint32 num_bytes, kal_uint8 *ptr, kal_bool isSeek)
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;
   int32 uGetNByte;

   if (!ihdl->wav.isFileAccess) {
      uGetNByte = draGetBytesFromBitstream(hdl, num_bytes, ptr);
   } else if (isSeek) {
      uGetNByte = autGetBytesFromFile(hdl, ihdl->pstFSAL, ihdl->fileOffset, num_bytes, ptr);
   } else {
      uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, num_bytes, ptr);
   }
   
   return uGetNByte;
}

kal_int32 wavDraPutData( MHdl *hdl, kal_int32 buf_len )
{
   wavMediaHdl *ihdl = (wavMediaHdl *)hdl;
   kal_int32 totalLen = 0;
   kal_uint8 *pMBwrite = (kal_uint8 *)&hdl->rbInfo.rb_base[hdl->rbInfo.write];
   
   while (buf_len > 0) {
      kal_bool needCopy = KAL_TRUE;
      
      if (ihdl->wav.dra.remainOutputCount == 0) {
         int32 uGetNByte;
         kal_uint8 *pTempIn;
         kal_uint16 sync, msg, frameLen;
         kal_uint8 *pTempOut;
         int decResult = 0;
         kal_uint32 oriRead = ihdl->wav.bsRead;
         
         if (ihdl->mh.eof && (draGetDataCount(ihdl)<=1) )
            break;
         
         if ( (!ihdl->wav.isFileAccess)&&(ihdl->wav.isRunned) ) {
            break;
         }
         
         // Get 4 bytes
         pTempIn = ihdl->wav.dra.pTempInputBuf;
         uGetNByte = draGetBytes(hdl, 4, pTempIn, true);
         if (uGetNByte < 0) return -1;
         if (uGetNByte != 4) {
         	  if (!hdl->eof) {
         	     ihdl->wav.bsRead = oriRead;
         	     return 0;
         	  } else {
         	     return -2;
         	  }
         }
         sync = (pTempIn[1]<<8) | (pTempIn[0]);
         msg =  (pTempIn[3]<<8) | (pTempIn[2]);
         if (sync != 0x7FFF) {
            kal_trace(TRACE_ERROR, L1AUDIO_WAV_DRA_NO_SYNC, decResult, ihdl->fileOffset );
            return -3;
         }
         
         // To parse the msg.
         // For bit 32, 0: normal with 10 bits; 1: extended with 13 bits
         if (msg >> 15) {
            // extended
            frameLen = (msg<<1)>>3;
         } else {
            // normal
            frameLen = (msg<<1)>>6;
         }
         frameLen = frameLen * 4;
         if (frameLen < 8) return -4;
         
         if (frameLen >= WAV_MAX_DATA_REQUESTED) {
            decResult = 99;
         } else {
            // Get the entire bitstream for DRA frame
            pTempIn += 4;
            uGetNByte = draGetBytes(hdl, frameLen-4, pTempIn, false);
            if (uGetNByte < 0) return -1;
            if (uGetNByte != frameLen-4) {
           	   if (!hdl->eof) {
         	        ihdl->wav.bsRead = oriRead;
         	        return 0;
         	     } else {
         	        return -2;
         	     }
            }
            
            // Compare the free size between Media buffer and output buffer
            if (buf_len >= DRA_TEMP_OUTPUT_BUFFER_SIZE) {
               needCopy = KAL_FALSE;
               pTempOut = pMBwrite;
            } else {
               pTempOut = ihdl->wav.dra.pTempOutputBuf;
            }
            
            // To execute the decoder
            decResult = DRA_DecodeFrame(ihdl->wav.dra.pDecoder, ihdl->wav.dra.pTempInputBuf, frameLen, pTempOut,
                                        &ihdl->wav.dra.remainOutputCount, ihdl->wav.dra.mixMode, ihdl->wav.dra.nBitPcm, &ihdl->wav.dra.frameInfo);
            ihdl->wav.isRunned = true;
         }
         switch (decResult) {
            case 0:
               // Successful
               ihdl->wav.dra.readOffset = 0;
               if (!needCopy) {
                  int segment = ihdl->wav.dra.remainOutputCount;
                  
                  // Update data count
                  buf_len -= segment;
                  ihdl->wav.dra.remainOutputCount = 0;
                  totalLen += segment;
                  pMBwrite += segment;
               }
               ihdl->curFrame++;
               ihdl->fileOffset+=frameLen;
#if defined(__DRA_DECODE_SUPPORT__)
               if (ihdl->wav.isDRA)
               { 
                  if(ihdl->AudioSeekTbl != 0)
                  {
                     //AST_UpdateTable(ihdl->AudioSeekTbl, ihdl->fileOffset, ihdl->curFrame);
                     if ((ihdl->curFrame & 0x3F) == 0x3F)
                     {
                        ihdl->isUpdateDur = true;
                     }
                  }
               }
#endif
               break;
            case 1:
            case 5:
            case 10:
            case 11:
            case 99:
               // Discard frame
               needCopy = false;
               ihdl->curFrame++;
               ihdl->fileOffset+=frameLen;
#if defined(__DRA_DECODE_SUPPORT__)
               if (ihdl->wav.isDRA)
               { 
               	  if(ihdl->AudioSeekTbl != 0)
               	  {               	
                     //AST_UpdateTable(ihdl->AudioSeekTbl, ihdl->fileOffset, ihdl->curFrame);
                     if ((ihdl->curFrame & 0x3F) == 0x3F)
                     {
                        ihdl->isUpdateDur = true;
                     }
                  }  
               }
#endif
               kal_trace(TRACE_ERROR, L1AUDIO_WAV_DRA_ERROR, decResult, ihdl->fileOffset);
               break;
            default:
               kal_trace(TRACE_ERROR, L1AUDIO_WAV_DRA_ERROR, decResult, ihdl->fileOffset);
               return -4;
         }
      }
      
      // Move data from ihdl->wav.dra.pTempOutputBuf to media buffer
      if (needCopy) {
         kal_int32 segment;
         
         if (buf_len > ihdl->wav.dra.remainOutputCount)
            segment = ihdl->wav.dra.remainOutputCount;
         else
            segment = buf_len;
         
         // Copy data
         memcpy(pMBwrite, ihdl->wav.dra.pTempOutputBuf + ihdl->wav.dra.readOffset, segment*sizeof(kal_uint8));
         
         // Update data count
         buf_len -= segment;
         ihdl->wav.dra.remainOutputCount -= segment;
         ihdl->wav.dra.readOffset += segment;
         totalLen += segment;
         pMBwrite += segment;
      }
   }

   return totalLen;
}
#endif

/* Note: for ROM code start */
#ifndef __ROMSA_SUPPORT__
struct wavHeader_Struct wavHeader;

#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
struct wav_Struct wav;
#pragma arm section rwdata, rodata , zidata

#define wavShiftReadPointer() \
{ \
   read_cache++; \
   ptr++; \
   if( read_cache == rb_size_cache ) { \
      read_cache = 0; \
      ptr = wav.ctrl->rb_base; \
   } \
}
#endif
/* Note: for ROM code end */


#pragma arm section code = "INTERNCODE"

void (*wavMS_ADPCM_Decode)( wavMediaHdl *ihdl, uint16 data, uint32 position );
/* Note: for ROM code start */
#ifdef __ROMSA_SUPPORT__
extern void (*MS_ADPCM_Decode)( uint16 data, uint32 position );
#else
void (*MS_ADPCM_Decode)( uint16 data, uint32 position );
#endif
/* Note: for ROM code end */

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void ms_adpcm_decode_stereo( uint16 data, uint32 position )
{
   uint16 *pData;
   MS_ADPCM_STATE * state_p;
   
   pData = &wav.data[position];
   state_p = &(wav.ms_adpcm_state[0]);
   *pData = ms_adpcm_decode_sample( (uint8)(data >> 4 & 0x000F), state_p );   
   *(pData-2) = ms_adpcm_decode_sample( (uint8)(data >> 12), state_p );
   
   state_p = &(wav.ms_adpcm_state[1]);
   *(pData-1) = ms_adpcm_decode_sample( (uint8)(data & 0x000F), state_p );
   *(pData-3) = ms_adpcm_decode_sample( (uint8)(data >> 8 & 0x000F), state_p );
}
#endif /* Note: for ROM code */

#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void ms_adpcm_decode_mono( uint16 data, uint32 position )
{
   uint16 *pData = &wav.data[position];
   MS_ADPCM_STATE * state_p = &(wav.ms_adpcm_state[0]);
   *pData-- = ms_adpcm_decode_sample( (uint8)(data >> 4 & 0x000F), state_p );   
   *pData-- = ms_adpcm_decode_sample( (uint8)(data & 0x000F), state_p );
   *pData-- = ms_adpcm_decode_sample( (uint8)(data >> 12), state_p );
   *pData   = ms_adpcm_decode_sample( (uint8)(data >> 8 & 0x000F), state_p );
}
#endif /* Note: for ROM code */
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void wavADPCM_Decode(uint16 compressed_data, uint32 position, int8 shift, dviAdpcm_State* state)
{
   uint16 *pData = &wav.data[position];

   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
}
#endif /* Note: for ROM code */

/************************************************************/
/*  data writing to DSP ring buf via IDMA for wav playback  */
/*  Format: DVI-ADPCM (Mono)                                */
/************************************************************/
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void wavADPCMPutData( int32 dsp_len )   /* For IMA ADPCM */
{
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile uint16* idmaPtr = 0;
#endif
   const uint16 *ptr;
   uint16 *pData;
   uint16 sample = 0;
   int32 I = wav.data_count;
   uint16 dsp_w = *DSP_PCM_W;
   uint32 tmp1, tmp2, read_cache, rb_size_cache;
   bool mono2stereo = wav.ctrl->mono2stereo;
   uint8 data_count = wav.data_count;
   uint16 BlockCount = wav.BlockCount;
   uint16 wBlockAlign = wavHeader.wBlockAlign;
   int32 MBCount = wav.MBCount;

   if (mono2stereo)
      dsp_len = (dsp_len >> 1);

   if( (dsp_len <= 0) || (MBCount <= 0) )
      return;
   
// Rey: calculate the accurate sample number in media buffer and data buffer
// The media buffer is composed of: (sub-)block + Y blocks + (sub-block)
   if( MBCount > (wavHeader.wDataLength >> 1) )   // if there's junk after ssnd chunk
      MBCount = wavHeader.wDataLength >> 1;       // discard junk
   tmp1 = (wBlockAlign >> 1) - BlockCount;
   // 1. Calculate the preceding (sub-)block
   if( MBCount < tmp1 )
   {
      if( BlockCount > 0 )
         I += (MBCount << 2);
      else if( MBCount > 1 )       // wav.BlockCount==0 AND wav.MBCount >= 2
         I += (MBCount << 2) - 7;
      // End of calculation
   }
   else
   {
      // 1. Calculate the preceding (sub-)block
      I += tmp1 << 2;                  // adpcm 1:4, I is used to record the number of samples in media buffer
      if( BlockCount == 0 )        // current block count == 0: pre-sample
         I -= 7;
      MBCount -= tmp1;

      // 2. Calculate the Y blocks
      tmp1 = (wBlockAlign << 1) - 7;  // tmp1 is the total samples in a block
      tmp2 = wBlockAlign >> 1;        // tmp2 is the total words in a block
      while( MBCount >= tmp2 )
      {
         I += tmp1;
         MBCount -= tmp2;
      }
   
      // 3. Calculte the last sub-block
      // the sample number is added only if the number of remaining words in media buffer >= 2
      if( MBCount > 1 )                     // if( wav.MBCount >= 2 )
         I += (MBCount << 2) - 7;
   }
   if(I < dsp_len)
      dsp_len = I;

   read_cache = wav.ctrl->read;
   rb_size_cache = wav.ctrl->rb_size;
   ptr = &wav.ctrl->rb_base[read_cache];
   pData = &wav.data[data_count];
   tmp1 = mediaGetDataCount();
   for( I = dsp_len; I > 0; I-- ) {
      if(data_count == 0)
      {
         if( BlockCount )
         {
            wavADPCM_Decode( *ptr, 3, 1, &wav.dvi_state_ch1);
            wavShiftReadPointer();
            BlockCount++;
            data_count = 4;
            pData += 4;
            
            if(BlockCount == (wBlockAlign >> 1))
               BlockCount = 0;
         }
         else
         {
            wav.dvi_state_ch1.valpred = (int32)((int16)*ptr);
            *pData++ = *ptr;
            wavShiftReadPointer();
            wav.dvi_state_ch1.index = *ptr;
            wavShiftReadPointer();
            BlockCount = 2;
            data_count = 1;
         }
      }
      sample = *--pData;
      data_count--;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
      if(I==dsp_len)
      { 
         idmaPtr=DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w);
	       *idmaPtr++=sample;
	       if (mono2stereo)
	         *idmaPtr++=sample;
      }
      else
      {
         *idmaPtr++=sample;
	       if (mono2stereo)
	         *idmaPtr++=sample;
      }      
#else
      if( I != dsp_len ) 
      {
         *IDMA_SHORT_ADDR = sample;
         if (mono2stereo)
            *IDMA_SHORT_ADDR = sample;
      }
      else
      {
         *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = sample;
         if (mono2stereo)
            *IDMA_SHORT_ADDR = sample;
      }
#endif
   }
   wav.data_count = data_count;
   wav.BlockCount = BlockCount;
   wav.MBCount = MBCount;
   wav.ctrl->read = read_cache;
   wav.ctrl->dsp_last_sample = sample;
   
   tmp1 -= mediaGetDataCount();
   if( (tmp1 << 1) >= wavHeader.wDataLength )
      wavHeader.wDataLength = 0;
   else
      wavHeader.wDataLength -= (tmp1 << 1);

   if (mono2stereo)
      dsp_w += (dsp_len << 1);
   else
   	  dsp_w += dsp_len;

   if( dsp_w == wav.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}
#endif /* Note: for ROM code */

/************************************************************/
/*  data writing to DSP ring buf via IDMA for wav playback  */
/*  Format: DVI-ADPCM (Stereo)                                */
/************************************************************/
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void wavADPCMPutData_ST( int32 dsp_len )    /* For IMA ADPCM stereo */
{
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile uint16* idmaPtr = 0;
#endif	
   const uint16 *ptr;
   uint16 *pData;
   int32 I = wav.data_count;
   uint16 dsp_w = *DSP_PCM_W;
   uint32 read_cache, rb_size_cache;
   uint32 tmp1;
   uint8 data_count = wav.data_count;
   uint16 BlockCount = wav.BlockCount;
   int32 MBCount = wav.MBCount;
   uint16 wBlockAlign = wavHeader.wBlockAlign;
   
   if( (dsp_len <= 0) || (MBCount <= 0) )
      return;
      
// Rey: calculate the accurate sample number in media buffer and data buffer
// The media buffer is composed of: (sub-)block + Y blocks + (sub-block)   
   if( MBCount > (wavHeader.wDataLength >> 1) )
      MBCount = wavHeader.wDataLength >> 1;    // discard the junk after valid data
   tmp1 = (wBlockAlign >> 1) - BlockCount;
   // 1. Calculate the preceding (sub-)block
   if( MBCount < tmp1 )
   {
      MBCount &= 0xFFFFFFFC;
      if( MBCount )
      {
         I += MBCount << 2;     // adpcm 1:4, I is used to record the number of samples in media buffer
         if( BlockCount == 0 )  // current block count == 0: pre-sample
            I -= 14;
      }
      // End of calculation
   }
   else
   {
      // 1. Calculate the preceding (sub-)block
      I += tmp1 << 2;               // adpcm 1:4, I is used to record the number of samples in media buffer
      if( BlockCount == 0 )     // current block count == 0: pre-sample
         I -= 14;
      MBCount -= tmp1;

      // 2. Calculate the Y blocks
      tmp1 = (wBlockAlign << 1) - 14;    // tmp1 is the total samples in a block
      rb_size_cache = wBlockAlign >> 1;  // rb_size_cache is the total words in a block
      while( MBCount >= rb_size_cache )
      {
         I += tmp1;
         MBCount -= rb_size_cache;
      }
   
      // 3. Calculte the last sub-block
      // the sample number is added only if the number of remaining words in media buffer >= 4
      MBCount &= 0xFFFFFFFC;             // wav.MBCount -= wav.MBCount % 4;
      if( MBCount )                      // if( wav.MBCount >= 4 )
         I += (MBCount << 2) - 14;
   }
   if(I < dsp_len)
      dsp_len = I;

   tmp1 = mediaGetDataCount();
   read_cache = wav.ctrl->read;
   rb_size_cache = wav.ctrl->rb_size;
   ptr = &wav.ctrl->rb_base[read_cache];
   pData = &wav.data[data_count];
   for( I = dsp_len; I > 0; I-- ) {
      if(data_count == 0)
      {
         if(BlockCount != 0) {
            dviAdpcm_State *state;

            /* Left channel , 1st word */
            state = &wav.dvi_state_ch1;
            wavADPCM_Decode( *ptr, 15, 2, state);
            wavShiftReadPointer();
         
            /* 2nd word */
            wavADPCM_Decode( *ptr, 7, 2, state);
            wavShiftReadPointer();
         
            /* Ritht channel , 3rd word */
            state++; /* &wav.dvi_state_right_channel */
            wavADPCM_Decode( *ptr, 14, 2, state);
            wavShiftReadPointer();
         
            /* 4th word */
            wavADPCM_Decode( *ptr, 6, 2, state);
            wavShiftReadPointer(); 

            BlockCount += 4;
            data_count = 16;
            pData += 16;
            if(BlockCount == (wBlockAlign >> 1))
               BlockCount = 0;
         } else {      /* first sample */
            wav.dvi_state_ch1.valpred = (int32)((int16)*ptr); /* 1st word */
            wav.data[1] = (int32)((int16)*ptr);
            wavShiftReadPointer();
      
            wav.dvi_state_ch1.index = (int32)*ptr;
            wavShiftReadPointer();
      
            wav.dvi_state_ch2.valpred = (int32)((int16)*ptr);  /* 3rd word */
            wav.data[0] = (int32)((int16)*ptr);
            wavShiftReadPointer();
      
            wav.dvi_state_ch2.index = (int32)*ptr;
            wavShiftReadPointer();

            BlockCount = 4;
            data_count = 2;
            pData += 2;
         }
      }

      data_count--; 
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
      if ( I == dsp_len )
      {
         idmaPtr=DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) ;
	       *idmaPtr++ = *--pData;
      }
      else
         *idmaPtr++ = *--pData;
#else
      if ( I != dsp_len )
         *IDMA_SHORT_ADDR = *--pData;
      else
         *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = *--pData;
#endif
   }
   wav.data_count = data_count;    // Update the value
   wav.BlockCount = BlockCount;
   wav.MBCount = MBCount;
   wav.ctrl->read = read_cache;
   wav.ctrl->dsp_last_sample = *ptr;

   tmp1 -= mediaGetDataCount();
   if( (tmp1 << 1) >= wavHeader.wDataLength )
      wavHeader.wDataLength = 0;
   else
      wavHeader.wDataLength -= (tmp1 << 1);

   dsp_w+=dsp_len;                /* Update DSP writing pointer */
   if( dsp_w == wav.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}
#endif /* Note: for ROM code */

//  Microsoft ADPCM mono/stereo Playback
#ifndef __ROMSA_SUPPORT__ /* Note: for ROM code */
void wavMSADPCMPutData( int32 dsp_len )   /* For MS ADPCM */
{
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE
   volatile uint16* idmaPtr = 0;
#endif
   const uint16 *ptr;
   uint16 *pData;
   uint16 sample = 0;
   uint16 dsp_w = *DSP_PCM_W;
   uint16 read_cache, rb_size_cache;
   int32 I = wav.data_count;
   uint32 tmp1, tmp2;
   bool is_stereo = wav.ctrl->is_stereo;
   bool mono2stereo = wav.ctrl->mono2stereo;
   uint8 data_count;
   int32 MBCount = wav.MBCount;
   uint16 wBlockAlign = wavHeader.wBlockAlign;
   uint16 BlockCount = wav.BlockCount;

   MS_ADPCM_STATE * ms_adpcm_state_p0 = &(wav.ms_adpcm_state[0]);
   MS_ADPCM_STATE * ms_adpcm_state_p1 = &(wav.ms_adpcm_state[1]);

   if (mono2stereo)
      dsp_len = (dsp_len >> 1);

   if( (dsp_len <= 0) || (MBCount <= 0) )
      return;
   
// Rey: calculate the accurate sample number in media buffer and data buffer
// The media buffer is composed of: (sub-)block + Y blocks + (sub-block)
   if( MBCount > (wavHeader.wDataLength >> 1) )   // if there's junk after ssnd chunk
      MBCount = wavHeader.wDataLength >> 1;       // discard junk
   tmp1 = (wBlockAlign >> 1) - BlockCount;
   // 1. Calculate the preceding (sub-)block
   if( MBCount < tmp1 )
   {
      if( BlockCount > 0 )
         I += (MBCount << 2);
      else
      {
         if( is_stereo && MBCount > 6 )
         {
            // wav.BlockCount == 0 AND wav.MBCount >= 7
            I += (MBCount << 2) - 24;
         }
         else if( !is_stereo && MBCount > 3 )
         {
            // wav.BlockCount == 0 AND wav.MBCount >= 4
            I += (MBCount << 2) - 12;
         }
      }
      // End of calculation
   }
   else
   {
      // 1. Calculate the preceding (sub-)block
      I += tmp1 << 2;                  // adpcm 1:4, I is used to record the number of samples in media buffer
      if( BlockCount == 0 )        // current block count == 0: pre-sample
      {
         if( is_stereo )
            I -= 24;
         else
            I -= 12;
      }
      MBCount -= tmp1;

      // 2. Calculate the Y blocks
      if( is_stereo )
         tmp1 = (wBlockAlign << 1) - 24; // tmp1 is the total samples in a block
      else
         tmp1 = (wBlockAlign << 1) - 12; // tmp1 is the total samples in a block
      tmp2 = wBlockAlign >> 1;           // tmp2 is the total words in a block
      while( MBCount >= tmp2 )
      {
         I += tmp1;
         MBCount -= tmp2;
      }
   
      // 3. Calculte the last sub-block
      // the sample number is added only if the number of remaining words in media buffer >= 2
      if( is_stereo && MBCount > 6 )
      {
         // wav.BlockCount == 0 AND wav.MBCount >= 7
         I += (MBCount << 2) - 24;
      }
      else if( !is_stereo && MBCount > 3 )
      {
         // wav.BlockCount == 0 AND wav.MBCount >= 4
         I += (MBCount << 2) - 12;
      }
   }
   if(I < dsp_len)
      dsp_len = I;

   tmp1 = mediaGetDataCount();
   data_count = wav.data_count;
   read_cache = wav.ctrl->read;
   rb_size_cache = wav.ctrl->rb_size;
   ptr = &wav.ctrl->rb_base[read_cache];
   pData = &wav.data[data_count];
   for( I = dsp_len; I > 0; I-- ) {
      if (data_count == 0)
      {
         if( BlockCount )
         {
            MS_ADPCM_Decode( *ptr, 3 );
            wavShiftReadPointer();

            BlockCount++;
            data_count = 4;
            pData += 4;

            if(BlockCount == (wBlockAlign >> 1))
               BlockCount = 0;
         }
         else
         {
            short *pMSCoeff;
            const short *pCoeff;
            uint8 bPredictor;

            wav.ctrl->read = read_cache;
            if( is_stereo ) {
               rb_GetByte( &(ms_adpcm_state_p0->bPredictor) );
               rb_GetByte( &(ms_adpcm_state_p1->bPredictor) );
               rb_GetWord( &(ms_adpcm_state_p0->iDelta) );
               rb_GetWord( &(ms_adpcm_state_p1->iDelta) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p0->iSamp1) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p1->iSamp1) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p0->iSamp2) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p1->iSamp2) );
            } else {
               rb_GetByte( &(ms_adpcm_state_p0->bPredictor) );
               rb_GetWord( &(ms_adpcm_state_p0->iDelta) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p0->iSamp1) );
               rb_GetWord( (uint16*)&(ms_adpcm_state_p0->iSamp2) );
            }

            bPredictor = ms_adpcm_state_p0->bPredictor;
            pMSCoeff = &ms_adpcm_state_p0->iCoeff1;
            if( bPredictor > 6 ) {
               pCoeff = wav.aCoeff[bPredictor - 7];
               *pMSCoeff++ = *pCoeff++;
               *pMSCoeff = *pCoeff;
            }
            else {
               pCoeff = iCoeff[bPredictor];
               *pMSCoeff++ = *pCoeff++;
               *pMSCoeff = *pCoeff;
            }
            
            bPredictor = ms_adpcm_state_p1->bPredictor;
            pMSCoeff = &ms_adpcm_state_p1->iCoeff1;
            if( is_stereo ) {
               if( bPredictor > 6 ) {
               	  pCoeff = wav.aCoeff[bPredictor - 7];
                  *pMSCoeff++ = *pCoeff++;
                  *pMSCoeff = *pCoeff;
               }
               else {
               	  pCoeff = iCoeff[bPredictor];
                  *pMSCoeff++ = *pCoeff++;
                  *pMSCoeff = *pCoeff;
               }
            }

            pData += 3;
            if (is_stereo) {
               *pData-- = ms_adpcm_state_p0->iSamp2;
               *pData-- = ms_adpcm_state_p1->iSamp2;
               *pData-- = ms_adpcm_state_p0->iSamp1;
               *pData = ms_adpcm_state_p1->iSamp1;
               BlockCount = 7;
            } else {
               uint8 tmp_byte;
               rb_GetByte( &tmp_byte ); 
               *pData-- = ms_adpcm_state_p0->iSamp2;
               *pData-- = ms_adpcm_state_p0->iSamp1;
               *pData-- = ms_adpcm_decode_sample( tmp_byte >> 4, ms_adpcm_state_p0 );   
               *pData = ms_adpcm_decode_sample( tmp_byte & 0x0F, ms_adpcm_state_p0 );
               BlockCount = 4;
            }
            read_cache = wav.ctrl->read;
            ptr = &wav.ctrl->rb_base[read_cache];
            data_count = 4;
            pData += 4;
         }
      }
      sample = *--pData;
      data_count--;
#ifdef L1AUDIO_IDMA_ALL_ADDRESS_MODE      
      if( I == dsp_len )
      {
      	idmaPtr=DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w);
	      *idmaPtr++=sample;
        if (mono2stereo)
	        *idmaPtr++=sample;
      }
      else
      {
      	*idmaPtr++=sample;
      	if (mono2stereo)
	        *idmaPtr++=sample;
      }
#else
      if( I != dsp_len ) {
         *IDMA_SHORT_ADDR = sample;
         if (mono2stereo)
            *IDMA_SHORT_ADDR = sample;
      } else {
         *DSP_DM_ADDR(PAGE_NUM, wav.ctrl->dsp_rb_base + dsp_w) = sample;
         if (mono2stereo)
            *IDMA_SHORT_ADDR = sample;
      }
#endif
   }
   wav.MBCount = MBCount;    // Update the value
   wav.BlockCount = BlockCount;
   wav.data_count = data_count;
   wav.ctrl->read = read_cache;
   wav.ctrl->dsp_last_sample = sample;
   
   tmp1 -= mediaGetDataCount();
   if( (tmp1 << 1) >= wavHeader.wDataLength )
      wavHeader.wDataLength = 0;
   else
      wavHeader.wDataLength -= (tmp1 << 1);

   if (mono2stereo)
      dsp_w += (dsp_len << 1);
   else
      dsp_w += dsp_len;

   if( dsp_w == wav.ctrl->dsp_rb_size )
      dsp_w = 0;
   *DSP_PCM_W = dsp_w;
}
#endif /* Note: for ROM code */

#ifndef __L1_STANDALONE__  // avoid link error
// Audio Framework Revise
static void wavDviADPCM_Decode(wavMediaHdl *ihdl, uint16 compressed_data, uint32 position, int8 shift, dviAdpcm_State* state)
{
   uint16 *pData = &ihdl->wav.data[position];

   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
   pData -= shift;
   compressed_data = compressed_data >> 4;
   *pData = dviAdpcm_Decode( (compressed_data & 0xF), state );
}

kal_int32 wavDviADPCMPutDataMono( MHdl *hdl, kal_int32 buf_len )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   kal_uint16 *pMBwrite = (kal_uint16 *)&hdl->rbInfo.rb_base[hdl->rbInfo.write];
   const uint16 *ptr = &ihdl->buf[(ihdl->wav.BlockCount/2)%WAV_MAX_DATA_REQ_WORD];
   uint16 *pData;
   int32 I;
   uint8 data_count = ihdl->wav.data_count;
   uint16 BlockCount = ihdl->wav.BlockCount;
   uint16 wBlockAlign = ihdl->wav.wBlockAlign;
   int32 uGetNByte;

   pData = &ihdl->wav.data[data_count];
   buf_len = buf_len >> 1;
   for( I = buf_len; I > 0; I-- ) {
      if(data_count == 0)
      {
         if( BlockCount )
         {
            if ( (BlockCount % WAV_MAX_DATA_REQUESTED) == 0) {
         	  	 uint32 len = wBlockAlign - BlockCount;
         	  	 if(len > WAV_MAX_DATA_REQUESTED)
         	  	 	  len = WAV_MAX_DATA_REQUESTED;
         	     uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	     if(uGetNByte < 0) return -1;
         	     if(uGetNByte != len) break;
         	     ptr = &ihdl->buf[0];
         	  }
            wavDviADPCM_Decode( ihdl, *ptr, 3, 1, &ihdl->wav.dvi_state_ch1);
            ptr++;
            BlockCount += 2;
            data_count = 4;
            pData += 4;

            if(BlockCount == wBlockAlign)
               BlockCount = 0;
         }
         else
         {
         	  uint32 len = wBlockAlign;
         	  ptr = &ihdl->buf[0];
         	  if(len > WAV_MAX_DATA_REQUESTED)
         	  	  len = WAV_MAX_DATA_REQUESTED;
         	  uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	  if(uGetNByte < 0) return -1;
         	  if(uGetNByte != len) break;

            ihdl->wav.dvi_state_ch1.valpred = (int32)((int16)*ptr);
            *pData++ = *ptr;
            ptr++;

            ihdl->wav.dvi_state_ch1.index = *ptr;
            ptr++;
            BlockCount = 4;
            data_count = 1;
         }
      }
      *pMBwrite++ = *--pData;
      data_count--;
   }
   ihdl->wav.dsp_last_sample = *pData;
   ihdl->wav.data_count = data_count;
   ihdl->wav.BlockCount = BlockCount;

   return ((buf_len - I) << 1);
}

kal_int32 pcmDviADPCMPutDataMono( MHdl *hdl, kal_int32 buf_len )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   kal_uint16 *pMBwrite = (kal_uint16 *)&hdl->rbInfo.rb_base[hdl->rbInfo.write];
   const uint16 *ptr = &ihdl->buf[ihdl->wav.BlockCount/2];
   uint16 *pData;
   int32 I;
   uint8 data_count = ihdl->wav.data_count;
   uint16 BlockCount = ihdl->wav.BlockCount;
   uint16 wBlockAlign = ihdl->wav.wBlockAlign;
   int32 uGetNByte;

   pData = &ihdl->wav.data[data_count];
   buf_len = buf_len >> 1;
   for( I = buf_len; I > 0; I-- ) {
      if(data_count == 0)
      {
         if (BlockCount == 0) {
            if (hdl->eof)
               break;

            //wBlockAlign = WAV_MAX_DATA_REQUESTED;
            uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, wBlockAlign, (kal_uint8 *)&ihdl->buf[0]);
            ptr = (kal_uint16 *)&ihdl->buf[0];
            if(uGetNByte != wBlockAlign) {
               wBlockAlign = uGetNByte & 0xFFFE;
               ihdl->wav.wBlockAlign = wBlockAlign;
               hdl->eof = true;
            }
            BlockCount = 0;
         }

         wavDviADPCM_Decode( ihdl, *ptr, 3, 1, &ihdl->wav.dvi_state_ch1);
         ptr++;
         BlockCount += 2;
         data_count = 4;
         pData += 4;

         if(BlockCount == wBlockAlign)
            BlockCount = 0;
      }
      *pMBwrite++ = *--pData;
      data_count--;
   }
   ihdl->wav.dsp_last_sample = *pData;
   ihdl->wav.data_count = data_count;
   ihdl->wav.BlockCount = BlockCount;

   return ((buf_len - I) << 1);
}


kal_int32 wavDviADPCMPutData_ST( MHdl *hdl, kal_int32 buf_len )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   kal_uint16 *pMBwrite = (kal_uint16 *)&hdl->rbInfo.rb_base[hdl->rbInfo.write];
   const uint16 *ptr = &ihdl->buf[(ihdl->wav.BlockCount/2)%WAV_MAX_DATA_REQ_WORD];
   uint16 *pData;
   int32 I;
   uint8 data_count = ihdl->wav.data_count;
   uint16 BlockCount = ihdl->wav.BlockCount;
   uint16 wBlockAlign = ihdl->wav.wBlockAlign;
   int32 uGetNByte;

   pData = &ihdl->wav.data[data_count];
   buf_len = buf_len >> 1;
   for( I = buf_len; I > 0; I-- ) {
      if(data_count == 0)
      {
         if(BlockCount != 0) {
            dviAdpcm_State *state;

            if ( (BlockCount % WAV_MAX_DATA_REQUESTED) == 0) {
         	  	 uint32 len = wBlockAlign - BlockCount;
         	  	 if(len > WAV_MAX_DATA_REQUESTED)
         	  	 	  len = WAV_MAX_DATA_REQUESTED;
         	     uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	     if(uGetNByte < 0) return -1;
         	     if(uGetNByte != len) break;
         	     ptr = &ihdl->buf[0];
         	  }
            /* Left channel , 1st word */
            state = &ihdl->wav.dvi_state_ch1;
            wavDviADPCM_Decode( ihdl, *ptr, 15, 2, state);
            ptr++;

            /* 2nd word */
            wavDviADPCM_Decode( ihdl, *ptr, 7, 2, state);
            ptr++;

            /* Ritht channel , 3rd word */
            state++; /* &wav.dvi_state_right_channel */
            wavDviADPCM_Decode( ihdl, *ptr, 14, 2, state);
            ptr++;

            /* 4th word */
            wavDviADPCM_Decode( ihdl, *ptr, 6, 2, state);
            ptr++;

            BlockCount += 8;
            data_count = 16;
            pData += 16;
            if(BlockCount == wBlockAlign)
               BlockCount = 0;
         } else {      /* first sample */
             {
         	  uint32 len = wBlockAlign;
         	  ptr = &ihdl->buf[0];
         	  if(len > WAV_MAX_DATA_REQUESTED)
         	  	  len = WAV_MAX_DATA_REQUESTED;
         	  uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	  if(uGetNByte < 0) return -1;
         	  if(uGetNByte != len) break;
         	 }

            ihdl->wav.dvi_state_ch1.valpred = (int32)((int16)*ptr); /* 1st word */
            ihdl->wav.data[1] = (int32)((int16)*ptr);
            ptr++;

            ihdl->wav.dvi_state_ch1.index = (int32)*ptr;
            ptr++;

            ihdl->wav.dvi_state_ch2.valpred = (int32)((int16)*ptr);  /* 3rd word */
            ihdl->wav.data[0] = (int32)((int16)*ptr);
            ptr++;

            ihdl->wav.dvi_state_ch2.index = (int32)*ptr;
            ptr++;

            BlockCount = 8;
            data_count = 2;
            pData += 2;
         }
      }
      *pMBwrite++ = *--pData;
      data_count--;
   }
   ihdl->wav.dsp_last_sample = *pData;
   ihdl->wav.data_count = data_count;    // Update the value
   ihdl->wav.BlockCount = BlockCount;

   return ((buf_len - I) << 1);
}

void wavMSADPCM_decode_stereo( wavMediaHdl *ihdl, uint16 data, uint32 position )
{
   uint16 *pData;
   MS_ADPCM_STATE * state_p;

   pData = &ihdl->wav.data[position];
   state_p = &(ihdl->wav.ms_adpcm_state[0]);
   *pData = ms_adpcm_decode_sample( (uint8)(data >> 4 & 0x000F), state_p );
   *(pData-2) = ms_adpcm_decode_sample( (uint8)(data >> 12), state_p );

   state_p = &(ihdl->wav.ms_adpcm_state[1]);
   *(pData-1) = ms_adpcm_decode_sample( (uint8)(data & 0x000F), state_p );
   *(pData-3) = ms_adpcm_decode_sample( (uint8)(data >> 8 & 0x000F), state_p );
}

void wavMSADPCM_decode_mono( wavMediaHdl *ihdl, uint16 data, uint32 position )
{
   uint16 *pData = &ihdl->wav.data[position];
   MS_ADPCM_STATE * state_p = &(ihdl->wav.ms_adpcm_state[0]);
   *pData-- = ms_adpcm_decode_sample( (uint8)(data >> 4 & 0x000F), state_p );
   *pData-- = ms_adpcm_decode_sample( (uint8)(data & 0x000F), state_p );
   *pData-- = ms_adpcm_decode_sample( (uint8)(data >> 12), state_p );
   *pData   = ms_adpcm_decode_sample( (uint8)(data >> 8 & 0x000F), state_p );
}

//  Microsoft ADPCM mono/stereo Playback   /* For MS ADPCM */
kal_int32 wavMSADPCMPutDataMonoST( MHdl *hdl, kal_int32 buf_len )
{
   wavMediaHdl *ihdl = (wavMediaHdl *) hdl;
   kal_uint16 *pMBwrite = (kal_uint16 *)&hdl->rbInfo.rb_base[hdl->rbInfo.write];
   const uint16 *ptr = &ihdl->buf[(ihdl->wav.BlockCount/2)%WAV_MAX_DATA_REQ_WORD];
   uint16 *pData;
   int32 I;
   bool is_stereo = ihdl->wav.is_stereo;

   uint8 data_count = ihdl->wav.data_count;
   uint16 wBlockAlign = ihdl->wav.wBlockAlign;
   uint16 BlockCount = ihdl->wav.BlockCount;
   int32 uGetNByte;

   MS_ADPCM_STATE * ms_adpcm_state_p0 = &(ihdl->wav.ms_adpcm_state[0]);
   MS_ADPCM_STATE * ms_adpcm_state_p1 = &(ihdl->wav.ms_adpcm_state[1]);

   pData = &ihdl->wav.data[data_count];
   buf_len = buf_len >> 1;
   for( I = buf_len; I > 0; I-- ) {
      if (data_count == 0)
      {
         if( BlockCount )
         {
         	  if ( (BlockCount % WAV_MAX_DATA_REQUESTED) == 0) {
         	  	 uint32 len = wBlockAlign - BlockCount;
         	  	 if(len > WAV_MAX_DATA_REQUESTED)
         	  	 	  len = WAV_MAX_DATA_REQUESTED;
         	     uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	     if(uGetNByte < 0) return -1;
         	     if(uGetNByte != len) break;
         	     ptr = &ihdl->buf[0];
         	  }

            wavMS_ADPCM_Decode( ihdl, *ptr, 3 );
            ptr++;

            BlockCount+=2;
            data_count = 4;
            pData += 4;

            if(BlockCount == wBlockAlign )
               BlockCount = 0;
         }
         else
         {
            short *pMSCoeff;
            const short *pCoeff;
            uint8 bPredictor;
            {
         	  uint32 len = wBlockAlign;
         	  ptr = &ihdl->buf[0];
         	  if(len > WAV_MAX_DATA_REQUESTED)
         	  	  len = WAV_MAX_DATA_REQUESTED;
         	  uGetNByte = autGetBytes(hdl, ihdl->pstFSAL, len, (kal_uint8 *)&ihdl->buf[0]);
         	  if(uGetNByte < 0) return -1;
         	  if(uGetNByte != len) break;
         	}


            if( is_stereo ) {
               kal_uint16 tmp_buf = *ptr++;
               ms_adpcm_state_p0->bPredictor = tmp_buf & 0xFF;
               ms_adpcm_state_p1->bPredictor = (tmp_buf >> 8) & 0xFF;
               ms_adpcm_state_p0->iDelta = *ptr++;
               ms_adpcm_state_p1->iDelta = *ptr++;
               ms_adpcm_state_p0->iSamp1 = *ptr++;
               ms_adpcm_state_p1->iSamp1 = *ptr++;
               ms_adpcm_state_p0->iSamp2 = *ptr++;
               ms_adpcm_state_p1->iSamp2 = *ptr++;
            } else {
               kal_uint16 tmp;
               tmp = *ptr++;
               ms_adpcm_state_p0->bPredictor = tmp & 0xFF;
               ms_adpcm_state_p0->iDelta = tmp >> 8;
               tmp = *ptr++;
               ms_adpcm_state_p0->iDelta |= tmp << 8;
               ms_adpcm_state_p0->iSamp1 = tmp >> 8;
               tmp = *ptr++;
               ms_adpcm_state_p0->iSamp1 |= tmp << 8;
               ms_adpcm_state_p0->iSamp2 = tmp >> 8;
               tmp = *ptr;
               ms_adpcm_state_p0->iSamp2 |= tmp << 8;
            }

            bPredictor = ms_adpcm_state_p0->bPredictor;
            pMSCoeff = &ms_adpcm_state_p0->iCoeff1;
            if( bPredictor > 6 ) {
               pCoeff = ihdl->wav.aCoeff[bPredictor - 7];
               *pMSCoeff++ = *pCoeff++;
               *pMSCoeff = *pCoeff;
            }
            else {
               pCoeff = iCoeff[bPredictor];
               *pMSCoeff++ = *pCoeff++;
               *pMSCoeff = *pCoeff;
            }

            bPredictor = ms_adpcm_state_p1->bPredictor;
            pMSCoeff = &ms_adpcm_state_p1->iCoeff1;
            if( is_stereo ) {
               if( bPredictor > 6 ) {
               	  pCoeff = ihdl->wav.aCoeff[bPredictor - 7];
                  *pMSCoeff++ = *pCoeff++;
                  *pMSCoeff = *pCoeff;
               }
               else {
               	  pCoeff = iCoeff[bPredictor];
                  *pMSCoeff++ = *pCoeff++;
                  *pMSCoeff = *pCoeff;
               }
            }

            pData += 3;
            if (is_stereo) {
               *pData-- = ms_adpcm_state_p0->iSamp2;
               *pData-- = ms_adpcm_state_p1->iSamp2;
               *pData-- = ms_adpcm_state_p0->iSamp1;
               *pData = ms_adpcm_state_p1->iSamp1;
               BlockCount = 14;
            } else {
               kal_uint16 tmp;
               tmp = *ptr++;
               tmp >>= 8;
               *pData-- = ms_adpcm_state_p0->iSamp2;
               *pData-- = ms_adpcm_state_p0->iSamp1;
               *pData-- = ms_adpcm_decode_sample( tmp >> 4, ms_adpcm_state_p0 );
               *pData = ms_adpcm_decode_sample( tmp & 0x0F, ms_adpcm_state_p0 );
               BlockCount = 8;
            }

            data_count = 4;
            pData += 4;
         }
      }
      *pMBwrite++ = *--pData;
      data_count--;
   }
   ihdl->wav.dsp_last_sample = *pData;
   ihdl->wav.BlockCount = BlockCount;
   ihdl->wav.data_count = data_count;

   return ((buf_len - I) << 1);
}
#endif // #ifndef __L1_STANDALONE__
#pragma arm section code

#endif
