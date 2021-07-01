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
 *  WlanSrvApi.c
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
#include "mmi_features.h"
// #if defined(__IOT__) && defined(__MMI_WLAN_FEATURES__)

#include "DtcntSrvIprot.h"
#include "mmi2abm_struct.h"
#include "WiFiApSrvGprot.h"
#include "mmi_frm_mem_gprot.h"
#include "Mmi_frm_nvram_gprot.h"
#include "Mmi_cb_mgr_gprot.h"
#include "MMI_conn_app_trc.h"
#include "MMI_trc_int.h"
#include "kal_trace.h"
#include "WlanSrvIprot.h"
#include "WlanSrvGprot.h"
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__)
#include "mmi_rp_srv_wlan_def.h"
#endif
#include "wndrv_cal.h"
#include "nvram_common_defs.h"
#include "common_nvram_editor_data_item.h"

/***************************************************************************** 
* Global Variable
*****************************************************************************/
#if defined (__MMI_WLAN_FEATURES__) && defined(__TCPIP__)
extern srv_wlan_context g_srv_wlan_cntx;
#endif

//TODO: srv_apmode_get_mac_address is wrapped by __IOT__ in tetheringSrvApi.c 
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
extern void srv_apmode_get_mac_address(void *mac_addr);
#endif

/**********************************************************/
/* Service External Interfaces                            */
/**********************************************************/
srv_wlan_result_enum srv_wlan_connect_by_spec_prof(
    U32 prof_id,
    srv_wlan_conn_res_cb_func_ptr callback,
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_BOOL is_legal = MMI_FALSE; 
    srv_dtcnt_wlan_conn_prof_struct connProfile;    
    srv_dtcnt_prof_wlan_struct *dtcnt_prof;
    srv_wlan_conn_res_struct *conn_res;
    srv_wlan_result_enum result;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_CONNECT_PROF, prof_id);

    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_CONNECT);
    if (!is_legal)
    {
        result = SRV_WLAN_RESULT_STATE_ERROR;
    }        
    else
    {
        dtcnt_prof = get_ctrl_buffer(sizeof(srv_dtcnt_prof_wlan_struct));
        memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));
        result = (srv_wlan_result_enum)srv_wlan_query_dtcnt_prof(prof_id, SRV_DTCNT_PROF_FIELD_ALL, dtcnt_prof);
        if (SRV_DTCNT_RESULT_SUCCESS == result)
        {
            connProfile.num_prof  = 1;
            connProfile.prof_data = &dtcnt_prof;
            connProfile.connect_type = ONE_PROFILE_SELECT;

            MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN SRV API] conn prof - ssid: %s", dtcnt_prof->ssid);
            MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN SRV API] conn prof - auth mode: %d, pwd: %s", dtcnt_prof->auth_mode, dtcnt_prof->passphrase);
            
            srv_wlan_add_action_job(SRV_WLAN_JOB_CONNECT, (void*)callback, user_data);            
            mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND, srv_wlan_connect_callback, NULL);
            result = (srv_wlan_result_enum)srv_dtcnt_wlan_connect_by_app_prof(&connProfile, NULL, NULL);            
            free_ctrl_buffer(dtcnt_prof);
            return result;
        }
        free_ctrl_buffer(dtcnt_prof);        
    }
    
    if (callback)
    {
        conn_res = OslMalloc(sizeof(srv_wlan_conn_res_struct));
        memset(conn_res, 0, sizeof(srv_wlan_conn_res_struct));
        conn_res->result = result;
        conn_res->cause = SRV_WLAN_INVALID_CAUSE;
        callback(user_data, conn_res);
        OslMfree(conn_res);
    }
    
    return result;    
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_connect(
    srv_wlan_ap_info_struct *ap_info, 
    srv_wlan_conn_res_cb_func_ptr callback,
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_prof_struct *wlan_prof = NULL;
    srv_dtcnt_prof_wlan_struct* dtcnt_prof = NULL;
    MMI_BOOL is_legal, ret;
    srv_dtcnt_wlan_conn_prof_struct connProfile;
    srv_wlan_result_enum result;
    srv_wlan_conn_res_struct *conn_res;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_CONNECT);
    
    if (!ap_info)
    {
        result = SRV_WLAN_RESULT_INVALID_INPUT;
        goto conn_err_hdl;
    }

    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_CONNECT);
    if (!is_legal)
    {
        result = SRV_WLAN_RESULT_STATE_ERROR;
        goto conn_err_hdl;
    }   

    wlan_prof = (srv_wlan_prof_struct*)get_ctrl_buffer(sizeof(srv_wlan_prof_struct));
    memset(wlan_prof, 0, sizeof(srv_wlan_prof_struct));

    memcpy(wlan_prof->ssid, ap_info->ssid, SRV_WLAN_PROF_MAX_SSID_LEN);
    memcpy(wlan_prof->password, ap_info->password, SRV_WLAN_PROF_PSWD_MAX_LEN);
    wlan_prof->auth_mode = ap_info->auth_mode;

    dtcnt_prof = srv_dtcnt_get_wlan_conn_prof();
    memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    ret = srv_wlan_w2dprof_map(dtcnt_prof, wlan_prof); 
    dtcnt_prof->profile_id = 0xFFFFFFFF;

    if (ret)
    {
        connProfile.num_prof = 1;
        connProfile.prof_data = &dtcnt_prof;
        connProfile.connect_type = ONE_PROFILE_SELECT;

        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN SRV API] conn prof - ssid: %s", dtcnt_prof->ssid);
        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN SRV API] conn prof - auth mode: %d, pwd: %s", dtcnt_prof->auth_mode, dtcnt_prof->passphrase);
        
        srv_wlan_add_action_job(SRV_WLAN_JOB_CONNECT, (void*)callback, user_data);            
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND, srv_wlan_connect_callback, NULL);
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_connect_by_app_prof(&connProfile, NULL, NULL);

        free_ctrl_buffer(wlan_prof);
        
        return result;
    }
    else
    {        
        result = SRV_WLAN_RESULT_INVALID_INPUT;
        goto conn_err_hdl;
    }

conn_err_hdl:
    if (callback)
    {
        conn_res = OslMalloc(sizeof(srv_wlan_conn_res_struct));
        memset(conn_res, 0, sizeof(srv_wlan_conn_res_struct));
        conn_res->result = result;
        conn_res->cause = SRV_WLAN_INVALID_CAUSE;
        callback(user_data, conn_res);
        OslMfree(conn_res);
    }
    
    if (wlan_prof)
    {
        free_ctrl_buffer(wlan_prof);
    }
   
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_disconnect(srv_wlan_cb_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_BOOL is_legal = MMI_FALSE; 
    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_DISCONN);
    
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_DISCONNECT);
    if (is_legal)
    {
        srv_wlan_add_action_job(SRV_WLAN_JOB_DISCONNECT, (void*)callback, user_data);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND, srv_wlan_disconnect_callback, NULL);
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_disconnect();
    }
    else
    {
        result = SRV_WLAN_RESULT_STATE_ERROR;        
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_FAILED);
        }
    }   

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


void srv_wlan_init_profile(srv_wlan_prof_struct *wlan_prof)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_INI_PROF);
    
    if (!wlan_prof)
    {
        return;
    }
    
    memset(wlan_prof, 0, sizeof(srv_wlan_prof_struct));
    wlan_prof->auth_mode = SRV_WLAN_AUTH_MODE_OPEN;
#endif 
    return;   
}


srv_wlan_result_enum srv_wlan_add_prof(const srv_wlan_prof_struct *wlan_prof, U32 *prof_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)
    MMI_BOOL ret;
    srv_wlan_result_enum result;
    srv_wlan_prof_list_struct prof_list = {0};
    srv_wlan_prof_struct *stored_prof = NULL;
    srv_dtcnt_prof_wlan_struct *dtcnt_prof = NULL;
    U8 index;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_ADD_PROF);
    
    wlan_srv_wprof_trace(wlan_prof);
    if (!wlan_prof || !prof_id)
    {        
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    *prof_id = 0;

    /* Check if the profile has already existed. */
    result = srv_wlan_query_prof_list(&prof_list);
    if (SRV_DTCNT_RESULT_SUCCESS == result)
    {
        stored_prof = (srv_wlan_prof_struct *)get_ctrl_buffer(sizeof(srv_wlan_prof_struct));
        memset(stored_prof, 0, sizeof(srv_wlan_prof_struct));
        
        for (index = 0; index < prof_list.num_ids; index++)
        {
            result = srv_wlan_query_prof(prof_list.ids[index], stored_prof);
            if (SRV_DTCNT_RESULT_SUCCESS != result)
            {                
                free_ctrl_buffer(stored_prof);
                return result;
            }
            
            if (srv_wlan_prof_match(wlan_prof, stored_prof))
            {
                *prof_id = stored_prof->profile_id;                
                free_ctrl_buffer(stored_prof);
                result = SRV_WLAN_RESULT_ONE_STORE_EXISTS;
                MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_ADD_PROF_RET, *prof_id, result);
                return result;
            }
        }
        free_ctrl_buffer(stored_prof);
    }
    else
    {        
        return result;
    }

    /* Map the wlan srv profile into dtcnt srv profile. */
    dtcnt_prof = (srv_dtcnt_prof_wlan_struct *)get_ctrl_buffer(sizeof(srv_dtcnt_prof_wlan_struct));
    memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    ret = srv_wlan_w2dprof_map(dtcnt_prof, wlan_prof); 
    if (!ret)
    {
        free_ctrl_buffer(dtcnt_prof);        
        return SRV_WLAN_RESULT_FAILED;
    }

    // Add the wlan srv profile into dtcnt srv.
    result = srv_wlan_add_prof_int(dtcnt_prof, prof_id);

    free_ctrl_buffer(dtcnt_prof);
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_ADD_PROF_RET, *prof_id, result);

    return result;    
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}

srv_wlan_result_enum srv_wlan_update_prof(
    U32 prof_id, 
    const srv_wlan_prof_struct *wlan_prof,
    U32 prof_fields)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_dtcnt_store_prof_data_struct prof_data;
    srv_dtcnt_prof_wlan_struct *dtcnt_prof;
    srv_wlan_result_enum result;
    MMI_BOOL ret;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_UPD_PROF, prof_id);

    /* Map wlan prof and dtcnt prof */
    dtcnt_prof = get_ctrl_buffer(sizeof(srv_dtcnt_prof_wlan_struct));
    memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));
    ret = srv_wlan_w2dprof_map(dtcnt_prof, wlan_prof);
    if (ret)
    {
        /* Map the prof_fields */
        if ((SRV_WLAN_PROF_FIELD_PW & prof_fields) && (SRV_WLAN_PROF_FIELD_ALL != prof_fields))
        {
            switch (wlan_prof->auth_mode)
            {
                case SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
                case SRV_WLAN_AUTH_MODE_WPA_ONLY_PSK:
                {
                    prof_fields &= ~SRV_DTCNT_WLAN_PROF_FIELD_PW;
                    prof_fields |= SRV_DTCNT_WLAN_PROF_FIELD_PASSPHRASE;
                    break;
                }
                case SRV_WLAN_AUTH_MODE_WEP:
                {
                    prof_fields &= ~SRV_DTCNT_WLAN_PROF_FIELD_PW;
                    prof_fields |= SRV_DTCNT_WLAN_PROF_FIELD_WEP_KEY_SETTINGS;
                    break;
                }
                default:
                    break;
            }
        }
        
        /* Fill prof_data for dtcnt update API */
        prof_data.prof_data = dtcnt_prof;
        prof_fields &= ~SRV_DTCNT_WLAN_PROF_FIELD_PRIORITY;
        prof_data.prof_fields = prof_fields;
        prof_data.prof_type = SRV_DTCNT_BEARER_WIFI;

        /* Update profile */
        result = (srv_wlan_result_enum)srv_dtcnt_store_update_prof(prof_id, &prof_data);    
    }
    else
    {
        result = SRV_WLAN_RESULT_INVALID_INPUT;
    }
        
    free_ctrl_buffer(dtcnt_prof);
    
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_delete_prof(U32 prof_id)
{    
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_dtcnt_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_DEL_PROF, prof_id);
    result = srv_dtcnt_store_delete_prof(prof_id, MMI_TRUE, NULL, NULL);
    return (srv_wlan_result_enum)result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_query_prof(U32 prof_id, srv_wlan_prof_struct * wlan_prof)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_dtcnt_prof_wlan_struct *dtcnt_prof;
    srv_wlan_result_enum result;    

    if (!wlan_prof || CBM_DEFAULT_ACCT_ID >= prof_id)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }
        
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_QRY_PROF, prof_id);
    dtcnt_prof = get_ctrl_buffer(sizeof(srv_dtcnt_prof_wlan_struct));
    memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));    
    result = srv_wlan_query_dtcnt_prof(prof_id, SRV_DTCNT_PROF_FIELD_ALL, dtcnt_prof);
    
    if (SRV_WLAN_RESULT_SUCCESS == result)
    {
        if (!srv_wlan_d2wprof_map(wlan_prof, dtcnt_prof))
        {
            result = SRV_WLAN_RESULT_FAILED;
        }
        else
        {
             wlan_srv_wprof_trace(wlan_prof);
        }
    }

    free_ctrl_buffer(dtcnt_prof);    

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_query_prof_list(srv_wlan_prof_list_struct * prof_list)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_qry_struct acct_id_query = {0};
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_QRY_PROF_LIST);

    if (!prof_list)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    memset(prof_list, 0, sizeof(srv_wlan_prof_list_struct));
    acct_id_query.qry_info.filters = SRV_DTCNT_STORE_QRY_TYPE_BEARER_TYPE;
    acct_id_query.qry_info.bearer_qry_info = SRV_DTCNT_BEARER_WIFI;
    result = srv_dtcnt_store_qry_ids(&acct_id_query);
    if (SRV_DTCNT_RESULT_SUCCESS == result)
    {
        memcpy(prof_list->ids, acct_id_query.ids, SRV_DTCNT_STORE_IDS_QRY_MAX_SIZE * sizeof(U32));
        prof_list->num_ids = acct_id_query.num_ids;
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_QRY_PROF_LIST_RET, prof_list->num_ids, result);

    return (srv_wlan_result_enum)result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


MMI_BOOL srv_wlan_get_connected_ap_bssid(srv_wlan_prof_str_info_qry_struct * bssid)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_CONN_AP_BSSID);
    
    if (!bssid)
    {
        return MMI_FALSE;
    }

    if (!bssid->dest || SRV_WLAN_WNDRV_MAC_ADDRESS_LEN > bssid->dest_len)
    {
        bssid->req_len = SRV_WLAN_WNDRV_MAC_ADDRESS_LEN;        
        return MMI_FALSE;
    }

    memset(bssid->dest, 0, bssid->dest_len);
    return srv_dtcnt_wlan_get_connected_ap_bssid((U8*)bssid->dest);
#else
    return MMI_FALSE;
#endif
}


MMI_BOOL srv_wlan_get_connected_ap_prof_id(U32 * prof_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_CONN_PROF_ID);

    return srv_dtcnt_wlan_get_connected_ap_prof_id(prof_id);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_get_connected_ap_rssi(S32 *rssi_out)
{    
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_CONN_AP_RSSI);
    
    return srv_dtcnt_wlan_get_connected_ap_rssi(rssi_out);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_get_connected_ap_info(void *info, S32 info_type)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_BOOL ret = MMI_FALSE;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_CONN_AP_INFO, info_type);
    if (!info)
    {
        return MMI_FALSE;
    }
    
    switch (info_type)
    {
        case SRV_WLAN_AP_INFO_BSSID:
        {
            memset(info, 0, SRV_WLAN_WNDRV_MAC_ADDRESS_LEN + 1);
            ret = srv_dtcnt_wlan_get_connected_ap_bssid((U8*)info);
            MMI_PRINT(
                MOD_MMI_CONN_APP, 
                TRACE_GROUP_7, 
                "[WLAN SRV API] Get ap info ret: %d. Bssid of connected AP: %d", 
                ret,
                (U8*)info);
            return ret;
        }
        
        case SRV_WLAN_AP_INFO_PROF_ID:
        {            
            ret = srv_dtcnt_wlan_get_connected_ap_prof_id((U32*)info);
            MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_CONN_PROF_ID, ret, *(U32*)info);
            return ret;
        }
        
        case SRV_WLAN_AP_INFO_RSSI:
        {
            ret = srv_dtcnt_wlan_get_connected_ap_rssi((S32*)info);
            MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_CONN_AP_RSSI, ret, *(S32*)info);
            return ret;
        }
        
        case SRV_WLAN_AP_INFO_ALL:
        {
            MMI_BOOL ret = MMI_TRUE;
            
            srv_wlan_conned_ap_info_struct *ap_info = (srv_wlan_conned_ap_info_struct *)info;
            memset(ap_info, 0, sizeof(srv_wlan_conned_ap_info_struct));
            
            ret = srv_wlan_get_connected_ap_info(ap_info->bssid, SRV_WLAN_AP_INFO_BSSID);
            if (!ret)
            {
                memset(ap_info, 0, sizeof(srv_wlan_conned_ap_info_struct));
                return MMI_FALSE;
            }

            ret = srv_wlan_get_connected_ap_info(&(ap_info->prof_id), SRV_WLAN_AP_INFO_PROF_ID);
            if (!ret)
            {
                memset(ap_info, 0, sizeof(srv_wlan_conned_ap_info_struct));
                return MMI_FALSE;
            }

            ret = srv_wlan_get_connected_ap_info(&(ap_info->rssi_out), SRV_WLAN_AP_INFO_RSSI);
            if (!ret)
            {
                memset(ap_info, 0, sizeof(srv_wlan_conned_ap_info_struct));
                return MMI_FALSE;
            }
            return MMI_TRUE;
        }

        default:
            return MMI_FALSE;
    }
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_get_mac_address(srv_wlan_prof_str_info_qry_struct *mac_address_out)
{   
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) \
    && defined(__TCPIP__)

    S16 error;
    wndrv_cal_mac_addr_struct nvram_record;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_MAC_ADDR);

    if(!mac_address_out)
    {
        return MMI_FALSE;
    }

    mac_address_out->req_len = SRV_WLAN_WNDRV_MAC_ADDRESS_LEN;
    if (mac_address_out->dest_len < SRV_WLAN_WNDRV_MAC_ADDRESS_LEN || !mac_address_out->dest)
    {
        return MMI_FALSE;
    }
    else
    {
        ReadRecord(
            NVRAM_EF_WNDRV_MAC_ADDRESS_LID,
            1,
            &nvram_record,
            NVRAM_EF_WNDRV_MAC_ADDRESS_SIZE,
            &error);

        memcpy(
            mac_address_out->dest,
            nvram_record.mac_addr,
            sizeof(U8) * 6);
    }   
    
    return MMI_TRUE;
#else
    return MMI_FALSE;
#endif
}


U32 srv_wlan_scan(srv_wlan_scan_res_cb_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_BOOL is_legal = MMI_FALSE;
    U32 scan_job_id = 0;
    srv_wlan_scan_result_struct *scan_res;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SCAN);
    
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_SCAN);
    if (is_legal)
    {
        scan_job_id = srv_dtcnt_wlan_scan(NULL, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND, srv_wlan_scan_callback, NULL);
        srv_wlan_add_action_job(SRV_WLAN_JOB_SCAN, (void*)callback, user_data);
    }    
    else
    {        
        if (callback)
        {
            scan_res = OslMalloc(sizeof(srv_wlan_scan_result_struct));
            scan_res->result = SRV_WLAN_SCAN_RESULT_FAILED;
            scan_res->ap_list_num = 0;
            memset(scan_res->ap_list, 0, sizeof(scan_res->ap_list));
            scan_res->scan_job_id = 0;
            callback(0, user_data, scan_res);
            OslMfree(scan_res);
        }
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SCAN_JOB_ID, scan_job_id);
    return scan_job_id;
#else
    return 0;
#endif
}


void srv_wlan_scan_abort(U32 job_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    // Can't use in sniffer mode
    srv_dtcnt_wlan_scan_abort(job_id);
#endif
}


srv_wlan_result_enum srv_wlan_set_scan_spec_ssid_list(
    U8 ssid_list_num, 
    const srv_wlan_ssid_struct ssid_list[],
    srv_wlan_cb_func_ptr callback,
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SET_SPEC_SSID_LIST);
    if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_FAILED);
        }
        return SRV_WLAN_RESULT_STATE_ERROR;
    }

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SPEC_SSID_LIST);
    wlan_srv_aplist_trace(ssid_list_num, (srv_dtcnt_ssid_struct*)ssid_list);
    
    result = (srv_wlan_result_enum)srv_dtcnt_wlan_set_scan_spec_ssid_list(
                                        ssid_list_num,
                                        (srv_dtcnt_ssid_struct*)ssid_list, 
                                        (srv_dtcnt_wlan_cb_func_ptr)callback, 
                                        user_data);
        
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_get_scan_spec_ssid_list(
    U8 *ssid_list_num, 
    srv_wlan_ssid_struct ssid_list[])    
{   
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_SPEC_SSID_LIST);

    if (!ssid_list_num || !ssid_list)
    {
    
        result = SRV_WLAN_RESULT_INVALID_INPUT;
    }
    else
    {
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_get_scan_spec_ssid_list(
                                        ssid_list_num, 
                                        (srv_dtcnt_ssid_struct*)ssid_list);        

        /* Trace */
        if (SRV_WLAN_RESULT_SUCCESS == result)
        {
            wlan_srv_aplist_trace(*ssid_list_num, (srv_dtcnt_ssid_struct*)ssid_list);
        }
    }   
    
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_set_roaming_para(
    MMI_BOOL enable_roaming, 
    srv_wlan_cb_func_ptr callback, 
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SET_ROAMING_PARA, enable_roaming);
    
    /* Everytime wlan is initialized, the para will be inilialized to the default value. */
    if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_FAILED);
        }
        result = SRV_WLAN_RESULT_STATE_ERROR;
    }
    else
    {
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_set_roaming_para(
                                            enable_roaming, 
                                            (srv_dtcnt_wlan_cb_func_ptr)callback, 
                                            user_data);
    }
    
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_get_roaming_para(MMI_BOOL * is_roaming)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_ROAMING_PARA);

    if (!is_roaming)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    result = (srv_wlan_result_enum)srv_dtcnt_wlan_get_roaming_para(is_roaming);
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_ROAMING_PARA_RET, *is_roaming, result);

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_set_scan_dwell_time(
    U16 dwell_time,
    srv_wlan_cb_func_ptr callback, 
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SET_DWELL_TIME, dwell_time);

    
    /* Everytime wlan is initialized, the para will be inilialized to the default value. */
    if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_FAILED);
        }
        result = SRV_WLAN_RESULT_STATE_ERROR;
    }
    else
    {
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_set_scan_dwell_time(
                                             dwell_time, 
                                             (srv_dtcnt_wlan_cb_func_ptr)callback, 
                                             user_data);        
    }

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_get_scan_dwell_time(U16 *dwell_time)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_DWELL_TIME);

    if (!dwell_time)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }    

    result = (srv_wlan_result_enum)srv_dtcnt_wlan_get_scan_dwell_time(dwell_time);
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_DWELL_TIME_RET, *dwell_time, result);
    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_set_scan_param(
    void *param, 
    S32 param_type, 
    srv_wlan_cb_func_ptr callback, 
    void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SET_SCAN_PARAM, param_type);

    if (!param)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    /* Everytime wlan is initialized, the para will be inilialized to the default value. */
    if (SRV_DTCNT_WLAN_STATUS_INACTIVE == srv_dtcnt_wlan_status())
    {
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_FAILED);
        }
        
        return SRV_WLAN_RESULT_STATE_ERROR;
    }

    switch (param_type)
    {
        case SRV_WLAN_SCAN_PARAM_DWELL_TIME:
        {
            return (srv_wlan_result_enum)srv_dtcnt_wlan_set_scan_dwell_time(
                                             *(U16*)param, 
                                             (srv_dtcnt_wlan_cb_func_ptr)callback, 
                                             user_data);
        }
        
        case SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST:
        {
            srv_wlan_spec_ssid_list_struct* spec_ssid_list = (srv_wlan_spec_ssid_list_struct*)param;
            return (srv_wlan_result_enum)srv_dtcnt_wlan_set_scan_spec_ssid_list(
                                        spec_ssid_list->ssid_list_num,
                                        (srv_dtcnt_ssid_struct*)spec_ssid_list->ssid_list, 
                                        (srv_dtcnt_wlan_cb_func_ptr)callback, 
                                        user_data);
        }
#if 0        
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            return SRV_WLAN_RESULT_INVALID_INPUT;
    }
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_get_scan_param(void *param, S32 param_type)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_SCAN_PARAM, param_type);

    if (!param)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    switch (param_type)
    {
        case SRV_WLAN_SCAN_PARAM_DWELL_TIME:
        {
            return (srv_wlan_result_enum)srv_dtcnt_wlan_get_scan_dwell_time((U16*)param);
        }

        case SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST:
        {
            srv_wlan_result_enum result;
            srv_wlan_spec_ssid_list_struct* spec_ssid_list = (srv_wlan_spec_ssid_list_struct*)param;
            U32 index;
            
            result = (srv_wlan_result_enum)srv_dtcnt_wlan_get_scan_spec_ssid_list(
                                            &(spec_ssid_list->ssid_list_num),
                                            (srv_dtcnt_ssid_struct*)spec_ssid_list->ssid_list);
            
            if (SRV_WLAN_RESULT_SUCCESS == result)
            {
                spec_ssid_list->ssid_list_num = 0;
                for (index = 0; index < SRV_WLAN_MAX_SPEC_SSID_LIST_NUM; index++)
                {
                    if (spec_ssid_list->ssid_list[index].ssid_len)
                    {
                        spec_ssid_list->ssid_list_num++;
                    }
                }
            }
            
            return result;
        }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        default:
            return SRV_WLAN_RESULT_INVALID_INPUT;
    }
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_get_ip_info(srv_wlan_ip_info_struct* ip_info)
{    
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_IP_INFO);

    if (!ip_info)
    {
        return SRV_WLAN_RESULT_INVALID_INPUT;
    }

    if (SRV_DTCNT_WLAN_STATUS_CONNECTED != srv_dtcnt_wlan_status())
    {
        return SRV_WLAN_RESULT_STATE_ERROR;
    }

    memcpy(ip_info->ip_addr, g_srv_wlan_cntx.ip_info.ip_addr, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(ip_info->netmask, g_srv_wlan_cntx.ip_info.netmask, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(ip_info->gateway, g_srv_wlan_cntx.ip_info.gateway, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(ip_info->dns1, g_srv_wlan_cntx.ip_info.dns1, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(ip_info->dns2, g_srv_wlan_cntx.ip_info.dns2, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    
    wlan_srv_ip_info_trace(ip_info);
    
    return SRV_WLAN_RESULT_SUCCESS;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


void srv_wlan_switch(srv_wlan_set_mode_enum mode, srv_wlan_cb_func_ptr callback, void *user_data)
{  
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_cb_struct *cb;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SWITCH, mode);
    
    if (MMI_TRUE == g_srv_wlan_cntx.is_switching)
    {
        if (callback)
        {
            callback(user_data, SRV_WLAN_REQ_RES_BUSY);
        }
        return;
    }

    g_srv_wlan_cntx.is_switching = MMI_TRUE;
    g_srv_wlan_cntx.mode_switch_to = mode;
    switch(mode)
    {
        #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
        case SRV_WLAN_SET_MODE_AP:
        {
            cb = OslMalloc(sizeof(srv_wlan_cb_struct));
            cb->cb_func_ptr = (void*)callback;
            cb->user_data = user_data;
            if (srv_wlan_need_do_action(SRV_DTCNT_WLAN_ACTION_DEINIT))
            {   
                /* Need to close STA Mode */
                srv_wlan_deinit(srv_wlan_switch_ap_on, cb);
                //srv_dtcnt_wlan_deinit(srv_wlan_switch_ap_on_sta_off_cb, cb);                
                break;
            }

            srv_wlan_switch_ap_on(cb, SRV_WLAN_REQ_RES_DONE);
                        
            break;
        }
        #endif
        
        case SRV_WLAN_SET_MODE_STA:
        {
            cb = OslMalloc(sizeof(srv_wlan_cb_struct));
            cb->cb_func_ptr = (void*)callback;
            cb->user_data = user_data;
            
            #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
            if (srv_apmode_is_on() == MMI_TRUE)
            {   
                /* Need to close AP Mode */
                srv_apmode_switch_off(srv_wlan_switch_sta_on, cb);
                break;
            }

            srv_wlan_switch_sta_on(SRV_APMODE_OK, cb);
            #else
            srv_wlan_switch_sta_on(NULL, cb);
            #endif
            
            break;
        }
        
        #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
        case SRV_WLAN_SET_MODE_AP_STA:
        {
            cb = OslMalloc(sizeof(srv_wlan_cb_struct));
            cb->cb_func_ptr = (void*)callback;
            cb->user_data = user_data;
            if (srv_apmode_is_on() == MMI_FALSE)
            {   
                /* Need to close AP Mode */
                srv_apmode_switch_on(srv_wlan_switch_sta_on, cb);
                break;
            }

            srv_wlan_switch_sta_on(SRV_APMODE_OK, cb);
            
            break;
        }
        #endif
        
        case SRV_WLAN_SET_MODE_OFF:
        {
            cb = OslMalloc(sizeof(srv_wlan_cb_struct));
            cb->cb_func_ptr = (void*)callback;
            cb->user_data = user_data;
            #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
            if (srv_apmode_is_on() == MMI_TRUE)
            {   
                /* Need to close AP Mode */
                srv_apmode_switch_off(srv_wlan_switch_sta_off, cb);
                break;
            }
            
            srv_wlan_switch_sta_off(SRV_APMODE_OK, cb);
            #else
            srv_wlan_switch_sta_off(NULL, cb);
            #endif
            
            break;
        }
            
        default:
        {            
            g_srv_wlan_cntx.mode_switch_to = SRV_WLAN_SET_MODE_NONE;
            g_srv_wlan_cntx.is_switching = MMI_FALSE;
            if (callback)
            {
                callback(user_data, SRV_WLAN_REQ_RES_FAILED);
            }
            break;
        }
    }
#endif    
}


srv_wlan_mode_status_enum srv_wlan_status(void)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_mode_status_enum mode_status;
    srv_dtcnt_wlan_status_enum sta_status;
    
    if (!g_srv_wlan_cntx.is_switching)
    {
        sta_status = srv_dtcnt_wlan_status();
        /* Switch may fail. So mode_switch_to shouldn't be used to represent the current status. */
        #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
        if (srv_apmode_is_on() == MMI_TRUE)
        {            
            if (SRV_DTCNT_WLAN_STATUS_INACTIVE == sta_status)
            {
                mode_status = SRV_WLAN_MODE_STATUS_AP;
            }
            else
            {
                mode_status = SRV_WLAN_MODE_STATUS_AP_STA;
            }
        }
        else
        #endif
        {
            if (SRV_DTCNT_WLAN_STATUS_INACTIVE == sta_status)
            {
                mode_status = SRV_WLAN_MODE_STATUS_OFF;
            }
            else
            {
                mode_status = SRV_WLAN_MODE_STATUS_STA;
            }
        }
    }
    else
    {
        switch (g_srv_wlan_cntx.mode_switch_to)
        {
            case SRV_WLAN_SET_MODE_AP:
            {                
                mode_status = SRV_WLAN_MODE_STATUS_AP_SWITCHING;
                break;
            }

            case SRV_WLAN_SET_MODE_STA:
            {                       
                mode_status = SRV_WLAN_MODE_STATUS_STA_SWITCHING;
                break;
            }

            case SRV_WLAN_SET_MODE_AP_STA:
            {                
                mode_status = SRV_WLAN_MODE_STATUS_AP_STA_SWITCHING;
                break;
            }

            case SRV_WLAN_SET_MODE_OFF:
            {                
                mode_status = SRV_WLAN_MODE_STATUS_OFF_SWITCHING;
                break;
            }

            default:
            {
                mode_status = SRV_WLAN_MODE_STATUS_ERROR;
                break;
            }
        }
    }    

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_STATUS, mode_status);
    return mode_status;
#else
    return SRV_WLAN_MODE_STATUS_ERROR;
#endif    
}


srv_wlan_result_enum srv_wlan_sniffer_on(
                        srv_wlan_sniffer_on_cfg_struct *sniffer_on_config,
                        srv_wlan_sniffer_on_cb_func_ptr callback,
                        void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && \
    defined(__TCPIP__) && defined(__WIFI_SNIFFER_SUPPORT__)

    MMI_BOOL is_legal = MMI_FALSE; 
    srv_wlan_sniffer_on_res_struct res = {0};
    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SNIFFER_ON);
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_SNIFFER_ON);

    if (is_legal)
    {
        srv_wlan_add_action_job(SRV_WLAN_JOB_SNIFFER_ON, (void*)callback, user_data);

        srv_dtcnt_wlan_sniffer_on(
            (srv_dtcnt_wlan_sniffer_on_cfg_struct*)sniffer_on_config,
            srv_wlan_sniffer_on_callback,
            NULL);       
        
        result = SRV_WLAN_RESULT_PROCESSING;
    }
    else
    {
        if (callback)
        {
            res.cb_type = SRV_WLAN_SNIFFER_ON_RES;
            res.result = SRV_WLAN_SNIFFER_FAIL_STATE_ERROR;
            callback(user_data, &res);
        }
        
        result = SRV_WLAN_RESULT_STATE_ERROR;
    }

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


srv_wlan_result_enum srv_wlan_sniffer_off(
                        srv_wlan_sniffer_off_cb_func_ptr callback,
                        void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && \
    defined(__TCPIP__) && defined(__WIFI_SNIFFER_SUPPORT__)
   
    MMI_BOOL is_legal = MMI_FALSE; 
    srv_wlan_result_enum result;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SNIFFER_OFF);
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_SNIFFER_OFF);

    if (is_legal)
    {
        srv_wlan_add_action_job(SRV_WLAN_JOB_SNIFFER_OFF, (void*)callback, user_data);
        // Call dtcnt srv API        
        srv_dtcnt_wlan_sniffer_off(srv_wlan_sniffer_off_callback, user_data);
        
        result = SRV_WLAN_RESULT_PROCESSING;
    }
    else
    {
        if (callback)
        {            
            callback(user_data, SRV_WLAN_SNIFFER_FAIL_STATE_ERROR);
        }
        
        result = SRV_WLAN_RESULT_STATE_ERROR;
    }

    return result;
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


/* Everytime connection succeeds, the reconn prof id will be set to be the conn prof id automatically. */
MMI_BOOL srv_wlan_set_reconn_prof_id(U32 prof_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    U64 profile = prof_id;
    S16 error;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_SET_RECONN_PROF_ID, prof_id);
    WriteValue(NVRAM_WLAN_RECONN_PROF_ID, &profile, DS_DOUBLE, &error);

    if (0 < error)
    {
        return MMI_TRUE;
    }
    
    return MMI_FALSE;
#else
    return MMI_FALSE;
#endif
}


MMI_BOOL srv_wlan_get_reconn_prof_id(U32* prof_id)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    U64 profile = 0;
    S16 error;
    MMI_BOOL ret = MMI_FALSE;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_RECONN_PROF_ID);
    ReadValue(NVRAM_WLAN_RECONN_PROF_ID, &profile, DS_DOUBLE, &error);    
    
    *prof_id = (U32)profile;

    if (0 < error && (*prof_id > CBM_DEFAULT_ACCT_ID))
    {
        *prof_id = (U32)profile;
        ret = MMI_TRUE;
    }
    else
    {
        *prof_id = 0;
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_GET_RECONN_PROF_ID_RET, *prof_id, ret);

    return ret;
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_reg_ip_available_noti(srv_wlan_noti_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_REG_IP_AVL_NOTI);
    reg_info.reg_type = SRV_WLAN_NOTI_IP_AVAILABLE;
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;        

    return srv_wlan_reg_noti_int(&reg_info);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_dereg_ip_available_noti(srv_wlan_noti_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_DEREG_IP_AVL_NOTI);
    reg_info.reg_type = SRV_WLAN_NOTI_IP_AVAILABLE;
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;        

    return srv_wlan_dereg_noti_int(&reg_info);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_reg_passive_disconn_noti(srv_wlan_noti_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_REG_PAS_DISCONN_NOTI);
    reg_info.reg_type = SRV_WLAN_NOTI_PASSIVE_DISCONN;
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;        

    return srv_wlan_reg_noti_int(&reg_info);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_dereg_passive_disconn_noti(srv_wlan_noti_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_DEREG_PAS_DISCONN_NOTI);
    reg_info.reg_type = SRV_WLAN_NOTI_PASSIVE_DISCONN;
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;        

    return srv_wlan_dereg_noti_int(&reg_info);
#else
    return MMI_FALSE;
#endif    
}


MMI_BOOL srv_wlan_reg_noti(S32 noti_type, srv_wlan_noti_func_ptr callback, void *user_data)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_REG_NOTI, noti_type);
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;
    reg_info.reg_type = noti_type;
    return srv_wlan_reg_noti_int(&reg_info);    
#else
    return MMI_FALSE;
#endif
}


MMI_BOOL srv_wlan_dereg_noti(S32 noti_type, srv_wlan_noti_func_ptr callback, void *user_data)    
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    srv_wlan_reg_noti_struct reg_info;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_DEREG_NOTI, noti_type);
    reg_info.cb_func_ptr = (void*)callback;
    reg_info.user_data = user_data;
    reg_info.reg_type = noti_type;
    return srv_wlan_dereg_noti_int(&reg_info); 
#else
    return MMI_FALSE;
#endif    
}


/* For detail description please refer to DtcntSrvGprot.h */
srv_wlan_sta_status_enum srv_wlan_sta_status(void)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_wlan_sta_status_enum sta_status = SRV_WLAN_STA_STATUS_INACTIVE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (srv_dtcnt_wlan_state())
    {
        case SRV_DTCNT_WLAN_STATE_NULL:
        {
            sta_status = SRV_WLAN_STA_STATUS_INACTIVE;
            break;
        }
        
        case SRV_DTCNT_WLAN_STATE_INIT:
        {
            sta_status = SRV_WLAN_STA_STATUS_ACTIVE;
            break;
        }

        case SRV_DTCNT_WLAN_STATE_CONNECTED:
        {
            sta_status = SRV_WLAN_STA_STATUS_CONNECTED;
            break;
        }
            
        case SRV_DTCNT_WLAN_STATE_SNIFFER_ON:
        {
            sta_status = SRV_WLAN_STA_STATUS_SNIFFER;
            break;
        }
            
        case SRV_DTCNT_WLAN_STATE_DEINIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_INIT_WAIT:
        case SRV_DTCNT_WLAN_STATE_DISCONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_CONNECT_WAIT:
        case SRV_DTCNT_WLAN_STATE_SNIFFER_ON_WAIT:
        case SRV_DTCNT_WLAN_STATE_SNIFFER_OFF_WAIT:          
        {
            sta_status = SRV_WLAN_STA_STATUS_BUSY;
            break;
        }     
            
        default:
            break;
    }

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_API_STA_STATUS, sta_status);
    return sta_status;
#else
    return SRV_WLAN_STA_STATUS_TOTAL;
#endif
}


srv_wlan_result_enum srv_wlan_set_para(
    srv_wlan_set_mode_enum mode,
    void *para,
    S32 flag)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    switch (mode)
    {
        #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
        case SRV_WLAN_SET_MODE_AP:
        case SRV_WLAN_SET_MODE_AP_STA:
        {            
            MMI_BOOL ret;
            srv_apmode_config_struct hs_ap_para = {0};
            srv_wlan_cfg_ap_struct *ap_para = (srv_wlan_cfg_ap_struct*)para;            
            
            if (srv_apmode_is_on())
            {
                return SRV_WLAN_RESULT_STATE_ERROR;
            }
            
            if (!ap_para)
            {
                return SRV_WLAN_RESULT_INVALID_INPUT;
            }
            else
            {
                hs_ap_para.auth_mode = srv_wlan_hswlan_authmode_cvt(ap_para->auth_mode, MMI_TRUE);
                if (hs_ap_para.auth_mode < 0)
                {
                    return SRV_WLAN_RESULT_INVALID_INPUT;
                }
                
                memcpy(hs_ap_para.ssid, ap_para->ssid, SRV_WLAN_WNDRV_SSID_MAX_LEN + 1);
                memcpy(hs_ap_para.psk, ap_para->pwd, SRV_WLAN_PROF_PSWD_MAX_LEN);                
            }
            
            ret = srv_apmode_config_set_para(
                    &hs_ap_para,
                    (srv_apmode_config_para_enum)flag);

            return ret ? SRV_WLAN_RESULT_SUCCESS : SRV_WLAN_RESULT_FAILED;            
        }
        #endif
        
        default:
        {
            return SRV_WLAN_RESULT_INVALID_INPUT;
        }
    }    
#else
    return SRV_WLAN_RESULT_FAILED;
#endif
}


srv_wlan_result_enum srv_wlan_get_para(
    srv_wlan_set_mode_enum mode,
    void *para)
{
#if defined (__MMI_WLAN_FEATURES__) && defined(__MTK_TARGET__) && defined(__TCPIP__)

    if (!para)
    {
        return SRV_WLAN_RESULT_INVALID_STORE;
    }

    switch (mode)
    {
        #if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
        case SRV_WLAN_SET_MODE_AP:
        case SRV_WLAN_SET_MODE_AP_STA:
        {
            MMI_BOOL ret;
            srv_apmode_config_struct *hs_ap_para = (srv_apmode_config_struct*)para;

            ret = srv_apmode_config_get_para(hs_ap_para);

            hs_ap_para->auth_mode = srv_wlan_hswlan_authmode_cvt(hs_ap_para->auth_mode, MMI_FALSE);

            if (hs_ap_para->auth_mode >= 0 && ret)
            {
                return SRV_WLAN_RESULT_SUCCESS;
            }
            else
            {
                return SRV_WLAN_RESULT_FAILED;
            }
        }
        #endif
        
        default:
        {
            return SRV_WLAN_RESULT_INVALID_INPUT;
        }
    }
#else
    return SRV_WLAN_RESULT_FAILED;
#endif    
}


// #endif /* __IOT__ && __MMI_WLAN_FEATURES__ && __TCPIP__ */
