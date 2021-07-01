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
 *  app_thread_mutex_gprot.h
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef APP_THREAD_MUTEXT_GPROT_H
#define APP_THREAD_MUTEXT_GPROT_H

#ifdef __cplusplus
extern "C"
{
#endif
/*************************************************************************
  * Include Statements
  *************************************************************************/
#include "MMIDataType.h"
#include "kal_public_defs.h"
#include "kal_general_types.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
typedef struct _mutex_list_note
{
	kal_mutexid mutexID;
	kal_taskid taskID;	/* Reference count */
	U8 ref_count;
	struct _mutex_list_note *next;	 
} mutex_list_note;

typedef struct
{
	U32 guard;
	/* Mutex info */
	mutex_list_note* mutex_info;
} app_frm_mutex_struct;


/***************************************************************************** 
 * Function
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *	app_frm_mutex_create
 * DESCRIPTION
 *	Recursive mutex intialize. 
 * PARAMETERS
 *	mutex		  : [OUT]		the mutex that needs to create.
 * RETURNS
 *	void
 * Sample code:
 * static app_frm_mutex_struct my_mutex;
 * S32 sub_thread_one(THREAD_HANDLE thread_handle, void* user_data)
 * {
 *      app_frm_mutex_create(&my_mutex);
 *      app_frm_mutex_lock(&my_mutex);
 *      //access global data;
 *      change_global_data();
 *      app_frm_mutex_unlock(&my_mutex);
 *  }
 *
 * S32 sub_thread_one(THREAD_HANDLE thread_handle, void* user_data)
 * {
 *      do_some_thing();
 *      app_frm_mutex_lock(&my_mutex);
 *      //access global data;
 *      change_global_data();
 *      app_frm_mutex_unlock(&my_mutex);
 *  } 
 *****************************************************************************/
extern void app_frm_mutex_create(app_frm_mutex_struct *mutex);

/*****************************************************************************
 * FUNCTION
 *	app_frm_mutex_lock
 * DESCRIPTION
 *	get the mutex. after the mutex be locked by one task, then the task lock it again, the task will 
 *     not goto suspend, and lock must pair with unlock.
 *     becareful using it in main thread, do not blocking main thread to long. 
 * PARAMETERS
 *	mutex : [IN] The mutex
 * RETURNS
 *	void
 *****************************************************************************/
extern void app_frm_mutex_lock(app_frm_mutex_struct *mutex);

/*****************************************************************************
 * FUNCTION
 *	app_frm_mutex_unlock
 * DESCRIPTION
 *	release the mutex.
 * PARAMETERS
 *	mutex  : [IN] The mutex
 * RETURNS
 *	void
 *****************************************************************************/
extern void app_frm_mutex_unlock(app_frm_mutex_struct *mutex);

	
	
#ifdef __cplusplus
	}	/* extern "C" */
#endif

#endif // APP_THREAD_MUTEXT_GPROT_H

