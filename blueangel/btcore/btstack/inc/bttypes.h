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

#ifndef __BTTYPES_H
#define __BTTYPES_H

/****************************************************************************
 *
 * File:
 *     $Workfile:bttypes.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     General types, defines, and prototypes for Blue SDK components.
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

// #include "xatypes.h"
#include "btostypes.h"

#include "btconfig.h"
#include "xastatus.h"
#include "utils.h"
#include "eventmgr.h"
#include "bt_feature.h"

/*---------------------------------------------------------------------------
 * Global Types layer
 *
 *     General types and conversion functions used by all components of
 *     the stack and applications are defined here.
 */

/****************************************************************************
 *
 * Constants
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BDADDR_NTOA_SIZE constant
 *
 *     Defines the minimum size for the string when using the bdaddr_ntoa
 *     function.
 */
#define BDADDR_NTOA_SIZE        18

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtStatus type
 *
 *     This type is returned from most stack APIs to indicate the success
 *     or failure of the operation. In many cases, BT_STATUS_PENDING
 *     is returned, meaning that a future callback will indicate the
 *     result of the operation.
 */
typedef XaStatus BtStatus;

#define BT_STATUS_SUCCESS           XA_STATUS_SUCCESS
#define BT_STATUS_FAILED            XA_STATUS_FAILED
#define BT_STATUS_PENDING           XA_STATUS_PENDING
#define BT_STATUS_BUSY              XA_STATUS_BUSY
#define BT_STATUS_NO_RESOURCES      XA_STATUS_NO_RESOURCES
#define BT_STATUS_NOT_FOUND         XA_STATUS_NOT_FOUND
#define BT_STATUS_DEVICE_NOT_FOUND  XA_STATUS_DEVICE_NOT_FOUND
#define BT_STATUS_CONNECTION_FAILED XA_STATUS_CONNECTION_FAILED
#define BT_STATUS_TIMEOUT           XA_STATUS_TIMEOUT
#define BT_STATUS_NO_CONNECTION     XA_STATUS_NO_CONNECTION
#define BT_STATUS_INVALID_PARM      XA_STATUS_INVALID_PARM
#define BT_STATUS_IN_PROGRESS       XA_STATUS_IN_PROGRESS
#define BT_STATUS_RESTRICTED        XA_STATUS_RESTRICTED
#define BT_STATUS_INVALID_TYPE      XA_STATUS_INVALID_TYPE
#define BT_STATUS_HCI_INIT_ERR      XA_STATUS_HCI_INIT_ERR
#define BT_STATUS_NOT_SUPPORTED     XA_STATUS_NOT_SUPPORTED
#define BT_STATUS_IN_USE            XA_STATUS_IN_USE
#define BT_STATUS_SDP_CONT_STATE    XA_STATUS_CONTINUE
#define BT_STATUS_CANCELLED         XA_STATUS_CANCELLED
#define BT_STATUS_NOSERVICES        XA_STATUS_NOSERVICES
#define BT_STATUS_SCO_REJECT        MTK_STATUS_SCO_REJECT
#define BT_STATUS_CHIP_REASON       MTK_STATUS_CHIP_REASON
#define BT_STATUS_BLOCK_LIST        MTK_STAUTS_BLOCK_LIST
#define BT_STATUS_SCATTERNET_REJECT MTK_STATUS_SCATTERNET_REJECT
#define BT_STATUS_REMOTE_REJECT     MTK_STATUS_REMOTE_REJECT
#define BT_STATUS_KEY_ERR           MTK_STATUS_KEY_ERR
#define BT_STATUS_CONNECTION_EXIST          MTK_STATUS_CONNECTION_EXIST
/* End of BtStatus */

/*---------------------------------------------------------------------------
 * BtPacketFlags type
 *
 *     This type is used by L2CAP and protocols that use directly L2CAP
 *     to manage the status of a particular BtPacket.
 */
typedef U8 BtPacketFlags;

#define BTP_FLAG_NONE       0x00        /* No current flags */
#define BTP_FLAG_INUSE      0x01        /* Used only by packet owner */
#define BTP_FLAG_LSYSTEM    0x02        /* Used only by L2CAP */
#define BTP_FLAG_LSYSTEM_SREJ    0x04        /* Used only by L2CAP SREJ*/
#define BTP_FLAG_TAIL       0x08        /* Used only by L2CAP Applications */
#define BTP_FLAG_RDEV_FISRT 0x10       /* Used only by L2CAP, retransmission tx first */
#define BTP_FLAG_FCS        0x20        /* FCS field is valid, set only by L2CAP */
#define BTP_FLAG_RDEV_RETX  0x40        /* Used only by L2CAP, retransmission tx packet */





#define BTP_FLAG_HIGH_PRIPORTY       0x20
#define BTP_FLAG_LOW_PRIPORTY       0x40
#define BTP_FLAG_NONE_PRIPORTY       0x80

/* End of BtPacketFlags */

#if defined(__BT_41_LE_FLOW_CONTROL_)
/*---------------------------------------------------------------------------
 * BtPacketFlags2 type
 *
 *     This type is used by L2CAP and protocols that use directly L2CAP
 *     to manage the status of a particular BtPacket.
 */
typedef U8 BtPacketFlags2;
#define L2BT2_FLAG_NONE           0x00        /* No current flags */
#define L2BT2_FLAG_LAST_SDU_SEG   0x01        /* No current flags */
/* End of BtPacketFlags2 */
#endif

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtPacket structure
 *
 *     Represents a packet of data. These packets may be used by applications
 *     to provide data to the stack. Certain stack events may also provide
 *     data to the application enclosed in a BtPacket structure.
 */
typedef struct _BtPacket
{
    ListEntry node; /* Used internally by the stack. */

    U8 *data;       /* Points to a buffer of user data.  */
    U16 dataLen;    /* Indicates the length of "data" in bytes. */

    U8 flags;   /*
                 * Must be initialized to BTP_FLAG_NONE by
                 * applications running on top of L2CAP. Other
                 * higher layer protocols must never modify this
                 * value.
                 */
    U8 priority_type;
#if defined (__BT_2_1_AUTO_FLUSH__)
    U8 timebound;
#endif

    /* Group: The following fields are for internal use only by the stack. */
    void *ulpContext;
    U8 *tail;
    U16 tailLen;

#if XA_STATISTICS == XA_ENABLED
    U32 rfc_timer;
    U32 hci_timer;
    U32 l2cap_timer;
#endif /* XA_STATISTICS == XA_ENABLED */

    U16 llpContext;
    U16 remoteCid;

#if L2CAP_FLOW_NON_BASIC_MODE == XA_ENABLED
    U16 segStart;
    U16 segNum;
    U8 fcs[2];
    U16 internalUsed; /* For streamming mode, used to record the txSeq*/
    U8 pollFinal;
#endif /* L2CAP_FLOW_NON_BASIC_MODE == XA_ENABLED */
#if defined(__BT_41_LE_FLOW_CONTROL_)
    U8 leFinal;
    U8 flags2;
	struct _BtPacket *returnPacket;	
#endif


    U8 hciPackets;
    U8 headerLen;
    U8 header[BT_PACKET_HEADER_LEN];
} BtPacket;

typedef struct _BtRxPacket
{
    ListEntry node; /* Used internally by the stack. */

    U8 *data;       /* Points to a buffer of user data.  */
    U16 dataLen;    /* Indicates the length of "data" in bytes. */
    U16 reqSeq;
} BtRxPacket;

/* Internal ROM constant defined in btrom.c to represent an invalid address */
extern const BD_ADDR INVALID_BDADDR;

/****************************************************************************
 *
 * Function Reference
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * bdaddr_aton()
 *
 *     Converts an ASCII-formatted Bluetooth device address into a BD_ADDR
 *     structure.
 *
 * Parameters:
 *     addr - Address in the format "xx:xx:xx:xx:xx", where x is a
 *         hexadecimal digit. The most significant byte appears first.
 *
 * Returns:
 *     BD_ADDR - A structure that contains the binary version of the
 *         address.
 */
BD_ADDR bdaddr_aton(const char *addr);

/*---------------------------------------------------------------------------
 * bdaddr_ntoa()
 *
 *     Converts a BD_ADDR structure into an ASCII-formatted device address.
 *
 * Parameters:
 *     addr - Binary device address to convert.
 *
 *     addrString - Destination string space for formatted device address.
 *         The string must contain at least BDADDR_NTOA_SIZE bytes of space.
 *
 * Returns:
 *     char * - A copy of the pointer passed in as "addrString".
 */
char *bdaddr_ntoa(const BD_ADDR *addr, char *addrString);

/*---------------------------------------------------------------------------
 * AreBdAddrsEqual()
 *
 *     Compares two Bluetooth device addresses for equality.
 *
 * Parameters:
 *     addrA - First address to compare.
 *
 *     addrB - Second address to compare.
 *
 * Returns:
 *     TRUE when the addresses are the same, FALSE when they are different
 */
BOOL AreBdAddrsEqual(const BD_ADDR *addrA, const BD_ADDR *addrB);

#define AreBdAddrsEqual(_ADDRA, _ADDRB)   OS_MemCmpExt((_ADDRA)->addr, 6, (_ADDRB)->addr, 6)

/*---------------------------------------------------------------------------
 * IsValidBdAddr()
 *
 *     Determines whether a BD_ADDR contains a valid Bluetooth device
 *     address.
 *
 * Parameters:
 *     addr - Address to examine.
 *
 * Returns:
 *     TRUE when the address is valid, FALSE if it is invalid.
 */
BOOL IsValidBdAddr(const BD_ADDR *Addr);

#define IsValidBdAddr(_BDA) (OS_MemCmpExt((_BDA)->addr, 6, INVALID_BDADDR.addr, 6) == FALSE)

#endif /* __BTTYPES_H */

