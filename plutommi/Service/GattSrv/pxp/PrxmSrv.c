#ifdef __BT_GATTC_PROFILE__ 

#include "PrxmSrv.h"
#include "Prxm_def.h"
#include "MMI_features.h"
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"
#endif

#ifdef MMI_SRV_BT_PRXM_PROFILE 

void prxm_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void prxm_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void prxm_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status);
void prxm_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid);
void prxm_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                           gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties);
void prxm_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info, ATT_VALUE *value);
void prxm_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                             gattc_char_struct *char_info);
void prxm_read_remote_rssi_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi);
BtStatus prxm_disconnect(char *bdaddr);
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
mmi_ret prxm_handle_cm_disconnect(mmi_event_struct *para);
#endif
void prxm_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);
void prxm_connection_ext_callback(gattsrv_conn_struct *conn);

PrxmCntx  g_prxm_cntx = {0};
U8        g_prxm_uid[] = {
	0xB3, 0x72, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};

/*****************************************************************
 * Immediate Alert Service (IAS) 0x1802
 *****************************************************************/
static U8 PRXM_SRV_IAS_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x02, 0x18, 0x00, 0x00,
};

/*****************************************************************
 * Link Loss Service (LLS) 0x1803
 *****************************************************************/
static U8 PRXM_SRV_LLS_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x03, 0x18, 0x00, 0x00,
};

/*****************************************************************
 * Tx Power Service (TPS) 0x1804
 *****************************************************************/
static U8 PRXM_SRV_TPS_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x04, 0x18, 0x00, 0x00,
};

gattc_callback_struct g_prxm_cb = {
	prxm_register_callback,
    NULL,
    prxm_connection_callback,
    NULL,
    NULL,
    prxm_search_complete_callback,
    prxm_search_result_callback,
    prxm_get_characteristic_callback,
    NULL,
    NULL,
    NULL,
    NULL,
    prxm_read_characteristic_callback,
    prxm_write_characteristic_callback,
    NULL,
    NULL,
    NULL,
    prxm_read_remote_rssi_callback,
    NULL,
    NULL,
    prxm_research_service_callback,
    prxm_connection_ext_callback,
};

int  get_prxm_service_type(ATT_UUID uu)
{
	U16 uuid = 0;
	int type = -1;
	
	uuid = convert_array_to_uuid16(uu);
	switch(uuid)
	{
	case LINK_LOSS_SERVICE:
		type = LLS_SERVICE_TYPE;
		break;
	case TX_POWER_SERVICE:
		type = TPS_SERVICE_TYPE;
		break;
	case IMMEDIATE_ALERT_SERVICE:
		type = IAS_SERVICE_TYPE;
		break;
	default:
		break;
	}
	return type;
}

void prxm_service_list_init(PrxmConnCntx *conn)
{
	int i = 0;

	for(i = 0; i < PRX_SERVICE_NUM; i++)
	{
		mmi_InitializeListHead(&conn->srv_info[i].svc_list);
	}
}

void prxm_service_list_deinit(PrxmConnCntx *conn)
{
	int i = 0;
	PrxSvcList *pSvcNode = NULL;
	PrxSvcList *pSvcNext = NULL;
	PrxCharList *pChrNode = NULL;
	PrxCharList *pChrNext = NULL;
	
	for(i = 0; i < PRX_SERVICE_NUM; i++)
	{
		pSvcNode = (PrxSvcList *)mmi_GetHeadList(&conn->srv_info[i].svc_list);
		while ((ListEntry *)pSvcNode != &conn->srv_info[i].svc_list)
		{
			pChrNode = (PrxCharList *)mmi_GetHeadList(&pSvcNode->char_list);
			while ((ListEntry *)pChrNode != &pSvcNode->char_list)
			{
				memset(&pChrNode->char_uuid, 0, sizeof(ATT_UUID));
				pChrNext = (PrxCharList *)mmi_GetNextNode(&pChrNode->char_node);
				mmi_RemoveEntryList(&pChrNode->char_node);
				free_ctrl_buffer(pChrNode);
				pChrNode = pChrNext;
			}
			memset(&pSvcNode->svc_uuid, 0, sizeof(GATT_SVC_UUID));
			pSvcNext = (PrxSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
			mmi_RemoveEntryList(&pSvcNode->svc_node);
			free_ctrl_buffer(pSvcNode);
			pSvcNode = pSvcNext;
		}
	}
}

void prxm_service_uuid_add(PrxmConnCntx *conn, GATT_SVC_UUID svc_uuid)
{
	int type = -1;
	PrxSvcList *pSvcNode = NULL;
	
	type = get_prxm_service_type(svc_uuid.uuid);
	if(type == -1)
		return;
	
	conn->srv_info[type].isSupported = TRUE;
	pSvcNode = (PrxSvcList *)mmi_GetHeadList(&conn->srv_info[type].svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info[type].svc_list)
	{
		if(memcmp(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID)) == 0)
			return;

		pSvcNode = (PrxSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	pSvcNode = (PrxSvcList *)get_ctrl_buffer(sizeof(PrxSvcList));
	memcpy(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID));
	mmi_InsertTailList(&conn->srv_info[type].svc_list, &pSvcNode->svc_node);
	mmi_InitializeListHead(&pSvcNode->char_list);
}

void prxm_char_uuid_add(PrxmConnCntx *conn, GATT_SVC_UUID svc_uuid, ATT_UUID char_uuid)
{
	int type = -1;
	PrxSvcList  *pSvcNode = NULL;
	PrxCharList *pChrNode = NULL;
	
	type = get_prxm_service_type(svc_uuid.uuid);
	if(type == -1)
		return;
	
	pSvcNode = (PrxSvcList *)mmi_GetHeadList(&conn->srv_info[type].svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info[type].svc_list)
	{
		if(memcmp(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID)) == 0)
			goto insert_char_list;

		pSvcNode = (PrxSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	pSvcNode = (PrxSvcList *)get_ctrl_buffer(sizeof(PrxSvcList));
	memcpy(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID));
	mmi_InsertTailList(&conn->srv_info[type].svc_list, &pSvcNode->svc_node);
	mmi_InitializeListHead(&pSvcNode->char_list);
	
insert_char_list:
	pChrNode = (PrxCharList *)mmi_GetHeadList(&pSvcNode->char_list);
	while ((ListEntry *)pChrNode != &pSvcNode->char_list)
	{
		if(memcmp(&pChrNode->char_uuid, &char_uuid, sizeof(ATT_UUID)) == 0)
			return;

		pChrNode = (PrxCharList *)mmi_GetNextNode(&pChrNode->char_node);
	}

	pChrNode = (PrxCharList *)get_ctrl_buffer(sizeof(PrxCharList));
	memcpy(&pChrNode->char_uuid, &char_uuid, sizeof(ATT_UUID));
	mmi_InsertTailList(&pSvcNode->char_list, &pChrNode->char_node);
}


void prxm_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	if(memcmp(app_uuid, &g_prxm_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if(g_prxm_cntx.state == PRX_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_prxm_cntx.reg_ctx = reg_ctx;
				g_prxm_cntx.state = PRX_STATUS_ENABLED;
			}
			else
			{
				g_prxm_cntx.state = PRX_STATUS_DISABLED;
			}
		}
		else if(g_prxm_cntx.state == PRX_STATUS_DISABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_prxm_cntx.reg_ctx = NULL;
				g_prxm_cntx.callback = NULL;
				g_prxm_cntx.state = PRX_STATUS_DISABLED;
			}
			else
			{
				g_prxm_cntx.state = PRX_STATUS_ENABLED;
			}
		}
	}
}

void prxm_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	PrxmConnCntx    *pConnNext = NULL;
	bt_uuid_struct 	filter_uuid;


	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		pConnNext = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			pConnNode->conn_ctx = conn->conn_ctx;
			if(connected)
			{
				//do next step Discovery all
				pConnNode->conn_status = PRX_STATUS_CONNECTING;
				prxm_service_list_init(pConnNode);
				
				#if 0 //mtk06501 add for MAUI_03518227/MAUI_03518229, 20140916
/* under construction !*/
				#else
				memcpy(filter_uuid.uu, &PRXM_SRV_IAS_UUID_128, sizeof(bt_uuid_struct));
				srv_gattc_search_service(conn, &filter_uuid);
				
				memcpy(filter_uuid.uu, &PRXM_SRV_LLS_UUID_128, sizeof(bt_uuid_struct));
				srv_gattc_search_service(conn, &filter_uuid);
				
				memcpy(filter_uuid.uu, &PRXM_SRV_TPS_UUID_128, sizeof(bt_uuid_struct));
				srv_gattc_search_service(conn, &filter_uuid);
				#endif		
			}
			else
			{
				prxm_service_list_deinit(pConnNode);
				mmi_RemoveEntryList(&pConnNode->conn_node);
				free_ctrl_buffer(pConnNode);
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(bd_addr->addr, PRX_STATUS_DISCONNECTED);
			}
			return;
		}
		pConnNode = pConnNext;
	}

	if(connected)
	{
		pConnNode = (PrxmConnCntx *)get_ctrl_buffer(sizeof(PrxmConnCntx));
		memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
		pConnNode->conn_ctx = conn->conn_ctx;
		pConnNode->conn_status = PRX_STATUS_CONNECTING;
		mmi_InsertTailList(&g_prxm_cntx.conn_list, &pConnNode->conn_node);
		prxm_service_list_init(pConnNode);

#if 0 //mtk06501 add for MAUI_03518227/MAUI_03518229, 20140916
/* under construction !*/
#else
		memcpy(filter_uuid.uu, &PRXM_SRV_IAS_UUID_128, sizeof(bt_uuid_struct));
		srv_gattc_search_service(conn, &filter_uuid);
		
		memcpy(filter_uuid.uu, &PRXM_SRV_LLS_UUID_128, sizeof(bt_uuid_struct));
		srv_gattc_search_service(conn, &filter_uuid);
		
		memcpy(filter_uuid.uu, &PRXM_SRV_TPS_UUID_128, sizeof(bt_uuid_struct));
		srv_gattc_search_service(conn, &filter_uuid);
#endif		
	}
}

void prxm_connection_ext_callback(gattsrv_conn_struct *conn)
{
	kal_prompt_trace(MOD_BT, "[PRXM] prxm_connection_ext_callback ==> \n");

    if (!conn)
    {
        return;
    }

	kal_prompt_trace(MOD_BT, "[PRXM] prxm_connection_ext_callback connected %d, is_ind:%d!\n", conn->connected, conn->is_ind);
}

void prxm_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	
	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			if(status == OS_STATUS_SUCCESS)
			{
				if(pConnNode->conn_status == PRX_STATUS_CONNECTING)
				{
					pConnNode->conn_status = PRX_STATUS_CONNECTED;
					if(g_prxm_cntx.callback != NULL)
						g_prxm_cntx.callback->connection_state_cb(pConnNode->bdaddr, pConnNode->conn_status);
				}
			}
			else
			{
				prxm_disconnect(pConnNode->bdaddr);
			}
			return;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void prxm_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	int type = -1;

	type = get_prxm_service_type(svc_uuid->uuid);
	if(type == -1)
		return;

	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			prxm_service_uuid_add(pConnNode, *svc_uuid);
			return;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void prxm_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status, 
										   gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gattc_char_struct prxm_char;
	ATT_UUID          uuid;
	ATT_VALUE         char_value;
	int  type = -1;
	
	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			type = get_prxm_service_type(char_info->svc_uuid->uuid);
			if(((pConnNode->flag & PRXM_OP_WRITE_LLS_CHAR) == PRXM_OP_WRITE_LLS_CHAR)
				&& (type == LLS_SERVICE_TYPE))
			{
				if(status == OS_STATUS_SUCCESS)
				{
					srv_gattc_write_characteristic(conn, 
								                   char_info, 
								                   &pConnNode->srv_info[type].char_value,
								                   GATTC_WRITE_TYPE_REQUEST,
								                   GATTC_AUTH_REQ_NONE);
				}
				else
				{
					pConnNode->flag &= ~PRXM_OP_WRITE_LLS_CHAR; 
					if(g_prxm_cntx.callback != NULL)
						g_prxm_cntx.callback->config_level_cb(pConnNode->bdaddr, FALSE);
				}
			}
			else if(((pConnNode->flag & PRXM_OP_READ_TPS_CHAR) == PRXM_OP_READ_TPS_CHAR)
				    && (type == TPS_SERVICE_TYPE))
			{
				if(status == OS_STATUS_SUCCESS)
				{
					srv_gattc_read_characteristic(conn, 
								                  char_info, 
								                  GATTC_AUTH_REQ_NONE);
				}
				else
				{
					pConnNode->flag &= ~PRXM_OP_READ_TPS_CHAR; 
					if(g_prxm_cntx.callback != NULL)
						g_prxm_cntx.callback->read_txpower_cb(pConnNode->bdaddr, 0, FALSE);
				}
			}
			else if(((pConnNode->flag & PRXM_OP_WRITE_IAS_CHAR) == PRXM_OP_WRITE_IAS_CHAR)
				    && (type == IAS_SERVICE_TYPE))
			{
				if(status == OS_STATUS_SUCCESS)
				{
					if(pConnNode->start == TRUE)
					{
						memcpy(&char_value, &pConnNode->srv_info[type].char_value, sizeof(ATT_VALUE));
					}
					else
					{
						char_value.value[0] = PRX_ALERT_LEVEL_NO;
						char_value.len = 1;
					}
					srv_gattc_write_characteristic(conn, 
								                   char_info, 
								                   &char_value,
								                   GATTC_WRITE_TYPE_NO_RSP,
								                   GATTC_AUTH_REQ_NONE);
				}
				else
				{
					pConnNode->flag &= ~PRXM_OP_WRITE_IAS_CHAR; 
					if(g_prxm_cntx.callback != NULL)
						g_prxm_cntx.callback->alert_notify_cb(pConnNode->bdaddr, FALSE);
				}
			}
			else
			{
				if(status == OS_STATUS_SUCCESS)
				{
					srv_gattc_get_characteristic(conn, char_info->svc_uuid, char_info->char_uuid);
				}
			}
			break;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void prxm_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info, ATT_VALUE *value)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	int  type = -1;
	U16  uuid = 0;
	S32  txpower = 0;
	int  i = 0;
	
	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			type = get_prxm_service_type(char_info->svc_uuid->uuid);
			if(((pConnNode->flag & PRXM_OP_READ_TPS_CHAR) == PRXM_OP_READ_TPS_CHAR)
			   && (type == TPS_SERVICE_TYPE))
			{
				uuid = convert_array_to_uuid16(*char_info->char_uuid);
				if(uuid == TX_POWER_CHAR_UUID)
				{
					pConnNode->flag &= ~PRXM_OP_READ_TPS_CHAR;
					if(status == OS_STATUS_SUCCESS)
					{
						for(i = 0; i < value->len; i ++)
						{
							txpower |= ((S32)value->value[i])<<((value->len-i-1)*8);
						}
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->read_txpower_cb(pConnNode->bdaddr, txpower, TRUE);
					}
					else
					{
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->read_txpower_cb(pConnNode->bdaddr, txpower, FALSE);
					}
				}
			}
			break;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void prxm_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	int  type = -1;
	U16  uuid = 0;
	int  txpower = 0;
	int  i = 0;
	
	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			type = get_prxm_service_type(char_info->svc_uuid->uuid);
			if(((pConnNode->flag & PRXM_OP_WRITE_LLS_CHAR) == PRXM_OP_WRITE_LLS_CHAR)
					&& (type == LLS_SERVICE_TYPE))
			{
				uuid = convert_array_to_uuid16(*char_info->char_uuid);
				if(uuid == ALERT_LEVEL_CHAR_UUID)
				{
					pConnNode->flag &= ~PRXM_OP_WRITE_LLS_CHAR;
					if(status == OS_STATUS_SUCCESS)
					{
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->config_level_cb(pConnNode->bdaddr, TRUE);
					}
					else
					{
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->config_level_cb(pConnNode->bdaddr, FALSE);
					}
				}
			}
			else if(((pConnNode->flag & PRXM_OP_WRITE_IAS_CHAR) == PRXM_OP_WRITE_IAS_CHAR)
					&& (type == IAS_SERVICE_TYPE))
			{
				uuid = convert_array_to_uuid16(*char_info->char_uuid);
				if(uuid == ALERT_LEVEL_CHAR_UUID)
				{
					pConnNode->flag &= ~PRXM_OP_WRITE_IAS_CHAR;
					if(status == OS_STATUS_SUCCESS)
					{
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->alert_notify_cb(pConnNode->bdaddr, TRUE);
					}
					else
					{
						if(g_prxm_cntx.callback != NULL)
							g_prxm_cntx.callback->alert_notify_cb(pConnNode->bdaddr, FALSE);
					}
				}
			}
			break;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void prxm_read_remote_rssi_callback(void *reg_ctx, OS_STATUS status, BD_ADDR *bd_addr, S32 rssi)
{
	PrxmConnCntx    *pConnNode = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	
	while ((ListEntry *)pConnNode != &g_prxm_cntx.conn_list)
	{
		if(memcmp(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE) == 0)
		{
			if(status == OS_STATUS_SUCCESS)
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->read_rssi_cb(pConnNode->bdaddr, rssi, TRUE);
			}
			else
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->read_txpower_cb(pConnNode->bdaddr, rssi, FALSE);
			}
			break;
		}
		pConnNode = (PrxmConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}



BtStatus prxm_init(prxm_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED)
	{
		g_prxm_cntx.state = PRX_STATUS_ENABLING;
		g_prxm_cntx.callback = cb;
		memcpy(g_prxm_cntx.uid.uu, &g_prxm_uid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_prxm_cntx.conn_list);
		srv_gattc_register(&g_prxm_cntx.uid, &g_prxm_cb);
        #ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, prxm_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
        #endif
	}
	else if(g_prxm_cntx.state == PRX_STATUS_DISABLING)
	{
		status = BT_STATUS_FAILED;
	}
	
	return status;
}

BtStatus prxm_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	PrxmConnCntx    *pConnNext = NULL;
	
	if((g_prxm_cntx.state == PRX_STATUS_DISABLED)
		|| (g_prxm_cntx.state == PRX_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;
	
	if(g_prxm_cntx.state == PRX_STATUS_ENABLED)
	{
        while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
		{
			pConnNext = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == PRX_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == PRX_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				//srv_gattc_disconnect(&gatt_conn, &bd_addr);
			}
			prxm_service_list_deinit(pConnCur);
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}

	srv_gattc_deregister(g_prxm_cntx.reg_ctx);
    
#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
    mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, prxm_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
#endif
    
	g_prxm_cntx.state = PRX_STATUS_DISABLED;
	return BT_STATUS_SUCCESS;
}

BtStatus prxm_connect(char *bdaddr)
{
	PrxmConnCntx *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	BD_ADDR       bd_addr;
	int           i = 0;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			if(pConnCur->conn_status == PRX_STATUS_DISCONNECTED
				|| pConnCur->conn_status == PRX_STATUS_DISCONNECTING)
			{
				pConnCur->flag = PRXM_OP_IDLE;
				pConnCur->conn_status = PRX_STATUS_CONNECTING;
				srv_gattc_connect(g_prxm_cntx.reg_ctx, &bd_addr, TRUE);
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);

				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == PRX_STATUS_CONNECTED)
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	pConnCur = (PrxmConnCntx *)get_ctrl_buffer(sizeof(PrxmConnCntx));
	memset(pConnCur, 0, sizeof(PrxmConnCntx));
	pConnCur->flag = PRXM_OP_IDLE;
	memcpy(pConnCur->bdaddr, bdaddr, BD_ADDR_SIZE);
	mmi_InsertTailList(&g_prxm_cntx.conn_list, &pConnCur->conn_node);
	pConnCur->conn_status = PRX_STATUS_CONNECTING;
	srv_gattc_connect(g_prxm_cntx.reg_ctx, &bd_addr, TRUE);
	if(g_prxm_cntx.callback != NULL)
		g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);

	return BT_STATUS_PENDING;
}

BtStatus prxm_disconnect(char *bdaddr)
{
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED
				|| pConnCur->conn_status == PRX_STATUS_CONNECTING)
			{
				pConnCur->conn_status = PRX_STATUS_DISCONNECTING;
				pConnCur->flag = PRXM_OP_IDLE;
				srv_gattc_disconnect(&gatt_conn, &bd_addr);
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == PRX_STATUS_DISCONNECTED)
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_prxm_cntx.callback != NULL)
					g_prxm_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus prxm_configAlertLevel(char *bdaddr, int type, U8 level)
{
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED)
			{
				if(pConnCur->srv_info[type].isSupported)
				{
					gattc_char_struct char_info;
					ATT_UUID          uuid;
					
					pConnCur->srv_info[type].char_value.value[0] = level;
					pConnCur->srv_info[type].char_value.len = sizeof(level);
					switch(type)
					{
					case LLS_SERVICE_TYPE:
						pConnCur->flag |= PRXM_OP_WRITE_LLS_CHAR;
						memset(&char_info, 0, sizeof(gattc_char_struct));
						convert_uuid16_to_array(LINK_LOSS_SERVICE, &uuid);
						uuid.inst = 0;
						memcpy(&char_info.svc_uuid->uuid, &uuid, sizeof(ATT_UUID));
						char_info.svc_uuid->is_primary = 1;
						memset(&char_info.char_uuid, 0, sizeof(ATT_UUID));
						srv_gattc_get_characteristic(&gatt_conn, char_info.svc_uuid, char_info.char_uuid);
						break;
					case IAS_SERVICE_TYPE:
						return BT_STATUS_SUCCESS;
					default:
						break;
					}
					return BT_STATUS_PENDING;
				}
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus prxm_alert(char *bdaddr, BOOL start)
{
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR 		 bd_addr;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED)
			{
				if(pConnCur->srv_info[IAS_SERVICE_TYPE].isSupported)
				{
					gattc_char_struct char_info;
					ATT_UUID          uuid;

					pConnCur->start = start;
					pConnCur->flag |= PRXM_OP_WRITE_IAS_CHAR;
					memset(&char_info, 0, sizeof(gattc_char_struct));
					convert_uuid16_to_array(IMMEDIATE_ALERT_SERVICE, &uuid);
					uuid.inst = 0;
					memcpy(&char_info.svc_uuid->uuid, &uuid, sizeof(ATT_UUID));
					char_info.svc_uuid->is_primary = 1;
					memset(&char_info.char_uuid, 0, sizeof(ATT_UUID));
					srv_gattc_get_characteristic(&gatt_conn, char_info.svc_uuid, char_info.char_uuid);
					return BT_STATUS_PENDING;
				}
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus prxm_readTxPower(char *bdaddr)
{
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR 		 bd_addr;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED)
			{
				if(pConnCur->srv_info[TPS_SERVICE_TYPE].isSupported)
				{
					gattc_char_struct char_info;
					ATT_UUID          uuid;

					pConnCur->flag |= PRXM_OP_READ_TPS_CHAR;
					memset(&char_info, 0, sizeof(gattc_char_struct));
					convert_uuid16_to_array(TX_POWER_SERVICE, &uuid);
					uuid.inst = 0;
					memcpy(&char_info.svc_uuid->uuid, &uuid, sizeof(ATT_UUID));
					char_info.svc_uuid->is_primary = 1;
					memset(&char_info.char_uuid, 0, sizeof(ATT_UUID));
					srv_gattc_get_characteristic(&gatt_conn, char_info.svc_uuid, char_info.char_uuid);
					return BT_STATUS_PENDING;
				}
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus prxm_readRssi(char *bdaddr)
{
	PrxmConnCntx    *pConnCur = (PrxmConnCntx *)mmi_GetHeadList(&g_prxm_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR 		 bd_addr;
	
	if(g_prxm_cntx.state == PRX_STATUS_DISABLED
		|| g_prxm_cntx.state == PRX_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_prxm_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_prxm_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == PRX_STATUS_CONNECTED)
			{
				srv_gattc_read_remote_rssi(pConnCur->conn_ctx, &bd_addr);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (PrxmConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

//service change callback test---------------------------------Start
void prxm_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr)
{
	bt_uuid_struct 	filter_uuid;
    
    kal_prompt_trace(MOD_BT, "[PRXR] prxm_research_service_callback ==> ");

    memcpy(filter_uuid.uu, &PRXM_SRV_IAS_UUID_128, sizeof(bt_uuid_struct));
    srv_gattc_search_service(conn, &filter_uuid);
    
    memcpy(filter_uuid.uu, &PRXM_SRV_LLS_UUID_128, sizeof(bt_uuid_struct));
    srv_gattc_search_service(conn, &filter_uuid);
    
    memcpy(filter_uuid.uu, &PRXM_SRV_TPS_UUID_128, sizeof(bt_uuid_struct));
    srv_gattc_search_service(conn, &filter_uuid);
}
//service change callback test---------------------------------End


#ifdef __MMI_BLE_PXP_LISTEN_CM_EVT__
void prxm_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret prxm_handle_cm_disconnect(mmi_event_struct *para)
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
        
		prxm_get_bd_addr(&remote_addr, evt->dev_addr);
        prxm_disconnect(remote_addr.addr);
    }

    return MMI_RET_OK;
}
#endif

#else //MMI_SRV_BT_PRXM_PROFILE

BtStatus prxm_init(prxm_callback_t *cb)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_deinit()
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_connect(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_disconnect(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_configAlertLevel(char *bdaddr, int type, U8 level)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_alert(char *bdaddr, BOOL start)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_readTxPower(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus prxm_readRssi(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

#endif //MMI_SRV_BT_PRXM_PROFILE
#endif //__BT_GATTC_PROFILE__
