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
#include "vmbtpdms.h"

#ifdef __MRE_BT_PDMS__
#include "PdmsSrvGprot.h"

typedef struct
{
    VM_P_HANDLE m_pHandle;
    VMINT m_nResid;
    vm_pdms_connection_state_callback           connection_state_cb;
    vm_pdms_data_to_read_callback               data_to_read_notify_cb;
    vm_pdms_read_data_request_callback          read_data_request_cb;
} vm_btpdms_save_struct;


static vm_pdms_callback_t vm_pdms_internal_callback_t;
static VMINT g_is_init_register = -1;
static VMINT g_ref_count = 0;

void vm_pdms_connection_state_internal_proc(VMINT8 *bd_addr, VMINT state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE *list = NULL;
    VMUINT num = 0;
    vm_btpdms_save_struct *ctx_p;
    VMINT i = 0;
           
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_pmng_get_process_list(NULL, &num);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 11, 0, num);
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

        if ((resHandle = vm_res_findfirst(list[i], VM_RES_TYPE_BTPDMS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTPDMS, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 11, 1, list[i]);
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 11, 2, resHandle);
                if (vm_pmng_set_ctx(list[i]) == VM_PMNG_OP_OK)
                {
                    ctx_p->connection_state_cb(bd_addr, state);
                    vm_pmng_reset_ctx();
                }
            }
            vm_res_findclose(VM_RES_TYPE_BTPDMS);
        }	  
    }
    _vm_kernel_free(list);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS, 11, 3);
    return;
}

VMINT vm_pdms_data_to_read_internal_proc(VMINT8 *bd_addr, void* buf, VMUINT32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE *list = NULL;
    VMUINT num = 0;
    vm_btpdms_save_struct *ctx_p;
    VMINT i = 0;    
           
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_pmng_get_process_list(NULL, &num);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 10, 0, num);
    if (0 == num)
    {
        return 0;
    }
    list = (VM_P_HANDLE *)_vm_kernel_calloc(sizeof(VM_P_HANDLE *) * num);
    vm_pmng_get_process_list(list, &num);
    for (i = 0; i < num; i++)
    {
        VMINT resHandle = 0;
        VMINT bufSize = 0;

        if ((resHandle = vm_res_findfirst(list[i], VM_RES_TYPE_BTPDMS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTPDMS, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 10, 1, list[i]);
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 10, 2, resHandle);
                if (vm_pmng_set_ctx(list[i]) == VM_PMNG_OP_OK)
                {
                    ctx_p->data_to_read_notify_cb(bd_addr, buf, len);
                    vm_pmng_reset_ctx();
                }
            }
            vm_res_findclose(VM_RES_TYPE_BTPDMS);
        }	  
    }
    _vm_kernel_free(list);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 10, 3);
    return 0;
}

VMINT vm_pdms_read_data_request_internal_proc(VMINT8 *bd_addr, void* buf, VMUINT32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE *list = NULL;
    VMUINT num = 0;
    vm_btpdms_save_struct *ctx_p;
    VMINT i = 0;
           
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vm_pmng_get_process_list(NULL, &num);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 9, 0, num);
    if (0 == num)
    {
        return 0;
    }
    list = (VM_P_HANDLE *)_vm_kernel_calloc(sizeof(VM_P_HANDLE *) * num);
    vm_pmng_get_process_list(list, &num);
    for (i = 0; i < num; i++)
    {
        VMINT resHandle = 0;
        VMINT bufSize = 0;

        if ((resHandle = vm_res_findfirst(list[i], VM_RES_TYPE_BTPDMS)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTPDMS, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 9, 1, list[i]);
                MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 9, 2, resHandle);
                if (vm_pmng_set_ctx(list[i]) == VM_PMNG_OP_OK)
                {
                    ctx_p->read_data_request_cb(bd_addr, buf, len);
                    vm_pmng_reset_ctx();
                }
            }
            vm_res_findclose(VM_RES_TYPE_BTPDMS);
        }
    }
    _vm_kernel_free(list);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 9, 3);
    return 0;
}

void vm_btpdms_init_callback(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 8, 0);
    vm_pdms_internal_callback_t.connection_state_cb = vm_pdms_connection_state_internal_proc;
    vm_pdms_internal_callback_t.data_to_read_notify_cb = vm_pdms_data_to_read_internal_proc;
    vm_pdms_internal_callback_t.read_data_request_cb = vm_pdms_read_data_request_internal_proc;
    
    return;
}

VMINT vm_pdms_is_app_register(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0;
    VMINT bufSize = 0;
    VMINT result = 0;
    vm_btpdms_save_struct * ctx_p = NULL;
    
    if ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_BTPDMS)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 7, 0);
        if (vm_res_get_data(VM_RES_TYPE_BTPDMS, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 7, 1);
            result = 1;
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 7, 2);
            result = -1;
        }
        vm_res_findclose(VM_RES_TYPE_BTPDMS); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 7, 3);
    return result;
}

VMINT vm_pdms_init(vm_pdms_callback_t *cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VM_P_HANDLE phandle;
    VMINT result = 0;
    vm_btpdms_save_struct* btpdms_p;
    VMINT pdms_id;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((phandle = vm_pmng_get_app_handle()) == 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 6, 0);
        return VM_BT_PDMS_STATUS_ERROR;  		
    }
    
    if(g_is_init_register == -1)
    {
        vm_btpdms_init_callback();
        result = pdms_init((pdms_callback_t*)&vm_pdms_internal_callback_t);
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 6, 1, result);
        if(result == VM_BT_PDMS_STATUS_SUCCESS)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 6, 2);
            g_is_init_register = 1;
        }
        else
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 6, 3);
            result = -result;
            return result;
        }
    }
    
    if(vm_pdms_is_app_register(phandle) == 1)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 6, 4);
        return VM_BT_PDMS_STATUS_ERROR_OF_REGISTER;
    }
    
    if((btpdms_p = (vm_btpdms_save_struct *)_vm_kernel_malloc(sizeof(vm_btpdms_save_struct))) == NULL)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 6, 5);
		    return VM_BT_PDMS_STATUS_ERROR_OF_MEM;
    }

    btpdms_p->m_pHandle = phandle;
    btpdms_p->connection_state_cb = cb->connection_state_cb;
    btpdms_p->data_to_read_notify_cb = cb->data_to_read_notify_cb;
    btpdms_p->read_data_request_cb = cb->read_data_request_cb;
    
    if ((pdms_id = vm_res_save_data(VM_RES_TYPE_BTPDMS, (void *) btpdms_p, sizeof(vm_btpdms_save_struct), NULL, phandle)) < 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 6, 6);
        _vm_kernel_free(btpdms_p);
        return VM_BT_PDMS_STATUS_ERROR_OF_RES;
    }
    btpdms_p->m_nResid = pdms_id;
    g_ref_count++;
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 6, 7);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 6, 8, g_ref_count);
    return 0;
}

VMINT vm_pdms_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT resHandle = 0; 
    VMINT bufSize = 0;
    vm_btpdms_save_struct * ctx_p = NULL;
    VM_P_HANDLE curr_phandle = vm_pmng_get_app_handle();
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if((resHandle = vm_res_findfirst(curr_phandle, VM_RES_TYPE_BTPDMS)) != VM_RES_NOT_FIND)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 5, 0, resHandle);
        if (vm_res_get_data(VM_RES_TYPE_BTPDMS, resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
             _vm_kernel_free(ctx_p);
        }
        else
        {
             MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 5, 1);
        }
        
        if (vm_res_release_data(VM_RES_TYPE_BTPDMS, resHandle) < VM_RES_OK)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 5, 2);
            return VM_BT_PDMS_STATUS_ERROR;
        }
        vm_res_findclose(VM_RES_TYPE_BTPDMS); 
        g_ref_count--;
    }
    if(g_ref_count == 0)
    {
        VMINT return_value = 0;
        g_is_init_register = -1;
        return_value = pdms_deinit();
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 5, 3, return_value);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGM , 5, 4, g_ref_count);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 5, 5);
    return 0;
}

VMINT vm_pdms_send_data(VMINT8* bdaddr, void* buf, VMUINT32 len, VMINT *err_code)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    VMINT result = 0;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    result = pdms_send_data((char*)bdaddr,buf, (U32)len, (S32*)err_code);
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 4, result);
    return result;
}

static void vm_btpdms_notify_callback(VM_P_HANDLE process_handle, VMINT sys_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(sys_state)
    {
        case VM_PMNG_UNLOAD:
        if (vm_pmng_get_app_handle() == process_handle)
        {		
            MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 3, 0);	
            vm_pdms_deinit();			
        }
     		break;
     		
		    default:
        return;
    }
}

static void vm_btpdms_initial(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 2, 0);
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTPDMS, vm_btpdms_notify_callback);
}

static void vm_btpdms_finialize(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 1, 0);
    vm_pdms_deinit();
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTPDMS, NULL);
}

static VMINT vm_btpdms_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
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
            vm_btpdms_initial();
            break;
        case EVT_MOD_RELEASE:
            vm_btpdms_finialize();
            break;
    }
    return 0;
}

VMINT _vm_reg_btpdms_module(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int res = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if ((res = _vm_reg_module("btpdm MODULE", (MOD_EVT_PROCESS) vm_btpdms_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGE , 0, res);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_BTPDMS, TRC_MRE_BTPDMS_LOGS , 0, res);
    return res;
}

#endif /* __MRE_BT_PDMS__ */
