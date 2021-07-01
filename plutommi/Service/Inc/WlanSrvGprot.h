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
 *  WlanSrvGprot.h
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
#ifndef __WLAN_SRV_GPROT_H__
#define __WLAN_SRV_GPROT_H__

#include "mmi_features.h"
// #if defined(__IOT__) && defined(__MMI_WLAN_FEATURES__)
#ifndef __WIFI_SCAN_ONLY__

#include "MMIDataType.h"
#include "cbm_consts.h"

/* WLAN Services include files */
#include "wndrv_cnst.h"         /* WNDRV_XXX constants */
#include "supc_abm_msgs.h"      /* wlan supc related structures */

#ifndef CODEGEN_DTCNT_SRV /* for codegen */
#include "mmi_rp_srv_dtcnt_def.h"
#include "MMI_features.h"
//#ifdef __CCA_SUPPORT__
#ifdef __MMI_CCA_SUPPORT__
/* CCA Services include files */
#include "CcaSrvGprot.h"
#endif /* __CCA_SUPPORT__ */
#endif /* CODEGEN_DTCNT_SRV */

#include "mmi_res_range_def.h"
#include "kal_general_types.h"
#include "ps_public_enum.h"
#include "mmi_frm_utility_gprot.h"
#include "custom_data_account.h"
#include "DtcntSrvGprot.h"
#include "DtcntSrvIprot.h"

/****************************************************************************/
/* Definitions                                                              */
/****************************************************************************/
#define __SRV_WLAN_DEFINES__

/* --- SSID Length --------------------------------------------------------- */
/* WNDRV_SSID_MAX_LEN */ 
#define SRV_WLAN_WNDRV_SSID_MAX_LEN          (32)

/* --- MAC Address Length -------------------------------------------------- */
/* WNDRV_MAC_ADDRESS_LEN */
#define SRV_WLAN_WNDRV_MAC_ADDRESS_LEN       (6)

/* Maximum length of WLAN SSID attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_SSID_LEN          (SRV_WLAN_WNDRV_SSID_MAX_LEN)

/* Maximum length of profile IP address length in WLAN profile */
#define SRV_WLAN_PROF_MAX_IP_ADDR_LEN      (4)
#define SRV_WLAN_PROF_MAX_PROXY_ADDR_LEN   (63)

/* Maximum length of proxy auth ID attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_PX_AUTH_ID_LEN   (40)

/* Maximum length of proxy auth password attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_PX_AUTH_PW_LEN   (40)

/* Maximum length of homepage attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_HOMEPAGE_LEN     (256)

/* Maximum length of WLAN profile name attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_WLAN_PROF_NAME_LEN   (SRV_WLAN_PROF_MAX_SSID_LEN)

/* Maximum length of username attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_USER_LEN         (31)

/* Maximum length of WLAN profile passphrase attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_PASSPHRASE_LEN       (64)

/* Maximum length of WLAN profile psk attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_PSK_LEN              (34)

/* Maximum length of WLAN profile wep key attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_WEP_KEY_LEN          (26)

/* Maximum length of password attribute in WLAN profile */
#define SRV_WLAN_PROF_MAX_PW_LEN           (31)

/* Maximum length of password attribute of all kinds in WLAN profile */
#define SRV_WLAN_PROF_PSWD_MAX_LEN          (64)

#define SRV_WLAN_MAX_SPEC_SSID_LIST_NUM    (7)

/* MAX WLAN profile number */
#ifdef __WIFI_SLIM__
#define SRV_MAX_WLAN_ACCOUNT_NUM  (10)
#else
#define SRV_MAX_WLAN_ACCOUNT_NUM  (30)		
#endif

/* Maximum number of AP list search result */
#if defined(__IOT__)
    #define SRV_WLAN_MAX_AP_LIST_NUM  (16)
#else
#ifdef __WIFI_SLIM__
#define SRV_WLAN_MAX_AP_LIST_NUM  (8)
#else
#define SRV_WLAN_MAX_AP_LIST_NUM  (30)
#endif
#endif

#ifdef __WAPI_SUPPORT__
#define SRV_WLAN_WAPI_PSK_STR_LEN  (32+1)			/* WAPI PSK string length */
#endif /* __WAPI_SUPPORT__ */

/* Profile fields */

/* Set SSID field in wlan account profile */
#define SRV_WLAN_PROF_FIELD_SSID                  (0x00000002)

/* Set auth type field in wlan account profile */
#define SRV_WLAN_PROF_FIELD_AUTH_TYPE             (0x00000400)

/* Set username field in wlan account profile */
#define SRV_WLAN_PROF_FIELD_USER                  (0x00080000)

/* Set password field in wlan account profile */
#define SRV_WLAN_PROF_FIELD_PW                    (0x00100000)

#if 0
/* under construction !*/
/* under construction !*/
#endif

/* Set All fields */
#define SRV_WLAN_PROF_FIELD_ALL                   (0xFFFFFFFF)

/****************************************************************************/
/* Enum                                                              */
/****************************************************************************/
#define __SRV_WLAN_ENUMS__

/* WLAN services result enum */
typedef enum
{
    SRV_WLAN_RESULT_SUCCESS    = 0,    /* success */
    SRV_WLAN_RESULT_FAILED,            /* general failed case */
    SRV_WLAN_RESULT_PROCESSING,        /* processing state implies Event notify */
    SRV_WLAN_RESULT_STATE_ERROR,       /* service status error */
    SRV_WLAN_RESULT_INVALID_INPUT,     /* the input parameter is invalid */
    SRV_WLAN_RESULT_ABORTED,           /* the process is aborted */
    SRV_WLAN_RESULT_TERMINATED,        /* the process is terminated */
    SRV_WLAN_RESULT_ONE_STORE_EXISTS,  /* currently only support one store */
    SRV_WLAN_RESULT_STORE_NOT_COMMIT,  /* store doesn't be config commited before */
    SRV_WLAN_RESULT_INVALID_STORE,     /* store invalid */
    SRV_WLAN_RESULT_STORE_FULL,        /* reach maximum profile storage */
    SRV_WLAN_RESULT_READ_ONLY,         /* can't delete or update read_only profile */
    SRV_WLAN_RESULT_FIRST_BOOTUP,      /* first bootup rerurn code for store open */
    SRV_WLAN_RESULT_RESET_FACTORY,     /* the data base sim profiles folder is deleted */
    SRV_WLAN_RESULT_FS_ERROR,          /* the database file system error */
    SRV_WLAN_RESULT_IGNORE,
    SRV_WLAN_RESULT_TOTAL
} srv_wlan_result_enum;


/* WLAN set mode enum */
typedef enum
{
    SRV_WLAN_SET_MODE_NONE,
    SRV_WLAN_SET_MODE_OFF,              /* OFF */
    SRV_WLAN_SET_MODE_AP,               /* AP only*/
    SRV_WLAN_SET_MODE_STA,              /* STA only */
    SRV_WLAN_SET_MODE_AP_STA,           /* AP+STA */

    SRV_WLAN_SET_MODE_TOTAL
}srv_wlan_set_mode_enum;


/* WLAN mode status enum */
typedef enum
{
    SRV_WLAN_MODE_STATUS_OFF,              /* OFF */
    SRV_WLAN_MODE_STATUS_OFF_SWITCHING,
    SRV_WLAN_MODE_STATUS_AP,               /* AP only*/
    SRV_WLAN_MODE_STATUS_AP_SWITCHING,
    SRV_WLAN_MODE_STATUS_STA,              /* STA only */
    SRV_WLAN_MODE_STATUS_STA_SWITCHING,
    SRV_WLAN_MODE_STATUS_AP_STA,           /* AP+STA */
    SRV_WLAN_MODE_STATUS_AP_STA_SWITCHING,
    SRV_WLAN_MODE_STATUS_ERROR,

    SRV_WLAN_MODE_STATUS_TOTAL
} srv_wlan_mode_status_enum;


/* WLAN station status enum */
typedef enum
{
    SRV_WLAN_STA_STATUS_INACTIVE      = 0x01, /* inactive state */
    SRV_WLAN_STA_STATUS_ACTIVE        = 0x02, /* active state */
    SRV_WLAN_STA_STATUS_CONNECTED     = 0x04, /* connected state */
    SRV_WLAN_STA_STATUS_INVALID_MAC   = 0x08, /* current MAC address isn't valid, OR'd with ACTIVE and CONNECTED status */
    SRV_WLAN_STA_STATUS_SNIFFER       = 0x10, /* sniffer status */
    SRV_WLAN_STA_STATUS_BUSY          = 0x20, /* status changing */

    SRV_WLAN_STA_STATUS_TOTAL         = 0xFF
} srv_wlan_sta_status_enum;


/* WLAN request result enum */
typedef enum
{
    SRV_WLAN_REQ_RES_DONE = 0,    /* request completed successfully */
    SRV_WLAN_REQ_RES_TERMINATED,  /* request is terminated by newer request */
    SRV_WLAN_REQ_RES_DUPLICATED,  /* request is removed by newer same request */
    SRV_WLAN_REQ_RES_FAILED,      /* request is ignored due to state error */
    SRV_WLAN_REQ_RES_ADD_BY_SRV,
    SRV_WLAN_REQ_RES_UNKNOWN_ERROR,
    SRV_WLAN_REQ_RES_CANCELLED,
    SRV_WLAN_REQ_RES_BUSY,
    
    SRV_WLAN_REQ_RES_TOTAL
} srv_wlan_req_res_enum;

/* causes */
typedef enum
{
    SRV_WLAN_TIMEOUT,
    SRV_WLAN_LOST_COVERAGE,
    SRV_WLAN_NORMAL_REJ,
    SRV_WLAN_CONNECT_FAIL,
    SRV_WLAN_AUTH_FAIL,
    SRV_WLAN_CAUSE_COUNT,
    SRV_WLAN_UNSUPPORTED_EAP_TYPE, //add for WiFi UE enhancement
    SRV_WLAN_WRONG_USER_INFO,      //add for WiFi UE enhancement
    SRV_WLAN_LOW_RSSI, // when RSSI < -85dBm . indicate this cause
    SRV_WLAN_INVALID_CAUSE
} srv_wlan_cause_enum; /* same as supc_abm_cause_enum */

/* connection type */
typedef enum
{
    SRV_WLAN_ALL_PROFILE_ENABLE,
    SRV_WLAN_ONE_PROFILE_SELECT,
    SRV_WLAN_START_WPS_PIN,
    SRV_WLAN_START_WPS_PBC
} srv_wlan_connection_type_enum; /* supc_connection_type_enum */

/* AP type */
typedef enum
{
    SRV_WLAN_AP_USER_DEFINE,
    SRV_WLAN_AP_DEFAULT,
    SRV_WLAN_AP_UNKNOW,
    SRV_WLAN_AP_BLACK_LIST,
    SRV_WLAN_AP_END
}srv_wlan_ap_type_enum;

/* WEP key format */
typedef enum
{
    SRV_WLAN_WEP_KEY_FORMAT_HEX,  /* HEX encoded */
    SRV_WLAN_WEP_KEY_FORMAT_ASCII,/* ASCII encoded */
    SRV_WLAN_WEP_KEY_FORMAT_TOTAL
} srv_wlan_wep_key_format_enum;

/* wlan network type enum */
typedef enum
{
    SRV_WLAN_NETWORK_TYPE_INFRA,  /* infrasturcture mode */
    SRV_WLAN_NETWORK_TYPE_ADHOC,  /* ad-hoc mode */
    SRV_WLAN_NETWORK_TYPE_TOTAL
} srv_wlan_network_type_enum;

/* wlan auth.mode enum */
typedef enum
{
    SRV_WLAN_AUTH_MODE_OPEN,                     /* Open Network */
    SRV_WLAN_AUTH_MODE_WEP,                      /* WEP */
    SRV_WLAN_AUTH_MODE_IEEE8021X,                /* IEEE802.1x */
    SRV_WLAN_AUTH_MODE_WPA_ONLY,                 /* WPA Enterprise */
    SRV_WLAN_AUTH_MODE_WPA_ONLY_PSK,             /* WPA Only PSK */
    SRV_WLAN_AUTH_MODE_WAPICERT,                 /* WAPICERT */
    SRV_WLAN_AUTH_MODE_WAPIPSK,                  /* WAPIPSK */
    
    SRV_WLAN_AUTH_MODE_WPA2_ONLY,                /* WPA2 Enterprise */
    SRV_WLAN_AUTH_MODE_WPA_WPA2_MIX,             /* WPA WPA2 Mix Enterprise */
    SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK,           /* WPA2 Only PSK */
    SRV_WLAN_AUTH_MODE_WPA_WPA2_MIX_PSK,         /* WPA WPA2 Mix PSK */
    SRV_WLAN_AUTH_MODE_TOTAL
} srv_wlan_auth_mode_enum;

/* wlan encrypt mode */
typedef enum
{
    SRV_WLAN_ENCRYPT_MODE_NONE,   /* unencrypt mode */
    SRV_WLAN_ENCRYPT_MODE_WEP,    /* WEP mode */
    SRV_WLAN_ENCRYPT_MODE_TKIP,   /* TKIP mode */
    SRV_WLAN_ENCRYPT_MODE_AES,    /* AES mode */
    SRV_WLAN_ENCRYPT_MODE_WPI,    /* WPI mode */
    SRV_WLAN_ENCRYPT_MODE_TKIP_AES, /*TKIP_CCMP */
    SRV_WLAN_ENCRYPT_MODE_TOTAL
} srv_wlan_encrypt_mode_enum;

/* wlan wep key encrypt mode */
typedef enum
{
    SRV_WLAN_WEP_KEY_ENCRYPT_64,  /* 64 */
    SRV_WLAN_WEP_KEY_ENCRYPT_128, /* 128 */
    SRV_WLAN_WEP_KEY_ENCRYPT_TOTAL
} srv_wlan_wep_key_encrypt_enum;

/* WLAN scan result enum */
typedef enum
{
    SRV_WLAN_SCAN_RESULT_SUCCESS = 0,   /* WLAN scan success */
    SRV_WLAN_SCAN_RESULT_FAILED,        /* WLAN scan failed */
    SRV_WLAN_SCAN_RESULT_ABORTED,       /* WLAN scan service is aborted */
    SRV_WLAN_SCAN_RESULT_DELETE,        /* WLAN scan delete in CONNECT_WAIT */
    SRV_WLAN_SCAN_RESULT_TOTAL
} srv_wlan_scan_result_enum;

/* sniffer on callback type */
typedef enum
{
    SRV_WLAN_SNIFFER_ON_RES,
    SRV_WLAN_SNIFFER_ON_AP_INFO,

    SRV_WLAN_SNIFFER_ON_END
}srv_wlan_sniffer_on_cb_type_enum;

/* sniffer result enum */
typedef enum
{  
   SRV_WLAN_SNIFFER_SUCCESS = 0,
   SRV_WLAN_SNIFFER_FAIL_INVALID_CHANNEL,
   SRV_WLAN_SNIFFER_FAIL_INVALID_SNIFFERFILTEROPTIONS,
   SRV_WLAN_SNIFFER_FAIL_INVALID_ONOFFSWITCH,
   SRV_WLAN_SNIFFER_FAIL_NETWORK_IS_CONNECTED,   
   SRV_WLAN_SNIFFER_FAIL_UNKNOWN,
   SRV_WLAN_SNIFFER_FAIL_STATE_ERROR,
   SRV_WLAN_SNIFFER_FAIL_HW_ERROR
} srv_wlan_sniffer_res_enum;

/* notification type */
typedef enum
{
    SRV_WLAN_NOTI_NONE,
    SRV_WLAN_NOTI_IP_AVAILABLE,
    SRV_WLAN_NOTI_PASSIVE_DISCONN,        
    
    SRV_WLAN_NOTI_END = 0xFFFF
}srv_wlan_noti_type_enum;

/* Connected ap info type */ 
typedef enum
{
    SRV_WLAN_AP_INFO_BSSID,
    SRV_WLAN_AP_INFO_PROF_ID,
    SRV_WLAN_AP_INFO_RSSI,
    SRV_WLAN_AP_INFO_ALL,

    SRV_WLAN_AP_INFO_END = 0xFFFF
}srv_wlan_ap_info_type_enum;

/* scan param type */
typedef enum
{
    SRV_WLAN_SCAN_PARAM_DWELL_TIME,
    SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST,
    
    SRV_WLAN_SCAN_PARAM_END = 0xFFFF
}srv_wlan_scan_param_type_enum;


/* Custom config apmode para enum */
typedef enum
{
    SRV_WLAN_CFG_AP_PARA_AUTH_MODE = 0x00000001, /* AP mode */
    SRV_WLAN_CFG_AP_PARA_SSID = 0x00000002, /* AP mode */
    SRV_WLAN_CFG_AP_PARA_PWD = 0x00000004, /* AP mode */
    
    SRV_WLAN_CFG_AP_PARA_ALL = SRV_WLAN_CFG_AP_PARA_AUTH_MODE |
                               SRV_WLAN_CFG_AP_PARA_SSID |  
                               SRV_WLAN_CFG_AP_PARA_PWD, /*All parameter */

    SRV_WLAN_CFG_AP_PARA_END
} srv_wlan_cfg_ap_para_enum;  /* Same as srv_apmode_config_para_enum */


/****************************************************************************/
/* Struct                                                              */
/****************************************************************************/
#define __SRV_WLAN_STRUCTS__

/* structure for WLAN profile */
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __WAPI_SUPPORT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
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
#else
typedef struct
{
    U8 ssid[SRV_WLAN_PROF_MAX_SSID_LEN+1];       /* SSID ASCII string (MAX: SRV_WLAN_PROF_MAX_SSID_LEN) */         
    srv_wlan_auth_mode_enum auth_mode;        /* profile auth.mode */        
    U8 username[SRV_WLAN_PROF_MAX_USER_LEN+1];   /* user name string (ASCII, MAX: SRV_WLAN_PROF_MAX_USER_LEN) */
    U8 password[SRV_WLAN_PROF_PSWD_MAX_LEN+1]; /* password string (ASCII, MAX: SRV_WLAN_PROF_PSWD_MAX_LEN) */
    #if 0
/* under construction !*/
    #endif
    U32 profile_id;
} srv_wlan_prof_struct;
#endif


/* structure for filling AP information */
typedef struct
{
    U8 ssid[SRV_WLAN_PROF_MAX_SSID_LEN+1];
    srv_wlan_auth_mode_enum auth_mode;
    U8 password[SRV_WLAN_PROF_PSWD_MAX_LEN+1];
}srv_wlan_ap_info_struct;


/* structure for WLAN SRV to send the connect result to APP */
typedef struct
{
    srv_wlan_result_enum   result;     /* SUCCESS: connected, FAILD: connect failed, 
                                         * ABORTED: preemptived by new connect req 
                                         * TERMINATED: terminated by new disconnect req
                                         * STATE_ERROR: can't perform connect req
                                         */
    srv_wlan_cause_enum     cause;      /* Error cause, uses only if result = FAILD */
    U8                      bssid[SRV_WLAN_WNDRV_MAC_ADDRESS_LEN];   /* MAC Address */
    U8                      ssid[SRV_WLAN_WNDRV_SSID_MAX_LEN];       /* SSID */
    MMI_BOOL                init_by_soc;                    /* connection activated by socket flag */
    U16                     ssid_len;                       /* SSID length in array */
    U32                     channel_number;                 /* channel info from chip */
    U32                     profile_id;                     /* connected profile id */
    U32                         auth_type;
    U32                         eap_peap_auth_type;
    U32                         eap_ttls_auth_type;
    srv_wlan_connection_type_enum   conn_type;
    kal_uint16                  encry_mode; /*defaultly, it is WPS_ENCR_TYPES, 
                                              and now we don't to parse encry_mode in M2 */
    kal_uint8                   passphase[32];
    kal_uint8                   passphase_len;
    MMI_BOOL                need_login;
    MMI_BOOL                cancel_by_discon;
    int                     rssi;
} srv_wlan_conn_res_struct;


/* structure to send sniffer on result to APP */
typedef struct
{   
    srv_wlan_sniffer_on_cb_type_enum    cb_type;
    srv_wlan_sniffer_res_enum           result;
    srv_wlan_prof_struct               profile; // Get by sniffer
}srv_wlan_sniffer_on_res_struct;


/* structure to store results of query list operation */
typedef struct
{
    U32 ids[SRV_DTCNT_STORE_IDS_QRY_MAX_SIZE];      /* account id list query result */
    U8  num_ids;                                    /* the number of queried id list */
} srv_wlan_prof_list_struct;


/* structure for APP to query the string type info attribute in profiles */
typedef struct
{      
    CHAR *dest;       /* destination buffer. */
    U16 dest_len;     /* application's dest buffer length. */
    U16 req_len;      /* if this attribute is provided by application (NOT NULL), 
                         WLAN SRV will hint application the required buffer length */
} srv_wlan_prof_str_info_qry_struct;


/* sturcture of Ap information returned by scan operation. */
typedef struct
{
    U8      bssid[ SRV_WLAN_WNDRV_MAC_ADDRESS_LEN ]; /* MAC address */
    U8      ssid [ SRV_WLAN_WNDRV_SSID_MAX_LEN ];  
    U16     ssid_len;  
    S32     rssi;                           /* receive signal, in dBm */
    U32     channel_number;    
    U8      max_rate; 
    U8      privacy;                        /* WEP encryption requirement */
    srv_wlan_network_type_enum  network_type;  /* profile network type */
    srv_wlan_auth_mode_enum     auth_mode;     /* profile auth.mode */    
    srv_wlan_encrypt_mode_enum  encrypt_mode;  /* profile encrypt mode */
} srv_wlan_scan_ap_info_struct;


/* sturcture to send the scan result to APP */
typedef struct
{
    srv_wlan_scan_result_enum                   result;      /* scan result enum */
    U8                                          ap_list_num; /* total num of searched ap list */
    srv_wlan_scan_ap_info_struct                ap_list[SRV_WLAN_MAX_AP_LIST_NUM]; /* bss info array */
    U32                                         scan_job_id; /* scan_job_id, 0xFFFFFF means scan result broadcasting */    
} srv_wlan_scan_result_struct;


/* sturcture for user to pass the specialized ssid for scaning. */
typedef struct
{
    U8 ssid_len;
    U8 ssid[SRV_WLAN_WNDRV_SSID_MAX_LEN];
}srv_wlan_ssid_struct;


/* sturcture of ip inforamtion. */
typedef struct
{
    U8 ip_addr[SRV_WLAN_PROF_MAX_IP_ADDR_LEN];    /* IP address (ASCII, MAX: SRV_WLAN_PROF_MAX_IP_ADDR_LEN) */
    U8 netmask[SRV_WLAN_PROF_MAX_IP_ADDR_LEN];    /* Netmask (ASCII, MAX: SRV_WLAN_PROF_MAX_IP_ADDR_LEN) */
    U8 gateway[SRV_WLAN_PROF_MAX_IP_ADDR_LEN];    /* Gateway (ASCII, MAX: SRV_WLAN_PROF_MAX_IP_ADDR_LEN) */
    U8 dns1[SRV_WLAN_PROF_MAX_IP_ADDR_LEN];       /* Primary DNS (ASCII, MAX: SRV_WLAN_PROF_MAX_IP_ADDR_LEN) */
    U8 dns2[SRV_WLAN_PROF_MAX_IP_ADDR_LEN];       /* Secondary DNS (ASCII, MAX: SRV_WLAN_PROF_MAX_IP_ADDR_LEN) */
}srv_wlan_ip_info_struct;


/* structure for filling the parameters of sniffer on operation. */
typedef struct
{
    U32 sniffer_filter_op;
    U8  channel_num;
    S32 min_rssi;
    S32 max_rssi;
    U16 min_pack_len;
    U16 max_pack_len;
}srv_wlan_sniffer_on_cfg_struct;


/* structure for notification */
typedef struct
{   
    srv_wlan_noti_type_enum type;
    void * data;
}srv_wlan_noti_struct;


/* structure for connected ap information */
typedef struct 
{
    U8 bssid[SRV_WLAN_WNDRV_MAC_ADDRESS_LEN + 1];
    U32 prof_id;
    S32 rssi_out;
}srv_wlan_conned_ap_info_struct;


/* structure for spec ssid list scan param */
typedef struct
{
    U8 ssid_list_num;
    srv_wlan_ssid_struct ssid_list[SRV_WLAN_MAX_SPEC_SSID_LIST_NUM];
}srv_wlan_spec_ssid_list_struct;

/* structure for configing AP mode param */
typedef struct 
{
    /* AP mode info */    
    U16 auth_mode; /* srv_wlan_auth_mode_enum */
    U8 ssid[SRV_WLAN_WNDRV_SSID_MAX_LEN + 1];
    U8 pwd[SRV_WLAN_PROF_PSWD_MAX_LEN];

    /* add */
}srv_wlan_cfg_ap_struct; /* same as srv_apmode_config_struct */

/****************************************************************************/
/* API                                                              */
/****************************************************************************/
#define __SRV_WLAN_CB_FUNCS__

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_conn_res_cb_func_ptr
 * DESCRIPTION
 *  Prototype of wLAN connect result callback function
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  conn_res    :   [IN]    connect results from DA SRV
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_conn_res_cb_func_ptr) (
            void *user_data,
            srv_wlan_conn_res_struct *conn_res);
            
            
/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_cb_func_ptr
 * DESCRIPTION
 *  Prototype of wLAN general callback function for no feedback arguments except application piggyback data
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  res         :   [IN]    request result
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_cb_func_ptr) (void *user_data, srv_wlan_req_res_enum res);
  
  
/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_scan_res_cb_func_ptr
 * DESCRIPTION
 *  Prototype of wLAN scan result callback function
 *  APPs need to copy the bss info byself.
 * PARAMETERS
 *  job_id      :   [IN]    APP's job ID from return value by calling WLAN scan operation
 *  user_data   :   [IN]    APP's piggyback user_data
 *  scan_res    :   [IN]    Scan results from WLAN srv
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_scan_res_cb_func_ptr) (
            U32 job_id,
            void *user_data,
            srv_wlan_scan_result_struct *scan_res);
                         

/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_sniffer_on_cb_func_ptr
 * DESCRIPTION
 *  Prototype of wlan sniffer on callback function. Tell user the result of sniffer on. If successfully, 
 *  function will be called again with AP info.
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  res         :   [IN]    Sniffer on results from WLAN srv
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_sniffer_on_cb_func_ptr) (
            void *user_data,
            srv_wlan_sniffer_on_res_struct *res);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_sniffer_off_cb_func_ptr
 * DESCRIPTION
 *  Prototype of wlan sniffer off callback function. Tell user the result of sniffer off. 
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  res         :   [IN]    Sniffer off results from WLAN srv
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_sniffer_off_cb_func_ptr) (
            void *user_data,
            srv_wlan_sniffer_res_enum res);


/*****************************************************************************
 * <GROUP  CallbackFunctions>
 *
 * FUNCTION
 *  srv_wlan_noti_func_ptr
 * DESCRIPTION
 *  Prototype of notification register function. When notification comes, corresponding register
 *  function will be called if it's registered before.
 * PARAMETERS
 *  user_data   :   [IN]    APP's piggyback user_data
 *  noti        :   [IN]    Noti type
 * RETURNS
 *  void
 *****************************************************************************/
typedef void (*srv_wlan_noti_func_ptr) (void *user_data, srv_wlan_noti_struct *noti);     


#define __SRV_WLAN_APIS__

/*****************************************************************************
 * FUNCTION
 *  srv_wlan_connect_by_spec_prof
 * DESCRIPTION
 *  The function is used to connect the applications specified AP for applications.
 *  1. DA WLAN servive can only support one connection at the same time due to chip constraint.
 *  2. If the new connect request is arrived, current connecting process will be aborted.
 *  3. If there is one connection already, the connection will be disconnected 
 *     then connect a new one.
 * PARAMETERS
 *  prof_id     :   [IN]    prof_id for wlan profile
 *  callback    :   [IN]    connect result callback notify function for APP
 *  user_data   :   [IN]    application associated piggyback data
 * RETURNS
 *  SRV_WLAN_RESULT_INVALID_INPUT  : profile_num <= 0 or profile pointer invalid
 *  SRV_WLAN_RESULT_STATE_ERROR    : the wlan status can't perform the scan process
 *  SRV_WLAN_RESULT_PROCESSING     : accept the connect quest, wait for event notify.
 * EXAMPLE
 *  <code>
 *  // STA status is ACTIVED before calling srv_wlan_connect_by_spec_prof(). And there's an available
 *  // profile id(For how to get an available profile id, please refer to srv_wlan_add_prof()).
 *  srv_wlan_connect_by_spec_prof(prof_id, conn_cb, NULL);
 *  void conn_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *       if (SRV_WLAN_REQ_RES_DONE == res)
 *       {
 *           // Connection succeeds.
 *       }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_connect_by_spec_prof(
                        U32 prof_id,
                        srv_wlan_conn_res_cb_func_ptr callback,
                        void *user_data);
                        

/*****************************************************************************
 * FUNCTION
 *  srv_wlan_connect
 * DESCRIPTION
 *  The function is used to connect the AP specified by the info in ap_info.
 *  1. DA WLAN servive can only support one connection at the same time due to chip constraint.
 *  2. If the new connect request is arrived, current connecting process will be aborted.
 *  3. If there is one connection already, the connection will be disconnected 
 *     then connect a new one.
 * PARAMETERS
 *  ap_info     :   [IN]    Ap information such as ssid, auth mode, password
 *  callback    :   [IN]    connect result callback notify function for APP
 *  user_data   :   [IN]    application associated piggyback data
 * RETURNS
 *  SRV_WLAN_RESULT_INVALID_INPUT  : profile_num <= 0 or profile pointer invalid
 *  SRV_WLAN_RESULT_STATE_ERROR    : the wlan status can't perform the scan process
 *  SRV_WLAN_RESULT_PROCESSING     : accept the connect quest, wait for event notify.
 * SEE ALSO
 *  srv_wlan_connect_by_spec_prof
 * EXAMPLE
 *  <code>
 *  // STA status is ACTIVED before calling srv_wlan_connect().
 *  srv_wlan_ap_info_struct ap_info = {0};
 *  strcpy(ap_info.ssid, "ssidexample");
 *  ap_info.auth_mode = SRV_WLAN_AUTH_MODE_WPA_ONLY_PSK;
 *  strcpy(ap_info.password, "ssidpwd");
 *  srv_wlan_connect(&ap_info, conn_cb, NULL);
 *  void conn_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *       if (SRV_WLAN_REQ_RES_DONE == res)
 *       {
 *           // Connection succeeds.
 *       }
 *  }  
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_connect(
    srv_wlan_ap_info_struct *ap_info, 
    srv_wlan_conn_res_cb_func_ptr callback,
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_disconnect
 * DESCRIPTION
 *  1. The function is used to disconnect current WLAN connection.
 *  2. After WLAN init process is done, SRV will callback APP with user_data.
 * PARAMETERS
 *  callback    :   [IN]    callback function to notify applications the disconnect operation is done
 *  user_data   :   [IN]    application piggyback data 
 * RETURNS
 *  SRV_WLAN_RESULT_STATE_ERROR    :   the wlan status can't perform the disconnect process
 *  SRV_WLAN_RESULT_SUCCESS        :   the WLAN status is active.
 *  SRV_WLAN_RESULT_PROCESSING     :   accept the disconnect quest, wait for event notify.
 * EXAMPLE
 *  <code>
 *  // STA status is CONNECTED before calling srv_wlan_disconnect().
 *  srv_wlan_disconnect(disconn_cb, NULL);
 *  void disconn_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *       if (SRV_WLAN_REQ_RES_DONE == res)
 *       {
 *           // Disconnection succeeds.
 *       }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_disconnect(
                        srv_wlan_cb_func_ptr callback,
                        void *user_data);


 /*****************************************************************************
 * FUNCTION 
 *  srv_wlan_init_profile
 * DESCRIPTION
 *  The function is used to init the wlan profile structure. In other words, fill in default
 *  values for the structure data members.
 * PARAMETERS
 *  profile :   [OUT]    specified profile to be set
 * RETURNS
 *  void
 * EXAMPLE
 *  <code>
 *  srv_wlan_prof_struct wlan_prof;
 *  srv_wlan_init_profile(&wlan_prof);
 *  </code>
 *****************************************************************************/
extern void srv_wlan_init_profile(srv_wlan_prof_struct * wlan_prof);
                        

/*****************************************************************************
 * FUNCTION
 *  srv_wlan_add_prof
 * DESCRIPTION
 *  The function is to add a new wlan profile by specified profile data.
 * PARAMETERS
 *  prof        :   [IN]        profile data buffer to be added
 *  prof_id     :   [OUT]       return prof_id for wlan profile
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS        : add profile successfully.
 *  SRV_WLAN_RESULT_ONE_STORE_EXISTS : the profile has already been added.
 *  SRV_WLAN_RESULT_FAILED         : add profile failed.
 *  SRV_WLAN_RESULT_INVALID_STORE  : store handle invalid.
 *  SRV_WLAN_RESULT_INVALID_INPUT  : the input parameter is invalid.
 *  SRV_WLAN_RESULT_STORE_FULL     : storage full
 * EXAMPLE
 *  <code>
 *  srv_wlan_prof_struct wlan_prof;
 *  U32 prof_id = 0;
 *  srv_wlan_result_enum ret;
 *  srv_wlan_init_profile(&wlan_prof);
 *  strcpy(wlan_prof.ssid, "ssidexample");
 *  // If auth mode is SRV_WLAN_AUTH_MODE_OPEN, password is no need.
 *  wlan_prof.auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
 *  strcpy(wlan_prof.password, "ssidpwd");
 *  ret = srv_wlan_add_prof(&wlan_prof, &prof_id);
 *  if (ret == SRV_WLAN_RESULT_SUCCESS)
 *  {
 *      // Add profile successfully.
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_add_prof(
                        const srv_wlan_prof_struct * wlan_prof, 
                        U32 * prof_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_update_prof
 * DESCRIPTION
 *  The function is to update WLAN profile content by specified profile id. Structure
 *  data members can be updated seperately, or updated all at one time.
 * PARAMETERS
 *  prof_id     :   [IN]    update wlan profile id
 *  wlan_prof   :   [IN]    profile info from application
 *  prof_fields :   [IN]    SRV_WLAN_PROF_FIELD_X, such as SRV_WLAN_PROF_FIELD_ALL
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS            : update profile successfully.
 *  SRV_WLAN_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_WLAN_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *  SRV_WLAN_RESULT_READ_ONLY          : this profile can't be deleted or update 
 * EXAMPLE
 *  <code> 
 *  // Fill in the new value for the data members you want to update.
 *  srv_wlan_prof_struct wlan_prof = {0};
 *  strcpy(wlan_prof.password, "newpwd");
 *  // There's an avaialbe profile id(For how to get an available profile id, please
 *  // refer to srv_wlan_add_prof()).
 *  srv_wlan_update_prof(prof_id, &wlan_prof, SRV_WLAN_PROF_FIELD_PW);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_update_prof(
                        U32 prof_id, 
                        const srv_wlan_prof_struct * wlan_prof,
                        U32 prof_fields);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_delete_prof
 * DESCRIPTION
 *  The function is to delete a WLAN profile by specified profile id.
 * PARAMETERS
 *  prof_id     :   [IN]    query wlan profile id
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS            : delete profile successfully.
 *  SRV_WLAN_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_WLAN_RESULT_INVALID_INPUT      : the input parameter is invalid.
 *  SRV_WLAN_RESULT_READ_ONLY          : this profile can't be deleted or update
 * EXAMPLE
 *  <code>
 *  // There's an avaialbe profile id(For how to get an available profile id, please
 *  // refer to srv_wlan_add_prof()).
 *  srv_wlan_delete_prof(prof_id);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_delete_prof(U32 prof_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_query_prof
 * DESCRIPTION
 *  The function is to query WLAN profile content by specified profile id.
 * PARAMETERS
 *  prof_id     :   [IN]    query wlan profile id
 *  prof        :   [OUT]    profile info from application
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS            : query profile successfully.
 *  SRV_WLAN_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_WLAN_RESULT_INVALID_INPUT      : the input parameter is invalid.
 * EXAMPLE
 *  <code>
 *  // There's an avaialbe profile id(For how to get an available profile id, please
 *  // refer to srv_wlan_add_prof()).
 *  srv_wlan_prof_struct wlan_prof = {0};
 *  SRV_WLAN_RESULT_SUCCESS ret;
 *  ret = srv_wlan_query_prof(prof_id, &wlan_prof);
 *  if (SRV_WLAN_RESULT_SUCCESS == ret)
 *  {
 *      // Query profile successfully. wlan_prof returns with detail of the profile.
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_query_prof(
                        U32 prof_id, 
                        srv_wlan_prof_struct * prof);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_query_prof_list
 * DESCRIPTION
 *  The function is to query the number and ids of the WLAN profiles added.
 * PARAMETERS
 *  prof_list   :   [OUT]    query wlan profile list
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS            : query profile successfully.
 *  SRV_WLAN_RESULT_INVALID_STORE      : store handle invalid.
 *  SRV_WLAN_RESULT_INVALID_INPUT      : the input parameter is invalid.
 * EXAMPLE
 *  <code>
 *  srv_wlan_prof_list_struct prof_list;
 *  srv_wlan_query_prof_list(&prof_list);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_query_prof_list(srv_wlan_prof_list_struct * prof_list);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_connected_ap_bssid
 * DESCRIPTION
 *  The function is used to get connected WiFi access point's bssid.
 *  1. dest buffer length must be >= SRV_WLAN_WNDRV_MAC_ADDRESS_LEN, i.e. dest_len must 
 *     be >= SRV_WLAN_WNDRV_MAC_ADDRESS_LEN, otherwise WLAN SRV will return MMI_FALSE 
 *     and reqired length (SRV_WLAN_WNDRV_MAC_ADDRESS_LEN) will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, WLAN SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  bssid [OUT]: array used to store bssid. The length is SRV_WLAN_WNDRV_MAC_ADDRESS_LEN(6).
 * RETURNS
 * MMI_TRUE: get bssid succ
 * MMI_FALSE: get bssid fail
 * EXAMPLE
 *  <code>
 *  CHAR dest[SRV_WLAN_WNDRV_MAC_ADDRESS_LEN] = {0};
 *  srv_wlan_prof_str_info_qry_struct bssid;
 *  bssid.dest = dest;
 *  bssid.dest_len = SRV_WLAN_WNDRV_MAC_ADDRESS_LEN;
 *  srv_wlan_get_connected_ap_bssid(&bssid);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_connected_ap_bssid(srv_wlan_prof_str_info_qry_struct * bssid);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_connected_ap_prof_id
 * DESCRIPTION
 *  The function is used to get connected WiFi access point's profile id.
 * PARAMETERS
 *  prof_id [OUT]: parameter used to store WIFI profile id.
 * RETURNS
 * MMI_TRUE: get profile id succ
 * MMI_FALSE: get profile id fail
 * EXAMPLE
 *  <code>
 *  U32 prof_id;
 *  srv_wlan_get_connected_ap_prof_id(&prof_id);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_connected_ap_prof_id(U32 * prof_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_connected_ap_rssi
 * DESCRIPTION
 *  The function is used to get rssi of the connected WiFi access point.
 * PARAMETERS
 *  rssi_out [OUT]: parameter used to store rssi.
 * RETURNS
 * MMI_TRUE: get rssi succ
 * MMI_FALSE: get rssi fail
 * EXAMPLE
 *  <code>
 *  S32 rssi;
 *  srv_wlan_get_connected_ap_rssi(&rssi);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_connected_ap_rssi(S32 *rssi_out);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_connected_ap_info
 * DESCRIPTION
 *  The function is used to get information of the connected AP, such as bssid, rssi, 
 *  and profile id. 
 *  
 *  Input parameter, info_type, indicates what kind of information is wanted. User should provide 
 *  enough memory to store the information as following:
 *
 *  info_type                   info
 *  SRV_WLAN_AP_INFO_BSSID      U8 array with length at least SRV_WLAN_WNDRV_MAC_ADDRESS_LEN + 1
 *  SRV_WLAN_AP_INFO_PROF_ID    U32* points to a U32 variable
 *  SRV_WLAN_AP_INFO_RSSI       S32* points to an S32 variable
 *  SRV_WLAN_AP_INFO_ALL        srv_wlan_conned_ap_info_struct* to an srv_wlan_conned_ap_info_struct variable
 *
 * PARAMETERS
 *  info      [OUT]: parameter used to store ap info. Please refer to the description.
 *  info_type [IN]: srv_wlan_ap_info_type_enum
 * RETURNS
 * MMI_TRUE: get ap info succ
 * MMI_FALSE: get ap info fail
 * EXAMPLE
 *  <code>
 *  // To get bssid
 *  U8 bssid[SRV_WLAN_WNDRV_MAC_ADDRESS_LEN + 1] = {0};
 *  srv_wlan_get_connected_ap_info((void*)bssid, SRV_WLAN_AP_INFO_BSSID);
 *  // To get prof id
 *  U32 prof_id;
 *  srv_wlan_get_connected_ap_info((void*)&prof, SRV_WLAN_AP_INFO_PROF_ID);
 *  // To get rssi
 *  S32 rssi;
 *  srv_wlan_get_connected_ap_info((void*)&rssi, SRV_WLAN_AP_INFO_RSSI);
 *  // To get all inforamtion
 *  srv_wlan_conned_ap_info_struct ap_info = {0};
 *  srv_wlan_get_connected_ap_info((void*)&ap_info, SRV_WLAN_AP_INFO_ALL);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_connected_ap_info(void *info, S32 info_type);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_mac_address
 * DESCRIPTION
 *  The function is used to get MAC address.
 *  1. dest buffer length must be >= SRV_WLAN_WNDRV_MAC_ADDRESS_LEN, i.e. dest_len must 
 *     be >= SRV_WLAN_WNDRV_MAC_ADDRESS_LEN, otherwise WLAN SRV will return MMI_FALSE 
 *     and reqired length (SRV_WLAN_WNDRV_MAC_ADDRESS_LEN) will be set back to application.
 *  2. Also, if dest = NULL, and req_len exist, WLAN SRV will return MMI_FALSE
 *     with required length in req_len for application.
 * PARAMETERS
 *  mac_address_out     :   [OUT]    MAC address output location
 * RETURNS
 *  MMI_TRUE    :   Get MAC address successfully
 *  MMI_FALSE   :   Get MAC address failed
 * EXAMPLE
 *  <code>
 *  CHAR dest[SRV_WLAN_WNDRV_MAC_ADDRESS_LEN] = {0};
 *  srv_wlan_prof_str_info_qry_struct mac_addr;
 *  mac_addr.dest = dest;
 *  mac_addr.dest_len = SRV_WLAN_WNDRV_MAC_ADDRESS_LEN;
 *  srv_wlan_get_mac_address(&mac_addr);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_mac_address(srv_wlan_prof_str_info_qry_struct * mac_address_out);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan
 * DESCRIPTION
 *  The function is used to scan the AP list for applications.
 * PARAMETERS
 *  callback    :   [IN]    scan result callback notify function for APP
 *  user_data   :   [IN]    application piggyback data
 * RETURNS
 *  Job ID > 0 : New scan job created successfully.
 *  Job ID = 0 : Can't create a new scan job.
 * EXAMPLE
 *  <code>
 *  U32 job_id;
 *  job_id = srv_wlan_scan(scan_cb, NULL);
 *  void scan_cb(
 *           U32 job_id,
 *           void *user_data,
 *           srv_wlan_scan_result_struct *scan_res)
 *  {
 *      if (SRV_WLAN_SCAN_RESULT_SUCCESS == scan_res->result)
 *      {
 *          // Scan successfully. Information of APs scaned is in scan_res.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern U32 srv_wlan_scan(srv_wlan_scan_res_cb_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_scan_abort
 * DESCRIPTION
 *  The function is used to abort the scanning AP list process for applications.
 * PARAMETERS
 *  job_id  :   [IN]    created job ID from calling srv_wlan_scan
 * RETURNS
 *  void
 * EXAMPLE
 *  <code>
 *  // scan job_id is returned by srv_wlan_scan().
 *  srv_wlan_scan_abort(job_id);
 *  </code>
 *****************************************************************************/
extern void srv_wlan_scan_abort(U32 job_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_scan_spec_ssid_list
 * DESCRIPTION
 *  The function is used to set specialized ssid list for scaning. User should 
 *  not set the specialized ssid list again before the last set process finishes.
 *
 *  If ssid_list_num = 0, delete spec ssid list which is set before to use the default scan.
 *  If ssid_list_num !=0, replace the new spec ssid list with the old.
 *
 *  The max ssid_list_num is defined in SRV_WLAN_MAX_SPEC_SSID_LIST_NUM
 * PARAMETERS
 *  ssid_list_num :   [IN]    the number of ssid list
 *  ssid_list     :   [IN]    ssid list
 *  callback      :   [IN]    callback function to notify applications the operation is done
 *  user_data     :   [IN]    application piggyback data 
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS        : Successfuly.
 *  SRV_WLAN_RESULT_FAILED         : Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT  : Invalid input parameter(s).
 *  SRV_WLAN_RESULT_PROCESSING     : Waiting for result.
 * EXAMPLE
 *  <code>
 *  srv_wlan_ssid_struct ssid_list[] = {{5, "ssid1"},{5, "ssid2"},{5, "ssid3"},{5, "ssid4"}};
 *  U8 ssid_list_num = 4;
 *  srv_wlan_set_scan_spec_ssid_list(ssid_list_num, ssid_list, set_scan_spec_ssid_list_cb, NULL);
 *  void set_scan_spec_ssid_list_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Set special ssid list successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_set_scan_spec_ssid_list(
        U8 ssid_list_num, 
        const srv_wlan_ssid_struct * ssid_list,
        srv_wlan_cb_func_ptr callback,
        void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_scan_spec_ssid_list
 * DESCRIPTION
 *  The function is used to get customized specialized ssid list for scaning. 
 *  If customer doesn't set spec ssid list before, deault value will be returned.
 *  Customer should provide enough memory for ssid_list.
 * PARAMETERS
 *  ssid_list_num [OUT]: the number of specialized ssid list.
 *  ssid_list     [OUT]: ssid list
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS        : Successfuly.
 *  SRV_WLAN_RESULT_FAILED         : Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT  : Invalid input parameter(s).
 * EXAMPLE
 *  <code>
 *  U8 ssid_list_num;
 *  srv_wlan_ssid_struct ssid_list;
 *  srv_wlan_get_scan_spec_ssid_list(&ssid_list_num, &ssid_list);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_scan_spec_ssid_list(
    U8 * ssid_list_num, 
    srv_wlan_ssid_struct * ssid_list);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_roaming_para
 * DESCRIPTION
 *  The function is used to set roaming parameter.
 * PARAMETERS
 *  enable_roaming     :   [IN]    WLAN roaming parameter
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS     : Successfuly.
 *  SRV_WLAN_RESULT_FAILED      :  Failed.
 *  SRV_WLAN_RESULT_PROCESSING  : Waiting for result.
 * EXAMPLE
 *  <code>
 *  MMI_BOOL enable_roaming = MMI_TRUE;
 *  srv_wlan_set_roaming_para(enable_roaming, set_roaming_cb, NULL);
 *  void set_roaming_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Set roaming successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_set_roaming_para(
    MMI_BOOL enable_roaming, 
    srv_wlan_cb_func_ptr callback, 
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_roaming_para
 * DESCRIPTION
 *  The function is used to get roaming parameter.
 * PARAMETERS
 *  is_roaming     :   [OUT]    WLAN roaming parameter
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS: Successfuly.
 *  SRV_WLAN_RESULT_FAILED:  Failed.
 * EXAMPLE
 *  <code>
 *  MMI_BOOL is_roaming = MMI_TRUE;
 *  srv_wlan_get_roaming_para(&is_roaming);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_roaming_para(MMI_BOOL * is_roaming);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_scan_dwell_time
 * DESCRIPTION
 *  The function is used to set dwell time of each channel when scaning.
 * PARAMETERS
 *  roaming_para     :   [IN]    WLAN dwell time
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS: Successfuly.
 *  SRV_WLAN_RESULT_FAILED:  Failed.
 *  SRV_DTCNT_RESULT_PROCESSING: Waiting for result.
 * EXAMPLE
 *  <code>
 *  U16 dwell_time = 70;
 *  srv_wlan_set_scan_dwell_time(dwell_time, set_dwell_time_cb, NULL);
 *  void set_dwell_time_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Set dwell time successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_set_scan_dwell_time(
    U16 dwell_time,
    srv_wlan_cb_func_ptr callback, 
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_scan_dwell_time
 * DESCRIPTION
 *  The function is used to get dwell time of each channel when scaning.
 * PARAMETERS
 *  dwell_time     :   [OUT]    WLAN dwell time
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS: Successfuly.
 *  SRV_WLAN_RESULT_FAILED:  Failed.
 * EXAMPLE
 *  <code>
 *  U16 dwell_time;
 *  srv_wlan_get_scan_dwell_time(&dwell_time);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_scan_dwell_time(U16 * dwell_time);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_scan_param
 * DESCRIPTION
 *  The function is used to set scan parameters, such as dwell time or specific ssid list.
 *  For scan parameters will be initialized to the default value evertytime wlan is turned on
 *  from inactive status, setting scan parameters is not useful at INACTIVE status, so it's not
 *  allowed. 
 *  If scan parameter(s) is(are) not set, default value(s) will be used.
 *  Default values: dwell time: 60  spec_ssid_list: NULL
 * 
 *  Input parameter param_type indicates the kind of scan param that is wanted to be set. User 
 *  should provide proper param to each kind of scan param as following:
 *
 *  param_type                              param
 *  SRV_WLAN_SCAN_PARAM_DWELL_TIME          U16* points to a U16 variable
 *  SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST      srv_wlan_spec_ssid_list_struct* points to an
 *                                          srv_wlan_spec_ssid_list_struct variable
 * PARAMETERS
 *  param           [IN] scan parameters
 *  param_type      [IN] srv_wlan_scan_param_type_enum
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS:        Successfuly.
 *  SRV_WLAN_RESULT_FAILED:         Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT:  Invalid input parameter(s).
 *  SRV_WLAN_RESULT_STATE_ERROR:    Set scan parameter(s) in INACTIVE status
 * EXAMPLE
 *  <code>
 *  // Set dwell time
 *  U16 dwell_time = 70;
 *  srv_wlan_set_scan_param((void*)&dwell_time, SRV_WLAN_SCAN_PARAM_DWELL_TIME, set_dwell_time_cb, NULL);
 *  
 *  void set_dwell_time_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Set dwell time successfully.
 *      }
 *  }
 *  // Set specialized ssid list
 *  srv_wlan_spec_ssid_list_struct ssid_list = {0};
 *  ssid_list.ssid_list[0] = {5, "ssid1"};
 *  ssid_list.ssid_list[1] = {5, "ssid2"};
 *  ssid_list.ssid_list[2] = {5, "ssid3"};
 *  ssid_list.ssid_list[3] = {5, "ssid4"};
 *  ssid_list.ssid_list_num = 4;
 *  srv_wlan_set_scan_param((void*)&ssid_list, SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST, set_spec_ssid_list_cb, NULL);
 *  void set_spec_ssid_list_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Set specialized ssid list successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_set_scan_param(
    void *param, 
    S32 param_type, 
    srv_wlan_cb_func_ptr callback, 
    void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_scan_param
 * DESCRIPTION
 *  The function is used to get scan parameters, such as dwell time or specific ssid list.
 * 
 *  Input parameter param_type indicates the kind of scan param that is wanted. User 
 *  should provide proper param to each kind of scan param as following:
 *
 *  param_type                              param
 *  SRV_WLAN_SCAN_PARAM_DWELL_TIME          U16* points to a U16 variable
 *  SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST      srv_wlan_spec_ssid_list_struct* points to an
 *                                          srv_wlan_spec_ssid_list_struct variable
 * PARAMETERS
 *  param           [OUT] scan parameters
 *  param_type      [IN]  srv_wlan_scan_param_type_enum
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS:        Successfuly.
 *  SRV_WLAN_RESULT_FAILED:         Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT:  Invalid input parameter(s).
 * EXAMPLE
 *  <code>
 *  // Get dwell time
 *  U16 dwell_time;
 *  srv_wlan_get_scan_param((void*)&dwell_time, SRV_WLAN_SCAN_PARAM_DWELL_TIME);
 *  // Get specialized ssid list
 *  srv_wlan_spec_ssid_list_struct ssid_list;
 *  srv_wlan_get_scan_param((void*)&ssid_list, SRV_WLAN_SCAN_PARAM_SPEC_SSID_LIST);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_scan_param(void *param, S32 param_type);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_ip_info
 * DESCRIPTION
 *  The function is used to get ip addr, netmask, gateway ip, dns, when they are available.
 *  These ip info will be available only when wlan srv is in CONNECTED status. And there're 
 *  two situation due to the way of how to get ip.
 *  If using static ip when connecting, the ip will be availabe once connection succeeds.
 *  If using DHCP when connecting, ip will be availabe only when ABM notify the ip by MSG.
 *  That'll take a little time after connection succeeds. 
 * PARAMETERS
 *  ip_info     :   [OUT]    Ip info
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS:      Successfuly.
 *  SRV_WLAN_RESULT_STATE_ERROR:  Wrong time to get ip for ip is not available. 
 *  SRV_WLAN_RESULT_FAILED:       Failed.
 * EXAMPLE
 *  <code>
 *  srv_wlan_ip_info_struct ip_info = {0};
 *  srv_wlan_get_ip_info(&ip_info);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_ip_info(srv_wlan_ip_info_struct* ip_info);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_switch
 * DESCRIPTION
 *  The function is used to switch the mode. 
 *  SRV_WLAN_SET_MODE_OFF turns off both AP mode and STA mode.
 *  SRV_WLAN_SET_MODE_AP turns only AP mode on.
 *  SRV_WLAN_SET_MODE_STA turns only STA mode on.
 *  SRV_WLAN_SET_MODE_AP_STA turns both AP mode and STA mode on.
 * PARAMETERS
 *  mode         :   [IN]    The mode wanted to switch on.
 * RETURNS
 *  void
 * EXAMPLE
 *  <code>
 *  srv_wlan_switch(SRV_WLAN_SET_MODE_AP, switch_mode_cb, NULL);
 *  void switch_mode_cb(void *user_data, srv_wlan_req_res_enum res)
 *  {
 *      if (SRV_WLAN_REQ_RES_DONE == res)
 *      {
 *          // Switch mode successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/
extern void srv_wlan_switch(srv_wlan_set_mode_enum mode, srv_wlan_cb_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_status
 * DESCRIPTION
 *  The function is used to query current status of WLAN services.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_wlan_mode_status_enum
 * EXAMPLE
 *  <code>
 *  srv_wlan_mode_status_enum mode;
 *  mode = srv_wlan_status();
 *  </code>
 *****************************************************************************/
extern srv_wlan_mode_status_enum srv_wlan_status(void);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_sta_status
 * DESCRIPTION
 *  The function is used to query current status in WLAN STA mode.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_wlan_sta_status_enum
 *  SRV_WLAN_STA_STATUS_BUSY means that WIFI status is changing, 
 *  User need to wait changing finish and poll the result in interval timer
 * EXAMPLE
 *  <code>
 *  srv_wlan_sta_status_enum sta_status;
 *  sta_status = srv_wlan_sta_status(); 
 *  </code>
 *****************************************************************************/ 
extern srv_wlan_sta_status_enum srv_wlan_sta_status(void);


#ifdef __WIFI_SNIFFER_SUPPORT__
/*****************************************************************************
 * FUNCTION
 *  srv_wlan_sniffer_on
 * DESCRIPTION
 *  The function is used to open sniffer in WLAN STA mode.
 * PARAMETERS
 *  sniffer_on_config   :   [IN]    the configuration parameter of sniffer status
 *  callback            :   [IN]    callback function to notify applications the operation is done
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS        : Successfuly.
 *  SRV_WLAN_RESULT_FAILED         : Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT  : Invalid input parameter(s).
 *  SRV_WLAN_RESULT_PROCESSING     : Waiting for result.
 * EXAMPLE
 *  <code>
 *  srv_wlan_sniffer_on(NULL, sniffer_on_cb, NULL);
 *  void sniffer_on_cb(void *user_data, srv_wlan_sniffer_on_res_struct *res)
 *  {
 *      switch (res->cb_type)
 *      {
 *          case SRV_WLAN_SNIFFER_ON_RES:
 *          {
 *              if (res->result == SRV_WLAN_SNIFFER_SUCCESS)
 *              {
 *                  // Open sniffer successfully.
 *              }
 *              break;
 *          }
 *          case SRV_WLAN_SNIFFER_ON_AP_INFO:
 *          {
 *              if (res->result == SRV_WLAN_SNIFFER_SUCCESS)
 *              {
 *                  // Get AP information successfully. And Ap information is stored
 *                  // in res->profile.
 *              }
 *              break;
 *          }
 *          default:
 *              break;
 *      }
 *  }
 *  </code>
 *****************************************************************************/ 
extern srv_wlan_result_enum srv_wlan_sniffer_on(
                                srv_wlan_sniffer_on_cfg_struct *sniffer_on_config,
                                srv_wlan_sniffer_on_cb_func_ptr callback,
                                void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_sniffer_off
 * DESCRIPTION
 *  The function is used to close sniffer in WLAN STA mode.
 * PARAMETERS
 *  callback            :   [IN]    callback function to notify applications the operation is done
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS        : Successfuly.
 *  SRV_WLAN_RESULT_FAILED         : Failed.
 *  SRV_WLAN_RESULT_INVALID_INPUT  : Invalid input parameter(s).
 *  SRV_WLAN_RESULT_PROCESSING     : Waiting for result.
 * EXAMPLE
 *  <code>
 *  srv_wlan_sniffer_off(sniffer_off_cb, NULL);
 *  void sniffer_off_cb(void *user_data, srv_wlan_sniffer_res_enum res)
 *  {
 *      if (SRV_WLAN_SNIFFER_SUCCESS == res)
 *      {
 *          // Exist sniffer successfully.
 *      }
 *  }
 *  </code>
 *****************************************************************************/ 
extern srv_wlan_result_enum srv_wlan_sniffer_off(
                        srv_wlan_sniffer_off_cb_func_ptr callback,
                        void *user_data);
#endif


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_reconn_prof_id
 * DESCRIPTION
 *  The function is used to set reconnect profile id. It will be stored and may be used in reconfig flow. 
 *  Every time connection succeeds, the reconn prof id will be set to be the conn prof id automatically.
 * PARAMETERS
 *  prof_id            :   [IN]    WLAN profile id which has been stored in WLAN service
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  // There's an avaialbe profile id(For how to get an available profile id, please
 *  // refer to srv_wlan_add_prof()). 
 *  srv_wlan_set_reconn_prof_id(prof_id);
 *  </code>
 *****************************************************************************/ 
extern MMI_BOOL srv_wlan_set_reconn_prof_id(U32 prof_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_reconn_prof_id
 * DESCRIPTION
 *  The function is used to get reconnect profile id. It will be stored and may be used in bootup flow. 
 *  Everytime connection succeeds, the reconn prof id will be set to be the conn prof id automatically.
 * PARAMETERS
 *  prof_id            :   [OUT]    WLAN profile id which has been stored in WLAN service
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  U32 prof_id;
 *  srv_wlan_get_reconn_prof_id(&prof_id);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_get_reconn_prof_id(U32 *prof_id);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_reg_ip_available_noti
 * DESCRIPTION
 *  The function is used to register ip available notification if client used DHCP setting(default). 
 *  When client connect success, do not mean that client has gotten the IP address.
 *  Register callback to listen IP available notication when connect success. 
 * PARAMETERS
 *  callback            :   [IN]    callback function to notify applications the notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  srv_wlan_reg_ip_available_noti(ip_available_hdl, NULL);
 *  // When IP is available, ip_available_hdl will be called.
 *  void ip_available_hdl(void *user_data, srv_wlan_noti_struct *noti)
 *   {
 *      if (noti->type == SRV_WLAN_NOTI_IP_AVAILABLE)
 *      {
 *          //...
 *      }
 *   } 
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_reg_ip_available_noti(srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_dereg_ip_available_noti
 * DESCRIPTION
 *  The function is used to deregister ip available notification if client used DHCP setting(default). 
 *  Deregister the callback when client disconnect success.
 * PARAMETERS
 *  callback            :   [IN]    callback function to notify applications the notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  srv_wlan_dereg_ip_available_noti(ip_available_hdl, NULL);
 *  // Deregister with the same callback and user_data.
 *  srv_wlan_dereg_ip_available_noti(ip_available_hdl, NULL);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_dereg_ip_available_noti(srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_reg_passive_disconn_noti
 * DESCRIPTION
 *  The function is used to register WIFI passive disconnect notification. 
 *  Register callback to listen passive disconnect notication when connect success. 
 * PARAMETERS
 *  callback            :   [IN]    callback function to notify applications the notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  srv_wlan_reg_passive_disconn_noti(passive_disconn_hdl, NULL);
 *  // When connection is disconnected passively, passive_disconn_hdl will be called.
 *  void passive_disconn_hdl(void *user_data, srv_wlan_noti_struct *noti)
 *  {
 *    if (noti->type == SRV_WLAN_NOTI_PASSIVE_DISCONN)
 *    {
 *       //...
 *    }
 *  } 
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_reg_passive_disconn_noti(srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_dereg_passive_disconn_noti
 * DESCRIPTION
 *  The function is used to deregister WIFI passive disconnect notification. 
 *  Deregister callback when disconnect success. 
 * PARAMETERS
 *  callback            :   [IN]    callback function to notify applications the notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_BOOL
 * EXAMPLE
 *  <code>
 *  srv_wlan_reg_passive_disconn_noti(passive_disconn_hdl, NULL);
 *  // Deregister with the same callback and user_data.
 *  srv_wlan_dereg_passive_disconn_noti(passive_disconn_hdl, NULL);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_dereg_passive_disconn_noti(srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_reg_noti
 * DESCRIPTION
 *  The function is used to register the handler of notifications, such as ip available notification, or 
 *  WIFI passive disconnect notification. When relative things happens, notification will be actived and
 *  callback function will be invoked if it's registered before. 
 * 
 *  srv_wlan_reg_noti() should be paired with srv_wlan_dereg_noti().
 * PARAMETERS
 *  noti_type           :   [IN]    Notification type. Please refer to srv_wlan_noti_type_enum
 *  callback            :   [IN]    callback function to notify that notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_TRUE    Successfully
 *  MMI_FALSE    Failed
 * EXAMPLE
 *  <code>
 *  srv_wlan_reg_noti(SRV_WLAN_NOTI_IP_AVAILABLE, ip_available_hdl, NULL);
 *  // When IP is available, ip_available_hdl will be called.
 *  void ip_available_hdl(void *user_data, srv_wlan_noti_struct *noti)
 *  {
 *    if (noti->type == SRV_WLAN_NOTI_IP_AVAILABLE)
 *    {
 *      //...
 *    }
 *  }
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_reg_noti(S32 noti_type, srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_dereg_noti
 * DESCRIPTION
 *  The function is used to deregister the handler of notifications which is registered before.
 *  the type of notification, callback and user_data should be the same as the one that registed 
 *  by using srv_wlan_reg_noti().
 *
 *  srv_wlan_reg_noti() should be paired with srv_wlan_dereg_noti()
 * PARAMETERS
 *  noti_type           :   [IN]    Notification type. Please refer to srv_wlan_noti_type_enum
 *  callback            :   [IN]    callback function to notify that notification is coming
 *  user_data           :   [IN]    application piggyback data 
 * RETURNS
 *  MMI_TRUE    Successfully
 *  MMI_FALSE    Failed
 * EXAMPLE
 *  <code>
 *  srv_wlan_reg_noti(SRV_WLAN_NOTI_IP_AVAILABLE, ip_available_hdl, NULL);
 *  // Deregister with the same callback and user_data. Then when IP is avaliable, ip_available_hdl  
 *  // will not be called.
 *  srv_wlan_dereg_noti(SRV_WLAN_NOTI_IP_AVAILABLE, ip_available_hdl, NULL);
 *  </code>
 *****************************************************************************/
extern MMI_BOOL srv_wlan_dereg_noti(S32 noti_type, srv_wlan_noti_func_ptr callback, void *user_data);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_set_para
 * DESCRIPTION
 *  Set parameters under different modes. User should prepare variables with proper types for 
 *  "para" and "flag" input parameters.
 *
 *  Currently, only MODE_AP and MODE_AP_STA are supported to set AP's SSID, Auth mode, and 
 *  Password. For Auth mode, only OPEN and WPA2_ONLY_PSK are supported. To make the parameter(s)
 *  work, do set parameter(s) before AP is turned on.
 *
 *  Default values will be used if parameters are not set or setting operation failed.
 *  Default SSID: MTK_XXXXXX(The value of XXXXXX depends on the last three bytes of mac addr)
 *  Default AUTH MODE:  WPA2_ONLY_PSK
 *  Default Password:   12345678
 *
 * PARAMETERS
 *  para :  [IN] srv_wlan_cfg_ap_struct(in AP mode)
 *  flag :  [IN] Indicate which parameter to config. 
 *               srv_wlan_cfg_ap_para_enum(in AP mode)
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS: set parameter success
 *  SRV_WLAN_RESULT_FAILED: set parameter fail
 *  SRV_WLAN_RESULT_STATE_ERROR: set at inappropriate state, such as set AP para when AP is on.
 *  SRV_WLAN_RESULT_INVALID_INPUT: invalid input parameters.
 * EXAMPLE
 *  <code>
 *  extern void switch_mode_cb(void *user_data, srv_wlan_req_res_enum res);
 *  // Set AP parameter before turning on AP mode.
 *  srv_wlan_cfg_ap_struct ap_param = {0};
 *  ap_param.auth_mode = SRV_WLAN_AUTH_MODE_WPA2_ONLY_PSK;
 *  strcpy(ap_param.ssid, "SSIDEXAMPLE");
 *  strcpy(ap_param.pwd, "PWDEXAMPLE")
 *  srv_wlan_set_para(SRV_WLAN_SET_MODE_AP, (void*)&ap_param, SRV_WLAN_CFG_AP_PARA_ALL);
 *  // Turn on AP mode
 *  srv_wlan_switch(SRV_WLAN_SET_MODE_AP, switch_mode_cb, NULL);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_set_para(
                    srv_wlan_set_mode_enum mode,
                    void *para,
                    S32 flag);


/*****************************************************************************
 * FUNCTION
 *  srv_wlan_get_para
 * DESCRIPTION
 *  Get parameter under different modes. Currently, only MODE_AP or MODE_AP_STA are 
 *  supported to get AP's SSID, Auth mode, and Password.
 
 *  User should prepare varible with proper type for "para" input parameter.
 * PARAMETERS
 *  para :  [OUT] return parameters to App.
 *                srv_wlan_cfg_ap_struct(under MODE_AP or MODE_AP_STA)
 * RETURNS
 *  SRV_WLAN_RESULT_SUCCESS: get parameter success
 *  SRV_WLAN_RESULT_FAILED: get parameter fail 
 *  SRV_WLAN_RESULT_INVALID_INPUT: invalid input parameters.
 * EXAMPLE
 *  <code> 
 *  srv_wlan_cfg_ap_struct ap_param = {0}; 
 *  srv_wlan_get_para(SRV_WLAN_SET_MODE_AP, (void*)&ap_param);
 *  </code>
 *****************************************************************************/
extern srv_wlan_result_enum srv_wlan_get_para(
                    srv_wlan_set_mode_enum mode,
                    void *para);
#endif /* __WIFI_SCAN_ONLY__ */
// #endif /* __IOT__ && __MMI_WLAN_FEATURES__ && __TCPIP__ */
#endif /* __WLAN_SRV_GPROT_H__ */
    
