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
 * BLEcmSrvPrmt.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for MTK bluetooth primitive handle with BT stack
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"
#ifdef __MMI_BT_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "BLEcmSrvProt.h"
#include "BLESrvGprot.h"
#include "bluetooth_bm_struct.h"

#include "conversions.h"
#include "bluetooth_struct.h"

#include "app_ltlcom.h"
#include "l4c_common_enum.h"
#include "stack_common.h"
#include "stack_config.h"
#include "stack_msgs.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "mmiapi_dm_struct.h"
#include "string.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"
#include "BtcmSrvGprot.h"
#include "mmi_rp_srv_blecm_def.h"

/*****************************************************************
*Internal functions
*****************************************************************/

static void srv_ble_cm_dev_update_name(const srv_bt_cm_bt_addr* dev_addr, const U8* dev_name, U32 name_len);

/*****************************************************************************
 * FUNCTION
 *  srv_ble_discovery_result_ind_hdler
 * DESCRIPTION
 *  This function is to handle discovery result indication and to process found device
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/

U8 srv_ble_discovery_result_ind_hdler(void* msg)
{

	
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U16 i = 0;
	U32 j, name_len;
	bt_bm_discovery_result_ind_struct* msg_p = (bt_bm_discovery_result_ind_struct*)msg;
	srv_bt_cm_inquiry_indication_struct para;
	U8 dev_name[SRV_BT_CM_BD_UCS2_NAME_LEN] = {0};
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_DISCOVERY_RESULT_IND_HDLER,
		msg_p->cod,
		((msg_p->bd_addr.nap & 0xff00) >> 8),
		(msg_p->bd_addr.nap & 0x00ff),
		(msg_p->bd_addr.uap),
		((msg_p->bd_addr.lap & 0xff0000) >> 16),
		((msg_p->bd_addr.lap & 0x00ff00) >> 8),
		(msg_p->bd_addr.lap & 0x0000ff),
		g_srv_ble_cm_cntx.dev_state.state);


	if ((g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIRING) && 
		(g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIR_RES_IND))
	{
		return 0;
	}
	
	if( msg_p->device_type == BTBM_DEVICE_TYPE_BR_EDR)
		return 0;


	if (srv_ble_cm_get_dev_info_by_addr((srv_bt_cm_bt_addr*)(&msg_p->bd_addr), SRV_BLE_CM_DISCOVERED_DEV))
	{
		return 0;
	}

    name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
		(SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
		msg_p->name_len;
	

	if (name_len)
	{
		memcpy(dev_name, (U8*)msg_p->name, SRV_BT_CM_BD_UCS2_NAME_LEN-1);
		dev_name[SRV_BT_CM_BD_UCS2_NAME_LEN-1] = '\0';
	}
	else
	{
		name_len = SRV_BT_CM_BD_UCS2_NAME_LEN - 1;
		if (&msg_p->bd_addr && dev_name && !dev_name[0])
		{
			kal_sprintf(dev_name,"%02x:%02x:%02x:%02x:%02x:%02x",
		        (msg_p->bd_addr.nap&0xff00)>>8, msg_p->bd_addr.nap&0x00ff,
		         msg_p->bd_addr.uap, (msg_p->bd_addr.lap&0xff0000)>>16,
		        (msg_p->bd_addr.lap&0x00ff00)>>8, (msg_p->bd_addr.lap&0x0000ff));
		}
	}


    
	//srv_ble_cm_dev_update_name((srv_bt_cm_bt_addr*)&msg_p->bd_addr, dev_name, name_len);

	srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_INQUIR_RES_IND);
	i = g_srv_ble_cm_cntx.discovered_dev_num;
    g_srv_ble_cm_cntx.scan_list[i].cod = msg_p->cod;
	srv_ble_cm_copy_addr(&g_srv_ble_cm_cntx.scan_list[i].le_bd_addr,(srv_bt_cm_bt_addr*)&msg_p->bd_addr);
	srv_ble_cm_copy_n_utf8_chars(
                    g_srv_ble_cm_cntx.scan_list[i].name,
                    SRV_BT_CM_BD_FNAME_LEN,
                    (U8*)dev_name,
                    name_len);
	for (i = 0; i < SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST; i++)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_SEARCHED_LIST,
			i,
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.uap),
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_cntx.scan_list[i].le_bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_cntx.discovered_dev_num);
	}

// the flow:  service list need 
	g_srv_ble_cm_cntx.discovered_dev_num++;
	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_INCREASE_DISCOVERED_DEV_NUM,
		g_srv_ble_cm_cntx.discovered_dev_num);
	MMI_BT_ASSERT(g_srv_ble_cm_cntx.discovered_dev_num <= SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST);

	MMI_FRM_INIT_EVENT(&para, SRV_LE_CM_EVENT_INQUIRY_IND); 

	para.discovered_dev_num = g_srv_ble_cm_cntx.discovered_dev_num;
	
	mmi_frm_cb_emit_event((mmi_event_struct*)&para);
	return 0;

}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_discovery_update_ind_hdler
 * DESCRIPTION
 *  This function is to handle discovery update indication and to process found device
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/

U8 srv_ble_discovery_update_ind_hdler(void* msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	U32 i = 0;
	U32 j, name_len;
	bt_bm_discovery_result_ind_struct* msg_p = (bt_bm_discovery_result_ind_struct*)msg;
	srv_bt_cm_inquiry_indication_struct para;
	srv_bt_cm_dev_struct* dev_p =(srv_bt_cm_dev_struct*)srv_ble_cm_get_dev_info_by_addr((const srv_bt_cm_bt_addr*)(&msg_p->bd_addr), SRV_BLE_CM_DISCOVERED_DEV);

    /*----------------------------------------------------------------*/
    /* Code Body                                                                                */
    /*----------------------------------------------------------------*/

	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_DISCOVERY_RESULT_IND_HDLER,
		msg_p->cod,
		((msg_p->bd_addr.nap & 0xff00) >> 8),
		(msg_p->bd_addr.nap & 0x00ff),
		(msg_p->bd_addr.uap),
		((msg_p->bd_addr.lap & 0xff0000) >> 16),
		((msg_p->bd_addr.lap & 0x00ff00) >> 8),
		(msg_p->bd_addr.lap & 0x0000ff),
		g_srv_ble_cm_cntx.dev_state.state);

	if ((g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIRING) && 
		(g_srv_ble_cm_cntx.dev_state.state != SRV_BLE_CM_STATE_INQUIR_RES_IND))
	{
		return 0;
	}
	if( msg_p->device_type ==BTBM_DEVICE_TYPE_BR_EDR)
		return 0;
	
	if (dev_p)
	{
		name_len = msg_p->name_len > (SRV_BT_CM_BD_UCS2_NAME_LEN - 1) ?
			(SRV_BT_CM_BD_UCS2_NAME_LEN - 1) :
			msg_p->name_len;
		srv_ble_cm_dev_update_name((srv_bt_cm_bt_addr*)&msg_p->bd_addr, (U8*)msg_p->name, name_len);
		
		i = srv_ble_cm_get_dev_index((srv_bt_cm_bt_addr*)&msg_p->bd_addr, SRV_BLE_CM_DISCOVERED_DEV);
		if (i == 0xFFFFFFFF)
		{
			return 0;
		}
		srv_ble_cm_copy_n_utf8_chars(g_srv_ble_cm_cntx.scan_list[i].name,
								SRV_BT_CM_BD_FNAME_LEN,	msg_p->name, name_len);		
	}	
	srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_INQUIR_RES_IND);

	MMI_TRACE(
		MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_INCREASE_DISCOVERED_DEV_NUM,
		g_srv_ble_cm_cntx.discovered_dev_num);
	MMI_BT_ASSERT(g_srv_ble_cm_cntx.discovered_dev_num <= SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST);

	MMI_FRM_INIT_EVENT(&para, SRV_LE_CM_EVENT_INQUIRY_IND); 

	para.discovered_dev_num = g_srv_ble_cm_cntx.discovered_dev_num;

    mmi_frm_cb_emit_event((mmi_event_struct*)&para);
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handler discovery confirm and send the event to mmi
 * PARAMETERS
 *  msg         [IN]        inter layer message                          
 * RETURNS
 *  void
 *****************************************************************************/

U8 srv_ble_discovery_cnf_hdler(void* msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	bt_bm_discovery_cnf_struct* msg_p = (bt_bm_discovery_cnf_struct*)msg;
    srv_bt_cm_inquiry_complete_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_DISCOVERY_CNF, g_srv_ble_cm_cntx.dev_state.state);
	MMI_FRM_INIT_EVENT(&para, SRV_LE_CM_EVENT_INQUIRY_COMPLETE); 

    switch (g_srv_ble_cm_cntx.dev_state.state)
    {

	    case SRV_BLE_CM_STATE_INQUIR_CANCELLING:			
			srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
            para.result = msg_p->result;
            para.is_cancelled = MMI_TRUE;
		    mmi_frm_cb_emit_event((mmi_event_struct*)&para);
            break;

        default:
			srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
            if (msg_p->result == BTBM_ADP_SUCCESS)
            {
                if(msg_p->total_number == g_srv_ble_cm_cntx.discovered_dev_num)
                {
                    para.result = BTBM_ADP_SUCCESS;
                }
                else
                {
                    para.result = BTBM_ADP_FAILED;
                }
            }
            else
            {
                para.result = msg_p->result;
            }

            para.is_cancelled = MMI_FALSE;

			    		
		    mmi_frm_cb_emit_event((mmi_event_struct*)&para);
            break;
    }
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cancel_discovery_cnf_hdler
 * DESCRIPTION
 *  This function is to handle cancel discovery confirm and send event to mmi
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/

U8 srv_ble_cancel_discovery_cnf_hdler(void* msg)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	bt_bm_discovery_cancel_cnf_struct* msg_p = (bt_bm_discovery_cancel_cnf_struct*)msg;
    srv_bt_cm_inquiry_complete_struct para;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(
	    MMI_CONN_TRC_G7_BT,
	    SRV_BLE_CM_CANCEL_DISCOVERY_CNF_HDLER,
	    g_srv_ble_cm_cntx.dev_state.state);

	if ((g_srv_ble_cm_cntx.dev_state.state == SRV_BLE_CM_STATE_INQUIRING) ||
		  (g_srv_ble_cm_cntx.dev_state.state == SRV_BLE_CM_STATE_INQUIR_RES_IND) ||
		  (g_srv_ble_cm_cntx.dev_state.state == SRV_BLE_CM_STATE_INQUIR_CANCELLING))
	{

		srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
	    MMI_FRM_INIT_EVENT(&para, SRV_LE_CM_EVENT_INQUIRY_COMPLETE); 
		para.result = msg_p->result;
		para.is_cancelled = MMI_TRUE;	
		mmi_frm_cb_emit_event((mmi_event_struct*)&para);
	}
	return 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_dev_update_name
 * DESCRIPTION
 *  This function is to update the device name.
 * PARAMETERS
 *  dev_addr         [IN]        inter layer message    
 *  dev_name         [IN]       the device name
 *  name_len         [IN]       the name's length
 * RETURNS
 *  void
 *****************************************************************************/

static void srv_ble_cm_dev_update_name(const srv_bt_cm_bt_addr* dev_addr, const U8* dev_name, U32 name_len)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

    U32 i;
    /*----------------------------------------------------------------*/
    /* Code Body                                                                                */
    /*----------------------------------------------------------------*/

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_DEV_UPDATE_NAME,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        dev_name);

    if (dev_name)
    {
        i = srv_ble_cm_get_dev_index(dev_addr, SRV_BLE_CM_DISCOVERED_DEV);
        if (i < SRV_BLE_CM_MAX_DISCOVERY_RESULTS_IN_LIST)
        {
                srv_ble_cm_copy_n_utf8_chars(
                    g_srv_ble_cm_cntx.scan_list[i].name,
                    SRV_BT_CM_BD_FNAME_LEN,
                    (U8*)dev_name,
                    name_len);
            
        }
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_write_scanenable_mode_cnf
 * DESCRIPTION
 *  This function is to handle write scanenable mode confirm
 * PARAMETERS
 *  msg         [IN]        inter layer message              
 * RETURNS
 *  void
 *****************************************************************************/
U8 srv_ble_cm_write_scanenable_mode_cnf(void* msg)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    bt_bm_write_scanenable_mode_cnf_struct* msg_p = (bt_bm_write_scanenable_mode_cnf_struct*)msg;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_WRITE_SCANENABLE_MODE_CNF,
        g_srv_ble_cm_cntx.dev_state.state,
        msg_p->result);


  //  if (msg_p->result == BTBM_ADP_SUCCESS)
    {
     //  
		if (srv_ble_cm_get_state() == SRV_BLE_CM_STATE_VISIBILITY_SETTING)
		{
			
		    srv_bt_cm_set_visibility_struct para;
			MMI_FRM_INIT_EVENT(&para, SRV_LE_CM_EVENT_SET_VISIBILITY); 
			if(msg_p->result == BTBM_ADP_SUCCESS)
			{
				para.result = MMI_TRUE;

			}
			else
			{
				para.result = MMI_FALSE;

			}				
		    para.is_from_mmi = MMI_TRUE;   
		
			mmi_frm_cb_emit_event((mmi_event_struct*)&para);
			
		    srv_ble_cm_set_state(NULL, SRV_BLE_CM_STATE_IDLE);
		}
    }
    

   /* else
    {
        MMI_BT_ASSERT(0);
    }*/

    return 0;
}


#endif /* __MMI_BT_SUPPORT__ */ 
