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
 * CommSettings.h
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
#if 1
#ifndef __COMM_SETTINGS_H__
#define __COMM_SETTINGS_H__
/***************************************************************************** 
 * Include
 *****************************************************************************/
#include "MMI_features.h"
#include "NetSetSrvGprot.h"
#include "DtcntSrvIprot.h"

/***************************************************************************** 
 * Define
 *****************************************************************************/
 
/*Setting Type Enum*/
typedef enum
{
    SETTING_ENUM_NULL,                //NULL
	SETTING_CELLULAR_GPRS_SERVICE,    //switch GPRS connection to on or off
	SETTING_CELLULAR_GPRS_ROAMING,    //allow data roaming or not
	SETTING_CELLULAR_CONNECTION_SIM,  //selection one preferred SIM to data connection in multiple SIM case 
	SETTING_NETWORK_ACCOUNTS,         //network accounts
	SETTING_DATETIME,                 //get or set system date and time
	SETTING_SCHEDULE_POWER_ON_OFF,    //schedule power on/off setting
	SETTING_NETWORK_TIME_AUTO_UPDATE, //network time auto update on/off setting
	SETTING_SIM_GPRS_TRANSFER_PREFER, //call perfer or data prefer setting
	SETTING_GPS_SYNC_TIME,            // GPS sync time set
	SETTING_ENUM_NUM
}settingModuleTypes;


/*Operation Type Enum for Each module*/

/*
**Operation type for SETTING_CELLULAR_GPRS_SERVICE
*/
typedef enum
{
	OPERATION_GPRS_SERVICE_ON,         //set GPRS connection on
	OPERATION_GPRS_SERVICE_OFF,        //set GPRS connection off
	OPERATION_GPRS_SERVICE_GET_STATUS, //get current GPRS connection status
	OPERATION_GPRS_SERVICE_NUM
}operationTypesGPRSSrv;

/*
**Operation type for SETTING_CELLULAR_GPRS_ROAMING
*/
typedef enum
{
	OPERATION_GPRS_ROAMING_ON,         //allow data roaming
	OPERATION_GPRS_ROAMING_OFF,        //don't allow data roaming
	OPERATION_GPRS_ROAMING_GET_STATUS, //get current data roaming status
	OPERATION_GPRS_ROAMING_NUM
}operationTypesGPRSRoaming;

/*
**Operation type for SETTING_CELLULAR_CONNECTION_SIM
*/
typedef enum
{
	OPERATION_CONNECTION_SIM_SET,             //set currently connection SIM id, example SIM1 or SIM2
	OPERATION_CONNECTION_SIM_GET_CURRENT_SIM, //get currently connection SIM id
	OPERATION_CONNECTION_SIM_NUM
}operationTypesGPRSConnectionSIM;

/*
**Operation type for SETTING_NETWORK_ACCOUNTS
*/
typedef enum
{
	OPERATION_NETWORK_ACCOUNTS_ADD,             //add network accounts
	OPERATION_NETWORK_ACCOUNTS_EDIT,            //edit network accounts
	OPERATION_NETOWRK_ACCOUNTS_DELETE,          //delete network accounts
	OPERATION_NETWORK_ACCOUNTS_GET_ACCOUNT_LIST,//get exist accounts list
	OPERATION_NETWORK_ACCOUNTS_NUM
}operationTypesNetworkAccounts;

/*
**Operation type for SETTING_DATETIME
*/
typedef enum
{
	OPERATION_DATETIME_SET,    //set system date and time
	OPERATION_DATETIME_GET,    //get system datet and ime
	OPERATION_DATETIME_NUM
}operationTypesDatetime;

/*
**Operation type for SETTING_SCHEDULE_POWER_ON_OFF
*/
typedef enum
{
	OPERATION_SET_SCHEDULE_POWER_ON_STATUS,  //switch schedule power on to on/off
	OPERATION_SET_SCHEDULE_POWER_OFF_STATUS, //switch schedule power off to on/off
	OPERATION_SCHEDULE_POWER_ON_OFF_NUM
}operationTypesSchedulePowerOnOff;

/*
**Operation type for SETTING_NETWORK_TIME_AUTO_UPDATE
*/
typedef enum
{
	OPERATION_NETWORK_TIME_ON,           //set network time auto update on
	OPERATION_NETWORK_TIME_OFF,          //set network time auto update off
	OPERATION_NETWORK_TIME_GET_STATUS,   //get network time auto update status
	OPERATION_NETWORK_TIME_NUM
}operationTypesNetworkTime;

/*
**Operation type for SETTING_SIM_GPRS_TRANSFER_PREFER
*/
typedef enum
{
	OPERATION_SIM_GPRS_TRANSFER_SET_CALL_PREFER, //set GPRS transfer call prefer
	OPERATION_SIM_GPRS_TRANSFER_SET_DATA_PREFER, //set GPRS transfer data prefer
	OPERATION_SIM_GPRS_TRANSFER_GET_STATUS,      //get GPRS transfer status
	OPERATION_SIM_GPRS_TRANSFER_PREFER_NUM
}operationTypesGPRSTranferPref;

/*
**Operation type for OPERATION_DATETIME_GPS_TIME_SYNC
*/
typedef enum
{
	OPERATION_DATETIME_GPS_TIME_SYNC_ON,  //allow GPS to update time
	OPERATION_DATETIME_GPS_TIME_SYNC_OFF, //defuse GPS to update time
	OPERATION_DATETIME_GPS_TIME_SYNC_GET, //get GPS updated time
	
	OPERATION_DATETIME_GPS_TIME_SYNC_NUM
}operationTypesDTGPSSyncTime;

//Error code
/*ok means setting apply done*/
#define SETTING_RESULT_OK 0
/*fail means system error when apply setting*/
#define SETTING_RESULT_FAIL -1
/*would block means current setting is a asynchronous mode, result and data will notify to callback*/
#define SETTING_RESULT_WOULD_BLOCK -2
/*invalid means wrong type and operation combination*/
#define SETTING_RESULT_INVALID -3

typedef struct
{
    mmi_sim_enum sim_type;   //SIM type
	mmi_proc_func ptr_func;  //call back function
	void *user_data;         //user data
} srv_gprs_tranfer_cntx_struct;

typedef struct
{
	srv_dtcnt_store_prof_data_struct *prof;
	U32 *acc_prof_id;
	srv_dtcnt_result_enum operate_result;
}srv_dtcnt_add_prof_cntx_struct;

typedef struct
{
	srv_dtcnt_store_prof_data_struct *prof;
	U32 acc_prof_id;
	srv_dtcnt_result_enum operate_result;
}srv_dtcnt_update_prof_cntx_struct;

typedef struct
{
	U32 acc_prof_id;
    MMI_BOOL force_exec;
    void *user_data;
    srv_dtcnt_store_delete_cb_func_ptr callback;
	srv_dtcnt_result_enum operate_result;
}srv_dtcnt_delete_prof_cntx_struct;

typedef struct
{
	srv_dtcnt_store_prof_qry_struct *qry;
	srv_dtcnt_result_enum operate_result;
}srv_dtcnt_get_prof_ids_cntx_struct;


/*Interface and callback function*/

/*****************************************************************************
 * <GROUP CallBackFunctions>
 *
 * FUNCTION
 *  srv_setting_result_callback
 * DESCRIPTION
 *  setting result callback funtion, app should provide a callback funtion when apply
 *  settings, and this function will be called if current setting is asynchronous mode
 * PARAMETERS
 *  result:             [IN] Operation result
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  void
 *****************************************************************************/
typedef void(* srv_setting_result_callback)(MMI_BOOL result, void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_settings_command
 * DESCRIPTION
 *  General setting command interface, which is use to set/get platfrom related settings
 *  
 * PARAMETERS
 *  type:               [IN] setting type, refer enum settingModuleTypes
 *  user_data:          [IN] setting operation, refer to setting operation enum for each setting type
 *  in:                 [IN] in parameters, if you use set/add/edit/delete related operaitons, 
 *                           please provide in para
 *  out:                [OUT] out data, if you use get/query related operations, please provide out para
 *  srv_setting_result_callback: [IN] setting result callback funtion, will be called by 
 *                               system when current setting is asynchronous mode
 *  user_data:          [IN] User data
 * RETURN VALUES
 *  int                 [out] SETTING_RESULT_OK, SETTING_RESULT_FAIL, SETTING_RESULT_INVALID
 *
 * Sample Code1
 *   //switch on mobile data connection.
 *   VMINT32 result = VM_SETTING_SRV_NO_ERROR;
 *   result = vm_setting_srv_command(VM_SETTING_CELLULAR_GPRS_SERVICE, VM_OPERATION_GPRS_SERVICE_ON, NULL, NULL, NULL, NULL);
 *   if (result == VM_SETTING_RESULT_OK)
 *	 {
 *		VATLog_Status(VAT_SUCCESS, "This case is passed.");
 *	 }
 *	 else if (result == VM_SETTING_RESULT_INVALID)
 *	 {
 *		 VATLog_Status(UNKNOWN, "This case is not support.");
 *	 }
 *	 else
 *	 {
 *		 VATLog_Status(VAT_FAILED, "This case is failed.");
 *	 }
 *
 * Sample Code2
 *   //set system time
 *   VMINT32 result = VM_SETTING_SRV_NO_ERROR;
 *	 vm_time_struct get_time, set_time;
 *	
 *   vm_setting_srv_command(VM_SETTING_DATETIME, VM_OPERATION_DATETIME_GET, NULL, &get_time, NULL, NULL);
 *	 set_time = get_time;
 *	 set_time.nHour = 12;
 *	 set_time.nMin = 14;
 *	 result = vm_setting_srv_command(VM_SETTING_DATETIME, VM_OPERATION_DATETIME_SET, &set_time, NULL, NULL, NULL);
 *   if (result == VM_SETTING_RESULT_OK)
 *	 {
 *		VATLog_Status(VAT_SUCCESS, "This case is passed.");
 *	 }
 *	 else if (result == VM_SETTING_RESULT_INVALID)
 *	 {
 *		 VATLog_Status(UNKNOWN, "This case is not support.");
 *	 }
 *	 else
 *	 {
 *		 VATLog_Status(VAT_FAILED, "This case is failed.");
 *	 }
 *
 *****************************************************************************/
extern int srv_settings_command(unsigned short type, 
						unsigned short operation, 
						void *in, 
						void *out, 
						srv_setting_result_callback cb,
						void *user_data);

#endif /* __COMM_SETTINGS_H__ */
#endif /*__IOT__*/


