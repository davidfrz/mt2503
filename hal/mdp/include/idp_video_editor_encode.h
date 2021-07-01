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
 *
 * Project:
 * --------
 *	 Maui
 *
 * Description:
 * ------------
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 17 2010 cm.huang
 * removed!
 * .
 *
 * 11 23 2010 cm.huang
 * removed!
 * .
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
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __idp_video_editor_encode_h__
#define __idp_video_editor_encode_h__

#include "kal_general_types.h"
#include <idp_core.h>

enum
{
  IDP_VIDEO_EDITOR_ENCODE_INTMEM_START_ADDRESS = 1,
  IDP_VIDEO_EDITOR_ENCODE_INTMEM_SIZE,
  IDP_VIDEO_EDITOR_ENCODE_EXTMEM_START_ADDRESS,
  IDP_VIDEO_EDITOR_ENCODE_EXTMEM_SIZE,
  
  IDP_VIDEO_EDITOR_ENCODE_VIDEO_SRC_WIDTH,
  IDP_VIDEO_EDITOR_ENCODE_VIDEO_SRC_HEIGHT,
  
  IDP_VIDEO_EDITOR_ENCODE_TARGET_VIDEO_Y_BUFFER_ADDRESS,
  IDP_VIDEO_EDITOR_ENCODE_TARGET_VIDEO_U_BUFFER_ADDRESS,
  IDP_VIDEO_EDITOR_ENCODE_TARGET_VIDEO_V_BUFFER_ADDRESS,
  
  IDP_VIDEO_EDITOR_ENCODE_LCD_BUFFER_ADDRESS,
  
  IDP_VIDEO_EDITOR_ENCODE_ENCODE_DONE_CB,
  IDP_VIDEO_EDITOR_ENCODE_ENCODE_DONE_CB_PARAM,
  
  IDP_VIDEO_EDITOR_ENCODE_LAST_USER_CONFIG
};

extern kal_bool idp_video_editor_encode_open_real(             
  kal_uint32 * const key,                           
  char const * const filename,                      
  kal_uint32 const lineno);                         

extern kal_bool idp_video_editor_encode_close(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_stop(                 
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_start_intermedia_pipe( 
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_start_input(           
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_start_output(          
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_start_all(             
  kal_uint32 const key);                            

extern kal_bool idp_video_editor_encode_config(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_editor_encode_configurable(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_editor_encode_config_fast(
  kal_uint32 const key,
  kal_uint32 const para_type,
  kal_uint32 const para_value);

extern kal_bool idp_video_editor_encode_query(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_editor_encode_config_and_start(
  kal_uint32 const key,
  ...);

extern kal_bool idp_video_editor_encode_is_busy(               
  kal_uint32 const key,                             
  kal_bool * const busy);

extern kal_bool idp_video_editor_encode_is_in_use(void);

#define idp_video_editor_encode_open(key) idp_video_editor_encode_open_real(key, __FILE__, __LINE__)

#endif
