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
 * ps_public_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the ABM network internal APIs 
 *   and these APIs can only be used by MMI CBM and DA
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
 *
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _PS_PUBLIC_ENUM_H_
#define _PS_PUBLIC_ENUM_H_

#include "custom_nvram_sec.h"

#define MAX_APN_LEN             100
#define MAX_PDP_ADDR_LEN        16
#define TCM_MAX_PEER_ACL_ENTRIES	 	10

#define MAX_GPRS_USER_NAME_LEN 32
#define MAX_GPRS_PASSWORD_LEN  32
#define MAX_GPRS_APN_LEN       100
#define MAX_GPRS_IP_ADDR       4 /* IP address length */

#if (MAX_EXT_PDP_CONTEXT >= 1)
    #define MAX_GPRS_DIALUP_NUM    MAX_EXT_PDP_CONTEXT /* MAX_GPRS_DIALUP_NUM is for L4C, ABM, RATDM use */
#else
    #define MAX_GPRS_DIALUP_NUM    1
#endif /* MAX_EXT_PDP_CONTEXT >= 1 */

#define INVALID_PDP_CONTEXT_ID (0x0)

/* Poying: MSBB. */
// #define MAX_NUM_CONFIG_OPTION_PACKETS   5
#if defined(__REL8__) || defined(__IPV6__) || defined(__IPV4V6__)
#define MAX_NUM_CONFIG_OPTION_PACKETS   6
#else  /* #if defined(__REL8__) || defined(__IPV6__) || defined(__IPV4V6__) */
#define MAX_NUM_CONFIG_OPTION_PACKETS   5
#endif /* #if defined(__REL8__) || defined(__IPV6__) || defined(__IPV4V6__) */


/* Poying: MSBB. */
/* Support PAP or CHAP ID and PW length up to 128 Bytes */
#define MAX_CONFIG_OPTION_CONTENT_LEN   (MAX_GPRS_USER_NAME_LEN+MAX_GPRS_PASSWORD_LEN+6)
#define LIMIT_CONFIG_OPTION_CONTENT_LEN (128)
/* Restrict the length of user_name, password and APN */
#if (MAX_CONFIG_OPTION_CONTENT_LEN > LIMIT_CONFIG_OPTION_CONTENT_LEN)
   #error GPRS_USER_NAME_LEN and GPRS_PASSWORD_LEN exceed the maximum
#endif

/* Check if APN length is valid. */
#if (MAX_GPRS_APN_LEN > 100)
   #error MAX_GPRS_APN_LEN exceed the maximum
#endif


#define MAX_SIM_PASSWD_LEN      9

#define MAX_DIGITS_USSD          183
#define MAX_CC_ADDR_LEN          41
#define MAX_CC_ADDR_BCD_LEN      21
#define L4C_MAX_CALL_LIST_LEN    7
#define MAX_CC_SUB_ADDR_LEN      41
#define MAX_SIM_ADDR_BCD_LEN      21

/* SMS PART START */
#define SMSAL_MAX_CMD_LEN           (156)       /* max command data length */
#define SMSAL_MAX_MSG_LEN           (160) 

#if defined(__REL4__)
   #define SMSAL_MAX_MAILBOX_NUM  SMSAL_MAX_MBDN_NUM
#else
   #define SMSAL_MAX_MAILBOX_NUM  SMSAL_MAX_LINES
#endif

#ifdef __SMS_MSP_UP_TO_4__
#define SMSAL_MAX_MSP_NUM     4  //(max support msp)
#ifdef __REL6__
#define SMSAL_MAX_MBDN_NUM    10 // 20 is too much, reduce to 10
#else
#define SMSAL_MAX_MBDN_NUM    10 // 16 is too much, reduce to 10
#endif
#else //__SMS_MSP_UP_TO_4__
#define SMSAL_MAX_MSP_NUM     2 //(max support msp)
#ifdef __REL6__
#define SMSAL_MAX_MBDN_NUM    10 //(5 * SMSAL_MAX_MSP_NUM, max support mbdn)
#else
#define SMSAL_MAX_MBDN_NUM    8 //(4 * SMSAL_MAX_MSP_NUM, max support mbdn)
#endif
#endif //__SMS_MSP_UP_TO_4__

/* 
 * !! Attention !!
 *
 * the following constants are related to CB : 
 * the CB in RMC/MMI MUST be consistent with this defined values !! 
 *
 */

/* Ripple: CB for SMSAL/RATCM/GAS/BMC. */
#define CB_MAX_MSG_CBMI_NUM    60
#define SMSAL_CB_MAX_ENTRY 30
#define CB_MAX_MSG_CBMID_NUM    SMSAL_CB_MAX_ENTRY
#define CB_MAX_MSG_CBMIR_NUM    (SMSAL_CB_MAX_ENTRY*2)
#define CB_MAX_LANG_NUM    SMSAL_CB_MAX_ENTRY
#define CB_MAX_DATA_NUM_PER_PAGE 88

#define SMSAL_CB_PER_7BIT_LEN          (93)
#define SMSAL_CB_PER_UCS2_LEN          (88)
#define SMSAL_CB_PER_UCS2_CONT_LEN     (82)


#define SMSAL_PS_CBMI_MAX_ENTRY        (60)
#if defined(__CB_CHANNEL_ONLY_STORED_IN_NVRAM__)
#define SMSAL_CBMI_SIM_ENTRY           (0)
#else
#define SMSAL_CBMI_SIM_ENTRY           (20)
#endif
#if defined(__CB_CHANNEL_ONLY_STORED_IN_NVRAM__)
#define SMSAL_CBMI_ME_ENTRY            (40)
#else
#define SMSAL_CBMI_ME_ENTRY            (20)
#endif
#define SMSAL_DEFAULT_CBMI_ENTRY       (10)
#define SMSAL_DEFAULT_DCS_ENTRY        (21)  /* CBS DCS 20 language + unspecified (other language) */

#define SMSAL_MMI_CBMI_MAX_ENTRY       (SMSAL_CBMI_SIM_ENTRY + SMSAL_CBMI_ME_ENTRY)
#define SMSAL_MMI_DCS_MAX_ENTRY        (SMSAL_CB_MAX_ENTRY)

#define SMSAL_CB_UNUSED_CBMI        (0xffff) /* unused CBMIR 0xffffffff */
#define SMSAL_CB_UNUSED_DCS         (0x0080) /* one byte */
#define SMSAL_CB_UNUSED_ISO639      (0xffff) /* two byte */

#define SMSAL_CB_HOMEZONE_MI        (0x00dd) /* HomeZone Message ID 221 */
#define SMSAL_CB_HOMEZONE_SN        (0x0010) /* HomeZone Series Number */
#define SMSAL_CB_HOMEZONE_DCS       (0x0000) /* HomeZone DCS */

#define SMSAL_PAGE_SIZE             (40)        /* 40 messages/page */                                              
#define SMSAL_ONE_MSG_LEN           (160)
#define SMSAL_ADDR_LEN              (11)
#define SMSAL_ME_ADDR_LEN           (21)
#define SMSAL_INVALID_INDEX         (0xffff)
#define SMSAL_MAX_TPDU_SIZE         (175)

/* SMS PART END */

#define PHB_MAX_ASSOCIATE_GRP 10
#define PHB_MAX_EMAIL_LENGTH 61

#define MAX_SIM_NAME_LEN               (32)
#define MAX_PLMN_LEN             6

#ifdef __PLMN_LIST_WITH_CELL_INFO__
#if defined(__UMTS_RAT__) && defined(__GSM_RAT__)
/* under construction !*/
#else
#define MAX_PLMN_LIST_LEN        8
#endif
#else
#if defined(__UMTS_RAT__) && defined(__GSM_RAT__)
/* under construction !*/
#else
#define MAX_PLMN_LIST_LEN        16
#endif
#endif /* __PLMN_LIST_WITH_CELL_INFO__ */

#define MAX_NW_NAME_LEN 24

/* DO NOT MODIFY THIS BY YOURSELF!! Please confirm with SIM task owner first.  
   1. Enlarge this max support size will cause ctrl buffer usage grow.                      
   2. full SW library(ex: L4,SIM,MM lib) update is necessary                   */
#ifdef LOW_COST_SUPPORT
#define MAX_SUPPORT_PLMN_DATA_SIZE       120  
#else
#ifdef __EXTENDED_PLMN_DATA_SIZE__
#define MAX_SUPPORT_PLMN_DATA_SIZE       650
#else
#define MAX_SUPPORT_PLMN_DATA_SIZE       500     
#endif
#endif

/* Max supported PLMN record number is decided by MAX_SUPPORT_PLMN_DATA_SIZE and record size
   SIM task can support up to MAX_SUPPORT_PLMN_DATA_SIZE / PLMN_record_size records
   NOTE: Record size is 5 bytes for EF_UPLMNWACT,EF_OPLMNWACT,etc.  3 bytes for EF_PLMNSEL   */
#define MAX_SUPPORT_EF_PLMNSEL_REC       MAX_SUPPORT_PLMN_DATA_SIZE/3  

#define L4C_FDN_CHECK_FAIL  2601

#define L4C_EM_QUICK_TEST_MAX_COUNT 100

#define IS_INTER_NUM(ton) (( (ton) & 0x10) != 0 )

#define MO_CALL_ASSIGN_FAIL_CALLID 254  /* CSMCC_INVALID_CALL_ID-1 */

/* This value is used by MMI and equals to LMMI_SRC to prevent it using HAL private header */
#define L4C_SOURCE_ID_DEFAULT 0

typedef enum
{
    L4C_CALL_OPERATION,   
    L4C_SS_OPERATION,  
    L4C_SMS_OPERATION,  /*used by l4_custom_approval_type() only*/
    L4C_SMS_SCA_OPERATION,    
    L4C_SMS_DA_OPERATION,
    L4C_CSD_OPERATION,        // internal CSD access  e.g. wap over CSD	
    L4C_INT_GPRS_OPERATION,   // internal GPRS access e.g. wap over GPRS
    L4C_EXT_GPRS_OPERATION,   // external GPRS access e.g. GPRS dialup
    L4C_NONE_OPERATION = 255
}l4c_operation_type_enum; //MAUI_02956467, mtk02285, moved from l4c_common_enum.h
#define L4C_MAX_ETWS_SECURITY_INFO_LEN  50

#ifdef __PLMN_LIST_PREF_SUPPORT__
typedef enum
{
  /* This enum should sync with plmn_list_preference_enum  */
   L4C_ACCURACY_PREFERED,
   L4C_SPEED_PREFERED
}l4c_plmn_list_preference_enum;
#endif

#define SM_PCO_CONTAINER_ID_DNS_SERVER_IPV6_ADDRESS 0x0003

#if (defined(__IPV4V6__) || defined (__IPV6__))
#define MAX_SRC_ADDR_SBNET_MASK_LEN 32  // For IPv6
#else  /* (defined(__IPV4V6__) || defined (__IPV6__)) */
#define MAX_SRC_ADDR_SBNET_MASK_LEN 8   // For IPv4
#endif /* (defined(__IPV4V6__) || defined (__IPV6__)) */

typedef enum {
   PHB_LN_CALL,
   PHB_LN_VOIP,
   PHB_LN_VIDEO
} phb_ln_addr_type_enum;

typedef enum {
   PHB_STORAGE_NONE,
   PHB_STORAGE_NVRAM,
   PHB_STORAGE_SIM,
   PHB_STORAGE_SIM2,
   PHB_STORAGE_SIM3,
   PHB_STORAGE_SIM4,
   PHB_STORAGE_TCARD,
   PHB_STORAGE_NUM = PHB_STORAGE_TCARD,
   PHB_STORAGE_MAX
} phb_storage_enum;


typedef enum {
   PHB_ERRNO_FAIL,
   PHB_ERRNO_SUCCESS,
   PHB_ERRNO_NOT_SUPPORT,
   PHB_ERRNO_READ_FAIL,
   PHB_ERRNO_READ_SUCCESS,
   PHB_ERRNO_READ_EMPTY,
   PHB_ERRNO_DELETE_EMPTY,
   PHB_ERRNO_NOT_READY,
   PHB_ERRNO_BUSY,
   PHB_ERRNO_ANR_FULL,
   PHB_ERRNO_EMAIL_FULL,
   PHB_ERRNO_SNE_FULL
} phb_errno_enum;

typedef enum {
   PHB_LND,
   PHB_LNM,
   PHB_LNR,
   PHB_LN_NONE,
   PHB_LN_MAX = PHB_LN_NONE
} phb_ln_type_enum;

typedef enum {
   PHB_NONE,
   PHB_ECC,
   PHB_FDN,
   PHB_BDN,
   PHB_MSISDN,
   PHB_SDN,
   PHB_PHONEBOOK,
   PHB_EXT1,   
   /* USIM */
   PHB_SNE, 
   PHB_AAS,
   PHB_ANR,
   PHB_GAS,
   PHB_GRP,
   PHB_EMAIL,
   PHB_PBC,
   /* USIM */
   PHB_TYPE_ENUM_MAX
} phb_type_enum;

#if 1
#ifndef VOIP_URI_LEN
#define VOIP_URI_LEN                        (41)
#endif
#endif //remove on MAUIW1043_RHR remove stage


#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
#define PHB_TYPE_TOTAL  PHB_TYPE_ENUM_MAX
#else
#define PHB_TYPE_TOTAL  PHB_EXT1
#endif

#ifndef NVRAM_PHB_SIZE
#define NVRAM_PHB_SIZE (54+MAX_PS_NAME_SIZE)
#endif

/* Max entries could be packed in peer buffer */
#define PHB_MAX_PHB_ENTRIES            (0+10)   

typedef enum
{
	L4C_PHB_UPDATE,
	L4C_PHB_DELETE,
	L4C_PHB_DELETE_ALL,
	L4C_PHB_WRITE_LND,
	L4C_PHB_WRITE_LNM,
	L4C_PHB_WRITE_LNR,
	L4C_PHB_DELETE_LND,
	L4C_PHB_DELETE_LNM,
	L4C_PHB_DELETE_LNR,
	L4C_PHB_UPDATE_NONE
}l4c_phb_update_enum;

typedef enum {
   PHB_NO_CAUSE,
   PHB_CAUSE_STORAGE_FULL,          /* This value is returned when just added entry causes storage full */
   PHB_CAUSE_CAPACITY_EXCEEDED,      /* Since storage is full, attempt of adding an entry returns this value */
   PHB_CAUSE_NOT_SUPPORT
} phb_cause_enum;

typedef enum
{
    APPROVAL_TYPE_NONE,
    APPROVAL_TYPE_ECC_ONLY,
    APPROVAL_TYPE_FDN_ONLY,
    APPROVAL_TYPE_FULL		//check both ECC and FDN
}l4c_phb_approval_type_enum;

typedef enum {
   PHB_BCD = 0x01,
   PHB_ASCII = 0x00,
   PHB_UCS2 = 0x08
#ifdef __PHB_0x81_SUPPORT__	/*MTK 2004-04-20 Wisoln, support maximum length of 0x81 UCS2*/
   ,
   PHB_UCS2_81 = 0x09,
   PHB_UCS2_82 = 0x10
#endif
} phb_charset_enum;



typedef enum
{
   L4C_OK,
   L4C_ERROR,
   L4C_NVRAM_ERROR_INIT = 5

} l4c_result_enum;

/* Johnny: for RMMI internal usage, do not add other enums here */
typedef enum
{
   L4C_NO_CAUSE,
   L4C_GEN_CAUSE
} l4c_cause_enum;

typedef enum
{
    ATCI_REQ_QOS = 0,
    ATCI_MIN_QOS,
    ATCI_NEG_QOS 	/* SATe */
} atci_qos_enum;

typedef enum {
    SUBSCRIBED_DELAY_CLASS = 0,
    RESERVED_NW_TO_MS_DELAY_CLASS = 0,
    DELAY_CLASS1,
    DELAY_CLASS2,
    DELAY_CLASS3,
    DELAY_CLASS4,
    RESERVED_BIDIRECT_DELAY_CLASS = 7,
    TOT_DELAY_CLASS = 8
} delay_class_enum;

typedef enum {
    SUBSCRIBED_REL_CLASS = 0,
    RESERVED_NW_TO_MS_REL_CLASS  = 0,
    REL_CLASS1,
    REL_CLASS2,
    REL_CLASS3,
    REL_CLASS4,
    REL_CLASS5,
    RESERVED_BIDIRECT_REL_CLASS = 7
} reliability_class_enum;

typedef enum {
    SUBSCRIBED_PTC = 0,
    RESERVED_NW_TO_MS_PTC = 0,
    PTC_1,
    PTC_2,
    PTC_3,
    PTC_4,
    PTC_5,
    PTC_6,
    PTC_7,
    PTC_8,
    PTC_9,
    RESERVED_BIDIRECT_PTC = 15
} peak_throughput_class;

typedef enum {
    SUBSCRIBED_PREC_CLASS = 0,
    RESERVED_NW_TO_MS_PREC_CLASS  = 0,
    PREC_CLASS1,
    PREC_CLASS2,
    PREC_CLASS3,
    RESERVED_BIDIRECT_PREC_CLASS = 7
} precedence_class_enum;

typedef enum {
    SUBSCRIBED_MEAN_THROUGHPUT = 0,
    RESERVED_NW_TO_MS_MEAN_THROUGHPUT = 0,
    MEAN_THROUGHPUT1,
    MEAN_THROUGHPUT2,
    MEAN_THROUGHPUT3,
    MEAN_THROUGHPUT4,
    MEAN_THROUGHPUT5,
    MEAN_THROUGHPUT6,
    MEAN_THROUGHPUT7,
    MEAN_THROUGHPUT8,
    MEAN_THROUGHPUT9,
    MEAN_THROUGHPUT10,
    MEAN_THROUGHPUT11,
    MEAN_THROUGHPUT12,
    MEAN_THROUGHPUT13,
    MEAN_THROUGHPUT14,
    MEAN_THROUGHPUT15,
    MEAN_THROUGHPUT16,
    MEAN_THROUGHPUT17,
    MEAN_THROUGHPUT18,
    RESERVED_BIDIRECT_MEAN_THROUGHPUT = 30,
    BEST_EFFORT_THROUGHPUT = 31
} mean_throughput_enum;

typedef enum
{
     IPV4_ADDR_TYPE = 0X21,
     IPV6_ADDR_TYPE = 0X57,
     IPV4V6_ADDR_TYPE = 0X8D,
     PPP_ADDR_TYPE  = 0X01,
     OSP_IHOSS_ADDR_TYPE = 0X02,
     NULL_PDP_ADDR_TYPE = 0X03 /* This is added incase if no pdpaddrtype is 
                                  specified */
}pdp_addr_type_enum;

typedef enum
{
     IPV4_ADDR_LEN = 0X04,
     IPV6_ADDR_LEN = 0X10,
     IPV4V6_ADDR_LEN = 0X14,
     PPP_ADDR_LEN  = 0X0,
     OSP_IHOSS_ADDR_LEN = 0X0,
    /* NULL_PDP_ADDR_LEN = 0X02  Incase if no pdpaddr is specified then this
                                 length will be null */
    NULL_PDP_ADDR_LEN = 0X01
}pdp_addr_len_enum;

typedef enum
{
   L4C_GPRS_ATTACHED, //0
   L4C_NONE_GPRS, // 1
   L4C_GPRS_DETACHED, // 2
   L4C_INVALID_SIM,// 3
   L4C_GPRS_ATTEMPT_ATTACH,// 4
   L4C_GPRS_COVERAGE,//5 
   L4C_PDP_ATTEMPT_ACT,//6
   L4C_PDP_DEACTIVED,//7
   L4C_PDP_ACTIVED//8
} l4c_gprs_status_enum;

typedef enum
{
   L4C_RAT_NONE,
   L4C_RAT_GSM,
   L4C_RAT_UMTS,
   L4C_RAT_GSM_UMTS
} l4c_rat_enum;

typedef enum
{
   L4C_PREFER_RAT_NONE,
   L4C_PREFER_RAT_GSM,
   L4C_PREFER_RAT_UMTS,
   L4C_PREFER_RAT_INVALID
} l4c_prefer_rat_enum;

typedef enum 
{
   L4C_SIM_NOT_INSERTED,
   L4C_SIM_INSERTED,
   L4C_SIM_BLOCK,
   L4C_SIM_NONE
}l4c_sim_status_enum;

typedef enum
{
  CS_DOMAIN    = 0,
  PS_DOMAIN    = 1,
  CS_PS_DOMAIN = 2,
  DOMAIN_NONE  = 3
} domain_id_enum;

typedef enum
{
    NONE_SPECIFIED = 0x00,
    GPRS_SUPPORT = 0x01,
    EDGE_SUPPORT = 0x02,
    UMTS_SUPPORT = 0x04,
    HSDPA_SUPPORT = 0x08,
    HSUPA_SUPPORT = 0x10,
    HSDPA_UPA_SUPPORT = 0x18,
    NOT_CHANGE = 0xff     
}data_speed_support_enum;

typedef enum
{
   DATA_SPEED_NONE_ACTIVATE = 0x0000,
   DATA_SPEED_GPRS_CAPABILITY = 0x0001,
   DATA_SPEED_EDGE_CAPABILITY = 0x0002,
   DATA_SPEED_UMTS_CAPABILITY = 0x0004,
   DATA_SPEED_HSDPA_CAPABILITY = 0x0008,           //mac-hs
   DATA_SPEED_HSUPA_CAPABILITY = 0x0010,           //mac-e/es
   DATA_SPEED_HSDPA_HSUPA_CAPABILITY = 0x0018,     //mac-hs + mac-e/es
   DATA_SPEED_HSDPAP_CAPABILITY = 0x0020,          //mac-ehs
   DATA_SPEED_HSDPAP_UPA_CAPABILITY = 0x0030,      //mac-ehs + mac-e/es
   DATA_SPEED_HSUPAP_CAPABILITY = 0x0040,          //mac-i/is
   DATA_SPEED_HSUPAP_DPA_CAPABILITY = 0x0048,      //mac-hs + mac-i/is
   DATA_SPEED_HSPAP_CAPABILITY = 0x0060,           //mac-ehs + mac-i/is
   DATA_SPEED_DC_DPA_CAPABILITY = 0x0088,          //(DC) mac-hs
   DATA_SPEED_DC_DPA_UPA_CAPABILITY = 0x0098,      //(DC) mac-hs + mac-e/es
   DATA_SPEED_DC_HSDPAP_CAPABILITY = 0x00a0,       //(DC) mac-ehs
   DATA_SPEED_DC_HSDPAP_UPA_CAPABILITY = 0x00b0,   //(DC) mac-ehs + mac-e/es
   DATA_SPEED_DC_HSUPAP_DPA_CAPABILITY = 0x00c8,   //(DC) mac-hs + mac-i/is
   DATA_SPEED_DC_HSPAP_CAPABILITY = 0x00e0,         //(DC) mac-ehs + mac-i/is
   DATA_SPEED_LTE_CAPABILITY = 0x1000
} data_speed_activate_enum; 


typedef enum
{
   CSD_BEARER_DIALUP,
   GPRS_BEARER_DIALUP,
   INVALID_BEARER
}l4c_dialup_bearer_enum; //Moved from l4c_common_enum.h

typedef enum
{
   TCM_PDP_DEACTIVATE,
   TCM_PDP_ACTIVATE,
   TCM_PDP_DEACTIVATE_LOCAL /* __LOCAL_DEACTIVATE_PDP_SUPPORT__ */
}l4c_tcm_pdp_action_enum;

typedef enum
{
   TCM_AT_PDP_CID = 1,
   TCM_EM_PDP_CID_1 = 2,
   TCM_EM_PDP_CID_2
}l4c_tcm_em_pdp_cid_enum; //mtk00714 w0634

typedef enum
{
    RMMI_UCM_ATD = 0,
    RMMI_UCM_ATD_2,
    RMMI_UCM_ATD_3,
    RMMI_UCM_ATD_4,
    RMMI_UCM_ATD_DATA, //for ATD dialing data call
    RMMI_UCM_ATH,
    RMMI_UCM_ATA,
    RMMI_UCM_BLDN,
    RMMI_UCM_CHLD,
    RMMI_UCM_CHUP,
    RMMI_UCM_MEM_DIAL,  //mem dial from SIM1
    RMMI_UCM_MEM_DIAL_2, //mem dial from SIM2
    RMMI_UCM_MEM_DIAL_3,
    RMMI_UCM_MEM_DIAL_4
} rmmi_ucm_action_enum;

typedef enum
{
    RMMI_UCM_CAUSE_NONE = 0,
    RMMI_UCM_CAUSE_ATD_NOT_ALLOWED,
    RMMI_UCM_CAUSE_ATA_NOT_ALLOWED,
    RMMI_UCM_CAUSE_ATH_NOT_ALLOWED,
    RMMI_UCM_CAUSE_CHLD_NOT_ALLOWED,
    RMMI_UCM_CAUSE_NO_CALL_TO_ANSWER,   //specific cause for ATA
    RMMI_UCM_CAUSE_NO_CALL_TO_HANGUP,   //specific cause  for ATH   
    RMMI_UCM_CAUSE_NO_CALL_TO_HOLD,     //specific cause  for CHLD              
    RMMI_UCM_CAUSE_NO_CALL_TO_REL,      //specific cause for CHLD
    RMMI_UCM_CAUSE_NO_CALL_TO_ECT,      //specific cause for CHLD
    RMMI_UCM_CAUSE_NO_CALL_TO_CONFERENCE,       // specific cause for CHLD                
    RMMI_UCM_CAUSE_INVALID_CALLID,      //specific cause for CHLD
    RMMI_UCM_CAUSE_NO_NUM_EXIST, //specific cause for memory dial or bldn when number not exist ( BQB expect return "ERROR") 
    RMMI_UCM_CAUSE_ATD_DATA_NOT_ALLOWED //MAUI_02634907
} rmmi_ucm_cause_enum;

typedef enum
{
    RMMI_UCM_RCODE_OK,
    RMMI_UCM_RCODE_CONNECT,
    RMMI_UCM_RCODE_RING,
    RMMI_UCM_RCODE_NO_CARRIER,
    RMMI_UCM_RCODE_ERROR,
    RMMI_UCM_RCODE_CCWA
} rmmi_rcode_type_enum;

typedef enum
{
    CLIR_INVOKE,
    CLIR_SUPPRESS,
    CLIR_AUTO
} rmmi_clir_enum;

typedef enum 
{
   CALL_DIAL,
   CALL_ANSWER
}l4c_data_call_op_enum;

typedef enum
{
    L4C_DISCONNECT_NONE,
    L4C_DISCONNECT_MO,
    L4C_DISCONNECT_MT
} l4c_ath_req_enum;

typedef enum
{
    L4C_SS_MO,
    L4C_SS_MT,
    L4C_SS_NONE
} l4c_ss_direction_enum;

typedef enum
{
   CSMCC_REL_HELD_OR_UDUB, /*0*/
   CSMCC_REL_ACTIVE_AND_ACCEPT, /*1*/
   CSMCC_REL_SPECIFIC_CALL, /*2*/
   CSMCC_HOLD_ACTIVE_AND_ACCEPT, /*3*/
   CSMCC_HOLD_ACTIVE_EXCEPT_SPECIFIC_CALL, /*4*/
   CSMCC_ADD_HELD_CALL, /*5*/
   CSMCC_EXPLICIT_CALL_TRANSFER, /*6*/
   CSMCC_ACTIVATE_CCBS_CALL, /*7*/
   CSMCC_REL_ALL_EXCEPT_WAITING_CALL, /*8*/
   CSMCC_REL_SPECIFIC_ACTIVE_CALL, /* 9 */
   CSMCC_SWAP_CALL, /* 10 */
   CSMCC_REL_HELD,  /* 11 */
   CSMCC_REL_ACTIVE,  /* 12 */
   CSMCC_REL_ALL,  /* 13 */
   CSMCC_REL_UDUB,  /* 14 */
   CSMCC_REL_CCBS,  /* 15 */
   CSMCC_REL_ACTIVE_AND_ACCEPT_WAITING,  /* 16 */
   CSMCC_REL_ACTIVE_AND_ACCEPT_CCBS,  /* 17 */
   CSMCC_REL_ACTIVE_AND_ACCEPT_HELD,  /* 18 */
   CSMCC_HOLD_ACTIVE_AND_ACCEPT_WAITING,  /* 19 */
   CSMCC_HOLD_ACTIVE_AND_ACCEPT_CCBS,  /* 20 */
   CSMCC_VT_FALL_TO_VOICE, /* 21 */ /*MAUI_02641977 CMCC requietment, to disconnect the vt call with cause88*/
   
   CSMCC_INVALID_CRSS_TYPE = 255
} csmcc_crss_req_enum;

typedef enum
{
   CLCC_MO_CALL,
   CLCC_MT_CALL,
   CLCC_UNKNOWN_DIR
} clcc_dir_enum;

typedef enum
{
   CSMCC_SETUP_MSG,
   CSMCC_DISCONNECT_MSG,
   CSMCC_ALERT_MSG,
   CSMCC_CALL_PROCESS_MSG,
   CSMCC_SYNC_MSG,
   CSMCC_PROGRESS_MSG,
   CSMCC_CALL_CONNECTED_MSG,
   CSMCC_ALL_CALLS_DISC_MSG = 129,
   CSMCC_MO_CALL_ID_ASSIGN_MSG = 130,
   CSMCC_STATE_CHANGE_HELD = 131,
   CSMCC_STATE_CHANGE_ACTIVE = 132,
   CSMCC_STATE_CHANGE_DISCONNECTED = 133,
   CSMCC_STATE_CHANGE_MO_DISCONNECTING =134, 
   CSMCC_CPI_END = 255
}csmcc_cpi_msg_type_enum; /*mtk00924 add 041210 for +ECPI*/


typedef enum {
   INVALID_OPERATION,
   SS_OPERATION,
   SIM_OPERATION,
   GPRS_OPERATION,
   CC_OPERATION
} csmss_string_op_enum;

//kc1111
//0: test
//1: reconfiguration
//2: manually
//3: automatically
typedef enum
{
   ECALL_TEST,
   ECALL_RECONFIGURATION,
   ECALL_MANUALLY_INITIATED,
   ECALL_AUTOMATICALLY_INITIATED,
   ECALL_DISABLE = 0xff
} ecall_type_enum;

//agps begin
/* ENUMERATED NotificationToMSUser */
typedef enum
{
   L4C_SS_NotificationToMSUser_notifyLocationAllowed,
   L4C_SS_NotificationToMSUser_notifyAndVerify_LocationAllowedIfNoResponse,
   L4C_SS_NotificationToMSUser_notifyAndVerify_LocationNotAllowedIfNoResponse,
    // ...
   L4C_SS_NotificationToMSUser_locationNotAllowed
}
L4C_SS_NotificationToMSUser;

/* ENUMERATED OccurrenceInfo */
typedef enum
{
   L4C_SS_OccurrenceInfo_oneTimeEvent,
   L4C_SS_OccurrenceInfo_multipleTimeEvent
    // ...
}
L4C_SS_OccurrenceInfo;

/* ENUMERATED LocationEstimateType */
typedef enum
{
   L4C_SS_LocationEstimateType_currentLocation,
   L4C_SS_LocationEstimateType_currentOrLastKnownLocation,
   L4C_SS_LocationEstimateType_initialLocation,
    // ...
   L4C_SS_LocationEstimateType_activateDeferredLocation,
   L4C_SS_LocationEstimateType_cancelDeferredLocation
}
L4C_SS_LocationEstimateType;

/* ENUMERATED LCS-FormatIndicator */
typedef enum
{
   L4C_SS_LCS_FormatIndicator_logicalName,
   L4C_SS_LCS_FormatIndicator_e_mailAddress,
   L4C_SS_LCS_FormatIndicator_msisdn,
   L4C_SS_LCS_FormatIndicator_url,
   L4C_SS_LCS_FormatIndicator_sipUrl
    // ...
}
L4C_SS_LCS_FormatIndicator;

/* ENUMERATED VerificationResponse */
typedef enum
{
   L4C_SS_VerificationResponse_permissionDenied,
   L4C_SS_VerificationResponse_permissionGranted
    // ...
}
L4C_SS_VerificationResponse;

/* ENUMERATED AreaType */
typedef enum
{
   L4C_SS_AreaType_countryCode,
   L4C_SS_AreaType_plmnId,
   L4C_SS_AreaType_locationAreaId,
   L4C_SS_AreaType_routingAreaId,
   L4C_SS_AreaType_cellGlobalId,
    // ...
   L4C_SS_AreaType_utranCellId
}
L4C_SS_AreaType;

/* ENUMERATED MOLR-Type */
typedef enum
{
   L4C_SS_MOLR_Type_locationEstimate,
   L4C_SS_MOLR_Type_assistanceData,
   L4C_SS_MOLR_Type_deCipheringKeys
    // ...
}
L4C_SS_MOLR_Type;

/* ENUMERATED LocationMethod */
typedef enum
{
   L4C_SS_LocationMethod_msBasedEOTD,
   L4C_SS_LocationMethod_msAssistedEOTD,
   L4C_SS_LocationMethod_assistedGPS,
    // ...
   L4C_SS_LocationMethod_msBasedOTDOA
}
L4C_SS_LocationMethod;

/* ENUMERATED ResponseTimeCategory */
typedef enum
{
   L4C_SS_ResponseTimeCategory_lowdelay,
   L4C_SS_ResponseTimeCategory_delaytolerant
    // ...
}
L4C_SS_ResponseTimeCategory;
//agps end

/* SMS PART START */
typedef enum
{
   SMSAL_DEFAULT_PID = 0x00,   /* Text SMS */
   SMSAL_TELEX_PID   = 0x21,   /* Telex */
   SMSAL_G3_FAX_PID  = 0x22,   /* Group 3 telefax */
   SMSAL_G4_FAX_PID  = 0x23,   /* Group 4 telefax */
   SMSAL_VOICE_PID   = 0x24,   /* Voice Telephone */
   SMSAL_ERMES_PID   = 0x25,   /* ERMES (European Radio Messaging System) */
   SMSAL_PAGING_PID  = 0x26,   /* National Paging system */
   SMSAL_X400_PID    = 0x31,   /* Any public X.400-based message system */
   SMSAL_EMAIL_PID   = 0x32    /* E-mail SMS */
   
} smsal_pid_enum;

typedef enum
{
   SMSAL_DEFAULT_DCS        = 0x00,  /* GSM 7-bit */
   SMSAL_8BIT_DCS           = 0x04,  /* 8-bit */
   SMSAL_UCS2_DCS           = 0x08,  /* UCS2 */  
   SMSAL_RESERVED_DCS       = 0x0c,  /* reserved alphabet,
                                        currently, MMI shall display "not support alphabet" 
                                        or "cannot display" when receive dcs indicated this value */ 
   SMSAL_EXT_DCS            = 0x10  /* Special dcs for non-standard character, 
                                       used by MMI and EMS */
} smsal_dcs_enum;

typedef enum
{
   /* Mailbox */
   SMSAL_LINE_1 = 0,
   SMSAL_LINE_2 = 1,
   SMSAL_MAX_LINES = 2,          

   /* SMS profile parameter */
   SMSAL_PROFILE_1 = 0,
   SMSAL_PROFILE_2 = 1,
   SMSAL_PROFILE_3 = 2,
   SMSAL_PROFILE_4 = 3, /* SMSAL_MAX_PROFILE_NUM (4) */
   SMSAL_PROFILE_NONE = 0xff /* invalid profile ID */
} smsal_dest_no_enum;

typedef enum
{
   SMSAL_CB_MI          = 0x01,
   SMSAL_CB_MIR         = 0x02,
   SMSAL_CB_DCS         = 0x04,
   SMSAL_CB_MI_MASK     = 0x08,
   SMSAL_CB_MIR_MASK    = 0x10,
   SMSAL_CB_DCS_MASK    = 0x20,
   SMSAL_CB_ALL_LANG    = 0x40
} smsal_cb_para_enum;

/* TP-Status(TP-ST) in Status Report */
typedef enum
{
   /* 
    * Short message transaction completed 
    */
   ST_COMP_MSG_RECV_BY_SME      = 0x00,  /* Short message received by the SME */
   ST_COMP_MSG_FORWARD_NOT_CONF = 0x01,  /* Short message forwarded by the SC to the SME 
                                            but the SC is unable to confirm deliver */
   ST_COMP_MSG_REPLACE          = 0x02,  /* Short message replaced by the SC */
   
   /* 
    * Temporary error, SC still trying to transfer SM 
    */
   ST_TE1_CONGESTION           = 0x20,  /* Congestion */
   ST_TE1_SME_BUSY             = 0x21,  /* SME busy */
   ST_TE1_NO_RSP_FROM_SME      = 0x22,  /* No response from SME */
   ST_TE1_SERVICE_REJECT       = 0x23,  /* Service rejected */
   ST_TE1_QOS_NOT_AVAIL        = 0x24,  /* Quality of service not available */
   ST_TE1_ERROR_IN_SME         = 0x25,  /* Error in SME */
   
   /* 
    * Permanent error, SC is not making any more transfer attempts 
    */
   ST_PE_REMOTE_PROC_ERROR    = 0x40,  /* Remote procedure error */
   ST_PE_INCOMP_DEST          = 0x41,  /* Incompatible destination */
   ST_PE_CONN_REJ_BY_SME      = 0x42,  /* Connection rejected by SME */
   ST_PE_NOT_OBTAINABLE       = 0x43,  /* Not obtainable */
   ST_PE_QOS_NOT_AVAIL        = 0x44,  /* Quality of service not available */
   ST_PE_NO_INTERWK_AVAIL     = 0x45,  /* No interworking available */
   ST_PE_VP_EXPIRED           = 0x46,  /* SM Validity Period Expired */
   ST_PE_DEL_BY_ORI_SME       = 0x47,  /* SM Deleted by originating SME */
   ST_PE_DEL_BY_SC            = 0x48,  /* SM Deleted by SC Administration */
   ST_PE_NOT_EXIST            = 0x49,  /* SM does not exist */
         
   /* 
    * Temporary error, SC is not making any more transfer attempts
    */
   ST_TE2_CONGESTION           = 0x60,  /* Congestion */
   ST_TE2_SME_BUSY             = 0x61,  /* SME busy */
   ST_TE2_NO_RSP_FROM_SME      = 0x62,  /* No response from SME */
   ST_TE2_SERVICE_REJECT       = 0x63,  /* Service rejected */
   ST_TE2_QOS_NOT_AVAIL        = 0x64,  /* Quality of service not available */
   ST_TE2_ERROR_IN_SME         = 0x65,  /* Error in SME */ 
    
   ST_SERVICE_REJECT           = 0xff   /* all reserved values interpreted as "service reject" */
   
} smsal_st_enum;

/* 
 * the difference between SMSAL_SM_PREFER and SMSAL_MT is :
 *
 * SMSAL_SM_PREFER : in at+cpms? , only SIM storage information will be return
 * SMSAL_MT        : .....         both SIM/ME storage information will be return
 */
typedef enum
{
   SMSAL_SM = 0,            /* SIM only   */
   SMSAL_ME = 1,            /* ME only    */     
   SMSAL_SR = 2,            /* status report (currently NOT support) */   
   SMSAL_BM = 3,            /* broadcast     (currently NOT support) */   
   SMSAL_TA = 4,            /* adaptation    (currently NOT support) */    
   SMSAL_SM_PREFER = 5,     /* SIM prefer, try SIM first, then ME */
   SMSAL_ME_PREFER = 6,     /* ME prefer, try ME first, then SIM */        
   SMSAL_MT = 7,            /* any of storages associated with ME (SIM first) */       
   SMSAL_STORAGE_UNSPECIFIED = 7   
      
} smsal_storage_enum;

#ifdef SMS_FOR_NEPTUNE
/* This enum is for para_ind in both l4csmsal_set_parameter_req_struct (2 bytes) */
/* and smsal_send_msg_req_struct(1 byte).                                        */
typedef enum
{
   SMSAL_PARA_FO             =   0x01,
   SMSAL_PARA_SCA            =   0x02,
   SMSAL_PARA_PID            =   0x04,
   SMSAL_PARA_DCS            =   0x08,
   SMSAL_PARA_VP             =   0x10,   
   SMSAL_PARA_SUPP_CONCAT    =   0x20,
   SMSAL_PARA_BEARER         =   0x40,
   SMSAL_PARA_DIRECT_DISPLAY =   0x80,
   SMSAL_PARA_PREFER_MEM     = 0x0100,   
   SMSAL_PARA_CBCH_REQ       = 0x0200,   
   SMSAL_PARA_MAILBOX_ADDR   = 0x0400,   
   SMSAL_PARA_PROFILE_NAME   = 0x0800,
   SMSAL_PARA_ALL_CB_LANG    = 0x1000,
   SMSAL_PARA_SAVE_PROFILE   = 0x2000,
   SMSAL_PARA_RESTORE_PROFILE= 0x4000,

   SMSAL_COM_PARA_FO             =   0x0001,
   SMSAL_COM_PARA_BEARER         =   0x0002,
   SMSAL_COM_PARA_PREFER_MEM     =   0x0004,   
   SMSAL_COM_PARA_STATUS_REP     =   0x0008,   
   SMSAL_COM_PARA_REPLY_PATH     =   0x0010,   
   SMSAL_COM_PARA_CBCH_REQ       =   0x0020,   
   SMSAL_COM_PARA_MAILBOX_ADDR   =   0x0040,   
   SMSAL_COM_PARA_ALL_CB_LANG    =   0x0080,
   SMSAL_COM_PARA_RESTORE_PROFILE=   0x0100,
   SMSAL_COM_PARA_MBI_NUM        =   0x0200
//   SMSAL_COM_PARA_SEL_MSP        =   0x0400
} smsal_parameter_enum;

#else
typedef enum
{
   SMSAL_PARA_FO               =   0x0001,
   SMSAL_PARA_PID              =   0x0002,
   SMSAL_PARA_DCS              =   0x0004,
   SMSAL_PARA_VP               =   0x0008,   
   SMSAL_PARA_SCA              =   0x0010,
   SMSAL_PARA_PROFILE_NAME     =   0x0020,
   SMSAL_PARA_SAVE_PROFILE     =   0x0040,

   SMSAL_PARA_STATUS_REP       =   0x0100,
   SMSAL_PARA_REPLY_PATH       =   0x0200
} smsal_profile_para_enum;

typedef enum
{
   SMSAL_COM_PARA_FO             =   0x0001,
   SMSAL_COM_PARA_BEARER         =   0x0002,
   SMSAL_COM_PARA_PREFER_MEM     =   0x0004,   
   SMSAL_COM_PARA_STATUS_REP     =   0x0008,   
   SMSAL_COM_PARA_REPLY_PATH     =   0x0010,   
   SMSAL_COM_PARA_CBCH_REQ       =   0x0020,   
   SMSAL_COM_PARA_MAILBOX_ADDR   =   0x0040,   
   SMSAL_COM_PARA_ALL_CB_LANG    =   0x0080,
   SMSAL_COM_PARA_RESTORE_PROFILE=   0x0100,
   SMSAL_COM_PARA_MBI_NUM        =   0x0200
//   SMSAL_COM_PARA_SEL_MSP        =   0x0400
} smsal_common_para_enum;
#endif

/* follow +CGSMS command in 07.07 */
typedef enum
{   
   SMS_GPRS_ONLY = 0,
   SMS_GSM_ONLY,
   SMS_PREFER_GPRS,
   SMS_PREFER_GSM,   
   NUM_OF_SMS_SERVICE_MODE
}sms_bearer_enum;

typedef enum
{
   /* follows intended for AT commands and MMI */
   SMSAL_REC_UNREAD = 0,         /* received unread */
   SMSAL_REC_READ,               /* received read */
   SMSAL_STO_UNSENT,             /* stored unsent */
   SMSAL_STO_SENT,               /* stored sent */
   
   SMSAL_ALL,                    /* all (only applicable to +CMGL command) 
                                  * not for MMI
                                  */

   /* follows intended for MMI only */   
   SMSAL_INBOX_PARTIAL,          /* parts of inbox messages */
   SMSAL_OUTBOX_PARTIAL,         /* parts of outbox messages */
   SMSAL_STO_DRAFT,              /* stored draft */
   SMSAL_INVALID_STATUS
} smsal_status_enum;

/* for +EQSI proprietary command */
typedef enum
{
    RMMI_SMSAL_SM = 0,
    RMMI_SMSAL_ME = 1,
    RMMI_SMSAL_MT = 2 
} rmmi_smsal_storage_enum;

/* SMS PART END */

typedef enum
{
    SCRI_REQ_SENT = 0,
    SCRI_CS_SESSION_ONGOING = 1,
    SCRI_PS_SIGNALLING_ONGOING = 2,
    SCRI_NO_PS_DATA_SESSION = 3,
    SCRI_REQ_NOT_SENT = 4,
    SCRI_NOT_ALLOWED = 5
} end_session_result_enum;

/* mtk03643 : cipher icon share between mmi & mm */
typedef enum {
    GMMREG_CIPHER_OFF,
	GMMREG_CIPHER_ON,
	GMMREG_CIPHER_INVALID=0xff
} gmmreg_cipher_ind_enum; /* ripple: cipher ind */


#ifdef __GEMINI__
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

typedef enum
{
    PHB_APPROVE_FORMAT_FAIL = 0,
    PHB_APPROVE_PHB_NOT_READY,
    /* for backward compatible to PHB_CAUSE_FDN_BLOCKED */
    PHB_APPROVE_FDN_BLOCKED = 2600
} phb_approve_cause_enum;


typedef enum
{
    ESDP_CATEGORY_WALLPAPER = 0,
    ESDP_CATEGORY_RINGTONE,//currently disabled
    ESDP_CATEGORY_HOMECITY,
    ESDP_CATEGORY_THEME,
    ESDP_CATEGORY_SHORTCUT,
    ESDP_CATEGORY_SCREENSAVER,
    ESDP_CATEGORY_PWRONDISPLAY,
    ESDP_CATEGORY_PWROFFDISPLAY,
    ESDP_CATEGORY_MAX = ESDP_CATEGORY_PWROFFDISPLAY
}esdp_category_enum;

typedef enum
{
   TYPE_NO_REQUIRED,
   TYPE_PHONELOCK,
   TYPE_CHV1,
   TYPE_CHV2,
   TYPE_UBCHV1,
   TYPE_UBCHV2,
   TYPE_NP,
   TYPE_NSP,
   TYPE_SP,
   TYPE_CP,
   TYPE_IMSI_LOCK,
   TYPE_PERSONALIZATION_KEY,
   TYPE_CHV1_BLOCKED,
   TYPE_CHV2_BLOCKED,
   TYPE_SIM_CARD_BLOCKED,
   TYPE_UBCHV2_BLOCKED,
   TYPE_UBCHV1_CHV1_NOT_LOCK,
   TYPE_LINK_NS_SP,
   TYPE_LINK_SIM_C,
   TYPE_UNSPECIFIED,
   TYPE_UNEXPECTED_ERROR //Kinki: for stress test [MAUI_00859767]
}smu_security_type_enum;

//Kinki: MAUI_00632199
typedef enum
{
   SMU_SIM_NOT_READY,    //default value
   SMU_SIM_NO_IMSI,         //if no IMSI will be got in this power-on sesssion (etc.  no SIM, block SIM, IMSI can't be got.)
   SMU_SIM_REPLACED,       //IMSI is read and doesn't match with the previous IMSI.
   SMU_SIM_NOT_REPLACED //IMSI is read and the same as the previous one.
}smu_sim_status_enum;

typedef enum
{
   SMU_ADD_PLMNSEL,
   SMU_REMOVE_PLMNSEL,
   SMU_REPLACE_PLMNSEL,
   SMU_INSERT_EMPTY   //Benson 20040407 add for AT+COPS
}smu_plmnsel_op_enum;

//Kinki add for MAUI_00632199
#ifdef __GEMINI__
/* under construction !*/
#else
extern smu_sim_status_enum check_sim_status(void);
#endif

/*--- SML related enum ---*/

typedef enum {
    SML_STATE_NULL,
    SML_STATE_LOCK,
    SML_STATE_UNLOCK,
    SML_STATE_AUTOLOCK,
    SML_STATE_DISABLE	
} sml_state_enum;

typedef enum {
    SML_KEY_EMPTY,
    SML_KEY_SET
} sml_key_state_enum;

typedef enum {
    SML_OP_UNLOCK,
    SML_OP_LOCK,
    SML_OP_ADD,
    SML_OP_REMOVE,
    SML_OP_DISABLE
} sml_op_enum;

typedef enum {
    SML_CAT_N,
    SML_CAT_NS,
    SML_CAT_SP,
    SML_CAT_C,
    SML_CAT_SIM,
    SML_CAT_NS_SP,
    SML_CAT_SIM_C,
    SML_CAT_SIZE
} sml_cat_enum;

typedef enum {
    SML_MAGIC_HEAD,
    SML_MAGIC_TAIL,
    SML_CAT_META,
    SML_CAT_KEY,
    SML_CAT_CODE,
    SML_CAT_RANGE    
} sml_ctx_enum;

typedef enum
{
    RAC_DETACH,
    RAC_ATTACH
} l4crac_ps_attach_enum;

typedef enum
{
    RAC_CS = 1,
    RAC_PS = 2,
    RAC_CS_AND_PS = 3
} l4crac_attach_type_enum;

typedef enum
{
   L4C_RAC_OK,
   L4C_RAC_NO_CELL,
   L4C_RAC_LIMITED_SERVICE,
   L4C_RAC_ERROR,
   L4C_RAC_INVALID_SIM,
   L4C_RAC_ATTEMPT_TO_UPDATE,
   L4C_RAC_SEARCHING, /* Johnny 2005/11/07: add new temp gsm_status for MMI: L4C_RAC_SEARCHING */
   L4C_RAC_NULL
} l4c_rac_response_enum;

#ifdef __MONITOR_PAGE_DURING_TRANSFER__
typedef enum
{
   DATA_PREFER, // default value
   CALL_PREFER,
   AS_OPTIMAL   // decided by AS
} gprs_transfer_preference_enum;
#endif //__MONITOR_PAGE_DURING_TRANSFER__

typedef enum
{
	L4C_APPLY_AT_RUNTIME = 0,
    L4C_APPLY_AFTER_REBOOT,
    L4C_APPLY_INVALID
} l4c_hspa_mode_apply_enum;

typedef enum 
{
	L4C_HSPA_OFF,
	L4C_HSDPA_ON,
	L4C_HSDPA_HSUPA_ON,
	L4C_HSPA_INVLIAD
} l4c_hspa_preference_enum; // it shall be sync to hspa_preference_enum
// --- mtk02285, hspa_mmi 

typedef enum
{
    MANUAL_MODE    = 0,
    AUTOMATIC_MODE = 1
} plmn_selection_mode_enum;

 typedef enum {
   PHB_NORMAL_NUM = 129,
   PHB_INTER_NUM = 145,
   PHB_UNKNOW = 255
} phb_ton_enum;

/******************************
*******RMMI related ENUM BEGIN*****
*******************************/
typedef enum
{
    RMMI_PLMN_LONG_ALPHA,
    RMMI_PLMN_SHORT_ALPHA,
    RMMI_PLMN_NUMERIC
} rmmi_plmn_format_enum;

typedef enum
{
    RMMI_DISABLE_REPORT = 0,
    RMMI_ENABLE_REPORT
} rmmi_report_mode_enum;

typedef enum
{
    RMMI_DISABLE_NW_REG_REPORT,
    RMMI_ENABLE_NW_REG_REPORT,
    RMMI_ENABLE_LOC_REPORT,
    RMMI_ENABLE_LOC_AND_CAUSE_REPORT,
} rmmi_nw_reg_report_mode_enum;

typedef enum
{
    RMMI_NUM_PARTIAL_HEAD_TAIL,
    RMMI_VERBOSE_FULL_HEAD_TAIL
} rmmi_result_code_format;

typedef enum
{
    RMMI_SUPPRESS_OFF,
    RMMI_SUPRESS_ON
} rmmi_result_code_suppress_enum;

typedef enum
{
    RMMI_SIMPLE_ERROR,
    RMMI_NUMERIC_ERROR,
    RMMI_TEXT_ERROR
} rmmi_error_report_mode_enum;

typedef enum
{
    RMMI_CHSET_IRA,
    RMMI_CHSET_HEX,
    RMMI_CHSET_GSM,
    RMMI_CHSET_PCCP437,
    RMMI_CHSET_PCDN,
    RMMI_CHSET_88591,
    RMMI_CHSET_UCS2,
#ifdef __PHB_0x81_SUPPORT__
    RMMI_CHSET_UCS2_0X81,
#endif 
    RMMI_CHSET_TOTAL_NUM
} rmmi_chset_enum;

typedef enum
{
    RMMI_UART_TO_SIM1,
    RMMI_UART_TO_SIM2,
    RMMI_UART_TO_SIM3,
    RMMI_UART_TO_SIM4,
    RMMI_SIM_UART_SETTING_NONE = 0xFF
}rmmi_sim_uart_setting_enum;


/******************************
*******RMMI related ENUM END*******
*******************************/

typedef enum
{
    L4C_UART_TO_SIM1,
    L4C_UART_TO_SIM2,
    L4C_UART_TO_SIM3,
    L4C_UART_TO_SIM4,
    L4C_DUAL_SIM_UART_SETTING_NONE = 0xFF
}l4c_dual_sim_uart_setting_enum;

typedef enum
{
    L4C_SETTING_FLIGHT_MODE,
    L4C_SETTING_WLAN_FLIGHT_MODE,    
    L4C_SETTING_DUAL_SIM_MODE,
    L4C_SETTING_DUAL_SIM_UART,
    L4C_SETTING_3G_SERVICE_BITMAP,
    L4C_SETTING_MAX
}l4c_nvram_setting_enum;

typedef enum
{
   MT_CALL_ALLOW,
   MT_CALL_REJECT,
   MT_CALL_APPROVAL_ENABLE,
   MT_CALL_APPROVAL_DISABLE
}l4c_mt_call_approval_enum;

typedef enum
{
   ALS_DIAL_BY_SETTING, //dial call according to the ALS setting in NVRAM
   ALS_DIAL_LINE1,
   ALS_DIAL_LINE2   	   
}l4c_als_dial_type_enum;

typedef enum
{
   INFO_ECC_CHECK_BY_MODEM, //let modem check if dialed number is ECC (it's current MAUI solution default value)
   INFO_ECC_CALL,  //inform the dialed number is a ECC call
   INFO_NORMAL_CALL,  //inform the dialed number is a normal call
   //kc1111
   INFO_ECALL_START,
   INFO_ECALL_TEST = 0x00 + INFO_ECALL_START, //inform the dialed number is a test Ecall
   INFO_ECALL_RECONFIGURATION = 0x01 + INFO_ECALL_START, //inform the dialed number is a reconfiguration Ecall
   INFO_ECALL_MANUALLY_INITIATED = 0x02 + INFO_ECALL_START,  //inform the dialed number is a manually Ecall
   INFO_ECALL_AUTOMATICALLY_INITIATED = 0x03 + INFO_ECALL_START  //inform the dialed number is a automatically Ecall
}l4c_mmi_ecc_info_enum;

typedef enum
{
   SINGLE_VOICE_CALL,
   SINGLE_DATA_CALL,
   SINGLE_FAX_CALL,
   FOLLOW_VOICE_CALL,
   ALT_DATA_VOICE_CALL,
   ALT_FAX_VOICE_CALL,
   FOLLOW_DATA_CALL,
   ALT_DATA_DATA_CALL,
   ALT_FAX_FAX_CALL,
   UNKNOWN_CALL
} l4ccsm_cc_call_mode_enum;

// mtk02285, hspa_mmi ---
typedef enum
{
    L4C_NONE_SPECIFIED = 0x00,
    L4C_GPRS_SUPPORT = 0x01,
    L4C_EDGE_SUPPORT = 0x02,
    L4C_UMTS_SUPPORT = 0x04,
    L4C_HSDPA_SUPPORT = 0x08,
    L4C_HSUPA_SUPPORT = 0x10,
    L4C_HSDPA_UPA_SUPPORT = 0x18,
    L4C_NOT_CHANGE = 0xff  
} l4c_data_speed_support_enum; // it shall be sync to data_speed_support_enum

typedef enum
{
    L4C_NONE_ACTIVATE = 0,
    L4C_GPRS_CAPABILITY,
    L4C_EDGE_CAPABILITY,
    L4C_UMTS_CAPABILITY,
    L4C_HSDPA_CAPABILITY,           //mac-hs
    L4C_HSUPA_CAPABILITY,           //mac-e/es
    L4C_HSDPA_HSUPA_CAPABILITY,     //mac-hs + mac-e/es

    L4C_HSDPAP_CAPABILITY,          //mac-ehs
    L4C_HSDPAP_UPA_CAPABILITY,      //mac-ehs + mac-e/es
    L4C_HSUPAP_CAPABILITY,          //mac-i/is
    L4C_HSUPAP_DPA_CAPABILITY,      //mac-hs + mac-i/is
    L4C_HSPAP_CAPABILITY,           //mac-ehs + mac-i/is
    L4C_DC_DPA_CAPABILITY,          //(DC) mac-hs
    L4C_DC_DPA_UPA_CAPABILITY,      //(DC) mac-hs + mac-e/es
    L4C_DC_HSDPAP_CAPABILITY,       //(DC) mac-ehs
    L4C_DC_HSDPAP_UPA_CAPABILITY,   //(DC) mac-ehs + mac-e/es
    L4C_DC_HSUPAP_DPA_CAPABILITY,   //(DC) mac-hs + mac-i/is
    L4C_DC_HSPAP_CAPABILITY,        //(DC) mac-ehs + mac-i/is
    L4C_LTE_CAPABILITY
} l4c_data_bearer_capablility_enum;


#if defined(__BT_SUPPORT__)
//defined later
typedef enum
{
    RMMI_CIND_BEGIN = 0,
    RMMI_CIND_SERVICE,
    RMMI_CIND_CALL,
    RMMI_CIND_CALLSETUP,
    RMMI_CIND_CALLHELD,
    RMMI_CIND_BATTCHG,
    RMMI_CIND_SIGNAL,
    RMMI_CIND_ROAM,
    RMMI_CIND_END
} rmmi_cind_enum;
#else /* defined(__BT_SUPPORT__) */ 
typedef enum
{
    RMMI_CIND_BEGIN = 0,
    RMMI_CIND_BATTCHG,
    RMMI_CIND_SIGNAL,
    RMMI_CIND_SERVICE,
    RMMI_CIND_MESSAGE,
    RMMI_CIND_CALL,
    RMMI_CIND_ROAM,
    RMMI_CIND_SMSMEMSTATUS,
    RMMI_CIND_CALLSETUP,
    RMMI_CIND_END
} rmmi_cind_enum;
#endif /* defined(__BT_SUPPORT__) */ 

typedef enum
{
    RMMI_CIND_CC_NONE = 0,
    RMMI_CIND_CC_ACTIVE = 1
} rmmi_cind_call;

typedef enum
{
    RMMI_CIND_CSUP_NONE = 0,
    RMMI_CIND_CSUP_INCOMING,
    RMMI_CIND_CSUP_OUTGOING,
    RMMI_CIND_CSUP_ALERT,
    RMMI_CIND_CSU_PEND
} rmmi_cind_callsetup;

typedef enum
{
    RMMI_CIND_HELD_NONE = 0,
    RMMI_CIND_HELD_ACTIVE_HOLD = 1,
    RMMI_CIND_HELD_HOLD = 2
} rmmi_cind_callheld;

typedef enum
{
    NW_BAND_PGSM900 = 0x01,
    NW_BAND_EGSM900 = 0x02,
    NW_BAND_RGSM900 = 0x04,
    NW_BAND_DCS1800 = 0x08,
    NW_BAND_PCS1900 = 0x10,
    NW_BAND_GSM450 = 0x20,
    NW_BAND_GSM480 = 0x40,
    NW_BAND_GSM850 = 0x80
} l4c_nw_band_enum;

typedef enum {
/* ============================== CM cause ============================== */	
   CM_RADIO_LINK_FAIL = 0, /* Ripple: add for SAT3 use. sec 11.3.2, spec.. 11.14 */
// 3GPP 24.008 clause 10.5.4.11(Annex H) CC+SS cause value
// 3GPP 24.011 clause 8.2.5.4 SMS RP cause value
// 3GPP 24.011 clause 8.1.4.2 SMS CP cause value
// Class(000): 0-15 -> normal event             CC+SS    SMS
   CM_UNASSIGNED_NUM                     = 1,  // X       X
   CM_NO_ROUTE_TO_DESTINATION            = 3,  // X
   CM_CHANNEL_UN_ACCP                    = 6,  // X
   CM_OPR_DTR_BARRING                    = 8,  // X       X
   CM_CALL_BARRED                        = 10, //         X
   CM_RESERVED                           = 11, //         X
// Class(001): 16-31 -> normal event
   CM_NORMAL_CALL_CLR                    = 16, // X
   CM_USER_BUSY                          = 17, // X       X! (SMS: nwk failure)
   CM_NO_USER_RESPONDING                 = 18, // X
   CM_NO_ANSWER_ON_ALERT                 = 19, // X
   CM_CALL_REJECTED                      = 21, // X       X
   CM_NUMBER_CHANGED                     = 22, // X       X! (SMS: congestion)
   CM_PRE_EMPTION                        = 25, // X
   CM_NON_SEL_USER_CLEAR                 = 26, // X
   CM_DEST_OUT_OF_ORDER                  = 27, // X       X
   CM_INVALID_NUMBER_FORMAT              = 28, // X       X
   CM_FACILITY_REJECT                    = 29, // X       X
   CM_RES_STATUS_ENQ                     = 30, // X       X! (SMS:Unknown_Sub)
   CM_NORMAL_UNSPECIFIED                 = 31, // X
// Class(010): 32-48 -> resource unavailable
   CM_NO_CIRCUIT_CHANNEL_AVAIL           = 34, // X
   CM_NETWORK_OUT_OF_ORDER               = 38, // X       X
   CM_TEMPORARY_FAILURE                  = 41, // X       X
   CM_SWITCH_EQUIPMENT_CONGESTION        = 42, // X       X
   CM_ACCESS_INFO_DISCARDED              = 43, // X
   CM_REQUESTED_CKT_CHANEL_NOT_AVIL      = 44, // X
   CM_RESOURCE_UNAVAIL_UNSPECIFIED       = 47, // X       X
// Class(011): 49-64 -> service or option not available
   CM_QOS_UNAVAIL                        = 49, // X
   CM_REQ_FAC_NOT_SUBS                   = 50, // X       X
   CM_IC_BAR_CUG                         = 55, // X
   CM_BEARER_CAP_NOT_AUTHORISED          = 57, // X
   CM_BEARER_CAP_NOT_AVAIL               = 58, // X
   CM_SER_UNAVAILABLE                    = 63, // X
// Class(100): 65-80 -> service or option not implementated
   CM_BEARER_SER_UNIMPL                  = 65, // X
   CM_ACM_EXCEEDED                       = 68, // X
   CM_REQ_FACILITY_UNAVAIL               = 69, // X       X
   CM_RESTR_DIGITAL_INFO                 = 70, // X
   CM_SER_OPT_UNIMPL                     = 79, // X
// Class(101): 81-95 -> invalid message
   CM_INVALID_TI_VALUE                   = 81, // X       X
   CM_USER_NOT_IN_CUG                    = 87, // X
   CM_INCOMPATIBLE_DEST                  = 88, // X
   CM_INVALID_TRANSIT_NW_SEL             = 91, // X
   CM_SEMANTIC_ERR                       = 95, // X       X
// Class(110): 96-112 -> protocol error
   CM_INVALID_MANDATORY_INF              = 96, // X       X
   CM_MSG_TYPE_UNIMPL                    = 97, // X       X
   CM_MSG_TYPE_NOT_COMPATIBLE            = 98, // X       X
   CM_IE_NON_EX                          = 99, // X       X
   CM_COND_IE_ERR                       = 100, // X
   CM_INCOMP_MESG_WITH_STATE            = 101, // X
   CM_RECOVERY_ON_TIMER_EXPIRY          = 102, // X
   CM_PROTOCOL_ERR_UNSPECIFIED          = 111, // X       X
// Class(111): 113-127 -> interworking
   CM_INTER_WRK_UNSPECIFIED             = 127, // X       X
/* ============================== ~CM cause ============================== */

/* ============================== SMS cause ============================== */
// 3GPP 23.040 clause 9.2.3.22 SMS TP cause values
// 128-255 -> SMS cause value
      
   /* PID error */   
   TELEMATIC_INT_WRK_NOT_SUPPORT = 0x80, /* telematic interworking not support */
   SMS_TYPE0_NOT_SUPPORT         = 0x81, /* short message type 0 not support */
   CANNOT_REPLACE_MSG            = 0x82, 
   UNSPECIFIED_PID_ERROR         = 0x8F, 
   
   /* DCS error */
   ALPHABET_NOT_SUPPORT          = 0x90, /* data coding scheme (alphabet) not support */
   MSG_CLASS_NOT_SUPPORT         = 0x91, /* message class not support */
   UNSPECIFIED_TP_DCS            = 0x9f,

   /* Command error */
   CMD_CANNOT_ACTION             = 0xa0, /* command cannot be actioned */
   CMD_NOT_SUPPORT               = 0xa1, /* command unsupported */
   UNSPECIFIED_CMD_ERROR         = 0xaf, 
   
   TPDU_NOT_SUPPORT              = 0xb0,   
   SC_BUSY                       = 0xc0,
   NO_SC_SUBSCRIPTION            = 0xc1,
   SC_SYS_FAILURE                = 0xc2,  /* SC system failure */
   INVALID_SME_ADDR              = 0xc3,  
   DEST_SME_BARRED               = 0xc4,  /* destination SME barred */
   SM_REJ_DUP_SM                 = 0xc5,  /* SM rejected-duplicate SM */
   TP_VPF_NOT_SUPPORT            = 0xc6,
   TP_VP_NOT_SUPPORT             = 0xc7,
      
   SIM_STORAGE_FULL              = 0xd0,
   NO_SMS_STO_IN_SIM             = 0xd1,  /* No SMS storage capability in SIM */
   ERROR_IN_MS                   = 0xd2, 
   MEM_CAP_EXCEEDED              = 0xd3,  /* Memory Capacity Exceeded */
   
   /* SIM Application Toolkit */
   SMS_SAT_BUSY                  = 0xd4,  /* SIM Application Toolkit Busy */
   SMS_SAT_DL_ERROR              = 0xd5,  /* SIM data download error */
   
   /* 0XE0 to 0xFE are specific to application */
   SMS_CP_RETRY_EXCEED           = 0xe0,
   SMS_RP_TR1M_TIMEOUT           = 0xe1,
   SMS_CONNECTION_BROKEN         = 0xe2,
   
   UNSPECIFIED_TP_FCS            = 0xff,

// 3GPP 27.005 clause 3.2.5 SMS ATcmd cause values
// 256-511 -> SMS AT command cause value
   INVALID_PDU_MODE_PARA  = 304,   /* invalid pdu mode parameter */
   INVALID_TEXT_MODE_PARA = 305,   /* invalid text mode parameter */
   SMS_SIM_FAILURE        = 313,   /* sim failure */
   MEM_FAILURE	          = 320,   /* memory failure */
   INVALID_MEM_INDEX	  = 321,   /* invalid memory index */
   MEM_FULL	          = 322,   /* memory full */
   SCA_UNKNOWN	          = 330,   /* SMSC address unknown */
   NO_CNMA_EXPECTED       = 340,   /* no +CNMA acknowledgement expected */
   SMSAL_UNSPECIFIED_ERROR_CAUSE = 500,
   
// 512-767 -> SMS proprietary cause values
   SMSAL_NO_ERROR             = 512,
   MSG_LEN_EXCEEDED           = 513,   /* message length exceeds 
                                          maximum length */
   INVALID_REQ_PARAMETER      = 514,   /* invalid request parameters */
   SMS_ME_STORAGE_FAILURE     = 515,   /* ME storage failure */
   SMSAL_INVALID_BEARER       = 516,   /* Invalid bearer service */
   SMSAL_INVALID_SERVICE_MODE = 517,   /* Invalid service mode */
   SMSAL_INVALID_STORAGE_TYPE = 518,   /* Invalid storage type */
   SMSAL_INVALID_MSG_FORMAT   = 519,   /* Invalid message format */
   TOO_MANY_MO_CONCAT_MSG     = 520,   /* Too many MO concatenated messages */
   SMSAL_NOT_READY            = 521,
   SMSAL_NO_MO_SERVICE        = 522,
   NOT_SUPP_SR_CMD_IN_STORAGE = 523,   /* not support TP-Status-Report & TP-Command in storage */   
   SMSAL_NOT_SUPPORT_MSG_TYPE = 524,   /* Reserved MTI */
   SMS_RL_NO_FREE_ENTITY      = 525,   /* no free entity in RL layer */
   SMS_PORT_NUM_ALREADY_REG   = 526,   /* The port number is already registerred */
   SMS_PORT_NUM_NO_FREE_ENTITY= 527,   /* There is no free entity for port number */
   SMS_RL_MMS_STATE_ERR       = 528,   /* More Message to Send state error */
   SMS_MO_SMS_NOT_ALLOW       = 529,   /* MO SMS is not allow */
   SMS_PS_SUSPENDED           = 530,   /* GPRS is suspended */
   SMS_ME_STORAGE_FULL        = 531,   /* ME storage full */
   SMS_SIM_REFRESHING         = 532,   /* doing SIM refresh */
/* ============================== ~SMS cause ============================== */
   
/* ============================== CC cause ============================== */   
// 768-1023 -> CC proprietary cause values
	CSMCC_CMD_NOT_ALLOW = 768,
	CSMCC_ILLEGAL_CALL_ID,
	CSMCC_CALL_ALLOC_FAIL,
	CSMCC_BC_FILL_FAIL,
	CSMCC_CALL_RE_EST,
	CSMCC_ILLEGAL_DTMF_TONE,
	CSMCC_ILLEGAL_BC,
	CSMCC_MODIFY_ACTUAL_MODE,   
	CSMCC_DATA_ACT_FAIL,
	CSMCC_NO_RESPONSE_FROM_NW,
	CSMCC_CALL_ACCEPT_NOT_ALLOW,
        CSMCC_SAT_CALL_CTRL_REJECTED, /* call rejected by SAT call control: added for MAUI_01300426 */
        CSMCC_VT_NO_UMTS_CAPABILITY,  /*[MAUI_01712442]*/
    
   CM_L4C_GEN_CAUSE = 896,
   CM_L4C_CC_CALL_ABORT = 897,  /*CSD call is aborted by user during call establishment
   				or MT call abort MO call/USSD*/
   CM_L4C_CC_CALL_DISC_IND = 898,  /*CSD call is disconnected due to lower layer failure*/
/* ============================== ~CC cause ============================== */
   
/* ============================== SS cause ============================== */   
// 1024-1279 -> SS proprietary cause values
// 3GPP 23.080 clause 4.3 SS Error Types
   CM_SS_ERR_START                                = 1024,
   CM_SS_ERR_UNKNOWNSUBSCRIBER                    =   1 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALSUBSCRIBER                    =   9 + CM_SS_ERR_START,
   CM_SS_ERR_BEARERSERVICENOTPROVISIONED          =  10 + CM_SS_ERR_START,
   CM_SS_ERR_TELESERVICENOTPROVISIONED            =  11 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALEQUIPMENT                     =  12 + CM_SS_ERR_START,
   CM_SS_ERR_CALLBARRED                           =  13 + CM_SS_ERR_START,
   CM_SS_ERR_ILLEGALSS_OPERATION                  =  16 + CM_SS_ERR_START,
   CM_SS_ERR_SS_ERRORSTATUS                       =  17 + CM_SS_ERR_START,
   CM_SS_ERR_SS_NOTAVAILABLE                      =  18 + CM_SS_ERR_START,
   CM_SS_ERR_SS_SUBSCRIPTIONVIOLATION             =  19 + CM_SS_ERR_START,
   CM_SS_ERR_SS_INCOMPABILITY                     =  20 + CM_SS_ERR_START,
   CM_SS_ERR_FACILITYNOTSUPPORTED                 =  21 + CM_SS_ERR_START,
   CM_SS_ERR_ABSENTSUBSCRIBER                     =  27 + CM_SS_ERR_START,
   CM_SS_ERR_SHORTTERMDENIAL                      =  29 + CM_SS_ERR_START,
   CM_SS_ERR_LONGTERMDENIAL                       =  30 + CM_SS_ERR_START,
   CM_SS_ERR_SYSTEMFAILURE                        =  34 + CM_SS_ERR_START,
   CM_SS_ERR_DATAMISSING                          =  35 + CM_SS_ERR_START,
   CM_SS_ERR_UNEXPECTEDDATAVALUE                  =  36 + CM_SS_ERR_START,
   CM_SS_ERR_PW_REGISTRATIONFAILURE               =  37 + CM_SS_ERR_START,
   CM_SS_ERR_NEGATIVEPW_CHECK                     =  38 + CM_SS_ERR_START,
   CM_SS_ERR_NUMBEROFPW_ATTEMPTSVIOLATION         =  43 + CM_SS_ERR_START,
   CM_SS_ERR_POSITIONMETHODFAILURE                =  54 + CM_SS_ERR_START,
   CM_SS_ERR_UNKNOWNALPHABET                      =  71 + CM_SS_ERR_START,
   CM_SS_ERR_USSD_BUSY                            =  72 + CM_SS_ERR_START,
   CM_SS_ERR_REJECTEDBYUSER                       = 121 + CM_SS_ERR_START,
   CM_SS_ERR_REJECTEDBYNETWORK                    = 122 + CM_SS_ERR_START,
   CM_SS_ERR_DEFLECTIONTOSERVEDSUBSCRIBER         = 123 + CM_SS_ERR_START,
   CM_SS_ERR_SPECIALSERVICECODE                   = 124 + CM_SS_ERR_START,
   CM_SS_ERR_INVALIDDEFLECTIONTONUMBER            = 125 + CM_SS_ERR_START,
   CM_SS_ERR_MAXNUMBEROFMPTY_PARTICIPANTSEXCEEDED = 126 + CM_SS_ERR_START,
   CM_SS_ERR_RESOURCESNOTAVAILABLE                = 127 + CM_SS_ERR_START,

   CM_SS_GENERALPROBLEM_START                     = 1152,
   CM_SS_GENERALPROBLEM_UNRECOGNIZEDCOMPONENT     =       CM_SS_GENERALPROBLEM_START,
   CM_SS_GENERALPROBLEM_MISTYPEDCOMPONENT         = 1   + CM_SS_GENERALPROBLEM_START,
   CM_SS_GENERALPROBLEM_BADLYSTRUCTUREDCOMPONENT  = 2   + CM_SS_GENERALPROBLEM_START,

   CM_SS_INVOKEPROBLEM_START                      = 1155,
   CM_SS_INVOKEPROBLEM_DUPLICATEINVOKEID          =       CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNRECOGNIZEDOPERATION      = 1  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_MISTYPEDPARAMETER          = 2  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_RESOURCELIMITATION         = 3  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_INITIATINGRELEASE          = 4  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNRECOGNIZEDLINKDID        = 5  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_LINKEDRESONSEUNEXPECTED    = 6  +  CM_SS_INVOKEPROBLEM_START,
   CM_SS_INVOKEPROBLEM_UNEXPECTEDLINKEDOPERATION  = 7  +  CM_SS_INVOKEPROBLEM_START,

   CM_SS_RETURNRESULTPROBLEM_START                     = 1163,
   CM_SS_RETURNRESULTPROBLEM_RR_UNRECOGNIZEDINVOKEID   =      CM_SS_RETURNRESULTPROBLEM_START,
   CM_SS_RETURNRESULTPROBLEM_RR_RETURNRESULTUNEXPECTED = 1 +  CM_SS_RETURNRESULTPROBLEM_START,
   CM_SS_RETURNRESULTPROBLEM_RR_MISTYPEDPARAMETER      = 2 +  CM_SS_RETURNRESULTPROBLEM_START,

   CM_SS_RETURNERRORPROBLEM_START                      = 1166,
   CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDINVOKEID    =      CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_RETURNERRORUNEXPECTED   = 1 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_UNRECOGNIZEDERROR       = 2 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_UNEXPECTEDERROR         = 3 +  CM_SS_RETURNERRORPROBLEM_START,
   CM_SS_RETURNERRORPROBLEM_RE_MISTYPEDPARAMETER       = 4 +  CM_SS_RETURNERRORPROBLEM_START,
/* ============================== ~SS cause ============================== */

/* ============================== MM cause ============================== */
// 3GPP 24.008 clause 10.5.3.6(Annex G) MM reject cause values
// 3GPP 24.008 clause 10.5.5.14(Annex G) GMM cause values
// 2048 -> MM cause values
   CM_MM_CAUSE_START                     = 2048,
   CM_MM_CAUSE_NONE                     =     0x00 + CM_MM_CAUSE_START,
   CM_MM_IMSI_UNKNOWN_IN_HLR            =     0x02 + CM_MM_CAUSE_START,
   CM_MM_ILLEGAL_MS                     =     0x03 + CM_MM_CAUSE_START,
   CM_MM_IMSI_UNKNOWN_IN_VLR            =     0x04 + CM_MM_CAUSE_START,
   CM_MM_IMEI_NOT_ACCEPTED              =     0x05 + CM_MM_CAUSE_START,
   CM_MM_ILLEGAL_ME                     =     0x06 + CM_MM_CAUSE_START,
   CM_MM_GPRS_NOT_ALLOWED               =     0x07 + CM_MM_CAUSE_START,
   CM_MM_GPRS_NON_GPRS_NOT_ALLOWED      =     0x08 + CM_MM_CAUSE_START,
   CM_MM_MS_ID_NOT_DERIVED_BY_NW        =     0x09 + CM_MM_CAUSE_START,
   CM_MM_IMPLICIT_DETACH                =     0x0a + CM_MM_CAUSE_START,
   CM_MM_PLMN_NOT_ALLOWED               =     0x0b + CM_MM_CAUSE_START,
   CM_MM_LOCATION_AREA_NOT_ALLOWED      =     0x0c + CM_MM_CAUSE_START,
   CM_MM_ROAMING_AREA_NOT_ALLOWED       =     0x0d + CM_MM_CAUSE_START,
   CM_MM_GPRS_NOT_ALLOWED_IN_PLMN       =     0x0e + CM_MM_CAUSE_START,
   CM_MM_NO_SUITABLE_CELLS_IN_LA        =     0x0f + CM_MM_CAUSE_START,
   CM_MM_MSC_TEMP_NOT_REACHABLE         =     0x10 + CM_MM_CAUSE_START,
   CM_MM_NETWORK_FAILURE                =     0x11 + CM_MM_CAUSE_START,
   CM_MM_MAC_FAILURE                    =     0x14 + CM_MM_CAUSE_START,
   CM_MM_SYNC_FAILURE                   =     0x15 + CM_MM_CAUSE_START,
   CM_MM_CONGESTION                     =     0x16 + CM_MM_CAUSE_START,
   CM_MM_SERV_OPTION_NOT_SUPPORTED      =     0x20 + CM_MM_CAUSE_START,
   CM_MM_REQ_SERV_OPTION_NOT_SUBSCRIBED =     0x21 + CM_MM_CAUSE_START,
   CM_MM_SERV_OPTION_TEMP_OUT_OF_ORDER  =     0x22 + CM_MM_CAUSE_START,
   CM_MM_CALL_CANNOT_BE_IDENTIFIED      =     0x26 + CM_MM_CAUSE_START,
   CM_MM_NO_PDP_CONTEXT_ACTIVATED       =     0x28 + CM_MM_CAUSE_START,
   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MIN =  0x30 + CM_MM_CAUSE_START,  /* 30..3f */
   CM_MM_RETRY_UPON_ENTRY_INTO_NEWCELL_MAX =  0x3f + CM_MM_CAUSE_START,
   CM_MM_SEMANTICALLY_INCORRECT_MSG        =  0x5f + CM_MM_CAUSE_START,
   CM_MM_INVALID_MM_MAND_INFO              =  0x60 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_NON_EXISTENT             =  0x61 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_NOT_IMPLEMENTED          =  0x61 + CM_MM_CAUSE_START,
   CM_MM_MSG_TYPE_INCOMPAT_WITH_PROTO_STATE = 0x62 + CM_MM_CAUSE_START,
   CM_MM_IE_NOT_IMPLEMENTED                 = 0x63 + CM_MM_CAUSE_START,
   CM_MM_CONDITIONAL_MM_IE_ERROR            = 0x64 + CM_MM_CAUSE_START,
   CM_MM_MSG_NOT_COMPAT_WITH_PROTO_STATE    = 0x65 + CM_MM_CAUSE_START,  /* 65..6f */
   CM_MM_PROTO_ERROR_UNSPECIFIED            = 0x6f + CM_MM_CAUSE_START,

   /* RR connection establishment failure */
   CM_MM_ACCESS_BARRED  ,
   CM_MM_ASSIGNMENT_REJECT ,
   CM_MM_RANDOM_ACCES_FAILURE ,
   CM_MM_RR_NO_SERVICE ,
   CM_RR_PLMN_SRCH_REJ_EMERGENCY,   
   CM_MM_RR_CONN_RELEASE,

   /* other cause */
   CM_MM_AUTH_FAILURE,
   CM_MM_IMSI_DETACH,
   CM_MM_ABORT_BY_NW ,
   CM_MM_CONN_TIMEOUT,
   /* MM internal casuse */
   CM_MM_CM_ENQUEUE_FAIL,
   CM_MM_NOT_UPDATED ,
   CM_MM_STATE_NOT_ALLOWED_CM,
   CM_MM_EMERGENCY_NOT_ALLOWED,
   CM_MM_NO_SERVICE,
   CM_MM_ACCESS_CLASS_BARRED,
#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif
   CM_MM_CAUSE_END                       = 2048 + 256,
/* ============================== ~MM cause ============================== */

/* ============================== SIM cause ============================== */
   SIM_CAUSE_START                                     = 2560,
   SIM_CAUSE_CMD_SUCCESS                               =     SIM_CAUSE_START,
   SIM_CAUSE_CMD_FAIL                                  = 1 + SIM_CAUSE_START,
   SIM_CAUSE_FATAL_ERROR                               = 2 + SIM_CAUSE_START,
   SIM_CAUSE_NO_INSERTED                               = 3 + SIM_CAUSE_START,
   SIM_CAUSE_CHV_NOT_INIT                              = 4 + SIM_CAUSE_START,
   SIM_CAUSE_CHV_VERIFY_ERROR                          = 5 + SIM_CAUSE_START, /* SIM_CHV_RETRY_ALLOW */
   SIM_CAUSE_CHV_BLOCK                                 = 6 + SIM_CAUSE_START, /* SIM_CHV_BLOCK */
   SIM_CAUSE_ACCESS_NOT_ALLOW                          = 7 + SIM_CAUSE_START, /* */
   SIM_CAUSE_SAT_CMD_BUSY                              = 8 + SIM_CAUSE_START, /* */
   SIM_CAUSE_DL_ERROR                                  = 9 + SIM_CAUSE_START, /* */
   SIM_CAUSE_MEMORY_PROBLEM                            = 10 + SIM_CAUSE_START, /* */
   SIM_CAUSE_TECHNICAL_PROBLEM                         = 11 + SIM_CAUSE_START, /* */
   SIM_CAUSE_PUK_UNLOCK                                = 12 + SIM_CAUSE_START, /* add new enum value to 
                                                                               distinguish whether normal poweron or PUK-unlock-poweron */
   SIM_CAUSE_END,
/* ============================== ~SIM cause ============================== */

/* ============================== PHB cause ============================== */
   PHB_CAUSE_FDN_BLOCKED = 2600,
   PHB_L4C_ERROR = 2601,  /*called number is not approved by PHB*/
/* ============================== ~PHB cause ============================== */

/* ============================== SM cause ============================== */
// 3GPP 24.008 clause 10.5.6.6(Annex I) SM/LLC/SNDCP/PDP/GPRS cause values
// 3072 -> SM cause values

    SM_CAUSE_START                   = 3072,
    SM_CAUSE_EMPTY                   =   0x01 + SM_CAUSE_START, // there is no such cause in SM spec, just invent a default empty value for coding usage
    OPERATOR_DETERMINED_BARRING      =   0x08 + SM_CAUSE_START, //__REL4__
    LLC_SND_FAILURE                  =   0X19 + SM_CAUSE_START,
    INSUFF_RESOURCE                  =   0X1A + SM_CAUSE_START,
    UNKNOWN_APN                      =   0X1B + SM_CAUSE_START,
    UNKNOWN_PDP_ADDR_OR_TYPE         =   0X1C + SM_CAUSE_START,
    AUTHENTICATION_FAILURE           =   0X1D + SM_CAUSE_START,
    ACTIVATION_REJ_GGSN              =   0X1E + SM_CAUSE_START,
    ACTIVATION_REJ                   =   0X1F + SM_CAUSE_START,
    UNSUPPORTED_SERVICE_OPTION       =   0X20 + SM_CAUSE_START,
    UNSUBSCRIBED_SERVICE_OPTION      =   0X21 + SM_CAUSE_START,
    OUT_OF_ORDER_SERVICE_OPTION      =   0X22 + SM_CAUSE_START,
    REGULAR_DEACTIVATION             =   0X24 + SM_CAUSE_START,
    QOS_NOT_ACCEPTED                 =   0X25 + SM_CAUSE_START,
    NETWORK_FAIL                     =   0X26 + SM_CAUSE_START,
    REACTIVATION_REQD                =   0X27 + SM_CAUSE_START,
    UNSUPPORTED_NW_CONTEXT_ACTIVATION=   0X28 + SM_CAUSE_START, /* Came and went from 4.08 + SM_CAUSE_START,
                                                  should this be removed? */
    SEMANTIC_ERROR_IN_TFT_OP         =   0X29 + SM_CAUSE_START,
    SYNTACTICAL_ERROR_IN_TFT_OP      =   0X2A + SM_CAUSE_START,
    UNKNOWN_PDP_CONTEXT              =   0X2B + SM_CAUSE_START,
    SEMANTIC_ERROR_IN_PACKET_FILTER  =   0X2C + SM_CAUSE_START,
    SYNTAX_ERROR_IN_PACKET_FILTER    =   0X2D + SM_CAUSE_START,
    PDP_CONTEXT_WO_TFT_ALREADY_ACT   =   0X2E + SM_CAUSE_START,
    ACTIVATION_REJ_BCM_VIOLATION     =   0X30 + SM_CAUSE_START, // __REL7__
    PDP_TYPE_IPV4_ONLY_ALLOWED       =   0X32 + SM_CAUSE_START, // __REL8__
    PDP_TYPE_IPV6_ONLY_ALLOWED       =   0X33 + SM_CAUSE_START, // __REL8__
    SINGLE_ADDR_BEARERS_ONLY_ALLOWED =   0X34 + SM_CAUSE_START, // __REL8__
    COLLISION_WITH_NW_INITIATED_REQ  =   0X38 + SM_CAUSE_START, // __REL8__
    /* The following cause values are only for sm internal usage */
    INVALID_TI                       =   0X51 + SM_CAUSE_START,
    INCORRECT_MSG                    =   0X5F + SM_CAUSE_START,
    INVALID_MAND_INFO                =   0X60 + SM_CAUSE_START,
    UNIMPLE_MSG_TYPE                 =   0X61 + SM_CAUSE_START,
    INCOMPAT_MSG_TYP_PROTO_STAT      =   0X62 + SM_CAUSE_START,
    UNIMPLE_IE                       =   0X63 + SM_CAUSE_START,
    CONDITIONAL_IE_ERROR             =   0X64 + SM_CAUSE_START,
    INCOMP_MSG_PROTO_STAT            =   0X65 + SM_CAUSE_START,
    UNSPECIFIED                      =   0X6F + SM_CAUSE_START,
    APN_RESTRICTION_VALUE_INCOMPATIBLE_WITH_ACTIVE_PDP_CTX                      =   0X70 + SM_CAUSE_START, /* 24.008 R6 CR 841 */
    STARTUP_FAILURE , /* cause enum when the link layer startup fails */ 
    SM_CAUSE_END,
/* ============================== ~SM cause ============================== */

/* ============================== ABM cause ============================== */
//
// ABM error causes, Kevin Chien
//    
    ABM_CAUSE_START = 3272,
    ABM_E_SUCCESS,
    ABM_E_INVALID_NW_ACC_ID,
    ABM_E_GPRS_REACTIVATE,
    ABM_E_GPRS_PROTOCOL_REJECTION,
    ABM_E_CSD_REACTIVATE,
    ABM_E_CSD_PPP_NEGOTIATED_FAILED,
    ABM_E_CSD_ACT_FAILED,
    ABM_E_CSD_CALL_SETUP_FAILED,
    ABM_E_WIFI_REACTIVATE,
    ABM_E_WIFI_NOTREADY,
    ABM_E_REJECTED,
    ABM_E_SLOT_LIMITED,
    ABM_E_ABORT,
    ABM_E_NON_AUTO_DEACT,
    ABM_E_BEARER_IS_HOLD, /* 3287 */
/* ============================== ~ABM cause ============================== */

/* ============================== TCM cause ============================== */
    TCM_CAUSE_START             = 3372,
    TCM_L4C_INVALID_PARAMETER   = 0x00 + TCM_CAUSE_START,
    TCM_L4C_NSAPI_NOT_IN_USE,
    
    TCM_L4C_CID_ALREADY_IN_USE,
    TCM_L4C_CID_UNEXPECTED, 

    TCM_L4C_CID_PRIMARY_IS_NOT_ACTIVATED,

    TCM_ACL_ACTION_NOT_ALLOWED,
    TCM_ACL_SIM_FILE_FULL,
    TCM_ACL_ADD_ENTRY_FAILED,
    TCM_ACL_DEL_ENTRY_FAILED,
    TCM_ACL_SET_ENTRY_FAILED,
    TCM_ACL_SIM_READ_FAILED,
    TCM_ACL_SIM_WRITE_FAILED,
/* ============================== ~TCM cause ============================== */

/* ============================== L4C cause ============================== */
    L4C_CMD_CONFLICT = 3472,
    L4C_LOCAL_DISCONNECT_CSD = 3473 //MAUI_01801045
/* ============================== ~L4C cause ============================== */
}ps_cause_enum;


typedef enum {// string  SIA   SIB   SIC
   L4_ALLSS,
   L4_EMLPP,  // "75",    -     -     -
   L4_EMLPP0, // "750",   -     -     -
   L4_EMLPP1, // "751",   -     -     -
   L4_EMLPP2, // "752",   -     -     -
   L4_EMLPP3, // "753",   -     -     -
   L4_EMLPP4, // "754",   -     -     -
   L4_CD,     // "66",    -     -     -
   L4_CLIP,   // "30",    -     -     -
   L4_CLIR,   // "31",    -     -     -
   L4_COLP,   // "76",    -     -     -
   L4_COLR,   // "77",    -     -     -
   L4_CFU,    // "21",   DN    BS     -
   L4_CFB,    // "67",   DN    BS     -
   L4_CFNRY,  // "61",   DN    BS     T
   L4_CFNRC,  // "62",   DN    BS     -
   L4_CFA,    // "002",  DN    BS     T
   L4_CFC,    // "004",  DN    BS     T
   L4_CW,     // "43",   BS     -     -
   L4_HOLD,
   L4_MPTY,
   L4_UUS1,   // "361",   R     -     -
   L4_UUS2,   // "362",   R     -     -
   L4_UUS3,   // "363",   R     -     -
   L4_UUSALL, // "360",   R     -     -
   L4_BAOC,   // "33",   PW    BS     -
   L4_BOIC,   // "331",  PW    BS     -
   L4_BOICEXHC, // "332",PW    BS     -
   L4_BAIC,   // "35",   PW    BS     -
   L4_BAICROAM, // "351",PW    BS     -
   L4_BAC,    // "330",  PW    BS     -
   L4_BOC,    // "333",  PW    BS     -
   L4_BIC,    // "353",  PW    BS     -
   L4_ECT,    // "96",
   L4_CCBS,   // "37",    N (1-5)
   L4_FM,     // "214",
   L4_CNAP,   // "300",   -     -     -
   L4_MSP1,   // "591",  PW
   L4_MSP2,   // "592",  PW
   L4_MSP3,   // "593",  PW
   L4_MSP4,   // "594",  PW
   L4_MC,     // "88",       NBR_USER (1-NBR_SB)
   L4_CDIP
} l4_ss_code_enum;

typedef enum { //                           Basic Service group number
// L4_ALL_BS_AND_TS               = N/A    1-12
//         TELESERVICES
   L4_ALL_TELESERVICES            = 10, // 1-6 + 12 
   L4_TELEPHONY                   = 11, // 1
   L4_ALL_DATA_TELESERVICES       = 12, // 2-6
   L4_FACSIMILE_SERVICES          = 13, // 6
   L4_SHORT_MESSAGE_SERVICES      = 16, // 2
   L4_ALL_TELESERVICES_EXCEPT_SMS = 19, // 1 + 3-6 + 12
//         VOICE GROUP SERVICES
   L4_VOICE_GROUP_CALL_SERVICE    = 17,
   L4_VOICE_BROADCAST_SERVICE     = 18,
//         BEARER SERVICE
   L4_ALL_BEARER_SERVICES         = 20, // 7-11
   L4_ALL_ASYNC_SERVICES          = 21, // 7
   L4_ALL_SYNC_SERVICES           = 22, // 8
   L4_ALL_DATA_CIRCUIT_SYNC       = 24, // 8
   L4_ALL_DATA_CIRCUIT_ASYNC      = 25, // 7
   L4_AUXILIARY_TELEPHONY         = 89,
   L4_ALL_GPRS_BEARER_SERVICES    = 99,  // 13
   /* Johnny: these enums do not exist in 22.030, only for MMI display,
      user should not input these enums for tele/bearer service code */
   L4_BS_ALLPADACCESSCA_SERVICES = 100,
   L4_BS_ALLDATAPDS_SERVICES = 101
} l4_bs_code_enum;

typedef enum
{
   PROTOCOL_1 = 0x00,
   PROTOCOL_2 = 0x01,
   PROTOCOL_3 = 0x02,
   PROTOCOL_4 = 0x03   
}protocol_id_enum;

typedef enum {
    L4_GERAN_RXLEVEL,
    L4_GERAN_BER,
    L4_UTRA_RSCP,
    L4_UTRA_ECNO,
    L4_EUTRA_RSRQ,
    L4_EUTRA_RSRP
} l4_cesq_param_enum;

#endif
