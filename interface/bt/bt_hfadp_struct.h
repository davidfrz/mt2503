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
 *  bt_hfadp_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines HFP handsfree role adp layer structures.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/

#ifdef __BT_HF_PROFILE__

#ifndef __BT_HFADP_STRUCT_H_
#define __BT_HFADP_STRUCT_H_

#include "app_ltlcom.h"
#include "kal_general_types.h"
#include "bluetooth_struct.h"
#include "bt_dm_struct.h"

/*****************************************************************************
* Macro Definitions
*****************************************************************************/

#define MAX_HF_OPERATOR_LENGTH 16
#define MAX_HF_PHONE_NUMBER_LENGTH 48

#define MAX_HF_CONN_NUM BT_PROFILES_LINK_NUM


#define MAX_HF_XAPL_NUMBER_LENGTH 20
#define MAX_HF_CUSTOM_AT_NUMBER 2
/*****************************************************************************
* Structures
*****************************************************************************/

/*************************************************************
 [HF Activate]
**************************************************************/

/* MSG_ID_BT_HF_ACTIVATE_REQ */
/* MSG_ID_BT_HF_ACTIVATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result; /* 0 success, non-zero failed */
} bt_hf_activate_cnf_struct;


/*************************************************************
 [HF Deactivate]
**************************************************************/

/* MSG_ID_BT_HF_DEACTIVATE_REQ */
/* MSG_ID_BT_HF_DEACTIVATE_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result; /* 0 success, non-zero failed */
} bt_hf_deactivate_cnf_struct;


/*************************************************************
 [HF Outgoing Connection]
**************************************************************/

/* MSG_ID_BT_HF_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr; /* remote device BT address */
    kal_bool hs_conn; /* true for Headset Profile, false for Hands-free Profile */
} bt_hf_connect_req_struct;

/* MSG_ID_BT_HF_CONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16  result;
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
} bt_hf_connect_cnf_struct;


/*************************************************************
 [HF Incoming Connection]
**************************************************************/

/* MSG_ID_BT_HF_CONNECT_IND_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
    kal_bool hs_conn;
} bt_hf_connect_ind_req_struct;

/* MSG_ID_BT_HF_CONNECT_IND_RES */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool accept; /* true accept, false reject */
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
} bt_hf_connect_ind_res_struct;


/*************************************************************
 [HF Outgoing Disconnection]
**************************************************************/

/* MSG_ID_BT_HF_DISCONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
} bt_hf_disconnect_req_struct;

/* MSG_ID_BT_HF_DISCONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
} bt_hf_disconnect_cnf_struct;


/*************************************************************
 [HF Incoming Disconnection]
**************************************************************/
/* MSG_ID_BT_HF_DISCONNECT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    bt_dm_addr_struct bt_addr;
    kal_uint8 connection_id;
} bt_hf_disconnect_ind_struct;


/*************************************************************
 [HF Outgoing SCO Connection]
**************************************************************/

/* MSG_ID_BT_HF_SCO_CONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
} bt_hf_sco_connect_req_struct;

/* MSG_ID_BT_HF_SCO_CONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 connection_id;
} bt_hf_sco_connect_cnf_struct;


/*************************************************************
 [HF Incoming SCO Connection]
**************************************************************/
/* MSG_ID_BT_HF_SCO_CONNECT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
} bt_hf_sco_connect_ind_struct;


/*************************************************************
 [HF Outgoing SCO Disconnection]
**************************************************************/

/* MSG_ID_BT_HF_SCO_DISCONNECT_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
} bt_hf_sco_disconnect_req_struct;

/* MSG_ID_BT_HF_SCO_DISCONNECT_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint16 result;
    kal_uint8 connection_id;
} bt_hf_sco_disconnect_cnf_struct;


/*************************************************************
 [HF Incoming SCO Disconnection]
**************************************************************/
/* MSG_ID_BT_HF_SCO_DISCONNECT_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
} bt_hf_sco_disconnect_ind_struct;


/*************************************************************
 [HF Generic AT Command Request]
**************************************************************/
typedef enum
{
    HF_FINAL_RESULT_CODE_OK = 0, /* Success */
    /* AT Command timeout: remote device does not response within the time */
    HF_FINAL_RESULT_CODE_TIMEOUT,
    /* Generic Error */
    HF_FINAL_RESULT_CODE_ERROR,
    /* Externed Error: the externed error code is in 'cme_errcode' */
    HF_FINAL_RESULT_CODE_CME_ERROR,
    /* Other Erros */
    HF_FINAL_RESULT_CODE_BUSY,
    HF_FINAL_RESULT_CODE_DELAYED,
    HF_FINAL_RESULT_CODE_BLACKLISTED,
    HF_FINAL_RESULT_CODE_NO_ANSWER,
    HF_FINAL_RESULT_CODE_NO_CARRIER,
    HF_FINAL_RESULT_CODE_NO_DIALTONE
} bt_hf_final_result_code_enum;

/* MSG_ID_BT_HF_AT_COMMAND_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data;
    kal_uint32 size;
    kal_uint8 connection_id;
} bt_hf_at_command_req_struct;

/* MSG_ID_BT_HF_AT_COMMAND_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 connection_id;
} bt_hf_at_command_cnf_struct;


/*************************************************************
 [HF Generic Result Code Indication]
**************************************************************/

/* MSG_ID_BT_HF_RESULT_CODE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 *data;
    kal_uint32 size;
    kal_uint8 connection_id;
} bt_hf_result_code_ind_struct;

/* MSG_ID_BT_HF_CHUP_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
} bt_hf_chup_req_struct;


/* MSG_ID_BT_HF_RESULT_CODE_CNF */
typedef bt_hf_chup_req_struct bt_hf_result_code_cnf_struct;

/* After upper layer copy out the data from the buffer, upper layer
   should send a message back to confirm. Only after comfirmation,
   BT can continue send data to upper layer. */


/*************************************************************
 [HF ATA]
**************************************************************/

/* MSG_ID_BT_HF_ATA_REQ */
typedef bt_hf_chup_req_struct bt_hf_ata_req_struct;

/* MSG_ID_BT_HF_ATA_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_ata_cnf_struct;


/*************************************************************
 [HF ATDdddddddd;]
**************************************************************/

/* MSG_ID_BT_HF_ATD_NUM_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_atd_num_req_struct;

/* MSG_ID_BT_HF_ATD_NUM_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_atd_num_cnf_struct;


/*************************************************************
 [HF ATD>n;]
**************************************************************/

/* MSG_ID_BT_HF_ATD_MEM_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 index;
    kal_uint8 connection_id;
} bt_hf_atd_mem_req_struct;

/* MSG_ID_BT_HF_ATD_MEM_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_atd_mem_cnf_struct;


/*************************************************************
 [HF AT+BLDN]
**************************************************************/

/* MSG_ID_BT_HF_BLDN_REQ */
typedef bt_hf_chup_req_struct bt_hf_bldn_req_struct;
/* MSG_ID_BT_HF_BLDN_CNF*/
typedef bt_hf_at_command_cnf_struct bt_hf_bldn_cnf_struct;


/*************************************************************
 [HF AT+CHUP]
**************************************************************/

/* MSG_ID_BT_HF_CHUP_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_chup_cnf_struct;


/*************************************************************
 [HF AT+CMEE=<n>]
**************************************************************/

/* MSG_ID_BT_HF_CMEE_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_cmee_req_struct;

/* MSG_ID_BT_HF_CMEE_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_cmee_cnf_struct;


/*************************************************************
 [HF AT+NREC=0]
**************************************************************/

/* MSG_ID_BT_HF_NREC_REQ */
typedef bt_hf_chup_req_struct bt_hf_nrec_req_struct;

/* MSG_ID_BT_HF_NREC_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_nrec_cnf_struct;


/*************************************************************
 [HF AT+VTS=<DTMF>]
**************************************************************/

/* MSG_ID_BT_HF_VTS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 dtmf;
    kal_uint8 connection_id;
} bt_hf_vts_req_struct;

/* MSG_ID_BT_HF_VTS_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_vts_cnf_struct;


/*************************************************************
 [HF AT+VGS=<n>]
**************************************************************/

/* MSG_ID_BT_HF_VGS_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 gain;
    kal_uint8 connection_id;
} bt_hf_vgs_req_struct;

/* MSG_ID_BT_HF_VGS_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_vgs_cnf_struct;


/*************************************************************
 [HF AT+VGM=<n>]
**************************************************************/

/* MSG_ID_BT_HF_VGM_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 gain;
    kal_uint8 connection_id;
} bt_hf_vgm_req_struct;

/* MSG_ID_BT_HF_VGM_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_vgm_cnf_struct;


/*************************************************************
 [HF AT+CHLD=<n>]
**************************************************************/

/* MSG_ID_BT_HF_CHLD_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 n;
    kal_uint8 connection_id;
} bt_hf_chld_req_struct;

/* MSG_ID_BT_HF_CHLD_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_chld_cnf_struct;


/*************************************************************
 [HF AT+CLIP=<n>]
**************************************************************/

/* MSG_ID_BT_HF_CLIP_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_clip_req_struct;

/* MSG_ID_BT_HF_CLIP_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_clip_cnf_struct;


/*************************************************************
 [HF AT+CCWA=<n>]
**************************************************************/

/* MSG_ID_BT_HF_CCWA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_ccwa_req_struct;

/* MSG_ID_BT_HF_CCWA_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_ccwa_cnf_struct;


/*************************************************************
 [HF AT+COPS=3,0]
**************************************************************/

/* MSG_ID_BT_HF_COPS_SET_REQ */
typedef bt_hf_chup_req_struct bt_hf_cops_set_req_struct;

/* MSG_ID_BT_HF_COPS_SET_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_cops_set_cnf_struct;


/*************************************************************
 [HF AT+COPS?]
**************************************************************/

/* MSG_ID_BT_HF_COPS_REQ */
typedef bt_hf_chup_req_struct bt_hf_cops_req_struct;

/* MSG_ID_BT_HF_COPS_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final; /* TRUE is final cnf: check result and cmeErrorCode */
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8  size;
    kal_uint8  operator_string[MAX_HF_OPERATOR_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_cops_cnf_struct;


/*************************************************************
 [HF AT+CNUM]
**************************************************************/

/* MSG_ID_BT_HF_CNUM_REQ */
typedef bt_hf_chup_req_struct bt_hf_cnum_req_struct;

/* MSG_ID_BT_HF_CNUM_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final; /* TRUE is final cnf: check result and cmeErrorCode */
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 type; /* phone number type */
    kal_uint8 service; /* shall be either 4 (voicd) or 5 (fax) */
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_cnum_cnf_struct;


/*************************************************************
 [HF AT+BVRA=<n>]
**************************************************************/

/* MSG_ID_BT_HF_BVRA_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_bvra_req_struct;

/* MSG_ID_BT_HF_BVRA_CNF */
typedef bt_hf_at_command_cnf_struct bt_hf_bvra_cnf_struct;


/*************************************************************
 [HF AT+BINP=1]
**************************************************************/

/* MSG_ID_BT_HF_BINP_REQ */
typedef bt_hf_chup_req_struct bt_hf_binp_req_struct;

/* MSG_ID_BT_HF_BINP_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_binp_cnf_struct;


/*************************************************************
 [HF AT+BTRH?]
**************************************************************/

/* MSG_ID_BT_HF_BTRH_READ_REQ */
typedef bt_hf_chup_req_struct bt_hf_btrh_req_struct;

/* MSG_ID_BT_HF_BTRH_READ_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 n;
    kal_uint8 connection_id;
} bt_hf_btrh_read_cnf_struct;


/*************************************************************
 [HF AT+BTRH=<n>]
**************************************************************/

/* MSG_ID_BT_HF_BTRH_SET_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 n; /* 0 ~ 2 */
    kal_uint8 connection_id;
} bt_hf_btrh_set_req_struct;

/* MSG_ID_BT_HF_BTRH_SET_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 n;
    kal_uint8 connection_id;
} bt_hf_btrh_set_cnf_struct;


/*************************************************************
 [HF AT+CLCC]
**************************************************************/

/* MSG_ID_BT_HF_CLCC_REQ */
typedef bt_hf_chup_req_struct bt_hf_clcc_req_struct;

/* MSG_ID_BT_HF_CLCC_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool final;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 index;
    kal_uint8 dir;
    kal_uint8 status;
    kal_uint8 mode;
    kal_uint8 multiparty;
    kal_uint8 type;
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_clcc_cnf_struct;


/* MSG_ID_BT_HF_XAPL_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
    kal_uint8 features;
    kal_uint8 size;
    kal_uint8 id_version[MAX_HF_XAPL_NUMBER_LENGTH + 1];
} bt_hf_xapl_req_struct;

/* MSG_ID_BT_HF_XAPL_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
    kal_bool final;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
    kal_uint8 features;
} bt_hf_xapl_cnf_struct;

/* MSG_ID_BT_HF_ACCEV_REQ */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
    kal_uint8 num;
    kal_uint8 key[MAX_HF_CUSTOM_AT_NUMBER];
    kal_uint8 value[MAX_HF_CUSTOM_AT_NUMBER];
} bt_hf_accev_req_struct;

/* MSG_ID_BT_HF_ACCEV_CNF */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 connection_id;
    bt_hf_final_result_code_enum result;
    kal_uint16 cme_errcode; /* Contain +CME ERROR: <err> error code. */
} bt_hf_accev_cnf_struct;

/*************************************************************
 [HF +VGS:<n>]
**************************************************************/
/* MSG_ID_BT_HF_VGS_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 gain;
    kal_uint8 connection_id;
} bt_hf_vgs_ind_struct;

/* MSG_ID_BT_HF_VGS_IND_RES */
typedef bt_hf_vgs_ind_struct bt_hf_vgs_ind_res_struct;

/*************************************************************
 [HF +VGM:<n>]
**************************************************************/
/* MSG_ID_BT_HF_VGM_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 gain;
    kal_uint8 connection_id;
} bt_hf_vgm_ind_struct;


/*************************************************************
 [HF +BSIR:<n>]
**************************************************************/
/* MSG_ID_BT_HF_BSIR_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_bsir_ind_struct;


/*************************************************************
 [HF +CIEV:<event>,<value>]
**************************************************************/
/* MSG_ID_BT_HF_CIEV_SERVICE_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 service; /* 0 ~ 1 */
    kal_uint8 connection_id;
} bt_hf_ciev_service_ind_struct;

/* MSG_ID_BT_HF_CIEV_CALL_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 call; /* 0 ~ 1 */
    kal_uint8 connection_id;
} bt_hf_ciev_call_ind_struct;

/* MSG_ID_BT_HF_CIEV_CALLSETUP_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 callsetup; /* 0 ~ 3 */
    kal_uint8 connection_id;
} bt_hf_ciev_callsetup_ind_struct;

/* MSG_ID_BT_HF_CIEV_CALLHELD_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 callheld; /* 0 ~ 2 */
    kal_uint8 connection_id;
} bt_hf_ciev_callheld_ind_struct;

/* MSG_ID_BT_HF_CIEV_SIGNAL_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 signal; /* 0 ~ 5 */
    kal_uint8 connection_id;
} bt_hf_ciev_signal_ind_struct;

/* MSG_ID_BT_HF_CIEV_ROAM_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 roam;
    kal_uint8 connection_id;
} bt_hf_ciev_roam_ind_struct;

/* MSG_ID_BT_HF_CIEV_BATTCHG_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 battchg; /* 0 ~ 5 */
    kal_uint8 connection_id;
} bt_hf_ciev_battchg_ind_struct;


/*************************************************************
 [HF RING]
**************************************************************/
/* MSG_ID_BT_HF_RING_IND */
typedef bt_hf_chup_req_struct bt_hf_ring_ind_struct;

/*************************************************************
 [HF +CLIP:<number>,<type>]
**************************************************************/
/* MSG_ID_BT_HF_CLIP_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_clip_ind_struct;


/*************************************************************
 [HF +CCWA:<number>,<type>]
**************************************************************/
/* MSG_ID_BT_HF_CCWA_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 type;
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_ccwa_ind_struct;


/*************************************************************
 [HF +BVRA:<n>]
**************************************************************/
/* MSG_ID_BT_HF_BVRA_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_bool enable;
    kal_uint8 connection_id;
} bt_hf_bvra_ind_struct;


/*************************************************************
 [HF +BTRH:<n>]
**************************************************************/
/* MSG_ID_BT_HF_BTRH_IND */
typedef struct
{
    LOCAL_PARA_HDR
    kal_uint8 n; /* 0 ~ 2 */
    kal_uint8 connection_id;
} bt_hf_btrh_ind_struct;


typedef struct
{
    kal_uint8 size;
    kal_uint8 number[MAX_HF_PHONE_NUMBER_LENGTH + 1];
    kal_uint8 connection_id;
} bt_hf_atd_num_req_para_struct;


#endif /* __BT_HFADP_STRUCT_H_ */

#endif /* __BT_HF_PROFILE__ */

