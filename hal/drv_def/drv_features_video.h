
#ifndef __DRV_FEATURES_VIDEO_H__
#define __DRV_FEATURES_VIDEO_H__

#include "drv_features_chip_select.h"
#include "drv_features_vcodec.h"
#include "drv_features_mmsysmisc.h"

/**************************************************
* General options
***************************************************/
#if defined(__VIDEO_ARCHI_V2__)
    #define __VE_VIDEO_ARCHI_V2__
#endif

#if defined(LOW_COST_SUPPORT)
    #define __VE_SLIM_PROJECT__
#endif

#if defined(__MED_VIDEO_ULC__) && (defined(MT6250) || defined(MT6260))
    #define __VE_ULC_PROJECT__
#endif

#if defined(__MTK_TARGET__)
    #define __VE_MTK_TARGET__


    /*(Video_decoder_component_v2.c, Video_encoder_component_v2.c)
    �Ψӷminternal stack��function���ӥu���X��chip���䴩�ҥH�ڥ]�@��compile option�ӰϧO*/
    #define STKMGR_USER_FILTER_ENABLE   //please remove this one
    #define __VE_STKMGR_USER_FILTER_ENABLE__
#endif

#if defined(__MTK_INTERNAL__)
/* under construction !*/
#endif

#if defined(__SW_VIDEO_MAX_RESOLUTION__)
    #define __VE_SW_VIDEO_MAX_RESOLUTION__
#endif

#if defined(__DRV_MTV_SUPPORT__)
    #define __VE_MTV_SUPPORT__
#endif

#if defined(__DYNAMIC_SWITCH_CACHEABILITY__)
    #define __VE_DYNAMIC_SWITCH_CACHEABILITY__
#endif

#if defined(__MTK_L1CACHEABLE__)
    #define __VE_MTK_L1CACHEABLE__
#endif

#if defined(DRV_FEATURE__MM_INTMEM_IF)
    #define __VE_MM_INTMEM_IF__
#endif

#ifdef __MED_VIDEO_ULC__
    #define __VE_MED_VIDEO_ULC__
#endif

#define __VE_VIDEO_COMMON__
#define __VE_MPL_PLAYER__

#define __VE_PARSE_TRANSFORMATION_INFO__
#if defined(__VIDEO_3D_SIDE_BY_SIDE__)
    #define __VE_3D_SIDE_BY_SIDE__
#endif

#if defined(PGDL_SUPPORT_YOUTUBE)
/* under construction !*/
#endif

/***************************************************
    Decoder
***************************************************/
//#if defined(__J2ME__)
#if defined(SUPPORT_MMAPI)
    #define __VE_ENABLE_FORCE_SLEEP__
    #define __VE_JAVA_ENABLED__
    #define __VE_STOPTIME_SUPPORT__
#endif

#define __VE_ROBUST_FLOW__

#if defined(__KMV_SUPPORT__)
	#define __VE_KMV_SUPPORT__
	//#define __VE_KMV_PROFILE_ENABLE__
#endif 

#if defined(MT6235) || defined(MT6235B)
    #define __VE_IMPROVE_RESIZER__
#endif
/***************************************************/



/*BITSTREAM_SUPPORT =  FALSE Macross Chen (�����) [�U�� 02:08]: V2���٨S�g*/
/*
#ifdef __BITSTREAM_VIDEO_API_SUPPORT__

#endif
*/

/**************************************************
* Muxer
***************************************************/
#if defined(__MPEG4_ENC_SUPPORT__) || defined(__MJPEG_ENC_SUPPORT__) || defined(__H264_ENC_SW_SUPPORT__)
    #define __VE_SUPPORT_MUXER__
#endif

#if defined(__MJPEG_ENC_SUPPORT__)
    #define __VE_SUPPORT_AVI_MUXER__
#endif

#if defined(__MPEG4_ENC_SUPPORT__) || defined(__H264_ENC_SW_SUPPORT__)
    #define __VE_SUPPORT_MP4_MUXER_ADAPTER__
#endif

/**************************************************
* Encoder
***************************************************/
#if 0
#if defined(__VE_VIDEO_ARCHI_V2__)
#if defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) || defined(MT6252) || defined(MT6252H) || defined(MT6921) || defined(MT6250)
#if !defined(__MEDIA_VT__)
/* under construction !*/
#endif  // !defined(__MEDIA_VT__)
#endif  // defined(MT6253) || defined(MT6253E) || defined(MT6253L) || defined(MT6253T) || defined(MT6252) || defined(MT6252H) || defined(MT6921) || defined(MT6250)
#endif  // defined(__VE_VIDEO_ARCHI_V2__)
#endif
#define __VE_SLIM_RECORDER_SOURCE__

#if defined(__MPEG4_ENC_SUPPORT__) || defined(__MJPEG_ENC_SUPPORT__)
    #define __VE_SUPPORT_ENCODER__
#endif

#if defined(LOW_COST_SUPPORT)
#else
    #define __VE_VENC_PROFILING_BITSTREAM__
    #define __VE_VENC_PROFILING_CODEC__
    #define __VE_SUPPORT_YUV_RECORDING__
#endif

#if defined(__MEDIA_VT__)
/* under construction !*/
/* under construction !*/
#endif


#if defined(__RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__)
#define __VE_ENCODE_WITH_MOTION_SENSOR_SUPPORT__
#endif  // defined(__RECORDER_MOTION_SENSOR_SUPPORT_BY_TAG__) || defined(__RECORDER_MOTION_SENSOR_SUPPORT_BY_ENCODE__)


// Enable this define only when
// we needs to dump bitstream from encoder component through catcher log
//#define __VE_ENC_DUMP_BITSTREAM__

/**************************************************
* H264 decoder
***************************************************/
#if defined(__H264_ENC_SW_SUPPORT__)
    #define __VE_H264_ENC_SW_SUPPORT__
#endif

#if defined(__SW_H264_LOSSY_SUPPORT__)
    #define VIDEO_SW_H264_LOSSY_SUPPORT     //please remove this one
    #define __VE_VIDEO_SW_H264_LOSSY_SUPPORT__
#endif

#if defined(__H264_DEC_HW_SUPPORT__)
    #define __VE_H264_DEC_HW_SUPPORT__
#endif

#if defined(__H264_DEC_SW_SUPPORT__)
    #define __VE_H264_DEC_SW_SUPPORT__
#endif

#if defined(__H264_DEC_SW_SLIM__)
    #define __VE_H264_DEC_SW_SLIM__
#endif

#if defined(__H264_DEC_SW_SUPPORT_MAINHIGH__)
    #define __VE_H264_DEC_SW_SUPPORT_MAINHIGH__
#endif

#if defined(__H264_DEC_SUPPORT__)
    #define __VE_H264_DEC_SUPPORT__
#endif

/**************************************************
* MPEG4 decoder
***************************************************/
#if defined(__MPEG4_DEC_SW_SUPPORT__)
    #define __VE_MPEG4_DEC_SW_SUPPORT__
#endif

#if defined(__SW_MP4_LOSSY_SUPPORT__)
    #define VIDEO_SW_MP4_LOSSY_SUPPORT      //please remove this one
    #define __VE_VIDEO_SW_MP4_LOSSY_SUPPORT__
#endif

#if defined(__MPEG4_DEC_HW_SUPPORT__)
    #define __VE_MPEG4_DEC_HW_SUPPORT__
#endif

#if defined(__MP4_DEC_SW_SLIM__)
    #define __VE_MP4_DEC_SW_SLIM__
#endif

/**************************************************
* MJPEG decoder
***************************************************/
#if defined(__MJPEG_DEC_SW_SUPPORT__)
    #define __VE_MJPEG_DEC_SW_SUPPORT__

    #if defined(MT6256)
        #define __VE_MJPEG_DEC_SUPPORT_MT6256_SERIES__
    #elif defined(MT6255)
        #define __VE_MJPEG_DEC_SUPPORT_MT6255_SERIES__
    #endif
#endif

#if defined(__MJPG_DEC_SW_SLIM__)
    #define __VE_MJPG_DEC_SW_SLIM__
#endif

/**************************************************
* RV decoder
***************************************************/
#if defined(__RV_DEC_SW_SUPPORT__)
    #define __VE_RV_DEC_SW_SUPPORT__
#endif

#if defined(__RM_DEC_SW_SLIM__)
    #define __VE_RM_DEC_SW_SLIM__
#endif

/**************************************************
* VP8 decoder
***************************************************/
#if defined(__VP8_DEC_SW_SUPPORT__)
    #define __VE_VP8_DEC_SW_SUPPORT__
#endif

#if defined(__VP8_DEC_SW_SLIM__)
    #define __VE_VP8_DEC_SW_SLIM__
#endif


/**************************************************
* MJPEG encoder
***************************************************/
#if defined(__MJPEG_ENC_SUPPORT__)
    #if defined(MT6256)
        #define __VE_MJPEG_ENC_BYPASS__
    #else
        #define __VE_MJPEG_ENC_SUPPORT__
    #endif
#endif

#if defined(__AVI_ENC_SUPPORT__)
    #define __VE_AVI_ENC_SUPPORT__
#endif

#if defined(MT6256) && defined(__AVI_ENC_SUPPORT__)
    #define __VE_MJPEG_DIRECT_COUPLED_SENSOR__
#endif  // defined(MT6256) && defined(__AVI_ENC_SUPPORT__)


/**************************************************
* MPEG4 encoder
***************************************************/
#if defined(__MPEG4_ENC_SUPPORT__)
    #define __VE_MPEG4_ENC_SUPPORT__
#endif

#if defined(__MPEG4_ENC_SW_SUPPORT__)
    #define __VE_MPEG4_ENC_SW_SUPPORT__
#endif

#if defined(__MPEG4_ENC_HW_SUPPORT__)
    #define __VE_MPEG4_ENC_HW_SUPPORT__
#endif

#if defined(__MP4_ENC_HW_SUPPORT__)
    #define __VE_MP4_ENC_HW_SUPPORT__
#endif

#if defined(__VIDEO_ENC_D1_SUPPORT__)
    #define __VE_ENC_D1_SUPPORT__
#endif

#if (defined(MT6268) || defined(MT6268A) || defined(MT6270A))
    #define DRV_MP4_V2_ENHANCE      //please remove this one
    #define __VE_MP4_V2_ENHANCE__
#endif
//#define DRV_MP4_ENC_MODIFY_SPECIAL_Q_FOR_IFRAME   (should never turned on, for 6219, 6227 series and 6228 series)
//#define DRV_MP4_V1_ENC_PARAM_TYPE_1               (should never turned on, for 6219 only)

#if defined(__MPEG4_ENC_SW_SLIM__)
    #define __VE_MPEG4_ENC_SW_SLIM__
#endif

// Temporal sub-feature solution for SW codec to evaluate algorithm
// Should not enable on Target now
//#define __VE_ENABLE_CODEC_ADJUST_TIME__

/**************************************************
* H264 encoder
***************************************************/
#if defined(__H264_ENC_SW_SUPPORT__)
    #define __VE_H264_ENC_SW_SUPPORT__
#endif

/**************************************************
* Video telephony
***************************************************/
#if defined(__MEDIA_VT__)
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

/**************************************************
* Clipper
***************************************************/
#if defined(__VIDEO_CLIPPER_SUPPORT__)
    #define __VE_VIDEO_CLIPPER_SUPPORT__
    #if defined(MJPG_DECODE) || defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)
        #define __VE_SUPPORT_MUXER__
    #endif

    #if defined(MJPG_DECODE)
        #define __VE_SUPPORT_AVI_MUXER__
    #endif

    #if defined(__M3GPMP4_FILE_FORMAT_SUPPORT__)
        #define __VE_SUPPORT_MP4_MUXER_ADAPTER__
    #endif
#endif

/**************************************************
* H264 open API
***************************************************/
#if (defined(__H264_OPEN_API_SUPPORT__))
    #if (defined(DRV_H264_6268_SERIES))
       #define H264_OPEN_API_SUPPORT        //please remove this one
       #define __VE_H264_OPEN_API_SUPPORT__
    #else
       #error "We don't support h264 open api in this platform"
    #endif
#endif

#if defined(__H264_HW_OPEN_API_SUPPORT__)
    #define __VE_H264_HW_OPEN_API_SUPPORT__
#endif

#if defined(__H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__ )
    #define __VE_H264_OPEN_API_DRIVER_ERROR_CONCEALMENT__
#endif

#if defined(__H264_DEBUG_ASSERT__)
    #define __VE_H264_DEBUG_ASSERT__
#endif

#if defined(__H264_SLICEMAP_DEBUG__)
    #define __VE_H264_SLICEMAP_DEBUG__
#endif

#if defined(__H264_DUMMY_B_SLICE_SUPPORT__ )
    #define __VE_H264_DUMMY_B_SLICE_SUPPORT__
#endif

#if defined(__H264_OPEN_API_DRIVER_FMO_BUG_FIXED__)
    #define __VE_H264_OPEN_API_DRIVER_FMO_BUG_FIXED__
#endif

#if defined(__OLD_PDN_DEFINE__)
    #define __VE_OLD_PDN_DEFINE__
#endif

#if defined(_H264_NEW_GMC_SETTING)
    #define __VE_H264_NEW_GMC_SETTING__
#endif

#if defined(__CLKG_DEFINE__)
    #define __VE_CLKG_DEFINE__
#endif

#if defined(__KAL_OLD_HISR_API__)
    #define __VE_KAL_OLD_HISR_API__
#endif

#if defined(__H264_SW_OPEN_API_SUPPORT__)
    #define __VE_H264_SW_OPEN_API_SUPPORT__
#endif

/**************************************************
* Memory management
***************************************************/
#if defined(MT6235) || defined(MT6235B)
    #define __SPECIAL_MEM_ALLOCATION_FOR_RENDERER__  //please remove this one
    #define __VE_SPECIAL_MEM_ALLOCATION_FOR_RENDERER__
#endif

/**************************************************
* Visual Hisr management
***************************************************/
    #define __VE_VISUAL_HISR_DBG_LOG__  // to enable debug log information

/**************************************************
* Streaming support
***************************************************/
#if (defined(STREAM_SUPPORT) || defined(__MTV_SUPPORT__))
    #define __VE_STREAM_SUPPORT__
    
    #if defined(__CMMB_SUPPORT__)
    #define __VE_STREAM_CMMB_SUPPORT__
    #endif
#endif

/**************************************************
* Progressive download
***************************************************/
#ifdef PGDL_SUPPORT
    #define __VE_PGDL_SUPPORT__
#endif

/**************************************************
* Audio support
***************************************************/
#if defined(__BES_TS_SUPPORT__)
    #define __VE_BES_TS_SUPPORT__
#endif

/**************************************************
* Audio support
***************************************************/
#if defined(__BT_A2DP_PROFILE__)
#define __VE_BT_A2DP_SUPPORT__
#endif

/**************************************************
* Subtitle support
***************************************************/
#if defined(__VIDEO_ARCHI_V2__)
#if defined(__VIDEO_SUBTITLE_SUPPORT__)
#define __VE_SUBTITLE_SUPPORT__
#endif
#endif

/**************************************************
* FLV file format support
***************************************************/
#if defined(__FLV_FILE_FORMAT_SUPPORT__)
#define __VE_FLV_FILE_FORMAT_SUPPORT__
#define __VE_FLV_PSEUDO_KEY_TABLE__
#endif

/**************************************************
* MKV file format support
***************************************************/
#if defined(__VIDEO_ARCHI_V2__)
#if defined(__MKV_FILE_FORMAT_SUPPORT__)
#define __VE_MKV_FILE_FORMAT_SUPPORT__
#endif
#endif

/**************************************************
* Source provider
***************************************************/
#if defined(__VIDEO_ARCHI_V2__)

#if !defined(__STREAM_SERVER_SUPPORT__)
#define __VE_SOURCE_PROVIDER__
#endif

//#define SP_CONTAINER_INTEGRITY
#define __VE_SP_DIRECT_SEEK__
#define __VE_SP_PREVIEW__
#define __VE_SP_LOG_FUNC__
#define __VE_SP_LOG_HIGH__
#ifndef __VE_SLIM_PROJECT__
 #define __VE_SP_SEEK_SPEED_UP__
 #define __VE_SP_LOG_LOW__
 #define __VE_SP_DBG__
#endif
#ifdef __VE_STREAM_SUPPORT__
 #define __VE_SP_STREAM_JUMP__
#endif 
#if defined(MT6268)
 #define __VE_SP_HW_DEC_PIPELINE__
#endif
//#define __VE_SP_PROFILE__
#ifdef __VE_SP_PROFILE__
 //#define __VE_SP_PROFILE_V_MIN_BUFFER__
 //#define __VE_SP_PROFILE_A_MIN_BUFFER__
#endif
#if defined(__MP4_DEC_SW_SLIM__) || defined(__H264_DEC_SW_SLIM__) || defined(__MJPG_DEC_SW_SLIM__) || defined(LOW_COST_SUPPORT)
 #define __VE_SP_SLIM__
#endif
//#define __VE_DUMP_PROVIDER_BITSTREAM__
#endif

/**************************************************
* MP4 file format supprt
***************************************************/
#ifdef __M3GPMP4_FILE_FORMAT_SUPPORT__
#define __VE_MP43GP_FILE_FORMAT_SUPPORT__
#if defined(__VIDEO_3D_ANAGLYPH__)
#define __VE_PRIRATE_3D_FORMAT__
#endif
#define __VE_MP43GP_MULTI_TRACK__

#if defined(__H264_DEC_SUPPORT__) || defined(__MP4_DEC_SW_SUPPORT_ASP__)
#define __VE_MP4_PARSER_SUPPORT_CTTS__
#endif
#endif

/**************************************************
* avi provider
***************************************************/
#if defined(MJPG_DECODE)
#define __VE_SP_AVI__
#define __VE_SP_AVI_DBG__
#define __VE_SP_AVI_LOG_HIGH__
#ifndef __VE_SLIM_PROJECT__
#define __VE_SP_AVI_LOG_FUNC__
#define __VE_SP_AVI_LOG_LOW__
#define __VE_SP_AVI_NON_IDX1_PLAYBACK__
#define __VE_SP_AVI_ASSERT__
#endif
//#define __VE_SP_AVI_PROFILE__
#endif

/**************************************************
* rm provider
***************************************************/
#if defined(__RM_DEC_SUPPORT__)
#define __VE_SP_RM__
#endif

/**************************************************
* Fluency control
***************************************************/
#if defined( __VE_VIDEO_ARCHI_V2__ ) && !defined(__VE_ULC_PROJECT__)
    #define __VE_VFC_RECOVER_SUPPORT__
    #define __VE_VFC_SCD_SUPPORT__
#endif
/**
 Feature option: VIDEO_PLAYER_RECORDER_W_DCM = ENABLE
 **/
#if defined(__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__) && defined(__MTK_TARGET__)
#define __VE_DCM_WITH_COMPRESSION__
#endif

#if !defined(__VE_ULC_PROJECT__) && !defined(__VE_KMV_SUPPORT__)
#define __VE_DURATION_MODE__  /*Video Smooth Display*/
#endif

/**
 Feature option: MM_DCM = ENABLE
 **/
#if defined(__MM_DCM_SUPPORT__) && defined(__MTK_TARGET__)

#ifndef __DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__
    #error "__DCM_W_COMPRESSION_VIDEO_PLAYER_RECORDER__ should defined for __MM_DCM_SUPPORT__"
#endif

#define __VE_MM_DCM_SUPPORT__
#endif

#ifdef __TIME_LAPSE_VIDEO_RECORDER__
    #define __VE_TIME_LAPSE_VIDEO_RECORDER__
#endif

#ifdef __STREAM_SERVER_SUPPORT__
#define __VE_STREAM_SERVER_SUPPORT__
#define __VE_SUPPORT_RTP_MUXER_ADAPTER__
#endif

/**************************************************
* MOT Feature
***************************************************/
#ifdef __MOT_SUPPORT__
#define __VE_MOT_CATEGORY__
#define __VE_MOT_DECRYPTION__
#endif

/**
  MJPG Encode Mode
**/
#ifdef __MJPEG_ENC_SW_SLIM__
    #define __VE_MJPEG_ENC_SW_SLIM__
#endif

#endif   /*End __DRV_FEATURES_VIDEO_H__*/
