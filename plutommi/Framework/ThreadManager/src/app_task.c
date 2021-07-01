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
 *  ThreadMgr.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



/*************************************************************************
* Include Statements
*************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "kal_general_types.h"
#include "app_thread_mgr.h"

/***************************************************************************** 
* Declear
*****************************************************************************/
MMI_BOOL app_relay_Init(task_indx_type task_indx);
void app_relay_task_main(task_entry_struct *entry_param);
MMI_BOOL app_task_Init(task_indx_type task_indx);
void app_task_main(task_entry_struct *entry_param);
extern U32 app_frm_msg_signal_handler(ilm_struct *ilm);

/***************************************************************************** 
 * Global Function
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *	app_relay_create
 * DESCRIPTION
 *	MMI task create function for system service.
 * PARAMETERS
 *	handle		[OUT]			 
 * RETURNS
 *	The result is ok or not.
 *****************************************************************************/
kal_bool app_relay_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    static comptask_handler_struct mmi_handler_info = 
    {
        app_relay_task_main,     /* task entry function */
        app_relay_Init,          /* task initialization function */
        NULL, 
        NULL,                    /* task reset handler */
        NULL,                    /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    *handle = &mmi_handler_info;
    return KAL_TRUE;

}

/*****************************************************************************
 * FUNCTION
 *  app_relay_task_main
 * DESCRIPTION
 *  Entry function for Protocol task
 *  
 *  This receives protocol task events from the stack and forwards it to
 *  MMI task.
 * PARAMETERS
 *  entry_param     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void app_relay_task_main(task_entry_struct *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	ilm_struct ilm;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	msg_receive_extq(&ilm);
	if (app_frm_msg_signal_handler(&ilm))
	{
		return;
	}
	else
	{
		ilm.sap_id = 0;
	    ilm.dest_mod_id = MOD_MMI;
		msg_send(&ilm);
	}
}

/*****************************************************************************
 * FUNCTION
 *  app_relay_Init
 * DESCRIPTION
 *  MMI Init Function
 * PARAMETERS
 *  task_indx       [IN]        Index of task
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL app_relay_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *	app_task_create
 * DESCRIPTION
 *	MMI task create function for system service.
 * PARAMETERS
 *	handle		[OUT]			 
 * RETURNS
 *	The result is ok or not.
 *****************************************************************************/
kal_bool app_task_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    static comptask_handler_struct mmi_handler_info = 
    {
        app_task_main,     /* task entry function */
        app_task_Init,     /* task initialization function */
        NULL, 
        NULL,              /* task reset handler */
        NULL,              /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    *handle = &mmi_handler_info;
    return KAL_TRUE;
	
}

/*****************************************************************************
 * FUNCTION
 *  app_relay_Init
 * DESCRIPTION
 *  MMI Init Function
 * PARAMETERS
 *  task_indx       [IN]        Index of task
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL app_task_Init(task_indx_type task_indx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  app_task_main
 * DESCRIPTION
 *  Entry function for Protocol task
 *  
 *  This receives protocol task events from the stack and forwards it to
 *  MMI task.
 * PARAMETERS
 *  entry_param     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void app_task_main(task_entry_struct *entry_param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	ilm_struct ilm;
	APP_THREAD_CREATE_PARAM_STRUCT* create_para_ptr;
	APP_THREAD_INFO* info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	while (1)
	{
		//todo: get ilm, receive create msg, fill task index,
		msg_receive_extq(&ilm);
		if (ilm.msg_id == MSG_ID_APP_FRM_THREAD_CREATE_IND)
		{
			create_para_ptr = (APP_THREAD_CREATE_PARAM_STRUCT*)ilm.local_para_ptr;
			info = app_frm_get_thread_info(create_para_ptr->thread_handle);
			if(info->thread_function)
			{				
				kal_set_active_module_id((module_type)info->mod_id);
				info->thread_function(create_para_ptr->thread_handle, create_para_ptr->data);
			}
			//todo release the handle;
			app_frm_release_thread_int(create_para_ptr->thread_handle);
		}
		free_ilm(&ilm);
	}
}

