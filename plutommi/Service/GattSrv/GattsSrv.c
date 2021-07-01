#ifdef __BT_GATTS_PROFILE__ 

/****************************************************************************
* header files
****************************************************************************/
#include "mmi_frm_events_gprot.h"
#include "GattsSrv.h"

#include "mmi_rp_srv_gatt_def.h"
#include "BLESrvGprot.h"
#include "GattcSrv.h"
#include "BtcmSrvGprot.h"

#include "MMI_conn_app_trc.h" 
#include "MMI_trc_Int.h"




/****************************************************************************
* function define
****************************************************************************/
#ifdef __MMI_BLE_LOW_POWER__
static void gatts_conn_param_interval_reset(void);
static void gatts_conn_param_interval_req(char *bd_addr);
static void gatts_get_bd_addr_from_btcm_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src);
static void gatts_set_conn_interval_for_all_links(void);

	
#define  GATTS_BD_ADDR_SIZE                   6
#define  GATTS_SET_CONN_INTERVAL_TIME        (1000 * 15)
#define  PROFILE_ID_MHEALTH  (0xFF)

static BOOL gatts_set_conn_interval_flag = FALSE;
static U8 gatts_bdaddr[GATTS_BD_ADDR_SIZE] = {0};

	
void gatts_conn_param_interval_reset(void)
{
	StopTimer(GATTS_SET_CONN_INTERVAL_TIMER_ID);
	//gatts_set_conn_interval_flag = FALSE;
	//kal_prompt_trace(MOD_BT, "[GATTSSRV] gatts_conn_param_interval_reset success\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_CONN_INTERVAL_RESET_OK);
	srv_gattc_conn_param_update(PROFILE_ID_MHEALTH,(char *)gatts_bdaddr,CONNECTION_PRIORITY_LOW_POWER); 
}

void gatts_conn_param_interval_req(char *bd_addr)
{
	if (!bd_addr)
	{
		//kal_prompt_trace(MOD_BT, "[GATTSSRV] gatts_conn_param_interval_req addr is null\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_ADDR_NULL);
		return;
	}
	memset(gatts_bdaddr,0x00,GATTS_BD_ADDR_SIZE);
	memcpy((char *)gatts_bdaddr, bd_addr, GATTS_BD_ADDR_SIZE);
	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_CONN_INTERVAL_REQ, gatts_bdaddr[0],
		gatts_bdaddr[1],gatts_bdaddr[2],gatts_bdaddr[3],gatts_bdaddr[4],gatts_bdaddr[5]);

	StopTimer(GATTS_SET_CONN_INTERVAL_TIMER_ID);
	srv_gattc_conn_param_update(PROFILE_ID_MHEALTH,(char *)gatts_bdaddr,CONNECTION_PRIORITY_BALANCE); 
	//kal_prompt_trace(MOD_BT, "[GATTSSRV] gatts_conn_param_interval_req success\n");
	StartTimer(GATTS_SET_CONN_INTERVAL_TIMER_ID,GATTS_SET_CONN_INTERVAL_TIME,gatts_conn_param_interval_reset);
}
void gatts_get_bd_addr_from_btcm_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    memcpy((U8 *)&dst->addr[0], (U8 *)&src->lap, 3);
    dst->addr[3] = src->uap;
    memcpy((U8 *)&dst->addr[4], (U8 *)&src->nap, 2);
}

void gatts_set_conn_interval_for_all_links(void)
{
	U16 i;
	U32 linked_index = 0;
	
	linked_index = srv_ble_cm_get_connected_dev_num();
	//kal_prompt_trace(MOD_BT, "[GATTSSRV] gatts_set_conn_interval_for_all_links linked_index=%d\n", linked_index);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_CONN_SET_LINK_NUM, linked_index);

	for (i = 0; i < linked_index; i++)
	{
	    BD_ADDR remote_addr;
		srv_bt_cm_dev_struct* dev_info = NULL;
		
		dev_info = srv_ble_cm_get_connected_dev_info(i);        
        gatts_get_bd_addr_from_btcm_addr(&remote_addr, &dev_info->le_bd_addr);
		gatts_conn_param_interval_req(remote_addr.addr);
	}
	//gatts_set_conn_interval_flag = TRUE;
}
#endif /*__MMI_BLE_LOW_POWER__*/
/*add for low power end*/

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_register_cnf
 * DESCRIPTION
 *  This function is to handle gatts register confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_register_cnf(void *msg)
{
    bt_gatts_register_cnf_struct *cnf = (bt_gatts_register_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->register_server_cb)
    {
        callback->register_server_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            (bt_uuid_struct *)cnf->user_id);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_deregister_cnf
 * DESCRIPTION
 *  This function is to handle gatts deregister confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_deregister_cnf(void *msg)
{
    bt_gatts_deregister_cnf_struct *cnf = (bt_gatts_deregister_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->deregister_server_cb)
    {
        callback->deregister_server_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_connect_cnf
 * DESCRIPTION
 *  This function is to handle gatts connect confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_connect_cnf(void *msg)
{
    bt_gatts_connect_cnf_struct *cnf = (bt_gatts_connect_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL;
    gatt_conn_struct conn;

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx;    
    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->connection_cb)
    {
        if (cnf->result == 0)
        {
            callback->connection_cb(&conn, TRUE, (BD_ADDR *)cnf->bd_addr);
        }
        else if (cnf->result != 2)
        {
            callback->connection_cb(&conn, FALSE, (BD_ADDR *)cnf->bd_addr);
        }
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gatts_conn;
        
        gatts_conn.conn = &conn;
        gatts_conn.bd_addr = (BD_ADDR *)cnf->bd_addr;
        if (cnf->result == 0)
        {
            gatts_conn.connected = TRUE;
        }
        else if (cnf->result != 2)
        {
            gatts_conn.connected = FALSE;
        }
        else
        {
            return;
        }
        
		gatts_conn.is_ind = ((cnf->LocalRole == BCR_MASTER) ? FALSE : TRUE);
        callback->connection_ext_cb(&gatts_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_connected_ind
 * DESCRIPTION
 *  This function is to handle gatts connected indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_connected_ind(void *msg)
{
    bt_gatts_connected_ind_struct *ind = (bt_gatts_connected_ind_struct *)msg;
    gatts_callback_struct *callback = NULL;
    gatt_conn_struct conn;    

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    conn.reg_ctx = ind->reg_ctx;
    conn.conn_ctx = ind->conn_ctx;  
    callback = (gatts_callback_struct *)ind->app_ctx;
    if (callback->connection_cb)
    {
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_state msg;

        if (ind->LocalRole != 0xFF) //exclude the case that not link change state.
        {
            memset(&msg, 0, sizeof(msg));
            memcpy(msg.dev_addr.addr, ind->bd_addr, sizeof(ind->bd_addr));
            msg.is_conn = TRUE;
            msg.is_ind = ((ind->LocalRole == BCR_MASTER) ? FALSE : TRUE);
            msg.result = ((ind->result == 0) ? TRUE : FALSE);
            gatt_conn_state_handle(msg);
        }
#endif
        callback->connection_cb(&conn, (ind->result == 0) ? TRUE : FALSE, (BD_ADDR *)ind->bd_addr);
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gatts_conn;
        
        gatts_conn.conn = &conn;
        gatts_conn.bd_addr = (BD_ADDR *)ind->bd_addr;
        gatts_conn.connected = (ind->result == 0) ? TRUE : FALSE;
        gatts_conn.is_ind = ((ind->LocalRole == BCR_MASTER) ? FALSE : TRUE);
        callback->connection_ext_cb(&gatts_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_disconnect_cnf
 * DESCRIPTION
 *  This function is to handle gatts disconnect confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_disconnect_cnf(void *msg)
{
    bt_gatts_disconnect_cnf_struct *cnf = (bt_gatts_disconnect_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL;
    gatt_conn_struct conn;       

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    conn.reg_ctx = cnf->reg_ctx;
    conn.conn_ctx = cnf->conn_ctx; 
    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->connection_cb && (cnf->result != 2))
    {
        callback->connection_cb(&conn, FALSE, (BD_ADDR *)cnf->bd_addr);
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gatts_conn;
        
        gatts_conn.conn = &conn;
        gatts_conn.bd_addr = (BD_ADDR *)cnf->bd_addr;
        if (cnf->result != 2)
        {
            gatts_conn.connected = FALSE;
        }
        else
        {
            return;
        }
        gatts_conn.is_ind = FALSE;
        callback->connection_ext_cb(&gatts_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_disconnected_ind
 * DESCRIPTION
 *  This function is to handle gatts disconnected indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_disconnected_ind(void *msg)
{
    bt_gatts_disconnected_ind_struct *ind = (bt_gatts_disconnected_ind_struct *)msg;
    gatts_callback_struct *callback = NULL;
    gatt_conn_struct conn;        

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    conn.reg_ctx = ind->reg_ctx;
    conn.conn_ctx = ind->conn_ctx;
    callback = (gatts_callback_struct *)ind->app_ctx;
    if (callback->connection_cb)
    {
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_state msg;

        if (ind->result != 0xFF)
        {
            memset(&msg, 0, sizeof(msg));
            memcpy(msg.dev_addr.addr, ind->bd_addr, sizeof(ind->bd_addr));
            msg.is_conn = FALSE;
            msg.is_ind = (DISC_BY_LOCAL_HOST(ind->result) ? FALSE : TRUE);
            msg.result = TRUE;
            msg.reason = ind->result;
            msg.LastInd = ind->LastInd; //20150331
            gatt_conn_state_handle(msg);
        }
#endif
        callback->connection_cb(&conn, FALSE, (BD_ADDR *)ind->bd_addr);
    }
#ifdef MMI_SRV_CONN_STATE_IND
    if (callback->connection_ext_cb)
    {
        gattsrv_conn_struct gatts_conn;
        
        gatts_conn.conn = &conn;
        gatts_conn.bd_addr = (BD_ADDR *)ind->bd_addr;
        gatts_conn.connected = FALSE;
        gatts_conn.is_ind = (DISC_BY_LOCAL_HOST(ind->result) ? FALSE : TRUE);
        callback->connection_ext_cb(&gatts_conn);
    }
#endif    
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_listen_cnf
 * DESCRIPTION
 *  This function is to handle gatts listen confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_listen_cnf(void *msg)
{
    bt_gatts_listen_cnf_struct *cnf = (bt_gatts_listen_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL;      

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->listen_cb)
    {
        callback->listen_cb(cnf->reg_ctx, (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED);
    }
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_add_service_cnf
 * DESCRIPTION
 *  This function is to handle gatts add service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_add_service_cnf(void *msg)
{
    bt_gatts_add_service_cnf_struct *cnf = (bt_gatts_add_service_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->service_added_cb)
    {
        callback->service_added_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, &cnf->uuid, cnf->service_handle);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_add_incl_service_cnf
 * DESCRIPTION
 *  This function is to add gatts included service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_add_incl_service_cnf(void *msg)
{
    bt_gatts_add_incl_service_cnf_struct *cnf = (bt_gatts_add_incl_service_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->included_service_added_cb)
    {
        callback->included_service_added_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, cnf->service_handle, cnf->incl_service_handle);
    }  
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_add_char_cnf
 * DESCRIPTION
 *  This function is to handle gatts add characteristic confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_add_char_cnf(void *msg)
{
    bt_gatts_add_char_cnf_struct *cnf = (bt_gatts_add_char_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->characteristic_added_cb)
    {
        callback->characteristic_added_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, &cnf->char_uuid, cnf->service_handle, cnf->char_handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_add_descr_cnf
 * DESCRIPTION
 *  This function is to handle gatts add descriptor confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_add_descr_cnf(void *msg)
{
    bt_gatts_add_descr_cnf_struct *cnf = (bt_gatts_add_descr_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->descriptor_added_cb)
    {
        callback->descriptor_added_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, &cnf->descr_uuid, cnf->service_handle, cnf->descr_handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_start_service_cnf
 * DESCRIPTION
 *  This function is to handle gatts start service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_start_service_cnf(void *msg)
{
    bt_gatts_start_service_cnf_struct *cnf = (bt_gatts_start_service_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->service_started_cb)
    {
        callback->service_started_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, cnf->service_handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_stop_service_cnf
 * DESCRIPTION
 *  This function is to handle gatts stop service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_stop_service_cnf(void *msg)
{
    bt_gatts_stop_service_cnf_struct *cnf = (bt_gatts_stop_service_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->service_stopped_cb)
    {
        callback->service_stopped_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, cnf->service_handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_delete_service_cnf
 * DESCRIPTION
 *  This function is to handle gatts delete service confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_delete_service_cnf(void *msg)
{
    bt_gatts_delete_service_cnf_struct *cnf = (bt_gatts_delete_service_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->service_deleted_cb)
    {
        callback->service_deleted_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->reg_ctx, cnf->service_handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_send_indication_cnf
 * DESCRIPTION
 *  This function is to handle gatts send indication confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_send_indication_cnf(void *msg)
{
    bt_gatts_send_indication_cnf_struct *cnf = (bt_gatts_send_indication_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (cnf->need_confirm && callback->response_confirmation_cb)
    {
        callback->response_confirmation_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_send_response_cnf
 * DESCRIPTION
 *  This function is to handle gatts send response confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_send_response_cnf(void *msg)
{
    bt_gatts_send_response_cnf_struct *cnf = (bt_gatts_send_response_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->response_confirmation_cb)
    {
        callback->response_confirmation_cb((cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            cnf->handle);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_read_tx_power_cnf
 * DESCRIPTION
 *  This function is to handle gatts read tx power confirm message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_read_tx_power_cnf(void *msg)
{
    bt_gatts_read_tx_power_cnf_struct *cnf = (bt_gatts_read_tx_power_cnf_struct *)msg;
    gatts_callback_struct *callback = NULL; 

    if (!cnf || !cnf->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)cnf->app_ctx;
    if (callback->read_tx_power_cb)
    {
        callback->read_tx_power_cb(cnf->reg_ctx, 
            (cnf->result == 0) ? OS_STATUS_SUCCESS : OS_STATUS_FAILED, 
            (BD_ADDR *)cnf->bd_addr, cnf->tx_power);        
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_read_request_ind
 * DESCRIPTION
 *  This function is to handle gatts read request indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_read_request_ind(void *msg)
{
    bt_gatts_read_request_ind_struct *ind = (bt_gatts_read_request_ind_struct *)msg;
    gatts_callback_struct *callback = NULL; 
    gatt_conn_struct conn;

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)ind->app_ctx;
    if (callback->request_read_cb)
    {
        conn.reg_ctx = ind->reg_ctx;
        conn.conn_ctx = ind->conn_ctx;        
        callback->request_read_cb(&conn, ind->trans_id, (BD_ADDR *)ind->bd_addr, 
            ind->handle, ind->offset, ind->is_long);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_write_request_ind
 * DESCRIPTION
 *  This function is to handle gatts write request indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_write_request_ind(void *msg)
{
    bt_gatts_write_request_ind_struct *ind = (bt_gatts_write_request_ind_struct *)msg;
    gatts_callback_struct *callback = NULL; 
    gatt_conn_struct conn;
    ATT_VALUE value;

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)ind->app_ctx;
    if (callback->request_write_cb)
    {
        conn.reg_ctx = ind->reg_ctx;
        conn.conn_ctx = ind->conn_ctx;
        value.len = (ind->value.len > ATT_MAX_VALUE_LEN) ? ATT_MAX_VALUE_LEN : ind->value.len;
        if (value.len)
        {
            memcpy(value.value, ind->value.value, value.len);
        }
        callback->request_write_cb(&conn, ind->trans_id, (BD_ADDR *)ind->bd_addr, 
            ind->handle, &value, ind->offset, ind->need_rsp, ind->is_prepare);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_execute_write_request_ind
 * DESCRIPTION
 *  This function is to handle gatts execute write request indication message
 * PARAMETERS
 *  msg     [IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_execute_write_request_ind(void *msg)
{
    bt_gatts_exec_write_request_ind_struct *ind = (bt_gatts_exec_write_request_ind_struct *)msg;
    gatts_callback_struct *callback = NULL; 
    gatt_conn_struct conn;

    if (!ind || !ind->app_ctx)
    {
        return;
    }

    callback = (gatts_callback_struct *)ind->app_ctx;
    if (callback->request_exec_write_cb)
    {
        conn.reg_ctx = ind->reg_ctx;
        conn.conn_ctx = ind->conn_ctx;        
        callback->request_exec_write_cb(&conn, ind->trans_id, (BD_ADDR *)ind->bd_addr, ind->cancel);
    } 
}

/*****************************************************************************
 * FUNCTION
 *  gatts_handle_update_connected_info
 * DESCRIPTION
 *  This function is to handle gatts update connected name message
 * PARAMETERS
 *  msg     [IN]: bt_gatts_connected_info_struct
 * RETURNS
 *  void
 *****************************************************************************/
static void gatts_handle_update_connected_info(void *msg)
{
    bt_gatts_connected_info_struct *info = (bt_gatts_connected_info_struct *)msg;
        
    if (!info || !info->app_ctx)
    {
        return;
    }
    
#ifdef MMI_SRV_CONN_STATE_IND
    gatt_update_remote_device_name(info->dev_name, (BD_ADDR *)info->bd_addr);
#endif
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_init(void)
{
    SetProtocolEventHandler(gatts_handle_register_cnf, MSG_ID_BT_GATTS_REGISTER_CNF);
    SetProtocolEventHandler(gatts_handle_deregister_cnf, MSG_ID_BT_GATTS_DEREGISTER_CNF);    
    SetProtocolEventHandler(gatts_handle_connect_cnf, MSG_ID_BT_GATTS_CONNECT_CNF);
    SetProtocolEventHandler(gatts_handle_connected_ind, MSG_ID_BT_GATTS_CONNECTED_IND);
    SetProtocolEventHandler(gatts_handle_disconnect_cnf, MSG_ID_BT_GATTS_DISCONNECT_CNF);
    SetProtocolEventHandler(gatts_handle_disconnected_ind, MSG_ID_BT_GATTS_DISCONNECTED_IND);
    SetProtocolEventHandler(gatts_handle_listen_cnf, MSG_ID_BT_GATTS_LISTEN_CNF);    
    SetProtocolEventHandler(gatts_handle_add_service_cnf, MSG_ID_BT_GATTS_ADD_SERVICE_CNF);  
    SetProtocolEventHandler(gatts_handle_add_incl_service_cnf, MSG_ID_BT_GATTS_ADD_INCL_SERVICE_CNF); 
    SetProtocolEventHandler(gatts_handle_add_char_cnf, MSG_ID_BT_GATTS_ADD_CHAR_CNF); 
    SetProtocolEventHandler(gatts_handle_add_descr_cnf, MSG_ID_BT_GATTS_ADD_DESCR_CNF); 
    SetProtocolEventHandler(gatts_handle_start_service_cnf, MSG_ID_BT_GATTS_START_SERVICE_CNF); 
    SetProtocolEventHandler(gatts_handle_stop_service_cnf, MSG_ID_BT_GATTS_STOP_SERVICE_CNF);     
    SetProtocolEventHandler(gatts_handle_delete_service_cnf, MSG_ID_BT_GATTS_DELETE_SERVICE_CNF);  
    SetProtocolEventHandler(gatts_handle_send_indication_cnf, MSG_ID_BT_GATTS_SEND_INDICATION_CNF); 
    SetProtocolEventHandler(gatts_handle_send_response_cnf, MSG_ID_BT_GATTS_SEND_RESPONSE_CNF); 
    SetProtocolEventHandler(gatts_handle_read_tx_power_cnf, MSG_ID_BT_GATTS_READ_TX_POWER_CNF);     
    SetProtocolEventHandler(gatts_handle_read_request_ind, MSG_ID_BT_GATTS_READ_REQUEST_IND); 
    SetProtocolEventHandler(gatts_handle_write_request_ind, MSG_ID_BT_GATTS_WRITE_REQUEST_IND); 
    SetProtocolEventHandler(gatts_handle_execute_write_request_ind, MSG_ID_BT_GATTS_EXEC_WRITE_REQUEST_IND);      
    SetProtocolEventHandler(gatts_handle_update_connected_info, MSG_ID_BT_GATTS_UPDATE_CONNECTED_INFO);      
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_register
 * DESCRIPTION
 *  Registers a GATT server application with the stack
 * PARAMETERS
 *  uuid     [IN]
 *  callback [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_register(bt_uuid_struct *uuid, gatts_callback_struct *callback)
{
    bt_gatts_register_req_struct *req = NULL;

    if (!uuid)
    {
        return;
    }
    req = (bt_gatts_register_req_struct*)
            construct_local_para(sizeof(bt_gatts_register_req_struct), TD_CTRL);    
    if (req)
    {
        req->app_ctx = callback;
        memcpy(req->user_id, uuid->uu, sizeof(uuid->uu));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_REGISTER_REQ, (void*)req);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_deregister
 * DESCRIPTION
 *  Unregister a server application from the stack
 * PARAMETERS
 *  reg_ctx [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_deregister(void *reg_ctx)
{
    bt_gatts_deregister_req_struct *req = (bt_gatts_deregister_req_struct*)
            construct_local_para(sizeof(bt_gatts_deregister_req_struct), TD_CTRL);
    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_DEREGISTER_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_connect
 * DESCRIPTION
 *  Create a connection to a remote peripheral
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 *  direct  [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_connect(void *reg_ctx, BD_ADDR *bd_addr, BOOL direct)
{
    bt_gatts_connect_req_struct *req = NULL;
    
    if (!bd_addr)
    {
        return;
    }
    req = (bt_gatts_connect_req_struct*)
        construct_local_para(sizeof(bt_gatts_connect_req_struct), TD_CTRL);
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->direct = direct;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_CONNECT_REQ, (void*)req);
#ifdef MMI_SRV_CONN_STATE_IND
        gatt_conn_clear_state(bd_addr);
#endif
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_disconnect
 * DESCRIPTION
 *  Disconnect an established connection or cancel a pending one
 * PARAMETERS
 *  conn    [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr)
{
    bt_gatts_disconnect_req_struct *req = NULL;

    if (!conn || !bd_addr)
    {
        return;
    }
    req = (bt_gatts_disconnect_req_struct*)
            construct_local_para(sizeof(bt_gatts_disconnect_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_DISCONNECT_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_listen
 * DESCRIPTION
 *  Start or stop a listen for connection
 * PARAMETERS
 *  reg_ctx [IN]
 *  start   [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_listen(void *reg_ctx, BOOL start)
{
    bt_gatts_listen_req_struct *req = NULL;

    req = (bt_gatts_listen_req_struct*)
            construct_local_para(sizeof(bt_gatts_listen_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->start = start;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_LISTEN_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_set_adv_data
 * DESCRIPTION
 *  Set advertise data
 * PARAMETERS
 *  reg_ctx           [IN] register context, can get it from register callback
 *  set_scan_rsp      [IN] scan response
 *  include_name      [IN] include name or not?
 *  include_txpower   [IN] include txpower or not?
 *  min_interval      [IN] min interval
 *  max_interval      [IN] max interval
 *  appearance        [IN] appearance
 *  manufacturer_len  [IN] manufacturer length
 *  manufacturer_data [IN] manufacturer data string
 *  service_data_len  [IN] service data length
 *  service_data      [IN] service data
 *  service_uuid_len  [IN] service uuid length
 *  service_uuid      [IN] service uuid data
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_set_adv_data(void *reg_ctx, BOOL set_scan_rsp, BOOL include_name, BOOL include_txpower, 
                                U16 min_interval, U16 max_interval, U16 appearance,
                                U16 manufacturer_len, char *manufacturer_data,
                                U16 service_data_len, char *service_data,
                                U16 service_uuid_len, char *service_uuid)
{
    bt_gatts_set_adv_data_req_struct *req = NULL;

    req = (bt_gatts_set_adv_data_req_struct*)
            construct_local_para(sizeof(bt_gatts_set_adv_data_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->set_scan_rsp = set_scan_rsp;
        req->include_name = include_name;
        req->include_txpower = include_txpower;
        req->min_interval = min_interval;
        req->max_interval = max_interval;
        req->appearance = appearance;
        req->manufacturer_len = (manufacturer_len > 512) ? 512 : manufacturer_len;  
        req->service_data_len = (service_data_len > 512) ? 512 : service_data_len;    
        req->service_uuid_len = (service_uuid_len > 512) ? 512 : service_uuid_len;    
        if (manufacturer_data)
        {
            memcpy(req->manufacturer_data, manufacturer_data, req->manufacturer_len);
        }
        if (service_data)
        {
            memcpy(req->service_data, service_data, req->service_data_len);
        }
        if (service_uuid)
        {
            memcpy(req->service_uuid, service_uuid, req->service_uuid_len);
        }        
        
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_SET_ADV_DATA_REQ, (void*)req);
    }    
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_add_service
 * DESCRIPTION
 *  Create a new service
 * PARAMETERS
 *  reg_ctx     [IN]
 *  srvc_id     [IN]
 *  num_handles [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_add_service(void *reg_ctx, GATT_SVC_UUID *srvc_id, U16 num_handles)
{
    bt_gatts_add_service_req_struct *req = NULL;

    if (!srvc_id)
    {
        return;
    }
    req = (bt_gatts_add_service_req_struct*)
            construct_local_para(sizeof(bt_gatts_add_service_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->num_handles = num_handles;
        memcpy(&req->uuid, srvc_id, sizeof(GATT_SVC_UUID));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_ADD_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_add_included_service
 * DESCRIPTION
 *  Assign an included service to it's parent service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 *  included_handle [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_add_included_service(void *reg_ctx, ATT_HANDLE service_handle, 
                                    ATT_HANDLE included_handle)
{
    bt_gatts_add_incl_service_req_struct *req = (bt_gatts_add_incl_service_req_struct*)
            construct_local_para(sizeof(bt_gatts_add_incl_service_req_struct), TD_CTRL);  
    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        req->incl_service_handle = included_handle;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_ADD_INCL_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_add_characteristic
 * DESCRIPTION
 *  Add a characteristic to a service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 *  uuid            [IN]
 *  properties      [IN]
 *  permission      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_add_characteristic(void *reg_ctx, 
                                  ATT_HANDLE service_handle, ATT_UUID *uuid,
                                  GATT_CHAR_PROPERTIES properties, GATT_PERMISSION permission)
{
    bt_gatts_add_char_req_struct *req = NULL;

    if (!uuid)
    {
        return;
    }
    req = (bt_gatts_add_char_req_struct*)
            construct_local_para(sizeof(bt_gatts_add_char_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        req->properties = properties;
        req->permission = permission;
        memcpy(&req->char_uuid, uuid, sizeof(ATT_UUID));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_ADD_CHAR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_add_descriptor
 * DESCRIPTION
 *  Add a descriptor to a given service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 *  uuid            [IN]
 *  permission      [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_add_descriptor(void *reg_ctx, ATT_HANDLE service_handle,
                              ATT_UUID *uuid, GATT_PERMISSION permission)
{
    bt_gatts_add_descr_req_struct *req = NULL;

    if (!uuid)
    {
        return;
    }
    req = (bt_gatts_add_descr_req_struct*)
            construct_local_para(sizeof(bt_gatts_add_descr_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        req->permission = permission;
        memcpy(&req->descr_uuid, uuid, sizeof(ATT_UUID));
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_ADD_DESCR_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_start_service
 * DESCRIPTION
 *  Starts a local service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 *  transport       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_start_service(void *reg_ctx, ATT_HANDLE service_handle,
                             GATT_TRANSPORT transport)
{
    bt_gatts_start_service_req_struct *req = NULL;

    req = (bt_gatts_start_service_req_struct*)
            construct_local_para(sizeof(bt_gatts_start_service_req_struct), TD_CTRL);    
    if (req)
    {
    
#ifdef __MMI_BLE_LOW_POWER__
	//if (TRUE != gatts_set_conn_interval_flag)
	{
	    gatts_set_conn_interval_for_all_links();
	    //kal_prompt_trace(MOD_BT, "[GATTSSRV] srv_gatts_start_service\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_CONN_SET_START_SERVICE);
	}
#endif
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        req->transport = transport;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_START_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_stop_service
 * DESCRIPTION
 *  Stops a local service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_stop_service(void *reg_ctx, ATT_HANDLE service_handle)
{
    bt_gatts_stop_service_req_struct *req = NULL;

    req = (bt_gatts_stop_service_req_struct*)
            construct_local_para(sizeof(bt_gatts_stop_service_req_struct), TD_CTRL);    
    if (req)
    {
#ifdef __MMI_BLE_LOW_POWER__
	//if (TRUE != gatts_set_conn_interval_flag)
	{
	    gatts_set_conn_interval_for_all_links();
	    //kal_prompt_trace(MOD_BT, "[GATTSSRV] srv_gatts_stop_service\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_GATTS_CONN_SET_STOP_SERVICE);
	}
#endif
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_STOP_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_delete_service
 * DESCRIPTION
 *  Delete a local service
 * PARAMETERS
 *  reg_ctx         [IN]
 *  service_handle  [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_delete_service(void *reg_ctx, ATT_HANDLE service_handle)
{
    bt_gatts_delete_service_req_struct *req = NULL;

    req = (bt_gatts_delete_service_req_struct*)
            construct_local_para(sizeof(bt_gatts_delete_service_req_struct), TD_CTRL);    
    if (req)
    {
        req->reg_ctx = reg_ctx;
        req->service_handle = service_handle;
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_DELETE_SERVICE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_send_indication
 * DESCRIPTION
 *  Send value indication to a remote device
 * PARAMETERS
 *  conn             [IN]
 *  attribute_handle [IN]
 *  need_confirm     [IN]
 *  value            [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_send_indication(gatt_conn_struct *conn, ATT_HANDLE attribute_handle,
                               BOOL need_confirm, ATT_VALUE *value)
{
    bt_gatts_send_indication_req_struct *req = NULL;

    if (!conn || !value)
    {
        return;
    }
    req = (bt_gatts_send_indication_req_struct*)
            construct_local_para(sizeof(bt_gatts_send_indication_req_struct) - sizeof(ATT_VALUE) + sizeof(value->len) + value->len, TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;
        req->handle = attribute_handle;
        req->need_confirm = need_confirm;
        req->value.len = value->len;
        if (value->len)
        {
            memcpy(req->value.value, value->value, value->len);
        }
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_SEND_INDICATION_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_send_response
 * DESCRIPTION
 *  Send a response to a read/write operation
 * PARAMETERS
 *  conn     [IN]
 *  trans_id [IN]
 *  result   [IN]
 *  handle   [IN] 
 *  value    [IN] 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_send_response(gatt_conn_struct *conn, U16 trans_id,
                             U8 status, ATT_HANDLE handle, ATT_VALUE *value)
{
    bt_gatts_send_response_req_struct *req = NULL;

    if (!conn || !value)
    {
        return;
    }
    req = (bt_gatts_send_response_req_struct*)
            construct_local_para(sizeof(bt_gatts_send_response_req_struct) - sizeof(ATT_VALUE) + sizeof(value->len) + value->len, TD_CTRL);    
    if (req)
    {
        req->reg_ctx = conn->reg_ctx;
        req->conn_ctx = conn->conn_ctx;
        req->result = status;
        req->trans_id = trans_id;
        req->handle = handle;
        req->value.len = value->len;
        if (value->len)
        {
            memcpy(req->value.value, value->value, value->len);
        }        
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_SEND_RESPONSE_REQ, (void*)req);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_gatts_read_tx_power
 * DESCRIPTION
 *  Request tx power for a given remote device
 * PARAMETERS
 *  reg_ctx [IN]
 *  bd_addr [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void srv_gatts_read_tx_power(void *reg_ctx, BD_ADDR *bd_addr)
{
    bt_gatts_read_tx_power_req_struct *req = NULL;
    
    if (!bd_addr)
    {
        return;
    }    
    req = (bt_gatts_read_tx_power_req_struct*)
                construct_local_para(sizeof(bt_gatts_read_tx_power_req_struct), TD_CTRL);     
    if (req)
    {       
        req->reg_ctx = reg_ctx;
        memcpy(req->bd_addr, bd_addr->addr, sizeof(bd_addr->addr));   
        gatt_send_msg_to_bt((U16)MSG_ID_BT_GATTS_READ_TX_POWER_REQ, (void*)req);
    }
}
#endif
