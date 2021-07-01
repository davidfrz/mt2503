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
 * AvrcpSrvUtil.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#include "MMI_features.h"
#if (defined(__MMI_AVRCP_SUPPORT__) || defined(__MMI_AVRCP_CT_SUPPORT__))

/* General header file */
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"             /* Task message communiction */
#include "xatypes.h"
#include "kal_trace.h"              /* Trace Header Files */

#include "bluetooth_avrcp_struct.h"
#include "kal_general_types.h"
#include "stack_config.h"
#include "stack_ltlcom.h"
#include "kal_public_api.h"
#include "AvrcpSrvUtil.h"

void srv_avrcp_send_msg(module_type src_id, module_type dst_id, kal_uint16 sap_id, 
    kal_uint16 msg_id, void *local_param_ptr, void *peer_buff_ptr)
{
   ilm_struct *ilm_ptr = allocate_ilm(src_id);
   ilm_ptr->src_mod_id = src_id;
   ilm_ptr->dest_mod_id = dst_id;
   ilm_ptr->sap_id = (sap_type)sap_id;
   ilm_ptr->msg_id = (msg_type)msg_id;
   ilm_ptr->local_para_ptr = (local_para_struct*)local_param_ptr;
   ilm_ptr->peer_buff_ptr = (peer_buff_struct*) peer_buff_ptr;

   msg_send_ext_queue(ilm_ptr);
}

// activate
void srv_avrcp_send_activate_req(module_type src_mod_id, kal_uint8 local_role)
{
    bt_avrcp_activate_req_struct* msg_p = (bt_avrcp_activate_req_struct*)
            construct_local_para(sizeof(bt_avrcp_activate_req_struct), TD_CTRL);

    //msg_p->chnl_num = chnl_num;
    msg_p->local_role = local_role;

    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_ACTIVATE_REQ, msg_p, NULL);
}

// deactivate
void srv_avrcp_send_deactivate_req( module_type src_mod_id )
{
    bt_avrcp_deactivate_req_struct* msg_p = (bt_avrcp_deactivate_req_struct*)
            construct_local_para(sizeof(bt_avrcp_deactivate_req_struct), TD_CTRL);

    //msg_p->local_role = local_role;

    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_DEACTIVATE_REQ, msg_p, NULL);
}

// connect
void srv_avrcp_send_connect_req(module_type src_mod_id, bt_avrcp_dev_addr_struct* device_addr, kal_uint8 local_role)
{
    bt_avrcp_connect_req_struct* msg_p = (bt_avrcp_connect_req_struct*)
            construct_local_para(sizeof(bt_avrcp_connect_req_struct), TD_CTRL);

    //msg_p->chnl_num = chnl_num;
    msg_p->local_role = local_role;
    kal_mem_cpy(&msg_p->device_addr, device_addr, sizeof(bt_avrcp_dev_addr_struct));    
    
    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_CONNECT_REQ, msg_p, NULL);
}

// disconnect
void srv_avrcp_send_disconnect_req( module_type src_mod_id, kal_uint8 chnl_num)
{
    bt_avrcp_disconnect_req_struct* msg_p = (bt_avrcp_disconnect_req_struct*)
            construct_local_para(sizeof(bt_avrcp_disconnect_req_struct), TD_CTRL);

    msg_p->chnl_num = chnl_num;

    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_DISCONNECT_REQ, msg_p, NULL);
}

//command frame
void srv_avrcp_send_cmd_frame_req(module_type src_mod_id, kal_uint8 chnl_num, kal_uint8 seq_id, 
    kal_uint8 c_type, kal_uint8 subunit_type, kal_uint8 subunit_id, kal_uint16 data_len, kal_uint8* frame_data)
{
    bt_avrcp_cmd_frame_req_struct* msg_p = (bt_avrcp_cmd_frame_req_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_req_struct), TD_CTRL);

    msg_p->chnl_num = chnl_num;
    msg_p->seq_id = seq_id;
    msg_p->c_type = c_type;
    msg_p->subunit_type = subunit_type;
    msg_p->subunit_id = subunit_id;
    msg_p->data_len = data_len;

    if ((data_len > 0) && (frame_data != NULL))
    {
        kal_mem_cpy(msg_p->frame_data, frame_data, data_len);
    }

    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_CMD_FRAME_REQ, msg_p, NULL);
}

void srv_avrcp_send_cmd_frame_ind_rsp( module_type src_mod_id, U8 chnl_num, kal_uint8 seq_id, 
    kal_uint16 profile_id,kal_uint8 c_type, kal_uint8 subunit_type, kal_uint8 subunit_id, 
    kal_uint16 data_len, kal_uint8* frame_data)
{
    bt_avrcp_cmd_frame_ind_rsp_struct* msg_p = (bt_avrcp_cmd_frame_ind_rsp_struct*)
            construct_local_para(sizeof(bt_avrcp_cmd_frame_ind_rsp_struct), TD_CTRL);

    msg_p->chnl_num = chnl_num;
    msg_p->seq_id = seq_id;
    msg_p->profile_id  = profile_id;    
    msg_p->c_type = c_type;             //0x09;
    msg_p->subunit_type = subunit_type;
    msg_p->subunit_id = subunit_id;
    msg_p->data_len = data_len;

    if ((data_len > 0) && (frame_data != NULL))
    {
        kal_mem_cpy(msg_p->frame_data, frame_data, data_len);
    }

    srv_avrcp_send_msg_to_bt(src_mod_id, (kal_uint16)MSG_ID_BT_AVRCP_CMD_FRAME_IND_RSP, msg_p, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  srv_avrcp_check_cmd_type
 * DESCRIPTION
 *  This function is to check command type
 * PARAMETERS
 *  c_type              [IN]        
 *  subunit_type        [IN]        
 *  subunit_id          [IN]        
 *  data_len            [IN]        
 *  frame_data          [IN]         
 * RETURNS
 *  U16
 *****************************************************************************/
U16 srv_avrcp_check_cmd_type(U8 c_type, U8 subunit_type, U8 subunit_id, U16 data_len, U8 *frame_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_len > 0)
    {
        /* check if pass through command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_PASS_THROUGH) && 
            (frame_data[0] == BT_AVRCP_OP_PASS_THROUGH))
        {
            return BT_AVRCP_OP_PASS_THROUGH;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_UNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_UNIT_INFO) && 
            (frame_data[0] == BT_AVRCP_OP_UNIT_INFO))
        {
            return BT_AVRCP_OP_UNIT_INFO;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_SUBUNIT_INFO) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_SUBUNIT_INFO) && 
            (frame_data[0] == BT_AVRCP_OP_SUBUNIT_INFO))
        {
            return BT_AVRCP_OP_SUBUNIT_INFO;
        }

        /* check if unit info command */
        if ((subunit_type == BT_AVRCP_SUBUNIT_TYPE_PASS_THROUGH) &&
            (subunit_id == BT_AVRCP_SUBUNIT_ID_PASS_THROUGH) && 
            (frame_data[0] == BT_AVRCP_OP_VENDOR))
        {
            return BT_AVRCP_OP_VENDOR;
        }
    }

    return 0;
}

MMI_BOOL srv_avrcp_check_valid_role(U8 role)
{
    return (role == BT_AVRCP_CT || role == BT_AVRCP_TG) ? MMI_TRUE : MMI_FALSE;
}

#endif /* __MMI_AVRCP_SUPPORT__ */

