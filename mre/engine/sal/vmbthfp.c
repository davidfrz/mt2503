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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_features.h"
#include "vmswitch.h"
#include "vmresmng.h"
#include "vmpromng.h"
#include "vmmod.h"
#include "vmlog.h"
#include "vmsys.h"
#include "vmmem.h"
#include "MMIDataType.h"
#include "kal_general_types.h"

#if defined(__MRE_BT_HFP__)
#include "vmbthfp.h"
#include "UcmBTSrvGprot.h"

static VMINT g_is_init_register = -1;
static VMINT g_register_handle = -1;
static VMINT g_ref_count = 0;

typedef struct
{
    VM_P_HANDLE m_pHandle;
    VMINT m_nResid;
    vm_bthfp_hf_notify_cb bthfp_callback;
    void *user_data;
} vm_bthfp_hf_save_struct;



void vm_bthfp_hf_act_request(vm_bthfp_hf_act_opcode_enum act_op, void *act_data)
{
    srv_ucm_bt_act_request((srv_ucm_bt_act_opcode_enum)act_op, act_data);
}

VMINT vm_bthfp_hf_act_permit(vm_bthfp_hf_act_opcode_enum act_op, void *ptr)
{
    VMINT result = 0;
    result = srv_ucm_bt_act_permit((srv_ucm_bt_act_opcode_enum)act_op, ptr);
    return result;
}

VMINT32 vm_bthfp_hf_query_all_devices_call_count(vm_bthfp_hf_call_state_enum call_state, VMINT32* call_list)
{
    VMINT32 result = 0;
    result = srv_ucm_bt_query_call_count((srv_ucm_bt_call_state_enum)call_state, (S32*)call_list);
    return result;
}

VMINT32 vm_bthfp_hf_query_single_device_call_count(VMINT32 srv_hd, vm_bthfp_hf_call_state_enum call_state, VMINT32* index)
{
    VMINT32 result = 0;
    result = srv_ucm_bt_query_call_count_ext((S32)srv_hd, (srv_ucm_bt_call_state_enum)call_state, (S32*)index);
    return result;
}

VMINT32 vm_bthfp_hf_query_all_devices_group_count(vm_bthfp_hf_call_state_enum call_state, VMINT32* group_list)
{
    VMINT32 result = 0;
    result = srv_ucm_bt_query_group_count((srv_ucm_bt_call_state_enum)call_state, (S32*)group_list);
    return result;
}

VMINT32 vm_bthfp_hf_query_single_device_group_count(VMINT32 srv_hd, vm_bthfp_hf_call_state_enum call_state, VMINT32* index)
{
    VMINT32 result = 0;
    result = srv_ucm_bt_query_group_count_ext((S32)srv_hd, (srv_ucm_bt_call_state_enum)call_state, (S32*)index);
    return result;
}

VMBOOL vm_bthfp_hf_query_call_data(VMUINT32 call_id, vm_bthfp_hf_call_info_struct* call_info)
{
    VMBOOL result = 0;
    result = srv_ucm_bt_query_call_data((U32)call_id, (srv_ucm_bt_call_info_struct*)call_info);
    return result;
}

VMINT32 vm_bthfp_hf_query_service_hd(vm_bthfp_btaddr* bt_addr)
{
    VMINT32 result = 0;
    result = srv_ucm_bt_query_service_hd((srv_bt_cm_bt_addr*)bt_addr);
    return result;
}

VMBOOL vm_bthfp_hf_query_connected_dev_info(VMINT32 srv_hd, vm_bthfp_hf_dev_info_struct* dev_info)
{
    VMBOOL result = 0;
    result = srv_ucm_bt_query_connected_dev_info((S32)srv_hd, (srv_ucm_bt_dev_info_struct*)dev_info);
    return result;
}

VMUINT32 vm_bthfp_hf_query_connected_dev_count(VMINT32* srv_hd_list)
{
    VMUINT32 result = 0;
    result = srv_ucm_bt_query_connected_dev_count((S32*)srv_hd_list);
    return result;
}

VMBOOL vm_bthfp_hf_is_any_call(void)
{
    VMBOOL result = 0;
    result = srv_ucm_bt_is_any_call();
    return result;
}

VMBOOL vm_bthfp_hf_is_conference_call(VMUINT32* count, VMINT32* srv_hd_list)
{
    VMBOOL result = 0;
    result = srv_ucm_bt_is_conference_call((U32*)count, (S32*)srv_hd_list);
    return result;
}

VMBOOL vm_bthfp_hf_is_valid_service_hd(VMINT32 srv_hd)
{
    VMBOOL result = 0;
    result = srv_ucm_bt_is_valid_service_hd((S32)srv_hd);
    return result;
}

VMUINT8 vm_bthfp_hf_proc_inject_string(VMUINT8 index, VMUINT8* string)
{
    VMUINT8 result = 0;
    result = srv_ucm_bt_proc_inject_string((U8)index, (kal_uint8*) string);
    return result;
}

void vm_bthfp_hf_notify_internal_proc(U32 evt, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE *list = NULL;
    VMUINT num = 0;
    vm_bthfp_hf_save_struct *ctx_p;
    VMINT i = 0;
           
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_pmng_get_process_list(NULL, &num);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 6, 0, num);
    if (0 == num)
    {
        return;
    }
    list = (VM_P_HANDLE *)_vm_kernel_calloc(sizeof(VM_P_HANDLE *) * num);
    vm_pmng_get_process_list(list, &num);
    for (i = 0; i < num; i++)
    {
        VMINT resHandle = 0;
        VMINT bufSize = 0;

        if ((resHandle = vm_res_findfirst(list[i], VM_RES_TYPE_BTHFP_HF)) != VM_RES_NOT_FIND)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 6, 1, resHandle);
            if (vm_res_get_data(VM_RES_TYPE_BTHFP_HF, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 6, 2, bufSize);
                if (vm_pmng_set_ctx(list[i]) == VM_PMNG_OP_OK)
                {
                    ctx_p->bthfp_callback(evt, para, ctx_p->user_data);
                    vm_pmng_reset_ctx();
                }
            }
            vm_res_findclose(VM_RES_TYPE_BTHFP_HF);
        }
    }
    _vm_kernel_free(list);
    return;
}

VMINT vm_bthfp_hf_is_app_register(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0;
    VMINT bufSize = 0;
    VMINT result = 0;
    vm_bthfp_hf_save_struct * ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_BTHFP_HF)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 5, 0, resHandle);
        if (vm_res_get_data(VM_RES_TYPE_BTHFP_HF, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            result = 1;
        }
        else
        {
            result = -1;
        }
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 5, 1, result);
        vm_res_findclose(VM_RES_TYPE_BTHFP_HF); 
    }
    return result;
}


VMINT vm_bthfp_hf_register_notify_callback(vm_bthfp_hf_notify_cb callback, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE phandle;
    VMINT result = 0;
    vm_bthfp_hf_save_struct* bthfp_hf_p;
    VMINT bthfp_hf_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phandle = vm_pmng_get_app_handle()) == 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 4, 0);
        return VM_BTHFP_HF_ERROR;  		
    }
    
    if(g_is_init_register == -1)
    {
        result = srv_ucm_bt_register_notify_callback(vm_bthfp_hf_notify_internal_proc, SRV_UCM_BT_NOTI_EVT_IND | SRV_UCM_BT_NOTI_EVT_ACT | SRV_UCM_BT_NOTI_EVT_CONN, NULL);
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 4, 1, result);
        if(result >= 0)
        {
            g_is_init_register = 1;
            g_register_handle = result;
        }
        else
        {
            return result;
        }
    }
    
    if(vm_bthfp_hf_is_app_register(phandle) == 1)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 4, 2);
        return VM_BTHFP_HF_REGISTERED;
    }
   
    if((bthfp_hf_p = (vm_bthfp_hf_save_struct *)_vm_kernel_malloc(sizeof(vm_bthfp_hf_save_struct))) == NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 4, 3);
		    return VM_BTHFP_HF_ERROR_OF_MEM;
    }

    bthfp_hf_p->m_pHandle = phandle;
    bthfp_hf_p->bthfp_callback = callback;
    bthfp_hf_p->user_data = user_data;
    
    if ((bthfp_hf_id = vm_res_save_data(VM_RES_TYPE_BTHFP_HF, (void *) bthfp_hf_p, sizeof(vm_bthfp_hf_save_struct), NULL, phandle)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 4, 4);
        _vm_kernel_free(bthfp_hf_p);
        return VM_BTHFP_HF_ERROR_OF_RES;
    }
    bthfp_hf_p->m_nResid = bthfp_hf_id;
    g_ref_count++;
    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 4, 5, bthfp_hf_id);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 4, 6, g_ref_count);
    return bthfp_hf_id;
}

VMINT32 vm_bthfp_hf_deregister_notify_callback(VMINT32 noti_id)
{
    VMINT res_node_size = 0;
    vm_bthfp_hf_save_struct *res_p = NULL;
    VM_P_HANDLE phandle = -1;
    VM_P_HANDLE curr_phandle = vm_pmng_get_app_handle();

    if ((phandle = vm_res_get_process_handle(VM_RES_TYPE_BTHFP_HF, noti_id)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 3, 0, phandle);
        return VM_BTHFP_HF_ERROR_INVALID_ID;
    }
	
    if (curr_phandle > 0)   /* app, not engine */
    {
        if (phandle != curr_phandle)    /* application A can not cancel  belongs to application B */
        {
            return VM_BTHFP_HF_ERROR_OF_PROCESS;
        }
    }

    if (vm_res_get_data(VM_RES_TYPE_BTHFP_HF, noti_id, (void **)&res_p, &res_node_size) < VM_RES_OK)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 3, 1);
        return VM_BTHFP_HF_ERROR;
    }

    _vm_kernel_free(res_p);

    if (vm_res_release_data(VM_RES_TYPE_BTHFP_HF, noti_id) < VM_RES_OK)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 3, 2);
        return VM_BTHFP_HF_ERROR;
    }
    g_ref_count--;
    if(g_ref_count == 0)
    {
        VMINT return_value = 0;
        g_is_init_register = -1;
        return_value = srv_ucm_bt_deregister_notify_callback(g_register_handle);
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 3, 3, return_value);      
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGM , 3, 4, g_ref_count);
    return 0;
}

static void vm_bthfp_hf_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
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
                while ((i = vm_res_findfirst(process_handle, VM_RES_TYPE_BTHFP_HF)) != VM_RES_NOT_FIND)
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGS , 2, i);
                    vm_bthfp_hf_deregister_notify_callback(i);
                    vm_res_findclose(VM_RES_TYPE_BTHFP_HF);
                }				
            }
     		break;
     		
		    default:
        return;
    }
}

static void vm_bthfp_hf_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTHFP_HF, vm_bthfp_hf_notify_callback);
}

static void vm_bthfp_hf_finialize(void)
{
    VMINT i = VM_RES_NOT_FIND;

    while ((i = vm_res_findfirst(-1, VM_RES_TYPE_BTHFP_HF)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGS , 1, i);
        vm_bthfp_hf_deregister_notify_callback(i);
        vm_res_findclose(VM_RES_TYPE_BTHFP_HF);
    }
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTHFP_HF, NULL);
}

static VMINT vm_bthfp_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
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
            vm_bthfp_hf_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_bthfp_hf_finialize();
            break;
    }
    return 0;
}

VMINT _vm_reg_bthfp_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("BTHFP MODULE", (MOD_EVT_PROCESS) vm_bthfp_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGE , 0, res);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_BTHFP, TRC_MRE_BTHFP_HF_LOGS , 0, res);
    return res;
}

#endif /* __MRE_BT_HFP__ */
