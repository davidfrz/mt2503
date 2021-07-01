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
 *    video_muxer_mem_req_v2.h
 *
 * Project:
 * --------
 *    MAUI
 *
 * Description:
 * ------------
 *    The required memory size of video muxer
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
 *
 *
 *
 ****************************************************************************/
#ifndef __VIDEO_MUXER_MEM_REQ_V2_H__
#define __VIDEO_MUXER_MEM_REQ_V2_H__

#if defined(__VIDEO_ARCHI_V2__)
#include "cache_sw.h"

#define FILE_NAME_PATH_SIZE     (261 * 2)
#define FILE_WORKING_PATH_SIZE  (261 * 2)

#define MUXER_COMMAND_Q_NUM         (5)
#define MUXER_COMMAND_Q_BUFFER_SIZE (8)

#define MUXER_AUDIO_INPUT_BUFFER_Q_NUM          (3)
#define MUXER_VIDEO_INPUT_BUFFER_Q_NUM          (30)
#define MUXER_INPUT_BUFFER_Q_BUFFER_SIZE        (32)

#define MUXER_VIDEO_RESENT_Q_NUMBER (32)
#define MUXER_AUDIO_RESENT_Q_NUMBER (6)
#define MUXER_RESENT_Q_SIZE  (64)

#define MUXER_COMP_BUFFER_SIZE  ((MUXER_COMMAND_Q_NUM + CPU_CACHE_LINE_SIZE)*MUXER_COMMAND_Q_BUFFER_SIZE +          \
                                 (MUXER_AUDIO_INPUT_BUFFER_Q_NUM + CPU_CACHE_LINE_SIZE)*MUXER_INPUT_BUFFER_Q_BUFFER_SIZE + \
                                 (MUXER_VIDEO_INPUT_BUFFER_Q_NUM + CPU_CACHE_LINE_SIZE)*MUXER_INPUT_BUFFER_Q_BUFFER_SIZE + \
                                 (MUXER_VIDEO_RESENT_Q_NUMBER + MUXER_AUDIO_RESENT_Q_NUMBER) * MUXER_RESENT_Q_SIZE) +   \
                                 (FILE_NAME_PATH_SIZE + CPU_CACHE_LINE_SIZE)     +   \
                                 (FILE_WORKING_PATH_SIZE + CPU_CACHE_LINE_SIZE)

#define MUXER_COMP_MEM_SIZE  (MUXER_COMP_BUFFER_SIZE)

#endif  //__VIDEO_ARCHI_V2__
#endif  //  __VIDEO_MUXER_MEM_REQ_V2_H__

