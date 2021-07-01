
/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  PdmsSrv.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file defines the SAP of the Pedometer Profile.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "MMI_features.h"

#ifdef __MMI_BLE_PDMS_SUPPORT__ 

#include "DebugInitDef_Int.h"
#include "PdmsSrvGprot.h"
#include "PdmsSrv.h"
#include "Pdms_def.h"
#include "Kal_trace.h"

/*UT*/
#include "BtcmSrvGprot.h"
#include "MMI_trc_Int.h"
#include "MMI_conn_app_trc.h"
#include "mmi_cb_mgr_gprot.h"
#include "mmi_rp_srv_blecm_def.h"
#include "blesrvgprot.h" // srv_ble_cm_get_connected_dev_num

static BtStatus pdms_disconnect_event_handler(BD_ADDR *bdaddr);
static void pdms_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src);
static mmi_ret pdms_recv_event_handler(mmi_event_struct *evt);

PdmsCntx  g_pdms_cntx = {0};
U8        g_pdms_uuid[] = {
	0x18, 0xAA, 0x1F, 0x49, 0xFF, 0xE5, 0x40, 0x56,
	0X84, 0x5B, 0x6D, 0xF1, 0xF1, 0xB1, 0x6E, 0x9D
};
gatts_callback_struct g_pdms_cb = {
	pdms_register_server_callback,
    pdms_connection_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
	pdms_service_started_callback,
	NULL,
	NULL,
	pdms_request_read_callback,
	pdms_request_write_callback,
	NULL,
	NULL,
	NULL,
	NULL,
	NULL,
};
gatts_factory_callback_struct g_pdms_factory_cb = {
	NULL,
	NULL,
	pdms_add_services_callback,
	NULL,
};


/*UT*/
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
/*UT end*/


int pdms_find_uuid_by_handle(ATT_HANDLE att_handle, ATT_UUID *svc_uuid, ATT_UUID *chr_uuid)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_pdms_cntx.srv_list.srvlist);

	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_find_uuid_by_handle %x!\n", att_handle);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_FIND_UUID_BY_HANDLE, att_handle);
	if (mmi_IsListEmpty(&g_pdms_cntx.srv_list.srvlist))
	{
		return TYPE_UNKNOW;
	}

    if (att_handle == 0)
	{
	     return TYPE_UNKNOW;
	}
    
	while ((ListEntry *)svc_list != &g_pdms_cntx.srv_list.srvlist)
	{
		if (svc_list->handle == att_handle)
		{
			//kal_prompt_trace(MOD_BT, "[PDMS] svc_list->type %d!\n", svc_list->type);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_FIND_UUID_TYPE, svc_list->type);
			switch(svc_list->type)
			{
				case TYPE_SERVICE:
					memcpy(svc_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					return TYPE_SERVICE;
				case TYPE_CHARACTERISTIC:
					memcpy(chr_uuid, &svc_list->uuid, sizeof(ATT_UUID));
					pdms_find_uuid_by_handle(svc_list->srvhandle, svc_uuid, chr_uuid);
					return TYPE_CHARACTERISTIC;
				default:
					return svc_list->type;
			}
		}
			
		svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
	}
	return TYPE_UNKNOW;
}

void pdms_request_read_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                      ATT_HANDLE attr_handle, U16 offset, BOOL is_long)
{
	PdmsConnCntx    *pConnNode = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = pdms_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              uuid = convert_array_to_uuid16(chr_uuid);
	ATT_VALUE        att_value;
    S32 ret_val;
#if 0
/* under construction !*/
/* under construction !*/
#endif
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_READ_CB, attr_handle, type, uuid, offset, is_long);
   
	if(type == TYPE_CHARACTERISTIC)
	{	
            if(uuid == PDMS_CHAR_UUID)
            {
                if(g_pdms_cntx.callback)
                {                   
                    ret_val = g_pdms_cntx.callback->read_data_request_cb(bd_addr->addr, &(att_value.value[offset]), (PDMS_MAX_VALUE_LEN - offset) );
                    if(ret_val >0 )
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
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_request_read_callback -!\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_READ_CB_END);
	
}

void pdms_register_server_callback(void *reg_ctx, OS_STATUS status, bt_uuid_struct *app_uuid)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_REGISTER_CB, status, g_pdms_cntx.state, g_pdms_cntx.op_flag);
	if (memcmp(app_uuid, &g_pdms_cntx.uid, sizeof(bt_uuid_struct)) == 0)
	{
		if (g_pdms_cntx.state == PDMS_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				g_pdms_cntx.reg_ctx = reg_ctx;
				if (g_pdms_cntx.op_flag == PDMS_OP_INIT)
				{
					g_pdms_cntx.op_flag = PDMS_OP_ADD_SERVICE;
					#ifndef PDMS_UT
					srv_gatts_profile_factory_get_services(g_pdms_cntx.reg_ctx, PROFILE_ID_PEDOMETER, &g_pdms_cntx.srv_list);
					srv_gatts_profile_factory_add_services(g_pdms_cntx.reg_ctx, &g_pdms_cntx.srv_list);
					#endif
				}
			}
			else
			{
				g_pdms_cntx.reg_ctx = NULL;
				g_pdms_cntx.callback = NULL;
				g_pdms_cntx.op_flag = PDMS_OP_DEINIT;
				g_pdms_cntx.state = PDMS_STATUS_DISABLED;
			}
		}
		else if (g_pdms_cntx.state == PDMS_STATUS_DISABLING)
		{	
			if (g_pdms_cntx.op_flag == PDMS_OP_INIT)
			{
				g_pdms_cntx.state = PDMS_STATUS_ENABLING;
				#ifndef PDMS_UT
				srv_gatts_profile_factory_register(&g_pdms_cntx.uid, &g_pdms_cb, &g_pdms_factory_cb);
				#endif
			}
			else
			{
				g_pdms_cntx.reg_ctx = NULL;
				g_pdms_cntx.callback = NULL;
				g_pdms_cntx.op_flag = PDMS_OP_DEINIT;
				g_pdms_cntx.state = PDMS_STATUS_DISABLED;
			}
		}
	}
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_register_server_callback -!\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_REGISTER_CB_END);
}

void pdms_connection_callback(gatt_conn_struct *conn, BOOL connected, BD_ADDR *bd_addr)
{
	PdmsConnCntx    *pConnNode = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);
	PdmsConnCntx    *pConnNext = NULL;

	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_connection_callback connected %d!\n", connected);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_CONNECT_CB, connected);
	//if (!mmi_IsListEmpty(&g_pdms_cntx.conn_list))
	//{
		while ((ListEntry *)pConnNode != &g_pdms_cntx.conn_list)
		{
			pConnNext = (PdmsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
			if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
			{
				//kal_prompt_trace(MOD_BT, "[PDMS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_FIND_IN_LIST);
				pConnNode->conn_ctx = conn->conn_ctx;
				if (connected && (pConnNode->conn_status != PDMS_STATUS_CONNECTED))
				{
					//do next step Discovery all
					#ifndef PDMS_UT
					if (SRV_PDMS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
	                {
					srv_gatts_listen(conn->reg_ctx, FALSE);
	                }
	                //srv_gatts_listen(conn->reg_ctx, FALSE);
					//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
					#endif
					pConnNode->conn_status = PDMS_STATUS_CONNECTED;
					if (g_pdms_cntx.callback != NULL)
						g_pdms_cntx.callback->connection_state_cb(bd_addr->addr, PDMS_STATUS_CONNECTED);
				}
				else if (!connected)
				{
					#ifndef PDMS_UT
					srv_gatts_listen(conn->reg_ctx, TRUE);
					#endif
					mmi_RemoveEntryList(&pConnNode->conn_node);
					free_ctrl_buffer(pConnNode);
					if (g_pdms_cntx.callback != NULL)
						g_pdms_cntx.callback->connection_state_cb(bd_addr->addr, PDMS_STATUS_DISCONNECTED);
				}
				return;
			}
			pConnNode = pConnNext;
		}
	//}
	//else
	//{
		if (connected)
		{
			//kal_prompt_trace(MOD_BT, "[PDMS] not find in list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_NOT_FIND_IN_LIST);
			pConnNode = (PdmsConnCntx *)get_ctrl_buffer(sizeof(PdmsConnCntx));
			memcpy(pConnNode->bdaddr, bd_addr->addr, BD_ADDR_SIZE);
			pConnNode->conn_ctx = conn->conn_ctx;
			#ifndef PDMS_UT
			if (SRV_PDMS_MAX_DEV == srv_ble_cm_get_connected_dev_num())
	            {
					srv_gatts_listen(conn->reg_ctx, FALSE);
	            }
			//srv_gatts_listen(conn->reg_ctx, FALSE);
			//srv_gatts_connect(conn->reg_ctx, bd_addr, FALSE);
			#endif
			pConnNode->conn_status = PDMS_STATUS_CONNECTED;
			mmi_InsertTailList(&g_pdms_cntx.conn_list, &pConnNode->conn_node);
			if (g_pdms_cntx.callback != NULL)
				g_pdms_cntx.callback->connection_state_cb(bd_addr->addr, PDMS_STATUS_CONNECTED);
		}
	//}
}

void pdms_request_write_callback(gatt_conn_struct *conn, U16 trans_id, BD_ADDR *bd_addr,
                                     ATT_HANDLE attr_handle, ATT_VALUE *value, U16 offset,
                                     BOOL need_rsp, BOOL is_prep)
{
	PdmsConnCntx    *pConnNode = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);
	ATT_UUID         svc_uuid;
	ATT_UUID         chr_uuid;
	int              type = pdms_find_uuid_by_handle(attr_handle, &svc_uuid, &chr_uuid);
	U16              svc_uuid16 = convert_array_to_uuid16(svc_uuid);
	U16              chr_uuid16 = convert_array_to_uuid16(chr_uuid);
    S32 ret_val = 0;
	#if 0
/* under construction !*/
/* under construction !*/
	#endif
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_WRITE_CB, attr_handle, svc_uuid16, chr_uuid16);

	if (mmi_IsListEmpty(&g_pdms_cntx.conn_list))
	{
		//kal_prompt_trace(MOD_BT, "[PDMS] pdms_request_write_callback doesn't connected!\n");
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_CONNECT_FAIL);
		return;
	}
	while ((ListEntry *)pConnNode != &g_pdms_cntx.conn_list)
	{
		if (memcmp(bd_addr->addr, pConnNode->bdaddr, BD_ADDR_SIZE) == 0)
		{
		#if 0
/* under construction !*/
/* under construction !*/
		#endif	
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_WRITE_VALUE, value->value[offset], 
				value->len, offset, need_rsp, is_prep);                 
			if (svc_uuid16 == PDMS_SERVICE && chr_uuid16 == PDMS_CHAR_UUID)
			{
				if (g_pdms_cntx.callback)
				{                   
					ret_val = g_pdms_cntx.callback->data_to_read_notify_cb(bd_addr->addr, &(value->value[offset]), value->len);
					if (ret_val !=0)
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
		pConnNode = (PdmsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
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
void pdms_service_started_callback(OS_STATUS status, void *reg_ctx,
                                         ATT_HANDLE srvc_handle)
{
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_SERVICE_START_CB, status, srvc_handle);
	if (status == OS_STATUS_SUCCESS)
	{
		srv_gatts_listen(reg_ctx, TRUE);
	}
}


void pdms_add_services_callback(OS_STATUS status, void *reg_ctx)
{
	gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_pdms_cntx.srv_list.srvlist);
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_SERVICE_ADD_CB, status, g_pdms_cntx.state, g_pdms_cntx.op_flag);
	if (g_pdms_cntx.reg_ctx == reg_ctx)
	{
		if (g_pdms_cntx.state == PDMS_STATUS_ENABLING)
		{	
			if (status == OS_STATUS_SUCCESS)
			{
				if (g_pdms_cntx.op_flag == PDMS_OP_ADD_SERVICE)
				{
					if (mmi_IsListEmpty(&g_pdms_cntx.srv_list.srvlist))
					{
						//kal_prompt_trace(MOD_BT, "[PDMS] is empty service list!\n");
						MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_LIST_EMPTY);
						return;
					}
					while ((ListEntry *)svc_list != &g_pdms_cntx.srv_list.srvlist)
					{
						if (svc_list->type == TYPE_SERVICE)
						{
							#ifndef PDMS_UT
							srv_gatts_start_service(reg_ctx, svc_list->handle, GATT_TRANSPORT_LE);
							#endif
						}
						svc_list = (gatts_service_decl_struct *)mmi_GetNextNode(&svc_list->declnode);
					}
					g_pdms_cntx.state = PDMS_STATUS_ENABLED;
				}
			}
			else
			{
				pdms_deinit();
			}
		}	
		
	}
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_add_services_callback -!\n");
}


S32 pdms_init(pdms_callback_t *cb)
{
	BtStatus status = BT_STATUS_SUCCESS;
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_INIT, g_pdms_cntx.state, g_pdms_cntx.op_flag);
	mmi_frm_cb_reg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, pdms_recv_event_handler, NULL);
	if (g_pdms_cntx.state == PDMS_STATUS_DISABLED)
	{
		g_pdms_cntx.state = PDMS_STATUS_ENABLING;
		g_pdms_cntx.op_flag = PDMS_OP_INIT;
		g_pdms_cntx.callback = cb;
		memcpy(g_pdms_cntx.uid.uu, &g_pdms_uuid, sizeof(bt_uuid_struct));
		mmi_InitializeListHead(&g_pdms_cntx.conn_list);
		#ifndef PDMS_UT
		srv_gatts_profile_factory_register(&g_pdms_cntx.uid, &g_pdms_cb, &g_pdms_factory_cb);
		#endif
	}
	else if (g_pdms_cntx.state == PDMS_STATUS_DISABLING)
	{
		if(g_pdms_cntx.op_flag == PDMS_OP_DEINIT)
		{
			g_pdms_cntx.op_flag = PDMS_OP_INIT;
		}
		g_pdms_cntx.callback = cb;
		memcpy(g_pdms_cntx.uid.uu, &g_pdms_uuid, sizeof(bt_uuid_struct));
	}
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_init -!\n");
	return status;
}

S32 pdms_deinit()
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	PdmsConnCntx    *pConnCur = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);
	PdmsConnCntx    *pConnNext = NULL;
#if 0
/* under construction !*/
/* under construction !*/
#endif	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_DEINIT, g_pdms_cntx.state, g_pdms_cntx.op_flag);
	if ((g_pdms_cntx.state == PDMS_STATUS_DISABLED)
		|| (g_pdms_cntx.state == PDMS_STATUS_DISABLING))
		return BT_STATUS_SUCCESS;
	#ifndef PDMS_UT
	//srv_gatts_listen(g_pdms_cntx.reg_ctx, FALSE);
	#endif
	if (g_pdms_cntx.state == PDMS_STATUS_ENABLED)
	{
		if (mmi_IsListEmpty(&g_pdms_cntx.conn_list))
		{
			//kal_prompt_trace(MOD_BT, "[PDMS] is empty connection list!\n");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_LIST_EMPTY);
			goto do_deinit;
		}
		
        while ((ListEntry *)pConnCur != &g_pdms_cntx.conn_list)
		{
			pConnNext = (PdmsConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
			gatt_conn.reg_ctx = g_pdms_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if((pConnCur->conn_status == PDMS_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == PDMS_STATUS_CONNECTING))
			{
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				#ifndef PDMS_UT
				//srv_gatts_disconnect(&gatt_conn, &bd_addr);
				#endif

                if(g_pdms_cntx.callback != NULL)
					g_pdms_cntx.callback->connection_state_cb(bd_addr.addr, PDMS_STATUS_DISCONNECTED);
			}
			mmi_RemoveEntryList(&pConnCur->conn_node);
			free_ctrl_buffer(pConnCur);
			pConnCur = pConnNext;
		}
	}
	
do_deinit:
	#ifndef PDMS_UT
	srv_gatts_profile_factory_delete_services(g_pdms_cntx.reg_ctx, &g_pdms_cntx.srv_list);
	srv_gatts_profile_factory_clear_services(g_pdms_cntx.reg_ctx, &g_pdms_cntx.srv_list);
	srv_gatts_profile_factory_deregister(g_pdms_cntx.reg_ctx);
	#endif
	mmi_frm_cb_dereg_event(SRV_LE_CM_EVENT_DISCONNECT_REQ, pdms_recv_event_handler, NULL);
	g_pdms_cntx.state = PDMS_STATUS_DISABLED;
	g_pdms_cntx.op_flag = PDMS_OP_DEINIT;
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_deinit -!\n");
	return BT_STATUS_SUCCESS;
}

S32 pdms_send_data(char* bdaddr,void* buf, U32 len, S32 *err_code)
{
    gatts_service_decl_struct *svc_list = (gatts_service_decl_struct *)mmi_GetHeadList(&g_pdms_cntx.srv_list.srvlist);
    PdmsConnCntx    *pConnNode = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);
    PdmsConnCntx    *pConnNext = NULL;
    gatt_conn_struct gatt_conn;
    ATT_VALUE *att_value = NULL;
    ATT_UUID         svc_uuid;
    ATT_UUID         chr_uuid;
    int type;
    U16  svc_uuid16;
    U16  chr_uuid16;
    U32 send_size = 0; 
    
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_SEND_DATA, buf, len);
    //kal_prompt_trace(MOD_BT, "[PDMS] pdms_send_data buf:%x, size:%d !\n", buf, len);

    if (buf == NULL)
    {
        *err_code = -1;
        return 0;
    }
       
    if (!mmi_IsListEmpty(&g_pdms_cntx.conn_list))
    {
        while ((ListEntry *)pConnNode != &g_pdms_cntx.conn_list)
        {
            pConnNext = (PdmsConnCntx *)mmi_GetNextNode(&pConnNode->conn_node);
            if (pConnNode->conn_status == PDMS_STATUS_CONNECTED )
            {
                //kal_prompt_trace(MOD_BT, "[PDMS] find in list!\n");
				MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_FIND_IN_LIST);
                gatt_conn.reg_ctx = g_pdms_cntx.reg_ctx;
                gatt_conn.conn_ctx = pConnNode->conn_ctx;

                while ((ListEntry *)svc_list != &g_pdms_cntx.srv_list.srvlist)
                {          

                    //kal_prompt_trace(MOD_BT, "[PDMS] find in list!\n");
					MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_FIND_IN_LIST);
                    if (svc_list->type == TYPE_CHARACTERISTIC)
                    {
                         
                        type = pdms_find_uuid_by_handle(svc_list->handle, &svc_uuid, &chr_uuid);   
                        if (type != TYPE_CHARACTERISTIC)
                        {
                            *err_code = -3;
                            break;                          
                        }
                         
                        svc_uuid16 = convert_array_to_uuid16(svc_uuid);
                        chr_uuid16 = convert_array_to_uuid16(chr_uuid);
                        if (chr_uuid16 == PDMS_CHAR_UUID)
                        {  
                            send_size = len;
                            if (len > PDMS_MAX_VALUE_LEN)
                            {
                                len = PDMS_MAX_VALUE_LEN;
                            }
                             
                            att_value = (ATT_VALUE *)get_ctrl_buffer(sizeof(ATT_VALUE));
                            memcpy(att_value->value, buf, len);
                            att_value->len = len;
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
BtStatus pdms_disconnect_event_handler(BD_ADDR *bdaddr)
{
	gatt_conn_struct gatt_conn;
	BD_ADDR          bd_addr;
	PdmsConnCntx    *pConnCur = (PdmsConnCntx *)mmi_GetHeadList(&g_pdms_cntx.conn_list);

	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_disconnect_event_handler !\n");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_DISCONN_EVENT_HANDLER);
	if ((g_pdms_cntx.state == PDMS_STATUS_DISABLED)
		|| (g_pdms_cntx.state == PDMS_STATUS_DISABLING))
		return BT_STATUS_FAILED;

    while ((ListEntry *)pConnCur != &g_pdms_cntx.conn_list)
	{
		//kal_prompt_trace(MOD_BT, "[PDMS] pdms_disconnect_event_handler pConnCur->bdaddr %s!\n",pConnCur->bdaddr);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_DISCONN_EVENT_ADDR, pConnCur->bdaddr);
	    if (memcmp(bdaddr->addr, pConnCur->bdaddr, BD_ADDR_SIZE) == 0)
	    {
			//kal_prompt_trace(MOD_BT, "[PDMS] find in list conn_status %d !\n", pConnCur->conn_status);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_DISCONN_EVENT_STATUS, pConnCur->conn_status);
			gatt_conn.reg_ctx = g_pdms_cntx.reg_ctx;
			gatt_conn.conn_ctx = pConnCur->conn_ctx;
			if ((pConnCur->conn_status == PDMS_STATUS_CONNECTED) 
				|| (pConnCur->conn_status == PDMS_STATUS_CONNECTING))
			{
				pConnCur->conn_status = PDMS_STATUS_DISCONNECTING;
				memcpy(bd_addr.addr, pConnCur->bdaddr, BD_ADDR_SIZE);
				srv_gatts_disconnect(&gatt_conn, &bd_addr);
				if(g_pdms_cntx.callback != NULL)
					g_pdms_cntx.callback->connection_state_cb(bd_addr.addr, PDMS_STATUS_DISCONNECTED);
				//kal_prompt_trace(MOD_BT, "[PDMS] pdms_disconnect_event_handler disconnected 1!\n");
				return BT_STATUS_SUCCESS;
			}
			else if ((pConnCur->conn_status == PDMS_STATUS_DISCONNECTED) 
				|| (pConnCur->conn_status == PDMS_STATUS_DISCONNECTING))
			{
				if(g_pdms_cntx.callback != NULL)
					g_pdms_cntx.callback->connection_state_cb(pConnCur->bdaddr, PDMS_STATUS_DISCONNECTED);
				//kal_prompt_trace(MOD_BT, "[PDMS] pdms_disconnect_event_handler disconnected 2!\n");
				return BT_STATUS_SUCCESS;
			}			
			break;	
		}
		pConnCur = (PdmsConnCntx *)mmi_GetNextNode(&pConnCur->conn_node);
	}
	return BT_STATUS_FAILED;
}

void pdms_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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

mmi_ret pdms_recv_event_handler(mmi_event_struct *evt)
{
    srv_le_cm_evt_disconnect_struct *disconn_data = (srv_le_cm_evt_disconnect_struct *)evt;
	//kal_prompt_trace(MOD_BT, "[PDMS] pdms_recv_event_handler evt->evt_id %d!\n",evt->evt_id);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_RECV_EVENT_HANDLER, evt->evt_id);
	    
    if ( evt->evt_id == SRV_LE_CM_EVENT_DISCONNECT_REQ ) 
    {
        BD_ADDR remote_addr;
		pdms_get_bd_addr(&remote_addr,disconn_data->dev_addr);
		pdms_disconnect_event_handler(&remote_addr);
		//kal_prompt_trace(MOD_BT, "[PDMS] pdms_recv_event_handler remote_addr %s!\n",remote_addr.addr);
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_PDMS_RECV_EVENT_ADDR, remote_addr.addr);
    }
    return MMI_RET_OK;
}
#endif  /* __MMI_BLE_PDMS_SUPPORT__ */
