/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  gui_title_pre_oem.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intends for title.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *     HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef __GUI_TITLE_PRE_OEM_H__
#define __GUI_TITLE_PRE_OEM_H__

#include "MMI_features.h"
#include "gui_config.h"
#include "gui_menu_shortcut.h"
#include "wgui.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "CustThemesRes.h"
#include "gui_data_types.h"
#include "gui_windows.h"

#define GUI_TITLE_MAX_LENGTH   256
#define GUI_TITLE_BUFFER_SIZE ((GUI_TITLE_MAX_LENGTH + 1) * ENCODING_LENGTH)

typedef struct
{
    U8 text[GUI_TITLE_BUFFER_SIZE];             /* buffer of text */
    S32 x;
    S32 y;
    S32 width;
    S32 height;
    MMI_BOOL no_icon_shct;                      /* do now show icon and shortcut */
    MMI_BOOL show_text;                         /* whether title show text or icon1 */
    MMI_BOOL has_title;                         /* The current screen have title or not */
    PU8 icon;                                   /* left icon */
    PU8 icon2;                                  /* right icon */
    gdi_handle icon_ani_handle;                 /* handle of animated icon */
    gdi_handle icon2_ani_handle;                /* handle of animate icon2 */
    UI_filled_area *active_filler;              /* filler of active mode */
    UI_font_type normal_font;                   /* filler of normal mode */
    UI_font_type active_font;                   /* font of active mode */
    color text_color;                           /* color of text */
    color text_border_color;                    /* color of border text */
    void (*pre_goto_callback) (S32 i);          /* call back functon of previous goto */
    void (*goto_callback) (S32 i);              /* call back function of goto */
    U32 style;                                  /* style of title */            
    void (*hide_callback)(S32 x, S32 y, S32 w, S32 h); /* hide callback */ 
    /* the target lcd of title */
    gdi_handle target_lcd;
    /* the target layer of title */
    gdi_handle target_layer;
    /* the alpha blending layer of title */
    gdi_handle alpha_blend_layer;
    gui_shortcut_struct sc;                     /* shortcut struct */
    scrolling_text scrolling_text;              /* scrolling text struct */ 
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
    /* the x offset of title, use in SSE */
    S32 offset_x;
    /* the y offset of title, use in SSE */
    S32 offset_y;
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

#ifdef __MMI_VUI_ENGINE__
    /* The call back of update screen fot venus engine */
    void (*venus_update_screen_callback)(void *handle);
    /* The pointer of title object */
    void *venus_update_screen_handle;
#endif

#if 0//def  __MMI_UI_TITLE_MINI_INDICATOR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_TITLE_MINI_INDICATOR__ */

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__    
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
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
#endif /*TITLE_TRANSITION_STYLE_NON_BLOCKING*/
#endif /* __MMI_UI_TITLE_TRANSITION__ */   

} gui_title_struct;

#endif /*__GUI_TITLE_PRE_OEM_H__*/

