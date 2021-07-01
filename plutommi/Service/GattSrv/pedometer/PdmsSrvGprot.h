/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  PdmsAdpSrvGprot.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the Pedometer Profile.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 *
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef PDMS_SRV_GPROT_H
#define PDMS_SRV_GPROT_H

/****************************************************************************
 * Header
 ****************************************************************************/
#include "MMI_features.h"
/* auto add by kw_check begin */
#include "MMIDataType.h"
#include "kal_general_types.h"
/* auto add by kw_check end */
#include "bt_mmi.h"


/****************************************************************************
 * Define
 ****************************************************************************/
#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif


/****************************************************************************
 * Structure
 ****************************************************************************/
/** BT-Findme callback defination. */

/** Callback invoked in response to connect/disconnect for Monitor/Reporter*/
typedef void (*pdms_connection_state_callback)(char *bdaddr, int state);

/** Callback for start/stop alert level */
typedef S32 (*pdms_data_to_read_callback)(char *bd_addr, void* buf, U32 len);

/** Callback for remote side send read request */
typedef S32 (*pdms_read_data_request_callback)(char *bdaddr, void* buf, U32 len);


/* define proximity monitor role callback funtion*/
typedef struct
{
    pdms_connection_state_callback           connection_state_cb;
    pdms_data_to_read_callback               data_to_read_notify_cb;
    pdms_read_data_request_callback          read_data_request_cb;
}pdms_callback_t;


/****************************************************************************
 * Function
 ****************************************************************************/
/*****************************************************************************
 * FUNCTION
 *  pdms_init
 * DESCRIPTION
 *  This function is to let pedometer app init pdms server callback
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  BTStatus
 *****************************************************************************/
extern S32 pdms_init(pdms_callback_t *cb);
/*****************************************************************************
 * FUNCTION
 *  srv_pdms_adp_read
 * DESCRIPTION
 *  This function is to let pedometer app deinit pdms server callback
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  BTStatus
 *****************************************************************************/
extern S32 pdms_deinit();
/*****************************************************************************
 * FUNCTION
 *  srv_pdms_adp_read
 * DESCRIPTION
 *  This function is to let pedometer app send data to remote
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
extern S32 pdms_send_data(char* bdaddr,void* buf, U32 len, S32 *err_code);



/* DOM-NOT_FOR_SDK-END */


#endif /* PDMS_SRV_GPROT_H */

