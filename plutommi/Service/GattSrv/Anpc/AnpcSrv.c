
#ifdef __BT_GATTC_PROFILE__ 

#include "kal_trace.h"
#include "Kal_debug.h"
#include "MMI_features.h"
#include "MMIDataType.h"
#include "CustDataRes.h"
#include "GattcSrv.h"
#include "GattSrv.h"
#include "MMI_conn_app_trc.h"
#include "MMI_trc_Int.h"
#include "AnpcSrv.h"
#include "BLESrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "mmi_cb_mgr_gprot.h"


#define ANPC_DEBUG(S) kal_prompt_trace(MOD_BT, S)  

#define SRV_ANPC_TRACE_GROUP    MMI_CONN_TRC_G7_BT



typedef enum
{
    ANPC_STATE_DISABLED = 0,
    ANPC_STATE_ENABLING,
    ANPC_STATE_ENABLED,
    ANPC_STATE_DISCONNECTING,
    ANPC_STATE_CONNECTING,
    ANPC_STATE_CONNECTED,
    ANPC_STATE_SEARCHING,
} anpc_state_enum;

U8 anps_srv_uuid[16] = {0xfb, 0x34, 0x9b, 0x5f, 0x80, 0x00, 0x00, 0x80, 0x00, 0x10, 0x00, 0x00, 0x11,
    0x18, 0x00, 0x00};

#ifdef __BT_MAX_LE_LINK_NUM__
#define MAX_LINK_NUM_ANP __BT_MAX_LE_LINK_NUM__
#else
#define MAX_LINK_NUM_ANP 1
#endif
typedef struct
{
	BD_ADDR                     conn_addr;
	void*						conn_ctx;
	BOOL						is_record;
}anpc_srv_deivce_manager_struct;


typedef struct
{
	anpc_srv_deivce_manager_struct dev[MAX_LINK_NUM_ANP];
    gattc_callback_struct       gatt_cb;
    anp_client_app_callback     app_cb;
    anpc_state_enum             state;
    gatt_conn_struct            conn;
    bt_uuid_struct              app_uuid;
    BD_ADDR                     remote_addr;
    U16                         oper;
    U16                         cp_cmd;
    U8                          on_off;
    U8                          category_id;
    BOOL                        srv_found;
    BOOL                        conn_init;
	BOOL						is_server_find;
} anpc_srv_cntx_struct;

anpc_srv_cntx_struct apnc_srv_ctx;
anpc_srv_cntx_struct* pAnpcCtx = &apnc_srv_ctx;

static void srv_anp_client_deregister_notification(BD_ADDR* btaddr);


static void anpc_app_cb(anp_client_app_cb_param* param)
{
    if (pAnpcCtx->app_cb != NULL)
    {
        pAnpcCtx->app_cb(param);
    }
    else
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_APP_CB_IS_NULL);
    }
}

static void  anpc_register_client_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
    OS_ANPC_STATUS result;
    anp_client_app_cb_param param;

    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_REG_CB_ENTRY);

    if (kal_mem_cmp(app_uuid, &pAnpcCtx->app_uuid, sizeof(bt_uuid_struct)) != 0)
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_APP_UUID_IS_WRONG);
        return;
    }

    if (pAnpcCtx->state != ANPC_STATE_ENABLING)
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_REG_CB_IN_WRONG_STATE, pAnpcCtx->state);
        return;
    }

    
    if (status == OS_STATUS_SUCCESS)
    {
        result = OS_ANPC_STATUS_SUCCESS;
        pAnpcCtx->state = ANPC_STATE_ENABLED;
        pAnpcCtx->conn.reg_ctx = reg_ctx;
    }
    else
    {
        result = OS_ANPC_STATUS_FAILED;
    }

    kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
    param.evtid = ANPC_MMI_EVT_ENABLE_CNF;
    param.result = result;

    anpc_app_cb(&param);
}

/** Callback triggered in response to listen */
static void anpc_listen_callback(void *reg_ctx, OS_STATUS status)
{
    anp_client_app_cb_param param;

   
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_LISTEN_CB_ENTRY);

    if (reg_ctx == pAnpcCtx->conn.reg_ctx)
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        
        if (status == OS_STATUS_SUCCESS)
        {
            param.result = OS_ANPC_STATUS_SUCCESS;
        }
        else
        {
            param.result = OS_ANPC_STATUS_FAILED;
        }

        param.evtid = ANPC_MMI_EVT_LISTEN_RESULT;

        anpc_app_cb(&param);
    }
    else
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_LISTEN_CB_ERR_REG_CTX);
    }


}


BOOL anpc_check_is_find_service()
{
	return pAnpcCtx->is_server_find;
}

BOOL anpc_get_device_address_by_conn(BD_ADDR *bd_addr, void *conn_ctx)
{
	kal_uint32 i;
	BOOL ret = FALSE;

	if(!bd_addr)
	{
		MMI_ASSERT(0);
	}
	for(i = 0; i < MAX_LINK_NUM_ANP; i++)
	{
		if(apnc_srv_ctx.dev[i].is_record && apnc_srv_ctx.dev[i].conn_ctx == conn_ctx)
		{
			kal_mem_cpy(bd_addr, &apnc_srv_ctx.dev[i].conn_addr, BD_ADDR_SIZE);
			ret = TRUE;
			break;
		}

	}	
	return ret;
}
void anpc_add_conn_device(BD_ADDR *bd_addr, void *conn_ctx)
{
	kal_uint32 i;
	for(i = 0; i < MAX_LINK_NUM_ANP; i++)
	{
		if(!apnc_srv_ctx.dev[i].is_record)
		{
			kal_mem_cpy(&apnc_srv_ctx.dev[i].conn_addr, bd_addr, BD_ADDR_SIZE);
			apnc_srv_ctx.dev[i].conn_ctx = conn_ctx;			
			apnc_srv_ctx.dev[i].is_record = TRUE;
			MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONN_ADD_DEVICE);
			break;
		}

	}

}
void anpc_remove_conn_device(BD_ADDR *bd_addr)
{
	kal_uint32 i;
	for(i = 0; i < MAX_LINK_NUM_ANP; i++)
	{
		if(apnc_srv_ctx.dev[i].is_record && kal_mem_cmp(&apnc_srv_ctx.dev[i].conn_addr, bd_addr, BD_ADDR_SIZE) == 0)
		{
			kal_mem_set(&apnc_srv_ctx.dev[i].conn_addr, 0, BD_ADDR_SIZE);
			apnc_srv_ctx.dev[i].conn_ctx = 0;
			apnc_srv_ctx.dev[i].is_record = FALSE;
			break;
		}

	}

}


// TODO:Connect req or listen will all receive this ?
static void anpc_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
    anp_client_app_cb_param param;
    bt_uuid_struct filter_uuid;

    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CNN_CB_ENTRY_STATE, pAnpcCtx->state);
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CNN_CB_BDADDR, bd_addr->addr[0], bd_addr->addr[1], bd_addr->addr[2]
        , bd_addr->addr[3], bd_addr->addr[4], bd_addr->addr[5]);

    if (conn && bd_addr)
    {
        if ((conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
            //&& (kal_mem_cmp(bd_addr, &pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) == 0))
        {
            kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
            
            if (connected == TRUE)
            {
                //param.evtid = ANPC_MMI_EVT_CONNEC_IND;
                //pAnpcCtx->state = ANPC_STATE_CONNECTED;
                //if (pAnpcCtx->state != ANPC_STATE_SEARCHING)
                //{
                	if(!pAnpcCtx->is_server_find)
                {
                		anpc_add_conn_device(bd_addr, conn->conn_ctx);
	                    //pAnpcCtx->conn.conn_ctx = conn->conn_ctx;
	                    //kal_mem_cpy(&pAnpcCtx->remote_addr, bd_addr, BD_ADDR_SIZE);
                    
                    kal_mem_cpy(&filter_uuid.uu, &anps_srv_uuid, 16);
                    pAnpcCtx->state = ANPC_STATE_SEARCHING;
                    pAnpcCtx->srv_found = FALSE;
                    srv_gattc_search_service(conn, &filter_uuid);
                }
                else
                {
                	MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONN_CALLBACK_DISCON);					
                    srv_gattc_disconnect(conn, bd_addr);
                }
                //}
                #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
				#endif
            }
            else
            {

				if(kal_mem_cmp(bd_addr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE) == 0)
				{
					srv_anp_client_deregister_notification(bd_addr);
                param.evtid = ANPC_MMI_EVT_DISCONNECT_IND;
					kal_mem_cpy(&param.bdaddr, bd_addr, BD_ADDR_SIZE);
                if (pAnpcCtx->state != ANPC_STATE_DISABLED)
                {
                    pAnpcCtx->state = ANPC_STATE_ENABLED;
                }
					pAnpcCtx->is_server_find = FALSE;
                pAnpcCtx->conn_init = FALSE;
                anpc_app_cb(&param);
            }
				anpc_remove_conn_device(bd_addr);        
               
            }

        }
        else
        {
            
            pAnpcCtx->conn_init = FALSE;
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CNN_CB_ERR_REG_CTX);
        }
    }
    else
    {
       
        pAnpcCtx->conn_init = FALSE;
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CNN_CB_PARAM_ERR, (U32)conn, (U32)bd_addr);
    }
}

static void anpc_search_complete_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    anp_client_app_cb_param param;
	BD_ADDR bd_addr;
	BOOL ret;


    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_SRC_COMPLETE_CB_STATE, pAnpcCtx->state);

    if (conn->reg_ctx == pAnpcCtx->conn.reg_ctx)
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        
        if (status == OS_STATUS_SUCCESS && pAnpcCtx->srv_found == TRUE
			&& pAnpcCtx->is_server_find == FALSE)
        {
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_SRC_COMPLETE_CB_ADDR, pAnpcCtx->remote_addr.addr[0], pAnpcCtx->remote_addr.addr[1]
                , pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[3], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[5]);
            pAnpcCtx->state = ANPC_STATE_CONNECTED;
            param.evtid = ANPC_MMI_EVT_CONNEC_IND;
			ret = anpc_get_device_address_by_conn(&bd_addr,conn->conn_ctx);
			if(ret)
			{
				pAnpcCtx->is_server_find = TRUE;
				kal_mem_cpy(&pAnpcCtx->remote_addr, &bd_addr,BD_ADDR_SIZE);
				kal_mem_cpy(&param.bdaddr,&bd_addr,BD_ADDR_SIZE);
				pAnpcCtx->conn.conn_ctx = conn->conn_ctx;
            anpc_app_cb(&param);
        }
        else
        {
        	MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONN_CALLBACK_COMPELETE_1);				
        }
				
	
        }
        else
        {
        	ret = anpc_get_device_address_by_conn(&bd_addr,conn->conn_ctx);
			MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONN_CALLBACK_COMPELETE_2, ret);		
			if(ret)
			{
				srv_gattc_disconnect(conn, &bd_addr);
				//srv_anp_client_disconnect_req(&bd_addr);
    }
    else
    {
				MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONN_CALLBACK_COMPELETE_3);			
			}
            
        }
    }
    else
    {

        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_SRC_COMPLETE_CB_ERR_REG_CTX);
    }

}

static  void anpc_search_result_callback(gatt_conn_struct *conn, GATT_SVC_UUID *uuid)
{
  
    U16 srv_uuid;
    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_SRC_RESULT_CB);

    srv_uuid = convert_array_to_uuid16(uuid->uuid);

    if (srv_uuid == ALERT_NOTIFICATION_U16)
    {
        pAnpcCtx->srv_found = TRUE;
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_SRC_FOUND);
    }
}

static void anpc_get_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *cha, GATT_CHAR_PROPERTIES properties)
{
    anp_client_app_cb_param param;
    U16 uuid;
    ATT_VALUE   value;

    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_GET_CHAR_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_set(&value, 0x0, sizeof(ATT_VALUE));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*cha->char_uuid);

        if ((pAnpcCtx->oper == ANPC_OPER_READ_NEW_ALERT) && (uuid == NEW_ALERT_CATEGORY_U16))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                srv_gattc_read_characteristic(conn, cha, GATTC_AUTH_REQ_NONE);
            }
            else
            {
                pAnpcCtx->oper = ANPC_OPER_IDLE;
                param.evtid = ANPC_MMI_EVT_READ_SUPPORTED_NEW_ALERT_CNF;
                param.result = OS_ANPC_STATUS_FAILED;
                anpc_app_cb(&param);
            }
        }
        else if ((pAnpcCtx->oper == ANPC_OPER_READ_UNREAD_ALERT) && (uuid == UNREAD_ALERT_CATEGORY_U16))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                srv_gattc_read_characteristic(conn, cha, GATTC_AUTH_REQ_NONE);
            }
            else
            {
                pAnpcCtx->oper = ANPC_OPER_IDLE;
                param.evtid = ANPC_MMI_EVT_READ_SUPPORTED_UNREAD_ALERT_CNF;
                param.result = OS_ANPC_STATUS_FAILED;
                anpc_app_cb(&param);
            }
        }
        else if (((pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT) && (uuid == NEW_ALERT_U16)) 
            || ((pAnpcCtx->oper == ANPC_OPER_CONFIG_UNREAD_ALERT) && (uuid == UNREAD_ALERT_U16)))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                if (pAnpcCtx->on_off = ANPC_CONFIG_ALERT_ON)
                {
                    srv_gattc_register_for_notification(conn->reg_ctx, &pAnpcCtx->remote_addr, cha);
                }
                else
                {
                    srv_gattc_deregister_for_notification(conn->reg_ctx, &pAnpcCtx->remote_addr, cha);
                }

            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT)
                {
                    param.evtid = ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF;
                }
                else
                {
                    param.evtid = ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF;
                }
                
                pAnpcCtx->oper = ANPC_OPER_IDLE;
                param.result = OS_ANPC_STATUS_FAILED;
                param.on_off = pAnpcCtx->on_off;
                anpc_app_cb(&param);
            }
        }
        else if ((pAnpcCtx->oper == ANPC_OPER_WRITE_CONTROL_POINT_REQ) && (uuid == ALERT_CONTROL_POINT_U16))
        {
            if (pAnpcCtx->cp_cmd == CMD_ENABLE_NEW_ALERT)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_ENABLE_NEW_ALERT;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);
                }
            }
            else if (pAnpcCtx->cp_cmd == CMD_DISABLE_NEW_ALERT)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_DISABLE_NEW_ALERT;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);

                }
            }
            else if (pAnpcCtx->cp_cmd == CMD_ENABLE_UNREAD_ALERT)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_ENABLE_UNREAD_ALERT;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);
                }
            }
            else if (pAnpcCtx->cp_cmd == CMD_DISABLE_UNREAD_ALERT)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_DISABLE_UNREAD_ALERT;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);

                }
            }
            else if (pAnpcCtx->cp_cmd == CMD_NOTIFY_NEW_ALERT_IMM)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_NOTIFY_NEW_ALERT_IMM;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);

                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);

                }
            }
            else if (pAnpcCtx->cp_cmd == CMD_NOTIFY_UNREAD_ALERT_IMM)
            {
                if (status == OS_STATUS_SUCCESS)
                {
                    value.value[0] = CMD_NOTIFY_NEW_ALERT_IMM;
                    value.value[1] = pAnpcCtx->category_id;
                    value.len = 2;
                    srv_gattc_write_characteristic(conn, cha, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                }
                else
                {
                    pAnpcCtx->oper = ANPC_OPER_IDLE;
                    param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
                    param.result = OS_ANPC_STATUS_FAILED;
                    param.category_id = pAnpcCtx->category_id;
                    param.cmd = pAnpcCtx->cp_cmd;
                    anpc_app_cb(&param);
                }
            }
            else
            {
               
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_UNKNOW_CMD, pAnpcCtx->cp_cmd);
            }
        }
        else
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_GET_CHAR_CB_ERR_REG_CTX);
    }

}

static void anpc_get_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status, gattc_descr_struct *descr)
{
    anp_client_app_cb_param param;
    U16 uuid;
    ATT_VALUE   value;

   
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_GET_DES_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_set(&value, 0x0, sizeof(ATT_VALUE));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*descr->char_uuid);

        if (((pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT) && (uuid == NEW_ALERT_U16)) 
            || ((pAnpcCtx->oper == ANPC_OPER_CONFIG_UNREAD_ALERT) && (uuid == UNREAD_ALERT_U16)))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                if (pAnpcCtx->on_off == ANPC_CONFIG_ALERT_ON)
                {
                    value.value[0] = 0x01;
                }
                else
                {
                    value.value[0] = 0x00;
                }
                
                value.value[1] = 0x00;
                value.len = 2;
                
                srv_gattc_write_descriptor(conn, descr, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT)
                {
                    param.evtid = ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF;
                }
                else
                {
                    param.evtid = ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF;
                }
                
                pAnpcCtx->oper = ANPC_OPER_IDLE;
                param.result = OS_ANPC_STATUS_FAILED;
                param.on_off = pAnpcCtx->on_off;
                anpc_app_cb(&param);
            }
        }
 
        else
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_GET_DES_CB_ERR_REG_CTX);
    }

}

static void anpc_register_for_notification_callback(void *reg_ctx, OS_STATUS status, 
                                BD_ADDR *bd_addr, gattc_char_struct *cha)
{
    anp_client_app_cb_param param;
    U16 uuid;
    ATT_VALUE   value;
    ATT_UUID    descr_uuid;
    gattc_descr_struct desc_info;


    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_REG_NOTIFY_CB_STATE, pAnpcCtx->state);

    if ((reg_ctx != NULL) && (reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_set(&value, 0x0, sizeof(ATT_VALUE));
        kal_mem_set(&descr_uuid, 0x0, sizeof(ATT_UUID));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*cha->char_uuid);

        if (((pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT) && (uuid == NEW_ALERT_U16)) 
            || ((pAnpcCtx->oper == ANPC_OPER_CONFIG_UNREAD_ALERT) && (uuid == UNREAD_ALERT_U16)))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                convert_uuid16_to_array(ANP_CHAR_CONFIGURATION_U16, &descr_uuid);
                //srv_gattc_get_descriptor(&pAnpcCtx->conn, cha, &descr_uuid);
                if (pAnpcCtx->on_off == ANPC_CONFIG_ALERT_ON)
                {
                    value.value[0] = 0x01;
                }
                else
                {
                    value.value[0] = 0x00;
                }
                
                value.value[1] = 0x00;
                value.len = 2;

                desc_info.svc_uuid = cha->svc_uuid;
                desc_info.char_uuid = cha->char_uuid;
                desc_info.descr_uuid = &descr_uuid;
                srv_gattc_write_descriptor(&pAnpcCtx->conn, &desc_info, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT)
                {
                    param.evtid = ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF;
                }
                else
                {
                    param.evtid = ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF;
                }
            
                pAnpcCtx->oper = ANPC_OPER_IDLE;
                param.result = OS_ANPC_STATUS_FAILED;
                param.on_off = pAnpcCtx->on_off;
                anpc_app_cb(&param);
            }
        }
        else
        {
           
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_REG_NOTIFY_CB_ERR_REG_CTX);
    }

}

static void anpc_notify_callback(gatt_conn_struct *conn, BD_ADDR *bd_addr,
                                gattc_char_struct *cha, ATT_VALUE *value, BOOL is_notify)
{
    anp_client_app_cb_param param;
    U16 uuid;
    U8 len;

    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_NOTIFY_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx) && value != NULL)
    {
        if (kal_mem_cmp(bd_addr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) == 0)
        {
            kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
            kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

            uuid = convert_array_to_uuid16(*cha->char_uuid);

            if (uuid == NEW_ALERT_U16 || uuid == UNREAD_ALERT_U16)
            {

                param.category_id = value->value[0];
                param.alert_num = value->value[1];
				if((value->len - 2) > (ANP_MAX_INFO_LENGTH))
				{
					len = ANP_MAX_INFO_LENGTH;
					param.is_trucated = MMI_TRUE;
				}
				else
				{
					len = value->len - 2;
					param.is_trucated = MMI_FALSE;
				}
                //len = ((value->len - 2) > (ANP_MAX_INFO_LENGTH)) ? (ANP_MAX_INFO_LENGTH) : (value->len - 2);
                kal_mem_cpy(&param.alert_info, &value->value[2], len);

                if (uuid == NEW_ALERT_U16)
                {
                    param.evtid = ANPC_MMI_EVT_NEW_ALERT_NOTIFY_IND;
                }
                else
                {
                    param.evtid = ANPC_MMI_EVT_UNREAD_ALERT_NOTIFY_IND;
                }
                anpc_app_cb(&param);
            }    
            else
            {
              
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
            }
        }
        else
        {
          
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_NOT_CONNECTIED_DEV);
        }
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_NOTIFY_CB_ERR_REG_CTX);
    }
}

static void anpc_read_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *cha, ATT_VALUE *value)
{
    anp_client_app_cb_param param;
    U16 uuid;

   
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_READ_CHA_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*cha->char_uuid);

        if ((pAnpcCtx->oper == ANPC_OPER_READ_NEW_ALERT) && (uuid == NEW_ALERT_CATEGORY_U16))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                param.category_bit = ((U16)value->value[1]) << 8 | value->value[0];
                param.result = OS_ANPC_STATUS_SUCCESS;
            }
            else
            {
                param.result = OS_ANPC_STATUS_FAILED;
            }
            pAnpcCtx->oper = ANPC_OPER_IDLE;
            param.evtid = ANPC_MMI_EVT_READ_SUPPORTED_NEW_ALERT_CNF;
            anpc_app_cb(&param);
        }
        else if ((pAnpcCtx->oper == ANPC_OPER_READ_UNREAD_ALERT) && (uuid == UNREAD_ALERT_CATEGORY_U16))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                param.category_bit = ((U16)value->value[1]) << 8 | value->value[0];
                param.result = OS_ANPC_STATUS_SUCCESS;
            }
            else
            {
                param.result = OS_ANPC_STATUS_FAILED;
            }
            pAnpcCtx->oper = ANPC_OPER_IDLE;
            param.evtid = ANPC_MMI_EVT_READ_SUPPORTED_UNREAD_ALERT_CNF;
            anpc_app_cb(&param);
        }        
        else
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_READ_CHAR_ERR_REG_CTX);
    }

}


static void anpc_write_characteristic_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_char_struct *cha)
{
    anp_client_app_cb_param param;
    U16 uuid;

    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_CHA_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*cha->char_uuid);

        if (uuid == ALERT_CONTROL_POINT_U16 && pAnpcCtx->oper == ANPC_OPER_WRITE_CONTROL_POINT_REQ)
        {
            if (status == OS_STATUS_SUCCESS)
            {
                param.result = OS_ANPC_STATUS_SUCCESS;
            }
            else
            {
                param.result = OS_ANPC_STATUS_FAILED;
            }
            
            param.category_id = pAnpcCtx->category_id;
            param.evtid = ANPC_MMI_EVT_WRITE_CONTROL_POINT_CNF;
            param.cmd = pAnpcCtx->cp_cmd;
            pAnpcCtx->oper = ANPC_OPER_IDLE;
            
            anpc_app_cb(&param);
        }
        else
        {
           
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_CHAR_ERR_REG_CTX);
    }

}

static void anpc_read_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr, ATT_VALUE *value)
{
    // Not implement
}

static void anpc_write_descriptor_callback(gatt_conn_struct *conn, OS_STATUS status,
                                gattc_descr_struct *descr)
{
    anp_client_app_cb_param param;
    U16 uuid;
    ATT_VALUE   value;

   
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_DES_CB_STATE, pAnpcCtx->state);

    if ((conn != NULL) && (conn->reg_ctx == pAnpcCtx->conn.reg_ctx))
    {
        kal_mem_set(&param, 0x0, sizeof(anp_client_app_cb_param));
        kal_mem_set(&value, 0x0, sizeof(ATT_VALUE));
        kal_mem_cpy(&param.bdaddr, &pAnpcCtx->remote_addr, BD_ADDR_SIZE);

        uuid = convert_array_to_uuid16(*descr->char_uuid);

        if (((pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT) && (uuid == NEW_ALERT_U16)) 
            || ((pAnpcCtx->oper == ANPC_OPER_CONFIG_UNREAD_ALERT) && (uuid == UNREAD_ALERT_U16)))
        {
            if (status == OS_STATUS_SUCCESS)
            {
                param.result = OS_ANPC_STATUS_SUCCESS;
            }
            else
            {
                param.result = OS_ANPC_STATUS_FAILED;
            }

            if (pAnpcCtx->oper == ANPC_OPER_CONIFG_NEW_ALERT)
            {
                param.evtid = ANPC_MMI_EVT_CONIFG_NEW_ALERT_CNF;
            }
            else
            {
                param.evtid = ANPC_MMI_EVT_CONFIG_UNREAD_ALERT_CNF;
            }
            
            pAnpcCtx->oper = ANPC_OPER_IDLE;
            param.on_off = pAnpcCtx->on_off;
            anpc_app_cb(&param);
        }
 
        else
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_INVALID_UUID_IN_OPER, uuid, pAnpcCtx->oper);
        }
    }
    else
    {
      
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_DES_ERR_REG_CTX);
    }

}


static void anpc_execute_write_callback(gatt_conn_struct *conn, OS_STATUS status)
{
    // Not implement
}

void anpc_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret srv_anp_client_handle_disconnect(mmi_event_struct *para)
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
    	anpc_get_bd_addr(&remote_addr, evt->dev_addr);
        srv_anp_client_disconnect_req(&remote_addr);
  
    }
    
    return MMI_RET_OK;
}

static void srv_anp_client_init()
{
	mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, srv_anp_client_handle_disconnect, NULL);
    kal_mem_set(&apnc_srv_ctx, 0x0, sizeof(anpc_srv_cntx_struct));
}

// Anp profile init function. Init anp client and register MMI callback function to profile layer.
OS_ANPC_STATUS srv_anp_client_enable(anp_client_app_callback callback)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;

    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_ENABLE_ENTRY_STATE, pAnpcCtx->state);

    if ((pAnpcCtx->state == ANPC_STATE_DISABLED) && (callback != NULL))
    {
        srv_anp_client_init();

        pAnpcCtx->state = ANPC_STATE_ENABLING;
        
        kal_mem_set(&pAnpcCtx->app_uuid, 0x0, sizeof(bt_uuid_struct));
        pAnpcCtx->app_uuid.uu[0] = 'm';
        pAnpcCtx->app_uuid.uu[1] = 't';
        pAnpcCtx->app_uuid.uu[2] = 'k';
        pAnpcCtx->app_uuid.uu[3] = 'a';
        pAnpcCtx->app_uuid.uu[4] = 'n';
        pAnpcCtx->app_uuid.uu[5] = 'p';
        pAnpcCtx->app_uuid.uu[6] = 'a';
        pAnpcCtx->app_uuid.uu[7] = 'p';
        pAnpcCtx->app_uuid.uu[8] = 'p';

        pAnpcCtx->gatt_cb.register_client_cb = anpc_register_client_callback;
        pAnpcCtx->gatt_cb.listen_cb = anpc_listen_callback;
        pAnpcCtx->gatt_cb.scan_result_cb = NULL;
        pAnpcCtx->gatt_cb.search_complete_cb = anpc_search_complete_callback;
        pAnpcCtx->gatt_cb.search_result_cb = anpc_search_result_callback;
        pAnpcCtx->gatt_cb.get_characteristic_cb = anpc_get_characteristic_callback;
        pAnpcCtx->gatt_cb.get_descriptor_cb = anpc_get_descriptor_callback;
        pAnpcCtx->gatt_cb.connection_cb = anpc_connection_callback;
        pAnpcCtx->gatt_cb.get_included_service_cb = NULL;
        pAnpcCtx->gatt_cb.register_for_notification_cb = anpc_register_for_notification_callback;
        pAnpcCtx->gatt_cb.notify_cb = anpc_notify_callback;
        pAnpcCtx->gatt_cb.read_characteristic_cb = anpc_read_characteristic_callback;
        pAnpcCtx->gatt_cb.write_characteristic_cb = anpc_write_characteristic_callback;
        pAnpcCtx->gatt_cb.read_descriptor_cb = anpc_read_descriptor_callback;
        pAnpcCtx->gatt_cb.write_descriptor_cb = anpc_write_descriptor_callback;
        pAnpcCtx->gatt_cb.execute_write_cb = anpc_execute_write_callback;
        pAnpcCtx->gatt_cb.deregister_client_cb = NULL;

        pAnpcCtx->app_cb = callback;

        srv_gattc_register(&pAnpcCtx->app_uuid, &pAnpcCtx->gatt_cb);
        ret = OS_ANPC_STATUS_PENDING;
    }
    else
    {
        if (callback != NULL)
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_ALREADY_ENABLED);
            ret = OS_ANPC_STATUS_SUCCESS;
        }
        else
        {
           
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_ENABLE_FAILE_CB_IS_NULL);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }

    return ret;
}

// Anp profile deinit function.
void srv_anp_client_disable()
{
    
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_DISABLE_ENTRY_STATE, pAnpcCtx->state);

    if (pAnpcCtx->state == ANPC_STATE_DISABLED)
    {
        // Just return.
    }
    else
    {
        pAnpcCtx->app_cb = NULL;
        //srv_anp_client_disconnect_req(&pAnpcCtx->remote_addr);
        pAnpcCtx->state = ANPC_STATE_DISABLED;
        srv_gattc_deregister(pAnpcCtx->conn.reg_ctx);
    }
}

OS_ANPC_STATUS srv_anp_client_listen(BOOL start)
{
    OS_ANPC_STATUS ret = OS_ANPC_STATUS_FAILED;
   
    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_LISTEN_ENTRY, start);

    if (pAnpcCtx->state >= ANPC_STATE_ENABLED)
    {
        srv_gattc_listen(pAnpcCtx->conn.reg_ctx, start);
        ret = OS_ANPC_STATUS_PENDING;
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_LISTEN_FAILED_STATE, pAnpcCtx->state);
        ret = OS_ANPC_STATUS_FAILED;
    }
    
    return ret;
}


// Connect to ANP server using specified BT address.
OS_ANPC_STATUS srv_anp_client_connect_req(BD_ADDR* btaddr, BOOL direct)
{
    OS_ANPC_STATUS ret = OS_ANPC_STATUS_FAILED;
    BD_ADDR remote_addr = {0};

    if (btaddr != NULL)
    {
        

        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONNECT_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);

        if (pAnpcCtx->state = ANPC_STATE_ENABLED)
        {
            kal_mem_cpy(&pAnpcCtx->remote_addr, btaddr, BD_ADDR_SIZE);
            pAnpcCtx->state = ANPC_STATE_CONNECTING;
            pAnpcCtx->conn_init = TRUE;
            srv_gattc_connect(pAnpcCtx->conn.reg_ctx, &pAnpcCtx->remote_addr, direct);
            
            ret = OS_ANPC_STATUS_PENDING;
        }
        else if (pAnpcCtx->state > ANPC_STATE_ENABLED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                

                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);
                
                ret = OS_ANPC_STATUS_FAILED;
            }
            else if (pAnpcCtx->state == ANPC_STATE_DISCONNECTING)
            {
               
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_DISCONNECTING);
                ret = OS_ANPC_STATUS_FAILED;
            }
            else if (pAnpcCtx->state == ANPC_STATE_CONNECTING || pAnpcCtx->state == ANPC_STATE_SEARCHING)
            {
                
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONNECTING);
                ret = OS_ANPC_STATUS_PENDING;
            }
            else
            {
                
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONNECTED);
                ret = OS_ANPC_STATUS_SUCCESS;
            }
        }
        else
        {
           
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONNECT_FAILED_WITH_WRONG_STATE, pAnpcCtx->state);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONNECT_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }

    return ret;
}

// Disconnect the connection with specified ANP server.
OS_ANPC_STATUS srv_anp_client_disconnect_req(BD_ADDR* btaddr)
{
    OS_ANPC_STATUS ret = OS_ANPC_STATUS_FAILED;
    
    if (btaddr != NULL)
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_DISCONNECT_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);
            //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state >= ANPC_STATE_ENABLED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);

                ret = OS_ANPC_STATUS_FAILED;
            }
            //else if (pAnpcCtx->state == ANPC_STATE_DISCONNECTING)
           // {
            //    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_DISCONNECTING);
            //    ret = OS_ANPC_STATUS_PENDING;
           // }
            else
            {
                srv_gattc_disconnect(&pAnpcCtx->conn, btaddr);
                pAnpcCtx->state = ANPC_STATE_DISCONNECTING;
                ret = OS_ANPC_STATUS_PENDING;
            }        
        }
        else
        {
            ret = OS_ANPC_STATUS_SUCCESS;
        }
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_DISC_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }

    return ret;
}

/*
OS_ANPC_STATUS srv_anp_client_search_server_srv(BD_ADDR* btaddr)
{
    OS_ANPC_STATUS ret = OS_ANPC_STATUS_FAILED;
    bt_uuid_struct filter_uuid;
    
    if (btaddr != NULL)
    {
        kal_prompt_trace(MOD_BT, "[ANPC]search server srv. state:(%d), addr:(0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x)", pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);    
            //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr, &pAnpcCtx->remote_addr, sizeof(BD_ADDR)) != 0)
            {

                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {

                kal_mem_cpy(&anps_srv_uuid, &filter_uuid.uu, 16);

                srv_gattc_search_service(&pAnpcCtx->conn, &filter_uuid);
                pAnpcCtx->state = ANPC_STATE_SEARCHING;
                ret = OS_ANPC_STATUS_PENDING;
            }
        }
        else if(pAnpcCtx->state == ANPC_STATE_SEARCHING)
        {
            ret = OS_ANPC_STATUS_PENDING;
        }
        else
        {
            kal_prompt_trace(MOD_BT, "[ANPC]anp search srv failed. state is wrong(%d).", pAnpcCtx->state);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        kal_prompt_trace(MOD_BT, "[ANPC]anp search srv failed. addr is null.");
        ret = OS_ANPC_STATUS_FAILED;
    }

    return ret;

}
*/

// Read the supported new alert category from server.
OS_ANPC_STATUS srv_anp_client_read_supported_new_alert_category_req(BD_ADDR* btaddr)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;
    gattc_char_struct char_info;

    if (btaddr != NULL)
    {
      
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_READ_SUP_NEW_ALERT_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);

                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_IDLE)
                {
                    kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                    kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                    svc_uuid.is_primary = 1;
                    convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
                    convert_uuid16_to_array(NEW_ALERT_CATEGORY_U16, &chr_uuid);
                    pAnpcCtx->oper = ANPC_OPER_READ_NEW_ALERT;
                    //srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);
                    char_info.svc_uuid = &svc_uuid;
                    char_info.char_uuid = &chr_uuid;
                    srv_gattc_read_characteristic(&pAnpcCtx->conn, &char_info, GATTC_AUTH_REQ_NONE);
                    ret = OS_ANPC_STATUS_PENDING;
                }
                else
                {
                    
                    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_OPER_NOT_IDLE, pAnpcCtx->oper);
                    ret = OS_ANPC_STATUS_FAILED;
                }
            }        
        }
        else
        {
            
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_NOT_IN_CNN);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;
}

// Read the supported unread alert category from server.
OS_ANPC_STATUS srv_anp_client_read_supported_unread_alert_category_req(BD_ADDR* btaddr)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;
    gattc_char_struct char_info;

    if (btaddr != NULL)
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_READ_SUP_UNREAD_ALERT_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);

                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_IDLE)
                {            
                    kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                    kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                    svc_uuid.is_primary = 1;
                    convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
                    convert_uuid16_to_array(UNREAD_ALERT_CATEGORY_U16, &chr_uuid);
                    pAnpcCtx->oper = ANPC_OPER_READ_UNREAD_ALERT;
                    //srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);
                    char_info.svc_uuid = &svc_uuid;
                    char_info.char_uuid = &chr_uuid;
                    srv_gattc_read_characteristic(&pAnpcCtx->conn, &char_info, GATTC_AUTH_REQ_NONE);
                    ret = OS_ANPC_STATUS_PENDING;
                }
                else
                {
                    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_OPER_NOT_IDLE, pAnpcCtx->oper);
                    ret = OS_ANPC_STATUS_FAILED;
                }
            }        
        }
        else
        {
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_NOT_IN_CNN);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;

}

static BOOL anp_client_is_valid_control_point_cmd(U16 cmd)
{
    BOOL ret = FALSE;

    switch (cmd)
    {
    case CMD_ENABLE_NEW_ALERT:
    case CMD_ENABLE_UNREAD_ALERT:
    case CMD_DISABLE_NEW_ALERT:
    case CMD_DISABLE_UNREAD_ALERT:
    case CMD_NOTIFY_NEW_ALERT_IMM:
    case CMD_NOTIFY_UNREAD_ALERT_IMM:
        ret = TRUE;
        break;
    default:
        ret = FALSE;
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_UNKNOW_CP_CMD, cmd);
        break;
    }

    return ret;
}

OS_ANPC_STATUS srv_anp_client_wirte_control_point(BD_ADDR* btaddr, U16 cmd, kal_uint8 category_id)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;
    gattc_char_struct char_info;
    ATT_VALUE value;

    if (btaddr != NULL)
    {
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_CP_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);
       
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_WRITE_CP_REQ_CMD, cmd, category_id);
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);

                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_IDLE)
                {            
                    if (anp_client_is_valid_control_point_cmd(cmd) == TRUE)
                    {
                        kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                        kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                        kal_mem_set(&char_info, 0x0, sizeof(gattc_char_struct));
                        kal_mem_set(&value, 0x0, sizeof(ATT_VALUE));
                        svc_uuid.is_primary = 1;
                        convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
                        convert_uuid16_to_array(ALERT_CONTROL_POINT_U16, &chr_uuid);
                        pAnpcCtx->cp_cmd = cmd;
                        pAnpcCtx->oper = ANPC_OPER_WRITE_CONTROL_POINT_REQ;
                        pAnpcCtx->category_id = category_id;
                        //srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);

                        value.value[0] = (U8)cmd;
                        value.value[1] = pAnpcCtx->category_id;
                        value.len = 2;

                        char_info.svc_uuid = &svc_uuid;
                        char_info.char_uuid = &chr_uuid;
                        srv_gattc_write_characteristic(&pAnpcCtx->conn, &char_info, &value, GATTC_WRITE_TYPE_REQUEST, GATTC_AUTH_REQ_NONE);
                        ret = OS_ANPC_STATUS_PENDING;
                    }
                }
                else
                {
                    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_OPER_NOT_IDLE, pAnpcCtx->oper);
                    ret = OS_ANPC_STATUS_FAILED;
                }
            }        
        }
        else
        {
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_NOT_IN_CNN);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;

}

static void srv_anp_client_deregister_notification(BD_ADDR* btaddr)
{
	gattc_char_struct	char_info;
	GATT_SVC_UUID	svc_uuid;
	ATT_UUID		chr_uuid;

	kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
	kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
						   
	svc_uuid.is_primary = 1;
	convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
	char_info.svc_uuid = &svc_uuid;
	//deresister all notification
	{  
	    convert_uuid16_to_array(NEW_ALERT_U16, &chr_uuid);		
		char_info.char_uuid = &chr_uuid;
		srv_gattc_deregister_for_notification(pAnpcCtx->conn.reg_ctx, btaddr, &char_info);
	}
	{
		convert_uuid16_to_array(UNREAD_ALERT_U16, &chr_uuid);
		char_info.char_uuid = &chr_uuid;
		srv_gattc_deregister_for_notification(pAnpcCtx->conn.reg_ctx, btaddr, &char_info);
	}

}

OS_ANPC_STATUS srv_anp_client_configure_alert(BD_ADDR* btaddr, U16 oper, U8 on_off)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;
    gattc_char_struct   char_info;

    if (btaddr != NULL)
    {
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONFIG_ALERT_REQ_STATE, pAnpcCtx->state, 
            btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);
        
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_CONFIG_ALERT_REQ_OPER, oper, on_off);
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr->addr, pAnpcCtx->remote_addr.addr, BD_ADDR_SIZE) != 0)
            {
                MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_CONN_OTHER_DEV,
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);

                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                if (pAnpcCtx->oper == ANPC_OPER_IDLE)
                {            
                    if (oper == ANPC_OPER_CONIFG_NEW_ALERT || oper == ANPC_OPER_CONFIG_UNREAD_ALERT)
                    {
                        kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                        kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                        
                        svc_uuid.is_primary = 1;
                        convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);

                        if (oper == ANPC_OPER_CONIFG_NEW_ALERT)
                        {
                            convert_uuid16_to_array(NEW_ALERT_U16, &chr_uuid);
                        } 
                        else if (oper == ANPC_OPER_CONFIG_UNREAD_ALERT)
                        {
                            convert_uuid16_to_array(UNREAD_ALERT_U16, &chr_uuid);
                        }

                        pAnpcCtx->oper = oper;
                        pAnpcCtx->on_off = on_off;
                        //srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);

                        char_info.svc_uuid = &svc_uuid;
                        char_info.char_uuid = &chr_uuid;

                        if (pAnpcCtx->on_off == ANPC_CONFIG_ALERT_ON)
                        {
                            srv_gattc_register_for_notification(pAnpcCtx->conn.reg_ctx, btaddr, &char_info);
                        }
                        else
                        {
                            srv_gattc_deregister_for_notification(pAnpcCtx->conn.reg_ctx, btaddr, &char_info);
                        }

                        ret = OS_ANPC_STATUS_PENDING;
                    }
                }
                else
                {
                    MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_OPER_NOT_IDLE, pAnpcCtx->oper);
                    ret = OS_ANPC_STATUS_FAILED;
                }
            }        
        }
        else
        {
            MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_NOT_IN_CNN);
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        MMI_TRACE(SRV_ANPC_TRACE_GROUP, TRC_SRV_ANPC_OPER_FAILED_ADDR_IS_NULL);
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;

}

/*
// Request to notify when new alert count changes.
OS_ANPC_STATUS srv_anp_client_active_new_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;

    if (btaddr != NULL)
    {
        kal_prompt_trace(MOD_BT, "[ANPC]active new alert req. state:(%d), addr:(0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x)", pAnpcCtx->state, 
             btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);    
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr, &pAnpcCtx->remote_addr, sizeof(BD_ADDR)) != 0)
            {
                kal_prompt_trace(MOD_BT, "[ANPC]active failed.Current cnn with (0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x)",
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);
                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                svc_uuid.is_primary = 1;
                convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
                convert_uuid16_to_array(NEW_ALERT_U16, &chr_uuid);
                pAnpcCtx->oper |= ANPC_OEPR_ACTIVE_NEW_ALERT;
                srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);
                ret = OS_ANPC_STATUS_PENDING;
            }        
        }
        else
        {
            kal_prompt_trace(MOD_BT, "[ANPC]active failed. Not in connection.");
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        kal_prompt_trace(MOD_BT, "[ANPC]active failed. addr is null.");
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;

}

// Request to notify when unread alert status changes.
OS_ANPC_STATUS srv_anp_client_active_unread_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
    OS_ANPC_STATUS  ret = OS_ANPC_STATUS_FAILED;
    GATT_SVC_UUID   svc_uuid;
    ATT_UUID        chr_uuid;

    if (btaddr != NULL)
    {
        kal_prompt_trace(MOD_BT, "[ANPC]active unread alert req. state:(%d), addr:(0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x)", pAnpcCtx->state, 
             btaddr->addr[5], btaddr->addr[4], btaddr->addr[3], btaddr->addr[2], btaddr->addr[1], btaddr->addr[0]);    
             //void srv_gattc_disconnect(gatt_conn_struct *conn, BD_ADDR *bd_addr));
        if (pAnpcCtx->state == ANPC_STATE_CONNECTED)
        {
            if (kal_mem_cmp(btaddr, &pAnpcCtx->remote_addr, sizeof(BD_ADDR)) != 0)
            {
                kal_prompt_trace(MOD_BT, "[ANPC]active failed.Current cnn with (0x%2x:0x%2x:0x%2x:0x%2x:0x%2x:0x%2x)",
                    pAnpcCtx->remote_addr.addr[5], pAnpcCtx->remote_addr.addr[4], pAnpcCtx->remote_addr.addr[3], 
                    pAnpcCtx->remote_addr.addr[2], pAnpcCtx->remote_addr.addr[1], pAnpcCtx->remote_addr.addr[0]);
                ret = OS_ANPC_STATUS_FAILED;
            }
            else
            {
                kal_mem_set(&svc_uuid, 0x0, sizeof(GATT_SVC_UUID));
                kal_mem_set(&chr_uuid, 0x0, sizeof(ATT_UUID));
                svc_uuid.is_primary = 1;
                convert_uuid16_to_array(ALERT_NOTIFICATION_U16, &svc_uuid.uuid);
                convert_uuid16_to_array(UNREAD_ALERT_U16, &chr_uuid);
                pAnpcCtx->oper |= ANPC_OEPR_ACTIVE_UNREAD_ALERT;
                srv_gattc_get_characteristic(&pAnpcCtx->conn, &svc_uuid, &chr_uuid);
                ret = OS_ANPC_STATUS_PENDING;
            }        
        }
        else
        {
            kal_prompt_trace(MOD_BT, "[ANPC]active failed. Not in connection.");
            ret = OS_ANPC_STATUS_FAILED;
        }
    }
    else
    {
        kal_prompt_trace(MOD_BT, "[ANPC]active failed. addr is null.");
        ret = OS_ANPC_STATUS_FAILED;
    }
    return ret;

}

// Request to disable specific new alert count changes notify.
OS_ANPC_STATUS anp_client_disable_new_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
}

OS_ANPC_STATUS anp_client_disable_unread_alert_notify_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
}

// Request the server to notify specific new alert immediately.
OS_ANPC_STATUS anp_client_notify_new_alert_immediately_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
}

// Request the server to notify specific unread alert status immediately.
OS_ANPC_STATUS anp_client_notify_new_unread_immediately_req(BD_ADDR* btaddr, kal_uint8 category_id)
{
}
*/
#endif /* __BT_GATTC_PROFILE__ */

