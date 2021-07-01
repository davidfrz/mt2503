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
 *  gui_dialer_pad.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Dialer Pad
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 12 19 2013 renxiao.zeng
 * removed!
 * .
 *
 * 10 21 2013 ye.tian
 * removed!
 * -BT box2 patch 11C.
 *
 * 10 09 2013 ye.tian
 * removed!
 * -fix QA issue.
 *
 * 09 25 2013 ye.tian
 * removed!
 * -make __MMI_UI_DIALER_PAD_ONLY_KEY__ depend on __MMI_TOUCH_SCREEN__ off  .
 * Or __MMI_BT_BOX_TEST_DIALER_PAD_STYLE__ on.
 *
 * 09 23 2013 shengxi.xu
 * removed!
 * - Check in dialer pad for non touch
 *
 * 09 18 2013 shengxi.xu
 * removed!
 * -Check in for dialer pad
 *
 * 09 13 2013 ye.tian
 * removed!
 * update Dialer pad UI and phone setting set dialer pad UI style.
 * 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================
 *******************************************************************************/
     
#include "MMI_features.h"

#ifdef __MMI_UI_DIALER_PAD__
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


#if (!defined(__MMI_TOUCH_SCREEN__)) || defined(__MMI_BT_BOX_TEST_DIALER_PAD_STYLE__) 
#define __MMI_UI_DIALER_PAD_ONLY_KEY__
#endif

 
#ifndef __GUI_DIALER_PAD_H__
#define __GUI_DIALER_PAD_H__

/***************************************************************************** 
* Define
*****************************************************************************/
#define GUI_DIALER_PAD_BORDER_GAP   (2)
#define GUI_DIALER_PAD_MATRIX_MAX_NUM    (15)

#define GUI_DIALER_PAD_PEN_DOWN_DELAY    (500)

#define GUI_DIALER_PAD_MAX_BIT   (5)  //must be less than this
#define GUI_DIALER_PAD_MAX_NUM  (10000)  //must be less than this

#define GUI_DIALER_PAD_TEXT_BUFFER_SIZE ((GUI_DIALER_PAD_MAX_BIT+7)/8*8)
#define GUI_DIALER_PAD_TEXT_X_OFFSET (4)

#define GUI_DIALER_PAD_INVALID_INDEX    (-1)
#define GUI_DIALER_PAD_INVALID_NUM      (-1)

#define GUI_DIALER_PAD_TEXT_COLOR_GRAY          gui_color(178, 178, 178)
#define GUI_DIALER_PAD_TEXT_COLOR_THIN_BLACK    gui_color(100, 100, 100)
#define GUI_DIALER_PAD_TEXT_COLOR_WHITE         gui_color(255, 255, 255)
#define GUI_DIALER_PAD_TEXT_COLOR_BLACK         gui_color(0, 0, 0)


#define GUI_DIALER_PAD_MAX_COLUMN    (3)  //max column in a picker

#define GUI_DIALER_PAD_MAX_DISPLAY_ROW  (5)

#ifdef __MMI_TOUCH_SCREEN__
#define GUI_DIALER_PAD_PEN_MOVE_SWITCH_THRESHOLD    (15)
#endif


#define GUI_DIALER_PAD_NO_ERROR             (0)
#define GUI_DIALER_PAD_ERROR_WRONG_STYLE    (-1)
#define GUI_DIALER_PAD_ERROR_ILEGAL_DATA    (-2)



typedef enum
{
    GUI_DIALER_PAD_NUM_COLOR_WHITE,
    GUI_DIALER_PAD_NUM_COLOR_BLACK,
    GUI_DIALER_PAD_NUM_COLOR_MAX
} gui_dialer_pad_num_color;

typedef enum
{
    GUI_DIALER_PAD_SWITCH_TYPE_LEFT,
    GUI_DIALER_PAD_SWITCH_TYPE_RIGHT,
    GUI_DIALER_PAD_SWITCH_TYPE_UP,
    GUI_DIALER_PAD_SWITCH_TYPE_DOWN,
    GUI_DIALER_PAD_SWITCH_TYPE_MAX
} gui_dialer_pad_switch_type;

typedef enum
{
    GUI_DIALER_PAD_SWITCH_DIRECTION_HORIZONTAL,
    GUI_DIALER_PAD_SWITCH_DIRECTION_VERTICAL,
    GUI_DIALER_PAD_SWITCH_DIRECTION_MAX
} gui_dialer_pad_switch_direction;

typedef enum
{
    GUI_DIALER_PAD_STYLE_START,
    GUI_DIALER_PAD_STYLE_MATRIX = GUI_DIALER_PAD_STYLE_START,
    GUI_DIALER_PAD_STYLE_HORIZONTAL_ROLL,
    GUI_DIALER_PAD_STYLE_VK,
    GUI_DIALER_PAD_STYLE_MAP,
    GUI_DIALER_PAD_STYLE_VK_KEY,
    GUI_DIALER_PAD_STYLE_DIALER_CICUAL_ROLL,
    GUI_DIALER_PAD_STYLE_END = GUI_DIALER_PAD_STYLE_DIALER_CICUAL_ROLL
} gui_dialer_pad_style;



#ifdef __MMI_TOUCH_SCREEN__
typedef enum
{
    GUI_DIALER_PAD_PEN_STATUS_NONE,
    GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_BOUND,
    GUI_DIALER_PAD_PEN_STATUS_DOWN_IN_VISIBLE,
    GUI_DIALER_PAD_PEN_STATUS_MAX
} gui_dialer_pad_pen_status;
#endif  //__MMI_TOUCH_SCREEN__



typedef S16 (*gui_dialer_pad_get_highlight_matrix_index)(void);


//Dialer Picker will emulate key event(like key down/longpress/up)
typedef struct
{
    U8 image_index;
    U8 ch;
    U8 key_code;
} gui_dialer_pad_matrix_struct;

typedef struct
{
#ifdef __MMI_TOUCH_SCREEN__
    mmi_pen_hdlr pen_down_hdlr;
    mmi_pen_hdlr pen_move_hdlr;
    mmi_pen_hdlr pen_repeat_hdlr;
    mmi_pen_hdlr pen_up_hdlr;
#endif
    FuncPtr show_func;
    FuncPtr goto_previous;
    FuncPtr goto_next;
    gui_dialer_pad_get_highlight_matrix_index get_highlight_matrix_index;
} gui_dialer_pad_hdlr_struct;

typedef struct
{
#ifdef __RANFOW_TUNING__
    U8 inject_index;
#endif  //__RANFOW_TUNING__
    U8 highlight_index;  //current highlight index
#ifdef __MMI_TOUCH_SCREEN__
    S16 pos_offset;
    U32 pen_down_time;
    gui_dialer_pad_pen_status pen_status;
    mmi_pen_point_struct pen_down_pos;
    mmi_pen_point_struct last_pen_move_pos;
#endif  //__MMI_TOUCH_SCREEN__
    gui_bound effective_bound;
    gui_bound original_bound;
    gui_dialer_pad_hdlr_struct dialer_hdlr;
    gui_dialer_pad_style style;
    S16 matrix_index;  /* index is from 0 to 11, [1, 2, 3, 4, 5, 6, 7, 8, 9, *, 0, #] proposal to be 4 */
} gui_dialer_pad_context_struct;




/***************************************************************************** 
* Extern Global Function
*****************************************************************************/

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
extern U16 gui_dialer_pad_get_highlight(void);

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_create
 * DESCRIPTION
 *  Create Dialer Pad
 * PARAMETERS
 *  style [IN] the dialer pad style
 *  bound [IN] the whole area picker in
 * RETURNS
 *  U8  -- if error, will return error code
 *****************************************************************************/
extern U8 gui_dialer_pad_create(gui_dialer_pad_style style, gui_bound bound);

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_show
 * DESCRIPTION
 *  Show Picker
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_dialer_pad_show(void);

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
extern void gui_dialer_pad_register_key_hdlr(void);

#ifdef __MMI_TOUCH_SCREEN__
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
extern void gui_dialer_pad_register_pen_hdlr(void);
#endif  //__MMI_TOUCH_SCREEN__

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
extern U8 gui_dialer_pad_inject_string(U8 index);
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
extern gui_dialer_pad_style gui_dialer_pad_get_style(void);



#define  GUI_DIALER_PAD_HORIZONTAL_DIALER
#ifdef GUI_DIALER_PAD_HORIZONTAL_DIALER
//#define DEBUG_BT_BOX_PEN_MOVE_DIALER_UI

typedef enum
{
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_START = 0,
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_DELAY,
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_PEN_UP_TIME_OUT,
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_GET_INDEX,
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE_AFTER_INSERT_CHAR,
    GUI_DIALER_PAD_HORIZONTAL_VK_STYLE__END 
} gui_dialer_pad_horizontal_vk_style;

typedef struct
{   
    U8 default_show_state; //init seting when highlight change
    U8 default_max_show_state; //init seting when highlight change
    U8 default_min_show_state; //init seting when highlight change
    U8 show_state; //every one 7 class  ,from 1 to 7 
    U8 change_flag; // 1 large to small ,2 small to large
    U8 show_flag; // 1 show ,0 no show
    U8 index;    
} gui_dialer_pad_horizontal_show_image_struct;

typedef struct
{  
    U16 w; // image with
    U16 h; // image hight
    S32 alpha;
} gui_dialer_pad_horizontal_show_image_default_setting_struct;

typedef struct
{  
    S16 show_x; // image x
    S16 show_y; // image y
    U16 show_w; // image with
    U16 show_h; // image hight
    
} gui_dialer_pad_horizontal_show_image_temp_struct;

typedef struct
{  
    S32  x1; 
    S32  y1; 
	S32  x2; 
    S32  y2;
	S32 move_x_offset ;	   // one once pen move size
	S32 auto_move_x_offset ;	   // one once pen move size
	void (*show_frame)(void); // show frame func
	mmi_pen_point_struct move_point;  //current pen move point
	mmi_pen_point_struct old_point;   //current pen down point 
	U8 move_flag ;	       // pen mvoe flag   
	U8 auto_move_flag ;	       // pen mvoe flag  
	U8 highlight_change ;   // highlight item need change flag
	U8 highlight_item ;  //current highlight item image index ID
	U8 old_highlight_item ; //last highlight item image index ID
	U8 highlight_index ;   //Enlage UI highlight image index 
	U8 other_ui_flag ;     //Enlage UI enable flag
	U8 move_key_redraw_frame; // for key event redraw frame
	U8 vk_highlight_invalid ;    // 1: vk no highlight 0: vk have highlight
    mmi_pen_event_type_enum pen_state ;         // 0: no state 
    gui_dialer_pad_horizontal_vk_style up_time_out_flag;
    U8 highlight_index_times;    // for record pop "*" times ,make it change slow ,get many repeat event then change one time
} gui_dialer_pad_horizontal_struct;


#define GUI_DIALER_PAD_HORIZONTAL_MOVE_TIMER  (100)

#define GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_LEFT  (1)
#define GUI_DIALER_PAD_HORIZONTAL_MOVE_TO_RIGHT (2)
#define GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_LEFT  (1)
#define GUI_DIALER_PAD_HORIZONTAL_AUTO_MOVE_TO_RIGHT (2)

#define GUI_DIALER_PAD_HORIZONTAL_MOVE_DOWN_SHOW_HIGHLIGHT    (10)

#define GUI_DIALER_PAD_HORIZONTAL_LARGE_TO_SMALL  (1)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_TO_LARGE  (2)



#if  defined(__MMI_MAINLCD_320X240__)
#if 1
#define GUI_DIALER_PAD_HORIZONTAL_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_Y1  (100)
#define GUI_DIALER_PAD_HORIZONTAL_Y2  (200) 

#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_1  (60)//8
#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_2  (60)//14 
#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_3  (40)//15 


#define GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_W (70) 
#define GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_H (70)

#define GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_W (20)
#define GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_H (10)

#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W  (50) // when pen move this width then change hightlight index
#define GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W  (10) // when pen move this width then change hightlight item image state


#define GUI_DIALER_PAD_HORIZONTAL_KEY_COUNT (15)   // all key count

#define GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT (7)  // it should be  2n+1

#define GUI_DIALER_PAD_HORIZONTAL_HIHGLIGHT_SMALL (3) // let highlight change small quickly


#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES (2)//((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)/2)//5




#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_HIGHLIGHT_ITEM  (2) 
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES    (7)  //it should be 2n+1
//#define GUI_DIALER_PAD_HORIZONTAL_COUNT_STATES            (100)  // should < 255


#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_STATE  (3)


//////////////////////
//only for UI_SHOW_TYPE_VK_POP  UI
#define GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT   (0)//(90) //(200)
#define GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT2  (0)//(50) //(100)


#define GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT (12)  // pop up UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_VK_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_VK_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_VK_Y1  (18)
#define GUI_DIALER_PAD_HORIZONTAL_VK_Y2  (200) 

#define GUI_DIALER_PAD_HORIZONTAL_POP_W (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W)
#define GUI_DIALER_PAD_HORIZONTAL_POP_H (65)


#define GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT (4)
#define GUI_DIALER_PAD_HORIZONTAL_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_START_Y (GUI_DIALER_PAD_HORIZONTAL_VK_Y1+4+GUI_DIALER_PAD_HORIZONTAL_POP_H) 
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H (35)
#define GUI_DIALER_PAD_HORIZONTAL_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_MARGIN_H (4)


#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_IMAGE_W (35)


#define GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START (11)
#define GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END (14)

#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_INDEX_TIMES_MAX (3) 

#define GUI_DIALER_PAD_HORIZONTAL_VK_BUTTTON_SMALL (6)

#define GUI_DIALER_PAD_HORIZONTAL_VK_ALPHA   (223)

//////////////////////
//only for UI_SHOW_TYPE_VK_KEY POP   UI
#define GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT (12)  // pop up UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y1  (78)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y2  (200)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_H (35)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_H (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_Y (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y1+12) 
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT (4)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_H (4)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_BUTTTON_SMALL (6)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_BUTTTON_HIGHLIGHT_MOVE_UP (0)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ALPHA   (200)
//////////////////////
//only for UI_SHOW_TYPE_SMALL_MAP_TO_LARGE_BUTTON  UI

#define GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT (12)  // pop up key UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y1  (87)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y2  (200)


#define GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_SMALL_MAP_COUNT (3)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_Y (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y1+19) 

#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W (35)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H (15)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_H (4)

#define GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_X  (170)
#define GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_y  (150) 

#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_X  (30)
#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_Y  (122) 

#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_MAX_X  (62)


/////////////////////
#endif  
#else /*__MMI_MAINLCD_320X240__*/

#if 1
#define GUI_DIALER_PAD_HORIZONTAL_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_Y1  (100)
#define GUI_DIALER_PAD_HORIZONTAL_Y2  (200) 

#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_1  (60)//8
#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_2  (60)//14 
#define GUI_DIALER_PAD_HORIZONTAL_WIDTH_3  (40)//15 


#define GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_W (70) 
#define GUI_DIALER_PAD_HORIZONTAL_LARGEST_IMAGE_H (70)

#define GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_W (20)
#define GUI_DIALER_PAD_HORIZONTAL_LEAST_IMAGE_H (10)

#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W  (50) // when pen move this width then change hightlight index
#define GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W  (10) // when pen move this width then change hightlight item image state


#define GUI_DIALER_PAD_HORIZONTAL_KEY_COUNT (15)   // all key count

#define GUI_DIALER_PAD_HORIZONTAL_SHOW_KEY_COUNT (7)  // it should be  2n+1

#define GUI_DIALER_PAD_HORIZONTAL_HIHGLIGHT_SMALL (3) // let highlight change small quickly


#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MIN_STATE_TIMES (2)//((GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_MOVE_W/GUI_DIALER_PAD_HORIZONTAL_ONE_STATE_CHANGE_MOVE_W)/2)//5




#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_HIGHLIGHT_ITEM  (2) 
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_COUNT_STATES    (7)  //it should be 2n+1
//#define GUI_DIALER_PAD_HORIZONTAL_COUNT_STATES            (100)  // should < 255


#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_CHANGE_STATE  (3)


//////////////////////
//only for UI_SHOW_TYPE_VK_POP  UI
#define GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT   (0)//(90) //(200)
#define GUI_DIALER_PAD_HORIZONTAL_VK_POP_TIMEOUT2  (0)//(50) //(100)

#define GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT (12)  // pop up UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_VK_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_VK_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_VK_Y1  (18)
#define GUI_DIALER_PAD_HORIZONTAL_VK_Y2  (200) 

#define GUI_DIALER_PAD_HORIZONTAL_POP_W (GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W)
#define GUI_DIALER_PAD_HORIZONTAL_POP_H (65)


#define GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_COUNT (4)
#define GUI_DIALER_PAD_HORIZONTAL_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_START_Y (GUI_DIALER_PAD_HORIZONTAL_VK_Y1+4+GUI_DIALER_PAD_HORIZONTAL_POP_H) 
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_H (35)
#define GUI_DIALER_PAD_HORIZONTAL_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_MARGIN_H (4)


#define GUI_DIALER_PAD_HORIZONTAL_DEFAULT_IMAGE_W (35)


#define GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_START (11)
#define GUI_DIALER_PAD_HORIZONTAL_STAR_KEY_INDEX_END (14)

#define GUI_DIALER_PAD_HORIZONTAL_HIGHLIGHT_INDEX_TIMES_MAX (3) 

#define GUI_DIALER_PAD_HORIZONTAL_VK_BUTTTON_SMALL (6)

#define GUI_DIALER_PAD_HORIZONTAL_VK_ALPHA   (223)

//////////////////////
//only for UI_SHOW_TYPE_VK_KEY POP   UI
#define GUI_DIALER_PAD_HORIZONTAL_POP_KEY_UI_SHOW_KEY_COUNT (12)  // pop up UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y1  (78)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y2  (200)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_H (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_DEFAULT_IMAGE_W (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_H (35)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_W (75)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_HIGH_BG_H (35)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_START_Y (GUI_DIALER_PAD_HORIZONTAL_VK_KEY_Y1+12) 
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ONE_LINE_COUNT (4)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_MARGIN_H (4)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_BUTTTON_SMALL (6)

#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_BUTTTON_HIGHLIGHT_MOVE_UP (0)


#define GUI_DIALER_PAD_HORIZONTAL_VK_KEY_ALPHA   (200)
//////////////////////
//only for UI_SHOW_TYPE_SMALL_MAP_TO_LARGE_BUTTON  UI

#define GUI_DIALER_PAD_HORIZONTAL_POP_UI_SHOW_KEY_COUNT (12)  // pop up key UI just show 12 keys


#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X1  (0)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_X2  (320)

#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y1  (87)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y2  (200)


#define GUI_DIALER_PAD_HORIZONTAL_ONE_LINE_SMALL_MAP_COUNT (3)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_X (3) 
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_START_Y (GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_Y1+19) 

#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_W (35)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_DEFAULT_H (15)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_W (4)
#define GUI_DIALER_PAD_HORIZONTAL_SMALL_MAP_MARGIN_H (4)

#define GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_X  (170)
#define GUI_DIALER_PAD_HORIZONTAL_DOING_BUTTON_y  (150) 

#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_X  (30)
#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_Y  (122) 

#define GUI_DIALER_PAD_HORIZONTAL_LARGE_MAP_BUTTON_MAX_X  (62)


/////////////////////
#endif  


#endif /*__MMI_MAINLCD_320X240__*/

extern void gui_dialer_pad_horizontal_cancel_pop_up_timer(void);
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_check_cancel_timer
 * DESCRIPTION
 *  check cancel auto move timer
 * PARAMETERS
 *  void 
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void gui_dialer_pad_horizontal_check_cancel_timer(void);

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
void gui_dialer_pad_horizontal_next_item();
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
void gui_dialer_pad_horizontal_prev_item();
/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_horizontal_init
 * DESCRIPTION
 *  initialze gui_dialer_pad_horizontal struct 
 * PARAMETERS
 *  ui_type [U8] set UI type 
 *  
 *  
 * RETURNS 
 * void
 *****************************************************************************/
void gui_dialer_pad_horizontal_init(U8 ui_type);

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
MMI_BOOL gui_dialer_pad_horizontal_check_highlight_item_range(mmi_pen_point_struct point);
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
void gui_dialer_pad_small_map_large_button_show_frame();
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
void gui_dialer_pad_vk_pop_show_frame();
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
void gui_dialer_pad_vk_pop_key_show_frame();

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
void gui_dialer_pad_horizontal_show_frame();
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
U8 gui_dialer_pad_horizontal_get_next_item(U8 current_item);
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
U8 gui_dialer_pad_horizontal_get_prev_item(U8 current_item);
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
void gui_dialer_pad_horizontal_move_change_highlight(U8 change_times);
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
void gui_dialer_pad_horizontal_move_reset_item_with_highlight();
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
void gui_dialer_pad_horizontal_move_change_item_state(U8 change_state);

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
MMI_BOOL gui_dialer_pad_horizontal_check_range(mmi_pen_point_struct point);        
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
void gui_dialer_pad_horizontal_pen_down(mmi_pen_point_struct point);
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
void gui_dialer_pad_horizontal_pen_up(mmi_pen_point_struct point);
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
void gui_dialer_pad_horizontal_pen_repeat(mmi_pen_point_struct point);
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
void gui_dialer_pad_horizontal_pen_move(mmi_pen_point_struct point);
#endif /*GUI_DIALER_PAD_HORIZONTAL_DIALER*/


//#define GUI_DIALER_PAD_MATRIX_DIALER
#if defined(GUI_DIALER_PAD_MATRIX_DIALER)
#define GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_W 102
#define GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_H 50
#define GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_BORDER 0
#define GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_XGAP 2
#define GUI_DIALER_PAD_IMAGE_MATRIX_ITEM_YGAP 3
#define GUI_DIALER_PAD_IMAGE_MATRIX_ROWS 4
#define GUI_DIALER_PAD_IMAGE_MATRIX_UP_SCROLL_SENSITIVITY 0.80f
#define GUI_DIALER_PAD_IMAGE_MATRIX_DOWN_SCROLL_SENSITIVITY 0.40f

//delta pos y, check it > h then free run
#define GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_COEFFICIENT 0.90F
#define GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_THRESHOLD_TIME 400//ms
#define GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_SENSITIVITY 0.05F
#define GUI_DIALER_PAD_IMAGE_MATRIX_MOVE_THRESHOLD 10
#define GUI_DIALER_PAD_IMAGE_MATRIX_HOLD_THRESHOLD 5
#define GUI_DIALER_PAD_IMAGE_MATRIX_INTERVAL 0//ms
#define GUI_DIALER_PAD_IMAGE_MATRIX_FREE_RUN_POS_DELTA 3




//matrix img ssp
typedef enum
{
	GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_UNFOCUS,
	GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FOCUS,
	GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_HOLD,
	GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_FREE_RUN,
	GUI_DIALER_PAD_SCOLLING_BY_PEN_STATE_TOTAL,
}gui_dialer_pad_image_matrix_scrolling_by_pen_state;



typedef struct _gui_dialer_pad_transform_struct{
  S16 hilited_row;//hilited row index
  S16 hilited_col;//hilted col index
  float y_offset[GUI_DIALER_PAD_IMAGE_MATRIX_ROWS];//bottom,save the current offset of each row
  float row_top[GUI_DIALER_PAD_IMAGE_MATRIX_ROWS];//top, save the current offset of each row
  float up_scroll_sensitivity;//[0, 1]
  float down_scroll_sensitivity;//[0, 1]
  float scroll_coefficient;//ssp coefficient
  float scroll_momentum;//save the current momentum
  float move_threshold;//free run when distance > this value
  float hold_threshold;//move when distance > this value
  float y_pos_delta;
  float scroll_sensitivity;
  float scale;
  
}gui_dialer_pad_transform_struct;




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
extern void gui_dialer_pad_matrix_image_goto_previous_row(void);

/*****************************************************************************
 * FUNCTION
 *  gui_dialer_pad_matrix_image_goto_next_row
 * DESCRIPTION
 *  goto previous row 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern void gui_dialer_pad_matrix_image_goto_next_row(void);
#endif  //GUI_DIALER_PAD_MATRIX_DIALER

#define GUI_PICKER_CIRCUAL_ROLL_DIALER

#ifdef GUI_PICKER_CIRCUAL_ROLL_DIALER

#define CIRTUAL_SLIDE_THREOD 30.0f
#define CENTER_X 134  //122
#define CENTER_Y 101
#define CIRCUAL_ANIMATE_TIME 100
#define ANIMATION_DIS 6

#define CENTER_X_CIRTUAL 134
#define CENTER_Y_CIRTUAL 138
#define CIRCUTL_ANGLE 18
#define CIRCUTL_PI                          3.1415926f
#define CIRCUTL_SEMIMAJOR 300
#define CIRCUTL_SEMIMINOR 165

//bool is_animation;

typedef struct
{
    S32 pos_x;
    S32 pos_y;
}cirtual_struct;


extern void gui_circual_roll_picker_init(void);

#endif

#endif  //__GUI_DIALER_PAD_H__
#endif  //__MMI_UI_DIALER_PAD__
