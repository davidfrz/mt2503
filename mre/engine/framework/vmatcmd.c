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
 * vmatcmd.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   mre atcmd
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
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#include "vmswitch.h"

#ifdef __MRE_CORE_ATCMD__
#include "app_frm_command_gprot.h"
#include "vmsys.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmatcmd.h"

extern VMINT mre_running;

static void vm_atcmd_notify_process_status(VM_P_HANDLE process_handle, VMINT sys_state)
{
	VMINT resHandle = 0;
	VMINT mtk_handle;
	vm_atcmd_user_data* p_data;
	
	switch (sys_state)
	{
	case VM_PMNG_BACKGROUND:
		break;
	case VM_PMNG_UNLOAD:
        while ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_ATCMD)) 
            != VM_RES_NOT_FIND)
        {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, resHandle, (VMINT *)&mtk_handle) == VM_RES_OK)
			{
				p_data = (vm_atcmd_user_data*)mtk_handle;
        		app_frm_close_command_port(p_data->port);
				vm_free(p_data);
				vm_res_release_data(VM_RES_TYPE_ATCMD, resHandle);
				vm_res_findclose(VM_RES_TYPE_ATCMD); 
			}
        }
	default:
		break;
	}
}

static VMINT vm_atcmd_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	VMINT resHandle = 0;
	VMUINT16 port_i = -1;
	VMINT mtk_handle;
	vm_atcmd_user_data* p_data;

	switch(event)
	{
	case EVT_MOD_INIT:
		if (vm_res_type_set_notify_callback(VM_RES_TYPE_ATCMD, vm_atcmd_notify_process_status) != 0)
		{
			return -1;
		}
		break;
	case EVT_MOD_ACTIVE:
		break;
	case EVT_MOD_INACTIVE:
		break;
	case EVT_MOD_RELEASE:
        while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_ATCMD)) != VM_RES_NOT_FIND)
        {
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, resHandle, (VMINT *)&mtk_handle) == VM_RES_OK)
			{
				p_data = (vm_atcmd_user_data*)mtk_handle;
        		app_frm_close_command_port(p_data->port);
				vm_free(p_data);
				vm_res_release_data(VM_RES_TYPE_ATCMD, resHandle);
				vm_res_findclose(VM_RES_TYPE_ATCMD); 
			}
        }
		vm_res_type_set_notify_callback(VM_RES_TYPE_ATCMD, NULL);
		
		break;
	default:
		resHandle = -2;
	}

	return resHandle;
}

VMINT _vm_reg_atcmd_module(void)
{
	int res = 0;
	
	if ((res = _vm_reg_module("ATCMD MODULE", (MOD_EVT_PROCESS)vm_atcmd_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		res = -1;
	}

	return res;
}

static void vm_atcmd_event_callback(vm_command_struct *param, void *user_data)
{
	vm_command_callback cb;
	VMINT res_handle = -1;
	VMINT mtk_handle = 0;
	vm_atcmd_user_data* p_data = (vm_atcmd_user_data*)user_data;

	if (mre_running == FALSE)
		return;

	if ((res_handle = vm_res_findfirst(p_data->handle, VM_RES_TYPE_ATCMD)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
		{
			if(mtk_handle == (VMINT)user_data)
			{
				vm_res_get_callback(VM_RES_TYPE_ATCMD, res_handle, (void**)&cb);
				if (vm_pmng_set_ctx(p_data->handle) == VM_PMNG_OP_OK)
				{
					if (cb != NULL)
					{
						cb(param, p_data->user_data);
					}
					vm_pmng_reset_ctx();
				}
			}
		}
		
		while ((res_handle = vm_res_findnext(p_data->handle, VM_RES_TYPE_ATCMD)) != VM_RES_NOT_FIND)
		{		
			if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
			{
				if(mtk_handle == (VMINT)user_data)
				{
					vm_res_get_callback(VM_RES_TYPE_ATCMD, res_handle, (void**)&cb);
					if (vm_pmng_set_ctx(p_data->handle) == VM_PMNG_OP_OK)
					{
						if (cb != NULL)
						{
							cb(param, p_data->user_data);
						}
						vm_pmng_reset_ctx();
					}
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_ATCMD);
	}	
}

VMUINT16 vm_command_open_port(VMUINT16 port, vm_command_callback call_back, void* user_data)
{
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();
	VMUINT16 port_i = 0;
	VMINT handle = -1;
	vm_atcmd_user_data* p_data = vm_malloc(sizeof(vm_atcmd_user_data));
	if(p_data == NULL)
	{
		return 0;
	}
	
	p_data->handle = process_handle;
	p_data->port = port;
	p_data->user_data = user_data;
	
	if ((handle = vm_res_save_data(VM_RES_TYPE_ATCMD, NULL, 0, (void*)NULL, process_handle))>= 0)
	{
		port_i = app_frm_open_command_port(port, (app_command_callback)vm_atcmd_event_callback, (void*)p_data);
		
		if (port_i == 0 )
		{
			vm_free(p_data);
			vm_res_release_data(VM_RES_TYPE_ATCMD, handle);
		}
		else
		{
			vm_res_set_mtk_reshandle(VM_RES_TYPE_ATCMD, handle, (VMINT)p_data);
			vm_res_set_callback(VM_RES_TYPE_ATCMD, handle, (void*)call_back);
		}
	}
	return port_i;
}

void vm_command_close_port(VMUINT16 port)
{
	VMINT resHandle = 0;
	vm_atcmd_user_data* p_data;
	VMINT mtk_handle;
	VM_P_HANDLE process_handle = vm_pmng_get_current_handle();

	if ((resHandle = vm_res_findfirst(process_handle, VM_RES_TYPE_ATCMD)) != VM_RES_NOT_FIND)
    {
		if (vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, resHandle, (VMINT *)&mtk_handle) == VM_RES_OK)
		{
			p_data = (vm_atcmd_user_data*)mtk_handle;
			
			if(port == p_data->port)
        	{
        		app_frm_close_command_port(port );
				vm_free(p_data);
				vm_res_release_data(VM_RES_TYPE_ATCMD, resHandle);
			}
		}
		while ((resHandle = vm_res_findnext(process_handle, VM_RES_TYPE_ATCMD)) != VM_RES_NOT_FIND)
		{		
			if (vm_res_get_mtk_reshandle(VM_RES_TYPE_ATCMD, resHandle, (VMINT *)&mtk_handle) == VM_RES_OK)
			{
				p_data = (vm_atcmd_user_data*)mtk_handle;
				
				if(port == p_data->port)
				{
					app_frm_close_command_port(port );
					vm_free(p_data);
					vm_res_release_data(VM_RES_TYPE_ATCMD, resHandle);
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_ATCMD);
	}
}

void vm_command_reply(char* reply_buf, VMUINT32 buf_size, VMUINT32 reply_type)
{
	app_frm_command_reply(reply_buf, buf_size, reply_type);
}

VMUINT16 vm_open_command_port(VMUINT16 port, vm_command_callback call_back, void *user_data)
{
	return vm_command_open_port(port, call_back, user_data);
}

void vm_close_command_port(VMUINT16 port)
{
	vm_command_close_port(port);
}

#endif


