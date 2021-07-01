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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/
#include "mmi_features.h"
//#ifdef WIN32
//#include "O:\\plutommi\\Service\\Inc\\WlanSrvGprot.h"

#ifndef __WIFI_SCAN_ONLY__
//#else
#include "WlanSrvGprot.h"
//#endif
#endif
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#include "vmswitch.h"

#ifdef __MRE_SAL_NWSETTING__
    
#include "vmresmng.h"
#include "vmmod.h"
#include "vmmem.h"
#include "vmpromng.h"
#include "vmnwsetting.h"
#include "mmi_trc.h"
#include "mmi_mre_trc.h"
#include "MREAppMgrSrvGprot.h"
#ifndef __WIFI_SCAN_ONLY__

enum
{
    E_WLAN_CONN, //vm_wlan_cb_func_ptr
    E_WLAN_RES, //vm_wlan_conn_res_cb_func_ptr
    E_WLAN_SCAN, //vm_wlan_scan_res_cb_func_ptr
    E_WLAN_SNIFFER_ON, //vm_wlan_sniffer_on_cb_func_ptr
    E_WLAN_SNIFFER_OFF, //vm_wlan_sniffer_off_cb_func_ptr
    E_WLAN_NOTI_IP, //vm_wlan_noti_func_ptr
    E_WLAN_NOTI_DISCONN, //vm_wlan_noti_func_ptr
    E_WLAN_NOTI //vm_wlan_noti_func_ptr
};

typedef struct _vm_wlan_ctx_act_t vm_wlan_ctx_act_t;
struct _vm_wlan_ctx_act_t
{
    VMUINT idx;
    VMINT type;
    void *cb;
    void *user_data;
    vm_wlan_ctx_act_t *next;
};

typedef struct
{
    VM_P_HANDLE p;
    vm_wlan_ctx_act_t *head;
    //vm_wlan_cb_func_ptr wlan_conn_cb;
    //vm_wlan_conn_res_cb_func_ptr wlan_res_cb;
	//vm_wlan_scan_res_cb_func_ptr wlan_scan_cb;
    //void *user_data;
	//void *scan_user_data;
}vm_wlan_ctx_t;

static vm_wlan_ctx_t ctx = {0};


static vm_wlan_ctx_act_t *vm_wlan_int_alloc(vm_wlan_ctx_t *ctx_p)
{
    vm_wlan_ctx_act_t *client;
    vm_wlan_ctx_act_t *tmp;
    if (NULL == ctx_p)
        return NULL;

	client = vm_calloc(sizeof(vm_wlan_ctx_act_t));
	if (NULL == client)
	    return NULL;

    client->idx = (VMUINT)client;
    
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

static void vm_wlan_int_free(vm_wlan_ctx_t *ctx_p, VMUINT idx)
{
    vm_wlan_ctx_act_t *p, *q;
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
            vm_free(p);
            return;
        }
    }

    q = p->next;
    while (q)
    {
        if (idx == q->idx)
        {
            p->next = q->next;
            vm_free(q);
            return;   
        }
        p = q;
        q = q->next;
    }
    
}

static void vm_wlan_int_release_alls(vm_wlan_ctx_t *ctx_p)
{
    vm_wlan_ctx_act_t *tmp;
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
        vm_free(tmp);
        tmp = ctx_p->head;
    }


    
}

static vm_wlan_ctx_act_t * vm_wlan_int_get(vm_wlan_ctx_t *ctx_p, VMUINT idx)
{
    vm_wlan_ctx_act_t *tmp;
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

//static void* VM_WLAN_SETTING_CB(const wlan_ctx_act_t *act)
//{
//    if (!act)
//        return NULL;
//    switch (act->type)
//    {
//    case E_WLAN_CONN:
//        {
//            return act->cb;
//        }break;
//    case E_WLAN_RES:
//        {
//            
//        }break;
//    case E_WLAN_SCAN:
//        {
//            
//        }break;
//    default:
//        break;
//    }
//}
static void srv_wlan_scan_int_cb(
			U32 job_id,
            void *user_data,
            srv_wlan_scan_result_struct *scan_res)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 55, __LINE__);

    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 55, __LINE__);
        return;
    }
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        55, __LINE__);

    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        if (act->cb)
        {	
        	vm_wlan_scan_result_struct scan_result;
			VMINT i;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 55, __LINE__);
			if (scan_res)
			{
				scan_result.ap_list_num = scan_res->ap_list_num;
				scan_result.result = scan_res->result;
				scan_result.scan_job_id = scan_res->scan_job_id;
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 55, __LINE__);
				for (i=0; i< scan_res->ap_list_num; i++)
				{
					scan_result.ap_list[i].ssid_len = scan_res->ap_list[i].ssid_len;
					scan_result.ap_list[i].rssi = scan_res->ap_list[i].rssi;
					scan_result.ap_list[i].channel_number = scan_res->ap_list[i].channel_number;
					scan_result.ap_list[i].max_rate = scan_res->ap_list[i].max_rate;
					scan_result.ap_list[i].privacy = scan_res->ap_list[i].privacy;
					scan_result.ap_list[i].network_type = scan_res->ap_list[i].network_type;
					scan_result.ap_list[i].auth_mode = scan_res->ap_list[i].auth_mode;
					scan_result.ap_list[i].encrypt_mode = scan_res->ap_list[i].encrypt_mode;
                    memcpy(scan_result.ap_list[i].bssid, scan_res->ap_list[i].bssid, VM_WLAN_WNDRV_MAC_ADDRESS_LEN);
                    memcpy(scan_result.ap_list[i].ssid, scan_res->ap_list[i].ssid, VM_WLAN_WNDRV_SSID_MAX_LEN);
					
				}
                ((vm_wlan_scan_res_cb_func_ptr)act->cb)(job_id, act->user_data, &scan_result);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 55, __LINE__);
			}
			else
                ((vm_wlan_scan_res_cb_func_ptr)act->cb)(job_id, act->user_data, NULL);
        }
        
        vm_wlan_int_free(&ctx, act->idx);
        vm_pmng_reset_ctx(); 
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 55, __LINE__);
}


static void srv_wlan_conn_int_cb(void *user_data, srv_wlan_req_res_enum res)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 66, __LINE__);

    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 66, __LINE__);
        return;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        66, __LINE__);
        

    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 66, __LINE__);
        if (act->cb)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 66, __LINE__);
            ((vm_wlan_cb_func_ptr)act->cb)(act->user_data, res);
        }
        
        vm_wlan_int_free(&ctx, act->idx);
        vm_pmng_reset_ctx(); 
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 66, __LINE__);
    // vm_wlan_int_free(&ctx, act->idx);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 66, __LINE__);
}

static void srv_wlan_res_int_cb(
            void *user_data,
            srv_wlan_conn_res_struct *conn_res)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 77, __LINE__);
    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 77, __LINE__);
        return;
    }
        
    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        if (act->cb)
        {   
            vm_wlan_conn_res_struct res;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 77, __LINE__);
            if (conn_res)
            {
                res.result = conn_res->result;
                res.cause = conn_res->cause;
                res.init_by_soc = conn_res->init_by_soc;
                res.ssid_len = conn_res->ssid_len;
                res.channel_number = conn_res->channel_number;
                res.profile_id = conn_res->profile_id;
                res.auth_type = conn_res->auth_type;
                res.eap_peap_auth_type = conn_res->eap_peap_auth_type;
                res.eap_ttls_auth_type = conn_res->eap_ttls_auth_type;
                res.conn_type = conn_res->conn_type;
                res.encry_mode = conn_res->encry_mode;
                res.passphase_len = conn_res->passphase_len;
                res.need_login = conn_res->need_login;
                res.cancel_by_discon = conn_res->cancel_by_discon;
                res.rssi = conn_res->rssi;
                memcpy(res.bssid, conn_res->bssid, VM_WLAN_WNDRV_MAC_ADDRESS_LEN);
                memcpy(res.ssid, conn_res->ssid, VM_WLAN_WNDRV_SSID_MAX_LEN);
                memcpy(res.passphase, conn_res->passphase, 32);
                ((vm_wlan_conn_res_cb_func_ptr)act->cb)(act->user_data, &res);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 77, __LINE__);
            }
            else
            {
                ((vm_wlan_conn_res_cb_func_ptr)act->cb)(act->user_data, NULL);
            }
        }
        
        vm_wlan_int_free(&ctx, act->idx);
        vm_pmng_reset_ctx(); 
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 77, __LINE__);
    // vm_wlan_int_free(&ctx, act->idx);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, act->cb, __LINE__);
}

static void vm_wlan_sniffer_on_int_cb(void *user_data, srv_wlan_sniffer_on_res_struct *sniffer_res)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 88, __LINE__);
    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 88, __LINE__);
        return;
    }
        
    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        if (act->cb)
        {   
            vm_wlan_sniffer_on_res_struct res;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 88, __LINE__);
            if (SRV_WLAN_SNIFFER_ON_AP_INFO == sniffer_res->cb_type)
            {             
                res.cb_type = sniffer_res->cb_type;
                res.result = sniffer_res->result;
                //res.profile.ssid = sniffer_res->profile.ssid;
                res.profile.auth_mode = sniffer_res->profile.auth_mode;
                res.profile.profile_id = sniffer_res->profile.profile_id;
                memcpy(res.profile.ssid, sniffer_res->profile.ssid, VM_WLAN_WNDRV_SSID_MAX_LEN + 1);
                memcpy(res.profile.username, sniffer_res->profile.username, VM_WLAN_PROF_MAX_USER_LEN + 1);
                memcpy(res.profile.password, sniffer_res->profile.password, VM_WLAN_PROF_PSWD_MAX_LEN + 1);
                ((vm_wlan_sniffer_on_cb_func_ptr)act->cb)(act->user_data, &res);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 88, __LINE__);
            }
            else
            {
                res.cb_type = sniffer_res->cb_type;
                res.result = sniffer_res->result;
                ((vm_wlan_sniffer_on_cb_func_ptr)act->cb)(act->user_data, &res);
                if(VM_WLAN_SNIFFER_SUCCESS == res.result)
                {
                    return;
                }
            }
        }       
        
        vm_wlan_int_free(&ctx, act->idx);
        
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 88, __LINE__);
    // vm_wlan_int_free(&ctx, act->idx);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, act->cb, __LINE__);
}

static void vm_wlan_sniffer_off_int_cb(void *user_data, srv_wlan_sniffer_res_enum res)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 99, __LINE__);
    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 99, __LINE__);
        return;
    }
        
    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 99, __LINE__);
        if (act->cb)
        {   
            ((vm_wlan_sniffer_off_cb_func_ptr)act->cb)(act->user_data, res);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 99, __LINE__);
        }
        
        vm_wlan_int_free(&ctx, act->idx);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 99, __LINE__);
    // vm_wlan_int_free(&ctx, act->idx);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, act->cb, __LINE__);
}

static void vm_wlan_noti_int_cb(void *user_data, srv_wlan_noti_struct *out_noti)
{
    vm_wlan_ctx_act_t *act = (vm_wlan_ctx_act_t*)user_data;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 100, __LINE__);
    act = vm_wlan_int_get(&ctx, (VMUINT)act);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E4, 100, __LINE__);
        return;
    }
        
    if (vm_pmng_set_ctx(ctx.p) == VM_PMNG_OP_OK)
    {
        if (act->cb)
        {   
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 100, __LINE__);
            if (out_noti)
            {
                vm_wlan_noti_struct noti;
                noti.data = out_noti->data;
                noti.type = out_noti->type;
                ((vm_wlan_noti_func_ptr)act->cb)(act->user_data, &noti);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 100, __LINE__);
            }
            else
                ((vm_wlan_noti_func_ptr)act->cb)(act->user_data, NULL);
        }
        vm_pmng_reset_ctx(); 
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 100, __LINE__);
    // vm_wlan_int_free(&ctx, act->idx);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, act->cb, __LINE__);
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

VMINT vm_wlan_prof_init(vm_wlan_prof_struct *profile)
{
    srv_wlan_prof_struct wlan_prof;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 3, __LINE__);
    if (NULL == profile)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 3, __LINE__);
        return -2;
    }

    srv_wlan_init_profile(&wlan_prof);
    
    //profile->priority = wlan_prof.priority;
    profile->profile_id = wlan_prof.profile_id;
    profile->auth_mode = wlan_prof.auth_mode;
    memcpy(profile->ssid, wlan_prof.ssid, VM_WLAN_PROF_MAX_SSID_LEN + 1);
    memcpy(profile->username, wlan_prof.username, VM_WLAN_PROF_MAX_USER_LEN + 1);
    memcpy(profile->password, wlan_prof.password, VM_WLAN_PROF_PSWD_MAX_LEN + 1);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        //profile->priority,
        0,
        profile->profile_id,
        profile->auth_mode,
        0,
        0,
        0,
        3, __LINE__);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 3, __LINE__);

    
    return 0;
}


VMINT vm_wlan_prof_add(const vm_wlan_prof_struct *prof, VMUINT32 *prof_id)
{
    VMINT ret;
    srv_wlan_prof_struct wlan_prof;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 4, __LINE__);
    if (NULL == prof)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 4, __LINE__);
        return -2;
    }
    //wlan_prof.priority = prof->priority;
    wlan_prof.profile_id = prof->profile_id;
    wlan_prof.auth_mode = prof->auth_mode;
    memcpy(wlan_prof.ssid, prof->ssid, VM_WLAN_PROF_MAX_SSID_LEN + 1);
    memcpy(wlan_prof.username, prof->username, VM_WLAN_PROF_MAX_USER_LEN + 1);
    memcpy(wlan_prof.password, prof->password, VM_WLAN_PROF_PSWD_MAX_LEN + 1);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        //wlan_prof.priority,
        0,
        wlan_prof.profile_id,
        wlan_prof.auth_mode,
        0,
        0,
        0,
        4, __LINE__);
    

    ret = srv_wlan_add_prof(&wlan_prof, (U32 *)prof_id);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}
                        
VMINT vm_wlan_disconnect(
                        vm_wlan_cb_func_ptr callback,
                        void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 5, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 5, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        5, __LINE__);

    ret = srv_wlan_disconnect(srv_wlan_conn_int_cb, act);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}

VMINT vm_wlan_prof_connect(
                        VMUINT32 prof_id,
                        vm_wlan_conn_res_cb_func_ptr callback,
                        void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 6, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 6, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_RES;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        6, __LINE__);
        
    ret = srv_wlan_connect_by_spec_prof(prof_id, srv_wlan_res_int_cb, act);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}

VMINT vm_wlan_get_connected_ap_info(void *info, VMINT info_type)
{

    MMI_BOOL b = MMI_FALSE;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 151, __LINE__);
    
    b = srv_wlan_get_connected_ap_info(info, info_type);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 151, b);

    return b ? 0 : -2;
    
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    return 0;
}

VMINT vm_wlan_prof_query(
                        VMUINT32 prof_id, 
                        vm_wlan_prof_struct *prof)
{
    
    VMINT ret;
    srv_wlan_prof_struct wlan_prof;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 8, __LINE__);
    if (NULL == prof)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 8, __LINE__);
        return -2;
    }
    
    ret = srv_wlan_query_prof((U32)prof_id, &wlan_prof);
    if (SRV_WLAN_RESULT_SUCCESS == ret)
    {
        //prof->priority = wlan_prof.priority;
        prof->profile_id = wlan_prof.profile_id;
        prof->auth_mode = wlan_prof.auth_mode;
        memcpy(prof->ssid, wlan_prof.ssid, VM_WLAN_PROF_MAX_SSID_LEN + 1);
        memcpy(prof->username, wlan_prof.username, VM_WLAN_PROF_MAX_USER_LEN + 1);
        memcpy(prof->password, wlan_prof.password, VM_WLAN_PROF_PSWD_MAX_LEN + 1);
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
            //prof->priority,
            0,
            prof->profile_id,
            prof->auth_mode,
            0,
            0,
            0,
            8, __LINE__);
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);

    return ret;
    
}





VMINT vm_wlan_scan(
        vm_wlan_scan_res_cb_func_ptr callback,
        void *user_data)
{
    U32 ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 20, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 20, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_SCAN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        20, __LINE__);
    ret = srv_wlan_scan(srv_wlan_scan_int_cb, act);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    
	return ret;
}

VMINT vm_wlan_scan_abort(VMUINT32 job_id)
{
	srv_wlan_scan_abort(job_id);
	return 0;
}


VMINT vm_wlan_prof_query_list(vm_wlan_prof_list_struct *prof_list)
{
	VMINT ret;
	srv_wlan_prof_list_struct prof_list_got;

	ret = srv_wlan_query_prof_list(&prof_list_got);
	if (ret == SRV_WLAN_RESULT_SUCCESS)
	{
		memcpy(prof_list->ids, &(prof_list_got.ids), sizeof(U32) * VM_MAX_WLAN_ACCOUNT_NUM);
		prof_list->num_ids = prof_list_got.num_ids;
	}

	return ret;
}


VMINT vm_wlan_prof_update(
                        VMUINT32 prof_id, 
                        vm_wlan_prof_struct *prof,
                        VMUINT32 prof_fields)
{
    
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 16, __LINE__);

    if (NULL == prof)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 16, __LINE__);
        return -2;
    }

    ret = srv_wlan_update_prof(prof_id, (srv_wlan_prof_struct *)prof, prof_fields);
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ret,
        prof_fields,
        0,
        0,
        0,
        0, 
        16, __LINE__);
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 16, __LINE__);

    return ret;
}


VMINT vm_wlan_prof_delete(VMUINT32 prof_id)
{
	return srv_wlan_delete_prof(prof_id);
}



VMINT vm_wlan_roaming_set(
    VMINT enable_roaming, 
    vm_wlan_cb_func_ptr callback, 
    void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 12, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 12, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        enable_roaming,
        0,
        act->idx,
        act->user_data,
        12, __LINE__);



	ret = srv_wlan_set_roaming_para(enable_roaming, srv_wlan_conn_int_cb, act);
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}

VMINT vm_wlan_roaming_get(VMINT *is_roaming)
{
    kal_bool roaming;
    VMINT ret;
    
	ret = (VMINT)srv_wlan_get_roaming_para(&roaming);	

    *is_roaming = roaming ? 1 : 0;
    return ret;
}


VMINT vm_wlan_mode_set(vm_wlan_set_mode_enum mode, vm_wlan_cb_func_ptr callback, void *user_data)
{
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 14, __LINE__);
#ifdef __MMI_MRE_AUTH_SUPPORT__
    if(MMI_FALSE == srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_WLAN_SWITCH))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_AUTH_SWITCH_FAIL);
        return -404;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_AUTH_SWITCH_BEGIN);
    }
#endif
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 14, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        mode,
        0,
        act->idx,
        act->user_data,
        14, __LINE__);

	srv_wlan_switch(mode, srv_wlan_conn_int_cb, act); // BUILDE
	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 14, __LINE__);

	return 0;
}


VMINT vm_wlan_get_mac_address(vm_wlan_prof_str_info_qry_struct *mac_address_out)
{
    VMINT ret;
    MMI_BOOL b;
    srv_wlan_prof_str_info_qry_struct mac_addr;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 9, __LINE__);
    if (!mac_address_out && mac_address_out->dest)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 9, __LINE__);
        return -2;
    }

    mac_addr.dest_len = mac_address_out->dest_len;
    mac_addr.req_len = mac_address_out->req_len;
    mac_addr.dest = (CHAR*)vm_calloc(mac_addr.dest_len);
    b = srv_wlan_get_mac_address(&mac_addr);
    
    
    if (b)
    {
        mac_address_out->dest_len = mac_addr.dest_len;
        mac_address_out->req_len = mac_addr.req_len;      
        memcpy(mac_address_out->dest, mac_addr.dest, mac_address_out->dest_len);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 9, __LINE__);
        vm_free(mac_addr.dest);
        ret = 0;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 9, __LINE__);
        vm_free(mac_addr.dest);
        ret = -3;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 9, __LINE__);
    return ret;
}

VMINT vm_wlan_get_ip_info(vm_wlan_ip_info_struct* ip_info)
{
    VMINT ret;
    srv_wlan_ip_info_struct srv_ip_info;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 10, __LINE__);
    if (!ip_info)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 10, __LINE__);
        return -2;
    }

    ret = srv_wlan_get_ip_info(&srv_ip_info);

    if (SRV_WLAN_RESULT_SUCCESS == ret)
    {
        memcpy(ip_info->ip_addr, srv_ip_info.ip_addr, VM_WLAN_PROF_MAX_IP_ADDR_LEN);
        memcpy(ip_info->netmask, srv_ip_info.netmask, VM_WLAN_PROF_MAX_IP_ADDR_LEN);
        memcpy(ip_info->gateway, srv_ip_info.gateway, VM_WLAN_PROF_MAX_IP_ADDR_LEN);
        memcpy(ip_info->dns1, srv_ip_info.dns1, VM_WLAN_PROF_MAX_IP_ADDR_LEN);
        memcpy(ip_info->dns2, srv_ip_info.dns2, VM_WLAN_PROF_MAX_IP_ADDR_LEN);
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 10, __LINE__);
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 10, __LINE__);
    return ret;
}

VMINT vm_wlan_status(void)
{
    return (VMINT)srv_wlan_sta_status();
}

VMINT vm_wlan_sniffer_on(
                                vm_wlan_sniffer_on_cfg_struct *sniffer_on_config,
                                vm_wlan_sniffer_on_cb_func_ptr callback,
                                void *user_data)
{
#ifdef __WIFI_SNIFFER_SUPPORT__
    VMINT ret;
    vm_wlan_ctx_act_t *act;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 22, __LINE__);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
    ctx.p = vm_pmng_get_current_handle();
    
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 22, __LINE__);
        return -3;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_SNIFFER_ON;
    act->cb = (void*)callback;
    act->user_data = user_data;

 #if 0   
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    ret = srv_wlan_sniffer_on((srv_wlan_sniffer_on_cfg_struct*)sniffer_on_config, vm_wlan_sniffer_on_int_cb, act);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
#else
    return -2;
#endif /*  __WIFI_SNIFFER_SUPPORT__*/
}

VMINT vm_wlan_sniffer_off(
                        vm_wlan_sniffer_off_cb_func_ptr callback,
                        void *user_data)
{
#ifdef __WIFI_SNIFFER_SUPPORT__

    VMINT ret;
    vm_wlan_ctx_act_t *act;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 23, __LINE__);
    
    ctx.p = vm_pmng_get_current_handle();
    
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 23, __LINE__);
        return -3;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_SNIFFER_OFF;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        23, __LINE__);

    ret = srv_wlan_sniffer_off(vm_wlan_sniffer_off_int_cb, act);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
#else
    
    return -2; /* __WIFI_SNIFFER_SUPPORT__ */
#endif
}

VMINT vm_wlan_prof_set_reconn_id(VMUINT32 prof_id)
{
    MMI_BOOL ret = srv_wlan_set_reconn_prof_id(prof_id);
    return ret ? 0 : -3;
}

VMINT vm_wlan_prof_get_reconn_id(VMUINT32 *prof_id)
{
    MMI_BOOL ret = srv_wlan_get_reconn_prof_id((U32*)prof_id);
    return ret ? 0 : -3;
}

static vm_wlan_ctx_act_t *vm_wlan_get_int(VMINT type, VMINT log_id, void *callback, void *user_data)
{
//    VMINT ret;
    vm_wlan_ctx_act_t *act = NULL, *tmp = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, log_id, __LINE__);
    
    ctx.p = vm_pmng_get_current_handle();
    
    tmp = ctx.head;
    while (tmp)
    {
        if (tmp->type == type &&
            tmp->cb == callback &&
            tmp->user_data == user_data)
        {   
            act = tmp;
            break;
        }
        tmp = tmp->next;
    }
    
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, log_id, __LINE__);
        return NULL;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        log_id, __LINE__);

    return act;
}


static vm_wlan_ctx_act_t *vm_wlan_int_init(VMINT type, VMINT log_id, void *callback, void *user_data)
{
//    VMINT ret;
    vm_wlan_ctx_act_t *act;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, log_id, __LINE__);
    
    ctx.p = vm_pmng_get_current_handle();
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, log_id, __LINE__);
        return NULL;
    }
    act->idx = (VMUINT)act;
    act->type = type;
    act->cb = callback;
    act->user_data = user_data;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        log_id, __LINE__);

    return act;

}



/* olders srv_*/
VMINT vm_wlan_get_connected_ap_bssid(vm_wlan_prof_str_info_qry_struct *bssid)
{
    MMI_BOOL b = srv_wlan_get_connected_ap_bssid((srv_wlan_prof_str_info_qry_struct*)bssid);
    return b ? 0 : -2;
}

VMINT vm_wlan_get_connected_ap_prof_id(VMUINT32 *prof_id)
{
    MMI_BOOL b = srv_wlan_get_reconn_prof_id((U32 *)prof_id);
    return b ? 0 : -2;
}

VMINT vm_wlan_get_connected_ap_rssi(VMINT32 *rssi_out)
{
    MMI_BOOL b = srv_wlan_get_connected_ap_rssi((S32 *)rssi_out);
    return b ? 0 : -2;
}

VMINT vm_wlan_reg_ip_available_noti(vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 24, __LINE__);
    act = vm_wlan_get_int(E_WLAN_NOTI_IP, 25, (void*)callback, user_data);
    if (act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 24, __LINE__);
        return -2;
    }
    
    act = vm_wlan_int_init(E_WLAN_NOTI_IP, 25, (void*)callback, user_data);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 24, __LINE__);
        return -3;
    }        


    ret = srv_wlan_reg_ip_available_noti(vm_wlan_noti_int_cb, act);
    
    if (!ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 24, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}

VMINT vm_wlan_dereg_ip_available_noti(vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    //act = vm_wlan_int_init(E_WLAN_NOTI, 25, (void*)callback, user_data);
    act = vm_wlan_get_int(E_WLAN_NOTI_IP, 25, (void*)callback, user_data);
    
    if (!act)
        return -2;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        25, __LINE__);

    ret = srv_wlan_dereg_ip_available_noti(vm_wlan_noti_int_cb, act);
    if (ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 25, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}
VMINT vm_wlan_reg_passive_disconn_noti(vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 26, __LINE__);
    act = vm_wlan_get_int(E_WLAN_NOTI_DISCONN, 26, (void*)callback, user_data);
    if (act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 26, __LINE__);
        return -2;
    }
    act = vm_wlan_int_init(E_WLAN_NOTI_DISCONN, 26, (void*)callback, user_data);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 26, __LINE__);
        return -2;
    }
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        26, __LINE__);

    ret = srv_wlan_reg_passive_disconn_noti(vm_wlan_noti_int_cb, act);
    if (!ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 26, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}

VMINT vm_wlan_dereg_passive_disconn_noti(vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    //act = vm_wlan_int_init(E_WLAN_NOTI, 27, (void*)callback, user_data);
    act = vm_wlan_get_int(E_WLAN_NOTI_DISCONN, 27, (void*)callback, user_data);
    if (!act)
        return -2;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        27, __LINE__);

    ret = srv_wlan_dereg_passive_disconn_noti(vm_wlan_noti_int_cb, act);
    if (ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 27, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}


VMINT vm_wlan_set_scan_dwell_time(VMUINT16 dwell_time,
                                        vm_wlan_cb_func_ptr callback, 
                                        void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 21, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 21, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        dwell_time,
        0,
        act->idx,
        act->user_data,
        21, __LINE__);
        
	ret = srv_wlan_set_scan_dwell_time(dwell_time, srv_wlan_conn_int_cb, act);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
    
}


VMINT vm_wlan_get_scan_dwell_time(VMUINT16 *dwell_time)
{
	return srv_wlan_get_scan_dwell_time(dwell_time);
}


VMINT vm_wlan_set_scan_spec_ssid_list(
        VMUINT8 ssid_list_num, 
        const vm_wlan_ssid_struct *ssid_list,
        vm_wlan_cb_func_ptr callback,
        void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 13, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 13, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        ssid_list_num,
        0,
        act->idx,
        act->user_data,
        13, __LINE__);
        
	ret = srv_wlan_set_scan_spec_ssid_list(ssid_list_num, (const srv_wlan_ssid_struct *)ssid_list, srv_wlan_conn_int_cb, act);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;

}

VMINT vm_wlan_get_scan_spec_ssid_list(
    VMUINT8 * ssid_list_num, 
    vm_wlan_ssid_struct *ssid_list)
{
    return srv_wlan_get_scan_spec_ssid_list(ssid_list_num, (srv_wlan_ssid_struct *)ssid_list); // BUILDE
}



/* end */


VMINT vm_wlan_connect(
    vm_wlan_ap_info_struct *ap_info, 
    vm_wlan_conn_res_cb_func_ptr callback,
    void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 28, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 28, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_RES;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        0,
        0,
        act->idx,
        act->user_data,
        28, __LINE__);

    ret = srv_wlan_connect((srv_wlan_ap_info_struct *)ap_info, srv_wlan_res_int_cb, (void*)act);

    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 28, __LINE__);
    return ret;
}

VMINT vm_wlan_scan_set_param(
    void *param, 
    VMINT32 param_type, 
    vm_wlan_cb_func_ptr callback, 
    void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    ctx.p = vm_pmng_get_current_handle();
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 29, __LINE__);
    
    act = vm_wlan_int_alloc(&ctx);
    if (NULL == act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 29, __LINE__);
        return -2;
    }
    act->idx = (VMUINT)act;
    act->type = E_WLAN_CONN;
    act->cb = (void*)callback;
    act->user_data = user_data;

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        param_type,
        0,
        act->idx,
        act->user_data,
        29, __LINE__);

    ret = srv_wlan_set_scan_param((void*)param, (VMINT32)param_type, srv_wlan_conn_int_cb, act);

	
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 29, ret);
    return 0;
}

VMINT vm_wlan_scan_get_param(void *param, VMINT32 param_type)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 30, __LINE__);
    return (VMINT)srv_wlan_get_scan_param((void *)param, (VMINT32)param_type);
}

VMINT vm_wlan_reg_noti(VMINT noti_type, vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 31, __LINE__);
    act = vm_wlan_get_int(E_WLAN_NOTI - 2 + noti_type, 31, (void*)callback, user_data);
    if (act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 31, __LINE__);
        return -2;
    }
    
    act = vm_wlan_int_init(E_WLAN_NOTI - 2 + noti_type, 31, (void*)callback, user_data);
    if (!act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 31, __LINE__);
        return -3;
    }        


    ret = srv_wlan_reg_noti((S32)noti_type, vm_wlan_noti_int_cb, act);

    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        noti_type,
        0,
        act->idx,
        act->user_data,
        32, __LINE__);

    if (!ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E3, 31, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}

VMINT vm_wlan_dereg_noti(VMINT noti_type, vm_wlan_noti_func_ptr callback, void *user_data)
{
    VMINT ret;
    vm_wlan_ctx_act_t *act;
    //act = vm_wlan_int_init(E_WLAN_NOTI, 25, (void*)callback, user_data);
    act = vm_wlan_get_int(E_WLAN_NOTI - 2 + noti_type, 32, (void*)callback, user_data);
    
    if (!act)
        return -2;
        
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_LOG, 
        ctx.p,
        act->type,
        noti_type,
        0,
        act->idx,
        act->user_data,
        32, __LINE__);

    ret = srv_wlan_dereg_noti((S32)noti_type, vm_wlan_noti_int_cb, act);
    if (ret)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 32, __LINE__);
        vm_wlan_int_free(&ctx, act->idx);
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret ? 0 : -3;
}

VMINT vm_wlan_set_para(
                    vm_wlan_set_mode_enum mode,
                    void *para,
                    VMINT32 flag)
{
    vm_wlan_result_enum ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 33, __LINE__);
    ret = srv_wlan_set_para((srv_wlan_set_mode_enum)mode, (void *)para, (S32)flag);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}

VMINT vm_wlan_get_para(
                    vm_wlan_set_mode_enum mode,
                    void *para)
{
    vm_wlan_result_enum ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 34, __LINE__);
    ret = srv_wlan_get_para((srv_wlan_set_mode_enum)mode, (void *)para);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, ret, __LINE__);
    return ret;
}
#endif

VMINT vm_wlan_mode_get(void)
{
#ifndef __WIFI_SCAN_ONLY__
	return srv_wlan_status();
#endif
    return -2;
}

#include "wlansrvscanonly.h"
typedef struct
{
    vm_wlan_init_cb init_cb;
    vm_wlan_deinit_cb deinit_cb;
    vm_wlan_scan_cb scan_cb;
    void *user_data_init;
    void *user_data_deinit;
    void *user_data_scan;
    VM_P_HANDLE p;
    VMINT used;
}wndrv_t;

static wndrv_t ctx_wndrv;

#ifdef __WIFI_SCAN_ONLY__

/*
wndrv_t *vm_wndrv_int_get_ctx()
{
    return 
}
*/

/* Callback */
void vm_wndrv_int_init_cb(void *user_data, wlan_init_cnf_struct *cnf)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 35, __LINE__);
    if (vm_pmng_set_ctx(ctx_wndrv.p) == VM_PMNG_OP_OK)
    {
        if (ctx_wndrv.init_cb)
        {
            (ctx_wndrv.init_cb)(ctx_wndrv.user_data_init, (vm_wlan_init_cnf_struct*)cnf);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 35, __LINE__);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 35, __LINE__);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 35, __LINE__);
}
void vm_wndrv_int_deinit_cb(void *user_data, wlan_deinit_cnf_struct *cnf)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 36, __LINE__);
    if (vm_pmng_set_ctx(ctx_wndrv.p) == VM_PMNG_OP_OK)
    {
        if (ctx_wndrv.deinit_cb)
        {
            (ctx_wndrv.deinit_cb)(ctx_wndrv.user_data_deinit, (vm_wlan_deinit_cnf_struct*)cnf);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 36, __LINE__);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 36, __LINE__);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 36, __LINE__);
}
void vm_wndrv_int_scan_cb(void *user_data, wlan_scan_cnf_struct *cnf)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 37, __LINE__);
    if (vm_pmng_set_ctx(ctx_wndrv.p) == VM_PMNG_OP_OK)
    {
        if (ctx_wndrv.scan_cb)
        {
            (ctx_wndrv.scan_cb)(ctx_wndrv.user_data_init, (vm_wlan_scan_cnf_struct*)cnf);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 37, __LINE__);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 37, __LINE__);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 37, __LINE__);
}

#endif /* __WIFI_SCAN_ONLY__ */
static void vm_wndrv_open_sta_cb(void *user_data, vm_wlan_req_res_enum res)
{
    vm_wlan_init_cnf_struct cnf;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 41, __LINE__);
    if (vm_pmng_set_ctx(ctx_wndrv.p) == VM_PMNG_OP_OK)
    {
        if (ctx_wndrv.init_cb)
        {
            if(VM_WLAN_REQ_RES_DONE == res)
            {
                cnf.state = VM_SCANONLY_SUCCESS;
            }
            else
            {
                cnf.state = VM_SCANONLY_INIT_FAIL__UNKOWN;
            }
            (ctx_wndrv.init_cb)(ctx_wndrv.user_data_init, &cnf);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 41, __LINE__);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 41, __LINE__);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 41, __LINE__);
}
VMINT vm_wndrv_init(vm_wlan_init_req_struct *req, vm_wlan_init_cb callback, void *user_data)
{
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 38, __LINE__);
#ifdef __MMI_MRE_AUTH_SUPPORT__
    if(MMI_FALSE == srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_WLAN_SWITCH))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_AUTH_INIT_FAIL);
        return -404;
    }
    else
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_AUTH_INIT_BEGIN);
    }
#endif
    ctx_wndrv.p = vm_pmng_get_current_handle();
    ctx_wndrv.init_cb = callback;
    ctx_wndrv.user_data_init= user_data;
#ifdef __WIFI_SCAN_ONLY__
    ret = (VMINT)wlan_init((wlan_init_req_struct *)req, vm_wndrv_int_init_cb, &ctx_wndrv);
#else
    vm_wlan_mode_set(VM_WLAN_SET_MODE_STA, vm_wndrv_open_sta_cb, &ctx_wndrv);
    ret = VM_WNDRV_RESULT_WOULDBLOCK;
#endif
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 38, ret);
    return ret;
}

static void vm_wndrv_switch_off_cb(void *user_data, vm_wlan_req_res_enum res)
{
    vm_wlan_deinit_cnf_struct cnf;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 42, __LINE__);
    if (vm_pmng_set_ctx(ctx_wndrv.p) == VM_PMNG_OP_OK)
    {
        if (ctx_wndrv.deinit_cb)
        {
            if(VM_WLAN_REQ_RES_DONE == res)
            {
                cnf.state = VM_SCANONLY_SUCCESS;
            }
            else
            {
                cnf.state = VM_SCANONLY_DEINIT_FAIL__UNKOWN;
            }
            (ctx_wndrv.deinit_cb)(ctx_wndrv.user_data_init, &cnf);
            MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E1, 42, __LINE__);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E2, 42, __LINE__);
        vm_pmng_reset_ctx(); 
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 42, __LINE__);
}

VMINT vm_wndrv_deinit(vm_wlan_deinit_req_struct *req, vm_wlan_deinit_cb callback, void *user_data)
{
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 39, __LINE__);
    ctx_wndrv.p = vm_pmng_get_current_handle();
    ctx_wndrv.deinit_cb = callback;
    ctx_wndrv.user_data_deinit = user_data;
#ifdef __WIFI_SCAN_ONLY__
    ret = (VMINT)wlan_deinit((wlan_deinit_req_struct *)req, vm_wndrv_int_deinit_cb, &ctx_wndrv);
#else
    vm_wlan_mode_set(VM_WLAN_SET_MODE_OFF, vm_wndrv_switch_off_cb, &ctx_wndrv);
    ret = VM_WNDRV_RESULT_WOULDBLOCK;
#endif
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 39, ret);
    return ret;
}


static vm_wlan_scan_cb common_cb = NULL;
void vm_wlan_scan_res_cb (
            VMUINT32 job_id,
            void *user_data,
            vm_wlan_scan_result_struct *scan_res)
{
    if (scan_res)
    {
        if (common_cb && scan_res)
        {
            if (VM_WLAN_SCAN_RESULT_SUCCESS == scan_res->result)
            {
                int i;
                vm_wlan_scan_cnf_struct cnf = {0};
                cnf.status = VM_SCANONLY_SUCCESS;
                cnf.scan_ap_num = scan_res->ap_list_num > VM_SCANONLY_MAX_SCAN_AP_NUM ? VM_SCANONLY_MAX_SCAN_AP_NUM : scan_res->ap_list_num;
                for (i = 0; i < cnf.scan_ap_num; i++)
                {
                    memcpy(cnf.scan_ap[i].bssid, scan_res->ap_list[i].bssid, VM_SCANONLY_MAC_ADDRESS_LEN);
                    memcpy(cnf.scan_ap[i].ssid, scan_res->ap_list[i].ssid, VM_WLAN_WNDRV_SSID_MAX_LEN);
                    cnf.scan_ap[i].ssid_len = scan_res->ap_list[i].ssid_len;
                    cnf.scan_ap[i].rssi = (signed char)scan_res->ap_list[i].rssi;
                    cnf.scan_ap[i].channel_number = (VMUINT8)scan_res->ap_list[i].channel_number;
                }
                common_cb(user_data, &cnf);
                common_cb = NULL;
            }
            else if (VM_WLAN_SCAN_RESULT_FAILED == scan_res->result || 
                VM_WLAN_SCAN_RESULT_ABORTED == scan_res->result ||
                VM_WLAN_SCAN_RESULT_DELETE == scan_res->result)
            {
                common_cb = NULL;
            }
        }
        
    }
}

VMINT vm_wndrv_scan(vm_wlan_scan_req_struct *req, vm_wlan_scan_cb callback, void *user_data)
{
#ifdef __WIFI_SCAN_ONLY__
    VMINT ret;
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_S, 40, __LINE__);
    ctx_wndrv.p = vm_pmng_get_current_handle();
    ctx_wndrv.scan_cb = callback;
    ctx_wndrv.user_data_scan = user_data;
    ret = (VMINT)wlan_scan((wlan_scan_req_struct *)req, vm_wndrv_int_scan_cb, &ctx_wndrv);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMSOCK, TRC_MRE_SYNC_NWSETTING_E, 40, ret);
    return ret;
#else
    if (NULL == callback || NULL != common_cb)
        return;
    vm_wlan_scan(vm_wlan_scan_res_cb, user_data);
    common_cb = callback;
    return VM_WNDRV_RESULT_WOULDBLOCK;
#endif
}


VMINT vm_get_nwsetting_sym(VMCHAR* func_name)
{
#ifndef __WIFI_SCAN_ONLY__
    //if(strcmp(func_name,"vm_srv_wlan_init") == 0)
    //    return (VMINT)vm_srv_wlan_init;
    //if(strcmp(func_name,"vm_srv_wlan_deinit") == 0)
    //    return (VMINT)vm_srv_wlan_deinit;
    if(strcmp(func_name,"vm_srv_wlan_init_profile") == 0 || 
        strcmp(func_name,"vm_wlan_prof_init") == 0)
        return (VMINT)vm_wlan_prof_init;        
    if(strcmp(func_name,"vm_srv_wlan_add_prof") == 0 || 
        strcmp(func_name,"vm_wlan_prof_add") == 0)
        return (VMINT)vm_wlan_prof_add;
    if(strcmp(func_name,"vm_srv_wlan_disconnect") == 0 || 
        strcmp(func_name,"vm_wlan_disconnect") == 0)
        return (VMINT)vm_wlan_disconnect;
    if(strcmp(func_name,"vm_srv_wlan_connect_by_spec_prof") == 0 || 
        strcmp(func_name,"vm_wlan_prof_connect") == 0)
        return (VMINT)vm_wlan_prof_connect;
        
    /* multi to single */
    if(strcmp(func_name,"vm_srv_wlan_get_connected_ap_bssid") == 0)
       return (VMINT)vm_wlan_get_connected_ap_bssid;
    if(strcmp(func_name,"vm_srv_wlan_get_connected_ap_prof_id") == 0) 
       return (VMINT)vm_wlan_get_connected_ap_prof_id;
    if(strcmp(func_name,"vm_srv_wlan_get_connected_ap_rssi") == 0)
       return (VMINT)vm_wlan_get_connected_ap_rssi;
    if(strcmp(func_name,"vm_wlan_get_connected_ap_info") == 0)
        return (VMINT)vm_wlan_get_connected_ap_info;        
        
    if(strcmp(func_name,"vm_srv_wlan_query_prof") == 0 || 
        strcmp(func_name,"vm_wlan_prof_query") == 0)
        return (VMINT)vm_wlan_prof_query;     
    if(strcmp(func_name,"vm_srv_wlan_scan") == 0 || 
        strcmp(func_name,"vm_wlan_scan") == 0)
        return (VMINT)vm_wlan_scan;
    if(strcmp(func_name,"vm_srv_wlan_scan_abort") == 0 || 
        strcmp(func_name,"vm_wlan_scan_abort") == 0)
        return (VMINT)vm_wlan_scan_abort;	
        
    if(strcmp(func_name,"vm_srv_wlan_query_prof_list") == 0 || 
        strcmp(func_name,"vm_wlan_prof_query_list") == 0)
        return (VMINT)vm_wlan_prof_query_list;	
    if(strcmp(func_name,"vm_srv_wlan_status") == 0 || 
        strcmp(func_name,"vm_wlan_mode_get") == 0)
        return (VMINT)vm_wlan_mode_get;	
    if(strcmp(func_name,"vm_srv_wlan_update_prof") == 0 || 
        strcmp(func_name,"vm_wlan_prof_update") == 0)
        return (VMINT)vm_wlan_prof_update;	
    if(strcmp(func_name,"vm_srv_wlan_delete_prof") == 0 ||
        strcmp(func_name,"vm_wlan_prof_delete") == 0)
        return (VMINT)vm_wlan_prof_delete;	

    if(strcmp(func_name,"vm_srv_wlan_set_roaming_para") == 0 || 
        strcmp(func_name,"vm_wlan_roaming_set") == 0)
        return (VMINT)vm_wlan_roaming_set;					
    if(strcmp(func_name,"vm_srv_wlan_get_roaming_para") == 0 || 
        strcmp(func_name,"vm_wlan_roaming_get") == 0)
        return (VMINT)vm_wlan_roaming_get;	
    if(strcmp(func_name,"vm_srv_wlan_set_scan_spec_ssid_list") == 0 || 
        strcmp(func_name,"vm_wlan_set_scan_spec_ssid_list") == 0)
        return (VMINT)vm_wlan_set_scan_spec_ssid_list;	
    if(strcmp(func_name,"vm_srv_wlan_get_scan_spec_ssid_list") == 0 || 
        strcmp(func_name,"vm_wlan_get_scan_spec_ssid_list") == 0)
        return (VMINT)vm_wlan_get_scan_spec_ssid_list;	



	if(strcmp(func_name,"vm_srv_wlan_set_scan_dwell_time") == 0 ||
	    strcmp(func_name,"vm_wlan_set_scan_dwell_time") == 0)
		return (VMINT)vm_wlan_set_scan_dwell_time;	
	if(strcmp(func_name,"vm_srv_wlan_get_scan_dwell_time") == 0 || 
	    strcmp(func_name,"vm_wlan_get_scan_dwell_time") == 0)
		return (VMINT)vm_wlan_get_scan_dwell_time;	
    if(strcmp(func_name,"vm_srv_wlan_get_mac_address") == 0 || 
        strcmp(func_name,"vm_wlan_get_mac_address") == 0)
        return (VMINT)vm_wlan_get_mac_address;
    if(strcmp(func_name,"vm_srv_wlan_get_ip_info") == 0 || 
        strcmp(func_name,"vm_wlan_get_ip_info") == 0)
        return (VMINT)vm_wlan_get_ip_info;
    if(strcmp(func_name,"vm_srv_wlan_switch") == 0 || 
        strcmp(func_name,"vm_wlan_mode_set") == 0)
        return (VMINT)vm_wlan_mode_set;

    if(strcmp(func_name,"vm_srv_wlan_sta_status") == 0 || 
        strcmp(func_name,"vm_wlan_status") == 0)
        return (VMINT)vm_wlan_status;
    if(strcmp(func_name,"vm_srv_wlan_sniffer_on") == 0 ||
        strcmp(func_name,"vm_wlan_sniffer_on") == 0)
        return (VMINT)vm_wlan_sniffer_on;
    if(strcmp(func_name,"vm_srv_wlan_sniffer_off") == 0 || 
        strcmp(func_name,"vm_wlan_sniffer_off") == 0)
        return (VMINT)vm_wlan_sniffer_off;
    if(strcmp(func_name,"vm_srv_wlan_set_reconn_prof_id") == 0 || 
        strcmp(func_name,"vm_wlan_prof_set_reconn_id") == 0)
        return (VMINT)vm_wlan_prof_set_reconn_id;
    if(strcmp(func_name,"vm_srv_wlan_get_reconn_prof_id") == 0 || 
        strcmp(func_name,"vm_wlan_prof_get_reconn_id") == 0)
        return (VMINT)vm_wlan_prof_get_reconn_id;
    if(strcmp(func_name,"vm_srv_wlan_reg_ip_available_noti") == 0 || 
        strcmp(func_name,"vm_wlan_reg_ip_available_noti") == 0)
        return (VMINT)vm_wlan_reg_ip_available_noti;
    if(strcmp(func_name,"vm_srv_wlan_dereg_ip_available_noti") == 0 || 
        strcmp(func_name,"vm_wlan_dereg_ip_available_noti") == 0)
        return (VMINT)vm_wlan_dereg_ip_available_noti;
    if(strcmp(func_name,"vm_srv_wlan_reg_passive_disconn_noti") == 0 || 
        strcmp(func_name,"vm_wlan_reg_passive_disconn_noti") == 0)
        return (VMINT)vm_wlan_reg_passive_disconn_noti;
    if(strcmp(func_name,"vm_srv_wlan_dereg_passive_disconn_noti") == 0 || 
        strcmp(func_name,"vm_wlan_dereg_passive_disconn_noti") == 0)
        return (VMINT)vm_wlan_dereg_passive_disconn_noti;

        
    if(strcmp(func_name,"vm_wlan_connect") == 0)
        return (VMINT)vm_wlan_connect;
    if(strcmp(func_name,"vm_wlan_scan_set_param") == 0)
        return (VMINT)vm_wlan_scan_set_param;
    if(strcmp(func_name,"vm_wlan_scan_get_param") == 0)
        return (VMINT)vm_wlan_scan_get_param;
    if(strcmp(func_name,"vm_wlan_reg_noti") == 0)
        return (VMINT)vm_wlan_reg_noti;
    if(strcmp(func_name,"vm_wlan_dereg_noti") == 0)
        return (VMINT)vm_wlan_dereg_noti;

    if(strcmp(func_name,"vm_wlan_set_para") == 0)
        return (VMINT)vm_wlan_set_para;
    if(strcmp(func_name,"vm_wlan_get_para") == 0)
        return (VMINT)vm_wlan_get_para;

        
#endif
        
    if(strcmp(func_name,"vm_wndrv_init") == 0)
        return (VMINT)vm_wndrv_init;
    if(strcmp(func_name,"vm_wndrv_deinit") == 0)
        return (VMINT)vm_wndrv_deinit;
    if(strcmp(func_name,"vm_wndrv_scan") == 0)
        return (VMINT)vm_wndrv_scan;
	return 0;
}

#endif

