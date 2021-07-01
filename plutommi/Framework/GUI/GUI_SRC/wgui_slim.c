/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *  wgui_slim.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Wrappers for BT box without LCD 
 *
 *   
 *  For example, applications and category screens should use GDI API directly 
 *  for image decoder and animations.
 * 
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 05 2015 anne.xu
 * removed!
 * wgui_slim.c get_softkey_icon build error check in.
 *
 * 10 15 2014 snow.wang
 * removed!
 * .
 *
 * 05 05 2014 xianggao.kong
 * removed!
 * BT Call Parts.
 *
 * 03 29 2014 hujin.hu
 * removed!
 * .
 *
 * 01 16 2014 hujin.hu
 * removed!
 * .
 *
 * 01 15 2014 hujin.hu
 * removed!
 * BTbox w/o patch back to 11C.
 *
 * 01 15 2014 ting.wang
 * removed!
 * Align to BTBox compile option, change __FWUI_NOT_PRESENT__ to __MMI_UI_DISPLAY_LEVEL_NONE__.
 * 
 *
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"       
#include "mmi_platform.h"
#include "mmi_frm_gprot.h"
#include "PixcomFontengine.h"
#include "gui_config.h"
#include "gui_data_types.h"
#include "gui.h"
#include "gui_bytestream.h"
#include "wgui_categories_defs.h"
#include "kal_non_specific_general_types.h"
#include "gdi_include.h"        
#include "gui_setting.h"
#include "lcd_sw_rnd.h"
#include "wgui_status_icon_bar.h"

/* lcd driver related */
#include "kal_non_specific_general_types.h"
#include "lcd_sw_inc.h"
#include "lcd_if.h"
#include "FileManagerGProt.h"

#include "ImeGprot.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "stdlib.h"
#include "gdi_datatype.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "stdarg.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "mmi_frm_mem_gprot.h"
#include "string.h"
#include "mmi_frm_timer_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_at_util_gprot.h"
#include "gdi_const.h"
#include "gui_resource_type.h"
#include "gui_switch.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_inputs.h"
#include "gui_status_icon_bar.h"
#include "FontRes.h"
#include "device.h"
#include "CustDataRes.h"
#include "custom_uem.h"

#include "gdi_primitive.h"
#include "InlineCuiGprot.h"
#include "CommonScreens.h"
#include "Wgui_tab_bars.h"
#include "Imc_config.h"
#include "Gui_font_size.h"
#include "wgui_categories_CM.h"
#include "IMERes.h"
#include "gui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_mms_viewer_int.h"
#include "wgui_categories_fmgr.h"
#include "wgui_categories_UCE.h"
#include "GlobalResDef.h"
#include "mmi_frm_events.h"
#include "Wgui_categories_list.h"


#if defined(__MMI_UI_DISPLAY_LEVEL_NONE__)

const U16 gIndexIconsImageList[] = 
{
 0
}; 

#ifdef __IOT__
#define IMM_MAX_INPUT_MODE_NUM    (1)
#endif
S32 MMI_title_height; 
S32 MMI_softkey_height = MMI_SOFTKEY_HEIGHT;
MMI_theme *current_MMI_theme = NULL;
tab_bar_item_type MMI_tab_bar_items[5];
S32 MMI_current_menu_type;
fixed_matrix_menu MMI_fixed_matrix_menu;
S32 main_menu_index = -1;
mmi_imm_input_mode_enum  MMI_all_prefered_input_mode_set[IMM_MAX_INPUT_MODE_NUM] = {IMM_INPUT_MODE_NONE};
UI_string_type MMI_message_string;
multi_line_input_box MMI_multiline_inputbox;
UI_multi_line_input_box_theme *current_multi_line_input_box_theme = NULL;
dm_data_struct g_dm_data;
wgui_inline_item wgui_inline_items[MAX_INLINE_ITEMS];
UI_theme *current_UI_theme  = NULL;

S32 UI_text_x;              /* Current text cursor position */
S32 UI_text_y;
S32 UI_text_height;         /* Current line height to use */

S32 MMI_content_x;
S32 MMI_content_y;
S32 MMI_content_width;
S32 MMI_content_height;

S32 MMI_singleline_inputbox_x;
S32 MMI_singleline_inputbox_y;
S32 MMI_singleline_inputbox_width;
S32 MMI_singleline_inputbox_height;

/* <group dom_utility_variables> */
 S32 MMI_pop_up_dialog_x;
/* <group dom_utility_variables> */
 S32 MMI_pop_up_dialog_y;
/* <group dom_utility_variables> */
 S32 MMI_pop_up_dialog_width;
/* <group dom_utility_variables> */
 S32 MMI_pop_up_dialog_height;
gdi_handle wgui_base_layer;
gdi_handle wgui_layer_1;
UI_filled_area wgui_pop_up_dialog_background;
UI_string_type MMI_title_string = NULL;
S32 volume_level_UI;
S16 MMI_current_input_ext_type = 0;

S32 GUI_current_fixed_icontext_list_menuitem_column = 0;
fixed_icontext_list_menuitem MMI_fixed_icontext_list_menuitem;
fixed_icontext_list_menuitem_type *MMI_fixed_icontext_list_menuitems = NULL;
fixed_list_menu MMI_fixed_list_menu;
void *MMI_fixed_menuitem_pointers[MAX_FIXED_MENU_ITEM_POINTERS];
fixed_twostate_menuitem MMI_fixed_twostate_menuitem;
fixed_twostate_menuitem_type *MMI_fixed_twostate_menuitems = NULL;
S32 *fixed_twostate_menu_n_items;
typedef MMI_BOOL (*cat431_pen_handler)   (mmi_pen_point_struct point, mmi_pen_event_type_enum event_type);









void UI_dummy_function(void)
{
}

//api from wingui.c
void DebugPrint(U8 x, U8 y, S8 *s)
{

}

void InitDebugPrint(void)
{

}

void MMICheckDiskDisplay(void)
{

}

void MMIResourceMismatchWarning(
        kal_int8 errType,
        kal_int8 errResType,
        kal_uint8 const *codeversion,
        kal_uint8 const *resversion)
{

}        

S8 *GetImageTheme(U16 ImageId)
{
   return NULL;
}

//api from commonscreen.c
void mmi_frm_highlight_inline_generic_done(void)
{
}

void mmi_frm_highlight_input_method_generic(void)
{

}

void mmi_ime_delete_editor_common_scr_with_sg(U16 g_id, U16 scr_id)
{

}


//api from immi.c
void mmi_imm_phone_language_change_handler(void)
{

}

//gui_inputs.c
BOOL r2lMMIFlag;

//wgui_softkeys.c
void ChangeLeftSoftkeyExt(U16 s)
{

}

void ChangeRightSoftkeyExt(U16 s)
{

}

void SetCenterSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{

}

void SetLeftSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{

}

void SetRightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{

}

//api from wgui_categories_util.c
U16 GetRootTitleIcon(U16 ItemId)
{
		return 0;
}

void RegisterHighlightHandler(void (*f) (S32 item_index))
{

}

PU8 get_image(MMI_ID_TYPE i)
{
	return NULL;
}

//from wgui_categories_inputs.c
void ShowCategory111Screen_ext_int(
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *message2,
        S32 duration,
        U8 *history_buffer)
{

}

void wgui_inputs_category_set_rsk_func(void (*f) (void))
{

}

//from wgui_inputs.c
void wgui_inputs_register_validation_func(void (*f) (U8 *, U8 *, S32))
{

}

//from wgui_categories_list.c
void ShowCategory36Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{

}        

void wgui_cat1032_refresh_list(
					S32 number_of_items, 
					S32 highlighted_item, 
					GetAsyncItemFuncPtr get_item_func,
					GetAsyncHintFuncPtr get_hint_func)
{

}					

void wgui_cat1032_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        S8 highlighted_tab,    
        U16 list_icon1,
        U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{

}

//from wgui_categories_popup.c
void ShowCategory66Screen_int_ex(
        U16 title,
//        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message
#ifndef __MMI_POPUP_NO_SHOW_ICON__          
        ,U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/        
        )
{

}        

//from wgui_categories_text_viewer.c
void ShowCategory74Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *buffer,
        S32 buffer_length,
        U8 *history_buffer)
{

}        

void ShowCategory7Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U8 *history_buffer)
{

}        

//from fseditorcui.c
void cui_fseditor_close(mmi_id fseditor_gid)
{

}

mmi_id cui_fseditor_create(mmi_id parent_gid)
{
	return 0;
}

U32 cui_fseditor_get_parent_data(mmi_id fseditor_gid)
{
	return 0;
}

S32 cui_fseditor_get_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size)
{
	return 0;
}

void cui_fseditor_run(mmi_id fseditor_gid)
{

}

void cui_fseditor_set_input_method(
        mmi_id fseditor_gid,
        U32 input_type,
        const mmi_imm_input_mode_enum *required_input_mode_set,
        S16 input_ext_type)
{

}        

void cui_fseditor_set_parent_data(mmi_id fseditor_gid, U32 parent_data)
{

}

void cui_fseditor_set_text(mmi_id fseditor_gid, WCHAR *buffer, S32 buffer_size, S32 edit_length)
{

}

void cui_fseditor_set_title(mmi_id fseditor_gid, U16 label, U16 icon)
{

}

//from menucui.c
void cui_menu_change_left_softkey_string(mmi_id owner_gid, WCHAR* lsk_str)
{

}

void cui_menu_close(mmi_id owner_gid)
{

}

mmi_id cui_menu_create_and_run(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data)
{
	return 0;
}                       

void cui_menu_set_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids)
{

}

void cui_menu_set_currlist_flags(mmi_id owner_gid, U32 flags)
{

}

void cui_menu_set_default_title_image(mmi_id owner_gid, UI_image_type img)
{

}

void cui_menu_set_default_title_string(mmi_id owner_gid, WCHAR* str)
{

}

void cui_menu_set_item_disabled(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_disabled_flag)
{

}

void cui_menu_set_item_hint(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str)
{

}

void cui_menu_set_item_string(mmi_id owner_gid, mmi_menu_id menu_id, WCHAR* str)
{

}

//from immc.c
mmi_imm_message_id_enum mmi_imm_set_app_desired_input_mode(mmi_imm_input_mode_enum desired_input_mode)
{
	return 0;
}

void wgui_status_icon_bar_reset_icon_display(S32 icon_id)
{

}

void wgui_status_icon_bar_set_icon_display(S32 icon_id)
{

}

void wgui_status_icon_bar_update(void)
{

}

void ShowCategory353Screen_int(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S32 number_of_items,
                U8 **list_of_items,
                U16 *list_of_icons,
                U8 **list_of_descriptions,
                S32 flags,
                S32 highlighted_item,
                U8 *history_buffer)
{

}   

void cui_inline_close(mmi_id inline_gid)
{

}    

mmi_id cui_inline_create(mmi_id parent_gid, const cui_inline_struct *inline_struct)
{
	return 0;
}         

S32 cui_inline_delete_item(mmi_id gid, U16 item_id)
{
	return 0;
}

S32 cui_inline_get_value(mmi_id gid, U16 item_id, void *value)
{
	return 0;
}

S32 cui_inline_insert_item(mmi_id gid, U16 pre_id, cui_inline_set_item_struct *new_item)
{
	return 0;
}

void cui_inline_lock_main_screen(mmi_id gid)
{

}

void cui_inline_redraw_screen(mmi_id gid)
{

}

void cui_inline_run(mmi_id inline_id)
{

}

void cui_inline_set_all_items_softkey_text(mmi_id gid, WGUI_SOFTKEY_ENUM key, U16 string_id)
{

}

 void cui_inline_set_fullscreen_edit_title_icon(mmi_id gid, U16 item_id, U16 icon)
{

}

void cui_inline_set_highlight_item(mmi_id gid, U16 item_id)
{

}

S32 cui_inline_set_item_attributes(mmi_id gid, U16 item_id, U8 operation, U32 flag)
{
	return 0;
}

void cui_inline_set_screen_attributes(mmi_id gid, U8 operation, U32 flag)
{

}

S32 cui_inline_set_softkey_icon(mmi_id gid, U16 item_id, WGUI_SOFTKEY_ENUM key, U16 image_id)
{
	return 0;
}

S32 cui_inline_set_softkey_text(mmi_id gid, U16 item_id, WGUI_SOFTKEY_ENUM key, U16 string_id)
{
	return 0;
}

S32 cui_inline_set_value(mmi_id gid, U16 item_id, void *value)
{
	return 0;
}

void cui_inline_unlock_main_screen(mmi_id gid)
{

}

mmi_id cui_menu_create(mmi_id parent_gid,
                       cui_menu_src_type_enum src_type,
                       cui_menu_type_enum menu_type,
                       mmi_menu_id root_menu_id,
                       MMI_BOOL is_item_flags_from_res,
                       void* parent_data)
{
	return 0;
}                       

void  cui_menu_run(mmi_id owner_gid)
{

}

void cui_menu_set_default_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id)
{

}

void cui_menu_set_default_title_image_by_id(mmi_id owner_gid, U16 img_id)
{

}

void cui_menu_set_item_hidden(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL is_hidden_flag)
{

}

void wgui_inline_set_lsk_function(void (*f) (void))
{

}

void wgui_override_list_menu_slim_style(wgui_list_menu_slim_style_enum style)
{

}

void wgui_restore_list_menu_slim_style(void)
{

}

void cui_menu_set_radio_list_item(mmi_id owner_gid, mmi_menu_id menu_id)
{

}

void ShowCategory52Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}

void EntryScrForInputMethodAndDone(void)
{

}
 
void SetInputMethodAndDoneCaptionIcon(U16 IconId)
{

}

void ShowCategory304Screen(U16 message_icon, U8 *history_buffer)
{

}       

void mmi_ime_delete_editor_common_scr(U16 scr_id)
{

}

UI_string_type get_string(MMI_ID_TYPE i)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type s = (UI_string_type) GetString((U16) i);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(s == NULL || s[0] == '\0')
	{
		return NULL;
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
#endif//	
    return ((UI_string_type) s);
}

void asyncdynamic_list_goto_item(S32 item_index)
{

}

void entry_full_screen(void)
{

}

void ChangeTitle_ex(
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
	U16 image_ID, 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/	
	U8 *string)
{
}

#if defined(__MMI_CASCADED_OPTION_MENU__)
void DisplayCascadingMenu(U16 cascading_menu_id, CascadingMenuCmdHdlrFuncPtr command_handler)
{

}
#endif/*#if defined(__MMI_CASCADED_OPTION_MENU__)*/


void (*ExitCategoryFunction) (void) = UI_dummy_function;

void ShowCategory63Screen_ex(
	U8 *message
#ifndef __MMI_POPUP_NO_SHOW_ICON__	
	, U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/	
	)
{

}	

void UI_cancel_timer(void (*callback) (void))
{

}

color UI_color(U8 r, U8 g, U8 b)
{
	    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c.r = r;
    c.b = b;
    c.g = g;
    c.alpha = 100;
    return (c);
}

void UI_disable_alignment_timers(void)
{

}

void UI_enable_alignment_timers(void)
{

}

void UI_free(void *ptr)
{

}

void UI_measure_string(UI_string_type text, S32 *width, S32 *height)
{
#ifdef __DISPLAY_LEVEL_GDI_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Get_StringWidthHeight((U8*) text, width, height);

#endif
}

void UI_set_font(UI_font_type f)
{
    #ifdef __DISPLAY_LEVEL_GDI_ONLY__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /* Let UI_font point to &static_font instead of input parameter */ 
    static stFontAttribute static_font;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    static_font = *f;
    SetFont(static_font, 0);
    #endif
}

void UI_set_text_border_color(color c)
{

}

void UI_set_text_color(color c)
{

}

void UI_start_timer(S32 count, void (*callback) (void))
{

}

void UI_start_timer_ex(S32 count, gui_timer_funcptr_type callback, void *arg)
{

}

S32 cui_menu_get_currlist_item_count(mmi_id owner_gid)
{
	return 0;
}

mmi_menu_id cui_menu_get_currlist_menu_id_from_index(mmi_id owner_gid, S32 index )
{
	return 0;
}

void cui_menu_set_non_leaf_item(mmi_id owner_gid, mmi_menu_id menu_id, MMI_BOOL flag)
{

}

void cui_menu_set_rotate_screen(mmi_id owner_gid, mmi_frm_screen_rotate_enum rotation)
{

}

void draw_title(void)
{

}

FuncPtr get_softkey_function(MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{
	return NULL;
}

UI_font_type gui_font_get_type(gui_font_size_enum index)
{
	return NULL;
}

void gui_print_truncated_borderd_text(
	S32 x, 
	S32 y, 
	S32 xwidth, 
	UI_string_type st)
{

}	

void gui_print_truncated_text(
	S32 x, 
	S32 y, 
	S32 xwidth, 
	UI_string_type st)
{

}

void reset_title_status_icon(void)
{

}	

void show_title_status_icon(void)
{

}

MMI_BOOL wgui_softkey_get_offset(
          UI_string_type sk_str_p,
          S32 *offset_x,
          S32 *offset_y,
          S32 *truncated_width,
          WGUI_SOFTKEY_ENUM key,
          mmi_frm_screen_rotate_enum rotate_degree)
{
	return MMI_FALSE;
}          

void wgui_status_icon_bar_reset_display(wgui_status_icon_bar_enum bar_id)
{

}

void wgui_status_icon_bar_set_display(wgui_status_icon_bar_enum bar_id)
{

}

void wgui_title_set_menu_shortcut_number(S32 menu_shortcut_number)
{

}

void EnableCenterSoftkey_ex(
#ifndef __MMI_WGUI_DISABLE_CSK__
	U16 s, 
	U16 i
#endif/*__MMI_WGUI_DISABLE_CSK__*/
	)
{

}	

void MMI_dummy_function(void)
{

}

U32 cui_inline_get_parent_data(mmi_id gid)
{
	return 0;
}

void cui_inline_set_parent_data(mmi_id gid, U32 parent_data)
{

}

void cui_inline_set_title_icon(mmi_id gid, U16 icon)
{

}

MMI_BOOL cui_menu_is_menu_event (U16 evt_id)
{
	return MMI_FALSE;
}

PU8 wgui_get_list_menu_icon(int index, MMI_ID_TYPE default_image_id)
{
	return NULL;
}

void ShowCategory223Screen_ext(
        WCHAR *title,//U16 title,
        PU8 title_icon,//U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U16 flag,
        U32 duration,
        U8 *history_buffer)
{

}

void cui_menu_set_default_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id)
{

}

void UI_move_text_cursor(S32 x, S32 y)
{

}

void UI_print_bordered_text(UI_string_type text)
{

}

void gui_draw_filled_area(
	S32 x1, 
	S32 y1, 
	S32 x2, 
	S32 y2, 
	UI_filled_area *f)
{

}	

void ShowCategory163Screen_int_ex(
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        UI_string_type message
#ifndef __MMI_POPUP_NO_SHOW_ICON__        
        ,U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/        
        )
{

}        

void UI_print_text(UI_string_type text)
{

}

void cui_inline_set_title(mmi_id gid, U16 string_id, U16 image_id)
{

}

void cui_menu_set_default_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id)
{

}

void ChangeCenterSoftkey_ex(
#ifndef __MMI_WGUI_DISABLE_CSK__  
	U16 s, 
	U16 i
#endif/*__MMI_WGUI_DISABLE_CSK__*/	
	)
{

}	

void cui_menu_set_currlist_highlighted_id(mmi_id owner_gid, mmi_menu_id menu_id)
{

}

void cui_menu_set_currlist_title_by_id(mmi_id owner_gid, U16 str_id, U16 img_id)
{

}

void cui_menu_pause(mmi_id owner_gid)
{

}

void cui_menu_play(mmi_id owner_gid)
{

}

void cui_menu_set_access_by_shortcut(mmi_id owner_gid,MMI_BOOL access_by_sc_flag)
{

}

void cui_menu_set_currlist_title(mmi_id owner_gid, WCHAR* str, UI_image_type img)
{

}

void SetCategory16RightSoftkeyFunction(void (*f) (void), MMI_key_event_type k)
{

}

void ShowCategory16Screen_int(
        U16 left_softkey,
        U16 right_softkey,
        U8 *Buffer,
        U32 BufferLength,
        U8 *history_buffer)
{

}        

void ShowCategory17Screen_int(
        U16 title_id,
        U16 left_softkey,
        U16 right_softkey,
        U16 NotificationStringId,
        PU8 NameOrNumber,
        PU8 IP_Number,
        U16 CallLine,
        U16 default_image_id,
        U16 resource_id,
        CHAR* resource_filename,
        wgui_cate_momt_res_type_enum resource_type,
        U16 repeat_count,
        BOOL is_visaul_update,
        BOOL is_aud_enable,
        BOOL is_play_aud_when_start,
        PU8 history_buffer)
{

}        

void ShowCategory403Screen_int(
                U8 *title,
                U16 title_icon,
                U16 left_softkey,
                U16 right_softkey,
                S8 n_tabs,
                S8 highlighted_tab,
                tab_bar_item_type *tab_items,
                MYTIME *CallDuration,
                U16 duration_icon,
                U8 **list_of_items,
                U16 *list_of_icons,
                S32 number_of_items,
                U16 highlighted_item,
                U8 *history_buffer)
{

}                

void ShowCategory6Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U8 **list_of_descriptions,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void ShowCategory74Screen(
                    U16 title,
                    U16 title_icon,
                    U16 left_softkey,
                    U16 left_softkey_icon,
                    U16 right_softkey,
                    U16 right_softkey_icon,
                    U8 *buffer,
                    S32 buffer_length,
                    U8 *history_buffer)
{

}                    

void ShowCategoryDummyScreen(void)
{

}

void duration_string(UI_time *t, UI_string_type s, U32 flags)
{

}

void reset_call_cost_UI(void)
{

}
void show_call_cost_UI(PU8 symbol, PU8 value)
{

}

void wgui_cat403_set_duration(MYTIME *CallDuration)
{

}

void wgui_cat9001_show(void)
{

}

void wgui_inputs_dialer_display_char(U8 key_code)
{

}

MMI_BOOL wgui_inputs_dialer_is_dialer_keys(S16 mmi_key_code)
{
	return MMI_FALSE;
}

mmi_ret wgui_inputs_options_menu_handler(mmi_event_struct *evt, mmi_id parent_id)
{
	return 0;
}

void Category53ChangeItemText(
	S32 index, 
	U8 *text)
{

}	


void (*RedrawCategoryFunction) (void) = UI_dummy_function;

void cui_menu_set_default_title(mmi_id owner_gid, WCHAR* str, UI_image_type img)
{

}

void date_string(UI_time *time, UI_string_type string, U32 flags)
{

}

void time_string(UI_time *t, UI_string_type s, U32 flags)
{

}
void Category53ChangeItemIcon(
	S32 index, 
	U8 *icon)
{

}	

S32 GetHighlightedItem(void)
{
	return 0;
}

void ShowCategory53Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

U32 cui_inline_get_screen_attributes(mmi_id gid)
{
	return 0;
}

S32 UI_get_string_width(UI_string_type text)
{
	return 0;
}

void clear_screen(void)
{

}

void register_default_hide_softkeys(void)
{

}

void show_left_softkey(void)
{

}

void show_right_softkey(void)
{

}

void show_softkey(WGUI_SOFTKEY_ENUM key)
{

}

void show_softkey_background(void)
{

}

void wgui_title_change_ex(
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__
	U16 icon_ID, 
	U16 icon2_ID, 
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
	U8 *text, 
	U32 flag)
{

}	

void wgui_title_show(U32 part)
{

}

void ShowCategory11Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 highlighted_item,
        U8 *history_buffer)
{

}        

void ShowCategory83Screen(
      UI_image_ID_type bg_id,
      gui_calendar_type_enum type,
      applib_time_struct max_date,
      applib_time_struct min_date,
      applib_time_struct show_date,
      MMI_BOOL is_status_bar,
      U8 *str_LeftSoftkey,
      U8 *str_rightSoftkey,
      U8 *history_buffer,
      U32 flag)
{

}      

void set_inline_date_boundary(
      S32 date_year_max,
      S32 date_year_min,
      S32 date_month_max,
      S32 date_month_min)
{

}      

void wgui_cat83_register_cell_lunar_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct cell_time,
            applib_time_struct time_interval,
            PU8 title,
            U32 title_length,
            gui_calendar_cell_detail_info_struct *detail_info))
{

}            

void wgui_cat83_register_highlight_change_callback(
          MMI_BOOL (*f)(
                gui_calendar_type_enum type,
                applib_time_struct highlighted_time,
                applib_time_struct start_time,
                applib_time_struct end_time))
{

}                

void ShowCategory14Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void execute_left_softkey_function(MMI_key_event_type k)
{

}

void gui_sse_setup_scenario(gui_sse_scenario_enum scenario)
{

}

void initialize_mainmenu_title_icons(void)
{

}

void mmi_frm_set_highlight_handler(void)
{

}

void register_menu_shortcut_selected(void (*f) (S32 i))
{

}

void cui_menu_set_currlist_left_softkey_by_id(mmi_id owner_gid, U16 lsk_str_id)
{

}

void cui_menu_set_currlist_right_softkey_by_id(mmi_id owner_gid, U16 rsk_str_id)
{

}

void cui_menu_set_item_string_by_id(mmi_id owner_gid, mmi_menu_id menu_id, U16 str_id)
{

}

void ShowCategory84Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void (*SUBLCD_ExitCategoryFunction) (void) = UI_dummy_function;

void dm_init(void)
{

}

void initialize_category_screens(void)
{

}

void setup_UI_wrappers(void)
{

}

void wgui_init(void)
{

}

void Category52ChangeItemDescription(
	S32 index, 
	U8 *text)
{

}	

const sIMEModeDetails * mmi_imm_get_corresponding_multitap_mode(mmi_imm_input_mode_enum input_mode, U16 mode_case)
{
	return NULL;
}

mmi_imm_input_mode_enum mmi_imm_get_current_input_mode(void)
{
	return 0;
}

const sIMEModeDetails * mmi_imm_get_input_mode_array_item(mmi_imm_input_mode_enum input_mode)
{
	return NULL;
}

void mmi_imm_write_prefered_input_method_to_nvram(mmi_imm_input_mode_enum input_mode)
{

}

S32 mmi_imm_get_prefer_input_mode_list(mmi_imm_input_mode_enum *mode_array, S32 max)
{
	return 0;
}

S32 mmi_imm_get_prefer_input_mode_string_list(U8 **strarray, S32 max)
{
	return 0;
}

MMI_BOOL mmi_imm_is_smart_alphabetic_input_modes_enabled(void)
{
	return MMI_FALSE;
}

void mmi_imm_set_inputmethod(U16 index)
{

}

void register_center_softkey_to_enter_key(void)
{

}

void ShowCategory121Screen_int(
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U16 message_icon,
        U8 *history_buffer,
        U8 flag)
{

}        

void ShowCategory2Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 message,
        U8 *history_buffer)
{

}        

void ShowCategory8Screen_int_ex(
        U16 title,
     //   U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message
#ifndef __MMI_POPUP_NO_SHOW_ICON__          
        ,U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/        
        )
{

}        

void gui_touch_feedback_play(gui_touch_feedback_enum event_enum)
{

}

void SetCheckboxToggleRightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void))
{

}

S32 UI_strlen(UI_string_type text)
{
	return 0;
}

void _measure_image(U8 *image, S32 *width, S32 *height)
{

}

void wgui_cat1043_show(
		U16 title,
		U16 title_icon,
		U16 left_softkey,
		U16 right_softkey,
		S32 number_of_items,
		GetAsyncItemFuncPtr get_item_func,
		GetAsyncHintFuncPtr get_hint_func,
		S32 highlighted_item,
		S8 highlighted_tab,    
		U16 list_icon1,
		U16 list_icon2,
		U8 *history_buffer,
		S32 *category_error_flag)
{

}		

void wgui_cat1047_show(
		U16 title,
		U16 title_icon,
		S32 number_of_items,
		pBOOL(*get_text_callback) (S32 item_index, UI_string_type str_buff),
		U8 *list_of_states,
		S32 highlighted_item,
		U8 *history_buffer)
{

}		

void wgui_draw_pop_up_screen_background(
	S32 x1, 
	S32 y1, 
	S32 x2, 
	S32 y2, 
	UI_filled_area *f)
{

}	


void wgui_inputs_ml_create_set_buffer(UI_string_type buffer, S32 buffer_length, S32 text_length, S32 edit_position)
{

}

S32 wgui_inputs_ml_get_line_height(void)
{
	return 0;
}

void wgui_inputs_ml_move(S32 x, S32 y)
{

}

void wgui_inputs_ml_resize(S32 width, S32 height)
{

}

void wgui_inputs_ml_show(void)
{

}

void wgui_inputs_ml_show_no_draw(void)
{

}

void wgui_inputs_ml_toggle_insert_mode(void)
{

}

void wgui_set_animation_image_y(S32 x, S32 y, PU8 img)
{

}

void wgui_show_animation(void)
{

}

void gui_fixed_icontext_list_menuitem_stop_scroll(void)
{

}

void gui_fixed_icontext_menuitem_stop_scroll(void)
{

}

void gui_fixed_twostate_menuitem_stop_scroll(void)
{

}

void ShowCategory154Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *message1,
        U8 *message2,
        U16 message_icon,
        U8 *history_buffer)
{

}        

void cat66_update_progress_string(void)
{

}

void ShowCategory165Screen_int_ex(
        U16 left_softkey,
        U16 right_softkey,
        UI_string_type message
#ifndef __MMI_POPUP_NO_SHOW_ICON__         
        ,U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/        
        )
{

}        

void cui_menu_set_currlist_left_softkey(mmi_id owner_gid, WCHAR* lsk_str)
{

}

void cui_menu_set_currlist_right_softkey(mmi_id owner_gid, WCHAR* rsk_str)
{

}

void wgui_status_icon_bar_hide_icon(S32 icon_id)
{

}

void wgui_status_icon_bar_show_icon(S32 icon_id)
{

}

void wgui_cat9002_show(U16 image_icon_1, U16 image_icon_2, U8 *history_buffer, U8 flags)
{

}

void wgui_status_icon_bar_set_icon_animate(S32 icon_id)
{

}

void redraw_left_softkey(void)
{

}

void redraw_right_softkey(void)
{

}

void wgui_status_icon_bar_blink_icon(S32 icon_id)
{

}

void ShowCategory262Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U16 list_icon,
        U8 *history_buffer,
        S32 *category_error_flag)
{

}        

void cui_menu_enable_center_softkey(mmi_id owner_gid, U16 str_id, U16 img_id)
{

}

void wgui_cat_list_set_display_more_icon(MMI_BOOL IsIcon)
{

}

kal_uint32 MMIGetGDIShowFullScreenTime(void)
{
	return 0;
}

void mmi_display_popup(UI_string_type string, mmi_event_notify_enum event_id)
{

}

U8 *dummy_get_history(U8 *buffer)
{
	return NULL;
}

S32 dummy_get_history_size(void)
{
	return 0;
}


U8 *(*GetCategoryHistory) (U8 *buffer) = dummy_get_history;
S32(*GetCategoryHistorySize) (void) = dummy_get_history_size;


void UI_set_line_height(S32 height)
{

}

void clear_key_handlers(void)
{

}

void clear_left_softkey(void)
{

}

void clear_right_softkey(void)
{

}

void gui_change_scrolling_text(scrolling_text *s, UI_string_type text)
{

}

void gui_create_scrolling_text(
        scrolling_text *s,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type text,
        void (*timer_callback) (void),
        void (*draw_background) (S32 x1, S32 y1, S32 x2, S32 y2),
        color text_color,
        color border_color)
{

}

void gui_handle_scrolling_text(scrolling_text *s)
{

}

void gui_scrolling_text_stop(scrolling_text *s)
{

}

void gui_show_scrolling_text(scrolling_text *s)
{

}

void cui_inline_set_icon_list(mmi_id gid, U16 *icon_list)
{

}

S32 cui_inline_set_item_select(mmi_id gid, U16 item_id, S32 n_items, PU8 *list_of_items, U8 highlighted_item)
{
	return 0;
}

void cui_menu_enable_tap_to_highlight(mmi_id owner_gid)
{

}

void cui_menu_set_item_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon)
{

}

void ShowCategory223Screen_int(
         U16 title,
         U16 title_icon,
         U16 left_softkey,
         U16 right_softkey,
         U16 message_icon,
         U16 flag,
         U32 duration,
         U8 *history_buffer)
{

}         

void (*gui_show_image) (S32 x, S32 y, PU8 i) = NULL;

void wgui_softkey_get_dimension(WGUI_SOFTKEY_ENUM key, S32 *width, S32 *height)
{

}

void wgui_softkey_get_position(WGUI_SOFTKEY_ENUM key, S32 *x, S32 *y)
{

}

void ShowCategory221Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        gdi_color background_color,
        FuncPtr redraw_content_callback)
{

}        

void gui_touch_feedback_disable_vibrate_internal(void)
{

}

void update_mainlcd_dt_display(void)
{

}

void cui_menu_change_center_softkey_content(mmi_id owner_gid, WCHAR* lsk_str, UI_image_type img )
{

}

void cui_fseditor_set_custom_options_menu(mmi_id fseditor_gid, MMI_BOOL is_diable_defaut_menu, PU16 menu_list, U8 count)
{

}

void * cui_menu_get_app_parent_data(mmi_id owner_gid)
{
	return NULL;
}

void cui_menu_get_checkbox_state(mmi_id owner_gid, U8* list_of_states)
{

}

S32 cui_menu_get_index_in_currlist_from_menu_id(mmi_id owner_gid, mmi_menu_id menu_id)
{
	return 0;
}

void cui_menu_set_checkbox_state(mmi_id owner_gid, U8* list_of_states)
{

}

void cui_inline_set_title_string(mmi_id gid, UI_string_type s)
{

}

void cui_menu_override_center_softkey(mmi_id owner_gid, WCHAR* csk_str, UI_image_type csk_img)
{

}

void cui_menu_set_item_second_image(mmi_id owner_gid, mmi_menu_id menu_id, U16 img_icon)
{

}

//huking
U8 *get_audio(MMI_ID_TYPE i, U8 *type, U32 *filelen)
{
	  /*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
		U8 *s = NULL;
	
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
		ASSERT(type != NULL && filelen != NULL);
	
		*type = 0;;
		*filelen = 0;
	
		if (i == 0)
		{
			return (NULL);
		}
	
		s = (U8*) GetAudio((U16) i);
	
		if(s == NULL || s[0] == '\0')
		{
			return NULL;
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
#endif//0
		*type = s[0];
	
		*filelen |= (U32) (s[1]);
		*filelen |= (U32) ((U32) s[2] << 8);
		*filelen |= (U32) ((U32) s[3] << 16);
		*filelen |= (U32) ((U32) s[4] << 24);
	
		return (s + 8);

}

void ShowCategory152Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U8 *history_buffer)
{

}        

void ClearHighlightHandler(void)
{

}

void ShowCategory151Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U8 *message,
        U8 *message_icon,
        U8 *history_buffer)
{

}        

void ShowCategory171Screen_int(
        U8 *left_softkey,
        U8 *right_softkey,
        U8 *message,
        PU8 message_icon,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{

}        

void ShowCategory172Screen_int(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void ShowCategory174Screen_int(
        U8 *title,
        PU8 title_icon,
        U8 *left_softkey,
        U8 *right_softkey,
        S32 number_of_items,
        U8 **list_of_items,
        PU8 *list_of_icons,
        U8 **list_of_descriptions,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void cui_menu_insert_currlist(mmi_id owner_gid, S32 number_of_items, mmi_menu_id* list_of_ids, mmi_menu_id after_menu_id )
{

}

void Category53ChangeItemDescription(
	S32 index, 
	U8 *text)
{

}	

mmi_imm_input_mode_enum mmi_imm_get_prefer_input_mode(void)
{
	return 0;
}

void ShowCategory263Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U16 list_icon,
        U8 *history_buffer,
        S32 *category_error_flag)
{

}        

void clear_softkey_handler(WGUI_SOFTKEY_ENUM key)
{
}

void wgui_async_list_register_update_callback(AsyncUpdateCallback async_update_callback)
{

}

void wgui_cat1002_show_int(
      UI_string_type title,
      PU8 title_icon,
      UI_string_type left_softkey,
      UI_string_type right_softkey,
      S32 number_of_items,
      GetAsyncItemFuncPtr get_item_func,
      GetAsyncHintFuncPtr get_hint_func,
      checkbox_get_image_funcptr_type get_state_func,
      checkbox_clicked_funcptr_type set_state_func,
      UI_string_type info_message,
      S32 highlighted_item,
      U16 list_icon,
      U8 *history_buffer,
      S32 *category_error_flag)
{

}      

void wgui_cat6003_show(
        U16 left_softkey,
        U16 right_softkey,
        WCHAR* message,
        WCHAR* sub_message,
        U8 percentage)
{

}        

void wgui_cat6003_update_all(
        WCHAR* message,
        WCHAR* sub_message,
        U8 percentage)
{

}        

void wgui_cat_set_list_menu_empty_lable(UI_string_type lable)
{

}

void (*SUBLCD_RedrawCategoryFunction) (void) = UI_dummy_function;

void ShowCategory184Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void dynamic_list_goto_item(S32 item_index)
{

}

void wgui_inputs_multitap_reset(void)
{

}

MMI_BOOL wgui_inputs_multitap_setup_functions(wgui_multitap_type_enum multitap_type, void (*input_callback) (UI_character_type), void (*input_complete_callback) (void))
{
	return MMI_FALSE;
}

void update_sublcd_dt_display(void)
{

}

void cui_menu_disable_cascading_option_menu(mmi_id owner_gid)
{

}

void cui_menu_set_new_list_parent_id(mmi_id owner_gid, mmi_menu_id parent_menu_id)
{

}

void cui_fseditor_set_characters_filter(mmi_id fseditor_gid, MMI_BOOL is_allowed, const UI_character_type *characters_list)
{

}

void EntryInputMethodScreen(void)
{

}

void wgui_cat_setup_special_style(U32 style_flags)
{

}

void ShowCategory141Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *message,
        U16 message_icon,
        U8 *history_buffer)
{

}        

void ShowCategory88Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 bg_image_id,
        U16 n_items,
        U8 **string_list,
        S32 *lower_limit,
        S32 *upper_limit,
        S32 **current_value,
        void (**cb_func) (S32 value),
        U8 *history_buffer)
{

}

void UpdateCategory402Value(U16 value, U8 *string)
{

}


void set_force_icon_on_highlight_only_in_menuitem(void)
{
}

void wgui_fixed_list_register_get_flags_handler(GetMenuitemFlags get_flags_handler)
{

}

void wgui_inputs_multitap_stop(void)
{

}

void ShowCategory15Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        U16 *list_of_icons,
        S32 flags,
        S32 highlighted_item,
        U8 *history_buffer)
{

}                

void ShowCategory1Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 number_of_items,
        U16 *list_of_items,
        S32 highlighted_item,
        U8 *history_buffer)
{

}        

void ShowCategory87Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        S32 l_limit,
        S32 u_limit,
        S32 *current_value,
        U8 *history_buffer)
{

}        

void ShowCategory105Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 *volume_level,
        U8 *history_buffer)
{

}        

void show_vertical_bar(S32 volume_level)
{

}

void show_vertical_bar_next(void)
{

}

void show_vertical_bar_previous(void)
{

}

void mmi_imc_config_keymap_auto_test(MMI_BOOL is_on)
{

}

void mmi_imc_send_current_input_mode_indication(void)
{

}

U32 wgui_inputs_direct_input_from_tst_module(U8 index, U8 *p)
{
	return 0;
}

void ShowCategory163Screen_ext_int(
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        UI_string_type message
#ifndef __MMI_POPUP_NO_SHOW_ICON__         
        ,wgui_cat_popup_icon_type_enum message_icon_type,
        PU8 message_icon,
        S32 message_icon_size,
        U8 message_icon_format,
        UI_string_type message_icon_file_path
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/        
        )
{

}        

void wgui_status_icon_bar_animate_icon(S32 icon_id)
{

}

MMI_BOOL wgui_status_icon_bar_whether_icon_display(S32 icon_id)
{
	return MMI_FALSE;
}

void CloseCategory57Screen(void)
{

}

U8 *GetCategory57Data(U8 *data)
{
	return NULL;
}

S32 GetCategory57DataSize(void)
{

	return 0;
}

void UI_common_screen_exit(void)
{

}

void UI_common_screen_pre_exit(void)
{

}


void dm_enable_small_screen_flatten(void)
{

}

void gui_sse_set_is_dummy_screen(MMI_BOOL is_dummy)
{

}

void wgui_cat1031_refresh_list(
					S32 number_of_items, 
					S32 highlighted_item, 
					GetAsyncItemFuncPtr get_item_func,
					GetAsyncHintFuncPtr get_hint_func)
{

}					

void wgui_cat1031_set_disable_sc_show(MMI_BOOL flag)
{

}

MMI_BOOL gui_sse_get_is_dummy_screen(void)
{
	return MMI_FALSE;
}

void dm_disable_small_screen_flatten(void)
{

}

void dm_force_small_screen_flatten(void)
{

}

void dm_unforce_small_screen_flatten(void)
{

}

void gui_sse_set_is_small_screen(MMI_BOOL is_small)
{

}

void ShowCategory64Screen_ex(
	U16 message
#ifndef __MMI_POPUP_NO_SHOW_ICON__	
	, U16 message_icon
#endif/*__MMI_POPUP_NO_SHOW_ICON__*/	
	)
{

}	

void wgui_status_icon_bar_change_icon_level(S32 icon_id, S32 level)
{

}

void wgui_status_icon_bar_change_icon_image(S32 icon_id, S32 image_id)
{

}

void wgui_status_icon_bar_change_timer_format_callback(void)
{

}

void gui_screen_switch_effect_block(MMI_BOOL enable)
{

}

void leave_full_screen(void)
{

}

void gui_cleanup(void)
{

}

void gui_free_multilayer_screen(void)
{

}

void gui_set_entry_new_screen(U8 new_entry)
{

}

void wgui_reset_wallpaper_on_bottom(void)
{

}

void UI_fill_rectangle(
	S32 x1, 
	S32 y1, 
	S32 x2, 
	S32 y2, 
	color c)
{

}	

void dm_get_scr_bg_image(U16 *image_id, S8 **file_name, S32 *x, S32 *y, U8 *opacity)
{

}

void wgui_set_wallpaper_on_bottom(MMI_BOOL state)
{

}


void UI_draw_vertical_line(S32 y1, S32 y2, S32 x, color c)
{

}

void gui_create_multi_line_input_box_set_buffer(
        multi_line_input_box *b,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        UI_string_type buffer,
        S32 length,
        S32 text_length,
        S32 edit_position)
{

}        

void gui_get_multi_line_input_box_default_font_style(
                        multi_line_input_box *b,
                        UI_font_type text_font)
{

}                        

void gui_multi_line_input_box_next_line(multi_line_input_box *b)
{

}

void gui_multi_line_input_box_previous_line(multi_line_input_box *b)
{

}

void gui_resize_multi_line_input_box(multi_line_input_box *b, S32 width, S32 height)
{

}

void gui_set_multi_line_input_box_default_bg_color(
                          multi_line_input_box *b, 
                          color c, 
                          MMI_BOOL b_set)
{

}                          

void gui_set_multi_line_input_box_theme(multi_line_input_box *b, UI_multi_line_input_box_theme *t)
{

}

void gui_show_multi_line_input_box(multi_line_input_box *b)
{

}

void set_left_softkey_label(UI_string_type s)
{

}

void set_right_softkey_label(UI_string_type s)
{

}

void Cat431GetScreenInfo(MMI_BOOL isFullScreen, U32 *x, U32 *y, U32 *w, U32 *h, GDI_HANDLE *title_layer, GDI_HANDLE *bottom_layer)
{

}

void ChangeLeftSoftkeyByString_ex(
	UI_string_type s
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__  	
	, PU8 i
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/ 	
	)
{

}	

void ChangeRightSoftkeyByString_ex(
	UI_string_type s
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__ 	
	, PU8 i
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	)
{

}	

mmi_id cui_fseditor_adm_create(mmi_id parent_gid,KAL_ADM_ID app_adm_id)
{
	return 0;
}

void cui_inline_set_item_fullscreen_edit(
        mmi_id gid,
        U16 item_id,
        cui_inline_set_item_fullscreen_edit_struct *fullscreen_attr)
{

}        

void cui_inline_set_item_text_edit(
        mmi_id gid,
        U16 item_id,
        PU8 buffer,
        S32 buffer_size,
        U32 input_type,
        S16 input_extended_type,
        mmi_imm_input_mode_enum *required_input_mode_set,
        U16 default_text_id)
{

}        

void cui_inline_set_title_string_with_string_id(mmi_id gid, U16 string_id)
{

}

void cui_menu_change_left_softkey_string_by_id(mmi_id owner_gid, U16 lsk_str_id)
{

}

void ShowCategory132Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U8 *history_buffer)
{

}        

void ShowCategory412Screen(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        PU8 left_softkey_icon,
        UI_string_type right_softkey,
        PU8 right_softkey_icon,
        PU8 progress_image,
        UI_string_type display_str,
        U8 percentage_value,
        S32 number_of_items,
        UI_string_type *list_of_items,
        U8 *history_buffer)
{

}        

#if defined(__MMI_BROWSER_2__) || defined(__MMI_GADGET_SUPPORT__)

void ShowCategory431Screen(
        U8* title,
        U16 title_icon1,
        U16 title_icon2,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        cat431_pen_handler pen_handler,
        MMI_BOOL isFullScreen,
        S32 percentage,
        S8* display_string,
        U8* history_buffer)
{

}        
#endif

void wgui_cat132_enable_fullscreen(void)
{

}        

S32 cui_fseditor_get_text_len(mmi_id fseditor_gid)
{
	return 0;
}

 UI_string_type mmi_imm_get_allowed_email_address_characters(void)
{
	return NULL;
}

mmi_imm_message_id_enum mmi_imm_set_characters(MMI_BOOL is_allowed, const UI_character_type *characters_lsit)
{
	return 0;
}

void set_leading_zero(U8 u8type)
{

}

#if defined (__MMI_MMSXMLDEF_H__) && defined (__UI_MMS_VIEWER_CATEGORY__)
void Category630Initialize(wgui_mv_initialize_struct *init)
{

}
#endif

void Category630MidSlidesCBDoneNotify (void)
{

}

void SetCategory57RightSoftkeyFunctions(void (*done_function) (void), void (*back_function) (void))
{

}

#if defined(__UI_MMS_VIEWER_CATEGORY__)
void ShowCategory630Screen (BOOL toggle, U16 mode, softkey_fn lsk_function, U16 lsk_str_id, softkey_fn rsk_function, MMI_BOOL is_fullscreen, PU8 guibuffer,WGUI_MV_USED_BY_ENUM used_by)
{

}
#endif

void cui_menu_set_default_title_string_by_id(mmi_id owner_gid, U16 str_id)
{

}

void SetInlineFullScreenEditCustomFunction(InlineItem *item, void (*f) (void))
{

}

void SetInlineItemActivation(InlineItem *item, S32 key_code, S32 key_event)
{

}

void SetInlineItemCaption(InlineItem *item, U8 *text_p)
{

}

void SetInlineItemFullScreenEdit_ext(
        InlineItem *item,
        U16 title,
        U16 title_icon,
        U8 *buffer,
        S32 buffer_size,
        U32 input_type,
        S16 input_extended_type)
{

}        

void ShowCategory227Screen_int(
        U8 *title_string,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        void (*display_call_back) (dm_coordinates *coordinate),
        MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point))
{

}

void wgui_cat1031_show(
        WCHAR* title,
        PU8 title_icon,
        WCHAR* left_softkey,
        PU8 left_softkey_icon,
        WCHAR* right_softkey,
        PU8 right_softkey_icon,
		S32 number_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        S32 highlighted_item,
		S8 highlighted_tab,    
        U16 list_icon1,
		U16 list_icon2,
        U8 *history_buffer,
        S32 *category_error_flag)
{

}        

void change_left_softkey_ex(
	U16 s
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__
	, U16 icon
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/
)
{

}

void DisplayPopup(U8 *string, U16 imageId, U8 imageOnBottom, U32 popupDuration, U8 toneId)
{

}

void ShowCategory21Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message,
        U8 *history_buffer)
{

}        

void change_softkey_ex(
	U16 s,
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__	
	U16 i, 
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	WGUI_SOFTKEY_ENUM key)
{

}

void redraw_softkey(WGUI_SOFTKEY_ENUM key)
{

}

void SetIdleScreenNetworkName(U8 *s)
{

}

void SetIdleScreenNetworkStatus(U8 *s)
{

}

void SetIdleScreenSlaveNetworkName(U8 *s)
{

}

void SetIdleScreenSlaveNetworkStatus(U8 *s)
{

}

void ShowCategory33Screen_int(
        U16 left_softkey,
        U16 right_softkey,
        U8 *history_buffer)
{

}        

void idle_screen_show_network_details(void)
{

}

void wgui_softkey_update(void)
{

}

MMI_BOOL gui_ems_test_UCS2_character(UI_character_type c)
{
	return MMI_FALSE;
}


void cui_fseditor_set_softkey_icon(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 icon)
{

}

void cui_fseditor_set_softkey_text(mmi_id fseditor_gid, WGUI_SOFTKEY_ENUM key_type, U16 text)
{

}

void wgui_cat21x_register_get_displayable(wgui_fmgr_get_displayable_func get_displayable)
{

}

void wgui_cat21x_register_get_thumb_image(wgui_fmgr_get_thumb_image_func get_thumb_image)
{

}

void wgui_cat21x_register_set_displayable(wgui_fmgr_set_displayable_func set_displayable)
{

}

UI_string_type get_softkey_label(WGUI_SOFTKEY_ENUM key)
{
	return NULL;
}

void set_softkey_function(void (*f) (void), MMI_key_event_type k, WGUI_SOFTKEY_ENUM key)
{

}

void DisableCategory57ScreenRskBack(void)
{

}

S32 cui_inline_set_text_len(mmi_id gid, U16 item_id, U32 len)
{
	return 0;
}

void SetIdleScreenWallpaperID(U16 image_ID)
{

}

void SetIdleScreenWallpaperName(UI_string_type name)
{

}

void ShowCategory129Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U8 *history_buffer)
{

}

void ShowCategory130Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{

}        

MMI_BOOL mmi_imc_get_char_info(UI_character_type code, UI_string_type info_buffer, S32 buffer_size, mmi_imm_input_mode_enum mode)
{
	return MMI_FALSE;
}

void MMICheckDiskDisplay_Ex(MMI_BOOL force_to_display)
{

}

mmi_ret mmi_imc_editor_cursor_movement_handler(mmi_event_struct* param)
{
	return 0;
}

S32 mmi_imc_enter_spell_word_screen_handler(mmi_event_struct* param)
{
	return 0;
}

mmi_ret mmi_imc_input_method_screen_handler(mmi_event_struct* param)
{
	return 0;
}

mmi_ret wgui_inline_proc_post_event(mmi_event_struct* param)
{
	return 0;
}

mmi_ret wgui_status_icon_bar_sleepout_callback_handler(mmi_event_struct* param)
{
	return 0;
}

void ShowCategory5Screen_ext2_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        U32 input_type,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer,
        S16 input_ext_type,
        mmi_imm_input_mode_enum *required_input_mode_set)
{

}        

void wgui_inputs_ml_move_cursor_to_start(void)
{

}

void wgui_inputs_ml_redraw(void)
{

}

void wgui_status_icon_bar_change_icon_image_ex(S32 icon_id, PU8 image_data)
{

}

void wgui_status_icon_bar_get_clip(wgui_status_icon_bar_enum bar_id, S32 *x1, S32 *y1, S32 *x2, S32 *y2)
{

}

void wgui_status_icon_bar_reset(void)
{

}

void wgui_status_icon_bar_reset_target_layer(wgui_status_icon_bar_enum bar_id)
{

}

void wgui_status_icon_bar_set_alpha_blend_layer(wgui_status_icon_bar_enum bar_id, gdi_handle alpha_blend_layer)
{

}

void wgui_status_icon_bar_set_target_layer(wgui_status_icon_bar_enum bar_id, gdi_handle target_layer)
{

}

void UI_draw_horizontal_line(
	S32 x1, 
	S32 x2, 
	S32 y, 
	color c)
{

}	

void UI_putpixel(
	S32 x, 
	S32 y, 
	color c)
{

}	

S32 is_on_idlescreen(void)
{
	return 0;
}

void gui_create_horizontal_progress_indicator(horizontal_progress_indicator *pi, S32 x, S32 y, S32 width, S32 height)
{

}

void gui_create_horizontal_scrollbar(horizontal_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{

}

void gui_create_vertical_scrollbar(vertical_scrollbar *v, S32 x, S32 y, S32 width, S32 height)
{

}

void gui_set_horizontal_progress_indicator_range(horizontal_progress_indicator *pi, S32 range)
{

}

void gui_set_horizontal_progress_indicator_value(horizontal_progress_indicator *pi, S32 value)
{

}

void gui_set_horizontal_scrollbar_range(horizontal_scrollbar *v, S32 range)
{

}

void gui_set_horizontal_scrollbar_scale(horizontal_scrollbar *v, S32 scale)
{

}

void gui_set_horizontal_scrollbar_value(horizontal_scrollbar *v, S32 value)
{

}

void gui_set_vertical_scrollbar_range(vertical_scrollbar *v, S32 range)
{

}

void gui_set_vertical_scrollbar_scale(vertical_scrollbar *v, S32 scale)
{

}

void gui_set_vertical_scrollbar_value(vertical_scrollbar *v, S32 value)
{

}

void gui_show_horizontal_progress_indicator(horizontal_progress_indicator *pi)
{

}

void gui_show_horizontal_scrollbar(horizontal_scrollbar *h)
{

}

void gui_show_vertical_scrollbar(vertical_scrollbar *v)
{

}

void UI_fixed_menuitem_dummy_function(void *item, void *common_item_data)
{

}

void UI_fixed_menuitem_dummy_function_with_2_S32(void *item, void *common_item_data, S32 x, S32 y)
{

}

void UI_fixed_menuitem_dummy_get_length_function(void *item, void *common_item_data, S32 *width)
{

}

void create_fixed_twostate_menuitems(PU8 ON_icon, PU8 OFF_icon)
{

}

void gui_create_fixed_icontext_list_menuitem(
        fixed_icontext_list_menuitem *m,
        S32 width,
        S32 height,
        S32 n_text_columns,
        S32 n_icon_columns)
{

}        

void gui_create_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y, S32 width, S32 height)
{

}

void gui_create_fixed_twostate_menuitem(fixed_twostate_menuitem *m, S32 width, S32 height, PU8 ON_icon, PU8 OFF_icon)
{

}

void gui_fixed_icontext_list_menuitem_set_icon_coordinates(
        fixed_icontext_list_menuitem *m,
        S32 icon_column,
        S32 x,
        S32 y,
        S32 width,
        S32 height)
{

}        

void gui_fixed_icontext_list_menuitem_set_text_coordinates(
        fixed_icontext_list_menuitem *m,
        S32 text_column,
        S32 x,
        S32 y,
        S32 width,
        S32 height)
{

}        

void gui_get_fixed_icontext_list_menuitem_flag(
	void *item, 
	void *common_item_data, 
	S32 index, 
	U32* flags, 
	U32* flags_ext)
{

}	

void gui_get_fixed_twostate_menuitem_flag(void *item, void *common_item_data, S32 index, U32* flags, U32* flags_ext)
{

}

void gui_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data)
{

}

void gui_highlight_fixed_twostate_menuitem(void *item, void *common_item_data)
{

}

void gui_list_menu_goto_item(fixed_list_menu *m, S32 i)
{

}

void gui_list_menu_goto_next_item(fixed_list_menu *m)
{

}

void gui_list_menu_goto_previous_item(fixed_list_menu *m)
{

}

void gui_measure_fixed_icontext_list_menuitem(void *item, void *common_item_data, S32 *width, S32 *height)
{

}

void gui_measure_fixed_twostate_menuitem(void *item, void *common_item_data, S32 *width, S32 *height)
{

}

void gui_menuitem_set_icon_position(void *common_item_data, S32 x, S32 y)
{

}

void gui_menuitem_set_text_position(void *common_item_data, S32 x, S32 y)
{

}

void gui_move_fixed_list_menu(fixed_list_menu *m, S32 x, S32 y)
{

}

void gui_remove_highlight_fixed_icontext_list_menuitem(void *item, void *common_item_data)
{

}

void gui_remove_highlight_fixed_twostate_menuitem(void *item, void *common_item_data)
{

}

void gui_resize_fixed_icontext_list_menuitem(fixed_icontext_list_menuitem *m, S32 width, S32 height)
{

}

void gui_resize_fixed_icontext_menuitem(void *m0, S32 width, S32 height)
{

}

void gui_resize_fixed_list_menu(fixed_list_menu *m, S32 width, S32 height)
{

}

void gui_set_fixed_icontext_list_menuitem_current_theme(fixed_icontext_list_menuitem *m)
{

}

void gui_set_fixed_icontext_menuitem_current_theme(void *m)
{

}

void UI_draw_rectangle(S32 x1, S32 y1, S32 x2, S32 y2, color c)
{

}


void gui_set_fixed_list_menu_item_functions(
        fixed_list_menu *m,
        void (*item_display_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_measure_function) (void *item, void *common_item_data, S32 *width, S32 *height),
        void (*item_highlight_function) (void *item, void *common_item_data),
        void (*item_remove_highlight_function) (void *item, void *common_item_data),
        void (*item_hide_function) (void *item, void *common_item_data, S32 x, S32 y),
        void (*item_resize_function) (S32 x, S32 y),
        void (*item_get_flag_function)(void *item, void *common_item_data, S32 index, U32 *flags, U32 *flags_ext),
        void (*item_get_length_function)(void *item, void *common_item_data, S32 *width))
{

}

void gui_show_fixed_icontext_list_menuitem(
	void *item, 
	void *common_item_data, 
	S32 x, 
	S32 y)
{

}		

void gui_show_fixed_list_menu(fixed_list_menu *m)
{

}

void gui_show_fixed_twostate_menuitem(void *item, void *common_item_data, S32 x, S32 y)
{

}

void gui_show_list_menu_no_draw(fixed_list_menu *m)
{

}

void radio_list_handle_item_select(S32 h)
{

}

void register_fixed_list_highlight_handler(void (*f)(S32 item_index))
{

}

void register_menu_shortcut_handler(void (*f) (S32 i))
{

}

void register_menu_shortcut_keys(void)
{

}

void resize_fixed_icontext_list_menuitems(S32 width, S32 height)
{

}

void resize_fixed_list(S32 width, S32 height)
{

}

void resize_fixed_twostate_menuitems(S32 width, S32 height)
{

}

void set_MMI_current_fixed_icontext_list_menuitem_theme_list(void)
{

}

void standard_check_list_handle_item_select(S32 h)
{

}

void ChangeCategory79MessageString(U8 *new_string, S32 buffer_size, MMI_BOOL is_reset_y, MMI_BOOL need_scrollbar, MMI_BOOL is_r2l_display)
{

}

void ShowCategory78Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        multi_line_input_box_icon_hdlr icon_callback,
        U8 *buffer,
        S32 buffer_size,
        U8 *history_buffer)
{

}        

void gui_touch_feedback_disable_tone_internal(void)
{

}

void gui_touch_feedback_enable_tone_internal(void)
{

}

void gui_touch_feedback_enable_vibrate_internal(void)
{

}

void ShowCategory123Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message,
        U16 message_icon,
        U8 *history_buffer)
{

}        
        
void ShowCategory280Screen(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        wgui_uce_msg_type_enum msg_type,
        U32 input_method_type,
        UI_string_type subjcet_firstline,
        UI_string_type subject_secondline,
        U8 *gui_buffer)
{

}        


void wgui_uce_initialize_editor(
        U8 *text_buffer,
        U16 text_buffer_size,
        U8 new_slide_number,
        U8 total_slide_number,
        U8 total_character,
        wgui_uce_get_message_size_callback get_msg_size,
        wgui_uce_text_change_callback text_change,
        wgui_uce_get_display_type_callback get_display_type,
        wgui_uce_get_sms_remaining_character_callback get_sms_rm_character,
        wgui_uce_get_sms_segment_callback get_sms_segment,
        wgui_uce_highlight_handler highlight_handler,
        wgui_uce_change_slide_handler slide_handler)
{

}        

U32 wgui_uce_insert_text_template(U8 *string, U16 no_of_char, U8 *guibuffer)
{
	return 0;
}

void wgui_uce_set_current_text_info(wgui_uce_text_info_struct *text_info)
{

}

void DisableLeftSoftkey_ex(
	U16 s
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__
	, U16 i
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	)
{

}

void DisableRightSoftkey_ex(
	U16 s
#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__	
	, U16 i
#endif/*__MMI_ICONTEXT_BTN_DISPLAY_ICON__*/	
	)
{

}	

void ShowCategory222Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        gdi_color background_color,
        S8 *button_string,
        S8 *file_name_ptr,
        BOOL is_short_filename,
        void (*decode_result_callback) (GDI_RESULT),
        gdi_image_src_enum src_type)
{

}        

void wgui_cat222_disable_err_msg_display(void)
{

}

void DisplaySubLcdPopup(U16 imageId)
{

}

void wgui_cat020_update_duration(void)
{

}

void wgui_cat403_update_duration(void)
{

}

void Cat412UpdateList(
        UI_string_type display_str,
        U8 percentage_value,
        S32 number_of_items,
        UI_string_type *list_of_items)
{

}        

void InitIME(void)
{

}

void wgui_softkey_lock_softkey(U16 s, U16 i, WGUI_SOFTKEY_ENUM key)
{

}

void wgui_softkey_unlock_softkey(WGUI_SOFTKEY_ENUM key)
{

}

void ShowCategory166Screen(U16 image_id, S8 *image_filename, void (*animation_complete_callback) (GDI_RESULT))
{

}

void StopCategory166Animation(void)
{

}

void SetDialingInputCursorToFirst(void)
{

}

void cui_fseditor_set_title_string(mmi_id fseditor_gid, const WCHAR *label)
{

}

#ifndef __DISPLAY_LEVEL_GDI_ONLY__
BOOL IsL2RMMIStyle(void)
{

	return MMI_FALSE;
}
#endif
void mmi_frm_nmgr_cancel_deferred_scenario(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg)
{

}

MMI_BOOL mmi_frm_nmgr_notify_by_app(mmi_scenario_id scenario_id, mmi_event_notify_enum type, mmi_noti_scrn_func_ptr screen_entry, void *arg)
{

	return MMI_FALSE;
}

MMI_BOOL mmi_frm_nmgr_popup(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
	return MMI_FALSE;
}

MMI_ID mmi_popup_display( 
            WCHAR* title, 
        	mmi_event_notify_enum event_type, 
        	mmi_popup_property_struct *arg)
{

	return GRP_ID_INVALID;
}

MMI_ID mmi_popup_display_ext( 
            MMI_STR_ID title, 
        	mmi_event_notify_enum event_type, 
        	mmi_popup_property_struct *arg)
{
	return GRP_ID_INVALID;

}

MMI_ID mmi_popup_display_simple(
            WCHAR* title, 
            mmi_event_notify_enum event_type, 
            MMI_ID parent_id,
            void * user_tag)
{
	return GRP_ID_INVALID;

}

MMI_ID mmi_confirm_display_ext(
        	MMI_STR_ID title, 
        	mmi_event_notify_enum event_type, 
        	mmi_confirm_property_struct *arg)
{
	return GRP_ID_INVALID;

}

void mmi_confirm_property_init(mmi_confirm_property_struct *arg, mmi_confirm_type_enum ctype)
{

}

MMI_ID mmi_popup_display_simple_ext(
            MMI_STR_ID title, 
            mmi_event_notify_enum event_type, 
            MMI_ID parent_id,
            void * user_tag)
{
	return GRP_ID_INVALID;

}

MMI_ID mmi_confirm_display(
        	WCHAR* title, 
        	mmi_event_notify_enum event_type, 
        	mmi_confirm_property_struct *arg)
{
	return GRP_ID_INVALID;

}

void mmi_popup_property_init(mmi_popup_property_struct *arg)
{

}

mmi_ret mmi_alert_normal_exit_helper(mmi_event_struct *evt)
{
	return MMI_RET_OK;

}

MMI_BOOL mmi_alert_dismiss(MMI_ID id)
{
	return MMI_FALSE;

}

#ifndef __DISPLAY_LEVEL_GDI_ONLY__
S32 Get_CharHeight(void)
{
	return 0;
}

void Get_CharWidthHeight(U32 Ch, S32 *pWidth, S32 *pHeight)
{

}

void mmi_fe_set_r2l_state(MMI_BOOL state)
{

}

pBOOL IsChineseSet(void)
{
	return 0;
}

void mmi_fe_init(void)
{

}

U8 *Get_Current_Lang_CountryCode(void)
{
	return NULL;
}
#endif

MMI_BOOL mmi_frm_nmgr_is_scenario_deferred(mmi_scenario_id scen_id, mmi_noti_scrn_func_ptr scrn_entry_func, void *arg)
{
	return MMI_FALSE;
}

void mmi_frm_nmgr_alert_cancel(
        NMGR_HANDLE open_handle)
{

}

NMGR_HANDLE mmi_frm_nmgr_alert(    
    mmi_frm_nmgr_alert_struct *alert_info)
{
	return NULL;
}

NMGR_HANDLE mmi_frm_nmgr_compose_alert_handle(MMI_ID app_id, mmi_event_notify_enum event_type, S32 icon_id)
{
	return NULL;
}

#ifndef __DISPLAY_LEVEL_GDI_ONLY__
pBOOL IsEnglishSet(void)
{
	return MMI_FALSE;
}

S32 Get_CharHeightOfAllLang(U8 size)
{
	return 0;
}

U32 Get_StringLength_InCluster(U8 *input_str, U32 len, U32 base_len)
{
	return 0;
}

void Get_StringWidthHeight_n(U8 *String, S32 n, S32 *pWidth, S32 *pHeight)
{

}

U32 Get_StringWidthHeight_variant(
        U8 *string,
        S32 w,
        S32 n,
        S32 *pWidth,
        S32 *pHeight,
        S32 max_width,
        U8 checkLineBreak,
        U8 checkCompleteWord)
{
	return 0;
}

U8 SetFont(stFontAttribute Font, U8 arrCount)
{
	return 0;
}
#endif

U8 mmi_frm_nmgr_get_defer_notification_count(void)
{
	return 0;
}

void mmi_frm_nmgr_invoke_deder_event(void)
{
}

MMI_BOOL mmi_frm_nmgr_notify_by_idle(mmi_scenario_id scenario_id, mmi_event_notify_enum type, WCHAR *string)
{
    return MMI_FALSE;
}

mmi_ret mmi_frm_nmgr_control_end_callback(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}

mmi_ret mmi_frm_nmgr_invoke_defer_event_callback(mmi_event_struct* para)
{
	return MMI_RET_OK;
}

#ifndef __DISPLAY_LEVEL_GDI_ONLY__
U32 Get_CharNumInWidth_w(U8 *String, U32 width, U8 checklinebreak, U32 gap)
{
	return 0;
}

void Get_StringWidthHeight(U8 *String, S32 *pWidth, S32 *pHeight)
{

}

void mmi_fe_get_char_info_of_all_lang(U8 size, S32 *pheight, S32 *pascent, S32 *pdescent)
{

}

MMI_BOOL mmi_fe_get_glyph_metrics(U16 ch, mmi_fe_glyph_metrics_struct_p matrix)
{
	return MMI_TRUE;
}

U32 mmi_fe_get_string_widthheight(mmi_fe_get_string_info_param_struct_p query)
{
	return 0;
}

MMI_BOOL mmi_fe_is_r2l_state(void)
{
	return MMI_FALSE;
}

void mmi_fe_set_text_color(mmi_fe_color c)
{
}

U32 mmi_fe_show_string_n(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len)
{
	return 0;
}

U32 mmi_fe_show_string_n_baseline(U32 x_unsigned, U32 y_unsigned, U8 *String, S32 Len, S32 baseline)
{
	return 0;
}

mmi_font_engine_error_message_enum mmi_font_engine_show_truncated_text(
                                    S32 x,
                                    S32 y,
                                    S32 xwidth,
                                    U8 *st,
                                    U8 *truncated_symbol,
                                    MMI_BOOL bordered)
{
	return 0;
}

S32 Get_CharAscent(void)
{
	return 0;
}

S32 Get_CharDisplayHeightOfAllLangAndType(U8 size)
{
	return 0;
}
#endif
void BatteryIndicationPopup(U16 stringId)
{

}

void BatteryStatusIndication(U8 battery_voltage)
{

}

void HintPhnsetPreferedInputMethod(U16 index)
{

}

void mmi_ime_settings_inputmethodsettings_highlight(void)
{

}

mmi_ret mmi_imesettings_menu_handler(cui_menu_event_struct *evt, MMI_ID parent_gid)
{
	return MMI_RET_OK;
}

void mmi_phnset_set_pref_input_mode_menu_hint(MMI_ID menucui_id)
{

}

void IdleScreenChargerConnected(U8 playtone)
{
}

void IdleScreenBatteryFullCharged(void)
{

}

void IdleScreenChargerDisconnected(void)
{

}

void ShowChargingScr_int(void)
{

}

mmi_ret wgui_softkey_default_proc(mmi_event_struct *evt)
{
      
    return MMI_RET_OK;
}

void ExecuteCurrHiliteHandler(S32 hiliteid)
{


}

void ExecuteCurrHiliteHandler_Ext(S32 hiliteid)
{
  
}


U16 GetCurrHiliteID(void)
{

    return 0;
}


void SetHiliteHandler(U16 itemid, FuncPtr hiliteFuncPtr)
{

 
}

FuncPtr mmi_frm_get_hilite_hdlr(U16 menu_id)
{
	return NULL;   

}


void ClearHiliteHandler(U16 itemid)
{

}



void ConstructHintsList(U16 parentID, U8 **hintArray)
{
 
}


void SetHintHandler(U16 itemid, FuncPtrShort hintFuncPtr)
{
   
}


FuncPtrShort mmi_frm_get_hint_hdlr(U16 menu_id)
{

        return NULL;
      
}


void ClearHintHandler(U16 itemid)
{

}


void SetParentHandler(U16 parentID)
{
 
}


U16 GetParentHandler(void)
{

    return 0;
}


void ClearInputEventHandler(U16 device)
{
 
}


void GetInputEventInfo(U16 *device, U16 *keyCode, U16 *keyType, mmi_pen_event_type_enum *pen_type, mmi_pen_stroke_type_enum *stroke_type)
{

}

U8 MaskItems(U16 *maskList, U8 noOfItems, U32 maskingWord)
{
   
 
    return 0;
}


U8 MaskItemsU8(U8 *maskList, U8 noOfItems, U32 maskingWord)
{
    /*----------------------------------------------------------------*/
  
    return 0;
}


U8 MaskStringItems(U8 **maskList, U8 noOfItems, U32 maskingWord)
{
   
    return 0;
}


void ExecuteItemHiliteHandler(U16 hiliteItemID)
{
 
}


MMI_BOOL mmi_frm_binary_search(U32 key, mmi_frm_pair_data_struct* search_table, U32 num, U32* index)
{
 
    return MMI_FALSE;    
}


MMI_BOOL mmi_frm_binary_search_ex(U32 key, mmi_frm_pair_data_struct* search_table, U32 num, U32* index)
{
 
    return MMI_FALSE;    
}

//ucs2


U16 mmi_frm_get_curr_key_tone(void)
{
	return 0;
}

void mmi_frm_kbd_set_tone_state(mmi_frm_kbd_tone_state_enum state)
{
}



void mmi_frm_set_dial_key_tone_type(mmi_frm_dial_key_tone_type_enum  type)
{

}


mmi_frm_kbd_tone_state_enum mmi_frm_kbd_get_key_tone_state(void)
{
	return 0;
}



mmi_ret mmi_key_tone_pre_key_routing_cb(mmi_event_struct *evt)
{
	return MMI_RET_OK;
}


//end ucs2
void wgui_stop_title_animation(void)
{

}

void ShowCategory163Screen(
                UI_string_type left_softkey,
                PU8 left_softkey_icon,
                UI_string_type right_softkey,
                PU8 right_softkey_icon,
                UI_string_type message,
                U16 message_icon,
                U8 *history_buffer)
{

}

void gui_util_painter_create_empty(gui_util_painter_struct *p)
{

}

void wgui_set_menu_empty_string_by_id(U16 str_id)
{

}

void wgui_text_label_create(
        U32 text_label_id,
        S32 x,
        S32 y,
        S32 width,
        S32 height,
        U8 *title,
        UI_font_type text_font,
        color text_color,
        MMI_BOOL border_enable,
        color border_color,
        gui_util_painter_struct background,
        gui_text_label_align_enum text_h_align_type,
        gui_text_label_align_enum text_v_align_type,
        GDI_HANDLE target_layer,
        GDI_HANDLE target_lcd)
{

}

void wgui_text_label_show(U32 text_label_id)
{

}

void wgui_cat223_update_duration(U32 duration)
{

}

MMI_BOOL cui_tab_get_items(tab_bar_item_type *tab_bar_items_p, S8 *tabs_p)
{

}

//MMI_BOOL mmi_frm_scenario_is_redrawing(void)
//{
//    return MMI_FALSE;   
//}


void wgui_horizontal_tab_bar_goto_next_item(void)
{

}

void wgui_horizontal_tab_bar_goto_prev_item(void)
{

}

MMI_BOOL cui_tab_is_in_tab_screen(void)
{
    return MMI_FALSE;
}


void ShowCategory219FmgrScreen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 num_of_items,
        GetAsyncItemFuncPtr get_item_func,
        GetAsyncHintFuncPtr get_hint_func,
        CatFmgrGetFileData get_menuitem_data,
        CatFmgrHideFileData hide_menuitem_data,
        U8 num_per_row,
        U8 num_per_col,
        S32 highlighted_item,
        U8 *history_buffer,
        S32 *category_error_flag)
{

}

#ifdef __MMI_ICONTEXT_BTN_DISPLAY_ICON__
PU8 get_softkey_icon(WGUI_SOFTKEY_ENUM key)
{
	return NULL;
}
#endif

MMI_BOOL mmi_frm_end_scenario(mmi_scenario_id scenario_id)
{
	return MMI_FALSE;
}

MMI_BOOL mmi_frm_start_scenario(mmi_scenario_id scenario_id)
{
	return MMI_FALSE;
}

void mmi_frm_init_scenario(void)
{

}

MMI_BOOL mmi_frm_is_scenario_started(mmi_scenario_id scenario_id)
{
	return MMI_FALSE;
}

void ShowCategory6Screen_ext(
                U8* title,
                U8* title_icon,
                U8* left_softkey,
                U8* left_softkey_icon,
                U8* right_softkey,
                U8* right_softkey_icon,
                S32 number_of_items,
                U8 **list_of_items,
                U8 **list_of_descriptions,
                S32 highlighted_item,
                U8 *history_buffer)
{
}

#endif/* __MMI_UI_DISPLAY_LEVEL_NONE__ */

