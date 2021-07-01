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
 *  wgui_asyncdynamic_menuitems.c
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
 *  Compared to dynamic list menu, 
 *  1. it gets data of multiple menu items in one callback function,
 *  2. it uses icontext-list menu item instead of icontext menu item.
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
#include "wgui_fixed_menuitems.h"
#include "wgui_asyncdynamic_menuitems.h"
#include "gui_asyncdynamic_menus.h"
#include "gui_typedef.h"
#include "GlobalConstants.h"
#include "MMIDataType.h"
#include "gui_fixed_menuitems.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "kal_general_types.h"
#include "gui_theme_struct.h"
#include "gui_data_types.h"
#include "mmi_frm_events_gprot.h"
#include "gui_effect_oem.h"
#include "wgui_fixed_menus.h"
#include "gui_fixed_menus.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "gdi_const.h"
#include "gui_scrollbars.h"
#include "Gui_dynamic_menus.h"


#if (MAX_FIXED_ICONTEXT_LIST_MENU_ITEMS < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
#error "Internal parameter error"
#endif 

#if (MAX_SUB_MENUS < MAX_ASYNCDYNAMIC_ITEMS_BUFF)
#error "Internal parameter error"
#endif

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
static wgui_asyncdynamic_menuitem_load_complete_funcptr_type wgui_asyncdynamic_menuitem_load_complete_callback;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
asyncdynamic_item_circular_buffer_t asyncdynamic_item_buffer;

/***************************************************************************** 
 * Local Function
 *****************************************************************************/

/***************************************************************************** 
 * Global Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  init_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Iitialize the asyncdynamic item buffer.
 *
 *  a. If the icontext-list menu item has more than one string, it can not support hint callback
 *  because hint and secnd string item use the same memory buffer.
 *  b. If 'history' is not NULL, 'h_item' is ignored. 
 * PARAMETERS
 *  total_items         [IN]        total number of items
 *  get_item_func       [IN]        A call back function for filling in item text & image at run time
 *  get_hint_func       [IN]        Callback funtion for filling hint data
 * RETURNS
 *  Return 1 if sucessful; otherwise 0.
 *****************************************************************************/
void init_asyncdynamic_item_buffer(S32 total_items, GetAsyncItemFuncPtr get_item_func, GetAsyncHintFuncPtr get_hint_func)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	memset(&asyncdynamic_item_buffer, 0, sizeof(asyncdynamic_item_circular_buffer_t));
    asyncdynamic_item_buffer.n_total_items = total_items;
    asyncdynamic_item_buffer.load_func = get_item_func;
    asyncdynamic_item_buffer.hint_func = get_hint_func;

    /* asyncdynamic_list_goto_item_no_redraw() will load the data */
  //  return 1;
}


/*****************************************************************************
 * FUNCTION
 *  get_asyncdynamic_item_from_buffer
 * DESCRIPTION
 *  Get the specified item in the buffer.
 * PARAMETERS
 *  index       [IN]        item index to be retrieved
 * RETURNS
 *  An icontext list menu item
 *****************************************************************************/
fixed_icontext_list_menuitem_type *get_asyncdynamic_item_from_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 offset;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    offset = index - asyncdynamic_item_buffer.head_item_index;

	MMI_ASSERT(offset >= 0 && offset < asyncdynamic_item_buffer.count);
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
    return &MMI_fixed_icontext_list_menuitems[(offset + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
}


/*****************************************************************************
 * FUNCTION
 *  in_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Check whether a item is loaded in buffer
 * PARAMETERS
 *  index       [IN]        item index to be checked
 * RETURNS
 *  Return TRUE if the specified item exists in the buffer; otherwise, FALSE.
 *****************************************************************************/
pBOOL in_asyncdynamic_item_buffer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (asyncdynamic_item_buffer.count == 0)
    {
        return FALSE;
    }
    count = index - asyncdynamic_item_buffer.head_item_index;
    if (count < 0 || count >= asyncdynamic_item_buffer.count)
    {
        return FALSE;
    }
    return TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  flush_asyncdynamic_item_buffer_before_load_chunk
 * DESCRIPTION
 *  Flush the buffer.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void flush_asyncdynamic_item_buffer_before_load_chunk(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    asyncdynamic_item_buffer.head_item_index = 0;
    asyncdynamic_item_buffer.head = 0;
    asyncdynamic_item_buffer.tail = 0;
    asyncdynamic_item_buffer.count = 0;
    /* Keep n_total_items, load_func, flush_func, and hint_func unchanged */
}

/*****************************************************************************
 * FUNCTION
 *  load_chunk_asyncdynamic_item_buffer
 * DESCRIPTION
 *  Load a chunk of items, starting from [start_index] to [start_index+n_items-1], to the buffer.
 *  The loading mechanism will try to maintain the continuous buffer as large as possible.
 * PARAMETERS
 *  start_index     [IN]        the starting index of requested items
 *  n_items         [IN]        the number of items to be loaded
 * RETURNS
 *  1: success, 0: fail
 *****************************************************************************/
S32 load_chunk_asyncdynamic_item_buffer(S32 start_index, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 size;
    S32 i, j;
    S32 start;  /* Start index in queue */
    S32 offset; /* Offset to queue head */
    S32 count;  /* count of loaded menu item */
    gui_iconlist_menu_item md[MAX_ASYNCDYNAMIC_ITEMS_BUFF];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* Use two array subMenuData[] and hintData[] only. */
    /* MMI_DBG_ASSERT(!asyncdynamic_item_buffer.hint_func || MMI_fixed_icontext_list_menuitem.n_text_columns <= 1); */
    MMI_DBG_ASSERT(MMI_fixed_icontext_list_menuitem.n_text_columns <= FIXED_ICONTEXT_LIST_MAX_TEXT_COLUMNS);

    /*
     * FIXME. 
     * 1. the algorithm is slightly different than load_chunk_dynamic_item_buffer() 
     * it should be revised some day.
     *
     * 2. The performance can be improved if some data is already in the queue.
     * This is okay because n_items is typically 1 or 2. However, n_items might be large
     * with touch screen.
     * 
     */

    /* 
     * Compute the number of menu item to load 
     */
    if (asyncdynamic_item_buffer.count == 0)
    {
        offset = 0;
    }
    else    /* sometimes offset < 0 */
    {
        offset = start_index - asyncdynamic_item_buffer.head_item_index;
    }

    if (n_items > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
    {
        n_items = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
    }

    if (start_index + n_items > asyncdynamic_item_buffer.n_total_items)
    {
        n_items = asyncdynamic_item_buffer.n_total_items - start_index;
    }

    if (n_items <= 0)
    {
        return 0;
    }

    /* 
     * Get the data 
     */
    for (i = 0; i < n_items; i++)   /* Use md[] to hold data temporarily */
    {
        /* We hold data in subMenuData[] and hintData[]. */
        md[i].item_list[0] = (UI_string_type)subMenuData[(i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];        
        md[i].item_list[1] = (UI_string_type)hintData[(i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF];
        
        /* The 3rd text column shares hintData[][] with the 2nd text column. */
        MMI_ASSERT(MAX_ASYNCDYNAMIC_ITEMS_BUFF * 2 <= MAX_SUB_MENUS);
        md[i].item_list[2] = (UI_string_type)hintData[((i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF) + MAX_ASYNCDYNAMIC_ITEMS_BUFF];
		md[i].item_list[3] = (UI_string_type)subMenuData[((i + start_index) & MASK_ASYNCDYNAMIC_ITEMS_BUFF) + MAX_ASYNCDYNAMIC_ITEMS_BUFF];

        md[i].image_list[0] = NULL;
        md[i].image_list[1] = NULL;
        md[i].image_list[2] = NULL;
        md[i].image_list[3] = NULL;
        
		#ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
		md[i].item_icon_flags[0] = 0;
        md[i].item_icon_flags[1] = 0;
        md[i].item_icon_flags[2] = 0;
        md[i].item_icon_flags[3] = 0;
		md[i].item_icon_len[0] = 0;
        md[i].item_icon_len[1] = 0;
        md[i].item_icon_len[2] = 0;
        md[i].item_icon_len[3] = 0;
		#endif /*__MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__*/
        md[i].flag = 0;
        md[i].flag_ext = 0;
    }
#if defined(GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN)||defined(GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN)
    if (wgui_list_menu_slow_data_mode && gui_screen_smooth_scrolling_in_freerun())
        count = -1;
    else
#endif/*GUI_MATRIX_MENU_SMOOTH_SCROLLING_BY_PEN*/		
        count = asyncdynamic_item_buffer.load_func(start_index, md, n_items);
//	#ifdef GUI_LIST_MENU_SMOOTH_SCROLLING_BY_PEN
    if (count != n_items && count != -1)
    {
        /* Data loaded fail */
        return 0;
    }
    else if (count != n_items)
    {
        gui_asyncdynamic_list_loading_error = MMI_TRUE;

        if (count < 0)
        {
            count = 0;
        }
        for (i = count; i < n_items; i++)
        {
            for (j = 0; j < MMI_fixed_icontext_list_menuitem.n_text_columns; j++)
            {
                if (MMI_fixed_list_menu.show_loading_index == j || MMI_fixed_list_menu.show_loading_index == -1)
                {
                    mmi_ucs2cpy((CHAR *)md[i].item_list[j], (CHAR *)GetString(STR_GLOBAL_LOADING));
                }
                else
                {
                    mmi_ucs2cpy((CHAR *)md[i].item_list[j], (CHAR *)L"\0");
                }
            }
            md[i].image_list[0] = (PU8) GetImage(IMG_GLOBAL_FONT_1);
            /* fill null pointer to prevent abnormal cases */
            for (j = 1; j < MMI_fixed_icontext_list_menuitem.n_icon_columns; j++)
            {
                md[i].image_list[j] = NULL;
            }
        }
        count = n_items;
    }
    else
    {
        gui_asyncdynamic_list_loading_error = MMI_FALSE;
    }
//	#else
//	    if (count != n_items)
//	    {
//	        /* Data loaded fail */
//	        return 0;
//	    }
//	#endif

    start = (offset + asyncdynamic_item_buffer.head) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;

    for (i = 0; i < n_items; i++)
    {
        S32 k = (i + start) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;

        for (j = 0; j < MMI_fixed_icontext_list_menuitem.n_icon_columns; j++)
        {
            MMI_fixed_icontext_list_menuitems[k].item_icons[j] = md[i].image_list[j];
			#ifdef __MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__
			MMI_fixed_icontext_list_menuitems[k].item_icon_flags[j] = md[i].item_icon_flags[j];
            MMI_fixed_icontext_list_menuitems[k].item_icon_len[j] = md[i].item_icon_len[j];
			#endif /*__MMI_WEARABLE_DEVICE_NOTI_UI_ENHANCE__*/
        }

        for (j = 0; j < MMI_fixed_icontext_list_menuitem.n_text_columns; j++)
        {
            MMI_fixed_icontext_list_menuitems[k].item_texts[j] = md[i].item_list[j];
        }

        for (j = 0; j < FIXED_ICONTEXT_LIST_MAX_ICON_COLUMNS; j++)
        {
            /* Icon animation is not enabled, but it can be supported easily */
            MMI_fixed_icontext_list_menuitems[k].item_icon_handles[j] = GDI_ERROR_HANDLE;
        }

        
        /*MMI_fixed_icontext_list_menuitems[k].flags = md->flag;
        MMI_fixed_icontext_list_menuitems[k].ext_flags = md->flag_ext;*/
		MMI_fixed_icontext_list_menuitems[k].flags = md[i].flag;
        MMI_fixed_icontext_list_menuitems[k].ext_flags = md[i].flag_ext;
    }

    /* 
     * Setup queue head & tail
     */
    if (asyncdynamic_item_buffer.count == 0 || (offset < 0 && offset + count < 0) ||
        (offset > asyncdynamic_item_buffer.count))
    {
        /* Drop all old data */
        asyncdynamic_item_buffer.head_item_index = start_index;
        asyncdynamic_item_buffer.head = start;
        asyncdynamic_item_buffer.tail = (start + count) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
        asyncdynamic_item_buffer.count = count;
    }
    else if (offset < 0)
    {
        /* Move head backward */
        asyncdynamic_item_buffer.head_item_index = start_index;
        asyncdynamic_item_buffer.head = start;
        size = asyncdynamic_item_buffer.count - offset;
        if (size > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
        {
            size = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
        }
        else if (size < count)
        {
            size = count;
        }
        asyncdynamic_item_buffer.tail = (start + size) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
        asyncdynamic_item_buffer.count = size;
    }
    else
    {
        size = count + offset;
        if (size > MAX_ASYNCDYNAMIC_ITEMS_BUFF)
        {
            asyncdynamic_item_buffer.head = asyncdynamic_item_buffer.tail =
                (start + count) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
            asyncdynamic_item_buffer.head_item_index = start_index + count - MAX_ASYNCDYNAMIC_ITEMS_BUFF;
            MMI_DBG_ASSERT(asyncdynamic_item_buffer.head_item_index >= 0);
            asyncdynamic_item_buffer.count = MAX_ASYNCDYNAMIC_ITEMS_BUFF;
        }
        else if (size > asyncdynamic_item_buffer.count)
        {
            asyncdynamic_item_buffer.tail = (asyncdynamic_item_buffer.head + size) & MASK_ASYNCDYNAMIC_ITEMS_BUFF;
            asyncdynamic_item_buffer.count = size;
        }
    }
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
    return 1;
}


/*****************************************************************************
 * FUNCTION
 *  resize_asyncdynamic_icontext_menuitems_to_list_width
 * DESCRIPTION
 *  Resize the asyncdynamic menu item width to the maximum.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void resize_asyncdynamic_icontext_menuitems_to_list_width(void)
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
    	wgui_show_list_menu_no_draw(gui_show_asyncdynamic_list_menu);
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0		
        if (MMI_fixed_list_menu.vbar.scale >= MMI_fixed_list_menu.vbar.range)
        {
            resize_fixed_icontext_list_menuitems(
                MMI_fixed_list_menu.width - 4,
                MMI_fixed_icontext_list_menuitem.height);
        }
#ifndef __MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__			
    }
    else if (MMI_fixed_list_menu.flags & UI_LIST_MENU_DISABLE_SCROLLBAR)
    {
        resize_fixed_icontext_list_menuitems(MMI_fixed_list_menu.width - 4, MMI_fixed_icontext_list_menuitem.height);
    }
#endif/*__MMI_UI_MENU_AUTO_DISABLE_SCROLLBAR__*/	
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
#endif//0
//add by huking
/*****************************************************************************
 * FUNCTION
 *  wgui_asyncdynamic_menuitem_register_load_complete_callback
 * DESCRIPTION
 *  Registers the load complete callback after items are loaded in load_chunk_asyncdynamic_item_buffer().
 * PARAMETERS
 *  callback       [IN]     load complete callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_asyncdynamic_load_chunk_error(S32 first_item, S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (!gui_asyncdynamic_list_error && !load_chunk_asyncdynamic_item_buffer(first_item, n_items))
    {
        gui_asyncdynamic_list_error = MMI_TRUE;
    }
}


//end huking add

