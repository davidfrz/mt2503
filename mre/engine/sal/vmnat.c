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
*
 * removed!
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "mmi_features.h"
//#ifdef WIN32
//#include "O:\\plutommi\\Framework\\RouterCtrl\\inc\\router_ctrl.h"


//#else
#include "router_ctrl.h"
//#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "vmswitch.h"

#ifdef __MRE_SAL_NAT__
#include "mmi_trc.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmnat.h"

//#include "vmsys.h"

typedef struct
{
    VM_P_HANDLE p_hdl;
    VMINT res_id;
    vm_upnp_result_cb cb;
    void *user_data;
    VMUINT idx;

    //VMUINT8 req_id;
}vm_nat_ctx_t;

static void vm_nat_free_ctx(vm_nat_ctx_t * ctx_p);
static vm_nat_ctx_t * vm_nat_malloc_ctx(void);
static vm_nat_ctx_t * vm_nat_get_ctx(VMUINT idx);

static void vm_nat_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_nat_ctx_t * ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_NAT)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_NAT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            vm_nat_free_ctx(ctx_p);
            //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_117 );
        }
        else
        {
            //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_121 );
        }
        vm_res_release_data(VM_RES_TYPE_NAT, resHandle);
        vm_res_findclose(VM_RES_TYPE_NAT); 
    }

}

static void vm_nat_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_106 );
    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_nat_free_resource(process_handle);
        break;
    }
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_128 );
}


static VMINT vm_nat_initialize_resource(void)
{
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_134 );
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_NAT, 
        vm_nat_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_142 );


    return 0;
}

static VMINT vm_nat_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_nat_ctx_t* ctx_p = NULL;

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_153 );
    vm_nat_free_resource(-1);

    
    vm_res_type_set_notify_callback(VM_RES_TYPE_NAT, NULL);

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_174 );
    ///TODO: Deregister WPS relate functions

    return 0;
}

static VMINT vm_nat_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_nat_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_nat_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_196 , event);
        return -2;
    }

    return 0;
}

VMINT _vm_reg_nat_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_207 );
    if ((res_code = _vm_reg_module("NAT MODULE", (MOD_EVT_PROCESS)vm_nat_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_210 , res_code);
    }

    //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMnat_213 );
    return res_code;
}

static vm_nat_ctx_t * vm_nat_get_ctx(VMUINT idx)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_nat_ctx_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_NAT)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_NAT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->idx == idx)
            {
                vm_res_findclose(VM_RES_TYPE_NAT);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_NAT)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_NAT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->idx == idx)
                {
                    vm_res_findclose(VM_RES_TYPE_NAT);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_NAT);
    }	
    return NULL;
}


static vm_nat_ctx_t * vm_nat_malloc_ctx(void)
{
    vm_nat_ctx_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_nat_ctx_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_NAT, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            ctx_p->idx = (VMUINT)ctx_p;
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

static void vm_nat_free_ctx(vm_nat_ctx_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_NAT, ctx_p->res_id);
        _vm_kernel_free(ctx_p);
    }
}


static void vm_upnp_result_int_cb(kal_uint8  request_id, kal_int32 ret, void* res_data, void* user_data)
{
    vm_nat_ctx_t *ctx_p = (vm_nat_ctx_t *)user_data;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_S, 3, __LINE__);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E1, 3, __LINE__);
        return;
    }

    ctx_p = vm_nat_get_ctx((VMUINT)user_data);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E2, 3, __LINE__);
        return;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_LOG, 
        request_id,
        ret,
        0,
        ctx_p->res_id,
        ctx_p->p_hdl,
        ctx_p->idx,
        3, __LINE__);
    
    PMNG_WRAP_CALLBACK(ctx_p->p_hdl, ctx_p->cb(request_id, ret, res_data, ctx_p->user_data));

    vm_nat_free_ctx(ctx_p);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E, 3, __LINE__);
}

VMINT vm_upnp_mapping_ports(VMUINT8  request_id, vm_upnp_result_cb cb, vm_upnp_map_info* request_data, void* user_data)
{
    vm_nat_ctx_t *ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_S, 1, __LINE__);

    if (NULL == cb || NULL == request_data)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E1, 1, __LINE__);
        return -2;
    }

    ctx_p = vm_nat_malloc_ctx();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E2, 1, __LINE__);
        return -3;
    }
    
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->cb = cb;
    ctx_p->user_data = user_data;
    //ctx_p->req_id = request_id;
    

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_LOG, 
        request_id,
        request_data->count,
        0,
        ctx_p->res_id,
        ctx_p->p_hdl,
        ctx_p->idx,
        1, __LINE__);
        
    mmi_frm_mapping_ports((kal_uint8)request_id, vm_upnp_result_int_cb, (upnp_map_info *)request_data, (void *)ctx_p);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E, 1, __LINE__);
    return 0;
}

VMINT vm_upnp_get_ext_ip(VMUINT8  request_id, vm_upnp_result_cb cb, void *user_data)
{
    vm_nat_ctx_t *ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_S, 2, __LINE__);
    if (NULL == cb)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E1, 2, __LINE__);
        return -2;
    }
    
    ctx_p = vm_nat_malloc_ctx();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E2, 2, __LINE__);
        return -3;
    }
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->cb = cb;
    ctx_p->user_data = user_data;
    //ctx_p->req_id = request_id;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_LOG, 
        request_id,
        0,
        0,
        ctx_p->res_id,
        ctx_p->p_hdl,
        ctx_p->idx,
        2, __LINE__);

    mmi_frm_get_ext_ip((kal_uint8)request_id, vm_upnp_result_int_cb, (void *)ctx_p);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_NAT_E, 2, __LINE__);
    return 0;
}

VMINT vm_get_nat_sym(VMCHAR* func_name )
{
    if(strcmp(func_name, "vm_upnp_mapping_ports") == 0)
        return (VMINT)vm_upnp_mapping_ports;        
    if(strcmp(func_name, "vm_upnp_get_ext_ip") == 0)
        return (VMINT)vm_upnp_get_ext_ip;   

    return 0;
}

#endif

