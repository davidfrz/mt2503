/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
*	DmSelfRegister.c
*
* Project:
* --------
*	MAUI
*
* Description:
* ------------
*	This file for DM Self-Register application.
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
*
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================
*
*****************************************************************************/
//#include "MMI_include.h"
#include "MMI_features.h"

#ifdef __MMI_DM_SELF_REGISTER_SUPPORT__
#include "DmSelfRegisterProt.h"
#include "DmSelfRegisterGprot.h"
#include "mmi_rp_srv_dm_sr_def.h"

    #include "MMIDataType.h"
    #include "kal_non_specific_general_types.h"
    #include "stack_config.h"
    #include "mmi_frm_queue_gprot.h"
    #include "app_ltlcom.h"
    #include "stack_msgs.h"
    #include "kal_release.h"
    #include "DebugInitDef_Int.h"
    #include "MMI_conn_app_trc.h"
    #include "kal_trace.h"
    #include "string.h"
    #include "TimerEvents.h"
    #include "mmi_frm_timer_gprot.h"
    #include "mmi_msg_struct.h"
    #include "mmi_frm_events_gprot.h"
    #include "mmi_frm_nvram_gprot.h"
    #include "custom_mmi_default_value.h"
    #include "Unicodexdcl.h"
    #include "mmi_frm_mem_gprot.h"
    #include "app_buff_alloc.h"
    #include "nvram_common_defs.h"
    #include "stack_ltlcom.h"

/* ... Add More MMI header */
//#include "CommonScreens.h"
//#include "ProtocolEvents.h"

/* ...Add MSG header */
//#include "customer_ps_inc.h"
//#include "mmi_msg_context.h"
//#include "MessagesL4Def.h"
//#include "MessagesResourceData.h"
//#include "MessagesMiscell.h"
//#include "MessagesExDcl.h"
/*  */
//#include "customer_ps_inc.h"
//#include "l4c2smsal_struct.h"
//#include "smsal_l4c_enum.h"
/*  */
/*  */
/*  */
/*  */
/*  */

//#include "nvram_user_defs.h"

/*Mude Lin Add For DM Self-Register*/
//#include "Nvram_enums.h"
//#include "Nvram_interface.h"

//#include "DateTimeGprot.h"
//#include "app_datetime.h"

/* SMS2.0 */    
#include "SmsCuiGprot.h"
//#include "SMSApi.h"     /* for SMS related functions */
//#include "SmsAppGprot.h"
#include "SmsSrvGprot.h"
#include "NwInfoSrvGprot.h"


//#ifdef __MMI_DUAL_SIM__
//#include "mtpnp_ad_master_common_def.h"
//#include "Mtpnp_ad_master_if.h"
//#endif
//#include "SimDetectionGprot.h"


#include "ps_public_enum.h"

#include "BootupSrvGprot.h"
#include "SimCtrlSrvGprot.h"

#include "NwUsabSrvGprot.h"

#ifdef __OP02_DM__
#include "DMTypeDef.h"
#endif

static MMI_BOOL mmi_dm_sr_check_is_operator_sim_card(mmi_sim_enum sim_id);
static void mmi_dm_sr_send_port_sms(void);
static void mmi_dm_sr_send_port_sms_callback(srv_sms_callback_struct* callback_data);

//static void mmi_dm_sr_send_sms_req(void);
//static void mmi_dm_sr_send_sms_rsp(void *number, module_type mod, U16 result);
static void mmi_dm_sr_read_nvram(void);
static void mmi_dm_sr_write_nvram(void);
//static void mmi_dm_sr_reg_port_req(void);
//static void mmi_dm_sr_reg_port_rsp(void * first, module_type mod, U16 result);
//static void mmi_dm_sr_check_ack_sms(void * data, module_type mode, U16 result);
static void mmi_dm_sr_get_imei_req(void);
static void mmi_dm_sr_get_equip_info_req(U8 equip_id);
#if 0
/* under construction !*/
#endif
static void mmi_dm_sr_get_content_info_req(void);
static void mmi_dm_sr_get_content_info_rsp(void *inMsg, int mod);
//static void mmi_dm_sr_get_sms_common_setting_req(void);
//static void mmi_dm_sr_get_sms_common_settting_rsp(void *data, module_type mod, U16 result);
//static void mmi_dm_sr_reset_sms_common_setting_req(void);
//static void mmi_dm_sr_reset_sms_common_setting_rsp(void *data, module_type mod, U16 result);
//static void mmi_dm_sr_resume_pre_sms_common_setting_req(void);
//static void mmi_dm_sr_resume_pre_sms_common_setting_rsp(void *data, module_type mod, U16 result);
static void mmi_dm_sr_get_sms_numbers(void);
#if defined(__OP02_DM__)
static void mmi_dm_sr_read_des_number_req(void);
static MMI_BOOL mmi_dm_sr_read_des_number_rsp(void *inMsg);
static void mmi_dm_sr_read_port_number_req(void);
static MMI_BOOL mmi_dm_sr_read_port_number_rsp(void *inMsg);
static U16 mmi_dm_sr_hx_atoi(const char *s);
#endif

#if 0
/* under construction !*/
#endif

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
#endif

static int dm_self_imsi_repeat_time = 3;
static mmi_dm_sr_info_struct dm_self_reg_info;
static MMI_BOOL dm_self_start_flag = MMI_FALSE;
static void mmi_dm_sr_sim_process_init(void);
static S8 SIM1_IMSI[DM_SR_IMSI_SIZE];
static void mmi_dm_sr_get_imsi(void);
static void mmi_dm_sr_repeat_get_imsi(void);
static void mmi_dm_sr_imsi_process(void);
#ifdef __MMI_DUAL_SIM__
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
#endif /* __MMI_DUAL_SIM__ */
static U8 dm_self_first_network_ready = 0;
static void mmi_dm_sr_send_message(module_type MOD_SRC, 
	module_type MOD_DEST, 
	U8 MSG_SAP, 
	const U16 MSG_ID, 
	void *LOCAL, 
	void *PEER);

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_send_message
 * DESCRIPTION
 *  Common function for sending message
 * PARAMETERS
 *  MOD_SRC         [IN]        Source module
 *  MOD_DEST        [IN]        Destination module
 *  MSG_SAP         [IN]        Message SAP
 *  MSG_ID          [IN]        Message ID
 *  LOCAL           [IN]        Local parameter
 *  PEER            [IN]        Peer buffer
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_sr_send_message(
        module_type MOD_SRC,
        module_type MOD_DEST,
        U8 MSG_SAP,
        const U16 MSG_ID,
        void *LOCAL,
        void *PEER)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYQUEUE Message;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    Message.oslSrcId = MOD_SRC;
    Message.oslDestId = MOD_DEST;
    Message.oslMsgId = (msg_type) MSG_ID;
    Message.oslDataPtr = LOCAL;
    Message.oslPeerBuffPtr = PEER;
    OslMsgSendExtQueue(&Message);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_nw_availability_changed_notify
 * DESCRIPTION
 *  Handler for network service availability chahnged.
 * PARAMETERS
 *  evt     [IN] srv_nw_info_service_availability_changed_evt_struct*
 * RETURNS
 *  MMI_TRUE
 *****************************************************************************/
mmi_ret mmi_dm_sr_nw_availability_changed_notify(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_nw_info_service_availability_changed_evt_struct *availability_evt;
    U8 sim;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_EXT_ASSERT(evt->evt_id == EVT_ID_SRV_NW_INFO_SERVICE_AVAILABILITY_CHANGED,
        evt->evt_id, 0, 0);
    
    availability_evt = (srv_nw_info_service_availability_changed_evt_struct*)evt;

    if (availability_evt->sim == MMI_SIM1)
    {
        sim = 0;
    }
    else
    {
	sim = 1;
    }
	
    switch (availability_evt->new_status)
    {
        case SRV_NW_INFO_SA_NO_SERVICE:
            break;

        case SRV_NW_INFO_SA_FULL_SERVICE:
            mmi_dm_sr_notify_network_ready(sim);
	    break;
        case SRV_NW_INFO_SA_LIMITED_SERVICE:
	    break;
        case SRV_NW_INFO_SA_SEARCHING:
            break;

        default:
            /* Ignore */
            return MMI_RET_OK;
    }

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_notify_network_ready
 * DESCRIPTION
 *  notify network change 
 * PARAMETERS
 *  sim         [IN]    show which sim's network is ready now           
 * RETURNS
 *  void
 *****************************************************************************/	
void mmi_dm_sr_notify_network_ready(U8 sim)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 master_switch = 0;
    S16 error;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_NETWORK_READY);
   
    ReadValue(NVRAM_DM_SELF_REGISTER_MASTER_SWITCH, 
              &master_switch, 
	      DS_BYTE, 
              &error);

    if (master_switch == 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_MASTER_SWITCH_RESULT, master_switch);
        return;
    }


   
    if (sim == 0)
    {
	    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_NETWORK_READY_NOTIFY);
        if ((dm_self_first_network_ready != 0) && (dm_self_reg_info.is_self_reg_succuss == TRUE))
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_NETWORK_READY_NO_FIRST);
	        return;
        }
        dm_self_first_network_ready = 1;

        if (srv_sms_is_sms_ready() == MMI_TRUE)
        {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_NETWORK_READY_START);
            mmi_dm_sr_sim_process_init();
        }
    }

#ifdef __MMI_DUAL_SIM__
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
#endif /* __MMI_DUAL_SIM__ */
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_sim_process_init
 * DESCRIPTION
 *  notify network change 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_sim_process_init(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_SIM_PROCESS_INIT);
#ifdef __MMI_DUAL_SIM__
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
#endif /* __MMI_DUAL_SIM__ */ 
        if (dm_self_start_flag == MMI_FALSE)
        {   
           
            dm_self_start_flag = MMI_TRUE;
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_SIM_PROCESS_INIT_START);

            memset(&dm_self_reg_info, 0, sizeof(mmi_dm_sr_info_struct));
            dm_self_reg_info.repeat_send_sms_times = DM_SR_REPEAT_TIMES;
 
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */        
	            mmi_dm_sr_get_imsi();
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
        }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
}
mmi_sim_enum srv_dm_sr_get_used_sim(void)
{    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_sim_enum stat = MMI_SIM_NONE; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (dm_self_reg_info.is_self_reg_succuss != TRUE)
    {
		stat = MMI_SIM_NONE; 
    }
    else if (dm_self_reg_info.sim == MMI_SIM1)
    {
		stat = MMI_SIM1;
    }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
    return stat;
}


#ifdef __MMI_DUAL_SIM__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 
/* under construction !*/
#endif
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
#ifdef __OP01__    
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
/* under construction !*/
#else
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif    
/* under construction !*/
#if 0 //only when sim card changed can do register; flight mode should not do register
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
#endif
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
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_content_info_req
 * DESCRIPTION
 *  DM Self-Register get sms content information request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_content_info_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type = dm_self_reg_info.check_get_info_type;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_CONTENT_INFO_REQ, type);
	switch (type)
	{			
		case DM_SR_GET_IMEI_REQ:
			mmi_dm_sr_get_imei_req();
			break;
			
		case DM_SR_GET_MANUFACTOR_REQ:
			mmi_dm_sr_get_equip_info_req(0);
			break;
			
		case DM_SR_GET_DEVICE_MODEL_REQ:
			mmi_dm_sr_get_equip_info_req(1);		
			break;
			
		case DM_SR_GET_SOFTWARE_VERSION_REQ:
			mmi_dm_sr_get_equip_info_req(2);		
			break;
			
		default:
			break;					
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_content_info_rsp
 * DESCRIPTION
 *  DM Self-Register get content information response
 * PARAMETERS
 *  inMsg       [IN]        Input message
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_content_info_rsp(void *inMsg, int mod)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 type = dm_self_reg_info.check_get_info_type;
	U8 result = FALSE;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_CONTENT_INFO_RSP, type);	

    switch (type)
	{
		case DM_SR_GET_IMEI_REQ:
			{
    			mmi_nw_get_imei_rsp_struct *dataPtr = (mmi_nw_get_imei_rsp_struct*) inMsg;
    			ClearProtocolEventHandler(MSG_ID_MMI_NW_GET_IMEI_RSP);

			    if (dataPtr->result == 1)
			    {
			    	result = TRUE;
			        strcpy(dm_self_reg_info.IMEI_string, (S8*) dataPtr->imei);
	//				MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_get_content_info_rsp dm_self_reg_info.IMEI_string = %s", dm_self_reg_info.IMEI_string);				
			    }
			}
			break;
			
		case DM_SR_GET_MANUFACTOR_REQ:
			{
			    mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
			        strcpy(dm_self_reg_info.manufacture_name, (S8*)data_ptr->equip_id);
	//				MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_get_content_info_rsp dm_self_reg_info.manufacture_name = %s", dm_self_reg_info.manufacture_name);
				}
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		case DM_SR_GET_DEVICE_MODEL_REQ:
			{
				mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
					strcpy(dm_self_reg_info.device_model, (S8*)data_ptr->equip_id);
	//		    	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_get_content_info_rsp dm_self_reg_info.device_model = %s", dm_self_reg_info.device_model);
			    }
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		case DM_SR_GET_SOFTWARE_VERSION_REQ:
			{
			    mmi_eq_get_equip_id_rsp_struct *data_ptr = (mmi_eq_get_equip_id_rsp_struct*) inMsg;
				ClearProtocolEventHandler(MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);

			    if (data_ptr->result == 1)
			    {
                    result = TRUE;
					strcpy(dm_self_reg_info.software_version, (S8*)data_ptr->equip_id);
	//		    	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_get_content_info_rsp dm_self_reg_info.software_versio = %s", dm_self_reg_info.software_version);
			    }
			    else
			    {
			        MMI_ASSERT(0);
			    }
			}
			break;
			
		default:
			break;					
	}

    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_CONTENT_INFO_RSP_RESULT, result);	

	if (result == TRUE)
	{
		dm_self_reg_info.check_get_info_type++;	

		if(dm_self_reg_info.check_get_info_type < DM_SR_GET_INFO_REQ_TOTAL)
		{
			mmi_dm_sr_get_content_info_req();
		}
		else if(dm_self_reg_info.check_get_info_type == DM_SR_GET_INFO_REQ_TOTAL)
		{
            mmi_dm_sr_send_port_sms();
		}
	}
    else
    {    
        if(dm_self_reg_info.sim == MMI_SIM1)
        {
            dm_self_start_flag = MMI_FALSE;
        }
    #ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif    
    }
}
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_imsi
 * DESCRIPTION
 *  DM Self-Register get imsi 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_imsi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL status = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_IMSI);

    status = srv_sim_ctrl_get_imsi(MMI_SIM1, SIM1_IMSI, DM_SR_IMSI_SIZE); 
    if (status == TRUE) 
    {
        mmi_dm_sr_imsi_process();
    }
    else
    { 
	    if (dm_self_imsi_repeat_time > 0)
	    {
            StartTimer(DM_SR_IMSI_REPEAT_TIMER_ID, DM_SR_REPEAT_GET_IMSI_TIME, mmi_dm_sr_repeat_get_imsi);
	    }
	    else
	    {
            dm_self_reg_info.is_self_reg_succuss = FALSE;
            dm_self_start_flag = MMI_FALSE;
            mmi_dm_sr_write_nvram();
	    }
    }

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_repeat_get_imsi
 * DESCRIPTION
 *  DM Self-Register repeat send the regiser sms if failed
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_repeat_get_imsi(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_REPEAT_GET_IMSI, dm_self_imsi_repeat_time);
    StopTimer(DM_SR_IMSI_REPEAT_TIMER_ID);
    dm_self_imsi_repeat_time--;
    mmi_dm_sr_get_imsi();
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_imsi_process
 * DESCRIPTION
 *  DM Self-Register process imsi 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_imsi_process(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_dm_sr_result_ind_struct *data_ptr = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
 //  MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_IMSI_PROCESS);

    memcpy(dm_self_reg_info.IMSI_number, SIM1_IMSI, DM_SR_IMSI_SIZE);
 //   MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_imsi_process dm_self_reg_info.IMSI_number = %s", dm_self_reg_info.IMSI_number);

                
    mmi_dm_sr_read_nvram();

#ifndef __MMI_DUAL_SIM__
	if (SMU_SIM_REPLACED != check_sim_status() && dm_self_reg_info.is_self_reg_succuss == TRUE)
	{
		data_ptr = (srv_dm_sr_result_ind_struct* )OslConstructDataPtr(sizeof(srv_dm_sr_result_ind_struct));
        data_ptr->sim = dm_self_reg_info.sim;
        mmi_dm_sr_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_DM_SELF_REGISTER_RESULT_IND, (oslParaType*) data_ptr, NULL);
	}
    else
#endif
    {
	    if (dm_self_reg_info.is_self_reg_succuss == TRUE)
        {
	        dm_self_reg_info.is_self_reg_succuss = FALSE;
            mmi_dm_sr_write_nvram();
	    }
                   
        if (mmi_dm_sr_check_is_operator_sim_card(MMI_SIM1) == MMI_TRUE)
	    {
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_IMSI_RSP_OP);

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
            mmi_dm_sr_get_sms_numbers();
	    }
        else
        {
            dm_self_start_flag = MMI_FALSE;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_check_is_operator_sim_card
 * DESCRIPTION
 *  DM Self-Register check whether the sim card is OP 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static MMI_BOOL mmi_dm_sr_check_is_operator_sim_card(mmi_sim_enum sim_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//	S8* tmp_imsi = dm_self_reg_info.IMSI_number;
	MMI_BOOL status = MMI_FALSE;
	S8 sim_plmn[SRV_MAX_PLMN_LEN+1];
	S8 nw_plmn[SRV_MAX_PLMN_LEN+1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_CHECK_OP_SIM_CARD, dm_self_reg_info.IMSI_number, (dm_self_reg_info.IMSI_number + 1));

	status = srv_nw_info_get_nw_plmn(sim_id, nw_plmn, SRV_MAX_PLMN_LEN+1);
	//MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_check_is_operator_sim_card status = %d, sim_id = %d, nw_plmn = %s", status, sim_id, nw_plmn);

	if (status == MMI_FALSE)
	{
//	    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_PLMN_WR);
	    return MMI_FALSE;
	}
	status = srv_sim_ctrl_get_home_plmn(sim_id, sim_plmn, SRV_MAX_PLMN_LEN+1);
//	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_check_is_operator_sim_card status = %d, sim_id = %d, sim_plmn = %s", status, sim_id, sim_plmn);

	if ((strncmp(sim_plmn, DM_SR_OP_NUM_1, DM_SR_OP_NUM_LEN) == 0) || 
              (strncmp(sim_plmn, DM_SR_OP_NUM_2, DM_SR_OP_NUM_LEN) == 0) ||
                (strncmp(sim_plmn, DM_SR_OP_NUM_3, DM_SR_OP_NUM_LEN) == 0))
	{
	    if((strncmp((S8*)nw_plmn, DM_SR_OP_NUM_1, DM_SR_OP_NUM_LEN) == 0) ||
                (strncmp((S8*)nw_plmn, DM_SR_OP_NUM_2, DM_SR_OP_NUM_LEN) == 0) ||
                  (strncmp((S8*)nw_plmn, DM_SR_OP_NUM_3, DM_SR_OP_NUM_LEN) == 0))
            {
                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_CHECK_OP_NET_SIM_RGT);
                return MMI_TRUE;
            }
            else
            {
                MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_CHECK_OP_NET_SIM_WRO);
                return MMI_FALSE;
            }
	}
	else
	{
            MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_CHECK_OP_SIM_WRO);
            return MMI_FALSE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_imei_req
 * DESCRIPTION
 *  DM Self-Register get IMEI request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_imei_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_IMEI_REQ);
    SetProtocolEventHandler(mmi_dm_sr_get_content_info_rsp, MSG_ID_MMI_NW_GET_IMEI_RSP);	
	
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else			
    mmi_dm_sr_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_NW_GET_IMEI_REQ, NULL, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_equip_info_req
 * DESCRIPTION
 *  DM Self-Register get equip information request
 * PARAMETERS
 *  equip_id       [IN]        equip type(manufacture name, device model, software version)
 * RETURNS
 *  void
 *****************************************************************************/	
static void mmi_dm_sr_get_equip_info_req(U8 equip_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_eq_get_equip_id_req_struct* data_ptr = NULL;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_EQUIP_INFO_REQ, equip_id);
	data_ptr = (mmi_eq_get_equip_id_req_struct* )OslConstructDataPtr(sizeof(mmi_eq_get_equip_id_req_struct));
	data_ptr->equip_type = equip_id;

	SetProtocolEventHandler(mmi_dm_sr_get_content_info_rsp, MSG_ID_MMI_EQ_GET_EQUIP_ID_RSP);
	mmi_dm_sr_send_message(MOD_MMI, MOD_L4C, 0, MSG_ID_MMI_EQ_GET_EQUIP_ID_REQ, (oslParaType*) data_ptr, NULL);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_nvram
 * DESCRIPTION
 *  DM Self-Register read dm reigister status before and the register destination number from NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_read_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
 	ReadValue(NVRAM_DM_SELF_REGISTER_RESULT, &dm_self_reg_info.is_self_reg_succuss, DS_BYTE, &error);
//#ifdef __MMI_DUAL_SIM__
 	ReadValue(NVRAM_DM_SELF_REGISTER_SIM, &dm_self_reg_info.sim, DS_BYTE, &error);
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_READ_NVRAM_RESULT_SIM, dm_self_reg_info.sim);
//#endif
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_READ_NVRAM_RESULT, dm_self_reg_info.is_self_reg_succuss);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_write_nvram
 * DESCRIPTION
 *  DM Self-Register write the register result to NVRAM
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_write_nvram(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;
	mmi_sim_enum sim;
	
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_WRITE_NVRAM);	
    WriteValue(NVRAM_DM_SELF_REGISTER_RESULT, &dm_self_reg_info.is_self_reg_succuss, DS_BYTE, &error);
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
#else
	sim = MMI_SIM1;
	WriteValue(NVRAM_DM_SELF_REGISTER_SIM, &sim, DS_BYTE, &error);
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_WRITE_NVRAM_RESULT_SIM, dm_self_reg_info.sim);
#endif
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_WRITE_NVRAM_RESULT, dm_self_reg_info.is_self_reg_succuss);
}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_handle_sms_ready_ind
 * DESCRIPTION
 *  DM Self-Register Function
 * PARAMETERS
 *  dummy       [IN]        Input message
 *  mod         [IN]        Module type
 *  result      [IN]        Message Result
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_dm_sr_handle_sms_ready_ind(mmi_event_struct* event_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_sms_event_struct* sms_event_data;
    srv_sms_event_sms_ready_struct *event_info;
    U8 master_switch = 0;
    S16 error;
   /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_SMS_READY_IND);
    ReadValue(NVRAM_DM_SELF_REGISTER_MASTER_SWITCH, 
                 &master_switch, 
                 DS_BYTE, 
                 &error);
   
    if (master_switch == 0)
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_MASTER_SWITCH_RESULT, master_switch);
        return MMI_RET_OK;
    }

    sms_event_data = (srv_sms_event_struct*)event_data;
    event_info = (srv_sms_event_sms_ready_struct*)sms_event_data->event_info;

    if (srv_nw_usab_is_usable(MMI_SIM1))
    {
        MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_SIM_USABLE);
        
		if(event_info->is_sms_ready == MMI_TRUE && dm_self_first_network_ready != 0)
        {
            mmi_dm_sr_sim_process_init();
        }
    }

#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */

    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_send_port_sms
 * DESCRIPTION
 *  DM Self-Register send the register sms request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_send_port_sms(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    SMS_HANDLE sms_handler;
    S8 sms_addr[(CUI_SMS_MAX_ADDR_LEN + 1) *ENCODING_LENGTH];
    U16 addr_len;
    S16 error;
    S8* content_asc_buffer = NULL;
    S8* content_ucs2_buffer = NULL;
    U8 content_asc_str_len = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    sms_handler = srv_sms_get_send_handle();
    ReadRecord(NVRAM_EF_DM_SR_NUMBER_LID, 1, &dm_self_reg_info.des_number, NVRAM_EF_DM_SR_NUMBER_SIZE, &error);
    addr_len = mmi_asc_n_to_ucs2((S8*)sms_addr, dm_self_reg_info.des_number, CUI_SMS_MAX_ADDR_LEN);
    sms_addr[addr_len] = 0;
    sms_addr[addr_len+1] = 0;
    srv_sms_set_address(sms_handler, sms_addr);

    srv_sms_set_data_port(sms_handler, dm_self_reg_info.srcport_number, dm_self_reg_info.desport_number);

    srv_sms_set_status_report(sms_handler, MMI_FALSE);
    srv_sms_set_not_allow_empty_sc(sms_handler);
    srv_sms_set_no_sending_icon(sms_handler);

    srv_sms_set_content_dcs(sms_handler, SRV_SMS_DCS_8BIT);

    content_asc_str_len = strlen(DM_SR_SMS_HEADER) + strlen(dm_self_reg_info.IMEI_string) + 1
        #if defined(__OP02__)
						+ strlen(dm_self_reg_info.IMSI_number) + 1
        #endif
						+ strlen(dm_self_reg_info.manufacture_name) + 1
						+ strlen(dm_self_reg_info.device_model) + 1
						+ strlen(dm_self_reg_info.software_version);

    if (content_asc_str_len > DM_SR_MAX_SMS_LEN)
    {
        return;
    }

    content_asc_buffer = (S8*)OslMalloc(content_asc_str_len + 1);
    memset(content_asc_buffer, 0, (content_asc_str_len + 1));

    strcpy(content_asc_buffer, (S8*)DM_SR_SMS_HEADER);
    strcat(content_asc_buffer, dm_self_reg_info.IMEI_string);
    strcat(content_asc_buffer, "/");
#if defined(__OP02__)
    strcat(content_asc_buffer, dm_self_reg_info.IMSI_number);
    strcat(content_asc_buffer, "/");
#endif    
    strcat(content_asc_buffer, dm_self_reg_info.manufacture_name);
    strcat(content_asc_buffer, "/");	
    strcat(content_asc_buffer, dm_self_reg_info.device_model);
    strcat(content_asc_buffer, "/");
    strcat(content_asc_buffer, dm_self_reg_info.software_version);

    content_ucs2_buffer = (S8*)OslMalloc((content_asc_str_len + 1) * 2);
    memset(content_ucs2_buffer, 0, ((content_asc_str_len + 1) * 2));

    mmi_asc_to_ucs2(content_ucs2_buffer, content_asc_buffer);
//    srv_sms_set_content(sms_handler, content_ucs2_buffer, ((content_asc_str_len + 1) * 2));
    srv_sms_set_content(sms_handler, content_asc_buffer, ((content_asc_str_len + 1) ));

#ifdef __MMI_DUAL_SIM__
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
	srv_sms_set_sim_id(sms_handler, SRV_SMS_SIM_1);
#endif

    srv_sms_send_msg(sms_handler, mmi_dm_sr_send_port_sms_callback, NULL);

    OslMfree(content_asc_buffer);
    OslMfree(content_ucs2_buffer);

}


/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_send_port_sms
 * DESCRIPTION
 *  DM Self-Register send the register sms request
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_dm_sr_send_port_sms_callback(srv_sms_callback_struct* callback_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
//#ifdef __MMI_DUAL_SIM__
    srv_dm_sr_result_ind_struct *data_ptr = NULL;
//#endif
    S16 error_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if (callback_data->result == MMI_TRUE)
	{
        dm_self_reg_info.is_self_reg_succuss = TRUE;
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#else
        dm_self_reg_info.sim = MMI_SIM1;
#endif /* __MMI_DUAL_SIM__ */
   
        WriteRecord(NVRAM_EF_DMSR_SIM_IMSI_LID, 1, dm_self_reg_info.IMSI_number, DM_SR_IMSI_SIZE, &error_code);

        mmi_dm_sr_write_nvram();
       

	    dm_self_start_flag = MMI_TRUE;
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
	    data_ptr = (srv_dm_sr_result_ind_struct* )OslConstructDataPtr(sizeof(srv_dm_sr_result_ind_struct));
        data_ptr->sim = dm_self_reg_info.sim;
        
        mmi_dm_sr_send_message(MOD_MMI, MOD_MMI, 0, MSG_ID_MMI_DM_SELF_REGISTER_RESULT_IND, (oslParaType*) data_ptr, NULL);

    }
    else
    {
        if (dm_self_reg_info.sim == MMI_SIM1)
        {
            dm_self_start_flag = MMI_FALSE;
        }
#ifdef __MMI_DUAL_SIM__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_DUAL_SIM__ */
        dm_self_reg_info.is_self_reg_succuss = FALSE;
        mmi_dm_sr_write_nvram();
        
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    }

}

#if 0
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef __MMI_DUAL_SIM__
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
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_get_sms_numbers
 * DESCRIPTION
 *  DM Self-Register read dm tree's des_number & port_number 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_get_sms_numbers(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S16 error;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
#if defined(__OP02_DM__)

        mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_READ_RSP, (PsIntFuncPtr)mmi_dm_sr_read_des_number_rsp, MMI_TRUE);
        mmi_dm_sr_read_des_number_req();

#else
	ReadRecord(NVRAM_EF_DM_SR_NUMBER_LID, 1, &dm_self_reg_info.des_number, NVRAM_EF_DM_SR_NUMBER_SIZE, &error);
	dm_self_reg_info.srcport_number = DM_SR_SCR_PORT;
	dm_self_reg_info.desport_number = DM_SR_DES_PORT;
//	MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_read_nvram dm_self_reg_info.des_number = %s", dm_self_reg_info.des_number);
//	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_DES_NUMBER_RESULT, dm_self_reg_info.des_number);
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_SRC_PORT_NUMBER_RESULT, dm_self_reg_info.srcport_number);
	MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_DES_PORT_NUMBER_RESULT, dm_self_reg_info.desport_number);

    mmi_dm_sr_get_content_info_req();        

#endif


}


#if defined(__OP02_DM__)
/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_des_number_req
 * DESCRIPTION
 *  DM Self-Register read dm tree's des_number 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_read_des_number_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_req_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    read_ptr = (dm_node_op_read_req_struct*)construct_local_para(sizeof(dm_node_op_read_req_struct), TD_RESET);

    read_ptr->request_app = DM_NODE_OP_APP_SR;
    strcpy((char*)read_ptr->uri, (const char*)DM_SR_DES_NUM_URI);

    MMI_SEND_MSG_TO_DM(MSG_ID_DM_NODE_OP_READ_REQ, read_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_des_number_rsp
 * DESCRIPTION
 *  Response of read dm tree's des_number & port_number 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dm_sr_read_des_number_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_rsp_struct *ptr = (dm_node_op_read_rsp_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    
    if(ptr->request_app != DM_NODE_OP_APP_SR)
    {
        return MMI_FALSE;
    }
    else
    {
        if(strcmp((const char*)ptr->uri, (const char*)DM_SR_DES_NUM_URI)!=0)
        {
            return MMI_FALSE;
        }
        else
        {
            if(ptr->result != DM_RESULT_ERR_SUCC)
            {
                dm_self_reg_info.is_self_reg_succuss = FALSE;
                mmi_dm_sr_write_nvram();
            }
            else
            {
                if(ptr->data_type != DM_DATA_TYPE_S8)
                {
                    MMI_ASSERT(0);
                }
                else if(ptr->data_length == 0)
                {
                    MMI_ASSERT(0);
                }
                else
                {
                    strncpy((char*)dm_self_reg_info.des_number, (const char*)ptr->data, ptr->data_length);
//                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_DES_NUMBER_RESULT, dm_self_reg_info.des_number);
//                    MMI_PRINT(MOD_MMI_CONN_APP, MMI_CONN_TRC_G3_DM, "[DM SR][Function] mmi_dm_sr_read_nvram dm_self_reg_info.des_number = %s", dm_self_reg_info.des_number);

                    mmi_frm_set_protocol_event_handler(MSG_ID_DM_NODE_OP_READ_RSP, (PsIntFuncPtr)mmi_dm_sr_read_port_number_rsp, MMI_TRUE);
                    mmi_dm_sr_read_port_number_req();
                }
            }
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_port_number_req
 * DESCRIPTION
 *  DM Self-Register read dm tree's port_number 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_dm_sr_read_port_number_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_req_struct *read_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	

    read_ptr = (dm_node_op_read_req_struct*)construct_local_para(sizeof(dm_node_op_read_req_struct), TD_RESET);

    read_ptr->request_app = DM_NODE_OP_APP_SR;
    strcpy((char*)read_ptr->uri, (const char*)DM_SR_PORT_NUM_URI);

    MMI_SEND_MSG_TO_DM(MSG_ID_DM_NODE_OP_READ_REQ, read_ptr);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_read_port_number_rsp
 * DESCRIPTION
 *  DM Self-Register read dm tree's des_number & port_number 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL mmi_dm_sr_read_port_number_rsp(void *inMsg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    dm_node_op_read_rsp_struct *ptr = (dm_node_op_read_rsp_struct *)inMsg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    
    if(ptr->request_app != DM_NODE_OP_APP_SR)
    {
        return MMI_FALSE;
    }
    else
    {
        if(strcmp((const char*)ptr->uri, (const char*)DM_SR_PORT_NUM_URI)!=0)
        {
            return MMI_FALSE;
        }
        else
        {
            if(ptr->result != DM_RESULT_ERR_SUCC)
            {
                dm_self_reg_info.is_self_reg_succuss = FALSE;
                mmi_dm_sr_write_nvram();
            }
            else
            {
                if(ptr->data_type != DM_DATA_TYPE_S8)
                {
                    MMI_ASSERT(0);
                }
                else if(ptr->data_length == 0)
                {
                    MMI_ASSERT(0);
                }
                else
                {
                    dm_self_reg_info.srcport_number = mmi_dm_sr_hx_atoi((const S8*)ptr->data);
                    dm_self_reg_info.desport_number = dm_self_reg_info.srcport_number;
                    MMI_TRACE(MMI_CONN_TRC_G3_DM, MMI_DM_TRC_SR_GET_DES_PORT_NUMBER_RESULT, dm_self_reg_info.desport_number);

                    mmi_dm_sr_get_content_info_req();
                }
            }
        }
    }
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_dm_sr_hx_atoi
 * DESCRIPTION
 *  
 * PARAMETERS
 *  s       [IN]        
 * RETURNS
 *  
 *****************************************************************************/
static U16 mmi_dm_sr_hx_atoi(const char *s)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 n = 0;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (s[i] != '\0')
    {
        n *= 16;

	if('0'<=s[i] && s[i]<='9')
	{
		n += s[i] - '0';
	}
	else if('a'<=s[i] && s[i]<='f')
	{
		n += (s[i] - 'a') + 10;
	}
	else if('A'<=s[i] && s[i]<='F')
	{
		n += (s[i] - 'A') + 10;
	}
	else
	{
		MMI_ASSERT(0);
	}
	
        i++;
    }
    return n;
}

#if 0
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
#endif

#endif
#endif /*__MMI_DM_SELF_REGISTER_SUPPORT__*/
