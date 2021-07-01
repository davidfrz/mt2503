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
 * vmpromng.c
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

#ifndef VM_BTCM_H
#define VM_BTCM_H

#include "vmswitch.h"

#ifdef __MRE_SAL_BTCM__

#include "vmbtcm_sdk.h"

#else

#define vm_btcm_init (void*)NULL
#define vm_btcm_exit (void*)NULL
#define vm_btcm_get_power_status (void*)NULL
#define vm_btcm_switch_on (void*)NULL
#define vm_btcm_switch_off (void*)NULL
#define vm_btcm_srv_set_visibility (void*)NULL
#define vm_btcm_srv_get_visibility (void*)NULL
#define vm_btcm_search (void*)NULL
#define vm_btcm_search_abort (void*)NULL
#define vm_btcm_set_host_name (void*)NULL
#define vm_btcm_get_host_dev_info (void*)NULL
#define vm_btcm_get_dev_num (void*)NULL
#define vm_btcm_get_dev_info_by_index (void*)NULL
#define vm_bt_cm_release_all_conn (void*)NULL
#define vm_bt_cm_send_passkey (void*)NULL
#define vm_custom_set_bt_pairing_method (void*)NULL
#define vm_btcm_is_profile_connected (void*)NULL
#define vm_btcm_is_dev_busy (void*)NULL
#define vm_btcm_get_dev_info (void*)NULL
#define vm_ble_cm_init (void*)NULL
#define vm_ble_cm_exit (void*)NULL
#define vm_ble_cm_search (void*)NULL
#define vm_ble_cm_get_connected_dev_info (void*)NULL
#define vm_ble_cm_get_connected_dev_num (void*)NULL
#define vm_ble_cm_get_searched_dev_info (void*)NULL
#define vm_ble_cm_get_searched_dev_num (void*)NULL
#define vm_ble_cm_get_maxed_linked_num (void*)NULL
#define vm_ble_cm_disconnect_req (void*)NULL
#define vm_ble_cm_connect_req (void*)NULL
#define vm_ble_cm_search_abort (void*)NULL
#endif /* __MRE_SAL_BTCM__ */

#endif /* VM_BTCM_H */

