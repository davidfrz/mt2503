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
 * phb_sap.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This is function declarations for L4CPHB SAP.
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
#ifndef _PHB_SAP_H
#define _PHB_SAP_H

#include "kal_release.h"
#include "l4c2phb_enums.h"
#include "ps_public_enum.h"
#include "kal_general_types.h"
#include "l4c2phb_struct.h"
#include "sim_common_enums.h"
#include "app_ltlcom.h"

#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */
#ifndef _L4C2PHB_ENUMS_H
#error "l4c2phb_enums.h should be included"
#endif 

    /* This macro fetches word(32bits)-aligned value, the argument should be unsigned */
#define get_32bits_aligned_val(x) (((kal_uint32)(x) + 3) & (~(0x03)))

    extern phb_errno_enum l4cphb_phonebook_status_req(
                            phb_storage_enum storage,
                            kal_uint16 *total,
                            kal_uint16 *available);
    extern phb_errno_enum l4cphb_status_req(phb_type_enum type, kal_uint16 *total, kal_uint16 *available);
    extern phb_errno_enum l4c_phb_get_file_info(kal_uint8 type, phb_storage_enum storage, l4cphb_file_info_struct* file_info, kal_uint8 occurrence);
    extern phb_errno_enum l4c_phb_get_ln_file_info(kal_uint8 type, phb_storage_enum storage, l4cphb_file_info_struct* file_info);
    extern phb_errno_enum l4cphb_mode_req(sim_dn_enum mode, kal_bool switch_on);

    extern kal_bool l4cphb_test_storage(kal_uint8 const **buffer);
    extern kal_bool l4cphb_test_index(kal_uint8 const **buffer);
    extern kal_bool l4cphb_test_text(kal_uint8 const **buffer);
    extern kal_bool l4cphb_test_write_parameter(kal_uint8 const **buffer);
    extern kal_uint8 *l4cphb_alloc_peer_buf(peer_buff_struct **peer_buf_ptr, kal_uint16 count);
#if !defined(__PHB_NO_CALL_LOG__)
    extern kal_uint8 *l4cphb_alloc_ln_peer_buf(peer_buff_struct **peer_buf_ptr, kal_uint16 count);
#endif /* !defined(__PHB_NO_CALL_LOG__) */

    extern kal_uint16 l4cphb_get_index_by_location(kal_uint8 type, kal_uint8 storage, kal_uint16 record_index);

    extern kal_bool l4cphb_get_alpha_list_req(phb_type_enum type, kal_uint16 *list);

#ifdef __cplusplus
}
#endif 

#endif /* _PHB_SAP_H */ 

