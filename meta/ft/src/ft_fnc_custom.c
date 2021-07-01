/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_custom.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Misc Function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
 
/*************************************************************************
 * Include Statements for KAL
 *************************************************************************/
 
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"

#ifdef __MTK_TARGET__
#include <stdio.h>

#endif

/*************************************************************************
 * Include Statements for MAUI
 *************************************************************************/

#include "ftc_msg.h"
#include "ft_private.h"


// added in RHR first round
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "fctycomp_config.h"
// added in RHR first round
#include "stack_config.h"
void FT_Custom_Operation(ilm_struct *ptrMsg)
{
    ilm_struct    *ptr_ilm;
    kal_uint16    pdu_length;
    kal_uint8	   *pdu_ptr = NULL;
    //peer_buff_struct *p_peer_buff_ptr;

    kal_uint16	pdu_length_new;
    kal_uint8	*pdu_ptr_new;
    peer_buff_struct *peer_buff_new;

    FT_CUSTOMER_REQ  *p_req = (FT_CUSTOMER_REQ *)ptrMsg->local_para_ptr;

    if(ptrMsg->peer_buff_ptr == NULL)  // do nothing
        return; 

    switch(p_req->type)
    {
        case FT_CUSTOMER_OP_BASIC:
            {

                pdu_ptr = get_pdu_ptr( ptrMsg->peer_buff_ptr, &pdu_length );

                // construct a peer buffer to send to NVRAM
                if( NULL != (peer_buff_new=construct_peer_buff(pdu_length, 0, 0, TD_CTRL)) ) 
                {
                    pdu_ptr_new = get_pdu_ptr( peer_buff_new, &pdu_length_new );
                    kal_mem_cpy(pdu_ptr_new, pdu_ptr, pdu_length);
                    peer_buff_new->pdu_len = pdu_length;
                }
                ptr_ilm = FT_ALLOC_OTHER_MSG( sizeof(ftc_basic_req_struct) );
                ptr_ilm->peer_buff_ptr = peer_buff_new;

                FT_SEND_MSG(MOD_FT, MOD_FTC, FT_FTC_SAP , (msg_type)MSG_ID_FTC_BASIC_REQ, ptr_ilm);

                peer_buff_new=NULL;/* make sure FTC will release the mem*/

                break;
            }
        default:
            break;
    } 

    //peer_buff_struct *p_peer_buff_ptr = ptrMsg->peer_buff_ptr;

    // get the parameter from peer buffer
    //kal_int8 *data_in = (kal_int8*) get_pdu_ptr( p_peer_buff_ptr, &pdu_length );
    //ptr_ilm->peer_buff_ptr = ptrMsg->peer_buff_ptr;

}

void FT_Handle_FTC_CNF(ilm_struct *ptrMsg)
{
    ilm_struct		*ilm_ptr;
    FT_CUSTOMER_CNF  *ptrMsg2;  // send back to PC

    switch (ptrMsg->msg_id)
    {
        case MSG_ID_FTC_BASIC_CNF:
            {
                ftc_basic_cnf_struct *tmp_local_para = NULL;  // from FTC Task
                tmp_local_para = (ftc_basic_cnf_struct*)ptrMsg->local_para_ptr;

                ilm_ptr = FT_ALLOC_MSG( sizeof(FT_CUSTOMER_CNF) );

                ilm_ptr->peer_buff_ptr = ptrMsg->peer_buff_ptr;
                ptrMsg2 = (FT_CUSTOMER_CNF*)ilm_ptr->local_para_ptr;  

                ptrMsg2->header.ft_msg_id = FT_CUSTOM_CNF_ID;
                ptrMsg2->type = FT_CUSTOMER_OP_BASIC; 
                ptrMsg2->status = tmp_local_para->status; //FTC_CNF_OK;
                // for debug   
                sprintf((kal_char *)g_FT_debug_buf, "recv message from ftc");
                tst_sys_trace(g_FT_debug_buf); 
            }
            break;
        default:
            return;

    }
    // send confirm to PC
    FT_SEND_MSG(MOD_FT, MOD_TST, FT_TST_SAP, MSG_ID_FT_TO_TST, ilm_ptr); 	   
    
}
/*
void FT_WriteTo_NVRAM(ft_nvram_write_req_struct_T* req, peer_buff_struct* peer_buff)
{

    ilm_struct *ptr_ilm;
    nvram_write_req_struct *nvram_ptr_loc_para;
    kal_uint16             pdu_length;
    kal_uint8              *pdu_ptr = get_pdu_ptr( peer_buff, &pdu_length );
    ptr_ilm = FT_ALLOC_OTHER_MSG( sizeof(nvram_write_req_struct) );
    nvram_ptr_loc_para=(nvram_write_req_struct *)(ptr_ilm->local_para_ptr);
    nvram_ptr_loc_para->file_idx=req->file_idx;// LID 
    nvram_ptr_loc_para->para=req->para;
    nvram_ptr_loc_para->access_id=0 ; // change it!
    ptr_ilm->peer_buff_ptr = peer_buff;
  
    FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_WRITE_REQ, ptr_ilm);
}

*/
