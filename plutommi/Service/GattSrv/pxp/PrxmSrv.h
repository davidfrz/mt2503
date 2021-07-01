#ifndef __PRXM_SRV_H__
#define __PRXM_SRV_H__

//#ifdef MMI_SRV_BT_PRXM_PROFILE 

#include "bt_mmi.h"

#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif

/** BT-Proximity callback defination. */

/** Callback invoked in response to connect/disconnect for Monitor/Reporter*/
typedef void (*prxm_connection_state_callback)(char *bdaddr, int state);

/** Callback for config alert level */
typedef void (*prxm_config_level_callback)(char *bd_addr, int result);

/** Callback for start/stop alert level */
typedef void (*prxm_alert_notify_callback)(char *bd_addr, int result);

/** Callback read txpower value result*/
typedef void (*prxm_read_txpower_callback)(char *bd_addr, U8 value, int result);

/** Callback read txpower value result*/
typedef void (*prxm_read_rssi_callback)(char *bd_addr, S32 value, int result);


/* define proximity monitor role callback funtion*/
typedef struct
{
    prxm_connection_state_callback           connection_state_cb;
    prxm_config_level_callback               config_level_cb;
	prxm_alert_notify_callback               alert_notify_cb;
    prxm_read_txpower_callback               read_txpower_cb;
    prxm_read_rssi_callback                  read_rssi_cb;
}prxm_callback_t;

BtStatus prxm_init(prxm_callback_t *cb);

BtStatus prxm_deinit();

BtStatus prxm_connect(char *bdaddr);

BtStatus prxm_disconnect(char *bdaddr);

BtStatus prxm_configAlertLevel(char *bdaddr, int type, U8 level);

BtStatus prxm_alert(char *bdaddr, BOOL start);

BtStatus prxm_readTxPower(char *bdaddr);

BtStatus prxm_readRssi(char *bdaddr);

//#endif

#endif
