#ifndef __SOGPS_SRV_H__
#define __SOGPS_SRV_H__

//#ifdef MMI_SRV_BT_SOGPS_PROFILE 

#include "bt_mmi.h"

#ifndef BtStatus

typedef int BtStatus;
#define BT_STATUS_SUCCESS  0
#define BT_STATUS_FAILED   1
#define BT_STATUS_PENDING  2

#endif
//#define SRV_SOGPS_MAX_DEV         BT_MAX_LE_LINK_NUM
#define SRV_SOGPS_MAX_DEV         __BT_MAX_LE_LINK_NUM__

/** BT-Findme callback defination. */

/** Callback invoked in response to connect/disconnect for Monitor/Reporter*/
typedef void (*sogps_connection_state_callback)(char *bdaddr, int state);

/** Callback for start/stop alert level */
typedef S32 (*sogps_data_to_read_callback)(char *bd_addr, U8* buf, U32 len);

/** Callback for remote side send read request */
typedef S32 (*sogps_read_data_request_callback)(U32 conn_id, char* bdaddr, void* buf, U32 len);


/* define proximity monitor role callback funtion*/
typedef struct
{
    sogps_connection_state_callback           connection_state_cb;
    sogps_data_to_read_callback                data_to_read_notify_cb;
    sogps_read_data_request_callback         read_data_request_cb;
}sogps_callback_t;

BtStatus sogps_init(sogps_callback_t *cb);

BtStatus sogps_deinit();

//S32 sogps_send_data(void* buf, U32 len, S32 *err_code);
S32 sogps_send_data(void* buf, char *bdaddr, U32 len, S32 *err_code);
void sogps_conn_param_interval_set_high_level(U8 dev_type);


//#endif

#endif
