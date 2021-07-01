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
 *   wgui_categories_calendar.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *  calendar related funtions
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_release.h"
#include "DebugInitDef_Int.h"

#include "string.h"
#include "stdio.h"
#include "Unicodexdcl.h"
#include "lcd_sw_inc.h"

//#include "GlobalDefs.h"
#include "CustDataRes.h"
//#include "CustDataProts.h"
//#include "WguiCategoryGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_app_uiframework_def.h"
//#include "mmi_frm_gprot.h"
//#include "CalendarDef.h"        /* Calendar image */
//#include "CalendarProt.h"
//#include "CalendarResDef.h"
//#include "CalendarGprot.h"

#include "gui_themes.h"
#include "gui_font_size.h"
//#include "profilingengine.h"

#include "mmi_frm_events_gprot.h"
#include "Gui_Setting.h"
#include "wgui_categories_enum.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_calendar.h"

#ifdef __MMI_TOUCH_SCREEN__
#include "wgui_touch_screen.h"
#endif /*__MMI_TOUCH_SCREEN__*/ 

#ifdef __MMI_TOUCH_SCREEN__
#include "gui_touch_feedback.h"
#endif /*__MMI_TOUCH_SCREEN__*/

//RHR
    #include "MMI_features.h"
    #include "app_datetime.h"
    #include "gdi_const.h"
    #include "gdi_datatype.h"
    #include "wgui.h"
    #include "gui_theme_struct.h"
    #include "MMIDataType.h"
    #include "kal_general_types.h"
    #include "gui_typedef.h"
    #include "wgui_categories_calendar.h"
    #include "gui_data_types.h"
    #include "string.h"
    #include "mmi_frm_input_gprot.h"
    #include "gdi_include.h"
    #include "wgui_include.h"
    #include "gui.h"
    #include "kal_public_api.h"
    #include "DebugInitDef_Int.h"
    #include "gui_themes.h"
    #include "CustThemesRes.h"
    #include "mmi_rp_app_uiframework_def.h"
    #include "stdio.h"
    #include "Unicodexdcl.h"
    #include "wgui_inputs.h"
    #include "gui_calendar.h"
    #include "mmi_frm_mem_gprot.h"
    #include "wgui_categories_enum.h"
    #include "wgui_draw_manager.h"
    #include "wgui_categories_util.h"
    #include "custom_mmi_default_value.h"
    #include "wgui_touch_screen.h"
    #include "mmi_frm_events_gprot.h"
    #include "lcd_sw_rnd.h"
    #include "lcd_sw_inc.h"
    #include "Gui_Setting.h"
    #include "PhoneSetupGprots.h"

#if defined(__MMI_WEARABLE_DEVICE__)
#ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
#define __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
#endif

#ifndef __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
#define __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
#endif/*__ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__*/
#endif/*__MMI_WEARABLE_DEVICE__*/

#ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
S16 g_calendar_monthly_view_pen_down_y = 0;

#ifdef __MMI_WEARABLE_DEVICE__
#define MMI_SWATCH_BACK_MOVE_THRESHOLD_X  (LCD_WIDTH/3)
static MMI_BOOL g_swatch_is_pen_down = MMI_FALSE;
static mmi_pen_point_struct g_swatch_pen_down_pos = {0};
#endif  //__MMI_WEARABLE_DEVICE__

#endif
static applib_time_struct g_cat_calendar_highlight_time;
#ifndef __MMI_CALENDAR_NEW_STYLE__
static applib_time_struct g_cat_calendar_start_time;
#endif
static applib_time_struct g_cat_calendar_end_time;
static applib_time_struct g_cat_calendar_max_time;
static applib_time_struct g_cat_calendar_min_time;
#ifdef __GDI_MEMORY_PROFILE_2__
static GDI_HANDLE g_cat_calendar_abm_layer = NULL;
#endif
static GDI_HANDLE g_cat_calendar_target_layer = NULL;
static UI_image_ID_type g_cat_calendar_bg_id = IMAGE_ID_NULL;

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_CALENDAR_NEW_STYLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

static gui_calendar_type_enum g_cat_calendar_type;
static wgui_cat83_event_struct g_cat_calendar_events;

#ifdef __MMI_CALENDAR_EVENT__
static S32 (*g_cat_calendar_cell_data_query_handler)(
             gui_calendar_type_enum type,
             applib_time_struct start_time,
             applib_time_struct end_time,
             applib_time_struct interval,
             S32 query_count,
             gui_calendar_cell_struct *cells) = NULL;
#endif
static S32 (*g_cat_calendar_cell_lunar_query_handler)(
             gui_calendar_type_enum type, // calendar type
             applib_time_struct cell_time, // highlighted time to query
             applib_time_struct time_interval, // the interval of time to query
             PU8 title, // title of cell
             U32 title_length, // title's length in U8
             gui_calendar_cell_detail_info_struct *detail_info) = NULL;

#ifdef __MMI_CLNDR_EVENT_INFO__
static S32 (*g_cat_calendar_event_query_handler)(
             gui_calendar_type_enum type, // calendar type
             applib_time_struct event_time, // highlighted time to query
             applib_time_struct time_interval, // the interval of time to query
             wgui_cat83_event_struct *event_info) = NULL;
#endif
static MMI_BOOL (*g_cat_calendar_highlight_change_callback)(
                  gui_calendar_type_enum type, // calendar type
                  applib_time_struct highlighted_time,
                  applib_time_struct start_time,
                  applib_time_struct end_time) = NULL;

static wgui_calendar_horizontal_select_struct g_cat83_cal_h_select[WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT];

static void wgui_cat83_draw_horizontal_select(U8 index);

#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif

extern S32 UI_strlen(UI_string_type text);


#ifdef __MMI_TOUCH_SCREEN__

static MMI_BOOL wgui_cat83_pen_check_bound(mmi_pen_point_struct pos ,U8 index ,U8 icon_index)
{
    if (PEN_CHECK_BOUND(pos.x, pos.y,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_width,
             g_cat83_cal_h_select[index].icon_info[icon_index].icon_height))
    {
        return MMI_TRUE;
    }
    else
        return MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL wgui_cat83_horizintal_select_switch(U8 index, U8 direction)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    applib_time_struct inc, temp, current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(&inc, 0, sizeof(applib_time_struct));
    memset(&temp, 0, sizeof(applib_time_struct));
    current_time = g_cat_calendar_highlight_time;
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
    {
        current_time.nDay = 1;
#ifdef __MMI_CALENDAR_NEW_STYLE__
            inc.nMonth = 1;
#else
            if (index == 0)
            {
                inc.nYear = 1;
            }
            if (index == 1)
            {
                inc.nMonth = 1;
            }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/

        if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV)
        {
            applib_dt_decrease_time(
                (applib_time_struct*)&current_time,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&temp);
        }
        if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT)
        {
            applib_dt_increase_time(
                (applib_time_struct*)&current_time,
                (applib_time_struct*)&inc,
                (applib_time_struct*)&temp);
        }

		/* compare with the max time and min time */
		{
            applib_time_struct diff;
			S32 compare_result = 0;
			compare_result = applib_dt_compare_time(
                                 &g_cat_calendar_max_time,
                                 &temp,
                                 &diff);
			if (compare_result != DT_TIME_LESS)
			{
				compare_result = applib_dt_compare_time(
                                     &g_cat_calendar_min_time,
                                     &temp,
                                     &diff);
                if (compare_result != DT_TIME_GREATER)
                {
                    result = MMI_TRUE;
                }
			}
		}
    }
 #ifdef __MMI_CALENDAR_EVENT__
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
    {
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 0)
#endif
        {
            inc.nDay = 7;

            if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV)
            {
                inc.nDay = current_time.DayIndex + 1;
                applib_dt_decrease_time(
                    (applib_time_struct*)&current_time,
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&temp);
            }
            if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT)
            {
                inc.nDay = DT_DAYS_OF_WEEK - current_time.DayIndex;
                applib_dt_increase_time(
                    (applib_time_struct*)&current_time,
                    (applib_time_struct*)&inc,
                    (applib_time_struct*)&temp);
            }

			/* compare with the max time and min time */
			{
				applib_time_struct diff;
				S32 compare_result = 0;
				compare_result = applib_dt_compare_time(
									&g_cat_calendar_max_time,
									&temp,
									&diff);
				if (compare_result != DT_TIME_LESS)
				{
					compare_result = applib_dt_compare_time(
										&g_cat_calendar_min_time,
										&temp,
										&diff);
					if (compare_result != DT_TIME_GREATER)
					{
						result = MMI_TRUE;
					}
				}
			}
        }
#ifndef __MMI_CALENDAR_NEW_STYLE__
        if (index == 1)
        {
            if (direction == WGUI_CAL_H_SELECT_ALLOW_PREV &&
                g_cat_calendar_start_time.nHour > 0)
            {
                result = MMI_TRUE;
            }
            if (direction == WGUI_CAL_H_SELECT_ALLOW_NEXT &&
                g_cat_calendar_end_time.nHour < DT_HRS_PRE_DAY)
            {
                result = MMI_TRUE;
            }
        }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
#endif /*WEEKLY VIEW*/

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_down_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif

#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (wgui_cat83_pen_check_bound(pos, index, icon_index))
            {
                if(g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
                {
                    return MMI_FALSE;
                }
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_DOWN;
        #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
        #endif /* __MMI_SLIM_IMG_RES__ */

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                
                g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = TRUE;
                gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
            }
        }
    }
    return MMI_TRUE;
}

#ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
static MMI_BOOL wgui_cat83_for_swatch_pen_down_hdlr(mmi_pen_point_struct pos)
{
		/*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
		
	
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
	    g_calendar_monthly_view_pen_down_y = pos.y;

    #ifdef __MMI_WEARABLE_DEVICE__
	    g_swatch_is_pen_down = MMI_TRUE;
	    g_swatch_pen_down_pos.x = pos.x;
	    g_swatch_pen_down_pos.y = pos.y;
	#endif  //__MMI_WEARABLE_DEVICE__

        //wgui_general_pen_down_hdlr(pos);
		return MMI_TRUE;//一定要return true，否则下一个pen up handler执行不到；
}
#endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_up_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if(g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
    #ifdef __MMI_SLIM_IMG_RES__
                if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN ||
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN)
                {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                }
    #endif

                if (wgui_cat83_pen_check_bound(pos ,index ,icon_index))
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state != GUI_CALENDAR_PEN_STATE_DOWN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                                       
                        //gdi_layer_lock_frame_buffer();
                        wgui_cat83_draw_horizontal_select(index);
                        //gdi_layer_unlock_frame_buffer();
                   }
                   else
                   {
                        if(icon_index == 0)/*prev icon*/
                        {
                               if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                               {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                    if(index == 0)
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                    }
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                    }
                        #endif
                               }
                #ifdef __MMI_CALENDAR_EVENT__
                               if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                               {
                 #ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                 #else
                                    if (index == 0)
                                    {
                                         wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                    } 
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                    }
                 #endif
                               }     
                #endif
                        }
                        else /*next icon*/
                        {
                            if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                            {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                if(index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                }
                        #endif
                        }
                #ifdef __MMI_CALENDAR_EVENT__
                        if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                        {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                        #else
                                if (index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                 }
                         #endif
                          }
                    #endif
                      }
                     wgui_cat83_draw_horizontal_select(index);
                     gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
                  }
               }
               else
               {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;

                        //gdi_layer_lock_frame_buffer();
                        wgui_cat83_draw_horizontal_select(index);
                        //gdi_layer_unlock_frame_buffer();
                  }
               }
               g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = FALSE;
            }
        }
    }
    return MMI_TRUE;
}

#ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
static MMI_BOOL wgui_cat83_for_swatch_pen_up_hdlr(mmi_pen_point_struct pos)
{
		/*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
		S16 distance_y_prev, distance_y_next = 0;
		
		
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
	#ifdef __MMI_WEARABLE_DEVICE__
	    //由于是app自己处理pen up，所以左右滑动也要自己处理；
	    if (g_swatch_is_pen_down && ((pos.x - g_swatch_pen_down_pos.x) > MMI_SWATCH_BACK_MOVE_THRESHOLD_X))  //swipe right
	    {
	        mmi_frm_scrn_close_active_id();
	        g_swatch_is_pen_down = MMI_FALSE;
	        //wgui_general_pen_up_hdlr(pos);

	        return;
	    }
    #endif  //__MMI_WEARABLE_DEVICE__

	    //处理上下滑动；
		if(pos.y >= g_calendar_monthly_view_pen_down_y)
		  distance_y_prev = pos.y - g_calendar_monthly_view_pen_down_y;
		else
		  distance_y_next = g_calendar_monthly_view_pen_down_y - pos.y;

		//向下滑，prev;
        if(pos.y > g_calendar_monthly_view_pen_down_y && distance_y_prev > LCD_HEIGHT/10)//24 pixels
        {
				              if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                               {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                    if(index == 0)
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                    }
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                    }
                        #endif
                               }
                		#ifdef __MMI_CALENDAR_EVENT__
                               if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                               {
                 			#ifdef __MMI_CALENDAR_NEW_STYLE__
                                    wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                 			#else
                                    if (index == 0)
                                    {
                                         wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                    } 
                                    else
                                    {
                                        wgui_calendar_switch_prev(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                    }
                 			#endif
                               }     
                		#endif			    
        }

        //向上滑，next;
		if(pos.y < g_calendar_monthly_view_pen_down_y && distance_y_next > LCD_HEIGHT/10)//24 pixels
		{
		                   if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
                            {
                        #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                        #else
                                if(index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_YEAR);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MONTH);
                                }
                        #endif
                        }
                    #ifdef __MMI_CALENDAR_EVENT__
                        if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
                        {
                           #ifdef __MMI_CALENDAR_NEW_STYLE__
                                wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                           #else
                                if (index == 0)
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_WEEK);
                                }
                                else
                                {
                                    wgui_calendar_switch_next(GUI_CALENDAR_TIME_SWITCH_MULTI_PERIOD);
                                 }
                           #endif
                          }
                    #endif    
	    }

		return MMI_TRUE;
}

#endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    U8 index ,icon_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
#else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
                if (wgui_cat83_pen_check_bound(pos ,index ,icon_index))
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        result = MMI_TRUE;
                    }
                    else
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_MOVE_IN;
                    #ifdef __MMI_SLIM_IMG_RES__
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_x += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_y += GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    #endif /* __MMI_SLIM_IMG_RES__ */
                    }
                }
                else
                {
                #ifdef __MMI_SLIM_IMG_RES__
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
                    {
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                        g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    }
                #endif /* __MMI_SLIM_IMG_RES__ */
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                }

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                 result = MMI_TRUE;
          }
       }
    }
    return result;
}

#ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
static MMI_BOOL wgui_cat83_for_swatch_pen_move_hdlr(mmi_pen_point_struct pos)
{
   return MMI_TRUE;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_pen_abort_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  c       [IN]         
 *  pos     [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static MMI_BOOL wgui_cat83_pen_abort_hdlr(mmi_pen_point_struct pos)
        {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index ,icon_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
    #else
    for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
    #endif
    {
        /* check  arrow icon*/
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
        {
            if (g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button == TRUE)
            {
            #ifdef __MMI_SLIM_IMG_RES__
                if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN ||
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN)
        {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
            }
        #endif /* __MMI_SLIM_IMG_RES__ */
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;

                //gdi_layer_lock_frame_buffer();
                wgui_cat83_draw_horizontal_select(index);
                //gdi_layer_unlock_frame_buffer();
                g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = FALSE;
            }
         }
     }
    return MMI_TRUE;
        }
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
static void wgui_cat83_draw_icon_with_opacity_layer(S32 x, S32 y, S32 w, S32 h, PU8 icon)
        {
    GDI_HANDLE opacity_layer = GDI_NULL_HANDLE;
    GDI_HANDLE abm_src_layer = GDI_NULL_HANDLE;
	
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer != NULL)
            {
        abm_src_layer = g_cat_calendar_abm_layer;
            }
    else
#endif
    {
        gdi_layer_get_active(&abm_src_layer);
    }

    gdi_layer_create(x, y, w - 1, h - 1, &opacity_layer);
    gdi_layer_push_and_set_active(opacity_layer);
    //gdi_push_and_set_alpha_blending_source_layer(opacity_layer);
    //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_set_opacity(MMI_TRUE,128); 
    gdi_image_draw(0, 0, icon);
    //gdi_pop_and_restore_alpha_blending_source_layer();
    gdi_layer_pop_and_restore_active();
    gdi_layer_push_and_set_clip(x, y, x + w - 1, y + h - 1);
    gdi_layer_flatten_with_clipping(abm_src_layer, opacity_layer, 0, 0);
    gdi_layer_pop_clip();
    gdi_layer_free(opacity_layer);
    }
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
#endif /* __MMI_TOUCH_SCREEN__ */

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_init_horizontal_select
 * DESCRIPTION
 *  Calendar category init horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_init_horizontal_select(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
    S32 icon_width[WGUI_CAL_H_SELECT_ALLOW_TOTAL] = {0, 0};
    S32 icon_height[WGUI_CAL_H_SELECT_ALLOW_TOTAL] = {0, 0};
    U8 icon_index;
#endif

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
#endif
#endif
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /*get icon width and height*/
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

#ifdef __MMI_CALENDAR__
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
    gdi_image_get_dimension_id(
        (U16)LEFT_RED_ARROW_NORMAL,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_PREV],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_PREV]);
    gdi_image_get_dimension_id(
        (U16)RIGHT_RED_ARROW_NORMAL,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_NEXT],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_NEXT]);
#else
  #if !defined(__MMI_WEARABLE_DEVICE__)
    gdi_image_get_dimension_id(
        (U16)CAL_LEFT_ARROW_UP_IMAGE,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_PREV],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_PREV]);
    gdi_image_get_dimension_id(
        (U16)CAL_RIGHT_ARROW_UP_IMAGE,
        &icon_width[WGUI_CAL_H_SELECT_ALLOW_NEXT],
        &icon_height[WGUI_CAL_H_SELECT_ALLOW_NEXT]); 
  #endif/*__MMI_WEARABLE_DEVICE__*/
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_CALENDAR__ */

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

/*init horizontal select*/
#ifdef __MMI_CALENDAR_NEW_STYLE__
    index = 0;
    #else
    for (index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index++)
    #endif
    {
        /* Calculate every horizontal select's position and dimension. */
#ifdef __MMI_CALENDAR_NEW_STYLE__
            g_cat83_cal_h_select[index].x = GUI_CALENDAR_FRAME_START_X + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
#else
        if (index == 0)
        {
            g_cat83_cal_h_select[index].x = GUI_CALENDAR_FRAME_START_X + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
        }
        else
        {
            g_cat83_cal_h_select[index].x = 
                GUI_CALENDAR_FRAME_START_X + (GUI_CALENDAR_FRAME_WIDTH + GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER) / 2;
    }
#endif /*__MMI_CALENDAR_NEW_STYLE__*/
        if (dm_check_control_exist(MMI_CATEGORY83_ID, DM_STATUS_BAR1))
    {
            g_cat83_cal_h_select[index].y = MMI_status_bar_height;
        }
        else
        {
            g_cat83_cal_h_select[index].y = 0;
        }
        
#ifdef __MMI_CALENDAR_NEW_STYLE__
        g_cat83_cal_h_select[index].width = GUI_CALENDAR_FRAME_WIDTH - (GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER << 1);
    #else
        g_cat83_cal_h_select[index].width = 
            GUI_CALENDAR_FRAME_WIDTH / 2 - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_OTHER / 2 - GUI_CALENDAR_HORIZONTAL_SELECT_GAP_BORDER;
    #endif
	#ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
        g_cat83_cal_h_select[index].height = GUI_CALENDAR_FRAME_START_Y - g_cat83_cal_h_select[index].y;
	#else
	    g_cat83_cal_h_select[index].height = 34 - g_cat83_cal_h_select[index].y;
	#endif

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

        /* init horizontal select prev and next icon*/
#ifdef __MMI_CALENDAR__
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
        for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index++)
        {
#ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if(icon_index == 0)
            {
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(LEFT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(LEFT_RED_ARROW_PRESSED);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(LEFT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x;
    }
            else
    {
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(RIGHT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(RIGHT_RED_ARROW_PRESSED);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(RIGHT_RED_ARROW_NORMAL);
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = 
                     g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - icon_width[icon_index];
    #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
#endif
            }

#else
   #if !defined(__MMI_WEARABLE_DEVICE__)
            if(icon_index == 0)
        {
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(CAL_LEFT_ARROW_UP_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(CAL_LEFT_ARROW_DOWN_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(CAL_LEFT_ARROW_DISABLE_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x;
        }
            else
            {
                g_cat83_cal_h_select[index].icon_info[icon_index].up_icon = get_image(CAL_RIGHT_ARROW_UP_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].down_icon = get_image(CAL_RIGHT_ARROW_DOWN_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon = get_image(CAL_RIGHT_ARROW_DISABLE_IMAGE);
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x = g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - icon_width[icon_index];
    #ifdef __MMI_SLIM_IMG_RES__
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x -= GUI_CALENDAR_BASIC_UI_ARROW_SHIFT;
    #endif
    }
#endif /*__MMI_SLIM_IMG_RES__*/
#endif /*__MMI_SLIM_IMG_RES__*/
            
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_width = icon_width[icon_index];
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_height = icon_height[icon_index];
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_y = g_cat83_cal_h_select[index].y + (g_cat83_cal_h_select[index].height - icon_height[icon_index]) / 2;
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
            g_cat83_cal_h_select[index].icon_info[icon_index].pen_down_in_button = 0;
        }
#endif /*__MMI_TOUCH_SCREEN__*/
#endif /* __MMI_CALENDAR__ */
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #ifdef __MMI_CALENDAR_NEW_STYLE__
/* under construction !*/
/* under construction !*/
        #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif /*__MMI_CALENDAR_NEW_STYLE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #if defined (__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
    #else
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
        #ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif
    }
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_draw_horizontal_select
 * DESCRIPTION
 *  Calendar category display horizontal select.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_draw_horizontal_select(U8 index)
{
   /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 cell_x, cell_width, string_x = 0; 
    S32 string_width, string_height;
    PU8 icon;
    S8 temp_text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH + 1];
    UI_character_type text[WGUI_CAT_CAL_HORIZONTAL_SELECT_TEXT_LENGTH + 1];
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif
#endif

    U8 seperator;

    U8 icon_index;
#ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
    char str_month[13][20] = { {0},
		                        {'J','a', 'n', 'u', 'a', 'r', 'y', 0},
								{'F','e', 'b', 'r', 'u', 'a', 'r', 'y', 0},
								{'M','a', 'r', 'c', 'h', 0},
								{'A','p', 'r', 'i', 'l', 0},
								{'M','a', 'y', 0},
								{'J','u', 'n', 'e', 0},
								{'J','u', 'l', 'y', 0},
								{'A','u', 'g', 'u', 's', 't', 0},
								{'S','e', 'p', 't', 'e', 'm', 'b', 'e', 'r', 0},
								{'O','c', 't', 'o', 'b', 'e', 'r', 0},
								{'N','o', 'v', 'e', 'm', 'b', 'e', 'r', 0},
								{'D','e', 'c', 'e', 'm', 'b', 'e', 'r', 0},
	                        };

    WCHAR str_month_chn[20] = {0};
	WCHAR text_chn [30] = {0};
    stFontAttribute		Title_font=			{	0,0,0,0x0003,0,1	}; //20px;
	U8 data;

	data = srv_setting_get_language();
#endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    #if 0
/* under construction !*/
    #endif
    
 #ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
    switch (PhnsetGetDateSeperatorFormat())
    {
        case 0:
            seperator = '.';
            break;
    
        case 1:
            seperator = ':';
            break;
    
        case 2:
            seperator = '/';
            break;
    
        case 3:
            seperator = '-';
            break;
    
        default:
            seperator = '.';
            break;
    }
 #else
    seperator = ' ';
 #endif


    gdi_layer_lock_frame_buffer();
    gdi_layer_push_and_set_active(g_cat_calendar_target_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer != NULL &&
        g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
    {    
      #ifndef __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
	    //new style;(remove original bg)
        gdi_draw_solid_rect(
            g_cat83_cal_h_select[index].x,
            g_cat83_cal_h_select[index].y,
            g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
            g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1,
            GDI_COLOR_TRANSPARENT);
	  #endif/*__ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__*/
    }
    else
    {
#endif /* __GDI_MEMORY_PROFILE_2__ */
    gdi_draw_solid_rect(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1,
        GDI_COLOR_WHITE);
    if (g_cat_calendar_bg_id != IMAGE_ID_NULL)
    {
        gdi_image_draw_id(0, 0, g_cat_calendar_bg_id);
    }
    else
    {
        gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->sub_menu_bkg_filler);
    }
#ifdef __GDI_MEMORY_PROFILE_2__
    }
#endif /* __GDI_MEMORY_PROFILE_2__ */ 

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
    #ifdef __MMI_CALENDAR_NEW_STYLE__
/* under construction !*/
/* under construction !*/
    #else
/* under construction !*/
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
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif //if 0

#ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
//only remove prev and next allow;
    /*prev and next allow*/
#if defined(__MMI_FTE_SUPPORT__) || defined(__MMI_TOUCH_SCREEN__)
    for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
    {

        if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DOWN ||
            g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_MOVE_IN)
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].down_icon;
    }
        else if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].disable_icon;
    }
    else
    {
            icon = g_cat83_cal_h_select[index].icon_info[icon_index].up_icon;
    }

    if(icon != NULL)
    {
        #ifdef __MMI_CLNDR_FTE_SLIM_RES__
            if(g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
            {
                wgui_cat83_draw_icon_with_opacity_layer(
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_width,
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_height,
                    icon);
            }
            else
        #endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
            {
        gdi_image_draw(
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_x,
                g_cat83_cal_h_select[index].icon_info[icon_index].icon_y,
            icon);
    }
        }
#if 0
    #ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* __MMI_MENSTRUAL__ */
#endif //if 0
    }
#endif /* __MMI_TOUCH_SCREEN__ */
#endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/

    /* Display text */
#if defined(__MMI_FTE_SUPPORT__)||defined( __MMI_TOUCH_SCREEN__)
    cell_x = g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_width;
#else
    cell_x = g_cat83_cal_h_select[index].x ;
#endif

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#else
#if defined(__MMI_FTE_SUPPORT__)||defined( __MMI_TOUCH_SCREEN__)
        cell_width =
                g_cat83_cal_h_select[index].width -
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_width -
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height;
#else
       cell_width = g_cat83_cal_h_select[index].width;
#endif
#endif //if 0

    /* Show text background */
#ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
#ifndef __MMI_CLNDR_FTE_SLIM_RES__
#if defined( __MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) && defined(__MMI_CALENDAR__) /*lhm remove IMG_CALENDAR_HORIZONTAL_SELECT_BG*/
    if (g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].up_icon != NULL &&
        g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_NEXT].up_icon != NULL)
        {
            gdi_image_draw_resized_id(
                cell_x,
                g_cat83_cal_h_select[index].y + ((g_cat83_cal_h_select[index].height - g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height) >> 1),
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_NEXT].icon_x - cell_x,
                g_cat83_cal_h_select[index].icon_info[WGUI_CAL_H_SELECT_ALLOW_PREV].icon_height,
                IMG_CALENDAR_HORIZONTAL_SELECT_BG);
        }
#endif /* __MMI_FTE_SUPPORT__ */
#endif /*__MMI_CLNDR_FTE_SLIM_RES__*/
#endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif// if 0

    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_MONTH)
    {
        applib_time_struct temp, diff;
        S32 time_compare;
        time_compare = applib_dt_compare_time(
                            &g_cat_calendar_max_time,
                            &g_cat_calendar_highlight_time,
                            &diff);
        if (DT_TIME_LESS == time_compare)
        {
            temp = g_cat_calendar_max_time;
        }
        else
        {
            time_compare = applib_dt_compare_time(
                               &g_cat_calendar_min_time,
                               &g_cat_calendar_highlight_time,
                               &diff);
            if (DT_TIME_GREATER == time_compare)
            {
                temp = g_cat_calendar_min_time;
            }
            else
            {
                temp = g_cat_calendar_highlight_time;
             }
        }
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
					  #ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
                        sprintf((S8*)temp_text, "%02d%c%04d", temp.nMonth, seperator, temp.nYear);
					  #else
					    if(data == 0)
					    sprintf((S8*)temp_text, "%s%c%04d", str_month[temp.nMonth], seperator, temp.nYear);
						else
						{
							wcscpy(str_month_chn, (WCHAR*)GetString(STR_GLOBAL_JANUARY_SHORT + temp.nMonth -1));
						    kal_wsprintf(text_chn, "%04d%c", temp.nYear, seperator);
							wcscat(text_chn, str_month_chn);
						}
					  #endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%c%02d", temp.nYear, seperator, temp.nMonth);
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "%4d", temp.nYear);
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "%d", temp.nMonth);
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
    }
    
#ifdef __MMI_CALENDAR_EVENT__
    if (g_cat_calendar_type == GUI_CALENDAR_TYPE_WEEK)
    {
    #ifdef __MMI_TOUCH_SCREEN__
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
                        sprintf((S8*)temp_text, "Week%02d%c%04d", applib_dt_get_week_number(&g_cat_calendar_end_time), seperator, g_cat_calendar_end_time.nYear);
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%cWeek%02d", g_cat_calendar_end_time.nYear, seperator, applib_dt_get_week_number(&g_cat_calendar_end_time));
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "W%02d", applib_dt_get_week_number(&g_cat_calendar_highlight_time));
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "12H");
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
#else /*__MMI_TOUCH_SCREEN__*/
    #ifdef __MMI_CALENDAR_NEW_STYLE__
                switch (PhnsetGetDateFormat())
                {
                    case 0: /* day,month,year */
                    case 1: /* month, day, year */
                        sprintf((S8*)temp_text, "Week%02d%c%04d", applib_dt_get_week_number(&g_cat_calendar_end_time), seperator, g_cat_calendar_end_time.nYear);
                        break;
        #if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
                    default:
                        sprintf((S8*)temp_text, "%04d%cWeek%02d", g_cat_calendar_end_time.nYear, seperator, applib_dt_get_week_number(&g_cat_calendar_end_time));
                        break;
                }
    #else
            if (index == 0)
            {
                sprintf((S8*)temp_text, "Week");
            }
            if (index == 1)
            {
                sprintf((S8*)temp_text, "%2d", applib_dt_get_week_number(&g_cat_calendar_highlight_time));
            }
    #endif /*__MMI_CALENDAR_NEW_STYLE__*/
#endif /*__MMI_TOUCH_SCREEN__*/
    }
#endif /*WEEKLY VIEW*/

  #ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
    if(data == 0)
  #endif
    mmi_asc_to_ucs2((S8*)text, temp_text);

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __MMI_CALENDAR_NEW_STYLE__
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
    #ifndef __MMI_CALENDAR_NEW_STYLE__
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
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif //if 0

 #ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_CALENDAR_HORIZONTAL_SELECT));
    gui_measure_string((UI_string_type)text, &string_width, &string_height);
    gui_set_text_color(*(current_MMI_theme->calendar_horizontal_text_color));
    gui_set_text_border_color(*(current_MMI_theme->calendar_horizontal_border_color));
 #else
    //gui_set_font(&Title_font);//font size;
    gui_set_font(&MMI_medium_font);//20px;
    if(data == 0)
    gui_measure_string((UI_string_type)text, &string_width, &string_height);
	else
		gui_measure_string((UI_string_type)text_chn, &string_width, &string_height);
    gui_set_text_color(gui_color(255, 255, 255));
 #endif/*__SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__*/

    gdi_layer_set_clip(
        cell_x,
        g_cat83_cal_h_select[index].y,
        cell_x + cell_width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
/* under construction !*/
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#else
    string_x = cell_x + ((cell_width - string_width) >> 1);
#endif //if 0

    //if (r2lMMIFlag)
    if(mmi_fe_get_r2l_state())
    {
        string_x += string_width - 1;
    }

    gui_move_text_cursor(
        string_x,
        g_cat83_cal_h_select[index].y + ((g_cat83_cal_h_select[index].height - string_height) >> 1));

 #ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
	if(data == 0)
 #endif
      #ifndef __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
    gui_print_bordered_text((UI_string_type)text);
	  #else
	    //new style;(no border)
	    gui_print_text((UI_string_type)text);
	  #endif/*__ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__*/
 #ifdef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
	else
	  #ifndef __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
		gui_print_bordered_text((UI_string_type)text_chn);
	  #else
	    //new style;(no border)
	    gui_print_text((UI_string_type)text_chn);
	  #endif/*__ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__*/
 #endif
    gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();

    #ifdef __MMI_CALENDAR_NEW_STYLE__
        gdi_layer_blt_previous(
            cell_x,
            g_cat83_cal_h_select[index].y,
            cell_x + cell_width - 1,
            g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
    #endif
    
    gdi_layer_unlock_frame_buffer();  
    
    gdi_layer_blt_previous(
        g_cat83_cal_h_select[index].x,
        g_cat83_cal_h_select[index].y,
        g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
        g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_highlight_change_handler
 * DESCRIPTION
 *  Calendar category highlight change handler.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat83_highlight_change_handler(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time,
             applib_time_struct start_time,
             applib_time_struct end_time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 #if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif
    if (g_cat_calendar_highlight_change_callback != NULL)
    {
        U8 index ;
    #if defined(__MMI_FTE_SUPPORT__)||defined( __MMI_TOUCH_SCREEN__)
        U8 icon_index;
    #endif
        MMI_BOOL change_horizintal_select = MMI_TRUE;
    
    #ifndef __MMI_CALENDAR_NEW_STYLE__
        g_cat_calendar_start_time = start_time;
    #endif
        g_cat_calendar_end_time = end_time;
        g_cat_calendar_highlight_time = highlighted_time;


#ifdef __MMI_CALENDAR_NEW_STYLE__
        index = 0;
#else
        for(index = 0; index < WGUI_CAT_CAL_HORIZONTAL_SELECT_COUNT; index ++)
#endif
        {
            change_horizintal_select = MMI_TRUE;
  #ifndef __ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__
    #if defined(__MMI_FTE_SUPPORT__)||defined( __MMI_TOUCH_SCREEN__)
            for(icon_index = 0; icon_index < WGUI_CAL_H_SELECT_ALLOW_TOTAL; icon_index ++)
            {
            
                if(wgui_cat83_horizintal_select_switch(index, icon_index) == MMI_TRUE)
                {
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_NORMAL;
                }
                else
                {
                    if (g_cat83_cal_h_select[index].icon_info[icon_index].icon_state == GUI_CALENDAR_PEN_STATE_DISABLED)
                    {
                        change_horizintal_select = MMI_FALSE;
                    }
                    g_cat83_cal_h_select[index].icon_info[icon_index].icon_state = GUI_CALENDAR_PEN_STATE_DISABLED;
                }
            }
    #endif /* __MMI_TOUCH_SCREEN__ */
  #endif/*__ASTER_NEW_STYLE_CHANGE_FOR_CALENDAR__*/
        
            if (change_horizintal_select)
            {
                wgui_cat83_draw_horizontal_select(index);            
                gdi_layer_blt_previous(
                    g_cat83_cal_h_select[index].x,
                    g_cat83_cal_h_select[index].y,
                    g_cat83_cal_h_select[index].x + g_cat83_cal_h_select[index].width - 1,
                    g_cat83_cal_h_select[index].y + g_cat83_cal_h_select[index].height - 1);
            }
        }

        if (g_cat_calendar_highlight_change_callback(type, highlighted_time, start_time, end_time) == MMI_FALSE)
        {
            return;
        }
    }

#ifdef __MMI_CLNDR_EVENT_INFO__
    if (g_cat_calendar_event_query_handler != NULL)
    {
    /* Display the cell event. */
    #if defined(__MMI_CLNDR_EVENT_INFO__) && (defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__))
        S32 entry_x, entry_y, entry_width, entry_height;
        S32 icon_x, icon_width, icon_height;
        S32 string_x, string_width, string_height, string_xwidth;
        S32 i;
        applib_time_struct time_interval;
    
        memset(&time_interval, 0, sizeof(applib_time_struct));
        if (type == GUI_CALENDAR_TYPE_MONTH)
        {
            time_interval.nDay = GUI_CALENDAR_MONTH_TIME_INTERVAL;
        }
        if (type == GUI_CALENDAR_TYPE_WEEK)
        {
            time_interval.nHour = GUI_CALENDAR_WEEK_TIME_INTERVAL;
        }
        g_cat_calendar_event_query_handler(
            type,
            highlighted_time,
            time_interval,
            &g_cat_calendar_events);

        entry_width = GUI_CALENDAR_INFOBOX_WIDTH - GUI_CALENDAR_INFOBOX_GAP * 2;
        entry_height = GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
        entry_x = GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_GAP;
        entry_y = GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_GAP;

    gui_set_font(gui_font_get_type(GUI_FONT_SIZE_CALENDAR_INFOBOX));
    gui_set_text_color(*(current_MMI_theme->calendar_infobox_text_color));

    gdi_layer_push_and_set_active(g_cat_calendar_target_layer);
    gdi_layer_push_clip();
    gdi_layer_set_clip(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1);
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer != NULL &&
        g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
    {    
        gdi_effect_alpha_blending_rect(
            g_cat_calendar_abm_layer,
            GUI_CALENDAR_INFOBOX_START_X,
            GUI_CALENDAR_INFOBOX_START_Y,
            GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
            GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1,
            current_MMI_theme->calendar_infobox_bg_alpha * 255 / 100,
            current_MMI_theme->calendar_infobox_bg_color->r,
            current_MMI_theme->calendar_infobox_bg_color->g,
            current_MMI_theme->calendar_infobox_bg_color->b);
    }
    else
    {
#endif /* __GDI_MEMORY_PROFILE_2__ */
	gdi_draw_solid_rect(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1,
        gdi_act_color_from_rgb(
            current_MMI_theme->calendar_infobox_bg_alpha,
            current_MMI_theme->calendar_infobox_bg_color->r,
            current_MMI_theme->calendar_infobox_bg_color->g,
            current_MMI_theme->calendar_infobox_bg_color->b));
#ifdef __GDI_MEMORY_PROFILE_2__
    }
#endif

    for (i = 0; i < g_cat_calendar_events.event_entry_number; i++)
    {
        gdi_layer_push_clip();
        gdi_layer_set_clip(entry_x, entry_y, entry_x + entry_width - 1, entry_y + entry_height - 1);
        gdi_effect_alpha_blending_rect(
            g_cat_calendar_target_layer,
            entry_x,
            entry_y,
            entry_x + entry_width - 1,
            entry_y + entry_height - 1,
            current_MMI_theme->calendar_infobox_entry_alpha * 255 / 100,
            current_MMI_theme->calendar_infobox_entry_bg_color->r,
            current_MMI_theme->calendar_infobox_entry_bg_color->g,
            current_MMI_theme->calendar_infobox_entry_bg_color->b);

        //if (r2lMMIFlag)
        if(mmi_fe_get_r2l_state())
        {
            icon_x = entry_x + entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
        }
        else
        {
            icon_x = entry_x;
        }
        string_x = icon_x;
        if(g_cat_calendar_events.entry_list[i].icon != 0)
        {
            gdi_handle h0, h1, h2, h3;

            gdi_image_get_dimension_id(
                (U16)g_cat_calendar_events.entry_list[i].icon,
                &icon_width,
                &icon_height);
            gdi_layer_push_clip();
            gdi_layer_set_clip(
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_height) >> 1),
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1) + icon_width - 1,
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_height) >> 1) + icon_height - 1);
            gdi_layer_get_blt_layer(&h0, &h1, &h2, &h3);
            gdi_layer_flatten_with_clipping(h0, h1, h2, h3);
            gdi_push_and_set_alpha_blending_source_layer(g_cat_calendar_target_layer);
            gdi_image_draw_id(
                icon_x + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - icon_width) >> 1),
                (U16) g_cat_calendar_events.entry_list[i].icon);
            gdi_pop_and_restore_alpha_blending_source_layer();
            gdi_layer_pop_clip();
            //if (!r2lMMIFlag)
            if(!mmi_fe_get_r2l_state())
            {
                string_x += GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
            }
        }
        else
        {
            icon_width = 0;
            icon_height = 0;
        }

        if (g_cat_calendar_events.entry_list[i].string != NULL &&
            UI_strlen((UI_string_type)(g_cat_calendar_events.entry_list[i].string)) > 0)
        {
            if(g_cat_calendar_events.entry_list[i].string != NULL)
            {
                gui_measure_string(
                    (UI_string_type)g_cat_calendar_events.entry_list[i].string,
                    &string_width,
                    &string_height);
                    string_xwidth = entry_width - GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT;
                gui_print_truncated_text(
                    string_x,
                    entry_y + ((GUI_CALENDAR_INFOBOX_ENTRY_HEIGHT - string_height) >> 1),
                    string_xwidth, 
                    (UI_string_type)g_cat_calendar_events.entry_list[i].string);
            }
        }
        
        entry_y += entry_height + GUI_CALENDAR_INFOBOX_GAP;
        gdi_layer_pop_clip();
    }
    gdi_layer_pop_clip();
    gdi_layer_pop_and_restore_active();
    gdi_layer_blt_previous(
        GUI_CALENDAR_INFOBOX_START_X,
        GUI_CALENDAR_INFOBOX_START_Y,
        GUI_CALENDAR_INFOBOX_START_X + GUI_CALENDAR_INFOBOX_WIDTH - 1,
        GUI_CALENDAR_INFOBOX_START_Y + GUI_CALENDAR_INFOBOX_HEIGHT - 1);
#endif /* defined(__MMI_MAINLCD_240X320__) || defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) */
    }
#endif /*__MMI_CLNDR_EVENT_INFO__*/
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif
}



/*****************************************************************************
 * FUNCTION
 *  ExitCategory83Screen
 * DESCRIPTION
 *  exit function of category83
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory83Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
/* under construction !*/
#endif
    reset_softkeys();

    wgui_calendar_close();

#ifdef __MMI_CALENDAR_EVENT__
    g_cat_calendar_cell_data_query_handler = NULL;
#endif
    g_cat_calendar_cell_lunar_query_handler = NULL;
#ifdef __MMI_CLNDR_EVENT_INFO__
    g_cat_calendar_event_query_handler = NULL;
#endif
    g_cat_calendar_highlight_change_callback = NULL;
#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
#endif
#endif

    /* Free event entry of calendar. */
    for (i = 0; i < WGUI_CAT_CAL_EVENT_ENTRY_NUM; i++)
    {
        if (g_cat_calendar_events.entry_list[i].string != NULL)
        {
            mmi_frm_scrmem_free(g_cat_calendar_events.entry_list[i].string);
            g_cat_calendar_events.entry_list[i].string = NULL;
	    g_cat_calendar_events.entry_list[i].icon = NULL;
        }
    }
    g_cat_calendar_events.event_entry_number = 0;
    g_cat_calendar_events.event_string_max_length = 0;

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #ifndef __MMI_CALENDAR_NEW_STYLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

    g_cat_calendar_type = GUI_CALENDAR_TYPE_NONE;
#ifdef __GDI_MEMORY_PROFILE_2__
    g_cat_calendar_abm_layer = NULL;
#endif
    g_cat_calendar_target_layer = NULL;
    g_cat_calendar_bg_id = IMAGE_ID_NULL;
#if 0
/* under construction !*/
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83HistorySize
 * DESCRIPTION
 *  Gets the history buffer size of category 83
 * PARAMETERS
 *  void
 * RETURNS
 *  size in U8s of the history buffer
 *****************************************************************************/
S32 GetCategory83HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_EVENT__
    return wgui_calendar_get_history_size();
#else
    return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  GetCategory83History
 * DESCRIPTION
 *  Gets the history buffer of category 83
 * PARAMETERS
 *  history_buffer      [?]     
 * RETURNS
 *  return history buffer
 *****************************************************************************/
U8 *GetCategory83History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_CALENDAR_EVENT__
    if (GUI_CALENDAR_TYPE_WEEK == g_cat_calendar_type)
    {
        wgui_calendar_get_history(MMI_CATEGORY83_ID, history_buffer);
    }
#endif
    return (history_buffer);
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
#if !defined (__MMI_MAINLCD_128X128__)
/* under construction !*/
#endif
/* under construction !*/
#endif

#ifdef __MMI_CALENDAR_EVENT__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_cell_data_query_handler
 * DESCRIPTION
 *  Register cell data query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell data query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_cell_data_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct start_time,
            applib_time_struct end_time,
            applib_time_struct interval,
            S32 query_count,
            gui_calendar_cell_struct *cells))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_cell_data_query_handler = f;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_cell_lunar_query_handler
 * DESCRIPTION
 *  Register cell lunar query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell lunar query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_cell_lunar_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct cell_time,
            applib_time_struct time_interval,
            PU8 title,
            U32 title_length,
            gui_calendar_cell_detail_info_struct *detail_info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_cell_lunar_query_handler = f;
}

#ifdef __MMI_CLNDR_EVENT_INFO__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_event_query_handler
 * DESCRIPTION
 *  Register cell event query handler.
 * PARAMETERS
 *  f           [IN]    Is the cell event query handler.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_event_query_handler(
      S32 (*f)(
            gui_calendar_type_enum type,
            applib_time_struct cell_time,
            applib_time_struct time_interval,
            wgui_cat83_event_struct *event_info))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_event_query_handler = f;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_highlight_change_callback
 * DESCRIPTION
 *  Register highlight select callback.
 * PARAMETERS
 *  f           [IN]    Is the highlight change callback.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_highlight_change_callback(
          MMI_BOOL (*f)(
                gui_calendar_type_enum type,
                applib_time_struct highlighted_time,
                applib_time_struct start_time,
                applib_time_struct end_time))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_cat_calendar_highlight_change_callback = f;
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_register_highlight_select_callback
 * DESCRIPTION
 *  Register highlight select callback.
 * PARAMETERS
 *  f           [IN]    Is the highlight select callback.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_register_highlight_select_callback(
      void (*f)(
             gui_calendar_type_enum type,
             applib_time_struct highlighted_time))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //g_cat_calendar_highlight_select_callback = f;
    wgui_calendar_register_highlight_select_function(f);
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
#endif
#endif /* __MMI_TOUCH_SCREEN__ */


/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_handle_control_area
 * DESCRIPTION
 *  This function is only set the layers to calendar component.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_handle_control_area(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GDI_MEMORY_PROFILE_2__
    if (g_cat_calendar_abm_layer == NULL)
    {
        g_cat_calendar_abm_layer = dm_get_scr_bg_layer();
        if (g_cat_calendar_abm_layer != NULL &&
            g_cat_calendar_abm_layer != GDI_ERROR_HANDLE)
        {
            wgui_calendar_set_abm_layer(g_cat_calendar_abm_layer);
        }
    }
#endif
    if (g_cat_calendar_target_layer == NULL)
    {
        gdi_layer_get_base_handle(&g_cat_calendar_target_layer);
        if (g_cat_calendar_target_layer != NULL &&
            g_cat_calendar_target_layer != GDI_ERROR_HANDLE)
        {
            wgui_calendar_set_target_layer(g_cat_calendar_target_layer);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ShowCategory83Screen
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id               [IN]    Is the background of calendar.
 *  type                [IN]    Is the type of calendar.
 *  max_date            [IN]    Is the max date to display.
 *  min_date            [IN]    Is the min date to display.
 *  show_date           [IN]    Is the date to show.
 *  str_LeftSoftkey     [IN]    The string of left softkey.
 *  str_rightSoftkey    [IN]    The string of right softkey.
 * RETURNS
 *  void
 *****************************************************************************/
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
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 dm_data_flags = DM_CLEAR_SCREEN_BACKGROUND;
    S32 i;
#if 0
/* under construction !*/
/* under construction !*/
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetupCategoryKeyHandlers();

    /* Create calendar component. */
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif
    /* Create the memory of event info. */
    for (i = 0; i < WGUI_CAT_CAL_EVENT_ENTRY_NUM; i++)
    {
        g_cat_calendar_events.entry_list[i].string = (U8*)mmi_frm_scrmem_alloc(WGUI_CAT_CAL_EVENT_ENTRY_SIZE);
		MMI_DBG_ASSERT(g_cat_calendar_events.entry_list[i].string != NULL);
		memset(g_cat_calendar_events.entry_list[i].string, 0, WGUI_CAT_CAL_EVENT_ENTRY_SIZE);
    }
    g_cat_calendar_events.event_entry_number = WGUI_CAT_CAL_EVENT_ENTRY_NUM;
    g_cat_calendar_events.event_string_max_length = WGUI_CAT_CAL_EVENT_STRING_MAX_LENGTH * ENCODING_LENGTH;
#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

    /* Record the max / min time and highlight time. */
    g_cat_calendar_type = type;
    g_cat_calendar_max_time = max_date;
    g_cat_calendar_min_time = min_date;
    g_cat_calendar_highlight_time = show_date;

    wgui_calendar_create(
        g_cat_calendar_type,
        max_date,
        min_date,
        show_date,
        flag);
    wgui_calendar_set_key_handler();

#ifdef __MMI_CALENDAR_EVENT__
    if (history_buffer != NULL)
    {
        wgui_calendar_set_history(MMI_CATEGORY83_ID, history_buffer);
    }

    if (g_cat_calendar_cell_data_query_handler != NULL)
    {
        wgui_calendar_register_cell_data_query_handler(
            g_cat_calendar_cell_data_query_handler);
    }
#endif
    if (g_cat_calendar_cell_lunar_query_handler != NULL)
    {
        wgui_calendar_register_cell_detail_query_handler(
            g_cat_calendar_cell_lunar_query_handler);
    }
    wgui_calendar_register_highlight_change_function(
        wgui_cat83_highlight_change_handler);

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

#ifdef __MMI_CALENDAR_EVENT__
    if (type == GUI_CALENDAR_TYPE_WEEK)
    {
        wgui_calendar_set_flags_on(GUI_CALENDAR_WEEK_DISPLAY_WEEKDAY_DATE_ONE_LINE);
    #if defined(__MMI_MAINLCD_128X128__) || defined(__MMI_MAINLCD_128X160__) || defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)
        wgui_calendar_set_flags_on(GUI_CALENDAR_WEEK_HIDE_WEEKDAY_STRING);
    #endif
    }
#endif

#if 0
#ifdef __MMI_TOUCH_SCREEN__
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
#endif

/*init horizontal select */
    wgui_cat83_init_horizontal_select();  

    gdi_layer_lock_frame_buffer();
    if (bg_id != NULL)
    {
        dm_set_scr_bg_image(bg_id, NULL, 0, 0, 255);
        g_cat_calendar_bg_id = bg_id;
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    gdi_layer_unlock_frame_buffer();
    dm_register_category_controlled_callback(wgui_cat83_handle_control_area);
#ifdef __MMI_TOUCH_SCREEN__
  #ifndef __SWATCCH_FOR_CALENDAR_MONTHLY_VIEW_SLIM__
    //remove prev/next icon pen event;
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_down_hdlr, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_up_hdlr, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_move_hdlr, MMI_PEN_EVENT_MOVE);
    wgui_register_category_screen_control_area_pen_handlers(wgui_cat83_pen_abort_hdlr, MMI_PEN_EVENT_ABORT);
  #else
    //add pen move prev/next switch handle;
    //only icon area is valid,not full screen area;
    //register a NULL wgui_cat83_for_swatch_pen_move_hdlr func; clear FW wgui general pen move hdlr;
    mmi_pen_register_move_handler(wgui_cat83_for_swatch_pen_move_hdlr);
  
    mmi_pen_register_down_handler(wgui_cat83_for_swatch_pen_down_hdlr);
    mmi_pen_register_up_handler(wgui_cat83_for_swatch_pen_up_hdlr);
  #endif
#endif /* __MMI_TOUCH_SCREEN__ */

    set_left_softkey_label((UI_string_type)str_LeftSoftkey);
    set_right_softkey_label((UI_string_type)str_rightSoftkey);

    if (is_status_bar == MMI_FALSE)
    {
        dm_data_flags |= DM_NO_STATUS_BAR;
    }
    
    wgui_cat_setup_category(MMI_CATEGORY83_ID, dm_data_flags, ExitCategory83Screen, GetCategory83History, GetCategory83HistorySize);
    dm_redraw_category_screen();
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#if defined(__MMI_FTE_SUPPORT__)&&defined(__MMI_TOUCH_SCREEN__)&&defined(__MMI_ICON_BAR_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  ShowCategory83Screen
 * DESCRIPTION
 *  category screen of integrated calendar (monthly/weekly and menstral)
 * PARAMETERS
 *  bg_id                       [IN]        
 *  horizon_string_list         [IN]        Horizontal string list
 *  cell                        [IN]        2 dimension cell array
 *  num_of_row                  [IN]        Number of row
 *  num_of_column               [IN]        Number of column
 *  current_row                 [IN]        Row of current time
 *  current_column              [IN]        Column of current time
 *  highlighted_row             [IN]        Highlighted row
 *  highlighted_column          [IN]        Highlighted column
 *  is_status_bar               [IN]  
 *  item_count                  [IN]
 *  resource_array              [IN]
 *  callback                    [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat9004_show(
      UI_image_ID_type bg_id,
      gui_calendar_type_enum type,
      applib_time_struct max_date,
      applib_time_struct min_date,
      applib_time_struct show_date,
      MMI_BOOL is_status_bar,
      U8 *str_LeftSoftkey,
      U8 *str_rightSoftkey,
      S32 item_count,
      gui_icon_bar_item_resource_struct *resource_array,
      GUIIconbarItemCallback callback,
      MMI_BOOL *icon_bar_enable_state,
      U8 *history_buffer,
      U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__)
    S32 i;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__)
    wgui_icon_bar_setup_by_resource(
        item_count,
        resource_array,
        callback);
    for(i = 0; i < item_count; i++)
    {
        wgui_icon_bar_set_item_enable_state(i, icon_bar_enable_state[i]);
    }
#endif /* __MMI_MAINLCD_320X480__ */
    
    ShowCategory83Screen(
        bg_id,
        type,
        max_date,
        min_date,
        show_date,
        is_status_bar,
        str_LeftSoftkey,
        str_rightSoftkey,
        history_buffer,
        flag);
}
#endif /* defined(__MMI_FTE_SUPPORT__)&&defined(__MMI_TOUCH_SCREEN__)&&defined(__MMI_ICON_BAR_SUPPORT__)*/

#if 0
#ifdef __MMI_MENSTRUAL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_CALENDAR_NEW_STYLE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MENSTRUAL__ */
#endif

/*****************************************************************************
 * FUNCTION
 *  wgui_cat83_refresh_events_reminder
 * DESCRIPTION
 *  Update calendar events reminder.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat83_refresh_events_reminder(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    wgui_calendar_update();
}


