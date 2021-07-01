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
 *  PhoneBookpbapcWearable.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  PBAPC
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
 ****************************************************************************/


#include "MMI_features.h"

#if defined(__MMI_BT_PBAP_CLIENT__)
#include "PhbpbapSrvGprot.h"

#if defined(__MMI_PHB_PBAPC_SYNC_CONTACT__) && defined(__MMI_WEARABLE_DEVICE__)
#include "gui_typedef.h"
#include "PhoneBookpbapcWearable.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "wgui_fixed_menus.h"
#include "wgui_categories_util.h"
#include "wgui_categories_list.h"
#include "BTMMIScrGprots.h"
//#include ".\..\..\plutommi\Framework\Scenario\mmi_frm_scenario_prot.h"
#include "CommonScreensResDef.h"
#include "wgui_include.h"
#include "BtcmSrvGprot.h"
#include "btcmsrvgprot.h"
#include "BTMMIScrGprots.h"

/* global */
mmi_phb_pbapc_cntx_struct g_mmi_phb_pbapc_cntx;
char show_first_item_flag = 0;
S32 g_phb_pbapc_enable_first_item = 0;


/* extern func */
extern void mmi_phb_launch_entry(void);

extern void mmi_phb_launch_exit(void);

/* func */
mmi_phb_pbapc_cntx_struct *mmi_phb_pbapc_get_cntx()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return &g_mmi_phb_pbapc_cntx;
}

extern void (*update_data_function) ();
mmi_pen_point_struct down_pos;
extern void gui_ssp_update_first_item_data(void);
extern void gui_ssp_update_context(void);
extern MMI_BOOL need_gui_buff;


void mmi_pbapc_pen_down_hdlr(mmi_pen_point_struct pos)
{
    down_pos = pos;
}


void mmi_pbapc_pen_move_hdlr(mmi_pen_point_struct pos)
{
    if (pos.y > down_pos.y)
    {
        show_first_item_flag = 1;
        mmi_phb_pbapc_show_list();
    }
}


void mmi_pbapc_pen_up_hdlr(mmi_pen_point_struct pos)
{
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (1 == show_first_item_flag)
    {
        gui_start_timer(2000, gui_ssp_update_first_item_data); 
        wgui_register_general_pen_handler();
    }
}


void mmi_phb_pbapc_entry_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_qsearch_filter_struct qsearch_filter;
    srv_bt_cm_bt_addr bt_addr;
    U8 bt_index;
    mmi_ret gid;
    S32 ret = -1;
    mmi_ret cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    /* reg evt */
    mmi_frm_cb_reg_event(EVT_ID_DIALER_DISCONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
    mmi_frm_cb_reg_event(EVT_ID_DIALER_CONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);

    if (!mmi_frm_scrn_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_PBAPC_BT,
            mmi_phb_launch_exit,
            mmi_phb_launch_entry,
            MMI_FRM_FULL_SCRN
            ))
    {
        return;
    }

    wgui_set_menu_empty_string_by_id(STR_ID_PHB_PBAPC_NO_CONTACT);

    //g_phb_pbapc_enable_first_item = 1;

    phb_pbapc_cntx_p->bt_index = 0;
    phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_MAIN;
    //show_first_item_flag = 0;
    phb_pbapc_cntx_p->flag_ext |= 0x02;

    bt_index = phb_pbapc_cntx_p->bt_index;

    //update_data_function = mmi_phb_pbapc_show_list;

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ENTY_LIST, GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ENTY_LIST_I, phb_pbapc_cntx_p->flag_ext, phb_pbapc_cntx_p->flag[bt_index]);
    if (mmi_phb_pbapc_is_connect())
    {
        if (phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_LOAD)
        {
            /* load done, just build list */
            qsearch_filter.key_word = NULL;
            qsearch_filter.key_len = 0;
            qsearch_filter.input_mode = 0;
            phb_pbapc_cntx_p->contact_count = srv_phb_pbapc_build_contact_list(bt_index,
                                                                               &qsearch_filter,
                                                                               phb_pbapc_cntx_p->contact_array,
                                                                               SRV_PHB_PBAPC_CONTACT_COUNT);

            mmi_phb_pbapc_show_list();
        }
        else if (phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_BG_LOADING)
        {
            /* remove BG flag */
            phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_BG_LOADING;
            /* loading, just show processing bar */
            mmi_phb_pbapc_show_loading(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
        }
        else
        {
            mmi_phb_pbapc_sync_contact();
        }

        phb_pbapc_cntx_p->flag_ext &= ~0x04;
    }
    else    /* profile doesn't connect case */
    {
        if (phb_pbapc_cntx_p->flag_ext & 0x04)
        {
            qsearch_filter.key_word = NULL;
            qsearch_filter.key_len = 0;
            qsearch_filter.input_mode = 0;
            phb_pbapc_cntx_p->contact_count = srv_phb_pbapc_build_contact_list(bt_index,
                                                                               &qsearch_filter,
                                                                               phb_pbapc_cntx_p->contact_array,
                                                                               SRV_PHB_PBAPC_CONTACT_COUNT);
            mmi_phb_pbapc_show_list();
        }
        else
        {
            if (mmi_bt_dialer_app_is_connected())
            {
                mmi_phb_pbapc_show_fail();
            }
            else /* btd doesn't connect */
            {
                mmi_phb_pbapc_show_connect();
            }
        }
    }
}


void mmi_phb_pbapc_exit_list(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->flag_ext &= ~0x02;

    //g_phb_pbapc_enable_first_item = 0;

    wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);

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
    //wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
}


void mmi_phb_pbapc_entry_list_tab(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_qsearch_filter_struct qsearch_filter;
    srv_bt_cm_bt_addr bt_addr;
    U8 bt_index;
    mmi_ret gid;
    S32 ret = -1;
    mmi_ret cui_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    /* reg evt */
    mmi_frm_cb_reg_event(EVT_ID_DIALER_DISCONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);
    mmi_frm_cb_reg_event(EVT_ID_DIALER_CONN_EVENT_ID, mmi_phb_pbapc_notify_evt_hdlr, (void *)0xbabe0004);

#ifdef __MMI_TAB_BAR_SUPPORT_TAB_PAGE__
    if (!cui_tab_enter(
            GRP_ID_PHB_MAIN,
            SCR_ID_PHB_PBAP_LIST,
            mmi_phb_pbapc_exit_list,
            mmi_phb_pbapc_entry_list_tab,
            MMI_FRM_FULL_SCRN
            ))
#else
    if (!mmi_frm_scrn_tab_page_enter(
            GRP_ID_PHB_MAIN,
            SCR_PBOOK_MAIN_MENU,
            SCR_ID_PHB_PBAP_LIST,
            mmi_phb_pbapc_exit_list,
            mmi_phb_pbapc_entry_list_tab,
            MMI_FRM_TAB_PAGE
            ))
#endif
    {
        return;
    }

    wgui_set_menu_empty_string_by_id(STR_ID_PHB_PBAPC_NO_CONTACT);

    //g_phb_pbapc_enable_first_item = 1;

    phb_pbapc_cntx_p->bt_index = 0;
    phb_pbapc_cntx_p->parent_id = GRP_ID_PHB_MAIN;
    //show_first_item_flag = 0;
    phb_pbapc_cntx_p->flag_ext |= 0x02;

    bt_index = phb_pbapc_cntx_p->bt_index;

    //update_data_function = mmi_phb_pbapc_show_list;

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ENTY_LIST_TAB, GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ENTY_LIST_TAB_I, phb_pbapc_cntx_p->flag_ext, phb_pbapc_cntx_p->flag[bt_index]);

    if (mmi_phb_pbapc_is_connect())
    {
        if (phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_LOAD)
        {
            /* load done, just build list */
            qsearch_filter.key_word = NULL;
            qsearch_filter.key_len = 0;
            qsearch_filter.input_mode = 0;
            phb_pbapc_cntx_p->contact_count = srv_phb_pbapc_build_contact_list(bt_index,
                                                                               &qsearch_filter,
                                                                               phb_pbapc_cntx_p->contact_array,
                                                                               SRV_PHB_PBAPC_CONTACT_COUNT);

            mmi_phb_pbapc_show_list();
        }
        else if (phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_BG_LOADING)
        {
            /* remove BG flag */
            phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_BG_LOADING;
            /* loading, just show processing bar */
            mmi_phb_pbapc_show_loading(GRP_ID_PHB_MAIN, SCR_ID_PHB_PROCESSING);
        }
        else
        {
            mmi_phb_pbapc_sync_contact();
        }

        phb_pbapc_cntx_p->flag_ext &= ~0x04;
    }
    else    /* profile doesn't connect case */
    {
        if (phb_pbapc_cntx_p->flag_ext & 0x04)
        {
            qsearch_filter.key_word = NULL;
            qsearch_filter.key_len = 0;
            qsearch_filter.input_mode = 0;
            phb_pbapc_cntx_p->contact_count = srv_phb_pbapc_build_contact_list(bt_index,
                                                                               &qsearch_filter,
                                                                               phb_pbapc_cntx_p->contact_array,
                                                                               SRV_PHB_PBAPC_CONTACT_COUNT);
            mmi_phb_pbapc_show_list();
        }
        else
        {
            if (mmi_bt_dialer_app_is_connected())
            {
                mmi_phb_pbapc_show_fail();
            }
            else /* btd doesn't connect */
            {
                mmi_phb_pbapc_show_connect();
            }
        }
    }
}


static void mmi_phb_pbapc_show_loading(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->load_gid = parent_id;
    phb_pbapc_cntx_p->load_sid = scrn_id;

    mmi_phb_pbapc_entry_show_loading();
}


static void mmi_phb_pbapc_show_connect()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    ret = mmi_frm_scrn_enter(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_CONNECT, NULL, mmi_phb_pbapc_show_connect, MMI_FRM_FULL_SCRN);

    if (MMI_TRUE != ret)
    {
        return;
    }

    wgui_showcategory6333_screen(
                                NULL,
                                (UI_string_type)GetString(STR_GLOBAL_CONNECT),
                                (UI_string_type)GetString(STR_GLOBAL_CANCEL),
                                (UI_string_type)GetString(STR_ID_PHB_PBAPC_NOT_CONNECTED),
                                NULL);

    SetLeftSoftkeyFunction(mmi_phb_pbapc_connect_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_pbapc_connect_rsk, KEY_EVENT_UP);
}


static void mmi_phb_pbapc_show_fail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    ret = mmi_frm_scrn_enter(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL, NULL, mmi_phb_pbapc_show_fail, MMI_FRM_FULL_SCRN);

    if (MMI_TRUE != ret)
    {
        return;
    }

    wgui_showcategory6333_screen(
                                NULL,
                                (UI_string_type)GetString(STR_ID_PHB_PBAPC_RETRY),
                                (UI_string_type)GetString(STR_GLOBAL_CANCEL),
                                (UI_string_type)GetString(STR_ID_PHB_PBAPC_FAIL_SYNC),
                                NULL);

    SetLeftSoftkeyFunction(mmi_phb_pbapc_fail_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_pbapc_fail_rsk, KEY_EVENT_UP);
}


static void mmi_phb_pbapc_cancel_sync()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bt_index;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    bt_index = phb_pbapc_cntx_p->bt_index;

    phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_LOADING;
    phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_LOAD;

    srv_phb_pbapc_load_contact_cancel(bt_index);

    mmi_phb_pbapc_show_loading_abort(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid);
}


static void mmi_phb_pbapc_entry_show_loading()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
    U16 percentage;
    U16 sync_count;
    U16 total_count;
    U8 bt_index;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    ret = mmi_frm_scrn_enter(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid, NULL, mmi_phb_pbapc_entry_show_loading, MMI_FRM_FULL_SCRN);

    if (MMI_TRUE != ret)
    {
        return;
    }

    //wgui_cat6003_show(STR_ID_PHB_PBAPC_BG, STR_GLOBAL_STOP,(WCHAR*)GetString(STR_GLOBAL_LOADING), NULL, 0);
    wgui_showcategory6335_screen(STR_ID_PHB_PBAPC_HIDE, STR_GLOBAL_CANCEL, (WCHAR*)GetString(STR_ID_PHB_PBAPC_SYNC), 0);

    wgui_cat6335_update_all((WCHAR*)GetString(STR_ID_PHB_PBAPC_SYNC), 0);

    bt_index = phb_pbapc_cntx_p->bt_index;

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_SHOW_LOAD, phb_pbapc_cntx_p->flag_ext, phb_pbapc_cntx_p->flag[bt_index]);

    if (phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_LOADING)
    {
        srv_phb_pbapc_get_sync_info(bt_index, &sync_count, &total_count);

        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_SHOW_LOAD_I, sync_count, total_count);

        if (total_count)
        {
            if (sync_count >= total_count)
            {
                percentage = 100;
            }
            else
            {
                percentage = (sync_count * 100) / total_count; 
            }

            //wgui_cat6003_update_all((WCHAR*)GetString(STR_GLOBAL_LOADING), NULL, percentage);
            wgui_cat6335_update_all((WCHAR*)GetString(STR_ID_PHB_PBAPC_SYNC), percentage);
        }
    }

    SetLeftSoftkeyFunction(mmi_phb_pbapc_loading_lsk, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_phb_pbapc_loading_rsk, KEY_EVENT_UP);
}


static void mmi_phb_pbapc_loading_lsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    bt_index = phb_pbapc_cntx_p->bt_index;
    phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_BG_LOADING;

    mmi_frm_group_close(GRP_ID_PHB_MAIN);
}


static void mmi_phb_pbapc_connect_lsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //phb_pbapc_cntx_p->flag_ext &= ~0x08;

    gid = GRP_ID_PHB_MAIN;
    mmi_bt_dialer_show_popup(gid);

    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_CONNECT);
}


static void mmi_phb_pbapc_fail_lsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ret gid;
    S32 ret = -1, ret1;
    mmi_ret cui_id;
    srv_bt_cm_bt_addr bt_addr;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //phb_pbapc_cntx_p->flag_ext &= ~0x08;

    bt_index = phb_pbapc_cntx_p->bt_index;
    /* connect pbapc */
    ret = srv_phb_pbapc_get_btd_addr(&bt_addr, bt_index);

    gid = GRP_ID_PHB_MAIN;
    cui_id = cui_bt_dialer_connecting_create(gid);
    if (cui_id != GRP_ID_INVALID)
    {
        cui_bt_dialer_connecting_run(cui_id);
        phb_pbapc_cntx_p->cui_id = cui_id;
        ret1 = srv_pbapc_connect(&bt_addr, mmi_phb_pbapc_con_profile_cb);

        if (ret1 != SRV_PBAPC_RET_OK)
        {
            mmi_popup_display_ext(
                STR_GLOBAL_CURRENTLY_NOT_AVAILABLE,
                MMI_EVENT_FAILURE,
                NULL);
        }
        //mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);
    }
}


static void mmi_phb_pbapc_loading_rsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    bt_index = phb_pbapc_cntx_p->bt_index;

    /* cancel */
    srv_phb_pbapc_load_contact_cancel(phb_pbapc_cntx_p->bt_index);

    phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_LOAD;
    phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_LOADING;

    mmi_phb_pbapc_show_loading_abort(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid);
}


static void mmi_phb_pbapc_connect_rsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->flag_ext |= 0x04;

    phb_pbapc_cntx_p->flag_ext &= ~0x08;

    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_CONNECT);
}


static void mmi_phb_pbapc_fail_rsk()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->flag_ext |= 0x04;

    phb_pbapc_cntx_p->flag_ext &= ~0x08;

    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);
}


static void mmi_phb_pbapc_con_profile_cb(srv_bt_cm_bt_addr *dev_addr,
                                                 srv_bt_cm_connection_type conn_type,
                                                 MMI_BOOL result,
                                                 MMI_BOOL is_connect,
                                                 MMI_BOOL is_indicate)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 bt_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (!result)
    {
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
        //mmi_phb_pbapc_show_fail();

        //return;
    }
    else
    {
        phb_pbapc_cntx_p->flag_ext &= ~0x08;
        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);
    }

    cui_bt_dialer_connecting_close(phb_pbapc_cntx_p->cui_id);
    phb_pbapc_cntx_p->cui_id = GRP_ID_INVALID;
}


static void mmi_phb_pbapc_show_loading_abort(MMI_ID parent_id, MMI_ID scrn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    mmi_frm_scrn_close(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid);

    phb_pbapc_cntx_p->load_gid = 0;
    phb_pbapc_cntx_p->load_sid = 0;
}


static void mmi_phb_pbapc_show_list()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 *gui_buffer = NULL;
    U8 bt_index = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

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
                #ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
                #else
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
                #ifdef __MMI_TELEPHONY_SUPPORT__
/* under construction !*/
                #else
/* under construction !*/
                #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
    wgui_cat1032_show(
                (WCHAR*) GetString(STR_SCR_PBOOK_VIEW_CAPTION),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                NULL,
                NULL,
                NULL,
                NULL,
                phb_pbapc_cntx_p->contact_count + 1,
                mmi_phb_pbapc_list_get_item,
                NULL,
                0,
            #ifdef __MMI_TELEPHONY_SUPPORT__
                1,
            #else
                0,
            #endif
                0,
                0,
                gui_buffer,
                NULL);

    if ((phb_pbapc_cntx_p->flag_ext & 0x01))
    {
        phb_pbapc_cntx_p->flag_ext &= ~0x01;

        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_SHOW_LIST, phb_pbapc_cntx_p->jmp_pos);
        asyncdynamic_list_goto_item_ex(phb_pbapc_cntx_p->jmp_pos + 1);
    }
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_pbapc_list_tap_callback);
    /*if (1 == show_first_item_flag || 0 != phb_pbapc_cntx_p->contact_count)
        {
            wgui_register_general_pen_handler();
            gui_start_timer(2000, gui_ssp_update_first_item_data); 
        }
        else */
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


static S32 mmi_phb_pbapc_load_cb(srv_phb_pbapc_load_contact_rsp *load_rsp, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bt_index;
    MMI_ID active_id;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;
    U16 sync_count = 0;
    U16 total_count = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    bt_index = phb_pbapc_cntx_p->bt_index;

    phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_LOAD;
    phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_LOADING;

    if(!(phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_BG_LOADING))
    {
        mmi_frm_get_active_scrn_id(&group_id, &scrn_id);
        srv_phb_pbapc_get_sync_info(bt_index, &sync_count, &total_count);
        //wgui_cat6003_update_all((WCHAR*)GetString(STR_GLOBAL_LOADING), NULL, 100);

        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_LOAD_CB, sync_count, total_count);

        if (phb_pbapc_cntx_p->load_gid == group_id &&
            phb_pbapc_cntx_p->load_sid == scrn_id)
        {
            if (load_rsp->ret == SRV_PHB_PBAPC_RET_OK &&
                total_count &&
                sync_count)
            {
                wgui_cat6335_update_all((WCHAR*)GetString(STR_ID_PHB_PBAPC_SYNC), 100);

            }
        }

        mmi_phb_pbapc_show_loading_abort(phb_pbapc_cntx_p->load_gid, phb_pbapc_cntx_p->load_sid);
    }
    else
    {

    }

    phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_BG_LOADING;

    return 0;
}


static void mmi_phb_pbapc_sync_contact()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bt_index;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    bt_index = phb_pbapc_cntx_p->bt_index;

    mmi_frm_cb_reg_event(EVT_ID_PHB_PBAPC_SYNC_STATUS_UPDATE, mmi_phb_pbapc_notify_evt_hdlr, NULL);

    if (phb_pbapc_cntx_p->flag_ext & 0x02)
    {
        mmi_phb_pbapc_show_loading(phb_pbapc_cntx_p->parent_id, SCR_ID_PHB_PROCESSING);
    }
    else
    {
        phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_BG_LOADING;
    }

    phb_pbapc_cntx_p->flag[bt_index] &= ~MMI_PHB_PBAPC_FLAG_LOAD;
    phb_pbapc_cntx_p->flag[bt_index] |= MMI_PHB_PBAPC_FLAG_LOADING;
    srv_phb_pbapc_load_contact(phb_pbapc_cntx_p->bt_index, mmi_phb_pbapc_load_cb, phb_pbapc_cntx_p);

    /* kill view group & quick search group */
    if (mmi_frm_group_is_present(GRP_ID_PHB_PBAPC_ALPHA_SEARCH))
    {
        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_SYNC_CON, GRP_ID_PHB_PBAPC_ALPHA_SEARCH);
        mmi_frm_group_close(GRP_ID_PHB_PBAPC_ALPHA_SEARCH);
    }
    if (mmi_frm_group_is_present(GRP_ID_PHB_PBAPC_VIEW_CONTACT))
    {
        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_SYNC_CON_I, GRP_ID_PHB_PBAPC_VIEW_CONTACT);
        mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
    }
}


static MMI_BOOL mmi_phb_pbapc_is_connect()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 bt_index;
    MMI_BOOL ret = MMI_FALSE;
    srv_bt_cm_bt_addr addr;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    S32 result = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    bt_index = phb_pbapc_cntx_p->bt_index;
    result = srv_phb_pbapc_get_btd_addr(&addr, bt_index);

    if (result == SRV_PHB_PBAPC_RET_OK)
    {
        ret = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_PBAPC_CONNECTION, &addr);
    }

#if !defined(__MTK_TARGET__)
    return MMI_TRUE;
#endif
    return ret;
}


static S32 mmi_phb_pbapc_list_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
       mmi_phb_pbapc_list_get_item_int((item_index + index), menu_data[index].item_list[0], &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
    }

    return data_size;
}


static void mmi_phb_pbapc_list_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    srv_phb_pbapc_list_entry_struct *pse_contact = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

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
    #endif
    if (item_index == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_PBAPC_SYNC_PHONE), MAX_SUBMENU_CHARACTERS);
    }
    else
    {
        srv_phb_pbapc_get_name(phb_pbapc_cntx_p->bt_index, phb_pbapc_cntx_p->contact_array[item_index - 1], str_buff, SRV_PHB_PBAPC_NAME_LENGTH);
    }

    if (str_buff[0] == 0)
    {
        mmi_ucs2ncpy((CHAR*) str_buff, GetString(STR_ID_PHB_UNNAMED), MAX_SUBMENU_CHARACTERS);
    }
}


mmi_ret mmi_phb_pbapc_menu_cui_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret ret = MMI_RET_DONT_CARE;
    cui_menu_event_struct *menu_evt = (cui_menu_event_struct*)evt;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    switch (evt->evt_id)
    {
        case EVT_ID_CUI_MENU_ITEM_SELECT:
        {
            break;
        }

        case EVT_ID_CUI_MENU_CLOSE_REQUEST:
        {
            cui_menu_close(menu_evt->sender_id);
            ret = MMI_RET_OK;
            break;
        }

        default:
        {
            ret = MMI_RET_DONT_CARE;
            break;
        }
    }

    return ret;
}


static void cui_phb_pbapc_view_contact(mmi_id parent_id, U8 bt_index, U16 contact_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_pbapc_cntx_p->index = bt_index;
    phb_pbapc_cntx_p->cid = contact_id;

    mmi_phb_pbapc_get_info(&(phb_pbapc_cntx_p->pse_phb));

    mmi_frm_group_create_ex(parent_id, GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_phb_pbapc_view_contact_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAP_VIEW_CONTACT_DETAIL, mmi_phb_pbapc_view_contact_scrn_proc, NULL);
}


static MMI_RET mmi_phb_pbapc_view_contact_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;

        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_phb_pbapc_show_contact_detail();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
            
        break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        default:
         break;
     }

    return MMI_RET_OK;
}


static void mmi_phb_pbapc_get_info(mmi_phb_pbapc_phb_info_struct *phb_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0;
    U16 cid;
    srv_phb_pbapc_btd_enum bt_index;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    memset(phb_info, 0x00, sizeof(mmi_phb_pbapc_phb_info_struct));
    bt_index = phb_pbapc_cntx_p->index;
    cid = phb_pbapc_cntx_p->cid;
    //phb_info->num_count = srv_phb_pbapc_get_number_count(bt_index, cid);
    srv_phb_pbapc_get_name(bt_index, cid, phb_info->name, SRV_PHB_PBAPC_NAME_LENGTH);
    for (i = 0; i < 4; i++)
    {
        if (srv_phb_pbapc_get_number(bt_index, cid, i, phb_info->num[i].number, &phb_info->num[i].type, SRV_PHB_PBAPC_NUMBER_LENGTH))
        {
            phb_info->num_count++;
        }
    }
}


static S32 mmi_phb_pbapc_view_get_item(S32 start_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    S32 i = 0, k = 0;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_phb_pbapc_phb_info_struct *phb_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_info = &(phb_pbapc_cntx_p->pse_phb);

    if (phb_info->num_count == 0)
    {
        mmi_ucs2cpy((S8*)menu_data[k].item_list[0], GetString(STR_ID_PHB_PBAPC_NO_NUMBER));
        menu_data[k].item_list[1] = L'\0';

        i = 1;
    }
    else
    {
        for (i = 0; i < data_size; ++i)
        {
            k = start_index + i;
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
            #endif
            //mmi_ucs2cpy((S8*)menu_data[k].item_list[0], (S8*)GetString(mmi_phb_pbapc_get_num_type(phb_info->num[k].type)));

            //mmi_ucs2cpy((S8*)menu_data[k].item_list[1], (S8*)phb_info->num[k].number);
            mmi_ucs2cpy((S8*)menu_data[i].item_list[0], (S8*)GetString(mmi_phb_pbapc_get_num_type(phb_info->num[k].type)));

            mmi_ucs2cpy((S8*)menu_data[i].item_list[1], (S8*)phb_info->num[k].number);

        }
    }

    return i;
}


static void mmi_phb_pbapc_show_contact_detail()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    S32 highlight_item = 0;
    U8 *gui_buffer = NULL;
    S32 item_num = 0;
    mmi_phb_pbapc_phb_info_struct *phb_info = NULL;
    S32 i = 0, k = 0;
    MMI_BOOL empty = MMI_FALSE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();
    phb_info = &(phb_pbapc_cntx_p->pse_phb);

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    RegisterHighlightHandler(mmi_phb_pbapc_view_contact_highlight_hdlr);

    wgui_fixed_list_register_get_flags_handler(mmi_phb_pbapc_set_view_flags);

    item_num = phb_info->num_count;

    if (item_num)
    {
        highlight_item = 1;
    }
    else
    {
        item_num = 1;
        highlight_item = 1;
    }

    if (phb_info->name[0] == L'\0')
    {
        empty = MMI_TRUE;
    }

    wgui_swatch_two_line_menu_list_screen(
                                    (empty ? (PU8)GetString(STR_ID_PHB_PBAPC_NO_NAME) : (PU8)(phb_info->name)),
                                    NULL,
                                    NULL,
                                    NULL,
                                    NULL,
                                    item_num,
                                    mmi_phb_pbapc_view_get_item,
                                    highlight_item,
                                    gui_buffer);
/*
    ShowCategory84Screen(
                STR_SCR_ENTRY_VIEW_CAPTION,
                GetRootTitleIcon(MAIN_MENU_PHONEBOOK_MENUID),
                0,
                0,
                NULL,
                NULL,
                item_num * 2,
                (U8 **) item_list,
                NULL,
                WGUI_CATE_ITEM_DISABLE_WITHOUT_CHANGE_TEXT_COLOR,
                highlight_item,
                gui_buffer);
*/
#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_phb_pbapc_view_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


static void mmi_phb_pbapc_view_contact_highlight_hdlr(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_pbapc_cntx_p->hlight_index = index;
}


static MMI_BOOL mmi_phb_pbapc_set_view_flags(S32 index, U32* flag, U32* flag_ex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_phb_pbapc_phb_info_struct *phb_info = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    phb_info = &(phb_pbapc_cntx_p->pse_phb);

    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif

    return MMI_TRUE;
}


static void  mmi_phb_pbapc_view_contact_op_call(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    mmi_ucm_make_call_para_struct call_para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();


    mmi_ucm_init_call_para(&call_para);

    call_para.ucs2_num_uri = phb_pbapc_cntx_p->pse_phb.num[index].number;
    call_para.adv_para.after_callback_user_data = NULL;
    call_para.adv_para.after_make_call_callback = NULL;
    call_para.adv_para.highlight_dial_type = SRV_UCM_INVALID_CALL_TYPE;
    call_para.adv_para.is_ip_dial = MMI_FALSE;
    call_para.adv_para.module_id = SRV_UCM_MODULE_ORIGIN_COMMON;
    call_para.adv_para.phb_data = phb_pbapc_cntx_p->pse_phb.name;
    mmi_ucm_call_launch(0, &call_para);

}


static U16 mmi_phb_pbapc_get_num_type(U8 num_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 str_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (num_type)
    {
        case VCARD_TEL_TYPE_CELL:
            str_id = STR_ID_PHB_MOBILE_NUMBER;
            break;

        case VCARD_TEL_TYPE_HOME:
            str_id = STR_HOME_NUMBER;
            break;

        case VCARD_TEL_TYPE_WORK:
            str_id = STR_OFFICE_NUMBER;
            break;

        case VCARD_TEL_TYPE_FAX:
            str_id = STR_FAX_NUMBER;
            break;

        default:
            str_id = STR_ID_PHB_NUMBER;
            break;
    }

    return str_id;
}


static mmi_ret mmi_phb_pbapc_view_contact_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret menu_cui_proc = MMI_RET_DONT_CARE;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    menu_cui_proc = mmi_phb_pbapc_menu_cui_proc(evt);
 
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
             break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
             break;

        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


mmi_ret mmi_phb_pbapc_notify_evt_hdlr(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_phb_pbapc_notify_evt_struct *notify_evt = NULL;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 percentage;
    U8 bt_index;
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (evt->evt_id == EVT_ID_PHB_PBAPC_SYNC_STATUS_UPDATE)
    {
        srv_phb_pbapc_sync_status_evt_struct *sync = NULL;

        bt_index = phb_pbapc_cntx_p->bt_index;
        sync = (srv_phb_pbapc_sync_status_evt_struct *) evt;

        mmi_frm_get_active_scrn_id(&group_id, &scrn_id);

        MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_EVT_HDLR, 
                phb_pbapc_cntx_p->flag[bt_index], group_id,
                phb_pbapc_cntx_p->load_gid, scrn_id, phb_pbapc_cntx_p->load_sid, 
                sync->sync_count, sync->total_count);

        if ((!(phb_pbapc_cntx_p->flag[bt_index] & MMI_PHB_PBAPC_FLAG_BG_LOADING))
            && (phb_pbapc_cntx_p->load_gid == group_id)
            && (phb_pbapc_cntx_p->load_sid == scrn_id))
        {
            if (sync->sync_count >= sync->total_count)
            {
                percentage = 100;
            }
            else
            {
                percentage = (sync->sync_count * 100) / sync->total_count;
            }

            //wgui_cat6003_update_all((WCHAR*)GetString(STR_GLOBAL_LOADING), NULL, percentage);
            wgui_cat6335_update_all((WCHAR*)GetString(STR_ID_PHB_PBAPC_SYNC), percentage);
        }
    }
    else if (evt->evt_id == EVT_ID_PBAP_NOTIFY)
    {
        srv_pbapc_notify_event_struct *notify_evt = (srv_pbapc_notify_event_struct *) evt;
        srv_pbapc_connect_rsp_struct *connect_rsp = NULL;

        switch (notify_evt->type)
        {
            case EVT_ID_PBAPC_CONNECT_RSP:
            {
                connect_rsp = (srv_pbapc_connect_rsp_struct *)(notify_evt->data);

                if (connect_rsp->ret == SRV_PBAPC_RET_OK)
                {
                    if (phb_pbapc_cntx_p->flag[notify_evt->bt_index] & MMI_PHB_PBAPC_FLAG_LOADING)
                    {
                        ;
                    }
                    else
                    {
                        phb_pbapc_cntx_p->bt_index = notify_evt->bt_index;
                        mmi_phb_pbapc_sync_contact();
                    }

                    phb_pbapc_cntx_p->flag_ext &= ~0x08;
                    mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);
                }

                //phb_pbapc_cntx_p->flag_ext &= ~0x08;

                //mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);

                break;
            }

            default:
                break;
        }
    }
    else if (evt->evt_id == EVT_ID_DIALER_CONN_EVENT_ID)
    {
        phb_pbapc_cntx_p->flag_ext &= ~0x08;

        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_CONNECT);
    }
    else if (evt->evt_id == EVT_ID_DIALER_DISCONN_EVENT_ID)
    {
        phb_pbapc_cntx_p->flag_ext &= ~0x08;

        mmi_frm_scrn_close(GRP_ID_PHB_MAIN, SCR_ID_PHB_PBAPC_FAIL);
    }

    return MMI_RET_OK;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_phb_pbapc_list_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 contact_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //if (index == 0 && show_first_item_flag == 1)
    if (index == 0)
    {
        if (mmi_phb_pbapc_is_connect())
        {
            /* sync contact */
            mmi_phb_pbapc_sync_contact();
        }
        else
        {
            phb_pbapc_cntx_p->flag_ext &= ~0x04;
            phb_pbapc_cntx_p->flag_ext |= 0x08;

            mmi_frm_display_dummy_screen();
            mmi_frm_scrn_close_active_id();
        }

        return ;
    }

    //if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        //if (show_first_item_flag == 1)
        {
            index -= 1;
        }

        contact_id = phb_pbapc_cntx_p->contact_array[index];
        cui_phb_pbapc_view_contact(phb_pbapc_cntx_p->parent_id, phb_pbapc_cntx_p->bt_index, contact_id);
        //mmi_phb_pbapc_sync_contact();
    }
}


static void mmi_phb_pbapc_view_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U16 contact_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (index == 0 && phb_pbapc_cntx_p->pse_phb.num_count == 0)
    {
        return ;
    }
    //if (tap_type == ENUM_TAP_ON_HIGHLIGHTED_ITEM)
    {
        mmi_phb_pbapc_view_contact_op_call(phb_pbapc_cntx_p->hlight_index);
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


static void *mmi_phb_pbapc_alpha_tap_callback(S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    if (index == 0)
    {
        phb_pbapc_cntx_p->jmp_pos = 0;
    }
    else
    {
        phb_pbapc_cntx_p->jmp_pos = phb_pbapc_cntx_p->jump_info.jump_pos[index];
    }

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ALPHA_TAP_CB, index, phb_pbapc_cntx_p->jmp_pos);

    phb_pbapc_cntx_p->flag_ext |= 0x01;
    mmi_frm_scrn_close_active_id();

    return NULL;
}

#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


#if defined(__MMI_PHB_QUICK_SEARCH__)
#define PBAPC_ALPHA_SEARCH

void mmi_phb_pbapc_alpha_search(mmi_id parent_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_group_create_ex(parent_id, GRP_ID_PHB_PBAPC_ALPHA_SEARCH, mmi_phb_pbapc_alpha_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_PHB_PBAPC_ALPHA_SEARCH, SCR_ID_PHB_PBAPC_ALPHA_SEARCH, mmi_phb_pbapc_alpha_scrn_proc, NULL);
}


static mmi_ret mmi_phb_pbapc_alpha_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_ret menu_cui_proc = MMI_RET_DONT_CARE;
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    menu_cui_proc = mmi_phb_pbapc_menu_cui_proc(evt);
 
    if (menu_cui_proc == MMI_RET_OK)
    {
        return MMI_RET_OK;
    }

    switch (evt->evt_id)
    {
        case EVT_ID_GROUP_FIRST_ENTRY:
            break;
            
        case EVT_ID_GROUP_INACTIVE:
        {
            break;
        }
        case EVT_ID_GROUP_ACTIVE:
             break;
            
        case EVT_ID_GROUP_GOBACK:
        case EVT_ID_GROUP_DELETE_REQ:
             break;

        case EVT_ID_GROUP_DEINIT:
        {
            break;
        }

        case EVT_ID_GROUP_FOCUSED:
        case EVT_ID_GROUP_REDRAW_START:
            break;

        case EVT_ID_PHB_SAVE_CONTACT:
        case EVT_ID_PHB_SAVE_CONTACT_CANCEL:
        {
            break;
        }

        default:
            break;
    }

    return MMI_RET_OK;
}


static MMI_RET mmi_phb_pbapc_alpha_scrn_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/


    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;
        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_phb_pbapc_alpha_show();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
            
        break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        default:
         break;
     }

    return MMI_RET_OK;
}


U8 *mmi_phb_pbapc_search_input[SRV_PHB_PBAPC_ALPHA_LIST_COUNT] = 
{
    (U8 *) "A\0\0",
    (U8 *) "B\0\0",
    (U8 *) "C\0\0",
    (U8 *) "D\0\0",
    (U8 *) "E\0\0",
    (U8 *) "F\0\0",
    (U8 *) "G\0\0",
    (U8 *) "H\0\0",
    (U8 *) "I\0\0",
    (U8 *) "J\0\0",
    (U8 *) "K\0\0",
    (U8 *) "L\0\0",
    (U8 *) "M\0\0",
    (U8 *) "N\0\0",
    (U8 *) "O\0\0",
    (U8 *) "P\0\0",
    (U8 *) "Q\0\0",
    (U8 *) "R\0\0",
    (U8 *) "S\0\0",
    (U8 *) "T\0\0",
    (U8 *) "U\0\0",
    (U8 *) "V\0\0",
    (U8 *) "W\0\0",
    (U8 *) "X\0\0",
    (U8 *) "Y\0\0",
    (U8 *) "Z\0\0",
    (U8 *) "#\0\0",
};


static void mmi_phb_pbapc_alpha_show()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;
    U8 *gui_buffer = NULL;
    U8 bt_index = 0;
    U8 *qs_str[SRV_PHB_PBAPC_ALPHA_LIST_COUNT];
    S32 i = 0;
    U16 alpha;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_DEFAULT);

    srv_phb_pbapc_build_alpha_jump_table(
                                    phb_pbapc_cntx_p->contact_array,
                                    phb_pbapc_cntx_p->contact_count,
                                    phb_pbapc_cntx_p->bt_index,
                                    &(phb_pbapc_cntx_p->jump_info));

    for (i = 0; i < phb_pbapc_cntx_p->jump_info.alpha_count; ++i)
    {
        alpha = phb_pbapc_cntx_p->jump_info.alpha[i];

        if (alpha == L'#')
        {
            qs_str[i] = mmi_phb_pbapc_search_input[SRV_PHB_PBAPC_ALPHA_LIST_COUNT -1];
        }
        else
        {
            qs_str[i] = mmi_phb_pbapc_search_input[alpha - L'A'];
        }
    }

    MMI_TRACE(MMI_PHB_PBAPC_TRACE_GROUP, TRC_MMI_PHB_WR_ALPHA_SHOW, phb_pbapc_cntx_p->jump_info.alpha_count, gui_buffer);

    ShowBTNotiCategory145Screen_list_input_WEARABLE_DEVICE(
                                        (U8 *)GetString(STR_ID_PHB_PBAPC_QUICK_SEARCH),
                                        NULL,
                                        NULL,
                                        NULL,
                                        NULL,
                                        NULL,
                                        //&(phb_pbapc_cntx_p->jump_info.alpha),
                                        qs_str,
                                        phb_pbapc_cntx_p->jump_info.alpha_count,
                                        gui_buffer);
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
#endif

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    //wgui_register_tap_callback(mmi_phb_pbapc_alpha_tap_callback);
    wgui_BTcat145_list_input_head_area_register_controlled_callback(mmi_phb_pbapc_alpha_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


static S32 mmi_phb_pbapc_alpha_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (index = 0; index < data_size; index++)
    {
       mmi_phb_pbapc_alpha_get_item_int((item_index + index), menu_data[index].item_list[0], &menu_data[index].image_list[0], &menu_data[index].image_list[1]);
    }

    return data_size;
}


static S32 mmi_phb_pbapc_alpha_get_hint(S32 item_index, UI_string_type *hint_array)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    //mmi_wcsncpy((WCHAR *)(hint_array[0]), L"15208425455", 12);

    return 0;
}


static void mmi_phb_pbapc_alpha_get_item_int(S32 item_index, UI_string_type str_buff, PU8 *img_buff_p1, PU8 *img_buff_p2)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_phb_pbapc_cntx_struct *phb_pbapc_cntx_p = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    phb_pbapc_cntx_p = mmi_phb_pbapc_get_cntx();

    str_buff[0] = phb_pbapc_cntx_p->jump_info.alpha[item_index];
    str_buff[1] = L'\0';
}
#endif /* defined(__MMI_PHB_QUICK_SEARCH__) */


#define MAX_PBAPC_BQB_MAX_FIELDS                        (6)

typedef struct
{
    S32 hlight_index;
    SRV_PHB_PBAPC_HANDLE pbapc_handle;
} mmi_pbapc_bqb_context_struct;


mmi_pbapc_bqb_context_struct g_mmi_pbapc_bqb_cntx;

S32 g_pbap_bqb_flag = 0;


MMI_BOOL mmi_pbapc_is_bqb_test()
{
    return srv_bt_cm_get_bqb_test_flag();
}


void mmi_pbapc_bqb_start()
{
    mmi_frm_group_create_ex(GRP_ID_PHB_MAIN, GRP_ID_PHB_PBAPC_VIEW_CONTACT, mmi_pbapc_bqb_grp_proc, NULL, MMI_FRM_NODE_SMART_CLOSE_FLAG);

    mmi_frm_scrn_create(GRP_ID_PHB_PBAPC_VIEW_CONTACT, SCR_ID_PHB_PBAPC_VIEW_CONTACT, mmi_pbapc_bqb_scr_proc, NULL);
}


static mmi_ret mmi_pbapc_bqb_grp_proc(mmi_event_struct *evt)
{
    return MMI_RET_OK;
}

static mmi_ret mmi_pbapc_bqb_scr_proc(mmi_event_struct *evt)
{
    switch (evt->evt_id)
    {
        case EVT_ID_SCRN_INACTIVE:
        {
            break;

        }

        case EVT_ID_SCRN_ACTIVE:
        {
            mmi_pbapc_bqb_show();
            break;
        }

        case EVT_ID_SCRN_DEINIT:
            
        break;
        case EVT_ID_SCRN_GOBACK_IN_END_KEY:
        case EVT_ID_SCRN_DELETE_REQ_IN_END_KEY:
        {
            break;
        }
        default:
         break;
    }

    return MMI_RET_OK;
}

static S32 mmi_pbapc_bqb_get_item(S32 item_index, gui_iconlist_menu_item *menu_data, S32 data_size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (index = 0; index < data_size; index++)
    {
        switch (index + item_index)
        {
            case 0:
            {
                menu_data[index].item_list[0] = (UI_string_type)(L"PBD/BV-1-C(Download)");
                break;
            }
            case 1:
            {
                menu_data[index].item_list[0] = (UI_string_type)(L"PDF/BV-1-I(Retrieve)");
                break;
            }
            case 2:
            {
                menu_data[index].item_list[0] = (UI_string_type)(L"PDF/BV-6-I(Abort)");
                break;
            }
            case 3:
            {
                menu_data[index].item_list[0] = (UI_string_type)(L"SSM/BV-2-C(Close)");
                break;
            }

            default:
                break;
        }
    }

    return data_size;
}


#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
static void mmi_pbapc_bqb_tap_callback(mmi_tap_type_enum tap_type, S32 index)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    g_mmi_pbapc_bqb_cntx.hlight_index = index;

    mmi_pbapc_bqb_option();
}
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */


static void mmi_pbapc_bqb_show()
{
    CHAR *item_list[MAX_PBAPC_BQB_MAX_FIELDS]; 
    S32 highlight_item = 0;
    U8 *gui_buffer = NULL;
    S32 item_num = 0;

    //gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    //RegisterHighlightHandler(mmi_pbapc_bqb_highlight_hdlr);

    wgui_override_list_menu_slim_style(WGUI_LIST_MENU_SLIM_STYLE_NO_ICON);

    item_num = 4;

    wgui_cat1032_show(
                (WCHAR*) GetString(STR_ID_PBAP_BQB_TEST),
                (PU8) GetImage(IMG_SCR_PBOOK_CAPTION),
                NULL,
                NULL,
                NULL,
                NULL,
                item_num,
                mmi_pbapc_bqb_get_item,
                NULL,
                0,
                0,
                0,
                0,
                NULL,
                NULL);

#if defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__)
    wgui_register_tap_callback(mmi_pbapc_bqb_tap_callback);
#endif /* defined(__MMI_FTE_SUPPORT__) && defined(__MMI_TOUCH_SCREEN__) */
}


static void mmi_pbapc_bqb_highlight_hdlr(S32 index)
{

    g_mmi_pbapc_bqb_cntx.hlight_index = index;

    mmi_pbapc_bqb_option();
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

extern void srv_pbapc_bqb_disconnect_req();

static void mmi_pbapc_bqb_option()
{
    S32 index = 0;

    index = g_mmi_pbapc_bqb_cntx.hlight_index;

    if (index == 0)
    {
        mmi_pbapc_bqb_read_folder();
    }
    else if (index == 1)
    {
        mmi_pbapc_bqb_read_folder();
    }
    else if (index == 2)
    {
        //mmi_pbapc_bqb_abort();
        mmi_pbapc_bqb_read_folder();
        g_pbap_bqb_flag = 1;
    }
    else if (index == 3)
    {
        mmi_pbapc_bqb_disconnect();

        if (g_mmi_pbapc_bqb_cntx.pbapc_handle)
        {
            srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
            g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;
        }

        g_pbap_bqb_flag = 0;
    }
}


static void mmi_pbapc_bqb_back()
{
    if (g_mmi_pbapc_bqb_cntx.pbapc_handle)
    {
        srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
        g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;
    }

    mmi_frm_group_close(GRP_ID_PHB_PBAPC_VIEW_CONTACT);
}


static void mmi_pbapc_bqb_read_folder()
{
    S32 ret = -1;
    srv_phb_pbapc_read_folder_req_struct folder_req;

    g_mmi_pbapc_bqb_cntx.pbapc_handle = srv_phb_pbapc_create_handle(&ret);

    /* Req head */
    folder_req.handle = g_mmi_pbapc_bqb_cntx.pbapc_handle;
    folder_req.storage = SRV_PHB_PBAP_STORAGE_PHONE_PB;
    folder_req.user_data = (void *)0xb0b;
    folder_req.bt_index = SRV_PHB_PBAPC_BTD_1ST;

    folder_req.folder_name = NULL;
    folder_req.vcard_format = SRV_PHB_PBAP_VCARD_FORMAT_21;
    folder_req.vcard_filter = SRV_PHB_PBAP_VCARD_FILTER_ALL;
    folder_req.list_count = 52;
    folder_req.list_offset = 0;

    ret = srv_phb_pbapc_read_pse_folder(&folder_req, mmi_pbapc_bqb_read_folder_cb);
}


static S32 mmi_pbapc_bqb_read_folder_cb(srv_phb_pbapc_read_folder_rsp_struct *folder_rsp, void *user_data)
{
    srv_phb_pbapc_destory_handle(g_mmi_pbapc_bqb_cntx.pbapc_handle);
    g_mmi_pbapc_bqb_cntx.pbapc_handle = NULL;

    return 0;
}

extern  void srv_pbapc_bqb_abort_req();
extern void srv_pbapc_bqb_disconnect();

static void mmi_pbapc_bqb_abort()
{
    srv_pbapc_bqb_abort_req();
}

static void mmi_pbapc_bqb_disconnect()
{
    srv_pbapc_bqb_disconnect();
}


#endif

#endif /* defined(__MMI_BT_PBAP_CLIENT__) */

