
#include "MMI_features.h"
#ifdef __MMI_ONE_KEY_SOS_SUPPORT__
#include "GlobalResDef.h"                   // STR_GLOBAL_ERROR
#include "mmi_frm_scenario_gprot.h"         // MMI_FRM_NODE_SMART_CLOSE_FLAG
#include "OneKeySOSGprot.h"
#include "OneKeySOSprot.h"
#include "mmi_rp_app_oksos_def.h"
#include "DebugInitDef_Int.h" // MMI_ASSERT
#include "gui_data_types.h" // UI_string_type
#include "gui_typedef.h" // list_menu_category_history
#include "wgui_touch_screen.h" // mmi_tap_type_enum
#include "gui_inputs.h" // MMI_DIALING_KEY_ZERO
#include "Wgui_categories.h" // wgui_register_tap_callback
#include "Wgui_categories_list.h" // wgui_swatch_two_line_menu_list_screen
#include "Wgui_categories_util.h" //get_string
#include "MMI_common_app_trc.h"               // for trace id
#include "AlertScreen.h" // mmi_popup_display_ext
#include "UcmSrvGprot.h" // SRV_UCM_TOTAL_CALL_TYPE

static mmi_oksos_cntx_struct g_mmi_oksos_cntx;
mmi_oksos_cntx_struct* g_oksos_p = &g_mmi_oksos_cntx;


static void mmi_oksos_empty_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 list_not_ready;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    clear_screen();

    wgui_cat1032_show(
        (WCHAR*)GetString(STR_ID_OKSOS_LIST_TITLE),
        0,
        0,
        0,
        (WCHAR*)GetString(STR_GLOBAL_BACK),
        0,
        0,
        NULL,
        NULL,
        NULL,
        0,
        0,   
        0,
        NULL,
        &list_not_ready);

    SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
}


void mmi_oksos_list_tap_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count, num_index [ SRV_OKSOS_MAX_REC_COUNT ];
    srv_oksos_new_req_struct req;
    srv_oksos_data_info_struct* num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = srv_oksos_query_num_list(g_oksos_p->key, num_index);

    if (count == 0)
    {
        return;
    }

    MMI_ASSERT(count > index);

    req.type = SRV_OKSOS_REQ_TYPE_ACTION;
    req.para.act.type = SRV_OKSOS_TYPE_GSM_DIAL;
    req.proc_func = NULL;

    num_info = OslMalloc(sizeof(srv_oksos_data_info_struct));
    memset(num_info, 0, sizeof(srv_oksos_data_info_struct));

    req.para.act.index = num_index[index];

    if (SRV_OKSOS_RET_OK == srv_oksos_query_info(num_index[index], num_info))
    {
        req.para.act.key_value = num_info->key;
        req.para.act.attempts = num_info->attempts;
        req.para.act.index = num_info->index;

        srv_oksos_request_new(&req);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST);
    }
}


static S32 mmi_oksos_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 count, index [ SRV_OKSOS_MAX_REC_COUNT ];
    srv_oksos_data_info_struct* data_info;
    U32 i, idx;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    data_info = OslMalloc(sizeof(srv_oksos_data_info_struct));

    count = srv_oksos_query_num_list(g_oksos_p->key, index);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_SYNC_CB, start_index, num_item, count);

    MMI_ASSERT(count > start_index);

    for (i = 0, idx = start_index; i < num_item; idx++, i++)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_SYNC_IDX, idx, index[idx]);

        if (SRV_OKSOS_RET_OK == srv_oksos_query_info(index[idx], data_info))
        {
            if (mmi_ucs2strlen((CHAR*)data_info->name) > 0)
            {
                mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)data_info->name, SRV_OKSOS_MAX_NAME_LEN);
            }
            else
            {
                mmi_ucs2cpy((CHAR*)menu_data[i].item_list[0], NULL);
            }
            MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_SYNC_NUM,
                 mmi_ucs2strlen((CHAR*)data_info->name), data_info->name[0], data_info->name[1], data_info->name[2]);
            if (mmi_ucs2strlen((CHAR*)data_info->number) > 0)
            {
                mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[1], (CHAR*) data_info->number, SRV_OKSOS_MAX_NAME_LEN);
            }
            else
            {
                mmi_ucs2cpy((CHAR*)menu_data[i].item_list[1], NULL);
            }
        }
        else
        {
            //MMI_ASSERT(0);
            mmi_ucs2cpy((CHAR*)menu_data[i].item_list[0], NULL);
            mmi_ucs2cpy((CHAR*)menu_data[i].item_list[1], NULL);
        }
    }
    OslMfree(data_info);
    return num_item;
}


static void mmi_oksos_list_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    U32 num_count;
    S32 hilit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST);

    if (guiBuffer != NULL)
    {
        list_menu_category_history *hist = (list_menu_category_history*) guiBuffer;
        hilit = hist->highlighted_item;
    }
    else
    {
        hilit = 0;
    }

    wgui_cat_set_list_menu_empty_lable((UI_string_type)get_string(STR_GLOBAL_EMPTY));

    num_count = srv_oksos_query_num_list(g_oksos_p->key, NULL);

    if (num_count == 0)
    {
        mmi_oksos_empty_list();
    }
    else
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_LIST_SHOW, num_count);

        wgui_swatch_two_line_menu_list_screen(
             (PU8)GetString(STR_ID_OKSOS_LIST_TITLE),
             NULL,
             NULL,
             NULL,
             NULL,
             num_count,
             mmi_oksos_list_get_item_async,
             hilit,
             guiBuffer);
    #if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        wgui_register_tap_callback(mmi_oksos_list_tap_cb);
    #endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    }
}


static mmi_ret mmi_oksos_list_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_active_evt_struct* act_scrn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                act_scrn = (mmi_frm_scrn_active_evt_struct*)evt;

                if (mmi_frm_scrn_is_present(GRP_ID_OKSOS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_close(GRP_ID_OKSOS_APP, SCR_ID_DUMMY);
                }

                if (act_scrn->scrn_id == SCR_ID_OKSOS_LIST)
                {
                    if (mmi_frm_scrn_is_present(GRP_ID_OKSOS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
                    {
                        mmi_frm_scrn_close(GRP_ID_OKSOS_APP, SCR_ID_DUMMY);
                    }
                }
                mmi_oksos_list_show();
            }
            break;

        case EVT_ID_GROUP_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static void mmi_oksos_list_enter(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_OKSOS_APP) == MMI_FALSE)
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_OKSOS_APP,
            mmi_oksos_list_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (SCR_ID_OKSOS_LIST == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_DUMMY);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST);
    }

    mmi_frm_scrn_create(GRP_ID_OKSOS_APP, 
        SCR_ID_OKSOS_LIST, 
        mmi_oksos_list_proc,
        NULL);
}



static void mmi_oksos_manual_dial(srv_oksos_key_value_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_oksos_list_enter();
}


static void mmi_oksos_auto_dial(srv_oksos_key_value_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_new_req_struct req;
    U32 index [ SRV_OKSOS_MAX_REC_COUNT ], i;
    U32 count = srv_oksos_query_num_list(key, index);
    srv_oksos_data_info_struct* num_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
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
}


void mmi_oksos_set_key_count(U8 count)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (count <= SRV_OKSOS_MAX_KEY_COUNT)
    {
        srv_oksos_new_req_struct req;

        memset(&req, 0 , sizeof(srv_oksos_new_req_struct));
        req.type = SRV_OKSOS_REQ_TYPE_KEY_COUNT;
        req.para.key = count;

        srv_oksos_request_new(&req);
    }
}

void mmi_oksos_launch(srv_oksos_key_value_enum key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_key_info_struct key_info;
    srv_oksos_result_enum result;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_oksos_p->key = key;

    result = srv_oksos_query_key_info(key, &key_info);

    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_LAUNCH, result);

    if (SRV_OKSOS_RET_OK == result)
    {
        if (srv_oksos_is_action_valid(key, SRV_OKSOS_TYPE_GSM_DIAL))
        {
            srv_oksos_request_cancel(SRV_OKSOS_REQ_TYPE_ACTION);

            if (SRV_OKSOS_MODE_AUTO_LOOP == key_info.mode)
            {
                mmi_oksos_auto_dial(key);
            }
            else if (SRV_OKSOS_MODE_MANUAL == key_info.mode)
            {
                mmi_oksos_manual_dial(key);
            }
            else
            {
                // unknown mode
                MMI_ASSERT(0);
            }
        }
        else
        {
            // error alert.
            mmi_popup_display_ext(STR_GLOBAL_ERROR, MMI_EVENT_FAILURE, NULL);
        }
    }
#ifdef __MMI_OKSOS_INTERNAL_ECC__
    else if (MMI_KEY_VALUE_NONE == key)
    {
        srv_oksos_request_internal_ecc();
    }
#endif /* __MMI_OKSOS_INTERNAL_ECC__ */
    else if (SRV_OKSOS_RET_EMPTY_LIST == result)
    {
        mmi_popup_display_ext(STR_GLOBAL_EMPTY, MMI_EVENT_FAILURE, NULL);
    }
}


mmi_ret mmi_oksos_main_evt_hdlr(mmi_event_struct* event)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_oksos_data_change_notify_struct* data_change = (srv_oksos_data_change_notify_struct*)event;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (data_change)
    {
        MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_EVT_HD, data_change->type);

        if (mmi_frm_scrn_is_present(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST, MMI_FRM_NODE_ALL_FLAG))
        {
            mmi_frm_scrn_close(GRP_ID_OKSOS_APP, SCR_ID_OKSOS_LIST);
        }
    }
    return MMI_RET_OK;
}


void mmi_oksos_dial_long_press_handler(S32 key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_COMMON_TRC_G5_CALL, TRC_MMI_OKSOS_LONG_CB, key);

    if (key >=0 && key <= 9)
    {
        mmi_oksos_launch((srv_oksos_key_value_enum)key);
    }
#ifdef __MMI_TOUCH_SCREEN__
    else if (MMI_DIALING_KEY_ZERO == key)
    {
        mmi_oksos_launch(MMI_KEY_VALUE_NONE);
    }
#endif /* __MMI_TOUCH_SCREEN__ */
}


#endif /* __MMI_ONE_KEY_SOS_SUPPORT__ */
