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
 * Filename:
 * ---------
 * l4c_msghdlr.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

#ifndef _L4C_MSGHDLR_H
#define _L4C_MSGHDLR_H

#include "app_ltlcom.h"
//#include "kal_non_specific_general_types.h"
#include "stack_config.h"

#include "kal_general_types.h"


extern void nvram_startup_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void nvram_read_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void nvram_reset_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void nvram_write_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_ps_abm_start_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void nvram_set_lock_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_nvram_sds_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_read_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_write_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_file_info_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_poweroff_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_status_update_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#ifdef __GSMCDMA_DUALSIM__
extern void sim_get_gsmcdma_dualsim_info_cnf_hdlr(local_para_struct  *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void sim_set_gsmcdma_dualsim_mode_cnf_hdlr(local_para_struct  *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif /* __GSMCDMA_DUALSIM__ */

extern void l4c_null_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

extern void l4c_mmi_ready_notify_req(void);
extern void l4c_at_general_res_req(kal_bool result, kal_uint8* string); /* AT_FRST */

#ifdef __LED_SUPPORT__
extern void l4c_gpio_control_led_req_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif  //__LED_SUPPORT__

#ifdef __NBR_CELL_INFO__
 /*----- 081107 Lexel: for cell info--------*/
extern void l4c_nbr_cell_info_reg_req_hdlr(module_type src_id,local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4c_nbr_cell_info_dereg_req_hdlr(module_type src_id,local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cps_nbr_cell_info_start_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cps_nbr_cell_info_stop_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
extern void l4cps_nbr_cell_info_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

#if defined(__ENABLE_MYBCCH__)
extern kal_bool l4cps_set_mybcch_cell_lock_req_hdlr(kal_uint8 src_id, kal_uint32 enabled_bitmap, kal_bool band_indicator, kal_uint16 *lock_arfcn, kal_uint32 mode);
extern kal_bool l4cps_get_mybcch_info_req_hdlr(kal_uint8 src_id, kal_uint32 cmd_mode);
extern void l4cps_get_mybcch_info_cnf_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern kal_bool l4cas_enter_capid_cal_mode_req_hdlr(kal_uint8 src_id);
extern kal_bool l4cas_leave_capid_cal_mode_req_hdlr(kal_uint8 src_id);
extern void l4cas_capid_cal_result_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);


#if defined(__AT_RRC_TRACE_SUPPORT__)
extern void l4cas_rrc_peer_trace_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif
extern void l4cas_b3_info_ind_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);

#if defined(__NFC_SUPPORT__)
extern void l4c_nfc_test_rsp_hdlr(local_para_struct *local_para_ptr, peer_buff_struct *peer_buff_ptr);
#endif

extern void l4cps_gas_cell_power_level_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);
extern void l4cps_uas_cell_power_level_ind_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
} dummy_header_struct;

extern void l4c_med_in_proc_call_cnf_hdlr(local_para_struct * local_para_ptr, peer_buff_struct * peer_buff_ptr);

#endif /* _L4C_MSGHDLR_H */
