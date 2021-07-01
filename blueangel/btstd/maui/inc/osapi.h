/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 *
 * MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

#ifndef __OSAPI_H
#define __OSAPI_H

/****************************************************************************
 *
 * File:
 *     $Workfile:osapi.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #2 $
 *
 * Description:
 *     Defines the APIs used by the stack to access system services.
 *
 * Copyright 1999-2005 Extended Systems, Inc.
 * Portions copyright 2005 iAnywhere Solutions, Inc.
 * All rights reserved. All unpublished rights reserved.
 *
 * Unpublished Confidential Information of iAnywhere Solutions, Inc.
 * Do Not Disclose.
 *
 * No part of this work may be used or reproduced in any form or by any
 * means, or stored in a database or retrieval system, without prior written
 * permission of iAnywhere Solutions, Inc.
 *
 * Use of this work is governed by a license granted by iAnywhere Solutions,
 * Inc.  This work contains confidential and proprietary information of
 * iAnywhere Solutions, Inc. which is protected by copyright, trade secret,
 * trademark and other intellectual property rights.
 *
 ****************************************************************************/
/*****************************************************************************
* Include
*****************************************************************************/
/* basic system service headers */
#include "bt_common.h"
#include "btostypes.h"


/*---------------------------------------------------------------------------
 * Operating System API layer
 *
 *     The OS API is a set of functions used by the stack to access
 *     system services. If you are porting to a new operating system,
 *     you must provide the functions described here.
 *
 *     The functions in this API are intended for exclusive use by the
 *     stack. Applications should use the native operating system interface
 *     and avoid making OS_ calls themselves.
 */

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * TimeT type
 *
 *     Indicates an amount of time in system ticks or milliseconds. This must
 *     be a 32-bit value because some timeouts may exceed 5 minutes.
 */
typedef U32 TimeT;

/* End of TimeT type */

/* typedef unsigned long DWORD; */


typedef void (*OsTimerNotify)(void);


/****************************************************************************
 *
 * Function Reference
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * OS_Init()
 *
 *     Initializes the stack and operating system layer. This function is
 *     not called by the stack, but must be called by your operating system
 *     or application to set up the stack and its operating system services.
 *
 *     The OS_Init function must perform the following tasks in this order:
 *
 *     1) Seed the random number generator with a random value such as
 *     the current system time.
 *
 *     2) Any other operating-system specific functions, such as timer
 *     initialization or the creation of semaphores.
 *
 *     3) Call EVM_Init to initialize the Event Manager. This also
 *     initializes all stack layers. Note that this function may
 *     return FALSE if stack initialization failed for some reason.
 *
 *     4) Create and start the stack task. This task calls EVM_Process
 *     at least once for every call to OS_NotifyEvm. See OS_NotifyEvm
 *     for more details.
 *
 * Returns:
 *     TRUE - Success.
 *
 *     FALSE - Initialization failed for some reason.
 */
BOOL OS_Init(void);

/*---------------------------------------------------------------------------
 * OS_Deinit()
 *
 *     Deinitializes the stack and operating system layer. This function
 *     is not called by the stack, but may be called by your operating
 *     system or application to shut down the stack and free its resources.
 */
void OS_Deinit(void);

/*---------------------------------------------------------------------------
 * OS_GetSystemTime()
 *
 *     Called by the stack to get the current system time in ticks.
 *
 *     The system time provided by this function can start at any value;
 *     it does not to start at 0. However, the time must "roll over" only
 *     when reaching the maximum value allowed by TimeT. For instance, a
 *     16-bit TimeT must roll over at 0xFFFF. A 32-bit TimeT must roll
 *     over at 0xFFFFFFFF.
 *
 *     System ticks may or may not be equivalent to milliseconds. See the
 *     MS_TO_TICKS macro in config.h (General Configuration Constants)
 *     for more information.
 *
 * Returns:
 *     The current time in ticks.
 */
//TimeT OS_GetSystemTime(void);

// TODO: Remove conflicting API definitions
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
#endif

/*---------------------------------------------------------------------------
 * OS_Rand32()
 *
 *     Called by the stack to generate a random number between 0x0000 and 0xFFFFFFFF.
 *
 * Returns:
 *     A 32-bit random number.
 */
S32 OS_Rand32(void);

// TODO: Remove conflicting API definitions
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
#endif
//void OS_ResetTimerId(void);
void OS_ResetInd(void);

/*---------------------------------------------------------------------------
 * OS_NotifyEvm()
 *
 *     Called by the stack to indicate that EVM_Process should be called.
 *     Depending on your operating system, this call may be made in
 *     interrupt mode or task mode.
 *
 *     In multitasking systems, the stack task alternately calls EVM_Process
 *     and blocks to save CPU time. The block may be implemented by an
 *     event semaphore or similar object. OS_NotifyEvm should post the
 *     semaphore, or otherwise cause the stack task to unblock and
 *     call EVM_Process.
 *
 *     In non-multitasking systems (where XA_MULTITASKING is disabled),
 *     tasks are usually simulated using a round-robin execution scheme. In
 *     this case, EVM_Process is called continuously, and no task ever
 *     blocks. Therefore, this function is not used.
 *
 *     If OS_NotifyEvm is called during EVM_Process execution,
 *     EVM_Process must be executed again before the stack task blocks.
 *
 * Requires:
 *     XA_MULTITASKING enabled.
 */
void OS_NotifyEvm(void);

#define OS_LockStack()   (void)0
#define OS_UnlockStack() (void)0
#define OS_StopHardware() (void)0
#define OS_ResumeHardware() (void)0


// TODO: Remove conflicting API definitions
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

/*---------------------------------------------------------------------------
 * OS_StrCat()
 *
 *     Concatenate the string.
 *
 * Parameters:
 *     source - String to copy from
 *     dest - String buffer to copy to
 *
 * Returns:
 *     Returns dest string.
 */
char* OS_StrCat(char *dest, const char *source);

/*---------------------------------------------------------------------------
 * OS_SetSystemPropertyUint()
 *
 *     Set system properties with type unsigned int.
 *
 * Parameters:
 *     name - system property name       [IN]
 *     val - value of the system property  [IN]
 *     persist - indicate persist property or not  [IN]
 * Returns:
 *     0 : failed
 *     other :success
 */
//U32 OS_SetSystemPropertyUint(const char *name, U32 val, U8 persist);

/*---------------------------------------------------------------------------
 * OS_GetSystemPropertyUint()
 *
 *     Get system properties with type unsigned int.
 *
 * Parameters:
 *     name - system property name                              [IN]
 *     val - pointer of the value of the system property     [OUT]
 *     persist - indicate persist property or not                [IN]
 * Returns:
 *     0 : failed
 *     other :success
 */
//U32 OS_GetSystemPropertyUint(const char *name, U32 *val, U8 persist);

/*---------------------------------------------------------------------------
 * OS_GetBitsValue()
 *
 *     Get value of bits in specified memory address.
 *
 * Parameters:
 *     addr - address of the mask bits
 *     start_pos - start bit
 *     bits - number of bits to get
 *
 * Returns:
 *     value in the specified bits
 */
U32 OS_GetBitsValue(const U8 *addr, U32 start_pos, U32 bits);

/*---------------------------------------------------------------------------
 * OS_TestBit()
 *
 *     Test bit in correspond bit position in array "addr".
 *
 * Parameters:
 *     nr - bit position to test (0-based)
 *     addr - address of the mask bits
 *
 * Returns:
 *     0: bit is not set
 *     otherwise : bit is set
 */
U32 OS_TestBit(U32 nr, const U8 *addr);

/*---------------------------------------------------------------------------
 * OS_SetBit()
 *
 *     Set bit in correspond bit position in array "addr".
 *
 * Parameters:
 *     nr - bit position to test (0-based)
 *     addr - address of the mask bits
 *
 * Returns:
 */
void OS_SetBit(U32 nr, U8 *addr);

#ifdef BTMTK_ON_MAUI
//extern void kal_assert_fail_native(char* expr, char* file, kal_uint32 line);
//extern void BtRadio_Restart_Req(void);


//Osapi.h
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/

//#define Assert(exp)  (((exp) != 0) ? (void)0 : kal_assert_fail())
//#define AssertEval(exp) (((exp) != 0) ? (void)0 : kal_assert_fail())
#endif



/*---------------------------------------------------------------------------
 * OS_Report()
 *
 *     Called by the stack to report debugging information.
 *
 * Requires:
 *     XA_DEBUG_PRINT enabled.
 *
 * Parameters:
 *     format - A string containing the failed expression.
 *
 *     ... - printf style arguments.
 */
//void OS_Report(const char *format, ...);

#define DebugPrint(s) OS_Report s
//#define Report(s) OS_Report s

#endif /* __OSAPI_H */

