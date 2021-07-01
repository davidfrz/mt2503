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
 * BtRmtCapCategory.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BTRemoteCapture App.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/

#include "mmi_features.h"
#ifdef __MMI_BT_REMOTE_CAPTURE__
#include "gdi_include.h"
#include "mmi_rp_app_btremotecapture_def.h"
#include "mmi_trc_int.h"
#include "TouchScreenGprot.h"
#include "BTNotiSrvGprot.h"
#include "mmi_conn_app_trc.h"
#include "kal_public_api.h"

#ifdef __MMI_MAINLCD_320X320__
#define Cap_Touch_Button_X (160 - 32)
#define Cap_Touch_Button_Y (270 - 32)
#define Cap_Touch_Button_Width 64
#define Cap_Touch_Button_Height 64
#elif defined (__MMI_MAINLCD_240X320__)
#define Cap_Touch_Button_X (120 - 32)
#define Cap_Touch_Button_Y (270 - 32)
#define Cap_Touch_Button_Width 64
#define Cap_Touch_Button_Height 64
#else
#define Cap_Touch_Button_X (120 - 32)
#define Cap_Touch_Button_Y (200 - 32)
#define Cap_Touch_Button_Width 64
#define Cap_Touch_Button_Height 64
#endif


#define MMI_BT_RMT_CAP_SWIPE_THREHOLD (LCD_WIDTH/3)


typedef struct{
	S8 file_name_ptr[BT_NOTIFY_XML_FILE_NAME_LENTH];
	U8 *buffer_ptr;
}mmi_bt_rmt_cap_last_screen_struct;

typedef struct{
	mmi_pen_point_struct pen_down_pos;

}mmi_bt_rmt_cap_categry_cntx;

static mmi_pen_point_struct Cap_button_ponit[4] = {{Cap_Touch_Button_X, Cap_Touch_Button_Y},
												   {Cap_Touch_Button_X + Cap_Touch_Button_Width - 1, Cap_Touch_Button_Y},
  												   {Cap_Touch_Button_X + Cap_Touch_Button_Width - 1, Cap_Touch_Button_Y + Cap_Touch_Button_Height - 1},
												   {Cap_Touch_Button_X, Cap_Touch_Button_Y + Cap_Touch_Button_Height - 1}
												   };
static mmi_pen_polygon_area_struct Cap_button_area;

static MMI_BOOL is_down_in_area; 

static mmi_bt_rmt_cap_categry_cntx g_rmtcap_category_cntx;
#if 0
/* under construction !*/
#endif

extern mmi_bt_rmtcap_exit_show_pic(void);
extern mmi_bt_rmtcap_main_capture(void);
extern mmi_bt_rmtcap_main_exit_capture(void);

void mmi_bt_rmtcap_draw_screen(
		S8 *file_name_ptr,
		U8 *buffer_ptr,
        S32 *category_error_flag)
{
/*----------------------------------------------------------------*/
/* Local Variables                                                */
/*----------------------------------------------------------------*/
	GDI_HANDLE layer_base;
	GDI_HANDLE layer_OSD;
	GDI_RESULT ret;
	//kal_uint32 curr_tick;
	//kal_uint32 last_tick;
/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/

	//use base layer to show picture, use creatd layer to show icon.
	//gdi_lcd_set_high_priority_freeze(0);	

	gdi_layer_lock_frame_buffer();  //to avoid other one blt this layer

	gdi_layer_get_base_handle(&layer_base);
	gdi_layer_push_and_set_active(layer_base);
	gdi_layer_clear_background(GDI_COLOR_BLACK);
	
	if(file_name_ptr)
	{
		ret = gdi_image_draw_resized_file(0,0,LCD_WIDTH - 1,LCD_HEIGHT - 1,file_name_ptr);			
	}
	else if(buffer_ptr)
	{
		//ret = gdi_image_draw_resized(0,0,LCD_WIDTH - 1,LCD_HEIGHT - 1,buffer_ptr);
		//kal_get_time(&curr_tick);
		ret = gdi_image_draw_resized_mem(0,0,LCD_WIDTH - 1,LCD_HEIGHT - 1,buffer_ptr, GDI_IMAGE_TYPE_JPG, BT_NOTIFY_MRE_MAX_DATA_LENTH);
		//kal_get_time(&last_tick);


	}

		gdi_layer_pop_and_restore_active();
	
	ret = gdi_layer_create_cf(GDI_COLOR_FORMAT_PARGB6666, Cap_Touch_Button_X, Cap_Touch_Button_Y, Cap_Touch_Button_Width, Cap_Touch_Button_Height, &layer_OSD);
	if(ret == GDI_FAILED)
	{
		MMI_ASSERT(0);
	}
	
		gdi_layer_push_and_set_active(layer_OSD);
		gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_set_opacity(MMI_TRUE, 180);
		gdi_image_draw(0, 0, (U8 *)GetImage(IMG_ID_BT_RMT_CAP_PRESS_BUTTON));

		gdi_layer_flatten_to_base(layer_base,layer_OSD,0,0);
		gdi_layer_pop_and_restore_active();
		gdi_layer_unlock_frame_buffer();

		gdi_layer_blt(layer_base,0,0,0,0,0,LCD_WIDTH - 1, LCD_HEIGHT - 1);
		gdi_layer_free(layer_OSD);   //every time create layer and free layer will donw the performance, need next development to only create this layer once during remote capture.
	

}

void mmi_bt_rmtcap_draw_shot_screen(
									S8 *file_name_ptr,
									U8 *buffer_ptr)
{
/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/

	GDI_HANDLE layer_base;
	GDI_HANDLE layer_OSD;

/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/	

	//use base layer to show picture, use creatd layer to show icon.
	//gdi_lcd_set_high_priority_freeze(0);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_DRAW_SHOT_SCREEN, file_name_ptr, buffer_ptr);

	gdi_layer_lock_frame_buffer();	//to avoid other one blt this layer

	gdi_layer_get_base_handle(&layer_base);
	gdi_layer_push_and_set_active(layer_base);
		
	if(file_name_ptr)
	{
		GDI_RESULT ret;
		gdi_layer_set_background(GDI_COLOR_BLACK);
		gdi_image_draw_resized_file(0,0,LCD_WIDTH - 1,LCD_HEIGHT - 1,file_name_ptr);
		//gdi_image_draw_file(0, 0, file_name_ptr);
		gdi_layer_pop_and_restore_active();
		gdi_layer_unlock_frame_buffer();
		gdi_layer_blt(layer_base,0,0,0,0,0,LCD_WIDTH - 1, LCD_HEIGHT - 1);
		
		
	}
	else if(buffer_ptr)
	{

	}
	else
	{
		MMI_ASSERT(0);
	}
	


}

static void mmi_bt_rmtcap_pen_down_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body                                                      */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PEN_DOWN_HDLR, pos.x, pos.y);
	g_rmtcap_category_cntx.pen_down_pos.x = pos.x;
	g_rmtcap_category_cntx.pen_down_pos.y = pos.y;
	if(mmi_pen_check_inside_polygon(&Cap_button_area, pos))
	{
		is_down_in_area = MMI_TRUE;	
	}
	else
	{
		is_down_in_area = MMI_FALSE;
	}
	

}

static void mmi_bt_rmtcap_pen_up_hdlr(mmi_pen_point_struct pos)
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PEN_UP_HDLR, pos.x, pos.y);	
	if(mmi_pen_check_inside_polygon(&Cap_button_area, pos) && is_down_in_area)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_ENTER_MAIN_CAPTURE);		
		mmi_bt_rmtcap_main_capture();
	}
	else
	{
		is_down_in_area = MMI_FALSE;
	}
	
}

static void mmi_bt_rmtcap_pen_move_to_idle_hdlr(mmi_pen_point_struct pos)
{
/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MOVE_TO_IDLE_HDLR, pos.x, pos.y);	
	if(pos.x - g_rmtcap_category_cntx.pen_down_pos.x > MMI_BT_RMT_CAP_SWIPE_THREHOLD)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_ENTER_MAIN_EXIT);	
		mmi_bt_rmtcap_main_exit_capture();
	}

}

static void mmi_bt_rmtcap_pen_move_to_draw_hdlr(mmi_pen_point_struct pos)
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MOVE_TO_DRAW_HDLR, pos.x, pos.y);
	if(pos.x - g_rmtcap_category_cntx.pen_down_pos.x > MMI_BT_RMT_CAP_SWIPE_THREHOLD)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_ENTER_EXIT_SHOW);		
		mmi_bt_rmtcap_exit_show_pic();
	}
}


void mmi_bt_rmtcap_set_draw_screen_pen_callback()
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SET_DRAW_PEN_CALLBACK);
#ifdef __MMI_TOUCH_SCREEN__
	Cap_button_area.num = 4;
	Cap_button_area.points = (mmi_pen_point_struct*) Cap_button_ponit;
	mmi_pen_register_down_handler(mmi_bt_rmtcap_pen_down_hdlr);
	mmi_pen_register_up_handler(mmi_bt_rmtcap_pen_up_hdlr);
	mmi_pen_register_abort_handler(NULL);
	mmi_pen_register_move_handler(mmi_bt_rmtcap_pen_move_to_idle_hdlr);
 #endif
}

void mmi_bt_rmtcap_set_capture_screen_pen_callback()
{

/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SET_CAPTURE_PEN_CALLBACK);	
#ifdef __MMI_TOUCH_SCREEN__
	Cap_button_area.num = 0;
	mmi_pen_register_down_handler(mmi_bt_rmtcap_pen_down_hdlr);
	mmi_pen_register_up_handler(NULL);
	mmi_pen_register_abort_handler(NULL);
	mmi_pen_register_move_handler(mmi_bt_rmtcap_pen_move_to_draw_hdlr);
 #endif




}
void mmi_bt_rmtcap_clear_pen_callback()
{
/*----------------------------------------------------------------*/
/* Local Variables												  */
/*----------------------------------------------------------------*/
	
/*----------------------------------------------------------------*/
/* Code Body													  */
/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CLEAR_PEN_CALLBACK);
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler(NULL);
	mmi_pen_register_up_handler(NULL);
	mmi_pen_register_abort_handler(NULL);
	mmi_pen_register_move_handler(NULL);

 #endif
}


#endif
