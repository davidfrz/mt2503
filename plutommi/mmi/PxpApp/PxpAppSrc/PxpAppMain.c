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
 *  PxpAppMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the Pxp application.
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
		 
#ifdef __MMI_BLE_PXP_SUPPORT__
#include "PxpAppGprot.h"
#include "PxpAppProt.h"
#include "PxpAppMain.h"
#include "AlertScreen.h"
#include "mmi_frm_scenario_gprot.h"
#include "MMI_conn_app_trc.h"

#include "mmi_rp_app_pxpapp_def.h"
#include "wgui_categories_popup.h"
#include "GpioSrvGprot.h"
#include "wgui_softkeys.h"
#include "ProfilesSrvGprot.h"
#include "PrxrSrv.h"
#include "Prxr_def.h"
#include "TouchScreenGprot_Int.h"

#include "PrxCommon.h"
#include "mmi_rp_srv_prof_def.h"
#include "BtcmSrvGprot.h"
#include "Gui_typedef.h"

#include "Mdi_audio.h"
#include "mmi_common_app_trc.h"
#include "kal_general_types.h"
#include "Unicodexdcl.h"
#include "kal_public_api.h"
#include "DebugInitDef_Int.h"
#include "GlobalResDef.h"
#include "AlertScreen.h"
#include "wgui_categories_util.h"
#include "mmi_frm_events_gprot.h"
#include "BootupSrvGprot.h"
#include "IdleGprot.h"
#include "gui_effect_oem.h"
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
#include "ScrLockerGprot.h"
#include "mmi_rp_app_scr_locker_def.h"
#endif
#include "mmi_frm_input_gprot.h"
#include "device.h"
#include "Mdi_audio.h"
#include "mmi_cb_mgr_gprot.h"

/*add for low power*/
#ifdef __MMI_BLE_LOW_POWER__
#include "GattcSrv.h"
#endif
// for check if on power off process
#include "ShutdownSrvGprot.h"

/****************************************************************************
 * Global define
 ****************************************************************************/
MMI_BOOL s_pxp_is_vibrating = MMI_FALSE;
int s_conn_status = 0;
mmi_pxp_app_context_struct g_pxpapp_cntx = {MMI_FALSE,MMI_FALSE,MMI_FALSE,0,MMI_PXP_ALERT_LEVEL_NO,MMI_PXP_ALERT_TYPE_NONE};  /*Global context of pxpapp*/
//prxr_callback_t *prxr_cb = NULL;
mmi_pen_point_struct pxpapp_button_ok_pos;

#define  PXP_BD_ADDR_SIZE                   6
char pxp_bdaddr[PXP_BD_ADDR_SIZE];
char pxp_base_addr[PXP_BD_ADDR_SIZE] = {0};
prxr_callback_t pxp_cb;
MMI_BOOL g_alert_disable = MMI_FALSE;


#define MMI_PXPAPP_SET_ADV_INTERVAL_TIME        (1000 * 30)
//#define MMI_PXPAPP_TARGET_ALERT_TIME        (1000 * 60)
#if defined(__MMI_MAINLCD_240X320__)
#define YPOS_ERROR_STRING                  15
#define YPOS_BETWWEN_STR_IMG               65
#define  PXPAPP_BUTTON_OK_Y               260
#else
#define YPOS_ERROR_STRING                  15
#define YPOS_BETWWEN_STR_IMG                 25
#define  PXPAPP_BUTTON_OK_Y               180
#endif
#define SIZE_BUTTONE_OK              60
#define WIDTH_OF_LINE                         1
#define SIZE_STR_OK                  22

/****************************************************************************
 * Function
 ****************************************************************************/
#ifdef __MMI_WEARABLE_DEVICE__
mmi_ret mmi_pxpapp_pen_right_hdlr(mmi_event_struct *evt);
#endif

/* For the detail information, please refer to the PxpAppGprot.h */
#if defined(__MMI_SCREEN_LOCK_ANY_TIME__) || defined(__MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__)
/*****************************************************************************
 * FUNCTION
 *  mmi_pxp_notify_screen_lock_hdlr
 * DESCRIPTION
 *  Pxp handle screen  lock function.
 * PARAMETERS
 *  evt     [IN]        The event for lock screen
 * RETURNS
 *  mmi_ret event handle result
 *****************************************************************************/
extern mmi_ret mmi_pxp_notify_screen_lock_hdlr(mmi_event_struct *evt)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SCREEN_LOCK);

	switch (evt->evt_id)
	{
		case EVT_ID_SCREEN_LOCK_KEY_PRE_LOCK_EVT_ROUTING:
		{
			if (g_pxpapp_cntx.is_popuping)
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
		}
			  break;
			  
	   default:
			return MMI_RET_OK;
	}
	return MMI_RET_OK;
}
#endif /*defined( __MMI_SCREEN_LOCK_ANY_TIME_WDEVICE__) && defined(__MMI_WEARABLE_DEVICE__)*/

/*add for low power*/
#if 0 
#ifdef __MMI_BLE_LOW_POWER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_BLE_LOW_POWER__*/
#endif
/*for low power end*/

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_server_init
 * DESCRIPTION
 *  to rigister callbacks and enable proximity reporter role
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of profile enable result
 *****************************************************************************/
void mmi_pxpapp_server_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE |
                 SRV_BT_CM_EVENT_PANIC_IND |
                 SRV_BT_CM_EVENT_ACTIVATE;
	
	srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_bt_event_notify_pxpapp, event_mask, NULL);
	return;	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_event_notify_pxpapp
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_event_notify_pxpapp(U32 event, void* para)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_PROC, event, 0);
    switch (event)
    {
        case SRV_BT_CM_EVENT_BLE_ACTIVATE:
            mmi_bt_power_on_to_init();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            mmi_bt_power_on_to_deinit();
            break;
#if 0			
#ifdef __MMI_BLE_LOW_POWER__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_BLE_LOW_POWER__ */
#endif
			
		default :
			break;
	}

}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_to_init
 * DESCRIPTION
 *  This function is to rigister ppxp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_to_init(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_INIT);
    /*rigister callback to enable reporter role*/
	pxp_cb.connection_state_cb = mmi_pxpapp_connection_state_cb;
	pxp_cb.alert_notify_cb = mmi_pxpapp_alert_notify_cb;
	pxp_cb.config_level_cb = mmi_pxpapp_config_level_alert;
	prxr_init(&pxp_cb);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_to_deinit
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_to_deinit(void)
{	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_DEINIT);
	/*derigister callback to unable reporter role*/
	prxr_deinit(&pxp_cb);
	pxp_cb.connection_state_cb = NULL;
	pxp_cb.alert_notify_cb = NULL;
	pxp_cb.config_level_cb = NULL;
	if (memcmp(&pxp_bdaddr, &pxp_base_addr, (sizeof(char) * PXP_BD_ADDR_SIZE)) != 0)
	{
		memset(pxp_bdaddr,0x00,PXP_BD_ADDR_SIZE);
	}
	mmi_pxpapp_lls_config_alert_disable();
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_config_level_alert
 * DESCRIPTION
 *  to notify reporter mmi task link loss alert level config result
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of LLS 
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_config_level_alert(char* bdaddr,U8 alert_level )
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONFIG_LEVEL, bdaddr[0], bdaddr[1], 
		bdaddr[2], bdaddr[3], bdaddr[4], bdaddr[5], alert_level);
	if ((NULL == bdaddr) || 
		(memcmp(bdaddr, &pxp_base_addr, (sizeof(char) * PXP_BD_ADDR_SIZE)) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp(&pxp_bdaddr, bdaddr, (sizeof(char) * PXP_BD_ADDR_SIZE)))
	{
		switch(alert_level)
		{
			case PRX_ALERT_LEVEL_NO:
			{
				mmi_pxpapp_lls_config_alert_disable();
			}
				break;
				
			case PRX_ALERT_LEVEL_MILD_RANGE:
			case PRX_ALERT_LEVEL_MILD:
			{
				g_pxpapp_cntx.pxp_lls_alert_level = MMI_PXP_ALERT_LEVEL_MILD;
				mmi_pxpapp_lls_config_alert();
			}
				break;
				
			case PRX_ALERT_LEVEL_HIGH_RANGE:
			case PRX_ALERT_LEVEL_HIGH:
			{
				g_pxpapp_cntx.pxp_lls_alert_level = MMI_PXP_ALERT_LEVEL_HIGH;
				mmi_pxpapp_lls_config_alert();
			}
				break;
				
			default:
				break;
		}	
	}	
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_lls_config_alert
 * DESCRIPTION
 *  to enable reporter 's  link loss alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_lls_config_alert(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONFIG_ALERT);
	
	g_pxpapp_cntx.is_config_alert = MMI_TRUE;
	/*light on idle*/
    srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	/*show status icons*/
	wgui_status_icon_bar_show_icon(STATUS_ICON_PXPAPP_CONFIG_ALERT);
	wgui_status_icon_bar_update();
}
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_lls_config_alert_disable
 * DESCRIPTION
 *  to disable reporter 's  link loss alert config
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_lls_config_alert_disable(void)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONFIG_ALERT_DISABLE);
	/*unshow status icons*/
	g_pxpapp_cntx.pxp_lls_alert_level = MMI_PXP_ALERT_LEVEL_NO;
	wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PXPAPP_CONFIG_ALERT);
	wgui_status_icon_bar_update();
	if (MMI_TRUE == g_pxpapp_cntx.is_config_alert)
	{
	    /*light off idle*/
		srv_backlight_turn_off();
		g_pxpapp_cntx.is_config_alert = MMI_FALSE;
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_connection_state_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_connection_state_cb(char* bdaddr, int connect_state)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONNECT_CB, bdaddr[0], bdaddr[1], bdaddr[2], 
		bdaddr[3], bdaddr[4], bdaddr[5], connect_state);
	
	if ((NULL == bdaddr) || 
		(memcmp(bdaddr, &pxp_base_addr, (sizeof(char) * PXP_BD_ADDR_SIZE)) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp((char *)pxp_bdaddr, bdaddr, PXP_BD_ADDR_SIZE) ||
		(0 == memcmp(&pxp_bdaddr, &pxp_base_addr, (sizeof(char) * PXP_BD_ADDR_SIZE)))) 
	{
		switch (connect_state)
		{
			/*according pxp profile connect status to handle diff things*/
			s_conn_status = connect_state;
			case PRX_STATUS_DISCONNECTED:
			{
	            /*for low power begain*/
#if 0
#ifdef __MMI_BLE_LOW_POWER__
/* under construction !*/
#endif
#endif
				/*for low power end*/
				g_pxpapp_cntx.pxp_alert_type = MMI_PXP_ALERT_TYPE_DISCONNECTED;
				
				/*unshow status icons*/
				wgui_status_icon_bar_reset_icon_display(STATUS_ICON_PXPAPP_CONFIG_ALERT);
				wgui_status_icon_bar_update();
				switch(g_pxpapp_cntx.pxp_lls_alert_level)
				{
					case MMI_PXP_ALERT_LEVEL_NO:
					{	
						if (g_pxpapp_cntx.is_popuping)
						{
							mmi_pxpapp_exit_notification_screen();						
						}
					}
						break;
						
					case MMI_PXP_ALERT_LEVEL_MILD:
	                {
						if (g_pxpapp_cntx.is_popuping)
						{
							mmi_pxpapp_exit_notification_screen();	
						}
						if (!srv_shutdown_is_running())
						{

						    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
							    MMI_EVENT_BLE_APP_ALERT,
							    mmi_pxpapp_launch_enter_popup,
							    NULL);
						}
	                }
						break;
						
					case MMI_PXP_ALERT_LEVEL_HIGH:
	                {
						if (g_pxpapp_cntx.is_popuping)
						{
							mmi_pxpapp_exit_notification_screen();	
						}
						if (!srv_shutdown_is_running())
	                    {
						    mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
							    MMI_EVENT_BLE_APP_ALERT,
							    mmi_pxpapp_launch_enter_popup,
							    NULL);
						}
	                }
						break;
						
					default:
						break;
				}
				memset(pxp_bdaddr,0x00,PXP_BD_ADDR_SIZE);
				g_pxpapp_cntx.pxp_lls_alert_level = MMI_PXP_ALERT_LEVEL_NO;
			}
				break;
				
			case PRX_STATUS_CONNECTING:
				break;
				
			case PRX_STATUS_CONNECTED:
			{
				/*for low power begain*/
#if 0
#ifdef __MMI_BLE_LOW_POWER__
/* under construction !*/
#endif
#endif
				memset(pxp_bdaddr,0x00,PXP_BD_ADDR_SIZE);
		        memcpy((char *)pxp_bdaddr, bdaddr, PXP_BD_ADDR_SIZE);
			
	            /*reconnect*/
				if (g_pxpapp_cntx.is_popuping)
				{
					mmi_pxpapp_exit_notification_screen();						
				}
			}
				break;	
				
			case PRX_STATUS_DISCONNECTING:
				break;
				
			default:
				break;
				
		}
	}    
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_alert_notify_cb
 * DESCRIPTION
 *  to notify reporter mmi task start/stop path loss alert(IAS)
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of IAS
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_alert_notify_cb(char* bdaddr, U8 alert_level)
{
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_CB, bdaddr[0], bdaddr[1], bdaddr[2], 
		bdaddr[3], bdaddr[4], bdaddr[5], alert_level);
	if ((NULL == bdaddr) || 
		(memcmp(bdaddr, &pxp_base_addr, (sizeof(char) * PXP_BD_ADDR_SIZE)) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp(&pxp_bdaddr, bdaddr, (sizeof(char) * PXP_BD_ADDR_SIZE)))
	{
		switch(alert_level)
		{
			case PRX_ALERT_LEVEL_NO:
			{
				g_alert_disable = MMI_TRUE;
				if (g_pxpapp_cntx.is_popuping)
				{
					mmi_pxpapp_exit_notification_screen();
				}
		    }
				break;
				
			case PRX_ALERT_LEVEL_MILD:
	        {	
				g_pxpapp_cntx.pxp_alert_type = MMI_PXP_ALERT_TYPE_FIND_DEVICE;
				if (!g_pxpapp_cntx.is_popuping)
				{
					mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
					MMI_EVENT_BLE_APP_ALERT,
					mmi_pxpapp_launch_enter_popup,
					NULL);
				}
	        }
				break;
				
			case PRX_ALERT_LEVEL_HIGH:
	        {	
				g_pxpapp_cntx.pxp_alert_type = MMI_PXP_ALERT_TYPE_FIND_DEVICE;
				if (!g_pxpapp_cntx.is_popuping)
				{
					mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
					MMI_EVENT_BLE_APP_ALERT,
					mmi_pxpapp_launch_enter_popup,
					NULL);
				}
	        }
				break;
				
			case PRX_ALERT_LEVEL_MILD_RANGE:
	        {	
				g_pxpapp_cntx.pxp_alert_type = MMI_PXP_ALERT_TYPE_OUT_IN_RANGE;
				if (!g_pxpapp_cntx.is_popuping)
				{
					mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
					MMI_EVENT_BLE_APP_ALERT,
					mmi_pxpapp_launch_enter_popup,
					NULL);
				}
	        }
				break;
				
			case PRX_ALERT_LEVEL_HIGH_RANGE:
	        {	
				g_pxpapp_cntx.pxp_alert_type = MMI_PXP_ALERT_TYPE_OUT_IN_RANGE;
				if (!g_pxpapp_cntx.is_popuping)
				{
					mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_BLE_APP_ALERT,
						MMI_EVENT_BLE_APP_ALERT,
						mmi_pxpapp_launch_enter_popup,
						NULL);
				}
	        }
				break;
				
			default:
				break;
		}
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_launch_enter_popup
 * DESCRIPTION
 *  launch point of pxpapp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_launch_enter_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ENTER_POPUP);
	grp_id = mmi_frm_group_create(
				GRP_ID_ROOT,
				GRP_ID_PXPAPP_MAIN,
				mmi_pxpapp_grp_proc,
				NULL);
	mmi_frm_group_enter(grp_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);
    mmi_pxpapp_entry_notification_screen();
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_pxpapp_grp_proc(mmi_event_struct *evt)
{
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CLOSE_POPUP);
			mmi_frm_group_close(GRP_ID_PXPAPP_MAIN);
		}
			break;
			
		default:
			break;

	}
	return MMI_OK;

}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_up_hdlr
 * DESCRIPTION
 *  handle pen up event
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_up_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;		
    if((point.y > PXPAPP_BUTTON_OK_Y) &&(pxpapp_button_ok_pos.y > PXPAPP_BUTTON_OK_Y))  
	{
		pxpapp_button_ok_pos.x = 0;
		pxpapp_button_ok_pos.y = 0;
		mmi_pxpapp_show_button_str();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
		
		if (g_pxpapp_cntx.is_popuping)
		{
			mmi_pxpapp_exit_notification_screen();
		}
	}
	else
	{
	    mmi_pxpapp_show_button_normal();
		gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
	}
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_empty_hdlr
 * DESCRIPTION
 *  dummy scrren
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_empty_hdlr(mmi_pen_point_struct pos)
{
	/*do nothing*/
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_show_button_str
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_pxpapp_show_button_str(void)
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
	gui_measure_string((UI_string_type)GetString(STR_ID_PXP_OK),&start_stop_width,&start_stop_height);
	
	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = PXPAPP_BUTTON_OK_Y + (SIZE_BUTTONE_OK - SIZE_STR_OK ) / 2;
	
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,PXPAPP_BUTTON_OK_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);
	gui_print_text((UI_string_type)GetString(STR_ID_PXP_OK));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_show_button_normal
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of the profile initial
 *****************************************************************************/
void mmi_pxpapp_show_button_normal(void)
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
	gui_measure_string((UI_string_type)GetString(STR_ID_PXP_OK),&start_stop_width,&start_stop_height);
	
	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = PXPAPP_BUTTON_OK_Y + (SIZE_BUTTONE_OK - SIZE_STR_OK ) / 2;
	
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,PXPAPP_BUTTON_OK_Y,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,bg_color,bg_color,0);
	gui_print_text((UI_string_type)GetString(STR_ID_PXP_OK));
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_down_hdlr
 * DESCRIPTION
 *  dummy scrren
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_down_hdlr(mmi_pen_point_struct pos)
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
    if(point.y > PXPAPP_BUTTON_OK_Y)    
    {
		is_touch_feed = MMI_TRUE;  
    }
	if (is_touch_feed) 
	{  
	    pxpapp_button_ok_pos = pos;
		mmi_pxpapp_show_button_str();
	}
	else
	{
		pxpapp_button_ok_pos.x = 0;
		pxpapp_button_ok_pos.y = 0;
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_move_hdlr
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_pen_move_hdlr(mmi_pen_point_struct pos)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_pen_point_struct point;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    point = pos;
    if(point.y < PXPAPP_BUTTON_OK_Y)   
	{
		pxpapp_button_ok_pos.x = 0;
		pxpapp_button_ok_pos.y = 0;
	    mmi_pxpapp_show_button_normal();
	}
	else
	{
		pxpapp_button_ok_pos = pos;
		mmi_pxpapp_show_button_str();
	}
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_alert_sreen_show
 * DESCRIPTION
 *  to draw screen of  alert
 * PARAMETERS
 *  [evt]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_alert_sreen_show(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	gdi_color black_color;
	gdi_color ok_color;
	int text_width,text_xpos,text_ypos = 0;
	int img_width,text_height, img_height,img_xpos,img_ypos = 0;
	int line_ypos_start, line_ypos_stop = 0;
	int start_stop_width, start_stop_height,start_stop_xpos,start_stop_ypos = 0;
	U32 str_id = 0;
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	g_pxpapp_cntx.is_popuping = MMI_TRUE;
	black_color = GDI_RGB_TO_BUFFER_FORMAT(0,0,0);
	ok_color = GDI_RGB_TO_BUFFER_FORMAT(255,150,0);
	
	switch (g_pxpapp_cntx.pxp_alert_type)
	{
		case MMI_PXP_ALERT_TYPE_DISCONNECTED:
		{
			str_id = (U32)STR_ID_PXP_DISCONNECTED;
			g_pxpapp_cntx.image_id = (U16)IMG_PXPAPP_DISCONNECTED_ID;
		}
			break;
			
		case MMI_PXP_ALERT_TYPE_OUT_IN_RANGE:
		{
			str_id =(U32) STR_ID_PXP_OUT_RANGE;
			g_pxpapp_cntx.image_id = (U16)IMG_PXPAPP_RANGE_ALERT_ID;
		}
			break;

		case MMI_PXP_ALERT_TYPE_FIND_DEVICE:
		{
		 	str_id =(U32) STR_ID_ALERT_ID;
			g_pxpapp_cntx.image_id = (U16)IMG_PXPAPP_ALERT_ID;
		}
			break;
			
		default:
			break;
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_SHOW, str_id, g_pxpapp_cntx.image_id);
	gdi_layer_lock_frame_buffer();
	gdi_layer_clear(black_color);
	
	gui_set_text_color(gui_color(255,255,255));
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(str_id),&text_width,&text_height);
	text_xpos = (UI_DEVICE_WIDTH - text_width) / 2;
	text_ypos = YPOS_ERROR_STRING;
	gui_move_text_cursor(text_xpos,text_ypos);
	gui_print_text((UI_string_type)GetString(str_id));

	gdi_image_get_dimension_id(g_pxpapp_cntx.image_id,&img_width,&img_height);
	img_xpos = (UI_DEVICE_WIDTH - img_width) / 2;
	img_ypos = (YPOS_ERROR_STRING + text_height + YPOS_BETWWEN_STR_IMG);
	gdi_image_draw_id(img_xpos,img_ypos,g_pxpapp_cntx.image_id);

	line_ypos_start = (UI_DEVICE_HEIGHT - SIZE_BUTTONE_OK - WIDTH_OF_LINE);
	line_ypos_stop = (line_ypos_start + WIDTH_OF_LINE);
	gui_line(0,UI_DEVICE_WIDTH,line_ypos_start,line_ypos_stop,gui_color(0,0,0));//61,107,120
	gui_draw_horizontal_line(0,UI_DEVICE_WIDTH,line_ypos_start,gui_color(0,0,0));

	gui_set_text_color(gui_color(255,255,255));//52,149,165
	gui_set_font(&MMI_medium_font);
	gui_measure_string((UI_string_type)GetString(STR_ID_PXP_OK),&start_stop_width,&start_stop_height);
	start_stop_xpos = (UI_DEVICE_WIDTH - start_stop_width) / 2;
	start_stop_ypos = line_ypos_stop + (SIZE_BUTTONE_OK - SIZE_STR_OK ) / 2;
	gui_move_text_cursor(start_stop_xpos,start_stop_ypos);
	gdi_draw_frame_rect(0,line_ypos_stop,UI_DEVICE_WIDTH,UI_DEVICE_HEIGHT,ok_color,ok_color,0);
	gui_print_text((UI_string_type)GetString(STR_ID_PXP_OK));

	gdi_layer_unlock_frame_buffer();
	gui_BLT_double_buffer(0,0,UI_DEVICE_WIDTH -1,UI_DEVICE_HEIGHT -1);

}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_target_alert_enable
 * DESCRIPTION
 *  Display notification popup and play alarm tone when LLS or ALS come.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_target_alert_enable(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_ENABLE);
	/*light up the screen and ringing*/
    srv_backlight_turn_on(SRV_BACKLIGHT_PERMANENT);
	/*beep and vibration*/
	mdi_audio_suspend_background_play();
	srv_prof_play_tone_with_id(SRV_PROF_TONE_WARNING, 
							AUD_ID_PROF_RING1, 
						    SRV_PROF_RING_TYPE_REPEAT, 
							NULL);
	mdi_audio_set_volume(VOL_TYPE_MEDIA,MDI_AUD_VOL_MUTE(7));
	srv_vibrator_on();
	s_pxp_is_vibrating = MMI_TRUE;
  g_alert_disable = MMI_FALSE;
	g_pxpapp_cntx.is_alerting = MMI_TRUE;
}

#ifdef __MMI_WEARABLE_DEVICE__
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_pen_right_hdlr
 * DESCRIPTION
 *  handler of "pen right'.
 * PARAMETERS
 * 
 * RETURNS
 *  
 *****************************************************************************/
mmi_ret mmi_pxpapp_pen_right_hdlr(mmi_event_struct *evt)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_PEN_RIGHT);

	if (evt->evt_id == EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT)
	{
		gui_screen_switch_effect_block(MMI_TRUE);
		mmi_frm_end_scenario(MMI_SCENARIO_ID_BLE_APP_ALERT);

		if (g_pxpapp_cntx.pxp_alert_type == MMI_PXP_ALERT_TYPE_FIND_DEVICE)
		{
			U32 send_size = 0;
			U8 data = 1;
			U32 data_len = 1;
			//tell Sp to disable the PXP
			send_size = prxr_send_data(&data,data_len);
			if (data_len == send_size)
			{
			    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SEND_DATA_SUCCESS);
			}
			else
			{
			    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SEND_DATA_FAIL);
			}
		}
			
		if (g_pxpapp_cntx.is_alerting)
		{
			mmi_pxpapp_target_alert_disable();
		}
		
		if (g_pxpapp_cntx.is_popuping)
		{
			g_pxpapp_cntx.is_popuping = MMI_FALSE;
		}

		return MMI_RET_OK;
	}
	return MMI_RET_OK;
}
#endif

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_target_alert_disable
 * DESCRIPTION
 *  to stop alert and light off the screen and stop ringing
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_target_alert_disable(void)
{
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_DISABLE);
	/*light off the screen and stop ringing*/
    srv_backlight_turn_off();
	srv_vibrator_off();
	s_pxp_is_vibrating = MMI_FALSE;
	
	/*beep and vibration*/
	srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
	mdi_audio_resume_background_play();
	
	g_pxpapp_cntx.is_alerting = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_notification_popup_screen
 * DESCRIPTION
 *  Display notification popup and play alarm tone when LLS or ALS come.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_entry_notification_screen(void)
{   
	if (!mmi_frm_scrn_enter(
             GRP_ID_PXPAPP_MAIN, 
             SCR_ID_PXPAPP_POPUP, 
             mmi_pxpapp_exit_notification_screen_proc, 
             //NULL,
             (FuncPtr)mmi_pxpapp_entry_notification_screen, 
             MMI_FRM_FULL_SCRN))
    {
    	return;
    }
	
	gui_screen_switch_effect_block(MMI_TRUE);
	mmi_frm_start_scenario(MMI_SCENARIO_ID_BLE_APP_ALERT);
	mmi_pxpapp_alert_sreen_show();
	
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_reg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_pxpapp_pen_right_hdlr, NULL);
#endif

#ifdef __MMI_TOUCH_SCREEN__
	mmi_pen_register_down_handler(mmi_pxpapp_pen_down_hdlr);
	mmi_pen_register_up_handler(mmi_pxpapp_pen_up_hdlr);
	mmi_pen_register_move_handler(mmi_pxpapp_pen_move_hdlr);
	mmi_pen_register_abort_handler(mmi_pxpapp_pen_empty_hdlr);	  
	mmi_pen_register_repeat_handler(mmi_pxpapp_pen_empty_hdlr);
	mmi_pen_register_long_tap_handler(mmi_pxpapp_pen_empty_hdlr);
#endif /* __MMI_TOUCH_SCREEN__ */

    SetKeyHandler(mmi_pxpapp_exit_notification_screen, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_pxpapp_exit_notification_screen, KEY_BACK, KEY_EVENT_UP);

#ifdef __MMI_WEARABLE_DEVICE__	
	if (mmi_frm_kbd_is_key_supported(KEY_POWER))
	{
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_UP);
		 ClearKeyHandler(KEY_POWER, KEY_EVENT_DOWN);
		 SetKeyHandler(mmi_pxpapp_exit_notification_screen, KEY_POWER, KEY_EVENT_DOWN);
		 SetKeyLongpressHandler(mmi_pxpapp_exit_notification_screen, KEY_POWER);
	}
	else
#endif
    {
		SetKeyLongpressHandler(mmi_pxpapp_exit_notification_screen, KEY_END);
    }

	mmi_pxpapp_target_alert_enable();

}
/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_exit_notification_screen
 * DESCRIPTION
 *  Disapear notification popup and play alarm tone when LLS or ALS come.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_exit_notification_screen(void)
{
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_pxpapp_pen_right_hdlr, NULL);
#endif	
	gui_screen_switch_effect_block(MMI_TRUE);
	mmi_frm_end_scenario(MMI_SCENARIO_ID_BLE_APP_ALERT);
	
	if ((g_pxpapp_cntx.pxp_alert_type == MMI_PXP_ALERT_TYPE_FIND_DEVICE) && (!g_alert_disable))
	{
		U32 send_size = 0;
		U8 data = 1;
		U32 data_len = 1;
		//tell Sp to disable the PXP
		send_size = prxr_send_data(&data,data_len);
		if (data_len == send_size)
		{
		    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SEND_DATA_SUCCESS);
		}
		else
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SEND_DATA_FAIL);
		}
	}
	
	if (g_pxpapp_cntx.is_popuping)
	{
		g_pxpapp_cntx.is_popuping = MMI_FALSE;
	}

	if (g_pxpapp_cntx.is_alerting)
	{
		mmi_pxpapp_target_alert_disable();
	}

	if (g_alert_disable)
	{
		g_alert_disable = MMI_FALSE;
	}

	mmi_frm_scrn_close(GRP_ID_PXPAPP_MAIN,SCR_ID_PXPAPP_POPUP); 

}

/*****************************************************************************
 * FUNCTION
 *  mmi_pxpapp_exit_notification_screen_proc
 * DESCRIPTION
 *  Disapear notification popup and play alarm tone when LLS or ALS come.
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_pxpapp_exit_notification_screen_proc(void)
{
	/*stop alarm ring*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_EXIT_SCREEN_PROC);
#ifdef __MMI_WEARABLE_DEVICE__
	mmi_frm_cb_dereg_event(EVT_ID_WEARABLE_DEVICE_MOVE_RIGHT, mmi_pxpapp_pen_right_hdlr, NULL);
#endif

	srv_vibrator_off();
	s_pxp_is_vibrating = MMI_FALSE;
	/*beep and vibration*/
	srv_prof_stop_tone(SRV_PROF_TONE_WARNING);
}

/*AT commond*/
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
#endif


#endif /*__MMI_BLE_PXP_SUPPORT__*/


