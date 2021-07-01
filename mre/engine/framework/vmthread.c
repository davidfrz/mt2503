/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * vmthread.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre thread
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_CORE_THREAD__

#include "stack_ltlcom.h"

#include "app_frm_thread_gprot.h"
#include "app_frm_message_gprot.h"
#include "app_thread_mutex_gprot.h"
#include "vmsys.h"
#include "vmpromnginner.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmthread.h"

typedef struct _vm_thread_user_data
{
	VM_P_HANDLE process_handle;
	VM_THREAD_FUNC cb;
	VMINT r9;
	void* user_data;
}vm_thread_user_data;

extern VMINT mre_running;
extern int vm_get_sb(void);
extern _vm_pcb_t* vm_sh_pcb_in_pt(VMINT search_type, VMINT value, VM_PROCESS_STATUS* status);
extern void app_frm_change_priority(THREAD_HANDLE thread, U32 new_priority);

vm_thread_user_data vm_thread_data[VM_THREAD_SIZE] = {0};

void vm_release_thread(VM_P_HANDLE process_handle)
{
	int i;
	
	for(i = 0; i < VM_THREAD_SIZE; i++)
	{
		if(vm_thread_data[i].process_handle == process_handle)
		{
			vm_thread_data[i].cb = NULL;
			vm_thread_data[i].r9 = 0;
			vm_thread_data[i].process_handle = 0;
			vm_thread_data[i].user_data = NULL;
		}
	}
}

static VMINT32 vm_thread_proc_callback(THREAD_HANDLE thread_handle, void* user_data)
{
	VMINT32 R9 = 0;
	vm_thread_user_data* p_data = (vm_thread_user_data*)user_data;
	VM_P_HANDLE process_handle = app_frm_get_main_thread_handle();

	if (mre_running == FALSE || (p_data->process_handle != process_handle))
		return 0;
	
	R9 = vm_get_sb();
	vm_restore_sb(p_data->r9);
	if (p_data->cb != NULL)
	{
		p_data->cb(thread_handle, p_data->user_data);
	}
	vm_restore_sb(R9);
	p_data->cb = NULL;
	p_data->r9 = 0;
	p_data->process_handle = 0;
	p_data->user_data = NULL;
	return 0;
}

VM_THREAD_HANDLE vm_thread_create(VM_THREAD_FUNC thread_function, void* data,VMUINT8 priority)
{
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	VM_THREAD_HANDLE thread_handle = 0;
	_vm_pcb_t* pcb = NULL;
	VMINT i;
	
	if(thread_function==NULL)
	{
		return 0;
	}

	for(i=0; i< VM_THREAD_SIZE; i++)
	{
		if(vm_thread_data[i].process_handle == 0)
			break;
	}

	if(i==VM_THREAD_SIZE)
	{
		return 0;
	}

	if ((pcb = vm_sh_pcb_in_pt(SH_TYPE_PROCESS_HANDLE, process_handle, NULL)) != NULL)
	{

		vm_thread_data[i].process_handle = process_handle;
		vm_thread_data[i].cb = thread_function;
		vm_thread_data[i].r9 = pcb->r9;
		vm_thread_data[i].user_data = data;
		
		thread_handle = app_frm_create_thread(vm_thread_proc_callback, (void*)&vm_thread_data[i], priority, THREAD_TYPE_MRE, process_handle);

		if(thread_handle == 0)
		{
			vm_thread_data[i].process_handle = 0;
			vm_thread_data[i].cb = NULL;
			vm_thread_data[i].r9 = 0;
			vm_thread_data[i].user_data = NULL;
		}
	}
	
	return thread_handle;
}

VM_THREAD_HANDLE vm_thread_get_current_handle(void)
{
	return app_frm_get_current_thread_handle();
}

VM_THREAD_HANDLE vm_thread_get_main_handle(void)
{
	return app_frm_get_main_thread_handle();
}

void vm_thread_send_msg(VM_THREAD_HANDLE thread_handle, VMUINT32 msg_id, void* user_data)
{
	app_frm_send_msg_to_thread(thread_handle, msg_id, user_data);
}

void vm_thread_get_msg(VM_MSG_STRUCT* msg)
{
	ilm_struct lim_ptr;
	APP_EVENT_STRUCT* evt;
	U16 length;
	app_frm_get_thread_message(&lim_ptr);
	evt = (APP_EVENT_STRUCT*) get_local_para_ptr(lim_ptr.local_para_ptr, &length);
	msg->message_id = evt->message_id;
	msg->user_data = evt->user_data;
	free_ilm(&lim_ptr);
}

void vm_thread_change_priority(VM_THREAD_HANDLE thread_handle, VMUINT32 new_priority)
{
	app_frm_change_priority(thread_handle, new_priority); 
}

VM_SIGNAL_ID vm_signal_init(void)
{
	return app_frm_signal_init();
}

void vm_signal_clean(VM_SIGNAL_ID s_id)
{
	app_frm_signal_clean(s_id);
}
	
void vm_signal_post(VM_SIGNAL_ID s_id)
{
	app_frm_signal_post(s_id);
}

VMINT32 vm_signal_wait(VM_SIGNAL_ID s_id)
{
	return app_frm_signal_wait(s_id);
}

VMINT32 vm_signal_timedwait(VM_SIGNAL_ID s_id, VMUINT32 time_count)
{
	return app_frm_signal_timedwait(s_id, time_count);
}

void vm_signal_deinit(VM_SIGNAL_ID s_id)
{
	app_frm_signal_deinit(s_id);
}

void vm_mutex_create(vm_thread_mutex_struct *mutex)
{
	app_frm_mutex_create((app_frm_mutex_struct *)mutex);
}

void vm_mutex_lock(vm_thread_mutex_struct *mutex)
{
	app_frm_mutex_lock((app_frm_mutex_struct *)mutex);
}

void vm_mutex_unlock(vm_thread_mutex_struct *mutex)
{
	app_frm_mutex_unlock((app_frm_mutex_struct *)mutex);
}

void vm_thread_sleep(VMUINT32 timeout)
{
       VMUINT32 ticks;
       ticks = kal_milli_secs_to_ticks(timeout);
       kal_sleep_task(ticks);
       return;
}

#endif


