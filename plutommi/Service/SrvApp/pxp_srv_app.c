#include "MMI_features.h"

#ifdef __MMI_BLE_PXP_SUPPORT__

#include "MMIDataType.h"
#include "MMITimer.h"
#include "PrxrSrv.h"
#include "PrxCommon.h"
#include "BtcmSrvGprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "GpioSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_srv_gatt_app_def.h"


#define PXP_SRV_APP_TARGET_ALERT_TIME        (1000 * 60)

static void pxp_srv_app_event_notify(U32 event, void* para);
static void pxp_srv_app_target_alert_disable(void);


prxr_callback_t pxp_cb_cntx;
static MMI_BOOL is_alerting = MMI_FALSE;

/*****************************************************************************
 * FUNCTION
 *  fmpt_srv_app_target_alert_enable
 * DESCRIPTION
 *  to start alert
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_target_alert_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "pxp_srv_app_target_alert_enable");
    if (is_alerting == MMI_TRUE)
    {
        return;
    }
	StartTimer(PXP_SRV_APP_ALERT_TIMER, PXP_SRV_APP_TARGET_ALERT_TIME, pxp_srv_app_target_alert_disable);
	/*beep and vibration*/
	srv_prof_play_tone_with_id(SRV_PROF_TONE_ALARM, 
							AUD_ID_PROF_RING1, 
						    SRV_PROF_RING_TYPE_REPEAT, 
							NULL);
	srv_vibrator_on();
	is_alerting = MMI_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_target_alert_enable
 * DESCRIPTION
 *  to stop alert
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_target_alert_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "pxp_srv_app_target_alert_disable");
    if (is_alerting == MMI_FALSE)
    {
        return;
    }
	StopTimer(PXP_SRV_APP_TARGET_ALERT_TIME);
	/*beep and vibration*/
	srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
	srv_vibrator_off();
	is_alerting = MMI_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_connection_state_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_connection_state_cb(char* bdaddr, int connect_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONNECT_CB,bdaddr,connect_state);
	switch (connect_state)
	{
		/*according pxp profile connect status to handle diff things*/
		case PRX_STATUS_DISCONNECTED:
		{
			pxp_srv_app_target_alert_enable();
		}
			break;
		case PRX_STATUS_CONNECTING:
			break;
		case PRX_STATUS_CONNECTED:
			//do nothing
			break;	
		case PRX_STATUS_DISCONNECTING:
			break;
		default:
			break;

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
void pxp_srv_app_alert_notify_cb(char* bdaddr, U8 alert_level)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//char* rbd_addr;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_ALERT_CB,bdaddr,alert_level);
	//mmi_pxpapp_create_cntx();
	switch(alert_level)
	{
		case PRX_ALERT_LEVEL_NO:
		{
            pxp_srv_app_target_alert_disable();
	    }
			break;
		case PRX_ALERT_LEVEL_MILD:
        {
            pxp_srv_app_target_alert_enable();
        }
			break;
		case PRX_ALERT_LEVEL_HIGH:
        {
            pxp_srv_app_target_alert_enable();
        }
			break;
		default:
			break;

	}

}

/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_config_level_alert
 * DESCRIPTION
 *  to notify reporter mmi task link loss alert level config result
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of LLS 
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_config_level_alert(char* bdaddr,U8 alert_level )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//char* rbd_addr = NULL;
    U8 temp_alert_level;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_CONFIG_LEVEL,bdaddr,alert_level);
	//mmi_pxpapp_create_cntx();
	switch(alert_level)
	{
		case PRX_ALERT_LEVEL_NO:
			temp_alert_level = PRX_ALERT_LEVEL_NO;
			break;
		case PRX_ALERT_LEVEL_MILD:
			temp_alert_level = PRX_ALERT_LEVEL_MILD;
			break;
		case PRX_ALERT_LEVEL_HIGH:
			temp_alert_level = PRX_ALERT_LEVEL_HIGH;				
			break;
		default:
			break;
	}
    // save the temp_alert_level to NVRAM
}


/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_power_on_to_init
 * DESCRIPTION
 *  This function is to rigister ppxp profile CBs
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_power_on_to_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	//prxr_callback_t pxp_cb_cntx;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_INIT);
    /*rigister callback to enable reporter role*/
	pxp_cb_cntx.connection_state_cb = pxp_srv_app_connection_state_cb;
	pxp_cb_cntx.alert_notify_cb = pxp_srv_app_alert_notify_cb;
	pxp_cb_cntx.config_level_cb = pxp_srv_app_config_level_alert;
	prxr_init(&pxp_cb_cntx);
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
void pxp_srv_power_on_to_deinit(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_DEINIT);
	/*derigister callback to unable reporter role*/
	prxr_deinit(&pxp_cb_cntx);
	pxp_cb_cntx.connection_state_cb = NULL;
	pxp_cb_cntx.alert_notify_cb = NULL;
	pxp_cb_cntx.config_level_cb = NULL;
	return;
}

/*****************************************************************************
 * FUNCTION
 *  pxp_srv_app_init
 * DESCRIPTION
 *  to rigister callbacks and enable proximity reporter role
 * PARAMETERS
 *  void
 * RETURNS
 *  Status of profile enable result
 *****************************************************************************/
void pxp_srv_app_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    event_mask = SRV_BT_CM_EVENT_ACTIVATE |
                 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)pxp_srv_app_event_notify, event_mask, NULL);
	return;	
}

/*****************************************************************************
 * FUNCTION
 *  bt_srv_app_event_notify
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void pxp_srv_app_event_notify(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_PXPAPP_SWITCH_PROC, event, 0);
    switch (event)
    {
        case SRV_BT_CM_EVENT_ACTIVATE:
            pxp_srv_app_power_on_to_init();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            pxp_srv_power_on_to_deinit();
            break;

		default :
			break;
	}

}

#endif
