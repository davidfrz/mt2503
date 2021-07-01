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

/*******************************************************************************
* Filename:
* ---------
*  
*
* Project:
* --------
*  MAUI
*
* Description:
* ------------
*  
*
* Author:
* -------
*
*
*==============================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*------------------------------------------------------------------------------
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"
#include "vmmagic.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmmem.h"


VMINT vm_magic_save_data(void* pointer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_id = 0;
    VM_P_HANDLE phandle = vm_pmng_get_current_handle();
    vm_magic_t* vm_magic_p = (vm_magic_t*)pointer;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    res_id = vm_res_save_data(VM_RES_TYPE_MAGIC, pointer, sizeof(pointer), (void*)NULL, phandle);
    if (res_id < 0)
    {
        vm_log_debug("vm_magic_save_data : save res fail!!");
        _vm_kernel_free(vm_magic_p->pointer);
        _vm_kernel_free(vm_magic_p);
        res_id = -1;
    }
    return res_id;
}


VMINT vm_magic_get_data_by_resid(VMINT	resid, void** data_buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_node_size = 0;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_current_handle();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_MAGIC, resid)) < 0)
    {
        return -1;
    }
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not delete timer belongs to application B */
        {
            return -2;
        }
    }
    if (vm_res_get_data(VM_RES_TYPE_MAGIC, resid, (void **)data_buffer, &res_node_size) < VM_RES_OK)
    {
        return -3;
    }
    else
    {
        vm_log_debug("vm_magic_get_data_by_resid success");
        return 0;
    }
}


VMINT vm_magic_get_data_by_native_handle(VMINT	native_handle, void** data_buffer, VMINT p_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT resid = -1;
    VMINT res_node_size = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(p_handle <= 0)
    {
        p_handle = -1;
    }
    resid = vm_res_findfirst(p_handle, VM_RES_TYPE_MAGIC);
    if(resid!=VM_RES_NOT_FIND)
	{
        if (vm_res_get_data(VM_RES_TYPE_MAGIC, resid, (void **)data_buffer, &res_node_size) < VM_RES_OK)
        {
            vm_res_findclose(VM_RES_TYPE_MAGIC);
            return -1;
        }
        if(native_handle == ((vm_magic_t*)data_buffer)->native_handle)
        {
			vm_res_findclose(VM_RES_TYPE_MAGIC);
            return 0;
        }

		while (resid != VM_RES_NOT_FIND)
		{
			resid = vm_res_findnext(p_handle, VM_RES_TYPE_MAGIC);
			if (vm_res_get_data(VM_RES_TYPE_MAGIC, resid, (void **)data_buffer, &res_node_size) < VM_RES_OK)
			{
				vm_res_findclose(VM_RES_TYPE_MAGIC);
				return -1;
			}
			if(native_handle == ((vm_magic_t*)data_buffer)->native_handle)
			{
				break;
			}

		 }
         vm_res_findclose(VM_RES_TYPE_MAGIC);
	}
	  return 0;
}


VMINT vm_magic_cancel(VMINT id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT res_node_size = 0;
    vm_magic_t *res_p = NULL;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_current_handle();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_MAGIC, id)) < 0)
    {
        return -1;
    }
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not delete timer belongs to application B */
        {
            return -2;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_MAGIC, id, (void **)&res_p, &res_node_size) < VM_RES_OK)
    {
        return -3;
    }
	  else
	  {
		    vm_log_debug("vm_magic_cancel:get res data success");
	  }

    _vm_kernel_free(res_p -> pointer);
	  _vm_kernel_free(res_p);
    vm_res_set_data(VM_RES_TYPE_MAGIC, id, NULL, 0);
    vm_res_set_callback(VM_RES_TYPE_MAGIC, id, NULL);

    if (vm_res_release_data(VM_RES_TYPE_MAGIC, id) < VM_RES_OK)
    {
        return -4;
    }
    else
    {
        vm_log_debug("vm_magic_cancel:vm_res_release_data success");
    }
	
    return 0;
}


static void vm_magic_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
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
        if (vm_pmng_get_app_handle() == process_handle)
        {			
            while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_MAGIC)) != VM_RES_NOT_FIND)
            {
                vm_magic_cancel(i);
                vm_res_findclose(VM_RES_TYPE_MAGIC);
            }				
        }
     		break;
     		
		    default:
        return;
    }
}


static void vm_magic_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_res_type_set_notify_callback(VM_RES_TYPE_MAGIC, vm_magic_notify_callback);
}


static void vm_magic_finialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT i = VM_RES_NOT_FIND;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_MAGIC)) != VM_RES_NOT_FIND)
    {
        vm_magic_cancel(i);
        vm_res_findclose(VM_RES_TYPE_MAGIC);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_MAGIC, NULL);
}


static VMINT vm_magic_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
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
            vm_magic_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_magic_finialize();
            break;
    }
    return 0;
}


VMINT _vm_reg_magic_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("MAGIC MODULE", (MOD_EVT_PROCESS) vm_magic_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        
    }
    return res;
}

