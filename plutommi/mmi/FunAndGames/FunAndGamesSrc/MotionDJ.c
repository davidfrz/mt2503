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
 *  MotionDJ.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Motion Game - DJ
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
#ifndef _MMI_MOTION_DJ_C
#define _MMI_MOTION_DJ_C

#include "MMI_features.h"
#include "GameResDef.h"

#ifdef __MMI_MOTIONGAME_DJ__    /* this must after GameInc.h" */

#include "MMIDataType.h"
#include "gui_data_types.h"
#include "gdi_const.h"
#include "gdi_datatype.h"
#include "kal_general_types.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "CommonScreensResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_nvram_gprot.h"
#include "nvram_common_defs.h"
#include "custom_mmi_default_value.h"
#include "wgui_categories_util.h"
#include "GlobalConstants.h"
#include "AlertScreen.h"
#include "CustDataRes.h"
#include "Unicodexdcl.h"
#include "wgui_categories_text_viewer.h"
#include "wgui_categories_list.h"
#include "gui.h"
#include "device.h"
#include "gdi_include.h"
#include "wgui_touch_screen.h"
#include "mmi_res_range_def.h"
#include "gui_themes.h"
#include "lcd_sw_inc.h"

#include "mmi_rp_app_games_def.h"
#include "CommonScreens.h"      /* DisplayPopup() */
#include "MotionDJResDef.h"
#include "mmi_rp_app_funandgames_def.h"
#include "mmi_rp_app_games_def.h"
#include "mdi_datatype.h"       /* mdi datatype */
#include "mdi_audio.h"  /* audio */
#include "SensorSrvGport.h" /* motion sensor */

#ifdef __MMI_BACKGROUND_CALL__
#include "UCMGProt.h"
#include "UcmSrvGProt.h"
#endif

/* cui prot */
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "ProfilesSrvGprot.h"

/***************************************************************************** 
* Include
*****************************************************************************/

/***************************************************************************** 
* Define
*****************************************************************************/
#define DJ_MENU_ICON_IMG_ID         GetRootTitleIcon(MENU_ID_MOTION_APP)
#define DJ_AUDIO_COUNT              (10)
#define DJ_VOLUME_LEVEL             (7)

#define DJ_NUM_OF_INSTRUMENT_ENTRY  (3)
#define DJ_NUM_OF_VOCAL_ENTRY       (3)
#define DJ_NUM_OF_ALL_ENTRY         (DJ_NUM_OF_INSTRUMENT_ENTRY+DJ_NUM_OF_VOCAL_ENTRY)

#define DJ_ICON_FADE_TIME           (300)

#define DJ_FONT_COLOR               (gui_color(255, 255, 255))
#define DJ_FONT_BORDER_COLOR        (gui_color(0, 0, 0))

#define DJ_SEL_FONT_COLOR           (gui_color(255, 255, 255))
#define DJ_SEL_FONT_BORDER_COLOR    (gui_color(255, 0, 0))

#ifdef __MMI_TOUCH_SCREEN__
#if defined(__MMI_MAINLCD_176X220__) 
#define DJ_BACK_POS_X               144
#define DJ_BACK_POS_Y               197
#elif defined(__MMI_MAINLCD_240X320__)
#define DJ_BACK_POS_X               208
#define DJ_BACK_POS_Y               297
#elif defined(__MMI_MAINLCD_240X400__)
#define DJ_BACK_POS_X               208
#define DJ_BACK_POS_Y               377
#elif defined(__MMI_MAINLCD_320X240__)
#define DJ_BACK_POS_X               288
#define DJ_BACK_POS_Y               217
#elif defined(__MMI_MAINLCD_320X480__)
#define DJ_BACK_POS_X               288
#define DJ_BACK_POS_Y               457
#endif
#endif


/* turn on this flag will enable indivisual audio's volume config - mdi/med not implement yet */
/*#define DJ_ENABLE_INDIVISUAL_VOLUME*/

/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef enum
{
    DJ_TRIGGER_NONE,
    DJ_TRIGGER_AUTO,
    DJ_TRIGGER_SHAKE,
    DJ_TRIGGER_PRESS,

    NUM_OF_DJ_TRIGGER_TYPE
} dj_trigger_type_enum;

typedef enum
{
    DJ_AUD_INSTRUMENT,
    DJ_AUD_VOCAL,

    NUM_OF_DJ_AUDIO_TYPE
} dj_audio_type_enum;

typedef enum
{
    DJ_KEY_NONE,
    DJ_KEY_0,
    DJ_KEY_1,
    DJ_KEY_2,
    DJ_KEY_3,
    DJ_KEY_4,
    DJ_KEY_5,
    DJ_KEY_6,
    DJ_KEY_7,
    DJ_KEY_8,
    DJ_KEY_9,
    DJ_KEY_STAR,
    DJ_KEY_POUND,

    NUM_OF_DJ_KEY
} dj_key_enum;

typedef enum
{
    DJ_POPUP_RESULT_ACTION_NONE = 0,

    DJ_POPUP_RESULT_ACTION_CLOSE_EDIT_GROUP,
    DJ_POPUP_RESULT_ACTION_CLOSE_VOL_GROUP,
    DJ_POPUP_RESULT_ACTION_ALL
} dj_popup_result_action_enum;

/* 16 byte - NVRAM_EF_MOTION_DJ_SIZE */
typedef struct
{
    U16 audio_type; /* 2 byte */
    U16 audio_id;   /* 2 byte */
    U16 vol;        /* 2 byte */
    U16 trigger;    /* 2 byte */
    U16 key;        /* 2 byte */
    U16 reserve_1;  /* 2 byte */
    U16 reserve_2;  /* 2 byte */
    U16 reserve_3;  /* 2 byte */
} dj_event_struct;

typedef struct
{

    UI_string_type audio_str[DJ_AUDIO_COUNT];
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    UI_string_type volume_str[DJ_VOLUME_LEVEL];
#endif 
    UI_string_type trigger_str[NUM_OF_DJ_TRIGGER_TYPE];
    UI_string_type key_str[NUM_OF_DJ_KEY];

    /* selected */
    S32 audio_selected;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    S32 volume_selected;
#endif 
    S32 trigger_selected;
    S32 key_selected;

} setting_data_struct;

typedef struct
{
    BOOL is_trigger_sel;
    BOOL is_key_sel;
    BOOL is_text_sel;
} dj_draw_state_struct;

typedef struct
{
    S32 icon_trigger_x;
    S32 icon_trigger_y;
    S32 icon_key_x;
    S32 icon_key_y;
    S32 text_x;
    S32 text_y;
} dj_draw_pos_struct;

/* context */
typedef struct
{
    S32 selected_idx;
    U16 selected_audio_type;
    U16 prev_trigger;
    GDI_HANDLE item_layer;
    GDI_HANDLE bg_layer;
    GDI_HANDLE bg_anim;
    MDI_HANDLE aud_bg_handle;
    MDI_HANDLE aud_handle[DJ_NUM_OF_ALL_ENTRY];
    BOOL is_key_pressed[NUM_OF_DJ_KEY];
    setting_data_struct inline_data;
    dj_event_struct event_list[DJ_NUM_OF_ALL_ENTRY];

    dj_draw_state_struct draw_state[DJ_NUM_OF_ALL_ENTRY];
    U8 volume;
    U8 *volume_selected_p[7];
    S32 volume_selected_item;
    mdi_handle motion_handle;

    mmi_id cur_gid;
} dj_cntx_struct;

#if defined(__MMI_MAINLCD_176X220__) 
const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    3, 11, 52, 11, 92, 28,      /* inst 0 */
    3, 42, 52, 42, 92, 59,      /* inst 1 */
    3, 73, 52, 73, 92, 90,      /* inst 2 */
    3, 103, 52, 103, 92, 121,   /* vox 0 */
    3, 135, 52, 135, 92, 152,   /* vox 1 */
    3, 166, 52, 166, 92, 183    /* vox 2 */
};
#elif defined(__MMI_MAINLCD_240X320__)
const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    7, 14,  73, 14,  127, 32,      /* inst 0 */
    7, 61,  73, 61,  127, 79,      /* inst 1 */
    7, 108, 73, 108, 127, 126,     /* inst 2 */
    7, 155, 73, 155, 127, 173,     /* vox 0 */
    7, 202, 73, 202, 127, 220,     /* vox 1 */
    7, 249, 73, 249, 127, 267      /* vox 2 */
};
#elif defined(__MMI_MAINLCD_240X400__)
const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    7, 21,  73, 21,  127, 39,      /* inst 0 */
    7, 82,  73, 82,  127, 100,     /* inst 1 */
    7, 143, 73, 143, 127, 161,     /* inst 2 */
    7, 204, 73, 204, 127, 222,     /* vox 0 */
    7, 265, 73, 265, 127, 283,     /* vox 1 */
    7, 326, 73, 326, 127, 344      /* vox 2 */
};
#elif defined(__MMI_MAINLCD_320X240__)
const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    41, 14,  117, 14,  166, 29,      /* inst 0 */
    41, 50,  117, 50,  166, 65,      /* inst 1 */
    41, 86,  117, 86,  166, 101,     /* inst 2 */
    41, 122, 117, 122, 166, 137,     /* vox 0 */
    41, 158, 117, 158, 166, 173,     /* vox 1 */
    41, 194, 117, 194, 166, 209      /* vox 2 */
};
#elif defined(__MMI_MAINLCD_320X480__)
const dj_draw_pos_struct g_dj_draw_pos[DJ_NUM_OF_ALL_ENTRY] = 
{
    10, 14,  91, 14,  173, 44,      /* inst 0 */
    10, 90,  91, 90,  173, 120,     /* inst 1 */
    10, 166, 91, 166, 173, 196,     /* inst 2 */
    10, 242, 91, 242, 173, 272,     /* vox 0 */
    10, 318, 91, 318, 173, 348,     /* vox 1 */
    10, 394, 91, 394, 173, 424      /* vox 2 */
};
#endif

MMI_BOOL g_dj_is_pen_down;

/***************************************************************************** 
* Global Variable
*****************************************************************************/
extern __align(2)
     const U8 motion_dj_aud_dummy_bg[DJ_AUD_DUMMY_BG_LEN];

     extern __align(2)
     const U8 motion_dj_instrument_midi_0[DJ_AUD_INS_MIDI_0_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_1[DJ_AUD_INS_MIDI_1_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_2[DJ_AUD_INS_MIDI_2_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_3[DJ_AUD_INS_MIDI_3_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_4[DJ_AUD_INS_MIDI_4_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_5[DJ_AUD_INS_MIDI_5_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_6[DJ_AUD_INS_MIDI_6_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_7[DJ_AUD_INS_MIDI_7_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_8[DJ_AUD_INS_MIDI_8_LEN];
     extern __align(2)
     const U8 motion_dj_instrument_midi_9[DJ_AUD_INS_MIDI_9_LEN];

     extern __align(2)
     const U8 motion_dj_vocal_wav_0[DJ_AUD_VOX_WAVE_0_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_1[DJ_AUD_VOX_WAVE_1_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_2[DJ_AUD_VOX_WAVE_2_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_3[DJ_AUD_VOX_WAVE_3_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_4[DJ_AUD_VOX_WAVE_4_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_5[DJ_AUD_VOX_WAVE_5_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_6[DJ_AUD_VOX_WAVE_6_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_7[DJ_AUD_VOX_WAVE_7_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_8[DJ_AUD_VOX_WAVE_8_LEN];
     extern __align(2)
     const U8 motion_dj_vocal_wav_9[DJ_AUD_VOX_WAVE_9_LEN];

/***************************************************************************** 
* Global Function
*****************************************************************************/
     extern void inline_select_menu_goto_item(S32 index);

/***************************************************************************** 
* Local Variable
*****************************************************************************/
     dj_cntx_struct g_dj_cntx;

/***************************************************************************** 
* Local Function
*****************************************************************************/
/* volume setting screen */
     static void mmi_motion_dj_entry_vol_setting_scr(void);
     static void mmi_motion_dj_vol_setting_done_hdlr(U32 gid);

/* volume setting screen */
     static void mmi_motion_dj_entry_help_scr(void);

/* setting screen */
     static void mmi_motion_dj_entry_setting_scr(void);
     static void mmi_motion_dj_setting_highlight_hdlr(S32 index);

/* edit screen */
     static void mmi_motion_dj_entry_edit_scr(void);
     //static void mmi_motion_dj_edit_delay_play_audio(void);
     //static void mmi_motion_dj_edit_audio_highlight_handler(S32 index);
     static void mmi_motion_dj_edit_done(mmi_id gid);

/* play screen */
     static void mmi_motion_dj_entry_play_scr(void);
     static void mmi_motion_dj_exit_play_scr(void);
     static void mmi_motion_dj_play_shake_trigger(srv_sensor_type_enum sensor_type, void *sensor_data, void *user_data);
     static void mmi_motion_dj_draw_items(void);
#if 0
/* under construction !*/
#endif
     static void mmi_motion_dj_auto_icon_timeout(void);
     static void mmi_motion_dj_shake_0_icon_timeout(void);
     static void mmi_motion_dj_shake_1_icon_timeout(void);
     static void mmi_motion_dj_shake_2_icon_timeout(void);
     static void mmi_motion_dj_shake_3_icon_timeout(void);
     static void mmi_motion_dj_shake_4_icon_timeout(void);
     static void mmi_motion_dj_shake_5_icon_timeout(void);

     static void mmi_motion_dj_play_key_0_press(void);
     static void mmi_motion_dj_play_key_0_release(void);
     static void mmi_motion_dj_play_key_1_press(void);
     static void mmi_motion_dj_play_key_1_release(void);
     static void mmi_motion_dj_play_key_2_press(void);
     static void mmi_motion_dj_play_key_2_release(void);
     static void mmi_motion_dj_play_key_3_press(void);
     static void mmi_motion_dj_play_key_3_release(void);
     static void mmi_motion_dj_play_key_4_press(void);
     static void mmi_motion_dj_play_key_4_release(void);
     static void mmi_motion_dj_play_key_5_press(void);
     static void mmi_motion_dj_play_key_5_release(void);
     static void mmi_motion_dj_play_key_6_press(void);
     static void mmi_motion_dj_play_key_6_release(void);
     static void mmi_motion_dj_play_key_7_press(void);
     static void mmi_motion_dj_play_key_7_release(void);
     static void mmi_motion_dj_play_key_8_press(void);
     static void mmi_motion_dj_play_key_8_release(void);
     static void mmi_motion_dj_play_key_9_press(void);
     static void mmi_motion_dj_play_key_9_release(void);
     static void mmi_motion_dj_play_key_star_press(void);
     static void mmi_motion_dj_play_key_star_release(void);
     static void mmi_motion_dj_play_key_pound_press(void);
     static void mmi_motion_dj_play_key_pound_release(void);

#ifdef __MMI_TOUCH_SCREEN__
     static void mmi_motion_dj_pen_down_hdlr(mmi_pen_point_struct pos);
     static void mmi_motion_dj_pen_up_hdlr(mmi_pen_point_struct pos);
     static void mmi_motion_dj_pen_move_hdlr(mmi_pen_point_struct pos);
     static void mmi_motion_dj_rsk_down_hdlr(void);
     static void mmi_motion_dj_rsk_up_hdlr(void);
#endif /* __MMI_TOUCH_SCREEN__ */ 

     static void mmi_motion_dj_volume_up(void);
     static void mmi_motion_dj_volume_down(void);

#ifdef __BT_SPK_VOL_CONTROL__
    static MMI_BOOL mmi_motion_dj_hfp_volume_callback(U8 volume, MMI_BOOL is_mute);
#endif

    static void mmi_motion_dj_draw_after_draw_anim(GDI_RESULT result);
    static void mmi_motion_dj_entry_app_internal(void);
    static MMI_ID mmi_motion_dj_display_popup(mmi_id gid, UI_string_type string, mmi_event_notify_enum event_id, S32 user_data);

/*****************************************************************************
*
*  App                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_init_app
 * DESCRIPTION
 *  init dj app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_init_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
}

static void mmi_motion_dj_init_main_menu(evt)
{
    cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
    
    cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_MOTION_DJ_START, IMG_GLOBAL_L1);
    cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_MOTION_DJ_SETTING, IMG_GLOBAL_L2);
    cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_MOTION_DJ_VOL_SETTING, IMG_GLOBAL_L3);
    cui_menu_set_item_image(menu_evt->sender_id, MENU_ID_MOTION_DJ_HELP, IMG_GLOBAL_L4);
    
    cui_menu_enable_center_softkey(menu_evt->sender_id, 0, IMG_GLOBAL_COMMON_CSK);
}


static mmi_ret mmi_motion_dj_app_group_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
    /*********************** General Group Function Start ***************************************/
    case EVT_ID_GROUP_FIRST_ENTRY:
    case EVT_ID_GROUP_ACTIVE:
    case EVT_ID_GROUP_INACTIVE:
        break;
        
    case EVT_ID_GROUP_DEINIT:
        break; 
        
    case EVT_ID_POPUP_QUIT:
        break;

    /*********************** General Group Function End ***************************************/    
        
    /*********************** Menu Cui Function Start ***************************************/
    case EVT_ID_CUI_MENU_LIST_ENTRY:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_MOTION_DJ_APP)
            {
                mmi_motion_dj_init_main_menu(evt);
            }
        }
        break;
        
    case EVT_ID_CUI_MENU_ITEM_CSK_SELECT:
    case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            if (menu_evt->parent_menu_id == MENU_ID_MOTION_DJ_APP)
            {
                switch(menu_evt->highlighted_menu_id)
                {
                case MENU_ID_MOTION_DJ_START:
                    mmi_motion_dj_entry_play_scr();
                    break;
                    
                case MENU_ID_MOTION_DJ_SETTING:
                    mmi_motion_dj_entry_setting_scr();
                    break;
                    
                case MENU_ID_MOTION_DJ_VOL_SETTING:
                    mmi_motion_dj_entry_vol_setting_scr();
                    break;
                    
                case MENU_ID_MOTION_DJ_HELP:
                    mmi_motion_dj_entry_help_scr();
                    break;
                }
            }
            break;
        }
        break;
        
    case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_event_struct* menu_evt = (cui_menu_event_struct*)evt;
            
            cui_menu_close(menu_evt->sender_id);
            break;
        }
        break;
    /*********************** Menu Cui Function End ***************************************/
    }
    
    return MMI_RET_OK;
}


void mmi_motion_dj_entry_app(void)
{
    if (mmi_frm_group_is_present(g_dj_cntx.cur_gid))
    {
        mmi_frm_group_close(g_dj_cntx.cur_gid);
    }
    
    g_dj_cntx.cur_gid = mmi_frm_group_create (GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_motion_dj_app_group_proc, NULL);
    MMI_ASSERT (g_dj_cntx.cur_gid);
    
    mmi_frm_group_enter(g_dj_cntx.cur_gid, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_motion_dj_entry_app_internal();
}


static void mmi_motion_dj_init_app_internal(void)
{
    U8 i;
    S32 idx;
    S16 error;

    for (i = 0 ; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        /* load value from NVRAM */
        ReadRecord(
            NVRAM_EF_MOTION_DJ_LID,
            i+1,
            (void*)&g_dj_cntx.event_list[i],
            NVRAM_EF_MOTION_DJ_SIZE,
            &error);
    }
    
    ReadValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    if (g_dj_cntx.volume == 0xff)
    {
        g_dj_cntx.volume = LEVEL4;
        WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    }
    
    /* init if needed */ 
    if (g_dj_cntx.event_list[0].audio_type == 0xffff) 
    {
        idx = 0;
        for (i = 0; i < DJ_NUM_OF_INSTRUMENT_ENTRY; i++)
        {
            g_dj_cntx.event_list[idx].audio_type = DJ_AUD_INSTRUMENT;
            g_dj_cntx.event_list[idx].audio_id = 0;
            g_dj_cntx.event_list[idx].vol = LEVEL4;
            g_dj_cntx.event_list[idx].trigger = DJ_TRIGGER_NONE;
            g_dj_cntx.event_list[idx].key = DJ_KEY_NONE;
            idx++;
        }
        
        for (i = 0; i < DJ_NUM_OF_VOCAL_ENTRY; i++)
        {
            g_dj_cntx.event_list[idx].audio_type = DJ_AUD_VOCAL;
            g_dj_cntx.event_list[idx].audio_id = 0;
            g_dj_cntx.event_list[idx].vol = LEVEL4;
            g_dj_cntx.event_list[idx].trigger = DJ_TRIGGER_NONE;
            g_dj_cntx.event_list[idx].key = DJ_KEY_NONE;
            idx++;
        }
        
        for (i = 0 ; i < DJ_NUM_OF_ALL_ENTRY; i++)
        {
            /* write inited value to NVRAM */
            WriteRecord(
                NVRAM_EF_MOTION_DJ_LID,
                i+1,
                (void*)&g_dj_cntx.event_list[i],
                NVRAM_EF_MOTION_DJ_SIZE,
                &error);
        }
        
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_app
 * DESCRIPTION
 *  enter point of dj app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_entry_app_internal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID  cui_gid;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_motion_dj_init_app_internal();
    
    mmi_frm_group_create(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_APP, mmi_motion_dj_app_group_proc, (void*)NULL); 
    
    mmi_frm_group_enter(SCR_ID_MOTION_DJ_APP, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    cui_gid = cui_menu_create(
        SCR_ID_MOTION_DJ_APP, 
        CUI_MENU_SRC_TYPE_RESOURCE, 
        CUI_MENU_TYPE_APPMAIN,
        MENU_ID_MOTION_DJ_APP, 
        MMI_TRUE, 
        NULL);
    cui_menu_set_default_title_image(cui_gid, (UI_image_type)get_image(DJ_MENU_ICON_IMG_ID));
    cui_menu_run(cui_gid);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_start
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_highlight_start(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_play_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_play_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_setting
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_highlight_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_setting_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_setting_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_vol_setting
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_highlight_vol_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_vol_setting_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_vol_setting_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_highlight_setting
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_highlight_help(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SetLeftSoftkeyFunction(mmi_motion_dj_entry_help_scr, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_entry_help_scr, KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
}


/*****************************************************************************
*
*  Volume Setting Screen                                                
*
*****************************************************************************/
typedef enum
{
    MMI_MOTION_DJ_VOL_SETTING_CAPTION,
    MMI_MOTION_DJ_VOL_SETTING_SELECTOR,

    MMI_MOTION_DJ_VOL_SETTING_COUNT
} mmi_motion_dj_vol_setting_enum;

static const U16 mmi_motion_dj_vol_setting_str[] =
{
    STR_GLOBAL_1,
        STR_GLOBAL_2,
        STR_GLOBAL_3,
        STR_GLOBAL_4,
        STR_GLOBAL_5,
        STR_GLOBAL_6,
        STR_GLOBAL_7,
        STR_GLOBAL_8,
        STR_GLOBAL_9
};

static const cui_inline_item_caption_struct mmi_motion_dj_vol_setting_caption = 
{
    STR_GLOBAL_VOLUME
};
static const cui_inline_item_select_struct mmi_motion_dj_vol_setting_selector = 
{
    7, 0, (U16 *)&mmi_motion_dj_vol_setting_str[0]
};

static const cui_inline_set_item_struct mmi_motion_dj_vol_setting_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_VOL_SETTING_CAPTION,	    CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + MMI_MOTION_DJ_VOL_SETTING_CAPTION,   (void*)&mmi_motion_dj_vol_setting_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_VOL_SETTING_SELECTOR,	    CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                   (void*)&mmi_motion_dj_vol_setting_selector}
};

static const cui_inline_struct mmi_motion_dj_vol_setting_inline_cntx = 
{
    MMI_MOTION_DJ_VOL_SETTING_COUNT,
    STR_ID_MOTION_DJ_VOL_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_motion_dj_vol_setting_inline_item 
};


static void mmi_motion_dj_vol_setting_init_inline_item_value(MMI_ID inline_id)
{
    g_dj_cntx.volume_selected_item = (S32)g_dj_cntx.volume;
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_VOL_SETTING_SELECTOR, 
        (void *)g_dj_cntx.volume_selected_item);
}

static void mmi_motion_dj_vol_setting_change_item_content(cui_event_inline_notify_struct *notify)
{
    switch(notify->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    case MMI_MOTION_DJ_VOL_SETTING_SELECTOR:
        g_dj_cntx.volume_selected_item = notify->param;
        break;
    }
}

static mmi_ret mmi_motion_dj_vol_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        /**********************Inline CUI event*************************/
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
            if (notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_motion_dj_vol_setting_change_item_content(notify);
            }
        }
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        break;
        
    case EVT_ID_CUI_INLINE_SET_KEY:
        break;
        
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            //cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mmi_motion_dj_vol_setting_done_hdlr(SCR_ID_MOTION_DJ_VOL_SETTING);
        }
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            cui_inline_close(inline_evt->sender_id);
        }
        break;
    
    case EVT_ID_POPUP_QUIT:
        if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)DJ_POPUP_RESULT_ACTION_CLOSE_VOL_GROUP)
        {
            //cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mmi_frm_group_close(SCR_ID_MOTION_DJ_VOL_SETTING);
        }
        break;
    }

    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_vol_setting_scr
 * DESCRIPTION
 *  enter setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_vol_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_VOL_SETTING, mmi_motion_dj_vol_setting_group_proc, (void*)NULL); 
    mmi_frm_group_enter(SCR_ID_MOTION_DJ_VOL_SETTING, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(SCR_ID_MOTION_DJ_VOL_SETTING, &mmi_motion_dj_vol_setting_inline_cntx);
    mmi_motion_dj_vol_setting_init_inline_item_value(inline_id);
    cui_inline_set_title_icon(inline_id, DJ_MENU_ICON_IMG_ID);
    cui_inline_run(inline_id);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_vol_setting_done_hdlr
 * DESCRIPTION
 *  highlight handler of start
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_vol_setting_done_hdlr(U32 gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.volume = (U8)g_dj_cntx.volume_selected_item;
    WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);

    mmi_motion_dj_display_popup(g_dj_cntx.cur_gid, (UI_string_type)GetString(STR_GLOBAL_DONE), MMI_EVENT_SUCCESS, DJ_POPUP_RESULT_ACTION_NONE);
    mmi_frm_group_close(SCR_ID_MOTION_DJ_VOL_SETTING);
}


/*****************************************************************************
*
*  Help Screen                                                
*
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_help_scr
 * DESCRIPTION
 *  enter setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_help_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    PS8 buffer;
    S32 bufferSize;
    U8 *guiBuffer;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_HELP, NULL, mmi_motion_dj_entry_help_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_HELP);

    buffer = GetString(STR_ID_MOTION_DJ_HELP_CONTENT);
    bufferSize = mmi_ucs2strlen(buffer);

    ShowCategory74Screen(
        STR_GLOBAL_HELP,
        DJ_MENU_ICON_IMG_ID,
        0,
        0,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        (PU8) buffer,
        bufferSize,
        guiBuffer);

    /* go back to game menu */
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
*
*  Setting Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_setting_scr
 * DESCRIPTION
 *  enter setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_setting_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer;
    U16 icon_list_1[MAX_SUB_MENUS];
    U16 icon_list_2[MAX_SUB_MENUS];
    S32 i;
    MMI_BOOL entry_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    entry_ret = mmi_frm_scrn_enter (g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_SETTING, NULL, mmi_motion_dj_entry_setting_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    gui_buffer = mmi_frm_scrn_get_gui_buf(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_SETTING);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString((U16) (STR_ID_MOTION_DJ_INSTRUMENT_0 + g_dj_cntx.event_list[i].audio_id)));
            }
            else
            {
                mmi_ucs2cpy((PS8) subMenuDataPtrs[i], (PS8) GetString(STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1 + i));
            }
        }
        else
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString((U16) (STR_ID_MOTION_DJ_VOCAL_0 + g_dj_cntx.event_list[i].audio_id)));
            }
            else
            {
                mmi_ucs2cpy(
                    (PS8) subMenuDataPtrs[i],
                    (PS8) GetString(STR_ID_MOTION_DJ_VOCAL_TITLE_1 + i - DJ_NUM_OF_INSTRUMENT_ENTRY));
            }
        }

        icon_list_1[i] = (U16) (IMG_ID_MOTION_DJ_ICON_TRIGGER_NONE + g_dj_cntx.event_list[i].trigger);
        icon_list_2[i] = (U16) (IMG_ID_MOTION_DJ_ICON_KEY_DUMMY + g_dj_cntx.event_list[i].key);
    }

    /* get item count */
    RegisterHighlightHandler(mmi_motion_dj_setting_highlight_hdlr);

    EnableCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    
    ShowCategory73Screen(
        STR_ID_MOTION_DJ_SETTING,
        DJ_MENU_ICON_IMG_ID,
        STR_GLOBAL_OK,
        0,
        STR_GLOBAL_BACK,
        0,
        DJ_NUM_OF_ALL_ENTRY,
        (U8 **) subMenuDataPtrs,    /* list of items */
        (U16*) icon_list_1,         /* list of icon1 */
        (U16*) icon_list_2,         /* list of icon2 */
        (U16) 0,                    /* highlighted item */
        gui_buffer,
        1);                         /* display flag */

    SetLeftSoftkeyFunction(mmi_motion_dj_entry_edit_scr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_motion_dj_entry_edit_scr, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_setting_highlight_hdlr
 * DESCRIPTION
 *  highlight handler for settng
 * PARAMETERS
 *  index       [IN]        Highlighted item index
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_setting_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.selected_idx = index;

    if (index < DJ_NUM_OF_INSTRUMENT_ENTRY)
    {
        g_dj_cntx.selected_audio_type = DJ_AUD_INSTRUMENT;
    }
    else
    {
        g_dj_cntx.selected_audio_type = DJ_AUD_VOCAL;
    }
}

/*****************************************************************************
*
*  Edit Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_edit_scr
 * DESCRIPTION
 *  enter audio edit screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
typedef enum
{
    MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_CAPTION = 0,
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    MMI_MOTION_DJ_MUSIC_SETTING_VOL_CAPTION,
#endif
    MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_CAPTION,
    MMI_MOTION_DJ_MUSIC_SETTING_KEY_CAPTION,
    
    MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_SELECTOR,
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    MMI_MOTION_DJ_MUSIC_SETTING_VOL_SELECTOR,
#endif
    MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_SELECTOR,
    MMI_MOTION_DJ_MUSIC_SETTING_KEY_SELECTOR,

    MMI_MOTION_DJ_MUSIC_SETTING_COUNT
} mmi_motion_dj_music_setting_enum;

/*********************************** audio start*********************************/
static const U16 mmi_motion_dj_music_setting_audio_ins_str[] =
{
    STR_ID_MOTION_DJ_INSTRUMENT_0,
    STR_ID_MOTION_DJ_INSTRUMENT_1,
    STR_ID_MOTION_DJ_INSTRUMENT_2,
    STR_ID_MOTION_DJ_INSTRUMENT_3,
    STR_ID_MOTION_DJ_INSTRUMENT_4,
    STR_ID_MOTION_DJ_INSTRUMENT_5,
    STR_ID_MOTION_DJ_INSTRUMENT_6,
    STR_ID_MOTION_DJ_INSTRUMENT_7,
    STR_ID_MOTION_DJ_INSTRUMENT_8,
    STR_ID_MOTION_DJ_INSTRUMENT_9
};

static const U16 mmi_motion_dj_music_setting_audio_vox_str[] =
{
    STR_ID_MOTION_DJ_VOCAL_0,
    STR_ID_MOTION_DJ_VOCAL_1,
    STR_ID_MOTION_DJ_VOCAL_2,
    STR_ID_MOTION_DJ_VOCAL_3,
    STR_ID_MOTION_DJ_VOCAL_4,
    STR_ID_MOTION_DJ_VOCAL_5,
    STR_ID_MOTION_DJ_VOCAL_6,
    STR_ID_MOTION_DJ_VOCAL_7,
    STR_ID_MOTION_DJ_VOCAL_8,
    STR_ID_MOTION_DJ_VOCAL_9
};

static const cui_inline_item_caption_struct mmi_motion_dj_music_setting_audio_caption = 
{
    STR_ID_MOTION_DJ_EDIT_AUDIO
};
static const cui_inline_item_select_struct mmi_motion_dj_music_setting_audio_selector = 
{
    10, 0, (U16 *)&mmi_motion_dj_music_setting_audio_ins_str[0]
};
/*********************************** audio end *********************************/


/*********************************** volume start *********************************/
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
static const cui_inline_item_caption_struct mmi_motion_dj_music_setting_vol_caption = 
{
    STR_GLOBAL_VOLUME
};
static const cui_inline_item_select_struct mmi_motion_dj_music_setting_vol_selector = 
{
    DJ_VOLUME_LEVEL, 0, (U16 *)&mmi_motion_dj_vol_setting_str[0]
};
#endif
/*********************************** volume end *********************************/


/*********************************** trigger start *********************************/
static const U16 mmi_motion_dj_music_setting_trigger_str[] =
{
    STR_GLOBAL_NONE,
    STR_ID_MOTION_DJ_EDIT_TRIGGER_AUTO,
    STR_ID_MOTION_DJ_EDIT_TRIGGER_SHAKE,
    STR_ID_MOTION_DJ_EDIT_TRIGGER_KEY_PRESS
};

static const cui_inline_item_caption_struct mmi_motion_dj_music_setting_trigger_caption = 
{
    STR_ID_MOTION_DJ_EDIT_TRIGGER
};
static const cui_inline_item_select_struct mmi_motion_dj_music_setting_trigger_selector = 
{
    4, 0, (U16 *)&mmi_motion_dj_music_setting_trigger_str[0]
};
/*********************************** trigger end *********************************/


/*********************************** key start *********************************/
static const U16 mmi_motion_dj_music_setting_key_str[] =
{
    STR_GLOBAL_NONE,
    STR_ID_MOTION_DJ_KEY_0,
    STR_ID_MOTION_DJ_KEY_1,
    STR_ID_MOTION_DJ_KEY_2,
    STR_ID_MOTION_DJ_KEY_3,
    STR_ID_MOTION_DJ_KEY_4,
    STR_ID_MOTION_DJ_KEY_5,
    STR_ID_MOTION_DJ_KEY_6,
    STR_ID_MOTION_DJ_KEY_7,
    STR_ID_MOTION_DJ_KEY_8,
    STR_ID_MOTION_DJ_KEY_9,
    STR_ID_MOTION_DJ_KEY_STAR,
    STR_ID_MOTION_DJ_KEY_POUND
};

static const cui_inline_item_caption_struct mmi_motion_dj_music_setting_key_caption = 
{
    STR_ID_MOTION_DJ_EDIT_KEY
};
static const cui_inline_item_select_struct mmi_motion_dj_music_setting_key_selector = 
{
    13, 0, (U16 *)&mmi_motion_dj_music_setting_key_str[0]
};
/*********************************** key end *********************************/


/*********************************** content start *********************************/
static const cui_inline_set_item_struct mmi_motion_dj_music_setting_inline_item[] = 
{
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_CAPTION,	  CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_CAPTION,    (void*)&mmi_motion_dj_music_setting_audio_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_SELECTOR,	  CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                            (void*)&mmi_motion_dj_music_setting_audio_selector},
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_VOL_CAPTION,	      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + MMI_MOTION_DJ_MUSIC_SETTING_VOL_CAPTION,      (void*)&mmi_motion_dj_music_setting_vol_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_VOL_SELECTOR,	  CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                            (void*)&mmi_motion_dj_music_setting_vol_selector},
#endif
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_CAPTION,	  CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_CAPTION,  (void*)&mmi_motion_dj_music_setting_trigger_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_SELECTOR,  CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                            (void*)&mmi_motion_dj_music_setting_trigger_selector},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_KEY_CAPTION,	      CUI_INLINE_ITEM_TYPE_CAPTION,   IMG_GLOBAL_L1 + MMI_MOTION_DJ_MUSIC_SETTING_KEY_CAPTION,      (void*)&mmi_motion_dj_music_setting_key_caption},
    {CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_KEY_SELECTOR,	  CUI_INLINE_ITEM_TYPE_SELECT,    0,                                                            (void*)&mmi_motion_dj_music_setting_key_selector}
};

static const cui_inline_struct mmi_motion_dj_music_setting_inline_cntx = 
{
    MMI_MOTION_DJ_MUSIC_SETTING_COUNT,
    STR_ID_MOTION_DJ_VOL_SETTING,
    0,
    CUI_INLINE_SCREEN_LOOP | CUI_INLINE_SCREEN_DISABLE_DONE, 
    NULL, 
    mmi_motion_dj_music_setting_inline_item 
};
/*********************************** content end *********************************/


static void mmi_motion_dj_music_setting_init_inline_item_value(MMI_ID inline_id)
{
    U16 string_id;

    g_dj_cntx.inline_data.audio_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    g_dj_cntx.inline_data.volume_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].vol;
#endif 
    g_dj_cntx.inline_data.trigger_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger;
    g_dj_cntx.inline_data.key_selected = g_dj_cntx.event_list[g_dj_cntx.selected_idx].key;
    
    g_dj_cntx.prev_trigger = g_dj_cntx.inline_data.trigger_selected;

    if (g_dj_cntx.selected_idx < DJ_NUM_OF_INSTRUMENT_ENTRY)
    {
        cui_inline_set_value(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_SELECTOR, 
            (void *)g_dj_cntx.inline_data.audio_selected);
    }
    else
    {
        U8 i;
        UI_string_type string[10];

        for (i = 0; i < 10; i++)
        {
            string[i] = (UI_string_type)GetString(mmi_motion_dj_music_setting_audio_vox_str[i]);
        }
        cui_inline_set_item_select(inline_id, 
            CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_SELECTOR, 
            10, (void*)&string[0], g_dj_cntx.inline_data.audio_selected);
    }

#ifdef DJ_ENABLE_INDIVISUAL_VOLUME    
    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_VOL_SELECTOR, 
        (void *)g_dj_cntx.inline_data.volume_selected);
#endif

    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_SELECTOR, 
        (void *)g_dj_cntx.inline_data.trigger_selected);

    cui_inline_set_value(inline_id, 
        CUI_INLINE_ITEM_ID_BASE + MMI_MOTION_DJ_MUSIC_SETTING_KEY_SELECTOR, 
        (void *)g_dj_cntx.inline_data.key_selected);

    if (g_dj_cntx.selected_idx < DJ_NUM_OF_INSTRUMENT_ENTRY)
    {
        if (g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger != DJ_TRIGGER_NONE)
        {
            string_id = STR_ID_MOTION_DJ_INSTRUMENT_0 + g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id;
        }
        else
        {
            string_id = STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1 + g_dj_cntx.selected_idx;
        }
    }
    else
    {
        if (g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger != DJ_TRIGGER_NONE)
        {
            string_id = STR_ID_MOTION_DJ_VOCAL_0 + g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id;
        }
        else
        {
            string_id = STR_ID_MOTION_DJ_INSTRUMENT_TITLE_1 + g_dj_cntx.selected_idx;
        }
    }
    cui_inline_set_title_string(inline_id, (UI_string_type)GetString(string_id));
}

static void mmi_motion_dj_music_setting_change_item_content(cui_event_inline_notify_struct *notify)
{
    switch(notify->item_id - CUI_INLINE_ITEM_ID_BASE)
    {
    case MMI_MOTION_DJ_MUSIC_SETTING_AUDIO_SELECTOR:
        g_dj_cntx.inline_data.audio_selected = notify->param;
        break;

#ifdef DJ_ENABLE_INDIVISUAL_VOLUME   
    case MMI_MOTION_DJ_MUSIC_SETTING_VOL_SELECTOR:
        g_dj_cntx.inline_data.volume_selected = notify->param;
        break;
#endif

    case MMI_MOTION_DJ_MUSIC_SETTING_TRIGGER_SELECTOR:
        g_dj_cntx.inline_data.trigger_selected = notify->param;
        break;

    case MMI_MOTION_DJ_MUSIC_SETTING_KEY_SELECTOR:
        g_dj_cntx.inline_data.key_selected = notify->param;
        break;
    }
}

static mmi_ret mmi_motion_dj_music_setting_group_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        /**********************Inline CUI event*************************/
    case EVT_ID_CUI_INLINE_NOTIFY:
        {
            cui_event_inline_notify_struct *notify = (cui_event_inline_notify_struct *)evt;
            if (notify->event_type == CUI_INLINE_NOTIFY_SELECT_FOCUS_CHANGED)
            {
                mmi_motion_dj_music_setting_change_item_content(notify);
            }
        }
        break;
        
    case EVT_ID_CUI_INLINE_MAIN_SCREEN_ACTIVE:
        break;
        
    case EVT_ID_CUI_INLINE_SET_KEY:
        break;
        
    case EVT_ID_CUI_INLINE_CSK_PRESS:
    case EVT_ID_CUI_INLINE_SUBMIT:
        {
            //cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mdi_audio_stop_string();
            
            mmi_motion_dj_edit_done(g_dj_cntx.cur_gid);
        }
        break;
        
    case EVT_ID_CUI_INLINE_ABORT:
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mdi_audio_stop_string();
            cui_inline_close(inline_evt->sender_id);
        }
        break;

    case EVT_ID_POPUP_QUIT:
        if (((mmi_event_popoupcallback_result_struct*)evt)->user_tag == (void*)DJ_POPUP_RESULT_ACTION_CLOSE_VOL_GROUP)
        {
            cui_event_inline_set_key_struct *inline_evt = (cui_event_inline_set_key_struct *)evt;
            
            mmi_frm_group_close(inline_evt->sender_id);
        }
        break;
    }
    
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_vol_setting_scr
 * DESCRIPTION
 *  enter setting screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_edit_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID inline_id = GRP_ID_INVALID;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_EDIT, mmi_motion_dj_music_setting_group_proc, (void*)NULL); 
    mmi_frm_group_enter(SCR_ID_MOTION_DJ_EDIT, MMI_FRM_NODE_SMART_CLOSE_FLAG);
    inline_id = cui_inline_create(SCR_ID_MOTION_DJ_EDIT, &mmi_motion_dj_music_setting_inline_cntx);
    mmi_motion_dj_music_setting_init_inline_item_value(inline_id);
    cui_inline_set_title_icon(inline_id, DJ_MENU_ICON_IMG_ID);
    cui_inline_run(inline_id);
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
#endif
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
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_edit_done
 * DESCRIPTION
 *  setting edit done
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_edit_done(mmi_id gid)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
    S32 i;

    U16 trigger;
    U16 key;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    trigger = g_dj_cntx.inline_data.trigger_selected;
    key = g_dj_cntx.inline_data.key_selected;

    if (trigger != DJ_TRIGGER_NONE)
    {

        /* trigger is press but key is not set */
        if (trigger == DJ_TRIGGER_PRESS)
        {
            if (key == DJ_KEY_NONE)
            {
                mmi_motion_dj_display_popup(
                    g_dj_cntx.cur_gid,
                    (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_EMPTY_KEY), 
                    MMI_EVENT_FAILURE, 
                    DJ_POPUP_RESULT_ACTION_NONE);

                return;
            }
        }

        for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
        {
            if (g_dj_cntx.selected_idx != i)
            {
                if (trigger == DJ_TRIGGER_AUTO)
                {
                    if (g_dj_cntx.event_list[i].trigger == trigger)
                    {
                        /* already has auto trigger event */
                        mmi_motion_dj_display_popup(
                            g_dj_cntx.cur_gid,
                            (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_AUTO), 
                            MMI_EVENT_FAILURE, 
                            DJ_POPUP_RESULT_ACTION_NONE);
                        return;
                    }
                    else
                    {
                        g_dj_cntx.inline_data.key_selected = DJ_KEY_NONE;
                    }
                }
                else if ((trigger == DJ_TRIGGER_SHAKE) || (trigger == DJ_TRIGGER_PRESS))
                {
                    /* has same event - shake and press with same key */
                    if ((g_dj_cntx.event_list[i].key != DJ_KEY_NONE) && (g_dj_cntx.event_list[i].key == key))
                    {
                        if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE)
                        {
                            mmi_motion_dj_display_popup(
                                g_dj_cntx.cur_gid,
                                (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE_SAME_KEY), 
                                MMI_EVENT_FAILURE, 
                                DJ_POPUP_RESULT_ACTION_NONE);
                            return;
                        }
                        else if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_PRESS)
                        {
                            mmi_motion_dj_display_popup(
                                g_dj_cntx.cur_gid,
                                (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_PRESS_SAME_KEY), 
                                MMI_EVENT_FAILURE, 
                                DJ_POPUP_RESULT_ACTION_NONE);
                            return;
                        }
                    }
                    else if ((trigger == DJ_TRIGGER_SHAKE) &&
                             (key == DJ_KEY_NONE) &&
                             (g_dj_cntx.event_list[i].trigger == trigger) && (g_dj_cntx.event_list[i].key == key))
                    {
                        /* has shake only */
                        mmi_motion_dj_display_popup(
                            g_dj_cntx.cur_gid,
                            (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_HAS_SHAKE), 
                            MMI_EVENT_FAILURE, 
                            DJ_POPUP_RESULT_ACTION_NONE);
                        return;
                    }
                }
            }
        }

    }

    /* checking: can only have 1 auto */
    mmi_motion_dj_display_popup(
        g_dj_cntx.cur_gid,
        (UI_string_type)GetString(STR_GLOBAL_DONE), 
        MMI_EVENT_SUCCESS, 
        DJ_POPUP_RESULT_ACTION_NONE);
    mmi_frm_group_close(SCR_ID_MOTION_DJ_EDIT);

    /* pass , write to NVRAM */
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].audio_id = g_dj_cntx.inline_data.audio_selected;
#ifdef DJ_ENABLE_INDIVISUAL_VOLUME
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].vol = g_dj_cntx.inline_data.volume_selected;
#endif 
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].trigger = g_dj_cntx.inline_data.trigger_selected;
    g_dj_cntx.event_list[g_dj_cntx.selected_idx].key = g_dj_cntx.inline_data.key_selected;

    /* write value from NVRAM */
    WriteRecord(
        NVRAM_EF_MOTION_DJ_LID,
        g_dj_cntx.selected_idx+1,
        (void*)&g_dj_cntx.event_list[g_dj_cntx.selected_idx],
        NVRAM_EF_MOTION_DJ_SIZE,
        &error);

}

/*****************************************************************************
*
*  Play Screen                                                
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_entry_play_scr
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_entry_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //U8 *gui_buffer;
    S32 i;
    BOOL has_trigger;
    S16 error;
    MMI_BOOL entry_ret;

    //modify for sensor split
	srv_sensor_motion_shake_cfg_struct shake_sensitive;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has any trigger */

   // modify for sensor split
	shake_sensitive.sensitive = SRV_SENSOR_MOTION_SHAKE_WEAK;

    g_dj_is_pen_down = MMI_FALSE;
    has_trigger = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
        {
            has_trigger = TRUE;
        }
    }

    if (!has_trigger)
    {
        mmi_motion_dj_display_popup(
            g_dj_cntx.cur_gid,
            (UI_string_type)GetString(STR_ID_MOTION_DJ_NOTIFY_EMPTY_TRIGGER), 
            MMI_EVENT_FAILURE, 
            DJ_POPUP_RESULT_ACTION_NONE);
        return;
    }

#ifdef __MMI_BACKGROUND_CALL__
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
        {
            if (mmi_frm_scrn_get_state (g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_PLAY) == MMI_SCENARIO_STATE_BACKWARD_ACTIVE)
            {
                mmi_ucm_app_entry_error_message();
                return;
            }
            else
            {
                mmi_frm_scrn_close(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_PLAY);
                return;
            }
        }
#endif

    /* entry new screen */
    entry_ret = mmi_frm_scrn_enter (g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_PLAY, mmi_motion_dj_exit_play_scr, mmi_motion_dj_entry_play_scr, MMI_FRM_UNKNOW_SCRN);
    if (!entry_ret)
    {
        return;
    }

    //gui_buffer = mmi_frm_scrn_get_gui_buf(g_dj_cntx.cur_gid, SCR_ID_MOTION_DJ_PLAY);

    /* entry full screen app */
    entry_full_screen();

    gdi_layer_reset_clip();
    gdi_layer_reset_text_clip();

    /* stop bg music */
    mdi_audio_suspend_background_play();

    /* stop MMI sleep */
    //TurnOnBacklight(0);

    /* force all playing keypad tone off */
    srv_profiles_stop_tone(SRV_PROF_TONE_KEYPAD);

    /* disable key pad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

    /* disalbe align timer  */
    UI_disable_alignment_timers();

    /* enable multi-layer */
    gdi_layer_multi_layer_enable();

	//modify for sensor split
    /* enable motion sensor */
   // g_dj_cntx.motion_handle = mdi_motion_start_listen_shake(MDI_MOTION_SENSITIVE_LOW, mmi_motion_dj_play_shake_trigger, NULL);

	g_dj_cntx.motion_handle = srv_sensor_start_listen(SRV_SENSOR_MOTION_SHAKE, &shake_sensitive, 
	                   mmi_motion_dj_play_shake_trigger, NULL);


    /* RSK up leave screen */

    SetKeyHandler(mmi_motion_dj_play_key_0_press, KEY_0, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_0_release, KEY_0, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_1_press, KEY_1, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_1_release, KEY_1, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_2_press, KEY_2, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_2_release, KEY_2, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_3_press, KEY_3, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_3_release, KEY_3, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_4_press, KEY_4, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_4_release, KEY_4, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_5_press, KEY_5, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_5_release, KEY_5, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_6_press, KEY_6, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_6_release, KEY_6, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_7_press, KEY_7, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_7_release, KEY_7, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_8_press, KEY_8, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_8_release, KEY_8, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_9_press, KEY_9, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_9_release, KEY_9, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_star_press, KEY_STAR, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_star_release, KEY_STAR, KEY_EVENT_UP);
    SetKeyHandler(mmi_motion_dj_play_key_pound_press, KEY_POUND, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_play_key_pound_release, KEY_POUND, KEY_EVENT_UP);

#ifdef __MMI_TOUCH_SCREEN__
    wgui_register_pen_down_handler(mmi_motion_dj_pen_down_hdlr);
    wgui_register_pen_up_handler(mmi_motion_dj_pen_up_hdlr);
    wgui_register_pen_move_handler(mmi_motion_dj_pen_move_hdlr);
    SetKeyHandler(mmi_motion_dj_rsk_down_hdlr, KEY_RSK, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_rsk_up_hdlr, KEY_RSK, KEY_EVENT_UP);
#else
    SetKeyHandler(mmi_frm_scrn_close_active_id, KEY_RSK, KEY_EVENT_UP);
#endif /* __MMI_TOUCH_SCREEN__ */

#ifndef DJ_ENABLE_INDIVISUAL_VOLUME
    SetKeyHandler(mmi_motion_dj_volume_up, KEY_VOL_UP, KEY_EVENT_DOWN);
    SetKeyHandler(mmi_motion_dj_volume_down, KEY_VOL_DOWN, KEY_EVENT_DOWN);
#endif /* DJ_ENABLE_INDIVISUAL_VOLUME */ 

    for (i = 0; i < NUM_OF_DJ_KEY; i++)
    {
        g_dj_cntx.is_key_pressed[i] = FALSE;

        g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;
        g_dj_cntx.draw_state[i].is_key_sel = FALSE;
        g_dj_cntx.draw_state[i].is_text_sel = FALSE;
    }

    /* create layer */
    gdi_layer_get_base_handle(&g_dj_cntx.bg_layer);
    gdi_layer_clear(GDI_COLOR_BLACK);

    gdi_layer_create(0, 0, UI_device_width, UI_device_height, &g_dj_cntx.item_layer);
    gdi_layer_push_and_set_active(g_dj_cntx.item_layer);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();

    gdi_layer_set_blt_layer(g_dj_cntx.bg_layer, g_dj_cntx.item_layer, 0, 0);

    /* draw backgroud */
    gdi_layer_push_and_set_active(g_dj_cntx.bg_layer);
    gdi_anim_set_draw_after_callback(mmi_motion_dj_draw_after_draw_anim);
    gdi_image_draw_animation_id(0, 0, IMG_ID_MOTION_DJ_PLAY_BG, &g_dj_cntx.bg_anim);
    gdi_layer_pop_and_restore_active();

    /* draw items */
    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);

    ReadValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    if (g_dj_cntx.volume == 0xff)
    {
        g_dj_cntx.volume = LEVEL4;
        WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    }
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_dj_cntx.volume);
    
#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_register_volume_sync_callback(
        APP_GAMES, 
        MDI_AUD_VOL_LEVEL_NORMAL,
        mmi_motion_dj_hfp_volume_callback);
#endif
    
    /* start a bg midi which will always active DPS */
    g_dj_cntx.aud_bg_handle = mdi_audio_mma_open_string(0, (void*)motion_dj_aud_dummy_bg, DJ_AUD_DUMMY_BG_LEN, MDI_FORMAT_SMF, 0, NULL, NULL);

    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
    mdi_audio_mma_play(g_dj_cntx.aud_bg_handle);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        g_dj_cntx.aud_handle[i] = 0;

        if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            /* clear handle first */
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
#define DJ_OPEN_MIDI_CASE(__idx__)                                             \
            {                                                                              \
               case(__idx__):                                                              \
               {                                                                           \
                  if(g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)                   \
                  {                                                                        \
                     g_dj_cntx.aud_handle[i] =                                             \
                        mdi_audio_mma_open_string(0,                                       \
                                                (void*)motion_dj_instrument_midi_##__idx__,\
                                                (U32)DJ_AUD_INS_MIDI_##__idx__##_LEN,      \
                                                MDI_FORMAT_SMF,                            \
                                                0,                                         \
                                                NULL,                                      \
                                                NULL);                                     \
                  }                                                                        \
                  else                                                                     \
                  {                                                                        \
                     g_dj_cntx.aud_handle[i] =                                             \
                        mdi_audio_mma_open_string(0,                                       \
                                                (void*)motion_dj_instrument_midi_##__idx__,\
                                                (U32)DJ_AUD_INS_MIDI_##__idx__##_LEN,      \
                                                MDI_FORMAT_SMF,                            \
                                                1,                                         \
                                                NULL,                                      \
                                                NULL);                                     \
                  }                                                                        \
               }                                                                           \
               break;                                                                      \
            }

                switch (g_dj_cntx.event_list[i].audio_id)
                {
                        DJ_OPEN_MIDI_CASE(0);
                        DJ_OPEN_MIDI_CASE(1);
                        DJ_OPEN_MIDI_CASE(2);
                        DJ_OPEN_MIDI_CASE(3);
                        DJ_OPEN_MIDI_CASE(4);
                        DJ_OPEN_MIDI_CASE(5);
                        DJ_OPEN_MIDI_CASE(6);
                        DJ_OPEN_MIDI_CASE(7);
                        DJ_OPEN_MIDI_CASE(8);
                        DJ_OPEN_MIDI_CASE(9);
                }
            }

            /* start auto play */
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
            {
                mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                mdi_audio_mma_play(g_dj_cntx.aud_handle[i]);
            }

        }
        else
        {
            if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
            {
#define DJ_OPEN_WAVE_CASE(__idx__)                                       \
            {                                                                        \
               case(__idx__):                                                        \
               {                                                                     \
                  if(g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)             \
                  {                                                                  \
                     g_dj_cntx.aud_handle[i] =                                       \
                        mdi_audio_mma_open_string(0,                                 \
                                                (void*)motion_dj_vocal_wav_##__idx__,\
                                                (U32)DJ_AUD_VOX_WAVE_##__idx__##_LEN,\
                                                MDI_FORMAT_WAV,                      \
                                                0,                                   \
                                                NULL,                                \
                                                NULL);                               \
                  }                                                                  \
                  else                                                               \
                  {                                                                  \
                     g_dj_cntx.aud_handle[i] =                                       \
                        mdi_audio_mma_open_string(0,                                 \
                                                (void*)motion_dj_vocal_wav_##__idx__,\
                                                (U32)DJ_AUD_VOX_WAVE_##__idx__##_LEN,\
                                                MDI_FORMAT_WAV,                      \
                                                1,                                   \
                                                NULL,                                \
                                                NULL);                               \
                  }                                                                  \
               }                                                                     \
               break;                                                                \
            }

                switch (g_dj_cntx.event_list[i].audio_id)
                {
                        DJ_OPEN_WAVE_CASE(0);
                        DJ_OPEN_WAVE_CASE(1);
                        DJ_OPEN_WAVE_CASE(2);
                        DJ_OPEN_WAVE_CASE(3);
                        DJ_OPEN_WAVE_CASE(4);
                        DJ_OPEN_WAVE_CASE(5);
                        DJ_OPEN_WAVE_CASE(6);
                        DJ_OPEN_WAVE_CASE(7);
                        DJ_OPEN_WAVE_CASE(8);
                        DJ_OPEN_WAVE_CASE(9);
                }

                /* start auto play */
                if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
                {
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                    mdi_audio_mma_play(g_dj_cntx.aud_handle[i]);
                }
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_exit_play_scr
 * DESCRIPTION
 *  enter play screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_exit_play_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_cancel_timer(mmi_motion_dj_auto_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_0_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_1_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_2_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_3_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_4_icon_timeout);
    gui_cancel_timer(mmi_motion_dj_shake_5_icon_timeout);

    gdi_image_stop_animation(g_dj_cntx.bg_anim);

    /* disable motion sensor */
    if (g_dj_cntx.motion_handle >= 0)
    {
        srv_sensor_stop_listen(g_dj_cntx.motion_handle);
        g_dj_cntx.motion_handle = -1;
    }
    /* stop dummy background audio */
    mdi_audio_mma_stop(g_dj_cntx.aud_bg_handle);
    mdi_audio_mma_close(g_dj_cntx.aud_bg_handle);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.aud_handle[i] != 0)
        {
            if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
            {
                mdi_audio_mma_stop(g_dj_cntx.aud_handle[i]);
                mdi_audio_mma_close(g_dj_cntx.aud_handle[i]);
            }
            else
            {
                mdi_audio_mma_stop(g_dj_cntx.aud_handle[i]);
                mdi_audio_mma_close(g_dj_cntx.aud_handle[i]);
            }
        }
    }

    /* free layer */
    gdi_layer_free(g_dj_cntx.item_layer);
    gdi_layer_set_blt_layer(g_dj_cntx.bg_layer, 0, 0, 0);

    /* resume alignment timer */
    UI_enable_alignment_timers();

    /* let MMI can sleep */
    //TurnOffBacklight();

    /* enable multi-layer */
    gdi_layer_multi_layer_disable();

#ifdef __BT_SPK_VOL_CONTROL__
    mdi_audio_bt_clear_volume_sync_callback(APP_GAMES);
#endif

    /* resume background audio */
    mdi_audio_resume_background_play();

    /* re-enable keypad tone */
    mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);

    /* this will force title status to redraw */
    entry_full_screen();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_draw_items
 * DESCRIPTION
 *  draw items
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_draw_items(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 text_id;
    S32 i;
	S32 str_w;
    S32 str_h;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_active(g_dj_cntx.item_layer);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger != DJ_TRIGGER_NONE)
        {

            if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
            {
                text_id = STR_ID_MOTION_DJ_INSTRUMENT_0;
            }
            else
            {
                text_id = STR_ID_MOTION_DJ_VOCAL_0;
            }

            if (g_dj_cntx.draw_state[i].is_trigger_sel)
            {
                gdi_image_draw_id(
                    g_dj_draw_pos[i].icon_trigger_x,
                    g_dj_draw_pos[i].icon_trigger_y,
                    (U16) (IMG_ID_MOTION_DJ_PLAY_NONE_SEL + g_dj_cntx.event_list[i].trigger));
            }
            else
            {
                gdi_image_draw_id(
                    g_dj_draw_pos[i].icon_trigger_x,
                    g_dj_draw_pos[i].icon_trigger_y,
                    (U16) (IMG_ID_MOTION_DJ_PLAY_NONE + g_dj_cntx.event_list[i].trigger));

            }

            if (g_dj_cntx.event_list[i].key != DJ_KEY_NONE)
            {
                if (g_dj_cntx.draw_state[i].is_key_sel)
                {
                    gdi_image_draw_id(
                        g_dj_draw_pos[i].icon_key_x,
                        g_dj_draw_pos[i].icon_key_y,
                        (U16) (IMG_ID_MOTION_DJ_PLAY_KEY_0_SEL + g_dj_cntx.event_list[i].key - 1));
                }
                else
                {
                    gdi_image_draw_id(
                        g_dj_draw_pos[i].icon_key_x,
                        g_dj_draw_pos[i].icon_key_y,
                        (U16) (IMG_ID_MOTION_DJ_PLAY_KEY_0 + g_dj_cntx.event_list[i].key - 1));
                }
            }

        #if defined(__MMI_MAINLCD_320X480__)
            gui_set_font(&MMI_large_font);
        #else
            gui_set_font(&MMI_medium_font);
        #endif

			gui_measure_string((UI_string_type) GetString((U16) (text_id + g_dj_cntx.event_list[i].audio_id)), &str_w, &str_h);
			if (r2lMMIFlag == 1)
			{
				gui_move_text_cursor(g_dj_draw_pos[i].text_x + str_w, g_dj_draw_pos[i].text_y);
			}
			else
			{
                gui_move_text_cursor(g_dj_draw_pos[i].text_x, g_dj_draw_pos[i].text_y);
			}
            gui_set_text_color(DJ_FONT_COLOR);
            gui_set_text_border_color(DJ_FONT_BORDER_COLOR);
            gui_print_bordered_text((UI_string_type) GetString((U16) (text_id + g_dj_cntx.event_list[i].audio_id)));

        }
    }

#ifdef __MMI_TOUCH_SCREEN__
    if (g_dj_is_pen_down == MMI_TRUE)
    {
        gdi_image_draw_id(DJ_BACK_POS_X, DJ_BACK_POS_Y, (U16)IMG_ID_MOTION_DJ_PLAY_BACK_DOWN);
    }
    else
    {
        gdi_image_draw_id(DJ_BACK_POS_X, DJ_BACK_POS_Y, (U16)IMG_ID_MOTION_DJ_PLAY_BACK);
    }
#endif

    gdi_layer_pop_and_restore_active();

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_shake_trigger
 * DESCRIPTION
 *  shake trigger
 * PARAMETERS
 *  direct      the shake direction
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_shake_trigger(srv_sensor_type_enum sensor_type, void *sensor_data, 
                                         void *user_data)


{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;
    BOOL has_shake_key;
    BOOL has_shake_only;
    S32 shake_key_idx = 0;
    S32 shake_only_idx = 0;
    S32 idx = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* check if has shake event with key press */

    has_shake_key = FALSE;
    has_shake_only = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        /* has shake with key event */
        if ((g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE) &&
            (g_dj_cntx.event_list[i].key != DJ_KEY_NONE) &&
            (g_dj_cntx.is_key_pressed[g_dj_cntx.event_list[i].key] == TRUE))
        {
            has_shake_key = TRUE;
            shake_key_idx = i;
            break;
        }
        else if ((g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE) && (g_dj_cntx.event_list[i].key == DJ_KEY_NONE))
        {
            has_shake_only = TRUE;
            shake_only_idx = i;
        }
    }

    if (has_shake_key || has_shake_only)
    {
        if (has_shake_key)
        {
            idx = shake_key_idx;
        }
        else if (has_shake_only)
        {
            idx = shake_only_idx;
        }

        g_dj_cntx.draw_state[idx].is_trigger_sel = TRUE;

        switch (idx)
        {
            case 0:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_0_icon_timeout);
                break;

            case 1:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_1_icon_timeout);
                break;

            case 2:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_2_icon_timeout);
                break;

            case 3:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_3_icon_timeout);
                break;

            case 4:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_4_icon_timeout);
                break;

            case 5:
                gui_start_timer(DJ_ICON_FADE_TIME, mmi_motion_dj_shake_5_icon_timeout);
                break;
        }

        if (idx < DJ_NUM_OF_INSTRUMENT_ENTRY)
        {
            mdi_audio_mma_stop(g_dj_cntx.aud_handle[idx]);
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
            mdi_audio_mma_play(g_dj_cntx.aud_handle[idx]);
        }
        else
        {
            mdi_audio_mma_stop(g_dj_cntx.aud_handle[idx]);
            mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
            mdi_audio_mma_play(g_dj_cntx.aud_handle[idx]);
        }

        mmi_motion_dj_draw_items();
        gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
        return;
    }
}

/*****************************************************************************
* FUNCTION
*   mmi_motion_dj_auto_play_finish_hdlr()
* DESCRIPTION
*   key  press handler
* PARAMETERS
*   mdi_result IN    audio handle
*   result     IN    play result 
* RETURNS
*   void
* GLOBALS AFFECTED
*   nil
*****************************************************************************/
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
#endif /* 0 */ 


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_auto_icon_timeout
 * DESCRIPTION
 *  time out to darw small auto icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_auto_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* find the auto icon, draw unselect icon */

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_AUTO)
        {
            g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_0_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_0_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[0].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_1_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_1_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[1].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_2_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_2_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[2].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_3_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_3_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[3].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_4_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_4_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[4].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_shake_5_icon_timeout
 * DESCRIPTION
 *  time out to darw small shake icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_shake_5_icon_timeout(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.draw_state[5].is_trigger_sel = FALSE;

    mmi_motion_dj_draw_items();
    gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_key_press_handler
 * DESCRIPTION
 *  key  press handler
 * PARAMETERS
 *  key_id      [IN]        Key_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_key_press_handler(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.is_key_pressed[key_id] = TRUE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].key == key_id)
        {
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_PRESS)
            {
                g_dj_cntx.draw_state[i].is_trigger_sel = TRUE;
                g_dj_cntx.draw_state[i].is_key_sel = TRUE;

                if (i < DJ_NUM_OF_INSTRUMENT_ENTRY)
                {
                    mdi_audio_mma_stop(g_dj_cntx.aud_handle[i]);
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2); 
                    mdi_audio_mma_play(g_dj_cntx.aud_handle[i]);
                }
                else
                {
                    mdi_audio_mma_stop(g_dj_cntx.aud_handle[i]);
                    mdi_audio_set_headset_mode_output_path(MDI_DEVICE_SPEAKER2);
                    mdi_audio_mma_play(g_dj_cntx.aud_handle[i]);
                }
            }
            else if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE)
            {
                g_dj_cntx.draw_state[i].is_key_sel = TRUE;
            }

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_play_key_release_handler
 * DESCRIPTION
 *  key  release handler
 * PARAMETERS
 *  key_id      [IN]        Key_id
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_play_key_release_handler(U16 key_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_cntx.is_key_pressed[key_id] = FALSE;

    for (i = 0; i < DJ_NUM_OF_ALL_ENTRY; i++)
    {
        if (g_dj_cntx.event_list[i].key == key_id)
        {
            if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_PRESS)
            {
                g_dj_cntx.draw_state[i].is_trigger_sel = FALSE;
                g_dj_cntx.draw_state[i].is_key_sel = FALSE;
            }
            else if (g_dj_cntx.event_list[i].trigger == DJ_TRIGGER_SHAKE)
            {
                g_dj_cntx.draw_state[i].is_key_sel = FALSE;
            }

            mmi_motion_dj_draw_items();
            gdi_layer_blt_previous(0, 0, UI_device_width - 1, UI_device_height - 1);
            return;
        }
    }
}


#ifdef __MMI_TOUCH_SCREEN__
/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_pen_down_hdlr(mmi_pen_point_struct pos)    /* all done */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= DJ_BACK_POS_X && pos.y >= DJ_BACK_POS_Y)
    {
        g_dj_is_pen_down = MMI_TRUE;
        
    #ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
    #endif
        mmi_motion_dj_draw_items();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_pen_down_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_motion_dj_pen_up_hdlr(mmi_pen_point_struct pos)    /* all done */
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= DJ_BACK_POS_X && pos.y >= DJ_BACK_POS_Y)
    {
        mmi_frm_scrn_close_active_id();
    }
    else
    {
        g_dj_is_pen_down = MMI_FALSE;
        mmi_motion_dj_draw_items();
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (pos.x >= DJ_BACK_POS_X && pos.y >= DJ_BACK_POS_Y)
    {
        g_dj_is_pen_down = MMI_TRUE;
        mmi_motion_dj_draw_items();
    }
    else
    {
        g_dj_is_pen_down = MMI_FALSE;
        mmi_motion_dj_draw_items();
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_rsk_down_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_dj_is_pen_down = MMI_TRUE;
    mmi_motion_dj_draw_items();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  pos         [IN]        
 *  S16(?)      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_rsk_up_hdlr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dj_is_pen_down)
    {
        mmi_frm_scrn_close_active_id();
        g_dj_is_pen_down = MMI_FALSE;
    }
}
#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_volume_up
 * DESCRIPTION
 *  Set game volume up
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_volume_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dj_cntx.volume < LEVEL7)
    {
        g_dj_cntx.volume++;
        WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    }

    mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_dj_cntx.volume);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_volume_down
 * DESCRIPTION
 *  Set game volume down
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_volume_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_dj_cntx.volume > LEVEL1)
    {
        g_dj_cntx.volume--;
        WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
    }

    mdi_audio_set_volume(MDI_VOLUME_MEDIA, g_dj_cntx.volume);
}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_hfp_volume_callback
 * DESCRIPTION
 *  entry sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
static MMI_BOOL mmi_motion_dj_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (volume < MAX_VOL_LEVEL && is_mute == MMI_FALSE)
    {
        if(GetActiveScreenId() == SCR_ID_MOTION_DJ_PLAY)
        {
            g_dj_cntx.volume = volume;
            WriteValue(NVRAM_MOTION_DJ_VOLUMN, &g_dj_cntx.volume, DS_BYTE, &error);
            mdi_audio_set_volume(VOL_TYPE_MEDIA, volume);
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}
#endif /* __BT_SPK_VOL_CONTROL__ */


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_hfp_volume_callback
 * DESCRIPTION
 *  entry sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * BOOL
 *****************************************************************************/
S32 mmi_motion_dj_get_string_width(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (LCD_WIDTH - g_dj_draw_pos[0].text_x);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_motion_dj_draw_after_draw_anim
 * DESCRIPTION
 *  Draw item after draw background
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_motion_dj_draw_after_draw_anim(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_motion_dj_draw_items();
}


static MMI_ID mmi_motion_dj_display_popup(mmi_id gid, UI_string_type string, mmi_event_notify_enum type, S32 user_data)
{
    MMI_ID result;
    mmi_group_node_struct node_info;
    mmi_popup_property_struct property;

    mmi_frm_group_get_info (gid, &node_info);
    mmi_popup_property_init(&property);
    
    property.user_tag = (void*)user_data;
    property.parent_id = gid;
    property.callback = (mmi_proc_func)node_info.proc;
    
    result = mmi_popup_display(string, type, &property);

    return result;
}


#define DJ_KEY_HANDLER(__key__,__KEY__)                        \
   static void mmi_motion_dj_play_key_##__key__##_press(void)  \
   {                                                           \
      mmi_motion_dj_play_key_press_handler(DJ_KEY_##__KEY__);  \
   }                                                           \
   static void mmi_motion_dj_play_key_##__key__##_release(void)\
   {                                                           \
      mmi_motion_dj_play_key_release_handler(DJ_KEY_##__KEY__);\
   }

DJ_KEY_HANDLER(0, 0)
DJ_KEY_HANDLER(1, 1)
DJ_KEY_HANDLER(2, 2)
DJ_KEY_HANDLER(3, 3)
DJ_KEY_HANDLER(4, 4)
DJ_KEY_HANDLER(5, 5)
DJ_KEY_HANDLER(6, 6)
DJ_KEY_HANDLER(7, 7) DJ_KEY_HANDLER(8, 8) DJ_KEY_HANDLER(9, 9) DJ_KEY_HANDLER(star, STAR) DJ_KEY_HANDLER(pound, POUND)
#endif /* IS_DJ_BASE_MOTIONGAME */ 
#endif /* _MMI_MOTION_DJ_C */ 

