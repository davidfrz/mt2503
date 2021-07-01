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
 *  FmpAppMain.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file implements the fmp application.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/****************************************************************************
 * Include
 ****************************************************************************/
#include "MMI_features.h"


#ifdef __MMI_BLE_DOGP_SUPPORT__ 
#include "Stdlib.h"
#include "MMIDataType.h"
#include "Unicodexdcl.h" 
#include "Che_api.h"
#include "kal_public_api.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "MMI_trc_Int.h"
#if !defined(__IOT__)
#include "mmi_rp_app_bluetooth_def.h"
#endif
#include "mmi_frm_scenario_gprot.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_cb_mgr_gprot.h"
#include "MMI_conn_app_trc.h" 
#include "BtcmSrvGprot.h"

#include "SogpsAdpSrvGprot.h"
#include "SogpsAdpSrv.h"
#include "mmi_rp_srv_bt_noti_def.h"
#include "Sogps_def.h"
#include "SogpCommon.h"

/****************************************************************************
 * Global and define
 ****************************************************************************/
S32 sogps_ut_mre_read_data(void* buf, U32 len);

sogps_adp_srv_context_t g_sogp_adp_srv_context = {0};
sogps_callback_t g_sogps_adp_srv_cb;

static FS_HANDLE mre_test_handle = 0;   
static S32 s_sogps_adp_srv_conn_id_counter = 0;

#define multilink

#ifdef multilink
#define SOGP_ADP_ADDR_SIZE                   6
char g_sogp_adp_addr[SOGP_ADP_ADDR_SIZE];
char g_sogp_base_addr[SOGP_ADP_ADDR_SIZE] = {0};
#endif

void srv_sogps_adp_get_bt_device_addr(U8 *src, srv_bt_cm_bt_addr *dst)
{
    dst->lap = 0; // clear the MSB
    memcpy((U8 *)&dst->lap, (U8 *)&src[0], 3);
    dst->uap = src[3];
    memcpy((U8 *)&dst->nap, (U8 *)&src[4], 2);
}

static void srv_sogps_adp_send_connect_indication(U8 cntx_chnl, S32 ret_code, char* bdaddr)
{
    srv_sogps_adp_connect_ind_struct event;
    
    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] connect ind");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_SEND_CONN_IND);
	
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SOGPS_CONNECT_IND);
    event.conn_id = 0; //s_sogps_adp_srv_conn_id_counter++;
    event.result = ret_code;
    srv_sogps_adp_get_bt_device_addr((U8*)bdaddr, &(event.bt_addr) );

    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}

static void srv_sogps_adp_send_disconnect_indication(U8 cntx_chnl, MMI_BOOL ret_code, char* bdaddr)
{
    srv_sogps_adp_disconnect_ind_struct event;

    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] disconnect ind");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_SEND_DISCONN_IND);
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SOGPS_DISCONNECT_IND);
    event.conn_id = cntx_chnl;
    event.result = ret_code;
    srv_sogps_adp_get_bt_device_addr((U8*)bdaddr, &(event.bt_addr) );

    //MMI_TRACE(MMI_CONN_TRC_G7_BT,TRC_SRV_BT_NOTIFY_CAPC_NOTIFYAPP,event.ret_code,event.ret_is_num);
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}

static void srv_sogps_adp_send_read_indication(U8 cntx_chnl, MMI_BOOL ret_code, char* bdaddr)
{
    srv_sogps_adp_ready_to_read_ind_struct event;

    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] read ind");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_SEND_READ_IND);
	
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SOGPS_READY_TO_READ);
    event.conn_id = cntx_chnl;
    event.result = ret_code;
    srv_sogps_adp_get_bt_device_addr((U8*)bdaddr, &(event.bt_addr) );
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}

static void srv_sogps_adp_send_write_indication(U8 cntx_chnl, MMI_BOOL ret_code, char* bdaddr )
{
    srv_sogps_adp_ready_to_write_ind_struct event;

    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] write ind");
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_SEND_WRITE_IND);
    
    MMI_FRM_INIT_EVENT(&event, EVT_ID_SOGPS_READY_TO_WRITE);
    event.conn_id = cntx_chnl;
    event.result = ret_code;
	
    srv_sogps_adp_get_bt_device_addr((U8*)bdaddr, &(event.bt_addr) );
    MMI_FRM_CB_EMIT_POST_EVENT(&event);
}


U32 srv_sogps_adp_read(U32 conn_id, void* buf, U32 len)
{
    U32 read_size = 0;
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    if(cntx_p->recv_buf_len > len)
    {
        read_size = len;      
    }
    else
    {
        read_size = cntx_p->recv_buf_len;  
    }
    
    if(read_size == 0)
    {
    
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_READ, buf, len, read_size, cntx_p->recv_buf_len);
        //kal_prompt_trace(MOD_BT, "[SOGPS ADP] read data: buf=%x size=%d read=%d recv_buf_len=%d", buf, len, read_size, cntx_p->recv_buf_len);
        return 0;
    }
    memcpy(buf, cntx_p->recv_buf, read_size);

    if(cntx_p->recv_buf_len > read_size)
    {
        //move left data to head
        memmove(cntx_p->recv_buf, &(cntx_p->recv_buf[read_size]), (cntx_p->recv_buf_len - read_size) );
        cntx_p->recv_buf_len -= read_size;   
    }
    else
    {
        cntx_p->recv_buf_len = 0;
    }
	
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_READ, buf, len, read_size, cntx_p->recv_buf_len);

    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] read data: buf=%x size=%d read=%d recv_buf_len=%d", buf, len, read_size, cntx_p->recv_buf_len);
    return read_size;
}

void srv_sogps_adp_get_bd_addr(BD_ADDR *dst,const srv_bt_cm_bt_addr *src)
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


S32 srv_sogps_adp_write_ext(U32 conn_id, srv_bt_cm_bt_addr* bt_addr, void* buf, U32 len, S32 *err_code)
{
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
    S32 send_size = 0;
	BD_ADDR remote_addr;

    if(len > (SOGP_ADP_SRV_SEND_BUFFER_SIZE - cntx_p->send_buf_len ))
    {
        //buffer full
        *err_code =  -1;
    }
    else
    {
        memcpy(&(cntx_p->send_buf[cntx_p->send_buf_len]), buf, len);        
        cntx_p->send_buf_len += len; 
 #ifdef __MTK_TARGET__  
        srv_sogps_adp_get_bd_addr(&remote_addr, bt_addr);
        send_size = sogps_send_data(buf,(char*)remote_addr.addr, len, err_code); 
 #else
        send_size = len;
 #endif
    }
    
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_WRITE, buf, len, *err_code, cntx_p->send_buf_len);
    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] write data: buf = %x len=%d err=%d send_buf_len=%d", buf, len, *err_code, cntx_p->send_buf_len);
    
    return send_size;
}

/****************************************************************************
 * Function
 ****************************************************************************/
void srv_sogps_adp_connect_state_cb(char* bdaddr, int connect_state)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] sogps connect state:%d", connect_state);
	MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_CONNECT_CB, connect_state);
#ifdef multilink
	if ((NULL == bdaddr) || 
	(memcmp(bdaddr, &g_sogp_base_addr,  SOGP_ADP_ADDR_SIZE) == 0))
	{	
	    return;
	}
	
	if (0 == memcmp((char *)g_sogp_adp_addr, bdaddr, SOGP_ADP_ADDR_SIZE) ||
		(0 == memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE))) 
#endif
	{
        switch(connect_state)
        {
            case SOGP_STATUS_DISCONNECTED:
                cntx_p->is_connect = MMI_FALSE;
                cntx_p->send_buf_start = 0;
                cntx_p->send_buf_len = 0;
                cntx_p->recv_buf_start = 0;
                cntx_p->recv_buf_len = 0;
                srv_sogps_adp_send_disconnect_indication(0, MMI_TRUE, bdaddr);
			#ifdef multilink
				if (memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE) != 0)
				{
					memset(g_sogp_adp_addr, 0x00, SOGP_ADP_ADDR_SIZE);
				}
			#endif
	            break;
	        case SOGP_STATUS_CONNECTED:
	            cntx_p->is_connect = MMI_TRUE;
			#ifdef multilink
				memset(g_sogp_adp_addr, 0x00, SOGP_ADP_ADDR_SIZE);
				memcpy((CHAR *)g_sogp_adp_addr, bdaddr, SOGP_ADP_ADDR_SIZE);
			#endif	
                srv_sogps_adp_send_connect_indication(0, MMI_TRUE, bdaddr);
                srv_sogps_adp_send_read_indication(0, MMI_TRUE, bdaddr);
                srv_sogps_adp_send_write_indication(0, MMI_TRUE, bdaddr);
                break;
            case SOGP_STATUS_DISCONNECTING:
                break;
            case SOGP_STATUS_CONNECTING:
                break;
            default:
                break;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  mmi_fmpapp_target_alert_notify_cb
 * DESCRIPTION
 *  to notify mmi task start/stop alert
 * PARAMETERS
 *  [bdaddr] Remote bluetooth device addr
 *  [connect_state] profile current connection state
 * RETURNS
 *  void
 *****************************************************************************/
S32 srv_sogps_adp_data_to_read_notify_cb(char* bdaddr,const U8* buf, U32 len)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef multilink
	if ((NULL == bdaddr) || 
	(memcmp(bdaddr, &g_sogp_base_addr,	SOGP_ADP_ADDR_SIZE) == 0))
	{	
		return -1;
	}
		
	if (0 == memcmp((char *)g_sogp_adp_addr, bdaddr, SOGP_ADP_ADDR_SIZE) ||
		(0 == memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE))) 
#endif
	{

	    if(len > (SOGP_ADP_SRV_RECV_BUFFER_SIZE - cntx_p->recv_buf_len ))
	    {
	        //buffer full
	        //kal_prompt_trace(MOD_BT, "[SOGPS ADP] data to read cb: [%x %x] , len=%d, recv_buf_len=%d", buf[0], buf[len-1], len,cntx_p->recv_buf_len);
	        //kal_prompt_trace(MOD_BT, "[SOGPS ADP] data to read cb: buffer full");
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_BUFFER_FULL);
	        return -1;
	    }

	    memcpy(&(cntx_p->recv_buf[cntx_p->recv_buf_len]), buf, len);        
	    cntx_p->recv_buf_len += len;   
    
        srv_sogps_adp_send_read_indication(0, MMI_TRUE, bdaddr);

	    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] data to read cb: [%x %x] , len = %d, recv_buf_len=%d", buf[0], buf[len-1], len,cntx_p->recv_buf_len);
    
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_READ_NOTIFY_CB, buf[0], buf[len-1], len, cntx_p->recv_buf_len);
	    return 0;
	}
	return -1;
}

S32 srv_sogps_adp_read_data_request_cb(U32 conn_id, char* bdaddr, void* buf, U32 len)
{
    S32 read_size = 0;
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
    S32 err_code = 0;
#ifdef multilink
	if ((NULL == bdaddr) || 
	(memcmp(bdaddr, &g_sogp_base_addr,	SOGP_ADP_ADDR_SIZE) == 0))
	{	
		return -1;
	}
		
	if (0 == memcmp((char *)g_sogp_adp_addr, bdaddr, SOGP_ADP_ADDR_SIZE) ||
		(0 == memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE))) 
#endif
	{       
	    if(cntx_p->send_buf_len > len)
	    {
	        read_size = len;      
	    }
	    else
	    {
	        read_size = cntx_p->send_buf_len;  
	    }
	    
	    if(read_size == 0)
	    {
	        //kal_prompt_trace(MOD_BT, "[SOGPS ADP] read data cb: buf=%x size=%d read=%d send_buf_len=%d", buf, len, read_size,cntx_p->send_buf_len);
			MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_READ_REQUEST_CB, buf, len, read_size,cntx_p->send_buf_len);
			return 0;
	    }
	    
	    memcpy(buf, cntx_p->send_buf, read_size);

	    if(cntx_p->send_buf_len > read_size)
	    {
	        //move left data to head
	        memmove(cntx_p->send_buf, &(cntx_p->send_buf[read_size]), (cntx_p->send_buf_len - read_size) );
	        cntx_p->send_buf_len -= read_size; 

	        //send indicaiton
	     #ifdef __MTK_TARGET__       
	        sogps_send_data(&(cntx_p->send_buf[0]), bdaddr, cntx_p->send_buf_len, &err_code); 
	     #else
	        // do nothing
	     #endif
		    MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_SEND_DATA, &(cntx_p->send_buf[0]), cntx_p->send_buf_len, err_code);

	        //kal_prompt_trace(MOD_BT, "[SOGPS ADP] send indicaiton: buf=%x send_buf_len=%d err=%d", &(cntx_p->send_buf[0]), cntx_p->send_buf_len, err_code);
	    }
	    else
	    {
	        cntx_p->send_buf_len = 0;
	    }
		MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_SOGP_ADP_READ_REQUEST_CB, buf, len, read_size,cntx_p->send_buf_len);

	    //kal_prompt_trace(MOD_BT, "[SOGPS ADP] read data cb: buf=%x size=%d read=%d send_buf_len=%d", buf, len, read_size,cntx_p->send_buf_len);
	    return read_size;
	}
	return -1;
}

void srv_sogps_adp_init()
{
    g_sogps_adp_srv_cb.connection_state_cb = srv_sogps_adp_connect_state_cb;
    g_sogps_adp_srv_cb.data_to_read_notify_cb = srv_sogps_adp_data_to_read_notify_cb;
    g_sogps_adp_srv_cb.read_data_request_cb  = srv_sogps_adp_read_data_request_cb;
#ifdef multilink
	if (memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE) != 0)
	{
		memset(g_sogp_adp_addr, 0x00, SOGP_ADP_ADDR_SIZE);
	}
#endif       
    sogps_init(&g_sogps_adp_srv_cb);
}

void srv_sogps_adp_deinit()
{
#ifdef multilink
	if (memcmp(&g_sogp_adp_addr, &g_sogp_base_addr, SOGP_ADP_ADDR_SIZE) != 0)
	{
		memset(g_sogp_adp_addr, 0x00, SOGP_ADP_ADDR_SIZE);
	}
#endif          
    sogps_deinit();
}



/*****************************************************************************
 * FUNCTION
 *  mmi_bt_event_notify_fmpapp
 * DESCRIPTION
 *  This function is to received service event
 * PARAMETERS
 *  void
 *
 *
 * RETURNS
 *  void
 *****************************************************************************/
void srv_sogps_adp_bt_event_hdlr(U32 event, void* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (event)
    {
        case SRV_BT_CM_EVENT_BLE_ACTIVATE:
            srv_sogps_adp_init();
            break;

        case SRV_BT_CM_EVENT_BEGIN_DEACTIVATE:
            srv_sogps_adp_deinit();
            break;

		default :
			break;
	}
}

void srv_sogps_adp_bootup_init(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 event_mask;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/	
	//MMI_TRACE(MMI_CONN_TRC_G7_BT, TRC_BLE_FMPAPP_CLIENT_INIT);
	event_mask = SRV_BT_CM_EVENT_BLE_ACTIVATE |
				 SRV_BT_CM_EVENT_BEGIN_DEACTIVATE;
	srv_bt_cm_set_notify((srv_bt_cm_notifier)srv_sogps_adp_bt_event_hdlr, event_mask, NULL);
	return; 
}

void srv_sogps_adp_write_remote_device_type(CONN_DEV_TYPE_ENUM dev_type)
{
	U8 device_type = dev_type;
	sogps_conn_param_interval_set_high_level(device_type);
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
#endif

U8 sogps_ut_handle(U8 index, kal_uint8 *string)
{
    sogps_adp_srv_context_t* cntx_p = &g_sogp_adp_srv_context; 
    S32 err_code;

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
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
  #ifndef __MTK_TARGET__           
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
 #endif        
/* under construction !*/
/* under construction !*/
#endif 

    return 0;
}



#endif  /* __MMI_BLE_DOGP_SUPPORT__  */

