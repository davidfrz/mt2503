#ifndef SRV_UCM_BT_PROT_H
#define SRV_UCM_BT_PROT_H

#include "MMI_features.h"

#ifdef __MMI_HF_SUPPORT__
#include "UcmBTSrvGprot.h"
#include "custom_mmi_default_value.h"
#include "BtcmSrvGprot.h"
#include "BTDialerSrvGprot.h"

#define SRV_UCM_BT_END_ALL_HANDLE_COUNT (2)
#define SRV_UCM_MAX_COMP_ACTION (2)
#define FG_SRV_UCM_BT_RING_NONE 0x00
#define FG_SRV_UCM_BT_RING_IND 0x01
#define FG_SRV_UCM_BT_RING_EVT_DONE 0x02
#define FG_SRV_UCM_BT_RING_NON_NONE 0xFF
#define SRV_UCM_BT_CONF_REF_TIME (3000)

typedef enum
{
    SRV_BT_DIALER_STATE_SETUP,
    SRV_BT_DIALER_STATE_CALL,
    SRV_BT_DIALER_STATE_HOLD,
}srv_bt_dialer_call_state_ind_enum;

typedef enum
{
    SRV_UCM_BT_ACTION_NONE,
    SRV_UCM_BT_ACTION_ADD_MO,
    SRV_UCM_BT_ACTION_ADD_MT,
    SRV_UCM_BT_ACTION_DELETE,
    SRV_UCM_BT_ACTION_UPDATE
}srv_ucm_bt_action_enum;

typedef enum
{
    SRV_UCM_BT_CALL_BY_CALL_ID,
    SRV_UCM_BT_CALL_BY_STATE,
    SRV_UCM_BT_CALL_INFO_END
} srv_ucm_bt_call_info_op_enum;

typedef enum
{
    SRV_UCM_BT_DEV_BY_ADDR,
    SRV_UCM_BT_DEV_BY_SRV_HD,
    SRV_UCM_BT_DEV_INFO_END
} srv_ucm_bt_dev_info_op_enum;


typedef struct
{
    srv_bt_dialer_call_setup_ind_enum setup;
    srv_bt_dialer_call_ind_enum call;
    srv_bt_dialer_AtHeldInd_enum held;
}srv_ucm_bt_ciev_ind_struct;

typedef struct
{
    U8 call_idx;
    srv_ucm_bt_call_state_enum call_state;
    U8 num_uri[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];
    U8 dir;
    U8 mode;
    U8 multiParty;
}srv_ucm_bt_call_list_struct;

typedef struct
{
    S32 srv_hd;
    S32 call_count; // call count of a device
    S32 call_temp_count;
    srv_ucm_bt_action_enum sync_result;
    srv_ucm_bt_act_opcode_enum pending_action;
    U8 ring_enable;
    U8 dev_ref;
    U8 custom_features; // only useful for IOS.
    U8 cur_level; // only use for IOS.
    MMI_BOOL alloced;
    MMI_BOOL conn_cnf;
    srv_bt_cm_bt_addr dev_addr;
    srv_ucm_bt_ciev_ind_struct ciev_ind;
    srv_ucm_bt_release_call_ind_struct call_end;
    U16 dev_name[SRV_BT_CM_BD_UCS2_NAME_LEN];
    U8* mo_num_from_app;
    U16* mo_name_from_app;
    srv_ucm_bt_call_info_struct call_info[SRV_UCM_BT_MAX_CALL];
    srv_ucm_bt_call_list_struct call_temp_list[SRV_UCM_BT_MAX_CALL];
}srv_ucm_bt_call_dev_info_struct;

typedef struct
{
    S32 srv_hd;
    srv_ucm_bt_act_opcode_enum action;
}srv_ucm_bt_comp_act_struct;

typedef struct
{
    MMI_BOOL comp_action;
    U16 dev_call_id;
    U16 dev_count;
    U16 left_act;
    S32 sco_used;
    srv_ucm_bt_notify_struct noti_inst[SRV_UCM_BT_MAX_INSTANCE_NUM];
    srv_ucm_bt_call_dev_info_struct dev_info[SRV_UCM_BT_MAX_DEV];
} srv_ucm_bt_cntx_struct;

extern srv_ucm_bt_cntx_struct *g_ucm_bt_srv_p;

void srv_ucm_bt_send_act_notify(srv_ucm_bt_act_opcode_enum act_op, srv_ucm_bt_act_notify_enum notify_type , void *ptr);
void srv_ucm_bt_send_indication(srv_ucm_bt_ind_opcode_enum ind_op, void *ptr);
void srv_ucm_bt_event_notify(U32 event, void* para);
mmi_ret srv_ucm_bt_post_event_callback(mmi_post_result_event_struct *result_evt);
void srv_ucm_bt_register_hf_event(S32 srv_hd, srv_bt_dialer_notify_event_struct* notify);

MMI_BOOL srv_ucm_bt_set_pending_action(S32 srv_hd, srv_ucm_bt_act_opcode_enum op);
void srv_ucm_bt_reset_pending_action(S32 srv_hd);
MMI_BOOL srv_ucm_bt_is_pending_action(S32 srv_hd);
srv_ucm_bt_act_opcode_enum srv_ucm_bt_get_pending_action(S32 srv_hd);
void srv_ucm_bt_sco_state_sync_hdlr(S32 srv_hd, MMI_BOOL open);
#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__)
MMI_BOOL srv_ucm_bt_get_remote_name(srv_ucm_bt_call_info_struct* call_info);
#endif
void srv_ucm_bt_conf_refresh_handler(void* arg);

srv_ucm_bt_call_dev_info_struct* srv_ucm_bt_get_dev_info(srv_ucm_bt_dev_info_op_enum op, void* para);
srv_ucm_bt_call_info_struct* srv_ucm_bt_get_call_info(S32 srv_hd, srv_ucm_bt_call_info_op_enum op, U8 info);
void srv_ucm_bt_call_scenario_control(void);
void srv_ucm_bt_get_connected_dev_name(srv_bt_cm_bt_addr* dev_addr, WCHAR* name_p);
void srv_ucm_bt_register_hf_connection_event(srv_bt_dialer_notify_event_struct* notify);

void srv_ucm_bt_del_device(srv_bt_cm_bt_addr* dev_addr);
srv_ucm_bt_call_dev_info_struct* srv_ucm_bt_new_device(srv_bt_cm_bt_addr *dev_addr, srv_bt_dialer_notify_hf_event cb_ptr);

void srv_ucm_bt_outgoing_call_ind(S32 srv_hd);
void srv_ucm_bt_incoming_call_ind(S32 srv_hd);
void srv_ucm_bt_release_ind(S32 srv_hd);
void srv_ucm_bt_refresh_ind(S32 srv_hd);
void srv_ucm_bt_ring_ind(S32 srv_hd, MMI_BOOL wait);
void srv_ucm_bt_vgs_sync_ind(S32 srv_hd, U8 gain);
#ifdef __BT_HF_BVRA_SUPPORT__
void srv_ucm_bt_bvra_ind(S32 srv_hd, MMI_BOOL enable);
#endif /* __BT_HF_BVRA_SUPPORT__ */
#ifdef __MMI_HF_BAT_SUPPORT__
void srv_ucm_bt_custom_at_support_ind(S32 srv_hd, MMI_BOOL valid, U8 features);
#endif /* __MMI_HF_BAT_SUPPORT__ */


void srv_ucm_bt_dial_action(void* act_data);
void srv_ucm_bt_accept_action(void* act_data);
void srv_ucm_bt_hold_action(void* act_data);
void srv_ucm_bt_retrieve_action (void* act_data);
void srv_ucm_bt_swap_action (void* act_data);
void srv_ucm_bt_end_single_action (void* act_data);
void srv_ucm_bt_end_all_action(void* act_data);
void srv_ucm_bt_send_dtmf_action(void* act_data);
void srv_ucm_bt_force_refresh_action(void* act_data);
void srv_ucm_bt_switch_audio_path_action(void* act_data);
#ifdef __BT_HF_BVRA_SUPPORT__
void srv_ucm_bt_bvra_action(void* act_data);
#endif /* __BT_HF_BVRA_SUPPORT__ */
#ifdef __BT_SPK_VOL_CONTROL__
void srv_ucm_bt_set_vgs_action(void* ptr);
#endif /* __BT_SPK_VOL_CONTROL__ */
#ifdef __MMI_HF_BAT_SUPPORT__
void srv_ucm_bt_bat_report_action(void* ptr);
#endif /* __MMI_HF_BAT_SUPPORT__ */

void srv_ucm_bt_check_compound_action(S32 srv_hd, srv_ucm_bt_act_opcode_enum opcode);
void srv_ucm_bt_next_comp_action(void);
void srv_ucm_bt_abort_compound_action(S32 srv_hd);

srv_ucm_bt_result_enum srv_ucm_bt_dial_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_accept_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_hold_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_retrieve_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_swap_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_new_dev_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_delete_dev_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_force_refresh_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_end_single_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_end_all_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_send_dtmf_prmt(void* ptr);
srv_ucm_bt_result_enum srv_ucm_bt_setup_new_call_prmt(srv_ucm_bt_call_dev_info_struct* cur_dev);
#ifdef __MMI_HF_BAT_SUPPORT__
srv_ucm_bt_result_enum srv_ucm_bt_bat_report_prmt(void* ptr);
#endif /* __MMI_HF_BAT_SUPPORT__ */
#ifdef __BT_HF_BVRA_SUPPORT__
srv_ucm_bt_result_enum srv_ucm_bt_bvra_prmt(void* ptr);
#endif /* __BT_HF_BVRA_SUPPORT__ */
#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
extern void srv_ucm_bt_redial_action(void* act_data);
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */
#endif /* __MMI_HF_SUPPORT__ */
#endif /* SRV_UCM_BT_PROT_H */
