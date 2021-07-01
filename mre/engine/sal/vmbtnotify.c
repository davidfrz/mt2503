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
 * vmpromng.c
 *
 * Project:
 * --------
 *   MAUI
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
 * removed!
 *
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"
#include "BTNotiSrvGprot.h"

#include "vmswitch.h"

#ifdef __MRE_SAL_BTNOTIFY__
#include "vmbtnotify.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"
#include "vmbtcm.h"

extern void _vm_trace(char* fmt, ...);

#ifdef WIN32
#define vm_trace _vm_trace
#else
#define vm_trace(...) _vm_trace(__VA_ARGS__)
#endif

typedef struct
{
    VM_P_HANDLE p_hdl;
    VMINT res_id;
    //VMINT conn_id[MAX_MRE_SPP_CLIENT];
    //VMINT is_connected;
    //void (*cb)(VMUINT evt, void * param, void * user_data);
    VMCHAR sender[VM_MAX_IOER];
    void (*cb)(vm_srv_bt_noti_callback_struct *data);
    vm_srv_bt_cm_bt_addr bt_addr;
    //void * user_data;
}vm_btnotify_context_t;

static void vm_btnotify_free_ctx(vm_btnotify_context_t * ctx_p);
static vm_btnotify_context_t * vm_btnotify_malloc_ctx(void);
static vm_btnotify_context_t * vm_btnotify_get_ctx(const VMCHAR ioer[VM_MAX_IOER]);
static S32 vm_btnotify_notifier_cb(U32 evt, void* para);

static void vm_btnotify_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btnotify_context_t * ctx_p = NULL;
    
    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_NOTIFY)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            //vm_btnotify_close(ctx_p->srv_hd);
        }
        else
        {
        }
        vm_res_release_data(VM_RES_TYPE_NOTIFY, resHandle);
        vm_res_findclose(VM_RES_TYPE_NOTIFY); 
    }

}


static void vm_btnotify_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btnotify_context_t * ctx_p = NULL;

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_btnotify_free_resource(process_handle);
        break;
    }
}


static VMINT vm_btnotify_initialize_resource(void)
{
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_NOTIFY, 
        vm_btnotify_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.


    return 0;
}

static VMINT vm_btnotify_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btnotify_context_t* ctx_p = NULL;

    vm_btnotify_free_resource(-1);
    
    vm_res_type_set_notify_callback(VM_RES_TYPE_NOTIFY, NULL);


    return 0;
}

static VMINT vm_btnotify_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_btnotify_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_btnotify_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        //MMI_TRACE(MMI_MRE_TRC_MOD_VMBTSPP, TRC_MRE_VMBTSPP_210 , event);
        return -2;
    }

    return 0;
}

VMINT _vm_reg_btnotify_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("BTNTF MODULE", (MOD_EVT_PROCESS)vm_btnotify_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}

static vm_btnotify_context_t * vm_btnotify_get_ctx(const VMCHAR ioer[VM_MAX_IOER])
{
    
    VMINT resHandle = 0, bufSize = 0;
    vm_btnotify_context_t * ctx_p = NULL;
    VMINT i = 0;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
        
            if (0 == strcmp(ctx_p->sender, ioer))
            {
                vm_res_findclose(VM_RES_TYPE_NOTIFY);
                return ctx_p;
            }

        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (0 == strcmp(ctx_p->sender, ioer))
                {
                    vm_res_findclose(VM_RES_TYPE_NOTIFY);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_NOTIFY);
    }	
    return NULL;
}

static vm_btnotify_context_t * vm_btnotify_get_ctx_by_cb(void *cb)
{
    
    VMINT resHandle = 0, bufSize = 0;
    vm_btnotify_context_t * ctx_p = NULL;
    VMINT i = 0;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
        
            if (cb == ctx_p->cb)
            {
                vm_res_findclose(VM_RES_TYPE_NOTIFY);
                return ctx_p;
            }

        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (cb == ctx_p->cb)
                {
                    vm_res_findclose(VM_RES_TYPE_NOTIFY);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_NOTIFY);
    }	
    return NULL;
}

static vm_btnotify_context_t * vm_btnotify_malloc_ctx(void)
{
    vm_btnotify_context_t * ctx_p = NULL;

    if ((ctx_p = _vm_kernel_calloc(sizeof(vm_btnotify_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_NOTIFY, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            return ctx_p;
        }
        else
        {
            _vm_kernel_free(ctx_p);
        }
    }

    return NULL;
}

static void vm_btnotify_free_ctx(vm_btnotify_context_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_NOTIFY, ctx_p->res_id);
        _vm_kernel_free(ctx_p);
    }
}

static void vm_srv_bt_noti_int_cb(void *data)
{
    srv_bt_noti_mre_callback_struct *param = (srv_bt_noti_mre_callback_struct *)data;
    vm_srv_bt_noti_callback_struct noti = {0};
    vm_btnotify_context_t *ctx_p;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 3, __LINE__);
    if (NULL == param)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 3, __LINE__);
        return;
    }


    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, param->err_code, __LINE__);
    
    noti.bt_addr.lap = param->bt_addr.lap;
    noti.bt_addr.nap = param->bt_addr.nap;
    noti.bt_addr.uap = param->bt_addr.uap;
    

    if (SRV_BT_NOTIFY_RET_LINK_DISCONNECTED == param->err_code)
    {
        VMUINT i = 0;
        VM_P_HANDLE *list = NULL;
        VMUINT num = 0;
        vm_pmng_get_process_list(NULL, &num);
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 330, num);

        if (0 == num)
        {
            return;
        }
        list = (VM_P_HANDLE *)_vm_kernel_calloc(sizeof(VM_P_HANDLE *) * num);
        vm_pmng_get_process_list(list, &num);

        noti.err_code = VM_SRV_BT_NOTIFY_RET_LINK_DISCONNECTED;
        for (i = 0; i < num; i++)
        {
            VMINT resHandle = 0, bufSize = 0;

            if ((resHandle = vm_res_findfirst(list[i], VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
            {
                if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
                    resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
                {
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 331, __LINE__);
                    PMNG_WRAP_CALLBACK(list[i], ctx_p->cb(&noti));
                }

                while ((resHandle = vm_res_findnext(list[i], VM_RES_TYPE_NOTIFY)) != VM_RES_NOT_FIND)
                {
                    if (vm_res_get_data(VM_RES_TYPE_NOTIFY, 
                    resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
                    {
                        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 332, __LINE__);
                        PMNG_WRAP_CALLBACK(list[i], ctx_p->cb(&noti));
                    }
                }
                vm_res_findclose(VM_RES_TYPE_NOTIFY);
            }	  
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_LOG, 3, 
                noti.err_code, 
                param->data_type, 
                noti.bt_addr.lap, 
                noti.bt_addr.nap, 
                noti.bt_addr.uap, 
                param->sender_id, 
                33, __LINE__);

        _vm_kernel_free(list);
                
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 3, __LINE__);
        return;
    }

    ctx_p = vm_btnotify_get_ctx(param->sender_id);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E2, 3, __LINE__);
        return;
    }
    memcpy(noti.sender, param->sender_id, VM_MAX_IOER);
    noti.err_code = param->err_code;
    noti.data_type = param->data_type;    
    memcpy(noti.receiver, param->receiver_id, VM_MAX_IOER);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_LOG, 3, 
            noti.err_code, 
            noti.data_type, 
            0, 
            0, 
            0, 
            param->sender_id, 
            3, __LINE__);
    switch (param->data_type)
    {
    case SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER:
        {
            noti.data.buffer.len = param->data.buffer.len;
            memcpy(noti.data.buffer.buf, param->data.buffer.data, VM_BT_NOTIFY_MRE_MAX_DATA_LENTH);
        }break;
    case SRV_BT_NOTI_MRE_DATA_TYPE_FILE:
        {
            memcpy(noti.data.file_path, param->data.file_path, 2 * VM_BT_NOTIFY_MRE_FILE_NAME_LENTH);
        }break;
    default:

        return;
        break;
    }

    ctx_p->bt_addr.lap = param->bt_addr.lap;
    ctx_p->bt_addr.nap = param->bt_addr.nap;
    ctx_p->bt_addr.uap = param->bt_addr.uap;
    
    PMNG_WRAP_CALLBACK(ctx_p->p_hdl, ctx_p->cb(&noti));
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 3, __LINE__);

}

VMINT vm_srv_bt_noti_check_connection(void)
{
    MMI_BOOL ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 4, __LINE__);
    ret = srv_bt_noti_check_connection();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, ret, __LINE__);
    return ret ? 0 : -2;
}

VMINT vm_srv_bt_noti_register_callback(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], vm_srv_bt_noti_callback cb)
{
    vm_btnotify_context_t *ctx_p;
    srv_bt_cm_bt_addr bt_int = {0};

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 2, __LINE__);
    if (NULL == cb || NULL == sender)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 2, __LINE__);
        return -2;
    }
    
    ctx_p = vm_btnotify_get_ctx(sender);
    if (NULL == ctx_p)
    {
        ctx_p = vm_btnotify_malloc_ctx();
        if (NULL == ctx_p)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E2, 2, __LINE__);
            return -3;
        }
    }
    
    memcpy(ctx_p->sender, sender, VM_MAX_IOER);    
    ctx_p->p_hdl = vm_pmng_get_current_handle();
    ctx_p->cb = cb;

    if (bt_addr)
    {
        bt_int.lap = bt_addr->lap;
        bt_int.nap = bt_addr->nap;
        bt_int.uap = bt_addr->uap;
        ctx_p->bt_addr.lap = bt_addr->lap;
        ctx_p->bt_addr.nap = bt_addr->nap;
        ctx_p->bt_addr.uap = bt_addr->uap;
        srv_bt_noti_register_mre_callback(&bt_int, vm_srv_bt_noti_int_cb);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 2, __LINE__);
    }
    else
    {
        srv_bt_noti_register_mre_callback(NULL, vm_srv_bt_noti_int_cb);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E4, 2, __LINE__);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, ctx_p->res_id, __LINE__);
    return ctx_p->res_id;
}

VMINT vm_srv_bt_noti_send_cmd_ext(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len)
{
    
    return vm_srv_bt_noti_send_ex(bt_addr, sender, sender, data_type, data, len);
}

VMINT vm_srv_bt_noti_send_ex(const vm_srv_bt_cm_bt_addr *bt_addr, const VMCHAR sender[VM_MAX_IOER], const VMCHAR receiver[VM_MAX_IOER], VMINT data_type, const VMBYTE *data, VMINT len)
{
    
    vm_btnotify_context_t *ctx_p;
    char *buf, str_len[8] = {0};
    srv_bt_cm_bt_addr bt_int = {0};
    VMINT total;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 1, __LINE__);
    if (NULL == sender || NULL == data || len == 0 || 
        (VM_SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER != data_type && VM_SRV_BT_NOTI_MRE_DATA_TYPE_FILE != data_type) || 
        !bt_addr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 1, __LINE__);
        return -2;
    }
    ctx_p = vm_btnotify_get_ctx(sender);
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E2, 1, __LINE__);
        return -3;
    }

    //itoa(len, str_len, 10);
    //total = 4 + strlen(sender) + 1 + strlen(str_len) + len + 4;
    
    //MREE sender_id data_type data_len data 

    buf = vm_calloc(VM_BT_NOTIFY_MRE_MAX_DATA_LENTH);
    sprintf((char*)buf, "%s %s %s %d %d ", "MREE", sender, receiver, data_type, len); 
    total = strlen(buf) + len;
    if (total > VM_BT_NOTIFY_MRE_MAX_DATA_LENTH)
    {
        vm_free(buf);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E3, 1, __LINE__);
        return -4;
    }

    memcpy(buf + strlen(buf), data, len);
    bt_int.lap = bt_addr->lap;
    bt_int.nap = bt_addr->nap;
    bt_int.uap = bt_addr->uap;
    
    if (!srv_bt_noti_send_cmd_ext(&bt_int, "MREE", buf + 5, total - 5))
    {           
        vm_free(buf);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E4, 1, __LINE__);
        return -5;
    }
    
    vm_free(buf);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 1, __LINE__);
    return 0;
}

VMINT vm_bt_noti_check_channel_valid(VMINT cntx_chnl)
{
    MMI_BOOL ret = srv_bt_noti_check_channel_valid((S32)cntx_chnl);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 5, __LINE__);
    if (ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 5, __LINE__);
        return 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 5, __LINE__);
        return -2;
    }
}


VMINT vm_bt_noti_get_bt_device_addr(VMINT cntx_chnl, vm_srv_bt_cm_bt_addr *bt_addr)
{
    srv_bt_cm_bt_addr *int_bt_addr;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 6, __LINE__);
    if (NULL == bt_addr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 6, __LINE__);
        return -2;
    }

    int_bt_addr = srv_bt_noti_get_bt_device_addr((U8)cntx_chnl);
    if (NULL == int_bt_addr)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E2, 6, __LINE__);
        return -3;
    }

    bt_addr->lap = int_bt_addr->lap;
    bt_addr->nap = int_bt_addr->nap;
    bt_addr->uap = int_bt_addr->uap;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 6, __LINE__);
    return 0;
    
}


VMINT vm_bt_noti_deregister_callback(vm_srv_bt_cm_bt_addr *bt_addr, vm_srv_bt_noti_callback cb_ptr)
{
    VMINT ret = 1;
    
    vm_btnotify_context_t *ctx_p;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 7, __LINE__);
    
    ctx_p = vm_btnotify_get_ctx_by_cb((void *)cb_ptr);
    if (!ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E1, 7, cb_ptr);
        return -3;
    }
    
    //ret = srv_bt_noti_deregister_callback((srv_bt_cm_bt_addr *)bt_addr, (srv_bt_noti_callback)cb_ptr);
    if (ret)
    {
        vm_btnotify_free_ctx(ctx_p);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E2, 7, ret);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 7, ret);
    return ret ? 0 : -2;
}

VMINT vm_get_btnotify_sym(VMCHAR* func_name)
{
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_S, 11, __LINE__);
    
    if(strcmp(func_name,"vm_srv_bt_noti_check_connection") == 0)
        return (VMINT)vm_srv_bt_noti_check_connection;
    if(strcmp(func_name,"vm_srv_bt_noti_register_mre_callback") == 0)
        return (VMINT)vm_srv_bt_noti_register_callback;        
    if(strcmp(func_name,"vm_srv_bt_noti_register_callback") == 0)
        return (VMINT)vm_srv_bt_noti_register_callback;        
    if(strcmp(func_name,"vm_srv_bt_noti_send_cmd_ext") == 0)
        return (VMINT)vm_srv_bt_noti_send_cmd_ext;
    if(strcmp(func_name,"vm_srv_bt_noti_send_ex") == 0)
        return (VMINT)vm_srv_bt_noti_send_ex;
    
    if(strcmp(func_name,"vm_bt_noti_get_bt_device_addr") == 0)
        return (VMINT)vm_bt_noti_get_bt_device_addr;
    if(strcmp(func_name,"vm_bt_noti_check_channel_valid") == 0)
        return (VMINT)vm_bt_noti_check_channel_valid;

    if(strcmp(func_name,"vm_bt_noti_deregister_callback") == 0)
        return (VMINT)vm_bt_noti_deregister_callback;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_BTNTF_E, 11, __LINE__);
    return 0;

    
}


#endif /* __MRE_SAL_BTNOTIFY__ */


