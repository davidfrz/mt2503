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
 * phb_handler_sat.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is SAT handler of PHB module.
 *   Note that when __SAT__ is defined will this file be compiled.
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
#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"
#include "nvram_interface.h"

#ifdef __SAT__
#include "ps2sat_struct.h"
#endif 

//#include "l4_common.h"
#include "ps2sim_struct.h"

#include "l4c2phb_enums.h"
//#include "l4c2phb_struct.h"
#include "Smu_common_enums.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
#include "phb_se.h"

#include "phb_context.h"

//#include "phb_common.h"
#include "phb_utils.h"
#include "phb_ilm.h"

#include "phb_handler_startup.h"
#include "phb_handler_sat.h"

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "ps_public_enum.h"
#include "stack_config.h"
#include "nvram_common_defs.h"
#include "nvram_enums.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_HANDLER_SAT_C_

#ifdef __SAT__

#ifdef __PHB_USIM_SUPPORT__
#if defined(__GEMINI__) || defined(GEMINI_PLUS)
extern kal_bool is_usim_type(sim_interface_enum which_sim);
#else /* __GEMINI__ */
extern kal_bool is_usim_type(void);
#endif /* __GEMINI__ */
#endif /* __PHB_USIM_SUPPORT__ */

extern void l4csmu_get_chv_info_status(sim_chv_info_struct *chv_info, sim_chv_status_struct *chv_status);

extern sim_chv_status_struct chv_status[];
extern kal_int32 phb_query_count[];


/*****************************************************************************
 * FUNCTION
 *  phb_sat_file_change_handler
 * DESCRIPTION
 *  In current implementation, all related EF's will be rescanned.
 *  Hence, actually the file_change request will be forwarded to
 *  startup_handler().
 * PARAMETERS
 *  ilm_ptr             [IN]        The primitives
 *  control_block       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sat_file_change_handler(ilm_struct *ilm_ptr, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SAT_FILE_CHANGE);

    if (ilm_ptr != NULL)
    {
        kal_uint16 i;
        kal_bool need_reset_flag = KAL_FALSE;
        sat_file_change_ind_struct *sat_file_change_ind;

        sat_file_change_ind = (sat_file_change_ind_struct*) ilm_ptr->local_para_ptr;

      /**
       * Since sat_file_change is an implicit reset, there 2 ways to implement this:
       *
       * 1. Interrupts other being processed operations and forbids 
       *   other further requests to PHB, except approve and search:
       *   In this implementation, 
       *   startup handler should always uses the first control_block, 
       *   and lock all control_blocks are locked temporarily;
       *   thus prevent other operations, except approve and search, 
       *   from accessing PHB while it is busy.
       *
       * 2. Allow all other operations to provide maximum possible
       *   concurrency degrees.
       *
       * Curretly, solution 1 is implemented.
       * Control_blocks are all locked to interrupt all other in-processing
       * operations and reject all further requests, to prevent
       * multiple access to PHB when it is not ready.
       */
        /* LN not ready means phb haven't been inited yet */
        if (phb_ptr->state == PHB_STATE_LN_NOT_READY)
        {
        }
        else if (sat_file_change_ind->is_full_changed)
        {
            need_reset_flag = KAL_TRUE;
        }
        else
        {
            for (i = 0; i < sat_file_change_ind->num_of_file; i++)
            {
                switch (sat_file_change_ind->file_list[i])
                {
                    case FILE_ADN_IDX:
                    case FILE_ECC_IDX:
                    case FILE_EXT1_IDX:                       
                #ifdef __PHB_USIM_SUPPORT__
                       need_reset_flag = KAL_TRUE;
                       /* MUST: Break CAN'T BE REMOVED */
                       break;                   
                    case FILE_U_ECC_IDX:
                        
                    case FILE_G_ADN_IDX:
                    case FILE_U_ADN_IDX:
                        
                    case FILE_G_PBR_IDX:
                    case FILE_U_PBR_IDX:
                        
                    case FILE_G_EXT1_IDX:
                    case FILE_U_EXT1_IDX:
                        
                    case FILE_U_FDN_IDX:
                    case FILE_U_SDN_IDX:
                    case FILE_U_EXT2_IDX:
                    case FILE_U_EXT3_IDX:
                    case FILE_U_BDN_IDX:
                    case FILE_U_EXT4_IDX:
                    case FILE_U_MSISDN_IDX:
                    case FILE_U_EXT5_IDX:
                #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
                    case FILE_G_IAP_IDX:
                    case FILE_U_IAP_IDX:
                        
                    case FILE_G_ANR_IDX:
                    case FILE_U_ANR_IDX:
                        
                    case FILE_G_EMAIL_IDX:
                    case FILE_U_EMAIL_IDX:
                        
                    case FILE_G_SNE_IDX:
                    case FILE_U_SNE_IDX:
                        
                    case FILE_G_GAS_IDX:
                    case FILE_U_GAS_IDX:
                        
                    case FILE_G_AAS_IDX:
                    case FILE_U_AAS_IDX:
                        
                    case FILE_G_GRP_IDX:
                    case FILE_U_GRP_IDX:
                #endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */
                       ASSERT(phb_util_is_usim(phb_which_sim_ex()));
                #endif /* __PHB_USIM_SUPPORT__ */
                    case FILE_FDN_IDX:
                    case FILE_SDN_IDX:
                    case FILE_EXT2_IDX:
                    case FILE_EXT3_IDX:
                    case FILE_BDN_IDX:
                    case FILE_EXT4_IDX:
                    case FILE_MSISDN_IDX:
                        need_reset_flag = KAL_TRUE;
                        break;
                    default:
                        break;
                }
            }
        }
        if (need_reset_flag)
        {
            for (i = 0; i < PHB_CONCURRENCY_DEGREE; i++)
            {
                if (phb_ptr->control_block[i].is_allocated == KAL_TRUE)
                {
                    phb_ptr->control_block[i].err_handler(NULL, &(phb_ptr->control_block[i]));
                }
            }

            phb_reset_all_control_blocks();
            control_block = phb_alloc_control_block();
            
            ASSERT(control_block != NULL);

            control_block->src_id = sat_file_change_ind->src_id;
            /* Retain msg_id */
            control_block->cnf_msg_id = ilm_ptr->msg_id;

            phb_is_sim_file_support();
        }
        phb_ptr->dn_type = l4csmu_get_dial_mode();

        if (need_reset_flag == KAL_FALSE)
        {
            phb_sat_file_change_confirm(PHB_ERRNO_SUCCESS, sat_file_change_ind->src_id, NULL);
        }
        else if ((phb_ptr->state == PHB_STATE_READY) ||
                 (phb_ptr->state == PHB_STATE_NOT_READY_FDN_READY) || (phb_ptr->state == PHB_STATE_NOT_READY))
        {
         /** 
          * Assume data descriptor obtained from nvram_get_infor() and
          * sim_service_table_query() remains consistent, DO NOT reset it.
          * What needs to be reset is their free_count!
          */
            phb_data_desc_reset();
            
            phb_se_reset();

            /* Reset context */
            kal_mem_set(&phb_ptr->ecc, 0, sizeof(sim_ecc_struct));
            phb_ptr->state = PHB_STATE_NOT_READY;
        #ifdef __PHB_USIM_SUPPORT__
            phb_ptr->is_global = KAL_TRUE;
        #endif
            kal_trace(TRACE_STATE, STATE_PHB_NOT_READY);

            // TODO: need to be able to reload specific files
            /*  
             *  Since SIM file changed, need to reload file info, and MMI also need to reload
             *  send begin inication to MMI, MMI will clear it's variable and reload phonebook.
             */
            {
            #if !defined(__PHB_STORAGE_BY_MMI__)
                kal_uint16 phb_total, phb_size;

                if (nvram_get_info(NVRAM_EF_PHB_LID, &phb_total, &phb_size) == NVRAM_ERRNO_SUCCESS)
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_TRUE);

                /*
                 * MAX_ENTRIES_COUNT must NOT be exceeded. See comment
                 * of phb_get_info_set_value() for detail.
                 */
                    if (phb_total > NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT)
                    {
                        phb_total = NVRAM_PHB_INDEX_MAX_ENTRIES_COUNT;
                    }
                    phb_data_desc_set(DATA_DESC_PHB, phb_total, phb_size);
                }
                else
            #endif /* __PHB_STORAGE_BY_MMI__ */
                {
                    phb_data_desc_set_is_support(DATA_DESC_PHB, KAL_FALSE);
                }
            }
            /* phb_get_info() will return to startup_handler() */
            control_block->proc_stage = startup_none;

        #if defined(__GEMINI__) || defined(GEMINI_PLUS)
            l4csmu_get_chv_info_status(NULL, &chv_status[phb_current_mod - MOD_PHB]);
            phb_query_count[phb_current_mod - MOD_PHB] = 0;
        #else
            l4csmu_get_chv_info_status(NULL, &chv_status[0]);
            phb_query_count[0] = 0;
        #endif
            
            phb_get_info(ilm_ptr, control_block);
            
        }
        /* error */
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

            phb_sat_file_change_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
            return;
        }

    }
    else
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_STATE);

        control_block->cnf_msg_id = MSG_ID_SAT_FILE_CHANGE_IND;
        phb_sat_file_change_confirm(PHB_ERRNO_FAIL, control_block->src_id, control_block);
        return;
    }
}   /* end of phb_sat_file_change_handler function */


/*****************************************************************************
 * FUNCTION
 *  phb_sat_file_change_confirm
 * DESCRIPTION
 *  This is phb_sat_file_change_confirm function of PHB module.
 * PARAMETERS
 *  result              [IN]        
 *  src_id              [IN]        
 *  control_block       [?]         
 *  ilm_ptr(?)          [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_sat_file_change_confirm(phb_errno_enum result, kal_uint8 src_id, control_block_type *control_block)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    local_para_struct *local_param_ptr = NULL;
    sat_file_change_res_struct *sat_file_change_res;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_trace(TRACE_FUNC, FUNC_PHB_SAT_FILE_CHANGE_CNF, result, src_id);

    sat_file_change_res = (sat_file_change_res_struct*) construct_local_para(
                                                            sizeof(sat_file_change_res_struct),
                                                            TD_CTRL);
    sat_file_change_res->src_id = src_id;

    local_param_ptr = (local_para_struct*) sat_file_change_res;

    /* Reject newly received request */
    if (result == PHB_ERRNO_BUSY)
    {
        sat_file_change_res->is_successful = KAL_FALSE;
    }

    else
    {
        sat_file_change_res->is_successful = (result == PHB_ERRNO_SUCCESS) ? KAL_TRUE : KAL_FALSE;

        if (control_block)
        {
            phb_free_control_block(control_block);
        }
    }

    phb_send_ilm(MOD_SIM, MSG_ID_SAT_FILE_CHANGE_RES, local_param_ptr, NULL);
}   /* end of phb_sat_file_change_confirm */

#endif /* __SAT__ */ 

