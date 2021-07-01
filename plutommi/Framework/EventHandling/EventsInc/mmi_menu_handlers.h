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
 *  mmi_menu_handlers.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Hilite handlers and Hint handlers of menuitems
 *
 * Author:
 * -------
 * -------
 *
*==============================================================================
 *              HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef _MENUHANDLER_H
#define _MENUHANDLER_H

/* need typedef void (*FuncPtr) (void); before include this file */

/* #define MENU_HILITE_HANDLER_COUNT   70; */
/* #define MENU_HINT_HANDLER_COUNT     0; */

#include "mmi_rp_all_defs.h"
/* Extern functions of Hilite Handler */
extern void mmi_frm_highlight_inline_generic_done(void);
extern void mmi_frm_highlight_input_method_generic(void);
extern void DataConnectGSMHiliteHandler(void);
extern void mmi_fmgr_highlight_to_phb(void);
extern void mmi_fmgr_highlight_to_sms(void);
extern void mmi_fmgr_highlight_audio_play(void);
extern void mmi_fmgr_highlight_video_play(void);
extern void HighlightConnectivity(void);
extern void GB_WG_Search_Web_Highlight_Hdlr(void);
extern void mmi_bt_main_hilight_handler(void);
extern void mmi_secset_main_menu_highlight_hdlr(void);
extern void mmi_imgview_highlight_app(void);
extern void mmi_sndrec_hightlight_main(void);
extern void mmi_audply_highlight_option_play(void);
extern void mmi_audply_highlight_option_details(void);
extern void mmi_audply_highlight_option_remove(void);
extern void mmi_audply_highlight_option_settings(void);
extern void mmi_audply_highlight_option_add(void);
extern void mmi_audply_highlight_option_add_to_ring(void);
extern void mmi_audply_highlight_option_removeall(void);
extern void mmi_audply_highlight_option_refresh(void);
extern void HighlightAudioPlayer(void);
extern void HighlightAudioPlayerBt(void);
extern void HighlightWCMenu(void);
extern void HighlightWcBrowseCity(void);
extern void mmi_data_connection_sim_hilite_hdlr(void);
extern void DataConnectHiliteHandler(void);
extern void mmi_profiles_highlight_sound_settings(void);
extern void mmi_profiles_highlight_volume_settings(void);
extern void highlight_mainmenu_profiles(void);
extern void HighlightCalibrationSetting(void);
extern void HighlightPhnsetScr(void);
extern void HighlightDisplayScr(void);
extern void HighlightRstScr(void);
extern void HighlightMreApps(void);
extern void mmi_highlight_netset_main(void);
extern void mmi_service_hilite_sat_hdlr(void);
extern void HighlightVersionInfo(void);
extern void HighlightCalcMenu(void);
extern void HighlightAlmMenu(void);
extern void HighlightClndrMenu(void);
extern void mmi_ucm_highlight_call_type_voice(void);
extern void mmi_vdoply_highlight_app(void);
extern void mmi_vdoply_highlight_play(void);
extern void highlight_mainmenu_messages(void);
extern void mmi_um_highlight_write_msg(void);
extern void mmi_um_highlight_inbox(void);
extern void mmi_um_highlight_draft(void);
extern void mmi_um_highlight_unsent(void);
extern void mmi_um_highlight_sent(void);
extern void mmi_um_ui_sh_main_msg_entry_del_msg_folder(void);
extern void mmi_um_highlight_setting(void);
extern void highlight_mainmenu_filemngr(void);
extern void highlight_mainmenu_phonebook(void);
extern void highlight_mainmenu_funandgames(void);
extern void highlight_mainmenu_extra(void);
extern void highlight_mainmenu_calllog(void);
extern void highlight_mainmenu_multimedia(void);
extern void highlight_mainmenu_services(void);
extern void highlight_mainmenu_organizer(void);
extern void mmi_settings_highlight_general_call_setting(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_settings(void);
extern void highlight_mainmenu_WiFi_wizard(void);
extern void highlight_mainmenu_callcenter(void);
extern void highlight_mainmenu_tools(void);
extern void highlight_mainmenu_bt_dialer(void);
extern void highlight_mainmenu_phonebook(void);
extern void highlight_mainmenu_btnotification(void);
extern void highlight_mainmenu_btrmtcap(void);


/* Extern functions of Hint Handler */

const mmi_frm_hilite_hdlr_struct mmi_frm_const_hilite_hdlr_table[] = {
    {MENU_DONE_OPTION_ID, mmi_frm_highlight_inline_generic_done},
    {MENU_INPUT_METHOD_OPTION_ID, mmi_frm_highlight_input_method_generic},
    {SERVICES_DATA_CONNECT_MENU_ID, DataConnectGSMHiliteHandler},
    {MENU_ID_FMGR_FWD_CONTACT, mmi_fmgr_highlight_to_phb},
    {MENU_ID_FMGR_FWD_SMS, mmi_fmgr_highlight_to_sms},
    {MENU_ID_FMGR_AUD_OPTION_PLAY, mmi_fmgr_highlight_audio_play},
    {MENU_ID_FMGR_VID_OPTION_PLAY, mmi_fmgr_highlight_video_play},
    {MENU_ID_CONNECTIVITY, HighlightConnectivity},
    {MENU_ID_SEARCH_WEB_WINGUO_ENTRY, GB_WG_Search_Web_Highlight_Hdlr},
    {MENU_CONN_BT_MAIN, mmi_bt_main_hilight_handler},
    {MENU_ID_SECSET_MAIN_MENU, mmi_secset_main_menu_highlight_hdlr},
    {MENU_ID_IMGVIEW_APP, mmi_imgview_highlight_app},
    {MENU_ID_SNDREC_MAIN, mmi_sndrec_hightlight_main},
    {MENU_ID_AUDPLY_OPTION_PLAY, mmi_audply_highlight_option_play},
    {MENU_ID_AUDPLY_OPTION_DETAILS, mmi_audply_highlight_option_details},
    {MENU_ID_AUDPLY_OPTION_REMOVE, mmi_audply_highlight_option_remove},
    {MENU_ID_AUDPLY_OPTION_SETTINGS, mmi_audply_highlight_option_settings},
    {MENU_ID_AUDPLY_OPTION_ADD, mmi_audply_highlight_option_add},
    {MENU_ID_AUDPLY_OPTION_ADD_TO_RING, mmi_audply_highlight_option_add_to_ring},
    {MENU_ID_AUDPLY_OPTION_REMOVE_ALL, mmi_audply_highlight_option_removeall},
    {MENU_ID_AUDPLY_OPTION_REFRESH, mmi_audply_highlight_option_refresh},
    {AUDIO_PLAYER_MAIN_MENUID, HighlightAudioPlayer},
    {MAIN_MENU_BT_MUSIC_APP_MENUID, HighlightAudioPlayerBt},
    {ORGANIZER_WORLDCLOCK_MENU, HighlightWCMenu},
    {MITEM_WORLDCLOCK_BROWSECITY, HighlightWcBrowseCity},
    {MENU_ID_DATA_CONNECTION_SIM, mmi_data_connection_sim_hilite_hdlr},
    {SERVICES_DATA_CONNECT_MAIN_MENU_ID, DataConnectHiliteHandler},
    {MAIN_MENU_PROF_SOUND_SETTING, mmi_profiles_highlight_sound_settings},
    {MAIN_MENU_PROF_VOLUME_SETTING, mmi_profiles_highlight_volume_settings},
    {MAIN_MENU_PROFILES_MENUID, highlight_mainmenu_profiles},
    {MENU_SETTING_CALIBRATION, HighlightCalibrationSetting},
    {MENU9102_INITIAL_SETUP, HighlightPhnsetScr},
    {MENU_PHNSET_BACKLIGHT_DISP, HighlightDisplayScr},
    {MENU_SETTING_RESTORE, HighlightRstScr},
    {MENU_ID_SETTING_MREAPPS, HighlightMreApps},
    {MENU_ID_NETSET_MAIN, mmi_highlight_netset_main},
    {MENU_ID_SAT1_ENTRY, mmi_service_hilite_sat_hdlr},
    {MENU_ID_SETTING_VERSION_INFO, HighlightVersionInfo},
    {EXTRA_CALCULATOR_MENU, HighlightCalcMenu},
    {ORGANIZER_ALARM_MENU, HighlightAlmMenu},
    {ORGANIZER_CALENDER_MENU, HighlightClndrMenu},
    {MENU_ID_UCM_CALL_TYPE_VOICE, mmi_ucm_highlight_call_type_voice},
    {MENU_ID_VDOPLY_APP, mmi_vdoply_highlight_app},
    {MENU_ID_VDOPLY_PLAY, mmi_vdoply_highlight_play},
    {MAIN_MENU_MESSAGES_MENUID, highlight_mainmenu_messages},
    {MENU_ID_UM_WRITE_MSG, mmi_um_highlight_write_msg},
    {MENU_ID_UM_INBOX, mmi_um_highlight_inbox},
    {MENU_ID_UM_DRAFT, mmi_um_highlight_draft},
    {MENU_ID_UM_UNSENT, mmi_um_highlight_unsent},
    {MENU_ID_UM_SENT, mmi_um_highlight_sent},
    {MENU_ID_UM_DELETE_MSG_FOLDER, mmi_um_ui_sh_main_msg_entry_del_msg_folder},
    {MENU_ID_UM_SETTING, mmi_um_highlight_setting},
    {MAIN_MENU_FILE_MNGR_MENUID, highlight_mainmenu_filemngr},
    {MAIN_MENU_PHONEBOOK_MENUID, highlight_mainmenu_phonebook},
    {MAIN_MENU_FUNANDGAMES_MENUID, highlight_mainmenu_funandgames},
    {MAIN_MENU_EXTRA_MENUID, highlight_mainmenu_extra},
    {MAIN_MENU_CALL_LOG, highlight_mainmenu_calllog},
    {MAIN_MENU_MULTIMEDIA_MENUID, highlight_mainmenu_multimedia},
    {MAIN_MENU_SERVICES_MENUID, highlight_mainmenu_services},
    {MAIN_MENU_ORGANIZER_MENUID, highlight_mainmenu_organizer},
    {MENU_ID_UCM_CALL_SETTING, mmi_settings_highlight_general_call_setting},
    {MAIN_MENU_SETTINGS_MENUID, highlight_mainmenu_settings},
    {MAIN_MENU_SETTINGS_NO_SIM_MENUID, highlight_mainmenu_settings},
    {MAIN_MENU_WLAN_WIZARD_MENUID, highlight_mainmenu_WiFi_wizard},
    {MAIN_MENU_CALL_CENTER, highlight_mainmenu_callcenter},
    {MAIN_MENU_TOOLSANDFUN_MENUID, highlight_mainmenu_tools},
    {MAIN_MENU_BTDIALER_MENUID, highlight_mainmenu_bt_dialer},
    {MAIN_MENU_SMS_BT_MESSAGES_MENUID, highlight_mainmenu_phonebook},
    {MAIN_MENU_BTNOTIFICATION_MENUID, highlight_mainmenu_btnotification},
    {MAIN_MENU_BTRMTCAP_MENUID, highlight_mainmenu_btrmtcap},
};

const mmi_frm_hint_hdlr_struct mmi_frm_const_hint_hdlr_table[1] = {{0, NULL}};

#endif /* _MENUHANDLER_H */ 
