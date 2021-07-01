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
#include "BtcmSrvGprot.h"
#ifdef __MMI_BT_MAP_CLIENT__
#include "MapcSrv.h"
#include "MapcSrvAdap.h"
#endif 
#include "bluetooth_map_struct.h"
#include "DebugInitDef_Int.h"
#include "BTMMIScrGprots.h"
#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
#include "BTNotiSrvGprot.h"
#include "Mmi_rp_srv_bt_noti_def.h"
#include "Unicodexdcl.h"
#include "FileMgrSrvGprot.h"
#endif /*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)*/

#ifdef __MMI_BT_MAP_CLIENT__
extern srv_map_client_cntx_struct g_gmap_client_cntx[MAX_MAPC_LINK_SUPPORT];
#endif
#ifdef __MMI_WEARABLE_DEVICE__
extern srv_bt_cm_bt_addr g_map_cur_noti_dev_addr;
#endif /*__MMI_WEARABLE_DEVICE__*/
srv_mapc_adp_cntx_struct g_mapc_adp_cntx[MAX_MAPC_LINK_SUPPORT];

MapcAdpCallback g_mapc_adp_cb[SRV_MAPC_ADP_CMD_END] = {0};
const char g_mapx_cmd_header[] = "MAPX";
const char g_mapd_cmd_header[] = "MAPD";

#define MMI_MAPC_ADP_STATE_TRANS(i, x)  \
{                                \
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ADP_STATE_CHANGE,g_mapc_adp_cntx[i].adp_state,x);\
    g_mapc_adp_cntx[i].adp_state = (x);  \
}

void MMI_MAPC_ADP_dump_dev_addr(srv_bt_cm_bt_addr *dev_addr)
{
#if 1
    MMI_TRACE(
        MMI_MAPC_TRC_CLASS,
        SRV_MAPC_ADP_DUMP_DEV_ADDR,
        ((dev_addr->nap & 0xff00) >> 8),
        (dev_addr->nap & 0x00ff),
        (dev_addr->uap),
        ((dev_addr->lap & 0xff0000) >> 16),
        ((dev_addr->lap & 0x00ff00) >> 8),
        (dev_addr->lap & 0x0000ff));
#endif
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_is_connected
 * DESCRIPTION
 * 
 * PARAMETERS
 * index_order
 * RETURNS
 *  MMI_BOOL
 *****************************************************************************/
MMI_BOOL srv_bt_mapc_adp_is_connected(U8 index_order)
{

	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL ret = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#if defined(__MTK_TARGET__)

	if(index_order >= MAX_MAPC_LINK_SUPPORT)
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_IS_NO_CONNECTED, ret);
		return ret;
	}
  #if (defined(__MMI_BT_MAPC_BY_MAP__) && (defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)))
    if (g_mapc_adp_cntx[index_order].is_map_by_spp_connected ||
        srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_MAPC_CONNECTION, &g_gmap_client_cntx[index_order].bd_addr))
    {
    	ret = MMI_TRUE;
    	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_IS_NO_CONNECTED, ret);
        return ret;
    }
  #elif defined(__MMI_BT_MAPC_BY_MAP__)
	{	
		ret = srv_bt_cm_is_profile_connected_ex(SRV_BT_CM_MAPC_CONNECTION, &g_gmap_client_cntx[index_order].bd_addr);
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_IS_NO_CONNECTED, ret);
		return ret;
  	}
  #elif defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
	{
		ret = g_mapc_adp_cntx[index_order].is_map_by_spp_connected;
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_IS_NO_CONNECTED, ret);
		return ret;
  	}
  #else
    {
    	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_IS_NO_CONNECTED, ret);
    	return ret;
  	}
  #endif

#else /* defined(__MTK_TARGET__)*/
	return MMI_TRUE;
#endif /* defined(__MTK_TARGET__)*/
}

#if defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BT_MAPC_BY_DOGP__)
/*****************************************************************************
 * FUNCTION
 * mapc_adp_itoa
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *  void
 *****************************************************************************/
static void mapc_adp_itoa(kal_char *buf, kal_int32 i, kal_int32 base)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    kal_char *s;
#define LEN   20
   kal_int32 rem;
   static kal_char rev[LEN+1];
   
   /*----------------------------------------------------------------*/
   /* Code Body 													 */
   /*----------------------------------------------------------------*/
   rev[LEN] = 0;
   if (i == 0)
   {
      buf[0] = '0';
      ++buf;
      return;
   }
   s = &rev[LEN];
   while (i)
   {
      rem = i % base;
      if (rem < 10)
         *--s = rem + '0';
      else if (base == 16)
         *--s = "abcdef"[rem - 10];
      i /= base;
   }
   while (*s)
   {
      buf[0] = *s++;
      ++buf;
   }
}


/*
cmd:  TYPE PARAM_NUM PARAM
*/
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_set_fldr
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_set_fldr(char *cmd, bt_mapc_set_folder_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    ///TODO: Sprintf
    srv_mapc_adp_set_folder_cmd folder_cmd = {0};
	
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GEN_CMD_SET_FOLDER);
    mapc_adp_itoa(folder_cmd.cmd_type ,SRV_MAPC_ADP_CMD_SET_FOLDER,10);
    mapc_adp_itoa(folder_cmd.para_num, 2, 10);
    mapc_adp_itoa(folder_cmd.flag, req_data->flag, 10);
    if (req_data->folder != NULL && req_data->folder[0] != 0)
    {
        mmi_ucs2_to_asc(folder_cmd.folder_name, (CHAR *)req_data->folder);
        
    }
    else
    {
        strcpy(folder_cmd.folder_name,"ROOT");
    }
    //folder_cmd.folder_name[0] = '0';
    sprintf(cmd,"%s %s %s %s",
        folder_cmd.cmd_type, 
        folder_cmd.para_num,
        folder_cmd.flag,
        folder_cmd.folder_name);
    return strlen(cmd);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_get_listing
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
 U16 srv_bt_mapc_adp_gen_cmd_get_listing(char *cmd, bt_mapc_get_message_listing_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mapc_adp_get_list_cmd get_list_cmd = {0};
    	
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ADP_GEN_CMD_GET_LISTING, 
        req_data->list_size,req_data->list_offset,req_data->max_subject_len,req_data->child_folder);

    mapc_adp_itoa(get_list_cmd.cmd_type,SRV_MAPC_ADP_CMD_GET_LISTING,10);
    mapc_adp_itoa(get_list_cmd.para_num,3,10);
    mapc_adp_itoa(get_list_cmd.list_size,req_data->list_size,10);
    mapc_adp_itoa(get_list_cmd.offset,req_data->list_offset,10);
    mapc_adp_itoa(get_list_cmd.max_sub_len,req_data->max_subject_len,10);

    sprintf(cmd,"%s %s %s %s %s",
        get_list_cmd.cmd_type, 
        get_list_cmd.para_num,
        get_list_cmd.list_size,
        get_list_cmd.offset,
        get_list_cmd.max_sub_len);

    return strlen(cmd);
    
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_get_msg
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_get_msg(char *cmd, bt_mapc_get_message_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mapc_adp_get_msg_cmd msg_cmd = {0};
		
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GEN_CMD_GET_MSG);

    mapc_adp_itoa(msg_cmd.cmd_type, SRV_MAPC_ADP_CMD_GET_MSG, 10);
    mapc_adp_itoa(msg_cmd.para_num, 1, 10);

    if (req_data->handle != NULL)
    {
        memcpy(msg_cmd.handle, req_data->handle, strlen(req_data->handle));
    }
    else
    {
        msg_cmd.handle[0] = '0';
    }

    sprintf(cmd,"%s %s %s",
        msg_cmd.cmd_type, 
        msg_cmd.para_num,
        msg_cmd.handle);
    return strlen(cmd);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_push_msg
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_push_msg(char *cmd, bt_mapc_push_message_req_struct *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mapc_adp_push_msg_cmd push_cmd = {0};
			
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GEN_CMD_PUSH_MSG);

    mapc_adp_itoa(push_cmd.cmd_type,SRV_MAPC_ADP_CMD_PUSH_MSG,10);

    sprintf(cmd,"%s",
        push_cmd.cmd_type);
    return strlen(cmd);
}
/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_set_status
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_set_status(char *cmd, bt_mapc_set_message_status_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mapc_adp_set_status_cmd status_cmd = {0}; 
			
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GEN_CMD_SET_STATUS);

    mapc_adp_itoa(status_cmd.cmd_type,SRV_MAPC_ADP_CMD_SET_STATUS,10);
    mapc_adp_itoa(status_cmd.para_num,2,10);
    mapc_adp_itoa(status_cmd.status,req_data->status,10);

    if (req_data->handle != NULL)
    {
        mmi_ucs2_to_asc(status_cmd.handle, req_data->handle);
    }
    else
    {
        status_cmd.handle[0] = '0';
    }

    sprintf(cmd,"%s %s %s",
        status_cmd.cmd_type, 
        status_cmd.para_num,
        status_cmd.handle);
    return strlen(cmd);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_conn_status
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_conn_status(char *cmd)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_mapc_adp_map_conn_cmd status_cmd = {0}; 
			
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GEN_CMD_CONN_STATUS);

    mapc_adp_itoa(status_cmd.cmd_type,SRV_MAPC_ADP_CMD_CONNECT,10);
    mapc_adp_itoa(status_cmd.para_num,0,10);

    sprintf(cmd,"%s %s",
        status_cmd.cmd_type, 
        status_cmd.para_num);
    return strlen(cmd);
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_gen_cmd_genaral
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	U16
 *****************************************************************************/
U16 srv_bt_mapc_adp_gen_cmd_genaral(char *cmd, srv_mapc_adp_cmd_type cmd_type, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 cmd_len = 0;
			
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
    memset(cmd, 0, SRV_MAPC_ADP_MAX_CMD_LENGTH);

    switch (cmd_type)
    {
        case SRV_MAPC_ADP_CMD_SET_FOLDER:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_set_fldr(cmd, (bt_mapc_set_folder_req_struct *)data);
            break;
        }
        case SRV_MAPC_ADP_CMD_GET_LISTING:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_get_listing(cmd, (bt_mapc_get_message_listing_req_struct *)data);
            break;
        }
        case SRV_MAPC_ADP_CMD_GET_MSG:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_get_msg(cmd, (bt_mapc_get_message_req_struct *)data);
            break;
        }
        case SRV_MAPC_ADP_CMD_PUSH_MSG:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_push_msg(cmd, (bt_mapc_push_message_req_struct *)data);
            break;
        }
        case SRV_MAPC_ADP_CMD_SET_STATUS:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_set_status(cmd, (bt_mapc_set_message_status_req_struct *)data);
            break;
        }
        case SRV_MAPC_ADP_CMD_CONNECT:
        {
            cmd_len = srv_bt_mapc_adp_gen_cmd_conn_status(cmd);
            break;
        }
    }
    return cmd_len;
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_set_folder_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_bt_mapc_adp_set_folder_req(U8 cntx_index, bt_mapc_set_folder_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{
		bt_mapc_set_folder_cnf_struct msg_p = {0};
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SET_FOLDER_REQ_BAD_STATE, cntx_index, g_mapc_adp_cntx[cntx_index].adp_state);
		free_local_para((local_para_struct *)req_data);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_FOLDER](&msg_p);
		return;
	}
	
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_FOLDER_SETTING);
	
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_SET_FOLDER, req_data);
    free_local_para((local_para_struct *)req_data);
    result = srv_bt_noti_send_cmd_ext((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr), 
									g_mapx_cmd_header, 
									g_mapc_adp_cntx[cntx_index].cmd, 
									cmd_len);
    if (!result)
    {       
        bt_mapc_set_folder_cnf_struct msg_p = {0};
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SET_FOLDER_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_FOLDER](&msg_p);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_get_listing_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void
 *****************************************************************************/
void srv_bt_mapc_adp_get_listing_req(U8 cntx_index, bt_mapc_get_message_listing_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
   		
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/	
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{

		bt_mapc_get_message_listing_cnf_struct msg_p = {0};
		
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_LIST_REQ_BAD_STATE, cntx_index,g_mapc_adp_cntx[cntx_index].adp_state);
		free_local_para((local_para_struct *)req_data);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
		msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
		g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_LISTING](&msg_p);
		return;

	}
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_LIST_GETTING);

    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_GET_LISTING, req_data);
    free_local_para((local_para_struct *)req_data);
	
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

    result = srv_bt_noti_send_cmd_ext((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr),
									g_mapx_cmd_header, 
									g_mapc_adp_cntx[cntx_index].cmd, 
									cmd_len);

    if (!result)
    {
        bt_mapc_get_message_listing_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_LIST_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_LISTING](&msg_p);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_get_list_size_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_get_list_size_req(U8 cntx_index, bt_mapc_get_message_listing_size_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	bt_mapc_get_message_listing_size_cnf_struct msg_rsp = {0};
		
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
	memcpy(&msg_rsp.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_rsp.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    msg_rsp.result = SRV_BT_MAPC_SUCCESS;
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_LIST_SIZE_REQ);
    free_local_para((local_para_struct *)req_data);
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_LIST_SIZE]((void *)&msg_rsp);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_get_msg_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_get_msg_req(U8 cntx_index, bt_mapc_get_message_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	U16 cmd_len = 0;
    U8 spp_handle[MAP_MAX_HANDLE_STR_UCS2_LEN + 2];
    MMI_BOOL result = MMI_FALSE;
    		
	/*----------------------------------------------------------------*/
    /* Code Body 													 */
    /*----------------------------------------------------------------*/
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{
	    bt_mapc_get_message_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_MSG_REQ_BAD_STATE, cntx_index,g_mapc_adp_cntx[cntx_index].adp_state);		
		free_local_para((local_para_struct *)req_data);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_MSG](&msg_p);
		return;

	}
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_MSG_GETTING);
    memset(spp_handle, 0, MAP_MAX_HANDLE_STR_UCS2_LEN + 2);
    app_ucs2_strncpy(spp_handle, req_data->handle, BT_MAP_MAX_HANDLE_STR_LEN);
    memset(req_data->handle, 0, BT_MAP_MAX_HANDLE_STR_LEN + 1);
    mmi_ucs2_to_asc(req_data->handle, spp_handle);
    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_GET_MSG, req_data);
    free_local_para((local_para_struct *)req_data);
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

	result = srv_bt_noti_send_cmd_ext((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr),
									g_mapx_cmd_header, 
									g_mapc_adp_cntx[cntx_index].cmd, 
									cmd_len);

    if (!result)
    {
        bt_mapc_get_message_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_MSG_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_MSG](&msg_p);
    }

}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_push_msg_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_push_msg_req(U8 cntx_index, bt_mapc_push_message_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{
        bt_mapc_push_message_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_PUSH_MSG_REQ_BAD_STATE,cntx_index, g_mapc_adp_cntx[cntx_index].adp_state);
		free_local_para((local_para_struct *)req_data);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_PUSH_MSG](&msg_p);
		return;
	}
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;
	MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_MSG_PUSHING);
    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_PUSH_MSG, req_data);
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

    result = srv_bt_noti_send_file_with_prefix_command((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr),
												(WCHAR *)req_data->file, 
                                                g_mapd_cmd_header,
                                                g_mapc_adp_cntx[cntx_index].cmd,
                                                cmd_len);
    
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_PUSH_MSG_REQ);
    
    free_local_para((local_para_struct *)req_data);

    if (!result)
    {
        bt_mapc_push_message_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_PUSH_MSG_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_PUSH_MSG](&msg_p);
    }
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_map_conn_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_map_conn_req(U8 cntx_index)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
		return;
	}
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;

    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_CONNECTING);
    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_CONNECT, NULL);
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

    result = srv_bt_noti_send_cmd_ext((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr), 
							g_mapx_cmd_header,
							g_mapc_adp_cntx[cntx_index].cmd,
							cmd_len);

    if (!result)
    {      
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_CONN_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_set_status_req
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_set_status_req(U8 cntx_index, bt_mapc_set_message_status_req_struct *req_data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U16 cmd_len = 0;
    MMI_BOOL result = MMI_FALSE;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(g_mapc_adp_cntx[cntx_index].adp_state != SRV_MAPC_ADP_IDLE)
	{
        bt_mapc_set_message_status_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SET_STATUS_REQ_BAD_STATE, cntx_index, g_mapc_adp_cntx[cntx_index].adp_state);
		free_local_para((local_para_struct *)req_data);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
		g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_TRUE;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_STATUS](&msg_p);
		return;
	}
	g_mapc_adp_cntx[cntx_index].is_bad_state = MMI_FALSE;
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_MSG_STATUS_SETTING);
    cmd_len = srv_bt_mapc_adp_gen_cmd_genaral(g_mapc_adp_cntx[cntx_index].cmd, SRV_MAPC_ADP_CMD_SET_STATUS, req_data);
    free_local_para((local_para_struct *)req_data);
	MMI_MAPC_ADP_dump_dev_addr((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr));

    result = srv_bt_noti_send_cmd_ext((srv_bt_cm_bt_addr*)&(g_gmap_client_cntx[cntx_index].bd_addr),
								g_mapx_cmd_header, 
								g_mapc_adp_cntx[cntx_index].cmd, 
								cmd_len);

    if (!result)
    {
        bt_mapc_set_message_status_cnf_struct msg_p = {0};
        
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SET_STATUS_REQ_FAIL);
		MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_STATUS](&msg_p);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adap_connect_by_app
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
MMI_BOOL srv_bt_mapc_adap_connect_by_app(U8 index_order, MapcAdpConnCallback connCallback)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/	
	if(index_order >= MAX_MAPC_LINK_SUPPORT)
		return MMI_FALSE;

	if (!g_mapc_adp_cntx[index_order].is_spp_connected)
    {
        return MMI_FALSE;
    }

    g_mapc_adp_cntx[index_order].conn_callback = connCallback;
    srv_bt_mapc_adp_map_conn_req(index_order);
    return MMI_TRUE;
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_set_folder_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_set_folder_rsp(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_set_folder_cnf_struct msg_p = {0};
    S32 error_code = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, 
		SRV_MAPC_ADP_SET_FOLDER_RSP, 
		cntx_index,
		noti_evt->ret_is_num, 
		noti_evt->ret_code,
		g_mapc_adp_cntx[cntx_index].is_bad_state);
	if(g_mapc_adp_cntx[cntx_index].is_bad_state == MMI_TRUE)
	{
		return;
	}
    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == SRV_MAPC_ADP_CMD_SET_FOLDER)
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
        }
        else
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
    }
	else
	{
		msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
	}
	
	memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_FOLDER](&msg_p);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_get_listing_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_get_listing_rsp(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_get_message_listing_cnf_struct msg_p = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_LISTING_RSP,cntx_index, noti_evt->ret_code,g_mapc_adp_cntx[cntx_index].is_bad_state);
	if(g_mapc_adp_cntx[cntx_index].is_bad_state == MMI_TRUE)
	{
		return;
	}
    if (!noti_evt->ret_is_num)
    {
        if (noti_evt->ret_code == SRV_MAPC_ADP_CMD_GET_LISTING)
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
            app_ucs2_strncpy(msg_p.file, noti_evt->user_data, BT_MAP_MAX_TEMP_FILE_NAME_LEN);
        }
        else
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
    }
    else
    {
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
    }
	memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_LISTING]((void *)&msg_p);
}


/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_get_msg_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_get_msg_rsp(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_get_message_cnf_struct msg_p = {0};

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_MSG_RSP,cntx_index, noti_evt->ret_code,g_mapc_adp_cntx[cntx_index].is_bad_state);
	if(g_mapc_adp_cntx[cntx_index].is_bad_state == MMI_TRUE)
	{
		return;
	}
    if (!noti_evt->ret_is_num)
    {
        MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_GET_MSG_RSP, noti_evt->ret_code);
        if (noti_evt->ret_code == SRV_MAPC_ADP_CMD_GET_MSG)
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
            msg_p.fraction_rsp = BT_MAP_FRACTION_RSP_NO;
            app_ucs2_strncpy(msg_p.file, noti_evt->user_data, BT_MAP_MAX_TEMP_FILE_NAME_LEN);
        }
        else
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
    }
    else
    {
        msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
    }
	memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_GET_MSG]((void *)&msg_p);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_set_status_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_set_status_rsp(U8 cntx_index,void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_set_message_status_cnf_struct msg_p = {0};
    S32 error_code = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SET_STATUS_RSP, cntx_index,noti_evt->ret_is_num,noti_evt->ret_code,g_mapc_adp_cntx[cntx_index].is_bad_state);
	if(g_mapc_adp_cntx[cntx_index].is_bad_state == MMI_TRUE)
	{
		return;
	}
    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == SRV_MAPC_ADP_CMD_SET_STATUS)
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
        }
        else
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
    }
	else
	{
		msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
	}
	memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_SET_STATUS](&msg_p);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_push_msg_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_push_msg_rsp(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_push_message_cnf_struct msg_p = {0};
    S32 error_code = 0;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_PUSH_MSG_RSP,cntx_index, noti_evt->ret_is_num,noti_evt->ret_code,g_mapc_adp_cntx[cntx_index].is_bad_state);
	if(g_mapc_adp_cntx[cntx_index].is_bad_state == MMI_TRUE)
	{
		return;
	}
    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == SRV_MAPC_ADP_CMD_PUSH_MSG)
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
        }
        else
        {
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
    }
	else
	{
		msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL;
	}
	memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
	msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_PUSH_MSG](&msg_p);
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_map_conn_rsp
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_map_conn_rsp(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;    
    S32 error_code = 0;
    bt_mapc_connect_cnf_struct msg_p;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_CONN_RSP, noti_evt->ret_is_num,noti_evt->ret_code);

    if (noti_evt->ret_is_num)
    {
        error_code = noti_evt->ret_code;

        if (error_code == SRV_MAPC_ADP_CMD_CONNECT)
        {
            g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
        }
        else
        {
            g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
            msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_FAIL_BAD_STATE;
        }
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_CONNECT](&msg_p);
		
        if (g_mapc_adp_cntx[cntx_index].conn_callback)
        {
            g_mapc_adp_cntx[cntx_index].conn_callback(g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected);
            g_mapc_adp_cntx[cntx_index].conn_callback = NULL;
        }
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_handle_evt_report
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_handle_evt_report(U8 cntx_index, void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)data;
    bt_mapc_mns_send_event_ind_struct msg_p = {0};
    U32 size = 0;
    S32 fileHandle;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_HANDLE_EVT_RPT, noti_evt->ret_is_num,noti_evt->ret_code);
	if (!noti_evt->ret_is_num && g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_SPP)
    {        
        app_ucs2_strncpy(msg_p.file, noti_evt->user_data, SRV_BT_MAP_MAX_TEMP_FILE_NAME_LEN);
        if ((fileHandle = FS_Open((WCHAR *)msg_p.file, FS_READ_ONLY)) < 0)
        {
            msg_p.data_size = 0;
        }
        else
        {
            FS_GetFileSize(fileHandle, &size);
            msg_p.data_size = (U16)size;
            FS_Close(fileHandle);
        }
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
        g_mapc_adp_cb[SRV_MAPC_ADP_CMD_EVENT_REPORT](&msg_p);
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_set_callback
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_set_callback(MapcAdpCallback callback, srv_mapc_adp_cmd_type cmdType)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (callback != NULL)
    {
        g_mapc_adp_cb[cmdType] = callback;
    }
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_conn_cnf
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_conn_cnf(void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_connectivity_notify_struct *noti_evt = (srv_bt_noti_map_connectivity_notify_struct *)data;
    bt_mapc_connect_cnf_struct msg_p = {0};
	U8 cntx_index;
	srv_bt_cm_bt_addr *btd = NULL;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF, noti_evt->is_connected);
#ifdef __MMI_WEARABLE_DEVICE__
	{
		g_map_cur_noti_dev_addr.lap = noti_evt->bt_addr.lap;
		g_map_cur_noti_dev_addr.uap = noti_evt->bt_addr.uap; 
		g_map_cur_noti_dev_addr.nap = noti_evt->bt_addr.nap; 
		MMI_MAPC_ADP_dump_dev_addr(&g_map_cur_noti_dev_addr);
	}
#endif /*__MMI_WEARABLE_DEVICE__*/
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(noti_evt->bt_addr), -1);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
	{
		for(cntx_index = 0; cntx_index < MAX_MAPC_LINK_SUPPORT; cntx_index++)
		{
			btd = (srv_bt_cm_bt_addr *)&g_gmap_client_cntx[cntx_index].bd_addr;
			if(g_gmap_client_cntx[cntx_index].mas_id < 0
		#if !defined(__MMI_BT_MAPC_BY_DOGP__)
				 && !srv_bt_cm_get_existed_conn_num_by_addr(btd)
		#endif /*!defined(__MMI_BT_MAPC_BY_DOGP__)*/
				 )
			{			
				MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF0, cntx_index);
				g_gmap_client_cntx[cntx_index].conn_type = SRV_BT_MAPC_CONN_SPP;
				break;
			}
		}
	}
	else if(g_gmap_client_cntx[cntx_index].mas_id > 0 
		&& g_gmap_client_cntx[cntx_index].state >= SRV_MAPC_STATE_CONNECTING)
	{
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF1, cntx_index, g_gmap_client_cntx[cntx_index].state,g_gmap_client_cntx[cntx_index].mas_id);
		return;
	}
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
	{		
	
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF2);
		return;
	}
    if (noti_evt->is_connected)
    {
    
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF3, cntx_index , noti_evt->is_connected);
		g_gmap_client_cntx[cntx_index].conn_type = SRV_BT_MAPC_CONN_SPP;

		g_mapc_adp_cntx[cntx_index].is_spp_connected = MMI_TRUE;
		
    	msg_p.result = BT_MAP_SUCCESS;
    	g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_TRUE;
		memcpy(&g_gmap_client_cntx[cntx_index].bd_addr, &(noti_evt->bt_addr), sizeof(srv_bt_cm_bt_addr));
		memcpy(&msg_p.addr, &(noti_evt->bt_addr), sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = 255;
		
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF4);
		g_mapc_adp_cb[SRV_MAPC_ADP_CMD_CONNECT]((void *)&msg_p);
       
    }
    else
    {
    
		MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_CONN_CNF6,  noti_evt->is_connected);
    	g_mapc_adp_cntx[cntx_index].is_spp_connected = MMI_FALSE;       
        g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
		//msg_p.result = BT_MAP_FAIL;
    }   
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_disconn_cnf
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
void srv_bt_mapc_adp_disconn_cnf(void *data)
{
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    srv_bt_noti_map_connectivity_notify_struct *noti_evt = (srv_bt_noti_map_connectivity_notify_struct *)data;
    bt_mapc_disconnect_cnf_struct msg_p = {0};
	U8 cntx_index;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_DISCONN_CNF, noti_evt->is_connected);
#ifdef __MMI_WEARABLE_DEVICE__

	{
		g_map_cur_noti_dev_addr.lap = 0;
		g_map_cur_noti_dev_addr.uap = 0; 
		g_map_cur_noti_dev_addr.nap = 0; 
		MMI_MAPC_ADP_dump_dev_addr(&g_map_cur_noti_dev_addr);
	}
#endif /*__MMI_WEARABLE_DEVICE__*/
	cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(noti_evt->bt_addr), -1);
	if(cntx_index == MAX_MAPC_LINK_SUPPORT)
		return;
    if (g_gmap_client_cntx[cntx_index].conn_type == SRV_BT_MAPC_CONN_SPP && g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected)
    {
	    msg_p.result = (bt_map_result_enum)SRV_BT_MAPC_SUCCESS;
	    MMI_TRACE(MMI_MAPC_TRC_CLASS, SRV_MAPC_ADP_SPP_DISCONN_CNF, noti_evt->is_connected);
	    MMI_MAPC_ADP_STATE_TRANS(cntx_index, SRV_MAPC_ADP_IDLE);

        g_mapc_adp_cntx[cntx_index].is_spp_connected = MMI_FALSE;
        g_mapc_adp_cntx[cntx_index].is_map_by_spp_connected = MMI_FALSE;
    
		memcpy(&msg_p.addr, &g_gmap_client_cntx[cntx_index].bd_addr, sizeof(srv_bt_cm_bt_addr));
		msg_p.mas_id = g_gmap_client_cntx[cntx_index].mas_id;
	    g_mapc_adp_cb[SRV_MAPC_ADP_CMD_DISCONNECT]((void *)&msg_p); 
	}
}

/*****************************************************************************
 * FUNCTION
 * srv_bt_mapc_adp_event_hdlr
 * DESCRIPTION
 * 
 * 
 * PARAMETERS
 * 
 * RETURNS
 *	void 
 *****************************************************************************/
mmi_ret srv_bt_mapc_adp_event_hdlr(mmi_event_struct *param)
{   
	/*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (param->evt_id)
    {
        case EVT_ID_SRV_BT_NOTI_MAP_DISCONNECT_CNF:
        {
            srv_bt_mapc_adp_disconn_cnf(param);
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MAP_CONNECT_CNF:
        {
            srv_bt_mapc_adp_conn_cnf(param);
            break;
        }
        case EVT_ID_SRV_BT_NOTI_MAP_CMD_NOTIFY:
        { 
            srv_bt_noti_map_event_notify_struct *noti_evt = (srv_bt_noti_map_event_notify_struct *)param;

			U8 cntx_index = srv_bt_mapc_get_dev_cntx_index((srv_bt_cm_bt_addr *)&(noti_evt->bt_addr), -1);
			if(cntx_index == MAX_MAPC_LINK_SUPPORT)
				return MMI_RET_OK;

            MMI_TRACE(MMI_MAPC_TRC_CLASS,SRV_MAPC_ADP_CMD_NOTIFY,cntx_index, g_mapc_adp_cntx[cntx_index].adp_state);

			if (noti_evt->ret_code == SRV_MAPC_ADP_CMD_EVENT_REPORT)
            {
                srv_bt_mapc_adp_handle_evt_report(cntx_index, param);
            }
            else if (g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_FOLDER_SETTING)
            {
                srv_bt_mapc_adp_set_folder_rsp(cntx_index, param);
            }
            else if (g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_LIST_GETTING)
            {
                srv_bt_mapc_adp_get_listing_rsp(cntx_index, param);
            }
            else if (g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_MSG_GETTING)
            {
                srv_bt_mapc_adp_get_msg_rsp(cntx_index, param);
            }
            else if (g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_MSG_STATUS_SETTING)
            {
                srv_bt_mapc_adp_set_status_rsp(cntx_index, param);
            }
            else if (g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_MSG_PUSHING)
            {
                srv_bt_mapc_adp_push_msg_rsp(cntx_index, param);
            }
            else if ((g_mapc_adp_cntx[cntx_index].adp_state == SRV_MAPC_ADP_CONNECTING))
            {
                srv_bt_mapc_adp_map_conn_rsp(cntx_index,param);
            }
            break;
        }
    }
    return MMI_RET_OK;
}
#endif/*defined( __MMI_BT_MAPC_BY_SPP__) || defined(__MMI_BLE_DOGP_SUPPORT__)*/
