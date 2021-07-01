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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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

#ifndef APP_FRM_THREAD_GPROT_H
#define APP_FRM_THREAD_GPROT_H
#ifdef __MULTI_THREAD_SUPPORT__
#ifdef __cplusplus
extern "C"
{
#endif

/***************************************************************************** 
* Include
*****************************************************************************/	
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "MMIDataType.h"




/***************************************************************************** 
* Define
*****************************************************************************/
#define THREAD_HANDLE  U32
#define SIGNAL_ID      U32
#define THREAD_TYPE_NONE           0
#define THREAD_TYPE_NATIVE         1
#define THREAD_TYPE_MRE            2
#define SIGNAL_RESULT_SUCCESS      0
#define SIGNAL_RESULT_TIMEOUT      1
#define SIGNAL_RESULT_CANCEL       2

/***************************************************************************** 
* Typedef 
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  THREAD_FUNC
 * DESCRIPTION
 *  Thread main function type, and the thread will be closed when it returned.
 * PARAMETERS
 *  thread_handle         [IN]       The thread handler, used for thread management
 *  user_data               [IN]       The create param transfer to main function.
 * RETURNS
 *  return 
 *****************************************************************************/
typedef S32 (*THREAD_FUNC)(
            THREAD_HANDLE thread_handle, 
            void* user_data);


/***************************************************************************** 
* Function
*****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  app_frm_create_thread
 * DESCRIPTION
 *  used for create a thread.
 * PARAMETERS
 *  thread_function   [IN]   The thread main function.
 *  user_data           [IN]   The param of thread_function.
 *  priority               [IN]   Thread priority, 
 *                                    1 is the highest priority, 255 is the lowest priority, and MMI task's priority 
 *                                    is higher than 129 and lower than 128. 0 is default priority lower than MMI task.
 *  type                   [IN]   THREAD_TYPE_MRE or THREAD_TYPE_NATIVE.   
 *  main_handle        [IN]   the main thread handle, see app_frm_get_main_thread_handle(). 
 * RETURNS
 *  return The handle of the creating thread.
 *
 * Example code:
 * S32 hello_world_proc(THREAD_HANDLE main_handler, APP_EVENT_STRUCT*evt)
 * {
 * 	switch (evt->message_id)
 * 	{
 * 		case APPLICATION_START:			
 * 			app_frm_create_thread(sub_thread_proc, 
 *                                                   NULL, 
 *                                                   0, 
 *                                                   THREAD_TYPE_NATIVE,
 *                                                   main_handler
 *                                                   );
 * 			break;
 * 		case APPLICATION_STOP:
 * 			break;
 * 		}
 * 	}
 * 	return 0;
 * }
 *
 * S32 sub_thread_proc(THREAD_HANDLE thread_handle, void* user_data)
 * {
 * 	 do_some_thing();
 * 	 return 0;
 * }
 *****************************************************************************/
extern THREAD_HANDLE app_frm_create_thread(
                    THREAD_FUNC           thread_function, 
                    void*                 data,
                    U8 			 		  priority,
					U8                    type,
					THREAD_HANDLE         main_handle
                    );

/*****************************************************************************
 * FUNCTION
 *  app_frm_get_current_mod_id
 * DESCRIPTION
 *  used for get MOD id.
 * PARAMETERS
 *  None
 * RETURNS
 *  return  MOD id.
 *****************************************************************************/
extern U16 app_frm_get_current_mod_id(void);

/*****************************************************************************
 * FUNCTION
 *  app_frm_get_current_thread_handle
 * DESCRIPTION
 *  used for get thread handle. this API does not support in main task.
 * PARAMETERS
 *  None
 * RETURNS
 *  return  The handle of current thread.
 *****************************************************************************/
extern THREAD_HANDLE app_frm_get_current_thread_handle(void);

/*****************************************************************************
 * FUNCTION
 *  app_frm_get_main_thread_handle
 * DESCRIPTION
 *  used for get main thread handle.
 *  For native application, it must invoke app_frm_set_main_thread_handle first.
 * PARAMETERS
 *  None
 * RETURNS
 *  return  The handle of main thread.
 *****************************************************************************/
extern THREAD_HANDLE app_frm_get_main_thread_handle(void);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_init
 * DESCRIPTION
 *  Initial a signal for thread communication.
 * PARAMETERS
 *  None
 * RETURNS
 *  The signal id of create.
 *
 * Example code:
 * S32 hello_world_proc(THREAD_HANDLE main_handler, 
 *						 APP_EVENT_STRUCT*evt)
 * {
 *	 THREAD_HANDLE sub_handle;
 *	 SIGNAL_ID s_id;
 *	 switch (evt->message_id)
 *	 {
 *		 case APPLICATION_START: 
 *			 //create signal.
 *			 s_id = app_frm_signal_init();
 * 			app_frm_create_thread(thread_function, 
 *                                                   (void*)s_id, 
 *                                                   THREAD_PRIORITY_LOW, 
 *                                                   THREAD_TYPE_NATIVE,
 *                                                   main_handler
 *                                                   );

 *			 break;
 *		 case APPLICATION_STOP:
 * 			 //release signal.
 *			 app_frm_signal_deinit(s_id);
 *			 break;
 *		 case MSG_xxx_ID:
 *			 handle_xxx_msg();
 *			 //post signal
 *			 app_frm_signal_post(s_id);
 *			 break;
 *		 }
 *	 }
 *	 return 0;
 * }
 *
 * S32 thread_function(
 *			 THREAD_HANDLE thread_handle, 
 *			 void* user_data)
 * {
 *	 APP_EVENT_STRUCT* evt;
 *	 SIGNAL_ID s_id = (SIGNAL_ID)user_data;
 *	 do_some_thing();
 *
 *	 // wait main thread handle MSG_xxx_ID.
 *	 app_frm_signal_wait(s_id);
 *	 do_other_thing();
 *	 return 0;
 * }
 *****************************************************************************/
extern SIGNAL_ID app_frm_signal_init(void);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_clean
 * DESCRIPTION
 *  The id of the signal which was clean.
 * PARAMETERS
 *  None
 * RETURNS
 *  The signal id of create.
 *****************************************************************************/
extern void app_frm_signal_clean(SIGNAL_ID s_id);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_post
 * DESCRIPTION
 *  post a signal then the thread, which is waiting for it, will be waken up. 
 *  the signal id is get from app_frm_signal_init(void)
 * PARAMETERS
 *  s_id:             [IN] The id of the signal which was post.
 * RETURNS
 *  None.
 *****************************************************************************/
extern void app_frm_signal_post(SIGNAL_ID s_id);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_wait
 * DESCRIPTION
 *  wait a signal then the thread will getting blocking if the signal was not set. 
 *  then it will geting wake up when other thread post the signal.
 *  and this API only support in sub-thread, it can't be invoke from main task.
 * PARAMETERS
 *  s_id:             [IN] the waiting for signal id.
 * RETURNS
 *  return SIGNAL_RESULT_SUCCESS, if it is wake up by the signal.
 *  return SIGNAL_RESULT_CANCEL, if it is wake up forcely without the signal.
 *****************************************************************************/
extern S32 app_frm_signal_wait(SIGNAL_ID s_id);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_wait
 * DESCRIPTION
 *  wait a signal then the thread will getting blocking if the signal was not set. 
 *  then it will geting wake up when other thread post the signal.
 *  and this API only support in sub-thread, it can't be invoke from main task.
 * PARAMETERS
 *  s_id:             [IN] the waiting for signal id.
 *  time_count:   [IN] the max time to wait..(microsecond)
 * RETURNS
 *  return SIGNAL_RESULT_SUCCESS, if it is wake up by the signal.
 *  return SIGNAL_RESULT_TIMEOUT, if time out.
 *  return SIGNAL_RESULT_CANCEL, if it is wake up forcely without the signal.
 *****************************************************************************/
extern S32 app_frm_signal_timedwait(SIGNAL_ID s_id, U32 time_count);

/*****************************************************************************
 * FUNCTION
 *  app_frm_signal_deinit
 * DESCRIPTION
 *  destory a signal when app will not use it any more.
 * PARAMETERS
 *  s_id:             [IN] the signal id of deinit.
 * RETURNS
 *  None
 *****************************************************************************/
extern void app_frm_signal_deinit(SIGNAL_ID s_id);
#ifdef __cplusplus
}   /* extern "C" */
#endif

#endif // __MULTI_THREAD_SUPPORT__
#endif // APP_FRM_THREAD_GPROT_H

