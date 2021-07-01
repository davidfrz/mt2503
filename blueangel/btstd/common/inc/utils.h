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

#ifndef __UTILS_H
#define __UTILS_H

/***************************************************************************
 *
 * File:
 *     $Workfile:utils.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Includes for utility functions.
 *
 * Created:
 *     October 1, 1996
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

#include "btostypes.h"

#ifdef BTMTK_ON_MAUI
#include "kal_public_api.h"

#ifdef __PRODUCTION_RELEASE__
extern void BtRadio_Restart_Req(void);

#define Assert(exp) (((exp) != 0) ? (void)0 : (void)BtRadio_Restart_Req()) //(void)0 : (void)MTK_BT_Assert())
#define AssertEval(exp) (((exp) != 0) ? (void)0 : (void)BtRadio_Restart_Req())
 
#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#endif

#ifdef BTMTK_ON_LINUX
#ifndef Assert
#define Assert(exp) OS_Assert(exp)
#endif
#endif

/* For backward compatibility */
BOOL StrnCmp(const U8 *str1, U16 len1, const U8 *str2, U16 len2);

#define StrnCmp(s1, l1, s2, l2) OS_MemCmpExt(s1, l1, s2, l2)

/*
 * Min and Max macros.
 */
#ifndef max
#define max(a,b)            (((a) > (b)) ? (a) : (b))
#endif

#ifndef min
#define min(a,b)            (((a) < (b)) ? (a) : (b))
#endif

/*
 * Macro to convert lower case ASCII characters to upper case
 */
#ifndef ToUpper
#define ToUpper(ch)  (((ch) >= 'a' && (ch) <= 'z') ? ((ch) - 'a' + 'A') : (ch))
#endif

#ifndef ALIGN
/*
 * Data structure alignment macros. Some modules aggregate data allocations,
 * care must be taken to insure that dynamically allocated structures fall
 * on appropriate byte boundries. The configuration constant XA_INTEGER_SIZE
 * is used to force alignment on 16 or 32 bit boundries. All data structures
 * will be sub-allocated on byte boundries that macth the XA_INTEGER_SIZE.
 *
 * The ALIGN() macro will grow lengths to a multiple of
 * XA_INTEGER_SIZE byte. When XA_INTEGER_SIZE == 4 the macro will look like:
 * ((length + 3) & 0xFFFC)
 */
#define ALIGN(_LEN)     (((_LEN) + XA_INTEGER_SIZE - 1) & (U16)(0-XA_INTEGER_SIZE))
#endif /* ALIGN */

/*---------------------------------------------------------------------------
 * CheckUnlockedParm()
 *
 *     Verifies the validity of calling parameters outside
 *     of a function's OS_LockStack/OS_UnlockStack pair. The behavior of
 *     this macro depends on both XA_ERROR_CHECK and XA_DEBUG.
 *
 *     If XA_ERROR_CHECK is enabled, the expression will be evaluated. If the
 *     expression is false, the macro will return from the current function
 *     with the specified return code.
 *
 *     If XA_DEBUG is enabled, but XA_ERROR_CHECK is disabled, the expression
 *     will be evaluated. If the expression is false, the macro will assert.
 *
 *     If XA_DEBUG and XA_ERROR_CHECK are both disabled, the expression will
 *     not be evaluated.
 *
 * Parameters:
 *     code - Status code to return when "exp" is false (only when
 *         XA_ERROR_CHECK is enabled)
 *     exp - Expression to evaluate
 */
#if XA_ERROR_CHECK == XA_ENABLED
#define CheckUnlockedParm(code, exp) if (!(exp)) return (code)
#else /* XA_ERROR_CHECK == XA_ENABLED */
#if XA_DEBUG == XA_ENABLED
#define CheckUnlockedParm(code, exp) Assert(exp)
#else /* XA_DEBUG is disabled as well */
#define CheckUnlockedParm(code, exp) (void)0
#endif /* XA_DEBUG */
#endif /* XA_ERROR_CHECK == XA_ENABLED */

/*---------------------------------------------------------------------------
 * CheckLockedParm()
 *
 *     Verifies the validity of calling parameters inside
 *     of a function's OS_LockStack/OS_UnlockStack pair. This macro
 *     acts just as CheckUnlockedParm does, except that it will
 *     call OS_UnlockStack before returning with the specified return code.
 *
 * Parameters:
 *     code - Status code to return when "exp" is false (only when
 *         XA_ERROR_CHECK is enabled)
 *     exp - Expression to evaluate
 */
#if XA_ERROR_CHECK == XA_ENABLED
#define CheckLockedParm(code, exp) do { if (!(exp)) { OS_UnlockStack(); \
            return (code); } } while(0)
#else /* XA_ERROR_CHECK == XA_ENABLED */
#if XA_DEBUG == XA_ENABLED
#define CheckLockedParm(code, exp) Assert(exp)
#else /* XA_DEBUG is disabled as well */
#define CheckLockedParm(code, exp) (void)0
#endif /* XA_DEBUG */
#endif /* XA_ERROR_CHECK == XA_ENABLED */

/*---------------------------------------------------------------------------
 * CheckParmExit()
 *
 *     Verifies the validity of calling parameters. The behavior of
 *     this macro depends on both XA_ERROR_CHECK and XA_DEBUG.
 *
 *     If XA_ERROR_CHECK is enabled, the expression will be evaluated. If the
 *     expression is false, this macro will set the "status" variable to
 *     the specified error code, then goto the "exit" label.
 *
 *     If XA_DEBUG is enabled, but XA_ERROR_CHECK is disabled, the expression
 *     will be evaluated. If the expression is false, the macro will assert.
 *
 *     If XA_DEBUG and XA_ERROR_CHECK are both disabled, the expression will
 *     not be evaluated.
 *
 *     IMPORTANT--This macro requires a local variable (called "status")
 *     to be defined by the function in which this macro occurs. The
 *     "status" variable is referenced by this macro only when XA_ERROR_CHECK
 *     is enabled. This macro requires the exit label "exit", for convenience
 *     the label "Check_Parm_Exit" can be used.
 *
 * Parameters:
 *     code - Status code to assign to "status" when "exp" is false (only when
 *         XA_ERROR_CHECK is enabled).
 *
 *     label - The name of a goto label. Code will jump to this label
 *         when "exp" is false (only when XA_ERROR_CHECK is enabled).
 *
 *     exp - Expression to evaluate
 */
#if XA_ERROR_CHECK == XA_ENABLED
#define CheckParmExit(code, exp) do { if (!(exp)) { status = (code); \
            goto exit; } } while(0)
#define Check_Parm_Exit  exit:
#else /* XA_ERROR_CHECK == XA_ENABLED */
#if XA_DEBUG == XA_ENABLED
#define CheckParmExit(code, exp) Assert(exp)
#define Check_Parm_Exit
#else /* XA_DEBUG == XA_ENABLED */
#define CheckParmExit(code, exp) (void)0
#define Check_Parm_Exit
#endif /* XA_DEBUG == XA_ENABLED */
#endif /* XA_ERROR_CHECK == XA_ENABLED */



#if 1

/* Little Endian to Host integer format conversion functions */
U16 LEtoHost16(const U8 *le_value);
U32 LEtoHost32(const U8 *le_value);
U64 LEtoHost64(const U8 *le_value);

/* Big Endian to Host integer format conversion functions */
U16 BEtoHost16(const U8 *be_ptr);
U32 BEtoHost32(const U8 *be_ptr);
U64 BEtoHost64(const U8 *be_ptr);

/* Store value into a buffer in Little Endian integer format */
void StoreLE16(U8 *buff, U16 le_value);
void StoreLE32(U8 *buff, U32 le_value);
void StoreLE64(U8 *buff, U64 le_value);

/* Store value into a buffer in Big Endian integer format */
void StoreBE16(U8 *ptr, U16 be_value);
void StoreBE32(U8 *ptr, U32 be_value);
void StoreBE64(U8 *buff, U64 be_value);

#else
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
#endif /* XA_USE_ENDIAN_MACROS == XA_ENABLED */

/****************************************************************************
 *
 * List Manipulation Utilities
 *
 ****************************************************************************/

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 *
 * ListEntry is for creating doubly linked circular lists. They can be used as
 * either a list head, or as part of another structure to allow that
 * structure to be a link node.
 */
#ifndef LISTS_DEFINED
#define LISTS_DEFINED

typedef struct _ListEntry
{
    struct _ListEntry *Flink;
    struct _ListEntry *Blink;

} ListEntry;
#endif /* LISTS_DEFINED */

/*---------------------------------------------------------------------------
 *
 * The XA Buffer Descriptor is used for managing data buffers that are shared
 * between protocol layers. The number of bytes of data available to read is
 * writeOffset - readOffset.
 */
typedef struct _XaBufferDesc
{
    ListEntry link; /* For Queuing, must be first */

    U16 writeOffset;    /* Write offset into buff */
    U16 readOffset;     /* Read offset into buff */
    U16 buffSize;       /* Size of associated buffer */
    U8 *buff;
} XaBufferDesc;

/****************************************************************************
 *
 * Functions and Macros Reference.
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 *
 * Used to define unused function parameters. Some compilers warn if this
 * is not done.
 */
// #define UNUSED_PARAMETER(_PARM)     (_PARM==_PARM)

/*---------------------------------------------------------------------------
 *
 *  Doubly-linked list manipulation routines.  Some are implemented as
 *  macros but logically are procedures.
 */

extern void InitializeListHead(ListEntry *list);

extern void InitializeListEntry(ListEntry *list);

#define IsEntryAvailable(Entry) (\
                                 ((Entry)->Flink == 0))

extern U8 IsListEmpty(ListEntry *list);

#define GetHeadList(ListHead) (ListHead)->Flink

#define GetTailList(ListHead) (ListHead)->Blink

#define GetNextNode(Node)     (Node)->Flink

#define GetPrevNode(Node)     (Node)->Blink

#define IsNodeConnected(n) (((n)->Blink->Flink == (n)) && ((n)->Flink->Blink == (n)))

void _InsertTailList(ListEntry *head, ListEntry *entry);
extern void InsertTailList(ListEntry *head, ListEntry *entry);

void _InsertHeadList(ListEntry *head, ListEntry *entry);

#define InsertHeadList(a, b) (Assert(IsListCircular(a)), \
                              _InsertHeadList(a, b),       \
                              Assert(IsListCircular(a)))

ListEntry *_RemoveHeadList(ListEntry *head);
extern ListEntry *RemoveHeadList(ListEntry *head);

void RemoveEntryList(ListEntry *entry);
BOOL IsNodeOnList(ListEntry *head, ListEntry *node);
BOOL IsListCircular(ListEntry *list);
void MoveList(ListEntry *dest, ListEntry *src);
void InsertList(ListEntry *dest, ListEntry *src, U8 front);

#if XA_DEBUG == XA_ENABLED
void VerifyMacros(void);
#endif /* XA_DEBUG == XA_ENABLED */

U32 Util_GetBitsValue(const U8 *addr, U32 start_pos, U32 bits);
U32 Util_TestBit(U32 nr, const U8 *addr);
void Util_SetBit(U32 nr, U8 *addr);
U8 *Util_SwapEndian_UCS2(U8 *dstBuffer, U8 *srcBuffer);

OS_CHSET_ENUM Util_GetFileEncoding(WCHAR* src_filename);
U8 Util_SetFileEncoding(WCHAR* src_filename, OS_CHSET_ENUM src_encode, WCHAR* dst_filename, OS_CHSET_ENUM dst_encode);

// To be renamed.
S32 btmtk_chset_ucs2_to_utf8_length_in_bytes(const U8 *raw);
S32 btmtk_chset_utf8_to_ucs2_length_in_bytes(const U8 *raw);


#endif /* __UTILS_H */

