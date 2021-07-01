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
 *   mtv_custom.h
 *
 * Project:
 * --------
 *   MAUI
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MTV_CUSTOM_H
#define _MTV_CUSTOM_H

/* service manager */

/**
  * The maximum lenght of TV service name
  */
#if defined(__ATV_SUPPORT__)
        #define MTV_MAX_SERVICE_NAME            41

    #if defined(__ATV_SLIM_VERSION__)
        #define MTV_MAX_SERVICE_NUM             30
    #else
        #define MTV_MAX_SERVICE_NUM             50
    #endif
#else
    #define MTV_MAX_SERVICE_NAME            64
    #define MTV_MAX_SERVICE_NUM             50
#endif

/* buffer engine */

/**
  * The interval to save recording checkpoint. The number is counted
  * in packet number.
  */
#define MTV_SAVE_CHECKPOINT_INTERVAL    512

/**
  * The minimum requirement of storage space in bytes to start time-shifting operations.
  */
#define MIN_SAMPLE_STREAM_SIZE          (128*1024)

/**
  * The filename prefix for sample stream.
  */
#define AV_STREAM_PREFIX                L"~avstm"

/**
  * The filename prefix for audio sample index.
  */
#define AUDIO_INDEX_PREFIX              L"~audidx"

/**
  * The filename prefix for video sample index.
  */
#define VIDEO_INDEX_PREFIX              L"~vididx"

/* recorder */

/**
  * The maximum size of a recording. It should be less than 2G-1.
  */
#define MAX_RECORDING_SIZE              (2*1024*1024 - 1)

/**
  * Minimum duration in seconds for time-shifting to work.
  */
#define MTV_MIN_DURATION_FOR_TIMESHIFT  30

/**
  * The cache block size for file I/O. Note that this value cannot be set
  * arbitrarily without considering available MED EXTMEM and the buffer waiting
  * delay of asynchronous I/O.
  */
#define MTV_CACHE_BLOCK_SIZE            (4*1024)

/* T-DMB SP */

/**
  * The maximum number of concurrently started T-DMB service. This value should be
  * the same as the limitation from tuner host library.
  */
#define MTV_MAX_TDMB_SERVICES           3

/**
  * The maximum number of service components in a mobile TV service.
  */
#ifdef __ATV_SUPPORT__
#define MAX_SPI_SERVICE_COMPONENTS      2
#else
#define MAX_SPI_SERVICE_COMPONENTS      4
#endif

/**
  * The maximum number of services that can be started simultanesouly
  */
#define MTV_MAX_MULTIPLE_SERVICES       2

/**
  * The maximum number of T-DMB components in a T-DMB service. If received service has
  * more components than the limit, the extra components will not be recognized.
  */
#define MTV_MAX_TDMB_STREAMS            MAX_SPI_SERVICE_COMPONENTS

/**
  * The maximum external memory that T-DMB demux can use.
  */
#define MTV_TDMB_DEMUX_BUF_SIZE     (128*1024)

/**
  * The maximum external memory that T-DMB host lib will use for packet buffer.
  */
#define MAX_TDMB_BUFFER_SIZE        (512*1024)

/**
  * The maximum external memory of T-DMB middleware will use.
  */
#if defined(__CMMB_SUPPORT__)

    #if defined(__CMMB_CAS_MBBMS_SUPPORT__)
        #define MED_MTV_ESG_MEMORY  (700)    //SG&ESG may be open concurrency when set APN in CMMB setting
    #else
        #define MED_MTV_ESG_MEMORY  (342)
    #endif

    #if defined(__CMMB_DS_SUPPORT__)
        #define MED_MTV_SP_MEMORY       (512 + 2 * 1024)
    #else
        #define MED_MTV_SP_MEMORY       (512)
    #endif

    #define MED_MTV_PLAYER_MEMORY    32

    #define MAX_MED_MTV_ESG_MEMORY      ((MED_MTV_ESG_MEMORY) * 1024 + 512)    // add ADM overhead
                                                      /* PLAYER + SP + CMMB_ESG + MBBMS_ESG */
    #define MAX_MED_MTV_MEMORY          ((MED_MTV_SP_MEMORY + MED_MTV_ESG_MEMORY)*1024 + 512)

#elif defined(__ATV_SUPPORT__)
    #define MED_MTV_CORE_MEMORY (64*1024)
    //#define MED_MTV_VIDEO_MEMORY (LCD_WIDTH * LCD_HEIGHT * 2)    // player preview buffer memory
    #define MAX_MED_MTV_MEMORY          (MED_MTV_CORE_MEMORY)
#else
    #define MAX_MED_MTV_MEMORY          (1024*1024)
#endif

/**
  * The maximum duration in seconds of audio concealment.
  */
#define MTV_AUDIO_CONCEALMENT_THRESHOLD 4

/**
  * The maximum allowed audio/video offset in seconds.
  */
#define MTV_MAX_ALLOWED_AV_OFFSET       10

#endif /* _MTV_CUSTOM_H */
