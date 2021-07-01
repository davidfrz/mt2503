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
*  wgui_dynamic_menuitems.c
*
* Project:
* --------
*  PlutoMMI
*
* Description:
* ------------
*  In order to use limited memory (size decided in compile-time) to load unlimited items (size decide in run-time) 
*  to a category screen, a modification in MMI for dynamic item loading is required as the following.
*
* Author:
* -------
 * -------
*
*******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "gui_setting.h"
#include "wgui.h"
#include "wgui_fixed_menuitems.h"
#include "wgui_dynamic_menuitems.h"
#include "gui_dynamic_menus.h"
#include "MMIDataType.h"
#include "gui_typedef.h"
#include "MMI_features.h"
#include "gui.h"
#include "gui_fixed_menuitems.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "gui_switch.h"
#include "lcd_sw_inc.h"
#include "gui_effect_oem.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "gui_scrollbars.h"


/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
dynamic_item_circular_buffer_t dynamic_item_buffer;
BOOL dynamic_item_text_align_left = FALSE;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  init_dynamic_item_buffer
 * DESCRIPTION
 *  Initialize the global dynamic item buffer.
 * PARAMETERS
 *  n_items             [IN]        total number of items
 *  get_item_func       [IN]        a callback function for filling in item text & image at run time
 *  get_hint_func       [IN]        a callback function to get hint data
 *  flush_data_func     [IN]        a callback function when cached data is flushed (flush_dynamic_item_buffer_before_load_chunk())
 * RETURNS
 *  void
 *****************************************************************************/
void init_dynamic_item_buffer(
        S32 n_items,
        GetItemFuncPtr get_item_func,
        GetHintFuncPtr get_hint_func,
        FlushDataFuncPtr flush_data_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&dynamic_item_buffer, 0, sizeof(dynamic_item_circular_buffer_t));
    dynamic_item_buffer.load_func = get_item_func;
    dynamic_item_buffer.hint_func = get_hint_func;
    dynamic_item_buffer.flush_func = flush_data_func;

#ifdef __MMI_UI_LIST_HIGHLIGHT_EFFECTS__
    gui_add_cleanup_hook(gui_stop_list_highlight_effect);
#endif 

    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
    {
        /* Special case for JAM (Java application manager) */
        if (flush_data_func)
        {
            flush_data_func();
        }
    }
    dynamic_item_buffer.n_total_items = n_items;
}


/*****************************************************************************
 * FUNCTION
 *  load_dynamic_item_buffer
 * DESCRIPTION
 *  Load items into the buffer.
 * PARAMETERS
 *  n_items     [IN]        total number of items
 * RETURNS
 *  void
 *****************************************************************************/
void load_dynamic_item_buffer(S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    PU8 image = NULL;
    U32 flags = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_buffer.head_item_index = 0;
    dynamic_item_buffer.head = 0;
    dynamic_item_buffer.tail = 0;
    dynamic_item_buffer.count = 0;
    dynamic_item_buffer.n_total_items = n_items;
    if (n_items > MAX_DYNAMIC_ITEMS_BUFF)
    {
        n_items = MAX_DYNAMIC_ITEMS_BUFF;
    }

    if (dynamic_item_text_align_left)
    {
        flags = UI_MENUITEM_DISABLE_ICON;
    }

    for (i = 0; i < n_items; i++)
    {
        if (dynamic_item_buffer.load_func(i, (UI_string_type) subMenuData[i], &image, 3))
        {
            MMI_fixed_icontext_menuitems[i].item_icon = image;
            MMI_fixed_icontext_menuitems[i].item_text = (UI_string_type) subMenuData[i];
            MMI_fixed_icontext_menuitems[i].flags = flags;
            MMI_fixed_icontext_menuitems[i].text_width = 0;
            MMI_fixed_icontext_menuitems[i].text_height = 0;
            dynamic_item_buffer.count++;
        }
        else
        {
            break;
        }
    }
    dynamic_item_buffer.tail = dynamic_item_buffer.count & MASK_DYNAMIC_ITEMS_BUFF;
}


/*****************************************************************************
 * FUNCTION
 *  get_dynamic_item_from_buffer
 * DESCRIPTION
 *  Get the specified item in the buffer.
 * PARAMETERS
 *  index       [IN]        item index to be retrieved
 * RETURNS
 *  An icontext menu item
 *****************************************************************************/
fixed_icontext_menuitem_type *get_dynamic_item_from_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* pre-condition: in_dynamic_item_buffer( index ) return TRUE */
    return &MMI_fixed_icontext_menuitems[(index - dynamic_item_buffer.head_item_index +
                                          dynamic_item_buffer.head) & MASK_DYNAMIC_ITEMS_BUFF];
}


/*****************************************************************************
 * FUNCTION
 *  in_dynamic_item_buffer
 * DESCRIPTION
 *  Check whether an item is already loaded in the buffer.
 * PARAMETERS
 *  index       [IN]        item index to be checked
 * RETURNS
 *  Return TRUE if the specified item exists in the buffer; otherwise, FALSE.
 *****************************************************************************/
MMI_BOOL in_dynamic_item_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dynamic_item_buffer.count == 0)
    {
        return MMI_FALSE;
    }
    count = index - dynamic_item_buffer.head_item_index;

	return (count >= 0 && count < dynamic_item_buffer.count);
}


/*****************************************************************************
 * FUNCTION
 *  flush_dynamic_item_buffer_before_load_chunk
 * DESCRIPTION
 *  Flush the buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void flush_dynamic_item_buffer_before_load_chunk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dynamic_item_buffer.head_item_index = 0;
    dynamic_item_buffer.head = 0;
    dynamic_item_buffer.tail = 0;
    dynamic_item_buffer.count = 0;

    if (dynamic_item_buffer.flush_func)
    {
        dynamic_item_buffer.flush_func();
    }
    /* Keep n_total_items, load_func, flush_func, and hint_func unchanged */
}


/*****************************************************************************
 * FUNCTION
 *  load_chunk_dynamic_item_buffer
 * DESCRIPTION
 *  Load a chunk of items, starting from [start_index] to [start_index + n_items-1], to buffer.
 *  The loading mechanism will try to maintain the continuous buffer as large as possible.
 * PARAMETERS
 *  start_index     [IN]        the starting index of requested items
 *  n_items         [IN]        the number of items to be loaded
 * RETURNS
 *  The number of items that are loaded successfully.
 *****************************************************************************/
S32 load_chunk_dynamic_item_buffer(S32 start_index, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 i, count, start, offset, index;
    PU8 image = NULL;
    U32 flags = 0;
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN 
    MMI_BOOL use_load = MMI_FALSE;
#endif/* GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * If UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA is set, flush_dynamic_item_buffer_before_load_chunk()
     * * should be invoked before load_chunk_dynamic_item_buffer().
     */
    MMI_ASSERT(!(MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA) ||
               (n_items <= MMI_MAX_MENUITEMS_IN_CONTENT && dynamic_item_buffer.count == 0));

    offset = start_index - dynamic_item_buffer.head_item_index;
    /* protect when n_items > MAX_DYNAMIC_ITEMS_BUFF */
    if (n_items > MAX_DYNAMIC_ITEMS_BUFF)
    {
        n_items = MAX_DYNAMIC_ITEMS_BUFF;
    }
    else if (start_index + n_items > dynamic_item_buffer.n_total_items)
    {
        n_items = dynamic_item_buffer.n_total_items - start_index;
    }

    if (n_items <= 0)
    {
        return 0;
    }

    /* protect when index out of bound */
    if (offset + n_items > dynamic_item_buffer.n_total_items)
    {
        n_items = dynamic_item_buffer.n_total_items - offset;
    }
    start = (offset + dynamic_item_buffer.head) & MASK_DYNAMIC_ITEMS_BUFF;

    if (dynamic_item_text_align_left)
    {
        flags = UI_MENUITEM_DISABLE_ICON;
    }

    for (count = 0, index = start_index, i = start; count < n_items;
         count++, index++, i = (i + 1) & MASK_DYNAMIC_ITEMS_BUFF)
    {
        
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
        if (!in_dynamic_item_buffer(index))
        {
            if (wgui_list_menu_slow_data_mode && gui_screen_smooth_scrolling_in_freerun())
            {
                mmi_ucs2cpy((CHAR *)subMenuData[i], (CHAR *)GetString(STR_GLOBAL_LOADING));
                MMI_fixed_icontext_menuitems[i].item_icon = NULL;
                MMI_fixed_icontext_menuitems[i].item_text = (UI_string_type) subMenuData[i];
                MMI_fixed_icontext_menuitems[i].flags = flags;
                MMI_fixed_icontext_menuitems[i].text_width = 0;
                MMI_fixed_icontext_menuitems[i].text_height = 0;
                use_load = MMI_TRUE;
            }
            else if (dynamic_item_buffer.load_func(index, (UI_string_type) subMenuData[i], &image, 3))
            {
                MMI_fixed_icontext_menuitems[i].item_icon = image;
                MMI_fixed_icontext_menuitems[i].item_text = (UI_string_type) subMenuData[i];
                MMI_fixed_icontext_menuitems[i].flags = flags;
                MMI_fixed_icontext_menuitems[i].text_width = 0;
                MMI_fixed_icontext_menuitems[i].text_height = 0;
            }
            else
            {
                break;
            }
        }
#else
        if (!in_dynamic_item_buffer(index))
        {
            if (dynamic_item_buffer.load_func(index, (UI_string_type) subMenuData[i], &image, 3))
            {
                MMI_fixed_icontext_menuitems[i].item_icon = image;
                MMI_fixed_icontext_menuitems[i].item_text = (UI_string_type) subMenuData[i];
                MMI_fixed_icontext_menuitems[i].flags = flags;
                MMI_fixed_icontext_menuitems[i].text_width = 0;
                MMI_fixed_icontext_menuitems[i].text_height = 0;
            }
            else
            {
                break;
            }
        }
#endif
    }

    if (count == 0
#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN 
		|| use_load
#endif/*#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN */		
		)
    {
        return 0;
    }
    if (dynamic_item_buffer.count == 0 || (offset < 0 && offset + count < 0) || (offset > dynamic_item_buffer.count))
    {
        dynamic_item_buffer.head_item_index = start_index;
        dynamic_item_buffer.head = start;
        dynamic_item_buffer.tail = i;
        dynamic_item_buffer.count = count;
    }
    else if (offset < 0)
    {
        dynamic_item_buffer.head_item_index = start_index;
        dynamic_item_buffer.head = start;
        size = dynamic_item_buffer.count - offset;
        if (size > MAX_DYNAMIC_ITEMS_BUFF)
        {
            size = MAX_DYNAMIC_ITEMS_BUFF;
        }
        else if (size < count)
        {
            size = count;
        }
        dynamic_item_buffer.tail = (start + size) & MASK_DYNAMIC_ITEMS_BUFF;
        dynamic_item_buffer.count = size;
    }
    else
    {
        size = count + offset;
        if (size > MAX_DYNAMIC_ITEMS_BUFF)
        {
            dynamic_item_buffer.head = dynamic_item_buffer.tail = i;
            dynamic_item_buffer.head_item_index = index - MAX_DYNAMIC_ITEMS_BUFF;
            dynamic_item_buffer.count = MAX_DYNAMIC_ITEMS_BUFF;
        }
        else if (size > dynamic_item_buffer.count)
        {
            dynamic_item_buffer.tail = (dynamic_item_buffer.head + size) & MASK_DYNAMIC_ITEMS_BUFF;
            dynamic_item_buffer.count = size;
        }
    }

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  resize_dynamic_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the dynamic menu item width to the maximum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_dynamic_icontext_menuitems_to_list_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifndef __MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__		
    if (MMI_fixed_list_menu.flags & UI_LIST_MENU_AUTO_DISABLE_SCROLLBAR)
    {
#endif/*__MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__*/    
    	wgui_show_list_menu_no_draw(gui_show_dynamic_list_menu);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//		
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_icontext_menuitems(
                MMI_fixed_list_menu.width - 4,
                MMI_fixed_icontext_menuitem.height );
        }
#ifndef __MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__			
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_icontext_menuitems(MMI_fixed_list_menu.width - 4, MMI_fixed_icontext_menuitem.height);
    }
#endif/*__MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__*/	
}

//add by huking

/*****************************************************************************
 * FUNCTION
 *  gui_list_menu_noncache_flush_and_load_chunk_item_buffer
 * DESCRIPTION
 *  gui_list_menu_noncache_flush_and_load_chunk_item_buffer
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_list_menu_noncache_flush_and_load_chunk_item_buffer(fixed_list_menu*m)

{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (m->flags & UI_LIST_MENU_DISABLE_CACHE_DYNAMIC_DATA)
	{
		flush_dynamic_item_buffer_before_load_chunk();
	}
}



//end huking add

