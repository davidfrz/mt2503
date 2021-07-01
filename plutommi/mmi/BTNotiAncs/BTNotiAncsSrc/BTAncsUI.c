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
*  BTAncsUI.c
*
* Project:
* --------
*   MAUI
*
* Description:
* ------------
*   ANCS UI Source File
*
* Author:
* -------
 * -------
*
*==============================================================================
*           HISTORY
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
 * removed!
 *
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#ifdef 0//__MMI_BLE_ANCS_SUPPORT__
#include "GlobalResDef.h"
#include "BTAncsGprot.h"
#include "BTAncsprot.h"
#include "mmi_frm_mem_gprot.h"          // OslMalloc
#include "gui_data_types.h"             // UI_string_type
#include "mmi_rp_app_ancs_def.h"
#include "BTNotiAncsSrvGprot.h"
#include "mmi_rp_app_sms_def.h"         // IMG_MESSAGE_UNREAD
#include "mmi_frm_scenario_gprot.h"     // mmi_frm_scrn_close_active_id
#include "GlobalConstants.h"            // KEY_EVENT_UP
#include "custom_mmi_default_value.h"   // MYTIME
#include "gui_typedef.h"                // DT_IDLE_SCREEN
#include "mmi_rp_app_btnotification_def.h" // STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME
#include "wgui_touch_screen.h"          // mmi_tap_type_enum
#include "MMI_conn_app_trc.h"           // for ancs trace id
#include "AlertScreen.h"                // mmi_confirm_property_struct
#include "mmi_rp_app_calllog_def.h"     //STR_ID_CLOG_BT_DISMISS
#include "CommonScreensResDef.h"        //EVT_ID_ALERT_QUIT


static S32 mmi_bt_ancs_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item);
static void mmi_bt_ancs_list_tap_cb(mmi_tap_type_enum tap_type, S32 index);


static mmi_ret mmi_bt_ancs_msg_list_mark_as_read_confirm_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_alert_result_evt_struct *confirm_evt = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    ASSERT(evt);
    
    switch (evt->evt_id)
    {
        case EVT_ID_ALERT_QUIT:
        {
            confirm_evt = (mmi_alert_result_evt_struct*)evt;
            switch (confirm_evt->result)
            {
                case MMI_ALERT_CNFM_YES:
                {
                    //delete all notification
                    S32 nid_list[SRV_ANCS_MAX_NOTI_NUM];
                    U32 noti_count;
                    U8 i;
                    
                    noti_count = srv_ancs_query_notification_count(nid_list, SRV_ANCS_GET_BY_NONE, NULL);
                    for (i = 0; i < noti_count; i++)
                    {
                        srv_ancs_delete_notification(nid_list[i], SRV_ANCS_GET_BY_NONE, NULL);
                    }
                    break;
                }
                default:
                break;
            }
        }
    }

    return  MMI_RET_OK;
}


static void mmi_bt_ancs_msg_list_long_tap_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_confirm_property_struct confirm_property;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/   
    mmi_confirm_property_init(&confirm_property, CNFM_TYPE_YESNO);
    confirm_property.callback = (mmi_proc_func)mmi_bt_ancs_msg_list_mark_as_read_confirm_proc;
    confirm_property.parent_id  = GRP_ID_BT_ANCS_APP;
    
    mmi_confirm_display_ext(
        STR_ID_BTNOTIFICATION_MARK_ALL_AS_READ,
        MMI_EVENT_CONFIRM,
        &confirm_property);
}


void mmi_bt_ancs_notify_popup_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ancs_noti_info_struct* noti_info_p;
    WCHAR* timestamp_buffer;
    WCHAR  time[20];
    UI_string_type str_title;
    UI_string_type str_message;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_POP_SHOW, g_ancs_p->hilite_noti);

    noti_info_p = OslMalloc(sizeof(srv_ancs_noti_info_struct));

    if(!srv_ancs_query_notification_info(noti_info_p, g_ancs_p->hilite_noti, SRV_ANCS_GET_BY_NONE, NULL))
    {
        mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
        OslMfree(noti_info_p);
        return;
    }

    if (noti_info_p->cat_id == SRV_ANCS_CAT_MISSED_CALL ||       //missed call
        noti_info_p->cat_id == SRV_ANCS_CAT_SOCIAL ||            //sms
        noti_info_p->cat_id == SRV_ANCS_CAT_EMAIL ||
        !(noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME))
    {
        str_title = noti_info_p->title;
    }
    else
    {
        str_title = noti_info_p->app_name;
    }

    if (noti_info_p->cat_id == SRV_ANCS_CAT_SCHEDULE)
    {
        str_message = noti_info_p->title;
    }
    else
    {
        str_message = noti_info_p->msg;
    }
    
    if (noti_info_p->attr_flags & SRV_ANCS_ATTR_DATE)
    {
        timestamp_buffer = OslMalloc(sizeof(WCHAR) * 60);
        memset(timestamp_buffer, 0, sizeof(WCHAR) * 60);
        date_string((MYTIME*) &noti_info_p->date, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) time);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) (L" "));
        time_string((MYTIME*) &noti_info_p->date, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time);
    }
    else
    {
        timestamp_buffer = NULL;
    }

#ifdef __MMI_WEARABLE_DEVICE__
    wgui_showcategory6333_screen(
        str_title,
        (UI_string_type)GetString(STR_GLOBAL_VIEW),
        (UI_string_type)GetString(STR_ID_CLOG_BT_DISMISS),
        str_message,
        (UI_string_type)timestamp_buffer);
#else  //__MMI_WEARABLE_DEVICE__
    wgui_showcategory632_screen(
        (UI_string_type)noti_info_p->app_name,
        (UI_string_type)noti_info_p->title,
        (UI_string_type)GetString(STR_GLOBAL_VIEW),
        (UI_string_type)GetString(STR_GLOBAL_CANCEL),
        (UI_string_type)noti_info_p->msg,
        (UI_string_type)timestamp_buffer);
#endif  //__MMI_WEARABLE_DEVICE__
    OslMfree(noti_info_p);

    if (timestamp_buffer != NULL)
    {
        OslMfree(timestamp_buffer);
    }
    SetLeftSoftkeyFunction((FuncPtr)mmi_bt_ancs_details_launch, KEY_EVENT_UP);
    SetRightSoftkeyFunction((FuncPtr)mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    SetCenterSoftkeyFunction((FuncPtr)mmi_bt_ancs_details_launch, KEY_EVENT_UP);
}

void mmi_bt_ancs_notify_details_show(S32 noti_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ancs_noti_info_struct* noti_info_p;
    U8* gui_buffer = NULL;
    WCHAR* timestamp_buffer;
    WCHAR  time[20];
    U8 *title;
    U8 *app_name;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_DETAIL_SHOW, noti_id);

    noti_info_p = OslMalloc(sizeof(srv_ancs_noti_info_struct));

    if(!srv_ancs_query_notification_info(noti_info_p, noti_id, SRV_ANCS_GET_BY_NONE, NULL))
    {
        mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
        OslMfree(noti_info_p);
        return;
    }

    if (!mmi_is_redrawing_bk_screens()
        && mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP);
    }

    set_cat145_show_image_finish();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (noti_info_p->attr_flags & SRV_ANCS_ATTR_DATE)
    {
        timestamp_buffer = OslMalloc(sizeof(WCHAR) * 60);
        memset(timestamp_buffer, 0, sizeof(WCHAR) * 60);
        date_string((MYTIME*)&noti_info_p->date, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) time);
        mmi_ucs2cat((PS8) timestamp_buffer, (const PS8) (L" "));
        time_string((MYTIME*) &noti_info_p->date, (UI_string_type)time, DT_IDLE_SCREEN);
        mmi_ucs2cat((PS8)timestamp_buffer, (const PS8)time);
    }
    else
    {
        timestamp_buffer = NULL;
    }

    if (noti_info_p->cat_id == SRV_ANCS_CAT_MISSED_CALL ||       //missed call 
        noti_info_p->cat_id == SRV_ANCS_CAT_EMAIL ||
        (noti_info_p->cat_id == SRV_ANCS_CAT_SOCIAL && 
        (noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME) &&
        mmi_ucs2cmp((const CHAR*)noti_info_p->title, (const CHAR*)noti_info_p->app_name)))
    {
        title = (U8*) noti_info_p->title;
        app_name = (U8*) noti_info_p->app_name;
    }
    else
    {
        title = NULL;
        if(!(noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME))
        {
            app_name = (U8*) noti_info_p->title;
        }
        else
        {
            app_name = (U8*) noti_info_p->app_name;
        }
    }
    
    //show category
#if defined(__MMI_WEARABLE_DEVICE__) && defined(__MMI_TOUCH_SCREEN__)
	wgui_BTcat145_footer_area_set_no_show_button(MMI_TRUE);   //don't show delete button
    ShowBTNotiCategory145Screen_WEARABLE_DEVICE(
        title,    //show contact name or number
        NULL,
        STR_GLOBAL_DELETE,
        NULL,
        NULL,
        NULL,
        IMG_MESSAGE_UNREAD,
        app_name,  //show app name 
        (U8*)noti_info_p->msg,
        NULL,
        gui_buffer,
        (U8*)timestamp_buffer);
#else  //__MMI_WEARABLE_DEVICE__ && __MMI_TOUCH_SCREEN__
    ShowBTNotiCategory145Screen(
        NULL,
        0,
        STR_GLOBAL_OPTIONS,
        0,
        STR_GLOBAL_BACK,
        0,
        IMG_MESSAGE_UNREAD,
        NULL,
        (U8*)timestamp_buffer,
        0,
        gui_buffer);
#endif  //__MMI_WEARABLE_DEVICE__) && __MMI_TOUCH_SCREEN__
    OslMfree(noti_info_p);
    if (timestamp_buffer != NULL)
    {
        OslMfree(timestamp_buffer);
    }
}


void mmi_bt_ancs_notify_list_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 *guiBuffer;
    S32 nid_list[SRV_ANCS_MAX_NOTI_NUM];
    U32 noti_count;
    S32 hilit;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_LIST_SHOW);

    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_LIST);

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

    noti_count = srv_ancs_query_notification_count(nid_list, SRV_ANCS_GET_BY_NONE, NULL);

    if (noti_count == 0)
    {
        mmi_bt_ancs_empty_list();
    }
    else
    {
        kal_prompt_trace(MOD_MMI_CONN_APP, "[ANCS] begin to show: %d", noti_count);
        wgui_swatch_two_line_menu_list_screen(
             (PU8)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
             NULL,
             STR_GLOBAL_VIEW,
             NULL, // IMG_BTNOTIFICATON_LIST_ICON
             STR_GLOBAL_BACK,
             noti_count,
             mmi_bt_ancs_list_get_item_async,
             hilit,
             guiBuffer);
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
        //wgui_register_pen_long_tap_handler(mmi_bt_ancs_msg_list_long_tap_hdlr);
        SetLeftSoftkeyFunction(mmi_bt_ancs_msg_list_long_tap_hdlr,KEY_EVENT_LONG_PRESS);
        wgui_register_tap_callback(mmi_bt_ancs_list_tap_cb);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
    }
}

void mmi_bt_ancs_empty_list(void)
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
        (PU8)GetString(STR_ID_BTNOTIFICATION_APPLICATION_APP_NAME),
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


S32 mmi_bt_ancs_list_get_item_async(S32 start_index, gui_iconlist_menu_item *menu_data, S32 num_item)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 idx, i;
    srv_ancs_noti_info_struct* noti_info_p;
    S32 nid_list [SRV_ANCS_MAX_NOTI_NUM];
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    noti_info_p = OslMalloc(sizeof(srv_ancs_noti_info_struct));

    count = srv_ancs_query_notification_count(nid_list, SRV_ANCS_GET_BY_NONE, NULL);

    kal_prompt_trace(MOD_MMI_CONN_APP, "[ANCS] sync cb, start_index:%d, num_item:%d, count:%d", start_index, num_item, count);

    MMI_ASSERT(count > start_index);

    for (i = 0, idx = start_index; i < num_item; idx++, i++)
    {
        if (srv_ancs_query_notification_info(noti_info_p, nid_list[idx], SRV_ANCS_GET_BY_NONE, NULL))
        {
            if (noti_info_p->attr_flags & SRV_ANCS_ATTR_APP_NAME)
            {
                mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)noti_info_p->app_name, SRV_ANCS_APP_DISPLAY_NAME);
            }
            else if (noti_info_p->attr_flags & SRV_ANCS_ATTR_TITLE)
            {
                mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[0], (CHAR*)noti_info_p->title, SRV_ANCS_APP_DISPLAY_NAME);
            }
            else
            {
                mmi_ucs2cpy((CHAR*)menu_data[i].item_list[0], NULL);
            }
            if (noti_info_p->attr_flags & SRV_ANCS_ATTR_MSG)
            {
                mmi_ucs2ncpy((CHAR*)menu_data[i].item_list[1], (CHAR*)noti_info_p->msg, SRV_ANCS_APP_DISPLAY_NAME);
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
    OslMfree(noti_info_p);
    return num_item;
}

void mmi_bt_ancs_list_tap_cb(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ancs_noti_info_struct* noti_info_p;
    S32 nid_list [SRV_ANCS_MAX_NOTI_NUM];
    U32 count;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    count = srv_ancs_query_notification_count(nid_list, SRV_ANCS_GET_BY_NONE, NULL);

    if (count == 0)
    {
        return;
    }

    MMI_ASSERT(count > index);

    g_ancs_p->hilite_noti = nid_list[index];

    mmi_bt_ancs_details_launch();
}

#endif //  __MMI_BLE_ANCS_SUPPORT__

