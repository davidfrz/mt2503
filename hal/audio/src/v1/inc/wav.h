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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   wav.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Definition for wave functions, adapted from g711.h 1.10
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WAV_H
#define __WAV_H

#include "kal_general_types.h"
#include "fsal.h"
#include "DraExport.h"

#include "l1audio.h"
#include "common_def.h"
#include "audio_def.h"
#include "media.h"
#include "ast.h"

#define WAV_STATE_IDLE          0     // 1,3
#define WAV_STATE_RECORDING     1     // 2,0
#define WAV_STATE_RECORD_PAUSE  2     // 0,1
#define WAV_STATE_READY_TO_PLAY 3     // 0,6,4
#define WAV_STATE_PLAYING       4     // 5,0
#define WAV_STATE_PLAY_PAUSE    5     // 0,4
#define WAV_STATE_READY_PAUSE   6     // 3,0

#define  FRAME_BUF_SIZE          160
#if defined( MED_LOW )
#define  FRAME_BUF_NO            2
#else
#define  FRAME_BUF_NO            4
#endif//defined( MED_LOW )
#define  FRAME_BUF_MASK    (FRAME_BUF_NO-1)

#if defined(MT6255) || defined(MT6250) || defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
#define  FRAME_BUF_SIZE_16K      320
#define  DSP_PCM_16K_REC_LEN     320
#endif

#define  MSADPCM_EXTRA_COEFF     10

extern const short iCoeff[7][2];

typedef struct {
   int   index;
   int   valpred;
} dviAdpcm_State;

typedef struct adpcmblockheader_tag{
   uint8    bPredictor;
   uint16   iDelta;
   short    iSamp1;
   short    iSamp2;
   short    iCoeff1;
   short    iCoeff2;
} MS_ADPCM_STATE;

#if defined(__DRA_DECODE_SUPPORT__)

#define DRA_TEMP_OUTPUT_BUFFER_SIZE 4096
#define DRA_BITSTREAM_BUFFER_SIZE 16*1024

typedef struct draStateStruct {
   void                *pDecoder;
   dra_audio_info      audioInfo;   // The first frame for configutration
   dra_frame_info      frameInfo;   // Current frame information
   dra_cfg             config;
   int                 mixMode;
   int                 nBitPcm;
   
   kal_bool            isVBR;
   kal_uint8           *pTempInputBuf;
   kal_uint8           *pTempOutputBuf;
   kal_uint32          tempInputBufSize;
   kal_uint32          tempOutputBufSize;
   long                readOffset;
   long                remainOutputCount;
} DRA_StateInfo;

typedef struct tGUID
{
   uint32   Data1;
   uint16   Data2;
   uint16   Data3;
   uint8    Data4[ 8 ];
} GUID;

#endif

struct wavHeader_Struct{  /* MS's WAV header */
   uint32   wRiffLength;
   uint32   wSamplesWritten;
   uint32   wDataLength;        /* data chunk size */
   uint16   wBlockAlign;
   uint16   nNumCoef;
};

struct wav_Struct{
   mediaControl   *ctrl;
   uint32         sample_rate; 
   uint16         aud_id;
   uint16         BlockCount;
   uint16         data[16];
   uint8          tmp_r;
   uint8          tmp_w;
   uint16         *tmp_buf[FRAME_BUF_NO];
#if defined(__DUAL_MIC_SUPPORT__)
   uint16         *tmp_buf_dual_mic;
#endif
   int32          MBCount;
   uint8          state;
   uint8          data_size;
   uint8          data_count;
   int8           sr_index;
   dviAdpcm_State dvi_state_ch1;
   dviAdpcm_State dvi_state_ch2;
   uint32         next_chunk;    // the offset of next chunk, in word
   bool           dedicated_mode;
   bool           (*PutSample)( uint16 **pbuf, uint16 data, uint16 *sample_count);
   void           (*Wav_PutData)(int32 dsp_len);
   
   // For MS ADPCM
   MS_ADPCM_STATE ms_adpcm_state[2];
   short          aCoeff[MSADPCM_EXTRA_COEFF][2];    // allow 10 more coefficient set
   void           *pSRC_Handle;
   kal_int16      *pTempPcmBuf;
   bool           fNB2WB;
};

int    linear2alaw( int pcm_val );
uint16   alaw2linear ( uint8 a_val );
int    linear2ulaw( int pcm_val );
uint16   ulaw2linear( uint8 u_val );
uint8    alaw2ulaw( uint8 aval );
uint8    ulaw2alaw( uint8 uval );
void     dviAdpcm_Init( dviAdpcm_State *state );
uint8    dviAdpcm_Encode( uint16 pcm, dviAdpcm_State *state );
int      dviAdpcm_Decode( int delta, dviAdpcm_State *state );
short ms_adpcm_decode_sample( uint8 error_delta, MS_ADPCM_STATE *state );

/* Note: for ROM code start */
#ifdef __ROMSA_SUPPORT__
extern int mediaGetDataCount( void );
extern bool rb_GetByte( unsigned char *data_8 );
extern bool rb_GetWord( unsigned short *data_16 );
extern void ms_adpcm_decode_mono( unsigned short data, unsigned int position );
extern void ms_adpcm_decode_stereo( unsigned short data, unsigned int position );
extern void wavADPCMPutData( int dsp_len );
extern void wavADPCMPutData_ST( int dsp_len );
extern void wavADPCM_Decode(uint16 compressed_data, uint32 position, int8 shift, dviAdpcm_State* state);
extern void wavADPCM_SubBlockDecodeST(void);
extern void wavMSADPCMPutData( int dsp_len );
#endif
/* Note: for ROM code end */


#define WAV_MAX_DATA_REQUESTED 1024
#define WAV_MAX_DATA_REQ_WORD  512
#define FSAL_BUF_SIZE 1024
#define _bytes_reverse_32( _before, _after )  \
{ _after =  ( _before << 24 ) | ( _before & 0x0000FF00 ) << 8 | ( _before & 0x00FF0000 ) >> 8 | ( _before >> 24 ); }
#define _bytes_reverse_16( _before, _after )  \
{ _after = ( _before << 8 ) | ( _before >> 8 ); }

#define IS_AIFF   0
#define IS_AIFF_C 1

extern void   (*MS_ADPCM_Decode)( uint16 data, uint32 position );


typedef struct wavVar{
   kal_uint16         BlockCount;
   kal_uint16         data[16];
   kal_uint16         channel_num;
   kal_uint16         formatTag;
   kal_uint16         samplesPerBlock;
   kal_uint16         dsp_last_sample_p;
   kal_uint16         dsp_last_sample;
   kal_int32          sampleRate;
   kal_int32          AvgBytesPerSec;
   kal_int32          dataChunkOffset;
   kal_uint32         wDataChunkLength;
   kal_uint32         wDataLength;
   kal_uint16         BitsPerSample;
   kal_uint16         wBlockAlign;
   kal_uint16         nNumCoef;
   kal_uint8          state;
   kal_uint8          data_count;
   kal_int8           sr_index;

   // AIFF
   kal_uint8          aiff_type;          // the type of aiff file, either IS_AIFF or IS_AIFF_C
   kal_uint16         data_size;          // data size of a sample, in byte
   kal_uint32         ssnd_offset;        // offset in ssnd chunk
   kal_uint32         word_left_in_form;  // data count left in the form chunk, in word
   kal_uint32         word_left_in_ck;    // data count left in the current chunk, in word
   kal_uint32         ssnd_state;         // 0: not found yet
                                          // 1: ssnd is found but the actual sound data is not found
                                          // 2: sound data is found
   // AU
   kal_uint32         data_offset;     // data offset in byte, found in AU file header
   kal_uint32         data_length;     // length of sound data in byte, found in AU file header
   kal_uint32         data_read;       // total data read so far, in byte

   dviAdpcm_State     dvi_state_ch1;
   dviAdpcm_State     dvi_state_ch2;
   
   kal_uint32         nextChunkOffset;    // the offset of next chunk, in word
   kal_bool           is_stereo;
   kal_bool           mono2stereo;
   kal_bool           is_8KVoice;
   kal_int32          (*Wav_PutData)(MHdl *hdl, kal_int32 mbBufLen );
   
   // For MS ADPCM
   MS_ADPCM_STATE     ms_adpcm_state[2];
   kal_int16          aCoeff[MSADPCM_EXTRA_COEFF][2];    // allow 10 more coefficient set

#if defined(__DRA_DECODE_SUPPORT__)
   // DRA
   kal_bool           isDRA;
   kal_bool           isRunned;
   DRA_StateInfo      dra;
   kal_uint32         bsRead;
   kal_uint32         bsWrite;
   kal_uint32         bsSize;
   kal_uint8          *bsBase;
   kal_bool           isFileAccess;
#endif
} wavInternal;

#define MAX_CACHE_PROCESS_SIZE  2048

typedef struct wav_internal {
   MHdl             mh;
   wavInternal      wav;
   kal_uint16       aud_id_decoder;
   kal_bool         read_error;
   kal_bool         fUseTCMFromAPM;
   STFSAL           *pstFSAL;
   audInfoStruct    *description;
   kal_uint16       buf[WAV_MAX_DATA_REQUESTED/2];
   kal_int32        reidualDataCnt;
   kal_uint32       fileOffset;
   kal_uint32       file_size;
   Media_Event      end_status;
   
   // EOF handling
   kal_bool         decode_EOF;
   kal_int32        zeroCount;
   
   // Execute in L1Audio task
   kal_bool         isAudioTask;
   kal_bool         isUpdateDur;
   
   // Cache table
   AudioSeekTable  *AudioSeekTbl;
   kal_uint64       frameDur;
   kal_uint32       curFrame;
   } wavMediaHdl;

extern kal_int32 wavDviADPCMPutDataMono( MHdl *hdl, kal_int32 buf_len );
extern kal_int32 wavDviADPCMPutData_ST( MHdl *hdl, kal_int32 buf_len );
extern void wavMSADPCM_decode_stereo( wavMediaHdl *ihdl, uint16 data, uint32 position );
extern void wavMSADPCM_decode_mono( wavMediaHdl *ihdl, uint16 data, uint32 position );
extern void   (*wavMS_ADPCM_Decode)( wavMediaHdl *ihdl, uint16 data, uint32 position );
extern kal_int32 wavMSADPCMPutDataMonoST( MHdl *hdl, kal_int32 buf_len );
extern kal_int32 pcmDviADPCMPutDataMono( MHdl *hdl, kal_int32 buf_len );
extern kal_int32 wavDraPutData( MHdl *hdl, kal_int32 buf_len );

//kal_int32 wavGetDSPDataCnt( kal_int32 dsp_rb_size );
//kal_int32 wavPutSilence(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample);

void wavUpdateCacheTable(wavMediaHdl *ihdl, kal_uint16 frameLen);
AST_Status wavASTParseFileHeader(void *hdlptr, kal_uint32 *FirstFrameOffset);
AST_Status wavASTParseFrame(void *hdlptr, kal_uint32 *CurOffset, kal_uint32 *ParseFrameNum);
#endif
