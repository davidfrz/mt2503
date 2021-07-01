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

/***************************************************************************** 
* Include
*****************************************************************************/
#include "app_frm_message_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "app_frm_launcher_gprot.h"
#include "app_thread_mgr.h"
#include "app_frm_message.h"
#include "mmi_frm_queue_gprot.h"
#include "app_frm_utility_Gprot.h"


/***************************************************************************** 
* Define
*****************************************************************************/



/***************************************************************************** 
* Typedef 
*****************************************************************************/


/***************************************************************************** 
 * Variable 
 *****************************************************************************/
static APP_PROC mre_proc;

/***************************************************************************** 
* Function
*****************************************************************************/
extern void app_frm_register_mre_handler(
					APP_PROC	mre_handler_callback
					)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	mre_proc = mre_handler_callback;
	return;
}


extern void app_frm_send_msg_to_thread(
                    THREAD_HANDLE thread, 
                    U32 msg_id, 
                    void* user_data 
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	APP_THREAD_INFO* source_info;
	APP_THREAD_INFO* dest_info;	
	APP_EVENT_STRUCT* local_para_ptr;
	module_type      dest_mod_id;
	THREAD_HANDLE current_thread;
	APP_MAIN_EVENT_STRUCT* main_local_ptr;
	U32                msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	current_thread = app_frm_get_current_thread_handle();
	source_info = app_frm_get_thread_info(current_thread);
	dest_info = app_frm_get_thread_info(thread);
	msg = MSG_ID_APP_FRM_THREAD_MESSGAE_IND;
	if ((source_info != NULL) && (source_info->main_thread_hd == thread))
	{
		//send to main thread.
		main_local_ptr = mmi_construct_msg_local_para(sizeof(APP_MAIN_EVENT_STRUCT));
		main_local_ptr->message_id = msg_id;
		main_local_ptr->user_data = user_data;
		main_local_ptr->main_thread_hd = thread;
		if (source_info->thread_type == THREAD_TYPE_MRE)
		{
			msg = MSG_ID_APP_FRM_THREAD_MRE_MESSGAE_IND;
		}
	    app_frm_send_msg_int(
	                MOD_MMI, 
	                msg, 
	                (local_para_struct *)main_local_ptr, 
	                NULL);		
		return;
	}

	if (dest_info == NULL)
	{
		// receiver thread handler is ivalid.
		return;
	}
	dest_mod_id = (module_type)dest_info->mod_id;
	local_para_ptr = mmi_construct_msg_local_para(sizeof(APP_EVENT_STRUCT));
    local_para_ptr->message_id = msg_id;
    local_para_ptr->user_data = user_data;
    app_frm_send_msg_int(
                dest_mod_id, 
                msg, 
                (local_para_struct *)local_para_ptr, 
                NULL);
}

extern void app_frm_main_task_init_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	SetProtocolEventHandler(app_frm_main_msg_hdlr, MSG_ID_APP_FRM_THREAD_MESSGAE_IND);
	SetProtocolEventHandler(app_frm_main_mre_msg_hdlr, MSG_ID_APP_FRM_THREAD_MRE_MESSGAE_IND);
	
}

extern U8 app_frm_main_mre_msg_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	APP_MAIN_EVENT_STRUCT* local_para_ptr;
	APP_THREAD_INFO* info;
	APP_EVENT_STRUCT evt;
	THREAD_HANDLE hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_para_ptr = (APP_MAIN_EVENT_STRUCT*)inMsg;
	evt.message_id = local_para_ptr->message_id;
	evt.user_data = local_para_ptr->user_data;
	hd = local_para_ptr->main_thread_hd;
	if (mre_proc != NULL)
	{
		//send to MRE engineer.
		mre_proc(hd, &evt);
	}
	return 0;		
}

extern U8 app_frm_main_msg_hdlr(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	APP_MAIN_EVENT_STRUCT* local_para_ptr;
	APP_THREAD_INFO* info;
	APP_EVENT_STRUCT evt;
	THREAD_HANDLE hd;
	APP_PROC proc;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	local_para_ptr = (APP_MAIN_EVENT_STRUCT*)inMsg;
	evt.message_id = local_para_ptr->message_id;
	evt.user_data = local_para_ptr->user_data;
	hd = local_para_ptr->main_thread_hd;
	info = app_frm_get_thread_info(hd);
	ASSERT(info != NULL);
	proc = info->app_main_proc;
	ASSERT(proc);
	proc(hd, &evt);
	return 0;		
}

extern void app_frm_get_thread_message( 
                    ilm_struct* ilm
                    )
{
	msg_receive_extq(ilm);
}
