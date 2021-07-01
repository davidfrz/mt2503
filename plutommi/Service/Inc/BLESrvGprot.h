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
 * BLESrvGprot.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is the header file for external module to use BT CM related apis
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
#ifndef BLE_SRV_GPROT_H
#define BLE_SRV_GPROT_H

#include "MMI_features.h"
#include "kal_public_api.h"
#include "kal_general_types.h"

#include "app_ltlcom.h"
#include "bluetooth_gap_struct.h"
#include "bluetooth_struct.h"
#include "MMIDataType.h"
#include "custom_btcm_config.h"
/* BLE CM current state enum */
typedef enum
{
    SRV_BLE_CM_STATE_IDLE,                              /* 0*/
    SRV_BLE_CM_STATE_INQUIRING,                         /* 1 */
    SRV_BLE_CM_STATE_INQUIR_RES_IND,                    /* 2 */
    SRV_BLE_CM_STATE_INQUIR_CANCELLING,                 /* 3 */  
    SRV_BLE_CM_STATE_CONNECTING,                        /* 4 */
    SRV_BLE_CM_STATE_DISCONNECTING,                     /* 5 */  
    SRV_BLE_CM_STATE_VISIBILITY_SETTING,                /* 6 */
    SRV_BLE_CM_STATE_TOTAL                              /* . */
} srv_ble_cm_state_enum;
/* BlE device type */
typedef enum
{
    SRV_BLE_CM_DISCOVERED_DEV,   /* discovered device */
    SRV_BLE_CM_CONNECTED_DEV,  /* connected device */
    SRV_BLE_CM_ALL_DEV,          /* all device */
    SRV_BLE_CM_DEV_TYPE_TOTAL
} srv_ble_cm_dev_type_enum;

/* visibility type enum */
typedef enum
{
	SRV_BLE_CM_VISIBILITY_P_ON_I_ON,	/* I:can be discovered by other bt device ;p: can be connect or bond by other bt device*/		
	SRV_BLE_CM_VISIBILITY_P_OFF_I_OFF,			
	SRV_BLE_CM_VISIBILITY_P_OFF_I_ON,			
	SRV_BLE_CM_VISIBILITY_P_ON_I_OFF,		
    SRV_BLE_CM_VISIBILITY_TOTAL  /* last enum for visibility type */
} srv_ble_cm_visibility_type;

typedef struct
{
    srv_bt_cm_bt_addr dev_addr;
	srv_ble_cm_state_enum state;

} srv_bt_cm_dev_state_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    srv_bt_cm_bt_addr* dev_addr;
	void* reserved;

} srv_le_cm_evt_connect_req_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    srv_bt_cm_bt_addr* dev_addr;
	void* reserved;

} srv_le_cm_evt_disconnect_struct;

typedef struct
{
    MMI_EVT_PARAM_HEADER                        /* Event parameter header */
    srv_bt_cm_bt_addr* dev_addr;
	kal_uint8 name[SRV_BT_CM_BD_FNAME_LEN];                        /* device name */
	MMI_BOOL is_ind;// is indication
	MMI_BOOL result;// success
	MMI_BOOL is_conn;// connect or disconnect
	void* reserved;

} srv_le_cm_evt_gatt_cnf_struct;

typedef struct
{
    srv_bt_cm_bt_addr* dev_addr;
	kal_uint8 name[SRV_BT_CM_BD_FNAME_LEN];                        /* device name */
	MMI_BOOL is_ind;// is indication
	MMI_BOOL result;// success
	MMI_BOOL is_conn;// connect or disconnect
	kal_uint8 reason;
} srv_le_cm_gatt_dev_info_struct;

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_search
 * DESCRIPTION 
 *  This function is to process inquiry request and invoke srv_bt_cm_discovery_req_hdler
 * PARAMETERS
 *  max_response        [IN]            max repsone number of device
 *  timeout             [IN]                inquiry timeout timer
 *  cod                 [IN]                  class of device
 *  name_discovery      [IN]            name discovery 
 *  user_data   [IN]            user data 
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_ble_cm_search(U8 max_response, U16 timeout, U32 cod, MMI_BOOL name_discovery);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_connected_dev_info
 * DESCRIPTION
 *  this function is to get the device infor in connected device by index
 * PARAMETERS
 *  U16: [IN] index
 *  
 * RETURNS
 * srv_bt_cm_dev_struct* : the device info
 ******************************************************************************/  
srv_bt_cm_dev_struct* srv_ble_cm_get_connected_dev_info(U16 index);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_connected_dev_num
 * DESCRIPTION
 *  this function is to get the number about connected device.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32 : number
 ******************************************************************************/  
U32 srv_ble_cm_get_connected_dev_num(void);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_searched_dev_info
 * DESCRIPTION
 *  this function is to get device info in scan list by index.
 * PARAMETERS
 *  U16: [IN] index
 *  
 * RETURNS
 * srv_bt_cm_dev_struct* : the device info
 ******************************************************************************/  
srv_bt_cm_dev_struct* srv_ble_cm_get_searched_dev_info(U16 index);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_searched_dev_num
 * DESCRIPTION
 *  this function is to get total number about scan_list.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32: number
 ******************************************************************************/   
U32 srv_ble_cm_get_searched_dev_num(void);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_get_maxed_linked_num
 * DESCRIPTION
 *  this function is to get maxed linked num,BLE_LINK_NUM is defined in le cm service.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 * U32: the maxed num.
 ******************************************************************************/
U32 srv_ble_cm_get_maxed_linked_num(void);

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_disconnect_req
 * DESCRIPTION
 *  this function is send event to app ,disconnect gatt.
 * PARAMETERS
 *  dev_addr:  [IN] address
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_disconnect_req(srv_bt_cm_bt_addr* dev_addr);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_connect_req
 * DESCRIPTION
 *  this function is send event to app ,connect gatt.
 * PARAMETERS
 *  dev_addr:  [IN] address
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_connect_req(srv_bt_cm_bt_addr* dev_addr);
/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_copy_addr
 * DESCRIPTION
 *  this function is to copy address.
 * PARAMETERS
 *  dest
 *  src
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_copy_addr(void *dest,void *src);
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_set_visibility
 * DESCRIPTION
 *  This function is to handle write scanenable mode request and send MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_REQ
 * PARAMETERS
 *  type       [IN]            visiblity type
 * RETURNS
 *  void
 *****************************************************************************/

S32 srv_ble_cm_set_visibility(srv_ble_cm_visibility_type type);
/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_search_abort
 * DESCRIPTION
 *  This function is to process inquiry cancel request
 * PARAMETERS
 *  void
 * RETURNS
 *  S32  : result
 *****************************************************************************/
S32 srv_ble_cm_search_abort(void);


/* DOM-NOT_FOR_SDK-BEGIN */

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_gatt_cnf
 * DESCRIPTION
 *  this function is send gatt connect/disconnect cnf.
 * PARAMETERS
 *  dev_info:  [IN] the device info.
 *  
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_gatt_cnf(srv_le_cm_gatt_dev_info_struct* dev_info);

/****************************************************************************** 
 * FUNCTION
 *  srv_ble_cm_update_conn_dev_name
 * DESCRIPTION
 *  this function is to update the le device name.
 * PARAMETERS
 *  dev_addr:  [IN] the device address.
 *  dev_name: [IN] the device name
 *
 * RETURNS
 * void
 ******************************************************************************/
void srv_ble_cm_update_conn_dev_name(kal_uint8 * dev_name, srv_bt_cm_bt_addr* dev_addr);
/* DOM-NOT_FOR_SDK-END */
#endif /* BLE_SRV_GPROT_H */
