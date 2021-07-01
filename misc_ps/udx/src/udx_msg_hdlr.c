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
 *  udx_msg_hdlr.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is intended for UDX message handler.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#ifdef __UDX_SUPPORT__

#include "kal_release.h"
#include "stack_common.h"
#include "stack_ltlcom.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "fs_type.h"
#include "mmi2udx_struct.h"
#include "udx_msg_hdlr.h"
#include "udx_parser.h"

#include "kal_non_specific_general_types.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */

static mmi_udx_parse_data_rsp_struct *g_udx_data_rsp;
static kal_bool g_udx_result;

/***************************************************************************** 
 * Global Variable
 *****************************************************************************/
/* Write your global variable here */
/* 
 * Global variable shall be declared in the XxxxProt.h (not XXXGprot.h),
 * it shall be accessible by files within the same module.
 */

kal_bool g_udx_abort_op = KAL_FALSE;

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
 *  udx_send_msg_to_mmi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  msg_id          [IN]        
 *  local_ptr       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
static void udx_send_msg_to_mmi(msg_type msg_id, local_para_struct *local_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ilm_struct *ilm_send = allocate_ilm(MOD_UDX);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ilm_send->msg_id = msg_id;
    ilm_send->local_para_ptr = local_ptr;
    ilm_send->peer_buff_ptr = NULL;
    SEND_ILM(MOD_UDX, MOD_MMI, MMI_UDX_SAP, ilm_send);
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
 *  udx_build_header_req
 * DESCRIPTION
 *  This function is used to process build begin request
 * PARAMETERS
 *  b_req       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_header_req(mmi_udx_build_header_req_struct *b_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_header_rsp_struct *b_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(b_req != NULL);

    if (g_udx_abort_op)
    {
        return;
    }

    b_rsp = (mmi_udx_build_header_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_build_header_rsp_struct), TD_CTRL);

    if (udx_build_header_info(b_req) < 0)
    {
        g_udx_result = KAL_FALSE;
    }
    else
    {
        g_udx_result = KAL_TRUE;
    }

    b_rsp->error_code = g_udx_error_code;
    b_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_BUILD_HEADER_RSP, (local_para_struct*) b_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_data_req
 * DESCRIPTION
 *  This function is used to process build data request
 * PARAMETERS
 *  d_req       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_data_req(mmi_udx_build_data_req_struct *d_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_data_rsp_struct *d_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(d_req != NULL);

    if (g_udx_abort_op)
    {
        return;
    }

    d_rsp = (mmi_udx_build_data_rsp_struct*)
            construct_local_para(sizeof(mmi_udx_build_data_rsp_struct), TD_CTRL);

    if (d_req->data_type == UDX_TYPE_VCARD)
    {
        if (udx_build_vcard_data(d_req) < 0)
        {
            g_udx_result = KAL_FALSE;
        }
        else
        {
            g_udx_result = KAL_TRUE;
        }
    }
    else
    {
        /* Not supported now */
        ASSERT(0);
    }

    d_rsp->error_code = g_udx_error_code;
    d_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_BUILD_DATA_RSP, (local_para_struct*) d_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_end_req
 * DESCRIPTION
 *  This function is used to process build end request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_end_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_end_rsp_struct *e_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_udx_abort_op)
    {
        return;
    }

    e_rsp = (mmi_udx_build_end_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_build_end_rsp_struct), TD_CTRL);

    if (udx_rebuild_header_info() < 0)
    {
        g_udx_result = KAL_FALSE;
    }
    else
    {
        g_udx_result = KAL_TRUE;
    }

    e_rsp->error_code = g_udx_error_code;
    e_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_BUILD_END_RSP, (local_para_struct*) e_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_abort_req
 * DESCRIPTION
 *  This function is used to process build abort request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_abort_rsp_struct *a_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    a_rsp = (mmi_udx_build_abort_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_build_abort_rsp_struct), TD_CTRL);

    if (g_udx_state == UDX_STATE_BUILD_END || !g_udx_result)
    {
        g_udx_state = UDX_STATE_BUILD_ABORT;
        g_udx_error_code = UDX_CODE_NO_ERROR;
    }
    else if (udx_build_abort() < 0)
    {
        /* There is no need to do extra disposal */
    }

    a_rsp->error_code = g_udx_error_code;
    a_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_BUILD_ABORT_RSP, (local_para_struct*) a_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_header_req
 * DESCRIPTION
 *  This function is used to process parse header request
 * PARAMETERS
 *  h_req       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_header_req(mmi_udx_parse_header_req_struct *h_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_header_rsp_struct *h_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(h_req != NULL);

    h_rsp = (mmi_udx_parse_header_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_parse_header_rsp_struct), TD_CTRL);

    udx_header_info_p = &(h_rsp->h_info);
    g_udx_valid_mask = 0;
    memset(udx_header_info_p, 0, sizeof(udx_header_info_struct));

    if (udx_parse_header_info(h_req) < 0)
    {
        g_udx_result = KAL_FALSE;
    }
    else
    {
        g_udx_result = KAL_TRUE;
    }

    h_rsp->error_code = g_udx_error_code;
    h_rsp->state = g_udx_state;
    h_rsp->valid_mask = g_udx_valid_mask;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_PARSE_HEADER_RSP, (local_para_struct*) h_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_body_req
 * DESCRIPTION
 *  This function is used to process parse body request
 * PARAMETERS
 *  b_req       [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_body_req(mmi_udx_parse_body_req_struct *b_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_body_rsp_struct *b_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(b_req != NULL);

    b_rsp = (mmi_udx_parse_body_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_parse_body_rsp_struct), TD_CTRL);

    if (udx_parse_body_data(b_req) < 0)
    {
        g_udx_result = KAL_FALSE;
    }
    else
    {
        g_udx_result = KAL_TRUE;
    }

    b_rsp->error_code = g_udx_error_code;
    b_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_PARSE_BODY_RSP, (local_para_struct*) b_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_data_req
 * DESCRIPTION
 *  This function is used to process parse next data request
 * PARAMETERS
 *  nd_req      [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_data_req(mmi_udx_parse_data_req_struct *data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_data_rsp_struct *data_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ASSERT(data_req != NULL);

    if (data_req->mem_full)
    {
        udx_parse_finish_ind(KAL_TRUE);
        udx_parse_close();
        return;
    }

    data_rsp = (mmi_udx_parse_data_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_parse_data_rsp_struct), TD_CTRL);

    g_udx_data_rsp = data_rsp;
    udx_vcard_data_p = &(data_rsp->u.vcard_data);
    g_udx_valid_mask = 0;
    g_udx_lost_count = 0;
    memset(udx_vcard_data_p, 0, sizeof(udx_vcard_data_struct));

    if (udx_parse_resume() < 0)
    {
        g_udx_result = KAL_FALSE;
        udx_parse_data_rsp(UDX_TYPE_VCARD, 0xFFFF);
    }
    else
    {
        g_udx_result = KAL_TRUE;
    }
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_data_rsp
 * DESCRIPTION
 *  This function is used to process parse data indication
 * PARAMETERS
 *  type    [IN]        
 *  seq     [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_data_rsp(kal_uint8 type, kal_uint16 seq)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_udx_data_rsp->error_code = g_udx_error_code;
    g_udx_data_rsp->state = g_udx_state;
    g_udx_data_rsp->valid_mask = g_udx_valid_mask;
    g_udx_data_rsp->lost_count = g_udx_lost_count;
    g_udx_data_rsp->data_type = type;
    g_udx_data_rsp->sequence = seq;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_PARSE_DATA_RSP, (local_para_struct*) g_udx_data_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_finish_ind
 * DESCRIPTION
 *  This function is used to process parse finish indication
 * PARAMETERS
 *  is_full     [IN]    
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_finish_ind(kal_bool is_full)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_finish_ind_struct *f_ind;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!is_full)
    {
        free_local_para((local_para_struct*) g_udx_data_rsp);
    }
    else
    {
        g_udx_error_code = UDX_CODE_NO_ERROR;
    }

    f_ind = (mmi_udx_parse_finish_ind_struct*)
        construct_local_para(sizeof(mmi_udx_parse_finish_ind_struct), TD_CTRL);

    /* Must set g_udx_state to UDX_STATE_PARSE_FINISH */
    g_udx_state = UDX_STATE_PARSE_FINISH;

    f_ind->error_code = g_udx_error_code;
    f_ind->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_PARSE_FINISH_IND, (local_para_struct*) f_ind);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_abort_req
 * DESCRIPTION
 *  This function is used to process parse abort request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_abort_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_abort_rsp_struct *a_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    a_rsp = (mmi_udx_parse_abort_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_parse_abort_rsp_struct), TD_CTRL);

    if (g_udx_state == UDX_STATE_PARSE_HEADER || g_udx_state == UDX_STATE_PARSE_FINISH || !g_udx_result)
    {
        g_udx_state = UDX_STATE_PARSE_ABORT;
        g_udx_error_code = UDX_CODE_NO_ERROR;
    }
    else if (udx_parse_abort() < 0)
    {
        /* There is no need to do extra disposal */
    }

    a_rsp->error_code = g_udx_error_code;
    a_rsp->state = g_udx_state;

    udx_send_msg_to_mmi(MSG_ID_MMI_UDX_PARSE_ABORT_RSP, (local_para_struct*) a_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_enter_usb_mode
 * DESCRIPTION
 *  This function is used to process usb interrupt
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void udx_enter_usb_mode(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (g_udx_state >= UDX_STATE_BUILD_BEGIN && g_udx_state < UDX_STATE_BUILD_ABORT)
    {
        udx_build_abort_req();
    }

    if (g_udx_state >= UDX_STATE_PARSE_BODY && g_udx_state < UDX_STATE_PARSE_ABORT)
    {
        udx_parse_abort_req();
    }
}

#endif /* __UDX_SUPPORT__ */

/***************************************************************************** 
 * Include 
 *****************************************************************************/
/* Write your #include header file here */

#ifdef __MULTI_VCARD_SUPPORT__

#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "stack_msgs.h"
#include "mmi2udx_struct.h"
#include "vcard_lib.h"
#include "vcard_utility.h"
#include "vcard_parser.h"
#include "vcard_builder.h"

/***************************************************************************** 
 * Static Declaration
 *****************************************************************************/
/* Define your local variable here */
/* Local variable are those variable only be used within this .c file. */



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



/***************************************************************************** 
 * Global Function 
 *****************************************************************************/
/* Write your global function here */
/* 
 * Global function shall be declared in XxxProt.h or XxxGprot.h.
 */


/*****************************************************************************
 * FUNCTION
 *  udx_build_vcard_rsp
 * DESCRIPTION
 *  This function is used to process build vcard response
 * PARAMETERS
 *  dest_id         [IN]        
 *  handle          [IN]        
 *  vb_callback     [IN]        
 *  error_code      [IN]        
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_vcard_rsp(
        kal_int32 dest_id,
        void *handle,
        vcard_builder_callback_type vb_callback,
        kal_int32 error_code,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_build_vcard_rsp_struct *build_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    build_rsp = (mmi_udx_build_vcard_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_build_vcard_rsp_struct), TD_RESET);

    build_rsp->handle = handle;
    build_rsp->vb_callback = vb_callback;
    build_rsp->error_code = error_code;
    build_rsp->user_data = user_data;

    vcard_send_msg_from_udx(dest_id, MSG_ID_MMI_UDX_BUILD_VCARD_RSP, (local_para_struct*) build_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_build_vcard_req
 * DESCRIPTION
 *  This function is used to process build vcard request
 * PARAMETERS
 *  src_id          [IN]        
 *  build_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void udx_build_vcard_req(kal_int32 src_id, mmi_udx_build_vcard_req_struct *build_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_builder_struct *builder = (vcard_builder_struct*) build_req->vb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vcard_is_busying(builder))
    {
        return;
    }

    if (builder->write_length == -1)
    {
        builder->write_length = 0;
        vcard_build_object(builder);
    }
    else
    {
        vcard_build_next_object(builder);
    }

    udx_build_vcard_rsp(src_id, builder, builder->vb_callback, builder->error_code, builder->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_vcard_rsp
 * DESCRIPTION
 *  This function is used to process parse vcard response
 * PARAMETERS
 *  dest_id         [IN]        
 *  handle          [IN]        
 *  vp_callback     [IN]        
 *  error_code      [IN]        
 *  percentage      [IN]        
 *  object          [IN]        
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_vcard_rsp(
        kal_int32 dest_id,
        void *handle,
        vcard_parser_callback_type vp_callback,
        kal_int32 error_code,
        kal_uint16 percentage,
        vcard_object_struct *object,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_parse_vcard_rsp_struct *parse_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    parse_rsp = (mmi_udx_parse_vcard_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_parse_vcard_rsp_struct), TD_RESET);

    parse_rsp->handle = handle;
    parse_rsp->vp_callback = vp_callback;
    parse_rsp->error_code = error_code;
    parse_rsp->percentage = percentage;
    parse_rsp->object = object;
    parse_rsp->user_data = user_data;

    vcard_send_msg_from_udx(dest_id, MSG_ID_MMI_UDX_PARSE_VCARD_RSP, (local_para_struct*) parse_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_parse_vcard_req
 * DESCRIPTION
 *  This function is used to process parse vcard request
 * PARAMETERS
 *  src_id          [IN]        
 *  parse_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void udx_parse_vcard_req(kal_int32 src_id, mmi_udx_parse_vcard_req_struct *parse_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) parse_req->vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vcard_is_busying(parser))
    {
        return;
    }

    if (parser->read_offset == -1)
    {
        vcard_parse_object(parser, -1);
    }
    else
    {
        vcard_parse_next_object(parser);
    }

    udx_parse_vcard_rsp(
        src_id,
        parser,
        parser->vp_callback,
        parser->error_code,
        parser->percentage,
        parser->object,
        parser->user_data);
}


/*****************************************************************************
 * FUNCTION
 *  udx_read_vcard_rsp
 * DESCRIPTION
 *  This function is used to process read vcard response
 * PARAMETERS
 *  dest_id         [IN]        
 *  handle          [IN]        
 *  vp_callback_ex  [IN]        
 *  error_code      [IN]        
 *  object_count    [IN]        
 *  object_offset_list  [IN]        
 *  user_data       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void udx_read_vcard_rsp(
        kal_int32 dest_id,
        void *handle,
        vcard_parser_callback_ex_type vp_callback_ex,
        kal_int32 error_code,
        kal_uint32 object_count,
        kal_int32 *object_offset_list,
        void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_udx_read_vcard_rsp_struct *read_rsp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    read_rsp = (mmi_udx_read_vcard_rsp_struct*)
        construct_local_para(sizeof(mmi_udx_read_vcard_rsp_struct), TD_RESET);

    read_rsp->handle = handle;
    read_rsp->vp_callback_ex = vp_callback_ex;
    read_rsp->error_code = error_code;
    read_rsp->object_count = object_count;
    read_rsp->object_offset_list = object_offset_list;
    read_rsp->user_data = user_data;

    vcard_send_msg_from_udx(dest_id, MSG_ID_MMI_UDX_READ_VCARD_RSP, (local_para_struct*) read_rsp);
}


/*****************************************************************************
 * FUNCTION
 *  udx_read_vcard_req
 * DESCRIPTION
 *  This function is used to process read vcard request
 * PARAMETERS
 *  src_id          [IN]        
 *  parse_req       [?]         
 * RETURNS
 *  void
 *****************************************************************************/
void udx_read_vcard_req(kal_int32 src_id, mmi_udx_read_vcard_req_struct *read_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    vcard_parser_struct *parser = (vcard_parser_struct*) read_req->vp;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!vcard_is_busying(parser))
    {
        return;
    }

    if (parser->object_count < parser->app_buffer_size)
    {
        parser->app_buffer[parser->object_count] = parser->process_char;
        parser->object_count++;

        if (parser->read_offset == -1)
        {
            if (vcard_parse_object(parser, -1) != VCARD_RESULT_MORE)
            {
                //break;
            }
        }
        else
        {
            if (vcard_parse_next_object(parser) != VCARD_RESULT_MORE)
            {
                if (parser->grouping == 0)
                {
                    parser->object_count--;
                }
                //break;
            }
        }
    }

    udx_read_vcard_rsp(
        src_id,
        parser,
        parser->vp_callback_ex,
        parser->error_code,
        parser->object_count,
        parser->app_buffer,
        parser->user_data);
}

#endif /* __MULTI_VCARD_SUPPORT__ */

