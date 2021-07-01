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
 *  wgui_categories_btbox.h
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *  Categories for BTBox
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Log$
 *
 * 06 29 2016 ziyao.xiong
 * removed!
 * [2503AE]Alarm & Calendar.
 *
 * 05 20 2014 anne.xu
 * removed!
 * .Wearable Device 11CW1418MP code check in
 *
 * 03 28 2014 zhixiong.wang
 * removed!
 * Check in karaoke & Megaphone QVGA Code into 11C & 11C52MP.
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
#ifndef __WGUI_CATEGORIES_BTBOX_H__
#define __WGUI_CATEGORIES_BTBOX_H__

#if defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__) || defined(__MMI_WEARABLE_DEVICE_SETTING__) || defined(__MMI_WEARABLE_DEVICE_ALARM__)

#include "MMIDataType.h"

#include "gdi_const.h"
#include "gdi_datatype.h"

#include "gui_data_types.h"
#include "gui.h"
#include "gui_typedef.h"

#include "gui_picker.h"

/***************************************************************************** 
* Define
*****************************************************************************/
typedef struct
{
    gdi_handle anim_handle;
    U16 message_icon;
    MMI_BOOL anim_play;
} wgui_cat8001_context;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef __MMI_GUI_PICKER__
typedef struct
{
    MMI_BOOL two_page;
    U8 current_page;
    FuncPtr save_func;
    gui_picker_type picker_type;
} wgui_picker_context;
#endif  //__MMI_GUI_PICKER__


/***************************************************************************** 
* Extern Global Function
*****************************************************************************/
extern void ShowCategory8001Screen(
        U16 title,
        U16 left_softkey,
        U16 right_softkey,
        U16 message_icon,
        MMI_BOOL anim_play);

extern void wgui_cat8001_set_animation(MMI_BOOL play);

extern void wgui_picker_entry(U8* user_data, mmi_id group_id, FuncPtr save_func);
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
#endif

#endif  /* defined(__MMI_BTD_BOX_UI_STYLE__) || defined(__MMI_MEGAPHONE_SUPPORT__) */

#ifdef __KARAOKE_SUPPORT__
extern void ShowCategory8002Screen(
        U16 title,
        U16 left_softkey,
        U16 right_softkey);
#endif
#endif  //__WGUI_CATEGORIES_BTBOX_H__

