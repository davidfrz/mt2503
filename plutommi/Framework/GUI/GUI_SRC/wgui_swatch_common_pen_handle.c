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
 *  wgui_swatch_common_pen_handle.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  swatch common pen handle
 * 
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 04 2016 ziyao.xiong
 * removed!
 * Fix the build error.
 *
 * 03 30 2015 anne.xu
 * removed!
 * Wearable asterV2 UI enhance check in.
 *
 * 03 30 2015 ziyao.xiong
 * removed!
 * For alarm.
 *
 * 03 30 2015 ziyao.xiong
 * removed!
 * Aster new style change for alarm & calendar.
 *
 * 07 02 2014 anne.xu
 * removed!
 * .Wearable Device common pen move handler bug fixed check in
 *
 * 06 13 2014 anne.xu
 * removed!
 * .Wearable Device alarm screen shake
 *
 * 05 29 2014 anne.xu
 * removed!
 * .Wearable Device common pen handler change check in
 *
 * 05 27 2014 anne.xu
 * removed!
 * .Wearable Device alarm long tap action change check in
 *
 * 05 22 2014 anne.xu
 * removed!
 * .Wearable Device No LCD build error check in
 *
 * 04 24 2014 anne.xu
 * removed!
 * .common pen move code change check in
 *
 * 04 16 2014 ziyao.xiong
 * removed!
 * modify for wearable off case.
 *
 * 04 14 2014 ziyao.xiong
 * removed!
 * [wearable device]check in WEARv1_DEV about Calendar.
 *
 * 
 * 
 *
 *******************************************************************************/

/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "mmi_features.h"
	 
#ifdef __MMI_WEARABLE_DEVICE__
#include "globalresdef.h"
#include "gdi_include.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "gui_effect_oem.h"
#include "Wgui_categories_util.h"
#include "MiscFunctions.h"
#include "app_datetime.h"
#include "mmi_common_app_trc.h"
#include "mmi_trc_int.h"
#include "mmi_frm_input_gprot.h"
#include "idlememcfg.h"
#include "gpiosrvgprot.h"
#include "wgui_swatch_common_pen_handle.h"
//#include "mmi_rp_app_idle_swatch_def.h"

#if defined(__MMI_WEARABLE_DEVICE__)
#ifndef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
#define __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
#endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/

#ifdef __MMI_WEARABLE_DEVICE_ALARM__
#ifndef __ASTER_NEW_STYLE_CHANGE_FOR_ALARM__
#define __ASTER_NEW_STYLE_CHANGE_FOR_ALARM__
#endif/*__ASTER_NEW_STYLE_CHANGE_FOR_ALARM__*/
#endif/*__MMI_WEARABLE_DEVICE_ALARM__*/

#endif/*__MMI_WEARABLE_DEVICE__*/

#ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__

#ifdef __MMI_WEARABLE_DEVICE__
#define MMI_SWATCH_BACK_MOVE_THRESHOLD_X  (LCD_WIDTH/3)
static MMI_BOOL g_swatch_is_pen_down = MMI_FALSE;
static mmi_pen_point_struct g_swatch_pen_down_pos = {0};
#endif  //__MMI_WEARABLE_DEVICE__

#endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/

#ifdef __ASTER_NEW_STYLE_CHANGE_FOR_ALARM__
extern MMI_BOOL g_is_add_alarm_screen_pressed;
#endif/*__ASTER_NEW_STYLE_CHANGE_FOR_ALARM__*/

static swatch_common_pen_handle_struct swatch_pen_common_handle;

mmi_ret mmi_swath_common_pen_move_right_hdlr(mmi_event_struct *evt)
{
	if(evt->evt_id == EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT && swatch_pen_common_handle.pen_move_direction == MMI_SWATCH_MOVE_DIRECTION_V)
	{
		return MMI_RET_DONT_CARE;
	}
	return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_common_abs
 * DESCRIPTION
 *  
 * PARAMETERS
 *  x
 *  
 * RETURNS
 *  S32
 *****************************************************************************/

static S32 mmi_swatch_common_abs(S32 x)
{
	if(x > 0)
	{
		return x;   
	}
	else
	{
		return -x;
	}
}

static void mmi_swatch_common_cell_change_index(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 old_highlight_index;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	old_highlight_index = swatch_pen_common_handle.cell_info->highlight_index;

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_cell_change_index before change,highlight_index=%d\n", swatch_pen_common_handle.cell_info->highlight_index);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_cell_change_index before change,pen_move_offset=%d\n", swatch_pen_common_handle.pen_move_offset);
	swatch_pen_common_handle.cell_info->highlight_index -=  swatch_pen_common_handle.pen_move_offset / (swatch_pen_common_handle.cell_info->cell_height + swatch_pen_common_handle.cell_info->cell_distance);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_cell_change_index after change,highlight_index=%d\n", swatch_pen_common_handle.cell_info->highlight_index);

	if (old_highlight_index != swatch_pen_common_handle.cell_info->highlight_index)
	{
		SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_cell_change_index has changed\n");
		swatch_pen_common_handle.cell_info->change_index_rule(swatch_pen_common_handle.pen_move_offset);
	}
		

}

static void mmi_swatch_common_swap_animation(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 distance;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_swap_animation start_anim_pos=%d\n", swatch_pen_common_handle.start_anim_pos);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_swap_animation end_anim_pos=%d\n", swatch_pen_common_handle.end_anim_pos);
	
	if(swatch_pen_common_handle.start_anim_pos >= 0)
	{
		if(swatch_pen_common_handle.start_anim_pos > swatch_pen_common_handle.end_anim_pos)
		{
			swatch_pen_common_handle.pen_move_offset -= SMART_WATCH_COMMON_PEN_SWAP_DIS;
			swatch_pen_common_handle.start_anim_pos = swatch_pen_common_handle.pen_move_offset;
			if(swatch_pen_common_handle.pen_move_offset <= swatch_pen_common_handle.end_anim_pos)
			{
				gui_cancel_timer(mmi_swatch_common_swap_animation);
				swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.end_anim_pos;
				swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				mmi_swatch_common_cell_change_index();
				swatch_pen_common_handle.pen_move_offset = 0;
			}
			else
			{
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
			}
		}
		else
		{
			swatch_pen_common_handle.pen_move_offset += SMART_WATCH_COMMON_PEN_SWAP_DIS;
			swatch_pen_common_handle.start_anim_pos = swatch_pen_common_handle.pen_move_offset;
			if(swatch_pen_common_handle.pen_move_offset >= swatch_pen_common_handle.end_anim_pos)
			{
				gui_cancel_timer(mmi_swatch_common_swap_animation);
				swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.end_anim_pos;
				swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);	
				mmi_swatch_common_cell_change_index();			
				swatch_pen_common_handle.pen_move_offset = 0;
			}
			else
			{
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
			}
		}
	}
	else
	{
		if(swatch_pen_common_handle.start_anim_pos > swatch_pen_common_handle.end_anim_pos)
		{
			swatch_pen_common_handle.pen_move_offset -= SMART_WATCH_COMMON_PEN_SWAP_DIS;
			swatch_pen_common_handle.start_anim_pos = swatch_pen_common_handle.pen_move_offset;
			if(swatch_pen_common_handle.pen_move_offset <= swatch_pen_common_handle.end_anim_pos)
			{
				gui_cancel_timer(mmi_swatch_common_swap_animation);
				swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.end_anim_pos;
				swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset); 
				mmi_swatch_common_cell_change_index(); 
				swatch_pen_common_handle.pen_move_offset = 0;
			}
			else
			{
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
			}
		}
		else
		{
			swatch_pen_common_handle.pen_move_offset += SMART_WATCH_COMMON_PEN_SWAP_DIS;
			swatch_pen_common_handle.start_anim_pos = swatch_pen_common_handle.pen_move_offset;
			if(swatch_pen_common_handle.pen_move_offset >= swatch_pen_common_handle.end_anim_pos)
			{
				gui_cancel_timer(mmi_swatch_common_swap_animation);
				swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.end_anim_pos;
				swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				mmi_swatch_common_cell_change_index();
				swatch_pen_common_handle.pen_move_offset = 0;
			}
			else
			{
				swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
				gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
			}
		}

		SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_swap_animation out\n");
	}
	
}

static MMI_BOOL mmi_swatch_is_in_valid_pen_move_area(mmi_pen_point_struct pos)
{
	if (pos.x >= swatch_pen_common_handle.pen_pos_start.x && pos.x <= swatch_pen_common_handle.pen_pos_end.x\
		&& pos.y >= swatch_pen_common_handle.pen_pos_start.y && pos.y <= swatch_pen_common_handle.pen_pos_end.y)
		return MMI_TRUE;
	
	return MMI_FALSE;
}

static void mmi_swatch_common_change_pen_pos_to_valid(mmi_pen_point_struct *pos)
{

	if (pos->x < swatch_pen_common_handle.pen_pos_start.x)
	{
		pos->x = swatch_pen_common_handle.pen_pos_start.x;
	}
	else if (pos->x > swatch_pen_common_handle.pen_pos_end.x)
	{
		pos->x = swatch_pen_common_handle.pen_pos_end.x;
	}

	if (pos->y < swatch_pen_common_handle.pen_pos_start.y)
	{
		pos->y = swatch_pen_common_handle.pen_pos_start.y;
	}
	else if (pos->y > swatch_pen_common_handle.pen_pos_end.y)
	{
		pos->y = swatch_pen_common_handle.pen_pos_end.y;
	}
	

}

static void mmi_swatch_common_pen_down_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 
  #ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
	#ifdef __MMI_WEARABLE_DEVICE__
	    g_swatch_is_pen_down = MMI_TRUE;
	    g_swatch_pen_down_pos.x = pos.x;
	    g_swatch_pen_down_pos.y = pos.y;
	#endif  //__MMI_WEARABLE_DEVICE__
  #endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/

	swatch_pen_common_handle.is_in_valid_pen_move_area = MMI_TRUE;
	swatch_pen_common_handle.is_valid_pen_move = MMI_TRUE;

	if (MMI_FALSE == mmi_swatch_is_in_valid_pen_move_area(pos))
	{
		swatch_pen_common_handle.is_in_valid_pen_move_area = MMI_FALSE;
		SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_down_hdlr not in valid pen move area\n");
	//	return;
	}

	#ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
	    //pen down handle;
		if(swatch_pen_common_handle.cell_info->pen_down_hdlr)
		{
			swatch_pen_common_handle.cell_info->pen_down_hdlr(pos);
		}	
	#endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/	
	
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_down_hdlr in, pos.y=%d\n", pos.y);
	swatch_pen_common_handle.pen_down_pos = pos;
	swatch_pen_common_handle.pen_move_direction = MMI_SWATCH_MOVE_DIRECTION_NONE;
	
	if(swatch_pen_common_handle.pen_move_offset != 0)
	{
		gui_cancel_timer(mmi_swatch_common_swap_animation);
		swatch_pen_common_handle.temp_offset= swatch_pen_common_handle.pen_move_offset;
		swatch_pen_common_handle.pen_move_offset = 0;
	}
	else
	{
		swatch_pen_common_handle.temp_offset = 0;
	}
	

	swatch_pen_common_handle.pen_click = MMI_TRUE;
	

	swatch_pen_common_handle.prevpen_move_offset = swatch_pen_common_handle.pen_down_pos.y;

	//swatch_pen_common_handle.cell_info->disable_array_image = MMI_TRUE;
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_down_hdlr out");

}

static void mmi_swatch_common_pen_move_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	S32 delta_x = pos.x - swatch_pen_common_handle.pen_down_pos.x;
	S32 delta_y = pos.y - swatch_pen_common_handle.pen_down_pos.y;
	U32 abs_delta_x = delta_x > 0 ?delta_x:(-delta_x);
	U32 abs_delta_y = delta_y > 0 ?delta_y:(-delta_y);
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 
	if (swatch_pen_common_handle.pen_move_direction == MMI_SWATCH_MOVE_DIRECTION_NONE)
	{
		if (abs_delta_x > abs_delta_y)
		{
			swatch_pen_common_handle.pen_move_direction = MMI_SWATCH_MOVE_DIRECTION_H;
		}
		else
		{
			swatch_pen_common_handle.pen_move_direction = MMI_SWATCH_MOVE_DIRECTION_V;
		}
	}

    #ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
	    //底部无效区域只响应move，清除highlight;
		if(swatch_pen_common_handle.cell_info->pen_move_hdlr)
		{
			swatch_pen_common_handle.cell_info->pen_move_hdlr(swatch_pen_common_handle.pen_down_pos, pos);
		}	
	#endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/	
	if (swatch_pen_common_handle.pen_move_direction == MMI_SWATCH_MOVE_DIRECTION_H)
		return;

	if (MMI_FALSE == swatch_pen_common_handle.is_in_valid_pen_move_area)
	{
		SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr valid out\n");
		return;
	}

	if (MMI_FALSE == mmi_swatch_is_in_valid_pen_move_area(pos))
		mmi_swatch_common_change_pen_pos_to_valid(&pos);
	
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr in, pos.y=%d\n", pos.y);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr in, pre_move_offset=%d\n", swatch_pen_common_handle.prevpen_move_offset);

	swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.pen_move_offset + pos.y - swatch_pen_common_handle.prevpen_move_offset;

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr in, pen_move_offset=%d\n", swatch_pen_common_handle.pen_move_offset);

	if(swatch_pen_common_handle.temp_offset != 0)
	{
		swatch_pen_common_handle.pen_move_offset += swatch_pen_common_handle.temp_offset;
		swatch_pen_common_handle.temp_offset = 0;
	}
	swatch_pen_common_handle.prevpen_move_offset = pos.y;

	//if (mmi_swatch_common_abs(swatch_pen_common_handle.pen_move_offset) > SMART_WATCH_COMMON_PEN_CLICK_THRESHOLD)
	{
		if (swatch_pen_common_handle.cell_info->check_is_valid_pen_move && MMI_FALSE == swatch_pen_common_handle.cell_info->check_is_valid_pen_move(swatch_pen_common_handle.pen_move_offset))
		{
			swatch_pen_common_handle.is_valid_pen_move = MMI_FALSE;
			swatch_pen_common_handle.pen_move_offset = 0;
			SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr valid out\n");
			return;
		}
	}
	if (mmi_swatch_common_abs(pos.y - swatch_pen_common_handle.pen_down_pos.y) > SMART_WATCH_COMMON_PEN_CLICK_THRESHOLD)
	{
		swatch_pen_common_handle.cell_info->disable_array_image = MMI_TRUE;
	}
	swatch_pen_common_handle.is_valid_pen_move = MMI_TRUE;
	mmi_swatch_common_cell_change_index();
	
	swatch_pen_common_handle.pen_move_offset = swatch_pen_common_handle.pen_move_offset % (swatch_pen_common_handle.cell_info->cell_height + swatch_pen_common_handle.cell_info->cell_distance);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr, pen_move_offset=%d after mode\n", swatch_pen_common_handle.pen_move_offset);
	
	swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
	
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_move_hdlr out\n");

}

static void mmi_swatch_common_pen_up_hdlr(mmi_pen_point_struct pos)
{

	S32 distance, cell_total_height, X;

	#ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
      #ifdef __MMI_WEARABLE_DEVICE__
	    //由于是app自己处理pen up，所以左右滑动也要自己处理；
	  //只有在有效区域右滑，才能back处理；
	  if (swatch_pen_common_handle.pen_move_direction == MMI_SWATCH_MOVE_DIRECTION_H)
	  {
		  if(0<=pos.x && pos.x<=240 && 0<=pos.y && pos.y<=LCD_HEIGHT-40) //50->40
		  {
			if (g_swatch_is_pen_down && ((pos.x - g_swatch_pen_down_pos.x) > MMI_SWATCH_BACK_MOVE_THRESHOLD_X))  //swipe right
			{
				mmi_frm_scrn_close_active_id();
				g_swatch_is_pen_down = MMI_FALSE;
	            
				swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
				//mmi_frm_asm_free_anonymous;   init中申请；
				mmi_swatch_common_pen_handle_exit();

				//g_is_launch_monthly_view = KAL_FALSE;
				return;
			}
	    }
	  }
      #endif  //__MMI_WEARABLE_DEVICE__
    #endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/

    #ifdef __ASTER_NEW_STYLE_CHANGE_FOR_ALARM__
		if(g_is_add_alarm_screen_pressed == MMI_TRUE)
			g_is_add_alarm_screen_pressed = MMI_FALSE;
    #endif/*__ASTER_NEW_STYLE_CHANGE_FOR_ALARM__*/
	/*if (MMI_FALSE == swatch_pen_common_handle.is_valid_pen_move)
	{
		SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr valid out\n");
		return;
	}*/

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr in, pos.y=%d\n", pos.y);
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr up, pen move offset=%d\n", swatch_pen_common_handle.pen_move_offset);
	
	distance = swatch_pen_common_handle.pen_move_offset; //pos.y - mainmenu_swatch_list.pen_down_pos_y;

	swatch_pen_common_handle.pen_move_offset = distance;

	cell_total_height = swatch_pen_common_handle.cell_info->cell_height + swatch_pen_common_handle.cell_info->cell_distance;

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr up, distance=%d\n", distance);

	X = mmi_swatch_common_abs(distance) % cell_total_height;

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr up, X=%d\n", X);


	if(X <= SMART_WATCH_COMMON_PEN_CLICK_THRESHOLD && MMI_TRUE == swatch_pen_common_handle.is_valid_pen_move)
	{
		//long tap has happened
		/*if (MMI_FALSE == swatch_pen_common_handle.pen_click && swatch_pen_common_handle.cell_info->long_tap_handle)
		{
			//mmi_swatch_common_pen_handle_exit();
			swatch_pen_common_handle.cell_info->long_tap_handle(pos);
			swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
			return;
		}*/
		
		if(MMI_TRUE == swatch_pen_common_handle.pen_click && swatch_pen_common_handle.cell_info->click_handle && \
			swatch_pen_common_handle.cell_info->click_handle(swatch_pen_common_handle.pen_down_pos, pos) == MMI_TRUE )
		{
			swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
			//mmi_swatch_common_pen_handle_exit();
			return;
		}
	} 

	if(X <= SMART_WATCH_COMMON_UP_THRESHOLD)
	{
		if(distance > 0)//move down
		{
			swatch_pen_common_handle.start_anim_pos = distance;
			swatch_pen_common_handle.end_anim_pos = distance - X;
			swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
			gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
		}
		else //move up
		{
			swatch_pen_common_handle.start_anim_pos = distance;
			swatch_pen_common_handle.end_anim_pos = distance + X;
			swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
			gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
		}
	}
	else
	{
		if(distance > 0) //move down
		{
			swatch_pen_common_handle.start_anim_pos = distance;
			swatch_pen_common_handle.end_anim_pos = distance + (cell_total_height - X);
			swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
			gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
		}
		else //move up
		{
			swatch_pen_common_handle.start_anim_pos = distance;
			swatch_pen_common_handle.end_anim_pos = distance - (cell_total_height - X);
			swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
			gui_start_timer(SMART_WATCH_COMMON_ANIM_TIMER, mmi_swatch_common_swap_animation);
		}
	}
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_up_hdlr out\n");

}

static void mmi_swatch_common_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 

	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_long_tap_hdlr in pos.y=%d\n", pos.y);
	if (NULL != swatch_pen_common_handle.cell_info->long_tap_handle)
	{
		swatch_pen_common_handle.pen_click = MMI_FALSE;
		if (MMI_FALSE == swatch_pen_common_handle.pen_click && swatch_pen_common_handle.cell_info->long_tap_handle)
		{
			//mmi_swatch_common_pen_handle_exit();
			swatch_pen_common_handle.cell_info->long_tap_handle(pos);
			swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;
			return;
		}
	}
	SWATCH_PEN_TRACE("[SWATCH_PEN]mmi_swatch_common_pen_long_tap_hdlr out\n");
}

static void mmi_swatch_common_pen_handle_init(swatch_common_cell_info *cell_info)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	GDI_RESULT gdi_result;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 
	swatch_pen_common_handle.cell_info = cell_info;

	//set pen pos area
	if (swatch_pen_common_handle.cell_info->set_pen_pos_area)
		swatch_pen_common_handle.cell_info->set_pen_pos_area(&swatch_pen_common_handle.pen_pos_start, &swatch_pen_common_handle.pen_pos_end);
	else
	{
		swatch_pen_common_handle.pen_pos_start.x = 0;
		swatch_pen_common_handle.pen_pos_start.y = 0;
		swatch_pen_common_handle.pen_pos_end.x = LCD_WIDTH;
		swatch_pen_common_handle.pen_pos_end.y = LCD_HEIGHT;
	}

	swatch_pen_common_handle.pen_move_offset = 0;
	swatch_pen_common_handle.cell_info->disable_array_image = MMI_FALSE;

	//create layer buffer & layer
	//alarm base layer create
	/*MMI_ASSERT (NULL == swatch_pen_common_handle.cell_info->cell_layer_buffer);  

	swatch_pen_common_handle.cell_info->cell_layer_buffer = mmi_frm_asm_alloc_anonymous_nc(LCD_WIDTH * LCD_HEIGHT * 4);

	MMI_ASSERT(NULL != swatch_pen_common_handle.cell_info->cell_layer_buffer);

	if (NULL != swatch_pen_common_handle.cell_info->cell_layer_buffer)
	{
	
	    gdi_result = gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32_PARGB,
											 0,
											 0,
											 LCD_WIDTH,
											 LCD_HEIGHT,
											 &swatch_pen_common_handle.cell_info->cell_layer_handler,
											 swatch_pen_common_handle.cell_info->cell_layer_buffer,
											 LCD_WIDTH * LCD_HEIGHT * 4);
	   
		 MMI_ASSERT(GDI_SUCCEED == gdi_result);
	}*/
	gdi_result = gdi_layer_create(0,
								 0,
								 LCD_WIDTH,
								 LCD_HEIGHT,
								 &swatch_pen_common_handle.cell_info->cell_layer_handler);
	   
	MMI_ASSERT(GDI_SUCCEED == gdi_result);

	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_swath_common_pen_move_right_hdlr, NULL);
	
}

void mmi_swatch_common_pen_handle_exit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	GDI_RESULT gdi_result;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/ 

	gui_cancel_timer(mmi_swatch_common_swap_animation);
	
	//if (NULL != swatch_pen_common_handle.cell_info->cell_layer_buffer)
	/*if (swatch_pen_common_handle.cell_info != NULL && NULL != swatch_pen_common_handle.cell_info->cell_layer_buffer)
	{
		if (swatch_pen_common_handle.cell_info->cell_layer_handler != GDI_LAYER_EMPTY_HANDLE)
		{
			gdi_result = gdi_layer_free(swatch_pen_common_handle.cell_info->cell_layer_handler);
			MMI_ASSERT(GDI_SUCCEED == gdi_result);
		}
		mmi_frm_asm_free_anonymous(swatch_pen_common_handle.cell_info->cell_layer_buffer);
		swatch_pen_common_handle.cell_info->cell_layer_buffer = NULL;
	}	*/
	if (swatch_pen_common_handle.cell_info != NULL &&
		swatch_pen_common_handle.cell_info->cell_layer_handler != GDI_LAYER_EMPTY_HANDLE)
	{
		gdi_result = gdi_layer_free(swatch_pen_common_handle.cell_info->cell_layer_handler);
		swatch_pen_common_handle.cell_info->cell_layer_handler = GDI_LAYER_EMPTY_HANDLE;
		MMI_ASSERT(GDI_SUCCEED == gdi_result);
	}
	mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_swath_common_pen_move_right_hdlr, NULL);
}

void mmi_swatch_cell_entry(swatch_common_cell_info *cell_info)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
	mmi_swatch_common_pen_handle_init(cell_info);  

	swatch_pen_common_handle.cell_info->draw_cell_bg();
	swatch_pen_common_handle.cell_info->draw_cell_layer(swatch_pen_common_handle.pen_move_offset);
	
    gdi_layer_set_blt_layer(        
        swatch_pen_common_handle.cell_info->base_layer,
        swatch_pen_common_handle.cell_info->cell_layer_handler,
        NULL,
        NULL);
    
    clear_key_handlers();
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_clear_pen_handlers();
    wgui_register_pen_down_handler(mmi_swatch_common_pen_down_hdlr);
    wgui_register_pen_move_handler(mmi_swatch_common_pen_move_hdlr);
    wgui_register_pen_up_handler(mmi_swatch_common_pen_up_hdlr);
	mmi_pen_register_long_tap_handler(mmi_swatch_common_pen_long_tap_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */
}

#endif


