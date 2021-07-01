#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "OneKeySosSrv.h"
#include "OneKeySosSrvGprot.h"
#include "DebugInitDef_Int.h"

#include "mmi_frm_mem_gprot.h" // OslMalloc
#include "mmi_frm_events_gprot.h" // MMI_FRM_INIT_EVENT
#include "mmi_cb_mgr_gprot.h" // MMI_FRM_CB_EMIT_POST_EVENT_EX

#include "Conversions.h"  // for mmi_chset_utf8_to_ucs2_string
#include "App_datetime.h"
#include "nvram_common_defs.h" // for NVRAM_EF_OKSOS_INFO_LID
#include "mmi_frm_nvram_gprot.h" // NVRAM_WRITE_SUCCESS
#include "MMI_common_app_trc.h" // MMI_COMMON_TRC_G5_CALL
#include "UcmSrvGprot.h" // srv_ucm_dial_act_req_struct
#include "Unicodexdcl.h" // mmi_ucs2ncmp
#include "mmi_rp_srv_oksos_def.h"
#include "BTNotiSrvGprot.h" // srv_bt_noti_connect_status_change_notify_struct
#include "Mmi_frm_timer_gprot.h" // StartTimerEx
#include "mmi_frm_utility_gprot.h" // MMI_SIM_TOTAL
#include "SsSrvGprot.h" // srv_ss_is_valid_ss_string

static srv_oksos_cntx_struct g_srv_oksos_cntx;
srv_oksos_cntx_struct* g_srv_oksos_p = &g_srv_oksos_cntx;

/* For UT test, add AT entry */
//#define __OKSOS_UT_TEST__

/* For UT Test, make the BT condition okay */
// #define __OKSOS_UT_CONDITION_OK__

/* For internal ECC number which can't be changed by user */
#ifdef __MMI_OKSOS_INTERNAL_ECC__
const U8 OKSOS_SP_KEY_VALUE = 0x99;
const U8 OKSOS_SP_TIMES = 3;
const char* g_srv_oksos_internal_ecc[] = 
{
    "112",
    "911",
    "110",
    "119",
    "120",
    "122"
};
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */

#define OKSOS_IsValidDevice(addr) \
            ((addr != NULL) && \
            ((addr)->lap != 0 || (addr)->nap != 0 || (addr)->uap != 0))

#define OKSOS_IsSameDevice(saddr, daddr) \
            ((saddr != NULL) && (daddr != NULL) && \
            ((saddr)->lap == (daddr)->lap && (saddr)->nap == (daddr)->nap && (saddr)->uap == (daddr)->uap))

static void _oksos_request_exec_done(srv_oksos_result_enum result, srv_oksos_node_struct* req);

/*****************************************************************************
 * FUNCTION
 *  _oksos_node_insert_head
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_node_insert_head(srv_oksos_node_struct* head, srv_oksos_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(head && node);
    node->next = head->next;
    node->prev = head;
    head->next->prev = node;
    head->next = node;
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_node_del
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_node_del(srv_oksos_node_struct* del_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (del_req)
    {
        if (del_req->req_para)
        {
            OslMfree(del_req->req_para);
        }
        OslMfree(del_req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_node_insert_tail
 * DESCRIPTION
 *  
 * PARAMETERS
 * 
 * RETURNS
 *
 *****************************************************************************/
static void _oksos_node_insert_tail(srv_oksos_node_struct* head, srv_oksos_node_struct* node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_ASSERT(head && node);
    node->next = head;
    node->prev = head->prev;
    head->prev->next = node;
    head->prev = node;
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_node_remove_node
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_node_remove_node(srv_oksos_node_struct *node)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(node);
    node->prev->next = node->next;
    node->next->prev = node->prev;
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_node_delete_by_type
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_node_delete_by_type(srv_oksos_node_struct* head, srv_oksos_req_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_node_struct* cur_node = head->next;
    srv_oksos_node_struct* del_node = NULL;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while(cur_node != head)
    {
        if (cur_node && cur_node->req_para && (type == cur_node->req_para->type || type == SRV_OKSOS_REQ_TYPE_NONE))
        {
            del_node = cur_node;
        }

        cur_node = cur_node->next;

        if (del_node != NULL)
        {
            _oksos_node_remove_node(del_node);
            _oksos_node_del(del_node);
            del_node = NULL;
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_node_get_next
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_node_struct* _oksos_node_get_next(srv_oksos_req_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_node_struct* cur_req = g_srv_oksos_p->req_list.next;
    srv_oksos_node_struct* result = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    while (cur_req != &g_srv_oksos_p->req_list)
    {
        if (type == cur_req->req_para->type || type == SRV_OKSOS_REQ_TYPE_NONE)
        {
            result = cur_req;
            cur_req->next->prev = cur_req->prev;
            cur_req->prev->next = cur_req->next;
            result->next = result;
            result->prev = result;
            break;
        }
        cur_req = cur_req->next;
    }

     SRV_OKSOS_LOG1(TRC_SRV_OKSOS_GET_NEXT_NOD, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_get_pending
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_node_struct* _oksos_request_get_pending(srv_oksos_req_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type < SRV_OKSOS_REQ_TYPE_TOTAL);
    return g_srv_oksos_p->req_info.pending_req[type];
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_execute_ext
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_request_execute_ext(srv_oksos_node_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (req->req_para->type)
    {
        case SRV_OKSOS_REQ_TYPE_ACTION:
            srv_oksos_act_req(&req->req_para->para.act);
            break;

        case SRV_OKSOS_REQ_TYPE_DATA_CTRL: 
            result = srv_oksos_data_ctrl_req(&req->req_para->para.data);
            _oksos_request_exec_done(result, req);
            break;

        case SRV_OKSOS_REQ_TYPE_DATA_LOAD:
            srv_oksos_data_load_req(&req->req_para->para.load);
            _oksos_request_exec_done(result, req);
            break;

        case SRV_OKSOS_REQ_TYPE_KEY_COUNT:
            srv_oksos_key_set_count(req->req_para->para.key);
            _oksos_request_exec_done(result, req);
            break;

    #ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
        case SRV_OKSOS_REQ_TYPE_DATA_TRANS:
            srv_oksos_transfer_req(&req->req_para->para.transfer);
            _oksos_request_exec_done(result, req);
            break;
    #endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_delay_execute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void _oksos_request_delay_execute(void* params)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_node_struct* req = (srv_oksos_node_struct*)params;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (req)
    {
        SRV_OKSOS_LOG1(TRC_SRV_OKSOS_EXC_DLY_HD, req);
        req->delay_time = 0;
        _oksos_request_execute_ext(req);
    }
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_execute
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum _oksos_request_execute(srv_oksos_req_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_UNKNOWN;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(type < SRV_OKSOS_REQ_TYPE_TOTAL);

    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_EXC_NODE, g_srv_oksos_p->req_info.pending_req[type]);

    if (g_srv_oksos_p->req_info.pending_req[type] != NULL)
    {
        result = SRV_OKSOS_RET_PENDING;
    }
    else
    {
        srv_oksos_node_struct* req = _oksos_node_get_next(type);

        if (req && req->req_para)
        {
            result = srv_oksos_request_permit(req->req_para);

            if (SRV_OKSOS_RET_OK == result)
            {
                srv_oksos_request_update_info(SRV_OKSOS_PENDING_ON, req);

                if (req->delay_time > 0)
                {
                    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_EXC_DELAY, req->delay_time);
                    StartTimerEx(OKSOS_REQ_DELAY_TIMER, req->delay_time, _oksos_request_delay_execute, (void*)req);
                }
                else
                {
                    _oksos_request_execute_ext(req);
                }
            }
            else
            {
                _oksos_request_exec_done(result, req);
            }
        }
        else
        {
            result = SRV_OKSOS_RET_NO_REQ;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_exec_done
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void _oksos_request_exec_done(srv_oksos_result_enum result, srv_oksos_node_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_EXC_DONE, result, req);

    if (req && req->req_para)
    {
        srv_oksos_request_update_info(SRV_OKSOS_PENDING_OFF, req);

        if (SRV_OKSOS_RET_UCM_RETRY == result)
        {
            req->delay_time = SRV_OKSOS_REQ_DELAY_TIME;
            _oksos_node_insert_tail(&g_srv_oksos_p->req_list, req);
            _oksos_request_execute(req->req_para->type);
        }
        else
        {
            if (req->req_para->proc_func)
            {
                req->req_para->proc_func(result, req->req_para);
            }
            _oksos_request_execute(req->req_para->type);
            _oksos_node_del(req);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  _oksos_request_node_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_node_struct* _oksos_request_node_add(srv_oksos_new_req_struct* req_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_node_struct* new_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(req_para);

    new_req = OslMalloc(sizeof(srv_oksos_node_struct));
    memset(new_req, 0, sizeof(srv_oksos_node_struct));
    new_req->req_para = OslMalloc(sizeof(srv_oksos_new_req_struct));
    memcpy(new_req->req_para, req_para, sizeof(srv_oksos_new_req_struct));

    if (SRV_OKSOS_REQ_TYPE_ACTION == req_para->type)
    {
        _oksos_node_insert_tail(&g_srv_oksos_p->req_list, new_req);
    }
    else
    {
        _oksos_node_insert_head(&g_srv_oksos_p->req_list, new_req);
    }

    return new_req;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_evt_hdlr
 * DESCRIPTION
 *  This function is to handle the indication sent from ucm srv
 * PARAMETERS
 *  mmi_event_struct:     [IN] Event structure passed by callback manager
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_oksos_evt_hdlr(mmi_event_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_EVT_HD, para->evt_id);

    switch(para->evt_id)
    {
        case EVT_ID_SRV_UCM_INDICATION:
            {
                srv_ucm_ind_evt_struct *ind = (srv_ucm_ind_evt_struct*)para;

                switch (ind->ind_type)
                {
                    case SRV_UCM_OUTGOING_CALL_IND:
                        {
                            srv_ucm_outgoing_call_ind_struct* out_ind = (srv_ucm_outgoing_call_ind_struct*)ind->ptr;

                            if (SRV_UCM_MODULE_ORIGIN_OKSOS == out_ind->module_id && _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION) != NULL)
                            {
                                memcpy(&g_srv_oksos_p->req_info.dialing_uid, &out_ind->uid_info, sizeof(srv_ucm_id_info_struct));
                            }
                        }
                        break;

                    case SRV_UCM_CONNECT_IND:
                        {
                            srv_oksos_node_struct* cur_req = _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION);
                            srv_ucm_connect_ind_struct* con_ind = (srv_ucm_connect_ind_struct*)ind->ptr;

                            if (SRV_UCM_MODULE_ORIGIN_OKSOS == con_ind->module_id && cur_req != NULL
                              && srv_oksos_act_is_same_call(&g_srv_oksos_p->req_info.dialing_uid, &con_ind->uid_info))
                            {
                                memset(&g_srv_oksos_p->req_info.dialing_uid, 0, sizeof(srv_ucm_id_info_struct));
                                srv_oksos_act_cancel_req();
                                _oksos_request_exec_done(SRV_OKSOS_RET_OK, cur_req);
                            }
                        }
                        break;

                    case SRV_UCM_RELEASE_IND:
                        {
                            srv_oksos_node_struct* cur_req = _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION);
                            srv_ucm_release_ind_struct* rel_ind = (srv_ucm_release_ind_struct*)ind->ptr;

                            if (SRV_UCM_MODULE_ORIGIN_OKSOS == rel_ind->module_id && cur_req != NULL
                              && srv_oksos_act_is_same_call(&g_srv_oksos_p->req_info.dialing_uid, &rel_ind->uid_info))
                            {
                                memset(&g_srv_oksos_p->req_info.dialing_uid, 0, sizeof(srv_ucm_id_info_struct));

                                if ((rel_ind->call_duration.nDay + 
                                    rel_ind->call_duration.nHour +  
                                    rel_ind->call_duration.nMin + 
                                    rel_ind->call_duration.nSec) == 0)
                                {
                                    cur_req->req_para->para.act.attempts--;
                                    _oksos_request_exec_done(SRV_OKSOS_RET_UCM_RETRY, cur_req);
                                }
                                else
                                {
                                    _oksos_request_exec_done(SRV_OKSOS_RET_OK, cur_req);
                                }
                            }
                        }
                        break;

                    default:
                        break;
                }
            }
            break;

        case EVT_ID_SRV_UCM_ACTION_NOTIFY:
            {
                srv_ucm_act_notify_evt_struct *act_notify = (srv_ucm_act_notify_evt_struct*)para;

                if(SRV_UCM_ACT_NOTIFY_TYPE_START == act_notify->notify_type)
                {
                    if (SRV_UCM_END_SINGLE_ACT == act_notify->act_op)
                    {
                        srv_oksos_node_struct* cur_req = _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION);

                        srv_oksos_act_cancel_req();
                        _oksos_request_exec_done(SRV_OKSOS_RET_OK, cur_req);
                    }
                }
            }
            break;

        default:
            break;
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_data_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_new_req_struct load_req;
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    ReadValueSlim(NVRAM_SRV_OKSOS_KEY, (void*)&g_srv_oksos_p->key_count, DS_BYTE);
    ReadValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);

    g_srv_oksos_p->data_count = g_srv_oksos_p->nvram_info[DS_DOUBLE-1];
    g_srv_oksos_p->key_mode = g_srv_oksos_p->nvram_info[DS_DOUBLE-2];
    memcpy(&g_srv_oksos_p->data_info, g_srv_oksos_p->nvram_info, sizeof(U32));

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_REC_INIT, g_srv_oksos_p->key_count, g_srv_oksos_p->data_info);

    for (idx = 0; idx < SRV_OKSOS_MAX_REC_COUNT; idx++)
    {

        if (srv_oksos_is_valid_index(idx))
        {
            load_req.type = SRV_OKSOS_REQ_TYPE_DATA_LOAD;
            load_req.para.load.load_type = SRV_OKSOS_LOAD_TYPE_ONE;
            load_req.para.load.data_index = idx;
            load_req.para.load.output_p = (void*)&g_srv_oksos_p->data[idx];
            load_req.proc_func = NULL;

            srv_oksos_request_new(&load_req);
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_save
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_save(U16 index, srv_oksos_data_common_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data)
    {
        WriteRecordSlim(NVRAM_EF_OKSOS_INFO_LID,
                    (index+1),
                    (void*)data,
                    sizeof(srv_oksos_data_common_struct));

        g_srv_oksos_p->nvram_info[DS_DOUBLE-1] = (U8)g_srv_oksos_p->data_count;
        g_srv_oksos_p->nvram_info[DS_DOUBLE-2] = g_srv_oksos_p->key_mode;
        memcpy(g_srv_oksos_p->nvram_info, &g_srv_oksos_p->data_info, sizeof(U32));

        WriteValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);

        result = SRV_OKSOS_RET_OK;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_load
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_load(U16 index, srv_oksos_data_common_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data)
    {
        ReadRecordSlim(NVRAM_EF_OKSOS_INFO_LID,
                    (index+1),
                    (void*)data,
                    sizeof(srv_oksos_data_common_struct));

        result = SRV_OKSOS_RET_OK;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_load_multi_record
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_load_multi(U16 index, U16 count, srv_oksos_data_common_struct* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data)
    {
        ReadMultiRecordSlim(NVRAM_EF_OKSOS_INFO_LID,
                        (index+1),
                        (void*)data,
                        (U16)(count*sizeof(srv_oksos_data_common_struct)),
                        count);

        result = SRV_OKSOS_RET_OK;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_id_alloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_oksos_data_index_alloc(U8 key, U8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_ALLOC_ID, g_srv_oksos_p->data_info);

    if (key > 0 && num > 0)
    {
        U16 index = (key - 1) * SRV_OKSOS_MAX_NUM_COUNT + (num - 1);

        if (!(srv_oksos_is_valid_index(index)))
        {
            g_srv_oksos_p->data_info |= (1 << index);
            SRV_OKSOS_LOG1(TRC_SRV_OKSOS_ALLOC_ID, g_srv_oksos_p->data_info);
            g_srv_oksos_p->data_count++;
            return index;
        }
    }

    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_ALLOC_ID, g_srv_oksos_p->data_info);
    return SRV_OKSOS_INVALIE_REC_ID;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_index_get
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U16 srv_oksos_data_index_get(U8 key, U8 num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index = (key - 1) * SRV_OKSOS_MAX_NUM_COUNT + (num - 1);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (!(srv_oksos_is_valid_index(index)))
    {
        index = SRV_OKSOS_INVALIE_REC_ID;
    }

    return index;
}

static void srv_oksos_data_index_free(U16 data_index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(data_index <= SRV_OKSOS_MAX_REC_COUNT);

    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_FREE_ID, g_srv_oksos_p->data_info);

    g_srv_oksos_p->data_info &= (~(1 << (data_index)));

    g_srv_oksos_p->data_count--;

    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_FREE_ID, g_srv_oksos_p->data_info);
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_add
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_add(srv_oksos_data_req_strcut* data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 index;
    srv_oksos_result_enum result = SRV_OKSOS_RET_SAVE_FAIL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_req)
    {
        index = srv_oksos_data_index_alloc(data_req->para.key, data_req->para.index);

        memcpy(&g_srv_oksos_p->data[index], &data_req->para, sizeof(srv_oksos_data_common_struct));


        if (index != SRV_OKSOS_INVALIE_REC_ID)
        {
            result = srv_oksos_data_save((U16)index, &data_req->para);
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_update
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_update(srv_oksos_data_req_strcut* data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_req)
    {
        if ((data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE))) || (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_TIMES))))
        {
            U32 i;
            U16 index;

            for (i = 1; i <= SRV_OKSOS_MAX_NUM_COUNT; i++)
            {
                index = srv_oksos_data_index_get(data_req->para.key, i);

                if (SRV_OKSOS_INVALIE_REC_ID != index)
                {
                    if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE)))
                    {
                        g_srv_oksos_p->data[index].mode = data_req->para.mode;
                    }
                    if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_TIMES)))
                    {
                        g_srv_oksos_p->data[index].attempts = data_req->para.attempts;
                    }
                    srv_oksos_data_save(index, &g_srv_oksos_p->data[index]);
                }
            }

            if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE)))
            {
                srv_oksos_key_set_mode(data_req->para.key, data_req->para.mode);
            }
        }
        else
        {
            U16 index = srv_oksos_data_index_get(data_req->para.key, data_req->para.index);

            if (SRV_OKSOS_INVALIE_REC_ID != index)
            {
                if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_NUM)))
                {
                    memcpy(&g_srv_oksos_p->data[index].number, &data_req->para.number, sizeof(data_req->para.number));
                }
                if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_NAME)))
                {
                    memcpy(&g_srv_oksos_p->data[index].name, &data_req->para.name, sizeof(data_req->para.name));
                }
                if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE)))
                {
                    g_srv_oksos_p->data[index].mode = data_req->para.mode;
                }
                if (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_TIMES)))
                {
                    g_srv_oksos_p->data[index].attempts = data_req->para.attempts;
                }

                memcpy(&g_srv_oksos_p->data[index], &data_req->para, sizeof(srv_oksos_data_common_struct));
                srv_oksos_data_save(index, &g_srv_oksos_p->data[index]);
            }
        }
        result = SRV_OKSOS_RET_OK;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_delete
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_data_delete(srv_oksos_data_req_strcut* data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_req)
    {
        U16 index =  srv_oksos_data_index_get(data_req->para.key,data_req->para.index);

        srv_oksos_data_index_free(index);
 
        // just reset bit
        g_srv_oksos_p->nvram_info[DS_DOUBLE-1] = (U8)g_srv_oksos_p->data_count;
        memcpy(g_srv_oksos_p->nvram_info, &g_srv_oksos_p->data_info, sizeof(U32));
        WriteValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);

        // don't need wirte nvram again
        memset(&g_srv_oksos_p->data[index], 0, sizeof(srv_oksos_data_common_struct));

        result = SRV_OKSOS_RET_OK;
    }
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_ctrl_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_data_ctrl_req(srv_oksos_data_req_strcut* data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    if (data_req)
    {
        SRV_OKSOS_LOG1(TRC_SRV_OKSOS_DCTRL_REQ, data_req->dreq_type);

        switch(data_req->dreq_type)
        {
            case SRV_OKSOS_DREQ_TYPE_ADD:
                result = srv_oksos_data_add(data_req);
                break;

            case SRV_OKSOS_DREQ_TYPE_MODIFY:
                result = srv_oksos_data_update(data_req);
                break;

            case SRV_OKSOS_DREQ_TYPE_DELETE:
                result = srv_oksos_data_delete(data_req);
                break;

            default:
                result = SRV_OKSOS_RET_INVALIE_TYPE;
                break;
        }
    }

    if (SRV_OKSOS_RET_OK == result)
    {
        srv_oksos_data_change_notify_struct evt;

        MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_OKSOS_DATA_CHANGE);

        evt.type = data_req->dreq_type;

        MMI_FRM_CB_EMIT_POST_EVENT(&evt);
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_ctrl_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_data_ctrl_prmt(srv_oksos_data_req_strcut* data_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_OK;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_req)
    {
        if (SRV_OKSOS_DREQ_TYPE_ADD == data_req->dreq_type)
        {
            if(data_req->para.key-1 > g_srv_oksos_p->key_count)
            {
                result = SRV_OKSOS_RET_INVALID_KEY_VALUE;
            }
            else if (srv_oksos_data_index_get(data_req->para.key, data_req->para.index) != SRV_OKSOS_INVALIE_REC_ID)
            {
                result = SRV_OKSOS_RET_REC_EXIST;
            }
        }
        else if (SRV_OKSOS_DREQ_TYPE_MODIFY == data_req->dreq_type)
        {
            if ((data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE))) || (data_req->value_flag & (1 << (SRV_OKSOS_VFLAG_TIMES))))
            {
                if (data_req->para.key-1 > g_srv_oksos_p->key_count)
                {
                    result = SRV_OKSOS_RET_INVALID_KEY_VALUE;
                }
            }
            else if (srv_oksos_data_index_get(data_req->para.key, data_req->para.index) == SRV_OKSOS_INVALIE_REC_ID)
            {
                result = SRV_OKSOS_RET_REC_NOT_FIND;
            }
        }
        else if (SRV_OKSOS_DREQ_TYPE_DELETE == data_req->dreq_type)
        {
            if (data_req->para.key-1 > g_srv_oksos_p->key_count)
            {
                result = SRV_OKSOS_RET_INVALID_KEY_VALUE;
            }
            else if (srv_oksos_data_index_get(data_req->para.key, data_req->para.index) == SRV_OKSOS_INVALIE_REC_ID)
            {
                result = SRV_OKSOS_RET_REC_NOT_FIND;
            }
        }
        else
        {
            result = SRV_OKSOS_RET_INVALIE_TYPE;
        }
    }
    else
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_load_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_data_load_prmt(srv_oksos_data_load_req_strcut* load_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (load_req == NULL || load_req->output_p == NULL)
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }
    else if (load_req->data_index >= (NVRAM_EF_OKSOS_INFO_TOTAL))
    {
        result = SRV_OKSOS_RET_INVALID_IDX;
    }
    else if (SRV_OKSOS_LOAD_TYPE_ALL == load_req->load_type
     && (load_req->data_count > SRV_OKSOS_MAX_REC_COUNT
     || (load_req->data_index + load_req->data_count) > SRV_OKSOS_MAX_REC_COUNT))
    {
        result = SRV_OKSOS_RET_INVALID_MUL_LOAD;
    }
    else
    {
        result = SRV_OKSOS_RET_OK;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_data_load_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_data_load_req(srv_oksos_data_load_req_strcut* load_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_DLOAD_REQ, load_req->load_type);

    if (SRV_OKSOS_LOAD_TYPE_ONE == load_req->load_type)
    {
        srv_oksos_data_load(load_req->data_index, load_req->output_p);
    }
    else if (SRV_OKSOS_LOAD_TYPE_ALL == load_req->load_type)
    {
        srv_oksos_data_load_multi(load_req->data_index, load_req->data_count, load_req->output_p);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_key_set_count
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_key_set_count(U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_KEY_REQ, count);

    if (count <= SRV_OKSOS_MAX_KEY_COUNT)
    {
        g_srv_oksos_p->key_count = count;
        WriteValueSlim(NVRAM_SRV_OKSOS_KEY, (void*)&g_srv_oksos_p->key_count, DS_BYTE);

        // reset all the data
        memset(g_srv_oksos_p->nvram_info, 0, DS_DOUBLE);
        memset(g_srv_oksos_p->data, 0, NVRAM_EF_OKSOS_INFO_TOTAL*sizeof(srv_oksos_data_common_struct));
        g_srv_oksos_p->data_info = 0;
        g_srv_oksos_p->data_count = 0;
        g_srv_oksos_p->key_mode = 0;
        WriteValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);
    }
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_key_count_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_key_count_prmt(U8 key_count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_count == g_srv_oksos_p->key_count)
    {
        result = SRV_OKSOS_RET_KEY_SAME_COUNT;
    }
#ifndef __MMI_OKSOS_INTERNAL_ECC__
    else if (0 == key_count)
    {
        result = SRV_OKSOS_RET_INVALID_KEY_COUNT;
    }
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */
    else if (key_count <= SRV_OKSOS_MAX_KEY_COUNT)
    {
        result = SRV_OKSOS_RET_OK;
    }
    else
    {
        result = SRV_OKSOS_RET_INVALID_KEY_COUNT;
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_key_set_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_oksos_key_set_mode(U8 key, U8 mode)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key <= g_srv_oksos_p->key_count)
    {
        if (SRV_OKSOS_MODE_MANUAL == mode)
        {
            g_srv_oksos_p->key_mode |= (1 << (key-1));
        }
        else
        {
            g_srv_oksos_p->key_mode &= (~(1 << (key-1)));
        }
        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

    if (result)
    {
        g_srv_oksos_p->nvram_info[DS_DOUBLE-2] = g_srv_oksos_p->key_mode;
        WriteValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);
    }

    SRV_OKSOS_LOG3(TRC_SRV_OKSOS_KEY_SET_MODE, key, mode, g_srv_oksos_p->key_mode);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_key_get_mode
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_oksos_key_get_mode(U8 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 mode;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(key <= g_srv_oksos_p->key_count);
    mode = g_srv_oksos_p->key_mode & (1<<(key-1));
    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_KEY_SET_MODE, key, mode);
    return mode;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_callback
 * DESCRIPTION
 *  callback of action
 * PARAMETERS
 *  event:     [IN] Event structure passed by callback manager
 * RETURNS
 *  mmi_ret
 *****************************************************************************/
static mmi_ret srv_oksos_act_callback(mmi_event_struct *event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ucm_act_result_evt_struct *act_result = (srv_ucm_act_result_evt_struct *) event;
    srv_ucm_act_rsp_struct *dial_rsp;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(event->evt_id)
    {
        case EVT_ID_SRV_UCM_ACTION_RESULT:
        {
            switch (act_result->act_op)
            {
                case SRV_UCM_DIAL_ACT:
                case SRV_UCM_END_ALL_AND_DIAL_ACT:
                {
                    dial_rsp = (srv_ucm_act_rsp_struct*)act_result->act_result;

                    if (SRV_UCM_RESULT_INTERCEPTED == dial_rsp->result_info.result)
                    {
                        srv_oksos_node_struct* cur_req = _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION);

                        if (cur_req)
                        {
                            cur_req->req_para->para.act.attempts--;
                            _oksos_request_exec_done(SRV_OKSOS_RET_UCM_RETRY, cur_req);
                        }
                    }
                    else if (SRV_UCM_RESULT_OK != dial_rsp->result_info.result)
                    {
                       _oksos_request_exec_done(SRV_OKSOS_RET_UCM_FAIL, _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION));
                    }
                }
            }
        }
    }
    return MMI_RET_OK;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_act_prmt(srv_oksos_act_req_struct* act_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_req)
    {
        switch(act_req->type)
        {
            case SRV_OKSOS_TYPE_GSM_DIAL:
                {
                    result = srv_oksos_act_dial_prmt(act_req);
                }
                break;

            default:
                result = SRV_OKSOS_RET_INVALIE_TYPE;
                break;
        }
    }
    else
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_act_req(srv_oksos_act_req_struct* act_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_node_struct* pending = _oksos_request_get_pending(SRV_OKSOS_REQ_TYPE_ACTION);
    srv_ucm_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    // only one type now
    SRV_OKSOS_LOG3(TRC_SRV_OKSOS_ACT_REQ, act_req->type, act_req->key_value, act_req->index);

    if (SRV_OKSOS_TYPE_GSM_DIAL == act_req->type && pending != NULL)
    {
        srv_ucm_dial_act_req_struct dial_req;
        U16 index = srv_oksos_data_index_get(act_req->key_value, act_req->index);

        memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
        dial_req.module_id = SRV_UCM_MODULE_ORIGIN_OKSOS;

    #ifdef __MMI_OKSOS_INTERNAL_ECC__
        if (OKSOS_SP_KEY_VALUE == act_req->key_value)
        {
            dial_req.data_index = NVRAM_EF_OKSOS_INFO_TOTAL;
            mmi_asc_n_to_ucs2((CHAR*)dial_req.num_uri, (CHAR*)g_srv_oksos_internal_ecc[act_req->index], SRV_UCM_MAX_NUM_URI_LEN);
        }
        else
    #endif /* __MMI_OKSOS_INTERNAL_ECC__ */
        {
            dial_req.data_index = index;
            mmi_asc_n_to_ucs2((CHAR*)dial_req.num_uri, (CHAR*)g_srv_oksos_p->data[index].number, SRV_UCM_MAX_NUM_URI_LEN);
        }

        result = srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, (void*)&dial_req);

        if (SRV_UCM_RESULT_OK == result)
        {
            srv_ucm_act_request(SRV_UCM_DIAL_ACT, (void*)&dial_req, NULL, srv_oksos_act_callback);
        }
        else
        {
            result = srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, (void*)&dial_req);

            if (SRV_UCM_RESULT_OK == result)
            {
                srv_ucm_act_request(SRV_UCM_END_ALL_AND_DIAL_ACT, (void*)&dial_req, NULL, srv_oksos_act_callback);
            }
            else
            {
                _oksos_request_exec_done(SRV_OKSOS_RET_UCM_FAIL, pending);
            }
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_is_ss_string
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_oksos_act_is_ss_string(CHAR* ucs2_str)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    mmi_sim_enum sim_id;
    U32 i;
    U8 length;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_str)
    {
        length = (U8)mmi_ucs2strlen(ucs2_str);

        for (i = 0, sim_id = MMI_SIM1; i < MMI_SIM_TOTAL; i++, sim_id <<= 1)
        {
            if (srv_ss_is_valid_ss_string(sim_id, length, (WCHAR*)ucs2_str))
            {
                result = MMI_TRUE;
            }
        }
        SRV_OKSOS_LOG2(TRC_SRV_OKSOS_IS_ACT_SS, length, result);
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_is_ucm_allow
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_act_is_ucm_allow(U8* acs_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (acs_num && strlen((char*)acs_num) > 0)
    {
        srv_ucm_dial_act_req_struct dial_req;

        memset(&dial_req, 0, sizeof(srv_ucm_dial_act_req_struct));
        dial_req.call_type = SRV_UCM_VOICE_CALL_TYPE_ALL;
        mmi_asc_n_to_ucs2((CHAR*)dial_req.num_uri, (CHAR*)acs_num, SRV_UCM_MAX_NUM_URI_LEN);

        if (srv_oksos_act_is_ss_string((CHAR*)dial_req.num_uri))
        {
            result = SRV_OKSOS_RET_SS_IGNORE;
        }
        else if (SRV_UCM_RESULT_OK != srv_ucm_query_act_permit(SRV_UCM_DIAL_ACT, (void*)&dial_req))
        {
            if (SRV_UCM_RESULT_OK != srv_ucm_query_act_permit(SRV_UCM_END_ALL_AND_DIAL_ACT, (void*)&dial_req))
            {
                result = SRV_OKSOS_RET_UCM_FAIL;
            }
            else
            {
                result = SRV_OKSOS_RET_OK;
            }
        }
        else
        {
            result = SRV_OKSOS_RET_OK;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_dial_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_act_dial_prmt(srv_oksos_act_req_struct* act_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (act_req->attempts < 1)
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }
#ifdef __MMI_OKSOS_INTERNAL_ECC__
    else if (OKSOS_SP_KEY_VALUE == act_req->key_value) 
    {
        if(act_req->index < (sizeof(g_srv_oksos_internal_ecc)/sizeof(g_srv_oksos_internal_ecc[0])))
        {
            result = srv_oksos_act_is_ucm_allow((U8*)g_srv_oksos_internal_ecc[act_req->index]);
        }
        else
        {
            result = SRV_OKSOS_RET_INVALID_IDX;
        }
    }
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */
    else if (srv_oksos_query_num_list(MMI_KEY_VALUE_NONE, NULL) == 0)
    {
        result = SRV_OKSOS_RET_EMPTY_LIST;
    }
    else if (act_req->key_value-1 > g_srv_oksos_p->key_count)
    {
        result = SRV_OKSOS_RET_INVALID_KEY_VALUE;
    }
    else
    {
        U16 index = srv_oksos_data_index_get(act_req->key_value, act_req->index);

        if (SRV_OKSOS_INVALIE_REC_ID == index)
        {
            result = SRV_OKSOS_RET_REC_NOT_FIND;
        }
        else
        {
            result = srv_oksos_act_is_ucm_allow(g_srv_oksos_p->data[index].number);
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_cancel_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_act_cancel_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    _oksos_node_delete_by_type(&g_srv_oksos_p->req_list, SRV_OKSOS_REQ_TYPE_ACTION);
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_act_is_same_call
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_oksos_act_is_same_call(srv_ucm_id_info_struct* src, srv_ucm_id_info_struct* dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(src && dst);

    return ((src->group_id == dst->group_id && src->call_id == dst->group_id)?MMI_TRUE:MMI_FALSE);
}



#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_create_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static char* srv_oksos_transfer_create_cmd(U8* data, U32 data_len, U32* command_len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    char* cmd = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (command_len)
    {
        *command_len = 0;
    }

    if (data)
    {
        char* data_p;
        U32 header_len;
        U32 idx;

        cmd = OslMalloc(SRV_OKSOS_MAX_WRITE_BUFF);

        memset(cmd, 0, SRV_OKSOS_MAX_WRITE_BUFF);
        sprintf(cmd, "%s %s %d %d ",BT_NOTIFY_OKSOS_SENDER, BT_NOTIFY_OKSOS_RECEIVER, 0, data_len);

        kal_wap_trace(MOD_MMI_COMMON_APP, TRACE_GROUP_5,
          "[OKSOSSrv] srv_oksos_transfer_create_cmd, cmd:%s, data_len:%d", cmd, data_len);

        header_len = strlen(cmd);
        data_p = cmd + header_len;

        MMI_ASSERT((U32)(&cmd[SRV_OKSOS_MAX_WRITE_BUFF] - data_p) >= data_len);

        memcpy(data_p, data, data_len);

        for (idx = 0; idx < data_len; idx++)
        {
            SRV_OKSOS_LOG2(TRC_SRV_OKSOS_DATA_BUFF, idx, (*(data+idx)));
        }


        if (command_len)
        {
            *command_len = header_len + data_len;
        }
    }
    return cmd;
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_delete_cmd
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_delete_cmd(char** cmd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (*cmd)
    {
        OslMfree((*cmd));
        (*cmd) = NULL;
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_check_connection
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_oksos_transfer_check_connection(srv_bt_cm_bt_addr *bt_addr)
{
#ifdef __OKSOS_UT_CONDITION_OK__
    return MMI_TRUE;
#else
    return (OKSOS_IsValidDevice(bt_addr) && srv_bt_noti_check_connection_ext(bt_addr))? MMI_TRUE : MMI_FALSE;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_err_rsp_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_transfer_err_rsp_prmt(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        if (!srv_oksos_transfer_check_connection(&data_trans->bt_addr))
        {
            result = SRV_OKSOS_RET_TRAN_NO_CONNECTION;
        }
        else
        {
            result = SRV_OKSOS_RET_OK;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_sos_ind_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_transfer_sos_ind_prmt(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        if (!srv_oksos_transfer_check_connection(&data_trans->bt_addr))
        {
            result = SRV_OKSOS_RET_TRAN_NO_CONNECTION;
        }
        else
        {
            result = SRV_OKSOS_RET_OK;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_read_rsp_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_transfer_read_rsp_prmt(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        U16 index = srv_oksos_data_index_get(data_trans->key_value, data_trans->num_index);

        if (SRV_OKSOS_INVALIE_REC_ID == index)
        {
            result = SRV_OKSOS_RET_REC_NOT_FIND;
        }
        else if (0 == data_trans->value_flag)
        {
            result = SRV_OKSOS_RET_TRAN_NO_VALUE;
        }
        else if (SRV_OKSOS_TRAN_CMD_READ_RSP != data_trans->tran_type)
        {
            result = SRV_OKSOS_RET_TRAN_INVALID_TYPE;
        }
        else if (!srv_oksos_transfer_check_connection(&data_trans->bt_addr))
        {
            result = SRV_OKSOS_RET_TRAN_NO_CONNECTION;
        }
        else
        {
            result = SRV_OKSOS_RET_OK;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_write_rsp_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_transfer_write_rsp_prmt(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALIE_TYPE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        U16 index = srv_oksos_data_index_get(data_trans->key_value, data_trans->num_index);

        if (SRV_OKSOS_DREQ_TYPE_DELETE == data_trans->write_type)
        {
            if (SRV_OKSOS_INVALIE_REC_ID == index)
            {
                result = SRV_OKSOS_RET_OK;
            }
            else
            {
                result = SRV_OKSOS_RET_SAVE_FAIL;
            }
        }
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        else if (0 == data_trans->value_flag)
        {
            result = SRV_OKSOS_RET_TRAN_NO_VALUE;
        }
        else if (SRV_OKSOS_TRAN_CMD_WRITE_RSP != data_trans->tran_type)
        {
            result = SRV_OKSOS_RET_TRAN_INVALID_TYPE;
        }
        else if (!srv_oksos_transfer_check_connection(&data_trans->bt_addr))
        {
            result = SRV_OKSOS_RET_TRAN_NO_CONNECTION;
        }
        else
        {
            result = SRV_OKSOS_RET_OK;
        }
    }
    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_cmd_prmt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static srv_oksos_result_enum srv_oksos_transfer_cmd_prmt(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALIE_TYPE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data_trans)
    {
        switch (data_trans->tran_type)
        {
            case SRV_OKSOS_TRAN_CMD_ERR:
                result = srv_oksos_transfer_err_rsp_prmt(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_SOS_IND:
                result = srv_oksos_transfer_sos_ind_prmt(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_READ_RSP:
                result = srv_oksos_transfer_read_rsp_prmt(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_WRITE_RSP:
                result = srv_oksos_transfer_write_rsp_prmt(data_trans);
                break;

            default:
                break;
        }
    }
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_get_err_code
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static U8 srv_oksos_transfer_get_err_code(srv_oksos_result_enum result)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 err_code;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (result)
    {
        case SRV_OKSOS_RET_TRAN_INVALID_TYPE:
            err_code = SRV_OKSOS_RET_TRAN_INVALID_TYPE;
            break;

        case SRV_OKSOS_RET_EMPTY_NUM:
        case SRV_OKSOS_RET_EMPTY_LIST:
            err_code = SRV_OKSOS_ERR_INVALID_PDU;
            break;

        case SRV_OKSOS_RET_INVALUE_PARA:
            err_code = SRV_OKSOS_ERR_INVALID_IDX;
            break;

        case SRV_OKSOS_RET_INVALID_KEY_VALUE:
            err_code = SRV_OKSOS_ERR_INVALID_KEY_VALUE;

        case SRV_OKSOS_RET_REC_FULL:
            err_code = SRV_OKSOS_ERR_SOS_LIST_FULL;
            break;

        case SRV_OKSOS_RET_INVALID_NUM:
            err_code = SRV_OKSOS_ERR_INVALID_IDX;
            break;

        default:
            err_code = SRV_OKSOS_ERR_UNKNOW_ERR;
            break;
    }
    return err_code;
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_send_err_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_send_err_rsp(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* write_p, *temp_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        U32 data_len, command_len;
        char* cmd;

        temp_buff = OslMalloc(SRV_OKSOS_MAX_WRITE_BUFF);
        memset(temp_buff, 0, SRV_OKSOS_MAX_WRITE_BUFF);
        write_p = temp_buff;

        // command type + command label
        *write_p = SRV_OKSOS_TRAN_CMD_ERR;
        *(write_p+1) = data_trans->cmd_label;
        write_p += 2;

        // command value length
        write_p += 2;

        // error code
        *write_p = srv_oksos_transfer_get_err_code(data_trans->result);

        // command type
        *(write_p+1) = (U8)data_trans->err_cmd;

        write_p += 2;

        *(write_p) = data_trans->key_value;
        *(write_p+1) = data_trans->num_index;
        write_p += 2;     

        data_len = write_p - &temp_buff[4];

        // comand length
        memcpy(&temp_buff[2], &data_len, sizeof(U16));

        cmd = srv_oksos_transfer_create_cmd(temp_buff, (write_p - &temp_buff[0]), &command_len);
        srv_bt_noti_send_cmd_ext(&data_trans->bt_addr, BT_NOTIFY_OKSOS_CMD, cmd, command_len);
        srv_oksos_transfer_delete_cmd(&cmd);

        OslMfree(temp_buff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_send_sos_ind
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_send_sos_ind(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* write_p, *temp_buff;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        U32 i, j, data_len, command_len;
        char* cmd;
        U16 index;
        U8 mode = 0, attempts = 3;

        temp_buff = OslMalloc(SRV_OKSOS_MAX_WRITE_BUFF);
        memset(temp_buff, 0, SRV_OKSOS_MAX_WRITE_BUFF);
        write_p = temp_buff;

        // command type + command label
        *write_p = SRV_OKSOS_TRAN_CMD_SOS_IND;
        *(write_p+1) = data_trans->cmd_label;
        write_p += 2;

        // command value length
        write_p += 2;

        // key count
        *write_p = g_srv_oksos_p->key_count;

        // max number watch supported
        *(write_p+1) = SRV_OKSOS_MAX_NUM_COUNT;

        write_p += 2;

        for (i = 1; i <= g_srv_oksos_p->key_count; i++)
        {
            *write_p = i;
            write_p++;

            for (j = 1; j <= SRV_OKSOS_MAX_NUM_COUNT; j++)
            {
                index = srv_oksos_data_index_get(i, j);

                if (SRV_OKSOS_INVALIE_REC_ID != index)
                {
                    *write_p = j;
                    mode = g_srv_oksos_p->data[index].mode;
                    attempts = g_srv_oksos_p->data[index].attempts;
                }
                else
                {
                    *write_p = 0;
                }
                write_p++;
            }
            // mode
            *write_p = mode;
            // attempts
            *(write_p+1) = attempts;
            write_p += 2;
        }

        data_len = write_p - &temp_buff[4];

        // comand length
        memcpy(&temp_buff[2], &data_len, sizeof(U16));

        cmd = srv_oksos_transfer_create_cmd(temp_buff, (write_p - &temp_buff[0]), &command_len);
        srv_bt_noti_send_cmd_ext(&data_trans->bt_addr, BT_NOTIFY_OKSOS_CMD, cmd, command_len);
        srv_oksos_transfer_delete_cmd(&cmd);

        OslMfree(temp_buff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_send_read_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_send_read_rsp(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8* write_p, *temp_buff;
    U32 buff_len = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        U16 index = srv_oksos_data_index_get(data_trans->key_value, data_trans->num_index);

        temp_buff = OslMalloc(SRV_OKSOS_MAX_WRITE_BUFF);
        memset(temp_buff, 0, SRV_OKSOS_MAX_WRITE_BUFF);

        write_p = temp_buff;

        *write_p = SRV_OKSOS_TRAN_CMD_READ_RSP;
        *(write_p+1) = data_trans->cmd_label;
        *(write_p+4) = data_trans->key_value;
        *(write_p+5) = data_trans->num_index;

        write_p += 6;

        if (index != SRV_OKSOS_INVALIE_REC_ID)
        {
            srv_oksos_data_common_struct* data_p = &g_srv_oksos_p->data[index];

            if (data_trans->value_flag & (1 << (SRV_OKSOS_VFLAG_NUM)))
            {
                U32 num_len = strlen((char*)data_p->number);

                // value flag
                *write_p = SRV_OKSOS_VFLAG_NUM;

                // value length
                memcpy((write_p+1), &num_len, sizeof(U16));

                write_p+=3;

                MMI_ASSERT(SRV_OKSOS_MAX_WRITE_BUFF >= NVRAM_EF_OKSOS_MAX_NUM_LEN);

                // value
                memcpy(write_p, data_p->number, num_len);

                write_p += num_len;

                MMI_ASSERT((U32)(&temp_buff[SRV_OKSOS_MAX_WRITE_BUFF] - write_p) >= num_len);
            }
            if (data_trans->value_flag & (1 << (SRV_OKSOS_VFLAG_NAME)))
            {
                U32 name_len = strlen((char*)data_p->name);

                // value flag
                *write_p = SRV_OKSOS_VFLAG_NAME;

                // value length
                memcpy((write_p+1), &name_len, sizeof(U16));              

                write_p+=3;

                MMI_ASSERT((&temp_buff[SRV_OKSOS_MAX_WRITE_BUFF]-write_p) >= (NVRAM_EF_OKSOS_MAX_NAME_LEN*ENCODING_LENGTH));

                // value
                memcpy(write_p, data_p->name, name_len);
                write_p += name_len;
            }
            if (data_trans->value_flag & (1 << (SRV_OKSOS_VFLAG_MODE)))
            {
                // value flag
                *write_p = SRV_OKSOS_VFLAG_MODE;

                // value
                *(write_p+1) = data_p->mode;

                write_p+=2;
            }
            if (data_trans->value_flag & (1 << (SRV_OKSOS_VFLAG_TIMES)))
            {
                // value flag
                *write_p = SRV_OKSOS_VFLAG_TIMES;

                // value
                *(write_p+1) = data_p->attempts;

                write_p+=2;
            }
            buff_len = write_p - &temp_buff[4]; // command length of OKSOS

            MMI_ASSERT(buff_len <= SRV_OKSOS_MAX_WRITE_BUFF);

            // command length
            memcpy(&temp_buff[2], &buff_len, sizeof(U16));

            SRV_OKSOS_LOG1(TRC_SRV_OKSOS_READ_CMD_BLEN, buff_len);

            // TODO: didn't support multi link
            if(srv_oksos_transfer_check_connection(&data_trans->bt_addr))
            {
                U32 cmd_len;
                char* cmd = srv_oksos_transfer_create_cmd(temp_buff, (write_p - &temp_buff[0]), &cmd_len);
                srv_bt_noti_send_cmd_ext(&data_trans->bt_addr, BT_NOTIFY_OKSOS_CMD, cmd, cmd_len);
                srv_oksos_transfer_delete_cmd(&cmd);
            }

            OslMfree(temp_buff);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_send_write_rsp
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_send_write_rsp(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if(data_trans && srv_oksos_transfer_check_connection(&data_trans->bt_addr))
    {
        U32 cmd_len, idx, value_flag = data_trans->value_flag;
        U16 data_len;
        U8 *write_p, *temp_buff;
        char* cmd;

        temp_buff = OslMalloc(SRV_OKSOS_MAX_WRITE_BUFF);
        memset(temp_buff, 0, SRV_OKSOS_MAX_WRITE_BUFF);

        write_p = temp_buff;

        *write_p = SRV_OKSOS_TRAN_CMD_WRITE_RSP;
        *(write_p+1) = data_trans->cmd_label;
  
        write_p += 4; // skip command type and command label and command length

        *write_p = data_trans->write_type;
        write_p++;

        *write_p = data_trans->key_value;
        *(write_p+1) = data_trans->num_index;
        write_p += 2;
        
        for(idx = 0; idx < SRV_OKSOS_VFLAG_TOTAL; idx++)
        {
            if (value_flag & (1 << idx))
            {
                *write_p = idx;
                write_p++;
            }
        }

        data_len = write_p - &temp_buff[4];
        memcpy(&temp_buff[2], &data_len, sizeof(U16));

        cmd = srv_oksos_transfer_create_cmd(temp_buff, (write_p - &temp_buff[0]), &cmd_len);
        srv_bt_noti_send_cmd_ext(&data_trans->bt_addr, BT_NOTIFY_OKSOS_CMD, cmd, cmd_len);
        srv_oksos_transfer_delete_cmd(&cmd);

        OslMfree(temp_buff);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_req
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_transfer_req(srv_oksos_trans_cmd_req_struct* data_trans)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_trans)
    {
        SRV_OKSOS_LOG1(TRC_SRV_OKSOS_TRAN_REQ, data_trans->tran_type);

        switch (data_trans->tran_type)
        {
            case SRV_OKSOS_TRAN_CMD_ERR:
                srv_oksos_transfer_send_err_rsp(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_SOS_IND:
                srv_oksos_transfer_send_sos_ind(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_READ_RSP:
                srv_oksos_transfer_send_read_rsp(data_trans);
                break;

            case SRV_OKSOS_TRAN_CMD_WRITE_RSP:
                srv_oksos_transfer_send_write_rsp(data_trans);
                break;

            default:
                break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_cmd_read_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_cmd_read_hdlr(U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data)
    {
        U16 cmd_len;
        U8* read_p;
        srv_oksos_new_req_struct new_req;

        memset(&new_req, 0, sizeof(srv_oksos_new_req_struct));

        new_req.type = SRV_OKSOS_REQ_TYPE_DATA_TRANS;
        new_req.para.transfer.tran_type = SRV_OKSOS_TRAN_CMD_READ_RSP;
        new_req.para.transfer.cmd_label = *(data+1);
        memcpy(&cmd_len, (data+2), sizeof(U16));
        new_req.para.transfer.key_value = *(data+4);
        new_req.para.transfer.num_index = *(data+5);
        memcpy(&new_req.para.transfer.bt_addr, &g_srv_oksos_p->bt_addr, sizeof(srv_bt_cm_bt_addr));

        SRV_OKSOS_LOG1(TRC_SRV_OKSOS_READ_CMD_LEN, cmd_len);

        // remove key value and nubmer index
        cmd_len -= 2;

        read_p = data+6;

        while (cmd_len > 0)
        {
            SRV_OKSOS_LOG1(TRC_SRV_OKSOS_READ_CMD_VFLAG, *read_p);

            if (*read_p > 0)
            {
                new_req.para.transfer.value_flag |= (1 << (*read_p));               
            }

            cmd_len--;
            read_p++;
        }

        new_req.para.transfer.result = srv_oksos_request_new(&new_req);

        if (cmd_len > SRV_OKSOS_MAX_READ_CMD_LEN
         || (SRV_OKSOS_RET_OK != new_req.para.transfer.result
         && SRV_OKSOS_RET_PENDING != new_req.para.transfer.result))
        {
            // Error response
            new_req.para.transfer.err_cmd = SRV_OKSOS_TRAN_CMD_READ_RSP;
            new_req.para.transfer.tran_type = SRV_OKSOS_TRAN_CMD_ERR;
            srv_oksos_request_new(&new_req);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_cmd_write_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_oksos_transfer_cmd_write_hdlr(U8* data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_new_req_struct new_req;
    srv_oksos_new_req_struct write_rsp;
    U8* read_p;
    srv_oksos_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (data)
    {
        U16 cmd_len;
        U32 value_flag = 0;

        // command length
        memcpy(&cmd_len, data+2, sizeof(U16));

        read_p = data+4;

        memset(&new_req, 0, sizeof(srv_oksos_new_req_struct));
        memset(&write_rsp, 0, sizeof(srv_oksos_new_req_struct));
        new_req.type = SRV_OKSOS_REQ_TYPE_DATA_CTRL;
        new_req.para.data.dreq_type = (srv_oksos_data_req_type)((*read_p));
        new_req.para.data.para.key = *(read_p+1);
        new_req.para.data.para.index = *(read_p+2);

        // skip type, key, index
        read_p += 3;

        if (SRV_OKSOS_VFLAG_NUM == *read_p)
        {
            U16 num_len;

            read_p++;

            // number length
            memcpy(&num_len, read_p, sizeof(U16));
            read_p += 2;

            // number
            memcpy(new_req.para.data.para.number, read_p, num_len);
            read_p += num_len;

            value_flag |= (1 << SRV_OKSOS_VFLAG_NUM);
        }

        if (SRV_OKSOS_VFLAG_NAME == *read_p)
        {
            U16 name_len;

            read_p++;

            // number length
            memcpy(&name_len, read_p, sizeof(U16));
            read_p += 2;

            // number
            memcpy(new_req.para.data.para.name, read_p, name_len);
            read_p += name_len;

            value_flag |= (1 << SRV_OKSOS_VFLAG_NAME);
        }

        if (SRV_OKSOS_VFLAG_MODE == *read_p)
        {
            read_p++;
            new_req.para.data.para.mode = *read_p;
            read_p++;

            value_flag |= (1 << SRV_OKSOS_VFLAG_MODE);
        }
        else
        {
            new_req.para.data.para.mode = srv_oksos_key_get_mode(new_req.para.data.para.key);
        }

        if (SRV_OKSOS_VFLAG_TIMES == *read_p)
        {
            read_p++;
            new_req.para.data.para.attempts = *read_p;
            read_p++;

            value_flag |= (1 << SRV_OKSOS_VFLAG_TIMES);
        }

        new_req.para.data.value_flag = value_flag;

        if (0 == new_req.para.data.para.attempts)
        {
            new_req.para.data.para.attempts = SRV_OKSOS_DEFAULT_LOOP_ATTEMPTS;
        }

        write_rsp.type = SRV_OKSOS_REQ_TYPE_DATA_TRANS;
        // command label
        write_rsp.para.transfer.cmd_label = *(data+1);
        // command para
        write_rsp.para.transfer.key_value = new_req.para.data.para.key;
        write_rsp.para.transfer.num_index = new_req.para.data.para.index;
        write_rsp.para.transfer.write_type = ((U8)new_req.para.data.dreq_type);
        write_rsp.para.transfer.value_flag = value_flag;
        memcpy(&write_rsp.para.transfer.bt_addr, &g_srv_oksos_p->bt_addr, sizeof(srv_bt_cm_bt_addr));

        result = srv_oksos_request_new(&new_req);

        if (SRV_OKSOS_RET_OK == result || SRV_OKSOS_RET_PENDING == result)
        {
            // send write reponse
            write_rsp.para.transfer.tran_type = SRV_OKSOS_TRAN_CMD_WRITE_RSP;
        }
        else
        {
            // error response
            write_rsp.para.transfer.tran_type = SRV_OKSOS_TRAN_CMD_ERR;
            write_rsp.para.transfer.err_cmd = SRV_OKSOS_TRAN_CMD_WRITE_RSP;
        }
        srv_oksos_request_new(&write_rsp);
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_notify_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_transfer_notify_callback(void *data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_callback_struct *p_data;
    U8* read_p;
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    p_data = (srv_bt_noti_callback_struct*)data;

    read_p = (U8*)p_data->data.buffer.data;

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_NOTI_CB, p_data->data.buffer.len, (*read_p));

    for (idx = 0; idx < p_data->data.buffer.len; idx++)
    {
        SRV_OKSOS_LOG2(TRC_SRV_OKSOS_TRAN_NOTI_BUFF, idx, p_data->data.buffer.data[idx]);
    }

    switch (*read_p)
    {
        case SRV_OKSOS_TRAN_CMD_READ_REQ:
            srv_oksos_transfer_cmd_read_hdlr(read_p);
            break;

        case SRV_OKSOS_TRAN_CMD_WRITE_REQ:
            srv_oksos_transfer_cmd_write_hdlr(read_p);
            break;

        default:
            break;
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_transfer_connection_callback
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret srv_oksos_transfer_connection_callback(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_connect_status_change_notify_struct* conn = (srv_bt_noti_connect_status_change_notify_struct*)evt;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_SRV_OKSOS_CONN_CB, conn->bt_addr.lap,
             conn->bt_addr.uap, conn->bt_addr.nap, conn->is_connected);

    if (conn->is_connected)
    {
        if (!OKSOS_IsValidDevice(&g_srv_oksos_p->bt_addr))
        {
            srv_oksos_new_req_struct new_req;

            memcpy(&g_srv_oksos_p->bt_addr, &conn->bt_addr, sizeof(srv_bt_cm_bt_addr));
            memset(&new_req, 0, sizeof(srv_oksos_new_req_struct));
            new_req.type = SRV_OKSOS_REQ_TYPE_DATA_TRANS;
            memcpy(&new_req.para.transfer.bt_addr, &conn->bt_addr, sizeof(srv_bt_cm_bt_addr));
            new_req.para.transfer.tran_type = SRV_OKSOS_TRAN_CMD_SOS_IND;
            new_req.para.transfer.cmd_label = 'O';

            srv_oksos_request_new(&new_req);
        }
    }
    else
    {
        if (OKSOS_IsSameDevice(&conn->bt_addr, &g_srv_oksos_p->bt_addr))
        {
            memset(&g_srv_oksos_p->bt_addr, 0, sizeof(srv_bt_cm_bt_addr));
        }
    }

    return MMI_RET_OK;
}
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG(TRC_SRV_OKSOS_INIT);
    memset(g_srv_oksos_p, 0, sizeof(srv_oksos_cntx_struct));
    g_srv_oksos_p->req_list.next = &g_srv_oksos_p->req_list;
    g_srv_oksos_p->req_list.prev = &g_srv_oksos_p->req_list;

    srv_oksos_data_init();

#ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
    srv_bt_noti_register_callback_ext(
        BT_NOTIFY_OKSOS_CMD,
        BT_NOTIFY_OKSOS_SENDER,
        srv_oksos_transfer_notify_callback);
#endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_init_para
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_init_para(srv_oksos_new_req_struct* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG(TRC_SRV_OKSOS_INIT_PARA);
    memset(para, 0, sizeof(srv_oksos_new_req_struct));
    para->type = SRV_OKSOS_REQ_TYPE_ACTION;
    para->para.act.attempts = 1;
    para->para.act.type = SRV_OKSOS_TYPE_GSM_DIAL;
}

/*****************************************************************************
 * FUNCTION
 *  srv_oksos_request_new
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_request_new(srv_oksos_new_req_struct* new_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;
    srv_oksos_node_struct* new_node;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_NEW_REQ_START, new_req->type);

    new_node = _oksos_request_node_add(new_req);

    result = _oksos_request_execute(new_req->type);

    if (SRV_OKSOS_RET_PENDING == result)
    {
        new_node->delay_time = SRV_OKSOS_REQ_DELAY_TIME;
    }

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_NEW_REQ_END, new_req->type, result);

    return result;
}



/*****************************************************************************
 * FUNCTION
 *  srv_oksos_request_permit
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_request_permit(srv_oksos_new_req_struct* new_req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result = SRV_OKSOS_RET_INVALUE_PARA;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (new_req)
    {
        SRV_OKSOS_LOG1(TRC_SRV_OKSOS_REQ_PRMT_START, new_req->type);

        switch(new_req->type)
        {
            case SRV_OKSOS_REQ_TYPE_ACTION:
                result = srv_oksos_act_prmt(&new_req->para.act);
                break;

            case SRV_OKSOS_REQ_TYPE_DATA_CTRL:
                result = srv_oksos_data_ctrl_prmt(&new_req->para.data);
                break;

        #ifdef __MMI_ONE_KEY_SOS_DATA_TRANS__
            case SRV_OKSOS_REQ_TYPE_DATA_TRANS:
                result = srv_oksos_transfer_cmd_prmt(&new_req->para.transfer);
                break;
        #endif /* __MMI_ONE_KEY_SOS_DATA_TRANS__ */

            case SRV_OKSOS_REQ_TYPE_DATA_LOAD:
                result = srv_oksos_data_load_prmt(&new_req->para.load);
                break;

            case SRV_OKSOS_REQ_TYPE_KEY_COUNT:
                result = srv_oksos_key_count_prmt(new_req->para.key);
                break;

            default:
                break;
        }
    }
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_REQ_PRMT_END, result);
    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_request_update_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_request_update_info(srv_oksos_req_flag_enum flag, srv_oksos_node_struct* req)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_req_type idx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
   SRV_OKSOS_LOG2(TRC_SRV_OKSOS_UPDATE_INFO, flag, req);

    if (req)
    {
        MMI_ASSERT(req->req_para->type < SRV_OKSOS_REQ_TYPE_TOTAL);

        switch(flag)
        {
            case SRV_OKSOS_PENDING_ON:
                g_srv_oksos_p->req_info.pending_req[req->req_para->type] = req;
                break;

            case SRV_OKSOS_PENDING_OFF:
                g_srv_oksos_p->req_info.pending_req[req->req_para->type] = NULL;
                break;

            default:
                break;
        }
    }

    for (idx = SRV_OKSOS_REQ_TYPE_NONE; idx < SRV_OKSOS_REQ_TYPE_TOTAL; idx++)
    {
        SRV_OKSOS_LOG2(TRC_SRV_OKSOS_PENDING_REQ, idx, g_srv_oksos_p->req_info.pending_req[idx])
    }
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_request_cancel
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_request_cancel(srv_oksos_req_type type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG1(TRC_SRV_OKSOS_CANCEL_REQ, type);
    _oksos_node_delete_by_type(&g_srv_oksos_p->req_list, type);    
}

#ifdef __MMI_OKSOS_INTERNAL_ECC__
/*****************************************************************************
 * FUNCTION
 *  srv_oksos_request_internal_ecc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_oksos_request_internal_ecc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_new_req_struct req;
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    req.type = SRV_OKSOS_REQ_TYPE_ACTION;
    req.para.act.type = SRV_OKSOS_TYPE_GSM_DIAL;
    req.proc_func = NULL;
    req.para.act.key_value = OKSOS_SP_KEY_VALUE;
    req.para.act.attempts = OKSOS_SP_TIMES;

    for (idx = 0; idx < sizeof(g_srv_oksos_internal_ecc)/sizeof(g_srv_oksos_internal_ecc[0]); idx++)
    {
        req.para.act.index = idx;
        srv_oksos_request_new(&req);
    }
}
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_is_action_valid
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_oksos_is_action_valid(srv_oksos_key_value_enum key, srv_oksos_type_enum act)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (SRV_OKSOS_TYPE_GSM_DIAL == act)
    {
        U32 i;
        U32 index[SRV_OKSOS_MAX_REC_COUNT];
        U32 count = srv_oksos_query_num_list(key, index);
        srv_oksos_data_info_struct* num_info;
        srv_oksos_new_req_struct req;

        memset(&req, 0, sizeof(srv_oksos_new_req_struct));
        req.type = SRV_OKSOS_REQ_TYPE_ACTION;
        req.para.act.type = act;
        req.proc_func = NULL;

        num_info = OslMalloc(sizeof(srv_oksos_data_info_struct));

        for (i = 0; i < count; i++)
        {
            req.para.act.index = index[i];

            if (SRV_OKSOS_RET_OK == srv_oksos_query_info(index[i], num_info))
            {
                req.para.act.key_value = num_info->key;
                req.para.act.attempts = num_info->attempts;
                req.para.act.index = num_info->index;
    
                if (SRV_OKSOS_RET_OK == srv_oksos_request_permit(&req))
                {
                    result = MMI_TRUE;
                    break;
                }
            }
        }

        OslMfree(num_info);
    }

    SRV_OKSOS_LOG3(TRC_SRV_OKSOS_IS_ACT_VALID, key, act, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_is_valid_number
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_oksos_is_valid_number(U16* ucs2_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ucs2_num)
    {
        S32 idx;

        for (idx = 0; idx < SRV_OKSOS_MAX_REC_COUNT;idx++)
        {
            if (srv_oksos_is_valid_index(idx))
            {
                if (mmi_ucs2ncmp((CHAR*)g_srv_oksos_p->data[idx].number,(CHAR*)ucs2_num, NVRAM_EF_OKSOS_MAX_NUM_LEN) == 0)
                {
                    result = MMI_TRUE;
                }
            }
        }
    }

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_query_num_list
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U32 srv_oksos_query_num_list(srv_oksos_key_value_enum key, U32 index[SRV_OKSOS_MAX_REC_COUNT])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count = 0;
    U32 idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (index)
    {
        memset(index, 0, sizeof(U32)*SRV_OKSOS_MAX_REC_COUNT);
    }

    if (MMI_KEY_VALUE_NONE == key)
    {
        U32 num_count = g_srv_oksos_p->key_count * SRV_OKSOS_MAX_NUM_COUNT;

        for (idx = 0; idx < num_count; idx++)
        {
            if (srv_oksos_is_valid_index(idx))
            {
                if (index)
                {
                    index[count] = idx;
                }
                count++;
            }
        }
    }
    else if (key <= g_srv_oksos_p->key_count)
    {
        U16 data_index;

        for (idx = 1; idx <= SRV_OKSOS_MAX_NUM_COUNT; idx++)
        {
            data_index = srv_oksos_data_index_get((U8)key, idx);

            if (SRV_OKSOS_INVALIE_REC_ID != data_index)
            {
                if (index)
                {
                    index[count] = data_index;
                }
                count++;
            }
        }
    }

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_GET_NUM_LIST, key, count);

    return count;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_query_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_query_info(U32 index, srv_oksos_data_info_struct* info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (info)
    {
        memset(info, 0, sizeof(srv_oksos_data_info_struct));

        if (srv_oksos_is_valid_index(index))
        {
            info->key = g_srv_oksos_p->data[index].key;
            info->index = g_srv_oksos_p->data[index].index;
            info->mode = g_srv_oksos_p->data[index].mode;
            info->attempts = g_srv_oksos_p->data[index].attempts;
            mmi_chset_utf8_to_ucs2_string((U8*)info->number, ENCODING_LENGTH*NVRAM_EF_OKSOS_MAX_NUM_LEN, (U8*)g_srv_oksos_p->data[index].number);
            mmi_chset_utf8_to_ucs2_string((U8*)info->name, ENCODING_LENGTH*NVRAM_EF_OKSOS_MAX_NAME_LEN, (U8*)g_srv_oksos_p->data[index].name);
            result = SRV_OKSOS_RET_OK;
        }
        else
        {
            result = SRV_OKSOS_RET_REC_NOT_FIND;
        }
    }
    else
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_GET_INFO, index, result);

    return result;
}


/*****************************************************************************
 * FUNCTION
 *  srv_oksos_query_key_info
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
srv_oksos_result_enum srv_oksos_query_key_info(srv_oksos_key_value_enum key, srv_oksos_key_info_struct* key_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_result_enum result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (key_info && key <= g_srv_oksos_p->key_count && key > MMI_KEY_VALUE_NONE)
    {
        U32 i;
        U16 index;

        memset(key_info, 0, sizeof(srv_oksos_key_info_struct));

        for (i = 1; i <= SRV_OKSOS_MAX_NUM_COUNT; i++)
        {
            index = srv_oksos_data_index_get((U8)key, (U8)i);

            if (SRV_OKSOS_INVALIE_REC_ID != index)
            {
                key_info->attempts = g_srv_oksos_p->data[index].attempts;
                key_info->mode = g_srv_oksos_p->data[index].mode;
                key_info->used_num_count++;
            }
        }

        if (key_info->used_num_count > 0)
        {
            result = SRV_OKSOS_RET_OK;
        }
        else
        {
            result = SRV_OKSOS_RET_EMPTY_LIST;
        }
    }
    else
    {
        result = SRV_OKSOS_RET_INVALUE_PARA;
    }

    SRV_OKSOS_LOG2(TRC_SRV_OKSOS_GET_KEY_INFO, key, result);

    return result;
}


#ifdef __OKSOS_UT_TEST__
srv_oksos_data_common_struct g_oksos_dummy_data[SRV_OKSOS_MAX_NUM_COUNT] = 
{
    {
        1,
        1,
        SRV_OKSOS_MODE_AUTO_LOOP,
        3,
        "10086",
        "China Mobile"
    },

    {
        1,
        2,
        SRV_OKSOS_MODE_AUTO_LOOP,
        3,
        "18328439999",
        "Jack"
    },

    {
        1,
        3,
        SRV_OKSOS_MODE_AUTO_LOOP,
        3,
        "13533333333",
        "Girlfriend"
    },

    {
        2,
        1,
        SRV_OKSOS_MODE_MANUAL,
        1,
        "10010",
        "Customer support"
    },

    {
        2,
        2,
        SRV_OKSOS_MODE_MANUAL,
        3,
        "18355555555",
        "Robbert"
    }

};

srv_oksos_data_common_struct g_oksos_dummy_data_modify[SRV_OKSOS_MAX_NUM_COUNT] = 
{
    {
        1,
        1,
        SRV_OKSOS_MODE_MANUAL,
        1,
        "12315",
        "Chinese customer..."
    },

    {
        1,
        2,
        SRV_OKSOS_MODE_MANUAL,
        1,
        "02885939000",
        "Mediatek CD"
    },

    {
        1,
        3,
        SRV_OKSOS_MODE_MANUAL,
        1,
        "12345",
        "City Master voice mail"
    },

    {
        2,
        1,
        SRV_OKSOS_MODE_MANUAL,
        2,
        "123123123",
        "Who knows?"
    },

    {
        2,
        2,
        SRV_OKSOS_MODE_MANUAL,
        2,
        "01012533352",
        "Something in the BJ"
    }

};

U8 g_oksos_dummy_transfer_data[] = {
    0x03/* command type */, 0x64/* command label */, 0x05, 0x00/* command length */, 0x01/* key value */,
    0x01/* number index */, 0x01/* value flag 1*/, 0x03/* value flag 2*/, 0x04/* value flag 3*/
};

U8 g_oksos_dummy_transfer_write_add[] = {
    0x04/* command type */, 0x65/* command label */, 0x05, 0x00/* command length */, 0x00/* write type */,
    0x01/* key value */, 0x01/* number index */,
    0x01/* value flag 1*/, 0x03, 0x00/* value length */, 0x31, 0x32, 0x33/* value (num:123)*/,
    0x02/* value flag 2*/, 0x03, 0x00/* value length */, 0x41, 0x42, 0x43/* Name: ABC */,
    0x03/* value flag 3*/, 0x00,
    0x04/* value flag 4*/, 0x03
};

U8 g_oksos_dummy_transfer_write_add2[] =
{
    0x04, 0xFF, 0x17, 0x00, 0x00, 0x01, 0x01, 0x01,
    0x0B, 0x00, 0x31, 0x38, 0x33, 0x32, 0x38, 0x34,
    0x33, 0x32, 0x39, 0x30, 0x39, 0x02, 0x03, 0x00,
    0x72, 0x69, 0x64
};

#endif // __OKSOS_UT_TEST__
/*****************************************************************************
 * FUNCTION
 *  srv_oksos_get_user_cntx
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_oksos_ut_handle(U8 index, kal_uint8* string)
{
#ifdef __OKSOS_UT_TEST__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    SRV_OKSOS_LOG3(TRC_SRV_OKSOS_UT_ENTRY, index, string[6], string[7]);

    if (strcmp((char*)string, "OKSOS_INIT") == 0)
    {
        srv_oksos_init();
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_ADD") == 0)
    {
        srv_oksos_new_req_struct req;

        req.type = SRV_OKSOS_REQ_TYPE_DATA_CTRL;
        req.para.data.dreq_type = SRV_OKSOS_DREQ_TYPE_ADD;
        memcpy(&req.para.data.para, &g_oksos_dummy_data[index] ,sizeof(srv_oksos_data_common_struct));
        req.proc_func = NULL;

        srv_oksos_request_new(&req);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_DEL") == 0)
    {
        srv_oksos_new_req_struct req;

        req.type = SRV_OKSOS_REQ_TYPE_DATA_CTRL;
        req.para.data.dreq_type = SRV_OKSOS_DREQ_TYPE_DELETE;
        memcpy(&req.para.data.para, &g_oksos_dummy_data[index] ,sizeof(srv_oksos_data_common_struct));
        req.proc_func = NULL;

        srv_oksos_request_new(&req);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_UPD") == 0)
    {
        srv_oksos_new_req_struct req;

        req.type = SRV_OKSOS_REQ_TYPE_DATA_CTRL;
        req.para.data.dreq_type = SRV_OKSOS_DREQ_TYPE_MODIFY;
        memcpy(&req.para.data.para, &g_oksos_dummy_data_modify[index] ,sizeof(srv_oksos_data_common_struct));
        req.proc_func = NULL;

        srv_oksos_request_new(&req);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_RESET") == 0)
    {
        U32 i;
        srv_oksos_data_common_struct empty;

        memset(g_srv_oksos_p->nvram_info, 0, DS_DOUBLE);
        memset(&empty, 0, sizeof(srv_oksos_data_common_struct));
        memset(g_srv_oksos_p->data, 0, NVRAM_EF_OKSOS_INFO_TOTAL*sizeof(srv_oksos_data_common_struct));

        g_srv_oksos_p->data_info = 0;
        g_srv_oksos_p->data_count = 0;
        g_srv_oksos_p->key_mode = 0;

        WriteValueSlim(NVRAM_SRV_OKSOS_NUM_INFO, (void*)g_srv_oksos_p->nvram_info, DS_DOUBLE);

        for (i = 0; i < SRV_OKSOS_MAX_REC_COUNT; i++)
        {
            WriteRecordSlim(NVRAM_EF_OKSOS_INFO_LID,
                        (i+1),
                        (void*)&empty,
                        sizeof(srv_oksos_data_common_struct));
        }
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_DIAL") == 0)
    {
        srv_oksos_new_req_struct req;
        U32 index [ SRV_OKSOS_MAX_REC_COUNT ], i;
        U32 count = srv_oksos_query_num_list(MMI_KEY_VALUE_NONE, index);
        srv_oksos_data_info_struct* num_info;

        req.type = SRV_OKSOS_REQ_TYPE_ACTION;
        req.para.act.type = SRV_OKSOS_TYPE_GSM_DIAL;
        req.proc_func = NULL;

        num_info = OslMalloc(sizeof(srv_oksos_data_info_struct));

        for (i = 0; i < count; i++)
        {
            req.para.act.index = index[i];

            if (SRV_OKSOS_RET_OK == srv_oksos_query_info(index[i], num_info))
            {
                req.para.act.key_value = num_info->key;
                req.para.act.attempts = num_info->attempts;
                req.para.act.index = num_info->index;

                srv_oksos_request_new(&req);
            }
        }

        OslMfree(num_info);
        result = 1;
    }
#ifdef __MMI_OKSOS_INTERNAL_ECC__
    else if (strcmp((char*)string, "OKSOS_DEFAULT") == 0)
    {
        srv_oksos_new_req_struct req;
        U32 idx;

        req.type = SRV_OKSOS_REQ_TYPE_ACTION;
        req.para.act.type = SRV_OKSOS_TYPE_GSM_DIAL;
        req.proc_func = NULL;
        req.para.act.key_value = OKSOS_SP_KEY_VALUE;
        req.para.act.attempts = OKSOS_SP_TIMES;

        for (idx = 0; idx < sizeof(g_srv_oksos_internal_ecc)/sizeof(g_srv_oksos_internal_ecc[0]); idx++)
        {
            req.para.act.index = idx;
            srv_oksos_request_new(&req);
        }
        result = 1;
    }
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */
    else if (strcmp((char*)string, "OKSOS_DATA") == 0)
    {
        srv_oksos_transfer_cmd_read_hdlr(g_oksos_dummy_transfer_data);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_CONN") == 0)
    {
        srv_bt_noti_connect_status_change_notify_struct notify;

        notify.bt_addr.lap = 0x1234;
        notify.bt_addr.uap = 0x56;
        notify.bt_addr.nap = 0x78;
        notify.is_connected = (MMI_BOOL)index;

        srv_oksos_transfer_connection_callback((mmi_event_struct*)&notify);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_WRT") == 0)
    {
        srv_oksos_transfer_cmd_write_hdlr(g_oksos_dummy_transfer_write_add);
        result = 1;
    }
    else if (strcmp((char*)string, "OKSOS_WRT2") == 0)
    {
        srv_oksos_transfer_cmd_write_hdlr(g_oksos_dummy_transfer_write_add2);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
#else // __OKSOS_UT_TEST__
    return 0;
#endif // __OKSOS_UT_TEST__
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
