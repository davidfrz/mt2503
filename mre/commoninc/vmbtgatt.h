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

/*******************************************************************************
 * Filename:
 * ---------
 * vmbtgatt.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 * 
 *
*==============================================================================
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef VM_BTGATT_H
#define VM_BTGATT_H

#include "vmswitch.h"

#ifdef __MRE_SAL_BTGATT__

#include "vmbtgatt_sdk.h"

#else

#define vm_gatts_register (void*)NULL
#define vm_gatts_deregister (void*)NULL
#define vm_gatts_connect (void*)NULL
#define vm_gatts_disconnect (void*)NULL
#define vm_gatts_listen (void*)NULL
#define vm_gatts_add_service (void*)NULL
#define vm_gatts_add_included_service (void*)NULL
#define vm_gatts_add_characteristic (void*)NULL
#define vm_gatts_add_descriptor (void*)NULL
#define vm_gatts_start_service (void*)NULL
#define vm_gatts_stop_service (void*)NULL
#define vm_gatts_delete_service (void*)NULL
#define vm_gatts_send_indication (void*)NULL
#define vm_gatts_send_response (void*)NULL
#define vm_gatts_read_tx_power (void*)NULL

#define vm_gattc_register (void*)NULL
#define vm_gattc_deregister (void*)NULL
#define vm_gattc_scan (void*)NULL
#define vm_gattc_connect (void*)NULL
#define vm_gattc_disconnect (void*)NULL
#define vm_gattc_refresh (void*)NULL
#define vm_gattc_search_service (void*)NULL
#define vm_gattc_get_included_service (void*)NULL
#define vm_gattc_get_characteristic (void*)NULL
#define vm_gattc_get_descriptor (void*)NULL
#define vm_gattc_read_characteristic (void*)NULL
#define vm_gattc_write_characteristic (void*)NULL
#define vm_gattc_read_descriptor (void*)NULL
#define vm_gattc_write_descriptor (void*)NULL
#define vm_gattc_execute_write (void*)NULL
#define vm_gattc_register_for_notification (void*)NULL
#define vm_gattc_deregister_for_notification (void*)NULL
#define vm_gattc_read_remote_rssi (void*)NULL
#define vm_gattc_get_device_type (void*)NULL
#define vm_gattc_listen (void*)NULL
#define vm_gattc_set_adv_data (void*)NULL

#define vm_gatts_profile_factory_register (void*)NULL
#define vm_gatts_profile_factory_deregister (void*)NULL
#define vm_gatts_profile_factory_get_services (void*)NULL
#define vm_gatts_profile_factory_clear_services (void*)NULL
#define vm_gatts_profile_factory_add_services (void*)NULL
#define vm_gatts_profile_factory_delete_services (void*)NULL
#define vm_gatts_profile_factory_create_srv_list (void*)NULL
#define vm_gatts_profile_factory_delete_srv_list (void*)NULL
#define vm_gatts_set_adv_data (void*)NULL
#define vm_gattc_conn_param_update (void*)NULL
#define vm_gattc_set_adv_interval (void*)NULL

#endif /* __MRE_SAL_BTGATT__ */

#endif /* VM_BTGATT_H */

