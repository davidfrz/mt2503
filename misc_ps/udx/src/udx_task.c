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
 *  udx_task.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX task.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#if defined(__UDX_SUPPORT__) || defined(__MULTI_VCARD_SUPPORT__)

#include "kal_general_types.h"
#include "mmi_frm_queue_gprot.h"
#include "stack_config.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "mmi2udx_struct.h"
#include "udx_msg_hdlr.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */



/* Declare your local function here */



/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */
/* 
 * Global variable shall be declared in the XxxxProt.h (not XXXGprot.h),
 * it shall be accessible by files within the same module.
 */



/***************************************************************************** 
 * Local Function
 *****************************************************************************/
/* Write your local function here */
/*
 * Local function can only be called within this .C file, it shall be declared as static.
 */


#define LOCAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  udx_task_main
 * DESCRIPTION
 *  This function is used to receive udx task's message id from external queue
 * PARAMETERS
 *  task_entry_ptr      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_task_main(task_entry_struct *task_entry_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct current_ilm;
    kal_uint32 my_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_get_my_task_index(&my_index);

    while (1)
    {
        receive_msg_ext_q_for_stack(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm);
        stack_set_active_module_id(my_index, current_ilm.dest_mod_id);

        switch (current_ilm.msg_id)
        {
        #if defined(__UDX_SUPPORT__)
            case MSG_ID_MMI_UDX_BUILD_HEADER_REQ:
                g_udx_abort_op = KAL_FALSE;
                udx_build_header_req((mmi_udx_build_header_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_BUILD_DATA_REQ:
                udx_build_data_req((mmi_udx_build_data_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_BUILD_END_REQ:
                udx_build_end_req();
                break;

            case MSG_ID_MMI_UDX_BUILD_ABORT_REQ:
                g_udx_abort_op = KAL_TRUE;
                udx_build_abort_req();
                break;

            case MSG_ID_MMI_UDX_PARSE_HEADER_REQ:
                udx_parse_header_req((mmi_udx_parse_header_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_PARSE_BODY_REQ:
                udx_parse_body_req((mmi_udx_parse_body_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_PARSE_DATA_REQ:
                udx_parse_data_req((mmi_udx_parse_data_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_PARSE_ABORT_REQ:
                udx_parse_abort_req();
                break;
        #endif /* defined(__UDX_SUPPORT__) */

        #if defined(__MULTI_VCARD_SUPPORT__)
            case MSG_ID_MMI_UDX_BUILD_VCARD_REQ:
                udx_build_vcard_req(current_ilm.src_mod_id, (mmi_udx_build_vcard_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_PARSE_VCARD_REQ:
                udx_parse_vcard_req(current_ilm.src_mod_id, (mmi_udx_parse_vcard_req_struct*) current_ilm.local_para_ptr);
                break;

            case MSG_ID_MMI_UDX_READ_VCARD_REQ:
                udx_read_vcard_req(current_ilm.src_mod_id, (mmi_udx_read_vcard_req_struct*) current_ilm.local_para_ptr);
                break;
        #endif /* defined(__MULTI_VCARD_SUPPORT__) */

            default:
                ASSERT(0);
                break;
        }

        mmi_free_msg(&current_ilm);
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_task_init
 * DESCRIPTION
 *  This function is used to init udx task
 * PARAMETERS
 *  task_index      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
static kal_bool udx_task_init(task_indx_type task_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return KAL_TRUE;
}

/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* Write your global function here */
/* 
 * Global function shall be declared in XxxProt.h or XxxGprot.h.
 */


#define GLOBAL_FUNCTION
/*****************************************************************************
 * FUNCTION
 *  udx_create
 * DESCRIPTION
 *  This function is used to create udx task
 * PARAMETERS
 *  handle      [IN]        
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_bool udx_create(comptask_handler_struct **handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    static const comptask_handler_struct udx_handler_info = 
    {
        udx_task_main,  /* task entry function */
        udx_task_init,  /* task initialization function */
        NULL,           /* task configuration function */
        NULL,           /* task reset handler */
        NULL            /* task termination handler */
    };

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    *handle = (comptask_handler_struct*) (&udx_handler_info);
    return KAL_TRUE;
}

#endif /* defined(__UDX_SUPPORT__) || defined(__MULTI_VCARD_SUPPORT__) */

