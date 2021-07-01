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
 *  gui_picker.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Picker CP
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 05 23 2014 anne.xu
 * removed!
 * .Wearable Device 11C1418MP
 *
 * 05 20 2014 anne.xu
 * removed!
 * .Wearable Device 11CW1418MP code check in
 *
 * 12 19 2013 renxiao.zeng
 * removed!
 * .
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 *******************************************************************************/
     
#include "MMI_features.h"

#ifdef __MMI_UI_TIME_PICKER__
#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"

#include "gui_data_types.h"
#include "gui.h"
#include "gui_typedef.h"
#include "gui_inputs.h"
#include "ImeGprot.h"
#include "ImeGprotEnums.h"
#include "mmi_rp_app_uiframework_def.h"

 
#ifndef __GUI_PICKER_H__
#define __GUI_PICKER_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#define GUI_PICKER_BORDER_GAP   (2)

#define GUI_PICKER_MAX_BIT   (5)  //must be less than this
#define GUI_PICKER_MAX_NUM  (10000)  //must be less than this

#define GUI_PICKER_TEXT_BUFFER_SIZE ((GUI_PICKER_MAX_BIT+7)/8*8)
#define GUI_PICKER_TEXT_X_OFFSET (4)

#define GUI_PICKER_INVALID_INDEX    (-1)
#define GUI_PICKER_INVALID_NUM      (-1)

//for cosmos style picker
#define GUI_PICKER_9_SLICE_BG_LEFT   (6)
#define GUI_PICKER_9_SLICE_BG_TOP    (32)//(44)
#define GUI_PICKER_9_SLICE_BG_RIGHT  (7)
#define GUI_PICKER_9_SLICE_BG_BOTTOM (10)//(22)
#define GUI_PICKER_SHADOWN_HEIGHT    (18)
#define GUI_PICKER_ARROW_WIDTH       (13)
#define GUI_PICKER_ARROW_HEIGHT      (27)
#define GUI_PICKER_COLUMNE_GAP       (1)
#define GUI_PICKER_NUMBER_X_OFFSET   (30)

#define GUI_PICKER_SHADOW_HEIGHT     (18)

#define GUI_PICKER_TEXT_COLOR_GRAY          gui_color(178, 178, 178)
#define GUI_PICKER_TEXT_COLOR_THIN_BLACK    gui_color(100, 100, 100)
#define GUI_PICKER_TEXT_COLOR_WHITE         gui_color(255, 255, 255)
#define GUI_PICKER_TEXT_COLOR_BLACK         gui_color(0, 0, 0)
#define GUI_PICKER_TEXT_COLOR_BLUE          gui_color(0, 192, 255)

#ifdef __MMI_WEARABLE_DEVICE__
#define GUI_PICKER_TEXT_COLOR_1          gui_color(149, 156, 172)
#define GUI_PICKER_TEXT_COLOR_2          gui_color(90, 94, 105)
#endif /*__MMI_WEARABLE_DEVICE__*/

#define GUI_PICKER_MAX_COLUMN    (3)  //max column in a picker

#define GUI_PICKER_MAX_DISPLAY_ROW  (5)

#define __GUI_PICKER_SSP_AUTO_FREE_RUN__


//SSP
#define GUI_PICKER_SSP_TIMER_DELAY      (100)
#define GUI_PICKER_SSP_RECOVER_STEP     (20)
#define GUI_PICKER_SSP_REDUCING_FACTOR  (0.2)
#define GUI_PICKER_SSP_FREE_RUN_SPEED   (60)
#ifdef __GUI_PICKER_SSP_AUTO_FREE_RUN__
#define GUI_PICKER_SSP_FREE_RUN_THRESHOLD   (10)  //when move diff lager than this, auto free run
#define GUI_PICKER_SSP_TIME_THRESHOLD       (300)  //when time less than this, auto free run
#define GUI_PICKER_SSP_STOP_THRESHOLD       (20)  //when speed less than this, stop free run
#endif

#define __RANFOW_TUNING__

#ifdef __RANFOW_TUNING__
#define PICKER_TUNING_LOOP  (1)  //picker can loop
#define PICKER_TUNING_DIALER_SHOW_MATRIX    (2)
#endif  //__RANFOW_TUNING__


#define GUI_PICKER_NO_ERROR             (0)
#define GUI_PICKER_ERROR_WRONG_TYPE     (-1)
#define GUI_PICKER_ERROR_WRONG_STYLE    (-2)

typedef enum
{
    GUI_PICKER_SSP_STATE_NONE,
    GUI_PICKER_SSP_STATE_HOLD,
    GUI_PICKER_SSP_STATE_MOVE,
    GUI_PICKER_SSP_STATE_FREE_RUN,  //no use in picker now
    GUI_PICKER_SSP_STATE_RECOVER
} gui_picker_ssp_state;

typedef enum
{
    GUI_PICKER_NUM_COLOR_WHITE,
    GUI_PICKER_NUM_COLOR_BLACK,
    GUI_PICKER_NUM_COLOR_MAX
} gui_picker_num_color;

typedef enum
{
    GUI_PICKER_TYPE_DATE,  //there will be three pages
    GUI_PICKER_TYPE_YEAR,
    GUI_PICKER_TYPE_MONTH_AND_DAY,
    GUI_PICKER_TYPE_TIME,
    GUI_PICKER_TYPE_MAX
} gui_picker_type;

typedef enum
{
    GUI_PICKER_SWITCH_TYPE_LEFT,
    GUI_PICKER_SWITCH_TYPE_RIGHT,
    GUI_PICKER_SWITCH_TYPE_UP,
    GUI_PICKER_SWITCH_TYPE_DOWN,
    GUI_PICKER_SWITCH_TYPE_MAX
} gui_picker_switch_type;

typedef enum
{
    GUI_PICKER_HINT_POSITION_CLOSE_TO_CENTER,  //hint will be close to center
    GUI_PICKER_HINT_POSITION_AUTO_BY_BOUND  //hint will has the same bound as center, and auto position
} gui_picker_hint_position_type;

typedef enum
{
    GUI_PICKER_STYLE_START,
    GUI_PICKER_STYLE_COSMOS = GUI_PICKER_STYLE_START,
    GUI_PICKER_STYLE_END = GUI_PICKER_STYLE_COSMOS,
} gui_picker_style;



#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    GUI_PICKER_PEN_STATUS_NONE,
    GUI_PICKER_PEN_STATUS_DOWN_IN_BOUND,
    GUI_PICKER_PEN_STATUS_DOWN_IN_VISIBLE,
    GUI_PICKER_PEN_STATUS_MAX
} gui_picker_pen_status;
#endif  //__MMI_TOUCH_SCREEN__



typedef U16 (*gui_picker_get_switch_func_ptr)(U16 current_value, gui_picker_switch_type switch_type, U8 switch_offset);


typedef struct
{
    U8 column;
    U8 line_height;
    U8 bit[GUI_PICKER_MAX_COLUMN];
    U16 number[GUI_PICKER_MAX_COLUMN];
    gui_picker_get_switch_func_ptr get_switch_func[GUI_PICKER_MAX_COLUMN];
    gui_bound column_bound[GUI_PICKER_MAX_COLUMN];
    U16 column_name_id[GUI_PICKER_MAX_COLUMN];
} gui_picker_number_struct;

typedef struct
{
    gui_picker_type type;
    gui_picker_style style;
} gui_picker_header;

typedef struct
{
    gui_picker_header header;
	#ifdef __MMI_WEARABLE_DEVICE__
	MMI_BOOL two_page;  //whether divide to two page
	#endif //__MMI_WEARABLE_DEVICE__
    U8 display_row;  //how many row to display(the center will always be selected, it must be odd)
    U16 min_year;
    U16 max_year;
    U16 current_year;
    U8 month;
    U8 day;
} gui_picker_date_struct;

typedef struct
{
    gui_picker_header header;
    U8 display_row;  //how many row to display(the center will always be selected, it must be odd)
    U16 min_year;
    U16 max_year;
    U16 current_year;
} gui_picker_year_struct;

typedef struct
{
    gui_picker_header header;
    MMI_BOOL two_page;  //whether divide to two page
    U8 display_row;  //how many row to display(the center will always be selected, it must be odd)
    U8 month;
    U8 day;
} gui_picker_month_and_day_struct;

typedef struct
{
    gui_picker_header header;
    MMI_BOOL two_page;  //whether divide to two page
    U8 display_row;  //how many row to display(the center will always be selected, it must be odd)
    U8 hour;
    U8 minute;
	#ifdef __MMI_WEARABLE_DEVICE__ //xl
	U8 am_pm;
	#endif
} gui_picker_time_struct;

#define GUI_PICKER_STRUCT_MAX_SIZE ((sizeof(gui_picker_date_struct)+31)/32*32)

typedef struct
{
#ifdef __RANFOW_TUNING__
    U8 inject_index;
#endif  //__RANFOW_TUNING__
    U8 highlight_index;  //current highlight index
#ifdef __MMI_TOUCH_SCREEN__
    S16 pos_offset;
    U32 pen_down_time;
#ifdef __GUI_PICKER_SSP_AUTO_FREE_RUN__
    float ssp_speed;
#endif
    gui_picker_pen_status pen_status;
    mmi_pen_point_struct pen_down_pos;
    mmi_pen_point_struct last_pen_move_pos;
#endif  //__MMI_TOUCH_SCREEN__
    gui_bound effective_bound;
    gui_bound original_bound;
    gui_picker_ssp_state ssp_state;
    gui_picker_number_struct picker_number;
    U8 user_data[GUI_PICKER_STRUCT_MAX_SIZE];  //provide memory for user
#ifdef __MMI_WEARABLE_DEVICE__
	MMI_BOOL highlight_change;
#endif /*__MMI_WEARABLE_DEVICE__*/    
} gui_picker_context_struct;




/***************************************************************************** 
* Extern Global Function
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  gui_picker_set_highlight
 * DESCRIPTION
 *  Set picker highlight item (use for month&day or time)
 * PARAMETERS
 *  highlight_index
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_picker_set_highlight(U8 highlight_index);

/*****************************************************************************
 * FUNCTION
 *  gui_picker_get_user_data
 * DESCRIPTION
 *  Get Picker user data
 * PARAMETERS
 *  void
 * RETURNS
 *  U8*
 *****************************************************************************/
extern U8* gui_picker_get_user_data(void);

/*****************************************************************************
 * FUNCTION
 *  gui_picker_create
 * DESCRIPTION
 *  Create Picker
 * PARAMETERS
 *  user_data [IN] it contains a gui picker struct
 *  bound [IN] the whole area picker in
 * RETURNS
 *  U8  -- if error, will return error code
 *****************************************************************************/
extern U8 gui_picker_create(U8* user_data, gui_bound bound);

/*****************************************************************************
 * FUNCTION
 *  gui_picker_reset
 * DESCRIPTION
 *  Reset Picker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_picker_reset(void);

/*****************************************************************************
 * FUNCTION
 *  gui_picker_show
 * DESCRIPTION
 *  Show Picker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_picker_show(void);

/*****************************************************************************
 * FUNCTION
 *  gui_picker_inject_string
 * DESCRIPTION
 *  This function handle inject string. only available when __RANFOW_TUNING__ is defined
 * PARAMETERS
 *  index
 * RETURNS
 *  U8
 *****************************************************************************/
extern U8 gui_picker_inject_string(U8 index);


#endif  //__GUI_PICKER_H__
#endif  //__MMI_UI_TIME_PICKER__
