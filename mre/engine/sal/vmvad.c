#include "vmswitch.h"
#ifdef __MRE_SAL_VAD__
#include "mmi_frm_events_gprot.h"
#include "med_struct.h"
#include "med_api.h"
#include "stack_msgs.h"

#include "vmsys.h"
#include "vmvad.h"
#include "vmresmng.h"
#include "vmmod.h"

extern VMINT mre_running;

MMI_BOOL vm_vad_msg_callback(void* inMsg);

static void vm_vad_notify_process_status(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT resHandle = 0;
	
	switch (sys_state)
	{
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
        while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_VAD)) 
            != VM_RES_NOT_FIND)
        {
        	vm_res_release_data(VM_RES_TYPE_VAD, resHandle);
			vm_res_findclose(VM_RES_TYPE_VAD); 
        }
	default:
		break;
	}
}

static VMINT vm_vad_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	VMINT resHandle = 0;

	switch(event)
	{
	case EVT_MOD_INIT:
		if (vm_res_type_set_notify_callback(VM_RES_TYPE_VAD, vm_vad_notify_process_status) != 0)
		{
			return -1;
		}
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_VAD)) != VM_RES_NOT_FIND)
        {
			vm_res_release_data(VM_RES_TYPE_VAD, resHandle);
			vm_res_findclose(VM_RES_TYPE_VAD); 
        }
		vm_res_type_set_notify_callback(VM_RES_TYPE_VAD, NULL);
		mmi_frm_clear_protocol_event_handler(MSG_ID_MEDIA_VAD_DETECT_IND, (PsIntFuncPtr)vm_vad_msg_callback);
		break;
	default:
		resHandle = -2;
	}

	return resHandle;
}

VMINT _vm_reg_vad_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("VAD MODULE", (MOD_EVT_PROCESS)vm_vad_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		res = -1;
	}
	else
	{
		mmi_frm_set_protocol_event_handler(MSG_ID_MEDIA_VAD_DETECT_IND, (PsIntFuncPtr)vm_vad_msg_callback, MMI_TRUE);
	}
	
	return res;
}

VMBOOL vm_vad_switch_on_off(VMBOOL on, void* param)
{
	return media_aud_switch_vad_on_off(on, param);	
}

VMBOOL vm_vad_set_level(VMUINT8 level)
{
	return media_aud_set_vad_level(level);	
}

VMBOOL vm_vad_is_on(void)
{
	return aud_is_vad_on();	
}

VMUINT8 vm_vad_get_level(void)
{
	return aud_get_vad_level();	
}

MMI_BOOL vm_vad_msg_callback(void* inMsg)
{
	vm_vad_msg_hdlr cb;
	VMINT res_handle = -1;
	VMINT prc_handle = -1;
	
	
	media_vad_detect_ind_struct* ind = (media_vad_detect_ind_struct*)inMsg;
	
	if (mre_running == FALSE)
		return;

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_VAD)) != VM_RES_NOT_FIND)
	{
		vm_res_get_callback(VM_RES_TYPE_VAD, res_handle, (void**)&cb);
		prc_handle = vm_res_get_process_handle(VM_RES_TYPE_VAD, res_handle);

		if (vm_pmng_set_ctx(prc_handle) == VM_PMNG_OP_OK)
		{
			if (cb != NULL)
			{
				cb(ind->result, NULL);
			}
			vm_pmng_reset_ctx();
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_VAD)) != VM_RES_NOT_FIND)
		{		
			vm_res_get_callback(VM_RES_TYPE_VAD, res_handle, (void**)&cb);
			prc_handle = vm_res_get_process_handle(VM_RES_TYPE_VAD, res_handle);

			if (vm_pmng_set_ctx(prc_handle) == VM_PMNG_OP_OK)
			{
				if (cb != NULL)
				{
					cb(ind->result, NULL);
				}
				vm_pmng_reset_ctx();
			}
		}
		vm_res_findclose(VM_RES_TYPE_VAD);
	}		
}

void vm_vad_register_callback(vm_vad_msg_hdlr callback)
{
	VMINT resHandle = 0;
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	VMINT result = 0;
	
	if ((resHandle = vm_res_save_data(VM_RES_TYPE_VAD, NULL, 0, (void*)NULL, process_handle))>= 0)
    {
		vm_res_set_callback(VM_RES_TYPE_VAD, resHandle, (void*)callback);
	}
}

#endif 
