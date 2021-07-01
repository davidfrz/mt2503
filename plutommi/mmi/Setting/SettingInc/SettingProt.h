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
 * SettingProt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#ifndef SETTINGPROT_H
#define SETTINGPROT_H

#include "MMIDataType.h"
#include "PhoneSetup.h"
/* auto add by kw_check begin */
#include "kal_non_specific_general_types.h"
/* auto add by kw_check end */
#include "MMI_ap_dcm_config.h"
extern void EntryScrSettingMenu(void);
extern void mmi_phnset_init(void);

extern void SendPHMessageAndShowScreen(void);

extern void EntryScrSetTime(void);
extern void ExitScrSetTime(void);
extern void SetTimeFailure(void);

extern void EntryScrSetTimeFormat(void);
extern void ExitScrSetTimeFormat(void);

extern void EntryScrSetDate(void);
extern void ExitScrSetDate(void);
extern void SetDateFailure(void);

extern void EntryScrSetDateFormat(void);
extern void ExitScrSetDateFormat(void);
extern void SendMessageDateAndShowScreen(void);

extern void EntryScr24hours(void);
extern void ExitScr24hours(void);

extern void EntryScrAmPm(void);
extern void ExitScrAmPm(void);

extern void EntryScrDateMonth(void);
extern void ExitScrDateMonth(void);

extern void EntryScrDateMonthYear(void);
extern void ExitScrtDateMonthYear(void);

extern void EntryScrMonthDateYear(void);
extern void ExitScrMonthDateYear(void);

extern void EntryScrDateMonthYear2(void);
extern void ExitScrDateMonthYear2(void);

extern void SetTimeFormatSuccess(void *info);
extern void SetDateFormatSuccess(void *info);
extern void SetTimeFormatFailure(void);
extern void SetDateFormatFailure(void);

extern void EntryWelcomeTextOff(void);

extern void ExitWelcomeTextDoneHdlr(void);

extern void InitPhoneSetupApp(void);

extern void EntryRstCheckPhoneLock(void);
extern void EntryRstScr(void);
extern void RstVerifyPhoneLockReq(void);
extern void RstSendRestoreMsgToWap(void);

extern U8 RstGetNITZStatusDefault(void);
extern U8 RstGetScrSaverStatusDefault(void);
extern U8 RstGetScrSaverWaitingDefault(void);
extern U16 RstGetScrSaverImgIdDefault(void);
extern U16 RstGetWallpaperImgIdDefault(void);

#ifdef __MMI_SUB_WALLPAPER__
extern U16 RstGetWallpaperSubImgIdDefault(void);    /* diamond, 2005/06/03 sub-LCD wallpaper default value */
#endif 
extern void RstWapRspHdlr(void *msg);
extern void RstStartRestore(void);
extern void EntryRstConfirm(void);
extern void GoBackfromRestoreTimer(void);
extern void GoBack3NHistory(void);
extern void ExitConfirmRestoreFactory(void);
extern void SECSETGetPIN1StatusReq(void);
extern void HighlightAphorismText(void);
extern void EntryAphorismText(void);
extern void SendAphorismOnOff(void);
extern void ExitScrWaitForResponse(void);


#ifdef __MMI_AVATAR__
extern void dispchar_get_current_avatar_id(U16 id, U32 *avatar_id, U32 *serial_num);
#endif
#if 0
#if __MMI_PHNSET_COMMENT__
#ifdef __MMI_PREFER_INPUT_METHOD__
/* under construction !*/
#endif 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
#if defined(__MMI_APHORISM__)
/* under construction !*/
#endif 
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_PHNSET_COMMENT__ */ 
#endif
#endif /* SETTINGPROT_H */ 

