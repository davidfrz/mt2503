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
 *  gui_title.h
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
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#ifndef __GUI_TITLE_H__
#define __GUI_TITLE_H__

#include "gui_title_pre_oem.h"
#include "MMI_features.h"
#include "CustMenuRes.h"
#include "gui_config.h"
#include "wgui.h"
#include "gui_menu_shortcut.h"
#include "gui_title_post_oem.h"
#include "gui_typedef.h"

#define GUI_TITLE_PART_ICON              0x00000001
#define GUI_TITLE_PART_ICON2             0x00000002
#define GUI_TITLE_PART_TEXT              0x00000004
#define GUI_TITLE_PART_SHORTCUT          0x00000008
#define GUI_TITLE_PART_INSERTSHORTCUT    0x00000010
#define GUI_TITLE_PART_SIGNAL            0x00000020
#define GUI_TITLE_PART_BATTERY           0x00000040
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
#define GUI_TITLE_PART_ALL   (GUI_TITLE_PART_ICON | GUI_TITLE_PART_ICON2 | GUI_TITLE_PART_TEXT | GUI_TITLE_PART_SHORTCUT | GUI_TITLE_PART_SIGNAL | GUI_TITLE_PART_BATTERY)
//#endif

#define GUI_TITLE_STYLE_NORMAL          0x00000000
#define GUI_TITLE_STYLE_SCROLLING       0x00000001
#define GUI_TITLE_STYLE_LEFTALIGN       0x00000002
#define GUI_TITLE_STYLE_DISABLEBG       0x00000004
#define GUI_TITLE_STYLE_OEM_START       0x00000008
#define GUI_TITLE_STYLE_OEM_END         0x80000000

#ifdef __MMI_TOUCH_SCREEN__
/* DOM-NOT_FOR_SDK-END */

/* <group dom_buttons_enum>
 *  Enum values which are used to describe pen event of button. */
typedef enum
{
    /* Is an enum value which represents no event of title is generated */
    GUI_TITLE_PEN_NONE, 
    /* Is an enum value which represents pen down event inside title */
    GUI_TITLE_PEN_DOWN,
    /* Is an enum value which represents pen repeat event inside title */
    GUI_TILE_PEN_REPEAT,
    /* Is an enum value which represents pen longtap event inside title */
    GUI_TITLE_PEN_LONGTAP,
   	GUI_TITLE_PEN_UP_INSIDE,
    /* Is an enum value which represents pen up event outside button */
    GUI_TITLE_PEN_UP_OUTSIDE,
    /* Is an enum value which represents pen move event outside button */
    GUI_TITLE_PEN_MOVE_OUTSIDE,
    /* Is an enum value which represents pen move event inside button */
    GUI_TITLE_PEN_MOVE_INSIDE
} gui_title_pen_enum;

/* DOM-NOT_FOR_SDK-BEGIN */
#endif /* __MMI_TOUCH_SCREEN__ */ 


//extern U16 title_bg_id;
#if 0
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif//0


extern UI_window_title_theme *current_window_title_theme;
extern UI_window_title_theme *current_thick_title_theme;

//extern void (*gui_title_show_background) (gui_title_struct *, S32, S32, S32, S32);
//extern void (*gui_title_measure)(gui_title_struct *t, U32 part, S32 *x1, S32 *x2, S32 *h);

extern void gui_title_register_hide_callback(
                gui_title_struct *t,
                void (*hide_callback)(S32 x, S32 y, S32 w, S32 h));

extern void gui_title_reset_hide_callback(gui_title_struct *t);
extern void gui_title_create_ex(
                gui_title_struct *t,
                S32 x, 
                S32 y, 
                S32 wdith, 
                S32 height, 
                gdi_handle target_lcd, 
                gdi_handle target_layer,
                gdi_handle alpha_blend_layer);

extern void gui_title_create(
	gui_title_struct *t, 
	S32 x, 
	S32 y, 
	S32 wdith, 
	S32 height);

extern MMI_BOOL gui_title_show(
	gui_title_struct *t, 
	U32 npart);

extern void gui_title_move(
	gui_title_struct *t, 
	S32 x, 
	S32 y);

extern void gui_title_resize(
	gui_title_struct *t, 
	S32 width, 
	S32 height);

extern void gui_title_change_ex(
	gui_title_struct *t, 
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
	PU8 icon, 
	PU8 icon2, 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/	
	U8 *text);

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
#define gui_title_change gui_title_change_ex
#else/**/
#define gui_title_change(_arg0, _arg1, _arg2, _arg3) gui_title_change_ex(_arg0, _arg3)
#endif/**/

extern void gui_title_set_style(
	gui_title_struct *t, 
	U32 style);

extern void gui_title_unset_style(
	gui_title_struct *t, 
	U32 style);

extern void gui_title_register_callback(
                gui_title_struct *t,
                void (*pre_goto_funcptr) (S32 i), 
                void (*goto_funcptr) (S32 i), 
                U32 flag);

extern void gui_title_set_theme(
	gui_title_struct *t, 
	UI_window_title_theme *th);

extern void gui_title_set_current_theme(gui_title_struct *t);

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
extern void gui_title_set_no_icon_shct(
	gui_title_struct *t, 
	MMI_BOOL no_icon_shct);
#else/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
#define gui_title_set_no_icon_shct(_arg1, _arg2) 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/

#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
void gui_title_measure_area1(
	gui_title_struct *t, 
	S32 *width, 
	S32 *height);

void gui_title_measure_area2(
	gui_title_struct *t, 
	S32 *width, 
	S32 *height);
#else/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
#define gui_title_measure_area1(_arg1, _arg2, _arg3) 
#define gui_title_measure_area2(_arg1, _arg2, _arg3) 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/

extern void gui_title_set_in_wap(MMI_BOOL in_wap);
extern MMI_BOOL gui_title_get_in_wap(void);

#ifdef __MMI_SCREEN_SWITCH_EFFECT__
extern void gui_title_get_text_info(
	gui_title_struct *t, 
	S32 *text_width, 
	S32 *text_height, 
	PU8 *text_content);
#endif /* __MMI_SCREEN_SWITCH_EFFECT__ */

extern void gui_title_set_alpha_blend_layer(
	gui_title_struct *t, 
	gdi_handle alpha_blend_layer);

extern gdi_handle gui_title_get_alpha_blend_layer(gui_title_struct *t);

extern void gui_title_reset_alpha_blend_layer(gui_title_struct *t);

extern void gui_title_set_target_lcd(
	gui_title_struct *t, 
	gdi_handle target_lcd);

extern gdi_handle gui_title_get_target_lcd(gui_title_struct *t);

extern void gui_title_reset_target_lcd(gui_title_struct *t);

extern void gui_title_set_target_layer(
	gui_title_struct *t, 
	gdi_handle target_layer);

extern gdi_handle gui_title_get_target_layer(gui_title_struct *t);

extern void gui_title_reset_target_layer(gui_title_struct *t);

extern void gui_title_close(gui_title_struct *t);

#ifdef __MMI_VUI_ENGINE__
extern void gui_title_register_venus_update_screen(
                gui_title_struct *t,
                void (*venus_update_screen_callback)(void *handle),
                void *venus_update_screen_handle);
#endif/*__MMI_VUI_ENGINE__*/

#if 0//def __MMI_UI_ANIMATED_TITLE_EFFECT__
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
#if(TITLE_TRANSITION_STYLE_NON_BLOCKING)
/* under construction !*/
#endif /* (TITLE_TRANSITION_STYLE_NON_BLOCKING) */ 
#endif /* __MMI_UI_TITLE_TRANSITION__ */ 

//huking add
#define gui_title_show_normal gui_title_oem_show_normal
#define gui_title_show_background gui_title_oem_show_background
#define gui_title_measure gui_title_measure_oem
//end huking add


#endif /* __GUI_TITLE_H__ */ 


