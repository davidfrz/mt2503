/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * Btmapc_srv.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for bluetooth map client profile and used by any application
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *-------------------------------------------------------------------------------------------*/


#include "MMI_features.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "app_ltlcom.h"
#include "MMIDataType.h"
#include "mmi_frm_events_gprot.h"
#include "Mmi_frm_mem_gprot.h"
#include "QueueGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "MapcSrv.h"
#endif
#include "Bluetooth_map_struct.h"
#include "DebugInitDef_Int.h"
#include "BTMMIScrGprots.h"
#include "MapcSrvAdap.h"
#include "BtCmSrvGprot.h"
#include "BTNotiSrvGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__

#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__) 
extern srv_mapc_adp_cntx_struct g_mapc_adp_cntx[MAX_MAPC_LINK_SUPPORT];
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)*/

srv_map_client_cntx_struct g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT];
S8 g_gmap_cur_index = -1;
srv_bt_cm_bt_addr g_map_dev_addr = {0};
#ifdef __MMI_WEARABLE_DEVICE__
srv_bt_cm_bt_addr g_map_cur_noti_dev_addr = {0};
srv_bt_cm_bt_addr g_map_cur_map_dev_addr = {0};
#endif /*__MMI_WEARABLE_DEVICE__*/

#define MMI_MAPC_STATE_TRANS(i, x)  \
{                                \
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_STATE_CHANGE,g_gmap_client_cntx[i].state,x);\
    g_gmap_client_cntx[i].state = (x);  \
}

typedef void (*srv_bt_mapc_notify_cb)(S32 srv_hd, srv_bt_mapc_cbevent_enum event, void* para);

void srv_bt_mapc_get_message_listing(U8 cntx_index, U8 *child_folder);
#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__IOT__)
extern void mmi_bt_dialor_callback(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL result,MMI_BOOL is_connect, MMI_BOOL is_indicate);
#endif
void srv_bt_mapc_connect_cnf(void *msg);
void srv_mapc_activate_cnf(void *msg);
void srv_mapc_deactivate_cnf(void *msg);
void srv_mapc_disconnect_ex(U8 cntx_index, void *user_data);
void srv_bt_mapc_disconnect_cnf(void *msg);
void srv_bt_mapc_set_notify_registration_cnf(void *msg);

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_cur_order_index
 * DESCRIPTION
 * response 
 * PARAMETERS
 * bt_addr
 * mas_id
 * RETURNS
 *  U8
 *****************************************************************************/
void srv_bt_mapc_set_cur_order_index(srv_bt_mapc_bt_enum index_order)
{
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	 MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_SET_CUR_INDEX, index_order);
	 
	 if(index_order >= SRV_BT_MAPC_BT_INDEX2)
		g_gmap_cur_index = -1;
	 else
		g_gmap_cur_index = (S8)index_order;	
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_bt_info_by_idx
 * DESCRIPTION
 * response 
 * PARAMETERS
 * bt_addr
 * mas_id
 * RETURNS
 *  U8
 *****************************************************************************/
S32 srv_bt_mapc_get_bt_addr_by_idx(srv_bt_cm_bt_addr *bt_addr, srv_bt_mapc_bt_enum index_order)
{		 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_cm_bt_addr *btd = NULL;
	S32 ret = SRV_BT_MAPC_SUCCESS;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[0].bd_addr);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].bd_addr);
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_GET_ADDR_BY_INDEX, index_order);
	
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		ret = SRV_BT_MAPC_FAIL_NOT_SUPPORTED;
	else
    {
    	btd = (srv_bt_cm_bt_addr *)&g_gmap_client_cntx[index_order].bd_addr;
	
#if defined(__MMI_BT_MAPC_BY_DOGP__) && defined(__MMI_WEARABLE_DEVICE__)
		if((btd->lap == 0 && btd->uap == 0 && btd->nap == 0)
			|| (srv_bt_cm_get_linked_dev_list_idx() > 0 && !srv_bt_cm_is_dev_in_link_table(btd)))
		{
			bt_addr->lap = g_map_cur_map_dev_addr.lap;
    		bt_addr->uap = g_map_cur_map_dev_addr.uap;
    		bt_addr->nap = g_map_cur_map_dev_addr.nap;
			MMI_MAPC_ADP_dump_dev_addr(&g_map_cur_map_dev_addr);
		}
    	else
#else /* defined(__MMI_BT_MAPC_BY_DOGP__) && defined(__MMI_WEARABLE_DEVICE__)*/
		if(btd->lap == 0 && btd->uap == 0 && btd->nap == 0)
		{
			
			MMI_MAPC_ADP_dump_dev_addr(bt_addr);
			ret = SRV_BT_MAPC_FAIL_NOT_FOUND;
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
	#endif
		else
#endif /*!defined(__MMI_BLE_DOGP_SUPPORT__)*/
		{
    		bt_addr->lap = btd->lap;
    		bt_addr->uap = btd->uap;
    		bt_addr->nap = btd->nap;
		}
	}
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_GET_ADDR_BY_INDEX_RET, ret);
	
	MMI_MAPC_ADP_dump_dev_addr(bt_addr);

	return ret;
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_dev_cntx_index
 * DESCRIPTION
 * response 
 * PARAMETERS
 * bt_addr
 * mas_id
 * RETURNS
 *  U8
 *****************************************************************************/
U8 srv_bt_mapc_get_dev_cntx_index(srv_bt_cm_bt_addr *bt_addr, S32 mas_id)
{	
	 /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 U8 cntx_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_DEV_CNTX_IDX_MAS_ID, mas_id);
	MMI_MAPC_ADP_dump_dev_addr(bt_addr);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[0].bd_addr);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].bd_addr);
	if(bt_addr == NULL && (mas_id <= 0 || mas_id == 255))
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_DEV_CNTX_IDX_NOTFOUND);
		return MAX_MAPC_LINK_SUPPORT;
	}

	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{		
		if(bt_addr != NULL)
		{
			if(!srv_bt_cm_is_dev_addr_equal((srv_bt_cm_bt_addr *)&g_gmap_client_cntx[cntx_index].bd_addr, bt_addr))
				continue;
		}
		
		if(mas_id > 0 && mas_id != 255)
		{
			if(g_gmap_client_cntx[cntx_index].mas_id != mas_id)
				continue;
		}
		
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_DEV_CNTX_IDX, cntx_index);
		return cntx_index;			
	}
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_DEV_CNTX_IDX_NOTFOUND);
	return MAX_MAPC_LINK_SUPPORT;

}
/*****************************************************************************
 * FUNCTION
 * srv_mapc_send_msg
 * DESCRIPTION
 * response 
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_send_msg(msg_type msg_id, void *p_local_para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_send5(
        MOD_MMI,
        MOD_BT,
        BT_APP_SAP,
        (msg_type)msg_id,
        (local_para_struct*)p_local_para);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_req
 * DESCRIPTION
 * response 
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_disconnect_req(U32 conn_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    bt_mapc_disconnect_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT, conn_id);
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index(&g_map_dev_addr, conn_id);

	if( cntx_index == MAX_MAPC_LINK_SUPPORT)
	{
		if(conn_id > 0 && conn_id != 255)
		{
			for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
			{								
				if(g_gmap_client_cntx[cntx_index].mas_id == conn_id)
				{
					if ((g_map_dev_addr.lap == 0) && (g_map_dev_addr.uap == 0) && (g_map_dev_addr.nap == 0))
					{
						g_map_dev_addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
						g_map_dev_addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
						g_map_dev_addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
					}
					
					break;
				}
			}			
		}
	}
	if( cntx_index == MAX_MAPC_LINK_SUPPORT)	
	{
		cntx_index = 0;
		if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
 			(*g_gmap_client_cntx[cntx_index].srv_cm_cb)(&g_map_dev_addr, 
 										SRV_BT_CM_MAPC_CONNECTION, 
 										MMI_FALSE, 
 										MMI_FALSE, 
 										MMI_FALSE);
		return;
	}
		
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT_STATE, g_gmap_client_cntx[cntx_index].state);

	if(g_gmap_client_cntx[cntx_index].state <= SRV_MAPC_STATE_DISCONNECTING)
	{    
		if(g_gmap_client_cntx[cntx_index].state != SRV_MAPC_STATE_DISCONNECTING)
			g_gmap_client_cntx[cntx_index].mas_id = -1;
		g_gmap_client_cntx[cntx_index].prev_bd_addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
    	g_gmap_client_cntx[cntx_index].prev_bd_addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
    	g_gmap_client_cntx[cntx_index].prev_bd_addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;

		if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
			(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&g_gmap_client_cntx[cntx_index].bd_addr, 
     										SRV_BT_CM_MAPC_CONNECTION, 
     										MMI_TRUE, 
     										MMI_FALSE, 
     										MMI_FALSE);
		return;
	}
	
#ifdef __MMI_BT_MAPC_BY_MAP__   
	if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
	{
		msg = construct_local_para(sizeof(bt_mapc_disconnect_req_struct), TD_CTRL);
		MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_DISCONNECTING);
	    msg->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
	    msg->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
	    msg->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
	    msg->mas_id = g_gmap_client_cntx[cntx_index].mas_id; 
    	srv_mapc_send_msg(MSG_ID_BT_MAPC_DISCONNECT_REQ, msg);
	}
	else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
	{
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
		if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
			(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(g_gmap_client_cntx[cntx_index].bd_addr),
												SRV_BT_CM_MAPC_CONNECTION,
												MMI_TRUE, 
												MMI_FALSE,
												MMI_FALSE);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
	}
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_activate_req
 * DESCRIPTION
 * Send mapc activate request
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_activate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 cntx_index;
#ifndef __MMI_BT_MAPC_BY_MAP__
    bt_mapc_activate_cnf_struct msg_p;
#endif /*__MMI_BT_MAPC_BY_MAP__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_REQ);
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		//ASSERT(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_INIT);
		MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATING);
	}
	
#ifdef __MMI_BT_MAPC_BY_MAP__
    srv_mapc_send_msg(MSG_ID_BT_MAPC_ACTIVATE_REQ, NULL);
#else /*__MMI_BT_MAPC_BY_MAP__*/
    msg_p.result = SRV_BT_MAPC_SUCCESS;
    srv_mapc_activate_cnf(&msg_p);
#endif /*__MMI_BT_MAPC_BY_MAP__*/
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_deactivate_req
 * DESCRIPTION
 * Send mapc deactivate request
 * PARAMETERS
 * void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_deactivate_req(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
#ifndef __MMI_BT_MAPC_BY_MAP__
    bt_mapc_deactivate_cnf_struct msg_p;
#endif /*__MMI_BT_MAPC_BY_MAP__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_MAPC_DEACTIVATE_REQ);
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_DEACTIVATING);
	}
	
#ifdef __MMI_BT_MAPC_BY_MAP__
        srv_mapc_send_msg(MSG_ID_BT_MAPC_DEACTIVATE_REQ, NULL);
#else /*__MMI_BT_MAPC_BY_MAP__*/
        msg_p.result = SRV_BT_MAPC_SUCCESS;
        srv_mapc_deactivate_cnf(&msg_p);
#endif /*__MMI_BT_MAPC_BY_MAP__*/
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_init
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_init(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_cm_profile_struct mapc_tbl;
    srv_bt_mapc_notify_cb mapc_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_INIT);
	memset(g_gmap_client_cntx, 0, MAX_MAPC_LINK_SUPPORT * sizeof(srv_map_client_cntx_struct));
	g_gmap_cur_index = -1;
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		mapc_cb = g_gmap_client_cntx[cntx_index].srv_map_callback;


    	g_gmap_client_cntx[cntx_index].mas_id = -1;
    	g_gmap_client_cntx[cntx_index].srv_hd = -1;
    	g_gmap_client_cntx[cntx_index].user_data = NULL;
    	g_gmap_client_cntx[cntx_index].srv_map_callback = mapc_cb;
    	#if defined(__PLUTO_MMI_PACKAGE__) && defined(__MMI_BT_DIALER_SUPPORT__) && !defined(__IOT__)
    	g_gmap_client_cntx[cntx_index].srv_cm_cb = mmi_bt_dialor_callback;
    	#endif
    	g_gmap_client_cntx[cntx_index].mns_registration = SRV_MAPC_MNS_STATE_FALSE;
    	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_INIT);
    	g_gmap_client_cntx[cntx_index].conn_type = SRV_BT_MAPC_CONN_SPP;
	}
  	mapc_tbl.profile_id = SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID;
	mapc_tbl.activater = srv_bt_mapc_activate_req;
	mapc_tbl.deactivater = srv_bt_mapc_deactivate_req;
	mapc_tbl.disconnector = srv_bt_mapc_disconnect_req;
    srv_bt_cm_profile_register((const srv_bt_cm_profile_struct*)&mapc_tbl);
    srv_mapc_set_event_hdlr();
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_deinit
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_deinit(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_notify_cb mapc_cb;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DEINIT);
    // Don't reset this callback, it only registered at bootup stage.
    memset(g_gmap_client_cntx, 0, MAX_MAPC_LINK_SUPPORT * sizeof(srv_map_client_cntx_struct));
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		mapc_cb = g_gmap_client_cntx[cntx_index].srv_map_callback;

   
    	g_gmap_client_cntx[cntx_index].mas_id = -1;
    	g_gmap_client_cntx[cntx_index].srv_hd = -1;
    	g_gmap_client_cntx[cntx_index].srv_map_callback = mapc_cb;
	
	    MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_INIT);		
	}
	g_gmap_cur_index = -1;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mapc_open
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mapc_open(U32 app_id)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_OPEN,g_gmap_client_cntx[cntx_index].srv_hd);

	    if(g_gmap_client_cntx[cntx_index].srv_hd < 0)
	    {    
	    	g_gmap_client_cntx[cntx_index].srv_hd = cntx_index;
	        g_gmap_client_cntx[cntx_index].app_id = app_id;
	    }
	}
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_mapc_close
 * DESCRIPTION
 *  This function is to initialize MAP context
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_mapc_close(U32 srv_hd)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CLOSE,g_gmap_client_cntx[cntx_index].srv_hd);

	    if(g_gmap_client_cntx[cntx_index].srv_hd == srv_hd)
	    {    
	    	g_gmap_client_cntx[cntx_index].srv_hd = -1;
	        g_gmap_client_cntx[cntx_index].app_id = 0;
	        return MMI_TRUE;
	    }
	        
	}
	return MMI_FALSE;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_register_callback
 * DESCRIPTION
 *  This function is to register the callback so that we can inform the above
 *  application about the events by calling this callback
 * PARAMETERS
 * srv_hd
 * srv_map_callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_register_cm_callback(srv_bt_cm_map_callback srv_cm_cb)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		g_gmap_client_cntx[cntx_index].srv_cm_cb = srv_cm_cb;
	}
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_mapc_register_callback
 * DESCRIPTION
 *  This function is to register the callback so that we can inform the above
 *  application about the events by calling this callback
 * PARAMETERS
 * srv_hd
 * srv_map_callback
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_register_callback(S32 srv_hd, srv_bt_mapc_notify_cb srv_map_callback)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	{
		g_gmap_client_cntx[cntx_index].srv_map_callback = srv_map_callback;
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_req
 * DESCRIPTION
 * To start connection we need to have a connect req function 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_connect_req(U8 cntx_index, srv_bt_cm_bt_addr dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_connect_req_struct *msg;	
#ifndef __MMI_BT_MAPC_BY_MAP__
    bt_mapc_connect_cnf_struct conn_cnf;
#endif /*__MMI_BT_MAPC_BY_MAP__*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CONNECT, dev_addr.lap, dev_addr.uap, dev_addr.nap, -1);

	if(g_gmap_client_cntx[cntx_index].state < SRV_MAPC_STATE_ACTIVATED)
	{

		if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
			(*g_gmap_client_cntx[cntx_index].srv_cm_cb)(&dev_addr, 
											SRV_BT_CM_MAPC_CONNECTION, 
											MMI_FALSE, 
											MMI_TRUE, 
											MMI_FALSE);  
		return;
	}
    else if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_CONNECTING)	     
    {
		if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
			(*g_gmap_client_cntx[cntx_index].srv_cm_cb)(&dev_addr, 
											SRV_BT_CM_MAPC_CONNECTION, 
											MMI_TRUE, 
											MMI_TRUE, 
											MMI_FALSE);  
		return;
    }
	
    g_gmap_client_cntx[cntx_index].mas_id = srv_bt_cm_start_conn(MMI_FALSE, 
															SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID, 
															&dev_addr, 
															NULL);  
    if(g_gmap_client_cntx[cntx_index].mas_id < 0)
    {
        if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
        {
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
        }
        if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
     		(*g_gmap_client_cntx[cntx_index].srv_cm_cb)(&dev_addr, 
     											SRV_BT_CM_MAPC_CONNECTION, 
     											MMI_FALSE, 
     											MMI_TRUE, 
     											MMI_FALSE); 
     	return;
    }
    
    msg = construct_local_para(sizeof(bt_mapc_connect_req_struct), TD_CTRL);
			
    msg->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap = dev_addr.lap;
    msg->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap = dev_addr.nap;
    msg->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap = dev_addr.uap;
	msg->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CONNECT, dev_addr.lap, dev_addr.uap, dev_addr.nap, msg->mas_id);
    MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_CONNECTING);

#ifdef __MMI_BT_MAPC_BY_MAP__
	srv_mapc_send_msg(MSG_ID_BT_MAPC_CONNECT_REQ, msg);
#else /*__MMI_BT_MAPC_BY_MAP__*/
    conn_cnf.addr.lap = dev_addr.lap;
    conn_cnf.addr.nap = dev_addr.nap;
    conn_cnf.addr.uap = dev_addr.uap;
	conn_cnf.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    conn_cnf.result = SRV_BT_MAPC_FAIL_NOT_SUPPORTED;
    free_local_para((local_para_struct *)msg);
    srv_bt_mapc_connect_cnf(&conn_cnf);   
#endif /*__MMI_BT_MAPC_BY_MAP__*/
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_is_new_connection
 * DESCRIPTION
 * To start connection we need to have a connect req function 
 * PARAMETERS
 * index
 * RETURNS
 *  void
 *****************************************************************************/
MMI_BOOL srv_bt_mapc_is_new_connection(U8 index_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return MMI_FALSE;
	
    if(g_gmap_client_cntx[index_order].bd_addr.lap == g_gmap_client_cntx[index_order].prev_bd_addr.lap&&
        g_gmap_client_cntx[index_order].bd_addr.nap == g_gmap_client_cntx[index_order].prev_bd_addr.nap&&
        g_gmap_client_cntx[index_order].bd_addr.uap == g_gmap_client_cntx[index_order].prev_bd_addr.uap)
        return MMI_FALSE;
    return MMI_TRUE;

}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_set_notify_registration_req
 * DESCRIPTION
 * To register at server end about the notification server receives from operator
 * and informs the client if client registers for notification 
 * PARAMETERS
 * val
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_set_notify_registration_req(U8 cntx_index, MMI_BOOL val)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_set_notif_registration_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_REGISTRATION_REQ,g_gmap_client_cntx[cntx_index].state,val);
 #ifdef __MMI_BT_MAPC_BY_MAP__
    if(g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_CONNECTED)
    {
        msg = construct_local_para(sizeof(bt_mapc_set_notif_registration_req_struct), TD_CTRL);
        
	    msg->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
	    msg->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
	    msg->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
	    msg->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
	    msg->on = val;
		
	    if(val == MMI_TRUE)
	        g_gmap_client_cntx[cntx_index].mns_registration = SRV_MAPC_MNS_SETTING_TRUE;
	    else
	        g_gmap_client_cntx[cntx_index].mns_registration = SRV_MAPC_MNS_SETTING_FALSE;
		
	    MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_SET_NOTIFY_REGISTRATION);
	    srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_NOTIF_REGISTRATION_REQ, msg);
    }
#endif /*__MMI_BT_MAPC_BY_MAP__*/
}



/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_cnf
 * DESCRIPTION
 * response 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_connect_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;	
    bt_mapc_connect_cnf_struct *msg_p = NULL;
    srv_bt_mapc_connect_rsp  msg_u = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_mapc_connect_cnf_struct *)msg;
    msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	
	if( cntx_index == MAX_MAPC_LINK_SUPPORT)
	{
        if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
    		(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr), 
    											SRV_BT_CM_MAPC_CONNECTION, 
    											!(msg_p->result), 
    											MMI_TRUE, 
    											MMI_FALSE);
		return;
	}

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT_CNF,g_gmap_client_cntx[cntx_index].state,msg_p->result);

	g_gmap_cur_index = -1;

    if((msg_p != NULL ) && (msg_p->result == SRV_BT_MAPC_SUCCESS))
    {
        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_CONNECTED);
		
        srv_bt_cm_connect_ind(g_gmap_client_cntx[cntx_index].mas_id);
        g_gmap_client_cntx[cntx_index].conn_type = SRV_BT_MAPC_CONN_MAP;
		
        if(g_gmap_client_cntx[cntx_index].mns_support && 
            g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP &&
            (srv_bt_cm_get_bqb_test_flag() == MMI_FALSE))
        {
        	
            srv_mapc_set_notify_registration_req(cntx_index, MMI_TRUE);
        }
        else
        {			           
			msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
	        msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;
			MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
			if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
	        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_CONNECT_RSP, &msg_u);
	        if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
				(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr), 
												SRV_BT_CM_MAPC_CONNECTION,
												!(msg_p->result), 
												MMI_TRUE, 
												MMI_FALSE);
			}
		#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
		g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
		#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/

    }
    else
    {
        if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
        {
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
        }
        srv_bt_cm_stop_conn(g_gmap_client_cntx[cntx_index].mas_id);
        g_gmap_client_cntx[cntx_index].mas_id = -1;
		
    #if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
		g_gmap_client_cntx[cntx_index].conn_type = SRV_BT_MAPC_CONN_SPP;
	
        #ifdef __MMI_WEARABLE_DEVICE__
		MMI_MAPC_ADP_dump_dev_addr(&g_map_cur_noti_dev_addr);
        #endif /*__MMI_WEARABLE_DEVICE__*/
	    // after map connect fail, judge the spp of this bt device addr weather connect or not
	    // g_mapc_adp_cntx[cntx_index].is_spp_connected = MMI_TRUE;
        //g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
       #if defined( __MMI_BT_MAPC_BY_DOGP__) && defined(__MMI_WEARABLE_DEVICE__)
		if(srv_bt_noti_check_sync_connection())
	   	{
			if(srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_SPP_CONNECTION, (srv_bt_cm_bt_addr *)&(msg_p->addr)))	   
			{				
				g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
				g_gmap_client_cntx[cntx_index].mas_id = 255;
				msg_u.Error = SRV_BT_MAPC_SUCCESS;   
				msg_p->result = SRV_BT_MAPC_SUCCESS;
				MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_CONNECTED);
			}
			else
			{
				if(g_map_cur_noti_dev_addr.lap == 0 && g_map_cur_noti_dev_addr.uap == 0 && g_map_cur_noti_dev_addr.nap == 0)
				{
					g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
					msg_u.Error = SRV_BT_MAPC_FAIL;   
					msg_p->result = SRV_BT_MAPC_FAIL;

				}
				else
				{
					g_gmap_client_cntx[cntx_index].bd_addr.lap = g_map_cur_noti_dev_addr.lap;
   					g_gmap_client_cntx[cntx_index].bd_addr.nap = g_map_cur_noti_dev_addr.nap;
    				g_gmap_client_cntx[cntx_index].bd_addr.uap = g_map_cur_noti_dev_addr.uap;
					g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
					g_gmap_client_cntx[cntx_index].mas_id = 255;
					msg_u.Error = SRV_BT_MAPC_SUCCESS;   
					msg_p->result = SRV_BT_MAPC_SUCCESS;
					MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_CONNECTED);

				}
			}

		}
	   #else /*__MMI_BLE_DOGP_SUPPORT__*/
	    if(srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_SPP_CONNECTION, (srv_bt_cm_bt_addr *)&(msg_p->addr))) 	   
		{
			g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
			g_gmap_client_cntx[cntx_index].mas_id = 255;
			msg_u.Error = SRV_BT_MAPC_SUCCESS;   
			msg_p->result = SRV_BT_MAPC_SUCCESS;
			MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_CONNECTED);
		}
		#endif /*__MMI_BLE_DOGP_SUPPORT__*/
		else if(!srv_bt_cm_check_dev_profile_support_status((srv_bt_cm_bt_addr *)&(msg_p->addr), SRV_BT_CM_MESSAGE_ACCESS_PROFILE_SERVER_UUID))
        {
        	g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
            msg_u.Error = SRV_BT_MAPC_FAIL_NOT_SUPPORTED;
            msg_p->result = SRV_BT_MAPC_FAIL;
        }  
		else
		{
			g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
			msg_u.Error = SRV_BT_MAPC_FAIL;   
			msg_p->result = SRV_BT_MAPC_FAIL;
		}
		
        if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_CONNECT_RSP, &msg_u);
        if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr), 
        										SRV_BT_CM_MAPC_CONNECTION, 
        										!(msg_p->result), 
        										MMI_TRUE,
        										MMI_FALSE);
    #else  /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
        if(!srv_bt_cm_check_dev_profile_support_status((srv_bt_cm_bt_addr *)&(msg_p->addr), SRV_BT_CM_MESSAGE_ACCESS_PROFILE_SERVER_UUID))
        {
            msg_u.Error = SRV_BT_MAPC_FAIL_NOT_SUPPORTED;
        }  
        if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_CONNECT_RSP, &msg_u);
        if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr), 
        											SRV_BT_CM_MAPC_CONNECTION, 
        											!(msg_p->result), 
        											MMI_TRUE, 
        											MMI_FALSE);
    #endif  /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
    }
}
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_spp_connect_cnf
 * DESCRIPTION
 * response 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_spp_connect_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    bt_mapc_connect_cnf_struct *msg_p = NULL;
    srv_bt_mapc_connect_rsp  msg_u;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_mapc_connect_cnf_struct *)msg;
    msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	
	if( cntx_index == MAX_MAPC_LINK_SUPPORT)
	{
		return;
	}
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT_CNF,g_gmap_client_cntx[cntx_index].state,msg_p->result);
	
	g_gmap_cur_index = -1;

    if((msg_p != NULL ) && (msg_p->result == SRV_BT_MAPC_SUCCESS))
    {
        if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_SPP)
        { 
            g_gmap_client_cntx[cntx_index].mas_id = msg_p->mas_id;
            MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CONNECT_MAS_ID, g_gmap_client_cntx[cntx_index].mas_id);
            msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
            msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
			if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
            	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, 
            												SRV_BT_MAPC_EVT_ID_CONNECT_RSP, 
            												&msg_u);
       }
    }
    else
    {
        if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
        {
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
        }
    }
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_spp_disconnect_cnf
 * DESCRIPTION
 * Handle the disconnect confirmation from server side 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_spp_disconnect_cnf(void *msg)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
	bt_mapc_disconnect_cnf_struct *msg_p = (bt_mapc_disconnect_cnf_struct *)msg;
	//srv_bt_mapc_disconnect_rsp  msg_u;
		

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if ( cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;

	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT_CNF, g_gmap_client_cntx[cntx_index].state);
	
	//msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
    //msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;	
	
    if(msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
        g_gmap_client_cntx[cntx_index].mas_id = -1;
        g_gmap_client_cntx[cntx_index].prev_bd_addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
        g_gmap_client_cntx[cntx_index].prev_bd_addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
        g_gmap_client_cntx[cntx_index].prev_bd_addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;

        if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
        {
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
        }
    }
    else
    {
    	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    }
	
    if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
        (*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_DISCONNECT_IND, NULL);
	g_gmap_client_cntx[cntx_index].user_data = NULL;
}

#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
/*****************************************************************************
 * FUNCTION
 * srv_mapc_disconnect_from_cm
 * DESCRIPTION
 * response 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_disconnect_from_cm(srv_bt_cm_bt_addr *dev_addr, srv_bt_cm_map_callback srv_cm_cb)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT_FROM_CM);

	cntx_index = srv_bt_mapc_get_dev_cntx_index(dev_addr, -1);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
	{
		if(srv_cm_cb)
     		srv_cm_cb(dev_addr, SRV_BT_CM_MAPC_CONNECTION, MMI_FALSE, MMI_FALSE, MMI_FALSE);
		return;
	}

    if(srv_cm_cb != NULL)
    {
    	g_gmap_client_cntx[0].srv_cm_cb = srv_cm_cb;
		g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].srv_cm_cb = srv_cm_cb;
    }
	g_map_dev_addr.lap = dev_addr->lap;
	g_map_dev_addr.nap = dev_addr->nap;
	g_map_dev_addr.uap = dev_addr->uap;
	
    srv_mapc_disconnect_ex(cntx_index, NULL);
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_req_from_cm
 * DESCRIPTION
 * response 
 * PARAMETERS
 * dev_addr
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_connect_req_from_cm(srv_bt_cm_bt_addr dev_addr, srv_bt_cm_map_callback srv_cm_cb, MMI_BOOL is_mns_supported)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
	U8 cntx_index_temp;
	srv_bt_cm_bt_addr *btd = NULL;
	srv_bt_cm_bt_addr temp_btd = {0};
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	temp_btd.lap = dev_addr.lap;
	temp_btd.nap = dev_addr.nap;
	temp_btd.uap = dev_addr.uap;
#if defined(__MMI_BT_MAPC_BY_DOGP__) && defined(__MMI_WEARABLE_DEVICE__)
	{
		g_map_cur_map_dev_addr.lap = dev_addr.lap;
		g_map_cur_map_dev_addr.nap = dev_addr.nap;
		g_map_cur_map_dev_addr.uap = dev_addr.uap;
	}
#endif /*defined(__MMI_BLE_DOGP_SUPPORT__)*/

	MMI_MAPC_ADP_dump_dev_addr(&temp_btd);
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_CALLBACK, srv_cm_cb);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[0].bd_addr);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].bd_addr);
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_G_INDEX, g_gmap_cur_index);
	
	cntx_index_temp = srv_bt_mapc_get_dev_cntx_index(&temp_btd, -1);
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX_TEMP, cntx_index_temp);
	if(g_gmap_cur_index == -1 || g_gmap_cur_index >= MAX_MAPC_LINK_SUPPORT)
	{	
		if(cntx_index_temp == MAX_MAPC_LINK_SUPPORT)
		{
			for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
			{
				btd = (srv_bt_cm_bt_addr *)&g_gmap_client_cntx[cntx_index].bd_addr;
				if(g_gmap_client_cntx[cntx_index].mas_id < 0
				#if !defined(__MMI_BT_MAPC_BY_DOGP__)
					 && !srv_bt_cm_get_existed_conn_num_by_addr(btd)
				#endif /*!defined(__MMI_BLE_DOGP_SUPPORT__)*/
				)
				{
					MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX, cntx_index, g_gmap_client_cntx[cntx_index].mas_id);
					break;
				}
			}
			if(cntx_index == MAX_MAPC_LINK_SUPPORT)
			{
				MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX0, cntx_index);
#if defined(__MMI_BT_MAPC_BY_DOGP__)
				cntx_index = 0;
#else /*defined(__MMI_BLE_DOGP_SUPPORT__)*/
				cntx_index = 0;
				g_gmap_client_cntx[cntx_index].mas_id = -1;
				MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
#endif /*defined(__MMI_BLE_DOGP_SUPPORT__)*/
				MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX1, cntx_index);

			}
		}
		else
		{		
			cntx_index = cntx_index_temp;
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX2, cntx_index);
		}

	}
	else
	{
		if(cntx_index_temp == MAX_MAPC_LINK_SUPPORT || cntx_index_temp == g_gmap_cur_index)
		{
			cntx_index = g_gmap_cur_index;
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX3,cntx_index, cntx_index_temp);
		}
		else
		{
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX6,cntx_index, cntx_index_temp);
			if(g_gmap_client_cntx[cntx_index_temp].mas_id < 0)
			{
				g_gmap_client_cntx[cntx_index_temp].bd_addr.lap = 0;
				g_gmap_client_cntx[cntx_index_temp].bd_addr.nap = 0;
				g_gmap_client_cntx[cntx_index_temp].bd_addr.uap = 0;
				MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
			}
			cntx_index = g_gmap_cur_index;
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX4, cntx_index);
		}
	}
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CON_REQ_FROM_CM_GET_INDEX5, cntx_index);

	if(srv_cm_cb != NULL)
    {  	
        g_gmap_client_cntx[0].srv_cm_cb = srv_cm_cb;
		g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].srv_cm_cb = srv_cm_cb;
    }
    g_gmap_client_cntx[cntx_index].mns_support = is_mns_supported;
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[0].bd_addr);
	MMI_MAPC_ADP_dump_dev_addr(&g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT - 1].bd_addr);

    srv_bt_mapc_connect_req(cntx_index, dev_addr);
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_disconnect
 * DESCRIPTION
 * response 
 * PARAMETERS
 * cntx_index
 * RETURNS
 *  void
 *****************************************************************************/
 void srv_mapc_disconnect(U8 index_order, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;
    g_gmap_client_cntx[index_order].user_data = user_data;
    srv_bt_mapc_disconnect_req(g_gmap_client_cntx[index_order].mas_id);
}
/*****************************************************************************
   * FUNCTION
   * srv_mapc_disconnect_ex
   * DESCRIPTION
   * response 
   * PARAMETERS
   * cntx_index
   * RETURNS
   *  void
   *****************************************************************************/

  void srv_mapc_disconnect_ex(U8 cntx_index, void *user_data)
 {
	 /*----------------------------------------------------------------*/
	 /* Local Variables 											   */
	 /*----------------------------------------------------------------*/
 
	 /*----------------------------------------------------------------*/
	 /* Code Body													   */
	 /*----------------------------------------------------------------*/
	 g_gmap_client_cntx[cntx_index].user_data = user_data;
     srv_bt_mapc_disconnect_req(g_gmap_client_cntx[cntx_index].mas_id);
}	

 /*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_ind
 * DESCRIPTION
 * response 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
 void srv_bt_mapc_disconnect_ind(void *msg)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
	MMI_BOOL is_indication = MMI_TRUE;
	
	bt_mapc_disconnect_ind_struct *msg_p = (bt_mapc_disconnect_ind_struct *)msg;	

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if ( cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT_IND, g_gmap_client_cntx[cntx_index].state, msg_p->mas_id);
   if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
    {
    	if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_CONNECTING)
		{	
			bt_mapc_connect_cnf_struct msg_cnf = {0};
			msg_cnf.result = BT_MAP_FAIL;
			msg_cnf.addr.lap = msg_p->addr.lap;
			msg_cnf.addr.nap = msg_p->addr.nap;
			msg_cnf.addr.uap = msg_p->addr.uap;
			msg_cnf.mas_id = msg_p->mas_id;  /* Range 0~255 */
			srv_bt_mapc_connect_cnf(&msg_cnf);
			return;
    	}
		else if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_SET_NOTIFY_REGISTRATION)
		{		
			bt_mapc_set_notif_registration_cnf_struct msg_cnf = {0};
			msg_cnf.result = BT_MAP_FAIL;
			msg_cnf.addr.lap = msg_p->addr.lap;
			msg_cnf.addr.nap = msg_p->addr.nap;
			msg_cnf.addr.uap = msg_p->addr.uap;
			msg_cnf.mas_id = msg_p->mas_id;  /* Range 0~255 */
			srv_bt_mapc_set_notify_registration_cnf(&msg_cnf);

		}
		else if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_DISCONNECTING)
		{
			is_indication = MMI_FALSE;
		}
        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
    }
	srv_bt_cm_stop_conn(msg_p->mas_id);
    g_gmap_client_cntx[cntx_index].mas_id = -1;
    g_gmap_client_cntx[cntx_index].prev_bd_addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
    g_gmap_client_cntx[cntx_index].prev_bd_addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
    g_gmap_client_cntx[cntx_index].prev_bd_addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
	
    if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_DISCONNECT_IND, NULL);
	
    if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
    {
    	(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr),
    										SRV_BT_CM_MAPC_CONNECTION, 
    										MMI_TRUE,
    										MMI_FALSE,
    										is_indication);
    }
#if 0
#if defined(__MMI_BT_MAPC_BY_SPP__) && !defined(__MMI_WEARABLE_DEVICE__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /*__MMI_BT_MAPC_BY_SPP__*/
#endif
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_disconnect_cnf
 * DESCRIPTION
 * Handle the disconnect confirmation from server side 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_disconnect_cnf(void *msg)
{
    
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
	bt_mapc_disconnect_cnf_struct *msg_p = (bt_mapc_disconnect_cnf_struct *)msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if (cntx_index == MAX_MAPC_LINK_SUPPORT)
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
#endif
		return;
	}

	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_DISCONNECT_CNF, g_gmap_client_cntx[cntx_index].state); 
    switch (g_gmap_client_cntx[cntx_index].state)
    {
        case SRV_MAPC_STATE_DISCONNECTING:
        case SRV_MAPC_STATE_DEACTIVATING:
        default:
        {       
            srv_bt_mapc_disconnect_rsp  msg_u;
		
            MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT_IND,g_gmap_client_cntx[cntx_index].state,msg_p->mas_id);
            msg_u.Error = (srv_bt_mapc_result_enum)msg_p->result;
            msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;			
            if(msg_u.Error == SRV_BT_MAPC_SUCCESS || msg_u.Error == SRV_BT_MAPC_FAIL_NOT_SUPPORTED)
            {
            	if(msg_u.Error == SRV_BT_MAPC_SUCCESS)
                {
                	srv_bt_cm_stop_conn(msg_p->mas_id);
            	}
				msg_p->result = SRV_BT_MAPC_SUCCESS;
                g_gmap_client_cntx[cntx_index].mas_id = -1;
                g_gmap_client_cntx[cntx_index].prev_bd_addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
                g_gmap_client_cntx[cntx_index].prev_bd_addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
                g_gmap_client_cntx[cntx_index].prev_bd_addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
				
                if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_ACTIVATED)
                {
                    MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
                }
            }
			else if(msg_u.Error == SRV_BT_MAPC_FAIL_BUSY)
			{
				MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_DISCONNECT_IND_BUSY);
				MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_DISCONNECTING);
				return;
			}
			else
            {
            	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
            }
			
            if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
                (*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_DISCONNECT_RSP, &msg_u);

			if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
                (*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&(msg_p->addr),
                									SRV_BT_CM_MAPC_CONNECTION,
                									!(msg_p->result), 
                									MMI_FALSE,
                									MMI_FALSE);

            g_gmap_client_cntx[cntx_index].user_data = NULL;
            break;
        }     
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_abort_cnf
 * DESCRIPTION
 * Handle the abort request of any ongoing operation  
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_abort_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
	bt_mapc_abort_cnf_struct  *msg_p = NULL;
    srv_mapc_abort_cnf msg_u;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_mapc_abort_cnf_struct *)msg;
    if(msg_p == NULL)
        return;
	
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ABORT_CNF, msg_p->result); 
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if (cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;

    msg_u.Error =(srv_bt_mapc_result_enum)msg_p->result;
    msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;
    if(g_gmap_client_cntx[cntx_index].mas_id == msg_p->mas_id && g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    {
    	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_ABORT_RSP, &msg_u);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_abort_req
 * DESCRIPTION
 * To send the abort request for an ongoing operation at server end 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_abort_req(U8 index_order, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_abort_req_struct  *msg_p;	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ABORT_REQ,g_gmap_client_cntx[index_order].state);    
  
#ifdef __MMI_BT_MAPC_BY_MAP__
	if (g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
	{
	    if(g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE)
	    {
	    	msg_p = construct_local_para(sizeof(bt_mapc_abort_req_struct), TD_CTRL);
		    msg_p->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
		    msg_p->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
		    msg_p->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
		    msg_p->mas_id = g_gmap_client_cntx[index_order].mas_id;
		    g_gmap_client_cntx[index_order].user_data = user_data;
		    srv_mapc_send_msg(MSG_ID_BT_MAPC_ABORT_REQ, (void *)&msg_p);
	    }
	}
	else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
	{
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
		bt_mapc_abort_cnf_struct msg_cnf;
		msg_cnf.result = SRV_BT_MAPC_SUCCESS;
		msg_cnf.addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
		msg_cnf.addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
		msg_cnf.addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
		msg_cnf.mas_id = g_gmap_client_cntx[index_order].mas_id;
		srv_bt_mapc_abort_cnf(&msg_cnf);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
	}

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_folder_req
 * DESCRIPTION
 * To send the set folder request while folder navigation at server end
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_folder_req(U8 cntx_index, U8 *folder, srv_btmapc_folder_flag_enum flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_set_folder_req_struct *msg;
    srv_bt_mapc_set_folder_res msg_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_REQ, cntx_index, g_gmap_client_cntx[cntx_index].state);

    if(flag == SRV_BT_MAPC_BACK && g_gmap_client_cntx[cntx_index].folder_depth == MAPC_ROOT_FOLDER_DEPTH)
    {
        msg_rsp.Error = SRV_BT_MAPC_FAIL_INVALID_PARAMETER;
        msg_rsp.user_data = g_gmap_client_cntx[cntx_index].user_data;
		if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP, &msg_rsp);
    }
    else if(g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_IDLE)
    {
    	msg = construct_local_para(sizeof(bt_mapc_set_folder_req_struct), TD_RESET);
        msg->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
        msg->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
        msg->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
        msg->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg->flag = (bt_map_folder_op_enum)flag;
        if (folder != NULL)
        {
            app_ucs2_strncpy((kal_int8 *)msg->folder, (const kal_int8 *)folder, BT_MAP_MAX_FOLDER_NAME_LEN);
            app_ucs2_strcat((kal_int8 *)msg->folder, (const kal_int8 *)L"\0");
        
            app_ucs2_strncpy((kal_int8 *)g_gmap_client_cntx[cntx_index].child_folder, (const kal_int8 *)folder, BT_MAP_MAX_FOLDER_NAME_LEN);
            app_ucs2_strcat((kal_int8 *)g_gmap_client_cntx[cntx_index].child_folder, (const kal_int8 *)L"\0"); 
        }
        else
        {
            app_ucs2_strcat((kal_int8 *)msg->folder, (const kal_int8 *)L"\0");
            app_ucs2_strcat((kal_int8 *)g_gmap_client_cntx[cntx_index].child_folder, (const kal_int8 *)L"\0");
        }
        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_GETTING_FOLDER);
#ifdef __MMI_BT_MAPC_BY_MAP__
        if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
        {
            srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_FOLDER_REQ, msg);
        } 
		else
#endif /*__MMI_BT_MAPC_BY_MAP__*/      
        {
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
            srv_bt_mapc_adp_set_folder_req(cntx_index, msg);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
        }

    }  
}


// folder should name of the folder on which operation is taking place 
/*****************************************************************************
 * FUNCTION
 * srv_mapc_change_folder
 * DESCRIPTION
 * To send the set folder request while folder navigation at server end
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_mapc_change_folder(U8 index_order, U8 *folder, srv_btmapc_folder_flag_enum flag, srv_bt_mapc_listing_enum list_type, void *user_data)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return MMI_FALSE;
	
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_CHANGE_FOLDER_REQ,g_gmap_client_cntx[index_order].state);

   
    if(g_gmap_client_cntx[index_order].state < SRV_MAPC_STATE_CONNECTED)
        return MMI_FALSE;

	 MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_IDLE);
	 
    if(flag < SRV_BT_MAPC_END)
    {
        g_gmap_client_cntx[index_order].user_data = user_data;
        g_gmap_client_cntx[index_order].get_msg_lst = list_type;
        g_gmap_client_cntx[index_order].folder_flag = flag;
        srv_bt_mapc_set_folder_req(index_order, folder, flag);
    }
    else if (flag == SRV_BT_MAPC_END && list_type == SRV_BT_MAPC_MESSAGE_LIST_ONLY && folder!= NULL)
    {
        srv_bt_mapc_get_message_listing(index_order, (U8*)folder);
    }
    else
    {
        return MMI_FALSE;
    }
    return MMI_TRUE;
    
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing
 * DESCRIPTION
 * To send request to get message listing in a particular folder and first 
 * get folder listing size 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing(U8 cntx_index, U8 *child_folder)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_get_message_listing_size_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_GET_MESSAGE_LISTING_INDEX, cntx_index);

    if(g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_IDLE)
    {
		msg = construct_local_para(sizeof(bt_mapc_get_message_listing_size_req_struct), TD_CTRL);
        msg->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
        msg->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
        msg->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
        memset(msg->child_folder, 0, BT_MAP_MAX_FOLDER_NAME_LEN);
        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_GETTING_MESSAGE_LISTING);
#ifdef __MMI_BT_MAPC_BY_MAP__
		if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
		{ 
			MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_BY_MAPC);
        	srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_SIZE_REQ, msg);       
    	}
		else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
		{
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
        	srv_bt_mapc_adp_get_list_size_req(cntx_index, msg);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
		}
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_folder_cnf
 * DESCRIPTION
 * To handle the set folder req and send the folder listing size req 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_folder_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    bt_mapc_set_folder_cnf_struct *msg_p = NULL;
    srv_bt_mapc_set_folder_res msg_rsp;
    U8  child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN + 1];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    msg_p = (bt_mapc_set_folder_cnf_struct *)msg;

    ASSERT(msg_p);
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_CNF,g_gmap_client_cntx[cntx_index].state,msg_p->result,g_gmap_client_cntx[cntx_index].get_msg_lst);
    msg_rsp.Error = (srv_bt_mapc_result_enum)msg_p->result;
    msg_rsp.user_data = g_gmap_client_cntx[cntx_index].user_data;
    if(msg_p->result == SRV_BT_MAPC_SUCCESS && (g_gmap_client_cntx[cntx_index].get_msg_lst == SRV_BT_MAPC_MESSAGE_LIST_ONLY) &&
        (g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_NEXT || g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_FORWARD))
    {
        memset(child_folder, 0, SRV_BT_MAP_MAX_FOLDER_NAME_LEN);
        app_ucs2_strcpy(g_gmap_client_cntx[cntx_index].prev_child_folder, g_gmap_client_cntx[cntx_index].child_folder);
        srv_bt_mapc_get_message_listing(cntx_index, child_folder);
    }
    else
    {              
        if(msg_p->result == SRV_BT_MAPC_SUCCESS)
        {
            if(g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_ROOT)
            {
                //srv_mapc_change_folder(MAPC_ROOT_FOLDER2)
                U8 child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN+1];
                g_gmap_client_cntx[cntx_index].folder_depth = 0;
                app_ucs2_strcpy((kal_int8 * )child_folder, (const kal_int8 *) L"telecom");
                app_ucs2_strcat((kal_int8 * )child_folder, (const kal_int8 *)L"\0");
                g_gmap_client_cntx[cntx_index].folder_flag = SRV_BT_MAPC_FORWARD;
                srv_bt_mapc_set_folder_req(cntx_index, child_folder, SRV_BT_MAPC_FORWARD);
                return;
            }
            else if(g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_FORWARD && g_gmap_client_cntx[cntx_index].folder_depth == 0)
            {           
            	U8 child_folder[SRV_BT_MAP_MAX_FOLDER_NAME_LEN + 1];
                g_gmap_client_cntx[cntx_index].folder_depth++;
                app_ucs2_strcpy((kal_int8 *) child_folder, (const kal_int8 *) L"msg");
                app_ucs2_strcat((kal_int8 *) child_folder, (const kal_int8 *)L"\0");
                g_gmap_client_cntx[cntx_index].folder_flag = SRV_BT_MAPC_FORWARD;
                srv_bt_mapc_set_folder_req(cntx_index, child_folder, SRV_BT_MAPC_FORWARD);
                return;
            }
            else if(g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_FORWARD)
            {
                g_gmap_client_cntx[cntx_index].folder_depth++;
            }
            else if(g_gmap_client_cntx[cntx_index].folder_flag == SRV_BT_MAPC_BACK)
            {
                g_gmap_client_cntx[cntx_index].folder_depth--;
            }
        }
           
        MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_FOLDER_CNF1,g_gmap_client_cntx[cntx_index].folder_depth);
    //    (*gmap_client_cntx_p->srv_map_callback)(g_gmap_client_cntx.srv_hd,SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP,&msg_rsp);
    } 
	
	if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_SET_FOLDER_RSP, &msg_rsp);
	
	
}    



/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing_size_cnf
 * DESCRIPTION
 * To send request to get message listing size  in a particular folder and then request 
 * for getting the folder listing size 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing_size_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    bt_mapc_get_message_listing_req_struct *msg_req;
    bt_mapc_get_message_listing_size_cnf_struct *msg_p = NULL;
    srv_bt_mapc_message_listing_cnf msg_cnf;
    srv_bt_mapc_set_msg_listing_prop_struct msg_list_prop = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    msg_p = (bt_mapc_get_message_listing_size_cnf_struct *)msg;
	
    cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_SIZE_CNF,g_gmap_client_cntx[cntx_index].state,msg_p->result);
	
	msg_list_prop = g_gmap_client_cntx[cntx_index].msg_lst_prop;
    g_gmap_client_cntx[cntx_index].get_msg_lst = SRV_BT_MAPC_NONE;
    msg_cnf.user_data = g_gmap_client_cntx[cntx_index].user_data;
    msg_cnf.result = (srv_bt_mapc_result_enum)msg_p->result;
    msg_cnf.list_size = 0;
    msg_cnf.unread = MMI_FALSE;
    if(msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
        msg_req = construct_local_para(sizeof(bt_mapc_get_message_listing_req_struct), TD_CTRL);        
        msg_req->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_req->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
        msg_req->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
        msg_req->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
        app_ucs2_strncpy((kal_int8 *)msg_req->child_folder, (const kal_int8 *)g_gmap_client_cntx[cntx_index].child_folder, BT_MAP_MAX_FOLDER_NAME_LEN);
        memset(msg_req->child_folder, 0, BT_MAP_MAX_FOLDER_NAME_LEN);
        msg_req->list_offset = msg_list_prop.ListStartOffset;
        msg_req->list_size = msg_list_prop.Maxlistcount;
        msg_req->max_subject_len = msg_list_prop.SubjectLength;
        msg_req->mask = (bt_map_msg_list_mask_enum)msg_list_prop.ParameterMask;
        msg_req->filter_msg = (bt_map_filter_msg_enum)msg_list_prop.FilterMessageType;
        app_ucs2_strncpy((kal_int8 *)msg_req->filter_begin, (const kal_int8 *)msg_list_prop.FilterPeriodBegin, SRV_BT_MAP_MAX_DATE_STR_LEN);
        app_ucs2_strncpy((kal_int8 *)msg_req->filter_end, (const kal_int8 *)msg_list_prop.FilterPeriodEnd, SRV_BT_MAP_MAX_DATE_STR_LEN);
        msg_req->filter_status=(bt_map_filter_status_enum)msg_list_prop.FilterReadStatus;
        app_ucs2_strncpy((kal_int8 *)msg_req->filter_rec, (const kal_int8 *)msg_list_prop.FilterRecipient, SRV_BT_MAP_MAX_CONTACT_STR_LEN);
        app_ucs2_strncpy((kal_int8 *)msg_req->filter_orig, (const kal_int8 *)msg_list_prop.FilterOriginator, SRV_BT_MAP_MAX_CONTACT_STR_LEN);
        msg_req->filter_prio = (bt_map_filter_prio_enum)msg_list_prop.FilterPriority;
        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_GETTING_MESSAGE_LISTING);
#ifdef __MMI_BT_MAPC_BY_MAP__
        if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
        {  
            srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_REQ, msg_req);
        }
        else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
        {
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
            srv_bt_mapc_adp_get_listing_req(cntx_index, msg_req);       
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
		}

    }
    else
    {
    	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    	if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    		(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP, &msg_cnf);
    }
    
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_listing_size_cnf
 * DESCRIPTION
 * To handle the message listing confirmation from server
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_listing_cnf(void *msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_message_listing_cnf msg_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_mapc_get_message_listing_cnf_struct *msg_p = (bt_mapc_get_message_listing_cnf_struct *)msg;
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_CNF,g_gmap_client_cntx[cntx_index].state,msg_p->result);
    g_gmap_client_cntx[cntx_index].get_msg_lst = SRV_BT_MAPC_NONE;
    msg_cnf.user_data = g_gmap_client_cntx[cntx_index].user_data;
    msg_cnf.result = (srv_bt_mapc_result_enum)msg_p->result;
    msg_cnf.list_size = 0;
    msg_cnf.unread = MMI_FALSE;
#ifdef __MMI_BT_MAPC_BY_MAP__	
	if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_DISCONNECTING
		&& g_gmap_client_cntx[cntx_index].mas_id > 0
		&& g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_LISTING_CNF_1);
		MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
		srv_bt_mapc_disconnect_req(g_gmap_client_cntx[cntx_index].mas_id);
		return;
	}
#endif /*__MMI_BT_MAPC_BY_MAP__*/
	if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_GETTING_MESSAGE_LISTING
		|| g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_SPP)
    {
    	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    	if(msg_p->result == SRV_BT_MAPC_SUCCESS)
	    {
	        msg_cnf.unread = (MMI_BOOL)msg_p->unread;
	        msg_cnf.list_size = msg_p->list_size;
	        app_ucs2_strncpy((kal_int8 *)msg_cnf.file, (const kal_int8 *)msg_p->file, BT_MAP_MAX_TEMP_FILE_NAME_LEN);
			if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
	        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP, &msg_cnf);
	    
	    }
	    else
	    {
	        //error handling need to update the application
	        if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
	        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_LISTING_RSP, &msg_cnf);
	    }
    }
   
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_request
 * DESCRIPTION
 * To send request to a particular message 
 * PARAMETERS
 * child_folder
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_msg_req(U8 index_order, U8 *handle, MMI_BOOL attachment, srv_bt_map_charset_enum charset, void *user_data)
{
    
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_get_message_req_struct *msg_req;
    srv_bt_mapc_message_cnf_struct msg_cnf;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;
    
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_REQ,index_order,attachment,charset);
	
    msg_cnf.Error = SRV_BT_MAPC_FAIL_BAD_STATE;
    msg_cnf.user_data = user_data;
	
    if(g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE)
    {
        msg_req = construct_local_para(sizeof(bt_mapc_get_message_req_struct), TD_CTRL);
        msg_req->mas_id = g_gmap_client_cntx[index_order].mas_id;
        msg_req->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
        msg_req->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
        msg_req->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
        app_ucs2_strncpy((kal_int8 *)msg_req->handle, (const kal_int8 *)handle, BT_MAP_MAX_HANDLE_STR_LEN/2);
        msg_req->attachment = attachment;
        msg_req->charset = (bt_map_charset_enum)charset;
        msg_req->fraction_req = BT_MAP_FRACTION_REQ_FIRST;
        g_gmap_client_cntx[index_order].user_data = user_data;    
        MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_GETTING_MESSAGE);
#ifdef __MMI_BT_MAPC_BY_MAP__
        if (g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
        {
            srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_REQ, msg_req);
        }
        else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
        {
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
            srv_bt_mapc_adp_get_msg_req(index_order, msg_req);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
        }
    }
    else
    {
    	if(g_gmap_client_cntx[index_order].srv_map_callback != NULL)
    		(*g_gmap_client_cntx[index_order].srv_map_callback)(g_gmap_client_cntx[index_order].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_RSP, &msg_cnf);
    }

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_get_message_cnf
 * DESCRIPTION
 * To handle get message confirmation from server 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_get_message_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_message_cnf_struct msg_cnf;
    bt_mapc_get_message_req_struct *msg_req;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_mapc_get_message_cnf_struct *msg_p = (bt_mapc_get_message_cnf_struct *)msg;

    cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_GET_MSG_CNF,msg_p->result,msg_p->fraction_rsp);
    
    msg_cnf.Error = (srv_bt_mapc_result_enum)msg_p->result;
    msg_cnf.user_data = g_gmap_client_cntx[cntx_index].user_data;
    if(msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
#ifdef __MMI_BT_MAPC_BY_MAP__
        if(msg_p->fraction_rsp == BT_MAP_FRACTION_RSP_MORE && g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
        {
            msg_req = construct_local_para(sizeof(bt_mapc_get_message_req_struct), TD_CTRL);
            msg_req->mas_id = g_gmap_client_cntx[cntx_index].mas_id;
            msg_req->addr.lap = g_gmap_client_cntx[cntx_index].bd_addr.lap;
            msg_req->addr.uap = g_gmap_client_cntx[cntx_index].bd_addr.uap;
            msg_req->addr.nap = g_gmap_client_cntx[cntx_index].bd_addr.nap;
            msg_req->attachment = MMI_FALSE;
            msg_req->charset = BT_MAP_CHARSET_UTF8;
            msg_req->fraction_req = BT_MAP_FRACTION_REQ_NEXT;
            MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_GETTING_MESSAGE);
            srv_mapc_send_msg(MSG_ID_BT_MAPC_GET_MESSAGE_REQ, msg_req);
        }
        else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
        {      
			//if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_GETTING_MESSAGE)
            {
            	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE)
            	msg_cnf.Error = (srv_bt_mapc_result_enum)msg_p->result;
           		msg_cnf.data_size = msg_p->data_size;
            	app_ucs2_strncpy((kal_int8 *)msg_cnf.file, (const kal_int8 *)msg_p->file, SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
				if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
            		(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_RSP, &msg_cnf);
            }
        }
    
    }
    else
    {   	
		//update application about the error in retrieving the message.
		//if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_GETTING_MESSAGE)
    	{
			MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    		if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    			(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_GET_MSG_RSP, &msg_cnf);
		 }
		
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_message_status_req
 * DESCRIPTION
 * To update the status of the message like delete or make it as read or unread 
 * PARAMETERS
 * status_val
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_message_status_req(U8 index_order, U8 *handle, srv_bt_mapc_msg_status_enum status_val, void *user_data)
{    
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_set_message_status_req_struct *msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_MSG_STATUS,status_val,g_gmap_client_cntx[index_order].state,index_order);
    if(g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE)
    {    
        msg = construct_local_para(sizeof(bt_mapc_set_message_status_req_struct), TD_CTRL);        
        msg->mas_id = g_gmap_client_cntx[index_order].mas_id;
        msg->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
        msg->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
        msg->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
        app_ucs2_strncpy((kal_int8 *)msg->handle, (const kal_int8 *)handle, BT_MAP_MAX_HANDLE_STR_LEN/2);
        msg->status = (bt_map_msg_status_enum)status_val;
        g_gmap_client_cntx[index_order].user_data = user_data;
        MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_SET_MESSAGE_STATUS);
#ifdef __MMI_BT_MAPC_BY_MAP__
        if (g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
        {
            srv_mapc_send_msg(MSG_ID_BT_MAPC_SET_MESSAGE_STATUS_REQ, msg);
        }
		else
#endif /*__MMI_BT_MAPC_BY_MAP__*/        
		{
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
	       srv_bt_mapc_adp_set_status_req(index_order, msg);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
		}

    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_push_message_req
 * DESCRIPTION
 * To push message which is composed at client end to the server 
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_push_message_req(U8 index_order, srv_bt_mapc_push_message_req_struct *msg, void *user_data)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_push_message_req_struct *msg_req;
    srv_bt_mapc_push_message_status_res msg_res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    srv_bt_mapc_push_message_req_struct *msg_p = (srv_bt_mapc_push_message_req_struct *)msg;

	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_PUSH_MSG_REQ,index_order,msg_p->child_folder,g_gmap_client_cntx[index_order].state);
    
    if(g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE)
    {
        msg_req = construct_local_para(sizeof(bt_mapc_push_message_req_struct), TD_CTRL);        
        msg_req->mas_id = g_gmap_client_cntx[index_order].mas_id;
        msg_req->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
        msg_req->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
        msg_req->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
        if(app_ucs2_strcmp(g_gmap_client_cntx[index_order].prev_child_folder, msg_p->child_folder) == 0)
        {
            memset(msg_req->child_folder, 0, BT_MAP_MAX_FOLDER_NAME_LEN);
        }
        else
        {
            app_ucs2_strncpy((kal_int8 *)msg_req->child_folder, (const kal_int8 *)msg_p->child_folder, SRV_BT_MAP_MAX_FOLDER_NAME_LEN);
        }
        msg_req->sent_op = BT_MAP_SAVE_AND_SENT;
        msg_req->retry = MMI_FALSE;
        msg_req->charset = BT_MAP_CHARSET_UTF8;
        app_ucs2_strncpy((kal_int8 *)msg_req->file, (const kal_int8 *)msg_p->file, BT_MAP_MAX_TEMP_FILE_NAME_LEN);
        msg_req->data_size = msg_p->data_size;
        g_gmap_client_cntx[index_order].user_data = user_data;
        MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_PUSHING_MESSAGE);
#ifdef __MMI_BT_MAPC_BY_MAP__	
        if (g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
        {
            srv_mapc_send_msg(MSG_ID_BT_MAPC_PUSH_MESSAGE_REQ, msg_req);
        }
        else
#endif /*__MMI_BT_MAPC_BY_MAP__*/			
        {
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)     
            srv_bt_mapc_adp_push_msg_req(index_order, msg_req);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
        }   
    }
    else
    {
        //send application failure of message if not connected
        msg_res.Error = SRV_BT_MAPC_FAIL;
        memset(msg_res.Handle, 0, sizeof(U16) * (SRV_BT_MAP_MAX_HANDLE_STR_LEN + 1));
        msg_res.user_data = user_data;		
    	if(g_gmap_client_cntx[index_order].srv_map_callback != NULL)
        	(*g_gmap_client_cntx[index_order].srv_map_callback)(g_gmap_client_cntx[index_order].srv_hd, SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP, &msg_res);
    }
    

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_push_message_cnf
 * DESCRIPTION
 * To handle the rsp from server about the push message feature
 * PARAMETERS
 * msg
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_push_message_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_push_message_status_res msg_res;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    bt_mapc_push_message_cnf_struct  *msg_p = (bt_mapc_push_message_cnf_struct  *)msg;
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_PUSH_MSG_CNF,msg_p->result);
	  
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	
	//if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_PUSHING_MESSAGE)
    {
    	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
    	msg_res.Error = (srv_bt_mapc_result_enum)msg_p->result;
	    if (msg_p->handle != NULL)
	    {
	        app_ucs2_strncpy((kal_int8 *)msg_res.Handle, (const kal_int8 *)msg_p->handle, BT_MAP_MAX_HANDLE_STR_LEN/2);
	    }
	    msg_res.user_data = g_gmap_client_cntx[cntx_index].user_data;
		
		if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
		    (*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_PUSH_MSG_RSP, &msg_res);
	}
	
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_update_inbox_req
 * DESCRIPTION
 * To send request to server so that it can update the inbox and we can get the latest 
 * message 
 * PARAMETERS
 * void 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_update_inbox_req(U8 index_order)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_update_inbox_req_struct *msg;
    srv_bt_mapc_update_inbox_res msg_w;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_UPDATE_INBOX,g_gmap_client_cntx[index_order].state);
#ifdef __MMI_BT_MAPC_BY_MAP__
    if(g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE && g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
    {
        msg = construct_local_para(sizeof(bt_mapc_update_inbox_req_struct), TD_CTRL);
        msg->mas_id = g_gmap_client_cntx[index_order].mas_id;
        msg->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
        msg->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
        msg->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
        MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_UPDATING_INBOX);
        srv_mapc_send_msg(MSG_ID_BT_MAPC_UPDATE_INBOX_REQ, msg);
    } 
    else
#endif /*__MMI_BT_MAPC_BY_MAP__*/
    {
        msg_w.Error = SRV_BT_MAPC_FAIL;
        msg_w.user_data = NULL;
		MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_IDLE);
    	// unable to update the inbox from first check connection
    	if(g_gmap_client_cntx[index_order].srv_map_callback != NULL)
    		(*g_gmap_client_cntx[index_order].srv_map_callback)(g_gmap_client_cntx[index_order].srv_hd, SRV_BT_MAPC_EVT_ID_UPDATE_INBOX_RSP, &msg_w);
		
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_update_inbox_req
 * DESCRIPTION
 * To handle the inbox update request 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_update_inbox_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    bt_mapc_update_inbox_cnf_struct *msg_p = (bt_mapc_update_inbox_cnf_struct *)msg;
    srv_bt_mapc_update_inbox_res msg_w;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_UPDATE_INBOX_CNF,msg_p->result);
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
    msg_w.Error = (srv_bt_mapc_result_enum)msg_p->result;
    msg_w.user_data = g_gmap_client_cntx[cntx_index].user_data;
	
	MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
	if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_UPDATE_INBOX_RSP, &msg_w);

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_notify_registration_cnf
 * DESCRIPTION
 * To notify server to start notification service so that it can inform client 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_notify_registration_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*------------------------------btmmiscr----------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_connect_rsp  msg_u;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_mapc_set_notif_registration_cnf_struct *msg_p = (bt_mapc_set_notif_registration_cnf_struct *)msg;
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_NOTIFY_REG_CNF,msg_p->result);

	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;

    if(msg_p->result == SRV_BT_MAPC_SUCCESS /*&& msg_p->mas_id == g_gmap_client_cntx[cntx_index].mas_id*/)
    {
        if(g_gmap_client_cntx[cntx_index].mns_registration == SRV_MAPC_MNS_SETTING_TRUE)
        	g_gmap_client_cntx[cntx_index].mns_registration = SRV_MAPC_MNS_STATE_TRUE;
        else
        	g_gmap_client_cntx[cntx_index].mns_registration = SRV_MAPC_MNS_STATE_FALSE;
        
    }
    msg_u.Error = SRV_BT_MAPC_SUCCESS;
    msg_u.user_data = g_gmap_client_cntx[cntx_index].user_data;
    MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
	if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_CONNECT_RSP, &msg_u);
	if(g_gmap_client_cntx[cntx_index].srv_cm_cb != NULL)
		(*g_gmap_client_cntx[cntx_index].srv_cm_cb)((srv_bt_cm_bt_addr *)&g_gmap_client_cntx[cntx_index].bd_addr,
									SRV_BT_CM_MAPC_CONNECTION, 
									!(msg_p->result), 
									MMI_TRUE, 
									MMI_FALSE);

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_message_status_cnf
 * DESCRIPTION
 * To handle the set message status request's response  
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_set_message_status_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;
    srv_bt_mapc_set_message_status_rsp msg_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    bt_mapc_set_message_status_cnf_struct *msg_p = (bt_mapc_set_message_status_cnf_struct*)msg;

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_MSG_STATUS_CNF,msg_p->result);
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
	
	//if(g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_SET_MESSAGE_STATUS)
	{   
		MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_IDLE);
		msg_rsp.Error = (srv_bt_mapc_result_enum)msg_p->result;
    	msg_rsp.user_data = g_gmap_client_cntx[cntx_index].user_data;
		if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
    		(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_SET_MSG_STATUS_RSP, (void *)&msg_rsp);
    }
	
        
}


/*****************************************************************************
 * FUNCTION
 * srv_mapc_activate_cnf
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_activate_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	 bt_mapc_activate_cnf_struct *msg_p = (bt_mapc_activate_cnf_struct*) msg;
	 
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_CNF,g_gmap_client_cntx[0].state,msg_p->result);

    if (msg_p->result == SRV_BT_MAPC_SUCCESS)
    {
    	U8 cntx_index;
		for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
		{
			if (g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_ACTIVATING)
        	{
				MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_ACTIVATED);
			}
		}
        srv_bt_cm_activate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);// ITS VALUE IS 0X1132
        
    }
    else
    {
        //MMI_ASSERT(0);
    }
    
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_deactivate_cnf
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_deactivate_cnf(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;	
    bt_mapc_deactivate_cnf_struct *msg_p = (bt_mapc_deactivate_cnf_struct*) msg;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ACTIVATE_CNF,g_gmap_client_cntx[0].state,msg_p->result);
    if (msg_p->result == SRV_BT_MAPC_SUCCESS)
	{
		for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
	    {
	    	if (g_gmap_client_cntx[cntx_index].state == SRV_MAPC_STATE_DEACTIVATING)
		    {

		        MMI_MAPC_STATE_TRANS(cntx_index, SRV_MAPC_STATE_INIT);
		        
		    }
		    else
		    {
		        //MMI_ASSERT(0);
		    }
		}
		srv_bt_cm_deactivate_cnf_hdler(SRV_BT_CM_MESSAGE_ACCESS_PROFILE_UUID);
	}	
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_mns_send_event_ind
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_mns_send_event_ind(void *msg)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U8 cntx_index;	
    srv_bt_mapc_mns_send_event_ind_struct msg_ind;
    srv_bt_mapc_mns_send_event_rsp_struct ind_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    bt_mapc_mns_send_event_ind_struct *msg_p = (bt_mapc_mns_send_event_ind_struct *)msg;
	
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(msg_p->addr), msg_p->mas_id);
	if (cntx_index == MAX_MAPC_LINK_SUPPORT 
		&& g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_MAP)
	{
	#ifdef __MMI_BT_MAPC_BY_MAP__
		bt_mapc_mns_send_event_rsp_struct *msg_rsp = construct_local_para(sizeof(bt_mapc_mns_send_event_rsp_struct), TD_CTRL);
        msg_rsp->result = SRV_BT_MAPC_FAIL_NOT_FOUND;
		msg_rsp->addr.lap = msg_p->addr.lap;
        msg_rsp->addr.uap = msg_p->addr.uap;
        msg_rsp->addr.nap = msg_p->addr.nap;
        msg_rsp->mas_id = msg_p->mas_id;
		srv_mapc_send_msg(MSG_ID_BT_MAPC_MNS_SEND_EVENT_RSP, msg_rsp);
	#endif
		return;
	}
    if (g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_IDLE)
    {		
		msg_ind.bt_index = cntx_index;		
		msg_ind.data_size = msg_p->data_size; 
        app_ucs2_strncpy((kal_int8 *)msg_ind.file, (const kal_int8 *)msg_p->file, SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
		if(g_gmap_client_cntx[cntx_index].srv_map_callback != NULL)
        	(*g_gmap_client_cntx[cntx_index].srv_map_callback)(g_gmap_client_cntx[cntx_index].srv_hd, SRV_BT_MAPC_EVT_ID_MNS_IND, (void *)&msg_ind);
    }
    else
    {
		ind_rsp.result = SRV_BT_MAPC_FAIL;
        srv_bt_mapc_mns_send_event_rsp(cntx_index, ind_rsp);
    }    
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_mns_send_event_rsp
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * index_order  :dev index used by sms app in bt cm.
 * indication_rsp
 * is_order  : inder_order is cntx_index or not , FALSE is cntx_index.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_mapc_mns_send_event_rsp (U8 index_order, srv_bt_mapc_mns_send_event_rsp_struct indication_rsp)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_mapc_mns_send_event_rsp_struct *msg_rsp;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SEND_EVENT_RSP_INDEX,index_order);
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return;
#ifdef __MMI_BT_MAPC_BY_MAP__
    if (g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
    {
        msg_rsp = construct_local_para(sizeof(bt_mapc_mns_send_event_rsp_struct), TD_CTRL);
        msg_rsp->result = (bt_map_result_enum)indication_rsp.result;
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_MNS_EVENT_IND_RSP, msg_rsp->result);
        
        msg_rsp->addr.lap = g_gmap_client_cntx[index_order].bd_addr.lap;
        msg_rsp->addr.uap = g_gmap_client_cntx[index_order].bd_addr.uap;
        msg_rsp->addr.nap = g_gmap_client_cntx[index_order].bd_addr.nap;
        msg_rsp->mas_id = g_gmap_client_cntx[index_order].mas_id;
        srv_mapc_send_msg(MSG_ID_BT_MAPC_MNS_SEND_EVENT_RSP, msg_rsp);
    }
#endif /*__MMI_BT_MAPC_BY_MAP__*/
}

/*****************************************************************************
 * FUNCTION
 * srv_mapc_set_event_hdlr
 * DESCRIPTION
 * To handle the authorize indication from server for notificattion service 
 * of any events 
 * message 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
void srv_mapc_set_event_hdlr(void)
{
     /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __MMI_BT_MAPC_BY_MAP__
    SetProtocolEventHandler((PsFuncPtr) srv_mapc_activate_cnf, MSG_ID_BT_MAPC_ACTIVATE_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_mapc_deactivate_cnf, MSG_ID_BT_MAPC_DEACTIVATE_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_connect_cnf, MSG_ID_BT_MAPC_CONNECT_CNF);
    #if 0
/* under construction !*/
    #endif
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_disconnect_cnf, MSG_ID_BT_MAPC_DISCONNECT_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_disconnect_ind, MSG_ID_BT_MAPC_DISCONNECT_IND);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_mns_send_event_ind, MSG_ID_BT_MAPC_MNS_SEND_EVENT_IND);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_abort_cnf, MSG_ID_BT_MAPC_ABORT_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_push_message_cnf,MSG_ID_BT_MAPC_PUSH_MESSAGE_CNF);
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_folder_cnf, MSG_ID_BT_MAPC_SET_FOLDER_CNF);
    #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
    #endif 
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_listing_size_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_SIZE_CNF);
    
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_listing_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_LISTING_CNF);
    
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_get_message_cnf, MSG_ID_BT_MAPC_GET_MESSAGE_CNF);
    
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_notify_registration_cnf, MSG_ID_BT_MAPC_SET_NOTIF_REGISTRATION_CNF);
    
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_update_inbox_cnf, MSG_ID_BT_MAPC_UPDATE_INBOX_CNF);
    
    SetProtocolEventHandler((PsFuncPtr) srv_bt_mapc_set_message_status_cnf, MSG_ID_BT_MAPC_SET_MESSAGE_STATUS_CNF);
#endif /*__MMI_BT_MAPC_BY_MAP__*/
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_set_folder_cnf, SRV_MAPC_ADP_CMD_SET_FOLDER);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_get_message_listing_size_cnf, SRV_MAPC_ADP_CMD_GET_LIST_SIZE);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_spp_connect_cnf, SRV_MAPC_ADP_CMD_CONNECT);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_get_message_listing_cnf, SRV_MAPC_ADP_CMD_GET_LISTING);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_get_message_cnf, SRV_MAPC_ADP_CMD_GET_MSG);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_set_message_status_cnf, SRV_MAPC_ADP_CMD_SET_STATUS);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_push_message_cnf, SRV_MAPC_ADP_CMD_PUSH_MSG);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_mns_send_event_ind, SRV_MAPC_ADP_CMD_EVENT_REPORT);
    srv_bt_mapc_adp_set_callback((MapcAdpCallback)srv_bt_mapc_spp_disconnect_cnf, SRV_MAPC_ADP_CMD_DISCONNECT);  
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/  
    
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_set_msg_listing_prop
 * DESCRIPTION
 * .
 * 
 * PARAMETERS
 * msg 
 * RETURNS
 *  void
 *****************************************************************************/
S8 srv_bt_mapc_set_msg_listing_prop(U8 index_order, srv_bt_mapc_set_msg_listing_prop_struct * msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_set_msg_listing_prop_struct *msg_p = NULL;
    msg_p = (srv_bt_mapc_set_msg_listing_prop_struct *)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_SET_MSG_LIST_PROP_INDEX,index_order);

	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return (S8)-1;
	
    if (g_gmap_client_cntx[index_order].state >= SRV_MAPC_STATE_IDLE)
    {
        g_gmap_client_cntx[index_order].msg_lst_prop.FilterMessageType = msg_p->FilterMessageType;
        g_gmap_client_cntx[index_order].msg_lst_prop.Maxlistcount = msg_p->Maxlistcount;
        g_gmap_client_cntx[index_order].msg_lst_prop.ListStartOffset = msg_p->ListStartOffset;
        g_gmap_client_cntx[index_order].msg_lst_prop.FilterReadStatus = msg_p->FilterReadStatus;
        g_gmap_client_cntx[index_order].msg_lst_prop.FilterPriority = msg_p->FilterPriority;
        g_gmap_client_cntx[index_order].msg_lst_prop.SubjectLength = msg_p->SubjectLength;
		g_gmap_client_cntx[index_order].msg_lst_prop.ParameterMask = msg_p->ParameterMask;
        app_ucs2_strncpy((kal_int8 *)g_gmap_client_cntx[index_order].msg_lst_prop.FilterPeriodBegin, (const kal_int8 *)msg_p->FilterPeriodBegin, SRV_BT_MAP_MAX_DATE_STR_LEN);
        app_ucs2_strncpy((kal_int8 *)g_gmap_client_cntx[index_order].msg_lst_prop.FilterPeriodEnd, (const kal_int8 *)msg_p->FilterPeriodEnd, SRV_BT_MAP_MAX_DATE_STR_LEN);
        app_ucs2_strncpy((kal_int8 *)g_gmap_client_cntx[index_order].msg_lst_prop.FilterRecipient, (const kal_int8 *)msg_p->FilterRecipient, SRV_BT_MAPC_FILTER_SIZE);
        app_ucs2_strncpy((kal_int8 *)g_gmap_client_cntx[index_order].msg_lst_prop.FilterOriginator, (const kal_int8 *)msg_p->FilterOriginator, SRV_BT_MAPC_FILTER_SIZE);
        MMI_MAPC_STATE_TRANS(index_order, SRV_MAPC_STATE_SET_MSG_LISTING_PROPERTY);
        return 0;
        
    }
    else
    {
        return (S8)-1;
    }

}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_connect_type
 * DESCRIPTION
 * 
 * PARAMETERS
 * index_order
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
srv_bt_mapc_connected_enum srv_bt_mapc_connect_type(U8 index_order)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_mapc_connected_enum conn_type;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(!srv_bt_mapc_adp_is_connected(index_order))
		conn_type = SRV_BT_MAPC_CONN_NONE;
	else
		conn_type = g_gmap_client_cntx[index_order].conn_type;
	
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_CONNECT_TYPE,index_order,conn_type);
	
	return conn_type;

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_is_available
 * DESCRIPTION
 * 
 * PARAMETERS
 * index_order
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_mapc_is_available(U8 index_order)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(srv_bt_mapc_adp_is_connected(index_order))
	{
	#ifdef __MMI_BT_MAPC_BY_MAP__
		if(g_gmap_client_cntx[index_order].conn_type == SRV_BT_MAPC_CONN_MAP)
		{			
			if(g_gmap_client_cntx[index_order].state == SRV_MAPC_STATE_IDLE
				|| g_gmap_client_cntx[index_order].state == SRV_MAPC_STATE_CONNECTED)
			{
				ret = MMI_TRUE;
			}
			
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_IS_AVAILABLE_1, g_gmap_client_cntx[index_order].state);
		}
		else
	#endif /*__MMI_BT_MAPC_BY_MAP__*/
		{
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)		
			if(g_mapc_adp_cntx[index_order].adp_state == SRV_MAPC_ADP_IDLE)
			{
				ret = MMI_TRUE;
			}
			
			MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_IS_AVAILABLE_2, g_mapc_adp_cntx[index_order].adp_state);
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)*/

		}

	}
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_IS_AVAILABLE_3, index_order, ret);

	return ret;
}

#endif /*__MMI_BT_MAP_CLIENT__*/
