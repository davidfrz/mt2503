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

#ifndef VM_BTHFP_SDK_H
#define VM_BTHFP_SDK_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#include "vmsys.h"

/* Maximum number length */
#define VM_BTHFP_HF_MAX_NUM_URI_LEN (41)
#define VM_BTHFP_HF_MAX_DIS_NAME_FROM_APP (41)

typedef struct
{
    VMUINT32 lap;    /* Lower Address Part 00..23 */
    VMUINT8  uap;    /* upper Address Part 24..31 */
    VMUINT16 nap;    /* Non-significant    32..47 */
} vm_bthfp_btaddr;

typedef struct VM_BTHFP_MYTIME
{
    VMUINT16 nYear;
    VMUINT8 nMonth;
    VMUINT8 nDay;
    VMUINT8 nHour;
    VMUINT8 nMin;
    VMUINT8 nSec;
    VMUINT8 DayIndex; /* 0=Sunday */
} VM_BTHFP_MYTIME;

/* Call state enum */
typedef enum
{
    VM_BTHFP_HF_BT_IDLE_STATE = 0x00, /* IDLE state */
    VM_BTHFP_HF_OUTGOING_STATE = 0x01, /* Outgoing state */
    VM_BTHFP_HF_INCOMING_STATE = 0x02, /* Incoming state */
    VM_BTHFP_HF_ACTIVE_STATE = 0x04, /* Active state */
    VM_BTHFP_HF_HOLD_STATE = 0x08, /* Hold state */
    VM_BTHFP_HF_CALL_STATE_END_OF_ENUM /* End of the enum */
} vm_bthfp_hf_call_state_enum;


typedef enum
{
    VM_BTHFP_HF_SUCCESS = 0,
    VM_BTHFP_HF_INVALD_PARA = -1,
    VM_BTHFP_HF_REGISTERED = -2,
    VM_BTHFP_HF_INST_FULL = -3,
    VM_BTHFP_HF_UNKNOWN_ERR = -4,
    VM_BTHFP_HF_ERROR = -5,
    VM_BTHFP_HF_ERROR_OF_MEM = -6,
    VM_BTHFP_HF_ERROR_OF_RES = -7,
    VM_BTHFP_HF_ERROR_INVALID_ID = -8,
    VM_BTHFP_HF_ERROR_OF_PROCESS = -9,
} vm_bthfp_hf_reg_result_enum;

typedef enum
{
    VM_BTHFP_HF_NOTI_EVT_NONE = 0x00,
    VM_BTHFP_HF_NOTI_EVT_IND = 0x01,
    VM_BTHFP_HF_NOTI_EVT_ACT = 0x02,
    VM_BTHFP_HF_NOTI_EVT_CONN = 0x04,
    VM_BTHFP_HF_NOTI_EVT_TOTAL
} vm_bthfp_hf_notify_mask_enum;

#define VM_BTHFP_HF_CALL_STATE_CONNECTED (vm_bthfp_hf_call_state_enum) (VM_BTHFP_HF_ACTIVE_STATE | VM_BTHFP_HF_HOLD_STATE)
#define VM_BTHFP_HF_CALL_STATE_MOMT (vm_bthfp_hf_call_state_enum) (VM_BTHFP_HF_INCOMING_STATE | VM_BTHFP_HF_OUTGOING_STATE)
#define VM_BTHFP_HF_CALL_STATE_ALL (vm_bthfp_hf_call_state_enum)(VM_BTHFP_HF_INCOMING_STATE|VM_BTHFP_HF_OUTGOING_STATE|VM_BTHFP_HF_ACTIVE_STATE | VM_BTHFP_HF_HOLD_STATE)

/* Action opcode enum */
typedef enum
{
    VM_BTHFP_HF_NO_ACT = 0, /* No action */
    VM_BTHFP_HF_DIAL_ACT, /* Dial action */
    VM_BTHFP_HF_REDIAL_ACT, /* Redial action */ 
    VM_BTHFP_HF_ACCEPT_ACT, /* Accept action */
    VM_BTHFP_HF_HOLD_ACT, /* Hold action */
    VM_BTHFP_HF_RETRIEVE_ACT, /* Retrieve action */
    VM_BTHFP_HF_SWAP_ACT,  /* Swap action */
    VM_BTHFP_HF_END_SINGLE_ACT, /* End single action */
    VM_BTHFP_HF_END_ALL_ACT, /* End all action, null */
    VM_BTHFP_HF_END_ALL_PROCESSING_ACT, /* End all processing action, null */
    VM_BTHFP_HF_BVRA_ACT, /*  */
    VM_BTHFP_HF_SEND_DTMF_ACT, /* Send DTMF action, no response */
    VM_BTHFP_HF_FORCE_REFRESH_ACT, /* */
    VM_BTHFP_HF_NEW_DEV,
    VM_BTHFP_HF_DEL_DEV,
    VM_BTHFP_HF_SWITCH_AUDIO_PATH, /*  */
    VM_BTHFP_HF_SET_VGS_ACT, /*  */
    VM_BTHFP_HF_BAT_REPORT_ACT, /*  */
    VM_BTHFP_HF_ACT_OPCODE_TOTAL /* Total enum number */
}vm_bthfp_hf_act_opcode_enum;


/* UCM error cause enum */
typedef enum
{
    VM_BTHFP_HF_RESULT_OK, /* OK */
    VM_BTHFP_HF_RESULT_UNSPECIFIED_ERROR, /* Unspecified error */
    VM_BTHFP_HF_RESULT_NOT_CONNECTED,
    VM_BTHFP_HF_RESULT_UCM_BUSY,
    VM_BTHFP_HF_RESULT_NOT_ALLOWED_TO_DIAL,
    VM_BTHFP_HF_RESULT_NOT_ALLOWED_TO_SETUP,
    VM_BTHFP_HF_RESULT_EMPTY_NUM,
    VM_BTHFP_HF_RESULT_INVALID_NUM,
    VM_BTHFP_HF_RESULT_INVALID_CALL_ID,
    VM_BTHFP_HF_RESULT_NO_CALL_TO_ACCEPT,
    VM_BTHFP_HF_RESULT_NO_CALL_TO_HOLD,
    VM_BTHFP_HF_RESULT_NO_CALL_TO_RETRIEVE,
    VM_BTHFP_HF_RESULT_NO_CALL_TO_SWAP,
    VM_BTHFP_HF_RESULT_NO_CALL_TO_END,
    VM_BTHFP_HF_RESULT_NO_DEV,
    VM_BTHFP_HF_RESULT_DEVICE_EXIST,
    VM_BTHFP_HF_RESULT_DEVICE_LIST_IS_FULL,
    VM_BTHFP_HF_RESULT_SP_NO_RESPONSE,
    VM_BTHFP_HF_RESULT_FEATURE_DONT_SUPPORT,
    VM_BTHFP_HF_RESULT_END_OF_ENUM /* end of the enum */
} vm_bthfp_hf_result_enum;

/* The bt notification callback mre engine */
typedef void (*vm_bthfp_hf_notify_cb)(VMUINT32 evt, void *para, void* user_data);


/* refresh indication struct */
typedef struct
{
    VMUINT8 call_id;
    VMUINT8 call_idx;
    VMUINT8 dir;
    VMUINT8 mode;
    VMUINT8 multiParty;
    vm_bthfp_hf_call_state_enum call_state; //to maintain the varios states of a call like Active, Hold, etc
    VMINT32 srv_hd;
    VMUINT8 num_uri[VM_BTHFP_HF_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    VMUINT16 dis_name[VM_BTHFP_HF_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
    VM_BTHFP_MYTIME start_time;//Maintain time duration of the active call
    vm_bthfp_hf_act_opcode_enum proc_act;
    void* action_data;
}vm_bthfp_hf_call_info_struct;

/* refresh indication struct */
typedef struct
{
    VMINT32 srv_hd;
    vm_bthfp_btaddr dev_addr;
    VMUINT16 dev_name[19];
}vm_bthfp_hf_dev_info_struct;



/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_act_request
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  void
 *****************************************************************************/
void vm_bthfp_hf_act_request(vm_bthfp_hf_act_opcode_enum act_op, void *act_data);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_act_permit
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  vm_bthfp_hf_result_enum
 *****************************************************************************/
VMINT vm_bthfp_hf_act_permit(vm_bthfp_hf_act_opcode_enum act_op, void *ptr);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_all_devices_call_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMINT32 vm_bthfp_hf_query_all_devices_call_count(vm_bthfp_hf_call_state_enum call_state, VMINT32* call_list);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_single_device_call_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMINT32 vm_bthfp_hf_query_single_device_call_count(VMINT32 srv_hd, vm_bthfp_hf_call_state_enum call_state, VMINT32* index);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_all_devices_group_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMINT32 vm_bthfp_hf_query_all_devices_group_count(vm_bthfp_hf_call_state_enum call_state, VMINT32* group_list);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_single_device_group_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMINT32 vm_bthfp_hf_query_single_device_group_count(VMINT32 srv_hd, vm_bthfp_hf_call_state_enum call_state, VMINT32* index);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_call_data
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMBOOL vm_bthfp_hf_query_call_data(VMUINT32 call_id, vm_bthfp_hf_call_info_struct* call_info);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_service_hd
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 * 
 *****************************************************************************/
VMINT32 vm_bthfp_hf_query_service_hd(vm_bthfp_btaddr* bt_addr);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_connected_dev_info
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMBOOL vm_bthfp_hf_query_connected_dev_info(VMINT32 srv_hd, vm_bthfp_hf_dev_info_struct* dev_info);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_query_connected_dev_count
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 * 
 *****************************************************************************/
VMUINT32 vm_bthfp_hf_query_connected_dev_count(VMINT32* srv_hd_list);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_is_any_call
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  void
 *****************************************************************************/
VMBOOL vm_bthfp_hf_is_any_call(void);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_is_conference_call
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 * 
 *****************************************************************************/
VMBOOL vm_bthfp_hf_is_conference_call(VMUINT32* count, VMINT32* srv_hd_list);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_is_valid_service_hd
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 * 
 *****************************************************************************/
VMBOOL vm_bthfp_hf_is_valid_service_hd(VMINT32 srv_hd);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_proc_inject_string
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMUINT8 vm_bthfp_hf_proc_inject_string(VMUINT8 index, VMUINT8* string);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_register_notify_callback
 * DESCRIPTION
 *  callback according to vm_bthfp_hf_notify_mask_enum event to handle
 * PARAMETERS
 *
 * RETURN VALUES
 *  vm_bthfp_hf_reg_result_enum
 *****************************************************************************/
VMINT vm_bthfp_hf_register_notify_callback(vm_bthfp_hf_notify_cb callback, void* user_data);

/*****************************************************************************
 *
 * FUNCTION
 *  vm_bthfp_hf_deregister_notify_callback
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURN VALUES
 *  
 *****************************************************************************/
VMINT32 vm_bthfp_hf_deregister_notify_callback(VMINT32 noti_id);


#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* VM_BTHFP_SDK_H */