
#include "UcmBTSrvGprot.h"
#include "UcmSrvGprot.h"
#include "UcmBTSrv.h"

#include "mmi_frm_events_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "mmi_rp_srv_ucm_def.h"
#include "DateTimeType.h" // DTGetRTCTime
#include "DateTimeGprot.h" // for srv_ucm_bt_on_time_change_event
#include "App_datetime.h"
#include "mmi_cb_mgr_gprot.h" // MMI_FRM_CB_EMIT_POST_EVENT_EX
#include "mmi_frm_scenario_gprot.h" //mmi_frm_is_scenario_started
#include "Unicodexdcl.h"                /* mmi_asc_to_ucs2 */
#include "MMI_common_app_trc.h"
#include "mdi_audio.h" // mdi_audio_resume_background_play_by_app

#include "DebugInitDef_Int.h"
#include "conversions.h"    // for mmi_chset_utf8_to_ucs2_string();
#ifdef __BT_PBAP_CLIENT__
#include "PbapSrvGprot.h" // for SRV_PBAPC_FLAG_CONNECTED
#include "PhbpbapSrvGprot.h" // for srv_phb_pbapc_get_name_by_number
#endif /* __BT_PBAP_CLIENT__ */
#ifdef __MMI_HF_BAT_SUPPORT__
#include "CharBatSrvGprot.h" // srv_charbat_battery_level_enum
#endif /* __MMI_HF_BAT_SUPPORT__ */

#ifdef __MMI_HF_SUPPORT__ 
srv_ucm_bt_cntx_struct g_ucm_bt_srv_cntx;
srv_ucm_bt_cntx_struct *g_ucm_bt_srv_p = &g_ucm_bt_srv_cntx;

//#define __UCM_BT_UT_TEST__

#ifdef __UCM_BT_UT_TEST__
S32 srv_ucm_ut_handler;
S32 srv_ucm_ut_noti_hd;
#endif

void srv_ucm_bt_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(g_ucm_bt_srv_p, 0, sizeof(srv_ucm_bt_cntx_struct));
    srv_bt_dialer_register_hf_connection_notifier(srv_ucm_bt_register_hf_connection_event);
    srv_ucm_bt_send_indication(SRV_UCM_BT_HF_INIT_IND, NULL);
}

void srv_ucm_bt_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dev_info = &g_ucm_bt_srv_p->dev_info[0]; dev_info < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_info++)
    {
        if (dev_info->alloced)
        {
            srv_ucm_bt_del_device(&dev_info->dev_addr);
        }
    }

    memset(g_ucm_bt_srv_p, 0, sizeof(srv_ucm_bt_cntx_struct));

    srv_ucm_bt_send_indication(SRV_UCM_BT_HF_DEINIT_IND, NULL);
}

void srv_ucm_bt_act_request(srv_ucm_bt_act_opcode_enum act_op, void *act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_UCM_BT_RESULT_OK != srv_ucm_bt_act_permit(act_op, act_data) && !g_ucm_bt_srv_p->comp_action)
    {
        return;
    }

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_ACT_REQ, act_op);

    switch (act_op)
    {
        case SRV_UCM_BT_DIAL_ACT:
            srv_ucm_bt_dial_action(act_data);
            break;
    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_UCM_BT_BVRA_ACT:
            srv_ucm_bt_bvra_action(act_data);
            break;
    #endif /* __BT_HF_BVRA_SUPPORT__ */

    #ifdef __MMI_UCM_BT_BTBOX_NOLCD__
        case SRV_UCM_BT_REDIAL_ACT:
            srv_ucm_bt_redial_action(act_data);
            break;
    #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

        case SRV_UCM_BT_ACCEPT_ACT:
            srv_ucm_bt_accept_action(act_data);
            break;

        case SRV_UCM_BT_HOLD_ACT:
            srv_ucm_bt_hold_action(act_data);
            break;

        case SRV_UCM_BT_RETRIEVE_ACT:
            srv_ucm_bt_retrieve_action(act_data);
            break;

        case SRV_UCM_BT_SWAP_ACT:
            srv_ucm_bt_swap_action(act_data);
            break;

        case SRV_UCM_BT_END_SINGLE_ACT:
            srv_ucm_bt_end_single_action(act_data);
            break;

        case SRV_UCM_BT_END_ALL_ACT:
            srv_ucm_bt_end_all_action(act_data);
            break;

        case SRV_UCM_BT_SEND_DTMF_ACT:
            srv_ucm_bt_send_dtmf_action(act_data);
            break;

        case SRV_UCM_BT_FORCE_REFRESH_ACT:
            srv_ucm_bt_force_refresh_action(act_data);
            break;

        case SRV_UCM_BT_SWITCH_AUDIO_PATH:
            srv_ucm_bt_switch_audio_path_action(act_data);
            break;

    #ifdef __BT_SPK_VOL_CONTROL__
        case SRV_UCM_BT_SET_VGS_ACT:
            srv_ucm_bt_set_vgs_action(act_data);
            break;
    #endif /* __BT_SPK_VOL_CONTROL__ */

    #ifdef __MMI_HF_BAT_SUPPORT__
        case SRV_UCM_BT_BAT_REPORT_ACT:
            srv_ucm_bt_bat_report_action(act_data);
            break;
    #endif /* __MMI_HF_BAT_SUPPORT__ */

        default:
            // undefined action
            break;
    }
    if (act_op > SRV_UCM_BT_NO_ACT && act_op < SRV_UCM_BT_SEND_DTMF_ACT && !g_ucm_bt_srv_p->comp_action)
    {
        srv_ucm_bt_send_act_notify(act_op, SRV_UCM_BT_ACT_NOTIFY_START, act_data);
    }
}

srv_ucm_bt_result_enum srv_ucm_bt_act_permit(srv_ucm_bt_act_opcode_enum act_op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_PRMT_REQ, act_op);

    switch (act_op)
    {
        case SRV_UCM_BT_DIAL_ACT:
            result = srv_ucm_bt_dial_prmt(ptr);
            break;

    #ifdef __MMI_UCM_BT_BTBOX_NOLCD__
        case SRV_UCM_BT_REDIAL_ACT:
            result = srv_ucm_bt_dial_prmt(ptr);
            break;
    #endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */

        case SRV_UCM_BT_ACCEPT_ACT:
            result = srv_ucm_bt_accept_prmt(ptr);
            break;

        case SRV_UCM_BT_HOLD_ACT:
            result = srv_ucm_bt_hold_prmt(ptr);
            break;

        case SRV_UCM_BT_RETRIEVE_ACT:
            result = srv_ucm_bt_retrieve_prmt(ptr);
            break;

        case SRV_UCM_BT_SWAP_ACT:
            result = srv_ucm_bt_swap_prmt(ptr);
            break;

        case SRV_UCM_BT_END_SINGLE_ACT:
            result = srv_ucm_bt_end_single_prmt(ptr);
            break;

        case SRV_UCM_BT_END_ALL_ACT:
            result = srv_ucm_bt_end_all_prmt(ptr);
            break;

        case SRV_UCM_BT_FORCE_REFRESH_ACT:
            result = srv_ucm_bt_force_refresh_prmt(ptr);
            break;

        case SRV_UCM_BT_SEND_DTMF_ACT:
            result = srv_ucm_bt_send_dtmf_prmt(ptr);
            break;

    #ifdef __MMI_HF_BAT_SUPPORT__
        case SRV_UCM_BT_BAT_REPORT_ACT:
            result = srv_ucm_bt_bat_report_prmt(ptr);
            break;
    #endif /* __MMI_HF_BAT_SUPPORT__ */

    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_UCM_BT_BVRA_ACT:
            result = srv_ucm_bt_bvra_prmt(ptr);
            break;
    #endif /* __BT_HF_BVRA_SUPPORT__ */

        default:
            break;
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL,TRC_SRV_UCM_BT_PRMT_RET, result);
    return result;
}

void srv_ucm_bt_send_act_notify(srv_ucm_bt_act_opcode_enum act_op, srv_ucm_bt_act_notify_enum notify_type ,void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_act_notify_evt_struct evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_BT_ACTION_NOTIFY);
    evt.act_op = act_op;
    evt.notify_type = notify_type;

    if (notify_type == SRV_UCM_BT_ACT_NOTIFY_START)
    {
        switch (act_op)
        {
            case SRV_UCM_BT_DIAL_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_bt_atd_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_atd_act_req_struct));
                break;
            case SRV_UCM_BT_ACCEPT_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_bt_ata_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_ata_act_req_struct));
                break;
            case SRV_UCM_BT_HOLD_ACT:
            case SRV_UCM_BT_RETRIEVE_ACT:
            case SRV_UCM_BT_SWAP_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_bt_chld_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_chld_act_req_struct));
                break;
        #ifdef __BT_HF_BVRA_SUPPORT__
            case SRV_UCM_BT_BVRA_ACT:
                evt.ptr = OslMalloc(sizeof(srv_ucm_bt_bvra_act_req_struct));
                memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_bvra_act_req_struct));
                break;
        #endif /* __BT_HF_BVRA_SUPPORT__ */
            case SRV_UCM_BT_END_SINGLE_ACT:
            case SRV_UCM_BT_END_ALL_ACT:
            case SRV_UCM_BT_END_ALL_PROCESSING_ACT:
            case SRV_UCM_BT_SEND_DTMF_ACT:
                evt.ptr = NULL;
                break;
            default:
                MMI_ASSERT(0); /* not valid op_code */
                break;
        }
    }
    else if (notify_type == SRV_UCM_BT_ACT_NOTIFY_END)
    {
        evt.ptr = OslMalloc(sizeof(srv_ucm_bt_act_rsp_struct));
        memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_act_rsp_struct));
    }
    else
    {
        MMI_ASSERT(0);
    }

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ucm_bt_post_event_callback, (void *)evt.ptr);

}


void srv_ucm_bt_send_indication(srv_ucm_bt_ind_opcode_enum ind_op, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_ind_evt_struct evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_UCM_BT_INDICATION);
    evt.ind_type = ind_op;

    switch (ind_op)
    {
        case SRV_UCM_BT_INCOMING_CALL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_incoming_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_incoming_call_ind_struct));
            break;

        case SRV_UCM_BT_OUTGOING_CALL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_outgoing_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_outgoing_call_ind_struct));
            break;

        case SRV_UCM_BT_RELEASE_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_release_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_release_call_ind_struct));
            break;

        case SRV_UCM_BT_RING_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_ring_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_ring_ind_struct));
            break;

        case SRV_UCM_BT_REFRESH_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_refresh_call_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_refresh_call_ind_struct));
            break;

        case SRV_UCM_BT_HF_INIT_IND:
        case SRV_UCM_BT_HF_DEINIT_IND:

            evt.ptr = NULL;
            break;

        case SRV_UCM_BT_VGS_SYNC_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_vgs_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_vgs_ind_struct));
            break;

        case SRV_UCM_BT_RESET_CALL_LIST_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_reset_call_list_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_reset_call_list_ind_struct));
            break;

        case SRV_UCM_BT_CMD_FAIL_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_cmd_fail_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_cmd_fail_ind_struct));
            break;

        case SRV_UCM_BT_SYS_TIME_CHANGE_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_sys_time_change_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_sys_time_change_ind_struct));
            break;
    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_UCM_BT_BVRA_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_bvra_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_bvra_ind_struct));
            break;

        case SRV_UCM_BT_CONN_TYPE_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_link_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_link_ind_struct));
            break;

    #endif /* __BT_HF_BVRA_SUPPORT__ */

    #ifdef __MMI_HF_BAT_SUPPORT__
        case SRV_UCM_BT_CUST_AT_IND:
            evt.ptr = OslMalloc(sizeof(srv_ucm_bt_custom_at_ind_struct));
            memcpy(evt.ptr, ptr, sizeof(srv_ucm_bt_custom_at_ind_struct));
            break;
    #endif /* __MMI_HF_BAT_SUPPORT__ */

        default:
            evt.ptr = NULL;
            break;
    }

    MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ucm_bt_post_event_callback, (void *)evt.ptr);
}


void srv_ucm_bt_event_notify(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_UCM_BT_MAX_INSTANCE_NUM; ++i)
    {
        if ((g_ucm_bt_srv_p->noti_inst[i].noti_hd > 0) &&
            (g_ucm_bt_srv_p->noti_inst[i].noti_hd <= SRV_UCM_BT_MAX_INSTANCE_NUM))
        {
            if (event & g_ucm_bt_srv_p->noti_inst[i].event_mask)
            {
                if (g_ucm_bt_srv_p->noti_inst[i].notifier)
                {
                    g_ucm_bt_srv_p->noti_inst[i].notifier(event, para);
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NOTI_CB, event, g_ucm_bt_srv_p->noti_inst[i].noti_hd);
                }
            }
        }
    }
}

mmi_ret srv_ucm_bt_post_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result_evt != NULL && result_evt->evt_p != NULL)
    {
        switch (result_evt->evt_p->evt_id)
        {
            case EVT_ID_SRV_UCM_BT_INDICATION:
                srv_ucm_bt_event_notify(SRV_UCM_BT_NOTI_EVT_IND, result_evt->evt_p);
                break;

            case EVT_ID_SRV_UCM_BT_ACTION_NOTIFY:
                srv_ucm_bt_event_notify(SRV_UCM_BT_NOTI_EVT_ACT, result_evt->evt_p);
                break;

            default:
                break;
        }
    }

    if (result_evt->user_data != NULL)
    {
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }
    return MMI_RET_OK;
}

#define srv_ucm_bt_reset_ring_flag(_value) (_value &= FG_SRV_UCM_BT_RING_NONE)
#define srv_ucm_bt_set_ring_flag(_value, _flag) ((_value) |= (_flag))
#define srv_ucm_bt_check_ring_flag(_value, _flag) ((_value) & (_flag))

static void srv_ucm_bt_dump_cur_dev_info(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (dev_p = &g_ucm_bt_srv_p->dev_info[0]; dev_p < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_p++)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_DUMP_CUR_DEV_INFO,
                 dev_p->dev_addr.lap,
                 dev_p->dev_addr.uap,
                 dev_p->dev_addr.nap,
                 dev_p->srv_hd,
                 dev_p->alloced);
    }
}

static void srv_ucm_bt_free_mo_info_from_app(srv_ucm_bt_call_dev_info_struct* dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_info);

    if (dev_info->mo_name_from_app)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NAME_FROM_APP, 901, dev_info->mo_name_from_app);
        OslMfree(dev_info->mo_name_from_app);
        dev_info->mo_name_from_app = NULL;
    }
    if (dev_info->mo_num_from_app)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NAME_FROM_APP, 902, dev_info->mo_num_from_app);
        OslMfree(dev_info->mo_num_from_app);
        dev_info->mo_num_from_app = NULL;
    }
}

static srv_ucm_bt_call_dev_info_struct* srv_ucm_bt_get_free_device(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 index;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < SRV_UCM_BT_MAX_DEV; index++)
    {
        if (g_ucm_bt_srv_p->dev_info[index].alloced == MMI_FALSE)
        {
            return &g_ucm_bt_srv_p->dev_info[index];
        }
    }
    return NULL;
}

static U8 srv_ucm_bt_get_free_call_id(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_ALLOC_ID, g_ucm_bt_srv_p->dev_call_id);

    for (index = 0; index < (SRV_UCM_BT_MAX_DEV*SRV_UCM_BT_MAX_CALL); index++)
    {
        if (!(g_ucm_bt_srv_p->dev_call_id & (1 << index)))
        {
            g_ucm_bt_srv_p->dev_call_id |= (1 << index);
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_ALLOC_ID, g_ucm_bt_srv_p->dev_call_id);
            return (index+1);
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_ALLOC_ID, g_ucm_bt_srv_p->dev_call_id);
    return 0;
}

static S32 srv_ucm_bt_get_free_call_index(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 idx;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);

    MMI_ASSERT(dev_info);

    for (idx = 0; idx < SRV_UCM_BT_MAX_CALL; idx++)
    {
        if (dev_info->call_info[idx].call_idx == 0)
        {
            return idx;
        }
    }
    return (-1);
}

static srv_ucm_bt_call_dev_info_struct* srv_ucm_bt_get_dev_info(srv_ucm_bt_dev_info_op_enum op, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(para);

    for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        if (SRV_UCM_BT_DEV_BY_SRV_HD == op)
        {
            if (g_ucm_bt_srv_p->dev_info[i].srv_hd == (*((S32*)para)))
            {
                return &g_ucm_bt_srv_p->dev_info[i];
            }
        }
        else if (SRV_UCM_BT_DEV_BY_ADDR == op)
        {
            if (((srv_bt_cm_bt_addr*)para)->lap == 0
              && ((srv_bt_cm_bt_addr*)para)->uap == 0
              && ((srv_bt_cm_bt_addr*)para)->nap == 0)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_GET_DEV_INFO_P1, 0xFF);
                return NULL;
            }
            else if (g_ucm_bt_srv_p->dev_info[i].dev_addr.lap == ((srv_bt_cm_bt_addr*)para)->lap
                  && g_ucm_bt_srv_p->dev_info[i].dev_addr.uap == ((srv_bt_cm_bt_addr*)para)->uap
                  && g_ucm_bt_srv_p->dev_info[i].dev_addr.nap == ((srv_bt_cm_bt_addr*)para)->nap)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL,TRC_SRV_UCM_BT_GET_DEV_INFO_P2,
                    ((g_ucm_bt_srv_p->dev_info[i].dev_addr.nap & 0xff00) >> 8),
                    (g_ucm_bt_srv_p->dev_info[i].dev_addr.nap & 0x00ff),
                    (g_ucm_bt_srv_p->dev_info[i].dev_addr.uap),
                    ((g_ucm_bt_srv_p->dev_info[i].dev_addr.lap & 0xff0000) >> 16),
                    ((g_ucm_bt_srv_p->dev_info[i].dev_addr.lap & 0x00ff00) >> 8),
                    (g_ucm_bt_srv_p->dev_info[i].dev_addr.lap & 0x0000ff));

                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_GET_DEV_INFO_P3, i);
                return &g_ucm_bt_srv_p->dev_info[i];
            }
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    return NULL;
}

static srv_ucm_bt_call_info_struct* srv_ucm_bt_get_call_info(S32 srv_hd, srv_ucm_bt_call_info_op_enum op, U8 info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
    {
        if (SRV_UCM_BT_CALL_BY_CALL_ID == op && info != 0)
        {
            if (dev_info->call_info[i].call_id == info)
            {
                return &dev_info->call_info[i];
            }
        }
        else if (SRV_UCM_BT_CALL_BY_STATE == op)
        {
            if (dev_info->call_info[i].call_state & (srv_ucm_bt_call_state_enum)info)
            {
                return &dev_info->call_info[i];
            }
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

void srv_ucm_bt_get_connected_dev_name(srv_bt_cm_bt_addr* dev_addr, WCHAR* name_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 name[SRV_BT_CM_BD_FNAME_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(name_p);

    srv_bt_cm_get_dev_name(
        dev_addr,
        (U8) SRV_BT_CM_BD_FNAME_LEN,
        name);

    mmi_chset_utf8_to_ucs2_string(
        (kal_uint8*) (name_p),
        SRV_BT_CM_BD_NAME_UCS2_LEN,
        (kal_uint8*) name);

}


static void srv_ucm_bt_free_call_id(U8 call_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(call_id <= SRV_UCM_BT_MAX_DEV*SRV_UCM_BT_MAX_CALL+1);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_FREE_ID, g_ucm_bt_srv_p->dev_call_id);

    g_ucm_bt_srv_p->dev_call_id &= (~(1 << (call_id-1)));

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_FREE_ID, g_ucm_bt_srv_p->dev_call_id);
}

void srv_ucm_bt_del_device(srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    S32 call_list[SRV_UCM_BT_MAX_CALL];
    S32 call_count;
    S32 idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_addr);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_ADDR, dev_addr);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_DEL_DEV, dev_info);

    MMI_ASSERT(dev_info);

    if (dev_info == NULL)
    {
        srv_ucm_bt_dump_cur_dev_info();
        return;
    }

    if (dev_info->dev_ref > 0)
    {
        dev_info->dev_ref--;
        return;
    }

    call_count = srv_ucm_bt_query_call_count_ext(dev_info->srv_hd , SRV_UCM_BT_CALL_STATE_ALL, call_list);

    srv_ucm_bt_abort_compound_action(dev_info->srv_hd);

    srv_ucm_bt_reset_pending_action(dev_info->srv_hd);

    if (call_count > 0)
    {
        for (idx = 0; idx < call_count; idx++)
        {
            srv_ucm_bt_free_call_id(call_list[idx]);
        }
    }

    srv_bt_dialer_close(dev_info->srv_hd);

    srv_ucm_bt_free_mo_info_from_app(dev_info);

    memset(dev_info, 0, sizeof(srv_ucm_bt_call_dev_info_struct));
    g_ucm_bt_srv_p->dev_count--;

#ifdef __UCM_BT_UT_TEST__
    srv_ucm_ut_handler = 0;
#endif

}

srv_ucm_bt_call_dev_info_struct* srv_ucm_bt_new_device(srv_bt_cm_bt_addr *dev_addr, srv_bt_dialer_notify_hf_event cb_ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    const srv_bt_cm_dev_struct* cm_dev_info;
    U8 name[SRV_BT_CM_BD_UCS2_NAME_LEN];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_addr);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_ADDR, dev_addr);

    if (dev_info)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_DEV_EXISTED, dev_info);
        dev_info->dev_ref++;
        return dev_info;
    }

    dev_info = srv_ucm_bt_get_free_device();

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NEW_DEV, dev_info);

    if (dev_info == NULL)
    {
        return NULL;
    }

    dev_info->alloced = MMI_TRUE;

    memcpy(&dev_info->dev_addr, dev_addr, sizeof(srv_bt_cm_bt_addr));

    dev_info->srv_hd = srv_bt_dialer_open(dev_addr);
    srv_bt_dialer_register_hf_notifier(dev_info->srv_hd, cb_ptr);

    cm_dev_info = srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_ALL_DEV);

    if (cm_dev_info)
    {
        srv_ucm_bt_get_connected_dev_name(dev_addr, (WCHAR*)dev_info->dev_name);
        mmi_ucs2_to_asc((CHAR*)name, (CHAR*)dev_info->dev_name);
        kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_5,"[UcmBTSrv] dev name:%s", name); 
    }

    g_ucm_bt_srv_p->dev_count++;

#ifdef __UCM_BT_UT_TEST__
    srv_ucm_ut_handler = dev_info->srv_hd;
#endif

    return dev_info;
}

MMI_BOOL srv_ucm_bt_device_is_any_call(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    if (dev_info->ciev_ind.setup == SRV_BT_DIALER_CALL_SETUP_COMPLETE
        && dev_info->ciev_ind.call == SRV_BT_DIALER_CALL_NOT_ACTIVE
        && dev_info->ciev_ind.held == SRV_BT_DIALER_NO_CALL_HELD)
    {
        return MMI_FALSE;
    }
    else
    {
        return MMI_TRUE;
    }
}

static srv_ucm_bt_call_state_enum srv_ucm_bt_tranfer_call_state(srv_bt_dialer_AtCallState_enum btsrv_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(btsrv_type)
    {
        case SRV_BT_DIALER_ATCS_ACTIVE:
            return SRV_UCM_BT_ACTIVE_STATE;
        case SRV_BT_DIALER_ATCS_HELD:
            return SRV_UCM_BT_HOLD_STATE;
        case SRV_BT_DIALER_ATCS_DIALING:
        case SRV_BT_DIALER_ATCS_ALERTING:
            return SRV_UCM_BT_OUTGOING_STATE;
        case SRV_BT_DIALER_ATCS_INCOMING:
        case SRV_BT_DIALER_ATCS_WAITING:
            return SRV_UCM_BT_INCOMING_STATE;
        default:
            return SRV_UCM_BT_BT_IDLE_STATE;
    }
}

static srv_ucm_bt_result_enum srv_ucm_bt_tranfer_error_code(U16 error)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_result_enum err_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(error)
    {
        case SRV_BT_DIALER_ATCME_SUCCESS:
            err_code = SRV_UCM_BT_RESULT_OK;
            break;

        case SRV_BT_DIALER_INTERNAL_ERROR:
            err_code = SRV_UCM_BT_RESULT_UNSPECIFIED_ERROR;
            break;

        case SRV_BT_DIALER_CMD_TIME_OUT:
            err_code = SRV_UCM_BT_RESULT_SP_NO_RESPONSE;
            break;

        default:
            err_code = SRV_UCM_BT_RESULT_UNSPECIFIED_ERROR;
            break;
    }
    return err_code;
}
static void srv_ucm_bt_add_to_temp_list(S32 srv_hd, srv_bt_dialer_AtHfResult_struct* result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info ;
    S32 count;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info && result);

    if (dev_info->call_temp_count >= SRV_UCM_BT_MAX_CALL)
    {
        return;
    }

    count = dev_info->call_temp_count;

    dev_info->call_temp_list[count].call_idx = result->currentCalls.index;
    dev_info->call_temp_list[count].call_state = srv_ucm_bt_tranfer_call_state(result->currentCalls.state);
    dev_info->call_temp_list[count].dir = result->currentCalls.dir;
    dev_info->call_temp_list[count].mode = result->currentCalls.mode;
    dev_info->call_temp_list[count].multiParty = result->currentCalls.multiParty;
    dev_info->call_temp_count++;
    memcpy(dev_info->call_temp_list[count].num_uri, result->currentCalls.number, SRV_UCM_BT_MAX_NUM_URI_LEN);
}

static void srv_ucm_bt_ciev_ind_hdlr(S32 srv_hd, srv_bt_dialer_call_state_ind_enum call_state, S32 value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    if (SRV_BT_DIALER_STATE_SETUP == call_state)
    {
         dev_info->ciev_ind.setup = (srv_bt_dialer_call_setup_ind_enum)value;
    }
    else if (SRV_BT_DIALER_STATE_CALL == call_state)
    {
         dev_info->ciev_ind.call = (srv_bt_dialer_call_ind_enum)value;
    }
    else if (SRV_BT_DIALER_STATE_HOLD == call_state)
    {
         dev_info->ciev_ind.held = (srv_bt_dialer_AtHeldInd_enum)value;
    }
    else
    {
        MMI_ASSERT(0);
    }

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    // srv_ucm_bt_abort_compound_action(srv_hd);
    if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, &dev_info->dev_addr)
        && dev_info->conn_cnf)
    {
        if (srv_bt_dialer_list_current_calls(srv_hd))
        {
            memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));
        }
    }
}

static void srv_ucm_bt_auto_sco_update(S32 srv_hd, srv_bt_dialer_event_enum cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 conn_id = srv_bt_dialer_get_connection_id(srv_hd);
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cmd == SRV_BT_DIALER_EVT_ID_ATA_CMD_RSP)
    {
        if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL) == 1
         && srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_INCOMING_STATE, NULL) == 1)
        {
            srv_bt_dialer_set_incoming_call_ans_status(conn_id, MMI_TRUE);
        }
    }
    else if (cmd == SRV_BT_DIALER_EVT_ID_AT_DIAL_CMD_RSP)
    {
        if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
        {
            srv_bt_dialer_set_incoming_call_ans_status(conn_id, MMI_TRUE);
        }
    }
}

void srv_ucm_bt_call_scenario_control(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SNRIO_CTRL);

    /* Incoming call scenario */
    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_INCOMING_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_UCM_INCOMING_CALL);
        }
    }
    else
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if (!srv_ucm_is_incoming_call()) // MAUI_03435769
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        {
            mmi_frm_end_scenario(MMI_SCENARIO_ID_UCM_INCOMING_CALL);
        }
    }

    /* Outgoing call scenario */
    if (srv_ucm_bt_query_group_count(SRV_UCM_BT_OUTGOING_STATE, NULL) > 0)
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_UCM_OUTGOING_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_UCM_OUTGOING_CALL);
        }
    }
    else
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if (!srv_ucm_is_outgoing_call())
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        {
            mmi_frm_end_scenario(MMI_SCENARIO_ID_UCM_OUTGOING_CALL);
        }
    }

    /* In call scenario */
    if ((srv_ucm_bt_query_group_count(SRV_UCM_BT_OUTGOING_STATE, NULL) == 0) &&
        (srv_ucm_bt_query_group_count(SRV_UCM_BT_INCOMING_STATE, NULL) == 0) &&
        (srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0))
    {
        if (!mmi_frm_is_scenario_started(MMI_SCENARIO_ID_IN_CALL))
        {
            mmi_frm_start_scenario(MMI_SCENARIO_ID_IN_CALL);
        }
    }
    else
    {
    #ifdef __MMI_TELEPHONY_SUPPORT__
        if (srv_ucm_query_call_count(SRV_UCM_CALL_STATE_CONNECTED, SRV_UCM_CALL_TYPE_ALL, NULL) == 0)
    #endif /* __MMI_TELEPHONY_SUPPORT__ */
        {
            mmi_frm_end_scenario(MMI_SCENARIO_ID_IN_CALL);
        }
    }
}

static void srv_ucm_bt_sync_del_call(srv_ucm_bt_call_dev_info_struct* dev_info, U32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_DECREASE_DEL,
          call_index, dev_info->call_info[call_index].call_state,
          dev_info->call_info[call_index].num_uri[0],
          dev_info->call_info[call_index].num_uri[1],
          dev_info->call_info[call_index].num_uri[2]);

    srv_ucm_bt_free_call_id(dev_info->call_info[call_index].call_id);
    memset(&dev_info->call_info[call_index], 0, sizeof(srv_ucm_bt_call_info_struct));
}

static void srv_ucm_bt_sync_del_find(srv_ucm_bt_call_dev_info_struct* dev_info, U32 call_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MYTIME currnt_time;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_DECREASE_DEL_FIND,
          call_index, dev_info->call_info[call_index].call_state,
          dev_info->call_info[call_index].num_uri[0],
          dev_info->call_info[call_index].num_uri[1],
          dev_info->call_info[call_index].num_uri[2]);

    dev_info->call_end.call_id = dev_info->call_info[call_index].call_id;
    dev_info->call_end.srv_hd = dev_info->call_info[call_index].srv_hd;
    memcpy(&dev_info->call_end.dev_addr, &dev_info->dev_addr, sizeof(srv_bt_cm_bt_addr));
    memcpy(dev_info->call_end.dis_name, dev_info->call_info[call_index].dis_name, ENCODING_LENGTH*(SRV_UCM_BT_MAX_NUM_URI_LEN+1));

    if (dev_info->call_info[call_index].call_state & SRV_UCM_BT_CALL_STATE_CONNECTED)
    {
        DTGetRTCTime(&currnt_time);
        GetTimeDifference(&currnt_time, &dev_info->call_info[call_index].start_time, &dev_info->call_end.duration);
    }
    else
    {
        memset(&dev_info->call_end.duration, 0, sizeof(MYTIME));
    }
}

srv_ucm_bt_action_enum srv_ucm_bt_sync_call_list(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    S32 num_len;
    S32 i, j;
    S32 call_index = 0;
    MMI_BOOL is_find = MMI_FALSE;
    srv_ucm_bt_action_enum result = SRV_UCM_BT_ACTION_NONE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_CALL_LIST,dev_info->call_count ,dev_info->call_temp_count);

    if (dev_info->call_temp_count == dev_info->call_count) // update
    {
        // no call exist, don't update.
        if (dev_info->call_temp_count == 0)
        {
            return SRV_UCM_BT_ACTION_NONE;
        }

        for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
        {
            for (j = 0; j < dev_info->call_temp_count; j++)
            {
                if (dev_info->call_info[i].call_idx == dev_info->call_temp_list[j].call_idx)
                {
                    dev_info->call_info[i].dir = dev_info->call_temp_list[j].dir;
                    dev_info->call_info[i].mode = dev_info->call_temp_list[j].mode;
                    dev_info->call_info[i].multiParty = dev_info->call_temp_list[j].multiParty;
                    if (dev_info->call_info[i].call_state != dev_info->call_temp_list[j].call_state)
                    {
                        // call connect, record the start time
                        if ((dev_info->call_info[i].call_state & (srv_ucm_bt_call_state_enum)(SRV_UCM_BT_OUTGOING_STATE | SRV_UCM_BT_INCOMING_STATE))
                            && (dev_info->call_temp_list[j].call_state & SRV_UCM_BT_CALL_STATE_CONNECTED))
                        {
                            DTGetRTCTime(&(dev_info->call_info[i].start_time));
                        }

                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_STATE,
                                   i, dev_info->call_info[i].call_state, j, dev_info->call_temp_list[j].call_state);

                        dev_info->call_info[i].call_state = dev_info->call_temp_list[j].call_state;
                        result = SRV_UCM_BT_ACTION_UPDATE;
                    }
                    // call number is changed.
                    if (strcmp((CHAR*)dev_info->call_info[i].num_uri, (CHAR*)dev_info->call_temp_list[j].num_uri) != 0)
                    {
                        num_len = (strlen((CHAR*)dev_info->call_temp_list[j].num_uri) >= SRV_UCM_BT_MAX_NUM_URI_LEN) ? 
                                    SRV_UCM_BT_MAX_NUM_URI_LEN: 
                                    (strlen((CHAR*)dev_info->call_temp_list[j].num_uri)+1);
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_OLD,
                                    i, dev_info->call_info[i].num_uri[0], 
                                    dev_info->call_info[i].num_uri[1],
                                    dev_info->call_info[i].num_uri[2]);
                        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_NEW,
                                    j, dev_info->call_temp_list[j].num_uri[0], 
                                    dev_info->call_temp_list[j].num_uri[1],
                                    dev_info->call_temp_list[j].num_uri[2], num_len);

                        memcpy(dev_info->call_info[i].num_uri, dev_info->call_temp_list[j].num_uri, num_len);
                        mmi_asc_to_ucs2((CHAR*)dev_info->call_info[i].dis_name, (CHAR*)dev_info->call_temp_list[j].num_uri);
                    #if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__) 
                        srv_ucm_bt_get_remote_name(&dev_info->call_info[i]);
                    #endif
                        // update state
                        dev_info->call_info[i].call_state = dev_info->call_temp_list[j].call_state;
                        DTGetRTCTime(&(dev_info->call_info[i].start_time));
                        result = SRV_UCM_BT_ACTION_UPDATE;
                    }
                }
            }
        }
    }
    else if (dev_info->call_temp_count < dev_info->call_count) // decrease
    {
        for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_DECREASE_SINGLE,
                     i, dev_info->call_info[i].call_state, 
                     dev_info->call_info[i].num_uri[0],
                     dev_info->call_info[i].num_uri[1],
                     dev_info->call_info[i].num_uri[2]);

            if (dev_info->call_temp_count == 0)
            {
                if (dev_info->call_info[i].call_idx != 0)
                {
                    if (!is_find)
                    {
                        is_find = MMI_TRUE;
                        srv_ucm_bt_sync_del_find(dev_info, i);
                    }
                    srv_ucm_bt_sync_del_call(dev_info, i);
                    result = SRV_UCM_BT_ACTION_DELETE;
                }
                else
                {
                    continue;
                }
            }
            else
            {
                for(j = 0; j < dev_info->call_temp_count; j++)
                {
                    if (dev_info->call_info[i].call_idx == 0)
                    {
                        break;
                    }
                    if (dev_info->call_info[i].call_idx == dev_info->call_temp_list[j].call_idx)
                    {
                        if (dev_info->call_info[i].call_state != dev_info->call_temp_list[j].call_state)
                        {
                            if (dev_info->call_info[i].call_state & (srv_ucm_bt_call_state_enum)(SRV_UCM_BT_INCOMING_STATE|SRV_UCM_BT_OUTGOING_STATE))
                            {
                                DTGetRTCTime(&(dev_info->call_info[i].start_time));
                                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_TIME, i);
                            }
                            dev_info->call_info[i].call_state = dev_info->call_temp_list[j].call_state;
                        }
                        // call number is changed.
                        if (strcmp((CHAR*)dev_info->call_info[i].num_uri, (CHAR*)dev_info->call_temp_list[j].num_uri) != 0)
                        {
                            num_len = (strlen((CHAR*)dev_info->call_temp_list[j].num_uri) >= SRV_UCM_BT_MAX_NUM_URI_LEN) ? 
                                        SRV_UCM_BT_MAX_NUM_URI_LEN: (strlen((CHAR*)dev_info->call_temp_list[j].num_uri)+1);
                            memcpy(dev_info->call_info[i].num_uri, dev_info->call_temp_list[j].num_uri, num_len);
                            mmi_asc_to_ucs2((CHAR*)dev_info->call_info[i].dis_name, (CHAR*)dev_info->call_temp_list[j].num_uri);
                        #if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__) 
                            srv_ucm_bt_get_remote_name(&dev_info->call_info[i]);
                        #endif
                            DTGetRTCTime(&(dev_info->call_info[i].start_time));

                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_TIME, i);
                            dev_info->call_info[i].call_state = dev_info->call_temp_list[j].call_state;
                        }
                        dev_info->call_info[i].multiParty = dev_info->call_temp_list[j].multiParty;
                        break;
                    }
                }
                if (j == dev_info->call_temp_count)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_DECREASE_FIND);
                    if (!is_find)
                    {
                        is_find = MMI_TRUE;
                        srv_ucm_bt_sync_del_find(dev_info, i);
                    }
                    srv_ucm_bt_sync_del_call(dev_info, i);
                    result = SRV_UCM_BT_ACTION_DELETE;
                }
            }
        }
    }
    else // increase (call_temp_count > call_count)
    {
        for (i = 0; i < dev_info->call_temp_count; i++)
        {
            for (j = 0; j < SRV_UCM_BT_MAX_CALL; j++)
            {
                if (dev_info->call_info[j].call_idx == dev_info->call_temp_list[i].call_idx)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_INCREASE_SAME, dev_info->call_info[j].call_idx);
                    // call number is changed.
                    if (strcmp((CHAR*)dev_info->call_info[j].num_uri, (CHAR*)dev_info->call_temp_list[i].num_uri) != 0)
                    {
                        num_len = (strlen((CHAR*)dev_info->call_temp_list[i].num_uri) >= SRV_UCM_BT_MAX_NUM_URI_LEN) ? 
                                    SRV_UCM_BT_MAX_NUM_URI_LEN: (strlen((CHAR*)dev_info->call_temp_list[i].num_uri)+1);
                        memcpy(dev_info->call_info[j].num_uri, dev_info->call_temp_list[i].num_uri, num_len);
                        mmi_asc_to_ucs2((CHAR*)dev_info->call_info[j].dis_name, (CHAR*)dev_info->call_temp_list[i].num_uri);
                    #if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__) 
                        srv_ucm_bt_get_remote_name(&dev_info->call_info[j]);
                    #endif
                        if (dev_info->call_temp_list[i].call_state & SRV_UCM_BT_CALL_STATE_CONNECTED)
                        {
                            DTGetRTCTime(&(dev_info->call_info[j].start_time));
                            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_TIME, j);
                        }
                        dev_info->call_info[j].call_state = dev_info->call_temp_list[i].call_state;
                    }
                    else if (dev_info->call_info[j].call_state ^ dev_info->call_temp_list[i].call_state)
                    {
                        dev_info->call_info[j].call_state = dev_info->call_temp_list[i].call_state;
                    }
                    break;
                }
            }
            if (j == SRV_UCM_BT_MAX_CALL)
            {
                call_index = srv_ucm_bt_get_free_call_index(srv_hd);
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_INCREASE_INDEX, call_index);
                if (call_index == -1)
                {
                    return SRV_UCM_BT_ACTION_NONE;
                }
                dev_info->call_info[call_index].srv_hd = srv_hd;
                dev_info->call_info[call_index].call_idx = dev_info->call_temp_list[i].call_idx;
                dev_info->call_info[call_index].call_state = dev_info->call_temp_list[i].call_state;
                dev_info->call_info[call_index].dir = dev_info->call_temp_list[i].dir;
                dev_info->call_info[call_index].mode = dev_info->call_temp_list[i].mode;
                dev_info->call_info[call_index].multiParty = dev_info->call_temp_list[i].multiParty;
                dev_info->call_info[call_index].call_id = srv_ucm_bt_get_free_call_id();
                MMI_ASSERT(dev_info->call_info[call_index].call_id);
                num_len = (strlen((CHAR*)dev_info->call_temp_list[i].num_uri) >= SRV_UCM_BT_MAX_NUM_URI_LEN) ? 
                                    SRV_UCM_BT_MAX_NUM_URI_LEN: 
                                    (strlen((CHAR*)dev_info->call_temp_list[i].num_uri)+1);
                memcpy(dev_info->call_info[call_index].num_uri, dev_info->call_temp_list[i].num_uri, num_len);
                mmi_asc_to_ucs2((CHAR*)dev_info->call_info[call_index].dis_name, (CHAR*)dev_info->call_temp_list[i].num_uri);

                if (dev_info->mo_name_from_app && dev_info->mo_num_from_app
                    && dev_info->call_info[call_index].call_state & SRV_UCM_BT_OUTGOING_STATE
                    && strcmp((CHAR*)dev_info->mo_num_from_app, (CHAR*)dev_info->call_info[call_index].num_uri) == 0)
                {
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NAME_FROM_APP, 501, dev_info->mo_name_from_app);
                    mmi_ucs2ncpy((CHAR*)dev_info->call_info[call_index].dis_name,
                             (CHAR*)dev_info->mo_name_from_app,
                             SRV_UCM_BT_MAX_NUM_URI_LEN);
                    srv_ucm_bt_free_mo_info_from_app(dev_info);
                }
            #if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__)
                else
                {
                    // TODO: add query phb
                    srv_ucm_bt_get_remote_name(&dev_info->call_info[call_index]);
                }
            #endif

                if (dev_info->call_temp_list[i].call_state & SRV_UCM_BT_CALL_STATE_CONNECTED)
                {
                    DTGetRTCTime(&(dev_info->call_info[call_index].start_time));
                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_UPDATE_TIME, call_index);
                    result = SRV_UCM_BT_ACTION_UPDATE;
                }
                else if (dev_info->call_temp_list[i].call_state & SRV_UCM_BT_OUTGOING_STATE)
                {
                    result = SRV_UCM_BT_ACTION_ADD_MO;
                }
                else if (dev_info->call_temp_list[i].call_state & SRV_UCM_BT_INCOMING_STATE)
                {
                    result = SRV_UCM_BT_ACTION_ADD_MT;
                }

                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_INCREASE_CALL_INFO,
                          i , dev_info->call_temp_list[i].call_state, dev_info->call_temp_list[i].num_uri[0],
                          dev_info->call_temp_list[i].num_uri[1], dev_info->call_temp_list[i].num_uri[2]);
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_INCREASE_CALL_STATE,
                          i , dev_info->call_info[i].call_state, dev_info->call_info[i].num_uri[0],
                          dev_info->call_info[i].num_uri[1], dev_info->call_info[i].num_uri[2]);

            }
        }
    }
    if (dev_info->call_count != 0 && dev_info->call_temp_count == 0)
    {
        U8 conn_id = srv_bt_dialer_get_connection_id(srv_hd);
        // Reset the initial state
        srv_bt_dialer_post_evt_to_a2dp();
        srv_bt_dialer_set_incoming_call_ans_status(conn_id, MMI_FALSE);
    }
    dev_info->call_count = dev_info->call_temp_count;
    dev_info->call_temp_count = 0;
    memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));
    srv_ucm_bt_free_mo_info_from_app(dev_info);
    // conf exist
    if (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_ACTIVE_STATE, NULL) > 1
      || srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_HOLD_STATE, NULL) > 1)
    {
        StartTimerEx(UCM_CONF_REFRESH_TIMER_ID, SRV_UCM_BT_CONF_REF_TIME, srv_ucm_bt_conf_refresh_handler, &dev_info->srv_hd);
    }
    else if (IsMyTimerExist(UCM_CONF_REFRESH_TIMER_ID))
    {
        StopTimer(UCM_CONF_REFRESH_TIMER_ID);
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SYNC_RESULT, result);
    return result;
}

static void srv_ucm_bt_reset_call_list(srv_ucm_bt_call_dev_info_struct* dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_count;
    S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    U32 idx;
    srv_ucm_bt_reset_call_list_ind_struct cmd_err;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(dev_info);

    call_count = srv_ucm_bt_query_call_count_ext(dev_info->srv_hd , SRV_UCM_BT_CALL_STATE_ALL, call_list);

    srv_ucm_bt_abort_compound_action(dev_info->srv_hd);

    for (idx = 0; idx < call_count; idx++)
    {
        srv_ucm_bt_free_call_id(call_list[idx]);
    }

    srv_ucm_bt_free_mo_info_from_app(dev_info);

    dev_info->pending_action = SRV_UCM_BT_NO_ACT;
    dev_info->call_count = 0;
    dev_info->call_temp_count = 0;
    dev_info->sync_result = SRV_UCM_BT_ACTION_NONE;
    dev_info->ring_enable = FG_SRV_UCM_BT_RING_NONE;
    dev_info->ciev_ind.setup = SRV_BT_DIALER_CALL_SETUP_COMPLETE;
    dev_info->ciev_ind.call = SRV_BT_DIALER_CALL_NOT_ACTIVE;
    dev_info->ciev_ind.held = SRV_BT_DIALER_NO_CALL_HELD;
    memset(dev_info->call_info, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_info_struct));
    memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));

    cmd_err.srv_hd = dev_info->srv_hd;
    srv_ucm_bt_send_indication(SRV_UCM_BT_RESET_CALL_LIST_IND, &cmd_err);
    srv_ucm_bt_call_scenario_control();

    if (!srv_ucm_bt_is_any_call())
    {
        mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
    }
    else
    {
        srv_ucm_bt_call_info_struct call_info;
        if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, call_list) > 0)
        {
            if (srv_ucm_bt_query_call_data(call_list[0], &call_info))
            {
                srv_ucm_bt_refresh_ind(call_info.srv_hd);
            }
        }
    }
}


S32 srv_ucm_bt_register_notify_callback(srv_ucm_bt_notify_cb callback, U32 evt_mask, void* user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 noti_hd = SRV_UCM_BT_UNKNOWN_ERR;
    U32 reg_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL && evt_mask > 0)
    {
        U32 i;
        for (i = 0; i < SRV_UCM_BT_MAX_INSTANCE_NUM; i++)
        {
            if (g_ucm_bt_srv_p->noti_inst[i].noti_hd == 0)
            {
                noti_hd = i + 1;
                g_ucm_bt_srv_p->noti_inst[i].noti_hd = noti_hd;
                g_ucm_bt_srv_p->noti_inst[i].notifier = callback;
                g_ucm_bt_srv_p->noti_inst[i].event_mask = evt_mask;
                g_ucm_bt_srv_p->noti_inst[i].user_data = user_data;
                break;
            }
            else if (g_ucm_bt_srv_p->noti_inst[i].notifier == callback)
            {
                noti_hd = SRV_UCM_BT_REGISTERED;
                break;
            }
            else
            {
                reg_count++;
            }
        }
        if (reg_count == SRV_UCM_BT_MAX_INSTANCE_NUM)
        {
            noti_hd = SRV_UCM_BT_INST_FULL;
        }
    }
    else
    {
        noti_hd = SRV_UCM_BT_INVALD_PARA;
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_REG_NOTI_CB, noti_hd, callback, evt_mask);
    return noti_hd;
}


S32 srv_ucm_bt_deregister_notify_callback(S32 noti_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if ((noti_hd > 0) && (noti_hd <= SRV_UCM_BT_MAX_INSTANCE_NUM))
    {
        memset(&g_ucm_bt_srv_p->noti_inst[noti_hd - 1], 0, sizeof(srv_ucm_bt_notify_struct));
        result = SRV_UCM_BT_SUCCESS;
    }
    else
    {
        result = SRV_UCM_BT_INVALD_PARA;
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_DEREG_NOTI_CB, noti_hd, result);
    return result;
}


void srv_ucm_bt_register_hf_connection_event(srv_bt_dialer_notify_event_struct* notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 call_list[SRV_UCM_BT_ALL_DEV_MAX_CALL];
#ifdef __BT_HF_BVRA_SUPPORT__
    srv_ucm_bt_link_ind_struct link_ind;
#endif /* __BT_HF_BVRA_SUPPORT__ */

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(notify);

#ifdef __BT_HF_BVRA_SUPPORT__
    memset(&link_ind, 0, sizeof(srv_ucm_bt_link_ind_struct));
#endif /* __BT_HF_BVRA_SUPPORT__ */

    switch(notify->event_id)
    {
        case SRV_BT_DIALER_EVT_ID_DISCONNECT_IND:

            srv_ucm_bt_del_device(&notify->result.conn_info.dev_addr);

            if (!srv_ucm_bt_is_any_call())
            {
                srv_ucm_bt_call_scenario_control();
                srv_ucm_bt_send_indication(SRV_UCM_BT_HF_DEINIT_IND, NULL);
                if (srv_bt_dialer_is_any_call_ex(&notify->result.conn_info.dev_addr))
                {
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                }

            #ifdef __BT_HF_BVRA_SUPPORT__
                memcpy(&link_ind.bt_addr, &notify->result.conn_info.dev_addr, sizeof(srv_bt_cm_bt_addr));
                link_ind.type = SRV_UCM_BT_CONN_TYPE_LINK_OFF;
                srv_ucm_bt_send_indication(SRV_UCM_BT_CONN_TYPE_IND, &link_ind);
            #endif /* __BT_HF_BVRA_SUPPORT__ */
            }
            else
            {
                srv_ucm_bt_call_info_struct call_info;
                if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, call_list) > 0)
                {
                    if (srv_ucm_bt_query_call_data(call_list[0], &call_info))
                    {
                        srv_ucm_bt_refresh_ind(call_info.srv_hd);
                    }
                }
            }

            break;

        case SRV_BT_DIALER_EVT_ID_DISCONNECT_REQ:
            break;

        case SRV_BT_DIALER_EVT_ID_CONNECT_CNF:

            if (notify->result.conn_cnf.result != 0)
            {
                srv_ucm_bt_del_device(&notify->result.conn_cnf.dev_addr);
            }
            else
            {
                srv_ucm_bt_call_dev_info_struct* dev_p;

                dev_p = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_ADDR, (void*)&notify->result.conn_cnf.dev_addr);

                if (dev_p)
                {
                    // SP already has a active/held call, then connected
                    if (!dev_p->conn_cnf && srv_bt_dialer_is_any_call_ex(&notify->result.conn_cnf.dev_addr))
                    {
                        mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                    }
                    dev_p->conn_cnf = MMI_TRUE;
                }
            }

        #ifdef __BT_HF_BVRA_SUPPORT__
            if (notify->result.conn_cnf.result == 0)
            {
                memcpy(&link_ind.bt_addr, &notify->result.conn_cnf.dev_addr, sizeof(srv_bt_cm_bt_addr));
                link_ind.type = SRV_UCM_BT_CONN_TYPE_LINK_ON;
                srv_ucm_bt_send_indication(SRV_UCM_BT_CONN_TYPE_IND, &link_ind);
            }
        #endif /* __BT_HF_BVRA_SUPPORT__ */
            break;

        case SRV_BT_DIALER_EVT_ID_DISCONNECT_CNF:

            srv_ucm_bt_del_device(&notify->result.conn_cnf.dev_addr);

            if (!srv_ucm_bt_is_any_call())
            {
                srv_ucm_bt_send_indication(SRV_UCM_BT_HF_DEINIT_IND, NULL);
                if (srv_bt_dialer_is_any_call_ex(&notify->result.conn_cnf.dev_addr))
                {
                    mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                }

            #ifdef __BT_HF_BVRA_SUPPORT__
                memcpy(&link_ind.bt_addr, &notify->result.conn_cnf.dev_addr, sizeof(srv_bt_cm_bt_addr));
                link_ind.type = SRV_UCM_BT_CONN_TYPE_LINK_OFF;
                srv_ucm_bt_send_indication(SRV_UCM_BT_CONN_TYPE_IND, &link_ind);
            #endif /* __BT_HF_BVRA_SUPPORT__ */
            }
            else
            {
                srv_ucm_bt_call_info_struct call_info;
                if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, call_list) > 0)
                {
                    if (srv_ucm_bt_query_call_data(call_list[0], &call_info))
                    {
                        srv_ucm_bt_refresh_ind(call_info.srv_hd);
                    }
                }
            }

            break;

        case SRV_BT_DIALER_EVT_ID_CONNECT_REQ:
        case SRV_BT_DIALER_EVT_ID_CONNECT_IND:

            srv_ucm_bt_new_device(&notify->result.conn_info.dev_addr, srv_ucm_bt_register_hf_event);
            break;

        default:
            break;
    }
}

void srv_ucm_bt_register_hf_event(S32 srv_hd, srv_bt_dialer_notify_event_struct* notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_action_enum result = SRV_UCM_BT_ACTION_NONE;
    srv_ucm_bt_act_rsp_struct act_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info && notify);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_CMD_EVT_CB, notify->event_id);

    switch(notify->event_id)
    {
        case SRV_BT_DIALER_CIEV_CALL_SETUP_INDICATION:
        {
            srv_ucm_bt_ciev_ind_hdlr(srv_hd, SRV_BT_DIALER_STATE_SETUP, notify->result.call_setup_ind.setup);
            if (srv_ucm_bt_check_ring_flag(dev_info->ring_enable, FG_SRV_UCM_BT_RING_NON_NONE)
            && SRV_BT_DIALER_CALL_SETUP_COMPLETE == notify->result.call_setup_ind.setup)
            {
                srv_ucm_bt_reset_ring_flag(dev_info->ring_enable);
            }
        }
        break;

        case SRV_BT_DIALER_CIEV_CALL_INDICATION:
        {
            srv_ucm_bt_ciev_ind_hdlr(srv_hd, SRV_BT_DIALER_STATE_CALL, notify->result.call_ind.call);
        }
        break;

        case SRV_BT_DIALER_EVT_ID_AT_CALL_HOLD:
        {
            srv_ucm_bt_ciev_ind_hdlr(srv_hd, SRV_BT_DIALER_STATE_HOLD, notify->result.held_ind.held);
        }
        break;

        case SRV_BT_DIALER_EVT_ID_AT_VGS_IND:
        {
            srv_ucm_bt_vgs_sync_ind(srv_hd, notify->result.vgs.gain);
        }
        break;
    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_BT_DIALER_EVT_ID_AT_VOICE_RECOGNITION:
        {
            srv_ucm_bt_bvra_ind(srv_hd, (MMI_BOOL)notify->result.vrec.enabled);
        }
        break;
    #endif /* __BT_HF_BVRA_SUPPORT__  */

    #ifdef __MMI_HF_BAT_SUPPORT__
        case SRV_BT_DIALER_EVT_ID_AT_XAPL_RSP:
        {
            srv_ucm_bt_custom_at_support_ind(srv_hd, notify->result.xapl.valid, notify->result.xapl.features);
        }
        break;
    #endif /* __MMI_HF_BAT_SUPPORT__ */

        case SRV_BT_DIALER_EVT_ID_CLIP_IND:
        {
            if (srv_bt_dialer_list_current_calls(srv_hd))
            {
                memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));
            }
        }
        break;

        // only for BQB, TC_HF_ICA_BV_05_I
        case SRV_BT_DIALER_EVT_ID_AT_BSIR_IND:
        {
        }
        break;

        case SRV_BT_DILAER_EVT_ID_SCO_CONN_IND:
        {
            // srv_ucm_bt_sco_state_sync_hdlr(srv_hd, notify->result.sco_conn_ind.is_open);
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_SCO_IND,notify->result.sco_conn_ind.is_open);
        #ifdef __BT_HF_BVRA_SUPPORT__
            srv_ucm_bt_event_notify(SRV_UCM_BT_NOTI_EVT_CONN, (void*)notify->result.sco_conn_ind.is_open);
        #endif /* __BT_HF_BVRA_SUPPORT__ */
        }
        break;

        case SRV_BT_DIALER_EVT_ID_AT_IN_BAND_RING_TONE:
        {
            MMI_BOOL wait;
            srv_ucm_bt_set_ring_flag(dev_info->ring_enable, FG_SRV_UCM_BT_RING_IND);
            if (srv_ucm_bt_query_group_count_ext(srv_hd, SRV_UCM_BT_INCOMING_STATE, NULL) > 0
               && !srv_ucm_bt_check_ring_flag(dev_info->ring_enable, FG_SRV_UCM_BT_RING_EVT_DONE))
            {
                srv_ucm_bt_set_ring_flag(dev_info->ring_enable, FG_SRV_UCM_BT_RING_EVT_DONE);
                if (dev_info->call_count == srv_ucm_bt_query_group_count(SRV_UCM_BT_CALL_STATE_ALL, NULL))
                {
                    wait = MMI_FALSE;
                }
                else
                {
                    wait = MMI_TRUE;
                }
                srv_ucm_bt_ring_ind(srv_hd, wait);
            }
        }
        break;

        case SRV_BT_DIALER_EVT_ID_AT_DIAL_CMD_RSP:
        {
            if (SRV_BT_DIALER_ATCME_SUCCESS != notify->result.error_code.error && NULL != dev_info->mo_name_from_app)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NAME_FROM_APP, 301, dev_info->mo_name_from_app);
                srv_ucm_bt_free_mo_info_from_app(dev_info);
            }
        }

    #ifdef __BT_HF_BVRA_SUPPORT__
        case SRV_BT_DIALER_EVT_ID_AT_BVRA_RSP: 
    #endif /* __BT_HF_BVRA_SUPPORT__ */
        case SRV_BT_DIALER_EVT_ID_AT_HANGUP_ACTIVE_CALLS_RSP:
        case SRV_BT_DIALER_EVT_ID_ATA_CMD_RSP:
        case SRV_BT_DIALER_EVT_ID_AT_HOLD_ACTION_RSP:
        {
            srv_ucm_bt_auto_sco_update(srv_hd, notify->event_id);

            if (srv_ucm_bt_is_pending_action(srv_hd))
            {
                if (!g_ucm_bt_srv_p->comp_action || SRV_BT_DIALER_ATCME_SUCCESS != notify->result.error_code.error)
                {
                    act_rsp.srv_hd = srv_hd;
                    act_rsp.result = srv_ucm_bt_tranfer_error_code(notify->result.error_code.error);
                    act_rsp.op_code = srv_ucm_bt_get_pending_action(srv_hd);

                    srv_ucm_bt_send_act_notify(act_rsp.op_code, SRV_UCM_BT_ACT_NOTIFY_END, (void*)&act_rsp);

                    srv_ucm_bt_reset_pending_action(srv_hd);
                }
                if (SRV_BT_DIALER_ATCME_SUCCESS != notify->result.error_code.error)
                {
                #ifdef __BT_HF_BVRA_SUPPORT__
                    // BVRA use for MRE app "Siri", it will cause interaction issue if reset call list, just ignore.
                    if (SRV_BT_DIALER_EVT_ID_AT_BVRA_RSP != notify->event_id)
                #endif /* __BT_HF_BVRA_SUPPORT__ */
                    {
                        srv_ucm_bt_reset_call_list(dev_info);
                    }
                }
            }
        }
        break;

        case SRV_BT_DIALER_EVT_ID_AT_LIST_CURRENT_CALLS:
        {
            if (notify->result.currentCalls.error != SRV_BT_DIALER_ATCME_SUCCESS)
            {
                srv_ucm_bt_cmd_fail_ind_struct fail_ind;

                fail_ind.srv_hd = srv_hd;
                srv_ucm_bt_send_indication(SRV_UCM_BT_CMD_FAIL_IND, &fail_ind);
                srv_ucm_bt_reset_call_list(dev_info);
                break;
            }

            if (notify->result.currentCalls.final)
            {
                S32 all_count;

                result = srv_ucm_bt_sync_call_list(srv_hd);

                all_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL);

                srv_ucm_bt_call_scenario_control();

                if (SRV_UCM_BT_ACTION_NONE != result)
                {
                    if (dev_info->sync_result != result || result == SRV_UCM_BT_ACTION_DELETE)
                    {
                        dev_info->sync_result = result;
                        if (SRV_UCM_BT_ACTION_ADD_MO == result)
                        {
                            if (all_count == dev_info->call_count)
                            {
                                mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                            }
                            srv_ucm_bt_outgoing_call_ind(srv_hd);
                        }
                        else if (SRV_UCM_BT_ACTION_ADD_MT == result)
                        {
                            MMI_BOOL wait;
                            if (all_count == dev_info->call_count)
                            {
                                mdi_audio_suspend_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                            }

                            srv_ucm_bt_incoming_call_ind(srv_hd);

                            if (!(dev_info->ring_enable ^ FG_SRV_UCM_BT_RING_IND))
                            {
                                srv_ucm_bt_set_ring_flag(dev_info->ring_enable, FG_SRV_UCM_BT_RING_EVT_DONE);
                                if (all_count == dev_info->call_count)
                                {
                                    wait = MMI_FALSE;
                                }
                                else
                                {
                                    wait = MMI_TRUE;
                                }
                                srv_ucm_bt_ring_ind(srv_hd, wait);
                            }
                        }
                        else if (SRV_UCM_BT_ACTION_DELETE == result)
                        {
                            if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
                            {
                                mdi_audio_resume_background_play_by_app(MDI_AUD_SUSPEND_BG_UCM_BT);
                            }
                            srv_ucm_bt_release_ind(srv_hd);
                        }
                        else if (SRV_UCM_BT_ACTION_UPDATE == result)
                        {
                            srv_ucm_bt_refresh_ind(srv_hd);
                        }
                    }
                    else
                    {
                        srv_ucm_bt_refresh_ind(srv_hd);
                    }

                    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_IS_COMP_ACT ,g_ucm_bt_srv_p->comp_action);
                    if (g_ucm_bt_srv_p->comp_action)
                    {
                        srv_ucm_bt_next_comp_action();
                        g_ucm_bt_srv_p->comp_action = MMI_FALSE;
                    }
                }
                else if (SRV_UCM_BT_FORCE_REFRESH_ACT == srv_ucm_bt_get_pending_action(srv_hd))
                {
                    srv_ucm_bt_refresh_ind(srv_hd);
                    srv_ucm_bt_reset_pending_action(srv_hd);
                }
            }
            else if (srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, &dev_info->dev_addr))
            {
                srv_ucm_bt_add_to_temp_list(srv_hd, &notify->result);
            }
          }
          break;

          default:
          break;
    }
}

void srv_ucm_bt_outgoing_call_ind(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_info_struct* call_info;
    srv_ucm_bt_outgoing_call_ind_struct outgoing_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_info = srv_ucm_bt_get_call_info(srv_hd, SRV_UCM_BT_CALL_BY_STATE, (U8)SRV_UCM_BT_OUTGOING_STATE);

    MMI_ASSERT(call_info);

    memset(&outgoing_ind, 0, sizeof(outgoing_ind));

    outgoing_ind.srv_hd = srv_hd;
    outgoing_ind.call_id = call_info->call_id;
    memcpy(outgoing_ind.num_uri, call_info->num_uri, SRV_UCM_BT_MAX_NUM_URI_LEN);
    memcpy(outgoing_ind.dis_name, call_info->dis_name, ENCODING_LENGTH * SRV_UCM_BT_MAX_NUM_URI_LEN);

    srv_ucm_bt_send_indication(SRV_UCM_BT_OUTGOING_CALL_IND, &outgoing_ind);
}

void srv_ucm_bt_incoming_call_ind(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_info_struct* call_info;
    srv_ucm_bt_incoming_call_ind_struct incoming_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    call_info = srv_ucm_bt_get_call_info(srv_hd, SRV_UCM_BT_CALL_BY_STATE, (U8)SRV_UCM_BT_INCOMING_STATE);

    MMI_ASSERT(call_info);

    memset(&incoming_ind, 0, sizeof(incoming_ind));

    incoming_ind.srv_hd = srv_hd;
    incoming_ind.call_id = call_info->call_id;
    memcpy(incoming_ind.num_uri, call_info->num_uri, SRV_UCM_BT_MAX_NUM_URI_LEN);
    memcpy(incoming_ind.dis_name, call_info->dis_name, ENCODING_LENGTH * SRV_UCM_BT_MAX_NUM_URI_LEN);

    srv_ucm_bt_send_indication(SRV_UCM_BT_INCOMING_CALL_IND, &incoming_ind);
}

void srv_ucm_bt_vgs_sync_ind(S32 srv_hd, U8 gain)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_vgs_ind_struct vgs_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    vgs_ind.gain = gain;
    vgs_ind.srv_hd = srv_hd;

    srv_ucm_bt_send_indication(SRV_UCM_BT_VGS_SYNC_IND, &vgs_ind);
}

void srv_ucm_bt_release_ind(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_release_call_ind_struct release_ind;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    memcpy(&release_ind, &dev_info->call_end, sizeof(srv_ucm_bt_release_call_ind_struct));
    srv_ucm_bt_send_indication(SRV_UCM_BT_RELEASE_IND, &release_ind);
}

void srv_ucm_bt_refresh_ind(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_refresh_call_ind_struct refresh;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh.srv_hd = srv_hd;
    srv_ucm_bt_send_indication(SRV_UCM_BT_REFRESH_IND, &refresh);
}

void srv_ucm_bt_ring_ind(S32 srv_hd, MMI_BOOL wait)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_ring_ind_struct ring;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ring.srv_hd = srv_hd;
    ring.wait_tone = wait;
    srv_ucm_bt_send_indication(SRV_UCM_BT_RING_IND, &ring);
}

void srv_ucm_bt_sys_time_change_ind(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_sys_time_change_ind_struct refresh;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    refresh.srv_hd = srv_hd;
    srv_ucm_bt_send_indication(SRV_UCM_BT_SYS_TIME_CHANGE_IND, &refresh);
}

void srv_ucm_bt_sco_state_sync_hdlr(S32 srv_hd, MMI_BOOL open)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
}

#ifdef __BT_HF_BVRA_SUPPORT__
void srv_ucm_bt_bvra_ind(S32 srv_hd, MMI_BOOL enable)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_bvra_ind_struct bvra;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bvra.srv_hd = srv_hd;
    bvra.enable = enable;
    srv_ucm_bt_send_indication(SRV_UCM_BT_BVRA_IND, &bvra);
}
#endif /* __BT_HF_BVRA_SUPPORT__ */

#ifdef __MMI_HF_BAT_SUPPORT__
void srv_ucm_bt_custom_at_support_ind(S32 srv_hd, MMI_BOOL valid, U8 features)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_custom_at_ind_struct custom_cmd;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (valid)
    {
        custom_cmd.srv_hd = srv_hd;
        custom_cmd.features = features;

        dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

        MMI_ASSERT(dev_info);

        dev_info->custom_features = features;

        srv_ucm_bt_send_indication(SRV_UCM_BT_CUST_AT_IND, &custom_cmd);
    }
}
#endif /* __MMI_HF_BAT_SUPPORT__ */
void srv_ucm_bt_dial_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_atd_act_req_struct* atd_req = (srv_ucm_bt_atd_act_req_struct*)act_data;
    U8 num[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];
    U32 len;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(atd_req);
    memset(num, 0, sizeof(num));

    mmi_ucs2_to_asc((CHAR*)num, (CHAR*)atd_req->num_uri);

    len = mmi_ucs2strlen((CHAR*)(atd_req->dis_name));
    if (len > 0 && len <= SRV_UCM_BT_MAX_DIS_NAME_FROM_APP)
    {
        dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &atd_req->srv_hd);
        if (NULL != dev_info)
        {
            dev_info->mo_name_from_app = OslMalloc(sizeof(atd_req->dis_name));
            dev_info->mo_num_from_app = OslMalloc(sizeof(num));
            memcpy(dev_info->mo_name_from_app, atd_req->dis_name, sizeof(atd_req->dis_name));
            memcpy(dev_info->mo_num_from_app, num, sizeof(num));
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NAME_FROM_APP, 101, dev_info->mo_name_from_app);
        }
    }
    srv_ucm_bt_set_pending_action(atd_req->srv_hd, SRV_UCM_BT_DIAL_ACT);
    srv_bt_dialer_send_dial_req(atd_req->srv_hd, (CHAR*)num);
}


#ifdef __BT_HF_BVRA_SUPPORT__
void srv_ucm_bt_bvra_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_bvra_act_req_struct* req = (srv_ucm_bt_bvra_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    srv_ucm_bt_set_pending_action(req->srv_hd, SRV_UCM_BT_BVRA_ACT);
    srv_bt_dialer_send_voice_recognition_req(req->srv_hd, req->enable);
}
#endif /* __BT_HF_BVRA_SUPPORT__ */

#ifdef __MMI_UCM_BT_BTBOX_NOLCD__
void srv_ucm_bt_redial_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_atd_act_req_struct* atd_req = (srv_ucm_bt_atd_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(atd_req);
    srv_bt_dialer_send_redial_req(atd_req->srv_hd);
}
#endif /* __MMI_UCM_BT_BTBOX_NOLCD__ */


void srv_ucm_bt_accept_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 con_call_count;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    srv_ucm_bt_ata_act_req_struct* ata_req = (srv_ucm_bt_ata_act_req_struct*)act_data;
    MMI_BOOL cmd = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(ata_req);
    con_call_count = srv_ucm_bt_query_group_count_ext(ata_req->srv_hd, SRV_UCM_BT_CALL_STATE_CONNECTED, NULL);

    if (srv_ucm_bt_query_group_count_ext(ata_req->srv_hd, SRV_UCM_BT_INCOMING_STATE, NULL) > 0)
    {
        if (con_call_count == 0)
        {
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
         #endif
            {
                cmd = MMI_TRUE;
                srv_bt_dialer_send_ata_req(ata_req->srv_hd);
            }
        }
        else if (con_call_count == 1)
        {
        /** Places all active calls (if any exist) on hold and accepts the other
                *  (held or waiting) call. If "call" is specified, places all active calls
                *  on hold except the specified call.
                */
            cmd = MMI_TRUE;
            srv_bt_dialer_hold_all_active_calls(ata_req->srv_hd, (S8)(-1));
        }
        else if (con_call_count > 1)
        {
        /** Releases all active calls (if any exist) and accepts the other
                *  (held or waiting) call. If "call" is specified, will release the
                *  specific call.
                */
            cmd = MMI_TRUE;
            srv_bt_dialer_release_all_active_calls(ata_req->srv_hd, (S8)(-1));
        }
        if (cmd)
        {
            srv_ucm_bt_set_pending_action(ata_req->srv_hd, SRV_UCM_BT_ACCEPT_ACT);
        }
    }
}
void srv_ucm_bt_hold_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* hold_req = (srv_ucm_bt_chld_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(hold_req);
    srv_ucm_bt_set_pending_action(hold_req->act_hd, SRV_UCM_BT_HOLD_ACT);
    srv_bt_dialer_hold_all_active_calls(hold_req->act_hd, (S8)(-1));
}

void srv_ucm_bt_retrieve_action (void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* rtv_req = (srv_ucm_bt_chld_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_set_pending_action(rtv_req->hold_hd, SRV_UCM_BT_RETRIEVE_ACT);
    srv_bt_dialer_send_call_retrieve_req(rtv_req->hold_hd);
}

void srv_ucm_bt_swap_action (void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* swap_req = (srv_ucm_bt_chld_act_req_struct*)act_data;
    srv_ucm_bt_call_info_struct* call_info;
    srv_ucm_bt_chld_act_req_struct* chld_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (swap_req->act_hd == swap_req->hold_hd)
    {
        srv_bt_dialer_hold_all_active_calls(swap_req->act_hd,(S8)(-1));
    }
    else
    {
        g_ucm_bt_srv_p->comp_action = MMI_TRUE;
        srv_bt_dialer_hold_all_active_calls(swap_req->act_hd, (S8)(-1));

        call_info = srv_ucm_bt_get_call_info(swap_req->hold_hd, SRV_UCM_BT_CALL_BY_CALL_ID, swap_req->hold_id);
        MMI_ASSERT(call_info);

        chld_req = OslMalloc(sizeof(srv_ucm_bt_chld_act_req_struct));
        chld_req->hold_id = swap_req->hold_id;
        chld_req->hold_hd= swap_req->hold_hd;

        call_info->proc_act = SRV_UCM_BT_RETRIEVE_ACT;
        call_info->action_data = chld_req;
    }
    srv_ucm_bt_set_pending_action(swap_req->act_hd, SRV_UCM_BT_SWAP_ACT);
}

void srv_ucm_bt_end_single_action (void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_single_act_req_struct* req = (srv_ucm_bt_end_single_act_req_struct*)act_data;
    srv_ucm_bt_call_info_struct* call_info;
    S32 call_count;
    MMI_BOOL cmd = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    call_info = srv_ucm_bt_get_call_info(req->srv_hd, SRV_UCM_BT_CALL_BY_CALL_ID, req->call_id);

    MMI_ASSERT(call_info);

    call_count = srv_ucm_bt_query_call_count_ext(call_info->srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL);

    if (call_count == 1 || (call_info->call_state & SRV_UCM_BT_OUTGOING_STATE))
    {
        cmd = MMI_TRUE;
        srv_bt_dialer_hangup_current_call(call_info->srv_hd);
    }
    else if (call_count > 1)
    {
        if (call_info->call_state & (srv_ucm_bt_call_state_enum)(SRV_UCM_BT_INCOMING_STATE | SRV_UCM_BT_HOLD_STATE))
        {
            // Release all held calls or sets User Determined User Busy(UDUB) for a waiting call
            cmd = MMI_TRUE;
            srv_bt_dialer_release_all_held_calls(call_info->srv_hd);
        }
        else if (call_info->call_state & SRV_UCM_BT_ACTIVE_STATE)
        {
            /** Releases all active calls (if any exist) and accepts the other
                        *  (held or waiting) call. If "call" is specified, will release the
                        *  specific call.
                        */
            // follow BTD v2.3
            cmd = MMI_TRUE;
            srv_bt_dialer_release_all_active_calls(call_info->srv_hd, (S8)-1);
            // release special call
            // maybe have IOT issue. because some SP don't support AT+CHLD=2x
            // srv_bt_dialer_release_all_active_calls(call_info->srv_hd, call_info->call_idx);
        }
        else
        {
            // undefine action
        }
    }
    if (cmd)
    {
        srv_ucm_bt_set_pending_action(req->srv_hd, SRV_UCM_BT_END_SINGLE_ACT);
    }
}

void srv_ucm_bt_end_all_action (void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_all_act_req_struct* req = (srv_ucm_bt_end_all_act_req_struct*)act_data;
    S32 call_count;
    srv_ucm_bt_call_info_struct* call_info;
    MMI_BOOL cmd = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    // end all connected calls to accept the call of another device
    call_count = srv_ucm_bt_query_call_count_ext(req->srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL);

    if (call_count > 1)
    {
        if (srv_ucm_bt_query_call_count_ext(req->srv_hd,(srv_ucm_bt_call_state_enum)(SRV_UCM_BT_INCOMING_STATE|SRV_UCM_BT_HOLD_STATE), NULL) > 0)
        {
            call_info = srv_ucm_bt_get_call_info(req->srv_hd, SRV_UCM_BT_CALL_BY_STATE, SRV_UCM_BT_ACTIVE_STATE);
            if (call_info != NULL)
            {
                g_ucm_bt_srv_p->comp_action = MMI_TRUE;

                call_info->proc_act = SRV_UCM_BT_END_ALL_ACT;
                call_info->action_data = OslMalloc(sizeof(srv_ucm_bt_end_all_act_req_struct));
                memcpy(call_info->action_data, req, sizeof(srv_ucm_bt_end_all_act_req_struct));
            }
            cmd = MMI_TRUE;
            srv_bt_dialer_release_all_held_calls(req->srv_hd);
        }
        else
        {
            MMI_ASSERT(0);
        }
    }
    else if (call_count == 1)
    {
        cmd = MMI_TRUE;
        srv_bt_dialer_hangup_current_call(req->srv_hd);
    }

    if (cmd)
    {
        srv_ucm_bt_set_pending_action(req->srv_hd, SRV_UCM_BT_END_ALL_ACT);
    }
}

void srv_ucm_bt_send_dtmf_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_dtmf_act_req_struct* req = (srv_ucm_bt_dtmf_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_bt_dialer_send_generate_dtmf_tone_req(req->srv_hd, req->digit);
}

void srv_ucm_bt_force_refresh_action(void* act_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_force_refresh_act_req_struct* req = (srv_ucm_bt_force_refresh_act_req_struct*)act_data;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);
    srv_ucm_bt_set_pending_action(req->srv_hd, SRV_UCM_BT_FORCE_REFRESH_ACT);
    if (srv_bt_dialer_list_current_calls(req->srv_hd))
    {
        srv_ucm_bt_call_dev_info_struct* dev_info;

        dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &req->srv_hd);
        memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));
    }
}

void srv_ucm_bt_switch_audio_path_action(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_switch_audio_act_req_struct* req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_ucm_bt_switch_audio_act_req_struct*)ptr;

    MMI_ASSERT(req);

    srv_bt_dialer_switch_audio_path_bt(req->srv_hd);
}


#ifdef __BT_SPK_VOL_CONTROL__
void srv_ucm_bt_set_vgs_action(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_vgs_req_struct* req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_ucm_bt_vgs_req_struct*)ptr;

    MMI_ASSERT(req);

    srv_bt_dialer_speaker_vol_gain_req(req->srv_hd, req->gain);
}
#endif /* __BT_SPK_VOL_CONTROL__ */

#ifdef __MMI_HF_BAT_SUPPORT__
static U8 srv_ucm_bt_bat_mapping(srv_charbat_battery_level_enum cur_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                               */
    /*----------------------------------------------------------------*/
    U8 iphone_level;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (cur_level)
    {
        case BATTERY_LOW_POWEROFF:      /* pass */
        case BATTERY_LOW_TX_PROHIBIT:   /* pass */
        case BATTERY_LOW_WARNING:       /* pass */
        case BATTERY_LEVEL_0:
            iphone_level = 0;
            break;

        case BATTERY_LEVEL_1:   /* pass */
            iphone_level = 3;
            break;

        case BATTERY_LEVEL_2:   /* pass */
            iphone_level = 6;
            break;

        case BATTERY_LEVEL_3:   /* pass */
            iphone_level = 9;
            break;

        default:
            iphone_level = 4;
            break;
    }
    return iphone_level;
}

void srv_ucm_bt_bat_report_action(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_bat_report_act_req_struct* req;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req = (srv_ucm_bt_bat_report_act_req_struct*)ptr;

    MMI_ASSERT(req);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&req->srv_hd);

    if (dev_info)
    {
        dev_info->cur_level = srv_ucm_bt_bat_mapping((srv_charbat_battery_level_enum)req->value);
        srv_bt_dialer_battery_report_req(req->srv_hd, dev_info->cur_level);
    }
}
#endif /* __MMI_HF_BAT_SUPPORT__ */

srv_ucm_bt_result_enum srv_ucm_bt_dial_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_atd_act_req_struct* act_req = (srv_ucm_bt_atd_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(act_req);

    if (srv_ucm_bt_is_pending_action(act_req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }
    else if (srv_ucm_is_any_call())
    {
        result = SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    else if (srv_ucm_bt_device_is_any_call(act_req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    else if (mmi_ucs2strlen((CHAR*)act_req->num_uri) == 0)
    {
        result = SRV_UCM_BT_RESULT_EMPTY_NUM;
    }
    else if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, NULL) > 0)
    {
        result = SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    else if (!srv_ucm_bt_is_valid_service_hd(act_req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_NO_DEV;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_accept_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_ata_act_req_struct* req = (srv_ucm_bt_ata_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }

    if (srv_ucm_bt_query_call_count_ext(req->srv_hd, SRV_UCM_BT_INCOMING_STATE, NULL) == 0)
    {
        result =  SRV_UCM_BT_RESULT_NO_CALL_TO_ACCEPT;
    }
    return result;

}

srv_ucm_bt_result_enum srv_ucm_bt_hold_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* req = (srv_ucm_bt_chld_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->act_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }

    if (srv_ucm_bt_query_call_count_ext(req->act_hd, SRV_UCM_BT_ACTIVE_STATE, NULL) == 0)
    {
        result =  SRV_UCM_BT_RESULT_NO_CALL_TO_HOLD;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_retrieve_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* req = (srv_ucm_bt_chld_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->hold_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }

    if (srv_ucm_bt_query_call_count_ext(req->hold_hd, SRV_UCM_BT_HOLD_STATE, NULL) == 0)
    {
        result =  SRV_UCM_BT_RESULT_NO_CALL_TO_RETRIEVE;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_swap_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_chld_act_req_struct* req = (srv_ucm_bt_chld_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->act_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }
    else if (srv_ucm_bt_query_call_count_ext(req->act_hd, SRV_UCM_BT_ACTIVE_STATE, NULL) == 0
          || srv_ucm_bt_query_call_count_ext(req->hold_hd, SRV_UCM_BT_HOLD_STATE, NULL) == 0)
    {
        result = SRV_UCM_BT_RESULT_NO_CALL_TO_SWAP;
    }
    else if (srv_ucm_bt_get_call_info(req->act_hd,SRV_UCM_BT_CALL_BY_CALL_ID, req->active_id) == NULL
          || srv_ucm_bt_get_call_info(req->hold_hd,SRV_UCM_BT_CALL_BY_CALL_ID, req->hold_id) == NULL)
    {
        result = SRV_UCM_BT_RESULT_INVALID_CALL_ID;
    }
    return result;

}

srv_ucm_bt_result_enum srv_ucm_bt_end_single_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_single_act_req_struct* req = (srv_ucm_bt_end_single_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }
    else if (srv_ucm_bt_get_call_info(req->srv_hd, SRV_UCM_BT_CALL_BY_CALL_ID, req->call_id) == NULL)
    {
        result =  SRV_UCM_BT_RESULT_NO_CALL_TO_END;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_end_all_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_all_act_req_struct* req = (srv_ucm_bt_end_all_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    if (srv_ucm_bt_is_pending_action(req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }
    else if (srv_ucm_bt_query_call_count_ext(req->srv_hd, SRV_UCM_BT_CALL_STATE_ALL, NULL) == 0)
    {
        result =  SRV_UCM_BT_RESULT_NO_CALL_TO_END;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_new_dev_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_dev_act_req_struct* req = (srv_ucm_bt_dev_act_req_struct*)ptr;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_ADDR, &req->dev_addr);

    if (dev_info)
    {
        result = SRV_UCM_BT_RESULT_DEVICE_EXIST;
    }
    else if (SRV_UCM_BT_MAX_DEV == g_ucm_bt_srv_p->dev_count)
    {
        result = SRV_UCM_BT_RESULT_DEVICE_LIST_IS_FULL;
    }
    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_delete_dev_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_dev_act_req_struct* req = (srv_ucm_bt_dev_act_req_struct*)ptr;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_result_enum result = SRV_UCM_BT_RESULT_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_ADDR, &req->dev_addr);

    if (dev_info == NULL)
    {
        result = SRV_UCM_BT_RESULT_NO_DEV;
    }

    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_force_refresh_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_force_refresh_act_req_struct* req = (srv_ucm_bt_force_refresh_act_req_struct*)ptr;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&req->srv_hd);

    if (dev_info == NULL)
    {
        result = SRV_UCM_BT_RESULT_NO_DEV;
    }
    else if (dev_info->call_count > 0)
    {
        result = SRV_UCM_BT_RESULT_OK;
    }
    else
    {
        result = SRV_UCM_BT_RESULT_UNSPECIFIED_ERROR;
    }

    return result;
}

srv_ucm_bt_result_enum srv_ucm_bt_send_dtmf_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_dtmf_act_req_struct* req = (srv_ucm_bt_dtmf_act_req_struct*)ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);
    if ((req->digit == (U8)'*') || (req->digit == (U8)'#')
        || ((req->digit >= (U8)'0') && (req->digit <= (U8)'9')))
    {
        return SRV_UCM_BT_RESULT_OK;
    }
    else
    {
        return SRV_UCM_BT_RESULT_INVALID_NUM;
    }
}


#ifdef __MMI_HF_BAT_SUPPORT__
srv_ucm_bt_result_enum srv_ucm_bt_bat_report_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_bat_report_act_req_struct* req = (srv_ucm_bt_bat_report_act_req_struct*)ptr;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req);

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&req->srv_hd);

    MMI_ASSERT(dev_info);

    if (!(dev_info->custom_features & SRV_BT_DIALER_XAPL_BAT))
    {
        result = SRV_UCM_BT_RESULT_FEATURE_DONT_SUPPORT;
    }
    else if (!req->force && dev_info->cur_level == srv_ucm_bt_bat_mapping((srv_charbat_battery_level_enum)req->value))
    {
        result = SRV_UCM_BT_RESULT_UNSPECIFIED_ERROR;
    }
    else
    {
        result = SRV_UCM_BT_RESULT_OK;
    }
    return result;
}
#endif /* __MMI_HF_BAT_SUPPORT__ */


#ifdef __BT_HF_BVRA_SUPPORT__
srv_ucm_bt_result_enum srv_ucm_bt_bvra_prmt(void* ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_bvra_act_req_struct* req = (srv_ucm_bt_bvra_act_req_struct*)ptr;
    srv_ucm_bt_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_is_pending_action(req->srv_hd))
    {
        result = SRV_UCM_BT_RESULT_UCM_BUSY;
    }
    else if (srv_ucm_bt_is_any_call())
    {
        result = SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_DIAL;
    }
    else
    {
        result = SRV_UCM_BT_RESULT_OK;
    }
    return result;
}
#endif /* __BT_HF_BVRA_SUPPORT__ */


srv_ucm_bt_result_enum srv_ucm_bt_setup_new_call_prmt(srv_ucm_bt_call_dev_info_struct* cur_dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(cur_dev);

    if (g_ucm_bt_srv_p->dev_count == 1)
    {
        return SRV_UCM_BT_RESULT_OK;
    }
    else if (g_ucm_bt_srv_p->dev_count > 1)
    {
        srv_ucm_bt_call_dev_info_struct* dev_info;
        for (dev_info = &g_ucm_bt_srv_p->dev_info[0]; dev_info < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_info++)
        {
            if (dev_info != cur_dev 
                && dev_info->ciev_ind.setup > SRV_BT_DIALER_CALL_SETUP_COMPLETE
                && cur_dev->ciev_ind.setup > SRV_BT_DIALER_CALL_SETUP_COMPLETE
                && cur_dev->ciev_ind.call == 0 && cur_dev->ciev_ind.held == 0)
            {
                return SRV_UCM_BT_RESULT_NOT_ALLOWED_TO_SETUP;
            }
        }
    }
    else
    {
        MMI_ASSERT(0);
    }
    return SRV_UCM_BT_RESULT_OK;
}

U32 srv_ucm_bt_query_connected_dev_count(S32* srv_hd_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, count;

    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    if(srv_hd_list)
    {
        memset(srv_hd_list, -1, SRV_UCM_BT_MAX_DEV);
    }

    for (i = 0, count = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        if (g_ucm_bt_srv_p->dev_info[i].alloced 
         && srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_HF_CONNECTION, &g_ucm_bt_srv_p->dev_info[i].dev_addr))
        {
            if (srv_hd_list)
            {
                srv_hd_list[count] = g_ucm_bt_srv_p->dev_info[i].srv_hd;
            }
            count++;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_QRY_DEV_CNT, count);
    return count;
}

MMI_BOOL srv_ucm_bt_query_connected_dev_info(S32 srv_hd, srv_ucm_bt_dev_info_struct* dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        if (g_ucm_bt_srv_p->dev_info[i].alloced && g_ucm_bt_srv_p->dev_info[i].srv_hd == srv_hd)
        {
            if (dev_info)
            {
                dev_info->srv_hd = srv_hd;
                memcpy(dev_info->dev_name, g_ucm_bt_srv_p->dev_info[i].dev_name, ENCODING_LENGTH*SRV_BT_CM_BD_UCS2_NAME_LEN);
                memcpy(&dev_info->dev_addr, &g_ucm_bt_srv_p->dev_info[i].dev_addr, sizeof(srv_bt_cm_bt_addr));
            }
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

S32 srv_ucm_bt_query_service_hd(srv_bt_cm_bt_addr* bt_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(bt_addr);

    for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        if (g_ucm_bt_srv_p->dev_info[i].dev_addr.lap == bt_addr->lap
         && g_ucm_bt_srv_p->dev_info[i].dev_addr.nap == bt_addr->nap
         && g_ucm_bt_srv_p->dev_info[i].dev_addr.uap == bt_addr->uap
         && g_ucm_bt_srv_p->dev_info[i].alloced)
        {
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_QUERY_HD, g_ucm_bt_srv_p->dev_info[i].srv_hd);
            return g_ucm_bt_srv_p->dev_info[i].srv_hd;
        }
    }
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_QUERY_HD, -1);
    return -1;
}

S32 srv_ucm_bt_query_call_count(srv_ucm_bt_call_state_enum call_state, S32* call_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, call_count;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (call_list != NULL)
    {
        memset(call_list, 0, sizeof(S32)*SRV_UCM_BT_ALL_DEV_MAX_CALL);
    }

    for (dev_info = &g_ucm_bt_srv_p->dev_info[0], call_count = 0; dev_info < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_info++)
    {
        if (dev_info->call_count == 0)
        {
            continue;
        }

        for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
        {
            if (call_state & dev_info->call_info[i].call_state)
            {
                if (call_list)
                {
                    call_list[call_count] = dev_info->call_info[i].call_id;
                }
                call_count++;
            }
        }
    }
    return call_count;
}

S32 srv_ucm_bt_query_call_count_ext(S32 srv_hd, srv_ucm_bt_call_state_enum call_state, S32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, call_count;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    if (index != NULL)
    {
        memset(index, 0, sizeof(S32)*SRV_UCM_BT_MAX_CALL);
    }
    for (i = 0, call_count = 0; i < SRV_UCM_BT_MAX_CALL; i++)
    {
        if (call_state & dev_info->call_info[i].call_state)
        {
            if (index != NULL)
            {
                index[call_count] = dev_info->call_info[i].call_id;
            }
            call_count++;
        }
    }
    return call_count;
}

S32 srv_ucm_bt_query_group_count(srv_ucm_bt_call_state_enum call_state, S32* group_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, dev_idx, call_count = 0;
    MMI_BOOL is_multi = MMI_FALSE;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (group_list != NULL)
    {
        memset(group_list, 0, sizeof(S32)*SRV_UCM_BT_ALL_DEV_MAX_GROUP);
    }

    for (dev_idx = 0; dev_idx < SRV_UCM_BT_MAX_DEV; dev_idx++)
    {
        dev_info = &g_ucm_bt_srv_p->dev_info[dev_idx];

        if (dev_info->call_count == 0)
        {
            continue;
        }
    
        for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
        {
            if (call_state & dev_info->call_info[i].call_state)
            {
                if(dev_info->call_info[i].multiParty)
                {
                    if (is_multi)
                    {
                        continue;
                    }
                    is_multi = MMI_TRUE;
                }
                if (group_list)
                {
                    group_list[call_count] = dev_info->call_info[i].call_id;
                }
                call_count++;
            }
        }
    }
    return call_count;
}

S32 srv_ucm_bt_query_group_count_ext(S32 srv_hd, srv_ucm_bt_call_state_enum call_state, S32* index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, call_count;
    MMI_BOOL is_multi = MMI_FALSE;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, (void*)&srv_hd);

    MMI_ASSERT(dev_info);

    if (index != NULL)
    {
        memset(index, 0, sizeof(S32)*SRV_UCM_BT_MAX_GROUP);
    }

    for (i = 0, call_count = 0; i < SRV_UCM_BT_MAX_CALL; i++)
    {
        if (call_state & dev_info->call_info[i].call_state)
        {
            if(dev_info->call_info[i].multiParty)
            {
                if (is_multi)
                {
                    continue;
                }
                is_multi = MMI_TRUE;
            }
            if (index != NULL && call_count < SRV_UCM_BT_MAX_GROUP)
            {
                index[call_count] = dev_info->call_info[i].call_id;
            }
            call_count++;
        }
    }
    return call_count;
}

MMI_BOOL srv_ucm_bt_query_call_data(U32 call_id, srv_ucm_bt_call_info_struct* call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 dev_idx;
    U32 i;
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(call_info);

    if (call_id == 0)
    {
        return MMI_FALSE;
    }

    memset(call_info, 0, sizeof(srv_ucm_bt_call_info_struct));

    for (dev_idx = 0; dev_idx < SRV_UCM_BT_MAX_DEV; dev_idx++)
    {
        dev_info = &g_ucm_bt_srv_p->dev_info[dev_idx];
    
        for (i = 0; i < SRV_UCM_BT_MAX_CALL; i++)
        {
            if (call_id == dev_info->call_info[i].call_id)
            {
                call_info->call_id = dev_info->call_info[i].call_id;
                call_info->call_idx= dev_info->call_info[i].call_idx;
                call_info->dir = dev_info->call_info[i].dir;
                call_info->mode = dev_info->call_info[i].mode;
                call_info->multiParty = dev_info->call_info[i].multiParty;
                call_info->call_state = dev_info->call_info[i].call_state;
                call_info->srv_hd = dev_info->call_info[i].srv_hd;
                memcpy(call_info->num_uri, dev_info->call_info[i].num_uri, sizeof(call_info->num_uri));
                memcpy(call_info->dis_name, dev_info->call_info[i].dis_name, sizeof(call_info->dis_name));
                memcpy(&call_info->start_time, &dev_info->call_info[i].start_time, sizeof(MYTIME));
                return MMI_TRUE;
            }
        }
    }
    return MMI_FALSE;
}

MMI_BOOL srv_ucm_bt_is_any_call(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_IS_ANY_CALL,
                  g_ucm_bt_srv_p->dev_info[i].ciev_ind.setup,
                  g_ucm_bt_srv_p->dev_info[i].ciev_ind.call,
                  g_ucm_bt_srv_p->dev_info[i].ciev_ind.held);
        if (g_ucm_bt_srv_p->dev_info[i].ciev_ind.setup != SRV_BT_DIALER_CALL_SETUP_COMPLETE
            || g_ucm_bt_srv_p->dev_info[i].ciev_ind.call != SRV_BT_DIALER_CALL_NOT_ACTIVE
            || g_ucm_bt_srv_p->dev_info[i].ciev_ind.held != SRV_BT_DIALER_NO_CALL_HELD)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}

MMI_BOOL srv_ucm_bt_is_valid_service_hd(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
    {
        if (g_ucm_bt_srv_p->dev_info[i].alloced && g_ucm_bt_srv_p->dev_info[i].srv_hd == srv_hd)
        {
            return MMI_TRUE;
        }
    }
    return MMI_FALSE;
}


MMI_BOOL srv_ucm_bt_set_pending_action(S32 srv_hd, srv_ucm_bt_act_opcode_enum op)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!srv_ucm_bt_is_pending_action(srv_hd) && !g_ucm_bt_srv_p->comp_action)
    {
        dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);
        MMI_ASSERT(dev_info);
        dev_info->pending_action = op;
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

void srv_ucm_bt_reset_pending_action(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);
    MMI_ASSERT(dev_info);
    dev_info->pending_action = SRV_UCM_BT_NO_ACT;
}

void srv_ucm_bt_next_comp_action(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_call_info_struct* call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_NEXT_COMP_ACT);
    for (dev_info = &g_ucm_bt_srv_p->dev_info[0]; dev_info < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_info++)
    {
        for (call_info = &dev_info->call_info[0]; call_info < &dev_info->call_info[SRV_UCM_BT_MAX_CALL]; call_info++)
        {
            if (call_info->proc_act != SRV_UCM_BT_NO_ACT)
            {
                MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_COMP_DETL_ACT, call_info->proc_act, call_info->srv_hd);
                srv_ucm_bt_act_request(call_info->proc_act, call_info->action_data);
            }
        }
    }
}

void srv_ucm_bt_abort_compound_action(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_call_info_struct* call_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD,(void*)&srv_hd);

    MMI_ASSERT(dev_info);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_ABORT_COMP_ACT, srv_hd);

    for (call_info = &dev_info->call_info[0]; call_info < &dev_info->call_info[SRV_UCM_BT_MAX_CALL]; call_info++)
    {
        if (call_info->action_data)
        {
            g_ucm_bt_srv_p->comp_action = MMI_FALSE;
            call_info->proc_act = SRV_UCM_BT_NO_ACT;
            OslMfree(call_info->action_data);
        }
    }
}

void srv_ucm_bt_check_compound_action(S32 srv_hd, srv_ucm_bt_act_opcode_enum opcode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_end_all_act_req_struct end_all;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(opcode)
    {
        case SRV_UCM_BT_END_ALL_ACT:
            end_all.srv_hd = srv_hd;
            srv_ucm_bt_end_all_action(&end_all);
            break;

        default:
            break;
    }
}

srv_ucm_bt_act_opcode_enum srv_ucm_bt_get_pending_action(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);

    MMI_ASSERT(dev_info);

    return dev_info->pending_action;
}

void srv_ucm_bt_conf_refresh_handler(void* arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 srv_hd;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_hd = *((S32*)arg);
    if (srv_ucm_bt_is_valid_service_hd(srv_hd)
    && (srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_ACTIVE_STATE, NULL) > 1
    ||  srv_ucm_bt_query_call_count_ext(srv_hd, SRV_UCM_BT_HOLD_STATE, NULL) > 1))
    {
        if (srv_bt_dialer_list_current_calls(srv_hd))
        {
            srv_ucm_bt_call_dev_info_struct* dev_info;

            dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);
            memset(dev_info->call_temp_list, 0, SRV_UCM_BT_MAX_CALL*sizeof(srv_ucm_bt_call_list_struct));
        }
        StartTimerEx(UCM_CONF_REFRESH_TIMER_ID, SRV_UCM_BT_CONF_REF_TIME, srv_ucm_bt_conf_refresh_handler, arg);
    }
}
MMI_BOOL srv_ucm_bt_is_conference_call(U32* count, S32* srv_hd_list)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    srv_ucm_bt_call_info_struct* call_info;
    U32 conf_count = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_hd_list != NULL)
    {
        memset(srv_hd_list, 0, sizeof(S32)*SRV_UCM_BT_MAX_DEV);
    }
    for (dev_info = &g_ucm_bt_srv_p->dev_info[0]; dev_info < &g_ucm_bt_srv_p->dev_info[SRV_UCM_BT_MAX_DEV]; dev_info++)
    {
        if (dev_info->call_count == 0)
        {
            continue;
        }

        for (call_info = &dev_info->call_info[0]; call_info < &dev_info->call_info[SRV_UCM_BT_MAX_CALL]; call_info++)
        {
            if (call_info->multiParty)
            {
                if (srv_hd_list != NULL)
                {
                    srv_hd_list[conf_count] = call_info->srv_hd;
                }
                conf_count++;
                break;
            }
        }
    }

    if (count != NULL)
    {
        *count = conf_count;
    }

    if (conf_count > 0)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}
MMI_BOOL srv_ucm_bt_is_pending_action(S32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_bt_call_dev_info_struct* dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &srv_hd);
    MMI_ASSERT(dev_info);
    if (dev_info->pending_action > SRV_UCM_BT_NO_ACT
     && dev_info->pending_action < SRV_UCM_BT_SEND_DTMF_ACT)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_PENDING_ACT, dev_info->pending_action);
        return MMI_TRUE;
    }
    return MMI_FALSE;
}

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__BT_PBAP_CLIENT__)
MMI_BOOL srv_ucm_bt_get_remote_name(srv_ucm_bt_call_info_struct* call_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 bt_index;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    U16 dis_name[SRV_UCM_BT_MAX_NUM_URI_LEN + 1];
    MMI_BOOL result;
    U8 name[SRV_UCM_BT_MAX_NUM_URI_LEN+1];
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(call_info);
    dev_info = srv_ucm_bt_get_dev_info(SRV_UCM_BT_DEV_BY_SRV_HD, &call_info->srv_hd);

    if (dev_info == NULL)
    {
        return MMI_FALSE;
    }

    bt_index = srv_phb_pbapc_get_btd_index(&dev_info->dev_addr, SRV_PBAPC_FLAG_CONNECTED);

    memset(name, 0, sizeof(name));

    if (bt_index >= 0 
        && srv_phb_pbapc_get_name_by_number((srv_phb_pbapc_btd_enum)bt_index, call_info->dis_name, dis_name, SRV_UCM_BT_MAX_NUM_URI_LEN)
        && mmi_ucs2strlen((CHAR*)dis_name) > 0)
    {
        memcpy(call_info->dis_name, dis_name, sizeof(call_info->dis_name));
        mmi_ucs2_to_asc((CHAR*)name, (CHAR*)dis_name);
        result =  MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }
    kal_wap_trace(MOD_MMI_COMMON_APP,TRACE_GROUP_5,"[UcmBTSrv] get remote name:%s, result:%d", name, result); 
    return result;
}
#endif /* __MMI_PHB_PBAPC_SYNC_CONTACT__ */

mmi_ret srv_ucm_bt_on_time_change_event(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_datetimie_evt_struct* datetime_evt;
    S32 ret;
    MYTIME diff_time;
    S32 i, j;
    srv_ucm_bt_call_dev_info_struct* dev_info;
    S32 srv_hd = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL) > 0)
    {
        datetime_evt = (srv_datetimie_evt_struct*)evt;
        ret = CompareTime(datetime_evt->old_time, datetime_evt->new_time, NULL);

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_TIME_CHANGE_HDLR,'o','l','d',
                                             datetime_evt->old_time.nYear,
                                             datetime_evt->old_time.nMonth,
                                             datetime_evt->old_time.nDay,
                                             datetime_evt->old_time.nHour,
                                             datetime_evt->old_time.nMin,
                                             datetime_evt->old_time.nSec,
                                             datetime_evt->old_time.DayIndex);

        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_UCM_BT_TIME_CHANGE_HDLR, 'n','e','w',
                                             datetime_evt->new_time.nYear,
                                             datetime_evt->new_time.nMonth,
                                             datetime_evt->new_time.nDay,
                                             datetime_evt->new_time.nHour,
                                             datetime_evt->new_time.nMin,
                                             datetime_evt->new_time.nSec,
                                             datetime_evt->new_time.DayIndex);
        if (ret == DT_TIME_EQUAL)
        {
            return MMI_RET_OK;
        }

        for (i = 0; i < SRV_UCM_BT_MAX_DEV; i++)
        {
            dev_info = &g_ucm_bt_srv_p->dev_info[i];

            for (j = 0; j < SRV_UCM_BT_MAX_CALL; j++)
            {

                if (dev_info->call_info[j].call_id == 0 
                    || dev_info->call_info[j].call_state & SRV_UCM_BT_CALL_STATE_MOMT)
                {
                    continue;
                }

                if (ret == DT_TIME_LESS)
                {
                    GetTimeDifference(&datetime_evt->new_time, &datetime_evt->old_time, &diff_time);

                    IncrementTime(dev_info->call_info[j].start_time,
                                  diff_time,
                                  &dev_info->call_info[j].start_time);
                    srv_hd = dev_info->srv_hd;
                }
                else if (ret == DT_TIME_GREATER)
                {
                    GetTimeDifference(&datetime_evt->old_time, &datetime_evt->new_time, &diff_time);

                    DecrementTime(dev_info->call_info[j].start_time,
                                  diff_time,
                                  &dev_info->call_info[j].start_time);
                    srv_hd = dev_info->srv_hd;
                }
                if (srv_hd != 0)
                {
                    srv_ucm_bt_sys_time_change_ind(srv_hd);
                    srv_hd = 0;
                }
            }
        }
    }
    return MMI_RET_OK;
}


void srv_ucm_bt_mre_notify_callback(U32 evt, void *para)
{

    if (SRV_UCM_BT_NOTI_EVT_IND & evt)
    {
        srv_ucm_bt_ind_evt_struct* ind = (srv_ucm_bt_ind_evt_struct*)para;
    }
    else if (SRV_UCM_BT_NOTI_EVT_ACT & evt)
    {
        srv_ucm_bt_act_notify_evt_struct* act = (srv_ucm_bt_act_notify_evt_struct*)para;
    }
}


U8 srv_ucm_bt_proc_inject_string(U8 index, kal_uint8* string)
{
#ifdef __UCM_BT_UT_TEST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 call_count;
    S32 call_index[SRV_UCM_BT_ALL_DEV_MAX_CALL];
    srv_ucm_bt_atd_act_req_struct dial_req;
    srv_ucm_bt_ata_act_req_struct ata;
    srv_ucm_bt_end_single_act_req_struct chup;
    srv_ucm_bt_dtmf_act_req_struct vts;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (strcmp((char*)string, "BTD_atd") == 0)   // Enable PortA as 115200
    {
        U8 num[SRV_UCM_BT_MAX_NUM_URI_LEN+1] = "10086";

        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv] ATD");

        memset(&dial_req, 0, sizeof(srv_ucm_bt_atd_act_req_struct));
        dial_req.srv_hd = srv_ucm_ut_handler;
        mmi_asc_to_ucs2((CHAR*)dial_req.num_uri, (CHAR*)num);
        srv_ucm_bt_act_request(SRV_UCM_BT_DIAL_ACT, &dial_req);
        return 1;                                                        
    }
    else if (strcmp((char*)string, "BTD_ata") == 0)
    {
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv] ATA");
        call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_INCOMING_STATE, call_index);
        if (call_count > 0)
        {
            ata.srv_hd = srv_ucm_ut_handler;
            ata.call_id = call_index[0];
            srv_ucm_bt_act_request(SRV_UCM_BT_ACCEPT_ACT, &ata);
        }
        return 1;                                                        
    }
    if (strcmp((char*)string, "BTD_chup") == 0)
    {
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv] AT+CHUP");
        call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_ALL, call_index);
        if (call_count == 1)
        {
            chup.srv_hd = srv_ucm_ut_handler;
            chup.call_id = call_index[0];
            srv_ucm_bt_act_request(SRV_UCM_BT_END_SINGLE_ACT, &chup);
        }
        return 1;                                                        
    }
    if (strcmp((char*)string, "BTD_vts") == 0)
    {
        kal_wap_trace(MOD_MMI_CONN_APP,TRACE_GROUP_7,"[BTDialerSrv] AT+VTS");
        call_count = srv_ucm_bt_query_call_count(SRV_UCM_BT_CALL_STATE_CONNECTED, NULL);
        if (call_count > 0)
        {
            vts.srv_hd = srv_ucm_ut_handler;
            vts.digit = index;
            srv_ucm_bt_act_request(SRV_UCM_BT_SEND_DTMF_ACT, &vts);
        }
        return 1;                                                        
    }
    else if (strcmp((char*)string, "BTD_reg") == 0)
    {
        S32 reg_id;
        reg_id = srv_ucm_bt_register_notify_callback(
                      srv_ucm_bt_mre_notify_callback,
                      SRV_UCM_BT_NOTI_EVT_IND|SRV_UCM_BT_NOTI_EVT_ACT,
                      NULL);
        if (reg_id > 0)
        {
            srv_ucm_ut_noti_hd = reg_id;
        }
        return 1;                                                        
    }
    else if (strcmp((char*)string, "BTD_dereg") == 0)
    {
        srv_ucm_bt_deregister_notify_callback(srv_ucm_ut_noti_hd);
        return 1;
    }
    #ifdef __MMI_HF_BAT_SUPPORT__
    else if (strcmp((char*)string, "BTD_bat") == 0)
    {
        srv_ucm_bt_bat_report_act_req_struct bat_req;
        S32 srv_hd_list[SRV_UCM_BT_MAX_DEV];

        if (srv_ucm_bt_query_connected_dev_count(srv_hd_list) > 0)
        {
            bat_req.srv_hd = srv_hd_list[0];
            bat_req.value = index;
            bat_req.force = MMI_FALSE;

            srv_ucm_bt_act_request(SRV_UCM_BT_BAT_REPORT_ACT, &bat_req);            
        }
        return 1;
    }
    #endif
#endif
    return 0;
}
#else
S32 srv_ucm_bt_query_call_count(srv_ucm_bt_call_state_enum call_state, S32* call_list)
{
    return 0;
}
#endif /* __MMI_HF_SUPPORT__ */
