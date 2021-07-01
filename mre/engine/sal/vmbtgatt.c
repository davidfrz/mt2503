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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/
#include "mmi_features.h"

#include "GattsSrv.h"
#include "GattcSrv.h"

#include "vmswitch.h"
#ifdef __MRE_SAL_BTGATT__






#include "vmbtgatt.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmlog.h"
#include "mmi_trc.h"


typedef struct _vm_node_t vm_node_t;
struct _vm_node_t
{
    VMUINT idx; // service handle
    void *user_data;
    vm_node_t *next;
};


typedef struct
{
    VMINT res_id;
    VM_P_HANDLE p_hdl;
    vm_gatts_callback_struct s_cb;
    vm_gattc_callback_struct c_cb;
    
    void *reg_ctx;
    void *conn_ctx;
    bt_uuid_struct uuid;
    
    vm_node_t *head;
    vm_gatts_factory_callback_struct s_fac_cb;
}vm_btgatt_context_t;

static void vm_btgatt_free_ctx(vm_btgatt_context_t * ctx_p);
static vm_btgatt_context_t * vm_btgatt_malloc_ctx(void);
static vm_btgatt_context_t * vm_btgatt_get_ctx(void *reg_ctx);
static vm_btgatt_context_t * vm_btgatt_get_ctx_by_uuid(bt_uuid_struct *uuid);
static vm_btgatt_context_t * vm_btgatt_get_ctx_sub_node(VMUINT idx);

static void vm_btgatt_notifier_cb(U32 event, void* para);


static vm_node_t *vm_list_int_alloc(vm_btgatt_context_t *ctx_p)
{
    vm_node_t *client;
    vm_node_t *tmp;
    if (NULL == ctx_p)
        return NULL;

	client = _vm_kernel_calloc(sizeof(vm_node_t));
	if (NULL == client)
	    return NULL;

    client->idx = 0;//(VMUINT)client;
    client->next = NULL;
    client->user_data= NULL;
    
    tmp = ctx_p->head;
    if (NULL == tmp)
    {
        ctx_p->head = client;
        return client;
    }
    
    while (tmp->next)
    {
        tmp = tmp->next;
        
    }

    tmp->next = client;
    
     
    return client;
}

static void vm_list_int_free(vm_btgatt_context_t *ctx_p, VMUINT idx)
{
    vm_node_t *p, *q;
    if (NULL == ctx_p || 0 >= idx)
        return;

    p = ctx_p->head;
    if (NULL == p)
    {
        return;    
    }
    else
    {
        if (p->idx == idx)
        {
            ctx_p->head = p->next;
            _vm_kernel_free(p);
            return;
        }
    }

    q = p->next;
    while (q)
    {
        if (idx == q->idx)
        {
            p->next = q->next;
            _vm_kernel_free(q);
            return;   
        }
        p = q;
        q = q->next;
    }
    
}

static void vm_list_int_release_all(vm_btgatt_context_t *ctx_p)
{
    vm_node_t *tmp;
    if (NULL == ctx_p)
    {
        return;
    }

    tmp = ctx_p->head;
    if (NULL == tmp)
        return;
    
    while (tmp)
    {
        ctx_p->head = tmp->next;
        _vm_kernel_free(tmp);
        tmp = ctx_p->head;
    }


    
}

static vm_node_t * vm_list_int_get(vm_btgatt_context_t *ctx_p, VMUINT idx)
{
    vm_node_t *tmp;
    if (NULL == ctx_p || 0 >= idx)
        return NULL;

    tmp = ctx_p->head;
    while (tmp)
    {
        if (tmp->idx == idx)
            return tmp;
        tmp = tmp->next;
    }
    return NULL;
}



static void vm_btgatt_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btgatt_context_t * ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_BTGATT)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            //vm_btgatt_exit(ctx_p->res_id);
            vm_btgatt_free_ctx(ctx_p);
        }
        else
        {
        }
        //vm_res_release_data(VM_RES_TYPE_BTGATT, resHandle);
        vm_res_findclose(VM_RES_TYPE_BTGATT); 
    }

}

static void vm_btgatt_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_btgatt_free_resource(process_handle);
        break;
    }
}


static VMINT vm_btgatt_initialize_resource(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_134 );
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_BTGATT, 
        vm_btgatt_notify_process_status) != 0)
    {
        return -1;
    }

    ///TODO: other init.


    return 0;
}

static VMINT vm_btgatt_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btgatt_context_t* ctx_p = NULL;

    vm_btgatt_free_resource(-1);

    
    vm_res_type_set_notify_callback(VM_RES_TYPE_BTGATT, NULL);

    ///TODO: Deregister WPS relate functions

    return 0;
}

static VMINT vm_btgatt_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_btgatt_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_btgatt_finialize_resource();
        break;
    case EVT_MOD_ACTIVE:
        break;
    case EVT_MOD_INACTIVE:
        break;
    default:
        return -2;
    }

    return 0;
}

VMINT _vm_reg_btgatt_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("GATT MODULE", (MOD_EVT_PROCESS)vm_btgatt_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}

static vm_btgatt_context_t * vm_btgatt_get_ctx(void *reg_ctx)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btgatt_context_t * ctx_p = NULL;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (ctx_p->reg_ctx == reg_ctx)
            {
                vm_res_findclose(VM_RES_TYPE_BTGATT);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (ctx_p->reg_ctx == reg_ctx)
                {
                    vm_res_findclose(VM_RES_TYPE_BTGATT);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_BTGATT);
    }	
    return NULL;
}

static vm_btgatt_context_t * vm_btgatt_get_ctx_sub_node(VMUINT idx)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btgatt_context_t * ctx_p = NULL;
    vm_node_t *node;

    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            node = vm_list_int_get(ctx_p, idx);
            if (NULL != node)
            {
                vm_res_findclose(VM_RES_TYPE_BTGATT);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                node = vm_list_int_get(ctx_p, idx);
                if (NULL != node)
                {
                    vm_res_findclose(VM_RES_TYPE_BTGATT);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_BTGATT);
    }	
    return NULL;
}

static vm_btgatt_context_t * vm_btgatt_get_ctx_by_uuid(bt_uuid_struct *uuid)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_btgatt_context_t * ctx_p = NULL;
    ASSERT(uuid != NULL);
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (0 == memcmp(uuid->uu, ctx_p->uuid.uu, 16))
            {
                vm_res_findclose(VM_RES_TYPE_BTGATT);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_BTGATT)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_BTGATT, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (0 == memcmp(uuid->uu, ctx_p->uuid.uu, 16))
                {
                    vm_res_findclose(VM_RES_TYPE_BTGATT);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_BTGATT);
    }   
    return NULL;
}


static vm_btgatt_context_t * vm_btgatt_malloc_ctx(void)
{
    vm_btgatt_context_t * ctx_p = NULL;

    if ((ctx_p = vm_calloc(sizeof(vm_btgatt_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_BTGATT, 
            (void*)ctx_p, sizeof(ctx_p), NULL, vm_pmng_get_current_handle())) >= 0)
        {
            ctx_p->p_hdl = vm_pmng_get_current_handle();
            return ctx_p;
        }
        else
        {
            vm_free(ctx_p);
        }
    }

    return NULL;
}

static void vm_btgatt_free_ctx(vm_btgatt_context_t * ctx_p)
{
    if (ctx_p)
    {
        //vm_res_release_data(VM_RES_TYPE_BTGATT, ctx_p->res_id);
        if (VM_RES_OK == vm_res_release_data(VM_RES_TYPE_BTGATT, ctx_p->res_id))
        {
            vm_list_int_release_all(ctx_p);
            vm_free(ctx_p);
        }
    }
}



/** Callback invoked in response to register */
void ms_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);

/** Callback indicating that a remote device has connected or been disconnected */
void ms_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);

/** Callback triggered in response to listen */
void ms_listen_callback(void *reg_ctx, OS_STATUS status);

/** Callback invoked in response to create_service */
void ms_service_added_callback(OS_STATUS status, void *reg_ctx,
                GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle);

/** Callback indicating that an included service has been added to a service */
void ms_included_service_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_HANDLE srvc_handle, ATT_HANDLE incl_srvc_handle);

/** Callback invoked when a characteristic has been added to a service */
void ms_characteristic_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle);

/** Callback invoked when a descriptor has been added to a characteristic */
void ms_descriptor_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE descr_handle);

/** Callback invoked in response to start_service */
void ms_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/** Callback invoked in response to stop_service */
void ms_service_stopped_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/** Callback triggered when a service has been deleted */
void ms_service_deleted_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

/**
 * Callback invoked when a remote device has requested to read a characteristic
 * or descriptor. The application must respond by calling send_response
 */
void ms_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);

/**
 * Callback invoked when a remote device has requested to write to a
 * characteristic or descriptor.
 */
void ms_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);

/** Callback invoked when a previously prepared write is to be executed */
void ms_request_exec_write_callback(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel);

/**
 * Callback triggered in response to send_response if the remote device
 * sends a confirmation.
 */
void ms_response_confirmation_callback(OS_STATUS status, ATT_HANDLE handle);

/** Callback triggered in response to read_tx_power */
void ms_read_tx_power_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power);

/** Callback indicating that a remote device has connected or been disconnected */
void ms_connection_ext_callback(gattsrv_conn_struct *conn);










/** Callback invoked in response to register */
void mc_register_client_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);

/** Callback for scan results */
void mc_scan_result_callback(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir);

/** Callback indicating that a remote device has connected or been disconnected */
void mc_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);

/** Callback triggered in response to listen */
void mc_listen_callback(void *reg_ctx, OS_STATUS status);

/** Callback triggered in response to set_adv_data */
void mc_set_adv_data_callback(void *reg_ctx, OS_STATUS status);

/**
 * Invoked in response to search_service when the GATT service search
 * has been completed.
 */
void mc_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status);

/** Reports GATT services on a remote device */
void mc_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid);

/** GATT characteristic enumeration result callback */
void mc_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch, GATT_CHAR_PROPERTIES properties);

/** GATT descriptor enumeration result callback */
void mc_get_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr);

/** GATT included service enumeration result callback */
void mc_get_included_service_callback(gatt_conn_struct *conn, OS_STATUS status,
                                GATT_SVC_UUID *svc_uuid, GATT_SVC_UUID *incl_svc_uuid);

/** Callback invoked in response to [de]register_for_notification */
void mc_register_for_notification_callback(void *reg_ctx, OS_STATUS status, 
                                BD_ADDR *bd_addr, gattc_char_struct *ch);

/**
 * Remote device notification callback, invoked when a remote device sends
 * a notification or indication that a client has registered for.
 */
void mc_notify_callback(gatt_conn_struct *conn, BD_ADDR *bd_addr,
                                gattc_char_struct *ch, ATT_VALUE *value, BOOL is_notify);

/** Reports result of a GATT read operation */
void mc_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch, ATT_VALUE *value);

/** GATT write characteristic operation callback */
void mc_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch);

/** Callback invoked in response to read_descriptor */
void mc_read_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr, ATT_VALUE *value);                                

/** Callback invoked in response to write_descriptor */
void mc_write_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr);    

/** GATT execute prepared write callback */
void mc_execute_write_callback(gatt_conn_struct *conn, OS_STATUS status);

/** Callback triggered in response to read_remote_rssi */
void mc_read_remote_rssi_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi);

/** Callback triggered in response to get_device_type */
void mc_get_device_type_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, GATTC_DEV_TYPE dev_type);

/** Callback indicating that a remote device has connected or been disconnected */
void mc_connection_ext_callback(gattsrv_conn_struct *conn);

/** Callback triggered in response to service change */
void mc_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);



static gattc_callback_struct client_callback = {
    mc_register_client_callback,
    mc_scan_result_callback,
    mc_connection_callback,
    mc_listen_callback,
    mc_set_adv_data_callback,
    mc_search_complete_callback,
    mc_search_result_callback,
    mc_get_characteristic_callback,
    mc_get_descriptor_callback,
    mc_get_included_service_callback,
    mc_register_for_notification_callback,
    mc_notify_callback,
    mc_read_characteristic_callback,
    mc_write_characteristic_callback,
    mc_read_descriptor_callback,                                
    mc_write_descriptor_callback,    
    mc_execute_write_callback,
    mc_read_remote_rssi_callback,
    mc_get_device_type_callback,
    NULL,
    mc_research_service_callback,
    mc_connection_ext_callback
};



static gatts_callback_struct server_callback = {
    ms_register_server_callback,
    ms_connection_callback,
    ms_listen_callback,
    ms_service_added_callback,
    ms_included_service_added_callback,
    ms_characteristic_added_callback,
    ms_descriptor_added_callback,
    ms_service_started_callback,
    ms_service_stopped_callback,
    ms_service_deleted_callback,
    ms_request_read_callback,
    ms_request_write_callback,
    ms_request_exec_write_callback,
    ms_response_confirmation_callback,
    ms_read_tx_power_callback,
    NULL,
    ms_connection_ext_callback
};

VMINT vm_gatts_register(vm_bt_uuid_struct *uuid, vm_gatts_callback_struct *callback)
{
    vm_btgatt_context_t *ctx;
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 0, __LINE__);
    if (NULL == uuid || NULL == callback)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 0, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_malloc_ctx();
    if (!ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 0, __LINE__);
        return -3;
    }    
    ctx->s_cb.register_server_cb = callback->register_server_cb;
    ctx->s_cb.connection_cb = callback->connection_cb;
    ctx->s_cb.listen_cb = callback->listen_cb;
    ctx->s_cb.service_added_cb = callback->service_added_cb;
    ctx->s_cb.included_service_added_cb = callback->included_service_added_cb;
    ctx->s_cb.characteristic_added_cb = callback->characteristic_added_cb;
    ctx->s_cb.descriptor_added_cb = callback->descriptor_added_cb;
    ctx->s_cb.service_started_cb = callback->service_started_cb;
    ctx->s_cb.service_stopped_cb = callback->service_stopped_cb;
    ctx->s_cb.service_deleted_cb = callback->service_deleted_cb;
    ctx->s_cb.request_read_cb = callback->request_read_cb;
    ctx->s_cb.request_write_cb = callback->request_write_cb;
    ctx->s_cb.request_exec_write_cb = callback->request_exec_write_cb;
    ctx->s_cb.response_confirmation_cb = callback->response_confirmation_cb;
    ctx->s_cb.read_tx_power_cb = callback->read_tx_power_cb;
    ctx->s_cb.connection_ext_cb = callback->connection_ext_cb;

    memcpy(ctx->uuid.uu, uuid->uu, 16);

    srv_gatts_register((bt_uuid_struct *)uuid, &server_callback);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 0, __LINE__);
    return 0;
}

VMINT vm_gatts_deregister(void *reg_ctx)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 1, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 1, __LINE__);
        return -2;
    }
        
    srv_gatts_deregister(ctx->reg_ctx);

    vm_btgatt_free_ctx(ctx);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 1, __LINE__);
    return 0;
}

VMINT vm_gatts_connect(void *reg_ctx, VM_BD_ADDR *bd_addr, VMBOOL direct)
{
    
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 2, __LINE__);

    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 2, __LINE__);
        return -2;
    }

    if (NULL == bd_addr)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 2, __LINE__);
        return -3;
    }
    

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[1],
        bd_addr->addr[2],
        bd_addr->addr[3],
        bd_addr->addr[4],
        bd_addr->addr[5],
        2, __LINE__);

    srv_gatts_connect(ctx->reg_ctx, (BD_ADDR *)bd_addr, (BOOL)direct);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 2, __LINE__);
    return 0;
}
VMINT vm_gatts_disconnect(vm_gatt_conn_struct *conn, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx;
    gatt_conn_struct conn_int;

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 3, __LINE__);
    if (NULL == conn || NULL == bd_addr)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 3, __LINE__);
        return -3;
    }    
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 3, __LINE__);
        return -2;
    }
    conn_int.conn_ctx = conn->conn_ctx;
    conn_int.reg_ctx = conn->reg_ctx;
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[1],
        bd_addr->addr[2],
        bd_addr->addr[3],
        bd_addr->addr[4],
        bd_addr->addr[5],
        3, __LINE__);

    srv_gatts_disconnect(&conn_int, (BD_ADDR *)bd_addr);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 3, __LINE__);
    return 0;
}

VMINT vm_gatts_listen(void *reg_ctx, VMBOOL start)
{
    vm_btgatt_context_t *ctx;
    gatt_conn_struct conn_int;

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 11, __LINE__);
    if (NULL == reg_ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 11, __LINE__);
        return -3;
    }    
    ctx = vm_btgatt_get_ctx(reg_ctx);
    
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 11, __LINE__);
        return -2;
    }
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        start,
        0,
        0,
        0,
        0,
        0,
        11, __LINE__);

    srv_gatts_listen(reg_ctx, (BOOL)start);

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 11, __LINE__);
    return 0;
}


VMINT vm_gatts_set_adv_data(void *reg_ctx, VMBOOL set_scan_rsp, VMBOOL include_name, VMBOOL include_txpower, 
                                VMUINT16 min_interval, VMUINT16 max_interval, VMUINT16 appearance,
                                VMUINT16 manufacturer_len, VMCHAR *manufacturer_data,
                                VMUINT16 service_data_len, VMCHAR *service_data,
                                VMUINT16 service_uuid_len, VMCHAR *service_uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 20, __LINE__);
    if (NULL == reg_ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 20, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 20, __LINE__);
        return -3;
    }
    
    srv_gatts_set_adv_data(reg_ctx, 
                           (BOOL)set_scan_rsp, 
                           (BOOL)include_name, 
                           (BOOL)include_txpower, 
                           (U16)min_interval, 
                           (U16)max_interval, 
                           (U16)appearance,
                           (U16)manufacturer_len, 
                           (char *)manufacturer_data,
                           (U16)service_data_len, 
                           (char *)service_data,
                           (U16)service_uuid_len, 
                           (char *)service_uuid);
                            
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        set_scan_rsp,
        include_name,
        include_txpower,
        min_interval,
        max_interval,
        reg_ctx,
        20, __LINE__);
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 20, __LINE__);
    return 0;
}
		
                                
VMINT vm_gatts_add_service(void *reg_ctx, VM_GATT_SVC_UUID *srvc_id, VMUINT16 num_handles)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 4, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 4, __LINE__);
        return -2;
    }

    if (NULL != srvc_id)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
            srvc_id->uuid.inst,
            0,
            0,
            0,
            reg_ctx,
            0,
            4, __LINE__);
        
    }

    
        
    srv_gatts_add_service(reg_ctx, (GATT_SVC_UUID *)srvc_id, (U16)num_handles);

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 4, __LINE__);
    return 0;
}
VMINT vm_gatts_add_included_service(void *reg_ctx, VM_ATT_HANDLE service_handle, VM_ATT_HANDLE included_handle)
{
    
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 5, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 5, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        included_handle,
        0,
        0,
        reg_ctx,
        0,
        5, __LINE__);
    srv_gatts_add_included_service(reg_ctx, (ATT_HANDLE)service_handle, (ATT_HANDLE)included_handle);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 5, __LINE__);
    return 0;
}
VMINT vm_gatts_add_characteristic(void *reg_ctx, 
                                  VM_ATT_HANDLE service_handle, VM_ATT_UUID *uuid,
                                  VM_GATT_CHAR_PROPERTIES properties, VM_GATT_PERMISSION permission)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 6, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 6, __LINE__);
        return -2;
    }


    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        properties,
        permission,
        0,
        reg_ctx,
        uuid,
        6, __LINE__);

    srv_gatts_add_characteristic(reg_ctx, 
                            (ATT_HANDLE)service_handle, 
                            (ATT_UUID *)uuid, 
                            (GATT_CHAR_PROPERTIES)properties, 
                            (GATT_PERMISSION)permission);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 6, __LINE__);
    return 0;
}
VMINT vm_gatts_add_descriptor(void *reg_ctx, VM_ATT_HANDLE service_handle,
                              VM_ATT_UUID *uuid, VM_GATT_PERMISSION permission)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 7, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 7, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        permission,
        0,
        0,
        reg_ctx,
        uuid,
        7, __LINE__);
        
    srv_gatts_add_descriptor(reg_ctx, 
                            (ATT_HANDLE)service_handle, 
                            (ATT_UUID *)uuid, 
                            (GATT_PERMISSION)permission);
                            
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 7, __LINE__);
    return 0;
}
VMINT vm_gatts_start_service(void *reg_ctx, VM_ATT_HANDLE service_handle,
                             VMUINT8 transport)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 8, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 8, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        transport,
        0,
        0,
        reg_ctx,
        0,
        8, __LINE__);

    srv_gatts_start_service(reg_ctx, (ATT_HANDLE)service_handle, (U8)transport);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 8, __LINE__);
    return 0;
}
VMINT vm_gatts_stop_service(void *reg_ctx, VM_ATT_HANDLE service_handle)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 9, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 9, __LINE__);
        return -2;
    }
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        0,
        0,
        0,
        reg_ctx,
        0,
        9, __LINE__);

    srv_gatts_stop_service(reg_ctx, (ATT_HANDLE)service_handle);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 9, __LINE__);
    return 0;
}
VMINT vm_gatts_delete_service(void *reg_ctx, VM_ATT_HANDLE service_handle)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 10, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 10, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        service_handle,
        0,
        0,
        0,
        reg_ctx,
        0,
        10, __LINE__);

    srv_gatts_delete_service(reg_ctx, (ATT_HANDLE)service_handle);


    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 10, __LINE__);
    return 0;
}
VMINT vm_gatts_send_indication(vm_gatt_conn_struct *conn, VM_ATT_HANDLE attribute_handle,
                               VMBOOL need_confirm, VM_ATT_VALUE *value)
{
    vm_btgatt_context_t *ctx;

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 12, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 12, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 12, __LINE__);
        return -3;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        attribute_handle,
        need_confirm,
        0,
        0,
        conn->reg_ctx,
        conn->conn_ctx,
        12, __LINE__);

    srv_gatts_send_indication((gatt_conn_struct *)conn, (ATT_HANDLE)attribute_handle, (BOOL)need_confirm, (ATT_VALUE *)value);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 12, __LINE__);
    return 0;
}
VMINT vm_gatts_send_response(vm_gatt_conn_struct *conn, U16 trans_id,
                             VMUINT8 status, VM_ATT_HANDLE handle, VM_ATT_VALUE *value)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 13, __LINE__);

    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 13, __LINE__);
        return -2;
    }    
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 13, __LINE__);
        return -3;
    }

    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        trans_id,
        status,
        handle,
        0,
        conn,
        value,
        13, __LINE__);

    srv_gatts_send_response((gatt_conn_struct *)conn, (U16)trans_id, (U8)status, (ATT_HANDLE)handle, (ATT_VALUE *)value);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 13, __LINE__);
    return 0;
}


VMINT vm_gatts_read_tx_power(void *reg_ctx, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 13, __LINE__);

    if (NULL == reg_ctx || NULL == bd_addr)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 13, __LINE__);
        return -2;
    }    
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 13, __LINE__);
        return -3;
    }
    
    vm_gatts_read_tx_power(reg_ctx, (VM_BD_ADDR *)bd_addr);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[2],
        bd_addr->addr[4],
        bd_addr->addr[5],
        reg_ctx,
        bd_addr,
        13, __LINE__);
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 13, __LINE__);
    return 0;
}



VMINT vm_gattc_register(vm_bt_uuid_struct *app_uuid, vm_gattc_callback_struct *callback)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 14, __LINE__);
    if (NULL == app_uuid || NULL == callback)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 14, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_malloc_ctx();
    
    if (!ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 14, __LINE__);
        return -3;
    }

    memcpy(ctx->uuid.uu, app_uuid->uu, 16);

    ctx->c_cb.register_client_cb = callback->register_client_cb;
    ctx->c_cb.scan_result_cb = callback->scan_result_cb;
    ctx->c_cb.connection_cb = callback->connection_cb;
    ctx->c_cb.listen_cb = callback->listen_cb;
    ctx->c_cb.set_adv_data_cb = callback->set_adv_data_cb;
    ctx->c_cb.search_complete_cb = callback->search_complete_cb;
    ctx->c_cb.search_result_cb = callback->search_result_cb;
    ctx->c_cb.get_characteristic_cb = callback->get_characteristic_cb;
    ctx->c_cb.get_descriptor_cb = callback->get_descriptor_cb;
    ctx->c_cb.get_included_service_cb = callback->get_included_service_cb;
    ctx->c_cb.register_for_notification_cb = callback->register_for_notification_cb;
    ctx->c_cb.notify_cb = callback->notify_cb;
    ctx->c_cb.read_characteristic_cb = callback->read_characteristic_cb;
    ctx->c_cb.write_characteristic_cb = callback->write_characteristic_cb;
    ctx->c_cb.read_descriptor_cb = callback->read_descriptor_cb;
    ctx->c_cb.write_descriptor_cb = callback->write_descriptor_cb;
    ctx->c_cb.execute_write_cb = callback->execute_write_cb;
    ctx->c_cb.read_remote_rssi_cb = callback->read_remote_rssi_cb;
    ctx->c_cb.get_device_type_cb = callback->get_device_type_cb;
    ctx->c_cb.research_service_cb = callback->research_service_cb;
    ctx->c_cb.connection_ext_cb = callback->connection_ext_cb;
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        ctx->uuid.uu[0],
        ctx->uuid.uu[1],
        ctx->uuid.uu[2],
        ctx->uuid.uu[3],
        0,
        0,
        14, __LINE__);
        
    srv_gattc_register((bt_uuid_struct *)app_uuid, &client_callback);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 14, __LINE__);
    return 0;
}
VMINT vm_gattc_deregister(void *reg_ctx)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 15, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 15, __LINE__);
        return -2;
    }

    srv_gattc_deregister(reg_ctx);

    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        ctx->p_hdl,
        ctx->res_id,
        reg_ctx,
        15, __LINE__);

    vm_btgatt_free_ctx(ctx);

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 15, __LINE__);
    return 0;
}
VMINT vm_gattc_scan(void *reg_ctx, VMBOOL start)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 16, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 16, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        start,
        0,
        0,
        0,
        0,
        reg_ctx,
        16, __LINE__);

    srv_gattc_scan(reg_ctx, (BOOL)start);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 16, __LINE__);
    return 0;
}
VMINT vm_gattc_connect(void *reg_ctx, VM_BD_ADDR *bd_addr, VMBOOL direct)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 17, __LINE__);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 17, __LINE__);
        return -2;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[2],
        bd_addr->addr[4],
        bd_addr->addr[5],
        direct,
        reg_ctx,
        17, __LINE__);

    srv_gattc_connect(reg_ctx, (BD_ADDR *)bd_addr, (BOOL)direct);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 17, __LINE__);
    return 0;
}
VMINT vm_gattc_disconnect(vm_gatt_conn_struct *conn, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 18, __LINE__);
    if (NULL == conn || NULL == bd_addr)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 18, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 18, __LINE__);
        return -3;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[2],
        bd_addr->addr[4],
        bd_addr->addr[5],
        conn->conn_ctx,
        conn->reg_ctx,
        18, __LINE__);

    srv_gattc_disconnect((gatt_conn_struct *)conn, (BD_ADDR *)bd_addr);
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 18, __LINE__);
    return 0;
}

VMINT vm_gattc_listen(void *reg_ctx, VMBOOL start)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 19, __LINE__);
    if (NULL == reg_ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 19, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 19, __LINE__);
        return -3;
    }

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        start,
        0,
        0,
        0,
        0,
        reg_ctx,
        19, __LINE__);

    srv_gattc_listen(reg_ctx, (BOOL)start);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 19, __LINE__);
    return 0;
}

VMINT vm_gattc_set_adv_data(void *reg_ctx, VMBOOL set_scan_rsp, VMBOOL include_name, VMBOOL include_txpower, 
                                VMUINT16 min_interval, VMUINT16 max_interval, VMUINT16 appearance,
                                VMUINT16 manufacturer_len, VMCHAR *manufacturer_data,
                                VMUINT16 service_data_len, VMCHAR *service_data,
                                VMUINT16 service_uuid_len, VMCHAR *service_uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 20, __LINE__);
    if (NULL == reg_ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 20, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 20, __LINE__);
        return -3;
    }
    srv_gattc_set_adv_data(reg_ctx,
                            (BOOL)set_scan_rsp,
                            (BOOL)include_name,
                            (BOOL)include_txpower, 
                            (U16)min_interval, 
                            (U16)max_interval,
                            (U16)appearance,
                            (U16)manufacturer_len,
                            (char *)manufacturer_data,
                            (U16)service_data_len, 
                            (char *)service_data,
                            (U16)service_uuid_len, 
                            (char *)service_uuid);
                            
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        set_scan_rsp,
        include_name,
        include_txpower,
        min_interval,
        max_interval,
        reg_ctx,
        20, __LINE__);
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 20, __LINE__);
    return 0;
}

VMINT vm_gattc_refresh(void *reg_ctx, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 21, __LINE__);
    
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 21, __LINE__);
        return -2;
    }
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        bd_addr->addr[0],
        bd_addr->addr[2],
        bd_addr->addr[3],
        bd_addr->addr[4],
        bd_addr->addr[5],
        reg_ctx,
        21, __LINE__);

    srv_gattc_refresh(reg_ctx, (BD_ADDR *)bd_addr);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 21, __LINE__);
    return 0;
}

VMINT vm_gattc_search_service(vm_gatt_conn_struct *conn, vm_bt_uuid_struct *uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 22, __LINE__);
    if (NULL == conn/* || NULL == uuid*/)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 22, __LINE__);
        return -2;
    }
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 22, __LINE__);
        return -3;
    }
/*
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        uuid->uu[0],
        uuid->uu[1],
        uuid->uu[2],
        uuid->uu[3],
        conn->conn_ctx,
        conn->reg_ctx,
        21, __LINE__);
*/
    srv_gattc_search_service((gatt_conn_struct *)conn, (bt_uuid_struct *)uuid);
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 22, __LINE__);
    return 0;
}
VMINT vm_gattc_get_included_service(vm_gatt_conn_struct *conn, VM_GATT_SVC_UUID *svc_uuid, 
                                VM_GATT_SVC_UUID *incl_svc_uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 23, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 23, __LINE__);
        return -2;
    }    
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 23, __LINE__);
        return -2;
    }    

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        21, __LINE__);

    srv_gattc_get_included_service((gatt_conn_struct *)conn, (GATT_SVC_UUID *)svc_uuid, (GATT_SVC_UUID *)incl_svc_uuid);
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 23, __LINE__);
    return 0;
}
VMINT vm_gattc_get_characteristic(vm_gatt_conn_struct *conn, VM_GATT_SVC_UUID *svc_uuid, VM_ATT_UUID *start_char_uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 24, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 24, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 24, __LINE__);
        return -3;
    }    
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        24, __LINE__);


    srv_gattc_get_characteristic((gatt_conn_struct *)conn, (GATT_SVC_UUID *)svc_uuid, (ATT_UUID *)start_char_uuid);

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 24, __LINE__);

    return 0;
}
VMINT vm_gattc_get_descriptor(vm_gatt_conn_struct *conn, vm_gattc_char_struct *char_info, VM_ATT_UUID *start_descr_uuid)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 25, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 25, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 25, __LINE__);
        return -3;
    }   
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        25, __LINE__);

    srv_gattc_get_descriptor((gatt_conn_struct *)conn, (gattc_char_struct *)char_info, (ATT_UUID *)start_descr_uuid);

    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 25, __LINE__);
    return 0;
}
VMINT vm_gattc_read_characteristic(vm_gatt_conn_struct *conn, vm_gattc_char_struct *ch, VM_GATTC_AUTH_REQ auth_req)
{
    
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 26, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 26, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 26, __LINE__);
        return -3;
    }  

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        auth_req,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        26, __LINE__);

    srv_gattc_read_characteristic((gatt_conn_struct*)conn, (gattc_char_struct*)ch, (GATTC_AUTH_REQ)auth_req);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 26, __LINE__);
    return 0;
}
VMINT vm_gattc_write_characteristic(vm_gatt_conn_struct *conn, vm_gattc_char_struct *ch, 
                                VM_ATT_VALUE *value, VM_GATTC_WRITE_TYPE write_type, VM_GATTC_AUTH_REQ auth_req)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 27, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 27, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 27, __LINE__);
        return -3;
    }    

    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        auth_req,
        write_type,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        27, __LINE__);

    srv_gattc_write_characteristic((gatt_conn_struct *)conn, 
                        (gattc_char_struct *)ch, 
                        (ATT_VALUE *)value, 
                        (GATTC_WRITE_TYPE)write_type, 
                        (GATTC_AUTH_REQ)auth_req);
                        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 27, __LINE__);
    return 0;
}
VMINT vm_gattc_read_descriptor(vm_gatt_conn_struct *conn, vm_gattc_descr_struct *descr, GATTC_AUTH_REQ auth_req)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 28, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 28, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 28, __LINE__);
        return -3;
    }    
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        auth_req,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        28, __LINE__);

    srv_gattc_read_descriptor((gatt_conn_struct *)conn, (gattc_descr_struct *)descr, (GATTC_AUTH_REQ)auth_req);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 28, __LINE__);
    return 0;
}
VMINT vm_gattc_write_descriptor(vm_gatt_conn_struct *conn, vm_gattc_descr_struct *descr, 
                                VM_ATT_VALUE *value, VM_GATTC_WRITE_TYPE write_type, VM_GATTC_AUTH_REQ auth_req)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 29, __LINE__);
    if (NULL == conn)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E1, 29, __LINE__);
        return -2;
    }    
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
    {
        MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E2, 29, __LINE__);
        return -3;
    }    

    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        auth_req,
        write_type,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        29, __LINE__);

    srv_gattc_write_descriptor((gatt_conn_struct*)conn, 
                    (gattc_descr_struct *)descr, 
                    (ATT_VALUE *)value, 
                    (GATTC_WRITE_TYPE)write_type, 
                    (GATTC_AUTH_REQ)auth_req);
                    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 29, __LINE__);
    return 0;
}
VMINT vm_gattc_execute_write(vm_gatt_conn_struct *conn, VMUINT8 exeute)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return -2;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (NULL == ctx)
        return -3;

    srv_gattc_execute_write((gatt_conn_struct *)conn, (U8)exeute);

    return 0;
}
VMINT vm_gattc_register_for_notification(void *reg_ctx, VM_BD_ADDR *bd_addr, vm_gattc_char_struct *ch)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
        return -2;

    srv_gattc_register_for_notification((void *)reg_ctx, (BD_ADDR *)bd_addr, (gattc_char_struct *)ch);

    return 0;
}
VMINT vm_gattc_deregister_for_notification(void *reg_ctx, VM_BD_ADDR *bd_addr, vm_gattc_char_struct *ch)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
        return -2;

    srv_gattc_deregister_for_notification(reg_ctx, (BD_ADDR *)bd_addr, (gattc_char_struct *)ch);
    return 0;
}
VMINT vm_gattc_read_remote_rssi(void *reg_ctx, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 30, __LINE__);
    if (NULL == ctx)
        return -2;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 30, ctx->conn_ctx);

    srv_gattc_read_remote_rssi(reg_ctx, (BD_ADDR *)bd_addr);
    return 0;
}
VMINT vm_gattc_get_device_type(void *reg_ctx, VM_BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx(reg_ctx);
    if (NULL == ctx)
        return -2;

    srv_gattc_get_device_type(reg_ctx, (BD_ADDR *)bd_addr);
    return 0;
}


VMINT vm_gattc_conn_param_update(VMUINT32 profile_id, VMCHAR *bd_addr, VM_CONN_PRIO_ENUM connectionPriority)
{
#ifdef __MMI_BLE_LOW_POWER__
    srv_gattc_conn_param_update((U32)profile_id, (char*)bd_addr, connectionPriority);
    return 0;
#else
    return -2;
#endif
}


VMINT vm_gattc_set_adv_interval(VMUINT32 profile_id, vm_gattc_adv_interval_enum adv_interval)
{
#ifdef __MMI_BLE_LOW_POWER__
    srv_gattc_set_adv_interval((U32)profile_id, adv_interval);
    return 0;
#else
    return -2;
#endif
}




/** Callback invoked in response to register */
void ms_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    
    vm_btgatt_context_t *ctx = vm_btgatt_get_ctx_by_uuid(app_uuid);
    if (!ctx)
    {
        return;
    }

    ctx->reg_ctx = reg_ctx;
    
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.register_server_cb)
        ctx->s_cb.register_server_cb(reg_ctx, (VM_OS_STATUS)status, (vm_bt_uuid_struct *)app_uuid));
    if (OS_STATUS_FAILED == status) // TODO: check other cases like this case
    {
        vm_btgatt_free_ctx(ctx);
    }
}

/** Callback indicating that a remote device has connected or been disconnected */
void ms_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;

    ctx->conn_ctx = conn->conn_ctx;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.connection_cb)
        ctx->s_cb.connection_cb((vm_gatt_conn_struct *)conn, (VMBOOL)connected, (VM_BD_ADDR *)bd_addr));
    
}

/** Callback triggered in response to listen */
void ms_listen_callback(void *reg_ctx, OS_STATUS status)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.listen_cb)
        ctx->s_cb.listen_cb(reg_ctx, (VM_OS_STATUS)status));
}

/** Callback invoked in response to create_service */
void ms_service_added_callback(OS_STATUS status, void *reg_ctx,
                GATT_SVC_UUID *srvc_id, ATT_HANDLE srvc_handle)
{
    vm_btgatt_context_t *ctx;
    vm_node_t *node;
    
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    if (OS_STATUS_SUCCESS == status)
    {
        node = vm_list_int_alloc(ctx); // spencial thing.
        if (NULL == node)
            return;
        
        node->idx = srvc_handle;
    }

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.service_added_cb)
        ctx->s_cb.service_added_cb((VM_OS_STATUS)status, reg_ctx,
                (VM_GATT_SVC_UUID *)srvc_id, (VM_ATT_HANDLE)srvc_handle));
    
}

/** Callback indicating that an included service has been added to a service */
void ms_included_service_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_HANDLE srvc_handle, ATT_HANDLE incl_srvc_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.included_service_added_cb)
        ctx->s_cb.included_service_added_cb((VM_OS_STATUS)status, reg_ctx,
                (VM_ATT_HANDLE)srvc_handle, (VM_ATT_HANDLE)incl_srvc_handle));
}

/** Callback invoked when a characteristic has been added to a service */
void ms_characteristic_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE char_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.characteristic_added_cb)
        ctx->s_cb.characteristic_added_cb((VM_OS_STATUS)status, reg_ctx,
                (VM_ATT_UUID *)uuid, (VM_ATT_HANDLE)srvc_handle, (VM_ATT_HANDLE)char_handle));
}

/** Callback invoked when a descriptor has been added to a characteristic */
void ms_descriptor_added_callback(OS_STATUS status, void *reg_ctx,
                ATT_UUID *uuid, ATT_HANDLE srvc_handle, ATT_HANDLE descr_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.descriptor_added_cb)
        ctx->s_cb.descriptor_added_cb((VM_OS_STATUS)status, reg_ctx,
                (VM_ATT_UUID *)uuid, (VM_ATT_HANDLE)srvc_handle, (VM_ATT_HANDLE)descr_handle));
}

/** Callback invoked in response to start_service */
void ms_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.service_started_cb)
        ctx->s_cb.service_started_cb((VM_OS_STATUS)status, reg_ctx,
                                         (VM_ATT_HANDLE)srvc_handle));
}

/** Callback invoked in response to stop_service */
void ms_service_stopped_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.service_stopped_cb)
        ctx->s_cb.service_stopped_cb((VM_OS_STATUS)status, reg_ctx,
                                         (VM_ATT_HANDLE)srvc_handle));
}

/** Callback triggered when a service has been deleted */
void ms_service_deleted_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;

    if (OS_STATUS_SUCCESS == status)
    {
        vm_list_int_free(ctx, srvc_handle);
    }
    
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.service_deleted_cb)
        ctx->s_cb.service_deleted_cb((VM_OS_STATUS)status, reg_ctx,
                                         (VM_ATT_HANDLE)srvc_handle));
}

/**
 * Callback invoked when a remote device has requested to read a characteristic
 * or descriptor. The application must respond by calling send_response
 */
void ms_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.request_read_cb)
        ctx->s_cb.request_read_cb((vm_gatt_conn_struct *)conn, (VMUINT16)trans_id, (VM_BD_ADDR *)bd_addr,
                                      (VM_ATT_HANDLE)attr_handle, (VMUINT16)offset, (VMBOOL)is_long));
}

/**
 * Callback invoked when a remote device has requested to write to a
 * characteristic or descriptor.
 */
void ms_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.request_write_cb)
        ctx->s_cb.request_write_cb((vm_gatt_conn_struct *)conn, (VMUINT16)trans_id, (VM_BD_ADDR *)bd_addr,
                                       (VM_ATT_HANDLE)attr_handle, (VM_ATT_VALUE*)value, (VMUINT16)offset,
                                       (VMBOOL)need_rsp, (VMBOOL)is_prep));
}

/** Callback invoked when a previously prepared write is to be executed */
void ms_request_exec_write_callback(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.request_exec_write_cb)
        ctx->s_cb.request_exec_write_cb((vm_gatt_conn_struct *)conn, (VMUINT16)trans_id,
                                            (VM_BD_ADDR *)bd_addr, (VMBOOL)cancel));
}

/**
 * Callback triggered in response to send_response if the remote device
 * sends a confirmation.
 */
void ms_response_confirmation_callback(OS_STATUS status, ATT_HANDLE handle)
{
    vm_btgatt_context_t *ctx;
        
    ctx = vm_btgatt_get_ctx_sub_node(handle); // this handle is comming from add service
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.response_confirmation_cb)
        ctx->s_cb.response_confirmation_cb((VM_OS_STATUS)status, (VM_ATT_HANDLE)handle));
}

void ms_read_tx_power_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.read_tx_power_cb)
        ctx->s_cb.read_tx_power_cb(reg_ctx, (VM_OS_STATUS)status, (VM_BD_ADDR *)bd_addr, (VMUINT8)tx_power));
}


void ms_connection_ext_callback(gattsrv_conn_struct *conn)
{
	  vm_gattsrv_conn_struct conn_temp;
	  
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->conn->reg_ctx);
    if (!ctx)
        return;
        
    conn_temp.conn = (vm_gatt_conn_struct*)conn->conn;
    conn_temp.bd_addr = (VM_BD_ADDR*)conn->bd_addr;
    conn_temp.connected = (VMBOOL)conn->connected;
    conn_temp.is_ind = (VMBOOL)conn->is_ind;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_cb.connection_ext_cb)
        ctx->s_cb.connection_ext_cb((vm_gattsrv_conn_struct *)&conn_temp));
}


/** Callback invoked in response to register */
void mc_register_client_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx_by_uuid(app_uuid);
    
    if (!ctx)
        return;
        
    ctx->reg_ctx = reg_ctx;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.register_client_cb)
        ctx->c_cb.register_client_cb(reg_ctx, (VM_OS_STATUS)status, (vm_bt_uuid_struct *)app_uuid));
    
    if (OS_STATUS_FAILED == status) // TODO: check other cases like this case
    {
        vm_btgatt_free_ctx(ctx);
    }
}

/** Callback for scan results */
void mc_scan_result_callback(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.scan_result_cb)
        ctx->c_cb.scan_result_cb(reg_ctx, (VM_BD_ADDR *)bd_addr, (VMINT32)rssi, (VMUINT8)eir_len, (VMUINT8 *)eir));
}

/** Callback indicating that a remote device has connected or been disconnected */
void mc_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    vm_btgatt_context_t *ctx;
    
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 31, __LINE__);
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        31, __LINE__);
    ctx->conn_ctx = conn->conn_ctx;

    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.connection_cb)
        ctx->c_cb.connection_cb((vm_gatt_conn_struct *)conn, (VMBOOL)connected, (VM_BD_ADDR *)bd_addr));
       
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_E, 31, __LINE__);
}

/** Callback triggered in response to listen */
void mc_listen_callback(void *reg_ctx, OS_STATUS status)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.listen_cb)
        ctx->c_cb.listen_cb(reg_ctx, (VM_OS_STATUS)status));
}

/** Callback triggered in response to set_adv_data */
void mc_set_adv_data_callback(void *reg_ctx, OS_STATUS status)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.set_adv_data_cb)
        ctx->c_cb.set_adv_data_cb(reg_ctx, (VM_OS_STATUS)status));
}

/**
 * Invoked in response to search_service when the GATT service search
 * has been completed.
 */
void mc_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    vm_btgatt_context_t *ctx;
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 32, __LINE__);
    if (NULL == conn || NULL == conn->reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_LOG, 
        0,
        0,
        0,
        0,
        conn->conn_ctx,
        conn->reg_ctx,
        32, __LINE__);
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.search_complete_cb)
        ctx->c_cb.search_complete_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status));
    MMI_TRACE(TRACE_GROUP_4, TRC_MRE_BTGATT_S, 32, __LINE__);
}

/** Reports GATT services on a remote device */
void mc_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.search_result_cb)
        ctx->c_cb.search_result_cb((vm_gatt_conn_struct *)conn, (VM_GATT_SVC_UUID *)uuid));
}

/** GATT characteristic enumeration result callback */
void mc_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch, GATT_CHAR_PROPERTIES properties)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.get_characteristic_cb)
        ctx->c_cb.get_characteristic_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (vm_gattc_char_struct *)ch, (VM_GATT_CHAR_PROPERTIES)properties));
}

/** GATT descriptor enumeration result callback */
void mc_get_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.get_descriptor_cb)
        ctx->c_cb.get_descriptor_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status, (vm_gattc_descr_struct *)descr));
}

/** GATT included service enumeration result callback */
void mc_get_included_service_callback(gatt_conn_struct *conn, OS_STATUS status,
                                GATT_SVC_UUID *svc_uuid, GATT_SVC_UUID *incl_svc_uuid)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.get_included_service_cb)
        ctx->c_cb.get_included_service_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (VM_GATT_SVC_UUID *)svc_uuid, (VM_GATT_SVC_UUID *)incl_svc_uuid));
}

/** Callback invoked in response to [de]register_for_notification */
void mc_register_for_notification_callback(void *reg_ctx, OS_STATUS status, 
                                BD_ADDR *bd_addr, gattc_char_struct *ch)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.register_for_notification_cb)
        ctx->c_cb.register_for_notification_cb(reg_ctx, (VM_OS_STATUS)status, 
                                (VM_BD_ADDR *)bd_addr, (vm_gattc_char_struct *)ch));

}

/**
 * Remote device notification callback, invoked when a remote device sends
 * a notification or indication that a client has registered for.
 */
void mc_notify_callback(gatt_conn_struct *conn, BD_ADDR *bd_addr,
                                gattc_char_struct *ch, ATT_VALUE *value, BOOL is_notify)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.notify_cb)
        ctx->c_cb.notify_cb((vm_gatt_conn_struct *)conn, (VM_BD_ADDR *)bd_addr,
                                (vm_gattc_char_struct *)ch, (VM_ATT_VALUE *)value, (VMBOOL)is_notify));
}

/** Reports result of a GATT read operation */
void mc_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch, ATT_VALUE *value)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.read_characteristic_cb)
        ctx->c_cb.read_characteristic_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (vm_gattc_char_struct *)ch, (VM_ATT_VALUE *)value));

}

/** GATT write characteristic operation callback */
void mc_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *ch)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.write_characteristic_cb)
        ctx->c_cb.write_characteristic_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (vm_gattc_char_struct *)ch));
}

/** Callback invoked in response to read_descriptor */
void mc_read_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr, ATT_VALUE *value)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.read_descriptor_cb)
        ctx->c_cb.read_descriptor_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (vm_gattc_descr_struct *)descr, (VM_ATT_VALUE *)value));

}                                

/** Callback invoked in response to write_descriptor */
void mc_write_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.write_descriptor_cb)
        ctx->c_cb.write_descriptor_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status,
                                (vm_gattc_descr_struct *)descr));

}


/** GATT execute prepared write callback */
void mc_execute_write_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.execute_write_cb)
        ctx->c_cb.execute_write_cb((vm_gatt_conn_struct *)conn, (VM_OS_STATUS)status));
}

/** Callback triggered in response to read_remote_rssi */
void mc_read_remote_rssi_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.read_remote_rssi_cb)
        ctx->c_cb.read_remote_rssi_cb(reg_ctx, (VM_OS_STATUS)status, (VM_BD_ADDR *)bd_addr, (VMINT32)rssi));
}

/** Callback triggered in response to get_device_type */
void mc_get_device_type_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, GATTC_DEV_TYPE dev_type)
{
    // TODO:
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.get_device_type_cb)
        ctx->c_cb.get_device_type_cb(reg_ctx, (VM_OS_STATUS)status, (VM_BD_ADDR *)bd_addr, (VM_GATTC_DEV_TYPE)dev_type));

}


void mc_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr)
{
    // TODO:
    vm_btgatt_context_t *ctx;
    if (NULL == conn->reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.research_service_cb)
        ctx->c_cb.research_service_cb((vm_gatt_conn_struct*)conn, (VM_OS_STATUS) status, (VM_BD_ADDR*)bd_addr));
}



void mc_connection_ext_callback(gattsrv_conn_struct *conn)
{
	  vm_gattsrv_conn_struct conn_temp;
	  
    vm_btgatt_context_t *ctx;
    if (NULL == conn)
        return;
        
    ctx = vm_btgatt_get_ctx(conn->conn->reg_ctx);
    if (!ctx)
        return;
        
    conn_temp.conn = (vm_gatt_conn_struct*)conn->conn;
    conn_temp.bd_addr = (VM_BD_ADDR*)conn->bd_addr;
    conn_temp.connected = (VMBOOL)conn->connected;
    conn_temp.is_ind = (VMBOOL)conn->is_ind;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->c_cb.connection_ext_cb)
        ctx->c_cb.connection_ext_cb((vm_gattsrv_conn_struct *)&conn_temp));
}



// callback function for srv_gatts_profile_factory_get_services
void factory_srvs_got_cb(OS_STATUS status, void* reg_ctx)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_fac_cb.factory_srvs_got_cb)
        ctx->s_fac_cb.factory_srvs_got_cb((VM_OS_STATUS)status, reg_ctx));
}

// callback function for srv_gatts_profile_factory_clear_services
void factory_srvs_cleared_cb(OS_STATUS status, void* reg_ctx)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_fac_cb.factory_srvs_cleared_cb)
        ctx->s_fac_cb.factory_srvs_cleared_cb((VM_OS_STATUS)status, reg_ctx));
}

// callback function for srv_gatts_profile_factory_add_services
void factory_srvs_added_cb(OS_STATUS status, void* reg_ctx)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_fac_cb.factory_srvs_added_cb)
        ctx->s_fac_cb.factory_srvs_added_cb((VM_OS_STATUS)status, reg_ctx));
}

// callback function for srv_gatts_profile_factory_delete_services
void factory_srvs_deleted_cb(OS_STATUS status, void* reg_ctx)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return;
        
    PMNG_WRAP_CALLBACK(ctx->p_hdl, 
        if (ctx->s_fac_cb.factory_srvs_deleted_cb)
        ctx->s_fac_cb.factory_srvs_deleted_cb((VM_OS_STATUS)status, reg_ctx));
}

#include "GattServicesFactorySrv.h"

static gatts_factory_callback_struct gatts_factory_callback = 
{
    factory_srvs_got_cb,
    factory_srvs_cleared_cb,
    factory_srvs_added_cb,
    factory_srvs_deleted_cb
};



//Register gatts profile callback. Callback functions about add-services will be replaced by this register function.
VMINT vm_gatts_profile_factory_register(vm_bt_uuid_struct* uuid, vm_gatts_callback_struct* gatts_cb, 
                                                                    vm_gatts_factory_callback_struct* factory_cb)
{
    vm_btgatt_context_t *ctx;
    
    if (NULL == uuid || NULL == gatts_cb || NULL == factory_cb)
    {
        return -2;
    }
    
    ctx = vm_btgatt_malloc_ctx();
    if (!ctx)
    {
        return -3;
    }    
    ctx->s_cb.register_server_cb = gatts_cb->register_server_cb;
    ctx->s_cb.connection_cb = gatts_cb->connection_cb;
    ctx->s_cb.listen_cb = gatts_cb->listen_cb;
    ctx->s_cb.service_added_cb = gatts_cb->service_added_cb;
    ctx->s_cb.included_service_added_cb = gatts_cb->included_service_added_cb;
    ctx->s_cb.characteristic_added_cb = gatts_cb->characteristic_added_cb;
    ctx->s_cb.descriptor_added_cb = gatts_cb->descriptor_added_cb;
    ctx->s_cb.service_started_cb = gatts_cb->service_started_cb;
    ctx->s_cb.service_stopped_cb = gatts_cb->service_stopped_cb;
    ctx->s_cb.service_deleted_cb = gatts_cb->service_deleted_cb;
    ctx->s_cb.request_read_cb = gatts_cb->request_read_cb;
    ctx->s_cb.request_write_cb = gatts_cb->request_write_cb;
    ctx->s_cb.request_exec_write_cb = gatts_cb->request_exec_write_cb;
    ctx->s_cb.response_confirmation_cb = gatts_cb->response_confirmation_cb;
    ctx->s_cb.read_tx_power_cb = gatts_cb->read_tx_power_cb;

    memcpy(ctx->uuid.uu, uuid->uu, 16);

    ctx->s_fac_cb.factory_srvs_got_cb = factory_cb->factory_srvs_got_cb;
    ctx->s_fac_cb.factory_srvs_cleared_cb = factory_cb->factory_srvs_cleared_cb;
    ctx->s_fac_cb.factory_srvs_added_cb = factory_cb->factory_srvs_added_cb;
    ctx->s_fac_cb.factory_srvs_deleted_cb = factory_cb->factory_srvs_deleted_cb;

    srv_gatts_profile_factory_register((bt_uuid_struct *)uuid, &server_callback, &gatts_factory_callback);

    
    return 0;
}

//Deregister a server application from the stack.
VMINT vm_gatts_profile_factory_deregister(void* reg_ctx)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return -2;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return -3;

    srv_gatts_profile_factory_deregister(reg_ctx);
    vm_btgatt_free_ctx(ctx);
    return 0;
}

//Get gatts profile services by profile id. gatts_services_struct fill be filled without handle.
// VM_OS_STATUS
VMINT vm_gatts_profile_factory_get_services(void* reg_ctx, VMINT32 id, vm_gatts_srvs_lst_struct* services)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return -2;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return -3;

    srv_gatts_profile_factory_get_services(reg_ctx, (S32)id, (gatts_srvs_lst_struct *)services);

    return 0;
}

//Clear used resource in profile factory. If this function is called, the parameter service structure will be set to empty.
VMINT vm_gatts_profile_factory_clear_services(void* reg_ctx, const vm_gatts_srvs_lst_struct* services)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return -2;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return -3;

    srv_gatts_profile_factory_clear_services(reg_ctx, (gatts_srvs_lst_struct *)services);
    return 0;
}

//Add gatts profile services  to gatt stack.
VMINT vm_gatts_profile_factory_add_services(void* reg_ctx, const vm_gatts_srvs_lst_struct* services)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return -2;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return -3;

    srv_gatts_profile_factory_add_services(reg_ctx, (gatts_srvs_lst_struct *)services);
    return 0;
}

//Delete gatts profile services from gatt stack.
VMINT vm_gatts_profile_factory_delete_services(void* reg_ctx, const vm_gatts_srvs_lst_struct* services)
{
    vm_btgatt_context_t *ctx;
    if (NULL == reg_ctx)
        return -2;
        
    ctx = vm_btgatt_get_ctx(reg_ctx);
    if (!ctx)
        return -3;

    srv_gatts_profile_factory_delete_services(reg_ctx, (gatts_srvs_lst_struct *)services);
    return 0;
}

//Crete service declare list before add service
VMINT vm_gatts_profile_factory_create_srv_list(vm_gatts_profile_srv_decl_struct *srv_list, VMUINT32 decl_num)
{
    S32 ret = srv_gatts_profile_factory_create_srv_list((gatts_profile_srv_decl_struct *)srv_list, (U32)decl_num);

    return (VMINT)ret;
}

//Delete service from profile table
// VM_OS_STATUS
VMINT vm_gatts_profile_factory_delete_srv_list(VMINT32 profile_id)
{
    OS_STATUS status;
    status = srv_gatts_profile_factory_delete_srv_list((S32)profile_id);
    return (VMINT)status;
}

VMINT vm_get_btgatt_sym(VMCHAR* func_name)
{    
    if(strcmp(func_name,"vm_gatts_register") == 0)
        return (VMINT)vm_gatts_register;
    if(strcmp(func_name,"vm_gatts_deregister") == 0)
        return (VMINT)vm_gatts_deregister;
    if(strcmp(func_name,"vm_gatts_connect") == 0)
        return (VMINT)vm_gatts_connect;
    if(strcmp(func_name,"vm_gatts_disconnect") == 0)
        return (VMINT)vm_gatts_disconnect;
    if(strcmp(func_name,"vm_gatts_add_service") == 0)
        return (VMINT)vm_gatts_add_service;
    if(strcmp(func_name,"vm_gatts_listen") == 0)
        return (VMINT)vm_gatts_listen;
    if(strcmp(func_name,"vm_gatts_set_adv_data") == 0)
        return (VMINT)vm_gatts_set_adv_data;
    if(strcmp(func_name,"vm_gatts_add_included_service") == 0)
        return (VMINT)vm_gatts_add_included_service;
    if(strcmp(func_name,"vm_gatts_add_characteristic") == 0)
        return (VMINT)vm_gatts_add_characteristic;
    if(strcmp(func_name,"vm_gatts_add_descriptor") == 0)
        return (VMINT)vm_gatts_add_descriptor;
    if(strcmp(func_name,"vm_gatts_start_service") == 0)
        return (VMINT)vm_gatts_start_service;
    if(strcmp(func_name,"vm_gatts_stop_service") == 0)
        return (VMINT)vm_gatts_stop_service;
    if(strcmp(func_name,"vm_gatts_delete_service") == 0)
        return (VMINT)vm_gatts_delete_service;
    if(strcmp(func_name,"vm_gatts_send_indication") == 0)
        return (VMINT)vm_gatts_send_indication;
    if(strcmp(func_name,"vm_gatts_send_response") == 0)
        return (VMINT)vm_gatts_send_response;
    if(strcmp(func_name,"vm_gatts_read_tx_power") == 0)
        return (VMINT)vm_gatts_read_tx_power;
        
    if(strcmp(func_name,"vm_gattc_register") == 0)
        return (VMINT)vm_gattc_register;
    if(strcmp(func_name,"vm_gattc_deregister") == 0)
        return (VMINT)vm_gattc_deregister;
    if(strcmp(func_name,"vm_gattc_scan") == 0)
        return (VMINT)vm_gattc_scan;
    if(strcmp(func_name,"vm_gattc_connect") == 0)
        return (VMINT)vm_gattc_connect;
    if(strcmp(func_name,"vm_gattc_disconnect") == 0)
        return (VMINT)vm_gattc_disconnect;
    if(strcmp(func_name,"vm_gattc_listen") == 0)
        return (VMINT)vm_gattc_listen;
    if(strcmp(func_name,"vm_gattc_set_adv_data") == 0)
        return (VMINT)vm_gattc_set_adv_data;
    if(strcmp(func_name,"vm_gattc_refresh") == 0)
        return (VMINT)vm_gattc_refresh;
    if(strcmp(func_name,"vm_gattc_search_service") == 0)
        return (VMINT)vm_gattc_search_service;
    if(strcmp(func_name,"vm_gattc_get_included_service") == 0)
        return (VMINT)vm_gattc_get_included_service;
    if(strcmp(func_name,"vm_gattc_get_characteristic") == 0)
        return (VMINT)vm_gattc_get_characteristic;
    if(strcmp(func_name,"vm_gattc_get_descriptor") == 0)
        return (VMINT)vm_gattc_get_descriptor;
    if(strcmp(func_name,"vm_gattc_read_characteristic") == 0)
        return (VMINT)vm_gattc_read_characteristic;
    if(strcmp(func_name,"vm_gattc_write_characteristic") == 0)
        return (VMINT)vm_gattc_write_characteristic;
    if(strcmp(func_name,"vm_gattc_read_descriptor") == 0)
        return (VMINT)vm_gattc_read_descriptor;
    if(strcmp(func_name,"vm_gattc_write_descriptor") == 0)
        return (VMINT)vm_gattc_write_descriptor;
    if(strcmp(func_name,"vm_gattc_execute_write") == 0)
        return (VMINT)vm_gattc_execute_write;
    if(strcmp(func_name,"vm_gattc_register_for_notification") == 0)
        return (VMINT)vm_gattc_register_for_notification;
    if(strcmp(func_name,"vm_gattc_deregister_for_notification") == 0)
        return (VMINT)vm_gattc_deregister_for_notification;
    if(strcmp(func_name,"vm_gattc_read_remote_rssi") == 0)
        return (VMINT)vm_gattc_read_remote_rssi;
    if(strcmp(func_name,"vm_gattc_get_device_type") == 0)
        return (VMINT)vm_gattc_get_device_type;

    if(strcmp(func_name,"vm_gatts_profile_factory_register") == 0)
        return (VMINT)vm_gatts_profile_factory_register;
    if(strcmp(func_name,"vm_gatts_profile_factory_deregister") == 0)
        return (VMINT)vm_gatts_profile_factory_deregister;
    if(strcmp(func_name,"vm_gatts_profile_factory_get_services") == 0)
        return (VMINT)vm_gatts_profile_factory_get_services;
    if(strcmp(func_name,"vm_gatts_profile_factory_clear_services") == 0)
        return (VMINT)vm_gatts_profile_factory_clear_services;
    if(strcmp(func_name,"vm_gatts_profile_factory_add_services") == 0)
        return (VMINT)vm_gatts_profile_factory_add_services;
    if(strcmp(func_name,"vm_gatts_profile_factory_delete_services") == 0)
        return (VMINT)vm_gatts_profile_factory_delete_services;
    if(strcmp(func_name,"vm_gatts_profile_factory_create_srv_list") == 0)
        return (VMINT)vm_gatts_profile_factory_create_srv_list;
    if(strcmp(func_name,"vm_gatts_profile_factory_delete_srv_list") == 0)
        return (VMINT)vm_gatts_profile_factory_delete_srv_list;
    if(strcmp(func_name,"vm_gattc_conn_param_update") == 0)
        return (VMINT)vm_gattc_conn_param_update;
    if(strcmp(func_name,"vm_gattc_set_adv_interval") == 0)
        return (VMINT)vm_gattc_set_adv_interval;
	return 0;
}



#endif /* __MRE_SAL_BTGATT__ */
