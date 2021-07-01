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
 *   wgui_categories_btbox.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Categories for BTBox
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

#include "mmi_features.h"

#if  defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__) || defined(__MMI_WEARABLE_DEVICE_SETTING__) || defined(__MMI_WEARABLE_DEVICE_ALARM__)

#include "CustDataRes.h"
#include "CustDataProts.h"
#include "lcd_if.h"
#include "ScreenRotationGprot.h"
#include "wgui_softkeys.h"
#include "Wgui_categories_util.h"
#include "wgui_touch_screen.h"
#include "gui_typedef.h"
#include "gui_themes.h"
#include "globalresdef.h"

#include "gui_font_size.h"

#include "CommonScreens.h"
#include "FileMgrSrvGProt.h"

#include "CustThemesRes.h"

#include "mmi_rp_app_uiframework_def.h"
#include "wgui_categories_btbox.h"



static wgui_cat8001_context g_cat8001_cntx;
#ifdef __MMI_GUI_PICKER__
static wgui_picker_context g_wgui_picker_cntx;
#endif /* #ifdef __MMI_GUI_PICKER__ */



/*****************************************************************************
 * FUNCTION
 *  wgui_cat8001_draw_ctrl_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category8001 screen.
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat8001_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 image_width = 0, image_height = 0;
	S32 interval = 0;
	U16 img_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if(g_cat8001_cntx.message_icon)
	{
		gdi_image_get_dimension_id(g_cat8001_cntx.message_icon, &image_width, &image_height);
		image_width = (image_width > MMI_content_width) ? MMI_content_width : image_width;
        image_height = (image_height > MMI_content_height-1) ? MMI_content_height-1 : image_height;
        interval = (MMI_content_height - 1 - image_height) >> 1;
        
		if (g_cat8001_cntx.anim_handle)
		{
			gdi_anim_stop(g_cat8001_cntx.anim_handle);
		}
        
        gdi_draw_solid_rect(MMI_content_x, MMI_content_y, UI_device_width,  UI_device_height - MMI_softkey_height - 1, GDI_COLOR_TRANSPARENT);

		img_type = gdi_image_get_type_from_id(g_cat8001_cntx.message_icon);
		if(g_cat8001_cntx.anim_play && GDI_IMAGE_TYPE_BMP_SEQUENCE == img_type) 
		{
			gdi_anim_draw_resized(
				(UI_device_width - image_width) >> 1, 
				MMI_content_y + interval,
				image_width, image_height,
				get_image(g_cat8001_cntx.message_icon), &g_cat8001_cntx.anim_handle);
		}
		else
		{	
			gdi_image_draw_resized_id(
				(UI_device_width - image_width) >> 1, 
				MMI_content_y + interval,
				image_width, image_height,
				g_cat8001_cntx.message_icon);
		}	
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat8001_exit
 * DESCRIPTION
 *  Exit category 8001
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat8001_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (g_cat8001_cntx.anim_handle)
	{
		gdi_anim_stop(g_cat8001_cntx.anim_handle);
	}
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat8001_set_animation
 * DESCRIPTION
 *  Set animation play or not
 * PARAMETERS
 *  play [IN] MMI_BOOL
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat8001_set_animation(MMI_BOOL play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    g_cat8001_cntx.anim_play = play;
}


/*****************************************************************************
* [Category8001]
*
* This category is for Linein.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *       (Icon)       *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
void ShowCategory8001Screen(
        U16 title,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        MMI_BOOL anim_play)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    clear_key_handlers();
    
    gdi_layer_lock_frame_buffer();

    gui_setup_common_layout();
	
    /* add title, softkey, image */
    dm_add_title_id(title, NULL);
    dm_add_softkey_id(left_softkey, right_softkey);

    g_cat8001_cntx.message_icon = message_icon;
    g_cat8001_cntx.anim_play = anim_play;

    gdi_layer_unlock_frame_buffer();
    
    dm_register_category_controlled_callback(wgui_cat8001_draw_ctrl_area);
    wgui_cat_setup_category_default_history(MMI_CAT8001_ID, NULL, wgui_cat8001_exit);
    dm_redraw_category_screen();
}


#ifdef __MMI_GUI_PICKER__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat_picker_switch_page
 * DESCRIPTION
 *  Switch two_page month&day or time.
 * PARAMETERS
 *  highlight_page
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_picker_switch_page(U8 highlight_page)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_picker_cntx.current_page = highlight_page;
    gui_picker_set_highlight(g_wgui_picker_cntx.current_page);
    mmi_frm_group_close(GRP_ID_BTBOX_PICKER_OPTION);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_picker_option_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  evt
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret wgui_cat_picker_option_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            if (menu_evt->parent_menu_id == MENU_ID_BTBOX_PICKER_OPTION_MENU)
            {
                if (g_wgui_picker_cntx.two_page || g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                {
                    if (g_wgui_picker_cntx.current_page == 2)
                    {
                        if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                        {
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, STR_ID_BTBOX_PICKER_SET_YEAR);
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, STR_ID_BTBOX_PICKER_SET_MONTH);
                        }
                    }
                    else if (g_wgui_picker_cntx.current_page == 1)
                    {
                        if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                        {
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, STR_ID_BTBOX_PICKER_SET_YEAR);
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, STR_ID_BTBOX_PICKER_SET_DAY);
                        }
                        else
                        {
                            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, MMI_TRUE);
                            if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_MONTH_AND_DAY)
                            {
                                cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, STR_ID_BTBOX_PICKER_SET_MONTH);
                            }
                            else if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_TIME)
                            {
                                cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, STR_ID_BTBOX_PICKER_SET_HOUR);
                            }
                        }
                    }
                    else
                    {
                        if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                        {
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, STR_ID_BTBOX_PICKER_SET_MONTH);
                            cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, STR_ID_BTBOX_PICKER_SET_DAY);
                        }
                        else
                        {
                            cui_menu_set_item_hidden(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_PREV, MMI_TRUE);
                            if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_MONTH_AND_DAY)
                            {
                                cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, STR_ID_BTBOX_PICKER_SET_DAY);
                            }
                            else if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_TIME)
                            {
                                cui_menu_set_item_string_by_id(menu_evt->sender_id, MENU_ID_BTBOX_PICKER_NEXT, STR_ID_BTBOX_PICKER_SET_MINUTE);
                            }
                        }
                    }
                }
            }
    
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_HILITE:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_BTBOX_PICKER_PREV:
                case MENU_ID_BTBOX_PICKER_NEXT:
                case MENU_ID_BTBOX_PICKER_SAVE:
            #ifdef __MMI_TOUCH_SCREEN__
                    wgui_reset_list_item_selected_callback();
            #endif
                    break;

                default:
                    break;
            }
            break;
        }
        case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            switch(menu_evt->highlighted_menu_id)
            {
                case MENU_ID_BTBOX_PICKER_PREV :
                    if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                    {
                        if (g_wgui_picker_cntx.current_page > 0)
                        {
                            wgui_cat_picker_switch_page(0);
                        }
                        else
                        {
                            wgui_cat_picker_switch_page(1);
                        }
                    }
                    else
                    {
                        wgui_cat_picker_switch_page(0);
                    }
                    break;

                case MENU_ID_BTBOX_PICKER_NEXT:
                    if (g_wgui_picker_cntx.picker_type == GUI_PICKER_TYPE_DATE)
                    {
                        if (g_wgui_picker_cntx.current_page < 2)
                        {
                            wgui_cat_picker_switch_page(2);
                        }
                        else
                        {
                            wgui_cat_picker_switch_page(1);
                        }
                    }
                    else
                    {
                        wgui_cat_picker_switch_page(1);
                    }
                    break;

                case MENU_ID_BTBOX_PICKER_SAVE:
                    g_wgui_picker_cntx.save_func();
                    GoBackHistory();
                    break;

                default:
                    break;
            } 
           break;                       
        }
        case EVT_ID_CUI_MENU_LIST_EXIT:
            break;
        
        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
            cui_menu_close(menu_evt->sender_id);
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_karaoke_list_entry_option
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_picker_entry_option(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_group_is_present(GRP_ID_BTBOX_PICKER_OPTION))
    {
        mmi_frm_group_close(GRP_ID_BTBOX_PICKER_OPTION);
    }

    mmi_frm_group_create_ex(
        GRP_ID_BTBOX_PICKER, 
        GRP_ID_BTBOX_PICKER_OPTION, 
        wgui_cat_picker_option_proc, 
        NULL, 
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    cui_menu_create_and_run(
        GRP_ID_BTBOX_PICKER_OPTION, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_OPTION, 
        MENU_ID_BTBOX_PICKER_OPTION_MENU, 
        MMI_FALSE, 
        NULL);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_picker_draw_ctrl_area
 * DESCRIPTION
 *  This function is used to draw the category controlled area of picker screen.
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_picker_draw_ctrl_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_picker_show();
}


/*****************************************************************************
* [CategoryPicker]
*
* This category is for DateTime Setting.
* use the same category ID of ShowCategory8001Screen
* Picker must take the whole control area
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *       Picker      *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
void wgui_cat_picker_show_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = DM_NO_TITLE;
    U8* user_data = gui_picker_get_user_data();
    gui_picker_header *header;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    entry_full_screen();
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    clear_key_handlers();    

    header = (gui_picker_header*)user_data;
    
    g_wgui_picker_cntx.picker_type = header->type;
    
    gdi_layer_lock_frame_buffer();
    gui_setup_common_layout();
    
    if (header->type == GUI_PICKER_TYPE_YEAR)
    {
        dm_add_title_id(STR_ID_BTBOX_PICKER_SET_YEAR, NULL);
        g_wgui_picker_cntx.two_page = MMI_FALSE;
    }
    else if (header->type == GUI_PICKER_TYPE_MONTH_AND_DAY)
    {
        gui_picker_month_and_day_struct *picker_month_and_day = (gui_picker_month_and_day_struct*)user_data;
        g_wgui_picker_cntx.two_page = picker_month_and_day->two_page;
        dm_add_title_id(STR_ID_BTBOX_PICKER_SET_MONTH_AND_DAY, NULL);
    }
    else if(header->type == GUI_PICKER_TYPE_TIME)//change by xl
    {
        gui_picker_time_struct *picker_time = (gui_picker_time_struct*)user_data;
        g_wgui_picker_cntx.two_page = picker_time->two_page;
        dm_add_title_id(STR_ID_BTBOX_PICKER_SET_TIME, NULL);
    }
	#ifdef __MMI_WEARABLE_DEVICE__
	else //date
	{
		gui_picker_date_struct *picker_date = (gui_picker_date_struct*)user_data;	
		g_wgui_picker_cntx.two_page = picker_date->two_page;
		
	}
	#endif //	#ifdef __MMI_WEARABLE_DEVICE__

    if (g_wgui_picker_cntx.two_page)
    {
        gui_picker_set_highlight(g_wgui_picker_cntx.current_page); 
		#ifdef __MMI_WEARABLE_DEVICE__
		dm_add_softkey_id(STR_GLOBAL_OK, STR_GLOBAL_CANCEL);
		#else
        dm_add_softkey_id(STR_GLOBAL_OPTIONS, STR_GLOBAL_BACK);
		#endif /*__MMI_WEARABLE_DEVICE__*/
        SetLeftSoftkeyFunction(wgui_cat_picker_entry_option, KEY_EVENT_UP);
    }
    else
    {
		#ifdef __MMI_WEARABLE_DEVICE__
		dm_add_softkey_id(STR_GLOBAL_OK, STR_GLOBAL_CANCEL);
		#else
        dm_add_softkey_id(STR_GLOBAL_SAVE, STR_GLOBAL_BACK);
		#endif /*__MMI_WEARABLE_DEVICE__*/
        SetLeftSoftkeyFunction(g_wgui_picker_cntx.save_func, KEY_EVENT_UP);
    }
    
    gdi_layer_unlock_frame_buffer();
#ifdef __MMI_WEARABLE_DEVICE__
	flags |= DM_SHOW_SWATCH_SOFTKEY;
#endif /*__MMI_WEARABLE_DEVICE__*/
    dm_register_category_controlled_callback(wgui_cat_picker_draw_ctrl_area);
    wgui_cat_setup_category_default_history(MMI_CAT8001_ID, flags, UI_dummy_function);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_picker_proc
 * DESCRIPTION
 *   
 * PARAMETERS
 *  evt
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret wgui_picker_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
		case EVT_ID_SCRN_INACTIVE:
		{
			gui_picker_reset();
			break;
		}
        case EVT_ID_GROUP_EXIT:
        {
            //reset context
            memset(&g_wgui_picker_cntx, 0, sizeof(wgui_picker_context));
            break;
        }
        case EVT_ID_SCRN_ACTIVE:
        {
            wgui_cat_picker_show_screen();
            break;
        }
    }
    return MMI_RET_OK;   
}


/*****************************************************************************
 * FUNCTION
 *  wgui_picker_entry
 * DESCRIPTION
 *  Entry Picker
 * PARAMETERS
 *  user_data
 *  group_id
 *  save_func
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_picker_entry(U8* user_data, mmi_id group_id, FuncPtr save_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result = GUI_PICKER_NO_ERROR;
    gui_bound bound;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(user_data != NULL && save_func != NULL);
    
	#ifdef __MMI_WEARABLE_DEVICE__
	bound.x = 0;
	bound.y = 0;
	bound.width = UI_device_width;
	bound.height = UI_device_height - MMI_SW_BUTTON_BAR_HEIGHT;
	#else
	bound.x = 0;
    bound.y = MMI_title_y + 2;//MMI_content_y;
    bound.width = UI_device_width;
    bound.height = MMI_title_height + MMI_content_height - 3;
	#endif /*__MMI_WEARABLE_DEVICE__*/
    result = gui_picker_create(user_data, bound);
    MMI_TRACE(MMI_FW_TRC_G2_GUI, TRC_GUI_PICKER_ENTER, result);
    MMI_ASSERT(result == GUI_PICKER_NO_ERROR);

    g_wgui_picker_cntx.save_func = save_func;

    if (mmi_frm_group_is_present(GRP_ID_BTBOX_PICKER))
    {
        mmi_frm_group_close(GRP_ID_BTBOX_PICKER);
    }
    
    mmi_frm_group_create_ex(
        group_id,
        GRP_ID_BTBOX_PICKER,
        wgui_picker_proc,
        NULL,
        MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_BTBOX_PICKER, SCR_ID_BTBOX_PICKER, wgui_picker_proc, NULL);
}

#endif /*#ifdef __MMI_GUI_PICKER__*/
#endif  /*defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__)*/ 

#ifdef __KARAOKE_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat8002_exit
 * DESCRIPTION
 *  Exit category 8002
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat8002_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

/*****************************************************************************
* [Category8002]
*
* This category is for karaoke.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *       Lyric      *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
void ShowCategory8002Screen(
        U16 title,
        U16 left_softkey,
        U16 right_softkey)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 flags = DM_NO_TITLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_full_screen();
    clear_screen();
    clear_key_handlers();
    
    gdi_layer_lock_frame_buffer();

    gui_setup_common_layout();
	
    /* add title, softkey, image */
    //dm_add_title_id(title, NULL);
    dm_add_softkey_id(left_softkey, right_softkey);
	
    gdi_layer_unlock_frame_buffer();
    
    SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    SetKeyHandler(NULL, KEY_CSK, KEY_EVENT_UP);

    wgui_cat_setup_category_default_history(MMI_CAT8002_ID, flags, wgui_cat8002_exit);
    dm_redraw_category_screen();
}

#endif
