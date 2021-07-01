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
*  FMRadioMainScreen_WD.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio main screen drawing functions
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__
#ifdef __MMI_FTE_SUPPORT__

#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "MMIDataType.h"
#include "mmi_frm_input_gprot.h"
#include "kal_non_specific_general_types.h"
#include "wgui_categories_util.h"
#include "gui.h"
#include "CustDataRes.h"
#include "gdi_include.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_include.h"
#include "GlobalConstants.h"
#include "gui_windows.h"
#include "gui_config.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "lcd_sw_inc.h"
#include "gui_data_types.h"
#include "kal_release.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "gui_switch.h"
#include "GlobalResDef.h"
#include "GpiosrvGprot.h"

#include "Wgui_softkeys.h"

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_AVRCP_SUPPORT__ */

#if 0//def __MMI_WEARABLE_DEVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //__MMI_WEARABLE_DEVICE__

/* MTK Leo end */
#include "gui_font_size.h"


GDI_HANDLE fmrdo_base_layer;
GDI_HANDLE fmrdo_skin_layer;
GDI_HANDLE fmrdo_btn_down_layer;
static fmrdo_main_draw_struct fmrdo_main_draw;  /* all memeber variables are zero initial */
U8 g_vol_displayed;
extern mmi_fmrdo_struct g_fmrdo;                    /* defined in FMRadioSrc.c */
extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern BOOL r2lMMIFlag; /* definedi n gui_inputs.c */

#ifdef __MMI_AVRCP_SUPPORT__
extern MMI_BOOL g_avrcp_is_btn_pressed;
extern U8 g_avrcp_btn;
#endif


#ifdef __MMI_TOUCH_SCREEN__
/* MTK Leo add 20050301, add touch screen support for FM Radio */
typedef enum
{
	FMRDO_PEN_NONE,
	FMRDO_PEN_MAIN_VOL_UP,
	FMRDO_PEN_MAIN_VOL_DOWN,
	FMRDO_PEN_MAIN_NEXT,
	FMRDO_PEN_MAIN_PREV,
	FMRDO_PEN_MAIN_TITLE,
	FMRDO_PEN_MAIN_POWER,
	FMRDO_PEN_COUNT
} FMRDO_PEN_STATE;
typedef enum
{
	FMRDO_PEN_SK_UP,
	FMRDO_PEN_SK_DOWN
} FMRDO_SOFTKEY_STATE;

S32 fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_init_main_images
* DESCRIPTION
*  Initialize main draw structure for images
* PARAMETERS
*  void       
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_init_main_images(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 w, h, w2, h2;
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[0];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_INIT_MAIN_IMAGES);
	
	/* channel name color */
	fmrdo_main_draw.channel_name_text_color = gui_color(
		skin_p->channel_name_text_color_r,
		skin_p->channel_name_text_color_g,
		skin_p->channel_name_text_color_b);
	/* channel font size */
	fmrdo_main_draw.channel_font_size = skin_p->channel_font_size;

	/* title box */
	fmrdo_main_draw.channel_name.x1 = 0;
	fmrdo_main_draw.channel_name.y1 = 0;
	fmrdo_main_draw.channel_name.x2 = UI_DEVICE_WIDTH - 1;
	fmrdo_main_draw.channel_name.y2 = skin_p->vol_inc_button_area.y1 - 1;
	/* down effect bg color */
	fmrdo_main_draw.down_img_bg_color = gui_color(
		skin_p->down_img_bg_color_r,
		skin_p->down_img_bg_color_g,
		skin_p->down_img_bg_color_b);
	/* down effect bg opacity */
	fmrdo_main_draw.down_img_bg_opacity = skin_p->down_img_bg_opacity;

	/* dimm effect bg opacity */
	fmrdo_main_draw.dimm_img_opacity = skin_p->dimm_img_opacity;

	/*background image */
	fmrdo_main_draw.bg_image = (PU8) GetImage(skin_p->bg_image_id);

	/* volume up button */
	fmrdo_main_draw.vol_up_button.up_img = (PU8) GetImage(skin_p->vol_inc_button_up_image_id);
	fmrdo_main_draw.vol_up_button.button_area.x1 = skin_p->vol_inc_button_area.x1;
	fmrdo_main_draw.vol_up_button.button_area.y1 = skin_p->vol_inc_button_area.y1;
	gui_measure_image(fmrdo_main_draw.vol_up_button.up_img, &w, &h);
	fmrdo_main_draw.vol_up_button.button_area.x2 = fmrdo_main_draw.vol_up_button.button_area.x1 + w;
	fmrdo_main_draw.vol_up_button.button_area.y2 = fmrdo_main_draw.vol_up_button.button_area.y1 + h;

	/* volume down button */
	fmrdo_main_draw.vol_down_button.up_img = (PU8) GetImage(skin_p->vol_dec_button_up_image_id);
	fmrdo_main_draw.vol_down_button.button_area.x1 = skin_p->vol_dec_button_area.x1;
	fmrdo_main_draw.vol_down_button.button_area.y1 = skin_p->vol_dec_button_area.y1;
	gui_measure_image(fmrdo_main_draw.vol_down_button.up_img, &w, &h);
	fmrdo_main_draw.vol_down_button.button_area.x2 = fmrdo_main_draw.vol_down_button.button_area.x1 + w;
	fmrdo_main_draw.vol_down_button.button_area.y2 = fmrdo_main_draw.vol_down_button.button_area.y1 + h;

	/* next button */
	fmrdo_main_draw.next_button.up_img = (PU8) GetImage(skin_p->next_button_up_image_id);
	fmrdo_main_draw.next_button.button_area.x1 = skin_p->next_button_area.x1;
	fmrdo_main_draw.next_button.button_area.y1 = skin_p->next_button_area.y1;
	gui_measure_image(fmrdo_main_draw.next_button.up_img, &w, &h);
	fmrdo_main_draw.next_button.button_area.x2 = fmrdo_main_draw.next_button.button_area.x1 + w;
	fmrdo_main_draw.next_button.button_area.y2 = fmrdo_main_draw.next_button.button_area.y1 + h;

	/* prev button */
	fmrdo_main_draw.prev_button.up_img = (PU8) GetImage(skin_p->prev_button_up_image_id);
	fmrdo_main_draw.prev_button.button_area.x1 = skin_p->prev_button_area.x1;
	fmrdo_main_draw.prev_button.button_area.y1 = skin_p->prev_button_area.y1;
	gui_measure_image(fmrdo_main_draw.prev_button.up_img, &w, &h);
	fmrdo_main_draw.prev_button.button_area.x2 = fmrdo_main_draw.prev_button.button_area.x1 + w;
	fmrdo_main_draw.prev_button.button_area.y2 = fmrdo_main_draw.prev_button.button_area.y1 + h;

	/* power button */
	fmrdo_main_draw.power_button.on_up_img = (PU8) GetImage(skin_p->power_button_on_up_image_id);
	fmrdo_main_draw.power_button.off_up_img = (PU8) GetImage(skin_p->power_button_off_up_image_id);
	fmrdo_main_draw.power_button.button_area.x1 = skin_p->power_button_area.x1;
	fmrdo_main_draw.power_button.button_area.y1 = skin_p->power_button_area.y1;
	gui_measure_image(fmrdo_main_draw.power_button.on_up_img, &w, &h);
	fmrdo_main_draw.power_button.button_area.x2 = fmrdo_main_draw.power_button.button_area.x1 + (S16) w;
	fmrdo_main_draw.power_button.button_area.y2 = fmrdo_main_draw.power_button.button_area.y1 + (S16) h;
}



/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_show_main
* DESCRIPTION
*  Show skin screen
* PARAMETERS  
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_show_main(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	GDI_RESULT gdi_ret = GDI_FAILED;
	S32 w = 0, h = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_SHOW_MAIN);
	
	/* Init images, always get image in ENFB project */
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
	if (!fmrdo_main_draw.is_ready)
	{
		mmi_fmrdo_init_main_images();
		fmrdo_main_draw.is_ready = TRUE;
	}

	if (g_fmrdo.down_img_buff)
	{
		w = fmrdo_main_draw.power_button.button_area.x2 - fmrdo_main_draw.power_button.button_area.x1;
		h = fmrdo_main_draw.power_button.button_area.y2 - fmrdo_main_draw.power_button.button_area.y1;
		gdi_ret = gdi_layer_create_using_outside_memory(0, 0, w, h, &fmrdo_btn_down_layer, g_fmrdo.down_img_buff, w * h * GDI_COLOR_FORMAT_16);

		if(gdi_ret == GDI_SUCCEED)
		{
			color c = fmrdo_main_draw.down_img_bg_color;
			gdi_layer_push_and_set_active(fmrdo_btn_down_layer);
			gdi_layer_clear(gdi_act_color_from_rgb(c.alpha, c.r, c.g, c.b));
			gdi_layer_set_opacity(TRUE, (S32)(fmrdo_main_draw.down_img_bg_opacity * 255 / 100));
			gdi_layer_pop_and_restore_active();
		}
	}
	gdi_layer_multi_layer_enable();
	/* get base layer as skin layer */
	gdi_layer_get_base_handle(&fmrdo_base_layer);
	gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_create(0, 0, UI_device_width, UI_device_height, &fmrdo_skin_layer);

	gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
	mmi_fmrdo_set_alpha_blending_layer(TRUE);

	/* associate functions */
	ExitCategoryFunction = mmi_fmrdo_hide_main;
	RedrawCategoryFunction = mmi_fmrdo_redraw_main_all;
	GetCategoryHistory = dummy_get_history;
	GetCategoryHistorySize = dummy_get_history_size;

	/* draw screen */
	mmi_fmrdo_redraw_main_all();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_hide_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_hide_main(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_HIDE_MAIN);
	
	gdi_layer_flatten_to_base(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);

	if(fmrdo_skin_layer)
	{
		gdi_layer_free(fmrdo_skin_layer);
		fmrdo_skin_layer = NULL;
	}
	if(fmrdo_btn_down_layer)
	{
		gdi_layer_free(fmrdo_btn_down_layer);
		fmrdo_btn_down_layer = NULL;
	}
	if(g_fmrdo.down_img_buff)
	{
		mmi_frm_scrmem_free(g_fmrdo.down_img_buff);
		g_fmrdo.down_img_buff = NULL;
	}
	gdi_layer_multi_layer_disable();

	/* restore blt layer as base layer only */
	gdi_layer_set_blt_layer(fmrdo_base_layer, 0, 0, 0);

#ifdef __MMI_TOUCH_SCREEN__
	fmrdo_pen_event_on_object = FMRDO_PEN_NONE;
#endif /* __MMI_TOUCH_SCREEN__ */ 

	/* associate functions */
	ExitCategoryFunction = MMI_dummy_function;
	RedrawCategoryFunction = MMI_dummy_function;
	GetCategoryHistory = dummy_get_history;
	GetCategoryHistorySize = dummy_get_history_size;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_all
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_all(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen)
	{	
		return;
	}
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_MAIN_ALL, g_fmrdo.is_power_on);
	
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gdi_layer_clear_background(GDI_COLOR_TRANSPARENT);
	gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_pop_and_restore_active();

	gdi_layer_lock_frame_buffer();
	gdi_layer_push_and_set_active(fmrdo_base_layer);
	gdi_layer_push_and_set_clip(0, 0, UI_device_width - 1, UI_device_height - 1);
	gdi_image_draw(0, 0, fmrdo_main_draw.bg_image);

	/* main background */
	mmi_fmrdo_redraw_main_push_button(
		FMRDO_BUTTON_VOL_DOWN,
		(BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_VOL_DOWN)));

	mmi_fmrdo_redraw_main_push_button(
		FMRDO_BUTTON_VOL_UP,
		(BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_VOL_UP)));

	mmi_fmrdo_redraw_main_push_button(
		FMRDO_BUTTON_MEMO_UP,
		(BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_UP)));

	mmi_fmrdo_redraw_main_push_button(
		FMRDO_BUTTON_MEMO_DOWN,
		(BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_DOWN)));

	mmi_fmrdo_redraw_main_toggle_button(
		FMRDO_BUTTON_POWER,
		(BOOL) (g_fmrdo.is_button_down && (g_fmrdo.selected_button == FMRDO_BUTTON_POWER)),
		g_fmrdo.is_power_on,
		TRUE);
	if(g_fmrdo.is_power_on)
	{
		mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
	}
	else
	{
		mmi_fmrdo_redraw_main_channel_name((UI_string_type)GetString(STR_ID_FMRDO_TITLE));
	}

#ifdef __MMI_AVRCP_SUPPORT__
		/* Show press down effect on repeat event from avrcp */
		if(g_fmrdo.is_power_on && g_avrcp_is_btn_pressed)
		{
			switch(g_avrcp_btn)
			{
			case MMI_AVRCP_POP_FORWARD:
			case MMI_AVRCP_POP_FAST_FORWARD:
				g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_UP;
				break;
	
			case MMI_AVRCP_POP_BACKWARD:
			case MMI_AVRCP_POP_REWIND:
				g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_DOWN;
				break;
	
			default:
				break;
			}
			mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, MMI_TRUE);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
#endif

	gdi_layer_pop_clip();
	gdi_layer_pop_and_restore_active();
	/* draw components */
	// mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);

	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_frequency
* DESCRIPTION
*  Redraw frequency on main screen
* PARAMETERS
*  freq            [IN]        
*  is_shown        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_frequency(U16 freq, BOOL is_shown)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 x1 = fmrdo_main_draw.channel_name.x1;
	S32 y1 = fmrdo_main_draw.channel_name.y1;
	S32 x2 = fmrdo_main_draw.channel_name.x2;
	S32 y2 = fmrdo_main_draw.channel_name.y2;
	S32 c_width, c_height;
	S32 str_w, str_h;
	UI_character_type freq_str[12];
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	UI_font_type channel_font = &MMI_medium_font;
#else
	UI_font_type channel_font = gui_font_get_type(GUI_FONT_SIZE_MATRIX);
#endif

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_vol_displayed || !g_fmrdo.in_main_screen)
	{
		return;
	}
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_MAIN_FREQ, g_fmrdo.is_power_on);
	
	memset(freq_str, 0, sizeof(freq_str));
	mmi_fmrdo_get_str_from_freq(freq, freq_str);

	c_width = x2 - x1;
	c_height = y2 - y1;

	gui_set_font(channel_font);
	gui_measure_string(freq_str, &str_w, &str_h);
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gdi_layer_lock_frame_buffer();
	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
	/* text */
	gui_set_text_color(fmrdo_main_draw.channel_name_text_color);

	fmrdo_main_draw.freq_area.x1 = x1 + (c_width - str_w) / 2;
	fmrdo_main_draw.freq_area.y1 = (c_height - str_h) / 2;
	fmrdo_main_draw.freq_area.x2 = fmrdo_main_draw.freq_area.x1 + str_w;
	fmrdo_main_draw.freq_area.y2 = fmrdo_main_draw.freq_area.y1 + str_h;

	gui_move_text_cursor(
		x1 + (c_width - str_w) / 2,
		(c_height - str_h) / 2);
	gui_print_text(freq_str);

	gdi_layer_pop_clip();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_unlock_frame_buffer();
	gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(x1, y1, x2, y2);

}



/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_volumebar
* DESCRIPTION
*  Redraw frequency on main screen
* PARAMETERS
*  volume            [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_volumebar(U8 volume)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	gui_volume_bar_struct volume_bar = {0};
	
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_MAIN_VOL_BAR);
	
	volume_bar.bg_opacity = 128;
	volume_bar.x = 15;
	volume_bar.y = 11;
	volume_bar.block_gap = 5;
	volume_bar.slot_width = 3;
	volume_bar.slot_gap = 1;
	volume_bar.show_bg = MMI_TRUE;
	volume_bar.slot_height = 19;
	volume_bar.max_value = FMRDO_MAX_VOL_LEVEL - 1;
	volume_bar.level_value = g_fmrdo.volume;
	volume_bar.slot_num = 8;
	volume_bar.bg_color = gdi_act_color_from_rgb(255, 255, 255, 255);
	volume_bar.highlight_color = gdi_act_color_from_rgb(255, 15, 201, 219);
	volume_bar.normal_color =  gdi_act_color_from_rgb(255, 255, 255, 255);	

	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gui_volume_bar_draw(volume_bar);
	gdi_layer_pop_and_restore_active();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_blt_previous(0, 0, UI_DEVICE_WIDTH - 1, UI_DEVICE_HEIGHT - 1);

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_hide_main_channel_name
* DESCRIPTION
*  Hide channel name on main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_hide_main_channel_name(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 x1 = fmrdo_main_draw.channel_name.x1;
	S32 y1 = fmrdo_main_draw.channel_name.y1;
	S32 x2 = fmrdo_main_draw.channel_name.x2;
	S32 y2 = fmrdo_main_draw.channel_name.y2;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_HIDE_CHANNEL_NAME);
	
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gdi_layer_lock_frame_buffer();
	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);

	gdi_layer_pop_clip();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_unlock_frame_buffer();
	gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(x1, y1, x2, y2);
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_channel_name
* DESCRIPTION
*  Redraw channel name on main screen
* PARAMETERS
*  other_str       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_channel_name(UI_string_type other_str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 x1 = fmrdo_main_draw.channel_name.x1;
	S32 y1 = fmrdo_main_draw.channel_name.y1;
	S32 x2 = fmrdo_main_draw.channel_name.x2;
	S32 y2 = fmrdo_main_draw.channel_name.y2;
	S32 c_width, c_height;
	S32 str_w, str_h;
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	UI_font_type channel_font = &MMI_medium_font;
#else
	UI_font_type channel_font = gui_font_get_type(GUI_FONT_SIZE_MATRIX);
#endif

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if ((g_fmrdo.is_power_on && g_vol_displayed) || !g_fmrdo.in_main_screen || !other_str)
	{
		return;
	}
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_CHANNEL_NAME);
	
	c_width = x2 - x1;
	c_height = y2 - y1;

	gui_set_font(channel_font);
	gui_measure_string(other_str, &str_w, &str_h);
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gdi_layer_lock_frame_buffer();
	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
	/* text */

	gui_set_text_color(fmrdo_main_draw.channel_name_text_color);

	gui_move_text_cursor(
		x1 + (c_width - str_w) / 2,
		(c_height - str_h) / 2);
	gui_print_text(other_str);

	gdi_layer_pop_clip();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_unlock_frame_buffer();
	gdi_layer_pop_and_restore_active();
	gdi_layer_blt_previous(x1, y1, x2, y2);

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_volume
* DESCRIPTION
*  Redraw volume indicator on main screen
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_volume(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_fmrdo_redraw_main_volumebar(g_fmrdo.volume);
	g_vol_displayed = 1;
	StartTimer(FMRDO_VOLUME_BAR_TIMER, 2000, mmi_fmrdo_reset_volume_bar);    
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_reset_volume_bar
* DESCRIPTION
*  Clear volume bar
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_reset_volume_bar(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_RESET_VOL_BAR);
	
	g_vol_displayed = 0;
	StopTimer(FMRDO_VOLUME_BAR_TIMER);
	if(g_fmrdo.is_power_on)
	{
	gdi_layer_push_and_set_active(fmrdo_skin_layer);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
	if(g_fmrdo.is_button_down)
	{
		gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, fmrdo_btn_down_layer, 0);
	}
	else
	{
	gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
	}
	gdi_layer_pop_and_restore_active();
		mmi_fmrdo_redraw_main_frequency(g_fmrdo.frequency, TRUE);
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_push_button
* DESCRIPTION
*  Redraw push buttons on main screen
* PARAMETERS
*  button      [IN]        
*  is_down     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_push_button(U8 button, BOOL is_down)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	fmrdo_main_push_button_struct *push_button_p;
	S32 x1, y1, x2, y2;
	S32 diffx, diffy;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen || (is_down && !g_fmrdo.is_power_on))
	{
		return;
	}
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_PUSH_BUTTON, button, is_down);
	
	switch (button)
	{
	case FMRDO_BUTTON_VOL_UP:
		push_button_p = &fmrdo_main_draw.vol_up_button;
		break;

	case FMRDO_BUTTON_VOL_DOWN:
		push_button_p = &fmrdo_main_draw.vol_down_button;
		break;

	case FMRDO_BUTTON_MEMO_UP:
		push_button_p = &fmrdo_main_draw.next_button;
		break;

	case FMRDO_BUTTON_MEMO_DOWN:
		push_button_p = &fmrdo_main_draw.prev_button;
		break;

	default:
		return;
	}

	x1 = push_button_p->button_area.x1;
	y1 = push_button_p->button_area.y1;
	x2 = push_button_p->button_area.x2;
	y2 = push_button_p->button_area.y2;

	if (is_down)
	{
		gdi_layer_push_and_set_active(fmrdo_btn_down_layer);
		gdi_layer_resize(x2 - x1, y2 - y1);
		gdi_layer_set_position(x1, y1);
		gdi_layer_pop_and_restore_active();
		gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, fmrdo_btn_down_layer, 0);
		gdi_layer_blt_previous(x1, y1, x2, y2);
		return;
	}
	else if(g_fmrdo.selected_button >= FMRDO_BUTTON_VOL_UP && g_fmrdo.selected_button <= FMRDO_BUTTON_MEMO_DOWN)
	{
		gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
		gdi_layer_blt_previous(x1, y1, x2, y2);
		return;
	}

	gdi_layer_lock_frame_buffer();
	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	if(g_fmrdo.is_power_on)
	{
		gdi_image_draw(x1, y1, push_button_p->up_img);
	}
	else
	{
		gui_draw_image_with_alpha_transparent(push_button_p->up_img, x1, y1, (S32)((fmrdo_main_draw.down_img_bg_opacity * 255) / 100));
	}
	gdi_layer_pop_clip();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_unlock_frame_buffer();
	gdi_layer_blt_previous(x1, y1, x2, y2);


}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_redraw_main_toggle_button
* DESCRIPTION
*  Redraw toggle buttons on main screen
* PARAMETERS
*  button          [IN]        
*  is_down         [IN]        
*  is_on           [IN]        
*  is_shown        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_redraw_main_toggle_button(U8 button, BOOL is_down, BOOL is_on, BOOL is_shown)
{

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	fmrdo_main_toggle_button_struct *toggle_button_p;
	S32 x1, y1, x2, y2;
	PU8 draw_img = NULL;
	S32 diffx, diffy;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(!g_fmrdo.in_main_screen)
	{
		return;
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_REDRAW_TOGGLE_BUTTON, button, is_down, is_on);
	
	switch (button)
	{
	case FMRDO_BUTTON_POWER:
		toggle_button_p = &fmrdo_main_draw.power_button;
		break;

	default:
		return;
	}
	x1 = toggle_button_p->button_area.x1;
	y1 = toggle_button_p->button_area.y1;
	x2 = toggle_button_p->button_area.x2;
	y2 = toggle_button_p->button_area.y2;

	if (is_down)
	{
		color c = fmrdo_main_draw.down_img_bg_color;

		mmi_fmrdo_set_alpha_blending_layer(TRUE);
		gdi_layer_push_and_set_active(fmrdo_btn_down_layer);
		gdi_layer_resize(x2 - x1, y2 - y1);
		gdi_layer_set_position(x1, y1);
		gdi_layer_pop_and_restore_active();
		gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, fmrdo_btn_down_layer, 0);
		mmi_fmrdo_set_alpha_blending_layer(FALSE);
		gdi_layer_blt_previous(x1, y1, x2, y2);
		return;
	}	
	gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
	gdi_layer_lock_frame_buffer();
	mmi_fmrdo_set_alpha_blending_layer(TRUE);
	gdi_layer_push_and_set_clip(x1, y1, x2, y2);

	if (is_on)
	{
		draw_img = toggle_button_p->on_up_img;
	}
	else
	{
		draw_img = toggle_button_p->off_up_img;
	}

	gdi_image_draw(x1, y1, draw_img);
	gdi_layer_pop_clip();
	mmi_fmrdo_set_alpha_blending_layer(FALSE);
	gdi_layer_unlock_frame_buffer();

	gdi_layer_blt_previous(x1, y1, x2, y2);
}


#ifdef __MMI_TOUCH_SCREEN__

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_check_inside_rectangle
* DESCRIPTION
*  Pen down event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_fmrdo_check_inside_rectangle(fmrdo_rectangle_struct *rect, mmi_pen_point_struct point)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if((point.x >= rect->x1 && point.x <= rect->x2) && (point.y >= rect->y1 && point.y <= rect->y2))
	{
		return MMI_TRUE;
	}
	return MMI_FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_pen_down_hdlr
* DESCRIPTION
*  Pen down event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 i = FMRDO_PEN_MAIN_VOL_UP;
	mmi_pen_point_struct point;
	fmrdo_rectangle_struct *rect = NULL;
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
	U8 is_touch_feedback = 0;      // Flag to determine whether the touch is valid or not 
	S32 icon_id;
	wgui_status_icon_bar_pen_enum evt_type;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if 0//def __MMI_WEARABLE_DEVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  //__MMI_WEARABLE_DEVICE__
	
	fmrdo_pen_event_on_object = FMRDO_PEN_NONE;

	for (; i < FMRDO_PEN_COUNT; i++)
	{
		switch (i)
		{
		case FMRDO_PEN_MAIN_VOL_UP:
			rect = (fmrdo_rectangle_struct *)&(skin_p->vol_inc_button_area);
			break;

		case FMRDO_PEN_MAIN_VOL_DOWN:
			rect = (fmrdo_rectangle_struct *)&(skin_p->vol_dec_button_area);
			break;

		case FMRDO_PEN_MAIN_NEXT:
			rect = (fmrdo_rectangle_struct *)&(skin_p->next_button_area);
			break;

		case FMRDO_PEN_MAIN_PREV:
			rect = (fmrdo_rectangle_struct *)&(skin_p->prev_button_area);
			break;

		case FMRDO_PEN_MAIN_POWER:
			rect = (fmrdo_rectangle_struct *)&(skin_p->power_button_area);
			break;

		case FMRDO_PEN_MAIN_TITLE:
			if(g_fmrdo.is_power_on)
			{
				rect = (fmrdo_rectangle_struct *)&fmrdo_main_draw.freq_area;
			}
			break;		

		default:
			continue;
		}
		if (((g_fmrdo.is_power_on && i <= FMRDO_PEN_MAIN_TITLE) || i == FMRDO_PEN_MAIN_POWER) && mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
			fmrdo_pen_event_on_object = i;
			is_touch_feedback = 1;
			break;
		}
	}

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PEN_DOWN_HDLR, fmrdo_pen_event_on_object);
	
	switch (fmrdo_pen_event_on_object)
	{
	case FMRDO_PEN_MAIN_VOL_UP:
		{
			mmi_fmrdo_press_volume_up();
		}
		break;

	case FMRDO_PEN_MAIN_VOL_DOWN:
		{
			mmi_fmrdo_press_volume_down();
		}
		break;

	case FMRDO_PEN_MAIN_NEXT:
		{
			mmi_fmrdo_press_memo_up_button();
		}
		break;

	case FMRDO_PEN_MAIN_PREV:
		{
			mmi_fmrdo_press_memo_down_button();
		}
		break;

	case FMRDO_PEN_MAIN_POWER:
		{
			mmi_fmrdo_press_power_button();
		}
		break;

	case FMRDO_PEN_MAIN_TITLE:
		{
			mmi_fmrdo_press_title_area();
		}
		break;

	default:
		break;
	}

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_pen_long_tap_hdlr
* DESCRIPTION
*  Pen up event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 freq;
	S32 icon_id;
	wgui_status_icon_bar_pen_enum evt_type;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (!g_fmrdo.is_power_on)
	{
		return;
	}
	
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PEN_LONG_TAP_HDLR, fmrdo_pen_event_on_object);
	
	switch (fmrdo_pen_event_on_object)
	{
	case FMRDO_PEN_MAIN_NEXT:
		{	
			g_fmrdo.normal_repeat_step_count = 1;
				/* frequency is not changed during button press down so we need to increase it */
				if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
				{
					freq = g_fmrdo.frequency + 1;
				}
				else
				{
					freq = MIN_FM_FREQUENCY;
				}
				mmi_fmrdo_set_frequency(freq);
		}
		break;

	case FMRDO_PEN_MAIN_PREV:
		{		
			g_fmrdo.normal_repeat_step_count = 1;
				/* frequency is not changed during button press down so we need to decrease it */
				if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
				{
					freq = g_fmrdo.frequency - 1;
				}
				else
				{
					freq = MAX_FM_FREQUENCY;
				}
				mmi_fmrdo_set_frequency(freq);
		}
		break;

	default:
		wgui_status_icon_bar_translate_pen_event(
			MMI_PEN_EVENT_LONG_TAP,
			pos.x,
			pos.y,
			&icon_id,
			&evt_type);
		break;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_pen_up_hdlr
* DESCRIPTION
*  Pen up event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S32 icon_id;
	wgui_status_icon_bar_pen_enum evt_type;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PEN_UP_HDLR, fmrdo_pen_event_on_object);
	
	switch (fmrdo_pen_event_on_object)
	{
	case FMRDO_PEN_MAIN_VOL_UP:
		{
			mmi_fmrdo_release_volume_up();
		}
		break;

	case FMRDO_PEN_MAIN_VOL_DOWN:
		{
			mmi_fmrdo_release_volume_down();
		}
		break;

	case FMRDO_PEN_MAIN_PREV:
		{
			mmi_fmrdo_release_memo_down_button();
		}
		break;

	case FMRDO_PEN_MAIN_NEXT:
		{
			mmi_fmrdo_release_memo_up_button();
		}
		break;

	case FMRDO_PEN_MAIN_POWER:
		{
			mmi_fmrdo_release_power_button();
		}
		break;

	case FMRDO_PEN_MAIN_TITLE:
		{
			mmi_fmrdo_release_title_area();
		}
		break;

	default:
		break;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_pen_move_hdlr
* DESCRIPTION
*  Pen move event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_pen_point_struct point;
	fmrdo_rectangle_struct *rect = NULL;
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
	S32 icon_id;
	wgui_status_icon_bar_pen_enum evt_type;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PEN_MOVE_HDLR, fmrdo_pen_event_on_object);
	
	switch (fmrdo_pen_event_on_object)
	{
	case FMRDO_PEN_MAIN_PREV:
		rect = (fmrdo_rectangle_struct *) & skin_p->prev_button_area;
		if (mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
			mmi_fmrdo_press_memo_down_button();
		}
		else
		{
			g_fmrdo.is_button_down = FALSE;
			mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
		break;

	case FMRDO_PEN_MAIN_NEXT:
		rect = (fmrdo_rectangle_struct *) & skin_p->next_button_area;
		if (mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
			mmi_fmrdo_press_memo_up_button();
		}
		else
		{
			g_fmrdo.is_button_down = FALSE;
			mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
		break;

	case FMRDO_PEN_MAIN_VOL_DOWN:
		rect = (fmrdo_rectangle_struct *)&skin_p->vol_dec_button_area;
		if (mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
		}
		else
		{
			g_fmrdo.is_button_down = FALSE;
			gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
			mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
		break;

	case FMRDO_PEN_MAIN_VOL_UP:
		rect = (fmrdo_rectangle_struct *)&skin_p->vol_inc_button_area;
		if (mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
		}
		else
		{
			g_fmrdo.is_button_down = FALSE;
			gdi_layer_set_blt_layer(fmrdo_base_layer, fmrdo_skin_layer, 0, 0);
			mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
		break;

	case FMRDO_PEN_MAIN_POWER:
		rect = (fmrdo_rectangle_struct *)&skin_p->power_button_area;
		if (mmi_fmrdo_check_inside_rectangle(rect, pos))
		{
		}
		else
		{
			g_fmrdo.is_button_down = FALSE;
			mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
		}
		break;

	case FMRDO_PEN_MAIN_TITLE:
		if(g_fmrdo.is_power_on)
		{			
			rect = (fmrdo_rectangle_struct *)&fmrdo_main_draw.freq_area;
			if (mmi_fmrdo_check_inside_rectangle(rect, pos))
			{
			}
			else
			{
				g_fmrdo.is_button_down = FALSE;
				g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
			}
		}
		break;

	default:
		break;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_pen_repeat_hdlr
* DESCRIPTION
*  Pen repeat event handler for main screen
* PARAMETERS
*  pos     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_pen_repeat_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	fmrdo_rectangle_struct *rect = NULL;
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];
	U16 freq;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (!g_fmrdo.is_power_on)
	{
		return;
	}
	
	switch (fmrdo_pen_event_on_object)
	{
	case FMRDO_PEN_MAIN_VOL_DOWN:
		{
			rect = (fmrdo_rectangle_struct *) & skin_p->vol_dec_button_area;

			if (mmi_fmrdo_check_inside_rectangle(rect, pos))
			{
				mmi_fmrdo_dec_volume();
			}
		}
		break;

	case FMRDO_PEN_MAIN_VOL_UP:
		{
			rect = (fmrdo_rectangle_struct*) & skin_p->vol_inc_button_area;

			if (mmi_fmrdo_check_inside_rectangle(rect, pos))
			{
				mmi_fmrdo_inc_volume();
			}
		}
		break;

	case FMRDO_PEN_MAIN_NEXT:
		{
			rect = (fmrdo_rectangle_struct*) & skin_p->next_button_area;

			if (mmi_fmrdo_check_inside_rectangle(rect, pos))
			{
				g_fmrdo.normal_repeat_step_count = 1;
				/* frequency is not changed during button press down so we need to increase it */
				if (g_fmrdo.frequency < MAX_FM_FREQUENCY)
				{
					freq = g_fmrdo.frequency + 1;
				}
				else
				{
					freq = MIN_FM_FREQUENCY;
				}
				mmi_fmrdo_set_frequency(freq);
			}
		}
		break;

	case FMRDO_PEN_MAIN_PREV:
		{
			rect = (fmrdo_rectangle_struct*) & skin_p->prev_button_area;

			if (mmi_fmrdo_check_inside_rectangle(rect, pos))
			{
				g_fmrdo.normal_repeat_step_count = 1;
				/* frequency is not changed during button press down so we need to decrease it */
				if (g_fmrdo.frequency > MIN_FM_FREQUENCY)
				{
					freq = g_fmrdo.frequency - 1;
				}
				else
				{
					freq = MAX_FM_FREQUENCY;
				}
				mmi_fmrdo_set_frequency(freq);
			}
		}
		break;
	}
}

#endif /* __MMI_TOUCH_SCREEN__ */ 
/* MTK Leo end */

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_set_alpha_blending_layer
* DESCRIPTION
*  Set alpha blending layer for displaying FM Radio components
* PARAMETERS
*  text        [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_set_alpha_blending_layer(BOOL set)
{
#ifdef __GDI_MEMORY_PROFILE_2__

	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	static S32 count;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (set)
	{
		if (count == 0)
		{
			gdi_push_and_set_alpha_blending_source_layer(fmrdo_base_layer);
		}
		count++;
	}
	else
	{
		if (count == 1)
		{
			gdi_pop_and_restore_alpha_blending_source_layer();
		}
		count--;
	}
	ASSERT(count >= 0);

#endif
}

#endif /* __MMI_FTE_SUPPORT__ */
#endif /* __MMI_FM_RADIO__ */ 

