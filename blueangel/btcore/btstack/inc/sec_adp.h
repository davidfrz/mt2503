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

#ifndef __SEC_ADP_H
#define __SEC_ADP_H

/****************************************************************************
 *
 * File:
 *     $Workfile:sec.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Public types, defines, and prototypes for accessing the
 *     security manager functionality of the Management Entity.
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


#include "me_adp.h"

/*---------------------------------------------------------------------------
 * Security Manager (SEC) layer
 *
 *     The Security Manager provides access to the security features
 *     offered by Bluetooth radio hardware. This includes encryption,
 *     authentication, and pairing services.
 */

/****************************************************************************
 *
 * Types
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtPairingType type
 *
 *     Bluetooth Pairing type. Indicates the action that should be taken during
 *     pairing. A link key is generated as a result of pairing. What happens to
 *     the link key is determined by the setting of BtPairingType.
 */
typedef U8 BtPairingType;

#define BPT_UNKNOWN          0x00       /* Do not save the link key */
#define BPT_NOT_SAVED        0x01       /* Do not save the link key */
#define BPT_SAVE_NOT_TRUSTED 0x02       /* Save the link key but make not trusted */
#define BPT_SAVE_TRUSTED     0x03       /* Save the link key and make trusted */

/* End of BtPairingType */

/*---------------------------------------------------------------------------
 * BtSecurityLevel type
 *
 *     Authorization and encryption require authentication. So if either of
 *     these two are set then authentication must also be set.
 */
typedef U8 BtSecurityLevel;

#define BSL_AUTHENTICATION_IN  0x01     /* Authentication on incoming required */
#define BSL_AUTHORIZATION_IN   0x02     /* Authorization on incoming required */
#define BSL_ENCRYPTION_IN      0x04     /* Encryption on incoming required */

#define BSL_AUTHENTICATION_OUT 0x08     /* Authentication on outgoing required */
#define BSL_AUTHORIZATION_OUT  0x10     /* Authorization on outgoing required */
#define BSL_ENCRYPTION_OUT     0x20     /* Encryption on outgoing required */

#define BSL_BROADCAST_IN       0x40     /* Reception of broadcast packets allowed */
#define BSL_NO_SECURITY        0x00

#define BSL_DEFAULT  (BSL_AUTHENTICATION_IN |  BSL_AUTHENTICATION_OUT)
#define BSL_DEFAULT_ALL  (BSL_AUTHENTICATION_IN |  BSL_AUTHENTICATION_OUT | BSL_ENCRYPTION_IN | BSL_ENCRYPTION_OUT)

/* End of BtSecurityLevel */

/*---------------------------------------------------------------------------
 * BtEncryptMode type
 */
typedef U8 BtEncryptMode;

#define BECM_ENCRYPT_DISABLE 0x00
#define BECM_ENCRYPT_ENABLE  0x01

/* End of BtEncryptMode */

/*---------------------------------------------------------------------------
 * BtSecurityMode type
 */
typedef U8 BtSecurityMode;

#define BSM_SEC_DISABLED    0x01
#define BSM_SEC_LEVEL_1     0x02
#define BSM_SEC_LEVEL_2     0x03
#define BSM_SEC_LEVEL_3     0x04
#define BSM_SEC_ENCRYPT     0x05

/* End of BtSecurityMode */

/****************************************************************************
 *
 * Data Structures
 *
 ****************************************************************************/

/*---------------------------------------------------------------------------
 * BtSecurityRecord structure
 *
 *     Security records are not stored in non-volatile memory.
 */
typedef struct _BtSecurityRecord
{
    ListEntry node; /* Used internally by the stack */

    /* Group: The user must fill in the three fields below */
    BtProtocolId id;
    U32 channel;
    BtSecurityLevel level;
    U8 level_type;

} BtSecurityRecord;

/*---------------------------------------------------------------------------
 * BtSecurityToken structure
 *
 *     Security tokens are used to request access by protocol
 *     layers and multiplexors.
 */
typedef struct _BtSecurityToken
{
    ListEntry node; /* Used internally by the stack */

    /*
     * Group: The following parameters must be set before calling
     * SEC_AccessRequest.
     */
    BtProtocolId id;    /* Protocol ID of caller */

    /* Pointer to remote device for which the access is being requested */
    BtRemoteDevice *remDev;

    /*
     * The multiplexing channel number. For example for L2CAP it is the PSM
     * and for RFCOMM it is the Server ID (incoming only) or a pointer to an
     * RfChannel structure (outgoing only).
     */
    U32 channel;

    /*
     * Incoming must be set to TRUE if access is desired for a connection
     * request from a remote (incoming). It must be set to FALSE if the
     * request is for a connection to remote device (outgoing).
     */
    BOOL incoming;

    /* Group: The stack uses the following fields are internally. */
    BtEventType result;
    BtSecurityRecord *record;
    BtSecurityLevel level;
    EvmTimer timer;
} BtSecurityToken;
#endif /* __SEC_ADP_H */

