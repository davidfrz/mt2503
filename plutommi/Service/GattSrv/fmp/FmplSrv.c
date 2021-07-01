#ifdef __BT_GATTC_PROFILE__ 

#include "DebugInitDef_Int.h"
#include "FmplSrv.h"
#include "Fmpl_def.h"
#include "MMI_features.h"
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"
#endif

#include "MMI_conn_app_trc.h" 
#include "MMI_trc_Int.h"


#ifdef MMI_SRV_BT_FMPL_PROFILE 

void fmpl_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void fmpl_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void fmpl_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status);
void fmpl_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid);
void fmpl_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                           gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties);
void fmpl_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info);
BtStatus fmpl_disconnect(char *bdaddr);
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
mmi_ret fmpl_handle_cm_disconnect(mmi_event_struct *para);
#endif
void fmpl_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr);
void fmpl_connection_ext_callback(gattsrv_conn_struct *conn);

FmplCntx  g_fmpl_cntx = {0};
U8        g_fmpl_uid[] = {
	0xB4, 0x73, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};

/*****************************************************************
 * Immediate Alert Service (IAS) 0x1802
 *****************************************************************/
static U8 FMPL_SRV_IAS_UUID_128[] = {
    0xFB, 0x34, 0x9B, 0x5F, 0x80, 0x00, 0x00, 0x80,
    0x00, 0x10, 0x00, 0x00, 0x02, 0x18, 0x00, 0x00,
};


gattc_callback_struct g_fmpl_cb = {
	fmpl_register_callback,
    NULL,
    fmpl_connection_callback,
    NULL,
    NULL,
    fmpl_search_complete_callback,
    fmpl_search_result_callback,
    fmpl_get_characteristic_callback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    fmpl_write_characteristic_callback,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    NULL,
    fmpl_research_service_callback,
    fmpl_connection_ext_callback,
};

int  get_fmp_service_type(ATT_UUID uu)
{
	U16 uuid = 0;
	int type = -1;
	
	uuid = convert_array_to_uuid16(uu);
	switch(uuid)
	{
	case IMMEDIATE_ALERT_SERVICE:
		type = IAS_SERVICE_TYPE;
		break;
	default:
		break;
	}
	//kal_prompt_trace(MOD_BT, "[FMPL] get_fmp_service_type %d!\n", type);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_GET_SERVICE_TYPE, type);
	return type;
}

void fmpl_service_list_init(FmplConnCntx *conn)
{
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_service_list_init !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SERVICE_LIST_INIT);
	mmi_InitializeListHead(&conn->srv_info.svc_list);
}

void fmpl_service_list_deinit(FmplConnCntx *conn)
{
	FmpSvcList *pSvcNode = NULL;
	FmpSvcList *pSvcNext = NULL;
	FmpCharList *pChrNode = NULL;
	FmpCharList *pChrNext = NULL;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_service_list_deinit !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SERVICE_LIST_DEINIT);
	pSvcNode = (FmpSvcList *)mmi_GetHeadList(&conn->srv_info.svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info.svc_list)
	{
		pChrNode = (FmpCharList *)mmi_GetHeadList(&pSvcNode->char_list);
		while ((ListEntry *)pChrNode != &pSvcNode->char_list)
		{
			memset(&pChrNode->char_uuid, 0, sizeof(ATT_UUID));
			pChrNext = (FmpCharList *)mmi_GetNextNode(&pChrNode->char_node);
			mmi_RemoveEntryList(&pChrNode->char_node);
			free_ctrl_buffer(pChrNode);
			pChrNode = pChrNext;
		}
		memset(&pSvcNode->svc_uuid, 0, sizeof(GATT_SVC_UUID));
		pSvcNext = (FmpSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
		mmi_RemoveEntryList(&pSvcNode->svc_node);
		free_ctrl_buffer(pSvcNode);
		pSvcNode = pSvcNext;
	}
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_service_list_deinit -!\n");
}

void fmpl_service_uuid_add(FmplConnCntx *conn, GATT_SVC_UUID svc_uuid)
{
	int type = -1;
	FmpSvcList *pSvcNode = NULL;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_service_uuid_add !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SERVICE_ADD);
	type = get_fmp_service_type(svc_uuid.uuid);
	if(type == -1)
		return;
	
	conn->srv_info.isSupported = TRUE;
	pSvcNode = (FmpSvcList *)mmi_GetHeadList(&conn->srv_info.svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info.svc_list)
	{
		if(memcmp(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID)) == 0)
			return;

		pSvcNode = (FmpSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	pSvcNode = (FmpSvcList *)get_ctrl_buffer(sizeof(FmpSvcList));
	memcpy(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID));
	mmi_InsertTailList(&conn->srv_info.svc_list, &pSvcNode->svc_node);
	mmi_InitializeListHead(&pSvcNode->char_list);
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_service_uuid_add -!\n");
}

void fmpl_char_uuid_add(FmplConnCntx *conn, GATT_SVC_UUID svc_uuid, ATT_UUID char_uuid)
{
	int type = -1;
	FmpSvcList  *pSvcNode = NULL;
	FmpCharList *pChrNode = NULL;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_char_uuid_add !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CHAR_ADD);
	type = get_fmp_service_type(svc_uuid.uuid);
	if(type == -1)
		return;
	
	pSvcNode = (FmpSvcList *)mmi_GetHeadList(&conn->srv_info.svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info.svc_list)
	{
		if(memcmp(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID)) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find service in list !\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			goto insert_char_list;
		}

		pSvcNode = (FmpSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	pSvcNode = (FmpSvcList *)get_ctrl_buffer(sizeof(FmpSvcList));
	memcpy(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID));
	mmi_InsertTailList(&conn->srv_info.svc_list, &pSvcNode->svc_node);
	mmi_InitializeListHead(&pSvcNode->char_list);
	
insert_char_list:
	pChrNode = (FmpCharList *)mmi_GetHeadList(&pSvcNode->char_list);
	while ((ListEntry *)pChrNode != &pSvcNode->char_list)
	{
		if(memcmp(&pChrNode->char_uuid, &char_uuid, sizeof(ATT_UUID)) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find characteristic in list !\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			return;
		}

		pChrNode = (FmpCharList *)mmi_GetNextNode(&pChrNode->char_node);
	}

	pChrNode = (FmpCharList *)get_ctrl_buffer(sizeof(FmpCharList));
	memcpy(&pChrNode->char_uuid, &char_uuid, sizeof(ATT_UUID));
	mmi_InsertTailList(&pSvcNode->char_list, &pChrNode->char_node);
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_char_uuid_add -!\n");
}

BOOL fmpl_find_service_uuid(FmplConnCntx *conn, U16 uuid, GATT_SVC_UUID *svc_uuid)
{
	FmpSvcList	*pSvcNode = NULL;
	U16          uuid16 = 0;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_find_service_uuid uuid %x !\n", uuid);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_SERVICE_UUID, uuid);
	pSvcNode = (FmpSvcList *)mmi_GetHeadList(&conn->srv_info.svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info.svc_list)
	{
		uuid16 = convert_array_to_uuid16(pSvcNode->svc_uuid.uuid);
		if(uuid16 == uuid)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find service in list !\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			memcpy(svc_uuid, &pSvcNode->svc_uuid, sizeof(GATT_SVC_UUID));
			return TRUE;
		}

		pSvcNode = (FmpSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	return FALSE;
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_find_service_uuid - !\n");
}

BOOL fmpl_find_char_uuid(FmplConnCntx *conn, GATT_SVC_UUID svc_uuid, U16 uuid, ATT_UUID *char_uuid)
{
	FmpSvcList  *pSvcNode = NULL;
	FmpCharList *pChrNode = NULL;
	U16          uuid16 = 0;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_find_char_uuid uuid %x !\n", uuid);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_CHAR_UUID, uuid);
	pSvcNode = (FmpSvcList *)mmi_GetHeadList(&conn->srv_info.svc_list);
	while ((ListEntry *)pSvcNode != &conn->srv_info.svc_list)
	{
		if(memcmp(&pSvcNode->svc_uuid, &svc_uuid, sizeof(GATT_SVC_UUID)) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find service in list !\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			goto find_char_list;
		}

		pSvcNode = (FmpSvcList *)mmi_GetNextNode(&pSvcNode->svc_node);
	}

	return FALSE;
	
find_char_list:
	pChrNode = (FmpCharList *)mmi_GetHeadList(&pSvcNode->char_list);
	while ((ListEntry *)pChrNode != &pSvcNode->char_list)
	{
		uuid16 = convert_array_to_uuid16(pSvcNode->svc_uuid.uuid);
		if(uuid16 == uuid)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find characteristic in list !\n");	
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			memcpy(char_uuid, &pChrNode->char_uuid, sizeof(ATT_UUID));
			return TRUE;
		}

		pChrNode = (FmpCharList *)mmi_GetNextNode(&pChrNode->char_node);
	}
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_char_uuid_add -!\n");
	return FALSE;
}

void fmpl_register_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_register_callback status %d state %d!\n", status, g_fmpl_cntx.state);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_REGISTER_CB, status, g_fmpl_cntx.state);
	if(memcmp(app_uuid, &g_fmpl_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if(g_fmpl_cntx.state == FMP_STATUS_ENABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_fmpl_cntx.reg_ctx = reg_ctx;
				g_fmpl_cntx.state = FMP_STATUS_ENABLED;
				srv_gattc_listen(reg_ctx, TRUE);
			}
			else
			{
				g_fmpl_cntx.state = FMP_STATUS_DISABLED;
			}
		}
		else if(g_fmpl_cntx.state == FMP_STATUS_DISABLING)
		{	
			if(status == OS_STATUS_SUCCESS)
			{
				g_fmpl_cntx.reg_ctx = NULL;
				g_fmpl_cntx.callback = NULL;
				g_fmpl_cntx.state = FMP_STATUS_DISABLED;
			}
			else
			{
				g_fmpl_cntx.state = FMP_STATUS_ENABLED;
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_register_callback -!\n");
}

void fmpl_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	FmplConnCntx    *pConnNode = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	FmplConnCntx    *pConnNext = NULL;
	bt_uuid_struct 	filter_uuid;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_connection_callback connected %d!\n", connected);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONNECT_CB, connected);

	memcpy(filter_uuid.uu, &FMPL_SRV_IAS_UUID_128, sizeof(bt_uuid_struct));
		
	while ((ListEntry *)pConnNode != &g_fmpl_cntx.conn_list)
	{
		pConnNext = (FmplConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		if(memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find in list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			pConnNode->conn_ctx = conn->conn_ctx;
			if(connected)
			{
				//do next step Discovery all
				fmpl_service_list_init(pConnNode);
                if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
				srv_gattc_listen(conn->reg_ctx, FALSE);
				#if 0 //mtk06501 add for MAUI_03518227/MAUI_03518229, 20140916
/* under construction !*/
				#else
				srv_gattc_search_service(conn, &filter_uuid);
				#endif
			}
			else
			{
				srv_gattc_listen(conn->reg_ctx, TRUE);
				fmpl_service_list_deinit(pConnNode);
				mmi_RemoveEntryList(&pConnNode->conn_node);
				free_ctrl_buffer(pConnNode);
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(bd_addr->addr, FMP_STATUS_DISCONNECTED);
			}
			return;
		}
		pConnNode = pConnNext;
	}

	if(connected)
	{
		//kal_prompt_trace(MOD_BT, "[FMPL] not find in list!\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_NOT_FIND_IN_LIST);
        if (srv_ble_cm_get_connected_dev_num() >= __BT_MAX_LE_LINK_NUM__)
		srv_gattc_listen(conn->reg_ctx, FALSE);
		pConnNode = (FmplConnCntx *)get_ctrl_buffer(sizeof(FmplConnCntx));
		memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
		pConnNode->conn_ctx = conn->conn_ctx;
		pConnNode->conn_status = FMP_STATUS_CONNECTING;
		mmi_InsertTailList(&g_fmpl_cntx.conn_list, &pConnNode->conn_node);
		fmpl_service_list_init(pConnNode);

		#if 0 //mtk06501 add for MAUI_03518227/MAUI_03518229, 20140916
/* under construction !*/
		#else
		srv_gattc_search_service(conn, &filter_uuid);
		#endif
	}
}

void fmpl_connection_ext_callback(gattsrv_conn_struct *conn)
{
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_connection_ext_callback ==> \n");

    if (!conn)
    {
        return;
    }
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONNECT_EXT_CB, conn->connected, conn->is_ind);
	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_connection_ext_callback connected %d, is_ind:%d!\n", conn->connected, conn->is_ind);
}


void fmpl_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
	FmplConnCntx	*pConnNode = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_search_complete_callback status %d!\n", status);	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SEARCH_COMPLETE_CB, status);
	while ((ListEntry *)pConnNode != &g_fmpl_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find in list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
			if(status == OS_STATUS_SUCCESS)
			{
				if(pConnNode->conn_status == FMP_STATUS_CONNECTING)
				{
					pConnNode->conn_status = FMP_STATUS_CONNECTED;
					if(g_fmpl_cntx.callback != NULL)
						g_fmpl_cntx.callback->connection_state_cb(pConnNode->bdaddr, pConnNode->conn_status);
				}
			}
			else
			{
				fmpl_disconnect(pConnNode->bdaddr);
			}
			return;
		}
		pConnNode = (FmplConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
	
}

void fmpl_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *svc_uuid)
{
	FmplConnCntx    *pConnNode = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	int type = -1;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_search_result_callback !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SEARCH_RESULT_CB);
	type = get_fmp_service_type(svc_uuid->uuid);
	if(type == -1)
		return;

	while ((ListEntry *)pConnNode != &g_fmpl_cntx.conn_list)
	{
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_FIND_IN_LIST);
		//kal_prompt_trace(MOD_BT, "[FMPL] find in list !\n");
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			fmpl_service_uuid_add(pConnNode, *svc_uuid);
			return;
		}
		pConnNode = (FmplConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void fmpl_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                           gattc_char_struct *char_info, GATT_CHAR_PROPERTIES properties)
{
	
	FmplConnCntx     *pConnNode = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	ATT_VALUE         char_value;
	U16               char_uuid= convert_array_to_uuid16(*char_info->char_uuid);
	U16               svc_uuid = convert_array_to_uuid16(char_info->svc_uuid->uuid);
	int  type = -1;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_get_characteristic_callback status %d!\n", status);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_GET_CHAR_CB, status);
	while ((ListEntry *)pConnNode != &g_fmpl_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			if((char_uuid == ALERT_LEVEL_CHAR_UUID)
				&& (svc_uuid == IMMEDIATE_ALERT_SERVICE))
			{
				//kal_prompt_trace(MOD_BT, "[FMPL] is immediately service find start %d!\n", pConnNode->start);
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_IMS_FIND_START, pConnNode->start);
				if(status == OS_STATUS_SUCCESS)
				{
					if(pConnNode->start == TRUE)
					{
						memcpy(&char_value, &pConnNode->srv_info.char_value, sizeof(ATT_VALUE));
					}
					else
					{
						char_value.value[0] = FMP_ALERT_LEVEL_NO;
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
					if(g_fmpl_cntx.callback != NULL)
						g_fmpl_cntx.callback->alert_notify_cb(pConnNode->bdaddr, FALSE);
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
		pConnNode = (FmplConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void fmpl_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                            gattc_char_struct *char_info)
{
	FmplConnCntx  *pConnNode = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	int  type = -1;
	U16  uuid = 0;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_write_characteristic_callback status %d!\n", status);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CHAR_WRITE_CB, status);
	while ((ListEntry *)pConnNode != &g_fmpl_cntx.conn_list)
	{
		if(pConnNode->conn_ctx == conn->conn_ctx)
		{
			type = get_fmp_service_type(char_info->svc_uuid->uuid);
			if(type == IAS_SERVICE_TYPE)
			{
				//kal_prompt_trace(MOD_BT, "[FMPL] is immediately service write done!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_IMS_WRITE_DONE);
				uuid = convert_array_to_uuid16(*char_info->char_uuid);
				if(uuid == ALERT_LEVEL_CHAR_UUID)
				{
					if(status == OS_STATUS_SUCCESS)
					{
						if(g_fmpl_cntx.callback != NULL)
							g_fmpl_cntx.callback->alert_notify_cb(pConnNode->bdaddr, TRUE);
					}
					else
					{
						if(g_fmpl_cntx.callback != NULL)
							g_fmpl_cntx.callback->alert_notify_cb(pConnNode->bdaddr, FALSE);
					}
				}
			}
			break;
		}
		pConnNode = (FmplConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

BtStatus fmpl_init(fmpl_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_init state %d!\n", g_fmpl_cntx.state);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_INIT, g_fmpl_cntx.state);
	if(g_fmpl_cntx.state == FMP_STATUS_DISABLED)
	{
		g_fmpl_cntx.state = FMP_STATUS_ENABLING;
		g_fmpl_cntx.callback = cb;
		memcpy(g_fmpl_cntx.uid.uu, &g_fmpl_uid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_fmpl_cntx.conn_list);
		srv_gattc_register(&g_fmpl_cntx.uid, &g_fmpl_cb);
        
        #ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
        mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, fmpl_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
        #endif
	}
	else if(g_fmpl_cntx.state == FMP_STATUS_DISABLING)
	{
		status = BT_STATUS_FAILED;
	}
	
	return status;
}

BtStatus fmpl_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	FmplConnCntx    *pConnCur = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	FmplConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_deinit state %d!\n", g_fmpl_cntx.state);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_DEINIT, g_fmpl_cntx.state);
	if((g_fmpl_cntx.state == FMP_STATUS_DISABLED)
		|| (g_fmpl_cntx.state == FMP_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;
	
	if(g_fmpl_cntx.state == FMP_STATUS_ENABLED)
	{
        while ((ListEntry *)pConnCur != &g_fmpl_cntx.conn_list)
		{
			pConnNext = (FmplConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_fmpl_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == FMP_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == FMP_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				//srv_gattc_disconnect(&gatt_conn, &bd_addr);
			}
			fmpl_service_list_deinit(pConnCur);
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}

	srv_gattc_deregister(g_fmpl_cntx.reg_ctx);
    
#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
    mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, fmpl_handle_cm_disconnect, NULL); //listen CM disconnect req, 20141125
#endif
	g_fmpl_cntx.state = FMP_STATUS_DISABLED;
	return BT_STATUS_SUCCESS;
}

BtStatus fmpl_connect(char *bdaddr)
{
	FmplConnCntx *pConnCur = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	BD_ADDR       bd_addr;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_connect !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONN_REQ);
	if(g_fmpl_cntx.state == FMP_STATUS_DISABLED
		|| g_fmpl_cntx.state == FMP_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_fmpl_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find in list conn_status %d !\n", pConnCur->conn_status);	
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONN_STATUS, pConnCur->conn_status);
			if(pConnCur->conn_status == FMP_STATUS_DISCONNECTED
				|| pConnCur->conn_status == FMP_STATUS_DISCONNECTING)
			{
				pConnCur->conn_status = FMP_STATUS_CONNECTING;
				srv_gattc_connect(g_fmpl_cntx.reg_ctx, &bd_addr, TRUE);
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);

				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == FMP_STATUS_CONNECTED)
			{
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
		}
		pConnCur = (FmplConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_NOT_FIND_IN_LIST);
	//kal_prompt_trace(MOD_BT, "[FMPL] not find in list!\n");
	pConnCur = (FmplConnCntx *)get_ctrl_buffer(sizeof(FmplConnCntx));
	memset(pConnCur, 0, sizeof(FmplConnCntx));
	memcpy(pConnCur->bdaddr, bdaddr, BD_ADDR_SIZE);
	mmi_InsertTailList(&g_fmpl_cntx.conn_list, &pConnCur->conn_node);
	pConnCur->conn_status = FMP_STATUS_CONNECTING;
	srv_gattc_connect(g_fmpl_cntx.reg_ctx, &bd_addr, TRUE);
	if(g_fmpl_cntx.callback != NULL)
		g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);

	return BT_STATUS_PENDING;
}

BtStatus fmpl_disconnect(char *bdaddr)
{
	FmplConnCntx    *pConnCur = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_disconnect !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_DISCONN_REQ);
	if(g_fmpl_cntx.state == FMP_STATUS_DISABLED
		|| g_fmpl_cntx.state == FMP_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_fmpl_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] find in list conn_status %d !\n", pConnCur->conn_status);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_DISCONN_STATUS, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_fmpl_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == FMP_STATUS_CONNECTED
				|| pConnCur->conn_status == FMP_STATUS_CONNECTING)
			{
				pConnCur->conn_status = FMP_STATUS_DISCONNECTING;
				srv_gattc_disconnect(&gatt_conn, &bd_addr);
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			else if(pConnCur->conn_status == FMP_STATUS_DISCONNECTED)
			{
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_SUCCESS;
			}
			else
			{
				if(g_fmpl_cntx.callback != NULL)
					g_fmpl_cntx.callback->connection_state_cb(pConnCur->bdaddr, pConnCur->conn_status);
				return BT_STATUS_PENDING;
			}
			break;
		}
		pConnCur = (FmplConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus fmpl_configAlertLevel(char *bdaddr, U8 level)
{
	FmplConnCntx    *pConnCur = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_configAlertLevel level %d!\n", level);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONFIG_ALERT_LEVEL, level);
	if(g_fmpl_cntx.state == FMP_STATUS_DISABLED
		|| g_fmpl_cntx.state == FMP_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_fmpl_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[FMPL] conn_status %d!\n", pConnCur->conn_status);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_CONN_STATUS, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_fmpl_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if(pConnCur->conn_status == FMP_STATUS_CONNECTED)
			{
				if(pConnCur->srv_info.isSupported)
				{
					memset(&pConnCur->srv_info.char_value, 0, sizeof(ATT_VALUE));
					pConnCur->srv_info.char_value.value[0] = level;
					pConnCur->srv_info.char_value.len = sizeof(level);
					return BT_STATUS_SUCCESS;
				}
			}
			break;
		}
		pConnCur = (FmplConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

BtStatus fmpl_alert(char *bdaddr, BOOL start)
{
	FmplConnCntx    *pConnCur = (FmplConnCntx *)mmi_GetHeadList(&g_fmpl_cntx.conn_list);
	gatt_conn_struct gatt_conn;
	BD_ADDR 		 bd_addr;
	FmpSvcList *pSvcNode = NULL;
	BOOL        ret = FALSE;

	//kal_prompt_trace(MOD_BT, "[FMPL] fmpl_alert state %d level %d!\n", g_fmpl_cntx.state, start);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_ALERT, g_fmpl_cntx.state, start);
	if(g_fmpl_cntx.state == FMP_STATUS_DISABLED
		|| g_fmpl_cntx.state == FMP_STATUS_DISABLING)
		return BT_STATUS_FAILED;

	memcpy(bd_addr.addr, bdaddr, BD_ADDR_SIZE);
	while ((ListEntry *)pConnCur != &g_fmpl_cntx.conn_list)
	{
		if(memcmp(bdaddr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
		{
			gatt_conn.reg_ctx = g_fmpl_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			//kal_prompt_trace(MOD_BT, "[FMPL] conn_status %d  isSupported %d !\n", pConnCur->conn_status, pConnCur->srv_info.isSupported);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_ALERT_CONN_STATUS, pConnCur->conn_status, pConnCur->srv_info.isSupported);

			if((pConnCur->conn_status == FMP_STATUS_CONNECTED) && (pConnCur->srv_info.isSupported == TRUE))
			{
				GATT_SVC_UUID     svc_uuid;

				if((ret = fmpl_find_service_uuid(pConnCur, IMMEDIATE_ALERT_SERVICE, &svc_uuid)) == TRUE)
				{
					pConnCur->start = start;
					srv_gattc_get_characteristic(&gatt_conn, &svc_uuid, NULL);
					return BT_STATUS_PENDING;
				}
				else
				{
				    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_NOT_FIND_IN_LIST);
					//kal_prompt_trace(MOD_BT, "[FMPL] doesn't find immediate alert service !\n");
					return BT_STATUS_FAILED;
				}
			}
			break;
		}
		pConnCur = (FmplConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}

	return BT_STATUS_FAILED;
}

//service change callback test---------------------------------Start
void fmpl_research_service_callback(gatt_conn_struct *conn, OS_STATUS status, BD_ADDR *bd_addr)
{
	bt_uuid_struct 	filter_uuid;
    
    //kal_prompt_trace(MOD_BT, "[FMPL] fmpl_research_service_callback ==> ");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_FMPL_SERVICE_RESEARCH_CB);
	memcpy(filter_uuid.uu, &FMPL_SRV_IAS_UUID_128, sizeof(bt_uuid_struct));

    srv_gattc_search_service(conn, &filter_uuid);
}
//service change callback test---------------------------------End

#ifdef __MMI_BLE_FMP_LISTEN_CM_EVT__
void fmpl_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret fmpl_handle_cm_disconnect(mmi_event_struct *para)
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
        
        fmpl_get_bd_addr(&remote_addr, evt->dev_addr);
        fmpl_disconnect(remote_addr.addr);
    }
    
    return MMI_RET_OK;
}
#endif

#else //MMI_SRV_BT_FMPL_PROFILE
BtStatus fmpl_init(fmpl_callback_t *cb)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}

BtStatus fmpl_deinit()
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


BtStatus fmpl_connect(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


BtStatus fmpl_disconnect(char *bdaddr)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


BtStatus fmpl_configAlertLevel(char *bdaddr, U8 level)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


BtStatus fmpl_alert(char *bdaddr, BOOL start)
{
    BtStatus status = BT_STATUS_SUCCESS;
    
    return status;
}


#endif //MMI_SRV_BT_FMPL_PROFILE
#endif //__BT_GATTC_PROFILE__

