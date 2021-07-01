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
 *  app_thread_mutex.c
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
#include "app_thread_mutex_gprot.h"
#include "mmi_frm_remutex_gprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
#define APP_FRM_MUTEX_MAX 20
#define APP_FRM_MUEXT_LOCK        mmi_frm_recursive_mutex_lock(&g_app_mutex)
#define APP_FRM_MUEXT_UNLOCK      mmi_frm_recursive_mutex_unlock(&g_app_mutex)
/***************************************************************************** 
 * Variable
 *****************************************************************************/
static mutex_list_note* g_mutex_free_list;
static mutex_list_note g_mutex_array[APP_FRM_MUTEX_MAX];
static mmi_frm_recursive_mutex_struct g_app_mutex;

/***************************************************************************** 
 * Function
 *****************************************************************************/

extern void app_frm_mutex_init_int(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(i = 1; i < APP_FRM_MUTEX_MAX; i++)
	{
		g_mutex_array[i].mutexID= kal_create_mutex("app_frm");
		g_mutex_array[i - 1].next= &g_mutex_array[i];
	}
	g_mutex_free_list = g_mutex_array;
	g_mutex_free_list->mutexID= kal_create_mutex("app_frm");
	mmi_frm_recursive_mutex_init(&g_app_mutex, "APP_FRM_MUTEX");
	return;
}

extern void app_frm_mutex_create(app_frm_mutex_struct *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 var;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	var = (U32)mutex;
	mutex->mutex_info = NULL;
	mutex->guard = (var)^('FRMW');
}

extern void app_frm_mutex_lock(app_frm_mutex_struct *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 var;
	kal_taskid taskID;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(mutex != NULL);
	var = (mutex->guard) ^ ('FRMW');
	//do not copy mutex struct.
	ASSERT(var == (U32)mutex);	
	taskID = kal_get_current_task();
	APP_FRM_MUEXT_LOCK;
	if (mutex->mutex_info == NULL)
	{		
		ASSERT(g_mutex_free_list != NULL); //no more mutex to use.
		mutex->mutex_info = g_mutex_free_list;
		g_mutex_free_list = g_mutex_free_list->next;
		
        kal_take_mutex(mutex->mutex_info->mutexID);
        mutex->mutex_info->ref_count = 1;
        mutex->mutex_info->taskID = taskID;
		APP_FRM_MUEXT_UNLOCK;
    }
    else if(mutex->mutex_info->taskID == taskID)
    {   
        ASSERT((mutex->mutex_info->ref_count >= 1) && (mutex->mutex_info->ref_count < 255));// logic error.
        mutex->mutex_info->ref_count++;
		APP_FRM_MUEXT_UNLOCK;
    }
	else
	{
		APP_FRM_MUEXT_UNLOCK;
        kal_take_mutex(mutex->mutex_info->mutexID);
		// only one task can ready from here. needn't lock again.
		ASSERT(mutex->mutex_info->ref_count == 0);
		mutex->mutex_info->ref_count = 1;
        mutex->mutex_info->taskID = taskID;
	}	
}

extern void app_frm_mutex_unlock(app_frm_mutex_struct *mutex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	kal_taskid taskID;
	U32 var;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	ASSERT(mutex != NULL);
	var = (mutex->guard) ^ ('FRMW');
	//do not copy mutex struct.
	ASSERT(var == (U32)mutex);	
	taskID = kal_get_current_task();
	ASSERT (mutex && (mutex->mutex_info != NULL) && (taskID == mutex->mutex_info->taskID));
	APP_FRM_MUEXT_LOCK;
	if (mutex->mutex_info->ref_count > 1)
	{
		mutex->mutex_info->ref_count--;
	}
	else
	{
		mutex->mutex_info->ref_count--;
		mutex->mutex_info->taskID = NULL;
		kal_mutex_waiting_count(mutex->mutex_info->mutexID, &var);
		if (var == 0)
		{
			// free mutex.
			mutex->mutex_info->next = g_mutex_free_list;
			g_mutex_free_list = mutex->mutex_info;
			kal_give_mutex(mutex->mutex_info->mutexID);
			mutex->mutex_info = NULL;
		}
		else
		{
			kal_give_mutex(mutex->mutex_info->mutexID);
		}
	}
	APP_FRM_MUEXT_UNLOCK;
}

