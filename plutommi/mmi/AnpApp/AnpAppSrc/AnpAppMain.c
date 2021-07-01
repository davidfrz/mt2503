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

				  
#ifdef __MMI_BLE_ANP_SUPPORT__

#include "AnpAppGprot.h"
#include "AnpAppProt.h"
#include "AnpAppMain.h"
#include "mmi_rp_app_anpapp_def.h"
#include "AnpcSrv.h"
#include "BtcmSrvGprot.h"
#include "GpioSrvGprot.h"
#include "wgui_softkeys.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "CommonScreens.h"
#include "MMI_conn_app_trc.h"
#include "TouchScreenGprot_Int.h"


#include "MMI_common_app_trc.h"
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



/****************************************************************************
 * Global and define
 ****************************************************************************/
 
/* Time interval to expiry and show finding stop screen in FMPAPP. */
#define CATEGORY_BIT_SIMPLE_ALERT          0x0001
#define CATEGORY_BIT_EMAIL          0x0002
#define CATEGORY_BIT_NEWS          0x0004
#define CATEGORY_BIT_CALL          0x0008
#define CATEGORY_BIT_MISSED_CALL        0x0010
#define CATEGORY_BIT_SMS_MMS          0x0020
#define CATEGORY_BIT_VOICE_MAIL          0x0040
#define CATEGORY_BIT_SCHEDULE         0x0080
#define CATEGORY_BIT_HIGH_PRIORITIZED_ALERT          0x0100
#define CATEGORY_BIT_INSTANT_MESSAGE         0x0200
#define CATEGORY_BIT_INSTANT_NOTIFY         0x2000




#define CATEGORY_ID_SIMPLE_ALERT 0x00
#define CATEGORY_ID_EMAIL        0x01
#define CATEGORY_ID_NEWS         0x02
#define CATEGORY_ID_CALL         0x03
#define CATEGORY_ID_MISSED_CALL  0x04
#define CATEGORY_ID_SMS_MMS      0x05
#define CATEGORY_ID_VOICE_MAIL   0x06
#define CATEGORY_ID_SCHEDULE     0x07
#define CATEGORY_ID_HIGH_PRIORITIZED_ALERT 0x08
#define CATEGORY_ID_INSTANT_MESSAGE 0x09
#define CATEGORY_ID_NOTIFY 0x13



#define ANPC_ALERT_ON                          0x01
#define ANPC_ALERT_OFF                         0x00



kal_uint8 anpc_alert_info[ANP_MAX_INFO_LENGTH];
kal_uint8 anpc_alert_num = 0;

U32 anpc_str_id = 0;
WCHAR popup_str[60] = {0};
kal_uint8 base_alert_info[ANP_MAX_INFO_LENGTH] = {0};
U8 new_message_flag = 0;
U8 unread_message_flag = 0;
//BD_ADDR *anpc_addr;

srv_prof_tone_enum anpc_tone_id;
kal_uint16 new_category_bit;
kal_uint16 unread_category_bit;



/*****************************************************************************
 * FUNCTION
 *  mmi_anpapp_client_init
 * DESCRIPTION
 *  to initial app client role
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_anpapp_client_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_CLIENT_INIT);
	event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
				 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)mmi_bt_event_notify_anpapp_client, event_mask, NULL);
	return; 
}


/*****************************************************************************
 * FUNCTION
 *  mmi_bt_event_notify_anpapp_client
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_event_notify_anpapp_client(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case SRV_BT_CM_EVENT_BLE_ACTIVATE:
            mmi_bt_power_on_init_anpc();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            mmi_bt_power_on_deinit_anpc();
            break;

		default :
			break;
	}
}

static MMI_BOOL mmi_anpapp_entry_notification_screen_by_nmgr(mmi_scenario_id scen_id, void *arg)
{

	mmi_anpapp_entry_notification_screen();
	return MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_anpapp_launch_enter_popup
 * DESCRIPTION
 *  launch point of anpapp
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_anpapp_launch_enter_popup(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	mmi_id grp_id;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_ENTER_POPUP);
	grp_id = mmi_frm_group_create(
				GRP_ID_ROOT,
				GRP_ID_ANPAPP_MAIN,
				mmi_anpapp_grp_proc,
				NULL);
	mmi_frm_group_enter(grp_id,MMI_FRM_NODE_SMART_CLOSE_FLAG);
	mmi_frm_nmgr_notify_by_app(MMI_SCENARIO_ID_DEFAULT,MMI_EVENT_DEFAULT,mmi_anpapp_entry_notification_screen_by_nmgr,NULL);
    
}
/*****************************************************************************
 * FUNCTION
 *  mmi_anpapp_grp_proc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
MMI_RET mmi_anpapp_grp_proc(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	switch (evt->evt_id)
	{
		case EVT_ID_GROUP_DEINIT:
		{
			//mmi_pxpapp_free_cntx();
			//MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_CLOSE_POPUP);
			mmi_frm_group_close(GRP_ID_ANPAPP_MAIN);
		}
			break;
		default:
			break;

	}
	return MMI_OK;

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
void mmi_anpapp_exit_notification_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	/*stop alarm ring*/
	srv_prof_stop_tone(SRV_PROF_TONE_SMS);
	srv_vibrator_off();
    //srv_backlight_turn_off();
	mmi_frm_scrn_close(GRP_ID_ANPAPP_MAIN,SCR_ID_ANPAPP_SHOW); 
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
void mmi_anpapp_alert_sreen_show(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	//(UI_string_type)GetString(STR_ID_ANP_VIEW),
	srv_backlight_turn_on(SRV_BACKLIGHT_SHORT_TIME);
	wgui_showcategory6333_screen(NULL,
								(UI_string_type)GetString(STR_GLOBAL_OK),
								NULL,
								(UI_string_type)popup_str,
								NULL);
	
    SetLeftSoftkeyFunction(mmi_anpapp_exit_notification_screen, KEY_EVENT_UP);
    SetRightSoftkeyFunction(mmi_anpapp_exit_notification_screen,KEYBOARD_KEY_UP);
}

/*****************************************************************************
 * FUNCTION
 *  mmi_anpapp_entry_notification_screen
 * DESCRIPTION
 *  Display notification popup 
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_anpapp_entry_notification_screen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if (!mmi_frm_scrn_enter(
             GRP_ID_ANPAPP_MAIN, 
             SCR_ID_ANPAPP_SHOW, 
             mmi_anpapp_exit_notification_screen, 
             (FuncPtr)mmi_anpapp_entry_notification_screen, 
             MMI_FRM_FULL_SCRN))
    {
    	return;
    }
	mmi_anpapp_alert_sreen_show();
#if 0
#ifdef __MMI_TOUCH_SCREEN__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* __MMI_TOUCH_SCREEN__ */
#endif
    SetKeyHandler(mmi_anpapp_exit_notification_screen, KEY_END, KEY_EVENT_UP);
    SetKeyHandler(mmi_anpapp_exit_notification_screen, KEY_BACK, KEY_EVENT_UP);

	/*beep and vibration*/
	srv_prof_play_tone_with_id(SRV_PROF_TONE_SMS, 
							AUD_ID_PROF_TONE1, 
						    SRV_PROF_RING_TYPE_ONCE, 
							NULL);
	srv_vibrator_play_once();
	//srv_vibrator_on();


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
#endif
/*****************************************************************************
 * FUNCTION
 *  mmi_anpapp_client_cb
 * DESCRIPTION
 *  This function is to rigister anp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
static void mmi_anpapp_client_cb(anp_client_app_cb_param* param)
{
	WCHAR temp_alert_info[ANP_MAX_INFO_LENGTH];
    switch (param->evtid)
    {
		case ANPC_MMI_EVT_ENABLE_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_ENABLE_CNF,param->result);
	        if (param->result == OS_ANPC_STATUS_SUCCESS)
	        {
				srv_anp_client_listen(TRUE); 
			}
			else
			{
				/*error popup*/
				//mmi_popup_display();
			}
		}
			break;
		case ANPC_MMI_EVT_CONNEC_IND:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_CNNC_CNF,param->result);
	        if (param->result == OS_ANPC_STATUS_SUCCESS)
	        {
	            srv_anp_client_listen(FALSE);
	        	/* note the addr*/
				srv_anp_client_configure_alert(&param->bdaddr,ANPC_OPER_CONIFG_NEW_ALERT,ANPC_CONFIG_ALERT_ON);	
				/*to write the control point cmd*/
				//srv_anp_client_read_supported_new_alert_category_req(&param->bdaddr);
			}
			else
			{
	            /*show error popup*/
				//mmi_popup_display();
			}
		}
			break;
		case ANPC_MMI_EVT_DISCONNECT_IND:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_DISCONNECT_ND);
		}
			break;
		case ANPC_MMI_EVT_LISTEN_RESULT:
		{
			switch (param->result)
			{
			    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_LISTEN_CNF,param->result);
				case OS_ANPC_STATUS_SUCCESS:
				{
					#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#endif
				}
					break;
				case OS_ANPC_STATUS_FAILED:
				case OS_ANPC_STATUS_PENDING:
				default:
					break;
			}
		}
			break;
		case ANPC_MMI_EVT_READ_SUPPORTED_NEW_ALERT_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_NEW_CNF1,param->result);
			if (param->result == OS_ANPC_STATUS_SUCCESS)
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
#endif
//#if 0
                kal_uint8 cat_id = 0;
			    kal_uint16 cat_bits;
				for(cat_bits = 0x0001;cat_bits <= 0x8000;(cat_bits = cat_bits << 1))
				{
				    if (param->category_bit == 0)
				    {
	                    /*error popup*/
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_NEW_CNF2,param->category_bit,cat_id);
						return;
					}
					else if (cat_bits & param->category_bit)
					{
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_NEW_CNF2,cat_bits,cat_id);
						srv_anp_client_wirte_control_point(&param->bdaddr,
										 CMD_ENABLE_NEW_ALERT,
										 cat_id);
						new_category_bit = param->category_bit;
						new_category_bit &= ~cat_bits;
						break;
					}
					cat_id++;
				}
//#endif	
			}
			else
			{
	            /*error popup*/
			}
		}
			break;
		case ANPC_MMI_EVT_READ_SUPPORTED_UNREAD_ALERT_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_UNREAD_CNF1,param->result);
			if (param->result == OS_ANPC_STATUS_SUCCESS)
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
#endif
			//#if 0
				kal_uint8 cat_id = 0;
			    kal_uint16 cat_bits;
				for(cat_bits = 0x0001;cat_bits <= 0x8000;(cat_bits = cat_bits << 1))
				{
				    if (param->category_bit == 0)
				    {
				    
					    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_UNREAD_CNF2,param->category_bit,0);
	                    /*error popup*/
						//srv_anp_client_configure_alert(&param->bdaddr,ANPC_OPER_CONIFG_NEW_ALERT,ANPC_CONFIG_ALERT_ON);						
						return;
					}
					else if (cat_bits & param->category_bit)
					{
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_READ_UNREAD_CNF2,cat_bits,cat_id);
						srv_anp_client_wirte_control_point(&param->bdaddr,
										 CMD_ENABLE_UNREAD_ALERT,
										 cat_id);
						unread_category_bit = param->category_bit;
						unread_category_bit &= ~cat_bits;
						break;
					}
					cat_id++;
				}
			//#endif
				
			}
			else
			{
	            /*error popup*/
			}
		}
			break;
		case ANPC_MMI_EVT_NEW_ALERT_NOTIFY_IND:
		{
			switch (param->category_id)
			{
				case CATEGORY_ID_SIMPLE_ALERT:			
					if (param->alert_num != 0)
					{
			
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATIONS;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATION;
					   }  			
                        anpc_alert_num = param->alert_num;
					   	
					}
					memset(popup_str,0,sizeof(popup_str));
					
					kal_wsprintf(popup_str,
								"%d %w",
								anpc_alert_num,
								GetString(anpc_str_id)								
								);
					
					mmi_anpapp_launch_enter_popup();
					break;
	            case CATEGORY_ID_EMAIL:
				case CATEGORY_ID_NEWS:
					break;
				case CATEGORY_ID_CALL:	
				case CATEGORY_ID_MISSED_CALL:
				{
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_NEW_IND_MISSED_CALL,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);
					
					if (param->alert_num != 0)
					{
					   if(param->category_id == CATEGORY_ID_MISSED_CALL)
					   {
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MISSED_CALLS;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MISSED_CALL;
					   }
					   }
					   else
					   {
							anpc_str_id = (U32)STR_ID_ANP_INCOMING_CALL;
					   }
                        anpc_alert_num = param->alert_num;
					   	
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						mmi_chset_utf8_to_ucs2_string((kal_uint8 *)anpc_alert_info,ANP_MAX_INFO_LENGTH,param->alert_info);
						//mmi_ucs2_to_asc(anpc_alert_info, param->alert_info);
						//mmi_chset_utf8_to_ucs2_string(anpc_alert_info,ANP_MAX_INFO_LENGTH,param->alert_info);
						//memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
					memset(popup_str,0,sizeof(popup_str));
					if(param->category_id == CATEGORY_ID_CALL)
					{
				            if(!param->is_trucated)
					    {
						mmi_wsprintf(popup_str,60*2,STR_ID_ANP_INCOMING_CALL_EXT,anpc_alert_info);
					#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#endif
					    }
					    else
					    {
						mmi_wsprintf(popup_str,60*2,STR_ID_ANP_INCOMING_CALL_TRANCATE,anpc_alert_info, L"...");
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
					}
					else
					{
					kal_wsprintf(popup_str,
								"%d %w %w %w",
								anpc_alert_num,
								GetString(anpc_str_id),
								GetString(STR_ID_ANP_FROM),
								anpc_alert_info);
					}
						
					
					mmi_anpapp_launch_enter_popup();
				}
					break;
				case CATEGORY_ID_SMS_MMS:
				{
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_NEW_IND_SMS_MMS,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);

					if (param->alert_num != 0)
					{
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MESSAGES;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MESSAGE;
					   }
                        anpc_alert_num = param->alert_num;
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
				    memset(popup_str,0,sizeof(popup_str));
				    kal_wsprintf(popup_str,
							"%d %w %w %s",
							anpc_alert_num,
							GetString(anpc_str_id),
							GetString(STR_ID_ANP_FROM),
							anpc_alert_info);

				    mmi_anpapp_launch_enter_popup();

				}
					break;
				case CATEGORY_ID_VOICE_MAIL:
				case CATEGORY_ID_SCHEDULE:
				case CATEGORY_ID_HIGH_PRIORITIZED_ALERT:
				case CATEGORY_ID_INSTANT_MESSAGE:
					break;
				case CATEGORY_ID_NOTIFY:
				{
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_NEW_IND_NOTIFY,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);

					if (param->alert_num != 0)
					{
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATIONS;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATION;
					   }
						anpc_alert_num = param->alert_num;
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
					memset(popup_str,0,sizeof(popup_str));
					kal_wsprintf(popup_str,
							"%d %w %w %s",
							anpc_alert_num,
							GetString(anpc_str_id),
							GetString(STR_ID_ANP_FROM),
							anpc_alert_info);

					mmi_anpapp_launch_enter_popup();

				}

					break;
				default:
					break;
			}
		}
			break;
		case ANPC_MMI_EVT_UNREAD_ALERT_NOTIFY_IND:
		{
			switch (param->category_id)
			{
				case CATEGORY_ID_SIMPLE_ALERT:			
	            case CATEGORY_ID_EMAIL:
				case CATEGORY_ID_NEWS:
				case CATEGORY_ID_CALL:
					break;
				case CATEGORY_ID_MISSED_CALL:
				{
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_UNREAD_IND_MISSED_CALL,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);

					if (param->alert_num != 0)
					{
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MISSED_CALLS;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MISSED_CALL;
					   }
                        anpc_alert_num = param->alert_num;
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
					
				    memset(popup_str,0,sizeof(popup_str));
				    kal_wsprintf(popup_str,
							"%d %w %w %s",
							anpc_alert_num,
							GetString(anpc_str_id),
							GetString(STR_ID_ANP_FROM),
							anpc_alert_info);
					mmi_anpapp_launch_enter_popup();				
				}
					break;
				case CATEGORY_ID_SMS_MMS:
				{	
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_UNREAD_IND_SMS_MMS,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);

					if (param->alert_num != 0)
					{
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MESSAGES;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_MESSAGE;
					   }
                        anpc_alert_num = param->alert_num;
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
					
					memset(popup_str,0,sizeof(popup_str));
					kal_wsprintf(popup_str,
							"%d %w %w %s",
							anpc_alert_num,
							GetString(anpc_str_id),
							GetString(STR_ID_ANP_FROM),
							anpc_alert_info);
					mmi_anpapp_launch_enter_popup();

				}
					break;
				case CATEGORY_ID_VOICE_MAIL:
				case CATEGORY_ID_SCHEDULE:
				case CATEGORY_ID_HIGH_PRIORITIZED_ALERT:;
				case CATEGORY_ID_INSTANT_MESSAGE:
					break;
					
				case CATEGORY_ID_NOTIFY:
				{	
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_UNREAD_IND_NOTIFY,param->alert_num,param->alert_info[0],
						param->alert_info[1],param->alert_info[2],param->alert_info[3],param->alert_info[4],param->alert_info[5],
						param->alert_info[6],param->alert_info[7],param->alert_info[8],param->alert_info[9],param->alert_info[10],
						param->alert_info[11],param->alert_info[12],param->alert_info[13],param->alert_info[14],param->alert_info[15],
						param->alert_info[16],param->alert_info[17]);

					if (param->alert_num != 0)
					{
					   if (param->alert_num > 1)
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATIONS;
					   }
					   else
					   {
						   anpc_str_id = (U32)STR_ID_ANP_NOTIFICATION;
					   }
                        anpc_alert_num = param->alert_num;
					}
					if(memcmp(&(param->alert_info),&base_alert_info, (sizeof(kal_uint8) * ANP_MAX_INFO_LENGTH)) != 0)
					{
						memset(&anpc_alert_info,0x00,ANP_MAX_INFO_LENGTH);
						memcpy(&anpc_alert_info, &param->alert_info, ANP_MAX_INFO_LENGTH);
					}
					
					memset(popup_str,0,sizeof(popup_str));
					kal_wsprintf(popup_str,
							"%d %w %w %s",
							anpc_alert_num,
							GetString(anpc_str_id),
							GetString(STR_ID_ANP_FROM),
							anpc_alert_info);
					mmi_anpapp_launch_enter_popup();

				}	
					break;
					
				default:
					break;
			}
		}
			break;
		case ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF:
		{
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_WRITE_CP_CNF,param->cmd,param->result,param->category_id);
	        if ((param->cmd == CMD_ENABLE_NEW_ALERT) &&(param->result == OS_ANPC_STATUS_SUCCESS))
	        {
		        //#if 0
	            kal_uint8 cat_id = 0;
				kal_uint16 cat_bits;
				for(cat_bits = 0x0001;cat_bits <= 0x8000;(cat_bits = cat_bits << 1))
				{
				    if (new_category_bit == 0)
				    {
	                    /*error popup*/
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_WRITE_CP_NEW_CNF,new_category_bit,0);	
						//srv_anp_client_read_supported_unread_alert_category_req(&param->bdaddr);
						srv_anp_client_wirte_control_point(&param->bdaddr,
										 CMD_NOTIFY_NEW_ALERT_IMM,
										 0xFF);
						return;
					}
					else if (cat_bits & new_category_bit)
					{
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_WRITE_CP_NEW_CNF,cat_bits,cat_id);
						srv_anp_client_wirte_control_point(&param->bdaddr,
										 CMD_ENABLE_NEW_ALERT,
										 cat_id);
						new_category_bit &= ~cat_bits;
						break;
					}
					cat_id++;
				}
				//#endif
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
#endif
			}
			else if((param->cmd == CMD_NOTIFY_NEW_ALERT_IMM) &&(param->result == OS_ANPC_STATUS_SUCCESS))
			{
				srv_anp_client_read_supported_unread_alert_category_req(&param->bdaddr);

			}
			else if ((param->cmd == CMD_ENABLE_UNREAD_ALERT) &&(param->result == OS_ANPC_STATUS_SUCCESS))
			{
			//#if 0
	            kal_uint8 cat_id = 0;
				kal_uint16 cat_bits;
				for(cat_bits = 0x0001;cat_bits <= 0x8000;(cat_bits = cat_bits << 1))
				{
				    if (unread_category_bit == 0)
				    {
	                    /*error popup*/
						
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_WRITE_CP_UNREAD_CNF,unread_category_bit,0);
						srv_anp_client_configure_alert(&param->bdaddr,ANPC_OPER_CONIFG_NEW_ALERT,ANPC_CONFIG_ALERT_ON);
						return;
					}
					else if (cat_bits & unread_category_bit)
					{
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_WRITE_CP_UNREAD_CNF,cat_bits,cat_id);
						srv_anp_client_wirte_control_point(&param->bdaddr,
										 CMD_ENABLE_UNREAD_ALERT,
										 cat_id);
						unread_category_bit &= ~cat_bits;
						break;
					}
					cat_id++;
				}
			//#endif
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
			}
			else
			{
				/*error popup*/
				//mmi_display_popup(UI_string_type string,mmi_event_notify_enum event_id);
			}
		}
			break;
		case ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF:
		{
			if (param->result == OS_ANPC_STATUS_SUCCESS)
			{
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_CONFIG_NEW_CNF);
				srv_anp_client_configure_alert(&param->bdaddr,ANPC_OPER_CONFIG_UNREAD_ALERT,ANPC_CONFIG_ALERT_ON);
			}
			else
			{
				/*error popup*/
			}
		}
			break;
		case ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF:
		{
			if (param->result == OS_ANPC_STATUS_SUCCESS)
			{
				srv_anp_client_read_supported_new_alert_category_req(&param->bdaddr);
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_CONFIG_UNREAD_CNF);
		        /*nothing*/
			}
			else
			{
				/*error popup*/
			}
		}
			break;
		default:
			break;
		
	}
	return;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_init_anpc
 * DESCRIPTION
 *  This function is to rigister anp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_init_anpc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_BTC_SWITCH_ON);
	srv_anp_client_enable(mmi_anpapp_client_cb);
	return ;
}

/*****************************************************************************
 * FUNCTION
 *  mmi_bt_power_on_deinit_anpc
 * DESCRIPTION
 *  This function is to unregister service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_bt_power_on_deinit_anpc(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_ANPAPP_BTC_SWITCH_OFF);
	srv_anp_client_disable();
	return;
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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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

#endif /* __MMI_BLE_PXP_SUPPORT__*/

