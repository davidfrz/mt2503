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
 * vmdcl.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre dcl
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

#ifdef __MRE_CORE_DCL__
#include "mmi_trc.h"
#include "app_frm_thread_gprot.h"

#include "vmsys.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmdcl.h"
#include "vmdcl_eint.h"
#include "vmdcl_gpio.h"
#include "dcl.h"
#include "dcl_common.h"
#include "dcl_eint.h"
#include "vmlog.h"
#include "spi_hal.h"

#define VM_DCL_MAX_CALLBACK 10
#define VM_DCL_MAX_GPIO 20

typedef struct _vm_dcl_callback_note_struct
{
	VM_DCL_HANDLE device_handle;
	VM_DCL_EVENT event;
	VM_DCL_CALLBACK callback;
}vm_dcl_callback_note_struct;

typedef struct _vm_dcl_gpio_power_struct
{
	VM_DCL_HANDLE device_handle;
	VMINT32 gpio;
}vm_dcl_gpio_power_struct;

static vm_dcl_callback_note_struct vm_dcl_callback_list[VM_DCL_MAX_CALLBACK];
static vm_dcl_gpio_power_struct vm_dcl_gpio_list[VM_DCL_MAX_GPIO];

extern VMINT mre_running;
extern BOOL mmiapi_is_MMI_task(void);

static DCL_CALLBACK g_dcl_callback = NULL;

static DCL_UINT8 vm_dcl_msg_handler (void *local_buf,module_type src_mod, ilm_struct* ilm )
{
	DCL_EVENT event_id;
	DCL_HANDLE dev_handle;
	DCL_CB_ILM_DATA ilm_data;
	DCL_STATUS status=STATUS_OK;
#ifdef __MTK_TARGET__
	
	if(g_dcl_callback)
	{
		status = DCL_GetEventID_DevHandle(ilm, &event_id, &dev_handle);
		ilm_data.local_para_ptr = (void*)ilm->local_para_ptr;
		ilm_data.peer_buff_ptr = (void*)ilm->peer_buff_ptr;
		g_dcl_callback(&ilm_data,event_id,dev_handle);
	}
#endif	
	
	return STATUS_OK;
}

static DCL_STATUS vm_dcl_register_mmi_callback(
	DCL_HANDLE		device_handle,
	DCL_EVENT		event_id,
	DCL_CALLBACK	callback,
	void*			parameter,
	DCL_USER_ID  	user_id){
	msg_type msg_id=(msg_type)0;
	DCL_STATUS status=STATUS_OK;
#ifdef __MTK_TARGET__
	status = DCL_GetMSGID(device_handle,event_id,&msg_id);
	
	if(status == STATUS_OK)
	{
		if(0 != msg_id )
		{
			mmi_frm_set_protocol_event_handler(msg_id, vm_dcl_msg_handler,DCL_TRUE);
			g_dcl_callback = callback;
		}
		else
		{
			status = STATUS_INVALID_EVENT;
		}
	}
#endif	
	return status;
}


static void vm_dcl_notify_process_status(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT resHandle = 0;
	VM_DCL_HANDLE dcl_handle = -1;
	
	switch (sys_state)
	{
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
        while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_DCL)) 
            != VM_RES_NOT_FIND)
        {
        	if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
			{
				DCL_Close(dcl_handle);
				vm_res_release_data(VM_RES_TYPE_DCL, resHandle);
				vm_res_findclose(VM_RES_TYPE_DCL); 
        	}
        }
	default:
		break;
	}
}

static VMINT vm_dcl_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	VMINT resHandle = 0;
	VM_DCL_HANDLE dcl_handle = -1;
	int i;
	
	switch(event)
	{
	case EVT_MOD_INIT:
		if (vm_res_type_set_notify_callback(VM_RES_TYPE_DCL, vm_dcl_notify_process_status) != 0)
		{
			return -1;
		}
		for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
		{
			vm_dcl_callback_list[i].callback = NULL;
			vm_dcl_callback_list[i].device_handle = -1;
			vm_dcl_callback_list[i].event = 0;
		}
		for(i=0; i<VM_DCL_MAX_GPIO; i++)
		{
			vm_dcl_gpio_list[i].gpio = -1;
			vm_dcl_gpio_list[i].device_handle = -1;
		}
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
        {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
			{
        		DCL_Close(dcl_handle);
				vm_res_release_data(VM_RES_TYPE_DCL, resHandle);
				vm_res_findclose(VM_RES_TYPE_DCL); 
			}
        }
		vm_res_type_set_notify_callback(VM_RES_TYPE_DCL, NULL);
		
		for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
		{
			vm_dcl_callback_list[i].callback = NULL;
			vm_dcl_callback_list[i].device_handle = -1;
			vm_dcl_callback_list[i].event = 0;
		}
		
		for(i=0; i<VM_DCL_MAX_GPIO; i++)
	  {
			if(vm_dcl_gpio_list[i].gpio != -1)
			{
				vm_dcl_close_power(vm_dcl_gpio_list[i].gpio);
			}
			vm_dcl_gpio_list[i].gpio = -1;
			vm_dcl_gpio_list[i].device_handle = -1;
	  }
		break;
	default:
		resHandle = -2;
	}

	return resHandle;
}

VMINT _vm_reg_dcl_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("DCL MODULE", (MOD_EVT_PROCESS)vm_dcl_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		res = -1;
	}

	return res;
}

static void vm_dcl_event_callback(void* parameter, VM_DCL_EVENT event, VM_DCL_HANDLE device_handle)
{
	VM_DCL_CALLBACK cb;
	VMINT res_handle = -1;
	VMINT dev_handle = -1;
	VMINT prc_handle = -1;
	
	if (mre_running == FALSE)
		return;

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, res_handle, (VMINT *)&dev_handle))== VM_RES_OK)
		{
			if (dev_handle == device_handle)
			{
				vm_res_get_callback(VM_RES_TYPE_DCL, res_handle, (void**)&cb);
				prc_handle = vm_res_get_process_handle(VM_RES_TYPE_DCL, res_handle);

				if (vm_pmng_set_ctx(prc_handle) == VM_PMNG_OP_OK)
				{
					if (cb != NULL)
					{
						cb(parameter, event, device_handle);
					}
					vm_pmng_reset_ctx();
				}
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
		{
			if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, res_handle, (VMINT *)&dev_handle))== VM_RES_OK)
			{
				if (dev_handle == device_handle)
				{
					vm_res_get_callback(VM_RES_TYPE_DCL, res_handle, (void**)&cb);
					prc_handle = vm_res_get_process_handle(VM_RES_TYPE_DCL, res_handle);

					if (vm_pmng_set_ctx(prc_handle) == VM_PMNG_OP_OK)
					{
						if (cb != NULL)
						{
							cb(parameter, event, device_handle);
						}
						vm_pmng_reset_ctx();
					}
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_DCL);
	}	
}

static void vm_dcl_thread_event_callback(void* parameter, VM_DCL_EVENT event, VM_DCL_HANDLE device_handle)
{	
	int i;
	if (mre_running == FALSE)
		return;
	
	for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
	{
		if(vm_dcl_callback_list[i].device_handle == device_handle 
			&& vm_dcl_callback_list[i].event == event
			&& vm_dcl_callback_list[i].callback != NULL)
		{
			vm_dcl_callback_list[i].callback(parameter, event, device_handle);
			return ;
		}
	}
}

static VMBOOL vm_dcl_open_power(VMUINT32 gpio)
{
	PMU_CTRL_LDO_BUCK_SET_GPIO_POWER_EN val;
	VM_DCL_HANDLE handle = -1;
	handle = DCL_Open(DCL_PMU, FLAGS_NONE);
	val.enable =DCL_TRUE;
	val.gpionum = gpio;
	DclPMU_Control(handle, LDO_BUCK_SET_GPIO_POWER_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

static VMBOOL vm_dcl_close_power(VMUINT32 gpio)
{
	PMU_CTRL_LDO_BUCK_SET_GPIO_POWER_EN val;
	VM_DCL_HANDLE handle = -1;
	handle = DCL_Open(DCL_PMU, FLAGS_NONE);
	val.enable =DCL_FALSE;
	val.gpionum = gpio;
	DclPMU_Control(handle, LDO_BUCK_SET_GPIO_POWER_EN, (DCL_CTRL_DATA_T *)&val);
	DclPMU_Close(handle);
}

VM_DCL_HANDLE vm_dcl_open(VM_DCL_DEV dev, VM_DCL_FLAGS flags)
{
	BOOL isMMI = TRUE;
	VM_DCL_HANDLE dcl_handle = -1;
	
	isMMI = mmiapi_is_MMI_task() ? TRUE : FALSE;
	
	if(dev == VM_DCL_GPIO)
	{
		vm_dcl_open_power(flags);
	}
					
	if(isMMI)
	{
		VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
		VMINT handle = -1;

		if ((handle = vm_res_save_data(VM_RES_TYPE_DCL, NULL, 0, (void*)NULL, process_handle))>= 0)
		{
			dcl_handle = DCL_Open(dev, flags);
			
			if (dcl_handle == VM_DCL_HANDLE_INVALID )
			{
				if(dev == VM_DCL_GPIO)
				{
					vm_dcl_close_power(flags);
				}
				
				vm_res_release_data(VM_RES_TYPE_DCL, handle);
			}
			else
			{						
				if(dev == VM_DCL_EINT)
				{
					EINT_CTRL_SET_DST_MOD_ID_T mod;
					mod.dst_mod_id = MOD_MMI;
					DCL_Control(dcl_handle, EINT_CMD_SET_DST_MOD_ID, &mod);
				}
				vm_res_set_mtk_reshandle(VM_RES_TYPE_DCL, handle, dcl_handle);
			}
		}
	}
	else
	{
		dcl_handle = DCL_Open(dev, flags);
		
		if (dcl_handle != VM_DCL_HANDLE_INVALID )
		{
				if(dev == VM_DCL_GPIO)
				{
					int i;
			
					for(i=0; i<VM_DCL_MAX_GPIO; i++)
					{
						if(vm_dcl_gpio_list[i].device_handle == -1)
						{
							vm_dcl_gpio_list[i].device_handle = dcl_handle;
							vm_dcl_gpio_list[i].gpio = flags;
							break;
						}
					}
				}
				
				if(dev == VM_DCL_EINT)
				{
					EINT_CTRL_SET_DST_MOD_ID_T mod;
					mod.dst_mod_id = MOD_MMI;  // now all send to MMI
					// app_frm_get_current_mod_id()
					DCL_Control(dcl_handle, EINT_CMD_SET_DST_MOD_ID, &mod);
				}
		}
		else
		{
			if(dev == VM_DCL_GPIO)
			{
				vm_dcl_close_power(flags);
			}
		}
		
	}
	
	return dcl_handle;
}

VM_DCL_STATUS vm_dcl_control (VM_DCL_HANDLE device_handle,VM_DCL_CTRL_CMD cmd,  void* arg)
{
	return DCL_Control(device_handle, cmd, arg);
}

VM_DCL_STATUS vm_dcl_close(VM_DCL_HANDLE device_handle)
{
	BOOL isMMI = TRUE;
	VM_DCL_STATUS result = VM_DCL_STATUS_FAIL;
	VMINT i;
	
	isMMI = mmiapi_is_MMI_task() ? TRUE : FALSE;
		
	for(i=0; i<VM_DCL_MAX_GPIO; i++)
	{
		if(vm_dcl_gpio_list[i].device_handle == device_handle)
		{
			vm_dcl_close_power(vm_dcl_gpio_list[i].gpio);
			vm_dcl_gpio_list[i].gpio = -1;
			vm_dcl_gpio_list[i].device_handle = -1;
		}
	}
	
	if(isMMI)
	{
		VMINT resHandle = 0;
		VM_DCL_HANDLE dcl_handle = -1;
		VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

		if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
	    {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
			{
				if(dcl_handle == device_handle)
	        	{
	        		result = DCL_Close(device_handle);
					vm_res_release_data(VM_RES_TYPE_DCL, resHandle);
				}
			}
			while ((resHandle = vm_res_findnext(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
			{		
				if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
				{
					if(dcl_handle == device_handle)
					{
						result = DCL_Close(device_handle);
						vm_res_release_data(VM_RES_TYPE_DCL, resHandle);
						break;
					}
				}
			}
			vm_res_findclose(VM_RES_TYPE_DCL);
		}
	}
	else
	{
		int i;
		
		for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
		{
			if(vm_dcl_callback_list[i].device_handle == device_handle)
			{
				vm_dcl_callback_list[i].device_handle = -1;
				vm_dcl_callback_list[i].event = 0;
				vm_dcl_callback_list[i].callback = NULL;
			}
		}
		
		result = DCL_Close(device_handle);
	}
	
	return result;
}

VM_DCL_STATUS vm_dcl_registercallback(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, VM_DCL_CALLBACK callback, void* user_data)
{
	BOOL isMMI = TRUE;
	VM_DCL_STATUS result = VM_DCL_STATUS_FAIL;
	isMMI = mmiapi_is_MMI_task() ? TRUE : FALSE;

	if(isMMI)
	{
		VMINT resHandle = 0;
		VM_DCL_HANDLE dcl_handle = -1;
		VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

		if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
	    {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
			{
				if(dcl_handle == device_handle)
	        	{
	        		result = vm_dcl_register_mmi_callback(device_handle, event, vm_dcl_event_callback, (void*)user_data, DCL_USER_MRE);
					if(result >= VM_DCL_STATUS_OK)
					{
						vm_res_set_callback(VM_RES_TYPE_DCL, resHandle, (void*)callback);
					}
				}
			}
			
			while ((resHandle = vm_res_findnext(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
			{		
				if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
				{
					if(dcl_handle == device_handle)
					{
						result = vm_dcl_register_mmi_callback(device_handle, event, vm_dcl_event_callback, (void*)user_data, DCL_USER_MRE);
						if(result >= VM_DCL_STATUS_OK)
						{
							vm_res_set_callback(VM_RES_TYPE_DCL, resHandle, (void*)callback);
							break;
						}
					}
				}
			}
			
			vm_res_findclose(VM_RES_TYPE_DCL);
		}
	}
	else
	{
		int i;
		
		for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
		{
			if(vm_dcl_callback_list[i].device_handle == device_handle 
				&& vm_dcl_callback_list[i].event == event
				&& vm_dcl_callback_list[i].callback != NULL)
			{
				break;
			}
		}
		
		if(i != VM_DCL_MAX_CALLBACK)
		{
			return VM_DCL_STATUS_DEVICE_IS_BUSY;
		}
		
		for(i=0; i<VM_DCL_MAX_CALLBACK; i++)
		{
			if(vm_dcl_callback_list[i].device_handle == -1)
			{
				vm_dcl_callback_list[i].device_handle = device_handle;
				vm_dcl_callback_list[i].event = event;
				vm_dcl_callback_list[i].callback = callback;
				break;
			}
		}
		result = vm_dcl_register_mmi_callback(device_handle, event, vm_dcl_thread_event_callback, (void*)user_data, DCL_USER_MRE);
	}
	
	return result;
}

VM_DCL_STATUS vm_dcl_addlistenevent(VM_DCL_HANDLE device_handle,VM_DCL_EVENT event, void* user_data)
{
	BOOL isMMI = TRUE;
	VM_DCL_STATUS result = VM_DCL_STATUS_FAIL;
	isMMI = mmiapi_is_MMI_task() ? TRUE : FALSE;

	if(isMMI)
	{
		VMINT resHandle = 0;
		VM_DCL_HANDLE dcl_handle = -1;
		VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

		if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
	    {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
			{
				if(dcl_handle == device_handle)
	        	{
	        		result = vm_dcl_register_mmi_callback(device_handle, event, vm_dcl_event_callback, (void*)user_data, DCL_USER_MRE);				
					if(result >= VM_DCL_STATUS_OK)
					{
						vm_log_fatal("vm_dcl_register_mmi_callback success");
					}
				}
			}

			while ((resHandle = vm_res_findnext(process_handle, VM_RES_TYPE_DCL)) != VM_RES_NOT_FIND)
			{		
				if (vm_res_get_mtk_reshandle(VM_RES_TYPE_DCL, resHandle, (VMINT *)&dcl_handle) == VM_RES_OK)
				{
					if(dcl_handle == device_handle)
					{
						result = vm_dcl_register_mmi_callback(device_handle, event, vm_dcl_event_callback, (void*)user_data, DCL_USER_MRE);
						if(result >= VM_DCL_STATUS_OK)
						{
							vm_log_fatal("vm_dcl_register_mmi_callback success");
							break;
						}
					}
				}
			}
			
			vm_res_findclose(VM_RES_TYPE_DCL);

		}
	}
	return result;
}

VM_DCL_STATUS vm_dcl_read(VM_DCL_HANDLE device_handle, VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* returned_len,VM_DCL_OPTIONS options)
{
	return DCL_Read(device_handle, buf, buf_len, returned_len, options);
}

VM_DCL_STATUS vm_dcl_write(VM_DCL_HANDLE device_handle,VM_DCL_BUFF* buf, VM_DCL_BUFF_LEN buf_len, VM_DCL_BUFF_LEN* writed_len,VM_DCL_OPTIONS options)
{
	return DCL_Write(device_handle, buf, buf_len, writed_len, options);
}

VM_DCL_MODULE_TYPE_T vm_dcl_get_ownerid()
{
	BOOL isMMI = TRUE;
	isMMI = mmiapi_is_MMI_task() ? TRUE : FALSE;

	if(isMMI)
	{
		return (VM_DCL_MODULE_TYPE_T)MOD_MMI;
	}
	else
	{
		//return (VM_DCL_MODULE_TYPE_T)app_frm_get_current_mod_id();
		return (VM_DCL_MODULE_TYPE_T)MOD_MMI;
	}
}

VMUINT32 vm_irq_mask()
{
	return SaveAndSetIRQMask();
}

void vm_irq_restore(VMUINT32 mask)
{
	RestoreIRQMask(mask);
}

#endif


