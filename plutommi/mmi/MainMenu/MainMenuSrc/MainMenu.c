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
 * mainmenu.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for main menu
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
 ****************************************************************************/
/**
 * Copyright Notice
 * ?2002 - 2003, Pixtel Communications, Inc., 1489 43rd Ave. W.,
 * Vancouver, B.C. V6M 4K8 Canada. All Rights Reserved.
 *  (It is illegal to remove this copyright notice from this software or any
 *  portion of it)
 */

/**********************************************************************************
   Filename:      mainmenu.c
   Author:        manju, Vijay Vaidya
   Date Created:  September-07-2002
   Contains:      Main menu application
**********************************************************************************/
#include "MMI_features.h"
#include "AllAppGprot.h"
#include "MainMenuDef.h"
#include "MainMenuProt.h"
#include "SettingGprots.h"
#include "FunAndGamesProts.h"
#include "CallLogGprot.h"
#include "CommonScreens.h"
#include "IdleHomescreenGprot.h"
#include "MMIThemes.h"
#include "GpioSrvGprot.h"
#include "IntellAppMain.h"
#ifdef __MMI_BT_NOTIFICATION__
#include "btnotificationgprot.h"
#endif /* __MMI_BT_NOTIFICATION__ */
#ifdef __MMI_BT_REMOTE_CAPTURE__
#include "BtRmtCapGProt.h"
#endif/*__MMI_BT_REMOTE_CAPTURE__*/

#ifndef __MMI_TELEPHONY_SUPPORT__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
#include "CameraApp.h"
#endif
#if defined(__MMI_IMAGE_VIEWER__)
#include "ImgViewerGprot.h"
#include "ImageViewerGprot.h"
#endif
#if defined(__MMI_VIDEO_PLAYER__)
#include "VdoPlyGProt.h"
#endif
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
#include "VdoRecGProt.h"
#endif
#endif /* __BT_DIALER_PACKAGE__ */
#include "wgui_status_icon_bar.h"
#if defined(__MMI_WEARABLE_DEVICE__) && defined(__MMI_MAINLCD_128X128__)
#include "mmi_rp_app_idle_swatch_def.h"	
#endif /*defined(__MMI_WEARABLE_DEVICE__) && defined(__MMI_MAINLCD_128X128__)*/

#ifndef __MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__

void handle_mainmenu_right_softkey_up(void){}
void highlight_mainmenu_profiles(void){}
void highlight_mainmenu_phonebook(void){}
void highlight_mainmenu_messages(void){}
void highlight_mainmenu_funandgames(void){}
void highlight_mainmenu_organizer(void){}
void highlight_mainmenu_settings(void){}
#ifdef __MMI_MRE_MAIN_MENU__
void highlight_mainmenu_mre(void){}
#endif
#ifndef __DISABLE_SHORTCUTS_IMPL__
void highlight_mainmenu_shortcuts(void){}
#endif 


void highlight_mainmenu_connect(void){}
void highlight_mainmenu_connectivity(void){}
void highlight_mainmenu_services(void){}

#ifdef __MMI_WLAN_FEATURES__
void highlight_mainmenu_WiFi_wizard(void){}
#endif

#if 0
#if (defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)) && defined(WAP_SUPPORT)
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ & WAP_SUPPORT */
/* under construction !*/
#if defined(__OP02__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __OP02_*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#ifdef __OP02_0200__ 
/* under construction !*/
#endif
#endif /* __MMI_MOBILE_SERVICE__ */
/* under construction !*/
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif /* __MMI_MY_FAVORITE__ */
#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ || __MMI_OP02_0100__*/
#endif

void initalize_main_menu_application(void){}
void main_menu_shortcut_executer(S32 index){}
void main_menu_custom_highlight_handler(S32 index){}
void EntryMainMenuFromIdleScreen(void){}
void goto_main_menu(void){}
void mmi_main_menu_entry(void){}
#ifdef __MMI_TELEPHONY_SUPPORT__
void highlight_mainmenu_callcenter(void){}
#endif
void highlight_mainmenu_calllog(void){}
void highlight_mainmenu_multimedia(void){}
void highlight_mainmenu_filemngr(void){}
void highlight_mainmenu_extra(void){}
void EntryMainMultimedia(void){}
void mmi_entry_main_multimedia_screen(void){}
#ifdef __MMI_TELEPHONY_SUPPORT__
void mmi_settings_highlight_general_call_setting(void){}
#endif
void EntryMainExtra(void){}
void mmi_entry_main_extra_screen(void){}

#ifdef __MMI_SUBLCD_MASTER_MODE__

void ExitSubLCDMainMenuScreen(){}
void SubLCDMainMenuScreenHiliteHandler(S32 index){}
void EntrySubLCDMainMenuScreen(){}
U8 EntrySubLCDMainMenu(){}
#endif /* __MMI_SUBLCD_MASTER_MODE__ */
#ifdef __MMI_VUI_3D_MAINMENU__
void mmi_venus_3d_mm_launch_app(void *msgPtr, int mod_src)
#endif


#if 0
#if defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined(__MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ || __MMI_OP02_0100__ */
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_MESSAGES_CLUB__
/* under construction !*/
#endif 
#ifdef __OP01__
#if defined(__OP01_3G__) && defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* under construction !*/
#endif
#ifdef __MMI_139_PUSH_MAIL__
/* under construction !*/
#endif
#ifdef __MMI_MOBILE_VIDEO__
/* under construction !*/
#endif
#ifdef BROWSER_SUPPORT
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
#endif /* __OP01__ */
/* under construction !*/
#if defined(__MMI_OP02_0100__) && defined(WAP_SUPPORT)
/* under construction !*/
#endif /* __MMI_OP02_0100__ & WAP_SUPPORT */
/* under construction !*/
#ifdef __OP02_0200__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __OP02_0200__ */
/* under construction !*/
#ifdef __MMI_OP02_LEMEI__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP01_FWPBW__) */
#endif /* 0 */

#if defined(__MMI_BT_DIALER_SUPPORT__)
void mmi_entry_bt_dialer_application_scr(void){}
void highlight_mainmenu_bt_dialer(void){}
#endif
void EntryMainFileMngr(void){}
void ExitMainFileMngr(void){}

#if 0
#ifdef __MMI_BI_DEGREE_MAIN_MENU_STYLE__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
#endif

void highlight_mainmenu_tools(void){};

#ifndef __MMI_TELEPHONY_SUPPORT__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
void highlight_mainmenu_camera(void) {}
#endif
#if defined(__MMI_IMAGE_VIEWER__)
void highlight_mainmenu_image_viewer(void){}
#endif
#if defined(__MMI_VIDEO_PLAYER__)
void highlight_mainmenu_video_player(void){}
#endif
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
void highlight_mainmenu_video_recorder(void){}
#endif
#endif /* __BT_DIALER_PACKAGE__ */


#else /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/


#include "Service.h"
#ifdef __SAT__
#include "SATGProts.h"
#endif 

#include "FunandGamesProts.h"
#include "MainMenudef.h"
#include "OrganizerGProt.h"
#ifdef __MMI_WLAN_FEATURES__
#include "DataAccountGProt.h"
#endif

#if 0
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
/* under construction !*/
#endif
/* under construction !*/
#ifdef __OP02__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OP02_0200__
/* under construction !*/
#endif
#endif /* __OP02__ */
/* under construction !*/
#endif

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
extern U8 PhnsetGetMainMenuStyle(void);
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */ 

#ifdef __J2ME__
#include "JavaAgencyGProt.h"
#endif

#ifdef __UM_SUPPORT__
#include "UMGProt.h"
#include "mmi_rp_app_unifiedmessage_def.h"
#else
#include "SmsAppGprot.h"
#include "mmi_rp_srv_sms_def.h"
#endif

#include "CallSetGprot.h"

#ifndef __DISABLE_SHORTCUTS_IMPL__
#include "mmi_rp_app_shortcuts_def.h"
#include "ShortcutsGProts.h"
#endif /* __DISABLE_SHORTCUTS_IMPL__ */

#include "stack_msgs.h"
#include "wgui_draw_manager.h"
#include "wgui_categories_enum.h"
#include "CustDataRes.h"
#include "wgui_title.h"
#include "GlobalMenuItems.h"
#include "MessagesMiscell.h"
#include "mmi_frm_queue_gprot.h"
#include "app_ltlcom.h"
#include "stack_config.h"
#include "gui_custom_menus.h"
#include "mmi_rp_app_mainmenu_def.h"
#include "wgui_fixed_menus.h"
#include "FileMgrGProt.h"
#include "SettingGenum.h"
#include "wgui_categories_util.h"
#include "mmi_rp_app_extra_def.h"
#include "GlobalResDef.h"
#include "browser_api.h"
#include "wgui_categories_mm.h"
#include "PhoneSetupGprots.h"

#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
#include "AppMgrSrvGprot.h"
#include "MREAppMgrSrvGprot.h"
#include "AlertScreen.h"
#include "CommonScreensResDef.h"

#ifdef __MMI_USB_SUPPORT__
#include "USBSrvGprot.h"
#endif

#endif 

#ifdef __MMI_LINE_IN__
#include "LineinGprot.h"
#endif
#if defined(__MMI_WEARABLE_DEVICE__)

#include "AppMgrSrvGprot.h"
#include "Watch_barrel.h"
#include "gdi_include.h"
#if !defined(__MMI_MAINMENU_SPREAD_SUPPORT__) && defined(__DELETE_APP_IN_MAINMENU__)
#include "CommonScreensResDef.h"
#endif //__MMI_MAINMENU_SPREAD_SUPPORT__

#ifdef __MMI_MAINLCD_128X32__
static mmi_ret mmi_swatch_mainmenu_enter_proc(mmi_event_struct * evt);
#endif

/*Smart watch mainmenu num*/
//#define SMART_WATCH_MAINMENU_ITEM_NUM 20
#define SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS 20

#if defined(__MMI_MAINLCD_128X128__)

#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD_S 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD_S 3
#define SMART_WATCH_MAINMENU_UP_THRESHOLD_S 40

#define SMART_WATCH_MAINMENU_LEFT_GAP_S 20
#define SMART_WATCH_MAINMENU_TOP_GAP_S 10
#define SMART_WATCH_MAINMENU_CELL1_WIDTH_S 88
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT_S 94
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN_S 5
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S 114
#define SMART_WATCH_MAINMENU_BETWEEN_GAP_S 20
#define SMART_WATCH_MAINMENU_CELL_WIDTH_S 88
#define SMART_WATCH_MAINMENU_CELL_HEIGHT_S 68
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS 5  
#define SMART_WATCH_MAINMENU_ANIM_TIMER 20

#elif defined(__MMI_MAINLCD_320X320__)

#define SMART_WATCH_MAINMENY_INDICATOR_ICON_OFFSETX 145
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_TOP_OFFSETY 2
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_END_OFFSETY 303

#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
#define SMART_WATCH_MAINMENU_ICON_NUM_PAGE 4
#define SMART_WATCH_MAINMENU_CELL_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL_HEIGHT_S 80
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT_S 1 //icon��Ӧapp����ĸ߶�
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_H_S 30
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V_S 29 
#define SMART_WATCH_MAINMENU_FIRST_ICON_OFFSET_X 25
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE_S 28 
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET_S 15
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD_S 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD_S 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD_S 40

#define SMART_WATCH_MAINMENU_LEFT_GAP_S 52
#define SMART_WATCH_MAINMENU_TOP_GAP_S 50
#define SMART_WATCH_MAINMENU_CELL1_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT_S 110
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN_S 1
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S 300
#define SMART_WATCH_MAINMENU_BETWEEN_GAP_S 56
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS_S 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER_S 0

#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH_S 92
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT_S 84
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X_S 5  
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y_S 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*__MMI_FOUR_ICON_MAINMENU*/

#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__)
#define SMART_WATCH_MAINMENU_CELL_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL_HEIGHT 130
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT 15
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V 65
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE 45
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET 1
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD 40

#define SMART_WATCH_MAINMENU_LEFT_GAP 95
#define SMART_WATCH_MAINMENU_TOP_GAP 60
#define SMART_WATCH_MAINMENU_CELL1_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT 195
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN 25
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE 320
#define SMART_WATCH_MAINMENU_BETWEEN_GAP 0
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER 0

#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH 142
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT 134
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X 6 
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*(__MMI_SMART_WATCH_MAINMENU_ONE__)*/

#elif defined(__MMI_MAINLCD_240X320__)  /*240 * 240 Resolution*/
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_OFFSETX 105
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_TOP_OFFSETY 2
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_END_OFFSETY 303  //223

#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
#define SMART_WATCH_MAINMENU_ICON_NUM_PAGE 6
/*Swatch mainmenu layout info*/
#define SMART_WATCH_MAINMENU_CELL_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL_HEIGHT_S 80
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT_S 1 //icon��Ӧapp����ĸ߶�
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_H_S 30
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V_S 29 
#define SMART_WATCH_MAINMENU_FIRST_ICON_OFFSET_X 25
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE_S 28 
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET_S 15
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD_S 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD_S 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD_S 40

#define SMART_WATCH_MAINMENU_LEFT_GAP_S 22
#define SMART_WATCH_MAINMENU_TOP_GAP_S 20
#define SMART_WATCH_MAINMENU_CELL1_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT_S 100
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN_S 1
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S 320
#define SMART_WATCH_MAINMENU_BETWEEN_GAP_S 36
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS_S 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER_S 0
#define SMART_WATCH_MAINMENU_ROW_S  3
#define SMART_WATCH_MAINMENU_COL_S  2



#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH_S 92
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT_S 84
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X_S 5  
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y_S 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*__MMI_FOUR_ICON_MAINMENU*/

#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__)
#define SMART_WATCH_MAINMENU_CELL_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL_HEIGHT 130
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT 15
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V 65
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE 45
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET 1
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD 40

#define SMART_WATCH_MAINMENU_LEFT_GAP 55
#define SMART_WATCH_MAINMENU_TOP_GAP 60 //20
#define SMART_WATCH_MAINMENU_CELL1_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT 195
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN 25
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE 300
#define SMART_WATCH_MAINMENU_BETWEEN_GAP 0
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER 0

#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH 142
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT 134
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X 6 
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*(__MMI_SMART_WATCH_MAINMENU_ONE__)*/

#else /*240 * 240 Resolution*/
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_OFFSETX 105
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_TOP_OFFSETY 2
#define SMART_WATCH_MAINMENY_INDICATOR_ICON_END_OFFSETY 223

#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
#define SMART_WATCH_MAINMENU_ICON_NUM_PAGE 4
/*Swatch mainmenu layout info*/
#define SMART_WATCH_MAINMENU_CELL_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL_HEIGHT_S 80
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT_S 1 //icon��Ӧapp����ĸ߶�
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_H_S 30
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V_S 29 
#define SMART_WATCH_MAINMENU_FIRST_ICON_OFFSET_X 25
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE_S 28 
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET_S 15
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD_S 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD_S 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD_S 40

#define SMART_WATCH_MAINMENU_LEFT_GAP_S 22
#define SMART_WATCH_MAINMENU_TOP_GAP_S 20
#define SMART_WATCH_MAINMENU_CELL1_WIDTH_S 80
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT_S 100
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN_S 1
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S 220
#define SMART_WATCH_MAINMENU_BETWEEN_GAP_S 36
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS_S 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER_S 0
#define SMART_WATCH_MAINMENU_ROW_S  2
#define SMART_WATCH_MAINMENU_COL_S  2

#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH_S 92
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT_S 84
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X_S 5  
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y_S 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*__MMI_FOUR_ICON_MAINMENU*/

#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__)
#define SMART_WATCH_MAINMENU_CELL_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL_HEIGHT 130
#define SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT 15
#define SMART_WATCH_MAINMENU_CELL_DISTANCE_V 65
#define SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE 45
#define SMART_WATCH_MAINMENU_CELL_STRING_OFFSET 1
#define SMART_WATCH_MAINMENU_MOVE_THRESHOLD 40
#define SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD 2
#define SMART_WATCH_MAINMENU_UP_THRESHOLD 40

#define SMART_WATCH_MAINMENU_LEFT_GAP 55
#define SMART_WATCH_MAINMENU_TOP_GAP 20
#define SMART_WATCH_MAINMENU_CELL1_WIDTH 130
#define SMART_WATCH_MAINMENU_CELL1_HEIGHT 195
#define SMART_WATCH_MAINMENU_IMAGE_MARGIN 25
#define SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE 220
#define SMART_WATCH_MAINMENU_BETWEEN_GAP 0
#define SMART_WATCH_MAINMENU_PEN_SWAP_DIS 40  
#define SMART_WATCH_MAINMENU_ANIM_TIMER 0



//add by xl 
#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH 142
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT 134
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X 6 
#define SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y 2
#endif /*__DELETE_APP_IN_MAINMENU__*/
#endif /*(__MMI_SMART_WATCH_MAINMENU_ONE__)*/

#endif

#if defined(__DELETE_APP_IN_MAINMENU__)
#define SMART_WATCH_MAINMENU_DELETE_ICON_WIDTH_S 24
#define SMART_WATCH_MAINMENU_DELETE_ICON_HEIGHT_S 24
#endif /*__DELETE_APP_IN_MAINMENU__*/

#define SMART_WATCH_MAINMENU_LEFT_SLIDE_X_THRESHOLD 20
#define SMART_WATCH_MAINMENU_LEFT_SLIDE_Y_THRESHOLD 20
swatch_mm_struct mainmenu_swatch_list = {0};

#ifdef __MMI_MAINLCD_128X32__
const swatch_icon_map_struct g_mmi_swatch_icon_table_four[]=
{
    {"native.mtk.btdialer", MAIN_MENU_SWATCH_BT_SETTING_ICON},
	{"native.mtk.phonebook", 0},
	{"native.mtk.messaging", 0},
	{"native.mtk.calendar", 0},
	{"native.mtk.setting", 0},  //MAIN_MENU_SWATCH_SETTING_ICON_S
	{"native.mtk.btnotification", 0},
	{"native.mtk.btremotecapture", 0},
    {"native.mtk.bluetooth", 0},
    {"native.mtk.imageviewer",0},
    {"native.mtk.fmrdo", 0},
    {"native.mtk.audioplayerbt", 0},
    {"native.mtk.calllog", 0},
    {"native.mtk.mspace", 0},
    {"native.mtk.profile", 0},
  #if defined(__MTK_TARGET__)
    {"native.mtk.filemgr", 0},
  #else
	{"native.mtk.filemgr", 0},
  #endif
    {"native.mtk.services_sat", 0},
    {"native.mtk.calculator", 0},
    {"native.mtk.alarm", 0},
    {"native.mtk.dialer", 0},
    {"native.mtk.videoplayer", 0},
    {"native.mtk.connectivity", 0},
    {"mtk.native.wallpaper", 0},
    {"native.guobi.winguo", 0},
    {"native.guobi.winguo_net", 0},
    {"native.mtk.fmpapp", 0}
	
};	

#else
#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__)
const swatch_icon_map_struct g_mmi_swatch_icon_table_one[]=
{
	{"native.mtk.btdialer", MAIN_MENU_SWATCH_BT_DIALER_ICON},
	{"native.mtk.phonebook", MAIN_MENU_ARROW_LOC_PHB_ICON},
	{"native.mtk.btphonebook", MAIN_MENU_SWATCH_PHONE_BOOK_ICON},
	{"native.mtk.messaging", MAIN_MENU_ARROW_LOC_MESSAGE_ICON},
	{"native.mtk.btmessaging", MAIN_MENU_SWATCH_MESSAGE_ICON},
	{"native.mtk.calendar", MAIN_MENU_SWATCH_CALENDAR_ICON},
	{"native.mtk.setting", MAIN_MENU_SWATCH_SETTING_ICON},	//MAIN_MENU_SWATCH_SETTING_ICON
	{"native.mtk.btnotification", MAIN_MENU_SWATCH_BT_NOTIFY_ICON},
	{"native.mtk.btremotecapture", MAIN_MENU_SWATCH_BT_RMCP_ICON},
	{"native.mtk.bluetooth", 0},
	{"native.mtk.imageviewer",0},
	{"native.mtk.fmrdo", MAIN_MENU_ARROW_FM_ICON},
	{"native.mtk.audioplayerbt", MAIN_MENU_ARROW_AUDPLY_ICON},
	{"native.mtk.calllog", MAIN_MENU_ARROW_LOC_CALLLOG_ICON},
	{"native.mtk.btcalllog", MAIN_MENU_ARROW_CALLLOG_ICON},
	{"native.mtk.mspace", 0},
	{"native.mtk.profile", 0},

#if defined(__MTK_TARGET__)
	{"native.mtk.filemgr", MAIN_MENU_ARROW_FILEMGR_ICON},
#else
	{"native.mtk.filemgr", MAIN_MENU_ARROW_FILEMGR_ICON},
#endif
	{"native.mtk.services_sat", 0},
	{"native.mtk.calculator", 0},
	{"native.mtk.alarm", MAIN_MENU_ARROW_ALARM_ICON},
#ifdef __MMI_WEARABLE_DEVICE_DIALER__
	{"native.mtk.dialer", MAIN_MENU_ARROW_DIALER_ICON},
#else  /*__MMI_WEARABLE_DEVICE_DIALER__*/
	{"native.mtk.dialer", 0},
#endif /*__MMI_WEARABLE_DEVICE_DIALER__*/
	{"native.mtk.videoplayer", MAIN_MENU_ARROW_VDOPLY_ICON},
	{"native.mtk.connectivity", 0},
	{"mtk.native.wallpaper", 0},
	{"native.guobi.winguo", 0},
	{"native.guobi.winguo_net", 0},
#ifdef __MMI_APP_WITHOUT_LOCAL__
    {"native.mtk.wlan", 0},
#endif
	{"native.mtk.fmpapp", MAIN_MENU_FMP_ICON},
	{"native.mtk.audioplayer", MAIN_MENU_ARROW_LOC_MUSIC_ICON},
    {"native.mtk.vdorec",MAIN_MENU_ARROW_VDOREC_ICON},
    {"native.mtk.camcera",MAIN_MENU_ARROW_CAMERA_ICON},
    {"native.mtk.worldclock",0},
    {"native.mtk.worldclock",0},
    {"native.mtk.sndrec",0}
};
#endif/*__MMI_SMART_WATCH_MAINMENU_ONE__*/

#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
const swatch_icon_map_struct g_mmi_swatch_icon_table_four[]=
{
    {"native.mtk.btdialer", MAIN_MENU_SWATCH_BT_DIALER_ICON_S},
	{"native.mtk.phonebook", MAIN_MENU_ARROW_LOC_PHB_ICON_S},
	{"native.mtk.btphonebook", MAIN_MENU_SWATCH_PHONE_BOOK_ICON_S},
	{"native.mtk.messaging", MAIN_MENU_ARROW_LOC_MESSAGE_ICON_S},
	{"native.mtk.btmessaging", MAIN_MENU_SWATCH_MESSAGE_ICON_S},
	{"native.mtk.calendar", MAIN_MENU_SWATCH_CALENDAR_ICON_S},
	{"native.mtk.setting", MAIN_MENU_SWATCH_SETTING_ICON_S},  //MAIN_MENU_SWATCH_SETTING_ICON_S
	{"native.mtk.btnotification", MAIN_MENU_SWATCH_BT_NOTIFY_ICON_S},
	{"native.mtk.btremotecapture", MAIN_MENU_SWATCH_BT_RMCP_ICON_S},
    {"native.mtk.bluetooth", 0},
    {"native.mtk.imageviewer",0},
    {"native.mtk.fmrdo", MAIN_MENU_ARROW_FM_ICON_S},
    {"native.mtk.audioplayerbt", MAIN_MENU_ARROW_AUDPLY_ICON_S},
    {"native.mtk.calllog", MAIN_MENU_ARROW_LOC_CALLLOG_ICON_S},
    {"native.mtk.btcalllog", MAIN_MENU_ARROW_CALLLOG_ICON_S},
    {"native.mtk.mspace", 0},
    {"native.mtk.profile", 0},
  #if defined(__MTK_TARGET__)
    {"native.mtk.filemgr", MAIN_MENU_ARROW_FILEMGR_ICON_S},
  #else
	{"native.mtk.filemgr", MAIN_MENU_ARROW_FILEMGR_ICON_S},
  #endif
    {"native.mtk.services_sat", 0},
    {"native.mtk.calculator", 0},
    {"native.mtk.alarm", MAIN_MENU_ARROW_ALARM_ICON_S},
   #ifdef __MMI_WEARABLE_DEVICE_DIALER__
    {"native.mtk.dialer", MAIN_MENU_ARROW_DIALER_ICON_S},
   #else /*__MMI_WEARABLE_DEVICE_DIALER__*/
   	{"native.mtk.dialer", 0},
   #endif /*__MMI_WEARABLE_DEVICE_DIALER__*/
    {"native.mtk.videoplayer", MAIN_MENU_ARROW_VDOPLY_ICON_S},
    {"native.mtk.connectivity", 0},
    {"mtk.native.wallpaper", 0},
    {"native.guobi.winguo", 0},
    {"native.guobi.winguo_net", 0},
#ifdef __MMI_APP_WITHOUT_LOCAL__
    {"native.mtk.wlan", 0},
#endif

#ifdef __MMI_HEART_RATE_SUPPORT__
    {"native.mtk.heartrate", MAIN_MENU_HEART_RATE_ICON_S},
#endif

#ifdef __MMI_BLOOD_PRESSURE_SUPPORT__
    {"native.mtk.bloodpressure", MAIN_MENU_BLOOD_PRESSURE_ICON_S},
#endif
    {"native.mtk.fmpapp", MAIN_MENU_FMP_ICON_S},
    {"native.mtk.fmpapp", MAIN_MENU_FMP_ICON_S},
	{"native.mtk.audioplayer", MAIN_MENU_ARROW_LOC_MUSIC_ICON_S},
    {"native.mtk.vdorec",MAIN_MENU_ARROW_VDOREC_ICON_S},
    {"native.mtk.camcera",MAIN_MENU_ARROW_CAMERA_ICON_S},
    {"native.mtk.worldclock",0},
    {"native.mtk.worldclock",0},
    {"native.mtk.sndrec",0}
};	
#endif /*__MMI_SMART_WATCH_MAINMENU_FOUR__*/
#endif
#if defined(__MMI_MAINLCD_128X128__)
const swatch_icon_map_struct g_mmi_small_swatch_icon_table[]=
{
    {"native.mtk.connectivity", IMG_ID_SWATCH_ICON_88_68},
    {"native.mtk.btnotification", IMG_ID_SWATCH_ICON_88_68},
    {"native.mtk.btremotecapture", IMG_ID_SWATCH_ICON_88_68},
    {"native.mtk.audioplayer", IMG_ID_SWATCH_ICON_88_68},
    {"native.mtk.messaging", IMG_ID_SWATCH_ICON_88_68},
    
    {"native.mtk.btdialer", 0},
	{"native.mtk.phonebook", 0},
	{"native.mtk.calendar", 0},
	{"native.mtk.setting", 0},  //MAIN_MENU_SWATCH_SETTING_ICON_S
    {"native.mtk.bluetooth", 0},
    {"native.mtk.imageviewer",0},
    {"native.mtk.fmrdo", 0},
    {"native.mtk.calllog", 0},
    {"native.mtk.mspace", 0},
    {"native.mtk.profile", 0},
  #if defined(__MTK_TARGET__)
    {"native.mtk.filemgr", 0},
  #else
	{"native.mtk.filemgr", 0},
  #endif
    {"native.mtk.services_sat", 0},
    {"native.mtk.calculator", 0},
    {"native.mtk.alarm", 0},
    {"native.mtk.dialer", 0},
    {"native.mtk.videoplayer", 0},
    {"mtk.native.wallpaper", 0},
    {"native.guobi.winguo", 0},
    {"native.guobi.winguo_net", 0}
};

#endif /*__MMI_MAINLCD_128X128__*/

S32 g_mmi_swatch_icon_table_len = 0;
static void mmi_main_menu_entry_swarch_style();

void mmi_swatch_mm_swap_animation(void);
static void mmi_mainmenu_swatch_draw_panel(MMI_BOOL is_blocking);
void mmi_swatch_set_down_flag(void);

#endif /*(__MMI_WEARABLE_DEVICE__)*/

extern void mmi_profiles_entry_main_screen(void);

#ifdef __SAT__
extern void GoToSATMainMenu(void);
#endif

extern U16 gMainMenuTitleIcon[];

extern S32 main_menu_index;
extern S32 MMI_main_menu_type;
extern UI_3D_circular_menu wgui_CM3D_menu;

#if 0
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
/* under construction !*/
#endif 
#endif

#if defined(__MMI_FM_RADIO__) 
extern void mmi_fmrdo_skip_highlight_hdlr(S32 index);   /* defined in FMRadioSrc.c */
extern U16 mmi_fmrdo_check_chip_or_hide(U16 n_items, U16 *string_ids, U16 *icon_ids); /* defined in FMRadioSrc.c */
#endif /* defined(__MMI_FM_RADIO__)  */ 

#ifdef BROWSER_SUPPORT
extern void goto_mobile_suite_screen(void);
#endif

#ifdef __MMI_MRE_MAIN_MENU__
		extern void mmi_mre_start(void);
#endif

void (*MMI_main_menu_lsk_handler) (void);
void (*MMI_main_menu_rsk_handler) (void);


#ifdef __MMI_VUI_MAINMENU__
static void mmi_venus_entry_main_menu_style1(void);
static void mmi_venus_exit_main_menu_style1(void);
#endif

#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
static void mmi_main_menu_entry_spread_matrix_style(void);
static mmi_ret mmi_main_menu_spread_matrix_style_event_handler(mmi_event_struct *event);
#endif


#ifdef __MMI_VUI_3D_MAINMENU__
static void mmi_venus_entry_3d_main_menu(void);
static void mmi_venus_exit_3d_main_menu(void);
#endif

#ifdef __MMI_VUI_LAUNCHER__
extern MMI_ID vapp_drawer_launch(void *param, U32 param_size);
#endif /* __MMI_VUI_LAUNCHER__ */
#ifdef __MMI_VUI_LAUNCHER_KEY__
extern MMI_ID vapp_launcher_mm_launch(void *param, U32 param_size);
#endif

#if 0
#ifdef __MMI_OP02_0100__
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __OP01__
#if defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MOBILE_VIDEO__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif /* __OP01__ */
#endif
static mmi_ret mmi_main_submenu_proc(mmi_event_struct *evt);


#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
static mmi_app_package_name_struct* mmi_mm_app_package_name_list = NULL;
static mmi_app_package_name_struct mmi_mm_app_highlight_item_name;
static srv_app_info_struct* mmi_mm_app_package_info = NULL;

#ifdef __MMI_USB_SUPPORT__
static S32 g_wgui_cat9015_n_items = 0;
#endif

extern void wgui_cat9015_show(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        S32 number_of_items,
        srv_app_info_struct *info,
        S32 highlighted_item,
        U8 *history_buffer);

#endif

/*****************************************************************************
 * FUNCTION
 *  handle_mainmenu_right_softkey_up
 * DESCRIPTION
 *  Go to previous screen when rt soft key
 *  is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void handle_mainmenu_right_softkey_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
}


/*****************************************************************************
 * FUNCTION
 *  set_main_menu_softkey_handler
 * DESCRIPTION
 *  Go to previous screen when rt soft key
 *  is released
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static set_main_menu_softkey_handler(void(*lsk)(void), void(*rsk)(void))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_MAINMENU__
    MMI_main_menu_lsk_handler = lsk;
    MMI_main_menu_rsk_handler = rsk;
    change_left_softkey(NULL, NULL);
    change_right_softkey(NULL, NULL);
    if (lsk)
        SetLeftSoftkeyFunction(lsk, KEY_EVENT_UP);
    if (rsk)
        SetRightSoftkeyFunction(rsk, KEY_EVENT_UP);
 
#else /* __MMI_VUI_MAINMENU__ */
    ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);    

    if (lsk)
    {
        SetLeftSoftkeyFunction(lsk, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(lsk, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(0, 0);
        ChangeCenterSoftkey(0, 0);
        SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
        SetCenterSoftkeyFunction(NULL, KEY_EVENT_UP);
    }

    if (rsk)
    {
        SetRightSoftkeyFunction(rsk, KEY_EVENT_UP);
    }
#endif /* __MMI_VUI_MAINMENU__ */
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_profiles
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 *  
 *  AUTHOR            :Ashima
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_profiles(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(mmi_profiles_entry_main_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_profiles_entry_main_screen, handle_mainmenu_right_softkey_up);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_phonebook
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_phonebook(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(mmi_phb_entry_main_menu, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_phb_entry_main_menu, handle_mainmenu_right_softkey_up);

}

#ifdef __MMI_BT_REMOTE_CAPTURE__
void highlight_mainmenu_btrmtcap(void)
{
    set_main_menu_softkey_handler(mmi_btrmtcap_entry_main_message_menu, handle_mainmenu_right_softkey_up);
}
#endif/*__MMI_BT_REMOTE_CAPTURE__*/

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_messages
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_messages(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

//#ifdef __MOD_SMSAL__
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __UM_SUPPORT__
    set_main_menu_softkey_handler(mmi_um_entry_main_message_menu, handle_mainmenu_right_softkey_up);
#else
	set_main_menu_softkey_handler(mmi_sms_entry_main_message_menu, handle_mainmenu_right_softkey_up);
#endif
#endif
//#endif 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_funandgames
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_funandgames(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(mmi_fng_entry_screen, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_fng_entry_screen, handle_mainmenu_right_softkey_up);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_organizer
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_organizer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(EntryOrganizer, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(EntryOrganizer, handle_mainmenu_right_softkey_up);

}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_settings
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_settings(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha0420 */
    //SetLeftSoftkeyFunction(EntryScrSettingMenu, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(EntryScrSettingMenu, handle_mainmenu_right_softkey_up);

}


#ifdef __MMI_MRE_MAIN_MENU__

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_mre
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_mre(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(appstore_main, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_mre_start, handle_mainmenu_right_softkey_up);
}
#endif


#ifndef __DISABLE_SHORTCUTS_IMPL__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_shortcuts
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_shortcuts(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_main_menu_softkey_handler(mmi_shct_launch_quick_menu_cfg, handle_mainmenu_right_softkey_up);
}
#endif /* __DISABLE_SHORTCUTS_IMPL__ */ 


extern void EntryConnectivityMain(void);
void highlight_mainmenu_connectivity(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/ 
    set_main_menu_softkey_handler(EntryConnectivityMain, handle_mainmenu_right_softkey_up);
}

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_services
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_services(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    /* micha1223 */
#ifdef __MMI_TELEPHONY_SUPPORT__
#ifdef __MMI_MERGE_SAT_TO_MAINMENU__
    /* micha1217 */
#ifndef BROWSER_SUPPORT
    /* micha0601 */
    if (IsSATPresent())
    {
        //SetLeftSoftkeyFunction(GoToSATMainMenu, KEY_EVENT_UP);
        set_main_menu_softkey_handler(GoToSATMainMenu, handle_mainmenu_right_softkey_up);
    }
    else
    {
        //SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
        set_main_menu_softkey_handler(GoToServicesMenu, handle_mainmenu_right_softkey_up);
    }
#else /* BROWSER_SUPPORT */ 
    //SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
    set_main_menu_softkey_handler(GoToServicesMenu, handle_mainmenu_right_softkey_up);
#endif /* BROWSER_SUPPORT */ 

#else /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 

    //SetLeftSoftkeyFunction(GoToServicesMenu, KEY_EVENT_UP);
    set_main_menu_softkey_handler(GoToServicesMenu, handle_mainmenu_right_softkey_up);

#endif /* __MMI_MERGE_SAT_TO_MAINMENU__ */ 
#endif
    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
}

#ifdef __MMI_WLAN_FEATURES__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_WiFi_wizard
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_WiFi_wizard(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(mmi_wlan_entry_wlan_wizard, KEY_EVENT_UP);


    //SetRightSoftkeyFunction(handle_mainmenu_right_softkey_up, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_wlan_entry_wlan_wizard_new, handle_mainmenu_right_softkey_up);

}
#endif

#if 0
#if (defined(__MMI_OP01_MENU_9MATRIX__) || defined(__MMI_OP01_MENU_12MATRIX__)) && defined(BROWSER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
/* under construction !*/
#endif /* BROWSER_SUPPORT */ 
/* under construction !*/
#endif /* __MMI_OP01_MENU_9MATRIX__ & BROWSER_SUPPORT */
/* under construction !*/
#if defined(__MMI_OP02_0100__) && defined(BROWSER_SUPPORT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP02_0100__ && BROWSER_SUPPORT */
/* under construction !*/
#if defined(__OP02__)
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* BROWSER_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  /* BROWSER_SUPPORT */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM_MASTER__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_DUAL_SIM_MASTER__ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_116114__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_116114__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_MOBILE_TV__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_MOBILE_MUSIC__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_PUSH_MAIL__
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP02__) */
/* under construction !*/
/* under construction !*/
#ifdef __MMI_CUSTOMER_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CUSTOMER_SERVICE__ */
/* under construction !*/
#ifdef __MMI_MOBILE_SERVICE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __OP02_0200__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* __MMI_MOBILE_SERVICE__ */
/* under construction !*/
#ifdef __MMI_MY_FAVORITE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_MY_FAVORITE__ */
/* under construction !*/
#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__  || __MMI_OP02_0100__*/
/* under construction !*/
#endif /*0*/
extern void mmi_venus_3d_mm_launch_app(void *msgPtr, int mod_src);

#if defined(__TINY_SYS__)
extern kal_uint8 IRQ_Query_If_Special_Resume(void);
extern kal_bool Is_first_bootup_or_wdt_reset();
#endif


/*****************************************************************************
 * FUNCTION
 *  initalize_main_menu_application
 * DESCRIPTION
 *  Set all highlte handler for main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void initalize_main_menu_application(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MTK_TARGET__) 
    S32 n_items, HighlightMenu, write_len;
    FS_HANDLE bmp_file_handle;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_highlight_handler();
    initialize_mainmenu_title_icons();
#if 0
#if (defined(__MMI_MAINLCD_240X400__)&& !defined(__MMI_VUI_3D_MAINMENU__))
/* under construction !*/
#endif
#endif
#if !defined(__MTK_TARGET__) 
    n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);
    bmp_file_handle = FS_Open((WCHAR*)L"C:\\defaultindex", FS_CREATE_ALWAYS);
    HighlightMenu = 0;

#ifdef __MMI_MAINLCD_320X240__
    if ((n_items / 4) % 2)
    {
        HighlightMenu = (n_items - 1) >> 1;
    }
    else
    {
        HighlightMenu = (n_items - 1 - 4) >> 1;
    }
#else
    if (((n_items + 2)/ 3) % 2)
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1) >> 1;
    }
    else
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1 - 3) >> 1;
    }
#endif

#if 0
#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
/* under construction !*/
#endif /* __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__ */ 
#endif
    FS_Write(bmp_file_handle, (void*)&HighlightMenu, sizeof(S32), &write_len);
    FS_Close(bmp_file_handle);
#endif /*  !defined(__MTK_TARGET__)  */
#ifdef __MMI_VUI_3D_MAINMENU__
    mmi_frm_set_protocol_event_handler(MSG_ID_MMI_3D_MM_LAUNCH_APP_REQ, (PsIntFuncPtr)mmi_venus_3d_mm_launch_app, MMI_FALSE);
#endif

	#if defined(__MMI_WEARABLE_DEVICE__)
	memset(&mainmenu_swatch_list, 0, sizeof(swatch_mm_struct));
	#if defined(__TINY_SYS__)
        if(Is_first_bootup_or_wdt_reset() == KAL_TRUE)
    #else
        if(1)
    #endif
        {
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
        }
        else
        {
            #if defined(__TINY_SYS__)
            if(IRQ_Query_If_Special_Resume() == 1)
            {
                srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            }
		    #endif
        }
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  main_menu_shortcut_executer
 * DESCRIPTION
 *  Shortcut handler to main menu
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_shortcut_executer(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* 
     * When matrix item number > 9, the menu shortcut will fail when going
     * to an invalid index. See fixed_matrix_goto_item().
     */
    if (((MMI_current_menu_type == MATRIX_MENU) || (MMI_current_menu_type == MATRIX_PAGE_MENU) )&&
        (MMI_fixed_matrix_menu.last_highlighted_item == -2))
    {
        return;
    }
    if (MMI_current_menu_type == PAGE_MENU)
    {
        return;
    }
    
    if (index >= 0 && index < n_items)
    {
        execute_left_softkey_function(KEY_EVENT_UP);
    }
}


/*****************************************************************************
 * FUNCTION
 *  main_menu_custom_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void main_menu_custom_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if 0
#if defined (__MMI_MAINMENU_240X400_SUPPORT_MATRIX_PAGE_MENU__) 
/* under construction !*/
#endif
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
/* under construction !*/
#endif 
#endif
    ExecuteCurrHiliteHandler_Ext(index);

#if 0
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_UI_DALMATIAN_SOFTKEYS__ */ 
#endif

#ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__   
    {
    #if 0
    #if !defined(__MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__) && !defined(__MMI_MAINLCD_96X64__) && (!defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINMENU_240X400_SUPPORT_MATRIX_PAGE_MENU__))
/* under construction !*/
    #endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR_ICON__ */
    #else
    #if !defined (__MMI_MAINLCD_96X64__)
        ChangeTitleIcon((U16) gMainMenuTitleIcon[index]);
    #endif
    #endif

        draw_title();
    }
#endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__ */ 

    main_menu_index = index;
#if 0
#if defined (__MMI_MAINMENU_240X400_SUPPORT_MATRIX_PAGE_MENU__) 
/* under construction !*/
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
}


/*****************************************************************************
 * FUNCTION
 *  EntryMainMenuFromIdleScreen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMenuFromIdleScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    goto_main_menu();
}
static mmi_id g_main_menu_group_id;
static void exit_main_menu(void);

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
static S32 mmi_get_mainmenu_attribute(U8 menu_style)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 attributes = MATRIX_MENU;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (menu_style)
    {
#ifdef __MMI_MAINMENU_MATRIX_SUPPORT__  
        case PHNSET_MAINMENU_STYLE_MATRIX:
#if 0
#if defined (__MMI_MAINMENU_240X400_SUPPORT_MATRIX_PAGE_MENU__)
/* under construction !*/
#else
/* under construction !*/
#endif
#else
            attributes = MATRIX_MENU;
#endif
            break;
#endif /* __MMI_MAINMENU_MATRIX_SUPPORT__ */ 

#ifdef __MMI_MAINMENU_PAGE_SUPPORT__    
        case PHNSET_MAINMENU_STYLE_PAGE:
            attributes = PAGE_MENU;
            break;
#endif /* __MMI_MAINMENU_PAGE_SUPPORT__ */ 

#ifdef __MMI_MAINMENU_LIST_SUPPORT__
        case PHNSET_MAINMENU_STYLE_LIST:
            attributes = LIST_MENU;
            break;
#endif /* __MMI_MAINMENU_LIST_SUPPORT__ */ 
        default:
            MMI_ASSERT(0);
            break;
    }
    return attributes;
}
#endif /* __MMI_MAINMENU_STYLE_CHANGE_EN__ */


static U8 mmi_get_mainmenu_highlight_menu(S32 n_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 HighlightMenu = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//#ifdef __MMI_DEFAULT_MAIN_MENU_HIGHLIGHT_MESSAGE__
//    HighlightMenu = (U8)GetChildMenuIDIndexByParentMenuID(IDLE_SCREEN_MENU_ID, MAIN_MENU_MESSAGES_MENUID);

#if defined(__MMI_MAINLCD_320X240__)
    if ((n_items / 4) % 2)
    {
        HighlightMenu = (n_items - 1) >> 1;
    }
    else
    {
        HighlightMenu = (n_items - 1 - 4) >> 1;
    }
#elif defined(__MMI_MAINLCD_96X64__)
	HighlightMenu = 0;
#else
    if (((n_items + 2)/ 3) % 2)
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1) >> 1;
    }
    else
    {
        HighlightMenu = ((((n_items + 2)/ 3) * 3) - 1 - 3) >> 1;
    }
#endif

    return HighlightMenu;
}


#ifdef __MMI_MAINMENU_SPREAD_SUPPORT__
static void mmi_main_menu_launch_app(void);
static void mmi_main_menu_uninstall_app(void);
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_proc
 * DESCRIPTION
 *  main menu group proc
 * PARAMETERS
 *  evt  [IN] event
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret mmi_main_menu_proc(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINMENU_SPREAD_SUPPORT__
    MMI_BOOL closeMenu = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINMENU_SPREAD_SUPPORT__
	switch(evt->evt_id)
	{
		case EVT_ID_CUI_MENU_LIST_ENTRY:
		{
			break;
		}
		case EVT_ID_CUI_MENU_ITEM_SELECT:
		{
			cui_menu_event_struct *event = (cui_menu_event_struct *)evt;

            if (event->highlighted_menu_id == MENU_ID_MAIN_MENU_OPTIONS_OPEN)
            {
                mmi_main_menu_launch_app();
            }
            else if (event->highlighted_menu_id == MENU_ID_MAIN_MENU_OPTIONS_UNINSTALLED)
            {
                mmi_main_menu_uninstall_app();
            }

			break;
		}
		case EVT_ID_CUI_MENU_CLOSE_REQUEST:
		{
			cui_menu_event_struct *event = (cui_menu_event_struct *)evt;
			
			cui_menu_close(event->sender_id);
			break;
		}
		default:
			break;
	}
#endif
#ifdef __MMI_WEARABLE_DEVICE__
		switch(evt->evt_id)
		{
			case EVT_ID_TOUCHSCREEN_MOVE_RIGHT:
				if(mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_H)
				{
					return MMI_RET_ERR;
				}
				break;
			default:
				break;
		}
#endif

    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
        case EVT_ID_GROUP_DEINIT:
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  goto_main_menu
 * DESCRIPTION
 *  Lanch the main menu group
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void goto_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VUI_LAUNCHER__
#ifdef __MMI_VUI_LAUNCHER_KEY__
	if(mmi_phnset_launcher_get_launcher_type() == MMI_PHNSET_LAUNCHER_KEY)
        vapp_launcher_mm_launch(NULL, 0);
	else
#endif
    vapp_drawer_launch(NULL, 0);
    return;
#endif /* __MMI_VUI_LAUNCHER__ */

#if defined(__INTELL_MOB_TER_APP__)
    intellapp();
	return;
#endif /* 给自己定义的函数一个路径，在主菜单中声明这个宏定义 */

#ifdef __MMI_VUI_LAUNCHER_KEY__
    vapp_launcher_mm_launch(NULL, 0);
    return;
#endif
    g_main_menu_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_menu_proc, NULL);

    mmi_frm_group_enter(g_main_menu_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_main_menu_entry();
}

#define TYPE(A)	TYPE_(A)
#define TYPE_(A) A##_MENU


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_entry
 * DESCRIPTION
 *  Display the main menu.
 *  
 *  This a entry function for the main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_main_menu_entry(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    MMI_ID_TYPE mm_stringIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs[MAX_MAIN_MENU_ITEMS];

    U8 *history_buffer;
    S32 n_items;
    S32 attributes;
    U8 HighlightMenu = 0;

    MMI_ID_TYPE *iconList;
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 menu_style = 0;
#endif
    MMI_ID_TYPE mm_iconIDs_display[MAX_MAIN_MENU_ITEMS];
    U8 i = 0;
    MMI_MENU_ID mmi_menuitem_list[MAX_MAIN_MENU_ITEMS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_main_menu_group_id, MAIN_MENU_SCREENID, exit_main_menu, mmi_main_menu_entry, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
#ifdef __MMI_VUI_3D_MAINMENU__

	mmi_venus_entry_3d_main_menu();
	return;

#elif defined(__MMI_VUI_MAINMENU__)
    mmi_venus_entry_main_menu_style1();
    return;

#elif defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    mmi_main_menu_entry_spread_matrix_style();
    return;

#elif defined(__MMI_WEARABLE_DEVICE__)
	mmi_main_menu_entry_swarch_style();
	return;

#endif  /* __MMI_VUI_3D_MAINMENU__ */

    gui_sse_setup_scenario(GUI_SSE_SCENARIO_ENTER_MAINMENU);

#if 0
#if defined( __MMI_OP12_MENU_12MATRIX__)
    #ifdef __SAT__
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
#endif

    history_buffer = mmi_frm_scrn_get_active_gui_buf();
    n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);
    GetSequenceStringIds_Ext(IDLE_SCREEN_MENU_ID, mm_stringIDs);
    GetSequenceImageIds_Ext(IDLE_SCREEN_MENU_ID, mm_iconIDs);
    SetParentHandler(IDLE_SCREEN_MENU_ID);
    attributes = TYPE(__MMI_MAINMENU_TYPE__);

    HighlightMenu = mmi_get_mainmenu_highlight_menu(n_items);

#if defined(__MMI_BT_DIALER_SUPPORT__) 
    HighlightMenu = 0;
#endif

#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    menu_style = PhnsetGetMainMenuStyle();
    attributes = mmi_get_mainmenu_attribute(menu_style);
//#elif (defined(__OPTR_NONE__) && defined(__MMI_MAINMENU_240X400_SUPPORT_MATRIX_PAGE_MENU__))
//	if(attributes == MATRIX_MENU)
//		attributes = MATRIX_PAGE_MENU;
#endif
    GetSequenceItemIds_Ext(IDLE_SCREEN_MENU_ID, mmi_menuitem_list);
    switch (attributes)
    {
        //case MATRIX_PAGE_MENU:
        case MATRIX_MENU:
            {
                for (i = 0; i < n_items; i++)
                {
                    mm_iconIDs_display[i] = mmi_res_get_mainmenu_img(mmi_menuitem_list[i], MMI_RG_MM_IMG_MATRIX);
                }
                iconList = mm_iconIDs_display;
                break;
            }
        case PAGE_MENU:
            {
                for (i = 0; i < n_items; i++)
                {
                    mm_iconIDs_display[i] = mmi_res_get_mainmenu_img(mmi_menuitem_list[i], MMI_RG_MM_IMG_PAGE);
                }
                iconList = mm_iconIDs_display;
                break;
            }
        case LIST_MENU:
            {
                for (i = 0; i < n_items; i++)
                {
                    mm_iconIDs_display[i] = mmi_res_get_mainmenu_img(mmi_menuitem_list[i], MMI_RG_MM_IMG_LIST);
                }
                iconList = mm_iconIDs_display;
                break;
            }
        default:
            iconList = mm_iconIDs;
            break;
    }
 
    RegisterHighlightHandler(main_menu_custom_highlight_handler);
#if 0
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
/* under construction !*/
#endif 
#endif

#if defined(__MMI_MAINLCD_128X64__)
	wgui_cat9014_show(
        STR_GLOBAL_OK,
        STR_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        HighlightMenu,
        (U8*) history_buffer);
#else /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 
    ShowCategory14Screen(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mm_stringIDs,
        iconList,
        attributes,
        HighlightMenu,
        (U8*) history_buffer);
#endif /* __MMI_BI_DEGREE_MAIN_MENU_STYLE__ */ 

    register_menu_shortcut_selected(main_menu_shortcut_executer);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  exit_main_menu
 * DESCRIPTION
 *  Store the  snap shot
 *  before displaying next screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void exit_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_handle handler;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_frm_scrn_add_history(g_main_menu_group_id, MAIN_MENU_SCREENID);

#ifdef __MMI_VUI_MAINMENU__    
    mmi_venus_exit_main_menu_style1();
    return;
#endif
#ifdef __MMI_VUI_3D_MAINMENU__
	mmi_venus_exit_3d_main_menu();
    return;
#endif
    /* unhide possible hidden menus in order to keep compatibility to other screens */
    mmi_frm_unhide_menu_item(MAIN_MENU_EXTRA_MENUID);
    mmi_frm_unhide_menu_item(MAIN_MENU_MULTIMEDIA_MENUID);
    mmi_frm_unhide_menu_item(MAIN_MENU_FUNANDGAMES_MENUID);

    /* Re-initialize title icons since the MM category modifies gMainMenuTitleIcon[]. */
    // TODO: If items are different in selectable MMs, GetRootTitleIcon() may go wrong.
    initialize_mainmenu_title_icons();

#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
    if (mmi_mm_app_package_name_list)
    {
        mmi_frm_scrmem_free(mmi_mm_app_package_name_list);
        mmi_mm_app_package_name_list = NULL;
    }
    if (mmi_mm_app_package_info)
    {
        mmi_frm_scrmem_free(mmi_mm_app_package_info);
        mmi_mm_app_package_info = NULL;
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, mmi_main_menu_spread_matrix_style_event_handler, NULL);

#endif

#if defined(__MMI_WEARABLE_DEVICE__)
    StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
	//gui_cancel_timer(mmi_swatch_mm_swap_animation);
	mainmenu_swatch_list.end_anim_pos = -100;

	gdi_layer_get_base_handle(&handler);
    if(handler == mainmenu_swatch_list.panel_layer_handle)
    {
        gdi_layer_free(mainmenu_swatch_list.base_layer);
    }
	else
	{
	    gdi_layer_free(mainmenu_swatch_list.panel_layer_handle);
	}
	
	
	//mmi_frm_asm_free_anonymous(mainmenu_swatch_list.layer_buffer);
	#ifndef __MMI_MAINLCD_128X32__
	gdi_layer_free(mainmenu_swatch_list.status_icon_layer);
	mmi_frm_asm_free_anonymous(mainmenu_swatch_list.status_bar_buf_ptr);
	#endif
	
	if(mainmenu_swatch_list.cache_ptr != NULL)
	{
	    mmi_frm_asm_free_anonymous(mainmenu_swatch_list.cache_ptr);
		mainmenu_swatch_list.cache_ptr = NULL;
	}
	WriteValueSlim(NVRAM_MAINMENU_HIGHLIGHT_INDEX, &mainmenu_swatch_list.highlight_index, DS_DOUBLE);
	gui_cancel_timer(mmi_swatch_set_down_flag);
	mainmenu_swatch_list.pen_click = MMI_FALSE;
	mainmenu_swatch_list.show_down_highlight = MMI_FALSE;
	mainmenu_swatch_list.page_index = -1;
    #if (defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))
    mmi_pen_config_sampling_period(MMI_PEN_SAMPLING_PERIOD_1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_move_offset(
        MMI_PEN_SKIP_MOVE_OFFSET,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        MMI_PEN_SKIP_LONGTAP_OFFSET,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);
    #endif /* __MMI_TOUCH_SCREEN__ */ 

	#ifdef __MMI_MAINLCD_128X32__
	mmi_frm_cb_dereg_event(EVT_ID_KEY_CLICK_SINGLE, mmi_swatch_mainmenu_enter_proc, NULL);
	#endif
	
#endif

}


#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
mmi_ret mmi_main_update(mmi_event_struct* evt)
{
    if(evt->evt_id == EVT_ID_SRV_APPMGR_UPDATE_INSTALLED_PACKAGE)
    {
        if(mmi_frm_scrn_get_active_id() == MAIN_MENU_SCREENID)
        {              
            exit_main_menu();           
            mmi_main_menu_entry();            
        }               
    }
    return MMI_RET_OK;    
}
#endif


#ifdef __MMI_TELEPHONY_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_callcenter
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_callcenter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_main_menu_softkey_handler(mmi_callset_call_center_launch, handle_mainmenu_right_softkey_up);
}
#endif


#if defined(__MMI_TELEPHONY_SUPPORT__) || defined(__MMI_BT_PBAP_CLIENT__)
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_calllog
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_calllog(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     set_main_menu_softkey_handler(mmi_clog_launch, mmi_frm_scrn_close_active_id);
}
#endif /* __MMI_TELEPHONY_SUPPORT__ || __MMI_BT_PBAP_CLIENT__ */


#if 0
/* under construction !*/
#if defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __SAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __SAT__ */
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_multimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_multimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(EntryMainMultimedia, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    set_main_menu_softkey_handler(EntryMainMultimedia, handle_mainmenu_right_softkey_up);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_filemngr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_filemngr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);

#ifdef __MMI_FILE_MANAGER__
    //SetLeftSoftkeyFunction(mmi_fmgr_launch, KEY_EVENT_UP);
    set_main_menu_softkey_handler(mmi_fmgr_launch, handle_mainmenu_right_softkey_up);

#else /* __MMI_FILE_MANAGER__ */ 

    //SetLeftSoftkeyFunction(NULL, KEY_EVENT_UP);
    set_main_menu_softkey_handler(NULL, handle_mainmenu_right_softkey_up);
    ClearKeyHandler(KEY_RIGHT_ARROW, KEY_EVENT_DOWN);
#endif /* __MMI_FILE_MANAGER__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_extra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_extra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //ChangeLeftSoftkey(STR_GLOBAL_OK, IMG_GLOBAL_OK);
    //ChangeRightSoftkey(STR_GLOBAL_BACK, IMG_GLOBAL_BACK);

    //SetLeftSoftkeyFunction(EntryMainExtra, KEY_EVENT_UP);
    //SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    set_main_menu_softkey_handler(EntryMainExtra, handle_mainmenu_right_softkey_up);
}

static mmi_id g_tools_group_id;

/*****************************************************************************
 * FUNCTION
 *  mmi_entry_main_tools_screen
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_entry_main_tools_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;
	U16 menu_item_id;
	U16 menu_text_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_tools_group_id, SCR_EXTRA, NULL, mmi_entry_main_tools_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
#if 0
#ifndef __DISABLE_SHORTCUTS_MENU__
#if defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __DISABLE_SHORTCUTS_MENU__ */
#endif

    /* For matrix 3x3, when support bt dialer, not support MRE, merge Fools and Fun to 'Tools & Fun' */
#if defined(__MMI_TELEPHONY_SUPPORT__) && defined(__MMI_BT_DIALER_SUPPORT__) && (defined(__MMI_MAINLCD_176X220__) || defined(__MMI_MAINLCD_240X320__)) && !defined(__MMI_MRE_MAIN_MENU__) 
	menu_item_id = MAIN_MENU_TOOLSANDFUN_MENUID;
	menu_text_id = MAIN_MENU_TOOLSANDFUN_TEXT;
#else
	menu_item_id = MAIN_MENU_TOOLS_MENUID;
	menu_text_id = MAIN_MENU_TOOLS_TEXT;
#endif

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = GetNumOfChild_Ext(menu_item_id);
    GetSequenceStringIds_Ext(menu_item_id, ItemList);
    GetSequenceImageIds_Ext(menu_item_id, ItemIcons);
    SetParentHandler(menu_item_id);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	wgui_list_menu_enable_access_by_shortcut();
    if (nItems == 0)
    {
        ShowCategory52Screen(
            menu_text_id,
            GetRootTitleIcon(menu_item_id),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            ItemList,
            ItemIcons,
            0,
            0,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory52Screen(
            menu_text_id,
            GetRootTitleIcon(menu_item_id),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            ItemList,
            ItemIcons,
            0,
            0,
            0,
            guiBuffer);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}

/*****************************************************************************
 * FUNCTION
 *  EntryMainExtra
 * DESCRIPTION
 *  entry extra app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void EntryMainTools(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_tools_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_submenu_proc, NULL);
     mmi_frm_group_enter(g_tools_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     mmi_entry_main_tools_screen();
}

/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_tools
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_tools(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    set_main_menu_softkey_handler(EntryMainTools, handle_mainmenu_right_softkey_up);
}


/* Max: temporary define here, shall be moved to each application file */

#define SCR_FILE_MANAGER   SCR_ID_FILE_MANAGER
#define SCR_MMEDIA         SCR_ID_MMEDIA
#define SCR_CAMERA         SCR_ID_CAMERA 

#if 0
#if defined(__MMI_OP01_MENU_NOSIM_LIST__) || defined(__MMI_OP02_0100__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FM_RADIO__)
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_FM_RADIO__)  */ 
/* under construction !*/
#endif /* defined(__MMI_FM_RADIO__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP01_MENU_NOSIM_LIST__ || __MMI_OP02_0100__ */
#endif

static mmi_id g_media_group_id;
static mmi_ret mmi_main_submenu_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_GROUP_ACTIVE:
        case EVT_ID_GROUP_INACTIVE:
        case EVT_ID_GROUP_DEINIT:
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}
static void mmi_main_multimedia_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FuncPtr lsk_handler = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_FM_RADIO__)
    mmi_fmrdo_skip_highlight_hdlr(index);
#else
    ExecuteCurrHiliteHandler(index);
#endif
    lsk_handler = get_softkey_function(KEY_EVENT_UP,MMI_LEFT_SOFTKEY);
    if(lsk_handler)
    {
        ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
        SetCenterSoftkeyFunction(lsk_handler, KEY_EVENT_UP);
    }
}
/*****************************************************************************
 * FUNCTION
 *  EntryMainMultimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainMultimedia(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_media_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_submenu_proc, NULL);
     mmi_frm_group_enter(g_media_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     mmi_entry_main_multimedia_screen();
}


/*****************************************************************************
 * FUNCTION
 *  EntryMainMultimedia
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_main_multimedia_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_media_group_id, SCR_MMEDIA, NULL, mmi_entry_main_multimedia_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }
    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = GetNumOfChild_Ext(MAIN_MENU_MULTIMEDIA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_MULTIMEDIA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_MULTIMEDIA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);

#if defined(__MMI_FM_RADIO__)
    RegisterHighlightHandler(mmi_main_multimedia_highlight_hdlr);
    nItems = mmi_fmrdo_check_chip_or_hide(nItems, ItemList, ItemIcons);
#else /* defined(__MMI_FM_RADIO__) */ 
    RegisterHighlightHandler(mmi_main_multimedia_highlight_hdlr);
#endif /* defined(__MMI_FM_RADIO__) */ 

#if defined(__MMI_LINE_IN__)
    nItems = mmi_linein_check_plug_in_or_hide(nItems, ItemList, ItemIcons);
#endif  //defined(__MMI_LINE_IN__)

	wgui_list_menu_enable_access_by_shortcut();
    ShowCategory52Screen(
        MAIN_MENU_MMEDIA_TEXT,
        GetRootTitleIcon(MAIN_MENU_MULTIMEDIA_MENUID),
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        nItems,
        ItemList,
        ItemIcons,
        0,
        0,
        0,
        guiBuffer);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}


#ifdef __MMI_TELEPHONY_SUPPORT__
//#if defined(__MMI_OP11_MENU_12MATRIX__) || defined(__MMI_OP12_MENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_12MATRIX__) || defined(__MMI_OP02_MAINMENU_9MATRIX__)
/*****************************************************************************
 * FUNCTION
 *  mmi_settings_highlight_general_call_setting
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_settings_highlight_general_call_setting(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body */
    /*----------------------------------------------------------------*/
//#ifndef __COSMOS_MMI_PACKAGE__
    SetLeftSoftkeyFunction(mmi_callset_call_setting_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction(GoBackHistory, KEY_EVENT_UP);
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_callset_call_setting_launch, KEY_EVENT_UP);
//#endif /* __COSMOS_MMI_PACKAGE__ */
}
//#endif
#endif

#if 0
#if defined( __MMI_OP11_MENU_12MATRIX__) || defined( __MMI_OP12_MENU_12MATRIX__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FM_RADIO__)
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_FM_RADIO__) 
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_FM_RADIO__) */ 
/* under construction !*/
#endif /* defined(__MMI_FM_RADIO__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

static mmi_id g_extra_group_id;

/*****************************************************************************
 * FUNCTION
 *  EntryMainExtra
 * DESCRIPTION
 *  entry extra app
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void EntryMainExtra(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
     g_extra_group_id = mmi_frm_group_create(GRP_ID_ROOT, GRP_ID_AUTO_GEN, mmi_main_submenu_proc, NULL);
     mmi_frm_group_enter(g_extra_group_id, MMI_FRM_NODE_SMART_CLOSE_FLAG);
     mmi_entry_main_extra_screen();
}
/*****************************************************************************
 * FUNCTION
 *  EntryMainExtra
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_entry_main_extra_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 ItemList[MAX_SUB_MENUS];
    U16 ItemIcons[MAX_SUB_MENUS];
    U16 nItems;
    U8 *guiBuffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(mmi_frm_scrn_enter(g_extra_group_id, SCR_EXTRA, NULL, mmi_entry_main_extra_screen, MMI_FRM_FULL_SCRN) == MMI_FALSE)
    {
        return;
    }

#if 0
#ifndef __DISABLE_SHORTCUTS_MENU__
#if defined(__MMI_OP11_HOMESCREEN_0302__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* __DISABLE_SHORTCUTS_MENU__ */
#endif

    guiBuffer = mmi_frm_scrn_get_active_gui_buf();
    nItems = GetNumOfChild_Ext(MAIN_MENU_EXTRA_MENUID);
    GetSequenceStringIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemList);
    GetSequenceImageIds_Ext(MAIN_MENU_EXTRA_MENUID, ItemIcons);
    SetParentHandler(MAIN_MENU_EXTRA_MENUID);
    RegisterHighlightHandler(ExecuteCurrHiliteHandler);
	wgui_list_menu_enable_access_by_shortcut();
    if (nItems == 0)
    {
        ShowCategory52Screen(
            MAIN_MENU_EXTRA_TEXT,
            GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID),
            0,
            0,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            ItemList,
            ItemIcons,
            0,
            0,
            0,
            guiBuffer);
    }
    else
    {
        ShowCategory52Screen(
            MAIN_MENU_EXTRA_TEXT,
            GetRootTitleIcon(MAIN_MENU_EXTRA_MENUID),
            STR_GLOBAL_OK,
            IMG_GLOBAL_OK,
            STR_GLOBAL_BACK,
            IMG_GLOBAL_BACK,
            nItems,
            ItemList,
            ItemIcons,
            0,
            0,
            0,
            guiBuffer);
    }
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


#ifdef __MMI_SUBLCD_MASTER_MODE__
static U16	main_menu_hilited_index = 0;

/*****************************************************************************
 * FUNCTION
 *  ExitSubLCDMainMenuScreen
 * DESCRIPTION
 *  Exit SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void ExitSubLCDMainMenuScreen()
{
    main_menu_hilited_index = 0;
    ForceEntrySubLCDSlave();
    GoBackHistory();
    /*
     * At the function EntrySubLCDMasterFromIdle(), we may freeze subLCD to avoid update subLCD when interrupt occurs.
     * When exit subLCD main menu screen, we will unfreeze the subLCD.
     */
    UI_set_sub_LCD_graphics_context();
    gdi_lcd_freeze(FALSE);
    UI_set_main_LCD_graphics_context();
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void SubLCDMainMenuScreenHiliteHandler(S32 index)
{
    main_menu_hilited_index = index;
    ExecuteCurrHiliteHandler(index);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenuScreen
 * DESCRIPTION
 *  Entry SubLCD MainMenu Screen
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
void EntrySubLCDMainMenuScreen()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 numOfItems = 0;
    U16 itemList[MAX_SUB_MENUS];
    U16 itemIcon[MAX_SUB_MENUS];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();
    DinitSubLCDHistory();
	ClearAllKeyHandler();
	
    SetParentHandler(MENU_ID_SUB_MAIN_MENU);

    numOfItems = GetNumOfChild_Ext(MENU_ID_SUB_MAIN_MENU);

    GetSequenceStringIds_Ext(MENU_ID_SUB_MAIN_MENU, itemList);
    GetSequenceImageIds_Ext(MENU_ID_SUB_MAIN_MENU, itemIcon);

    RegisterHighlightHandler(SubLCDMainMenuScreenHiliteHandler);

	
    ShowCategory314Screen(
        (U8*)GetString(MAIN_MENU_MENU_TEXT),
        0, 
        numOfItems,
        itemList,
        itemIcon,
        NULL, 
        main_menu_hilited_index,
        NULL);

    SetKeyHandler( ExitSubLCDMainMenuScreen, KEY_FWD, KEY_EVENT_UP);
}


/*****************************************************************************
 * FUNCTION
 *  EntrySubLCDMainMenu
 * DESCRIPTION
 *  Entry SubLCD MainMenu
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
U8 EntrySubLCDMainMenu()
{
    if (SetSubLCDInMasterMode())
    {
        DisplaySubLCDScreen(SUB_MAIN_MENU_SCREENID, EntrySubLCDMainMenuScreen, TRUE);
    	return TRUE;		
    }
    return FALSE;	
}

#endif /* __MMI_SUBLCD_MASTER_MODE__ */


#ifdef __MMI_VUI_MAINMENU__
extern void vadp_p2v_main_menu_style1_entry(void);
extern void vadp_p2v_main_menu_style1_exit(void);


/*****************************************************************************
 * FUNCTION
 *  mmi_venus_entry_main_menu_style1
 * DESCRIPTION
 *  Display the style 1 main menu.
 *  
 *  This a entry function for the main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_venus_entry_main_menu_style1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_screen_switch_effect_block(MMI_TRUE); // avoid sse conflict with entry effect 
    vadp_p2v_main_menu_style1_entry();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_venus_exit_main_menu_style1
 * DESCRIPTION
 *  Exit the style 1 main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_venus_exit_main_menu_style1(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vadp_p2v_main_menu_style1_exit();
}

#endif

#ifdef __MMI_VUI_3D_MAINMENU__
extern void vadp_p2v_3d_main_menu_exit(void);
extern void vadp_p2v_3d_main_menu_entry(void);

/*****************************************************************************
 * FUNCTION
 *  mmi_venus_entry_main_menu_style1
 * DESCRIPTION
 *  Display the style 1 main menu.
 *  
 *  This a entry function for the main menu
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_venus_entry_3d_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vadp_p2v_3d_main_menu_entry();
	MMI_main_menu_rsk_handler = mmi_frm_scrn_close_active_id;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_venus_exit_main_menu_style1
 * DESCRIPTION
 *  Exit the style 1 main menu.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

static void mmi_venus_exit_3d_main_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	vadp_p2v_3d_main_menu_exit();
	MMI_main_menu_rsk_handler = NULL;
}


void mmi_venus_3d_mm_launch_app(void *msgPtr, int mod_src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    mmi_3d_mm_launch_app_req_struct * req_ptr = (mmi_3d_mm_launch_app_req_struct*)msgPtr;

    FuncPtr launch_func = mmi_res_get_mainmenu_launch_handler(req_ptr->menu_id);

    U8 result = 1;

    mmi_3d_mm_launch_app_rsp_struct *local;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if(launch_func)
        launch_func();
    else
        result = 0;
	local = (mmi_3d_mm_launch_app_rsp_struct *)mmi_construct_msg_local_para(sizeof(mmi_3d_mm_launch_app_rsp_struct));
    local->result = result;
    
	mmi_frm_send_ilm(MOD_L4C, MSG_ID_MMI_3D_MM_LAUNCH_APP_RSP, (local_para_struct *)local, NULL);
}
#endif

#if 0
#ifdef __OP01__
#if defined(__OP01_3G__) && defined(__MMI_MOBILE_TV_CMMB_SUPPORT__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
#ifdef __MMI_139_PUSH_MAIL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifdef __MMI_MOBILE_VIDEO__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
  #ifdef __MMI_VUI_SHELL_OP01_HOMESCREEN__
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
  #endif /* __MMI_VUI_SHELL_OP01_HOMESCREEN__ */
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_MUSIC__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_FETION__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_STOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_MAP__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_MM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP01_HS_MIDLET_CMREAD__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#endif /* __OP01__ */
/* under construction !*/
#ifdef __OP02_0200__
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_MIDLET_WO_STORE__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#ifdef BROWSER_SUPPORT
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* __OP02_0200__ */
/* under construction !*/
/* under construction !*/
#ifdef __MMI_OP02_LEMEI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_OP02_LEMEI__ */
/* under construction !*/
/* under construction !*/
#if defined(__OP01_FWPBW__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__OP01_FWPBW__) */
/* under construction !*/
#endif /*0*/

#if defined(__MMI_BT_DIALER_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_entry_bt_dialer_application_scr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
extern U16 mmi_btdialer_app_launch_func(void *param, U32 param_size);
void mmi_entry_bt_dialer_application_scr(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
        
    mmi_btdialer_app_launch_func(NULL, 0);
}


/*****************************************************************************
 * FUNCTION
 *  highlight_mainmenu_bt_dialer
 * DESCRIPTION
 *  Associate the key handler
 *  with left and rt soft key
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void highlight_mainmenu_bt_dialer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    set_main_menu_softkey_handler(mmi_entry_bt_dialer_application_scr, handle_mainmenu_right_softkey_up);
}
#endif /*#if defined(__MMI_BT_DIALER_SUPPORT__)*/

#ifndef __MMI_TELEPHONY_SUPPORT__
#if defined (__MMI_CAMERA__) && !defined(__MMI_CAMCORDER__)
void highlight_mainmenu_camera(void)
{
    set_main_menu_softkey_handler(mmi_camera_lauch, handle_mainmenu_right_softkey_up);
}
#endif
#if defined(__MMI_IMAGE_VIEWER__)
void highlight_mainmenu_image_viewer(void)
{
    set_main_menu_softkey_handler(mmi_imgview_launch, handle_mainmenu_right_softkey_up);
}
#endif
#if defined(__MMI_VIDEO_PLAYER__)
void highlight_mainmenu_video_player(void)
{
    set_main_menu_softkey_handler(mmi_vdoply_entry_app, handle_mainmenu_right_softkey_up);
}
#endif
#if defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__)
void highlight_mainmenu_video_recorder(void)
{
    set_main_menu_softkey_handler(mmi_vdorec_lauch, handle_mainmenu_right_softkey_up);
}
#endif
#endif /* __BT_DIALER_PACKAGE__ */


#if defined(__MMI_MAINMENU_SPREAD_SUPPORT__)
/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_launch_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_launch_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_appmgr_launch(mmi_mm_app_highlight_item_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_uninstall_app_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:
			mmi_frm_scrn_close_active_id();
			return;

        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            break;
    }

    mmi_popup_property_init(&popup_property);
    popup_property.f_auto_dismiss = MMI_TRUE;
    popup_property.parent_id  = GRP_ID_ROOT;
    mmi_popup_display_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, &popup_property);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_uninstall_confirm_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_main_menu_uninstall_confirm_proc(mmi_alert_result_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_popup_property_struct popup_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt->evt_id == EVT_ID_ALERT_QUIT)
    {
        switch (evt->result)
        {
            case MMI_ALERT_CNFM_YES:
                mmi_popup_property_init(&popup_property);
                popup_property.f_auto_dismiss = MMI_FALSE;
                popup_property.parent_id = GRP_ID_ROOT;
                mmi_popup_display_ext(STR_GLOBAL_PLEASE_WAIT, MMI_EVENT_PROGRESS, &popup_property);

                
                if (srv_appmgr_uninstall_app(mmi_mm_app_highlight_item_name, mmi_main_menu_uninstall_app_callback, NULL) == MMI_RET_ERR)
                {
                    mmi_popup_property_init(&popup_property);
                    popup_property.f_auto_dismiss = MMI_TRUE;
                    popup_property.parent_id = GRP_ID_ROOT;
                    mmi_popup_display_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, &popup_property);
                }
            	break;
            	
            case MMI_ALERT_CNFM_NO:
            	break;
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_uninstall_app
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_uninstall_app(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_bg_running = MMI_FALSE;
    mmi_popup_property_struct popup_property;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(strncmp(mmi_mm_app_highlight_item_name, "mre", 3) == 0)
	{
		is_bg_running = srv_mre_appmgr_is_bg_running(mmi_mm_app_highlight_item_name);
	}

	if(is_bg_running)
	{
        mmi_popup_property_init(&popup_property);
        popup_property.f_auto_dismiss = MMI_TRUE;
        popup_property.parent_id = GRP_ID_ROOT;
        mmi_popup_display_ext(STR_ID_MAIN_MENU_EXIT_RUNNING_APP, MMI_EVENT_FAILURE, &popup_property);
	}
	else
	{
        mmi_confirm_property_struct confirmProperty;
        mmi_confirm_property_init(&confirmProperty, CNFM_TYPE_YESNO);
        confirmProperty.callback = (mmi_proc_func)mmi_main_menu_uninstall_confirm_proc;
        confirmProperty.parent_id = GRP_ID_ROOT; 
        confirmProperty.f_auto_question_mark = MMI_TRUE;

        mmi_confirm_display_ext(
            STR_ID_MAIN_MENU_UNINSTALL,
            MMI_EVENT_QUERY,
            &confirmProperty);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_option_menu
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void       
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_option_menu(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id menu_gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    menu_gid = cui_menu_create(
                g_main_menu_group_id,
                CUI_MENU_SRC_TYPE_RESOURCE,
                CUI_MENU_TYPE_OPTION,
                MAIN_MENU_OPTIONS_MENU,
                MMI_TRUE,
                NULL);
	cui_menu_enable_cascading_option_menu(menu_gid);
    cui_menu_run(menu_gid);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_spread_matrix_style_highlight_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_spread_matrix_style_highlight_handler(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL is_installed = MMI_FALSE;
    mmi_app_package_name_struct *installed_app_list = NULL;
    U32 installed_app_num = 0;
    mmi_ret result;
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* is installed app or not */
    if (strncmp(mmi_mm_app_package_name_list[index], "native", 5) != 0)
	{
		installed_app_num = srv_appmgr_get_app_package_num(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE);
		if (installed_app_num)
		{
            installed_app_list = mmi_frm_scrmem_alloc(installed_app_num * sizeof(mmi_app_package_name_struct));
            memset(installed_app_list, 0, installed_app_num * sizeof(mmi_app_package_name_struct));

			result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE, installed_app_list, installed_app_num);
			MMI_ASSERT(result != MMI_RET_ERR);

		    if (installed_app_list)
		    {
                for (i = 0; i < installed_app_num; ++i)
                {
                    if (strncmp(mmi_mm_app_package_name_list[index], installed_app_list[i], MMI_APP_NAME_MAX_LEN) == 0)
                    {
                        is_installed = MMI_TRUE;
                    }
                }
		    }

            if (installed_app_list)
	        {
		        mmi_frm_scrmem_free(installed_app_list);
		        installed_app_list = NULL;
	        }
        }
	}

    /* set softkey */
    if (is_installed)
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPTIONS, 0);
        SetLeftSoftkeyFunction(mmi_main_menu_option_menu, KEY_EVENT_UP);
    }
    else
    {
        ChangeLeftSoftkey(STR_GLOBAL_OPEN, 0);
        SetLeftSoftkeyFunction(mmi_main_menu_launch_app, KEY_EVENT_UP);
    }
    ChangeCenterSoftkey(0, IMG_GLOBAL_COMMON_CSK);
    SetCenterSoftkeyFunction(mmi_main_menu_launch_app, KEY_EVENT_UP);

#ifndef __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__   
    /* set title */
    ChangeTitle(0, (U8*)mmi_mm_app_package_info[index].string);
    draw_title();
#endif /* __MMI_MATRIX_MAIN_MENU_NO_TITLEBAR__ */ 

    main_menu_index = index;
    strncpy(mmi_mm_app_highlight_item_name, mmi_mm_app_package_name_list[index], MMI_APP_NAME_MAX_LEN - 1);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_spread_matrix_style_event_handler
 * DESCRIPTION
 *  
 * PARAMETERS
 *  index       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_main_menu_spread_matrix_style_event_handler(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, n_items;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    n_items = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE) + srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);

    switch (event->evt_id)
    {
		case EVT_ID_SRV_APPMGR_UPDATE_BADGE:
            {
                for (i = 0; i < n_items; i++)
                {
                    if(MMI_RET_ERR == srv_appmgr_get_app_package_info(mmi_mm_app_package_name_list[i], &mmi_mm_app_package_info[i]))
		            {
			            memset(&mmi_mm_app_package_info[i], 0, sizeof(srv_app_info_struct));
			            n_items--;
		            }
                }
                show_fixed_matrix();
            }
            break;
        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_entry_spread_matrix_style
 * DESCRIPTION
 *  main meun entry function
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_entry_spread_matrix_style(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID_TYPE mm_stringIDs[MAX_MAIN_MENU_ITEMS];
    MMI_ID_TYPE mm_iconIDs[MAX_MAIN_MENU_ITEMS];

    U8 *history_buffer;
    S32 n_items, pre_installed_n_items, fixed_n_items, reserved_n_items = 0;
    U8 HighlightMenu = 0;

    MMI_ID_TYPE *iconList;
#ifdef __MMI_MAINMENU_STYLE_CHANGE_EN__
    U8 menu_style = 0;
#endif
    MMI_ID_TYPE mm_iconIDs_display[MAX_MAIN_MENU_ITEMS];
    U8 i = 0;
    MMI_MENU_ID mmi_menuitem_list[MAX_MAIN_MENU_ITEMS];
    mmi_app_package_name_struct* temp_app_name = NULL;
    S32 nor_native_item_num = 0;
    mmi_app_package_name_struct* mre_list = NULL;
    S32 mre_num = 0;
    S32 exchange = 1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_sse_setup_scenario(GUI_SSE_SCENARIO_ENTER_MAINMENU);

    history_buffer = mmi_frm_scrn_get_active_gui_buf();
    n_items = GetNumOfChild_Ext(IDLE_SCREEN_MENU_ID);
    GetSequenceStringIds_Ext(IDLE_SCREEN_MENU_ID, mm_stringIDs);
    GetSequenceImageIds_Ext(IDLE_SCREEN_MENU_ID, mm_iconIDs);
    SetParentHandler(IDLE_SCREEN_MENU_ID);

    HighlightMenu = mmi_get_mainmenu_highlight_menu(n_items);

    GetSequenceItemIds_Ext(IDLE_SCREEN_MENU_ID, mmi_menuitem_list);

    for (i = 0; i < n_items; i++)
    {
        mm_iconIDs_display[i] = mmi_res_get_mainmenu_img(mmi_menuitem_list[i], MMI_RG_MM_IMG_MATRIX);
    }
    iconList = mm_iconIDs_display;

    RegisterHighlightHandler(mmi_main_menu_spread_matrix_style_highlight_handler);

#if 0
#ifdef __MMI_UI_DALMATIAN_SOFTKEYS__
/* under construction !*/
#endif
#endif

    fixed_n_items = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
    pre_installed_n_items  = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    n_items = fixed_n_items + pre_installed_n_items;

#ifdef __MMI_USB_SUPPORT__
    if (srv_usb_is_in_mass_storage_mode())
    {
        if (n_items < g_wgui_cat9015_n_items)
        {
            reserved_n_items = g_wgui_cat9015_n_items - n_items;
        }
    }
    else
    {
        g_wgui_cat9015_n_items = n_items;
    }
#endif 

    if(mmi_mm_app_package_name_list == NULL)
    {
        mmi_mm_app_package_name_list = mmi_frm_scrmem_alloc((n_items + reserved_n_items) * sizeof(mmi_app_package_name_struct));
        memset(mmi_mm_app_package_name_list, 0, (n_items + reserved_n_items) * sizeof(mmi_app_package_name_struct));
    }
    if (mmi_mm_app_package_info == NULL)
    {
        mmi_mm_app_package_info = mmi_frm_scrmem_alloc((n_items + reserved_n_items) * sizeof(srv_app_info_struct));
        memset(mmi_mm_app_package_info, 0, (n_items + reserved_n_items) * sizeof(srv_app_info_struct));
    }

    /* re-order */
    if (temp_app_name == NULL)
    {
        temp_app_name = mmi_frm_scrmem_alloc((n_items + reserved_n_items) * sizeof(mmi_app_package_name_struct));
        memset(temp_app_name, 0, (n_items + reserved_n_items) * sizeof(mmi_app_package_name_struct));
    }

    srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE, mmi_mm_app_package_name_list, fixed_n_items);

    for (i = 0; i < fixed_n_items; i++) 
    {
        if (strncmp(mmi_mm_app_package_name_list[i], "native", 5) != 0)
        {
            memcpy(&temp_app_name[fixed_n_items - nor_native_item_num - 1], &mmi_mm_app_package_name_list[i], sizeof(mmi_app_package_name_struct));
            nor_native_item_num++;
        }
        else
        {
            memcpy(&mmi_mm_app_package_name_list[0], &mmi_mm_app_package_name_list[i], (fixed_n_items - nor_native_item_num)*sizeof(mmi_app_package_name_struct));
            memcpy(&mmi_mm_app_package_name_list[fixed_n_items - nor_native_item_num], &temp_app_name[fixed_n_items - nor_native_item_num], (nor_native_item_num)*sizeof(mmi_app_package_name_struct));
            break;
        }
    }

    srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE, &mmi_mm_app_package_name_list[fixed_n_items], pre_installed_n_items);

    for (i = 0; i < n_items; i++)
    {
        if (strncmp(mmi_mm_app_package_name_list[i], "mre.shortcut", 12) == 0)
        {
            if (mre_num == 0)
            {
                mre_list = &mmi_mm_app_package_name_list[i];
                break;
            }
        }
    }

    if (mmi_mm_app_package_name_list)
    {
        mre_num = n_items - i;
    }

    while(exchange)
    {
        exchange = 0;

        for (i = 0; i < mre_num - 1; i++)
        {
            if (strcmp(mre_list[i], mre_list[i + 1]) > 0)
            {
                memcpy(&temp_app_name[0], &mre_list[i], sizeof(mmi_app_package_name_struct));
                memcpy(&mre_list[i], &mre_list[i + 1], sizeof(mmi_app_package_name_struct));
                memcpy(&mre_list[i + 1], &temp_app_name[0], sizeof(mmi_app_package_name_struct));
                exchange = 1;
            }
        }
    }

    for (i = 0; i < n_items; i++)
    {
        if(MMI_RET_ERR == srv_appmgr_get_app_package_info(mmi_mm_app_package_name_list[i], &mmi_mm_app_package_info[i]))
        {
            memset(&mmi_mm_app_package_info[i], 0, sizeof(srv_app_info_struct));
            n_items--;
        }
    }

    if (temp_app_name)
    {
        mmi_frm_scrmem_free(temp_app_name);
        temp_app_name = NULL;
    }

    wgui_cat9015_show(
        MAIN_MENU_TITLE_TEXT,
        MAIN_MENU_TITLE_ICON,
        STR_GLOBAL_OK,
        IMG_GLOBAL_OK,
        STR_GLOBAL_BACK,
        IMG_GLOBAL_BACK,
        n_items,
        mmi_mm_app_package_info,
        HighlightMenu,
        (U8*) history_buffer);

    mmi_frm_cb_reg_event(EVT_ID_SRV_APPMGR_UPDATE_BADGE, mmi_main_menu_spread_matrix_style_event_handler, NULL);

    register_menu_shortcut_selected(main_menu_shortcut_executer);
    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);

}
#endif

#if defined(__MMI_WEARABLE_DEVICE__)

S8 highlight_index = 0;

/*Mainmenu default order*/
mmi_app_package_name_struct g_mmi_watch_default_order[] = 
{
    "native.mtk.btnotification",
	"native.mtk.fmpapp",
    "native.mtk.phonebook",
	"native.mtk.dialer",
	"native.mtk.calllog",
	"native.mtk.messaging",
	"native.mtk.alarm",
	"native.mtk.btremotecapture",
	"native.mtk.btdialer",
	"native.mtk.calendar",
	"native.mtk.audioplayerbt",
	"native.mtk.setting",
	"native.mtk.camcera"
	"native.mtk.vdorec",
	"native.mtk.btmessaging",
	"native.mtk.btphonebook",
	"native.mtk.filemgr",
	"native.mtk.videoplayer",
	"native.mtk.audioplayer",
	"native.mtk.btcalllog",
};

const S32 mmi_watch_default_order_count = sizeof(g_mmi_watch_default_order) / sizeof(mmi_app_package_name_struct);


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_get_swatch_image_id
 * DESCRIPTION
 *  swatch mainmenu get image id
 * PARAMETERS
 *  package_id   [IN]  
 *  icon             [IN]
 * RETURNS
 *  S16
 *****************************************************************************/
S16 mmi_mainmenu_get_swatch_image_id(U32 package_id, MMI_ID *icon)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_app_package_name_struct app_name;
	WCHAR app_name2[100];
	S32 i;
	MMI_ID new_icon = 0;
	MMI_RET result;
	CHAR *last_backlash;
	S16 result_icon = 0;
	//mmi_app_package_name_struct app_icon_name;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	result = srv_appmgr_get_app_package_name_by_id(package_id, app_name);

	MMI_ASSERT(result != MMI_RET_ERR);
    
	for(i = 0; i < g_mmi_swatch_icon_table_len; i ++)
    {
        if(strncmp((CHAR *)app_name, mainmenu_swatch_list.icon_table[i].app_name, MMI_APP_NAME_MAX_LEN) == 0)
        {
            new_icon = mainmenu_swatch_list.icon_table[i].image_icon;
			if(new_icon == 0)
			{
				result_icon = 0;
				return result_icon;
			}
			else
			{
				result_icon = 1;
				*icon = new_icon;
            	return result_icon;
			}
        }
    }

	result_icon = 2;
    return result_icon;
}


#if defined(__DELETE_APP_IN_MAINMENU__)
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_is_installed_app
 * DESCRIPTION
 * mainmenu check is installed app
 * PARAMETERS
 *  app_id 	[IN]
 * RETURNS
 * MMI_BOOL
 *****************************************************************************/
MMI_BOOL mmi_swatch_is_installed_app(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < mainmenu_swatch_list.install_app_num; i++)
    {
        if (mainmenu_swatch_list.install_app_array[i] == app_id)
            return MMI_TRUE;
    }
    return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_uninstall_app_proc
 * DESCRIPTION
 * mainmenu uninstall app proc
 * PARAMETERS
 *  evt 	[IN]
 * RETURNS
 * static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_swatch_uninstall_app_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_close_active_id();
    return MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_uninstall_app_callback
 * DESCRIPTION
 * mainmenu uninstall app callback
 * PARAMETERS
 *  result 		[IN]
 *  user_data  [IN]
 * RETURNS
 * static void
 *****************************************************************************/
static void mmi_swatch_uninstall_app_callback(srv_appmgr_cb_event_enum result, void *user_data)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_event_struct evt;
    mmi_popup_property_struct popup_ctx;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_APPMGR_CB_EVENT_DONE:
        {
            MMI_FRM_INIT_EVENT(&evt, 0);
            mmi_frm_post_event(&evt, mmi_swatch_uninstall_app_proc, 0);
            return;
        }            
        case SRV_APPMGR_CB_EVENT_ERROR:
        case SRV_APPMGR_CB_EVENT_CANCEL:
        default:
            break;
    }
    popup_ctx.parent_id  = GRP_ID_ROOT;
    mmi_popup_display_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, &popup_ctx);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_uninstall_confirm_proc
 * DESCRIPTION
 * mainmenu uninstall confirm proc
 * PARAMETERS
 *  evt 		[IN]
  * RETURNS
 * static mmi_ret
 *****************************************************************************/
static mmi_ret mmi_swatch_uninstall_confirm_proc(mmi_event_struct *evt)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *confirm_evt = NULL;
    mmi_app_package_name_struct app_name = {0};
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_ASSERT(evt);
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            confirm_evt = (mmi_alert_result_evt_struct*)evt;
            
            switch (confirm_evt->result)
            {
                case MMI_ALERT_CNFM_OK:
                case MMI_ALERT_CNFM_YES:
                {
   					mmi_popup_property_struct popup_property;
    				mmi_popup_property_init(&popup_property);
                    popup_property.parent_id  = GRP_ID_ROOT;
                    mmi_popup_display_ext(STR_ID_SWATCH_APP_UNINSTALLING, MMI_EVENT_PROGRESS, &popup_property);                    
                    srv_appmgr_get_app_package_name_by_id(mainmenu_swatch_list.package_info_array[mainmenu_swatch_list.highlight_index], app_name);
                
                    if (srv_appmgr_uninstall_app(app_name, mmi_swatch_uninstall_app_callback, NULL) == MMI_RET_ERR)
                    {
                    	mmi_popup_display_ext(STR_GLOBAL_FAILED, MMI_EVENT_FAILURE, &popup_property);   
                    }
                    break;
                }
                default:
                	break;
            }
        }
    }

    return  MMI_RET_OK;
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_uninstall_app
 * DESCRIPTION
 * mainmenu uninstall app
 * PARAMETERS
 *  void
  * RETURNS
 * void
 *****************************************************************************/
void mmi_swatch_uninstall_app(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	mmi_app_package_name_struct package_name;
	MMI_RET result;
	MMI_BOOL is_bg_running = MMI_FALSE;
	srv_app_info_struct info;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	result = srv_appmgr_get_app_package_name_by_id(mainmenu_swatch_list.package_info_array[mainmenu_swatch_list.highlight_index], package_name);
	MMI_ASSERT(result != MMI_RET_ERR);
	if(strncmp(package_name, "mre", 3) == 0)
	{
		is_bg_running = srv_mre_appmgr_is_bg_running(package_name);
	}
#if defined(__J2ME__)
	else if (strncmp(package_name, "java", 4) == 0)
	{
		is_bg_running = srv_java_appfactory_is_app_running(package_name);
	}
#endif
	if(is_bg_running)
	{
		mmi_popup_property_struct arg;
		mmi_popup_property_init(&arg);  
		arg.parent_id = GRP_ID_ROOT; 
		mmi_popup_display_ext(STR_ID_SWATCH_APP_IS_RUNNING, MMI_EVENT_FAILURE, &arg);
	}
	else
	{
		WCHAR display_str[255] = {0};
		mmi_confirm_property_struct confirm_property;

		mmi_confirm_property_init(&confirm_property, CNFM_TYPE_YESNO);
		confirm_property.callback = (mmi_proc_func)mmi_swatch_uninstall_confirm_proc;
		confirm_property.parent_id  = GRP_ID_ROOT;
		
		result = srv_appmgr_get_app_package_info(package_name, &info);
		MMI_ASSERT(result != MMI_RET_ERR);
		kal_wsprintf(display_str, "%w %w \0\?\0 ", GetString(STR_ID_SWATCH_APP_UNINSTALL), info.string);

		mmi_confirm_display(
		display_str,
		MMI_EVENT_CONFIRM,
		&confirm_property);
	}
}

#endif /*__DELETE_APP_IN_MAINMENU__*/


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_get_swatch_package_list
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
 static void mmi_mainmenu_get_swatch_package_list()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 fixed_n_items, pre_installed_n_items, n_items, page_nums, i,j;
	mmi_app_package_name_struct * array = NULL;
	MMI_RET result;
	srv_app_info_struct info;
	U32 package_id;
	S32 icon_index = 0;
	MMI_ID icon_image;
	S16 result_icon;
	S32 page_count, icon_num, row_num, row_index;
	MMI_BOOL found = MMI_FALSE;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*Get App Info*/
	fixed_n_items = srv_appmgr_get_app_package_num(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE);
    pre_installed_n_items  = srv_appmgr_get_app_package_num(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE);
    n_items = fixed_n_items + pre_installed_n_items;

	array = mmi_frm_asm_alloc_anonymous(n_items * sizeof(mmi_app_package_name_struct));

	result = srv_appmgr_get_app_package_list(SRV_APPMGR_PRE_INSTALLED_APP_PACKAGE_FLAG_TYPE,
											 array,
											 pre_installed_n_items);
	MMI_ASSERT(result != MMI_RET_ERR);

	result = srv_appmgr_get_app_package_list(SRV_APPMGR_ALL_APP_PACKAGE_IN_MAIN_MENU_FLAG_TYPE,
											 array + pre_installed_n_items,
											 fixed_n_items);
	MMI_ASSERT(result != MMI_RET_ERR);

	/*Add for mainmenu order*/
	for(j = 0; j < mmi_watch_default_order_count; j++)
	{
	    found = MMI_FALSE;
	    for(i = 0; i < n_items; i++)
	    {
	        if(strncmp((CHAR *)g_mmi_watch_default_order[j], array[i], MMI_APP_NAME_MAX_LEN) == 0)
	        {
	            found = MMI_TRUE;
				break;
	        }
	    }

		if(found == MMI_TRUE)
		{
		    result = srv_appmgr_get_app_package_info(g_mmi_watch_default_order[j], &info);
			package_id = srv_appmgr_get_id_by_app_package_name(g_mmi_watch_default_order[j]);
			result_icon = mmi_mainmenu_get_swatch_image_id(package_id, &icon_image);
			if(result_icon != 0)
			{
			    mainmenu_swatch_list.panel_cell[icon_index].image_type = info.image.type;
			    mainmenu_swatch_list.panel_cell[icon_index].app_id = package_id;
			    switch(mainmenu_swatch_list.panel_cell[icon_index].image_type)
			    {
			        case MMI_IMAGE_SRC_TYPE_RES_ID:
					    mainmenu_swatch_list.panel_cell[icon_index].image.res_id = icon_image;
					    break;
				    case MMI_IMAGE_SRC_TYPE_PATH:
					    mmi_ucs2cpy((CHAR *)mainmenu_swatch_list.panel_cell[icon_index].image.path,
						            (CHAR *)info.image.data.path);
					    break;
				    case MMI_IMAGE_SRC_TYPE_MEM:
					    mainmenu_swatch_list.panel_cell[icon_index].image_len = info.image.data.image.image_len;
					    mainmenu_swatch_list.panel_cell[icon_index].image_ptr = info.image.data.image.image_ptr;
					    break;
				    default:
					    ASSERT(0);
					    break;
			    }

			    page_count = icon_index / mainmenu_swatch_list.mainmenu_page_num;
			    icon_num   = icon_index % mainmenu_swatch_list.mainmenu_page_num;

                #ifdef __MMI_MAINLCD_128X32__
				row_index = icon_num % 4;
			    row_num = 0;
                mainmenu_swatch_list.panel_cell[icon_index].pos.x = 
				    mainmenu_swatch_list.left_gap + row_index * (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap) + mainmenu_swatch_list.cell_width/2; 
				//SWATCH_MAINMENU_CELL_GAP + page_count * SWATCH_MAINMENU_PAGE_WIDTH + row_index * SWATCH_MAINMENU_CELL_WIDTH + SWATCH_MAINMENU_CELL_WIDTH/2;

                mainmenu_swatch_list.panel_cell[icon_index].pos.y = 
                    mainmenu_swatch_list.top_gap + page_count * mainmenu_swatch_list.page_size + row_num * mainmenu_swatch_list.cell_height+ mainmenu_swatch_list.cell_height/2;
				
				#else
			    row_index = icon_num % SMART_WATCH_MAINMENU_COL_S;
			    row_num = icon_num / SMART_WATCH_MAINMENU_COL_S;

                mainmenu_swatch_list.panel_cell[icon_index].pos.x = 
				    mainmenu_swatch_list.left_gap + row_index * (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap) + mainmenu_swatch_list.cell_width/2; 

                mainmenu_swatch_list.panel_cell[icon_index].pos.y = 
                    mainmenu_swatch_list.top_gap + page_count * mainmenu_swatch_list.page_size + row_num * mainmenu_swatch_list.cell_height+ mainmenu_swatch_list.cell_height/2;    
                #endif
				
                mmi_ucs2cpy((CHAR *)mainmenu_swatch_list.panel_cell[icon_index].string,
						    (CHAR *)info.string);
			
			    icon_index++;
			}
		}
	}


	for(i = 0; i < n_items ; i++)
	{
		package_id = srv_appmgr_get_id_by_app_package_name(array[i]);

		result_icon = mmi_mainmenu_get_swatch_image_id(package_id, &icon_image);

		for(j = 0; j < mmi_watch_default_order_count; j++)
		{
		    found = MMI_TRUE;
		    if(strncmp((CHAR *)g_mmi_watch_default_order[j], array[i], MMI_APP_NAME_MAX_LEN) == 0)
	        {
	            found = MMI_FALSE;
				break;
	        }
		}

		if(result_icon != 0 && found == MMI_TRUE)
		{	
		    result = srv_appmgr_get_app_package_info(array[i], &info);
			mainmenu_swatch_list.panel_cell[icon_index].image_type = info.image.type;
			mainmenu_swatch_list.panel_cell[icon_index].app_id = package_id;
			switch(mainmenu_swatch_list.panel_cell[icon_index].image_type)
			{
			    case MMI_IMAGE_SRC_TYPE_RES_ID:
					mainmenu_swatch_list.panel_cell[icon_index].image.res_id = icon_image;
					break;
				case MMI_IMAGE_SRC_TYPE_PATH:
					mmi_ucs2cpy((CHAR *)mainmenu_swatch_list.panel_cell[icon_index].image.path,
						        (CHAR *)info.image.data.path);
					break;
				case MMI_IMAGE_SRC_TYPE_MEM:
					mainmenu_swatch_list.panel_cell[icon_index].image_len = info.image.data.image.image_len;
					mainmenu_swatch_list.panel_cell[icon_index].image_ptr = info.image.data.image.image_ptr;
					break;
				default:
					ASSERT(0);
					break;
			}

			page_count = icon_index / mainmenu_swatch_list.mainmenu_page_num;
			icon_num   = icon_index % mainmenu_swatch_list.mainmenu_page_num;

            #ifdef __MMI_MAINLCD_128X32__
		    row_index = icon_num % 4;
			row_num = 0;
            mainmenu_swatch_list.panel_cell[icon_index].pos.x = 
				mainmenu_swatch_list.left_gap + row_index * (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap) + mainmenu_swatch_list.cell_width/2; 

            mainmenu_swatch_list.panel_cell[icon_index].pos.y = 
                mainmenu_swatch_list.top_gap + page_count * mainmenu_swatch_list.page_size + row_num * mainmenu_swatch_list.cell_height+ mainmenu_swatch_list.cell_height/2;
				
			#else

			row_index = icon_num % SMART_WATCH_MAINMENU_COL_S;
			row_num = icon_num / SMART_WATCH_MAINMENU_COL_S;

            mainmenu_swatch_list.panel_cell[icon_index].pos.x = 
				mainmenu_swatch_list.left_gap + row_index * (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap) + mainmenu_swatch_list.cell_width/2; 

            mainmenu_swatch_list.panel_cell[icon_index].pos.y = 
                mainmenu_swatch_list.top_gap + page_count * mainmenu_swatch_list.page_size + row_num * mainmenu_swatch_list.cell_height+ mainmenu_swatch_list.cell_height/2;    

			#endif

            mmi_ucs2cpy((CHAR *)mainmenu_swatch_list.panel_cell[icon_index].string,
						(CHAR *)info.string);
			
			icon_index++;
		}
	}

	if (icon_index < mainmenu_swatch_list.total_icon_num)// has app uninstall
	{
		//ajust pen move offset 
		if (0 == mainmenu_swatch_list.swatch_mm_style)
	 	{
	 		if (mainmenu_swatch_list.prevpen_move_offset > ((icon_index-1) * mainmenu_swatch_list.page_size))
	 		{
	 			mainmenu_swatch_list.prevpen_move_offset =  (icon_index-1) * mainmenu_swatch_list.page_size;
	 		}
	 	}
		else if(1 == mainmenu_swatch_list.swatch_mm_style)
		{
			page_nums = icon_index / mainmenu_swatch_list.mainmenu_page_num - 1;
			if (0 != icon_index % mainmenu_swatch_list.mainmenu_page_num)
			{
				page_nums++;
			}
			if ((page_nums * mainmenu_swatch_list.page_size) < mainmenu_swatch_list.prevpen_move_offset)
			{
				mainmenu_swatch_list.prevpen_move_offset = page_nums * mainmenu_swatch_list.page_size;
	 		}
		}
	}
	mainmenu_swatch_list.total_icon_num = icon_index;

	mmi_frm_asm_free_anonymous(array);

    #ifdef __MMI_MAINLCD_128X32__
	if(highlight_index >= mainmenu_swatch_list.total_icon_num)
	{
	    highlight_index = 0;
	}
	#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_pen_point_in_launch_area
 * DESCRIPTION
 *  main meun check pen up point area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/

S32 mmi_swatch_pen_point_in_launch_area(S32 pos_x, S32 pos_y)
{
	#if (defined(__MMI_TOUCH_SCREEN__) && !defined(__TOUCH_PANEL_CAPACITY__))
	U8 title_height = 0;
	
	if(0 == mainmenu_swatch_list.swatch_mm_style) //Only for 4 icon
	{
        title_height = Get_CharHeightOfAllLang(MMI_medium_font.size); //get medium font size
	}
	else if(1 == mainmenu_swatch_list.swatch_mm_style)
	{
		title_height = Get_CharHeightOfAllLang(MMI_small_font.size); //get medium font size
	}
	#endif /*(defined(__MMI_TOUCH_SCREEN__) && !defined(__TOUCH_PANEL_CAPACITY__))*/
	#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__) 
	if (0 == mainmenu_swatch_list.swatch_mm_style) //one icon type
	{
		#if (defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))
	    if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.cell_width &&
	       pos_y > mainmenu_swatch_list.top_gap &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height)
	    {
	        return 0;
	    }
		else
		{
		    return -1;
		}
		#elif (defined(__MMI_TOUCH_SCREEN__) && !defined(__TOUCH_PANEL_CAPACITY__))
		if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width&&
	       pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset + 
	       mainmenu_swatch_list.icon_height + 2 + title_height)
		{
			return 0;
		}
		else
		{
			return -1;
		}
		 #endif /*(defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))*/
	}
    #endif
	#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
	if(1 == mainmenu_swatch_list.swatch_mm_style) //four icon type
	{
	    #if defined(__MMI_MAINLCD_240X240__)
		#if (defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))
	    if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	       pos_y > mainmenu_swatch_list.top_gap &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height)
	    {
	        return 0;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2)&&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) * 2 &&
	            pos_y > mainmenu_swatch_list.top_gap && 
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height)
	    {
	        return 1;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2)
	    {
	        return 2;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2)
	    {
	        return 3;
	    }
	    else
	    {
	        return -1;
	    }
		#elif (defined(__MMI_TOUCH_SCREEN__) && !defined(__TOUCH_PANEL_CAPACITY__))
		 if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width &&
	       pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 0;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap)&&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap/2) * 2 &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset &&
	       		pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 1;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 2;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 3;
	    }
	    else
	    {
	        return -1;
	    }
		#endif /*(defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))*/
        #else
        #if (defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))
	    if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	       pos_y > mainmenu_swatch_list.top_gap &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height)
	    {
	        return 0;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2)&&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) * 2 &&
	            pos_y > mainmenu_swatch_list.top_gap && 
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height)
	    {
	        return 1;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2)
	    {
	        return 2;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2)
	    {
	        return 3;
	    }
        else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2 &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 3)
	    {
	        return 4;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.cell_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 2 &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height * 3)
	    {
	        return 5;
	    }
	    else
	    {
	        return -1;
	    }
		#elif (defined(__MMI_TOUCH_SCREEN__) && !defined(__TOUCH_PANEL_CAPACITY__))
		 if(pos_x > mainmenu_swatch_list.left_gap &&
	       pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width &&
	       pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset &&
	       pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 0;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap)&&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap/2) * 2 &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset &&
	       		pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 1;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 2;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height)
	    {
	        return 3;
	    }
        else if(pos_x > mainmenu_swatch_list.left_gap &&
	            pos_x < mainmenu_swatch_list.left_gap + mainmenu_swatch_list.icon_width &&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + + mainmenu_swatch_list.image_offset + (mainmenu_swatch_list.icon_height + title_height)*2)
	    {
	        return 4;
	    }
	    else if(pos_x > mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap) &&
	            pos_x < mainmenu_swatch_list.left_gap + (mainmenu_swatch_list.icon_width + mainmenu_swatch_list.between_gap/2) * 2&&
	            pos_y > mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + title_height &&
	            pos_y < mainmenu_swatch_list.top_gap + mainmenu_swatch_list.cell_height + mainmenu_swatch_list.image_offset + (mainmenu_swatch_list.icon_height + title_height)*2)
	    {
	        return 5;
	    }
	    else
	    {
	        return -1;
	    }
		#endif /*(defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))*/
        #endif
	}
	#endif
}


MMI_BOOL mmi_swatch_mm_launch(S32 pos_x, S32 pos_y)
{
    S32 page_index, icon_index;
	MMI_RET result;
	MMI_ID icon_image;
	mmi_app_package_name_struct package_name;
    S32 pen_distance = mainmenu_swatch_list.pen_move_offset;
	S32 page_count = mainmenu_swatch_list.pen_move_offset / mainmenu_swatch_list.page_size;

    page_index = mmi_swatch_pen_point_in_launch_area(pos_x, pos_y);

	if (mainmenu_swatch_list.page_index != -1)
		page_index = mainmenu_swatch_list.page_index;
	
	if (page_index == -1)
		return MMI_FALSE;
		

	icon_index = page_count * mainmenu_swatch_list.mainmenu_page_num + page_index;
	
	result = srv_appmgr_get_app_package_name_by_id(mainmenu_swatch_list.panel_cell[icon_index].app_id,
												   package_name);
	if (MMI_FALSE == mainmenu_swatch_list.show_down_highlight)
	{
		mainmenu_swatch_list.pen_click = MMI_TRUE;
		mainmenu_swatch_list.page_index = page_index;
		mmi_mainmenu_swatch_draw_panel(MMI_TRUE);
		kal_sleep_task(15);
		mainmenu_swatch_list.pen_click = MMI_FALSE;
		mainmenu_swatch_list.page_index = -1;
		mmi_mainmenu_swatch_draw_panel(MMI_TRUE);
	}
	else
	{
		mainmenu_swatch_list.show_down_highlight = MMI_FALSE;
		mainmenu_swatch_list.page_index = -1;
	}
	srv_appmgr_launch(package_name);
	return MMI_TRUE;
}


static void mmi_mainmenu_swatch_draw_title(WCHAR *title, S32 icon_layout_x, S32 icon_layout_y)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 name_w, name_h;
	S32 strin_region, offset_x, offset_y;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_reset_clip();
    gdi_layer_reset_text_clip(); 
	
	if(0 == mainmenu_swatch_list.swatch_mm_style) //Only for 4 icon
	{
        gui_set_font(&MMI_medium_font);  //(&MMI_large_font);     MMI_medium_font   
	}
	else if(1 == mainmenu_swatch_list.swatch_mm_style)
	{
	    gui_set_font(&MMI_small_font); 
	}
	
    gui_measure_string((UI_string_type) title, &name_w, &name_h);        
#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
	gui_set_text_color(*(current_MMI_theme->list_main_menu_normal_text_color));
    gui_set_text_border_color(*(current_MMI_theme->title_text_border_color));
#else
    gui_set_text_color(*(current_MMI_theme->title_text_color));
    gui_set_text_border_color(*(current_MMI_theme->title_text_border_color));
#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
	if(0 == mainmenu_swatch_list.swatch_mm_style) //Only for 1 icon
	{
		strin_region = LCD_WIDTH;
		offset_x = 0;
	}
	else if (1 == mainmenu_swatch_list.swatch_mm_style)
	{
	    if(icon_layout_x < LCD_WIDTH/2)
	    {
		    offset_x = 4;
	    }
		else
		{
		    offset_x = LCD_WIDTH / 2;
		}
		strin_region = LCD_WIDTH / 2 - 4;	
	}
	
	offset_y = icon_layout_y;

	/* Draw text */    
    if (name_w < strin_region)
    {
    	offset_x += ((strin_region - name_w) >> 1);
            
        #ifdef __MMI_BIDI_ALG__
        if (mmi_fe_is_r2l_state())
        {
                offset_x += name_w;
        }
        #endif
            
        gui_move_text_cursor(offset_x, offset_y);
        gui_print_text((UI_string_type) title);
    }
    /* Draw truncated text */
    else
    {        
        #ifdef __MMI_BIDI_ALG__
        if (mmi_fe_is_r2l_state())
        {
            offset_x += strin_region;
        }
        #endif
            
        gui_move_text_cursor(offset_x, offset_y);
            
        gui_print_truncated_text(
                offset_x, offset_y, strin_region, 
                (UI_string_type) title);
    }
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_swatch_draw_bg
 * DESCRIPTION
 *  swatch mainmenu draw bg
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_main_menu_swatch_draw_bg(void)
{

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(mainmenu_swatch_list.base_layer);

	//gdi_layer_clear(GDI_COLOR_TRANSPARENT);

	gdi_layer_set_source_key(MMI_TRUE,GDI_COLOR_TRANSPARENT);

	//gui_draw_filled_area(0,0,LCD_WIDTH-1, LCD_HEIGHT-1, current_MMI_theme->rotated_bkg_filler);

	//gdi_layer_clear(GDI_COLOR_BLACK);
	#ifdef __MMI_MAINLCD_128X32__
	gdi_layer_clear(GDI_COLOR_BLACK);
	#else
	gdi_layer_clear(gdi_act_color_from_rgb(255, 32, 32, 40));
	#endif
	#ifdef __MMI_MAINLCD_128X128__
	//draw bg
	gdi_image_draw_id(0, MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT, IMG_ID_SWATCH_128_128_BG_PICTURE);
	#endif /*__MMI_MAINLCD_128X128__*/

	//gdi_image_draw_resized_id(0,0,240,35,MAIN_MENU_SWATCH_UP_BG_ICON);

	//gdi_image_draw_resized_id(0,220,240,20,MAIN_MENU_SWATCH_DN_BG_ICON);

	gdi_layer_pop_and_restore_active();

	//gdi_image_draw_resized_id(0,0,240,35,MAIN_MENU_SWATCH_UP_BG_ICON);

	//gdi_image_draw_resized_id(0,220,240,20,MAIN_MENU_SWATCH_DN_BG_ICON);
	
}
/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_swatch_draw_status_icon
 * DESCRIPTION
 *  swatch mainmenu draw status icon
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_main_menu_swatch_draw_status_icon(void)
{
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(mainmenu_swatch_list.status_icon_layer);
    gdi_layer_set_source_key(MMI_TRUE, GDI_COLOR_TRANSPARENT);
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_and_restore_active();
	
	wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, mainmenu_swatch_list.status_icon_layer);

    /* Set status bar's blending layer */
    wgui_status_icon_bar_set_alpha_blend_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, mainmenu_swatch_list.status_icon_layer); //panel_layer_handle

    /* Register draw-background callback */
    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_H_BAR,
        hide_status_icons_bar0_by_transparent);

    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR); 

	wgui_status_icon_bar_update();
}

mmi_watch_cell_struct *mmi_watch_get_cell_ptr(S32 index)
{
    return &mainmenu_swatch_list.panel_cell[index];
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_draw_cell
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mainmenu_draw_cell(mmi_watch_draw_info_struct *draw_info,
                                    mmi_watch_cell_struct *cell,
                                    S32 index_num)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_watch_rect_struct rect;
	PU8 cell_buffer;
	gdi_handle handler;
	gdi_layer_flatten_flag_bitset flag;
	U32 icon_width;
	S32 x, y;
	U32 icon_height;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(draw_info->transform.m[0] == 1.0 &&
       draw_info->transform.m[1] == 0.0 &&
       draw_info->transform.m[3] == 0.0 &&
       draw_info->transform.m[4] == 1.0 &&
       draw_info->transform.m[6] == 0.0 &&
       draw_info->transform.m[7] == 0.0 &&
       draw_info->transform.m[8] == 1.0)
    {
        rect.x1 = draw_info->transform.m[2];
        rect.y1 = draw_info->transform.m[5];
        rect.x2 = draw_info->transform.m[2] + mainmenu_swatch_list.cell_width - 1;
        rect.y2 = draw_info->transform.m[5] + mainmenu_swatch_list.cell_height - 1;
    }
#ifdef G2D_SUPPORT
    else
    {
        mmi_watch_get_output_rect(&draw_info->transform, 
			                      mainmenu_swatch_list.cell_width, 
			                      mainmenu_swatch_list.cell_height, 
			                      &rect);
    }
#else  //G2D_SUPPORT
    else
    {
        ASSERT(0);
    }
#endif   //G2D_SUPPORT

	if(mainmenu_swatch_list.is_cached == MMI_FALSE  &&
	   (rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT)) //Only for 1 icon
	{

#ifdef __MMI_MAINLCD_128X128__
    cell_buffer = mmi_frm_asm_alloc_anonymous_nc(mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 2);
    MMI_ASSERT(cell_buffer != NULL);
    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_16,
		                                     0,
		                                     0,
		                                     mainmenu_swatch_list.cell_width,
		                                     mainmenu_swatch_list.cell_height,
		                                     &handler,
		                                     cell_buffer,
		                                     mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 2);
#else
    cell_buffer = mmi_frm_asm_alloc_anonymous_nc(mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);
    MMI_ASSERT(cell_buffer != NULL);
	gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32_PARGB,
		                                     0,
		                                     0,
		                                     mainmenu_swatch_list.cell_width,
		                                     mainmenu_swatch_list.cell_height,
		                                     &handler,
		                                     cell_buffer,
		                                     mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);
#endif
	/*draw Cell*/
	gdi_layer_push_and_set_active(handler);

#ifdef __MMI_MAINLCD_128X128__
    gdi_layer_clear(GDI_COLOR_WHITE);
    gdi_layer_set_source_key(MMI_TRUE,GDI_COLOR_WHITE);
#else
	gdi_layer_clear(GDI_COLOR_TRANSPARENT);
#endif

	switch(cell->image_type)
	{
	    case MMI_IMAGE_SRC_TYPE_RES_ID:
			/*gdi_image_draw_resized_id((SWATCH_MAINMENU_CELL_WIDTH - SWATCH_MAINMENU_ICON_WIDTH)/2,
				                      (SWATCH_MAINMENU_CELL_HEIGHT - SWATCH_MAINMENU_CION_HEIGHT)/2,
				                       SWATCH_MAINMENU_ICON_WIDTH,
				                       SWATCH_MAINMENU_CION_HEIGHT,
				                       cell->image.res_id);*/
			gdi_image_draw_id((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				               mainmenu_swatch_list.image_offset,
				               cell->image.res_id);
			break;
		case MMI_IMAGE_SRC_TYPE_PATH:
			/*gdi_image_draw_resized_file((SWATCH_MAINMENU_CELL_WIDTH - SWATCH_MAINMENU_ICON_WIDTH)/2,
				                        (SWATCH_MAINMENU_CELL_HEIGHT - SWATCH_MAINMENU_CION_HEIGHT)/2 - 5,
				                         SWATCH_MAINMENU_ICON_WIDTH,
				                         SWATCH_MAINMENU_CION_HEIGHT,
				                         (S8 *)cell->image.path);*/
			gdi_image_get_dimension_file((S8 *)cell->image.path, &icon_width, &icon_height);
			if (icon_width > mainmenu_swatch_list.icon_width)
			{
				gdi_image_draw_resized_file((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
			                         mainmenu_swatch_list.image_offset, mainmenu_swatch_list.icon_width,
			                         mainmenu_swatch_list.icon_height,
			                         (S8 *)cell->image.path);
			}
			else
			{
			gdi_image_draw_file((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				                 mainmenu_swatch_list.image_offset,
				                (S8 *)cell->image.path);
			}
			break;
		case MMI_IMAGE_SRC_TYPE_MEM:
			gdi_image_get_dimension(cell->image_ptr, &icon_width, &icon_height);
			if (icon_width > mainmenu_swatch_list.icon_width)
			{
				gdi_image_draw_resized((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
			                        mainmenu_swatch_list.image_offset,
			                        mainmenu_swatch_list.icon_width,
			                        mainmenu_swatch_list.icon_height,
			                        cell->image_ptr);
			}
			else
			{
				gdi_image_draw((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				                mainmenu_swatch_list.image_offset,
				                cell->image_ptr);
			}
			break;
	}

	//mmi_mainmenu_swatch_draw_title(cell->string, 0, mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + 1);

    gdi_layer_set_opacity(MMI_TRUE, draw_info->opacity);
	
	gdi_layer_pop_and_restore_active();

	}
	else if(mainmenu_swatch_list.is_cached == MMI_TRUE &&
		    (rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT))
	{
	    cell_buffer = mainmenu_swatch_list.cache_ptr + index_num * (mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);

		gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32_PARGB,
		                                         0,
		                                         0,
		                                         mainmenu_swatch_list.cell_width,
		                                         mainmenu_swatch_list.cell_height,
		                                         &handler,
		                                         cell_buffer,
		                                         mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);
	}

    if (rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT)
    {
		 //draw mainmenu pen down bg
#ifndef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
		if (mainmenu_swatch_list.pen_click == MMI_TRUE)
		{
		   S32 page_index = -1;
		   page_index = index_num - mainmenu_swatch_list.pen_move_offset / mainmenu_swatch_list.page_size * mainmenu_swatch_list.mainmenu_page_num;
   		   if (mainmenu_swatch_list.page_index == page_index)
			  {
			  x = rect.x1 + (mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2;
	    	  y = rect.y1 + mainmenu_swatch_list.image_offset;
				  gdi_draw_solid_rect(x - 2,
						  y-2,
						  x + mainmenu_swatch_list.icon_width + 2 -1,
						  y + mainmenu_swatch_list.icon_height + 2 - 1,
						  gdi_act_color_from_rgb(255,31,181,172));
			  }
			  
			 
		}
#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
	    

			gdi_layer_set_position_nb_concurrent(handler,rect.x1,rect.y1);
			gdi_layer_push_and_set_clip(rect.x1,rect.y1,rect.x2,rect.y2);
		
	    flag = GDI_LAYER_FLATTEN_FLAG_CLIP;
		gdi_layer_flatten_with_flag_ext(mainmenu_swatch_list.panel_layer_handle, 
			                            handler, 
			                            0, 
			                            0, 
			                            #ifdef GDI_6_LAYERS
			                            0, 
			                            0,
			                            #endif
			                            flag);
#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
		if (mainmenu_swatch_list.pen_click == MMI_TRUE)
		{
		   S32 page_index = -1;
		   page_index = index_num - mainmenu_swatch_list.pen_move_offset / mainmenu_swatch_list.page_size * mainmenu_swatch_list.mainmenu_page_num;
   		   if (mainmenu_swatch_list.page_index == page_index)
		   {
				x = rect.x1 + (mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2;
	    		y = rect.y1 + mainmenu_swatch_list.image_offset;
			  	gdi_image_draw_id(x, y, mainmenu_swatch_list.press_icon);
		   }	 
		}
#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
		gdi_layer_pop_clip();

		#ifdef __MMI_MAINLCD_128X32__
        /*Draw Highlight*/
		if(highlight_index == index_num)
		{
		    gdi_draw_line(rect.x1-1, rect.y1-1, rect.x2+1, rect.y1-1, GDI_COLOR_WHITE);
			gdi_draw_line(rect.x1-1, rect.y1-1, rect.x1-1, rect.y2+1, GDI_COLOR_WHITE);
			gdi_draw_line(rect.x2+1, rect.y1-1, rect.x2+1, rect.y2+1, GDI_COLOR_WHITE);
			gdi_draw_line(rect.x1-1, rect.y2+1, rect.x2+1, rect.y2+1, GDI_COLOR_WHITE);
		}
        #else
		mmi_mainmenu_swatch_draw_title(cell->string, rect.x1, rect.y1 + mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + 2);
		#endif
    }

    if(mainmenu_swatch_list.is_cached == MMI_FALSE  &&
	   (rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT))
    {
	    mmi_frm_asm_free_anonymous(cell_buffer);
    }
    if(rect.x1 < LCD_WIDTH && rect.y1 < LCD_HEIGHT && rect.x2 > 0  && rect.y2 > 0 && rect.x2 - rect.x1 + 1 <= LCD_WIDTH && rect.y2 - rect.y1 + 1 <= LCD_HEIGHT)
    {
	    gdi_layer_free(handler);
    }
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_get_swatch_icon_layout
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mainmenu_draw_swatch_icon(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_watch_draw_info_struct *draw_info_list;
	watch_transform_func tran_func;
	S32 i, max_idx, j;
	mmi_watch_draw_info_struct draw;
	mmi_watch_cell_struct cell_p;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_GDI, "mmi_mainmenu_draw_swatch_icon draw cell begin");
	if (mainmenu_swatch_list.total_icon_num > SMART_WATCH_MAINMENU_ITEM_NUM)
	{
		mainmenu_swatch_list.total_icon_num = SMART_WATCH_MAINMENU_ITEM_NUM;
	}
	
	draw_info_list = (mmi_watch_draw_info_struct *)mmi_frm_asm_alloc_anonymous_nc(
        sizeof(mmi_watch_draw_info_struct) * mainmenu_swatch_list.total_icon_num);    

    kal_mem_set(
        draw_info_list, 
        0, 
        sizeof(mmi_watch_draw_info_struct) * mainmenu_swatch_list.total_icon_num);

	tran_func = (watch_transform_func)mmi_watch_barrel_get_transform();

    for(i = 0; i < mainmenu_swatch_list.total_icon_num; i++)
    {
	    tran_func(i,
			      &(draw_info_list[i].transform),
			      &(draw_info_list[i].opacity),
			      &(draw_info_list[i].pos_z));
    }

	 /* Sort cell list with pos_z */
    for (i = 0; i < mainmenu_swatch_list.total_icon_num - 1; i ++)
    {
        max_idx = i;
        for(j = i + 1; j < mainmenu_swatch_list.total_icon_num; j ++)
        {
            if (draw_info_list[j].pos_z > draw_info_list[max_idx].pos_z)
            {
                max_idx = j;
            }
        }
        
        /* swap */
        if (i != max_idx)
        {
            draw = draw_info_list[i];
            draw_info_list[i] = draw_info_list[max_idx];
            draw_info_list[max_idx] = draw;

            cell_p = mainmenu_swatch_list.panel_cell[i];
            mainmenu_swatch_list.panel_cell[i] = mainmenu_swatch_list.panel_cell[max_idx];
            mainmenu_swatch_list.panel_cell[max_idx] = cell_p;
        }
    }

    kal_prompt_trace(MOD_GDI, "mmi_mainmenu_draw_swatch_icon draw cell begin1");

    /*Draw cell icon*/
	for (i = 0; i < mainmenu_swatch_list.total_icon_num; i ++)
	{
	    mmi_mainmenu_draw_cell(&draw_info_list[i],&mainmenu_swatch_list.panel_cell[i], i);
	}

    kal_prompt_trace(MOD_GDI, "mmi_mainmenu_draw_swatch_icon draw cell end");

	//free_ctrl_buffer(draw_info_list);
	mmi_frm_asm_free_anonymous(draw_info_list);
	
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_watch_update_layer
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_mainmenu_watch_update_layer(MMI_BOOL is_blocking)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_handle temp_handler;
	gdi_layer_blt_flag_bit_set flag = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif

    /*Use non blocking blt, first wait blt finish*/
    if(is_blocking == MMI_FALSE)
    {
        gdi_waiting_blt_finish();
        flag = GDI_LAYER_BLT_FLAG_NON_BLOCKING;
    }
	
	gdi_layer_blt_with_flag(
            mainmenu_swatch_list.panel_layer_handle,
            mainmenu_swatch_list.status_icon_layer,
            NULL,
            NULL,
            0,
            0,
            LCD_WIDTH - 1,
            LCD_HEIGHT - 1,
            flag,
            NULL);

	gdi_layer_set_blt_layer(mainmenu_swatch_list.panel_layer_handle,
            mainmenu_swatch_list.status_icon_layer,
            NULL,
            NULL);

	/*Swicth update Layer*/
	if(is_blocking == MMI_FALSE)
	{
	    temp_handler = mainmenu_swatch_list.panel_layer_handle;
	    mainmenu_swatch_list.panel_layer_handle = mainmenu_swatch_list.base_layer;
	    mainmenu_swatch_list.base_layer = temp_handler;
	}
}


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_swatch_draw_panel
 * DESCRIPTION
 *  swatch mainmenu draw panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mainmenu_swatch_draw_panel(MMI_BOOL is_blocking)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

		S32 i, j, icon_index = 0;
		mmi_app_package_name_struct package_name; 
		MMI_RET result;
		srv_app_info_struct info;
		MMI_ID icon_image;
		swatch_pos_struct icon_layout;
		S16 result_icon;
		U16 image_type;
		MMI_BOOL is_show = MMI_FALSE;
		S32 page_total;
		S32 page_count = mainmenu_swatch_list.pen_move_offset / mainmenu_swatch_list.page_size;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	    page_total = (mainmenu_swatch_list.total_icon_num - 1) / mainmenu_swatch_list.mainmenu_page_num;
		gdi_layer_push_and_set_active(mainmenu_swatch_list.panel_layer_handle);
		gdi_push_and_set_alpha_blending_source_layer(mainmenu_swatch_list.panel_layer_handle);
		//gdi_layer_clear(GDI_COLOR_BLACK);
		#ifdef __MMI_MAINLCD_128X32__
	    gdi_layer_clear(GDI_COLOR_BLACK);
	    #else
		#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
		gdi_layer_clear(gdi_act_color_from_rgb(255, 0, 0, 0));
		#else
		gdi_layer_clear(gdi_act_color_from_rgb(255, 32, 32, 40));
		#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
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
				#if defined(__DELETE_APP_IN_MAINMENU__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif /*__DELETE_APP_IN_MAINMENU__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if defined(__DELETE_APP_IN_MAINMENU__)
/* under construction !*/
		#endif /*__DELETE_APP_IN_MAINMENU__*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#else
		mmi_mainmenu_draw_swatch_icon();
		//kal_prompt_trace(MOD_GDI, "mmi_mainmenu_swatch_draw_panel draw cell");
		//gdi_pop_and_restore_alpha_blending_source_layer();	
#ifdef __MMI_MAINLCD_128X128__
        if (mainmenu_swatch_list.disable_array_image == MMI_FALSE)
		{
		    if(page_count != 0)
		    {
			    gdi_image_draw_id(0,14,IMG_ID_SWATCH_INDIcATOR_TOP);
		    }

			if(page_count != page_total)
			{
			    gdi_image_draw_id(0,122,IMG_ID_SWATCH_INDICATOR_BOTTOM);
			}
		}

		/*Draw indication bar*/
		for(i = 0; i <= page_total; i++)
		{
		    j = (LCD_HEIGHT - (page_total + 1)*8 - 14) / 2 + 14 + i * 8;
		    gdi_image_draw_id(10, j, IMG_ID_SWATCH_PAGE_OFF);
		}

		j = (LCD_HEIGHT - (page_total + 1)*8 - 14) / 2 + 14 + page_count * 8;
		gdi_image_draw_id(10, j, IMG_ID_SWATCH_PAGE_ON);
		
#else
        #ifndef __MMI_MAINLCD_128X32__
		if (mainmenu_swatch_list.disable_array_image == MMI_FALSE)
		{
		    if(page_count != 0)
		    {
                gdi_image_draw_id(SMART_WATCH_MAINMENY_INDICATOR_ICON_OFFSETX,
                                  SMART_WATCH_MAINMENY_INDICATOR_ICON_TOP_OFFSETY,
                                  MAIN_MENU_ARROW_UP_BG_ICON);
		    }

			if(page_count != page_total)
			{
                gdi_image_draw_id(SMART_WATCH_MAINMENY_INDICATOR_ICON_OFFSETX,
                                  SMART_WATCH_MAINMENY_INDICATOR_ICON_END_OFFSETY,
                                  MAIN_MENU_ARROW_DN_BG_ICON);
			}
		}
		#endif
#endif		
        gdi_pop_and_restore_alpha_blending_source_layer();
		gdi_layer_pop_and_restore_active();
		mmi_mainmenu_watch_update_layer(is_blocking);
		#endif
}


void mmi_swatch_mm_swap_animation(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 distance;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(mainmenu_swatch_list.start_anim_pos >= 0)
	{
		if(mainmenu_swatch_list.start_anim_pos > mainmenu_swatch_list.end_anim_pos)
		{
			mainmenu_swatch_list.pen_move_offset -= (mainmenu_swatch_list.pen_swap_dis*mainmenu_swatch_list.speed);
			mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
			if(mainmenu_swatch_list.pen_move_offset <= mainmenu_swatch_list.end_anim_pos)
			{
				//gui_cancel_timer(mmi_swatch_mm_swap_animation);
				StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
				mainmenu_swatch_list.disable_array_image = MMI_FALSE;
				mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.end_anim_pos;
				mainmenu_swatch_list.end_anim_pos = -100;
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;
			}
			else
			{
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
				//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
			}
		}
		else
		{
			mainmenu_swatch_list.pen_move_offset += (mainmenu_swatch_list.pen_swap_dis*mainmenu_swatch_list.speed);
			mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
			if(mainmenu_swatch_list.pen_move_offset >= mainmenu_swatch_list.end_anim_pos)
			{
				//gui_cancel_timer(mmi_swatch_mm_swap_animation);
				StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
				mainmenu_swatch_list.disable_array_image = MMI_FALSE;
				mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.end_anim_pos;
				mainmenu_swatch_list.end_anim_pos = -100;
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;
			}
			else
			{
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
				//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
			}
		}
	}
	else
	{
		if(mainmenu_swatch_list.start_anim_pos > mainmenu_swatch_list.end_anim_pos)
		{
			mainmenu_swatch_list.pen_move_offset -= (mainmenu_swatch_list.pen_swap_dis*mainmenu_swatch_list.speed);
			mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
			if(mainmenu_swatch_list.pen_move_offset <= mainmenu_swatch_list.end_anim_pos)
			{
				//gui_cancel_timer(mmi_swatch_mm_swap_animation);
				StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
				mainmenu_swatch_list.disable_array_image = MMI_FALSE;
				mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.end_anim_pos;
				mainmenu_swatch_list.end_anim_pos = -100;
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;
			}
			else
			{
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
				//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
			}
		}
		else
		{
			mainmenu_swatch_list.pen_move_offset += (mainmenu_swatch_list.pen_swap_dis*mainmenu_swatch_list.speed);
			mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
			if(mainmenu_swatch_list.pen_move_offset >= mainmenu_swatch_list.end_anim_pos)
			{
				//gui_cancel_timer(mmi_swatch_mm_swap_animation);
				StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
				mainmenu_swatch_list.disable_array_image = MMI_FALSE;
				mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.end_anim_pos;	
				mainmenu_swatch_list.end_anim_pos = -100;
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;
			}
			else
			{
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
				StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
				//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
			}
		}
	}
}


void mmi_swatch_set_down_flag(void)
{
	mainmenu_swatch_list.pen_click = MMI_TRUE;
	mainmenu_swatch_list.show_down_highlight = MMI_TRUE;
	mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
}
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mm_pen_down_hdlr
 * DESCRIPTION
 *  swatch mainmenu pen down hdlr
 * PARAMETERS
 *  pos	[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swatch_mm_pen_down_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	kal_prompt_trace(MOD_MMI, "[SWATCH_PEN]mmi_swatch_mm_pen_down_hdlr, pos.x=%d, pos.y=%d\n",pos.x, pos.y);
	mainmenu_swatch_list.pen_down_pos_y = pos.y;
	mainmenu_swatch_list.pen_down_pos_x = pos.x;

	if(mainmenu_swatch_list.end_anim_pos != -100)
	{
	    //gui_cancel_timer(mmi_swatch_mm_swap_animation);
		StopTimer(MAINMENU_SWATCH_ANIMATE_TIMER);
		mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.end_anim_pos;
		mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;
		mainmenu_swatch_list.end_anim_pos = -100;
		mainmenu_swatch_list.disable_array_image = MMI_FALSE;
		mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
	}

    mainmenu_swatch_list.swap_direction = MMI_SWATCH_SWAP_DIRECTION_NONE;
	//mainmenu_swatch_list.disable_array_image = MMI_TRUE;
	mainmenu_swatch_list.pen_click = MMI_FALSE;
	mainmenu_swatch_list.show_down_highlight = MMI_FALSE;
	mainmenu_swatch_list.page_index = mmi_swatch_pen_point_in_launch_area(pos.x, pos.y);
	gui_start_timer(150, mmi_swatch_set_down_flag);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mm_pen_move_hdlr
 * DESCRIPTION
 *  swatch mainmenu pen move hdlr
 * PARAMETERS
 *  pos	[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swatch_mm_pen_move_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    S32 page_dis, x_distance, y_distance;
	
    page_dis = (mainmenu_swatch_list.total_icon_num  - 1) / mainmenu_swatch_list.mainmenu_page_num;
    page_dis = page_dis * mainmenu_swatch_list.page_size + SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS;

	y_distance = mmi_mainmenu_swatch_abs(pos.y - mainmenu_swatch_list.pen_down_pos_y);
	x_distance = mmi_mainmenu_swatch_abs(pos.x - mainmenu_swatch_list.pen_down_pos_x);
    mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.prevpen_move_offset + mainmenu_swatch_list.pen_down_pos_y - pos.y;

    if(mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_NONE)
    {
		if(x_distance >= 2 * y_distance)
		{
		    mainmenu_swatch_list.swap_direction = MMI_SWATCH_SWAP_DIRECTION_V;
		}
		else
		{
		    mainmenu_swatch_list.swap_direction = MMI_SWATCH_SWAP_DIRECTION_H;
		}
    }
	if(y_distance > mainmenu_swatch_list.pen_click_threshold  || 
	       x_distance > 2)
	{
		gui_cancel_timer(mmi_swatch_set_down_flag);
		mainmenu_swatch_list.pen_click = MMI_FALSE;
		mainmenu_swatch_list.page_index = -1;
	}

	if (mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_V)
	{
		mainmenu_swatch_list.pen_move_offset =  mainmenu_swatch_list.prevpen_move_offset; //mainmenu_swatch_list.pen_move_offset - mainmenu_swatch_list.pen_move_offset % mainmenu_swatch_list.page_size;
		mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
	}

    if(mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_H)
    {
        if(mainmenu_swatch_list.pen_move_offset < (-SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS))
	    {
	        mainmenu_swatch_list.pen_move_offset = (-SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS);
	    }
	    else if(mainmenu_swatch_list.pen_move_offset > page_dis)
	    {
	        mainmenu_swatch_list.pen_move_offset = page_dis;
	    }
	    if(mmi_mainmenu_swatch_abs(pos.y - mainmenu_swatch_list.pen_down_pos_y) > mainmenu_swatch_list.pen_click_threshold  ||
	       mmi_mainmenu_swatch_abs(pos.x - mainmenu_swatch_list.pen_down_pos_x) > 2)
	    {
		     mainmenu_swatch_list.disable_array_image = MMI_TRUE;
	    }
		
	    mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
    }
}


void mmi_swatch_mm_pen_up_hdlr(mmi_pen_point_struct pos)
{
	S32 distance, X, start_pos, dis_x;
	S32 page_dis;
	gui_cancel_timer(mmi_swatch_set_down_flag);

	mainmenu_swatch_list.pen_click = MMI_FALSE;
	//left swipe enter bt notification
	/*if(mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_V || mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_NONE)
	{
	    if (-(pos.x - mainmenu_swatch_list.pen_down_pos_x) > SMART_WATCH_MAINMENU_LEFT_SLIDE_X_THRESHOLD\
		    &&  mmi_mainmenu_swatch_abs(pos.y - mainmenu_swatch_list.pen_down_pos_y) < SMART_WATCH_MAINMENU_LEFT_SLIDE_X_THRESHOLD)
	    {
		    srv_appmgr_launch("native.mtk.btnotification");
		    return;
	    }
	}*/
	
    page_dis = (mainmenu_swatch_list.total_icon_num - 1) / mainmenu_swatch_list.mainmenu_page_num;
    page_dis = page_dis * mainmenu_swatch_list.page_size + SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS;
	
	distance = mainmenu_swatch_list.pen_down_pos_y - pos.y;

	start_pos = mainmenu_swatch_list.prevpen_move_offset + distance;

	X = mmi_mainmenu_swatch_abs(pos.y - mainmenu_swatch_list.pen_down_pos_y);
    dis_x = mmi_mainmenu_swatch_abs(pos.x - mainmenu_swatch_list.pen_down_pos_x);

    if(start_pos < (-SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS))
	{
	    start_pos = (-SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS);
		distance = start_pos - mainmenu_swatch_list.prevpen_move_offset;
		X = mmi_mainmenu_swatch_abs(distance);
	}
	else if(start_pos > page_dis)
	{
	    start_pos = page_dis;
		distance = start_pos - mainmenu_swatch_list.prevpen_move_offset;
		X = mmi_mainmenu_swatch_abs(distance);
	}


    if(mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_V || mainmenu_swatch_list.swap_direction == MMI_SWATCH_SWAP_DIRECTION_NONE)
    {
	    if(X <= mainmenu_swatch_list.pen_click_threshold  &&
	       dis_x <= 2 && mainmenu_swatch_list.page_index != -1)
	    {
	      	mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.prevpen_move_offset - mainmenu_swatch_list.pen_down_pos_y + pos.y;
		    if (MMI_FALSE == mmi_swatch_mm_launch(pos.x, pos.y))
		    {
				mainmenu_swatch_list.pen_move_offset =  mainmenu_swatch_list.prevpen_move_offset;// - mainmenu_swatch_list.pen_move_offset % mainmenu_swatch_list.page_size;
				mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
		    }
			else
			{
				mainmenu_swatch_list.pen_move_offset =  mainmenu_swatch_list.prevpen_move_offset;
			}
		    return;
	    }
    }
	
	mainmenu_swatch_list.pen_down_pos_y = 0;
	mainmenu_swatch_list.page_index = -1;

    if(mainmenu_swatch_list.swap_direction != MMI_SWATCH_SWAP_DIRECTION_H)
    {
    	mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
        return;
    }

	if(X <= mainmenu_swatch_list.pen_up_threshold)
	{
		if(distance > 0)
		{
			mainmenu_swatch_list.start_anim_pos = start_pos;
			mainmenu_swatch_list.end_anim_pos = start_pos - X;
			mainmenu_swatch_list.speed = 1;
			mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
			StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
			//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
		}
		else
		{
			mainmenu_swatch_list.start_anim_pos = start_pos;
			mainmenu_swatch_list.end_anim_pos = start_pos + X;
			mainmenu_swatch_list.speed = 1;
			mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
			StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
			//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
		}
	}
	else
	{
		if(distance > 0)
		{
			mainmenu_swatch_list.start_anim_pos = start_pos;
			mainmenu_swatch_list.end_anim_pos = start_pos + (mainmenu_swatch_list.page_size - X);
			mainmenu_swatch_list.speed = 1;
			mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
			StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
			//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
		}
		else
		{
			mainmenu_swatch_list.start_anim_pos = start_pos;
			mainmenu_swatch_list.end_anim_pos = start_pos - (mainmenu_swatch_list.page_size - X);
			mainmenu_swatch_list.speed = 1;
			mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
			StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
			//gui_start_timer(mainmenu_swatch_list.mainmenu_anim_timer, mmi_swatch_mm_swap_animation);
		}
	}
}


#if defined(__DELETE_APP_IN_MAINMENU__)
/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mm_pen_long_tap_hdlr
 * DESCRIPTION
 *  swatch mainmenu pen long tap hdlr
 * PARAMETERS
 *  pos	[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swatch_mm_pen_long_tap_hdlr(mmi_pen_point_struct pos)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_RET result;
	mmi_app_package_name_struct * array = NULL;
	U32 i;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mainmenu_swatch_list.is_uninstall_status = !mainmenu_swatch_list.is_uninstall_status;
	
	if (MMI_TRUE == mainmenu_swatch_list.is_uninstall_status)
	{
		if (0 != mainmenu_swatch_list.install_app_num)
		{
			array = mmi_frm_asm_alloc_anonymous(mainmenu_swatch_list.install_app_num * sizeof(mmi_app_package_name_struct));
			MMI_ASSERT(NULL != array);
			memset(array, 0, mainmenu_swatch_list.install_app_num * sizeof(mmi_app_package_name_struct));
		
			result = srv_appmgr_get_app_package_list(SRV_APPMGR_INSTALLED_APP_PACKAGE_FLAG_TYPE,
												 array,
												 mainmenu_swatch_list.install_app_num * sizeof(mmi_app_package_name_struct));
			MMI_ASSERT(result != MMI_RET_ERR);
			for (i=0; i<mainmenu_swatch_list.install_app_num; i++)
			{
				mainmenu_swatch_list.install_app_array[i] = 
            	srv_appmgr_get_id_by_app_package_name(array[i]);
			}
			mmi_frm_asm_free_anonymous(array);			
		}
		
	}
	mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
}
#endif /*__DELETE_APP_IN_MAINMENU__*/

/*****************************************************************************
 * FUNCTION
 *  mmi_smart_watch_mainmenu_type_init
 * DESCRIPTION
 *  swatch mainmenu init
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_smart_watch_mainmenu_type_init(void)
{

	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S16 error;
	U8 style_index = 0xFF;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//#if defined(__MMI_ONE_ICON_MAINMENU__) && defined(__MMI_FOUR_ICON_MAINMENU__) && defined(__MMI_MAINLCD_240X240__)
	#if 1//def __MMI_WEARABLE_DEVICE_SETTING__
		ReadValue(NVRAM_PHNSET_MAIN_MENU_STYLE, &style_index, DS_BYTE, &error);
	    if(style_index != mainmenu_swatch_list.swatch_mm_style)
	    {
	        mainmenu_swatch_list.prevpen_move_offset = 0;
			mainmenu_swatch_list.swatch_mm_style = style_index;
	    }
	#elif defined(__MMI_SMART_WATCH_MAINMENU_ONE__)
		mainmenu_swatch_list.swatch_mm_style = 0;
	#elif defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
		mainmenu_swatch_list.swatch_mm_style = 1;
	#endif /*defined(__MMI_SMART_WATCH_MAINMENU_ONE__) && defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)*/

    
	#if defined(__DELETE_APP_IN_MAINMENU__)
	mainmenu_swatch_list.is_uninstall_status = MMI_FALSE;
	#endif /*__DELETE_APP_IN_MAINMENU__*/

	#if defined(__MMI_MAINLCD_128X128__)
		mainmenu_swatch_list.icon_table = g_mmi_small_swatch_icon_table;
		g_mmi_swatch_icon_table_len  = sizeof(g_mmi_small_swatch_icon_table) / sizeof(swatch_icon_map_struct);
		mainmenu_swatch_list.mainmenu_page_num = 1;
		mainmenu_swatch_list.left_gap = SMART_WATCH_MAINMENU_LEFT_GAP_S;
		mainmenu_swatch_list.top_gap = SMART_WATCH_MAINMENU_TOP_GAP_S;
		mainmenu_swatch_list.cell_width = SMART_WATCH_MAINMENU_CELL1_WIDTH_S;
		mainmenu_swatch_list.cell_height = SMART_WATCH_MAINMENU_CELL1_HEIGHT_S;
		mainmenu_swatch_list.image_offset = SMART_WATCH_MAINMENU_IMAGE_MARGIN_S;
		mainmenu_swatch_list.page_size = SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S;
		mainmenu_swatch_list.between_gap = SMART_WATCH_MAINMENU_BETWEEN_GAP_S; 
		mainmenu_swatch_list.icon_width = SMART_WATCH_MAINMENU_CELL_WIDTH_S;
		mainmenu_swatch_list.icon_height = SMART_WATCH_MAINMENU_CELL_HEIGHT_S;
		mainmenu_swatch_list.pen_swap_dis = SMART_WATCH_MAINMENU_PEN_SWAP_DIS;
		mainmenu_swatch_list.mainmenu_anim_timer = SMART_WATCH_MAINMENU_ANIM_TIMER;
	#elif defined(__MMI_MAINLCD_128X32__)
	    mainmenu_swatch_list.icon_table = g_mmi_swatch_icon_table_four;
		g_mmi_swatch_icon_table_len  = sizeof(g_mmi_swatch_icon_table_four) / sizeof(swatch_icon_map_struct);
		mainmenu_swatch_list.mainmenu_page_num = 4;
		mainmenu_swatch_list.left_gap = 5;
		mainmenu_swatch_list.top_gap = 2;
		mainmenu_swatch_list.cell_width = 28;
		mainmenu_swatch_list.cell_height = 28;
		mainmenu_swatch_list.image_offset = 0;
		mainmenu_swatch_list.page_size = 30;
		mainmenu_swatch_list.between_gap = 0; 
		mainmenu_swatch_list.icon_width = 26;
		mainmenu_swatch_list.icon_height = 26;
		mainmenu_swatch_list.pen_swap_dis = SMART_WATCH_MAINMENU_PEN_SWAP_DIS;
		mainmenu_swatch_list.mainmenu_anim_timer = 0;
	#else
	{
	#if defined(__MMI_SMART_WATCH_MAINMENU_ONE__) 
	if (0 == mainmenu_swatch_list.swatch_mm_style) //one icon type
	{
		//mainmenu_swatch_list.get_layout = mmi_mainmenu_get_swatch_one_icon_layout;
		//mainmenu_swatch_list.check_area = mmi_swatch_mm_check_is_in_area_one;
		//mainmenu_swatch_list.change_index = mmi_swatch_mm_change_highlight_index;
		mainmenu_swatch_list.icon_width = SMART_WATCH_MAINMENU_CELL_WIDTH;
		mainmenu_swatch_list.icon_height = SMART_WATCH_MAINMENU_CELL_HEIGHT;
		//mainmenu_swatch_list.icon_distance_v = SMART_WATCH_MAINMENU_CELL_DISTANCE_V;  //Left Gap
		//mainmenu_swatch_list.icon_top_distance = SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE;
		//mainmenu_swatch_list.icon_string_offset = SMART_WATCH_MAINMENU_CELL_STRING_OFFSET;
		mainmenu_swatch_list.pen_swap_dis = SMART_WATCH_MAINMENU_PEN_SWAP_DIS;
		mainmenu_swatch_list.mainmenu_anim_timer = SMART_WATCH_MAINMENU_ANIM_TIMER;
		mainmenu_swatch_list.pen_click_threshold = SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD;
		mainmenu_swatch_list.pen_up_threshold = SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS;  //SMART_WATCH_MAINMENU_UP_THRESHOLD;
		//mainmenu_swatch_list.icon_title_height = SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT;
		mainmenu_swatch_list.mainmenu_page_num = 1;
		mainmenu_swatch_list.left_gap = SMART_WATCH_MAINMENU_LEFT_GAP;
		mainmenu_swatch_list.top_gap = SMART_WATCH_MAINMENU_TOP_GAP;
		mainmenu_swatch_list.cell_width = SMART_WATCH_MAINMENU_CELL1_WIDTH;
		mainmenu_swatch_list.cell_height = SMART_WATCH_MAINMENU_CELL1_HEIGHT;
		mainmenu_swatch_list.image_offset = SMART_WATCH_MAINMENU_IMAGE_MARGIN;
		mainmenu_swatch_list.page_size = SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE;
		mainmenu_swatch_list.between_gap = SMART_WATCH_MAINMENU_BETWEEN_GAP;

		#if defined(__DELETE_APP_IN_MAINMENU__)
		mainmenu_swatch_list.uninstall_bg_width = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH;
		mainmenu_swatch_list.uninstall_bg_height = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT;
		mainmenu_swatch_list.uninstall_bg_offset_x = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X;
		mainmenu_swatch_list.uninstall_bg_offset_y = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y;
		#endif /*__DELETE_APP_IN_MAINMENU__*/

		#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
		mainmenu_swatch_list.press_icon = MAIN_MENU_PRESS_ICON;
		#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
		mainmenu_swatch_list.icon_table = g_mmi_swatch_icon_table_one;
		g_mmi_swatch_icon_table_len  = sizeof(g_mmi_swatch_icon_table_one) / sizeof(swatch_icon_map_struct);
	
	}	
	#endif
	#if defined(__MMI_SMART_WATCH_MAINMENU_FOUR__)
	if(1 == mainmenu_swatch_list.swatch_mm_style) //four icon type
	{
		//mainmenu_swatch_list.get_layout = mmi_mainmenu_get_swatch_four_icon_layout;
		//mainmenu_swatch_list.check_area = mmi_swatch_mm_check_is_in_area_four;
		//mainmenu_swatch_list.change_index = mmi_smart_mm_change_first_display_icon_index;
		mainmenu_swatch_list.icon_width = SMART_WATCH_MAINMENU_CELL_WIDTH_S;
		mainmenu_swatch_list.icon_height = SMART_WATCH_MAINMENU_CELL_HEIGHT_S;
		//mainmenu_swatch_list.icon_distance_v = SMART_WATCH_MAINMENU_CELL_DISTANCE_V_S;
		//mainmenu_swatch_list.icon_top_distance = SMART_WATCH_MAINMENU_CELL_TOP_DISTANCE_S;
		//mainmenu_swatch_list.icon_string_offset = SMART_WATCH_MAINMENU_CELL_STRING_OFFSET_S;
		mainmenu_swatch_list.pen_swap_dis = SMART_WATCH_MAINMENU_PEN_SWAP_DIS_S;
		mainmenu_swatch_list.mainmenu_anim_timer = SMART_WATCH_MAINMENU_ANIM_TIMER_S;
		mainmenu_swatch_list.pen_click_threshold = SMART_WATCH_MAINMENU_PEN_CLICK_THRESHOLD_S;
		mainmenu_swatch_list.pen_up_threshold = SMART_WATCH_MAINMENU_SWICTH_PAGE_DIS; //SMART_WATCH_MAINMENU_UP_THRESHOLD_S;
		//mainmenu_swatch_list.icon_distance_h = SMART_WATCH_MAINMENU_CELL_DISTANCE_H_S;
		//mainmenu_swatch_list.first_icon_offset_x = SMART_WATCH_MAINMENU_FIRST_ICON_OFFSET_X;
		//mainmenu_swatch_list.icon_title_height = SMART_WATCH_MAINMENU_ICON_TITLE_HEIGHT_S;
		mainmenu_swatch_list.mainmenu_page_num = SMART_WATCH_MAINMENU_ICON_NUM_PAGE;
		mainmenu_swatch_list.left_gap = SMART_WATCH_MAINMENU_LEFT_GAP_S;
		mainmenu_swatch_list.top_gap = SMART_WATCH_MAINMENU_TOP_GAP_S;
		mainmenu_swatch_list.cell_width = SMART_WATCH_MAINMENU_CELL1_WIDTH_S;
		mainmenu_swatch_list.cell_height = SMART_WATCH_MAINMENU_CELL1_HEIGHT_S;
		mainmenu_swatch_list.image_offset = SMART_WATCH_MAINMENU_IMAGE_MARGIN_S;
		mainmenu_swatch_list.page_size = SMART_WATCH_MAINMENU_IMAGE_PAG_SIZE_S;
		mainmenu_swatch_list.between_gap = SMART_WATCH_MAINMENU_BETWEEN_GAP_S;

		#if defined(__DELETE_APP_IN_MAINMENU__)
		mainmenu_swatch_list.uninstall_bg_width = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_WIDTH_S;
		mainmenu_swatch_list.uninstall_bg_height = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_HEIGHT_S;
		mainmenu_swatch_list.uninstall_bg_offset_x = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_X_S;
		mainmenu_swatch_list.uninstall_bg_offset_y = SMART_WATCH_MAINMENU_ICON_UNINSTALL_BG_OFFSET_Y_S;
		#endif /*__DELETE_APP_IN_MAINMENU__*/

		#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
		mainmenu_swatch_list.press_icon = MAIN_MENU_PRESS_ICON_S;
		#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
		mainmenu_swatch_list.icon_table = g_mmi_swatch_icon_table_four;
		g_mmi_swatch_icon_table_len  = sizeof(g_mmi_swatch_icon_table_four) / sizeof(swatch_icon_map_struct);
	}
	#endif
}
	#endif /*__MMI_MAINLCD_128X128__*/
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_cache_cell_icon
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_cache_cell_icon()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 mem_size;
	U8 i;
	gdi_handle handler;
	PU8 cell_buffer;
	mmi_watch_cell_struct *cell;
	U32 icon_width = 0;
	U32 icon_height = 0;
	S32 draw_info_mem_size = 0;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(1 == mainmenu_swatch_list.swatch_mm_style) //Only for 4 icon
	{
	    /*Alloc cache memory*/
		if (mainmenu_swatch_list.total_icon_num > SMART_WATCH_MAINMENU_ITEM_NUM)
		{
			mainmenu_swatch_list.total_icon_num = SMART_WATCH_MAINMENU_ITEM_NUM;
		}
		
	    mem_size = mainmenu_swatch_list.total_icon_num * mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4;

		draw_info_mem_size = sizeof(mmi_watch_draw_info_struct) * mainmenu_swatch_list.total_icon_num;
		
		mainmenu_swatch_list.cache_ptr = mmi_frm_asm_alloc_anonymous_nc(mem_size + draw_info_mem_size + 240*240*2);

		if(mainmenu_swatch_list.cache_ptr == NULL)
		{
		    mainmenu_swatch_list.is_cached = MMI_FALSE;
			return;
		}
		else
		{
		    mainmenu_swatch_list.is_cached = MMI_TRUE;
		}

		mmi_frm_asm_free_anonymous(mainmenu_swatch_list.cache_ptr);
		
 		mainmenu_swatch_list.cache_ptr = mmi_frm_asm_alloc_anonymous_nc(mem_size);
        //MMI_ASSERT(mainmenu_swatch_list.cache_ptr != NULL);
		/*Do cache*/
		for(i = 0; i < mainmenu_swatch_list.total_icon_num ;i++)
		{
		    cell = mmi_watch_get_cell_ptr(i); 
		    cell_buffer = mainmenu_swatch_list.cache_ptr + i * (mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);
		    gdi_layer_create_cf_using_outside_memory(GDI_COLOR_FORMAT_32_PARGB,
		                                     0,
		                                     0,
		                                     mainmenu_swatch_list.cell_width,
		                                     mainmenu_swatch_list.cell_height,
		                                     &handler,
		                                     cell_buffer,
		                                     mainmenu_swatch_list.cell_width * mainmenu_swatch_list.cell_height * 4);

	        /*draw Cell*/
	        gdi_layer_push_and_set_active(handler);

	       // gdi_layer_clear(GDI_COLOR_BLACK);
			//gdi_layer_clear(gdi_act_color_from_rgb(255, 32, 32, 40));
		   gdi_layer_clear(GDI_COLOR_TRANSPARENT);

	        switch(cell->image_type)
	        {
	            case MMI_IMAGE_SRC_TYPE_RES_ID:
			        gdi_image_draw_id((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				                       mainmenu_swatch_list.image_offset,
				                       cell->image.res_id);
			        break;
		        case MMI_IMAGE_SRC_TYPE_PATH:
					gdi_image_get_dimension_file((S8 *)cell->image.path, &icon_width, &icon_height);
					if (icon_width > mainmenu_swatch_list.icon_width)
					{
						gdi_image_draw_resized_file((mainmenu_swatch_list.cell_width - 70)/2,
					                         mainmenu_swatch_list.image_offset + (mainmenu_swatch_list.icon_height - 70)/2, 
					                         70,
					                         70,
					                         (S8 *)cell->image.path);
					}
					else
					{
			        gdi_image_draw_file((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				                         mainmenu_swatch_list.image_offset,
				                         (S8 *)cell->image.path);
					}
			        break;
		        case MMI_IMAGE_SRC_TYPE_MEM:
					gdi_image_get_dimension(cell->image_ptr, &icon_width, &icon_height);
					if (icon_width > mainmenu_swatch_list.icon_width)
					{
						gdi_image_draw_resized((mainmenu_swatch_list.cell_width - 70)/2,
					                        mainmenu_swatch_list.image_offset + (mainmenu_swatch_list.icon_height - 70)/2,
					                        70,
					                        70,  
					                        cell->image_ptr);
					}
					else
					{
			        	gdi_image_draw((mainmenu_swatch_list.cell_width - mainmenu_swatch_list.icon_width)/2,
				                        mainmenu_swatch_list.image_offset,
				                        cell->image_ptr);
					}
			        break;
	         }

	         //mmi_mainmenu_swatch_draw_title(cell->string, mainmenu_swatch_list.image_offset + mainmenu_swatch_list.icon_height + 1);
	
	         gdi_layer_pop_and_restore_active();

			 gdi_layer_free(handler);
		}
	}
	else
	{
	    mainmenu_swatch_list.is_cached = MMI_FALSE;
	}
}





#ifdef __MMI_MAINLCD_128X128__
/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_swatch_draw_small
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mainmenu_swatch_draw_small_screen(void)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	S32 i, icon_index = 0;
	mmi_app_package_name_struct package_name;
	MMI_RET result;
	srv_app_info_struct info;
	MMI_ID icon_image;
	swatch_pos_struct icon_layout;
	S16 result_icon;
	U16 image_type;
	//U16 str[4];
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(mainmenu_swatch_list.panel_layer_handle);

	gdi_push_and_set_alpha_blending_source_layer(mainmenu_swatch_list.panel_layer_handle);

	gdi_layer_clear(GDI_COLOR_TRANSPARENT);

	
	//for(i = 0; mainmenu_swatch_list.package_info_array[i] != 0; i++)
	{
		result = srv_appmgr_get_app_package_name_by_id(mainmenu_swatch_list.panel_cell[mainmenu_swatch_list.highlight_index].app_id,
													   package_name);
		
		result = srv_appmgr_get_app_package_info(package_name, &info);

		result_icon = mmi_mainmenu_get_swatch_image_id(mainmenu_swatch_list.panel_cell[mainmenu_swatch_list.highlight_index].app_id, &icon_image);

		//icon_layout = mmi_mainmenu_get_swatch_icon_layout(i - mainmenu_swatch_list.highlight_index);

		//draw icon
		icon_layout.x = MMI_SMALL_SW_SIDE_BAR_BTN_WIDTH + MMI_SMALL_SW_CONTENT_GAP_WITH_SIDE;
		icon_layout.y = MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT + MMI_SMALL_SW_CONTENT_GAP_WITH_SIDE;

		//if((icon_layout.y < LCD_HEIGHT) && (icon_layout.y + SMART_WATCH_MAINMENU_CELL_HEIGHT > 0))
		{
			if(result_icon == 1)
			{
				gdi_image_draw_id(icon_layout.x , icon_layout.y, icon_image);
				//mmi_mainmenu_swatch_draw_title(info.string, icon_layout.y);
			}
			else if(result_icon == 2)
			{
				if(info.image.type == MMI_IMAGE_SRC_TYPE_PATH)
				{
					gdi_image_draw_file(icon_layout.x,icon_layout.y,(S8*)info.image.data.path);
				}
				else if(info.image.type == MMI_IMAGE_SRC_TYPE_RES_ID)
				{
					gdi_image_draw_id(icon_layout.x,icon_layout.y,info.image.data.res_id);
				}
				else if(info.image.type == MMI_IMAGE_SRC_TYPE_MEM)
				{
					gdi_image_draw(icon_layout.x,icon_layout.y,info.image.data.mem);
				}
				else if(info.image.type == MMI_IMAGE_SRC_TYPE_ROM_MEMORY)
				{
					image_type = gdi_image_get_type_from_mem(info.image.data.image.image_ptr);
					gdi_image_draw_mem(icon_layout.x,
									   icon_layout.y,
									   info.image.data.image.image_ptr,
									   image_type,
									   info.image.data.image.image_len);
				}
			}

			//draw text
			mmi_mainmenu_swatch_draw_title(info.string, icon_layout.x ,icon_layout.y);  //mainmenu_swatch_list.highlight_index
		}	
	}  
	
	//draw indicate
	gdi_image_draw_id(icon_layout.x + MMI_SMALL_SW_SCREEN_CONTENT_WIDTH + MMI_SMALL_SW_CONTENT_GAP_WITH_SIDE, \
					MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT, IMG_ID_SWATCH_MAIN_RIGHT1 + mainmenu_swatch_list.highlight_index);
	
	gdi_pop_and_restore_alpha_blending_source_layer();
	
	gdi_layer_pop_and_restore_active();

	gdi_layer_blt(mainmenu_swatch_list.base_layer,
		          mainmenu_swatch_list.panel_layer_handle,
		          mainmenu_swatch_list.status_icon_layer,
		          NULL,
		          0, 0, LCD_WIDTH, LCD_HEIGHT);
}
void mmi_swatch_mainmenu_enter_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	//launch app
	mmi_swatch_mm_launch(LCD_WIDTH/2, LCD_HEIGHT/2);
}
void mmi_swatch_mainmenu_back_key_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GoBackHistory();
}
void mmi_swatch_mainmenu_key_down_handler(void)
{
	if(mainmenu_swatch_list.pen_move_offset < 0)
	{
	    mainmenu_swatch_list.start_anim_pos = -5;
	    mainmenu_swatch_list.end_anim_pos = 0;
	    mainmenu_swatch_list.speed = 1;
		mmi_swatch_mm_swap_animation();
	}
    else
    {
        mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
	    mainmenu_swatch_list.end_anim_pos = mainmenu_swatch_list.pen_move_offset - mainmenu_swatch_list.page_size;
	    mainmenu_swatch_list.speed = 4;
		mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
		StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
	    //gui_start_timer(SMART_WATCH_MAINMENU_ANIM_TIMER, mmi_swatch_mm_swap_animation);
    }
}

void mmi_swatch_mainmenu_key_down_ex_handler(void)
{
    if(mainmenu_swatch_list.disable_array_image == MMI_TRUE)
    {
        return;
    }
	
	if(mainmenu_swatch_list.pen_move_offset == 0)
	{
	    mainmenu_swatch_list.start_anim_pos = 0;
		mainmenu_swatch_list.end_anim_pos = -5;
		mainmenu_swatch_list.speed = 1;
		mmi_swatch_mm_swap_animation();
	    //mmi_mainmenu_swatch_draw_panel();
	    //gui_start_timer(SMART_WATCH_MAINMENU_ANIM_TIMER, mmi_swatch_mm_swap_animation);
	}
	mainmenu_swatch_list.disable_array_image = MMI_TRUE;
}


void mmi_swatch_mainmenu_key_up_handler(void)
{
    S32 page_dis;
	
    page_dis = (mainmenu_swatch_list.total_icon_num - 1) / mainmenu_swatch_list.mainmenu_page_num;
    page_dis = page_dis * mainmenu_swatch_list.page_size;
	
	if(mainmenu_swatch_list.pen_move_offset > page_dis)
	{
	    mainmenu_swatch_list.start_anim_pos = page_dis + 5;
	    mainmenu_swatch_list.end_anim_pos = page_dis;
	    mainmenu_swatch_list.speed = 1;
		mmi_swatch_mm_swap_animation();
	}
    else
    {
        mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
	    mainmenu_swatch_list.end_anim_pos = mainmenu_swatch_list.pen_move_offset + mainmenu_swatch_list.page_size;
	    mainmenu_swatch_list.speed = 4;
		mmi_mainmenu_swatch_draw_panel(MMI_FALSE);
		StartNonAlignTimer(MAINMENU_SWATCH_ANIMATE_TIMER,
					               mainmenu_swatch_list.mainmenu_anim_timer,
					               mmi_swatch_mm_swap_animation);
	    //gui_start_timer(SMART_WATCH_MAINMENU_ANIM_TIMER, mmi_swatch_mm_swap_animation);
    }
}

void mmi_swatch_mainmenu_key_up_ex_handler(void)
{
    S32 page_dis;
	
    page_dis = (mainmenu_swatch_list.total_icon_num - 1) / mainmenu_swatch_list.mainmenu_page_num;
    page_dis = page_dis * mainmenu_swatch_list.page_size;
 
    if(mainmenu_swatch_list.disable_array_image == MMI_TRUE)
    {
        return;
    }
		
	if(mainmenu_swatch_list.pen_move_offset == page_dis)
	{
	    mainmenu_swatch_list.start_anim_pos = mainmenu_swatch_list.pen_move_offset;
		mainmenu_swatch_list.end_anim_pos = mainmenu_swatch_list.pen_move_offset + 5;
		mainmenu_swatch_list.speed = 1;
	    mmi_swatch_mm_swap_animation();
	}

	mainmenu_swatch_list.disable_array_image = MMI_TRUE;
}

#endif /*__MMI_MAINLCD_128X128__*/

#ifdef __MMI_MAINLCD_128X32__


/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mm_launch_art
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swatch_mm_launch_art(void)
{
    mmi_app_package_name_struct package_name;
    srv_appmgr_get_app_package_name_by_id(mainmenu_swatch_list.panel_cell[highlight_index].app_id,
									      package_name);
	srv_appmgr_launch(package_name);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mm_change_highlight
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_swatch_mm_change_highlight(void)
{
    highlight_index++;
	if(highlight_index >= mainmenu_swatch_list.total_icon_num)
	{
	    highlight_index = 0;
	}

	mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.page_size * (highlight_index / 4);
	mainmenu_swatch_list.prevpen_move_offset = mainmenu_swatch_list.pen_move_offset;

	mmi_mainmenu_swatch_draw_panel(MMI_TRUE);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_swatch_mainmenu_enter_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  group_id
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_swatch_mainmenu_enter_proc(mmi_event_struct * evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_KEY_CLICK_SINGLE:
			mmi_swatch_mm_change_highlight();
			break;
	    default:
			break;
	}
	return MMI_RET_OK;	

}


#endif


/*****************************************************************************
 * FUNCTION
 *  mmi_mainmenu_swatch_clear_panel_layer
 * DESCRIPTION
 *  swatch mainmenu draw panel
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_mainmenu_swatch_clear_panel_layer(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gdi_layer_push_and_set_active(mainmenu_swatch_list.panel_layer_handle);
	#ifdef __MMI_WEARABLE_DEVICE_UI_ENHANCE__
	gdi_layer_clear(gdi_act_color_from_rgb(255, 0, 0, 0));
	#else
	gdi_layer_clear(gdi_act_color_from_rgb(255, 32, 32, 40));
	#endif /*__MMI_WEARABLE_DEVICE_UI_ENHANCE__*/
	gdi_layer_pop_and_restore_active();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_main_menu_entry_swarch_style
 * DESCRIPTION
 *  main meun entry function for smart watch
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_main_menu_entry_swarch_style()
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mmi_smart_watch_mainmenu_type_init();
	memset(&mainmenu_swatch_list.panel_cell, 0, sizeof(mmi_watch_cell_struct)*SMART_WATCH_MAINMENU_ITEM_NUM);
	mmi_mainmenu_get_swatch_package_list();
	mmi_main_menu_cache_cell_icon();

	mainmenu_swatch_list.pen_move_offset = mainmenu_swatch_list.prevpen_move_offset;
	mainmenu_swatch_list.end_anim_pos = -100;

	mainmenu_swatch_list.disable_array_image = MMI_FALSE;

	ReadValueSlim(NVRAM_MAINMENU_HIGHLIGHT_INDEX, &mainmenu_swatch_list.highlight_index, DS_DOUBLE);

	//mainmenu_swatch_list.layer_buffer = mmi_frm_asm_alloc_anonymous_nc(LCD_WIDTH * LCD_HEIGHT * 2);

	#if defined(__MMI_MAINLCD_128X128__)
	mainmenu_swatch_list.status_bar_buf_ptr = mmi_frm_asm_alloc_anonymous_nc(LCD_WIDTH * MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT * 4);
	#elif defined(__MMI_MAINLCD_128X32__)
    mainmenu_swatch_list.status_bar_buf_ptr = NULL;
	#else
	mainmenu_swatch_list.status_bar_buf_ptr = mmi_frm_asm_alloc_anonymous_nc(LCD_WIDTH * MMI_STATUS_ICON_BAR_HEIGHT * 4);
	#endif /*__MMI_MAINLCD_128X128__*/

	gdi_layer_create(0,
					 0,
					 LCD_WIDTH,
					 LCD_HEIGHT,
					 &mainmenu_swatch_list.panel_layer_handle);

	#ifndef __MMI_MAINLCD_128X32__
	#ifdef __MMI_MAINLCD_128X128__
	gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        LCD_WIDTH,
        MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT,
        &mainmenu_swatch_list.status_icon_layer,
        mainmenu_swatch_list.status_bar_buf_ptr,
        LCD_WIDTH * MMI_SMALL_SW_STATUS_ICON_BAR_HEIGHT * 4);
	#else
	gdi_layer_create_cf_using_outside_memory(
        GDI_COLOR_FORMAT_32_PARGB,
        0,
        0,
        LCD_WIDTH,
        MMI_STATUS_ICON_BAR_HEIGHT,
        &mainmenu_swatch_list.status_icon_layer,
        mainmenu_swatch_list.status_bar_buf_ptr,
        LCD_WIDTH * MMI_STATUS_ICON_BAR_HEIGHT * 4);
	#endif /*__MMI_MAINLCD_128X128__*/
	#endif

	gdi_layer_get_base_handle(&mainmenu_swatch_list.base_layer);
	
	mmi_mainmenu_swatch_clear_panel_layer();

	#ifndef __MMI_MAINLCD_128X32__
	mmi_main_menu_swatch_draw_status_icon();
	#endif
	
	mmi_mainmenu_swatch_draw_panel(MMI_FALSE);

    #if (defined(__MMI_TOUCH_SCREEN__) && defined(__TOUCH_PANEL_CAPACITY__))
    mmi_pen_config_sampling_period(1, MMI_PEN_SAMPLING_PERIOD_2);
    mmi_pen_config_move_offset(
        1,
        MMI_PEN_SKIP_STROKE_MOVE_OFFSET,
        1,
        MMI_PEN_SKIP_STROKE_LONGTAP_OFFSET);
    #endif /* __MMI_TOUCH_SCREEN__ */

	mmi_pen_register_down_handler(mmi_swatch_mm_pen_down_hdlr);
	mmi_pen_register_move_handler(mmi_swatch_mm_pen_move_hdlr);
	mmi_pen_register_up_handler(mmi_swatch_mm_pen_up_hdlr);
	#ifdef __MMI_MAINLCD_128X128__
	mmi_frm_set_key_handler(mmi_swatch_mainmenu_enter_key_handler,KEY_LSK,KEY_EVENT_UP);
	mmi_frm_set_key_handler(mmi_swatch_mainmenu_back_key_handler,KEY_RSK,KEY_EVENT_UP);
	mmi_frm_set_key_handler(mmi_swatch_mainmenu_key_down_handler,KEY_DOWN_ARROW,KEY_EVENT_UP);
    mmi_frm_set_key_handler(mmi_swatch_mainmenu_key_up_handler,KEY_UP_ARROW,KEY_EVENT_UP);
	mmi_frm_set_key_handler(mmi_swatch_mainmenu_key_down_ex_handler,KEY_DOWN_ARROW,KEY_EVENT_DOWN);
    mmi_frm_set_key_handler(mmi_swatch_mainmenu_key_up_ex_handler,KEY_UP_ARROW,KEY_EVENT_DOWN);
	#endif /*__MMI_MAINLCD_128X128__*/
	#if defined(__DELETE_APP_IN_MAINMENU__)
	mmi_pen_register_long_tap_handler(mmi_swatch_mm_pen_long_tap_hdlr);
	#endif /*__DELETE_APP_IN_MAINMENU__*/

	#ifdef __MMI_MAINLCD_128X32__
	mmi_frm_set_key_handler(mmi_swatch_mm_launch_art,KEY_POWER,KEY_LONG_PRESS);
	//mmi_frm_set_key_handler(mmi_swatch_mm_launch_art,KEY_LSK,KEY_LONG_PRESS);
	mmi_frm_cb_reg_event(EVT_ID_KEY_CLICK_SINGLE, mmi_swatch_mainmenu_enter_proc, NULL);
	#endif
}

#endif /*__MMI_WEARABLE_DEVICE__*/
#endif /*__MMI_IDLE_CLASSIC_AND_MAINMENU_SUPPORT__*/


