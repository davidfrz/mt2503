/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
*  LAWS PRINCIPLES. ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *  WlanSrvIprot.h
 *
 * Project:
 * --------
 *  Venus
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __WLAN_SRV_IPROT_H__
#define __WLAN_SRV_IPROT_H__

#include "mmi_features.h"
// #if defined(__IOT__) && defined(__MMI_WLAN_FEATURES__)
#if defined(__TCPIP__) && defined(__MMI_WLAN_FEATURES__)

#include "WlanSrvGprot.h"
#include "DtcntSrvIntEnum.h"

#define SRV_WLAN_PASSPHRASE_KEY_LEN_MIN         8

#define SRV_WLAN_WEP_KEY_LENGTH_128BITS_HEX     26

#define SRV_WLAN_AP_WEP_KEY_LEN_FIVE         5
#define SRV_WLAN_AP_WEP_KEY_LEN_TEN          10
#define SRV_WLAN_AP_WEP_KEY_LEN_THIRTEEN     13
#define SRV_WLAN_AP_WEP_KEY_LEN_TWENTY_SIX   26

// For ssid and password
#define SRV_WLAN_ALLOWED_CHARACTERS   "\'+\\\\_\\-. @!#$%&*/=?(),:;[]<>\"^`{|}~"

// Static Ip
#define SRV_WLAN_STATIC_IP_ADDR     "192.168.1.69"
#define SRV_WLAN_GATEWAY_IP_ADDR    "192.168.1.1"
#define SRV_WLAN_NETMASK            "255.255.255.0"
//#define SRV_WLAN_DSN1_ADDR          "192.168.1.1"
//#define SRV_WLAN_DSN2_ADDR          "0.0.0.0"
#define SRV_WLAN_DSN1_ADDR          "168.95.1.1"
#define SRV_WLAN_DSN2_ADDR          "168.95.1.2"

#define SRV_WLAN_REG_MAX_NUM      10

typedef enum
{
    SRV_WLAN_JOB_INIT,
    SRV_WLAN_JOB_DEINIT,
    SRV_WLAN_JOB_CONNECT,
    SRV_WLAN_JOB_DISCONNECT,
    SRV_WLAN_JOB_SCAN,
    SRV_WLAN_JOB_SNIFFER_ON,
    SRV_WLAN_JOB_SNIFFER_NOTI_AP,
    SRV_WLAN_JOB_SNIFFER_OFF,

    SRV_WLAN_JOB_END,    
}srv_wlan_job_type_enum;


typedef enum
{
    EVT_ID_WLAN_IP_AVAILABLE_NOTI, 
        
    EVT_ID_WLAN_END
}srv_wlan_event_enum;

typedef enum
{
    SRV_WLAN_RES_MAP_SRC_DTCNT, 
    SRV_WLAN_RES_MAP_SRC_APMODE,
    SRV_WLAN_RES_MAP_SRC_SNIFFER,
        
    SRV_WLAN_RES_MAP_SRC_END
}srv_wlan_res_map_src_type;

typedef struct
{
    void *cb_func_ptr;
    void *user_data;
} srv_wlan_cb_struct;


typedef struct srv_wlan_action_job_st
{
    srv_wlan_job_type_enum job_type;
    void *cb_func_ptr;
    void *user_data;    
    struct srv_wlan_action_job_st *next;
} srv_wlan_action_job_struct;

typedef struct srv_wlan_reg_noti_st
{
    srv_wlan_noti_type_enum reg_type;
    void *cb_func_ptr;
    void *user_data;
} srv_wlan_reg_noti_struct;

typedef struct
{
    srv_wlan_set_mode_enum mode_switch_to;
    MMI_BOOL is_switching;    
    srv_wlan_action_job_struct *action_job_list;
    srv_wlan_ip_info_struct ip_info;
}srv_wlan_context;

extern MMI_BOOL srv_wlan_is_action_legal(const srv_dtcnt_wlan_action_enum action);

extern MMI_BOOL srv_wlan_w2dprof_map(
            srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
            const srv_wlan_prof_struct *const wlan_prof);

extern MMI_BOOL srv_wlan_d2wprof_map(
            srv_wlan_prof_struct *const wlan_prof, 
            const srv_dtcnt_prof_wlan_struct *const dtcnt_prof);

extern mmi_ret srv_wlan_connect_callback (mmi_event_struct *evt);

extern mmi_ret srv_wlan_disconnect_callback (mmi_event_struct *evt);

extern mmi_ret srv_wlan_init_callback (mmi_event_struct *evt);

extern mmi_ret srv_wlan_deinit_callback (mmi_event_struct *evt);

extern MMI_BOOL srv_wlan_prof_match(const srv_wlan_prof_struct *const prof1, const srv_wlan_prof_struct *const prof2);

extern srv_wlan_result_enum srv_wlan_add_prof_int(srv_dtcnt_prof_wlan_struct *dtcnt_prof, U32 *acc_prof_id);
extern srv_wlan_result_enum srv_wlan_update_dtcnt_prof(U32 fields, srv_dtcnt_prof_wlan_struct *prof);
extern srv_wlan_result_enum srv_wlan_query_dtcnt_prof(const U32 prof_id, U32 fields, srv_dtcnt_prof_wlan_struct *dtcnt_Prof);
extern mmi_ret srv_wlan_scan_callback(mmi_event_struct *evt);
extern void srv_wlan_add_action_job(srv_wlan_job_type_enum job_type, void *callback, void* user_data);
extern MMI_BOOL srv_wlan_need_do_action(srv_dtcnt_wlan_action_enum action);
extern void srv_wlan_switch_ap_on(void *user_data, srv_wlan_req_res_enum res);
extern void srv_wlan_switch_sta_on(S32 result, void *user_data);
extern void srv_wlan_switch_sta_off(S32 result, void *user_data);
extern void srv_wlan_sniffer_on_callback(void *user_data, srv_dtcnt_wlan_sniffer_on_res_struct *dtcnt_res);
extern void srv_wlan_sniffer_off_callback (void *user_data, srv_dtcnt_wlan_sniffer_res_enum res);
extern MMI_BOOL srv_wlan_reg_noti_int(srv_wlan_reg_noti_struct *reg_func);
extern MMI_BOOL srv_wlan_dereg_noti_int(srv_wlan_reg_noti_struct *reg_func);
/*****************************************************************************
 * FUNCTION
 *  srv_wlan_init
 * DESCRIPTION
 *  The function is used to init the WLAN services.
 *  1. If the WLAN service is ACTIVE already, return SRV_WLAN_RESULT_SUCCESS.
 *  2. After WLAN init process is done, SRV will callback APP with user_data.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the init operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  SRV_WLAN_RESULT_SUCCESS    : wlan service is active
 *  SRV_WLAN_RESULT_PROCESSING : the wlan service is activating, wait for callback notify.
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_init(
                        srv_wlan_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wlan_deinit
 * DESCRIPTION
 *  The function is used to deinit the WLAN services.
 *  1. If the WLAN service is INACTIVE already, return SRV_WLAN_RESULT_SUCCESS.
 *  2. After WLAN deinit process is done, SRV will callback APP with user_data.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the deinit operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURN VALUES
 *  SRV_WLAN_RESULT_SUCCESS    : wlan service is inactive
 *  SRV_WLAN_RESULT_PROCESSING : the wlan service is deactivating, wait for callback notify.
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_deinit(
                        srv_wlan_cb_func_ptr callback,
                        void *user_data);

/*****************************************************************************
 * FUNCTION
 *  srv_wlan_hswlan_authmode_cvt
 * DESCRIPTION
 *  Convert HS auth mode enum to Wlan auth mode enum.
 * PARAMETERS
 *  auth_mode : [IN]  srv_tethering_wifi_hs_auth_mode_enum when wlan2hs is false
                      srv_wlan_auth_mode_enum when wlan2hs is true
 *  wlan2hs   : [IN]  If true, convert wlan auth mode enum to hs auth mode enum.
 *                    If false, do the opposite operation.
 * RETURN VALUES
 *  >= 0 : Convert successfully. The return value is the corresponding auth mode enum.
 *  < 0  : Convertion failed. 
 *****************************************************************************/
extern S32 srv_wlan_hswlan_authmode_cvt(
    S32 auth_mode,
    MMI_BOOL wlan2hs);

extern void wlan_srv_wprof_trace(const srv_wlan_prof_struct * const wlan_prof);
extern void wlan_srv_dprof_trace(const srv_dtcnt_prof_wlan_struct * const dtcnt_prof);
extern void wlan_srv_scan_result_trace(U8 ap_list_num, srv_wlan_scan_ap_info_struct * ap_list);
extern void wlan_srv_aplist_trace(U8 ap_list_num, srv_dtcnt_ssid_struct *ap_list);
extern void wlan_srv_ip_info_trace(srv_wlan_ip_info_struct* ip_info);

#endif /* __IOT__ && __MMI_WLAN_FEATURES__ && __TCPIP__ */
#endif /* __WLAN_SRV_IPROT_H__ */