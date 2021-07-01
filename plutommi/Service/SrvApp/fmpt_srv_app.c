#include "MMI_features.h"
#include "MMIDataType.h"
#include "MMITimer.h"
#include "FmptSrv.h"
#include "BtcmSrvGprot.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "GlobalResDef.h"
#include "GpioSrvGprot.h"
#include "ProfilesSrvGprot.h"
#include "mmi_rp_srv_prof_def.h"
#include "mmi_rp_srv_gatt_app_def.h"
#include "Fmpt_def.h"

#define FMP_SRV_APP_TARGET_ALERT_TIME        (1000 * 60)


static fmpt_callback_t fmpt_cb_cntx;
static MMI_BOOL is_alerting = MMI_FALSE;

static void fmpt_srv_app_target_alert_disable(void);
static void fmpt_srv_app_event_notify(U32 event, void* para);


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
void fmpt_srv_app_target_alert_enable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "fmpt_srv_app_target_alert_enable");
    if (is_alerting == MMI_TRUE)
    {
        return;
    }
	StartTimer(FMP_SRV_APP_ALERT_TIMER, FMP_SRV_APP_TARGET_ALERT_TIME, fmpt_srv_app_target_alert_disable);
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
void fmpt_srv_app_target_alert_disable(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_prompt_trace(MOD_MMI_CONN_APP, "fmpt_srv_app_target_alert_disable");
    if (is_alerting == MMI_FALSE)
    {
        return;
    }
	StopTimer(FMP_SRV_APP_TARGET_ALERT_TIME);
	/*beep and vibration*/
	srv_prof_stop_tone(SRV_PROF_TONE_ALARM);
	srv_vibrator_off();
	is_alerting = MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  fmpt_srv_app_connection_state_cb
 * DESCRIPTION
 *  to notify reporter current connection state
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [state] Profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
void fmpt_srv_app_connection_state_cb(char* bdaddr, int connect_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_REMOTER_CNNC,bdaddr,connect_state);
    switch(connect_state)
    {
        case FMP_STATUS_DISCONNECTED:
            break;
        case FMP_STATUS_CONNECTED:
            //do nothing
            break;
        case FMP_STATUS_DISCONNECTING:
            break;
        case FMP_STATUS_CONNECTING:
            break;
        default:
            break;
    }
}


/*****************************************************************************
 * FUNCTION
 *  fmpt_srv_app_alert_notify_cb
 * DESCRIPTION
 *  to notify reporter mmi task start/stop path loss alert(IAS)
 * PARAMETERS
 *  [bdaddr] Return remote bluetooth device addr
 *  [level] alert level of IAS
 * RETURNS
 *  void
 *****************************************************************************/
void fmpt_srv_app_alert_notify_cb(char* bdaddr, U8 alert_level)
    {
        /*----------------------------------------------------------------*/
        /* Local Variables                                                */
        /*----------------------------------------------------------------*/
    
        /*----------------------------------------------------------------*/
        /* Code Body                                                      */
        /*----------------------------------------------------------------*/
        MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_REMOTER_ALERT,bdaddr,alert_level);
        switch(alert_level)
        {
            case FMP_ALERT_LEVEL_NO:
            {
                fmpt_srv_app_target_alert_disable();
            }
                break;
            case FMP_ALERT_LEVEL_MILD:
            {
                fmpt_srv_app_target_alert_enable();
            }
                break;
            case FMP_ALERT_LEVEL_HIGH:
            {
                fmpt_srv_app_target_alert_enable();
            }
                break;
                
            default:
                break;
        }
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
void fmpt_srv_app_power_on_to_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_BTS_SWITCH_ON);
    /*rigister callback to enable target role*/
    fmpt_cb_cntx.connection_state_cb = fmpt_srv_app_connection_state_cb;
    fmpt_cb_cntx.alert_notify_cb = fmpt_srv_app_alert_notify_cb;
    fmpt_init(&fmpt_cb_cntx);
    return;
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
void fmpt_srv_power_on_to_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_BTS_SWITCH_OFF);
    /*to disable target role*/
    fmpt_deinit(&fmpt_cb_cntx);
    fmpt_cb_cntx.connection_state_cb = NULL;
    fmpt_cb_cntx.alert_notify_cb = NULL;
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
void fmpt_srv_app_init(void)
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
	srv_bt_cm_set_notify((srv_bt_cm_notifier)fmpt_srv_app_event_notify, event_mask, NULL);
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
void fmpt_srv_app_event_notify(U32 event, void* para)
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
            fmpt_srv_app_power_on_to_init();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            fmpt_srv_power_on_to_deinit();
            break;

		default :
			break;
	}

}


