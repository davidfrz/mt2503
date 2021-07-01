/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2005]. All rights reserved.
*
*************************************************************************/ 
/*******************************************************************************
 * Filename:
 * ---------
 *  Sample_Wps.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  Sample code for WPS
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 *******************************************************************************/
//#include "APPSDKFrameworkGProt.h"
//#include "APPSDKSystemServiceGProt.h"
//#include "APPSDKNetworkGProt.h"

#if defined(__GPS_SUPPORT__) && !defined(__GPS_EPO_DOWNLOAD__)
#ifdef __GPS_ADAPTOR_SUPPORT__

#include "epodownload.h"
#include "gps_main.h"
#include "gps_adaptor.h"

#if defined(__GPS_SSL_SUPPORT__)
#include "epodownload_ssl.h"
#endif

extern void sqlite3_randomness(int N, void *pBuf);
extern nvram_ef_mnl_setting_data_struct mnl_nvram;


epo_socket_cntx_struct g_epo_socket_cntx;





extern task_indx_type mod_task_g[RPS_TOTAL_STACK_MODULES];

static FS_HANDLE hEPOHandle = -1;    
static FS_HANDLE hEPOHandle_final = -1;    

epodownload_function_struct epodownload_function;
int epodownload_function_ptr= (int)(&epodownload_function);


kal_uint8 access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;

void epodownload_set_onoff(epo_socket_cntx_struct *cntx)
{
	//nvram_external_write_data(NVRAM_EF_AGPS_PROFILE_LID, 1, (kal_uint8*)profile, NVRAM_EF_AGPS_PROFILE_SIZE);
	//save to nvram
	int ret=KAL_TRUE;
	kal_uint8 temp_value;
	ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);	
	temp_value = *(kal_uint8 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-5);

	if(cntx->epodownload_enable == temp_value){
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload]:set value is same with nvram\n");
		return;
	}else{
		*(kal_uint8 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-5)=cntx->epodownload_enable;
	}
	ret=nvram_external_write_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);

	if(g_epo_socket_cntx.app_id == 0){
		epodownload_cntx_init_after_reboot();
	}else{
		epodownload_cntx_init_after_download_success();
	}
	
	if(cntx->epodownload_enable == 0){
		gps_adaptor_stop_timer(GPS_EPO_TIMER);
		access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
		return;
	}
	if(cntx->epodownload_enable == 1){
		gps_adaptor_stop_timer(GPS_EPO_TIMER);
		access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
		epodownload();
		return;
	}
}
void epodownload_get_onoff(epo_socket_cntx_struct *cntx)
{
	//nvram_external_write_data(NVRAM_EM_MINIGPS_UP_SETTING_LID, 1, (kal_uint8*)setting, NVRAM_EM_MINIGPS_UP_SETTING_SIZE);
	//get from nvram
	int ret=KAL_TRUE;
	ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);	
	cntx->epodownload_enable = *(kal_uint8 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-5);
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload]:epo enable = %d\n", cntx->epodownload_enable);
}

void epodownload_cntx_init_after_reboot(void){
	memset(&g_epo_socket_cntx,0,sizeof(g_epo_socket_cntx));
	select_7_30day_epodownload();
	select_whether_using_tempfile();
	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_INVALID;
	g_epo_socket_cntx.socket_id=-1;
  epodownload_get_onoff(&g_epo_socket_cntx);  
#if defined(__GPS_SSL_SUPPORT__)
    epodownload_ssl_init("*.mediatek.com");
#endif

	return;
}

void epodownload_cntx_init_after_download_success(void){
	int file_size=g_epo_socket_cntx.EPOFILE_SIZE;
	S8 app_id=g_epo_socket_cntx.app_id;
	U32 account_id=g_epo_socket_cntx.account_id;
	U8 whether_using_tempfile=g_epo_socket_cntx.epofile_save_option;
	memset(&g_epo_socket_cntx,0,sizeof(g_epo_socket_cntx));
	g_epo_socket_cntx.EPOFILE_SIZE=file_size;
	g_epo_socket_cntx.epofile_save_option=whether_using_tempfile;
	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_INVALID;
	g_epo_socket_cntx.socket_id=-1;
	g_epo_socket_cntx.app_id = app_id;
	g_epo_socket_cntx.account_id = account_id;
	epodownload_get_onoff(&g_epo_socket_cntx);
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%s using tempfile.\n",
						__FUNCTION__,
						g_epo_socket_cntx.epofile_save_option==EPOFILE_USING_TEMPFILE?"":"no");
	return;
}

void epodownload_cntx_init_after_download_failure(void){
	S8 app_id=g_epo_socket_cntx.app_id;
	U32 account_id=g_epo_socket_cntx.account_id;
	int file_size=g_epo_socket_cntx.EPOFILE_SIZE;
	U8 whether_using_tempfile=g_epo_socket_cntx.epofile_save_option;
	U8 retry_count=g_epo_socket_cntx.retry_count;
	memset(&g_epo_socket_cntx,0,sizeof(g_epo_socket_cntx));
	EPODOWNLOAD_SET_FLAG(FLAG_START_DOWNLOAD);
	g_epo_socket_cntx.EPOFILE_SIZE=file_size;
	g_epo_socket_cntx.epofile_save_option=whether_using_tempfile;
	g_epo_socket_cntx.retry_count=retry_count;
	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_INVALID;
	g_epo_socket_cntx.socket_id=-1;
	g_epo_socket_cntx.app_id = app_id;
	g_epo_socket_cntx.account_id = account_id;
	epodownload_get_onoff(&g_epo_socket_cntx);
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%s using tempfile.\n",
						__FUNCTION__,
						g_epo_socket_cntx.epofile_save_option==EPOFILE_USING_TEMPFILE?"":"no");
	return;
}



static epodownload_bool_type EPODOWNLOAD_GET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return ((g_epo_socket_cntx.flag) & flag) != 0 ? epodownload_type_success : epodownload_type_fail;
}

static void EPODOWNLOAD_SET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SET_FLAG,
					g_epo_socket_cntx.flag,
					g_epo_socket_cntx.flag | flag));
    g_epo_socket_cntx.flag |= flag;
}

static void EPODOWNLOAD_RESET_FLAG(U32 flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_RESET_FLAG,
					g_epo_socket_cntx.flag,
					g_epo_socket_cntx.flag & (~flag)));
    (g_epo_socket_cntx.flag) &=  ~flag;
}

static U32 decide_delay(int level,int retry_count){
	U32 delay_time=0;

	
	U32 delay[RETRY_MAX_COUNT]={
		1*60*1000,
		5*60*1000,
		15*60*1000,
		30*60*1000,
		60*60*1000,
	};
	if(retry_count<RETRY_MAX_COUNT){
		delay_time=delay[retry_count];
	}else{
		delay_time=delay[sizeof(delay)/sizeof(U32) - 1];
	}
	
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_DECIDE_DELAY,
					delay_time/1000/60));
	return delay_time;
}

/*

*/
mtk_int32 check_epofile_expire(void){
		struct tm result;
		kal_int32 t_loc;
		kal_int32 t_loc_nvram;
		int ret=KAL_FALSE;
		
		epodownload_function.epodownload_app_gettime(&t_loc);
    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_LOCAL_DATE,
					result.tm_year+1900,
					result.tm_mon,
					result.tm_mday,
					result.tm_hour,
					result.tm_min,
					result.tm_sec));

		if(get_download_time_nvram(&t_loc_nvram) == KAL_FALSE){
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return KAL_FALSE;
		}
		//condition 1 :over 5 days
		//condition 2 :nvram time is newer than local time
		if((t_loc < t_loc_nvram) || 
			(t_loc - t_loc_nvram) > (EPODOWNLOAD_EPOFILE_TIME/1000) ){
			ret=KAL_TRUE;
		}

		return ret;;
	
}


mtk_uint32 get_download_time_nvram(U32 *sec){
		struct tm result;
		kal_uint32 t_loc;
		int ret=KAL_TRUE;

		if(NULL == sec){
			return KAL_FALSE;
		}
		ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
		if(ret==KAL_FALSE){
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_FAILURE
					));
			return ret;
		}else{
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_SUCCESS
					));
		}
		t_loc = *(kal_uint32 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-4);

    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_DATE,
					result.tm_year+1900,
					result.tm_mon,
					result.tm_mday,
					result.tm_hour,
					result.tm_min,
					result.tm_sec));

		*sec = t_loc;
		return ret;;
	
}

mtk_uint32 save_download_time_nvram(void){
		struct tm result;
		kal_uint32 t_loc;
		int ret=KAL_TRUE;
		
		epodownload_function.epodownload_app_gettime(&t_loc);
    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_LOCAL_DATE,
					result.tm_year+1900,
					result.tm_mon,
					result.tm_mday,
					result.tm_hour,
					result.tm_min,
					result.tm_sec));

		ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
		if(ret==KAL_FALSE){
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_FAILURE
					));
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return ret;
		}else{
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_SUCCESS
					));
		}
		*(kal_uint32 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-4)=t_loc;
		ret=nvram_external_write_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
		if(ret==KAL_FALSE){
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_FAILURE
					));
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return ret;
		}else{
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_SUCCESS
					));
		}
		memset(&mnl_nvram,0,sizeof(mnl_nvram));
		ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
		if(ret==KAL_FALSE){
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_FAILURE
					));
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return ret;
		}else{
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_SUCCESS
					));
			if(*(kal_uint32 *)(mnl_nvram.nvram_ef_mnl_setting_data + sizeof(mnl_nvram.nvram_ef_mnl_setting_data)-4) == t_loc){
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_SAVE_SUCCESS
					));
			}else{
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_SAVE_FAILURE
					));
				EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
				ret=KAL_FALSE;
			}
		}
		return ret;

}



static void epodownload_submit_error(EPODOWNLOAD_ERR_CODE errcode){
	g_epo_socket_cntx.err_code=errcode;

	epodownload_error_handler(NULL);

	return;
}



void epodownload_timer_hdlr(void *param){
	U32 delay=0;
	if(EPODOWNLOAD_GET_FLAG(FLAG_EXCUTE_ERR_HANDLER) == epodownload_type_success){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_ERR_HANDLER_RUNNING));
		return;
	}
	gps_adaptor_stop_timer(GPS_EPO_TIMER);
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_TIMEOUT_TYPE,
				g_epo_socket_cntx.timer_handler_type));
	switch(g_epo_socket_cntx.timer_handler_type){
		case TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD:
			epodownload_submit_error(ERR_NOT_FINISHED_WITHIN_TIME);	
			break;
		case TIMEOUT_TYPE_EPOFILE_INVALID:
		case TIMEOUT_TYPE_NEXT_DOWNLOAD:
			epodownload();
			break;
		case TIMEOUT_TYPE_REBOOT:
			epodownload();
			break;
		case TIMEOUT_TYPE_SAVELOCALTIME:
			if(save_download_time_nvram() == KAL_FALSE){
				g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_SAVELOCALTIME;
				gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_SAVE_LOCALNVRAM, epodownload_timer_hdlr, NULL);
				return;
			}
			epodownload_cntx_init_after_download_success();
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_EPOFILE_INVALID;
			gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_TIME, epodownload_timer_hdlr, NULL);
			break;
		case TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_SUCCESS:
			if(mtk_gps_sys_epodownload_delete() < 0){
				g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_SUCCESS;
				gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_ACCESS_ERR, epodownload_timer_hdlr, NULL);
				return;
			}
			if(save_download_time_nvram() == KAL_FALSE){
				g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_SAVELOCALTIME;
				gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_SAVE_LOCALNVRAM, epodownload_timer_hdlr, NULL);
				return;
			}
			epodownload_cntx_init_after_download_success();
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_EPOFILE_INVALID;
			gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_TIME, epodownload_timer_hdlr, NULL);
			break;
		case TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_FAILURE:
			if(mtk_gps_sys_epodownload_delete() < 0){
				g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_FAILURE;
				gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_ACCESS_ERR, epodownload_timer_hdlr, NULL);
				return;
			}
			delay=decide_delay(0,g_epo_socket_cntx.retry_count);
			g_epo_socket_cntx.retry_count++;
	
			epodownload_cntx_init_after_download_failure();
	
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NEXT_DOWNLOAD;
			gps_adaptor_start_timer(GPS_EPO_TIMER, delay, epodownload_timer_hdlr, NULL);
			break;
		case TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM:
			epodownload_bt_connect_ind_hdlr(NULL);
			break;
		case TIMEOUT_TYPE_DOWNLOAD_BY_BT:
			access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
			epodownload();
			break;
		case TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM_WHEN_GPRS_DOWNLOAD:
			epodownload();
			break;
		default:
			break;
	}
}





static void epodownload_error_handler(void *param){
	U32 delay=0;
	U8 delay_random=0;

	EPODOWNLOAD_SET_FLAG(FLAG_EXCUTE_ERR_HANDLER);
	gps_adaptor_stop_timer(GPS_EPO_TIMER);
	
	if(-1 != g_epo_socket_cntx.socket_id){
	#ifdef __TCPIP__
		soc_close(g_epo_socket_cntx.socket_id); 
	#endif
		g_epo_socket_cntx.socket_id=-1;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_RELEASED, g_epo_socket_cntx.socket_id));
	}else{
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
	}

#if defined(__GPS_SSL_SUPPORT__)
    epodownload_ssl_deinit_cntx();
#endif
    
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_ERR_HANDLER_STATUS,
				g_epo_socket_cntx.retry_count,
				g_epo_socket_cntx.err_code,
				g_epo_socket_cntx.flag));

	

	//download success
	if(EPODOWNLOAD_GET_FLAG(FLAG_SUCCESS) == epodownload_type_success){
		if(MTK_GPS_ERROR ==mtk_gps_sys_epodownload_copy()){
			EPODOWNLOAD_RESET_FLAG(FLAG_SUCCESS);
			epodownload_submit_error(ERR_FILE_COPY_FAIL);	
			return;
		}
		mtk_gps_sys_epodownload_close();
		if(mtk_gps_sys_epodownload_delete() < 0){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_SUCCESS;
			gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_ACCESS_ERR, epodownload_timer_hdlr, NULL);
			return;
		}
		if(save_download_time_nvram() == KAL_FALSE){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_SAVELOCALTIME;
			gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_SAVE_LOCALNVRAM, epodownload_timer_hdlr, NULL);
			return;
		}
		
		epodownload_cntx_init_after_download_success();
		g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_EPOFILE_INVALID;
		gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_TIME, epodownload_timer_hdlr, NULL);
		access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
		return;
	}


	//download failure
	switch(g_epo_socket_cntx.err_code){
		case ERR_NETWORK_UNAVALIABLE:
		case ERR_RETRY_COUNT_OVERFLOW:
		case ERR_REGISTER_APPID:
		case ERR_SOCKET_CREATE:
		case ERR_SOCKET_SET_PARAM_NBIO:
		case ERR_SOCKET_SET_PARAM_ASYNC:
		case ERR_FILE_OPEN_FAIL:
		case ERR_FILE_CLOSE_FAIL:
		case ERR_FILE_READ_FAIL:
		case ERR_FILE_WRITE_FAIL:
		case ERR_DNS:
		case ERR_SOCKET_CONNECT:
		case ERR_SEND_DOWNLOAD_REQ:
		case ERR_DATA_RECEIVE:
		case ERR_FILE_CHECKSUM_FAIL:	
		case ERR_SOCKET_READ_WRITE_CONNECT_CLOSE:
		case ERR_ETAG_NOT_FOUND:
		case ERR_NOT_FINISHED_WITHIN_TIME:
			break;	
	
		default:
			break;
	}

	mtk_gps_sys_epodownload_close();
	if(mtk_gps_sys_epodownload_delete() < 0){
		g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_FAILURE;
		gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_ACCESS_ERR, epodownload_timer_hdlr, NULL);
		return;
	}

	//first decide when next download happen.
	delay=decide_delay(0,g_epo_socket_cntx.retry_count);
	g_epo_socket_cntx.retry_count++;
	
	epodownload_cntx_init_after_download_failure();
	
	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NEXT_DOWNLOAD;
	gps_adaptor_start_timer(GPS_EPO_TIMER, delay, epodownload_timer_hdlr, NULL);
	access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
	return ;
}



static int hash_string(unsigned char *hash,int length){
	int i=0;
	unsigned char temp;
	unsigned char buf[33]={0};
	memset(buf,0,sizeof(buf));
	for(i=0;i<length;i++){
		sprintf(buf+i*2,"%02x",hash[i]);	
	}

	if(strcmp(buf,g_epo_socket_cntx.check_sum) == 0){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_CHECKSUM_SUCCESS,
				buf));
		return KAL_TRUE;
	}else{
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_CHECKSUM_FAILURE,
				buf));
		return KAL_FALSE;
	}
}

static kal_bool my_applib_md5_file_update(applib_md5_ctx *mdContext, const kal_wchar *filename)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 buffer[1024];
    kal_uint32 dataLen = 0;
    kal_uint32 fileSize = 0;
    kal_int32 fileHandle=hEPOHandle;
    kal_uint32 rd_no = 0;

    
    if (FS_GetFileSize(fileHandle, &fileSize) < 0)
    {
        FS_Close(fileHandle);
        return KAL_FALSE;
    }

    while (fileSize)
    {
        if (fileSize > 1024)
        {
            dataLen = 1024;
        }
        else
        {
            dataLen = fileSize;
        }

        FS_Read(fileHandle, buffer, dataLen, &rd_no);
        if (rd_no != dataLen)
        {
            ASSERT(0);
        }
        epodownload_function.epodownload_applib_md5_update(mdContext, buffer, dataLen);
        fileSize -= dataLen;
    }
    return KAL_TRUE;
}

mtk_int32 check_when_epofile_invalid(void){
		struct tm result;
		kal_uint32 t_loc=0;
		kal_uint32 t_loc_nvram=0;
		int ret=0;
		
		epodownload_function.epodownload_app_gettime(&t_loc);
    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_LOCAL_DATE,
				result.tm_year+1900,
				result.tm_mon,
				result.tm_mday,
				result.tm_hour,
				result.tm_min,
				result.tm_sec));
		

		if(get_download_time_nvram(&t_loc_nvram) == KAL_FALSE){
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return 0;
		}

		if(t_loc < t_loc_nvram)
			return 0;

		return (((g_epo_socket_cntx.EPOFILE_SIZE==EPOFILE_SIZE_7?EPODOWNLOAD_EPOFILE_7_TIME:EPODOWNLOAD_EPOFILE_30_TIME)/1000) - (t_loc - t_loc_nvram)) * 1000;
	
}


mtk_int32 check_when_download(void){
		struct tm result;
		kal_uint32 t_loc=0;
		kal_uint32 t_loc_nvram=0;
		int ret=0;
		
		epodownload_function.epodownload_app_gettime(&t_loc);
    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_LOCAL_DATE,
				result.tm_year+1900,
				result.tm_mon,
				result.tm_mday,
				result.tm_hour,
				result.tm_min,
				result.tm_sec));
		

		if(get_download_time_nvram(&t_loc_nvram) == KAL_FALSE){
			EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			return 0;
		}

		if(t_loc < t_loc_nvram)
			return 0;

		return ((EPODOWNLOAD_EPOFILE_TIME/1000) - (t_loc - t_loc_nvram)) * 1000;
	
}



mtk_int32
mtk_gps_sys_epodownload_get_drvletter (void)
{
	int iDrvLetter=0;
	iDrvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, 0);
    if (iDrvLetter < FS_NO_ERROR)
    {
        /*no card we get normal driver*/
        iDrvLetter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 0);
        if (iDrvLetter >= FS_NO_ERROR)
        {
        	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD__GET_REMOVABLE_DRIVER,
				iDrvLetter));
		}
    }else{
    	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD__GET_NORMAL_DRIVER,
				iDrvLetter));
	}
	
	return iDrvLetter;
}

mtk_int32
mtk_gps_sys_epodownload_delete_file (U8 iDrvLetter,U8 *file_name)
{
	int ret;
	WCHAR wszFilename[32];
	
	kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_name);
	ret=FS_Delete(wszFilename);
    if (ret == 0)
    {
    	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:delete %d:\\%s success.\n",
			__FUNCTION__,
			iDrvLetter,
			file_name);
    }else if(ret == FS_FILE_NOT_FOUND){
    	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s has already not exist.\n",
			__FUNCTION__,
			iDrvLetter,
			file_name);
	}else{
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:delete %d:\\%s failure.\n",
			__FUNCTION__,
			iDrvLetter,
			file_name);
	}
	if(ret == 0 || ret == FS_FILE_NOT_FOUND)
		return MTK_GPS_SUCCESS;
    return  MTK_GPS_ERROR;
}



static mtk_int32
check_file_exist (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	U8 *file_name=EPO_FILE_NAME;
	mtk_int32 need_download=KAL_TRUE;
	kal_int32 fileHandle;

	iDrvLetter = mtk_gps_sys_epodownload_get_drvletter();

    if (iDrvLetter > 0)
    {
    	kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_name);
		fileHandle = FS_Open(wszFilename, FS_READ_WRITE);
    	
        if (fileHandle == FS_FILE_NOT_FOUND) {
        	need_download=KAL_FALSE;
			kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s not exist.\n",
				__FUNCTION__,
				iDrvLetter,
				file_name);
		}
		
    }
	FS_Close(fileHandle);
	

    return  need_download;
}


static mtk_int32
get_file_size (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	U8 *file_name=EPO_FILE_NAME;
	mtk_int32 need_download=MTK_GPS_SUCCESS;
	kal_int32 fileHandle;
	kal_int32 filesize=0;

	iDrvLetter = mtk_gps_sys_epodownload_get_drvletter();

    if (iDrvLetter > 0)
    {
    	kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_name);
		fileHandle = FS_Open(wszFilename, FS_READ_WRITE);

		if (FS_GetFileSize(fileHandle, &filesize) < 0)
    	{
        	FS_Close(fileHandle);
        	return filesize;
    	}
    }
	FS_Close(fileHandle);
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_EPOFILE_SIZE,
				filesize/1024));

    return  filesize;
}



static mtk_int32
check_whether_download (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	U8 *file_name=EPO_FILE_NAME;
	mtk_int32 need_download=MTK_GPS_ERROR;
	kal_int32 fileHandle;
	kal_int32 filesize=0;

	iDrvLetter = mtk_gps_sys_epodownload_get_drvletter();
    if (iDrvLetter > 0)
    {
    	kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_name);
		fileHandle = FS_Open(wszFilename, FS_READ_WRITE);
    	
        if (fileHandle == FS_FILE_NOT_FOUND) {
        	need_download=MTK_GPS_SUCCESS;
			kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s not exist.\n",
				__FUNCTION__,
				iDrvLetter,
				file_name);
		}else if (fileHandle >= 0){
			kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s exist.\n",
				__FUNCTION__,
				iDrvLetter,
				file_name);
			//check whether EPO.DAT size is right
			if (FS_GetFileSize(fileHandle, &filesize) < 0)
	    	{
	        	FS_Close(fileHandle);
				need_download=MTK_GPS_ERROR;
				EPODOWNLOAD_SET_FLAG(FLAG_FILE_OCCURED_ERR);
				kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s exist, but don't get size.\n",
					__FUNCTION__,
					iDrvLetter,
					file_name);
	        	return need_download;
	    	}else{
				if(filesize != g_epo_socket_cntx.EPOFILE_SIZE){
					kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s exist, but size is wrong.\n",
						__FUNCTION__,
						iDrvLetter,
						file_name);
					FS_Close(fileHandle);
					need_download=MTK_GPS_SUCCESS;	
					if(mtk_gps_sys_epodownload_delete_file(iDrvLetter,file_name) == MTK_GPS_ERROR){
						need_download=MTK_GPS_ERROR;
						EPODOWNLOAD_SET_FLAG(FLAG_FILE_OCCURED_ERR);
						kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s exist, delete fail.\n",
								__FUNCTION__,
								iDrvLetter,
								file_name);
					}
					return need_download;
				}
			}
			//check whether epofile expire
			if(check_epofile_expire() == KAL_TRUE){
				need_download=MTK_GPS_SUCCESS;	
			}			
        }else{
			need_download=MTK_GPS_ERROR;
			EPODOWNLOAD_SET_FLAG(FLAG_FILE_OCCURED_ERR);
			kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%d:\\%s exist, but other is using.\n",
				__FUNCTION__,
				iDrvLetter,
				file_name);
		}
		
    }
	FS_Close(fileHandle);
	

    return  need_download;
}


static mtk_int32
mtk_gps_sys_epodownload_get_freespace (void)
{
    FS_HANDLE fs_ret = FS_NO_ERROR;
    U8 drv_asc[10] = {0};
    U16 drv_ucs[10] = {0};
    FS_DiskInfo disk_info;
    S32 free_space = 0;

	kal_wsprintf(drv_ucs, "%c:\\", mtk_gps_sys_epodownload_get_drvletter());
    fs_ret = FS_GetDiskInfo((kal_uint16*) drv_ucs, &disk_info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
    if (fs_ret >= FS_NO_ERROR)
    {
        free_space = disk_info.FreeClusters * disk_info.SectorsPerCluster * disk_info.BytesPerSector;
    }
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_DISK_FREE_SPACE,
				free_space/1024));
	return free_space;
}


static mtk_int32
mtk_gps_sys_epodownload_check (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	int ret;
	applib_md5_ctx mdContext;
	unsigned char hash[16]={0};
	int i;
	U32  fileHandle;
	U32 file_size=0;

	FS_Seek(hEPOHandle,0,SEEK_SET);
	if (FS_GetFileSize(hEPOHandle, &file_size) < 0)
    {
        FS_Close(hEPOHandle);
        return MTK_GPS_ERROR;
   	}
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_EPOFILE_SIZE,
				file_size/1024));
		
	if(file_size == g_epo_socket_cntx.EPOFILE_SIZE){
		epodownload_function.epodownload_applib_md5_init(&mdContext);
		my_applib_md5_file_update(&mdContext, wszFilename);
		epodownload_function.epodownload_applib_md5_final(hash, &mdContext);

		if(hash_string(hash,sizeof(hash)) == KAL_TRUE){
			return  MTK_GPS_SUCCESS;
		}else{
			return  MTK_GPS_ERROR;
		}
	}


    return  MTK_GPS_ERROR;
}





mtk_int32
mtk_gps_sys_epodownload_delete (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	int ret=0;
	int ret1=0;
	U8 *file_name;
	U8 *file_final_name;

	if(g_epo_socket_cntx.epofile_save_option != EPOFILE_USING_TEMPFILE){
		file_name=EPO_FILE_NAME;
		file_final_name=EPO_FILE_NAME;
	}else{
		file_name=EPO_TEMPFILE_NAME;
		file_final_name=EPO_FILE_NAME;
	}
	

	iDrvLetter = mtk_gps_sys_epodownload_get_drvletter();

    if (iDrvLetter > 0)
    {
		if(g_epo_socket_cntx.epofile_save_option == EPOFILE_USING_TEMPFILE){
			//when using temp file, first delete temp file
			ret=mtk_gps_sys_epodownload_delete_file(iDrvLetter,file_name);

			if((EPODOWNLOAD_GET_FLAG(FLAG_SUCCESS) == epodownload_type_fail && check_when_epofile_invalid() <= 0) || 
				get_file_size() == 0){
				if(EPODOWNLOAD_GET_FLAG(FLAG_ACCESS_NVRAM_ERR) == epodownload_type_success){
					return -1;
				}
				ret1=mtk_gps_sys_epodownload_delete_file(iDrvLetter,file_final_name);
    			return  ret1;
			}else{
				//needn't delete original file
				return ret;
			}
		}

		if(EPODOWNLOAD_GET_FLAG(FLAG_SUCCESS) == epodownload_type_fail){
				if(ERR_DATA_RECEIVE <= g_epo_socket_cntx.err_code){
					ret1=mtk_gps_sys_epodownload_delete_file(iDrvLetter,file_final_name);
				}
		}
    }

    return  ret1;
}


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_epo_open
 * DESCRIPTION
 *  Open EPO file
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
static mtk_int32
mtk_gps_sys_epodownload_open (void)
{
    U8 iDrvLetter;
    WCHAR wszFilename[32];
	U8 *file_name;
	U8 *file_final_name;

	if(g_epo_socket_cntx.epofile_save_option != EPOFILE_USING_TEMPFILE){
		file_name=EPO_FILE_NAME;
		file_final_name=EPO_FILE_NAME;
	}else{
		file_name=EPO_TEMPFILE_NAME;
		file_final_name=EPO_FILE_NAME;
	}

	iDrvLetter = mtk_gps_sys_epodownload_get_drvletter();

    if (iDrvLetter > 0)
    {
    	kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_name);
		hEPOHandle = FS_Open(wszFilename, FS_READ_WRITE | FS_CREATE);
    	if(g_epo_socket_cntx.epofile_save_option != EPOFILE_USING_TEMPFILE){
			hEPOHandle_final=hEPOHandle;
		}else{
			kal_wsprintf(wszFilename, "%c:\\%s", iDrvLetter,file_final_name);
			hEPOHandle_final= FS_Open(wszFilename, FS_READ_WRITE | FS_CREATE);
		}
        
        if (hEPOHandle >= 0)
        {
        	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:create %d:\\%s success.\n",
				__FUNCTION__,
				iDrvLetter,
				file_name);
			if (hEPOHandle_final >= 0)
        	{
				kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:create %d:\\%s success.\n",
					__FUNCTION__,
					iDrvLetter,
					file_final_name);
        	}else{
        		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:create %d:\\%s failure.\n",
					__FUNCTION__,
					iDrvLetter,
					file_final_name);
			}
        }else{
        	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:create %d:\\%s failure.\n",
					__FUNCTION__,
					iDrvLetter,
					file_name);
		}
		
    }

	if(hEPOHandle >= 0 && hEPOHandle_final >= 0)
		return MTK_GPS_SUCCESS;
    return  MTK_GPS_ERROR;
}

/*****************************************************************************
 * FUNCTION
 *  mtk_sys_epo_close
 * DESCRIPTION
 *  Close EPO file
 * RETURNS
 *  void
 *****************************************************************************/
static void
mtk_gps_sys_epodownload_close (void)
{
    if (hEPOHandle >= 0)
    {
    	FS_Close(hEPOHandle);
		FS_Close(hEPOHandle_final);
		hEPOHandle = -1;
		hEPOHandle_final=-1;	
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_CLOSE_EPOFILE));
    }
}

/*****************************************************************************
 * FUNCTION
 *  mtk_sys_epo_read
 * DESCRIPTION
 *  Read EPO file
 *  (blocking read until reaching 'length' or EOF)
 * PARAMETERS
 *  buffer      [OUT]
 *  offset      [IN]
 *  length      [IN]
 *  p_nRead     [OUT]
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
static mtk_int32
mtk_gps_sys_epodownload_read (void* buffer, mtk_uint32 offset, mtk_uint32 length,
                      mtk_uint32* p_nRead)
{
    UINT nRead;
    int  result;

    if (hEPOHandle < 0)
    {
        return MTK_GPS_ERROR;
    }

    // Since MNL now read the EPO file sequentially,
    // we can ignore the offset parameter from MNL's request
    // otherwise we may need add FS_Seek() here
    result = FS_Read(hEPOHandle, buffer, length, &nRead);
    if (p_nRead)
    {
        *p_nRead = nRead;
    }
    return  result ? MTK_GPS_ERROR : MTK_GPS_SUCCESS;
}

/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_storage_write
 * DESCRIPTION
 *
 * PARAMETERS
 *  buffer      [IN]
 *  offset      [IN]
 *  length      [IN]
 *  p_nWritten  [OUT]
 * RETURNS
 *  success(0)
 *****************************************************************************/
static mtk_int32
mtk_gps_sys_epodownload_write (const void* buffer, mtk_uint32 offset, mtk_uint32 length,
                       mtk_uint32* p_nWritten)
{
  UINT nWrite;
  int  result;

  if (hEPOHandle < 0)
  {
    return MTK_GPS_ERROR;
  }

  result = FS_Write(hEPOHandle, (void*) buffer, length, &nWrite);
  if (p_nWritten)
  {
    *p_nWritten = nWrite;
  }
  GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_FILE_WRITE_STATUS,
				length,
				*p_nWritten,
				result));
  
  return  result ? MTK_GPS_ERROR : MTK_GPS_SUCCESS;
}


static mtk_int32
mtk_gps_sys_epodownload_copy (void)
{
  	UINT nWrite;
  	int  result;
	U32 fileSize=g_epo_socket_cntx.EPOFILE_SIZE;
	U32 dataLen;
	U8 buffer[1024];
	U32 rd_no = 0;
  
  	if (hEPOHandle < 0 || hEPOHandle_final< 0 || hEPOHandle==hEPOHandle_final)
  	{
    	return MTK_GPS_SUCCESS;
  	}
  	FS_Seek(hEPOHandle,0,SEEK_SET);
  	FS_Seek(hEPOHandle_final,0,SEEK_SET);
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_EPOFILE_SIZE,
				fileSize/1024));

	while (fileSize)
    {
        if (fileSize > 1024)
        {
            dataLen = 1024;
        }
        else
        {
            dataLen = fileSize;
        }

        FS_Read(hEPOHandle, buffer, dataLen, &rd_no);
        if (rd_no != dataLen)
        {
        	return MTK_GPS_ERROR;
            ASSERT(0);
        }

		result = FS_Write(hEPOHandle_final, (void*) buffer, dataLen, &nWrite);
  		if (nWrite != dataLen)
  		{
  			return MTK_GPS_ERROR;
    		ASSERT(0);
  		}

		
        fileSize -= dataLen;
    }
  
  return  result ? MTK_GPS_ERROR : MTK_GPS_SUCCESS;
}





/******************************************Global variable start******************/

#define EPODOWNLOAD_FILE_RESULT_SUCCESS 0
#define EPODOWNLOAD_FILE_RESULT_FAILURE 1
kal_int32 epodownload_file_get_drvletter (void){
	kal_int32 iDrvLetter=0;
	iDrvLetter = FS_GetDrive(FS_DRIVE_V_NORMAL, 1, 0);
    if (iDrvLetter < FS_NO_ERROR){
        iDrvLetter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 0);
        if (iDrvLetter >= FS_NO_ERROR){
        	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD__GET_REMOVABLE_DRIVER,
				iDrvLetter));
		}
    }else{
    	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD__GET_NORMAL_DRIVER,
				iDrvLetter));
	}
	return iDrvLetter;
}
kal_int8* epodownload_file_root_path(void){
	kal_int32 driver=-1;
	static kal_int8 path[2]={0,0};
	driver=epodownload_file_get_drvletter();
	sprintf(path,"%c",driver);
	return path;
}
FS_HANDLE epodownload_file_open(kal_uint8 *path,kal_uint8 *filename,kal_uint32 openflag){
	WCHAR wszFilename[32];
	kal_wsprintf(wszFilename, "%s:\\%s", path,filename);
	return FS_Open(wszFilename, openflag);
}
kal_int32 epodownload_file_close(FS_HANDLE hd){
	return FS_Close(hd);
}
kal_int32 epodownload_file_read (
	FS_HANDLE hd,void* buffer, kal_uint32 length,kal_uint32* p_nRead){
    UINT nRead;
    int  result;
    result = FS_Read(hd, buffer, length, &nRead);
    if (p_nRead)
    {
        *p_nRead = nRead;
    }
    return  result ? EPODOWNLOAD_FILE_RESULT_FAILURE : EPODOWNLOAD_FILE_RESULT_SUCCESS;
}
kal_int32 epodownload_file_write (
	FS_HANDLE hd, void* buffer, kal_uint32 length, kal_uint32* p_nWritten){
  UINT nWrite;
  int  result;
  result = FS_Write(hd, buffer, length, &nWrite);
  if (p_nWritten)
  {
    *p_nWritten = nWrite;
  }
  return  result ? EPODOWNLOAD_FILE_RESULT_FAILURE : EPODOWNLOAD_FILE_RESULT_SUCCESS;
}
kal_int32 epodownload_file_size (FS_HANDLE hd)
{
	kal_int32 filesize=0;
	FS_GetFileSize(hd, &filesize);
    return  filesize;
}
kal_int32 epodownload_file_delete (kal_uint8 *path,kal_uint8 *filename)
{
	int ret;
	WCHAR wszFilename[32];
	kal_wsprintf(wszFilename, "%s:\\%s", path,filename);
	ret=FS_Delete(wszFilename);
	return  ret ? EPODOWNLOAD_FILE_RESULT_FAILURE : EPODOWNLOAD_FILE_RESULT_SUCCESS;
}
kal_bool epodownload_file_exist(kal_uint8 *path,kal_uint8 *filename,kal_uint32 openflag){
	WCHAR wszFilename[32];
	FS_HANDLE hd;
	kal_wsprintf(wszFilename, "%s:\\%s", path,filename);
	hd=FS_Open(wszFilename, openflag);
	if(hd>=0){
		FS_Close(hd);
	}
	return hd>=0? KAL_TRUE:KAL_FALSE;
}
kal_bool epodownload_file_size_is_right(kal_int32 file_real_size,kal_int32 file_ritht_size){
	return file_real_size==file_ritht_size? KAL_TRUE:KAL_FALSE;
}
kal_bool epodownload_file_valid(kal_uint32 how_long){
		struct tm result;
		kal_int32 t_loc;
		kal_int32 t_loc_nvram;
		int ret=KAL_TRUE;
		epodownload_function.epodownload_app_gettime(&t_loc);
    	gmtime_r((const time_t *)(&t_loc),&result);
		result.tm_mon++;
		get_download_time_nvram(&t_loc_nvram);
		if((t_loc < t_loc_nvram) || 
			(t_loc - t_loc_nvram) > (how_long/1000) ){
			ret=KAL_FALSE;
		}
		return ret;;
}
kal_bool epodownload_file_need_download(kal_uint32 how_long){
		kal_int32 driver=FS_NO_ERROR;
		kal_int8 *path=NULL;
		kal_bool file_exist=KAL_FALSE;
		kal_bool file_valid=KAL_FALSE;
		kal_bool ret=KAL_FALSE;
		driver=epodownload_file_get_drvletter(); 
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:driver: %d.\n",
							__FUNCTION__,
							driver);
		if(driver==FS_NO_ERROR){
			ret=KAL_FALSE;
			return ret;
		}
		path=epodownload_file_root_path();
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:path: %s.\n",
							__FUNCTION__,
							path);
		file_exist=epodownload_file_exist(path,EPO_FILE_NAME,FS_READ_ONLY);		
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:file_exist: %d.\n",
							__FUNCTION__,
							file_exist);
		if(file_exist==KAL_FALSE){
			ret=KAL_TRUE;
			return ret;
		}
		file_valid=epodownload_file_valid(how_long);
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:file_valid: %d.\n",
							__FUNCTION__,
							file_valid);
		if(file_valid==KAL_FALSE){
			ret=KAL_TRUE;
			return ret;
		}
		return ret;;
}
kal_bool epodownload_file_download_success(kal_int8 *filename){
		kal_int32 driver=FS_NO_ERROR;
		kal_int8 *path=NULL;
		kal_bool file_exist=KAL_FALSE;
		kal_bool file_valid=KAL_FALSE;
		kal_bool ret=KAL_FALSE;
		if(mtk_gps_sys_epodownload_get_freespace()<g_epo_socket_cntx.EPOFILE_SIZE){
			return KAL_FALSE;
		}
		path=epodownload_file_root_path();
		hEPOHandle=epodownload_file_open(path,filename,FS_READ_ONLY);
		if(hEPOHandle>=0 && mtk_gps_sys_epodownload_check()==MTK_GPS_SUCCESS){
			ret=KAL_TRUE;
		}
		epodownload_file_close(hEPOHandle);
		return ret;;
}





static mtk_int32  epofile_property(char *buf,int length){
	int i;
	char* current_ptr=buf;
	char *ptr_csm=NULL;
	char *ptr_length=NULL;
	mtk_int32 ret=KAL_TRUE;
	for(i=0;i<length;i++){
		if(buf[i]==0x0d && buf[i+1]==0x0a){
			buf[i]=0;
			kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%s\n",
				__FUNCTION__,
				current_ptr);

			if(NULL == ptr_length){
				ptr_length=strstr(current_ptr,"Content-Length: ");
				if(ptr_length){
					ptr_length=ptr_length+strlen("Content-Length: ");
					kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:epofile sieze :%d\n",
						__FUNCTION__,
						atoi(ptr_length));
					if(g_epo_socket_cntx.EPOFILE_SIZE != atoi(ptr_length)){
						epodownload_submit_error(ERR_LENGTH_NOT_MATCH);
						ret=KAL_FALSE;
						return ret;
						break;
					}
				}
			}
			

			
			ptr_csm=strstr(current_ptr,"ETag");
			if(ptr_csm){
				ptr_csm=ptr_csm+4;
				if( ptr_csm[2] != '"'){
					epodownload_submit_error(ERR_ETAG_NOT_FOUND);
					return ret;
				}
				//add err code
				EPODOWNLOAD_SET_FLAG(FLAG_FIND_ETAG);
				ptr_csm=ptr_csm+3;
				strncpy(g_epo_socket_cntx.check_sum,ptr_csm,sizeof(g_epo_socket_cntx.check_sum)-1);
				g_epo_socket_cntx.check_sum[sizeof(g_epo_socket_cntx.check_sum)-1]=0;
				kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:find check sum :%s\n",
						__FUNCTION__,
						g_epo_socket_cntx.check_sum);
				return ret;
				break;
			}
			ptr_csm=NULL;
			current_ptr=buf+i+2;
		}
	}
    
	if(NULL == ptr_csm){
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:can't find check sum\n",
						__FUNCTION__);
		epodownload_submit_error(ERR_ETAG_NOT_FOUND);
		ret=KAL_FALSE;
	}
	return ret;
}





static epodownload_bool_type check_download_finish(void){
	if(g_epo_socket_cntx.sum == g_epo_socket_cntx.EPOFILE_SIZE){
			if(g_epo_socket_cntx.socket_id != -1){
			#ifdef __TCPIP__
				soc_close(g_epo_socket_cntx.socket_id); 
			#endif
				g_epo_socket_cntx.socket_id=-1;
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_RELEASED, g_epo_socket_cntx.socket_id));
			}else{
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
			}
			EPODOWNLOAD_SET_FLAG(FLAG_FINISH);
			if(mtk_gps_sys_epodownload_check() == MTK_GPS_ERROR){
				epodownload_submit_error(ERR_FILE_CHECKSUM_FAIL);
				return epodownload_type_success;
			}else{
				EPODOWNLOAD_SET_FLAG(FLAG_SUCCESS);
				epodownload_submit_error(ERR_NO);
				return epodownload_type_success;
			}
	}
	return epodownload_type_fail;
}


/******************************************Global variable end******************/
/*******************************create and connect my socket start*****************/
#ifdef __TCPIP__
static void my_socket_create(void)
{
    cbm_app_info_struct info;                        
    kal_uint8 val_async;                            //¡§|¡§¡§??socket?a¡§¡ã¡§?2?|¨¬?val?|¨¬
    kal_bool val_nonblocking=KAL_TRUE;                //¡§|¡§¡§??socket?a?¡è??¨¢¡§¡§¡§¡§?|¨¬?val?|¨¬
    kal_char *dest=EPOSERVER_NAME;//"www.baidu.com";
    kal_uint8 recvaddr[MAX_SOCK_ADDR_LEN];
    kal_uint8 addr_len ;
    kal_int8 ret_domain=SOC_ERROR;
    kal_int8 ret_connect=SOC_ERROR;

	//Step 1: check whether network is avaliable
	if(epodownload_function.epodownload_srv_mode_switch_is_network_service_available()== MMI_FALSE){
		epodownload_submit_error(ERR_NETWORK_UNAVALIABLE);
		return;
	}

	//Step 2: register data account
    if(g_epo_socket_cntx.app_id==0)
    {
        memset(&info,0,sizeof(info));                    //3?¡§o???£¤info
        info.app_str_id = 0;            //?¨¢??o??¡ì¡§¡ã?|¨¬??¨¢????
        info.app_icon_id = 0;            //?¨¢??o??¡ì¡§¡ã?|¨¬?icon
		info.app_type = DTCNT_APPTYPE_GPS;//DTCNT_APPTYPE_BRW_HTTP; //¡§a?¡ì1ysmart?-?¡§¡ã?¨º??¡ê¡è??apn?acmnet|¨¬?data account
        cbm_register_app_id_with_app_info(&info,&g_epo_socket_cntx.app_id);        //?¨¢?¨¦2¡§¡éapp id
        g_epo_socket_cntx.account_id=CBM_DEFAULT_ACCT_ID;
        g_epo_socket_cntx.account_id=
			cbm_encode_data_account_id(g_epo_socket_cntx.account_id,0,g_epo_socket_cntx.app_id,KAL_FALSE);//encode data account id?¨º?¡ì¡§oy?Y????¨¬id?¨º?
    }
    if(g_epo_socket_cntx.app_id == 0)
    {
		epodownload_submit_error(ERR_REGISTER_APPID);
        return ;
    }

	//Step3: socket create
    g_epo_socket_cntx.socket_id = 
		soc_create(SOC_PF_INET,SOC_SOCK_STREAM,0,MOD_GPSADAPTOR, g_epo_socket_cntx.account_id);//??????¡ìsocket id
    if(g_epo_socket_cntx.socket_id < 0)
    {
		epodownload_submit_error(ERR_SOCKET_CREATE);
        return ;
    }
	
	//Step4:socket set nonblocking
    if(soc_setsockopt(g_epo_socket_cntx.socket_id,SOC_NBIO, &val_nonblocking,sizeof(val_nonblocking))<0)//¡§|¡§¡§??socket?????a?¡è??¨¢¡§¡§¡§¡§?
    {
		epodownload_submit_error(ERR_SOCKET_SET_PARAM_NBIO);
        return ;
    }


	//Step5:socket set async
	val_async = SOC_WRITE | SOC_READ | SOC_CONNECT | SOC_CLOSE;//¡§|¡§¡§??socket?????a¡§¡ã¡§?2?
    if(soc_setsockopt(g_epo_socket_cntx.socket_id,SOC_ASYNC, & val_async,sizeof(val_async))<0)
    {
		epodownload_submit_error(ERR_SOCKET_SET_PARAM_ASYNC);
		return ;
    }

	//Step6:DNS
    ret_domain=soc_gethostbyname(KAL_FALSE,MOD_GPSADAPTOR,1,dest,recvaddr,&addr_len,0, g_epo_socket_cntx.account_id);                 //?????¨¤¡§o¡§?¡§¡ã????DD?a???¨º???|¨¬????¨¤¡§oserver|¨¬?ip??¨º
    if(ret_domain == SOC_SUCCESS)
    {
        memcpy(g_epo_socket_cntx.g_test_ip.addr,recvaddr,addr_len); //??¡§?¡§¡ã???a??|¨¬?|¨¬?|¨¬?ip?¨¤?¨º???|¨¬??¡§¡é11¡§???D
		g_epo_socket_cntx.g_test_ip.addr_len = addr_len;            //|¨¬???¡è3?¨¨?¡§¡§
    #if defined(__GPS_SSL_SUPPORT__)
        g_epo_socket_cntx.g_test_ip.port = 443;                    //???¡§2
    #else
        g_epo_socket_cntx.g_test_ip.port = 80;                    //???¡§2
    #endif
        g_epo_socket_cntx.g_test_ip.sock_type = SOC_SOCK_STREAM;        //socket type?atcp

		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_DNS_SERVER_IP,
						g_epo_socket_cntx.g_test_ip.addr[0],
						g_epo_socket_cntx.g_test_ip.addr[1],
						g_epo_socket_cntx.g_test_ip.addr[2],
						g_epo_socket_cntx.g_test_ip.addr[3]));
		
		//step7:connect to server
        ret_connect = soc_connect(g_epo_socket_cntx.socket_id,&g_epo_socket_cntx.g_test_ip);    //¡§???¡èt???????¡ì¡§¡é?¨¦¡§¡é??¡§?	
        if(ret_connect == SOC_SUCCESS)
        {	
#if defined(__GPS_SSL_SUPPORT__)
            epodownload_ssl_init_cntx();
#endif
            my_socket_send();                            //¡§¡é??¡§?3¡§|1|?¡§ahttp request		
        }
        else if(ret_connect != SOC_WOULDBLOCK)            //¡§¡é??¡§?¡§o?¨¬??¡§1
        {
			epodownload_submit_error(ERR_SOCKET_CONNECT);
            return ;
        }
    }
    else if(ret_domain != SOC_WOULDBLOCK)                //¡§?¡§¡ã???a??¡§o?¨¬??¡§1
    {
		epodownload_submit_error(ERR_DNS);
        return ;
    }
	
	
}
/***********************************create my socket end*****************/
/***********************************send http request start*****************/
#if !defined(__GPS_SSL_SUPPORT__)

static void my_socket_send(void)
{
    S32 ret_send=0;
    S8 CRLF[] = {0x0d,0x0a,0x00};
    S8 send_buf[128+64]={0};
	char *dest;

	if(g_epo_socket_cntx.socket_id == -1){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
		return;
	}
    memset(send_buf,0,sizeof(send_buf));
	
	if(g_epo_socket_cntx.EPOFILE_SIZE==EPOFILE_SIZE_30){
		dest=SERVER_EPOFILE_30DAYS;
	}
	else if(g_epo_socket_cntx.EPOFILE_SIZE==EPOFILE_SIZE_7){
		dest=SERVER_EPOFILE_7DAYS;
	}else{
		ASSERT(0);
	}

	strcat(send_buf,"GET ");
	strcat(send_buf,dest);
	strcat(send_buf," HTTP/1.1");
    strcat(send_buf,CRLF);
	strcat(send_buf,"Host: epodownload.mediatek.com");
    strcat(send_buf,CRLF);
	strcat(send_buf,"Cache-Control: no-cache");
    strcat(send_buf,CRLF);
	strcat(send_buf,"Pragma: no-cache");
    strcat(send_buf,CRLF);
	strcat(send_buf,CRLF);

	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:epodownload send download req: %s.\n",
						__FUNCTION__,
						send_buf);

	//step8:send download request
    ret_send=soc_send(g_epo_socket_cntx.socket_id, send_buf,strlen(send_buf)+1,0);
    if(ret_send > 0)
    {		
        my_socket_receive();
    }
    else if(ret_send != SOC_WOULDBLOCK)
    {
		epodownload_submit_error(ERR_SEND_DOWNLOAD_REQ);
        return ;
    }
}

#else
static void my_socket_send(void)
{
    S32 ret_send=0;

	if(g_epo_socket_cntx.socket_id == -1){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
		return;
	}
	
	if(g_epo_socket_cntx.EPOFILE_SIZE==EPOFILE_SIZE_30){
		ret_send = epodownload_ssl_send_request(g_epo_socket_cntx.socket_id, 30);
	}
	else if(g_epo_socket_cntx.EPOFILE_SIZE==EPOFILE_SIZE_7){
		ret_send = epodownload_ssl_send_request(g_epo_socket_cntx.socket_id, 7);
	}
    else
    {
		ASSERT(0);
	}

	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:epodownload send download ret: %d.\n",
						__FUNCTION__,
						ret_send);

	//step8:send download request
    if(ret_send > 0)
    {		
        my_socket_receive();
    }
    else if(ret_send != SOC_WOULDBLOCK)
    {
		epodownload_submit_error(ERR_SEND_DOWNLOAD_REQ);
        return ;
    }
}

#endif

/********************************send http request end*********************/

static epodownload_bool_type deal_with_receiving_packet(U8 *buffer,U32 length){
	S32 ret_recv=length;
	int i;
	mtk_uint32 len=0;
	int sum_temp;
	
	if(EPODOWNLOAD_GET_FLAG(FLAG_FIND_ETAG) == epodownload_type_success){
		//step11:deal with receiving data for rest part.
		sum_temp=g_epo_socket_cntx.sum;
		g_epo_socket_cntx.sum+=ret_recv;
		if(g_epo_socket_cntx.sum>g_epo_socket_cntx.EPOFILE_SIZE){
			if(MTK_GPS_ERROR == mtk_gps_sys_epodownload_write(&g_epo_socket_cntx.recv_buf[0],
						0,
						g_epo_socket_cntx.EPOFILE_SIZE-sum_temp,
						&len) ){
				epodownload_submit_error(ERR_FILE_WRITE_FAIL);
				return epodownload_type_fail;
			}			
			g_epo_socket_cntx.sum=g_epo_socket_cntx.EPOFILE_SIZE;
		}else{
			if(MTK_GPS_ERROR == mtk_gps_sys_epodownload_write(&g_epo_socket_cntx.recv_buf[0],
						0,
						ret_recv,
						&len) ){
				epodownload_submit_error(ERR_FILE_WRITE_FAIL);
				return epodownload_type_fail;
			}
		}		
	}else{//find \r\n\r\n,then writen the following content
		//step10:deal with receiving data for find some properties.
		for(i=0;i<ret_recv-3;i++){
			if(g_epo_socket_cntx.recv_buf[i]==0x0d && g_epo_socket_cntx.recv_buf[i+1]==0x0a && 
				g_epo_socket_cntx.recv_buf[i+2]==0x0d && g_epo_socket_cntx.recv_buf[i+3]==0x0a){			
				if(epofile_property(g_epo_socket_cntx.recv_buf,ret_recv) == KAL_FALSE){
					return;
				}
				i+=4;
				g_epo_socket_cntx.sum+=i;
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SUMMARY_BEFORE_EPOFILE,
						g_epo_socket_cntx.sum));
					
				g_epo_socket_cntx.sum=ret_recv-i;
				if(MTK_GPS_ERROR == mtk_gps_sys_epodownload_open()){
					epodownload_submit_error(ERR_FILE_OPEN_FAIL);
					return epodownload_type_fail;
				}
				if(MTK_GPS_ERROR == mtk_gps_sys_epodownload_write(&g_epo_socket_cntx.recv_buf[i],
						0,
						g_epo_socket_cntx.sum,
						&len) ){
					epodownload_submit_error(ERR_FILE_WRITE_FAIL);
					return epodownload_type_fail;
				}
				
				return epodownload_type_success;	
				break;
			}
		}
	}
	return epodownload_type_success;
}



/********************************receive http response start*****************/
static void my_socket_receive(void)
{
    S32 ret_recv=0;
	int i;
	mtk_uint32 len=0;
	int sum_temp;

	if(g_epo_socket_cntx.socket_id == -1){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
		return;
	}
	

	//step9:receive data
	while(g_epo_socket_cntx.err_code==ERR_NO && g_epo_socket_cntx.socket_id != -1){
        #if !defined(__GPS_SSL_SUPPORT__)
		ret_recv = soc_recv(
							g_epo_socket_cntx.socket_id,
							g_epo_socket_cntx.recv_buf + g_epo_socket_cntx.recv_buf_len,
							sizeof(g_epo_socket_cntx.recv_buf)-g_epo_socket_cntx.recv_buf_len,
							0
					);
        #else
        
        ret_recv = epodownload_ssl_recv(
							g_epo_socket_cntx.socket_id,
							g_epo_socket_cntx.recv_buf + g_epo_socket_cntx.recv_buf_len,
							sizeof(g_epo_socket_cntx.recv_buf)-g_epo_socket_cntx.recv_buf_len,
							0
					);
        

        #endif
		if(ret_recv >= 0){//receive  data
			g_epo_socket_cntx.recv_buf_len += ret_recv;
		}else if(ret_recv != SOC_WOULDBLOCK){//occur error
			epodownload_submit_error(ERR_DATA_RECEIVE);
			return;
		}
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_RECEIVE_STATUS,
						ret_recv ,
						g_epo_socket_cntx.recv_buf_len,
						g_epo_socket_cntx.sum));
		if(g_epo_socket_cntx.recv_buf_len ==0 && ret_recv == SOC_WOULDBLOCK){//no receive data
			GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_RECEIVE_NO_DATA
						));
			return;
		}
		
		//when meet condition: receive the whole packet, or have received some packet and last packet size<=0, or received count more than epofilesize
		if(g_epo_socket_cntx.recv_buf_len == sizeof(g_epo_socket_cntx.recv_buf) || 
			(g_epo_socket_cntx.recv_buf_len != ret_recv) ||
			g_epo_socket_cntx.sum + g_epo_socket_cntx.recv_buf_len >= g_epo_socket_cntx.EPOFILE_SIZE ){
			
			if(deal_with_receiving_packet(g_epo_socket_cntx.recv_buf,g_epo_socket_cntx.recv_buf_len) == epodownload_type_fail)
				return;
			if(epodownload_type_success == check_download_finish()){
				return;
			}
			g_epo_socket_cntx.recv_buf_len=0;
		}
		
		
		if(ret_recv<=0)break;
	}
	return;  
}
/**********************************receive http response end*********************/
/****************app socket notify indication handler start*************************/
static kal_bool my_socket_notify (void* msg_ptr)
{
    app_soc_notify_ind_struct* my_soc_notify = (app_soc_notify_ind_struct*)msg_ptr;
    kal_int8 ret_connect=SOC_ERROR;
    if(my_soc_notify->socket_id != g_epo_socket_cntx.socket_id)
    {
    	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
        return KAL_FALSE;
    }
	if(my_soc_notify->event_type == SOC_CLOSE){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_IGNORE_CLOSED_EVENT));
		return KAL_FALSE;
	}
	if(my_soc_notify->result!= KAL_TRUE){
		epodownload_submit_error(ERR_SOCKET_READ_WRITE_CONNECT_CLOSE);
		return KAL_FALSE;
	}
	
    switch(my_soc_notify->event_type)
    {
        case SOC_READ:
            
        #if defined(__GPS_SSL_SUPPORT__)
            if (epodownload_ssl_get_state() < 15 )
                my_socket_send();
            else
        #endif
            my_socket_receive();
            break;
        case SOC_WRITE:
            my_socket_send();
            break;
        case SOC_CONNECT:
            if(my_soc_notify->result == KAL_FALSE)
            {
                ret_connect = soc_connect(g_epo_socket_cntx.socket_id,&g_epo_socket_cntx.g_test_ip);    //¡§???¡èt???????¡ì¡§¡é?¨¦¡§¡é??¡§?
                if(ret_connect == SOC_SUCCESS)
                {
                #if defined(__GPS_SSL_SUPPORT__)
                    epodownload_ssl_init_cntx();
                #endif
                    my_socket_send();                        //¡§¡é??¡§?3¡§|1|?¡§ahttp request
                }
                else if(ret_connect != SOC_WOULDBLOCK)            //¡§¡é??¡§?¡§o?¨¬??¡§1
                {		
                    soc_close(g_epo_socket_cntx.socket_id);        
                }
            }
            else if(my_soc_notify->result == KAL_TRUE)
            {		
            #if defined(__GPS_SSL_SUPPORT__)
                epodownload_ssl_init_cntx();
            #endif
                my_socket_send();
            }
            break;
        case SOC_CLOSE:
            soc_close(g_epo_socket_cntx.socket_id);
			
			
            break;
    }
	

	
	
    return KAL_TRUE;
}
/******************app socket notify indication handler end*************************/
/***************app socket gethostbyname indication handler start*******************/
static kal_bool my_socket_get_host_by_name(void *msg_ptr)
{
    app_soc_get_host_by_name_ind_struct* dns_ind;
    kal_int8 ret_connect;
    kal_uint8 domain_app_id;    
	if(g_epo_socket_cntx.socket_id == -1){
		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SOCKET_ALREADY_RELEASED));
		return KAL_FALSE;
	}
    if(!(msg_ptr))
    {
        return KAL_FALSE;
    }
	
		
    dns_ind = (app_soc_get_host_by_name_ind_struct*)msg_ptr;
    domain_app_id = cbm_get_app_id(dns_ind->account_id);
    if(domain_app_id != g_epo_socket_cntx.app_id)
    {
        return KAL_FALSE;
    }

		
    if(dns_ind->result == KAL_TRUE)
    {
        memcpy(g_epo_socket_cntx.g_test_ip.addr,dns_ind->addr,dns_ind->addr_len);
        g_epo_socket_cntx.g_test_ip.addr_len = dns_ind->addr_len;
        #if defined(__GPS_SSL_SUPPORT__)
        g_epo_socket_cntx.g_test_ip.port = 443;
        #else
        g_epo_socket_cntx.g_test_ip.port = 80;
        #endif
        g_epo_socket_cntx.g_test_ip.sock_type = SOC_SOCK_STREAM;

		GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_DNS_SERVER_IP,
						g_epo_socket_cntx.g_test_ip.addr[0],
						g_epo_socket_cntx.g_test_ip.addr[1],
						g_epo_socket_cntx.g_test_ip.addr[2],
						g_epo_socket_cntx.g_test_ip.addr[3]));
		
		//step7:connect to server
        ret_connect = soc_connect(g_epo_socket_cntx.socket_id,&g_epo_socket_cntx.g_test_ip);
        if(ret_connect == SOC_SUCCESS)
        {
        #if defined(__GPS_SSL_SUPPORT__)
            epodownload_ssl_init_cntx();
        #endif
            my_socket_send();
        }
        else if(ret_connect != SOC_WOULDBLOCK)
        {
			epodownload_submit_error(ERR_SOCKET_CONNECT);
        }
    }
    else if(dns_ind->result == KAL_FALSE)
    {
		epodownload_submit_error(ERR_DNS);
    }
    return KAL_TRUE;
}
#else

static void my_socket_create(void)
{
    return;
}
/***********************************create my socket end*****************/
/***********************************send http request start*****************/
#if !defined(__GPS_SSL_SUPPORT__)

static void my_socket_send(void)
{
    return;
}

#else
static void my_socket_send(void)
{
    return;
}

#endif

/********************************send http request end*********************/

static epodownload_bool_type deal_with_receiving_packet(U8 *buffer,U32 length){
	return epodownload_type_success;
}



/********************************receive http response start*****************/
static void my_socket_receive(void)
{
	return;  
}
/**********************************receive http response end*********************/
/****************app socket notify indication handler start*************************/
static kal_bool my_socket_notify (void* msg_ptr)
{
    return KAL_TRUE;
}
/******************app socket notify indication handler end*************************/
/***************app socket gethostbyname indication handler start*******************/
static kal_bool my_socket_get_host_by_name(void *msg_ptr)
{
    return KAL_TRUE;
}


#endif

/***************app socket gethostbyname indication handler end*******************/

void epodownload_bt_connect_ind_hdlr(ilm_struct *ilm_ptr){
	kal_int8 *path=NULL;
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:access_epofile_and_nvram: %d.\n",
							__FUNCTION__,
							access_epofile_and_nvram);
	if(access_epofile_and_nvram==EPODOWNLOAD_NONE_ACCESS){
		if(epodownload_file_need_download(EPODOWNLOAD_EPOFILE_TIME_BT)==KAL_FALSE){
			return;
		}
		path=epodownload_file_root_path();
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:path: %s.\n",
							__FUNCTION__,
							path);
		epodownload_file_delete(path,EPO_FILE_NAME);
		//check freespace
		if(mtk_gps_sys_epodownload_get_freespace()<2*g_epo_socket_cntx.EPOFILE_SIZE){
			return;
		}
		{
			access_epofile_and_nvram=EPODOWNLOAD_GPSADAPTOR_BT_ACCESS;
			send_msg_to_gps_task(MOD_GPSADAPTOR,ilm_ptr->src_mod_id,
				MSG_ID_GPSADAPTOR_APK_DOWNLOAD_REQ,NULL,0);
			gps_adaptor_stop_timer(GPS_EPO_TIMER);
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DOWNLOAD_BY_BT;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 
					EPODOWNLOAD_TIME_DOWNLOAD_BY_BT, epodownload_timer_hdlr, NULL);	
			return;
		}
	}else if(access_epofile_and_nvram==EPODOWNLOAD_MNL_ACCESS){
		gps_adaptor_stop_timer(GPS_EPO_TIMER);
		g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM;
		gps_adaptor_start_timer(GPS_EPO_TIMER, 
			EPODOWNLOAD_TIME_WHETHER_ACCESS_EPOFILE_AND_NVRAM, epodownload_timer_hdlr, NULL);	
		return;
	}else{
		//do nothing
		return;
	}
}
void epodownload_download_finish_hdlr(ilm_struct *ilm_ptr){
	apk_gpsadaptor_download_finish_struct *local_struct;
	kal_int8 *path=NULL;
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_EPOFILE_ACCESS_OWNER,access_epofile_and_nvram));
	gps_adaptor_stop_timer(GPS_EPO_TIMER);
	// 2min timeout lator coming the message.
	if(access_epofile_and_nvram==EPODOWNLOAD_GPSADAPTOR_ACCESS || 
		access_epofile_and_nvram==EPODOWNLOAD_MNL_ACCESS){
		return;
	}
	if(access_epofile_and_nvram==EPODOWNLOAD_NONE_ACCESS){
		access_epofile_and_nvram=EPODOWNLOAD_GPSADAPTOR_BT_ACCESS;
	}
	if(mtk_gps_sys_epodownload_get_freespace()<1*g_epo_socket_cntx.EPOFILE_SIZE){
			return;
		}
	local_struct=(apk_gpsadaptor_download_finish_struct *)(ilm_ptr->local_para_ptr);
	strncpy(g_epo_socket_cntx.check_sum,local_struct->md5,sizeof(g_epo_socket_cntx.check_sum)-1);
	g_epo_socket_cntx.check_sum[sizeof(g_epo_socket_cntx.check_sum)-1]=0;
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:find BT check sum :%s\n",
						__FUNCTION__,
						g_epo_socket_cntx.check_sum);
	if(epodownload_file_download_success(EPO_FILE_NAME_BT) == KAL_TRUE){
		path=epodownload_file_root_path();
		hEPOHandle=epodownload_file_open(path,EPO_FILE_NAME_BT,FS_READ_ONLY);
		hEPOHandle_final=epodownload_file_open(path,EPO_FILE_NAME,FS_READ_WRITE | FS_CREATE);
		if(hEPOHandle>=0){
			if(hEPOHandle_final>=0){
				if(MTK_GPS_SUCCESS != mtk_gps_sys_epodownload_copy()){
					kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:cann't copy EPO.DAT\n",
						__FUNCTION__);
				}
				save_download_time_nvram();
				//epodownload_cntx_init_after_download_success();
				g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_EPOFILE_INVALID;
				gps_adaptor_start_timer(GPS_EPO_TIMER,EPODOWNLOAD_EPOFILE_TIME, epodownload_timer_hdlr, NULL);
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_BT_DOWNLOAD_SUCCESS));
			}else{
				epodownload_file_close(hEPOHandle);
			}
		}
	}
	epodownload_file_close(hEPOHandle);
	epodownload_file_close(hEPOHandle_final);
	if(EPODOWNLOAD_FILE_RESULT_SUCCESS != epodownload_file_delete(path,EPO_FILE_NAME_BT)){
		kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:cann't delete :%s\n",
						__FUNCTION__,
						EPO_FILE_NAME_BT);
	}
	access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
}
void epodownload_req_hdlr_socket(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 msg_id = ilm_ptr->msg_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(msg_id)
    {
    case MSG_ID_APP_SOC_GET_HOST_BY_NAME_IND:
		my_socket_get_host_by_name(ilm_ptr->local_para_ptr);
		break;
	case MSG_ID_APP_SOC_NOTIFY_IND:
		my_socket_notify(ilm_ptr->local_para_ptr);
		break;
	case MSG_ID_APK_GPSADAPTOR_BT_CONNECT_IND:		
		epodownload_bt_connect_ind_hdlr(ilm_ptr);
		break;
	case MSG_ID_APK_GPSADAPTOR_DOWNLOAD_FINISH:
		epodownload_download_finish_hdlr(ilm_ptr);
		break;
    default:
        //ASSERT(0);
        break;
    }
}



void epofile_download_socket(void){
	
	EPODOWNLOAD_SET_FLAG(FLAG_START_DOWNLOAD);
	gps_adaptor_stop_timer(GPS_EPO_TIMER);

	if(mtk_gps_sys_epodownload_get_freespace() < 
		(g_epo_socket_cntx.epofile_save_option == EPOFILE_USING_TEMPFILE ? 
		2*g_epo_socket_cntx.EPOFILE_SIZE:g_epo_socket_cntx.EPOFILE_SIZE)){

		//need to delete,because when EPO file exist in device, and user download new bin, then decide no enough space to using
		mtk_gps_sys_epodownload_delete_file(mtk_gps_sys_epodownload_get_drvletter(),EPO_FILE_NAME);
		if(g_epo_socket_cntx.epofile_save_option == EPOFILE_USING_TEMPFILE){
			mtk_gps_sys_epodownload_delete_file(mtk_gps_sys_epodownload_get_drvletter(),EPO_TEMPFILE_NAME);
		}
		epodownload_submit_error(ERR_NO_ENOUGH_FREESPACE);
		return;
	}
	
	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD;
	gps_adaptor_start_timer(GPS_EPO_TIMER, EPODOWNLOAD_BEGIN_TIME, epodownload_timer_hdlr, NULL);	

	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_BEGIN
						));
	my_socket_create();
}

void select_7_30day_epodownload(void){
	if(EPOFILE_SIZE_SELECT_30_DAY_SUPPORT == 1){
		g_epo_socket_cntx.EPOFILE_SIZE=EPOFILE_SIZE_30;
	}else{
		g_epo_socket_cntx.EPOFILE_SIZE=EPOFILE_SIZE_7;
	}
	GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_SELECT_DAYS,
						g_epo_socket_cntx.EPOFILE_SIZE/9/1024));
	return;
}

void select_whether_using_tempfile(void){
	if(EPOFILE_SAVE_USING_TMEPFILE_SUPPORT == 1){
		g_epo_socket_cntx.epofile_save_option=EPOFILE_USING_TEMPFILE;
	}else{
		g_epo_socket_cntx.epofile_save_option=EPOFILE_NO_USING_TEMPFILE;
	}
	kal_prompt_trace(MOD_GPSADAPTOR, "[epodownload][%s]:%s using tempfile.\n",
						__FUNCTION__,
						g_epo_socket_cntx.epofile_save_option==EPOFILE_USING_TEMPFILE?"":"no");
	return;
}




void epodownload(void){
   epodownload_get_onoff(&g_epo_socket_cntx);
	if(g_epo_socket_cntx.epodownload_enable == 0){
		return;
	}
	
	if(access_epofile_and_nvram==EPODOWNLOAD_MNL_ACCESS){
	  gps_adaptor_stop_timer(GPS_EPO_TIMER);
		g_epo_socket_cntx.timer_handler_type=
			TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM_WHEN_GPRS_DOWNLOAD;
		gps_adaptor_start_timer(GPS_EPO_TIMER, EPODOWNLOAD_TIME_WHETHER_ACCESS_EPOFILE_AND_NVRAM,
								epodownload_timer_hdlr, NULL);	
		return;
	}
	switch(access_epofile_and_nvram){
	case EPODOWNLOAD_GPSADAPTOR_BT_ACCESS:
	case EPODOWNLOAD_GPSADAPTOR_ACCESS:
		return;
		break;
	}
	access_epofile_and_nvram=EPODOWNLOAD_GPSADAPTOR_ACCESS;
	if(check_whether_download() == MTK_GPS_SUCCESS){
		epofile_download_socket();
	}else{
		access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
		if(EPODOWNLOAD_GET_FLAG(FLAG_ACCESS_NVRAM_ERR) == epodownload_type_success ||
			EPODOWNLOAD_GET_FLAG(FLAG_FILE_OCCURED_ERR) == epodownload_type_success){
			EPODOWNLOAD_RESET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			EPODOWNLOAD_RESET_FLAG(FLAG_FILE_OCCURED_ERR);
			gps_adaptor_stop_timer(GPS_EPO_TIMER);
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_REBOOT;
			gps_adaptor_start_timer(GPS_EPO_TIMER, EPODOWNLOAD_AFTER_REBOOT, epodownload_timer_hdlr, NULL);	
		}else{
			//indicate realy needn't download
			mtk_int32 when=check_when_download();
			when = when<0?0:when;
			gps_adaptor_stop_timer(GPS_EPO_TIMER);
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NEXT_DOWNLOAD;
			gps_adaptor_start_timer(GPS_EPO_TIMER, when , epodownload_timer_hdlr, NULL);	
		}
	}
	return ;
}


void epodownload_test_handler( ilm_struct *ilm_ptr )
{
    tst_module_string_inject_struct* tst_inject = (tst_module_string_inject_struct*)ilm_ptr->local_para_ptr;
	kal_uint32 sub_command=0;
	if(strlen(tst_inject->string)){
		sscanf(tst_inject->string, "%d", &sub_command); 
		kal_prompt_trace(MOD_GPSADAPTOR,"[epodownload][%s] command=%d,subcommand=%d\n",
			__FUNCTION__,
			tst_inject->index,
			sub_command);
	}
		if (0 == tst_inject->index)
    {	
    	access_epofile_and_nvram=sub_command;
    }
    if (1 == tst_inject->index)
    {	
    	if(sub_command == 1){
			epodownload();
		}
		if(sub_command == 2){
			gps_adaptor_stop_timer(GPS_EPO_TIMER);
			epodownload_cntx_init_after_reboot();
			access_epofile_and_nvram=EPODOWNLOAD_NONE_ACCESS;
		}
    }
    else if (2 == tst_inject->index)
    {
    	if(sub_command == 1){
			g_epo_socket_cntx.epofile_save_option=EPOFILE_USING_TEMPFILE;
		}
		if(sub_command == 2){
			g_epo_socket_cntx.epofile_save_option=EPOFILE_NO_USING_TEMPFILE;
		}
    }
	else if (3 == tst_inject->index)
    {
    	if(sub_command == 1){
			g_epo_socket_cntx.EPOFILE_SIZE=7*9*1024;
		}
		if(sub_command == 2){
			g_epo_socket_cntx.EPOFILE_SIZE=30*9*1024;
		}    
    }
	else if (4 == tst_inject->index)
    {
    	if(sub_command == 1){
			mtk_gps_sys_epodownload_delete_file(mtk_gps_sys_epodownload_get_drvletter(),EPO_FILE_NAME);
		}
		if(sub_command == 2){
			mtk_gps_sys_epodownload_delete_file(mtk_gps_sys_epodownload_get_drvletter(),EPO_TEMPFILE_NAME);
		}  
    }
	else if (5 == tst_inject->index)
    {
    	epodownload_submit_error(sub_command);
    }
	else if (6 == tst_inject->index)
    {
    #ifdef __TCPIP__
    	if(sub_command == 1){
			//Step 1: check whether network is avaliable
			if(epodownload_function.epodownload_srv_mode_switch_is_network_service_available()  == MMI_FALSE){
				epodownload_submit_error(ERR_NETWORK_UNAVALIABLE);
				return;
			}
		}
		if(sub_command == 2){
			//Step 2: register data account
			cbm_app_info_struct info; 
		    if(g_epo_socket_cntx.app_id==0)
		    {
		        memset(&info,0,sizeof(info));                    //3?¡§o???£¤info
		        info.app_str_id = 0;            //?¨¢??o??¡ì¡§¡ã?|¨¬??¨¢????
		        info.app_icon_id = 0;            //?¨¢??o??¡ì¡§¡ã?|¨¬?icon
				info.app_type = DTCNT_APPTYPE_BRW_HTTP; //¡§a?¡ì1ysmart?-?¡§¡ã?¨º??¡ê¡è??apn?acmnet|¨¬?data account
		        cbm_register_app_id_with_app_info(&info,&g_epo_socket_cntx.app_id);        //?¨¢?¨¦2¡§¡éapp id
		        g_epo_socket_cntx.account_id=
					cbm_encode_data_account_id(g_epo_socket_cntx.account_id,0,g_epo_socket_cntx.app_id,KAL_FALSE);//encode data account id?¨º?¡ì¡§oy?Y????¨¬id?¨º?
		    }
		    if(g_epo_socket_cntx.app_id == 0)
		    {
				epodownload_submit_error(ERR_REGISTER_APPID);
		        return ;
		    }
		}  
		if(sub_command == 3){
			//Step3: socket create
		    g_epo_socket_cntx.socket_id = 
				soc_create(SOC_PF_INET,SOC_SOCK_STREAM,0,MOD_GPSADAPTOR, g_epo_socket_cntx.account_id);//??????¡ìsocket id
		    if(g_epo_socket_cntx.socket_id < 0)
		    {
				epodownload_submit_error(ERR_SOCKET_CREATE);
		        return ;
		    }
		}  
		if(sub_command == 4){
			//Step4:socket set nonblocking
			kal_bool val_nonblocking=KAL_TRUE;  
		    if(soc_setsockopt(g_epo_socket_cntx.socket_id,SOC_NBIO, &val_nonblocking,sizeof(val_nonblocking))<0)//¡§|¡§¡§??socket?????a?¡è??¨¢¡§¡§¡§¡§?
		    {
				epodownload_submit_error(ERR_SOCKET_SET_PARAM_NBIO);
		        return ;
		    }
		}  
		if(sub_command == 5){
			//Step5:socket set async
			kal_uint8 val_async;  
			val_async = SOC_WRITE | SOC_READ | SOC_CONNECT | SOC_CLOSE;//¡§|¡§¡§??socket?????a¡§¡ã¡§?2?
		    if(soc_setsockopt(g_epo_socket_cntx.socket_id,SOC_ASYNC, & val_async,sizeof(val_async))<0)
		    {
				epodownload_submit_error(ERR_SOCKET_SET_PARAM_ASYNC);
				return ;
		    }
		}  
		if(sub_command == 6){
			//Step6:DNS
			kal_int8 ret_domain=SOC_ERROR;
			kal_char *dest=EPOSERVER_NAME;//"www.baidu.com";
    		kal_uint8 recvaddr[MAX_SOCK_ADDR_LEN];
    		kal_uint8 addr_len ;
			kal_int8 ret_connect=SOC_ERROR;
		    ret_domain=soc_gethostbyname(KAL_FALSE,MOD_GPSADAPTOR,1,dest,recvaddr,&addr_len,0, g_epo_socket_cntx.account_id);                 //?????¨¤¡§o¡§?¡§¡ã????DD?a???¨º???|¨¬????¨¤¡§oserver|¨¬?ip??¨º
		    if(ret_domain == SOC_SUCCESS)
		    {
		        memcpy(g_epo_socket_cntx.g_test_ip.addr,recvaddr,addr_len); //??¡§?¡§¡ã???a??|¨¬?|¨¬?|¨¬?ip?¨¤?¨º???|¨¬??¡§¡é11¡§???D
				g_epo_socket_cntx.g_test_ip.addr_len = addr_len;            //|¨¬???¡è3?¨¨?¡§¡§
            #if defined(__GPS_SSL_SUPPORT__)
                g_epo_socket_cntx.g_test_ip.port = 443;                    //???¡§2
            #else
                g_epo_socket_cntx.g_test_ip.port = 80;                    //???¡§2
            #endif
		        g_epo_socket_cntx.g_test_ip.sock_type = SOC_SOCK_STREAM;        //socket type?atcp

				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_DNS_SERVER_IP,
								g_epo_socket_cntx.g_test_ip.addr[0],
								g_epo_socket_cntx.g_test_ip.addr[1],
								g_epo_socket_cntx.g_test_ip.addr[2],
								g_epo_socket_cntx.g_test_ip.addr[3]));
				
				//step7:connect to server
		        ret_connect = soc_connect(g_epo_socket_cntx.socket_id,&g_epo_socket_cntx.g_test_ip);    //¡§???¡èt???????¡ì¡§¡é?¨¦¡§¡é??¡§?	
		        if(ret_connect == SOC_SUCCESS)
		        {	
		            
                #if defined(__GPS_SSL_SUPPORT__)
                    epodownload_ssl_init_cntx();
                #endif
		            my_socket_send();                            //¡§¡é??¡§?3¡§|1|?¡§ahttp request		
		        }
		        else if(ret_connect != SOC_WOULDBLOCK)            //¡§¡é??¡§?¡§o?¨¬??¡§1
		        {
					epodownload_submit_error(ERR_SOCKET_CONNECT);
		            return ;
		        }
		    }
			else if(ret_domain != SOC_WOULDBLOCK)                //¨®¨°???a??¨º¡ì¡ã¨¹
		    {
				epodownload_submit_error(ERR_DNS);
		        return ;
		    }
		}  
		if(sub_command == 7){
			
		}  
		#endif
    }
	else if (7 == tst_inject->index)
    {
    	gps_adaptor_stop_timer(GPS_EPO_TIMER);
    	g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD;
		gps_adaptor_start_timer(GPS_EPO_TIMER, 0, epodownload_timer_hdlr, NULL);	
    }
	else if (8 == tst_inject->index)
    {
		if(sub_command == 1){
			gps_adaptor_stop_timer(GPS_EPO_TIMER);
		}  
	
    	if(sub_command == 2){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}  
		
    	if(sub_command == 3){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 20*1000, epodownload_timer_hdlr, NULL);	
		}  

		if(sub_command == 4){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_EPOFILE_INVALID;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
		if(sub_command == 5){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_NEXT_DOWNLOAD;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
		if(sub_command == 6){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_REBOOT;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
		if(sub_command == 7){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_SAVELOCALTIME;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
		if(sub_command == 8){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_SUCCESS;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
		if(sub_command == 9){
			g_epo_socket_cntx.timer_handler_type=TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_FAILURE;
			gps_adaptor_start_timer(GPS_EPO_TIMER, 10*1000, epodownload_timer_hdlr, NULL);	
		}
    }
	else if (9 == tst_inject->index)
    {
    	int ret=KAL_TRUE;
		if(sub_command == 1){
			ret=nvram_external_read_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
			if(ret==KAL_FALSE){
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_FAILURE
						));
			}else{
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_READ_SUCCESS
						));
			}
		}  
	
    	if(sub_command == 2){
			ret=nvram_external_write_data( NVRAM_EF_MNL_SETTING_DATA_LID, 1, (kal_uint8 *)&mnl_nvram, NVRAM_EF_MNL_SETTING_DATA_SIZE);
			if(ret==KAL_FALSE){
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_FAILURE
						));
				EPODOWNLOAD_SET_FLAG(FLAG_ACCESS_NVRAM_ERR);
			}else{
				GPSADAPTOR_TRACE((TRACE_FUNC, GPSADAPOOR_EPODOWNLOAD_NVRAM_WRITE_SUCCESS
						));
			}
		}  
	}
	else if (10 == tst_inject->index)
    {
    	int ret=KAL_TRUE;
		if(sub_command == 1){
			mtk_gps_sys_epodownload_open();
		}  
	
    	if(sub_command == 2){
			mtk_gps_sys_epodownload_close();
		}  
	}
	else if (11 == tst_inject->index)
    {
    	
#if defined(__GPS_SSL_SUPPORT__)
		if(sub_command == 1)
        {
			epodownload_ssl_set_debug(1);
		}
    	else if(sub_command == 2)
        {
			epodownload_ssl_set_debug(0);
		}  
        
        epodownload_ssl_set_debug2(tst_inject->string);
            
#endif
	}
	else if (12 == tst_inject->index)
    {
    	int ret=KAL_TRUE;
		g_epo_socket_cntx.epodownload_enable = sub_command;
		epodownload_set_onoff(&g_epo_socket_cntx);
	}
	else if (13 == tst_inject->index)
    {
    	int ret=KAL_TRUE;
		g_epo_socket_cntx.epodownload_enable = sub_command;
		epodownload_get_onoff(&g_epo_socket_cntx);
	}
}



#endif
#endif
