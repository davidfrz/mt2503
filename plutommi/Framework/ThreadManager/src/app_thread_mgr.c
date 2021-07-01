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



/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_release.h"
#include "stack_types.h"
#include "syscomp_config.h"
#include "mmi_frm_gprot.h"
#include "mmi_frm_prot.h"
#include "mmi_frm_remutex_gprot.h"
#include "QueueGprot_Int.h"
#include "app_frm_thread_gprot.h"
#include "app_thread_mgr.h"
#include "app_frm_utility_Gprot.h"
#include "app_frm_message.h"


/***************************************************************************** 
 * Define
 *****************************************************************************/
#define APP_TASK_COUNT_MAX           10
#define APP_THREAD_COUNT_MAX         32
#define THREAD_ACCESS_LOCK           mmi_frm_recursive_mutex_lock(&app_thread_rmutex)
#define THREAD_ACCESS_UNLOCK         mmi_frm_recursive_mutex_unlock(&app_thread_rmutex)


typedef struct
{
    U32                   task_busy_mask;
    APP_THREAD_INFO      thread_arr[APP_THREAD_COUNT_MAX];
    U8                    valid_index;
} APP_MULTI_THREAD_STRUCT;

/***************************************************************************** 
 * Global variable
 *****************************************************************************/
static APP_MULTI_THREAD_STRUCT app_frm_thread_cntx;
const static MMI_ID app_mod_g[APP_TASK_COUNT_MAX] = 
{
    MOD_APP_THREAD1, 
    MOD_APP_THREAD2, 
    MOD_APP_THREAD3, 
    MOD_APP_THREAD4, 
    MOD_APP_THREAD5, 
    MOD_APP_THREAD6, 
    MOD_APP_THREAD7, 
    MOD_APP_THREAD8, 
    MOD_APP_THREAD9, 
    MOD_APP_THREAD10
};
static mmi_frm_recursive_mutex_struct  app_thread_rmutex;

const static U8 app_priority_g[APP_TASK_COUNT_MAX*2] = 
{
    TASK_PRIORITY_APP_HIGH1, 
    TASK_PRIORITY_APP_HIGH2, 
    TASK_PRIORITY_APP_HIGH3, 
    TASK_PRIORITY_APP_HIGH4, 
    TASK_PRIORITY_APP_HIGH5, 
    TASK_PRIORITY_APP_HIGH6, 
    TASK_PRIORITY_APP_HIGH7, 
    TASK_PRIORITY_APP_HIGH8, 
    TASK_PRIORITY_APP_HIGH9, 
    TASK_PRIORITY_APP_HIGH10, 
    TASK_PRIORITY_APP_LOW1, 
    TASK_PRIORITY_APP_LOW2, 
    TASK_PRIORITY_APP_LOW3, 
    TASK_PRIORITY_APP_LOW4, 
    TASK_PRIORITY_APP_LOW5, 
    TASK_PRIORITY_APP_LOW6, 
    TASK_PRIORITY_APP_LOW7, 
    TASK_PRIORITY_APP_LOW8, 
    TASK_PRIORITY_APP_LOW9, 
    TASK_PRIORITY_APP_LOW10
};
typedef struct
{
	kal_taskid task_id;
	U8         task_priority;
} APP_PRIORITY_STRUCT;

APP_PRIORITY_STRUCT app_task_priority_map[APP_TASK_COUNT_MAX*2];


/***************************************************************************** 
 * Function
 *****************************************************************************/
static void app_frm_assign_priority_int(kal_taskid task_id, U8 priority);
extern void app_frm_mutex_init_int(void);
extern void app_frm_signal_bootup_init(void);

extern void app_frm_thread_init(void)
{
    mmi_frm_recursive_mutex_init(&app_thread_rmutex, "APP_FRM_THREAD");
	app_frm_main_task_init_int();
	app_frm_mutex_init_int();
	app_frm_signal_bootup_init();
}

extern APP_THREAD_INFO* app_frm_get_thread_info(THREAD_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	APP_THREAD_INFO* info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (hd == 0)
		return NULL;
	info = &(app_frm_thread_cntx.thread_arr[hd&0xFFFF]);
	if ((info->valid_index == ((hd >> 16) & 0xFF)) && (info->mod_id != 0))
	{
		return info;
	}
	else
	{	
		// mre vm_handler.
    	return NULL;
	}
}

extern void app_frm_release_thread_int(THREAD_HANDLE hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    APP_THREAD_INFO* info;
	U32              i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    THREAD_ACCESS_LOCK;
    info = app_frm_get_thread_info(hd);

    app_frm_thread_cntx.task_busy_mask &= ~(0x1<<(info->mod_index));
    memset(info, 0, sizeof(APP_THREAD_INFO));
	for(i = 0; i < APP_TASK_COUNT_MAX*2; i++)
	{
		if (app_task_priority_map[i].task_id == info->task_id)
		{
			app_task_priority_map[i].task_id = 0;
			app_task_priority_map[i].task_priority = 0;
			break;
		}
	}
    THREAD_ACCESS_UNLOCK;
    return;
}


extern THREAD_HANDLE app_frm_create_thread(
                    THREAD_FUNC           thread_function, 
                    void*                  data, 
                    U8					  priority, 
                    U8                      type, 
                    THREAD_HANDLE          main_handle
                    )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           sub_hd;
    U32                     empty_index;
    U32                     i;
    U32                     busy_mask;
    APP_THREAD_INFO*        thread_info;
    APP_THREAD_CREATE_PARAM_STRUCT* local_para_ptr;
	kal_taskid 				task_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (thread_function == NULL)
    {
        kal_prompt_trace(MOD_NIL, "[THREAD] thread enter function invalid");
        return 0;
    }
    THREAD_ACCESS_LOCK;
    busy_mask = app_frm_thread_cntx.task_busy_mask;
    //get an empty task
    for (empty_index = 0; empty_index < APP_TASK_COUNT_MAX; empty_index++)
    {
        if ((busy_mask & (0x1<<empty_index)) == 0)
        {
            break;
        }
    }
    if (empty_index >= APP_TASK_COUNT_MAX)
    {
        THREAD_ACCESS_UNLOCK;
        //no empty task.
        kal_prompt_trace(MOD_NIL, "[THREAD] no empty task");
        return 0;
    }
    //take the task.
    app_frm_thread_cntx.task_busy_mask |= (0x1<<empty_index);

    //get an empty thread info
    for(i = 0; i< APP_THREAD_COUNT_MAX; i++)
    {
        if (app_frm_thread_cntx.thread_arr[i].mod_id == 0)
        {
            break;
        }
    }
    if (i >= APP_THREAD_COUNT_MAX)
    {
        THREAD_ACCESS_UNLOCK;
        kal_prompt_trace(MOD_NIL, "[THREAD] no empty thread info");
        return 0;
    }

    thread_info = &(app_frm_thread_cntx.thread_arr[i]);

    task_id = kal_get_task_by_index(
					kal_map_module_to_task_index((module_type)app_mod_g[empty_index])
					);
    thread_info->task_id = task_id;
    thread_info->main_thread_hd = main_handle;
    thread_info->mod_id = app_mod_g[empty_index];
    thread_info->thread_function = thread_function;
    thread_info->thread_type = type;
    thread_info->valid_index = app_frm_thread_cntx.valid_index;
    thread_info->mod_index = (U8)empty_index;

    sub_hd = type;
    sub_hd = (sub_hd << 8) | app_frm_thread_cntx.valid_index;
    sub_hd = (sub_hd << 16) | i;
    app_frm_thread_cntx.valid_index++;
    THREAD_ACCESS_UNLOCK;
    local_para_ptr = mmi_construct_msg_local_para(sizeof(APP_THREAD_CREATE_PARAM_STRUCT));
    local_para_ptr->data = data;
    local_para_ptr->thread_handle = sub_hd;
    app_frm_assign_priority_int(task_id, priority);
    app_frm_send_msg_int(
                (module_type)app_mod_g[empty_index], 
                MSG_ID_APP_FRM_THREAD_CREATE_IND, 
                (local_para_struct *)local_para_ptr, 
                NULL);
    return sub_hd;
}

extern THREAD_HANDLE app_frm_add_main_thread(APP_PROC proc, void* param)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           hd;
    U32                     i;
    APP_THREAD_INFO*        thread_info;
	APP_EVENT_STRUCT        evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (proc == NULL)
    {
        kal_prompt_trace(MOD_NIL, "[THREAD] thread enter function invalid");
        return 0;
    }
    THREAD_ACCESS_LOCK;

    //get an empty thread info
    for(i = 0; i< APP_THREAD_COUNT_MAX; i++)
    {
        if (app_frm_thread_cntx.thread_arr[i].mod_id == 0)
        {
            break;
        }
    }
    if (i >= APP_THREAD_COUNT_MAX)
    {
        THREAD_ACCESS_UNLOCK;
        kal_prompt_trace(MOD_NIL, "[THREAD] no empty thread info");
        return 0;
    }

    thread_info = &(app_frm_thread_cntx.thread_arr[i]);

    thread_info->task_id = kal_get_current_task();
    thread_info->main_thread_hd = 0;
    thread_info->mod_id = MOD_MMI;
    thread_info->thread_function = NULL;
	thread_info->app_main_proc = proc;
    thread_info->thread_type = THREAD_TYPE_NATIVE;
    thread_info->valid_index = app_frm_thread_cntx.valid_index;
    thread_info->mod_index = 0;

    hd = THREAD_TYPE_NATIVE;
    hd = (hd << 8) | app_frm_thread_cntx.valid_index;
    hd = (hd << 16) | i;
    app_frm_thread_cntx.valid_index++;
    THREAD_ACCESS_UNLOCK;
	evt.message_id = APPLICATION_START;
	evt.user_data = param;
	proc(hd, &evt);
    return hd;
}

extern THREAD_HANDLE app_frm_remove_main_thread(THREAD_HANDLE handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    APP_THREAD_INFO*        info;
	APP_EVENT_STRUCT        evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	THREAD_ACCESS_LOCK;
	info = app_frm_get_thread_info(handle);
	if(info == NULL)
	{
		//invalid handle.
		THREAD_ACCESS_UNLOCK;
		return 0;		
	}
	ASSERT(info->app_main_proc != NULL);
	evt.message_id = APPLICATION_STOP;
	evt.user_data = NULL;
	(info->app_main_proc)(handle, &evt);
	memset(info, 0x00, sizeof(APP_THREAD_INFO));
	THREAD_ACCESS_UNLOCK;
	return handle;
}


extern U16 app_frm_get_current_mod_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           hd;
    U16                     mod_id = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    hd = app_frm_get_current_thread_handle();
    if (hd != 0)
    {
        mod_id = app_frm_thread_cntx.thread_arr[hd&0xFFFF].mod_id;
    }
    if (mod_id == 0)
    {
        mod_id = kal_get_active_module_id();
    }
    return mod_id;
}

extern THREAD_HANDLE app_frm_get_current_thread_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           hd;
    kal_taskid          	tid;
    U32                     i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    tid = kal_get_current_task();
    for (i = 0; i < APP_THREAD_COUNT_MAX; i++)
    {
        if (app_frm_thread_cntx.thread_arr[i].task_id == tid)
        {
            hd = app_frm_thread_cntx.thread_arr[i].thread_type;
            hd = (hd << 8) | app_frm_thread_cntx.thread_arr[i].valid_index;
            hd = (hd << 16) | i;
            return hd;
        }
    }
    return 0;
}

extern THREAD_HANDLE app_frm_get_thread_handle_by_mod(U16 mod_id)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           hd;
    U32                     i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (mod_id == MOD_MMI)
		return 0;
    for (i = 0; i < APP_THREAD_COUNT_MAX; i++)
    {
        if (app_frm_thread_cntx.thread_arr[i].mod_id == mod_id)
        {
            hd = app_frm_thread_cntx.thread_arr[i].thread_type;
            hd = (hd << 8) | app_frm_thread_cntx.thread_arr[i].valid_index;
            hd = (hd << 16) | i;
            return hd;
        }
    }
    return 0;

}

extern THREAD_HANDLE app_frm_get_main_thread_handle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    THREAD_HANDLE           hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    hd = app_frm_get_current_thread_handle();
    if (hd == 0)
        return 0;
    else
        return app_frm_thread_cntx.thread_arr[hd&0xFFFF].main_thread_hd;
}

static void app_frm_assign_priority_int(kal_taskid task_id, U8 priority)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_taskid 				t_id = 0;
	S32        				i;
	U8                      user_set = priority;
	S32                     from = 0, temp_var;
	S32						s, b, empty_s_index,empty_b_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (user_set == 0)
		user_set = 129;
	if (user_set > 128)
	{
		//low priority
		from = APP_TASK_COUNT_MAX;		
	}
	else
	{
		//high priority
		from = 0;
	}
	b = from + APP_TASK_COUNT_MAX;
	s = from - 1;
	empty_s_index = s;
	empty_b_index = b;
	for (i = 0; i < APP_TASK_COUNT_MAX; i++)
	{
		temp_var = app_task_priority_map[i + from].task_priority;
		if ((temp_var <= user_set) && (b == from + APP_TASK_COUNT_MAX))
		{
			if (temp_var != 0)
			{
				s = i + from;
			}
			else
			{
				empty_s_index = i + from;
			}
		}
		else if ((temp_var > user_set) && (b == from + APP_TASK_COUNT_MAX))
		{
			b = i + from;
		}
		else if ((b != from + APP_TASK_COUNT_MAX) && (temp_var == 0))
		{
			empty_b_index = i + from;
			break;
		}
			
	}
	
	if (b == s + 1)
	{
		if (empty_s_index != from - 1)
		{
			temp_var = s - empty_s_index;
		}
		else
		{
			temp_var = APP_TASK_COUNT_MAX;
		}

		if ((empty_b_index != from + APP_TASK_COUNT_MAX) && (temp_var > (empty_b_index - b)))
		{
			// shift big side
			for (i = empty_b_index - 1; i >= b; i--)
			{
				t_id = app_task_priority_map[i].task_id;
				app_task_priority_map[i + 1].task_id = t_id;
				app_task_priority_map[i + 1].task_priority = app_task_priority_map[i].task_priority;		
			    kal_change_priority(t_id, app_priority_g[i + 1]);
			}			
			temp_var = b;
		}
		else
		{
			// shift small side
			for (i = empty_s_index + 1; i <= s; i++)
			{
				t_id = app_task_priority_map[i].task_id;
				app_task_priority_map[i - 1].task_id = t_id;
				app_task_priority_map[i - 1].task_priority = app_task_priority_map[i].task_priority;		
			    kal_change_priority(t_id, app_priority_g[i - 1]);
			}			
			temp_var = s;
		}
	}
	else
	{
		temp_var = (b + s) >> 1;
	}

	app_task_priority_map[temp_var].task_id = task_id;
	app_task_priority_map[temp_var].task_priority = user_set;		
    kal_change_priority(task_id, app_priority_g[temp_var]);
	return;
}

void app_frm_change_priority(THREAD_HANDLE thread, U32 new_priority)
{
    kal_taskid     task_id;
    APP_THREAD_INFO* thread_info;
    kal_uint32 i;
    thread_info = app_frm_get_thread_info(thread);
    if(thread_info == NULL)
    {
        kal_prompt_trace(MOD_MMI_FW, "[THREAD] thread(%x) not find", thread);
        return;
    }
    task_id = thread_info->task_id;
    for(i = 0; i < APP_TASK_COUNT_MAX*2; i++)
    {
        if (app_task_priority_map[i].task_id == task_id)
        {
        	app_task_priority_map[i].task_id = 0;
        	app_task_priority_map[i].task_priority = 0;		
            kal_change_priority(task_id, new_priority);           
            kal_prompt_trace(MOD_MMI_FW, "[THREAD][WARING] thread(%x) change priority to %d", thread, new_priority);
            return;
        }
    }
    kal_prompt_trace(MOD_MMI_FW, "[THREAD] thread(%x) not find", thread);
    return;
}
