#ifndef __ANP_CLIENT_SRV_H__
#define __ANP_CLIENT_SRV_H__

#include "kal_trace.h"

#include "bt_mmi.h"
#include "btostypes.h"

#define ANP_MAX_INFO_LENGTH     (36)

#define ALERT_NOTIFICATION_U16          0x1811
#define NEW_ALERT_CATEGORY_U16          0x2a47
#define UNREAD_ALERT_CATEGORY_U16       0x2a48
#define NEW_ALERT_U16                   0x2a46
#define UNREAD_ALERT_U16                0x2a45
#define ALERT_CONTROL_POINT_U16         0x2a44
#define ANP_CHAR_CONFIGURATION_U16      0x2902


#define CMD_ENABLE_NEW_ALERT            0x00
#define CMD_ENABLE_UNREAD_ALERT         0x01
#define CMD_DISABLE_NEW_ALERT           0x02
#define CMD_DISABLE_UNREAD_ALERT        0x03
#define CMD_NOTIFY_NEW_ALERT_IMM        0x04
#define CMD_NOTIFY_UNREAD_ALERT_IMM     0x05

#define ANPC_OPER_IDLE                          0x0000
#define ANPC_OPER_READ_NEW_ALERT                0x0001
#define ANPC_OPER_READ_UNREAD_ALERT             0x0002
#define ANPC_OPER_WRITE_CONTROL_POINT_REQ       0x0004
#define ANPC_OPER_CONIFG_NEW_ALERT              0x0008
#define ANPC_OPER_CONFIG_UNREAD_ALERT           0x0010

#define ANPC_CONFIG_ALERT_ON    0x01
#define ANPC_CONFIG_ALERT_OFF   0x00

typedef enum
{
    OS_ANPC_STATUS_SUCCESS	= 0,
    OS_ANPC_STATUS_FAILED	= 1,
    OS_ANPC_STATUS_PENDING  = 2,
    OS_ANPC_STATUS_BUSY     = 3,
} OS_ANPC_STATUS;

typedef enum
{
    ANPC_MMI_EVT_UNKNOW = (0),
    ANPC_MMI_EVT_ENABLE_CNF,
    ANPC_MMI_EVT_CONNEC_IND,
    ANPC_MMI_EVT_DISCONNECT_IND,
    ANPC_MMI_EVT_LISTEN_RESULT,
    ANPC_MMI_EVT_READ_SUPPORTED_NEW_ALERT_CNF,
    ANPC_MMI_EVT_READ_SUPPORTED_UNREAD_ALERT_CNF,
    ANPC_MMI_EVT_NEW_ALERT_NOTIFY_IND,
    ANPC_MMI_EVT_UNREAD_ALERT_NOTIFY_IND,
    ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF,
    ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF,
    ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF,
} anpc_mmi_evt_enum;

typedef struct
{
    anpc_mmi_evt_enum       evtid;
    BD_ADDR                 bdaddr;
    OS_ANPC_STATUS          result;
    kal_uint16              category_bit;
    kal_uint16              cmd;
    kal_uint8               on_off;
    kal_uint8               category_id;
    kal_uint8               alert_num;
    kal_uint8               alert_info[ANP_MAX_INFO_LENGTH];
	MMI_BOOL				is_trucated;
} anp_client_app_cb_param;

typedef void (*anp_client_app_callback)(anp_client_app_cb_param* param);


// Anp profile init function. Init anp client and register MMI callback function to profile layer.
OS_ANPC_STATUS srv_anp_client_enable(anp_client_app_callback callback);

// Anp profile deinit function.
void srv_anp_client_disable();

OS_ANPC_STATUS srv_anp_client_listen(BOOL start);

// Connect to ANP server using specified BT address.
OS_ANPC_STATUS srv_anp_client_connect_req(BD_ADDR* btaddr, BOOL direct);

// Disconnect the connection with specified ANP server.
OS_ANPC_STATUS srv_anp_client_disconnect_req(BD_ADDR* btaddr);

//OS_ANPC_STATUS srv_anp_client_search_server_srv(BD_ADDR* btaddr);


// Read the supported new alert category from server.
OS_ANPC_STATUS srv_anp_client_read_supported_new_alert_category_req(BD_ADDR* btaddr);

// Read the supported unread alert category from server.
OS_ANPC_STATUS srv_anp_client_read_supported_unread_alert_category_req(BD_ADDR* btaddr);


OS_ANPC_STATUS srv_anp_client_configure_alert(BD_ADDR* btaddr, U16 oper, U8 on_off);

OS_ANPC_STATUS srv_anp_client_wirte_control_point(BD_ADDR* btaddr, U16 cmd, kal_uint8 category_id);


/*
// Request to notify when new alert count changes.
OS_ANPC_STATUS srv_anp_client_active_new_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id);

// Request to notify when unread alert status changes.
OS_ANPC_STATUS srv_anp_client_active_unread_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id);

// Request to disable specific new alert count changes notify.
OS_ANPC_STATUS anp_client_disable_new_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id);

// Request to disable specific new alert count changes notify.
OS_ANPC_STATUS anp_client_disable_unread_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id);

// Request the server to notify specific new alert immediately.
OS_ANPC_STATUS anp_client_notify_new_alert_immediately_req(BD_ADDR* btaddr, kal_uint8 category_id);

// Request the server to notify specific unread alert status immediately.
OS_ANPC_STATUS anp_client_notify_unread_alert_immediately_req(BD_ADDR* btaddr, kal_uint8 category_id);
*/

#endif // __ANP_CLIENT_SRV_H__
