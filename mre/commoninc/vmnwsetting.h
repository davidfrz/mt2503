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
 *
 * removed!
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *============================================================================== 
 *******************************************************************************/

#ifndef VM_BTCM_H
#define VM_BTCM_H

#include "vmswitch.h"

#ifdef __MRE_SAL_NWSETTING__

#include "vmnwsetting_sdk.h"

#else

#define vm_srv_wlan_connect_by_spec_prof (void*)NULL
#define vm_srv_wlan_disconnect (void*)NULL
#define vm_srv_wlan_status (void*)NULL
#define vm_srv_wlan_init_profile (void*)NULL
#define vm_srv_wlan_add_prof (void*)NULL
#define vm_srv_wlan_update_prof (void*)NULL
#define vm_srv_wlan_delete_prof (void*)NULL
#define vm_srv_wlan_query_prof (void*)NULL
#define vm_srv_wlan_query_prof_list (void*)NULL
#define vm_srv_wlan_set_scan_spec_ssid_list (void*)NULL
#define vm_srv_wlan_get_scan_spec_ssid_list (void*)NULL
#define vm_srv_wlan_get_connected_ap_bssid (void*)NULL
#define vm_srv_wlan_get_connected_ap_prof_id (void*)NULL
#define vm_srv_wlan_get_mac_address (void*)NULL
#define vm_srv_wlan_scan (void*)NULL
#define vm_srv_wlan_scan_abort (void*)NULL
#define vm_srv_wlan_set_roaming_para (void*)NULL
#define vm_srv_wlan_get_roaming_para (void*)NULL
#define vm_srv_wlan_set_scan_dwell_time (void*)NULL
#define vm_srv_wlan_get_scan_dwell_time (void*)NULL
#define vm_srv_wlan_get_ip_info (void*)NULL
#define vm_srv_wlan_switch (void*)NULL
#define vm_srv_wlan_sta_status (void*)NULL
#define vm_srv_wlan_sniffer_on (void*)NULL
#define vm_srv_wlan_sniffer_off (void*)NULL
#define vm_srv_wlan_set_reconn_prof_id (void*)NULL
#define vm_srv_wlan_get_reconn_prof_id (void*)NULL
#define vm_srv_wlan_reg_ip_available_noti (void*)NULL
#define vm_srv_wlan_dereg_ip_available_noti (void*)NULL
#define vm_srv_wlan_reg_passive_disconn_noti (void*)NULL
#define vm_srv_wlan_dereg_passive_disconn_noti (void*)NULL
#define vm_srv_wlan_get_connected_ap_rssi (void*)NULL


/* NEW */
#define vm_wlan_prof_init (void*)NULL
#define vm_wlan_prof_add (void*)NULL
#define vm_wlan_disconnect (void*)NULL
#define vm_wlan_prof_connect (void*)NULL
#define vm_wlan_get_connected_ap_info (void*)NULL
#define vm_wlan_prof_query (void*)NULL
#define vm_wlan_scan (void*)NULL
#define vm_wlan_scan_abort (void*)NULL
#define vm_wlan_prof_query_list (void*)NULL
#define vm_wlan_mode_get (void*)NULL
#define vm_wlan_prof_update (void*)NULL
#define vm_wlan_prof_delete (void*)NULL
#define vm_wlan_roaming_set (void*)NULL
#define vm_wlan_roaming_get (void*)NULL
#define vm_wlan_set_scan_spec_ssid_list (void*)NULL
#define vm_wlan_get_scan_spec_ssid_list (void*)NULL
#define vm_wlan_set_scan_dwell_time (void*)NULL
#define vm_wlan_mode_set (void*)NULL
#define vm_wlan_get_scan_dwell_time (void*)NULL
#define vm_wlan_get_mac_address (void*)NULL
#define vm_wlan_get_ip_info (void*)NULL
#define vm_wlan_status (void*)NULL
#define vm_wlan_sniffer_on (void*)NULL
#define vm_wlan_sniffer_off (void*)NULL
#define vm_wlan_prof_set_reconn_id (void*)NULL
#define vm_wlan_prof_get_reconn_id (void*)NULL
#define vm_wlan_reg_ip_available_noti (void*)NULL
#define vm_wlan_dereg_ip_available_noti (void*)NULL
#define vm_wlan_reg_passive_disconn_noti (void*)NULL
#define vm_wlan_dereg_passive_disconn_noti (void*)NULL

#define vm_wlan_connect (void*)NULL
#define vm_wlan_scan_set_param (void*)NULL
#define vm_wlan_scan_get_param (void*)NULL
#define vm_wlan_reg_noti (void*)NULL
#define vm_wlan_dereg_noti (void*)NULL

#define vm_wlan_set_para (void*)NULL
#define vm_wlan_get_para (void*)NULL

#define vm_wndrv_init (void*)NULL
#define vm_wndrv_deinit (void*)NULL
#define vm_wndrv_scan (void*)NULL
#endif /* __MRE_SAL_NWSETTING__ */

#endif /* VM_BTCM_H */


