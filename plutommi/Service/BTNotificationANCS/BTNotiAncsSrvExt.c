#include "MMI_features.h"
#ifdef __MMI_BLE_ANCS_SUPPORT__ 
#include "mmi_cb_mgr_gprot.h" // MMI_FRM_CB_EMIT_POST_EVENT_EX
#include "MMI_conn_app_trc.h" // for ancs trace id
#include "mmi_rp_srv_bt_noti_def.h"
#include "BTNotiAncsSrv.h"
#include "BTNotiAncsSrvGprot.h"
#include "DebugInitDef_Int.h"
#include "BTNotiSrvGprot.h"
#include "BtCmSrvGprot.h"
#include "mmi_frm_mem_gprot.h" // OslMalloc
#include "mmi_frm_events_gprot.h" // MMI_FRM_INIT_EVENT
#include "Conversions.h"  // for mmi_chset_utf8_to_ucs2_string
#include "App_datetime.h"
#include "BLESrvGprot.h" // srv_le_cm_evt_disconnect_struct


/*****************************************************************************
 * FUNCTION
 *  srv_ancs_get_spcial_attr
 * DESCRIPTION
 * 
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void srv_ancs_get_spcial_attr(srv_bt_noti_data_msg_node_struct *noti_data, srv_ancs_noti_info_struct* noti_info_p)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_notify_subtype_enum ret;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_ASSERT(noti_data && noti_info_p);

    switch(noti_info_p->cat_id)
    {
 
        case SRV_ANCS_CAT_MISSED_CALL:
            {
                ret = srv_bt_notify_subtype_missed_call;
            }
        case SRV_ANCS_CAT_EMAIL:
            {
                ret = srv_bt_notify_subtype_text;
            #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                if (noti_data->page_content)
                {
                    memcpy(noti_data->page_content->title, noti_info_p->title, BT_NOTIFY_TITLE_LENTH * sizeof(U16));
                }
            #else /* __MMI_BT_NOTIFICATION_ENHANCE__ */
                memcpy(noti_data->title, noti_info_p->title, BT_NOTIFY_TITLE_LENTH * sizeof(U16));
            #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
                memcpy(noti_data->sender, noti_info_p->app_name, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
            }
            break;

        case SRV_ANCS_CAT_SOCIAL:
            {
                if ((noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME) &&
                    mmi_ucs2cmp((const CHAR*)noti_info_p->title, (const CHAR*)noti_info_p->app_name))
                {
                    ret = srv_bt_notify_subtype_sms;
                    memcpy(noti_data->sender, noti_info_p->title, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                }
                else
                {
                    ret = srv_bt_notify_subtype_text;

                    if(!(noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME))
                    {
                        memcpy(noti_data->sender, noti_info_p->title, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                    }
                    else
                    {
                        memcpy(noti_data->sender, noti_info_p->app_name, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                    }
                }
            }
            break;

        case SRV_ANCS_CAT_SCHEDULE:
            {
                ret = srv_bt_notify_subtype_text;
                if(noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME)
                {
                    memcpy(noti_data->sender, noti_info_p->app_name, BT_NOTIFY_SENDER_LENTH * sizeof(U16));

                    if (noti_info_p->attr_flags & SRV_ANCS_ATTR_TITLE)
                    {
                        U32 buff_len;

                        if (BT_NOTIFY_CONTENT_LENTH > SRV_ANCS_TITILE_MAX_LEN)
                        {
                            buff_len = SRV_ANCS_TITILE_MAX_LEN;
                        }
                        else
                        {
                            buff_len = BT_NOTIFY_CONTENT_LENTH;
                        }
                    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                        if (noti_data->page_content)
                        {
                            memcpy(noti_data->page_content->content, noti_info_p->title, buff_len * sizeof(U16));
                        }
                    #else
                        memcpy(noti_data->content, noti_info_p->title, buff_len * sizeof(U16));
                    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
                    }
                }
                else
                {
                    memcpy(noti_data->sender, noti_info_p->title, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                }
            }
            break;

        default:
            {
                ret = srv_bt_notify_subtype_text;
                if(!(noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME))
                {
                    memcpy(noti_data->sender, noti_info_p->title, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                }
                else
                {
                    memcpy(noti_data->sender, noti_info_p->app_name, BT_NOTIFY_SENDER_LENTH * sizeof(U16));
                }
            }
            break;
    }
    noti_data->header.subtype = ret;     //default value
}

/*****************************************************************************
 * FUNCTION
 *  srv_ancs_get_notification_info
 * DESCRIPTION
 *  get notification info, prepare data for integration with BT notification, 
 * PARAMETERS
 *  ancs_info       [IN]        
 *  noti_info        [OUT]
 * RETURNS
 *  void
 *****************************************************************************/
static MMI_BOOL srv_ancs_get_notification_info(srv_ancs_noti_info_struct* ancs_info, srv_bt_noti_data_msg_node_struct *noti_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 timestamp;
    MMI_BOOL result;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (ancs_info && noti_info)
    {
        //prepare header
        noti_info->header.category = srv_bt_notify_category_noti;   //default value
        noti_info->header.msg_id = 0;                               //default value
        noti_info->header.action = srv_bt_notify_action_add;        //default value

        srv_ancs_get_spcial_attr(noti_info, ancs_info);

        //noti_data.sender_number  maybe used by sms
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        noti_info->page_num = 1;
        if (ancs_info->attr_flags & SRV_ANCS_ATTR_MSG)
        {
            memcpy(noti_info->page_content->content, ancs_info->msg, BT_NOTIFY_CONTENT_LENTH * sizeof(U16));
        }
    #else /* __MMI_BT_NOTIFICATION_ENHANCE__ */
        if (ancs_info->attr_flags & SRV_ANCS_ATTR_MSG)
        {
            memcpy(noti_info->content, ancs_info->msg, BT_NOTIFY_CONTENT_LENTH * sizeof(U16));
        }
    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */

        noti_info->missed_call_count = 0;    //not used by ANCS

        timestamp = applib_dt_mytime_2_utc_sec((applib_time_struct *)&(ancs_info->date), KAL_FALSE);

        noti_info->timestamp = applib_dt_sec_local_to_utc(timestamp);

        noti_info->app_id = srv_ancs_app_id_hash(ancs_info->app_id);

        noti_info->is_read = MMI_FALSE;     //not used by ANCS

        noti_info->source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;

        noti_info->ANCS_msg_id = ancs_info->noti_id;

        srv_ancs_covert2cm_addr(ancs_info->bd_addr.addr, &(noti_info->bt_addr));

        result = MMI_TRUE;
    }
    else
    {
        result = MMI_FALSE;
    }

     MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_ANCS_GET_NOTI_INFO, result);
    return result;
}


void srv_ancs_send_indication(srv_ancs_noti_type_enum ind_op, S32 noti_id, void *ptr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_event_struct evt;
    MMI_BOOL valid = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_SRV_ANCS_SEND_IND, ind_op, noti_id);
    switch(ind_op)
    {
        case SRV_ANCS_TYPE_ADDED:
        case SRV_ANCS_TYPE_MODIFIED:
            {
                srv_ancs_noti_info_struct* noti_info_p = OslMalloc(sizeof(srv_ancs_noti_info_struct));

                if (srv_ancs_query_notification_info(noti_info_p, noti_id, SRV_ANCS_GET_BY_NONE, NULL))
                {
                    if (noti_info_p->attr_flags > SRV_ANCS_ATTR_BASE)
                    {
                        srv_bt_noti_event_info_add *noti_info_add = OslMalloc(sizeof(srv_bt_noti_event_info_add));
                        memset(noti_info_add, 0, sizeof(srv_bt_noti_event_info_add));

                    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                        noti_info_add->msg_info.page_content = OslMalloc(sizeof(srv_bt_noti_page_content_struct));
                        memset(noti_info_add->msg_info.page_content, 0, sizeof(srv_bt_noti_page_content_struct));
                    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */

                        if (srv_ancs_get_notification_info(noti_info_p, &noti_info_add->msg_info))
                        {
                            memcpy(&noti_info_add->bt_addr, &noti_info_add->msg_info.bt_addr, sizeof(srv_bt_cm_bt_addr));

                            MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BT_NOTI_ADD_MSG);
                            evt.event_info = noti_info_add;
                            valid = MMI_TRUE;
                        }
                        else
                        {
                        #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
                            OslMfree(noti_info_add->msg_info.page_content);
                        #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
                            OslMfree(noti_info_add);
                        }
                    }
                }
                OslMfree(noti_info_p);
            }
            break;
        case SRV_ANCS_TYPE_REMOVED:
            {
                srv_bt_noti_event_info_del *noti_info_del;
                BD_ADDR* rm_bd_addr = (BD_ADDR*)ptr;

                MMI_ASSERT(rm_bd_addr);

                noti_info_del = OslMalloc(sizeof(srv_bt_noti_event_info_del));
                noti_info_del->ANCS_id = noti_id;
                noti_info_del->del_msg_id = 0;    //not used by ANCS
                noti_info_del->source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;
                srv_ancs_covert2cm_addr(rm_bd_addr->addr, &(noti_info_del->bt_addr));

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BT_NOTI_DEL_MSG);
                evt.event_info = noti_info_del;

                valid = MMI_TRUE;
            }
            break;

        case SRV_ANCS_TYPE_CONNECTED:
            {
                srv_bt_noti_event_info_connceted *noti_info_conn = OslMalloc(sizeof(srv_bt_noti_event_info_connceted));
                BD_ADDR* conn_bd_addr = (BD_ADDR*)ptr;

                memset(noti_info_conn, 0, sizeof(srv_bt_noti_event_info_connceted));
                srv_ancs_covert2cm_addr(conn_bd_addr->addr, &(noti_info_conn->bt_addr));
                noti_info_conn->source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BT_NOTI_CONNECTED);
                evt.event_info = noti_info_conn;

                valid = MMI_TRUE;
            }
            break;
        case SRV_ANCS_TYPE_DISCONNECTED:
            {
                srv_bt_noti_event_info_disconnceted *noti_info_conn = OslMalloc(sizeof(srv_bt_noti_event_info_disconnceted));
                BD_ADDR* conn_bd_addr = (BD_ADDR*)ptr;

                memset(noti_info_conn, 0, sizeof(srv_bt_noti_event_info_disconnceted));
                srv_ancs_covert2cm_addr(conn_bd_addr->addr, &(noti_info_conn->bt_addr));
                noti_info_conn->source = SRV_BT_NOTIFY_DATA_SOURCE_ANCS;

                MMI_FRM_INIT_EVENT(&evt, EVT_ID_SRV_BT_NOTI_DISCONNECTED);
                evt.event_info = noti_info_conn;

                valid = MMI_TRUE;
            }
            break;
        default:
            break;
    }

    if (valid)
    {
        MMI_FRM_CB_EMIT_POST_EVENT_EX((mmi_event_struct *)&evt, srv_ancs_post_event_callback, (void *)evt.event_info);
    }
}

mmi_ret srv_ancs_post_event_callback(mmi_post_result_event_struct *result_evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (result_evt->user_data != NULL)
    {
    #ifdef __MMI_BT_NOTIFICATION_ENHANCE__
        if (EVT_ID_SRV_BT_NOTI_ADD_MSG == result_evt->evt_p->evt_id)
        {
            srv_bt_noti_event_struct *noti_data = (srv_bt_noti_event_struct *)result_evt->evt_p;

            if (noti_data)
            {
                srv_bt_noti_event_info_add *noti_info_add = (srv_bt_noti_event_info_add*)noti_data->event_info;

                if (noti_info_add && noti_info_add->msg_info.page_content)
                {
                    OslMfree(noti_info_add->msg_info.page_content);
                    noti_info_add->msg_info.page_content = NULL;
                }
            }
        }
    #endif /* __MMI_BT_NOTIFICATION_ENHANCE__ */
        OslMfree(result_evt->user_data);
        result_evt->user_data = NULL;
    }
    return MMI_RET_OK;
}


mmi_ret srv_ancs_disconnect_hdlr(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_le_cm_evt_disconnect_struct *evt = (srv_le_cm_evt_disconnect_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt)
    {
        srv_ancs_disconnect_req(evt->dev_addr);
    }
    return MMI_RET_OK;
}

#endif // __MMI_BLE_ANCS_SUPPORT__
