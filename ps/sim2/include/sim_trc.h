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
 *	sim_trc.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is trace map definition.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef _SIM_TRC_H
#define _SIM_TRC_H

#ifndef GEN_FOR_PC
#include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "kal_trace.h"

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "sim_trc_gen.h"
#endif /* TST Trace Defintion */
#endif
BEGIN_TRACE_MAP(MOD_SIM)

    /* TRACE_FUNC trace class */   
                  	
    TRC_MSG(FUNC_SIM_START_REQ_HANDLER,"sim_start_req_handler()") 	
    TRC_MSG(FUNC_SIM_WRITE_REQ_HANDLER,"sim_write_req_handler()")   
    TRC_MSG(FUNC_SIM_READ_REQ_HANDLER,"sim_read_req_handler()")	
    TRC_MSG(FUNC_SIM_INCREASE_REQ_HANDLER,"sim_increase_req_handler()")		
    TRC_MSG(FUNC_SIM_SECURITY_REQ_HANDLER,"sim_security_req_handler()")  
    TRC_MSG(FUNC_SIM_RUN_ALGO_REQ_HANDLER,"sim_run_algo_req_handler()")
    TRC_MSG(FUNC_SIM_SEEK_REQ_HANDLER,"sim_seek_req_handler()")
    TRC_MSG(FUNC_SIM_FILE_INFO_REQ_HANDLER,"sim_file_info_req_handler()")
    TRC_MSG(FUNC_SIM_DIAL_MODE_REQ_HANDLER,"sim_dial_mode_req_handler()")
    TRC_MSG(FUNC_SIM_STATUS_REQ_HANDLER,"sim_status_req_handler()")   
    TRC_MSG(FUNC_SIM_POWEROFF_REQ_HANDLER,"sim_poweroff_req_handler()")
    TRC_MSG(FUNC_SIM_TIMER_EXPIRY_HANDLER,"sim_timer_expiry_handler()")

    TRC_MSG(FUNC_SIM_BT_SAP_CONNECT_REQ_HANDLER, "bt_sim_connect_req_handler()")        /* Nick 20070117 */
    TRC_MSG(FUNC_SIM_BT_SAP_RESET_REQ_HANDLER, "bt_sim_reset_req_handler()")    /* Nick 20070117 */
    TRC_MSG(FUNC_SIM_BT_SAP_APDU_REQ_HANDLER, "bt_sim_apdu_req_handler()")      /* Nick 20070117 */
    TRC_MSG(FUNC_SIM_BT_SAP_DISCONNECT_REQ_HANDLER, "bt_sim_disconnect_req_handler()")  /* Nick 20070117 */
    TRC_MSG(FUNC_SIM_BT_SAP_POWER_OFF_REQ_HANDLER, "bt_sim_power_off_req_handler()")    /* Nick 20070117 */
    TRC_MSG(FUNC_SIM_BT_SAP_POWER_ON_REQ_HANDLER, "bt_sim_power_on_req_handler()")        /*mtk01612: [MAUI_02356228]*/    

    TRC_MSG(FUNC_L4C_SIM_GET_GSMCDMA_DUALSIM_INFO_REQ_HANDLER, "l4c_sim_GET_gsmcdma_dualsim_info_req_handler()")/* Nick 20080808 */
    TRC_MSG(FUNC_L4C_SIM_SET_GSMCDMA_DUALSIM_INFO_REQ_HANDLER, "l4c_sim_SET_gsmcdma_dualsim_mode_req_handler()")/* Nick 20080808 */

    TRC_MSG(FUNC_SIM_CSIM_REQ_HANDLER, "sim_csim_req_handler()")      //mtk01612: __CSIM__    
    TRC_MSG(FUNC_SAT_PROCOMM_DISPLAY_TEXT,"sat_procomm_display_text()")   
    TRC_MSG(FUNC_SAT_PROCOMM_GET_INKEY,"sat_procomm_get_inkey()")
    TRC_MSG(FUNC_SAT_PROCOMM_GET_INPUT,"sat_procomm_get_input()")
    TRC_MSG(FUNC_SAT_PROCOMM_PLAY_TONE,"sat_procomm_play_tone()")
    TRC_MSG(FUNC_SAT_PROCOMM_SETUP_MENU,"sat_procomm_setup_menu()")   
    TRC_MSG(FUNC_SAT_PROCOMM_SELECT_ITEM,"sat_procomm_select_item()")   
    TRC_MSG(FUNC_SAT_PROCOMM_SEND_SMS,"sat_procomm_send_sms()")    
    TRC_MSG(FUNC_SAT_PROCOMM_SEND_SS,"sat_procomm_send_ss()")   
    TRC_MSG(FUNC_SAT_PROCOMM_SEND_USSD,"sat_procomm_send_ussd()")   
    TRC_MSG(FUNC_SAT_PROCOMM_SETUP_CALL,"sat_procomm_setup_call()")   
    TRC_MSG(FUNC_SAT_PROCOMM_MORE_TIME,"sat_procomm_more_time()")
    TRC_MSG(FUNC_SAT_PROCOMM_REFRESH,"sat_procomm_refresh()")  
    TRC_MSG(FUNC_SAT_PROCOMM_POLL_INTERVAL,"sat_procomm_poll_interval()") 
    TRC_MSG(FUNC_SAT_PROCOMM_POLLING_OFF,"sat_procomm_polling_off") 	
    TRC_MSG(FUNC_SAT_PROCOMM_PROVIDE_LOCAL_INFO,"sat_procomm_provide_local_info()")
    TRC_MSG(FUNC_SAT_PROCOMM_SETUP_EVENT_LIST,"sat_procomm_setup_event_list()")
    TRC_MSG(FUNC_SAT_PROCOMM_PERFORM_CARD_APDU,"sat_procomm_perform_card_apdu()")
    TRC_MSG(FUNC_SAT_PROCOMM_POWER_OFF_CARD,"sat_procomm_power_off_card()")
    TRC_MSG(FUNC_SAT_PROCOMM_POWER_ON_CARD,"sat_procomm_power_on_card()")
    TRC_MSG(FUNC_SAT_PROCOMM_GET_READER_STATUS,"sat_procomm_get_reader_status()")
    TRC_MSG(FUNC_SAT_PROCOMM_TIMER_MANAGEMENT,"sat_procomm_timer_management()")
    TRC_MSG(FUNC_SAT_PROCOMM_SET_UP_IDLE_MODE_TEXT,"sat_procomm_set_up_idle_mode_text()")
    TRC_MSG(FUNC_SAT_PROCOMM_RUN_AT_COMMAND,"sat_procomm_run_at_command()")
    TRC_MSG(FUNC_SAT_PROCOMM_SEND_DTMF,"sat_procomm_send_dtmf()")
    TRC_MSG(FUNC_SAT_PROCOMM_LANGUAGE_NOTIFICATION,"sat_procomm_language_notification()")
    TRC_MSG(FUNC_SAT_PROCOMM_LAUNCH_BROWSER,"sat_procomm_launch_browser()")
    TRC_MSG(FUNC_SAT_PROCOMM_OPEN_CHANNEL,"sat_procomm_open_channel()")
    TRC_MSG(FUNC_SAT_PROCOMM_CLOSE_CHANNEL,"sat_procomm_close_channel()")
    TRC_MSG(FUNC_SAT_PROCOMM_RECEIVE_DATA,"sat_procomm_recv_data()")
    TRC_MSG(FUNC_SAT_PROCOMM_SEND_DATA,"sat_procomm_send_data()")
    TRC_MSG(FUNC_SAT_PROCOMM_GET_CHANNEL_STATUS,"sat_procomm_ch_status()")
    TRC_MSG(FUNC_SAT_SET_UP_IDLE_MODE_TEXT_RES_HANDLER,"sat_set_up_idle_mode_text_res_handler()")
    TRC_MSG(FUNC_SAT_PROCOMM_ACTIVATE,"sat_procomm_activate()") //__SATCL__
    TRC_MSG(FUNC_SAT_ACTIVATE_RES_HANDLER,"sat_activate_res_handler()")
    TRC_MSG(FUNC_SAT_RUN_AT_COMMAND_RES_HANDLER,"sat_run_at_command_res_handler()")
    TRC_MSG(FUNC_SAT_SEND_DTMF_RES_HANDLER,"sat_send_dtmf_res_handler()")
    TRC_MSG(FUNC_SAT_LANGUAGE_NOTIFICATION_RES_HANDLER,"sat_language_notification_res_handler()")
    TRC_MSG(FUNC_SAT_LAUNCH_BROWSER_RES_HANDLER,"sat_launch_browser_res_handler()")
    TRC_MSG(FUNC_SAT_OPEN_GPRS_CHANNEL_RES_HANDLER,"sat_open_gprs_channel_res_handler()")
    TRC_MSG(FUNC_SAT_OPEN_CSD_CHANNEL_RES_HANDLER,"sat_open_csd_channel_res_handler()")
    TRC_MSG(FUNC_SAT_OPEN_SERVER_MODE_CHANNEL_RES_HANDLER,"sat_open_server_mode_channel_res_handler()")
    TRC_MSG(FUNC_SAT_CLOSE_CHANNEL_RES_HANDLER,"sat_close_channel_res_handler()")
    TRC_MSG(FUNC_SAT_SEND_DATA_RES_HANDLER,"sat_send_data_res_handler()")
    TRC_MSG(FUNC_SAT_RECV_DATA_RES_HANDLER,"sat_recv_data_res_handler()")
    TRC_MSG(FUNC_SAT_CH_STATUS_RES_HANDLER,"sat_ch_status_res_handler()")   
    TRC_MSG(FUNC_SAT_PROVIDE_LOCAL_INFORMATION_HANDLER,"sat_provide_local_information_handler()")   
    TRC_MSG(FUNC_SAT_PROACTIVE_CMD_PROCESS,"sat_proactive_cmd_process()")
    TRC_MSG(FUNC_SAT_FILE_CHANGE_RES_HANDLER,"sat_file_change_res_handler()")  
    TRC_MSG(FUNC_SAT_DSPL_TEXT_RES_HANDLER,"sat_dspl_text_res_handler()")   
    TRC_MSG(FUNC_SAT_GET_INKEY_RES_HANDLER,"sat_get_inkey_res_handler()")
    TRC_MSG(FUNC_SAT_GET_INPUT_RES_HANDLER,"sat_get_input_res_handler()")
    TRC_MSG(FUNC_SAT_PLAY_TONE_RES_HANDLER,"sat_play_tone_res_handler()")   
    TRC_MSG(FUNC_SAT_SETUP_MENU_RES_HANDLER,"sat_setup_menu_res_handler()")   
    TRC_MSG(FUNC_SAT_SELECT_ITEM_RES_HANDLER,"sat_select_item_res_handler()")   
    TRC_MSG(FUNC_SAT_SEND_SMS_RES_HANDLER,"sat_send_sms_res_handler()")   
    TRC_MSG(FUNC_SAT_SEND_SS_RES_HANDLER,"sat_send_ss_res_handler()")   
    TRC_MSG(FUNC_SAT_SEND_USSD_RES_HANDLER,"sat_send_ussd_res_handler()")   
    TRC_MSG(FUNC_SAT_SETUP_CALL_RES_HANDLER,"sat_setup_call_res_handler()")   
    TRC_MSG(FUNC_SAT_SMS_DL_REQ_HANDLER,"sat_sms_dl_req_handler()")
    TRC_MSG(FUNC_SAT_CB_DL_REQ_HANDLER,"sat_cb_dl_req_handler()")   
    TRC_MSG(FUNC_SAT_MENU_SELECT_REQ_HANDLER,"sat_menu_select_req_handler()")   
    TRC_MSG(FUNC_SAT_CALL_CTRL_BY_SIM_REQ_HANDLER,"sat_call_ctrl_by_sim_req_handler()")
    TRC_MSG(FUNC_SAT_CALL_STATUS_IND_HANDLER,"sat_call_status_ind_handler()")
    TRC_MSG(FUNC_SAT_SEND_SMS_CTRL_BY_SIM_REQ_HANDLER,"sat_send_sms_ctrl_by_sim_req_handler()")
    TRC_MSG(FUNC_SIM_JSR177_ATR_REQ_HANDLER,"sim_jsr177_atr_req_handler()")
    TRC_MSG(FUNC_SIM_JSR177_APDU_REQ_HANDLER,"sim_jsr177_apdu_req_handler()") // mtk01616_110317
    TRC_MSG(FUNC_SIM_SEARCH_RECORD_REQ_HANDLER,"sim_search_record_req_handler()") /* MAUI_02953154 */
    TRC_MSG(FUNC_SIM_SYNC_POLL_TIMER_IND_HANDLER,"sim_sync_poll_timer_ind_handler()") /*mtk01612: [MAUI_03020152] sync polling timer*/

    /* TRACE_STATE trace class */   
    TRC_MSG(STATE_SIM_RESET, "SIM: RESET SIM STATE")        /* Benson 0204 */
    TRC_MSG(STATE_SIM_CARD_NOT_INSERTED, "SIM: SIM Card Not Inserted")  /* Benson 0204 */
    TRC_MSG(STATE_SIM_SELECT_CMD_SUCCESS, "SIM: sim_select() success!") /* Benson 0204 */
    TRC_MSG(STATE_SAT_REFRESH_BUSY, "SAT REFRESH BUSY: send file change ind")   /* Benson 0204 */
    TRC_MSG(STATE_SIM_CMD_SUCCESS, "SIM: SIM_CMD_SUCCESS")                      /* Benson 0204 */
    TRC_MSG(STATE_SIM_CMD_FAIL, "SIM: SIM_CMD_FAIL")        /* Benson 0204 */
    TRC_MSG(STATE_SIM_CHV_RETRY_ALLOW, "SIM: SIM_CHV_RETRY_ALLOW")    /* Benson 0204 */
    TRC_MSG(STATE_SIM_CHV_BLOCK, "SIM: SIM_CHV_BLOCK")      /* Benson 0204 */
    TRC_MSG(STATE_SIM_SAT_CMD_BUSY, "SIM: SIM_SAT_CMD_BUSY")    /* Benson 0204 */
    TRC_MSG(STATE_SIM_DL_ERROR, "SIM: SIM_DL_ERROR")        /* Benson 0204 */
    TRC_MSG(STATE_SIM_MEMORY_PROBLEM, "SIM: SIM_MEMORY_PROBLEM")/* Benson 0204 */
    TRC_MSG(STATE_SIM_TECHNICAL_PROBLEM, "SIM: SIM_TECHNICAL_PROBLEM")  /* Benson 0204 */
    TRC_MSG(STATE_SIM_WRONG_INSTRUCTION_CLASS, "SIM: SIM_WRONG_INSTRUCTION_CLASS")  /* Nick 20071212 */
    TRC_MSG(STATE_SIM_30V, "SIM: 3.0 V SIM")                /* Benson 04142004 */
    TRC_MSG(STATE_SIM_18V, "SIM: 1.8V SIM")                 /* Benson 04142004 */
    TRC_MSG(STATE_SIM_RESET_30V, "SIM RESET at 3.0V")       /* Benson 04142004 */
    TRC_MSG(STATE_SIM_RESET_18V, "SIM RESET at 1.8V")       /* Benson 04142004 */
    TRC_MSG(STATE_SIM_FILE_NOT_FOUND,"FILE_NOT_FOUND")
    TRC_MSG(STATE_SIM_BT_SAP_APDU_PROTOCOL_TYPE_0, "Transport Protocol Type: 0")    /* Nick 20070117 */
    TRC_MSG(STATE_SIM_STATUS_UPDATE, "SIM status update")    /* Nick 20080514: GEMINI */
    TRC_MSG(STATE_SIM_RESET_ITSELF, "SIM reset itself")      /* Nick 20080514 */


    TRC_MSG(STATE_MMI_CANT_GET_DUALSIM_INFO, "G+C MMI can't get dualsim info")                  /* Nick 20080808 */
    TRC_MSG(STATE_GSMCDMA_DETECTED, "G+C GSMCDMA dualsim file detected")                        /* Nick 20080808 */
    TRC_MSG(STATE_DUALSIM_CMD_FAIL_DISCONNECT_NOT_ALLOWED, "G+C dualsim disconnect not allowed")/* Nick 20080808 */
    TRC_MSG(STATE_DUALSIM_CMD_FAIL_CONNECT_NOT_ALLOWED, "G+C dualsim connect not allowed")      /* Nick 20080808 */

    TRC_MSG(STATE_SIM_CALL_DISCONNECT, "SIM: Disconnect on-going call")        /*mtk01612: [MAUI_02574001]*/
    
    TRC_MSG(STATE_SIM_CONNECT_WITH_PHONE_SUCCESS, "CONNECT_WITH_PHONE_SUCCESS")  /* Nick 20070117 */
    TRC_MSG(STATE_SIM_CONNECT_WITH_PHONE_FAILED, "CONNECT_WITH_PHONE_FAILED")    /* Nick 20070117 */
    TRC_MSG(STATE_SIM_DISCONNECT_WITH_PHONE_SUCCESS, "DISCONNECT_WITH_PHONE_SUCCESS")    /* Nick 20070117 */
    TRC_MSG(STATE_SIM_DISCONNECT_WITH_PHONE_FAILED, "DISCONNECT_WITH_PHONE_FAILED")      /* Nick 20070117 */    

    TRC_MSG(STATE_SIM_BT_SAP_RESET_SUCCESS, "BT_SAP_RESET_SUCCESS")      /* Nick 20070117 */
    TRC_MSG(STATE_SIM_BT_SAP_RESET_FAILED, "BT_SAP_RESET_FAILED")        /* Nick 20070117 */

    /* TRACE_INFO trace class */   
    TRC_MSG(INFO_SIM_SELECT_FILE, "SIM_FILE_SELECTED: %02X %02X => %02X %02X")
    TRC_MSG(INFO_SIM_STATUS_WORD, "SIM_STATUS_WORD:   %02X %02X")
    TRC_MSG(INFO_SAT_TIMER_EXPIRE_MESSAGE_RCVD,"Timer Expiry Message is received")
    TRC_MSG(INFO_SIM_SAT_CMD_BUSY_RETRY, "SIM_SAT_CMD_BUSY_RETRY")      /* Nick 20080827 */
 
    TRC_MSG(INFO_SIM_RESET_ERROR, "SIM_RESET_ERROR: %MDCL_SIM_STATUS")  /*Andrew 20081118 */ /*mtk01612: sim_feature_set*/    
    TRC_MSG(INFO_SIM_SELECT_ELP_BY_SPEC, "SELECT_ELP_BY_SPEC") 
    TRC_MSG(INFO_SIM_SELECT_ELP_BY_SPEC_ISO639_SPECIFIED, "INFO_SIM_SELECT_ELP_BY_SPEC_ISO639_SPECIFIED: type = %d, index = %d")      
    TRC_MSG(INFO_SIM_SELECT_ELP_BY_SPEC_ME_SUPPORT, "INFO_SIM_SELECT_ELP_BY_SPEC_ME_SUPPORT: type = %d, index = %d")    
    
    TRC_MSG(INFO_SIM_CONNECT_TYPE, "CONNECT_TYPE: %Msim_plug_out_type_enum")

    TRC_MSG(INFO_MMI_ALLOW_SIM_FETCH, "MMIallow %Msim_interface_enum fetch")       /* Nick 20080514 */
    TRC_MSG(INFO_MMI_NOT_ALLOW_SIM_FETCH, "MMInotallow %Msim_interface_enum fetch")  /* Nick 20080514 */
    TRC_MSG(INFO_RR_ALLOW_SIM_FETCH, "RRallow %Msim_interface_enum fetch")         /* Nick 20080514 */
    TRC_MSG(INFO_RR_NOT_ALLOW_SIM_FETCH, "RRnotallow %Msim_interface_enum fetch")    /* Nick 20080514 */
    TRC_MSG(INFO_USIM_AL_SELECT,"SELECT:%Msim_file_index_enum => %02X %02X") 
    TRC_MSG(INFO_SIM_AL_STATUS,"STATUS => %02X %02X")
    TRC_MSG(INFO_SIM_AL_READ_BINARY,"READ BINARY  offset: %hd length: %hd => %02X %02X")
    TRC_MSG(INFO_SIM_AL_UPDATE_BINARY,"UPDATE BINARY offset: %hd length: %hd => %02X %02X")
    TRC_MSG(INFO_SIM_AL_READ_RECORD,"READ RECORD rec# %hd size: %hd => %02X %02X")
    TRC_MSG(INFO_SIM_AL_UPDATE_RECORD,"UPDATE_RECORD rec# %hd size: %hd => %02X %02X")
    TRC_MSG(INFO_SIM_AL_INCREASE,"INCREASE => %02X %02X")
    TRC_MSG(INFO_SIM_AL_VERIFY,"VERIFY => %02X %02X")
    TRC_MSG(INFO_SIM_AL_CHANGE_PIN,"CHANGE PIN => %02X %02X")
    TRC_MSG(INFO_SIM_AL_SWITCH_PIN,"SWITCH PIN: %Msim_instruction_code_enum => %02X %02X")
    TRC_MSG(INFO_SIM_AL_UNBLOCK_PIN,"UNBLOCK PIN => %02X %02X")
    TRC_MSG(INFO_SIM_AL_DEACTIVATE_FILE,"DEACTIVATE FILE: %Msim_file_index_enum => %02X %02X")
    TRC_MSG(INFO_SIM_AL_ACTIVATE_FILE,"ACTIVATE FILE: %Msim_file_index_enum => %02X %02X")
    TRC_MSG(INFO_SIM_AL_AUTHENTICATE,"AUTHENTICATE => %02X %02X")
    TRC_MSG(INFO_SIM_AL_TERMINAL_PROFILE,"TERMINAL PROFILE => %02X %02X")
    TRC_MSG(INFO_SIM_AL_ENVELOPE,"ENVELOPE: send %hd bytes recv %hd bytes => %02X %02X")
    TRC_MSG(INFO_SIM_AL_FETCH,"FETCH %hd bytes => %02X %02X")
    TRC_MSG(INFO_SIM_AL_TERMINAL_RESPONSE,"TERMINAL RESPONSE => %02X %02X")
    TRC_MSG(INFO_USIM_AL_GET_CHALLENGE,"GET CHALLENGE: %hd bytes => %02X %02X")
    TRC_MSG(INFO_USIM_AL_MANAGE_CHANNEL,"MANAGE CHANNEL %Musim_channel_op_enum %Musim_logic_channel_enum => %02X %02X")
    TRC_MSG(INFO_USIM_SELECT_AID,"USIM SELECT AID: %02X %02X")
    TRC_MSG(INFO_USIM_AL_READ_BINARY_SFI,"usim_al_read_binary_with_sfi: %Musim_sfi_enum %hd  => %02X %02X")

    TRC_MSG(INFO_USIM_NO_FILE_MAPPING,"No rule of mapping %Msim_file_index_enum to USIM")
    TRC_MSG(INFO_USIM_FILE_MAPPING,"Mapping %Msim_file_index_enum to %Msim_file_index_enum")
    TRC_MSG(INFO_SERVICE_MAPPING_TRUE,"Mapping %Msim_service_enum Support")
    TRC_MSG(INFO_SERVICE_MAPPING_FALSE,"Mapping %Msim_service_enum Not Support")
    TRC_MSG(INFO_SIM_LOWCOST_MERGE_TASK, "LOWCOST_MERGE_TASK feature support") 
    TRC_MSG(INFO_SAT_TR_DROPPED, "Terminal Response is dropped") 
    TRC_MSG(INFO_SIM_SWITCH,"SIM_SWITCH: SIM %Msim_interface_enum switch to SLOT %Msim_interface_enum")
    TRC_MSG(INFO_SIM_CSUS_SWITCH,"SIM_CSUS_SWITCH: SIM %Msim_interface_enum switch to SLOT %Msim_interface_enum")
    TRC_MSG(INFO_SIM_POLL_TIMER_STATE,"SIM_SYNC_TIMER: sim_sync_poll_timer_state = %Msim_sync_poll_timer_state_enum")   
    TRC_MSG(INFO_SIM_POLL_TIMER_PERIOD,"SIM_SYNC_TIMER: poll_timer_period = %d (ticks)") /*mtk01612: [MAUI_03020152] sync polling timer*/        

    /* TRACE_WARNING trace class */   
    TRC_MSG(WARNING_SMS_DL_REQ_ADDR_SIZE_FALSE,"SMS_DL size_of_addr exceed")
    /* MAUI_01949754 mtk02374 20090903 */
    TRC_MSG(WARNING_RES_LENGTH_FALSE,"length of RES exceed")
    TRC_MSG(WARNING_CK_LENGTH_FALSE,"length of CK is not 16")
    TRC_MSG(WARNING_IK_LENGTH_FALSE,"length of IK is not 16")
    TRC_MSG(WARNING_KC_LENGTH_FALSE,"length of Kc is not 8")
    TRC_MSG(WARNING_AUTS_LENGTH_FALSE,"length of AUTS exceed")
    TRC_MSG(WARNING_AUTHENTICATION_TAG_UNKNOWN,"authentication response tag unknown")
    TRC_MSG(WARNING_SRES_LENGTH_FALSE,"length of SRES exceed")
    TRC_MSG(WARNING_FCP_PROP_INFO_SIZE,"Proprietary Info longer than 17") /*[MAUI_01923168] mtk80420:Low Item 3*/
    TRC_MSG(WARNING_PLMN_FILE_SIZE, "PLMN file size is larger than 500")  /* [MAUI_02630325] [Revise ASSERT] mtk80420 */
    TRC_MSG(WARNING_UST_FILE_SIZE, "USIM UST file size is larger than 256")  /* [MAUI_02630325] [Revise ASSERT] mtk80420 */
    TRC_MSG(WARNING_EST_FILE_SIZE, "USIM EST file size is larger than 256")  /* [MAUI_02630325] [Revise ASSERT] mtk80420 */
    TRC_MSG(WARNING_UICC_DETECTION_RULE,"UICC detection rule warning")    
    TRC_MSG(WARNING_FCP_SIZE,"FCP size is larger than 127,fcp[1]=%x,fcp[2]=%x") 
    TRC_MSG(WARNING_UNKNOWN_FILE_STRUCT,"Unknown EF file structure,type of structure=%x")

    /* New Warning */
    TRC_MSG(WARNING_SIM_CARD_REMOVED, "SIM_ERROR: SIM_CARD_REMOVED")    /* Benson 0204 */
    TRC_MSG(WARNING_FCP_TLV_LEN_ERROR, "USIM_FCP_ERROR: FCP TLV LENGTH ERROR!")  /* [MAUI_02630325] [Revise ASSERT] mtk80420 */
    TRC_MSG(WARNING_FCP_PROP_INFO_TLV_LEN_ERROR,"USIM_FCP_ERROR: FCP PROP INFO TLV LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_FILE_DESCRIPTOR_ERROR,"USIM_FCP_ERROR: FCP FILE DESCRIPTOR ERROR!")
    TRC_MSG(WARNING_FCP_FILE_ID_LEN_ERROR,"USIM_FCP_ERROR: FCP FILE ID ERROR!")
    TRC_MSG(WARNING_FCP_DF_NAME_LEN_ERROR,"USIM_FCP_ERROR: FCP DF NAME LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_PROP_UICC_CHAR_LEN_ERROR,"USIM_FCP_ERROR: FCP PROP UICC CHAR LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_PROP_APP_PWR_LEN_ERROR,"USIM_FCP_ERROR: FCP PROP APP PWR LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_PROP_MIN_APP_CLK_LEN_ERROR,"USIM_FCP_ERROR: FCP PROP MIN APP CLK LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_PROP_AVAIL_MEM_LEN_ERROR,"USIM_FCP_ERROR: FCP PROP AVAILABLE MEMORY LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_LIFE_CYCLE_LEN_ERROR,"USIM_FCP_ERROR: FCP LIFE CYCLE LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_PIN_NUMBER_ERROR,"USIM_FCP_ERROR: FCP PIN STATUS TEMPLATE DO NUMBER ERROR!")
    TRC_MSG(WARNING_FCP_PIN_DO_TAG_ERROR,"USIM_FCP_ERROR: FCP PIN DO TAG ERROR!")
    TRC_MSG(WARNING_FCP_TOTAL_FILE_SIZE_LEN_ERROR,"USIM_FCP_ERROR: FCP TOTAL FILE SIZE LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_FILE_SIZE_LEN_ERROR,"USIM_FCP_ERROR: FCP FILE SIZE LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_SFI_LEN_ERROR,"USIM_FCP_ERROR: FCP SFI LENGTH ERROR!")
    TRC_MSG(WARNING_FCP_TEMP_TAG_ERROR,"USIM_FCP_ERROR: FCP TEMPLATE TAG ERROR!")
    TRC_MSG(WARNING_FCP_SUB_TAG_ERROR,"USIM_FCP_ERROR: FCP SUB TAG ERROR!")
    TRC_MSG(WARNING_USIM_ICCID_LEN_ERROR,"USIM_ERROR: USIM ICCID LENGTH ERROR!")
    TRC_MSG(WARNING_USIM_AID_LEN_ERROR,"USIM_ERROR: USIM AID LENGTH ERROR!")  /*[MAUI_02630325] [Revise ASSERT] mtk80420 */
    TRC_MSG(WARNING_FCP_PIN_PS_DO_NOT_PRESENT,"USIM_FCP_ERROR: FCP PS_DO DOES NOT PRESENT FIRST!")
    TRC_MSG(WARNING_INFO_NUM_RECORD_SIZE,"SIM EF_InfoNum: record size not in 1 to 64")
    TRC_MSG(WARNING_UNEXPECTED_STKTR,"Unexpected AT+STKTR,is_wait_for_rsp = %d")

    /* TRACE_ERROR trace class */   
    TRC_MSG(ERROR_SIM_RESET_ABNORMAL_CMD_RETRY, "SIM_RESET_ABNORMAL: command retry")    /* Benson 0209 */
    TRC_MSG(ERROR_SERVICE_NOT_DEFINED,"%Msim_service_enum Not Defined!")
    TRC_MSG(ERROR_SIM_INTERFACE_ERROR,"SIM_ERROR: interface = %d Not Valid!")

    /* New GROUP1 */
    TRC_MSG(GROUP1_SIM_START_TIMER, "sim_start_timer()")      /* Benson 0204 */
    TRC_MSG(GROUP1_SIM_STOP_TIMER, "sim_stop_timer()")        /* Benson 0204 */
    TRC_MSG(GROUP1_SIM_START_RECOVERY_TIMER, "sim_start_recovery_timer()")

    /* New GROUP2*/
    TRC_MSG(GROUP2_SIM_ERROR_HANDLE,"sim_error_handler()")			
    /*[MAUI_02356453] 20110123 mtk01612: sim_smu_error_ind is removed due to no need after MAUI_01815935*/    
    TRC_MSG(GROUP2_SIM_READ_ECC_ELP,"sim_read_ecc_elp()")			
    TRC_MSG(GROUP2_SIM_PROFILE_DOWNLOAD,"sim_profile_download()")	
    TRC_MSG(GROUP2_SIM_READ_PHASE,"sim_read_phase()")				
    TRC_MSG(GROUP2_SIM_GET_DN_TYPE,"sim_get_dn_type()")				
    TRC_MSG(GROUP2_SIM_GET_PS_INFO,"sim_get_ps_info()")				
    TRC_MSG(GROUP2_SIM_READ_SERVICE_TABLE,"sim_read_service_table()")	
    TRC_MSG(GROUP2_SIM_INITIALIZATION,"sim_initialization()")				
    TRC_MSG(GROUP2_SIM_GET_CHV_INFO,"sim_get_chv_info()")
    TRC_MSG(GROUP2_SIM_STARTUP_READ,"sim_startup_read()")
    TRC_MSG(GROUP2_SIM_AL_RESET, "sim_al_reset()")            /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_RESET_ABNORMAL, "sim_reset_abnormal()")    /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_EXCEPTION_HANDLE, "sim_exception_handle()")    /* mtk01612 */    
    TRC_MSG(GROUP2_SIM_AL_VERIFY_CHV, "sim_al_verify_chv()")      /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_UNBLOCK_CHV, "sim_al_unblock_chv()")    /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_CHANGE_CHV, "sim_al__change_chv()")     /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_SWITCH_CHV, "sim_al_switch_chv()")     
    TRC_MSG(GROUP2_SIM_AL_READ_BINARY, "sim_al_read_binary()")    /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_UPDATE_BINARY, "sim_al_update_binary()")/* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_UPDATE_RECORD, "sim_al_update_record()")/* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_RUN_GSM_ALGO, "sim_al_run_gsm_algo()")  /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_SEEK, "sim_al_run_gsm_algo()")      /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_STATUS, "sim_al_status()")          /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_REHABILITATE, "sim_al_rehabilitate()")  /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_INVALIDATE, "sim_al_invalidate()")      /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_INCREASE, "sim_al_increase()")          /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_POWEROFF, "sim_al_poweroff()")          /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_READ_RECORD, "sim_al_read_record()")    /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_GET_RESPONSE, "sim_al_get_response()")  /* Benson 0204 */
    TRC_MSG(GROUP2_SIM_AL_FETCH,"sim_al_fetch()")
    TRC_MSG(GROUP2_SIM_AL_TERMINAL_RESPONSE,"sim_al_terminal_response()")
    TRC_MSG(GROUP2_SIM_AL_TERMINAL_PROFILE,"sim_al_terminal_profile()")
    TRC_MSG(GROUP2_SIM_AL_ENVELOPE,"sim_al_envelope()")
    TRC_MSG(GROUP2_SIM_AL_SEARCH_RECORD, "sim_al_search_record()")   /* MAUI_02953154 */

    TRC_MSG(GROUP2_SIM_CONNECT_REFRESH, "sim_connect_refresh()")  /* Nick 20080808 */

    TRC_MSG(GROUP2_USIM_RESET_ABNORMAL, "usim_reset_abnormal()")    /* mtk01612*/
    TRC_MSG(GROUP2_USIM_EXCEPTION_HANDLE, "usim_exception_handle()")    /* mtk01612 */   

    TRC_MSG(GROUP2_SIM_APDU_RESP, "sim_apdu_resp()")      //mtk01612: __CSIM__

    TRC_MSG(GROUP2_BUILD_TERMINAL_RESPONSE,"build_terminal_response()")
    TRC_MSG(GROUP2_FIND_MODIFIED_TYPE,"find_modified_type()")
    TRC_MSG(GROUP2_SAT_EVDL_MT_CALL,"sat_evdl_mt_call()")
    TRC_MSG(GROUP2_SAT_EVDL_CALL_CONNECT,"sat_evdl_call_connect()")
    TRC_MSG(GROUP2_SAT_EVDL_CALL_DISCONNECT,"sat_evdl_call_disconnect()")
    TRC_MSG(GROUP2_SAT_EVDL_LOCATION_STATUS,"sat_evdl_location_status()")
    TRC_MSG(GROUP2_SAT_EVDL_USER_ACTIVITY,"sat_evdl_user_activity()")
    TRC_MSG(GROUP2_SAT_EVDL_IDLE_SCREEN_AVAILABLE,"sat_evdl_idle_screen_available()")
    TRC_MSG(GROUP2_SAT_EVDL_CARD_READER_STATUS,"sat_evdl_card_reader_status()")
    TRC_MSG(GROUP2_SAT_EVDL_LANGUAGE_SELECTION,"sat_evdl_language_selection()")
    TRC_MSG(GROUP2_SAT_EVDL_BROWSER_TERMINATION,"sat_evdl_browser_termination()")
    TRC_MSG(GROUP2_SAT_EVDL_DATA_AVAILABLE,"sat_evdl_data_available()")
    TRC_MSG(GROUP2_SAT_EVDL_CHANNEL_STATUS,"sat_evdl_channel_status()")
    TRC_MSG(GROUP2_SAT_EVDL_ACCESS_TECHNOLOGY_CHANGE,"sat_evdl_access_technology_change()")
    TRC_MSG(GROUP2_SAT_EVDL_NW_SEARCH_MODE_CHANGE,"sat_evdl_nw_search_mode_change()")  /*mtk02374 090513 add for evdl nw search mode*/
    TRC_MSG(GROUP2_SAT_EVDL_HCI_CONNECTIVITY,"sat_evdl_hci_connectivity()")  /* __SATCM__ */
    TRC_MSG(GROUP2_SAT_TIMER_EXPIRATION,"sat_timer_expiration()")
    TRC_MSG(GROUP2_SAT_CALL_CTRL_CHECK,"sat_call_ctrl_check()")
    TRC_MSG(GROUP2_SAT_SMS_CTRL_CHECK,"sat_sms_ctrl_check()")
    TRC_MSG(GROUP2_SAT_START_BASE_TIMER,"sat_start_base_timer()")
    TRC_MSG(GROUP2_SAT_STOP_BASE_TIMER,"sat_stop_base_timer()")
    TRC_MSG(GROUP2_SAT_START_TIMER,"sat_start_timer()")
    TRC_MSG(GROUP2_SAT_STOP_TIMER,"sat_stop_timer()")
    TRC_MSG(GROUP2_SAT_TIMER_EXPIRY_HDLR,"sat_timer_expiry_hdlr()")
    TRC_MSG(GROUP2_DECODE_TEXT_STRING,"decode_text_string()")
    TRC_MSG(GROUP2_DECODE_ICON_ID,"decode_icon_id()")
    TRC_MSG(GROUP2_DECODE_ALPHA_ID,"decode_alpha_id()")
    TRC_MSG(GROUP2_DECODE_ONLY_DATA_BLOCK,"decode_only_data_block()")  	
    TRC_MSG(GROUP2_DECODE_ONLY_U8,"decode_only_u8()")
    TRC_MSG(GROUP2_DECODE_DURATION,"decode_duration()") 
    TRC_MSG(GROUP2_DECODE_ITEM,"decode_item()")   
    TRC_MSG(GROUP2_DECODE_ITEM_NEXT_ACTION_IND,"decode_item_next_action_ind()")
    TRC_MSG(GROUP2_DECODE_ITEM_ICON_ID_LIST,"decode_item_icon_id_list")	
    TRC_MSG(GROUP2_DECODE_FILE_LIST,"decode_file_list()")   
    TRC_MSG(GROUP2_ENCODE_TEXT_STRING,"encode_text_string()")
    
    /* TRACE_GROUP3 SIM_CMD_APDU */
    TRC_MSG(GROUP3_SIM_CMD_TX, "%Msim_instruction_code_enum : length: %hd")
    TRC_MSG(GROUP3_SIM_CMD_RX, "APDU_rx length: %hd")
    TRC_MSG(GROUP3_SIM_CMD_APDU_TX, "APDU_tx %hd: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
    TRC_MSG(GROUP3_SIM_CMD_APDU_RX, "APDU_rx %hd: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
    
#ifdef __USIM_SUPPORT__  
    TRC_MSG(GROUP3_USIM_CMD_TX, "%Musim_instruction_code_enum : length: %hd")
    TRC_MSG(GROUP3_USIM_CMD_RX, "APDU_rx length: %hd") 
    TRC_MSG(GROUP3_USIM_CMD_APDU_TX, "APDU_tx %hd: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
    TRC_MSG(GROUP3_USIM_CMD_APDU_RX, "APDU_rx %hd: %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X %02X")
#endif /* __USIM_SUPPORT__ */
    /* dual SIM control message (driver) */
    TRC_MSG(SIM_GEMINI_CMD1, "[SIM_CMD1] %x %x %x %x, %x %x %x %x")
    TRC_MSG(SIM_GEMINI_CMD2, "[SIM_CMD2] %x %x %x %x, %x %x %x %x")
    TRC_MSG(SIM_GEMINI_CMD3, "[SIM_CMD3] %x %x %x %x, %x %x %x %x")
    TRC_MSG(SIM_GEMINI_GEN1, "[SIM_GEN1] file %x, line %x, %x %x, %x %x %x %x") 
    TRC_MSG(SIM_GEMINI_GEN2, "[SIM_GEN2] %x %x, %x %x")
    
END_TRACE_MAP(MOD_SIM)

#endif /* _SIM_TRC_H */ 

