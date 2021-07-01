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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   rr.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  RR related message identity definition
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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


/*---------------RR_MSG_CODE_BEGIN-------------------*/

    /*-------------------------- RLC_MSG_CODE_BEGIN --------------------------*/
    MSG_ID_GRR_DATA_REQ = MSG_ID_RLC_CODE_BEGIN,
    MSG_ID_GRR_UNITDATA_REQ,
    MSG_ID_GRR_FLUSH_REQ,
    MSG_ID_MAC_RLC_UL_CON_IND,
#ifndef __MTK_TARGET__
    MSG_ID_MAC_RLC_DATA_REQ,
    MSG_ID_MAC_TIMER_EVENT_IND,
    MSG_ID_MAC_NEXT_OUTGOING_RRBP_IND,
#endif
    MSG_ID_MAC_RLC_ACK_IND,
    MSG_ID_MAC_RLC_SWITCH_TO_DL,
    MSG_ID_MAC_RLC_READY_IND,
    MSG_ID_MAC_RLC_PDCH_REL_IND,

    MSG_ID_RATCM_GAS_READY_TIMER_UPDATE_REQ,
  
    MSG_ID_MAC_RLC_REL_CNF,
    MSG_ID_RATCM_GAS_CELL_UPDATED_REQ,
    MSG_ID_MAC_RLC_ACCESS_REJECT_IND,

    MSG_ID_MAC_RLC_SWITCH_TO_UL,
    MSG_ID_RLC_DL_CODE_BEGIN = MSG_ID_MAC_RLC_SWITCH_TO_UL,
    MSG_ID_MAC_RLC_DL_CON_IND,

#ifndef __MTK_TARGET__
    MSG_ID_MAC_RLC_DL_DATA_IND,
    MSG_ID_MAC_RLC_ACK_REQ,
#endif

    MSG_ID_REASM_RLC_REASM_DONE_IND,

    MSG_ID_RATCM_GAS_START_TEST_MODE_REQ,    

    MSG_ID_MAC_RLC_TBF_REL_IND,
    MSG_ID_RLC_COMMON_CODE_BEGIN = MSG_ID_MAC_RLC_TBF_REL_IND,
#ifdef __PS_HO__
    MSG_ID_MAC_RLC_PS_HO_START_IND,
    MSG_ID_MAC_RLC_PS_HO_SUCCESS_IND,
    MSG_ID_MAC_RLC_PS_HO_FAIL_IND,    
    MSG_ID_RLC_CODE_END = MSG_ID_MAC_RLC_PS_HO_FAIL_IND,
#else
    MSG_ID_RLC_CODE_END = MSG_ID_MAC_RLC_TBF_REL_IND,
#endif
    

    /*-------------------------- RRM_MSG_CODE_BEGIN --------------------------*/

    MSG_ID_SIM_RR_READY_IND = MSG_ID_RRM_COMMON_CODE_BEGIN,
    
    MSG_ID_RATCM_GAS_ADD_FORBIDDEN_LA_REQ,
    MSG_ID_RATCM_GAS_DEACTIVATE_REQ,
    MSG_ID_RATCM_GAS_DEL_FORBIDDEN_LA_REQ,
    MSG_ID_RATCM_GAS_EQ_PLMN_LIST_UPDATE_REQ,
    MSG_ID_RATCM_GAS_INIT_REQ,
    MSG_ID_RATCM_GAS_PAGING_PARAM_ASSIGN_REQ,
    MSG_ID_RATCM_GAS_REGN_STATUS_UPDATE_REQ,
    MSG_ID_RATCM_GAS_RFOFF_REQ,
    MSG_ID_RATCM_GAS_RFON_REQ,
    MSG_ID_RATCM_GAS_SET_RAT_MODE_REQ,
    MSG_ID_RATCM_GAS_SIM_INFO_RESET_REQ,
    MSG_ID_RATCM_GAS_TLLI_ASSIGN_REQ,
    MSG_ID_RATCM_GAS_HPLMN_INFO_UPDATE_REQ, //mtk02475: MAUI_02456964
    MSG_ID_RATCM_GAS_SET_PREFERRED_BAND_REQ,
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    MSG_ID_RATCM_GAS_SET_GPRS_TRANSFER_PREFERENCE_REQ,
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

#ifdef __GEMINI__
#ifdef __PS_SERVICE__
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
#endif

#if defined(__GEMINI_GSM__) && defined( __UMTS_RAT__)
/* under construction !*/
#endif

    MSG_ID_MPAL_RR_SET_RAT_SERVICE_CNF,
    MSG_ID_MPAL_RR_BSIC_SYNC_CNF,
    MSG_ID_MPAL_RR_NEIGHBOR_BSIC_IND,
    MSG_ID_MPAL_RR_CELL_BSIC_IND,
    MSG_ID_MPAL_RR_DATA_IND,
    MSG_ID_MPAL_RR_CELL_SELECTION_INIT_CNF,

#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    MSG_ID_RRM_COMMON_CODE_END = MSG_ID_MPAL_RR_CELL_SELECTION_INIT_CNF,
#endif


    /*-------------------------- RCS_MSG_CODE_BEGIN --------------------------*/
    
    MSG_ID_RATCM_GAS_PLMN_LIST_REQ = MSG_ID_RCS_CODE_BEGIN,
    MSG_ID_RATCM_GAS_PLMN_LIST_STOP_REQ,
    MSG_ID_RATCM_GAS_PLMN_SEARCH_REQ,

    MSG_ID_MPAL_RR_SEARCH_RF_CNF,
    
#if defined(__UMTS_RAT__)&&defined(__GEMINI__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
    MSG_ID_RCS_CODE_END = MSG_ID_MPAL_RR_SEARCH_RF_CNF,
#endif /* defined(__UMTS_RAT__)&&defined(__GEMINI__) */



    /*------------------------- RMPC_MSG_CODE_BEGIN --------------------------*/

    MSG_ID_RATCM_GAS_CONN_EST_REQ = MSG_ID_RMPC_CODE_BEGIN, 
    MSG_ID_RATCM_GAS_CONN_REL_REQ,
    MSG_ID_RATCM_GAS_CONN_ABORT_REQ, /*ZY: add for user mo abort request*/
    MSG_ID_RATCM_GAS_DATA_REQ,
    MSG_ID_RATCM_GAS_SECURITY_MODE_REQ,
    MSG_ID_RATCM_GAS_SERVICE_CHANGE_REQ,
    MSG_ID_RATCM_GAS_CBCH_REQ,           
    MSG_ID_RATCM_GAS_CB_UPDATE_REQ, 

#ifdef __AGPS_CONTROL_PLANE__
    MSG_ID_RRLP_GAS_DATA_REQ,
#else
    /* NULL */
#endif

    MSG_ID_MAC_RMPC_CTRL_MSG_IND,
    MSG_ID_MAC_RMPC_PKT_ACCESS_REQ,
    MSG_ID_MAC_RMPC_ACCESS_RESULT_IND,
    MSG_ID_MAC_RMPC_ENTER_IDLE_REQ,
    
    MSG_ID_MAC_RMPC_DL_ASSIGN_RESULT_IND,
    MSG_ID_MAC_RMPC_TBF_STATUS_IND,
    MSG_ID_MAC_RMPC_CTRL_MSG_CNF,
    MSG_ID_MAC_RMPC_PS_HANDOVER_MSG_IND,
    MSG_ID_MAC_RMPC_PS_HANDOVER_CONNECT_IND,
    MSG_ID_MAC_RMPC_PS_HANDOVER_RESULT_IND,
    MSG_ID_MAC_RMPC_PS_HANDOVER_RECONNECT_IND,
    MSG_ID_MAC_RMPC_PS_HANDOVER_RSP_IND,
    MSG_ID_RLC_RMPC_RESEL_REQ,
    MSG_ID_RLC_RMPC_MS_STATE_CHANGE_IND,

    MSG_ID_MPAL_RR_NEIGHBOR_MEAS_IND,
    MSG_ID_MPAL_RR_NC_MEASUREMENT_IND,
    MSG_ID_MPAL_RR_EXTENDED_MEAS_IND,
    MSG_ID_MPAL_RR_SERV_IDLE_MEAS_IND,
    MSG_ID_MPAL_RR_SERV_DEDI_MEAS_IND,
    
#ifdef __PKT_EXT_MEAS__
    MSG_ID_MPAL_RR_PKT_EXT_MEASUREMENT_IND,
#endif /*__PKT_EXT_MEAS__*/

#ifdef __GEMINI__
#if 0 /*RSVAS migration */
/* under construction !*/
/* under construction !*/
#endif /* 0 */   
/* under construction !*/
#endif /*__GEMINI__ */

#ifndef __MTK_TARGET__
    MSG_ID_MPAL_RR_DETECT_PAGING_BLOCK_CALLBACK_REQ,
#endif

    MSG_ID_MPAL_RR_RACH_CNF,
    MSG_ID_MPAL_RR_HANDOVER_FAIL_IND,
    MSG_ID_MPAL_RR_HANDOVER_SUCCESS_IND,
    MSG_ID_MPAL_RR_HANDOVER_CONNECT_IND,
    MSG_ID_MPAL_RR_DEDICATED_CHANNEL_CONNECT_CNF,
    MSG_ID_MPAL_RR_DEDICATED_CHANNEL_DISCONNECT_CNF,
    MSG_ID_MPAL_RR_DEDICATED_CHANNEL_RECONNECT_CNF,
    MSG_ID_MPAL_RR_FREQUENCY_REDEFINITION_CNF,
    MSG_ID_MPAL_RR_CHANNEL_MODE_MODIFY_CNF,
    MSG_ID_MPAL_RR_CIPHERING_MODE_COMMAND_CNF,
    MSG_ID_MPAL_RR_CLOSE_TCH_LOOP_CNF,
    MSG_ID_MPAL_RR_OPEN_TCH_LOOP_CNF,
#ifdef __NORMAL_MODE_CAPID_CAL_SUPPORT__
    MSG_ID_MPAL_RR_ENTER_CAPID_CAL_MODE_CNF,
    MSG_ID_MPAL_RR_LEAVE_CAPID_CAL_MODE_CNF,
    MSG_ID_MPAL_RR_QUERY_CAPID_CAL_RESULT_CNF,
    MSG_ID_RMP_MSG_CODE_END = MSG_ID_MPAL_RR_QUERY_CAPID_CAL_RESULT_CNF,
#else
    MSG_ID_RMP_MSG_CODE_END = MSG_ID_MPAL_RR_OPEN_TCH_LOOP_CNF,
#endif /* __NORMAL_MODE_CAPID_CAL_SUPPORT__ */
  
    MSG_ID_LAPDM_RR_ESTB_CONF,
    MSG_ID_LAPDM_RR_ESTB_IND,
    MSG_ID_LAPDM_RR_REL_IND,
    MSG_ID_LAPDM_RR_REL_CONF,
    MSG_ID_LAPDM_RR_SUS_CONF,
    MSG_ID_LAPDM_RR_RESUME_CONF,
    MSG_ID_LAPDM_RR_RECON_CONF,
    MSG_ID_LAPDM_RR_DATA_IND,
    MSG_ID_LAPDM_RR_UNITDATA_IND,
    MSG_ID_LAPDM_RR_ERROR_IND,
    
#ifdef __UMTS_RAT__
/* under construction !*/
#endif

    MSG_ID_LAPDM_RR_DATA_CONF,
    MSG_ID_RMPC_CODE_END = MSG_ID_LAPDM_RR_DATA_CONF,
  

    /*------------------- MSG_ID_RRM_MPAL_DM_CODE_BEGIN ----------------------*/
    
#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*-------------------------- MAC_MSG_CODE_BEGIN --------------------------*/
    MSG_ID_RLC_MAC_RES_REQ = MSG_ID_MAC_CODE_BEGIN,
    MSG_ID_RLC_MAC_TBF_REL_REQ,
    MSG_ID_RLC_MAC_UL_DATA_IND,
    MSG_ID_RLC_MAC_ACK_RES,
/* Evelyn 20090415: Merge R6 */
    MSG_ID_RMPC_MAC_CTRL_MSG_REQ,
    MSG_ID_RMPC_MAC_CTRL_MSG_DELETE_REQ,
    MSG_ID_RMPC_MAC_UL_ASSIGN_IND,
    MSG_ID_RMPC_MAC_DL_ASSIGN_IND,
    MSG_ID_RMPC_MAC_SUSPEND_TBF_REQ,
    MSG_ID_RMPC_MAC_RESUME_TBF_REQ,
    MSG_ID_RMPC_MAC_SI_INFO_READY_IND,
//  Evelyn Add for PS HANDOVER
    MSG_ID_RMPC_MAC_PS_HANDOVER_REQ,
    MSG_ID_RMPC_MAC_PS_HANDOVER_ERROR_RSP,
    MSG_ID_MPAL_RR_PS_HANDOVER_CNF,
    MSG_ID_MPAL_RR_PS_HANDOVER_RECONNECT_CNF,
    

    MSG_ID_MPAL_RR_TRANSFER_DATA_IND,
    MSG_ID_MPAL_RR_EGPRS_TRANSFER_DATA_IND,
    MSG_ID_MPAL_RR_READY_TO_SEND_IND,
    MSG_ID_MPAL_RR_PDTCH_DISCONN_CNF,
    MSG_ID_MPAL_RR_CCCH_RRBP_CNF,
  
#if  defined(__MTK_TARGET__) && (!defined(__MAC_SHOW_TRANS_DATA__))
    /* NULL */
#else
    MSG_ID_RMPC_MAC_CELL_STATUS_IND, 
#endif

#if (!defined(__MTK_TARGET__)) && (defined (__GERAN_RTTI__) || defined(__GERAN_FANR__))
    MSG_ID_MPAL_RR_TRANSFER_DATA_NOTICE_IND,
#endif

    MSG_ID_MAC_MAC_TRANS_DATA_IND,


    MSG_ID_MPAL_RR_EGPRS_LOOP_CNF,
    MSG_ID_MPAL_RR_PDTCH_CONNECT_IND,
    
    MSG_ID_MAC_RMPC_COMMON_CODE_BEGIN = MSG_ID_MPAL_RR_PDTCH_CONNECT_IND,
    MSG_ID_MPAL_RR_INT_MEASUREMENT_IND,
    MSG_ID_MAC_RMPC_COMMON_CODE_END = MSG_ID_MPAL_RR_INT_MEASUREMENT_IND,
    
    MSG_ID_MAC_CODE_END = MSG_ID_MAC_RMPC_COMMON_CODE_END,
  
    /*------------------------- LAPDM_MSG_CODE_BEGIN -------------------------*/
    MSG_ID_RR_LAPDM_DATA_REQ = MSG_ID_LAPDM_CODE_BEGIN,
    MSG_ID_RR_LAPDM_UNITDATA_REQ,
#ifdef __AGPS_CONTROL_PLANE__
    MSG_ID_RR_LAPDM_APP_DATA_REQ,
    MSG_ID_RR_LAPDM_CLEAR_APP_QUEUE_REQ,
#else
    /* NULL */
#endif    
    MSG_ID_RR_LAPDM_ESTB_REQ,
    MSG_ID_RR_LAPDM_SUS_REQ,
    MSG_ID_RR_LAPDM_RESUME_REQ,
    MSG_ID_RR_LAPDM_RECON_REQ,
    MSG_ID_RR_LAPDM_REL_REQ,
    MSG_ID_RR_LAPDM_MDL_REL_REQ,
    MSG_ID_RR_LAPDM_CELL_OPTION_UPDATE_REQ,
    MSG_ID_LAPDM_UL_DATA_REQ,
    MSG_ID_LAPDM_DOWNLINK_IND,

    MSG_ID_RR_LAPDM_INTER_RAT_EST_REQ,
    MSG_ID_LAPDM_CODE_END = MSG_ID_RR_LAPDM_INTER_RAT_EST_REQ,

    MSG_ID_RR_MPAL_DEDICATED_DATA_REQ,
    MSG_ID_MPAL_RR_DEDICATED_DATA_IND,
    MSG_ID_MPAL_RR_DEDICATED_READY_TO_SEND_IND,
    MSG_ID_MPAL_RR_DEDICATED_DATA_CALLBACK_IND,
    MSG_ID_MPAL_RR_DEDICATED_READY_TO_SEND_CALLBACK_IND,
  
    /*------------------------- REASM_MSG_CODE_BEGIN -------------------------*/
    MSG_ID_RLC_REASM_BEGIN_REASM_IND = MSG_ID_REASM_CODE_BEGIN,
    MSG_ID_RLC_REASM_TBF_REL_IND,
    MSG_ID_FLC_REASM_RESUME_REQ,
    MSG_ID_REASM_CODE_END = MSG_ID_FLC_REASM_RESUME_REQ,
  
    /*-------------------------- MPAL_MSG_CODE_BEGIN -------------------------*/
    MSG_ID_RR_MPAL_SEARCH_RF_REQ = MSG_ID_MPAL_CODE_BEGIN,
    MSG_ID_RR_MPAL_REQ_CODE_BEGIN = MSG_ID_RR_MPAL_SEARCH_RF_REQ, /*Maruco20080904, add for count MPAL_NUM_UL_MSGS*/
    MSG_ID_RR_MPAL_SEARCH_RF_STOP_REQ,
    MSG_ID_RR_MPAL_BSIC_SYNC_REQ,
    MSG_ID_RR_MPAL_SPECIFIC_SYNC_REQ,
    MSG_ID_RR_MPAL_SERV_BCCH_MONITOR_REQ,
    MSG_ID_RR_MPAL_CCCH_MONITOR_REQ,
    MSG_ID_RR_MPAL_PAGE_MODE_CHANGE_REQ,
    MSG_ID_RR_MPAL_RACH_REQ,
    MSG_ID_RR_MPAL_STOP_RACH_REQ,
    MSG_ID_RR_MPAL_DEDICATED_CHANNEL_CONNECT_REQ,
    MSG_ID_RR_MPAL_DEDICATED_CHANNEL_DISCONNECT_REQ,
    MSG_ID_RR_MPAL_HANDOVER_REQ,
    MSG_ID_RR_MPAL_HANDOVER_STOP_REQ,
    MSG_ID_RR_MPAL_DEDICATED_CHANNEL_RECONNECT_REQ,
    MSG_ID_RR_MPAL_FREQUENCY_REDEFINITION_REQ,
    MSG_ID_RR_MPAL_CHANNEL_MODE_MODIFY_REQ,
    MSG_ID_RR_MPAL_CIPHERING_MODE_COMMAND_REQ,
    MSG_ID_RR_MPAL_CLOSE_TCH_LOOP_REQ,
    MSG_ID_RR_MPAL_OPEN_TCH_LOOP_REQ,
    MSG_ID_RR_MPAL_DAI_TEST_REQ,
    MSG_ID_RR_MPAL_POWER_CLASS_REQ,
    MSG_ID_RR_MPAL_CELL_OPTION_UPDATE_REQ,
    MSG_ID_RR_MPAL_EXTENDED_MEAS_REQ,
    MSG_ID_RR_MPAL_NEIGHBOR_MEAS_REQ,
    MSG_ID_RR_MPAL_NEIGHBOR_BSIC_START_REQ,
    MSG_ID_RR_MPAL_NEIGHBOR_BSIC_STOP_REQ,
    MSG_ID_RR_MPAL_NEIGHBOR_SYS_INFO_READ_REQ,
    MSG_ID_RR_MPAL_NEIGHBOR_SYS_INFO_STOP_REQ,
    MSG_ID_RR_MPAL_CELL_BSIC_START_REQ,
    MSG_ID_RR_MPAL_CELL_BSIC_STOP_REQ,
    MSG_ID_RR_MPAL_CELL_SYS_INFO_READ_REQ,
    MSG_ID_RR_MPAL_CELL_SYS_INFO_STOP_REQ,
#ifndef __MTK_TARGET__ 
#ifdef __NEW_TBF_ARCH__    
    MSG_ID_RR_MPAL_FLUSH_REQ, /*for MTBF UT*/
#endif /*__NEW_TBF_ARCH__*/
#ifdef __PS_HO__
    MSG_ID_RR_MPAL_FLUSH_CTRL_BLOCK_REQ, /*for PS_HO UT*/
#endif /* end of __PS_HO__ */
#endif

    /*------------------------ CBCH msgcodes --------------*/
    MSG_ID_RR_MPAL_CBCH_CONFIG_REQ,
    MSG_ID_RR_MPAL_CBCH_START_REQ,
    MSG_ID_RR_MPAL_CBCH_STOP_REQ,
    MSG_ID_RR_MPAL_CBCH_SKIP_REQ,
    
#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ /* Gemini 2.0 */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#endif /* end of __GEMINI__ */

    MSG_ID_RR_MPAL_SIM_READY_NOTIFY_REQ,
    MSG_ID_RR_MPAL_SET_RAT_SERVICE_REQ, 
    MSG_ID_RR_MPAL_CELL_SELECTION_INIT_REQ, 

    MSG_ID_T3124_EXPIRY,
  
#ifdef __PS_SERVICE__
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
   MSG_ID_RR_MPAL_MONITOR_PAGE_IN_PTM_START_REQ,
   MSG_ID_RR_MPAL_MONITOR_PAGE_IN_PTM_STOP_REQ,
#endif /* end of __MONITOR_PAGE_DURING_TRANSFER__*/
#ifdef __SMART_PAGING_IN_IDLE__
   MSG_ID_RR_MPAL_SMART_PAGE_START_REQ,
#endif /* __SMART_PAGING_IN_IDLE__ */   
#ifdef __RMP_PRESENT__
    MSG_ID_RR_MPAL_MONITOR_PBCCH_REQ,
    MSG_ID_RR_MPAL_STOP_MONITOR_PBCCH_REQ,
    MSG_ID_RR_MPAL_MONITOR_PCCCH_REQ,
    MSG_ID_RR_MPAL_NCELL_PBCCH_REQ,
    MSG_ID_RR_MPAL_STOP_NCELL_PBCCH_REQ,
#endif /* __RMP_PRESENT__ */    
    MSG_ID_RR_MPAL_NC_MEASUREMENT_REQ,
    MSG_ID_RR_MPAL_STOP_NC_MEASUREMENT_REQ,
#ifdef __PKT_EXT_MEAS__
    MSG_ID_RR_MPAL_PKT_EXT_MEASUREMENT_REQ,
#endif /*__PKT_EXT_MEAS__*/    
#ifdef __RMP_PRESENT__
    MSG_ID_RR_MPAL_INT_MEASUREMENT_REQ,
#endif /* __RMP_PRESENT__ */
    MSG_ID_RR_MPAL_PDTCH_CONNECT_REQ,
    MSG_ID_RR_MPAL_RRBP_REQ,
    MSG_ID_RR_MPAL_CTRL_REQ,
    MSG_ID_RR_MPAL_DATA_REQ,
    MSG_ID_RR_MPAL_PKT_TIMING_ADV_PWR_CTRL_REQ,
    MSG_ID_RR_MPAL_PDCH_RELEASE_REQ,
    MSG_ID_RR_MPAL_PDTCH_DISCONN_REQ,
#ifdef __PS_HO__
    MSG_ID_RR_MPAL_PS_HANDOVER_REQ,
    MSG_ID_RR_MPAL_PS_HANDOVER_RECONNECT_REQ,
#endif /* end of __PS_HO__ */
    MSG_ID_RR_MPAL_PDCH_ASSIGNMENT_REQ,
#endif /* end of __PS_SERVICE__ */

#ifdef __EGPRS_MODE__
    MSG_ID_RR_MPAL_UPDATE_IR_RESET_REQ,
    MSG_ID_RR_MPAL_EGPRS_LOOP_REQ,
#endif /* __EGPRS_MODE__ */    
#ifdef __NORMAL_MODE_CAPID_CAL_SUPPORT__
    MSG_ID_RR_MPAL_ENTER_CAPID_CAL_MODE_REQ,
    MSG_ID_RR_MPAL_LEAVE_CAPID_CAL_MODE_REQ,
    MSG_ID_RR_MPAL_QUERY_CAPID_CAL_RESULT_REQ,
#endif /* __NORMAL_MODE_CAPID_CAL_SUPPORT__ */
/*Maruco20080904, add for count MPAL_NUM_UL_MSGS*/
/*Must not include 3G msg since 3G msg use another function table */
    MSG_ID_RR_MPAL_REQ_CODE_END, 

#ifdef __UMTS_RAT__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /*--------------------------- MPAL UT (MPAL-L1)- -------------------------*/
#ifndef __MTK_TARGET__
    MSG_ID_MPHC_PHY_INFO_CHECK_REQ,
    MSG_ID_RR_MPAL_DETECT_PAGING_BLOCK_RESULT_CNF,
#endif /* __MTK_TARGET__ */

    MSG_ID_MPAL_CODE_END,


    /*-------------------------- APGS_MSG_CODE_BEGIN -------------------------*/
#ifdef __AGPS_CONTROL_PLANE__
    MSG_ID_GAS_RRLP_DATA_IND,
    MSG_ID_RRLP_GAS_DATA_CNF,
    MSG_ID_GAS_RRLP_ABORT_IND,
    MSG_ID_GAS_RRLP_FIRST_SEGMENT_IND,
    MSG_ID_GAS_RRLP_SEGMENT_DISCARD_IND,
#endif /* __AGPS_CONTROL_PLANE__ */
 
/*----------------------------- RR_MSG_CODE_END ------------------------------*/
