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

#ifndef APP_FRM_MESSAGE_GPROT_H
#define APP_FRM_MESSAGE_GPROT_H
#ifdef __MULTI_THREAD_SUPPORT__
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
* Include
*****************************************************************************/
#include "app_frm_thread_gprot.h"

/***************************************************************************** 
* Define
*****************************************************************************/


/***************************************************************************** 
* Typedef 
*****************************************************************************/
typedef struct
{
	LOCAL_PARA_HDR
	U16 message_id; 					  //message id
	void* user_data;					  // user data pointer
} APP_EVENT_STRUCT;

typedef S32 (*APP_PROC)(THREAD_HANDLE main_thread_handle, APP_EVENT_STRUCT *evt);


/***************************************************************************** 
* Function
*****************************************************************************/
	
/*****************************************************************************
 * FUNCTION
 *	app_frm_register_mre_handler
 * DESCRIPTION
 *	register MRE engineer call back function. and all the message send to the main thread of MRE
 *   application will invoke the call back with MRE vm handle.
 * PARAMETERS
 *	mre_handler_callback   [IN]  MRE engineer event handler.
 * RETURNS
 *	void.
 *
 * Example code:
 *
 * mre_engineer_init()
 * {
 *        // regist the call back when mre initialize.
 * 	    app_frm_register_mre_handler(
 * 					mre_engineer_main
 * 					);
 * }
 * 
 * S32 mre_engineer_main(THREAD_HANDLE mre_vm_handle, APP_EVENT_STRUCT*  evt)
 * {
 * 	   U16 m_id;
 * 	   m_id = evt->message_id;
 * 	   //handle the message and dispatch to mre_vm_handle.
 * 	   mre_handle_msg(mre_vm_handle, m_id, evt->user_data);
 * 	   return 0;
 * }
 *  
 *****************************************************************************/
extern void app_frm_register_mre_handler(
					APP_PROC	mre_handler_callback
					);


/*****************************************************************************
 * FUNCTION
 *  app_frm_send_msg_to_thread
 * DESCRIPTION
 *  used for sending msg between threads.
 * PARAMETERS
 *  thread         [IN]       The thread handler of reciever.
 *  msg_id        [IN]       The message id to be send.
 *  user_data    [IN]       The customer data of the message.
 * RETURNS
 *  None.
 *
 * Example code:
 * S32 sub_thread_proc(THREAD_HANDLE thread_handle, void* user_data)
 * {
 *    THREAD_HANDLE main_handle;
 * 	do_some_thing();
 *    main_handle = app_frm_get_main_thread_handle();
 * 	app_frm_send_msg_to_thread(main_handle, msg_xxx_id, NULL);
 * 	return 0;
 * }
 *****************************************************************************/
extern void app_frm_send_msg_to_thread(
                    THREAD_HANDLE thread, 
                    U32 msg_id, 
                    void* user_data
                    );

/*****************************************************************************
 * FUNCTION
 *  app_frm_get_thread_message
 * DESCRIPTION
 *  used for read msg from ext msg queue, and it will be blocked if the queue is empty. only can be
 *  used in sub thread. for main thread please referent app_frm_register_mre_handler() or
 *  app_frm_launch_app() 
 * PARAMETERS
 *  ilm                         [OUT]    The msg content.
 * RETURNS
 *  None 
 *
 * Example code:
 * S32 sub_thread_proc(THREAD_HANDLE thread_handle, void* user_data)
 * {
 * 	 ilm_struct ilm;
 * 	 U16 len;
 * 	 APP_EVENT_STRUCT* evt;
 * 	 app_frm_get_thread_message(
 * 					 &ilm
 * 					 );
 *     if (ilm.msg_id == MSG_ID_APP_FRM_THREAD_MESSGAE_IND)
 *     {
 * 	      evt = (APP_EVENT_STRUCT*) get_local_para_ptr(
 * 								 ilm.local_para_ptr, 
 * 								 &len
 * 								 );
 * 	      switch (evt->message_id)
 * 	      {
 * 		     case MSG_xxx_ID:
 * 			     do_some_thing();
 * 			     break;
 * 		     default:
 * 		           break;
 * 	      }
 *     }
 * 	 return 0;
 * }
 *****************************************************************************/
extern void app_frm_get_thread_message(
                    ilm_struct* ilm
                    );

#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif //__MULTI_THREAD_SUPPORT__
#endif // APP_FRM_MESSAGE_GPROT_H

