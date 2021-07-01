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
 * Vmtel.c
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#include "vmswitch.h"
#ifdef __MRE_SAL_TELE__

//#include "mmi_include.h"
//#include "SimDetectionGprot.h"
//#include "MMI_features.h"
#include "MMIDataType.h"

#include "UcmGProt.h"
#include "UcmSrvGProt.h"
#include "vmtel.h"
#include "vmlog.h"
#include "vmstdlib.h"
#include "vmsim.h"
//#include "vmopt.h"
#include "vmmod.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmpromnginner.h"
#include "ModeSwitchSrvGProt.h"

#include "globalresdef.h"
#include "DialerCuiGprot.h"
#include "MREAppMgrSrvGprot.h"

extern pBOOL mmi_bootup_get_active_flight_mode(void);

static VMINT vm_callout_status;
static srv_ucm_id_info_struct g_vm_ivr_call_info;
static srv_ucm_incoming_call_ind_struct g_vm_ivr_incoming_data;

static mmi_ret vm_callout_ucm_callback(mmi_event_struct * param)
{
	//srv_ucm_status_change_evt_struct *evt = (srv_ucm_status_change_evt_struct *)param;
	VMINT resid = -1;
	VM_CALLOUT_RESPONSE_T callout_callback;
	VMWSTR phonenum = NULL;
	VMINT size = 0;

	VMINT callcount = 0;

	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);
	vm_log_debug("vm_callout_ucm_callback : callcount=%d", callcount);
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
		
	}

	if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
	{
		VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_CALLOUT, resid);
		vm_res_get_callback(VM_RES_TYPE_CALLOUT, resid, (void**)&callout_callback);
		vm_res_get_data(VM_RES_TYPE_CALLOUT, resid, (void**)&phonenum, &size);

		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (callout_callback != NULL)
			{
				callout_callback(phonenum, vm_callout_status);
			}

			vm_pmng_reset_ctx();
		}

		if (vm_callout_status == VM_CALLOUT_IDEL)
		{
			vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);
		}
		
		vm_res_findclose(VM_RES_TYPE_CALLOUT);
		
	}
	return MMI_RET_OK;
}


static void vm_callout_process_state_pro(VM_P_HANDLE phandle, VMINT pro_state)
{
	VMINT resid = 0;
	
	switch(pro_state)
	{
		case VM_PMNG_UNLOAD:
			while ((resid = vm_res_findfirst(phandle, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
			{
				vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);		
				vm_res_findclose(VM_RES_TYPE_CALLOUT);		
			}				
			while ((resid = vm_res_findfirst(phandle, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
			{
			    srv_ucm_single_call_act_req_struct req;
                memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));
                
                srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,NULL);
                
				vm_res_release_data(VM_RES_TYPE_IVR, resid);		
				vm_res_findclose(VM_RES_TYPE_IVR);		
			}
			break;
		case VM_PMNG_FOREGROUND:
			break;
		case VM_PMNG_BACKGROUND:
			break;
	}
}


static void vm_callout_initial(void)
{
	VMINT callcount = 0;

	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	
	
	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}
	
	mmi_frm_cb_reg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, vm_callout_process_state_pro);	
	vm_res_type_set_notify_callback(VM_RES_TYPE_IVR, vm_callout_process_state_pro);	
}

static void vm_callout_finialize(void)
{
	VMINT callcount = 0;

	vm_res_type_set_notify_callback(VM_RES_TYPE_CALLOUT, NULL);

	mmi_frm_cb_dereg_event(EVT_ID_SRV_UCM_STATUS_CHANGE, vm_callout_ucm_callback, NULL);
	
	callcount = srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL);	

	if (callcount > 0)
	{
		vm_callout_status = VM_CALLOUT_BUSY;
	}
	else
	{
		vm_callout_status = VM_CALLOUT_IDEL;
	}

	vm_log_debug("vm_callout_finialize : callcount=%d, status=%d", callcount, vm_callout_status);
}

 static VMINT vm_callout_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
		case EVT_MOD_INIT:
			vm_callout_initial();
			break;
 		case EVT_MOD_RELEASE:
			vm_callout_finialize();
			break;
	}
	return 0;
}

 VMINT _vm_reg_callout_module(void)
{
	int res = 0;

	if ((res = _vm_reg_module("CALLOUT MODULE", (MOD_EVT_PROCESS)vm_callout_mod_evt_proc)) 
		!= REG_MRE_MODULE_SUCCESS)
	{
		vm_log_debug("_vm_reg_callout_modual : failed to register callout module. errorcode=%d", res);
	}
	return res;
}

 static VMINT vm_available_phnum(VMWSTR phnum)
{
	while(*phnum != 0)
	{
		if (   *phnum != (VMWCHAR)L'0'
			&& *phnum != (VMWCHAR)L'1'
			&& *phnum != (VMWCHAR)L'2'
			&& *phnum != (VMWCHAR)L'3'
			&& *phnum != (VMWCHAR)L'4'
			&& *phnum != (VMWCHAR)L'5'
			&& *phnum != (VMWCHAR)L'6'
			&& *phnum != (VMWCHAR)L'7'
			&& *phnum != (VMWCHAR)L'8'
			&& *phnum != (VMWCHAR)L'9'
			&& *phnum != (VMWCHAR)L'P'
			&& *phnum != (VMWCHAR)L'*'
			&& *phnum != (VMWCHAR)L'+'
			&& *phnum != (VMWCHAR)L'#')
		{
			return FALSE;
		}
		phnum++;
	}
	return TRUE;
}

VMINT vm_callout_ex(VMWSTR phnum, VM_CALLOUT_RESPONSE_T callback)
{
	VM_P_HANDLE phandle =  vm_pmng_get_current_handle();
//	VMINT resid = -1;
	
	mmi_ucm_make_call_para_struct  make_call_para;
	VMUINT16 gid = 0;  
	
#ifdef __MMI_MRE_AUTH_SUPPORT__
    if (!srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_CALLOUT))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_FAIL );
        return -404;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_SUCCESS );
#endif

	if (vm_pmng_state(phandle) != VM_PMNG_FOREGROUND)
	{
		vm_log_debug("vm_callout: state is not foreground");
		return VM_CALLOUT_ERR_STATE;
	}
#if defined(__MRE_SAL_SIM__) && !defined(__MMI_WEARABLE_DEVICE__)
 
	if (vm_sim_card_count() <= 0)
	{
		vm_log_debug("vm_callout: no sim card");
		return VM_CALLOUT_ERR_NO_SIM;
	}
#endif
#ifdef __MMI_TELEPHONY_SUPPORT__
	if (!srv_mode_switch_is_network_service_available())
	{
		vm_log_debug("vm_callout: flight mode");
		return VM_CALLOUT_ERR_FLIGHT;
	}
#endif
	if (vm_callout_status != VM_CALLOUT_IDEL)
	{
		vm_log_debug("vm_callout: device is busy now");
		return VM_CALLOUT_ERR_BUSY;
	}
	 
	if (phnum == NULL)
	{
		vm_log_debug("vm_callout : the ptr of phnum is NULL");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if ((vm_wstrlen(phnum) <= 0) || (vm_wstrlen(phnum) >= 40))
	{
		vm_log_debug("vm_callout : the len of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (vm_available_phnum(phnum) == FALSE)
	{
		vm_log_debug("vm_callout : the content of phnum is error");
		return VM_CALLOUT_ERR_PHONE_NUM;
	}
	if (phandle < 0)
	{
		vm_log_debug("vm_callout : phandle is error");
		return VM_CALLOUT_ERR_PROCESS;
	}
	 
	if ((vm_res_save_data(VM_RES_TYPE_CALLOUT, phnum, (vm_wstrlen(phnum) * 2), (void*)callback, phandle)) < 0)
	{
	    VMINT resid = -1;
	    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_CALLOUT)) != VM_RES_NOT_FIND)
    	{
    		vm_res_release_data(VM_RES_TYPE_CALLOUT, resid);   		
    		vm_res_findclose(VM_RES_TYPE_CALLOUT);    		
    	}
		
		if ((vm_res_save_data(VM_RES_TYPE_CALLOUT, phnum, (vm_wstrlen(phnum) * 2), (void*)callback, phandle)) < 0)
		{
		    vm_log_debug("vm_callout: res save error");
		    return VM_CALLOUT_ERR_NO_RES;
		}
	}

 
	vm_log_debug("vm_callout : before mmi_ucm_init_call_para");
#if !defined(__IOT__)
	mmi_ucm_init_call_para(&make_call_para);  
#endif
	vm_log_debug("vm_callout : after mmi_ucm_init_call_para");
#ifndef __MMI_WEARABLE_DEVICE__
    switch (vm_sim_get_active_sim_card())
    {
    case 1:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE;
        break;
    case 2:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        break;
    case 3:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        break;
    case 4:
        make_call_para.dial_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        break;
    default:
        return VM_CALLOUT_ERR_NO_SIM;
    }
#endif /* __MMI_WEARABLE_DEVICE__ */
	make_call_para.ucs2_num_uri = (U16*)phnum;
    
	vm_log_debug("vm_callout : before mmi_ucm_call_launch");
#if !defined(__IOT__)
	mmi_ucm_call_launch(gid, &make_call_para);	
#endif
	vm_log_debug("vm_callout : after mmi_ucm_call_launch");
	
	return VM_CALLOUT_NO_ERR;
}

void vm_callout(VMWSTR phnum) 
{
	vm_callout_ex(phnum, NULL);
}

static mmi_id g_vm_dialer_id = 0;

extern vm_dialer_launch_adp(VMSTR phone_num);

static mmi_ret vm_dialer_proce(mmi_event_struct *event)
{
    mmi_ret ret = MMI_RET_OK;

    switch (event->evt_id)
    {
        case EVT_ID_CUI_DIALER_CLOSE_REQ:
        #if !defined(__IOT__)
            cui_dialer_close(g_vm_dialer_id);
        #endif
            break;
        default:
            ret = MMI_RET_OK;
            break;
    }

    return ret;
}

VMINT vm_dialer_launch(VMWSTR phone_num)
{
#ifndef __COSMOS_MMI_PACKAGE__
    mmi_id parent_id;

    parent_id = mmi_frm_group_create_ex(GRP_ID_ROOT, GRP_ID_AUTO_GEN, vm_dialer_proce, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

#if defined(__IOT__)
    g_vm_dialer_id = 0;
#else
    g_vm_dialer_id = cui_dialer_create(parent_id);
#endif

    if (g_vm_dialer_id <= 0)
    {
        return -2;
    }
    
    if (phone_num)
    {
    #if !defined(__IOT__)
        cui_dialer_set_dial_string(g_vm_dialer_id, (WCHAR *)phone_num);
    #endif
    }

#if !defined(__IOT__)
    cui_dialer_run(g_vm_dialer_id);
#endif
#else
    vm_dialer_launch_adp((VMSTR)phone_num);
#endif    
    return 0;
}

static void _vm_ivr_send_indication(void)
{
    srv_ucm_send_indication(SRV_UCM_INCOMING_CALL_IND,&g_vm_ivr_incoming_data);
}

static mmi_ret _vm_ivr_end_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_end_callback %d",rsp->result_info.result);
    
    StartTimer(0xefda,1000,_vm_ivr_send_indication);
}
/*
static mmi_ret _vm_ivr_end_all_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    srv_ucm_single_call_act_req_struct req;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_end_all_callback %d",rsp->result_info.result);

    memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));   
//    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,_vm_ivr_end_callback);  
}
*/
static void _vm_ivr_handler_timer_cb(void)
{
    srv_ucm_single_call_act_req_struct req;

	memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));   
    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,_vm_ivr_end_callback);                
//    srv_ucm_act_request(SRV_UCM_END_ALL_PROCESSING_ACT,NULL,NULL,_vm_ivr_end_all_callback);
}

mmi_ret vm_ivr_handler(mmi_event_struct *param)
{
    mmi_ret result = MMI_RET_OK;
    ivr_callback_data data;
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)param->user_data;
    VMINT resid = -1;

    data.status = VM_IVR_CALLED_OUT;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler1 %d", param->evt_id);
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	    
        VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
        void* user_data;
        VMINT size = 4;
        vm_ivr_cb callback;        

        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler");
        
        vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
        vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
        data.user_data = user_data;
        
	    if (EVT_ID_SRV_UCM_STATUS_CHANGE == param->evt_id)
        {                
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
        	{
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"1");
                data.status = VM_IVR_CALL_END;
        		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}
        		vm_res_release_data(VM_RES_TYPE_IVR, resid);
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"2");
        	}
        	else
        	{
        	    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"3");
        	    data.status = VM_IVR_CALLED_OUT;
        	    if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"4");
        	}
        	result = MMI_RET_ERR;
        }
        else if (EVT_ID_SRV_UCM_INDICATION == param->evt_id)
        {
            srv_ucm_ind_evt_struct* evt_struct = (srv_ucm_ind_evt_struct*)param;
            
            if (SRV_UCM_OUTGOING_CALL_IND == evt_struct->ind_type)
            {                
                srv_ucm_outgoing_call_ind_struct* info = (srv_ucm_outgoing_call_ind_struct*)evt_struct->ptr;
                memcpy(&g_vm_ivr_call_info,&info->uid_info,sizeof(g_vm_ivr_call_info));
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler%d,%d",g_vm_ivr_call_info.group_id,g_vm_ivr_call_info.call_id);

                result = MMI_RET_ERR;
            }            
            else if (SRV_UCM_INCOMING_CALL_IND == evt_struct->ind_type)
            {    
                srv_ucm_single_call_act_req_struct req;
                
                MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"6");
                data.status = VM_IVR_INTERRUPT;
        		if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
        		{
        			if (callback != NULL)
        			{
        				callback(&data);
        			}

        			vm_pmng_reset_ctx();
        		}       

                memcpy(&g_vm_ivr_incoming_data,evt_struct->ptr,sizeof(g_vm_ivr_incoming_data));
                vm_res_release_data(VM_RES_TYPE_IVR, resid);
                
        		StartTimer(0xefda,100,_vm_ivr_handler_timer_cb);
#if 0        		
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif                
        		MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"7");
        		result = MMI_RET_ERR;
            }
            else
            {
                 MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"8");
                result = MMI_RET_ERR;
            }
            
        }
        else if (EVT_ID_SRV_UCM_ACTION_NOTIFY == param->evt_id)
        {
            MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"9");
            result = MMI_RET_ERR;
        }	
        vm_res_findclose(VM_RES_TYPE_IVR);
	}
	MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_handler end %d,%d",result,data.status);
	return result;    
}


static mmi_ret _vm_ivr_call_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback 1");
    
    if (rsp && SRV_UCM_RESULT_OK != rsp->result_info.result)
    {
        VMINT resid = -1;
        
        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback fail");
        
        if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
    	{	
            VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
            void* user_data;
            VMINT size = 4;
            vm_ivr_cb callback;
            ivr_callback_data data;

            MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"1");
            
            vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
            vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
            data.user_data = user_data;
            data.status = VM_IVR_FAIL;

            if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
    		{
    			if (callback != NULL)
    			{
    				callback(&data);
    			}

    			vm_pmng_reset_ctx();
    		}
    		vm_res_release_data(VM_RES_TYPE_IVR, resid);
    		vm_res_findclose(VM_RES_TYPE_IVR);
        }        
    }
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_call_callback end");
    return MMI_RET_OK; 
}

VMINT vm_ivr_call(vm_ivr_call_data* data)
{   
    VMINT result = 0;
    srv_ucm_dial_act_req_struct req;
    
#ifdef __MMI_MRE_AUTH_SUPPORT__
    if (!srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_CALLOUT))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_FAIL );
        return -404;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_SUCCESS );
#endif

    memset(&req, 0, sizeof(req));
    if (data->sim_card > vm_sim_max_card_count() || data->sim_card < 1)
    {
        result = -2;
        goto error;
    }

	if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
	{
	    result = -3;
        goto error;
	}
	
    if ((vm_res_save_data(VM_RES_TYPE_IVR, data->user_data, 4, (void*)data->callback, vm_pmng_get_current_handle())) < 0)
	{
		result = -4;
        goto error;
	}
	
	//req.call_type = 1<< ((data->sim_card-1)*8);
	switch (data->sim_card)
	{
    case 1:
        req.call_type = SRV_UCM_VOICE_CALL_TYPE;
        break;
    case 2:
        req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM2;
        break;
    case 3:
        req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM3;
        break;
    case 4:
        req.call_type = SRV_UCM_VOICE_CALL_TYPE_SIM4;
        break;
    default:
		result = -5;
        goto error;
        break;
	}
	kal_wstrncpy(req.num_uri,data->phone_num,SRV_UCM_MAX_NUM_URI_LEN+1);
	req.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
	req.is_ip_dial = 0;
	req.phb_data = NULL;
	
	srv_ucm_act_request(SRV_UCM_DIAL_ACT,&req,NULL,_vm_ivr_call_callback);
error:
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_call %d,%d",result,data->sim_card);
    return result;
}

/*
static mmi_ret _vm_ivr_dial_callback(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;
    VMINT resid = -1;

    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback 1");
    
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
        VM_P_HANDLE phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
        void* user_data;
        VMINT size = 4;
        vm_ivr_cb callback;
        ivr_callback_data data;

        MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback %d",rsp->result_info.result);
        
        vm_res_get_callback(VM_RES_TYPE_IVR, resid, (void**)&callback);
        vm_res_get_data(VM_RES_TYPE_IVR, resid, (void**)&user_data, &size);
        data.user_data = user_data;
        

		if (rsp && SRV_UCM_RESULT_OK == rsp->result_info.result)
        {
            data.status = VM_IVR_DIALED;
        }
        else
        {
            data.status = VM_IVR_DIAL_FAIL;
        }
        
        if (vm_pmng_set_ctx(phandle) == VM_PMNG_OP_OK)
		{
			if (callback != NULL)
			{
				callback(&data);
			}

			vm_pmng_reset_ctx();
		}
		vm_res_findclose(VM_RES_TYPE_IVR); 
    }   
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"_vm_ivr_dial_callback end");
    return MMI_RET_OK; 
}
*/
VMINT vm_ivr_dial_number(VMCHAR number)
{
    VMINT result = 0;
    srv_ucm_dtmf_struct digits;
    mmi_keypads_enum key;
    VMINT resid =1;
    
    if (!number)
    {
        result = -2;
        goto error;
    }

    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
	    VM_P_HANDLE phandle;
	    
	    vm_res_findclose(VM_RES_TYPE_IVR);
	    phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
	    if (vm_pmng_get_current_handle() != phandle)
	    {
	        result = -3;
	        goto error;
	    }
		
    }   
    else
    {
        result = -4;
        goto error;
    }

	switch (number)
	{
	case '1':
	    key = KEY_1;
	    break;
	case '2':
	    key = KEY_2;
	    break;
	case '3': 
	    key = KEY_3;
	    break;
	case '4':
	    key = KEY_4;
	    break;
	case '5':
	    key = KEY_5;
	    break;
	case '6':
	    key = KEY_6;
	    break;
	case '7':
	    key = KEY_7;
	    break;
	case '8':
	    key = KEY_8;
	    break;
	case '9':
	    key = KEY_9;
	    break;
	case '0':
	    key = KEY_0;
	    break;
    case '*':
	    key = KEY_STAR;
	    break;
    case '#':
	    key = KEY_POUND;
	    break;	
    default:
        result = -5;
        goto error;
	}	
	
	digits.digit = key;
	srv_ucm_act_request(SRV_UCM_START_DTMF_ACT,&digits,NULL,NULL);
	srv_ucm_act_request(SRV_UCM_STOP_DTMF_ACT,&digits,NULL,NULL);
error:	
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_dial_number %d",result);
	return result;
}

VMINT vm_ivr_end(void)
{
    VMINT result = 0;
    VMINT resid = -1;
    srv_ucm_single_call_act_req_struct req;
    
    if ((resid = vm_res_findfirst(-1, VM_RES_TYPE_IVR)) != VM_RES_NOT_FIND)
	{	
	    VM_P_HANDLE phandle;
	    
	    vm_res_findclose(VM_RES_TYPE_IVR);	    
	    phandle = vm_res_get_process_handle(VM_RES_TYPE_IVR, resid);
	    if (vm_pmng_get_current_handle() != phandle)
	    {
	        result = -2;
	        goto error;
	    }		
    }   
    else
    {
        result = -3;
        goto error;
    }
    memcpy(&req.action_uid,&g_vm_ivr_call_info,sizeof(req.action_uid));
    
    srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT,&req,NULL,NULL);
error:
    MMI_PRINT(MOD_MRE,TRACE_GROUP_9,"vm_ivr_end %d,%d,%d",result,req.action_uid.group_id,req.action_uid.call_id);
    return result;
}


#include "vmpromng.h"

typedef struct
{
    VMINT res_id;
    VM_P_HANDLE p_hdl;
    
    // actions
    vm_call_actions_func act_cb;
    vm_call_actions_callback_data act_rsp_data;
    
    // register (indication)
    vm_call_listener_func ind_cb;
    vm_call_listener_data ind_cb_data;

    // current uid
    srv_ucm_id_info_struct curr_uid_info;
    
}vm_call_context_t;

static void vm_call_free_ctx(vm_call_context_t * ctx_p);

static void vm_call_free_resource(VM_P_HANDLE phdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_call_context_t * ctx_p = NULL;

    while ((resHandle = vm_res_findfirst(phdl, VM_RES_TYPE_TEL)) 
        != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TEL, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            //vm_call_exit(ctx_p->res_id);
            // TODO: end call or sth.
            srv_ucm_act_request(SRV_UCM_END_SINGLE_ACT, (void *)&(ctx_p->curr_uid_info), NULL, NULL);
            vm_call_free_ctx(ctx_p);
        }
        else
        {
        }
        //vm_res_release_data(VM_RES_TYPE_BTGATT, resHandle);
        vm_res_findclose(VM_RES_TYPE_TEL); 
    }

}

static void vm_call_notify_process_status(VM_P_HANDLE process_handle, 
    VMINT sys_state)
{

    switch (sys_state)
    {
    case VM_PMNG_UNLOAD:
        vm_call_free_resource(process_handle);
        break;
    }
}


static VMINT vm_call_initialize_resource(void)
{
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_134 );
    if (vm_res_type_set_notify_callback(VM_RES_TYPE_TEL, 
        vm_call_notify_process_status) != 0)
    {
        return -1;
    }



    return 0;
}

static VMINT vm_call_finialize_resource(void)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_call_context_t* ctx_p = NULL;

    vm_call_free_resource(-1);

    
    vm_res_type_set_notify_callback(VM_RES_TYPE_TEL, NULL);


    return 0;
}

static VMINT vm_call_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
    switch(event)
    {
    case EVT_MOD_INIT:
        if (vm_call_initialize_resource() != 0)
            return -1;
        break;
    case EVT_MOD_RELEASE:
        vm_call_finialize_resource();
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

VMINT _vm_reg_call_module(void)
{
    int res_code = REG_MRE_MODULE_SUCCESS;
    
    if ((res_code = _vm_reg_module("TELE MODULE", (MOD_EVT_PROCESS)vm_call_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
    {
    }

    return res_code;
}

static vm_call_context_t * vm_call_get_ctx(VM_P_HANDLE p_hdl)
{
    VMINT resHandle = 0, bufSize = 0;
    vm_call_context_t * ctx_p = NULL;
    //ASSERT(uuid != NULL);
    if ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_TEL)) != VM_RES_NOT_FIND)
    {
        if (vm_res_get_data(VM_RES_TYPE_TEL, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
        {
            if (p_hdl == ctx_p->p_hdl)
            {
                vm_res_findclose(VM_RES_TYPE_TEL);
                return ctx_p;
            }
        }

        while ((resHandle = vm_res_findnext(-1, VM_RES_TYPE_TEL)) != VM_RES_NOT_FIND)
        {
            if (vm_res_get_data(VM_RES_TYPE_TEL, 
            resHandle, (void**)&ctx_p, &bufSize) == 0 && ctx_p != NULL)
            {
                if (p_hdl == ctx_p->p_hdl)
                {
                    vm_res_findclose(VM_RES_TYPE_TEL);
                    return ctx_p;
                }
            }
        }
        vm_res_findclose(VM_RES_TYPE_TEL);
    }   
    return NULL;
}


static vm_call_context_t * vm_call_malloc_ctx(void)
{
    vm_call_context_t * ctx_p = NULL;

    if ((ctx_p = vm_calloc(sizeof(vm_call_context_t))) != NULL)
    {
        if ((ctx_p->res_id = vm_res_save_data(VM_RES_TYPE_TEL, 
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

static void vm_call_free_ctx(vm_call_context_t * ctx_p)
{
    if (ctx_p)
    {
        vm_res_release_data(VM_RES_TYPE_TEL, ctx_p->res_id);
        if (VM_RES_OK == vm_res_release_data(VM_RES_TYPE_TEL, ctx_p->res_id))
        {
            vm_free(ctx_p);
        }
    }
}

extern _vm_pcb_t* pcb_table[];
mmi_ret vm_call_int_ind_handler(mmi_event_struct *param)
{
    //srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)param->user_data;
    mmi_ret ret = MMI_RET_OK;
    VMINT i = 0;
    vm_call_context_t *ctx_p = NULL;
    _vm_pcb_t* pcb = NULL;

    
#ifdef __IOT__
    VMINT num = vm_pmng_current_counter();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, 0, param->evt_id);
    if (0 == num)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E1, 0, __LINE__);
        return ret;
    }
#else
    VM_P_HANDLE phdl = vm_pmng_fg_process();
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, 0, param->evt_id);
    if (0 == phdl)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E2, 0, __LINE__);
        return ret;
    }
#endif

#ifdef __IOT__
	pcb = pcb_table[VM_PMNG_BACKGROUND];
#else
	pcb = pcb_table[VM_PMNG_FOREGROUND];
#endif

	for (; pcb != NULL; pcb = pcb->next_pcb)
	{
        ctx_p = vm_call_get_ctx(pcb->pHandle);
        if (NULL == ctx_p)
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E3, 0, __LINE__);
            continue;
        }

        
        if (EVT_ID_SRV_UCM_STATUS_CHANGE == param->evt_id)
        {                
            if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
            {
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
                #endif
            }
            else
            {
                //data.status = VM_IVR_CALLED_OUT;
            }
            ret = MMI_RET_ERR;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E9, 0, __LINE__);
        }
        else if (EVT_ID_SRV_UCM_INDICATION == param->evt_id)
        {
            srv_ucm_ind_evt_struct* evt_struct = (srv_ucm_ind_evt_struct*)param;
            
            if (SRV_UCM_OUTGOING_CALL_IND == evt_struct->ind_type)
            {                
                srv_ucm_outgoing_call_ind_struct* mo = (srv_ucm_outgoing_call_ind_struct*)evt_struct->ptr;
                vm_ucm_outgoing_call_ind_struct app_mo = {0};
                if (NULL == mo)
                {
                    // TODO: error log
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E8, 0, __LINE__);
                    continue;
                }

                // set current uid
                memcpy(&(ctx_p->curr_uid_info), &(mo->uid_info), sizeof(ctx_p->curr_uid_info));

                memcpy(app_mo.num_uri, mo->remote_info.num_uri, sizeof(app_mo.num_uri));
                app_mo.uid_info.call_type = mo->uid_info.call_type;
                app_mo.uid_info.group_id = mo->uid_info.group_id;
                app_mo.uid_info.call_id = mo->uid_info.call_id;

                ctx_p->ind_cb_data.type_op = VM_UCM_OUTGOING_CALL_IND;
                ctx_p->ind_cb_data.data = (void *)&app_mo;
                PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    ctx_p->ind_cb(&(ctx_p->ind_cb_data)));

                ret = MMI_RET_ERR;
                MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E4, app_mo.uid_info.call_id, __LINE__);
            }            
            else if (SRV_UCM_INCOMING_CALL_IND == evt_struct->ind_type)
            {    
                srv_ucm_incoming_call_ind_struct *mt = (srv_ucm_incoming_call_ind_struct*)evt_struct->ptr;
                vm_ucm_incoming_call_ind_struct app_mt = {0};
                if (NULL == mt)
                {
                    // TODO: error log
                    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E5, 0, __LINE__);
                    continue;
                }

                
                // set current uid
                memcpy(&(ctx_p->curr_uid_info), &(mt->uid_info), sizeof(ctx_p->curr_uid_info));
                
                memcpy(app_mt.num_uri, mt->remote_info.num_uri, sizeof(app_mt.num_uri));
                app_mt.uid_info.call_type = mt->uid_info.call_type;
                app_mt.uid_info.group_id = mt->uid_info.group_id;
                app_mt.uid_info.call_id = mt->uid_info.call_id;

                ctx_p->ind_cb_data.type_op = VM_UCM_INCOMING_CALL_IND;
                ctx_p->ind_cb_data.data = (void *)&app_mt;
                PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    ctx_p->ind_cb(&(ctx_p->ind_cb_data)));

                ret = MMI_RET_ERR;
                MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E6, app_mt.uid_info.call_id, __LINE__);
            }
            else if (SRV_UCM_CONNECT_IND == evt_struct->ind_type)
            {
                srv_ucm_connect_ind_struct *connect = (srv_ucm_connect_ind_struct *)evt_struct->ptr;
                vm_ucm_connect_ind_struct app_connect = {0};

                // set current uid
                memcpy(&(ctx_p->curr_uid_info), &(connect->uid_info), sizeof(ctx_p->curr_uid_info));
                
                app_connect.uid_info.call_type = connect->uid_info.call_type;
                app_connect.uid_info.group_id = connect->uid_info.group_id;
                app_connect.uid_info.call_id = connect->uid_info.call_id;
                
                ctx_p->ind_cb_data.type_op = VM_UCM_CONNECT_IND;
                ctx_p->ind_cb_data.data = (void *)&app_connect;
                PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    ctx_p->ind_cb(&(ctx_p->ind_cb_data)));
            }
            else if (SRV_UCM_RELEASE_IND == evt_struct->ind_type)
            {
                ctx_p->ind_cb_data.type_op = VM_UCM_CALL_END;
                ctx_p->ind_cb_data.data = NULL;
                PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                    ctx_p->ind_cb(&(ctx_p->ind_cb_data)));
                    
                //vm_call_free_ctx(ctx_p);
                MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E8, 0, __LINE__);
            }
        }
        else if (EVT_ID_SRV_UCM_ACTION_NOTIFY == param->evt_id)
        {
            
            //srv_ucm_act_notify_evt_struct
            ret = MMI_RET_ERR;
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E7, ret, __LINE__);
        }
        
    }
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E, ret, __LINE__);
    return ret;
}

static mmi_ret vm_call_int_action_cb(mmi_event_struct *param)
{
    srv_ucm_act_rsp_struct* rsp = (srv_ucm_act_rsp_struct*)((srv_ucm_act_result_evt_struct*)param)->act_result;

    if (rsp/* && SRV_UCM_RESULT_OK != rsp->result_info.result*/)
    {
        VM_P_HANDLE phdl = (VM_P_HANDLE)((srv_ucm_act_result_evt_struct*)param)->user_data;
        VMINT resid = -1, bufSize = 0;
        vm_call_context_t *ctx_p = NULL;
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, 1, phdl);

        ctx_p = vm_call_get_ctx(phdl);
        if (NULL != ctx_p)
        {
            ctx_p->act_rsp_data.data_act_rsp.no_counter = rsp->no_counter;
            ctx_p->act_rsp_data.data_act_rsp.result_info.result = rsp->result_info.result;
            memcpy(ctx_p->act_rsp_data.data_act_rsp.result_info.error_msg, rsp->result_info.error_msg, 
                sizeof(ctx_p->act_rsp_data.data_act_rsp.result_info.error_msg));
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_LOG, 
                ctx_p->act_rsp_data.data_act_rsp.no_counter,
                ctx_p->act_rsp_data.data_act_rsp.result_info.result,
                0,
                0,
                0,
                0,
                1, __LINE__);
            PMNG_WRAP_CALLBACK(ctx_p->p_hdl, 
                ctx_p->act_cb(&(ctx_p->act_rsp_data)));
            
            
            //vm_call_free_ctx(ctx_p);
        }
        
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E, 1, __LINE__);
    }

    return MMI_RET_OK; 
}

static VMINT vm_call_sim_check(VMINT call_type)
{
    // TODO:
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, call_type, __LINE__);
    switch (call_type)
    {
    case VM_UCM_VOICE_CALL_TYPE:
    case VM_UCM_VOICE_CALL_TYPE_SIM2:
    case VM_UCM_VOICE_CALL_TYPE_SIM3:
    case VM_UCM_VOICE_CALL_TYPE_SIM4:
        break;
    default:
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E1, 2, __LINE__);
            return -2;
        }break;
    }

    // here is a call
    if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_ALL, SRV_UCM_CALL_TYPE_ALL, NULL) > 0)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E2, 2, __LINE__);
        return -3;
    }

    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E, 2, __LINE__);
    return 0;

}

VMINT vm_call_reg_listener(vm_call_listener_func func)
{
    
    //vm_call_listener_func ind_cb;
    //vm_call_listener_data ind_cb_data;
    vm_call_context_t *ctx_p = NULL;

    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, 3, __LINE__);
    if (NULL == func)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E1, 3, __LINE__);
        return -2;
    }
    ctx_p = vm_call_malloc_ctx();
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E2, 3, __LINE__);
        return -3;
    }

    ctx_p->ind_cb = func;
    
    //ctx_p->ind_cb_data. = func;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E, 3, __LINE__);
    return 0;
}

VMINT vm_call_actions(const vm_call_actions_data *data)
{
    VMINT result = 0;
    srv_ucm_dial_act_req_struct act_dial = {0};
    vm_ucm_single_call_act_req_struct act_accept = {0};
    vm_ucm_single_group_act_req_struct act_hold = {0};
    vm_ucm_single_call_act_req_struct act_end = {0};
    VMINT ret = 0;
    void *act = NULL;
    srv_ucm_act_opcode_enum opcode;

    vm_call_context_t *ctx_p = NULL;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_S, 4, __LINE__);
#ifdef __MMI_MRE_AUTH_SUPPORT__
    if (!srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_CALLOUT))
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_FAIL );
        return -404;
    }
    MMI_TRACE(MMI_MRE_TRC_MOD_VMBTCM, TRC_MRE_VMBTCM_CALL_OUT_SUCCESS );
#endif

    if (NULL == data || NULL == data->data_act)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E1, 4, __LINE__);
        return -2;
    }

    ctx_p = vm_call_get_ctx(vm_pmng_get_current_handle());
    if (NULL == ctx_p)
    {
        MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E2, 4, __LINE__);
        return -3;
    }

    // full fil the vm_call_actions_callback_data
    ctx_p->act_rsp_data.type_act = data->type_act;
    ctx_p->act_rsp_data.userdata = data->userdata;
    
    ctx_p->act_cb = data->callback;
    
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_LOG, 
        ctx_p->act_rsp_data.type_act,
        ctx_p->p_hdl,
        0,
        0,
        ctx_p->act_cb,
        ctx_p->act_rsp_data.userdata,
        4, __LINE__);
        
    switch (data->type_act)
    {
        case VM_UCM_DIAL_ACT:
        {
            vm_ucm_dial_act_req_struct *app_act_dial = (vm_ucm_dial_act_req_struct *)data->data_act;
            act_dial.call_type = app_act_dial->call_type;
            memcpy(act_dial.num_uri, app_act_dial->num_uri, sizeof(act_dial.num_uri));
            act_dial.module_id = app_act_dial->module_id;
            act_dial.is_ip_dial = app_act_dial->is_ip_dial;
            act_dial.phb_data = app_act_dial->phb_data;

            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E3, act_dial.call_type, __LINE__);
            if (0 != vm_call_sim_check(act_dial.call_type))
            {
                MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E4, 4, __LINE__);
                return -4;
            }

            act = (void *)&act_dial;
            opcode = SRV_UCM_DIAL_ACT;
        }break;
        case VM_UCM_ACCEPT_ACT:
        {
            vm_ucm_single_call_act_req_struct *app_act_accept = (vm_ucm_single_call_act_req_struct *)data->data_act;
            act_accept.action_uid.call_type = app_act_accept->action_uid.call_type;
            act_accept.action_uid.group_id = app_act_accept->action_uid.group_id;
            act_accept.action_uid.call_id = app_act_accept->action_uid.call_id;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E5, act_accept.action_uid.call_id, __LINE__);

            act = (void *)&act_accept;
            opcode = SRV_UCM_ACCEPT_ACT;
        }break;
        case VM_UCM_HOLD_ACT:
        {
            vm_ucm_single_group_act_req_struct *app_act_hold = (vm_ucm_single_group_act_req_struct *)data->data_act;
            act_hold.call_type = app_act_hold->call_type;
            act_hold.action_group = app_act_hold->action_group;

            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E6, act_hold.call_type, __LINE__);
            act = (void *)&act_hold;        
            opcode = SRV_UCM_HOLD_ACT;
        }break;
        case VM_UCM_END_SINGLE_ACT:
        {
            vm_ucm_single_call_act_req_struct *app_act_end = (vm_ucm_single_call_act_req_struct *)data->data_act;
            act_end.action_uid.call_type = app_act_end->action_uid.call_type;
            act_end.action_uid.group_id = app_act_end->action_uid.group_id;
            act_end.action_uid.call_id = app_act_end->action_uid.call_id;
            
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E7, act_accept.action_uid.call_id, __LINE__);
            act = (void *)&act_end;
            opcode = SRV_UCM_END_SINGLE_ACT;
        }break;
        default:
        {
            MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E4, 4, __LINE__);
            return -5;
        }break;
    }
	
	srv_ucm_act_request(opcode, act, (void *)ctx_p->p_hdl, vm_call_int_action_cb);
    MMI_TRACE(MMI_MRE_TRC_MOD_VMTEL, TRC_MRE_CALL_E, 4, __LINE__);
    return 0;
}

VMINT vm_get_tell_sym(VMCHAR* func_name)
{
    if(strcmp(func_name,"vm_call_actions") == 0)
        return (VMINT)vm_call_actions;           
    if(strcmp(func_name,"vm_call_reg_listener") == 0)
        return (VMINT)vm_call_reg_listener;    

    return 0;
}


#endif //__MRE_SAL_TELE__
 
