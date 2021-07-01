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
 *   wgui_swatch_common_pen_handle.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   swatch common pen handle
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *$log$
 
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 /****************************************************************************
 * Include Files																
 *****************************************************************************/
#ifndef _WGUI_SWATCH_COMMON_PEN_HANDLE_H_
#define _WGUI_SWATCH_COMMON_PEN_HANDLE_H_
	 
#include "mmi_features.h"
	 
#ifdef __MMI_WEARABLE_DEVICE__
	 
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "gui.h"
	 
#if defined(__MMI_WEARABLE_DEVICE__)
#ifndef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
#define __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
#endif
#endif/*__MMI_WEARABLE_DEVICE__*/
	 
/***************************************************************************** 
 * Define
*****************************************************************************/
	 
#define __SWATCH_PEN_DEBUG__
#ifdef __SWATCH_PEN_DEBUG__
#ifndef __MTK_TARGET__
#define SWATCH_PEN_TRACE(format, ...) printf((format), ##__VA_ARGS__)
#else
#define SWATCH_PEN_TRACE(...) kal_prompt_trace(MOD_MMI_FW, __VA_ARGS__)
#endif
#else
#define SWATCH_PEN_TRACE(format, ...)
#endif /*__SWATCH_PEN_DEBUG__*/

	 
//#ifdef __MMI_TOUCH_SCREEN__
#define SMART_WATCH_COMMON_PEN_SWAP_DIS 40  
#define SMART_WATCH_COMMON_ANIM_TIMER 0
#define SMART_WATCH_COMMON_PEN_CLICK_THRESHOLD 3
#define SMART_WATCH_COMMON_UP_THRESHOLD 10
#define SMART_WATCH_COMMON_PEN_MOVE_THRESHOLD 5
//#endif /*__MMI_TOUCH_SCREEN__*/
	 
	 

	 
/***************************************************************************** 
* Structure
*****************************************************************************/
typedef enum
{
	MMI_SWATCH_MOVE_DIRECTION_NONE,
	MMI_SWATCH_MOVE_DIRECTION_H,
	MMI_SWATCH_MOVE_DIRECTION_V,
}mmi_swatch_common_pen_move_direction_enum;
typedef struct
{
	S32 x;
	S32 y;
}swatch_common_pos_struct;

typedef struct
{
	U8 cell_height;
	U8 cell_distance;
	U8 cell_top_distance;
	U8 total_icon_num;
	S32 highlight_index;

	MMI_BOOL disable_array_image;

	gdi_handle base_layer;
	gdi_handle cell_layer_handler;
	PU8 cell_layer_buffer;
	
	//swatch_common_pos_struct (*get_layout)(S32);
	//MMI_BOOL (*check_area)(S16, S16);
	void (*change_index_rule)(S32);
	void (*draw_cell_layer)(S32);
	void (*draw_cell_bg)(void);
 #ifdef __SWATCCH_FOR_CALENDAR_MAIN_SCREEN__
	MMI_BOOL (*pen_down_hdlr)(mmi_pen_point_struct);
    MMI_BOOL (*pen_move_hdlr)(mmi_pen_point_struct, mmi_pen_point_struct);
 #endif/*__SWATCCH_FOR_CALENDAR_MAIN_SCREEN__*/
	MMI_BOOL (*click_handle)(mmi_pen_point_struct, mmi_pen_point_struct);
	void (*long_tap_handle)(mmi_pen_point_struct);
	MMI_BOOL (*check_is_valid_pen_move)(S32);
	//MMI_BOOL (*is_valid_pen_pos)(mmi_pen_point_struct);
	void (*set_pen_pos_area)(swatch_common_pos_struct *, swatch_common_pos_struct *);
}swatch_common_cell_info;


typedef struct
{
	S32 pen_move_offset;
	S32 prevpen_move_offset;
	mmi_pen_point_struct pen_down_pos;
	S32 start_anim_pos;
	S32 end_anim_pos;
	MMI_BOOL pen_click;
	S32 temp_offset;
	MMI_BOOL is_in_valid_pen_move_area;
	MMI_BOOL is_valid_pen_move;
	swatch_common_pos_struct pen_pos_start;
	swatch_common_pos_struct pen_pos_end;
	
	swatch_common_cell_info *cell_info;
	mmi_swatch_common_pen_move_direction_enum pen_move_direction;
}swatch_common_pen_handle_struct;
	 
 /***************************************************************************** 
  * Function Declare
  *****************************************************************************/
extern void mmi_swatch_cell_entry(swatch_common_cell_info *cell_info);
extern void mmi_swatch_common_pen_handle_exit(void);

#endif /* __MMI_WEARABLE_DEVICE__ */ 
#endif /* _MMI_SWATCH_H_ */ 


