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
 /*******************************************************************************
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   sim_ps_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Structure provided by SIM task and inside-PS task uses only
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef SIM_PS_STRUCT_H
#define SIM_PS_STRUCT_H

#include "kal_general_types.h"
#include "event_shed.h" 
#include "stack_timer.h"
#include "sim_public_enum.h"
#include "sim_ps_enum.h"
#include "ps_public_struct.h"
#include "ps_public_enum.h"

/* inside PS */
typedef struct      //mtk02514_file
{
   /* This field gives the actual file id of EF */ 
   sim_file_id_enum           file_id;

   /* This field gives the id of the parent of the EF */ 
   sim_file_index_enum        parent_file_idx;

   /* This field gives the id of the grandparent of the EF */ 
//   sim_file_index_enum        grand_parent_file_idx;

   /* This field is used by USIM select by path function */
//   kal_uint8                        full_path[6];
}usim_ef_info_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mode;
    kal_uint8 access_id;
    kal_uint8 pin1[8];
} sim_start_req_struct;

typedef struct {
    kal_uint8 num_lp;
    kal_uint8 lp_file_type;
    kal_uint8 lp[NUM_OF_BYTE_LP * MAX_LP_NUM];
} sim_lp_struct;

typedef struct {
    kal_uint8 num_ecc;
    sim_ecc_entry_struct ecc_entry[5];
    kal_uint8 ecc_rec_len;
    kal_uint8 *ecc_ptr;
} sim_ecc_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    sim_chv_info_struct chv_info;
    sim_lp_struct lp[2];
    sim_ecc_struct ecc;
    kal_uint8 iccid[10];
    kal_uint8 access_id;
    kal_uint8 is_valid_rat_mode;  //__ENS_RAT_BALANCING__
    kal_uint8 rat_mode; //RAT mode setting value in EF_RAT	
} sim_start_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cause;
} sim_error_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result; /*[MAUI_02450359] mtk01612: use result as is_imsi_valid*/
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_gid1;
    kal_uint8 gid1[NUM_GID1]; /*[MAUI_03097146] mtk01612: use NUM_GID1, NUM_GID2 instead of hard code */
    kal_uint8 is_valid_gid2;
    kal_uint8 gid2[NUM_GID2];
/* moved from mmi_ready_ind */
    kal_uint16 num_plmnsel_data; /* zero means invalid! */
    kal_uint8 *plmnsel_data;
    kal_uint16 num_uplmnwact_data; /* zero means invalid! */
    kal_uint8 *uplmnwact_data;
    kal_uint16 num_oplmnwact_data; /* zero means invalid! */
    kal_uint8 *oplmnwact_data;
    kal_uint8 is_valid_dck;
    kal_uint8 dck[16];
/* [MAUI_02129840] mtk80420: Medium Item 5, Remove the ef_acc, sopname, opname from mmi_security_ind */

/*[[MAUI_02439033]] mtk01612: To sync plmn file handling. Send hplmn to SMU, even if SMU don't need it*/
    kal_uint16 num_hplmnwact_data;        /* zero means invalid! */
    kal_uint8 *hplmnwact_data;           /* Free by SMU! */
    
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
#endif /* 0 */
} sim_mmi_security_ind_struct;


typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[MAX_SIM_NAME_LEN];
   kal_uint8 bcd_len;
   kal_uint8 bcd_digit[41];
} sim_addr_struct;

typedef struct {
   kal_uint8 alpha_id_size;
   kal_uint8 alpha_id[21];
   kal_uint8 ton_npi;
   kal_uint8 digit_size;
   kal_uint8 digit[4];//[41];
   kal_uint8 index_level;
   kal_bool network_specific;
   kal_bool premium_rate;
} sim_info_num_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint8 dn_type;
    kal_uint8 phase;
    kal_uint8 is_valid_puct;
    kal_uint8 ef_puct[5];
    kal_uint8 is_spn_valid;
    kal_uint8 spn[17];
    kal_uint8 is_opname_valid;
    kal_uint8 opname[20];
    kal_uint8 is_sopname_valid;
    kal_uint8 sopname[10]; 
   kal_uint8 no_msisdn;        // MSISDN
   sim_addr_struct msisdn[2];
   kal_uint8 no_info_num;      // Information Numbers
   sim_info_num_struct *info_num;
   kal_bool is_valid_csp;
   kal_uint8 csp[22];          // Custom Service Profile
    /* Acting HPLMN */ /* mtk01488 */
    kal_bool is_valid_ef_acting_hplmn;
    kal_uint8 ef_acting_hplmn[3]; 
    kal_bool is_usim; 
    kal_uint8 is_valid_ef_ehplmn;  // 23.122 R7 feature
	kal_uint8 num_of_ehplmn;
    kal_uint8 ef_ehplmn[12];
} sim_mmi_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_ef_kc;
    kal_uint8 ef_kc[9];
    kal_uint8 ef_acc[2];
    kal_uint8 is_valid_ef_loci;
    kal_uint8 ef_loci[11];
    kal_uint8 is_valid_ef_gkc;
    kal_uint8 ef_gkc[9];
    kal_uint8 is_valid_ef_gloci;
    kal_uint8 ef_gloci[14];
    /* Below is adding for 3G */
    kal_uint8 ef_keys[33];      /* Always valid in USIM */
    kal_uint8 ef_keysps[33];  /* Always valid in USIM */
    kal_uint8 ef_hplmn_time;
    /* forbidden plmn */
    kal_uint8 is_valid_ef_fplmn;	 /* Keep for backward compatible */
    kal_uint8 num_of_fplmn; /* Extened to 10 sets of FPLMN for USIM */	
    kal_uint8 ef_fplmn[30];
    /* prefer plmn */
    kal_uint16 no_plmnsel_data;
    kal_uint8 *plmnsel_data;         /* Please don't free this pointer in MM. Keep by SMU! */
    /* user plmn */
    kal_uint16 no_uplmn_data;
    kal_uint8 *uplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    /* operator plmn */
    kal_uint16 no_oplmn_data;
    kal_uint8 *oplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    /* HPLMN */
    kal_uint16 no_hplmn_data;
    kal_uint8 *hplmn_data;           /* Please don't free this pointer in MM. Keep by SMU! */
    /* Acting HPLMN */ /* mtk01488 */
    kal_bool is_valid_ef_acting_hplmn;
    kal_uint8 ef_acting_hplmn[3]; 
    kal_bool is_usim;
    kal_bool is_service_27_support;
    kal_bool is_service_38_support;
    kal_uint8 is_valid_ef_ehplmn;	//__R7_EHPLMN__ start
    kal_uint8 num_of_ehplmn; 
    kal_uint8 ef_ehplmn[12]; //__R7_EHPLMN__ end
	kal_uint8 is_valid_ef_ehplmnpi; // 23.122 R7 feature
	kal_uint8 ef_ehplmnpi;
	kal_uint8 is_valid_ef_lrplmnsi;
	kal_uint8 ef_lrplmnsi; // 23.122 R7 feature
    kal_uint8 mnc_length; /*[MAUI_02940125] 20110513 mtk01612: carry mnc_length in SIM_MM_READY_IND*/                                                                        	
} sim_mm_ready_ind_struct;
/* GAS: MOD_SIM -> MOD_RRM */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_valid_ms_op_mode; /* !!!Remove for MONZA!!! */
    kal_uint8 ms_op_mode; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_imsi[9];
    kal_uint8 is_valid_ef_bcch; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_bcch[16];  /* ONLY for SIM card */
    kal_uint8 ef_acc[2];
    kal_uint8 is_valid_ef_loci; /* !!!Remove for MONZA!!! */
    kal_uint8 ef_loci[11];
    /* Acting HPLMN */ /* mtk01488 */
    kal_bool is_valid_ef_acting_hplmn;
    kal_uint8 ef_acting_hplmn[3]; 
    /* For MONZA only */	
    kal_bool is_usim;
    kal_bool is_test_sim;
    kal_bool is_valid_ef_netpar;   /*mtk01612: [MAUI_02575860]*/
    kal_uint16 size_ef_netpar; /*mtk01612: [MAUI_02575860]*/
    kal_uint8 ef_netpar[MAX_SUPPORT_NETPAR_DATA_SIZE];	/*mtk01612: [MAUI_02575860]*/
} sim_rr_ready_ind_struct;

/* UAS: MOD_SIM -> MOD_USIME */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool  is_usim;
    kal_bool is_test_sim;
    kal_bool is_gsm_access_allowed;
    kal_uint8 ef_acc[2];
    kal_uint8 ef_imsi[9];
	kal_bool is_valid_ef_start_hfn;
    kal_uint8 ef_start_hfn[6];
	kal_bool is_valid_ef_threshold;	
    kal_uint8 ef_threshold[3];
    kal_uint8 ef_loci[11];
    kal_bool is_valid_ef_psloci; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
    kal_uint8 ef_psloci[14]; /* If USIM inserted, this is EF-PSLOCI; if SIM inserted, this is EF_LOCIGPRS */
    kal_bool is_valid_ef_netpar;   /*mtk01612: [MAUI_02575860]*/
    kal_uint16 size_ef_netpar;
    kal_uint8 ef_netpar[MAX_SUPPORT_NETPAR_DATA_SIZE];
} usim_urr_ready_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 size_ef_netpar;
    kal_uint8 ef_netpar[MAX_SUPPORT_NETPAR_DATA_SIZE];
} usim_update_netpar_req_struct; /*mtk01612: [MAUI_02575860]*/

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
} usim_update_netpar_cnf_struct; /*mtk01612: [MAUI_02575860]*/


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_bool    cipher_ind;   // 20050202 Benson add for display cipher indication
} sim_mmrr_ready_ind_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 access_id;
    kal_uint8 path[6];
    kal_uint8 src_id; 
} sim_read_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 data[258]; // 256 + 2 for driver usage in T=1
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
    kal_uint8 src_id; 
} sim_read_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint8 data[260]; // 255 + 5 for command header space
    kal_uint8 access_id;
    kal_uint8 path[6];
    kal_uint8 src_id; 
} sim_write_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 para;
    kal_uint16 length;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
    kal_uint8 src_id; 
} sim_write_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 data[127];
    kal_uint8 data_len;
    kal_uint8 access_id;
    kal_uint8 path[6];
} sim_increase_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 data[258]; // 256 +2 for driver usage in T=1
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 length;
    kal_uint8 access_id;    
} sim_increase_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 op;
    kal_uint8 which_chv;
    kal_uint8 old_value[8];
    kal_uint8 new_value[8];
    kal_uint8 access_id;
} sim_security_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 op;
    kal_uint8 which_chv;
    kal_uint8 access_id;
    sim_chv_info_struct chv_info;
} sim_security_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 src_id; 
    kal_uint16 file_idx;
    kal_uint8 path[6];
    kal_uint8 info_type;
    kal_uint16 length; /*[MAUI_01702417] mtk01612: WinMo_GEMINI : +crsm*/  
} sim_file_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 src_id;      
    kal_uint8 file_type; 
    kal_uint16 file_idx;
    kal_uint8 info_type;
    kal_uint16 length;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 file_size;
    kal_uint8 num_of_rec;
    kal_uint8 res_data[256];
} sim_file_info_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 pattern[16];
    kal_uint8 length;
    kal_uint8 mode;
} sim_seek_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 length;
    kal_uint16 result;
    kal_uint8 data[258]; //  256 + 2 for driver usage in T=1
} sim_seek_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 dn_type;
    kal_uint8 switch_on;    
} sim_dial_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 result;
    kal_uint8 dn_type;
    kal_uint8 switch_on;    
} sim_dial_mode_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 length; /*mtk01612: [MAUI_01899190] usim_on_duma*/
} sim_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 data[258]; // 256 + 2 for driver usage in T=1
    kal_uint16 length;
} sim_status_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 switch_mode;
} sim_error_test_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint8 access_id;
    kal_uint8 state;		/* 1: read after update */
    kal_uint8 src_id;
} sim_read_plmn_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 file_idx;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint16 file_size;
    kal_uint8 file[MAX_SUPPORT_PLMN_DATA_SIZE]; /* depends on the maximum supported file size of plmn type files */
    kal_uint8 access_id;
    kal_uint8 state;		/* 1: read after update */
    kal_uint8 src_id;    
} sim_read_plmn_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint16 file_size;
    kal_uint8 file[MAX_SUPPORT_PLMN_DATA_SIZE];  /* depends on the maximum supported file size of plmn type files */
    kal_uint8 access_id;
    kal_uint8 src_id;    
} sim_write_plmn_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 file_idx;
    kal_uint16 result;
    kal_uint16 status_word;
    kal_uint8 access_id;
    kal_uint8 src_id;    
} sim_write_plmn_cnf_struct;


/* [MAUI_03058282] mtk80420: move sim_authenticate_req/cnf to public struct */


typedef struct {
    kal_uint8   ref_count;
    kal_uint16 msg_len;
    kal_uint8	next_type;
    sim_chv_info_struct	chv_info;
} sim_l4c_verify_pin_result_ind_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool is_sim_inserted;
} sim_status_update_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 switch_on;    
} sim_acl_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint16 result;
    kal_uint8 switch_on;    
} sim_acl_mode_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
} l4c_sim_get_gsmcdma_dualsim_info_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 is_sim_inserted;
   kal_uint8 is_df_gsm_existed;
   kal_uint8 is_df_cdma_existed;
} l4c_sim_get_gsmcdma_dualsim_info_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op;
} l4c_sim_set_gsmcdma_dualsim_mode_req_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8 src_id;
   kal_uint8 op;
   kal_uint8 result;
} l4c_sim_set_gsmcdma_dualsim_mode_cnf_struct;

/*mtk01612: wise_vsim start*/
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_bool  switch_on;    
} l4c_sim_set_vsim_mode_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint16 result;
    kal_bool  switch_on;   
} l4c_sim_set_vsim_mode_cnf_struct;
/*mtk01612: wise_vsim end*/


/*mtk01612: [MAUI_02014578] wise detect O2 prepay SIM*/
typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_bool is_o2_prepaid_sim;
} sim_o2_prepaid_sim_ind_struct;

/*mtk01612: MAUI_00479434 __CSIM__*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint16 req_len;
    kal_uint8 req[APDU_REQ_MAX_LEN];
} sim_csim_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_uint8 src_id;
    kal_uint8 result; //csim_result_enum
    kal_uint16 rsp_len;
    kal_uint8 rsp[APDU_RSP_MAX_LEN];
} sim_csim_cnf_struct;

/*mtk01612: [MAUI_03020152] sync polling timer*/
typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;  
    kal_bool is_sync_timer;
    kal_uint32 sync_time_period; 
} sim_sync_poll_timer_ind_struct;

/*mtk0188: SATe*/
//#define MAX_SUPPORT_SATE_CHANNEL  3

/* PH 03042005 Remote SAT */

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint16 proactive_cmd_len;
    kal_uint8 proactive_cmd[260];
} sat_proactive_cmd_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 length;
    kal_uint8 terminal_rsp[261];
} sat_terminal_rsp_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_moretime_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_poll_interval_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 length;
    kal_uint8 envelope[261];
} sat_envelope_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sim_cmd_result_enum result; 
} sat_envelope_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_refresh_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_polling_off_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_provide_local_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    kal_uint8 event_list[3];   // added by Nick for WISE 1209 //mtk01616_111129: extend size to 3 for __SATCM__ 
    sat_procomm_struct proactive_cmd;
} sat_setup_event_list_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;	
    sat_procomm_struct proactive_cmd;
} sat_timer_management_ind_struct;

/* ----End Remote SAT---- */

typedef struct {
    kal_uint8 qos_length; /* QOS identifer bit*/
    kal_uint8 unused1; /* Unused Bit*/
    kal_uint8 delay_class;
    kal_uint8 reliability_class;
    kal_uint8 peak_throughput;
    kal_uint8 unused2; /* Unused Bit*/
    kal_uint8 precedence_class;
    kal_uint8 unused3; /* Unused Bit*/
    kal_uint8 mean_throughput;
    kal_uint8 traffic_class;
    kal_uint8 delivery_order;
    kal_uint8 delivery_of_err_sdu;
    kal_uint8 max_sdu_size;
    kal_uint8 max_bitrate_up_lnk;
    kal_uint8 max_bitrate_down_lnk;
    kal_uint8 residual_bit_err_rate;
    kal_uint8 sdu_err_ratio;
    kal_uint8 transfer_delay;
    kal_uint8 traffic_hndl_priority;
    kal_uint8 guarntd_bit_rate_up_lnk;
    kal_uint8 guarntd_bit_rate_down_lnk;
} sat_gprs_qos_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_more_time_res_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 priority;
    kal_uint8 clear_text_type;
    kal_uint8 immediate_res;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */
} sat_dspl_text_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 additional_info;
} sat_dspl_text_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 type_of_input;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */
} sat_get_inkey_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 is_yes_selected;
} sat_get_inkey_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 type_of_input;
    kal_uint8 is_input_revealed_to_user;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 len_of_min_input;
    kal_uint8 len_of_max_input;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_get_input_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_get_input_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 is_softkey_preferred;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 num_of_item;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_menu_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_setup_menu_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_help_info_available;
    kal_uint8 is_softkey_preferred;
    kal_uint8 type_of_presentation;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 is_item_id_available;
    kal_uint8 item_id;
    kal_uint8 num_of_item;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_select_item_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 item_id;
} sat_select_item_res_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 tone_id;
    kal_uint32 duration;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_play_tone_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_play_tone_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 condition;
    kal_uint32 duration;
    kal_uint8 type_of_modification;
    kal_uint8 is_icon1_available;
    sat_icon_struct icon_info1;
    kal_uint8 is_icon2_available;
    sat_icon_struct icon_info2;
    kal_uint8 size_of_ccp;
    kal_uint8 ccp[MAX_SAT_SIZE_OF_CCP];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_call_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_setup_call_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 is_sms_packed_required;
    kal_uint8 size_of_addr;
    kal_uint8 addr[MAX_SIM_ADDR_LEN];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_sms_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_send_sms_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 type_of_modification;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_ss_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_additional_info;
    kal_uint8 additional_info[255];
} sat_send_ss_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 type_of_modification;
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_ussd_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_additional_info;
    kal_uint8 additional_info[255];
} sat_send_ussd_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 type;
    kal_uint8 size_of_ccp1;
    kal_uint8 ccp1[MAX_SAT_SIZE_OF_CCP];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_SUB_ADDR_BCD_LEN];
    kal_uint8 size_of_ccp2;
    kal_uint8 ccp2[MAX_SAT_SIZE_OF_CCP];
    kal_bool is_sat_action;
} sat_call_ctrl_by_sim_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 res;
    kal_uint8 type;
    kal_uint8 size_of_ccp1;
    kal_uint8 ccp1[MAX_SAT_SIZE_OF_CCP];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_SUB_ADDR_BCD_LEN];
    kal_uint8 is_bc_repeat_ind_avail;
    kal_uint8 bc_repeat_ind;
    kal_uint8 size_of_ccp2;
    kal_uint8 ccp2[MAX_SAT_SIZE_OF_CCP];
} sat_call_ctrl_by_sim_cnf_struct;

typedef sat_call_ctrl_by_sim_req_struct sat_ss_ctrl_by_sim_req_struct;
typedef sat_call_ctrl_by_sim_cnf_struct sat_ss_ctrl_by_sim_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 size_of_addr1;
    kal_uint8 addr1[MAX_SIM_ADDR_LEN];
    kal_uint8 size_of_addr2;
    kal_uint8 addr2[MAX_SIM_ADDR_LEN];
} sat_send_sms_ctrl_by_sim_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 res;
    kal_uint8 size_of_addr1;
    kal_uint8 addr1[MAX_SIM_ADDR_LEN];
    kal_uint8 size_of_addr2;
    kal_uint8 addr2[MAX_SIM_ADDR_LEN];
} sat_send_sms_ctrl_by_sim_cnf_struct;


typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 size_of_addr;
    kal_uint8 addr[MAX_SIM_ADDR_LEN];
} sat_sms_dl_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 access_id;
    kal_uint8 is_successful;
    kal_uint16 size_of_sim_ack_data;
    kal_uint8 sim_ack_data[258];
    kal_uint8 cause;
} sat_sms_dl_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 size_of_cb_page_data;
    kal_uint8 rat;
    kal_uint8 current_page;
    kal_uint8 total_page;
    kal_uint8 cb_page_data[88];
} sat_cb_dl_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_successful;
    kal_uint8 rat;
    kal_uint8 current_page;
    kal_uint8 total_page;
} sat_cb_dl_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 item_id;
    kal_uint8 is_help_info_requested;
} sat_menu_select_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_successful;
} sat_menu_select_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_bool is_full_changed;
    kal_uint8 refresh_type; /* Add for SIM REFRESH type */
    kal_uint8 num_of_file;
    kal_uint16 file_list[120];  /* [MAUI_01716279] mtk02374 20090706 change to kal_uint16 due to file number is larger than 256*/
    kal_uint8 size_of_plmn;
    kal_uint8 *plmn_list;
} sat_file_change_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 is_successful;
} sat_file_change_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_imei_info_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 is_imei_valid;
    kal_uint8 imei[8];
} sat_imei_info_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 location_info[9]; /* mtk01616_110505 MAUI_02931370 Enlarge from 7 to 9. to support Extended Cell ID in location information */		
	
    /* mtk01778, 2007/07/31: Remove the unused proactive cmd in the structure to decrease local and 
       global memory consumption. In addition, add the "rat" information for SAT requirement after R4 . { */	
    kal_uint8 rat;	 /* rat_enum, in l3_inc_enums.h */     
	 /* sat_procomm_struct proactive_cmd; */  /* PH 03042005 For Remote SAT */     
    /* } mtk01778, 2007/07/31 */ 	     
} sat_location_info_ind_struct;

/*
 *  mtk02374 20090513
 *  add for provide local info with nw search mode
 */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 nw_search_mode;
} sat_nw_search_mode_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_time_zone_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 time_zone;
} sat_time_zone_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_current_time_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 time_info[6];
} sat_current_time_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mmi_info_type;
    kal_uint8 len_of_address;
    kal_uint8 address[MAX_SIM_ADDR_BCD_LEN];    
} sat_mmi_info_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_me_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 me_status;
    kal_uint8 timing_advance;    
} sat_me_status_cnf_struct;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_nmr_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 nmr[16];
    kal_uint8 size_of_bcch;
    kal_uint8 bcch[40];
} sat_nmr_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_language_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 language[2];
} sat_language_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 call_status;
} sat_call_status_ind_struct;


/* __SATCL__ */
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 target; // "target" in activate descriptor
    sat_procomm_struct proactive_cmd; 
} sat_activate_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_activate_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_setup_idle_dspl_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_setup_idle_dspl_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class b */
} sat_run_at_command_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 size_of_at_response;
    kal_uint8 at_response[MAX_AT_RESPONESE_LEN];	//mtk02514_081216
} sat_run_at_command_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_send_dtmf_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 additional_info;
} sat_send_dtmf_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_language_specified;
    kal_uint8 iso639_language[2];
    sat_procomm_struct proactive_cmd; /* PH 03042005 For Remote SAT */    
} sat_lang_notify_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
} sat_lang_notify_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 browser_mode;
    kal_uint8 browser_identity;
    kal_uint8 provision_file_id[10];
    sat_procomm_struct proactive_cmd; /* mtk01488: 20080930 For Remote SAT */        
} sat_launch_browser_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 additional_res;  /* MAUI_02888481 */
} sat_launch_browser_res_struct;

typedef struct {
    kal_uint8 addr_length; /* Address Length*/
    kal_uint8 addr_bcd[MAX_SIM_ADDR_BCD_LEN];
} sim_addr_bcd_struct;
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
#endif
typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_bool is_mt_call;
} sat_evdl_call_connect_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 ti;
    kal_bool is_far_end;
    //kal_bool cause_p;	
    //kal_uint8 cause;	
    kal_uint8 cause_len;				// Change data type [2006-9-5 Nick]
    kal_uint8 cause[30];				// Change data type [2006-9-5 Nick]
} sat_evdl_call_disconnect_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 mm_status;
    kal_uint8 location_info[9]; /* mtk01616_110505 MAUI_02931370 Enlarge from 7 to 9. to support Extended Cell ID in location information */		
} sat_evdl_location_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_evdl_user_activity_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sat_evdl_idle_screen_available_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 iso639_language[2];
} sat_evdl_language_selection_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 card_reader_status;
} sat_evdl_card_reader_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 browser_termination_cause;
} sat_evdl_browser_termination_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 channel_status[2];
    kal_uint8 channel_data_length;
} sat_evdl_data_available_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 channel_status[2];
} sat_evdl_channel_status_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class e */
} sat_open_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;
} sat_open_gprs_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct gprs_bearer;
    sat_csd_bearer_para_struct csd_bearer;
    kal_uint16 buffer_size;
    kal_uint8 size_of_address;
    kal_uint8 addr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint8 size_of_subaddr;
    kal_uint8 subaddr[MAX_SIM_ADDR_BCD_LEN];
    kal_uint32 duration1;
    kal_uint32 duration2;
    kal_uint16 no_username;
    kal_uint8 username[16];
    kal_uint8 dcs_of_username;
    kal_uint16 no_passwd;
    kal_uint8 passwd[16];
    kal_uint8 dcs_of_passwd;
    kal_uint8 protocol_type;  /* '01' UDP '02' TCP */
    kal_uint16 port_num;
    kal_int16 no_local_addr;
    kal_uint8 local_addr[16];
    kal_int16 no_dest_addr;
    kal_uint8 dest_addr[16];
    kal_uint8 dns[4];
    kal_uint8 apn[50];
    kal_uint8 apn_length;    
} sat_open_csd_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 bearer;
    kal_uint16 buffer_size;
    kal_uint16 port_num;
} sat_open_server_mode_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_status[2];
    kal_uint8 bearer;
    sat_gprs_bearer_para_struct bearer_para;
    kal_uint16 buffer_size;
} sat_open_gprs_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_status[2];
    kal_uint8 bearer;
    sat_csd_bearer_para_struct bearer_para;
    kal_uint16 buffer_size;
} sat_open_csd_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_status[2];
    kal_uint8 bearer;
    kal_uint16 buffer_size;
} sat_open_server_mode_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id;  // sat_channel_id_enum
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class e */
} sat_close_channel_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
} sat_close_channel_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id; //sat_channel_id_enum
    kal_uint8 ch_type;
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 data_size;
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class e */
} sat_send_data_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_type;
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_data_length;
} sat_send_data_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id; //sat_channel_id_enum
    kal_uint8 ch_type;
    kal_bool is_icon_available;
    sat_icon_struct icon_info;
    kal_uint8 ch_data_length;
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class e */
} sat_recv_data_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_type;
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 ch_data_length;
} sat_recv_data_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 ch_id;	/*mtk02374 20091230 for WISE BIP*/
    sat_procomm_struct proactive_cmd; /* mtk02374 20081224 RSAT Class e */
} sat_ch_status_ind_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 cmd_detail[5];
    kal_uint8 res;
    kal_uint8 cause;
    kal_uint8 channel_status[2];
} sat_ch_status_res_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} sim_imei_lock_verified_ind_struct;

extern const usim_ef_info_struct usim_ef_info[UICC_TOTAL_FILES];

#endif

