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
*  wgui_dynamic_menus.c
*
* Project:
* --------
*   PlutoMMI
*
* Description:
* ------------
*   In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
*   to a category screen, a modification in MMI for dynamic item loading is required as the following.
*
* Author:
* -------
 * -------
*
*******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "wgui_fixed_menuitems.h"
#include "gui_dynamic_menus.h"
#include "ProfilingEngine.h"
#include "gui_typedef.h"
#include "gui_config.h"
#include "MMIDataType.h"
#include "MMI_features.h"
#include "gui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "CustDataProts.h"
#include "CustMenuRes.h"
#include "wgui_fixed_menus.h"
#include "gui.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "gui_fixed_menus.h"
#include "gdi_const.h"
#include "wgui_include.h"
#include "wgui_categories_util.h"
#include "gui_scrollbars.h"
#include "kal_general_types.h"
#include "gdi_datatype.h"
#include "gdi_include.h"
#include "gui_menu_post_oem.h"
#include "wgui_dynamic_menuitems.h"
#include "Unicodexdcl.h"
#include "lcd_sw_inc.h"
#include "wgui_dynamic_menus.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
#if 0//((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
/* under construction !*/
#endif
extern MMI_BOOL g_list_goto_disable_item;

//extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_dynamic_text_list_pop_up_description(void);

/***************************************************************************** 
 * Local Function
 *****************************************************************************/


/***************************************************************************** 
 * Global Function
 *****************************************************************************/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
#endif/*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/
/* under construction !*/
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
/* under construction !*/
/* under construction !*/
#endif/*GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN*/
/* under construction !*/
#if 0//((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
/* under construction !*/
/* under construction !*/
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)
/* under construction !*/
#endif/*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/ 
/* under construction !*/
#ifndef __MMI_UI_MENU_SLIM__
/* under construction !*/
#endif/*__MMI_UI_MENU_SLIM__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
/* under construction !*/
#endif/*__MMI_UI_TWO_LINE_MENUITEM_STYLES__*/ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__	
/* under construction !*/
#endif/*__MMI_TOUCH_SCREEN__*/
/* under construction !*/
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
/* under construction !*/
#endif/*defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)*/    
/* under construction !*/
#endif//0

/*****************************************************************************
 * FUNCTION
 *  show_dynamic_list
 * DESCRIPTION
 *  Show the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_dynamic_list(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif/*__MMI_SUBLCD__*/
   // gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
	gui_push_and_set_list_menu_act_handle_active();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif/*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/ 

    wgui_reset_ssp_and_sync_menu_display_when_freerun();
#if 0//GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#if (defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)
    wgui_two_line_stop_scroller();
#endif/*(defined __MMI_UI_TWO_LINE_MENUITEM_STYLES__ || defined __MMI_UI_HINTS_IN_MENUITEM__)*/

	///TODO: only be used in IMPS, can be removed?? 	
#ifndef __MMI_UI_MENU_SLIM__
    /* call pre-display callback */
    if (MMI_fixed_list_menu.pre_display_function)
    {
        MMI_fixed_list_menu.pre_display_function();
    }
#endif/*__MMI_UI_MENU_SLIM__*/

#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

#ifndef __MMI_UI_MENU_ENHANCEMENT_SLIM__
    wgui_hide_list_menu_if_bkg_disabled();
#endif/*__MMI_UI_MENU_ENHANCEMENT_SLIM__*/
    
    gui_show_dynamic_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS	
    wgui_display_dynamic_text_list_pop_up_description();
#endif/*UI_ENABLE_POP_UP_DESCRIPTIONS*/
   // wgui_list_menu_show_empty_label_if_needed();
    wgui_blt_previous_whole_list_menu();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
    gdi_lcd_set_active(act_lcd);
#endif/*__MMI_SUBLCD__*/
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0	
  #ifdef __MMI_SUBLCD__ 	
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
  #ifdef __MMI_SUBLCD__ 
/* under construction !*/
/* under construction !*/
  #endif	
/* under construction !*/
#endif//0
/* under construction !*/
#if 0//((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
/* under construction !*/
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 
#if 0
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
#endif
#endif//0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__	
/* under construction !*/
#endif
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
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
#ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
#else 
#ifndef __MMI_UI_MENU_SLIM__
/* under construction !*/
#endif
#endif 
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
#endif
/* under construction !*/
#endif

/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_goto_item_common(GUI_FIXED_LIST_PREV_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_list_goto_item_common(GUI_FIXED_LIST_NEXT_ITEM);
}


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif/*__MMI_SUBLCD__*/
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_is_fixed_list_menu_empty())//(MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

    if (item_index == MMI_fixed_list_menu.highlighted_item &&
        (MMI_fixed_list_menu.highlighted_item >= MMI_fixed_list_menu.first_displayed_item &&
        MMI_fixed_list_menu.highlighted_item <= MMI_fixed_list_menu.last_displayed_item))
    {
        return;
    }
#ifndef __MMI_WEARABLE_DEVICE__
    MMI_fixed_list_menu.item_get_flag_function(
        NULL,  
        NULL,
        item_index,  
        &flags, 
        &flags_ext);

    if (gui_is_menuitem_disabled(flags))
		return;
#endif /*__MMI_WEARABLE_DEVICE__*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_SUBLCD__
    gdi_lcd_get_active(&act_lcd);
    gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif/*__MMI_SUBLCD__*/	
    //gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
	gui_push_and_set_list_menu_act_handle_active();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To handle the redraw of hilighter if item index is greater then no of items */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
		gdi_lcd_set_active(act_lcd);
#endif/*__MMI_SUBLCD__*/
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    redraw_dynamic_list();

    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
	gdi_lcd_set_active(act_lcd);  
#endif/*__MMI_SUBLCD__*/
}

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
/*****************************************************************************
 * FUNCTION
 *  dynamic_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  Go to the specified item with smooth scrolling effect.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
*****************************************************************************/
void dynamic_list_shortcut_handle_with_SSK(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle act_lcd;
    S32 old_highlighed_item, new_highlighted_item, menu_height;
    gui_common_menuitem_base_struct *m;
#if 0//__MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
#endif
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_is_fixed_list_menu_empty())//(MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    
    MMI_fixed_list_menu.item_get_flag_function(
        NULL,
        NULL,
        item_index,  
        &flags, 
        &flags_ext);

	if (gui_is_menuitem_disabled(flags))
		return;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

#if 0//__MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else   /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    if (item_index != MMI_fixed_list_menu.highlighted_item)
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
    {
        /* goto the item with smooth scrolling effect */
#ifdef __MMI_SUBLCD__
		gdi_lcd_get_active(&act_lcd);
		gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif/*__MMI_SUBLCD__*/
       // gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
		gui_push_and_set_list_menu_act_handle_active();

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        /* To handle the redraw of hilighter if item index is greater then no of items */
        if (item_index >= MMI_fixed_list_menu.n_items)
        {
            gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
			gdi_lcd_set_active(act_lcd);
#endif/*__MMI_SUBLCD__*/
            return;
        }
        gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

        old_highlighed_item = MMI_fixed_list_menu.highlighted_item;
        gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

        if (gui_list_menu_is_support_smooth_scrolling())
        {
            new_highlighted_item = MMI_fixed_list_menu.highlighted_item;

            m = (gui_common_menuitem_base_struct*) MMI_fixed_list_menu.common_item_data;

            menu_height = MMI_fixed_list_menu.displayed_items * m->height;
            if (gui_list_menu_is_highlight_item_two_line())
            {
                menu_height += MMI_fixed_list_menu.height;
            }

            if ((new_highlighted_item == MMI_fixed_list_menu.first_displayed_item) && (new_highlighted_item > 0))
            {
                MMI_fixed_list_menu.first_displayed_item -= 1;
                MMI_fixed_list_menu.last_displayed_item -= 1;
            }
            else
            {
                if (MMI_fixed_list_menu.height < menu_height + (m->height / 3))
                {
                    /* for scroll down, the next menu item has already load in buffer */
                    if ((new_highlighted_item == MMI_fixed_list_menu.last_displayed_item) && 
                        (new_highlighted_item < (MMI_fixed_list_menu.n_items - 1)))
                    {
                        MMI_fixed_list_menu.first_displayed_item += 1;
                        MMI_fixed_list_menu.last_displayed_item += 1;
                    }
                }
            }
        }

        redraw_dynamic_list();

        gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
		gdi_lcd_set_active(act_lcd); 
#endif
    }
}
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/*****************************************************************************
 * FUNCTION
 *  dynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the dynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void dynamic_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_SUBLCD__	
    gdi_handle act_lcd;
#endif/*__MMI_SUBLCD__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_is_fixed_list_menu_empty())//(MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }
    set_dynamic_pop_up_descriptions(item_index);
	
#ifdef __MMI_SUBLCD__
	gdi_lcd_get_active(&act_lcd);
	gdi_lcd_set_active(MMI_fixed_list_menu.act_lcd_handle);
#endif/*__MMI_SUBLCD__*/
   // gdi_layer_push_and_set_active(MMI_fixed_list_menu.act_layer_handle);
	gui_push_and_set_list_menu_act_handle_active();

	gui_list_goto_menuitem_index_auto_adjust(&item_index);
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
/* under construction !*/
/* under construction !*/
#endif//0
	
    gui_dynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    gdi_layer_pop_and_restore_active();
#ifdef __MMI_SUBLCD__
	gdi_lcd_set_active(act_lcd);           
#endif/*__MMI_SUBLCD__*/
    set_dynamic_pop_up_descriptions(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the dynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  register_menu_shortcut_keys();
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
    register_menu_shortcut_keys_and_handler(dynamic_list_shortcut_handle_with_SSK);
#else
    register_menu_shortcut_keys_and_handler(dynamic_list_goto_item);//dynamic_list_shortcut_handle
#endif
    
#ifdef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT)
        register_menu_shortcut_selected(wgui_list_menu_shortcut_executer);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  register_dynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the dynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_dynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	clear_keyboard_key_handler();

	register_navigation_key_handlers(
		dynamic_list_goto_previous_item,
		dynamic_list_goto_next_item,
		NULL,
		NULL);

   
	
 //   SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
 //   SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	
 //   SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
 //   SetKeyHandler(dynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);

//	SetKeyHandler(dynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
//    SetKeyHandler(dynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);

//	SetKeyHandler(dynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
//    SetKeyHandler(dynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

	register_vol_key_handlers(
		dynamic_list_goto_previous_item,
		dynamic_list_goto_next_item);
}

#if 0//((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_SUBLCD__
/* under construction !*/
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
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS        
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#ifdef __MMI_SUBLCD__
/* under construction !*/
        #endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* ((UI_ENABLE_FRAME_SKIPPING) && (ENABLE_LIST_MENU_FRAME_SKIPPING)) */ 


/*****************************************************************************
 * FUNCTION
 *  DynamicListIncreaseItem
 * DESCRIPTION
 *  Increase the total number of dynamic item.
 * PARAMETERS
 *  steps       [IN]        Number of items to be increased
 * RETURNS
 *  void
 *****************************************************************************/
void DynamicListIncreaseItem(S16 steps)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_buffer.n_total_items = dynamic_item_buffer.n_total_items + steps;
    MMI_fixed_list_menu.n_items = MMI_fixed_list_menu.n_items + steps;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetItems
 * DESCRIPTION
 *  Return total number of dynamic items and the requested item text from the dynamic buffer.
 *  The caller must take care of the validity of the specified item in the buffer.
 * PARAMETERS
 *  string          [OUT]       Requested item text
 *  item_index      [IN]        Index of the requested item
 * RETURNS
 *  total number of dynamic items
 *****************************************************************************/
S32 DynamicListGetItems(U8 *string, U16 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy((CHAR *) string, (CHAR *) MMI_fixed_icontext_menuitems[(item_index) % 32].item_text);
    }

    return MMI_fixed_list_menu.n_items;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicListGetHighlightedItem
 * DESCRIPTION
 *  Return the index and text of the highlighted item.
 * PARAMETERS
 *  string      [OUT]       Highlighted item text
 * RETURNS
 *  Highlighted item index
 *****************************************************************************/
S32 DynamicListGetHighlightedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (CHAR *) string,
            (CHAR *) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.highlighted_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.highlighted_item;
}


/*****************************************************************************
 * FUNCTION
 *  DynamicGetFirstDisplayedItem
 * DESCRIPTION
 *  Return the index and text of first displayed item.
 * PARAMETERS
 *  string      [OUT]       First displayed item text
 * RETURNS
 *  First displayed item index
 *****************************************************************************/
S32 DynamicGetFirstDisplayedItem(U8 *string)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (string != NULL)
    {
        mmi_ucs2cpy(
            (CHAR *) string,
            (CHAR *) MMI_fixed_icontext_menuitems[(MMI_fixed_list_menu.first_displayed_item) % 32].item_text);
    }

    return MMI_fixed_list_menu.first_displayed_item;
}


#if  0//__MMI_SUPPORT_DYNAMIC_MATRIX_MENU__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_SUBLCD__
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
/* under construction !*/
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_INTERACTIVE_PROFILNG__
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
#ifdef __MMI_INTERACTIVE_PROFILNG__
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
#ifdef __MMI_INTERACTIVE_PROFILNG__
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
#ifdef __MMI_INTERACTIVE_PROFILNG__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // __MMI_SUPPORT_DYNAMIC_MATRIX_MENU__


