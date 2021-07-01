#ifdef __BT_GATTS_PROFILE__ 

#include "DebugInitDef_Int.h"
#include "PrxrSrv.h"
#include "Prxr_def.h"
#include "MMI_features.h"
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"
#endif

#include "MMI_conn_app_trc.h" 
#include "MMI_trc_Int.h"

#ifdef MMI_SRV_BT_PRXR_PROFILE 

/** BT-GATT Server callback structure. */
void prxr_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void prxr_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void prxr_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);
void prxr_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);
void prxr_response_confirmation_callback(OS_STATUS status, ATT_HANDLE handle);
void prxr_read_txpower_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power);
void prxr_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

//void prxr_get_services_callback(OS_STATUS status, void *reg_ctx);
void prxr_add_services_callback(OS_STATUS status, void *reg_ctx);
//void prxr_delete_services_callback(OS_STATUS status, void *reg_ctx);
BtStatus prxr_init(prxr_callback_t *cb);
BtStatus prxr_deinit();
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
mmi_ret prxr_handle_cm_disconnect(mmi_event_struct *para);
#endif
void prxr_connection_ext_callback(gattsrv_conn_struct *conn);

#define PRXR_MAX_VALUE_LEN 1

PrxrCntx  g_prxr_cntx = {0};
U8        g_prxr_uid[] = {
	0xB5, 0x74, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};
gatts_callback_struct g_prxr_cb = {
	prxr_register_server_callback,
    prxr_connection_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	prxr_service_started_callback,
	NULL,
	NULL,
	prxr_request_read_callback,
	prxr_request_write_callback,
	NULL,
	prxr_response_confirmation_callback,
	prxr_read_txpower_callback,
	NULL,
    prxr_connection_ext_callback,
};
gatts_factory_callback_struct g_prxr_factory_cb = {
	NULL,
	NULL,
	prxr_add_services_callback,
	NULL,
};

int prxr_find_uuid_by_handle(ATT_HANDLE att_handle, ATT_UUID *svc_uuid, ATT_UUID *chr_uuid)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_prxr_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_find_uuid_by_handle %x!\n", att_handle);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_FIND_UUID_BY_HANDLE, att_handle);
	if(mmi_IsListEmpty(&g_prxr_cntx.srv_list.srvlist))
		return TYPE_UNKNOW;
	while((ListEntry *)svc_list != &g_prxr_cntx.srv_list.srvlist)
	{
		if(svc_list->handle == att_handle)
		{
			//kal_prompt_trace(MOD_BT, "[PRXR] svc_list->type %d!\n", svc_list->type);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_FIND_TYPE_BY_HANDLE, svc_list->type);
			switch(svc_list->type)
			{
			case TYPE_SERVICE:
				memcpy(svc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
				return TYPE_SERVICE;
				
			case TYPE_CHARACTERISTIC:
				memcpy(chr_uuid, &svc_list->uuid, sizeof(ATT_UUID));
				prxr_find_uuid_by_handle(svc_list->srvhandle, svc_uuid, chr_uuid);
				return TYPE_CHARACTERISTIC;
				
			default:
				return svc_list->type;
			}
		}
			
		svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
	}
	return TYPE_UNKNOW;
}

void prxr_clear_req()
{
	PrxrReq *pNode = (PrxrReq *)mmi_GetHeadList(&g_prxr_cntx.req_list);
	PrxrReq *pNext = NULL;

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_clear_req!\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_CLEAR_REQ);
	if(mmi_IsListEmpty(&g_prxr_cntx.req_list))
		return;
	while((ListEntry *)pNode != &g_prxr_cntx.req_list)
	{
		pNext = (PrxrReq *)mmi_GetNextNode(&g_prxr_cntx.req_list);
		mmi_RemoveEntryList(&pNode->req_node);
		free_ctrl_buffer(pNode);
		pNode = pNext;
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_clear_req-!\n");
}

void prxr_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_register_server_callback status %d, op_flag %d!\n", status, g_prxr_cntx.op_flag);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SERVER_REGISTER_CB, status, g_prxr_cntx.op_flag);
	if(memcmp(app_uuid, &g_prxr_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if(g_prxr_cntx.state == PRX_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_prxr_cntx.reg_ctx = reg_ctx;
				if(g_prxr_cntx.op_flag == PRXR_OP_INIT)
				{
					g_prxr_cntx.op_flag = PRXR_OP_ADD_SERVICE;
					srv_gatts_profile_factory_get_services(g_prxr_cntx.reg_ctx, PROFILE_ID_PXP, &g_prxr_cntx.srv_list);
					srv_gatts_profile_factory_add_services(g_prxr_cntx.reg_ctx, &g_prxr_cntx.srv_list);
				}
			}
			else
			{
				prxr_clear_req();
				g_prxr_cntx.reg_ctx = NULL;
				g_prxr_cntx.callback = NULL;
				g_prxr_cntx.op_flag = PRXR_OP_DEINIT;
				g_prxr_cntx.state = PRX_STATUS_DISABLED;
			}
		}
		else if(g_prxr_cntx.state == PRX_STATUS_DISABLING)
		{	
			if(g_prxr_cntx.op_flag == PRXR_OP_INIT)
			{
				g_prxr_cntx.state = PRX_STATUS_ENABLING;
				srv_gatts_profile_factory_register(&g_prxr_cntx.uid, &g_prxr_cb, &g_prxr_factory_cb);
			}
			else
			{
				prxr_clear_req();
				g_prxr_cntx.reg_ctx = NULL;
				g_prxr_cntx.callback = NULL;
				g_prxr_cntx.op_flag = PRXR_OP_DEINIT;
				g_prxr_cntx.state = PRX_STATUS_DISABLED;
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_register_server_callback-!\n");
}

void prxr_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	PrxrConnCntx    *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
	PrxrConnCntx    *pConnNext = NULL;

	if(g_prxr_cntx.state == PRX_STATUS_DISABLED)
	{
		//kal_prompt_trace(MOD_BT, "[PRXR] Error State %d, ignore connect ind!\n", g_prxr_cntx.state);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_CONN_ERROR, g_prxr_cntx.state);
		return;
	}
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_CONN_CB, connected);
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_connection_callback connected %d!\n", connected);
	while ((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
	{
		pConnNext = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[PRXR] find in list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_FIND_IN_LIST);
			pConnNode->conn_ctx = conn->conn_ctx;
			if(connected  && (pConnNode->conn_status != PRX_STATUS_CONNECTED))
			{
				//do next step Discovery all
                if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
				srv_gatts_listen(conn->reg_ctx, FALSE);
				//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
				pConnNode->lls_alert_level = PRX_ALERT_LEVEL_NO;
				pConnNode->conn_status = PRX_STATUS_CONNECTED;
				if(g_prxr_cntx.callback != NULL)
					g_prxr_cntx.callback->connection_state_cb(bd_addr->addr, PRX_STATUS_CONNECTED);
			}
			else if(!connected)
			{
				srv_gatts_listen(conn->reg_ctx, TRUE);
				mmi_RemoveEntryList(&pConnNode->conn_node);
				free_ctrl_buffer(pConnNode);
				if(g_prxr_cntx.callback != NULL)
					g_prxr_cntx.callback->connection_state_cb(bd_addr->addr, PRX_STATUS_DISCONNECTED);
			}
			return;
		}
		pConnNode = pConnNext;
	}

	if(connected)
	{
		//kal_prompt_trace(MOD_BT, "[PRXR] not find in list!\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_NOT_FIND_IN_LIST);
		pConnNode = (PrxrConnCntx *)get_ctrl_buffer(sizeof(PrxrConnCntx));
		memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
		pConnNode->conn_ctx = conn->conn_ctx;
		pConnNode->lls_alert_level = PRX_ALERT_LEVEL_NO;
        if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
		srv_gatts_listen(conn->reg_ctx, FALSE);
		//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
		pConnNode->conn_status = PRX_STATUS_CONNECTED;
		mmi_InsertTailList(&g_prxr_cntx.conn_list, &pConnNode->conn_node);
		if(g_prxr_cntx.callback != NULL)
			g_prxr_cntx.callback->connection_state_cb(bd_addr->addr, PRX_STATUS_CONNECTED);
	}
}

void prxr_connection_ext_callback(gattsrv_conn_struct *conn)
{
    if (!conn)
    {
        return;
    }
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_CONN_EXT_CB, conn->connected, conn->is_ind);
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_connection_ext_callback connected %d, is_ind:%d!\n", conn->connected, conn->is_ind);
}

void prxr_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
	PrxrConnCntx    *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = prxr_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
	ATT_VALUE        att_value;
	PrxrReq         *pNode = NULL;
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_READ_CB, attr_handle, chr_uuid16);
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_request_read_callback attr_handle %x, uuid %x!\n", attr_handle, chr_uuid16);
	if(type == TYPE_CHARACTERISTIC)
	{
		if((chr_uuid16 == TX_POWER_CHAR_UUID) && (svc_uuid16 == TX_POWER_SERVICE))
		{
			pNode = (PrxrReq *)get_ctrl_buffer(sizeof(PrxrReq));
			pNode->att_handle = attr_handle;
			memcpy(pNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
			pNode->gatt_conn.reg_ctx = conn->reg_ctx;
			pNode->gatt_conn.conn_ctx = conn->conn_ctx;
			pNode->req_type = PRXR_REQ_READ_TXPOWER;
			pNode->trans_id = trans_id;
			pNode->offset = offset;
			mmi_InsertTailList(&g_prxr_cntx.req_list, &pNode->req_node);
			srv_gatts_read_tx_power(conn->reg_ctx, bd_addr);
		}
		else if((chr_uuid16 == ALERT_LEVEL_CHAR_UUID) && (svc_uuid16 == LINK_LOSS_SERVICE))
		{
			while ((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
		{
				if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
				{
					att_value.len = 1;
					att_value.value[offset] = pConnNode->lls_alert_level;
					srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);
					break;
				}
				pConnNode = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		}
	}
	else
	{
		att_value.len = 1;
		att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
		srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
	}
	}
	else
	{
		att_value.len = 1;
		att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
		srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_request_read_callback -!\n");
	
}

void prxr_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
	PrxrConnCntx    *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = prxr_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
	ATT_VALUE        att_value;
	PrxrReq         *pNode = NULL;

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_WRITE_CB, attr_handle, svc_uuid16, chr_uuid16);
	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	if(type == TYPE_CHARACTERISTIC)
	{
		while ((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
		{
			if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
			{
				//kal_prompt_trace(MOD_BT, "[PRXR] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_FIND_IN_LIST);
				if(svc_uuid16 == LINK_LOSS_SERVICE && chr_uuid16 == ALERT_LEVEL_CHAR_UUID)
				{
					pConnNode->lls_alert_level = value->value[offset];
					srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value);
					if(g_prxr_cntx.callback)
						g_prxr_cntx.callback->config_level_cb(bd_addr->addr, value->value[offset]);
				}
				else if(svc_uuid16 == IMMEDIATE_ALERT_SERVICE && chr_uuid16 == ALERT_LEVEL_CHAR_UUID)
				{
					if(g_prxr_cntx.callback)
						g_prxr_cntx.callback->alert_notify_cb(bd_addr->addr, value->value[offset]);
				}
				else
				{
					att_value.len = 1;
					att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
					srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
				}
				return;
			}
			pConnNode = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		}
	}
	else
	{
		//kal_prompt_trace(MOD_BT, "[PRXR] other type!\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_TYPE_ERROR);
		att_value.len = 1;
		att_value.value[offset] = GATT_ERROR_REQUEST_NOT_SUPPORT;
		srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, &att_value);
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_request_write_callback -!\n");
}

void prxr_response_confirmation_callback(OS_STATUS status, ATT_HANDLE handle)
{
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_response_confirmation_callback handle %x!\n", handle);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_CONFIRMATION_CB, handle);
}

void prxr_read_txpower_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, U8 tx_power)
{
	PrxrReq         *pNode = (PrxrReq *)mmi_GetHeadList(&g_prxr_cntx.req_list);
	PrxrReq         *pNext = NULL;

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_read_txpower_callback status %d, tx_power %x!\n", status, tx_power);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_TXPOWER_READ_CB, status, tx_power);
	while((ListEntry *)pNode != &g_prxr_cntx.req_list)
	{
		if((memcmp(pNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE) == 0)
			&& (pNode->req_type == PRXR_REQ_READ_TXPOWER))
		{
			pNext = (PrxrReq *)mmi_GetNextNode(&pNode->req_node);
			if(status == OS_STATUS_SUCCESS)
			{
				pNode->att_value.len = 1;
    			pNode->att_value.value[pNode->offset] = tx_power;
				srv_gatts_send_response(&pNode->gatt_conn, pNode->trans_id, OS_STATUS_SUCCESS, pNode->att_handle, &pNode->att_value);
			}
			else
			{
			    pNode->att_value.len = 1;
    			pNode->att_value.value[pNode->offset] = GATT_ERROR_INSUFFICIENT_RESOURCES;
				srv_gatts_send_response(&pNode->gatt_conn, pNode->trans_id, OS_STATUS_FAILED, pNode->att_handle, &pNode->att_value);
			}
			mmi_RemoveEntryList(&pNode->req_node);
			free_ctrl_buffer(pNode);
			pNode = pNext;
			return;
		}
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_read_txpower_callback -!\n");
}

void prxr_service_started_callback(OS_STATUS status, void *reg_ctx, ATT_HANDLE srvc_handle)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&g_prxr_cntx.srv_node->declnode);
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SERVICE_START_CB, status, g_prxr_cntx.state, g_prxr_cntx.op_flag);
	if(g_prxr_cntx.reg_ctx == reg_ctx)
	{
		if(g_prxr_cntx.state == PRX_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				if(g_prxr_cntx.op_flag == PRXR_OP_ADD_SERVICE)
				{
					if(mmi_IsListEmpty(&g_prxr_cntx.srv_list.srvlist))
					{
						//kal_prompt_trace(MOD_BT, "[PRXR] is empty service list!\n");
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_EMPTY_LIST);
						return;
					}
				
					while((ListEntry *)svc_list != &g_prxr_cntx.srv_list.srvlist)
					{
						if(svc_list->type == TYPE_SERVICE)
						{
							g_prxr_cntx.srv_node = svc_list;
							#ifndef PRXR_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
							break;
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
					if((ListEntry *)svc_list == &g_prxr_cntx.srv_list.srvlist)
					{
						g_prxr_cntx.state = PRX_STATUS_ENABLED;
						srv_gatts_listen(reg_ctx, TRUE);
					}
				}
			}
			else
			{
				prxr_deinit();
			}
		}	
		
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_service_started_callback -!\n");
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
/* under construction !*/
/* under construction !*/
#endif

void prxr_add_services_callback(OS_STATUS status, void *reg_ctx)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_prxr_cntx.srv_list.srvlist);
#if 0
/* under construction !*/
/* under construction !*/
#endif
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SERVICE_ADD_CB, status, g_prxr_cntx.state, g_prxr_cntx.op_flag);
	if(g_prxr_cntx.reg_ctx == reg_ctx)
	{
		if(g_prxr_cntx.state == PRX_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				if(g_prxr_cntx.op_flag == PRXR_OP_ADD_SERVICE)
				{
					if(mmi_IsListEmpty(&g_prxr_cntx.srv_list.srvlist))
					{
						//kal_prompt_trace(MOD_BT, "[PRXR] is empty service list!\n");
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_EMPTY_LIST);
						return;
					}
				
					while((ListEntry *)svc_list != &g_prxr_cntx.srv_list.srvlist)
					{
						if(svc_list->type == TYPE_SERVICE)
						{
							g_prxr_cntx.srv_node = svc_list;
							#ifndef PRXR_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
							break;
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
				}
			}
			else
			{
				prxr_deinit();
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_add_services_callback -!\n");
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
/* under construction !*/
/* under construction !*/
#endif

BtStatus prxr_init(prxr_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_init state %d, op_flag %d!\n", g_prxr_cntx.state, g_prxr_cntx.op_flag);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_INIT, g_prxr_cntx.state, g_prxr_cntx.op_flag);
	if(g_prxr_cntx.state == PRX_STATUS_DISABLED)
	{
		g_prxr_cntx.state = PRX_STATUS_ENABLING;
		g_prxr_cntx.op_flag = PRXR_OP_INIT;
		g_prxr_cntx.callback = cb;
		memcpy(g_prxr_cntx.uid.uu, &g_prxr_uid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_prxr_cntx.req_list);
		mmi_InitializeListHead(&g_prxr_cntx.conn_list);
		srv_gatts_profile_factory_register(&g_prxr_cntx.uid, &g_prxr_cb, &g_prxr_factory_cb);
        
        #ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, prxr_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
        #endif
	}
	else if(g_prxr_cntx.state == PRX_STATUS_DISABLING)
	{
		if(g_prxr_cntx.op_flag == PRXR_OP_DEINIT)
		{
			g_prxr_cntx.op_flag = PRXR_OP_INIT;
		}
		g_prxr_cntx.callback = cb;
		memcpy(g_prxr_cntx.uid.uu, &g_prxr_uid, sizeof(bt_uuid_struct));
	}
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_init -!\n");
	return status;
}

BtStatus prxr_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	PrxrConnCntx    *pConnCur = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
	PrxrConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_deinit state %d, op_flag %d!\n", g_prxr_cntx.state, g_prxr_cntx.op_flag);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_DEINIT, g_prxr_cntx.state, g_prxr_cntx.op_flag);
	if((g_prxr_cntx.state == PRX_STATUS_DISABLED)
		|| (g_prxr_cntx.state == PRX_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;

	if(g_prxr_cntx.state == PRX_STATUS_ENABLED)
	{
        while ((ListEntry *)pConnCur != &g_prxr_cntx.conn_list)
		{
			pConnNext = (PrxrConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_prxr_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == PRX_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == PRX_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				//srv_gatts_disconnect(&gatt_conn, &bd_addr);
			}
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}
	
	srv_gatts_profile_factory_delete_services(g_prxr_cntx.reg_ctx, &g_prxr_cntx.srv_list);
	srv_gatts_profile_factory_clear_services(g_prxr_cntx.reg_ctx, &g_prxr_cntx.srv_list);
	srv_gatts_profile_factory_deregister(g_prxr_cntx.reg_ctx);
    
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
    mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, prxr_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
#endif
    
	g_prxr_cntx.state = PRX_STATUS_DISABLED;
	g_prxr_cntx.op_flag = PRXR_OP_DEINIT;
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_deinit-!\n");
	return BT_STATUS_SUCCESS;
}

U32 prxr_send_data(void* buf, U32 len)
{
#ifdef MMI_BLE_IAS_ALERT_STATUS_CHAR
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_prxr_cntx.srv_list.srvlist);
    PrxrConnCntx        *pConnNode = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
    PrxrConnCntx        *pConnNext = NULL;
    gatt_conn_struct    gatt_conn;
    ATT_VALUE           *att_value = NULL;
    ATT_UUID            svc_uuid;
    ATT_UUID            chr_uuid;
    int                 type = 0;
    U16                 svc_uuid16 = 0;
    U16                 chr_uuid16 = 0;
    U32                 send_size = 0; 
    
	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_send_data ==> \n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SEND_DATA);

    if(buf == NULL)
    {
        return send_size;
    }
       
    if(!mmi_IsListEmpty(&g_prxr_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_prxr_cntx.conn_list)
        {
            pConnNext = (PrxrConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            
            if(pConnNode->conn_status == PRX_STATUS_CONNECTED) //CONNECTED
            {
                gatt_conn.reg_ctx = g_prxr_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while((ListEntry *)svc_list != &g_prxr_cntx.srv_list.srvlist)
                {          
                    if(svc_list->type == TYPE_CHARACTERISTIC)
                    {
                        type = prxr_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid);   
                        if(type != TYPE_CHARACTERISTIC)
                        {
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
                        
                        //kal_prompt_trace(MOD_BT, "[PRXR] prxr_send_data, svc_uuid16:0x%x, chr_uuid16:0x%x \n", svc_uuid16, chr_uuid16);
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SEND_DATA_VALUE, svc_uuid16, chr_uuid16);
                        if (chr_uuid16 == ALERT_STATUS_CHAR_UUID)
                        {  
                            send_size = len;
                            if(len > PRXR_MAX_VALUE_LEN)
                            {
                                len = PRXR_MAX_VALUE_LEN;
                            }
                             
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
                            memcpy(att_value->value, buf, len);
                            att_value->len = len;
                            srv_gatts_send_indication(&gatt_conn, svc_list->handle, FALSE, att_value);
                            free_ctrl_buffer(att_value);
                            att_value = NULL;
                            break;
                        }
                    }
                    
                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
            }
            
            pConnNode = pConnNext;
        }
    }
    
    //kal_prompt_trace(MOD_BT, "[PRXR] prxr_send_data <==, send_size:%d \n", send_size);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_SEND_DATA_SIZE, send_size);
    return  send_size;
#else //MMI_BLE_IAS_ALERT_STATUS_CHAR
    return  0;
#endif //MMI_BLE_IAS_ALERT_STATUS_CHAR
}
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
BtStatus prxr_disconnect(char *bdaddr)
{
	PrxrConnCntx    *pConnCur = (PrxrConnCntx *)mmi_GetHeadList(&g_prxr_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;

	//kal_prompt_trace(MOD_BT, "[PRXR] prxr_disconnect !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_DISCONNECT);
	if(g_prxr_cntx.state == PRX_STATUS_DISABLED
		|| g_prxr_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxr_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[PRXR] find in list conn_status %d !\n", pConnCur->conn_status);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PRXR_DISCONNECT_STATUS, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_prxr_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED
				|| pConnCur->conn_status == PRX_STATUS_CONNECTING)
			{
				pConnCur->conn_status = PRX_STATUS_DISCONNECTING;
				//pConnCur->flag = FMPL_OP_IDLE;
				srv_gatts_disconnect(&gatt_conn, &bd_addr);
				if(g_prxr_cntx.callback != NULL)
					g_prxr_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == PRX_STATUS_DISCONNECTED)
			{
				if(g_prxr_cntx.callback != NULL)
					g_prxr_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_prxr_cntx.callback != NULL)
					g_prxr_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (PrxrConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

void prxr_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret prxr_handle_cm_disconnect(mmi_event_struct *para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_le_cm_evt_disconnect_struct *evt = (srv_le_cm_evt_disconnect_struct *)para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (evt)
    {
        BD_ADDR remote_addr;
        
		prxr_get_bd_addr(&remote_addr, evt->dev_addr);
        prxr_disconnect(remote_addr.addr);
    }
    
    return MMI_RET_OK;
}
#endif

#else //MMI_SRV_BT_PRXR_PROFILE

BtStatus prxr_init(prxr_callback_t *cb)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxr_deinit()
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

#endif //MMI_SRV_BT_PRXR_PROFILE
#endif //__BT_GATTS_PROFILE__
