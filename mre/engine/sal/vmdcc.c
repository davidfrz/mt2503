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
 * vmdcc.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre dcc
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_SAL_DCC__

#include "mmi_dcc.h"

#include "vmdcc.h"
#include "MMIDataType.h"
#include "vmsys.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmem.h"

typedef enum
{
	VM_DCC_FUNC_NONE = 0,
	VM_DCC_FUNC_POWER_ON,
	VM_DCC_FUNC_CB,
	VM_DCC_FUNC_POWER_OFF,
	VM_DCC_FUNC_SLEEP,
	VM_DCC_FUNC_WAKEUP,
	VM_DCC_FUNC_ACCESS,
	VM_DCC_FUNC_MAX
} vm_dcc_func_type;


typedef struct
{	
    /* saving current mre app handle */
    VM_P_HANDLE m_pHandle;
	/* device type*/
	vm_dcc_device_type dev_type;
	/* callback type */
	vm_dcc_func_type callback_type;
	/* customer's func */
	union{
		VM_DCC_POWER_FUNC func1;
		VM_DCC_CB_FUNC func2;
		VM_DCC_ACESS_DEVICE_CB func3;
	} func;
	/* the pointer to customer user data */
	void* user_data;
} vm_dcc_device_param_struct;

extern VMINT mre_running;

VMINT vm_dcc_cancel(VMINT id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_node_size = 0;
    vm_dcc_device_param_struct *res_p = NULL;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_current_handle();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_DCC, id)) < 0)
    {
        return -1;
    }
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not delete res belongs to application B */
        {
            return -2;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_DCC, id, (void **)&res_p, &res_node_size) < VM_RES_OK)
    {
        return -3;
    }
	else
	{
	    vm_log_debug("vm_dcc_cancel:get res data success");
	}

    _vm_kernel_free(res_p);
    vm_res_set_data(VM_RES_TYPE_DCC, id, NULL, 0);
    vm_res_set_callback(VM_RES_TYPE_DCC, id, NULL);

    if (vm_res_release_data(VM_RES_TYPE_DCC, id) < VM_RES_OK)
    {
        return -4;
    }
    else
    {
        vm_log_debug("vm_dcc_cancel:vm_res_release_data success");
    }
	
    return 0;
}


static void vm_dcc_process_status_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sys_state)
    {
        case VM_PMNG_UNLOAD:
	        //if (vm_pmng_get_app_handle() == process_handle)
	        {			
	            while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_DCC)) != VM_RES_NOT_FIND)
	            {
	            	vm_dcc_cancel(i);
					vm_dcc_device_init();
	                vm_res_release_data(VM_RES_TYPE_DCC, i);
	                vm_res_findclose(VM_RES_TYPE_DCC);
	            }				
	        }
     		break;
     		
		default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *   vm_initialize_dcc
 * DESCRIPTION
 *   this function will be called to handle MOD_EVENT_INIT of DCC module.
 *   it will turn on power saving mode, and register 
 *   vm_dcc_process_status_callback to handle the status change of an app.
 * PARAMETERS
 *   void
 * RETURNS
 *   if no error, return 0.
 *   otherwise, return -1.
 *****************************************************************************/
static VMINT vm_initialize_dcc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (vm_res_type_set_notify_callback(
            VM_RES_TYPE_DCC, 
            vm_dcc_process_status_callback) != 0)
    {
        return -1;
    }

    return 0;
}

/*****************************************************************************
 * FUNCTION
 *   vm_finialize_dcc
 * DESCRIPTION
 *   this function will be called to handle the MOD_EVENT_RELEASE of DCC module.
 *   it will turn off power saving mode, release resources, and reset notify 
 *   callback of app's status change.
 * PARAMETERS
 *   void
 * RETURNS
 *   the return value is always 0.
 *****************************************************************************/
static VMINT vm_finialize_dcc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT rHandle = VM_RES_NOT_FIND;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((rHandle = vm_res_findfirst(-1, VM_RES_TYPE_DCC)) != VM_RES_NOT_FIND)
    {
    	vm_dcc_cancel(rHandle);
        vm_res_findclose(VM_RES_TYPE_DCC);		
        vm_res_release_data(VM_RES_TYPE_DCC, rHandle);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_DCC, NULL);

    return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vm_dcc_mod_evt_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  event       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static VMINT vm_dcc_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
    case EVT_MOD_INIT:
        vm_initialize_dcc();
        break;

    case EVT_MOD_RELEASE:
        vm_finialize_dcc();
        break;
    }

    return 0;
}

/*******************************A**********************************************
 * FUNCTION
 *  _vm_reg_dcc_module
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
VMINT _vm_reg_dcc_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return _vm_reg_module(
        "DCC MODULE", 
        (MOD_EVT_PROCESS) vm_dcc_mod_evt_proc);
}


static MMI_DCC_FUNC_RET vm_dcc_power_on_func(void* op_code, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = (vm_dcc_device_param_struct *)device_param;
    MMI_DCC_FUNC_RET ret = VM_DCC_FAIL; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (vm_pmng_set_ctx(device_p->m_pHandle) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
			return ret;
        }
        if (device_p->func.func1)
        {
            ret = device_p->func.func1(op_code, device_p->user_data);
        }
        vm_pmng_reset_ctx();
    }
	return ret;
}

static void vm_dcc_callback_func(void* op_code, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = (vm_dcc_device_param_struct *)device_param;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (vm_pmng_set_ctx(device_p->m_pHandle) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
			return;
        }
        if (device_p->func.func2)
        {
            device_p->func.func2(op_code, device_p->user_data);
        }
        vm_pmng_reset_ctx();
    }
}

static void vm_dcc_access_cb_func(vm_dcc_device_type dev_type, void* op_code, vm_dcc_func_notify_info_struct* result, void* user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = (vm_dcc_device_param_struct *)user_data;
     
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    if (vm_pmng_set_ctx(device_p->m_pHandle) == VM_PMNG_OP_OK)
    {
        if (mre_running == FALSE)
        {
            vm_pmng_reset_ctx();
			return;
        }
        if (device_p->func.func3)
        {
            device_p->func.func3(dev_type, op_code, result, device_p->user_data);
        }
        vm_pmng_reset_ctx();
    }
}


VMINT vm_dcc_save_data(void* pointer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_id = 0;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle();
    vm_dcc_device_param_struct* vm_dcc_p = (vm_dcc_device_param_struct*)pointer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_id = vm_res_save_data(VM_RES_TYPE_DCC, vm_dcc_p, sizeof(vm_dcc_p), (void*)NULL, phandle);
    if (res_id < 0)
    {
        vm_log_debug("vm_dcc_save_data : save res fail!!");        
        _vm_kernel_free(vm_dcc_p);
        res_id = -1;
    }
    return res_id;
}

/*****************************************************************************
 * DESCRIPTION
 *	register device power on func
 * PARAMETERS
 *	dev_type:    		[IN]  device type
 *	power_on_func:      [IN]  power on function
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_register_power_on_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC power_on_func, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/	
	vm_dcc_device_param_struct *device_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = vm_pmng_get_current_handle();
	device_p->dev_type = dev_type;
	device_p->user_data = device_param;
	device_p->func.func1 = power_on_func;   
	device_p->callback_type = VM_DCC_FUNC_POWER_ON;
    vm_dcc_save_data(device_p);	

	mmi_dcc_register_power_on_func((mmi_dcc_device_type)dev_type, vm_dcc_power_on_func, device_p);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device power off func
 * PARAMETERS
 *	dev_type:    		[IN]  device type
 *	power_off_func:     [IN]  power off function
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_register_power_off_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC power_off_func, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = vm_pmng_get_current_handle();
	device_p->dev_type = dev_type;
	device_p->user_data = device_param;
	device_p->func.func1 = power_off_func;
	device_p->callback_type = VM_DCC_FUNC_POWER_OFF;
    vm_dcc_save_data(device_p);	
	mmi_dcc_register_power_off_func((mmi_dcc_device_type)dev_type, vm_dcc_power_on_func, device_p);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_register_callback_func(vm_dcc_device_type dev_type, VM_DCC_CB_FUNC cb_func, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = vm_pmng_get_current_handle();
	device_p->dev_type = dev_type;
	device_p->user_data = device_param;
	device_p->func.func2 = cb_func;
	device_p->callback_type = VM_DCC_FUNC_CB;
       
    vm_dcc_save_data(device_p);	
	mmi_dcc_register_callback_func((mmi_dcc_device_type)dev_type, vm_dcc_callback_func, device_p);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_register_sleep_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC sleep_func, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = vm_pmng_get_current_handle();
	device_p->dev_type = dev_type;
	device_p->user_data = device_param;
	device_p->func.func1 = sleep_func;
	device_p->callback_type = VM_DCC_FUNC_SLEEP;
	
    vm_dcc_save_data(device_p);
	mmi_dcc_register_sleep_func((mmi_dcc_device_type)dev_type, vm_dcc_power_on_func, device_p);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_register_wakeup_func(vm_dcc_device_type dev_type, VM_DCC_POWER_FUNC wakeup_func, void* device_param)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vm_dcc_device_param_struct *device_p = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = vm_pmng_get_current_handle();
	device_p->dev_type = dev_type;
	device_p->user_data = device_param;
	device_p->func.func1 = wakeup_func;
	device_p->callback_type = VM_DCC_FUNC_WAKEUP;
	
    vm_dcc_save_data(device_p);
	mmi_dcc_register_wakeup_func((mmi_dcc_device_type)dev_type, vm_dcc_power_on_func, device_p);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_notify_power_on(vm_dcc_device_type dev_type, void* op_code, VMINT result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_notify_power_on((mmi_dcc_device_type)dev_type, op_code, result);
}


/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_notify_power_off(vm_dcc_device_type dev_type, void* op_code, VMINT result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_notify_power_off((mmi_dcc_device_type)dev_type, op_code, result);
}


/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_notify_callback(vm_dcc_device_type dev_type, void* op_code, void* result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_notify_callback((mmi_dcc_device_type)dev_type, op_code, result);
}


/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_notify_sleep(vm_dcc_device_type dev_type, void* op_code, VMINT result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_notify_sleep((mmi_dcc_device_type)dev_type, op_code, result);
}
 

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_notify_wakeup(vm_dcc_device_type dev_type, void* op_code, VMINT result)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_notify_wakeup((mmi_dcc_device_type)dev_type, op_code, result);
}
 

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_set_power_mode_param(vm_dcc_device_type dev_type, VMFLOAT Istrarup, VMFLOAT Isleep, VMFLOAT Tstartup, VMFLOAT Tworking)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_set_power_mode_param((mmi_dcc_device_type)dev_type, Istrarup, Isleep, Tstartup, Tworking);
}
 

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_set_next_working_peroid(vm_dcc_device_type dev_type, VMINT time) 
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_set_next_working_peroid((mmi_dcc_device_type)dev_type, time);
}

/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
VMINT vm_dcc_get_next_working_peroid(vm_dcc_device_type dev_type) 
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	return mmi_dcc_get_next_working_peroid((mmi_dcc_device_type)dev_type);
}


/*****************************************************************************
 * DESCRIPTION
 *	register device callback func
 * PARAMETERS
 *	dev_type:      			[IN]  device type
 *	cb_func:        		[IN]  callback function when device power on success
 *	cb_user_data:			[IN]  user data of callback func
 * RETURNS
 *  The return value is void. 
 *****************************************************************************/
void vm_dcc_access_device(vm_dcc_device_type dev_type, void* op_code, VM_DCC_ACESS_DEVICE_CB access_cb, void* user_data)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	vm_dcc_device_param_struct *device_p = NULL;    
	VMINT id = VM_RES_NOT_FIND;
	VMINT res_node_size = 0;
    vm_dcc_device_param_struct *res_p = NULL;
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*find the res table, if same type, delete the previous one */   
    id = vm_res_findfirst(process_handle, VM_RES_TYPE_DCC);
  	while ( id != VM_RES_NOT_FIND)
  	{
  		if (vm_res_get_data(VM_RES_TYPE_DCC, id, (void **)&res_p, &res_node_size) == VM_RES_OK)
		{
			if (res_p->dev_type == dev_type && res_p->callback_type == VM_DCC_FUNC_ACCESS)
			{
				_vm_kernel_free(res_p);
			    vm_res_set_data(VM_RES_TYPE_DCC, id, NULL, 0);
			    vm_res_set_callback(VM_RES_TYPE_DCC, id, NULL);
			    vm_res_release_data(VM_RES_TYPE_DCC, id);
				break;
			}
		}
  		id = vm_res_findnext(process_handle, VM_RES_TYPE_DCC);
  	}
	vm_res_findclose(VM_RES_TYPE_DCC);
	
	device_p = (vm_dcc_device_param_struct*)_vm_kernel_malloc(sizeof(vm_dcc_device_param_struct));
	device_p->m_pHandle = process_handle;
	device_p->dev_type = dev_type;
	device_p->user_data = user_data;
	device_p->func.func3 = access_cb;
	device_p->callback_type = VM_DCC_FUNC_ACCESS;
       
    vm_dcc_save_data(device_p);	
	mmi_dcc_access_device((mmi_dcc_device_type)dev_type, op_code, vm_dcc_access_cb_func, device_p);
}


//device init action
/*****************************************************************************
 * FUNCTION
 *	st_pc_device_init
 * DESCRIPTION
 *	init device table and create timer
 * PARAMETERS
 *	void
 * RETURNS
 *	void
 *****************************************************************************/
void vm_dcc_device_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	mmi_dcc_device_init();
}

VMINT vm_get_dcc_sym(VMCHAR* func_name)
{    
    if(strcmp(func_name,"vm_dcc_register_power_on_func") == 0)
        return (VMINT)vm_dcc_register_power_on_func;
    if(strcmp(func_name,"vm_dcc_register_power_off_func") == 0)
        return (VMINT)vm_dcc_register_power_off_func;
    if(strcmp(func_name,"vm_dcc_register_callback_func") == 0)
        return (VMINT)vm_dcc_register_callback_func;
    if(strcmp(func_name,"vm_dcc_register_sleep_func") == 0)
        return (VMINT)vm_dcc_register_sleep_func;
    if(strcmp(func_name,"vm_dcc_register_wakeup_func") == 0)
        return (VMINT)vm_dcc_register_wakeup_func;
    if(strcmp(func_name,"vm_dcc_notify_power_on") == 0)
        return (VMINT)vm_dcc_notify_power_on;
    if(strcmp(func_name,"vm_dcc_notify_power_off") == 0)
        return (VMINT)vm_dcc_notify_power_off;
    if(strcmp(func_name,"vm_dcc_notify_callback") == 0)
        return (VMINT)vm_dcc_notify_callback;
    if(strcmp(func_name,"vm_dcc_notify_sleep") == 0)
        return (VMINT)vm_dcc_notify_sleep;
    if(strcmp(func_name,"vm_dcc_notify_wakeup") == 0)
        return (VMINT)vm_dcc_notify_wakeup;
    if(strcmp(func_name,"vm_dcc_set_power_mode_param") == 0)
        return (VMINT)vm_dcc_set_power_mode_param;
    if(strcmp(func_name,"vm_dcc_set_next_working_peroid") == 0)
        return (VMINT)vm_dcc_set_next_working_peroid;
    if(strcmp(func_name,"vm_dcc_get_next_working_peroid") == 0)
        return (VMINT)vm_dcc_get_next_working_peroid;
    if(strcmp(func_name,"vm_dcc_access_device") == 0)
        return (VMINT)vm_dcc_access_device;
    if(strcmp(func_name,"vm_dcc_device_init") == 0)
        return (VMINT)vm_dcc_device_init;
        
    
	return 0;
}


#endif


