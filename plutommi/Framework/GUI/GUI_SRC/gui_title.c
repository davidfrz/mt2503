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
 * Filename:
 * ---------
 *  gui_title.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  title related funtions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
 * Include
 *****************************************************************************/

#include "MMI_features.h"
#include "MMIDataType.h"
#include "wgui.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"
#include "Wgui_title.h"
#include "gui_title.h"
#include "wgui_include.h"


/*****************************************************************************
 * Define
 *****************************************************************************/

#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


/*****************************************************************************
 * Typedef
 *****************************************************************************/

/*****************************************************************************
 * Variable
 *****************************************************************************/
UI_window_title_theme *current_window_title_theme = NULL;
UI_window_title_theme *current_thick_title_theme = NULL;
//U16 title_bg_id = 0;    /* added for customized title background image */



static MMI_BOOL g_gui_title_is_in_wap = MMI_FALSE;

#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

/*****************************************************************************
 * Local Function
 *****************************************************************************/

//S32 (*gui_title_show_normal) (gui_title_struct *, U32) = NULL;
//void (*gui_title_show_background) (gui_title_struct *, S32, S32, S32, S32) = NULL;
//void (*gui_title_measure)(gui_title_struct *t, U32 part, S32 *x1, S32 *x2, S32 *h) = NULL;

#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
void (*gui_title_show_status_icon)(gui_title_struct * t) = NULL;
#endif

#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
        #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
    #else /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
/* under construction !*/
    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


/*****************************************************************************
 * Local funciton
 *****************************************************************************/

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VUI_ENGINE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_VUI_ENGINE__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
                #endif
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
                #else
/* under construction !*/
                #endif
                #ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
                #else
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
            #else
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
    #else /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if(!TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !TITLE_TRANSITION_STYLE_NON_BLOCKING */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
            #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifndef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
        #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* TITLE_TRANSITION_WITH_PREVIOUS_TITLE_MOVEMENT */
/* under construction !*/
            #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #ifdef __MMI_VUI_ENGINE__
/* under construction !*/
            #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */
/* under construction !*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */


/*****************************************************************************
 * Extern Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  gui_title_show
 * DESCRIPTION
 *  draw title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  part        [IN]            Part ID of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_show(gui_title_struct *t, U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//    MMI_BOOL bitblt = MMI_TRUE;
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)     
    stFontAttribute title_font_attribute;
    UI_font_type title_font;
#endif /* __MMI_FTE_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__) 
    title_font = t->normal_font;
    title_font_attribute = *title_font;
    if (t->hide_callback)
    {
        title_font_attribute.smallCaps = 2;
    }
    t->normal_font = &title_font_attribute;
#endif /* __MMI_FTE_SUPPORT__ */

    if(part & GUI_TITLE_PART_TEXT)
    {
        t->show_text = MMI_TRUE;
    }
    t->has_title = MMI_TRUE;
#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

    return (MMI_BOOL)gui_title_show_normal(t, part);

#if 0//defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
/* under construction !*/
#endif /* __MMI_FTE_SUPPORT__ */
//    return bitblt;

}


#ifdef __MMI_SCREEN_SWITCH_EFFECT__
/*****************************************************************************
 * FUNCTION
 *  gui_title_get_text_info
 * DESCRIPTION
 *
 * PARAMETERS
 *  t       [IN/OUT]

 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_get_text_info(gui_title_struct *t, S32 *text_width, S32 *text_height, PU8 *text_content)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 area1_width = 0, area1_height = 0, area2_width = 0, area2_height = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_DBG_ASSERT(t != NULL);

    *text_content = t->text;
    *text_width = 0;
    *text_height = t->height;

    if (t->style & GUI_TITLE_STYLE_SCROLLING)   /*  */
    {

    }
    else
    {
        gui_title_measure_area1(t, &area1_width, &area1_height);
        gui_title_measure_area2(t, &area2_width, &area2_height);

        *text_width = t->width - area1_width - area2_width;
    }
}
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */


/*****************************************************************************
 * FUNCTION
 *  gui_title_move
 * DESCRIPTION
 *  move title
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  x       [IN]
 *  y       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_move(gui_title_struct *t, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_resize
 * DESCRIPTION
 *  resize title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  width       [IN]
 *  height      [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_resize(gui_title_struct *t, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->width = width;
    t->height = height;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_change
 * DESCRIPTION
 *  change title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  icon        [IN]            Left icon
 *  icon2       [IN]            Right icon
 *  text        [IN]            Text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_change_ex(
	gui_title_struct *t, 
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
	PU8 icon, 
	PU8 icon2, 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/	
	U8 *text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */
    if (text)
    {
        mmi_ucs2ncpy((S8*) t->text, (S8*) text, GUI_TITLE_MAX_LENGTH);
    }
    else
    {
        t->text[0] = 0;
        t->text[1] = 0;
    }
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
    t->icon = icon;
    t->icon2 = icon2;
#endif
    if (t->style & GUI_TITLE_STYLE_SCROLLING)
    {
        gui_scrolling_text_stop(&(t->scrolling_text));
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_create_ex
 * DESCRIPTION
 *  create title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  x                   [IN]            the x coordinate of title
 *  y                   [IN]            the y coordinate of title
 *  wdith               [IN]            the width of title
 *  height              [IN]            the height of title
 *  target_lcd          [IN]            Is the target of lcd title
 *  target_layer        [IN]            Is the target layer of title
 *  alpha_blend_layer   [IN]            Is the alpha blend layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_create_ex(
        gui_title_struct *t,
        S32 x,
        S32 y,
        S32 wdith,
        S32 height,
        gdi_handle target_lcd,
        gdi_handle target_layer,
        gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->x = x;
    t->y = y;
    t->width = wdith;
    t->height = height;
    t->target_lcd = target_lcd;
    t->target_layer = target_layer;
    t->alpha_blend_layer = alpha_blend_layer;
    t->hide_callback = NULL;
    t->style = GUI_TITLE_STYLE_NORMAL;
    t->has_title = MMI_FALSE;
    gui_title_set_current_theme(t);
   // gui_title_show_normal = gui_title_oem_show_normal;
  //  gui_title_show_background = gui_title_oem_show_background;
  //  gui_title_measure = gui_title_measure_oem;
	
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    gui_title_show_status_icon = gui_title_show_status_icon_oem;
#endif/*MMI_SHOW_STATUS_ICON_IN_TITLE*/

#ifdef __MMI_TITLE_BAR_NO_ICON_SHCT__
	    t->no_icon_shct = MMI_FALSE;
#else /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
	    t->no_icon_shct = MMI_TRUE;
#endif  /*__MMI_TITLE_BAR_NO_ICON_SHCT__*/


#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */

#if 0//def __MMI_UI_TITLE_MINI_INDICATOR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_MINI_INDICATOR__ */

    //huking
    g_current_title = t;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_create
 * DESCRIPTION
 *  create title
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  x           [IN]            the x coordinate of title
 *  y           [IN]            the y coordinate of title
 *  wdith       [IN]            the width of title
 *  height      [IN]            the height of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_create(
	gui_title_struct *t, 
	S32 x, 
	S32 y, 
	S32 width, 
	S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_create_ex(
    	t, 
    	x, 
    	y, 
    	width, 
    	height,
    	GDI_NULL_HANDLE, 
    	GDI_NULL_HANDLE, 
    	GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_style
 * DESCRIPTION
 *  set title style
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style | style;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_unset_style
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t           [IN/OUT]        Is the struct of title
 *  style       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_unset_style(gui_title_struct *t, U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->style = t->style & ~style;
    if (style == GUI_TITLE_STYLE_SCROLLING)
    {
        gui_scrolling_text_stop(&(t->scrolling_text));
    }
}

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
/*****************************************************************************
 * FUNCTION
 *  gui_title_set_no_icon_shct
 * DESCRIPTION
 *  set title style for show icon
 * PARAMETERS
 *  t                   [IN/OUT]        Is the struct of title
 *  no_icon_shct        [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_no_icon_shct(gui_title_struct *t, MMI_BOOL no_icon_shct)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->no_icon_shct = no_icon_shct;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_theme
 * DESCRIPTION
 *  set the specify theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 *  th      [IN]            Specify theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_theme(gui_title_struct *t, UI_window_title_theme *th)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SCREEN_ROTATE__
    if (mmi_frm_is_screen_width_height_swapped())
    {
        t->active_filler = current_MMI_theme->rotated_title_filler;
    }
    else
#endif/*__MMI_SCREEN_ROTATE__*/
//    {
        t->active_filler = th->active_filler;
//    }
    t->normal_font = th->text_font;
    t->active_font = th->text_font;
    t->text_color = th->active_text_color;
    t->text_border_color = th->text_border_color;
	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    t->sc.normal_text_color = th->shortcut_text_color;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_current_theme
 * DESCRIPTION
 *  set current theme
 * PARAMETERS
 *  t       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_current_theme(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_set_theme(t, current_window_title_theme);

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_register_callback
 * DESCRIPTION
 *  register the callback function of pre_goto and goto
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  pre_goto_funcptr        [IN]
 *  goto_funcptr            [IN]
 *  flag                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_register_callback(
        gui_title_struct *t,
        void (*pre_goto_funcptr) (S32 i),
        void (*goto_funcptr) (S32 i),
        U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_PRE_GOTO)
    {
        t->pre_goto_callback = pre_goto_funcptr;
    }
    if (flag & WGUI_TITLE_SHORTCUT_CHANGE_GOTO)
    {
        t->goto_callback = goto_funcptr;
    }

}


void gui_title_register_hide_callback(
        gui_title_struct *t,
        void (*hide_callback)(S32 x, S32 y, S32 w, S32 h))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (hide_callback != NULL)
    {
        t->hide_callback = hide_callback;
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_hide_callback
 * DESCRIPTION
 *  reset the hide callback function of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_hide_callback(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->hide_callback = NULL;
}

/*****************************************************************************
 * FUNCTION
 *  gui_title_set_alpha_layer
 * DESCRIPTION
 *  set alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  alpha_layer             [IN]            Is the alpha layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_alpha_blend_layer(gui_title_struct *t, gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->alpha_blend_layer = alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_alpha_blend_layer
 * DESCRIPTION
 *  set alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's alpha blend layer
 *****************************************************************************/
gdi_handle gui_title_get_alpha_blend_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->alpha_blend_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_alpha_layer
 * DESCRIPTION
 *  reset alpha layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_alpha_blend_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->alpha_blend_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_target_lcd
 * DESCRIPTION
 *  set target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  target_lcd              [IN]            Is the target_lcd of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_target_lcd(gui_title_struct *t, gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_lcd = target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_target_lcd
 * DESCRIPTION
 *  get target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's target lcd
 *****************************************************************************/
gdi_handle gui_title_get_target_lcd(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->target_lcd;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_target_lcd
 * DESCRIPTION
 *  reset target lcd of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_target_lcd(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_lcd = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_set_target_layer
 * DESCRIPTION
 *  set target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 *  target_layer            [IN]            Is the target_layer of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_target_layer(gui_title_struct *t, gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_get_target_layer
 * DESCRIPTION
 *  get target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  title's target layer
 *****************************************************************************/
gdi_handle gui_title_get_target_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return t->target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_reset_target_layer
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_reset_target_layer(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->target_layer = GDI_NULL_HANDLE;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_in_wap
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_set_in_wap(MMI_BOOL in_wap)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_title_is_in_wap = in_wap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_is_in_wap
 * DESCRIPTION
 *  reset target layer of title
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL gui_title_get_in_wap(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_gui_title_is_in_wap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_title_close
 * DESCRIPTION
 *  close title, init the title struct date
 * PARAMETERS
 *  t                       [IN/OUT]        Is the struct of title
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_close(gui_title_struct *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_close(&(t->sc));
    t->hide_callback = NULL;
	
#ifndef __MMI_SUBLCD__	
    t->target_lcd = GDI_NULL_HANDLE;
#endif/*__MMI_SUBLCD__*/

    t->target_layer = GDI_NULL_HANDLE;
    t->alpha_blend_layer = GDI_NULL_HANDLE;
	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
    t->show_text = MMI_FALSE;
    t->icon = NULL;
    t->icon2 = NULL;
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/

    t->has_title = MMI_FALSE;
    g_gui_title_is_in_wap = MMI_FALSE;
    
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    t->offset_x = 0;
    t->offset_y = 0;
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

    if (t->style & GUI_TITLE_STYLE_SCROLLING)
    {
        gui_title_unset_style(t,GUI_TITLE_STYLE_SCROLLING);
    }
	
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__    

	gui_stop_image_anim(t->icon_ani_handle);
	gui_stop_image_anim(t->icon2_ani_handle);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0	
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
#endif/**/

#ifdef __MMI_VUI_ENGINE__
    t->venus_update_screen_callback = NULL;
    t->venus_update_screen_handle = NULL;
#endif
}


#ifdef __MMI_VUI_ENGINE__

/*****************************************************************************
 * FUNCTION
 *  gui_title_register_venus_update_screen
 * DESCRIPTION
 *  Register the venus update screen callback function and handle
 * PARAMETERS
 *  t                               [IN/OUT]        Is the struct of title
 *  venus_update_screen_callback    [IN]            The callback of update screen in venus
 *  venus_update_screen_handle      [IN]            The pointer of title object in venus
 * RETURNS
 *  void
 *****************************************************************************/
void gui_title_register_venus_update_screen(
        gui_title_struct *t,
        void(*venus_update_screen_callback)(void *handle),
        void *venus_update_screen_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->venus_update_screen_callback = venus_update_screen_callback;
    t->venus_update_screen_handle = venus_update_screen_handle;
}

#endif /* __MMI_VUI_ENGINE__ */

#if 0//def __MMI_UI_TITLE_TRANSITION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */


#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */


/***************************************************************************** 
 * Touch Screen Adaptation
 *****************************************************************************/

#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_WEARABLE_DEVICE__)
	/*
	To handle list not move when user first pen done on title area,
	and promote the user experience
	*/


/*****************************************************************************
 * FUNCTION
 *  gui_title_translate_pen_event
 * DESCRIPTION
 *  
 * PARAMETERS    
 *  title_event            [OUT]         
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL gui_title_translate_pen_event(
				gui_title_struct *t,
                mmi_pen_event_type_enum pen_event,
                S16 x,
                S16 y,
                gui_title_pen_enum *title_event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (pen_event)
    {
        case MMI_PEN_EVENT_DOWN:
            if (PEN_CHECK_BOUND(x, y, t->x, t->y, t->width, t->height))
            {
                ret = MMI_TRUE;
                *title_event = GUI_TITLE_PEN_DOWN;
            }
            else
            {
                ret = MMI_FALSE;
            }
            break;

        case MMI_PEN_EVENT_UP:
            if (PEN_CHECK_BOUND(x, y, t->x, t->y, t->width, t->height))
            {
                *title_event = GUI_TITLE_PEN_UP_INSIDE;
            }
            else
            {
                *title_event = GUI_TITLE_PEN_UP_OUTSIDE;
            }

            break;

        case MMI_PEN_EVENT_LONG_TAP:
			
            break;

        case MMI_PEN_EVENT_REPEAT:

            break;

        case MMI_PEN_EVENT_MOVE:
            if (PEN_CHECK_BOUND(x, y, t->x, t->y, t->width, t->height))
            {
				*title_event = GUI_TITLE_PEN_MOVE_INSIDE;

            }
            else
            {
      			*title_event = GUI_TITLE_PEN_MOVE_OUTSIDE;
            }
            break;

        case MMI_PEN_EVENT_ABORT:
            break;

        default:
            MMI_ASSERT(0);
    }

    return ret;
}
#endif/*#if defined(__MMI_WEARABLE_DEVICE__)*/
#endif//



