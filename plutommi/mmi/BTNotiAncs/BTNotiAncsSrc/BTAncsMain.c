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
*  BTAncsMain.c
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
 *------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
*==============================================================================
*******************************************************************************/

#include "MMI_features.h"
#include "GlobalResDef.h"                   // STR_GLOBAL_ERROR
#ifdef 0//__MMI_BLE_ANCS_SUPPORT__
#include "BTAncsGprot.h"
#include "BTAncsprot.h"
#include "mmi_rp_srv_bt_ancs_def.h"         // EVT_ID_SRV_BT_ANCS_NOTI
#include "mmi_rp_app_ancs_def.h"
#include "mmi_frm_scenario_gprot.h"         // MMI_FRM_NODE_SMART_CLOSE_FLAG
#include "MMI_conn_app_trc.h"               // for ancs trace id
#include "mmi_rp_app_bluetooth_def.h"       // STR_BT_DISCONN_POP
#include "mmi_rp_app_btnotification_def.h"  //GRP_ID_BTNOTIFICATION_APP

mmi_bt_ancs_cntx_struct g_mmi_bt_ancs_cntx;
mmi_bt_ancs_cntx_struct* g_ancs_p = &g_mmi_bt_ancs_cntx;

mmi_ret mmi_bt_ancs_evt_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ancs_ind_evt_struct* ancs_ind_p;
    srv_ancs_noti_ind_struct* noti_p;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_BT_ANCS_NOTI:
            ancs_ind_p = (srv_ancs_ind_evt_struct*)evt;
            noti_p = (srv_ancs_noti_ind_struct*)ancs_ind_p->ptr;

            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_EVT_HD, noti_p->event_id, noti_p->noti_uid);
            
            switch (ancs_ind_p->ind_type)
            {
                case SRV_ANCS_TYPE_ADDED:
                case SRV_ANCS_TYPE_MODIFIED:
                    g_ancs_p->hilite_noti = noti_p->noti_uid;

                    mmi_frm_nmgr_notify_by_app(
                        MMI_SCENARIO_ID_BT_NOTIFY,
                        MMI_EVENT_BT_NOTIFY,
                        mmi_bt_ancs_popup_launch,
                        NULL);
                    break;
                    
                case SRV_ANCS_TYPE_REMOVED:
                    {
                        //if this notificaiton is showed in popup or detail screen . delete it
                        if (g_ancs_p->hilite_noti == noti_p->noti_uid)
                        {
                            if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP, MMI_FRM_NODE_ALL_FLAG))
                            {
                                mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP);
                            }
                            if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL, MMI_FRM_NODE_ALL_FLAG))
                            {
                                mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL);
                            }
                        }
                        //if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_LIST, MMI_FRM_NODE_ALL_FLAG))
                        if (mmi_frm_scrn_get_active_id() == SCR_ID_BT_ANCS_LIST)
                        {
                            //update the list
                            mmi_bt_ancs_list_launch();
                        }
                    }
                    break;

                case SRV_ANCS_TYPE_CONNECTED:
                    if (mmi_frm_group_is_present(GRP_ID_BTNOTIFICATION_APP))
                    {
                        //update the list
                        mmi_frm_group_close(GRP_ID_BTNOTIFICATION_APP);
                        mmi_bt_ancs_list_launch();
                    }
                    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_INFO,(WCHAR*)GetString(STR_ID_ANCS_DEV_CON));
                    break;
                    
                case SRV_ANCS_TYPE_DISCONNECTED:
                    mmi_frm_nmgr_popup(MMI_SCENARIO_ID_BT_NOTIFY, MMI_EVENT_INFO,(WCHAR*)GetString(STR_ID_ANCS_DEV_DISCON));
                    break;

                default:
                    break;
            }

            break;

        default:
            break;
    }

    return MMI_RET_OK;
}


static mmi_ret mmi_bt_ancs_notify_app_proc(mmi_event_struct *evt)
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
        /*case EVT_ID_SCRN_ACTIVE:
            {
                act_scrn = (mmi_frm_scrn_active_evt_struct*)evt;

                if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY);
                }

                if (act_scrn->scrn_id == SCR_ID_BT_ANCS_POPUP)
                {
                    mmi_bt_ancs_notify_popup_show();
                }
                else if (act_scrn->scrn_id == SCR_ID_BT_ANCS_DETAIL)
                {
                    mmi_bt_ancs_notify_details_show();
                }
                else if (act_scrn->scrn_id == SCR_ID_BT_ANCS_LIST)
                {
                    mmi_bt_ancs_notify_list_show();
                }
            }
            break;*/

        case EVT_ID_GROUP_DEINIT:
            break;
            
        default:
            break;
    }
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_ancs_popup_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_active_evt_struct* act_scrn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                act_scrn = (mmi_frm_scrn_active_evt_struct*)evt;
    
                if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY);
                }
    
                mmi_bt_ancs_notify_popup_show();
            }
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}

static mmi_ret mmi_bt_ancs_details_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *noti_to_delete;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            noti_to_delete = (S32 *)(evt->user_data);
        
             if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
             {
                 mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY);
             }
        
             mmi_bt_ancs_notify_details_show(*noti_to_delete);
        }
        break;
        
        case EVT_ID_SCRN_DEINIT:
        {
            noti_to_delete = (S32 *)(evt->user_data);
            
            //If the notification is viewed by popup, delete it
            srv_ancs_delete_notification(*noti_to_delete, SRV_ANCS_GET_BY_NONE, NULL);
            
            OslMfree(noti_to_delete);
        }
        break;
        
        default:
            break;
    }
    
    return MMI_RET_OK;
}


static mmi_ret mmi_bt_ancs_list_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_frm_scrn_active_evt_struct* act_scrn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                act_scrn = (mmi_frm_scrn_active_evt_struct*)evt;
    
                if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY, MMI_FRM_NODE_ALL_FLAG))
                {
                    mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_DUMMY);
                }
    
                mmi_bt_ancs_notify_list_show();
            }
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}

void mmi_bt_ancs_popup_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP) == MMI_FALSE)
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_ANCS_APP,
            mmi_bt_ancs_notify_app_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (SCR_ID_BT_ANCS_POPUP == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_DUMMY);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP);
    }

    mmi_frm_scrn_create(GRP_ID_BT_ANCS_APP, 
        SCR_ID_BT_ANCS_POPUP, 
        mmi_bt_ancs_popup_scrn_proc,
        NULL);
}


void mmi_bt_ancs_details_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 *noti_to_delete;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP) == MMI_FALSE)
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_ANCS_APP,
            mmi_bt_ancs_notify_app_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (SCR_ID_BT_ANCS_DETAIL == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_DUMMY);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL);
    }

    noti_to_delete = OslMalloc(sizeof(S32));
    memcpy(noti_to_delete, &(g_ancs_p->hilite_noti), sizeof(S32));
    
    mmi_frm_scrn_create(GRP_ID_BT_ANCS_APP, 
        SCR_ID_BT_ANCS_DETAIL, 
        mmi_bt_ancs_details_scrn_proc,
        noti_to_delete);

}

void mmi_bt_ancs_list_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP) == MMI_FALSE)
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_ANCS_APP,
            mmi_bt_ancs_notify_app_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (SCR_ID_BT_ANCS_LIST == mmi_frm_scrn_get_active_id())
    {
        mmi_frm_display_dummy_screen_ex(mmi_frm_group_get_active_id(), SCR_ID_DUMMY);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_LIST, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_LIST);
    }

    mmi_frm_scrn_create(GRP_ID_BT_ANCS_APP, 
        SCR_ID_BT_ANCS_LIST, 
        mmi_bt_ancs_list_scrn_proc,
        NULL);

}

void mmi_bt_ancs_delete_notification(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    srv_ancs_delete_notification(g_ancs_p->hilite_noti, SRV_ANCS_GET_BY_NONE, NULL);

    if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_DETAIL);
    }
}

void mmi_bt_ancs_launch(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
    
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_bt_ancs_list_launch();
#else
	mmi_bt_ancs_details_launch();
#endif /*__MMI_WEARABLE_DEVICE__*/
}

#endif /* __MMI_BLE_ANCS_SUPPORT__ */


/* Support ANCSv1.1, incoming call*/
#ifdef __MMI_ANCS_IOS8_SUPPORT__
#include "mmi_frm_events_gprot.h"
#include "BTNotiAncsSrvGprot.h"
#include "mmi_rp_srv_bt_ancs_def.h"
#include "BTAncsProt.h"
#include "mmi_rp_app_ancs_def.h"
#include "wgui_categories_CM.h" //WGUI_CATE_MOMT_INCOMING_CALL
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
#include "mmi_rp_app_scr_locker_def.h" //EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING
#endif
#include "GpioSrvGprot.h"
#ifdef __MMI_HF_SUPPORT__
#include "UcmSrvGprot.h"
#include "UcmBTSrvGprot.h"
#endif


ancs_noti_cntx_struct g_mmi_bt_ancs_cntx;
ancs_noti_cntx_struct* g_ancs_p = &g_mmi_bt_ancs_cntx;

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_incoming_call_left_hdle
 * DESCRIPTION
 *  Handle accept key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ancs_incoming_call_left_hdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_MMI, "[ANCS_Li]Incoming call left hdle, addr = %d, noti_id = %d", g_ancs_p->bt_addr.lap, g_ancs_p->noti_info.noti_id);
    srv_ancs_perform_notification_action(&(g_ancs_p->bt_addr), g_ancs_p->noti_info.noti_id, SRV_ANCS_ACTION_POSITIVE);

    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
    {
        mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
    }
    
    memset(g_ancs_p, 0, sizeof(ancs_noti_cntx_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_incoming_call_right_hdle
 * DESCRIPTION
 *  Handle reject key in the incoming call screen.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ancs_incoming_call_right_hdle(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_MMI, "[ANCS_Li]Incoming call right hdle, addr = %d, noti_id = %d", g_ancs_p->bt_addr.lap, g_ancs_p->noti_info.noti_id);
    srv_ancs_perform_notification_action(&(g_ancs_p->bt_addr), g_ancs_p->noti_info.noti_id, SRV_ANCS_ACTION_NEGATIVE);

    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
    {
        mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
    }
    
    memset(g_ancs_p, 0, sizeof(ancs_noti_cntx_struct));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_notify_popup_show
 * DESCRIPTION
 *  show the incoming call screen
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_bt_ancs_notify_popup_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 noti_str_id = STR_ID_ANCS_INCOMING_CALL;
    U8* guiBuffer = NULL;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_POP_SHOW, g_ancs_p->noti_info.noti_id);
    
    guiBuffer = mmi_frm_scrn_get_gui_buf(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP);
    ShowCategory17Screen_ext(
            STR_ID_ANCS_ACCEPT,
            STR_ID_ANCS_REJECT,
            noti_str_id,
            (U8*)g_ancs_p->noti_info.title, //name or number
            IMG_ID_ANCS_INCOMING,
            WGUI_CATE_MOMT_INCOMING_CALL,
            guiBuffer);
    SetInComingAccepthandler(mmi_bt_ancs_incoming_call_left_hdle);
    SetInComingRejecthandler(mmi_bt_ancs_incoming_call_right_hdle);

    //play vibration
    srv_vibrator_post_req(VIB_PATTERN_1, PLAY_REPEAT);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_notify_app_proc
 * DESCRIPTION
 *   ANCS incoming call group proc
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_ancs_notify_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret result = MMI_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch(evt->evt_id)
    {
        case EVT_ID_TOUCHSCREEN_MOVE_RIGHT:
            result = MMI_RET_ERR;
            
        case EVT_ID_GROUP_DEINIT:
            srv_vibrator_post_req(VIB_PATTERN_1, PLAY_STOP);
            srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
            break;
            
        default:
            break;
    }
    return result;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_popup_launch
 * DESCRIPTION
 *  ANCS incoming call screen proc
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static mmi_ret mmi_bt_ancs_notify_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    //mmi_frm_scrn_active_evt_struct* act_scrn;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
            {
                mmi_bt_ancs_notify_popup_show();
            }
            break;

        default:
            break;
    }
    
    return MMI_RET_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_popup_launch
 * DESCRIPTION
 *  launch the incoming call screen
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
 static MMI_BOOL mmi_bt_ancs_popup_launch(mmi_scenario_id scen_id, void *arg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP) == MMI_FALSE)
    {
        mmi_frm_group_create_ex(
            GRP_ID_ROOT,
            GRP_ID_BT_ANCS_APP,
            mmi_bt_ancs_notify_grp_proc,
            NULL,
            MMI_FRM_NODE_SMART_CLOSE_FLAG);
    }

    if (mmi_frm_scrn_is_present(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP, MMI_FRM_NODE_ALL_FLAG))
    {
        mmi_frm_scrn_close(GRP_ID_BT_ANCS_APP, SCR_ID_BT_ANCS_POPUP);
    }

    mmi_frm_scrn_create(GRP_ID_BT_ANCS_APP, 
        SCR_ID_BT_ANCS_POPUP, 
        mmi_bt_ancs_notify_scrn_proc,
        NULL);

    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_ancs_evt_hdlr
 * DESCRIPTION
 *  Handler of ancs indication
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_bt_ancs_evt_hdlr(mmi_event_struct* evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_ancs_ind_evt_struct* ancs_ind_p;
    mmi_ret result = MMI_RET_OK;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SRV_ANCS_NOTI_IND:
            {
                ancs_ind_p = (srv_ancs_ind_evt_struct*)evt;
                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_EVT_HD, evt->evt_id, ancs_ind_p->ind_type);
                
                switch (ancs_ind_p->ind_type)
                {
                    case SRV_ANCS_TYPE_ADDED:
                    case SRV_ANCS_TYPE_MODIFIED:
                        {
                            srv_ancs_add_evt_struct* noti_add_p;
                            
                            noti_add_p = (srv_ancs_add_evt_struct*)ancs_ind_p->ptr;
                            if (noti_add_p->noti_info.cat_id == SRV_ANCS_CAT_INCOMING_CALL)
                            {
                                memcpy(&(g_ancs_p->bt_addr), &(noti_add_p->bt_addr), sizeof(srv_bt_cm_bt_addr));
                                memcpy(&(g_ancs_p->noti_info), &(noti_add_p->noti_info), sizeof(srv_ancs_noti_info_struct));
                            
                                mmi_frm_nmgr_notify_by_app(
                                    MMI_SCENARIO_ID_BT_NOTIFY,
                                    MMI_EVENT_BT_NOTIFY,
                                    mmi_bt_ancs_popup_launch,
                                    NULL);
                            }
                        }
                        break;
                        
                    case SRV_ANCS_TYPE_REMOVED:
                        {
                            srv_ancs_remove_evt_struct* noti_remov_p;

                            noti_remov_p = (srv_ancs_remove_evt_struct*)ancs_ind_p->ptr;
                            if (noti_remov_p->bt_addr.lap == g_ancs_p->bt_addr.lap &&
                                noti_remov_p->bt_addr.nap == g_ancs_p->bt_addr.nap &&
                                noti_remov_p->bt_addr.uap == g_ancs_p->bt_addr.uap &&
                                noti_remov_p->noti_id == g_ancs_p->noti_info.noti_id)
                            {
                                if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
                                {
                                    mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
                                }
                                memset(g_ancs_p, 0, sizeof(ancs_noti_cntx_struct));
                            }
                        }
                        break;

                    case SRV_ANCS_TYPE_CONNECTED:
                        break;
                        
                    case SRV_ANCS_TYPE_DISCONNECTED:
                        break;

                    default:
                        break;
                }
            }
            break;

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
        case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
            {
                if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
                {
                    result = MMI_RET_ERR; //not allow to lock screen
                }
            }
            break;
#endif /* __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__ */

        case EVT_ID_GPIO_BEFORE_LCD_SLEEP_IN:
            {
                if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
                {
                    result = MMI_RET_ERR; //not allow to turn off the backlight
                }
            }
            break;

#ifdef __MMI_HF_SUPPORT__
        case EVT_ID_SRV_UCM_BT_INDICATION:
            {
                srv_ucm_bt_ind_evt_struct *event_ucm = (srv_ucm_bt_ind_evt_struct *)evt;
                switch (event_ucm->ind_type)
                {
                    case SRV_UCM_BT_INCOMING_CALL_IND:
                    case SRV_UCM_BT_OUTGOING_CALL_IND:
                    case SRV_UCM_BT_REFRESH_IND:
                        {
                            if (mmi_frm_group_is_present(GRP_ID_BT_ANCS_APP))
                            {
                                mmi_frm_group_close(GRP_ID_BT_ANCS_APP);
                                MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_ANCS_EVT_HD_UCM, event_ucm->ind_type);
                            }         
                        }
                        break;
                    default:
                        break;
                }
            }
            break;
#endif /*__MMI_HF_SUPPORT__*/

        default:
            break;
    }

    return result;
}

#endif /* __MMI_ANCS_IOS8_SUPPORT__ */
