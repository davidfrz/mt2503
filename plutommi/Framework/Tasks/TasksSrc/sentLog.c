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
 * sentlog.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Protocol task functionality.
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
  *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


/*****************************************************************************
* Include                                                                     
*****************************************************************************/

#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "MMI_features.h"
//#include "tst_trace.h"

#include "mmi_frm_queue_gprot.h"
#include "MMIDataType.h"
#include "SppSrvGprot.h"
//#include "BTMMISpp.h"
//#include "BTMMIScrGprots.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "mmi_cb_mgr_gprot.h"
//#include "mmi_rp_app_bluetooth_def.h"
#include "mmi_frm_scenario_gprot.h"
#include "Fs_gprot.h"
#include "App_str.h"
#include "sent_log.h"

#ifdef __MMI_SENT_LOG_VIA_BT__
/*****************************************************************************
* Define                                                                      
*****************************************************************************/
#ifdef __MMI_SEND_LOG_FOR_MMI__
#define MMI_FRM_LOG_MIN_SIZE 512
#define MMI_FRM_LOG_MAX_SIZE 2048
#define MMI_FRM_LOG_QUEUE_SIZE 12*1024
#define MMI_FRM_LOG_SPP_SIZE 2048+20  //20 for lost
#else
#define MMI_FRM_LOG_MIN_SIZE 0
#define MMI_FRM_LOG_MAX_SIZE 1024*5
#define MMI_FRM_LOG_QUEUE_SIZE 20*1024
#define MMI_FRM_LOG_SPP_SIZE 1024*5  //20 for lost
#endif
#define MMI_FRM_SPP_MIN_BUFF_SIZE (SPP_MIN_TX_BUFSIZE + SPP_MIN_RX_BUFSIZE)
#define MMI_FRM_SPP_TEST_PATH L"z:\\@BTMre\\log.txt"
/*****************************************************************************
* Typedef                                                                     
*****************************************************************************/
typedef struct
{
	MMI_BOOL is_sent_completed;
	U32 left_size;
	U8 buf[MMI_FRM_LOG_SPP_SIZE];
	U8 buf_for_spp[MMI_FRM_SPP_MIN_BUFF_SIZE];
}mmi_frm_log_buf_struct;

typedef struct
{
	SppHandle handle;
	S32 conn_id;	
	S32 is_connected;
	mmi_frm_log_buf_struct buf_cntx;
}mmi_frm_log_cntx_struct;
#define TEST_TIMER_ID 0xF779 //63353 

/*****************************************************************************
* Local Variable                                                              
*****************************************************************************/
static mmi_frm_log_cntx_struct mmi_frm_log_cntx;
static mmi_frm_log_cntx_struct* g_mmi_frm_log_contx = &mmi_frm_log_cntx;
static U8 LOG_SPP_PROFILE_ID[16] = {0x97,0xA4,0x2C,0x60,0xA8,0x26,0x11,0xE4,0x8B,0x1C,0x00,0x02,0xA5,0xD5,0xC5,0x1B};
static U32 test_idx;
static FS_HANDLE fd_handle = -1; 


static U8 log_buf[MMI_FRM_LOG_QUEUE_SIZE];
static U8 log_buf_lost[20];
static U32 log_buf_read;
static U32 log_buf_write;
static U32 log_buf_write_over_max;
static U32 log_buf_is_overwrite;
static U32 log_buf_overwrite_count;

/*****************************************************************************
* Extern Global Variable                                                      
*****************************************************************************/

/*****************************************************************************
* Local Function                                                              
*****************************************************************************/

/*****************************************************************************
* Extern Global Function                                                      
*****************************************************************************/

extern void mmi_frm_trace_via_bt(const char * fmt,...);

void mmi_frm_log_spp_authorize_rsp(srv_bt_cm_bt_addr *bt_addr, U32 profile_id, U32 result)
{
	if (result)
		srv_spp_accept(
			g_mmi_frm_log_contx->conn_id, 
			g_mmi_frm_log_contx->buf_cntx.buf_for_spp, 
			sizeof(g_mmi_frm_log_contx->buf_cntx.buf_for_spp)/2,
			sizeof(g_mmi_frm_log_contx->buf_cntx.buf_for_spp)/2
			);
	else
	{		
		srv_spp_reject(g_mmi_frm_log_contx->conn_id);
		g_mmi_frm_log_contx->conn_id = -1;
	}
}

void mmi_frm_log_spp_authorize_ind(srv_spp_event_cntx* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_event_cntx auth_ind = *(srv_spp_event_cntx*)para;
	//srv_bt_cm_bt_addr dev_addr;


	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
//	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP,MMI_BT_SPP_SERVER_AUTHORIZE_IND, auth_ind.para, auth_ind.ret);

	if (g_mmi_frm_log_contx->conn_id > 0) 
		srv_spp_reject(auth_ind.para);
	else
		g_mmi_frm_log_contx->conn_id = auth_ind.para;

	//srv_spp_get_dev_addr(g_mmi_frm_log_contx->conn_id, &dev_addr);

	srv_spp_accept(
	g_mmi_frm_log_contx->conn_id, 
	g_mmi_frm_log_contx->buf_cntx.buf_for_spp, 
	sizeof(g_mmi_frm_log_contx->buf_cntx.buf_for_spp)/2,
	sizeof(g_mmi_frm_log_contx->buf_cntx.buf_for_spp)/2
	);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void mmi_frm_log_spp_bind_fail_handler(void)
{
//	MMI_TRACE(MMI_BT_SPP_TRACE_GROUP,MMI_BT_SPP_SERVER_BIND_HANDLER);
	srv_spp_close(g_mmi_frm_log_contx->handle);
}

void mmi_frm_log_spp_connect_ind(srv_spp_event_cntx* para)
{
		/*----------------------------------------------------------------*/
		/* Local Variables												  */
		/*----------------------------------------------------------------*/
	
	
		/*----------------------------------------------------------------*/
		/* Code Body													  */
		/*----------------------------------------------------------------*/
	//MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN, disconn_ind.para, disconn_ind.ret);	
		if(para->ret)
		{
			g_mmi_frm_log_contx->is_connected = 1;
			g_mmi_frm_log_contx->buf_cntx.is_sent_completed = 1;

		}
	




}

void mmi_frm_log_spp_ready_write(srv_spp_event_cntx* para)
{
	U32 sent_size;
	if(g_mmi_frm_log_contx->buf_cntx.is_sent_completed == 0 && g_mmi_frm_log_contx->conn_id == para->para)
	{
			sent_size = srv_spp_write(g_mmi_frm_log_contx->conn_id, g_mmi_frm_log_contx->buf_cntx.buf, g_mmi_frm_log_contx->buf_cntx.left_size);
			if(sent_size != g_mmi_frm_log_contx->buf_cntx.left_size)
			{
				g_mmi_frm_log_contx->buf_cntx.is_sent_completed = 0;
				memcpy(g_mmi_frm_log_contx->buf_cntx.buf, g_mmi_frm_log_contx->buf_cntx.buf+sent_size, g_mmi_frm_log_contx->buf_cntx.left_size-sent_size);
				g_mmi_frm_log_contx->buf_cntx.left_size -= sent_size;				
			}
			else
			{
				g_mmi_frm_log_contx->buf_cntx.is_sent_completed = 1;
				g_mmi_frm_log_contx->buf_cntx.left_size = 0;
			}

	}



}


void mmi_frm_log_spp_disconnect(srv_spp_event_cntx* para)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_spp_event_cntx disconn_ind = *(srv_spp_event_cntx*)para;

	/*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
//MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_DISCONN, disconn_ind.para, disconn_ind.ret);

	if (g_mmi_frm_log_contx->conn_id == disconn_ind.para)
	{		
#if !defined(__IOT__)
		//mmi_bt_authorize_screen_close(SRV_BT_CM_SPP_PROFILE_UUID);

#endif
		g_mmi_frm_log_contx->conn_id = -1;
		g_mmi_frm_log_contx->is_connected = 0;
	}

}

S32 mmi_frm_log_event_handler(U32 evt, void* para)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_spp_event_cntx notify_para = *(srv_spp_event_cntx*)para;

	/*----------------------------------------------------------------*/
	/* Code Body												  */
	/*----------------------------------------------------------------*/
	//MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_GET_EVENT_ID, evt);
		
	switch (evt)
	{
		case SRV_SPP_EVENT_BIND_FAIL:
			mmi_frm_log_spp_bind_fail_handler();	
			break;
		case SRV_SPP_EVENT_AUTHORIZE:
			mmi_frm_log_spp_authorize_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_CONNECT:
			mmi_frm_log_spp_connect_ind(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_WRITE:
			mmi_frm_log_spp_ready_write(&notify_para);
			break;
		case SRV_SPP_EVENT_READY_TO_READ:

			break;
		case SRV_SPP_EVENT_DISCONNECT:
			mmi_frm_log_spp_disconnect(&notify_para);
			//mmi_bt_spp_disconnect(&notify_para);
			break;
		default:
			break;
	}
	return MMI_RET_OK;
}

void mmi_frm_log_test_writelog()
{
	
	U32 i;
	for(i=0;i<=150;i++)
	{
		mmi_frm_trace_via_bt("mmi_frm_log_test_writelog %d\n", test_idx++);
	}
	StartTimer(TEST_TIMER_ID, 1000, mmi_frm_log_test_writelog);

}
#endif //__MMI_SENT_LOG_VIA_BT__

void mmi_frm_log_via_usb_init()
{

#ifdef __MMI_SENT_LOG_VIA_BT__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U32 evt_mask = 0;
	WCHAR file_name[80] = {0};

    /*----------------------------------------------------------------*/
    /* Code Body	                                              */
    /*----------------------------------------------------------------*/
    //MMI_TRACE(MMI_BT_SPP_TRACE_GROUP, MMI_BT_SPP_SERVER_INIT);
	g_mmi_frm_log_contx->handle = srv_spp_open();	
	if (g_mmi_frm_log_contx->handle == SRV_SPP_INVALID_HANDLE)
		return;
	
	evt_mask = SRV_SPP_EVENT_BIND_FAIL|
		SRV_SPP_EVENT_AUTHORIZE|
		SRV_SPP_EVENT_CONNECT|
		SRV_SPP_EVENT_READY_TO_WRITE|
		SRV_SPP_EVENT_READY_TO_READ|
		SRV_SPP_EVENT_DISCONNECT;	
	srv_spp_set_notify_hdlr(g_mmi_frm_log_contx->handle, evt_mask, mmi_frm_log_event_handler, NULL);

	srv_spp_bind_128bit_uuid(g_mmi_frm_log_contx->handle, LOG_SPP_PROFILE_ID);

	g_mmi_frm_log_contx->conn_id = -1;
	g_mmi_frm_log_contx->is_connected = 0;
	g_mmi_frm_log_contx->buf_cntx.is_sent_completed = 1;

	//StartTimer(TEST_TIMER_ID, 1000, mmi_frm_log_test_writelog);
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif		   

#endif		   

}

#ifdef __MMI_SENT_LOG_VIA_BT__
MMI_BOOL mmi_frm_log_prepare(void* buf, U32* buf_size)
{
	U32 interval;
	
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare");
	if(buf == NULL)
	{
		return MMI_FALSE;
	}
	if(log_buf_write >= log_buf_read || 
		(log_buf_write_over_max && log_buf_write <= log_buf_read))
	{
		if(log_buf_write_over_max) //if log_buf_write_over_max==1, then must match log_buf_write < log_buf_read
		{
			interval = log_buf_write+MMI_FRM_LOG_QUEUE_SIZE - log_buf_read;
		}
		else
		{
			interval = log_buf_write - log_buf_read;

		}
		kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare interval %d", interval);
		if(interval >= MMI_FRM_LOG_MIN_SIZE && interval <= MMI_FRM_LOG_MAX_SIZE)
		{
			if(log_buf_write_over_max)
			{
				*buf_size = interval;
				interval = MMI_FRM_LOG_QUEUE_SIZE-log_buf_read;
				memcpy(buf, log_buf+log_buf_read, interval);				
				log_buf_write_over_max = 0;				
				memcpy((U8 *)buf+interval, log_buf, log_buf_write);	
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 1");

			}
			else
			{
				if(!log_buf_read && log_buf_overwrite_count)
				{
					memcpy(buf, log_buf_lost, strlen(log_buf_lost));
					memcpy((U8 *)buf+strlen(log_buf_lost), log_buf+log_buf_read, interval);
					*buf_size = interval+strlen(log_buf_lost);
					log_buf_overwrite_count = 0;
				}
				else
				{
					memcpy(buf, log_buf+log_buf_read, interval);
					*buf_size = interval;	
				}
		
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 2");

			}
			log_buf_read = log_buf_write;

		}
		else if(interval > MMI_FRM_LOG_MAX_SIZE)
		{
			if(log_buf_write_over_max)
			{
				if(log_buf_read <= (MMI_FRM_LOG_QUEUE_SIZE - MMI_FRM_LOG_MAX_SIZE))
				{
					memcpy(buf, log_buf+log_buf_read, MMI_FRM_LOG_MAX_SIZE);
					*buf_size = MMI_FRM_LOG_MAX_SIZE;
					log_buf_read += MMI_FRM_LOG_MAX_SIZE;
					kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 3");
				}
				else
				{

					
					*buf_size = MMI_FRM_LOG_MAX_SIZE;
					// cpy the duration to max 
					interval = MMI_FRM_LOG_QUEUE_SIZE-log_buf_read;
					memcpy(buf, log_buf+log_buf_read, interval);				
					log_buf_write_over_max = 0;
					// cpy to the left
					memcpy((U8 *)buf+interval, log_buf, MMI_FRM_LOG_MAX_SIZE-interval);	
					kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 4 buf %x, buf_interval %x, interval %d", buf, (U8 *)buf+interval, interval);
					log_buf_read = MMI_FRM_LOG_MAX_SIZE-interval;
					kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 4");
					
				}
			}
			else
			{
				if(!log_buf_read && log_buf_overwrite_count)
				{
					memcpy(buf, log_buf_lost, strlen(log_buf_lost));
					memcpy((U8 *)buf+strlen(log_buf_lost), log_buf+log_buf_read, MMI_FRM_LOG_MAX_SIZE);
					*buf_size = MMI_FRM_LOG_MAX_SIZE+strlen(log_buf_lost);
					log_buf_overwrite_count = 0;

				}
				else
				{
					memcpy(buf, log_buf+log_buf_read, MMI_FRM_LOG_MAX_SIZE);
					*buf_size = MMI_FRM_LOG_MAX_SIZE;
				}

				log_buf_read += MMI_FRM_LOG_MAX_SIZE;
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 5");
			}
		}
		else
		{
			kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 6");
			return MMI_FALSE;
		}
		return MMI_TRUE;
			
	}
	else
	{
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_log_prepare 7");
		return MMI_FALSE;
	}

}

#endif
mmi_frm_send_log_by_bt()
{
#ifdef __MMI_SENT_LOG_VIA_BT__
	U32 buf_size, sent_size, save_size;
	
	if(g_mmi_frm_log_contx->is_connected)
	{
		if(g_mmi_frm_log_contx->buf_cntx.is_sent_completed && mmi_frm_log_prepare(g_mmi_frm_log_contx->buf_cntx.buf, &buf_size))
		{

			//FS_HANDLE fd = -1;
			sent_size=srv_spp_write(g_mmi_frm_log_contx->conn_id, g_mmi_frm_log_contx->buf_cntx.buf, buf_size);
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
#endif   
			if(sent_size != buf_size)
			{
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_send_log_by_usb, sent_size =%d, buf_size = %d", sent_size, buf_size);
				g_mmi_frm_log_contx->buf_cntx.is_sent_completed = 0;
				memcpy(g_mmi_frm_log_contx->buf_cntx.buf, g_mmi_frm_log_contx->buf_cntx.buf+sent_size, buf_size - sent_size);
				g_mmi_frm_log_contx->buf_cntx.left_size = buf_size - sent_size;				
			}
		}
		
	}
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_send_log_by_usb, r =%d, w=%d, is_sent_completed =%d, index =%d", log_buf_read, log_buf_write,g_mmi_frm_log_contx->buf_cntx.is_sent_completed, test_idx);


   //part 1, check whether need sent
   //part 2,  sent by spp

#endif
}
//MMI_TRACE
//kal_prompt_trace
#ifdef __MMI_SENT_LOG_VIA_BT__
void mmi_frm_trace_lost(const char *fmt,...)
{
	U8 msg_buffer[20], len;
	va_list args;		
	va_start(args, fmt);
	memset(log_buf_lost, 0, 20);
	vsnprintf(log_buf_lost, 20, fmt, args);
	//len = strlen(msg_buffer);
	va_end(args);
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_lost %d");
}
#endif

void mmi_frm_trace_via_bt_int(const char *fmt, va_list args)
{
#ifdef __MMI_SEND_LOG_FOR_MMI__
	U8 msg_buffer[50], len; 
	memset(msg_buffer, 0, 50);
    vsnprintf(msg_buffer, 50, fmt, args);
	len = strlen(msg_buffer);
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt %d, write %d", len, log_buf_write);
	if((log_buf_write+len) <= MMI_FRM_LOG_QUEUE_SIZE)
	{
		
		memcpy(log_buf+log_buf_write, msg_buffer, len);
		log_buf_write += len;
		kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 1");
	}
	else
	{
		U32 temp_len = MMI_FRM_LOG_QUEUE_SIZE - log_buf_write;
		memcpy(log_buf+log_buf_write, msg_buffer, temp_len);
		memcpy(log_buf, msg_buffer+temp_len, len-temp_len);
		log_buf_write = len-temp_len;
		log_buf_write_over_max = 1;
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 2");
	}
	if(log_buf_write_over_max && log_buf_write>=log_buf_read)
	{
			//log_buf_is_overwrite = 1;
			log_buf_overwrite_count = MMI_FRM_LOG_QUEUE_SIZE-log_buf_read;			
			log_buf_write_over_max = 0;			 			
			log_buf_read = 0;
			kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 2");
			mmi_frm_trace_lost("\nLog lost %d\n", log_buf_overwrite_count);
	}

#endif

}

void mmi_frm_trace_for_other_task(U8 *buffer, U16 length)
{
#ifdef __MMI_SENT_LOG_VIA_BT__
#ifndef  __MMI_SEND_LOG_FOR_MMI__    
	kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt %d, write %d", length, buffer);
	if((log_buf_write+length) <= MMI_FRM_LOG_QUEUE_SIZE)
	{
		
		memcpy(log_buf+log_buf_write, buffer, length);
		log_buf_write += length;
		kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 1");
	}
	else
	{
		U32 temp_len = MMI_FRM_LOG_QUEUE_SIZE - log_buf_write;
		memcpy(log_buf+log_buf_write, buffer, temp_len);
		memcpy(log_buf, buffer+temp_len, length-temp_len);
		log_buf_write = length-temp_len;
		log_buf_write_over_max = 1;
				kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 2");
	}
	if(log_buf_write_over_max && log_buf_write>=log_buf_read)
	{
			//log_buf_is_overwrite = 1;
			log_buf_overwrite_count = MMI_FRM_LOG_QUEUE_SIZE-log_buf_read;
			log_buf_write_over_max = 0;
			log_buf_read = 0;   //need mutex protect
			kal_prompt_trace(MOD_MMI,"[Log]mmi_frm_trace_via_bt 3");
			//mmi_frm_trace_lost("\nLog lost %d\n", log_buf_overwrite_count);
			kal_prompt_trace(MOD_MMI, "Log lost %d", log_buf_overwrite_count);
	}
	//StartTimer(TEST_TIMER_ID, 500, mmi_frm_log_test_writelog);

#endif
#endif


}




void mmi_frm_trace_via_bt(const char *fmt,...)
{
#ifdef  __MMI_SEND_LOG_FOR_MMI__ 

	va_list args;	 
	va_start(args, fmt);
	mmi_frm_trace_via_bt_int(fmt, args);
	va_end(args);
#endif
}

