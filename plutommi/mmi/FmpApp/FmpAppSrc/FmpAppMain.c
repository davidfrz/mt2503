/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 *  FmpAppMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the fmp application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"
#include "MMIDataType.h"

				  
#ifdef __MMI_BLE_FMP_SUPPORT__

#include "FmpAppGprot.h"
#include "FmpAppProt.h"
#include "FmpAppMain.h"
#include "mmi_rp_app_fmpapp_def.h"
#include "Fmpl_def.h"
//#include "Fmpt_def.h"
#include "BtcmSrvGprot.h"
#include "GpioSrvGprot.h"
#include "wgui_softkeys.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "CommonScreens.h"
#include "MMI_conn_app_trc.h"
#include "TouchScreenGprot_Int.h"

#include "FmpCommon.h"


//#include "mmi_common_app_trc.h"
//#include "MMI_common_app_trc.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#include "mmi_frm_scenario_gprot.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "BootupSrvGprot.h"
#include "IdleGprot.h"
#include "gui_effect_oem.h"

#include "mmi_frm_input_gprot.h"

#include "mmi_cb_mgr_gprot.h"


/****************************************************************************
 * Global and define
 ****************************************************************************/
 
/* Time interval to expiry and show finding stop screen in FMPAPP. */
//#define MMI_FMPAPP_FINDING_STOP_TIME        (1000 * 3)
#define MMI_FMPAPP_TARGET_ALERT_TIME        (1000 * 60)
#define SIZE_FIND_MY_DEVICE                  20
#if defined(__MMI_MAINLCD_240X320__)
#define YPOS_FIND_MY_DEVICE                  15
#define YPOS_BETWWEN_STR_IMG                 65
#define FMPAPP_BUTTON_START_Y               260
#else
#define YPOS_FIND_MY_DEVICE                  15
#define YPOS_BETWWEN_STR_IMG                 25
#define FMPAPP_BUTTON_START_Y               180
#endif
#define SIZE_BUTTONE_START_STOP              60
#define WIDTH_OF_LINE                         1
#define SIZE_STR_START_STOP                  22
#define FMPL_BD_ADDR_SIZE                   6

fmpl_callback_t fmp_locator_cb;
mmi_pen_point_struct fmpapp_button_start_pos;
char fmpl_bdaddr[FMPL_BD_ADDR_SIZE];
MMI_BOOL to_alert = MMI_FALSE;
char base_addr[FMPL_BD_ADDR_SIZE] = {0};
int s_conn_state = 0;


/****************************************************************************
 * Function
 ****************************************************************************/
/* For the detail information, please refer to the FmpAppGprot.h */
#ifdef __MMI_WEARABLE_DEVICE__
mmi_ret mmi_fmpapp_pen_right_hdlr(mmi_event_struct *evt);
#endif

/*Locator  Role Begain*/
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_button_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	gdi_color bg_color;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bg_color = GDI_RGB_TO_BUFFER_FORMAT(127,75,0);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_START),&start_stop_width,&start_stop_height);

	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = FMPAPP_BUTTON_START_Y + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;
	
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,FMPAPP_BUTTON_START_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_START));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_button_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	gdi_color bg_color;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bg_color = GDI_RGB_TO_BUFFER_FORMAT(255,150,0);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_START),&start_stop_width,&start_stop_height);

	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = FMPAPP_BUTTON_START_Y + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;

	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,FMPAPP_BUTTON_START_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);	
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_START));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_stop_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_stop_button_str(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	gdi_color bg_color;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bg_color = GDI_RGB_TO_BUFFER_FORMAT(127,75,0);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_STOP),&start_stop_width,&start_stop_height);

	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = FMPAPP_BUTTON_START_Y + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;

	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,FMPAPP_BUTTON_START_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);	
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_STOP));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_show_stop_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_show_stop_button_normal(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	gdi_color bg_color;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	bg_color = GDI_RGB_TO_BUFFER_FORMAT(255,150,0);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_STOP),&start_stop_width,&start_stop_height);

	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = FMPAPP_BUTTON_START_Y + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;

	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,FMPAPP_BUTTON_START_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_STOP));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_client_init
 * DESCRIPTION
 *  to initial find me locator role
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_fmpapp_client_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_CLIENT_INIT);
	event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
				 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_bt_event_notify_fmpapp_client, event_mask, NULL);
	return; 
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_event_notify_fmpapp
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_event_notify_fmpapp_client(U32 event, void* para)
{
    switch (event)
    {
        case SRV_BT_CM_EVENT_BLE_ACTIVATE:
            mmi_bt_power_on_init_fmpl();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            mmi_bt_power_on_deinit_fmpl();
            break;

		default :
			break;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_init_fmpl
 * DESCRIPTION
 *  This function is to rigister ppxp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_init_fmpl(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_BTC_SWITCH_ON);
    fmp_locator_cb.connection_state_cb = mmi_fmpapp_locator_connect_state;
    fmp_locator_cb.alert_notify_cb = mmi_fmpapp_locator_alert_notify_cb;
	fmpl_init(&fmp_locator_cb);
	if (memcmp(&fmpl_bdaddr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)) != 0)
	{
		memset(fmpl_bdaddr, 0x00, FMPL_BD_ADDR_SIZE);
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_deinit_fmpl
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_deinit_fmpl(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_BTC_SWITCH_OFF);
	fmpl_deinit(&fmp_locator_cb);
    fmp_locator_cb.connection_state_cb = NULL;
    fmp_locator_cb.alert_notify_cb = NULL;
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_launch
 * DESCRIPTION
 *  launch point of fmpapp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_launch(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_ID group_id;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    	
	group_id = mmi_frm_group_create(
			GRP_ID_ROOT,
			GRP_ID_FMPAPP_MAIN,
			mmi_fmpapp_grp_proc,
			NULL);
	mmi_frm_group_enter(group_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_fmpapp_entry_normal_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_grp_proc
 * DESCRIPTION
 *  proc of  fmpapp 
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
MMI_RET mmi_fmpapp_grp_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
		{
		#ifdef __MMI_WEARABLE_DEVICE__
			mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_fmpapp_pen_right_hdlr, NULL);
		#endif
			if (MMI_TRUE == to_alert)
			{
				to_alert = MMI_FALSE;
				fmpl_alert((char *)fmpl_bdaddr, MMI_FALSE);
			}
			mmi_frm_group_close(GRP_ID_FMPAPP_MAIN);
	    }
			break;
			
		default:
			break;
	}
	return MMI_OK;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_down_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_down_hdlr_normal(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL is_touch_feed = MMI_FALSE;
    mmi_pen_point_struct point; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
	if (point.y > FMPAPP_BUTTON_START_Y)    
    {
		is_touch_feed = MMI_TRUE;  
    }
	if (is_touch_feed) 
	{  
		fmpapp_button_start_pos = pos;
		mmi_fmpapp_show_button_str();
	}
	else
	{
		fmpapp_button_start_pos.x = 0;
		fmpapp_button_start_pos.y = 0;
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_move_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_move_hdlr_normal(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
    if (point.y < FMPAPP_BUTTON_START_Y)   
	{
		fmpapp_button_start_pos.x = 0;
		fmpapp_button_start_pos.y = 0;
	    mmi_fmpapp_show_button_normal();
	}
	else
	{
		fmpapp_button_start_pos = pos;
		mmi_fmpapp_show_button_str();
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_empty_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_empty_hdlr_normal(mmi_pen_point_struct pos)
{
	/*do nothing*/
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_up_hdlr_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_up_hdlr_normal(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
	if ((point.y > FMPAPP_BUTTON_START_Y) && (fmpapp_button_start_pos.y > FMPAPP_BUTTON_START_Y))  
	{
		fmpapp_button_start_pos.x = 0;
		fmpapp_button_start_pos.y = 0;
		mmi_fmpapp_show_button_str();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
		
	    /*to connect with remote device find me target role*/
		if (memcmp(&fmpl_bdaddr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)) != 0)
		{
		    BtStatus alert_result;
		    fmpl_configAlertLevel((char *)fmpl_bdaddr,FMP_ALERT_LEVEL_HIGH);
			to_alert = MMI_TRUE;
			alert_result = fmpl_alert((char *)fmpl_bdaddr,MMI_TRUE);
			switch (alert_result)
			{
				case 0:
					break;
					
				case 1:
				{
					/*popup please connect with your BLE device first*/
					mmi_display_popup((UI_string_type)GetString(STR_ID_FMP_ERR_BLE), MMI_EVENT_INFO);
					return;
				}
					break;
					
				case 2:
					break;
					
				default:
					break;
			}
		    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_LOCATOR_ALERT, fmpl_bdaddr[0], fmpl_bdaddr[1], 
				fmpl_bdaddr[2], fmpl_bdaddr[3], fmpl_bdaddr[4], fmpl_bdaddr[5], 1);
		}
		else
		{
	        /*popup please connect with your BLE device first*/
			mmi_display_popup((UI_string_type)GetString(STR_ID_FMP_ERR_BLE), MMI_EVENT_INFO);
			return;
		}
	}
	else
	{
	    mmi_fmpapp_show_button_normal();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_exit_normal_screen
 * DESCRIPTION
 *  screen of "start find device" 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_exit_normal_screen(void)
{
	mmi_frm_scrn_close_active_id();
	mmi_frm_scrn_close(GRP_ID_FMPAPP_MAIN,SCR_ID_FMPAPP_START);
}

#ifdef __MMI_WEARABLE_DEVICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_right_hdlr
 * DESCRIPTION
 *  screen of "pen right" 
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
mmi_ret mmi_fmpapp_pen_right_hdlr(mmi_event_struct *evt)
{
	if (evt->evt_id == EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT)
	{
		mmi_fmpapp_stop_clicked_cb();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
		return MMI_RET_OK;
	}
	return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_entry_normal_screen
 * DESCRIPTION
 *  screen of "start find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_entry_normal_screen(void)
{
	if (!mmi_frm_scrn_enter(
		 GRP_ID_FMPAPP_MAIN, 
		 SCR_ID_FMPAPP_START, 
		 NULL,
		 (FuncPtr)mmi_fmpapp_entry_normal_screen, 
		 MMI_FRM_FULL_SCRN))
    {
    	return;
    }
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_ENTER_START);
	
    /* show start screen "find my device" */
	mmi_fmpapp_normal_sreen_show();
#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler(mmi_fmpapp_pen_down_hdlr_normal);
	mmi_pen_register_up_handler(mmi_fmpapp_pen_up_hdlr_normal);
	mmi_pen_register_move_handler(mmi_fmpapp_pen_move_hdlr_normal);
	mmi_pen_register_abort_handler(mmi_fmpapp_pen_empty_hdlr_normal);	  
	mmi_pen_register_repeat_handler(mmi_fmpapp_pen_empty_hdlr_normal);
	mmi_pen_register_long_tap_handler(mmi_fmpapp_pen_empty_hdlr_normal);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    SetKeyHandler(mmi_fmpapp_exit_normal_screen, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmpapp_exit_normal_screen, KEY_BACK, KEY_EVENT_UP); 
	
#ifdef __MMI_WEARABLE_DEVICE__
	if (mmi_frm_kbd_is_key_supported(KEY_POWER))
	{
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
		 SetKeyHandler(mmi_fmpapp_exit_normal_screen, KEY_POWER, KEY_EVENT_UP);
		 SetKeyLongpressHandler(mmi_fmpapp_exit_normal_screen, KEY_POWER);
	}
	else
#endif
    {
		SetKeyLongpressHandler(mmi_fmpapp_exit_normal_screen, KEY_END);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_normal_sreen_show
 * DESCRIPTION
 *  to draw screen of "start find device" 
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_normal_sreen_show(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	gdi_color black_color;
	gdi_color start_bg_color;
	int text_width,text_xpos,text_ypos = 0;
	int img_width,text_height, img_height,img_xpos,img_ypos = 0;
	int line_ypos_start, line_ypos_stop = 0;
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	black_color = GDI_RGB_TO_BUFFER_FORMAT(0,0,0);
	start_bg_color = GDI_RGB_TO_BUFFER_FORMAT(255,150,0);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_START_SHOW);
	
    gdi_layer_lock_frame_buffer();
	gdi_layer_clear(black_color);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_MAINMENU),&text_width,&text_height);
	text_xpos = (UI_DEVICE_WIDTH - text_width) / 2;
	text_ypos = YPOS_FIND_MY_DEVICE;
	gui_move_text_cursor(text_xpos,text_ypos);
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_MAINMENU));

	gdi_image_get_dimension_id(IMG_FMPAPP_FIND_NORMAL_ID,&img_width,&img_height);
	img_xpos = (UI_DEVICE_WIDTH - img_width) / 2;
	img_ypos = (YPOS_FIND_MY_DEVICE + text_height + YPOS_BETWWEN_STR_IMG);
	gdi_image_draw_id(img_xpos,img_ypos,IMG_FMPAPP_FIND_NORMAL_ID);

	line_ypos_start = (UI_DEVICE_HEIGHT - SIZE_BUTTONE_START_STOP - WIDTH_OF_LINE);
	line_ypos_stop = (line_ypos_start + WIDTH_OF_LINE);
	gui_draw_horizontal_line(0,UI_DEVICE_WIDTH,line_ypos_start,gui_color(0,0,0));

	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_START),&start_stop_width,&start_stop_height);
	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = line_ypos_stop + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,line_ypos_stop,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,start_bg_color,start_bg_color,0);
    gui_print_text((UI_string_type)GetString(STR_ID_FMP_START));

	gdi_layer_unlock_frame_buffer();
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_locator_connect_state
 * DESCRIPTION
 * to notify mmi task current connection state
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_locator_connect_state(char* rbd_addr, int connect_state)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_LOCATOR_CNNC, rbd_addr[0], rbd_addr[1],  
		rbd_addr[2], rbd_addr[3], rbd_addr[4], rbd_addr[5], connect_state);
	
	if ((NULL == rbd_addr) || 
		(memcmp(rbd_addr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp((char *)fmpl_bdaddr, rbd_addr, FMPL_BD_ADDR_SIZE) ||
		(0 == memcmp(&fmpl_bdaddr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)))) 
	{
		switch(connect_state)
		{
			s_conn_state = connect_state;
			case FMP_STATUS_DISCONNECTED:
			{
				/*close normal screen and popup about unconnection*/
				if (MMI_TRUE == to_alert)
				{
					mmi_fmpapp_exit_finding_screen();						
				}
				if (memcmp(&fmpl_bdaddr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)) != 0)
				{
					memset(fmpl_bdaddr, 0x00, FMPL_BD_ADDR_SIZE);
				}	
			}
				break;
				
			case FMP_STATUS_CONNECTED:
			{
				memset(fmpl_bdaddr, 0x00, FMPL_BD_ADDR_SIZE);
				memcpy((CHAR *)fmpl_bdaddr, rbd_addr, FMPL_BD_ADDR_SIZE);
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_LOCATOR_CNNC, fmpl_bdaddr[0], fmpl_bdaddr[1], 
					fmpl_bdaddr[2], fmpl_bdaddr[3], fmpl_bdaddr[4], fmpl_bdaddr[5], connect_state);
			}
				break;
				
			case FMP_STATUS_DISCONNECTING:
				break;
				
			case FMP_STATUS_CONNECTING:
				break;
				
			default:
				break;
		}
	}    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_locator_alert_notify_cb
 * DESCRIPTION
 * to notify mmi task start/stop alert result
 * PARAMETERS
 *  [addr] Remote bt device addr
 *  [alert_result] false(fail) or true(success)
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_locator_alert_notify_cb(char* addr,int alert_result)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_LOCATOR_ALERT_CB, addr[0], addr[1], 
		addr[2], addr[3], addr[4], addr[5], alert_result);

	if ((NULL == addr) || 
		(memcmp(addr, &base_addr, (sizeof(char) * FMPL_BD_ADDR_SIZE)) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp((char *)fmpl_bdaddr, addr, FMPL_BD_ADDR_SIZE) )
	{
		if (MMI_TRUE == alert_result )
		{
		    if (MMI_TRUE == to_alert)
		    {
				mmi_fmpapp_entry_finding_screen();
		    }
		}
		else
		{
			//to popup
		}
	}
	else
	{
	    return;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_down_hdlr_finding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_down_hdlr_finding(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL is_touch_feed = MMI_FALSE;
    mmi_pen_point_struct point; 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
    if (point.y > FMPAPP_BUTTON_START_Y)    
    {
		is_touch_feed = MMI_TRUE;  
    }
	if (is_touch_feed) 
	{  
		fmpapp_button_start_pos = pos;
		mmi_fmpapp_show_stop_button_str();
	}
	else
	{
		fmpapp_button_start_pos.x = 0;
		fmpapp_button_start_pos.y = 0;
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_move_hdlr_finding
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_move_hdlr_finding(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
    if (point.y < FMPAPP_BUTTON_START_Y)   
	{
		fmpapp_button_start_pos.x = 0;
		fmpapp_button_start_pos.y = 0;
	    mmi_fmpapp_show_stop_button_normal();
	}
	else
	{
		fmpapp_button_start_pos = pos;
		mmi_fmpapp_show_stop_button_str();
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_up_hdlr_finding
 * DESCRIPTION
 *  handle pen up event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_up_hdlr_finding(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
    if ((point.y > FMPAPP_BUTTON_START_Y))  
	{
		mmi_fmpapp_stop_clicked_cb();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
	}
	else
	{
		//do nothing
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_pen_empty_hdlr_finding
 * DESCRIPTION
 *  dummy screen
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_pen_empty_hdlr_finding(mmi_pen_point_struct pos)
{
	/*do nothing*/
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_exit_finding_screen
 * DESCRIPTION
 *  exit screen of "stop find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_exit_finding_screen(void)
{
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_fmpapp_pen_right_hdlr, NULL);
#endif

	to_alert = MMI_FALSE;
	fmpl_alert((char *)fmpl_bdaddr,MMI_FALSE);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_STOP_SHOW_CLOSE);
	
	if ((GRP_ID_FMPAPP_MAIN == group_id)&& (SCR_ID_FMPAPP_STOP == scrn_id))
	{
		mmi_frm_scrn_close_active_id();
	}
	else
	{
		mmi_frm_scrn_close(GRP_ID_FMPAPP_MAIN,SCR_ID_FMPAPP_STOP);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_exit_finding_screen_proc
 * DESCRIPTION
 *  incative sreen
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_exit_finding_screen_proc(void)
{
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_fmpapp_pen_right_hdlr, NULL);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_entry_finding_screen
 * DESCRIPTION
 *  screen of "stop find device" 
 * PARAMETERS
 *  [grp]parent's group ID
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_entry_finding_screen(void)
{
	if (!mmi_frm_scrn_enter(
		 GRP_ID_FMPAPP_MAIN, 
		 SCR_ID_FMPAPP_STOP, 
		 mmi_fmpapp_exit_finding_screen_proc,
		 //NULL,
		 (FuncPtr)mmi_fmpapp_entry_finding_screen, 
		 MMI_FRM_FULL_SCRN))
    {
    	return;
    }
	
	/* do not allow popup sliding for this waiting popup */
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_ENTER_STOP);
	mmi_fmpapp_finding_sreen_show();
	
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_fmpapp_pen_right_hdlr, NULL);
#endif

#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler(mmi_fmpapp_pen_down_hdlr_finding);
	mmi_pen_register_up_handler(mmi_fmpapp_pen_up_hdlr_finding);
	mmi_pen_register_move_handler(mmi_fmpapp_pen_move_hdlr_finding);
	mmi_pen_register_abort_handler(mmi_fmpapp_pen_empty_hdlr_finding);	  
	mmi_pen_register_repeat_handler(mmi_fmpapp_pen_empty_hdlr_finding);
	mmi_pen_register_long_tap_handler(mmi_fmpapp_pen_empty_hdlr_finding);
#endif /* __MMI_TOUCH_SCREEN__ */ 

    SetKeyHandler(mmi_fmpapp_exit_finding_screen, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_fmpapp_exit_finding_screen, KEY_BACK, KEY_EVENT_UP);

#ifdef __MMI_WEARABLE_DEVICE__	
	if (mmi_frm_kbd_is_key_supported(KEY_POWER))
	{
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
		 SetKeyHandler(mmi_fmpapp_exit_finding_screen, KEY_POWER, KEY_EVENT_UP);
		 SetKeyLongpressHandler(mmi_fmpapp_exit_finding_screen, KEY_POWER);
	}
	else
#endif
    {
		SetKeyLongpressHandler(mmi_fmpapp_exit_finding_screen, KEY_END);
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_finding_sreen_show
 * DESCRIPTION
 *  to draw screen of "stop find device" 
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_finding_sreen_show(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	gdi_color black_color;
	gdi_color stop_color;
	int text_width,text_xpos,text_ypos = 0;
	int img_width,text_height, img_height,img_xpos,img_ypos = 0;
	int line_ypos_start, line_ypos_stop = 0;
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	black_color = GDI_RGB_TO_BUFFER_FORMAT(0,0,0);
	stop_color = GDI_RGB_TO_BUFFER_FORMAT(255,150,0);//243,154,30
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_STOP_SHOW);
	gdi_layer_lock_frame_buffer();
	gdi_layer_clear(black_color);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_MAINMENU),&text_width,&text_height);
	text_xpos = (UI_DEVICE_WIDTH - text_width) / 2;
	text_ypos = YPOS_FIND_MY_DEVICE;
	gui_move_text_cursor(text_xpos,text_ypos);
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_MAINMENU));

	gdi_image_get_dimension_id(IMG_FMPAPP_FINDING_DEVICE_ID,&img_width,&img_height);
	img_xpos = (UI_DEVICE_WIDTH - img_width) / 2;
	img_ypos = (YPOS_FIND_MY_DEVICE + text_height + YPOS_BETWWEN_STR_IMG);
	gdi_image_draw_animation_id(img_xpos,img_ypos,IMG_FMPAPP_FINDING_DEVICE_ID,NULL);

	line_ypos_start = (UI_DEVICE_HEIGHT - SIZE_BUTTONE_START_STOP - WIDTH_OF_LINE);
	line_ypos_stop = (line_ypos_start + WIDTH_OF_LINE);
	gui_draw_horizontal_line(0,UI_DEVICE_WIDTH,line_ypos_start,gui_color(0,0,0));

	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_FMP_STOP),&start_stop_width,&start_stop_height);
	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = line_ypos_stop + (SIZE_BUTTONE_START_STOP - SIZE_STR_START_STOP ) / 2;
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,line_ypos_stop,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,stop_color,stop_color,0);	
	gui_print_text((UI_string_type)GetString(STR_ID_FMP_STOP));

	gdi_layer_unlock_frame_buffer();
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_stop_clicked_cb
 * DESCRIPTION
 * callback function of  clicking Stop key in screen of "stop find device" 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_fmpapp_stop_clicked_cb(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_ID group_id = 0;
    MMI_ID scrn_id = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_STOP_SHOW_CLOSE);
	to_alert = MMI_FALSE;
	fmpl_alert((char *)fmpl_bdaddr,MMI_FALSE);
	
    mmi_frm_get_active_scrn_id(&group_id, &scrn_id); 
	if ((GRP_ID_FMPAPP_MAIN == group_id)&& (SCR_ID_FMPAPP_STOP == scrn_id))
	{
		mmi_frm_scrn_close_active_id();
	}
	else
	{
		mmi_frm_scrn_close(GRP_ID_FMPAPP_MAIN,SCR_ID_FMPAPP_STOP);
	}
	mmi_fmpapp_entry_normal_screen();
}
/*Locator  Role end*/

/*Target role*/
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

/*AT Commond handle*/
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
#endif

#endif /* __MMI_BLE_FMP_SUPPORT__*/

