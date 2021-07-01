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
 *   mm.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   MM related message identity definition
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


/*----------------------- MM_MSG_CODE_BEGIN------------------*/
	/* mesage received from TIMER at MMTIMER SAP */
	/*TBD*/

	/* messages received from CC at MMCC sap */
	MSG_ID_MMCC_PROMPT_REJ = MSG_ID_MM_CODE_BEGIN,
	MSG_ID_MMCC_PROMPT_RSP,
	MSG_ID_MMCC_REL_REQ,
	MSG_ID_MMCC_EST_REQ,
	MSG_ID_MMCC_REEST_REQ,
	MSG_ID_MMCC_DATA_REQ,
    MSG_ID_MMCC_ABORT_CALL_REQ,

	/* messages received from SS at MMSS sap */
	MSG_ID_MMSS_EST_REQ,
	MSG_ID_MMSS_DATA_REQ,
	MSG_ID_MMSS_REL_REQ,
	/* messages received from SMS at MMSMS sap*/
	MSG_ID_MMSMS_REL_REQ,
	MSG_ID_MMSMS_DATA_REQ,
	MSG_ID_MMSMS_EST_REQ,

	/* messages received from RAC at GMMREG  sap */
        MSG_ID_GMMREG_ATTACH_REQ, 
        MSG_ID_GMMREG_DETACH_REQ,                     
        MSG_ID_GMMREG_PLMN_SEARCH_REQ,
        MSG_ID_GMMREG_START_REG_REQ,
        MSG_ID_GMMREG_INIT_REQ,
        MSG_ID_GMMREG_BAND_SEL_REQ,
        MSG_ID_GMMREG_SEL_MODE_REQ, 
        MSG_ID_GMMREG_RFOFF_REQ,
        MSG_ID_GMMREG_SET_ROAMING_MODE_REQ,
        MSG_ID_GMMREG_SET_PREFER_RAT_REQ,

        MSG_ID_GMMREG_PLMN_LIST_REQ,
        MSG_ID_GMMREG_PLMN_LIST_STOP_REQ,
        MSG_ID_GMMREG_SET_RAT_MODE_REQ,

        MSG_ID_GMMREG_SET_GPRS_TRANSFER_PREFERENCE_REQ,
        MSG_ID_GMMREG_SET_PREFERRED_BAND_REQ,   /* mtk02475: for set band without reboot*/
        MSG_ID_GMMREG_END_PS_DATA_SESSION_REQ, //mtk02475: for Fast Dormancy

	#ifdef __GEMINI__
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif	

	/* message received from SIM GMM_SIM_SAP */
	/*TBD*/

	/* message received from SMS GMM_SMS_SAP*/
	MSG_ID_GMMSMS_EST_REQ,
	MSG_ID_GMMSMS_UNITDATA_REQ,

	/* message received from SM GMM_SM_SAP */
        MSG_ID_GMMSM_ESTABLISH_REQ,          
        MSG_ID_GMMSM_UNITDATA_REQ,
        MSG_ID_GMMSM_SEQUENCE_IND,
        MSG_ID_GMMSM_NSAPI_STATUS_REQ,

        MSG_ID_GMMSM_ATTACH_REQ,
        MSG_ID_GMMSM_EST_REQ,

	/* message received from RABM at GMM_RABM_SAP*/
	/*TBD*/

	/* message received from SIM at MM_SIM_SAP*/
	/*TBD*/

	/* Temporarily Added the TC MSG_IDs here */
	/*TBD*/
	
        /* messages received from RATDM at MM_RATDM_SAP */        
        MSG_ID_MM_RATDM_SEQUENCE_CNF,
        MSG_ID_MM_RATDM_REESTABLISH_RAB_IND,
        MSG_ID_MM_RATDM_SEND_USER_DATA_IND,

        MSG_ID_MM_RATDM_RAB_RELEASE_IND,


        /* messages received from RATCM at MM_RATCM_SAP */
	MSG_ID_MM_RATCM_SET_RAT_MODE_CNF,
	MSG_ID_MM_RATCM_INIT_CNF,
	MSG_ID_MM_RATCM_RFOFF_CNF,
	MSG_ID_MM_RATCM_PLMN_SEARCH_CNF,
	MSG_ID_MM_RATCM_BAND_CHANGE_CNF,
	MSG_ID_MM_RATCM_SYS_INFO_IND,
	MSG_ID_MM_RATCM_PLMN_LOSS_IND,
	MSG_ID_MM_RATCM_OUT_OF_SERVICE_IND,
	MSG_ID_MM_RATCM_PLMN_LIST_CNF,
	MSG_ID_MM_RATCM_PLMN_LIST_STOP_CNF,
	MSG_ID_MM_RATCM_CELL_CHANGE_START_IND,
	MSG_ID_MM_RATCM_CELL_CHANGE_FINISH_IND,
	MSG_ID_MM_RATCM_PAGE_IND,
	MSG_ID_MM_RATCM_SYNC_IND,
	MSG_ID_MM_RATCM_SECURITY_MODE_COMPLETE_IND,
	MSG_ID_MM_RATCM_SECURITY_MODE_CHANGE_IND,
	MSG_ID_MM_RATCM_CONN_EST_CNF,
	MSG_ID_MM_RATCM_CONN_EST_IND,
	MSG_ID_MM_RATCM_CONN_REL_CNF,
	MSG_ID_MM_RATCM_CONN_REL_IND,
	MSG_ID_MM_RATCM_CONN_LOSS_IND,
	MSG_ID_MM_RATCM_CONN_ABORT_IND,
	MSG_ID_MM_RATCM_READY_TIMER_UPDATE_IND,
	MSG_ID_MM_RATCM_CS_DATA_IND,
	MSG_ID_MM_RATCM_PS_DATA_CNF,
	MSG_ID_MM_RATCM_PS_DATA_IND,
	MSG_ID_MM_RATCM_RESET_KEYS_IND,
	MSG_ID_MM_RATCM_LLC_STATUS_IND,
	MSG_ID_MM_RATCM_T3122_TIMEOUT_IND,
	MSG_ID_MM_RATCM_CCO_ACTIVATION_TIME_TIMEOUT_IND,
        MSG_ID_MM_RATCM_END_PS_DATA_SESSION_CNF,  /* MAUI_02852442, __NO_PSDATA_SEND_SCRI__ */
#ifdef __GEMINI__	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    MSG_ID_MM_RATCM_LCS_PROC_START_IND,
    MSG_ID_MM_RATCM_LCS_PROC_END_IND,


       MSG_ID_MM_RATCM_LLC_PSHO_IND,
       MSG_ID_MM_RATCM_PS_HO_SUCCESS_IND,

	MSG_ID_MM_RATCM_SIGNAL_APPEAR_IND,
    MSG_ID_MM_RATCM_START_TEST_MODE_IND,
	MSG_ID_MM_RATCM_STOP_TEST_MODE_IND,
	MSG_ID_MM_CODE_END = MSG_ID_MM_RATCM_STOP_TEST_MODE_IND,
/*----------------------- MM_MSG_CODE_END--------------------*/


