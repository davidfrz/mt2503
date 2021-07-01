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
 * phb_main.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is main() function of PHB module.
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
//#include "kal_release.h"        /* Basic data type */

//#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

//#include "syscomp_config.h"
//#include "task_config.h"        /* Task creation */

#include "kal_trace.h"
#include "phb_trc.h"

#include "sim_common_enums.h"
// #include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

//#include "l4_common.h"
#include "ps2sim_struct.h"

//#include "l4c2phb_enums.h"
#include "l4c2phb_struct.h"

//#include "nvram.h"

/* Prerequisite of phb_context.h */
#include "phb_defs.h"
#include "phb_control_block.h"
//#include "phb_config.h"
#include "phb_data_desc.h"
//#include "phb_data_entry_table.h"
//#include "phb_pindex.h"
//#include "phb_name_num_index.h"
#include "phb_se.h"

#include "phb_context.h"
#include "phb_utils.h"

#include "phb_handler_startup.h"
#include "phb_handler_read.h"
#include "phb_handler_write.h"
#include "phb_handler_delete.h"
#include "phb_handler_search.h"
#include "phb_handler_approve.h"
#include "phb_handler_sat.h"
#include "phb_main.h"
#include "phb_handler_delete_ln.h"
#include "phb_handler_read_ln.h"
#include "phb_handler_write_ln.h"
#include "phb_handler_startup_ln.h"

#include "kal_general_types.h"
#include "nvram_struct.h"

#undef  _FILE_CODE_
#define _FILE_CODE_ _PHB_MAIN_C_

/* phb */
extern phb_context_type phb_context[];
extern phb_context_type *phb_ptr;
extern kal_int32 phb_query_count[];

/*****************************************************************************
 * FUNCTION
 *  phb_main
 * DESCRIPTION
 *  This is main() function of PHB module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void phb_main(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 access_id = (kal_uint8) PHB_INVALID_VALUE;
    control_block_type *control_block = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ilm_ptr == NULL)
    {
        return;
    }

    if ((ilm_ptr->msg_id == MSG_ID_NVRAM_READ_CNF) ||
        (ilm_ptr->msg_id == MSG_ID_NVRAM_WRITE_CNF) ||
    #ifdef __PHB_DELETE_ALL_TURBO__ 
        (ilm_ptr->msg_id == MSG_ID_NVRAM_RESET_CNF)||
    #endif
        (ilm_ptr->msg_id == MSG_ID_SIM_FILE_INFO_CNF) ||
        (ilm_ptr->msg_id == MSG_ID_SIM_READ_CNF) || 
        (ilm_ptr->msg_id == MSG_ID_SIM_WRITE_CNF))
    {
    #if 0 /* enhance ID to replace drop cnf */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        switch (ilm_ptr->msg_id)
        {
            case MSG_ID_NVRAM_READ_CNF:
                access_id = ((nvram_read_cnf_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;

            case MSG_ID_NVRAM_WRITE_CNF:
                access_id = ((nvram_write_cnf_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;

            case MSG_ID_SIM_FILE_INFO_CNF:
                access_id = ((sim_file_info_req_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;

            case MSG_ID_SIM_READ_CNF:
                access_id = ((sim_read_cnf_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;

            case MSG_ID_SIM_WRITE_CNF:
                access_id = ((sim_write_cnf_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;
        #ifdef __PHB_DELETE_ALL_TURBO__ 
            case MSG_ID_NVRAM_RESET_CNF:
                access_id = ((nvram_reset_cnf_struct*) ilm_ptr->local_para_ptr)->access_id;
                break;
        #endif /* __PHB_DELETE_ALL_TURBO__ */
            default:
                break;
        }

        if (((access_id & 0x0F) < PHB_CONCURRENCY_DEGREE) &&
            ((control_block = &phb_ptr->control_block[(access_id & 0x0F)])->IO_cnf_receive != NULL) &&
            control_block->ID == access_id)
            /* call control_block.IO_cnf_receive */
        {
            (*control_block->IO_cnf_receive) (ilm_ptr, control_block);
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
            /* consume abnormal_cnf */
            return;
        }
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_INIT_LN_REQ)
    {
        phb_ptr->state = PHB_STATE_LN_NOT_READY;
        kal_trace(TRACE_STATE, STATE_PHB_LN_NOT_READY);
        //reset all control blocks while receiving the first msg
        phb_reset_all_control_blocks();
    #if !defined(__PHB_NO_CALL_LOG__)
    #ifdef __PHB_RECORD_LN_TYPE_SEQ__
        kal_trace(TRACE_STATE, STATE_PHB_DEFINE_RECORD_LN_TYPE_SEQ);
        phb_startup_sync_ln_type_seq(NULL, NULL);
    #else /* __PHB_RECORD_LN_TYPE_SEQ__ */
        kal_trace(TRACE_STATE, STATE_PHB_NOT_DEFINE_RECORD_LN_TYPE_SEQ);
        phb_startup_erase_ln(ilm_ptr, NULL);
    #endif /* __PHB_RECORD_LN_TYPE_SEQ__ */
    #else /* !defined(__PHB_NO_CALL_LOG__) */
        phb_no_call_log_init_ln_handler(ilm_ptr, NULL);
    #endif /* !defined(__PHB_NO_CALL_LOG__) */
    }
#ifdef __CANCEL_LOCK_POWERON__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_INIT_ME_LN_REQ)
    {
        phb_ptr->state = PHB_STATE_LN_NOT_READY;
        kal_trace(TRACE_STATE, STATE_PHB_LN_NOT_READY);
        //reset all control blocks while receiving the first msg
        phb_reset_all_control_blocks();
        phb_init_me_ln_handler();
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_INIT_ME_PHB_REQ)
    {
        phb_ptr->state = PHB_STATE_NOT_READY;
        kal_trace(TRACE_STATE, STATE_PHB_NOT_READY);

        phb_init_me_phb_handler(ilm_ptr, NULL);
    }
#endif /* __CANCEL_LOCK_POWERON__ */
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_STARTUP_REQ)
    {
        phb_ptr->state = PHB_STATE_NOT_READY;
        kal_trace(TRACE_STATE, STATE_PHB_NOT_READY);

        phb_startup_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_READ_REQ)
    {
        phb_read_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_WRITE_REQ)
    {
        phb_write_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_DELETE_REQ)
    {
        phb_delete_handler(ilm_ptr, NULL);
    }
#ifdef __PHB_SORT_ENABLE__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_SEARCH_REQ)
    {
        phb_search_handler(ilm_ptr, NULL);
    }
#endif /* __PHB_SORT_ENABLE__ */
#ifdef __PHB_FDN_GET_NAME__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_FDN_GET_NAME_REQ)
    {
        phb_fdn_get_name_handler(ilm_ptr, NULL);
    }
#endif /* __PHB_FDN_GET_NAME__ */
#ifndef __PHB_STORAGE_BY_MMI__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_APPROVE_REQ)
    {
        phb_approve_handler(ilm_ptr, NULL);
    }
#endif /* __PHB_STORAGE_BY_MMI__ */
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_SYNC_REQ)
    {
        phb_sync_handler(ilm_ptr, NULL);
    }
#if !defined(__PHB_NO_CALL_LOG__)
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_WRITE_LN_REQ)
    {
        phb_write_ln_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_READ_LN_REQ)
    {
        phb_read_ln_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_DELETE_LN_REQ)
    {
        phb_delete_ln_handler(ilm_ptr, NULL);
    }
#endif /* !defined(__PHB_NO_CALL_LOG__) */
#ifdef __PHB_ACCESS_SIM_LN__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_WRITE_SIM_LN_REQ)
    {
        phb_write_sim_ln_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_READ_SIM_LN_REQ)
    {
        phb_read_sim_ln_handler(ilm_ptr, NULL);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_DELETE_SIM_LN_REQ)
    {
        phb_delete_sim_ln_handler(ilm_ptr, NULL);
    }
#endif /* __PHB_ACCESS_SIM_LN__ */
#ifdef __REL5__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_UPDATE_NW_ECC_REQ)
    {
        phb_update_nw_ecc_list_handler(ilm_ptr, NULL);
    }
#endif /* __REL5__ */
#ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_CHECK_WRITE_USIM_ENTRY_REQ)
    {
        phb_check_write_usim_handler(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_WRITE_USIM_REQ)
    {
        phb_write_usim_handler(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_READ_USIM_REQ)
    {
        phb_read_usim_handler(ilm_ptr);
    }
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_DELETE_USIM_REQ)
    {
        phb_delete_usim_handler(ilm_ptr);
    }
#endif /* __PHB_USIM_ADDITIONAL_SUPPORT__ */

#ifdef __SAT__
    else if (ilm_ptr->msg_id == MSG_ID_SAT_FILE_CHANGE_IND)
    {
        phb_sat_file_change_handler(ilm_ptr, NULL);
    }
#endif /* __SAT__ */ 

    /*  
     *   If it a ADN record, wait for MMI response to continue to read next entry. 
     */
    else if (ilm_ptr->msg_id == MSG_ID_L4CPHB_STARTUP_READ_NEXT_REQ)
    {
        access_id = ((l4cphb_startup_read_next_req_struct*) ilm_ptr->local_para_ptr)->access_id;
        if ((access_id & 0x0F) < PHB_CONCURRENCY_DEGREE
        #ifdef _SPEEDUP_PHB            
            && phb_ptr->state != PHB_STATE_READY
        #endif            
            )
        {
            control_block = &phb_ptr->control_block[(access_id & 0x0F)];
            
            if (control_block->proc_stage == startup_build_index)
            {
                phb_build_next(NULL, control_block);
            }
            return;
        }
        else
        {
            kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
            /* consume abnormal_cnf */
            return;
        }

    }

    else
    {
        kal_trace(TRACE_ERROR, ERROR_PHB_ABNORMAL);
        /* consume abnormal primitives */
        return;
    }
}   /* end of module main function */


/*****************************************************************************
 * FUNCTION
 *  phb_init
 * DESCRIPTION
 *  This is init() function of PHB module.
 *  This function initialize all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma push
#pragma arm section code="DYNAMIC_COMP_MAUIINIT_SECTION"
#endif

kal_bool phb_init()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (; i < PHB_SIM_NUM; i++)
    {
        phb_ptr = &phb_context[i];
        if (i == 0)
        {
            phb_ptr->data_desc[DATA_DESC_PHB].free_bitmap = &free_bitmap_NVRAM_PHB[0];
        }
        else
        {
            phb_ptr->data_desc[DATA_DESC_PHB].free_bitmap = NULL;
        }
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        phb_ptr->data_desc[DATA_DESC_ADN].free_bitmap = free_bitmap_ADN[i][0];
    #else
        phb_ptr->data_desc[DATA_DESC_ADN].free_bitmap = free_bitmap_ADN[i];
    #endif
        phb_ptr->data_desc[DATA_DESC_FDN].free_bitmap = free_bitmap_FDN[i];
        phb_ptr->data_desc[DATA_DESC_BDN].free_bitmap = free_bitmap_BDN[i];
        phb_ptr->data_desc[DATA_DESC_MSISDN].free_bitmap = free_bitmap_MSISDN[i];
        phb_ptr->data_desc[DATA_DESC_SDN].free_bitmap = NULL;
        phb_ptr->data_desc[DATA_DESC_EXT1].free_bitmap = free_bitmap_EXT1[i];
        phb_ptr->data_desc[DATA_DESC_EXT2].free_bitmap = free_bitmap_EXT2[i];
        phb_ptr->data_desc[DATA_DESC_EXT3].free_bitmap = NULL;
        phb_ptr->data_desc[DATA_DESC_EXT4].free_bitmap = free_bitmap_EXT4[i];
    #ifdef __PHB_USIM_SUPPORT__        
        phb_ptr->data_desc[DATA_DESC_EXT5].free_bitmap = free_bitmap_EXT5[i];
    #ifdef __PHB_USIM_ADDITIONAL_SUPPORT__
        phb_ptr->data_desc[DATA_DESC_AAS].free_bitmap = free_bitmap_AAS[i];
        phb_ptr->data_desc[DATA_DESC_GAS].free_bitmap = free_bitmap_GAS[i];
    #endif
    #endif /* __PHB_USIM_SUPPORT__ */ 
        phb_ptr->drop_cnf = KAL_FALSE;

        phb_data_desc_new();

        /* initlialize search engine */
        phb_se_new(i);

        phb_context_reset();
    }
    
#if defined(__PHB_FDN_GET_NAME__) || defined(__ECALL_SUPPORT__)
    phb_init_fdn_context();
#endif /* __PHB_FDN_GET_NAME__ */

#if defined(__ECALL_SUPPORT__)
    phb_init_sdn_context();
#endif /* __PHB_FDN_GET_NAME__ */

    return KAL_TRUE;
}   /* end of phb_init function */
#if defined(__MTK_TARGET__) && defined(__DCM_WITH_COMPRESSION_MAUI_INIT__)
#pragma arm section code
#pragma pop
#endif


/*****************************************************************************
 * FUNCTION
 *  phb_reset
 * DESCRIPTION
 *  This is reset() function of PHB module.
 *  This function resets all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool phb_reset(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint8 curr_sim = phb_which_sim_ex();

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* if (phb_ptr->control_block[0].IO_stage == IO_WAIT ||
       phb_ptr->control_block[1].IO_stage == IO_WAIT ||
       phb_ptr->control_block[0].IO_stage == IO_REASSEMBLY||
       phb_ptr->control_block[1].IO_stage == IO_REASSEMBLY)
       {
       phb_ptr->drop_cnf = KAL_TRUE;
       } */

    phb_data_desc_reset();
    phb_se_reset();

    phb_context_reset();
    phb_query_count[curr_sim] = 0;

    return KAL_TRUE;
}   /* end of phb_reset function */


/*****************************************************************************
 * FUNCTION
 *  phb_reset_for_init
 * DESCRIPTION
 *  This is reset() function of PHB module.
 *  This function resets all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool phb_reset_for_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __GEMINI__
/* under construction !*/
#endif
   phb_reset();

#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
#endif
   
#if defined(GEMINI_PLUS) && (GEMINI_PLUS >= 3)
    phb_context_selection(SIM3);
    phb_reset();
#if defined(GEMINI_PLUS) && (GEMINI_PLUS >= 4)
    phb_context_selection(SIM4);
    phb_reset();
#endif
#endif

   return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  phb_deinit
 * DESCRIPTION
 *  This is deinit() function of PHB module.
 *  This function finalize all the context variables required for PHB module
 * PARAMETERS
 *  void
 * RETURNS
 *  True if succeed.
 *****************************************************************************/
kal_bool phb_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}   /* end of phb_init function */

