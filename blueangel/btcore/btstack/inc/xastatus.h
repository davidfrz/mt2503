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

#ifndef __XASTATUS_H
#define __XASTATUS_H
/***************************************************************************
 *
 * File:
 *     $Workfile:xastatus.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision: #1 $
 *
 * Description:
 *     Definition of status values for protocol stacks.
 *
 * Created:
 *     November 22, 1999
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
#include "bt_common.h"
#include "xatypes.h"


/*---------------------------------------------------------------------------
 *
 * Status of a stack operation or of the stack.
 */
typedef I8 XaStatus;

#define XA_STATUS_SUCCESS         0     /* Successful and complete */
#define XA_STATUS_FAILED          1     /* Operation failed */
#define XA_STATUS_PENDING         2     /* Successfully started but pending */
#define XA_STATUS_DISCONNECT      3     /* Link disconnected */
#define XA_STATUS_NO_LINK         4     /* No Link layer Connection exists */
#define XA_STATUS_IN_USE          5     /* Operation failed - already in use. */
/* IrDA specific return codes */
#define XA_STATUS_MEDIA_BUSY      6     /* IRDA: Media is busy */
#define XA_STATUS_MEDIA_NOT_BUSY  7     /* IRDA: Media is not busy */
#define XA_STATUS_NO_PROGRESS     8     /* IRDA: IrLAP not making progress */
#define XA_STATUS_LINK_OK         9     /* IRDA: No progress condition cleared */
#define XA_STATUS_SDU_OVERRUN    10     /* IRDA: Sent more data than current SDU size */
/* Bluetooth specific return codes */
#define XA_STATUS_BUSY              11
#define XA_STATUS_NO_RESOURCES      12
#define XA_STATUS_NOT_FOUND         13
#define XA_STATUS_DEVICE_NOT_FOUND  14
#define XA_STATUS_CONNECTION_FAILED 15
#define XA_STATUS_TIMEOUT           16
#define XA_STATUS_NO_CONNECTION     17
#define XA_STATUS_INVALID_PARM      18
#define XA_STATUS_IN_PROGRESS       19
#define XA_STATUS_RESTRICTED        20
#define XA_STATUS_INVALID_TYPE      21
#define XA_STATUS_HCI_INIT_ERR      22
#define XA_STATUS_NOT_SUPPORTED     23
#define XA_STATUS_CONTINUE          24
#define XA_STATUS_CANCELLED         25
#define XA_STATUS_NOSERVICES        26
#define MTK_STATUS_SCO_REJECT       27
#define MTK_STATUS_CHIP_REASON      28
#define MTK_STAUTS_BLOCK_LIST       29
#define MTK_STATUS_SCATTERNET_REJECT    30
#define MTK_STATUS_REMOTE_REJECT    31
#define MTK_STATUS_KEY_ERR          32
#define MTK_STATUS_CONNECTION_EXIST          33
/*
 * Protocol extensions can safely add status codes by defining
 * them as (XA_STATUS_OPEN + x).
 */
#define XA_STATUS_OPEN              30

/* End of XaStatus */

#endif /* __XASTATUS_H */

