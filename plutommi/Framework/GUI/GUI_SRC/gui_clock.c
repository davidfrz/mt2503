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
 *  gui_clock.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Clock - UI component
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

 
/*
 * This file contains internal UI component API, and is intended to be used by category screen module only. 
 * It's not recommended to be included in application code directly. 
 * For application developers, please include category screen header files instead (e.g., wgui_categories.h).
*/

#include "MMIDataType.h"
#include "CustDataRes.h"
#include "kal_release.h"
#include "DateTimeType.h"

#include "stdio.h"
#include "Unicodexdcl.h"

#include "MMI_trc_Int.h"

#include "mmi_rp_app_uiframework_def.h"
#include "custom_mmi_default_value.h"

#include "gui.h"
#include "wgui.h"
#include "gui_switch.h"
#include "gui_clock.h"
#include "gdi_include.h"
#include "wgui_categories_util.h"

#include "ImeGprot.h"

#define GUI_CLOCK_GAP_TIME_DATE_TWO_LINE                5
#define GUI_CLOCK_GAP_TIME_DATE_ONE_LINE                10
#ifdef __MMI_ANALOG_CLOCK__
#define GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS       0
#define GUI_CLOCK_ANALOG_CLOCK_SMOOTHEN_LINES           1
#endif

/* for R2L characters */

/*for language*/
extern pBOOL IsChineseSet(void);

/*for get date & time format*/
extern U8 PhnsetGetDateFormat(void);
extern U8 PhnsetGetDateSeperatorFormat(void);
extern U8 PhnsetGetTimeFormat(void);

#if defined(__IOT__)
U8 PhnsetGetDateFormat(void) 
{
    return (U8)srv_setting_get_date_format();
}

U8 PhnsetGetTimeFormat(void)
{
    return (U8)srv_setting_get_time_format();
}
#endif

/*for theme of clock*/
UI_clock_theme *current_clock_theme = NULL;

#ifdef __MMI_ANALOG_CLOCK__
/*analog's left top*/
static S32 g_gui_clock_analog_clock_dial_x;
static S32 g_gui_clock_analog_clock_dial_y;
/*analog's center coordinate*/
static S32 g_gui_clock_analog_clock_center_x;
static S32 g_gui_clock_analog_clock_center_y;
/*analog's hand counter*/
static S32 g_gui_clock_analog_clock_hours_hand_counter = 0;
static S32 g_gui_clock_analog_clock_minutes_hand_counter = 0;

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
/*analog's left top in sub lcd*/
S32 g_gui_clock_sub_lcd_analog_clock_dial_x = 2;
S32 g_gui_clock_sub_lcd_analog_clock_dial_y = 2;
/*analog's center coordinate in sub lcd*/
S32 g_gui_clock_sub_lcd_analog_clock_center_x = SUB_LCD_DEVICE_WIDTH >> 1;
S32 g_gui_clock_sub_lcd_analog_clock_center_y = SUB_LCD_DEVICE_HEIGHT >> 1;
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

static const FLOAT g_gui_clock_acm_sine_table[] = 
{
    (FLOAT) - 0.99999820, (FLOAT) - 0.99431727, (FLOAT) - 0.97773360, (FLOAT) - 0.95042917,
        (FLOAT) - 0.91270313,
        (FLOAT)-0.86496924, (FLOAT)-0.80775119, (FLOAT)-0.74167587,
    (FLOAT) - 0.66746803, (FLOAT) - 0.58594175, (FLOAT) - 0.49799022, (FLOAT) - 0.40457821,
        (FLOAT) - 0.30673042,
        (FLOAT)-0.20551889, (FLOAT)-0.10205382, (FLOAT)0.00000000,
    (FLOAT) 0.10457040, (FLOAT) 0.20799418, (FLOAT) 0.30913729, (FLOAT) 0.40689072, (FLOAT) 0.50018258,
        (FLOAT) 0.58798990,
        (FLOAT)0.66934994, (FLOAT)0.74337050,
    (FLOAT) 0.80923998, (FLOAT) 0.86623616, (FLOAT) 0.91373403, (FLOAT) 0.95121274, (FLOAT) 0.97826142,
        (FLOAT) 0.99458343,
        (FLOAT)0.99999980, (FLOAT)0.99445115,
    (FLOAT) 0.97799831, (FLOAT) 0.95082172, (FLOAT) 0.91321931, (FLOAT) 0.86560342, (FLOAT) 0.80849624,
        (FLOAT) 0.74252372,
        (FLOAT)0.66840956, (FLOAT)0.58696629,
    (FLOAT) 0.49908672, (FLOAT) 0.40573486, (FLOAT) 0.30793410, (FLOAT) 0.20675662, (FLOAT) 0.10331227,
        (FLOAT) - 0.00126490,
        (FLOAT)-0.10582843, (FLOAT)-0.20923132,
    (FLOAT) - 0.31033998, (FLOAT) - 0.40804598, (FLOAT) - 0.50127753, (FLOAT) - 0.58901256,
        (FLOAT) - 0.67028925,
        (FLOAT)-0.74421601, (FLOAT)-0.80998244, (FLOAT)-0.86686752,
    (FLOAT)-0.91424734, (FLOAT)-0.95160225, (FLOAT)-0.97852297, (FLOAT)-0.99471414,
};

static const FLOAT g_gui_clock_acm_cosine_table[] = 
{
    (FLOAT) 0.00189735, (FLOAT) 0.10645731, (FLOAT) 0.20984996, (FLOAT) 0.31094114, (FLOAT) 0.40862330,
        (FLOAT) 0.50182489,
        (FLOAT)0.58952354, (FLOAT)0.67075845,
    (FLOAT) 0.74463846, (FLOAT) 0.81035318, (FLOAT) 0.86718264, (FLOAT) 0.91450340, (FLOAT) 0.95179643,
        (FLOAT) 0.97865315,
        (FLOAT)0.99477888, (FLOAT)1.00000000,
    (FLOAT) 0.99451749, (FLOAT) 0.97813006, (FLOAT) 0.95101742, (FLOAT) 0.91347684, (FLOAT) 0.86591997,
        (FLOAT) 0.80886827,
        (FLOAT)0.74294728, (FLOAT)0.66887989,
    (FLOAT) 0.58747821, (FLOAT) 0.49963478, (FLOAT) 0.40631283, (FLOAT) 0.30853576, (FLOAT) 0.20737548,
        (FLOAT) 0.10394131,
        (FLOAT)-0.00063245, (FLOAT)-0.10519940,
    (FLOAT) - 0.20861283, (FLOAT) - 0.30973870, (FLOAT) - 0.40746839, (FLOAT) - 0.50073018,
        (FLOAT) - 0.58850135,
        (FLOAT)-0.66981977, (FLOAT)-0.74379342, (FLOAT)-0.80961137,
    (FLOAT) - 0.86655204, (FLOAT) - 0.91399082, (FLOAT) - 0.95140769, (FLOAT) - 0.97839241,
        (FLOAT) - 0.99464897,
        (FLOAT)-0.99999920, (FLOAT)-0.99438440, (FLOAT)-0.97786617,
    (FLOAT) - 0.95062563, (FLOAT) - 0.91296138, (FLOAT) - 0.86528656, (FLOAT) - 0.80812388,
        (FLOAT) - 0.74209994,
        (FLOAT)-0.66793902, (FLOAT)-0.58645414, (FLOAT)-0.49853857,
    (FLOAT)-0.40515651, (FLOAT)-0.30733233, (FLOAT)-0.20613779, (FLOAT)-0.10268295,
};

#if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
extern void flat_triangle_fill(polygon_vertex vertices[], color c);
extern void polygon_draw(polygon_vertex vertices[], S32 n_vertices, color c);
#elif(GUI_CLOCK_ANALOG_CLOCK_SMOOTHEN_LINES)
extern void UI_antialiased_line(S32 x1, S32 y1, S32 x2, S32 y2, color c);
#endif 

#endif /*__MMI_ANALOG_CLOCK__*/
#if defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
static void gui_clock_show_digital_image(
             gui_clock_struct *c,
             applib_time_struct *time_to_show);
#endif /* __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__ */
static void gui_clock_show_digital_small_image(
             gui_clock_struct *c,
             applib_time_struct *time_to_show);
/* add gui_clock_default_hide_function for orange, need verify for datetime */
/*
 * static void gui_clock_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2);
 */
/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_current_theme
 * DESCRIPTION
 *  set the theme of clock
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_current_theme(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    if (c->type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
        c->type < GUI_CLOCK_MAINLCD_TYPE_END)
    {
        c->date_text_font = current_clock_theme->date_text_font;
        c->time_text_font = current_clock_theme->time_text_font;
    }
#ifdef __MMI_SUBLCD__
    if (c->type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
        c->type < GUI_CLOCK_SUBLCD_TYPE_END)
    {
        c->date_text_font = current_clock_theme->date_text_font_sub_lcd;
        c->time_text_font = current_clock_theme->time_text_font_sub_lcd;
    }
#endif /* __MMI_SUBLCD__ */

    c->date_text_color = current_clock_theme->date_text_color;
    c->date_text_border_color = current_clock_theme->date_text_border_color;
    c->time_text_color = current_clock_theme->time_text_color;
    c->time_text_border_color = current_clock_theme->time_text_border_color;
#ifdef __MMI_ANALOG_CLOCK__
    c->analog_hand_hour_color = current_clock_theme->analog_hand_hour_color;
    c->analog_hand_min_color = current_clock_theme->analog_hand_min_color;
    c->analog_axis_color = current_clock_theme->analog_axis_color;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_theme
 * DESCRIPTION
 *  set a specific theme
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  t       [IN]        Pointer of new theme
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_theme(gui_clock_struct *c, UI_clock_theme *t)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    for (i = 0; i < WGUI_CLOCK_MAX_ITEMS; i++)
    {
        if (c[i].type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
            c[i].type < GUI_CLOCK_MAINLCD_TYPE_END)
        {
            c[i].date_text_font = t->date_text_font;
            c[i].time_text_font = t->time_text_font;
        }
    #ifdef __MMI_SUBLCD__
        if (c[i].type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
            c[i].type < GUI_CLOCK_SUBLCD_TYPE_END)
        {
            c[i].date_text_font = t->date_text_font_sub_lcd;
            c[i].time_text_font = t->time_text_font_sub_lcd;
        }
    #endif /* __MMI_SUBLCD__ */
        c[i].date_text_color = t->date_text_color;
        c[i].date_text_border_color = t->date_text_border_color;
        c[i].time_text_color = t->time_text_color;
        c[i].time_text_border_color = t->time_text_border_color;
    #ifdef __MMI_ANALOG_CLOCK__
        c[i].analog_hand_hour_color = t->analog_hand_hour_color;
        c[i].analog_hand_min_color = t->analog_hand_min_color;
        c[i].analog_axis_color = t->analog_axis_color;
    #endif
    }

}


#if defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
/*****************************************************************************
 * FUNCTION
 *  gui_clock_show_digital_image
 * DESCRIPTION
 *  get the width and height of digital clock that using image
 * PARAMETERS
 *  c                   [IN]        Pointer of clock component
 *  time_to_show        [IN]        pointer of time struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_show_digital_image(
             gui_clock_struct *c,
             applib_time_struct *time_to_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height, num_width, num_height;
    S32 colon_width, colon_height, am_width, am_height;
    U16 hours, minutes;
    U16 num1, num2, image = GDI_NULL_HANDLE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_clip();
    gui_set_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
    if (c->hide_callback != NULL)
    {
        c->hide_callback(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
    }
    else
    {	
        gdi_draw_solid_rect(
            c->x,
            c->y,
            c->x + c->width -1,
            c->y + c->height -1,
            GDI_COLOR_TRANSPARENT);
    }

    hours = time_to_show->nHour;
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    if (c->on_idle)
    {
    /* show day/night background */
    gui_set_clip(
        DIGITAL_BACKGROUND_X,
        DIGITAL_BACKGROUND_Y,
        DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH - 1,
        DIGITAL_BACKGROUND_Y + DIGITAL_BACKGROUND_HEIGHT - 1);
    #ifdef __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__
        if (hours >= 6 && hours <= 18)
        {
            image = IMG_TECHNO_DIGITAL_CLOCK_DAY_BACKGROUND;
        }
        else
        {
            image = IMG_TECHNO_DIGITAL_CLOCK_NIGHT_BACKGROUND;
        }
        gdi_image_draw_id(
            DIGITAL_BACKGROUND_X,
            DIGITAL_BACKGROUND_Y,
            image);
    #else /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
        gdi_image_draw_id(
            DIGITAL_BACKGROUND_X,
            DIGITAL_BACKGROUND_Y,
            IMG_TECHNO_DIGITAL_CLOCK);
    #endif /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
    }
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */

    gui_set_clip(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
    /* measure clock's width */
    gui_clock_measure_digital_clock(c, &width, &height);
    gdi_image_get_dimension_id(
            IMG_TECHNO_DIGITAL_CLOCK_0,
            &num_width,
            &num_height);
    /* calculate pos of first image */
    if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_LEFT)
    {
        x = c->x;
    }
    else if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_RIGHT)
    {
        x = (c->x + c->width - 1) - width;
    }
    else
    {
        x = c->x + c->width / 2 - width / 2;
    }
    y = c->y + (c->height / 2 - height / 2);

    /* show digital clock's image */
    if (PhnsetGetTimeFormat()) /* get current time format */
    {
        num1 = hours / 10;
        num2 = hours - num1 * 10;
    }
    else
    {
        if (hours == 12)
        {
            num1 = hours / 10;
            num2 = hours - num1 * 10;
            image = IMG_TECHNO_DIGITAL_CLOCK_PM;
        }
        else if(hours == 0)
        {
            num1 = 12 / 10;
            num2 = 12 - 10;
            image = IMG_TECHNO_DIGITAL_CLOCK_AM;
        }
        else if(hours > 12)
        {
            num1 = (hours - 12) / 10;
            num2 = (hours - 12) - num1 * 10;
            image = IMG_TECHNO_DIGITAL_CLOCK_PM;
        }
        else
        {
            num1 = hours / 10;
            num2 = hours - num1 * 10;
            image = IMG_TECHNO_DIGITAL_CLOCK_AM;
        }
    }
    
    /* show hour image */
    /* first num of hour */
    gdi_image_draw_id(x, y, (U16)(IMG_TECHNO_DIGITAL_CLOCK_0 + num1));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* second num of hour */
    gdi_image_draw_id(x, y, (U16)(IMG_TECHNO_DIGITAL_CLOCK_0 + num2));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* : */
    /* measure colon */
    gdi_image_get_dimension_id(
        IMG_TECHNO_DIGITAL_CLOCK_COLON,
        &colon_width,
        &colon_height);
    gdi_image_draw_id(x, y, IMG_TECHNO_DIGITAL_CLOCK_COLON);
    x += colon_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    
    minutes = time_to_show->nMin;
    /* calculate hour's show number */
    num1 = minutes / 10;
    num2 = minutes - num1 * 10;
    
    /* show minute image */
    /* first num of minute */
    gdi_image_draw_id(x, y, (U16)(IMG_TECHNO_DIGITAL_CLOCK_0 + num1));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* second num of minute */
    gdi_image_draw_id(x, y, (U16)(IMG_TECHNO_DIGITAL_CLOCK_0 + num2));

    if (!PhnsetGetTimeFormat())
    {
        x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
        gdi_image_get_dimension_id(
            IMG_TECHNO_DIGITAL_CLOCK_AM,
            &am_width,
            &am_height);
        y += num_height - am_height;
        gdi_image_draw_id(x, y, image);
    }
    gui_pop_clip();
}
#endif /* __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__ */


/*****************************************************************************
 * FUNCTION
 *  gui_clock_show_digital_small_image
 * DESCRIPTION
 *  get the width and height of digital clock that using small image
 * PARAMETERS
 *  c                   [IN]        Pointer of clock component
 *  time_to_show        [IN]        pointer of time struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_show_digital_small_image(
             gui_clock_struct *c,
             applib_time_struct *time_to_show)
{
#ifdef __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, width, height, num_width, num_height;
    S32 colon_width, colon_height, am_width, am_height;
    U16 hours, minutes;
    U16 num1, num2, image = GDI_NULL_HANDLE;
    GDI_RESULT result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    result = gdi_image_get_dimension_id(
                 IMG_TECHNO_DIGITAL_SMALL_CLOCK_0,
                 &num_width,
                 &num_height);
    if (result != GDI_SUCCEED)
    {
        return;
    }

    gui_push_clip();
	
    gui_set_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
	if (c->hide_callback != NULL)
	{
		c->hide_callback(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
	}
	else
	{	
        gdi_draw_solid_rect(
            c->x,
            c->y,
            c->x + c->width -1,
            c->y + c->height -1,
            GDI_COLOR_TRANSPARENT);
	}
    
    hours = time_to_show->nHour;

    /* measure clock's width */
    gui_clock_measure_digital_small_clock(c, &width, &height);

    /* calculate pos of first image */
    if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_LEFT)
    {
        x = c->x;
    }
    else if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_RIGHT)
    {
        x = (c->x + c->width - 1) - width;
    }
    else
    {
        x = c->x + c->width / 2 - width / 2;
    }
    y = c->y + (c->height >> 1) - (height >> 1) - (height % 2 == 0 ? 0 : 1);

    /* show digital clock's image */
    if (PhnsetGetTimeFormat()) /* get current time format */
    {
        num1 = hours / 10;
        num2 = hours - num1 * 10;
    }
    else
    {
        if (hours == 12)
        {
            num1 = hours / 10;
            num2 = hours - num1 * 10;
            image = IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM;
        }
        else if(hours == 0)
        {
            num1 = 12 / 10;
            num2 = 12 - 10;
            image = IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM;
        }
        else if(hours > 12)
        {
            num1 = (hours - 12) / 10;
            num2 = (hours - 12) - num1 * 10;
            image = IMG_TECHNO_DIGITAL_SMALL_CLOCK_PM;
        }
        else
        {
            num1 = hours / 10;
            num2 = hours - num1 * 10;
            image = IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM;
        }
    }
    
    /* show hour image */
    /* first num of hour */
    gdi_image_draw_id_blend2layers(x, y, (U16)(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0 + num1));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* second num of hour */
    gdi_image_draw_id_blend2layers(x, y, (U16)(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0 + num2));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* : */
    /* measure colon */
    gdi_image_get_dimension_id(
        IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON,
        &colon_width,
        &colon_height);
    gdi_image_draw_id_blend2layers(x, y, IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON);
    x += colon_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    
    minutes = time_to_show->nMin;
    /* calculate hour's show number */
    num1 = minutes / 10;
    num2 = minutes - num1 * 10;
    
    /* show minute image */
    /* first num of minute */
    gdi_image_draw_id_blend2layers(x, y, (U16)(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0 + num1));
    x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
    /* second num of minute */
    gdi_image_draw_id_blend2layers(x, y, (U16)(IMG_TECHNO_DIGITAL_SMALL_CLOCK_0 + num2));

    if (!PhnsetGetTimeFormat())
    {
        x += num_width + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;
        gdi_image_get_dimension_id(
            IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM,
            &am_width,
            &am_height);
        y += num_height - am_height;
        gdi_image_draw_id_blend2layers(x, y, image);
    }
    gui_pop_clip();
#endif /* __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__ */
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_get_clock_show_time
 * DESCRIPTION
 *  get the show time
 * PARAMETERS
 *  c                   [IN]        Pointer of clock component
 *  time_to_show        [OUT]       Time to show
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_get_clock_show_time(gui_clock_struct *c,applib_time_struct *time_to_show)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    applib_time_struct t;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    MMI_DBG_ASSERT(time_to_show != NULL);
    
    applib_dt_get_date_time(&t);

    if (c->time_compare == DT_TIME_LESS)
    {
        applib_time_struct temp;
        temp = c->diff;
        applib_dt_increase_time(&t, &temp, time_to_show);
    }
    else if (c->time_compare == DT_TIME_GREATER)
    {
        applib_time_struct temp;
        temp = c->diff;
        applib_dt_decrease_time(&t, &temp, time_to_show);
    }
    else
    {
        applib_dt_get_date_time(time_to_show);
    }

}

#ifdef __MMI_ANALOG_CLOCK__

/*****************************************************************************
 * FUNCTION
 *  gui_clock_analog_clock_initialize
 * DESCRIPTION
 *  initialize the clock before display
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_analog_clock_initialize(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    applib_time_struct time_to_show;
    S32 h, m;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    g_gui_clock_sub_lcd_analog_clock_dial_x =c->x ;
    g_gui_clock_sub_lcd_analog_clock_dial_y = c->y;
    g_gui_clock_sub_lcd_analog_clock_center_x = c->x + (c->width>> 1);
    g_gui_clock_sub_lcd_analog_clock_center_y = (c->y + (c->height >> 1));
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    g_gui_clock_analog_clock_center_x = c->x + (c->width>> 1) + 1;
    g_gui_clock_analog_clock_dial_x = c->x;
    g_gui_clock_analog_clock_center_y = (c->y + (c->height >> 1)) + 1;
    g_gui_clock_analog_clock_dial_y = (c->y);

    gui_clock_get_clock_show_time(c, &time_to_show);
            
    m = time_to_show.nMin;
    g_gui_clock_analog_clock_minutes_hand_counter = m;
    h = time_to_show.nHour;
    h++;
    
    if (h > 12)
    {
        h -= 12;
    }
    g_gui_clock_analog_clock_hours_hand_counter = (h - 1) * 5;
    g_gui_clock_analog_clock_hours_hand_counter += m / 12;

}
#endif /*__MMI_ANALOG_CLOCK__*/

/*****************************************************************************
 * FUNCTION
 *  gui_clock_create
 * DESCRIPTION
 *  create a clock component
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  x          [IN]        Start x posiion
 *  y       [IN]        Start y position
 *  width           [IN]        Width of clock
 *  height          [IN]        Height of clock
 *  clock_type      [IN]        Type of clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_create(gui_clock_struct *c, S32 x, S32 y, S32 width, S32 height, gui_clock_type_enum clock_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle sub_handle;
    gdi_handle act_lcd_handle;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (clock_type >= GUI_CLOCK_TYPE_END_OF_ENUM || c->active == MMI_TRUE)
    {
        return;
    }

    if (!(clock_type > GUI_CLOCK_MAINLCD_TYPE_BEGIN &&
          clock_type < GUI_CLOCK_MAINLCD_TYPE_END)
#ifdef __MMI_SUBLCD__
        && !(clock_type > GUI_CLOCK_SUBLCD_TYPE_BEGIN &&
             clock_type < GUI_CLOCK_SUBLCD_TYPE_END)
#endif /* __MMI_SUBLCD__ */
        )
    {
        return;
    }

    c->active = MMI_TRUE;
    c->type = clock_type;
    c->diff.nYear = 0;
    c->diff.nMonth = 0;
    c->diff.nDay = 0;
    c->diff.nHour = 0;
    c->diff.nMin = 0;
    c->diff.nSec = 0;
    c->time_compare = DT_TIME_EQUAL;
    c->x = x;
    c->y = y;
    c->width = width;
    c->height = height;
    c->hide_callback = NULL;
    c->close_callback = NULL;
    c->post_display_callback = NULL;
    c->gap_between_two_lines = GUI_CLOCK_GAP_TIME_DATE_TWO_LINE;
    c->gap_between_time_date_one_line = GUI_CLOCK_GAP_TIME_DATE_ONE_LINE;
    c->border_enable = MMI_TRUE;
    c->on_idle = MMI_FALSE;
    c->enable_update = MMI_TRUE;
    c->align_type = GUI_CLOCK_DIGITAL_ALIGN_CENTER;

	if (clock_type > GUI_CLOCK_MAINLCD_TYPE_BEGIN && clock_type < GUI_CLOCK_MAINLCD_TYPE_END)
    {
        c->target_lcd = GDI_LCD_MAIN_LCD_HANDLE;
        c->target_layer = GDI_LAYER_MAIN_BASE_LAYER_HANDLE;
    }
#ifdef __MMI_SUBLCD__
    else
    {
        c->target_lcd = GDI_LCD_SUB_LCD_HANDLE;

        gdi_lcd_get_active(&act_lcd_handle);
        gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
        gdi_layer_get_base_handle(&sub_handle);
        gdi_lcd_set_active(act_lcd_handle);
        c->target_layer = sub_handle;
    }
#endif /* __MMI_SUBLCD__ */ 

    c->abm_layer = GDI_LAYER_EMPTY_HANDLE;
    if (clock_type != GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL)
    {
        gui_clock_set_current_theme(c);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  on_idle [IN]        clock on idle or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_on_idle(gui_clock_struct *c, MMI_BOOL on_idle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    c->on_idle = on_idle;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_enable_update
 * DESCRIPTION
 *  enable clock's update
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  enable_update   [IN]        enable update or not
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_enable_update(gui_clock_struct *c, MMI_BOOL enable_update)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    c->enable_update = enable_update;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_close
 * DESCRIPTION
 *  close a clock component
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_close(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    c->active = MMI_FALSE;
}

#ifdef __MMI_ANALOG_CLOCK__

/*****************************************************************************
 * FUNCTION
 *  gui_clock_rotate_analog_clock_hand
 * DESCRIPTION
 *  
 * PARAMETERS
 *  vertices        [?]         [?]
 *  minute          [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
#if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
static void gui_clock_rotate_analog_clock_hand(polygon_vertex vertices[], S32 minute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FLOAT cosa, sina, x, y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(vertices != NULL);
    
    minute += 15;
    if (minute >= 60)
    {
        minute = minute - 60;
    }
    cosa = (FLOAT)g_gui_clock_acm_cosine_table[minute];
    sina = (FLOAT)g_gui_clock_acm_sine_table[minute];
    x = (FLOAT)vertices[0].x;
    y = (FLOAT)vertices[0].y;
    vertices[0].x = (S32) (x * cosa - y * sina);
    vertices[0].y = (S32) (x * sina + y * cosa);
    x = (FLOAT)vertices[1].x;
    y = (FLOAT)vertices[1].y;
    vertices[1].x = (S32) (x * cosa - y * sina);
    vertices[1].y = (S32) (x * sina + y * cosa);
    x = (FLOAT)vertices[2].x;
    y = (FLOAT)vertices[2].y;
    vertices[2].x = (S32) (x * cosa - y * sina);
    vertices[2].y = (S32) (x * sina + y * cosa);
}
#endif /* GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS */


/*****************************************************************************
 * FUNCTION
 *  gui_clock_analog_clock_draw_hand
 * DESCRIPTION
 *  draw the hand of analog clock
 * PARAMETERS
 *  clock       [IN]         
 *  type        [IN]        
 *  minute      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_analog_clock_draw_hand(gui_clock_struct *clock,S32 type, S32 minute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 radius;
    S32 x1 = g_gui_clock_analog_clock_center_x;
    S32 y1 = g_gui_clock_analog_clock_center_y;
    S32 x2, y2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    
#if defined(__MMI_MAINLCD_176X220__)
    
    /* offset to (0,0)   */
    polygon_vertex analog_clock_hour_hand_vertices[] = { {-0, 0},
    {+0, 0},
    {0, 0},
    };
    
    /* offset to (0,0)   */
    polygon_vertex analog_clock_minute_hand_vertices[] = { {-0, 0},
    {+0, 0},
    {0, 0},
    };
    
#elif defined(__MMI_MAINLCD_240X320__)
    /* offset to (0,0)   */
    polygon_vertex analog_clock_hour_hand_vertices[] = { {-2, 0},
    {+2, 0},
    {0, 0},
    };
    
    /* offset to (0,0)   */
    polygon_vertex analog_clock_minute_hand_vertices[] = { {-1, 0},
    {+1, 0},
    {0, 0},
    };
#elif defined(__MMI_MAINLCD_320X240__)
        /* offset to (0,0)   */
        polygon_vertex analog_clock_hour_hand_vertices[] = { {-2, 0},
        {+2, 0},
        {0, 0},
        };
        
        /* offset to (0,0)   */
        polygon_vertex analog_clock_minute_hand_vertices[] = { {-1, 0},
        {+1, 0},
        {0, 0},
        };
        
#elif defined(__MMI_MAINLCD_240X400__)
        /* offset to (0,0)   */
        polygon_vertex analog_clock_hour_hand_vertices[] = { {-2, 0},
        {+2, 0},
        {0, 0},
        };
        
        /* offset to (0,0)   */
        polygon_vertex analog_clock_minute_hand_vertices[] = { {-1, 0},
        {+1, 0},
        {0, 0},
        };
#endif 
    
#else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    
    /* offset to (0,0)   */
    polygon_vertex analog_clock_hour_hand_vertices[] = 
    {
        {-3, 0},
        {+3, 0},
        {0, 0},
    };
    
    /* offset to (0,0)   */
    polygon_vertex analog_clock_minute_hand_vertices[] = 
    {
        {-2, 0},
        {+2, 0},
        {0, 0},
    };
    
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    
#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    /* offset to (0,0)   */
    polygon_vertex sub_analog_clock_hour_hand_vertices[] = 
    {
        {-2, +1},
        {+2, +1},
        {0, 0},
    };
    
    /* offset to (0,0)   */
    polygon_vertex sub_analog_clock_minute_hand_vertices[] = 
    {
        {-2, 0},
        {+2, 0},
        {0, 0},
    };
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

    polygon_vertex vertices[3];
#endif /* GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

   MMI_DBG_ASSERT(clock != NULL);

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
    {
        x1 = g_gui_clock_sub_lcd_analog_clock_center_x;
        y1 = g_gui_clock_sub_lcd_analog_clock_center_y;
        radius = min(
                    g_gui_clock_sub_lcd_analog_clock_center_x - g_gui_clock_sub_lcd_analog_clock_dial_x,
                g_gui_clock_sub_lcd_analog_clock_center_y - g_gui_clock_sub_lcd_analog_clock_dial_y) - 1;
    }
    else
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
    {
        x1 = g_gui_clock_analog_clock_center_x;
        y1 = g_gui_clock_analog_clock_center_y;
        radius = min(
                    g_gui_clock_analog_clock_center_x - g_gui_clock_analog_clock_dial_x,
                    g_gui_clock_analog_clock_center_y - g_gui_clock_analog_clock_dial_y) - 1;
    }

    switch (type)
    {
        case 0: /* hour hand */
        {
            color c = clock->analog_hand_hour_color;

        #if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
        #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
            if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
            {
                vertices[0] = sub_analog_clock_hour_hand_vertices[0];
                vertices[1] = sub_analog_clock_hour_hand_vertices[1];

           sub_analog_clock_hour_hand_vertices[2].y = -radius * 4 / 5;
          
                vertices[2] = sub_analog_clock_hour_hand_vertices[2];
            }
            else
        #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
            {
                vertices[0] = analog_clock_hour_hand_vertices[0];
                vertices[1] = analog_clock_hour_hand_vertices[1];

          analog_clock_hour_hand_vertices[2].y = -radius * 4 / 5;
        
                vertices[2] = analog_clock_hour_hand_vertices[2];
            }
            gui_clock_rotate_analog_clock_hand(vertices, minute);
            vertices[0].x += x1;
            vertices[0].y += y1;
            vertices[1].x += x1;
            vertices[1].y += y1;
            vertices[2].x += x1;
            vertices[2].y += y1;
            flat_triangle_fill(vertices, c);
            polygon_draw(vertices, 3, c);
        #elif(GUI_CLOCK_ANALOG_CLOCK_SMOOTHEN_LINES)
            x2 = x1 + (S32) (((FLOAT)radius * 4 / 5) * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) (((FLOAT)radius * 4 / 5) * g_gui_clock_acm_sine_table[minute]);
            gdi_draw_antialiasing_line(
                x1, y1, x2, y2, 
                gdi_act_color_from_rgb(255, c.r, c.g, c.b));
        #else 
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gui_wline(x1, y1, x2, y2, c, 3);
        #endif 
        }
            break;
        case 1: /* minute hand */
        {
            color c = clock->analog_hand_min_color;;

        #if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
        #ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
            if (GDI_LCD->act_handle == GDI_LCD_SUB_LCD_HANDLE)
            {
                vertices[0] = sub_analog_clock_minute_hand_vertices[0];
                vertices[1] = sub_analog_clock_minute_hand_vertices[1];

          sub_analog_clock_minute_hand_vertices[2].y = -radius;
          
                vertices[2] = sub_analog_clock_minute_hand_vertices[2];
            }
            else
        #endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 
            {
                vertices[0] = analog_clock_minute_hand_vertices[0];
                vertices[1] = analog_clock_minute_hand_vertices[1];

          analog_clock_minute_hand_vertices[2].y = -radius;
                
                vertices[2] = analog_clock_minute_hand_vertices[2];
            }
            gui_clock_rotate_analog_clock_hand(vertices, minute);
            vertices[0].x += x1;
            vertices[0].y += y1;
            vertices[1].x += x1;
            vertices[1].y += y1;
            vertices[2].x += x1;
            vertices[2].y += y1;
            flat_triangle_fill(vertices, c);
            polygon_draw(vertices, 3, c);
        #elif(GUI_CLOCK_ANALOG_CLOCK_SMOOTHEN_LINES)
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gdi_draw_antialiasing_line(
                x1, y1, x2, y2, 
                gdi_act_color_from_rgb(255, c.r, c.g, c.b));
        #else 
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gui_wline(x1, y1, x2, y2, c, 1);
        #endif 
        }
            break;
        case 2:
        {
            color c = clock->analog_hand_hour_color;

        #if(GUI_CLOCK_ANALOG_CLOCK_DRAW_POLYGON_HANDS)
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gui_line(x1, y1, x2, y2, c);
        #elif(GUI_CLOCK_ANALOG_CLOCK_SMOOTHEN_LINES)
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gdi_draw_antialiasing_line(
                x1, y1, x2, y2, 
                gdi_act_color_from_rgb(255, c.r, c.g, c.b));
        #else 
            x2 = x1 + (S32) ((FLOAT)radius * g_gui_clock_acm_cosine_table[minute]);
            y2 = y1 + (S32) ((FLOAT)radius * g_gui_clock_acm_sine_table[minute]);
            gui_line(x1, y1, x2, y2, c);
        #endif 
        }
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_show_analog_clock_dial
 * DESCRIPTION
 *  show the analog clock
 * PARAMETERS
 *  c       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_show_analog_clock_dial(gui_clock_struct *c)
{   
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    gui_clock_analog_clock_initialize(c);

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    gui_push_clip();
    if (c->on_idle)
    {
    gui_set_clip(
        ANALOG_BACKGROUND_X,
        ANALOG_BACKGROUND_Y,
        ANALOG_BACKGROUND_X + ANALOG_BACKGROUND_WIDTH - 1,
        ANALOG_BACKGROUND_Y + MMI_IDLESCREEN_BAR_HEIGHT - 1);

    gui_show_image(0, (ANALOG_BACKGROUND_Y), (PU8)get_image(IMG_TECHNO_ANALOG_CLOCK));
    }
#else /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 
    gui_reset_clip();
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

    gui_clock_analog_clock_draw_hand(c, 0, g_gui_clock_analog_clock_hours_hand_counter);
    gui_clock_analog_clock_draw_hand(c, 1, g_gui_clock_analog_clock_minutes_hand_counter);

    if (c->target_lcd== GDI_LCD_MAIN_LCD_HANDLE)

#ifndef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        gdi_draw_solid_circle(
            g_gui_clock_analog_clock_center_x,
            g_gui_clock_analog_clock_center_y,
            GUI_CLOCK_AXIS_RADIUS, 
            gdi_act_color_from_rgb(255, c->analog_axis_color.r, c->analog_axis_color.g, c->analog_axis_color.b));
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

#ifdef __MMI_SUBLCD_SHOW_ANALOG_CLOCK__
    else
#if defined(__MMI_SUBLCD_COLOR__)
        gdi_draw_solid_circle(
            g_gui_clock_analog_clock_center_x,
            g_gui_clock_analog_clock_center_y,
            GUI_CLOCK_AXIS_RADIUS, 
            gdi_act_color_from_rgb(255, c->analog_axis_color.r, c->analog_axis_color.g, c->analog_axis_color.b));
#else /* defined(__MMI_SUBLCD_COLOR__) */ 
        gdi_draw_round_rect(
            g_gui_clock_sub_lcd_analog_clock_center_x - 3,
            g_gui_clock_sub_lcd_analog_clock_center_y - 3,
            g_gui_clock_sub_lcd_analog_clock_center_x + 3,
            g_gui_clock_sub_lcd_analog_clock_center_y + 3,
            GDI_COLOR_BLACK,
            GDI_COLOR_BLACK,
            2);
#endif /* defined(__MMI_SUBLCD_COLOR__) */ 
#endif /* __MMI_SUBLCD_SHOW_ANALOG_CLOCK__ */ 

#ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
    gui_pop_clip();
#endif /*__MMI_UI_TECHNO_IDLESCREEN_BAR__*/

}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_analog_clock_minute_tick
 * DESCRIPTION
 *  update when minute tick
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_analog_clock_minute_tick(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME t;
    S32 h, m;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GetDateTime(&t);
    m = t.nMin;
    g_gui_clock_analog_clock_minutes_hand_counter = m;
    h = t.nHour;
    h++;
    if (h > 12)
    {
        h -= 12;
    }
    g_gui_clock_analog_clock_hours_hand_counter = (h - 1) * 5;
    g_gui_clock_analog_clock_hours_hand_counter += m / 12;
    if (g_gui_clock_analog_clock_minutes_hand_counter >= 60)
    {
        g_gui_clock_analog_clock_minutes_hand_counter = 0;
    }
    if ((g_gui_clock_analog_clock_minutes_hand_counter % 12) == 0)
    {   /* g_gui_clock_analog_clock_hours_hand_counter++; */
        if (g_gui_clock_analog_clock_hours_hand_counter >= 60)
        {
            g_gui_clock_analog_clock_hours_hand_counter = 0;
        }
    }
}

#endif /* __MMI_ANALOG_CLOCK__ */

/*****************************************************************************
 * FUNCTION
 *  gui_clock_update
 * DESCRIPTION
 *  update a clock component
 * PARAMETERS
 *  c       [IN]     
 * RETURNS
 *  MMI_BOOL    [OUT]    whether has update the clock
 *****************************************************************************/
MMI_BOOL gui_clock_update(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    ret = MMI_FALSE;

    if (c->active == MMI_FALSE)
    {
        return ret;
    }

    if (c->enable_update == MMI_TRUE)
    {
    #ifdef __MMI_ANALOG_CLOCK__
        if (c->type == GUI_CLOCK_MAINLCD_TYPE_ANALOG)
        {
            gui_clock_analog_clock_minute_tick();
        }
    #endif
        gui_clock_show(c);
        ret = MMI_TRUE;
    }
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_date_string
 * DESCRIPTION
 *  get date time string for different requirement
 * PARAMETERS
 *  time        [IN]        Date time to convert
 *  string      [OUT]       Date time string
 *  flags       [IN]        Date time type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_date_string(
             applib_time_struct *time,
             U8* string,
             U32 flags,
             S32 date_separator,
             S32 date_format)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 day, month, year, day_index;
    S8 ts[32];
    U8 seperator;

#ifdef __MMI_SUBLCD__
    S8 as[64];
    U8 Tempbuffer[64];
    U8 *day_name = NULL;    
#endif /* __MMI_SUBLCD__ */ 

#if 0
#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
#endif /*__MMI_DATE_TIME_IN_DIFF_LANG__*/
/* under construction !*/
#ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
/* under construction !*/
#else /*__MMI_DATE_TIME_IN_DIFF_LANG__*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_DATE_TIME_IN_DIFF_LANG__*/
#else
    U8 month_str[12][4] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
    U8 day_str[7][4] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    day_index = time->DayIndex;
    day = time->nDay;
    month = time->nMonth;
    year = time->nYear;

    if (month > 12 || month < 1)
    {
        month = 1;
    }

    if (day_index > 6)
    {
        day_index = 0;
    }

    if (date_separator < 0)
    {
    #if defined(__IOT__)
        date_separator = srv_setting_get_date_seperator();
    #else
        date_separator = PhnsetGetDateSeperatorFormat();
    #endif
    }
    if (date_format < 0)
    {
    #if defined(__IOT__)
        date_format = srv_setting_get_date_format();
    #else
        date_format = PhnsetGetDateFormat();
    #endif
    }

    switch (date_separator)
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
    
    switch (flags)
    {

      /***** MainLCD DataTime *****/
    #ifdef __MMI_ANALOG_CLOCK__
      case GUI_CLOCK_MAINLCD_TYPE_ANALOG:
    #endif
      case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE:
      case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_ONE_LINE:
      case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE:
      case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME:
        {
            switch (date_format)  /* Get the current format of date */
            {
                case 0: /* day,month,year */
                    sprintf((S8*)ts, "%02d%c%02d%c%04d", day, seperator, month, seperator, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 1: /* month, day, year */
                    sprintf((S8*) ts, "%02d%c%02d%c%04d", month, seperator, day, seperator, year);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
                        
                case 2: /* year, month, day */
                    sprintf((S8*) ts, "%04d%c%02d%c%02d", year, seperator, month, seperator, day);
                    mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            }
        }
            break;
    case GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_TIME_MONTH_DAY_ONE_LINE:
        {            
			switch (date_format)  /* Get the current format of date */
            {
                case 0: /* day,month,year */
					sprintf((S8*) ts, "%02d%c%02d", day, seperator, month);
					mmi_asc_to_ucs2((S8*) string, ts);
                    break;

                case 1: /* month, day, year */                        
                case 2: /* year, month, day */
					sprintf((S8*) ts, "%02d%c%02d", month, seperator, day);
					mmi_asc_to_ucs2((S8*) string, ts);
                    break;
            }
        }
            break;
            
    case GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_DAY_DATE_ONE_LINE:
        {
            #if 0
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
/* under construction !*/
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */
            #else
                sprintf((S8*) ts, "%3s %02d %3s", day_str[day_index], day, month_str[month - 1]);
                mmi_asc_to_ucs2((S8*) string, ts);
            #endif
        }
        break;
        
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DAY:
        {
            #if 0
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
/* under construction !*/
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */
            #else
                sprintf((S8*) ts, "%3s", day_str[day_index]);
                mmi_asc_to_ucs2((S8*) string, ts);
            #endif
        }
        break;
        
    #ifdef __MMI_SUBLCD__
      /***** SubLCD DataTime *****/
    case GUI_CLOCK_SUBLCD_TYPE1:
    case GUI_CLOCK_SUBLCD_TYPE2:
    case GUI_CLOCK_SUBLCD_TYPE3:
    case GUI_CLOCK_SUBLCD_TYPE4:
        {
            if (IsChineseSet()) /* check if current language is chinese or not */
            {
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_CHI_SATURDAY);
                        break;
                }
            }
            else
            {
                /* not chinese */
                switch (day_index)
                {
                    case 0:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SUNDAY);
                        break;

                    case 1:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_MONDAY);
                        break;

                    case 2:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_TUESDAY);
                        break;

                    case 3:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_WEDNESDAY);
                        break;

                    case 4:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_THURSDAY);
                        break;

                    case 5:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_FRIDAY);
                        break;

                    case 6:
                        day_name = (PU8) GetString(STR_SUBLCD_ENG_SATURDAY);
                        break;
                }
            }   /* end of check chiese */
            mmi_ucs2cpy((S8*) as, (S8*) day_name);

            if (flags == GUI_CLOCK_SUBLCD_TYPE3)
            {
                year %= 100;

                switch (date_format)  /* Get the current format of date */
                {
                    case 0: /* day,month,year */
                        sprintf((S8*) ts, "%02d/%02d/%02d", day, month, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        break;

                    case 1: /* month, day, year */
                        sprintf((S8*) ts, "%02d/%02d/%02d", month, day, year);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        break;

                    case 2: /* year, month, day */
                        sprintf((S8*) ts, "%02d/%02d/%02d", year, month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        break;
                }

            }
            else if (flags == GUI_CLOCK_SUBLCD_TYPE2)
            {
                year %= 100;

                switch (date_format)  /* Get the current format of date */
                {
                    case 0: /* day,month,year */
                        sprintf((S8*) ts, "%02d/%02d", day, month);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        break;

                    case 1:
                    case 2:
                        sprintf((S8*) ts, "%02d/%02d", month, day);
                        mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                        mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
                        break;
                }

            }
            else
            {
                sprintf((S8*) ts, "%02d/%02d", day, month);
                mmi_asc_to_ucs2((S8*) Tempbuffer, ts);
                mmi_ucs2cat((S8*) as, (S8*) Tempbuffer);
            }

            mmi_ucs2cpy((S8*) string, (S8*) as);
            break;
        }
            /* break; */
    #endif /* __MMI_SUBLCD__ */ 

    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_time_string
 * DESCRIPTION
 *  convert time to string accoding to current time format
 * PARAMETERS
 *  c           [IN]        pointer of clock struct
 *  t           [IN]        Date to convets
 *  s           [OUT]       String format of time
 *  flags       [IN]        Date type
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_time_string(applib_time_struct*t, U8* s, U32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 hours, minutes;
#if 0
#ifdef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
#endif /*__MMI_DATE_TIME_IN_DIFF_LANG__*/
#endif
    S8 ts[32];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hours = t->nHour;
    minutes = t->nMin;
    switch (flags)
    {
    #ifdef __MMI_ANALOG_CLOCK__
        case GUI_CLOCK_MAINLCD_TYPE_ANALOG:
    #endif
        case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE:
        case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_ONE_LINE:
        case GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_TIME_MONTH_DAY_ONE_LINE:
        case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE:
        case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME:

            if (PhnsetGetTimeFormat())  /* get current time format */
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                mmi_asc_to_ucs2((S8*) s, ts);
            }
            else
            {
            #if 0
            #ifndef __MMI_DATE_TIME_IN_DIFF_LANG__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #else /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
            #endif /* __MMI_DATE_TIME_IN_DIFF_LANG__ */ 
            #else
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
            #endif
            }
            break;

            case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL:
                if (PhnsetGetTimeFormat())  /* get current time format */
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    mmi_asc_to_ucs2((S8*) s, ts);
                }
                else
                {
                    if (hours == 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                    else if (hours == 0)
                    {
                        sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                    }
                    else if (hours > 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                    }
                    else
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                    mmi_asc_to_ucs2((S8*) s, ts);
                }
                break;

    #ifdef __MMI_SUBLCD__
        case GUI_CLOCK_SUBLCD_TYPE1:
        case GUI_CLOCK_SUBLCD_TYPE2:
        case GUI_CLOCK_SUBLCD_TYPE3:
        
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                S32 width, height;

                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d AM", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d PM", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d AM", hours, minutes);
                }
                mmi_asc_to_ucs2((S8*) s, ts);
                gui_measure_string((UI_string_type) s, &width, &height);
                if (width > GDI_SUBLCD_WIDTH)
                {
                    if (hours == 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                    else if (hours == 0)
                    {
                        sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                    }
                    else if (hours > 12)
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                    }
                    else
                    {
                        sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                    }
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;

        case GUI_CLOCK_SUBLCD_TYPE4:
            if (PhnsetGetTimeFormat())
            {
                sprintf((S8*) ts, "%02d:%02d", hours, minutes);
            }
            else
            {
                if (hours == 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
                else if (hours == 0)
                {
                    sprintf((S8*) ts, "%02d:%02d", 12, minutes);
                }
                else if (hours > 12)
                {
                    sprintf((S8*) ts, "%02d:%02d", hours - 12, minutes);
                }
                else
                {
                    sprintf((S8*) ts, "%02d:%02d", hours, minutes);
                }
            }
            mmi_asc_to_ucs2((S8*) s, ts);
            break;
    #endif /* __MMI_SUBLCD__ */ 
    }
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_show_digital
 * DESCRIPTION
 *  show digital clock
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_show_digital(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    S32 x1,x2,y1,y2,w,h,x,y;
    U8 s[64];
    applib_time_struct time_to_show;
    S32 height_of_second_line,width_of_second_column;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    gui_clock_get_clock_show_time(c, &time_to_show);

#if !defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__GDI_MEMORY_PROFILE_2__)
    if (c->on_idle)
    {
    gdi_draw_solid_rect(c->x, c->y, c->x + c->width -1, c->y + c->height -1,
        GDI_COLOR_TRANSPARENT);    
    }
#endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */     

    y1 = 0;

#ifdef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
    if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_IMAGE)
    {
        gui_clock_show_digital_image(c, &time_to_show);
        return;
    }
#endif /* __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__ */

    if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE ||
        c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME)
    {
    #ifdef __MMI_UI_TECHNO_IDLESCREEN_BAR__
        if (c->on_idle)
        {
                gui_push_clip();
                gui_set_clip(
                    DIGITAL_BACKGROUND_X,
                    DIGITAL_BACKGROUND_Y,
                    DIGITAL_BACKGROUND_X + DIGITAL_BACKGROUND_WIDTH - 1,
                    DIGITAL_BACKGROUND_Y + MMI_IDLESCREEN_BAR_HEIGHT - 1);
    
                if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME)
                {
                    gdi_draw_solid_rect(
                        c->x,
                        c->y,
                        c->x + c->width - 1,
                        c->y + c->height - 1,
                        GDI_COLOR_TRANSPARENT);
                    #ifdef __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__
                        if (hours >= 6 && hours <= 18)
                        {
                            gdi_image_draw_id(
                                DIGITAL_BACKGROUND_X,
                                DIGITAL_BACKGROUND_Y,
                                IMG_TECHNO_DIGITAL_CLOCK_DAY_BACKGROUND);
                        }
                        else
                        {
                            gdi_image_draw_id(
                                DIGITAL_BACKGROUND_X,
                                DIGITAL_BACKGROUND_Y,
                                IMG_TECHNO_DIGITAL_CLOCK_NIGHT_BACKGROUND);
                        }
                    #else /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
                        gui_show_image(0, (ANALOG_BACKGROUND_Y), (PU8)get_image(IMG_TECHNO_DIGITAL_CLOCK));
                    #endif /* __MMI_DIGITAL_CLOCK_STYLE_BACKGROUND__ */
                }
                gui_pop_clip();
        }
    #endif /* __MMI_UI_TECHNO_IDLESCREEN_BAR__ */ 

        if(c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE)
        {
            gui_set_font(c->date_text_font);
            gui_clock_date_string(&time_to_show,s,c->type, -1, -1);
            gui_measure_string((UI_string_type)s, &w, &height_of_second_line);
            if (c->border_enable) /* border will add 2 pixels */
            {
                w = w + 2;
                height_of_second_line = height_of_second_line + 2;
            }
        }
    
        gui_set_font(c->time_text_font);
        gui_clock_time_string(&time_to_show,s,c->type);
        gui_measure_string((UI_string_type)s, &w, &h);
        if (c->border_enable)
        {
            w = w + 2;
            h = h + 2;
        }
        
        /* calculate logic coordinate */
        if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_LEFT)
        {
            x = 0;
        }
        else if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_RIGHT)
        {
            x = c->width - w;
        }
        else
        {
        x = (c->width >> 1) - (w >> 1);
        }

        if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE)
        {
            y = (c->height >> 1) - ((h + height_of_second_line + c->gap_between_two_lines) >> 1);
        }
        else
        {
            y = (c->height >> 1) - (h >> 1);
        }
        /* y should move down 1 pixel */
        if (c->border_enable)
        {
            y = y + 1;
        }
        
        /* change logic coordinate to phycial coordinate */
        x = c->x + x;
        y = c->y + y;

        gui_set_text_color(c->time_text_color);

        if (c->border_enable)
        {
            gui_set_text_border_color(c->time_text_border_color);
        }
        
        if (mmi_fe_get_r2l_state())
        {
            #if defined(__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_MAINLCD_240X400__)
                gui_move_text_cursor(x + w - 2, y);
            #else
                if (c->border_enable)
                {
                    gui_move_text_cursor((x + w - 1) - 1, y);
                }
                else
                {
                    gui_move_text_cursor(x + w - 1, y);
                }
            #endif /* (__MMI_UI_TECHNO_IDLESCREEN_BAR__) && defined(__MMI_MAINLCD_240X400__) */
        }
        else
        {
            if (c->border_enable)
            {
                 gui_move_text_cursor(x + 1, y);
            }
            else
            {
                gui_move_text_cursor(x, y);
            }
        }
         
        /* set clip area */
        x1 = x;
        y1 = y;
        x2 = x1 + w - 1;
        y2 = y1 + h - 1;
         
        if (c->border_enable)
        {
            gui_set_text_clip(x1, y1 - 1, x2, y2);
        }
        else
        {
            gui_set_text_clip(x1, y1, x2, y2);
        }

        /* print time */
         if(c->border_enable)
        {
             gui_print_bordered_text((UI_string_type)s);
        }
         else
        {
            gui_print_text((UI_string_type)s);
        }

         if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE)
        {
            y1 += h;
        }
    }

    if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE || 
		c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE ||
		c->type == GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_DAY_DATE_ONE_LINE ||
		c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DAY)
    {
       gui_set_font(c->date_text_font);
       gui_clock_date_string(&time_to_show,s,c->type, -1, -1);
       gui_measure_string((UI_string_type)s, &w, &h);
        /* if has text border, width and height need 2 more pixels */
        if (c->border_enable)
        {
            w = w + 2;
            h = h + 2;
        }
        
        /* calculate logic coordinate */
       if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_LEFT)
        {
            x = 0;
        }
        else if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_RIGHT)
        {
            x = c->width - w;
        }
        else
        {
       x = (c->width >> 1) - (w >> 1);
        }
       y = (c->height >> 1) - (h >> 1);
        if (c->border_enable)
        {
            y = y + 1;
        }
    
        /* change logic coordinate to physical coordinate */
        x = c->x + x;
       if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE)
       {
            y = y1 + c->gap_between_two_lines;
       }
       else
       {
            y = c->y + y;
       }

       gui_set_text_color(c->date_text_color);
       if (c->border_enable)
       {
           gui_set_text_border_color(c->date_text_border_color);
       }

       if (mmi_fe_get_r2l_state())
       {
	    if (c->border_enable)
	    {
		gui_move_text_cursor((x + w - 1) - 1, y);
	    }
	    else
	    {
                gui_move_text_cursor(x + w - 1, y);
            }
       }
       else
       {
           if (c->border_enable)
		   {
			   gui_move_text_cursor(x + 1, y);
		   }
		   else
		   { 
		       gui_move_text_cursor(x, y);
		   }
       }
         
        x1 = x;
        y1 = y;
        x2 = x1 + w - 1;
        y2 = y1 + h - 1;

        if (c->border_enable)
        {
            gui_set_text_clip(x1, y1 - 1, x2, y2);
	    }
	    else
	    {
            gui_set_text_clip(x1, y1, x2, y2);
	    }

                /* print time */
        if (c->border_enable)
        {
            gui_print_bordered_text((UI_string_type)s);
        }
        else
        {
            gui_print_text((UI_string_type)s);
        }

    }

    if(c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_ONE_LINE 
        || c->type == GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_TIME_MONTH_DAY_ONE_LINE )
    {
        /*print time*/
        gui_set_font(c->date_text_font);
        gui_clock_date_string(&time_to_show,s,c->type, -1, -1);
        gui_measure_string((UI_string_type)s, &width_of_second_column, &h);
        if (c->border_enable)
        {
            width_of_second_column = width_of_second_column + 2;
            h = h + 2;
        }
    
        gui_set_font(c->time_text_font);
        gui_clock_time_string(&time_to_show,s,c->type);        
        gui_measure_string((UI_string_type)s, &w, &h);
        if (c->border_enable)
        {
            w = w + 2;
            h = h + 2;
        }

        /* calculate logic coordinate */
        y = (c->height>> 1) - (h >> 1);
        if (c->border_enable)
        {
            y = y + 1;
        }        
        /* x = (c->width>> 1) - ((w + width_of_second_column + c->gap_between_time_date_one_line) >> 1); */
        if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_LEFT)
        {
            x = 0;
        }
        else if (c->align_type == GUI_CLOCK_DIGITAL_ALIGN_RIGHT)
        {
            x = c->width - (w + width_of_second_column + c->gap_between_time_date_one_line);
        }
        else
        {
        x = (c->width>> 1) - ((w + width_of_second_column + c->gap_between_time_date_one_line) >> 1);
        }        

        gui_set_text_color(c->time_text_color);

        if (c->border_enable)
        {
            gui_set_text_border_color(c->time_text_border_color);
        }
        
        /* change logic coordinate to physical coordinate */
        x = c->x + x;
        y = c->y + y;
        if (mmi_fe_get_r2l_state())
        {
	    if (c->border_enable)
	    {
		gui_move_text_cursor((x + w - 1) - 1, y);
	    }
	    else
	    {
		gui_move_text_cursor(x + w - 1, y);
             }
         }
         else
         {
            gui_move_text_cursor(x, y);
          }
         
            x1 = x;
            y1 = y;
        x2 = x1 + w - 1;
        y2 = y1 + h - 1;

        if (c->border_enable)
        {
            gui_set_text_clip(x1, y1 - 1, x2, y2);
	    }
	    else
	    {
            gui_set_text_clip(x1, y1, x2, y2);
	    }

        /* print time */
        if (c->border_enable)
        {
             gui_print_bordered_text((UI_string_type)s);
        }
         else
        {
            gui_print_text((UI_string_type)s);
        }

        x += (w + c->gap_between_time_date_one_line);
    
        gui_set_font(c->date_text_font);
        gui_clock_date_string(&time_to_show,s,c->type, -1, -1);        
        gui_measure_string((UI_string_type)s, &w, &h);
        if (c->border_enable)
        {
            w = w + 2;
            h = h + 2;
        }

        /* calculate logic coordinate */
        y = (c->height>> 1) - (h >> 1);
        if (c->border_enable)
        {
            y = y + 1;
        }

        gui_set_text_color(c->date_text_color);
        if (c->border_enable)
        {
            gui_set_text_border_color(c->date_text_border_color);
        }
        /* change logic coordinate to physical coordinate */
        x = c->x + x;
        y = c->y + y;
        if (mmi_fe_get_r2l_state())
        {
            if (c->border_enable)
	    {
		gui_move_text_cursor((x + w - 1) - 1, y);
	    }
	    else
	    {
                gui_move_text_cursor(x + w - 1, y);
             }
        }
        else
        {
            gui_move_text_cursor(x, y);
        }
         
        /* set clip area, note the border should in the clip */

        x1 = x;
        y1 = y;
        x2 = x1 + w - 1;
        y2 = y1 + h - 1;

        if (c->border_enable)
        {
            gui_set_text_clip(x1, y1 - 1, x2, y2);
	    }
	    else
	    {
            gui_set_text_clip(x1, y1, x2, y2);
	    }

        /* print date */
        if (c->border_enable)
        {
            gui_print_bordered_text((UI_string_type)s);
        }
         else
        {
            gui_print_text((UI_string_type)s);
        }
    }

    if (c->type == GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL)
    {
        gui_clock_show_digital_small_image(c, &time_to_show);
    }
}

#ifdef __MMI_SUBLCD__


/*****************************************************************************
 * FUNCTION
 *  gui_clock_show_sub_lcd
 * DESCRIPTION
 *  show clock in sub lcd
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
static void gui_clock_show_sub_lcd(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__)
    S32 h, w, x, y;
    UI_character_type s[64];
    S32 x1, y1;
    applib_time_struct time_to_show;
    S32 height_of_second_line;
   
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_clock_get_clock_show_time(c, &time_to_show);
    gui_set_text_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
    gdi_draw_solid_rect(c->x, c->y, c->x + c->width -1, c->y + c->height -1,
        GDI_COLOR_TRANSPARENT);    
#endif /* defined(__MMI_SUBLCD_SHOW_DATE__) || defined(__MMI_SUBLCD_SHOW_TIME__) */ 


    if (c->type == GUI_CLOCK_SUBLCD_TYPE1 || c->type == GUI_CLOCK_SUBLCD_TYPE2)
    {
    #ifdef __MMI_SUBLCD_SHOW_DATE__

        x1 = c->x;
        y1 = c->y;

        gui_set_text_color(c->date_text_color);

    #ifdef __MMI_SUB_WALLPAPER__
            if(c->border_enable)
            {
                gui_set_text_border_color(c->date_text_border_color);
            }
    #endif /*__MMI_SUB_WALLPAPER__*/
        
    #if defined(__MMI_SUBLCD_SHOW_TIME__)
        gui_set_font(c->time_text_font);
        gui_clock_time_string(&time_to_show, (U8*) s, c->type);
        gui_measure_string(s, &w, &height_of_second_line);
    #endif /* defined(__MMI_SUBLCD_SHOW_TIME__) */ 

        gui_set_font(c->date_text_font);        
        gui_clock_date_string(&time_to_show, (U8*) s, c->type, -1, -1);
        gui_measure_string(s, &w, &h);
        x = (c->width >> 1) - (w >> 1);
        x1 = c->x + x;

    #if defined(__MMI_SUBLCD_SHOW_TIME__)
            y = (c->height >> 1) - ((h + height_of_second_line + c->gap_between_two_lines) >> 1);
    #else /*defined(__MMI_SUBLCD_SHOW_TIME__)*/
            y = (c->height >> 1) - ( h >> 1);
    #endif/*defined(__MMI_SUBLCD_SHOW_TIME__)*/

        y1 = c->y + y;

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x1 + w, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        
        gui_set_text_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);

        if(c->border_enable)
        {
            gui_print_bordered_text(s);
        }
        else
        {
            gui_print_text(s);
        }
        
    #endif /*__MMI_SUBLCD_SHOW_DATE__*/

    #ifdef __MMI_SUBLCD_SHOW_TIME__

        gui_set_font(c->time_text_font);
        gui_clock_time_string(&time_to_show, (U8*)s, c->type);
        gui_measure_string(s, &w, &h);
        x = (c->width >> 1) - (w >> 1);
        x1 = c->x + x;
        
    #if defined(__MMI_SUBLCD_SHOW_DATE__)
            gui_set_font(c->date_text_font);
            gui_clock_date_string(&time_to_show, (U8*)s, c->type, -1, -1);
            gui_measure_string(s, &w, &height_of_second_line);
            y1 += height_of_second_line + c->gap_between_two_lines;            
            gui_set_font(c->time_text_font);
            gui_clock_time_string(&time_to_show, (U8*)s, c->type);
            gui_measure_string(s, &w, &h);
    #else /* defined(__MMI_SUBLCD_SHOW_DATE__) */ 
            y = (c->height >> 1) - ( h >> 1);
            y1 = c->y + y;
    #endif /* defined(__MMI_SUBLCD_SHOW_DATE__) */ 
        
        gui_set_text_color(c->time_text_color);

    #ifdef __MMI_SUB_WALLPAPER__
            if(c->border_enable)
            {
                gui_set_text_border_color(c->time_text_border_color);
            }
    #endif /*__MMI_SUB_WALLPAPER__*/

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x1 + w, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        
        gui_set_text_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
        if(c->border_enable)
        {
            gui_print_bordered_text(s);
        }
        else
        {
            gui_print_text(s);
        }
        
    #endif/*__MMI_SUBLCD_SHOW_TIME__*/
    }

    if (c->type == GUI_CLOCK_SUBLCD_TYPE3 || c->type == GUI_CLOCK_SUBLCD_TYPE4)
    {
    #ifdef __MMI_SUBLCD_SHOW_TIME__

        x1 = c->x;
        y1 = c->y;

        gui_set_text_color(c->time_text_color);

    #ifdef __MMI_SUB_WALLPAPER__
            if(c->border_enable)
            {
                gui_set_text_border_color(c->time_text_border_color);
            }
    #endif /*__MMI_SUB_WALLPAPER__*/

    #if defined(__MMI_SUBLCD_SHOW_DATE__)
            gui_set_font(c->date_text_font);
            gui_clock_date_string(&time_to_show, (U8*) s, c->type, -1, -1);
            gui_measure_string(s, &w, &height_of_second_line);
    #endif /* defined(__MMI_SUBLCD_SHOW_DATE__) */ 

        gui_set_font(c->time_text_font);        
        gui_clock_time_string(&time_to_show, (U8*) s, c->type);
        gui_measure_string(s, &w, &h);
        x = (c->width >> 1) - (w >> 1);
        x1 = c->x + x;

    #if defined(__MMI_SUBLCD_SHOW_DATE__)
            y = (c->height >> 1) - ((h + height_of_second_line + c->gap_between_two_lines) >> 1);
    #else /*defined(__MMI_SUBLCD_SHOW_TIME__)*/
            y = (c->height >> 1) - ( h >> 1);
    #endif/*defined(__MMI_SUBLCD_SHOW_TIME__)*/

        y1 = c->y + y;

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x1 + w, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        
        gui_set_text_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
        if(c->border_enable)
        {
            gui_print_bordered_text(s);
        }
        else
        {
            gui_print_text(s);
        }
        
    #endif /*__MMI_SUBLCD_SHOW_TIME__*/

    #ifdef __MMI_SUBLCD_SHOW_DATE__

        gui_set_font(c->date_text_font);
        gui_clock_date_string(&time_to_show, (U8*)s, c->type, -1, -1);
        gui_measure_string(s, &w, &h);
        x = (c->width >> 1) - (w >> 1);
        x1 = c->x + x;
        
    #if defined(__MMI_SUBLCD_SHOW_TIME__)
            gui_set_font(c->time_text_font);
            gui_clock_time_string(&time_to_show, (U8*)s, c->type);
            gui_measure_string(s, &w, &height_of_second_line);
            y1 += height_of_second_line + c->gap_between_two_lines;
            gui_set_font(c->date_text_font);
            gui_clock_date_string(&time_to_show, (U8*)s, c->type, -1, -1);
            gui_measure_string(s, &w, &h);
    #else /*__MMI_SUBLCD_SHOW_DATE__*/
            y = (c->height >> 1) - ( h >> 1);
            y1 = c->y + y;
    #endif /*__MMI_SUBLCD_SHOW_DATE__*/

        
        gui_set_text_color(c->date_text_color);

    #ifdef __MMI_SUB_WALLPAPER__
            if(c->border_enable)
            {
                gui_set_text_border_color(c->date_text_border_color);
            }
    #endif /*__MMI_SUB_WALLPAPER__*/

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(x1 + w, y1);
        }
        else
        {
            gui_move_text_cursor(x1, y1);
        }
        
        gui_set_text_clip(c->x, c->y, c->x + c->width -1, c->y + c->height -1);
        if(c->border_enable)
        {
            gui_print_bordered_text(s);
        }
        else
        {
            gui_print_text(s);
        }
        
    #endif/*__MMI_SUBLCD_SHOW_DATE__*/
    }
    
}

#endif /*__MMI_SUBLCD__*/


/*****************************************************************************
 * FUNCTION
 *  gui_clock_show
 * DESCRIPTION
 *  show a clock component
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_show(gui_clock_struct *c)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if (c->active == MMI_FALSE)
    {
        return;
    }

    gdi_layer_lock_frame_buffer();
    
    GDI_LOCK;    
    gdi_layer_push_clip();
    gdi_layer_set_clip(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);

    if (c->hide_callback != NULL)
    {
        c->hide_callback(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);    
    }

    switch (c->type)
    {
#ifdef __MMI_ANALOG_CLOCK__
    case GUI_CLOCK_MAINLCD_TYPE_ANALOG:
            gui_clock_show_analog_clock_dial(c);
            break;
#endif
            
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_TWO_LINE:
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_DATE_ONE_LINE:
    case GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_TIME_MONTH_DAY_ONE_LINE:
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DATE:
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME:
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_DAY:
    case GUI_CLOCK_MAINLCD_TYPE_DIGILTAL_DAY_DATE_ONE_LINE:
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_SMALL:
#ifdef __MMI_DIGITAL_CLOCK_IMAGE_NUMBER__
    case GUI_CLOCK_MAINLCD_TYPE_DIGITAL_TIME_IMAGE:
#endif
            gui_clock_show_digital(c);
            
            break;

    #ifdef __MMI_SUBLCD__

    case GUI_CLOCK_SUBLCD_TYPE1:
    case GUI_CLOCK_SUBLCD_TYPE2:
    case GUI_CLOCK_SUBLCD_TYPE3:
    case GUI_CLOCK_SUBLCD_TYPE4:

            mmi_fe_enable_date_char_display();
            gui_clock_show_sub_lcd(c);
            mmi_fe_disable_date_char_display();
            break;
    case GUI_CLOCK_SUBLCD_ANALOG_CLOCK:
            mmi_fe_enable_date_char_display();
            gui_clock_show_analog_clock_dial(c);
            mmi_fe_disable_date_char_display();
            break;

    #endif/*__MMI_SUBLCD__*/

        default :
            break;
    }

    gdi_layer_pop_clip();
    GDI_UNLOCK;

    if (c->post_display_callback != NULL)
    {
        c->post_display_callback(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1);
    }
    gdi_layer_unlock_frame_buffer();
    gdi_layer_blt_previous(c->x, c->y, c->x + c->width - 1, c->y + c->height - 1); 
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_move
 * DESCRIPTION
 *  move a clock component
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  x          [IN]        Start x posiion
 *  y       [IN]        Start y position
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_move(gui_clock_struct *c, S32 x, S32 y)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->x = x;
    c->y = y;

}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_resize
 * DESCRIPTION
 *  resize a clock component
 * PARAMETERS
 *  c           [IN]        Pointer of clock component
 *  width       [IN]        Width of clock
 *  height      [IN]        Height of clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_resize(gui_clock_struct *c, S32 width, S32 height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->width = width;
    c->height = height;
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_time
 * DESCRIPTION
 *  set the time of a clock
 * PARAMETERS
 *  c           [IN]        Pointer of clock component
 *  newtime     [IN]        New time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_time(gui_clock_struct *c, applib_time_struct newtime)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    applib_time_struct current_time;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    applib_dt_get_date_time(&current_time);
    
    c->time_compare = applib_dt_compare_time(&current_time, &newtime,NULL);

    if (c->time_compare == DT_TIME_EQUAL)
    {
        return;
    }
    else if (c->time_compare == DT_TIME_LESS)
    {
        applib_get_time_difference_ext(&newtime, &current_time, &c->diff);
    }
    else
    {
        applib_get_time_difference_ext(&current_time, &newtime, &c->diff);
    }
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_get_time
 * DESCRIPTION
 *  get the time of a clock
 * PARAMETERS
 *  c           [IN]        Pointer of clock component
 *  time        [IN]        Current time of the clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_get_time(gui_clock_struct *c, applib_time_struct *time)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    applib_time_struct current_time;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    applib_dt_get_date_time(&current_time);
    
    if (c->time_compare == DT_TIME_EQUAL)
    {
        time->nYear = current_time.nYear;
        time->nMonth = current_time.nMonth;
        time->nDay = current_time.nDay;
        time->nHour = current_time.nHour;
        time->nMin = current_time.nMin;
        time->nSec = current_time.nSec;
        time->DayIndex = current_time.DayIndex;
    }
    else if (c->time_compare == DT_TIME_LESS)
    {
        applib_dt_increase_time(&current_time, &c->diff, time);
    }
    else 
    {
        applib_dt_decrease_time(&current_time, &c->diff, time);
    }

}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_hide_function
 * DESCRIPTION
 *  set the hide callback function of the clock
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  f       [IN]        New hide callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_hide_function(gui_clock_struct *c, void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->hide_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_close_callback
 * DESCRIPTION
 *  set the close callback function of the clock
 *  clock's callback function will be called when app call wgui_clock_close_all, 
 *  wgui_clock_close_main_lcd, wgui_clock_close_sub_lcd
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  f       [IN]        New close callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_close_callback(gui_clock_struct *c, FuncPtr f)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->close_callback = f;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_post_display_callback
 * DESCRIPTION
 *  set the post display callback function of the clock
 * PARAMETERS
 *  c       [IN]        Pointer of clock component
 *  f       [IN]        New post display callback function
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_post_display_callback(
      gui_clock_struct *c,
      void (*f) (S32 x1, S32 y1, S32 x2, S32 y2))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->post_display_callback = f;
}

#ifdef __MMI_ANALOG_CLOCK__
/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_analog_clock_hour_hand_color
 * DESCRIPTION
 *  set the color of analog clock's hour hand
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New color of hour hand
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_analog_clock_hour_hand_color(gui_clock_struct *c, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);
    
    c->analog_hand_hour_color = new_color;
    
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_analog_clock_min_hand_color
 * DESCRIPTION
 *  set the color of analog clock's minute hand
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New color of minute hand
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_analog_clock_min_hand_color(gui_clock_struct *c, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->analog_hand_min_color = new_color;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_date_text_font
 * DESCRIPTION
 *  set the date text font of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_font        [IN]        New font of date text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_date_text_font(gui_clock_struct *c, UI_font_type new_font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->date_text_font = new_font;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_date_text_color
 * DESCRIPTION
 *  set the date text color of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_date_text_color(gui_clock_struct *c, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->date_text_color = new_color;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_date_text_border_color
 * DESCRIPTION
 *  set the date text border color of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New border color of date text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_date_text_border_color(gui_clock_struct *c, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->date_text_border_color = new_color;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_time_text_font
 * DESCRIPTION
 *  set the font of time text 
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_font        [IN]        New font of time text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_time_text_font(gui_clock_struct *c, UI_font_type new_font)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->time_text_font = new_font;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_time_text_color
 * DESCRIPTION
 *  set the color of time text 
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_time_text_color(gui_clock_struct *c, color new_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->time_text_color = new_color;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_time_text_border_color
 * DESCRIPTION
 *  set the border color of time text 
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  new_color       [IN]        New border color of time text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_time_text_border_color (gui_clock_struct *c, color new_color)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->time_text_border_color = new_color;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_gap_between_two_lines
 * DESCRIPTION
 *  set the gap between date text and time text
 * PARAMETERS
 *  c           [IN]        Pointer of clock component
 *  new_gap     [IN]        New gap between date text and time text
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_gap_between_two_lines(gui_clock_struct *c, S32 new_gap)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    if(new_gap < 0)
    {
        return;
    }

    c->gap_between_two_lines = new_gap;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_measure_time_text
 * DESCRIPTION
 *  get the width and height of time text
 * PARAMETERS
 *  c                   [IN]         
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_measure_time_text(gui_clock_struct *c, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    applib_time_struct time_to_show;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(font);
    gui_clock_get_clock_show_time(c, &time_to_show);
    time_to_show.nHour = 8;
    time_to_show.nMin = 22;
    gui_clock_time_string(&time_to_show, (U8*)s, c->type);
    gui_measure_string((UI_string_type)s, w, h);
    /* return a unified value of bordered text */
    *w = *w + 2;
    *h = *h + 2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_measure_date_text
 * DESCRIPTION
 *  get the width and height of date text
 * PARAMETERS
 *  c                   [IN]         
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 *  font                [IN]        Font
 *  clock_type(?)       [IN]        Clock type
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_measure_date_text(gui_clock_struct *c, S32 *w, S32 *h, UI_font_type font)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_character_type s[64];
    applib_time_struct time_to_show;
    S32 i, width;
    S32 date_seperator, date_format;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_set_font(font);
    gui_clock_get_clock_show_time(c, &time_to_show);
    time_to_show.nDay = 28;
    time_to_show.nYear = 8888;
    *w = 0;
#if defined(__IOT__)
    date_seperator = srv_setting_get_date_seperator();
    date_format = srv_setting_get_date_format();
#else
    date_seperator = PhnsetGetDateSeperatorFormat();
    date_format = PhnsetGetDateFormat();
#endif
    for (i = 1; i <= 12; i++)
    {
        time_to_show.nMonth = i;
        gui_clock_date_string(
            &time_to_show,
            (U8*)s,
            c->type,
            date_seperator,
            date_format);
        gui_measure_string((UI_string_type)s, &width, h);
        if (width > *w)
        {
            *w = width;
        }
    }
    /* return a unified value of bordered text */
    *w = *w + 2;
    *h = *h + 2;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_text_border_enable
 * DESCRIPTION
 *  enable the border text or not
 * PARAMETERS
 *  c           [IN]        Pointer of clock component
 *  enable      [IN]        Enable
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_text_border_enable(gui_clock_struct *c, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_DBG_ASSERT(c != NULL);

    c->border_enable = enable;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_target_layer
 * DESCRIPTION
 *  set target layer of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  target_layer    [IN]        target layer of clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_target_layer(gui_clock_struct *c, GDI_HANDLE target_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c->target_layer = target_layer;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_abm_layer
 * DESCRIPTION
 *  set alpha blending layer of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  abm_layer       [IN]        alpha blending layer of clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_abm_layer(gui_clock_struct *c, GDI_HANDLE abm_layer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c->abm_layer = abm_layer;
}


/* add gui_clock_default_hide_function for orange, need verify for datetime */
/*****************************************************************************
 * FUNCTION
 *  gui_clock_default_hide_function
 * DESCRIPTION
 *  use transparent color to redraw clock bg  
 * PARAMETERS
 *  coordinate      [IN]     Area to redraw
 * RETURNS
 *  void
 *****************************************************************************/
/*
static void gui_clock_default_hide_function(S32 x1, S32 y1, S32 x2, S32 y2)
{
    gui_push_clip();
    gui_set_clip(x1, y1, x2, y2);
    gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
    gui_pop_clip();
}
*/


/*****************************************************************************
 * FUNCTION
 *  gui_clock_set_digital_align_type
 * DESCRIPTION
 *  set digital align type of clock
 * PARAMETERS
 *  c               [IN]        Pointer of clock component
 *  type            [IN]        align type of digital clock
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_set_digital_align_type(gui_clock_struct *c, gui_clock_digital_align_enum type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    c->align_type = type;
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_measure_digital_clock
 * DESCRIPTION
 *  get the width and height of digital clock that using image
 * PARAMETERS
 *  c                   [IN]        Pointer of clock component
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_measure_digital_clock(gui_clock_struct *c, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
    S32 image_w = 0, image_h = 0;
    S32 count;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *w = 0;
    *h = 0;
#if defined(__MMI_DIGITAL_CLOCK_IMAGE_NUMBER__)
        gdi_image_get_dimension_id(
            IMG_TECHNO_DIGITAL_CLOCK_0,
            &image_w,
            &image_h);
        count = GUI_CLOCK_DIGITAL_CLOCK_NUMBER_COUNT;
        
        /* 24 hour, 00:00, total 5 numbers */                
        *w = image_w * count + 
            GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP * (count - 1);
        *h = image_h;

        /* measure colon */
        gdi_image_get_dimension_id(
                IMG_TECHNO_DIGITAL_CLOCK_COLON,
                &image_w,
                &image_h);
        *w += image_w + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;

        if (!PhnsetGetTimeFormat()) /* get current time format */
        {
            gdi_image_get_dimension_id(
                IMG_TECHNO_DIGITAL_CLOCK_AM,
                &image_w,
                &image_h);
            *w = *w + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP + image_w;
        }
#endif
}


/*****************************************************************************
 * FUNCTION
 *  gui_clock_measure_digital_small_clock
 * DESCRIPTION
 *  get the width and height of digital clock that using small image
 * PARAMETERS
 *  c                   [IN]        Pointer of clock component
 *  w                   [OUT]       Return width
 *  h                   [OUT]       Retrun height
 * RETURNS
 *  void
 *****************************************************************************/
void gui_clock_measure_digital_small_clock(gui_clock_struct *c, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
    S32 image_w, image_h;
    S32 count;
#endif /* __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *w = 0;
    *h = 0;
#ifdef __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__
    gdi_image_get_dimension_id(
        IMG_TECHNO_DIGITAL_SMALL_CLOCK_0,
        &image_w,
        &image_h);
    count = GUI_CLOCK_DIGITAL_CLOCK_NUMBER_COUNT;
        
    /* 24 hour, 00:00, total 5 numbers */                
    *w = image_w * count + 
         GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP * (count - 1);
    *h = image_h;

    /* measure colon */
    gdi_image_get_dimension_id(
        IMG_TECHNO_DIGITAL_SMALL_CLOCK_COLON,
        &image_w,
        &image_h);
    *w += image_w + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP;

    if (!PhnsetGetTimeFormat()) /* get current time format */
    {
        gdi_image_get_dimension_id(
            IMG_TECHNO_DIGITAL_SMALL_CLOCK_AM,
            &image_w,
            &image_h);
        *w = *w + GUI_CLOCK_DIGITAL_CLOCK_IMAGE_GAP + image_w;
    }
#endif /* __MMI_UI_CLOCK_SMAILL_DIGITAL_IMAGE_CLOCK__ */
}



