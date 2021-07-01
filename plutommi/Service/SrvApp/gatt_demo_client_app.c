/****************************************************************************
* Include
****************************************************************************/
#include "MMI_features.h"
#ifdef __BT_GATTC_PROFILE__ 
#include "Stdlib.h"
#include "MMIDataType.h"
#include "kal_public_api.h"
#include "GattSrv.h"
#include "GattcSrv.h"
#include "mmi_rp_srv_gatt_app_def.h"
#include "bt_demo_mode_switch.h"


/* ---------------------------------------------------------------------------
* global variables
* ------------------------------------------------------------------------ */

#define IMMEDIATE_ALERT_SERVICE    0x1802  //Immediate Alert Service, 0x1802
#define ALERT_LEVEL_CHAR_UUID      0x2A06  //Alert Level Characteristic, 0x2A06
#define IAS_SERVICE_TYPE           0  //Immediate Alert Service, 0x1802
#define DEVICE_NAME_PATTERN "MTK_BT_"
#define GATT_CONTROL_ST_COMMAND  "DemoApp: tp"
#define GATT_CONTROL_TOY_COMMAND "DemoApp: ps1"
#define GATT_MAXT_CONN 3
#define SERVICE_SERACH_RETRY_TIMES 2
typedef enum {
	APPC_STATUS_DISABLED = 0,
	APPC_STATUS_ENABLING,
	APPC_STATUS_ENABLED,
	APPC_STATUS_SCANING,
	APPC_STATUS_DISABLING,
}APPC_STATUS;

typedef struct {
	void                 *reg_ctx;
	APPC_STATUS            state;
	bt_uuid_struct        uid;      
}AppClientCntx;

typedef enum {
    APPC_STATUS_FREE = 0,
	APPC_STATUS_DISCONNECTED,
	APPC_STATUS_CONNECTING,
	APPC_STATUS_CONNECTED,
	APPC_STATUS_DISCONNECTING,
}APP_CLIENT_CONNECTION_STATUS;

typedef struct {
	void                 *conn_ctx;
	APP_CLIENT_CONNECTION_STATUS                   conn_status;
	BD_ADDR                  bdaddr;
    S32 service_find;
    S32 retry_times;
}AppClientConnCntx;


AppClientConnCntx gattc_conn_cntx[GATT_MAXT_CONN];
AppClientCntx  g_gattc_cntx = {0};

gattc_callback_struct g_gattc_cb;

const U8        g_gattc_uid[] = {
	0xB4, 0x73, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};

const U8 gattc_srv_uuid[] = 
{
	0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0X80,
	0x00, 0x10, 0x00, 0x00, 0xB0, 0x18, 0x00, 0x00
};
static GATT_SVC_UUID service_uuid;

/*{
	0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0X80,
	0x00, 0x10, 0x00, 0x00, 0x08, 0x18, 0x00, 0x10
};*/
const U8 gattc_char_uuid[] = 
{
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0X80,
    0x00, 0x10, 0x00, 0x00, 0xA0, 0x2A, 0x00, 0x00
};
/*{
	0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0X80,
	0x00, 0x10, 0x00, 0x00, 0x09, 0x2A, 0x00, 0x10
};*/
ATT_VALUE		 char_value;


/****************************************************************************
* FUNCTION DECLARATION 
****************************************************************************/
static void gatt_client_register_client_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);

/* Callback for scan results */
static void gatt_client_vmt_scan_result_callback(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir);

/*Callback indicating that a remote device has connected or been disconnected */
static void gatt_client_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);

/* Callback triggered in response to listen */
static void gatt_client_listen_callback(void *reg_ctx, OS_STATUS status);

/*Callback triggered in response to set_adv_data */
static void gatt_client_set_adv_data_callback(void *reg_ctx, OS_STATUS status){}

/**
* Invoked in response to search_service when the GATT service search
* has been completed.
*/
static void gatt_client_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status);

/*Reports GATT services on a remote device */
static void gatt_client_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid);

/* GATT characteristic enumeration result callback */
static void gatt_client_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
												   gattc_char_struct *ch, GATT_CHAR_PROPERTIES properties);

/*GATT descriptor enumeration result callback */
static void gatt_client_get_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr){}

/* GATT included service enumeration result callback */
static void gatt_client_get_included_service_callback(gatt_conn_struct *conn, OS_STATUS status,
													 GATT_SVC_UUID *svc_uuid, GATT_SVC_UUID *incl_svc_uuid){}

/* Callback invoked in response to [de]register_for_notification */
static void gatt_client_register_for_notification_callback(void *reg_ctx, OS_STATUS status, 
														  BD_ADDR *bd_addr, gattc_char_struct *ch){}

/*
* Remote device notification callback, invoked when a remote device sends
* a notification or indication that a client has registered for.
*/
static void gatt_client_notify_callback(gatt_conn_struct *conn, BD_ADDR *bd_addr,
									   gattc_char_struct *ch, ATT_VALUE *value, BOOL is_notify){}

/* Reports result of a GATT read operation */
static void gatt_client_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
													gattc_char_struct *ch, ATT_VALUE *value);

/* GATT write characteristic operation callback */
static void gatt_client_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
													 gattc_char_struct *ch);

/* Callback invoked in response to read_descriptor */
static void gatt_client_read_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
												gattc_descr_struct *descr, ATT_VALUE *value){}                                

/* Callback invoked in response to write_descriptor */
static void gatt_client_write_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
												 gattc_descr_struct *descr){}   

/* GATT execute prepared write callback */
static void gatt_client_execute_write_callback(gatt_conn_struct *conn, OS_STATUS status);

/* Callback triggered in response to read_remote_rssi */
static void gatt_client_read_remote_rssi_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi){}

/* Callback triggered in response to get_device_type */
static void gatt_client_get_device_type_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, GATTC_DEV_TYPE dev_type){}

static void gatt_client_scan_timeout_cb();

static void gatt_client_disconnect_conn(AppClientConnCntx* conn_hdl);

static void gatt_client_connect_all(void);

static kal_bool gatt_client_check_dev_is_exist(BD_ADDR* addr);


/****************************************************************************
* local variables
****************************************************************************/
/****************************************************************************
*  profile content
****************************************************************************/
void gatt_client_callback_init(gattc_callback_struct *gattc_cb)
{
	gattc_cb->register_client_cb = gatt_client_register_client_callback;
	gattc_cb->scan_result_cb = gatt_client_vmt_scan_result_callback ;
	gattc_cb->connection_cb = gatt_client_connection_callback;
	gattc_cb->listen_cb = gatt_client_listen_callback;
	gattc_cb->set_adv_data_cb = gatt_client_set_adv_data_callback;
	gattc_cb->search_complete_cb = gatt_client_search_complete_callback;
	gattc_cb->search_result_cb = gatt_client_search_result_callback;
	gattc_cb->get_characteristic_cb = gatt_client_get_characteristic_callback;
	gattc_cb->get_descriptor_cb = gatt_client_get_descriptor_callback;
	gattc_cb->get_included_service_cb = gatt_client_get_included_service_callback;
	gattc_cb->register_for_notification_cb = gatt_client_register_for_notification_callback;
	gattc_cb->notify_cb = gatt_client_notify_callback;
	gattc_cb->read_characteristic_cb = gatt_client_read_characteristic_callback;
	gattc_cb->write_characteristic_cb = gatt_client_write_characteristic_callback;
	gattc_cb->read_descriptor_cb = gatt_client_read_descriptor_callback;
	gattc_cb->write_descriptor_cb = gatt_client_write_descriptor_callback;
	gattc_cb->execute_write_cb = gatt_client_execute_write_callback;
	gattc_cb->read_remote_rssi_cb = gatt_client_read_remote_rssi_callback;
	gattc_cb->get_device_type_cb = gatt_client_get_device_type_callback;
	return;
}

void gatt_client_start(void)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_start");
    if(g_gattc_cntx.state == APPC_STATUS_DISABLED)
	{
		g_gattc_cntx.state = APPC_STATUS_ENABLING;
		memset(&g_gattc_cntx.uid,0x0,sizeof(bt_uuid_struct));
		memcpy(&g_gattc_cntx.uid.uu, &g_gattc_uid, sizeof(bt_uuid_struct));
		gatt_client_callback_init(&g_gattc_cb);
		srv_gattc_register(&g_gattc_cntx.uid, &g_gattc_cb);
	}
}
void gatt_client_register_client_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_register_client_callback");
	if(memcmp(app_uuid, &g_gattc_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if(g_gattc_cntx.state == APPC_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_gattc_cntx.reg_ctx = reg_ctx;
				g_gattc_cntx.state = APPC_STATUS_ENABLED;
				srv_gattc_scan(reg_ctx, KAL_TRUE);
                g_gattc_cntx.state = APPC_STATUS_SCANING;
                StartTimer(BT_SCAN_ALIVE_TIMER, 30000, gatt_client_scan_timeout_cb);
			}
			else
			{
				g_gattc_cntx.reg_ctx = NULL;
				g_gattc_cntx.state = APPC_STATUS_DISABLED;
			}
		}
		else if(g_gattc_cntx.state == APPC_STATUS_DISABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_gattc_cntx.reg_ctx = NULL;
				g_gattc_cntx.state = APPC_STATUS_DISABLED;
			}
			else
			{
				g_gattc_cntx.state = APPC_STATUS_ENABLED;
			}
		}
	}
}

void gatt_client_listen_callback(void *reg_ctx, OS_STATUS status)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_listen_callback, status:%d", status);
	if ((g_gattc_cntx.reg_ctx == reg_ctx) && (NULL != reg_ctx))
	{
		if(status == OS_STATUS_SUCCESS)
		{
		}
	}
}

void gatt_client_scan_timeout_cb()
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_scan_timeout_cb");
    srv_gattc_scan(g_gattc_cntx.reg_ctx, KAL_FALSE);
    g_gattc_cntx.state = APPC_STATUS_ENABLED;
    gatt_client_connect_all();
}

void gatt_client_connect_all(void)
{
    
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		if (gattc_conn_cntx[idx].conn_status == APPC_STATUS_DISCONNECTED)
		{
            srv_gattc_connect(g_gattc_cntx.reg_ctx, &gattc_conn_cntx[idx].bdaddr, KAL_TRUE);
            gattc_conn_cntx[idx].conn_status = APPC_STATUS_CONNECTING;
		}
	}
}


static AppClientConnCntx* gatt_client_get_free_conn(void)
{
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		if (gattc_conn_cntx[idx].conn_status == APPC_STATUS_FREE)
		{
		    gattc_conn_cntx[idx].conn_status = APPC_STATUS_DISCONNECTED;
            gattc_conn_cntx[idx].retry_times = SERVICE_SERACH_RETRY_TIMES;
            return &gattc_conn_cntx[idx];
		}
	}
	return NULL;
}


static S32 gatt_client_free_conn(AppClientConnCntx* conn_handle)
{
    if (conn_handle != NULL)
    {
        gatt_client_disconnect_conn(conn_handle);
        conn_handle->conn_status = APPC_STATUS_FREE;
        memset(conn_handle, 0, sizeof(AppClientConnCntx));
    }
}


static void gatt_client_free_all(void)
{
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		gatt_client_free_conn(&gattc_conn_cntx[idx]);
	}
    
	return ;
}


static void gatt_client_disconnect_conn(AppClientConnCntx* conn_hdl)
{
    gatt_conn_struct conn;
    if (!conn_hdl)
    {
        return;
    }
    if (conn_hdl->conn_status == APPC_STATUS_CONNECTED)
    {
        conn.reg_ctx = g_gattc_cntx.reg_ctx;
        conn.conn_ctx = conn_hdl->conn_ctx;
        srv_gattc_disconnect(&conn, &conn_hdl->bdaddr);
        conn_hdl->conn_status = APPC_STATUS_DISCONNECTED;
    }
}


static AppClientConnCntx*  gatt_client_search_conn_index_by_conn_id(void* conn_handle)
{
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		if (gattc_conn_cntx[idx].conn_ctx == conn_handle)
		{
		    return &gattc_conn_cntx[idx];
		}
	}
    
	return NULL;
}

static AppClientConnCntx* gatt_client_search_conn_index_by_addr(BD_ADDR* addr)
{
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		if (memcmp(&gattc_conn_cntx[idx].bdaddr.addr, addr->addr, BD_ADDR_SIZE) == 0)
		{
		    return &gattc_conn_cntx[idx];
		}
	}
    
	return NULL;
}


static kal_bool gatt_client_check_dev_is_exist(BD_ADDR* addr)
{
	U32 idx;

	for (idx = 0; idx < GATT_MAXT_CONN; idx++)
	{
		if (memcmp(&gattc_conn_cntx[idx].bdaddr.addr, addr->addr, BD_ADDR_SIZE) == 0)
		{
		    return KAL_TRUE;
		}
	}
    
	return KAL_FALSE;
}


void gatt_client_vmt_scan_result_callback(void *reg_ctx, BD_ADDR *bd_addr, S32 rssi, U8 eir_len, U8 *eir)
{
	/*----------------------------------------------------------------*/
	/* Local Variables                                                */
	/*----------------------------------------------------------------*/
	U32 idx;
	U8 server_addr[BD_ADDR_SIZE] = {0x74, 0xf4, 0xe1, 0x54, 0x62, 0x61};
    char *device_pattern = DEVICE_NAME_PATTERN;
    char *temp_eir;
    S32 toys_matched = 0;
    AppClientConnCntx* conn_cntx;
	/*----------------------------------------------------------------*/
	/* Code Body                                                      */
	/*----------------------------------------------------------------*/
/*    temp_eir = malloc(eir_len + 1);
    if (temp_eir)
    {
        memcpy(temp_eir, eir, eir_len);
        temp_eir[eir_len] = '\0';
    }
    else
    {
        temp_eir = (char *) eir;
        temp_eir[eir_len] = '\0';
    }
    for (idx = 0; idx < eir_len; idx++)
    {
        if (temp_eir[idx] == 0)
        {
            temp_eir[idx] = 0xFF;
        }
    }*/
    if (strstr(eir, device_pattern))
    {
        toys_matched = 1;
    }
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] scan_result_callback, is matched:%d", toys_matched);
	if(g_gattc_cntx.reg_ctx == reg_ctx && toys_matched)
	{

        if (gatt_client_check_dev_is_exist(bd_addr))
        {
            return;
        }
        conn_cntx = gatt_client_get_free_conn();

		if (conn_cntx)
		{
		    //srv_gattc_scan(reg_ctx,KAL_FALSE);// TODO: to check whether this is must or not
			memcpy(&conn_cntx->bdaddr, bd_addr, sizeof(BD_ADDR));
		}
        else
        {
            StopTimer(BT_SCAN_ALIVE_TIMER);
            srv_gattc_scan(reg_ctx,KAL_FALSE);
            g_gattc_cntx.state = APPC_STATUS_ENABLED;
        }
	}
}

void gatt_client_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    AppClientConnCntx* conn_cntx;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] connection_callback, is connected:%d", connected);
	if(connected)
	{
		conn_cntx = gatt_client_search_conn_index_by_addr(bd_addr);
        if (conn_cntx)
        {
            conn_cntx->conn_ctx = conn->conn_ctx;
            conn_cntx->conn_status = APPC_STATUS_CONNECTED;
            srv_gattc_search_service(conn, NULL);
            mode_switch_paly_tone(BT_MODE_SWITCH_CONNECTED);
        }
	}
    else
    {
        gatt_client_free_conn(gatt_client_search_conn_index_by_addr(bd_addr));
    }
}

void gatt_client_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid)
{
	//S32 type = -1;
    AppClientConnCntx* conn_hld;
	//type = get_gattc_service_type(uuid->uuid);
	//if(type == -1)
	//	return;
	//else if (type == 0)
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_search_result_callback");
	if(memcmp(&(uuid->uuid.uuid.uuid),&gattc_srv_uuid, (sizeof(U8) * 16)) == 0)
	{
        conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);
		if(conn_hld)
		{
			//srv_gattc_get_characteristic(conn, uuid, NULL);
			memcpy(&service_uuid, uuid, sizeof(GATT_SVC_UUID));
            conn_hld->service_find = 1;
			return;
		}
	}
}

void gatt_client_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    AppClientConnCntx* conn_hld;

    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_search_complete_callback");
    conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);
	if(conn_hld)
	{
		if(status == OS_STATUS_SUCCESS)
		{
            if (!conn_hld->service_find)
            {
                // means there are no service on this device, disconnect with this one
                gatt_client_free_conn(conn_hld);
            }
		}
        else
        {
            //retry search service.
            if (conn_hld->retry_times)
            {
                srv_gattc_search_service(conn, NULL);
                conn_hld->retry_times--;
            }
            else
            {
                gatt_client_free_conn(conn_hld);
            }
        }
		return;
	}

}

U16 gattc_convert_array_to_uuid16(ATT_UUID uu)
{
	U16 uuid = 0;

	if(uu.uuid.len == 2)
	{
		uuid = ((U16)uu.uuid.uuid[1]) << 8 | uu.uuid.uuid[0];
	}
	else if(uu.uuid.len == 16)
	{
		uuid = ((U16)uu.uuid.uuid[13]) << 8 | uu.uuid.uuid[12];
	}

	return uuid;
}

S32  get_gattc_service_type(ATT_UUID uu)
{
	U16 uuid = 0;
	S32 type = -1;

	uuid = gattc_convert_array_to_uuid16(uu);
	switch(uuid)
	{
	case IMMEDIATE_ALERT_SERVICE:
		type = IAS_SERVICE_TYPE;
		break;
	default:
		break;
	}
	return type;
}


void gatt_client_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
											gattc_char_struct *ch, GATT_CHAR_PROPERTIES properties)
{
    AppClientConnCntx* conn_hld;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_get_characteristic_callback");
    conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);

	if(conn_hld && (conn_hld->conn_ctx == conn->conn_ctx))
	{
		if(memcmp(&(ch->svc_uuid->uuid.uuid.uuid),&gattc_srv_uuid, (sizeof(U8) * 16)) == 0)
		{
			if(memcmp(&(ch->char_uuid->uuid.uuid),&gattc_char_uuid, (sizeof(U8) * 16)) == 0)
			{
				if(status == OS_STATUS_SUCCESS)
				{
					if (1)//(properties & (GATT_CHAR_PROP_WRITE | GATT_CHAR_PROP_WRITE_WO_RESPONSE))
					{
						srv_gattc_write_characteristic(conn, 
							ch, 
							&char_value,
							GATTC_WRITE_TYPE_REQUEST,
							GATTC_AUTH_REQ_NONE);
					}
                    else if (properties & (GATT_CHAR_PROP_READ))
					{
						srv_gattc_read_characteristic(conn,ch,GATTC_AUTH_REQ_NONE);
					}
				}
			}

		}
		else
		{
			if(status == OS_STATUS_SUCCESS)
			{
				srv_gattc_get_characteristic(conn, ch->svc_uuid, ch->char_uuid);
			}
		}
	}
	return ;
}

void gatt_client_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
											  gattc_char_struct *ch)
{
    AppClientConnCntx* conn_hld;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_write_characteristic_callback");
    conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);

	if(conn_hld)
	{

	}
	return;
}

void gatt_client_execute_write_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    AppClientConnCntx* conn_hld;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_execute_write_callback");
    conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);


	if(conn_hld && (conn_hld->conn_ctx == conn->conn_ctx))
	{
		if(status == OS_STATUS_SUCCESS)
		{
		}
	}
	return;
}

/* Reports result of a GATT read operation */
void gatt_client_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
											 gattc_char_struct *ch, ATT_VALUE *value)
{
    AppClientConnCntx* conn_hld;
    
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_read_characteristic_callback");
    conn_hld = gatt_client_search_conn_index_by_conn_id(conn->conn_ctx);

	if(conn_hld)
	{

	}
	return;
}

S32 gatt_client_stop(void)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_stop");
	if((g_gattc_cntx.state == APPC_STATUS_DISABLED)
		|| (g_gattc_cntx.state == APPC_STATUS_DISABLING))
		return 0;
		
    StopTimer(BT_SCAN_ALIVE_TIMER);
    if (g_gattc_cntx.state == APPC_STATUS_SCANING)
    {
        srv_gattc_scan(g_gattc_cntx.reg_ctx,KAL_FALSE);
        g_gattc_cntx.state = APPC_STATUS_ENABLED;
    }
	if(g_gattc_cntx.state == APPC_STATUS_ENABLED)
	{
        gatt_client_free_all();
	}

	srv_gattc_deregister(g_gattc_cntx.reg_ctx);
	g_gattc_cntx.state = APPC_STATUS_DISABLED;

	return 1;
}

void gatt_client_reactive_handler(void)
{
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] gatt_client_reactive_handler");
    if (g_gattc_cntx.state == APPC_STATUS_DISABLED)
    {
        gatt_client_start();
    }
    else if (g_gattc_cntx.state == APPC_STATUS_ENABLED || g_gattc_cntx.state == APPC_STATUS_SCANING)
    {
        if (g_gattc_cntx.state == APPC_STATUS_ENABLED)
        {
            srv_gattc_scan(g_gattc_cntx.reg_ctx, KAL_TRUE);
            g_gattc_cntx.state = APPC_STATUS_SCANING;
        }
        StartTimer(BT_SCAN_ALIVE_TIMER, 30000, gatt_client_scan_timeout_cb);
    }
}

void gatt_client_send_data_to_toy(char* str)
{
	U32 idx;
    gatt_conn_struct conn;

    if (str)
    {
        str += strspn(str, " \t,");
        if (strlen(str) > 20)
        {
            str[20] = '\0';
        }
    }
    else
    {
        return;
    }
    kal_prompt_trace(MOD_MMI_CONN_APP, "[BTGC] send_data_to_toy data:%s", str);
    for (idx = 0; idx < GATT_MAXT_CONN; idx++)
    {
        if (gattc_conn_cntx[idx].conn_status == APPC_STATUS_CONNECTED && gattc_conn_cntx[idx].service_find)
        {
            conn.reg_ctx = g_gattc_cntx.reg_ctx;
            conn.conn_ctx = gattc_conn_cntx[idx].conn_ctx;
            strcpy(char_value.value, str);
            char_value.len = strlen(str);
            srv_gattc_get_characteristic(&conn, &service_uuid, NULL);
        }
    }    
	return ;
}
#endif
