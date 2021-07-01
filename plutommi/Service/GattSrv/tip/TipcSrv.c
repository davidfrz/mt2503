
// For development
//#define __MMI_TIME_CLIENT_SUPPORT__

//#ifdef __MMI_TIME_CLIENT_SUPPORT__
#ifdef __BT_GATTC_PROFILE__ 

#include "GattcSrv.h"
#include "TipcSrv.h"
#include "MMI_conn_app_trc.h"

#define TIPC_STATE_IDLE             0
#define TIPC_STATE_REGISTERING      1
#define TIPC_STATE_DEREGISTERING    2
#define TIPC_STATE_STARTING_LISTEN  3
#define TIPC_STATE_STOPPING_LISTEN  4     
#define TIPC_STATE_READY            5
#define TIPC_STATE_CONNECTING       6
#define TIPC_STATE_DISCONNECTING    7
#define TIPC_STATE_CONNECTED        8
#define TIPC_STATE_SYNCING          9
#define TIPC_STATE_REG_NOTI         (10)
#define TIPC_STATE_GET_DESCR        (11)
#define TIPC_STATE_READ_DESCR       (12)
#define TIPC_STATE_WRITE_DESCR      (13)
#define TIPC_STATE_DONE             (14)
#define TIPC_STATE_GET_CHAR         (15)
#define TIPC_STATE_READ_LTI         (16)



typedef struct _tipc_app_cntx_t
{
    U8 in_use;
    U8 state;
    U8 srv_flags;
    U8 reserved;

    tipc_app_callback app_cb;
    void *gattc_reg_cntx;
    void *gattc_conn_cntx;
    //gatt_conn_struct *gattc_conn;
    BD_ADDR bd_addr;
    GATT_SVC_UUID srv_uuid;
    ATT_UUID char_uuid;
    ATT_UUID descr_uuid;
    ATT_UUID lti_uuid;

    U32 flag;                   /* 0x01: lock done */
    srv_tipc_dev_info_struct *dev_info;
    SRV_TIME_HANDLE hd;
    U32 tf_lock;
} tipc_app_cntx;

/*****************************************************************
 * Current Time Service (CTS)
 *****************************************************************/
// UUID of Current Time Service: 0x1805
static U8 SRV_CTS_UUID_16[] = {
    0x05, 0x18,
};
static U8 SRV_CTS_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x05, 0x18, 0x00, 0x00,
};

// UUID of Current Time Characteristic: 0x2A2B
static U8 CHR_CT_UUID_16[] = {
    0x2B, 0x2A,
};
static U8 CHR_CT_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x2B, 0x2A, 0x00, 0x00,
};

#if 0 /* For further extension */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* For further extension */

static srv_tipc_dev_info_struct dev_info[SRV_TIP_MAX_LINK_NUM];

// The context of TIP client.
static tipc_app_cntx g_tipc_cntx = {0};

// The callback function struct for GATT
static gattc_callback_struct g_tipc_gattc_callback;

static  bt_uuid_struct tipc_uuid;

static void tipc_gattc_register_callback(
    void *reg_ctx,
    OS_STATUS status,
    bt_uuid_struct *app_uuid);

static void tipc_gattc_listen_callback(
    void *reg_ctx,
    OS_STATUS status);

static void tipc_gattc_connect_callback(
    gatt_conn_struct *conn,
    BOOL connected,
    BD_ADDR *bd_addr);

static void tipc_gattc_search_service_result_callback(
    gatt_conn_struct *conn,
    GATT_SVC_UUID *uuid);

static void tipc_gattc_search_service_complete_callback(
    gatt_conn_struct *conn,
    OS_STATUS status);

static void tipc_gattc_get_char_callback(
    gatt_conn_struct *conn,
    OS_STATUS status,
    gattc_char_struct *chr,
    GATT_CHAR_PROPERTIES properties);

static void tipc_gattc_read_char_callback(
    gatt_conn_struct *conn,
    OS_STATUS status,
    gattc_char_struct *chr,
    ATT_VALUE *value);

#if 0 /* For further extension */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* For further extension */ 


static void tipc_register_for_notification_cb(
    void *reg_ctx,
    OS_STATUS status,
    BD_ADDR *bd_addr,
    gattc_char_struct *char_info);


static void tipc_get_descriptor_cb(
    gatt_conn_struct *conn,
    OS_STATUS status,
    gattc_descr_struct 
    *descr_info);


static void tipc_read_descriptor_cb(
    gatt_conn_struct *conn,
    OS_STATUS status,
    gattc_descr_struct *descr_info, ATT_VALUE 
    *value);


static void tipc_write_descriptor_cb(
    gatt_conn_struct *conn,
    OS_STATUS status,
    gattc_descr_struct *descr_info);


static void tipc_notify_cb(
    gatt_conn_struct *conn,
    BD_ADDR *bd_addr,
    gattc_char_struct *char_info,
    ATT_VALUE *value,
    BOOL is_notify);


static void _tipc_get_time_info();

static void _tipc_dump_uuid(BT_UUID *bt_uuid);

void srv_tipc_register(tipc_app_callback app_cb)
{
    kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_REGISTER);

    if (app_cb == NULL)
    {
        kal_trace(TRACE_GROUP_4, TIPC_SRV_ERR_REGISTER_NULL_APP_CB);
        return;
    }

    if (g_tipc_cntx.in_use == 0 && g_tipc_cntx.state == TIPC_STATE_IDLE)
    {
        memset(&g_tipc_cntx, 0x00, sizeof(tipc_app_cntx));
        memset(&g_tipc_gattc_callback, 0x00, sizeof(gattc_callback_struct));
        memset(dev_info, 0x00, sizeof(dev_info));

        g_tipc_cntx.dev_info = dev_info;
        g_tipc_cntx.in_use = 1;
        g_tipc_cntx.state = TIPC_STATE_REGISTERING;
        g_tipc_cntx.app_cb = app_cb;

        g_tipc_gattc_callback.register_client_cb = tipc_gattc_register_callback;
        g_tipc_gattc_callback.connection_cb = tipc_gattc_connect_callback;
        g_tipc_gattc_callback.listen_cb = tipc_gattc_listen_callback;
        g_tipc_gattc_callback.search_result_cb = tipc_gattc_search_service_result_callback;
        g_tipc_gattc_callback.search_complete_cb = tipc_gattc_search_service_complete_callback;
        g_tipc_gattc_callback.get_characteristic_cb = tipc_gattc_get_char_callback;
        g_tipc_gattc_callback.read_characteristic_cb = tipc_gattc_read_char_callback;
        g_tipc_gattc_callback.deregister_client_cb = NULL;

        // myler
        g_tipc_gattc_callback.register_for_notification_cb = tipc_register_for_notification_cb;
        g_tipc_gattc_callback.get_descriptor_cb = tipc_get_descriptor_cb;
        g_tipc_gattc_callback.read_descriptor_cb = tipc_read_descriptor_cb;
        g_tipc_gattc_callback.write_descriptor_cb = tipc_write_descriptor_cb;
        g_tipc_gattc_callback.notify_cb = tipc_notify_cb;

        // Register for GATT client.
        memcpy(tipc_uuid.uu, SRV_CTS_UUID_128, 16);
        srv_gattc_register(&tipc_uuid, &g_tipc_gattc_callback);
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, srv_tipc_evt_handle, NULL);
    }
    else
    {
        kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_REGISTER_IN_USE, g_tipc_cntx.in_use, g_tipc_cntx.state);
        app_cb(NULL, TIPC_EVENT_REGISTER_CNF, OS_STATUS_FAILED, NULL);
    }   
}

void srv_tipc_deregister(void *tipc_cntx)
{
    gatt_conn_struct gattc_conn;

    kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_DEREGISTER);
    if (tipc_cntx != NULL && tipc_cntx == &g_tipc_cntx)
    {
        switch (g_tipc_cntx.state)
        {
            case TIPC_STATE_READY:
                g_tipc_cntx.state = TIPC_STATE_STOPPING_LISTEN;
                // add for multi link
                if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                srv_gattc_listen(g_tipc_cntx.gattc_reg_cntx, FALSE);
                break;

            case TIPC_STATE_CONNECTED:
                g_tipc_cntx.state = TIPC_STATE_DISCONNECTING;
                gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
                gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;
                srv_gattc_disconnect(&gattc_conn, &g_tipc_cntx.bd_addr);
                break;

            default:
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_DEREGISTER_STATE, g_tipc_cntx.state);
                break;
        }
        #ifdef __TIME_SYNC_EXT__
        if (g_tipc_cntx.hd)
        {
            srv_time_deregister(g_tipc_cntx.hd);
            g_tipc_cntx.hd = NULL;
            g_tipc_cntx.tf_lock &= (~0x04);
        }
        #endif
        srv_gattc_deregister(g_tipc_cntx.gattc_reg_cntx);
        // Clear the callback immediately.
        g_tipc_cntx.app_cb(NULL, TIPC_EVENT_DEREGISTER_CNF, OS_STATUS_SUCCESS, NULL);
        memset(&g_tipc_cntx, 0x00, sizeof(tipc_app_cntx));
        memset(&g_tipc_gattc_callback, 0x00, sizeof(gattc_callback_struct));
        g_tipc_cntx.app_cb = NULL;
        g_tipc_cntx.state = TIPC_STATE_IDLE;
        g_tipc_cntx.in_use = 0;
    }
    else
    {
        kal_trace(TRACE_GROUP_4, TIPC_SRV_ERR_DEREGISTER_INVALID_CNTX, tipc_cntx, &g_tipc_cntx);
    }
}

static void tipc_gattc_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    switch (g_tipc_cntx.state)
    {
        case TIPC_STATE_REGISTERING:
            if (status == OS_STATUS_SUCCESS)
            {
                if (g_tipc_cntx.app_cb != NULL)
                {
                    g_tipc_cntx.state = TIPC_STATE_STARTING_LISTEN;
                    g_tipc_cntx.gattc_reg_cntx = reg_ctx;
                    srv_gattc_listen(reg_ctx, TRUE);
                }
                else
                {
                    g_tipc_cntx.state = TIPC_STATE_IDLE;
                    g_tipc_cntx.in_use = 0;
                    // Deregister GATT client context. No confirm will come back.
                    srv_gattc_deregister(reg_ctx);
                }
            }
            else
            {
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_REG_CB_FAILED, status);

                g_tipc_cntx.state = TIPC_STATE_IDLE;
                g_tipc_cntx.in_use = 0;

                if (g_tipc_cntx.app_cb != NULL)
                {
                    g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_REGISTER_CNF, status, NULL);
                    g_tipc_cntx.app_cb = NULL;
                }
            }
            break;

        default:
            kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_REG_CB_STATE, g_tipc_cntx.state);
            break;
    }

}

static void tipc_gattc_listen_callback(void *reg_ctx, OS_STATUS status)
{
    switch (g_tipc_cntx.state)
    {
        case TIPC_STATE_STARTING_LISTEN:
            if (status == OS_STATUS_SUCCESS)
            {
                if (g_tipc_cntx.app_cb != NULL)
                {
                    kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GATTC_LTN_CB_READY);
                    g_tipc_cntx.state = TIPC_STATE_READY;
                    g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_REGISTER_CNF, status, NULL);
                }
                else
                {
                    g_tipc_cntx.state = TIPC_STATE_STOPPING_LISTEN;
                    // add for multi link
                    if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                    srv_gattc_listen(g_tipc_cntx.gattc_reg_cntx, FALSE);
                }
            }
            else
            {
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_LTN_CB_START_FAILED, status);
                    
                g_tipc_cntx.state = TIPC_STATE_IDLE;
                g_tipc_cntx.in_use = 0;

                // Deregister GATT client context. No confirm will come back.
                srv_gattc_deregister(g_tipc_cntx.gattc_reg_cntx);
                g_tipc_cntx.gattc_reg_cntx = NULL;

                if (g_tipc_cntx.app_cb != NULL)
                {
                    g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_REGISTER_CNF, status, NULL);
                    g_tipc_cntx.app_cb = NULL;
                }
            }
            break;

        case TIPC_STATE_STOPPING_LISTEN:
            if (status != OS_STATUS_SUCCESS)
            {
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_LTN_CB_STOP_FAILED, status);
            }
            g_tipc_cntx.state = TIPC_STATE_IDLE;
            g_tipc_cntx.in_use = 0;

            // Deregister GATT client context. No confirm will come back.
            srv_gattc_deregister(g_tipc_cntx.gattc_reg_cntx);
            g_tipc_cntx.gattc_reg_cntx = NULL;
            break;

        default:
            kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_LTN_CB_STATE, g_tipc_cntx.state);
            break;
    }
}

static void tipc_gattc_connect_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    bt_uuid_struct att_uuid = {0};
    gattc_char_struct chr;
    srv_tipc_dev_info_struct *tipc_dev = NULL;
    srv_tip_connect_struct evt;

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_gattc_connect_callback--state: %d, connect: %d\n",
                    g_tipc_cntx.state, connected);

    if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
    {
        switch (g_tipc_cntx.state)
        {
            case TIPC_STATE_READY:
                if (connected)
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
                    #endif
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_ADDR, bd_addr);
                    if (tipc_dev)
                    {
                        if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                        srv_gattc_listen(conn->reg_ctx, FALSE);
                    }
                    else
                    {
                        tipc_dev = srv_tipc_alloc_dev();
                        if (tipc_dev)
                        {
                            memcpy(tipc_dev->bd_addr.addr, bd_addr->addr, BD_ADDR_SIZE);
                            tipc_dev->conn_ctx = conn->conn_ctx;
                            if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                            srv_gattc_listen(conn->reg_ctx, FALSE);

                            tipc_dev->srv_flags = 0x00;
                            memcpy(att_uuid.uu, SRV_CTS_UUID_128, 16);
                            srv_gattc_search_service(conn, &att_uuid);
                        }
                        else
                        {
                            srv_gattc_disconnect(conn, bd_addr);
                        }
                    }
                }
                else
                {
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_ADDR, bd_addr);
                    if (tipc_dev)
                    {
                        srv_tipc_free_dev(tipc_dev);
                    }
                    // Just ignore.
                }
                break;

            case TIPC_STATE_CONNECTING:
                if (memcmp(g_tipc_cntx.bd_addr.addr, bd_addr->addr, BD_ADDR_SIZE) == 0)
                {
                    if (connected)
                    {
                        if (g_tipc_cntx.app_cb != NULL)
                        {
                            kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GATTC_CNN_CB_CONNECTED);
                        
                            g_tipc_cntx.state = TIPC_STATE_SYNCING;
                            g_tipc_cntx.srv_flags = 0x00;

                            memcpy(att_uuid.uu, SRV_CTS_UUID_128, 16);
                            // notify app connected
                            g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_CONNECT_RESULT, OS_STATUS_SUCCESS, NULL);

                            srv_gattc_search_service(conn, &att_uuid);
                        }
                        else
                        {
                            g_tipc_cntx.state = TIPC_STATE_DISCONNECTING;
                            srv_gattc_disconnect(conn, bd_addr);
                        }
                    }
                    else
                    {
                        kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_CNN_CB_CONNECT_FAILED_BD_ADDR,
                            bd_addr->addr[0], bd_addr->addr[1], bd_addr->addr[2],
                            bd_addr->addr[3], bd_addr->addr[4], bd_addr->addr[5]);

                        g_tipc_cntx.state = TIPC_STATE_READY;
                        //g_tipc_cntx.gattc_conn = NULL;
                        memset(&g_tipc_cntx.bd_addr, 0, sizeof(BD_ADDR));
                    }
                }
                break;

            case TIPC_STATE_DISCONNECTING:
            case TIPC_STATE_CONNECTED:
            case TIPC_STATE_SYNCING:
            case TIPC_STATE_DONE:
                if (memcmp(g_tipc_cntx.bd_addr.addr, bd_addr->addr, BD_ADDR_SIZE) == 0)
                {
                    if (connected == FALSE)
                    {
                        if (g_tipc_cntx.app_cb != NULL)
                        {
                            // Waiting for the next incoming connection.
                            kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GATTC_CNN_CB_DISCONNECTED);
                            g_tipc_cntx.state = TIPC_STATE_READY;
                            g_tipc_cntx.flag &= (~0x01); /* unlock */
                            g_tipc_cntx.flag &= (~0x02);
                            srv_gattc_listen(g_tipc_cntx.gattc_reg_cntx, TRUE);

                            chr.svc_uuid = &g_tipc_cntx.srv_uuid;
                            chr.char_uuid = &g_tipc_cntx.char_uuid;
                            srv_gattc_deregister_for_notification(g_tipc_cntx.gattc_reg_cntx,
                                &g_tipc_cntx.bd_addr, &chr);
                            // notify app connected
                            g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_CONNECT_RESULT, OS_STATUS_FAILED, NULL);
                        #ifdef __TIME_SYNC_EXT__
                            if (g_tipc_cntx.hd)
                            {
                                srv_time_deregister(g_tipc_cntx.hd);
                                g_tipc_cntx.hd = NULL;
                                g_tipc_cntx.tf_lock &= (~0x04);
                            }
                        #endif
                            memset(g_tipc_cntx.bd_addr.addr, 0x00, BD_ADDR_SIZE);
                            MMI_FRM_INIT_EVENT(&evt, EVT_ID_TIP_DISCONNECT);
                            MMI_FRM_CB_EMIT_EVENT(&evt);
                        }
                        else
                        {
                            g_tipc_cntx.state = TIPC_STATE_STOPPING_LISTEN;
                            // add for multi link
                            if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
                            srv_gattc_listen(g_tipc_cntx.gattc_reg_cntx, FALSE);
                        }
                    }
                    else
                    {
                        // Invalide case.
                        kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_CNN_CB_INVALID_ARGS,
                            bd_addr->addr[0], bd_addr->addr[1], bd_addr->addr[2],
                            bd_addr->addr[3], bd_addr->addr[4], bd_addr->addr[5],
                            g_tipc_cntx.state, connected);
                    }
                }
                else
                {
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_ADDR, bd_addr);
                    if (tipc_dev)
                    {
                        srv_tipc_free_dev(tipc_dev);
                    }
                    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_gattc_connect_callback(disconnect)--\n");
                    /* disconnect 2nd device */
                    if (connected)
                    {
                        srv_gattc_disconnect(conn, bd_addr);
                    }
                }
                break;

            default:
                tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_ADDR, bd_addr);
                if (tipc_dev)
                {
                    srv_tipc_free_dev(tipc_dev);
                }
                if (connected)
                {
                    srv_gattc_disconnect(conn, bd_addr);
                }
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_CNN_CB_STATE, g_tipc_cntx.state);
                break;
        }
    }
    else
    {
        kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_gattc_connect_callback(err)--reg: 0x%x, conn->reg: 0x%x\n",
            g_tipc_cntx.gattc_reg_cntx, conn->reg_ctx);
    }
}


static void tipc_gattc_search_service_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid)
{
    U8 tmp_uuid_len = 0;
    U8 tmp_uuid[16] = {0};
    srv_tipc_dev_info_struct *tipc_dev = NULL;
    U16 srv_uuid16 = 0;
    S32 ret = 0;

    if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
    {
        switch (g_tipc_cntx.state)
        {
            case TIPC_STATE_SYNCING:
                if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx && uuid != NULL)
                {
                    tmp_uuid_len = uuid->uuid.uuid.len;
                    memcpy(tmp_uuid, uuid->uuid.uuid.uuid, tmp_uuid_len);

                    // myler
                    memcpy(&g_tipc_cntx.srv_uuid, uuid, sizeof(GATT_SVC_UUID));

                    if (tmp_uuid_len == 2)
                    {
                        if (memcmp(tmp_uuid, SRV_CTS_UUID_16, tmp_uuid_len) == 0)
                        {
                            g_tipc_cntx.srv_flags |= TIP_SRV_FLAG_CTS;
                        }
                    }
                    else if (tmp_uuid_len == 16)
                    {
                        if (memcmp(tmp_uuid, SRV_CTS_UUID_128, tmp_uuid_len) == 0)
                        {
                            g_tipc_cntx.srv_flags |= TIP_SRV_FLAG_CTS;
                        }
                    }
                }
                break;

            case TIPC_STATE_READY:
            {
                tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_CONN, conn->conn_ctx);

                if (tipc_dev)
                {
                    srv_uuid16 = convert_array_to_uuid16(uuid->uuid);

                    if (TIP_SERVICE_UUID == srv_uuid16)
                    {
                        tipc_dev->srv_flags |= TIP_SRV_FLAG_CTS;
                        memcpy(&tipc_dev->srv_uuid, uuid, sizeof(GATT_SVC_UUID));
                        ret = 1;
                    }
                }
                else
                {
                    ret = -2;
                }

                break;
            }

            default:
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_SSR_CB_STATE, g_tipc_cntx.state);
                break;
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]result_callback--ret: %d, state: %d\n",
        ret, g_tipc_cntx.state);
}

static void tipc_gattc_search_service_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    gatt_conn_struct gattc_conn;
    S32 ret = 0;
    srv_tipc_dev_info_struct *tipc_dev = NULL;
#ifdef __TIME_SYNC_EXT__
    srv_time_reg_struct reg = {0};
#endif
    srv_tip_connect_struct evt;

    if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
    {
        switch (g_tipc_cntx.state)
        {
            case TIPC_STATE_SYNCING:
                if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
                {
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_CONN, conn->conn_ctx);
                    if (tipc_dev)
                    {
                        //if (g_tipc_cntx.flag & 0x01)
                        {
                            srv_gattc_disconnect(conn, &tipc_dev->bd_addr);
                            srv_tipc_free_dev(tipc_dev);
                            ret = -10;
                        }
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
                    #endif
                }
                break;

            case TIPC_STATE_READY:
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_CONN, conn->conn_ctx);

                    if (tipc_dev)
                    {
                        if (g_tipc_cntx.flag & 0x01)
                        {
                            srv_gattc_disconnect(conn, &tipc_dev->bd_addr);
                            srv_tipc_free_dev(tipc_dev);
                            ret = -3;
                        }
                        else
                        {
                            if (tipc_dev->srv_flags & TIP_SRV_FLAG_CTS)
                            {
                                g_tipc_cntx.flag |= 0x01;
                                g_tipc_cntx.srv_flags = tipc_dev->srv_flags;
                                g_tipc_cntx.gattc_conn_cntx = tipc_dev->conn_ctx;
                                g_tipc_cntx.state = TIPC_STATE_SYNCING;
                                memcpy(g_tipc_cntx.bd_addr.addr, tipc_dev->bd_addr.addr, BD_ADDR_SIZE);
                                memcpy(&g_tipc_cntx.srv_uuid, &tipc_dev->srv_uuid, sizeof(GATT_SVC_UUID));
                                // notify app connected
                                g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_CONNECT_RESULT, OS_STATUS_SUCCESS, NULL);
                            #ifdef __TIME_SYNC_EXT__
                                if (g_tipc_cntx.hd)
                                {
                                    srv_time_deregister(g_tipc_cntx.hd);
                                    g_tipc_cntx.hd = NULL;
                                    g_tipc_cntx.tf_lock &= (~0x04);
                                }
                                memcpy(reg.bd_addr.addr, g_tipc_cntx.bd_addr.addr, BD_ADDR_SIZE);
                                reg.type = 0;
                                reg.ud = NULL;
                                reg.func_cb = (void *)srv_time_tf_cb;
                                g_tipc_cntx.hd = srv_time_register(&reg);
                            #endif
                                srv_tipc_free_dev(tipc_dev);

                                _tipc_get_time_info();

                                ret = 1;
                                MMI_FRM_INIT_EVENT(&evt, EVT_ID_TIP_CONNECT);
                                MMI_FRM_CB_EMIT_EVENT(&evt);
                            }
                            else
                            {
                                srv_gattc_disconnect(conn, &tipc_dev->bd_addr);
                                srv_tipc_free_dev(tipc_dev);
                                ret = -4;
                            }
                        }
                    }
                    else
                    {
                        ret = -2;
                    }
                }
                else
                {
                    tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_CONN, conn->conn_ctx);
                    ret = -5;

                    if (tipc_dev)
                    {
                        srv_gattc_disconnect(conn, &tipc_dev->bd_addr);
                        srv_tipc_free_dev(tipc_dev);
                        ret = -6;
                    }
                }

                break;
            }

            default:
                tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_CONN, conn->conn_ctx);
                if (tipc_dev)
                {
                    //if (g_tipc_cntx.flag & 0x01)
                    {
                        srv_gattc_disconnect(conn, &tipc_dev->bd_addr);
                        srv_tipc_free_dev(tipc_dev);
                        ret = -11;
                    }
                }
                kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_SSC_CB_STATE, g_tipc_cntx.state);
                break;
        }
    }
    else
    {
        ret = -1;
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]complete_callback--ret: %d, state: %d\n",
        ret, g_tipc_cntx.state);
}


static void tipc_gattc_get_char_callback(gatt_conn_struct *conn, OS_STATUS status,
    gattc_char_struct *chr, GATT_CHAR_PROPERTIES properties)
{
    U8 tmp_uuid_len = 0;
    U8 tmp_uuid[16] = {0};
    gatt_conn_struct gattc_conn;
    U16 char_uuid16 = 0;


    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]get_char_cb--status: %d, state: %d\n",
        status, g_tipc_cntx.state);

    switch (g_tipc_cntx.state)
    {
        case TIPC_STATE_SYNCING:
            if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
            {
                if (status == OS_STATUS_SUCCESS && chr != NULL)
                {
                    if (g_tipc_cntx.app_cb != NULL)
                    {
                        tmp_uuid_len = chr->char_uuid->uuid.len;
                        memcpy(tmp_uuid, chr->char_uuid->uuid.uuid, tmp_uuid_len);

                        _tipc_dump_uuid(&chr->char_uuid->uuid);

                        if ((tmp_uuid_len == 2 && !memcmp(tmp_uuid, CHR_CT_UUID_16, 2)) ||
                            (tmp_uuid_len == 16 && !memcmp(tmp_uuid, CHR_CT_UUID_128, 16)))
                        {
                            //myler
                            memcpy(&g_tipc_cntx.char_uuid, chr->char_uuid, sizeof(ATT_UUID));
                            srv_gattc_read_characteristic(conn, chr, GATTC_AUTH_REQ_NONE);
                        }
                        else
                        {
                            srv_gattc_get_characteristic(conn, chr->svc_uuid, chr->char_uuid);
                        }
                        return;
                    }
                }

                gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
                gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;

                g_tipc_cntx.state = TIPC_STATE_DISCONNECTING;
                srv_gattc_disconnect(&gattc_conn, &g_tipc_cntx.bd_addr);
            }
            break;

            case TIPC_STATE_GET_CHAR:
            {
                if (g_tipc_cntx.gattc_reg_cntx == conn->reg_ctx)
                {
                    if (status == OS_STATUS_SUCCESS)
                    {
                        char_uuid16 = convert_array_to_uuid16(*(chr->char_uuid));

                        if (TIP_LTI_CHAR_UUID == char_uuid16)
                        {
                            memcpy(&g_tipc_cntx.lti_uuid, chr->char_uuid, sizeof(ATT_UUID));
                            g_tipc_cntx.state = TIPC_STATE_READ_LTI;
                            g_tipc_cntx.flag |= 0x02;
                            srv_gattc_read_characteristic(conn, chr, GATTC_AUTH_REQ_NONE);
                        }
                        else
                        {
                            srv_gattc_get_characteristic(conn, chr->svc_uuid, chr->char_uuid);
                        }
                    }
                    else
                    {
                        g_tipc_cntx.state = TIPC_STATE_DONE;
                    }
                }
            }
            break;

        default:
            kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_GCH_CB_STATE, g_tipc_cntx.state);
            break;
    }
}

static void tipc_gattc_read_char_callback(gatt_conn_struct *conn, OS_STATUS status,
    gattc_char_struct *chr, ATT_VALUE *value)
{
    U8 tmp_uuid_len = 0;
    U8 tmp_uuid[16] = {0};
    tipc_date_time_struct date_time = {0};
    gattc_char_struct char_info;


    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]read_char_cb--status: %d, state: %d\n",
        status, g_tipc_cntx.state);

    switch (g_tipc_cntx.state)
    {
        case TIPC_STATE_SYNCING:
        case TIPC_STATE_DONE:
            if (status == OS_STATUS_SUCCESS && chr != NULL)
            {
                if (g_tipc_cntx.app_cb != NULL)
                {
                    tmp_uuid_len = chr->char_uuid->uuid.len;
                    memcpy(tmp_uuid, chr->char_uuid->uuid.uuid, tmp_uuid_len);

                    if ((tmp_uuid_len == 2 && !memcmp(tmp_uuid, CHR_CT_UUID_16, 2)) ||
                        (tmp_uuid_len == 16 && !memcmp(tmp_uuid, CHR_CT_UUID_128, 16)))
                    {
                        if (value != NULL)
                        {
                            kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GATTC_RCH_CB_VALUE_LEN, value->len);

                            date_time.year = (0x00ff & value->value[0]) | (0xff00 & (value->value[1] << 8));
                            date_time.month = value->value[2];
                            date_time.day = value->value[3];
                            date_time.hours = value->value[4];
                            date_time.minutes = value->value[5];
                            date_time.seconds = value->value[6];
                            date_time.day_of_week = value->value[7];
                            date_time.frac_256 = value->value[8];
                            date_time.adj_reason = value->value[9];

                            g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_TIME_INFO_RESULT, status, (void *) &date_time);

                            if (g_tipc_cntx.state == TIPC_STATE_SYNCING)
                            {
                                g_tipc_cntx.state = TIPC_STATE_REG_NOTI;
                                char_info.svc_uuid = &g_tipc_cntx.srv_uuid;
                                char_info.char_uuid = &g_tipc_cntx.char_uuid;
                                srv_gattc_register_for_notification(g_tipc_cntx.gattc_reg_cntx, &g_tipc_cntx.bd_addr, &char_info);
                            }
                        }
                    }
                }
            }
            //g_tipc_cntx.state = TIPC_STATE_DISCONNECTING;
            //srv_gattc_disconnect(g_tipc_cntx.gattc_conn, &g_tipc_cntx.bd_addr);
            break;

            case TIPC_STATE_READ_LTI:
            {
                kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]read_char_cb(LTI)--len: %d, tz: %d, dst: %d\n",
                    value->len, value->value[0], value->value[1]);
                g_tipc_cntx.state = TIPC_STATE_DONE;
            }
            break;

        default:
            kal_trace(TRACE_GROUP_4, TIPC_SRV_WRN_GATTC_RCH_CB_STATE, g_tipc_cntx.state);
            break;
    }
}

#if 0 /* For further extension */
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* For further extension */

static void _tipc_get_time_info()
{
    GATT_SVC_UUID svc_uuid = {0};
    ATT_UUID att_uuid = {0};
    gatt_conn_struct gattc_conn;

    kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GET_TIME_INFO);

    svc_uuid.is_primary = 1;
    svc_uuid.uuid.uuid.len = 16;
    memcpy(svc_uuid.uuid.uuid.uuid, SRV_CTS_UUID_128, 16);
    // att_uuid.uuid.len = 16;
    // memcpy(att_uuid.uuid.uuid, CHR_CT_UUID_128, 16);

    gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
    gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;

    srv_gattc_get_characteristic(&gattc_conn, &svc_uuid, &att_uuid);
}

static void _tipc_dump_uuid(BT_UUID *bt_uuid)
{
    if (bt_uuid != NULL)
    {
        kal_prompt_trace(MOD_BT, "[TIPC] %s(). uuid len: %d\n", __FUNCTION__, bt_uuid->len);
        if (bt_uuid->len == 2)
        {
            kal_prompt_trace(MOD_BT, "[TIPC] %s(). uuid: %02x %02x\n", __FUNCTION__,
                bt_uuid->uuid[0], bt_uuid->uuid[1]);
        }
        else if (bt_uuid->len == 16)
        {
            kal_prompt_trace(MOD_BT, "[TIPC] %s(). uuid: %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x %02x\n",
                __FUNCTION__,
                bt_uuid->uuid[0], bt_uuid->uuid[1], bt_uuid->uuid[2], bt_uuid->uuid[3],
                bt_uuid->uuid[4], bt_uuid->uuid[5], bt_uuid->uuid[6], bt_uuid->uuid[7],
                bt_uuid->uuid[8], bt_uuid->uuid[9], bt_uuid->uuid[10], bt_uuid->uuid[11],
                bt_uuid->uuid[12], bt_uuid->uuid[13], bt_uuid->uuid[14], bt_uuid->uuid[15]
                );
        }   
    }
}


static void tipc_register_for_notification_cb(void *reg_ctx, OS_STATUS status,
    BD_ADDR *bd_addr,
    gattc_char_struct *char_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gatt_conn_struct gattc_conn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_register_for_notification_cb--state: %d, bd_addr %02x:%02x%02x:%02x:%02x:%02x\n",
                    g_tipc_cntx.state, bd_addr->addr[0], bd_addr->addr[1], bd_addr->addr[2],
                    bd_addr->addr[3], bd_addr->addr[4], bd_addr->addr[5]);

    if (reg_ctx == g_tipc_cntx.gattc_reg_cntx &&
        TIPC_STATE_REG_NOTI == g_tipc_cntx.state)
    {
        g_tipc_cntx.state = TIPC_STATE_GET_DESCR;
        gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
        gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;

        srv_gattc_get_descriptor(&gattc_conn, char_info, NULL);
    }
}


static void tipc_get_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status,
    gattc_descr_struct *descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gattc_descr_struct read_req;
    gatt_conn_struct gattc_conn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_get_descriptor_cb--state: %d\n",
                    g_tipc_cntx.state);

    memcpy(&g_tipc_cntx.descr_uuid, descr_info->descr_uuid, sizeof(ATT_UUID));

    g_tipc_cntx.state = TIPC_STATE_READ_DESCR;

    read_req.svc_uuid = &g_tipc_cntx.srv_uuid;
    read_req.char_uuid = &g_tipc_cntx.char_uuid;
    read_req.descr_uuid = &g_tipc_cntx.descr_uuid;
    gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
    gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;

    srv_gattc_read_descriptor(&gattc_conn, &read_req, GATTC_AUTH_REQ_NONE);
}


static void tipc_read_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status,
    gattc_descr_struct *descr_info, ATT_VALUE *value)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gattc_descr_struct write_req;
    ATT_VALUE *w_value;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_read_descriptor_cb--state: %d, len: %d, value: %d\n",
                    g_tipc_cntx.state, value->len, value->value[0]);

    g_tipc_cntx.state = TIPC_STATE_WRITE_DESCR;

    w_value = get_ctrl_buffer(sizeof(ATT_VALUE));
    memset(w_value, 0, sizeof(ATT_VALUE));
    w_value->len = 2;
    w_value->value[0] = 0x01;
    w_value->value[1] = 0;

    write_req.svc_uuid = &g_tipc_cntx.srv_uuid;
    write_req.char_uuid = &g_tipc_cntx.char_uuid;
    write_req.descr_uuid = &g_tipc_cntx.descr_uuid;
    srv_gattc_write_descriptor(conn, &write_req, w_value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
    free_ctrl_buffer(w_value);
}


static void tipc_write_descriptor_cb(gatt_conn_struct *conn, OS_STATUS status,
    gattc_descr_struct *descr_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gatt_conn_struct gattc_conn;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_write_descriptor_cb--state: %d\n",
                    g_tipc_cntx.state);

    g_tipc_cntx.state = TIPC_STATE_DONE;

    gattc_conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
    gattc_conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;

    g_tipc_cntx.state = TIPC_STATE_GET_CHAR;
    srv_gattc_get_characteristic(&gattc_conn, &g_tipc_cntx.srv_uuid, NULL);
}


static void tipc_notify_cb(gatt_conn_struct *conn, BD_ADDR *bd_addr, gattc_char_struct *char_info,
    ATT_VALUE *value, BOOL is_notify)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tipc_date_time_struct date_time = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]tipc_notify_cb--state: %d, bd_addr %02x:%02x%02x:%02x:%02x:%02x\n",
                    g_tipc_cntx.state, bd_addr->addr[0], bd_addr->addr[1], bd_addr->addr[2],
                    bd_addr->addr[3], bd_addr->addr[4], bd_addr->addr[5]);

    kal_trace(TRACE_GROUP_4, TIPC_SRV_DBG_GATTC_RCH_CB_VALUE_LEN, value->len);

    date_time.year = (0x00ff & value->value[0]) | (0xff00 & (value->value[1] << 8));
    date_time.month = value->value[2];
    date_time.day = value->value[3];
    date_time.hours = value->value[4];
    date_time.minutes = value->value[5];
    date_time.seconds = value->value[6];
    date_time.day_of_week = value->value[7];
    date_time.frac_256 = value->value[8];
    date_time.adj_reason = value->value[9];

if (srv_bt_cm_get_bqb_test_flag())
{
    ;
}
else
{
    g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_TIME_INFO_RESULT, OS_STATUS_SUCCESS, (void *) &date_time);
}
#ifdef __TIME_SYNC_EXT__
    if (g_tipc_cntx.hd && (g_tipc_cntx.tf_lock & 0x04))
    {
        srv_time_read_tf(g_tipc_cntx.hd);
    }
#endif
}


void srv_tipc_get_time(void *tipc_cntx)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    tipc_date_time_struct date_time = {0};
    gatt_conn_struct conn;
    gattc_char_struct char_info;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]srv_tipc_get_time--state: %d\n",
                    g_tipc_cntx.state);

    if (tipc_cntx != NULL && tipc_cntx == &g_tipc_cntx &&
        g_tipc_cntx.state == TIPC_STATE_DONE)
    {
        conn.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
        conn.conn_ctx = g_tipc_cntx.gattc_conn_cntx;
        char_info.svc_uuid = &g_tipc_cntx.srv_uuid;
        char_info.char_uuid = &g_tipc_cntx.char_uuid;
        srv_gattc_read_characteristic(&conn, &char_info, GATTC_AUTH_REQ_NONE);
    }
}


static mmi_ret srv_tipc_evt_handle(mmi_event_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_le_cm_evt_disconnect_struct *cm_evt = NULL;
    BD_ADDR bd_addr;
    gatt_conn_struct con;
    srv_tipc_dev_info_struct *tipc_dev = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    cm_evt = (srv_le_cm_evt_disconnect_struct *)evt;
    srv_util_convert_addr(cm_evt->dev_addr, &bd_addr);

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC]srv_tipc_evt_handle--state: %d\n",
                    g_tipc_cntx.state);

    if (TIPC_STATE_READY == g_tipc_cntx.state)
    {
        tipc_dev = srv_tipc_get_dev(SRV_TIP_QUERY_BY_ADDR, &bd_addr);

        if (tipc_dev)
        {
            con.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
            con.conn_ctx = tipc_dev->conn_ctx;
            srv_gattc_disconnect(&con, &bd_addr);
            srv_tipc_free_dev(tipc_dev);
        }
    }
    else
    {
        if (memcmp(g_tipc_cntx.bd_addr.addr, bd_addr.addr, BD_ADDR_SIZE) == 0)
        {
            //if (g_tipc_cntx.state == TIPC_STATE_DONE)
            if (g_tipc_cntx.state <= TIPC_STATE_DONE &&
                g_tipc_cntx.state >= TIPC_STATE_SYNCING)
            {
                con.reg_ctx = g_tipc_cntx.gattc_reg_cntx;
                con.conn_ctx = g_tipc_cntx.gattc_conn_cntx;
                srv_gattc_disconnect(&con, &bd_addr);
                g_tipc_cntx.state = TIPC_STATE_DISCONNECTING;
            }
        }
    }

    return MMI_RET_OK;
}


static void srv_util_convert_addr(srv_bt_cm_bt_addr *src, BD_ADDR *dst)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (src && dst)
    {
        dst->addr[0] = (U8)(src->lap & 0x000000FF);
        dst->addr[1] = (U8)((src->lap & 0x0000FF00) >> 8);
        dst->addr[2] = (U8)((src->lap & 0x00FF0000) >> 16);
        dst->addr[3] = src->uap;
        dst->addr[4] = (U8)(src->nap & 0x00FF);
        dst->addr[5] = (U8)((src->nap & 0xFF00) >> 8);
    }
}


/*****************************************************************************
* FUNCTION
*  srv_tipc_get_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_tipc_dev_info_struct *srv_tipc_get_dev(U8 type, void *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tipc_dev_info_struct *tipc_dev = NULL;
    S32 i = 0;
    BD_ADDR *bd_addr = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_TIP_MAX_LINK_NUM && (!tipc_dev); ++i)
    {
        if (g_tipc_cntx.dev_info[i].flag & SRV_TIP_FLAG_USED)
        {
            switch (type)
            {
                case SRV_TIP_QUERY_BY_CONN:
                {
                    if (para == g_tipc_cntx.dev_info[i].conn_ctx &&
                        (g_tipc_cntx.dev_info[i].flag & SRV_TIP_FLAG_USED))
                    {
                        tipc_dev = &g_tipc_cntx.dev_info[i];
                    }
                    break;
                }

                case SRV_TIP_QUERY_BY_ADDR:
                {
                    bd_addr = (BD_ADDR *)para;
                    if (!memcmp(bd_addr->addr, g_tipc_cntx.dev_info[i].bd_addr.addr, BD_ADDR_SIZE))
                    {
                        tipc_dev = &g_tipc_cntx.dev_info[i];
                    }
                    break;
                }

                default:
                    break;
            }
        }
    }

    kal_wap_trace(MOD_MMI_CONN_APP, TRACE_GROUP_4, "[TIPC] srv_tipc_get_dev--type: %d, dev: 0x%x\n", type, tipc_dev);

    return tipc_dev;
}


/*****************************************************************************
* FUNCTION
*  srv_tipc_alloc_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static srv_tipc_dev_info_struct *srv_tipc_alloc_dev()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_tipc_dev_info_struct *tipc_dev = NULL;
    S32 i = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    for (i = 0; i < SRV_TIP_MAX_LINK_NUM; ++i)
    {
        if (!(g_tipc_cntx.dev_info[i].flag & SRV_TIP_FLAG_USED))
        {
            tipc_dev = &g_tipc_cntx.dev_info[i];
            g_tipc_cntx.dev_info[i].flag |= SRV_TIP_FLAG_USED;
            g_tipc_cntx.dev_info[i].index = i;
            break;
        }
    }

    //MMI_ASSERT(tipc_dev);

    return tipc_dev;
}


/*****************************************************************************
* FUNCTION
*  srv_tipc_free_dev
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_tipc_free_dev(srv_tipc_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memset(dev, 0x00, sizeof(srv_tipc_dev_info_struct));
}


#ifdef __TIME_SYNC_EXT__
/*****************************************************************************
* FUNCTION
*  srv_time_tf_cb
* DESCRIPTION
*
* PARAMETERS
*
* RETURNS
*
*****************************************************************************/
static void srv_time_tf_cb(srv_time_evt_struct *evt)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_time_tf_struct *tf = NULL;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    switch (evt->evt)
    {
        case SRV_TIME_EVT_CONNECT:
        {
            break;
        }

        case SRV_TIME_EVT_DISCONNECT:
        {
            if (g_tipc_cntx.hd)
            {
                srv_time_deregister(g_tipc_cntx.hd);
                g_tipc_cntx.hd = NULL;
                g_tipc_cntx.tf_lock &= (~0x04);
            }

            break;
        }

        case SRV_TIME_EVT_TF_SEARCH:
        {
            g_tipc_cntx.tf_lock |= 0x04;
            break;
        }

        case SRV_TIME_EVT_TF_RCB:
        {
            tf = (srv_time_tf_struct *) (evt->para);
            // notify app
            g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_TIME_TF, OS_STATUS_SUCCESS, (void *)(tf->tf));

            break;
        }

        case SRV_TIME_EVT_TF_NOTI:
        {
            tf = (srv_time_tf_struct *) (evt->para);
            // notify app
            g_tipc_cntx.app_cb(&g_tipc_cntx, TIPC_EVENT_TIME_TF, OS_STATUS_SUCCESS, (void *)(tf->tf));

            break;
        }

        default:
            break;
    }
}
#endif

#endif /* __BT_GATTC_PROFILE__ */

