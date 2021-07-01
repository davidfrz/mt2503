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
 * BLEcmSrvMain.c
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   This file is for BT CM main application flow and utilities.
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
 *.
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
#include "BLEcmSrvProt.h"
#include "BLESrvGprot.h"
#include "bluetooth_bm_struct.h"



#include "conversions.h"

#include "MMI_conn_app_trc.h"
#include "DebugInitDef_Int.h"
#include "kal_trace.h"
#include "MMIDataType.h"
#include "stack_msgs.h"
#include "mmi_frm_events_gprot.h"
#include "string.h"
#include "Unicodexdcl.h"
#include "stdlib.h"
#include "stdio.h"
#include "GlobalResDef.h"
#include "mmiapi_dm_struct.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_general_types.h"
#include "mmi_frm_timer_gprot.h"
#include "kal_public_api.h"
#include "mmi_frm_mem_gprot.h"

/***************************************************************************** 
 * External Variable
 *****************************************************************************/

srv_ble_cm_cntx_struct g_srv_ble_cm_cntx;


/*****************************************************************************
 * FUNCTION
 *  srv_ble_init_event_handler
 * DESCRIPTION
 *  This function is to init event handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ble_init_event_handler(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_BT_BM_DISCOVERY_RESULT_IND, srv_ble_discovery_result_ind_hdler);
	mmi_frm_set_multi_protocol_event_handler(MSG_ID_BT_BM_DISCOVERY_UPDATE_IND, srv_ble_discovery_update_ind_hdler);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_BT_BM_DISCOVERY_CNF, srv_ble_discovery_cnf_hdler);
    mmi_frm_set_multi_protocol_event_handler(MSG_ID_BT_BM_DISCOVERY_CANCEL_CNF, srv_ble_cancel_discovery_cnf_hdler);
	mmi_frm_set_multi_protocol_event_handler(MSG_ID_BT_BM_WRITE_SCANENABLE_MODE_CNF,srv_ble_cm_write_scanenable_mode_cnf);
}


/*****************************************************************************
 * FUNCTION
 *  srv_bt_cm_copy_n_utf8_chars
 * DESCRIPTION
 *  to copy n chars to dest string
 * PARAMETERS
 *  dest             [IN]        dest buffer 
 *  size_of_dest     [IN]        max size of dest buffer
 *  src              [IN]        src buffer 
 *  charNum          [IN]        number of char to be copied
 * RETURNS
 *  void
 *****************************************************************************/
void srv_ble_cm_copy_n_utf8_chars(U8* dest, U16 size_of_dest, U8* src, U8 char_num)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U8 char_count = 0;
    U8 char_byte_cnt = 0;
    U8 ucs_char[4];
    U16 byes_copied = 0;
    U16 max_size_of_dest = size_of_dest-2;
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //MMI_BT_ASSERT(dest);
    while (*src && char_count < char_num && byes_copied < max_size_of_dest)
    {
        char_byte_cnt = (U8)mmi_chset_utf8_to_ucs2(ucs_char, src);
        if ((byes_copied+char_byte_cnt) > max_size_of_dest)
        {
            //*dest = 0;
            //*(dest+1) = 0;
            break;
        }

        memcpy(dest, src, char_byte_cnt);
        dest += char_byte_cnt;
        src += char_byte_cnt;
        char_count++;
        byes_copied += char_byte_cnt;
    }

    *dest = 0;
    *(dest+1) = 0;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_addr_is_null
 * DESCRIPTION
 *  This function is to judge the address is null or not.
 * PARAMETERS
 *  bd_addr: [IN] address
 * RETURNS
 *  MMI_BOOL: the result
 *****************************************************************************/

MMI_BOOL srv_ble_cm_addr_is_null(srv_bt_cm_bt_addr* bd_addr)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
	MMI_BOOL addr_is_null = MMI_TRUE;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	if (bd_addr && (bd_addr->uap || bd_addr->nap || bd_addr->lap))
	{
		addr_is_null = MMI_FALSE;
	}

	return addr_is_null;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_get_dev_num
 * DESCRIPTION
 *  This function is get device number by device type.
 * PARAMETERS
 *  dev_type: [IN] device type
 * RETURNS
 *  U32: total number
 *****************************************************************************/

U32 srv_ble_cm_get_dev_num(srv_ble_cm_dev_type_enum dev_type)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 total_num = 0;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    switch (dev_type)
    {
        case SRV_BLE_CM_DISCOVERED_DEV:
            total_num = g_srv_ble_cm_cntx.discovered_dev_num;
            break;

        
        case SRV_BLE_CM_CONNECTED_DEV:
            total_num = (U32)g_srv_ble_cm_cntx.connected_dev_num;
            break;

       
    }

    MMI_TRACE(
        MMI_CONN_TRC_G7_BT,
        SRV_BLE_CM_GET_DEV_NUM,
        dev_type,
        total_num);
    return total_num;
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_add_connected_list
 * DESCRIPTION
 *  This function is add the device to le cm connected list.
 * PARAMETERS
 *  dev_info: [IN] device info
 * RETURNS
 *  void
 *****************************************************************************/

void srv_ble_cm_add_connected_list(srv_le_cm_gatt_dev_info_struct* dev_info)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

	U32 i;
	S32 j = -1;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_ADD_CONNECTED_LIST, 
		((dev_info->dev_addr->nap & 0xff00) >> 8),
        (dev_info->dev_addr->nap & 0x00ff),
        (dev_info->dev_addr->uap),
        ((dev_info->dev_addr->lap & 0xff0000) >> 16),
        ((dev_info->dev_addr->lap & 0x00ff00) >> 8),
        (dev_info->dev_addr->lap & 0x0000ff),
        dev_info->is_ind,
        g_srv_ble_cm_cntx.connected_dev_num);
    if(srv_ble_cm_get_connected_list_inx(dev_info->dev_addr) != -1)
    {
         return;
    }
	for (i = 0; i < BLE_LINK_NUM*2; i++)
    {
        if (srv_ble_cm_addr_is_null(&g_srv_ble_cm_cntx.connected_list[i].le_bd_addr))
        {
            memcpy(&g_srv_ble_cm_cntx.connected_list[i].le_bd_addr,dev_info->dev_addr, sizeof(srv_bt_cm_bt_addr));
			if (dev_info->name[0])
			{
				MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_HAVE_NAME);				
				memcpy(g_srv_ble_cm_cntx.connected_list[i].name,dev_info->name, sizeof(kal_uint8)*SRV_BT_CM_BD_FNAME_LEN);
			}
			else
			{

				if (dev_info->dev_addr && dev_info->name && !dev_info->name[0])
			    {
			    
			        MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_NO_NAME);
				    if ( dev_info->is_ind)
			    	{
				        kal_sprintf(g_srv_ble_cm_cntx.connected_list[i].name,"%02x:%02x:%02x:%02x:%02x:%02x",
				                    (dev_info->dev_addr->nap&0xff00)>>8, dev_info->dev_addr->nap&0x00ff,
				                    dev_info->dev_addr->uap, (dev_info->dev_addr->lap&0xff0000)>>16,
				                    (dev_info->dev_addr->lap&0x00ff00)>>8, (dev_info->dev_addr->lap&0x0000ff));
						
			        }
					else
					{
                        // from search list get name
                        srv_bt_cm_dev_struct* conn_dev;
						conn_dev= (srv_bt_cm_dev_struct*)srv_ble_cm_get_dev_info_by_addr(dev_info->dev_addr, SRV_BLE_CM_DISCOVERED_DEV);
						memcpy(g_srv_ble_cm_cntx.connected_list[i].name, conn_dev->name,  sizeof(kal_uint8)*SRV_BT_CM_BD_FNAME_LEN-1);
		                g_srv_ble_cm_cntx.connected_list[i].name[SRV_BT_CM_BD_FNAME_LEN-1] = '\0';
						//memcpy(g_srv_ble_cm_cntx.connected_list[i].name,conn_dev->name, sizeof(kal_uint8)*SRV_BT_CM_BD_FNAME_LEN);
						
					
						{
							U32 j=0;
							for(j=0; j<10;j++)
							{
							    MMI_TRACE(MMI_CONN_TRC_G7_BT,SRV_BLE_CM_NO_NAME_2,i,j,g_srv_ble_cm_cntx.connected_list[i].name[j]);
							}
						}
			
					}
			    
				}

			}
			g_srv_ble_cm_cntx.connected_dev_num++;
            break;
        }
    }
    for (i = 0; i < BLE_LINK_NUM*2; i++)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_CONNECTED_LIST,
			i,
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.uap),
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_cntx.connected_dev_num);
    }
}

/*****************************************************************************
 * FUNCTION
 *  srv_ble_cm_del_connected_list
 * DESCRIPTION
 *  This function is delete the device in le cm connected list.
 * PARAMETERS
 *  dev: [IN] device info
 * RETURNS
 *  void
 *****************************************************************************/

void srv_ble_cm_del_connected_list(srv_le_cm_gatt_dev_info_struct *dev)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    U32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
	MMI_TRACE(MMI_CONN_TRC_G7_BT,
		SRV_BLE_CM_DEL_CONNECTED_LIST, 
		((dev->dev_addr->nap & 0xff00) >> 8),
        (dev->dev_addr->nap & 0x00ff),
        (dev->dev_addr->uap),
        ((dev->dev_addr->lap & 0xff0000) >> 16),
        ((dev->dev_addr->lap & 0x00ff00) >> 8),
        (dev->dev_addr->lap & 0x0000ff),
        dev->is_ind,
        g_srv_ble_cm_cntx.connected_dev_num);
    for (i=0; i<BLE_LINK_NUM*2; i++)
    {
        if (srv_bt_cm_is_dev_addr_equal(dev->dev_addr, &g_srv_ble_cm_cntx.connected_list[i].le_bd_addr))
        {
            for (j = i; j < (BLE_LINK_NUM*2) - 1; j++)
            {
                //shift array
                memcpy(&g_srv_ble_cm_cntx.connected_list[j],&g_srv_ble_cm_cntx.connected_list[j+1], sizeof(srv_bt_cm_dev_struct));
            }
            memset(&g_srv_ble_cm_cntx.connected_list[SRV_BLE_CM_MAX_CONNECTED_LIST-1],0,sizeof(srv_bt_cm_dev_struct));
			g_srv_ble_cm_cntx.connected_dev_num--;
			break;
        }
    }
    for(i = 0; i< BLE_LINK_NUM*2; i++)
    {
		MMI_TRACE(MMI_CONN_TRC_G7_BT, 
			SRV_BLE_CM_CONNECTED_LIST_1,
			i,
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.nap & 0xff00) >> 8),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.nap & 0x00ff),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.uap),
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0xff0000) >> 16),
			((g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0x00ff00) >> 8),
			(g_srv_ble_cm_cntx.connected_list[i].le_bd_addr.lap & 0x0000ff),
			g_srv_ble_cm_cntx.connected_dev_num);
    }
}


#endif /* __MMI_BT_SUPPORT__ */ 
