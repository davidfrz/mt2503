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
 *  WlanSrvUtil.c
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
#if defined(__TCPIP__) && defined(__MMI_WLAN_FEATURES__)

#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"
#include "DtcntSrvWlan.h"
#include "DtcntSrvIntDef.h"
#include "WiFiApSrvGprot.h"
#include "TetheringSrvIprot.h"
#include "Mmi_cb_mgr_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_frm_events_gprot.h"
#include "mmi_frm_nvram_gprot.h"
#include "MMI_conn_app_trc.h"
#include "MMI_trc_int.h"
#include "kal_trace.h"
#include "WlanSrvGprot.h"
#include "WlanSrvIprot.h"
#include "mmi_rp_srv_wlan_def.h"


/***************************************************************************** 
* Function Declaration
*****************************************************************************/
static MMI_BOOL srv_wlan_w2dprof_map_ssid(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof);

static MMI_BOOL srv_wlan_w2dprof_map_auth_mode(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof);

static MMI_BOOL srv_wlan_w2dprof_map_username(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof);

static MMI_BOOL srv_wlan_w2dprof_map_pswd(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof);

static void srv_wlan_get_action_job(srv_wlan_action_job_struct *job);

extern void wlan_srv_test_main(void);

#ifdef __WIFI_SNIFFER_SUPPORT__
void srv_wlan_deinit_sniffer_auto_kill(void *user_data, srv_wlan_sniffer_res_enum res);
#endif

/***************************************************************************** 
* Global Variable
*****************************************************************************/
srv_wlan_context g_srv_wlan_cntx;
srv_wlan_reg_noti_struct g_srv_wlan_reg_noti[SRV_WLAN_REG_MAX_NUM];

static MMI_BOOL (*prof_param_map[]) (srv_dtcnt_prof_wlan_struct * const, const srv_wlan_prof_struct * const) =
{
    srv_wlan_w2dprof_map_ssid,
    srv_wlan_w2dprof_map_auth_mode,
    srv_wlan_w2dprof_map_username,
    srv_wlan_w2dprof_map_pswd,
    NULL
};


/***************************************************************************** 
 * Internal APIs
 *****************************************************************************/
/* Convert the dot ip(x.x.x.x) to 4 bytes format. */
static MMI_BOOL srv_wlan_ip_dotstr2bytes(U8 *const byte_ip, const CHAR *dot_ip)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i, bits, val;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!byte_ip || !dot_ip)
    {
        return MMI_FALSE;
    }

    for (i = 0; i < 4; i++)
    {
        val = bits = 0;
        while (*dot_ip >= '0' && *dot_ip <= '9')
        {
            bits++;
            val = val * 10 + (*dot_ip - '0');
            dot_ip++;
        }

        if (!(bits >= 1 && bits <= 3 && val >= 0 && val <= 255))
        {
            return MMI_FALSE;
        }
        
        if (*dot_ip != '.' && *dot_ip != '\0')
        {
            return MMI_FALSE;
        }
        
        byte_ip[i] = (U8)val;        
        
        /* skip "." */
        dot_ip++;
    }
    
    return MMI_TRUE;
}


/* If static ip is used */
static void srv_wlan_use_static_ip(srv_dtcnt_prof_wlan_struct * const dtcnt_prof)
{
    if (!dtcnt_prof)
    {
        return;
    }

    dtcnt_prof->use_dhcp = MMI_FALSE;
    srv_wlan_ip_dotstr2bytes(dtcnt_prof->ip_addr, SRV_WLAN_STATIC_IP_ADDR);
    srv_wlan_ip_dotstr2bytes(dtcnt_prof->gateway, SRV_WLAN_GATEWAY_IP_ADDR);
    srv_wlan_ip_dotstr2bytes(dtcnt_prof->netmask, SRV_WLAN_NETMASK);
    srv_wlan_ip_dotstr2bytes(dtcnt_prof->dns1, SRV_WLAN_DSN1_ADDR);
    srv_wlan_ip_dotstr2bytes(dtcnt_prof->dns2, SRV_WLAN_DSN2_ADDR);    
}


static srv_wlan_result_enum srv_wlan_find_lowest_priority_profid(U8 * const priority, U32 * const profile_id)
{
    srv_wlan_result_enum result;
    srv_wlan_prof_list_struct prof_list;
    srv_dtcnt_prof_wlan_struct *dtcnt_prof;
    U32 index, total_prof_num = 0;    

    if (!priority && !profile_id)
    {
        return SRV_WLAN_RESULT_FAILED;
    }

    *priority = 0;
    *profile_id = 0;

    total_prof_num = srv_dtcnt_wlan_get_total_prof_num();
    if (!total_prof_num || total_prof_num > SRV_MAX_WLAN_ACCOUNT_NUM)
    {        
        return SRV_WLAN_RESULT_FAILED;
    }
        
    result = srv_wlan_query_prof_list(&prof_list);
    if (SRV_WLAN_RESULT_SUCCESS == result)
    {
        dtcnt_prof = get_ctrl_buffer(sizeof(srv_dtcnt_prof_wlan_struct));
        memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));        
        result = srv_wlan_query_dtcnt_prof(prof_list.ids[0], SRV_DTCNT_PROF_FIELD_ALL, dtcnt_prof);
        if (SRV_WLAN_RESULT_SUCCESS == result)
        {            
            *priority = dtcnt_prof->priority;
            *profile_id = dtcnt_prof->profile_id;        

            for (index = 1; index < prof_list.num_ids; index++)
            {
                memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));        
                result = srv_wlan_query_dtcnt_prof(prof_list.ids[index], SRV_DTCNT_PROF_FIELD_ALL, dtcnt_prof);
                if (SRV_WLAN_RESULT_SUCCESS != result)
                {
                    break;
                }
                if (dtcnt_prof->priority > *priority)
                {
                    *priority = dtcnt_prof->priority;
                    *profile_id = dtcnt_prof->profile_id;  
                }            
            }
        }
        free_ctrl_buffer(dtcnt_prof);
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_LOWEST_PRIORITY, *profile_id, *priority, result);

    return result;
}


/* Check if the string is composed of  HEX characters. */
static MMI_BOOL srv_wlan_is_hex_string(const U8* const src, const U8 len)
{
    U32 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < len; index++)
    {
        if (src[index] >= '0' && src[index] <= '9')
        {
            continue;
        }
        else if (src[index] >= 'A' && src[index] <= 'F')
        {
            continue;
        }
        else if (src[index] >= 'a' && src[index] <= 'f')
        {
            continue;
        }
        else
        {
            return MMI_FALSE;
        }
    }
    
    return MMI_TRUE;
}


/* inStr is a hexadecimal string, every two bytes of which represents a decimal value.
 * outStr is a decimal string, each byte of which combines the two bytes hex value of inStr. */
static MMI_BOOL srv_wlan_hexstr_to_decimalstr(CHAR* const outStr, const CHAR* const inStr, const U32 length)
{
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (length % 2 != 0)
    {
        return MMI_FALSE;
    }
    
    memset(outStr, 0, length / 2 + 1);

    for (i = 0, j = 0; i < length; i++)
    {
        j = (i - i % 2) / 2;
        if (inStr[i] >= '0' && inStr[i] <= '9')
        {
            outStr[j] += (inStr[i] - '0') << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'A' && inStr[i] <= 'F')
        {
            outStr[j] += (inStr[i] - 'A' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else if (inStr[i] >= 'a' && inStr[i] <= 'f')
        {
            outStr[j] += (inStr[i] - 'a' + 0x0A) << 4 * ((i + 1) % 2);
        }
        else
        {
            return MMI_FALSE;
        }
    }
    return MMI_TRUE;
}


/* Check if the characters of ssid or pwd */
static MMI_BOOL srv_wlan_check_characters(const U8 *const str, const U32 str_len)
{
    U32 index, actual_len;
    U8 *char_ptr;

    if (!str || !str_len)
    {
        return MMI_FALSE;
    }

    actual_len = strlen((const char*)str);
    ASSERT(actual_len >= str_len);

    if (actual_len > str_len)
    {
        actual_len = str_len;
    }
    
    for (index = 0; index < actual_len; index++)
    {
        char_ptr = (U8*)strchr(SRV_WLAN_ALLOWED_CHARACTERS, (CHAR)str[index]);
        if (!char_ptr)
        {
            if ('0' <= str[index] && '9' >= str[index])
            {
                continue;
            }
            else if ('A' <= str[index] && 'Z' >= str[index])
            {
                continue;
            }
            else if ('a' <= str[index] && 'z' >= str[index])
            {
                continue;
            }
            
            return MMI_FALSE;
        }
    }

    return MMI_TRUE;
}


static MMI_BOOL srv_wlan_prof_check_ssid(const srv_wlan_prof_struct *const wlan_prof)
{
    U8 length;
    MMI_BOOL ret;
    
    if (!wlan_prof)
    {
        return MMI_FALSE;
    }
    
    length = strlen((const CHAR*)wlan_prof->ssid);
    ASSERT(length <= SRV_WLAN_PROF_MAX_SSID_LEN);

    if (0 == length)
    {
        return MMI_FALSE;
    }

    ret = srv_wlan_check_characters(wlan_prof->ssid, length);   
    
    return ret;
}


/* map functions will not check the vadility of the profile. */
static MMI_BOOL srv_wlan_w2dprof_map_ssid(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof)
{
    if (!dtcnt_prof || !wlan_prof)
    {
        return MMI_FALSE;
    }

    if (!srv_wlan_prof_check_ssid(wlan_prof))
    {
        return MMI_FALSE;
    }
    
    memset(dtcnt_prof->ssid, 0, SRV_WLAN_PROF_MAX_SSID_LEN + 1);
    strncpy((CHAR*)dtcnt_prof->ssid, (const CHAR*)wlan_prof->ssid, SRV_WLAN_PROF_MAX_SSID_LEN);
    dtcnt_prof->ssid_len = strlen((CHAR*)dtcnt_prof->ssid);
    
    return MMI_TRUE;
}


static MMI_BOOL srv_wlan_w2dprof_map_auth_mode(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof)
{
    if (!dtcnt_prof || !wlan_prof)
    {
        return MMI_FALSE;
    }

    switch (wlan_prof->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        {
            dtcnt_prof->auth_mode = (srv_dtcnt_wlan_auth_mode_enum)wlan_prof->auth_mode;
            break;
        }
        default:
            return MMI_FALSE;
    }    
    
    return MMI_TRUE;
}


static MMI_BOOL srv_wlan_w2dprof_map_username(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof)
{
    if (!dtcnt_prof || !wlan_prof)
    {
        return MMI_FALSE;
    }

    switch (wlan_prof->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        {
            memset(dtcnt_prof->username, 0, SRV_DTCNT_PROF_MAX_USER_LEN+1);
            break;
        }
        default:
            return MMI_FALSE;
    }

    return MMI_TRUE;
}


static MMI_BOOL srv_wlan_w2dprof_map_pswd(
                    srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
                    const srv_wlan_prof_struct *const wlan_prof)
{
    MMI_BOOL is_valid = MMI_FALSE;
    U32 length;
    CHAR* psk;
    CHAR* passphrase;

    if (!dtcnt_prof || !wlan_prof)
    {
        return MMI_FALSE;
    }

    if (SRV_WLAN_AUTH_MODE_OPEN == wlan_prof->auth_mode)
    {        
        return MMI_TRUE;    
    }
    
    length = strlen((CHAR*)wlan_prof->password);
    ASSERT(length <= SRV_WLAN_PROF_PSWD_MAX_LEN);
    
    is_valid = srv_wlan_check_characters(wlan_prof->password, length);
    if (!is_valid)
    {
        return MMI_FALSE;
    }
    
    psk = get_ctrl_buffer(SRV_DTCNT_PROF_MAX_PSK_LEN);
    passphrase = get_ctrl_buffer(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);

    if (SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK == wlan_prof->auth_mode ||
		SRV_WLAN_AUTH_MODE_WPA_ONLY_PSK == wlan_prof->auth_mode)
    {
        /* 8~63 bytes ASCII psw or 64 bytes HEX psw */
        if(length >= SRV_WLAN_PASSPHRASE_KEY_LEN_MIN)
        {
            if(SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN == length)
            {
                if (srv_wlan_is_hex_string(wlan_prof->password, length))
                {                    
                    memset(psk, 0, SRV_DTCNT_PROF_MAX_PSK_LEN);
                    srv_wlan_hexstr_to_decimalstr(psk, (CHAR*)wlan_prof->password, length);
                    memcpy(dtcnt_prof->psk, psk, SRV_DTCNT_PROF_MAX_PSK_LEN);
                    memcpy(dtcnt_prof->passphrase, wlan_prof->password, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);                    
                    is_valid = MMI_TRUE;
                }
            }
            else
            {
                memcpy(dtcnt_prof->passphrase, wlan_prof->password, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
                is_valid = MMI_TRUE;
            }
        }
    }
    else if (SRV_WLAN_AUTH_MODE_WEP == wlan_prof->auth_mode)
    {       
        if(!(0 == length || length > SRV_WLAN_WEP_KEY_LENGTH_128BITS_HEX))       
        {               
            switch (length)
            {
                case SRV_WLAN_AP_WEP_KEY_LEN_FIVE:
                {
                    dtcnt_prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                    dtcnt_prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;
                    memcpy(dtcnt_prof->wep_key, wlan_prof->password, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
                    is_valid = MMI_TRUE;
                    break;
                }
                case SRV_WLAN_AP_WEP_KEY_LEN_THIRTEEN:
                {
                    dtcnt_prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                    dtcnt_prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_ASCII;
                    memcpy(dtcnt_prof->wep_key, wlan_prof->password, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
                    is_valid = MMI_TRUE;
                    break;
                }
                case SRV_WLAN_AP_WEP_KEY_LEN_TEN:
                {                    
                    memset(passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
                    is_valid = srv_wlan_hexstr_to_decimalstr(passphrase, (CHAR*)wlan_prof->password, length);
                    if(is_valid == MMI_TRUE)
                    {   
                        dtcnt_prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_64;
                        dtcnt_prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
                        memcpy(dtcnt_prof->wep_key, wlan_prof->password, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
                    }
                    break;
                }
                case SRV_WLAN_AP_WEP_KEY_LEN_TWENTY_SIX:
                {
                    memset(passphrase, 0, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
                    is_valid = srv_wlan_hexstr_to_decimalstr(passphrase, (CHAR*)wlan_prof->password, length);
                    if(is_valid == MMI_TRUE)
                    {
                        dtcnt_prof->wep_key_len = SRV_DTCNT_WLAN_WEP_KEY_ENCRYPT_128;
                        dtcnt_prof->wep_key_format = SRV_DTCNT_WLAN_WEP_KEY_FORMAT_HEX;
                        memcpy(dtcnt_prof->wep_key, wlan_prof->password, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
                    }
                    break;
                }
                default:                    
                    break;
            }           
        }
    }
    
    free_ctrl_buffer(psk);    
    free_ctrl_buffer(passphrase); 
    return is_valid;
}

 
static srv_wlan_result_enum srv_wlan_add_prof_into_dtcnt(srv_dtcnt_prof_wlan_struct *dtcnt_prof, U32 * acc_prof_id)
{
    srv_dtcnt_store_prof_data_struct storeProfile;
    srv_dtcnt_result_enum result;

    storeProfile.prof_data = dtcnt_prof;
    storeProfile.prof_fields = SRV_DTCNT_WLAN_PROF_FIELD_ALL;
    storeProfile.prof_type = SRV_DTCNT_BEARER_WIFI;
    result = srv_dtcnt_store_add_prof(&storeProfile, acc_prof_id);

    return (srv_wlan_result_enum)result;
}


/* The validity of the password is not verified. */
static MMI_BOOL srv_wlan_d2wprof_map_pswd(
                    srv_wlan_prof_struct *const wlan_prof, 
                    const srv_dtcnt_prof_wlan_struct *const dtcnt_prof)
{
    if (!dtcnt_prof || !wlan_prof)
    {
        return MMI_FALSE;
    }

    switch (dtcnt_prof->auth_mode)
    {
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
        {            
            memcpy(wlan_prof->password, dtcnt_prof->passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
            break;
        }
        case SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK:
        {
            memcpy(wlan_prof->password, dtcnt_prof->passphrase, SRV_DTCNT_PROF_MAX_PASSPHRASE_LEN + 1);
            break;
        }
        case SRV_DTCNT_WLAN_AUTH_MODE_WEP:
        {
            memcpy(wlan_prof->password, dtcnt_prof->wep_key, SRV_DTCNT_PROF_MAX_WEP_KEY_LEN + 1);
            break;            
        }
        case SRV_DTCNT_WLAN_AUTH_MODE_OPEN:
        {
            /* No password */
            break;
        }            
        default:
            return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


/***************************************************************************** 
 * External APIs
 *****************************************************************************/
MMI_BOOL srv_wlan_is_action_legal(const srv_dtcnt_wlan_action_enum action)
{
    srv_dtcnt_wlan_state_enum current_state;
    srv_dtcnt_wlan_scan_state_enum current_scan_state;
    MMI_BOOL ret = MMI_FALSE;
    
    current_state = srv_dtcnt_wlan_state();    
    current_scan_state = srv_dtcnt_wlan_scan_state();
    switch (action)
    {
        case SRV_DTCNT_WLAN_ACTION_INIT:
        {
            ret = MMI_TRUE; 
            /* For switch API */
            /*if (SRV_DTCNT_WLAN_STATE_NULL == current_state)
            {
                ret = MMI_TRUE;
            }*/
            break;
        }
        case SRV_DTCNT_WLAN_ACTION_CONNECT:
        {
            if (SRV_DTCNT_WLAN_STATE_INIT == current_state)
            {
                ret = MMI_TRUE;
            }
            break;
        }
        case SRV_DTCNT_WLAN_ACTION_DISCONNECT:
        {            
            if (SRV_DTCNT_WLAN_STATE_CONNECTED == current_state)
            {
                ret = MMI_TRUE;
            }
            break;
        }
        case SRV_DTCNT_WLAN_ACTION_DEINIT:
        {
            ret = MMI_TRUE;
            /* For switch API */
            /*if (SRV_DTCNT_WLAN_STATE_INIT == current_state)
            {
                ret = MMI_TRUE;
            }*/
            break;
        }
        case SRV_DTCNT_WLAN_ACTION_SCAN:
        {
            /* During the scan or scan abort action the states are WAITING or ABORTING.
             * In dtcnt srv, scan abort doesn't notify wifi driver through ABM, but just invoke the 
             * callback list. So when the CNF of the last scan request received, there's no callback
             * to notify dtcnt srv user. And in user-end, the scan abort appears logically.
             * For user may changing the scan parameters during ABORTING, so during ABORTING, scan 
             * action can't be done.
             */            
            if (SRV_DTCNT_WLAN_SCAN_STATE_NULL == current_scan_state)
            {  
#ifdef __WIFI_SNIFFER_SUPPORT__
                if (SRV_DTCNT_WLAN_STATE_SNIFFER_ON_WAIT == current_state ||
                    SRV_DTCNT_WLAN_STATE_SNIFFER_ON == current_state ||
                    SRV_DTCNT_WLAN_STATE_SNIFFER_OFF_WAIT == current_state)
                {
                    /* In sniffer mode */
                    break;
                }
#endif
                /* Only when wifi is open, can the scan API be used. Wlan srv will not add action secretly. */
                if (!((srv_dtcnt_wlan_prev_state() == SRV_DTCNT_WLAN_STATE_NULL && srv_dtcnt_wlan_state() != SRV_DTCNT_WLAN_STATE_CONNECT_WAIT) ||
                    srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_NULL ||
                    srv_dtcnt_wlan_state() == SRV_DTCNT_WLAN_STATE_DEINIT_WAIT))
                {
                    if (srv_dtcnt_wlan_find_action(SRV_DTCNT_WLAN_ACTION_DEINIT) == NULL)
                    {
                        ret = MMI_TRUE;
                    }
                }
            }
            break;
        }
#ifdef __WIFI_SNIFFER_SUPPORT__
        case SRV_DTCNT_WLAN_ACTION_SNIFFER_ON:
        {            
            if (SRV_DTCNT_WLAN_STATE_INIT == current_state)
            {
                if (SRV_DTCNT_WLAN_SCAN_STATE_NULL == srv_dtcnt_wlan_scan_state())
                {
                     ret = MMI_TRUE;
                }
            }
            break;
        }

        case SRV_DTCNT_WLAN_ACTION_SNIFFER_OFF:
        {
            if (SRV_DTCNT_WLAN_STATE_SNIFFER_ON == current_state)
            {
                ret = MMI_TRUE;
            }
            break;
        }
#endif
        default:
            break;
    }

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_IS_ACTION_LEGAL, current_state, ret);

    return ret;    
}


MMI_BOOL srv_wlan_w2dprof_map(
            srv_dtcnt_prof_wlan_struct *const dtcnt_prof, 
            const srv_wlan_prof_struct *const wlan_prof)
{    
    MMI_BOOL (*prof_map_func) (srv_dtcnt_prof_wlan_struct * const, const srv_wlan_prof_struct * const) = prof_param_map[0];
    U32 index = 0;        
    MMI_BOOL ret = MMI_FALSE;
            
    srv_dtcnt_wlan_init_profile(dtcnt_prof);
    while (prof_map_func)
    {
        ret = prof_map_func(dtcnt_prof, wlan_prof);
        if (!ret)
        {
            return MMI_FALSE;
        }
        prof_map_func = prof_param_map[++index];
    }
    
    // TODO: Just for 0.5 Demo for no service-finding service
    //srv_wlan_use_static_ip(dtcnt_prof);
    dtcnt_prof->use_dhcp = MMI_TRUE;

    return MMI_TRUE;
}


MMI_BOOL srv_wlan_d2wprof_map(
            srv_wlan_prof_struct *const wlan_prof, 
            const srv_dtcnt_prof_wlan_struct *const dtcnt_prof)
{
    memset(wlan_prof, 0, sizeof(srv_wlan_prof_struct));
    /* password */
    if (!srv_wlan_d2wprof_map_pswd(wlan_prof, dtcnt_prof))
    {
        return MMI_FALSE;
    }
    
    memcpy(wlan_prof->ssid, dtcnt_prof->ssid, dtcnt_prof->ssid_len);
    wlan_prof->auth_mode = (srv_wlan_auth_mode_enum)dtcnt_prof->auth_mode;        
    memcpy(wlan_prof->username, dtcnt_prof->username, (SRV_DTCNT_PROF_MAX_USER_LEN+1));
    #if 0
/* under construction !*/
    #endif
    wlan_prof->profile_id = dtcnt_prof->profile_id;

    return MMI_TRUE;        
}


void srv_wlan_ipaddr_update_ind_hdlr(void *info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_dtcnt_wlan_ipaddr_update_evt_struct *ind;
    mmi_event_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_IP_UPD_HDL);
    ind = (srv_dtcnt_wlan_ipaddr_update_evt_struct*) info;
   
    memcpy(g_srv_wlan_cntx.ip_info.ip_addr, ind->new_ipaddr.ip_addr, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_srv_wlan_cntx.ip_info.netmask, ind->new_ipaddr.netmask, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_srv_wlan_cntx.ip_info.gateway, ind->new_ipaddr.gateway, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_srv_wlan_cntx.ip_info.dns1, ind->new_ipaddr.dns1, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    memcpy(g_srv_wlan_cntx.ip_info.dns2, ind->new_ipaddr.dns2, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);

    MMI_FRM_INIT_EVENT(&evt,EVT_ID_WLAN_IP_AVAILABLE_NOTI);
    mmi_frm_cb_emit_post_event(&evt);  
}


mmi_ret srv_wlan_ip_available_noti_hdl(mmi_event_struct *evt)
{
    U32 index;
    srv_wlan_noti_func_ptr callback;
    srv_wlan_noti_struct noti = {0};

    noti.type = SRV_WLAN_NOTI_IP_AVAILABLE;
    for (index = 0; index < SRV_WLAN_REG_MAX_NUM; index++)
    {
        if (SRV_WLAN_NOTI_IP_AVAILABLE == g_srv_wlan_reg_noti[index].reg_type)
        {
            if (!g_srv_wlan_reg_noti[index].cb_func_ptr)
            {
                MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_IP_REC_ERROR);
                g_srv_wlan_reg_noti[index].reg_type = SRV_WLAN_NOTI_NONE;
            }
            else
            {
                callback = (srv_wlan_noti_func_ptr)g_srv_wlan_reg_noti[index].cb_func_ptr;
                callback(g_srv_wlan_reg_noti[index].user_data, &noti);
            }
        }
    }    
}


mmi_ret srv_wlan_passive_disconn_noti_hdl(mmi_event_struct *evt)
{
    U32 index;
    srv_wlan_noti_func_ptr callback;
    srv_wlan_noti_struct noti = {0};

    for (index = 0; index < SRV_WLAN_REG_MAX_NUM; index++)
    {
        if (SRV_WLAN_NOTI_PASSIVE_DISCONN == g_srv_wlan_reg_noti[index].reg_type)
        {
            if (!g_srv_wlan_reg_noti[index].cb_func_ptr)
            {
                MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_IP_REC_ERROR);
                g_srv_wlan_reg_noti[index].reg_type = SRV_WLAN_NOTI_NONE;
            }
            else
            {
                callback = (srv_wlan_noti_func_ptr)g_srv_wlan_reg_noti[index].cb_func_ptr;
                noti.type = SRV_WLAN_NOTI_PASSIVE_DISCONN;
                callback(g_srv_wlan_reg_noti[index].user_data, &noti);
            }
        }
    }    
}


mmi_ret srv_wlan_connect_callback (mmi_event_struct *evt)
{
    srv_dtcnt_wlan_conn_res_ind_evt_struct *wlan_evt = (srv_dtcnt_wlan_conn_res_ind_evt_struct*)evt;    
    srv_wlan_action_job_struct job = {0};
    srv_wlan_conn_res_cb_func_ptr callback = NULL;
    srv_dtcnt_prof_wlan_struct *dtcnt_prof;
    srv_wlan_result_enum result;
    U64 profile = wlan_evt->conn_result.profile_id;
    S16 error;
    mmi_event_struct ip_evt;
        
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_CONN_CB, wlan_evt ? wlan_evt->conn_result.result : SRV_DTCNT_RESULT_FAILED);
    
    if (!evt)
    {
        return MMI_RET_OK;
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_CONN_RES_IND, srv_wlan_connect_callback, NULL);

    if (SRV_DTCNT_RESULT_SUCCESS == wlan_evt->conn_result.result)
    {                
        WriteValue(NVRAM_WLAN_RECONN_PROF_ID, &profile, DS_DOUBLE, &error);
        mmi_frm_cb_reg_event(EVT_ID_WLAN_IP_AVAILABLE_NOTI, srv_wlan_ip_available_noti_hdl, NULL);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_DISC_IND, srv_wlan_passive_disconn_noti_hdl, NULL);        
            
        /* Check if DHCP is used or not */
        dtcnt_prof = OslMalloc(sizeof(srv_dtcnt_prof_wlan_struct));
        memset(dtcnt_prof, 0, sizeof(srv_dtcnt_prof_wlan_struct));    
        result = srv_wlan_query_dtcnt_prof(
                    wlan_evt->conn_result.profile_id, 
                    SRV_DTCNT_WLAN_PROF_FIELD_ALL,
                    dtcnt_prof);
        
        if (SRV_WLAN_RESULT_SUCCESS != result)
        {
            if (srv_dtcnt_get_wlan_conn_prof()->profile_id == 0xFFFFFFFF)
            {
                OslMfree(dtcnt_prof);
                dtcnt_prof = srv_dtcnt_get_wlan_conn_prof();
            }
            else
            {
            dtcnt_prof->use_dhcp = MMI_FALSE;
        }
        }        

        if (dtcnt_prof->use_dhcp)
        {   
            /* DHCP IP */
            mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE, srv_wlan_ipaddr_update_ind_hdlr, NULL);
        }
        else
        {
            /* Static IP */
            memcpy(g_srv_wlan_cntx.ip_info.ip_addr, dtcnt_prof->ip_addr, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
            memcpy(g_srv_wlan_cntx.ip_info.netmask, dtcnt_prof->netmask, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
            memcpy(g_srv_wlan_cntx.ip_info.gateway, dtcnt_prof->gateway, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
            memcpy(g_srv_wlan_cntx.ip_info.dns1, dtcnt_prof->dns1, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
            memcpy(g_srv_wlan_cntx.ip_info.dns2, dtcnt_prof->dns2, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
            MMI_FRM_INIT_EVENT(&ip_evt,EVT_ID_WLAN_IP_AVAILABLE_NOTI);
            mmi_frm_cb_emit_post_event(&ip_evt);
        }

        if (srv_dtcnt_get_wlan_conn_prof()->profile_id != 0xFFFFFFFF)
        {
        OslMfree(dtcnt_prof);
    }
    }
  
    job.job_type = SRV_WLAN_JOB_CONNECT;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        callback = (srv_wlan_conn_res_cb_func_ptr)job.cb_func_ptr;
        callback(job.user_data, (srv_wlan_conn_res_struct*)&(wlan_evt->conn_result));
    }

    return MMI_RET_OK;
}


mmi_ret srv_wlan_disconnect_callback (mmi_event_struct *evt)
{
    srv_dtcnt_wlan_disc_res_ind_evt_struct *wlan_evt = (srv_dtcnt_wlan_disc_res_ind_evt_struct*)evt;
    srv_wlan_action_job_struct job = {0};
    srv_wlan_cb_func_ptr callback = NULL;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DISCONN_CB, wlan_evt ? wlan_evt->res : SRV_DTCNT_WLAN_REQ_RES_FAILED);
    
    if (!evt)
    {
        return MMI_RET_OK;
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_DISC_RES_IND, srv_wlan_disconnect_callback ,NULL);

    if (SRV_DTCNT_WLAN_REQ_RES_DONE == wlan_evt->res)        
    {
        mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_IPADDR_UPDATE, srv_wlan_ipaddr_update_ind_hdlr, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_WLAN_IP_AVAILABLE_NOTI, srv_wlan_ip_available_noti_hdl, NULL);
        mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_DISC_IND, srv_wlan_passive_disconn_noti_hdl, NULL);
        
        memset(g_srv_wlan_cntx.ip_info.ip_addr, 0, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
        memset(g_srv_wlan_cntx.ip_info.netmask, 0, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
        memset(g_srv_wlan_cntx.ip_info.gateway, 0, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
        memset(g_srv_wlan_cntx.ip_info.dns1, 0, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
        memset(g_srv_wlan_cntx.ip_info.dns2, 0, SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    }
    
    job.job_type = SRV_WLAN_JOB_DISCONNECT;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        callback = (srv_wlan_cb_func_ptr)job.cb_func_ptr;
        callback(job.user_data, (srv_wlan_req_res_enum)wlan_evt->res);
    }
    
    return MMI_RET_OK;
}


mmi_ret srv_wlan_init_callback(mmi_event_struct *evt)
{
    srv_dtcnt_wlan_init_res_ind_evt_struct *wlan_evt = (srv_dtcnt_wlan_init_res_ind_evt_struct*)evt;
    srv_wlan_action_job_struct job = {0};
    srv_wlan_cb_func_ptr callback = NULL;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_INIT_CB, wlan_evt ? wlan_evt->res : SRV_DTCNT_WLAN_REQ_RES_FAILED);

    if (!evt)
    {
        return MMI_RET_OK;
    }
    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, srv_wlan_init_callback ,NULL);
    
    job.job_type = SRV_WLAN_JOB_INIT;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        callback = (srv_wlan_cb_func_ptr)job.cb_func_ptr;
        callback(job.user_data, (srv_wlan_req_res_enum)wlan_evt->res);
    }

    return MMI_RET_OK;
}


mmi_ret srv_wlan_deinit_callback (mmi_event_struct *evt)
{
    srv_dtcnt_wlan_deinit_res_ind_evt_struct *wlan_evt = (srv_dtcnt_wlan_deinit_res_ind_evt_struct*)evt;
    srv_wlan_action_job_struct job = {0};
    srv_wlan_cb_func_ptr callback = NULL;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DEINIT_CB, wlan_evt ? wlan_evt->res : SRV_DTCNT_WLAN_REQ_RES_FAILED);

    if (!evt)
    {
        return MMI_RET_OK;
    }
    
    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, srv_wlan_deinit_callback ,NULL);

    if (SRV_DTCNT_WLAN_REQ_RES_DONE == wlan_evt->res)
    {
        srv_dtcnt_wlan_init_wlan();
    }

    job.job_type = SRV_WLAN_JOB_DEINIT;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        callback = (srv_wlan_cb_func_ptr)job.cb_func_ptr;
        callback(job.user_data, (srv_wlan_req_res_enum)wlan_evt->res);
    }
    
    return MMI_RET_OK;
}


MMI_BOOL srv_wlan_prof_match(const srv_wlan_prof_struct *const prof1, const srv_wlan_prof_struct *const prof2)
{    
    MMI_BOOL result = MMI_FALSE;
    S32 ret = -1;

    // TODO: Need to compare the network type and encrypt type.
    ret = strcmp((const char*)prof1->ssid, (const char*)prof2->ssid);
    if (!ret && 
        (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA == SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA) &&
        (prof1->auth_mode == prof2->auth_mode) &&
        (SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP == SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP))
    {
       result = MMI_TRUE;
    }    

    return result;
}


srv_wlan_result_enum srv_wlan_add_prof_int(srv_dtcnt_prof_wlan_struct *dtcnt_prof, U32 *acc_prof_id)
{
    srv_wlan_result_enum result;
    U32 prof_id;
    U8 priority;
    
    /* If reach to the max number limitation, replace the new profile with the one with lowest priority.
     * Otherwise, add the new profile with the priority of the count of the profiles including the new one. */
    if (SRV_MAX_WLAN_ACCOUNT_NUM == srv_dtcnt_wlan_get_total_prof_num())
    {   
        result = srv_wlan_find_lowest_priority_profid(&priority, &prof_id);
        if (SRV_WLAN_RESULT_SUCCESS == result)
        {
            ASSERT(priority || prof_id);
            dtcnt_prof->priority = priority;
            srv_wlan_delete_prof(prof_id);
            result = srv_wlan_add_prof_into_dtcnt(dtcnt_prof, acc_prof_id);            
        }        
    }
    else
    {
        dtcnt_prof->priority = srv_dtcnt_wlan_get_total_prof_num() + 1;
        result = srv_wlan_add_prof_into_dtcnt(dtcnt_prof, acc_prof_id);
    }

    return result;
}


srv_wlan_result_enum srv_wlan_update_dtcnt_prof(U32 fields, srv_dtcnt_prof_wlan_struct *prof)
{
    srv_dtcnt_result_enum result;
    srv_dtcnt_store_prof_data_struct storeProfile;

    storeProfile.prof_data = prof;
    storeProfile.prof_fields = fields;
    storeProfile.prof_type = SRV_DTCNT_BEARER_WIFI;
    
    result = srv_dtcnt_store_update_prof(prof->profile_id, &storeProfile);   
    
    return (srv_wlan_result_enum)result;
}

srv_wlan_result_enum srv_wlan_query_dtcnt_prof(const U32 prof_id, U32 fields, srv_dtcnt_prof_wlan_struct *dtcnt_prof)
{
    srv_dtcnt_store_prof_data_struct profileInfo = {0};
    srv_dtcnt_result_enum result;    

    profileInfo.prof_type = SRV_DTCNT_BEARER_WIFI;
    profileInfo.prof_fields = fields;
    profileInfo.prof_data = dtcnt_prof;
    result = (srv_dtcnt_result_enum)srv_dtcnt_store_qry_prof(prof_id, &profileInfo);

    return (srv_wlan_result_enum)result;
}


MMI_BOOL srv_wlan_d2w_scan_result_ap_list_map(srv_wlan_scan_ap_info_struct *wlan_ap_info, const supc_abm_bss_info_struct *bss_info)
{
    if (!wlan_ap_info || !bss_info)
    {
        return MMI_FALSE;
    }

    memcpy(wlan_ap_info->bssid, bss_info->bssid, SRV_WLAN_WNDRV_MAC_ADDRESS_LEN);
    wlan_ap_info->channel_number = bss_info->channel_number;
    wlan_ap_info->max_rate = bss_info->max_rate;
    wlan_ap_info->privacy = bss_info->privacy;
    wlan_ap_info->rssi = bss_info->rssi;
    wlan_ap_info->ssid_len = bss_info->ssid_len;
    memcpy(wlan_ap_info->ssid, bss_info->ssid, SRV_WLAN_WNDRV_SSID_MAX_LEN);
        
    /* Network type. */
    switch (bss_info->network_type)
    {
        case WNDRV_SUPC_NETWORK_AUTO_UNKNOWN:
            //baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            wlan_ap_info->network_type = SRV_WLAN_NETWORK_TYPE_INFRA;
            break;
        case WNDRV_SUPC_NETWORK_IBSS:
            //baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_ADHOC);
            wlan_ap_info->network_type = SRV_WLAN_NETWORK_TYPE_ADHOC;
            break;
        case WNDRV_SUPC_NETWORK_INFRASTRUCTURE:
            //baseInfo->setNetworkType (SRV_DTCNT_WLAN_NETWORK_TYPE_INFRA);
            wlan_ap_info->network_type = SRV_WLAN_NETWORK_TYPE_INFRA;
            break;
    }
    
    /* Auth mode and encrypt mode. */
    if (bss_info->rsn_ie_info_p == MMI_TRUE)
    {
        /* When auth. mode is WPA2 or WPA2+PSK, the default encryption mode is AES/CCMP */
        if (bss_info->rsn_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bss_info->rsn_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_AES);
            wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_AES;
        }
        else if (bss_info->rsn_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bss_info->rsn_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
            wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_TKIP;
        }

        if(bss_info->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bss_info->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                /* Whether WPA WPA2 PSK can be searched?? */
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK); //check adhoc WPA2PSK???
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
            }
            else
            {               
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_TOTAL); // not support
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_TOTAL;
            }
        }
        else if(bss_info->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bss_info->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                /* Whether WPA WPA2 PSK can be searched??  */
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
            }
#ifndef  WIFI_AUTH_PSK_ONLY
            else if (bss_info->rsn_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
            {
                /* Whether WPA WPA2 Enterprise can be searched??  */
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY;
            }
#endif
        }
    }
    else if (bss_info->wpa_ie_info_p == MMI_TRUE)
    {
        /* When auth. mode is WPA or WPA+PSK, the default encryption mode is TKIP */
        if (bss_info->wpa_ie_info.group_cipher & WPA_CIPHER_TKIP ||
            bss_info->wpa_ie_info.pairwise_cipher & WPA_CIPHER_TKIP)
        {
            //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_TKIP);
            wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_TKIP;
        }
        else if (bss_info->wpa_ie_info.group_cipher & WPA_CIPHER_CCMP ||
            bss_info->wpa_ie_info.pairwise_cipher & WPA_CIPHER_CCMP)
        {
            //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_AES);
            wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_AES;
        }
         
        if(bss_info->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            if (bss_info->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_WPA_NONE)
            {
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA2_ONLY_PSK);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
            }
            else
            {               
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_TOTAL);// no support
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_TOTAL;
            }
        }
        else if(bss_info->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bss_info->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_PSK)
            {
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY_PSK);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA_ONLY_PSK;
            }
#ifndef  WIFI_AUTH_PSK_ONLY			
            else if (bss_info->wpa_ie_info.key_mgmt & WPA_KEY_MGMT_IEEE8021X)
            {
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WPA_ONLY);
                 wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WPA_ONLY;
            }
#endif			
        }
    }
#ifdef __WAPI_SUPPORT__
#ifndef __MMI_HIDE_WAPI__
    else if (bss_info->wapi_ie_info_p == MMI_TRUE)
    {
        if (bss_info->wapi_ie_info.group_cipher & WAPI_CIPHER_SMS4 ||
            bss_info->wapi_ie_info.pairwise_cipher & WAPI_CIPHER_SMS4)
        {
            //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
            wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_WPI;
        }
        if(bss_info->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            if (bss_info->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_PSK)
            {
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WAPIPSK);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WAPIPSK;
                //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
                wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_WPI;
            }
            else if (bss_info->wapi_ie_info.key_mgmt & WAPI_KEY_MGMT_WAI)
            {
                //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WAPICERT);
                wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WAPICERT;
                //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WPI);
                wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_WPI;
            }
        }
    }
#endif /* __MMI_HIDE_WAPI__ */
#endif
    else if (bss_info->privacy > 0)
    {
        if(bss_info->network_type == WNDRV_SUPC_NETWORK_INFRASTRUCTURE)
        {
            //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WEP);
            wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WEP;
        }
        else if (bss_info->network_type == WNDRV_SUPC_NETWORK_IBSS)
        {
            //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_WEP);
            wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_WEP;
        }
        //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_WEP);
        wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_WEP;
    }
    else
    {
        //baseInfo->setAuthMode (SRV_DTCNT_WLAN_AUTH_MODE_OPEN);
        wlan_ap_info->auth_mode = SRV_WLAN_AUTH_MODE_OPEN;               
        //baseInfo->setEncryptMode (SRV_DTCNT_WLAN_ENCRYPT_MODE_NONE);
        wlan_ap_info->encrypt_mode = SRV_WLAN_ENCRYPT_MODE_NONE;
    }

    return MMI_TRUE;
}


mmi_ret srv_wlan_scan_callback(mmi_event_struct *evt)
{
    srv_dtcnt_wlan_scan_res_ind_evt_struct *wlan_evt = (srv_dtcnt_wlan_scan_res_ind_evt_struct*)evt;
    srv_wlan_action_job_struct job = {0};
    srv_wlan_scan_res_cb_func_ptr callback = NULL;    
    srv_wlan_scan_result_struct *scan_res = NULL;
    U32 index;
        
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SCAN_CB, wlan_evt ? wlan_evt->scan_res.result : SRV_DTCNT_WLAN_SCAN_RESULT_SUCCESS);
    
    if (!evt)
    {
        return MMI_RET_OK;
    }

    mmi_frm_cb_dereg_event(EVT_ID_SRV_DTCNT_WLAN_SCAN_RES_IND, srv_wlan_scan_callback, NULL);

    job.job_type = SRV_WLAN_JOB_SCAN;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        scan_res = OslMalloc(sizeof(srv_wlan_scan_result_struct));
        scan_res->result = wlan_evt->scan_res.result;
        scan_res->scan_job_id = wlan_evt->scan_res.scan_job_id;
        scan_res->ap_list_num = wlan_evt->scan_res.ap_list_num;
            
        for (index = 0; index < SRV_WLAN_MAX_AP_LIST_NUM && index < scan_res->ap_list_num; index++)
        {
            srv_wlan_d2w_scan_result_ap_list_map(
                &(scan_res->ap_list[index]), 
                wlan_evt->scan_res.ap_list[index]);
        }

        wlan_srv_scan_result_trace(scan_res->ap_list_num, scan_res->ap_list);
        
        callback = (srv_wlan_scan_res_cb_func_ptr)job.cb_func_ptr;
        callback(scan_res->scan_job_id, job.user_data, scan_res);
        OslMfree(scan_res);
    }

    return MMI_RET_OK;
}


/* Add the action job in the end of the list. */
void srv_wlan_add_action_job(srv_wlan_job_type_enum job_type, void *callback, void* user_data)
{
    srv_wlan_action_job_struct *job = NULL, *tmp_job = NULL;

    job = OslMalloc(sizeof(srv_wlan_action_job_struct));
    job->job_type = job_type;
    job->cb_func_ptr = callback;
    job->user_data = user_data;
    job->next = NULL;
    
    if (!g_srv_wlan_cntx.action_job_list)
    {
        g_srv_wlan_cntx.action_job_list = job;
    }
    else
    {
        tmp_job = g_srv_wlan_cntx.action_job_list;
        while (tmp_job->next)
        {
            tmp_job = tmp_job->next;            
        }

        tmp_job->next = job;
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_ADD_JOB, callback, user_data);
    
}


void srv_wlan_get_action_job(srv_wlan_action_job_struct *job)
{
    srv_wlan_action_job_struct *seek_job = NULL, *pre_job = NULL;
    
    if (!job || !g_srv_wlan_cntx.action_job_list)
    {
        return;
    }

    job->cb_func_ptr = NULL;
    job->user_data = NULL;

    seek_job = g_srv_wlan_cntx.action_job_list;
    
    do
    {
        if (seek_job->job_type == job->job_type)
        {
            job->cb_func_ptr = seek_job->cb_func_ptr;
            job->user_data = seek_job->user_data;            

            if (!pre_job)
            {
                g_srv_wlan_cntx.action_job_list = seek_job->next;
            }
            else
            {
                pre_job->next = seek_job->next;
            }
            
            MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_GET_JOB, seek_job->cb_func_ptr, seek_job->user_data);

            OslMfree(seek_job);
            break;
        }
        pre_job = seek_job;
        seek_job = seek_job->next;
    }while (seek_job);
}

/* For mode switch */
MMI_BOOL srv_wlan_need_do_action(srv_dtcnt_wlan_action_enum action)
{
    srv_dtcnt_wlan_state_enum state;
    MMI_BOOL ret = MMI_FALSE;
    
    state = srv_dtcnt_wlan_state();
    if (SRV_DTCNT_WLAN_ACTION_INIT == action)
    {
        if (SRV_DTCNT_WLAN_STATE_NULL == state ||
            SRV_DTCNT_WLAN_STATE_DEINIT_WAIT == state ||
            SRV_DTCNT_WLAN_STATE_INIT_WAIT == state)
        {
            ret = MMI_TRUE;
        }
    }
    else if (SRV_DTCNT_WLAN_ACTION_DEINIT == action)
    {
        if (SRV_DTCNT_WLAN_STATE_NULL != state)
        {
            ret = MMI_TRUE;
        }
    }

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_NEED_STA_ONOFF, ret);
    return ret;
}


srv_wlan_result_enum srv_wlan_init(srv_wlan_cb_func_ptr callback, void *user_data)
{   
    MMI_BOOL is_legal = MMI_FALSE;
    srv_wlan_result_enum result;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_INIT);
    
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_INIT);
    if (is_legal)
    {        
        srv_wlan_add_action_job(SRV_WLAN_JOB_INIT, (void*)callback, user_data);
        mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_INIT_RES_IND, srv_wlan_init_callback, NULL);
        result = (srv_wlan_result_enum)srv_dtcnt_wlan_init(NULL, NULL);
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
}


srv_wlan_result_enum srv_wlan_deinit(srv_wlan_cb_func_ptr callback,void * user_data)
{
    MMI_BOOL is_legal = MMI_FALSE;
    srv_wlan_result_enum result;
    srv_wlan_cb_struct *cb;
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DEINIT);
    
    is_legal = srv_wlan_is_action_legal(SRV_DTCNT_WLAN_ACTION_DEINIT);
    if (is_legal)
    {   
#ifdef __WIFI_SNIFFER_SUPPORT__
        if (SRV_DTCNT_WLAN_STATE_SNIFFER_ON_WAIT == srv_dtcnt_wlan_state() ||
            SRV_DTCNT_WLAN_STATE_SNIFFER_ON == srv_dtcnt_wlan_state())
        {
            /* Need to close sniffer first. */
            cb = OslMalloc(sizeof(srv_wlan_cb_struct));
            cb->cb_func_ptr = (void*)callback;
            cb->user_data = user_data;
            srv_wlan_sniffer_off(srv_wlan_deinit_sniffer_auto_kill, cb);
        }
        else
#endif            
        {
            srv_wlan_add_action_job(SRV_WLAN_JOB_DEINIT, (void*)callback, user_data);            
            mmi_frm_cb_reg_event(EVT_ID_SRV_DTCNT_WLAN_DEINIT_RES_IND, srv_wlan_deinit_callback, NULL);
            result = (srv_wlan_result_enum)srv_dtcnt_wlan_deinit(NULL, NULL);
        }        
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
}


srv_wlan_req_res_enum srv_wlan_result_map(srv_wlan_res_map_src_type src_type, S32 result)
{    
    if (SRV_WLAN_RES_MAP_SRC_DTCNT == src_type) /* srv_dtcnt_wlan_req_res_enum */
    {
        if (SRV_DTCNT_WLAN_REQ_RES_TOTAL == result)
        {
            return SRV_WLAN_REQ_RES_TOTAL;
        }
        else
        {
            return (srv_wlan_req_res_enum)result;
        }
    }
    else if (SRV_WLAN_RES_MAP_SRC_SNIFFER == src_type) /* srv_wlan_sniffer_res_enum */
    {
        switch (result)
        {
            case SRV_WLAN_SNIFFER_FAIL_INVALID_CHANNEL:
            case SRV_WLAN_SNIFFER_FAIL_INVALID_SNIFFERFILTEROPTIONS:
            case SRV_WLAN_SNIFFER_FAIL_INVALID_ONOFFSWITCH: 
            case SRV_WLAN_SNIFFER_FAIL_NETWORK_IS_CONNECTED:
            case SRV_WLAN_SNIFFER_FAIL_STATE_ERROR:
            case SRV_WLAN_SNIFFER_FAIL_HW_ERROR:
            {
                return SRV_WLAN_REQ_RES_FAILED;
            }
            
            case SRV_WLAN_SNIFFER_FAIL_UNKNOWN:
            {
                return SRV_WLAN_REQ_RES_UNKNOWN_ERROR;
            }

            default:
            {
                return (srv_wlan_req_res_enum)result;
            }
        }
    }
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
    else if (SRV_WLAN_RES_MAP_SRC_APMODE == src_type) /* srv_apmode_reslut */
    {

        switch (result)
        {            
            case SRV_APMODE_UNKNOWN_ERROR:   
            {
                return SRV_WLAN_REQ_RES_UNKNOWN_ERROR;
            }
            
            case SRV_APMODE_FAILED:        
            {
                return SRV_WLAN_REQ_RES_FAILED;
            }
            
            case SRV_APMODE_CANCELLED:
            {
                return SRV_WLAN_REQ_RES_CANCELLED;            
            }

            case SRV_APMODE_BUSY:
            {
                return SRV_WLAN_REQ_RES_BUSY;
            }

            default:
            {
                return (srv_wlan_req_res_enum)result;
            }
        }        
    }
#endif    

    return SRV_WLAN_REQ_RES_FAILED;
}

    
void srv_wlan_switch_end(void *user_data, S32 result, S32 result_type) /* result_type: srv_wlan_res_map_src_type */
{
    srv_wlan_cb_struct *cb = (srv_wlan_cb_struct*)user_data;
    srv_wlan_cb_func_ptr callback;
    srv_wlan_req_res_enum res = result;

    if (-1 != result_type)
    {
        res = srv_wlan_result_map(result_type, result); 
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SWITCH_END, result);
    
    g_srv_wlan_cntx.is_switching = MMI_FALSE;
    
    if (cb && cb->cb_func_ptr)
    {
        callback = (srv_wlan_cb_func_ptr)cb->cb_func_ptr;
        callback(cb->user_data, res);
    }
    
    if (cb)
    {
        OslMfree(cb);        
    }
}


void srv_wlan_ap_switching_done(S32 result, void *user_data)
{
    srv_wlan_switch_end(user_data, result, SRV_WLAN_RES_MAP_SRC_APMODE);
}


void srv_wlan_sta_switching_done(void *user_data, srv_wlan_req_res_enum res)
{    
    srv_wlan_switch_end(user_data, res, -1);        
}


void srv_wlan_switch_ap_on(void *user_data, srv_wlan_req_res_enum res)
{
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
    if (SRV_WLAN_REQ_RES_DONE == res)
    {
        if (srv_apmode_is_on() != MMI_TRUE)
        {
            srv_apmode_switch_on(srv_wlan_ap_switching_done, user_data);
            return;
        }
    }

    srv_wlan_switch_end(user_data, res, -1);    
#endif
}


void srv_wlan_switch_sta_on(S32 result, void *user_data) /* result: srv_apmode_reslut */
{
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
    if (SRV_APMODE_OK != result)
    {
        srv_wlan_switch_end(user_data, result, SRV_WLAN_RES_MAP_SRC_APMODE);
        return;
    }
#endif
    
    if (srv_wlan_need_do_action(SRV_DTCNT_WLAN_ACTION_INIT))
    {
        srv_wlan_init(srv_wlan_sta_switching_done, user_data);            
    }
    else
    {   
        // STA is ON.
        srv_wlan_switch_end(user_data, SRV_WLAN_REQ_RES_DONE, -1);            
    }   
}


void srv_wlan_switch_sta_off(S32 result, void *user_data)
{    
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
    if (SRV_APMODE_OK != result)
    {
        srv_wlan_switch_end(user_data, result, SRV_WLAN_RES_MAP_SRC_APMODE);
        return;
    }
#endif

    if (srv_wlan_need_do_action(SRV_DTCNT_WLAN_ACTION_DEINIT))
    {
        srv_wlan_deinit(srv_wlan_sta_switching_done, user_data);
    }
    else
    {
        // STA is OFF.
        srv_wlan_switch_end(user_data, SRV_WLAN_REQ_RES_DONE, -1);
    }
}


#ifdef __WIFI_SNIFFER_SUPPORT__
void srv_wlan_deinit_sniffer_auto_kill(void *user_data, srv_wlan_sniffer_res_enum res)
{
    srv_wlan_cb_struct *cb = (srv_wlan_cb_struct*)user_data;
    srv_wlan_cb_func_ptr callback;
    srv_wlan_req_res_enum deinit_res;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DEINIT_SNIFFER_OFF, res);

    if (cb && cb->cb_func_ptr)
    {               
        if (SRV_WLAN_SNIFFER_SUCCESS != res)
        {
            callback = (srv_wlan_cb_func_ptr)cb->cb_func_ptr;
            deinit_res = srv_wlan_result_map(SRV_WLAN_RES_MAP_SRC_SNIFFER, res);
            callback(cb->user_data, deinit_res);
        }
        else
        {
            srv_wlan_deinit(cb->cb_func_ptr, cb->user_data);        
        }   

        OslMfree(cb);
    }    
}


void srv_wlan_sniffer_on_callback(
            void *user_data,
            srv_dtcnt_wlan_sniffer_on_res_struct *dtcnt_res)
{
    srv_wlan_sniffer_on_cb_func_ptr callback;
    srv_wlan_sniffer_on_res_struct wlan_res;
    srv_wlan_action_job_struct job;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SNIFFER_ON_CB);

    if (!dtcnt_res)
    {
        return;
    }
    
    switch (dtcnt_res->cb_type)
    {
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SNIFFER_ON_CB_DET, dtcnt_res->cb_type, dtcnt_res->result);
        case SRV_WLAN_SNIFFER_ON_RES:
        {
            wlan_res.cb_type = SRV_WLAN_SNIFFER_ON_RES;
            wlan_res.result = (srv_wlan_sniffer_res_enum)dtcnt_res->result;
            memset(&(wlan_res.profile), 0, sizeof(srv_wlan_prof_struct));
            
            job.job_type = SRV_WLAN_JOB_SNIFFER_ON;
            srv_wlan_get_action_job(&job);
            if (job.cb_func_ptr)
            {
                if (SRV_WLAN_SNIFFER_SUCCESS == wlan_res.result)
                {
                    srv_wlan_add_action_job(SRV_WLAN_JOB_SNIFFER_NOTI_AP, job.cb_func_ptr, job.user_data);
                }
                callback = (srv_wlan_sniffer_on_cb_func_ptr)job.cb_func_ptr;
                callback(job.user_data, &wlan_res);
            }
            break;
        }
        
        case SRV_WLAN_SNIFFER_ON_AP_INFO:
        {           
            job.job_type = SRV_WLAN_JOB_SNIFFER_NOTI_AP;
            srv_wlan_get_action_job(&job);
            if (job.cb_func_ptr)
            {
                wlan_res.cb_type = SRV_WLAN_SNIFFER_ON_AP_INFO;
                wlan_res.result = (srv_wlan_sniffer_res_enum)dtcnt_res->result;
                memset(&wlan_res.profile, 0, sizeof(srv_wlan_prof_struct)); 
                
                if (SRV_WLAN_SNIFFER_SUCCESS == wlan_res.result)
                {                
                    if (!dtcnt_res->profile)
                    {
                        /* Trace only */
                        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SNIFFER_ON_AP_ERROR);
                    }
                    else
                    {
                        srv_wlan_d2wprof_map(&wlan_res.profile, dtcnt_res->profile);
                        wlan_srv_wprof_trace(&wlan_res.profile);
                    }                    
                }
                
                callback = (srv_wlan_sniffer_on_cb_func_ptr)job.cb_func_ptr;
                callback(job.user_data, &wlan_res);
            }
            break;
        }
        
        default:
            break;
    }
}


void srv_wlan_sniffer_off_callback (
            void *user_data,
            srv_dtcnt_wlan_sniffer_res_enum res)
{
    srv_wlan_action_job_struct job;
    srv_wlan_sniffer_off_cb_func_ptr callback;

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_SNIFFER_OFF_CB, res);

    job.job_type = SRV_WLAN_JOB_SNIFFER_OFF;
    srv_wlan_get_action_job(&job);
    if (job.cb_func_ptr)
    {
        callback = (srv_wlan_sniffer_off_cb_func_ptr)job.cb_func_ptr;
        callback(job.user_data, (srv_wlan_sniffer_res_enum)res);
    }
}
#endif


MMI_BOOL srv_wlan_is_reg_info_valid(srv_wlan_reg_noti_struct *reg_info)
{
    if (!reg_info || !reg_info->cb_func_ptr)
    {
        return MMI_FALSE;
    }

    if (reg_info->reg_type < SRV_WLAN_NOTI_IP_AVAILABLE || 
        reg_info->reg_type > SRV_WLAN_NOTI_PASSIVE_DISCONN)
    {
        return MMI_FALSE;
    }
    
    return MMI_TRUE;
}


MMI_BOOL srv_wlan_reg_noti_int(srv_wlan_reg_noti_struct *reg_info)
    {
    srv_wlan_reg_noti_struct *reg_pos = NULL;
    U32 index;

    if (!srv_wlan_is_reg_info_valid(reg_info))
    {
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_RET_NOTI_FAIL);
        return MMI_FALSE;
    }

    for (index = 0; index < SRV_WLAN_REG_MAX_NUM; index++)
    {
        if (g_srv_wlan_reg_noti[index].cb_func_ptr)
        {
            if (reg_info->reg_type == g_srv_wlan_reg_noti[index].reg_type &&
                reg_info->cb_func_ptr == g_srv_wlan_reg_noti[index].cb_func_ptr &&
                reg_info->user_data == g_srv_wlan_reg_noti[index].user_data)
            {
                return MMI_TRUE;
            }
        }
        else if (!reg_pos)
        {
            reg_pos = g_srv_wlan_reg_noti + index;
            continue;
        }
    }

    if (reg_pos)
    {
        reg_pos->reg_type = reg_info->reg_type;
        reg_pos->cb_func_ptr = reg_info->cb_func_ptr;
        reg_pos->user_data = reg_info->user_data;
    return MMI_TRUE;
}
    else
    {
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_RET_NOTI_FAIL);
        return MMI_FALSE;
    }
}


MMI_BOOL srv_wlan_dereg_noti_int(srv_wlan_reg_noti_struct *reg_info)
{
    U32 index;

    if (!srv_wlan_is_reg_info_valid(reg_info))
    {
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DERET_NOTI_FAIL);
        return MMI_FALSE;
    }
        
    for (index = 0; index < SRV_WLAN_REG_MAX_NUM; index++)
    {
        if (g_srv_wlan_reg_noti[index].cb_func_ptr)
        {
            if (reg_info->reg_type == g_srv_wlan_reg_noti[index].reg_type &&
                reg_info->cb_func_ptr == g_srv_wlan_reg_noti[index].cb_func_ptr &&
                reg_info->user_data == g_srv_wlan_reg_noti[index].user_data)
            {
                memset(&g_srv_wlan_reg_noti[index], 0, sizeof(srv_wlan_reg_noti_struct));
                break;
            }
        }
    }
        
    if (SRV_WLAN_REG_MAX_NUM == index)
    {
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_UTIL_DERET_NOTI_FAIL);
        return MMI_FALSE;
    }

    return MMI_TRUE;
}


void wlan_srv_wprof_trace(const srv_wlan_prof_struct * const wlan_prof)
{
    if (!wlan_prof)
    {
        return;
    }    
   
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] ssid = %s", wlan_prof->ssid);
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_PROF_AUTH_MODE, wlan_prof->auth_mode);
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] username = %s", wlan_prof->username);
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] password = %s", wlan_prof->password);    
}


void wlan_srv_dprof_trace(const srv_dtcnt_prof_wlan_struct * const dtcnt_prof)
{
    if (!dtcnt_prof)
    {
        return;
    }    

    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] ssid = %s", dtcnt_prof->ssid);
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_PROF_AUTH_MODE, dtcnt_prof->auth_mode);
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] username = %s", dtcnt_prof->username);
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] passphrase = %s", dtcnt_prof->passphrase);
    MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] wep_key = %s", dtcnt_prof->wep_key);
}


void wlan_srv_scan_result_trace(U8 ap_list_num, srv_wlan_scan_ap_info_struct * ap_list)
{
    U32 index;
    U8 ssid[32+1] = {0};

    if (!ap_list_num || !ap_list)
    {
        return;
    }
    
    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_AP_LIST_TOTAL, ap_list_num);

    for (index = 0; index < ap_list_num; index++)
    {
        memset(ssid, 0, 33);
        memcpy(ssid, ap_list[index].ssid, 32);
        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] ap_list[%d] ssid = %s", index, ssid);
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_AP_LIST_AUTH_MODE, index, ap_list[index].auth_mode);
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_AP_NW_TYPE, index, ap_list[index].network_type);
    }
}


void wlan_srv_aplist_trace(U8 ap_list_num, srv_dtcnt_ssid_struct *ap_list)
{
    U32 index;
    U8 ssid[32+1] = {0};

    MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_AP_LIST_TOTAL, ap_list_num);

    if (!ap_list_num || !ap_list)
    {
        return;
    }    

    for (index = 0; index < ap_list_num; index++)
    {
        memset(ssid, 0, 33);
        memcpy(ssid, ap_list[index].ssid, 32);
        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] ap_list[%d] ssid = %s", index, ssid);
    }
}


void wlan_srv_ip_info_trace(srv_wlan_ip_info_struct* ip_info)
{
    U32 i = 0, j;
    CHAR *ip_list_name[] = {"ip_addr", "network", "gateway", "dns1", "dns2", NULL};    
    U8 *ip_list[5] = {0};
    ip_list[0] = ip_info->ip_addr;
    ip_list[1] = ip_info->netmask;
    ip_list[2] = ip_info->gateway;
    ip_list[3] = ip_info->dns1;
    ip_list[4] = ip_info->dns2;        
    
    while (ip_list_name[i])
    {        
        MMI_PRINT(MOD_MMI_CONN_APP, TRACE_GROUP_7, "[WLAN Srv TRACE] %s: ", ip_list_name[i]);
        MMI_TRACE(TRACE_GROUP_7, SRV_WLAN_TRC_IP_ADDR, ip_list[i][0], ip_list[i][1], ip_list[i][2], ip_list[i][3]);
        i++;
    }
}


S32 srv_wlan_hswlan_authmode_cvt(
    S32 auth_mode, /* srv_tethering_wifi_hs_auth_mode_enum or srv_wlan_auth_mode_enum */
    MMI_BOOL wlan2hs)
{
#if defined (__HOTSPOT_SUPPORT__) && defined(__IOT__)
    if (wlan2hs)
    {
        switch (auth_mode)
        {
            case SRV_WLAN_AUTH_MODE_OPEN:
            {
                return SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN;
            }
            
            case SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK:
            {
                return SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK;
            }

            default:
            {
                return -1;
            }                
        }
    }
    else
    {
        switch (auth_mode)
        {
            case SRV_TETHERING_WIFI_HS_AUTH_MODE_OPEN:
            {
                return SRV_WLAN_AUTH_MODE_OPEN;
            }
            
            case SRV_TETHERING_WIFI_HS_AUTH_MODE_WPA2_PSK:
            {
                return SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
            }

            default:
            {
                return -1;
            }                
        }
    }
#else
    return -1;
#endif
}

#endif /* __IOT__ && __MMI_WLAN_FEATURES__ */
