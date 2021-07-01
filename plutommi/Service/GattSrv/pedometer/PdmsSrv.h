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
 *  PdmsSrvGprot.h
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
 * removed!
 * removed!
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PDMS_SRV_H__
#define __PDMS_SRV_H__


/****************************************************************************
 * Header
 ****************************************************************************/
#ifdef __MMI_BLE_PDMS_SUPPORT__ 

#include "bt_mmi.h"
#include "PdmsSrvGprot.h"
#include "Pdms_def.h"



/****************************************************************************
 * Define
 ****************************************************************************/
//#define PDMS_MAX_VALUE_LEN ATT_MAX_VALUE_LEN
#define PDMS_MAX_VALUE_LEN 20

#define SRV_PDMS_MAX_DEV         __BT_MAX_LE_LINK_NUM__

/****************************************************************************
 * Function
 ****************************************************************************/
/** BT-GATT Server callback structure. */
void pdms_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);
void pdms_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void pdms_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void pdms_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);

void pdms_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);

void pdms_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);
void pdms_add_services_callback(OS_STATUS status, void *reg_ctx);


#endif /*__MMI_BLE_PDMS_SUPPORT__ */

#endif/*__PDMS_SRV_H__*/

