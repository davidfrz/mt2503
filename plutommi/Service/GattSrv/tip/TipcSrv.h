#ifndef __TIME_CLIENT_SRV_H__
#define __TIME_CLIENT_SRV_H__

#include "kal_trace.h"

#include "bt_mmi.h"
#include "btostypes.h"
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"
#include "TimeSrvGprot.h"
#include "PhbSrvGprot.h"
#include "mmi_frm_events_gprot.h"

// Service flags
#ifndef TIP_SRV_FLAG_CTS
#define TIP_SRV_FLAG_CTS     0x01
#endif
#ifndef TIP_SRV_FLAG_NDCS
#define TIP_SRV_FLAG_NDCS    0x02
#endif
#ifndef TIP_SRV_FLAG_RTUS
#define TIP_SRV_FLAG_RTUS    0x04
#endif

#define SRV_TIP_MAX_LINK_NUM                   (4)
#define SRV_TIP_FLAG_USED                      (0x0001)
#define TIP_SERVICE_UUID                       (0x1805)
#define TIP_LTI_CHAR_UUID                      (0x2A0F)
#define TIP_CT_CHAR_UUID                       (0x2A2B)


typedef enum
{
    TIPC_EVENT_REGISTER_CNF = 1,
    TIPC_EVENT_DEREGISTER_CNF,
    TIPC_EVENT_TIME_INFO_RESULT,
    TIPC_EVENT_CONNECT_RESULT,
    TIPC_EVENT_TIME_TF,
} tipc_event_type;

typedef void (*tipc_app_callback)(void *app_cntx, tipc_event_type event, OS_STATUS status, void *data);

typedef struct
{
    // Exact Time 256
    U16 year;
    U8 month;
    U8 day;
    U8 hours;
    U8 minutes;
    U8 seconds;
    U8 day_of_week;
    U8 frac_256;

    // Adjust Reason
    U8 adj_reason;

    // Reserved bytes
    U8 rsv01;
    U8 rsv02;
} tipc_date_time_struct;

typedef struct
{
    U8 flag;                  /*0x01: used*/
    U8 state;
    U8 index;
    U8 srv_flags;
    BD_ADDR bd_addr;
    void *conn_ctx;
    GATT_SVC_UUID srv_uuid;
} srv_tipc_dev_info_struct;

typedef enum
{
    SRV_TIP_QUERY_BY_NULL          = 0,
    SRV_TIP_QUERY_BY_CONN,
    SRV_TIP_QUERY_BY_ADDR,
    SRV_TIP_QUERY_BY_CHAR_UUID,
    SRV_TIP_QUERY_BY_INDEX,

    SRV_TIP_QUERY_TYPE_TOTAL
} srv_tip_query_type_enum;

void srv_tipc_register(tipc_app_callback callback);

void srv_tipc_deregister(void *tipc_cntx);

void srv_tipc_get_time(void *tipc_cntx);

static mmi_ret srv_tipc_evt_handle(mmi_event_struct *evt);

static void srv_util_convert_addr(srv_bt_cm_bt_addr *src, BD_ADDR *dst);

static srv_tipc_dev_info_struct *srv_tipc_get_dev(U8 type, void *para);

static srv_tipc_dev_info_struct *srv_tipc_alloc_dev();

static void srv_tipc_free_dev(srv_tipc_dev_info_struct *dev);

#ifdef __TIME_SYNC_EXT__
static void srv_time_tf_cb(srv_time_evt_struct *evt);
#endif

#endif /* __TIME_CLIENT_SRV_H__ */
