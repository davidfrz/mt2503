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
 *  
 *
 * Project:
 * -------- 
 *  IOT
 *
 * Description:
 * ------------
 * 
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef APP_FRM_APP_MESSAGE_H
#define APP_FRM_APP_MESSAGE_H
#ifdef __MULTI_THREAD_SUPPORT__
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
* Include
*****************************************************************************/
#include "app_frm_thread_gprot.h"
#include "app_frm_launcher_gprot.h"
#include "app_frm_message_gprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/

typedef struct
{
	LOCAL_PARA_HDR
	U16 message_id;                       //message id
	THREAD_HANDLE   main_thread_hd;
	void* user_data;                      // user data pointer
} APP_MAIN_EVENT_STRUCT;

/***************************************************************************** 
* Typedef 
*****************************************************************************/


/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *	app_frm_main_task_init_int
 * DESCRIPTION
 *	internal used, invoke when main task initialization.
 * PARAMETERS
 *   N/A
 * RETURNS
 *	N/A
 *****************************************************************************/
extern void app_frm_main_task_init_int(void);

/*****************************************************************************
 * FUNCTION
 *	app_frm_main_msg_hdlr
 * DESCRIPTION
 *	used for dispatch the msg to native main thread.
 * PARAMETERS
 *   inMsg:             [IN]  Msg data.
 * RETURNS
 *   0
 *****************************************************************************/
extern U8 app_frm_main_msg_hdlr(void *inMsg);

/*****************************************************************************
 * FUNCTION
 *	app_frm_main_mre_msg_hdlr
 * DESCRIPTION
 *	used for dispatch the msg to mre app thread.
 * PARAMETERS
 *   inMsg:             [IN]  Msg data.
 * RETURNS
 *   0
 *****************************************************************************/
extern U8 app_frm_main_mre_msg_hdlr(void *inMsg);

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif //__MULTI_THREAD_SUPPORT__
#endif // APP_FRM_APP_MESSAGE_H

