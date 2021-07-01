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
 * BtDialersrv.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/
#include "BTDialerSrvGprot.h"

#ifndef __BTDIALER_SRV_H__
#define __BTDIALER_SRV_H__

#ifdef __MMI_HF_SUPPORT__

#define MMI_HF_INVALID_CONN_ID        0xFF
#define MMI_HF_INVALID_CM_CONN_ID     0xFFFFFFFF
#define MMI_HF_TEMP_CONN_ID           0xCC
#define MMI_RET_OK          (0)         /* the return value of mmi_ret */
#define BT_MAX_SRV_HD       (2)

#define SRV_BT_DIALER_AT_CMD_EVENT	20
#define MMI_HF_CONN_CNF_ACCEPT 		 1
#define MMI_HF_CONN_CNF_REJECT 		 0
#define srv_bt_dialer_IsListEmpty(ListHead) (((ListHead)->Flink == (ListHead)))
#define srv_bt_dialer_GetHeadList(ListHead) ((ListHead)->Flink)

//typedef unsigned int U32;
#define SRV_BT_DIALER_LOG(x)                            \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x);                 \
   }
#define SRV_BT_DIALER_LOG1(x, x1)                       \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1);             \
   }
#define SRV_BT_DIALER_LOG2(x, x1, x2)                   \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2);         \
   }

#define SRV_BT_DIALER_LOG3(x, x1, x2, x3)               \
   {                                                    \
      MMI_TRACE(MMI_CONN_TRC_G7_BT, x, x1, x2, x3);     \
   }


/*****************************************************************************
 * Enum
 *  srv_bt_dialer_at_cmd_type_enum
 * DESCRIPTION
 * AtCommands type
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void

 *****************************************************************************/
typedef  enum
{
    SRV_BT_DIALER_AT_NONE, //0

    /** Command to dial a phone number. The AtHandsfreeCmd.dial parameter is valid.
           */
    SRV_BT_DIALER_AT_DIAL_NUMBER, // 1

    SRV_BT_DIALER_AT_ANSWER, // 2

    /** This command allows calls can be put on hold, recovered, released, added 
         *  to conversation, and transferred. The test command can be issued to request
         *  a list of supported operations. The AtHandsfreeCmd.hold parameter is valid.
         */
    SRV_BT_DIALER_AT_CALL_HOLD, // 3
    /** This command instructs the ME to hangup the current GSM call. There are
         *  no parameters.
         */
    SRV_BT_DIALER_AT_HANG_UP, // 4

    /** This command is used to call the last phone number dialed. On reception,
         *  the ME shall set up a voice call to the last phone number dialed. There
         *  are no parameters to this command.
         */
    SRV_BT_DIALER_AT_REDIAL, // 5

    /**  */
    SRV_BT_DIALER_AT_MICROPHONE_GAIN, // 6

    /**  */
    SRV_BT_DIALER_AT_SPEAKER_GAIN, // 7

    /** This command is used by the TE to read the current "Response and Hold"
         *  state of the ME. This command may also be used to set the response
         *  and hold state on the ME of an incoming call. The unsolicited result
         *  code is used to indicate when an incoming call is either put on hold,
         *  accepted or rejected. The "btrh" parameters are used with this command.
         */
    SRV_BT_DIALER_AT_RESPONSE_AND_HOLD, // 8

    /** Command to dial a number from memory. The AtHandsfreeCmd.dial parameter is
         *  valid. 
         */
    SRV_BT_DIALER_AT_DIAL_MEMORY, // 9

    /** This command is used to request a list of the current calls. The result
         *  indicates each current call and its information. The "currentCall"
         *  parameter is used with the result of this command.
         */
    SRV_BT_DIALER_AT_LIST_CURRENT_CALLS, // 10

/*******************************************************************/

    /** This command enables/disables presentation of the calling line identity
         *  (CLI) to the subscriber. An unsolicited result is used to indicate the
         *  identity to the TE. The "callId" parameter is used with this command.
         */
    SRV_BT_DIALER_AT_CALL_ID, // 11

    /** This command allows the transmission of DTMF and arbitrary tones. These
         *  tones may be used (for example) when announcing the start of a recording
         *  period. The "dtmf" parameter is used with this command.
         */
    SRV_BT_DIALER_AT_GENERATE_DTMF_TONE, // 12

    /** The TE may test and read the status of the the ME indicators. Received
         *  unsolicited indicator result messages are indicated by AT_INDICATOR_EVENT.
         */
    SRV_BT_DIALER_AT_EVENT_REPORTING, // 13

    /** Command used for requesting the phone number corresponding to the last
         *  voice tag recorded in the ME. There are no parameters to this command.
         */
    SRV_BT_DIALER_AT_VOICE_TAG, // 14

    /** This command enables/disables the voice recognition function in the ME.
         *  The unsolicited result code is used to indicate when the voice recognition
         *  setting was changed autonomously on the ME. The "vrec" parameter is used
         *  with this command.
         */
    SRV_BT_DIALER_AT_VOICE_RECOGNITION, // 15

    /** This command is issued to disable any Echo Canceling and Noise Reduction
         *  functions embedded in the ME. There are no parameters to this command.
         */
    SRV_BT_DIALER_AT_ECHO_C_AND_NOISE_R, // 16

    /** This command allows control of the Call Waiting supplementary service. 
         *  An unsolicited result is used to indicate the presence of a call. The
         *  "wait" parameter is used with this command.
         */
    SRV_BT_DIALER_AT_CALL_WAIT_NOTIFY, // 17

    /** This command is used to request the Subscriber Number information from
         *  the ME. The result provides "subscriberNum" parameters.
         */
    SRV_BT_DIALER_AT_SUBSCRIBER_NUM, // 18

    /** This command is used for reading, selecting and registering the network
         *  operator. The response is used to return the current mode and the currently
         *  selected operator.  The "networkOper" and "networkOper_read" parameters
         *  are used with this command.
         */
    SRV_BT_DIALER_AT_NETWORK_OPERATOR, // 19

    /**Set Network operator format.
         */
    SRV_BT_DIALER_AT_SET_NETWORK_OPERATOR_FORMAT, // 20

/*******************************************************************/
    /* unused type  */
    SRV_BT_DIALER_AT_KEYPAD_CONTROL, // 21

    /** This unsolicited result code is used to report an indicator status change.
         */
    SRV_BT_DIALER_AT_INDICATOR_EVENT, // 22

    /** The test command is used to retrieve the mapping between each indicator
         *  supported by the ME and its corresponding range and order index. The TE
         *  can retrieve the current status of the indicators by issuing a read
         *  command. There are no parameters to this command.
         */
    SRV_BT_DIALER_AT_INDICATORS, // 23

    /** This command and result are used for exchanging the supported features
         *  list between the TE and ME. The "features" parameter is used with this
         *  command.
         */
    SRV_BT_DIALER_AT_SUPPORTED_FEATURES, // 24

    /** An unsolicited result code issued by the ME to indicate to the TE that
         *  the in-band ring tone setting has been locally changed. The TE may react
         *  accordingly by changing its own alert method.
         */
    SRV_BT_DIALER_AT_IN_BAND_RING_TONE, // 25

    /** Only for IOS, Enable custom AT commands from a headset.
         */
    SRV_BT_DIALER_AT_XAPL, // 26

    /** Only for IOS, Report a headset state change.
         */
    SRV_BT_DIALER_AT_IPHONEACCEV, // 27

    SRV_BT_DIALER_AT_CMD_TYPE_TOTAL
}srv_bt_dialer_at_cmd_type_enum;

/*****************************************************************************
 * Enum
 *  srv_bt_dialer_state_enum
 * DESCRIPTION
 * AtCommands type
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
typedef enum
{
    SRV_BTD_STATE_IDLE,
    SRV_BTD_STATE_ACTIVATING,
    SRV_BTD_STATE_ACTIVATED,
    SRV_BTD_STATE_DEACTIVATING,
    SRV_BTD_STATE_DEACTIVATED,
    SRV_BTD_STATE_INVALID
} srv_bt_dialer_serv_state_enum;

/*****************************************************************************
 * Enum
 *  srv_bt_dialer_state_enum
 * DESCRIPTION
 * AtCommands type
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
typedef enum
{
	SRV_BTD_DEV_STATE_IDLE,
	SRV_BTD_DEV_STATE_CONNECTING,
	SRV_BTD_DEV_STATE_CONNECTED,
	SRV_BTD_DEV_STATE_DISCONNECTING,
	SRV_BTD_DEV_STATE_INVALID
} srv_bt_dialer_dev_state_enum;

/*****************************************************************************
 * Enum
 *  srv_bt_dailer_at_cmd_hold_action_enum
 * DESCRIPTION
 * Hold action enum
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
typedef enum
{
	/** Release all held calls or sets User Determined User Busy(UDUB) for a waiting call
	 */
	SRV_BT_DIALER_AT_HOLD_RELEASE_HELD_CALLS,
	
	/** Releases all active calls (if any exist) and accepts the other
	 *  (held or waiting) call. If "call" is specified, will release the
	 *  specific call.
	 */
	SRV_BT_DIALER_AT_HOLD_RELEASE_ACTIVE_CALLS,

	/** Places all active calls (if any exist) on hold and accepts the other
	 *  (held or waiting) call. If "call" is specified, places all active calls
	 *  on hold except the specified call.
	 */
	SRV_BT_DIALER_AT_HOLD_HOLD_ACTIVE_CALLS,

	/** Adds a held call to the conversation. 
	 */
	SRV_BT_DIALER_AT_HOLD_ADD_HELD_CALL,

	/** Connects the two calls and disconnects the AG from both calls
	 *  (Explicit Call Transfer).
	 */
	SRV_BT_DIALER_AT_HOLD_EXPLICIT_TRANSFER,

	/* End of AtHoldAction */

}srv_bt_dailer_at_cmd_hold_action_enum;

/*****************************************************************************
 * Union
 *  srv_bt_dialer_AtHfCmd_struct
 * DESCRIPTION
 * Sending Handsfree command
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
typedef union {   
 
    /* AT_DIAL_NUMBER */   
    struct {   
        const char     *number;   
    } dial;

    /* AT_DIAL_MEMORY */
    struct {   
        U32 index;   
    } mem_dial;

    /* AT_CALL_WAIT_NOTIFY */   
    struct {   
        /* Enable/Disable the presentation of the AT_CALL_WAIT_NOTIFY
         * unsolicited result code.   
         */   
        U8              notify;   
    } wait;   
   
    /* AT_CALL_HOLD */   
    struct {   
        /* Call hold procedure to perform. */   
        srv_bt_dailer_at_cmd_hold_action_enum    action;   
   
        /* If "action" is AT_HOLD_RELEASE_ACTIVE_CALLS or    
         * AT_HOLD_HOLD_ACTIVE_CALLS, this value can be used to specify
         * the index (1 - 9) of a specific call to address.   
         */   
        U8              call;   
    } hold;   
   
    /* AT_CALL_ID */   
    struct {   
        BOOL            enabled;   
    } callId;   
   
    /* AT_EVENT_REPORTING */   
    struct {   
        U8              mode;   
        U8              ind;   
    } report;   
           
    /* AT_GENERATE_DTMF_TONE */   
    struct {   
        U8              tone;   
    } dtmf;   
   
    /* AT_VOICE_RECOGNITION */   
    struct {   
        MMI_BOOL            enabled;   
    } vrec;   
   
    /* AT_RESPONSE_AND_HOLD */   
    struct {   
        srv_bt_dialer_AtResponseHold_enum  setting;   
		srv_bt_dialer_AtResponseHoldtype_enum  at_type;
    } btrh;   
   
    /* AT_NETWORK_OPERATOR */   
    struct {   
        /* 0 = automatic, 1 = manual, 2 = deregister, 3 = set format only, 
         * 4 = manual/automatic.   
         */   
        U8              mode;   
   
        /* Format of "oper" parameter (0-3) */   
        srv_bt_dialer_AtOperFormat_enum    format;   
    } networkOper;

    /* AT_SPEAKER_GAIN */
    struct{
        U8 gain;
    }vgs;

    /* AT_MICROPHONE_GAIN */
    struct{
        U8 gain;
    }vgm;
    struct{
        U8 features;
    }xapl;
#ifdef __MMI_HF_BAT_SUPPORT__
    struct{
        U8 key; // bitwise
        U8 bat;
        U8 pow;
    }accev;
#endif /* __MMI_HF_BAT_SUPPORT__ */
} srv_bt_dialer_AtHfCmd_struct;   

/*****************************************************************************
 * Structure
 *  srv_bt_dialer_send_at_cmd_struct
 * DESCRIPTION
 * Internal Util Structure
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void

 *****************************************************************************/
typedef struct _srv_bt_dialer_send_at_cmd_struct
{
    U8 conn_id;
    srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd;
    srv_bt_dialer_at_cmd_type_enum type;
    struct _srv_bt_dialer_send_at_cmd_struct *Flink;
} srv_bt_dialer_send_at_cmd_struct;

/*****************************************************************************
 * Structure
 *  srv_bt_dialer_dev_info_struct
 * DESCRIPTION
 * Global Structure
 * CALLS
 * PARAMETERS
 * RETURNS
 *  void
 *****************************************************************************/
typedef struct
{
    MMI_BOOL hs_conn;
    MMI_BOOL alloc;
    MMI_BOOL bsir_enable;
    MMI_BOOL ciev_service;
    MMI_BOOL bvra_enable;
    MMI_BOOL callId;           /* State of caller id nofitication  */
    MMI_BOOL callWaiting;      /* State of call waiting            */
    MMI_BOOL bt_call_unallowed;
    MMI_BOOL post_evt;
    MMI_BOOL sco_auto;
#ifdef __BT_DIALER_HF_NO_IN_BAND_TONE__
    MMI_BOOL inband_muted;
#endif
    
    U8 ciev_call;
    U8 callsetup;
    U8 callheld;    
    U8 ciev_signal;
    U8 ciev_roam;
    U8 ciev_battchg;
    U8 btrh_n;    
    U8 bsir_bqb_state;
    U8 conn_id;
    U8 dev_ref;
    MMI_BOOL querying;
    MMI_BOOL indication;

    srv_bt_dialer_enable_features_enum enable_mask;
    U16 ind_mask;
    U16 call_count;
    U32 cm_conn_id;    
    
    S32 srv_hd;
    S32 state;
    srv_bt_dialer_at_cmd_type_enum pending_action;

    srv_bt_cm_bt_addr bd_addr;
    srv_bt_dialer_notify_hf_event cb_ptr;
    srv_bt_dialer_cm_connect_notify cm_cb;
#ifdef __MMI_WEARABLE_DEVICE__
    srv_bt_dialer_single_connect_notify sg_conn_cb; // single connection callback
#endif /* __MMI_WEARABLE_DEVICE__ */
} srv_bt_dialer_dev_info_struct;

typedef struct
{
    MMI_BOOL bt_call_unallowed;
    U8 conn_dev_count;
    U8 sco_allow;
    srv_bt_dialer_send_at_cmd_struct *hf_cmd; //send AT command
    srv_bt_dialer_serv_state_enum serv_state;
    srv_bt_dialer_notify_hf_connection_event connection_cb;
    srv_bt_cm_bt_addr last_dev_addr;
    srv_bt_dialer_dev_info_struct dev_info[BT_MAX_HF_DEV];
} srv_bt_dialer_context_struct;

void srv_bt_dialer_send_activate_req(void);
void srv_bt_dialer_send_deactivate_req(void);
void srv_bt_dialer_connect_ind(void *msg);
void srv_bt_dialer_send_disconnect_req(U32 cm_conn_id);
MMI_BOOL srv_bt_dialer_disconnect_ind(void* msg);
void srv_bt_dialer_HfExecuteNextCommand(void);
void srv_bt_dialer_add_node_to_list(U8 conn_id, srv_bt_dialer_AtHfCmd_struct *cmd, srv_bt_dialer_at_cmd_type_enum type);
static void srv_bt_dialer_send_ilm( void *local_para_ptr, msg_type msg_id, module_type dst_mod);
void srv_bt_dialer_InsertTailList(srv_bt_dialer_send_at_cmd_struct* entry);
void srv_bt_dialer_send_connect_ind_rsp(U8 conn_id, S32 accept);
void srv_bt_dialer_volume_gain_req(int gain);
void srv_bt_dialer_free_atcmd_queue(U8 index);
void srv_bt_dialer_set_hilite_dev(U8 conn_id, U8 setup, U8 call, U8 held);

MMI_BOOL srv_bt_dialer_volume_gain_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_vgm_ind_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_vgs_ind(void *msg);
MMI_BOOL srv_bt_dialer_activate_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_deactivate_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_connect_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_disconnect_cnf_hdlr(void *msg);
mmi_ret srv_bt_dialer_hf_proc_func(mmi_event_struct *evt);
srv_bt_dialer_send_at_cmd_struct * srv_bt_dialer_HfGetCurrentCommand(void);
void srv_bt_dialer_ata_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_ata_cnf_hdlr(void* msg);
void srv_bt_dialer_atd_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atd_cnf_hdlr(void* msg);
void srv_bt_dialer_atmem_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atmem_cnf_hdlr(void* msg);
void srv_bt_dialer_atbldn_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atbldn_cnf_hdlr(void* msg);
void srv_bt_dialer_atchup_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atchup_cnf_hdlr(void* msg);
void srv_bt_dialer_atcmee_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atcmee_cnf_hdlr(void* msg);
void srv_bt_dialer_atnrec_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atnrec_cnf_hdlr(void* msg);
void srv_bt_dialer_atvts_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atvts_cnf_hdlr(void* msg);
MMI_BOOL srv_bt_dialer_vgs_cnf_hdlr(void *msg);
void srv_bt_dialer_vgs_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
void srv_bt_dialer_atccwa_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atccwa_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_atclip_cnf_hdlr(void *msg);
void srv_bt_dialer_atclip_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atchld_cnf_hdlr(void *msg);
void srv_bt_dialer_atchld_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_volume_gain_cnf_hdlr(void *msg);
void srv_bt_dialer_set_atcops_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_set_atcops_cnf_hdlr(void *msg);
void srv_bt_dialer_atcops_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atcops_cnf_hdlr(void *msg);
MMI_BOOL srv_bt_dialer_atcnum_cnf_hdlr(void *msg);
void srv_bt_dialer_atcnum_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
void srv_bt_dialer_atbinp_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atbinp_cnf_hdlr(void *msg);
void srv_bt_dialer_atbtrh_read_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atbtrh_read_cnf_hdlr(void *msg);
#ifdef __BT_HF_BVRA_SUPPORT__
void srv_bt_dialer_atbvra_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atbvra_cnf_hdlr(void *msg);
#endif /* __BT_HF_BVRA_SUPPORT__ */
void srv_bt_dialer_atbtrh_set_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atbtrh_set_cnf_hdlr(void *msg);
void srv_bt_dialer_atclcc_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atclcc_cnf_hdlr(void *msg);
void srv_bt_dialer_vgm_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_vgm_cnf_hdlr(void *msg);
void srv_bt_dialer_atxapl_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_atxapl_cnf_hdlr(void* msg);
#ifdef __MMI_HF_BAT_SUPPORT__
void srv_bt_dialer_iphone_accev_req(srv_bt_dialer_send_at_cmd_struct* cmd_req);
MMI_BOOL srv_bt_dialer_iphone_accev_cnf_hdlr(void* msg);
#endif /* __MMI_HF_BAT_SUPPORT__ */

MMI_BOOL srv_bt_dialer_bsir_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_service_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_call_ind(void *msg);
MMI_BOOL srv_bt_dialer_callsetup_ind(void *msg);
MMI_BOOL srv_bt_dialer_callheld_ind(void *msg);

MMI_BOOL srv_bt_dialer_ciev_signal_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_roam_ind(void *msg);
MMI_BOOL srv_bt_dialer_ciev_battchg_ind(void *msg);
MMI_BOOL srv_bt_dialer_clip_ind(void *msg);
MMI_BOOL srv_bt_dialer_ccwa_ind(void *msg);
MMI_BOOL srv_bt_dialer_bvra_ind(void *msg);
MMI_BOOL srv_bt_dialer_btrh_ind(void *msg);
S32 srv_bt_dialer_convert_error_code(S32 error,S32 result_code);
MMI_BOOL srv_bt_dialer_ring_ind_hdlr(void *msg);
void srv_bt_dialer_send_connect_req(srv_bt_cm_bt_addr* bd_addr, srv_bt_dialer_cm_connect_notify srv_cm_cb);
/*Interface to send AT command of any type*/
MMI_BOOL srv_bt_dialer_send_at_command(S32 srv_hd,
                                    srv_bt_dialer_at_cmd_type_enum type,
                                    srv_bt_dialer_AtHfCmd_struct *btd_hf_cmd); 

extern void srv_bt_dialer_init(void);
extern void srv_bt_dialer_deinit(void);

srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_hd(S32 srv_hd);
MMI_BOOL srv_bt_dialer_is_serv_ready(void);
srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_conn_id(U8 conn_id);
srv_bt_dialer_dev_info_struct* srv_bt_dialer_get_dev_info_by_addr(srv_bt_cm_bt_addr* bd_addr);
void srv_bt_dialer_addr_transfer(void* out_addr, void* in_addr, MMI_BOOL bt_2_mmi);
mmi_ret srv_bt_dialer_sco_connection_event_hdlr(void *param);
#endif /*__MMI_HF_SUPPORT__*/

#endif /*__BTDIALER_SRV_H__*/