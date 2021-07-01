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

#ifndef	_VM_APP_COMM_SDK_H
#define _VM_APP_COMM_SDK_H


#ifdef __cplusplus
extern "C" {
#endif

#include "vmsys.h"
#include "vmpromng.h"

/* Maximum number of messages in LinkIt message queue. */
#define VM_APPCOMM_MESSAGE_QUEUE_SIZE 16

/* LINKIT application messge ID base, application should define its own message ID using a number starting from this base. */
#define VM_MESSAGE_ID_BASE  1000

/* LINKIT application messge ID maximum limit, application should define its own message ID using a number that's less than this limit. */
#define VM_MESSAGE_ID_MAX  60000

#define VM_MESSAGE_INVALID_ID   0


/* LINKIT message structure. */ 
typedef struct
{
    VM_P_HANDLE sender;   /* The sender's process handle. */
    VM_P_HANDLE receiver; /* The receiver's process handle. */
    VMUINT msg_id;  /* The message ID. */ 
    VMINT wparam;   /* wparam of message. */
    VMINT lparam;   /* lparam of message. */
} vm_message_struct;

/* LINKIT message queue structure- a circle array. */
typedef struct
{
    vm_message_struct message[VM_APPCOMM_MESSAGE_QUEUE_SIZE]; /* Message array. */
    VMINT   head; /* Message index which came first to the message queue. */
    VMINT   tail; /* Message index which came last to the message queue. */
}vm_message_queue_struct;

/* Mapping table size of native and LinkIt application.  */
#define VM_APPCOMM_MAPPING_TABLE_SIZE   10


/* Message mapping table item for the message from LinkIt application to native application. */
typedef struct
{
    VM_P_HANDLE sender; /* The process handle that the LinkIt application sender listens for. */
    VM_MESSAGE_PROC proc; /* Native application receiver callback function. */
}vm_message_proc_mapping_struct;


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_init
 * DESCRIPTION
 *  Initializes LinkIt message queue.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 * EXAMPLE
 * <code>
 * You don't need to call this API.
 * </code>
 *****************************************************************************/
void vm_appcomm_init(void);


/*****************************************************************************
* FUNCTION
 *    vm_appcomm_dispatch_msg
 * DESCRIPTION
 *  Dispatches LinkIt message in MMI task.
* RETURNS
*  void
* EXAMPLE
* <code>
* You don't need to call this API unless you think the message process has delayed 
* for a long time. 
* </code>
*****************************************************************************/
void vm_appcomm_dispatch_msg(void);


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_reg_msg_proc
 * DESCRIPTION
 *  Registers LinkIt message process.
 * PARAMETERS
 *  handle : [IN] Message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] Message process.
 * RETURNS
 *  1 if registered successfully.
 *  0 if register has failed.
 * EXAMPLE
 * <code>
 * typedef enum 
 * {
 *   CUSTOMER_APPCOMM_SCREEN = VM_MESSAGE_ID_BASE + 1,
 *   CUSTOMER_APPCOMM_MAX_NUM
 * }PEDOMETER_PROCESS_STATUS;
 *
 * VMINT customer_appcomm_example_cb(VM_P_HANDLE sender, VMUINT msg_id, VMINT wparam, VMINT lparam)
 * {
 *   if (VM_MSG_PAINT != msg_id && VM_MSG_QUIT != msg_id)
 *   {
 *       return 0;
 *   }
 *   switch(msg_id)
 *   {
 *        case CUSTOMER_APPCOMM_SCREEN:
 *        vm_log_debug("customer_appcomm_example_cb");
 *        break;
 *        
 *        default:
 *        break;
 *   }
 *   return 1;
 * }
 *
 * void customer_appcomm_init(void)
 * {
 *    VMINT handle = 0;
 *    handle = vm_pmng_get_current_handle();
 *    vm_appcomm_reg_msg_proc(handle, customer_appcomm_example_cb);
 * }
 *
 * void customer_appcomm_deinit(void)
 * {
 *    VMINT handle = 0;
 *    handle = vm_pmng_get_current_handle();
 *    vm_appcomm_dereg_msg_proc(handle, customer_appcomm_example_cb);
 * }
 *
 * void customer_appcomm_handle(void)
 * {
 *    VMINT handle = 0;
 *    handle = vm_pmng_get_current_handle();
 *    vm_post_msg(handle, CUSTOMER_APPCOMM_SCREEN, 0, 0);
 *    //vm_appcomm_send_msg(handle, CUSTOMER_APPCOMM_SCREEN, 0, 0);
 * }
 * </code>
 *****************************************************************************/
VMINT vm_appcomm_reg_msg_proc(VMINT handle, VM_MESSAGE_PROC proc);


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_dereg_msg_proc
 * DESCRIPTION
 *  Deregisters LinkIt message process.
 * PARAMETERS
 *  handle : [IN] Message sender handle, if despite of sender, this parameter should be set to zero.
 *  proc : [IN] Message process.
 * RETURNS
 *  1 if deregistered successfully.
 *  0 if deregister has failed.
 * EXAMPLE 
 * <code>
 * Refer to vm_appcomm_reg_msg_proc code example.
 * </code>
 *****************************************************************************/
VMINT vm_appcomm_dereg_msg_proc(VMINT handle, VM_MESSAGE_PROC proc);


/*****************************************************************************
 * FUNCTION
 *  vm_appcomm_send_msg
 * DESCRIPTION
 *  Sends message to LinkIt or native APP, this function will invoke message procedure directly.
 * PARAMETERS
 *  phandle : [IN] Receiver process handle, if receiver is a native application, then this value should be zero.
 *  msg_id : [IN] User defined message ID, it should be larger than VM_MESSAGE_ID_BASE.
 *  wparam : [IN] wparam of message.
 *  lparam : [IN] lparam of message.
 * RETURNS
 *  Message procedure return value.
 * EXAMPLE 
 * <code>
 * Refer to vm_appcomm_reg_msg_proc code example.
 * </code>
 *****************************************************************************/
VMINT vm_appcomm_send_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam);


/*****************************************************************************
 * FUNCTION
  *    vm_appcomm_post_msg
  * DESCRIPTION
  *  Posts message to LinkIt or native APP, this function will put this message to the end of LinkIt message queue. 
  *  When the function call is finished, MMI task will dispatch LinkIt message and invoke message procedure. 
  * PARAMETERS
  *  phandle : [IN] Receiver process handle, if receiver is native application, this value should be zero.
  *  msg_id : [IN] User defined message ID, it should be larger than VM_MESSAGE_ID_BASE.
  *  wparam : [IN] wparam of message.
  *  lparam : [IN] lparam of message.
  * RETURNS
  *  Message procedure return value.
 * EXAMPLE 
 * <code>
 * Refer to vm_appcomm_reg_msg_proc code example.
 * </code>
 *****************************************************************************/
VMINT vm_appcomm_post_msg(VMINT handle, VMUINT msg_id, VMINT wparam, VMINT lparam);


#ifdef __cplusplus
}
#endif 

#endif /* _VM_APP_COMM_SDK_H */
