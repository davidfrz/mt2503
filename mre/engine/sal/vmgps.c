#include "vmswitch.h"
#ifdef __MRE_SAL_GPS__
#include "vmsys.h"
#include "vmlog.h"
#include "vmpromng.h"
#include "vmresmng.h"
#include "vmmod.h"
#include "vmsalgps.h"
#include "vmgps.h"
#include "vmmacrostub.h"
#include "MMI_trc.h"
#include "gps_struct.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "stack_ltlcom.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "MREAppMgrSrvGprot.h"
#include "vmstdlib.h"

#define REG_GPS_MODULE_FAILED -2


extern VMINT mre_running;

vm_gps_sentence_info *vm_gps_sentence_info_p = NULL;

static void vm_gps_modual_initialize(void);
static void vm_gps_modual_finialize(void);
static VMINT vm_gps_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event);
static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state);
static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle);
static VMINT vm_gps_res_save_data_faild(VM_GPS_CAlLBACK_FUNC callback);
static void vm_gps_send_msg(msg_type msg_id, module_type dst_mod_id, sap_type sap_id, local_para_struct *p_local_para);
static VMUINT8 vm_gps_sentence_data_hdlr(void *msg);
static VMUINT8 vm_gps_poweron_hdlr(void *msg);
static VMUINT8 vm_gps_poweroff_hdlr(void *msg);
static VMUINT8 vm_gps_startmode_hdlr(void *msg);
static VMUINT8 vm_gps_set_param_hdlr(void *msg);

VMINT _vm_reg_gps_modual(void)
{
	int res_code = REG_MRE_MODULE_SUCCESS;
	
	if ((res_code = _vm_reg_module("GPS MODUAL", (MOD_EVT_PROCESS)vm_gps_mod_evt_proc)) != REG_MRE_MODULE_SUCCESS)
	{
		MMI_TRACE(TRACE_GROUP_5,TRC_MRE_GPS_FAIL_TO_REGISTER_MODULE,res_code);
	}

	return res_code;
}

static VMINT vm_gps_mod_evt_proc(MRE_MOD_LIFECIRCLE_EVT event)
{
	switch(event)
	{
	case EVT_MOD_INIT:
		vm_gps_modual_initialize();
		break;
	case EVT_MOD_RELEASE:
		vm_gps_modual_finialize();
		break;
	default:
		return REG_GPS_MODULE_FAILED;
	}

	return REG_MRE_MODULE_SUCCESS;
}

static void vm_gps_notify_process_handler(VM_P_HANDLE process_handle, VMINT sys_state)
{
	if (sys_state == VM_PMNG_UNLOAD)
	{
		vm_gps_delete_cur_process_res(process_handle);
	}
}


static void vm_gps_modual_initialize(void)
{
	vm_res_type_set_notify_callback(VM_RES_TYPE_GPS, vm_gps_notify_process_handler);
}

static void vm_gps_modual_finialize(void)
{
	VMINT resHandle = 0;

	while ((resHandle = vm_res_findfirst(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
	{
		vm_res_release_data(VM_RES_TYPE_GPS, resHandle);
		vm_res_findclose(VM_RES_TYPE_GPS); 
	}
	
	if(vm_gps_sentence_info_p != NULL)
	{					
		vm_gps_send_msg(MSG_ID_GPS_POWEROFF_REQ,MOD_GPSADAPTOR,0, (local_para_struct*)NULL);
		_vm_kernel_free(vm_gps_sentence_info_p);
		vm_gps_sentence_info_p = NULL;
	}
}

static void vm_gps_send_msg(msg_type msg_id, module_type dst_mod_id, 
                         sap_type sap_id, local_para_struct *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_ptr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_ptr = allocate_ilm(MOD_MMI);
    ilm_ptr->src_mod_id = MOD_MMI;
    ilm_ptr->dest_mod_id = dst_mod_id;
    ilm_ptr->msg_id = msg_id;
    ilm_ptr->sap_id = sap_id;
    ilm_ptr->local_para_ptr = p_local_para;
    ilm_ptr->peer_buff_ptr = NULL;
    SEND_ILM(MOD_MMI, dst_mod_id, sap_id, ilm_ptr);
}

static VMUINT8 vm_gps_sentence_data_hdlr(void *msg)
{
	gps_get_current_sentence_cnf_struct* cnf_p = (gps_get_current_sentence_cnf_struct*)msg;
	VM_GPS_CAlLBACK_FUNC cb;
	VMINT res_handle = -1;
	VMINT mtk_handle = 0;
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	memcpy(vm_gps_sentence_info_p, &cnf_p->gps_sentence_info, sizeof(gps_sentence_info_struct));

	if (mre_running == FALSE)
		return 0;

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
		{
			vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
			if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
			{
				if (cb != NULL)
				{
					cb(VM_GPS_SENTENCE_DATA, (void*)vm_gps_sentence_info_p);
				}
				vm_pmng_reset_ctx();
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{		
			if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
			{
				vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
				if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
				{
					if (cb != NULL)
					{
						cb(VM_GPS_SENTENCE_DATA, (void*)vm_gps_sentence_info_p);
					}
					vm_pmng_reset_ctx();
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
	}	
	
	return 0;
}

static VMUINT8 vm_gps_poweron_hdlr(void *msg)
{
	VMINT res_handle = -1;
	VM_GPS_CAlLBACK_FUNC cb;
	gps_poweron_cnf_struct* cnf_p = (gps_poweron_cnf_struct*)msg;
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
	{
		vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
		
		if (vm_pmng_set_ctx(cnf_p->user_data) == VM_PMNG_OP_OK)
		{
			if (cb != NULL)
			{
				cb(VM_GPS_OPEN_CNF, (void*)cnf_p->result);
			}
			vm_pmng_reset_ctx();
		}
		
		vm_res_findclose(VM_RES_TYPE_GPS);
	}	
	
	return 0;
}

static VMUINT8 vm_gps_poweroff_hdlr(void *msg)
{
	gps_poweroff_cnf_struct* cnf_p = (gps_poweroff_cnf_struct*)msg;
	return 0;
}

static VMUINT8 vm_gps_startmode_hdlr(void *msg)
{
	VMINT res_handle = -1;
	VM_GPS_CAlLBACK_FUNC cb;
	VMINT mtk_handle = 0;
	gps_start_mode_cnf_struct* cnf_p = (gps_start_mode_cnf_struct*)msg;
	
	if (mre_running == FALSE)
		return 0;

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
		{
			vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
			if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
			{
				if (cb != NULL)
				{
					cb(VM_GPS_SET_MODE_CNF, (void*)cnf_p->result);
				}
				vm_pmng_reset_ctx();
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{		
			if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
			{
				vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
				if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
				{
					if (cb != NULL)
					{
						cb(VM_GPS_SET_MODE_CNF, (void*)cnf_p->result);
					}
					vm_pmng_reset_ctx();
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
	}	
	
	return 0;
}


static VMUINT8 vm_gps_set_param_hdlr(void *msg)
{
	VMINT res_handle = -1;
	VM_GPS_CAlLBACK_FUNC cb;
	VMINT mtk_handle = 0;
	gps_set_param_cnf_struct* cnf_p = (gps_set_param_cnf_struct*)msg;
	
	if (mre_running == FALSE)
		return 0;
	
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

	if ((res_handle = vm_res_findfirst(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
	{
		if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
		{
			vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
			if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
			{
				if (cb != NULL)
				{
					cb(VM_GPS_SET_PARAM_CNF, (void*)cnf_p->result);
				}
				vm_pmng_reset_ctx();
			}
		}
		
		while ((res_handle = vm_res_findnext(-1, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{		
			if ((vm_res_get_mtk_reshandle(VM_RES_TYPE_GPS, res_handle, (VMINT *)&mtk_handle))== VM_RES_OK)
			{
				vm_res_get_callback(VM_RES_TYPE_GPS, res_handle, (void**)&cb);
				if (vm_pmng_set_ctx(mtk_handle) == VM_PMNG_OP_OK)
				{
					if (cb != NULL)
					{
						cb(VM_GPS_SET_PARAM_CNF, (void*)cnf_p->result);
					}
					vm_pmng_reset_ctx();
				}
			}
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
	}	
	
	return 0;
}

static VMINT vm_gps_delete_cur_process_res(VM_P_HANDLE process_handle)
{
	if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) > 0)
	{
		VMINT res_handle = 0;
		if ((res_handle = vm_res_findfirst(process_handle, VM_RES_TYPE_GPS)) != VM_RES_NOT_FIND)
		{
			vm_res_findclose(VM_RES_TYPE_GPS);
			vm_res_release_data(VM_RES_TYPE_GPS, res_handle);
			
			if (vm_res_get_data_list_count_by_type(VM_RES_TYPE_GPS) <= 0)
			{
				if(vm_gps_sentence_info_p != NULL)
				{										
                    gps_poweroff_req_struct* poweroff_req_p = NULL;
                    poweroff_req_p = construct_local_para(sizeof(gps_poweroff_req_struct), TD_RESET);
                    poweroff_req_p->user_data = vm_pmng_get_current_handle();
                    #ifdef __GPS_LLE_SUPPORT__
/* under construction !*/
                    #endif
					mmi_frm_clear_protocol_event_handler(MSG_ID_GPS_POWERON_CNF, (PsIntFuncPtr)vm_gps_poweron_hdlr);
					mmi_frm_clear_protocol_event_handler(MSG_ID_GPS_CURRENT_SENTENCE_IND, (PsIntFuncPtr)vm_gps_sentence_data_hdlr);
					mmi_frm_clear_protocol_event_handler(MSG_ID_GPS_SET_START_MODE_CNF, (PsIntFuncPtr)vm_gps_startmode_hdlr);
					mmi_frm_clear_protocol_event_handler(MSG_ID_GPS_SET_PARAM_CNF, (PsIntFuncPtr)vm_gps_set_param_hdlr);
					mmi_frm_clear_protocol_event_handler(MSG_ID_GPS_POWEROFF_CNF, (PsIntFuncPtr)vm_gps_poweroff_hdlr);
					
					vm_gps_send_msg(MSG_ID_GPS_POWEROFF_REQ,MOD_GPSADAPTOR,0, (local_para_struct*)poweroff_req_p);

					_vm_kernel_free(vm_gps_sentence_info_p);
					vm_gps_sentence_info_p = NULL;

					return VM_GPS_CLOSE_SUCCESS;
				}
			}
			return VM_GPS_CLOSE_STILL_APP_USE_DATA;
		}
		vm_res_findclose(VM_RES_TYPE_GPS);
		return VM_GPS_CLOSE_STILL_APP_USE_DATA;
	}
	return VM_GPS_CLOSE_FAILED;
}

static VMINT vm_gps_res_save_data_faild(VM_GPS_CAlLBACK_FUNC callback)
{
	VMINT handle;
	if (vm_res_get_data_list_count_by_proecss(vm_pmng_get_current_handle(), VM_RES_TYPE_GPS) <= 0)
	{
		if ((handle = vm_res_save_data(VM_RES_TYPE_GPS, NULL, 0, NULL, vm_pmng_get_current_handle())) < 0)
		{
			return TRUE;
		}
		else
		{
			vm_res_set_mtk_reshandle(VM_RES_TYPE_GPS, handle, (VMINT)vm_pmng_get_current_handle());
			vm_res_set_callback(VM_RES_TYPE_GPS, handle, (void*)callback);
		}
	}

	return FALSE;
}


VMINT vm_gps_open(VMUINT period, vm_gps_type_enum type, VM_GPS_CAlLBACK_FUNC callback)
{	

#ifdef __MMI_MRE_AUTH_SUPPORT__
		if(!srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_GPS))
		{
			vm_log_fatal("%s", "[Security check]gps failed");
			return VM_GPS_OPEN_RES_LESS;
		}
		vm_log_fatal("%s", "[Security check]gps success");
#endif

	if (vm_gps_res_save_data_faild(callback))
	{
		return VM_GPS_OPEN_RES_LESS;
	}

	if(vm_gps_sentence_info_p == NULL)
	{	
		gps_poweron_req_struct* poweron_req_p = NULL;
		
		if((vm_gps_sentence_info_p = (vm_gps_sentence_info*)_vm_kernel_malloc(sizeof(vm_gps_sentence_info))) == NULL)
		{
			return VM_GPS_OPEN_MEMORY_LESS;
		}
		
		memset(vm_gps_sentence_info_p,0,sizeof(vm_gps_sentence_info));
		mmi_frm_set_protocol_event_handler(MSG_ID_GPS_POWERON_CNF, (PsIntFuncPtr)vm_gps_poweron_hdlr, MMI_TRUE);
		mmi_frm_set_protocol_event_handler(MSG_ID_GPS_CURRENT_SENTENCE_IND, (PsIntFuncPtr)vm_gps_sentence_data_hdlr, MMI_TRUE);
		mmi_frm_set_protocol_event_handler(MSG_ID_GPS_SET_START_MODE_CNF, (PsIntFuncPtr)vm_gps_startmode_hdlr, MMI_TRUE);
		mmi_frm_set_protocol_event_handler(MSG_ID_GPS_SET_PARAM_CNF, (PsIntFuncPtr)vm_gps_set_param_hdlr, MMI_TRUE);
		mmi_frm_set_protocol_event_handler(MSG_ID_GPS_POWEROFF_CNF, (PsIntFuncPtr)vm_gps_poweroff_hdlr, MMI_TRUE);
		poweron_req_p = construct_local_para(sizeof(gps_poweron_req_struct), TD_RESET);
		poweron_req_p->user_data = vm_pmng_get_current_handle();
		poweron_req_p->tracking_period = period;
		poweron_req_p->gps_type = (gps_type_enum)type;
#ifdef __GPS_LLE_SUPPORT__
/* under construction !*/
#endif

		vm_gps_send_msg(MSG_ID_GPS_POWERON_REQ,MOD_GPSADAPTOR,0, (local_para_struct*)poweron_req_p);
				
		return VM_GPS_OPEN_SUCCESS;
	}
	else
	{
		return VM_GPS_OPEN_ALREADY_OPEN;
	}
	
}

VMINT vm_gps_close(void)
{
	return vm_gps_delete_cur_process_res(vm_pmng_get_current_handle());
}

VMINT vm_gps_set_mode(vm_gps_mode_enum mode)
{
	if(vm_gps_sentence_info_p != NULL)
	{
		gps_start_mode_req_struct* startmode_req_p = NULL;
				
		startmode_req_p = construct_local_para(sizeof(gps_poweron_req_struct), TD_RESET);
		startmode_req_p->user_data = vm_pmng_get_current_handle();
		startmode_req_p->start_mode = (gps_start_mode_enum)mode;
		
		vm_gps_send_msg(MSG_ID_GPS_SET_START_MODE_REQ,MOD_GPSADAPTOR,0, (local_para_struct*)startmode_req_p);

		return VM_GPS_SET_MODE_CLOSE_SUCCESS;
	}
	else
	{
		return VM_GPS_SET_MODE_NOT_OPEN;
	}
}

static vm_gps_agps_server_cfg g_vm_agps_server;

VMINT vm_gps_set_param(vm_gps_set_param_enum param, VMUINT32 value)
{
#ifdef __MMI_MRE_AUTH_SUPPORT__
	if(!srv_mre_appmgr_check_current_defined_authorization(SRV_MRE_APPMGR_APP_AUTH_GPS))
	{
		vm_log_fatal("%s", "[Security check]gps failed");
		return VM_GPS_SET_MODE_NOT_OPEN;
	}
	vm_log_fatal("%s", "[Security check]gps success");
#endif

	if(vm_gps_sentence_info_p != NULL)
	{
		gps_set_param_req_struct* set_api_req_p = NULL;
				
		set_api_req_p = construct_local_para(sizeof(gps_set_param_req_struct), TD_RESET);
		set_api_req_p->user_data = vm_pmng_get_current_handle();
		set_api_req_p->param_type = (gps_set_param_enum)param;
			if( param >= VM_GPS_CMD_SET_LOCATION_REPORT_PERIOD && param <= VM_GPS_CMD_SET_LOCATION_REPORT_PREIOD_WROK_SLEEP)
			{
				set_api_req_p->value = value;
			}
			else if(param == VM_GPS_CMD_SET_ASSIST_DATA_FOR_FAST_FIXED)
			{
				vm_gps_assist_data_cfg* cfg = (vm_gps_assist_data_cfg*)value;
				set_api_req_p->assist_data.u2YEAR = cfg->u2YEAR ;
				set_api_req_p->assist_data.u1MONTH = cfg->u1MONTH ;
				set_api_req_p->assist_data.u1DAY = cfg->u1DAY ;
				set_api_req_p->assist_data.u1HOUR = cfg->u1HOUR ;
				set_api_req_p->assist_data.u1MIN = cfg->u1MIN ;
				set_api_req_p->assist_data.u1SEC = cfg->u1SEC ;
				
				set_api_req_p->assist_data.Latitude = cfg->Latitude ;
				set_api_req_p->assist_data.Longitude = cfg->Longitude ;
				set_api_req_p->assist_data.Altitude = cfg->Altitude ;
			}
			else if(param == VM_GPS_CMD_SET_AGPS_ON_OFF)
			{
			    set_api_req_p->param_type = GPS_CMD_SET_AGPS_ON_OFF;
				set_api_req_p->value = value;
			}
			else if(param == VM_GPS_CMD_SET_SUPL_PROFILE)
			{
				vm_gps_agps_server_cfg* cfg = (vm_gps_agps_server_cfg*)value;
				set_api_req_p->param_type = GPS_CMD_SET_SUPL_PROFILE;
				memset(g_vm_agps_server.addr, 0, VM_GPS_AGPS_MAX_PROFILE_ADDR_LEN*2);
				vm_wstrcpy(g_vm_agps_server.addr, cfg->addr);
				g_vm_agps_server.port = cfg->port;
				set_api_req_p->value = (VMUINT32)&g_vm_agps_server;
			}
			else
			{
				// not support parameter
			}
			
		vm_gps_send_msg(MSG_ID_GPS_SET_PARAM_REQ,MOD_GPSADAPTOR,0, (local_para_struct*)set_api_req_p);

		return VM_GPS_SET_MODE_CLOSE_SUCCESS;
	}
	else
	{
		return VM_GPS_SET_MODE_NOT_OPEN;
	}
}



#endif

