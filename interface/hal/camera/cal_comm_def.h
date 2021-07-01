/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *	.h
 *
 * Project:
 * --------
 *   MT6238
 *
 * Description:
 * ------------
 *   This file is intends for ISP HW.
 *
 * Author:
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __CAL_COMM_DEF_H__
#define __CAL_COMM_DEF_H__

#include "kal_release.h"
#include "mm_comm_def.h"
#include "usbvideo_custom.h"
#include "img_common_enum.h"
#include "jpeg_enum.h"

/* CAL feature related definition */
#define CAL_FEATURE_NOT_SUPPORT		        (0x00000000)
#define CAL_FEATURE_GET_SUPPORT		        (0x00000001)
#define CAL_FEATURE_SET_SUPPORT		        (0x00000002)
#define CAL_FEATURE_GET_SET_SUPPORT         (CAL_FEATURE_GET_SUPPORT|CAL_FEATURE_SET_SUPPORT)

#define CAL_FEATURE_CAMERA_SUPPORT		    (0x00000001)
#define CAL_FEATURE_VIDEO_SUPPORT		    (0x00000002)
#define CAL_FEATURE_CAMERA_VIDEO_SUPPORT	(CAL_FEATURE_CAMERA_SUPPORT|CAL_FEATURE_VIDEO_SUPPORT)

#define CAL_CTRL_CODE_INIT         (0x00000001)
#define CAL_CTRL_CODE_DEINIT       (0x00000002)
#define CAL_CTRL_CODE_CONFIG       (0x00000004)
#define CAL_CTRL_CODE_START        (0x00000008)
#define CAL_CTRL_CODE_STOP         (0x00000010)
#define CAL_CTRL_CODE_PAUSE        (0x00000020)
#define CAL_CTRL_CODE_RESUME       (0x00000040)

#define CAM_SIZE_QVGA_WIDTH 	320
#define CAM_SIZE_QVGA_HEIGHT 	240
#define CAM_SIZE_VGA_WIDTH 		640
#define CAM_SIZE_VGA_HEIGHT 	480
#define CAM_SIZE_05M_WIDTH 		800
#define CAM_SIZE_05M_HEIGHT 	600
#define CAM_SIZE_1M_WIDTH 		1280
#define CAM_SIZE_1M_HEIGHT 		960
#define CAM_SIZE_2M_WIDTH 		1600
#define CAM_SIZE_2M_HEIGHT 		1200
#define CAM_SIZE_3M_WIDTH 		2048
#define CAM_SIZE_3M_HEIGHT 		1536
#define CAM_SIZE_5M_WIDTH 		2592
#define CAM_SIZE_5M_HEIGHT 		1944


typedef enum
{
    CAL_SCENARIO_CTRL=0,
    CAL_FEATURE_CTRL,
    CAL_CTRL_MAX
} CAL_CTRL_ENUM;

typedef enum
{
    CAL_SCENARIO_CAMERA_PREVIEW=0,
    CAL_SCENARIO_CAMERA_STILL_CAPTURE,
    CAL_SCENARIO_CAMERA_ZSD_PREVIEW,
    CAL_SCENARIO_CAMERA_ZSD_CAPTURE,
    CAL_SCENARIO_VIDEO,
    CAL_SCENARIO_VIDEO_TELEPHONY,
    CAL_SCENARIO_WEBCAM_PREVIEW,
    CAL_SCENARIO_WEBCAM_CAPTURE,
    CAL_SCENARIO_MATV,
    CAL_SCENARIO_POST_PROCESSING,
    CAL_SCENARIO_CCT_CAMERA_PREVIEW,
    CAL_SCENARIO_CCT_CAMERA_CAPTURE_JPEG,
    CAL_SCENARIO_CCT_CAMERA_CAPTURE_RAW,
    CAL_SCENARIO_CAMERA_STILL_CAPTURE_MEM,  // for wallpaper capture, for MDP driver only
    CAL_SCENARIO_VIDEO_MJPEG,               // for 720P MJPEG mode, for MDP driver only
    CAL_SCENARIO_CAMERA_MAV_CAPTURE,         // for multiple angle view feature capture
    CAL_SCENARIO_CAMERA_GYRO_PREVIEW,       // for camera gyro preview
    CAL_SCENARIO_MAX = 0xFF
} CAL_SCENARIO_ENUM;

typedef enum
{
    CAL_CBID_BEGIN=0,                   // for CAL callback to MED
    CAL_CBID_MAIN_IMAGE_READY,          // CAL_BUFFER_CB_STRUCT, callback when main image of still image is ready,
    CAL_CBID_QUICK_VIEW_IMAGE_READY,    // CAL_BUFFER_CB_STRUCT, callback when quick view image of still image is ready,
    CAL_CBID_THUMBNAIL_IMAGE_READY,     // CAL_BUFFER_CB_STRUCT, callback when thumbnail image of still image is ready,
    CAL_CBID_STILL_IMAGE_READY,         //  CAL_BUFFER_CB_STRUCT, callback when the integration of main/quick view/thumbnail image is done.
    CAL_CBID_STILL_IMAGE_TIMEOUT,       //  CAL_BUFFER_CB_STRUCT, callback when still capture timer expiry.
    CAL_CBID_VIDEO_IMAGE_READY,         // CAL_BUFFER_CB_STRUCT, callback when video image for video record is ready,
    CAL_CBID_DISPLAY_IMAGE_ROTATE_READY,// CAL_BUFFER_CB_STRUCT, callback when display image rotate done,
    CAL_CBID_AF_RESULT,                 // CAL_CAMERA_AF_RESULT_STRUCT, callback when AF result is ready
    CAL_CBID_FD_RESULT,              // CAL_CAMERA_FD_RESULT_STRUCT, callback when FD result is ready
    CAL_CBID_SD_RESULT,              // CAL_CAMERA_SD_RESULT_STRUCT, callback when SD result is ready
    CAL_CBID_PANO_RESULT,               //  CAL_CAMERA_PANO_RESULT_STRUCT, callback when PANO result is ready
    CAL_CBID_PANO_BG_ADD_IMAGE_READY, //  return CurrentShotNumber, callback when PANO bg stitch is ready
    CAL_CBID_PANO_IMAGE_READY,              //  CAL_BUFFER_CB_STRUCT, callback when the single PANO image buffer (JPEG or YUV) is ready.
    CAL_CBID_PANO_QUICK_VIEW_IMAGE_READY,   //  CAL_BUFFER_CB_STRUCT, callback when the quick view buffer of stitched image (YUV) is ready.    
    CAL_CBID_AUTOCAP_RESULT,            //  CAL_CAMERA_AUTOCAP_RESULT_STRUCT, callback when AUTOCAP result is ready.
    CAL_CBID_PANO_QVI_FOR_JAIA_READY,   //NULL, callback when the QVI (after clipping) for JAIA is ready.
    CAL_CBID_HDR_RESULT, //  CAL_CAMERA_HDR_RESULT_STRUCT, callback when HDR result is ready
    CAL_CBID_HDR_QUICK_VIEW_IMAGE_READY, //  CAL_BUFFER_CB_STRUCT, callback when the quick view buffer of HDR image is ready.
    CAL_CBID_ASD_RESULT,              // CAL_CAMERA_ASD_RESULT_STRUCT, callback when ASD result is ready
    CAL_CBID_PREVIEW_IMAGE_READY,       // CAL_BUFFER_CB_STRUCT, callback when the preview buffer for AP is ready.
    CAL_CBID_PREVIEW_IMAGE_EFFECT_READY,    // CAL_BUFFER_CB_STRUCT, callback when image effect done,
    CAL_CBID_CAPTURE_IMAGE_EFFECT_READY,    // CAL_BUFFER_CB_STRUCT, callback when image effect done,
    CAL_CBID_MAV_CAPTURE_IMAGE_READY,   // when each mav capture is ready 
    CAL_CBID_MAV_STITCH_IMAGE_READY,     // when mav stitch is ready return QVI buffer
    CAL_CBID_CAM_GYRO_RESULT,           // MAVCAP_RESULT_STRUCT 
    CAL_CBID_ISP_BEGIN=100,             // for ISP callback to CAL
    CAL_CBID_ISP_CAPTURE_RESIZER_OVERRUN,//NULL, callback when resizer overrun in capture scenario
    CAL_CBID_ISP_CAPTURE_GMC_OVERRUN, //NULL, callback when gmc overrun in capture scenario
    CAL_CBID_MDP_BEGIN=200,             // for MDP callback to CAL

    IDPCAL_CBID_CAM_CAPTURE_MAIN_IMAGE_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_CAM_CAPTURE_QUICKVIEW_IMAGE_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_CAM_CAPTURE_THUMBNAIL_IMAGE_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_CAM_CAPTURE_CROP_SIZE_IMAGE_DONE, // for image effect processing ex. lomo or color accent
    IDPCAL_CBID_CAM_CAPTURE_YUV_IMG_DONE, //NULL    

    IDPCAL_CBID_CAM_PREVIEW_DISPLAY_FRM_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_CAM_PREVIEW_POSTPROC_FRM_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_CAM_PREVIEW_CRZ_FRM_START, //NULL
    IDPCAL_CBID_CAM_PREVIEW_ZSD_YUV_IMG_DONE, //NULL

    IDPCAL_CBID_VIDEO_ENCODE_PREVIEW_DISPLAY_FRM_DONE, //IDPCAL_CB_ARG_FRAME_DONE*
    IDPCAL_CBID_VIDEO_ENCODE_ENCODE_FRM_DONE,  // Not used
    IDPCAL_CBID_VIDEO_ENCODE_CRZ_FRM_START, //NULL
    IDPCAL_CBID_VIDEO_ENCODE_GET_ENC_BUF, //kal_uint32*
//    IDPCAL_CBID_VIDEO_ENCODE_GET_DUM_BUF, //kal_uint32*
    IDPCAL_CBID_VIDEO_ENCODE_RET_ENC_BUF, //kal_uint8*

    CAL_CBID_JPEG_BEGIN=400,            // for JPEG encoder callback to CAL
    CAL_CBID_JPEG_ENC_COMPLETE,         // callback when hardware JPEG encode complete
    CAL_CBID_WEBCAM_BEGIN=600,          // for web camera callback to MED
    CAL_CBID_WEBCAM_GET_VIDEO_BUFF,     // CAL_WEBCAM_CB_STRUCT,
    CAL_CBID_WEBCAM_COMPLETE_VIDEO_BUFF,// CAL_WEBCAM_CB_STRUCT
    CAL_CBID_WEBCAM_GET_STILL_BUFF,     // CAL_WEBCAM_CB_STRUCT
    CAL_CBID_WEBCAM_COMPLETE_STILL_BUFF,// CAL_WEBCAM_CB_STRUCT
} CAL_CALLBACK_ID_ENUM;


// for those features of CCT
typedef struct
{
    //CAL_CCT_FEATURE_ENUM CctFeatureId;
    void *pCctFeatureParaIn;
    kal_uint32 CctFeatureParaInLen;
    void *pCctFeatureParaOut;
    kal_uint32 CctFeatureParaOutLen;
    kal_uint32 *pRealCctFeatureParaOutLen;
} CAL_CCT_FEATURE_CTRL_STRUCT, *P_CAL_CCT_FEATURE_CTRL_STRUCT;

typedef enum
{
    CAL_CAMERA_FEATURE_BEGIN=0,
    CAL_ISP_FEATURE_BEGIN=1000,
    CAL_SENSOR_FEATURE_BEGIN=2000,
    CAL_LENS_FEATURE_BEGIN=4000,
    CAL_CCT_FEATURE_BEGIN=5000,
    CAL_WEBCAM_FEATURE_BEGIN=6000,
    CAL_CAMERA_ENGINEER_FEATURE_BEGIN=7000,
    CAL_CAMERA_PROFILING_FEATURE_BEGIN = 8000,
} CAL_FEATURE_GROUP_ENUM;

typedef enum
{
    CAL_FEATURE_CAMERA_BEGIN = CAL_CAMERA_FEATURE_BEGIN,
    CAL_FEATURE_CAMERA_BRIGHTNESS,              //
    CAL_FEATURE_CAMERA_CONTRAST,                // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_CONTRAST_ENUM
    CAL_FEATURE_CAMERA_HUE,                     // does not support now
    CAL_FEATURE_CAMERA_SATURATION,              // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_SATURATION_ENUM
    CAL_FEATURE_CAMERA_SHARPNESS,               // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_SHARPNESS_ENUM
    CAL_FEATURE_CAMERA_GAMMA,                   // does not support now.
    CAL_FEATURE_CAMERA_WB,                      // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_WB_ENUM
    CAL_FEATURE_CAMERA_DIGITAL_ZOOM,            // CAL_FEATURE_TYPE_STRUCTURED, In: CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT, Out : CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT
    CAL_FEATURE_CAMERA_CURRENT_ZOOM_FACTOR,     // get/set digital zoom factor
    CAL_FEATURE_CAMERA_CURRENT_ZOOM_STEP,       // get current digital zoom step
    CAL_FEATURE_CAMERA_FAST_ZOOM,               // CAL_FEATURE_TYPE_STRUCTURED, CAL_CAMERA_FAST_ZOOM_STRUCT
    CAL_FEATURE_CAMERA_EV_VALUE,                // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_EV_ENUM
    CAL_FEATURE_CAMERA_FLASH_MODE,              // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_FLASH_ENUM
    CAL_FEATURE_CAMERA_IMAGE_EFFECT,            // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_IMAGE_EFFECT_ENUM
    CAL_FEATURE_CAMERA_BANDING_FREQ,            // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_BANDING_FREQ_ENUM
    CAL_FEATURE_CAMERA_SCENE_MODE,              // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_SCENE_MODE_ENUM
    CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE,        // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_VIDEO_SCENE_MODE_ENUM
    CAL_FEATURE_CAMERA_AE_METERING_MODE,        // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_AE_METERING_MODE_ENUM
    CAL_FEATURE_CAMERA_AF_KEY,                  // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_AF_KEY_ENUM
    CAL_FEATURE_CAMERA_AF_RANGE_CONTROL,        // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_AF_RANGE_ENUM
    CAL_FEATURE_CAMERA_AF_OPERATION_MODE,       // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_AF_OPERATION_MODE_ENUM
    CAL_FEATURE_CAMERA_GET_AF_ZONE,        // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_GET_AF_ZONE_PARA_ENUM
    CAL_FEATURE_CAMERA_AF_RESULT,				// CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_AF_RESULT,
    CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE,      // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_STILL_CAPTURE_ENUM
    CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE,      // CAL_FEATURE_TYPE_ENUMERATE, CAM_IMAGE_SIZE_ENUM
    CAL_FEATURE_CAMERA_ZSD_CAPTURE_SIZE,        // CAL_FEATURE_TYPE_ENUMERATE, CAM_IMAGE_SIZE_ENUM
    CAL_FEATURE_CAMERA_BINNING_INFO,            // CAL_FEATURE_TYPE_STRUCTURED, CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT
    CAL_FEATURE_CAMERA_SOURCE_SELECT,           // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_SOURCE_ENUM
    CAL_FEATURE_CAMERA_PANO_DIRECTION,          // CAL_FEATURE_TYPE_ENUMERATE, CAL_CAMERA_PANO_DIRECTION_ENUM
    CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_START, // CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT
    CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_STOP,  // CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT
    CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_PAUSE, // CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT
    CAL_FEATURE_CAMERA_BG_PANO_ADD_IMAGE_RESUME,  // CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT
    CAL_FEATURE_CAMERA_ENCODE_PANORAMA,         // CAL_FEATURE_TYPE_ENUMERATE, P_CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT
    CAL_FEATURE_CAMERA_SMILE_DETECT_START,      // CAL_FEATURE_TYPE_COMMAND, just send the feature ID to CAL
    CAL_FEATURE_CAMERA_HDR_CAPTURE_ABORT, // CAL_FEATURE_TYPE_ENUMERATE,
    CAL_FEATURE_CAMERA_GET_BSS_RESULT,          // CAL_FEATURE_TYPE_STRUCTURED, In : CAL_CAMERA_GET_BSS_RESULT_IN_STRUCT, Out : CAL_CAMERA_GET_BSS_RESULT_OUT_STRUCT, get the best picture index and size in best shot select mode
    CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE,       // CAL_FEATURE_TYPE_STRUCTURED, In : CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT, Out : NULL
    CAL_FEATURE_CAMERA_GET_FRAME_RATE,          // only support get operation
    CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION,// CAL_FEATURE_TYPE_STRUCTURED In : CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT, Out : FeatureCurrentValue, support get operation only
    CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY, // CAL_FEATURE_TYPE_STRUCTURED, In : NULL, Out : CAL_CAMERA_CAPTURE_OVERLAY_CAPABILITY_OUT_STRUCT
    CAL_FEATURE_CAMERA_QUERY_SW_ROTATE,         // CAL_FEATURE_TYPE_STRUCTURED, In : Out :
    CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_PAUSE, // CAL_FEATURE_TYPE_ENUMERATE, In : Out :
    CAL_FEATURE_CAMERA_PREVIEW_POSTPROC_RESUME,  // CAL_FEATURE_TYPE_ENUMERATE, In : Out : 
    CAL_FEATURE_CAMERA_TUNING_SENSOR,						//For Sensor tuning
    CAL_FEATURE_CAMERA_SET_VIDEO_ROT_ANGLE,     // CAL_FEATURE_TYPE_ENUMERATE, MM_IMAGE_ROTATE_ENUM
    CAL_FEATURE_CAMERA_STILL_CAPTURE_SIZE_WITH_DIMENSION,      // CAL_FEATURE_TYPE_ENUMERATE, CAM_IMAGE_SIZE_ENUM
    CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_ADDR,      // set extra QVI buffer address
    CAL_FEATURE_CAMERA_EXTRA_QVI_BUF_SIZE,      // set extra QVI buffer size
    CAL_FEATURE_CAMERA_JAIA_DISABLE,            // set jaia disable
    CAL_FEATURE_CAMERA_SENOSR_OUTPUT_TEST_PATTERN, // Camera Auto Test System
    CAL_FEATURE_CAMERA_GET_TEST_PATTERN,           // Camera Auto Test System, Out : Test pattern buffer addr
	CAL_FEATURE_CAMERA_PREVIEW_SIZE,			// CAL_FEATURE_TYPE_ENUMERATE, CAL_FEATURE_CAMERA_PREVIEW_SIZE
    CAL_FEATURE_CAMERA_END,
} CAL_CAMERA_FEATURE_ENUM;

typedef enum
{
    CAL_FEATURE_CAM_ENGINEER_BEGIN = CAL_CAMERA_ENGINEER_FEATURE_BEGIN,
    CAL_FEATURE_CAM_ENGINEER_SET_RAW_BIT,              // set raw data bit depth
    CAL_FEATURE_CAM_ENGINEER_GET_RAW_INFO,          // get raw data info (addr, size, width, height)
    CAL_FEATURE_CAM_ENGINEER_SET_RAW_ADDR,         // set raw data address
    CAL_FEATURE_CAM_ENGINEER_SET_EM,                      // set aaa em mode
    CAL_FEATURE_CAM_ENGINEER_SAVE_LOG,                  // save aaa log
    CAL_FEATURE_CAM_ENGINEER_SET_SHADE_EN,              // shading enable/disable
    CAL_FEATURE_CAM_ENGINEER_END,
} CAL_CAMERA_ENGINEER_FEATURE_ENUM;

// check whether we can merge all the six information into single. (CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_INFO ~ CAL_FEATURE_WEBCAM_GET_DEFAULT_COMPRESSION_IDX)
typedef enum
{
    CAL_FEATURE_WEBCAM_BEGIN=CAL_WEBCAM_FEATURE_BEGIN,
    CAL_FEATURE_WEBCAM_GET_ATTR,            // two level features, the feature ID of webcam will follow the definition of MSFT, structured feature
    CAL_FEATURE_WEBCAM_SET_ATTR,            // two level features, the feature ID of webcam will follow the definition of MSFT, structured feature
    CAL_FEATURE_WEBCAM_GET_ATTR_INFO,       // route to sensor driver
    CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE,
    CAL_FEATURE_WEBCAM_GET_STILL_SIZE,
    CAL_FEATURE_WEBCAM_GET_COMPRESSION,
    CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX,
    CAL_FEATURE_WEBCAM_END,
} CAL_WEBCAM_FEATURE_ENUM;

typedef enum
{
    CAL_CAMERA_MODE_CAMERA=0,
    CAL_CAMERA_MODE_VIDEO,
    CAL_CAMERA_MODE_AUTORAMA,
    CAL_CAMERA_MODE_MAX
} CAL_CAMERA_MODE_ENUM;

typedef enum
{
    CAM_IMAGE_SIZE_WALLPAPER=0,
    CAM_IMAGE_SIZE_QVGA,
    CAM_IMAGE_SIZE_VGA,
    CAM_IMAGE_SIZE_1M,
    CAM_IMAGE_SIZE_2M,
    CAM_IMAGE_SIZE_3M,
    CAM_IMAGE_SIZE_4M,
    CAM_IMAGE_SIZE_5M,
    CAM_IMAGE_SIZE_8M,
    CAM_IMAGE_SIZE_OTHER,
    CAM_IMAGE_SIZE_NOT_SUPPORT
} CAM_IMAGE_SIZE_ENUM;

typedef struct
{
    kal_uint16 ImageSizeWidth;
    kal_uint16 ImageSizeHeight;
} CAL_CAMERA_IMAGE_SIZE_STRUCT, *P_CAL_CAMERA_IMAGE_SIZE_STRUCT;

// the one will be merged into CAM_IMAGE_SIZE_ENUM in HAL version
typedef enum
{
    CAM_SIZE_WALLPAPER=0,
    CAM_SIZE_QVGA,
    CAM_SIZE_VGA,
    CAM_SIZE_1M,
    CAM_SIZE_2M,
    CAM_SIZE_3M,
    CAM_SIZE_4M,
    CAM_SIZE_5M,
    CAM_SIZE_8M,
    CAM_SIZE_OTHER,
    CAM_SIZE_NOT_SUPPORT
}CAP_SIZE;

typedef enum
{
    IMAGE_SENSOR_MIRROR_NORMAL=0,
    IMAGE_SENSOR_MIRROR_H,
    IMAGE_SENSOR_MIRROR_V,
    IMAGE_SENSOR_MIRROR_HV,
} IMAGE_SENSOR_MIRROR_ENUM;

typedef enum
{
    CAL_RAW_CAPTURE_MODE_OFFLINE=0,
    CAL_RAW_CAPTURE_MODE_OTF,
} CAL_RAW_CAPTURE_MODE_ENUM;

/* begin of CAL feature control interface */

// for CAL_FEATURE_CAMERA_CONTRAST
typedef enum
{
    CAM_CONTRAST_LOW=0,
    CAM_CONTRAST_MEDIUM,
    CAM_CONTRAST_HIGH,
    CAM_CONTRAST_MAX
} CAL_CAMERA_CONTRAST_ENUM;

// for CAL_FEATURE_CAMERA_SATURATION
typedef enum
{
    CAM_SATURATION_LOW=0,
    CAM_SATURATION_MEDIUM,
    CAM_SATURATION_HIGH,
    CAM_SATURATION_MAX
} CAL_CAMERA_SATURATION_ENUM;

// for CAL_FEATURE_CAMERA_SHARPNESS
typedef enum
{
    CAM_SHARPNESS_LOW=0,
    CAM_SHARPNESS_MEDIUM,
    CAM_SHARPNESS_HIGH,
    CAM_SHARPNESS_MAX
} CAL_CAMERA_SHARPNESS_ENUM;

// for CAL_FEATURE_CAMERA_WB
typedef enum
{
    CAM_WB_AUTO = 0,
    CAM_WB_CLOUD,
    CAM_WB_DAYLIGHT,
    CAM_WB_INCANDESCENCE,
    CAM_WB_FLUORESCENT,
    CAM_WB_TUNGSTEN,
    CAM_WB_MANUAL,
    CAM_NO_OF_WB
} CAL_CAMERA_WB_ENUM;

// for CAL_FEATURE_CAMERA_DIGITAL_ZOOM
typedef enum
{
    CAM_DZ_TYPE_RANGE,      // ISP supported digital zoom . (for Raw/YUV sensors)
    CAM_DZ_TYPE_LIST,       // Sensor supported digial zoom. (for JPEG sensor)
    CAM_DZ_TYPE_MAX
} CAL_CAMERA_DIGITAL_ZOOM_TYPE_ENUM;

typedef struct
{
    CAL_SCENARIO_ENUM   ScenarioId;
    CAM_IMAGE_SIZE_ENUM CameraImageSize;
} CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT, *P_CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT;

typedef struct
{
    CAL_CAMERA_DIGITAL_ZOOM_TYPE_ENUM DzType;
    kal_uint8 TotalZoomSteps;   // step between 0..(TotalZoomSteps-1)
    kal_uint16 MaxZoomFactor;   // zoom factor between 100..MaxZoomFactor (1.0~MaxZoomFactor/100)
    // for CAM_DZ_TYPE_LIST only. the zoom factor list table will maintain in sensor driver.
    // the number of Zoom factor list is declared in TotalZoomSteps
    const kal_uint16 *pZoomFactorListTable;
} CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT, *P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT;

// CAL_FEATURE_CAMERA_EV_VALUE
typedef enum
{
    CAM_EV_NEG_4_3 = 0,
    CAM_EV_NEG_3_3,
    CAM_EV_NEG_2_3,
    CAM_EV_NEG_1_3,
    CAM_EV_ZERO,
    CAM_EV_POS_1_3,
    CAM_EV_POS_2_3,
    CAM_EV_POS_3_3,
    CAM_EV_POS_4_3,
    CAM_EV_NIGHT_SHOT,
    CAM_NO_OF_EV
} CAL_CAMERA_EV_ENUM;

// for CAL_FEATURE_CAMERA_FLASH
typedef enum
{
    CAM_FLASH_OFF = 0,
    CAM_FLASH_ON,
    CAM_FLASH_AUTO,
    CAM_FLASH_REDEYE,
    CAM_NO_OF_FLASH
} CAL_CAMERA_FLASH_ENUM;

// for CAL_FEATURE_CAMERA_IMAGE_EFFECT
typedef enum
{
    CAM_EFFECT_ENC_NORMAL = 0,
    CAM_EFFECT_ENC_GRAYSCALE,
    CAM_EFFECT_ENC_SEPIA,
    CAM_EFFECT_ENC_SEPIAGREEN,
    CAM_EFFECT_ENC_SEPIABLUE,
    CAM_EFFECT_ENC_COLORINV,
    CAM_EFFECT_ENC_GRAYINV,
    CAM_EFFECT_ENC_BLACKBOARD,
    CAM_EFFECT_ENC_WHITEBOARD,
    CAM_EFFECT_ENC_COPPERCARVING,
    CAM_EFFECT_ENC_EMBOSSMENT,
    CAM_EFFECT_ENC_BLUECARVING,
    CAM_EFFECT_ENC_CONTRAST,
    CAM_EFFECT_ENC_JEAN,
    CAM_EFFECT_ENC_SKETCH,
    CAM_EFFECT_ENC_OIL,
    CAM_EFFECT_ENC_LOMO,
    CAM_EFFECT_ENC_COLOR_RED,
    CAM_EFFECT_ENC_COLOR_YELLOW,
    CAM_EFFECT_ENC_COLOR_GREEN,
    CAM_EFFECT_ENC_COLOR_BLUE,
    CAM_NO_OF_EFFECT_ENC
} CAL_CAMERA_IMAGE_EFFECT_ENUM;

// for CAL_FEATURE_CAMERA_BANDING_FREQ
typedef enum
{
    CAM_BANDING_50HZ = 0,
    CAM_BANDING_60HZ,
    CAM_NO_OF_BANDING
} CAL_CAMERA_BANDING_FREQ_ENUM;


// for CAL_FEATURE_CAMERA_SCENE_MODE
typedef enum
{
    CAM_AUTO_DSC = 0,
    CAM_PORTRAIT,
    CAM_LANDSCAPE,
    CAM_SPORT,
    CAM_FLOWER,
    CAM_NIGHTSCENE,
    CAM_TV_MODE,    /* !MT6238 , has to be removed but PC side tool need to modify also*/
    CAM_AV_MODE,    /* !MT6238 , has to be removed but PC side tool need to modify also */
    CAM_ISO_MODE,   /* !MT6238 , has to be removed but PC side tool need to modify also */
    CAM_DOCUMENT,
    CAM_ISO_ANTI_HAND_SHAKE,
    CAM_ISO100,
    CAM_ISO200,
    CAM_ISO400,
    CAM_ISO800,
    CAM_ISO1600,
    /* ASD */
    CAM_BACKLIGHT,                      // for ASD mode only
    CAM_BACKLIGHT_PORTRAIT,    // for ASD mode only
    CAM_NIGHT_PORTRAIT,            // for ASD mode only
    CAM_NO_OF_SCENE_MODE,
} CAL_CAMERA_SCENE_MODE_ENUM;

// for CAL_FEATURE_CAMERA_VIDEO_SCENE_MODE
typedef enum
{
    CAM_VIDEO_SCENE_BEGIN = CAM_ISO1600,
    CAM_VIDEO_AUTO,
    CAM_VIDEO_NIGHT,
} CAL_CAMERA_VIDEO_SCENE_MODE_ENUM;

// for CAL_FEATURE_CAMERA_AE_METERING_MODE
typedef enum
{
    CAM_AE_METER_AUTO = 0,
    CAM_AE_METER_SPOT,
    CAM_AE_METER_CENTRAL,
    CAM_AE_METER_AVERAGE,
    CAM_NO_OF_AE_METERING
} CAL_CAMERA_AE_METERING_MODE_ENUM;

// for CAL_FEATURE_CAMERA_AF_KEY
typedef enum
{
    CAM_AF_RELEASE = 0,
    CAM_AF_ONE_TIME,
    CAM_AF_CONTINUE,
    CAM_NO_OF_AF_KEY
} CAL_CAMERA_AF_KEY_ENUM;

// for CAL_FEATURE_CAMERA_AF_RANGE_CONTROL
typedef enum
{
    CAM_AF_RANGE_AUTO = 0,
    CAM_AF_RANGE_MACRO,
    CAM_AF_RANGE_LANDSCAPE,
    CAM_AF_RANGE_MANUAL,
    CAM_NO_OF_AF_RANGE
} CAL_CAMERA_AF_RANGE_ENUM;

// for CAL_FEATURE_CAMERA_AF_OPERATION_MODE
typedef enum
{
    CAM_AF_OFF,
    CAM_AF_SINGLE_ZONE,
    CAM_AF_MULTI5_ZONE,
    CAM_AF_CONTINUOUS,
    CAM_AF_MANUAL_MODE,
    CAM_AF_TOUCH_FOCUS_MODE,
    CAM_NO_OF_AF_OPERATION_MODE
} CAL_CAMERA_AF_OPERATION_MODE_ENUM;

/* for CAL_FEATURE_CAMERA_GET_AF_ZONE zone struct */
typedef struct
{
    kal_uint32 W;
    kal_uint32 H;
    kal_uint32 X;
    kal_uint32 Y;
} CAL_CAMERA_AF_RECT_STRUCT, *P_CAL_CAMERA_AF_RECT_STRUCT;

/* for CAL_FEATURE_CAMERA_GET_AF_ZONE zone struct */
#define AF_ZONE_NO (5)
typedef struct
{	/* AF Window Setting */
    kal_uint32                AfActiveZone;
    CAL_CAMERA_AF_RECT_STRUCT AfZoneLcd[AF_ZONE_NO]; /* for LCD display */
    CAL_CAMERA_AF_RECT_STRUCT AfZoneIsp[AF_ZONE_NO]; /* for ISP cal ATF */
} CAL_CAMERA_GET_AF_ZONE_STRUCT, *P_CAL_CAMERA_GET_AF_ZONE_STRUCT;

// for CAL_FEATURE_CAMERA_FAST_ZOOM
typedef struct
{
    kal_bool ZoomStart;
    kal_bool ZoomIn;
    kal_uint8 ZoomLimit;
    kal_uint8 ZoomStep;
    kal_uint8 ZoomSpeed;
} CAL_CAMERA_FAST_ZOOM_STRUCT, *P_CAL_CAMERA_FAST_ZOOM_STRUCT;

// for CAL_FEATURE_CAMERA_STILL_CAPTURE_MODE
typedef enum
{
    CAM_STILL_CAPTURE_NORMAL=0,
    CAM_STILL_CAPTURE_BEST_SHOT,
    CAM_STILL_CAPTURE_CONT_SHOT,
    CAM_STILL_CAPTURE_BURST_SHOT,
    CAM_STILL_CAPTURE_EV_BRACKETING,
    CAM_STILL_CAPTURE_ADD_FRAME,
    CAM_STILL_CAPTURE_PANO_VIEW,
    CAM_STILL_CAPTURE_AUTO_RAMA,
    CAM_STILL_CAPTURE_SMILE_SHOT,
    CAM_STILL_CAPTURE_HDR,
    CAM_STILL_CAPTURE_ZSD,
    CAM_STILL_CAPTURE_ASD,
    CAM_STILL_CAPTURE_MAV,
    CAM_STILL_CAPTURE_RAW_DATA,
    CAM_STILL_CAPTURE_3D_IMAGE,
    CAM_STILL_CAPTURE_MAX
} CAL_CAMERA_STILL_CAPTURE_ENUM;

typedef enum
{
    MULTISHOT_FALSE=0,
    MULTISHOT_FIRST,
    MULTISHOT_NOT_FIRST,
    MULTISHOT_END
} MULTISHOT_INFO_ENUM;

// for CAL_FEATURE_CAMERA_BINNING_INFO
typedef enum
{
    CAM_ISO_AUTO = 0,
    CAM_ISO_100,
    CAM_ISO_200,
    CAM_ISO_400,
    CAM_ISO_800,
    CAM_ISO_1600,
    CAM_NO_OF_ISO
} CAMERA_ISO_ENUM;

typedef struct
{
    CAM_IMAGE_SIZE_ENUM  MaxResolution;
    kal_bool    IsoSupported;
    kal_bool    BinningEnable;
} BINNING_INFO_STRUCT, *P_BINNING_INFO_STRUCT;

typedef struct
{
    BINNING_INFO_STRUCT	IsoBinningInfo[CAM_NO_OF_ISO];
} CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT, *P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT;

// for CAL_FEATURE_CAMERA_SOURCE_SELECT
typedef enum
{
    CAL_CAMERA_SOURCE_MAIN,
    CAL_CAMERA_SOURCE_SUB,
    CAL_CAMERA_SOURCE_MATV,
    CAL_CAMERA_SOURCE_MAX,
} CAL_CAMERA_SOURCE_ENUM;

// for CAL_FEATURE_CAMERA_PANO_DIRECTION
typedef enum
{
    CAM_PANO_RIGHT_DIR=0,
    CAM_PANO_LEFT_DIR,
    CAM_PANO_UP_DIR,
    CAM_PANO_DOWN_DIR,
    CAM_NO_OF_PANO_DIR
} CAL_CAMERA_PANO_DIRECTION_ENUM;

//for CAL_FEATURE_CAMERA_GET_BSS_RESULT
typedef struct
{
    kal_uint8 SnapShotIndex;
    kal_uint32 JpegSize;
} CAL_CAMERA_GET_BSS_RESULT_IN_STRUCT, *P_CAL_CAMERA_GET_BSS_RESULT_IN_STRUCT;

typedef struct
{
    kal_uint8 BestShotIndex;
} CAL_CAMERA_GET_BSS_RESULT_OUT_STRUCT, *P_CAL_CAMERA_GET_BSS_RESULT_OUT_STRUCT;

// for CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE
typedef struct
{
    MM_IMAGE_FORMAT_ENUM ImageDataFormat;
    MM_IMAGE_ROTATE_ENUM ImageRotAngle;
    kal_uint16 ImageWidth;
    kal_uint16 ImageHeight;
    kal_uint32 ImageBuffAddr;
    kal_uint32 ImageBuffSize;
} CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT, *P_CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT;

// for CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION
typedef struct
{
    kal_uint16 ImageWidth;
    kal_uint16 ImageHeight;
    JPEG_ENCODE_QUALITTY_ENUM JpegEncQuality;
    MM_IMAGE_FORMAT_ENUM JpegSamplingFormat;
} CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT, *P_CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT;

// for CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY
typedef struct
{
    kal_bool CaptureOverlaySupport;
} CAL_CAMERA_CAPTURE_OVERLAY_CAPABILITY_OUT_STRUCT, *P_CAL_CAMERA_CAPTURE_OVERLAY_CAPABILITY_OUT_STRUCT;

// for CAL_FEATURE_CAMERA_QUERY_SW_ROTATE
typedef struct
{
    CAL_SCENARIO_ENUM ScenarioId;
    MM_IMAGE_ROTATE_ENUM DisplayImageRotAngle;
    MM_IMAGE_ROTATE_ENUM TargetImageRotAngle;
} CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT, *P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT;

typedef struct
{
    kal_bool RequireSwRotate;
} CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_OUT_STRUCT, *P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_OUT_STRUCT;

/* web camera features start */
// for CAL_FEATURE_WEBCAM_GET_ATTR_INFO
typedef struct
{
    const USBVideo_Attr_Info *pWebCamAttrInfo;
    kal_uint8 WebCamAttrInfoNum;
} CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT, *P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT;

// for CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE
typedef struct
{
    const USBVideo_Video_Size_Info *pWebCamVideoSizeInfo;
    kal_uint8 WebCamVideoSizeInfoNum;
} CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT, *P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT;

// for CAL_FEATURE_WEBCAM_GET_STILL_SIZE
typedef struct
{
    const USBVideo_Still_Size_Info *pWebCamStillSizeInfo;
    kal_uint8 WebCamStillSizeInfoNum;
} CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT, *P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT;

// for CAL_FEATURE_WEBCAM_GET_COMPRESSION
typedef struct
{
    const USBVideo_Compression_Info *pWebCamCompressionInfo;
    kal_uint8 WebCamCompressionInfoNum;
} CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT, *P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT;

// for CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX
typedef struct
{
    USBVIDEO_VIDEO_SIZE_TYPE WebCamVideoSizeIdx;
    USBVIDEO_STILL_SIZE_TYPE WebCamStillSizeIdx;
    USBVIDEO_COMPRESSION_TYPE WebCamCompressionIdx;
} CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT, *P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT;

// CAL_FEATURE_WEBCAM_GET_ATTR, CAL_FEATURE_WEBCAM_SET_ATTR
typedef USBVideo_Attr_Value CAL_FEATURE_WEBCAM_ATTR_STRUCT;
typedef USBVideo_Attr_Value *P_CAL_FEATURE_WEBCAM_ATTR_STRUCT;
/* web camera features end */

typedef enum
{
    CAL_CAMERA_PROFILING_NULL=0,
    CAL_CAMERA_PROFILING_CAPTURE_KEY_PRESS,							/* profiling by MED */
    CAL_CAMERA_PROFILING_EXIT_CAMERA_PREVIEW,
    CAL_CAMERA_PROFILING_ENTER_CAPTURE,
    CAL_CAMERA_PROFILING_PREFLASH_COMPLETE,
    CAL_CAMERA_PROFILING_AAA_CAPTURE_COMP_COMPLETE, //5
    CAL_CAMERA_PROFILING_POST_PROCESS_FLASH_COMPLETE,
    CAL_CAMERA_PROFILING_BEFORE_CONFIG_SENSOR_DRIVER,
    CAL_CAMERA_PROFILING_CONFIG_SENSOR_DRIVER_COMPLETE,
    CAL_CAMERA_PROFILING_CONFIG_WAIT_STABLE_COMPLETE,
    CAL_CAMERA_PROFILING_RAW_IMAGE_OUT_COMPLETE,//10
    CAL_CAMERA_PROFILING_BEFORE_CONFIG_IDP_RESIZER,
    CAL_CAMERA_PROFILING_CONFIG_IDP_RESIZER_COMPLETE,
    CAL_CAMERA_PROFILING_CONFIG_JPEG_COMPLETE,
    CAL_CAMERA_PROFILING_MAINFLASH_TRIGGER_COMPLETE,
    CAL_CAMERA_PROFILING_CAPTURE_IDP_RESIZER_DONE,//15
    CAL_CAMERA_PROFILING_JPEG_DONE,									/* profiling by JpegCallback or Cal */
    CAL_CAMERA_PROFILING_IDP_RESIZER_TO_DISPLAY_COMPLETE,			/* profiling by IdpCallback or up layer ??*/
    CAL_CAMERA_PROFILING_CAMERA_CAPTURE_COMPLETE,
    CAL_CAMERA_PROFILING_BEFORE_SAVE_FILE,                          /// log file format
    CAL_CAMERA_PROFILING_SAVE_FILE_DONE,//20
    CAL_CAMERA_PROFILING_ENTER_CAMERA_PREVIEW,
    CAL_CAMERA_PROFILING_CAMERA_PREVIEW_COMPLETE,
    CAL_CAMERA_PROFILING_JPEG_SAVE_FILE_DONE,                       /* profiling by MED */
    CAL_CAMERA_PROFILING_OVER_BUFFER_SIZE,
    CAL_CAMERA_PROFILING_JAIA_DONE
} CAL_CAMERA_PROFILING_LOG_ENUM;


typedef struct
{
    CAL_CAMERA_PROFILING_LOG_ENUM LogId;
}CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT_STRUCT, *P_CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT_STRUCT;

typedef struct
{
    kal_uint8 *ResultBufferAddr;
    kal_uint32 ResultBufferSize;
    kal_uint32 ResultBufferOutputSize;
}CAL_FEATURE_CAMERA_PROFILING_GET_RESULT_STRUCT, *P_CAL_FEATURE_CAMERA_PROFILING_GET_RESULT_STRUCT;

typedef struct
{
    kal_uint16 ZoomStep;
    kal_uint16 SceneMode;
    kal_uint16 ShotNumber;
}CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO_STRUCT, *P_CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO_STRUCT;

typedef struct
{
    kal_uint8 CurrentShotNumber;            /* current image no (start from 1) */
    MM_IMAGE_FORMAT_ENUM SrcImgFormat ;	    /* src image color format */    
    kal_uint8 StitchDirection;              /* stitch direction */
    kal_uint16 ImageWidth;                  /* src image width */
    kal_uint16 ImageHeight;                 /* src image width */
    kal_uint32 ImageBufferAddr;             /* src image buffer addr */
    kal_uint32 ImageBufferSize;             /* src image buffer size */
    kal_uint32 ExtmemStartAddr;             /* external memory start address for postproc buffer cachable */
    kal_uint32 ExtmemSize;                  /* external memory size for postproc buffer cachable */
} CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT, *P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT;

/* for camera engineer mode */

// for CAL_FEATURE_CAM_ENGINEER_SET_RAW_BIT
typedef enum
{
    CAM_EM_RAW_8_BIT=0,
    CAM_EM_RAW_10_BIT
} CAL_FEATURE_CAM_ENGINEER_SET_RAW_BIT_ENUM;

// for CAL_FEATURE_CAM_ENGINEER_SET_EM
typedef enum
{
    CAM_AF_EM_FULL_SCAN_FORW1=0,  // 0
    CAM_AF_EM_FULL_SCAN_FORW4,    // 1
    CAM_AF_EM_FULL_SCAN_BACK1,    // 2
    CAM_AF_EM_FULL_SCAN_BACK4,    // 3
    CAM_AF_EM_CONT_FOCUS_SHOT,    // 4
    CAM_AF_EM_BEST_BRACKET_SHOT,  // 5
    CAM_AF_EM_CONT_FORWARD_LOG,   // 6
    CAM_AF_EM_CONT_BACKWARD_LOG,  // 7
    CAM_AF_EM_SINGLE_FORWARD_LOG, // 8
    CAM_AE_EM_FULL_SCAN,
    CAM_AE_EM_BEST_BRACKET_SCAN,
    CAM_AWB_EM_SEQ_PREVIEW_LOG_SAVE,
    CAM_AAA_EM_OFF,
    CAM_AAA_EM_NO
} CAL_CAM_ENGINEER_MODE_ENUM;

// for CAL_FEATURE_CAM_ENGINEER_SET_EM
typedef struct
{
    CAL_CAM_ENGINEER_MODE_ENUM CamEmMode;
} CAL_FEATURE_CAM_ENGINEER_SET_EM_IN_STRUCT, *P_CAL_FEATURE_CAM_ENGINEER_SET_EM_IN_STRUCT;

// for CAL_FEATURE_CAM_ENGINEER_SET_EM
typedef struct
{
    kal_uint32  SnapshotNum; 
    kal_bool    AfEnable;
    kal_bool    PreLogEnable;
} CAL_FEATURE_CAM_ENGINEER_SET_EM_OUT_STRUCT, *P_CAL_FEATURE_CAM_ENGINEER_SET_EM_OUT_STRUCT;

// for CAL_FEATURE_CAM_ENGINEER_GET_RAW_INFO
typedef struct
{
    kal_uint32 RawBufAddr;
    kal_uint32 RawBufSize;
    kal_uint32 RawWidth;
    kal_uint32 RawHeight;
} CAL_FEATURE_CAM_ENGINEER_GET_RAW_INFO_STRUCT, *P_CAL_FEATURE_CAM_ENGINEER_GET_RAW_INFO_STRUCT;
/* end of camera engineer mode */

typedef struct
{
    kal_uint16 QuickviewRoiX;               /* Quickview ROI start X */
    kal_uint16 QuickviewRoiY;               /* Quickview ROI start Y */
    kal_uint16 QuickviewRoiWidth;           /* Quickview ROI width */
    kal_uint16 QuickviewRoiHeight;          /* Quickview ROI height */
	kal_bool IsJaiaQviBufAligned;           /* If QVI buffer align to center */
} CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT, *P_CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT;

typedef union
{
    P_CAL_FEATURE_CAMERA_BINNING_INFO_STRUCT pBinningInfo;      // CAL_FEATURE_CAMERA_BINNING_INFO
    P_CAL_CAMERA_FAST_ZOOM_STRUCT pCamFastZoom;                 // CAL_FEATURE_CAMERA_FAST_ZOOM
    P_CAL_CAMERA_DIGITAL_ZOOM_IN_STRUCT pCamDzInPara;           // input of CAL_FEATURE_CAMERA_DIGITAL_ZOOM
    P_CAL_CAMERA_DIGITAL_ZOOM_OUT_STRUCT pCamDzOutPara;         // output of CAL_FEATURE_CAMERA_DIGITAL_ZOOM
    P_CAL_CAMERA_GET_BSS_RESULT_IN_STRUCT pCamGetBssInPara;    //input of CAL_FEATURE_CAMERA_GET_BSS_RESULT
    P_CAL_CAMERA_GET_BSS_RESULT_OUT_STRUCT pCamGetBssOutPara; //output of CAL_FEATURE_CAMERA_GET_BSS_RESULT
    P_CAL_CAMERA_GET_AF_ZONE_STRUCT pCamGetAfZoneOutPara;  //output of CAL_FEATURE_CAMERA_GET_AF_ZONE
    P_CAL_CAMERA_GET_PREVIEW_IMAGE_STRUCT pCamGetPreviewImageInPara; // input of CAL_FEATURE_CAMERA_GET_PREVIEW_IMAGE
    P_CAL_CAMERA_GET_JPEG_SIZE_ESTIMATION_STRUCT pGetJpegSizeEstimationPara; // input of CAL_FEATURE_CAMERA_GET_JPEG_SIZE_ESTIMATION
    P_CAL_CAMERA_CAPTURE_OVERLAY_CAPABILITY_OUT_STRUCT pCamOverlayCap;  // out of CAL_FEATUER_CAMERA_CAPTURE_OVERLAY_CAPABILITY
    P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_IN_STRUCT pCamSwRotInPara;     // input of CAL_FEATURE_CAMERA_QUERY_SW_ROTATE
    P_CAL_FEATURE_CAMERA_QUERY_SW_ROTATE_OUT_STRUCT pCamSwRotOutPara;   // output of CAL_FEATURE_CAMERA_QUERY_SW_ROTATE
    /* web camera start */
    P_CAL_FEATURE_WEBCAM_GET_ATTR_INFO_STRUCT pWebCamAttrInfo;  // CAL_FEATURE_WEBCAM_GET_ATTR_INFO
    P_CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE_STRUCT pWebCamVideoSize;// CAL_FEATURE_WEBCAM_GET_VIDEO_SIZE
    P_CAL_FEATURE_WEBCAM_GET_STILL_SIZE_STRUCT pWebCamStillSize;// CAL_FEATURE_WEBCAM_GET_STILL_SIZE
    P_CAL_FEATURE_WEBCAM_GET_COMPRESSION_STRUCT pWebCamCompression; // CAL_FEATURE_WEBCAM_GET_COMPRESSION
    P_CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX_STRUCT pWebCamDeafultIdx;  // CAL_FEATURE_WEBCAM_GET_DEFAULT_IDX
    P_CAL_FEATURE_WEBCAM_ATTR_STRUCT pWebCamAttr;                   // CAL_FEATURE_WEBCAM_GET_ATTR and CAL_FEATURE_WEBCAM_SET_ATTR
    /* camera profiling start*/
    P_CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT_STRUCT pCamPrrofilingLogPara;
    P_CAL_FEATURE_CAMERA_PROFILING_GET_RESULT_STRUCT pCamProfilingGetResultStruct;
    P_CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO_STRUCT pCamProfilingGetAppendInfoStruct;

	P_CAL_FEATURE_CAMERA_PANO_ADD_IMAGE_STRUCT pPanoAddImgPara;
	P_CAL_FEATURE_CAMERA_PANO_ENCODE_STRUCT pPanoEncodePara;
    //
    P_CAL_CCT_FEATURE_CTRL_STRUCT pCctInOutPara;                //input/output of CAL_CCT_FEATURE_CTRL

    void *pCapBuff;     // temp for camera capability query re-route UT
    /* web camera end */

    /* engineer mode */
    P_CAL_FEATURE_CAM_ENGINEER_SET_EM_IN_STRUCT pCamEmSetEmInPara;
    P_CAL_FEATURE_CAM_ENGINEER_SET_EM_OUT_STRUCT pCamEmSetEmOutPara;
    P_CAL_FEATURE_CAM_ENGINEER_GET_RAW_INFO_STRUCT pCamEmGetRawInfo;
    /* engineer mode end */
    
} CAL_FEATURE_TYPE_STRUCTURED_UNION, *P_CAL_FEATURE_TYPE_STRUCTURED_UNION;

// for CAL_CAMERA_PROFILING_FEATURE
typedef enum
{
    CAL_FEATURE_CAMERA_PROFILING_BEGIN = CAL_CAMERA_PROFILING_FEATURE_BEGIN,
    CAL_FEATURE_CAMERA_PROFILING_LOG_EVENT,
    CAL_FEATURE_CAMERA_PROFILING_GET_RESULT,
    CAL_FEATURE_CAMERA_PROFILING_GET_APPEND_INFO,
    CAL_FEATURE_CAMERA_PROFILING_END,
} CAL_CAMERA_PROFILING_FEATURE_ENUM;
////////////////////////////////////

typedef enum
{
    CAL_FEATURE_SET_OPERATION=0,
    CAL_FEATURE_GET_OPERATION,
    CAL_FEATURE_QUERY_OPERATION,
    CAL_FEATURE_CCT_OPERATION,
    CAL_FEATURE_OPERATION_MAX
} CAL_FEATURE_OPERATION_ENUM;

typedef enum
{
    CAL_FEATURE_TYPE_STRUCTURED=0,
    CAL_FEATURE_TYPE_ENUMERATE,
    CAL_FEATURE_TYPE_COMMAND,               /* FeatureId is enough, set only and no parameter is required */
    CAL_FEATURE_TYPE_MAX
} CAL_FEATURE_TYPE_ENUM;

#define MAX_CAMERA_SUPPORT_ITEM_COUNT 20

typedef struct
{
    kal_bool IsSupport;                 /* Is this camera function supportable ? */
    kal_uint16 ItemCount;               /* the number of the workable item*/
    kal_uint16 SupportItem[MAX_CAMERA_SUPPORT_ITEM_COUNT];   /* the enum of workable item */
    void * SupportItemInfo;   /* the enum of workable item info */
} CAL_FEATURE_TYPE_ENUM_STRUCT, *P_CAL_FEATURE_TYPE_ENUM_STRUCT;

typedef union
{
    CAL_FEATURE_TYPE_STRUCTURED_UNION FeatureStructured;
    CAL_FEATURE_TYPE_ENUM_STRUCT FeatureEnum;
} CAL_FEATURE_TYPE_UNION, *P_CAL_FEATURE_TYPE_UNION;

/* end of Camera Feature control interface */

// data structure for call back function in MED and CAL
// for CAL_CBID_WEBCAM_GET_VIDEO_BUFF,
//     CAL_CBID_WEBCAM_COMPLETE_VIDEO_BUFF
//     CAL_CBID_WEBCAM_GET_STILL_BUFF,
//     CAL_CBID_WEBCAM_COMPLETE_STILL_BUFF
typedef struct
{
    kal_uint32 BuffAddr;
    kal_uint32 BuffSize;
    kal_uint32 VideoTime;
    USBVIDEO_VIDEO_SIZE_TYPE VideoType;
} CAL_WEBCAM_CB_STRUCT, *P_CAL_WEBCAM_CB_STRUCT;

// for CAL_CBID_QUICK_VIEW_IMAGE_READY,
//     CAL_CBID_THUMBNAIL_IMAGE_READY,
//     CAL_CBID_VIDEO_IMAGE_READY,
//     CAL_CBID_STILL_IMAGE_READY
typedef struct
{
    MM_IMAGE_FORMAT_ENUM ImageBuffFormat;
    MM_IMAGE_ROTATE_ENUM ImageRotateAngle;
    MM_ERROR_CODE_ENUM ErrorStatus;
    kal_uint32 ImageBuffAddr;       // for RGBXXX/JPEG and other formates
    kal_uint32 ImageBuffSize;       // for RGBXXX/JPEG and other formates
    kal_uint32 ImageBuffYAddr;      // for YUV plain format
    kal_uint32 ImageBuffYSize;      // for YUV plain format
    kal_uint32 ImageBuffUAddr;      // for YUV plain format
    kal_uint32 ImageBuffUSize;      // for YUV plain format
    kal_uint32 ImageBuffVAddr;      // for YUV plain format
    kal_uint32 ImageBuffVSize;      // for YUV plain format
    kal_uint32 NextFrameBufferAddr; // address point to next frame buffer address
    kal_bool IsVideoImageBuffRotReady; // to notify MPL if the video image buffer is ready for encoding.
    kal_bool EnableReleaseWriteBuffer; // to enable release MDP write buffer function.
    kal_bool EnableAcquireWriteBuffer; // to enable acuire MDP write buffer function.
} CAL_BUFFER_CB_STRUCT, *P_CAL_BUFFER_CB_STRUCT;

typedef struct
{
    P_CAL_BUFFER_CB_STRUCT pCalBufferCB;
	kal_uint16 PanoStartX;
	kal_uint16 PanoStartY;
	kal_uint16 PanoWidth;
	kal_uint16 PanoHeight;
} CAL_BUFFER_CB_STRUCT_AUTORAMA, *P_CAL_BUFFER_CB_STRUCT_AUTORAMA;

typedef struct
{
    MM_ERROR_CODE_ENUM ErrorStatus;
    kal_uint32 ImageBuffAddr;
    kal_uint32 ImageBuffSize;
    kal_uint16 ImgWidth;
    kal_uint16 ImgHeight;
} CAL_PANO_RESULT_STRUCT, *P_CAL_PANO_RESULT_STRUCT;

typedef struct
{
    MM_ERROR_CODE_ENUM ErrorStatus;
    MM_IMAGE_FORMAT_ENUM ImageBuffFormat;
    kal_uint32 ImageBuffAddr;
    kal_uint32 ImageBuffSize;
} CAL_HDR_RESULT_STRUCT, *P_CAL_HDR_RESULT_STRUCT;

/* MAV Motion result */
typedef struct
{
    kal_uint16 CurrentImageNumber;
    kal_uint16 TotalImageNumber;
} CAL_MAV_CAP_RESULT_STRUCT, *P_CAL_MAV_CAP_RESULT_STRUCT;

/* MAV Stitch result */
typedef struct
{
    MM_ERROR_CODE_ENUM ErrorStatus;
    kal_uint32 EncodeDstBufferAddr;
    kal_uint32 EncodeDstBufferSize;
} CAL_MAV_RESULT_STRUCT, *P_CAL_MAV_RESULT_STRUCT;


typedef union
{
    CAL_HDR_RESULT_STRUCT  HdrResult;        // same type with still capture cb
    CAL_PANO_RESULT_STRUCT  PanoResult;

} CAL_POSTPROC_CB_UNION, *P_CAL_POSTPROC_CB_UNION;

// for CAL_CBID_AF_RESULT,
typedef enum
{
    AF_SEARCH_STATUS_IDLE=0,
    AF_SEARCH_STATUS_BUSY	,
    AF_SEARCH_STATUS_FOUND_FAIL,
    AF_SEARCH_STATUS_FOUND_SUCCESS,
    AF_SEARCH_STATUS_FOUND_NOFOCUS,
    AF_SEARCH_STATUS_SWITCH_MACRO
} CAL_AF_SEARCH_STATUS_ENUM;

typedef struct
{
    CAL_CALLBACK_ID_ENUM CbId;
    CAL_AF_SEARCH_STATUS_ENUM AfSearchResult;
    kal_uint32	AfSearchNum;
    kal_uint32	AfSearchBest;
    kal_uint32	AfSuccessZone;
    kal_uint32	AfSearchPower;
} CAL_CAMERA_AF_RESULT_STRUCT, *P_CAL_CAMERA_AF_RESULT_STRUCT;

#define IMAGE_PALETTE_MODE_ENUM img_palette_mode_enum_t
#endif /* __CAL_COMM_DEF_H__ */
