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

#ifndef __EVENTMGR_H
#define __EVENTMGR_H

/***************************************************************************
 *
 * File:
 *     $Workfile:eventmgr.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Types, defines, and prototypes for OS access to the Event Manager.
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

// #include "osapi.h"
#include "btosapi.h"
#include "utils.h"
#include "config.h"

#if (IRDA_STACK == XA_ENABLED) || (BT_STACK == XA_ENABLED) || (XA_EVENTMGR == XA_ENABLED)

/*---------------------------------------------------------------------------
 * Event Manager API layer
 *
 *     The Event Manager provides a thread of execution to all stack
 *     components and manages stack initialization and deinitialization. Refer
 *     to the documentation in each function for specific instructions
 *     on how it interacts with the operating system integration layer
 *     (OS API).
 */

/*
 * Forward reference of EvmTimer.
 */
typedef struct _EvmTimer EvmTimer;

/*---------------------------------------------------------------------------
 * Callback used to notify a stack component that the timer expired.
 */
typedef void (*EvmTimerNotify)(EvmTimer *);

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * EvmTimer structure
 *
 *     Represents a stack timer. This structure is for use by
 *     internal stack components only.
 */
struct _EvmTimer
{
    ListEntry node;         /* Used internally by the Event Manager */
    void *context;          /* Context area for use by callers */
    EvmTimerNotify func;    /* Function to call when timer fires */

    /* === Internal use only === */
    U32 time;         /* Amount of time to wait */
    U32 startTime;    /* System time when the timer started */
};

/****************************************************************************
 *
 * Function Reference
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * EVM_Init()
 *
 *     Called by the OS to initializes the event manager and the stack.
 *     This must be called before the first call to EVM_Process.
 *
 * Returns:
 *     TRUE - Initialization succeeded.
 *
 *     FALSE - Initialization failed.
 */
BOOL EVM_Init(void);

/*---------------------------------------------------------------------------
 * EVM_Deinit()
 *
 *     Called by the OS to deinitialize the event manager and the stack.
 *     Do not call EVM_Process after calling this function.
 */
void EVM_Deinit(void);

/*---------------------------------------------------------------------------
 * EVM_Process()
 *
 *     Called by the OS to give a thread of execution to the stack.
 *     Internally, this function calls OS_LockStack and OS_UnlockStack
 *     to protect the stack from reentrancy.
 */
void EVM_Process(void);

/* Prototypes for EVM_StartTimer EVM_CancelTimer macros */
void EvmStartTimer(EvmTimer *timer, U32 ticks, BOOL stopHardware);
void EvmCancelTimer(EvmTimer *timer, BOOL stopHardware);

/*---------------------------------------------------------------------------
 * EVM_StartTimer()
 *
 *     Called by stack layers to start a timer. After the specified
 *     amount of time elapses, the timer fires by calling the timer's
 *     callback function. The timer fires only once for each call to
 *     EVM_StartTimer().
 *
 *     If the timer was already running, this function resets it with a
 *     new time period.
 *
 *     Internally, timers are managed by calling OS_GetSystemTime during
 *     stack execution. When XA_MULTITASKING is enabled, this function
 *     uses OS_StartTimer, which maps to a single system timer.
 *
 * Parameters:
 *     timer - Pointer to a timer structure. The caller must
 *         initialize the func field, and may also initialize the context
 *         field if desired. When the timer fires, timer.func is called
 *         during stack execution. NOTE: The timer.func will typically check
 *         for Hold, Park or Sniff mode with ME_GetCurrentMode when called
 *         and handle these modes differently (usually restarting the timer
 *         is sufficient.)
 *
 *     ms - Number of milliseconds to wait before firing. This value
 *         is converted to system ticks using the MS_TO_TICKS macro.
 */
void EVM_StartTimer(EvmTimer *timer, U32 ms);
#ifndef BTMTK_ON_MAUI
#define EVM_StartTimer(timer, ms) EvmStartTimer(timer, MS_TO_TICKS(ms), TRUE)
#endif
/*---------------------------------------------------------------------------
 * EVM_CancelTimer()
 *
 *     Called by the stack to cancel a timer. This prevents the timer
 *     from firing.
 *
 * Parameters:
 *     timer - Pointer to a timer structure. The timer must have been
 *         started by EVM_StartTimer and must not have fired or
 *         been cancelled already.
 */
void EVM_CancelTimer(EvmTimer *timer);
#ifndef BTMTK_ON_MAUI
#define EVM_CancelTimer(timer) EvmCancelTimer(timer, TRUE)
#endif
void EvmResetTimer(EvmTimer *timer);

#define EVM_ResetTimer(timer) EvmResetTimer(timer)

#endif /* (IRDA_STACK == XA_ENABLED) || (BT_STACK == XA_ENABLED) || (XA_EVENTMGR == XA_ENABLED) */

#endif /* __EVENTMGR_H */

