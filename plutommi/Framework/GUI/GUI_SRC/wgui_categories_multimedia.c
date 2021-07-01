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
 *  wgui_categories_multimedia.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Multimedia related categories.
 *
 *  [Category221]       Empty Screen
 *  [Category222]       View Image Screen
 *  [Category223]       Play Audio Screen
 *  [Category224]       Play Video Full Screen
 *  [Category225]       Play Video Standard Screen (With title & softkey)
 *
 *  [Category331][SUB]  Emptry Sublcd Screen
 *  [Category332][SUB]  Image Icon Sublcd Screen 
 *  [Category333][SUB]  Play Audio Sublcd Screen
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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
#include "MMI_features.h"
#include "ProfilesSrvGprot.h"
#include "lcd_if.h"
#include "PhoneSetupGprots.h"   /* PhnsetGetDefEncodingType() */
#include "Conversions.h"        /* char set conversion */
#include "ImageViewerGprot.h"

#include "mdi_datatype.h"
#include "mdi_audio.h"

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
#include "mdi_video.h"  /* video lib */


#include "lcd_sw_rnd.h"
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

#ifdef __MMI_TVOUT__
#include "mdi_tv.h"     /* mdi tvout */
#include "WallpaperDefs.h"      /* some header for phonsetup.h */
#include "PhoneSetup.h" /* tvout display style */
#endif /* __MMI_TVOUT__ */ 

#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
#endif

#ifdef __MMI_AVATAR__
#include "avatargprot.h"
#endif

#include "wgui_softkeys.h"
#include "MMIDataType.h"
#include "gdi_datatype.h"
#include "wgui_categories_list.h"
#include "gui_data_types.h"
#include "gdi_const.h"
#include "gdi_include.h"
#include "wgui_draw_manager.h"
#include "wgui.h"
#include "gui_typedef.h"
#include "wgui_title.h"
#include "ScreenRotationGprot.h"
#include "wgui_categories_util.h"
#include "wgui_inputs.h"
#include "gui.h"
#include "wgui_include.h"
#include "mmi_frm_events_gprot.h"
#include "wgui_categories_enum.h"
#include "GlobalConstants.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "gui_themes.h"
#include "CustThemesRes.h"
#include "FileMgrSrvGProt.h"
#include "gui_config.h"
#include "gui_inputs.h"
#include "wgui_categories_inputs.h"
#include "CustDataRes.h"
#include "FileMgrServiceResDef.h"
#include "GlobalResDef.h"
#include "FileMgrResDef.h"
#include "FileMgrType.h"
#include "FileMgrGProt.h"
#include "custom_mmi_default_value.h"
#include "gui_switch.h"
#include "lcd_sw_inc.h"
#include "Gui_Setting.h"
#include "wgui_categories_multimedia.h"
#include "DebugInitDef_Int.h"
#include "mmi_frm_mem_gprot.h"
#include "GpioSrvGprot.h"
#include "mmi_frm_input_gprot.h"
#include "mmi_rp_app_uiframework_def.h"
#include "mmi_frm_history_gprot.h"
#include "custom_srv_prof_defs.h"
#include "gui_buttons.h"
#include "wgui_touch_screen.h"
#include "gui_theme_struct.h"
#include "gui_windows.h"
#include "PixcomFontEngine.h"
#include "wgui_categories_sublcd.h"
#ifdef __PLUTO_MMI_PACKAGE__
#if defined(__MMI_VIDEO_PLAYER__) || (!defined(__MMI_VIDEO_PLAYER__) && (defined(__MMI_VIDEO_PLAY_SUPPORT__) || (defined(__MMI_VIDEO_RECORDER__) && !defined(__MMI_CAMCORDER__))))
#include "mmi_rp_app_vdoply_def.h"
#endif
#endif
#include "mdi_include.h"
/****************************************************************************
* Define
*****************************************************************************/

/****************************************************************************
* Global Variable
*****************************************************************************/
extern S16 status_icon;
extern S32 wgui_image_clip_x1;
extern S32 wgui_image_clip_x2;
extern S32 wgui_image_clip_y1;
extern S32 wgui_image_clip_y2;
extern U8 wgui_category_screen_no_buttons;
//extern U16 title_bg_id;
extern gdi_handle wgui_layer_1;
extern gdi_handle wgui_base_layer;
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
extern S8 *idle_screen_wallpaper_name;
#endif
/****************************************************************************
* Global Function
*****************************************************************************/
extern void wgui_set_animation_image_y(S32 x, S32 y, PU8 img);
extern void wgui_show_transparent_animation(void);
extern void set_main_LCD_time_duration_hide_function(void (*f) (S32 x1, S32 y1, S32 x2, S32 y2));
extern U16 PhnsetGetCurWallPaperIdx(void);
#if defined(__MMI_LANGLN__)
extern void mmi_langln_bsk_stop_auto_scroll(void);
#endif

#ifdef __MMI_AUDIO_PLAYER__
extern int mmi_audply_exit_subLCD(void);
extern int mmi_audply_redraw_subLCD(BOOL);
extern BOOL mmi_audply_is_playing(void);
#endif /* __MMI_AUDIO_PLAYER__ */ 

#ifdef __MMI_FM_RADIO__
extern int mmi_fmrdo_exit_subLCD(void);
extern int mmi_fmrdo_redraw_subLCD(BOOL);
extern BOOL mmi_fmrdo_is_power_on(void);
#endif /* __MMI_FM_RADIO__ */ 

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
mdi_video_info_struct wgui_video_info;
#endif 

#if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
extern void DrawCate16CategoryBeforeBLTCallback(GDI_RESULT return_code);
extern void PhnsetWallpaperBadFileCallBack(U16 imgID);

extern void dm_category_33_controlled_area(dm_coordinates *coordinate);
extern void ShowCategory33Screen_ext(
                U16 left_softkey,
                U16 left_softkey_icon,
                U16 right_softkey,
                U16 right_softkey_icon,
                U8 *history_buffer);
extern void ExitCategory33Screen(void);
#endif

extern S32 mmi_is_redrawing_bk_screens(void);

/****************************************************************************
* Local Variable
*****************************************************************************/
/* [Category 221] */
static FuncPtr cat221_redraw_content_callback = NULL;
static gdi_color cat221_background_color;

/* [Category 222] */
static PS8 cat222_file_name_ptr;
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__ 
static UI_string_type cat222_title;
static PS8 cat222_button_str_ptr;   /* will use subMenu's data buffer to store */
static BOOL cat222_is_short_filename;
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__ */
static void (*cat222_decode_result_callback) (GDI_RESULT);
static GDI_HANDLE cat222_anim_handle;
static gdi_image_src_enum cat222_src_type;
static MMI_BOOL g_wgui_cat222_err_msg_display = MMI_TRUE;

#ifdef __MMI_TVOUT__
static BOOL cat222_is_fullscr_tvout = FALSE;
#endif 


/* [Category Vdoply] */
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
static U16 cat_vdoply_video_repeat_count;
static U64 cat_vdoply_video_start_time;
static U64 cat_vdoply_video_total_time;
static BOOL cat_vdoply_video_is_visual_update;
static BOOL cat_vdoply_video_is_play_audio;
static BOOL cat_vdoply_video_is_lcd_no_sleep;
static BOOL cat_vdoply_is_video_open;
static BOOL cat_vdoply_is_video_play;
static BOOL cat_vdoply_is_video_finished;
static MDI_RESULT cat_vdoply_is_video_play_result = -1;
static BOOL cat_vdoply_is_video_force_stop; /* force stop flag */
static BOOL cat_vdoply_is_video_from_id;
static GDI_HANDLE cat_vdoply_video_layer = GDI_ERROR_HANDLE;
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
static U32 g_cat_vdoply_3d_track_index;
static MMI_BOOL g_cat_vdoply_is_3d_type = MMI_FALSE;
static U32 g_cat_vdoply_2d_track_index;
static MMI_BOOL g_cat_vdoply_is_2d_type = MMI_FALSE;
#endif
#ifdef __MMI_SUBLCD__
static BOOL cat_vdoply_is_sublcd_display = FALSE;   /* must init */
#endif 
static void (*cat_vdoply_play_finish_callback) (MDI_RESULT result);
static U8 cat_vdoply_is_full_screen;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_SWFLASH__)
static U8 cat_vdoply_audio_volumn;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
static U8 cat_single_player_audio_volumn;
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

#if !defined(__MMI_SLIM_IMG_RES__)
static mmi_ret wgui_cat129_key_proc(mmi_event_struct *event);
#endif
/* [Category 229 ] */
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */ 
#endif

#if defined(__MMI_AVATAR__)
static MMI_BOOL cat_avatar_is_valid;
static U32 cat34_avatar_ptr;
static U32 cat34_avatar_serial_num;
static GDI_HANDLE cat34_anim_handle;
#endif

#if defined(__MMI_AVATAR__) || defined(__MMI_SWFLASH__)
static S32 g_mmi_idle_bg_media_type = 0;
static GDI_HANDLE cat_swflash_layer = GDI_ERROR_HANDLE;
#endif
/****************************************************************************
* Local Function
*****************************************************************************/
/* [Category 221] */
static void ExitCategory221Screen(void);

/* [Category 222] */
static void ExitCategory222Screen(void);
static void Cat222DecodeImage(void);
static void Cat222DrawTitle(void);
static void DrawCate222CategoryControlArea(dm_coordinates *coordinate);

/* [Category 223] */
static void wgui_cat223_exit(void);
static void wgui_cat223_draw_ctrl_area1(dm_coordinates *coordinate);
static void wgui_cat223_init_duration(UI_time *t, U32 duration);
static void wgui_cat223_hide_duration(S32 x1, S32 y1, S32 x2, S32 y2);

#ifdef __MMI_VIDEO_PLAY_SUPPORT__
   /* [Category Video Play Screen] */
typedef struct
{
    U64 playing_time;
    U16 history_id;
} wgui_catvdoply_history_struct;
static void ShowCategoryVdoplyScreen(BOOL is_fullscreen,
                                     U16 title_str,
                                     U16 title_icon,
                                     U16 lsk_str,
                                     U16 rsk_str,
                                     U16 video_id,
                                     PS8 video_filename,
                                     U16 repeat_count,
                                     BOOL is_visual_update,
                                     BOOL is_play_audio,
                                     BOOL is_lcd_no_sleep,
                                     GDI_COLOR bg_color, void (*play_finish_callback) (MDI_RESULT), void *gui_buffer);
static void ExitCategoryVdoplyScreen(void);
static void StopCategoryVdoplyVideo(void);
static void PauseCategoryVdoplyVideo(void);
static void ResumeCategoryVdoplyVideo(void);
static void CatVdoplyPlayFinishCallback(MDI_RESULT result, void *user_data);

#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
#endif
#endif


#ifdef __MMI_SUBLCD__
static void EnterCategoryVdoplySubScreen(void);
static void ExitCategoryVdoplySubScreen(void);
#endif /* __MMI_SUBLCD__ */ 
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) || defined(__MMI_SWFLASH__)
static void CatVdoplyVolUp(void);
static void CatVdoplyVolDown(void);
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
static void cat_single_player_volumn_up(void);
static void cat_single_player_volumn_down(void);
#endif 

#ifdef __MMI_SUBLCD__
/* [Category 331] [SUB] */
static void ExitCategory331Screen(void);

/* [Category 331] [SUB] */
static void ExitCategory332Screen(void);

/* [Category 333] [SUB] */
static U8 *GetCategory333History(U8 *history_buffer);
static S32 GetCategory333HistorySize(void);
static void ExitCategory333Screen(void);
static void RedrawCategory333Screen(void);
#endif /* __MMI_SUBLCD__ */ 

static void wgui_cat_hide_title_button(void *button_object);
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_ALPHA_BLENDING__) && defined(__MMI_SWFLASH__)
/* under construction !*/
#endif /* __MMI_ALPHA_BLENDING__ */
/* under construction !*/
#ifdef __MMI_CAT44X_SUPPORT__
/* under construction !*/
/* under construction !*/
#endif /*__MMI_CAT44X_SUPPORT__*/
#endif

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__)
static S32 g_wgui_catvdo_drm_flag = 0;
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__) */

#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__)
static void wgui_cat129_hide_title_callback(S32 x, S32 y, S32 w, S32 h);
#endif
/****************************************************************************
*
* MultiMedia Related [MainLCD] Categories
*
*****************************************************************************/

/*****************************************************************************
* [Category221]
*
* This category is basic frame with caption and softkeys.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *                 <----------- Empty. Will hook call back function to redraw.
*  *                    *
*  *                    *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  DrawCate221CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category221 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCate221CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(g_dm_data.s32flags & DM_NO_TITLE))
    {
#if defined(GUI_COMMON_USE_SPECIFIC_STYLE)
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
    #if defined(GUI_COMMON_USE_THICK_TITLE)
        wgui_title_set_thick(MMI_TRUE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
    #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
        wgui_title_set_thick(MMI_FALSE);
        move_title(MMI_TITLE_X, MMI_TITLE_Y);
        resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
    #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */

    #if defined(__MMI_SCREEN_ROTATE__)
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            show_title_status_icon();
        }
    #else /* defined(__MMI_SCREEN_ROTATE__) */ 
        show_title_status_icon();
    #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
#else /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
    #if defined(__MMI_SCREEN_ROTATE__)
        if (!mmi_frm_is_screen_width_height_swapped())
    #endif /* defined(__MMI_SCREEN_ROTATE__) */
        {
            #if defined(GUI_COMMON_USE_THICK_TITLE)
                wgui_title_set_thick(MMI_TRUE);
                move_title(MMI_TITLE_X, 0);
                resize_title(MMI_TITLE_WIDTH, MMI_THICK_TITLE_HEIGHT);
            #else /* defined(GUI_COMMON_USE_THICK_TITLE) */
                wgui_title_set_thick(MMI_FALSE);
                move_title(MMI_TITLE_X, 0);
                resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
            #endif /* defined(GUI_COMMON_USE_THICK_TITLE) */
        }
    #if defined(__MMI_SCREEN_ROTATE__)
        else
        {
            wgui_title_set_thick(MMI_FALSE);
            move_title(MMI_TITLE_X, 0);
            resize_title(MMI_TITLE_WIDTH, MMI_THIN_TITLE_HEIGHT);
        }
    #endif /* defined(__MMI_SCREEN_ROTATE__) */
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
#else /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */
    #if defined(__MMI_SCREEN_ROTATE__)
        if (!mmi_frm_is_screen_width_height_swapped())
        {
            show_title_status_icon();
        }
    #else /* defined(__MMI_SCREEN_ROTATE__) */ 
        show_title_status_icon();
    #endif /* defined(__MMI_SCREEN_ROTATE__) */ 
#endif /* defined(GUI_COMMON_USE_SPECIFIC_STYLE) */

        draw_title();
    }

    /* fill background */
    gdi_layer_reset_clip();

    /* if has title - draw content region only */
    if (!(g_dm_data.s32flags & DM_NO_TITLE))
    {
        gdi_draw_solid_rect(
            0,
            (MMI_title_y + MMI_title_height),
            UI_device_width - 1,
            (MMI_title_y + MMI_title_height) + MMI_content_height - 1,
            cat221_background_color);
    }
    else
    {
        gdi_draw_solid_rect(
            0,
            0,
            UI_device_width - 1,
            (MMI_title_y + MMI_title_height) + MMI_content_height - 1,
            cat221_background_color);
    }

    /* redraw callback function */
    if (cat221_redraw_content_callback != NULL)
    {
        cat221_redraw_content_callback();
    }

}


/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory221Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        gdi_color background_color,
        FuncPtr redraw_content_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 flags = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_SCREEN_ROTATE__)
    if (!(mmi_frm_is_screen_width_height_swapped()))
#endif /* defined(__MMI_SCREEN_ROTATE__) */
    {
        gui_setup_common_layout();
    }

    cat221_background_color = background_color;
    cat221_redraw_content_callback = redraw_content_callback;

    /* hide status if will not draw title bar */
#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
    if (title == 0 && title_icon == 0)
    {
        wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_H_BAR);
        flags |= DM_NO_TITLE;
    }
#endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */ 

    /* lock */
    gui_lock_double_buffer();

    wgui_title_set_menu_shortcut_number(-1);
	if((left_softkey == 0)&&(right_softkey == 0))
	{
		clear_category_screen_key_handlers();
		clear_left_softkey();
		clear_right_softkey();
	    flags |= DM_NO_SOFTKEY;
    }
	else
	{
        dm_add_softkey_id(left_softkey, right_softkey);
	}
    /* init title */
    dm_add_title_id(title, title_icon);

#if defined(__MMI_SCREEN_ROTATE__)
    if (mmi_frm_is_screen_width_height_swapped())
    {
        wgui_softkey_disable_text_translucence();
    }
#endif /* defined(__MMI_SCREEN_ROTATE__) */

    gui_unlock_double_buffer();

    dm_register_category_controlled_callback(DrawCate221CategoryControlArea);
    wgui_cat_setup_category_default_history(MMI_CATEGORY221_ID, flags, ExitCategory221Screen);
    dm_redraw_category_screen();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory221Screen
 * DESCRIPTION
 *  Exit category 221
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory221Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    reset_softkeys();

#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_H_BAR);
#endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */

}

/*****************************************************************************
* [Category222]
*
* This category is for view image from file.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *       (Image)      *
*  *                    *
*  *                    *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
#ifdef __MMI_NONBLOCKING_DECODE__
    #define __MMI_CAT222_NON_BLOCKING_DECODER__
#endif /* __MMI_NONBLOCKING_DECODE__ */

#if !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)
#define     CAT222_IMAGE_SPACING    (5) /* spacing between image and LCM boundry */
#else /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */ 
#define     CAT222_IMAGE_SPACING    (4) /* spacing between image and LCM boundry */
#endif /* !defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__) */ 


#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
static void DrawCate222CategoryControlArea2(dm_coordinates *coordinate)
{
    GDI_HANDLE bg_layer;

    gdi_layer_create_cf(
        GDI_COLOR_FORMAT_24,
        0, 0, UI_device_width, UI_device_height, &bg_layer);
    dm_add_blt_layer(bg_layer, DM_LAYER_BOTTOM);
    
    gdi_layer_push_and_set_active(bg_layer);
    gdi_layer_reset_clip();
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_draw_solid_rect(
        0, 0, UI_device_width - 1, UI_device_height - 1,
        gdi_act_color_from_rgb(0xFF, current_MMI_theme->lite_disp_scr_bg_color->r, current_MMI_theme->lite_disp_scr_bg_color->g, current_MMI_theme->lite_disp_scr_bg_color->b));
    gdi_layer_pop_and_restore_active();

	gdi_set_alpha_blending_source_layer(bg_layer);
}
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */


/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory222ScreenInternal_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        gdi_color background_color,
        S8 *button_string,
        S8 *file_name_ptr,
        BOOL is_short_filename,
        void (*decode_result_callback) (GDI_RESULT),
        gdi_image_src_enum src_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_setup_common_layout();

    cat222_file_name_ptr = file_name_ptr;
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__ 
    cat222_title = title;
    cat222_is_short_filename = is_short_filename;
#endif
    cat222_decode_result_callback = decode_result_callback;
    cat222_anim_handle = GDI_NULL_HANDLE;
    cat222_src_type = src_type;
    
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__ 
    if (button_string != NULL)
    {
        cat222_button_str_ptr = (S8*) (subMenuDataPtrs[0]); /* use submenu's data buffer, not a good solution */

        memset(cat222_button_str_ptr, 0, MAX_SUB_MENU_SIZE);
        mmi_ucs2ncpy(cat222_button_str_ptr, button_string, (MAX_SUB_MENU_SIZE / ENCODING_LENGTH) - 1);
    }
    else
    {
        cat222_button_str_ptr = NULL;
    }
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__ */

    wgui_title_set_menu_shortcut_number(-1);

    dm_add_title(title, title_icon);
    dm_add_softkey_str(left_softkey, right_softkey);

    ExitCategoryFunction = ExitCategory222Screen;

    dm_setup_category_functions(UI_dummy_function, dm_get_category_history, dm_get_category_history_size);
    dm_register_category_controlled_callback(DrawCate222CategoryControlArea);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY222_ID;
#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    wgui_set_wallpaper_on_bottom(MMI_TRUE);
#endif
    dm_register_category_controlled2_callback(DrawCate222CategoryControlArea2);
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_BLT;
#else /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND | DM_NO_BLT | DM_LITE_DISP_WALLPAPER;
#endif /* MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24 */
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();
    /* Draw Image */
    Cat222DecodeImage();
}



/*****************************************************************************
 * FUNCTION
 *  ShowCategory222Screen
 * DESCRIPTION
 *  Show Category 222 Screen.
 * PARAMETERS
 *  title                       [IN]        Title string
 *  title_icon                  [IN]        Title image id
 *  left_softkey                [IN]        Lsk string id
 *  left_softkey_icon           [IN]        Lsk image id
 *  right_softkey               [IN]        Rsk string id
 *  right_softkey_icon          [IN]        Rsk image id
 *  background_color            [IN]        Background color for content region
 *  button_string               [IN]        String on LSK region. (If this pointer is not NULL, the string will draw on lsk region.)
 *  file_name_ptr               [IN]        Filename to be decode.
 *  is_short_filename           [IN]        File name is short or not.
 *  decode_result_callback      [IN]        Decode result callback function
 *  EX: It may be used as show index/total number.(?)
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory222Screen_int(
        U16 title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        gdi_color background_color,
        S8 *button_string,
        S8 *file_name_ptr,
        BOOL is_short_filename,
        void (*decode_result_callback) (GDI_RESULT),
        gdi_image_src_enum src_type)
{
    ShowCategory222ScreenInternal_int(
        (UI_string_type) get_string(title),
        (PU8) get_image(title_icon),
        (UI_string_type) get_string(left_softkey),
        (UI_string_type) get_string(right_softkey),
        background_color,
        button_string,
        file_name_ptr,
        is_short_filename,
        decode_result_callback,
        src_type);
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory222Screen
 * DESCRIPTION
 *  Exit Category 222 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory222Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_setup_default_layout();

    if (cat222_anim_handle != GDI_NULL_HANDLE)
    {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
        gdi_image_nb_stop(cat222_anim_handle);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        gdi_image_stop_animation(cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
    }

    reset_softkeys();

    g_wgui_cat222_err_msg_display = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate222CategoryControlArea
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category222 screen
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate222CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__ 
    S32 str_height;
    S32 str_width;
    S32 spacing;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat222_button_str_ptr != NULL)
    {
        gdi_layer_push_and_set_clip(0, UI_device_width - MMI_button_bar_height, UI_device_width - 1, UI_device_height - 1);

        /* draw button string */
        gui_set_font(&MMI_medium_font);

        gui_measure_string((UI_string_type) cat222_button_str_ptr, &str_width, &str_height);
        spacing = (MMI_button_bar_height - str_height) >> 1;

        if (mmi_fe_get_r2l_state())
        {
            gui_move_text_cursor(spacing + str_width, UI_device_height - MMI_button_bar_height + spacing);
        }
        else
        {
            gui_move_text_cursor(spacing, UI_device_height - MMI_button_bar_height + spacing);
        }

        gui_set_text_color(*current_MMI_theme->list_normal_text_color);
        gui_print_text((UI_string_type) cat222_button_str_ptr);

        gdi_layer_pop_text_clip();
    }
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__ */

    Cat222DrawTitle();
}


/*****************************************************************************
 * FUNCTION
 *  Cat222DrawTitle
 * DESCRIPTION
 *  draw cat 222 title
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222DrawTitle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if !defined(__MMI_CATEGORY_MULTIMEDIA_SLIM__) && defined(__MMI_FILE_MANAGER__)
    S32 str_len;
    S32 index;
    S8 buf_filename_no_ext[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];
    S8 buf_filename_dest[(SRV_FMGR_PATH_MAX_FILE_NAME_LEN + 1) * ENCODING_LENGTH];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat222_title == NULL)
    {
        /* display filename */
        str_len = mmi_ucs2strlen(cat222_file_name_ptr);

        /* find file name - by finding "\\" */
        for (index = str_len * 2 - 2; index >= 2; index -= 2)
        {
            if (mmi_ucs2ncmp((PS8) & cat222_file_name_ptr[index], (PS8) L"\\", 1) == 0)
            {
                index += 2;
                break;
            }
        }

        mmi_ucs2ncpy((PS8) buf_filename_no_ext, (PS8) (&(cat222_file_name_ptr[index])), SRV_FMGR_PATH_MAX_FILE_NAME_LEN);

        srv_fmgr_path_hide_extension((WCHAR *)buf_filename_no_ext);

        /* short name encoding */
        if (cat222_is_short_filename)
        {
            mmi_chset_mixed_text_to_ucs2_str(
                (U8*) buf_filename_dest,
                sizeof(buf_filename_dest),
                (U8*) buf_filename_no_ext,
                (mmi_chset_enum)PhnsetGetDefEncodingType());

            ChangeTitleString((PU8) (buf_filename_dest));
        }
        else
        {
            ChangeTitleString((PU8) (buf_filename_no_ext));
        }
    }
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__*/

    draw_title();
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void wgui_cat222_disable_err_msg_display(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat222_err_msg_display = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  Cat222ShowErrMsg
 * DESCRIPTION
 *  Display error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222ShowErrMsg(UI_string_type err_str_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__
    S32 str_len, line_height;
#endif 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (err_str_ptr == NULL)
    {
        return;
    }

    gdi_layer_push_clip();
    gdi_layer_push_text_clip();

    gdi_layer_set_clip(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1);

#ifdef __MMI_WALLPAPER_ON_BOTTOM__
    gdi_draw_solid_rect(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1,
        gdi_act_color_from_rgb(0xFF, current_MMI_theme->lite_disp_scr_bg_color->r, current_MMI_theme->lite_disp_scr_bg_color->g, current_MMI_theme->lite_disp_scr_bg_color->b));
#else /* __MMI_WALLPAPER_ON_BOTTOM__ */
    gdi_draw_solid_rect(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1,
        GDI_COLOR_WHITE);
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */

    if (g_wgui_cat222_err_msg_display == MMI_TRUE)
    {
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__
        /* show error string in multi-line input box */
        str_len = mmi_ucs2strlen((PS8) err_str_ptr);

        create_multiline_inputbox_set_buffer(err_str_ptr, str_len, str_len, 0);
        MMI_multiline_inputbox.flags |= UI_MULTI_LINE_INPUT_BOX_DISABLE_CURSOR_DRAW
            | UI_MULTI_LINE_INPUT_BOX_CENTER_JUSTIFY
            | UI_MULTI_LINE_INPUT_BOX_DISABLE_BACKGROUND
            | UI_MULTI_LINE_INPUT_BOX_DISABLE_SCROLLBAR | UI_MULTI_LINE_INPUT_BOX_VIEW_MODE;

        MMI_multiline_inputbox.text_font = &MMI_medium_font;
#ifdef __MMI_FTE_SUPPORT__
		MMI_multiline_inputbox.normal_text_color = *current_MMI_theme->popup_text_color;
#endif
        /* resize to content size and call show_xx_no_draw function to calc its line count */
        resize_multiline_inputbox(MMI_content_width, MMI_content_height);
        move_multiline_inputbox(MMI_content_x, MMI_content_y);

        /* vertical center alignment */
        show_multiline_inputbox_no_draw();
        line_height = get_multiline_inputbox_line_height();
        resize_multiline_inputbox(
            UI_device_width,
            (MMI_multiline_inputbox.n_lines * line_height) + MULTILINE_INPUTBOX_HEIGHT_PAD + MMI_multiline_inputbox.text_y);
        move_multiline_inputbox(
            0,
            MMI_content_y + ((MMI_content_height - MMI_multiline_inputbox.height) >> 1));

        show_multiline_inputbox();
#else
        if (mmi_fe_get_r2l_state())
        {            
            gui_print_truncated_text(MMI_content_x + MMI_content_width - 1, MMI_content_y, MMI_content_width, err_str_ptr);
        }
        else
        {            
            gui_print_truncated_text(MMI_content_x, MMI_content_y, MMI_content_width, err_str_ptr);
        }        
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__*/
    }

    gdi_layer_pop_text_clip();
    gdi_layer_pop_clip();

    gdi_lcd_repaint_all();
}

#ifdef __MMI_FILE_MANAGER__
static void Cat222GetErrStrAndShow(UI_string_type err_str_ptr, GDI_RESULT result)
{
    if (err_str_ptr == NULL)
    {
        if (result == GDI_JPEG_ERR_IMAGE_TOO_LARGE)
        {
            err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_FILE_LIMIT_IMAGE_TOO_LARGE);            
        }
        else if (result == GDI_JPEG_ERR_DECODE_TIME_OUT)
        {
            err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_SYSTEM_BUSY_TO_DECODE);            
        }
        else if (result == GDI_IMAGE_ERR_INVALID_IMG_TYPE)
        {
            err_str_ptr = (UI_string_type) GetString(STR_GLOBAL_UNSUPPORTED_FORMAT);            
        }
        else
        {
            err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);          
        }        
    }
    
    Cat222ShowErrMsg(err_str_ptr);
}
#endif


/*****************************************************************************
 * FUNCTION
 *  wgui_cat222_image_last_frame_callback
 * DESCRIPTION
 *  image last frame callback;
 * PARAMETERS
 *  result [IN] GDI result
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat222_image_last_frame_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    UI_string_type err_str_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_FILE_MANAGER__
    if (result < 0)
    {
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
    #endif
        Cat222GetErrStrAndShow(err_str_ptr, result);
    }
#endif

    /* call decode result callback */
    if (cat222_decode_result_callback != NULL)
    {
        cat222_decode_result_callback(result);
    }
}


#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
/*****************************************************************************
 * FUNCTION
 *  Cat222ImageDoneCallback
 * DESCRIPTION
 *  Display error message
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222ImageDoneCallback(GDI_RESULT result, GDI_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	wgui_cat222_image_last_frame_callback(result);
}
#endif /* #__MMI_CAT222_NON_BLOCKING_DECODER__ */

/*****************************************************************************
 * FUNCTION
 *  Cat222DecodeImage
 * DESCRIPTION
 *  Decode Image
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void Cat222DecodeImage(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width = 0;
    S32 image_height = 0;
    S32 display_wnd_width;
    S32 display_wnd_height;

    S32 rect_height = 0;
    S32 rect_width = 0;
    S32 rect_offset_x = 0;
    S32 rect_offset_y = 0;

    S32 offset_x = 0;
    S32 offset_y = 0;
    GDI_RESULT result = 0;
    U16 image_type = 0;
    UI_string_type err_str_ptr = NULL;

    S32 resized_offset_x;
    S32 resized_offset_y;
    S32 resized_width;
    S32 resized_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    gdi_layer_push_and_set_active(dm_get_layer_handle(0));
#endif


    gdi_layer_push_and_set_clip(
        MMI_content_x, MMI_content_y,
        MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1);

    /* check file limitation */
//#if !defined(__COSMOS_MMI_PACKAGE__)
    if (result >= 0)
    {
        if (cat222_src_type == GDI_IMAGE_SRC_FROM_FILE)
        {
        #ifdef __MMI_FILE_MANAGER__
            if (!mmi_fmgr_util_file_limit_check(FMGR_LIMIT_IMAGE_VIEWER, cat222_file_name_ptr, (PS8*)&err_str_ptr))
            {
                result = -1;
            }
            else
        #endif
            {
                err_str_ptr = NULL;
            }
        }
    }
//#endif

    /* get image info */
    if (result >= 0 && cat222_src_type == GDI_IMAGE_SRC_FROM_FILE)
    {
        image_type = gdi_image_get_type_from_file(cat222_file_name_ptr);
        result = gdi_image_get_dimension_file((PS8) cat222_file_name_ptr, &image_width, &image_height);
    }
    else if (cat222_src_type == GDI_IMAGE_SRC_FROM_MEMORY)
    {
        image_type = gdi_image_get_type_from_mem(cat222_file_name_ptr);
        result = gdi_image_get_dimension_mem((U8) image_type, (PU8) cat222_file_name_ptr, 0, &image_width, &image_height);
    }
    if (result < 0)
    {
        if (err_str_ptr == NULL)
        {
        #ifdef __MMI_FILE_MANAGER__
            err_str_ptr = (UI_string_type) GetString(STR_ID_FMGR_INVALID_IMAGE_FORMAT);
        #endif
        }
    }
    
    display_wnd_width = MMI_content_width - CAT222_IMAGE_SPACING * 2;
    display_wnd_height = MMI_content_height - CAT222_IMAGE_SPACING * 2;

    /* clear gdi working buffer */
    gdi_image_clear_work_buffer();

    if (result >= 0)
    {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
        /* set non-blocking parameters */
        gdi_nb_set_blt(TRUE, FALSE);                        /* let GDI to blt the LCD after decoding without progressive blt */
        gdi_nb_set_done_callback(Cat222ImageDoneCallback);  /* register callback after decoding */
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */

        if ((display_wnd_width >= image_width) && (display_wnd_height >= image_height))
        {
            /* align preview window at the center of screen */
            offset_x = ((display_wnd_width - image_width + 1) >> 1) + CAT222_IMAGE_SPACING;
            offset_y = ((display_wnd_height - image_height + 1) >> 1) + MMI_content_y + CAT222_IMAGE_SPACING;

            rect_width = resized_width = image_width;
            rect_height = resized_height = image_height;
        }
        else
        {
            gdi_image_util_fit_bbox(
                display_wnd_width,
                display_wnd_height,
                image_width,
                image_height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);

            offset_x = resized_offset_x + CAT222_IMAGE_SPACING;
            offset_y = resized_offset_y + (MMI_title_y + MMI_title_height) + CAT222_IMAGE_SPACING;

            rect_width = resized_width;
            rect_height = resized_height;
        }
        rect_offset_x = offset_x;
        rect_offset_y = offset_y;
        
#ifndef __MMI_CATEGORY_MULTIMEDIA_SLIM__        
        if (image_type == GDI_IMAGE_TYPE_AVATAR)
        {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_anim_nb_draw_resized_mem(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PU8) cat222_file_name_ptr, GDI_IMAGE_TYPE_AVATAR, 0);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_anim_draw_mem_resized(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr, GDI_IMAGE_TYPE_AVATAR, 0, // NO USE
                            &cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
        else 
#endif /*__MMI_CATEGORY_MULTIMEDIA_SLIM__ */
        if (image_type == GDI_IMAGE_TYPE_GIF_FILE || image_type == GDI_IMAGE_TYPE_M3D_FILE || image_type == GDI_IMAGE_TYPE_SVG_FILE)
        {
			gdi_anim_set_last_frame_callback(wgui_cat222_image_last_frame_callback);
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_anim_nb_draw_resized_file(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PS8) cat222_file_name_ptr);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_image_draw_animation_resized_file(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr, &cat222_anim_handle);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
        else
        {
#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
            result = 0;
            cat222_anim_handle = gdi_image_nb_draw_resized_file(
                                        offset_x, offset_y, resized_width, resized_height,
                                        (PS8) cat222_file_name_ptr);
#else /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
            result = gdi_image_draw_resized_file(
                            offset_x, offset_y, resized_width, resized_height,
                            (PS8) cat222_file_name_ptr);
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
        }
    }

    if (result >= 0)
    {
        /* if is fit content size mode, draw a rect to make the image like a photo */
        gdi_draw_rect(
            rect_offset_x - 1,
            rect_offset_y - 1,
            rect_offset_x + rect_width,
            rect_offset_y + rect_height,
            GDI_COLOR_WHITE);
        gdi_draw_rect(
            rect_offset_x - 2,
            rect_offset_y - 2,
            rect_offset_x + rect_width + 1,
            rect_offset_y + rect_height + 1,
            GDI_COLOR_BLACK);
        gdi_draw_rect(
            rect_offset_x - 3,
            rect_offset_y - 3,
            rect_offset_x + rect_width + 2,
            rect_offset_y + rect_height + 2,
            GDI_COLOR_WHITE);
    }
    else
    {
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
    #endif
    #ifdef __MMI_FILE_MANAGER__
        Cat222GetErrStrAndShow(err_str_ptr, result);
    #endif

#ifdef __MMI_CAT222_NON_BLOCKING_DECODER__
        if (cat222_decode_result_callback != NULL)
        {
            cat222_decode_result_callback(result);
        }
#endif /* __MMI_CAT222_NON_BLOCKING_DECODER__ */
    }

    gdi_layer_pop_clip();
    gdi_layer_unlock_frame_buffer();
    gdi_lcd_repaint_all();

#if MAIN_MEDIA_LAYER_BITS_PER_PIXEL == 24
    gdi_layer_pop_and_restore_active();
#endif

#ifndef __MMI_CAT222_NON_BLOCKING_DECODER__
    if (cat222_decode_result_callback != NULL)
    {
        cat222_decode_result_callback(result);
    }
#endif /* !__MMI_CAT222_NON_BLOCKING_DECODER__ */
}


/*****************************************************************************
* [Category223]
*
* This category is for playing audio.
*
*  **********************
*  *       Caption      *
*  **********************
*  *                    *
*  *      00:00:00      *
*  *                    *
*  *       (Icon)       *
*  *                    *
*  *********    *********
*  *  LSK  *    *  RSK  *
*  **********************
*
*****************************************************************************/
#ifdef __MMI_MAINLCD_96X64__
static U16 g_message_icon_233 = 0;
static gdi_handle g_cat223_anim_handle = NULL;
static BOOL g_is_fmradio_enter = MMI_FALSE;
#endif

#if defined(__MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__)
/*****************************************************************************
 * FUNCTION
 *  cat_single_player_volumn_up
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cat_single_player_volumn_up(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_single_player_audio_volumn < SRV_PROF_MEDIA_VOL_LEVEL_16)
    {
        cat_single_player_audio_volumn++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(cat_single_player_audio_volumn));
    }
}

/*****************************************************************************
 * FUNCTION
 *  cat_single_player_volumn_down
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void cat_single_player_volumn_down(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_single_player_audio_volumn > SRV_PROF_MEDIA_VOL_LEVEL_0)
    {
        cat_single_player_audio_volumn--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(cat_single_player_audio_volumn));
    }
}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 

/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory223Screen_ext(
        WCHAR *title,//U16 title,
        PU8 title_icon,//U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U16 flag,
        U32 duration,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 l = 0, h = 0;
    UI_time t;
    S32 flags;
#ifdef __MMI_MAINLCD_96X64__
    S32 image_width = 0, image_height = 0;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sound recoder will show category 223 twice without entry new screen
     * we have to reset draw manager by ourselves */
    dm_reset_context();

    /* did not use history buffer */
    UI_UNUSED_PARAMETER(history_buffer);

    gdi_layer_lock_frame_buffer();

    gui_setup_common_layout();
	
	dm_set_scr_bg_flag( DM_SCR_BG_FORCE_SHOW | DM_BACK_FILL);

    /* add title, softkey, image */
    //dm_add_title_id(title, title_icon);
    dm_add_title((UI_string_type)title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);
	
#ifndef __MMI_MAINLCD_96X64__
    dm_add_image(get_image(message_icon), NULL, NULL);
#else
	//__MMI_MAINLCD_96X64__ draw image by wgui_cat223_draw_ctrl_area1
	g_message_icon_233 = message_icon;
#endif

    /* set a fake time display to set the time object attributes for getting time string size */
    set_time_display(0, 0, 0, 0, 0);
    main_LCD_measure_time_duration_string(&l, &h);

    /* set time display for control area display */
    wgui_cat223_init_duration(&t, (U32)(duration * 0.004615 + 0.5)); 
    set_main_LCD_time_duration_hide_function(wgui_cat223_hide_duration);
    set_time_duration(&t, duration);
#if defined(__MMI_MAINLCD_320X480__)
    set_time_display(flag,
        MMI_POP_UP_DIALOG_X + MMI_POP_UP_CONTENT_MARGIN_X + ((MMI_POP_UP_DIALOG_WIDTH - MMI_POP_UP_CONTENT_MARGIN_X*2 - l) >> 1),
        WGUI_CAT223_POPUP_Y + MMI_POP_UP_DIALOG_HEIGHT - MMI_POP_UP_CONTENT_MARGIN_Y - WGUI_CAT223_TIME_H + ((WGUI_CAT223_TIME_H - h) >> 1),
        l, h);
#elif defined(__MMI_MAINLCD_320X240__)
	set_time_display(flag, MMI_content_x + ((MMI_content_width - l) >> 1), MMI_content_y + (((MMI_MENUITEM_HEIGHT) - h) >> 1), l, h);
#elif defined(__MMI_MAINLCD_96X64__)    
    gdi_image_get_dimension_id(g_message_icon_233, &image_width, &image_height);
    set_time_display(flag, MMI_content_x + ((MMI_content_width - l) >> 1), MMI_content_y + ((MMI_content_height - h - image_height) >> 1), l, h);    
#else /* defined(__MMI_MAINLCD_320X480__) */
    set_time_display(flag, MMI_content_x + ((MMI_content_width - l) >> 1), MMI_content_y + (((MMI_MENUITEM_HEIGHT << 1) - h) >> 1), l, h);
#endif /* defined(__MMI_MAINLCD_320X480__) */

    gdi_layer_unlock_frame_buffer();
#ifdef __MMI_BTD_BOX_MULTIMEDIA_CAT_STYLE__

    /* first time enter, set audio volumn */
    srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void*)&cat_single_player_audio_volumn);    
    cat_single_player_audio_volumn = MDI_AUD_VOL_GET_EX_LEVEL(cat_single_player_audio_volumn);
    if(cat_single_player_audio_volumn == 0)
    {
        cat_single_player_audio_volumn = 4;
    }

    /* init audio volumn */
    mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_EX_MUTE(cat_single_player_audio_volumn));

    SetKeyHandler(cat_single_player_volumn_up, KEY_UP_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(cat_single_player_volumn_up, KEY_UP_ARROW, KEY_REPEAT);

    SetKeyHandler(cat_single_player_volumn_down, KEY_DOWN_ARROW, KEY_EVENT_DOWN);
    SetKeyHandler(cat_single_player_volumn_down, KEY_DOWN_ARROW, KEY_REPEAT);
#endif

    dm_register_category_controlled_callback(wgui_cat223_draw_ctrl_area1);

#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_176X220__)
    flags = DM_CLEAR_SCREEN_BACKGROUND;
#else /* defined(__MMI_MAINLCD_320X480__) */
    flags = DM_CLEAR_SCREEN_BACKGROUND_COLOR;
#endif /* defined(__MMI_MAINLCD_320X480__) */
    wgui_cat_setup_category(MMI_CATEGORY223_ID, flags, wgui_cat223_exit, dummy_get_history, dummy_get_history_size);
    dm_redraw_category_screen();
}

void ShowCategory223Screen_int(
         U16 title,
         U16 title_icon,
         U16 left_softkey,
         U16 right_softkey,
         U16 message_icon,
         U16 flag,
         U32 duration,
         U8 *history_buffer)
{
    ShowCategory223Screen_ext(
                    (WCHAR*)get_string(title),
                    (PU8)get_image(title_icon),
                    left_softkey,
                    right_softkey,
                    message_icon,
                    flag,
                    duration,
                    history_buffer);
}



/*****************************************************************************
 * FUNCTION
 *  wgui_cat223_exit
 * DESCRIPTION
 *  Exit category 223
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat223_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#ifdef __MMI_MAINLCD_96X64__
	if (g_cat223_anim_handle)
	{
		gdi_anim_stop(g_cat223_anim_handle);
	}
	
#if defined(__MMI_FM_RADIO__)
	/*FMRadio no need to draw duration, so return*/
	if(g_is_fmradio_enter)
	{
		g_is_fmradio_enter = MMI_FALSE;
		MMI_message_string = NULL;
		return;
	}
#endif
#endif/*__MMI_MAINLCD_96X64__*/

    close_main_LCD_time_display();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat223_draw_ctrl_area1
 * DESCRIPTION
 *  This function is used to draw the category controlled area of category223 screen.
 *  It contains the time display.
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat223_draw_ctrl_area1(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_MAINLCD_96X64__
	S32 image_width = 0, image_height = 0;
	S32 w = 0, h = 0;
	S32 x = 0, y = 0;
	S32 interval = 0;
	U16 img_type;  
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__) 
    gui_one_layer_draw_filled_bg_area(
        MMI_content_x,
        MMI_content_y, 
        MMI_content_x + MMI_content_width - 1,
        MMI_content_y + MMI_content_height - 1);
#endif

#ifdef __MMI_MAINLCD_96X64__
	//draw image
	if(g_message_icon_233)
	{
	#if defined(__MMI_FM_RADIO__)
		if(g_is_fmradio_enter)
		{
			gui_measure_string(MMI_message_string, &w, &h);		
		}
		else
	#endif
		{
			main_LCD_measure_time_duration_string(&w, &h);
		}


		gdi_image_get_dimension_id(g_message_icon_233, &image_width, &image_height);
		image_width = (image_width > MMI_content_width)? MMI_content_width : image_width;
        image_height = (image_height > (MMI_content_height - h))? (MMI_content_height - h) : image_height;
        interval = (MMI_content_height - h - image_height) >> 1;
		if (g_cat223_anim_handle)
		{
			gdi_anim_stop(g_cat223_anim_handle);
		}

		img_type = gdi_image_get_type_from_id(g_message_icon_233);
		if(GDI_IMAGE_TYPE_BMP_SEQUENCE == img_type) 
		{
			gdi_anim_draw_id(
				(LCD_WIDTH - image_width) >> 1, 
				MMI_content_y + interval + h + interval,
				g_message_icon_233, &g_cat223_anim_handle);
		}
		else
		{	
			gdi_image_draw_id(
				(LCD_WIDTH - image_width) >> 1, 
				MMI_content_y + interval + h + interval,
				g_message_icon_233);
		}	
	}
	
#if defined(__MMI_FM_RADIO__)
	/*FMRadio no need to draw duration, so return*/
	if(g_is_fmradio_enter)
	{		
		gui_measure_string(MMI_message_string, &w, &h);
        w = (w > MMI_content_width) ? MMI_content_width : w;
		x = MMI_content_x + ((MMI_content_width - w) >> 1);
		y = MMI_content_y + interval;

		gdi_layer_push_and_set_clip(x, y, x + w, y + h);

		gui_set_font(&MMI_default_font);
		gui_set_text_color(UI_COLOR_WHITE);
		//gui_set_text_border_color(UI_COLOR_RED);
		if (mmi_fe_get_r2l_state())
		{
			gui_move_text_cursor(x + w, y);
		}
		else
		{
			gui_move_text_cursor(x, y);
		}
		gui_print_truncated_text(x, y, w, MMI_message_string);

		gdi_layer_pop_clip();
	
		return;
	}
#endif /*__MMI_FM_RADIO__*/	
#endif /*__MMI_MAINLCD_96X64__*/
    time_display_duration();
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat223_init_duration
 * DESCRIPTION
 *  Init duration parameters
 * PARAMETERS
 *  t               [IN]        time
 *  duration        [IN]        duration
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat223_init_duration(UI_time *t, U32 duration)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 buf1, buf2;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    t->DayIndex = 0;
    buf1 = duration / 60;
    t->nSec = duration - buf1 * 60;
    buf2 = buf1 / 60;
    t->nMin = buf1 - buf2 * 60;
    t->nHour = (U8) buf2;
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat223_hide_duration
 * DESCRIPTION
 *  Hide duration display
 * PARAMETERS
 *  x1      [IN]        start x
 *  y1      [IN]        start y
 *  x2      [IN]        end x
 *  y2      [IN]        end y
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat223_hide_duration(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__) && defined(DM_NEW_POPUPBG_METHOD)
    dm_coordinates popup_clip = {0};

#elif !defined(__MMI_MAINLCD_176X220__)
    color c = *current_MMI_theme->datetime_bar_duration_background_color;
#endif /* defined(__MMI_MAINLCD_320X480__) && defined(DM_NEW_POPUPBG_METHOD) */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_MAINLCD_320X480__) && defined(DM_NEW_POPUPBG_METHOD)
    popup_clip.s16X = (S16)x1;
    popup_clip.s16Y = (S16)y1;
    popup_clip.s16Width = (S16)(x2 - x1 + 1);
    popup_clip.s16Height = (S16)(y2 - y1 + 1);
    dm_popupbg_set_clip((dm_coordinates*)&popup_clip);
    dm_redraw_popup_background();
#else /* defined(__MMI_MAINLCD_320X480__) && defined(DM_NEW_POPUPBG_METHOD) */
    gui_push_and_set_clip(x1, y1, x2, y2);

#if defined(__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__) 
     gui_one_layer_draw_filled_bg_area(x1, y1, x2, y2);
#else /*__MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__ */
    #if defined(__MMI_MAINLCD_176X220__) /*need to draw background image for sound recorder on __MMI_MAINLCD_176X220__*/
    	gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT); 
    #else
        gui_fill_rectangle(x1, y1, x2, y2, c);
    #endif
#endif /* __MMI_IMAGE_CACHE_FOR_ONE_GDI_LAYER__ */
    gui_pop_clip();
#endif /* defined(__MMI_MAINLCD_320X480__) && defined(DM_NEW_POPUPBG_METHOD) */
}

#ifdef __MMI_MAINLCD_96X64__
/*****************************************************************************
 * FUNCTION
 *  wgui_cat223_update_duration
 * DESCRIPTION
 *  update duration display
 * PARAMETERS
 *  duration      [IN]        display time, unit is mili seconds.
 * RETURNS
 *  void
 *****************************************************************************/
void wgui_cat223_update_duration(U32 duration)
{
	UI_time t;

    wgui_cat223_init_duration(&t,(U32)(duration * 0.004615 + 0.5));
	set_main_LCD_time_duration_hide_function(wgui_cat223_hide_duration);
	set_time_duration(&t, duration);
	time_display_duration();
}
#endif /*__MMI_MAINLCD_96X64__*/

#if defined(__MMI_FM_RADIO__) && defined(__MMI_MAINLCD_96X64__)

/*For FM radio player, show FM channel not show duration */
void ShowCategory223FMRadioScreen_ext(
        WCHAR *title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        WCHAR *str_fmradio,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	/*for distingush ShowCategory223FMRadioScreen_ext with ShowCategory223Screen_ext, because these use the same wgui_cat223_draw_ctrl_area1*/
	g_is_fmradio_enter = MMI_TRUE;
	MMI_message_string = str_fmradio;
	
    dm_reset_context();

    /* did not use history buffer */
    UI_UNUSED_PARAMETER(history_buffer);

    gdi_layer_lock_frame_buffer();

    gui_setup_common_layout();

    /* add title, softkey, image */
    dm_add_title((UI_string_type)title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);

	g_message_icon_233 = message_icon;

    gdi_layer_unlock_frame_buffer();

    dm_register_category_controlled_callback(wgui_cat223_draw_ctrl_area1);

    wgui_cat_setup_category(MMI_CATEGORY223_ID, DM_CLEAR_SCREEN_BACKGROUND_COLOR, wgui_cat223_exit, dummy_get_history, dummy_get_history_size);
    dm_redraw_category_screen();
}
#endif /*defined(__MMI_FM_RADIO__) && defined(__MMI_MAINLCD_96X64__)*/

/*****************************************************************************
* [Category224]
*
* This category is for play a video clip. Can be full screen or standard MMI style.
*
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  * (Fullscreen Video) *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  *                    *
*  **********************
*
*****************************************************************************/

#ifdef __MMI_VIDEO_PLAY_SUPPORT__

static U8 *wgui_catvdo_top_buf = NULL;
static GDI_HANDLE wgui_catvdo_top_layer = GDI_ERROR_HANDLE;

static U8 *wgui_catvdo_bottom_buffer = NULL;
static GDI_HANDLE wgui_catvdo_bottom_layer = GDI_ERROR_HANDLE;

static MMI_BOOL  g_cat225_is_vlw_scenario = MMI_FALSE;

/* For detail description, please refer to wgui_categories_multimedia.h */
void wgui_catvdo_refine_video_coordinate(S32 *x, S32 *y, S32 *w, S32 *h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((*x) % 2 != 0)
    {
        (*x) ++;
        if ((*w) > 1)   (*w) --;
    }

    if (((*w) &= ~1) < 2)
    {
        (*w) = 2;
    }

    if((*w)%2 > 0)
	{
		(*w)++;
	}
    if (((*h) &= ~1) < 2)
    {
        (*h) = 2;
    }
	if((*h)%2 > 0)
	{
		(*h)++;
	}
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory224Screen(
        U16 video_id,
        PS8 video_filename,
        U16 repeat_count,
        BOOL is_visual_update,
        BOOL is_play_audio,
        BOOL is_lcd_no_sleep,
        GDI_COLOR bg_color,
        void (*play_finish_callback) (MDI_RESULT),
        void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    ShowCategoryVdoplyScreen(
        TRUE,                   /* is_fullscreen *//* cat224 is fullscreen display */
        0,                      /* title_str */
        0,                      /* title_icon */
        0,                      /* lsk_str */
        0,                      /* rsk_str */
        video_id,               /* video_id */
        video_filename,         /* video_filename */
        repeat_count,           /* repeat_count */
        is_visual_update,       /* is_visual_update */
        is_play_audio,          /* is_play_audio */
        is_lcd_no_sleep,        /* is_lcd_no_sleep */
        bg_color,               /* bg_color */
        play_finish_callback,   /* play_finish_callback */
        gui_buffer);            /* gui_buffer */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void StopCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    StopCategoryVdoplyVideo();
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void PauseCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    PauseCategoryVdoplyVideo();
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void ResumeCategory224Video(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ResumeCategoryVdoplyVideo();
}

/*****************************************************************************
* [ShowCategory225Screen]
*
* Play video screen with title and softkey
*
*  **********************
*  *        Title       *
*  **********************
*  *                    *
*  *                    *
*  *                    *
*  *       (Video)      *
*  *                    *
*  *                    *
*  *                    *
*  ********      ********
*  * LSK  *      *  RSK *
*  **********************
*
*****************************************************************************/


/* For detail description, please refer to wgui_categories_multimedia.h */
extern void ShowCategory225Screen_int(
                U16 title_str,
                U16 title_icon,
                U16 lsk_str,
                U16 rsk_str,
                U16 video_id,
                PS8 video_filename,
                U16 repeat_count,
                BOOL is_visual_update,
                BOOL is_play_audio,
                BOOL is_lcd_no_sleep,
                GDI_COLOR bg_color,
                void (*play_finish_callback) (MDI_RESULT),
                void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_VIDEO_PLAY_SUPPORT__
    ShowCategoryVdoplyScreen(
        FALSE,                  /* is_fullscreen */
        title_str,              /* title_str */
        title_icon,             /* title_icon */
        lsk_str,                /* lsk_str */
        rsk_str,                /* rsk_str */
        video_id,               /* video_id */
        video_filename,         /* video_filename */
        repeat_count,           /* repeat_count */
        is_visual_update,       /* is_visual_update */
        is_play_audio,          /* is_play_audio */
        is_lcd_no_sleep,        /* is_lcd_no_sleep */
        bg_color,               /* bg_color */
        play_finish_callback,   /* play_finish_callback */
        gui_buffer);            /* gui_buffer */
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 
}

static void VdoCategoryControlArea_InitLayer(gdi_handle handle)
{
    /* init layer */
    gdi_layer_push_and_set_active(handle);
    gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
    gdi_layer_clear(GDI_COLOR_TRANSPARENT);
    gdi_layer_toggle_double();
    gdi_layer_copy_double();
    gdi_layer_pop_and_restore_active();
}

/*****************************************************************************
 * FUNCTION
 *  DrawCateVdoCategoryControlArea
 * DESCRIPTION
 *  draw vdo contro area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coord
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCateVdoCategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 resized_width, resized_height;
    S32 resized_offset_x, resized_offset_y;
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_is_full_screen)
    {
        content_width = UI_device_width;
        content_offset_x = 0;
#if defined(GUI_COMMON_SHOW_STATUS_ICON)    /* modify for png status icon bar */
        if (wgui_is_touch_title_bar_buttons())
        {
            content_height = UI_device_height - MMI_title_y - MMI_button_bar_height;
            content_offset_y = MMI_title_y;
        }
        else
#endif
        {
            content_height = UI_device_height;
            content_offset_y = 0;
        }
    }
    else
    {
        content_width = MMI_content_width;
        content_height = MMI_content_height;
        content_offset_x = MMI_content_x;
        content_offset_y = MMI_content_y;
    }

    /* create video layer */
    if (cat_vdoply_is_video_open)
    {
#ifdef __MDI_DISPLAY_FIT_INSIDE_SUPPORT__
        resized_offset_x = 0;
        resized_offset_y = 0;
        resized_width = content_width;
        resized_height = content_height;
#else
        /* resize */
		if(wgui_video_info.width == 0 || wgui_video_info.height == 0)
		{
			resized_offset_x = 0;
			resized_offset_y = 0;
			resized_width = content_width;
			resized_height = content_height;
		}
        else if (cat_vdoply_is_full_screen || (wgui_video_info.width > content_width) || (wgui_video_info.height > content_height))
        {
            /* full screen or large video */
            gdi_util_fit_box(
                GDI_UTIL_MODE_LONG_SIDE_FIT,
                content_width,
                content_height,
                wgui_video_info.width,
                wgui_video_info.height,
                &resized_offset_x,
                &resized_offset_y,
                &resized_width,
                &resized_height);
        }
        else
        {
            /* small video */
            resized_offset_x = (content_width - wgui_video_info.width) >> 1;
            resized_offset_y = (content_height - wgui_video_info.height) >> 1;
            resized_width = wgui_video_info.width;
            resized_height = wgui_video_info.height;
        }
#endif /* __MDI_DISPLAY_FIT_INSIDE_SUPPORT__ */
        /* shift to content position */
        resized_offset_x += content_offset_x;
        resized_offset_y += content_offset_y;

        wgui_catvdo_refine_video_coordinate(&resized_offset_x, &resized_offset_y, &resized_width, &resized_height);

        /* create layer */
        dm_create_layer(resized_offset_x, resized_offset_y, resized_width, resized_height, &cat_vdoply_video_layer, DM_LAYER_TOP);
        MMI_ASSERT(cat_vdoply_video_layer);

        /* init layer */
        gdi_layer_push_and_set_active(cat_vdoply_video_layer);
    #ifdef __MDI_DISPLAY_YUYV422_SUPPORT__
        gdi_layer_set_color_format(GDI_COLOR_FORMAT_UYVY422);
    #endif
        gdi_layer_clear(GDI_COLOR_BLACK);
        gdi_layer_pop_and_restore_active();
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
        if(g_cat_vdoply_is_3d_type)
		{
			if(g_cat225_is_vlw_scenario && g_cat_vdoply_is_2d_type)
			{
				/* sync with home screen video live wallpaper*/
				mdi_video_ply_set_track_index(g_cat_vdoply_2d_track_index);
			}
			else
			{
                mdi_video_ply_set_track_index(g_cat_vdoply_3d_track_index);
			}
		}
#endif

#ifdef __MDI_DISPLAY_FIT_OUTSIDE_SUPPORT__
         if(g_cat225_is_vlw_scenario)
         {
            mdi_video_ply_set_frame_mode(MDI_VIDEO_FRAME_MODE_FIT_OUTSIDE);
         }
#endif

        /* get first frame */
        video_ret = mdi_video_ply_seek_and_get_frame(cat_vdoply_video_start_time, cat_vdoply_video_layer);
        cat_vdoply_is_video_play = (video_ret >= 0) ? (TRUE) : (FALSE);
        if(video_ret == MDI_RES_VDOPLY_ERR_GET_FRAME_FAILED)
        {
            cat_vdoply_is_video_play = TRUE; /* Special handle , requiered by MDI */
        }
        cat_vdoply_is_video_play_result = video_ret;
    }

    if (wgui_is_touch_title_bar_buttons())
    {
        /* clear base layer black */
        gdi_layer_clear(GDI_COLOR_BLACK);

        /* create top double buffer : status icon + title */
        wgui_catvdo_top_buf = mmi_frm_scrmem_alloc_framebuffer(WGUI_CATVDO_TOP_DOUBLE_BUFFER_SIZE);
        MMI_ASSERT(wgui_catvdo_top_buf);
    //    gdi_layer_create_double_using_outside_memory(0, 0, UI_device_width, MMI_content_y, &wgui_catvdo_top_layer, wgui_catvdo_top_buf, WGUI_CATVDO_TOP_DOUBLE_BUFFER_SIZE);
		gdi_layer_create_cf_double_using_outside_memory(GDI_COLOR_FORMAT_32, 0, 0, UI_device_width, MMI_content_y, &wgui_catvdo_top_layer,
			wgui_catvdo_top_buf, WGUI_CATVDO_TOP_DOUBLE_BUFFER_SIZE/2, (wgui_catvdo_top_buf + WGUI_CATVDO_TOP_DOUBLE_BUFFER_SIZE/2), WGUI_CATVDO_TOP_DOUBLE_BUFFER_SIZE/2);

        MMI_ASSERT(wgui_catvdo_top_layer);
		gdi_set_alpha_blending_source_layer(wgui_catvdo_top_layer);///////////
        dm_add_blt_layer(wgui_catvdo_top_layer, DM_LAYER_TOP);
		

        /* init layer */
        //gdi_layer_push_and_set_active(wgui_catvdo_top_layer);
        //gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        //gdi_layer_toggle_double();  /* toggle doulbe buffer, video hw can record the blt buffer after blt*/
        //gdi_layer_copy_double();
        //gdi_layer_pop_and_restore_active();
        VdoCategoryControlArea_InitLayer(wgui_catvdo_top_layer);

        /* set active for title */
        gdi_layer_set_active(wgui_catvdo_top_layer);

#if defined(GUI_COMMON_SHOW_STATUS_ICON)
        /* set status icon with double bufer */
        {
            wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, wgui_catvdo_top_layer);
            wgui_status_icon_bar_set_double_buffer(WGUI_STATUS_ICON_BAR_H_BAR);
            gdi_layer_get_base_handle(&wgui_base_layer);
            wgui_status_icon_bar_set_alpha_blend_layer(
                WGUI_STATUS_ICON_BAR_H_BAR,
                wgui_base_layer);
        }
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */

        /* create bottom buffer : softkey */
        wgui_catvdo_bottom_buffer = mmi_frm_scrmem_alloc_framebuffer(WGUI_CATVDO_BOTTOM_DOUBLE_BUFFER_SIZE);
        MMI_ASSERT(wgui_catvdo_bottom_buffer);
        gdi_layer_create_double_using_outside_memory(0, (UI_device_height - MMI_softkey_height), UI_device_width, MMI_softkey_height, &wgui_catvdo_bottom_layer, wgui_catvdo_bottom_buffer, WGUI_CATVDO_BOTTOM_DOUBLE_BUFFER_SIZE);
        MMI_ASSERT(wgui_catvdo_bottom_layer);
        dm_add_blt_layer(wgui_catvdo_bottom_layer, DM_LAYER_TOP);

        /* init layer */
        //gdi_layer_push_and_set_active(wgui_catvdo_bottom_layer);
        //gdi_layer_set_source_key(TRUE, GDI_COLOR_TRANSPARENT);
        //gdi_layer_clear(GDI_COLOR_TRANSPARENT);
        //gdi_layer_toggle_double();
        //gdi_layer_copy_double();
        //gdi_layer_pop_and_restore_active();
        VdoCategoryControlArea_InitLayer(wgui_catvdo_bottom_layer);

        /* set softkey with double buffer */
        wgui_softkey_set_target_layer(wgui_catvdo_bottom_layer);
        wgui_softkey_set_double_buffer_enable(MMI_TRUE);
    }
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catvdoply_get_history_size
 * DESCRIPTION
 *  Gets the size of history data for video category
 * PARAMETERS
 *  void
 * RETURNS
 *  history size
 *****************************************************************************/
static S32 wgui_catvdoply_get_history_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return sizeof(wgui_catvdoply_history_struct);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_catvdoply_get_history
 * DESCRIPTION
 *  Gets the history data for video category into the given history buffer
 * PARAMETERS
 *  buffer      [OUT]   Buffer of history data.
 * RETURNS
 *  history
 *****************************************************************************/
static U8* wgui_catvdoply_get_history(U8* buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer != NULL)
    {
        wgui_catvdoply_history_struct *h = (wgui_catvdoply_history_struct*)buffer;
        U64 ply_time = 0;

        h->history_id = (U16)(g_dm_data.s32CatId | 0x8000);
        if (cat_vdoply_is_video_play == TRUE)
        {
			if(!wgui_video_info.is_seekable)
            {
				 ply_time = 0;
            }
            else if(cat_vdoply_is_video_finished == TRUE)
            {
                /* seek to end */
                ply_time = cat_vdoply_video_total_time;
            }
            else
            {
                mdi_video_ply_get_cur_play_time(&ply_time);
            }
        }
        h->playing_time = ply_time;
    }

    return buffer;
}

void wgui_cat225_set_preview_vlw_scenario(void)
{
	g_cat225_is_vlw_scenario = MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  ShowCategoryVdoplyScreen
 * DESCRIPTION
 *  Show Generic Play Video Category.
 * PARAMETERS
 *  is_fullscreen               [IN]        Is full screen display, if false, will draw title and softkeys
 *  title_str                   [IN]        Title string id
 *  title_icon                  [IN]        Title icon id
 *  lsk_str                     [IN]        Lsk str id
 *  lsk_icon                    [IN]        Lsk icon id
 *  rsk_str                     [IN]        Lsk str id
 *  rsk_icon                    [IN]        Lsk icon id
 *  video_id                    [IN]        Video ID
 *  video_filename              [IN]        Video filename
 *  repeat_count                [IN]        Repeat count, 0 means infinite
 *  is_visual_update            [IN]        Update visual to LCM or not
 *  is_play_audio               [IN]        Play audio or not
 *  is_lcd_no_sleep             [IN]        Will let lcd no sleep. This shall always TRUE unless u will handle lcd sleeping event
 *  bg_color                    [IN]        Backgroud color
 *  play_finish_callback        [IN]        Play finish call back hdlr
 *  gui_buffer                  [IN]        Gui_buffer, use to detemin if it is newly enter
 * RETURNS
 *  void
 *****************************************************************************/
static void ShowCategoryVdoplyScreen(
                BOOL is_fullscreen,
                U16 title_str,
                U16 title_icon,
                U16 lsk_str,
                U16 rsk_str,
                U16 video_id,
                PS8 video_filename,
                U16 repeat_count,
                BOOL is_visual_update,
                BOOL is_play_audio,
                BOOL is_lcd_no_sleep,
                GDI_COLOR bg_color,
                void (*play_finish_callback) (MDI_RESULT),
                void *gui_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
    U16 btn_prev_item_id, btn_next_item_id;
    MDI_RESULT video_ret = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* enter a sublcd screen with static image */
    /* 
     * this is very important since we cant draw anything on sublcd while video is playing,
     * which will casue driver assert.
     * 
     * caller of this category may ignore sublcd handling, it will be handled in this category 
     */
#ifdef __MMI_SUBLCD__
    if (!cat_vdoply_is_sublcd_display)
    {
        ForceSubLCDScreen(EnterCategoryVdoplySubScreen);
    }
#endif /* __MMI_SUBLCD__ */ 
    mmi_frm_set_curr_scr_blt_mode(MMI_FRM_SCR_BLT_IMMEDIATE);
    /* arg check */
    MMI_ASSERT((video_id == 0 && video_filename != NULL) || (video_id != 0 && video_filename == NULL));

    {   /* tricky: force to free scr_bg layer, otherwise it will occupy one layer */
        GDI_HANDLE dummy_layer;
        if (gdi_layer_create(0, 0, UI_device_width, UI_device_height, &dummy_layer) >= 0)
        {
            gdi_layer_free(dummy_layer);
        }
    }

    gui_setup_common_layout();
    wgui_softkey_set_filler_disabled(MMI_TRUE);
    
    /* clear keys */
    clear_key_handlers();

    /* init var */
    cat_vdoply_is_video_from_id = (video_id != 0) ? TRUE : FALSE;
    cat_vdoply_video_is_visual_update = is_visual_update;
    cat_vdoply_video_is_play_audio = is_play_audio;
    cat_vdoply_video_is_lcd_no_sleep = is_lcd_no_sleep;
    cat_vdoply_play_finish_callback = play_finish_callback;
    cat_vdoply_video_start_time = 0;
    cat_vdoply_video_total_time = 0;
    cat_vdoply_is_video_finished = FALSE;
    cat_vdoply_is_full_screen = TRUE;

    /* stop MMI sleep */
    if (cat_vdoply_video_is_lcd_no_sleep)
    {
        srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
    }

    /* set audio volumn */
    if (gui_buffer == NULL)
    {
        /* first time enter */
        srv_prof_get_current_profile_value(SRV_PROF_SETTINGS_RING_VOL_LEVEL, (void*)&cat_vdoply_audio_volumn);
        
        cat_vdoply_audio_volumn = MDI_AUD_VOL_GET_EX_LEVEL(cat_vdoply_audio_volumn);
    }

#if !defined(__MDI_VIDEO_DISABLE_AUDIO_BACKGROUND_PLAY__)
    if (cat_vdoply_video_is_play_audio)
#endif /* !defined(__MDI_VIDEO_DISABLE_AUDIO_BACKGROUND_PLAY__) */
    {
        /* suspend background audio */
        mdi_audio_suspend_background_play();
    }

    if (cat_vdoply_video_is_play_audio)
    {
        /* full screen play do not allows vol adjustment */
        if (!is_fullscreen)
        {
            //SetKeyHandler(CatVdoplyVolUp, KEY_VOL_UP, KEY_EVENT_DOWN);
            //SetKeyHandler(CatVdoplyVolDown, KEY_VOL_DOWN, KEY_EVENT_DOWN);
            SetKeyDownHandler(CatVdoplyVolUp, KEY_VOL_UP);
            SetKeyDownHandler(CatVdoplyVolDown, KEY_VOL_DOWN);
        }

        /* init audio volumn */
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(cat_vdoply_audio_volumn));
    }

    /*
     * user may request to repeat play many times, and wants a callback bewteen each play,
     * so we have to handle repeat play within this category by seeking to first frame 
     * after play finished each time, instead of using driver's repeat play.
     */

    cat_vdoply_video_repeat_count = (repeat_count == 0) ? 0xffff : repeat_count;        /* 0xff means infinte play */

    if (repeat_count != 0)
    {
        cat_vdoply_video_repeat_count--;
    }

   /********************************************************************************
   *  Draw non-full screen UI
   ********************************************************************************/
    if (!is_fullscreen)
    {
        /* not fullscreen, draw title and softkey */

        /* init softkey */
        dm_add_softkey_id(lsk_str,rsk_str);

        /* init title */
        dm_add_title_id(title_str, title_icon);
        wgui_title_set_menu_shortcut_number(-1);

        /* set content size */
        if (wgui_is_touch_title_bar_buttons())
        {            
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__)
//		    title_bg_id = 0;
			wgui_title_register_hide_callback(wgui_cat129_hide_title_callback);
#else
//			title_bg_id = IMAGE_VIEW_TITLEBAR_BG;
#endif
            wgui_set_wallpaper_on_bottom(MMI_TRUE);
#ifdef __MMI_FTE_SUPPORT__
		    set_softkey_flags_on(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_LEFT_SOFTKEY);
		    set_softkey_flags_on(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_RIGHT_SOFTKEY);
#endif
        }
        else
        {
            cat_vdoply_is_full_screen = FALSE;
        }
    }
    else
    {
        /* entry full screen */
        entry_full_screen();

        /* clear full screen */
        gdi_layer_clear(bg_color);
    }
	if(g_cat225_is_vlw_scenario)
	{
		mdi_video_ply_set_scenario_type(MDI_VIDEO_SCENARIO_MPEG4);
	}
   /********************************************************************************
   *  Open Video
   ********************************************************************************/
    if (video_id != 0)
    {
        /* source from id */
        /* always open with audio, if do not want audio, mute it by calling mdi function */
        video_ret = mdi_video_ply_open_clip_id(0, video_id, &wgui_video_info);
    }
    else if (video_filename != NULL)
    {
        /* source from file */
        /* always open with audio, if do not want audio, dsiable it in play function */
        video_ret = mdi_video_ply_open_clip_file(0, video_filename, &wgui_video_info);
    }
    else
    {
        /* no proper source */
        MMI_ASSERT(0);
    }
#ifdef __MMI_VIDEO_3D_ANAGLYPH__
    {
        S32 index;
        g_cat_vdoply_is_3d_type = MMI_FALSE;
		g_cat_vdoply_is_2d_type = MMI_FALSE;
        for(index = 0; index < wgui_video_info.track_num; index++)
        {
            if(wgui_video_info.track_info[index].track_type == MDI_VIDEO_TRACK_3D)
            {
                g_cat_vdoply_3d_track_index = wgui_video_info.track_info[index].track_index;
                g_cat_vdoply_is_3d_type = MMI_TRUE;
                break;
            }
        }
		/* just for video live wallpaper */
		/* video live wallpaper will show 2D video in home screen if the video have both track*/
		if(g_cat225_is_vlw_scenario)
		{
			for(index = 0; index < wgui_video_info.track_num; index++)
			{
				if(wgui_video_info.track_info[index].track_type == MDI_VIDEO_TRACK_2D_NORMAL)
				{
					g_cat_vdoply_2d_track_index = wgui_video_info.track_info[index].track_index;
					g_cat_vdoply_is_2d_type = MMI_TRUE;
					break;
				}
			}
		}
    }
#endif
    if (video_ret >= 0)
    {
        cat_vdoply_video_total_time = wgui_video_info.total_time_duration;
    }

    cat_vdoply_is_video_open = (video_ret >= 0) ? TRUE : FALSE;
    cat_vdoply_is_video_play_result = video_ret;

    /* check if the title bar buttons are enabled for the particular screen. */
    if (wgui_is_touch_title_bar_buttons())
    {
        U16 btn_left_down, btn_left_up;
        U16 btn_right_down, btn_right_up;

#if !defined(__MMI_SLIM_IMG_RES__)
        btn_left_down = LEFT_ARROW_DOWN;
        btn_left_up = LEFT_ARROW_UP;

        btn_right_down = RIGHT_ARROW_DOWN;
        btn_right_up = RIGHT_ARROW_UP;
	    mmi_frm_cb_reg_event(EVT_ID_PRE_KEY_EVT_ROUTING, wgui_cat129_key_proc, 0);
#else
        btn_left_down = btn_left_up = LEFT_RED_ARROW;
        btn_right_down = btn_right_up = RIGHT_RED_ARROW;
#endif

        btn_prev_item_id = dm_add_button(
                            NULL,
                            get_image(btn_left_up),
                            get_image(btn_left_down),
                            wgui_cat_hide_title_button);
        btn_next_item_id = dm_add_button(
                            NULL,
                            get_image(btn_right_up),
                            get_image(btn_right_down),
                            wgui_cat_hide_title_button);
#if !defined(__MMI_SLIM_IMG_RES__)
        (dm_get_button(0))->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        (dm_get_button(1))->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
#endif

#if defined(__MMI_TOUCH_SCREEN__)
        /* register the handler for pen event down istead of pen event up. */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    }

    dm_setup_category_functions(dm_redraw_category_screen, wgui_catvdoply_get_history, wgui_catvdoply_get_history_size);
    ExitCategoryFunction = ExitCategoryVdoplyScreen;

    dm_data.s32CatId = (wgui_is_touch_title_bar_buttons()) ? (MMI_CATEGORY_VDOPLY_BUTTON) : (MMI_CATEGORY_VDOPLY);
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if (is_fullscreen)
    {
        dm_data.s32flags = DM_NO_TITLE | DM_NO_STATUS_BAR | DM_NO_SOFTKEY | DM_BUTTON_DISABLE_BACKGROUND;
    }
    else
    {
#ifdef __MMI_FTE_SUPPORT__
        dm_data.s32flags = 0;    
        gdi_layer_clear(GDI_COLOR_BLACK);
#else
        dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
#endif
    }
    dm_setup_data(&dm_data);

    /* read history */
    if (gui_buffer != NULL)
    {
        wgui_catvdoply_history_struct *h = (wgui_catvdoply_history_struct*)gui_buffer;

        if (history_valid((U16)h->history_id, (U16)dm_data.s32CatId))
        {
            cat_vdoply_video_start_time = h->playing_time;
        }
    }

    dm_register_category_controlled_callback(DrawCateVdoCategoryControlArea);
    dm_redraw_category_screen();
    /* 
     * register exit category function befor calling the callback function, 
     * since this call back may exit this category 
     */

    /* if the screen is from the pop-up go-back, do not play video */
    if (mmi_is_redrawing_bk_screens())
    {
        return;
    }
    
    video_ret = cat_vdoply_is_video_play_result;

    if (wgui_is_touch_title_bar_buttons())
    {
        /* set active for title */
        gdi_layer_set_active(wgui_catvdo_top_layer);
    }

    /* play video */
    if (cat_vdoply_is_video_play == TRUE)
    {
         U32 blt_layer_flag;
#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__)
        wgui_catvdo_configure_drm_play();
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__) */

        if (wgui_is_touch_title_bar_buttons())
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
        }
        else
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
            /* base-video */
        }       
        video_ret = mdi_video_ply_play(
                       cat_vdoply_video_layer,
                       blt_layer_flag,
                       GDI_LAYER_ENABLE_LAYER_1,
                       1,                              /* repeat count */
                       is_visual_update,               /* update to LCM or not */
                       is_play_audio,                  /* play aud or not */                            
                       MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                       MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                       100,                            /* 1x play speed */
                       CatVdoplyPlayFinishCallback, 0);/* hook callback */


        /* 061506 double buffer Start */

        cat_vdoply_is_video_play = (video_ret >= 0) ? TRUE : FALSE;
        cat_vdoply_is_video_force_stop = FALSE;
    }

    if (cat_vdoply_is_video_play == FALSE)
    {
        /* APP may open video file to check the video size in the callback function,
           but it is not allowed to open video file twice.
           So, close file first to avoid this scenario. */
        if (cat_vdoply_is_video_open)
        {
            /* close video source */
            if (cat_vdoply_is_video_from_id)
            {
                /* source from id */
                mdi_video_ply_close_clip_id();
                cat_vdoply_is_video_open = FALSE;
            }
            else
            {
                /* source from file */
                mdi_video_ply_close_clip_file();
                cat_vdoply_is_video_open = FALSE;
            }
        }

        /* open file failed or play failed - reutrn error cause */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(video_ret);
        }
    }

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryVdoplyScreen
 * DESCRIPTION
 *  Exit Category 224 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategoryVdoplyScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_is_video_open)
    {
        /* stop video playing */
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }

        /* close video source */
        if (cat_vdoply_is_video_from_id)
        {
            /* source from id */
            mdi_video_ply_close_clip_id();
        }
        else
        {
            /* source from file */
            mdi_video_ply_close_clip_file();
        }
        cat_vdoply_is_video_open = FALSE;
    }

    /* let MMI can sleep */
    if (cat_vdoply_video_is_lcd_no_sleep)
    {
        srv_backlight_turn_off();
    }

#if !defined(__MDI_VIDEO_DISABLE_AUDIO_BACKGROUND_PLAY__)
    if (cat_vdoply_video_is_play_audio)
#endif /* !defined(__MDI_VIDEO_DISABLE_AUDIO_BACKGROUND_PLAY__) */
    {
        /* resume background audio */
        mdi_audio_resume_background_play();
    }

    if (wgui_is_touch_title_bar_buttons())
    {
        if (wgui_catvdo_top_buf != NULL)
        {
            /* reset base layer as active */
            gdi_layer_restore_base_active();

            /* free top layer */
            mmi_frm_scrmem_free(wgui_catvdo_top_buf);
            wgui_catvdo_top_buf = NULL;
            wgui_catvdo_top_layer = GDI_ERROR_HANDLE;

            /* reset status icon */
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
            wgui_status_icon_bar_set_target_layer(WGUI_STATUS_ICON_BAR_H_BAR, GDI_ERROR_HANDLE);
            wgui_status_icon_bar_reset_double_buffer(WGUI_STATUS_ICON_BAR_H_BAR);
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON) */
        }

        /* reset title background */
  //      title_bg_id = 0;

        if (wgui_catvdo_bottom_buffer != NULL)
        {
            /* reset bottom layer */
            mmi_frm_scrmem_free(wgui_catvdo_bottom_buffer);
            wgui_catvdo_bottom_layer = GDI_ERROR_HANDLE;
            wgui_softkey_set_double_buffer_enable(MMI_FALSE);
        }
#if !defined(__MMI_SLIM_IMG_RES__)
	set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_LEFT_SOFTKEY);
	set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_RIGHT_SOFTKEY);
	mmi_frm_cb_dereg_event(EVT_ID_PRE_KEY_EVT_ROUTING, wgui_cat129_key_proc, 0);
#endif
    }
    wgui_reset_touch_title_bar_buttons();
	g_cat225_is_vlw_scenario = MMI_FALSE;
#ifdef __MMI_SUBLCD__
    /* exit sublcd */
    if (cat_vdoply_is_sublcd_display)
    {
        GoBackSubLCDHistory();
        cat_vdoply_is_sublcd_display = FALSE;
    }
#endif /* __MMI_SUBLCD__ */ 
}


#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__)
/* For detail description, please refer to wgui_categories_multimedia.h */
void wgui_catvdo_set_drm_flag(S32 flags)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_catvdo_drm_flag = flags;
}


/* For detail description, please refer to wgui_categories_multimedia.h */
S32 wgui_catvdo_get_drm_flag(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_wgui_catvdo_drm_flag;
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void wgui_catvdo_configure_drm_play(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 DRM_flags = wgui_catvdo_get_drm_flag();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_flags & WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME)
    {
        mdi_video_ply_drm_disable_consume_time();
    }
    if (DRM_flags & WGUI_CATVDO_DRM_DISABLE_CONSUME_COUNT)
    {
        mdi_video_ply_drm_disable_consume_count();
    }
    if (DRM_flags & WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP)
    {
        mdi_video_ply_drm_disable_time_limit_stop();
    }
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void wgui_catvdo_configure_drm_repeat(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 DRM_flags = wgui_catvdo_get_drm_flag();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (DRM_flags & WGUI_CATVDO_DRM_DISABLE_CONSUME_TIME_LIMIT_STOP)
    {
        mdi_video_ply_drm_disable_consume_time();
        mdi_video_ply_drm_disable_consume_count();
        mdi_video_ply_drm_disable_time_limit_stop();
    }
}
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__) */


/*****************************************************************************
 * FUNCTION
 *  EnterCategoryVdoplySubScreen
 * DESCRIPTION
 *  Entery Category vdoply's sublcd screen, will draw an icon on sublcd
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void EnterCategoryVdoplySubScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ExecSubLCDCurrExitHandler();

    cat_vdoply_is_sublcd_display = TRUE;

#if defined(__MMI_VIDEO_PLAYER__)
    ShowCategory332Screen(IMG_ID_VDOPLY_SUBLCD_ICON);
#else
    ShowCategory332Screen(0);
#endif

    /* force all animation on sulcd stop, this is prevent IMG_ID_VDOPLY_SUBLCD_ICON is an animation gif */
    gdi_lcd_set_active(GDI_LCD_SUB_LCD_HANDLE);
    gdi_image_stop_animation_all();
    gdi_lcd_set_active(GDI_LCD_MAIN_LCD_HANDLE);

    SetSubLCDExitHandler(ExitCategoryVdoplySubScreen);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  ExitCategoryVdoplySubScreen
 * DESCRIPTION
 *  Exit Category Vdoply's sublcd screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategoryVdoplySubScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SubLCDHistoryNode sub_history;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* someone may exit/draw sublcd first then exit mainlcd, this may cause driver assert */
    if (cat_vdoply_is_video_play)
    {
        mdi_video_ply_stop();
        cat_vdoply_is_video_play = FALSE;
    }

    cat_vdoply_is_sublcd_display = FALSE;

    sub_history.entryFuncPtr = EnterCategoryVdoplySubScreen;
    AddSubLCDHistory(&sub_history);

}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  StopCategoryVdoplyVideo
 * DESCRIPTION
 *  Stop Category Vdoply screen's video
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void StopCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_vdoply_is_video_force_stop = TRUE;

    if (cat_vdoply_is_video_open)
    {
        /* stop video playing */
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  PauseCategoryVdoplyVideo
 * DESCRIPTION
 *  Pause video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void PauseCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* stop video playing */
    if (cat_vdoply_is_video_open)
    {
        if (cat_vdoply_is_video_play)
        {
            mdi_video_ply_stop();
            cat_vdoply_is_video_play = FALSE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  ResumeCategoryVdoplyVideo
 * DESCRIPTION
 *  Resume video play
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ResumeCategoryVdoplyVideo(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret;
    U32 blt_layer_flag;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* the callback function maybe already exit this category and close video file */
    /* check before play this video */
    if (cat_vdoply_is_video_open)
    {
        /* start play again */
        if (wgui_is_touch_title_bar_buttons())
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3;
        }
        else
        {
            blt_layer_flag = GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1;
        }
        video_ret = mdi_video_ply_play(
                        cat_vdoply_video_layer,
                        blt_layer_flag,
                        GDI_LAYER_ENABLE_LAYER_1,
                        1,                              /* repeat count */
                        cat_vdoply_video_is_visual_update,   /* update to LCM or not */
                        cat_vdoply_video_is_play_audio,      /* play aud or not */                            
                        MDI_DEVICE_SPEAKER2,            /* speaker & earphone */
                        MDI_VIDEO_LCD_ROTATE_0,         /* rotate */
                        100,                            /* 1x play speed */
                        CatVdoplyPlayFinishCallback, 0);   /* hook callback */


        if (video_ret < 0)
        {
            if (cat_vdoply_play_finish_callback != NULL)
            {
                cat_vdoply_play_finish_callback(video_ret);
            }
        }
        else
        {
            cat_vdoply_is_video_play = TRUE;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatVdoplyPlayFinishCallback
 * DESCRIPTION
 *  Play finish callback function, will handle looping here
 * PARAMETERS
 *  result      [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyPlayFinishCallback(MDI_RESULT result, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MDI_RESULT video_ret;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((result == MDI_RES_VDOPLY_ONLY_VIDEO_TRACK_ERROR) || (result == MDI_RES_VDOPLY_ONLY_AUDIO_TRACK_ERROR))
    {
        return; /* Special handle , requiered by MDI */
    }
    else if (result >= 0)
    {
        /* success play finished */

        /* call callback function */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(result);
        }

        /* teminate condition */
        if (cat_vdoply_video_repeat_count == 0)
        {
            cat_vdoply_is_video_finished = TRUE;
            return;
        }

        /* force stopped, will not loop again */
        if (cat_vdoply_is_video_force_stop == TRUE)
        {
            return;
        }

        /* calc remain count */
        if (cat_vdoply_video_repeat_count > 0)  /* play again */
        {
            if (cat_vdoply_video_repeat_count != 0xffff)
            {
                /* not infite play */
                cat_vdoply_video_repeat_count--;
            }
        }

        /* the callback function maybe already exit this category and close video file */
        /* check before play this video */
        if (cat_vdoply_is_video_open)
        {
            /* seek to first frame */
            video_ret = mdi_video_ply_seek(0);

            if (video_ret < 0)
            {
                if (cat_vdoply_play_finish_callback != NULL)
                {
                    cat_vdoply_play_finish_callback(video_ret);
                }
                return;
            }

#if defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__)
            wgui_catvdo_configure_drm_repeat();
#endif /* defined(__MMI_VIDEO_PLAY_SUPPORT__) && defined(__DRM_SUPPORT__) */

            /* start play again */
            if (wgui_is_touch_title_bar_buttons())
            {
                video_ret = mdi_video_ply_play(
                                cat_vdoply_video_layer,
                                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1 | GDI_LAYER_ENABLE_LAYER_2 | GDI_LAYER_ENABLE_LAYER_3,
                                GDI_LAYER_ENABLE_LAYER_1,
                                1,                      /* repeat count */
                                cat_vdoply_video_is_visual_update,       /* update to LCM or not */
                                cat_vdoply_video_is_play_audio,         /* play aud or not */    
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                CatVdoplyPlayFinishCallback, 0);    /* hook callback */
            }
            else
            {
                video_ret = mdi_video_ply_play(
                                cat_vdoply_video_layer,
                                GDI_LAYER_ENABLE_LAYER_0 | GDI_LAYER_ENABLE_LAYER_1,
                                GDI_LAYER_ENABLE_LAYER_1,
                                1,                      /* repeat count */
                                cat_vdoply_video_is_visual_update,      /* update to LCM or not */
                                cat_vdoply_video_is_play_audio,         /* play aud or not */                                
                                MDI_DEVICE_SPEAKER2,    /* speaker & earphone */
                                MDI_VIDEO_LCD_ROTATE_0, /* rotate */
                                100,                    /* 1x play speed */
                                CatVdoplyPlayFinishCallback, 0);    /* hook callback */
            }

            if (video_ret < 0)
            {
                if (cat_vdoply_play_finish_callback != NULL)
                {
                    cat_vdoply_play_finish_callback(video_ret);
                }
            }
        }
    }
    else
    {
        /* something wrong */

        /* call callback function */
        if (cat_vdoply_play_finish_callback != NULL)
        {
            cat_vdoply_play_finish_callback(result);
        }
    }

}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 


#if defined(__MMI_VIDEO_PLAY_SUPPORT__) // || defined(__MMI_SWFLASH__) 
/*****************************************************************************
 * FUNCTION
 *  CatVdoplyVolUp
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyVolUp(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_audio_volumn < SRV_PROF_VOL_LEVEL_7)
    {
        cat_vdoply_audio_volumn++;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(cat_vdoply_audio_volumn));
    }
}


/*****************************************************************************
 * FUNCTION
 *  CatVdoplyVolDown
 * DESCRIPTION
 *  volume down key press hdlr
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void CatVdoplyVolDown(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cat_vdoply_audio_volumn > SRV_PROF_VOL_LEVEL_0)
    {
        cat_vdoply_audio_volumn--;
        mdi_audio_set_volume(MDI_VOLUME_MEDIA, MDI_AUD_VOL_MUTE(cat_vdoply_audio_volumn));
    }
}
#endif /* __MMI_VIDEO_PLAY_SUPPORT__ */ 


/*****************************************************************************
 * FUNCTION
 *  wgui_cat_hide_title_button
 * DESCRIPTION
 *  Clear title bar button background as transparent color.
 * PARAMETERS
 *  button_object       [IN]     
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat_hide_title_button(void *button_object)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    button *button_obj = (button*) button_object;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(
        button_obj->x,
        button_obj->y,
        button_obj->x + button_obj->width + 1,
        button_obj->y + button_obj->height + 1);
    gdi_draw_solid_rect(
        button_obj->x,
        button_obj->y,
        button_obj->x + button_obj->width + 1,
        button_obj->y + button_obj->height + 1,
        GDI_COLOR_TRANSPARENT);
    gdi_layer_pop_clip();
}


#ifdef __MMI_TOUCH_SCREEN__
static MMI_BOOL (*Cat227ControlAreaPenHandler)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point) = NULL;


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenDownHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_DOWN, point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenUpHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenUpHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_UP, point);
    }
    else
    {
        return MMI_FALSE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  Cate227CategoryControlAreaPenMoveHandler
 * DESCRIPTION
 *  
 * PARAMETERS
 *
 * RETURNS
 *  
 *****************************************************************************/
MMI_BOOL Cate227CategoryControlAreaPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (Cat227ControlAreaPenHandler != NULL)
    {
        return Cat227ControlAreaPenHandler(MMI_PEN_EVENT_MOVE, point);
    }
    else
    {
        return MMI_FALSE;
    }
}
#endif /* __MMI_TOUCH_SCREEN__ */


/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory227Screen_int(
        U8 *title_string,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        void (*display_call_back) (dm_coordinates *coordinate),
        MMI_BOOL (*pen_all_call_back)(mmi_pen_event_type_enum pen_event, mmi_pen_point_struct point))
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dm_add_title((UI_string_type)title_string, get_image(title_icon));
    dm_add_softkey_id(left_softkey, right_softkey);

    dm_register_category_controlled_callback(display_call_back);
#if defined(__MMI_TOUCH_SCREEN__)
    Cat227ControlAreaPenHandler = pen_all_call_back;
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenUpHandler, MMI_PEN_EVENT_UP);
    wgui_register_category_screen_control_area_pen_handlers(Cate227CategoryControlAreaPenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    wgui_cat_setup_category(
        MMI_CATEGORY227_ID,
        DM_CLEAR_SCREEN_BACKGROUND,
        UI_dummy_function,
        dummy_get_history,
        dummy_get_history_size);
    dm_redraw_category_screen();

}

#if 0
#if defined(__MMI_SWFLASH__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_ALPHA_BLENDING__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_ALPHA_BLENDING__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if ((!defined( __MMI_MAINLCD_128X128__ ) && !defined(__MMI_MAINLCD_128X160__)) && defined(__GDI_MEMORY_PROFILE_2__))
#ifndef __MMI_TOUCH_DIAL_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif /* ((!defined( __MMI_MAINLCD_128X128__ ) && !defined(__MMI_MAINLCD_128X160__)) && defined(__GDI_MEMORY_PROFILE_2__)) */
/* under construction !*/
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(GUI_COMMON_SHOW_STATUS_ICON)*/
#endif /* __MMI_ALPHA_BLENDING__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __BT_SPK_VOL_CONTROL__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __BT_SPK_VOL_CONTROL__
/* under construction !*/
#endif /* __BT_SPK_VOL_CONTROL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__ 
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_TOUCH_SCREEN__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __BT_SPK_VOL_CONTROL__
/* under construction !*/
#endif /* __BT_SPK_VOL_CONTROL__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
#ifdef __MMI_AVATAR__
/*****************************************************************************
 * FUNCTION
 *  ExitCategoryAvatarScreen
 * DESCRIPTION
 *  Exit Category 224 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategoryAvatarScreen(void)
    {
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/


    /* let MMI can sleep, it's mflash's code, may not use*/
    //if (cat_swflash_is_lcd_no_sleep)
    //{
    //    srv_backlight_turn_off();
    //}

    cat_swflash_layer = GDI_ERROR_HANDLE;



    if (wgui_is_touch_title_bar_buttons())
    {
//        title_bg_id = 0;

        entry_full_screen();
    }

    wgui_reset_touch_title_bar_buttons();

}



/*****************************************************************************
 * FUNCTION
 *  DrawCateSWFlashCategoryControlArea
 * DESCRIPTION
 *  draw vdo contro area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coord
 * RETURNS
 *  void
 *****************************************************************************/
void DrawCateAvatarCategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 content_width, content_height;
    S32 content_offset_x, content_offset_y;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    {
        content_width = UI_device_width;
        content_height = UI_device_height;
        content_offset_x = 0;
        content_offset_y = 0;
    }


   /********************************************************************************
   *  Create Video Layer 
   ********************************************************************************/
    if (cat_swflash_layer == GDI_ERROR_HANDLE || cat_swflash_layer == GDI_LAYER_EMPTY_HANDLE)
    {/* the swflash layer maybe already set */
        if (wgui_is_touch_title_bar_buttons())
        {
            dm_create_layer(
                content_offset_x,
                content_offset_y,
                content_width,
                content_height,
                &cat_swflash_layer,
                DM_LAYER_ACTIVE_TOP);
        }
        else
        {
            dm_create_layer(
                content_offset_x,
                content_offset_y,
                content_width,
                content_height,
                &cat_swflash_layer,
                DM_LAYER_ACTIVE_BOTTOM);
        }
    }

    /* clear this layer with black */
    gdi_layer_push_and_set_active(cat_swflash_layer);
    gdi_layer_clear(gdi_layer_get_background());
    #ifdef GDI_USING_LAYER_BACKGROUND
    gdi_layer_set_background(GDI_COLOR_BLACK);
    #endif
    
#ifdef __MMI_ALPHA_BLENDING__
    gdi_set_alpha_blending_source_layer(cat_swflash_layer);
    	if (g_dm_data.s32CatId == MMI_CATEGORY34_ID)
	{
            gdi_anim_set_blt_before_callback((void (*)(GDI_RESULT))cat33_redraw_alpha_images);
	}
/* 073007 abm dialing Start */
#if ((!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)) && defined(__GDI_MEMORY_PROFILE_2__))
#ifndef __MMI_TOUCH_DIAL_SCREEN__
	else if (g_dm_data.s32CatId == MMI_CATEGORY16_ID)
	{
	    gdi_anim_set_blt_before_callback((void (*)(GDI_RESULT))DrawCate16CategoryBeforeBLTCallback);
	}
#endif
#endif /* ((!defined(__MMI_MAINLCD_128X128__) && !defined(__MMI_MAINLCD_128X160__)) && defined(__GDI_MEMORY_PROFILE_2__)) */
/* 073007 abm dialing End */




#endif /* __MMI_ALPHA_BLENDING__ */

    if (cat34_anim_handle!= GDI_NULL_HANDLE)
    {
        gdi_image_stop_animation(cat34_anim_handle);
        cat34_anim_handle = GDI_NULL_HANDLE;
    }

    if(!mmi_avatar_is_avatar_valid((U32) cat34_avatar_ptr, (U32) cat34_avatar_serial_num))
    {
        cat_avatar_is_valid = FALSE;
    }
    else
    {
        gdi_anim_draw_mem(
                0,
                0,
                (PS8) cat34_avatar_ptr,
                GDI_IMAGE_TYPE_AVATAR,
                0, // NO USE
                &cat34_anim_handle);
        cat_avatar_is_valid = TRUE;
    }
    gdi_layer_pop_and_restore_active();  
}
#endif


/*****************************************************************************
 * FUNCTION
 *  SetSWFlashPlayerLayer
 * DESCRIPTION
 *  set swflash player layer
 * PARAMETERS
 *  layer_handle      [IN]        layer handle
 * RETURNS
 *  void
 *****************************************************************************/
void SetSWFlashPlayerLayer(GDI_HANDLE layer_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_swflash_layer = layer_handle;
}


/*****************************************************************************
 * FUNCTION
 *  GetSWFlashPlayerLayer
 * DESCRIPTION
 *  Get swflash player layer
 * PARAMETERS
 *  void
 * RETURNS
 *  GDI_HANDLE
 *****************************************************************************/
GDI_HANDLE GetSWFlashPlayerLayer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return cat_swflash_layer;
}


/*****************************************************************************
 * FUNCTION
 *  GetCat34MediaType
 * DESCRIPTION
 *  Get category34 background media type
 * PARAMETERS
 *  void
 * RETURNS
 *  S32 type of media
 *****************************************************************************/
S32 GetCat34MediaType(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return g_mmi_idle_bg_media_type;
}


/*****************************************************************************
 * FUNCTION
 *  SetCat34MediaType
 * DESCRIPTION
 *  Get category34 background media type
 * PARAMETERS
 *  media_type      [IN]        media type
 * RETURNS
 *  void
 *****************************************************************************/
void SetCat34MediaType(S32 media_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_idle_bg_media_type = media_type;
}


/*****************************************************************************
 * FUNCTION
 *  SetupCat34Media
 * DESCRIPTION
 *  Setup category34 background media type
 * PARAMETERS
 *  bg_media_id             [IN]        New bg media ID
 *  bg_media_filename       [IN]        New bg media filename
 * RETURNS
 *  void
 *****************************************************************************/
mdi_result SetupCat34Media(U16 bg_media_id, S8 *bg_media_filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mdi_result mfh_ret = 0;
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MMI_SWFLASH__) || defined(__MMI_AVATAR__)
	if(bg_media_id == 0xFFFF && bg_media_filename == NULL)
    {
        bg_media_id = PhnsetGetCurWallPaperIdx();
        bg_media_filename = idle_screen_wallpaper_name;
    }
#endif

#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif
#ifdef __MMI_AVATAR__
    if (PhnsetGetDisplayType(bg_media_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_AVATAR;
    }
	else
#endif /* __MMI_AVATAR__ */
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
    }

    if (g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {

    }
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
    else /* g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_SWFLASH */
    {
        return 0;
    }
    return mfh_ret;
}

/*****************************************************************************
 * FUNCTION
 *  HandleCat34MediaPlayFailed
 * DESCRIPTION
 *  Handle media play error
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void HandleCat34MediaPlayFailed(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_SWFLASH__
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

#ifdef __MMI_AVATAR__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {
        if (cat_avatar_is_valid == MMI_FALSE)
        {
                PhnsetWallpaperBadFileCallBack(0);
                g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
        }
    }

#endif

}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory34Screen
 * DESCRIPTION
 *  show category 34
 * PARAMETERS
 *  left_softkey            [IN]    Left softkey label
 *  left_softkey_icon       [IN]    Icon for the Left softkey
 *  right_softkey           [IN]    Right softkey label
 *  right_softkey_icon      [IN]    Icon for the Right softkey
 *  bg_media_id             [IN]    background media ID
 *  bg_media_filename       [IN]    Background media filename
 *  history_buffer          [OUT]   History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory34Screen(
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U16 bg_media_id,
        S8 *bg_media_filename,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SWFLASH__ */
#endif
#ifdef __MMI_AVATAR__
    if(PhnsetGetDisplayType(bg_media_id) == PHNSET_TYPE_DISP_AVATAR)
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_AVATAR;
    }
    else
#endif /* __MMI_AVATAR__ */
    {
        g_mmi_idle_bg_media_type = MMI_IDLE_BG_MEDIA_IMG;
    }
    /********************************************************************************
    *  IdleScreen
    ********************************************************************************/
    ShowCategory33Screen_ext(
        left_softkey,
        left_softkey_icon,
        right_softkey,
        right_softkey_icon,
        history_buffer);

    /********************************************************************************
    *  SWFlash Setting
    ********************************************************************************/
    SetupCat34Media(bg_media_id, bg_media_filename);

    ExitCategoryFunction = ExitCategory34Screen;
    GetCategoryHistory = dummy_get_history;
    GetCategoryHistorySize = dummy_get_history_size;
    RedrawCategoryFunction = dm_redraw_category_screen;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_IMG )
    {
        dm_data.s32CatId = MMI_CATEGORY33_ID;
        dm_register_category_controlled_callback(NULL);
    }
#ifdef __MMI_AVATAR__
    else if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR  )
    {
        dispchar_get_current_avatar_id(bg_media_id, &(cat34_avatar_ptr), (U32 *)&cat34_avatar_serial_num);

        dm_data.s32CatId = MMI_CATEGORY34_ID;

        //if( mmi_avatar_is_avatar_valid((U32) cat34_avatar_ptr, (U32)cat34_avatar_serial_num) )
        {
            cat_avatar_is_valid = TRUE;
            dm_register_category_controlled_callback(DrawCateAvatarCategoryControlArea);
        }
        //else
        //    cat_avatar_is_valid = FALSE;
    }   
#endif
#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
#endif
    dm_data.s32flags = 0;
#ifdef __MMI_TOUCH_IDLESCREEN_SHORTCUTS__
    dm_data.s32flags |= DM_NO_SOFTKEY;
#endif /* __MMI_TOUCH_IDLESCREEN_SHORTCUTS__ */ 
    dm_data.s32flags |= DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);
    dm_register_category_controlled2_callback(dm_category_33_controlled_area);
    dm_redraw_category_screen();

    HandleCat34MediaPlayFailed();
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory34Screen
 * DESCRIPTION
 *  Exit category 34
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ExitCategory34Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cat_swflash_layer = GDI_ERROR_HANDLE;
#ifdef __MMI_AVATAR__
    if ( g_mmi_idle_bg_media_type == MMI_IDLE_BG_MEDIA_AVATAR)
    {
        ExitCategoryAvatarScreen();
    }
#endif

#if 0
#ifdef __MMI_SWFLASH__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_ALPHA_BLENDING__
/* under construction !*/
#endif
#endif /* __MMI_SWFLASH__ */
#endif

    ExitCategory33Screen();
}

#endif /* __MMI_SWFLASH__ */ 
/****************************************************************************
*
* MultiMedia Related [SubLCD] Categories
*
*****************************************************************************/

/*****************************************************************************
* [Category331] [SUB]
*
* This category is a empty SubLCD category.
*
*  ****************
*  *              *
*  *              *
*  *              *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory331Screen
 * DESCRIPTION
 *  Enter Category 331 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory331Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();

    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    SUBLCD_ExitCategoryFunction = ExitCategory331Screen;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory331Screen
 * DESCRIPTION
 *  Exit Category 331 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory331Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
* [Category332] [SUB]
*
* This category is to draw a image on sublcd
*
*  ****************
*  *              *
*  *              *
*  *  [ Image ]   *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory332Screen
 * DESCRIPTION
 *  Enter Category 332 Screen
 * PARAMETERS
 *  image_id        [IN]        Image id
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory332Screen(MMI_ID_TYPE image_id)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 image_width;
    S32 image_height;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();

    UI_set_sub_LCD_graphics_context();

    wgui_status_icon_bar_reset_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    gdi_layer_reset_clip();
    gdi_layer_clear(GDI_COLOR_WHITE);

    if (image_id != 0)
    {
        gdi_image_get_dimension_id(image_id, &image_width, &image_height);
        gdi_image_draw_id((UI_device_width - image_width) >> 1, (UI_device_height - image_height) >> 1, image_id);
    }

    gdi_layer_blt_base_layer(0, 0, UI_device_width - 1, UI_device_height - 1);

    SUBLCD_ExitCategoryFunction = ExitCategory332Screen;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;

    UI_set_main_LCD_graphics_context();
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 
}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory332Screen
 * DESCRIPTION
 *  Exit Category 332 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory332Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
}
#endif /* __MMI_SUBLCD__ */ 

/*****************************************************************************
* [Category333] [SUB]
*
* This category is for audio player sub display.
*
*  ****************
*  *              *
*  *              *
*  *  XXXXXXXXX   *
*  *              *
*  *              *
*  ****************
*
*****************************************************************************/


/*****************************************************************************
 * FUNCTION
 *  ShowCategory333Screen
 * DESCRIPTION
 *  Enter Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory333Screen(void)
{
#ifdef __MMI_SUBLCD__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    GDI_LOCK;
    SUBLCD_ExitCategoryFunction();
    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

    wgui_status_icon_bar_register_hide_callback(
        WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR,
        SUBLCD_screens_hide_status_icons);
    wgui_status_icon_bar_set_display(WGUI_STATUS_ICON_BAR_SUBLCD_H_BAR);

    gui_unlock_double_buffer();

    SUBLCD_ExitCategoryFunction = ExitCategory333Screen;
    SUBLCD_RedrawCategoryFunction = RedrawCategory333Screen;
    SUBLCD_GetCategoryHistory = GetCategory333History;
    SUBLCD_GetCategoryHistorySize = GetCategory333HistorySize;
    RedrawCategory333Screen();
    UI_set_main_LCD_graphics_context();
    GDI_UNLOCK;
#endif /* __MMI_SUBLCD__ */ 

}


/*****************************************************************************
 * FUNCTION
 *  ExitCategory333Screen
 * DESCRIPTION
 *  Exit Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void ExitCategory333Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();
    wgui_status_icon_bar_reset();
#ifdef __MMI_AUDIO_PLAYER__
    mmi_audply_exit_subLCD();
#endif 
#ifdef __MMI_FM_RADIO__
  //  mmi_fmrdo_exit_subLCD();
#endif 
    gui_hide_animations();

    SUBLCD_ExitCategoryFunction = MMI_dummy_function;
    SUBLCD_RedrawCategoryFunction = MMI_dummy_function;
    SUBLCD_GetCategoryHistory = dummy_get_history;
    SUBLCD_GetCategoryHistorySize = dummy_get_history_size;
    UI_set_main_LCD_graphics_context();
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  RedrawCategory333Screen
 * DESCRIPTION
 *  Redraw Category 333 Screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static void RedrawCategory333Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    color c = gui_color(0, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_set_sub_LCD_graphics_context();

    gui_lock_double_buffer();

#ifndef __MMI_SUB_WALLPAPER__
    wgui_status_icon_bar_show_sublcd_background(0, 0, (UI_device_width - 1), (UI_device_height - 1), MMI_FALSE);
#endif 
    SUBLCD_screens_show_status_icons();
    gui_draw_horizontal_line(0, UI_device_width - 1, 54, c);
#ifdef __MMI_AUDIO_PLAYER__
    if (mmi_audply_is_playing())
    {
        mmi_audply_redraw_subLCD(TRUE);
    }
#endif /* __MMI_AUDIO_PLAYER__ */ 
#ifdef __MMI_FM_RADIO__
    if (mmi_fmrdo_is_power_on())
    {
 //       mmi_fmrdo_redraw_subLCD(TRUE);
    }
#endif /* __MMI_FM_RADIO__ */ 

    gui_unlock_double_buffer();
    gui_BLT_double_buffer(0, 0, UI_device_width - 1, UI_device_height - 1);

    UI_set_main_LCD_graphics_context();
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCategory333HistorySize
 * DESCRIPTION
 *  Get Category 333 History Size
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static S32 GetCategory333HistorySize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (0);
}
#endif /* __MMI_SUBLCD__ */ 


/*****************************************************************************
 * FUNCTION
 *  GetCategory333History
 * DESCRIPTION
 *  *   Get Category 333 History
 * PARAMETERS
 *  history_buffer      [OUT]     History buffer
 * RETURNS
 *  void
 *****************************************************************************/
#ifdef __MMI_SUBLCD__
static U8 *GetCategory333History(U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return (history_buffer);
}
#endif /* __MMI_SUBLCD__ */ 


#if defined(__MMI_EDITABLE_AUDIO_EQUALIZER__)
static wgui_cat334_info_struct* g_wgui_cat334_info_p = NULL;

/*****************************************************************************
 * FUNCTION
 *  DrawCate334Content
 * DESCRIPTION
 *  draw category 334 content, that is, slide bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate334Content(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    PU8 bar_img = g_wgui_cat334_info_p->act_bar_image;
    PU8 ind_img = g_wgui_cat334_info_p->act_ind_image;
    S32 bar_x, bar_y, bar_w, bar_h;
    S32 ind_x, ind_y, ind_w, ind_h;
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    x = MMI_content_x;
    y = MMI_content_y;
    w = MMI_content_width;
    h = MMI_content_height;

    gdi_layer_push_and_set_clip(x, y, (x + w - 1), (y + h - 1));

    /* clear background */
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
    gdi_draw_solid_rect(x, y, (x + w - 1), (y + h - 1), GDI_COLOR_TRANSPARENT);
#else /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
    gdi_image_draw(x, y, g_wgui_cat334_info_p->bg_image);
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */

    /* display active slide bar */
    gdi_image_get_dimension(bar_img, &bar_w, &bar_h);
    bar_x = g_wgui_cat334_info_p->bar_start_x + 
                (bar_w + g_wgui_cat334_info_p->bar_hor_gap)*g_wgui_cat334_info_p->curr_act_bar;
    bar_y = g_wgui_cat334_info_p->bar_start_y;
    gdi_image_draw(bar_x, bar_y, bar_img);

    /* display each level indicator */
    gdi_image_get_dimension(ind_img, &ind_w, &ind_h);
    for (i = 0; i < g_wgui_cat334_info_p->total_bars; i++)
    {
        /* level starts from bottom */
        U16 level = g_wgui_cat334_info_p->total_levels - g_wgui_cat334_info_p->curr_level[i] - 1;

        ind_x = g_wgui_cat334_info_p->bar_start_x +
                    (bar_w + g_wgui_cat334_info_p->bar_hor_gap)*i -
                    ((ind_w - bar_w) >> 1);
        ind_y = g_wgui_cat334_info_p->bar_start_y + 
                    ((bar_h - g_wgui_cat334_info_p->available_height) >> 1) +
                    (g_wgui_cat334_info_p->available_height * level / (g_wgui_cat334_info_p->total_levels - 1)) -
                    (ind_h >> 1);
        gdi_image_draw(ind_x, ind_y, ind_img);
    }

    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  DrawCate334CategoryControlArea
 * DESCRIPTION
 *  draw category 334 control area
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void DrawCate334CategoryControlArea(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawCate334Content();
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void RedrawCategory334Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    DrawCate334Content();
    gdi_lcd_repaint_all();
}


#if defined(__MMI_TOUCH_SCREEN__)
/*****************************************************************************
 * FUNCTION
 *  Cate334TranslatePenEvent
 * DESCRIPTION
 *  translate pen event to bar ID & level
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Cate334TranslatePenEvent(mmi_pen_point_struct point, PU8 bar_ID, PU16 level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 x, y, w, h;
    PU8 bar_img = g_wgui_cat334_info_p->act_bar_image;
    PU8 ind_img = g_wgui_cat334_info_p->act_ind_image;
    S32 bar_w, bar_h;
    S32 ind_w, ind_h;
    MMI_BOOL ret = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_image_get_dimension(bar_img, &bar_w, &bar_h);
    gdi_image_get_dimension(ind_img, &ind_w, &ind_h);

    x = g_wgui_cat334_info_p->bar_start_x;
    y = g_wgui_cat334_info_p->bar_start_y;
    w = (g_wgui_cat334_info_p->total_bars - 1) * (bar_w + g_wgui_cat334_info_p->bar_hor_gap) + bar_w;
    h = bar_h;

    do
    {
        /* check content area */
        if (!PEN_CHECK_BOUND(point.x, point.y, x, y, w, h))
        {
            ret = MMI_FALSE;
            break;
        }

        /* check slide bar */
        {
            U8 temp_bar_id;

            temp_bar_id = (point.x - g_wgui_cat334_info_p->bar_start_x) /
                            (bar_w + g_wgui_cat334_info_p->bar_hor_gap);
            if ((point.x - g_wgui_cat334_info_p->bar_start_x) <
                ((bar_w + g_wgui_cat334_info_p->bar_hor_gap)*temp_bar_id + bar_w))
            {
                *bar_ID = temp_bar_id;
            }
            else
            {
                ret = MMI_FALSE;
                break;
            }
        }

        /* check level */
        {
            S32 available_x1, available_x2;

            available_x1 = g_wgui_cat334_info_p->bar_start_y +
                                ((bar_h - g_wgui_cat334_info_p->available_height) >> 1);
            available_x2 = available_x1 + g_wgui_cat334_info_p->available_height - 1;

            /* boundary check */
            if ((point.y < g_wgui_cat334_info_p->bar_start_y) ||
                (point.y >= (g_wgui_cat334_info_p->bar_start_y + bar_h - 1)))
            {
                ret = MMI_FALSE;
                break;
            }

            /* locate indicator */
            if ((point.y >= g_wgui_cat334_info_p->bar_start_y) &&
                (point.y < available_x1))
            {
                *level = 0;
            }
            else if ((point.y < (g_wgui_cat334_info_p->bar_start_y + bar_h - 1)) &&
                     (point.y >= available_x2))
            {
                *level = g_wgui_cat334_info_p->total_levels - 1;
            }
            else
            {
                *level = (point.y - available_x1 + 1) * g_wgui_cat334_info_p->total_levels / 
                           g_wgui_cat334_info_p->available_height;
            }

            *level = g_wgui_cat334_info_p->total_levels - *level - 1;
        }
        
        ret = MMI_TRUE;
    } while (0);
    
    return ret;
}


/*****************************************************************************
 * FUNCTION
 *  Cate334CategoryControlAreaPenDownAndMoveHandler
 * DESCRIPTION
 *  category 224 pen down and move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Cate334CategoryControlAreaPenDownHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 bar_id;
    U16 level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = Cate334TranslatePenEvent(point, &bar_id, &level);
    if (ret == MMI_TRUE)
    {
        gui_touch_feedback_play(GUI_TOUCH_FEEDBACK_DOWN);
        g_wgui_cat334_info_p->pen_handler(bar_id, level);
    }

    return ret;
}
/*****************************************************************************
 * FUNCTION
 *  Cate334CategoryControlAreaPenMoveHandler
 * DESCRIPTION
 *  category 334 pen move handler
 * PARAMETERS
 *  void
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
static MMI_BOOL Cate334CategoryControlAreaPenMoveHandler(mmi_pen_point_struct point)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret;
    U8 bar_id;
    U16 level;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ret = Cate334TranslatePenEvent(point, &bar_id, &level);
    if (ret == MMI_TRUE)
    {
        g_wgui_cat334_info_p->pen_handler(bar_id, level);
    }

    return ret;
}
#endif /* defined(__MMI_TOUCH_SCREEN__) */


/*****************************************************************************
 * FUNCTION
 *  ExitCategory334Screen
 * DESCRIPTION
 *  exit category 334 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void ExitCategory334Screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat334_info_p = NULL;
}


/* For detail description, please refer to wgui_categories_multimedia.h */
void ShowCategory334Screen_int(
        UI_string_type title,
        PU8 title_icon,
        UI_string_type left_softkey,
        UI_string_type right_softkey,
        wgui_cat334_info_struct* cat_info,
        U8* history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

    g_wgui_cat334_info_p = cat_info;

    gdi_layer_lock_frame_buffer();

    /* setup layout */
    gui_setup_common_layout();

    /* set title & softkey */
    dm_add_title(title, title_icon);
    dm_add_softkey_str(left_softkey, right_softkey);

    /* set background image */
    dm_add_image(cat_info->bg_image, NULL, NULL);

    gdi_layer_unlock_frame_buffer();
    
    /* set draw manager */
    ExitCategoryFunction = ExitCategory334Screen;
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    
#if defined(__MMI_TOUCH_SCREEN__)
    wgui_register_category_screen_control_area_pen_handlers(Cate334CategoryControlAreaPenDownHandler, MMI_PEN_EVENT_DOWN);
    wgui_register_category_screen_control_area_pen_handlers(Cate334CategoryControlAreaPenMoveHandler, MMI_PEN_EVENT_MOVE);
#endif /* defined(__MMI_TOUCH_SCREEN__) */

    dm_register_category_controlled_callback(DrawCate334CategoryControlArea);

    dm_data.s32ScrId = (S32) GetActiveScreenId();
    dm_data.s32CatId = MMI_CATEGORY334_ID;
    dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND;
    dm_setup_data(&dm_data);

    dm_redraw_category_screen();
}
#endif /* defined(__MMI_EDITABLE_AUDIO_EQUALIZER__) */

#if 0
#ifdef __MMI_CAT44X_SUPPORT__
/* under construction !*/
#if defined(__MMI_LANGLN__)
/* under construction !*/
#endif /* __MMI_LANGLN */
/* under construction !*/
#if defined(__MMI_MAINLCD_240X320__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_320X240__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_240X400__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#elif defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else /* defined(__MMI_MAINLCD_240X320__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_MAINLCD_240X320__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined (__MMI_WALLPAPER_ON_BOTTOM__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__)    
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif       
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
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MMI_TOUCH_SCREEN__
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
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
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
#ifdef __MMI_TOUCH_SCREEN__
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
#if defined(__MMI_TOUCH_SCREEN__)
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_WALLPAPER_ON_BOTTOM__ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif       
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
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_240X400__)
/* under construction !*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
#endif
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* defined(__MMI_MAINLCD_320X480__) */
#endif /* defined(__MMI_WALLPAPER_ON_BOTTOM__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
#endif
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__) && defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
    #endif
/* under construction !*/
#else /* defined(__MMI_MAINLCD_320X480__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #if defined(__MMI_WALLPAPER_ON_BOTTOM__)
/* under construction !*/
/* under construction !*/
    #endif
#endif  /* defined(__MMI_MAINLCD_320X480__) && defined(__MMI_WALLPAPER_ON_BOTTOM__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_LANGLN__)
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_SCREEN_ROTATE__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_SCREEN_ROTATE__ */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_TOUCH_SCREEN__
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
#ifndef __MMI_TITLE_BAR_NO_ICON_SHCT__	
/* under construction !*/
#endif/*__MMI_TITLE_BAR_NO_ICON_SHCT__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_MAINLCD_320X480__)  
#ifdef __MMI_WALLPAPER_ON_BOTTOM__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_WALLPAPER_ON_BOTTOM__ */
#endif /* defined(__MMI_MAINLCD_320X480__) */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__MMI_LANGLN__)
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
#if !defined(__MMI_MAINLCD_320X480__)
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
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */ 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_CAT44X_SUPPORT__ */
#endif 

/*****************************************************************************
 * FUNCTION
 *  cat129_clear_icon_bg
 * DESCRIPTION
 *  Clear button background function
 * PARAMETERS
 *  button      [IN]        Button pointer
 * RETURNS
 *  void
 *****************************************************************************/
void cat129_clear_icon_bg(void *button)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    icontext_button *b = (icontext_button*) button;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(b->x, b->y, b->x + b->width, b->y + b->height);
    gdi_draw_solid_rect(MMI_title_x, MMI_title_y, MMI_title_x + MMI_title_width - 1, MMI_title_y + MMI_title_height - 1, GDI_COLOR_TRANSPARENT);    /* 061705 Calvin added */
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif//0
    //{
#if !(defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__))
        gui_draw_filled_area(
            MMI_title_x,
            MMI_title_y,
            MMI_title_x + MMI_title_width - 1,
            MMI_title_y + MMI_title_height - 1,
            current_UI_theme->window_title_theme->active_filler);
#endif
    //}
    gdi_layer_pop_clip();
}


/*****************************************************************************
 * FUNCTION
 *  cat129_get_image_handle
 * DESCRIPTION
 *  get the animation handle for cat 129
 * PARAMETERS
 *  void
 * RETURNS
 *  gdi_handle
 *****************************************************************************/
gdi_handle cat129_get_image_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return dm_get_image_handle(0);
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat129_animation_pre_callback
 * DESCRIPTION
 *  set the animation pre callback handle for cat 129
 * PARAMETERS
 *  result    [IN]    GDI result
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat129_animation_pre_callback(GDI_RESULT result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_lock_frame_buffer();
    wgui_status_icon_bar_update();
    gdi_layer_unlock_frame_buffer();
}
#if !defined(__GDI_MEMORY_PROFILE_2__)
/*****************************************************************************
 * FUNCTION
 *  wgui_cat129_draw_ctrl_area1
 * DESCRIPTION
 *  draw the category control area 1 for category 129
 * PARAMETERS
 *  coordinate  [IN]    coordinate
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat129_draw_ctrl_area1(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 img_w = 1, img_h = 1;
    S32 x = 0, y = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_push_and_set_clip(MMI_content_x, MMI_content_y, MMI_content_x + MMI_content_width - 1, MMI_content_y + MMI_content_height - 1);

    /* clear */
    gdi_draw_solid_rect(0, 0, UI_device_width - 1, UI_device_height - 1, GDI_COLOR_WHITE);

    /* draw image */
    gui_measure_image(MMI_message_icon, &img_w, &img_h);
    if (img_w < UI_device_width)
    {
        x = ((UI_device_width - img_w) >> 1);
    }
    if (img_h < UI_device_height)
    {
        y = ((UI_device_height - img_h) >> 1);
    }
    gdi_image_draw_animation(x, y, (S8*)MMI_message_icon, &animation_handle);
    gdi_anim_set_draw_before_callback(wgui_cat129_animation_pre_callback);

    gdi_layer_pop_clip();
}
#endif /* !defined(__GDI_MEMORY_PROFILE_2__) */

#if defined(__MMI_MAINLCD_240X400__) || defined(__MMI_MAINLCD_320X480__) || defined(__MMI_MAINLCD_320X240__)
    #ifndef __WGUI_CAT129_DRAW_TITLE_AREA__
    #define __WGUI_CAT129_DRAW_TITLE_AREA__
    #endif
#endif

#if defined(__MMI_MAINLCD_240X400__)
#ifdef __MMI_FTE_SUPPORT__
	#define WGUI_CAT129_TITLE_BG_X 44
	#define WGUI_CAT129_TITLE_BG_WIDTH 150
#else
	#define WGUI_CAT129_TITLE_BG_X 47
	#define WGUI_CAT129_TITLE_BG_WIDTH 145
#endif
#elif defined(__MMI_MAINLCD_320X480__)
    #define WGUI_CAT129_TITLE_BG_X 72
	#define WGUI_CAT129_TITLE_BG_WIDTH 176
#elif  defined(__MMI_MAINLCD_320X240__)
    #define WGUI_CAT129_TITLE_BG_X 71
	#define WGUI_CAT129_TITLE_BG_WIDTH 176
#else
	#define WGUI_CAT129_TITLE_BG_X 47
	#define WGUI_CAT129_TITLE_BG_WIDTH 145
#endif

#ifdef __MMI_MAINLCD_240X320__
	#define WGUI_CAT129_TITLE_GAP 50
#elif defined(__MMI_MAINLCD_176X220__)
	#define WGUI_CAT129_TITLE_GAP 35
#else
	#define WGUI_CAT129_TITLE_GAP 18
#endif

#ifdef __WGUI_CAT129_DRAW_TITLE_AREA__
static scrolling_text wgui_cat129_scrolling_text;
static void wgui_cat129_scrolling_timer(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_handle_scrolling_text(&wgui_cat129_scrolling_text);
}
static void wgui_cat129_scrolling_text_draw_background(S32 x1, S32 y1, S32 x2, S32 y2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_push_and_set_clip(x1, y1, x2, y2);
//	gdi_image_draw(MMI_title_x, MMI_title_y, get_image(title_bg_id));
	gui_pop_clip();
    //gdi_draw_solid_rect(x1, y1, x2, y2, GDI_COLOR_TRANSPARENT);
}
#endif /*__WGUI_CAT129_DRAW_TITLE_AREA__*/
/*****************************************************************************
 * FUNCTION
 *  wgui_cat129_draw_ctrl_area2
 * DESCRIPTION
 *  draw the category control area 2 for category 129
 * PARAMETERS
 *  coordinate  [IN]    coordinate
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat130_draw_ctrl_area2(dm_coordinates *coordinate)
{
#ifdef __WGUI_CAT129_DRAW_TITLE_AREA__
	S32 sw, sh;
	S32 x, y, w, h;
    stFontAttribute title_font;

	title_font = *current_window_title_theme->text_font;
	title_font.smallCaps = 2;

	gui_set_font(&title_font);
	Get_StringWidthHeight((U8*)MMI_message_string, &sw, &sh);

	x = WGUI_CAT129_TITLE_BG_X;
	y = MMI_title_y;
	w = WGUI_CAT129_TITLE_BG_WIDTH;
	h = MMI_title_height;

	if((sw) < w)
	{
		x = x + (w - sw)/2;
		w = sw;
	}

	y = y + (h - sh)/2;
	h = (h + sh)/2;
	if(sw > WGUI_CAT129_TITLE_BG_WIDTH)
	{
	    gui_create_scrolling_text(
				&wgui_cat129_scrolling_text,
				x,
				y,
				w,
				h,
				MMI_message_string,
				wgui_cat129_scrolling_timer,
				wgui_cat129_scrolling_text_draw_background,
				*current_MMI_theme->title_text_color,
				*current_MMI_theme->title_text_border_color);
	    wgui_cat129_scrolling_text.flags |= UI_SCROLLING_TEXT_BORDERED_TEXT;
	    gui_show_scrolling_text(&wgui_cat129_scrolling_text);
	}
	else
	{
		gui_set_text_color(*current_MMI_theme->title_text_color);
		gui_set_text_border_color(*current_MMI_theme->title_text_border_color);

        if (mmi_fe_get_r2l_state())
		{
			gui_move_text_cursor(x, y);
		}
		else
		{
			gui_move_text_cursor(x+w-1, y);

		}
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_VECTOR_FONT_SUPPORT__)
		gui_print_text(MMI_message_string);
#else
		gui_print_bordered_text(MMI_message_string);
#endif
	}

#else
	return;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  wgui_cat130_draw_ctrl_area1
 * DESCRIPTION
 *  Draws the category130 category control area
 * PARAMETERS
 *  coordinate      [IN/OUT]        Coordinates of category controlled area.
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat130_draw_ctrl_area1(dm_coordinates *coordinate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gdi_layer_clear(GDI_COLOR_WHITE);
    gui_draw_filled_area(0, 0, UI_device_width, UI_device_height, current_MMI_theme->idle_bkg_filler);
}
#if !defined(__MMI_SLIM_IMG_RES__)
static mmi_ret wgui_cat129_key_proc(mmi_event_struct *event)
{

	  if (event->evt_id == EVT_ID_PRE_KEY_EVT_ROUTING)
	  {
	      mmi_frm_key_evt_struct *key_evt = (mmi_frm_key_evt_struct *)event;


		  if(key_evt->key_code == KEY_LEFT_ARROW && key_evt->key_type == KEY_EVENT_DOWN)
		  {
				icontext_button *left_button = dm_get_button(0);
				left_button->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
				dm_redraw_button(0);
				gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);

		  }
		  else if(key_evt->key_code == KEY_RIGHT_ARROW && key_evt->key_type == KEY_EVENT_DOWN)
		  {
				icontext_button *right_button = dm_get_button(1);
				right_button->flags |= (UI_BUTTON_STATE_CLICKED | UI_BUTTON_STATE_DOWN);
				dm_redraw_button(1);
				 gdi_layer_blt_previous(0, 0, MAIN_LCD_DEVICE_WIDTH, MAIN_LCD_DEVICE_HEIGHT);
		  }
	  }

	  return MMI_RET_OK;
}
#endif
/*****************************************************************************
 * FUNCTION
 *  wgui_cat129_exit
 * DESCRIPTION
 *  Exits the category129 screen
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void wgui_cat129_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    gui_hide_animations();

//    title_bg_id = 0;

#ifdef __WGUI_CAT129_DRAW_TITLE_AREA__
	gui_scrolling_text_stop(&wgui_cat129_scrolling_text);
#endif
#if !defined(__MMI_SLIM_IMG_RES__)
	set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_LEFT_SOFTKEY);
	set_softkey_flags_off(UI_BUTTON_DISABLE_BACKGND_DISPLAY, MMI_RIGHT_SOFTKEY);
    if (wgui_is_touch_title_bar_buttons())
	mmi_frm_cb_dereg_event(EVT_ID_PRE_KEY_EVT_ROUTING, wgui_cat129_key_proc, 0);
#endif
    wgui_reset_touch_title_bar_buttons();
}

#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_SLIM_IMG_RES__)
static void wgui_cat129_hide_title_callback(S32 x, S32 y, S32 w, S32 h)
{
	gdi_draw_solid_rect(x, y, x+w-1, y+h-1, GDI_COLOR_TRANSPARENT);
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_SLIM_IMG_RES__)
	gui_fill_rectangle(WGUI_CAT129_TITLE_GAP, y, x+w-WGUI_CAT129_TITLE_GAP, y+h-1, gui_color(126, 186, 0));
#endif
}
#endif /* __MMI_BASIC_UI_STYLE__*/

#if defined(__MMI_FTE_SUPPORT_SLIM__)
UI_filled_area dm_image_background_filler = {
 		UI_FILLED_AREA_TYPE_COLOR,
 		UI_IMAGE_ID_NULL,
 		NULL,
 		{0,0,0,100},//Background black
 		{0,0,0,100},
 		{0,0,0,100},
 		{0,0,0,100},
 		0};
#endif
void ShowCategory129ScreenInternal(
        UI_string_type title,
        PU8 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U8 *history_buffer,
        PU8 message_icon2,
        U8 buf_without_header)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_data_struct dm_data;
#if defined(__MMI_TOUCH_SCREEN__)
    U16 btn_prev_item_id = 0, btn_next_item_id = 0;
#endif /* defined(__MMI_TOUCH_SCREEN__) */
    U16 btn_left_down, btn_left_up;
    U16 btn_right_down, btn_right_up;
#if defined(__MMI_FTE_SUPPORT_SLIM__)
	S32 image_width = 0, image_height = 0;
	MMI_BOOL cat129_is_resize = MMI_FALSE;
#endif

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);

    gdi_layer_lock_frame_buffer();
    dm_add_title(title, title_icon);
    dm_add_softkey_id(left_softkey, right_softkey);
    wgui_softkey_set_filler_disabled(MMI_TRUE);
    if(message_icon != 0 || message_icon2 != 0)
    {
#if defined(__GDI_MEMORY_PROFILE_2__)
        /* use new layer instead of scr_bg layer to draw wallpaper */
        if(buf_without_header == 1)
        {            
            dm_add_image_2((message_icon2 == NULL ? get_image(message_icon) : message_icon2 ), 0, NULL, DM_IMAGE_RAW_DATA_BUFFER, 0, LCD_WIDTH, LCD_HEIGHT);
        }
        else if(buf_without_header == 0)
        {
        #if defined(__MMI_FTE_SUPPORT_SLIM__)
			if (message_icon2 != NULL)
			{
				gdi_image_get_dimension(message_icon2, &image_width, &image_height);
			}

			if ( image_width > UI_DEVICE_WIDTH || image_height > MMI_COMMON_CONTENT_HEIGHT )
			{
				cat129_is_resize = MMI_TRUE;
				dm_add_image_2((message_icon2 == NULL ? get_image(message_icon) : message_icon2 ), 0, &dm_image_background_filler, DM_IMAGE_WITH_HEADER|DM_IMAGE_RAW_DATA_BUFFER, 0, image_width, image_height );
			}
			else
			{
				cat129_is_resize = MMI_FALSE;
				dm_add_image((message_icon2 == NULL ? get_image(message_icon) : message_icon2 ), NULL, &dm_image_background_filler);
			}
		#else
            dm_add_image((message_icon2 == NULL ? get_image(message_icon) : message_icon2 ), NULL, NULL);
		#endif
        }
        else
        {
            ASSERT(0);
        }
#if defined(GUI_COMMON_SHOW_STATUS_ICON)
        dm_set_image_blt_before_callback(0, wgui_cat129_animation_pre_callback);
#endif
        wgui_set_wallpaper_on_bottom(MMI_TRUE);
#else /* defined(__GDI_MEMORY_PROFILE_2__) */
        MMI_message_icon = (message_icon2 == NULL ? get_image(message_icon) : message_icon2 );
#endif /* defined(__GDI_MEMORY_PROFILE_2__) */

#ifdef __MMI_SUBLCD__
        {
            S32 w, h;
            gdi_image_get_dimension_id(message_icon, &w, &h);
            
            if((w <= SUBLCD_WIDTH) && (h <= SUBLCD_HEIGHT))
            {
                 wgui_softkey_set_is_in_popup(MMI_TRUE); // draw softkey background if wallpaper not fill mainlcd.
            }
        }
#endif
    }
    else
    {
         wgui_set_wallpaper_on_bottom(MMI_TRUE);
    }
    gdi_layer_get_base_handle(&wgui_base_layer);
    wgui_status_icon_bar_set_target_layer(
        WGUI_STATUS_ICON_BAR_H_BAR, 
        wgui_base_layer);

    /* check if the title bar buttons are enabled for the particular screen. */
    if (wgui_is_touch_title_bar_buttons())
    {
#if !defined(__MMI_SLIM_IMG_RES__)
        btn_left_down = LEFT_ARROW_DOWN;
        btn_left_up = LEFT_ARROW_UP;

        btn_right_down = RIGHT_ARROW_DOWN;
        btn_right_up = RIGHT_ARROW_UP;
		mmi_frm_cb_reg_event(EVT_ID_PRE_KEY_EVT_ROUTING, wgui_cat129_key_proc, 0);
#else
        btn_left_down = btn_left_up = LEFT_RED_ARROW;
        btn_right_down = btn_right_up = RIGHT_RED_ARROW;
#endif
#if defined(__MMI_TOUCH_SCREEN__)
        btn_prev_item_id = 
#endif /* defined(__MMI_TOUCH_SCREEN__) */
                    dm_add_button(
                            NULL,
                            get_image(btn_left_up),
                            get_image(btn_left_down),
                            cat129_clear_icon_bg);

#if defined(__MMI_TOUCH_SCREEN__)
        btn_next_item_id = 
#endif /* defined(__MMI_TOUCH_SCREEN__) */
                    dm_add_button(
                            NULL,
                            get_image(btn_right_up),
                            get_image(btn_right_down),
                            cat129_clear_icon_bg);
#if !defined(__MMI_SLIM_IMG_RES__)
        (dm_get_button(0))->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
        (dm_get_button(1))->flags &= ~UI_BUTTON_SHIFT_BUTTON1;
#endif

#if 0//!(defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_SLIM_IMG_RES__))
/* under construction !*/
#endif

#if 0
/* under construction !*/
#ifdef __MMI_SUBLCD__
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    }
    gdi_layer_unlock_frame_buffer();
#if defined(__MMI_TOUCH_SCREEN__)
    if (wgui_is_touch_title_bar_buttons())
    {
        /* register the handler for pen event down istead of pen event up */
        dm_register_button_functions(btn_prev_item_id, KEY_EVENT_UP, gMMI_touch_title_button1_down_handler);
        dm_register_button_functions(btn_next_item_id, KEY_EVENT_UP, gMMI_touch_title_button2_down_handler);
    }
#endif /* defined(__MMI_TOUCH_SCREEN__) */ 
    dm_setup_category_functions(dm_redraw_category_screen, dummy_get_history, dummy_get_history_size);
    if(message_icon != 0 || message_icon2 != 0)
    {
		if (wgui_is_touch_title_bar_buttons())
		{
#if defined(__MMI_FTE_SUPPORT_SLIM__) && defined(__GDI_MEMORY_PROFILE_2__)
			if (cat129_is_resize)
			{
				dm_data.s32CatId = MMI_CATEGORY129_RESIZE_ID;
			}
			else
#endif
			{
				dm_data.s32CatId = MMI_CATEGORY129_ID;
			}
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__) || defined(__MMI_SLIM_IMG_RES__)
			wgui_title_register_hide_callback(wgui_cat129_hide_title_callback);
#endif
		}
		else
		{
			dm_data.s32CatId = MMI_CATEGORY129_NO_BUTTON_ID;
		}
#if !defined(__GDI_MEMORY_PROFILE_2__)
        dm_register_category_controlled_callback(wgui_cat129_draw_ctrl_area1);
#endif /* !defined(__GDI_MEMORY_PROFILE_2__) */
    }
    else
    {
#ifdef __WGUI_CAT129_DRAW_TITLE_AREA__
		dm_add_title(0, title_icon);
		MMI_message_string = title;
#endif
#if defined(__MMI_BASIC_UI_STYLE__) || defined(__MMI_FTE_SUPPORT_SLIM__)|| defined(__MMI_SLIM_IMG_RES__)
		wgui_title_register_hide_callback(wgui_cat129_hide_title_callback);
#endif
        dm_data.s32CatId = MMI_CATEGORY130_ID;
        dm_register_category_controlled_callback(wgui_cat130_draw_ctrl_area1);
		dm_register_category_controlled2_callback(wgui_cat130_draw_ctrl_area2);
    }
    ExitCategoryFunction = wgui_cat129_exit;
    dm_data.s32ScrId = (S32) GetActiveScreenId();
#if defined(__MMI_FTE_SUPPORT_SLIM__) && defined(__GDI_MEMORY_PROFILE_2__)
	if (cat129_is_resize)
	{
		dm_data.s32flags =  DM_CLEAR_SCREEN_BACKGROUND | DM_LITE_DISP_WALLPAPER_USER_COLOR | DM_SET_AS_ABM_LAYER;
		dm_set_scr_bg_lite_color(GDI_COLOR_BLACK);
	}
	else
#endif
	{
		dm_data.s32flags = DM_CLEAR_SCREEN_BACKGROUND |DM_SET_AS_ABM_LAYER;
	}
    dm_setup_data(&dm_data);
    dm_redraw_category_screen();

}


/* For detail description, please refer to wgui_categories.h */
void ShowCategory129Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory129ScreenInternal(
            (UI_string_type) title,
            get_image(title_icon),
            left_softkey,
            right_softkey,
            message_icon,
            history_buffer,
            NULL,
            0);

}

/*****************************************************************************
 * FUNCTION
 *  ShowCategory130Screen
 * DESCRIPTION
 *  Displays the category130 screen,show system theme wallpaper
 * PARAMETERS
 *  title                   [IN]        Title for the screen
 *  title_icon              [IN]        Icon displayed with the title
 *  left_softkey            [IN]        Left softkey label
 *  left_softkey_icon       [IN]        Left softkey icon
 *  right_softkey           [IN]        Right softkey label
 *  right_softkey_icon      [IN]        Right softkey icon
 *  history_buffer          [IN]        History buffer
 * RETURNS
 *  void
 *****************************************************************************/
void ShowCategory130Screen(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 left_softkey_icon,
        U16 right_softkey,
        U16 right_softkey_icon,
        U8 *history_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ShowCategory129ScreenInternal(
            (UI_string_type) title,
            get_image(title_icon),
            left_softkey, 
            right_softkey, 
            0,
            history_buffer,
            NULL,
            0);
}


static MMI_BOOL g_wgui_cat132_is_fullscreen = MMI_FALSE;


/* For detail description, please refer to wgui_categories.h */
static void wgui_cat132_exit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat132_is_fullscreen = MMI_FALSE;
}


/* For detail description, please refer to wgui_categories.h */
void wgui_cat132_enable_fullscreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_wgui_cat132_is_fullscreen = MMI_TRUE;
}


/* For detail description, please refer to wgui_categories.h */
void ShowCategory132Screen_int(
        U8 *title,
        U16 title_icon,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        U8 *history_buffer)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 catId;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    UI_UNUSED_PARAMETER(history_buffer);
    
    gdi_layer_lock_frame_buffer();

    /* Title */
    wgui_title_set_menu_shortcut_number(-1);
    dm_add_title((UI_string_type)title, get_image(title_icon));

    if (!g_wgui_cat132_is_fullscreen)
    {
        dm_add_softkey_id(left_softkey, right_softkey);
    }

    dm_add_image(get_image(message_icon), NULL, NULL);
    
    gdi_layer_unlock_frame_buffer();
    
    catId = (g_wgui_cat132_is_fullscreen) ? (MMI_CATEGORY132_FULLSCREEN_ID) : (MMI_CATEGORY132_ID);
#if defined(__MMI_SCREEN_ROTATE__)
    catId = (mmi_frm_is_screen_width_height_swapped()) ? (MMI_CATEGORY132_ROTATE_ID) : (catId);
#endif /* defined(__MMI_SCREEN_ROTATE__) */

    wgui_cat_setup_category(
            catId,
            DM_CLEAR_SCREEN_BACKGROUND_COLOR,
            wgui_cat132_exit,
            dummy_get_history,
            dummy_get_history_size);
    dm_redraw_category_screen();
}   /* end of ShowCategory132Screen */


