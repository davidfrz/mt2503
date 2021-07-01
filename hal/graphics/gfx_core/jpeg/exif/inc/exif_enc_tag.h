/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   exif_enc_tag.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   
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
 *============================================================================
 ****************************************************************************/
#ifndef __EXIF_ENC_TAG_V2_H__
#define __EXIF_ENC_TAG_V2_H__

#include "exif_enc_enum.h"
 

typedef enum
{
    EXIF_TAG_NULL                           = 0xffff,
    EXIF_TAG_INTEROPERABILITY_INDEX         = 0x0001,//
    EXIF_TAG_INTEROPERABILITY_VERSION       = 0x0002,
    EXIF_TAG_NEW_SUBFILE_TYPE               = 0x00fe,
    EXIF_TAG_IMAGE_WIDTH                    = 0x0100,//
    EXIF_TAG_IMAGE_LENGTH                   = 0x0101,//
    EXIF_TAG_BITS_PER_SAMPLE                = 0x0102,//
    EXIF_TAG_COMPRESSION                    = 0x0103,//
    EXIF_TAG_PHOTOMETRIC_INTERPRETATION     = 0x0106,//
    EXIF_TAG_FILL_ORDER                     = 0x010a,
    EXIF_TAG_DOCUMENT_NAME                  = 0x010d,
    EXIF_TAG_IMAGE_DESCRIPTION              = 0x010e,//
    EXIF_TAG_MAKE                           = 0x010f,//
    EXIF_TAG_MODEL                          = 0x0110,//
    EXIF_TAG_STRIP_OFFSETS                  = 0x0111,// Not record in JPEG.
    EXIF_TAG_ORIENTATION                    = 0x0112,//
    EXIF_TAG_SAMPLES_PER_PIXEL              = 0x0115,//
    EXIF_TAG_ROWS_PER_STRIP                 = 0x0116,// Not record in JPEG.
    EXIF_TAG_STRIP_BYTE_COUNTS              = 0x0117,// Not record in JPEG.
    EXIF_TAG_X_RESOLUTION                   = 0x011a,//
    EXIF_TAG_Y_RESOLUTION                   = 0x011b,//
    EXIF_TAG_PLANAR_CONFIGURATION           = 0x011c,//
    EXIF_TAG_RESOLUTION_UNIT                = 0x0128,//
    EXIF_TAG_TRANSFER_FUNCTION              = 0x012d,// Not finish yet.
    EXIF_TAG_SOFTWARE                       = 0x0131,//
    EXIF_TAG_DATE_TIME                      = 0x0132,//
    EXIF_TAG_ARTIST                         = 0x013b,//
    EXIF_TAG_WHITE_POINT                    = 0x013e,//
    EXIF_TAG_PRIMARY_CHROMATICITIES         = 0x013f,//
    EXIF_TAG_SUB_IFDS                       = 0x014a,
    EXIF_TAG_TRANSFER_RANGE                 = 0x0156,
    EXIF_TAG_JPEG_PROC                      = 0x0200,
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT        = 0x0201,//
    EXIF_TAG_JPEG_INTERCHANGE_FORMAT_LENGTH = 0x0202,//
    EXIF_TAG_YCBCR_COEFFICIENTS             = 0x0211,//
    EXIF_TAG_YCBCR_SUB_SAMPLING             = 0x0212,//
    EXIF_TAG_YCBCR_POSITIONING              = 0x0213,//
    EXIF_TAG_REFERENCE_BLACK_WHITE          = 0x0214,//
    EXIF_TAG_XML_PACKET                     = 0x02bc,
    EXIF_TAG_RELATED_IMAGE_FILE_FORMAT      = 0x1000,
    EXIF_TAG_RELATED_IMAGE_WIDTH            = 0x1001,
    EXIF_TAG_RELATED_IMAGE_LENGTH           = 0x1002,
    EXIF_TAG_CFA_REPEAT_PATTERN_DIM         = 0x828d,
    EXIF_TAG_CFA_PATTERN                    = 0x828e,
    EXIF_TAG_BATTERY_LEVEL                  = 0x828f,
    EXIF_TAG_COPYRIGHT                      = 0x8298,//
    EXIF_TAG_EXPOSURE_TIME                  = 0x829a,//
    EXIF_TAG_FNUMBER                        = 0x829d,//
    EXIF_TAG_IPTC_NAA                       = 0x83bb,
    EXIF_TAG_IMAGE_RESOURCES                = 0x8649,//
    EXIF_TAG_EXIF_IFD_POINTER               = 0x8769,//
    EXIF_TAG_INTER_COLOR_PROFILE            = 0x8773,
    EXIF_TAG_EXPOSURE_PROGRAM               = 0x8822,//
    EXIF_TAG_SPECTRAL_SENSITIVITY           = 0x8824,//
    EXIF_TAG_GPS_INFO_IFD_POINTER           = 0x8825,//
    EXIF_TAG_ISO_SPEED_RATINGS              = 0x8827,//
    EXIF_TAG_OECF                           = 0x8828,//
    EXIF_TAG_TIME_ZONE_OFFSET               = 0x882a,
    EXIF_TAG_EXIF_VERSION                   = 0x9000,//
    EXIF_TAG_DATE_TIME_ORIGINAL             = 0x9003,//
    EXIF_TAG_DATE_TIME_DIGITIZED            = 0x9004,//
    EXIF_TAG_COMPONENTS_CONFIGURATION       = 0x9101,//
    EXIF_TAG_COMPRESSED_BITS_PER_PIXEL      = 0x9102,//
    EXIF_TAG_SHUTTER_SPEED_VALUE            = 0x9201,//
    EXIF_TAG_APERTURE_VALUE                 = 0x9202,//
    EXIF_TAG_BRIGHTNESS_VALUE               = 0x9203,//
    EXIF_TAG_EXPOSURE_BIAS_VALUE            = 0x9204,//
    EXIF_TAG_MAX_APERTURE_VALUE             = 0x9205,//
    EXIF_TAG_SUBJECT_DISTANCE               = 0x9206,//
    EXIF_TAG_METERING_MODE                  = 0x9207,//
    EXIF_TAG_LIGHT_SOURCE                   = 0x9208,//
    EXIF_TAG_FLASH                          = 0x9209,//
    EXIF_TAG_FOCAL_LENGTH                   = 0x920a,//
    EXIF_TAG_SUBJECT_AREA                   = 0x9214,
    EXIF_TAG_TIFF_EP_STANDARD_ID            = 0x9216,
    EXIF_TAG_MAKER_NOTE                     = 0x927c,//
    EXIF_TAG_USER_COMMENT                   = 0x9286,//
    EXIF_TAG_SUB_SEC_TIME                   = 0x9290,//
    EXIF_TAG_SUB_SEC_TIME_ORIGINAL          = 0x9291,//
    EXIF_TAG_SUB_SEC_TIME_DIGITIZED         = 0x9292,//
    EXIF_TAG_XP_TITLE                       = 0x9c9b,
    EXIF_TAG_XP_COMMENT                     = 0x9c9c,
    EXIF_TAG_XP_AUTHOR                      = 0x9c9d,
    EXIF_TAG_XP_KEYWORDS                    = 0x9c9e,
    EXIF_TAG_XP_SUBJECT                     = 0x9c9f,
    EXIF_TAG_FLASH_PIX_VERSION              = 0xa000,//
    EXIF_TAG_COLOR_SPACE                    = 0xa001,//
    EXIF_TAG_PIXEL_X_DIMENSION              = 0xa002,//
    EXIF_TAG_PIXEL_Y_DIMENSION              = 0xa003,//
    EXIF_TAG_RELATED_SOUND_FILE             = 0xa004,//
    EXIF_TAG_INTEROPERABILITY_IFD_POINTER   = 0xa005,//
    EXIF_TAG_FLASH_ENERGY                   = 0xa20b,//
    EXIF_TAG_SPATIAL_FREQUENCY_RESPONSE     = 0xa20c,//
    EXIF_TAG_FOCAL_PLANE_X_RESOLUTION       = 0xa20e,//
    EXIF_TAG_FOCAL_PLANE_Y_RESOLUTION       = 0xa20f,//
    EXIF_TAG_FOCAL_PLANE_RESOLUTION_UNIT    = 0xa210,//
    EXIF_TAG_SUBJECT_LOCATION               = 0xa214,//
    EXIF_TAG_EXPOSURE_INDEX                 = 0xa215,//
    EXIF_TAG_SENSING_METHOD                 = 0xa217,//
    EXIF_TAG_FILE_SOURCE                    = 0xa300,//
    EXIF_TAG_SCENE_TYPE                     = 0xa301,//
    EXIF_TAG_NEW_CFA_PATTERN                = 0xa302,//
    EXIF_TAG_CUSTOM_RENDERED                = 0xa401,//
    EXIF_TAG_EXPOSURE_MODE                  = 0xa402,//
    EXIF_TAG_WHITE_BALANCE                  = 0xa403,//
    EXIF_TAG_DIGITAL_ZOOM_RATIO             = 0xa404,//
    EXIF_TAG_FOCAL_LENGTH_IN_35MM_FILM      = 0xa405,//
    EXIF_TAG_SCENE_CAPTURE_TYPE             = 0xa406,//
    EXIF_TAG_GAIN_CONTROL                   = 0xa407,//
    EXIF_TAG_CONTRAST                       = 0xa408,//
    EXIF_TAG_SATURATION                     = 0xa409,//
    EXIF_TAG_SHARPNESS                      = 0xa40a,//
    EXIF_TAG_DEVICE_SETTING_DESCRIPTION     = 0xa40b,//
    EXIF_TAG_SUBJECT_DISTANCE_RANGE         = 0xa40c,//
    EXIF_TAG_IMAGE_UNIQUE_ID                = 0xa420,//
    EXIF_TAG_GAMMA                          = 0xa500,
    EXIF_TAG_PRINT_IMAGE_MATCHING           = 0xc4a5

} EXIF_TAG_ENUM;


typedef enum
{
    EXIF_TAG_GPS_VERSION_ID                 = 0x0000,
    EXIF_TAG_GPS_LATITUDE_REF               = 0x0001,       /// Overlap with INTEROPERABILITY_INDEX
    EXIF_TAG_GPS_LATITUDE                   = 0x0002,       /// Overlap with INTEROPERABILITY_VERSION
    EXIF_TAG_GPS_LONGITUDE_REF              = 0x0003,
    EXIF_TAG_GPS_LONGITUDE                  = 0x0004,
    EXIF_TAG_GPS_ALTITUDE_REF               = 0x0005,
    EXIF_TAG_GPS_ALTITUDE                   = 0x0006,
    EXIF_TAG_GPS_TIME_STAMP                 = 0x0007,
    EXIF_TAG_GPS_SATELLITES                 = 0x0008,
    EXIF_TAG_GPS_STATUS                     = 0x0009,
    EXIF_TAG_GPS_MEASURE_MODE               = 0x000a,
    EXIF_TAG_GPS_DOP                        = 0x000b,
    EXIF_TAG_GPS_SPEED_REF                  = 0x000c,
    EXIF_TAG_GPS_SPEED                      = 0x000d,
    EXIF_TAG_GPS_TRACK_REF                  = 0x000e,
    EXIF_TAG_GPS_TRACK                      = 0x000f,
    EXIF_TAG_GPS_IMG_DIRECTION_REF          = 0x0010,
    EXIF_TAG_GPS_IMG_DIRECTION              = 0x0011,
    EXIF_TAG_GPS_MAP_DATUM                  = 0x0012,
    EXIF_TAG_GPS_DEST_LATITUDE_REF          = 0x0013,
    EXIF_TAG_GPS_DEST_LATITUDE              = 0x0014,
    EXIF_TAG_GPS_DEST_LONGITUDE_REF         = 0x0015,
    EXIF_TAG_GPS_DEST_LONGITUDE             = 0x0016,
    EXIF_TAG_GPS_DEST_BEARING_REF           = 0x0017,
    EXIF_TAG_GPS_DEST_BEARING               = 0x0018,
    EXIF_TAG_GPS_DEST_DISTANCE_REF          = 0x0019,
    EXIF_TAG_GPS_DEST_DISTANCE              = 0x001a,
    EXIF_TAG_GPS_PROCESSING_METHOD          = 0x001b,
    EXIF_TAG_GPS_AREA_INFORMATION           = 0x001c,
    EXIF_TAG_GPS_DATE_STAMP                 = 0x001d,
    EXIF_TAG_GPS_DIFFERENTIAL               = 0x001e

} EXIF_TAG_GPS_ENUM;



unsigned char exif_format_get_size(EXIF_TAG_FORMAT_ENUM format);



#endif  // End of #ifndef __EXIF_ENC_TAG_V2_H__
