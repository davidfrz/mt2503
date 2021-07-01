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
 * BTPRSrvFullBinFOTA.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for Full image FOTA.
 *
 * Author:
 * -------
 * 
 *
 *===========================================================
 ****************************************************************************/
#include "MMI_features.h"

#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
#include "Stdlib.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h" 
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "BTNotiSrvRecv.h"
#include "BTNotiSrvGprot.h"
#include "BTPushRecvSrv.h"
#include "BTPRSrvFullBinFOTA.h"
#include "ShutdownSrvGprot.h"
#include "FUnetSrv.h"
#include "Fs_gprot.h"
#include "CharBatSrvGprot.h"
#include "mmi_frm_timer_gprot.h"
#ifdef __IOT__
#include "mmi_rp_framework_bootup_def.h"
#else
#include "mmi_rp_app_bootup_def.h"
#endif

static FS_HANDLE g_fbin_fd = -1;
static WCHAR* g_fbin_path = NULL;
static S32 g_fbin_pack_num = -1; //for one firmware file,  package number splited from SP, watch should receive all  these packages.
static MMI_BOOL is_trigger_update = MMI_FALSE; // normal reboot is async process, in this process, can not receive other full bin again.

static void srv_btpr_fbin_fota_ext_cmd_cb(void *data);
#define FOTA_REBOOT_DELAY_DURATION   5000

void srv_btpr_fbin_fota_init(void)
{
    //register update full FOTA command hdlr
    srv_bt_notify_register_result_enum reg_ret = srv_bt_noti_register_callback_ext(
                                                                       BT_PUSH_EXTEND_CMD, 
                                                                       BT_PUSH_FULL_BIN_SENDER, 
                                                                       srv_btpr_fbin_fota_ext_cmd_cb);
    if (SRV_BT_NOTIFY_REGISTER_RET_OK == reg_ret)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_FBIN_HDLR_SUCCESS);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_REGISTER_FBIN_HDLR_FAIL);
    }

    g_fbin_path = srv_funet_get_fbin_path();
    return;
}

static void srv_btpr_fbin_fota_recv_fbin_data_start(srv_bt_noti_callback_struct *p_data)
{
    // if SP transfer data to watch, SP or its BT power off, watch may not receive end package, so data is not invalid
    if (g_fbin_fd >= FS_NO_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_FBIN_FD_ALREADY_EXIST);
        FS_Close(g_fbin_fd);
        g_fbin_fd = -1;
    }

    g_fbin_fd = FS_Open(g_fbin_path, FS_CREATE_ALWAYS | FS_READ_WRITE);
    if (g_fbin_fd < FS_NO_ERROR)
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_OPEN_FBIN_FILE_FAIL);
        srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_WRITE_FILE_FAIL);
    }
    else
    {
        g_fbin_pack_num = atoi(p_data->data.buffer.data);
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_NEED_RECEIVE_PACKAGES, g_fbin_pack_num);
    }
    return;
}

static mmi_ret srv_btpr_fbin_fota_del_fbin_cb(mmi_event_struct *param)
{
    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_DELETE_FBIN_FILE_SUCCESS);
    return 0;
}

static void srv_btpr_fbin_fota_recv_fbin_data_pack(srv_bt_noti_callback_struct *p_data)
{
    U32 nLen;
    S32 ret;

    if (g_fbin_fd >= FS_NO_ERROR)
    {
        ret = FS_Write(g_fbin_fd, p_data->data.buffer.data, p_data->data.buffer.len, &nLen);
        if (ret >= FS_NO_ERROR && p_data->data.buffer.len == nLen)
        {
            g_fbin_pack_num--; // to ensure data integrity which receiver from remote device
        }
        else if (FS_APP_QUOTA_FULL == ret)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_FOTA_FBIN_QUOTA_NOT_ENOUGH);
            FS_Close(g_fbin_fd);
            g_fbin_fd = -1;
            /*if write file fail, delete file, reply fail error to SP*/
            srv_fmgr_async_delete(g_fbin_path, 0, srv_btpr_fbin_fota_del_fbin_cb, NULL);
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_FILE_DISK_NOT_ENOUGH);
        }
        else if (p_data->data.buffer.len != nLen)
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_WRITE_FBIN_FILE_FAIL);
            FS_Close(g_fbin_fd);
            g_fbin_fd = -1;
            /*if write file fail, delete file, reply fail error to SP*/
            srv_fmgr_async_delete(g_fbin_path, 0, srv_btpr_fbin_fota_del_fbin_cb, NULL);
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_WRITE_FILE_FAIL);
        }
    }

    return;
}

static MMI_BOOL srv_btpr_fbin_fota_recv_fbin_data_end()
{
    if (g_fbin_fd >= FS_NO_ERROR)
    {
        FS_Close(g_fbin_fd);
        g_fbin_fd = -1;

        if (0 == g_fbin_pack_num)
        {
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_FILE_DATA_END);
            return MMI_TRUE;
        }
        else
        {
            MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_BT_TRANSFER_DATA_FAIL);
            srv_fmgr_async_delete(g_fbin_path, 0, srv_btpr_fbin_fota_del_fbin_cb, NULL);
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_TRANSFER_DATA_FAIL);
            return MMI_FALSE;
        }
    }
    else
    {
        return MMI_FALSE;
    }
}
static void srv_btpr_fbin_fota_funet_trigger()
{
    if (SRV_FUNET_FLAG_SUCCESS == srv_funet_trigger(g_fbin_path, SRV_FUNET_UPDATE_FULL))
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_TRIGGER_FUNET_SUCCESS);
        is_trigger_update = MMI_TRUE;
		StartTimer(FOTA_REBOOT_DELAY_TIMER, FOTA_REBOOT_DELAY_DURATION, srv_reboot_normal_start);
    }
    else
    {
        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_TRIGGER_FUNET_FAIL);
        srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_TRIGGER_UPDATE_FAIL);
    }
}

void srv_btpr_fbin_fota_recv_fbin(srv_bt_noti_callback_struct *data)
{
    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] receive full bin, data len = %d, err_code = %d", 
                                                               data->data.buffer.len, data->err_code);
    switch (data->err_code)
    {
        case BT_PUSH_RECV_FILE_DATA_BEGIN:
            {
                srv_btpr_fbin_fota_recv_fbin_data_start(data);
            }
            break;
        case BT_PUSH_RECV_FILE_DATA_PACK:
            {
                srv_btpr_fbin_fota_recv_fbin_data_pack(data);
            }
            break;
        case BT_PUSH_RECV_FILE_DATA_END:
            if (srv_btpr_fbin_fota_recv_fbin_data_end() == MMI_TRUE)
            {
                /*check battery is enough before trigger, now level_1 is set as threshold, can be finetune.
                   it must ensure that update process can not be break by power cut.
                */
                if (srv_charbat_get_battery_level() <= SRV_CHARBAT_BATTERY_LEVEL_1)
                {
                    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G4_FOTA, "[BTPushRecvSrv] low battery, can not trigger FOTA");
                    srv_fmgr_async_delete(g_fbin_path, 0, srv_btpr_fbin_fota_del_fbin_cb, NULL);
                    srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_DEVICE_LOW_BATTERY);
                }
                else
                {
                    srv_btpr_fbin_fota_funet_trigger();
                }

            }
            break;
        default:
            break;
    }

    return;
}

static void srv_btpr_fbin_fota_ext_cmd_cb(void *data)
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
        if (!strcmp(p_data->sender_id, BT_PUSH_FULL_BIN_SENDER) &&
            !strcmp(p_data->receiver_id, BT_PUSH_FULL_BIN_RECEIVER) &&
            is_trigger_update != MMI_TRUE)
        {
            srv_btpr_fbin_fota_recv_fbin(p_data);
        }
    }
    else if (SRV_BT_NOTI_MRE_DATA_TYPE_FILE == p_data->data_type)
    {
    }
    return;
}

void srv_btpr_fbin_fota_check_result(void)
{
    if (srv_fmgr_fs_path_exist(srv_funet_get_fbin_path()) >= 0)
    {
        srv_funet_update_ret_enum fota_ret;

        MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_FBIN_IS_EXIST);
        fota_ret = srv_funet_get_fota_result();
        if (SRV_FUNET_UPDATE_SUCCESS == fota_ret)
        {
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_FOTA_UPDATE_SUCCESS);
        }
        else if (SRV_FUNET_UPDATE_FAIL == fota_ret)
        {
            srv_bt_push_recv_reply_int_value(BT_PUSH_UPDATE_BIN_SENDER, BT_PUSH_UPDATE_BIN_RECEIVER, BT_PUSH_RECV_FOTA_UPDATE_FAIL);
        }
    }


    return;
}

void srv_btpr_fbin_fota_clear_status(void)
{
    MMI_TRACE(MMI_CONN_TRC_G4_FOTA, TRC_SRV_BTPUSHRECV_CLEAR_STATUS);
    // If BT disconnect when receiving data package, the fd should be close.
    if (g_fbin_fd >= FS_NO_ERROR)
    {
        FS_Close(g_fbin_fd);
        g_fbin_fd = -1;
    }

    return;
}

#endif //defined(__MMI_BT_NOTI_SRV__) && defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__)
