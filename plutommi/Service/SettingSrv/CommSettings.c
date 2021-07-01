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
 * CommSettings.c
 *
 * Project:
 * --------
 *   IOT
 *
 * Description:
 * ------------
 *   Platform common setting API for IOT
 *
 * Author:
 * -------
 * -------
 * 
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/
#if 1
#include "mmi_features.h"
#include "mmi_include.h"
#include "CommSettings.h"
#ifdef __MMI_DATA_LOCK__
#include "DataLockSrvGprot.h"
#endif
#include "DtcntSrvGprot.h"     //For data connection preference SIM
#include "DateTimeSrvGprot.h"
#include "NITZSrvIprot.h"
#include "CommSettingSpof.h"   //For scheduled power on/off setting
/***************************************************************************** 
 * Define
 *****************************************************************************/

/***************************************************************************** 
 * Typedef
 *****************************************************************************/

/***************************************************************************** 
 * Variables
 *****************************************************************************/

/***************************************************************************** 
 * Function
 *****************************************************************************/
#ifdef __MMI_DATA_LOCK__
static int srv_settings_data_lock_command(operationTypesGPRSSrv operation, MMI_BOOL *out);
static int srv_settings_data_roaming_command(operationTypesGPRSRoaming operation, MMI_BOOL *out);
#endif /*__MMI_DATA_LOCK__*/
static int srv_settings_dtcnt_sim_preference_command(operationTypesGPRSConnectionSIM operation, srv_dtcnt_sim_type_enum *in, srv_dtcnt_sim_type_enum *out);
static int srv_settings_date_time_command(operationTypesDatetime operation, applib_time_struct *in_time, applib_time_struct *out_time, srv_dt_set_time_res_funcptr callback, void* usr_data);

#ifdef __MMI_NITZ__
static int srv_settings_nitz_status_command(operationTypesNetworkTime operation, srv_nitz_type_enum *out_type);
#endif 

#ifdef __MMI_TELEPHONY_SUPPORT__
static int srv_settings_gprs_transfer_command(operationTypesGPRSTranferPref operation, srv_gprs_tranfer_cntx_struct *in_cntx);
#endif
static int srv_settings_data_account_command(operationTypesNetworkAccounts operation, void *in_cntx);
static int srv_settings_spof_command(operationTypesSchedulePowerOnOff operation, spof_nvram_struct *in);

#ifdef __GPS_ADAPTOR_SUPPORT__
static int srv_setting_dt_gps_time_sync_command(operationTypesDTGPSSyncTime operation, MMI_BOOL*out);
#endif

mmi_ret srv_setting_common_init(mmi_event_struct *evt)
{
	srv_dt_set_init();
	return MMI_RET_OK;
}
int srv_settings_command(unsigned short type, 
						unsigned short operation, 
						void *in, 
						void *out, 
						srv_setting_result_callback cb,
						void *user_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_command: type= %d, operation= %d.", type, operation);

	/*wrong type*/
    if (type <= SETTING_ENUM_NULL || type >= SETTING_ENUM_NUM)
    {
		return SETTING_RESULT_INVALID;
	}
    
    switch(type)
    {
	    case SETTING_CELLULAR_GPRS_SERVICE:
		#ifdef __MMI_DATA_LOCK__
	        result = srv_settings_data_lock_command((operationTypesGPRSSrv)operation, (MMI_BOOL*)out);
		#else
		    result = SETTING_RESULT_INVALID;
		#endif
	        break;
			
	    case SETTING_CELLULAR_GPRS_ROAMING:
		#ifdef __MMI_DATA_LOCK__
			result = srv_settings_data_roaming_command((operationTypesGPRSRoaming)operation, (MMI_BOOL*)out);
		#else
			result = SETTING_RESULT_INVALID;
		#endif
	        break;
	
		case SETTING_CELLULAR_CONNECTION_SIM:
			result = srv_settings_dtcnt_sim_preference_command((operationTypesGPRSConnectionSIM)operation, (srv_dtcnt_sim_type_enum*)in, (srv_dtcnt_sim_type_enum*)out);
			break;

		case SETTING_NETWORK_ACCOUNTS:
			result = srv_settings_data_account_command((operationTypesNetworkAccounts)operation, in);
			break;
			
		case SETTING_DATETIME:
			result = srv_settings_date_time_command((operationTypesDatetime)operation, (applib_time_struct *)in, (applib_time_struct *)out, (srv_dt_set_time_res_funcptr)cb, user_data);
			break;
		case SETTING_SCHEDULE_POWER_ON_OFF:
			result = srv_settings_spof_command((operationTypesSchedulePowerOnOff)operation, (spof_nvram_struct *)in);
			break;
		case SETTING_NETWORK_TIME_AUTO_UPDATE:
		#ifdef __MMI_NITZ__
			result = srv_settings_nitz_status_command((operationTypesNetworkTime)operation, (srv_nitz_type_enum *)out);
		#else
			result = SETTING_RESULT_INVALID;
		#endif
			break;
		case SETTING_SIM_GPRS_TRANSFER_PREFER:
		#ifdef __MMI_TELEPHONY_SUPPORT__
			result = srv_settings_gprs_transfer_command((operationTypesGPRSTranferPref)operation, (srv_gprs_tranfer_cntx_struct *)in);
		#else
			result = SETTING_RESULT_INVALID;
		#endif
			break;	
		case SETTING_GPS_SYNC_TIME:
		#ifdef __GPS_ADAPTOR_SUPPORT__
			result = srv_setting_dt_gps_time_sync_command((operationTypesDTGPSSyncTime)operation, (MMI_BOOL*)out);
		#else
			result = SETTING_RESULT_INVALID;
		#endif
			break;
	    default:
            break;
    }

	return result;  
}

#ifdef __MMI_DATA_LOCK__
static int srv_settings_data_lock_command(operationTypesGPRSSrv operation, MMI_BOOL *out)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_data_lock_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_GPRS_SERVICE_ON || operation >= OPERATION_GPRS_SERVICE_NUM)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_GPRS_SERVICE_ON:
			srv_data_lock_set_setting(MMI_TRUE);
	        result = SETTING_RESULT_OK;
	        break;
	        
	    case OPERATION_GPRS_SERVICE_OFF:
	        srv_data_lock_set_setting(MMI_FALSE);
	        result = SETTING_RESULT_OK;
	        break;
	     
	    case OPERATION_GPRS_SERVICE_GET_STATUS:
	        *out = srv_data_lock_get_setting();
			result = SETTING_RESULT_OK;
	        break;
	        
	    default:
	        break;
    }

	return result;
}

static int srv_settings_data_roaming_command(operationTypesGPRSRoaming operation, MMI_BOOL *out)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_data_lock_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_GPRS_ROAMING_ON || operation >= OPERATION_GPRS_ROAMING_NUM)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
	{
	    case OPERATION_GPRS_ROAMING_ON:
			srv_data_lock_network_roaming_set_setting(MMI_TRUE);
	        result = SETTING_RESULT_OK;
	        break;
	        
	    case OPERATION_GPRS_ROAMING_OFF:
	        srv_data_lock_network_roaming_set_setting(MMI_FALSE);
	        result = SETTING_RESULT_OK;
	        break;
	     
	    case OPERATION_GPRS_ROAMING_GET_STATUS:
	        *out = srv_data_lock_network_roaming_get_setting();
			result = SETTING_RESULT_OK;
	        break;
	        
	    default:
	        break;
    }
	
	return result;
}
#endif /*__MMI_DATA_LOCK__*/

static int srv_settings_dtcnt_sim_preference_command(operationTypesGPRSConnectionSIM operation, srv_dtcnt_sim_type_enum *in, srv_dtcnt_sim_type_enum *out)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_dtcnt_sim_preference_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_CONNECTION_SIM_SET || operation >= OPERATION_CONNECTION_SIM_NUM)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_CONNECTION_SIM_SET:
		{
			if(srv_dtcnt_set_sim_preference(*in))
			{
				result = SETTING_RESULT_OK;
			}
	        else
	        {
				result = SETTING_RESULT_FAIL;
			}
	        break;
	    }
	        
	    case OPERATION_CONNECTION_SIM_GET_CURRENT_SIM:
		{
			if(srv_dtcnt_get_sim_preference(out))
			{
				result = SETTING_RESULT_OK;
			}
	        else
	        {
				result = SETTING_RESULT_FAIL;
			}
	        break;
	    }
	    default:
	        break;
    }
	
	return result;
}

static int srv_settings_date_time_command(operationTypesDatetime operation, applib_time_struct *in_time, applib_time_struct *out_time, srv_dt_set_time_res_funcptr callback, void* usr_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_date_time_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_DATETIME_SET || operation >= OPERATION_DATETIME_NUM)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_DATETIME_SET:
		result = srv_dt_set_dt(SRV_UTC_DT_SYNC_LEVEL3, in_time, callback, usr_data);
	        break;
	        
	    case OPERATION_DATETIME_GET:
			applib_dt_get_rtc_time(out_time);
			result = SETTING_RESULT_OK;
	        break;
			
	    default:
	        break;
    }
	
	return result;
}

#ifdef __MMI_NITZ__
static int srv_settings_nitz_status_command(operationTypesNetworkTime operation, srv_nitz_type_enum *out_type)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_nitz_status_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_NETWORK_TIME_ON || operation >= OPERATION_NETWORK_TIME_NUM)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_NETWORK_TIME_ON:
			srv_set_apply_nitz_type(SRV_NITZ_ON);
			result = SETTING_RESULT_OK;
	        break;
			
		case OPERATION_NETWORK_TIME_OFF:
			srv_set_apply_nitz_type(SRV_NITZ_OFF);
			result = SETTING_RESULT_OK;
	        break;
	        
		case OPERATION_NETWORK_TIME_GET_STATUS:
			*out_type = srv_get_apply_nitz_type();
			result = SETTING_RESULT_OK;
	        break;
	    default:
	        break;
    }
	
	return result;
}
#endif /*__MMI_NITZ__*/

#ifdef __MMI_TELEPHONY_SUPPORT__
static int srv_settings_gprs_transfer_command(operationTypesGPRSTranferPref operation, srv_gprs_tranfer_cntx_struct *in_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_gprs_transfer_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_SIM_GPRS_TRANSFER_SET_CALL_PREFER || operation >= OPERATION_SIM_GPRS_TRANSFER_PREFER_NUM || in_cntx == NULL)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_SIM_GPRS_TRANSFER_SET_CALL_PREFER:
			srv_netset_set_pch_mode(in_cntx->sim_type, SRV_NETSET_CALL_PREFER, in_cntx->ptr_func, in_cntx->user_data);
			result = SETTING_RESULT_OK;
	        break;
			
		case OPERATION_SIM_GPRS_TRANSFER_SET_DATA_PREFER:
			srv_netset_set_pch_mode(in_cntx->sim_type, SRV_NETSET_DATA_PREFER, in_cntx->ptr_func, in_cntx->user_data);
			result = SETTING_RESULT_OK;
	        break;
	        
		case OPERATION_SIM_GPRS_TRANSFER_GET_STATUS:
			srv_netset_get_pch_mode(in_cntx->sim_type, in_cntx->ptr_func, in_cntx->user_data);
			result = SETTING_RESULT_OK;
	        break;
	    default:
	        break;
    }
	
	return result;
}
#endif /*__MMI_TELEPHONY_SUPPORT__*/

static int srv_settings_data_account_command(operationTypesNetworkAccounts operation, void *in_cntx)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_gprs_transfer_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_NETWORK_ACCOUNTS_ADD || operation >= OPERATION_NETWORK_ACCOUNTS_NUM || in_cntx == NULL)
    {
		return SETTING_RESULT_INVALID;
	}

	switch(operation)
    {
	    case OPERATION_NETWORK_ACCOUNTS_ADD:
		{
			srv_dtcnt_add_prof_cntx_struct *cntx = (srv_dtcnt_add_prof_cntx_struct *)in_cntx;
			cntx->operate_result = srv_dtcnt_store_add_prof(cntx->prof, cntx->acc_prof_id);
			result = SETTING_RESULT_OK;
		    break;
	    }	
	    case OPERATION_NETWORK_ACCOUNTS_EDIT:
		{
			srv_dtcnt_update_prof_cntx_struct *cntx = (srv_dtcnt_update_prof_cntx_struct *)in_cntx;
			cntx->operate_result = srv_dtcnt_store_update_prof(cntx->acc_prof_id, cntx->prof);
			result = SETTING_RESULT_OK;
		    break;
		}
		case OPERATION_NETOWRK_ACCOUNTS_DELETE:
		{
			srv_dtcnt_delete_prof_cntx_struct *cntx = (srv_dtcnt_delete_prof_cntx_struct *)in_cntx;
			cntx->operate_result = srv_dtcnt_store_delete_prof(cntx->acc_prof_id, cntx->force_exec, cntx->user_data, cntx->callback);
			result = SETTING_RESULT_OK;
		    break;
		}

		case OPERATION_NETWORK_ACCOUNTS_GET_ACCOUNT_LIST:
		{
			srv_dtcnt_get_prof_ids_cntx_struct *cntx = (srv_dtcnt_get_prof_ids_cntx_struct *)in_cntx;
			cntx->operate_result = srv_dtcnt_store_qry_ids(cntx->qry);
			result = SETTING_RESULT_OK;
		    break;
		}
		
	    default:
	        break;
    }
	
	return result;
}

static int srv_settings_spof_command(operationTypesSchedulePowerOnOff operation, spof_nvram_struct *in)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_settings_spof_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_SET_SCHEDULE_POWER_ON_STATUS || operation >= OPERATION_SCHEDULE_POWER_ON_OFF_NUM || in == NULL)
    {
		return SETTING_RESULT_INVALID;
	}
 
	switch(operation)
    {
	    case OPERATION_SET_SCHEDULE_POWER_ON_STATUS:
		{
			result = app_set_spof_status(OPERATION_SET_SCHEDULE_POWER_ON_STATUS, in);
		    break;
	    }	
	    case OPERATION_SET_SCHEDULE_POWER_OFF_STATUS:
		{
			result = app_set_spof_status(OPERATION_SET_SCHEDULE_POWER_OFF_STATUS, in);
		    break;
		}
		
	    default:
	        break;
    }
	
	return result;
}

#ifdef __GPS_ADAPTOR_SUPPORT__
static int srv_setting_dt_gps_time_sync_command(operationTypesDTGPSSyncTime operation, MMI_BOOL*out)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int result = SETTING_RESULT_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_PRINT(MOD_MMI_COMMON_APP, MMI_COMMON_TRC_G7_SETTING, "[CommSettings.c]srv_setting_dt_gps_time_sync_command.");
	
	/*wrong operation*/
    if (operation < OPERATION_DATETIME_GPS_TIME_SYNC_ON || operation >= OPERATION_DATETIME_GPS_TIME_SYNC_NUM)
    {
        return SETTING_RESULT_INVALID;
    }

	switch(operation)
    {
	    case OPERATION_DATETIME_GPS_TIME_SYNC_ON:
			srv_dt_set_set_gps_sync_time_mode(MMI_TRUE);
	        result = SETTING_RESULT_OK;
	        break;

	    case OPERATION_DATETIME_GPS_TIME_SYNC_OFF:
			srv_dt_set_set_gps_sync_time_mode(MMI_FALSE);
	        result = SETTING_RESULT_OK;
	        break;
	        
	    case OPERATION_DATETIME_GPS_TIME_SYNC_GET:
	        *out = srv_dt_set_get_gps_time_sync_mode();
	        result = SETTING_RESULT_OK;
	        break;

	    default:
	        break;
    }

	return result;
}
#endif
/*Sample Code: IOT command settings UT*/
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
#ifdef __MMI_DATA_LOCK__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#ifdef __MMI_NITZ__
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif
#endif /*__IOT__*/
