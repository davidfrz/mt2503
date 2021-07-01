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
 *   wgui_tab_bars.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Tab Bar - Category component
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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_TAB_BARS_SUPPORT__

#include "wgui_tab_bars.h"
#include "gui_setting.h"
#include "mmi_frm_gprot.h"
#include "wgui_categories_util.h"
#include "wgui_include.h"

#include "MMIDataType.h"
#include "kal_general_types.h"
#include "gui_theme_struct.h"
#include "gui_tab_bars_pre_oem.h"
#include "gui_typedef.h"
#include "gui_title_pre_oem.h"
#include "gui_menu_shortcut.h"
#include "gdi_include.h"
#include "gui_title.h"
#include "wgui.h"
#include "gui_data_types.h"
#include "wgui_inputs.h"
#include "GlobalConstants.h"
#include "mmi_frm_input_gprot.h"
#include "gdi_datatype.h"
#include "gui_tab_bars.h"
#include "gui_switch.h"
#include "lcd_sw_inc.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_enum.h"
#include "gdi_const.h"
#include "gui.h"


#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
#include "GlobalResDef.h"
#include "fix_size_mem.h"
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */

#define MMI_CATEGORYTAB_ID MMI_CATEGORY425_ID
//huking
//extern U16 title_bg_id;

/***************************************************************************** 
* Define
*****************************************************************************/
/* To restore the first displayed item after tab bar is scrolled with pen */
#define WGUI_TAB_BAR_RESTORE_DISPLAY_TIME       (3000)

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/***************************************************************************** 
* Local Variable
*****************************************************************************/

/* Default value is -1. Used to set  the display area of tab bar when it enters a new screen. */
static S16 MMI_horizontal_tab_bar_first_displayed_on_screen_switched = -1;
static MMI_BOOL horizontal_tab_bar_use_pen_switch = MMI_FALSE;

#ifdef __MMI_TOUCH_SCREEN__

#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
/* Default value is -1. Used to store the display area of tab bar after pen is up. */
static S16 MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
static MMI_BOOL horizontal_tab_bar_disable_reset_offset = MMI_FALSE;
#endif
/* Used by wgui_horizontal_tab_bar_translate_pen_event() */
static void (*MMI_horizontal_tab_bar_select_callback) (int index);

/* special case: UCM not use tab page API to create tab page, all controlled by APP itself, 
and just use category to create and show tab bar. So UCM want to control tab bar pen event by callback func.
In this case, when set callback, set g_callback_tab_id = 0xFFFF; other case g_callback_tab_id is current tab id */
static MMI_ID g_callback_tab_id = GRP_ID_INVALID;
#endif /* __MMI_TOUCH_SCREEN__ */ 

UI_window_title_theme *current_tab_title_theme = NULL;
static MMI_BOOL wgui_tab_bar_no_title_shortcut = MMI_FALSE;
/***************************************************************************** 
* Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_title_bg_id
 * DESCRIPTION
 *  reset the tittle background image id of tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_title_bg_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    title_bg_id = 0;
}

/***************************************************************************** 
* Global Variable
*****************************************************************************/

horizontal_tab_bar MMI_horizontal_tab_bar;

tab_bar_item_type MMI_tab_bar_items[UI_MAX_TAB_BAR_ITEMS];
extern gui_title_struct g_wgui_title_bar;

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
static wgui_tab_struct MMI_tab_inst[MMI_MAX_TAB_INST];
static MMI_ID g_activeTabID = 0;
static void cui_tab_show_focused_screen(S8 select_index);
static MMI_ID cui_tab_get_active_tab_id(void);
#endif


/***************************************************************************** 
* Global Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  wgui_title_timer_callback
 * DESCRIPTION
 *  This function is called when the menu shortcut handler times out
 *  
 *  Internal function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL modify = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_title_set_menu_shortcut_handler_display(MMI_FALSE);
//    MMI_horizontal_tab_bar.title.sc.display = MMI_FALSE;
    wgui_title_disable_menu_shortcut_display(MMI_TRUE);
    MMI_horizontal_tab_bar.title.sc.input_buffer[0] = 0;
    gdi_layer_lock_frame_buffer();

    MMI_horizontal_tab_bar.title.pre_goto_callback(gui_shortcut_get_index(&MMI_horizontal_tab_bar.title.sc) - 1);
    if (wgui_title_get_menu_shortcut_number() == g_wgui_title_bar.sc.number + 1)
    {
        modify = MMI_TRUE;
    }
    gui_shortcut_set_index(&MMI_horizontal_tab_bar.title.sc, wgui_title_get_menu_shortcut_number());

    if (MMI_horizontal_tab_bar.title.icon2 == NULL)
    {
        wgui_horizontal_show(GUI_TITLE_PART_SHORTCUT);
    }
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (is_enable_animated_title_effect())
    {
        wgui_title_start_animation();
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 
    gdi_layer_unlock_frame_buffer();
    /* BLT together with the previous BLT region */
    gdi_layer_blt_previous(
        MMI_content_x,
        MMI_content_y,
        MMI_content_x + MMI_content_width - 1,
        MMI_content_y + MMI_content_height - 1);

    if (modify)
    {
        MMI_horizontal_tab_bar.title.goto_callback(gui_shortcut_get_index(&MMI_horizontal_tab_bar.title.sc) - 1);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_shortcut_show_background
 * DESCRIPTION
 *  This function is called when the menu shortcut handler times out
 *  
 *  Internal function
 * PARAMETERS
 *  x       [IN]        coordinate of show area
 *  y       [IN]        coordinate of show area
 *  w       [IN]        width of show area
 *  h       [IN]        height of show area
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_shortcut_show_background(S32 x, S32 y, S32 w, S32 h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar.title.icon2 == NULL)
    {
        gui_title_show_background(&MMI_horizontal_tab_bar.title, x, y, w, h);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_title_dummy_goto_item
 * DESCRIPTION
 *  Dummy function used in MMI
 * PARAMETERS
 *  index       [IN]        index of item
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_dummy_goto_item(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(index);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_pre_key_down
 * DESCRIPTION
 *  pre function of key down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_pre_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_ANIMATED_TITLE_EFFECT__
    if (is_enable_animated_title_effect())
    {
        gui_title_stop_animation(&MMI_horizontal_tab_bar.title);
    }
#endif /* __MMI_UI_ANIMATED_TITLE_EFFECT__ */ 

}



/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_1_key_down
 * DESCRIPTION
 *  key '1' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_1_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '1');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_2_key_down
 * DESCRIPTION
 *  key '2' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_2_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '2');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_3_key_down
 * DESCRIPTION
 *  key '3' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_3_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '3');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_4_key_down
 * DESCRIPTION
 *  key '4' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_4_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '4');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_5_key_down
 * DESCRIPTION
 *  key '5' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_5_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '5');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_6_key_down
 * DESCRIPTION
 *  key '6' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_6_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '6');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_7_key_down
 * DESCRIPTION
 *  key '7' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_7_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '7');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_8_key_down
 * DESCRIPTION
 *  key '8' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_8_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '8');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_9_key_down
 * DESCRIPTION
 *  key '9' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_9_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '9');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_0_key_down
 * DESCRIPTION
 *  key '0' resolve function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_0_key_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_horizontal_tab_bar_pre_key_down();
    gui_shortcut_handler_keyinput(&MMI_horizontal_tab_bar.title.sc, (UI_character_type) '0');
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_show
 * DESCRIPTION
 *  draw the title
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_redraw(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_shortcut_set_index(&MMI_horizontal_tab_bar.title.sc, wgui_title_get_menu_shortcut_number());
    if (MMI_horizontal_tab_bar.title.has_title == MMI_TRUE)
    {
        wgui_horizontal_show(GUI_TITLE_PART_SHORTCUT);
    }
        
}



/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_show
 * DESCRIPTION
 *  draw the title
 * PARAMETERS
 *  part        [IN]        draw a part of title
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_show(U32 part)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL bitblt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_enable_integrated(MMI_FALSE);
#endif
    bitblt = gui_title_show(&MMI_horizontal_tab_bar.title, part);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_enable_integrated(MMI_TRUE);
#endif
#ifdef __MMI_FTE_SUPPORT__
    /* FTE will should show tab items after show tab title, because tab item overlap title */
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_FALSE, MMI_FALSE);
#endif
    if (bitblt)
    {
        gdi_layer_blt_previous(
            MMI_horizontal_tab_bar.title.x,
            MMI_horizontal_tab_bar.title.y,
            MMI_horizontal_tab_bar.title.x + MMI_horizontal_tab_bar.title.width - 1,
            MMI_horizontal_tab_bar.title.y + MMI_horizontal_tab_bar.title.height - 1);
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_set_shortcut_count
 * DESCRIPTION
 *  Sets the number of digits allowed in the menu shortcut
 *  handler. This is based on the number of items in the menu.
 * PARAMETERS
 *  n_items     [IN]        number of digits allowed in the menu shortcut
 *                          handler
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_set_shortcut_count(S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 width;
    S32 pre_width;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    pre_width = gui_shortcut_auto_resize(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.height);
    gui_shortcut_set_item_count(&MMI_horizontal_tab_bar.title.sc, n_items);
    width = gui_shortcut_auto_resize(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.height);
    if (mmi_fe_get_r2l_state())
    {
        gui_shortcut_move(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.x, MMI_horizontal_tab_bar.title.y);
    }
    else
    {
        gui_shortcut_move(&MMI_horizontal_tab_bar.title.sc, MMI_horizontal_tab_bar.title.width - width, MMI_horizontal_tab_bar.title.y);
    }

    
    if(pre_width != width)
    {
        if(MMI_horizontal_tab_bar.title.show_text == MMI_TRUE)
        {
            wgui_horizontal_show(GUI_TITLE_PART_ALL);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_shortcut_register_callback
 * DESCRIPTION
 *  Registers the keys used by the menu shortcut handler
 * PARAMETERS
 *  pre_goto_funcptr        [IN]      pre goto function pointer  
 *  goto_funcptr            [IN]      goto function pointer  
 *  flag                    [IN]      flag
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_shortcut_register_callback(void (*pre_goto_funcptr) (S32 i), void (*goto_funcptr) (S32 i), U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_title_register_callback(&MMI_horizontal_tab_bar.title, pre_goto_funcptr, goto_funcptr, flag);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_register_keys
 * DESCRIPTION
 *  Registers the keys used by the menu shortcut handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_register_keys(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
/*    SetKeyHandler(wgui_horizontal_tab_bar_0_key_down, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_1_key_down, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_2_key_down, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_3_key_down, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_4_key_down, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_5_key_down, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_6_key_down, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_7_key_down, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_8_key_down, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(wgui_horizontal_tab_bar_9_key_down, KEY_9, KEY_EVENT_DOWN);
*/
    SetKeyDownHandler(wgui_horizontal_tab_bar_0_key_down, KEY_0);
    SetKeyDownHandler(wgui_horizontal_tab_bar_1_key_down, KEY_1);
    SetKeyDownHandler(wgui_horizontal_tab_bar_2_key_down, KEY_2);
    SetKeyDownHandler(wgui_horizontal_tab_bar_3_key_down, KEY_3);
    SetKeyDownHandler(wgui_horizontal_tab_bar_4_key_down, KEY_4);
    SetKeyDownHandler(wgui_horizontal_tab_bar_5_key_down, KEY_5);
    SetKeyDownHandler(wgui_horizontal_tab_bar_6_key_down, KEY_6);
    SetKeyDownHandler(wgui_horizontal_tab_bar_7_key_down, KEY_7);
    SetKeyDownHandler(wgui_horizontal_tab_bar_8_key_down, KEY_8);
    SetKeyDownHandler(wgui_horizontal_tab_bar_9_key_down, KEY_9);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_setup_horizontal_tab_bar_no_title_shortcut
 * DESCRIPTION
 *  Set tab bar not shortcut in title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_setup_horizontal_tab_bar_no_title_shortcut(void)
{
    wgui_tab_bar_no_title_shortcut = MMI_TRUE;

    gui_shortcut_create_ex(
        &MMI_horizontal_tab_bar.title.sc,
        MMI_horizontal_tab_bar.title.x,
        MMI_horizontal_tab_bar.title.y,
        MMI_horizontal_tab_bar.title.width,
        MMI_horizontal_tab_bar.title.height,
        MMI_horizontal_tab_bar.target_lcd,
        MMI_horizontal_tab_bar.target_layer,
        MMI_horizontal_tab_bar.alpha_blend_layer);
    gui_shortcut_register_callback(
        &MMI_horizontal_tab_bar.title.sc,
        wgui_horizontal_tab_bar_timer_callback,
        wgui_horizontal_tab_bar_shortcut_show_background);
    gui_title_set_theme(&MMI_horizontal_tab_bar.title, current_tab_title_theme);
    gui_title_set_no_icon_shct(&MMI_horizontal_tab_bar.title, MMI_FALSE);

    gui_shortcut_set_show(&MMI_horizontal_tab_bar.title.sc, MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_create_horizontal_tab_bar_ex
 * DESCRIPTION
 *  Cerate horizontal tab bar component in category
 * PARAMETERS
 *  contain_hint            [IN]        Whether the tab bar contains hint area
 *  hint                    [IN]        string of hint
 *  n_item                  [IN]        number of tabs
 *  focused_item            [IN]        focused tab index
 *  keep_context            [IN]        keep context or not
 *  target_lcd              [IN]        target lcd of tab bar
 *  target_layer            [IN]        target layer of tab bar
 *  alpha_blend_layer       [IN]        alpha blend layer of tab bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_create_horizontal_tab_bar_ex(
        BOOL contain_hint,
        UI_string_type hint,
        S8 n_item,
        S8 focused_item,
	S16 width,
	S16 focused_width,
	S16 tab_gap,
        MMI_BOOL keep_context,
        U32 style,
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
    if (n_item > UI_MAX_TAB_BAR_ITEMS)
    {
        n_item = UI_MAX_TAB_BAR_ITEMS;
    }

    gui_create_horizontal_tab_bar_ex(
        &MMI_horizontal_tab_bar,
        MMI_HORIZONTAL_TAB_BAR_X,
        MMI_HORIZONTAL_TAB_BAR_Y,
        MMI_HORIZONTAL_TAB_BAR_WIDTH,
        MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT,
        (S16) (contain_hint ? MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT : 0),
        width,
        focused_width,//MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH
	tab_gap,
        hint,
        n_item,
        focused_item,
        style,
        MMI_tab_bar_items,
        target_lcd,
        target_layer,
        alpha_blend_layer);

    if (contain_hint)
    {
        gui_title_create_ex(
            &MMI_horizontal_tab_bar.title,
            MMI_horizontal_tab_bar.x,
            MMI_horizontal_tab_bar.y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT,
            MMI_horizontal_tab_bar.width,
            MMI_HORIZONTAL_TAB_BAR_HINT_AREA_HEIGHT,
            target_lcd,
            target_layer,
            alpha_blend_layer);

        gui_title_change(&MMI_horizontal_tab_bar.title, (PU8)MMI_horizontal_tab_bar.hint_icon, NULL, (U8*)MMI_horizontal_tab_bar.hint);
        gui_shortcut_create_ex(
            &MMI_horizontal_tab_bar.title.sc,
            MMI_horizontal_tab_bar.title.x,
            MMI_horizontal_tab_bar.title.y,
            MMI_horizontal_tab_bar.title.width,
            MMI_horizontal_tab_bar.title.height,
            target_lcd,
            target_layer,
            alpha_blend_layer);
        gui_shortcut_register_callback(
            &MMI_horizontal_tab_bar.title.sc,
            wgui_horizontal_tab_bar_timer_callback,
            wgui_horizontal_tab_bar_shortcut_show_background);
        gui_title_set_theme(&MMI_horizontal_tab_bar.title, current_tab_title_theme);
        gui_title_set_no_icon_shct(&MMI_horizontal_tab_bar.title, MMI_FALSE);
    }

    MMI_horizontal_tab_bar.flags |= UI_TAB_BAR_LOOP;
    gui_horizontal_tab_bar_set_icon_position(&MMI_horizontal_tab_bar, 13, 5);
    if (g_dm_data.s32CatId == 0)
    {
        g_dm_data.s32CatId = MMI_CATEGORYTAB_ID;
    }

    if (!keep_context)
    {
    #ifdef __MMI_TOUCH_SCREEN__
        //MMI_horizontal_tab_bar_select_callback = NULL;
    
    #ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
        MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
    #endif

    #endif /* __MMI_TOUCH_SCREEN__ */
        if(MMI_horizontal_tab_bar_first_displayed_on_screen_switched > -1)
        {
            gui_set_horizontal_tab_bar_display_range(
                &MMI_horizontal_tab_bar,
                (S32)MMI_horizontal_tab_bar_first_displayed_on_screen_switched);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_create_horizontal_tab_bar
 * DESCRIPTION
 *  Cerate horizontal tab bar component in category
 * PARAMETERS
 *  contain_hint            [IN]        Whether the tab bar contains hint area
 *  hint                    [IN]        string of hint
 *  n_item                  [IN]        number of tabs
 *  focused_item            [IN]        focused tab index
 *  keep_context            [IN]        keep context or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_create_horizontal_tab_bar(
        BOOL contain_hint,
        UI_string_type hint,
        S8 n_item,
        S8 focused_item,
        MMI_BOOL keep_context)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_create_horizontal_tab_bar_ex(
        contain_hint,
        hint,
        n_item,
        focused_item,
	MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH,
	MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH,
	GUI_TAB_GAP,
        keep_context,
        GUI_TAB_BAR_STYLE_DEFAULT,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_create_horizontal_tab_bar_with_style
 * DESCRIPTION
 *  Cerate horizontal tab bar component in category
 * PARAMETERS
 *  contain_hint            [IN]        Whether the tab bar contains hint area
 *  hint                    [IN]        string of hint
 *  n_item                  [IN]        number of tabs
 *  focused_item            [IN]        focused tab index
 *  keep_context            [IN]        keep context or not
 *  style                   [IN]        style of horizontal tab bar
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_create_horizontal_tab_bar_with_style(
        BOOL contain_hint,
        UI_string_type hint,
        S8 n_item,
        S8 focused_item,
        MMI_BOOL keep_context,
        U32 style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_create_horizontal_tab_bar_ex(
        contain_hint,
        hint,
        n_item,
        focused_item,
	MMI_HORIZONTAL_TAB_BAR_TAB_WIDTH,
	MMI_HORIZONTAL_TAB_BAR_FOCUSED_TAB_WIDTH,
	GUI_TAB_GAP,
        keep_context,
        style,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE,
        GDI_NULL_HANDLE);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_close_horizontal_tab_bar
 * DESCRIPTION
 *  Close the horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_close_horizontal_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_close(&MMI_horizontal_tab_bar);
    MMI_horizontal_tab_bar.title.pre_goto_callback = wgui_horizontal_tab_bar_dummy_goto_item;
    MMI_horizontal_tab_bar.title.goto_callback = wgui_horizontal_tab_bar_dummy_goto_item;
    wgui_tab_bar_no_title_shortcut = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_title
 * DESCRIPTION
 *  set the horizontal tab bar title
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_title(PU8 icon, UI_string_type text)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_horizontal_tab_bar.hint_icon = icon;
    MMI_horizontal_tab_bar.hint = text;
    gui_title_change(&MMI_horizontal_tab_bar.title, (PU8)MMI_horizontal_tab_bar.hint_icon, NULL, (U8*)MMI_horizontal_tab_bar.hint);

}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_scroll(void)
{
    gui_title_set_style(&MMI_horizontal_tab_bar.title, GUI_TITLE_STYLE_SCROLLING);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_reset_horizontal_tab_bar_scroll
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_reset_horizontal_tab_bar_scroll(void)
{
    gui_title_unset_style(&MMI_horizontal_tab_bar.title, GUI_TITLE_STYLE_SCROLLING);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar
 * DESCRIPTION
 *  Show the horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_horizontal_tab_bar(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar.theme->hint_bg_image )//&& title_bg_id == 0
    {
        //title_bg_id = MMI_horizontal_tab_bar.theme->hint_bg_image;
        gui_add_cleanup_hook(wgui_horizontal_tab_bar_reset_title_bg_id);
    }
    gui_lock_double_buffer();
    
    if (!wgui_tab_bar_no_title_shortcut)
    {
        gui_title_change(&MMI_horizontal_tab_bar.title, (PU8)MMI_horizontal_tab_bar.hint_icon, NULL, (U8*)MMI_horizontal_tab_bar.hint);
    #ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        wgui_status_icon_bar_enable_integrated(MMI_FALSE);
    #endif
        gui_title_show(&MMI_horizontal_tab_bar.title, GUI_TITLE_PART_ALL);
    #ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
        wgui_status_icon_bar_enable_integrated(MMI_TRUE);
    #endif
    }
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_FALSE, MMI_FALSE);
    
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.height - 1);

    gui_horizontal_tab_bar_start_blinking(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar_hint_area
 * DESCRIPTION
 *  show hint area of tab
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_show_horizontal_tab_bar_hint_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_enable_integrated(MMI_FALSE);
#endif
    gui_title_show(&MMI_horizontal_tab_bar.title, GUI_TITLE_PART_ALL);
#ifdef MMI_SHOW_STATUS_ICON_IN_TITLE
    wgui_status_icon_bar_enable_integrated(MMI_TRUE);
#endif
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_TRUE, MMI_FALSE);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.tab_area_height,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_show_horizontal_tab_bar_tab_area
 * DESCRIPTION
 *  show tab area of tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * REMARKS
 *  Used in category 435 that popup overlaps with hint area, and we do not want to redraw the
 *  whole screen. As a result, we redraw the tab area only.
 *****************************************************************************/
void wgui_show_horizontal_tab_bar_tab_area(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_lock_double_buffer();
    gui_show_horizontal_tab_bar(&MMI_horizontal_tab_bar, MMI_FALSE, MMI_TRUE);
    gui_unlock_double_buffer();
    gui_BLT_double_buffer(
        MMI_horizontal_tab_bar.x,
        MMI_horizontal_tab_bar.y,
        MMI_horizontal_tab_bar.x + MMI_horizontal_tab_bar.width - 1,
        MMI_horizontal_tab_bar.y + MMI_horizontal_tab_bar.tab_area_height - 1);

    gui_horizontal_tab_bar_start_blinking(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_move_horizontal_tab_bar
 * DESCRIPTION
 *  Move the horizontal tab bar
 * PARAMETERS
 *  x       [IN]        new position
 *  y       [IN]        new position
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_move_horizontal_tab_bar(S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_move_horizontal_tab_bar(&MMI_horizontal_tab_bar, x, y);
    gui_title_move(
        &MMI_horizontal_tab_bar.title, 
        x, 
        y + MMI_HORIZONTAL_TAB_BAR_TAB_AREA_HEIGHT);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_home
 * DESCRIPTION
 *  Focus the first item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_home(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_first_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_show_focused_screen((S8)MMI_horizontal_tab_bar.focused_item);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_end
 * DESCRIPTION
 *  Focus the last item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_end(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_last_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_show_focused_screen((S8)MMI_horizontal_tab_bar.focused_item);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_item
 * DESCRIPTION
 *  Focus certain item of horizontal tab bar
 * PARAMETERS
 *  index       [IN]        Item index
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_item(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_item(&MMI_horizontal_tab_bar, (S8) index);
    wgui_show_horizontal_tab_bar();

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_show_focused_screen((S8)MMI_horizontal_tab_bar.focused_item);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_next_item
 * DESCRIPTION
 *  Focus the next item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_next_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_next_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();
    
#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_show_focused_screen((S8)MMI_horizontal_tab_bar.focused_item);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_goto_prev_item
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_goto_prev_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_focus_prev_item(&MMI_horizontal_tab_bar);
    wgui_show_horizontal_tab_bar();

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    cui_tab_show_focused_screen((S8)MMI_horizontal_tab_bar.focused_item);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_blinking
 * DESCRIPTION
 *  Start the blinking of certain tab
 * PARAMETERS
 *  index       [IN]        Index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_start_blinking(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_tab_bar_items[index].flags |= UI_TAB_BAR_ITEM_STATE_BLINKING;

#if 0
#ifdef __MMI_OP11_TAB_BAR__
/* under construction !*/
#endif
#endif
}

/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_blinking
 * DESCRIPTION
 *  Start the blinking of certain tab
 * PARAMETERS
 *  index       [IN]        Index of the item
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_disabled(S32 index, MMI_BOOL disabled)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (disabled)
    {
        MMI_tab_bar_items[index].flags |= UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED;
    }
    else
    {
        MMI_tab_bar_items[index].flags &= ~UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_blinking
 * DESCRIPTION
 *  Start the blinking of certain tab
 * PARAMETERS
 *  index       [IN]        Index of the item
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL wgui_horizontal_tab_bar_is_disabled(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_tab_bar_items[index].flags & UI_TAB_BAR_ITEM_STATE_DISABLED_DISPLAYED)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_stop_blinking
 * DESCRIPTION
 *  Stop the blinking of certain tab
 * PARAMETERS
 *  index       [IN]      index of the item  
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_stop_blinking(int index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 old_flags;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    old_flags = MMI_tab_bar_items[index].flags;

    MMI_tab_bar_items[index].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING;
    MMI_tab_bar_items[index].flags &= ~UI_TAB_BAR_ITEM_STATE_BLINKING_DISPLAYED;

#if 0
#ifdef __MMI_OP11_TAB_BAR__
/* under construction !*/
#endif
#endif
    /* We need to refresh the tab bar */
    if ((old_flags & UI_TAB_BAR_ITEM_STATE_BLINKING) &&
        gui_horizontal_tab_bar_is_item_displayed(&MMI_horizontal_tab_bar, index))
    {
        wgui_show_horizontal_tab_bar();
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_get_horizontal_tab_bar_history
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  history     [OUT]   store tab bar history     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_get_horizontal_tab_bar_history(wgui_tab_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    history->flags = MMI_horizontal_tab_bar.flags;
    history->first_displayed_item = MMI_horizontal_tab_bar.first_displayed_item;
    history->last_displayed_item = MMI_horizontal_tab_bar.last_displayed_item;
    history->focused_item = MMI_horizontal_tab_bar.focused_item;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_history
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  history     [IN] history of tab bar     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_history(wgui_tab_bar_history_struct *history)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_horizontal_tab_bar.flags = history->flags;
    MMI_horizontal_tab_bar.first_displayed_item = history->first_displayed_item;
    MMI_horizontal_tab_bar.last_displayed_item = history->last_displayed_item;
    MMI_horizontal_tab_bar.focused_item = history->focused_item;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_set_target_lcd
 * DESCRIPTION
 *  set horizontal tab bar target lcd
 * PARAMETERS
 *  target_lcd    [IN] the new target lcd of tab bar     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_target_lcd(gdi_handle target_lcd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_set_target_lcd(&MMI_horizontal_tab_bar, target_lcd);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_get_target_lcd
 * DESCRIPTION
 *  get horizontal tab bar target lcd
 * PARAMETERS
 *  void     
 * RETURNS
 *  the target lcd handle of tab bar
 *****************************************************************************/
gdi_handle wgui_horizontal_tab_bar_get_target_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_horizontal_tab_bar_get_target_lcd(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_target_lcd
 * DESCRIPTION
 *  reset horizontal tab bar target lcd
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_target_lcd(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_reset_target_lcd(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_set_target_layer
 * DESCRIPTION
 *  set horizontal tab bar target layer
 * PARAMETERS
 *  target_layer    [IN]    the new target layer of tab bar     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_target_layer(gdi_handle target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_set_target_layer(&MMI_horizontal_tab_bar, target_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_get_target_layer
 * DESCRIPTION
 *  get horizontal tab bar target layer
 * PARAMETERS
 *  void     
 * RETURNS
 *  the target layer of tab bar
 *****************************************************************************/
gdi_handle wgui_horizontal_tab_bar_get_target_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_horizontal_tab_bar_get_target_lcd(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_target_layer
 * DESCRIPTION
 *  reset horizontal tab bar target layer
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_target_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_reset_target_layer(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_set_alpha_blend_layer
 * DESCRIPTION
 *  set horizontal tab bar alpha_blend_layer
 * PARAMETERS
 *  alpha_blend_layer    [IN]   the new alpha_blend_layer of tab bar     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_alpha_blend_layer(gdi_handle alpha_blend_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_set_alpha_blend_layer(&MMI_horizontal_tab_bar, alpha_blend_layer);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_get_alpha_blend_layer
 * DESCRIPTION
 *  get horizontal tab bar alpha_blend_layer
 * PARAMETERS
 *  void     
 * RETURNS
 *  the alpha blend layer of tab bar
 *****************************************************************************/
gdi_handle wgui_horizontal_tab_bar_get_alpha_blend_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return gui_horizontal_tab_bar_get_alpha_blend_layer(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_alpha_blend_layer
 * DESCRIPTION
 *  reset horizontal tab bar alpha_blend_layer
 * PARAMETERS
 *  void     
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_alpha_blend_layer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_horizontal_tab_bar_reset_alpha_blend_layer(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_register_hide_callback
 * DESCRIPTION
 *  register horizontal tab bar hide callback
 * PARAMETERS
 *  hide_callback       [IN]    the new hide callback function 
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_register_hide_callback(void (*hide_callback)(S32 x1, S32 y1, S32 x2, S32 y2))
{
    gui_horizontal_tab_bar_register_hide_callback (&MMI_horizontal_tab_bar, hide_callback);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_hide_callback
 * DESCRIPTION
 *  reset the tab bar's hide callback function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_hide_callback(void)
{
    gui_horizontal_tab_bar_reset_hide_callback(&MMI_horizontal_tab_bar);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_store_first_displayed_item
 * DESCRIPTION
 *  store the horizontal tab bar first displayed item index
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_store_first_displayed_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    horizontal_tab_bar_use_pen_switch = MMI_FALSE;
    MMI_horizontal_tab_bar_first_displayed_on_screen_switched = MMI_horizontal_tab_bar.first_displayed_item;
}


/*****************************************************************************
 * FUNCTION
 *  MMI_horizontal_tab_bar_first_displayed_on_screen_switched
 * DESCRIPTION
 *  Set the horizontal tab bar first displayed item index;
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_first_displayed_item(S8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_horizontal_tab_bar_first_displayed_on_screen_switched = index;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_get_first_displayed_item
 * DESCRIPTION
 *  Get the horizontal tab bar first displayed item index
 * PARAMETERS
 *  void    
 * RETURNS
 *  The tab bar first displayed item index
 *****************************************************************************/
S8 wgui_horizontal_tab_bar_get_first_displayed_item(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return MMI_horizontal_tab_bar.first_displayed_item;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_set_use_pen_switch
 * DESCRIPTION
 *  Set the horizontal tab bar first displayed item index;
 * PARAMETERS
 *  void    
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_use_pen_switch(MMI_BOOL use_pen_switch)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    horizontal_tab_bar_use_pen_switch = use_pen_switch;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_get_use_pen_switch
 * DESCRIPTION
 *  Get the horizontal tab bar first displayed item index
 * PARAMETERS
 *  void    
 * RETURNS
 *  The tab bar first displayed item index
 *****************************************************************************/
MMI_BOOL wgui_horizontal_tab_bar_get_use_pen_switch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return horizontal_tab_bar_use_pen_switch;
}

#if 0
#ifdef __MMI_WGUI_MINI_TAB_BAR__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WGUI_MINI_TAB_BAR__ */ 
#endif


#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ 
/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_select_callback_ex
 * DESCRIPTION
 *  If app want to control tab bar pen select action, app can use this API to set select_callback function.
 *  if app use tab page API to create tab page,
 *           g_callback_tab_id is current tab id, such as ucm app.
 *  if app not use tab page API to create tab page, just use category to show tab bar, all others are 
 *  controlled by app itselt,
 *           g_callback_tab_id is 0xFFFF, such as UM app,
 *  UM app is a special case, and it will modify to follow standard tab page flow.
 * PARAMETERS
 *  select_callback     [IN]        select callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_select_callback_ex(void (*select_callback) (int index))
{
#ifdef __MMI_TOUCH_SCREEN__
    if (cui_tab_is_in_tab_screen())
    {
        g_callback_tab_id = cui_tab_get_active_tab_id();       
    }
    else
    {
        g_callback_tab_id = 0xFFFF;
    }
    MMI_horizontal_tab_bar_select_callback = select_callback;
#endif
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_reset_horizontal_tab_bar_select_callback_ex
 * DESCRIPTION
 *  reset select_callback func. 
 *  if app use tab page API to create tab page, reset select_callback at the time of unint tab page, such as ucm app.
 *  if app not use tab page API to create tab page, just use category to show tab bar, all others are 
 *  controlled by app itselt, reset select_callback at the time when others use cui_tab_create, such as UM app,
 *  UM app is a special case, and it will modify to follow standard tab page flow.
 *  tab_id     [IN]       current tab id
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_reset_horizontal_tab_bar_select_callback_ex(MMI_ID tab_id)
{
    if(MMI_horizontal_tab_bar_select_callback && (g_callback_tab_id == tab_id || g_callback_tab_id == 0xFFFF))            
    {        
        MMI_horizontal_tab_bar_select_callback = NULL;
        g_callback_tab_id = GRP_ID_INVALID;
    }    
}
#endif

#else /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */
/*****************************************************************************
 * FUNCTION
 *  wgui_set_horizontal_tab_bar_select_callback
 * DESCRIPTION
 *  Focus the previous item of horizontal tab bar
 * PARAMETERS
 *  select_callback     [IN]        select callback function
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_set_horizontal_tab_bar_select_callback(void (*select_callback) (int index))
{
#ifdef __MMI_TOUCH_SCREEN__
    MMI_horizontal_tab_bar_select_callback = select_callback;
#endif
}
#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */



#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_enable_horizontal_tab_bar_pen_events
 * DESCRIPTION
 *  Handle pen events in horizontal tab bar and
 * PARAMETERS
 *  enable      [IN]        enable pen event or not
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_enable_horizontal_tab_bar_pen_events(BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (enable)
    {
        MMI_horizontal_tab_bar.flags &= ~UI_TAB_BAR_DISABLE_PEN;
    }
    else
    {
        MMI_horizontal_tab_bar.flags |= UI_TAB_BAR_DISABLE_PEN;
    }
}


#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_restore_offset_timer_hdlr
 * DESCRIPTION
 *  Handle pen events in horizontal tab bar and
 * PARAMETERS
 *  void
 *  tb(?)
 *  pen_event(?)
 *  x(?)
 *  y(?)
 * RETURNS
 *  void
 *****************************************************************************/
/* Timer handler to restore the display range of tab bar */
static void wgui_horizontal_tab_bar_restore_offset_timer_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar_first_displayed_before_pen_down >= 0)
    {
        if (horizontal_tab_bar_disable_reset_offset)
        {
            gui_start_timer(WGUI_TAB_BAR_RESTORE_DISPLAY_TIME, wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
        }
        else
        {
            gui_set_horizontal_tab_bar_display_range(
                &MMI_horizontal_tab_bar,
                MMI_horizontal_tab_bar_first_displayed_before_pen_down);
            wgui_show_horizontal_tab_bar_tab_area();
            
            MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_abort_restore_offset_timer
 * DESCRIPTION
 *  abort restore offset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_abort_restore_offset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
}

/* Start timer to restore the display range of tab bar */


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_start_restore_offset_timer
 * DESCRIPTION
 *  start restore offset timer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_horizontal_tab_bar_start_restore_offset_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (MMI_horizontal_tab_bar_first_displayed_before_pen_down >= 0)
    {
        gui_start_timer(WGUI_TAB_BAR_RESTORE_DISPLAY_TIME, wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
        gui_add_cleanup_hook(wgui_horizontal_tab_bar_abort_restore_offset_timer);
    }
}

#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_translate_pen_event
 * DESCRIPTION
 *  translate pen event function
 * PARAMETERS
 *  pen_event       [IN]       pen event 
 *  x               [IN]       pen position
 *  y               [IN]       pen position
 * RETURNS
 *  
 *****************************************************************************/
BOOL wgui_horizontal_tab_bar_translate_pen_event(mmi_pen_event_type_enum pen_event, S16 x, S16 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    BOOL ret;
    gui_tab_bar_pen_enum tab_event;
    gui_pen_event_param_struct tab_param;
    horizontal_tab_bar *tb = &MMI_horizontal_tab_bar;
#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
    S32 prev_fdisp; /* first displayed item before pen down */
    S32 prev_focus; /* focused item before pen down */
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
    prev_fdisp = tb->first_displayed_item;
    prev_focus = tb->focused_item;
#endif
    ret = gui_horizontal_tab_bar_translate_pen_event(tb, pen_event, x, y, &tab_event, &tab_param);

    if (ret)
    {
        #ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
        if (pen_event == MMI_PEN_EVENT_DOWN)
        {
            gui_cancel_timer(wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
            if (MMI_horizontal_tab_bar_first_displayed_before_pen_down < 0)
            {
                MMI_horizontal_tab_bar_first_displayed_before_pen_down = prev_fdisp;
            }
        }
        #endif

        horizontal_tab_bar_use_pen_switch = MMI_TRUE;
        MMI_horizontal_tab_bar_first_displayed_on_screen_switched = tb->first_displayed_item;
        if (tab_event == GUI_TAB_BAR_PEN_NEED_REDRAW)
        {
            wgui_show_horizontal_tab_bar_tab_area();
        }
        else if (tab_event == GUI_TAB_BAR_PEN_JUMP_TO_I)
        {        

        #ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
            if (MMI_horizontal_tab_bar_select_callback && 
                ((cui_tab_is_in_tab_screen() && g_callback_tab_id == cui_tab_get_active_tab_id())
                || (!cui_tab_is_in_tab_screen() && g_callback_tab_id == 0xFFFF)))
            {
                MMI_horizontal_tab_bar_select_callback(tab_param._u.i);                
            }
            else
            {
                wgui_horizontal_tab_bar_goto_item(tab_param._u.i);
            }
        #else  
            if (MMI_horizontal_tab_bar_select_callback)            
            {
                //MMI_horizontal_tab_bar_first_displayed_on_screen_switched = tb->first_displayed_item;
                MMI_horizontal_tab_bar_select_callback(tab_param._u.i);
                //MMI_horizontal_tab_bar_first_displayed_on_screen_switched = -1;
            }
        #endif
        }
        
        #ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
        if ((pen_event == MMI_PEN_EVENT_ABORT || pen_event == MMI_PEN_EVENT_UP) &&
            MMI_horizontal_tab_bar.focused_item == prev_focus &&
            MMI_horizontal_tab_bar.first_displayed_item != MMI_horizontal_tab_bar_first_displayed_before_pen_down)
        {
            if (gui_horizontal_tab_bar_is_item_displayed(tb, tb->focused_item))
            {
                MMI_horizontal_tab_bar_first_displayed_before_pen_down = -1;
            }
            else
            {
                wgui_horizontal_tab_bar_start_restore_offset_timer();
            }
        }
        #endif
        
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_set_disable_reset_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void wgui_horizontal_tab_bar_set_disable_reset_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
    horizontal_tab_bar_disable_reset_offset = MMI_TRUE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_horizontal_tab_bar_reset_disable_reset_offset
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
void wgui_horizontal_tab_bar_reset_disable_reset_offset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TAB_BAR_AUTO_RESTORE_HIGHLIGHT__
    horizontal_tab_bar_disable_reset_offset = MMI_FALSE;
    gui_cancel_timer(wgui_horizontal_tab_bar_restore_offset_timer_hdlr);
    wgui_horizontal_tab_bar_restore_offset_timer_hdlr();
#endif
}

#endif /* __MMI_TOUCH_SCREEN__ */ 


#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__


/*****************************************************************************
 * FUNCTION
 *  cui_tab_uninit_info
 * DESCRIPTION
 *  after close all tab related screen, tab info will be free. 
 * PARAMETERS
 *  tab_id        [IN]        tab id  
 * RETURNS
 *  MMI_TRUE         the related tab is found, tab info free successful. 
 *  MMI_FALSE       the related tab can not found, tab info not free. 
 *****************************************************************************/
static MMI_BOOL cui_tab_uninit_info(MMI_ID tab_id)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
#ifdef __MMI_TOUCH_SCREEN__   
    wgui_reset_horizontal_tab_bar_select_callback_ex(tab_id);
#endif

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if (MMI_tab_inst[i].tab_id == tab_id)
        { 
            MMI_tab_inst[i].group_id = 0;
            MMI_tab_inst[i].tab_id = 0;            
            MMI_tab_inst[i].sel_idx = 0;
            MMI_tab_inst[i].user_data = NULL;
           
            for(j = 0; j < MMI_tab_inst[i].tab_pages_count; j++)
            {
                MMI_tab_inst[i].tab_bar_info[j].screen_id = 0;
                MMI_tab_inst[i].tab_bar_info[j].tab_entry_func = NULL;
                MMI_tab_inst[i].tab_bar_info[j].tab_icon = NULL;
                MMI_tab_inst[i].tab_bar_info[j].tab_string = NULL;
                MMI_tab_inst[i].tab_bar_info[j].user_data = NULL;

                if(MMI_tab_inst[i].gui_buf[j])
                {
                    mmi_frm_free(MMI_tab_inst[i].gui_buf[j]);
                    MMI_tab_inst[i].gui_buf[j] = NULL;  
                    //MMI_tab_inst[i].gui_buf_size[j] = 0;
                }
                if(MMI_tab_inst[i].input_buf[j])
                {
                    mmi_frm_free(MMI_tab_inst[i].input_buf[j]);
                    MMI_tab_inst[i].input_buf[j] = NULL;
                    //MMI_tab_inst[i].input_buf_size[j] = 0;    
                }
            }   
            MMI_tab_inst[i].tab_pages_count = 0;
            
            return MMI_TRUE;
        }
    }
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_tab_proc
 * DESCRIPTION
 *   when all tab related screen closed, or screen go back, tab will be close.
 * PARAMETERS
 *  evt                [IN]           group proc event        
 * RETURNS
 *  MMI_RET_OK
 *****************************************************************************/
static MMI_RET cui_tab_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    wgui_tab_struct *inst;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    inst = (wgui_tab_struct*) evt->user_data;

    switch(evt->evt_id)
    { 
        case EVT_ID_GROUP_FOCUSED:
        {
            if(mmi_frm_shell_is_in_backward_scenario())
            {                
                mmi_frm_group_close(inst->tab_id);   
            }
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
            cui_tab_uninit_info(inst->tab_id);                 
            break;
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  cui_tab_create
 * DESCRIPTION
 *  app use cui_tab_create to set tab info and enter tab screen.
 * PARAMETERS
 *  group_id                     [IN]      app group id of tab screen  
 *  tab_id                        [IN]      tab id
 *  tab_pages_info_array    [IN]      tab pages info
 *  tab_pages_count         [IN]       total tab page num
 *  sel_idx                       [IN]       the page screen will show
 *  user_data                   [IN]       app user data
 * RETURNS
 *  MMI_FALSE         tab create false
 *  MMI_TRUE          tab create success
 *****************************************************************************/
MMI_BOOL cui_tab_create(MMI_ID group_id, MMI_ID tab_id, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_TOUCH_SCREEN__
    wgui_reset_horizontal_tab_bar_select_callback_ex(tab_id);
#endif 

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        /*tab have created, just update info*/
        if(MMI_tab_inst[i].group_id == group_id && MMI_tab_inst[i].tab_id == tab_id)
        {
            return cui_tab_update_info(group_id, tab_id, tab_pages_info_array, tab_pages_count, sel_idx, user_data);
        }
    }

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if (MMI_tab_inst[i].tab_id == 0)
        {
            g_activeTabID = tab_id;
        
            MMI_tab_inst[i].group_id = group_id;
            MMI_tab_inst[i].tab_id = tab_id;
            MMI_tab_inst[i].tab_pages_count = tab_pages_count;
            MMI_tab_inst[i].sel_idx = sel_idx;
            MMI_tab_inst[i].user_data = user_data;

            for(j=0; j<tab_pages_count; j++)
            {
                MMI_tab_inst[i].tab_bar_info[j]= tab_pages_info_array[j];

                MMI_tab_inst[i].gui_buf[j] = NULL;
                MMI_tab_inst[i].input_buf[j] = NULL;
            }
            break;
        }
    }

    if(i >= MMI_MAX_TAB_INST)
        return MMI_FALSE;

    mmi_frm_group_create(group_id, tab_id, cui_tab_proc, &MMI_tab_inst[i]);
    mmi_frm_group_enter(tab_id, MMI_FRM_NODE_NONE_FLAG );

    cui_tab_show_focused_screen((S8)sel_idx);
    g_activeTabID = 0;
    
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  cui_tab_enter
 * DESCRIPTION
 * enter tab page
 * PARAMETERS
 *  parent_id :         [IN] The parent group ID.
 *  scrn_id :           [IN] The new screen ID will enter.
 *  exit_proc :         [IN] The exit function of the new screen.
 *  entry_proc :        [IN] The entry function of the new screen.
 *  scrn_type :         [IN] The screen type of the new screen.
 * RETURN VALUES
 *  MMI_TRUE: enter tab screen success.
 *  MMI_FALSE: enter tab screen failure.
 *****************************************************************************/
MMI_BOOL cui_tab_enter (MMI_ID parent_id, MMI_ID scrn_id, FuncPtr exit_proc, FuncPtr entry_proc, mmi_frm_scrn_type_enum scrn_type)
{
    return mmi_frm_scrn_enter (parent_id, scrn_id, exit_proc, entry_proc, MMI_FRM_FULL_SCRN);
}

/*****************************************************************************
 * FUNCTION
 *  cui_tab_update_info
 * DESCRIPTION
 *  app use cui_tab_update_info to update tab info, can delete or add screen.
 * PARAMETERS
 *  group_id                     [IN]      app group id of tab screen  
 *  tab_id                        [IN]      tab id
 *  tab_pages_info_array    [IN]      tab pages info
 *  tab_pages_count         [IN]       total tab page num
 *  sel_idx                       [IN]       the page screen will show
 *  user_data                   [IN]       app user data.  If your user_data no need change, you can set user_data as NULL.
 * RETURNS
 *  MMI_FALSE         tab update failure
 *  MMI_TRUE          tab update success
 *****************************************************************************/
MMI_BOOL cui_tab_update_info(MMI_ID group_id, MMI_ID tab_id, mmi_frm_tab_struct *tab_pages_info_array, U8 tab_pages_count, U8 sel_idx, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j, k;
    U8 sel_idx_old = 0;
    BOOL bTabUpdate = MMI_FALSE;
    wgui_tab_struct temp_tab_inst = {0};
    U16 gui_buf_size = 0;
    U16 input_buf_size = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        /* found tab, update info */
        if (MMI_tab_inst[i].group_id == group_id && MMI_tab_inst[i].tab_id == tab_id)
        {            
            bTabUpdate = MMI_TRUE;            
            temp_tab_inst = MMI_tab_inst[i];
            sel_idx_old = temp_tab_inst.sel_idx;
            
            /* if old tab screen of this tab exist, save it's gui_buf & input_buf, then close it. */
            if(mmi_frm_scrn_get_state(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id) != MMI_SCENARIO_STATE_NONE)
            {
                if (temp_tab_inst.gui_buf[sel_idx_old])
                {
                    mmi_frm_free(temp_tab_inst.gui_buf[sel_idx_old]);
                    temp_tab_inst.gui_buf[sel_idx_old] = NULL;
                }
                if (temp_tab_inst.input_buf[sel_idx_old])
                {
                    mmi_frm_free(temp_tab_inst.input_buf[sel_idx_old]);
                    temp_tab_inst.input_buf[sel_idx_old] = NULL;
                }                   
                gui_buf_size = mmi_frm_scrn_get_gui_buf_size(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id);
                input_buf_size = mmi_frm_scrn_get_input_buf_size(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id);

                if(gui_buf_size > 0)
                {                    
                    temp_tab_inst.gui_buf[sel_idx_old] = (U8*)mmi_frm_malloc(gui_buf_size);
                    memset(temp_tab_inst.gui_buf[sel_idx_old], 0, gui_buf_size);
                    memcpy(
                        (U8*)temp_tab_inst.gui_buf[sel_idx_old], 
                        (U8*)mmi_frm_scrn_get_gui_buf(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id), 
                        gui_buf_size);
                }
                if(input_buf_size > 0)
                {                        
                    temp_tab_inst.input_buf[sel_idx_old] = (U16*)mmi_frm_malloc(input_buf_size);
                    memset(temp_tab_inst.input_buf[sel_idx_old], 0, input_buf_size);
                    memcpy(
                        (U8*)temp_tab_inst.input_buf[sel_idx_old], 
                        (U8*)mmi_frm_scrn_get_input_buf(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id), 
                        input_buf_size);
                }
                mmi_frm_scrn_close(temp_tab_inst.group_id, temp_tab_inst.tab_bar_info[sel_idx_old].screen_id);
            }       
       
            /* save new tab info */
            MMI_tab_inst[i].tab_pages_count = tab_pages_count;
            MMI_tab_inst[i].sel_idx = sel_idx;
            if(user_data && user_data != MMI_tab_inst[i].user_data)
            {
                MMI_tab_inst[i].user_data = user_data;
            }
            for(j = 0; j < tab_pages_count; j++)
            {
                MMI_tab_inst[i].tab_bar_info[j]= tab_pages_info_array[j];  
                MMI_tab_inst[i].gui_buf[j] = NULL;
                MMI_tab_inst[i].input_buf[j] = NULL;
            
                /* search tab info whether the new page exist in old info array */                    
                for(k = 0; k < temp_tab_inst.tab_pages_count; k++)
                {
                    if (temp_tab_inst.tab_bar_info[k].screen_id == tab_pages_info_array[j].screen_id)
                    {                            
                        MMI_tab_inst[i].gui_buf[j] = temp_tab_inst.gui_buf[k];                            
                        MMI_tab_inst[i].input_buf[j] = temp_tab_inst.input_buf[k];
                       
                        temp_tab_inst.gui_buf[k] = NULL;                            
                        temp_tab_inst.input_buf[k] = NULL;                            
                        break;
                    }
                }
            }

            if(MMI_tab_inst[i].group_id == mmi_frm_group_get_active_id())
            {
                cui_tab_show_focused_screen(sel_idx);
            }
            
            /* free useless info */
            for(k = 0; k < temp_tab_inst.tab_pages_count; k++)
            {
                if(temp_tab_inst.gui_buf[k])
                {
                    mmi_frm_free(temp_tab_inst.gui_buf[k]);
                    temp_tab_inst.gui_buf[k] = NULL;
                }   
                if(temp_tab_inst.input_buf[k])
                {
                    mmi_frm_free(temp_tab_inst.input_buf[k]);
                    temp_tab_inst.input_buf[k] = NULL;
                }
            }
            break;
        }
    }

    /* not found tab, add new tab*/
    if(!bTabUpdate)
    {
        return cui_tab_create(group_id, tab_id, tab_pages_info_array, tab_pages_count, sel_idx, user_data);
    }
    return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_show_focused_screen
 * DESCRIPTION
 *  show selected screen of active tab.
 * PARAMETERS
 *  select_index      [IN]         the index of tab to show. 
 * RETURNS
 *  void
 *****************************************************************************/
static void cui_tab_show_focused_screen(S8 select_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i;
    U8 sel_idx_old = 0;
    BOOL needUpdate = MMI_FALSE;  
    MMI_ID active_gid = GRP_ID_INVALID;
    U16 gui_buf_size = 0;
    U16 input_buf_size = 0;
    mmi_frm_tab_struct page_info;  

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifndef __MMI_NOT_SMALL_SCRN_SUPPORT__ /*MAUI_03480048*/
    if(mmi_frm_scenario_is_redrawing() == MMI_TRUE)
    {
        return;
    }  
#endif /* __MMI_NOT_SMALL_SCRN_SUPPORT__ */

    active_gid = mmi_frm_group_get_active_id();
    
    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].group_id == active_gid || (g_activeTabID > 0 && MMI_tab_inst[i].tab_id == g_activeTabID))
        {
            
            if (select_index >= 0 && select_index < MMI_tab_inst[i].tab_pages_count)
            {    
                needUpdate = MMI_TRUE;                
                sel_idx_old = MMI_tab_inst[i].sel_idx;
                MMI_tab_inst[i].sel_idx = select_index;
            }            
        
            if(needUpdate && MMI_tab_inst[i].sel_idx >= 0 && MMI_tab_inst[i].sel_idx < MMI_tab_inst[i].tab_pages_count)
            {                
                /* show new category */                  
                page_info = MMI_tab_inst[i].tab_bar_info[MMI_tab_inst[i].sel_idx];

                mmi_frm_scrn_first_enter(
                    MMI_tab_inst[i].group_id, 
                    page_info.screen_id, 
                    (FuncPtr)page_info.tab_entry_func, 
                    MMI_tab_inst[i].user_data);
                    
                /* if old tab screen of this tab exist, save it's gui_buf & input_buf, then close it. */
                if(sel_idx_old != MMI_tab_inst[i].sel_idx \
                   && mmi_frm_scrn_get_state(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id) != MMI_SCENARIO_STATE_NONE)
                {
                    if (MMI_tab_inst[i].gui_buf[sel_idx_old])
                    {
                        mmi_frm_free(MMI_tab_inst[i].gui_buf[sel_idx_old]);
                        MMI_tab_inst[i].gui_buf[sel_idx_old] = NULL;
                    }
                    if (MMI_tab_inst[i].input_buf[sel_idx_old])
                    {
                        mmi_frm_free(MMI_tab_inst[i].input_buf[sel_idx_old]);
                        MMI_tab_inst[i].input_buf[sel_idx_old] = NULL;
                    }                   
                    gui_buf_size = mmi_frm_scrn_get_gui_buf_size(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id);
                    input_buf_size = mmi_frm_scrn_get_input_buf_size(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id);

                    if(gui_buf_size > 0)
                    {
                        MMI_tab_inst[i].gui_buf[sel_idx_old] = (U8*)mmi_frm_malloc(gui_buf_size);
                        memset(MMI_tab_inst[i].gui_buf[sel_idx_old], 0, gui_buf_size);
                        memcpy(
                            (U8*)MMI_tab_inst[i].gui_buf[sel_idx_old], 
                            (U8*)mmi_frm_scrn_get_gui_buf(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id), 
                            gui_buf_size);
                    }
                    if(input_buf_size > 0)
                    {
                        MMI_tab_inst[i].input_buf[sel_idx_old] = (U16*)mmi_frm_malloc(input_buf_size);
                        memset(MMI_tab_inst[i].input_buf[sel_idx_old], 0, input_buf_size);
                        memcpy(
                            (U8*)MMI_tab_inst[i].input_buf[sel_idx_old], 
                            (U8*)mmi_frm_scrn_get_input_buf(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id), 
                            input_buf_size);
                    }
                    mmi_frm_scrn_close(MMI_tab_inst[i].group_id, MMI_tab_inst[i].tab_bar_info[sel_idx_old].screen_id);
                }                    
            } 
            //set disable tab bar at here?

            break;     
        }          
    }
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_get_items
 * DESCRIPTION
 *  get active tab group's tab bar item info, can replace mmi_frm_scrn_tab_get_bar_items.
 * PARAMETERS
 *  tab_bar_items_p   [OUT]        
 *  tabs_p                [OUT]        tab bar num
 * RETURNS
 *  MMI_TRUE           get tab bar info succes
 *  MMI_FALSE          get tab bar info false, maybe the tab have not created.
 *****************************************************************************/
MMI_BOOL cui_tab_get_items(tab_bar_item_type *tab_bar_items_p, S8 *tabs_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_gid = 0;
    U16 i = 0, k = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    active_gid = mmi_frm_group_get_active_id();
    
    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].group_id == active_gid)
        {
            *tabs_p = MMI_tab_inst[i].tab_pages_count;
            
            memset(tab_bar_items_p, 0, sizeof(tab_bar_item_type)*MMI_tab_inst[i].tab_pages_count);

            for(k = 0; k < *tabs_p; k++)
            {
                tab_bar_items_p->icon = MMI_tab_inst[i].tab_bar_info[k].tab_icon;
                tab_bar_items_p->text = (UI_string_type)MMI_tab_inst[i].tab_bar_info[k].tab_string;

			    tab_bar_items_p++;
            }         
            
            //set disable tab bar at here?
            
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_get_screen_gui_buf
 * DESCRIPTION
 *  get related screen gui buf. 
 * PARAMETERS
 *  tab_id       [IN]       tab id        
 *  scrn_id      [IN]       screen id
 * RETURNS
 *  gui_buf    
 *****************************************************************************/
U8* cui_tab_get_screen_gui_buf(MMI_ID tab_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    
    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].tab_id == tab_id)
        {
            for(j = 0; j < UI_MAX_TAB_BAR_ITEMS; j++)
            {
                if(MMI_tab_inst[i].tab_bar_info[j].screen_id == scrn_id)
                    return MMI_tab_inst[i].gui_buf[j];
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_get_screen_input_buf
 * DESCRIPTION
 *  get related screen input buf. 
 * PARAMETERS
 *  tab_id       [IN]       tab id        
 *  scrn_id      [IN]       screen id
 * RETURNS
 *  input buf
 *****************************************************************************/
U16* cui_tab_get_screen_input_buf(MMI_ID tab_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].tab_id == tab_id)
        {
            for(j = 0; j < UI_MAX_TAB_BAR_ITEMS; j++)
            {
                if(MMI_tab_inst[i].tab_bar_info[j].screen_id == scrn_id)
                    return MMI_tab_inst[i].input_buf[j];
            }
        }
    }
    return NULL;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_get_select_index
 * DESCRIPTION
 *  get tab bar select tab index.
 * PARAMETERS
 *  tab_id       [IN]       tab id        
 * RETURNS
 *  sel_idx
 *****************************************************************************/
U8 cui_tab_get_select_index(MMI_ID tab_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].tab_id == tab_id)
            return MMI_tab_inst[i].sel_idx;
    }
    return 0;
}



/*****************************************************************************
 * FUNCTION
 *  cui_tab_get_active_tab_id
 * DESCRIPTION
 *  get active tab id.
 * PARAMETERS
 *  void           
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_ID cui_tab_get_active_tab_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_gid = 0;
    U16 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    active_gid = mmi_frm_group_get_active_id();

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].group_id == active_gid)
            return MMI_tab_inst[i].tab_id;       
    }
    return GRP_ID_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  cui_tab_is_in_tab_screen
 * DESCRIPTION
 *  check current active screen is tab screen.
 * PARAMETERS
 *     
 * RETURNS
 *  MMI_TRUE      current active screen is a tab screen
 *  MMI_FALSE     active screen is not tab screen.
 *****************************************************************************/
MMI_BOOL cui_tab_is_in_tab_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID active_gid = 0;
    MMI_ID active_sid = 0;
    U16 i = 0, page_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    active_gid = mmi_frm_group_get_active_id();
    active_sid = mmi_frm_scrn_get_active_id();

    for(i = 0; i < MMI_MAX_TAB_INST; i++)
    {
        if(MMI_tab_inst[i].group_id == active_gid)
        {
            for(page_num = 0; page_num < MMI_tab_inst[i].tab_pages_count; page_num++)
            {
                if (MMI_tab_inst[i].tab_bar_info[page_num].screen_id == active_sid)
                    return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}


#endif /* __MMI_TAB_BAR_SUPPORT_TAB_PAGE__ */

#endif /* __MMI_TAB_BARS_SUPPORT__ */

