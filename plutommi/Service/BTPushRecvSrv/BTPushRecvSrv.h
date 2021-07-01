/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * FOTARecvSrv.h
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for FOTA receive srv.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/
#ifndef __BT_PUSH_RECV_SRV__
#define __BT_PUSH_RECV_SRV__

#include "MMI_features.h"

#ifdef __MMI_BT_NOTI_SRV__
#include "BTNotiSrvGprot.h"

#define BT_PUSH_EXTEND_CMD              "EXCD"

/* for extend command */
#define BT_PUSH_DIFF_PACK_SENDER        "fota_dpack"
#define BT_PUSH_DIFF_PACK_RECEIVER      "fota_dpack"
#define BT_PUSH_ROCK_FOTA_SENDER        "fota_rock"
#define BT_PUSH_ROCK_FOTA_RECEIVER      "fota_rock"
#define BT_PUSH_UPDATE_BIN_SENDER       "fota_ubin"
#define BT_PUSH_UPDATE_BIN_RECEIVER     "fota_ubin"
#define BT_PUSH_FULL_BIN_SENDER         "fota_fbin"
#define BT_PUSH_FULL_BIN_RECEIVER       "fota_fbin"
#define BT_PUSH_GET_VERSION_SENDER      "fota_bt_ver"
#define BT_PUSH_GET_VERSION_RECEIVER    "fota_bt_ver"
#define BT_PUSH_GET_FOTA_TYPE_SENDER    "fota_type"       
#define BT_PUSH_GET_FOTA_TYPE_RECEIVER  "fota_type"         
#define BT_PUSH_CUSTOMER_COMMAND_SENDER   "fota_cust_cmd"
#define BT_PUSH_CUSTOMER_COMMAND_RECEIVER "fota_cust_cmd"

/* fota receive firmware data type */
#define BT_PUSH_RECV_FILE_DATA_BEGIN            0
#define BT_PUSH_RECV_FILE_DATA_PACK             1
#define BT_PUSH_RECV_FILE_DATA_END              2

//fota update code
#define BT_PUSH_RECV_FOTA_UPDATE_SUCCESS        3
#define BT_PUSH_RECV_DATA_COMMON_ERROR         -1
#define BT_PUSH_RECV_WRITE_FILE_FAIL           -2
#define BT_PUSH_RECV_FILE_DISK_NOT_ENOUGH      -3
#define BT_PUSH_RECV_TRANSFER_DATA_FAIL        -4
#define BT_PUSH_RECV_TRIGGER_UPDATE_FAIL       -5
#define BT_PUSH_RECV_FOTA_UPDATE_FAIL          -6
#define BT_PUSH_RECV_DEVICE_LOW_BATTERY        -7
#define BT_PUSH_RECV_GET_VERSION_WRONG_STRING  -8
#define BT_PUSH_RECV_GET_CUSTOMER_INFO_WRONG   -9

typedef enum
{
    SRV_BT_PUSH_DIFF_VER, 
    SRV_BT_PUSH_UBIN_VER,
    SRV_BT_PUSH_USB_VER, 
    SRV_BT_PUSH_FBIN_VER,
    SRV_BT_PUSH_CUSTOMER_INFO,
    SRV_BT_PUSH_VER_TYPE_TOTAL
}srv_bt_push_ver_type_enum;

extern srv_bt_cm_bt_addr g_bt_push_addr;

void srv_bt_push_recv_send_excd_cmd(CHAR* data);
void srv_bt_push_recv_reply_int_value(CHAR* sender, CHAR* receiver, S32 err_code);
void srv_bt_push_recv_reply_version_info(srv_bt_push_ver_type_enum type);

#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__))
void srv_btpr_diff_fota_init(void);
void srv_btpr_diff_fota_check_result(void);
void srv_btpr_diff_fota_clear_status(void);
#endif //defined(__MMI_BT_NOTI_SRV__) && defined(__FUDIFFNET_ENABLE__)

#if (defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__))
void srv_btpr_ubin_fota_init(void);
void srv_btpr_ubin_fota_check_result(void);
void srv_btpr_ubin_fota_clear_status(void);
#endif //defined(__MMI_BT_NOTI_SRV__) && defined(__UPDATE_BINARY_FILE__)

#if (defined(__MMI_BT_NOTI_SRV__) && defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
void srv_btpr_fbin_fota_init(void);
void srv_btpr_fbin_fota_check_result(void);
void srv_btpr_fbin_fota_clear_status(void);
#endif //(defined(__MMI_BT_NOTI_SRV__) && defined(__FUNET_ENABLE__) && !defined(__UPDATE_BINARY_FILE__))
extern void srv_bt_push_recv_init(void);

#endif //__MMI_BT_NOTI_SRV__
#endif //__BT_PUSH_RECV_SRV__
