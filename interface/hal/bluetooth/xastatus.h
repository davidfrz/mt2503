#ifndef __XASTATUS_H
#define __XASTATUS_H
/***************************************************************************
 *
 * File:
 *     $Workfile:xastatus.h$ for iAnywhere Blue SDK, Version 2.1.1
 *     $Revision:27$
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
#define MTK_STATUS_SCO_REJECT        27
#define MTK_STATUS_CHIP_REASON  28
#define MTK_STAUTS_BLOCK_LIST   29
#define MTK_STATUS_SCATTERNET_REJECT 30

/*
 * Protocol extensions can safely add status codes by defining
 * them as (XA_STATUS_OPEN + x).
 */
#define XA_STATUS_OPEN              30

/* End of XaStatus */
#endif  //__XASTATUS_H


