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
 *    drv_sw_features_g2d.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all graphics driver feature options.
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
 * 06 05 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 05 17 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 04 27 2012 hung-wen.hsieh
 * removed!
 * .MT6276/MT6255/MT6250 Linear Transform always uses hw g2d..
 *
 * 04 24 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 03 23 2012 hung-wen.hsieh
 * removed!
 * .
 *
 * 01 06 2011 violet.wang
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_SW_FEATURES_G2D_H__
#define __DRV_SW_FEATURES_G2D_H__

#include "drv_features_g2d.h"

///G2D
#if defined(G2D_HW_SUPPORT)
   #define __HW_G2D_SUPPORT__  
#endif

#if defined(G2D_HW_LT_SUPPORT)
   #define __HW_G2D_LT_SUPPORT__  
#endif

#if defined(G2D_HW_RECT_FILL_SUPPORT)
   #define __HW_G2D_RECT_FILL_SUPPORT__

   #define G2D_LAYER_MIN_WIDTH                  (0x1)
   #define G2D_LAYER_MIN_HEIGHT                 (0x1)
   #define G2D_LAYER_MAX_WIDTH                  (0x7FF)
   #define G2D_LAYER_MAX_HEIGHT                 (0x7FF)

   #define G2D_LAYER_MIN_OFFSETX                (0x0)
   #define G2D_LAYER_MIN_OFFSETY                (0x0)
   #define G2D_LAYER_MAX_OFFSETX                (0x7FF)
   #define G2D_LAYER_MAX_OFFSETY                (0x7FF)
#endif

#if defined(G2D_HW_LT_ONLY)
   #define __HW_G2D_LT_ONLY__
#endif

#if defined(G2D_HW_AA_FONT_SUPPORT)
   #define __HW_G2D_AA_FONT_SUPPORT__  
#endif

#if defined(G2D_HW_TILT_FONT_SUPPORT)
   #define __HW_G2D_TILT_FONT_SUPPORT__  
#endif

#if defined(G2D_HW_DITHERING_SUPPORT)
   #define __HW_G2D_DITHERING_SUPPORT__  
#endif


#endif /// __DRV_SW_FEATURES_G2D_H__ 
