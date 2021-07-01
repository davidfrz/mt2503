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
*  wgui_asyncdynamic_menus.c
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
#include "CustMenuRes.h"
#include "wgui_fixed_menus.h"
#include "wgui_asyncdynamic_menus.h"
#include "gui_asyncdynamic_menus.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_categories_util.h"
#include "gui_typedef.h"
#include "MMIDataType.h"
#include "gui_config.h"
#include "MMI_features.h"
#include "gui_fixed_menuitems.h"
#include "gui_effect_oem.h"
#include "CustDataProts.h"
#include "gui.h"
#include "wgui.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "gui_fixed_menus.h"
#include "gdi_const.h"
#include "wgui_include.h"
#include "gui_scrollbars.h"
#include "kal_general_types.h"
#include "gui_menu_post_oem.h"
#include "gdi_include.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "ProfilingEngine.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
//extern void dummy_highlight_handler(S32 item_index);
extern void (*_MMI_hide_fixed_list_menu) (void);
extern void wgui_display_fixed_text_list_pop_up_description(void);
extern void wgui_display_asyncdynamic_text_list_pop_up_description(void);
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
static void asyncdynamic_matrix_goto_x(S32 goto_type, S32 item_index);
#endif/*__MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__*/
extern MMI_BOOL gui_asyncdynamic_list_error;
extern MMI_BOOL g_list_goto_disable_item;

#if 0//( UI_ENABLE_FRAME_SKIPPING )
/* under construction !*/
#endif 

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  reset_asyncdynamic_list
 * DESCRIPTION
 *  Reset the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
///TODO: only be used in IMPS, can be removed??		
#ifndef __MMI_UI_MENU_SLIM__	
	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
		/* clear asyncdynamic list pre-display handler */
	    register_asyncdynamic_list_pre_display_handler(NULL);
#endif/*__MMI_UI_MENU_SLIM__*/

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif/*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/ 

#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (MMI_current_menu_type == LIST_MENU)
        gui_ssp_pen_up_dummy();
#endif/*GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN*/

#if 0//( UI_ENABLE_FRAME_SKIPPING )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if(ENABLE_LIST_MENU_FRAME_SKIPPING)
/* under construction !*/
/* under construction !*/
		#endif/*end ENABLE_LIST_MENU_FRAME_SKIPPING*/
/* under construction !*/
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
	normal_fixed_list();

#if defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)      /* 072505 Calvin modified */
    gui_reset_transparent_source_layer();
#endif/*defined (__MMI_UI_TRANSPARENT_EFFECT__) || defined (__MMI_UI_LIST_HIGHLIGHT_EFFECTS__)*/ 

#ifndef __MMI_UI_MENU_SLIM__
    gui_cancel_timer(gui_callback_highlighter_text_filler);
#endif/*__MMI_UI_MENU_SLIM__*/

    //clear_keyboard_key_handler();

	clear_keyboard_and_navigation_key_handlers();
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0	
	
	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	{
		register_vol_key_handlers(
			NULL,
			NULL);
 //     ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_DOWN);
 //     ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_DOWN);
 //     ClearKeyHandler(KEY_VOL_UP, KEY_EVENT_REPEAT);
 //     ClearKeyHandler(KEY_VOL_DOWN, KEY_EVENT_REPEAT);
	}

    MMI_fixed_list_menu.item_highlighted = UI_dummy_function_s32;
    MMI_fixed_list_menu.highlighted_item = -1;
    MMI_fixed_list_menu.alpha_blend_layer_handle = GDI_NULL_HANDLE;    
	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
	//{
       MMI_fixed_list_menu.show_loading_index = -1;
	//}
    wgui_text_menuitem_reset_scrolling();

	if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	//{
	   gui_fixed_icontext_list_menuitem_stop_scroll();
	//}
    wgui_fixed_list_register_get_underline_function(NULL);
    wgui_fixed_list_register_pre_key_handler(NULL);
    wgui_fixed_list_set_data_layout(NULL, 0);
    wgui_fixed_list_register_hide_function(NULL);
    wgui_fixed_list_register_get_flags_handler(NULL);
    register_fixed_list_unhighlight_handler(UI_dummy_function_s32);
	
    gui_vertical_scrollbar_reset_target_layer(&MMI_fixed_list_menu.vbar);
    gui_vertical_scrollbar_reset_alpha_blend_layer(&MMI_fixed_list_menu.vbar);
    gui_vertical_scrollbar_enable_clear_background(&MMI_fixed_list_menu.vbar, MMI_TRUE);

	wgui_list_set_slow_data_mode(MMI_FALSE);

    if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
    {
       wgui_async_list_register_update_callback(NULL);
    }
	else if(MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_FIXED)
	{
	   wgui_fixed_list_register_display_callback(NULL);
       wgui_fixed_list_register_indicator_display_callback(NULL);
       gui_resize_vertical_scrollbar(&MMI_fixed_list_menu.vbar, MMI_fixed_list_menu.vbar.width, MMI_fixed_list_menu.height);

       #if 0//__MMI_OP11_SIDEBAR__
/* under construction !*/
/* under construction !*/
       #endif
	}
#ifdef __MMI_UI_TWO_LINE_MENUITEM_STYLES__
    reset_fixed_icontext_menuitem_type();
#endif/*__MMI_UI_TWO_LINE_MENUITEM_STYLES__*/

    wgui_list_menu_disable_access_by_shortcut();
    wgui_effect_register_query_enable_draw_last_frame(NULL);
	
#ifdef __MMI_TOUCH_SCREEN__	
    wgui_list_menu_disable_scrollbar_drag(MMI_FALSE);
#endif/*__MMI_TOUCH_SCREEN__*/
    
#if defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    gui_ssp_reset_static_layer();
#endif/*defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_KEY) || defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)*/    
}


/*****************************************************************************
 * FUNCTION
 *  show_asyncdynamic_list
 * DESCRIPTION
 *  Show the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_asyncdynamic_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif/*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/ 

    wgui_reset_ssp_and_sync_menu_display_when_freerun();

#if  0//GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifndef __MMI_UI_MENU_ENHANCEMENT_SLIM__
    wgui_hide_list_menu_if_bkg_disabled();
#endif/*__MMI_UI_MENU_ENHANCEMENT_SLIM__*/
	
    gui_show_asyncdynamic_list_menu(&MMI_fixed_list_menu);
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS	
    wgui_display_asyncdynamic_text_list_pop_up_description();
#endif/*UI_ENABLE_POP_UP_DESCRIPTIONS*/

//    wgui_list_menu_show_empty_label_if_needed();

	wgui_blt_previous_whole_list_menu();
#if 0//(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_ATV_SUPPORT__
    if (g_gui_list_display_callback)
    {
        g_gui_list_display_callback();
    }
#endif/*__MMI_ATV_SUPPORT__*/    
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
#else /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
/* under construction !*/
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 
/* under construction !*/
#endif//0

/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item_common
 * DESCRIPTION
 *  Go to the previous/next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asyncdynamic_list_goto_item_common(S32 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif

	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	if(wgui_is_down_key_hold()&& (MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1))
		 return;

	if(wgui_is_up_key_hold()&& (MMI_fixed_list_menu.highlighted_item == 0))
		 return;

#ifdef __128X128_WEARABLE_DEVICE_UI__
    if(((MMI_fixed_list_menu.highlighted_item == 0)&&(direction == 0))
        ||((MMI_fixed_list_menu.highlighted_item == MMI_fixed_list_menu.n_items - 1)&&(direction == 1))
        )
    {
        gui_list_key_ssp_back_show_item(direction,1);
        
        return;
    }
#endif
	if(wgui_list_is_goto_item_invalid())
		return;

#ifdef __MMI_CAT103_SUPPORT__
	if(gui_is_list_pre_key_handler_executed(direction == 0))
		return;
#endif/*__MMI_CAT103_SUPPORT__*/

#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_stop_list_highlight_effect();
#endif/*__MMI_UI_LIST_HIGHLIGHT_EFFECTS__*/ 

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
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
   // {
	gui_list_effect_slide_start();
   // }
    
    if (direction == 0)
    {
        gui_asyncdynamic_list_menu_goto_previous_item(&MMI_fixed_list_menu);
    }
    else
    {
        gui_asyncdynamic_list_menu_goto_next_item(&MMI_fixed_list_menu);
    }


    if (gui_asyncdynamic_list_error)
    {
        gui_list_effect_slide_end();
        gui_list_effect_slide_stop();
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        if (gui_get_current_list_effect() == MMI_UI_LIST_HIGHLIGHT_EFFECT_SLIDE)
        {
            gdi_layer_blt_previous(0, 0, 0, 0);
        }
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

        return;
    }

    redraw_asyncdynamic_list();

#if 0
/* under construction !*/
#endif  /* __MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__ */
  //  {
    gui_list_effect_slide_end();    
  //  }
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_goto_item_common(0);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_list_goto_item_common(1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags, flags_ext;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_is_fixed_list_menu_empty()|| 
		item_index == MMI_fixed_list_menu.highlighted_item)//(MMI_fixed_list_menu.n_items <= 0)
    {
        return;
    }

   // if (item_index == MMI_fixed_list_menu.highlighted_item)
   // {
   //     return;
    //}
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
#endif//

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To avoid highlight effect when user jump to wrong menu index */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

    if (!gui_asyncdynamic_list_error)
    {
       redraw_asyncdynamic_list(); 
    }    
}


#ifdef __MMI_WEARABLE_DEVICE__
/*****************************************************************************
 * FUNCTION
 * asyncdynamic_list_goto_item_ex
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item_ex(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 flags, flags_ext;
	S32 last_highlighted_item;
	U32 direction = 0;
	S32 disable_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (gui_is_fixed_list_menu_empty()|| 
		item_index == MMI_fixed_list_menu.first_displayed_item)//(MMI_fixed_list_menu.n_items <= 0)
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

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    /* To avoid highlight effect when user jump to wrong menu index */
    if (item_index >= MMI_fixed_list_menu.n_items)
    {
        return;
    }
    gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */

#ifdef __MMI_TOUCH_SCREEN__
    /* If highlight is changed by keypad, abort scroll timer */
    gui_dynamic_list_abort_scroll_timer();
    gui_asyncdynamic_list_abort_scroll_timer();
#endif /* __MMI_TOUCH_SCREEN__ */ 

    if (!gui_is_index_in_menu_valid_region(item_index, &MMI_fixed_list_menu) ||
		item_index == MMI_fixed_list_menu.first_displayed_item && item_index != -1)//((i < -1) || (i > m->n_items - 1))
    {
        return;
    }
	
    last_highlighted_item = MMI_fixed_list_menu.highlighted_item;
	
    MMI_fixed_list_menu.highlighted_item = item_index;
	MMI_fixed_list_menu.first_displayed_item = MMI_fixed_list_menu.highlighted_item;
	//get last item

	if  (MMI_FALSE == gui_list_menu_locate_item_compute_last(&MMI_fixed_list_menu))
   {
        MMI_fixed_list_menu.last_displayed_item = MMI_fixed_list_menu.n_items - 1;
		MMI_fixed_list_menu.first_displayed_item -= MMI_fixed_list_menu.displayed_items - \
			(MMI_fixed_list_menu.last_displayed_item - MMI_fixed_list_menu.first_displayed_item + 1);
   }
	flush_asyncdynamic_item_buffer_before_load_chunk();
	if(MMI_fixed_list_menu.n_items > 0)
	{
		gui_asyncdynamic_load_chunk_error(
				MMI_fixed_list_menu.first_displayed_item, 
				MMI_fixed_list_menu.last_displayed_item - MMI_fixed_list_menu.first_displayed_item + 2);
	}

    if (last_highlighted_item > item_index)
    {
        direction = 1;
    }
   /* while (gui_list_menu_is_goto_item_disabled(&MMI_fixed_list_menu))
    {
        disable_count++;		
        if (disable_count >= MMI_fixed_list_menu.n_items)
        {
          
            MMI_fixed_list_menu.highlighted_item = GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE;
            break;
        }
        gui_list_menu_goto_item_helper(&MMI_fixed_list_menu, &direction, item_index);
    }*/

    if (!gui_is_all_menuitem_in_list_disabled(&MMI_fixed_list_menu))//(m->highlighted_item != GUI_LIST_MENU_ALL_ITEMS_ARE_DISABLE)
    {
      	if (MMI_fixed_list_menu.menu_style == GUI_MENU_TYPE_ASYNCDYNAMIC)
        {
            if (!gui_asyncdynamic_list_error)
            {
                gui_asyncdynamic_list_menu_switch_highlighted_item(&MMI_fixed_list_menu, last_highlighted_item);
            }
            
        }
    }

    if (!gui_asyncdynamic_list_error)
    {
       redraw_asyncdynamic_list(); 
    }    
}

#endif /*__MMI_WEARABLE_DEVICE__*/
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_shortcut_handle_with_SSK
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
*****************************************************************************/
void asyncdynamic_list_shortcut_handle_with_SSK(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 new_highlighted_item, menu_height, last_displayed_item;
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
#endif//	

#if 0//__MMI_LIST_MENU_SCROLL_WITHOUT_CHANGE_HIGHLIGHT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    if (item_index != MMI_fixed_list_menu.highlighted_item)
#endif
    {
#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
        /* To avoid highlight effect when user jump to wrong menu index */
        if (item_index >= MMI_fixed_list_menu.n_items)
        {
            return;
        }
        gui_stop_list_highlight_effect();
#endif /* __MMI_UI_LIST_HIGHLIGHT_EFFECTS__ */ 

        /* calculate first_displayed_item, last_displayed_item and highlighted_item */
        gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);

        if (gui_list_menu_is_support_smooth_scrolling() && (!gui_asyncdynamic_list_error))
        {   
            /* if gui_list_menu_is_support_smooth_scrolling return MMI_TRUE, common_item_data must be Non-NULL */
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
                    last_displayed_item = MMI_fixed_list_menu.last_displayed_item;
                    if ((new_highlighted_item == last_displayed_item) && 
                        (new_highlighted_item < (asyncdynamic_item_buffer.n_total_items - 1)))
                    {
                            MMI_fixed_list_menu.first_displayed_item += 1;
                            MMI_fixed_list_menu.last_displayed_item += 1;
                    }
                }
            }
        }

        if (!gui_asyncdynamic_list_error)
        {
            redraw_asyncdynamic_list();
        }        
    }
}
#endif  /* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY */


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_list_goto_item_no_redraw
 * DESCRIPTION
 *  Go to a specified item without redrawing. For example, set the highlighted item
 *  before the asyncdynamic list is shown by the draw manager.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_list_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (gui_is_fixed_list_menu_empty())//(MMI_fixed_list_menu.n_items <= 0)
	{
	    return;
	}
	set_asyncdynamic_pop_up_descriptions(item_index);

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0	

    gui_asyncdynamic_list_menu_goto_item(&MMI_fixed_list_menu, item_index);
    set_asyncdynamic_pop_up_descriptions(item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the asyncdynamic list.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    register_menu_shortcut_keys();
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY
    register_menu_shortcut_keys_and_handler(asyncdynamic_list_shortcut_handle_with_SSK);
#else/*GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY*/
    register_menu_shortcut_keys_and_handler(asyncdynamic_list_shortcut_handle);
#endif/*GUI_LIST_MENU_SMOOTH_SCROLLING_BY_NUMBER_KEY*/

#ifdef __MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT)
        register_menu_shortcut_selected(wgui_list_menu_shortcut_executer);
#endif/*__MMI_LIST_MENU_HIGHLIGHT_CHANGE_AND_GOTO_BY_SHORTCUT__*/    
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_keys
 * DESCRIPTION
 *  Register key handlers of the asyncdynamic list, including 
 *  KEY_UP_ARROW, KEY_VOL_UP, KEY_DOWN_ARROW, and KEY_VOL_DOWN.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_keyboard_key_handler();

	register_navigation_key_handlers(
		asyncdynamic_list_goto_previous_item, 
		asyncdynamic_list_goto_next_item, 
		NULL, 
		NULL);
	
  //  SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_DOWN);
   // SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
	
  //  SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
  //  SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);

	//SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    //SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);

//	SetKeyHandler(asyncdynamic_list_goto_previous_item, KEY_VOL_UP, KEY_EVENT_REPEAT);
//    SetKeyHandler(asyncdynamic_list_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_REPEAT);

	register_vol_key_handlers(
      asyncdynamic_list_goto_previous_item,
      asyncdynamic_list_goto_next_item);
#ifdef __128X128_WEARABLE_DEVICE_UI__
    SetKeyUpHandler(fixed_list_goto_previous_item_up, KEY_VOL_UP);  
    SetKeyUpHandler(fixed_list_goto_next_item_up, KEY_VOL_DOWN);

    SetKeyUpHandler(fixed_list_goto_previous_item_up, KEY_UP_ARROW);  
    SetKeyUpHandler(fixed_list_goto_next_item_up, KEY_DOWN_ARROW);
#endif
}


#if 0//( UI_ENABLE_FRAME_SKIPPING )
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
    #endif 
/* under construction !*/
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
    #endif 
#ifdef UI_ENABLE_POP_UP_DESCRIPTIONS
/* under construction !*/
#endif
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
    #endif 
/* under construction !*/
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
    #endif 
    #if(UI_DOUBLE_BUFFER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* (UI_DOUBLE_BUFFER_SUPPORT) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */
/* under construction !*/
/* under construction !*/
#endif /* ( UI_ENABLE_FRAME_SKIPPING ) */ 


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_list_pre_display_handler
 * DESCRIPTION
 *  Register the handler function before displaying the menu.
 * PARAMETERS
 *  (*pre_display_handler)(void)       [IN]     pre-display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_list_pre_display_handler(void (*pre_display_handler)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_list_menu.pre_display_function = pre_display_handler;
}

#ifdef  __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__
/* Asyncdynamic matrix menu */
/*****************************************************************************
 * FUNCTION
 *  show_dynamic_matrix
 * DESCRIPTION
 *  Show the fixed matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void show_asyncdynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_asyncdynamic_matrix_menu(&MMI_fixed_matrix_menu);
   // gui_unlock_double_buffer();

	wgui_unlock_buffer_and_blt_whole_matrix_menu_previous();
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
}


/*****************************************************************************
 * FUNCTION
 *  reset_asyncdynamic_matrix
 * DESCRIPTION
 *  Reset the dynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void reset_asyncdynamic_matrix(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
  //  clear_keyboard_key_handler();

    clear_keyboard_and_navigation_key_handlers();
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0

	MMI_fixed_matrix_menu.item_highlighted = UI_dummy_function_s32;

#ifdef GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN
    gui_matrix_ssp_reset_state();
#endif/*GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN*/
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_previous_item
 * DESCRIPTION
 *  Go to the previous item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_previous_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	asyncdynamic_matrix_goto_x(GUI_ASYNC_PREV_ITEM, -1);
}



/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void asyncdynamic_matrix_goto_x(S32 goto_type, S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 last_first_displayed_row, last_highlight_item;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*
	if (MMI_fixed_matrix_menu.n_items <= 0)
    {
        return;
    }
*/
	if ((MMI_fixed_matrix_menu.n_items <= 1) && (MMI_fixed_matrix_menu.highlighted_item == 0))
    {
        return;
    }
    if(goto_type == GUI_ASYNC_ITEM)
    {
         // TODO: SHOULD USE A BETTER WAY TO RESPOND.
	    if (!gui_is_index_in_menu_valid_region(item_index, &MMI_fixed_matrix_menu))//((item_index >= MMI_fixed_matrix_menu.n_items) || (item_index < 0))
	    {
	        MMI_fixed_matrix_menu.last_highlighted_item = -2;

	        return;
	    }
    }
	
    if((goto_type == GUI_ASYNC_NEXT_ROW)|| (goto_type == GUI_ASYNC_PREV_ROW))
    {
	   // MMI_fixed_matrix_menu.last_highlighted_item = MMI_fixed_matrix_menu.highlighted_item;
       wgui_backup_matrix_menu_hilited_indx(); 
	   
#ifdef __MMI_INTERACTIVE_PROFILNG__
	    mmi_frm_profiling_delay_start_timer(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif/*__MMI_INTERACTIVE_PROFILNG__*/
   }

    last_first_displayed_row = MMI_fixed_matrix_menu.first_displayed_row;
    last_highlight_item = MMI_fixed_matrix_menu.highlighted_item;

	if(goto_type == GUI_ASYNC_NEXT_ROW)		
	   gui_asyncdynamic_matrix_menu_goto_next_row(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_NEXT_ITEM)
	   gui_asyncdynamic_matrix_menu_goto_next_item(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_PREV_ITEM)		
       gui_asyncdynamic_matrix_menu_goto_previous_item(&MMI_fixed_matrix_menu);
    else if(goto_type == GUI_ASYNC_PREV_ROW)		
       gui_asyncdynamic_matrix_menu_goto_previous_row(&MMI_fixed_matrix_menu);
	else if(goto_type == GUI_ASYNC_ITEM)		
	    gui_asyncdynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);

	if (gui_asyncdynamic_list_error)
    {
        return;
    }
	
    if (last_first_displayed_row == MMI_fixed_matrix_menu.first_displayed_row)
    {
        gui_lock_double_buffer();
        gui_show_asyncdynamic_matrix_menu_specific_items(&MMI_fixed_matrix_menu, last_highlight_item);
       // gui_unlock_double_buffer();

		wgui_unlock_buffer_and_blt_whole_matrix_menu_previous();
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif//0
    }
    else
    {
        redraw_asyncdynamic_matrix();  
    }    

#ifdef __MMI_INTERACTIVE_PROFILNG__
    if((goto_type == GUI_ASYNC_NEXT_ROW)||(goto_type == GUI_ASYNC_PREV_ROW))
      mmi_frm_profiling_delay_perform(MMI_FRM_PROFILING_DELAY_MATRIX_HIGHLIGHT);
#endif/*__MMI_INTERACTIVE_PROFILNG__*/
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_item
 * DESCRIPTION
 *  Go to the next item.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	asyncdynamic_matrix_goto_x(GUI_ASYNC_NEXT_ITEM, -1);
}



/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_previous_row
 * DESCRIPTION
 *  Go to the previous row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_previous_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	asyncdynamic_matrix_goto_x(GUI_ASYNC_PREV_ROW, -1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_next_row
 * DESCRIPTION
 *  Go to the the next row.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_next_row(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	asyncdynamic_matrix_goto_x(GUI_ASYNC_NEXT_ROW, -1);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_item
 * DESCRIPTION
 *  Go to the specified item.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_item(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	asyncdynamic_matrix_goto_x(GUI_ASYNC_ITEM, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  asyncdynamic_matrix_goto_item_no_redraw
 * DESCRIPTION
 *  Go to the specified item without redrawing the fixed matrix.
 * PARAMETERS
 *  item_index      [IN]        item index
 * RETURNS
 *  void
 *****************************************************************************/
void asyncdynamic_matrix_goto_item_no_redraw(S32 item_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_fixed_matrix_menu.highlighted_item = -1;
    gui_asyncdynamic_matrix_menu_goto_item(&MMI_fixed_matrix_menu, item_index);
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_matrix_loop_keys
 * DESCRIPTION
 *  register key handlers of asyncdynamic matrix menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_matrix_loop_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	register_navigation_key_handlers(
		asyncdynamic_matrix_goto_previous_row,
		asyncdynamic_matrix_goto_next_row,
		asyncdynamic_matrix_goto_previous_item,
		asyncdynamic_matrix_goto_next_item
	);
//    SetKeyHandler(asyncdynamic_matrix_goto_previous_row, KEY_UP_ARROW, KEY_EVENT_DOWN);
//    SetKeyHandler(asyncdynamic_matrix_goto_next_row, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
//    SetKeyHandler(asyncdynamic_matrix_goto_previous_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);    
//    SetKeyHandler(asyncdynamic_matrix_goto_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	
  //  SetKeyHandler(asyncdynamic_matrix_goto_previous_item, KEY_VOL_UP, KEY_EVENT_DOWN);
//	SetKeyHandler(asyncdynamic_matrix_goto_next_item, KEY_VOL_DOWN, KEY_EVENT_DOWN);

	register_vol_key_handlers(
		asyncdynamic_matrix_goto_previous_item,
		asyncdynamic_matrix_goto_next_item
	);
	
}


/*****************************************************************************
 * FUNCTION
 *  register_asyncdynamic_matrix_shortcut_handler
 * DESCRIPTION
 *  Register menu shortcut for the asyncdynamic matrix.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void register_asyncdynamic_matrix_shortcut_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
  //  register_menu_shortcut_keys();
    register_menu_shortcut_keys_and_handler(asyncdynamic_matrix_goto_item);
}
#endif  /* __MMI_SUPPORT_ASYNCDYNAMIC_MATRIX_MENU__ */


/*****************************************************************************
* FUNCTION
*  wgui_async_list_register_update_callback
* DESCRIPTION
*  Register asyncdynamic list update callback handler
* PARAMETERS
*  async_update_callback     :   [IN] Update callback funtion to update highlight index
* RETURNS
*  void
*****************************************************************************/
void wgui_async_list_register_update_callback(AsyncUpdateCallback async_update_callback)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_gui_async_list_update_callback = async_update_callback;
}


