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
 * FOTARecvSrvMain.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BT push recv srv entry.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_NOTI_SRV__
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "BTNotiSrvGprot.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "BTPushRecvSrv.h"
#include "verno.h"
#include "CharBatSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__))
#include "FUDiffNetSrv.h"
#endif
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
#include "custom_scatstruct.h"
#include "custom_ubin_irt.h"
#include "FUnetSrv.h"
#endif

#if defined(__MMI_USB_FIRMWARE_UPDATE__)
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"
#endif

#ifdef __GPS_ADAPTOR_SUPPORT__
#include "BTPRSrvEPODown.h"
#endif

#define DIFF_FOTA 0x00000001
#define UBIN_FOTA 0x00000010
#define USB_FOTA  0x00000100
#define FBIN_FOTA 0x00001000
#define ROCK_FOTA 0x00010000
static U32 g_fota_type = 0;

#define CHIP_RID_LEN 16 
static CHAR g_chip_rid[2* CHIP_RID_LEN + 1] = {0};
srv_bt_cm_bt_addr g_bt_push_addr;

#if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
#define FBIN_MODE "test"
#define FBIN_DOMAIN "http://dl.test.com"
#endif

//pRid is hexadecimal value, buf_len is length of pRid which denote as bit numbers
extern kal_bool SST_Get_ChipRID(kal_char *pRid, kal_int32 buf_len);

static mmi_ret srv_bt_push_recv_status_change_evt_hdlr(mmi_event_struct *evt);
static mmi_ret srv_bt_notification_event_hdlr(mmi_event_struct *evt);
static void srv_bt_push_get_chip_rid();
static void srv_bt_push_ext_cmd_cb(void *data);
static void srv_bt_push_fota_type_init(void);
static void srv_bt_push_recv_reply_customer_info(srv_bt_push_ver_type_enum type, CHAR* sender, CHAR* receiver);

void srv_bt_push_recv_init(void)
{
    srv_bt_notify_register_result_enum reg_ret;

    //reg cb to handle BT status change
    #if defined(__IOT__)
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_SYNC_DEV, srv_bt_notification_event_hdlr, NULL);
    #endif
    mmi_frm_cb_reg_event(EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE, srv_bt_push_recv_status_change_evt_hdlr, NULL);
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__))
    srv_btpr_diff_fota_init();
#endif
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
    srv_btpr_ubin_fota_init();
#endif
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
    srv_btpr_fbin_fota_init();
#endif
    srv_bt_push_get_chip_rid();

	#ifdef __GPS_ADAPTOR_SUPPORT__
	srv_btpr_epo_down_init();
	#endif

    srv_bt_push_fota_type_init();

    //register get fota type command hdlr
    reg_ret = srv_bt_noti_register_callback_ext(
                                               BT_PUSH_EXTEND_CMD, 
                                               BT_PUSH_GET_FOTA_TYPE_SENDER, 
                                               srv_bt_push_ext_cmd_cb);
    if (SRV_BT_NOTIFY_REGISTER_RET_OK == reg_ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_GET_FOTA_TYPE_HDLR_SUCCESS);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_GET_FOTA_TYPE_HDLR_FAIL);
    }

    //register get version info command hdlr
    reg_ret = srv_bt_noti_register_callback_ext(
                                               BT_PUSH_EXTEND_CMD, 
                                               BT_PUSH_GET_VERSION_SENDER, 
                                               srv_bt_push_ext_cmd_cb);
    if (SRV_BT_NOTIFY_REGISTER_RET_OK == reg_ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_GET_VERSION_HDLR_SUCCESS);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_GET_VERSION_HDLR_FAIL);
    }

	//register customer command hdlr
    reg_ret = srv_bt_noti_register_callback_ext(
                                               BT_PUSH_EXTEND_CMD, 
                                               BT_PUSH_CUSTOMER_COMMAND_SENDER, 
                                               srv_bt_push_ext_cmd_cb);
    if (SRV_BT_NOTIFY_REGISTER_RET_OK == reg_ret)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] register customer command hdlr success");
    }
    else
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] register customer command hdlr fail");
    }

}

static void srv_bt_push_fota_type_init(void)
{
#if defined(__FUDIFFNET_ENABLE__) && !defined(__ROCK_FOTA_SUPPORT__)
    g_fota_type += DIFF_FOTA;
#endif

#if defined(__FUDIFFNET_ENABLE__) && defined(__ROCK_FOTA_SUPPORT__)
    g_fota_type += ROCK_FOTA;
#endif

#if defined(__UPDATE_BINARY_FILE__)
    g_fota_type += UBIN_FOTA;
#endif

#if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
    g_fota_type += FBIN_FOTA;
#endif

#if defined(__MMI_USB_FIRMWARE_UPDATE__)
    g_fota_type += USB_FOTA;
#endif

    return;
}

static void srv_bt_push_ext_cmd_cb(void *data)
{
    srv_bt_noti_callback_struct *p_data = (srv_bt_noti_callback_struct*)data;

    if (p_data == NULL)
    {
        return;
    }

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] receive data type = %d, sender_id = %s", 
              p_data->data_type, p_data->sender_id);
    //record current bt addr of remote devie
    g_bt_push_addr.lap = p_data->bt_addr.lap;
    g_bt_push_addr.uap = p_data->bt_addr.uap;
    g_bt_push_addr.nap = p_data->bt_addr.nap;

    if (SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER == p_data->data_type)
    {
        if (!strcmp(p_data->sender_id, BT_PUSH_GET_VERSION_SENDER) &&
                 !strcmp(p_data->receiver_id, BT_PUSH_GET_VERSION_RECEIVER))
        {
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] receive version cmd = %s", p_data->data.buffer.data);

        #if defined(__FUDIFFNET_ENABLE__)
            #if defined(__ROCK_FOTA_SUPPORT__)
            //rock fota temp getversion
            if (!strncmp(p_data->data.buffer.data, "getRockVersion", p_data->data.buffer.len))
            {
            	  MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] Rock FOTA get version");
                srv_bt_push_recv_reply_version_info(SRV_BT_PUSH_DIFF_VER); // for Diff FOTA get version
            }
            else
            #else // __ROCK_FOTA_SUPPORT__
            if (!strncmp(p_data->data.buffer.data, "getDiffVersion", p_data->data.buffer.len))
            {
                srv_bt_push_recv_reply_version_info(SRV_BT_PUSH_DIFF_VER); // for Diff FOTA get version
            }
            else 
            #endif // __ROCK_FOTA_SUPPORT__
	#endif
        #if defined(__UPDATE_BINARY_FILE__)
            if (!strncmp(p_data->data.buffer.data, "getUBINVersion", p_data->data.buffer.len))
            {
                srv_bt_push_recv_reply_version_info(SRV_BT_PUSH_UBIN_VER); // for UBIN FOTA get version
            }
            else
	#endif
        #if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
            if (!strncmp(p_data->data.buffer.data, "getFBINVersion", p_data->data.buffer.len))
            {
                srv_bt_push_recv_reply_version_info(SRV_BT_PUSH_FBIN_VER); // for Full IMAGE FOTA get version
            }
            else
	#endif
        #if defined(__MMI_USB_FIRMWARE_UPDATE__)
            if (!strncmp(p_data->data.buffer.data, "getUSBVersion", p_data->data.buffer.len))
            {
                srv_bt_push_recv_reply_version_info(SRV_BT_PUSH_USB_VER); // for USB FOTA get version
            }
            else
        #endif
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] get version wrong string = %s", p_data->data.buffer.data);
                srv_bt_push_recv_reply_int_value(BT_PUSH_GET_VERSION_SENDER, BT_PUSH_GET_VERSION_RECEIVER, BT_PUSH_RECV_GET_VERSION_WRONG_STRING);
            }
        }
        else if (!strcmp(p_data->sender_id, BT_PUSH_GET_FOTA_TYPE_SENDER) &&
                 !strcmp(p_data->receiver_id, BT_PUSH_GET_FOTA_TYPE_RECEIVER))
        {
            if (!strncmp(p_data->data.buffer.data, "getType", p_data->data.buffer.len))
            {
                CHAR ext_cmd[50] = {0};
                kal_sprintf(ext_cmd, "%s %s %d %d %08x", 
                     BT_PUSH_GET_FOTA_TYPE_SENDER, 
                     BT_PUSH_GET_FOTA_TYPE_RECEIVER, 
                     0, 
                     8, 
                     g_fota_type);

                srv_bt_push_recv_send_excd_cmd(ext_cmd);
            }
        }
		else if (!strcmp(p_data->sender_id, BT_PUSH_CUSTOMER_COMMAND_SENDER) &&
                 !strcmp(p_data->receiver_id, BT_PUSH_CUSTOMER_COMMAND_RECEIVER))
        {
            if (!strncmp(p_data->data.buffer.data, "getCustomerInfo", p_data->data.buffer.len))
            {
                srv_bt_push_recv_reply_customer_info(SRV_BT_PUSH_CUSTOMER_INFO, BT_PUSH_CUSTOMER_COMMAND_SENDER, BT_PUSH_CUSTOMER_COMMAND_RECEIVER);
            }
			      else
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv]get customer info wrong, cmd=%s", p_data->data.buffer.data);
                srv_bt_push_recv_reply_int_value(BT_PUSH_CUSTOMER_COMMAND_SENDER, BT_PUSH_CUSTOMER_COMMAND_RECEIVER, BT_PUSH_RECV_GET_CUSTOMER_INFO_WRONG);
            }
        }
    }
    else if (SRV_BT_NOTI_MRE_DATA_TYPE_FILE == p_data->data_type)
    {
    }
    return;
}

static mmi_ret srv_bt_push_recv_status_change_evt_hdlr(mmi_event_struct *evt)
{
    srv_bt_noti_connect_status_change_notify_struct *bt_noti_evt = (srv_bt_noti_connect_status_change_notify_struct*)evt;
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] BT statu change evt_id:%d, is_connect:%d", evt->evt_id,bt_noti_evt->is_connected);
    if (evt->evt_id == EVT_ID_SRV_BT_NOTI_CONNECTION_STATUS_CHANGE)
    {
        if (bt_noti_evt->is_connected == MMI_TRUE)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_BT_CONNECT_SUCCESS);
            g_bt_push_addr = bt_noti_evt->bt_addr;
        #if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__))
            srv_btpr_diff_fota_check_result();
        #endif
        #if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
            srv_btpr_ubin_fota_check_result();
        #endif
        #if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
            srv_btpr_fbin_fota_check_result();
        #endif

			#ifdef __GPS_ADAPTOR_SUPPORT__
			srv_btpr_epo_notify_gps_btconn_status(1);
			#endif
        }
        else if(memcmp(&g_bt_push_addr, &(bt_noti_evt->bt_addr), sizeof(srv_bt_cm_bt_addr)) == 0)// BT disconnect
        {
        #if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__))
            srv_btpr_diff_fota_clear_status();
		#endif
        #if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
			srv_btpr_ubin_fota_clear_status();
        #endif
        #if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
            srv_btpr_fbin_fota_clear_status();
        #endif
        #ifdef __GPS_ADAPTOR_SUPPORT__
            srv_btpr_epo_notify_gps_btconn_status(0);
        #endif
        }
    }

    return MMI_RET_OK;
}

void srv_bt_push_recv_send_excd_cmd(CHAR* data)
{
    MMI_BOOL ret = MMI_FALSE;

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] send cmd, bt_addr:%d.%d.%d, data: %s", 
                       g_bt_push_addr.nap, g_bt_push_addr.uap, g_bt_push_addr.lap, data);
    ret = srv_bt_noti_send_cmd_ext(&g_bt_push_addr, "EXCD", data, strlen(data));
    if (MMI_TRUE == ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_SEND_CMD_SUCCESS);
    }
    else
    {
       MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_SEND_CMD_FAIL);
    }
    return;
}

void srv_bt_push_recv_reply_int_value(CHAR* sender, CHAR* receiver, S32 reply_code)
{
    CHAR data[50] = {0};
    CHAR error[5] = {0};

    if (reply_code >= 0)
    {
        kal_sprintf(error, "%d", reply_code);
        kal_sprintf(data, "%s %s %d %d %s", 
                     sender, 
                     receiver, 
                     0, 
                     strlen(error), 
                     error);
    }
    else
    {
        reply_code = abs(reply_code);
        kal_sprintf(error, "%d", reply_code);
        kal_sprintf(data, "%s %s %d %d -%s", 
                     sender, 
                     receiver, 
                     0, 
                     strlen(error), 
                     error);
    }

    srv_bt_push_recv_send_excd_cmd(data);
}

//extern const kal_uint32 g_SST_VERSION_base;
//extern BL_Info_Wrapper_st g_pass_info;
extern kal_uint32 INT_GetBootloaderFlag(void);
extern kal_bool INT_GetRID(kal_char *pRid, kal_int32 buf_len);

static void srv_bt_push_get_chip_rid()
{
#ifdef __MTK_TARGET__
    S32 i;
    CHAR tmp[2 * CHIP_RID_LEN + 1]={0};
    CHAR *pIndex = tmp;
	kal_uint32 boot_flag = INT_GetBootloaderFlag();
	
	INT_GetRID(g_chip_rid, (CHIP_RID_LEN * 8));

	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] me_id0=%0x", g_chip_rid[0]);
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] me_id0=%0x", g_chip_rid[1]);
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] me_id0=%0x", g_chip_rid[2]);
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] me_id0=%0x", g_chip_rid[3]);
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] me_id0=%0x", g_chip_rid[4]);
	
	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] boot_flag1=%0x", boot_flag);

    // get unique device id
    if (SST_Get_ChipRID(g_chip_rid, (CHIP_RID_LEN * 8)) == KAL_TRUE)
    {
        //convert 16 hexadecimal value to string        
        for (i = 0; i < CHIP_RID_LEN; i++)
        {
            sprintf(pIndex, "%02X", g_chip_rid[i]);
            pIndex += 2;
            //MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] get chip rid = %02x", g_chip_rid[i]);
        }
        strncpy(g_chip_rid, tmp, 2 * CHIP_RID_LEN + 1);
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] get chip rid = %s", g_chip_rid);
    }
    else
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] get chip rid fail");
    }
#else // __MTK_TARGET__
    strcpy(g_chip_rid, "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF");
#endif //__MTK_TARGET__

    return;
}

static CHAR* srv_bt_push_recv_get_version_data(srv_bt_push_ver_type_enum type)
{
    CHAR *pIndex = NULL;
    CHAR rel_date[50+1] = {0};
    CHAR battery[10] = {0};
    CHAR *ver_ptr = NULL;
    U16  ver_len;
#if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
    unsigned int* p_symbol_addr = NULL;
    kal_char* p_ubin_build_time = NULL;
#endif

    //get release date info
    strcpy(rel_date, BUILD_DATE_TIME_STR);
    pIndex = strchr(rel_date, ' ');
    memset(pIndex, 0, strlen(pIndex));

    //check battery is enough before FOTA, now level_1 is set as threshold, can be finetune.
    if (srv_charbat_get_battery_level() <= SRV_CHARBAT_BATTERY_LEVEL_1)
    {
        strcpy(battery, "low");
    }
    else
    {
        strcpy(battery, "normal");
    }

    switch(type)
    {
    #if defined(__FUDIFFNET_ENABLE__)
        case SRV_BT_PUSH_DIFF_VER:
        {
    #ifdef __ROCK_FOTA_SUPPORT__
            srv_fudiffnet_rock_fota_pre_info_struct fota_info;
		        srv_fudiffnet_get_rock_fota_pre_info(&fota_info);

            ver_len = strlen(VERNO_STR) + sizeof(rel_date) + sizeof(fota_info) + sizeof(g_chip_rid) +
                       sizeof(battery) + 100; //100 for fomart string
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info length = %d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }

            //data format: "verno=;releaseDate=;platform=;model=;dev_id=;battery="
            kal_sprintf(ver_ptr, "verno=%s;releaseDate=%s;platform=%s;model={%s////%s};dev_id=%s;battery=%s", 
                       VERNO_STR, rel_date, PLATFORM, fota_info.brand, fota_info.model, g_chip_rid, battery);
    #else /* __ROCK_FOTA_SUPPORT__*/
            srv_fudiffnet_fota_pre_info_swmc_struct fota_info;
            srv_fudiffnet_get_swmc_fota_pre_info(&fota_info);

            ver_len = strlen(VERNO_STR) + sizeof(rel_date) + sizeof(fota_info) + sizeof(g_chip_rid) +
                       sizeof(battery) + 100; //100 for fomart string
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info length = %d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }

            //data format: "verno=;releaseDate=;platform=;brand=;model=;domain=;pin_code=;dev_id=;battery="
            kal_sprintf(ver_ptr, "verno=%s;releaseDate=%s;platform=%s;brand=%s;model=%s;domain=%s;pin_code=%s;dev_id=%s;battery=%s", 
                       VERNO_STR, rel_date, PLATFORM, fota_info.brand, fota_info.model, fota_info.domain, fota_info.pin_code, g_chip_rid, battery);
    #endif /* __ROCK_FOTA_SUPPORT__*/
            break;
        }
    #endif
    #if defined(__UPDATE_BINARY_FILE__)
        case SRV_BT_PUSH_UBIN_VER:
        {
            srv_funet_fota_pre_info_struct fota_info;
            srv_funet_get_fota_pre_info(&fota_info);

            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "Call ubin_build_date_time() Start");
	    p_symbol_addr = (unsigned int*)(custom_get_UPDATE_ROM_entry() 
							+ UBIN_SYMBOL_UBIN_BUILD_DATE_TIME * sizeof(void *));
	    p_ubin_build_time = ((kal_char* (*)(void))(*p_symbol_addr))();
	    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "Call ubin_build_date_time() END");
            
            ver_len = strlen(VERNO_STR) + strlen(p_ubin_build_time) + sizeof(rel_date) + strlen(PLATFORM) +
                       sizeof(fota_info) + sizeof(g_chip_rid) + sizeof(battery) + 100; //100 for fomart string
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info length = %d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }

            //data format: "verno=;releaseDate=;platform=;model=;domian=;dev_id=;battery="
            kal_sprintf(ver_ptr, "verno=%s_UBIN_%s;releaseDate=%s;platform=%s;model=%s;domain=%s;dev_id=%s;battery=%s;dl_key=%s", 
                       VERNO_STR, p_ubin_build_time, rel_date, PLATFORM, fota_info.model, fota_info.domain, g_chip_rid, battery, fota_info.dl_key);
            break;
        }
    #endif
    #if (defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
        case SRV_BT_PUSH_FBIN_VER:
        {

            ver_len = strlen(VERNO_STR) + sizeof(rel_date) + strlen(PLATFORM) + strlen(FBIN_MODE) +
                       strlen(FBIN_DOMAIN) + sizeof(g_chip_rid) + sizeof(battery) + 100; //100 for fomart string
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info length = %d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }

            //data format: "verno=;releaseDate=;platform=;model=;domian=;dev_id=;battery="
            kal_sprintf(ver_ptr, "verno=%s;releaseDate=%s;platform=%s;model=%s;domain=%s;dev_id=%s;battery=%s", 
                       VERNO_STR, rel_date, PLATFORM, FBIN_MODE, FBIN_DOMAIN, g_chip_rid, battery);
            break;
        }
    #endif
    #if defined(__MMI_USB_FIRMWARE_UPDATE__)
        case SRV_BT_PUSH_USB_VER:
        {
            nvram_ef_usb_fota_info_struct fota_info;
            ReadRecordSlim(
                NVRAM_EF_USB_FOTA_INFO_LID, 
                1, 
                &fota_info, 
                NVRAM_EF_USB_FOTA_INFO_SIZE);
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] domain=%s", fota_info.domain);
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] model=%s", fota_info.model);
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] dl_key=%s", fota_info.dl_key);

            ver_len = strlen(VERNO_STR) + sizeof(rel_date) + strlen(PLATFORM) + sizeof(fota_info) + 
                       sizeof(g_chip_rid) + sizeof(battery) + 100; //100 for fomart string
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info length = %d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }

            //data format: "verno=;releaseDate=;platform=;model=;domain=;dev_id=;battery="
            kal_sprintf(ver_ptr, "verno=%s;releaseDate=%s;platform=%s;model=%s;domain=%s;dev_id=%s;battery=%s;dl_key=%s", 
                   VERNO_STR, rel_date, PLATFORM, fota_info.model, fota_info.domain, g_chip_rid, battery, fota_info.dl_key);
            break;
        }
    #endif
	    case SRV_BT_PUSH_CUSTOMER_INFO:
        {
            CHAR sample[]= "customerInfo=sample";

            ver_len = sizeof(sample);
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] customer info len=%d", ver_len);

            ver_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(ver_len);
            if (NULL == ver_ptr)
            {
                MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_get_version_data() alloc mem fail");
                return ver_ptr;
            }
            else
            {
                memset(ver_ptr, 0, ver_len);
            }
			//Data format in ver_ptr will deceide by customize, should match the parse format on SP application
            kal_sprintf(ver_ptr, "%s", sample);
			
            break;
        }
        default:
        {
            MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] no such version command");
            break;
        }
    }

    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] battery is: %s", battery);
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] version info data: %s", ver_ptr);

    return ver_ptr;
}

static void srv_bt_push_recv_reply_customer_info(srv_bt_push_ver_type_enum type, CHAR* sender, CHAR* receiver)
{
    CHAR* cmd_ptr = NULL;
    CHAR* ver_ptr = NULL;
    U16   cmd_len;

	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_reply_customer_info recv customer cmd");
    ver_ptr = srv_bt_push_recv_get_version_data(type);
    if (NULL == ver_ptr)
    {
        return;
    }

    cmd_len = strlen(ver_ptr) + 50;
    cmd_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(cmd_len);
    if (NULL == cmd_ptr)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_reply_customer_info() alloc mem fail");
        mmi_frm_asm_free_anonymous(ver_ptr);
        return;
    }
    memset(cmd_ptr, 0 , cmd_len);
    kal_sprintf(cmd_ptr, "%s %s %d %d %s", 
                     sender, 
                     receiver, 
                     0, 
                     strlen(ver_ptr), 
                     ver_ptr);
    mmi_frm_asm_free_anonymous(ver_ptr);

    //send excd cmd to remote device
    srv_bt_push_recv_send_excd_cmd(cmd_ptr);
    mmi_frm_asm_free_anonymous(cmd_ptr);
    
    return;
}

void srv_bt_push_recv_reply_version_info(srv_bt_push_ver_type_enum type)
{
    CHAR* cmd_ptr = NULL;
    CHAR* ver_ptr = NULL;
    U16   cmd_len;

    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_RECEIVE_GET_VERSION_CMD);
    ver_ptr = srv_bt_push_recv_get_version_data(type);
    if (NULL == ver_ptr)
    {
        return;
    }

    cmd_len = strlen(ver_ptr) + 50;
    cmd_ptr = (CHAR*)mmi_frm_asm_alloc_anonymous(cmd_len);
    if (NULL == cmd_ptr)
    {
        MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] srv_bt_push_recv_reply_version_info() alloc mem fail");
        mmi_frm_asm_free_anonymous(ver_ptr);
        return;
    }
    memset(cmd_ptr, 0 , cmd_len);
    kal_sprintf(cmd_ptr, "%s %s %d %d %s", 
                     BT_PUSH_GET_VERSION_SENDER, 
                     BT_PUSH_GET_VERSION_RECEIVER, 
                     0, 
                     strlen(ver_ptr), 
                     ver_ptr);
    mmi_frm_asm_free_anonymous(ver_ptr);

    //send excd cmd to remote device
    srv_bt_push_recv_send_excd_cmd(cmd_ptr);
    mmi_frm_asm_free_anonymous(cmd_ptr);
    
    return;
}

#if defined(__IOT__)
mmi_ret srv_bt_notification_event_hdlr(mmi_event_struct *evt)
{
    srv_bt_noti_sync_event_struct* sync_time = (srv_bt_noti_sync_event_struct*)evt;
    kal_prompt_trace(MOD_MMI_CONN_APP, "srv_bt_notification_event_hdlr");
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_SYNC_DEV:
            sync_time->call_back(&(sync_time->bt_addr), sync_time->time, sync_time->time_zone, MMI_FALSE);
            break;
    }
}
#endif

#endif //__MMI_BT_NOTI_SRV__

