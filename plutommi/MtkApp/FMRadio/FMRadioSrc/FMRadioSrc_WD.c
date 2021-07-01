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
*  FMRadioSrc_WD.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   FM Radio view related functions
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
 * removed!
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
 * removed!
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_FM_RADIO__

#ifdef __MMI_WEARABLE_DEVICE__
#include "wgui_touch_screen.h"
#include "BTMMISCOPathGprots.h"
#include "gui_typedef.h"

#include "aud_defs.h"
#include "mdi_datatype.h"
#include "mdi_audio.h"
#include "mdi_include.h"
#include "Device.h"
#include "kal_non_specific_general_types.h"
#include "gui_data_types.h"
#include "gui_virtual_keyboard_language_type.h"
#include "wgui_inline_edit.h"
#include "CustDataRes.h"
#include "GlobalResDef.h"
#include "Unicodexdcl.h"
#include "kal_release.h"
#include "string.h"
#include "DebugInitDef_Int.h"
#include "nvram_common_defs.h"
#include "mmi_rp_app_fmrdo_def.h"
#include "mmi_frm_nvram_gprot.h"
#include "gui_typedef.h"
#include "wgui_categories_util.h"
#include "AlertScreen.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_scenario_gprot.h"
#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_input_gprot.h"
#include "GlobalConstants.h"
#include "custom_mmi_default_value.h"
#include "fs_func.h"
#include "fs_type.h"
#include "fs_errcode.h"
#include "mmi_res_range_def.h"
#include "mmi_frm_history_gprot.h"
#include "gdi_const.h"
#include "wgui.h"
#include "gui_effect_oem.h"
#include "gui.h"
#include "wgui_categories_list.h"
#include "wgui_categories.h"
#include "ImeGprot.h"
#include "CommonScreensResDef.h"
#include "wgui_categories_popup.h"
#include "custom_events_notify.h"
#include "mmi_rp_file_type_def.h"
#include "FileMgrType.h"
#include "gui_touch_feedback.h"
#include "FMRadioDef.h"
#include "FMRadioType.h"
#include "FMRadioProt.h"
#include "FMRadioMainScreen.h"
#include "GpiosrvGprot.h"
#ifdef __MMI_TOUCH_SCREEN__
#include "gui_virtual_keyboard.h"
#endif
#ifdef __DM_LAWMO_SUPPORT__
#include "Dmuigprot.h"
#endif
#include "AlarmGprot.h"

#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif

#include "MMIDataType.h"

#ifdef __MMI_BACKGROUND_CALL__
#include "UcmSrvGprot.h"
#endif 

#include "UcmGProt.h"
#include "IdleGprot.h"
#include "menucuigprot.h"
#include "inlinecuigprot.h"
#include "fseditorcuigprot.h"

#ifdef __MMI_FILE_MANAGER__
#include "filemgrcuigprot.h"
#endif 

#include "mmi_rp_srv_prof_def.h"
#include "ShutdownSrvGprot.h"
#ifdef __MMI_NCENTER_SUPPORT__
#include "vsrv_ncenter.h"
#endif

#ifdef __MMI_FM_VIA_A2DP__
#include "av_bt.h"
#include "BTMMIA2DPScr.h"
#endif

#ifdef __MMI_BT_FM_VIA_SCO__
#include "BthScoPathSrvGProt.h"
#endif

#ifdef __MMI_AVRCP_SUPPORT__
#include "BtcmSrvGprot.h"
#include "BTMMIAVRCPGProt.h"
#endif /* __MMI_AVRCP_SUPPORT__ */

#ifdef __MMI_MAINLCD_96X64__
#include "VolumeHandler.h"
#include "mmi_rp_app_profiles_def.h"
#endif

static void mmi_fmrdo_channel_option_LSK(mmi_menu_id highlight_item);

#ifdef __MMI_AVRCP_SUPPORT__
U8 mmi_fmrdo_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events);
static void mmi_fmrdo_press_button_canceled(void);
#endif

mmi_fmrdo_struct g_fmrdo;   /* all memeber variables are zero initial */

static U16 channel_list_highlighted_item_index;
static UI_character_type channel_name_str[MAX_NAME_INPUT_LEN + 10];     /* used for showing channel_name or freq in idle screen or subLCD */
#ifndef __MMI_FM_PLUTO_SLIM__
#if !(defined(__MMI_VUI_HOMESCREEN_FM_RADIO__) || defined(__MMI_VUI_LAUNCHER_KEY__))
static S32 selected_background_play;
#endif 
static S32 selected_skin_index;
#endif /*__MMI_FM_PLUTO_SLIM__*/

#if defined(__MMI_FM_RADIO_LOUD_SPEAK__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)
static S32 selected_speaker_status;
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 

#if defined(__MMI_FM_RADIO_MONO__)
static S32 selected_channel_mono;
#endif /* defined(__MMI_FM_RADIO_MONO__) */ 

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
extern void(*mmi_fmrdo_preempted_cb_fptr)(void*, U32);
extern void* mmi_fmrdo_widget_userdata;
#endif


#ifdef __MMI_FM_VIA_A2DP__
extern mmi_fmrdo_a2dp_struct a2dp_info;	
extern MMI_BOOL fm_a2dp_connected;
#endif

extern const mmi_fmrdo_skin_struct g_fmrdo_skins[]; /* defined in resource_fmradio_skins.c */
#ifdef __MMI_FTE_SUPPORT__
extern U8 g_vol_displayed;
#endif

extern void kal_wsprintf(unsigned short *outstr, char *fmt, ...);
extern void kal_get_time(kal_uint32 *ticks_ptr);
void mdi_fmr_set_output_path(U8 path);

#ifdef __TC01__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__TC01__*/
#ifdef __MMI_FTE_SUPPORT__
MMI_BOOL g_fmrdo_search_freq_changed = MMI_FALSE;
#endif
#if defined(__MMI_FM_RADIO_RECORD__) && defined(__MMI_FTE_SUPPORT__)
extern U8 animate_count;
#endif

#ifdef __MTK_TARGET__
extern kal_bool FMR_IsChipValid(void);  /* this function is definedin in l1audio */
#endif
S32 g_fmrdo_menu_item_index;
extern GDI_HANDLE fmrdo_btn_down_layer;

#ifdef __MMI_AVRCP_SUPPORT__
MMI_BOOL g_avrcp_is_btn_pressed = MMI_FALSE;
U8 g_avrcp_btn = 0;
#endif

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_skip_highlight_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  index       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_skip_highlight_hdlr(S32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo_menu_item_index >= 0 && index >= g_fmrdo_menu_item_index)
	{
		index++;
	}
	ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_check_chip_or_hide
* DESCRIPTION
*  
* PARAMETERS
*  n_items         [IN]        Number of string IDs
*  string_ids      [IN]        String ID's
*  icon_ids        [IN]        Icon ID's
* RETURNS
*  U16
*****************************************************************************/
U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
	if (!FMR_IsChipValid())
	{
		/* hide FM Radio application menu item */
		S16 i, j;

		for (i = n_items - 1; i >= 0; i--)
		{
			if (string_ids[i] == STR_ID_FMRDO_TITLE)    /* look for FM Radio application string id */
			{
				break;
			}
		}
		g_fmrdo_menu_item_index = i;
		if (i >= 0) /* found FM Radio application string id */
		{
			n_items--;
			for (j = i; j < n_items; j++)   /* move rest application string & image ids up */
			{
				string_ids[j] = string_ids[j + 1];
				icon_ids[j] = icon_ids[j + 1];
			}
		}
	}
	else
#endif
	{
		g_fmrdo_menu_item_index = -1;
	}
	return n_items;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_power_on_main_screen
* DESCRIPTION
*  
* PARAMETERS
*  turn_on     [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_power_on_main_screen(BOOL turn_on)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	if (g_fmrdo.in_main_screen)
#endif
	{
		mmi_fmrdo_power_on_check(turn_on);
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_is_power_on
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
* BOOL
*****************************************************************************/
BOOL mmi_fmrdo_is_power_on(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP,MMI_FMRDO_TRC_IS_FM_POWER_ON,(g_fmrdo.is_ready && g_fmrdo.is_power_on));
	return (g_fmrdo.is_ready && g_fmrdo.is_power_on);
}

mmi_ret mmi_fmrdo_is_power_on_callback_hdlr(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch(event->evt_id)
	{
	case EVT_ID_SRV_PROF_IS_PLAYING:
		{
			if(g_fmrdo.is_ready && g_fmrdo.is_power_on)
			{
				return MMI_TRUE;
			}
			else
			{
				return MMI_FALSE;
			}
		}
	}
	return MMI_RET_OK;       
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_get_channel_name_or_freq
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  UI_string_type
*****************************************************************************/
UI_string_type mmi_fmrdo_get_channel_name_or_freq(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	UI_string_type str = channel_name_str;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	kal_wsprintf(str, "FM %d.%d", g_fmrdo.frequency / 10, g_fmrdo.frequency % 10);

	return str;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_set_volume
* DESCRIPTION
*  
* PARAMETERS
*  volume      [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_set_volume(U8 volume)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_UNIQUE_MEDIA_VOL__
	srv_prof_set_current_profile_value(SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL, (void *)&g_fmrdo.volume);
#endif /*__MMI_UNIQUE_MEDIA_VOL__ */

	if (g_fmrdo.is_ready && g_fmrdo.is_power_on/* && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE &&
											   g_fmrdo.state != FMRDO_STATE_SEARCH_ALL*/)
	{
		mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(volume));
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_preset_list_done
* DESCRIPTION
*  
* PARAMETERS
*  signal_band     [IN/OUT]     Pointer to first channel in sub band
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_preset_list_done(U8 *signal_band)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 i, j;
	MMI_BOOL found_first_channel_flag = MMI_FALSE;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_PRESET_LIST_DONE, -1);

	/* clear channel list */
	memset(&g_fmrdo.channel_list, 0, sizeof(mmi_fmrdo_channel_list_struct));

#ifdef WIN32
	{
		g_fmrdo.channel_list.freq[0] = 911;
		g_fmrdo.channel_list.freq[1] = 927;
		g_fmrdo.channel_list.freq[2] = 935;
		g_fmrdo.channel_list.freq[3] = 946;
		g_fmrdo.channel_list.freq[4] = 983;
		g_fmrdo.channel_list.freq[5] = 1026;
		g_fmrdo.channel_list.freq[6] = 1079;
		g_fmrdo.frequency = g_fmrdo.channel_list.freq[0]; 
	}
#else /* WIN32 */
	/* set channel list */
	for (i = j = 0; i < FM_BANDWIDTH; i++)
	{
		if (FM_SIG_MARK(signal_band[i]))
		{
			if(!found_first_channel_flag)
			{
				g_fmrdo.frequency = MIN_FM_FREQUENCY + i; 
				found_first_channel_flag = MMI_TRUE;
			}
			mmi_fmrdo_set_channel(
				j++,
				(U16) (i + MIN_FM_FREQUENCY),
				NULL);

			if (j >= FM_RADIO_CHANNEL_NUM)
			{
				break;  /* this line should never be reached if the searching algorithm is correct!! */
			}
		}
	}
#endif /* WIN32 */
	/* write channel list from nvram */
	WriteRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);

	/* rematch channel index */
	g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);

	if(g_fmrdo.channel_index == -1 && g_fmrdo.state != FMRDO_STATE_SEARCH_ALL_STOPPED)
	{
		mmi_popup_display_simple_ext(STR_ID_FMRDO_NO_CHANNEL_FOUND,
			MMI_EVENT_FAILURE,
			GRP_ID_FMRDO, 
			NULL);
	}

	g_fmrdo.state = FMRDO_STATE_READY;

#ifdef __MMI_FM_VIA_A2DP__
	if(mmi_a2dp_is_output_to_bt())
	{
		g_fmrdo.loud_speaker_on = 0;
	}
	else
	{
		g_fmrdo.loud_speaker_on = 1;
	}
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	if (!g_fmrdo.loud_speaker_on)
	{
#endif	/* __MMI_FM_RADIO_LOUD_SPEAK__ */
		srv_a2dp_set_app_callback(mmi_fmrdo_bt_open_callback);

		if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
		{
			g_fmrdo.state = FMRDO_STATE_BT_CONNECTING;
            srv_a2dp_open_source(mmi_a2dp_get_bt_headset(), MMI_TRUE);
//			av_bt_open_ex((srv_bt_cm_bt_addr *)mmi_a2dp_get_bt_headset(),a2dp_info.sample_rate,a2dp_info.is_stereo,
//								mmi_fmrdo_bt_open_callback,KAL_TRUE);
		}
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	}
	else
	{
		if (g_fmrdo.is_power_on)
		{
			if (g_fmrdo.volume)
			{
				mmi_fmrdo_set_volume(g_fmrdo.volume);
			}
			else
			{
				mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			}  
		}
	}
#endif	/* __MMI_FM_RADIO_LOUD_SPEAK__ */
#endif /* __MMI_FM_VIA_A2DP__ */
	mmi_idle_update_service_area();

#ifdef __MMI_VUI_HOMESCREEN_FM_RADIO__
	if (mmi_fmrdo_preempted_cb_fptr)
	{
		mmi_fmrdo_preempted_cb_fptr(mmi_fmrdo_widget_userdata, 0);
	}
#endif /* __MMI_VUI_HOMESCREEN_FM_RADIO__ */

	if(mmi_frm_scrn_get_active_id() == SCR_ID_FMRDO_CHANNEL_LIST)
	{
		wgui_cat1032_refresh_list(mmi_fmrdo_get_channel_count() + 1, 0, mmi_fmrdo_channel_list_item_ext, NULL);
	}
	if(mmi_fmrdo_is_channel_list_empty())
	{
		mmi_fmrdo_power_on_check(MMI_FALSE);
	}
	if(g_fmrdo.confirm_id)
	{
		mmi_frm_scrn_close(g_fmrdo.confirm_id, g_fmrdo.confirm_id);
		g_fmrdo.confirm_id = 0;
	}
	if(g_fmrdo.in_main_screen)
	{
		mmi_fmrdo_redraw_main_all();
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_get_freq_from_str
* DESCRIPTION
*  
* PARAMETERS
*  input_str       [IN]        
* RETURNS
*  U16
*****************************************************************************/
U16 mmi_fmrdo_get_freq_from_str(UI_string_type input_str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U16 freq = 0;
	BOOL fraction = FALSE;
	BOOL skip = FALSE;
	BOOL one_digit_dicimal = TRUE;
	S16 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (i = 0; input_str[i] != 0; i++)
	{
		if (input_str[i] == L'.')
		{
			if ((input_str[i + 1] != 0) && (input_str[i + 2] != 0))
			{
				one_digit_dicimal = FALSE;
			}
			fraction = TRUE;
		}
		else if (!skip)
		{
			freq = freq * 10 + input_str[i] - L'0';
			if (fraction)
			{
				skip = TRUE;
			}
		}
	}

	if (freq != 0 && !skip)
	{
		freq *= 10;
	}

	if (!one_digit_dicimal)
	{
		freq = 0xffff;  /* Only allow one digit after the '.' */
	}

	return freq;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_set_channel
* DESCRIPTION
*  
* PARAMETERS
*  channel_index       [IN]        
*  freq                [IN]        
*  name                [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_set_channel(S16 channel_index, U16 freq, UI_string_type name)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_fmrdo.channel_list.freq[channel_index] = freq;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_get_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_fmrdo_get_volume(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_UNIQUE_MEDIA_VOL__
	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL, (void *)&g_fmrdo.volume);
	g_fmrdo.volume &= 0xBF; /* to convert volume level back */
#endif /*__MMI_UNIQUE_MEDIA_VOL__ */

	return g_fmrdo.volume;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_inc_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_inc_volume(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.in_main_screen)
	{
		if (!g_fmrdo.volume)
		{
			mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_FALSE);
		}
		if (g_fmrdo.volume < FMRDO_MAX_VOL_LEVEL - 1)
		{
			mmi_fmrdo_set_volume(++g_fmrdo.volume);
		}
		else
		{
			mmi_fmrdo_set_volume(g_fmrdo.volume);   
		}
		mmi_fmrdo_redraw_main_volume();
	}

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_dec_volume
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_dec_volume(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.in_main_screen)
	{
		if (g_fmrdo.volume == 0 || g_fmrdo.volume == 1)
		{
			mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
		}
		if (g_fmrdo.volume > 0)
		{
			mmi_fmrdo_set_volume(--g_fmrdo.volume);
		}
		else
		{
			mmi_fmrdo_set_volume(g_fmrdo.volume);	
		}
		mmi_fmrdo_redraw_main_volume();
	}

}


#ifdef __BT_SPK_VOL_CONTROL__
/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_hfp_volume_callback
* DESCRIPTION
*  callback function of HFP volume, not support mute
* PARAMETERS
*  volume      [IN]        Volume want to set to FM by HFP
*  is_mute     [IN]        FM not support mute
* RETURNS
*  MMI_TRUE    Set volume to FM & redraw OK
*  MMI_FALSE   FM not handle the action
*****************************************************************************/
MMI_BOOL mmi_fmrdo_hfp_volume_callback(U8 volume, MMI_BOOL is_mute)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (volume < FMRDO_MAX_VOL_LEVEL && is_mute == MMI_FALSE)
	{
		if (g_fmrdo.is_power_on && g_fmrdo.state != FMRDO_STATE_SEARCH_ALL && g_fmrdo.state != FMRDO_STATE_SEARCH_ONE)
		{
			g_fmrdo.volume = volume;
			if (g_fmrdo.volume == 0)
			{
				mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
			}
			else
			{
				mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_FALSE);
				mmi_fmrdo_set_volume(volume);
			}
			if (g_fmrdo.in_main_screen)
			{
				// TODO: added latest
				mmi_fmrdo_redraw_main_volume();
			}
			return MMI_TRUE;
		}
		else if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
		{
			return MMI_TRUE;
		}
	}
	return MMI_FALSE;
}
#endif /* __BT_SPK_VOL_CONTROL__ */ 
#ifdef __DM_LAWMO_SUPPORT__


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_lawmo_lock_notify_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
//ry:LAWMO
mmi_ret mmi_fmrdo_lawmo_lock_notify_hdlr(mmi_event_struct *evt )
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	srv_dm_lawmo_lock_ind_evt_struct *lawmo_lock_ind = (srv_dm_lawmo_lock_ind_evt_struct*)evt;

	switch (lawmo_lock_ind->cmd)
	{
	case MMI_DMUI_CMD_LAWMO_PARTIALLYLOCK:
#ifdef __MTK_TARGET__
		if (FMR_IsChipValid())
#endif
		{
			mmi_fmrdo_power_on_check(FALSE);
		}
		(*lawmo_lock_ind->cb)(MMI_TRUE, "FMRadio");
		break;

	case MMI_DMUI_CMD_LAWMO_UNLOCK:
		(*lawmo_lock_ind->cb)(MMI_TRUE, "FMRadio");
		break;

	default:
		break;
	}
	return MMI_RET_OK;
}

#endif/*__DM_LAWMO_SUPPORT__*/


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_a2dp_connect_callback_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#if defined(__MMI_A2DP_SUPPORT__) && defined(__BT_SPEAKER_SUPPORT__)
void mmi_fmrdo_a2dp_connect_callback_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	if (mmi_frm_group_get_state(GRP_ID_FMRDO) != MMI_SCENARIO_STATE_NONE)
	{
		mmi_frm_group_close(GRP_ID_FMRDO);
	}        
}
#endif /*defined(__MMI_A2DP_SUPPORT__) && (__BT_SPEAKER_SUPPORT__)*/


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_earphone_check_invalid_and_popup
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_BOOL mmi_fmrdo_earphone_check_invalid_and_popup(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
	if (!srv_earphone_is_plug_in())
	{
		mmi_popup_display_simple_ext(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE,
			MMI_EVENT_INFO,
			GRP_ID_FMRDO, 
			NULL);
		return MMI_TRUE;
	}
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */
	return MMI_FALSE;
}

#ifdef __MMI_FILE_MANAGER__ 
/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_earphone_check_invalid_and_popup
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_fmgr_error_popup(S32 fs_error)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_popup_display_simple_ext(
		srv_fmgr_fs_error_get_string(fs_error),
		(mmi_event_notify_enum)srv_fmgr_fs_error_get_popup_type(fs_error),
		GRP_ID_FMRDO,
		NULL);
}
#endif

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_init_app
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_init_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MTK_TARGET__
	if (FMR_IsChipValid())
	{
		//    #ifdef __DM_LAWMO_SUPPORT__
		//        mmi_dmui_lawmo_register_notify(MMI_DMUI_APP_ID_FMRDO,MMI_DMUI_MO_TYPE_LAWMO_LOCK,(mmi_dmui_lawmo_cb)mmi_fmrdo_phone_lock_hdlr);
		//    #endif /* __DM_LAWMO_SUPPORT__ */
#ifdef __TC01__
/* under construction !*/
#endif/*__TC01__*/
	}
#endif /* __MTK_TARGET__ */
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_init_nvram
* DESCRIPTION
*  Read channel list and FM settings from NVRAM
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_init_nvram(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/* read channel list from nvram */
	ReadRecordSlim(NVRAM_EF_FM_RADIO_LID, 1, (void*)&g_fmrdo.channel_list, NVRAM_EF_FM_RADIO_SIZE);

	/* read settings from nvram */
	g_fmrdo.is_background_play = 1;
#ifdef __MMI_UNIQUE_MEDIA_VOL__
	srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL, (void *)&g_fmrdo.volume);
	g_fmrdo.volume &= 0xBF; /* to convert volume level back */
	if (g_fmrdo.volume == 0)
	{
		mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
	}
#endif /* __MMI_UNIQUE_MEDIA_VOL__ */

	g_fmrdo.skin_index = 0; /* only 1 skin in silm skin version */

#if defined(__MMI_FM_RADIO_MONO__)
	ReadValueSlim(NVRAM_FMRDO_CHANNEL_MONO, &g_fmrdo.mono, DS_BYTE);
	if (g_fmrdo.mono != 0 && g_fmrdo.mono != 1)
	{
		g_fmrdo.mono = 0;
		WriteValueSlim(NVRAM_FMRDO_CHANNEL_MONO, &g_fmrdo.mono, DS_BYTE);
	}
#endif /* defined(__MMI_FM_RADIO_MONO__) */ 
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
	g_fmrdo.loud_speaker_on = 1;
#endif /* defined(__MMI_FM_RADIO_LOUD_SPEAK__) */ 

	ReadValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);
	/* default frequency value */
	if (g_fmrdo.frequency > MAX_FM_FREQUENCY || g_fmrdo.frequency < MIN_FM_FREQUENCY)
	{
		if(g_fmrdo.channel_list.freq[0])
		{
			/* Reset last frequency to first channel in channel list */
			g_fmrdo.frequency = g_fmrdo.channel_list.freq[0];
		}
		else
		{
		g_fmrdo.frequency = 0;
	}
	}

	/* reset channel index */
	g_fmrdo.channel_index = mmi_fmrdo_match_channel_list(g_fmrdo.frequency);

	/* search & power states */
	g_fmrdo.is_search_on = FALSE;
	g_fmrdo.is_power_on = FALSE;

	/* mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued); */

	g_fmrdo.is_ready = TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_main_scrn_proc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_main_scrn_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifdef __MMI_MAINLCD_96X64__
	mmi_frm_key_evt_struct *p_key = (mmi_frm_key_evt_struct*)param;
#endif

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (param->evt_id)
	{
	case EVT_ID_SCRN_ACTIVE:
		mmi_fmrdo_entry_main();
		break;
	case EVT_ID_SCRN_INACTIVE:
		mmi_fmrdo_exit_main();
		break;

	case EVT_ID_SCRN_DEINIT:
		mmi_fmrdo_exit_root(param);
		break;
	case EVT_ID_SRV_SHUTDOWN_DEINIT:
		mmi_fmrdo_exit_root(param);
		break;	

	default:
		break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_main_scrn_proc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_channel_scrn_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (param->evt_id)
	{
	case EVT_ID_SCRN_ACTIVE:
		mmi_fmrdo_entry_channel_list(param);
		break;

	case EVT_ID_SCRN_HIGHLIGHT_CHANGE:
		{
			cat_evt_struct *evt = (cat_evt_struct *)param;
			channel_list_highlighted_item_index = (U16)evt->item_index;
			return MMI_RET_CHANGED;
		}

	default:
		break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_search_scrn_proc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_search_scrn_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	switch (param->evt_id)
	{
	case EVT_ID_SCRN_ACTIVE:
		mmi_fmrdo_entry_searching();
		break;

	case EVT_ID_WGUI_RSK_CLICK:
		mmi_fmrdo_search_all_channels_stop();
		return MMI_RET_KEY_HANDLED;

	default:
		break;
	}
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_medply_fte_proc
* DESCRIPTION
*  Screen group callback process
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_app_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	cui_menu_event_struct *menu_evt;
	mmi_group_event_struct *group_evt;
	U32 menu_level;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	/* Screen group event */
	switch(evt->evt_id)
	{
	case EVT_ID_GROUP_DEINIT: // framework de-init the group
		break;

	case EVT_ID_SCRN_INACTIVE:
		break;

	default:
		break;
	}
	return MMI_RET_OK;
}

#if (defined(__MMI_BT_DIALER_SUPPORT__) || defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__))
/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_bt_music_disconnect_callback
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_fmrdo_bt_music_disconnect_callback(MMI_BOOL result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (result)
	{
		mmi_fmrdo_run_app();
	}
}
#endif /* __MMI_BT_DIALER_SUPPORT__ */


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_run_app
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_run_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#if (defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__))
	if (mmi_bt_music_check_connection())
	{
		mmi_bt_music_disconnect(mmi_fmrdo_bt_music_disconnect_callback);
		//return;
	}
#endif

	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_DISABLED);

	if(!g_fmrdo.is_power_on && mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_FMR)< 0 )
	{
		mdi_audio_suspend_background_play();
	}
	if (!g_fmrdo.is_ready)
	{
		mmi_fmrdo_init_nvram();
	}

#ifdef __BT_SPK_VOL_CONTROL__
	mdi_audio_bt_register_volume_sync_callback(APP_FMRDO, MDI_AUD_VOL_LEVEL_NORMAL/*7 level volume*/, mmi_fmrdo_hfp_volume_callback);
#endif /* __BT_SPK_VOL_CONTROL__ */ 

#ifdef __MMI_FM_VIA_A2DP__
	mdi_fmr_get_audio_info((mdi_fmr_audio_info_struct *)&a2dp_info);
#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_set_cmd_hdlr();
#endif 

	mmi_frm_group_create_ex(GRP_ID_ROOT, 
		GRP_ID_FMRDO,
		mmi_fmrdo_app_proc,
		NULL,
		MMI_FRM_NODE_SMART_CLOSE_FLAG);

	/* power on */
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
	if (srv_earphone_is_plug_in())
#endif 
#ifdef __MMI_BACKGROUND_CALL__
		if (!srv_ucm_is_background_call())
#endif 
		{
			//mmi_fmrdo_search_all_channels_stop();
			//mmi_fmrdo_power_on_check(TRUE);
			//mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL);
		}
		mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_MAIN, mmi_fmrdo_main_scrn_proc, NULL);

#ifdef __MMI_BACKGROUND_CALL__
		if (srv_ucm_is_background_call())
		{
			mmi_ucm_app_entry_error_message();
			return;
		}
#endif /* __MMI_BACKGROUND_CALL__ */ 
		mmi_fmrdo_earphone_check_invalid_and_popup();

}

#if defined(__MMI_APP_MANAGER_SUPPORT__)
/*****************************************************************************
* FUNCTION
*  mmi_fmrado_launch
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
MMI_ID mmi_fmrado_launch(void* param, U32 param_size)
{
	mmi_fmrdo_run_app();
	return GRP_ID_FMRDO;
}
#endif /* __MMI_APP_MANAGER_SUPPORT__ */

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_highlight_menu
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_highlight_menu(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	ChangeLeftSoftkey(STR_GLOBAL_OK, 0);
	ChangeRightSoftkey(STR_GLOBAL_BACK, 0);

	SetLeftSoftkeyFunction(mmi_fmrdo_run_app, KEY_EVENT_UP);
	SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
	SetCenterSoftkeyFunction(mmi_fmrdo_run_app, KEY_EVENT_UP);
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_match_channel_list
* DESCRIPTION
*  
* PARAMETERS
*  frequency       [IN]        
* RETURNS
*  S16
*****************************************************************************/
S16 mmi_fmrdo_match_channel_list(U16 frequency)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 i;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* try matching current frequency first */
	for (i = 0; i < FM_RADIO_CHANNEL_NUM && frequency; i++)
	{
		if (g_fmrdo.channel_list.freq[i] == frequency)
		{
			return i;
		}
	}

	return -1;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_volume_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_volume_up(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_fmrdo.selected_button = FMRDO_BUTTON_VOL_UP;
	g_fmrdo.is_button_down = TRUE;
	mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_volume_down(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_fmrdo.selected_button = FMRDO_BUTTON_VOL_DOWN;
	g_fmrdo.is_button_down = TRUE;
	mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_volume_up
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_volume_up(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_fmrdo.selected_button == FMRDO_BUTTON_VOL_UP)
	{
		g_fmrdo.is_button_down = FALSE;
		mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_VOL_UP, FALSE);
		if (g_fmrdo.is_power_on)
		{
			mmi_fmrdo_inc_volume();
		}
		g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_volume_down
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_volume_down(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_fmrdo.selected_button == FMRDO_BUTTON_VOL_DOWN)
	{
		g_fmrdo.is_button_down = FALSE;
		mmi_fmrdo_redraw_main_push_button(FMRDO_BUTTON_VOL_DOWN, FALSE);
		if (g_fmrdo.is_power_on)
		{
			mmi_fmrdo_dec_volume();
		}
		g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_title_area
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_title_area(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_fmrdo.selected_button = FMRDO_BUTTON_TITLE;
	g_fmrdo.is_button_down = TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_title_area
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_title_area(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_TITLE)
	{
		mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST, mmi_fmrdo_channel_scrn_proc, NULL);
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_memo_up_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_memo_up_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.is_button_down)
	{
		return;
	}

	g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_UP;
	g_fmrdo.is_button_down = TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

	mmi_fmrdo_search_frequency_stop();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_memo_down_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_memo_down_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.is_button_down)
	{
		return;
	}
	g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_DOWN;
	g_fmrdo.is_button_down = TRUE;

#ifndef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
	mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

	mmi_fmrdo_search_frequency_stop();
#endif
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_memo_up_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_memo_up_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if ((g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_UP) || (g_avrcp_is_btn_pressed && (g_avrcp_btn == MMI_AVRCP_POP_FORWARD || g_avrcp_btn == SRV_AVRCP_POP_FAST_FORWARD)))
	{
		g_fmrdo.is_button_down = FALSE;
		if (mmi_fmrdo_is_channel_list_empty())
		{
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
			return;
		}
		if(g_avrcp_is_btn_pressed)
		{
			g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_UP;	
		}
		mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

		if(is_freq_changed)
		{
			g_fmrdo.normal_repeat_step_count = 0;
		}
		else
		{
			mmi_fmrdo_main_goto_next_channel();
		}
		g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_memo_down_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_memo_down_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	BOOL is_freq_changed = (g_fmrdo.normal_repeat_step_count != 0);

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if ((g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_MEMO_DOWN) || (g_avrcp_is_btn_pressed && (g_avrcp_btn == MMI_AVRCP_POP_BACKWARD || g_avrcp_btn == MMI_AVRCP_POP_REWIND)))
	{
		g_fmrdo.is_button_down = FALSE;
		if (mmi_fmrdo_is_channel_list_empty())
		{
			g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
			return;
		}
		if(g_avrcp_is_btn_pressed)
		{
			g_fmrdo.selected_button = FMRDO_BUTTON_MEMO_DOWN;	
		}
		mmi_fmrdo_redraw_main_push_button(g_fmrdo.selected_button, g_fmrdo.is_button_down);

		if(is_freq_changed)
		{
			g_fmrdo.normal_repeat_step_count = 0;
		}
		else
		{
			mmi_fmrdo_main_goto_previous_channel();
		}
		g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_power_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_press_power_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	g_fmrdo.selected_button = FMRDO_BUTTON_POWER;
	g_fmrdo.is_button_down = TRUE;
	StopTimer(FMRDO_VOLUME_BAR_TIMER);
	g_vol_displayed = 0;
	mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_searching_screen_popup_cb
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_searching_screen_popup_cb(mmi_alert_result_evt_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		case MMI_ALERT_INTERRUPT_EXIT:			
		case MMI_ALERT_CNFM_CANCEL:   
			{
				mmi_fmrdo_hw_scan_finish_ext();
			}
			break;

		}
	}
	return MMI_RET_OK;

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_search_screen_popup_cb
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_search_screen_popup_cb(mmi_alert_result_evt_struct *evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch (evt->result)
		{
		case MMI_ALERT_CNFM_1:   
			{
				mmi_confirm_property_struct arg = {0};
				MMI_ID popup_id;

				mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
				arg.parent_id = GRP_ID_FMRDO;
				arg.f_enter_history = MMI_TRUE;
				arg.callback = (mmi_proc_func)mmi_fmrdo_searching_screen_popup_cb;

				popup_id = mmi_confirm_display_ext(STR_GLOBAL_SEARCHING, MMI_EVENT_QUERY, &arg);		
				mmi_frm_scrn_close(g_fmrdo.confirm_id, g_fmrdo.confirm_id);
				g_fmrdo.confirm_id = popup_id;
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
				if (srv_earphone_is_plug_in() && !g_fmrdo.is_power_on)
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
				if (!g_fmrdo.is_power_on)
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
				{
					mmi_fmrdo_power_on_before_preset_auto_search();
				}

				if (g_fmrdo.is_power_on)	/* if audio is block, power won't be turned on */
				{
					/* start search all channels */
#ifdef __FM_RADIO_HW_SEARCH__
					mmi_fmrdo_hw_search_all_channels_start(mmi_fmrdo_preset_list_done);
#else 
					mmi_fmrdo_search_all_channels_start(mmi_fmrdo_preset_list_done);
#endif 

				}
			}
			break;

		case MMI_ALERT_CNFM_2:
			mmi_frm_scrn_close_active_id();
			g_fmrdo.confirm_id = 0;
			break;
		}
	}
	return MMI_RET_OK;

}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_release_power_button
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_release_power_button(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.is_button_down && g_fmrdo.selected_button == FMRDO_BUTTON_POWER)
	{
		g_fmrdo.is_button_down = FALSE;

		/* stop if it's searching */
		mmi_fmrdo_search_all_channels_stop();

		if(g_fmrdo.in_main_screen)
		{	
			if(!mmi_fmrdo_is_channel_list_empty())
			{
				/* power off if it's on */
				mmi_fmrdo_power_on_check((BOOL) ! g_fmrdo.is_power_on);
				mmi_fmrdo_redraw_main_all();
			}
			else
			{
				mmi_confirm_property_struct arg = {0};

				mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down, g_fmrdo.is_power_on, TRUE);

				mmi_confirm_property_init(&arg, CNFM_TYPE_USER_DEFINE);
				arg.parent_id = GRP_ID_FMRDO;
				arg.f_enter_history = MMI_TRUE;
				arg.softkey[0].str = (WCHAR *)GetString(STR_GLOBAL_SEARCH);
				arg.softkey[2].str = (WCHAR *)GetString(STR_GLOBAL_CANCEL);
				arg.callback = (mmi_proc_func)mmi_fmrdo_search_screen_popup_cb;

				g_fmrdo.confirm_id = mmi_confirm_display_ext(STR_ID_FMRDO_SEARCH_CHANNEL_LIST, MMI_EVENT_QUERY, &arg);
			}
		}
		else
		{
			mmi_fmrdo_power_on_check((BOOL) ! g_fmrdo.is_power_on);
		}

		g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_exit_root
* DESCRIPTION
*  
* PARAMETERS
*  param_p     [IN]     
* RETURNS
*  U8
*****************************************************************************/
mmi_ret mmi_fmrdo_exit_root(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (!g_fmrdo.is_background_play)
	{
		mmi_fmrdo_power_on_check(FALSE);
	}
	else if (g_fmrdo.is_power_on)
	{
		// TODO: MAUI_03144423
		mmi_fmrdo_search_all_channels_stop();
		if (mdi_audio_set_background_handler(MDI_BACKGROUND_APP_FMR, (mdi_bg_callback) mmi_fmrdo_continued, NULL) != MDI_AUDIO_ERROR)
		{
			mdi_audio_clear_other_background_handler(MDI_BACKGROUND_APP_FMR);
		}
	}		
	/* Keep frequency after exit FM radio */
	WriteValueSlim(NVRAM_FMRDO_LAST_CHANNEL, &g_fmrdo.frequency, DS_SHORT);
#ifdef __BT_SPK_VOL_CONTROL__
	if (!g_fmrdo.is_background_play || g_fmrdo.is_power_on == FALSE)
	{
		mdi_audio_bt_clear_volume_sync_callback(APP_FMRDO);
	}
#endif /* __BT_SPK_VOL_CONTROL__ */ 
	mmi_frm_kbd_set_tone_state(MMI_KEY_TONE_ENABLED);
#ifdef __MMI_NCENTER_SUPPORT__
	if(mmi_fmrdo_is_power_on())
	{	
		mmi_fmrdo_ncenter_add_fm();
	}
#endif
#ifdef __MMI_FM_VIA_A2DP__
	mmi_fmrdo_a2dp_connect_stop_animation();
#endif
#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_clear_cmd_hdlr();
#endif
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_profiles_vol_hdlr
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_profiles_vol_hdlr(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	srv_prof_evt_vol_change_struct *evt = (srv_prof_evt_vol_change_struct *)param;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_UNIQUE_MEDIA_VOL__
	if (g_fmrdo.is_ready && evt->evt_id == EVT_ID_SRV_PROF_VOL_CHANGED && evt->vol_type == SRV_PROF_VOL_MEDIA)
	{
		U8 profile_med_vol = 0;

		srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_MEDIA_VOL_LEVEL, (void *)&profile_med_vol);

		profile_med_vol &= 0xBF; /* to convert volume level back */

		if(profile_med_vol != g_fmrdo.volume)
		{
			if(profile_med_vol > MDI_AUD_VOL_6)
			{
				g_fmrdo.volume = MDI_AUD_VOL_6;
			}
			else if(profile_med_vol < MDI_AUD_VOL_0)
			{
				g_fmrdo.volume = MDI_AUD_VOL_0;
			}
			else
			{
				g_fmrdo.volume = profile_med_vol;
			}
			
			if(g_fmrdo.is_power_on)
			{
				if (g_fmrdo.volume)
				{
					mdi_audio_set_volume(AUD_VOLUME_FMR, MDI_AUD_VOL_MUTE(g_fmrdo.volume));
				}
				else
				{
					mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
				}
			}
		}
	}
#endif
return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_main_register_keys
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
#ifdef __MMI_TOUCH_SCREEN__
extern void mmi_fmrdo_pen_down_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_up_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_move_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_repeat_hdlr(mmi_pen_point_struct pos);
extern void mmi_fmrdo_pen_long_tap_hdlr(mmi_pen_point_struct pos);
#endif /* __MMI_TOUCH_SCREEN__ */ 

void mmi_fmrdo_main_register_keys(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[g_fmrdo.skin_index];

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	mmi_pen_register_down_handler(mmi_fmrdo_pen_down_hdlr);
	mmi_pen_register_up_handler(mmi_fmrdo_pen_up_hdlr);
	mmi_pen_register_move_handler(mmi_fmrdo_pen_move_hdlr);
	mmi_pen_register_repeat_handler(mmi_fmrdo_pen_repeat_hdlr);	
	mmi_pen_register_long_tap_handler(mmi_fmrdo_pen_long_tap_hdlr);	
	mmi_frm_cb_reg_event(EVT_ID_SRV_PROF_VOL_CHANGED, (mmi_proc_func)mmi_fmrdo_profiles_vol_hdlr, NULL);
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_entry_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_entry_main(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	const mmi_fmrdo_skin_struct *skin_p = &g_fmrdo_skins[0];
	S32 w = 0, h = 0;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_ENTRY_MAIN);

	if(!g_fmrdo.is_power_on && mdi_audio_get_background_callback_order(MDI_BACKGROUND_APP_FMR)< 0 )
	{
		mdi_audio_suspend_background_play();
	}
	if (g_fmrdo.is_power_on == TRUE)
	{
		if(g_fmrdo.state != FMRDO_STATE_BT_CONNECTING)
		{
		if (!g_fmrdo.volume)
		{
#ifdef __BT_SPK_VOL_CONTROL__
			mdi_audio_set_volume_to_bt(g_fmrdo.volume);
#endif
			mdi_audio_set_mute(AUD_VOLUME_FMR, MMI_TRUE);
		}
		else
		{
			mmi_fmrdo_set_volume(g_fmrdo.volume);
		}
#ifdef __MMI_NCENTER_SUPPORT__
		if(ncenter_fmrdo_nhandle || ncenter_fmrdo_ghandle)
		{
			mmi_fmrdo_ncenter_clear_fm();
		}
#endif
	}
	}

	/* setup SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
	gui_screen_switch_effect_setup(0, 0, 0);
#endif 

	g_fmrdo.in_main_screen = TRUE;
#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_set_cmd_hdlr();
#endif
	/* button state */
	g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	g_fmrdo.is_button_down = FALSE;
	g_fmrdo.normal_repeat_step_count = 0;
	g_fmrdo.is_long_press_number_key = FALSE;
	g_fmrdo.twinkle_frequency_count = 0;

	gui_measure_image((U8 *)GetImage(skin_p->power_button_on_up_image_id), &w, &h);
	g_fmrdo.down_img_buff = mmi_frm_scrmem_alloc_framebuffer(w * h * GDI_COLOR_FORMAT_16);

	MMI_ASSERT(g_fmrdo.down_img_buff);

	/* draw main screen */
	mmi_fmrdo_show_main();

	/* run SSE */
#ifdef __MMI_SCREEN_SWITCH_EFFECT__
	gui_screen_switch_effect_run();
#endif 
	/* Register all key handler */
	mmi_fmrdo_main_register_keys();

#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__  
/* under construction !*/
#endif /* __MMI_TOUCH_FEEDBACK_SUPPORT__  */
#endif
	mmi_fmrdo_update_center_key_status();
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_exit_main
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_exit_main(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_EXIT_MAIN);

	g_fmrdo.in_main_screen = FALSE;

	/* stop timer and update frequency if we don't release step up/down button yet */
#if defined(__MMI_FM_RADIO_RECORD__)
#ifdef __MMI_FTE_SUPPORT__
#ifndef MULTIMIDIA_FTE2_KEY_ONLY_SUPPORT
	gui_cancel_timer(mmi_fmrdo_update_record_bar);
#endif 
#endif 
#endif 

	mmi_fmrdo_reset_volume_bar();
	g_vol_displayed= 0;
	StopTimer(FMRDO_VOLUME_BAR_TIMER);

#ifndef __MMI_FM_PLUTO_SLIM__
	/* stop previous twinkle frequency if necessary */
	mmi_fmrdo_stop_twinkle_frequency(FALSE);
#endif
#ifdef __FM_RADIO_HW_SEARCH__
	/* stop hw searching twinkle */
#ifdef __MMI__FM_PLUTO_SLIM__
	gui_cancel_timer(mmi_fmrdo_twinkle_searching_timer);
#endif
#endif /* __FM_RADIO_HW_SEARCH__ */ 
	/* stop if it's searching */
	mmi_fmrdo_search_frequency_stop();
	g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
	g_fmrdo.is_button_down = FALSE;
	g_fmrdo.normal_repeat_step_count = 0;
	g_fmrdo.is_long_press_number_key = FALSE;
	g_fmrdo.twinkle_frequency_count = 0;
#if defined(__MMI_FM_RADIO_RECORD__)
	/* Abort due to exit screen */
	g_fmrdo.rec.user_abort = FALSE;
	mmi_fmrdo_stop_record_on_exit();
	mmi_fmrdo_util_stop_duration();
#endif /* defined(__MMI_FM_RADIO_RECORD__) */ 

	mdi_audio_resume_background_play();
#ifdef __MMI_FTE_SUPPORT__
#ifdef __MMI_TOUCH_FEEDBACK_SUPPORT__
/* under construction !*/
#endif /*__MMI_TOUCH_FEEDBACK_SUPPORT__*/
#endif
#ifdef __MMI_AVRCP_SUPPORT__
	mmi_fmrdo_avrcp_clear_cmd_hdlr();
#endif

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_is_channel_list_empty
* DESCRIPTION
* Function to tell if the channel list is empty. 
* PARAMETERS
*  void
* RETURNS
*  MMI_BOOL
*****************************************************************************/
MMI_BOOL mmi_fmrdo_is_channel_list_empty(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	MMI_BOOL result = MMI_TRUE;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(g_fmrdo.is_ready)
	{
		/* if first channel is present, then the list is not empty */
		if(g_fmrdo.channel_list.freq[0])
		{
			result = MMI_FALSE;
		}
	}
	return result;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_channel_list_item_ext
* DESCRIPTION
*  
* PARAMETERS
*  item_index          [IN]        Channel index
*  str_buff            [IN]        Channel name
*  img_buff_p          [OUT]       Image
*  str_img_mask        [IN]        
* RETURNS
*  pBOOL
*****************************************************************************/
S32 mmi_fmrdo_channel_list_item_ext(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	S32 index;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (index = 0; index< data_size; index++)
	{
		mmi_fmrdo_channel_list_item(start_index, menu_data[index].item_list[0], &menu_data[index].image_list[1], 0);
		start_index++;
	}
	return data_size;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_channel_list_item
* DESCRIPTION
*  
* PARAMETERS
*  item_index          [IN]        Channel index
*  str_buff            [IN]        Channel name
*  img_buff_p          [OUT]       Image
*  str_img_mask        [IN]        
* RETURNS
*  pBOOL
*****************************************************************************/
pBOOL mmi_fmrdo_channel_list_item(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p, U8 str_img_mask)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	/* show frequency text */
	U16 freq;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (item_index == 0)
	{
		mmi_ucs2cpy((CHAR *) str_buff, GetString(STR_ID_FMRDO_PRESET_AUTO_SEARCH));
	}
	else
	{
		freq = g_fmrdo.channel_list.freq[item_index - 1];
		kal_wsprintf(str_buff, "%d.%d", freq / 10, freq % 10);
	}

	/* show order icon */
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);
	if(g_fmrdo.channel_index != -1 && g_fmrdo.frequency && (g_fmrdo.channel_list.freq[item_index - 1] == g_fmrdo.frequency))
	{
		/* Playing current channel */
		*img_buff_p = (PU8)wgui_get_list_menu_icon(item_index, IMG_ID_FMRDO_CURR_CHANNEL_TICK);
	}
	wgui_restore_list_menu_slim_style();

	return TRUE;
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_get_str_from_freq
* DESCRIPTION
*  
* PARAMETERS
*  input_str       [IN]        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_get_str_from_freq(U16 freq, UI_string_type freq_str)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	UI_character_type temp[2] = {0};

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	kal_wsprintf(freq_str, "FM %d.%d", freq / 10, freq % 10);	
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_tap_callback_func
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_tap_callback_func(mmi_tap_type_enum tap_type, S32 index)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/


	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(index == 0)
	{
		mmi_confirm_property_struct arg = {0};

		mmi_confirm_property_init(&arg, CNFM_TYPE_CANCEL);
		arg.parent_id = GRP_ID_FMRDO;
		arg.f_enter_history = MMI_TRUE;
		arg.callback = (mmi_proc_func)mmi_fmrdo_searching_screen_popup_cb;

		g_fmrdo.confirm_id = mmi_confirm_display_ext(STR_GLOBAL_SEARCHING, MMI_EVENT_QUERY, &arg);		

#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
		if (srv_earphone_is_plug_in() && !g_fmrdo.is_power_on)
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
		if (!g_fmrdo.is_power_on)
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
		{
			mmi_fmrdo_power_on_before_preset_auto_search();
		}

		if (g_fmrdo.is_power_on)	/* if audio is block, power won't be turned on */
		{
			/* start search all channels */
#ifdef __FM_RADIO_HW_SEARCH__
			mmi_fmrdo_hw_search_all_channels_start(mmi_fmrdo_preset_list_done);
#else 
			mmi_fmrdo_search_all_channels_start(mmi_fmrdo_preset_list_done);
#endif 
		}
	}
	else
	{
		mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST);
		mmi_fmrdo_goto_channel(index - 1);
	}
}
#endif/*__MMI_FTE_SUPPORT__*/


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_entry_channel_list
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_entry_channel_list(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
#ifdef __MMI_BASIC_UI_STYLE__
	S32 error_flag;
#endif /* __MMI_BASIC_UI_STYLE__ */
	U8 *guiBuffer = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DRAW_ICON);

	guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_FMRDO, SCR_ID_FMRDO_CHANNEL_LIST);
	
	wgui_cat1032_show(
		(WCHAR*)GetString(STR_ID_FMRDO_CHANNEL_LIST),
		NULL,
		NULL,
		NULL,
		NULL,
		NULL,
		mmi_fmrdo_get_channel_count() + 1,
		mmi_fmrdo_channel_list_item_ext,
		NULL,
		0,
		0,
		0,
		IMG_ID_FMRDO_CURR_CHANNEL_TICK,
		guiBuffer,
		&error_flag);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
	/* Register for intuitive commands */
	wgui_register_tap_callback(mmi_fmrdo_tap_callback_func);
#endif /* __MMI_FTE_SUPPORT__ */

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_entry_preset_list_confirm_callback
* DESCRIPTION
*  
* PARAMETERS
*  void       
* RETURNS
*  S32
*****************************************************************************/
static mmi_ret mmi_fmrdo_entry_preset_list_confirm_callback(mmi_event_struct *mmi_evt)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	mmi_alert_result_evt_struct *evt = (mmi_alert_result_evt_struct*)mmi_evt;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if(evt->evt_id == EVT_ID_ALERT_QUIT)
	{
		switch(evt->result)
		{
		case MMI_ALERT_CNFM_YES:
			mmi_fmrdo_preset_list_confirm_OK();
			break;

		case MMI_ALERT_CNFM_NO:
			mmi_frm_scrn_close_active_id();
			break;

		default:
			break;
		}
	}
	return MMI_RET_OK;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_preset_list_confirm_OK
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_preset_list_confirm_OK(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
	if (srv_earphone_is_plug_in() && !g_fmrdo.is_power_on)
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
	if (!g_fmrdo.is_power_on)
#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
	{
		mmi_fmrdo_power_on_before_preset_auto_search();
	}

	if (g_fmrdo.is_power_on)    /* if audio is block, power won't be turned on */
	{
		/* start search all channels */
#ifdef __FM_RADIO_HW_SEARCH__
		mmi_fmrdo_hw_search_all_channels_start(mmi_fmrdo_preset_list_done);
#else 
		mmi_fmrdo_search_all_channels_start(mmi_fmrdo_preset_list_done);
#endif 
		mmi_fmrdo_update_center_key_status();
	}
	else
	{
#ifdef __MMI_BACKGROUND_CALL__
		if (srv_ucm_is_background_call())
		{
			mmi_ucm_app_entry_error_message();
		}
		else
#endif /* __MMI_BACKGROUND_CALL__ */ 
		{
#ifdef __MMI_FM_RADIO_BIND_EARPHONE__
			mmi_popup_display_simple_ext(STR_ID_FMRDO_PLEASE_PLUG_IN_EARPHONE,
				MMI_EVENT_INFO,
				GRP_ID_FMRDO, 
				NULL);
#else /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 

#endif /* __MMI_FM_RADIO_BIND_EARPHONE__ */ 
		}
	}
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_entry_searching
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_entry_searching(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* Show searching screen */
	ShowCategory66Screen(
		STR_ID_FMRDO_PRESET_AUTO_SEARCH,
		GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
		0,
		0,
		STR_GLOBAL_CANCEL,
		0,
		(U8*) GetString(STR_GLOBAL_SEARCHING),
		mmi_get_event_based_image(MMI_EVENT_PROGRESS),
		NULL);
}


#if defined(__MMI_FM_RADIO__) && defined(__MMI_FM_RADIO_BIND_EARPHONE__)

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_earphone_notify_hdlr
* DESCRIPTION
*  notify hdlr of earphone plugin/plugout.
* PARAMETERS
*  notify_flag     [IN]        Notify flag
*  para            [IN]        
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_earphone_notify_hdlr(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	switch (event->evt_id)
	{
	case EVT_ID_GPIO_EARPHONE_PLUG_IN:

#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__
		if(g_fmrdo.in_main_screen || mmi_frm_group_is_present(GRP_ID_FMRDO))
#else
		if(g_fmrdo.in_main_screen)
#endif
		{
#if defined(__MMI_FM_RADIO_LOUD_SPEAK__)
			if(g_fmrdo.loud_speaker_on)
			{
				mdi_audio_set_audio_mode(AUD_MODE_NORMAL);
			}
			else
#endif
			{
				mdi_audio_set_audio_mode(AUD_MODE_HEADSET);
			}
			mmi_fmrdo_power_on_main_screen(TRUE);		
		}
		break;

	case EVT_ID_GPIO_EARPHONE_PLUG_OUT:
		mmi_fmrdo_power_on_check(FALSE);
		break;

	default:
		break;
	}
	return MMI_RET_OK;
}
#endif

#ifdef __FM_RADIO_HW_SEARCH__


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_hw_stop_searching
* DESCRIPTION
*  stop hw searching
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_hw_stop_searching(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	//mmi_fmrdo_redraw_main_LSK_up();
	mmi_fmrdo_search_frequency_stop();
	/* clear LSK hdlr to avoid send abort search msg again */
	ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	ClearKeyHandler(KEY_LSK, KEY_EVENT_DOWN);
	mmi_fmrdo_exit_hw_seaching_screen(g_fmrdo.frequency);
	g_fmrdo.is_button_down = FALSE;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_exit_hw_seaching_screen
* DESCRIPTION
*  restore main screen key hdlr when hardware search done
* PARAMETERS
*  stop_freq       [IN]        Selected frequency
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_exit_hw_seaching_screen(U16 stop_freq)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
#ifndef __MMI_FM_PLUTO_SLIM__
	gui_cancel_timer(mmi_fmrdo_twinkle_searching_timer);
#endif
	mmi_fmrdo_redraw_main_frequency(stop_freq, TRUE);
	g_fmrdo.is_button_down = FALSE;
	//  mmi_fmrdo_restore_main_SK();
	mmi_fmrdo_main_register_keys();
	g_fmrdo.normal_repeat_step_count = 0;
}

#endif /* __FM_RADIO_HW_SEARCH__ */ 

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_main_goto_previous_channel
* DESCRIPTION
*  From current frequency switch to the previous user defined channel
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_main_goto_previous_channel(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 i;
	S16 prev_channel = -1;
	S16 last_channel = FM_RADIO_CHANNEL_NUM - 1;
	S16 channel_index = g_fmrdo.channel_index; /* current channel index */

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
	{
		return;
	}

	if (mmi_fmrdo_is_channel_list_empty())    /* the channel list is empty! */
	{
		return;
	}
	while(!g_fmrdo.channel_list.freq[last_channel])
		last_channel--;
	if (channel_index == -1)    /* current channle is not an user defined channel */
	{
		for (i = last_channel; i >= 0; i--)
		{
			if (g_fmrdo.channel_list.freq[i] < g_fmrdo.frequency)
			{
				prev_channel = i;
				break;
			}
		}
		if(i < 0)
		{
			prev_channel = last_channel;		
		}
		mmi_fmrdo_goto_channel(prev_channel);   /* goto next channel */		
		return;
	}
	else  
	{
		if (channel_index > 0 && g_fmrdo.channel_list.freq[channel_index - 1])
		{
			prev_channel = channel_index - 1;
			mmi_fmrdo_goto_channel(prev_channel);   /* goto next channel */
			return;
		}
		else
		{
			prev_channel = last_channel;
			mmi_fmrdo_goto_channel(prev_channel);   /* goto first channel */
			return;
		}
	}

}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_main_goto_next_channel
* DESCRIPTION
*  From current frequency switch to the next user defined channel
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_main_goto_next_channel(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 i;
	S16 next_channel = -1;
	S16 channel_index = g_fmrdo.channel_index; /* current channel index */

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
	{
		return;
	}

	if (mmi_fmrdo_is_channel_list_empty())    /* the channel list is empty! */
	{
		return;
	}
	if (channel_index == -1)    /* current channle is not an user defined channel */
	{
		for (i = 0; i < FM_RADIO_CHANNEL_NUM && g_fmrdo.channel_list.freq[i]; i++)
		{
			if (g_fmrdo.channel_list.freq[i] && g_fmrdo.channel_list.freq[i] > g_fmrdo.frequency)
			{
				next_channel = i;
				break;
			}
		}
		if(i == FM_RADIO_CHANNEL_NUM || !g_fmrdo.channel_list.freq[i])
		{
			next_channel = 0;		
		}
		mmi_fmrdo_goto_channel(next_channel);   /* goto next channel */		
		return;
	}
	else  
	{
		if (channel_index < FM_RADIO_CHANNEL_NUM - 1 && g_fmrdo.channel_list.freq[channel_index + 1])
		{
			next_channel = channel_index + 1;
			mmi_fmrdo_goto_channel(next_channel);   /* goto next channel */
			return;
		}
		else
		{
			next_channel = 0;
			mmi_fmrdo_goto_channel(next_channel);   /* goto first channel */
			return;
		}
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_get_channel_count
* DESCRIPTION
*  get current number of valid channels in FM Radio
* PARAMETERS
*  void
* RETURNS
*  is_ready
*****************************************************************************/
S16 mmi_fmrdo_get_channel_count(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	S16 channels = 0;
	S16 count;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	for (count = 0; count < FM_RADIO_CHANNEL_NUM; count++)
	{
		if (g_fmrdo.channel_list.freq[count] != 0)
		{
			channels++;
		}
	}
	return channels;
}



/*Add for FTE 2.0 FM widget*/


#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_scrlocker_event_notify_handler
* DESCRIPTION
*  
* PARAMETERS
*  
* RETURNS
*  mmi_ret
*****************************************************************************/
mmi_ret mmi_fmrdo_scrlocker_event_notify_handler(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	if (event->evt_id == EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING)
	{
		if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE )
		{
			return MMI_RET_ERR;
		}
#if defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
		if (g_fmrdo.state == FMRDO_STATE_SEARCH_ALL || g_fmrdo.state == FMRDO_STATE_SEARCH_ONE)
		{
			return MMI_RET_ERR;
		}
#endif 
	}
	return MMI_RET_OK;
}
#endif /* #ifdef __MMI_SCREEN_LOCK_ANY_TIME__ */


#ifdef __MMI_FM_VIA_A2DP__

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_entry_a2dp_connecting
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_entry_a2dp_connecting(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	/* Show searching screen */
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[mtk33271]mmi_fmrdo_entry_a2dp_connecting");
	ShowCategory66Screen(
		STR_GLOBAL_CONNECTING,
		GetRootTitleIcon(MENU_ID_FMRDO_MAIN),
		0,
		0,
		0,
		0,
		(U8*) GetString(STR_GLOBAL_CONNECTING),
		mmi_get_event_based_image(MMI_EVENT_PROGRESS),
		NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmrdo_a2dp_connect_stop_animation
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmrdo_a2dp_connect_stop_animation(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_cancel_timer(mmi_fmrdo_a2dp_connect_start_animation);
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "a2dp_connect_stop_animation");
	if(mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING, MMI_FRM_NODE_ALL_FLAG))
	{
		mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING);
    }
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_a2dp_connecting_scrn_proc
* DESCRIPTION
*  
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
mmi_ret mmi_fmrdo_a2dp_connecting_scrn_proc(mmi_event_struct *param)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI_MEDIA_APP, "[mtk33271]mmi_fmrdo_entry_a2dp_connecting,case = %d",param->evt_id);

	switch (param->evt_id)
	{
	case EVT_ID_SCRN_ACTIVE:
		mmi_fmrdo_entry_a2dp_connecting();
		break;

	case EVT_ID_SCRN_INACTIVE:
		if(mmi_frm_scrn_is_present(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING, MMI_FRM_NODE_ALL_FLAG))
		{
			mmi_frm_scrn_close(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING);
		}
		break;

	default:
		break;
	}
	return MMI_RET_OK;
}

/*****************************************************************************
* FUNCTION
*   mmi_fmrdo_a2dp_connect_start_animation
* DESCRIPTION
*   start osd animation
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_a2dp_connect_start_animation(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      						   */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_BT_START_OSD_ANI_IN);
	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected && (g_fmrdo.in_main_screen == MMI_TRUE))
	{
		mmi_frm_scrn_create(GRP_ID_FMRDO, SCR_ID_FMRDO_A2DP_CONNECTING, mmi_fmrdo_a2dp_connecting_scrn_proc, NULL);
	}
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_FMRDO_TRC_BT_START_OSD_ANI_OUT);
}

/*****************************************************************************
* FUNCTION
*   mmi_fmrdo_change_state_a2dp_connect
* DESCRIPTION
*   change state to BT Connecting
* PARAMETERS
*   void        
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_change_state_a2dp_connect(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      						   */
	/*----------------------------------------------------------------*/
	if(mmi_a2dp_is_output_to_bt() && !fm_a2dp_connected)
	{
		g_fmrdo.state = FMRDO_STATE_BT_CONNECTING;
	}
	if(!mmi_is_redrawing_bk_screens())
	{
		/* 
		MMI_FRM_INIT_EVENT(&evt,EVT_ID_FMRDO_A2DP_CONNECT);
		MMI_FRM_POST_EVENT(&evt,mmi_fmrdo_broadcast_event_callback_hdlr,NULL);
		*/
		gui_start_timer(200,mmi_fmrdo_a2dp_connect_start_animation);
	} 
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_broadcast_event_callback_hdlr
* DESCRIPTION
*  this is callback handler for framework event braodcast
* PARAMETERS
*  mmi_event_struct*  [IN] event info
* RETURNS
* mmi_ret
*****************************************************************************/
mmi_ret mmi_fmrdo_broadcast_event_callback_hdlr(mmi_event_struct *event)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	switch(event->evt_id)
	{
	case EVT_ID_FMRDO_A2DP_CONNECT:
		{
            mmi_fmrdo_a2dp_connect_start_animation();
			return MMI_RET_OK;
		}
	default:
		{
			return MMI_RET_OK;
		}
	}
}

#endif /*__MMI_FM_VIA_A2DP__*/

#ifdef __MMI_AVRCP_SUPPORT__

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_avrcp_set_cmd_hdlr
* DESCRIPTION
*  to set avrcp handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_avrcp_set_cmd_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/  

	mmi_bt_avrcp_set_cmd_hdlr(mmi_fmrdo_bt_avrcp_cmd_hdlr);
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_avrcp_clear_cmd_hdlr
* DESCRIPTION
*  to clear avrcp handler
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
void mmi_fmrdo_avrcp_clear_cmd_hdlr(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    
	if(!mmi_fmrdo_is_power_on() && !g_fmrdo.in_main_screen)
	{
		mmi_bt_avrcp_clear_cmd_hdlr(mmi_fmrdo_bt_avrcp_cmd_hdlr);
		g_avrcp_is_btn_pressed = MMI_FALSE;
		g_avrcp_btn = 0;
	}
}

/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_press_button_canceled
* DESCRIPTION
*  to cancel key down action
* PARAMETERS
*  void
* RETURNS
*  void
*****************************************************************************/
static void mmi_fmrdo_press_button_canceled(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/    

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_AVRCP_CANCELED,g_fmrdo.selected_button,g_fmrdo.is_button_down);

	g_avrcp_is_btn_pressed = MMI_FALSE;
	g_avrcp_btn = 0;

	if(g_fmrdo.selected_button == FMRDO_BUTTON_NONE || g_fmrdo.is_button_down == MMI_FALSE)
	{
		return;
	}

	g_fmrdo.is_button_down = MMI_FALSE;
	if(g_fmrdo.in_main_screen)
	{
		switch(g_fmrdo.selected_button)
		{
#ifndef __MMI_MAINLCD_96X64__
			case FMRDO_BUTTON_POWER:
				{
					mmi_fmrdo_redraw_main_toggle_button(g_fmrdo.selected_button, g_fmrdo.is_button_down ,g_fmrdo.is_power_on ,MMI_TRUE);
					break;
				}
#endif 
			default:
				break;
		}
	}
	g_fmrdo.selected_button = FMRDO_BUTTON_NONE;
}


/*****************************************************************************
* FUNCTION
*  mmi_fmrdo_bt_avrcp_cmd_hdlr
* DESCRIPTION
*  callback function to handle avrcp commands from BT device
* PARAMETERS
*  command         [IN]        
*  key_press       [IN]        
* RETURNS
*  U8
*****************************************************************************/
U8 mmi_fmrdo_bt_avrcp_cmd_hdlr(U8 command, mmi_avrcp_key_events key_events)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U8 result = MMI_AVRCP_CR_ACCEPT;

	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/

	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_BT_AVRCP_CMD,g_fmrdo.state,command,key_events);
	
	if((key_events == MMI_AVRCP_KEY_UP) && !srv_avrcp_is_avrcp_connected(mmi_a2dp_get_bt_headset()))
	{
		result = MMI_AVRCP_CR_REJECT;
		g_avrcp_is_btn_pressed = MMI_FALSE;
		g_avrcp_btn = 0;

		goto avrcp_finish;	
	}
	
	if (g_fmrdo.state == FMRDO_STATE_RECORD || g_fmrdo.state == FMRDO_STATE_RECORD_PAUSE)
	{
		result = MMI_AVRCP_CR_REJECT;
		goto avrcp_finish;
	}
	if (key_events == MMI_AVRCP_KEY_CANCELED)
	{
		switch (command)
		{
		case MMI_AVRCP_POP_PLAY:
		case MMI_AVRCP_POP_STOP:
		case MMI_AVRCP_POP_PAUSE:
		case MMI_AVRCP_POP_POWER:
		case MMI_AVRCP_POP_FORWARD:
		case MMI_AVRCP_POP_BACKWARD:
		case MMI_AVRCP_POP_CHANNEL_UP:
		case MMI_AVRCP_POP_CHANNEL_DOWN:
			mmi_fmrdo_press_button_canceled();
			break;
		default :
			break;
		}
		/*the return value do not mean anything in key canceled event*/
		result = MMI_AVRCP_CR_REJECT;
		goto avrcp_finish;
	}

	switch (command)
	{
	case MMI_AVRCP_POP_PLAY:
	case MMI_AVRCP_POP_PAUSE:
		{
			if (key_events == MMI_AVRCP_KEY_UP)
			{
				mmi_fmrdo_release_power_button();
				g_avrcp_is_btn_pressed = MMI_FALSE;
				g_avrcp_btn = 0;
			}
			else if(key_events == MMI_AVRCP_KEY_DOWN)
			{   
				g_avrcp_is_btn_pressed = MMI_TRUE;
				g_avrcp_btn = command;
				mmi_fmrdo_press_power_button(); 
			}
		}
			break;

	case MMI_AVRCP_POP_STOP:
		{
			if (key_events == MMI_AVRCP_KEY_UP)
			{  
				mmi_fmrdo_release_power_button();
				g_avrcp_is_btn_pressed = MMI_FALSE;
				g_avrcp_btn = 0;
			}
			else if(key_events == MMI_AVRCP_KEY_DOWN)
			{
				g_avrcp_is_btn_pressed = MMI_TRUE;
				g_avrcp_btn = command;
				mmi_fmrdo_press_power_button();
			}
		}
			break;

	case MMI_AVRCP_POP_FORWARD:
	case MMI_AVRCP_POP_FAST_FORWARD:
		{
			switch(key_events)
			{
			case MMI_AVRCP_KEY_UP:
				{ 
					if(mmi_fmrdo_is_power_on())
					{
						mmi_fmrdo_release_memo_up_button();
					}
						g_avrcp_is_btn_pressed = MMI_FALSE;
						g_avrcp_btn = 0;
				}
				break;

			case MMI_AVRCP_KEY_DOWN:
				{
					g_avrcp_is_btn_pressed = MMI_TRUE;
					g_avrcp_btn = command;
					if(mmi_fmrdo_is_power_on())
					{
				mmi_fmrdo_press_memo_up_button();
					}
				}
				break;

			case MMI_AVRCP_KEY_LONGPRESS:
			case MMI_AVRCP_KEY_REPEAT:
			{
					if(mmi_fmrdo_is_power_on())
					{
					U16 freq = (g_fmrdo.frequency < MAX_FM_FREQUENCY) ? g_fmrdo.frequency + 1 : MIN_FM_FREQUENCY;
					g_fmrdo.normal_repeat_step_count = 1;
					mmi_fmrdo_set_frequency(freq);
			}           
				}
				break;

			default:
				result = MMI_AVRCP_CR_REJECT;
				break;
			}
		}
			break;

	case MMI_AVRCP_POP_BACKWARD:
	case MMI_AVRCP_POP_REWIND:
		{
			switch(key_events)
			{
			case MMI_AVRCP_KEY_UP:
				{				
					if(mmi_fmrdo_is_power_on())
					{
						mmi_fmrdo_release_memo_down_button();
					}
						g_avrcp_is_btn_pressed = MMI_FALSE;
						g_avrcp_btn = 0;
				}
				break;

			case MMI_AVRCP_KEY_DOWN:
				{
					g_avrcp_is_btn_pressed = MMI_TRUE;
					g_avrcp_btn = command;
					if(mmi_fmrdo_is_power_on())
					{
				mmi_fmrdo_press_memo_down_button();
					}
				}
				break; 

			case MMI_AVRCP_KEY_LONGPRESS:
			case MMI_AVRCP_KEY_REPEAT:
			{
					if(mmi_fmrdo_is_power_on())
					{
					U16 freq = (g_fmrdo.frequency > MIN_FM_FREQUENCY) ? g_fmrdo.frequency - 1 : MAX_FM_FREQUENCY;  
					g_fmrdo.normal_repeat_step_count = 1;
					mmi_fmrdo_set_frequency(freq);
			}
				}			
				break;

			default:
				result = MMI_AVRCP_CR_REJECT;
				break;
			}
		}
			break;

	default:
		result = MMI_AVRCP_CR_NOT_IMPLEMENT;
		break;
	}


avrcp_finish:
	MMI_TRACE(MMI_MEDIA_TRC_G2_APP, MMI_TRC_FMRDO_AVRCP_RETURN, result); 
	return result;
}
#endif /* __MMI_AVRCP_SUPPORT__ */ 
#endif /* __MMI_WEARABLE_DEVICE__ */
#endif /* __MMI_FM_RADIO__ */ 

