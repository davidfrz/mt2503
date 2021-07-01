
#ifndef SRV_UCM_BT_GPROT_H
#define SRV_UCM_BT_GPROT_H

#include "MMI_features.h"
#include "MMIDataType.h"
#include "kal_general_types.h"
#include "custom_mmi_default_value.h"
#include "BtcmSrvGprot.h" // srv_bt_cm_bt_addr

/* Maximum number length */
#define SRV_UCM_BT_MAX_NUM_URI_LEN (41)
#ifdef __MMI_PHB_PBAPC_SYNC_CONTACT__
#define SRV_UCM_BT_MAX_DIS_NAME_FROM_APP SRV_PHB_PBAPC_NAME_LENGTH
#else
#define SRV_UCM_BT_MAX_DIS_NAME_FROM_APP (41)
#endif
#define SRV_UCM_BT_MAX_DEV (__BT_MAX_LINK_NUM__)
#define SRV_UCM_BT_MAX_CALL (7)
#define SRV_UCM_BT_MAX_GROUP (3)

#define SRV_UCM_BT_ALL_DEV_MAX_CALL (SRV_UCM_BT_MAX_DEV*SRV_UCM_BT_MAX_CALL)
#define SRV_UCM_BT_ALL_DEV_MAX_GROUP (SRV_UCM_BT_MAX_DEV*SRV_UCM_BT_MAX_GROUP)
#define SRV_UCM_BT_MAX_DISP_NAME_LEN (MAX_SUBMENU_CHARACTERS)

#define SRV_UCM_BT_MAX_INSTANCE_NUM (5)

/* Call state enum */
typedef enum
{
    SRV_UCM_BT_BT_IDLE_STATE = 0x00, /* IDLE state */
    SRV_UCM_BT_OUTGOING_STATE = 0x01, /* Outgoing state */
    SRV_UCM_BT_INCOMING_STATE = 0x02, /* Incoming state */
    SRV_UCM_BT_ACTIVE_STATE = 0x04, /* Active state */
    SRV_UCM_BT_HOLD_STATE = 0x08, /* Hold state */
    SRV_UCM_BT_CALL_STATE_END_OF_ENUM /* End of the enum */
} srv_ucm_bt_call_state_enum;

typedef enum
{
    SRV_UCM_BT_SUCCESS = 0,
    SRV_UCM_BT_INVALD_PARA = -1,
    SRV_UCM_BT_REGISTERED = -2,
    SRV_UCM_BT_INST_FULL = -3,
    SRV_UCM_BT_UNKNOWN_ERR = -4,
} srv_ucm_bt_reg_result_enum;

#ifdef __BT_HF_BVRA_SUPPORT__
typedef enum
{
    SRV_UCM_BT_CONN_TYPE_SCO_OFF,
    SRV_UCM_BT_CONN_TYPE_SCO_ON,
    SRV_UCM_BT_CONN_TYPE_LINK_OFF,
    SRV_UCM_BT_CONN_TYPE_LINK_ON,
    SRV_UCM_BT_CONN_TYPE_TATAL
} srv_ucm_bt_conn_type;
#endif /* __BT_HF_BVRA_SUPPORT__ */

typedef enum
{
    SRV_UCM_BT_NOTI_EVT_NONE = 0x00,
    SRV_UCM_BT_NOTI_EVT_IND = 0x01,
    SRV_UCM_BT_NOTI_EVT_ACT = 0x02,
    SRV_UCM_BT_NOTI_EVT_CONN = 0x04,
    SRV_UCM_BT_NOTI_EVT_TOTAL
} srv_ucm_bt_notify_mask_enum;

#define SRV_UCM_BT_CALL_STATE_CONNECTED (srv_ucm_bt_call_state_enum) (SRV_UCM_BT_ACTIVE_STATE | SRV_UCM_BT_HOLD_STATE)
#define SRV_UCM_BT_CALL_STATE_MOMT (srv_ucm_bt_call_state_enum) (SRV_UCM_BT_INCOMING_STATE | SRV_UCM_BT_OUTGOING_STATE)
#define SRV_UCM_BT_CALL_STATE_ALL (srv_ucm_bt_call_state_enum)(SRV_UCM_BT_INCOMING_STATE|SRV_UCM_BT_OUTGOING_STATE|SRV_UCM_BT_ACTIVE_STATE | SRV_UCM_BT_HOLD_STATE)

/* Action opcode enum */
typedef enum
{
    SRV_UCM_BT_NO_ACT = 0, /* No action */
    SRV_UCM_BT_DIAL_ACT, /* Dial action, srv_ucm_bt_atd_act_req_struct, srv_ucm_bt_act_rsp_struct*/
    SRV_UCM_BT_REDIAL_ACT, /* Redial action, srv_ucm_bt_atd_act_req_struct, srv_ucm_bt_act_rsp_struct*/ 
    SRV_UCM_BT_ACCEPT_ACT, /* Accept action, srv_ucm_bt_ata_act_req_struct, srv_ucm_bt_act_rsp_struct*/
    SRV_UCM_BT_HOLD_ACT, /* Hold action, srv_ucm_bt_chld_act_req_struct, srv_ucm_bt_act_rsp_struct*/
    SRV_UCM_BT_RETRIEVE_ACT, /* Retrieve action, srv_ucm_bt_chld_act_req_struct, srv_ucm_bt_act_rsp_struct */
    SRV_UCM_BT_SWAP_ACT,  /* Swap action, srv_ucm_bt_chld_act_req_struct, srv_ucm_bt_act_rsp_struct */
    SRV_UCM_BT_END_SINGLE_ACT, /* End single action, srv_ucm_bt_end_single_act_req_struct, srv_ucm_bt_act_rsp_struct */
    SRV_UCM_BT_END_ALL_ACT, /* End all action, null, srv_ucm_bt_act_rsp_struct */
    SRV_UCM_BT_END_ALL_PROCESSING_ACT, /* End all processing action, null, srv_ucm_bt_act_rsp_struct */
    SRV_UCM_BT_BVRA_ACT, /* srv_ucm_bt_bvra_act_req_struct */
    SRV_UCM_BT_SEND_DTMF_ACT, /* Send DTMF action, srv_ucm_bt_dtmf_act_req_struct, no response */
    SRV_UCM_BT_FORCE_REFRESH_ACT, /* srv_ucm_bt_force_refresh_act_req_struct */
    SRV_UCM_BT_NEW_DEV,
    SRV_UCM_BT_DEL_DEV,
    SRV_UCM_BT_SWITCH_AUDIO_PATH, /* srv_ucm_bt_switch_audio_act_req_struct */
    SRV_UCM_BT_SET_VGS_ACT, /* srv_ucm_bt_vgs_req_struct */
    SRV_UCM_BT_BAT_REPORT_ACT, /* srv_ucm_bt_bat_report_act_req_struct */
    SRV_UCM_BT_ACT_OPCODE_TOTAL /* Total enum number */
}srv_ucm_bt_act_opcode_enum;

typedef enum
{
    SRV_UCM_BT_ACT_NOTIFY_START = 0, /* Action starts  */
    SRV_UCM_BT_ACT_NOTIFY_END, /* Action ends */
    SRV_UCM_BT_ACT_NOTIFY_TOTAL /* Total enum number */
}srv_ucm_bt_act_notify_enum;

/* Indication opcode enum */
typedef enum
{
    SRV_UCM_BT_INCOMING_CALL_IND = 0, /*  */
    SRV_UCM_BT_OUTGOING_CALL_IND = 1, /*  */
    SRV_UCM_BT_RING_IND = 2,
    SRV_UCM_BT_ALERT_IND = 3, /*  */
    SRV_UCM_BT_CONNECT_IND = 4, /*  */
    SRV_UCM_BT_REFRESH_IND = 5, /*  */
    SRV_UCM_BT_VGS_SYNC_IND = 7, /* srv_ucm_bt_vgs_ind_struct */
    SRV_UCM_BT_RESET_CALL_LIST_IND = 8, /*  srv_ucm_bt_cmd_error_ind_struct */
    SRV_UCM_BT_RELEASE_IND = 9, /* srv_ucm_bt_release_call_ind_struct */
    SRV_UCM_BT_HF_INIT_IND = 10,
    SRV_UCM_BT_HF_DEINIT_IND = 11,
    SRV_UCM_BT_CMD_FAIL_IND = 12, /* srv_ucm_bt_cmd_fail_ind_struct */
    SRV_UCM_BT_SYS_TIME_CHANGE_IND = 13,  /* srv_ucm_bt_sys_time_change_ind_struct */
    SRV_UCM_BT_BVRA_IND = 14, /* srv_ucm_bt_bvra_ind_struct */
    SRV_UCM_BT_CUST_AT_IND = 15, /* srv_ucm_bt_custom_at_ind_struct */
    SRV_UCM_BT_CONN_TYPE_IND = 16, /* srv_ucm_bt_link_ind_struct */
    SRV_UCM_BT_IND_OPCODE_TOTAL /* Total enum number */
}srv_ucm_bt_ind_opcode_enum;

/* UCM error cause enum */
typedef enum
{
    SRV_UCM_BT_RESULT_OK, /* OK */
    SRV_UCM_BT_RESULT_UNSPECIFIED_ERROR, /* Unspecified error */
    SRV_UCM_BT_RESULT_NOT_CONNECTED,
    SRV_UCM_BT_RESULT_UCM_BUSY,
    SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_DIAL,
    SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_SETUP,
    SRV_UCM_BT_RESULT_EMPTY_NUM,
    SRV_UCM_BT_RESULT_INVALID_NUM,
    SRV_UCM_BT_RESULT_INVALID_CALL_ID,
    SRV_UCM_BT_RESULT_NO_CALL_TO_ACCEPT,
    SRV_UCM_BT_RESULT_NO_CALL_TO_HOLD,
    SRV_UCM_BT_RESULT_NO_CALL_TO_RETRIEVE,
    SRV_UCM_BT_RESULT_NO_CALL_TO_SWAP,
    SRV_UCM_BT_RESULT_NO_CALL_TO_END,
    SRV_UCM_BT_RESULT_NO_DEV,
    SRV_UCM_BT_RESULT_DEVICE_EXIST,
    SRV_UCM_BT_RESULT_DEVICE_LIST_IS_FULL,
    SRV_UCM_BT_RESULT_SP_NO_RESPONSE,
    SRV_UCM_BT_RESULT_FEATURE_DONT_SUPPORT,
    SRV_UCM_BT_RESULT_END_OF_ENUM /* end of the enum */
} srv_ucm_bt_result_enum;

/* The bt notification callback mre engine */
typedef void (*srv_ucm_bt_mre_notify_cb)(U32 evt, void *para);
typedef srv_ucm_bt_mre_notify_cb srv_ucm_bt_notify_cb;

/* event structure for EVT_ID_SRV_UCM_BT_ACTION_NOTIFY */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_bt_act_opcode_enum act_op; /* Action op-code */
    srv_ucm_bt_act_notify_enum notify_type; /* Start or end */
    void *ptr; /* Data pointer */
} srv_ucm_bt_act_notify_evt_struct;

/* event structure for EVT_ID_SRV_UCM_BT_INDICATION */
typedef struct {
    /* DOM-NOT_FOR_SDK-BEGIN */
    MMI_EVT_PARAM_HEADER
    /* DOM-NOT_FOR_SDK-END */
    srv_ucm_bt_ind_opcode_enum ind_type; /* Indication type */
    void *ptr; /* Data pointer */
} srv_ucm_bt_ind_evt_struct;

/* Dial action struct */
typedef struct
{
    S32 srv_hd;
    U16 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
    U16 dis_name[SRV_UCM_BT_MAX_DIS_NAME_FROM_APP + 1]; /* name from app, ucs2 */
} srv_ucm_bt_atd_act_req_struct;

/* single call action struct */
typedef struct
{
    S32 srv_hd;
    U8 call_id; /* Call id */
} srv_ucm_bt_single_call_act_req_struct;

#ifdef __MMI_HF_BAT_SUPPORT__
typedef struct
{
    S32 srv_hd;
    U8  value;
    MMI_BOOL force;
}srv_ucm_bt_bat_report_act_req_struct;
#endif /* __MMI_HF_BAT_SUPPORT__ */

/* command action struct */
typedef struct
{
    S32 srv_hd;
} srv_ucm_bt_common_act_req_struct;


/* Accept call action struct */
typedef srv_ucm_bt_single_call_act_req_struct srv_ucm_bt_ata_act_req_struct;

/* hold/retrieve/swap call action struct */
typedef struct
{
    S32 act_hd;
    S32 hold_hd;
    U8 active_id;
    U8 hold_id;
} srv_ucm_bt_chld_act_req_struct;

/* end single*/
typedef srv_ucm_bt_single_call_act_req_struct srv_ucm_bt_end_single_act_req_struct;

/* end all connect  */
typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_end_all_act_req_struct;

/* switch audio req  */
typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_switch_audio_act_req_struct;

/* force refresh req  */
typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_force_refresh_act_req_struct;

#ifdef __BT_HF_BVRA_SUPPORT__
/* bvra req  */
typedef struct
{
    S32 srv_hd;
    MMI_BOOL enable;
}srv_ucm_bt_bvra_act_req_struct;
#endif /* __BT_HF_BVRA_SUPPORT__ */


/* dtmf */
typedef struct
{
    S32 srv_hd;
    U8 digit;
} srv_ucm_bt_dtmf_act_req_struct;

/* new/del device req */
typedef struct
{
    srv_bt_cm_bt_addr             dev_addr;
} srv_ucm_bt_dev_act_req_struct;

/* Action response struct */
typedef struct
{
    srv_ucm_bt_result_enum     result; /* Result */
    S32                        srv_hd;
    srv_ucm_bt_act_opcode_enum op_code;
} srv_ucm_bt_act_rsp_struct;

/* Outgoing call indication struct */
typedef struct
{
    U8 call_id;
    S32 srv_hd;
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    U16 dis_name[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
} srv_ucm_bt_outgoing_call_ind_struct;

/* incoming call indication struct */
typedef struct
{
    U8 call_id;
    S32 srv_hd;
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    U16 dis_name[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
} srv_ucm_bt_incoming_call_ind_struct;

/* ring ind struct */
typedef struct
{
    MMI_BOOL wait_tone;
    S32      srv_hd;
} srv_ucm_bt_ring_ind_struct;

/* call end indication struct*/
typedef struct
{
    U8 call_id;
    S32 srv_hd;
    MYTIME duration;
    srv_bt_cm_bt_addr dev_addr;
    U16 dis_name[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
} srv_ucm_bt_release_call_ind_struct;

/* speaker vol indication struct*/
typedef struct
{
    U8 gain;
    S32 srv_hd;
} srv_ucm_bt_vgs_ind_struct;

#ifdef __BT_HF_BVRA_SUPPORT__
typedef struct
{
    S32 srv_hd;
    MMI_BOOL enable;
} srv_ucm_bt_bvra_ind_struct;

typedef struct
{
    srv_bt_cm_bt_addr bt_addr;
    srv_ucm_bt_conn_type type;
} srv_ucm_bt_link_ind_struct;
#endif /* __BT_HF_BVRA_SUPPORT__ */


#ifdef __MMI_HF_BAT_SUPPORT__
typedef struct
{
    S32 srv_hd;
    U8  features;
} srv_ucm_bt_custom_at_ind_struct;
#endif /* __MMI_HF_BAT_SUPPORT__ */

/* refresh indication struct */
typedef struct
{
    U8 call_id;
    U8 call_idx;
    U8 dir;
    U8 mode;
    U8 multiParty;
    srv_ucm_bt_call_state_enum call_state; //to maintain the varios states of a call like Active, Hold, etc
    S32 srv_hd;
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ascii */
    U16 dis_name[SRV_UCM_BT_MAX_NUM_URI_LEN + 1]; /* Number, ucs2 */
    MYTIME start_time;//Maintain time duration of the active call
    srv_ucm_bt_act_opcode_enum proc_act;
    void* action_data;
}srv_ucm_bt_call_info_struct;

/* refresh indication struct */
typedef struct
{
    S32 srv_hd;
    srv_bt_cm_bt_addr dev_addr;
    U16 dev_name[SRV_BT_CM_BD_UCS2_NAME_LEN];
}srv_ucm_bt_dev_info_struct;

typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_refresh_call_ind_struct;

typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_reset_call_list_ind_struct;

typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_cmd_fail_ind_struct;

typedef srv_ucm_bt_common_act_req_struct srv_ucm_bt_sys_time_change_ind_struct;

typedef srv_ucm_bt_vgs_ind_struct srv_ucm_bt_vgs_req_struct;

typedef struct
{
    S32                   noti_hd;
    srv_ucm_bt_notify_cb  notifier;
    U32                   event_mask;
    void*                 user_data;
} srv_ucm_bt_notify_struct;

extern void srv_ucm_bt_init(void);
extern void srv_ucm_bt_deinit(void);
extern void srv_ucm_bt_act_request(srv_ucm_bt_act_opcode_enum act_op, void *act_data);
extern srv_ucm_bt_result_enum srv_ucm_bt_act_permit(srv_ucm_bt_act_opcode_enum act_op, void *ptr);
extern S32 srv_ucm_bt_query_call_count(srv_ucm_bt_call_state_enum call_state, S32* call_list);
extern S32 srv_ucm_bt_query_call_count_ext(S32 srv_hd, srv_ucm_bt_call_state_enum call_state, S32* index);
extern S32 srv_ucm_bt_query_group_count(srv_ucm_bt_call_state_enum call_state, S32* group_list);
extern S32 srv_ucm_bt_query_group_count_ext(S32 srv_hd, srv_ucm_bt_call_state_enum call_state, S32* index);
extern MMI_BOOL srv_ucm_bt_query_call_data(U32 call_id, srv_ucm_bt_call_info_struct* call_info);
extern S32 srv_ucm_bt_query_service_hd(srv_bt_cm_bt_addr* bt_addr);
extern MMI_BOOL srv_ucm_bt_query_connected_dev_info(S32 srv_hd, srv_ucm_bt_dev_info_struct* dev_info);
extern U32 srv_ucm_bt_query_connected_dev_count(S32* srv_hd_list);
extern MMI_BOOL srv_ucm_bt_is_any_call(void);
extern MMI_BOOL srv_ucm_bt_is_conference_call(U32* count, S32* srv_hd_list);
extern MMI_BOOL srv_ucm_bt_is_valid_service_hd(S32 srv_hd);
extern S32 srv_ucm_bt_register_notify_callback(srv_ucm_bt_notify_cb callback, U32 evt_mask, void* user_data);
extern S32 srv_ucm_bt_deregister_notify_callback(S32 noti_hd);
extern U8 srv_ucm_bt_proc_inject_string(U8 index, kal_uint8* string);
#endif /* SRV_UCM_BT_GPROT_H */
