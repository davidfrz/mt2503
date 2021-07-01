/***********************************************************************
*   This software/firmware and related documentation ("MediaTek Software") 
*   are protected under relevant copyright laws. The information contained 
*   herein is confidential and proprietary to MediaTek Inc. and/or its licensors.
*
*   Without the prior written permission of MediaTek Inc. and/or its licensors, 
*   any reproduction, modification, use or disclosure of MediaTek Software, and 
*   information contained herein, in whole or in part, shall be strictly prohibited.
*
*   MediaTek Inc. (C) [2014]. All rights reserved.
*
*************************************************************************/ 
#ifndef _EPODOWNLOAD_H_
#define _EPODOWNLOAD_H_

#include "wps_struct.h"
#include "kal_public_defs.h"
#include "cbm_api.h"
#include "cbm_consts.h"
#include "wap_cmmn_utils.h"
#include "stack_ltlcom.h"
#include "syscomp_config.h"
#include "stdlib.h"  




#include "fs_errcode.h"
#include "fs_type.h"
#include "fs_func.h"


#include "mtk_gps.h"
#include "kal_trace.h"

#include "mtk_gps_type.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "soc_api.h"
#include "app_md5.h"
#include "ModeSwitchSrvGprot.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include <time.h>
#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "gps_trc.h"
#include "tst_sap.h"



enum{
	TYPE_NOT_DOWNLOAD=0,
	TYPE_DOWNLOAD=1,
	TYPE_FILE_ERR=2,
	TYPE_NVRAM_ERR=3,
};


enum{
	DOWNLOAD_FINISHED,
	DOWNLOAD_COURSE_FAILURE
};

typedef enum{
	ERR_NO=0,
	ERR_NO_ENOUGH_FREESPACE=1,
	ERR_NETWORK_UNAVALIABLE,//
	ERR_REGISTER_APPID,//
	ERR_SOCKET_CREATE,//
	ERR_SOCKET_SET_PARAM_NBIO,//
	ERR_SOCKET_SET_PARAM_ASYNC,//
	ERR_DNS,//
	ERR_SOCKET_CONNECT,//
	ERR_SEND_DOWNLOAD_REQ,//
	ERR_LENGTH_NOT_MATCH,//
	ERR_ETAG_NOT_FOUND,//
	ERR_FILE_OPEN_FAIL,//
	ERR_DATA_RECEIVE,//
	ERR_SOCKET_READ_WRITE_CONNECT_CLOSE,//
	ERR_RETRY_COUNT_OVERFLOW,//
	ERR_FILE_CLOSE_FAIL,//
	ERR_FILE_READ_FAIL,//
	ERR_FILE_WRITE_FAIL,//
	ERR_FILE_CHECKSUM_FAIL,//
	ERR_FILE_DELETE_FAIL,//
	ERR_NOT_FINISHED_WITHIN_TIME,//
	ERR_NEXT_DOWNLOAD,//
	ERR_FILE_COPY_FAIL,//
	ERR_COUNT,
}EPODOWNLOAD_ERR_CODE;

typedef enum{
	TIMEOUT_TYPE_INVALID=-1,
	TIMEOUT_TYPE_NOT_FINISH_DOWNLOAD=0,
	TIMEOUT_TYPE_EPOFILE_INVALID=1,
	TIMEOUT_TYPE_NEXT_DOWNLOAD=2,
	TIMEOUT_TYPE_REBOOT=3,
	TIMEOUT_TYPE_SAVELOCALTIME=4,
	TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_SUCCESS=5,
	TIMEOUT_TYPE_DELETE_EPOFILE_AFTER_DOWNLOAD_FAILURE=6,
	TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM=7,
	TIMEOUT_TYPE_DOWNLOAD_BY_BT=8,
	TIMEOUT_TYPE_QUERY_WHETHER_ACCESS_EPOFILE_AND_NVRAM_WHEN_GPRS_DOWNLOAD=9,
}TIMER_HANDLER_TYPE;

enum {
	EPOFILE_NO_USING_TEMPFILE,
	EPOFILE_USING_TEMPFILE,
};

#define EPO_FILE_NAME_BT "EPO_NEW.DAT"
#define EPO_FILE_NAME "EPO.DAT"
#define EPO_TEMPFILE_NAME "EPO_TEMP.DAT"

#define EPOFILE_SAVE_USING_TMEPFILE_SUPPORT 0
#define EPOFILE_SIZE_SELECT_30_DAY_SUPPORT 0


#define RETRY_MAX_COUNT 5
#define EPOFILE_SIZE_30 30*9*1024
#define EPOFILE_SIZE_7 7*9*1024

#define EPODOWNLOAD_TIME_DOWNLOAD_BY_BT 2*60*1000
#define EPODOWNLOAD_TIME_WHETHER_ACCESS_EPOFILE_AND_NVRAM 5*1000
#define EPODOWNLOAD_AFTER_REBOOT 20*1000
#define EPODOWNLOAD_SAVE_LOCALNVRAM (20*1000)
#define EPODOWNLOAD_EPOFILE_ACCESS_ERR (20*1000)


#define EPODOWNLOAD_EPOFILE_TIME_BT (1*24*3600*1000)
#define EPODOWNLOAD_EPOFILE_TIME (5*24*3600*1000)
#define EPODOWNLOAD_EPOFILE_7_TIME (7*24*3600*1000)
#define EPODOWNLOAD_EPOFILE_30_TIME (30*24*3600*1000)

#define EPODOWNLOAD_BEGIN_TIME 10*60*1000
#define EPODOWNLOAD_SUBMIT_ERR_TIME 0
#define EPODOWNLOAD_DNS_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_CONNECT_SERVER_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_SEND_DOWNLOAD_REQ_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_DATA_RECEIVE_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_SOCKET_NOTIFY_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_CHECKSUM_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_ETAG_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000
#define EPODOWNLOAD_RE_BEGIN_TIME EPODOWNLOAD_SUBMIT_ERR_TIME //30*60000


#define SYSTEM_LEVEL 1000*10
#define NETWORK_LEVEL 1000*5


#define FLAG_SUCCESS 0x00000001
#define FLAG_FINISH  0x00000002
#define FLAG_EXCUTE_ERR_HANDLER 0x00000004
#define FLAG_START_DOWNLOAD 0x00000008
#define FLAG_FIND_ETAG 0x00000010
#define FLAG_ACCESS_NVRAM_ERR 0x00000020
#define FLAG_FILE_OCCURED_ERR 0x00000040

#define EPODOWNLOAD_NONE_ACCESS 0
#define EPODOWNLOAD_MNL_ACCESS 1
#define EPODOWNLOAD_GPSADAPTOR_ACCESS 2
#define EPODOWNLOAD_GPSADAPTOR_BT_ACCESS 3





#define EPOSERVER_NAME "epodownload.mediatek.com"
#define SERVER_EPOFILE_30DAYS "http://epodownload.mediatek.com/EPO.DAT"
#define SERVER_EPOFILE_7DAYS "http://epodownload.mediatek.com/EPO_07.DAT"



typedef enum{
	epodownload_type_success=0,
	epodownload_type_fail=1,
}epodownload_bool_type;

typedef struct{
	kal_uint32 (*epodownload_app_gettime)(kal_uint32 *t_loc);
	void (*epodownload_applib_md5_init)(applib_md5_ctx *mdContext);
	void (*epodownload_applib_md5_update)(applib_md5_ctx *mdContext, const kal_uint8 *inBuf, kal_uint32 inLen);
	void (*epodownload_applib_md5_final)(kal_uint8 hash[], applib_md5_ctx *mdContext);
	MMI_BOOL (*epodownload_srv_mode_switch_is_network_service_available)(void);
	kal_bool initial_flag;
}epodownload_function_struct;

typedef enum{
	epodownload_state_idle=0,
	epodownload_state_check_whether_download,
	epodownload_state_begin_to_download,
	epodownload_state_submit_error,
	epodownload_state_wait_next_download,
	epodownload_state_download_success
}epodownload_state;


typedef struct
{
	signed char  socket_id;
	S8 app_id;
	U32 account_id;
	sockaddr_struct g_test_ip;
	S8 recv_buf[1024];
	U32 recv_buf_len;
	int sum;
	char check_sum[32+1];
	TIMER_HANDLER_TYPE timer_handler_type;
	EPODOWNLOAD_ERR_CODE err_code;

	U32 flag;
	U8 retry_count;
	int EPOFILE_SIZE;
	U8 epofile_save_option;
	U8 epodownload_enable;
} epo_socket_cntx_struct;


typedef struct{
	EPODOWNLOAD_ERR_CODE errID;
	char *str;
}err_id_string;

typedef struct
{
	U8 channel_id;
	U8 request_id;
	U32 seq_num;
	U32	data_size;
	U32 free_size;
	U8 content_type[256];
	U32 account_id;
} epo_wps_cntx_struct;

void epodownload_cntx_init_after_reboot(void);

void epodownload_cntx_init_after_download_success(void);

void epodownload_cntx_init_after_download_failure(void);

static epodownload_bool_type EPODOWNLOAD_GET_FLAG(U32 flag);
static void EPODOWNLOAD_SET_FLAG(U32 flag);
static void EPODOWNLOAD_RESET_FLAG(U32 flag);

static U32 decide_delay(int level,int retry_count);
static void epodownload_submit_error(EPODOWNLOAD_ERR_CODE errcode);

mtk_int32 check_epofile_expire(void);

mtk_uint32 get_download_time_nvram(U32 *sec);

mtk_uint32 save_download_time_nvram(void);



static void epodownload_hdlr(void *param);
void epodownload_timer_hdlr(void *param);
static void epodownload_error_handler(void *param);



static int hash_string(unsigned char *hash,int length);

static kal_bool my_applib_md5_file_update(applib_md5_ctx *mdContext, const kal_wchar *filename);

mtk_int32
mtk_gps_sys_epodownload_get_drvletter (void);
mtk_int32
mtk_gps_sys_epodownload_delete_file (U8 iDrvLetter,U8 *file_name);




static mtk_int32
check_file_exist (void);

mtk_int32 check_when_download(void);

static mtk_int32
check_whether_download (void);

static mtk_int32
mtk_gps_sys_epodownload_get_freespace (void);

static mtk_int32
mtk_gps_sys_epodownload_check (void);

mtk_int32
mtk_gps_sys_epodownload_delete (void);


/*****************************************************************************
 * FUNCTION
 *  mtk_gps_sys_epo_open
 * DESCRIPTION
 *  Open EPO file
 * RETURNS
 *  success(MTK_GPS_SUCCESS)
 *****************************************************************************/
static mtk_int32
mtk_gps_sys_epodownload_open (void);

/*****************************************************************************
 * FUNCTION
 *  mtk_sys_epo_close
 * DESCRIPTION
 *  Close EPO file
 * RETURNS
 *  void
 *****************************************************************************/
static void
mtk_gps_sys_epodownload_close (void);

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
                      mtk_uint32* p_nRead);

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
                       mtk_uint32* p_nWritten);


static mtk_int32
mtk_gps_sys_epodownload_copy (void);



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
#else

/******************************************Global variable start******************/






static mtk_int32 epofile_property(char *buf,int length);
static epodownload_bool_type check_download_finish(void);


/******************************************Global variable end******************/
/*******************************create and connect my socket start*****************/
static void my_socket_create(void);
/***********************************create my socket end*****************/
/***********************************send http request start*****************/
static void my_socket_send(void);
/********************************send http request end*********************/

static epodownload_bool_type deal_with_receiving_packet(U8 *buffer,U32 length);


/********************************receive http response start*****************/
static void my_socket_receive(void);
/**********************************receive http response end*********************/
/****************app socket notify indication handler start*************************/
static kal_bool my_socket_notify (void* msg_ptr);

/******************app socket notify indication handler end*************************/
/***************app socket gethostbyname indication handler start*******************/
static kal_bool my_socket_get_host_by_name(void *msg_ptr);
/***************app socket gethostbyname indication handler end*******************/

void epodownload_req_hdlr_socket(ilm_struct *ilm_ptr);


void epofile_download_socket(void);

void select_7_30day_epodownload(void);

void select_whether_using_tempfile(void);


void epodownload(void);

void epodownload_test_handler( ilm_struct *ilm_ptr );
void epodownload_bt_connect_ind_hdlr(ilm_struct *ilm_ptr);
void epodownload_download_finish_hdlr(ilm_struct *ilm_ptr);



#endif

void epodownload_set_onoff(epo_socket_cntx_struct *cntx);
void epodownload_get_onoff(epo_socket_cntx_struct *cntx);

#endif


