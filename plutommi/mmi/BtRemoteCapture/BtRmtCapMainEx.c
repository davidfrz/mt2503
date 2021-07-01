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
 * BtRmtCapMain.c
 *
 * Project:
 * --------
 *  
 *
 * Description:
 * ------------
 *   This file is for BTRemoteCapture App.
 *
 * Author:
 * -------
 * -------
 *
 *===========================================================
 ****************************************************************************/

#include "mmi_features.h"

#ifdef __MMI_BT_REMOTE_CAPTURE__
#include "BtRmtCapProt.h"
#include "mmi_frm_scenario_gprot.h"
#include "GlobalResDef.h"
#include "mmi_rp_app_btremotecapture_def.h"
#include "CustDataRes.h"
#include "wgui_categories_multimedia.h"
#include "wgui_categories_popup.h"
#include "wgui_softkeys.h"
#include "BTNotiSrvGprot.h"
#include "App_str.h"
#include "Mmi_rp_srv_bt_noti_def.h"
#include "mmi_rp_app_btnotification_def.h"
#include "mmi_conn_app_trc.h"
#include "CommonScreens.h"
#include "wgui_fixed_menus.h"

#include "Gui.h"
#include "wgui_categories_util.h"
#include "gdi_include.h"
#include "ProfilesSrvGprot.h"
#include "Mdi_audio.h"
#include "AudioPlayerBTNowPlaying.h"
#include "mmi_rp_app_bluetooth_def.h"
#include "BtcmSrvGprot.h"
#include "BTConnScr.h"
#include "kal_public_api.h"
#include "mmi_rp_app_scr_locker_def.h"
#include "ScrLockerGprot.h"
#include "mmi_rp_app_btnotification_def.h"
#include "gpiosrvgprot.h"
#if defined(__MMI_BT_PBAP_CLIENT__)
#include "mmi_rp_app_phonebook_def.h"
#endif

const char g_rmtcap_cmd_header[] = "CAPC";
mmi_bt_rmt_cap_cntx_struct g_mmi_rmtcap_cntx = {0};
mmi_bt_rmt_cap_cntx_struct *g_mmi_rmtcap_cntx_p = &g_mmi_rmtcap_cntx;
kal_uint32 before_tick;   //for debug
kal_uint32 after_tick;


static void mmi_bt_rmtcap_launch_rsp(void *data);
static void mmi_bt_rmtcap_play_shuttersound(void);
#ifndef __MMI_WEARABLE_DEVICE__
static void mmi_bt_rmtcap_write_default_pic(void);
#endif
static void mmi_bt_rmtcap_timeout(void);
static void mmi_bt_rmtcap_capture_rsp(void *data);
static void mmi_bt_rmtcap_handle_preview_by_memory(void *data);
#ifndef __MTK_TARGET__
static void mmi_bt_rmtcap_modis_capture_timeout(void);
#endif
static void mmi_bt_rmtcap_exit(void);
static mmi_ret mmi_bt_rmtcap_main_scrn_proc (mmi_event_struct *evt);
static mmi_ret mmi_bt_rmtcap_loading_scrn_proc (mmi_event_struct *evt);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
static mmi_ret mmi_bt_rmtcap_event_proc(mmi_event_struct * evt);
#endif
#ifdef defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
extern void mmi_bt_music_disconnect(BT_MUSIC_CALLBACK callback);
extern MMI_BOOL mmi_bt_music_check_connection(void);

#endif

#define MMI_RMTCAP_STATE_TRANS(x)  \
{                                \
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_STATE_TRANS,g_mmi_rmtcap_cntx_p->curr_state,x); \
    g_mmi_rmtcap_cntx_p->curr_state = (x);  \
}


void mmi_bt_rmtcap_preview_req()
{
    U16 cmd_len;
    MMI_BOOL result;   
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCH_REQ);
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_PRVIEW, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);
    result = srv_bt_noti_send_cmd_ext_by_source(g_mmi_rmtcap_cntx_p->bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);
	if(result)
	{
		StartTimer(MMI_BT_RMTCAP_TIMER_ID, MMI_BT_RMTCAP_TIME_OUT, mmi_bt_rmtcap_timeout);
	}	

}

void mmi_bt_rmtcap_launch_req()
{
    U16 cmd_len;
    MMI_BOOL result;   
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCH_REQ);
 #ifndef __MMI_WEARABLE_DEVICE__   
    mmi_bt_rmtcap_write_default_pic();
 #endif    
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_LAUNCH, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_LAUNCH);
    result = srv_bt_noti_send_cmd_ext_by_source(g_mmi_rmtcap_cntx_p->bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);

    if(!result)
    {
        srv_bt_noti_cap_event_notify_struct noti_evt;
        noti_evt.ret_is_num = MMI_TRUE;
        noti_evt.ret_code= -1;
        mmi_bt_rmtcap_launch_rsp(&noti_evt);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    }
    else
    {
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,MMI_BT_RMTCAP_TIME_OUT,mmi_bt_rmtcap_timeout);
    }
}

#ifndef __MMI_WEARABLE_DEVICE__
void mmi_bt_rmtcap_write_default_pic()
{
    WCHAR file_name[MMI_BT_RMTCAP_MAX_FILE_LENGTH] = {0};
    S32 default_height, default_width;
    gdi_handle temp_handle;
    FS_HANDLE fd = -1;
    U8 *img_buffer;

    app_ucs2_strncpy((kal_int8 *)file_name,
        (kal_int8 *)MMI_BT_RMTCAP_PIC_DEFAULT_PATH,
        mmi_wcslen(MMI_BT_RMTCAP_PIC_DEFAULT_PATH) * sizeof(WCHAR));
    fd = FS_Open((const WCHAR*)file_name, FS_READ_ONLY);
    if (fd < FS_NO_ERROR)
    {
        S32 result;
    
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_WRITE_DEFAULT_PIC_REQ_0);
        
        gui_measure_image((PU8)get_image(IMG_BT_RMTCAP_DFAULT_BG), &default_height, &default_width);
        
        img_buffer = mmi_frm_scrmem_alloc_framebuffer(default_height * default_width * 16 / 8);
        gdi_layer_create_using_outside_memory(0,
                                              0,
                                              default_width,
                                              default_height,
                                              &temp_handle,
                                              img_buffer,
                                              (default_height * default_width * 16 / 8));
        gdi_layer_push_and_set_active(temp_handle);
        gdi_image_draw_id(0,0,IMG_BT_RMTCAP_DFAULT_BG);
        result = gdi_image_encode_layer_to_jpeg(temp_handle, (PS8)file_name);
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_WRITE_DEFAULT_PIC_REQ_1, result);
        gdi_layer_pop_and_restore_active();
        mmi_frm_scrmem_free(img_buffer);
    }
    else
    {
        FS_Close(fd);
    }
}
#endif

mmi_ret mmi_bt_rmtcap_loading_show(mmi_event_struct *evt, MMI_ID Str_id)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SHOW_LOADING);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    ShowCategory165Screen(
            NULL,
            NULL,
            NULL,
            NULL,
            (UI_string_type) GetString(Str_id),
            IMG_GLOBAL_L1,
            gui_buffer);
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_popup_scrn_proc (mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->popup_src_id= SCR_ID_BTRMTCAP_POPUP_SCRN;
            mmi_bt_rmtcap_loading_show(evt, STR_ID_BTRMTCAP_CAPTURE_ING);
	    //mmi_bt_rmtcap_clear_pen_callback();
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
             g_mmi_rmtcap_cntx_p->popup_src_id = 0;
             g_mmi_rmtcap_cntx_p->main_scrn_id = 0;
             break;
        }
    }
    return MMI_RET_OK;
}

void mmi_bt_rmtcap_main_capture(void)
{
    U16 cmd_len;
    MMI_BOOL result;

    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_CAPTURE, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_CAPTURE);
    result = srv_bt_noti_send_cmd_ext_by_source(g_mmi_rmtcap_cntx_p->bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CAPTURE, cmd_len, result);
    if(!result)
    {
        srv_bt_noti_cap_event_notify_struct noti_evt;
        noti_evt.ret_is_num = MMI_TRUE;
        noti_evt.ret_code= -1;
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    }
    else
    {
    #ifdef __MTK_TARGET__
        mmi_bt_rmtcap_play_shuttersound();
    #endif

    #ifndef __MTK_TARGET__
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,1000,mmi_bt_rmtcap_modis_capture_timeout);
    #else
        StartTimer(MMI_BT_RMTCAP_TIMER_ID,MMI_BT_RMTCAP_TIME_OUT,mmi_bt_rmtcap_timeout);
    #endif
        mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
                       SCR_ID_BTRMTCAP_POPUP_SCRN, 
                       mmi_bt_rmtcap_popup_scrn_proc,
                       g_mmi_rmtcap_cntx_p);
    }
}



void mmi_bt_rmtcap_exit_show_pic(void)
{
	if(g_mmi_rmtcap_cntx_p->main_scrn_id != 0)
	{	
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);
#ifdef  __MTK_TARGET__
			StopTimer(MMI_BT_RMTCAP_TIMER_ID);
            mmi_bt_rmtcap_preview_req();
#endif	
  }	
    if (g_mmi_rmtcap_cntx_p->show_pic_scrn_id != 0)
    {
        mmi_frm_scrn_close_active_id();
    }
}


void mmi_bt_rmtcap_send_exit_req(void)
{
    U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
    if (!g_mmi_rmtcap_cntx_p->need_exit_cmd)
    {
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_CAPTURE, cmd_len, result);
        return;
    }
    cmd_len = mmi_bt_rmt_cap_gen_cmd_genaral(g_mmi_rmtcap_cntx_p->cmd, MMI_BT_RMTCAP_CMD_EXIT, NULL);
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    result = srv_bt_noti_send_cmd_ext_by_source(g_mmi_rmtcap_cntx_p->bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP, g_rmtcap_cmd_header, g_mmi_rmtcap_cntx_p->cmd, cmd_len);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_CAPTURE, cmd_len, result);
}


void mmi_bt_rmtcap_main_exit_capture(void)
{  
    MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
    mmi_bt_rmtcap_exit();
}

#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
static mmi_ret mmi_bt_rmtcap_event_proc(mmi_event_struct * evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
			{
				mmi_scr_locker_pre_lock_evt_struct* lock_event = (mmi_scr_locker_pre_lock_evt_struct*)evt;

				if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_POWER_KEY)
				{
					return MMI_RET_OK;
				}
				else if(lock_event->lock_mode == MMI_SCR_LOCKER_LOCK_MODE_AUTO_LOCK)
				{
					return MMI_RET_ERR;
				}
			}
			  break;
	   default:
			return MMI_RET_OK;
	}
	return MMI_RET_OK;	

}
#endif


void mmi_bt_rmtcap_image_preview_callback(S32 result)
{

}


#ifndef __MTK_TARGET__
void mmi_bt_rmtcap_modis_capture_timeout(void)
{
    WCHAR file_name[25] = L"Z:\\aa\\capture_pic.jpg";
    srv_bt_noti_cap_event_notify_struct noti_evt;
    noti_evt.ret_is_num = MMI_FALSE;
    noti_evt.ret_code= MMI_BT_RMTCAP_CMD_CAPTURE;
    noti_evt.user_data = OslMalloc(55);

    app_ucs2_strncpy((char *)noti_evt.user_data, (char *)file_name, 25);
    if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
    {
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
    }
    OslMfree(noti_evt.user_data);
}

#endif

void mmi_bt_rmtcap_timeout(void)
{
    srv_bt_noti_cap_event_notify_struct noti_evt;
    noti_evt.ret_is_num = MMI_TRUE;
    noti_evt.ret_code= -1;

    #ifndef __MTK_TARGET__
    noti_evt.ret_code = 1;
    #endif

    StopTimer(MMI_BT_RMTCAP_TIMER_ID);
    if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_LAUNCH || g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW)
    {
        mmi_bt_rmtcap_launch_rsp(&noti_evt);
    }
    else if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
    {
        mmi_bt_rmtcap_capture_rsp(&noti_evt);
    }
}


MMI_BOOL mmi_bt_rmtcap_is_slient_mode()
{
    if (srv_prof_is_profile_activated(SRV_PROF_SILENT_MODE) == MMI_TRUE)
    {
        return MMI_TRUE;
    }
    else
    {
        return MMI_FALSE;
    }
}


void mmi_bt_rmtcap_play_shuttersound()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 aud_len;
    U8 *aud_data = NULL;
    U8 aud_type;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (mmi_bt_rmtcap_is_slient_mode())
    {
        return;
    }
    aud_data = get_audio((U16) (AUD_ID_BTRMTCAP_CAMCO_CAPTURE), &aud_type, &aud_len);
    if (aud_data != NULL)
    {
        mdi_audio_play_string_with_vol_path(
            (void*)aud_data,
            aud_len,
            aud_type,
            DEVICE_AUDIO_PLAY_ONCE,
            NULL,
            NULL,
            MDI_AUD_VOL_4,
            MDI_DEVICE_SPEAKER_BOTH);
    }

}


mmi_ret mmi_btrmtcap_loading_key_handle(mmi_frm_key_evt_struct *evt)
{

    switch (evt->evt_id)
    {
        case EVT_ID_PRE_KEY:
        {
            if (evt->key_code == KEY_END && g_mmi_rmtcap_cntx_p->ignore_endkey)
            {
                return MMI_RET_ERR;
            }
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_pic_show(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PIC_SHOW);
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();

    if (g_mmi_rmtcap_cntx_p->file_name)
    {
        WCHAR file_name[BT_NOTIFY_XML_FILE_NAME_LENTH] = {0};
        
        app_ucs2_strncpy((char *)file_name, 
                         (char *)g_mmi_rmtcap_cntx_p->file_name, 
                          BT_NOTIFY_XML_FILE_NAME_LENTH);
    	StartTimer(MMI_BT_RMTCAP_TIMER_ID,MMI_BT_RMTCAP_CAP_TIME_OUT,mmi_bt_rmtcap_exit_show_pic);
		mmi_bt_rmtcap_draw_shot_screen((char *)file_name, NULL);
		mmi_bt_rmtcap_set_capture_screen_pen_callback();
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
    }  
    return MMI_RET_OK;
}

static S32 mmi_bt_rmtcap_get_device_list_item(S32 start_index, gui_iconlist_menu_item* menu_data, S32 num_items)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i;
    const srv_bt_cm_dev_struct *dev_info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    
    for (i = start_index; i < num_items; ++i)
    {
        dev_info = srv_bt_cm_get_linked_dev_info(i);
        if (dev_info != NULL)
        {
            mmi_chset_utf8_to_ucs2_string(
                (U8*)menu_data[i].item_list[0],
                SRV_BT_CM_BD_NAME_UCS2_LEN,
                ((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(i))->name);
            //mmi_wcscpy(menu_data[i].item_list[0], (WCHAR *)dev_info->name);
            menu_data[i].image_list[0] = mmi_bt_get_device_image(dev_info->cod);
        }
    }

    return num_items;
}

void mmi_bt_rmtcap_device_list_lsk_hdlr(void) 
{
    mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
       SCR_ID_BTRMTCAP_MAIN_SCRN, 
       mmi_bt_rmtcap_main_scrn_proc,
       g_mmi_rmtcap_cntx_p);
}


void mmi_bt_rmtcap_device_highlight_hdlr(S32 index)
{
    g_mmi_rmtcap_cntx_p->device_hilight_idx = index;
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(index))->bd_addr);

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_DEVICE_HLT_HDLR,
        g_mmi_rmtcap_cntx_p->device_hilight_idx,
        g_mmi_rmtcap_cntx_p->bt_addr->lap,
        g_mmi_rmtcap_cntx_p->bt_addr->uap,
        g_mmi_rmtcap_cntx_p->bt_addr->nap);
}


mmi_ret mmi_bt_rmtcap_device_list_show(mmi_event_struct *evt) 
{
    U8 *gui_buffer = NULL;
    S32 list_not_ready;
    S32 device_num = 2;

    
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0))->bd_addr);
    device_num = srv_bt_cm_get_linked_dev_list_idx();
    wgui_cat1032_show(
                    (WCHAR*)GetString(STR_ID_BTRMTCAP_APPLICATION_APP_NAME),
                    0,
                    (WCHAR*)GetString(STR_GLOBAL_OK),
                    0,
                    (WCHAR*)GetString(STR_GLOBAL_BACK),
                    0,
                    device_num,
                    mmi_bt_rmtcap_get_device_list_item,
                    NULL,
                    0,
                    0,
                    IMG_BT_DEV_OTHER,   
                    0,
                    gui_buffer,
                    &list_not_ready);

    RegisterHighlightHandler(mmi_bt_rmtcap_device_highlight_hdlr);
    SetLeftSoftkeyFunction(mmi_bt_rmtcap_device_list_lsk_hdlr, KEY_EVENT_UP);
    SetCenterSoftkeyFunction(mmi_bt_rmtcap_device_list_lsk_hdlr, KEY_EVENT_UP);

    return MMI_RET_OK;
}


#define MMI_BT_RMTCAP_DEFAULT_FILE_NAME   L"E:\\3.JPG"

mmi_ret mmi_bt_rmtcap_main_loading_show(mmi_event_struct *evt)
{

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	gui_buffer = mmi_frm_scrn_get_active_gui_buf();
	g_mmi_rmtcap_cntx_p->ignore_endkey = MMI_FALSE;
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
#else
	mmi_bt_rmtcap_draw_screen(NULL, NULL, NULL);
#endif
	mmi_bt_rmtcap_launch_req();
	clear_softkey_handler(MMI_RIGHT_SOFTKEY);
	g_mmi_rmtcap_cntx_p->ignore_endkey = MMI_TRUE;
	
#ifndef __MTK_TARGET__
	StartTimer(MMI_BT_RMTCAP_TIMER_ID,1000,mmi_bt_rmtcap_timeout);
#endif/*__MTK_TARGET__*/


}

mmi_ret mmi_bt_rmtcap_right_hdlr(mmi_event_struct *evt)
{
	if(evt->evt_id == EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_RIGHT_HDLR);
		return MMI_RET_DONT_CARE;
	}
	return MMI_RET_OK;
}

#ifdef __MMI_WEARABLE_DEVICE__ 
static void mmi_bt_rmtcap_lsk_connect(void)
{
	mmi_bt_dialer_show_popup(GRP_ID_BTRMTCAP_APP);
}
#endif

mmi_ret mmi_bt_rmtcap_main_show(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    U8 *gui_buffer = NULL;
	mmi_frm_scrn_active_evt_struct *main_evt;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MAIN_SHOW, g_mmi_rmtcap_cntx_p->is_remote_launched);
#ifdef __MTK_TARGET__
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MAIN_SHOW_1,
        g_mmi_rmtcap_cntx_p->device_hilight_idx,
        g_mmi_rmtcap_cntx_p->bt_addr->lap,
        g_mmi_rmtcap_cntx_p->bt_addr->uap,
        g_mmi_rmtcap_cntx_p->bt_addr->nap);
 
    gui_buffer = mmi_frm_scrn_get_active_gui_buf();
    g_mmi_rmtcap_cntx_p->ignore_endkey = MMI_FALSE;

    if (!srv_bt_noti_check_sync_connection_ext_by_source(g_mmi_rmtcap_cntx_p->bt_addr, SRV_BT_NOTIFY_DATA_SOURCE_SPP))
    {
        S32 list_not_ready;
        MMI_ID hint_str_id;
        U8 *gui_buffer = mmi_frm_scrn_get_active_gui_buf();
        if (srv_bt_cm_get_linked_dev_list_idx() == 0)
        {
        #ifndef __MMI_WEARABLE_DEVICE__
            hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT;
		#else
		#if defined(__MMI_BT_PBAP_CLIENT__)
			hint_str_id= STR_ID_PHB_PBAPC_NOT_CONNECTED;
		#else
			hint_str_id= STR_ID_BTNOTIFICATION_APPLICATION_NEED_USER_CONNECT_WATCH;
		#endif //#if defined(__MMI_BT_PBAP_CLIENT__)
		#endif
        }
        else
        {
            hint_str_id = STR_ID_BTNOTIFICATION_APPLICATION_DISCONNECT_WATCH;
        }
   #ifndef __MMI_WEARABLE_DEVICE__     
        wgui_set_menu_empty_string_by_id(hint_str_id);
        wgui_cat1032_show(
                    (WCHAR*)GetString(STR_ID_BTRMTCAP_APPLICATION_APP_NAME),
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
                    gui_buffer,
                    &list_not_ready);
        wgui_set_menu_empty_string_by_id(STR_GLOBAL_EMPTY);
		
	#else
    //wgui_status_icon_bar_hide_icon(STATUS_ICON_NOTIFICATION);    
    if (srv_bt_cm_get_linked_dev_list_idx() == 0)
    {        
        wgui_showcategory6333_screen(NULL,
            (UI_string_type)GetString(STR_GLOBAL_CONNECT),
            (UI_string_type)GetString(STR_GLOBAL_CANCEL),
            (UI_string_type)GetString(hint_str_id),
            NULL);
        SetLeftSoftkeyFunction(mmi_bt_rmtcap_lsk_connect, KEY_EVENT_UP);
        SetRightSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
    else
    {        
        wgui_showcategory6333_screen(NULL,
            (UI_string_type)GetString(STR_GLOBAL_OK),
            NULL,
            (UI_string_type)GetString(hint_str_id),
            NULL);
        SetLeftSoftkeyFunction(mmi_frm_scrn_close_active_id, KEY_EVENT_UP);
    }
	#endif
		srv_backlight_turn_off();
		mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_rmtcap_right_hdlr, NULL);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
		mmi_frm_cb_dereg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, mmi_bt_rmtcap_event_proc, NULL);
#endif
        return MMI_RET_OK;
    }
#endif

	main_evt = (mmi_frm_scrn_active_evt_struct *)evt;
	if(main_evt->is_first_active)
	{
		mmi_frm_start_scenario(MMI_SCENARIO_ID_BT_REMOTE_CAPTURE);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
	 	mmi_frm_cb_reg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, mmi_bt_rmtcap_event_proc, NULL);
#endif
		mdi_audio_suspend_background_play();
		mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_rmtcap_right_hdlr, NULL);
		srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	}			 


#ifndef __MTK_TARGET__
     g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_TRUE;  //for debug
#endif
    if (g_mmi_rmtcap_cntx_p->is_remote_launched)
    {

#ifndef __MTK_TARGET__
        WCHAR file_name[BT_NOTIFY_XML_FILE_NAME_LENTH] = {0};

        mdi_audio_suspend_background_play();
        dm_reset_context();
            
        if (g_mmi_rmtcap_cntx_p->file_name && 
            g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW)
        {
            app_ucs2_strncpy((char *)file_name, 
                             (char *)g_mmi_rmtcap_cntx_p->file_name, 
                              BT_NOTIFY_XML_FILE_NAME_LENTH);
        
			mmi_bt_rmtcap_draw_screen(
					(CHAR *)file_name,
					NULL,
					NULL);
			

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
   #endif
        }    
        else
        {                       
        /*
            app_ucs2_strncpy((kal_int8 *)file_name,
                (kal_int8 *)MMI_BT_RMTCAP_PIC_DEFAULT_PATH,
                mmi_wcslen(MMI_BT_RMTCAP_PIC_DEFAULT_PATH) * sizeof(WCHAR));

		*/                
			app_ucs2_strncpy((kal_int8 *)file_name,
							(kal_int8 *)MMI_BT_RMTCAP_DEFAULT_FILE_NAME,
							mmi_wcslen(MMI_BT_RMTCAP_DEFAULT_FILE_NAME) * sizeof(WCHAR));

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
		#else

			mmi_bt_rmtcap_draw_screen(
								(CHAR *)file_name,
								NULL,
								NULL);
			
		#endif
        }
		mmi_bt_rmtcap_set_draw_screen_pen_callback();	
	#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif	
#else  //#ifndef __MTK_TARGET__
	mmi_bt_rmtcap_draw_screen(NULL, NULL, NULL);	
#endif 
    }
    else

    {
  		mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
       			SCR_ID_BTRMTCAP_LOADING_POP_SCRN, 
       			mmi_bt_rmtcap_loading_scrn_proc,
       			g_mmi_rmtcap_cntx_p);
            
        
    }
    MMI_SCR_SET_KEY_PROC(mmi_btrmtcap_loading_key_handle, NULL);
    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_main_group_proc(mmi_event_struct *param)
{
    switch(param->evt_id)
    {
    	case EVT_ID_GROUP_ACTIVE:
		{
			break;
		}
        case EVT_ID_GROUP_INACTIVE:
        {
            mmi_bt_rmtcap_main_exit_capture();
            break;
        }
        case EVT_ID_GROUP_DEINIT:
        {
           g_mmi_rmtcap_cntx_p->grp_id = 0;
           break;
        }
    }
    return MMI_RET_OK;
}

mmi_ret mmi_bt_rmtcap_device_list_scrn_proc (mmi_event_struct *evt) 
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->devce_list_scrn_id = SCR_ID_BTRMTCAP_DEVICE_LIST;
            mmi_bt_rmtcap_device_list_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_rmtcap_cntx_p->devce_list_scrn_id = 0;
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_FALSE;
            if (g_mmi_rmtcap_cntx_p->file_name)
            {
                OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                g_mmi_rmtcap_cntx_p->file_name = NULL;
            }
            break;
        }
    }
    return MMI_RET_OK;
}


mmi_ret mmi_bt_rmtcap_main_scrn_proc (mmi_event_struct *evt)
{

	mmi_frm_scrn_active_evt_struct *main_evt;
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
	    main_evt = (mmi_frm_scrn_active_evt_struct *)evt;
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_MAIN_SCRN_PROC);	    
            g_mmi_rmtcap_cntx_p->main_scrn_id = SCR_ID_BTRMTCAP_MAIN_SCRN;
            gui_sse_setup_scenario(GUI_SSE_SCENARIO_NO_EFFECT);          
            mmi_bt_rmtcap_main_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
            g_mmi_rmtcap_cntx_p->main_scrn_id = 0;
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_FALSE;
            if (g_mmi_rmtcap_cntx_p->file_name)
            {
                OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                g_mmi_rmtcap_cntx_p->file_name = NULL;
            }
            mmi_frm_end_scenario(MMI_SCENARIO_ID_BT_REMOTE_CAPTURE);
            mmi_bt_rmtcap_send_exit_req();
            mdi_audio_resume_background_play();
			mmi_bt_rmtcap_clear_pen_callback();
			srv_backlight_turn_off();
			mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_bt_rmtcap_right_hdlr, NULL);
#ifdef __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__
			mmi_frm_cb_dereg_event(EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING, mmi_bt_rmtcap_event_proc, NULL);
#endif
            break;
        }
    }
    return MMI_RET_OK;
}

static mmi_ret mmi_bt_rmtcap_loading_scrn_proc (mmi_event_struct *evt)
{
		switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
            g_mmi_rmtcap_cntx_p->popup_src_id= SCR_ID_BTRMTCAP_LOADING_POP_SCRN;
            mmi_bt_rmtcap_main_loading_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
             g_mmi_rmtcap_cntx_p->popup_src_id = 0;
             break;
        }
    }
    return MMI_RET_OK;



}

mmi_ret mmi_bt_rmtcap_show_pic_scrn_proc(mmi_event_struct *evt)
{
    switch(evt->evt_id)
    {
        case EVT_ID_SCRN_ACTIVE:
        {
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SHOW_PIC_SCRN_ACTIVE);        		
            g_mmi_rmtcap_cntx_p->show_pic_scrn_id = SCR_ID_BTRMTCAP_SHOW_PICTURE;
            mmi_bt_rmtcap_pic_show(evt);
            break;
        }
        case EVT_ID_SCRN_DEINIT:
        {
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_SHOW_PIC_SCRN_DEINIT);        		
            g_mmi_rmtcap_cntx_p->show_pic_scrn_id = 0;
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
            break;
        }
    }
    return MMI_RET_OK;
}

void mmi_btrmtcap_launch()
{
    g_mmi_rmtcap_cntx_p->need_exit_cmd = MMI_TRUE;
    g_mmi_rmtcap_cntx_p->bt_addr = &(((srv_bt_cm_dev_struct *)srv_bt_cm_get_linked_dev_info(0))->bd_addr);

    
    g_mmi_rmtcap_cntx_p->grp_id = mmi_frm_group_create_ex(
                                    GRP_ID_ROOT,
                                    GRP_ID_BTRMTCAP_APP,
                                    mmi_bt_rmtcap_main_group_proc,
                                    g_mmi_rmtcap_cntx_p,
                                    MMI_FRM_NODE_SMART_CLOSE_FLAG);
    
    if (srv_bt_cm_get_linked_dev_list_idx() > 1)
    {
        mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
           SCR_ID_BTRMTCAP_DEVICE_LIST, 
           mmi_bt_rmtcap_device_list_scrn_proc,
           g_mmi_rmtcap_cntx_p);
    }
    else 
    {
       mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
       SCR_ID_BTRMTCAP_MAIN_SCRN, 
       mmi_bt_rmtcap_main_scrn_proc,
       g_mmi_rmtcap_cntx_p);
    }
}

void mmi_btrmtcap_bt_music_disconn_cb(MMI_BOOL result)
{
    if (result)
    {
        mmi_btrmtcap_launch();
    }
}
    
void mmi_btrmtcap_entry_main_message_menu()
{
#ifdef defined(__MMI_BT_MUSIC__) || defined(__MMI_AUDIO_PLAYER_BT__)
    if (mmi_bt_music_check_connection())
    {
        mmi_bt_music_disconnect(NULL);
        //return;
    }
    //else
#endif
    {
        mmi_btrmtcap_launch();
    }
}


void mmi_bt_rmtcap_exit()
{
    mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id,g_mmi_rmtcap_cntx_p->main_scrn_id);
    if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
    {
        mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
    }
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_1, g_mmi_rmtcap_cntx_p->show_pic_scrn_id);
    if (g_mmi_rmtcap_cntx_p->show_pic_scrn_id != 0)
    {
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EXIT_2);
        mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->show_pic_scrn_id);
    }
    //mmi_frm_group_close(g_mmi_rmtcap_cntx_p->grp_id);   
}


void mmi_bt_rmtcap_launch_rsp(void *data)
{
    srv_bt_noti_cap_event_notify_struct *noti_evt = data;
    S32 error_code = 0;
    StopTimer(MMI_BT_RMTCAP_TIMER_ID);
                  

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_LAUNCED_RSP, noti_evt->ret_is_num, noti_evt->ret_code);
    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;
        
        if (error_code == MMI_BT_RMTCAP_CMD_LAUNCH)
        {
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE); 
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                return;
            }
            g_mmi_rmtcap_cntx_p->is_remote_launched = MMI_TRUE;
#ifdef  __MTK_TARGET__
        if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_IDLE)
        {
            mmi_bt_rmtcap_preview_req();
        }
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
 #endif           
        }
        else if (error_code < 0)
        {

            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE); 
            mmi_display_popup((UI_string_type)get_string(STR_ID_BTRMTCAP_LAUNCH_FAILED), MMI_EVENT_FAILURE);
            mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id,g_mmi_rmtcap_cntx_p->main_scrn_id);
            if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }
            //mmi_frm_group_close(g_mmi_rmtcap_cntx_p->grp_id);
        }
    }
}

void mmi_bt_rmtcap_capture_rsp(void *data)
{
    srv_bt_noti_cap_event_notify_struct *noti_evt = data;
    S32 error_code = 0;    
    
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CAPTURE_RSP, noti_evt->ret_is_num, noti_evt->ret_code); 
    
    if (!noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == MMI_BT_RMTCAP_CMD_CAPTURE)
        {
            MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PIC_SHOW);
            StopTimer(MMI_BT_RMTCAP_TIMER_ID);
            if (g_mmi_rmtcap_cntx_p->file_name == NULL)
            {
                g_mmi_rmtcap_cntx_p->file_name = (WCHAR *)OslMalloc(BT_NOTIFY_XML_FILE_NAME_LENTH * 2);
            }
            app_ucs2_strncpy((char *)g_mmi_rmtcap_cntx_p->file_name, (char *)noti_evt->user_data, BT_NOTIFY_XML_FILE_NAME_LENTH);
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
                return;
            }
            if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }
            mmi_frm_scrn_create(GRP_ID_BTRMTCAP_APP, 
                SCR_ID_BTRMTCAP_SHOW_PICTURE, 
                mmi_bt_rmtcap_show_pic_scrn_proc,
                g_mmi_rmtcap_cntx_p);
        }       
    }
    else
    {
        error_code = noti_evt->ret_code;
        StopTimer(MMI_BT_RMTCAP_TIMER_ID);
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_IDLE);
        if (error_code < 0)
        {            
            if (g_mmi_rmtcap_cntx_p->grp_id == 0)
            {
                return;
            }
            mmi_display_popup((UI_string_type)get_string(STR_GLOBAL_FAILED), MMI_EVENT_FAILURE);
            if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }
        }
    }
}

void mmi_bt_rmt_cap_preview(void *data)
{
    
        srv_bt_noti_cap_event_notify_struct *noti_evt = data;
        S32 error_code = 0;
        
        MMI_RMTCAP_STATE_TRANS(MMI_BT_RMTCAP_STATE_PRVIEW);      
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_CAP_PREVIEW, g_mmi_rmtcap_cntx_p->curr_state,noti_evt->ret_code);        
        
        if (!noti_evt->ret_is_num)
        {
            error_code = noti_evt->ret_code;
    
            if (error_code == MMI_BT_RMTCAP_CMD_PRVIEW)
            {
                if (g_mmi_rmtcap_cntx_p->file_name == NULL)
                {
                    g_mmi_rmtcap_cntx_p->file_name = (WCHAR *)OslMalloc(BT_NOTIFY_XML_FILE_NAME_LENTH * 2);
                }
                app_ucs2_strncpy((char *)g_mmi_rmtcap_cntx_p->file_name, (char *)noti_evt->user_data, BT_NOTIFY_XML_FILE_NAME_LENTH);
                if (g_mmi_rmtcap_cntx_p->grp_id == 0)
                {
                    return;
                }
                if (!mmi_frm_scrn_is_present(
                    GRP_ID_BTRMTCAP_APP,
                    SCR_ID_BTRMTCAP_MAIN_SCRN,
                    MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
                {
                    //mmi_bt_rmtcap_main_show(NULL);
                }
            }
            else if (error_code < 0)
            {
                if (g_mmi_rmtcap_cntx_p->file_name)
                {
                    OslMfree(g_mmi_rmtcap_cntx_p->file_name);
                    g_mmi_rmtcap_cntx_p->file_name = NULL;
                }
            }
        }
}


mmi_ret mmi_bt_rmtcap_event_hdlr(mmi_event_struct *param)
{
    switch (param->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_CAP_CMD_NOTIFY:
        {
            srv_bt_noti_cap_event_notify_struct *noti_evt = (srv_bt_noti_cap_event_notify_struct *)param;
            S32 error_code;            
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EVENT_HDLR, g_mmi_rmtcap_cntx_p->curr_state);
            if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_LAUNCH)
            {
                mmi_bt_rmtcap_launch_rsp(param);
            }
            else if (g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_CAPTURE)
            {
                mmi_bt_rmtcap_capture_rsp(param);
            }
            else if ((g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_IDLE ||
                g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW)
                && g_mmi_rmtcap_cntx_p->is_remote_launched)
            {
                mmi_bt_rmt_cap_preview(param);
            }

            if (noti_evt->ret_is_num)
            {
                error_code = noti_evt->ret_code;
                if (error_code == MMI_BT_RMTCAP_CMD_EXIT)
                {
                    g_mmi_rmtcap_cntx_p->need_exit_cmd = MMI_FALSE;
                    mmi_bt_rmtcap_exit();
                }
            }
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF:
        {
            MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_EVENT_HDLR2, g_mmi_rmtcap_cntx_p->curr_state);
            mmi_bt_rmtcap_exit();
            break;
        }
    }
    
    return MMI_RET_OK;
}

void mmi_bt_rmtcap_bootup_init()
{
    WCHAR file_name[MMI_BT_RMTCAP_MAX_FILE_LENGTH] = {0};

    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_BOOTUP_INIT);
    app_ucs2_strncpy((kal_int8 *)file_name,
        (kal_int8 *)MMI_BT_RMTCAP_FOLDER_PATH,
        mmi_wcslen(MMI_BT_RMTCAP_FOLDER_PATH) * sizeof(WCHAR));
    memset(g_mmi_rmtcap_cntx_p, 0, sizeof(mmi_bt_rmt_cap_cntx_struct));   

    srv_bt_noti_register_callback_ext(MMI_BT_RMTCAP_CMD_HEADER, MMI_BT_RMTCAP_SENDER_ID, mmi_bt_rmtcap_handle_preview_by_memory);
}

mmi_ret mmi_bt_rmtcap_package_proc(mmi_event_struct *evt)
{
    return MMI_RET_DONT_CARE;
}

void mmi_bt_rmtcap_handle_preview_by_memory(void *data)
{
    srv_bt_noti_callback_struct *callback_data = (srv_bt_noti_callback_struct *)data;

    
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PREVIEW_BY_MEMORY_1, g_mmi_rmtcap_cntx_p->curr_state,callback_data->err_code);
	after_tick = before_tick;
	kal_get_time(&before_tick);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_GET_COST_TIME, (before_tick - after_tick));
    if ((g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_IDLE ||
        g_mmi_rmtcap_cntx_p->curr_state == MMI_BT_RMTCAP_STATE_PRVIEW) && 
        g_mmi_rmtcap_cntx_p->is_remote_launched)
    {

			if (g_mmi_rmtcap_cntx_p->popup_src_id != 0)
            {
                mmi_frm_scrn_close(g_mmi_rmtcap_cntx_p->grp_id, g_mmi_rmtcap_cntx_p->popup_src_id);
            }

        if (!mmi_frm_scrn_is_present(
                        GRP_ID_BTRMTCAP_APP,
                        SCR_ID_BTRMTCAP_MAIN_SCRN,
                        MMI_FRM_NODE_EXCLUDE_ACTIVE_SCRN_FLAG))
        {
        		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_IS_SCRN_PRESENT, callback_data->data_type, callback_data->err_code);
           // if (callback_data->data_type == SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER &&
           //     callback_data->err_code == MMI_BT_RMTCAP_CMD_PRVIEW)
           // {
           if(callback_data->err_code == MMI_BT_RMTCAP_CMD_PRVIEW)
           	{
           		StopTimer(MMI_BT_RMTCAP_TIMER_ID);
							if(callback_data->data_type == SRV_BT_NOTI_MRE_DATA_TYPE_BUFFER)
            {
            	mmi_bt_rmtcap_draw_screen(NULL ,callback_data->data.buffer.data, NULL);
									
								}   
								else
								{
										mmi_bt_rmtcap_draw_screen((char *)callback_data->data.file_path, NULL, NULL);
								}        
           
 
				mmi_bt_rmtcap_set_draw_screen_pen_callback();
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
			#endif	
            }
		    else if(callback_data->err_code == SRV_BT_NOTIFY_RET_LINK_DISCONNECTED)
		    {
				mmi_bt_rmtcap_exit();
			}
		   	
        }
    }
   
   MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_MMI_BT_RMTCAP_PREVIEW_BY_MEMORY_2);

}
#endif /*__MMI_BT_REMOTE_CAPTURE__*/

