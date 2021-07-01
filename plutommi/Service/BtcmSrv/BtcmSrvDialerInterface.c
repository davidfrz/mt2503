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
 * BtcmSrvInterface.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM external API and internal API declaration
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "MMI_features.h"

#ifdef __MMI_BT_SUPPORT__
/***************************************************************************** 
* Included files
*****************************************************************************/
#include "BtcmSrvGprot.h"
#include "BtcmSrvProt.h"
#include "bluetooth_bm_struct.h"

#include "conversions.h"

// RHR: add
#include "MMIDataType.h"
#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "string.h"
#include "mmiapi_dm_struct.h"
#include "wgui_categories_list.h"
#include "CustDataRes.h"
#include "mmi_frm_events_gprot.h"
#include "GlobalResDef.h"
#include "app_ltlcom.h"
#include "stack_config.h"
//#include "stack_ltlcom.h"
#include "stack_common.h"
#include "stack_msgs.h"
#include "nvram_common_defs.h"
#include "mmi_frm_nvram_gprot.h"
#include "kal_general_types.h"
//#include "TimerEvents.h"
#include "mmi_frm_timer_gprot.h"
#include "mmi_frm_mem_gprot.h"
#include "kal_public_api.h"
#include "bluetooth_struct.h"
// RHR: add
#include "mmi_rp_srv_btcm_def.h"
#include "SimCtrlSrvGprot.h"
#ifdef __MMI_BTBOX_NOLCD__
#include "BT_common_config.h"
#endif  //__MMI_BTBOX_NOLCD__

#ifndef MMI_BT_LINK_MAX_NUM
#ifdef __BT_MAX_LINK_NUM__
#define MMI_BT_LINK_MAX_NUM __BT_MAX_LINK_NUM__
#else
#define MMI_BT_LINK_MAX_NUM 1
#endif
#endif
/*Extern part*/
extern const U16 profile_id_to_connect_type_map[SRV_BT_CM_NUM_OF_PROFILE_UUID][2];
extern const U32 inq_prof_tbl_len;
extern const U32 inquiry_profile_tbl[];
extern srv_bt_cm_hdlr_struct srv_bt_cm_handle[SRV_BT_CM_MAX_INSTANCE_NUM];

typedef struct
{
	MMI_BOOL auto_reconn;
	MMI_BOOL linked;
	U32 busy_conn;
	S32 stamp;
	srv_bt_cm_dev_struct* dev_info;
}srv_bt_cm_dialer_linked_struct;

static srv_bt_cm_dialer_linked_struct g_linked_dev_tbl[MMI_BT_LINK_MAX_NUM];
static MMI_BOOL g_srv_bt_cm_prevent_conn_flag;
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_mapped_index
 * DESCRIPTION
 *  This function converts a device in linked table to related index.
 * PARAMETERS
 *  dev_addr		[IN]		the device
 * RETURNS
 *  S32            the index of the node, -1 if there is no node which meet the condition.
 *****************************************************************************/
static S32 srv_bt_cm_get_mapped_index(const srv_bt_cm_bt_addr* dev_addr)
{

	 /*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/	
	 S32 index = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	for(; index < MMI_BT_LINK_MAX_NUM; ++index)
	{   
	    if (g_linked_dev_tbl[index].dev_info == NULL)
            continue;
        
		if (srv_bt_cm_is_dev_addr_equal(dev_addr, &g_linked_dev_tbl[index].dev_info->bd_addr))
		{
			break;
		}
	}
	if(index == MMI_BT_LINK_MAX_NUM)
	{
		index = -1;
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_MAPPED_INDEX,
                ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
                (dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
                ((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
                index);

	return index;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_empty_linked_index
 * DESCRIPTION
 *  This function is to get a node which is not in connecting or connected.
 * PARAMETERS
    void
 * RETURNS
 *  S32            the index of the node, -1 if there is no node which meet the condition.
 *****************************************************************************/
static S32 srv_bt_cm_get_empty_linked_index(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 index = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	while(index<MMI_BT_LINK_MAX_NUM)
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_EMPTY_LINKED_INDEX, index, 
			g_linked_dev_tbl[index].dev_info, (S32)g_linked_dev_tbl[index].linked);

		if(g_linked_dev_tbl[index].dev_info == NULL || 
			g_linked_dev_tbl[index].linked == MMI_FALSE)
		{
			break;
		}
		++index;
	}
	if(index == MMI_BT_LINK_MAX_NUM)
	{
		index = -1;
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_EMPTY_LINKED_INDEX_2,index);

	return index;
}


MMI_BOOL srv_bt_cm_is_dev_in_link_table(const srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_TRUE;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	if (srv_bt_cm_get_mapped_index(dev_addr) == -1)
	{
		ret = MMI_FALSE;
	}

	return ret;
}

MMI_BOOL srv_bt_cm_up_to_max_link_num(void)
{
    return (srv_bt_cm_get_linked_dev_list_idx() == MMI_BT_LINK_MAX_NUM);
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_profile_connected_ex
 * DESCRIPTION
 *  This function is to check if XXX profile connected
 * PARAMETERS
 *  conn_type       [IN]        to check if conn_type is connected, conn_type is defind in srv_bt_cm_connection_type 
 *  dev_addr		[IN]		the profile related dev_addr
 * RETURNS
 *  MMI_BOOL            TRUE : the profile is connected
 *                      FALSE : the profile is not connected
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_profile_connected_ex(srv_bt_cm_connection_type conn_type, const srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

    MMI_BOOL result = MMI_FALSE;
    U32 i;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    S32 dev_index = srv_bt_cm_get_dev_index(dev_addr, SRV_BT_CM_ALL_DEV); 
    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_PROFILE_CONNECTED_EX_1,dev_index);
    if(dev_index == -1)
        return result;
	    	
    for (i = 0; i < SRV_BT_CM_MAX_CONNECTION; ++i)
    {
    	srv_bt_cm_connect_struct* existed_conn = &g_srv_bt_cm_cntx.existed_conn[i];

		/* check if the device existed*/
		if (dev_index != existed_conn->index_of_dev_list)
			continue;
		/* check if some profile is connecting*/
        if (existed_conn->conn_id == 0 || existed_conn->conn_id>SRV_BT_CM_MAX_CONNECTION)
			continue;
		/* check if the profile is connected*/
		if((existed_conn->active) && (srv_bt_cm_get_conn_type(existed_conn->profile_id) == conn_type))
        {
            result = MMI_TRUE;
            break;
        }
    }

    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_PROFILE_CONNECTED_EX,
                ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
	        (dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
	        ((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
	        conn_type, result);

    return result;
}

/**********************************************************************
* FUNCTION: 
* 	srv_bt_cm_get_linked_dev_num
* DESCRIPTION:
*    Get the number of linked device.
* PARAMETERS:
* void
* RETURNS:
* U32 		the number of the linked device
***********************************************************************/
U32 srv_bt_cm_get_linked_dev_list_idx(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 linked_num = 0;
	U32 i = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	
	while(i<MMI_BT_LINK_MAX_NUM)
	{
		if(g_linked_dev_tbl[i].linked == MMI_TRUE)
		{
			++linked_num;
		}
    	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_LINKED_DEV_NUM, i, 
			g_linked_dev_tbl[i].dev_info, (S32)g_linked_dev_tbl[i].linked, linked_num);

		++i;
	}
	
	return linked_num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_linked_dev_info
 * DESCRIPTION
 *  This function is to check if a dev has been connected
 * PARAMETERS
 *  index_order     [IN]        the linked order. 
 * RETURNS
 *  srv_bt_cm_dev_struct*    the linked device info. 
 *****************************************************************************/
const srv_bt_cm_dev_struct* srv_bt_cm_get_linked_dev_info(U32 index_order)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	srv_bt_cm_dev_struct* linked_dev = NULL;
	U32 i = 0;
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	for(; i<MMI_BT_LINK_MAX_NUM; ++i)
	{
		if(g_linked_dev_tbl[i].stamp == index_order)
		{
			linked_dev = g_linked_dev_tbl[i].dev_info;
			break;
		}
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_LINKED_DEV_INFO, index_order, linked_dev);	

	return linked_dev;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_dev_busy
 * DESCRIPTION
 *  This function is to check if a dev is connecting
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL            TRUE : there is some profile connecting
 *                      FALSE : the device is not connected or connected already.
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_dev_busy(const srv_bt_cm_bt_addr* dev_addr)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	S32 index = srv_bt_cm_get_mapped_index(dev_addr);
	MMI_BOOL result = MMI_FALSE;

	if (index != -1)
	{
		result = (g_linked_dev_tbl[index].busy_conn > 1? MMI_TRUE: MMI_FALSE);
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_DEV_BUSY, index, 
		(index == -1? 0 : g_linked_dev_tbl[index].busy_conn), result);	

	return result;
}

/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_busy_dev
 * DESCRIPTION
 *  This function is to get device which is busy.
 * PARAMETERS
 *  void
 * RETURNS
 *  srv_bt_cm_bt_addr*   the device which is busy
 *****************************************************************************/
const srv_bt_cm_bt_addr* srv_bt_cm_get_busy_dev(void)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	S32 index = 0;
	srv_bt_cm_bt_addr* busy_dev = NULL;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

	for(; index<MMI_BT_LINK_MAX_NUM; ++index)
	{
		srv_bt_cm_dev_struct* cur_dev_info = g_linked_dev_tbl[index].dev_info;
		if(cur_dev_info && srv_bt_cm_is_dev_busy(&cur_dev_info->bd_addr) == MMI_TRUE)
		{
			busy_dev = &cur_dev_info->bd_addr;
			break;
		}
	}

	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_BUSY_DEV, index, busy_dev);
	return busy_dev;
}


static void srv_bt_cm_update_linked_order(U32 dev_index, MMI_BOOL link)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	const S32 dev_order_index = g_linked_dev_tbl[dev_index].stamp;
	U32 id = 0;

	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_UPDATE_LINKED_ORDER, dev_index, dev_order_index, link);
	if (dev_order_index == -1 && link == MMI_TRUE)
	{
		S32 max_order = g_linked_dev_tbl[0].stamp;
		for (id=1; id<MMI_BT_LINK_MAX_NUM; ++id)
		{
			if (max_order < g_linked_dev_tbl[id].stamp)
			{
				max_order = g_linked_dev_tbl[id].stamp;
			}
		}
		g_linked_dev_tbl[dev_index].stamp = max_order + 1;
		/*g_linked_dev_tbl[dev_index].auto_reconn = MMI_FALSE;*/
		MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_UPDATE_LINKED_ORDER_2, dev_index, g_linked_dev_tbl[dev_index].stamp, max_order);
	}
	else if (dev_order_index != -1 && link == MMI_FALSE)
	{
		for (id = 0; id<MMI_BT_LINK_MAX_NUM; ++id)
		{
			if (g_linked_dev_tbl[id].stamp > dev_order_index)
			{
				g_linked_dev_tbl[id].stamp--;
			}
			else if(g_linked_dev_tbl[id].stamp == dev_order_index)
			{
				/*memset(&g_linked_dev_tbl[id], 0, sizeof(srv_bt_cm_dialer_linked_struct));*/
				g_linked_dev_tbl[id].linked = link;
				g_linked_dev_tbl[id].stamp = -1;
			}
			MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_UPDATE_LINKED_ORDER_3, id, g_linked_dev_tbl[id].stamp, link);
		}
	}
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_dev_busy_state
 * DESCRIPTION
 *  This function is provided for CONN app only, to set the connecting profile status.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 *  conn_type       [IN]		the type of profile
 *  state			[IN]		indicate that it is connecting/disconnecting or done.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_dev_busy_state(srv_bt_cm_bt_addr* dev_addr, srv_bt_cm_connection_type conn_type, MMI_BOOL state)
{
	/*----------------------------------------------------------------*/
	/* Local Variables												  */
	/*----------------------------------------------------------------*/
	U32 conn_bit;
	S32 index = srv_bt_cm_get_mapped_index(dev_addr);
	/*----------------------------------------------------------------*/
	/* Code Body													  */
	/*----------------------------------------------------------------*/

    /* the node will be added if it was not in the linked table*/
	if(index == -1)
	{
		index = srv_bt_cm_get_empty_linked_index();
		//MMI_BT_ASSERT(index != -1);
		if(index == -1)
		{
		  	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_DEV_BUSY_STATE_2, index); 
            return;
		}
		g_linked_dev_tbl[index].dev_info = (srv_bt_cm_dev_struct* )srv_bt_cm_get_dev_info_by_addr(dev_addr, SRV_BT_CM_ALL_DEV);
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_DEV_BUSY_STATE, 
                ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
                (dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
	        ((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
	        index, conn_type, state);
		
    /* update the busy status */
	conn_bit = g_linked_dev_tbl[index].busy_conn;
	if(state == MMI_TRUE)
	{
		conn_bit |= (1 << conn_type);
	}
	else
	{
		conn_bit &= ~(1 << conn_type);
	}

	g_linked_dev_tbl[index].busy_conn = conn_bit;

	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_DEV_BUSY_STATE_END, g_linked_dev_tbl[index].stamp, g_linked_dev_tbl[index].busy_conn, g_linked_dev_tbl[index].linked);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_dev_link_state
 * DESCRIPTION
 *  This function is provided for CONN app only, to set the connecting profile status.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 *  conn_type       [IN]		the type of profile
 *  state			[IN]		indicate that it is connecting/disconnecting or done.
 * RETURNS
 *  void
 *****************************************************************************/
void srv_bt_cm_set_dev_link_state(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL link_state)
{
	U32 conn_bit;
	S32 index = srv_bt_cm_get_mapped_index(dev_addr);
	MMI_BOOL remote_dev_linked_before;

    /* the node node must be in the mapping table*/
	if (index == -1)
    {
        srv_bt_cm_set_dev_busy_state(dev_addr,SRV_BT_CM_NO_CONNECTION, MMI_FALSE);
        index = srv_bt_cm_get_mapped_index(dev_addr);
    }   
	MMI_BT_ASSERT(index != -1);
    remote_dev_linked_before = g_linked_dev_tbl[index].linked;

	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_DEV_LINK_STATE,		
			((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
			(dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
			((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
			index, 	g_linked_dev_tbl[index].linked, link_state, 
			g_linked_dev_tbl[index].stamp);
    /*update the linked order*/
	g_linked_dev_tbl[index].linked = link_state;
	if (g_linked_dev_tbl[index].linked != remote_dev_linked_before)
    {
		srv_bt_cm_update_linked_order(index, g_linked_dev_tbl[index].linked);
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_DEV_LINK_STATE_END, index, g_linked_dev_tbl[index].stamp);
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_get_auto_reconn_flag
 * DESCRIPTION
 *  This function is to check if currently BT is auto-connecting.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_cm_get_auto_reconn_flag(srv_bt_cm_bt_addr* dev_addr)
{
	MMI_BOOL reconn_flag = MMI_FALSE;
	S32 index  = srv_bt_cm_get_mapped_index(dev_addr);
	
	if (index == -1 && dev_addr != NULL)
	{
		return reconn_flag;
	}

	/* check all device, if anyone is under reconnection */
	if (dev_addr == NULL)
	{
		S32 id = 0;
		for(; id < MMI_BT_LINK_MAX_NUM; ++id)
		{
			if (g_linked_dev_tbl[id].auto_reconn == MMI_TRUE)
			{
				reconn_flag = MMI_TRUE;
				break;
			}
	}

            MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_AUTO_RECONN_FLAG,
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, index, reconn_flag);
	}
	else
	{
		MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_GET_AUTO_RECONN_FLAG,
					((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
			        (dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
			        ((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
	        		index, g_linked_dev_tbl[index].auto_reconn);
		reconn_flag = g_linked_dev_tbl[index].auto_reconn;
	}
	return reconn_flag;
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_set_auto_reconn_flag
 * DESCRIPTION
 *  This function is to set auto-connecting flag.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
void srv_bt_cm_set_auto_reconn_flag(srv_bt_cm_bt_addr* dev_addr, MMI_BOOL auto_reconn)
{
    S32 index = -1;
    MMI_BT_ASSERT(dev_addr != NULL);
    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_AUTO_RECONN_FLAG,
            ((dev_addr->nap & 0xff00) >> 8), (dev_addr->nap & 0x00ff),
            (dev_addr->uap), ((dev_addr->lap & 0xff0000) >> 16),
            ((dev_addr->lap & 0x00ff00) >> 8), (dev_addr->lap & 0x0000ff),
            auto_reconn);

    index = srv_bt_cm_get_mapped_index(dev_addr);
    if (index == -1)
        return;
	
    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_AUTO_RECONN_FLAG_END, index, auto_reconn);
	g_linked_dev_tbl[index].auto_reconn = auto_reconn;
}

MMI_BOOL srv_bt_cm_is_headset(U32 cod)
{
	MMI_BOOL ret = MMI_FALSE;
	
    if (cod & SRV_BT_PHONE_MAJOR_DEVICE_MASK 		/* phone */
		|| cod & SRV_BT_COMPUTER_MAJOR_DEVICE_MASK  /* lap */
		|| cod & SRV_BT_PRINTER_IMAGING_MINOR_DEVICE_CLASS)/* printer */
    {
        ret = MMI_FALSE;
    }
    else if (cod & SRV_BT_AUDIO_MAJOR_SERVICE_MASK) //MMI_BT_AV_MAJOR_DEVICE_MASK
    {
        ret = MMI_TRUE;
    }
	return ret;
}
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_headset_connected_ex
 * DESCRIPTION
 *  This function is to check if there is headset connected.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_headset_connected_ex(void)
{
	MMI_BOOL headset_conn = MMI_FALSE;
	S32 i = 0;
	while(i<MMI_BT_LINK_MAX_NUM)
	{
		const srv_bt_cm_dev_struct* dev = srv_bt_cm_get_linked_dev_info(i++);
		if(dev != NULL && srv_bt_cm_is_headset(dev->cod))
		{
			headset_conn = srv_bt_cm_is_headset_connected(&dev->bd_addr);
			if (headset_conn == MMI_TRUE)
			{
				break;
			}
		}
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_HEADSET_CONNECTED_EX, headset_conn);

	return headset_conn;
}

// TODO:
/*Will be dependent on SH*/
/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_is_bt_dialer
 * DESCRIPTION
 *  This function is to check if remote dev is MTK bt dialer.
 * PARAMETERS
 *  dev_addr		[IN]		remote device
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_cm_is_bt_dialer(const srv_bt_cm_bt_addr* dev_addr)
{
    MMI_BOOL ret = MMI_FALSE;
    U32 cod = (SRV_BT_NETWORKING_MAJOR_SERVICE_MASK | SRV_BT_CAPTURING_MAJOR_SERVICE_MASK | SRV_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK | \
            SRV_BT_AUDIO_MAJOR_SERVICE_MASK| SRV_BT_TELEPHONY_MAJOR_SERVICE_MASK | SRV_BT_PHONE_MAJOR_DEVICE_MASK | SRV_BT_CELLULAR_MINOR_DEVICE_MASK);

    const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info((srv_bt_cm_bt_addr* )dev_addr);

    if(dev_info != NULL )
    {
        if ((dev_info->cod | SRV_BT_OBJECT_TRANSFER_MAJOR_SERVICE_MASK) == cod)
        {
            ret = MMI_TRUE;
        }
		MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_BTDIALER, dev_info->cod, ret);
    }

    return ret;
}

void srv_bt_cm_dialer_init()
{
    S32 i = 0;
    memset(&g_linked_dev_tbl, 0, (sizeof(srv_bt_cm_dialer_linked_struct)*MMI_BT_LINK_MAX_NUM));
	while(i<MMI_BT_LINK_MAX_NUM)
	{
        g_linked_dev_tbl[i++].stamp = -1;
	}
}

S32 srv_bt_cm_set_prevent_connect_flag(MMI_BOOL flag)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 page_inquiry_mode = 0;
    static S32 visibility_before_prevent = SRV_BT_CM_VISIBILITY_ON;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BT_CM_SET_PREVENT_PASSIVE_CONN_FLAG,
        flag,
        g_srv_bt_cm_cntx.state);

    if (g_srv_bt_cm_cntx.state >= SRV_BT_CM_STATE_IDLE)
    {
        if (flag == MMI_TRUE)
        {	
            visibility_before_prevent = srv_bt_cm_get_visibility();
            page_inquiry_mode = BTBM_ADP_P_OFF_I_OFF;
            g_srv_bt_cm_cntx.tmp_visibility_type = SRV_BT_CM_VISIBILITY_OFF;
        }
        else
        {
            page_inquiry_mode = BTBM_ADP_P_ON_I_ON;
            g_srv_bt_cm_cntx.tmp_visibility_type = SRV_BT_CM_VISIBILITY_ON;
            if (visibility_before_prevent == SRV_BT_CM_VISIBILITY_OFF)
            {
                #ifdef __BT_LE_ONLY__
				page_inquiry_mode = BTBM_ADP_P_OFF_I_OFF;
				#else
                page_inquiry_mode = BTBM_ADP_P_ON_I_OFF;
				#endif
            	g_srv_bt_cm_cntx.tmp_visibility_type = SRV_BT_CM_VISIBILITY_OFF;
            }

        }
        g_srv_bt_cm_prevent_conn_flag = flag;
        StopTimer(BT_TEMP_VISIBLE_TIMER);
        SRV_BT_CM_STATE_TRANS(SRV_BT_CM_STATE_VISIBILITY_SETTING);
        srv_bt_cm_write_scanenable_mode_req_hdler(page_inquiry_mode);
        /* will deal with the result in API:
         * srv_bt_cm_write_scanenable_mode_cnf_hdler()
         * 
         * remember the value, if success, then modify the flag,
         * else do not set the flag */

		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
        return SRV_BT_CM_RESULT_SUCCESS;
    }

    return SRV_BT_CM_RESULT_FAILED;
}

MMI_BOOL srv_bt_cm_get_prevent_connect_flag(void)
{
     MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BT_CM_GET_PREVENT_CONN_FLAG,g_srv_bt_cm_prevent_conn_flag);
	 return  g_srv_bt_cm_prevent_conn_flag;
}
void srv_bt_cm_reset_prevent_connect_flag()
{
	 g_srv_bt_cm_prevent_conn_flag = MMI_FALSE; 
	 MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BT_CM_RESET_PREVENT_CONN_FLAG,g_srv_bt_cm_prevent_conn_flag);
}

#ifdef __MMI_BTBOX_NOLCD__

/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_set_as_master
 * DESCRIPTION
 *  this function is used to set itself as master.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  void
 ******************************************************************************/
void srv_bt_cm_set_as_master(MMI_BOOL master)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_SET_AS_MASTER, master);
    g_srv_bt_cm_cntx.is_master = master;
    if (master)
    {
        /*U8 master_name[SRV_BT_CM_BD_FNAME_LEN] = {0};
        U16 master_suffix_len = mmi_ucs2strlen(BOX_MASTER_NAME);
        mmi_ucs2ncpy((CHAR*)master_name, (CHAR*)g_srv_bt_cm_cntx.host_dev.name, SRV_BT_CM_BD_FNAME_LEN-master_suffix_len);
        mmi_ucs2ncat((CHAR*)master_name, (CHAR*)BOX_MASTER_NAME, master_suffix_len);
        srv_bt_cm_set_host_dev_name(master_name);*/
        srv_bt_cm_set_host_dev_name(BOX_MASTER_NAME);
        //master's visibility will be always on unless link is full
        srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_ON);
    }
    else
    {
        srv_bt_cm_set_host_dev_name(g_srv_bt_cm_cntx.host_dev.name);
        //master's visibility will be always on unless link is full
        srv_bt_cm_set_visibility(SRV_BT_CM_VISIBILITY_TEMPORARY_ON);
    }
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_is_master
 * DESCRIPTION
 *  this function is used to check whether box is master.
 * PARAMETERS
 *  void
 *  
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_bt_cm_is_master(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_MASTER, g_srv_bt_cm_cntx.is_master);
    return g_srv_bt_cm_cntx.is_master;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_is_box
 * DESCRIPTION
 *  this function is used to check whether the connected device is box.
 * PARAMETERS
 *  dev_addr
 *  
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_bt_cm_is_box(const srv_bt_cm_bt_addr* dev_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    MMI_BOOL ret = MMI_FALSE;
	const srv_bt_cm_dev_struct* dev_info = srv_bt_cm_get_dev_info((srv_bt_cm_bt_addr* )dev_addr);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(dev_info != NULL)
	{
	    ret = srv_bt_cm_is_box_ext(dev_info->cod, (U8*)dev_info->name);
	}
    
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_BOX, 
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff),
        ret);

    return ret;
}


/****************************************************************************** 
 * FUNCTION
 *  srv_bt_cm_is_box_ext
 * DESCRIPTION
 *  this function is used to check whether the connected device is box.
 * PARAMETERS
 *  cod
 *  device_name
 *
 * RETURNS
 *  MMI_BOOL
 ******************************************************************************/
MMI_BOOL srv_bt_cm_is_box_ext(U32 cod, U8 *device_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (cod == BOX_COD && strcmp(device_name, g_srv_bt_cm_cntx.host_dev.name) == 0)
	{
	    MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_BOX_EXT, cod, device_name, 1);
	    return MMI_TRUE;
	}
	MMI_TRACE(MMI_CONN_TRC_G7_BT, SRV_BT_CM_IS_BOX_EXT, cod, device_name, 0);
    return MMI_FALSE;
}

#endif  //__MMI_BTBOX_NOLCD__

#endif