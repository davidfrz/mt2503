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
/*****************************************************************************
 *
 * Filename:
 * ---------
 * BLEcmSrvProt.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the internal header file for BT CM
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef BLE_CM_SRV_PROT_H
#define BLE_CM_SRV_PROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "wgui_categories_list.h"
//#include "TimerEvents.h"
#include "nvram_common_defs.h"
#include "kal_general_types.h"
#include "mmi_res_range_def.h"
#include "DmSrvGprot.h"


//#include "bluetooth_bm_struct.h"
#include "BLESrvGprot.h"
/***************************************************************************** 
* Macro
*****************************************************************************/
#ifdef __MMI_BT_SUPPORT__
#define BLE_LINK_NUM   __BT_MAX_LE_LINK_NUM__
#define SRV_BLE_CM_MAX_DEVICE_LIST  (SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST+SRV_BLE_CM_MAX_CONNECTED_LIST)
#define SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST 10
#define SRV_BLE_CM_MAX_CONNECTED_LIST (BLE_LINK_NUM*2)
typedef struct
{
    srv_bt_cm_bt_addr bd_addr;
	MMI_BOOL conn_flag;
} srv_le_cm_auto_conn_dev_struct;

typedef struct
{
    U32 discovered_dev_num;
    /* to store the number of service before refreshing service list */
    U32 service_list_num;
	U32 connected_dev_num;
    //srv_ble_cm_state_enum state;
	srv_bt_cm_dev_state_struct dev_state;
    srv_bt_cm_dev_struct dev_list[SRV_BLE_CM_MAX_DEVICE_LIST];
    srv_bt_cm_dev_struct scan_list[SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST];/* discovery List */
	srv_bt_cm_dev_struct connected_list[SRV_BLE_CM_MAX_CONNECTED_LIST];/* connected List */

}srv_ble_cm_cntx_struct;
extern srv_ble_cm_cntx_struct g_srv_ble_cm_cntx;

U8 srv_ble_discovery_result_ind_hdler(void* msg);

U8 srv_ble_discovery_update_ind_hdler(void* msg);

U8 srv_ble_discovery_cnf_hdler(void* msg);

U8 srv_ble_cancel_discovery_cnf_hdler(void* msg);
void srv_ble_init_event_handler(void);
void srv_ble_cm_copy_n_utf8_chars(U8* dest, U16 size_of_dest, U8* src, U8 char_num);
MMI_BOOL srv_ble_cm_addr_is_null(srv_bt_cm_bt_addr* bd_addr);
void srv_ble_cm_del_connected_list(srv_le_cm_gatt_dev_info_struct *dev);
void srv_ble_cm_add_connected_list(srv_le_cm_gatt_dev_info_struct* dev_info);
U32 srv_ble_cm_get_dev_num(srv_ble_cm_dev_type_enum dev_type);
U8 srv_ble_cm_write_scanenable_mode_cnf(void* msg);
srv_bt_cm_bt_addr* srv_ble_cm_get_current_dev(void);
void srv_ble_cm_reset_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr);
MMI_BOOL srv_ble_cm_is_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr);
MMI_BOOL srv_ble_cm_set_auto_conn_dev(srv_bt_cm_bt_addr* dev_addr);


#endif /* __MMI_BT_SUPPORT__ */

#endif /* BLE_CM_SRV_PROT_H */
