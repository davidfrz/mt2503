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
 *  wgui_categories_notification.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Category header file
 *
 * Author:
 * -------
 *  
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WGUI_CATEGORIES_NOTIFICATION_H__
#define __WGUI_CATEGORIES_NOTIFICATION_H__
#include "MMIDataType.h"
#include "gui_data_types.h"
    
//lhm remove from wgui_categories.h for option slim
#ifdef __MMI_FWUI_SLIM__
    #ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
    #define __MMI_CATEGORY_NOTIFICATION_SLIM__ 
    #endif
#endif

#if defined(__MMI_MAINLCD_128X128__)
#define CAT154_IMAGE_Y 53
#elif defined(__MMI_MAINLCD_128X160__)
#define CAT154_IMAGE_Y 60
#elif defined(__MMI_MAINLCD_176X220__)
#define CAT154_IMAGE_Y 65
#elif defined(__MMI_MAINLCD_240X320__)
#define CAT154_IMAGE_Y 97
#elif defined(__MMI_MAINLCD_320X240__)
#define CAT154_IMAGE_Y 84
#elif defined(__MMI_MAINLCD_240X400__)
#define CAT154_IMAGE_Y 140
#elif defined(__MMI_MAINLCD_320X480__)
#define CAT154_IMAGE_Y 153
#else
#define CAT154_IMAGE_Y 50
#endif
 /*****************************************************************************
  * FUNCTION
  *  ShowCategory154Screen
  * DESCRIPTION
  *  Displays the Message Received screen
  *
  *  <img name="wgui_cat154_img1" />
  * PARAMETERS
  *  title                   : [IN]<TITLE />        Title for the screen
  *  title_icon              : [IN]<N/A />        Icon shown with the title
  *  left_softkey            : [IN]<LSK />        Left softkey label
  *  left_softkey_icon       : [IN]<N/A />        Icon for the left softkey
  *  right_softkey           : [IN]<RSK />        Right softkey label
  *  right_softkey_icon      : [IN]<N/A />        Icon for the right softkey
  *  message1                : [IN]<C154_1 />        Notification message 1
  *  message2                : [IN]<C154_2 />        Notification message 2
  *  message_icon            : [IN]<N/A />        Image to show
  *  history_buffer          : [IN]<N/A />        History buffer
  * RETURNS
  *  void
  * EXAMPLE
  * <code>
  * void EntryScreen_154(void)
  * {
  *
  *   U8 *guiBuffer = NULL;
  *
  *   EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
  *
  *   ShowCategory154Screen(
  *       0,
  *       0,
  *       STR_ID_CSB_LSK_TEXT,
  *       0,
  *       STR_ID_CSB_RSK_TEXT,
  *       0,
  *       (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
  *       (U8*) GetString(STR_ID_CSB_DUMMY_TEXT),
  *       IMG_ID_PHNSET_WP_3,
  *       guiBuffer);
  *
  *   csb_set_key_handlers();
  * }
  * </code>
  *****************************************************************************/
     extern void ShowCategory154Screen(
                     U16 title,
                     U16 title_icon,
                     U16 left_softkey,
                     U16 left_softkey_icon,
                     U16 right_softkey,
                     U16 right_softkey_icon,
                     U8 *message1,
                     U8 *message2,
                     U16 message_icon,
                     U8 *history_buffer);
     extern void ExitCategory154Screen(void);
     extern void RedrawCategory154Screen(void);
     extern void wgui_cat154_set_owner_draw_softkey(MMI_BOOL is_draw_softkey);
 /*****************************************************************************
  * FUNCTION
  *  ChangeCategory154Data
  * DESCRIPTION
  *  Change data of category154
  * PARAMETERS
  *   message1                      : [IN ] <C154_1 /> Data pointer of message1
  *   message2                      : [IN ] <C154_2 /> Data pointer of message2
  *   message_icon                  : [IN ] <N/A /> Id of message icon
  * RETURNS
  *  void
  *****************************************************************************/
     extern void ChangeCategory154Data(U8 *message1, U8 *message2, U16 message_icon);
#ifndef __MMI_CATEGORY_NOTIFICATION_SLIM__
     extern void Setcategory154LeftAlign(void);
#endif /*__MMI_CATEGORY_NOTIFICATION_SLIM__*/
 /*****************************************************************************
  * FUNCTION
  *  wgui_cat154_refresh
  * DESCRIPTION
  *  refresh category154 if message change
  * PARAMETERS
  *  void 
  * RETURNS
  *  void
  *****************************************************************************/
     extern void wgui_cat154_refresh(void);
//end: lhm remove from wgui_categories.h for option slim

 /*****************************************************************************
 * FUNCTION
 *  ShowCategory9Screen
 * DESCRIPTION
 *  It is a category screen to notify user someting happeen.
 * 
 * <img name="wgui_cat009_img1" />
 * PARAMETERS
 *   message                       : [IN ] (UNLIM) Message string
 *   message_icon                  : [IN ] (N/A) Message icon
 *   history_buffer                : [IN ] (N/A) History buffer
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * void EntryScreen_9(void)
 * {
 * 
 *     U8 *guiBuffer = NULL;
 * 
 *     EntryNewScreen(SCR_ID_CSB_DUMMY_SCR_ID, ExitScreen_Generic, EntryCSBStartView, NULL);
 * 
 *     ShowCategory2Screen(
 *         STR_ID_CSB_DUMMY_TEXT,
 *         IMG_ID_GLOBAL_PROGRESS,
 *         guiBuffer);
 * 
 *     csb_set_key_handlers();
 * }
 * </code>
 *****************************************************************************/
extern void ShowCategory9Screen(U16 message, U16 message_icon, U8 *history_buffer);

#endif

