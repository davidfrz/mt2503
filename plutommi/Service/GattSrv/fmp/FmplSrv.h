#ifndef __FMPL_SRV_H__
#define __FMPL_SRV_H__

//#ifdef MMI_SRV_BT_FMPL_PROFILE 

#include "bt_mmi.h"

#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif


/** BT-Find Me callback defination. */

/** Callback invoked in response to connect/disconnect for Locator/Target*/
typedef void (*fmpl_connection_state_callback)(char *bdaddr, int state);

/** Callback for start/stop alert level */
typedef void (*fmpl_alert_notify_callback)(char *bd_addr, int result);


/* define proximity monitor role callback funtion*/
typedef struct
{
    fmpl_connection_state_callback           connection_state_cb;
	fmpl_alert_notify_callback               alert_notify_cb;
}fmpl_callback_t;

BtStatus fmpl_init(fmpl_callback_t *cb);

BtStatus fmpl_deinit();

BtStatus fmpl_connect(char *bdaddr);

BtStatus fmpl_disconnect(char *bdaddr);

BtStatus fmpl_configAlertLevel(char *bdaddr, U8 level);

BtStatus fmpl_alert(char *bdaddr, BOOL start);

//#endif

#endif
