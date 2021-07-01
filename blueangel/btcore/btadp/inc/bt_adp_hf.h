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
 *  bt_adp_hf.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines HFP handsfree role adp layer interfaces.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/

#ifdef __BT_HF_PROFILE__

#ifndef __BT_ADP_HF_H_
#define __BT_ADP_HF_H_

#include "stack_msgs.h"
#include "kal_public_defs.h"
#include "xatypes.h"
#include "bt_hfadp_struct.h"

/*****************************************************************************
* Functions
*****************************************************************************/

extern void hfadp_send_bt_message_ex(module_type src_mod, msg_type msg, U32 value, U32 value_size, U8 conn_id);
extern void bt_hfadp_send_connect_req(module_type src_mod, bt_dm_addr_struct bt_addr, kal_bool hs_conn);
extern void bt_hfadp_send_connect_ind_res(module_type src_mod, kal_bool accept, bt_dm_addr_struct bt_addr, U8 conn_id);
extern void bt_hfadp_send_disconnect_req(module_type src_mod, bt_dm_addr_struct bt_addr, U8 conn_id);
extern void bt_hfadp_send_at_command_req(module_type src_mod, U8 *data, U32 size, U8 conn_id);
extern void bt_hfadp_send_atd_num_req(module_type src_mod, bt_hf_atd_num_req_para_struct *para, U8 conn_id);
#define bt_hfadp_send_activate_req(src_mod) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_ACTIVATE_REQ, 0, 0)
#define bt_hfadp_send_deactivate_req(src_mod) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_DEACTIVATE_REQ, 0, 0)
#define bt_hfadp_send_result_code_cnf(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_RESULT_CODE_CNF, 0, 0, conn_id)
#define bt_hfadp_send_ata_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_ATA_REQ, 0, 0, conn_id)
#define bt_hfadp_send_bldn_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_BLDN_REQ, 0, 0, conn_id)
#define bt_hfadp_send_chup_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CHUP_REQ, 0, 0, conn_id)
#define bt_hfadp_send_nrec_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_NREC_REQ, 0, 0, conn_id)
#define bt_hfadp_send_cops_set_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_COPS_SET_REQ, 0, 0, conn_id)
#define bt_hfadp_send_cops_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_COPS_REQ, 0, 0, conn_id)
#define bt_hfadp_send_cnum_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CNUM_REQ, 0, 0, conn_id)
#define bt_hfadp_send_binp_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_BINP_REQ, 0, 0, conn_id)
#define bt_hfadp_send_btrh_read_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_BTRH_READ_REQ, 0, 0, conn_id)
#define bt_hfadp_send_clcc_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CLCC_REQ, 0, 0, conn_id)
#define bt_hfadp_send_sco_connect_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_SCO_CONNECT_REQ, conn_id, 16, conn_id)
#define bt_hfadp_send_sco_disconnect_req(src_mod, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_SCO_DISCONNECT_REQ, conn_id, 16, conn_id)
#define bt_hfadp_send_atd_mem_req(src_mod, index, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_ATD_MEM_REQ, index, 32, conn_id)
#define bt_hfadp_send_cmee_req(src_mod, enable, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CMEE_REQ, enable, 8, conn_id)
#define bt_hfadp_send_vts_req(src_mod, dtmf, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_VTS_REQ, dtmf, 8, conn_id)
#define bt_hfadp_send_vgs_req(src_mod, gain, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_VGS_REQ, gain, 8, conn_id)
#define bt_hfadp_send_vgm_req(src_mod, gain, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_VGM_REQ, gain, 8, conn_id)
#define bt_hfadp_send_chld_req(src_mod, n, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CHLD_REQ, n, 8, conn_id)
#define bt_hfadp_send_clip_req(src_mod, enable, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CLIP_REQ, enable, 8, conn_id)
#define bt_hfadp_send_ccwa_req(src_mod, enable, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_CCWA_REQ, enable, 8, conn_id)
#define bt_hfadp_send_bvra_req(src_mod, enable, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_BVRA_REQ, enable, 8, conn_id)
#define bt_hfadp_send_btrh_set_req(src_mod, n, conn_id) hfadp_send_bt_message_ex(src_mod, MSG_ID_BT_HF_BTRH_SET_REQ, n, 8, conn_id)

/* Handsfree Initialization and Message Handler Function */
extern void hfadp_init(void);
extern void hfadp_handler(ilm_struct *ilm);

#endif /* __BT_ADP_HF_H_ */

#endif /* __BT_HF_PROFILE__ */

