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
#ifndef VM_BTPDMS_SDK_H
#define VM_BTPDMS_SDK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "vmsys.h"


/****************************************************************************
 * Structure
 ****************************************************************************/
/* BT PDMS CONNECTION CALLBACK STATE */ 
typedef enum
{
    VM_BT_PDMS_CONNECTION_STATUS_DISCONNECTED = 0,
    VM_BT_PDMS_CONNECTION_STATUS_CONNECTING = 1,
    VM_BT_PDMS_CONNECTION_STATUS_CONNECTED = 2,
    VM_BT_PDMS_CONNECTION_STATUS_DISCONNECTING = 3,
    VM_BT_PDMS_CONNECTION_STATUS_MAX_NUM
} vm_bt_pdms_connection_status;

/* return result of bt pdms init and deinit */ 
typedef enum
{
    VM_BT_PDMS_STATUS_ERROR = -6,
    VM_BT_PDMS_STATUS_ERROR_OF_MEM = -5,
    VM_BT_PDMS_STATUS_ERROR_OF_RES = -4,
    VM_BT_PDMS_STATUS_ERROR_OF_REGISTER = -3,
    VM_BT_PDMS_STATUS_PENDING = -2, //current operation does not complete, need wait cnf callback
    VM_BT_PDMS_STATUS_FAILED = -1,  //current operation failed, need refer to error code
    VM_BT_PDMS_STATUS_SUCCESS = 0, //current operation complete and successful

} vm_bt_pdms_status; 
 
typedef enum
{
    VM_BT_PDMS_NO_ERROR = 0X00,
    VM_BT_PDMS_INVALID_HANDLE = 0X01,
    VM_BT_PDMS_READ_NOT_PERMITTED = 0X02,
    VM_BT_PDMS_WRITE_NOT_PERMITTED = 0X03,
    VM_BT_PDMS_INVALID_PDU = 0X04,
    VM_BT_PDMS_INSUFFICIENT_AUTHENTICATION = 0X05,
    VM_BT_PDMS_REQUEST_NOT_SUPPORTED = 0X06,
    VM_BT_PDMS_INVALID_OFFSET = 0X07,
    VM_BT_PDMS_INSUFFICIENT_AUTHORIZATION = 0X08,
    VM_BT_PDMS_PREPARE_QUEUE_FULL = 0X09,
    VM_BT_PDMS_ATTRIBUTE_NOT_FOUND = 0X0A,
    VM_BT_PDMS_ATTRIBUTE_NOT_LONG = 0X0B,
    VM_BT_PDMS_INSUFFICIENT_ENCRY_KEY_SIZE = 0X0C,
    VM_BT_PDMS_INVALID_ATTRIBUTE_VALUE_LEN = 0X0D,
    VM_BT_PDMS_UNLIKELY_ERROR = 0X0E,
    VM_BT_PDMS_INSUFFICIENT_ENCRYPTION = 0X0F,
    VM_BT_PDMS_UNSOPPORTED_GROUP_TYPE = 0X10,
    VM_BT_PDMS_INSUFFICIENT_RESOURCES = 0X11,
    VM_BT_PDMS_ERROR_CODE_TYPE_MAX_NUM        
} vm_bt_pdms_error_code_type;

/** BT-Findme callback defination. */
/* TO notify app current connection state, need be implement by app*/
/* Callback invoked in response to connect/disconnect for Monitor/Reporter*/
/* bdaddr is return remote bluetooth device address, format:XX:XX:XX:XX:XX:XX */
/* profile current connection state, see as: vm_bt_pdms_connection_status enum*/
typedef void (*vm_pdms_connection_state_callback)(VMINT8 *bdaddr, VMINT state);

/** Callback for start/stop alert level */
/* To notify app that remote device begin to request data */
/* bdaddr is return remote bluetooth device address, format:XX:XX:XX:XX:XX:XX */
/* please always return 0 */
typedef VMINT (*vm_pdms_data_to_read_callback)(VMINT8 *bd_addr, void* buf, VMUINT32 len);

/** Callback for remote side send read request */
/* please always return 0 */
typedef VMINT (*vm_pdms_read_data_request_callback)(VMINT8 *bd_addr, void* buf, VMUINT32 len);

/* define proximity monitor role callback funtion*/
typedef struct
{
    vm_pdms_connection_state_callback           connection_state_cb;
    vm_pdms_data_to_read_callback               data_to_read_notify_cb;
    vm_pdms_read_data_request_callback          read_data_request_cb;
}vm_pdms_callback_t;

/****************************************************************************
 * Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  vm_pdms_init
 * DESCRIPTION
 *  This function is to let pedometer app init pdms server callback
 * PARAMETERS
 *  vm_pdms_callback_t
 * RETURNS
 *  vm_bt_pdms_status
 *****************************************************************************/
VMINT vm_pdms_init(vm_pdms_callback_t *cb);

/*****************************************************************************
 * FUNCTION
 *  vm_pdms_deinit
 * DESCRIPTION
 *  This function is to let pedometer app deinit pdms server callback
 * PARAMETERS
 *  void
 * RETURNS
 *  vm_bt_pdms_status
 *****************************************************************************/
VMINT vm_pdms_deinit(void);

/*****************************************************************************
 * FUNCTION
 *  vm_pdms_send_data
 * DESCRIPTION
 *  This function is to let pedometer app send data to remote
 * PARAMETERS
 *  bdaddr is return remote bluetooth device address, format:XX:XX:XX:XX:XX:XX 
 * RETURNS
 *  void
 *****************************************************************************/
VMINT vm_pdms_send_data(VMINT8* bd_addr, void* buf, VMUINT32 len, VMINT *err_code);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VM_BTPDMS_SDK_H */