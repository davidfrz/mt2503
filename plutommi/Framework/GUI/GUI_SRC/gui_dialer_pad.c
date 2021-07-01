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
 *   gui_dialer_pad.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  Dialer Pad
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "mmi_features.h"
#include "gui_dialer_pad.h"

#ifdef __MMI_UI_DIALER_PAD__
#include "CustDataRes.h"
#include "CustDataProts.h"
#include "lcd_if.h"
#include "ScreenRotationGprot.h"
#include "wgui_softkeys.h"
#include "wgui_touch_screen.h"
#include "gui_typedef.h"
#include "mmi_frm_input_gprot.h"
#include "Gui_themes.h"
#include "gpiosrvgprot.h"

#include "gui_font_size.h"

#include "CommonScreens.h"

#include "CustThemesRes.h"
#include "math.h"




static gui_dialer_pad_context_struct g_dialer_pad_cntx;



/*****************************************************************************
************************  Image Order  *******************************************
                                        IMG_ID_DIALER_PAD_0,
                                        IMG_ID_DIALER_PAD_1,
                                        IMG_ID_DIALER_PAD_2,
                                        IMG_ID_DIALER_PAD_3,
                                        IMG_ID_DIALER_PAD_4,
                                        IMG_ID_DIALER_PAD_5,
                                        IMG_ID_DIALER_PAD_6,
                                        IMG_ID_DIALER_PAD_7,
                                        IMG_ID_DIALER_PAD_8,
                                        IMG_ID_DIALER_PAD_9,
                                        IMG_ID_DIALER_PAD_STAR,
                                        IMG_ID_DIALER_PAD_HASH,
                                        IMG_ID_DIALER_PAD_PLUS,
                                        IMG_ID_DIALER_PAD_P,
                                        IMG_ID_DIALER_PAD_W
*******************************************************************************
*********   Matrix   **************************************************************
*           {1, '1'}        {2, '2'}        {3, '3'}
*           {4, '4'}        {5, '5'}        {6, '6'}
*           {7, '7'}        {8, '8'}        {9, '9'}
*           {10, '*'}      {0, '0'}        {11, '#'}
*           {12, '+'}     {13, 'P'}       {14, 'W'}
*
 *****************************************************************************/
static gui_dialer_pad_matrix_struct gui_dialer_pad_matrix[GUI_DIALER_PAD_MATRIX_MAX_NUM] = 
{
 {1, '1', KEY_1},        {2, '2', KEY_2},         {3, '3', KEY_3},
 {4, '4', KEY_4},        {5, '5', KEY_5},         {6, '6', KEY_6},
 {7, '7', KEY_7},        {8, '8', KEY_8},         {9, '9', KEY_9},
 {10, '*', KEY_STAR},    {0, '0', KEY_0},         {11, '#', KEY_POUND},
 {12, '+', KEY_INVALID}, {13, 'P', KEY_INVALID},  {14, 'W', KEY_INVALID}
};


#ifdef GUI_DIALER_PAD_MATRIX_DIALER
static void gui_dialer_pad_matrix_image_init(void);
#endif

#ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
static S16 gui_dialer_pad_horizontal_check_highlight_for_longtap(void);
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_down_common_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_insert_character(U8 matrix_index, U8 key_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(matrix_index >= GUI_DIALER_PAD_MATRIX_MAX_NUM)return;
    //MMI_ASSERT(matrix_index < GUI_DIALER_PAD_MATRIX_MAX_NUM);
    
    if (matrix_index > 11
        #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
        || (matrix_index == 9 && g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK)  //VK style dialer will not treat star as multitap
        #endif  //GUI_DIALER_PAD_HORIZONTAL_DIALER
        )
    {
        if (key_type == KEY_EVENT_UP)
        {
            UI_character_type   char_code;
            char_code = (UI_character_type)(gui_dialer_pad_matrix[matrix_index].ch);
            mmi_imc_key_send_message( MMI_IMC_MESSAGE_INSERT_CHAR, char_code, 0 );
        }
    }
    else
    {
        mmi_frm_send_key_event(gui_dialer_pad_matrix[matrix_index].key_code, key_type);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_set_effective_bound
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_id
 * RETURNS
 *  S16
 *****************************************************************************/
static void gui_dialer_pad_set_effective_bound(gui_bound bound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bound.x  >= 0 && bound.x <= UI_device_width && bound.y >= 0 && bound.y <= UI_device_height && 
        bound.width > 0 && bound.width <= UI_device_width && bound.height > 0 && bound.height <= UI_device_height);
    memcpy((void*)&g_dialer_pad_cntx.effective_bound, (void*)&bound, sizeof(gui_bound));
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_get_dialer_matrix_index_by_image_id
 * DESCRIPTION
 *  
 * PARAMETERS
 *  image_id
 * RETURNS
 *  S16
 *****************************************************************************/
static S16 gui_dialer_pad_get_dialer_matrix_index_by_image_id(U8 image_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < GUI_DIALER_PAD_MATRIX_MAX_NUM; i++)
    {
        if (gui_dialer_pad_matrix[i].image_index == image_id)
            return i;
    }

    return GUI_DIALER_PAD_INVALID_INDEX;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_switch_dialer
 * DESCRIPTION
 *  Switch dialer
 * PARAMETERS
 *  switch_type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_switch_dialer(gui_dialer_pad_switch_type switch_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (switch_type == GUI_DIALER_PAD_SWITCH_TYPE_LEFT || switch_type == GUI_DIALER_PAD_SWITCH_TYPE_UP)
    {
        MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.goto_previous != NULL);
        g_dialer_pad_cntx.dialer_hdlr.goto_previous();
    }
    else
    {
        MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.goto_next != NULL);
        g_dialer_pad_cntx.dialer_hdlr.goto_next();
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_switch_to_prev
 * DESCRIPTION
 *  Switch number to previous
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_switch_to_prev(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_pad_switch_dialer(GUI_DIALER_PAD_SWITCH_TYPE_LEFT);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_switch_to_next
 * DESCRIPTION
 *  Switch number to next
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_switch_to_next(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_dialer_pad_switch_dialer(GUI_DIALER_PAD_SWITCH_TYPE_RIGHT);
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_down_delay_timer_callback
 * DESCRIPTION
 *  To avoid character input while there is pen move
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_down_delay_timer_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
    {
        gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_DOWN);
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_down_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 ticks;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_time(&ticks);
    g_dialer_pad_cntx.pen_down_time = kal_ticks_to_milli_secs(ticks);
    g_dialer_pad_cntx.last_pen_move_pos.x = g_dialer_pad_cntx.pen_down_pos.x = pos.x;
    g_dialer_pad_cntx.last_pen_move_pos.y = g_dialer_pad_cntx.pen_down_pos.y = pos.y;
    
    if (pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
        g_dialer_pad_cntx.pen_status = GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE;
        
        MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr != NULL);
        g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr(pos);

    #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
        //vk style will send key down in key up
        if (g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK)
        {
            g_dialer_pad_cntx.matrix_index = GUI_DIALER_PAD_INVALID_INDEX;
            return;
        }
    #endif  //GUI_DIALER_PAD_HORIZONTAL_DIALER

        MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index != NULL);
        g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index();
        if (g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        {
            //delay pen down for pen move
            gui_start_timer(GUI_DIALER_PAD_PEN_DOWN_DELAY, gui_dialer_pad_pen_down_delay_timer_callback);
        }
    }

    wgui_general_pen_down_hdlr(pos);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_move_hdlr
 * DESCRIPTION
 *  Pen move handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 x_diff = pos.x - g_dialer_pad_cntx.pen_down_pos.x, y_diff = pos.y - g_dialer_pad_cntx.pen_down_pos.y;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
        MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr != NULL);
        g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr(pos);        
    }
    
    if (g_dialer_pad_cntx.style != GUI_DIALER_PAD_STYLE_VK && g_dialer_pad_cntx.pen_status == GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE &&
        (GUI_ABS(x_diff) > GUI_DIALER_PAD_PEN_MOVE_SWITCH_THRESHOLD || GUI_ABS(y_diff) > GUI_DIALER_PAD_PEN_MOVE_SWITCH_THRESHOLD))
    {
        g_dialer_pad_cntx.pen_status = GUI_DIALER_PAD_PEN_STATUS_NONE;            

        if (g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        {
            U32 ticks, current_time;
            
            gui_cancel_timer(gui_dialer_pad_pen_down_delay_timer_callback);

            kal_get_time(&ticks);
            current_time = kal_ticks_to_milli_secs(ticks);
            if (current_time - g_dialer_pad_cntx.pen_down_time > GUI_DIALER_PAD_PEN_DOWN_DELAY)
            {
                gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_UP);
            }
        }
    }
    g_dialer_pad_cntx.last_pen_move_pos.x = pos.x;
    g_dialer_pad_cntx.last_pen_move_pos.y = pos.y;

    wgui_general_pen_move_hdlr(pos);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_repeat_hdlr
 * DESCRIPTION
 *  Pen repeat handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
        #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
        if (g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK)
        {
            MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.pen_repeat_hdlr != NULL);
            g_dialer_pad_cntx.dialer_hdlr.pen_repeat_hdlr(pos);
            return;
        }
        #endif  //GUI_DIALER_PAD_HORIZONTAL_DIALER

        if (g_dialer_pad_cntx.pen_status == GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE && g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        {
            gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_REPEAT);
        }
    }
    
    wgui_general_pen_repeat_hdlr(pos);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_long_tap_hdlr
 * DESCRIPTION
 *  Pen long tap handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dialer_pad_cntx.pen_status == GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE &&
        pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
        #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
    	if(g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK)
		{
        	g_dialer_pad_cntx.matrix_index = gui_dialer_pad_horizontal_check_highlight_for_longtap();
			if((gui_dialer_pad_matrix[g_dialer_pad_cntx.matrix_index].key_code == KEY_POUND)
				&&(wgui_inputs_ml_is_empty()))
			{
 				 gdi_layer_lock_frame_buffer();  
				 gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_DOWN);
				 g_dialer_pad_cntx.dialer_hdlr.show_func();
				 gdi_layer_unlock_frame_buffer();
			} 
			else
			{
				g_dialer_pad_cntx.matrix_index = GUI_DIALER_PAD_INVALID_INDEX;
			}
    	}
		#endif
        if (g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        {
            gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_LONG_PRESS);
        }
    }

    wgui_general_pen_long_tap_hdlr(pos);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_pen_up_hdlr
 * DESCRIPTION
 *  Pen down handler
 * PARAMETERS
 *  pos
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr != NULL);
    g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr(pos);

    if (pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
        #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
        //vk style will send key down in key up
        if (g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK)
        {
            g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index();
            gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_DOWN);
            gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_UP); 
            return;
        }
        #endif  //GUI_DIALER_PAD_HORIZONTAL_DIALER
        
        if (g_dialer_pad_cntx.pen_status == GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE && g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        {
            U32 ticks, current_time;
            kal_get_time(&ticks);
        	
            current_time = kal_ticks_to_milli_secs(ticks);
            if (current_time - g_dialer_pad_cntx.pen_down_time < GUI_DIALER_PAD_PEN_DOWN_DELAY)
            {//add pen down
                gui_cancel_timer(gui_dialer_pad_pen_down_delay_timer_callback);
                gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_DOWN);
            }
            gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_UP);
            g_dialer_pad_cntx.pen_status = GUI_DIALER_PAD_PEN_STATUS_NONE;
        }
    }

    wgui_general_pen_up_hdlr(pos);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_register_pen_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_register_pen_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_register_pen_down_handler(gui_dialer_pad_pen_down_hdlr);
    wgui_register_pen_move_handler(gui_dialer_pad_pen_move_hdlr);
    wgui_register_pen_repeat_handler(gui_dialer_pad_pen_repeat_hdlr);
    wgui_register_pen_long_tap_handler(gui_dialer_pad_pen_long_tap_hdlr);
    wgui_register_pen_up_handler(gui_dialer_pad_pen_up_hdlr);
}

#endif  //__MMI_TOUCH_SCREEN__


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_get_highlight
 * DESCRIPTION
 *  Get current higlight key code of dialer pad
 * PARAMETERS
 *  void
 * RETURNS
 *  U16
 *****************************************************************************/
U16 gui_dialer_pad_get_highlight(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index != NULL);
    g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index();
    if (g_dialer_pad_cntx.matrix_index != GUI_DIALER_PAD_INVALID_INDEX)
        return gui_dialer_pad_matrix[g_dialer_pad_cntx.matrix_index].key_code;

    return KEY_INVALID;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_create
 * DESCRIPTION
 *  Create Picker
 * PARAMETERS
 *  style [IN] the dialer pad style
 *  bound [IN] the whole area picker in
 * RETURNS
 *  U8  -- if error, will return error code
 *****************************************************************************/
U8 gui_dialer_pad_create(gui_dialer_pad_style style, gui_bound bound)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(bound.x >= 0 && bound.x <= UI_device_width && bound.y >= 0 && bound.y <= UI_device_height &&
        bound.width >= 1 && bound.width <= UI_device_width && bound.height >= 1 && bound.height <= UI_device_height);
    
    if (!((U8)style >= (U8)GUI_DIALER_PAD_STYLE_START && (U8)style <= (U8)GUI_DIALER_PAD_STYLE_END))
        return (U8)GUI_DIALER_PAD_ERROR_WRONG_STYLE;
    memset(&g_dialer_pad_cntx,0,sizeof(g_dialer_pad_cntx));
    g_dialer_pad_cntx.style = style;
    memcpy((void*)&g_dialer_pad_cntx.original_bound, (void*)&bound, sizeof(gui_bound));

    //dialer init
    #ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
    if (g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL ||
        g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK ||
        g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_MAP ||
        g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_VK_KEY)
    {
	    gui_dialer_pad_horizontal_init(g_dialer_pad_cntx.style);
    }
	#endif /*GUI_DIALER_PAD_HORIZONTAL_DIALER*/
    #ifdef GUI_DIALER_PAD_MATRIX_DIALER
    if (g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_MATRIX)
    {
        gui_dialer_pad_matrix_image_init();
    }
    #endif  //GUI_DIALER_PAD_MATRIX_DIALER
    #ifdef GUI_PICKER_CIRCUAL_ROLL_DIALER
	if(g_dialer_pad_cntx.style == GUI_DIALER_PAD_STYLE_DIALER_CICUAL_ROLL)
	{
		gui_circual_roll_picker_init();
	}
	#endif

    return (U8)GUI_DIALER_PAD_NO_ERROR;
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_show
 * DESCRIPTION
 *  Show Dialer Pad
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle base_layer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_get_base_handle(&base_layer);
    gdi_layer_push_and_set_active(base_layer);
    gdi_layer_push_and_set_clip(g_dialer_pad_cntx.original_bound.x, g_dialer_pad_cntx.original_bound.y, g_dialer_pad_cntx.original_bound.x + g_dialer_pad_cntx.original_bound.width, 
        g_dialer_pad_cntx.original_bound.y + g_dialer_pad_cntx.original_bound.height);
    gdi_draw_solid_rect(g_dialer_pad_cntx.original_bound.x, g_dialer_pad_cntx.original_bound.y, g_dialer_pad_cntx.original_bound.x + g_dialer_pad_cntx.original_bound.width, 
        g_dialer_pad_cntx.original_bound.y + g_dialer_pad_cntx.original_bound.height, GDI_COLOR_TRANSPARENT);

    MMI_ASSERT(g_dialer_pad_cntx.dialer_hdlr.show_func != NULL);
    g_dialer_pad_cntx.dialer_hdlr.show_func();
    
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(g_dialer_pad_cntx.original_bound.x, g_dialer_pad_cntx.original_bound.y, g_dialer_pad_cntx.original_bound.x+g_dialer_pad_cntx.original_bound.width, g_dialer_pad_cntx.original_bound.y+g_dialer_pad_cntx.original_bound.height);
    
    gui_dialer_pad_register_key_hdlr();

    #ifdef __MMI_TOUCH_SCREEN__
    gui_dialer_pad_register_pen_hdlr();
    #endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_register_key_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_register_key_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetKeyHandler(gui_dialer_pad_switch_to_prev, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_dialer_pad_switch_to_next, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(gui_dialer_pad_switch_to_prev, KEY_UP_ARROW, KEY_EVENT_REPEAT);
    SetKeyHandler(gui_dialer_pad_switch_to_next, KEY_DOWN_ARROW, KEY_EVENT_REPEAT);
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_inject_string
 * DESCRIPTION
 *  This function handle inject string. only available when __RANFOW_TUNING__ is defined
 * PARAMETERS
 *  index
 * RETURNS
 *  U8
 *****************************************************************************/
U8 gui_dialer_pad_inject_string(U8 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __RANFOW_TUNING__
    //MMI_TRACE(MMI_FW_TRC_G2_GUI, TRC_GUI_DIALER_PAD_INJECT_STRING, g_dialer_pad_cntx.inject_index, index);
    g_dialer_pad_cntx.inject_index = index;
#endif  //__RANFOW_TUNING__
    return 0;
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_get_style
 * DESCRIPTION
 *  Get current UI style
 * PARAMETERS
 *  void
 * RETURNS
 *  U8
 *****************************************************************************/
gui_dialer_pad_style gui_dialer_pad_get_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_dialer_pad_cntx.style;
}


#ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER

gui_dialer_pad_horizontal_struct  gui_dialer_pad_horizontal;

U8 width_s[3]= {GUI_DIALER_PAD_HORIZONTAL_WIDTH_1,GUI_DIALER_PAD_HORIZONTAL_WIDTH_2,GUI_DIALER_PAD_HORIZONTAL_WIDTH_3};

gui_dialer_pad_horizontal_show_image_struct  show_image_struct[GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT];

gui_dialer_pad_horizontal_show_image_default_setting_struct show_image_default_size[GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES]={
    {GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_W,GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_H,125},
    {30,20,125},
    {35,20,125},
    {40,25,125},
    {45,30,125},
    {50,35,125},
    {GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_W,GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_H,125},    

};

MMI_ID_TYPE dialing_ssp_key_image[]=
{
    IMG_ID_DIALER_PAD_0,
    IMG_ID_DIALER_PAD_0+1,
    IMG_ID_DIALER_PAD_0+2,
    IMG_ID_DIALER_PAD_0+3,
    IMG_ID_DIALER_PAD_0+4,
    IMG_ID_DIALER_PAD_0+5,
    IMG_ID_DIALER_PAD_0+6,
    IMG_ID_DIALER_PAD_0+7,
    IMG_ID_DIALER_PAD_0+8,
    IMG_ID_DIALER_PAD_0+9,
    IMG_ID_DIALER_PAD_0+10,
    IMG_ID_DIALER_PAD_0+11,
    IMG_ID_DIALER_PAD_0+12,
    IMG_ID_DIALER_PAD_0+13,
    IMG_ID_DIALER_PAD_0+14
};
MMI_ID_TYPE dialing_vk_pop_key_image[]=
{
    IMG_ID_DIALER_PAD_POP_NUMBER_1,
    IMG_ID_DIALER_PAD_POP_NUMBER_4,
    IMG_ID_DIALER_PAD_POP_NUMBER_7,
    IMG_ID_DIALER_PAD_POP_NUMBER_0,
    IMG_ID_DIALER_PAD_POP_NUMBER_2,
    IMG_ID_DIALER_PAD_POP_NUMBER_5,
    IMG_ID_DIALER_PAD_POP_NUMBER_8,
    IMG_ID_DIALER_PAD_POP_NUMBER_H,    
    IMG_ID_DIALER_PAD_POP_NUMBER_3,
    IMG_ID_DIALER_PAD_POP_NUMBER_6,
    IMG_ID_DIALER_PAD_POP_NUMBER_9,
    IMG_ID_DIALER_PAD_POP_NUMBER_C
};
U8 dialing_vk_pop_key_index[]=
{
    1,//IMG_ID_DIALER_PAD_POP_NUMBER_1,
    4,//IMG_ID_DIALER_PAD_POP_NUMBER_4,
    7,//IMG_ID_DIALER_PAD_POP_NUMBER_7,
    0,//IMG_ID_DIALER_PAD_POP_NUMBER_0,
    2,//IMG_ID_DIALER_PAD_POP_NUMBER_2,
    5,//IMG_ID_DIALER_PAD_POP_NUMBER_5,
    8,//IMG_ID_DIALER_PAD_POP_NUMBER_8,
    11,//IMG_ID_DIALER_PAD_POP_NUMBER_H,    
    3,//IMG_ID_DIALER_PAD_POP_NUMBER_3,
    6,//IMG_ID_DIALER_PAD_POP_NUMBER_6,
    9,//IMG_ID_DIALER_PAD_POP_NUMBER_9,
    10,//IMG_ID_DIALER_PAD_POP_NUMBER_C ,pop use IMG_ID_DIALER_PAD_POP_NUMBEM
};


MMI_ID_TYPE dialing_vk_pop_image[]=
{
    IMG_ID_DIALER_PAD_POP_NUMBER_1,
    IMG_ID_DIALER_PAD_POP_NUMBER_4,
    IMG_ID_DIALER_PAD_POP_NUMBER_7,
    IMG_ID_DIALER_PAD_POP_NUMBER_0,
    IMG_ID_DIALER_PAD_POP_NUMBER_2,
    IMG_ID_DIALER_PAD_POP_NUMBER_5,
    IMG_ID_DIALER_PAD_POP_NUMBER_8,
    IMG_ID_DIALER_PAD_POP_NUMBER_H,    
    IMG_ID_DIALER_PAD_POP_NUMBER_3,
    IMG_ID_DIALER_PAD_POP_NUMBER_6,
    IMG_ID_DIALER_PAD_POP_NUMBER_9,
    IMG_ID_DIALER_PAD_POP_NUMBER_C,   //IMG_ID_DIALER_PAD_POP_NUMBEM
    IMG_ID_DIALER_PAD_POP_NUMBER_PLUS,
    IMG_ID_DIALER_PAD_POP_NUMBER_P,
    IMG_ID_DIALER_PAD_POP_NUMBER_W
};
MMI_ID_TYPE dialing_vk_pop_h_image[]=
{
    IMG_ID_DIALER_PAD_POP_H_NUMBER_1,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_4,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_7,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_0,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_2,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_5,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_8,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_H,    
    IMG_ID_DIALER_PAD_POP_H_NUMBER_3,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_6,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_9,
    IMG_ID_DIALER_PAD_POP_NUMBER_C,   //IMG_ID_DIALER_PAD_POP_NUMBEM
    IMG_ID_DIALER_PAD_POP_H_NUMBER_PLUS,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_P,
    IMG_ID_DIALER_PAD_POP_H_NUMBER_W
};
U8 dialing_vk_pop_index[]=
{
    1,//IMG_ID_DIALER_PAD_POP_NUMBER_1,
    4,//IMG_ID_DIALER_PAD_POP_NUMBER_4,
    7,//IMG_ID_DIALER_PAD_POP_NUMBER_7,
    0,//IMG_ID_DIALER_PAD_POP_NUMBER_0,
    2,//IMG_ID_DIALER_PAD_POP_NUMBER_2,
    5,//IMG_ID_DIALER_PAD_POP_NUMBER_5,
    8,//IMG_ID_DIALER_PAD_POP_NUMBER_8,
    11,//IMG_ID_DIALER_PAD_POP_NUMBER_H,    
    3,//IMG_ID_DIALER_PAD_POP_NUMBER_3,
    6,//IMG_ID_DIALER_PAD_POP_NUMBER_6,
    9,//IMG_ID_DIALER_PAD_POP_NUMBER_9,
    10,//IMG_ID_DIALER_PAD_POP_NUMBER_C ,pop use IMG_ID_DIALER_PAD_POP_NUMBEM
    12, //"+" IMG_ID_DIALER_PAD_POP_NUMBER_PLUS
    13, // "P" IMG_ID_DIALER_PAD_POP_NUMBER_P
    14, //"W" IMG_ID_DIALER_PAD_POP_NUMBER_W
};


static S16 gui_dialer_pad_horizontal_get_highlight(void)
{
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START)
		{	
		    if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_TIME_OUT)
		    {
				return GUI_DIALER_PAD_INVALID_INDEX ;
		    }	
		}			

	    if(gui_dialer_pad_horizontal.vk_highlight_invalid)
	    {
			return GUI_DIALER_PAD_INVALID_INDEX ;
		}
	}

 	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
    {
        return gui_dialer_pad_get_dialer_matrix_index_by_image_id(gui_dialer_pad_horizontal.highlight_item);
	}
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_MAP)
    {		
		 return gui_dialer_pad_get_dialer_matrix_index_by_image_id(gui_dialer_pad_horizontal.highlight_index);		
    }
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
	{
	    wgui_inputs_ml_enable();
		return gui_dialer_pad_get_dialer_matrix_index_by_image_id(dialing_vk_pop_key_index[gui_dialer_pad_horizontal.highlight_index]);
	}
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		return gui_dialer_pad_get_dialer_matrix_index_by_image_id(dialing_vk_pop_index[gui_dialer_pad_horizontal.highlight_index]);
	}
   
}
static S16 gui_dialer_pad_horizontal_check_highlight_for_longtap(void)
{
	if(gui_dialer_pad_horizontal.vk_highlight_invalid)
	{
		return GUI_DIALER_PAD_INVALID_INDEX ;
	}

    if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		return gui_dialer_pad_get_dialer_matrix_index_by_image_id(dialing_vk_pop_index[gui_dialer_pad_horizontal.highlight_index]);
	}
	return GUI_DIALER_PAD_INVALID_INDEX ;
   
}

void gui_dialer_pad_horizontal_pop_up_timer_out()
{
    if(gui_dialer_pad_horizontal.up_time_out_flag == GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_DELAY)
    {
		gui_dialer_pad_horizontal.up_time_out_flag = GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_TIME_OUT;
		gui_dialer_pad_horizontal.show_frame();
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index();
		gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_DOWN);
		gui_dialer_pad_insert_character(g_dialer_pad_cntx.matrix_index, KEY_EVENT_UP); 
		if(KEY_STAR == gui_dialer_pad_matrix[g_dialer_pad_cntx.matrix_index].key_code)
		{
			mmi_frm_send_key_event(KEY_STAR, KEY_EVENT_DOWN);
			mmi_frm_send_key_event(KEY_STAR, KEY_EVENT_UP);
		}
		gui_dialer_pad_horizontal.up_time_out_flag = GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_GET_INDEX;
		
		gui_cancel_timer(gui_dialer_pad_horizontal_pop_up_timer_out);
		gui_start_timer(GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT2, gui_dialer_pad_horizontal_pop_up_timer_out);	
    }
	else if(gui_dialer_pad_horizontal.up_time_out_flag == GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_GET_INDEX)
	{
		gui_dialer_pad_horizontal.up_time_out_flag = GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_INSERT_CHAR;

	}
}

void gui_dialer_pad_horizontal_cancel_pop_up_timer(void)
{
	gui_cancel_timer(gui_dialer_pad_horizontal_pop_up_timer_out);
}



/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_init
 * DESCRIPTION
 *  initialze gui_dialer_pad_horizontal struct 
 * PARAMETERS
 *  void
 *  
 *  
 * RETURNS 
 * void
 *****************************************************************************/
void gui_dialer_pad_horizontal_init(U8 ui_type)
{
    gui_bound bound;
    U16 image_w = show_image_default_size[GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES -1].w;
	U16 image_h = show_image_default_size[GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES -1].h;

    memset(&gui_dialer_pad_horizontal,0,sizeof(gui_dialer_pad_horizontal));

	gui_dialer_pad_horizontal.x1 = GUI_DIALER_PAD_HORIZONTAL_X1;
	gui_dialer_pad_horizontal.y1 = GUI_DIALER_PAD_HORIZONTAL_Y1;
	gui_dialer_pad_horizontal.x2 = GUI_DIALER_PAD_HORIZONTAL_X2;
	gui_dialer_pad_horizontal.y2 = GUI_DIALER_PAD_HORIZONTAL_Y2;

	gui_dialer_pad_horizontal.highlight_item = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_HIGHLIGHT_ITEM;
	
	gui_dialer_pad_horizontal.old_highlight_item = gui_dialer_pad_horizontal.highlight_change;

	gui_dialer_pad_horizontal.other_ui_flag = ui_type; // 1 :enable larger map UI

	g_dialer_pad_cntx.dialer_hdlr.goto_previous = UI_dummy_function; //for avoid assert
	g_dialer_pad_cntx.dialer_hdlr.goto_next = UI_dummy_function;     //for avoid assert
	
    if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
    {
        gui_dialer_pad_horizontal_move_reset_item_with_highlight();
		gui_dialer_pad_horizontal.show_frame = gui_dialer_pad_horizontal_show_frame;
        g_dialer_pad_cntx.dialer_hdlr.show_func = gui_dialer_pad_horizontal_show_frame;
        g_dialer_pad_cntx.dialer_hdlr.goto_previous = gui_dialer_pad_horizontal_prev_item;
        g_dialer_pad_cntx.dialer_hdlr.goto_next = gui_dialer_pad_horizontal_next_item;
        
        //set bound
    	bound.x = gui_dialer_pad_horizontal.x1 + ((gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2 - image_w/2);
        bound.y = gui_dialer_pad_horizontal.y1 + ((gui_dialer_pad_horizontal.y2 - gui_dialer_pad_horizontal.y1 - image_h)/2);
        bound.width = image_w;
        bound.height = image_h;    
        gui_dialer_pad_set_effective_bound(bound);
	}
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
    {		
		gui_dialer_pad_horizontal.x1 = GUI_DIALER_PAD_HORIZONTAL_VK_X1;
		gui_dialer_pad_horizontal.y1 = GUI_DIALER_PAD_HORIZONTAL_VK_Y1;
		gui_dialer_pad_horizontal.x2 = GUI_DIALER_PAD_HORIZONTAL_VK_X2;
		gui_dialer_pad_horizontal.y2 = GUI_DIALER_PAD_HORIZONTAL_VK_Y2;	
		gui_dialer_pad_horizontal.pen_state =  MMI_STROKE_TYPE_MAX;

        gui_dialer_pad_horizontal.show_frame = gui_dialer_pad_vk_pop_show_frame;
        g_dialer_pad_cntx.dialer_hdlr.show_func = gui_dialer_pad_vk_pop_show_frame;
        #ifdef __MMI_TOUCH_SCREEN__
        g_dialer_pad_cntx.dialer_hdlr.pen_repeat_hdlr = gui_dialer_pad_horizontal_pen_repeat;
        #endif
        
        //set bound    
    	bound.x = gui_dialer_pad_horizontal.x1 ;
        bound.y = GUI_DIALER_PAD_HORIZONTAL_START_Y;
        bound.width = gui_dialer_pad_horizontal.x2- gui_dialer_pad_horizontal.x1;
        bound.height = gui_dialer_pad_horizontal.y2 - GUI_DIALER_PAD_HORIZONTAL_START_Y;         
        gui_dialer_pad_set_effective_bound(bound);
		
    }		
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_MAP)
	{        
		gui_dialer_pad_horizontal.x1 = GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X1;
		gui_dialer_pad_horizontal.y1 = GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y1;
		gui_dialer_pad_horizontal.x2 = GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X2;
		gui_dialer_pad_horizontal.y2 = GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y2;	
		gui_dialer_pad_horizontal.show_frame = gui_dialer_pad_small_map_large_button_show_frame;		
        g_dialer_pad_cntx.dialer_hdlr.show_func = gui_dialer_pad_small_map_large_button_show_frame;
        
        //set bound    
        gui_dialer_pad_set_effective_bound(g_dialer_pad_cntx.original_bound);
	}
    else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
    {
		gui_dialer_pad_horizontal.x1 = GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X1;
		gui_dialer_pad_horizontal.y1 = GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y1;
		gui_dialer_pad_horizontal.x2 = GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X2;
		gui_dialer_pad_horizontal.y2 = GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y2;	
		gui_dialer_pad_horizontal.pen_state =  MMI_STROKE_TYPE_MAX;

        gui_dialer_pad_horizontal.show_frame = gui_dialer_pad_vk_pop_key_show_frame;
        g_dialer_pad_cntx.dialer_hdlr.show_func = gui_dialer_pad_vk_pop_key_show_frame;

		gui_dialer_pad_horizontal.move_key_redraw_frame = 1;
#ifdef __MMI_TOUCH_SCREEN__  
        // just for avoid assert 
        g_dialer_pad_cntx.dialer_hdlr.pen_repeat_hdlr = gui_dialer_pad_horizontal_pen_repeat;
#endif
        //set bound    
        bound.x = 0;
        bound.y = 0;
        bound.width = 1;
        bound.height = 1; 
        gui_dialer_pad_set_effective_bound(bound);
		g_dialer_pad_cntx.dialer_hdlr.goto_previous = gui_dialer_pad_horizontal_prev_item;
		g_dialer_pad_cntx.dialer_hdlr.goto_next = gui_dialer_pad_horizontal_next_item;



	}
    //register hdlr
#ifdef __MMI_TOUCH_SCREEN__
    g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr = gui_dialer_pad_horizontal_pen_down;
    g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr = gui_dialer_pad_horizontal_pen_move;
    g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr = gui_dialer_pad_horizontal_pen_up;
    if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
    {
		g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr = UI_dummy_function;
		g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr = UI_dummy_function;
		g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr = UI_dummy_function;
	}
#endif
    g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index = gui_dialer_pad_horizontal_get_highlight;
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_check_highlight_item_range
 * DESCRIPTION
 *  check pen event point in highlight item 
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen event point
 *  
 *  
 * RETURNS 
 * pen event point in highlight item or not
 *****************************************************************************/
MMI_BOOL gui_dialer_pad_horizontal_check_highlight_item_range(mmi_pen_point_struct point)
{
    U16 image_w = show_image_default_size[GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES -1].w;
	U16 image_h = show_image_default_size[GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES -1].h;
    S16 x1,x2,y1,y2;

	x1 = gui_dialer_pad_horizontal.x1 + ((gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2 - image_w/2);
    y1 = gui_dialer_pad_horizontal.y1 + ((gui_dialer_pad_horizontal.y2 - gui_dialer_pad_horizontal.y1 - image_h)/2);
	x2 = x1 + image_w;
	y2 = y1 + image_h;
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
	{
	    if((point.x > x1)&&(point.x < x2)
	         &&(point.y > y1)&&(point.y < y2))
	    {
	        return KAL_TRUE;
	    }
	    else
	    {
	        return KAL_FALSE;
	    }
	}
    else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_MAP)
    {
		x1 = GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_X - image_w/2;
		y1 = GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_y - image_h/2;
		x2 = x1 + image_w;
		y2 = y1 + image_h;
	    if((point.x > x1)&&(point.x < x2)
	         &&(point.y > y1)&&(point.y < y2))
	    {
	        return KAL_TRUE;
	    }
	    else
	    {
	        return KAL_FALSE;
	    }
	}


}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_show_frame
 * DESCRIPTION
 *  show dialer horizontal frame 
 * PARAMETERS
 *  void
 *  
 *  
 * RETURNS
 * void
 *****************************************************************************/
void gui_dialer_pad_horizontal_show_frame()
{   U8 half_show_count = (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2;
    U8 item_index = 0;

    U8 default_show_state = 0;
    U8 show_state = 0;
    U8 *image_p =NULL;
    U8 index = 0,j = 0,i = 0;
    S16 change_w = 0;
	S16 change_h = 0;
    U16 show_w = 0;
    U16 show_h = 0;  
	U16 state_one_change_x_temp = 0;
	U16 state_one_change_y_temp = 0;	
	U8 max_state = 0 ;
	U8 min_state = 0 ;
    MMI_ID_TYPE btn_img_id = IMG_ID_DIALER_PAD_BTN;
	MMI_ID_TYPE highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN;
	 
    gui_dialer_pad_horizontal_show_image_temp_struct show_temp_info[GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT];    
    //color c;

    #ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
    U8 debug_i = 0;
	#endif

	
    //c.r = 0xff;
    //c.g = 0xff;
    //c.b = 0xff;
    //c.alpha = 100;

	if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT)
	{
		highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN_DOWN;
	}
	
    
          
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
    kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_show_frame stsart \n");
	for(debug_i = 0;debug_i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT; debug_i++ )
	{

		kal_prompt_trace(MOD_MMI_COMMON_APP,"S show_image_struct[%d].default:%d  max: %d min: %d show_state:%d change_flag: %d index: %d show_flag: %d", 
			      debug_i,
			      show_image_struct[debug_i].default_show_state,
			      show_image_struct[debug_i].default_max_show_state,
			      show_image_struct[debug_i].default_min_show_state,
			      show_image_struct[debug_i].show_state,
			      show_image_struct[debug_i].change_flag,
			      show_image_struct[debug_i].index,
			      show_image_struct[debug_i].show_flag);
			      
	}

#endif
 
	gdi_layer_push_and_set_clip(gui_dialer_pad_horizontal.x1 , gui_dialer_pad_horizontal.y1, 
	                            gui_dialer_pad_horizontal.x2 , gui_dialer_pad_horizontal.y2);
	//gui_fill_rectangle(GUI_DIALER_PAD_HORIZONTAL_X1, GUI_DIALER_PAD_HORIZONTAL_Y1, GUI_DIALER_PAD_HORIZONTAL_X2, GUI_DIALER_PAD_HORIZONTAL_Y2, c);
	gdi_draw_solid_rect(
						gui_dialer_pad_horizontal.x1,
						gui_dialer_pad_horizontal.y1,
						gui_dialer_pad_horizontal.x2,
						gui_dialer_pad_horizontal.y2,
						GDI_COLOR_TRANSPARENT); 
	
    memset(show_temp_info,0,sizeof(show_temp_info));
    // get w/h/y  
    for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT;j++ ) 
    {
        if(show_image_struct[j].show_flag)//need be show
        { 	
            default_show_state = show_image_struct[j].default_show_state;
            show_state = show_image_struct[j].show_state;
			max_state  = show_image_struct[j].default_max_show_state;
			min_state  = show_image_struct[j].default_min_show_state;
			
            if(show_image_struct[j].change_flag == GUI_DIALER_PAD_HORIZONTAL_SMALL_TO_LARGE)
            {
				state_one_change_x_temp = (show_image_default_size[max_state].w - show_image_default_size[default_show_state].w);
				state_one_change_y_temp = (show_image_default_size[max_state].h - show_image_default_size[default_show_state].h);

				change_w = (show_state * state_one_change_x_temp)/((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)); 
				change_h = (show_state * state_one_change_y_temp)/((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)); 
            }
            else if(show_image_struct[j].change_flag == GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL)
            {
				state_one_change_x_temp = (show_image_default_size[default_show_state].w - show_image_default_size[min_state].w);
				state_one_change_y_temp = (show_image_default_size[default_show_state].h - show_image_default_size[min_state].h);

               change_w = ((show_state * state_one_change_x_temp)/((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)))*(-1); 
			   change_h = ((show_state * state_one_change_y_temp)/((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)))*(-1); 

			   if(j == half_show_count)
               {
				  change_w = change_w - GUI_DIALER_PAD_HORIZONTAL_HIHGLIGHT_SMALL;
                  change_h = change_h - GUI_DIALER_PAD_HORIZONTAL_HIHGLIGHT_SMALL-1;
			   }
            }    
			 
            if(default_show_state < GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES)
            {                
               // if(show_key_point[j].x + move_x_offset >= 0)
                {
                    show_w = show_image_default_size[default_show_state].w + change_w;
                    show_h = show_image_default_size[default_show_state].h + change_h;
					
					if(show_image_struct[j].change_flag == GUI_DIALER_PAD_HORIZONTAL_SMALL_TO_LARGE)
					{
						if(show_w > show_image_default_size[max_state].w)
						{
							show_w = show_image_default_size[max_state].w;
						}
						if(show_h > show_image_default_size[max_state].h)
						{
							show_h = show_image_default_size[max_state].h;
						}						
					}
					else if(show_image_struct[j].change_flag == GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL)
					{
						if(show_w < show_image_default_size[min_state].w)
						{
							show_w = show_image_default_size[min_state].w;
						}
						if(show_h < show_image_default_size[min_state].h)
						{
							show_h = show_image_default_size[min_state].h;
						}

					} 

				
                    if(show_w > GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_W)
                    {
                        show_w = GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_W;
                    }
                    else if(show_w < GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_W)
                    {
                        show_w = GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_W;
                    }
                    
                    if(show_h > GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_H)
                    {
                        show_h = GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_H;
                    }
                    else if(show_h < GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_H)
                    {
                        show_h = GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_H;
                    }
                    show_temp_info[j].show_w = show_w;
                    show_temp_info[j].show_h = show_h;
                    show_temp_info[j].show_y = GUI_DIALER_PAD_HORIZONTAL_Y1 + ((GUI_DIALER_PAD_HORIZONTAL_Y2 - GUI_DIALER_PAD_HORIZONTAL_Y1 - show_h)/2);
                }    
            }   
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
			{
		
				kal_prompt_trace(MOD_MMI_COMMON_APP,"S W[%d].show_state: %d change_flag: %d x_temp: %d show_image_default_size[default_show_state].w: %d show_w %d\n ",
													 j,
													 show_image_struct[j].show_state,
													 show_image_struct[j].change_flag,
													 state_one_change_x_temp,
													 show_image_default_size[default_show_state].w,
													 show_w);
			}
						
#endif
			
        }
    }
    //get x
    item_index = half_show_count;

    show_temp_info[item_index].show_x = gui_dialer_pad_horizontal.x1 + ((gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2 - show_temp_info[item_index].show_w/2);
   
    for(i = 0;i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT;i++ )
    {   
        if(i == half_show_count)
        {
           item_index = half_show_count;
           continue;
        }             
        if(i < half_show_count)
        {   
            if(item_index)
            {
                item_index--;
            }
            show_temp_info[item_index].show_x = show_temp_info[item_index+1].show_x + (show_temp_info[item_index+1].show_w/2) 
                                                       - width_s[i] - (show_temp_info[item_index].show_w/2);

        }
        else 
        {
            if(item_index < (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1))
            {
                item_index++;
            }             
            show_temp_info[item_index].show_x = (show_temp_info[item_index-1].show_x + show_temp_info[item_index-1].show_w/2) 
                                                 + width_s[i - half_show_count - 1] - (show_temp_info[item_index].show_w/2);
        }
    }
    
    // start draw from left to right 
 
	{	
	    for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT;j++ ) 
	    {
	        index = show_image_struct[j].index;
	        if(show_image_struct[j].show_flag)//need be show
	        {
	            // show image
	            image_p = (U8*) GetImage(dialing_ssp_key_image[index]);
	            if(image_p)
	            {
	                default_show_state = show_image_struct[j].default_show_state;    

	                if(default_show_state < GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES)
	                {                    
	                    
	                    {
	                        #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
							#endif
							if(j == half_show_count)
							{
								btn_img_id = highlight_btn_img_id;
							}
							else
							{
								btn_img_id = IMG_ID_DIALER_PAD_BTN;
							}
	                        gui_draw_resized_image_with_alpha_transparent(
	                            (U8*) GetImage(btn_img_id),
	                            show_temp_info[j].show_x+ gui_dialer_pad_horizontal.move_x_offset,                            
	                            show_temp_info[j].show_y,
	                            show_temp_info[j].show_w,
	                            show_temp_info[j].show_h,
	                            show_image_default_size[default_show_state].alpha); 
							
	                        gui_draw_resized_image_with_alpha_transparent(
	                            image_p, 
	                            show_temp_info[j].show_x + gui_dialer_pad_horizontal.move_x_offset + (show_temp_info[j].show_w/4),
	                            show_temp_info[j].show_y + (show_temp_info[j].show_h/4),
	                            show_temp_info[j].show_w/2,
	                            show_temp_info[j].show_h/2,
	                            show_image_default_size[default_show_state].alpha); 
							//gdi_layer_pop_clip();
	                    }    
	                }                    
	            }              
	        }
	    }
    }  	
	
    gdi_layer_pop_clip();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
   
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
	{
	    S16 ssww = 0;
	    kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_show_frame end  move_x_offset: %d\n",gui_dialer_pad_horizontal.move_x_offset);
		
		for(debug_i = 0;debug_i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT; debug_i++ )
		{
            ssww =  show_temp_info[debug_i].show_x + gui_dialer_pad_horizontal.move_x_offset;
			kal_prompt_trace(MOD_MMI_COMMON_APP,"S show_temp_info[%d].show_x: %d show_y: %d show_w: %d show_h: %d index: %d [X: %d ]\n ",
				                                 debug_i,
				                                 show_temp_info[debug_i].show_x,
				                                 show_temp_info[debug_i].show_y,
				                                 show_temp_info[debug_i].show_w,
				                                 show_temp_info[debug_i].show_h,
				                                 show_image_struct[debug_i].index,
				                                 ssww);
		}
	}
#endif

	
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_vk_pop_key_show_frame
 * DESCRIPTION
 *  show dialer vk pop key frame 
 * PARAMETERS
 *  void
 *  
 *  
 * RETURNS
 * void
 *****************************************************************************/
void gui_dialer_pad_vk_pop_key_show_frame()
{  
    U8 default_show_state = 0;
    U8 *image_p =NULL;
    U8 j = 0;

    MMI_ID_TYPE btn_img_id = IMG_ID_DIALER_PAD_POP_BUTTON_NORMAL;
	MMI_ID_TYPE highlight_btn_img_id = IMG_ID_DIALER_PAD_POP_BUTTON_HIGH;
	MMI_ID_TYPE btn_high_bg_img_id =  IMG_ID_DIALER_PAD_POP_BG;


    // when pen move check if need redraw frame
    if(gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_MOVE)
	{	
		S16 x1,y1;
		S16 x_h,y_h;
		U8 old_highlight_index = gui_dialer_pad_horizontal.highlight_index;
		
		for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT;j++ ) 
		{
			default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
			image_p = (U8*) GetImage(dialing_vk_pop_key_image[j]);
			if(image_p)
			{
				x1 =  GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_X + (j%GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_W + GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W);
				y1 =  GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_Y + (j/GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_H + GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H);
				x_h = gui_dialer_pad_horizontal.move_point.x ;
				y_h = gui_dialer_pad_horizontal.move_point.y ;	
				if((((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))>=0)&&((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)))
					||(((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))< 0)&&(((x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2) - x_h )<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)))
					)
				{
				   if((((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))>=0)&&((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)))
					||(((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))< 0)&&(((y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2) - y_h )<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)))
					)
					{
						gui_dialer_pad_horizontal.highlight_index = j;
					}
				} 						 
			}

		}
		
		
		if((gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_MOVE)&&
			(old_highlight_index == gui_dialer_pad_horizontal.highlight_index))
		{
			return; // highlight index no change ,so return.
		}
	}
           
	gdi_layer_push_and_set_clip(gui_dialer_pad_horizontal.x1 , gui_dialer_pad_horizontal.y1, 
	                            gui_dialer_pad_horizontal.x2 , gui_dialer_pad_horizontal.y2);

	gdi_draw_solid_rect(
						gui_dialer_pad_horizontal.x1,
						gui_dialer_pad_horizontal.y1,
						gui_dialer_pad_horizontal.x2,
						gui_dialer_pad_horizontal.y2,
						GDI_COLOR_TRANSPARENT); 
	
 
    
    // start draw from left to right 
   	{   
	    S16 x1,y1;
		S16 x_h,y_h;
		S16 x_pop = 0, y_pop = 0;
		//gdi_handle handle_ptr = NULL;
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
        #endif
		
		for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT;j++ ) 
		{
            default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
            image_p = (U8*) GetImage(dialing_vk_pop_key_image[j]);
			if(image_p)
			{
				x1 =  GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_X + (j%GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_W + GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W);
				y1 =  GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_Y + (j/GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_H + GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H);
				x_h = gui_dialer_pad_horizontal.move_point.x ;
				y_h = gui_dialer_pad_horizontal.move_point.y ;	
				if(!gui_dialer_pad_horizontal.move_key_redraw_frame)
				{
					if((((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))>=0)&&((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)))
						||(((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2))< 0)&&(((x1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2) - x_h )<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)))
						)
					{
					   if((((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))>=0)&&((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)))
						||(((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2))< 0)&&(((y1+GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2) - y_h )<= (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)))
						)
						{
							gui_dialer_pad_horizontal.highlight_index = j;
							
							x_pop = x1;
							y_pop = y1;
							continue;  // no draw normal image when  pen down it
						}
					}	
				}
				else
				{
					if(gui_dialer_pad_horizontal.highlight_index == j)
					{
						gui_dialer_pad_horizontal.move_key_redraw_frame = 0; 
						x_pop = x1;
						y_pop = y1;
						continue;  // no draw normal image when  pen down it
					}
				}
 				gdi_image_draw_resized( x1,  y1,
										GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W,
										GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H,
					                	(U8*) GetImage(btn_img_id)); 
				#if	0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
		
				gui_draw_resized_image_with_alpha_transparent(
				                image_p,  
				                x1+(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)-(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W/2),//x1 + (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/4),
				                y1,//y1+ (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/4),
				                GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W,//(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2),
				                GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H-2,//(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2),
				                GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ALPHA); 
			}

		}
        // draw highlight button
		//if((gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_DOWN)
		// ||(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_MOVE)
		// ||(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_REPEAT))
		{
		
	        if((x_pop != 0)||(y_pop != 0))
	        {
				image_p = (U8*) GetImage(dialing_vk_pop_key_image[gui_dialer_pad_horizontal.highlight_index]);

				default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
				x1 = x_pop ;  

				y1 = y_pop ; 
                // draw highlight bg
                //gdi_layer_get_active(&handle_ptr);
               // gdi_push_and_set_alpha_blending_source_layer(handle_ptr);
				
				gdi_image_draw_resized( x1+(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)-(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_W/2), 						   
										y1+(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)-(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_H/2)-GUI_DIALER_PAD_HORIZONTAL_VK_KEY_BUTTTON_HIGHLIGHT_MOVE_UP,
										GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_W,
										GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_H,
				                		(U8*) GetImage(highlight_btn_img_id)); 
				//gdi_pop_and_restore_alpha_blending_source_layer();
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
                // draw highlight button
	       		gui_draw_resized_image_with_alpha_transparent(
								image_p,
								x1+(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W/2)-(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W/2),						   
								y1+(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H/2)-(GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_H/2),
								GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W,
								GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_H-2,
								GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ALPHA); 
				// draw nunber
				#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
              #endif 
			}
		}
	}
	
    gdi_layer_pop_clip();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
   
	
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_vk_pop_show_frame
 * DESCRIPTION
 *  show dialer vk pop frame 
 * PARAMETERS
 *  void
 *  
 *  
 * RETURNS
 * void
 *****************************************************************************/
void gui_dialer_pad_vk_pop_show_frame()
{  
    U8 default_show_state = 0;
    U8 *image_p =NULL;
    U8 j = 0;

    MMI_ID_TYPE btn_img_id = IMG_ID_DIALER_PAD_POP_BUTTON_NORMAL;
	MMI_ID_TYPE highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN;
	U8 old_highlight_index = gui_dialer_pad_horizontal.highlight_index; 


    // when pen move check if need redraw frame
    if((gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_MOVE)
		||(gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_REPEAT))
	{
		{	
			S16 x1,y1;
			S16 x_h,y_h;
			S16 x_pop = 0, y_pop = 0;
			
			
			for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT;j++ ) 
			{
				default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
				image_p = (U8*) GetImage(dialing_vk_pop_image[j]);
				if(image_p)
				{
					x1 =  GUI_DIALER_PAD_HORIZONTAL_START_X + (j%GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_MARGIN_W + GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W);
					y1 =  GUI_DIALER_PAD_HORIZONTAL_START_Y + (j/GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_MARGIN_H + GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H);
					x_h = gui_dialer_pad_horizontal.move_point.x ;
					y_h = gui_dialer_pad_horizontal.move_point.y ;	
					if((((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))>=0)&&((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2)))
						||(((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))< 0)&&(((x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2) - x_h )<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2)))
						)
					{
					   if((((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))>=0)&&((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2)))
						||(((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))< 0)&&(((y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2) - y_h )<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2)))
						)
						{
							gui_dialer_pad_horizontal.highlight_index = j;
							gui_dialer_pad_horizontal.vk_highlight_invalid = 0;
							x_pop = x1;
							y_pop = y1;
						}
					} 						 
				}
	
			}
			
			if((gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_MOVE)&&
				(GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START == gui_dialer_pad_horizontal.highlight_index))
			{
                if((old_highlight_index >= (GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START))
						     &&(old_highlight_index <= GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END)
				   )
                {
					gui_dialer_pad_horizontal.highlight_index = old_highlight_index;
					return;
				}
			}
			
			if((gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_MOVE)&&
				(old_highlight_index == gui_dialer_pad_horizontal.highlight_index))
			{
				return; // highlight index no change ,so return.
			}
            else if(gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_REPEAT)
            {
                if(gui_dialer_pad_horizontal.highlight_index == GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START)
                {
					gui_dialer_pad_horizontal.highlight_index_times++;
				}
				else
				{
					gui_dialer_pad_horizontal.highlight_index_times = 0;
				}
                gui_dialer_pad_horizontal.highlight_index = old_highlight_index;
				
				if(gui_dialer_pad_horizontal.highlight_index_times >= GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_INDEX_TIMES_MAX)
				{
				    gui_dialer_pad_horizontal.highlight_index_times = 0;				
					
					if(gui_dialer_pad_horizontal.highlight_index == GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END)
					{
						gui_dialer_pad_horizontal.highlight_index = GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START;
					}
					else if((gui_dialer_pad_horizontal.highlight_index >= (GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START))
						     &&(gui_dialer_pad_horizontal.highlight_index < GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END))
					{
						gui_dialer_pad_horizontal.highlight_index++;
					}
				}
				else
				{
					return; // highlight not in "*" , then return
				}
            }				
		}
	}


	if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT)
	{
		highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN_DOWN;
	}
    gdi_layer_lock_frame_buffer();       
	gdi_layer_push_and_set_clip(gui_dialer_pad_horizontal.x1 , gui_dialer_pad_horizontal.y1, 
	                            gui_dialer_pad_horizontal.x2 , gui_dialer_pad_horizontal.y2);

	gdi_draw_solid_rect(
						gui_dialer_pad_horizontal.x1,
						gui_dialer_pad_horizontal.y1,
						gui_dialer_pad_horizontal.x2,
						gui_dialer_pad_horizontal.y2,
						GDI_COLOR_TRANSPARENT); 
	
 
    
    // start draw from left to right 
   	{   
	    S16 x1,y1;
		S16 x_h,y_h;
		S16 x_pop = 0, y_pop = 0;

 		if((gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_DOWN)
			 ||(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_MOVE))
		{
			wgui_inputs_ml_disable();			
		}
		else if(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_UP)
		{
			wgui_inputs_ml_enable();			
		}
		
		wgui_inputs_ml_show(); // redraw dialer box

		
		for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT;j++ ) 
		{
            default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
            image_p = (U8*) GetImage(dialing_vk_pop_image[j]);
			if(image_p)
			{
				x1 =  GUI_DIALER_PAD_HORIZONTAL_START_X + (j%GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_MARGIN_W + GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W);
				y1 =  GUI_DIALER_PAD_HORIZONTAL_START_Y + (j/GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_MARGIN_H + GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H);
				x_h = gui_dialer_pad_horizontal.move_point.x ;
				y_h = gui_dialer_pad_horizontal.move_point.y ;	
				if((((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))>=0)&&((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2)))
					||(((x_h - (x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2))< 0)&&(((x1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2) - x_h )<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2)))
					)
				{
				   if((((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))>=0)&&((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2)))
					||(((y_h - (y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2))< 0)&&(((y1+GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2) - y_h )<= (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H/2)))
					)
					{
					    if(gui_dialer_pad_horizontal.pen_state != MMI_PEN_EVENT_REPEAT)
					    {
							gui_dialer_pad_horizontal.highlight_index = j;
					    }	
						gui_dialer_pad_horizontal.vk_highlight_invalid = 0;
						x_pop = x1;
						y_pop = y1;
					}
				}				  
 				gdi_image_draw_resized(				                
				                x1,                            
				                y1,
				                GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W,
				                GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H,
				                (U8*) GetImage(btn_img_id)); 

				#if 0			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				gui_draw_resized_image_with_alpha_transparent(
				                image_p,  
				                x1 + (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W/2)-(GUI_DIALER_PAD_HORIZONTAL_DEFAULT_IMAGE_W/2),
				                y1,
				                GUI_DIALER_PAD_HORIZONTAL_DEFAULT_IMAGE_W,
				                (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H-2),
				                GUI_DIALER_PAD_HORIZONTAL_VK_ALPHA); 				
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
				#endif

			}

		}
		// for pen up reset highlight value
		if((gui_dialer_pad_horizontal.pen_state == MMI_PEN_EVENT_UP)&&
		(GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START == gui_dialer_pad_horizontal.highlight_index))
		{
			if((old_highlight_index >= (GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START))
				     &&(old_highlight_index <= GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END)
			)
			{
				gui_dialer_pad_horizontal.highlight_index = old_highlight_index;
				gui_dialer_pad_horizontal.highlight_index_times = 0;	
			}
		}
        // draw big button
        if((!x_pop )&&(!y_pop ))
        {
			gui_dialer_pad_horizontal.vk_highlight_invalid = 1;
		}
		if((gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_DOWN)
		 ||(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_MOVE)
		 ||(gui_dialer_pad_horizontal.pen_state ==  MMI_PEN_EVENT_REPEAT))
		{
		
	        if((x_pop != 0)||(y_pop != 0))
	        {   
	            if(GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START == gui_dialer_pad_horizontal.highlight_index)
	            {
	             	//image_p = (U8*) GetImage(IMG_ID_DIALER_PAD_POP_NUMBEM);
					image_p = (U8*) GetImage(IMG_ID_DIALER_PAD_POP_H_NUMBEM);
	            }
				else
				{
					image_p = (U8*) GetImage(dialing_vk_pop_h_image[gui_dialer_pad_horizontal.highlight_index]);
	            }
				default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
				x1 = x_pop ;

				y1 = y_pop - GUI_DIALER_PAD_HORIZONTAL_POP_H - GUI_DIALER_PAD_HORIZONTAL_MARGIN_H; 

	       		gdi_image_draw_resized(								
								 x1, 						   
								 y1,
								GUI_DIALER_PAD_HORIZONTAL_POP_W,
								GUI_DIALER_PAD_HORIZONTAL_POP_H,
								//(U8*) GetImage(IMG_ID_DIALER_PAD_POP_BG)
								(U8*) GetImage(IMG_ID_DIALER_PAD_POP_LARGER_HIGH)								
								); 
				#if 0			               
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
				gui_draw_resized_image_with_alpha_transparent(
								image_p,
								(x1 ),
								(y1 ),
								(GUI_DIALER_PAD_HORIZONTAL_POP_W-2),
								(GUI_DIALER_PAD_HORIZONTAL_POP_H-2),
								GUI_DIALER_PAD_HORIZONTAL_VK_ALPHA); 				
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
                #endif
				

			}
		}
	}
    gdi_layer_pop_clip();
	gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
   
	
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_small_map_large_button_show_frame
 * DESCRIPTION
 *  show dialer small map and large button frame 
 * PARAMETERS
 *  void
 *  
 *  
 * RETURNS
 * void
 *****************************************************************************/
void gui_dialer_pad_small_map_large_button_show_frame()
{  

    U8 default_show_state = 0;
    U8 *image_p =NULL;
    U8 j = 0;

    MMI_ID_TYPE btn_img_id = IMG_ID_DIALER_PAD_BTN;
	MMI_ID_TYPE highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN;
	 
    //color c;
    
	if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT)
	{
		highlight_btn_img_id = IMG_ID_DIALER_PAD_BTN_DOWN;
	}
	
	gdi_layer_push_and_set_clip(gui_dialer_pad_horizontal.x1 , gui_dialer_pad_horizontal.y1, 
	                            gui_dialer_pad_horizontal.x2 , gui_dialer_pad_horizontal.y2);
	//gui_fill_rectangle(GUI_DIALER_PAD_HORIZONTAL_X1, GUI_DIALER_PAD_HORIZONTAL_Y1, GUI_DIALER_PAD_HORIZONTAL_X2, GUI_DIALER_PAD_HORIZONTAL_Y2, c);
	gdi_draw_solid_rect(
						gui_dialer_pad_horizontal.x1,
						gui_dialer_pad_horizontal.y1,
						gui_dialer_pad_horizontal.x2,
						gui_dialer_pad_horizontal.y2,
						GDI_COLOR_TRANSPARENT); 
	
   	{   
	    S16 x1,y1;
		S16 x_h,y_h;
		S16 x_pop = 0, y_pop = 0;

		
		for(j = 0;j < GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT;j++ ) 
		{
            default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
            image_p = (U8*) GetImage(dialing_ssp_key_image[j]);
			if(image_p)
			{
				x1 =  GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_X + (j%GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_SMALL_MAP_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_W + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W);
				y1 =  GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_Y + (j/GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_SMALL_MAP_COUNT)*(GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_H + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H);
				x_h = gui_dialer_pad_horizontal.move_point.x ;
				y_h = gui_dialer_pad_horizontal.move_point.y ;	
				if((((x_h - (x1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2))>=0)&&((x_h - (x1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2))<= (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2)))
					||(((x_h - (x1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2))< 0)&&(((x1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2) - x_h )<= (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2)))
					)
				{
				   if((((y_h - (y1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2))>=0)&&((y_h - (y1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2))<= (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2)))
					||(((y_h - (y1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2))< 0)&&(((y1 + GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2) - y_h )<= (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2)))
					)
					{
						gui_dialer_pad_horizontal.highlight_index = j;
						
						x_pop = x1;
						y_pop = y1;
					}
				}			  
					
				gui_draw_resized_image_with_alpha_transparent(
				                (U8*) GetImage(btn_img_id),
				                x1,                            
				                y1,
				                GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W,
				                GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H,
				                show_image_default_size[default_show_state].alpha); 
							
				gui_draw_resized_image_with_alpha_transparent(
				                image_p,  
				                x1 + (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/4),
				                y1+ (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/4),
				                (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W/2),
				                (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H/2),
				                show_image_default_size[default_show_state].alpha); 
			}

		}
        // draw big button
		{
		
	       // if((x_pop != 0)||(y_pop != 0))
	        {
	             image_p = (U8*) GetImage(dialing_ssp_key_image[0]);
	            default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;
				x1 = gui_dialer_pad_horizontal.move_point.x - show_image_default_size[default_show_state].w/2;
				if(x1 > GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_MAX_X)
				{
					x1 = GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_MAX_X;	
				}

				y1 = gui_dialer_pad_horizontal.move_point.y - show_image_default_size[default_show_state].h/2;	


				if((highlight_btn_img_id == IMG_ID_DIALER_PAD_BTN_DOWN)
					||(gui_dialer_pad_horizontal.move_point.x > (GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_MAX_X+show_image_default_size[default_show_state].w)))
				{
					x1 = GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_X ;
					y1 = GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_Y ;	
				}	
				gui_draw_resized_image_with_alpha_transparent(
								(U8*) GetImage(btn_img_id),
								 x1, 						   
								 y1,
								show_image_default_size[default_show_state].w,
								show_image_default_size[default_show_state].h,
								show_image_default_size[default_show_state].alpha); 
							
				gui_draw_resized_image_with_alpha_transparent(
								image_p,
								x1 + (show_image_default_size[default_show_state].w/4),
								y1 + (show_image_default_size[default_show_state].h/4),
								(show_image_default_size[default_show_state].w/2),
								(show_image_default_size[default_show_state].h/2),
								show_image_default_size[default_show_state].alpha); 



			}
		// draw highlight  button
	        {

				btn_img_id = highlight_btn_img_id;
	       
	            image_p = (U8*) GetImage(dialing_ssp_key_image[gui_dialer_pad_horizontal.highlight_index]);
	            default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES - 1;

				x1 = GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_X - show_image_default_size[default_show_state].w/2;
				y1 = GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_y - show_image_default_size[default_show_state].h/2;			
				gui_draw_resized_image_with_alpha_transparent(
								(U8*) GetImage(btn_img_id),
								 x1, 						   
								 y1,
								show_image_default_size[default_show_state].w,
								show_image_default_size[default_show_state].h,
								show_image_default_size[default_show_state].alpha); 
							
				gui_draw_resized_image_with_alpha_transparent(
								image_p, 
								x1 + (show_image_default_size[default_show_state].w/4),
								y1 + (show_image_default_size[default_show_state].h/4),
								(show_image_default_size[default_show_state].w/2),
								(show_image_default_size[default_show_state].h/2),
								show_image_default_size[default_show_state].alpha); 



	       


			}		
		}
	}
	
    gdi_layer_pop_clip();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
   	
}

void gui_dialer_pad_horizontal_timer_out()
{
	mmi_pen_point_struct point;
    S32 auto_move_x_flag = 0;
	
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
	{    
		if(gui_dialer_pad_horizontal.auto_move_flag ==	GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT)
		{
			auto_move_x_flag = 1;
		}
		else
		{
			auto_move_x_flag = -1;
		}
	     
		if((gui_dialer_pad_horizontal.auto_move_x_offset *auto_move_x_flag) < GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W)
		{
			gui_dialer_pad_horizontal.auto_move_x_offset = gui_dialer_pad_horizontal.auto_move_x_offset 
				                                               + (auto_move_x_flag*GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W); 
			point.x = gui_dialer_pad_horizontal.x1 + (gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2;
			point.y = gui_dialer_pad_horizontal.y1 + (gui_dialer_pad_horizontal.y2 - gui_dialer_pad_horizontal.y1)/2;	
			
			point.x = point.x + gui_dialer_pad_horizontal.auto_move_x_offset;

			gui_dialer_pad_horizontal_pen_move(point); 

			gui_start_timer(GUI_DIALER_PAD_HORIZONTAL_MOVE_TIMER, gui_dialer_pad_horizontal_timer_out);	  		 
		} 
		else
		{	
    		gui_dialer_pad_horizontal.move_x_offset = 0;
    		gui_dialer_pad_horizontal.auto_move_flag = 0;
			gui_dialer_pad_horizontal.auto_move_x_offset = 0;
			gui_cancel_timer(gui_dialer_pad_horizontal_timer_out);
		}

	}
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_next_item
 * DESCRIPTION
 *  get next item  
 * PARAMETERS
 *  void  
 *  
 *  
 * RETURNS
 *  void  
 *****************************************************************************/
void gui_dialer_pad_horizontal_next_item()
{   
    mmi_pen_point_struct point;
    U8 i = 0;
	U16 state_change_count =0;
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
	{
	    if((gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT) 
			||(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT))
	    {   
	        state_change_count = gui_dialer_pad_horizontal.auto_move_x_offset/ GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W;
	        if(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT)
			{
				state_change_count = state_change_count * (-1);
			}  
			if(state_change_count > GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES)
			{
				gui_dialer_pad_horizontal_check_cancel_timer();
			}
			else
			{
				return;
			}

	    }
		if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
		{ 
			point.x = gui_dialer_pad_horizontal.x1 + (gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2;
			point.y = gui_dialer_pad_horizontal.y1 + (gui_dialer_pad_horizontal.y2 - gui_dialer_pad_horizontal.y1)/2;	

			gui_dialer_pad_horizontal_pen_down(point); 

			gui_dialer_pad_horizontal.auto_move_flag =  GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT;
			gui_dialer_pad_horizontal.auto_move_x_offset = GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W; 	   
			gui_start_timer(GUI_DIALER_PAD_HORIZONTAL_MOVE_TIMER, gui_dialer_pad_horizontal_timer_out);		
		}
	}
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
	{
	    if(gui_dialer_pad_horizontal.highlight_index == (GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT -1))
	    {
			i = 1;
		}
		else if((gui_dialer_pad_horizontal.highlight_index + GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)>= GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT)
		{
        	i = GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT+1;	  
		}
		else
		{
			i = GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT;
		}
		do
		{
			gui_dialer_pad_horizontal.highlight_index = gui_dialer_pad_horizontal_get_next_item(gui_dialer_pad_horizontal.highlight_index);		
			i--;
		}while(i > 0);
		//gui_dialer_pad_horizontal.highlight_index = gui_dialer_pad_horizontal_get_next_item(gui_dialer_pad_horizontal.highlight_index);
		gui_dialer_pad_horizontal.move_key_redraw_frame = 1;
		gui_dialer_pad_horizontal.show_frame();
	}
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_prev_item
 * DESCRIPTION
 *  get prev item  
 * PARAMETERS
 *  void  
 *  
 *  
 * RETURNS
 *  void  
 *****************************************************************************/
void gui_dialer_pad_horizontal_prev_item()
{   
    mmi_pen_point_struct point;
    U8 i = 0;
	U16 state_change_count =0;
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
	{
	    if((gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT) 
			||(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT))
	    {   
	        state_change_count = gui_dialer_pad_horizontal.auto_move_x_offset/ GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W;
	        if(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT)
			{
				state_change_count = state_change_count * (-1);
			}  
			if(state_change_count > GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES)
			{
				gui_dialer_pad_horizontal_check_cancel_timer();
			}
			else
			{
				return;
			}

	    }

		
		if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL)
		{ 
			point.x = gui_dialer_pad_horizontal.x1 + (gui_dialer_pad_horizontal.x2 - gui_dialer_pad_horizontal.x1)/2;
			point.y = gui_dialer_pad_horizontal.y1 + (gui_dialer_pad_horizontal.y2 - gui_dialer_pad_horizontal.y1)/2;

			gui_dialer_pad_horizontal_pen_down(point); 

			gui_dialer_pad_horizontal.auto_move_flag =  GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT;
			gui_dialer_pad_horizontal.auto_move_x_offset = GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W*(-1); 	   
			gui_start_timer(GUI_DIALER_PAD_HORIZONTAL_MOVE_TIMER, gui_dialer_pad_horizontal_timer_out);		
		   
		}
	}
	else if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
	{
	    if(gui_dialer_pad_horizontal.highlight_index == 0)
	    {
			i = 1;
	    }
		else if(gui_dialer_pad_horizontal.highlight_index  < GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT)
		{
        	i = GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT+1;	  
		}
		else
		{
			i = GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT;
		}
		do
		{
			gui_dialer_pad_horizontal.highlight_index = gui_dialer_pad_horizontal_get_prev_item(gui_dialer_pad_horizontal.highlight_index);		
			i--;
		}while(i > 0);	
		//gui_dialer_pad_horizontal.highlight_index = gui_dialer_pad_horizontal_get_prev_item(gui_dialer_pad_horizontal.highlight_index);
		gui_dialer_pad_horizontal.move_key_redraw_frame = 1;
		gui_dialer_pad_horizontal.show_frame();
	}
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_get_next_item
 * DESCRIPTION
 *  get next item index 
 * PARAMETERS
 *  current_item [U8] current item index  
 *  
 *  
 * RETURNS
 *  next item index 
 *****************************************************************************/
U8 gui_dialer_pad_horizontal_get_next_item(U8 current_item)
{   
    U8 result_item = current_item;
	U8 max_count = GUI_DIALER_PAD_HORIZONTAL_KEY_COUNT;
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
	{
		max_count = GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT;
	}
    if(result_item < (max_count - 1))
    {
        result_item++;
    }
    else
    {
        result_item = 0;
    }
    return result_item;
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_get_prev_item
 * DESCRIPTION
 *  get prev item index 
 * PARAMETERS
 *  current_item [U8] current item index 
 *  
 *  
 * RETURNS
 *  prev item index 
 *****************************************************************************/ 
U8 gui_dialer_pad_horizontal_get_prev_item(U8 current_item)
{   
    U8 result_item = current_item;
	U8 max_count = GUI_DIALER_PAD_HORIZONTAL_KEY_COUNT;
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK_KEY)
	{
		max_count = GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT;
	}	
    if(result_item)
    {
        result_item--; 
    }
    else
    {
        result_item = max_count - 1;
    }

    return result_item;
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_move_reset_item_with_highlight
 * DESCRIPTION
 *  update image states with current highlight item
 * PARAMETERS
 *  void 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void gui_dialer_pad_horizontal_move_change_highlight(U8 change_times)
{  
    U8 i = 0;
    // update highlight  item
    if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_RIGHT)
    {
        for(i = 0 ;i < change_times ;i++)
        {
            gui_dialer_pad_horizontal.highlight_item = 
				   gui_dialer_pad_horizontal_get_prev_item(gui_dialer_pad_horizontal.highlight_item);
        }    
    }
    else if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_LEFT)
    {
        for(i = 0 ;i < change_times ;i++)
        {
            gui_dialer_pad_horizontal.highlight_item = 
				gui_dialer_pad_horizontal_get_next_item(gui_dialer_pad_horizontal.highlight_item);
        } 
    }
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_move_reset_item_with_highlight
 * DESCRIPTION
 *  update image states with current highlight item
 * PARAMETERS
 *  void 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/ 
void gui_dialer_pad_horizontal_move_reset_item_with_highlight()
{
    U8 item_index = 0;
    U8 old_item_index = 0;
    U8 i=0;
    U8 other_item1 = 0; //image index
    U8 other_item2 = 0; //image index

#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
		U8 debug_i = 0;	
#endif

	
    memset(show_image_struct,0,sizeof(show_image_struct));
    
    // update highlight item info
    item_index = (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2;
    show_image_struct[item_index].show_flag = 1;
    show_image_struct[item_index].default_show_state = GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES -1;   
    show_image_struct[item_index].index = gui_dialer_pad_horizontal.highlight_item;
    // update other  item info
    if(gui_dialer_pad_horizontal.highlight_item < GUI_DIALER_PAD_HORIZONTAL_KEY_COUNT )
    {   
        other_item1 = gui_dialer_pad_horizontal.highlight_item;
        for(i = 0;i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT;i++ )
        {   
            if(i == ((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {
               other_item1 = gui_dialer_pad_horizontal.highlight_item; 
               item_index = (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2;
               continue;
            }             
            old_item_index = item_index;
            if(i<((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {   
                other_item2 = gui_dialer_pad_horizontal_get_prev_item(other_item1);
                if(item_index)
                {
                    item_index--;
                }                 
            }
            else 
            {
                other_item2 = gui_dialer_pad_horizontal_get_next_item(other_item1);
                if(item_index < (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1))
                {
                    item_index++;
                } 
            }
            show_image_struct[item_index].show_flag = 1;
            if(show_image_struct[old_item_index].default_show_state >= GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_STATE)
            {
                show_image_struct[item_index].default_show_state = show_image_struct[old_item_index].default_show_state - GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_STATE;
            }
			else
			{
				show_image_struct[item_index].default_show_state = 0;
			}	
			
            other_item1 = other_item2;
            show_image_struct[item_index].index = other_item2;
			
            if(i<((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {   
                show_image_struct[item_index].default_max_show_state = show_image_struct[item_index + 1].default_show_state ;
				show_image_struct[item_index + 1].default_min_show_state = show_image_struct[item_index].default_show_state ;
                if(!item_index)
                {					
					show_image_struct[item_index].default_min_show_state = show_image_struct[item_index].default_show_state ;
                }                 
            }
            else 
            {
                show_image_struct[item_index].default_max_show_state = show_image_struct[item_index - 1].default_show_state ;
				show_image_struct[item_index - 1].default_min_show_state = show_image_struct[item_index].default_show_state ;
                if(item_index == (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT - 1))
                {					
					show_image_struct[item_index].default_min_show_state = show_image_struct[item_index].default_show_state ;
                } 
            }
			
        }
    }




#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
    kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_move_reset_item_with_highlight start \n");
	for(debug_i = 0;debug_i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT; debug_i++ )
	{

		kal_prompt_trace(MOD_MMI_COMMON_APP,"R show_image_struct[%d].default:%d  max: %d min: %d show_state:%d change_flag: %d index: %d show_flag: %d", 
			      debug_i,
			      show_image_struct[debug_i].default_show_state,
			      show_image_struct[debug_i].default_max_show_state,
			      show_image_struct[debug_i].default_min_show_state,
			      show_image_struct[debug_i].show_state,
			      show_image_struct[debug_i].change_flag,
			      show_image_struct[debug_i].index,
			      show_image_struct[debug_i].show_flag);
			      
	}
    kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_move_reset_item_with_highlight end \n");
#endif

}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_move_change_item_state
 * DESCRIPTION
 *  update image states
 * PARAMETERS
 *  change_state [U8]pen move change image states 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_move_change_item_state(U8 change_state)
{
    U8 i=0;
    U8 large_or_small = 0; // 1: large,2:small
    U8 item_index = 0;

#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
    U8 debug_i = 0;
#endif
	
    // update highlight item info
    item_index = (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2;
	
    show_image_struct[item_index].show_state =  change_state;
	show_image_struct[item_index].change_flag = GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL;
	
    // update other  item info
    {   
        for(i = 0;i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT ;i++)
        {   
            large_or_small = 0;
            if(i == ((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {
               item_index = (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2;
               continue;
            }
            if((!item_index)||(item_index == GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1))
            {
				continue;
			}
            if(i < ((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {   
                if(item_index)
                {
                    item_index--;
                } 
                if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_RIGHT)
                {   
                    large_or_small = GUI_DIALER_PAD_HORIZONTAL_SMALL_TO_LARGE;    
                }
                else
                {
                    large_or_small = GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL;
                }
            }
            else if(i > ((GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1)/2))
            {
                if(item_index < (GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT-1))
                {
                    item_index++;
                } 
                if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_LEFT)
                {   
                    large_or_small = GUI_DIALER_PAD_HORIZONTAL_SMALL_TO_LARGE;   
                }
                else
                {
                    large_or_small = GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL;
                }

            } 
			//GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL			
			{
            	show_image_struct[item_index].change_flag = large_or_small;     
				show_image_struct[item_index].show_state  = change_state;
			}
        }
    }
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
		kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_move_change_item_state start change_state:%d \n",change_state);
		for(debug_i = 0;debug_i < GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT; debug_i++ )
		{

			kal_prompt_trace(MOD_MMI_COMMON_APP,"M show_image_struct[%d].default:%d  max: %d min: %d show_state:%d change_flag: %d index: %d show_flag: %d", 
				      debug_i,
				      show_image_struct[debug_i].default_show_state,
				      show_image_struct[debug_i].default_max_show_state,
				      show_image_struct[debug_i].default_min_show_state,
				      show_image_struct[debug_i].show_state,
				      show_image_struct[debug_i].change_flag,
				      show_image_struct[debug_i].index,
				      show_image_struct[debug_i].show_flag);
			      
	}
		kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_move_change_item_state end \n");
#endif
	

}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_check_range
 * DESCRIPTION
 *  check pen event point 
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen down/move/up point 
 *  
 *  
 * RETURNS
 *  point in dialer horizontal area or not 
 *****************************************************************************/
MMI_BOOL gui_dialer_pad_horizontal_check_range(mmi_pen_point_struct point)
{
    if((point.x > gui_dialer_pad_horizontal.x1)&&(point.x < gui_dialer_pad_horizontal.x2)
         &&(point.y > gui_dialer_pad_horizontal.y1)&&(point.y < gui_dialer_pad_horizontal.y2))
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}    
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_check_cancel_timer
 * DESCRIPTION
 *  check cancel auto move timer
 * PARAMETERS
 *  void 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_check_cancel_timer(void)
{
	U16 state_change_count =0;

    if((gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT) 
		||(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT))
    {   
        state_change_count = gui_dialer_pad_horizontal.auto_move_x_offset/ GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W;
        if(gui_dialer_pad_horizontal.auto_move_flag == GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT)
		{
			state_change_count = state_change_count * (-1);
		}  
		if(state_change_count > GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES)
		{
			gui_dialer_pad_horizontal_move_change_highlight(1);
		}
		gui_dialer_pad_horizontal.move_x_offset = 0;
		gui_dialer_pad_horizontal.highlight_change = 0;
		gui_dialer_pad_horizontal.auto_move_x_offset = 0;
		gui_dialer_pad_horizontal.auto_move_flag = 0;
		gui_cancel_timer(gui_dialer_pad_horizontal_timer_out);
	}

}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_pen_down
 * DESCRIPTION
 *  handle pen down event
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen down point 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_pen_down(mmi_pen_point_struct point)
{
	 //SetKeyHandler(gui_dialer_pad_horizontal_next_item, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
	 
	 //SetKeyHandler(gui_dialer_pad_horizontal_prev_item, KEY_LEFT_ARROW, KEY_EVENT_DOWN);

	 gui_dialer_pad_horizontal_check_cancel_timer();

	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
	    if(gui_dialer_pad_horizontal.up_time_out_flag == GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_INSERT_CHAR)
	    {
			gui_dialer_pad_horizontal.up_time_out_flag = GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START;
		}
		
		if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START)
		{		
			return;
		}
	}

	if(gui_dialer_pad_horizontal_check_range(point))
	{
		gui_dialer_pad_horizontal.move_point.x = point.x;
		gui_dialer_pad_horizontal.move_point.y = point.y;

		           
		gui_dialer_pad_horizontal.old_point.x = point.x;
		gui_dialer_pad_horizontal.old_point.y = point.y;
		gui_dialer_pad_horizontal.move_flag = 0;

		gui_dialer_pad_horizontal.old_highlight_item = gui_dialer_pad_horizontal.highlight_item;
		gui_dialer_pad_horizontal_move_reset_item_with_highlight();
		if(gui_dialer_pad_horizontal_check_highlight_item_range(point))
		{
		  gui_dialer_pad_horizontal.move_flag = GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT; //just for show highlight  pic
		}

		{		 
			gui_dialer_pad_horizontal.pen_state =  MMI_PEN_EVENT_DOWN;
		}
        gui_dialer_pad_horizontal.show_frame();
	}
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_pen_up
 * DESCRIPTION
 *  handle pen up event
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen up point 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_pen_up(mmi_pen_point_struct point)
{
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START)
		{		
			return;
		}
	}  
    if((gui_dialer_pad_horizontal.highlight_change)&&(gui_dialer_pad_horizontal.move_flag))
    {
        gui_dialer_pad_horizontal_move_change_highlight(1);
    }
    gui_dialer_pad_horizontal_move_reset_item_with_highlight();
    gui_dialer_pad_horizontal.old_highlight_item = gui_dialer_pad_horizontal.highlight_item;
    gui_dialer_pad_horizontal.move_x_offset = 0;
    if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT)
    {
		gui_dialer_pad_horizontal.move_flag = 0; //just for show normal pic
    }	

	{		 
		gui_dialer_pad_horizontal.pen_state =  MMI_PEN_EVENT_UP;
	}
	if(gui_dialer_pad_horizontal.other_ui_flag != GUI_DIALER_PAD_STYLE_VK)
	{
    	gui_dialer_pad_horizontal.show_frame();
	}	
	
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{  
	    gui_dialer_pad_horizontal.up_time_out_flag = GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_DELAY;
		gui_cancel_timer(gui_dialer_pad_horizontal_pop_up_timer_out);
		gui_start_timer(GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT, gui_dialer_pad_horizontal_pop_up_timer_out);	
	}  
}
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_pen_repeat
 * DESCRIPTION
 *  handle pen repeat event
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen repeat point 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_pen_repeat(mmi_pen_point_struct point)
{
	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START)
		{	
			return;
		}
	}

	if(gui_dialer_pad_horizontal_check_range(point))
	{
	    if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	    {
	        gui_dialer_pad_horizontal.move_point.x = point.x;
			gui_dialer_pad_horizontal.move_point.y = point.y;
			
			gui_dialer_pad_horizontal.pen_state =  MMI_PEN_EVENT_REPEAT;
			
		    gui_dialer_pad_horizontal.show_frame();
	    }
	}	
}

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_pen_move
 * DESCRIPTION
 *  handle pen move event
 * PARAMETERS
 *  point [mmi_pen_point_struct]pen move point 
 *  
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_pen_move(mmi_pen_point_struct point)
{
    U16 move_x =0;
    U16 state_change_count =0;

	if(gui_dialer_pad_horizontal.other_ui_flag == GUI_DIALER_PAD_STYLE_VK)
	{
		if(gui_dialer_pad_horizontal.up_time_out_flag != GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START)
		{	
			return;
		}
	}
	
    if(gui_dialer_pad_horizontal_check_range(point))
    {   
        gui_dialer_pad_horizontal.move_point.x = point.x;
		gui_dialer_pad_horizontal.move_point.y = point.y;
	
        gui_dialer_pad_horizontal.highlight_change = 0;
        if(gui_dialer_pad_horizontal.old_point.x <= point.x)
        {   move_x = point.x - gui_dialer_pad_horizontal.old_point.x;
            gui_dialer_pad_horizontal.move_flag = GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_RIGHT;
        }
        else if(gui_dialer_pad_horizontal.old_point.x > point.x)
        {   move_x = gui_dialer_pad_horizontal.old_point.x - point.x;
            gui_dialer_pad_horizontal.move_flag = GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_LEFT;
        }
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
		kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_pen_move start old_point.x:%d  X:%d \n",gui_dialer_pad_horizontal.old_point.x,point.x);				
#endif

        state_change_count =  move_x/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W;
        gui_dialer_pad_horizontal.highlight_item = gui_dialer_pad_horizontal.old_highlight_item ; 
        if(move_x >= GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W)
        {
             gui_dialer_pad_horizontal_move_change_highlight(move_x/GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W);
             gui_dialer_pad_horizontal_move_reset_item_with_highlight();
        }
        
        move_x = move_x % GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W;
        
        state_change_count =  move_x/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W;
        
        if(move_x > GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)
        {
            if(state_change_count > GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES)
            {
                gui_dialer_pad_horizontal.highlight_change = 1;
            }
            gui_dialer_pad_horizontal_move_reset_item_with_highlight();
            gui_dialer_pad_horizontal_move_change_item_state(state_change_count);  
        }
        if(gui_dialer_pad_horizontal.move_flag == GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_RIGHT)
        {
            gui_dialer_pad_horizontal.move_x_offset = move_x;
        }
        else 
        {
            gui_dialer_pad_horizontal.move_x_offset = move_x*(-1); 
        }
#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
		kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_pen_move  old_point.x:%d  X:%d move_x_offset:%d\n",gui_dialer_pad_horizontal.old_point.x,point.x,gui_dialer_pad_horizontal.move_x_offset);				
#endif 
		{		 
			gui_dialer_pad_horizontal.pen_state =  MMI_PEN_EVENT_MOVE;
		}

        gui_dialer_pad_horizontal.show_frame();

#ifdef DEBUG_BT_BOX_PEN_MOVE_DIALER_UI
			kal_prompt_trace(MOD_MMI_COMMON_APP,"gui_dialer_box_ssp_pen_move end old_point.x:%d  X:%d move_x_offset:%d\n",gui_dialer_pad_horizontal.old_point.x,point.x,gui_dialer_pad_horizontal.move_x_offset);				
#endif 



    }
        
 
}


#endif /*BT_BOX_PEN_MOVE_HORIZONTAL_UI*/


#if defined(GUI_DIALER_PAD_MATRIX_DIALER)

/*offset y between the top and row(1,2,3)*/
static S32 g_picker_offset_y = 0;

//for ssp use
static S32 g_picker_interval = GUI_DIALER_PAD_IMAGE_MATRIX_INTERVAL;


static gui_dialer_pad_transform_struct g_gui_dialer_pad_transform;
static float gui_dialer_pad_transform_scale;
static gui_dialer_pad_image_matrix_scrolling_by_pen_state g_gui_dialer_pad_matrix_image_state;
static U32 g_gui_dialer_pad_matrix_image_pen_down_time;
static S32 g_gui_dialer_pad_matrix_image_pen_down_y;
static S32 g_gui_dialer_pad_matrix_image_pen_move_y;


/*****************************************************************************
* FUNCTION
*  gui_get_matrix_image_picker_max_row
*
* DESCRIPTION
*  gui_get_matrix_image_picker_max_row
* PARAMETERS
*  void
* RETURNS
* max row index
*
*****************************************************************************/
static S32 gui_get_matrix_image_picker_max_row(void)
{
   S32 index, i_max=0;
   float tmp = g_gui_dialer_pad_transform.y_offset[0] - g_gui_dialer_pad_transform.row_top[0];
   for(index = 1; index < GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; index++)
   {
      if(tmp<=g_gui_dialer_pad_transform.y_offset[index] - g_gui_dialer_pad_transform.row_top[index])
      {
		 tmp = g_gui_dialer_pad_transform.y_offset[index] - g_gui_dialer_pad_transform.row_top[index];
		 i_max = index;
	  }
   }
	return i_max;
}


/*****************************************************************************
* FUNCTION
*  gui_get_matrix_image_picker_row_scale0
*
* DESCRIPTION
*  gui_get_matrix_image_picker_row_scale0
* PARAMETERS
*  ri, row index
* RETURNS
* row scale
*
*****************************************************************************/
static float gui_get_matrix_image_picker_row_scale0(S32 ri)
{
    g_gui_dialer_pad_transform.scale = g_gui_dialer_pad_transform.row_top[ri]/(float)GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
  
  	if(g_gui_dialer_pad_transform.scale>=1.0f)
	{
	  g_gui_dialer_pad_transform.scale = 1.0f;
	}
	else if(g_gui_dialer_pad_transform.scale<=0.0f)
	{
		g_gui_dialer_pad_transform.scale = 0.0f;	
	}
   	return g_gui_dialer_pad_transform.scale;
}


/*****************************************************************************
* FUNCTION
*  gui_dialer_pad_matrix_image_sync_offset_down2up
*
* DESCRIPTION
*  gui_dialer_pad_matrix_image_sync_offset_down2up
* PARAMETERS
*  y_offset
* RETURNS
* void
*
*****************************************************************************/
static void gui_dialer_pad_matrix_image_sync_offset_down2up(S32 indx, S32 num)
{
   S32 ri;
   U32 igap = 0;
   float scale = 1.0f;
   
   for(ri = 1; ri <num; ri++)
   {
	   float row_top = g_gui_dialer_pad_transform.row_top[indx];
	   if(indx - 1 < 0)
	   {
		  indx = (indx - 1) + GUI_DIALER_PAD_IMAGE_MATRIX_ROWS;
	   }
	   else
	   {
		  indx = indx - 1;
	   }  
	   igap =(float)(scale * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_YGAP);
	   g_gui_dialer_pad_transform.y_offset[indx] = row_top - igap;
	   g_gui_dialer_pad_transform.row_top[indx] = 0.5f * g_gui_dialer_pad_transform.y_offset[indx];
	   scale = gui_get_matrix_image_picker_row_scale0(indx);

  }
}


/*****************************************************************************
* FUNCTION
*  gui_find_matrix_image_picker_sync_mostbottom
*
* DESCRIPTION
*  gui_find_matrix_image_picker_sync_mostbottom
* PARAMETERS
*  y_offset
* RETURNS
* void
*
*****************************************************************************/
static S32 gui_find_matrix_image_picker_sync_mostbottom(S32 y_offset)
{
	S32 ri;
	S32 imin = 0;
	float fmin = 0.0f;
	//first find top in latter half
	for(ri = 0; ri<GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; ri++)
	{
	   float top = g_gui_dialer_pad_transform.row_top[ri] + y_offset;	
       //keep it in [0, 2h]
	   if(top < 0)
	   {
		  top = top + 2.0f * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
	   }
	   else if(top >2.0f * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H)
	   {
		  top = top - 2.0f * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
	   }     		 

	   if(top >= GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H && top < 2.0f * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H)			 
	   	{
	   	   g_gui_dialer_pad_transform.row_top[ri] = top;
		   g_gui_dialer_pad_transform.y_offset[ri] = 2.0f * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
		   return ri;
	   	}   
	}
    
	fmin = g_gui_dialer_pad_transform.row_top[0] + y_offset - GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
	if(fmin < 0)
      fmin = -fmin;

	for(ri = 0; ri<GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; ri++)
	{
	   float delta = g_gui_dialer_pad_transform.row_top[ri] + y_offset - GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
	   if(delta < 0)
		   delta = -delta;
       
       if(fmin > delta)
       {
			fmin = delta;
			imin = ri;
	   }
	}
	
	return imin;

}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_sync_offset_y0
 *
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_sync_offset_y0
 * PARAMETERS
 *  y_offset
 * RETURNS
 * void
 *
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_sync_offset_y0(S32 y_offset)
{
	S32 ri, indx;
	float scale = 0.0f;
	U32 igap = 0;
	float ih = 0.0f;
	MMI_BOOL up = MMI_TRUE;
	float sum_ih = 0.0f;
	S32 max;

	max = gui_find_matrix_image_picker_sync_mostbottom(y_offset);
	gui_dialer_pad_matrix_image_sync_offset_down2up(max, GUI_DIALER_PAD_IMAGE_MATRIX_ROWS);
}


/*****************************************************************************
 * FUNCTION
 *  gui_adjust_matrix_image_picker_y_offset
 *
 * DESCRIPTION
 *  gui_adjust_matrix_image_picker_y_offset
 * PARAMETERS
 *  y_offset
 * RETURNS
 * void
 *
 *****************************************************************************/
static void gui_adjust_matrix_image_picker_y_offset(S32 y_offset)
{
  //float h;
  S32 rows =  GUI_DIALER_PAD_IMAGE_MATRIX_ROWS;
  S32 ri = 0;
  float h = (float)g_dialer_pad_cntx.original_bound.height; 

   gui_dialer_pad_matrix_image_sync_offset_y0(y_offset);
/*
adjust the offset to [0, h]
*/
  for(ri = 0;ri<GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; ri++)
  { 
//    g_gui_dialer_pad_transform.y_offset[ri] += (float)y_offset;
	if(g_gui_dialer_pad_transform.y_offset[ri] > h)
	{
		 while (g_gui_dialer_pad_transform.y_offset[ri] > h)
		 {
		   g_gui_dialer_pad_transform.y_offset[ri] -= h;
		 }
	}
	else if(g_gui_dialer_pad_transform.y_offset[ri] < 0.0)
	{
		while(g_gui_dialer_pad_transform.y_offset[ri] < 0.0)
		{
			g_gui_dialer_pad_transform.y_offset[ri] += h;
		}
	}

  }
}


/*****************************************************************************
 * FUNCTION
 *  gui_draw_image_with_transform_p
 * ?????float
 * DESCRIPTION
 *  gui_draw_image_with_transform_p
 * PARAMETERS
 *  void
 * RETURNS
 * void
 *
 *****************************************************************************/
void gui_draw_image_with_transform_p(
	U8*img_ptr,//img buffer
	S32 x,
	S32 y,
	S32 w,
	S32 h,
	MMI_BOOL num_img,//MMI_TRUE, num img
	S32 ri)//row index
{    
	gdi_handle temp_layer = NULL;
	S32 tmp_size;
	U8 *tmp_buf;
	U8 alpha;
	float* scale = &g_gui_dialer_pad_transform.scale;

///??resize img
    x = x + w * (1.0 - *scale)/(float)2.0;
 //   y = y + h * (1.0 - *scale)/(float)2.0;
	if(g_gui_dialer_pad_transform.row_top[ri]>GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H)
		y = y - g_gui_dialer_pad_transform.y_offset[ri] + g_gui_dialer_pad_transform.row_top[ri];
	else
		y = y - (*scale) * h;
	w = w * (*scale);
	h = h * (*scale);

	if(num_img)//half the size
	{
		x = x + w/4.0f;
		y = y + h/4.0f;
		w = w/2.0f;
		h = h/2.0f;
	}
	
    
	if(*scale < 0.3f)
	{
		alpha = 255 * 0.3f;
	}
	else
	{
		alpha = 255 * (*scale);
	}

	tmp_size = w * h * GDI_COLOR_FORMAT_32;
	tmp_buf = (U8*) mmi_frm_scrmem_alloc_framebuffer(tmp_size);	 

	gdi_layer_create_cf_using_outside_memory(
		GDI_COLOR_FORMAT_32,
		x,
		y,
		w,
		h,
		&temp_layer,
		tmp_buf,
		tmp_size);
			 
	gdi_layer_push_and_set_active(temp_layer);
	gdi_image_draw_resized(
		0,
		0,
		w,
		h,
		img_ptr);
	gdi_layer_set_opacity(MMI_TRUE, alpha);

	gdi_layer_pop_and_restore_active();

	((gdi_layer_struct*)temp_layer)->offset_x = ((gdi_layer_struct*)temp_layer)->offset_x + gdi_act_layer->offset_x;
	((gdi_layer_struct*)temp_layer)->offset_y = ((gdi_layer_struct*)temp_layer)->offset_y + gdi_act_layer->offset_y;



	gdi_layer_flatten_with_clipping((gdi_handle)gdi_act_layer,temp_layer, 0 , 0);

	gdi_layer_free(temp_layer);
	mmi_frm_scrmem_free(tmp_buf);
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_matrix_image_picker_show_scale
 * DESCRIPTION
 *  gui_get_matrix_image_picker_show_scale
 * PARAMETERS
 *  void
 * RETURNS
 * scale
 *
 *****************************************************************************/
static float gui_get_matrix_image_picker_show_scale(S32 ri)
{
	float scale = (g_gui_dialer_pad_transform.y_offset[ri] - g_gui_dialer_pad_transform.row_top[ri])/(float)GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;

//to keep the scale between [0, 1]
	if(scale < 0.0f)
	{
		scale = 0.0f;
	}
	else if(scale > 1.0f)
	{
		scale = 1.0f;
	}

	return scale;
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_matrix_image_picker_hilited_index
 * DESCRIPTION
 *  gui_get_matrix_image_picker_hilited_index
 * PARAMETERS
 *  pos, current pen down position
 * RETURNS
 *    get  the pen down item index
 *	-1, invalid
 *	[0, 11], valid
 *****************************************************************************/
static S16 gui_get_matrix_image_picker_hilited_index(mmi_pen_point_struct pos)
{
   S16 hilited_col;
   S16 index = 0;
   if(pos.y > g_dialer_pad_cntx.original_bound.y + 
		g_dialer_pad_cntx.original_bound.height - GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H)
	{
	
		if(pos.x >= g_dialer_pad_cntx.original_bound.x && 
			pos.x <= g_dialer_pad_cntx.original_bound.x + GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W)
		{
           hilited_col = 0;
		}
		else if(pos.x >=g_dialer_pad_cntx.original_bound.x + GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W +GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_XGAP&&
			pos.x <= g_dialer_pad_cntx.original_bound.x + 2 * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W +GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_XGAP)
		{
			hilited_col = 1;
		}
		else if(pos.x <=g_dialer_pad_cntx.original_bound.x +
			g_dialer_pad_cntx.original_bound.width)
		{
			hilited_col = 2;
		}
		else
		{
			return -1;
		}
		
		return g_gui_dialer_pad_transform.hilited_row * 3 + hilited_col;	
	}
    return -1;
  
}


/*****************************************************************************
 * FUNCTION
 *  gui_get_matrix_image_picker_hilited
 * DESCRIPTION
 *  gui_get_matrix_image_picker_hilited
 * PARAMETERS
 *  void
 * RETURNS
 *    get  the pen down item index
 *	-1, invalid
 *	[0, 11], valid
 *****************************************************************************/
static S16 gui_get_matrix_image_picker_hilited(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#ifdef __MMI_TOUCH_SCREEN__
    return gui_get_matrix_image_picker_hilited_index(g_dialer_pad_cntx.pen_down_pos);
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_show
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_show
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_show(void)
{
   S16 item_indx;
   S16 ri = 0;
   S16 i  = 0;
   U16 item_bkg_img = IMG_ID_DIALER_PAD_BTN;
   S32 x,y, w, h;
   S32 hilited_x, hilited_y;
   float scale = 0.5f;
   MMI_BOOL up = MMI_TRUE;
   S16 hilited_item = -1;
   
   if(g_gui_dialer_pad_transform.hilited_col>=0 && 
   	g_gui_dialer_pad_transform.hilited_col<3)
   {
   		hilited_item = g_gui_dialer_pad_transform.hilited_col + 
   			g_gui_dialer_pad_transform.hilited_row * 3;
   }

//   kal_prompt_trace(MOD_MMI, "g_picker_offset_y = %d", g_picker_offset_y);
   
   if(g_picker_offset_y > 0)
   {   		
		up = MMI_FALSE;
   }

//adjust offset
   if(up)
   {
   	 g_picker_offset_y = g_gui_dialer_pad_transform.up_scroll_sensitivity * g_picker_offset_y;
   }
   else
   {
   	 g_picker_offset_y = g_gui_dialer_pad_transform.up_scroll_sensitivity * g_picker_offset_y;
   }

   g_picker_offset_y %= (2 * GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H);
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
   x = g_dialer_pad_cntx.original_bound.x;
   y = g_dialer_pad_cntx.original_bound.y;
   w = g_dialer_pad_cntx.original_bound.width;
   h = g_dialer_pad_cntx.original_bound.height; 

   gui_adjust_matrix_image_picker_y_offset(g_picker_offset_y);
  
   for(ri = 0; ri<GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; ri++)//PICKER_IMAGE_ROWS
   {
        item_indx = ri*3;

		g_gui_dialer_pad_transform.scale = gui_get_matrix_image_picker_row_scale0(ri);//gui_get_matrix_image_picker_show_scale(ri);
		
		hilited_x = GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_BORDER + x;
	
		for(i=0;i<3; i++)
		{
			S32 img_id = IMG_ID_DIALER_PAD_0 + gui_dialer_pad_matrix[item_indx++].image_index;
            //hilited item
            if(item_indx - 1  == hilited_item)
            {
				item_bkg_img = IMG_ID_DIALER_PAD_BTN_DOWN;
			}
			else
			{
				item_bkg_img = IMG_ID_DIALER_PAD_BTN;
			}
			//draw number bkg 
			gui_draw_image_with_transform_p(
			  (U8*)GetImage(item_bkg_img), 
			  hilited_x,
			  y + g_gui_dialer_pad_transform.y_offset[ri],
			  GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W,
			  GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H,
			  MMI_FALSE,
			  ri
				);
			
		    //draw num , half size 
			gui_draw_image_with_transform_p(
				(U8*)GetImage(img_id), 
				hilited_x,
				y + g_gui_dialer_pad_transform.y_offset[ri],
				GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W,
				GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H,
				MMI_TRUE,
				ri
				);
			hilited_x += GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_XGAP + GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W ;
		}
   }
   
  // g_picker_offset_y = 5;

}


/*****************************************************************************
 * FUNCTION
 *  gui_sync_matrix_image_picker_final
 * DESCRIPTION
 *  gui_sync_matrix_image_picker_final
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_sync_matrix_image_picker_final(void)
{
   S32 ri;
   S32 hilited_row = gui_get_matrix_image_picker_max_row(); 

   S32 h = g_dialer_pad_cntx.original_bound.height;
   //init
   for(ri = 0; ri <GUI_DIALER_PAD_IMAGE_MATRIX_ROWS; ri++)
   {
	   g_gui_dialer_pad_transform.y_offset[ri] = 0;//g_dialer_pad_cntx.original_bound.height/2.0;
	   g_gui_dialer_pad_transform.row_top[ri] = 0;
   }

   g_gui_dialer_pad_transform.y_offset[hilited_row] = h-1;//g_dialer_pad_cntx.original_bound.height/2.0;
   g_gui_dialer_pad_transform.row_top[hilited_row] = h/2;

   g_gui_dialer_pad_transform.hilited_col = -1;
   g_gui_dialer_pad_transform.hilited_row = hilited_row;
   	
   g_picker_offset_y = 0;
   g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS;
   gui_adjust_matrix_image_picker_y_offset(g_picker_offset_y);
   
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_show_dialer
 * DESCRIPTION
 *  Show Dialer
 * PARAMETERS
 *  hint_type  [IN]  gui_dialer_pad_hint_type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_show_dialer_with_image(void)
{
	/*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
	 gui_bound bound = {0};
	 gdi_handle base_layer;
	 S32 hilited_row;
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 bound.x = g_dialer_pad_cntx.original_bound.x;
	 bound.y = g_dialer_pad_cntx.original_bound.y;
	 bound.width = g_dialer_pad_cntx.original_bound.width;
	 bound.height = g_dialer_pad_cntx.original_bound.height;
	
	 gdi_layer_get_base_handle(&base_layer);
	 gdi_layer_push_and_set_active(base_layer);
	 gdi_layer_push_and_set_clip(
	 	 g_dialer_pad_cntx.original_bound.x, 
	 	 g_dialer_pad_cntx.original_bound.y, 
	 	 g_dialer_pad_cntx.original_bound.x + g_dialer_pad_cntx.original_bound.width, 
		 g_dialer_pad_cntx.original_bound.y + g_dialer_pad_cntx.original_bound.height);
	 gdi_draw_solid_rect(
	 	g_dialer_pad_cntx.original_bound.x, 
	 	g_dialer_pad_cntx.original_bound.y, 
	 	g_dialer_pad_cntx.original_bound.x + g_dialer_pad_cntx.original_bound.width, 
		g_dialer_pad_cntx.original_bound.y + g_dialer_pad_cntx.original_bound.height, 
		GDI_COLOR_TRANSPARENT);

     //
     //show dialer picker with matrix image style
	 gui_dialer_pad_matrix_image_show();

	gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(
		g_dialer_pad_cntx.original_bound.x, 
		g_dialer_pad_cntx.original_bound.y, 
		g_dialer_pad_cntx.original_bound.x+g_dialer_pad_cntx.original_bound.width, 
		g_dialer_pad_cntx.original_bound.y+g_dialer_pad_cntx.original_bound.height);

//	gui_start_timer(g_picker_interval, gui_dialer_pad_show_dialer_with_image);
}


//ssp
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_ssp_update_frame
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_ssp_update_frame
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_ssp_update_frame(void)
{
	switch(g_gui_dialer_pad_matrix_image_state)
    {
       case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD:
       {
          g_picker_offset_y = g_gui_dialer_pad_matrix_image_pen_move_y - g_gui_dialer_pad_matrix_image_pen_down_y;
	   	   gui_dialer_pad_show_dialer_with_image();		
	   }
	   break;	
	   case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FREE_RUN:
	   {
			g_picker_offset_y = g_gui_dialer_pad_transform.scroll_momentum * 
				g_gui_dialer_pad_transform.scroll_coefficient;
						 
			if((S32)g_picker_offset_y == (S32)g_gui_dialer_pad_transform.scroll_momentum)
			{
				 gui_sync_matrix_image_picker_final();
				 gui_dialer_pad_show_dialer_with_image();
				 
				 gui_cancel_timer(gui_dialer_pad_matrix_image_ssp_update_frame);
			}
			else
			{
				 gui_dialer_pad_show_dialer_with_image();
				g_gui_dialer_pad_transform.scroll_momentum = g_picker_offset_y;
			    gui_start_timer((g_picker_interval), gui_dialer_pad_matrix_image_ssp_update_frame);
			}
	   }
	   break;
	}

}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_pen_abort_hdlr
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_pen_abort_hdlr
 * PARAMETERS
 *  pos: current pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_pen_abort_hdlr(void)
{

	gui_sync_matrix_image_picker_final();
	gui_dialer_pad_show_dialer_with_image();

	gui_cancel_timer(gui_dialer_pad_matrix_image_ssp_update_frame);
   	
//cancle timer
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_pen_down_hdlr
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_pen_down_hdlr
 * PARAMETERS
 *  pos: current pen down position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_pen_down_hdlr(mmi_pen_point_struct pos)
{
    kal_get_time(&g_gui_dialer_pad_matrix_image_pen_down_time);
	g_gui_dialer_pad_matrix_image_pen_down_y = (S32)pos.y;
   //not in dialer region
   
   //in dialer region
    switch(g_gui_dialer_pad_matrix_image_state)
    {
      case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS:
	  	g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FOCUS;
        break;
	  case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FREE_RUN:
	  {
	  	
		gui_sync_matrix_image_picker_final();
		gui_dialer_pad_show_dialer_with_image();
		
		gui_cancel_timer(gui_dialer_pad_matrix_image_ssp_update_frame);
	  	g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD;
	  }	
	}

}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_pen_move_hdlr
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_pen_move_hdlr
 * PARAMETERS
 *  pos: current pen move position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_pen_move_hdlr(mmi_pen_point_struct pos)
{
    g_gui_dialer_pad_matrix_image_pen_move_y = (S32)pos.y;
	
	switch(g_gui_dialer_pad_matrix_image_state)
    {
      case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS:
	  	//do nothing
        break;
      case GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_FOCUS:
	  	//goto hold state when pen down offset > threshold
	  	{
           S32 delta_pos_y = g_gui_dialer_pad_matrix_image_pen_move_y - g_gui_dialer_pad_matrix_image_pen_down_y;
		   if(delta_pos_y  < 0)
		   {
				delta_pos_y = -delta_pos_y;
		   }

		   if(delta_pos_y > g_gui_dialer_pad_transform.hold_threshold)
		   {
				g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD;	
              	gui_dialer_pad_matrix_image_pen_move_hdlr(pos);
                return;
		   } 
		}
	  	
		break;
	  case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD:
	  	g_gui_dialer_pad_transform.hilited_col = -1;
	    gui_start_timer((g_picker_interval), gui_dialer_pad_matrix_image_ssp_update_frame); 
        //start timer 
		break;
		
	}
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_pen_up_hdlr
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_pen_up_hdlr
 * PARAMETERS
 *  pos: current pen up position
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_pen_up_hdlr(mmi_pen_point_struct pos)
{
   g_gui_dialer_pad_transform.hilited_col = -1;
	switch(g_gui_dialer_pad_matrix_image_state)
    {
      case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS:
	  	//do nothing
        break;
      case GUI_LIST_SMOOTH_SCROLLING_BY_PEN_STATE_FOCUS:
	  	//goto hold state when pen down offset > threshold
	  	
	  	
		break;
	  case GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD:	  	
		{
				U32 pen_up_time, pen_down_to_up_delta_time; 
				S32 pen_down_to_up_delta_y, pos_delta = 0;
				
				kal_get_time(&pen_up_time);
				pen_down_to_up_delta_y = (S32)pos.y - g_gui_dialer_pad_matrix_image_pen_down_y;
                pos_delta = g_gui_dialer_pad_transform.y_pos_delta * pen_down_to_up_delta_y; 
                g_gui_dialer_pad_transform.scroll_momentum = pen_down_to_up_delta_y;

				if(g_gui_dialer_pad_transform.scroll_momentum < 0)
				{
					pos_delta = -pos_delta;
				}
				
				pen_down_to_up_delta_time = kal_ticks_to_milli_secs(pen_up_time - g_gui_dialer_pad_matrix_image_pen_down_time);
				if(pen_down_to_up_delta_time < GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_THRESHOLD_TIME &&
				   pos_delta > g_gui_dialer_pad_transform.move_threshold)
				{
					g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FREE_RUN;
				    g_gui_dialer_pad_transform.scroll_momentum = g_gui_dialer_pad_transform.scroll_momentum * 
						g_gui_dialer_pad_transform.scroll_sensitivity;
					gui_start_timer((g_picker_interval), gui_dialer_pad_matrix_image_ssp_update_frame);

				    return;
				}		
			}

        //start timer 
		break;
		
	}
	
	gui_sync_matrix_image_picker_final();
	gui_dialer_pad_show_dialer_with_image();
	
	gui_cancel_timer(gui_dialer_pad_matrix_image_ssp_update_frame);
	
	g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS;
}


//key
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_goto_previous_row
 * DESCRIPTION
 *  goto previous row 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

void gui_dialer_pad_matrix_image_goto_previous_row(void)
{
   S32 h = g_dialer_pad_cntx.original_bound.height;
   S16* hilited_row = &g_gui_dialer_pad_transform.hilited_row;

   if(*hilited_row - 1 < 0)
   {
		*hilited_row = *hilited_row - 1 + GUI_DIALER_PAD_IMAGE_MATRIX_ROWS;
   }
   else
   {
	   *hilited_row = *hilited_row - 1;
   }
   g_gui_dialer_pad_transform.hilited_col = -1;

   g_gui_dialer_pad_transform.y_offset[*hilited_row] = h;//g_dialer_pad_cntx.original_bound.height/2.0;
   g_gui_dialer_pad_transform.row_top[*hilited_row] = h/2;

   gui_dialer_pad_matrix_image_sync_offset_down2up(*hilited_row, GUI_DIALER_PAD_IMAGE_MATRIX_ROWS);

   //redraw
   gui_dialer_pad_show_dialer_with_image();
}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_goto_next_row
 * DESCRIPTION
 *  goto next row 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_matrix_image_goto_next_row(void)
{
	S32 h = g_dialer_pad_cntx.original_bound.height;
	S16* hilited_row = &g_gui_dialer_pad_transform.hilited_row;
	
	if(*hilited_row + 1 >= GUI_DIALER_PAD_IMAGE_MATRIX_ROWS)
	{
		 *hilited_row = *hilited_row + 1 - GUI_DIALER_PAD_IMAGE_MATRIX_ROWS;
	}
	else
	{
		*hilited_row = *hilited_row + 1;
	}
	g_gui_dialer_pad_transform.hilited_col = -1;
	
	g_gui_dialer_pad_transform.y_offset[*hilited_row] = h;//g_dialer_pad_cntx.original_bound.height/2.0;
	g_gui_dialer_pad_transform.row_top[*hilited_row] = h/2;
	
	gui_dialer_pad_matrix_image_sync_offset_down2up(*hilited_row, GUI_DIALER_PAD_IMAGE_MATRIX_ROWS);
	
	//redraw
	gui_dialer_pad_show_dialer_with_image();

}


/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_init
 * DESCRIPTION
 *  gui_dialer_pad_matrix_image_init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_dialer_pad_matrix_image_init(void)
{
  float scale = 0.0f;
  float ih = 0;//
  S32 igap = 0;
  S32 h = g_dialer_pad_cntx.original_bound.height;
  gui_bound bound;

  g_gui_dialer_pad_transform.up_scroll_sensitivity= GUI_DIALER_PAD_IMAGE_MATRIX_UP_SCROLL_SENSITIVITY;
  g_gui_dialer_pad_transform.down_scroll_sensitivity = GUI_DIALER_PAD_IMAGE_MATRIX_DOWN_SCROLL_SENSITIVITY;

  g_gui_dialer_pad_transform.move_threshold = GUI_DIALER_PAD_IMAGE_MATRIX_MOVE_THRESHOLD;
  g_gui_dialer_pad_transform.hold_threshold = GUI_DIALER_PAD_IMAGE_MATRIX_HOLD_THRESHOLD;
  g_gui_dialer_pad_transform.y_pos_delta = GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_POS_DELTA;
  g_gui_dialer_pad_transform.scroll_sensitivity = GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_SENSITIVITY;
  g_gui_dialer_pad_transform.scroll_coefficient = GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_COEFFICIENT;
//y_offset ?bottom
  //sync hilited row
   g_gui_dialer_pad_matrix_image_state = GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS;
   g_gui_dialer_pad_transform.hilited_col = -1;
   g_gui_dialer_pad_transform.hilited_row= 2;

   g_gui_dialer_pad_transform.y_offset[2] = h;//g_dialer_pad_cntx.original_bound.height/2.0;
   g_gui_dialer_pad_transform.row_top[2] = h/2;

   gui_dialer_pad_matrix_image_sync_offset_down2up(2, GUI_DIALER_PAD_IMAGE_MATRIX_ROWS);


    //set bound
    bound.x = g_dialer_pad_cntx.original_bound.x;
    bound.y = g_dialer_pad_cntx.original_bound.y + g_dialer_pad_cntx.original_bound.height - GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
    bound.width = g_dialer_pad_cntx.original_bound.width;
    bound.height = GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H;
    gui_dialer_pad_set_effective_bound(bound);
    
    //register hdlr
#ifdef __MMI_TOUCH_SCREEN__
    g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr = gui_dialer_pad_matrix_image_pen_down_hdlr;
    g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr = gui_dialer_pad_matrix_image_pen_move_hdlr;
    g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr = gui_dialer_pad_matrix_image_pen_up_hdlr;
#endif
    g_dialer_pad_cntx.dialer_hdlr.show_func = gui_dialer_pad_matrix_image_show;
    g_dialer_pad_cntx.dialer_hdlr.goto_previous = gui_dialer_pad_matrix_image_goto_previous_row;
    g_dialer_pad_cntx.dialer_hdlr.goto_next = gui_dialer_pad_matrix_image_goto_next_row;
    g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index = gui_get_matrix_image_picker_hilited;
}

#endif/* defined(GUI_DIALER_PAD_MATRIX_DIALER)*/

#ifdef GUI_PICKER_CIRCUAL_ROLL_DIALER

S32 distance_slide_x;
U8 display_matrix_index;
U8 draw_wallpaper_count;
U8 display_style;

static void gui_cirtual_roll_get_number_data(U8 matrix_index, U8 index, cirtual_struct *number_data)
{
    float angle, rate, matrix_index_2, diff_index;
    S32 distance_x;
	U8 rate_int;
	S16 real_index;

	if(display_style == 1)
	{

		rate = distance_slide_x/CIRTUAL_SLIDE_THREOD;

		rate_int = (U8)(GUI_ABS(rate));
	
		matrix_index_2 = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 ;

		if(rate <= 0)
		{
			real_index = matrix_index_2 + rate_int;
			if(index == real_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + (GUI_ABS(rate) - rate_int) * 37;
			}
			else if(index == (real_index + 1) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + 60 - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 37;
			}
			else if(index == (real_index + 2) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + 60 + 60 - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - 24 + (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index + 3) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + 60 + 60 + 60 - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index - 1) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - 60 - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index - 2) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - 60 - 60 - (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - 24 + (GUI_ABS(rate) - rate_int) * 24;
			}
			else
			{
				number_data->pos_x = -100;
				number_data->pos_y = -100;
			}
		}
		else
		{
			real_index = matrix_index_2 - rate_int;
			if(index == real_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + (GUI_ABS(rate) - rate_int) * 37;
			}
			else if(index == (real_index + 1) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + 60 + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index + 2) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X + 60 + 60 + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - 24 + (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index - 3) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - 60 - 60 - 60 + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 24;
			}
			else if(index == (real_index - 1) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - 60 + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - (GUI_ABS(rate) - rate_int) * 37;
			}
			else if(index == (real_index - 2) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3))
			{
				number_data->pos_x = CENTER_X - 60 - 60 + (GUI_ABS(rate) - rate_int) * 60;
				number_data->pos_y = CENTER_Y + 37 - 24 + (GUI_ABS(rate) - rate_int) * 24;
			}
			else
			{
				number_data->pos_x = -100;
				number_data->pos_y = -100;
			}
		}
	}
	else
	{
		rate = distance_slide_x/CIRTUAL_SLIDE_THREOD;

    	rate_int = (U8)(GUI_ABS(rate));
	
		matrix_index_2 = display_matrix_index - rate ;

		if(matrix_index_2 < 0)
		{
			matrix_index_2 = matrix_index_2 + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
		}
		else if(matrix_index_2 >= (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3) )
		{
			matrix_index_2 = matrix_index_2 - (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
		}

    	diff_index = index - matrix_index_2;

		if(diff_index <= -9)
		{
			diff_index = diff_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3) ;
		}
		else if(diff_index >= 9)
		{
			diff_index = diff_index - (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3) ;
		}
		

    	number_data->pos_x = CENTER_X_CIRTUAL + sin(diff_index * CIRCUTL_ANGLE * CIRCUTL_PI / 180.0f)*CIRCUTL_SEMIMAJOR;

    	number_data->pos_y = CENTER_Y_CIRTUAL - CIRCUTL_SEMIMINOR + cos(diff_index * CIRCUTL_ANGLE * CIRCUTL_PI / 180.0f)*CIRCUTL_SEMIMINOR;
	}
	
}


static void gui_cirtual_roll_draw_number_image(U8 matrix_index, U8 image_index,MMI_BOOL is_pressed,cirtual_struct *number_data)
{
	U8 rate_int, matrix_index_2;
	U16 num_0_img_id, num_0_sel_img_id;
	S32 num_width, num_height, num_sel_width,num_sel_height;
	U16 image_index_num, image_index_sel_num;

	if(number_data->pos_y == -100 && number_data->pos_x == -100)
		return;

	num_0_sel_img_id = IMG_ID_DIALER_PAD_SEL_0;

	num_0_img_id = IMG_ID_DIALER_PAD_0;

	if(image_index >= 0 && image_index <=8)
	{
		image_index_num = num_0_img_id + image_index + 1;
		image_index_sel_num = num_0_sel_img_id + image_index + 1;
	}
	else if(image_index == 9)
	{
		image_index_num = IMG_ID_DIALER_PAD_11;
		image_index_sel_num = IMG_ID_DIALER_PAD_SEL_11;
	}
	else if(image_index == 10)
	{
		image_index_num = IMG_ID_DIALER_PAD_0;
		image_index_sel_num = IMG_ID_DIALER_PAD_SEL_0;
	}
	else if(image_index == 11)
	{
		image_index_num = IMG_ID_DIALER_PAD_10;
		image_index_sel_num = IMG_ID_DIALER_PAD_SEL_10;
	}
	
	
	gdi_image_get_dimension_id(num_0_img_id, &num_width, &num_height);
    gdi_image_get_dimension_id(num_0_sel_img_id, &num_sel_width, &num_sel_height);

    //if(number_data->pos_x < CENTER_X + CIRTUAL_SLIDE_THREOD/4 && number_data->pos_x > CENTER_X - CIRTUAL_SLIDE_THREOD/4) 
    //{
    	//gdi_image_draw_resized_id(number_data->pos_x, number_data->pos_y, image_index_sel_num);
    //}
	//else
	{
		gdi_image_draw_id(number_data->pos_x, number_data->pos_y, image_index_num);
	}
	
}

static void gui_cirtual_roll_picker_show(void)
{
	
	U8 i;
	gdi_handle wallpaper_layer_handle;

	/*Draw wallpaper*/
	if(draw_wallpaper_count == 0)
	{
		wallpaper_layer_handle = dm_get_layer_handle(0);
		gdi_layer_push_and_set_active(wallpaper_layer_handle);
		//gdi_layer_clear(GDI_COLOR_TRANSPARENT);
		gdi_image_draw_resized_id(0,20,LCD_WIDTH, LCD_HEIGHT, IMG_ID_DIALER_PAD_BG);
		gdi_layer_pop_and_restore_active();
		draw_wallpaper_count++;
	}
	
	for(i = 0; i < (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3); i++)
    {
        cirtual_struct number_data;
        gui_cirtual_roll_get_number_data(g_dialer_pad_cntx.matrix_index, i, &number_data);
        gui_cirtual_roll_draw_number_image(g_dialer_pad_cntx.matrix_index, i, MMI_FALSE, &number_data);
    }
}

static void gui_cirtual_roll_picker_pen_move_hdlr(mmi_pen_point_struct pos)
{
#ifdef __MMI_TOUCH_SCREEN__
	S16 x_diff = pos.x - g_dialer_pad_cntx.pen_down_pos.x, y_diff = pos.y - g_dialer_pad_cntx.pen_down_pos.y;
	if (GUI_ABS(x_diff) > GUI_DIALER_PAD_PEN_MOVE_SWITCH_THRESHOLD || 
		GUI_ABS(y_diff) > GUI_DIALER_PAD_PEN_MOVE_SWITCH_THRESHOLD)
	{
		if(display_style == 1)
		{
			distance_slide_x = x_diff/3;
		}
		else
		{
			distance_slide_x = x_diff/2;
		}
		gui_dialer_pad_show();
	}
#endif
}


static void gui_circual_roll_picker_pen_down_hdlr(mmi_pen_point_struct pos)
{
	if (pos.x >= g_dialer_pad_cntx.effective_bound.x && pos.x <= (g_dialer_pad_cntx.effective_bound.x + g_dialer_pad_cntx.effective_bound.width) &&
        pos.y >= g_dialer_pad_cntx.effective_bound.y && pos.y <= (g_dialer_pad_cntx.effective_bound.y + g_dialer_pad_cntx.effective_bound.height))
    {
    	distance_slide_x = 0;
	}
}


static void gui_circual_roll_delay_timer_callback(void)
{
	S32 diff_index, slide_dis;
       
    diff_index = distance_slide_x / CIRTUAL_SLIDE_THREOD;

    slide_dis = distance_slide_x - diff_index*CIRTUAL_SLIDE_THREOD;
	
    if(GUI_ABS(slide_dis) < CIRTUAL_SLIDE_THREOD/2)
    {
    	if(distance_slide_x < 0)
    	{
    		distance_slide_x = distance_slide_x + ANIMATION_DIS;
			if(distance_slide_x >= 0)
			{
				g_dialer_pad_cntx.matrix_index = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index;
				g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
				distance_slide_x = 0;
				display_matrix_index = g_dialer_pad_cntx.matrix_index;
				gui_dialer_pad_show();
			}
			else
			{
				gui_dialer_pad_show();
				gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_delay_timer_callback);
			}
    	}
		else
		{
			distance_slide_x = distance_slide_x - ANIMATION_DIS;
			if(distance_slide_x <= 0)
			{
				g_dialer_pad_cntx.matrix_index = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index;
				g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
				distance_slide_x = 0;
				display_matrix_index = g_dialer_pad_cntx.matrix_index;
				gui_dialer_pad_show();
			}
			else
			{
				gui_dialer_pad_show();
				gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_delay_timer_callback);
			}
		}        
    }
    else
    {
    	if(distance_slide_x < 0)
    	{
    		distance_slide_x = distance_slide_x - ANIMATION_DIS;
			if(GUI_ABS(distance_slide_x) >= CIRTUAL_SLIDE_THREOD)
			{
				g_dialer_pad_cntx.matrix_index = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index + 1;
				g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
				distance_slide_x = 0;
				display_matrix_index = g_dialer_pad_cntx.matrix_index;
				gui_dialer_pad_show();
			}
			else
			{
				gui_dialer_pad_show();
				gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_delay_timer_callback);
			}
    	}
		else
		{
			distance_slide_x = distance_slide_x + ANIMATION_DIS;
			if(GUI_ABS(distance_slide_x) >= CIRTUAL_SLIDE_THREOD)
			{
				g_dialer_pad_cntx.matrix_index = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index - 1;
				g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
				distance_slide_x = 0;
				display_matrix_index = g_dialer_pad_cntx.matrix_index;
				gui_dialer_pad_show();
			}
			else
			{
				gui_dialer_pad_show();
				gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_delay_timer_callback);
			}
		} 
    }
}

static void gui_picker_slide_to_index()
{
    S32 diff_index, slide_dis;
       
    diff_index = distance_slide_x / CIRTUAL_SLIDE_THREOD;

    slide_dis = distance_slide_x - diff_index*CIRTUAL_SLIDE_THREOD;

    if(GUI_ABS(slide_dis) < 40/2)
    {
        g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index;
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
        
    }
    else
    {
        if(distance_slide_x < 0)
            g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index + 1;
        else
            g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - diff_index - 1;

		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
    }

    distance_slide_x = 0;

    gui_dialer_pad_show();
}

static void gui_circual_roll_picker_pen_up_hdlr(mmi_pen_point_struct pos)
{
#ifdef __MMI_TOUCH_SCREEN__
	if (g_dialer_pad_cntx.pen_status == GUI_DIALER_PAD_PEN_STATUS_NONE &&
		g_dialer_pad_cntx.pen_down_pos.y <= 195)
	{
		gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_delay_timer_callback);
		//gui_picker_slide_to_index();
	}
#endif
}


static MMI_BOOL gui_dialer_pad_check_is_touch(cirtual_struct *number_data, S32 image_width, S32 image_height)
{
#ifdef __MMI_TOUCH_SCREEN__
	S32 x1, y1, x2, y2;
	x1 = number_data->pos_x;
	x2 = number_data->pos_x + image_width;
	y1 = number_data->pos_y;
	y2 = number_data->pos_y + image_height;

	if(g_dialer_pad_cntx.pen_down_pos.x >= x1 &&
	   g_dialer_pad_cntx.pen_down_pos.x <= x2-1 &&
	   g_dialer_pad_cntx.pen_down_pos.y >= y1 &&
	   g_dialer_pad_cntx.pen_down_pos.y <= y2-1)
	{
		return MMI_TRUE;
	}
	else
	{
		return MMI_FALSE;
	}
#endif
}



static S16 gui_circual_roll_picker_hilited(void)
{
#ifdef __MMI_TOUCH_SCREEN__
	//gui_picker_dialer_struct *dialer_picker = (gui_picker_dialer_struct*)g_picker_cntx.user_data;
	//return dialer_picker->matrix_index;
	S16 matrix_index,matrix_index1, i;
	S32 image_width, image_height;
	cirtual_struct number_data;
	MMI_BOOL found = MMI_FALSE;
	matrix_index1 = display_matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8;

	gdi_image_get_dimension_id(IMG_ID_DIALER_PAD_0, &image_width, &image_height);
	
	if(display_style == 1)
	{
		for(i = 0; i < 5; i++)
		{
			matrix_index = (matrix_index1 - 2 + i) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
			gui_cirtual_roll_get_number_data(g_dialer_pad_cntx.matrix_index, matrix_index, &number_data);
			if(gui_dialer_pad_check_is_touch(&number_data, image_width, image_height) == MMI_TRUE)
			{
				break;
			}
		}

		if(i == 5)
		{
			matrix_index = GUI_DIALER_PAD_INVALID_INDEX;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
	}
	else
	{
		
		for(i = 0; i < 3; i++)
		{
			matrix_index = (matrix_index1 - 1 + i) % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
			gui_cirtual_roll_get_number_data(g_dialer_pad_cntx.matrix_index, matrix_index, &number_data);
			if(gui_dialer_pad_check_is_touch(&number_data, image_width, image_height) == MMI_TRUE)
			{
				found = MMI_TRUE;
				break;
			}
		}
		
		if(found == MMI_FALSE)
		{
			matrix_index = GUI_DIALER_PAD_INVALID_INDEX;
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
/* under construction !*/
/* under construction !*/
		#endif
	}
	
	return matrix_index;
#endif
}

static void gui_circual_roll_key_delay_timer_callback(void)
{
	distance_slide_x = distance_slide_x - ANIMATION_DIS*2;
	
	if(distance_slide_x <= 0)
	{
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 - 1;
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
		distance_slide_x = 0;
		gui_dialer_pad_show();
	}
	else
	{
		gui_dialer_pad_show();
		gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_key_delay_timer_callback);
	}
}

void gui_circual_roll_picker_goto_previous_row(void)
{
	//distance_slide_x = CIRTUAL_SLIDE_THREOD ;
	
	//gui_circual_roll_key_delay_timer_callback();
}

static void gui_circual_roll_key_next_delay_timer_callback(void)
{
	distance_slide_x = distance_slide_x + ANIMATION_DIS*2;
	
	if(distance_slide_x >= CIRTUAL_SLIDE_THREOD)
	{
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index + (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3)*8 + 1;
		g_dialer_pad_cntx.matrix_index = g_dialer_pad_cntx.matrix_index % (GUI_DIALER_PAD_MATRIX_MAX_NUM - 3);
		distance_slide_x = 0;
		gui_dialer_pad_show();
	}
	else
	{
		gui_dialer_pad_show();
		gui_start_timer(CIRCUAL_ANIMATE_TIME, gui_circual_roll_key_next_delay_timer_callback);
	}
}

void gui_circual_roll_picker_goto_next_row(void)
{
	//distance_slide_x = 0;
	
	//gui_circual_roll_key_next_delay_timer_callback();
}


static void gui_circual_roll_picker_init(void)
{
	gui_bound bound;
	gdi_handle wallpaper_layer_handle;
	
	distance_slide_x = 0;
	draw_wallpaper_count = 0;
	display_matrix_index = g_dialer_pad_cntx.matrix_index;
	display_style = 0;

	//set bound
    bound.x = 0; //g_picker_cntx.original_bound.x;
    bound.y = 100; //g_picker_cntx.original_bound.y + g_picker_cntx.original_bound.height;
    bound.width = LCD_WIDTH; //g_picker_cntx.original_bound.width;
    bound.height = 106 ; //g_picker_cntx.original_bound.height;
    gui_dialer_pad_set_effective_bound(bound);

	//register hdlr
#ifdef __MMI_TOUCH_SCREEN__
    g_dialer_pad_cntx.dialer_hdlr.pen_down_hdlr = gui_circual_roll_picker_pen_down_hdlr;
    g_dialer_pad_cntx.dialer_hdlr.pen_move_hdlr = gui_cirtual_roll_picker_pen_move_hdlr;
    g_dialer_pad_cntx.dialer_hdlr.pen_up_hdlr = gui_circual_roll_picker_pen_up_hdlr;
#endif
    g_dialer_pad_cntx.dialer_hdlr.show_func = gui_cirtual_roll_picker_show;
    g_dialer_pad_cntx.dialer_hdlr.goto_previous = gui_circual_roll_picker_goto_previous_row;
    g_dialer_pad_cntx.dialer_hdlr.goto_next = gui_circual_roll_picker_goto_next_row;
    g_dialer_pad_cntx.dialer_hdlr.get_highlight_matrix_index = gui_circual_roll_picker_hilited;

}

#endif
#endif  //__MMI_UI_DIALER_PAD__

