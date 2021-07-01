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
 * media.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Media file recording/playback
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __MEDIA_H
#define __MEDIA_H

#include "fs_type.h"
#include "fsal.h"

#include "l1audio.h"
#include "common_def.h"
#if defined(__AUDIO_COMPONENT_SUPPORT__)
#include "AudComUtil.h"
#endif


#if defined(__COOK_DECODE__)||defined(__APE_DECODE__)||defined(__VORBIS_DECODE__)
#include "ast.h"

#define AUDIO_STATE_IDLE           0     // 1,3
#define AUDIO_STATE_READY_TO_PLAY  3     // 0,6,4
#define AUDIO_STATE_PLAYING        4     // 5,0
#define AUDIO_STATE_PLAY_PAUSE     5     // 0,4
#define AUDIO_STATE_READY_PAUSE    6     // 3,0
#endif
#define  FRAME_BUF_SIZE          160

#define MAX_MMA_PLAYERS_SMF        4
#define MAX_MMA_PLAYERS_IMY        1
#define MAX_MMA_PLAYERS_WAV        4
#define MAX_MMA_PLAYERS_JTS        3
#define MAX_MMA_PLAYERS_AUD        1
//#include "ddload.h"

#define MASTER_GAIN_FACTOR            12
#define MEDIA_RB_DEFAULT_THRESHOLD   200
#define MEDIA_MIN_DATA_THRESHOLD    2048
#define ID3V2_HEADER_LEN      10
#define DSP_WRITE(addr, data) (*(addr) = (kal_uint16)(data))
#define SEEK_TABLE_BS_BUFFER_LEN    2048

#define MAX_SEEKABLE_FILESIZE  1073741823 //1G(2^30-1)

#define EOFCHECKTIME 3

/*
   Warning:  any new declared variable should be placed at last of this structure 
             because "mediaControl" is used in ROMSA
*/

typedef struct {
   union {
      Media_SMF_Param      smf;
      Media_iMelody_Param  imy;
      uint32               vm;
   } param;
   int32          max_swing;        /* 0 ~ 32767                     */
   int8           key_shift;
   uint8          level;            /* Digital volume control 0~100 */
   bool           in_speech;
   Media_Format   format;
   Media_Event    end_status;
   uint16         rb_threshold;
   /* DSP ring buffer control variables */
   uint16         dsp_rb_base;
   uint16         dsp_rb_size;
   uint16         dsp_rb_end;
   uint16         dsp_last_sample;  /* The last sample written to DSP buffer by MCU, for last-sample padding */
   /* Ring buffer control variables */
   bool           eof;              /* Flag indicating End-Of-File   */
   bool           ob_flag_r;        /* if ob_flag_r is set, then the odd_byte for read is stored in odd_byte_r */
   bool           ob_flag_w;        /* if ob_flag_w is set, then the odd_byte for write is stored in odd_byte_w */
   uint8          odd_byte_r;
   uint8          odd_byte_w;
   uint16         *rb_base;         /* Pointer to the ring buffer    */
   uint32         rb_size;          /* Size of the ring buffer(word) */
   uint32         write;            /* R/W by MMI, R by WAV driver   */
   uint32         read;             /* R by MMI, R/W by WAV driver   */
   uint32         file_len;   /* for wav recordig */
   uint32         uOffset;    /* for video recordig */
   bool           isDataConsumed;
   bool           is_stereo;
   bool           mono2stereo;
   bool           is_8KVoice;
   bool           CSD_Mode;
   bool           is_I2S_input;
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
   kal_uint16     magic_no;
#endif  // chip compile option

   kal_bool       fTransmit;
} mediaControl;


#if defined(__COOK_DECODE__)||defined(__APE_DECODE__)||defined(__VORBIS_DECODE__)
typedef struct {
   MHdl               mh;

   //file manage
   STFSAL             *pstFSAL;   
   kal_uint32         fileOffset;
   kal_uint32         file_size;

   //dec buffer
   kal_uint8          *pTempInputBuf;
   kal_uint8          *pTempOutputBuf;
   kal_uint32         tempInputBufSize;
   kal_uint32         tempOutputBufSize;
   kal_uint32         remainInputCount;
   kal_uint32         remainOutputCount;
   kal_uint32         outBufReadPtr;
   kal_uint32         inBufReadPtr; //temp for aac2

   //pcm ring buffer
   AUD_RB_INFO        pcmRB;
   
   //working buffer
   void               *pDecoder;
 
   //decoder member function
   Media_Status       (*InitDecoder)(MHdl *hdl);
   void               (*FreeDecoder)(MHdl *hdl);
   Media_Status       (*ParseHeader)(MHdl *hdl);
   void               (*ParseFrame) (MHdl *hdl);
   Media_Status       (*SyncFrame)  (MHdl *hdl);
   void               (*DecodeTask) (void* data);
   Media_Status       (*Seek)       (MHdl *hdl);
   
   //comon parameter
   Media_Status    end_status;
   kal_uint32      data_offset;
   kal_uint32      totalDuration;
   kal_uint32      reidualDataCnt;  
   kal_uint32      uFileSize;
   kal_uint32      resumeFrameOffset;
   kal_uint32      uCurFrame;
   kal_uint32      audio_format;
   kal_uint16      dsp_last_sample_p;
   kal_uint16      dsp_last_sample;
   kal_uint16      aud_id_decoder;
   kal_uint16      sample_rate;
   kal_int8        sr_index;
   kal_int8        uBsCheck;
   kal_uint8       chanel_number;
   kal_bool        is_8KVoice;
   kal_bool        read_error;
   kal_bool        fUseTCMFromAPM;
   kal_bool        isStreaming;
   kal_bool        isUpdateDur;
   kal_bool        put_silence;
   kal_bool        bitstream_EOF;
   // EOF handling
   kal_bool        decode_EOF;
   kal_bool        disable_pp;
   kal_int32       zeroCount;
   kal_uint32      uErrorCnt;
   AudioSeekTable  *AudioSeekTbl;
   
   //codec exculsive parameter
   void*              decParam;             
} AudioDecHdl;
#endif

#define VIDEO_TEMP_RINGBUF_SIZE (4608*2 + 10)
#define VIDEO_READY_THRESHOLD   (4608       )
#define AUDSTRM_BUFQSIZE (64)
#define AUDSTRM_BUFMASK  (0x3F)

typedef struct {
   kal_uint64        uPrevTimeStamp; //us
   void              *pBufferQ[AUDSTRM_BUFQSIZE];
   kal_bool          (*EmptyBufferDone)(void *hdl, void *pBufferHeader);
   void              (*UpdateHeader)(void *pBufQ, kal_uint32 uFrameLength);
   kal_uint8*        pSilenceFrame;
   kal_uint8*        pFrameHeader;
   kal_uint32        uQueueRead;
   kal_uint32        uQueueWrite;
   kal_uint32        uQueueReturn;
   kal_uint32        uRead;
   kal_uint32        uSilenceTimeUpperThreshold;  //us
   kal_uint32        uSilenceTimePerFrame;   //us
   kal_uint32        uSilenceTimeToBeFilled; //us
   kal_uint32        uSilenceLength;         //bytes
   kal_uint32        uHeaderLength;
   kal_uint32        uFrameNum;
   kal_uint32        uBistreamLen;
   kal_uint16        uAud_ID;
   kal_bool          fIsReady2Play;
   kal_bool          fReturnBuffer;
   kal_bool          fFillingSilence;
   kal_bool          fFillingFrame;
   kal_bool          fFillingHeader;
   kal_bool          fEOF;
   kal_bool          fPreBufValid;
   kal_bool          fNotFirstBuffer;
   kal_bool          fOnlyOneFrameInBuffer;
   kal_bool          fGetID;
} AudStrmStruct;


typedef struct {
   kal_uint32 (*GetMemSize)(void);
   void       *(*Init)(void *hdl);
   void       (*Free)(void *hdl);
   kal_uint32 (*Process)(void *hdl, kal_int16 *inBuf, kal_uint32 inBufLen, kal_uint8 *outBuf, kal_uint32 *outBufLen, kal_bool flush_encoder);
   void       (*Close)(void *hdl);
}Audio_Encode_Interface;


/*****************************************************************************
* Function Declaration
*****************************************************************************/
void  mediaInit( uint16 aud_id );
void  mediaHisr( uint16 flag );
int32 mediaGetFreeSpace( void );
int32 mediaGetDataCount( void );
void  mediaSetEvent( Media_Event event );
void  mediaHandler( void *data );
bool  mediaKeytoneForbidden( void );
bool  mediaIsDataConsumed( void );
mediaControl *mediaGetControl( void );
void  mediaDataNotification( void );
void  mediaIncRecordTime( void );

kal_bool Media_IsGSMMode(void);
void Media_SetFileHeader(kal_uint8 *pHeader, kal_uint32 uLen);
#if defined(MT6260) || defined(MT6261) || defined(MT2501) || defined(MT2502)
void Media_Hook_Record_HISR (kal_uint16 magic_no, void *userData);
void Media_Unhook_Record_HISR (void);
#endif  // chip compile option

/* L1Audio_IDMA*/
void IDMA_WriteToDSP(volatile kal_uint16 *dst, kal_uint16 *src, kal_uint32 length);
void IDMA_FillToDSP(volatile kal_uint16 *dst, kal_uint16 value, kal_uint32 length);
void IDMA_FillToDSP2(volatile kal_uint16 *dst, kal_uint16 value_L, kal_uint16 value_R, kal_uint32 length);
void IDMA_ReadFromDSP(kal_uint16 *dst, volatile kal_uint16 *src, kal_uint32 length);
void IDMA_ReadFromDSP_Skip_1(kal_uint16 *dst, volatile kal_uint16 *src, kal_uint32 length);
void IDMA_WriteToDSP_Duplicate(volatile kal_uint16 *dst, kal_uint16 *src, kal_uint32 length);

/* For Ring Buffer Access */
void  rb_ClearRB( void );
int32 rb_GetByteCount( void );
int32 rb_GetFreeSpace( void );
bool  rb_GetByte( uint8* data_8 );
bool  rb_GetWord( uint16* data_16 );
bool  rb_GetDWord( uint32* data_32 );
bool  rb_PeekByte( uint8* data_8 );
bool  rb_PeekWord( uint16* data_16 );
bool  rb_PeekDWord( uint32* data_32 );
bool  rb_PutByte( uint8 data_8 );
bool  rb_PutWord( uint16 data_16 );
bool  rb_PutDWord( uint32 data_32 );
uint32 rb_SkipNByte( uint32 skip_count );
uint32 rb_SkipNWord( uint32 skip_count );
uint32 rb_GetWriteIndex( void );
uint32 rb_GetReadIndex( void );
uint32 rb_GetSize( void );
uint16 rb_GetOBFlag( void );
uint16 rb_GetOddByte( void );
int rb_PutNByte( const uint8 *buffer, int len );
int rb_GetNByte( uint8 *buffer, int len );
/* For Ring Buffer Access */

void  pcmPlay( mediaControl *ctrl );
void  pcmRecord( mediaControl *ctrl );
void  pcmStop( mediaControl *ctrl );
void  pcmPause( mediaControl *ctrl );
void  pcmResume( mediaControl *ctrl );
void  pcmPlaybackHisr( void );
void  pcmRecordHisr( void );
uint32 pcmGetFrameIntensity( void );

void  wavStop( mediaControl *ctrl );
void  wavPause( mediaControl *mctrl );
void  wavResume( mediaControl *mctrl );
void  wavRecord( mediaControl *ctrl, void *info );
void  wavRecordHisr( void );
void  wavGetFileHeader( uint32 *len );
void  wavUpdateLevel( void );
void  wavInit( uint16 aud_id );
void  wavSetEvent( Media_Event event );

Media_Status wavRecordAppendable( Media_Format format, FS_HANDLE fs, Media_Record_File_Info *info );

Media_Status  auPlay( mediaControl *mctrl );
void  auStop( void );
void  auPause( mediaControl *mctrl );
void  auResume( mediaControl *mctrl );
void  auPlaybackHisr( void );
void  auUpdateLevel( void );

Media_Status  aiffPlay( mediaControl *mctrl );
void  aiffStop( void );
void  aiffPause( mediaControl *mctrl );
void  aiffResume( mediaControl *mctrl );
void  aiffPlaybackHisr( void );
void  aiffUpdateLevel( void );

Media_Status dafPlay( mediaControl *ctrl );
void  dafStop( void );
void  dafPause( mediaControl *mctrl );
Media_Status  dafResume( mediaControl *mctrl );
void  dafPlaybackHisr( void );
void  dafUpdateLevel( void );

Media_Status aacPlay( mediaControl *ctrl );
void  aacStop( void );
Media_Status  aacPause( mediaControl *mctrl );
Media_Status  aacResume( mediaControl *mctrl );
void  aacPlaybackHisr( void );
void  aacUpdateLevel( void );

void  vmRecord( mediaControl *ctrl, uint16 type, kal_bool flag );
Media_Status  vmPlay( mediaControl *ctrl );
void  vmStop( mediaControl *ctrl );
void  vmRecordHisr( void );
void  vmPlaybackHisr( void );
void  vmPause( mediaControl *ctrl );
void  vmResume( mediaControl *ctrl );

void  amrRecord( mediaControl *ctrl, uint16 type );
Media_Status  amrPlay( mediaControl *ctrl );
void  amrStop( mediaControl *ctrl );
void  amrRecordHisr( void );
void  amrBabyMonitorRecordHisr( void );
void  amrPlaybackHisr( void );
void  amrPause( mediaControl *ctrl );
void  amrResume( mediaControl *ctrl );
void  amrUpdateLevel( void );

void  awbEncRecord( mediaControl *ctrl, uint16 type );
void  awbEncPause( mediaControl *ctrl );
void  awbEncResume( mediaControl *ctrl );
void  awbEncStop( mediaControl *ctrl );
void  awbRecordHisr( void );

void  amr_DediEncInit( uint16 aud_id );
void  amr_DediEncRecord( mediaControl *ctrl, kal_uint32 param );
void  amr_DediEncStop( mediaControl *ctrl );
void  amr_DediEncPause(mediaControl *mctrl);
void  amr_DediEncResume(mediaControl *mctrl);
void  amr_DediEncRecordHisr( void );

void  VorbisEnc_Init( uint16 aud_id );
void  VorbisEnc_Record( mediaControl *ctrl );
void  VorbisEnc_Stop( mediaControl *ctrl );
void  VorbisEnc_Pause( mediaControl *ctrl );
void  VorbisEnc_Resume( mediaControl *ctrl );
void  VorbisEnc_Hisr( void );

void VoIPevInit( void );
void  VoIPevRecord( mediaControl *ctrl );
void  VoIPevStop( void );
void  VoIPevPause( void );
void  VoIPevResume( void );

void  smfInit( uint16 aud_id );
void  smfSetEvent( Media_Event event );
Media_Status smfStart( mediaControl *ctrl );
void  smfStop( void );

void  imyInit( uint16 aud_id );
void  imySetEvent( Media_Event event );
Media_Status imyStart( mediaControl *ctrl );
void  imyStop( void );

Media_Status smfDspStart( mediaControl *ctrl );
void  smfDspStop( void );

Media_Status imyDspStart( mediaControl *ctrl );
void  imyDspStop( void );

void  ktInit( uint16 aud_id );
void  ktLock( void );
void  ktUnlock( void );
void  toneInit( uint16 aud_id );

void DSPSYN_HW_Init(void);
void JSmf_Init( void );
void JImy_Init( void );
void JTone_Init( mediaControl *ctrl );
void JWav_Init( mediaControl *ctrl );
void JXWav_Init( mediaControl *ctrl );

/* Obsolete functions: MIDI playback interface using GMI interface */
Media_Status midiPlay( mediaControl *ctrl );
void  midiStop( void );

void iMelodyInit( uint16 aud_id );
Media_Status iMelodyPlay( mediaControl *ctrl );
void iMelodyStop( void );

/* A/V Sync interface */
#define VERIFY_AVSYNC 0
void Media_A2V_LISR( void );
void Media_A2V_REMOVE_MEDIA_END_CALLBACK(Media_Status (*CloseDevice)(MHdl *data));

void   vrsdInit( void );

#define VERIFY_DATA_TO_DSP 0

/* VRSI interface */
void vrsiInit( void );
kal_bool vrsiIsPlaying(void);

/* L1CTM interface */ 
void l1ctm_init( void );

// Audio Framework Revise
void mhdlInit( MHdl *hdl, kal_uint32 hisrMagic, void hisrHdlr( void *data ) );
void mhdlInitEx( MHdl *hdl, kal_uint32 hisrMagic, void hisrHdlr( void *data ) );
void mhdlFinalize( MHdl *hdl, kal_uint32 hisrMagic );
void mhdlHookInit( MHdl *hdl, kal_uint32 hisrMagic, void hisrHdlr( void *data ) );
void mhdlHookFinalize( kal_uint32 hisrMagic );
void mhdlException( MHdl *hdl, Media_Event event );

#if defined(__AUDIO_COMPONENT_SUPPORT__)
void mhdlException_CompHdl( AudComHdlInt *hdl, Media_Event event );
void mhdlFinalize_PCM( MHdl *hdl, kal_uint32 hisrMagic );
void mhdlAllowSleep_Id( kal_uint32 aud_id );
void mhdlDisallowSleep_Id( kal_uint32 aud_id );
void mhdlSetFlag_MD2G_Id( kal_uint32 aud_id );
void mhdlClearFlag_MD2G_Id( kal_uint32 aud_id );
#endif

void mhdlAllowSleep( MHdl *hdl );
void mhdlDisallowSleep( MHdl *hdl );
void mhdlDataRequest( MHdl *hdl, Media_Event end_status);
void mhdlDataRequestNone( MHdl *hdl, Media_Event end_status);
void mhdlDataNotification( MHdl *hdl );
void mhdlRefillAndUpdateVideoBuffer( MHdl *hdl );

kal_uint32 AudBufQ_AutoFillBuffer(MHdl *hdl, AudStrmStruct *pStrmStruct, kal_uint8 *pDst, kal_uint32 uDstLen, kal_bool fPCMByte2Word);

kal_uint8 autGetBitsFromBuf(kal_uint8 *pBuf, kal_uint32 *puBitCnt, kal_uint32 uBitLen);
kal_int32 autGetBytesFromFile(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr);
kal_int32 autGetBytesFromFileNoEnd(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 fileOffset, kal_uint32 num_bytes, kal_uint8 *ptr);
kal_int32 autGetBytes(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 uLen, kal_uint8 *pbBuf);
void autSkipID3Tag( MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileOffset, kal_uint8 *ptr );
void autWriteDataToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum, void(*incTime)(MHdl *handle, kal_uint32 num_bytes ));
void autGetFileSize(MHdl *hdl, STFSAL *pstFSAL, kal_uint32 *fileLen);

//new interface for AudioMediaHdl
kal_int32    autGetDSPDataCnt( kal_int32 dsp_rb_size ); //working in HISR
kal_int32    autPutSilenceToDSP2(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample_L, kal_int16 dsp_last_sample_R); //working in HISR
void         putSilence2(kal_uint16 dsp_rb_base, kal_int32 dsp_rb_size, kal_int16 dsp_last_sample_L, kal_int16 dsp_last_sample_R, kal_int32 dsp_len); //working in HISR
Media_Event  mhdlMFProcess( MHdl *hdl, Media_Event event );
Media_Status mhdlMFResume( MHdl *hdl );
Media_Status mhdlMFPause( MHdl *hdl );
Media_Status mhdlMFStop( MHdl *hdl );
Media_Status mhdlMFPlay( MHdl *hdl );
Media_Status mhdlMFClose( MHdl *hdl );
void         mhdlHisr( void *data );
int32        rbGetDataCount( AUD_RB_INFO *rb );
Media_Status autPutRing2LinearBuf( kal_uint8 *dstbuf, AUD_RB_INFO *srcRB, kal_uint32 frame_len);
kal_uint8    rbGetByte(AUD_RB_INFO *srcRB);
void         rbGetWriteBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len );// in bytes
void         rbGetReadBuffer( AUD_RB_INFO *rb, kal_uint8 **buffer, kal_uint32 *buf_len );// in bytes
void         rbWriteDataDone( AUD_RB_INFO *rb, kal_uint32 len ); // in bytes
void         rbReadDataDone( AUD_RB_INFO *rb, kal_uint32 len ); // in bytes
int32        rbGetFreeSpace( AUD_RB_INFO *rb );
kal_int8     autGetSampleRateIdx( kal_uint32 SampleRate );

// Dior modify for defined(DAF_DSP_BS_DMPATH
kal_uint32   autWriteDataFromRBToDSP( MHdl *hdl, kal_uint16 *dspWritePtr, kal_uint16 *dspReadPtr, kal_uint32 pageNum, void(*incTime)( MHdl *handle, uint32 num_bytes ), AUD_RB_INFO* srcRB, kal_bool bAllowBuffNotFull );
void         autMoveDataForAlign( MHdl *hdl );

//end of new interface for AudioMediaHdl

// speech enhancement control functions
//#define SPE_ES_FLAG     (1 << 0) 
#define SPE_AEC_FLAG    (1 << 1) 
//#define SPE_EES_FLAG    (1 << 2) 
#define SPE_UL_NR_FLAG  (1 << 3) 
#define SPE_DL_NR_FLAG  (1 << 4) 
#define SPE_TDDNC_FLAG  (1 << 5)
#define SPE_DMNR_FLAG   (1 << 6)
#define SPE_AGC_FLAG    (1 << 7)
#define NUM_OF_SPH_FLAG 8

//speech enhancement mask for l1sp.spe_mask usage
//#define SPH_ENH_MASK_ES    SPE_ES_FLAG
#define SPH_ENH_MASK_AEC   SPE_AEC_FLAG
//#define SPH_ENH_MASK_EES   SPE_EES_FLAG
#define SPH_ENH_MASK_ULNR  SPE_UL_NR_FLAG
#define SPH_ENH_MASK_DLNR  SPE_DL_NR_FLAG
#define SPH_ENH_MASK_TDDNC SPE_TDDNC_FLAG
#define SPH_ENH_MASK_DMNR  SPE_DMNR_FLAG
#define SPH_ENH_MASK_AGC   SPE_AGC_FLAG
#define SPH_ENH_MASK_SIDETONE (1 << NUM_OF_SPH_FLAG)



void SPE_LoadSpeechPara( uint16 c_para[NUM_COMMON_PARAS], uint16 m_para[NUM_MODE_PARAS], uint16 v_para[NUM_VOL_PARAS] );
void SPE_LoadSpeechPara_ES( uint16 timeConst, uint16 volConst );
void SPE_Init( void );
void SPE_TurnOnProcess(uint8 on_state);
void SPE_TurnOffProcess(uint8 off_state);
void SPE_Clear_DLL_Entry(uint8 cur_state);
void SPE_SetSBSD( bool state );
//void SPE_SetULNR( bool ec );
void SPE_LoadLimiterPara(uint16 para);
void SPE_LoadDmnrCoeffs(kal_int16 dmnr_para[NUM_DMNR_PARAM]); //enable only when "defined(__DUAL_MIC_SUPPORT__)"
void SPE_LoadWbDmnrCoeffs(kal_int16 wb_dmnr_para[NUM_WB_DMNR_PARAM]); //enable only when "defined(__DUAL_MIC_SUPPORT__) && defined(__AMRWB_LINK_SUPPORT__)" 

/* L1SP interface */ 
void L1SP_Init( void );
void L1SP_LoadSpeechPara( void );
void L1SP_Register_Service(void (*onHandler)(void *), void (*offHandler)(void *));
void L1SP_UnRegister_Service( void );
void L1SP_SetState(kal_uint8 state);
kal_uint8 L1SP_GetState( void );
void L1SP_Reload_SPE_Para( void );
void L1SP_Reload_DMNR_Para( void ); //enable only when "defined(__DUAL_MIC_SUPPORT__)"
void L1SP_Register_Pcm4WayService(void (*onHandler)(void *), void (*offHandler)(void *));
void L1SP_UnRegister_Pcm4Way_Service( void );

kal_bool L1SP_TCH_State( void );
void L1SP_EnableStrmPcmSPE(void);
void L1SP_DisableStrmPcmSPE(void);
void l1sp_updateSpeMask(uint8 updateFlags, bool enable);

int16 l1sp_getNumOfRecordMode(void);

void l1sp_setRecordModeDeviceMapping(uint8 *mappingTable, int16 length, int16 numOfRecordMode);

typedef struct 
{
   kal_uint16 *mode_par;
   kal_uint16 *common_par;
   kal_int16 *in_fir;
   kal_int16 *out_fir;
} SPE_Par_Struct;

enum{
   L1SP_STATE_IDLE = 0, 
   L1SP_STATE_2G_SPEECH_ON,
   L1SP_STATE_3G_SPEECH_ON,
   L1SP_STATE_3G324M_SPEECH_ON,
   L1SP_STATE_3G_SPEECH_CLOSING,    
   L1SP_STATE_3G_SPEECH_CLOSED 
}; 

#define SPH_FIR_COEFF_NORMAL           0
#define SPH_FIR_COEFF_HEADSET          1
#define SPH_FIR_COEFF_HANDFREE         2
#define SPH_FIR_COEFF_BT               3
#define SPH_FIR_COEFF_VOIP_NORMAL      4
#define SPH_FIR_COEFF_VOIP_HANDFREE    5

void sp3g_speech_init( uint8 RAT_Mode );
void sp3g_speech_close( void );
void sp3g_init( void );//boot up init
kal_bool   SP3G_Rab_State( void );
kal_uint32 SP3G_Rab_Id( void );
void       SP3G_Reset( void );
void       SP3G_SetRxTypeToNoData( void );
kal_bool   SP3G_IsDTXOn( void );

//Voice Clarity interface
bool VC_Start(void);
void VC_Stop(void);
bool VC_IsStart(void);
bool VS_Start(void);
void VS_Stop(void);
bool VS_IsStart(void);

void VMI_HookPostHandler( void (*PostHandler)(void *) );
void VMI_UnhookPostHandler( void );

kal_uint32 L1Audio_GetEventGroup( void );
void L1Audio_ExeEventHandler( kal_uint32 event );

void ttsInit(void);
kal_bool ttsIsEnable(void);

/*
Media_Status autGetMetaData( kal_wchar *filename, kal_uint8 *pbBuf, kal_uint32 uSize, audInfoStruct *contentInfo, void *param, 
                             Media_Status(*getContentDescInfo)( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param) );
Media_Status autGetID3MetaData(
   kal_wchar *filename,
   kal_uint8 *pbBuf,
   kal_uint32 uSize,
   audInfoStruct *contentInfo,
   void *param, 
   Media_Status (*getContentDescInfo)( STFSAL *pstFSAL, audInfoStruct *contentInfo, void *param)
);
*/

void autTchReadFromDSP( int16 *buf, kal_uint32 pageNum );
void ClearDSPAudioCommonFlag (void);

kal_uint32 Media_IncRecordedTime( kal_uint32 val );
kal_bool Media_IsRecordSilence( void );
Media_Status I2S_Record_Start( mediaControl *ctrl, void *param );
void I2S_Record_Stop(mediaControl *ctrl);
void I2S_Record_Pause(mediaControl *ctrl);
void I2S_Record_Resume(mediaControl *ctrl);
void Media_WriteDataDone_NoWaiting( kal_uint32 len );
void I2S_init(void);
kal_bool Media_IsDSPDec(void);
void Media_SetIsDSPDec( kal_bool type );
kal_bool Media_SetIsAlwaysRoute(kal_bool flag);
kal_bool Media_IsAlwaysRoute(void);
Media_Format Media_GetAudioFormat(void);
void Media_SetAudioFormat(Media_Format format);
void Media_SetSampleRate(kal_uint32 sampleRate);
kal_uint32 Media_GetSampleRate(void);
kal_uint32 Media_GetSamplingRateIndex(kal_uint32 sampling_rate);

//APM internal interface
void APM_ClearDropCount(void);

// For In Process Call
void L1Audio_InProcCall(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);
void L1Audio_InProcCall2(in_proc_call_type func, kal_uint32 func_arg1, void* func_arg2);
kal_bool L1Audio_IsInitiated(void);

typedef enum {
  PCMNWAY_BAND_INFO_UNSET = 0,
  PCMNWAY_BAND_INFO_NB,
  PCMNWAY_BAND_INFO_WB,
  PCMNWAY_BAND_INFO_DYNAMIC // follow codec
}PCMNWAY_BAND_INFO;

uint32 PCM2Way_GetFormat(void);


// For component-based recording
MHdl *PCM_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), void *param );
MHdl *AMR_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), void *param );
MHdl *AWB_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), void *param );
MHdl *VORBIS_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), void *param );
MHdl *VM_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), Media_Format format, void *param );
MHdl *WAV_Rec_Open( void(*handler)( MHdl *handle, Media_Event event ), Media_Format format, void *param );

// For remix
void Remix_Init(void);

#endif /* __MEDIA_H */


