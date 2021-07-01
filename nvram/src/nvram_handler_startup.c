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
 * nvram_handler_startup.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is startup handler function of NVRAM module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"

#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h" /* Task message communiction */

#include "nvram_main.h"
#include "nvram_data_items.h"

static void nvram_startup_confirm(
                module_type dest_id,
                nvram_errno_enum result,
                nvram_startup_req_struct *nvram_startup_req);


/*****************************************************************************
 * FUNCTION
 *  nvram_startup_handler
 * DESCRIPTION
 *  This is nvram_startup_handler() function of NVRAM module.
 * PARAMETERS
 *  ilm_ptr     [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_startup_handler(ilm_struct *ilm_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_startup_req_struct *nvram_startup_req;
    nvram_errno_enum result = NVRAM_ERRNO_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_STARTUP);
    nvram_startup_req = (nvram_startup_req_struct*) ilm_ptr->local_para_ptr;

    ASSERT(nvram_startup_req != NULL);

    /* Everything fine. */
    if (nvram_ptr->state == NVRAM_STATE_READY || nvram_ptr->state == NVRAM_STATE_NOT_READY)
    {
        nvram_trace(TRACE_STATE, STATE_NVRAM_READY);

        nvram_ptr->state = NVRAM_STATE_READY;

        /* Check power-on mode */
        if (nvram_startup_req->poweron_mode == NVRAM_POWERON_NORMAL)
        {
            /* nvram_send_ilm(MOD_LAYER1); */
        }

        /* Finally, startup success.. */
        // nvram_startup_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_SUCCESS, nvram_startup_req);
        // Success: Fall through
    }
    /* Fatal error. */
    /* State error */
    else
    {
        nvram_trace(TRACE_ERROR, ERROR_NVRAM_STATE);

        //nvram_startup_confirm(ilm_ptr->src_mod_id, NVRAM_ERRNO_FAIL, nvram_startup_req);
        result = NVRAM_ERRNO_FAIL;
    }

    nvram_startup_confirm(ilm_ptr->src_mod_id, result, nvram_startup_req);
}   /* end of nvram_startup_handler */


/*****************************************************************************
 * FUNCTION
 *  nvram_startup_confirm
 * DESCRIPTION
 *  This is nvram_startup_confirm() function of NVRAM module.
 * PARAMETERS
 *  dest_id                 [IN]        
 *  result                  [IN]        
 *  nvram_startup_req       [?]         
 *  ilm_ptr(?)              [IN]        The primitives
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_startup_confirm(
                module_type dest_id,
                nvram_errno_enum result,
                nvram_startup_req_struct *nvram_startup_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    nvram_startup_cnf_struct *nvram_startup_cnf;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_trace(TRACE_FUNC, FUNC_NVRAM_STARTUP_CNF, result);
    nvram_startup_cnf = (nvram_startup_cnf_struct*) construct_local_para(sizeof(nvram_startup_cnf_struct), TD_CTRL);

    /* Cylen, __FLIGHT_MODE_SUPPORT__ */
    if (result == NVRAM_ERRNO_SUCCESS)
    {
        /* read flight mode status */
        nvram_ltable_entry_struct *ldi;

        nvram_util_get_data_item(&ldi, NVRAM_EF_SYS_CACHE_OCTET_LID);
        result = nvram_read_data_item(ldi, NVRAM_SYS_FLIGHTMODE_STATE, 1, nvram_startup_cnf->data, NVRAM_EF_SYS_CACHE_OCTET_SIZE);
    }

    nvram_startup_cnf->result = result;
    nvram_startup_cnf->access_id = nvram_startup_req->access_id;

    nvram_send_ilm(dest_id, MSG_ID_NVRAM_STARTUP_CNF, nvram_startup_cnf, NULL);

    return;
} 

