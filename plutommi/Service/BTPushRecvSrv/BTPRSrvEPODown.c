/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 * BTPRSrvEPODown.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for GPS EPO INFO receive srv.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"

#if (defined(__MMI_BT_NOTI_SRV__) && defined(__GPS_ADAPTOR_SUPPORT__))

//#include "Stdlib.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h" 
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "BTNotiSrvRecv.h"
#include "BTNotiSrvGprot.h"
#include "FileMgrSrvGProt.h"
#include "BTPRSrvEPODown.h"
#include "BTPushRecvSrv.h"

#include "mmi_frm_queue_gprot.h"
#include "stack_msgs.h"
#include "FileMgrSrvGProt.h"
#include "Fs_gprot.h"
#include "app_frm_command_gprot.h"

#include "TimerEvents.h"
#include "gps_struct.h"

/*************struct*******************************************/

typedef struct
{
	U8 recv_epo_file; // 0:init, 1:bt recv, 1: copy and rename done
	U8 recv_md5_data;
	kal_uint8 md5_buf[32+1];
	WCHAR src_file_path[BT_NOTIFY_MRE_FILE_NAME_LENTH];
}mmi_btprsrv_epo_info_struct;

typedef struct
{
    LOCAL_PARA_HDR
} mmi_btprsrv_epo_struct;


/******************global varilable**************************************/
#ifdef __GPS_EPO_DOWNLOAD__
#define BTPR_RECV_EPOFILE_CPOY_PATH L" :\\@EPO\\EPO_GR_3_0.DAT"
#else
#define BTPR_RECV_EPOFILE_CPOY_PATH L" :\\EPO_NEW.DAT"
#endif

static mmi_btprsrv_epo_info_struct g_recv_epo_data ; // 0:init, 1:receive epo file, 2: receive md5 data


/********************************************************/

static mmi_ret srv_btpr_epo_del_epo_file_rsp(mmi_event_struct *param);

static mmi_ret srv_btpr_epo_cpoy_epo_file_rsp(mmi_event_struct *info);

static void srv_btpr_epo_gps_request_epo_download(kal_uint8* file_name);

static void srv_btpr_epo_notify_gps_epodown_success(kal_uint8* md5_data);

static void srv_btpr_epo_notify_by_gps(void *arg);

/********************************************************/

static U8 srv_btpr_epo_root_path(void)
{
	U8 driver = 0;
	char path[2] = {0,0};
	driver = FS_GetDrive(FS_DRIVE_I_SYSTEM , 1, FS_DRIVE_V_REMOVABLE | FS_DRIVE_V_NORMAL);
	if (driver < FS_NO_ERROR)
	{
		 /*no card we get normal driver*/
		 driver = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, 0);
	}

	sprintf(path,"%c",driver);
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_EPO, "[BTPushRecvSrv][EPO] srv_btpr_epo_root_path = %s(%d)", path, driver);

	return driver;
}

 void srv_btpr_epo_down_ext_cmd_cb(void *data)
{
    srv_bt_noti_callback_struct *p_data = (srv_bt_noti_callback_struct*)data;

    if (p_data == NULL)
    {
        return;
    }

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_EPO, "[BTPushRecvSrv][EPO] receive data type = %d, sender_id = %s", 
              p_data->data_type, p_data->sender_id);
    //record current bt addr of remote devie
    g_bt_push_addr.lap = p_data->bt_addr.lap;
    g_bt_push_addr.uap = p_data->bt_addr.uap;
    g_bt_push_addr.nap = p_data->bt_addr.nap;

	if (!strcmp(p_data->receiver_id, BT_PUSH_EPO_DOWN_SENDER))
	{
	    if (SRV_BT_NOTI_MRE_DATA_TYPE_FILE == p_data->data_type)
	    {
	    	S32 error_code = srv_fmgr_fs_path_exist(p_data->data.file_path);
	    	kal_prompt_trace(MOD_MMI_CONN_APP, "[BTPushRecvSrv][EPO]srv_btpr_epo_down_ext_cmd_cb: file exist(%d)", error_code);
			if((p_data->err_code == 0) && (error_code >= 0)) //&& (srv_fmgr_fs_path_exist(p_data->data.file_path) >= 0))
			{
				WCHAR m_dest_path[50];
				mmi_wcscpy(m_dest_path, (WCHAR*)BTPR_RECV_EPOFILE_CPOY_PATH);
            	m_dest_path[0] = srv_btpr_epo_root_path();

				if(srv_btpr_epo_root_path() == 0)
					return;
				
				g_recv_epo_data.recv_epo_file = 1;
				
			    // move and rename epo file acorrding to gps design: C:\EPO_NEW.DAT
			    srv_fmgr_async_copy_overwrite(p_data->data.file_path, m_dest_path, 0, srv_btpr_epo_cpoy_epo_file_rsp, NULL);
                memcpy(g_recv_epo_data.src_file_path, p_data->data.file_path, sizeof(WCHAR) * BT_NOTIFY_MRE_FILE_NAME_LENTH); 
                srv_bt_push_recv_reply_int_value(BT_PUSH_EPO_DOWN_SENDER, BT_PUSH_EPO_DOWN_SENDER, 1);
				
				MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_CB_EPO_SUCCESS);
			}
			else
			{
				MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_CB_EPO_FAIL, p_data->err_code);
				// send epo file receive fail cmd to apk
				srv_bt_push_recv_reply_int_value(BT_PUSH_EPO_DOWN_SENDER, BT_PUSH_EPO_DOWN_SENDER, -1);
			}
	    }
		else if (SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER == p_data->data_type)
	    {
	    	if(p_data->err_code == 0)
	    	{	
				// handle md5 data
				if(p_data->data.buffer.len == 32)
				{				
					memcpy(g_recv_epo_data.md5_buf, p_data->data.buffer.data, p_data->data.buffer.len + 1);
					srv_bt_push_recv_reply_int_value(BT_PUSH_EPO_DOWN_SENDER, BT_PUSH_EPO_DOWN_SENDER, 2);
					g_recv_epo_data.recv_md5_data = 1;
					
					MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_CB_MD5_SUCCESS);

					//send md5 file receive sucess cmd to apk 
					if((g_recv_epo_data.recv_epo_file == 2) && (g_recv_epo_data.recv_md5_data == 1))
					{
						srv_btpr_epo_notify_gps_epodown_success(g_recv_epo_data.md5_buf);
						srv_fmgr_async_delete(g_recv_epo_data.src_file_path, 0, srv_btpr_epo_del_epo_file_rsp, NULL);
						memset(&g_recv_epo_data, 0, sizeof(mmi_btprsrv_epo_info_struct));
					}
				}
				else
				{
					MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_CB_MD5_FAIL2, p_data->data.buffer.len);
					srv_bt_push_recv_reply_int_value(BT_PUSH_EPO_DOWN_SENDER, BT_PUSH_EPO_DOWN_SENDER, -2);
				}
			}
			else
			{
				MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_CB_MD5_FAIL1, p_data->err_code);
				// send  md5 data receive fail cmd to apk
				srv_bt_push_recv_reply_int_value(BT_PUSH_EPO_DOWN_SENDER, BT_PUSH_EPO_DOWN_SENDER, -2);
			}
	    }
	}

}

void srv_btpr_epo_down_init(void)
{
    //register tracer epo down load update command hdlr
    srv_bt_notify_register_result_enum reg_ret = srv_bt_noti_register_callback_ext(
                                                                       BT_PUSH_EXTEND_CMD, 
                                                                       BT_PUSH_EPO_DOWN_SENDER, 
                                                                       srv_btpr_epo_down_ext_cmd_cb);
    if (SRV_BT_NOTIFY_REGISTER_RET_OK == reg_ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_RSG_SUCCESS);
    }
    else
    {  
        MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_BTDATA_RSG_FAIL);
    }
	
#ifdef __GPS_EPO_DOWNLOAD__
	mmi_frm_set_single_protocol_event_handler(MSG_ID_EPO_BT_DOWNLOAD_REQ, (PsIntFuncPtr)srv_btpr_epo_notify_by_gps);
#else
	mmi_frm_set_single_protocol_event_handler(MSG_ID_GPSADAPTOR_APK_DOWNLOAD_REQ, (PsIntFuncPtr)srv_btpr_epo_notify_by_gps);
#endif
}

static mmi_ret srv_btpr_epo_del_epo_file_rsp(mmi_event_struct *param)
{
    MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_EPO_DEL_SUCCESS);
    return MMI_RET_OK;
}

static mmi_ret srv_btpr_epo_cpoy_epo_file_rsp(mmi_event_struct *info)
{
    switch(info->evt_id)
    {
        case EVT_ID_SRV_FMGR_ASYNC_DONE:
        {
			MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_EPO_CPY_SUCCESS,
				g_recv_epo_data.recv_epo_file, g_recv_epo_data.recv_md5_data);

			if(g_recv_epo_data.recv_epo_file == 1 )//&& (srv_fmgr_fs_path_exist((WCHAR *)BTPR_RECV_EPOFILE_CPOY_PATH) >= 0))
			{
				g_recv_epo_data.recv_epo_file = 2;
				
				if((g_recv_epo_data.recv_epo_file == 2) && (g_recv_epo_data.recv_md5_data == 1))
				{
					srv_btpr_epo_notify_gps_epodown_success(g_recv_epo_data.md5_buf);
					srv_fmgr_async_delete(g_recv_epo_data.src_file_path, 0, srv_btpr_epo_del_epo_file_rsp, NULL);
					memset(&g_recv_epo_data, 0, sizeof(mmi_btprsrv_epo_info_struct));
				}
			}
        }
        default:
            break;
    }
    return MMI_RET_OK;
}

static void srv_btpr_epo_gps_request_epo_download(kal_uint8* file_name)
{
	CHAR data[80] = {0};
	CHAR cmd[32] = {0};
	if (file_name != NULL)
    {
        sprintf(cmd, "ED_%s", file_name);
    }
    else
    {
        sprintf(cmd, "%s", BT_PUSH_RECV_EPO_DOWNLOAD_CMD);
    }

	sprintf(data, "%s %s %d %d %s", 
		          BT_PUSH_EPO_DOWN_SENDER,
		          BT_PUSH_EPO_DOWN_RECEIVER,
		          0,
		          strlen(cmd),
		          cmd);
	
	srv_bt_push_recv_send_excd_cmd(data);
	
	MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_GPS_UPDATE_REQUEST);
}



#ifdef __GPS_EPO_DOWNLOAD__

void srv_btpr_epo_notify_gps_btconn_status_int(kal_int8 connected)
{
	// send msg to gps the bt connect status, gps check epo file whether vaild
	MYQUEUE message;
	mmi_btprsrv_epo_struct* gps_btconn_status;

	MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_NOTIY_BT_STATUS);
	memset(&g_recv_epo_data, 0, sizeof(mmi_btprsrv_epo_info_struct));

	message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_GPS;
    if (connected)
    {
        message.oslMsgId = MSG_ID_EPODOWNLOAD_BT_CONNECT_IND;
    }
    else
    {
        message.oslMsgId = MSG_ID_EPODOWNLOAD_BT_DISCONNECT_IND;
    }
    gps_btconn_status = (mmi_btprsrv_epo_struct*) mmi_construct_msg_local_para(sizeof(mmi_btprsrv_epo_struct));

	message.oslDataPtr = (oslParaType*) gps_btconn_status;
    message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&message);
}

void srv_btpr_epo_notify_gps_btconn_status(kal_int8 connected)
{
	if(1 == connected && MMI_TRUE == srv_bt_noti_check_sync_connection_ext_by_source(&g_bt_push_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP))
    {
		srv_btpr_epo_notify_gps_btconn_status_int(connected);
    }
    else
    {
		srv_btpr_epo_notify_gps_btconn_status_int(connected);
    }
}

static void srv_btpr_epo_notify_gps_epodown_success(kal_uint8* md5_data)
{
	// send msg to gps the bt connect status, gps check epo file whether vaild
	MYQUEUE message;
	apk_gpsadaptor_download_finish_struct* gps_epodown_success;

	MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_EPO_DOWNLOAD_SUCCESS);

	message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_GPS;
    message.oslMsgId = MSG_ID_BT_EPO_DOWNLOAD_FINISH;
    gps_epodown_success = (apk_gpsadaptor_download_finish_struct*) mmi_construct_msg_local_para(sizeof(apk_gpsadaptor_download_finish_struct));
	memcpy(gps_epodown_success->md5, md5_data, sizeof(gps_epodown_success->md5));

	message.oslDataPtr = (oslParaType*) gps_epodown_success;
    message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&message);
}

static void srv_btpr_epo_notify_by_gps(void *arg)
{
    epo_download_req_struct* req = (epo_download_req_struct*) arg;
     srv_btpr_epo_gps_request_epo_download(req->epo_file_name);
}
#else

void srv_btpr_epo_notify_gps_btconn_status(kal_int8 connected)
{
	if(MMI_TRUE == srv_bt_noti_check_sync_connection_ext_by_source(&g_bt_push_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP))
		srv_btpr_epo_notify_gps_btconn_status_int();
}


void srv_btpr_epo_notify_gps_btconn_status_int(void)
{
	// send msg to gps the bt connect status, gps check epo file whether vaild
	MYQUEUE message;
	mmi_btprsrv_epo_struct* gps_btconn_status;

	MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_NOTIY_BT_STATUS);
	memset(&g_recv_epo_data, 0, sizeof(mmi_btprsrv_epo_info_struct));

	message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_GPSADAPTOR;
    message.oslMsgId = MSG_ID_APK_GPSADAPTOR_BT_CONNECT_IND;
    gps_btconn_status = (mmi_btprsrv_epo_struct*) mmi_construct_msg_local_para(sizeof(mmi_btprsrv_epo_struct));

	message.oslDataPtr = (oslParaType*) gps_btconn_status;
    message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&message);
}

static void srv_btpr_epo_notify_gps_epodown_success(kal_uint8* md5_data)
{
	// send msg to gps the bt connect status, gps check epo file whether vaild
	MYQUEUE message;
	apk_gpsadaptor_download_finish_struct* gps_epodown_success;

	MMI_TRACE(MMI_CONN_TRC_G4_EPO, TRC_SRV_BTEPODOWNSRV_EPO_DOWNLOAD_SUCCESS);

	message.oslSrcId = MOD_MMI;
    message.oslDestId = MOD_GPSADAPTOR;
    message.oslMsgId = MSG_ID_APK_GPSADAPTOR_DOWNLOAD_FINISH;
    gps_epodown_success = (apk_gpsadaptor_download_finish_struct*) mmi_construct_msg_local_para(sizeof(apk_gpsadaptor_download_finish_struct));
	memcpy(gps_epodown_success->md5, md5_data, sizeof(gps_epodown_success->md5));

	message.oslDataPtr = (oslParaType*) gps_epodown_success;
    message.oslPeerBuffPtr = NULL;
    mmi_msg_send_ext_queue(&message);
}

static void srv_btpr_epo_notify_by_gps(void *arg)
{
     srv_btpr_epo_gps_request_epo_download(NULL);
}

#endif
 
#endif // __GPS_ADAPTOR_SUPPORT__


