#include "MMI_features.h"

#ifdef __MMI_BLE_DOGP_SUPPORT__ 

#include "DebugInitDef_Int.h"
#include "SogpsSrv.h"
#include "Sogps_def.h"
#include "Kal_trace.h"
#include "MMI_conn_app_trc.h"

/*add for low power*/
#ifdef __MMI_BLE_LOW_POWER__
#include "mmi_rp_srv_sogps_def.h"
#include "GattcSrv.h"
#endif

#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "blesrvgprot.h" // srv_ble_cm_get_connected_dev_num

static BtStatus sogps_disconnect_event_handler(BD_ADDR *bdaddr);
static void sogps_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src);
static mmi_ret sogps_recv_event_handler(mmi_event_struct *evt);

/** BT-GATT Server callback structure. */
void sogps_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid);
void sogps_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr);
void sogps_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                       ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                       BOOL need_rsp, BOOL is_prep);
void sogps_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long);

void sogps_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle);

//void sogps_get_services_callback(OS_STATUS status, void *reg_ctx);
void sogps_add_services_callback(OS_STATUS status, void *reg_ctx);
//void sogps_delete_services_callback(OS_STATUS status, void *reg_ctx);
BtStatus sogps_init(sogps_callback_t *cb);
BtStatus sogps_deinit();

void sogps_request_exec_write_callback(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel);


//#define SOGPS_MAX_VALUE_LEN ATT_MAX_VALUE_LEN
#define  SOGPS_BD_ADDR_SIZE                   6
#define SOGPS_MAX_VALUE_LEN 20
ATT_HANDLE g_att_handle = 0;

U8 g_conn_interval_master = 0;

char g_sogp_conn_addr[SOGPS_BD_ADDR_SIZE] = {0};
MMI_BOOL g_firt_write = MMI_FALSE;

SogpsCntx  g_sogps_cntx = {0};
U8        g_sogps_uid[] = {
	0x18, 0xA0, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};
gatts_callback_struct g_sogps_cb = {
	sogps_register_server_callback,
    sogps_connection_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	sogps_service_started_callback,
	NULL,
	NULL,
	sogps_request_read_callback,
	sogps_request_write_callback,
	sogps_request_exec_write_callback,
	NULL,
	NULL,
	NULL,
    NULL,
};
gatts_factory_callback_struct g_sogps_factory_cb = {
	NULL,
	NULL,
	sogps_add_services_callback,
	NULL,
};
/*add for low power*/
#ifdef __MMI_BLE_LOW_POWER__
void sogps_conn_param_interval_reset(void);
void sogps_conn_param_interval_req(char *bd_addr);

#define SOGPS_SET_CONN_INTERVAL_TIME        (1000 * 15)
U8 sogp_bdaddr[SOGPS_BD_ADDR_SIZE] = {0};


void sogps_conn_param_interval_reset(void)
{
	StopTimer(SOGPS_SET_CONN_INTERVAL_TIMER_ID);
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_conn_param_interval_reset success\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_RESET_CONN_INTERVAL);
	srv_gattc_conn_param_update(PROFILE_ID_SOGP,(char *)sogp_bdaddr,CONNECTION_PRIORITY_LOW_POWER); 
}

void sogps_conn_param_interval_req(char *bd_addr)
{
    if (!bd_addr)
    {
	    //kal_prompt_trace(MOD_BT, "[SOGPS] sogps_conn_param_interval_req addr is null\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADDR_NULL);
        return;
    }
	memset(sogp_bdaddr,0x00,SOGPS_BD_ADDR_SIZE);
	memcpy((char *)sogp_bdaddr, bd_addr, SOGPS_BD_ADDR_SIZE);
	StopTimer(SOGPS_SET_CONN_INTERVAL_TIMER_ID);
	if (g_conn_interval_master == 1)
	{
		//means master is android
		srv_gattc_conn_param_update(PROFILE_ID_SOGP,(char *)sogp_bdaddr,CONNECTION_PRIORITY_HIGH_SPEED); 
	}
	else
	{
		//means master is ios
		srv_gattc_conn_param_update(PROFILE_ID_SOGP,(char *)sogp_bdaddr,CONNECTION_PRIORITY_BALANCE); 
	}
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_conn_param_interval_req success\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_SET_CONN_INTERVAL);
	StartTimer(SOGPS_SET_CONN_INTERVAL_TIMER_ID,SOGPS_SET_CONN_INTERVAL_TIME,sogps_conn_param_interval_reset);
}
#endif /*__MMI_BLE_LOW_POWER__*/
/*add for low power end*/

int sogps_find_uuid_by_handle(ATT_HANDLE att_handle, ATT_UUID *svc_uuid, ATT_UUID *chr_uuid)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_sogps_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_find_uuid_by_handle %x!\n", att_handle);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_FIND_UUID, att_handle);
	if (mmi_IsListEmpty(&g_sogps_cntx.srv_list.srvlist))
		return TYPE_UNKNOW;

    if (att_handle == 0)
	{
		return TYPE_UNKNOW;
	}
    
	while((ListEntry *)svc_list != &g_sogps_cntx.srv_list.srvlist)
	{
		if (svc_list->handle == att_handle)
		{
			//kal_prompt_trace(MOD_BT, "[SOGPS] svc_list->type %d!\n", svc_list->type);
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_FIND_UUID_TYPE, svc_list->type);
			switch(svc_list->type)
			{
				case TYPE_SERVICE:
					memcpy(svc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					return TYPE_SERVICE;
					
				case TYPE_CHARACTERISTIC:
					memcpy(chr_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					sogps_find_uuid_by_handle(svc_list->srvhandle, svc_uuid, chr_uuid);
					return TYPE_CHARACTERISTIC;
					
				default:
					return svc_list->type;
			}
		}
			
		svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
	}
	return TYPE_UNKNOW;
}

void sogps_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_register_server_callback status %x, state %d, op_flag %d!\n", 
	//	             status, g_sogps_cntx.state, g_sogps_cntx.op_flag);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_SERVER_REGISTER_CB, status, g_sogps_cntx.state, g_sogps_cntx.op_flag);
	if (memcmp(app_uuid, &g_sogps_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if (g_sogps_cntx.state == SOGP_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				g_sogps_cntx.reg_ctx = reg_ctx;
				if (g_sogps_cntx.op_flag == SOGPS_OP_INIT)
				{
					g_sogps_cntx.op_flag = SOGPS_OP_ADD_SERVICE;
					#ifndef SOGPS_UT
					srv_gatts_profile_factory_get_services(g_sogps_cntx.reg_ctx, PROFILE_ID_SOGP, &g_sogps_cntx.srv_list);
					srv_gatts_profile_factory_add_services(g_sogps_cntx.reg_ctx, &g_sogps_cntx.srv_list);
					#endif
				}
			}
			else
			{
				g_sogps_cntx.reg_ctx = NULL;
				g_sogps_cntx.callback = NULL;
				g_sogps_cntx.op_flag = SOGPS_OP_DEINIT;
				g_sogps_cntx.state = SOGP_STATUS_DISABLED;
			}
		}
		else if (g_sogps_cntx.state == SOGP_STATUS_DISABLING)
		{	
			if (g_sogps_cntx.op_flag == SOGPS_OP_INIT)
			{
				g_sogps_cntx.state = SOGP_STATUS_ENABLING;
				#ifndef SOGPS_UT
				srv_gatts_profile_factory_register(&g_sogps_cntx.uid, &g_sogps_cb, &g_sogps_factory_cb);
				#endif
			}
			else
			{
				g_sogps_cntx.reg_ctx = NULL;
				g_sogps_cntx.callback = NULL;
				g_sogps_cntx.op_flag = SOGPS_OP_DEINIT;
				g_sogps_cntx.state = SOGP_STATUS_DISABLED;
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_register_server_callback -!\n");
}

void sogps_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	SogpsConnCntx    *pConnNode = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
	SogpsConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_connection_callback connected %d!\n", connected);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_CONNECT_CB, connected);
	//if(!mmi_IsListEmpty(&g_sogps_cntx.conn_list))
	//{
	while ((ListEntry *)pConnNode != &g_sogps_cntx.conn_list)
	{
		pConnNext = (SogpsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
		if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[SOGPS] find in list!\n");
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_FIND_IN_LIST);
			pConnNode->conn_ctx = conn->conn_ctx;
			if (connected && (pConnNode->conn_status != SOGP_STATUS_CONNECTED))
			{
				//do next step Discovery all
				#ifndef SOGPS_UT
				if (SRV_SOGPS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
	            {
					srv_gatts_listen(conn->reg_ctx, FALSE);
	            }
                //srv_gatts_listen(conn->reg_ctx, FALSE);
				//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
				#endif
				pConnNode->conn_status = SOGP_STATUS_CONNECTED;
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
			}
			else if(!connected)
			{
				#ifndef SOGPS_UT
				srv_gatts_listen(conn->reg_ctx, TRUE);
				#endif
				g_conn_interval_master = 0;
				mmi_RemoveEntryList(&pConnNode->conn_node);
				free_ctrl_buffer(pConnNode);
				if((g_sogps_cntx.callback != NULL) &&
					(0 == memcmp((char *)g_sogp_conn_addr, (char *)bd_addr->addr, SOGPS_BD_ADDR_SIZE)))
				{
					g_firt_write = MMI_FALSE;
					memset(g_sogp_conn_addr, 0x00, SOGPS_BD_ADDR_SIZE);
					g_sogps_cntx.callback->connection_state_cb(bd_addr->addr, SOGP_STATUS_DISCONNECTED);
				}
			}
			return;
		}
		pConnNode = pConnNext;
	}
	//}
	//else
	//{
	if(connected)
	{
		//kal_prompt_trace(MOD_BT, "[SOGPS] not find in list!\n");
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_NOT_FIND_IN_LIST);
		pConnNode = (SogpsConnCntx *)get_ctrl_buffer(sizeof(SogpsConnCntx));
		memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
		pConnNode->conn_ctx = conn->conn_ctx;
		#ifndef SOGPS_UT
		if (SRV_SOGPS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
        {
			srv_gatts_listen(conn->reg_ctx, FALSE);
        }
		//srv_gatts_listen(conn->reg_ctx, FALSE);
		//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
		#endif
		pConnNode->conn_status = SOGP_STATUS_CONNECTED;
		mmi_InsertTailList(&g_sogps_cntx.conn_list, &pConnNode->conn_node);
	#if 0	
/* under construction !*/
/* under construction !*/
	#endif
	}
//}
}

void sogps_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
	SogpsConnCntx    *pConnNode = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = sogps_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
    S32 ret_val = 0;
       
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_write_callback attr_handle %x, svc_uuid16 %x, chr_uuid16 %x!\n", 
	//	             attr_handle, svc_uuid16, chr_uuid16);  

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_WRITE_CB, attr_handle, svc_uuid16, chr_uuid16);

    if (mmi_IsListEmpty(&g_sogps_cntx.conn_list))
	{
		//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_write_callback doesn't connected!\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_CONNECT_FAIL);
		return;
	}
	while ((ListEntry *)pConnNode != &g_sogps_cntx.conn_list)
	{
		if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[SOGPS] value %x %d %d %d %d", 
            //            value->value[offset], value->len, offset, need_rsp, is_prep);

			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_WRITE_VALUE,value->value[offset], value->len, offset, need_rsp, is_prep);
                  
			if (svc_uuid16 == SOGP_SERVICE && chr_uuid16 == DATA_TO_WRITE_UUID)
			{
			   if (g_sogps_cntx.callback)
               {
                    if (is_prep)
                    {
						g_att_handle = attr_handle;
					}
					
					if ((g_sogps_cntx.callback != NULL) && (MMI_FALSE == g_firt_write))
					{
					    g_firt_write = MMI_TRUE;
						memset(g_sogp_conn_addr, 0x00, SOGPS_BD_ADDR_SIZE);
						memcpy((char *)g_sogp_conn_addr, (char *)bd_addr->addr, SOGPS_BD_ADDR_SIZE);
						g_sogps_cntx.callback->connection_state_cb(bd_addr->addr, SOGP_STATUS_CONNECTED);
					}
					
                    ret_val = g_sogps_cntx.callback->data_to_read_notify_cb(bd_addr->addr, &(value->value[offset]), value->len);
					/*add for low power*/			
				#ifdef __MMI_BLE_LOW_POWER__
					sogps_conn_param_interval_req(bd_addr->addr);
				#endif
					if(ret_val !=0)
                    {
                        // error happen, should send error response
                        srv_gatts_send_response(conn, trans_id, OS_STATUS_FAILED, attr_handle, value); 
                    }
                    else
                    {
                        // success, should send success response
                        srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, value); 
                    }
                    
               }
			}
			return;
		}
		pConnNode = (SogpsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void sogps_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
	SogpsConnCntx    *pConnNode = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = sogps_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              uuid = convert_array_to_uuid16(chr_uuid);
	ATT_VALUE        att_value;
    S32 ret_val;

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_read_callback handle:%x, type:%d, uuid %x, offset %d, long %d!", 
    //    attr_handle, type, uuid, offset, is_long);

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_READ_CB, attr_handle, type, uuid, offset, is_long);
      
	if (type == TYPE_CHARACTERISTIC)
	{	
        if (uuid == DATA_TO_READ_UUID)
        {
            //att_value.len = 1;
            //att_value.value[offset] = 0x18;

            if (g_sogps_cntx.callback)
            {  		
                ret_val = g_sogps_cntx.callback->read_data_request_cb(0, bd_addr->addr, &(att_value.value[offset]), (SOGPS_MAX_VALUE_LEN - offset) );

				/*add for low power*/			
			#ifdef __MMI_BLE_LOW_POWER__
				sogps_conn_param_interval_req(bd_addr->addr);
			#endif
				if (ret_val > 0)
                {
                    att_value.len = ret_val;
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);   
                }
                else
                {
                    att_value.len = 0;
                    srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, attr_handle, &att_value);  
                }
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
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_read_callback -!\n");
	
}

void sogps_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_service_started_callback status %d, srvc_handle %d!\n", 
	//	             status, srvc_handle);
	if (status == OS_STATUS_SUCCESS)
	{
		srv_gatts_listen(reg_ctx, TRUE);
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
					#ifndef FMPT_UT
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#ifndef FMPT_UT
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

void sogps_add_services_callback(OS_STATUS status, void *reg_ctx)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_sogps_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_add_services_callback status %d, state %d, op_flag %d!\n", 
	//	             status, g_sogps_cntx.state, g_sogps_cntx.op_flag);

	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_SERVICE_ADD_CB, status, g_sogps_cntx.state, g_sogps_cntx.op_flag);
	if (g_sogps_cntx.reg_ctx == reg_ctx)
	{
		if (g_sogps_cntx.state == SOGP_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				if (g_sogps_cntx.op_flag == SOGPS_OP_ADD_SERVICE)
				{
					if (mmi_IsListEmpty(&g_sogps_cntx.srv_list.srvlist))
					{
						//kal_prompt_trace(MOD_BT, "[SOGPS] is empty service list!\n");
						return;
					}
					while((ListEntry *)svc_list != &g_sogps_cntx.srv_list.srvlist)
					{
						if (svc_list->type == TYPE_SERVICE)
						{
							#ifndef SOGPS_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
					g_sogps_cntx.state = SOGP_STATUS_ENABLED;
				}
			}
			else
			{
				sogps_deinit();
			}
		}	
		
	}
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_add_services_callback -!\n");
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
					#ifndef SOGPS_UT
/* under construction !*/
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
					#ifndef SOGPS_UT
/* under construction !*/
					#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#ifndef SOGPS_UT
/* under construction !*/
/* under construction !*/
				#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
BtStatus sogps_disconnect_event_handler(BD_ADDR *bdaddr)
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	SogpsConnCntx    *pConnCur = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_disconnect_event_handler !\n");
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_DISCONNECT_EVENT_CB);
	if ((g_sogps_cntx.state == SOGP_STATUS_DISABLED)
		|| (g_sogps_cntx.state == SOGP_STATUS_DISABLING))
		return BT_STATUS_FAILED;

    while ((ListEntry *)pConnCur != &g_sogps_cntx.conn_list)
	{
		//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_disconnect_event_handler pConnCur->bdaddr %s!\n",pConnCur->bdaddr);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_DISCONNECT_EVENT_CB_2, pConnCur->bdaddr);
	    if (memcmp(bdaddr->addr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
	    {
			//kal_prompt_trace(MOD_BT, "[SOGPS] find in list conn_status %d !\n", pConnCur->conn_status);
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_DISCONNECT_EVENT_CB_1, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_sogps_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if ((pConnCur->conn_status == SOGP_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == SOGP_STATUS_CONNECTING))
			{
				pConnCur->conn_status = SOGP_STATUS_DISCONNECTING;
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				srv_gatts_disconnect(&gatt_conn, &bd_addr);
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
				if((g_sogps_cntx.callback != NULL) &&
					(0 == memcmp((char *)g_sogp_conn_addr, (char *)bd_addr.addr, SOGPS_BD_ADDR_SIZE)))
				{
					g_firt_write = MMI_FALSE;
					memset(g_sogp_conn_addr, 0x00, SOGPS_BD_ADDR_SIZE);
					g_sogps_cntx.callback->connection_state_cb(bd_addr.addr, SOGP_STATUS_DISCONNECTED);
				}
				//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_disconnect_event_handler disconnected 1!\n");
				return BT_STATUS_SUCCESS;
			}
			else if ((pConnCur->conn_status == SOGP_STATUS_DISCONNECTED) 
				|| (pConnCur->conn_status == SOGP_STATUS_DISCONNECTING))
			{
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
				if((g_sogps_cntx.callback != NULL) &&
					(0 == memcmp((char *)g_sogp_conn_addr, pConnCur->bdaddr, SOGPS_BD_ADDR_SIZE)))
				{
					g_firt_write = MMI_FALSE;
					memset(g_sogp_conn_addr, 0x00, SOGPS_BD_ADDR_SIZE);
					g_sogps_cntx.callback->connection_state_cb(pConnCur->bdaddr, SOGP_STATUS_DISCONNECTED);
				}

				//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_disconnect_event_handler disconnected 2!\n");
				return BT_STATUS_SUCCESS;
			}			
			break;	
		}
		pConnCur = (SogpsConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}
	return BT_STATUS_FAILED;
}

void sogps_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret sogps_recv_event_handler(mmi_event_struct *evt)
{
    srv_le_cm_evt_disconnect_struct *disconn_data = (srv_le_cm_evt_disconnect_struct *)evt;
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_recv_event_handler evt->evt_id %d!\n",evt->evt_id);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_RECV_EVENT_HANDLER_1, evt->evt_id);
	    
    if ( evt->evt_id == SRV_LE_CM_EVENT_DISCONNECT_REQ ) 
    {
        BD_ADDR remote_addr;
		sogps_get_bd_addr(&remote_addr,disconn_data->dev_addr);
		sogps_disconnect_event_handler(&remote_addr);
		//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_recv_event_handler remote_addr %s!\n",remote_addr.addr);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_RECV_EVENT_HANDLER_2, remote_addr.addr);
    }
    return MMI_RET_OK;
}
BtStatus sogps_init(sogps_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_init state %d, op_flag %d!\n", 
	//	             g_sogps_cntx.state, g_sogps_cntx.op_flag);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_INIT, g_sogps_cntx.state, g_sogps_cntx.op_flag);
	mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, sogps_recv_event_handler, NULL);
	if (g_sogps_cntx.state == SOGP_STATUS_DISABLED)
	{
		g_sogps_cntx.state = SOGP_STATUS_ENABLING;
		g_sogps_cntx.op_flag = SOGPS_OP_INIT;
		g_sogps_cntx.callback = cb;
		memcpy(g_sogps_cntx.uid.uu, &g_sogps_uid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_sogps_cntx.conn_list);
		#ifndef SOGPS_UT
		srv_gatts_profile_factory_register(&g_sogps_cntx.uid, &g_sogps_cb, &g_sogps_factory_cb);
		#endif
	}
	else if (g_sogps_cntx.state == SOGP_STATUS_DISABLING)
	{
		if (g_sogps_cntx.op_flag == SOGPS_OP_DEINIT)
		{
			g_sogps_cntx.op_flag = SOGPS_OP_INIT;
		}
		g_sogps_cntx.callback = cb;
		memcpy(g_sogps_cntx.uid.uu, &g_sogps_uid, sizeof(bt_uuid_struct));
	}
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_init -!\n");
	return status;
}

BtStatus sogps_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	SogpsConnCntx    *pConnCur = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
	SogpsConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_deinit state %d, op_flag %d!\n", 
	//	             g_sogps_cntx.state, g_sogps_cntx.op_flag);
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_DEINIT, g_sogps_cntx.state, g_sogps_cntx.op_flag);
	g_conn_interval_master = 0;
	if((g_sogps_cntx.state == SOGP_STATUS_DISABLED)
		|| (g_sogps_cntx.state == SOGP_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;
	#ifndef SOGPS_UT
	//srv_gatts_listen(g_sogps_cntx.reg_ctx, FALSE);
	#endif
	if(g_sogps_cntx.state == SOGP_STATUS_ENABLED)
	{
		if (mmi_IsListEmpty(&g_sogps_cntx.conn_list))
		{
			//kal_prompt_trace(MOD_BT, "[SOGPS] is empty connection list!\n");
			goto do_deinit;
		}
		
        while ((ListEntry *)pConnCur != &g_sogps_cntx.conn_list)
		{
			pConnNext = (SogpsConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_sogps_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if ((pConnCur->conn_status == SOGP_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == SOGP_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				#ifndef SOGPS_UT
				//srv_gatts_disconnect(&gatt_conn, &bd_addr);
				#endif
			#if 0
/* under construction !*/
/* under construction !*/
			#endif
				if((g_sogps_cntx.callback != NULL) &&
					(0 == memcmp((char *)g_sogp_conn_addr, bd_addr.addr, SOGPS_BD_ADDR_SIZE)))
				{
					g_firt_write = MMI_FALSE;
					memset(g_sogp_conn_addr, 0x00, SOGPS_BD_ADDR_SIZE);
					g_sogps_cntx.callback->connection_state_cb(bd_addr.addr, SOGP_STATUS_DISCONNECTED);
				}
			}
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}
	
do_deinit:
	#ifndef SOGPS_UT
	srv_gatts_profile_factory_delete_services(g_sogps_cntx.reg_ctx, &g_sogps_cntx.srv_list);
	srv_gatts_profile_factory_clear_services(g_sogps_cntx.reg_ctx, &g_sogps_cntx.srv_list);
	srv_gatts_profile_factory_deregister(g_sogps_cntx.reg_ctx);
	#endif
    mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, sogps_recv_event_handler, NULL);
	g_sogps_cntx.state = SOGP_STATUS_DISABLED;
	g_sogps_cntx.op_flag = SOGPS_OP_DEINIT;
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_deinit -!\n");
	return BT_STATUS_SUCCESS;
}

S32 sogps_send_data(void* buf, char *bdaddr, U32 len, S32 *err_code)
{
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_sogps_cntx.srv_list.srvlist);
    SogpsConnCntx    *pConnNode = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
    SogpsConnCntx    *pConnNext = NULL;
    gatt_conn_struct gatt_conn;
    ATT_VALUE *att_value = NULL;
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    int type;
    U16  svc_uuid16;
    U16  chr_uuid16;
    U32 send_size = 0; 
    
    
    //kal_prompt_trace(MOD_BT, "[SOGPS] sogp_send_data buf:%x, size:%d !\n", buf, len);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_SEND_DATA, buf, len);

    if(buf == NULL)
    {
        *err_code = -1;
        return 0;
    }
       
    if(!mmi_IsListEmpty(&g_sogps_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_sogps_cntx.conn_list)
        {
            pConnNext = (SogpsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            if((pConnNode->conn_status == SOGP_STATUS_CONNECTED) &&
				(memcmp(pConnNode->bdaddr, bdaddr, BD_ADDR_SIZE) == 0))
            {
                //kal_prompt_trace(MOD_BT, "[SOGPS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_FIND_IN_LIST);
                gatt_conn.reg_ctx = g_sogps_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while((ListEntry *)svc_list != &g_sogps_cntx.srv_list.srvlist)
                {          
                   // kal_prompt_trace(MOD_BT, "[SOGPS] find in list!\n");
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_FIND_IN_LIST);
                    
                    if (svc_list->type == TYPE_CHARACTERISTIC)
                    {
                         
                        type = sogps_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid);   
                        if (type != TYPE_CHARACTERISTIC)
                        {
                            *err_code = -3;
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
                        if(chr_uuid16 == DATA_TO_READ_UUID)
                        {  
                        	/*add for IOS DOGP*/
                            char str[15] = {"ios indication"};
						   
                            send_size = len;
                            if(len > SOGPS_MAX_VALUE_LEN)
                            {
                                len = SOGPS_MAX_VALUE_LEN;
                            }

							/*add for low power*/						
						#ifdef __MMI_BLE_LOW_POWER__
							sogps_conn_param_interval_req(pConnNode->bdaddr);
						#endif                            
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
							/*add for IOS DOGP*/
                            //memcpy(att_value->value, buf, len);
                            //att_value->len = len;
							memcpy(att_value->value, str, 14);
                            att_value->len = 14;
                            srv_gatts_send_indication(&gatt_conn, svc_list->handle,FALSE, att_value);
                            free_ctrl_buffer(att_value);
                            att_value = NULL;
                            *err_code = 0;
                            break;
                        }
                    }
                    svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
                }
                
                return send_size;
            }
            pConnNode = pConnNext;
        }

        *err_code = -4;
        return 0;
    }
    else
    {
        // no connecton 
        *err_code = -5;
        return  0;
    }
}
void sogps_request_exec_write_callback(gatt_conn_struct *conn, U16 trans_id,
                                            BD_ADDR *bd_addr, BOOL cancel)
{
	SogpsConnCntx	 *pConnNode = (SogpsConnCntx *)mmi_GetHeadList(&g_sogps_cntx.conn_list);
	ATT_UUID		 svc_uuid;
	ATT_UUID		 chr_uuid;
	int 			 type = sogps_find_uuid_by_handle(g_att_handle, &svc_uuid, &chr_uuid);
	U16 			 svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16 			 chr_uuid16 = convert_array_to_uuid16(chr_uuid);
	ATT_VALUE        att_value;
		   
	//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_exec_write_callback attr_handle %x, svc_uuid16 %x, chr_uuid16 %x!\n", 
	//				 g_att_handle, svc_uuid16, chr_uuid16);	

	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_EXEC_WRITE_CB, g_att_handle, svc_uuid16, chr_uuid16);

	if (mmi_IsListEmpty(&g_sogps_cntx.conn_list))
	{
		//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_exec_write_callback doesn't connected!\n");
		
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_CONNECT_FAIL);
		return;
	}
	while ((ListEntry *)pConnNode != &g_sogps_cntx.conn_list)
	{
		if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
			//kal_prompt_trace(MOD_BT, "[SOGPS] sogps_request_exec_write_callback success trans_id = %d, cancel = %d", 
			//			  trans_id, cancel);
			
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_EXEC_WRITE_SUCCESS, trans_id, cancel);
				  
			if (svc_uuid16 == SOGP_SERVICE && chr_uuid16 == DATA_TO_WRITE_UUID)
			{					
				/*add for low power*/			
				#ifdef __MMI_BLE_LOW_POWER__
				sogps_conn_param_interval_req(bd_addr->addr);
				#endif
				//should send response
				att_value.len = 0;
                srv_gatts_send_response(conn, trans_id, OS_STATUS_SUCCESS, g_att_handle, &att_value);  
			}
			return;
		}
		pConnNode = (SogpsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
	}
}

void sogps_conn_param_interval_set_high_level(U8 dev_type)
{
	g_conn_interval_master = dev_type;
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
#endif

#endif  /* __MMI_BLE_DOGP_SUPPORT__ */