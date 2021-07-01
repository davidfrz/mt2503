/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 *  Router_ctrl.c
 *
 * Project:
 * -------- 
 *  IOT
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "router_ctrl.h"
#if defined(__IOT__) 
#include "mmi_features.h"
#if defined(__MMI_WLAN_FEATURES__)
#include "cbm_api.h"
#include "cbm_consts.h"
#include "app_frm_message_gprot.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "WlanSrvGprot.h"
#include "soc_api.h"
#include "app_mem_med.h"
#include "fix_size_mem.h"
#include "mmi_frm_events_gprot.h"
#include "kal_trace.h"
#include "mmi_frm_queue_gprot.h"
#include "app_thread_mutex_gprot.h"
#include "DebugInitDef_Int.h"
#include "mmi_fw_trc.h"
#ifndef __WIFI_SCAN_ONLY__

#define MMI_FRM_MAX_UPNP_CB_SLOT 5
#define UPNP_MAPPING_CHACE_NUM 20
#define UPNP_MAPPING_RANGE 80
#define UPNP_TRY_MIN(a) ((a)*90 + 2500)
#define debug_upnp

typedef kal_int32 (*upnp_parse_cb)(kal_char* buf);
#ifdef debug_upnp
#define UPNP_VALUE(v) upnp_r_v(v, __LINE__)
kal_int32 upnp_r_v(kal_int32 value, kal_int32 line)
{
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_ERROR_LINE, value, line);
    return value;
}

#else
#define UPNP_VALUE(v) v
#endif

typedef struct
{
    upnp_result_cb cb;
    void* user_data;
} MMI_UPNP_CB_INFO;

typedef struct
{
    kal_uint16 local_port;
    kal_uint16 ext_port;
} MMI_UPNP_KEEP_INFO;

typedef struct _upnp_gw_info
{
    kal_char*  controlService; // use for get ext_ip, and mapping port
    kal_char  postUrl[512]; //use for mapping port
    MMI_UPNP_CB_INFO mmi_cb_array[MMI_FRM_MAX_UPNP_CB_SLOT];
    MMI_UPNP_KEEP_INFO cache_ports[UPNP_MAPPING_CHACE_NUM];
} upnp_gw_info;

typedef struct _upnp_sub_thread_map_info
{
    kal_uint8  request_id;
    kal_uint32 count;
    upnp_request_info*  requset_data;
    upnp_result_cb cb_func;
    void* user_data;
    void* buf;
} upnp_sub_thread_map_info;

typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8  request_id;
    kal_int32 ret;
    void* user_data;
    void* res_data;
} MMI_FRM_MAPPING_MSG_INFO;

static upnp_gw_info g_upnp_cntx;
static kal_char g_ext_ip[16];
static kal_char g_local_addr[16];
static kal_char g_router_addr[16];
static kal_uint32 upnp_port;
static kal_uint16 g_upnp_inited = 0;
static kal_uint16    try_from;
static kal_uint16    mapping_base;
static kal_uint32 g_keep_ip;
static app_frm_mutex_struct upnp_mutex;

static kal_char *SearchFormat = 
"M-SEARCH * HTTP/1.1\r\n\
MX: 5\r\n\
ST: urn:schemas-upnp-org:device:InternetGatewayDevice:1\r\n\
HOST: 239.255.255.250:1900\r\n\
MAN: \"ssdp:discover\"\r\n\
Content-Length: 0\r\n\
\r\n";

static kal_char *GetFormat = 
"GET /%s HTTP/1.1\r\n\
Accept: text/xml, application/xml\r\n\
User-Agent: HC-NVS\r\n\
Host: %s:%d\r\n\
Connection: Keep-Alive\r\n\
Cache-Control: max-age=0\r\n\
\r\n";

static kal_char *HttpFormat =
"POST %s HTTP/1.1\r\n\
Host: %s:%d\r\n\
SOAPACTION: \"%s#%s\"\r\n\
CONTENT-TYPE: text/xml; charset=\"utf-8\"\r\n\
Content-Length: %d\r\n\r\n";

static kal_char *SoapFormat =
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n\
<s:Envelope xmlns:s=\"http://schemas.xmlsoap.org/soap/envelope/\" s:encodingStyle=\"http://schemas.xmlsoap.org/soap/encoding/\">\r\n\
<s:Body>\r\n<u:%s xmlns:u=\"%s\">\r\n%s</u:%s>\r\n</s:Body>\r\n</s:Envelope>\r\n";

static kal_char* Action_AddPort_Format = 
"<NewRemoteHost></NewRemoteHost>\r\n\
<NewExternalPort>%d</NewExternalPort>\r\n\
<NewProtocol>%s</NewProtocol>\r\n\
<NewInternalPort>%d</NewInternalPort>\r\n\
<NewInternalClient>%s</NewInternalClient>\r\n\
<NewEnabled>1</NewEnabled>\r\n\
<NewPortMappingDescription>%s</NewPortMappingDescription>\r\n\
<NewLeaseDuration>0</NewLeaseDuration>\r\n";

static kal_int32 upnp_tcp_exchange(kal_int8 soc_tcp_id, kal_char* buf, kal_uint32* len, upnp_parse_cb cb);
static kal_int32 sub_thread_get_ip_proc(THREAD_HANDLE thread_handle, void* user_data);
static kal_int32 sub_thread_map_ports_proc(THREAD_HANDLE thread_handle, void* user_data);
static void mmi_frm_upnp_default_cb(kal_uint8  request_id, kal_int32 ret, void* res_data, void* user_data);
static kal_int32 upnp_parse_search_data(kal_char* search_data);
static kal_int32 upnp_get_property_by_name(kal_char *xml, kal_char *name, kal_char *value);
static kal_int32 unnp_get_cache_index(kal_uint16 port);



static kal_int32 upnp_gw_init(kal_char* buf, srv_wlan_ip_info_struct* ip_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    kal_uint32 msg_count;
    kal_uint32 count = 0;
    kal_uint8* ip_addr;
    kal_int8 udp_soc;
    kal_int32 ret;
    kal_uint8 val;
    module_type mod_id;
    sockaddr_struct dest;
    sockaddr_struct fromaddr;
    ilm_struct ilm;
    app_soc_notify_ind_struct *ind_ptr;
    kal_uint8 app_id;
    kal_uint32 data_account;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GW_INIT);
#endif
    ip_addr = ip_info->ip_addr;
    kal_sprintf(g_local_addr, "%d.%d.%d.%d", *ip_addr, *(ip_addr + 1), *(ip_addr + 2), *(ip_addr + 3));
    len = strlen(g_local_addr);
    g_local_addr[len] = '\0';
    if (try_from < 2500)
    {
        try_from = UPNP_TRY_MIN(*(ip_addr + 3));
        mapping_base = try_from;
    }
    ip_addr = ip_info->gateway;
    kal_sprintf(g_router_addr, "%d.%d.%d.%d", *ip_addr, *(ip_addr + 1), *(ip_addr + 2), *(ip_addr + 3));
    len = strlen(g_router_addr);
    g_router_addr[len] = '\0';
    mod_id = (module_type)app_frm_get_current_mod_id();
#ifdef debug_upnp
    MMI_PRINT(MOD_MMI_FW, TRACE_GROUP_2, "[UPnP] enter upnp_gw_init(%s<->%s)", g_local_addr, g_router_addr);
#endif
    cbm_register_app_id(&app_id);
    data_account = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, (cbm_sim_id_enum)CBM_SIM_ID_SIM1, app_id, KAL_FALSE);

    //create udp socket
    udp_soc = soc_create(
                        SOC_PF_INET, 
                        SOC_SOCK_DGRAM, 
                        0, 
                        mod_id, 
                        data_account
                        );

    if (udp_soc < 0)
    {
        cbm_deregister_app_id(app_id);
        return UPNP_VALUE(UPNP_FAIL_CREATE_SOCKET);
    }
	
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GW_BIND_SOC, udp_soc, ret);
#endif

    val = SOC_READ | SOC_WRITE | SOC_CLOSE;
    ret = soc_setsockopt(udp_soc, SOC_ASYNC, &val, sizeof(val));

    if (ret != SOC_SUCCESS)
    {
        soc_close(udp_soc);
        cbm_deregister_app_id(app_id);
        return UPNP_VALUE(UPNP_FAIL_CREATE_SOCKET);
    }

    val = KAL_TRUE;
    ret = soc_setsockopt(udp_soc, SOC_NBIO, &val, sizeof(val));
    if (ret != SOC_SUCCESS)
    {
        soc_close(udp_soc);
        cbm_deregister_app_id(app_id);
        return UPNP_VALUE(UPNP_FAIL_CREATE_SOCKET);
    }
    //send url req.
    kal_mem_set(&dest, 0x00, sizeof(dest));
    dest.sock_type = SOC_SOCK_DGRAM;
    dest.addr_len = 4;
    kal_mem_cpy(
        dest.addr, 
        ip_info->gateway, 
        SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    dest.port = 1900;

    while (1)
    {
        msg_count = msg_get_extq_messages();
        if (msg_count > 0)
        {
            app_frm_get_thread_message(&ilm);
            if (ilm.msg_id == MSG_ID_APP_SOC_NOTIFY_IND)
            {
                ind_ptr = (app_soc_notify_ind_struct *)ilm.local_para_ptr;
                if (ind_ptr->event_type == SOC_READ)
                {
                    len = soc_recvfrom(udp_soc, 
                                        buf, 
                                        20*1024, 
                                        0, 
                                        &fromaddr);
#ifdef debug_upnp
                    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GW_READ_SEARCH_LEN, len);
#endif
                    if (len > 0)
                    {
                        buf[len] = '\0';
                        free_ilm(&ilm);
                        if (upnp_parse_search_data(buf) == UPNP_SUCCESS)
                        {
                            break;
                        }
                    }
                }
            }
            free_ilm(&ilm);
        }
        else
        {
            if (count < 40)
            {
                kal_sleep_task(500);
                ret = soc_sendto(udp_soc, 
                   SearchFormat, 
                   strlen(SearchFormat), 
                   0, 
                   &dest);
#ifdef debug_upnp
                MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GW_SEND_SEARCH_LEN, ret, count);
#endif
                count++;
                continue;
            }
            else
            {
                soc_close(udp_soc);
                cbm_deregister_app_id(app_id);
                return UPNP_VALUE(UPNP_FAIL_ROUTER_NOT_SUPPORT_UPNP);
            }
        }
    }
    soc_close(udp_soc);
    cbm_deregister_app_id(app_id);
    return UPNP_VALUE(UPNP_SUCCESS);
}
static kal_int32 upnp_mapping_port_int(kal_int8 tcp_soc, kal_char* buf, upnp_request_info* req_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = 0;
    kal_uint32 len = 0;
    kal_int32 try_port_num;
    kal_char* ptr;
    kal_char* protocal;
    kal_char* p;
    kal_int32 cache_index;
	kal_uint16* ext_port_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/

    cache_index = unnp_get_cache_index(req_info->local_port);
    if ((cache_index >= 0) && \
        (cache_index < UPNP_MAPPING_CHACE_NUM))
    {
        ext_port_p = &(g_upnp_cntx.cache_ports[cache_index].ext_port);
    }
    if ((ext_port_p != NULL) && (*ext_port_p != 0))

    {
        try_port_num = *ext_port_p;
    }
    else
    {
        try_port_num = try_from;
        try_from++;
    }    
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_TRY_MAPPING, req_info->local_port, try_port_num);
    if (req_info->mapping_protocal == UPNP_PROTOCAL_UDP)
    {
        protocal = "UDP";
    }
    else if (req_info->mapping_protocal == UPNP_PROTOCAL_TCP)
    {
        protocal = "TCP";
    }
    else
    {
        return UPNP_VALUE(UPNP_FAIL_OTHER);
    }
    ptr = buf;

    p = ptr + 10240;
    sprintf(ptr, Action_AddPort_Format, 
              try_port_num, 
              protocal, 
              req_info->local_port,                   
              g_local_addr, 
              "MTKBBM"
              );
    ret = strlen(ptr);

    sprintf(p, SoapFormat, 
               "AddPortMapping", 
               g_upnp_cntx.controlService, 
               ptr, 
               "AddPortMapping");
    ret = strlen(p);

    sprintf(ptr, HttpFormat, 
              g_upnp_cntx.postUrl, 
              g_router_addr, 
              upnp_port, 
              g_upnp_cntx.controlService, 
              "AddPortMapping", 
              ret);

    strcat(ptr, p);
    len = strlen(ptr);
    upnp_tcp_exchange(tcp_soc, ptr, &len, NULL);

    //parse response data.
    if (strstr(buf, "200 OK") == NULL)
    {
        if (ext_port_p != NULL)
        {
            *ext_port_p = 0;
        }
        return UPNP_VALUE(UPNP_FAIL_MAPPING);
    }
    else 
    {
        if (ext_port_p != NULL)
        {
            *ext_port_p = try_port_num;
        }
        req_info->ext_port = try_port_num;
        return UPNP_VALUE(UPNP_SUCCESS);
    }
}

static void upnp_clean_msg_queue()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 msg_count;
    ilm_struct ilm;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    msg_count = msg_get_extq_messages();
    while (msg_count > 0)
    {
        app_frm_get_thread_message(&ilm);
        free_ilm(&ilm);
        msg_count = msg_get_extq_messages();
    }
}
static void upnp_close_tcp_soc(kal_int8 soc_id, kal_uint8 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/ 

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    soc_close(soc_id);
    cbm_deregister_app_id(app_id);
	upnp_clean_msg_queue();
}


static kal_int8 upnp_create_tcp_soc(kal_uint8 *app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    kal_int8 soc_tcp_id;
    sockaddr_struct soc_addr;
    kal_int32 ret;
    srv_wlan_ip_info_struct ip_info;
	kal_uint32 data_account;
    kal_uint8 val;
    ilm_struct ilm;
	app_soc_notify_ind_struct* ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)
    kal_mem_set(&ip_info, 0, sizeof(srv_wlan_ip_info_struct));
    ret = srv_wlan_get_ip_info(&ip_info);
#else
    ip_info.gateway[0] = 192;
    ip_info.gateway[1] = 168;
    ip_info.gateway[2] = 1;
    ip_info.gateway[3] = 1;
    ip_info.ip_addr[0] = 192;
    ip_info.ip_addr[1] = 168;
    ip_info.ip_addr[2] = 1;
    ip_info.ip_addr[3] = 100;
#endif
    cbm_register_app_id(app_id);
    data_account = cbm_encode_data_account_id(CBM_WIFI_ACCT_ID, (cbm_sim_id_enum)CBM_SIM_ID_SIM1, *app_id, KAL_FALSE);
	ret = 15;
	upnp_clean_msg_queue();
	soc_tcp_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0/*IPPROTO_TCP*/, (module_type)app_frm_get_current_mod_id(), data_account);

	while ((ret > 0) && (soc_tcp_id < 0))
	{	
		upnp_clean_msg_queue();
		kal_sleep_task(100);
		upnp_clean_msg_queue();
		soc_tcp_id = soc_create(SOC_PF_INET, SOC_SOCK_STREAM, 0/*IPPROTO_TCP*/, (module_type)app_frm_get_current_mod_id(), data_account);
		ret--;
	}
    if (soc_tcp_id < 0)
    {		
		cbm_deregister_app_id(*app_id);
        return soc_tcp_id;
    }
	val = SOC_READ | SOC_WRITE | SOC_CONNECT | SOC_CLOSE;
    ret = soc_setsockopt(soc_tcp_id, SOC_ASYNC, &val, sizeof(val));
    if (ret < 0)
    {
        ASSERT(0);
    }

    val = KAL_TRUE;
    ret = soc_setsockopt(soc_tcp_id, SOC_NBIO, &val, sizeof(val));
    if (ret < 0)
    {
        ASSERT(0);
    }
    kal_mem_set(&soc_addr, 0x00, sizeof(soc_addr));
    soc_addr.sock_type = SOC_SOCK_STREAM;
    soc_addr.addr_len = IP_ADDR_LEN;
    soc_addr.port = upnp_port;
    kal_mem_cpy(
        soc_addr.addr, 
        ip_info.gateway, 
        SRV_WLAN_PROF_MAX_IP_ADDR_LEN);
    upnp_clean_msg_queue();
    ret = soc_connect(soc_tcp_id, &soc_addr);
    if ((ret < 0) && (SOC_WOULDBLOCK != ret))
    {
        soc_close(soc_tcp_id);
        cbm_deregister_app_id(*app_id);
        return UPNP_VALUE(ret);
    }
    while (1)
    {
        app_frm_get_thread_message(&ilm);
        ind = (app_soc_notify_ind_struct*)ilm.local_para_ptr;
        if ((ilm.msg_id == MSG_ID_APP_SOC_NOTIFY_IND)  && (ind->socket_id == soc_tcp_id))
        {
            if (ind->event_type == SOC_CONNECT)
            {
                if (ind->result != KAL_FALSE)
                {
                    //success.
                    free_ilm(&ilm);
                    break;
                }
                else
                {
                    //false
                    soc_close(soc_tcp_id);
                    cbm_deregister_app_id(*app_id);
                    free_ilm(&ilm);
                    return UPNP_VALUE(UPNP_FAIL_OTHER);
                }
            }
            else if ((ind->event_type == SOC_CLOSE) && (ind->socket_id == soc_tcp_id))
            {
                soc_close(soc_tcp_id);
                cbm_deregister_app_id(*app_id);
                free_ilm(&ilm);
                return UPNP_VALUE(UPNP_FAIL_OTHER);
			}
		}
	    free_ilm(&ilm);
	}
	upnp_clean_msg_queue();
    return soc_tcp_id;
}


static kal_int32 upnp_parse_search_data(kal_char* search_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char* p;
    kal_char* p1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_PARSE_SEARCH);
#endif
    p = strstr(search_data, "Location");
    if (!p)
    {
        p = strstr(search_data, "LOCATION");
        if (!p)
        {
            return UPNP_VALUE(UPNP_FAIL_OTHER);
        }
    }
    p1 = strstr(p, "\r\n");
    if (!p1)
    {
        return UPNP_VALUE(UPNP_FAIL_OTHER);
    }
    p[p1-p] = '\0';

    p1 = strstr(p, "http://");
    if (!p1)
    {
        return UPNP_VALUE(UPNP_FAIL_OTHER);
    }
    //parse  port postUrl
    p = p1 + 7;
    p1 = strstr(p, ":");
	if (p1 == NULL)
	{
		upnp_port = 80;
	}
	else
	{
    	sscanf(p1, ":%d", &upnp_port);
	}
    p1 = strstr(p, "/");
    strcpy(g_upnp_cntx.postUrl, p1+1);
    *p1 = '\0';
#ifdef debug_upnp
    MMI_PRINT(MOD_MMI_FW, TRACE_GROUP_2, "[UPnP] url: http://%s:%d/%s", g_router_addr, upnp_port, g_upnp_cntx.postUrl);
#endif
    return UPNP_VALUE(UPNP_SUCCESS);
}


static kal_int32 upnp_parse_description(kal_char* buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 ret = 0;
    kal_char* p;
    kal_char* p1;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
        MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_PARSE_DEACRIPTION);
#endif
    p = strstr(buf, "urn:schemas-upnp-org:device:InternetGatewayDevice:1");
    if (p == NULL)
    {
#ifdef debug_upnp
        MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_DEACRIPTION_E1);
#endif
        p = buf;
    }
    p1 = strstr(p, "urn:schemas-upnp-org:device:WANDevice:1");
    if (p1 == NULL)
    {
#ifdef debug_upnp
        MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_DEACRIPTION_E2);
#endif
    }
    else
    {
        p = p1;
    }
    p1 = strstr(p, "urn:schemas-upnp-org:device:WANConnectionDevice:1");
    if (p1 == NULL)
    {
#ifdef debug_upnp
        MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_DEACRIPTION_E3);
#endif
    }
    else
    {
        p = p1;
    }
    p1 = strstr(p, "urn:schemas-upnp-org:service:WANIPConnection:1");
    if (p1 == NULL)
    {
        p1 = strstr(p, "urn:schemas-upnp-org:service:WANPPPConnection:1");
		if(p1 != NULL)
		{
			g_upnp_cntx.controlService = "urn:schemas-upnp-org:service:WANPPPConnection:1";
		}
    }
	else
	{
		g_upnp_cntx.controlService = "urn:schemas-upnp-org:service:WANIPConnection:1";
    }
    if (p1 != NULL)
    {
        ret = upnp_get_property_by_name(p1, "controlURL", g_upnp_cntx.postUrl);
		p = strstr(g_upnp_cntx.postUrl, "http://");
		if (p != NULL)
		{
				p += 7;
		}
		else
		{
			  p = g_upnp_cntx.postUrl;
		}

		p1 = strstr(p, ":");
		if (NULL != p1)
		{
			  sscanf(p1, ":%d", &upnp_port);
			p = strstr(p1, "/");
			strcpy(g_upnp_cntx.postUrl, p);
		}
#ifdef debug_upnp
        MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_PARSE_CONTROL_URL, ret);
#endif    
        if (ret > 0)
        {
            return UPNP_VALUE(UPNP_SUCCESS);
        }
    }
    return UPNP_VALUE(UPNP_FAIL_OTHER);
}

static kal_int32 upnp_get_property_by_name(kal_char *xml, kal_char *name, kal_char *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *p1 = NULL;
    kal_char *p2 = NULL;
    kal_char startTag[32];
    kal_char endTag[32];
    kal_int32 len = strlen(name);
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    sprintf(startTag, "<%s>", name);
    sprintf(endTag, "</%s>", name);
    *(startTag + len + 2) = '\0';
    *(endTag + len + 3) = '\0';
    p1 = strstr(xml, startTag);
    if (!p1 )
    {
        return -1;
    }
    p2 = strstr(p1, endTag);
    if (!p2)
    {
        return -1;
    }

    //size enough
    memcpy(value, p1 + len + 2, p2-p1-len-2);
    value[p2-p1-len-2] = '\0';
    return strlen(value);
}

static kal_int32 upnp_tcp_send_IP_req(kal_int8 soc_tcp_id, kal_char* buf)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_char *p = buf;
    kal_char *p1 = buf + 1024;
    kal_uint32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_IP_ENTER);
#endif

    kal_sprintf(p1, SoapFormat, 
               "GetExternalIPAddress", 
               g_upnp_cntx.controlService, 
               "", 
               "GetExternalIPAddress");
    len = strlen(p1);

    kal_sprintf(p, HttpFormat, 
              g_upnp_cntx.postUrl, 
              g_router_addr, 
              upnp_port, 
              g_upnp_cntx.controlService, 
              "GetExternalIPAddress", 
              len);

    strcat(p, p1);
    len = strlen(p);
    upnp_tcp_exchange(soc_tcp_id, p, &len, NULL);

    if ((p = strstr(p, "200 OK")) == NULL)
    {
        return UPNP_VALUE(UPNP_FAIL_OTHER);
    }

    if ((p = strstr(p, "<NewExternalIPAddress"))!=NULL)
    {
        upnp_get_property_by_name(p, "NewExternalIPAddress", g_ext_ip);
    }
    return UPNP_VALUE(UPNP_SUCCESS);
}

static kal_int32 upnp_udp_send_description_req(kal_int8 soc_tcp_id, kal_char* buf)
{

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_SEND_DEACRIPTION);
#endif

    kal_sprintf(buf, GetFormat, g_upnp_cntx.postUrl, g_router_addr, upnp_port);
    len = strlen(buf);
    return upnp_tcp_exchange(soc_tcp_id, buf, &len, upnp_parse_description);
}


static kal_int32 upnp_tcp_exchange(kal_int8 soc_tcp_id, kal_char* buf, kal_uint32* len, upnp_parse_cb cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct ilm;
    app_soc_notify_ind_struct* ind;
    kal_int32 total_read = 0;
    kal_int32 read_len;
    kal_int32 ret = UPNP_SUCCESS;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/  

#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_EXCHANGE_ENTER);
#endif
    ret = soc_send(soc_tcp_id, buf, *len, 0);
    if ((ret < 0) && (SOC_WOULDBLOCK != ret))
    {
        *len = 0;
        buf[0] = '\0';
        return UPNP_VALUE(UPNP_FAIL_OTHER);
    }
    while (1)
    {
        app_frm_get_thread_message(&ilm);
        ind = (app_soc_notify_ind_struct*)ilm.local_para_ptr;
        if ((ilm.msg_id == MSG_ID_APP_SOC_NOTIFY_IND) && (ind->socket_id == soc_tcp_id))
        {
			if (ind->event_type == SOC_READ)
			{
                read_len = soc_recv(soc_tcp_id, 
                                      buf + total_read, 
                                      20*1024, 
                                      0);
                if (read_len > 0)
                {
                    total_read += read_len;
                }
#ifdef debug_upnp
                MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_EXCHANGE_READ, total_read);
#endif
               	if ((!cb) || ((cb) && cb(buf) == UPNP_SUCCESS))
               	{
                	free_ilm(&ilm);
					*len = total_read;
					ret = UPNP_SUCCESS;
                	break;
               	}
            }
            else if (ind->event_type == SOC_WRITE)
            {
#ifdef debug_upnp
                MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_EXCHANGE_WRITE);
#endif
				if(total_read == 0)
				{
	                soc_send(soc_tcp_id, buf, *len, 0);
				}
            }
            else if (ind->event_type == SOC_CLOSE)
            {
#ifdef debug_upnp
                MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_EXCHANGE_CLOSE);
#endif
	            free_ilm(&ilm);
				*len = 0;
				ret = UPNP_FAIL_OTHER;
	            break;
            }
        }
        free_ilm(&ilm);
    }
    buf[*len] = '\0';
    return UPNP_VALUE(ret);
}

/*****************************************************************************
* FUNCTION
*  sub_thread_get_ip_proc
* DESCRIPTION
*  xxx
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static kal_int32 sub_thread_get_ip_proc(THREAD_HANDLE thread_handle, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    upnp_sub_thread_map_info* req;
    kal_char* buf;
    kal_int8 soc_tcp_id;
    kal_int32 ret;
    srv_wlan_ip_info_struct ip_info;
	kal_uint8 app_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    app_frm_mutex_lock(&upnp_mutex);
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_THREAD_IP_ENTER);
#endif

    req = (upnp_sub_thread_map_info*)user_data;
    buf = req->buf;
#if defined(__MTK_TARGET__)
    kal_mem_set(&ip_info, 0, sizeof(srv_wlan_ip_info_struct));
    ret = srv_wlan_get_ip_info(&ip_info);
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GET_IP_INFO, ret, __LINE__);
#endif
#else
    ip_info.gateway[0] = 192;
    ip_info.gateway[1] = 168;
    ip_info.gateway[2] = 1;
    ip_info.gateway[3] = 1;
    ip_info.ip_addr[0] = 192;
    ip_info.ip_addr[1] = 168;
    ip_info.ip_addr[2] = 1;
    ip_info.ip_addr[3] = 100;
#endif
    if ((g_upnp_cntx.controlService == NULL) || (g_upnp_cntx.postUrl[0] == '\0'))
    {
        ret = upnp_gw_init(buf, &ip_info);
	    if (UPNP_SUCCESS != ret)
	    {
	        if (req->cb_func)
	        {
	            (req->cb_func)(req->request_id, ret, NULL, req->user_data);
	        }
	        applib_asm_free_anonymous(req->requset_data);
	        mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
	        return 0;
	    }
	    //todo:create tcp;
	    soc_tcp_id = upnp_create_tcp_soc(&app_id);
	    if (soc_tcp_id < 0)
	    {
#ifdef debug_upnp
			MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_CREATE_SOC_ERROR, soc_tcp_id, __LINE__);
#endif
	        if (req->cb_func)
	        {
	            (req->cb_func)(req->request_id, UPNP_FAIL_CREATE_SOCKET, NULL, req->user_data);
	        }
	        applib_asm_free_anonymous(req->requset_data);
	        mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
	        return 0;
	    }
        ret = upnp_udp_send_description_req(soc_tcp_id, buf);
        upnp_close_tcp_soc(soc_tcp_id, app_id);
        if (UPNP_SUCCESS != ret)
        {
            if (req->cb_func)
            {
                (req->cb_func)(req->request_id, ret, NULL, req->user_data);
            }
            applib_asm_free_anonymous(req->requset_data);
	        mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
	        return 0;
	    }
	}
    soc_tcp_id = upnp_create_tcp_soc(&app_id);
    if (soc_tcp_id < 0)
    {
#ifdef debug_upnp
		MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_CREATE_SOC_ERROR, soc_tcp_id, __LINE__);
#endif
        if (req->cb_func)
        {
            (req->cb_func)(req->request_id, UPNP_FAIL_CREATE_SOCKET, NULL, req->user_data);
        }
        applib_asm_free_anonymous(req->requset_data);
        mmi_frm_free(req);
        app_frm_mutex_unlock(&upnp_mutex);
        return 0;
    }

    ret = upnp_tcp_send_IP_req(soc_tcp_id,  buf);

    upnp_close_tcp_soc(soc_tcp_id, app_id);


    if (UPNP_SUCCESS != ret)
    {
        if (req->cb_func)
        {
            (req->cb_func)(req->request_id, ret, NULL, req->user_data);
        }
        applib_asm_free_anonymous(req->requset_data);
        mmi_frm_free(req);
        app_frm_mutex_unlock(&upnp_mutex);
        return 0;
    }
    g_keep_ip = 2;
#ifdef debug_upnp
	MMI_PRINT(MOD_MMI_FW, TRACE_GROUP_2, "[UPnP] invoke cb, ext_ip %s", g_ext_ip);
#endif    
    if (req->cb_func)
    {
        strcpy((char*)req->requset_data, g_ext_ip);
        (req->cb_func)(req->request_id, ret, (void*)req->requset_data, req->user_data);
    }
    mmi_frm_free(req);
    app_frm_mutex_unlock(&upnp_mutex);
    return 0;
}

/*****************************************************************************
* FUNCTION
*  sub_thread_map_ports_proc
* DESCRIPTION
*  xxx
* PARAMETERS
* RETURNS
*  void
*****************************************************************************/
static kal_int32 sub_thread_map_ports_proc(THREAD_HANDLE thread_handle, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    upnp_sub_thread_map_info* req;
    kal_uint32 i;
    kal_char* buf;
    kal_int32 ret;
	kal_uint32 fail_count;
    srv_wlan_ip_info_struct ip_info;
    kal_uint8 app_id;
    kal_int8 soc_tcp_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    app_frm_mutex_lock(&upnp_mutex);
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_THREAD_MAPPING_ENTER);
#endif
    req = (upnp_sub_thread_map_info*)user_data;
    buf = req->buf;
#if defined(__MTK_TARGET__)
    kal_mem_set(&ip_info, 0, sizeof(srv_wlan_ip_info_struct));
    ret = srv_wlan_get_ip_info(&ip_info);
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GET_IP_INFO, ret, __LINE__);
#else
    ip_info.gateway[0] = 192;
    ip_info.gateway[1] = 168;
    ip_info.gateway[2] = 1;
    ip_info.gateway[3] = 1;
    ip_info.ip_addr[0] = 192;
    ip_info.ip_addr[1] = 168;
    ip_info.ip_addr[2] = 1;
    ip_info.ip_addr[3] = 100;
#endif
    if ((g_upnp_cntx.controlService == NULL) || (g_upnp_cntx.postUrl[0] == '\0'))
    {
        ret = upnp_gw_init(buf, &ip_info);
        if (UPNP_SUCCESS != ret)
        {
            if (req->cb_func)
            {
                (req->cb_func)(req->request_id, ret, NULL, req->user_data);
            }
            applib_asm_free_anonymous(req->requset_data);
            mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
            return ret;
        }
		//todo:create tcp;
		soc_tcp_id = upnp_create_tcp_soc(&app_id);
		if (soc_tcp_id < 0)
		{
#ifdef debug_upnp
			MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_CREATE_SOC_ERROR, soc_tcp_id, __LINE__);
#endif
			if (req->cb_func)
			{
				(req->cb_func)(req->request_id, UPNP_FAIL_CREATE_SOCKET, NULL, req->user_data);
			}
			applib_asm_free_anonymous(req->requset_data);
			mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
            return 0;
        }
        ret = upnp_udp_send_description_req(soc_tcp_id, buf);

        upnp_close_tcp_soc(soc_tcp_id, app_id);

        if (UPNP_SUCCESS != ret)
        {
            if (req->cb_func)
            {
                (req->cb_func)(req->request_id, ret, NULL, req->user_data);
            }
            applib_asm_free_anonymous(req->requset_data);
            mmi_frm_free(req);
            app_frm_mutex_unlock(&upnp_mutex);
            return ret;
        }
    }
	fail_count = 0;
    for (i = 0; i < req->count; i++)
    {
        do
        {
			fail_count++;
			if (fail_count > 20 + i)
			{
                if (req->cb_func)
                {
                    (req->cb_func)(req->request_id, UPNP_FAIL_MAPPING, NULL, req->user_data);
                }
                applib_asm_free_anonymous(req->requset_data);
                mmi_frm_free(req);
                app_frm_mutex_unlock(&upnp_mutex);
                return UPNP_VALUE(UPNP_FAIL_MAPPING);				
			}
            soc_tcp_id = upnp_create_tcp_soc(&app_id);
            if (soc_tcp_id < 0)
            {
#ifdef debug_upnp
    			MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_CREATE_SOC_ERROR, soc_tcp_id, __LINE__);
#endif
                if (req->cb_func)
                {
                    (req->cb_func)(req->request_id, UPNP_FAIL_CREATE_SOCKET, NULL, req->user_data);
                }
                applib_asm_free_anonymous(req->requset_data);
                mmi_frm_free(req);
                app_frm_mutex_unlock(&upnp_mutex);
                return 0;
            }
            ret = upnp_mapping_port_int(soc_tcp_id, buf, &(req->requset_data[i]));
            upnp_close_tcp_soc(soc_tcp_id, app_id);

        } while (UPNP_SUCCESS != ret);
    }
    if (try_from >= mapping_base + UPNP_MAPPING_RANGE)
    {
        try_from = mapping_base;
    }
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_INVOKE_MAPPING_CB);
#endif
    if (req->cb_func)
    {
        (req->cb_func)(req->request_id, UPNP_SUCCESS, (void*)req->requset_data, req->user_data);
    }
    if (req->cb_func != mmi_frm_upnp_default_cb)
    {
        applib_asm_free_anonymous(req->requset_data);
    }
    mmi_frm_free(req);
    app_frm_mutex_unlock(&upnp_mutex);
    return 0;
}

static kal_int32 unnp_get_cache_index(kal_uint16 port)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    kal_int32 empty_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
    empty_index = -1;
    for (i = 0; i < UPNP_MAPPING_CHACE_NUM; i++)
    {
        if (g_upnp_cntx.cache_ports[i].local_port == port)
        {
            return i;
        }
        else if ((g_upnp_cntx.cache_ports[i].local_port == 0) && (empty_index == -1))
        {
            empty_index = i;
        }
    }
    if ((empty_index >= 0) && (empty_index < UPNP_MAPPING_CHACE_NUM))
    {
        g_upnp_cntx.cache_ports[empty_index].local_port = port;
        g_upnp_cntx.cache_ports[empty_index].ext_port = 0;
    }
    return empty_index;
}

static MMI_UPNP_CB_INFO* mmi_frm_get_free_cb_slot()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/  
    for( i = 0; i < MMI_FRM_MAX_UPNP_CB_SLOT; i++)
    {
        if (g_upnp_cntx.mmi_cb_array[i].cb == NULL)
            return &(g_upnp_cntx.mmi_cb_array[i]);
    }
    return NULL;
}
static void mmi_frm_free_cb_slot(MMI_UPNP_CB_INFO* slot)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_int32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/ 
    for( i = 0; i < MMI_FRM_MAX_UPNP_CB_SLOT; i++)
    {
        if (&g_upnp_cntx.mmi_cb_array[i] == slot)
        {
            slot->cb = NULL;
            return;
        }
    }
    // logic error.
    return;
}

static kal_int8 mmi_frm_mapping_event_handler (void *msg, S32 mod_src, ilm_struct *ilm)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UPNP_CB_INFO* cb_info;
    MMI_FRM_MAPPING_MSG_INFO * local_param;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/

    local_param = (MMI_FRM_MAPPING_MSG_INFO*)msg;
    cb_info = (MMI_UPNP_CB_INFO*)local_param->user_data;
    if (cb_info)
    {
        if (cb_info->cb)
        {
            cb_info->cb(
                local_param->request_id, 
                local_param->ret, 
                local_param->res_data, 
                cb_info->user_data
                );
        }
        mmi_frm_free_cb_slot(cb_info);
    }
    if (local_param->res_data)
    {
        applib_asm_free_anonymous(local_param->res_data);
    }
    return 0;
}


static void mmi_frm_upnp_default_cb(kal_uint8  request_id, kal_int32 ret, void* res_data, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct ilm;
    MMI_FRM_MAPPING_MSG_INFO * local_param;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_MMI_DEFAULT_CB);
#endif

    //check task,   
    memset(&ilm , 0x00, sizeof(ilm_struct));
    ilm.src_mod_id = (module_type)app_frm_get_current_mod_id();
    local_param = (MMI_FRM_MAPPING_MSG_INFO *)mmi_construct_msg_local_para(sizeof(MMI_FRM_MAPPING_MSG_INFO));
    local_param->request_id = request_id;
    local_param->res_data = res_data;
    local_param->ret = ret;
    local_param->user_data = user_data;
    if (MOD_MMI == ilm.src_mod_id)
    {
        //call back mmi cb.
        mmi_frm_mapping_event_handler((void *)local_param, MOD_MMI, NULL);
        mmi_free_msg_local_para(local_param);
    }
    else
    {
        //send MSG_ID_APP_UPNP_MAPPING_IND msg to mmi task. 
        ilm.local_para_ptr = (local_para_struct*)local_param;
        ilm.dest_mod_id = MOD_MMI;
        ilm.msg_id = (msg_type)MSG_ID_APP_UPNP_MAPPING_IND;
        ilm.peer_buff_ptr = NULL;
        msg_send(&ilm);
    }
}
#endif
#endif /* defined(__MMI_WLAN_FEATURES__) */

extern void mmi_frm_mapping_ports_init()
{
#if (!defined(__WIFI_SCAN_ONLY__) && defined(__MMI_WLAN_FEATURES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/

    //register event handler
    SetProtocolEventHandler((PsIntFuncPtr)mmi_frm_mapping_event_handler, MSG_ID_APP_UPNP_MAPPING_IND);
    app_frm_mutex_create(&upnp_mutex);
    return;
#endif    
}

extern void mmi_frm_get_ext_ip(kal_uint8  request_id, upnp_result_cb cb, void* user_data)
{
#if (!defined(__WIFI_SCAN_ONLY__) && defined(__MMI_WLAN_FEATURES__))

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UPNP_CB_INFO* cb_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_MMI_GET_IP);
#endif

    cb_info = mmi_frm_get_free_cb_slot();
    cb_info->cb = cb;
    cb_info->user_data = user_data;
    upnp_get_ext_ip(request_id,  mmi_frm_upnp_default_cb, cb_info);
    return;
#endif    
}

extern void mmi_frm_mapping_ports(kal_uint8  request_id, upnp_result_cb cb, upnp_map_info* request_data, void* user_data)
{
#if (!defined(__WIFI_SCAN_ONLY__) && defined(__MMI_WLAN_FEATURES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_UPNP_CB_INFO* cb_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_MMI_MAPPING_ENTER);
#endif

    cb_info = mmi_frm_get_free_cb_slot();
    cb_info->cb = cb;
    cb_info->user_data = user_data;
    upnp_map_ports(request_id,  mmi_frm_upnp_default_cb, request_data, cb_info);
    return;
#endif    
}

void upnp_get_ext_ip(kal_uint8  request_id, upnp_result_cb cb_func, void* user_data)
{
    
#if (!defined(__WIFI_SCAN_ONLY__) && defined(__MMI_WLAN_FEATURES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    upnp_sub_thread_map_info* req;
    kal_char* ext_ip;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_GET_IP_ENTER);
#endif

    if (g_upnp_inited == 0)
    {
        g_upnp_inited = 1;
    }
    if (g_ext_ip[0] != '\0')
    {
        ext_ip = applib_asm_alloc_anonymous(16);
        if (cb_func)
        {
            strcpy(ext_ip, g_ext_ip);
            cb_func(request_id, UPNP_SUCCESS, ext_ip, user_data);
        }
		g_keep_ip--;
		if (g_keep_ip <= 0)
		{
			g_ext_ip[0] = '\0';
        }
        return;
    }
    else
    {
        //todo start thread to get ext_ip
        req = mmi_frm_malloc(sizeof(upnp_sub_thread_map_info));
        req->request_id = request_id;
        req->count = 0;
        req->cb_func = cb_func;
        req->user_data = user_data;
        req->requset_data = applib_asm_alloc_anonymous(20*1024);
        req->buf = req->requset_data + 16;
        if (0 ==  app_frm_create_thread(
                            sub_thread_get_ip_proc, 
                            req, 
                            0, 
                            THREAD_TYPE_NATIVE, 
                            0
                            ))
        {
            applib_asm_free_anonymous(req->requset_data);
            mmi_frm_free(req);
            if (cb_func)
                cb_func(request_id, UPNP_FAIL_CREATE_THREAD, NULL, user_data);
            return;
        }
    }
#endif
}

void upnp_map_ports(kal_uint8  request_id, upnp_result_cb cb_func, upnp_map_info* request_data, void* user_data)
{
#if (!defined(__WIFI_SCAN_ONLY__) && defined(__MMI_WLAN_FEATURES__))
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    upnp_sub_thread_map_info* req;
    kal_uint32 len;
    /*----------------------------------------------------------------*/
    /* Code Body                                                       */
    /*----------------------------------------------------------------*/
#ifdef debug_upnp
    MMI_TRACE(TRACE_GROUP_2, MMI_UPNP_MAPPING_ENTER);
#endif

    req = mmi_frm_malloc(sizeof(upnp_sub_thread_map_info));
    req->request_id = request_id;
    req->count = request_data->count;
    req->cb_func = cb_func;
    req->user_data = user_data;
    len = sizeof(upnp_request_info) * request_data->count;
    req->requset_data = applib_asm_alloc_anonymous(len + 20*1024);
    if (g_upnp_inited == 0)
    {
        g_upnp_inited = 1;
    }
    if (req->requset_data == NULL)
    {
        mmi_frm_free(req);
        if (cb_func)
            cb_func(request_id, UPNP_FAIL_NO_MEMORY, NULL, user_data);
        return;
    }
    memcpy(req->requset_data, request_data->requset_data, len);
    req->buf = req->requset_data + len;

    if (0 ==  app_frm_create_thread(
                    sub_thread_map_ports_proc, 
                    req, 
                    0, 
                    THREAD_TYPE_NATIVE, 
                    0
                    ))
    {
        applib_asm_free_anonymous(req->requset_data);
        mmi_frm_free(req);
        if (cb_func)
            cb_func(request_id, UPNP_FAIL_CREATE_THREAD, NULL, user_data);
        return;
    }
    #endif
}

#endif /* __IOT__ */
